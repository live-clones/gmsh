/* A Bison parser, made by GNU Bison 1.875c.  */

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

// $Id: Gmsh.tab.cpp,v 1.210 2004-11-25 02:10:32 geuzaine Exp $
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
static int ViewErrorFlags[VIEW_NB_ELEMENT_TYPES];

#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

#if defined(HAVE_FLTK)
void UpdateViewsInGUI();
#endif

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
#line 81 "Gmsh.y"
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
#line 542 "Gmsh.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 554 "Gmsh.tab.cpp"

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
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
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
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   13940

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  208
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  137
/* YYNRULES -- Number of rules. */
#define YYNRULES  477
/* YYNRULES -- Number of states. */
#define YYNSTATES  2364

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
    1602,  1604,  1608,  1609,  1623,  1625,  1629,  1630,  1646,  1655,
    1657,  1659,  1661,  1663,  1665,  1667,  1669,  1674,  1682,  1692,
    1699,  1703,  1710,  1717,  1727,  1734,  1744,  1750,  1759,  1768,
    1780,  1787,  1797,  1807,  1817,  1825,  1834,  1847,  1854,  1862,
    1870,  1878,  1888,  1896,  1906,  1924,  1932,  1940,  1952,  1961,
    1974,  1983,  1992,  2001,  2014,  2029,  2044,  2067,  2088,  2097,
    2106,  2115,  2123,  2132,  2138,  2150,  2156,  2166,  2168,  2170,
    2172,  2173,  2176,  2183,  2190,  2197,  2204,  2209,  2216,  2221,
    2228,  2232,  2238,  2242,  2246,  2251,  2256,  2260,  2268,  2272,
    2280,  2284,  2287,  2290,  2306,  2309,  2316,  2325,  2334,  2345,
    2347,  2350,  2352,  2356,  2361,  2363,  2372,  2385,  2400,  2401,
    2414,  2415,  2432,  2433,  2452,  2461,  2474,  2489,  2490,  2503,
    2504,  2521,  2522,  2541,  2550,  2563,  2578,  2579,  2592,  2593,
    2610,  2611,  2630,  2632,  2635,  2645,  2653,  2656,  2663,  2673,
    2683,  2692,  2701,  2710,  2717,  2722,  2725,  2728,  2730,  2732,
    2734,  2736,  2738,  2740,  2744,  2747,  2750,  2753,  2757,  2761,
    2765,  2769,  2773,  2777,  2781,  2785,  2789,  2793,  2797,  2801,
    2805,  2809,  2815,  2820,  2825,  2830,  2835,  2840,  2845,  2850,
    2855,  2860,  2865,  2872,  2877,  2882,  2887,  2892,  2897,  2902,
    2909,  2916,  2923,  2928,  2933,  2938,  2943,  2948,  2953,  2958,
    2963,  2968,  2973,  2978,  2985,  2990,  2995,  3000,  3005,  3010,
    3015,  3022,  3029,  3036,  3041,  3043,  3045,  3047,  3049,  3051,
    3056,  3061,  3064,  3070,  3074,  3081,  3086,  3094,  3096,  3099,
    3102,  3106,  3110,  3122,  3132,  3140,  3148,  3149,  3153,  3155,
    3159,  3160,  3164,  3168,  3170,  3174,  3176,  3178,  3182,  3187,
    3191,  3197,  3202,  3204,  3206,  3208,  3212,  3217,  3224,  3232,
    3234,  3236,  3240,  3244,  3254,  3262,  3264,  3270,  3274,  3281,
    3283,  3287,  3289,  3296,  3301,  3306,  3313,  3320
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
     300,   206,   298,   207,     6,    -1,    99,   206,   337,   207,
     206,   337,   207,     6,    -1,     7,    -1,   177,    -1,   176,
      -1,   175,    -1,   174,    -1,   197,    -1,   196,    -1,     4,
     302,   330,     6,    -1,     4,   201,   330,   202,   302,   330,
       6,    -1,     4,   201,   206,   340,   207,   202,   302,   338,
       6,    -1,     4,   201,   202,     7,   338,     6,    -1,     4,
     303,     6,    -1,     4,   201,   330,   202,   303,     6,    -1,
       4,   203,     4,     7,   344,     6,    -1,     4,   201,   330,
     202,   203,     4,     7,   344,     6,    -1,     4,   203,     4,
     302,   330,     6,    -1,     4,   201,   330,   202,   203,     4,
     302,   330,     6,    -1,     4,   203,     4,   303,     6,    -1,
       4,   201,   330,   202,   203,     4,   303,     6,    -1,     4,
     203,   108,   203,     4,     7,   341,     6,    -1,     4,   201,
     330,   202,   203,   108,   203,     4,     7,   341,     6,    -1,
       4,   203,   109,     7,   342,     6,    -1,     4,   201,   330,
     202,   203,   109,     7,   342,     6,    -1,    59,   199,     4,
     200,   203,     4,     7,   330,     6,    -1,    59,   199,     4,
     200,   203,     4,     7,   344,     6,    -1,    39,   199,   330,
     200,     7,   332,     6,    -1,    55,    39,   199,   330,   200,
       7,   338,     6,    -1,    71,    39,   338,     7,   206,   330,
     205,   330,   205,   330,   207,     6,    -1,    46,    47,   338,
       7,   330,     6,    -1,    42,   199,   330,   200,     7,   338,
       6,    -1,    44,   199,   330,   200,     7,   338,     6,    -1,
      40,   199,   330,   200,     7,   338,     6,    -1,    40,   199,
     330,   200,     7,   338,    50,   332,     6,    -1,    41,   199,
     330,   200,     7,   338,     6,    -1,    41,   199,   330,   200,
       7,   338,    50,   332,     6,    -1,    48,   199,   330,   200,
       7,   206,   330,   205,   330,   205,     5,   205,     5,   205,
       5,   207,     6,    -1,   101,   199,   330,   200,     7,   338,
       6,    -1,   102,   199,   330,   200,     7,   338,     6,    -1,
     103,   199,   330,   200,     7,   338,   107,   338,   104,   330,
       6,    -1,    42,    66,   199,   330,   200,     7,   338,     6,
      -1,    71,    42,   338,     7,   206,   330,   205,   330,   205,
     330,   207,     6,    -1,    55,    42,   199,   330,   200,     7,
     338,     6,    -1,    50,    43,   199,   330,   200,     7,   338,
       6,    -1,    51,    43,   199,   330,   200,     7,   338,     6,
      -1,   119,    43,   199,   330,   200,     7,   206,   330,   205,
     338,   207,     6,    -1,    52,    43,   206,   330,   207,     7,
     199,   330,   205,   330,   200,   338,   338,     6,    -1,    52,
      43,   199,   330,   200,     7,   199,   330,   205,   330,   200,
     338,   338,     6,    -1,   103,    43,   105,   106,   199,   330,
     200,     7,   336,   107,   206,   338,   205,   338,   207,   104,
     206,   330,   205,   330,   207,     6,    -1,   103,    43,   199,
     330,   200,     7,   336,   107,   206,   338,   205,   338,   207,
     104,   206,   330,   205,   330,   207,     6,    -1,    43,    66,
     199,   330,   200,     7,   338,     6,    -1,    55,    43,   199,
     330,   200,     7,   338,     6,    -1,    54,    45,   199,   330,
     200,     7,   338,     6,    -1,    45,   199,   330,   200,     7,
     338,     6,    -1,    55,    45,   199,   330,   200,     7,   338,
       6,    -1,    61,   332,   206,   307,   207,    -1,    60,   206,
     332,   205,   332,   205,   330,   207,   206,   307,   207,    -1,
      62,   332,   206,   307,   207,    -1,    63,   206,   332,   205,
     330,   207,   206,   307,   207,    -1,   309,    -1,   308,    -1,
     306,    -1,    -1,   308,   305,    -1,   308,    39,   206,   340,
     207,     6,    -1,   308,    42,   206,   340,   207,     6,    -1,
     308,    43,   206,   340,   207,     6,    -1,   308,    45,   206,
     340,   207,     6,    -1,    65,   206,   308,   207,    -1,    65,
       4,   201,   330,   202,     6,    -1,    68,   206,   308,   207,
      -1,    68,     4,   201,   330,   202,     6,    -1,    68,     4,
       6,    -1,   108,   341,   206,   308,   207,    -1,   120,   344,
       6,    -1,   121,   344,     6,    -1,   120,   206,   308,   207,
      -1,   121,   206,   308,   207,    -1,     4,   344,     6,    -1,
       4,     4,   201,   330,   202,   344,     6,    -1,     4,   330,
       6,    -1,    59,   199,     4,   200,   203,     4,     6,    -1,
     100,     4,     6,    -1,   115,     6,    -1,    37,     6,    -1,
      37,   206,   330,   205,   330,   205,   330,   205,   330,   205,
     330,   205,   330,   207,     6,    -1,    38,     6,    -1,   110,
     199,   330,     8,   330,   200,    -1,   110,   199,   330,     8,
     330,     8,   330,   200,    -1,   110,     4,   111,   206,   330,
       8,   330,   207,    -1,   110,     4,   111,   206,   330,     8,
     330,     8,   330,   207,    -1,   112,    -1,   118,     4,    -1,
     116,    -1,   117,     4,     6,    -1,   113,   199,   330,   200,
      -1,   114,    -1,    64,    39,   206,   330,   205,   332,   207,
       6,    -1,    64,    39,   206,   330,   205,   332,   205,   332,
     205,   330,   207,     6,    -1,    64,    39,   206,   330,   205,
     332,   205,   332,   205,   332,   205,   330,   207,     6,    -1,
      -1,    64,    39,   206,   330,   205,   332,   207,   316,   206,
     325,   207,     6,    -1,    -1,    64,    39,   206,   330,   205,
     332,   205,   332,   205,   330,   207,   317,   206,   325,   207,
       6,    -1,    -1,    64,    39,   206,   330,   205,   332,   205,
     332,   205,   332,   205,   330,   207,   318,   206,   325,   207,
       6,    -1,    64,    42,   206,   330,   205,   332,   207,     6,
      -1,    64,    42,   206,   330,   205,   332,   205,   332,   205,
     330,   207,     6,    -1,    64,    42,   206,   330,   205,   332,
     205,   332,   205,   332,   205,   330,   207,     6,    -1,    -1,
      64,    42,   206,   330,   205,   332,   207,   319,   206,   325,
     207,     6,    -1,    -1,    64,    42,   206,   330,   205,   332,
     205,   332,   205,   330,   207,   320,   206,   325,   207,     6,
      -1,    -1,    64,    42,   206,   330,   205,   332,   205,   332,
     205,   332,   205,   330,   207,   321,   206,   325,   207,     6,
      -1,    64,    43,   206,   330,   205,   332,   207,     6,    -1,
      64,    43,   206,   330,   205,   332,   205,   332,   205,   330,
     207,     6,    -1,    64,    43,   206,   330,   205,   332,   205,
     332,   205,   332,   205,   330,   207,     6,    -1,    -1,    64,
      43,   206,   330,   205,   332,   207,   322,   206,   325,   207,
       6,    -1,    -1,    64,    43,   206,   330,   205,   332,   205,
     332,   205,   330,   207,   323,   206,   325,   207,     6,    -1,
      -1,    64,    43,   206,   330,   205,   332,   205,   332,   205,
     332,   205,   330,   207,   324,   206,   325,   207,     6,    -1,
     326,    -1,   325,   326,    -1,    72,   206,   338,   205,   338,
     205,   338,   207,     6,    -1,    72,   206,   338,   205,   338,
     207,     6,    -1,    67,     6,    -1,    53,    42,   338,     7,
     330,     6,    -1,    53,    42,   338,     7,   330,    56,    58,
     330,     6,    -1,    53,    42,   338,     7,   330,    56,    57,
     330,     6,    -1,    53,    43,   206,   330,   207,     7,   338,
       6,    -1,    49,    43,   206,   330,   207,     7,   338,     6,
      -1,    53,    45,   206,   330,   207,     7,   338,     6,    -1,
      67,    43,   338,     7,   330,     6,    -1,    67,    43,   338,
       6,    -1,    69,     6,    -1,    70,     6,    -1,   125,    -1,
     126,    -1,   127,    -1,   128,    -1,   129,    -1,   331,    -1,
     199,   330,   200,    -1,   189,   330,    -1,   188,   330,    -1,
     194,   330,    -1,   330,   189,   330,    -1,   330,   188,   330,
      -1,   330,   190,   330,    -1,   330,   191,   330,    -1,   330,
     192,   330,    -1,   330,   198,   330,    -1,   330,   184,   330,
      -1,   330,   185,   330,    -1,   330,   187,   330,    -1,   330,
     186,   330,    -1,   330,   183,   330,    -1,   330,   182,   330,
      -1,   330,   180,   330,    -1,   330,   179,   330,    -1,   330,
     178,   330,     8,   330,    -1,    12,   199,   330,   200,    -1,
      13,   199,   330,   200,    -1,    14,   199,   330,   200,    -1,
      15,   199,   330,   200,    -1,    16,   199,   330,   200,    -1,
      17,   199,   330,   200,    -1,    18,   199,   330,   200,    -1,
      19,   199,   330,   200,    -1,    20,   199,   330,   200,    -1,
      22,   199,   330,   200,    -1,    23,   199,   330,   205,   330,
     200,    -1,    24,   199,   330,   200,    -1,    25,   199,   330,
     200,    -1,    26,   199,   330,   200,    -1,    27,   199,   330,
     200,    -1,    28,   199,   330,   200,    -1,    29,   199,   330,
     200,    -1,    30,   199,   330,   205,   330,   200,    -1,    31,
     199,   330,   205,   330,   200,    -1,    32,   199,   330,   205,
     330,   200,    -1,    21,   199,   330,   200,    -1,    12,   201,
     330,   202,    -1,    13,   201,   330,   202,    -1,    14,   201,
     330,   202,    -1,    15,   201,   330,   202,    -1,    16,   201,
     330,   202,    -1,    17,   201,   330,   202,    -1,    18,   201,
     330,   202,    -1,    19,   201,   330,   202,    -1,    20,   201,
     330,   202,    -1,    22,   201,   330,   202,    -1,    23,   201,
     330,   205,   330,   202,    -1,    24,   201,   330,   202,    -1,
      25,   201,   330,   202,    -1,    26,   201,   330,   202,    -1,
      27,   201,   330,   202,    -1,    28,   201,   330,   202,    -1,
      29,   201,   330,   202,    -1,    30,   201,   330,   205,   330,
     202,    -1,    31,   201,   330,   205,   330,   202,    -1,    32,
     201,   330,   205,   330,   202,    -1,    21,   201,   330,   202,
      -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,     4,
      -1,     4,   201,   330,   202,    -1,   204,     4,   201,   202,
      -1,     4,   303,    -1,     4,   201,   330,   202,   303,    -1,
       4,   203,     4,    -1,     4,   201,   330,   202,   203,     4,
      -1,     4,   203,     4,   303,    -1,     4,   201,   330,   202,
     203,     4,   303,    -1,   333,    -1,   189,   332,    -1,   188,
     332,    -1,   332,   189,   332,    -1,   332,   188,   332,    -1,
     206,   330,   205,   330,   205,   330,   205,   330,   205,   330,
     207,    -1,   206,   330,   205,   330,   205,   330,   205,   330,
     207,    -1,   206,   330,   205,   330,   205,   330,   207,    -1,
     199,   330,   205,   330,   205,   330,   200,    -1,    -1,   199,
     335,   200,    -1,     5,    -1,   335,   205,     5,    -1,    -1,
     206,   337,   207,    -1,   199,   337,   200,    -1,   338,    -1,
     337,   205,   338,    -1,   330,    -1,   339,    -1,   206,   340,
     207,    -1,   189,   206,   340,   207,    -1,   330,     8,   330,
      -1,   330,     8,   330,     8,   330,    -1,    39,   206,   330,
     207,    -1,   306,    -1,   309,    -1,   315,    -1,     4,   201,
     202,    -1,   189,     4,   201,   202,    -1,     4,   201,   206,
     340,   207,   202,    -1,   189,     4,   201,   206,   340,   207,
     202,    -1,   330,    -1,   339,    -1,   340,   205,   330,    -1,
     340,   205,   339,    -1,   206,   330,   205,   330,   205,   330,
     205,   330,   207,    -1,   206,   330,   205,   330,   205,   330,
     207,    -1,     4,    -1,     4,   203,   108,   203,     4,    -1,
     206,   343,   207,    -1,     4,   201,   330,   202,   203,   109,
      -1,   341,    -1,   343,   205,   341,    -1,     5,    -1,    35,
     199,   344,   205,   344,   200,    -1,    36,   199,   344,   200,
      -1,    34,   199,   344,   200,    -1,    34,   199,   344,   205,
     340,   200,    -1,    34,   199,     4,   203,     4,   200,    -1,
      34,   199,     4,   201,   330,   202,   203,     4,   200,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   168,   168,   169,   170,   171,   177,   178,   181,   183,
     187,   194,   208,   225,   227,   231,   232,   233,   237,   242,
     247,   248,   249,   253,   256,   259,   266,   270,   276,   284,
     289,   293,   299,   304,   308,   313,   317,   320,   325,   329,
     333,   337,   342,   346,   349,   353,   357,   361,   365,   369,
     373,   376,   380,   383,   387,   390,   397,   399,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   420,   424,   441,   446,   455,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   491,   493,   499,   498,   510,   512,
     518,   517,   531,   533,   539,   538,   552,   554,   561,   559,
     575,   577,   584,   582,   598,   600,   607,   605,   621,   623,
     631,   628,   648,   650,   658,   655,   675,   677,   685,   682,
     702,   704,   713,   709,   730,   732,   741,   737,   758,   760,
     769,   765,   786,   788,   797,   793,   814,   816,   825,   821,
     842,   844,   853,   849,   870,   872,   885,   877,   908,   910,
     923,   915,   946,   948,   961,   953,   984,   986,   997,   991,
    1017,  1019,  1030,  1024,  1050,  1052,  1063,  1057,  1083,  1085,
    1095,  1090,  1115,  1117,  1127,  1122,  1147,  1149,  1159,  1154,
    1179,  1184,  1193,  1192,  1206,  1211,  1220,  1219,  1233,  1243,
    1244,  1245,  1246,  1247,  1251,  1252,  1259,  1287,  1323,  1372,
    1388,  1398,  1416,  1429,  1445,  1470,  1496,  1509,  1525,  1538,
    1554,  1573,  1595,  1604,  1622,  1638,  1654,  1673,  1692,  1710,
    1728,  1746,  1772,  1790,  1816,  1835,  1859,  1883,  1909,  1926,
    1944,  1963,  1982,  2021,  2046,  2068,  2084,  2103,  2122,  2138,
    2157,  2174,  2191,  2212,  2217,  2222,  2227,  2235,  2236,  2237,
    2242,  2245,  2249,  2265,  2281,  2297,  2318,  2331,  2342,  2351,
    2361,  2371,  2385,  2392,  2397,  2408,  2422,  2465,  2479,  2494,
    2503,  2513,  2517,  2521,  2525,  2538,  2552,  2566,  2591,  2616,
    2643,  2649,  2654,  2659,  2663,  2674,  2690,  2706,  2723,  2722,
    2744,  2743,  2765,  2764,  2787,  2810,  2833,  2857,  2856,  2885,
    2884,  2913,  2912,  2943,  2966,  2989,  3013,  3012,  3041,  3040,
    3070,  3069,  3101,  3104,  3110,  3136,  3160,  3169,  3187,  3205,
    3223,  3250,  3276,  3302,  3316,  3335,  3339,  3349,  3350,  3351,
    3352,  3353,  3357,  3358,  3359,  3360,  3361,  3362,  3363,  3364,
    3365,  3372,  3373,  3374,  3375,  3376,  3377,  3378,  3379,  3380,
    3381,  3382,  3383,  3384,  3385,  3386,  3387,  3388,  3389,  3390,
    3391,  3392,  3393,  3394,  3395,  3396,  3397,  3398,  3399,  3400,
    3401,  3402,  3403,  3405,  3406,  3407,  3408,  3409,  3410,  3411,
    3412,  3413,  3414,  3415,  3416,  3417,  3418,  3419,  3420,  3421,
    3422,  3423,  3424,  3425,  3434,  3435,  3436,  3437,  3441,  3453,
    3472,  3485,  3497,  3519,  3536,  3553,  3570,  3590,  3594,  3598,
    3602,  3606,  3613,  3617,  3621,  3625,  3633,  3635,  3641,  3644,
    3651,  3653,  3657,  3664,  3669,  3677,  3682,  3686,  3690,  3702,
    3708,  3719,  3739,  3749,  3759,  3771,  3787,  3805,  3828,  3856,
    3861,  3865,  3869,  3882,  3886,  3898,  3904,  3925,  3929,  3943,
    3948,  3955,  3959,  3967,  3981,  3985,  4004,  4020
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
  "ScalarLineValues", "ScalarLine", "@4", "VectorLineValues", "VectorLine",
  "@5", "TensorLineValues", "TensorLine", "@6", "ScalarTriangleValues",
  "ScalarTriangle", "@7", "VectorTriangleValues", "VectorTriangle", "@8",
  "TensorTriangleValues", "TensorTriangle", "@9", "ScalarQuadrangleValues",
  "ScalarQuadrangle", "@10", "VectorQuadrangleValues", "VectorQuadrangle",
  "@11", "TensorQuadrangleValues", "TensorQuadrangle", "@12",
  "ScalarTetrahedronValues", "ScalarTetrahedron", "@13",
  "VectorTetrahedronValues", "VectorTetrahedron", "@14",
  "TensorTetrahedronValues", "TensorTetrahedron", "@15",
  "ScalarHexahedronValues", "ScalarHexahedron", "@16",
  "VectorHexahedronValues", "VectorHexahedron", "@17",
  "TensorHexahedronValues", "TensorHexahedron", "@18", "ScalarPrismValues",
  "ScalarPrism", "@19", "VectorPrismValues", "VectorPrism", "@20",
  "TensorPrismValues", "TensorPrism", "@21", "ScalarPyramidValues",
  "ScalarPyramid", "@22", "VectorPyramidValues", "VectorPyramid", "@23",
  "TensorPyramidValues", "TensorPyramid", "@24", "Text2DValues", "Text2D",
  "@25", "Text3DValues", "Text3D", "@26", "InterpolationMatrix",
  "NumericAffectation", "NumericIncrement", "Affectation", "Shape",
  "Transform", "MultipleShape", "ListOfShapes", "Duplicata", "Delete",
  "Colorify", "Visibility", "Command", "Loop", "Extrude", "@27", "@28",
  "@29", "@30", "@31", "@32", "@33", "@34", "@35", "ExtrudeParameters",
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
       1,     3,     0,    13,     1,     3,     0,    15,     8,     1,
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
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
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
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   419,   219,   461,
     462,     0,     0,     0,     0,     0,   221,   222,   224,     0,
       0,   469,     0,   230,   371,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   451,   456,     0,   448,
       0,   237,     0,     0,     0,     0,     0,     0,   337,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,     0,     0,     0,
     343,   279,     0,     0,     0,     0,     0,   440,     0,   466,
       0,     0,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
     348,   349,   350,   351,     0,     0,     0,     0,     0,     0,
       0,    23,     0,   424,   287,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   443,   382,   403,   389,   410,   390,   411,
     391,   412,     0,   476,   475,   472,     0,   209,     0,     0,
       0,     0,   217,     0,     0,     0,   467,    73,     0,   234,
     240,     0,   242,     0,     0,   238,     0,   239,   261,     0,
       0,   450,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,   270,     0,   308,     0,   317,     0,   326,     0,
       0,     0,     0,     0,     0,   245,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   436,   426,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,     0,     0,   228,     0,   470,     0,     0,
       0,   248,   258,   457,     0,     0,   341,   251,   252,     0,
       0,     0,     0,   340,   342,   260,   235,   250,   259,   262,
       0,     0,     0,   435,     0,   434,     0,     0,   305,     0,
       0,   314,     0,     0,   323,     0,   272,   273,   274,   275,
       0,     0,   440,     0,     0,     0,     0,     0,   464,     0,
     297,   296,     0,     0,     0,     0,     0,    26,     0,    35,
       0,    39,     0,    33,     0,     0,    38,     0,    43,    41,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   444,     0,     0,   218,   223,   225,     0,   231,     0,
       0,   241,   243,   458,     0,     0,     0,   339,   338,   232,
     233,   270,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   442,   441,     0,     0,     0,     0,     0,
       0,     0,   440,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     477,     0,   468,     0,     0,     0,     0,     0,     0,   433,
       0,     0,     0,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     463,   298,     0,     0,    40,     0,     0,     0,     0,    30,
       0,    36,     0,    42,    31,    44,     0,    47,     0,    51,
      52,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,     0,     0,     0,   264,     0,
       0,   310,     0,   336,     0,     0,   333,   319,     0,     0,
     328,     0,     0,     0,     0,     0,     0,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   110,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,     0,   208,     0,
       0,     0,     0,   432,   306,     0,     0,     0,   309,   315,
       0,     0,   318,   324,     0,     0,   327,   236,   249,     0,
       0,   253,     0,     0,     0,     0,     0,    34,    37,    45,
       0,    46,    53,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   312,     0,     0,   321,
       0,   330,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,     0,     0,   255,
     254,     0,   307,     0,     0,     0,   316,     0,     0,   325,
       0,     0,     0,     0,     0,     0,    29,    32,     0,     0,
       0,   104,     0,   108,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   311,     0,
       0,   335,   320,     0,   329,     0,     0,     0,     0,     0,
       0,    49,    25,   105,   107,   109,   111,   113,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,   203,     0,   204,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   122,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,   334,   322,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,    11,     0,     0,
       0,   116,     0,   120,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,     0,    27,   117,   119,   121,   123,   125,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     134,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,   132,
       0,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   131,   133,   135,   137,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   146,   150,   154,   158,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
       0,   144,     0,   148,     0,   152,     0,   156,     0,   160,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   143,   145,   147,   149,   151,   153,   155,   157,   159,
     161,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,   194,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,     0,   192,     0,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,   191,
     193,   195,   197,   199,     0,     0,     0,   178,   182,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,     0,   180,     0,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   179,   181,   183,   185,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,   170,   174,
       0,     0,     0,     0,     0,     0,     0,   164,     0,   168,
       0,   172,     0,     0,     0,     0,     0,     0,   165,   167,
     169,   171,   173,   175
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,   217,     3,    11,     4,    21,    22,    23,    24,
       5,    73,    74,    75,   447,  1680,   665,  1585,  1682,   666,
    1586,  1684,   667,  1587,  1900,   668,  1846,  1902,   669,  1847,
    1904,   670,  1848,  2036,   671,  1998,  2038,   672,  1999,  2040,
     673,  2000,  2148,   674,  2118,  2150,   675,  2119,  2152,   676,
    2120,  2154,   677,  2121,  2156,   678,  2122,  2158,   679,  2123,
    2346,   680,  2340,  2348,   681,  2341,  2350,   682,  2342,  2295,
     683,  2283,  2297,   684,  2284,  2299,   685,  2285,  2244,   686,
    2226,  2246,   687,  2227,  2248,   688,  2228,  1707,   689,  1609,
    1802,   690,  1709,   691,   142,   254,    76,   577,   347,   563,
     564,   348,    80,    81,    82,    83,    84,   349,  1229,  1555,
    1663,  1232,  1560,  1667,  1235,  1564,  1670,  1417,  1418,    86,
      87,  1004,   350,   145,   369,   180,   249,   440,  1120,  1042,
    1043,   352,   500,   202,   753,   912,   146
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1380
static const short yypact[] =
{
    2859,    68,   134,   242,   403,  3276, -1380, -1380, -1380, -1380,
      46, -1380,   139,   144,   160,   187,   212,   272,    88,    92,
     123, -1380, -1380, -1380, -1380,  2404,   135,    19,   302,   149,
     174,   186,   -34,   348,   218,   222,   388,   223,   399,   402,
     419,   425,   432,   401,   493,   274,   275,   -68,   -68,   292,
     518,     8,   443,    10,   496,   503,    51,   495,   313,   322,
     -16,    11,    29, -1380,   323, -1380,   521, -1380,   547,   551,
     494,    13,    17, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,    18,  3048,
   -1380, -1380, -1380, -1380, -1380,   342,   342,   561, -1380,   148,
      15, -1380, -1380, -1380, -1380,   -41,   -10,    -2,   127,   198,
     229,   329,   370,   371,   389,   393,   412,   416,   450,   468,
     472,   483,   484,   492,   498,   512,   360,   363,   397, -1380,
   -1380, -1380, -1380,  2691,  2691,  2691, -1380, -1380,  2691,  1216,
      40,   593,  2691,   664,   474, -1380,   668,   609, -1380,  2691,
   -1380,  2691,  2691,  2691,   476,  2691,   502,  2691,  2691,   616,
    2691,   504,   515,   516,  -122,   616,   513,   523,   519,   532,
     542,   548,   555,   614,   -68,   -68,   -68,  2691,  2691,   -66,
   -1380,   -47,   -68,   552,   573,   574,   497, -1380,   616,    73,
   -1380, -1380, -1380,   616,   616,   757,  2691,  2691,   -62,  2691,
     570,  2691,   577,   673,  2691,  2691, -1380,   788, -1380,   596,
   -1380, -1380,   792, -1380,   793, -1380,   799,    18,   604,   632,
     662,   674,   687,   688,   711,   723,   727,   732,   758,   786,
     790,   797,   812,   817,   818,   819,   820,   823,   824,   825,
     826,   828,   830,   831,   833,   835,   836,   837,   871,   738,
     838,   739,  2691,  1022, -1380,   -68, -1380,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,    62,
      65,    65,   328,   839,   839,   839,  1707,  1032,  2442,  1945,
     219,   840,  1034,   843,   680, -1380, -1380,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691, -1380,  -120,  1347,  3038, 11923, 11946,  2691, 11969,
    2691, 11992, 12015,   491,   861,  2331,  2442, -1380, -1380, -1380,
    1210,  1042, -1380, 12038,  2691,  2691,  2691,  2691,  2691,  1061,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,   869,   169, -1380,
   -1380,  3748,  3772,   -68,   -68,   661,   661,   178,  2691,  2691,
    2691,  2691,  2739,   375, -1380,  2691,  2942,  1063,  1064, -1380,
   12061, 12084,   969,  2691, 12107,   982,  3796, -1380,   885,  1632,
   12130, -1380,  2691,  3008, -1380,  3032, -1380, -1380,    18,  1087,
    1089,  1090,  1091,  1092,  1093,  1094,  1096,  1099,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1109,  1110,  1111,  1112,  1113,
    1114,  1118,   919,  1119,  1120,  1121,  1123,  1126,  1125, -1380,
     -27,  1127,  1128,  1156, 11356,     9,   -19,  3167, 12153, 11377,
   12176, 11398, 12199, 11419, 12222, 11440, 12245, 11461, 12268, 11482,
   12291, 11503, 12314, 11524, 12337, 11545, 12360, 11566, 12383, 11587,
    3820,  3844, 12406, 11608, 12429, 11629, 12452, 11650, 12475, 11671,
   12498, 11692, 12521, 11713,  3868,  3892,  3916,  3940,  3964,  3988,
     524,   -23,   928,   962,  2691, -1380,   616,  2744,  1210, -1380,
     533,   195,    65,  2691,  1157,  1160,    16,   963, -1380,  1748,
     729,   418,   895,   895,   316,   316,   316,   316,    -6,    -6,
     839,   839,   839,   839,  1161,  2442,  2691,  1159,  1162,  1163,
   12544,  1164, 12567,  1167,  1168,  1262,  2691,   499,  2442,   537,
    2691,  2691,  1169,  2431, 12590, 12613, 12636,  2629,  2691,  3250,
    3280, 12659, 12682, 12705, 12728, 12751,   965,   -68,  2691,  2691,
   -1380, -1380, -1380,   970,  2443, -1380,   971,  2691,  4012,  4036,
    4060, 11734,  -111,   -42,   -43,   -95, -1380, -1380, -1380,  2691,
   11755, -1380,   973,   978,  1189,  1190,   999, 12774,  1193,  1018,
    2691,  3074,  2691,  2691, -1380, 12797, -1380, -1380,  1036,   997,
    1044,  1062,  1097,  1115,  1117,  1122,  1124,  1130,  1131,  1132,
    1134,  1135,  1136,  1137,  1139,  1140,  1142,  1170,  1171,  1172,
    1174,  1176,  1177,  1179,  1186,  1198,  1201,  1202,  1204, -1380,
    1263,  1095, -1380,  1206,   120, -1380, -1380,  1098,  1100,  1129,
    1133,  1175,  1213,  1214,  1215,  1217,  1218,  1220,  1222,  1224,
    1225,  1241,  1242,  1243,  1244,  1245,  1248,  1249,  1250,  1253,
    1254,  1255,  1256,  1108,  1290, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,  2691,  2691, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  1294, -1380,  2442,    65, -1380,
   11776,  1298,  2442,  1116,    53,  2691,  1300,  1302,   710, -1380,
    1303,  1257,    11,  1306, -1380,  2691, -1380,    76,  4084,   -68,
     616,   616,  1310,   616,  1312,   616,   616, -1380,  2442,  3306,
    1544,   541, -1380,  1832,   750,  1240,  1317,  1318,  1319,  1326,
    1450,   305,  1452,  1453,  1455,  1456,  1458,  1462,  1463,  1467,
     199,  4108,  4132, -1380, -1380,  3332,   -68,   -68,   -68,  1466,
    2442,  2442,  2442,  2442,   780,  1468,  2691,  2691,   616,   616,
    2691,  1470,   616,  1471,  4156, -1380,  1876,   395,  1472,  1307,
    1477,  2691,  2691,   -68,  1478,  1479,  1293,  1481,  1482,   616,
     616,  1483,   -68,  1484,  1485,   616,   616,  1486,  1487,  1489,
    1490,  1491,   616,   608,   616,  1492,  1493,  1494,  1518,  1520,
   -1380,  1522,   342,  1536, -1380,  1535,  3209,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,   616, -1380, 12820, 11797, 12843, 11818, 12866,
   11839, 12889, 11860, 11881,  1296,    85,  1297,   122, -1380,  1210,
   -1380,   188,   343,  1339,  1537,   815, -1380, -1380, -1380,    11,
    2691, -1380,   545, -1380,  2499,  1540,  2691,    20,    33,    52,
     616,  1543,   616,  1545,  1571,   546, -1380, -1380,  2442, -1380,
    2691, -1380,  2691,   616,   616,   616,  1351,  1379, -1380,    58,
     616,   616,   616,   616,   616,   616,   616,   383,  2691,  2691,
    2691,  1373,  -116,  -113,  -102, -1380,   550,   554,   557,   563,
   -1380, -1380,  4180,  4204,  1574,  1575, 12912,   -87,  1475, -1380,
    2691,  2691,  2691, -1380,  1377,  1417,  1381,  4228,  4252,   -82,
    1384,  1391,  1389,  1395,  1392,  1396,  1393,  1394,   282,  1397,
    1400,  1401,  1398,  1399,  1425,  1426,  1427,  1428,  1405, -1380,
   -1380, -1380, -1380, -1380,  1429,  1432,  1433,  1437,  1438,  1444,
    1440, -1380,  1441,     9, -1380,  1641,  4276,  4300,  4324,  4348,
    4372,  4396,  4420,  4444,  4468,  4492,  4516,  4540,  4564,  4588,
    4612,  4636,  4660,  4684,  4708,  4732,  4756,  4780,  4804,  4828,
    4852,  4876,   564, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380,  1445, -1380, -1380, -1380,   616,    65,  2691,  1643,
    1646,    16, -1380,  1645, 11902,    11, -1380, -1380,  4900, -1380,
   -1380,   -68, -1380,   -68,  1647, -1380,  1648, -1380, -1380,  1457,
     567,  2499,  4924,  1649,  1652,  1654,  2691,  2691,  2691,  2691,
    1655,  1658,  1659,  1660,  1661,  1662,  1664, -1380,  2640,  3358,
   12935,  2686,   661,   -68,  1666,   -68,  1667,   -68,  1668,  1669,
    1670,  1671,  1672,  2691,  2691, -1380, -1380,  1673,   616,   616,
    1572,   616,  3175,   269, 12958,  2691,    18,  1678,  2691,   616,
    1676,  1680,  1679,  1498,  1683,   608,  1684,  1688,  2691,  1686,
    1690,  1689,  1691,  1695,   608,  2691,  2691,  2691,   616,  1693,
    1697,   608,  2691,  1698,  1700,  1699,  2691,   342, -1380, -1380,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,   616,  1446,  1703,  1723,
    1725,   868, -1380,  1687,  1728, -1380,  1532, -1380,  2691,    22,
      24, -1380, -1380, -1380,  1534,  2691, -1380, -1380, -1380,  4948,
    4972,  1003,  1025, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
    1072,  1731,  1533, -1380,  2691, -1380,  1538,   213, -1380,  1546,
     224, -1380,  1547,   231, -1380,  1548, -1380, -1380, -1380, -1380,
    4996,  5020,   -87,   109,   582,  1549,  1636,  2691, -1380,  2691,
   -1380, -1380,  5044,    18,  1541,  5068,  1539, -1380,  1552, -1380,
    1553, -1380,  1542, -1380,  1554, 12981, -1380,  1558, -1380, -1380,
    1551,  1564, 13004,  5092, 13027,  1561, -1380,  1576,  1577,  5116,
    1569,  1578, -1380,  5140,  1570,  5164,  5188,  5212,  5236,  5260,
    5284,  5308,  5332,  5356,  5380,  5404,  5428,  5452,  5476,  5500,
    5524,  5548,  5572,  5596,  5620,  5644,  5668,  5692,  5716,  5740,
    5764, -1380,   616,  1579, -1380, -1380, -1380,    11, -1380,  1674,
    5788, -1380, -1380, -1380,  5812,  2691,  2691, -1380, -1380, -1380,
   -1380,   661,  3220, -1380,  2371,   280,  2371,   280,  2371,   280,
    2691,  2691,  1675, -1380, -1380,   616,  2691,  3384,  3410,   616,
      18,  1774,   -87,   608,  1778,  2691,  1780,   608,  1781,  1785,
    1783,  1784,  1807,  2691,  1819,   616,  1820,  1821,  2691,  1788,
    1822,  2691,  1824,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,   583,
   -1380,  1825, -1380,  2691,  1827, 13050, 13073,  1626,  2691, -1380,
    2371,  2371,  2691,  3436,   236,  1828,  1629,   -32, -1380,  3462,
     238,   -26,  3488,   245,   -17,  3514,  3540,  1630,  1633,  1247,
   -1380, -1380,  1634,  1681, -1380,  1637,  1638,  1640,  5836, -1380,
    1639, -1380,  1677, -1380, -1380, -1380, 13096, -1380,  1642, -1380,
   -1380, 13119,  1682, -1380, 13142,  1665, 13165, 13188, 13211,  5860,
    5884,  5908,  5932,  5956,  5980,  6004,  6028,  6052,  6076,  6100,
    6124,  6148,  6172,  6196,  6220,  6244,  6268,  6292,  6316,  6340,
   13234,  6364,  1831, -1380,  6388,  1696,   616,   616, -1380,  3566,
    2546,  1840,  2691, -1380,   616,  1865, -1380,  1866,  2691,  1867,
    1868,  2691,  1869,  1870,  1872,   616,   616, -1380,  1873,    18,
     608,   608,   608,   608,  1874,  1875,  1882,   608,  1894,  1897,
    1923,  1936, -1380, -1380, -1380,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691, -1380,  2691, -1380,  2691,
    1937,   616,   616, -1380, -1380,  1737,  3592,  1739, -1380, -1380,
    1741,  3618, -1380, -1380,  1743,  3644, -1380, -1380, -1380,  1740,
    1744, -1380,    18,  1745,  1747,  1753,  1754, -1380, -1380, -1380,
    1750, -1380, -1380, -1380,  1767,  1768,  1770,  1771,  6412,  6436,
    6460,  6484,  6508,  6532,  6556,  6580,  6604,  6628,  6652,  6676,
    6700,  6724,  6748,  6772,  6796,  6820,  6844,  6868,  6892,  1772,
   13257,  3670,  1775,  1967,  1973,   280,  1975,   616,   280,  1976,
     280,  1977,   616,  1880,    18,   608,   608,  1979,  1980,   608,
    1982,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,    65, -1380,  1983,  1985, -1380,
   -1380,   -13, -1380,  1782,   586,   -11, -1380,  1823,    -7, -1380,
    1826,  1818,  1830,  1859,  1786,  1829, -1380, -1380,  1838,  1857,
     601,  2499,   602,  2499,   606,  2499,  6916,  6940,  6964,  6988,
    7012,  7036,  7060,  7084,  7108,  7132,  7156,  7180,  7204,  7228,
    7252,  7276,  7300,  7324,  7348,  7372,  7396,   607, -1380,  1863,
   -1380,  1864,  2021,   280,   616,  2022,  2025,   280,  2064,   280,
    1968,  2691,    18,   608,   616,  2067,  2069,  2691,  2070,  2691,
    2071,  2691,  2072,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,    65,  2073,    65,  2074, -1380,    -4,
    1885, -1380, -1380,    -3, -1380,    72,  1887,  7420,    18,  1877,
    1889, -1380, -1380,  2499, -1380,  2499, -1380,  2499, -1380, 13280,
   13303, 13326,  7444,  7468,  7492,  7516,  7540,  7564,  7588,  7612,
    7636,  7660,  7684,  7708,  7732,  7756,  7780,  7804,  7828,  7852,
   -1380, -1380,   611, -1380, -1380,  2075,  2089,  2090,  2091,  2691,
    2691,    18,   608,   616, -1380, -1380, -1380,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,    65,  2092, -1380, -1380, -1380,
   -1380,  7876,  3696,  1927,  1895,  1896,  1898,  1899,  1900,  7900,
    7924,  7948,  7972,  7996,  8020,  8044,  8068,  8092,  8116,  8140,
    8164,  8188,  8212,  8236,  8260,  8284,  8308, -1380, -1380,  2691,
    2096,  1930,   616,   608,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  3722, -1380, -1380,  1902,  1926,
     612,  2499,   618,  2499,   619,  2499,  8332,  8356,  8380,  8404,
    8428,  8452,  8476,  8500,  8524,  8548,  8572,  8596,  8620,  8644,
    8668,  8692,  8716,  8740,  2132,   616,  2133,  2691,  2134,  2691,
    2135,  2691,  2136,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691, -1380,  1940, -1380,  2499, -1380,  2499, -1380,  2499, -1380,
   13349, 13372, 13395,  8764,  8788,  8812,  8836,  8860,  8884,  8908,
    8932,  8956,  8980,  9004,  9028,  9052,  9076,  9100,   616, -1380,
   -1380, -1380,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  1944,  1947,  1949,
    1959,  9124,  9148,  9172,  9196,  9220,  9244,  9268,  9292,  9316,
    9340,  9364,  9388,  9412,  9436,  9460,   616,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  1946,   622,  2499,   623,  2499,
     672,  2499,  9484,  9508,  9532,  9556,  9580,  9604,  9628,  9652,
    9676,  9700,  9724,  9748,  9772,  9796,  9820,   608,  2691,  2160,
    2691,  2161,  2691,  2162,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  1969,
    2499, -1380,  2499, -1380,  2499, -1380, 13418, 13441, 13464, 13487,
   13510, 13533,  9844,  9868,  9892,  9916,  9940,  9964,  9988, 10012,
   10036,  2164, -1380, -1380, -1380, -1380, -1380, -1380,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691, -1380,  1965,  1971,
    1972,  1974,  1978,  1987, 10060, 10084, 10108, 10132, 10156, 10180,
   10204, 10228, 10252,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,   676,  2499,
     677,  2499,   699,  2499,   744,  2499,   745,  2499,   748,  2499,
   10276, 10300, 10324, 10348, 10372, 10396, 10420, 10444, 10468,  2691,
    2167,  2691,  2168,  2691,  2169,  2691,  2173,  2691,  2175,  2691,
    2176,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691,
    2499, -1380,  2499, -1380,  2499, -1380,  2499, -1380,  2499, -1380,
    2499, -1380, 10492, 10516, 10540, 10564, 10588, 10612, 13556, 13579,
   13602,  2691,  2691,  2691,  2691,  2691,  2691, -1380, -1380, -1380,
   10636, 10660, 10684, 10708, 10732, 10756,  1988,  1989,  1990,  2691,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2691, 10780, 10804,
   10828, 10852, 10876, 10900,   749,  2499,   768,  2499,   769,  2499,
    2691,  2691,  2691,  2691,  2691,  2691,  2691,  2177,  2691,  2179,
    2691,  2191, 10924, 10948, 10972, 13625, 13648, 13671,  2499, -1380,
    2499, -1380,  2499, -1380,  2691,  2691,  2691, -1380, -1380, -1380,
   10996, 11020, 11044,  1992,  1993,  1994,  2691,  2691,  2691,  2691,
    2691,  2691, 11068, 11092, 11116,   772,  2499,   775,  2499,   776,
    2499,  2691,  2691,  2691,  2691,  2195,  2691,  2196,  2691,  2197,
   11140, 11164, 11188,  2499, -1380,  2499, -1380,  2499, -1380,  2691,
    2691,  2691, 11212, 11236, 11260,  2691,  2691,  2691, 11284, 11308,
   11332,  2691,  2691,  2691, 13694, 13717, 13740, -1380, -1380, -1380,
    2007,  2008,  2009,  2691,  2691,  2691,   783,  2499,   803,  2499,
     807,  2499,  2691,  2210,  2691,  2211,  2691,  2212,  2499, -1380,
    2499, -1380,  2499, -1380
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -1380, -1380,   -81, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,  1583, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1380,
   -1380, -1380, -1380, -1380,  -303,   -22, -1380,  2215,     0,  -370,
    -177,     3, -1380, -1380, -1380, -1380, -1380,  2216, -1380, -1380,
   -1380, -1380, -1380, -1380, -1380, -1380, -1380, -1308, -1379, -1380,
   -1380, -1073,   -25, -1380,   -31, -1380,   -92, -1380, -1205, -1037,
     827,  -179,  -337,  -741,  1173, -1380,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -57
static const short yytable[] =
{
     144,   212,   214,   143,   250,    78,   566,   503,    79,   539,
     382,   911,   186,   386,   189,   200,   179,   181,   210,   255,
     751,   215,   210,   156,   154,   148,  1069,   198,  1321,  1421,
    1322,  1424,   154,   203,   403,  1415,   405,  1342,  1496,  1070,
    1416,  1415,  1496,   392,   310,  1496,  1416,   126,   127,   128,
    1415,   126,   127,   128,  1415,  1416,  1415,   902,  1072,  1416,
    1415,  1416,  1262,  1415,  1415,  1416,   490,   210,  1416,  1416,
     210,  1271,   373,   374,     6,   373,   374,   357,  1278,   384,
     524,  1243,  1244,  1071,   358,   525,   373,   374,   151,  1103,
     193,  1104,  1105,   194,  1106,   800,   126,   127,   128,   126,
     127,   128,  1073,  1107,   158,  1108,   373,   374,   303,   304,
     305,   803,  1118,   306,   309,  1088,  1089,   314,  1130,  1119,
     175,   176,   373,   374,   334,   210,   335,   336,   337,   499,
     339,   177,   341,   342,     7,   353,   408,   393,   178,  1415,
     375,   373,   374,   368,  1416,   370,    89,  1435,   311,   312,
      90,   377,   371,   372,   126,   127,   128,   155,   257,   376,
     258,   903,   904,   802,   801,   155,    91,   499,  1063,   373,
     374,   390,   391,   629,   394,  1495,   396,   736,   630,   399,
     400,  1499,   737,   199,   328,   329,   330,   636,   757,   259,
    1502,   260,   331,    92,  1712,   101,  1716,   261,   745,   262,
    1718,   771,   101,  1805,  1807,   136,   137,   216,   373,   374,
     373,   374,   373,   374,   187,    88,   190,   201,    93,   211,
     591,   256,   752,   213,   446,   149,   502,   444,   204,   491,
     492,   493,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   385,  1399,   915,  1249,    94,  1808,
    1436,   742,  1496,   498,  1440,  1054,  1496,    95,   504,  1496,
     742,    96,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,  1661,   150,  1343,
    1665,   938,  1668,   530,  1186,   532,   136,   137,   136,   137,
     304,   498,    97,   853,  1197,   853,   263,   598,   264,   543,
     544,   545,   546,   547,   147,   549,   550,   551,   552,   553,
     554,   555,   560,   561,   136,   137,   499,  1415,   151,   252,
    1057,   253,  1416,   568,   569,   570,   571,   373,   374,   499,
     580,   939,   129,   130,   131,   132,   373,   374,   587,   129,
     130,   131,   132,   152,   557,   562,   562,   595,   565,   565,
    1496,   578,   579,   567,  1496,   153,  1496,   373,   374,  1097,
    1098,   136,   137,   129,   130,   131,   132,   265,   744,   266,
     895,   373,   374,   972,   948,  1759,    12,     8,     9,  1763,
      10,  1765,   373,   374,   156,   136,   137,   157,  1334,   373,
     374,   158,   160,   635,   373,   374,   373,   374,   267,  1336,
     268,   925,   747,   373,   374,   159,  1338,  1573,  1574,  1575,
    1576,  1492,   161,  1498,  1580,   162,   168,   317,   318,   319,
    1501,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   163,   956,   957,   958,   959,   331,   164,   740,
     373,   374,   304,   173,   165,   166,  1250,   167,   748,   746,
     316,   174,  1139,   317,   318,   319,   188,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   182,   195,
     498,   758,   191,   331,   326,   327,   328,   329,   330,   192,
     740,   769,   196,   498,   331,   773,   774,   129,   130,   131,
     132,   197,   205,   781,   136,   137,   790,   206,   269,   494,
     270,   253,   169,   791,   792,   170,   171,   209,   172,   136,
     137,   248,   795,    13,    14,    15,    16,    17,    18,    19,
      20,   207,  1674,  1675,   804,   208,  1678,   183,   499,   299,
     184,   185,   300,   900,   855,   814,   251,   816,   817,   271,
     273,   272,   274,   317,   318,   319,  1401,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   275,   499,
     276,  1080,   277,   331,   278,   973,   301,   313,  1056,  1058,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   279,   854,   280,   333,   281,   331,   282,   367,    98,
     343,   499,   499,   499,   499,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   283,
    1769,   284,   317,   318,   319,   344,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   285,   896,   286,
     315,   287,   331,   288,   332,   338,    46,    47,    48,    49,
      50,    51,   289,   291,   290,   292,   508,   136,   137,   885,
     886,   293,   535,   294,   253,   136,   137,   295,   381,   296,
     770,   340,   253,   887,   888,   889,   890,   891,   892,   893,
     354,   297,   498,   298,   355,   356,   908,   899,   362,   360,
     905,    46,    47,    48,    49,   734,    51,   735,   917,   361,
     914,   363,  1226,   999,  1000,  1001,  1002,  1003,   742,  1844,
     743,   364,   742,   498,   772,   740,   742,   365,   929,   499,
    1065,   742,  1066,  1079,   366,   742,   931,  1109,   378,   742,
    1012,  1110,   742,   389,  1111,   952,   953,   954,   742,  1186,
    1112,  1187,   742,   395,  1204,   498,   498,   498,   498,   379,
     380,   962,   963,   397,   398,   966,   960,  1186,  1186,  1344,
    1482,  1714,   979,  1715,   401,   402,   977,   978,   404,   406,
    1899,   988,   407,   409,   133,   345,  1727,  1729,  1728,  1730,
     135,  1731,  1754,  1732,  1755,   138,  1835,  1927,  1836,  1928,
     141,  1062,   346,  1929,  1931,  1930,  1932,  2058,  2060,  2059,
    2061,   410,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,   317,   318,
     319,   411,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   412,  1316,   854,   439,  2062,   331,  2063,
    1059,  2169,  2171,  2170,  2172,  1064,   413,   414,   317,   318,
     319,  1068,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   498,  2173,  1081,  2174,  1082,   331,   319,
     415,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   416,  1099,  1100,  1101,   417,   331,   317,   318,
     319,   418,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   441,   443,  1122,  1123,  1124,   331,  2175,
    2177,  2176,  2178,  2179,  2256,  2180,  2257,   419,   317,   318,
     319,  1407,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,  2258,  2260,  2259,  2261,  2304,   331,  2305,
    2306,  2308,  2307,  2309,  2079,   420,   351,  1190,  2352,   421,
    2353,  1158,   359,   317,   318,   319,   422,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,  2354,  1327,
    2355,   423,  2356,   331,  2357,   383,   424,   425,   426,   427,
     387,   388,   428,   429,   430,   431,   445,   432,  1221,   433,
     434,  1328,   435,  1191,   436,   437,   438,   331,   442,   496,
    1199,   506,  1200,   505,   507,  1253,   317,   318,   319,   541,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,  1209,  1210,  1211,  1212,  1284,   331,   536,   548,   556,
     582,   583,  1227,  1220,  1230,   586,  1233,   622,  1329,   322,
     323,   324,   325,   326,   327,   328,   329,   330,  1240,  1241,
     589,   592,   599,   331,   600,   601,   602,   603,   604,   605,
    1252,   606,   562,  1255,   607,   565,   608,   609,   610,   611,
     612,   613,   614,  1265,   615,   616,   617,   618,   619,   620,
    1272,  1273,  1274,   621,   623,   624,   625,  1279,   626,   627,
     628,  1283,   631,   738,   632,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,   633,   739,   749,   750,   754,   759,   756,   789,   760,
     761,   763,  1350,  1320,   765,   766,   775,   793,   794,   806,
    1324,   317,   318,   319,   807,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   808,   809,   810,  1332,
     812,   331,   820,   317,   318,   319,   819,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   540,    98,
     302,   813,  1347,   331,  1348,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   821,
     317,   318,   319,  1507,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,    98,   302,   822,   850,  1433,
     331,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   851,   884,   857,   894,   858,
    1405,  1406,   823,  1414,   898,  1420,   906,  1423,   907,  1413,
     909,  1419,   913,  1422,   883,  1425,  1426,   920,   901,   922,
     824,  1429,   825,   741,   933,   934,   935,   826,   859,   827,
    1438,   562,   860,   936,   565,   828,   829,   830,  1446,   831,
     832,   833,   834,  1451,   835,   836,  1454,   837,  1456,  1457,
    1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,
    1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,
    1478,  1479,  1480,  1481,   861,   838,   839,   840,  1484,   841,
     370,   842,   843,  1489,   844,   303,   304,  1490,   317,   318,
     319,   845,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   846,   133,   134,   847,   848,   331,   849,
     135,   852,   862,   863,   864,   138,   865,   866,   307,   867,
     141,   868,   308,   869,   870,   317,   318,   319,  1572,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     871,   872,   873,   874,   875,   331,   932,   876,   877,   878,
     133,   134,   879,   880,   881,   882,   135,   937,   910,   940,
     941,   138,   942,   943,   767,   944,   141,  1556,   768,   945,
     946,   947,   955,  1561,   961,   969,  1565,   967,   975,   974,
     976,   980,   981,   982,   983,   984,   987,   989,   990,   993,
     994,  1624,   995,   996,   997,  1006,  1053,  1055,  1007,  1008,
    1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,
    1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,  1607,
    1608,  1009,  1610,  1010,  1611,   317,   318,   319,  1011,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
    1013,  1014,  1060,  1673,  1061,   331,  1067,    98,   302,  1075,
    1086,  1077,   526,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,  1078,  1087,  1102,
    1115,  1116,  1121,  1125,  1126,  1708,  1127,   918,   919,  1131,
     921,  1132,   923,   924,  1133,  1134,  1136,  1135,  1137,  1138,
    1141,  1142,  1140,  1143,  1144,  1149,  1681,  1683,  1685,  1686,
    1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,  1696,
    1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,  1706,
    1145,  1146,  1147,  1148,  1150,   964,   965,  1151,  1152,   968,
     593,  1768,  1153,  1154,  1155,  1156,  1157,  1159,  1188,  1192,
    1193,  1195,  1312,  1201,  1202,  1206,   985,   986,  1207,  1203,
    1208,  1213,   991,   992,  1214,  1215,  1216,  1217,  1218,   998,
    1219,  1005,  1228,  1231,  1234,  1236,  1237,  1238,  1239,  1245,
    1242,  1254,  1257,  1258,  1800,  1259,  1803,  1811,  1260,  1261,
    1263,  1264,  1266,  1267,  1317,  1268,  1767,  1269,  1270,  1276,
    1277,  1280,  1773,  1281,  1775,  1282,  1777,  1313,  1779,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,
    1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1314,
    1843,  1315,   133,   134,  1318,  1319,  1323,  1330,   135,  1331,
    1346,  1351,  1356,   138,  1353,  1333,   927,  1074,   141,  1076,
     928,  1360,  1335,  1337,  1339,  1345,   755,  1354,  1355,  1357,
    1083,  1084,  1085,  1359,  1361,  1867,  1365,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1369,  1372,  1366,  1367,  1370,  1400,
    1434,  1437,  1427,  1402,  1841,  1842,  1439,  1441,  1442,  1443,
    1444,  1452,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,  1866,
     317,   318,   319,  1445,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,  1447,  1449,  1450,  1453,  1455,
     331,  1483,  1485,  1488,  1493,  1494,  1505,  1548,  1506,  1514,
     930,  1508,  1510,  1511,  1895,  1512,  1554,  1517,  1509,  1901,
    1903,  1905,  1906,  1907,  1908,  1909,  1910,  1911,  1912,  1913,
    1914,  1915,  1916,  1917,  1918,  1919,  1920,  1921,  1922,  1923,
    1521,  1558,  1559,  1562,  1563,  1566,  1567,  1515,  1568,  1571,
    1577,  1578,  1519,  1189,   971,   317,   318,   319,  1579,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
    1581,  1550,  1954,  1582,  1956,   331,  1958,   495,  1960,  1961,
    1962,  1963,  1964,  1965,  1966,  1967,  1968,  1969,  1970,  1971,
    1972,  1973,  1974,  1975,  1976,  1977,   317,   318,   319,  1583,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,  1584,  1612,  1615,  1617,  1622,   331,  1618,  1246,  1620,
    1625,  1623,  1626,  1627,  1628,  1629,  1256,  2001,  2002,  2003,
    2004,  2005,  2006,  2007,  2008,  2009,  2010,  2011,  2012,  2013,
    2014,  2015,  1630,  1659,  1631,  1275,  1632,  1633,  1655,  1660,
    1658,  1662,  1666,  1669,  1672,  1676,  1677,  1679,  1713,  1710,
    1711,  1723,  2037,  2039,  2041,  2042,  2043,  2044,  2045,  2046,
    2047,  2048,  2049,  2050,  2051,  2052,  2053,  2054,  2055,  2056,
     317,   318,   319,  1311,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,  1720,  1722,  1758,  1761,  1717,
     331,  1762,  1719,  2080,  1724,  2082,  1721,  2084,  1725,  2086,
    2087,  2088,  2089,  2090,  2091,  2092,  2093,  2094,  2095,  2096,
    2097,  2098,  2099,  2100,   317,   318,   319,  1726,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,  1756,
    1764,  1757,  1766,  1771,   331,  1772,  1774,  1776,  1778,  1801,
    1804,  1837,  1812,  2124,  2125,  2126,  2127,  2128,  2129,  2130,
    2131,  2132,  1806,  1809,  1813,  1838,  1839,  1840,  1868,  1871,
    1872,  1873,  1896,  1897,  1874,  1875,  1876,  1925,  2149,  2151,
    2153,  2155,  2157,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,   317,   318,   319,  1926,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,  1951,  1953,
    1955,  1957,  1959,   331,  2190,  1978,  2192,   501,  2194,  2016,
    2196,  2057,  2198,  2017,  2200,  2018,  2202,  2203,  2204,  2205,
    2206,  2207,  2208,  2209,  2210,  2019,  2081,  2083,  2085,  2101,
    2117,  2133,  1428,  2191,  2193,  2195,  1432,  2134,  2135,  2197,
    2136,  2199,  2201,  2269,  2137,  2271,  2220,  2221,  2222,  2223,
    2224,  2225,  1448,  2138,  2235,  2236,  2237,  2273,  2289,  2290,
    2291,  2314,  2316,  2318,  2238,  2239,  2240,  2241,  2242,  2243,
    2245,  2247,  2249,  2343,  2344,  2345,  2359,  2361,  2363,   856,
      77,    85,     0,     0,     0,  2262,  2263,  2264,  2265,  2266,
    2267,  2268,     0,  2270,  1194,  2272,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2280,
    2281,  2282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2292,  2293,  2294,  2296,  2298,  2300,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2310,  2311,  2312,  2313,
       0,  2315,     0,  2317,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2322,  2323,  2324,     0,     0,     0,
    2328,  2329,  2330,     0,     0,     0,  2334,  2335,  2336,     0,
       0,     0,     0,  1551,  1552,     0,     0,     0,  2347,  2349,
    2351,  1557,     0,     0,     0,     0,     0,  2358,     0,  2360,
       0,  2362,  1569,  1570,    98,   537,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,   302,     0,     0,  1613,  1614,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     0,     0,     0,    98,    99,   100,
       0,   101,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,   127,
     128,     0,     0,     0,  1664,    98,   343,     0,     0,  1671,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     0,     0,     0,     0,     0,
       0,   344,   572,    30,    31,   573,   574,    34,   575,    36,
       0,    37,     0,    39,    40,    41,     0,    43,    44,     0,
       0,     0,    46,    47,    48,    49,    50,    51,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,     0,   133,
     134,     0,     0,     0,     0,   135,     0,     0,     0,     0,
     138,     0,     0,     0,     0,   141,     0,   538,     0,     0,
       0,  1760,     0,     0,    58,    59,    60,     0,     0,     0,
       0,  1770,     0,     0,     0,     0,     0,     0,     0,  1410,
    1411,     0,    70,     0,     0,   135,     0,     0,     0,     0,
    1412,     0,     0,     0,     0,   141,     0,   178,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,   134,     0,     0,     0,     0,   135,     0,
     136,   137,     0,   138,     0,   139,     0,   140,   141,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
     133,   497,     0,     0,     0,     0,   135,     0,   776,     0,
    1845,   138,     0,    98,   302,   210,   141,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,   127,   128,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,    98,   302,     0,   331,     0,  1898,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   495,    98,   537,     0,
       0,   558,  1952,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   572,    30,
      31,   573,   574,    34,   575,    36,     0,    37,     0,    39,
      40,    41,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1997,     0,   317,   318,   319,
      56,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,   133,   134,
       0,     0,     0,     0,   135,     0,   780,     0,     0,   138,
      58,    59,    60,  2035,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    -8,
       1,     0,   -13,   -56,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   133,
     134,     0,     0,     0,   331,   135,     0,     0,     0,     0,
     138,  1224,   -56,  1225,     0,   141,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,   -56,
     -56,     0,   133,   134,     0,     0,     0,     0,   135,     0,
       0,     0,     0,   138,     0,     0,   576,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -56,
     -56,   -56,   -56,     0,     0,     0,     0,   -56,     0,   -56,
       0,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   572,    30,    31,   573,   574,    34,   575,    36,     0,
      37,     0,    39,    40,    41,     0,    43,    44,     0,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -8,    -8,     0,    -8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,     0,   572,    30,    31,
     573,   574,    34,   575,    36,     0,    37,     0,    39,    40,
      41,    70,    43,    44,     0,     0,     0,     0,     0,     0,
       0,   572,    30,    31,   573,   574,    34,   575,    36,    56,
      37,     0,    39,    40,    41,     0,    43,    44,     0,     0,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,    58,
      59,    60,     0,   572,    30,    31,   573,   574,    34,   575,
      36,     0,    37,     0,    39,    40,    41,    70,    43,    44,
       0,     0,     0,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,   581,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,     0,     0,    58,    59,    60,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     0,     0,
       0,     0,     0,    70,     0,     0,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,   242,   243,   244,
     245,   246,   247,     0,     0,   596,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   527,   597,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,   815,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,    26,
       0,     0,     0,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,    37,    38,    39,    40,    41,    42,
      43,    44,     0,     0,     0,    45,    46,    47,    48,    49,
      50,    51,     0,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,   664,     0,    57,    58,    59,    60,
    1247,     0,  1248,     0,    61,     0,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,  1015,     0,   331,     0,
       0,     0,     0,     0,     0,  1408,     0,  1409,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,     0,     0,     0,   782,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,   317,   318,   319,   783,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     317,   318,   319,   926,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   317,   318,   319,   951,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   317,   318,   319,  1222,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   317,   318,
     319,  1430,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,   317,   318,   319,  1431,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     317,   318,   319,  1491,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   317,   318,   319,  1497,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   317,   318,   319,  1500,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   317,   318,
     319,  1503,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,   317,   318,   319,  1504,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     317,   318,   319,  1553,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   317,   318,   319,  1616,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   317,   318,   319,  1619,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   317,   318,
     319,  1621,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,   317,   318,   319,  1657,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     317,   318,   319,  1870,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   317,   318,   319,  1924,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,   558,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,   559,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,   590,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,   714,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,   715,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,   728,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,   729,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,   730,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,   731,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,   732,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,   733,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,   796,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,   797,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,   798,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,   916,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,   949,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,   950,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,   970,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1113,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1114,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1128,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1129,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1160,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1161,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1162,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1163,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1164,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1165,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1166,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1167,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1168,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1169,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1170,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1171,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1172,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1173,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1174,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1175,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1176,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1177,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1178,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1179,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1180,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1181,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1182,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1183,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1184,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1185,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1198,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1205,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1325,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1326,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1340,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1341,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1349,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1352,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1363,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1368,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1371,   320,   321,   322,   323,
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
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1398,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1403,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1404,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1513,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1525,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1526,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1527,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1528,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1529,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1530,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1531,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1532,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1533,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1534,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1535,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1536,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1537,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1538,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1539,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1540,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1541,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1542,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1543,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1544,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1545,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1547,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1549,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1634,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1635,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1636,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1637,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1638,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1639,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1640,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1641,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1642,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1643,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1644,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1645,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1646,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1647,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1648,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1649,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1650,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1651,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1652,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1653,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1654,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1733,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1734,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1735,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1736,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1737,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1738,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1739,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1740,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1741,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1742,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1743,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1744,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1745,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1746,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1747,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1748,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1749,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1750,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1751,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1752,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1753,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1810,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1817,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1818,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1819,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1820,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1821,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1822,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1823,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1824,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1825,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1826,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1827,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1828,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1829,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1830,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1831,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1832,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1833,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1834,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1869,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1877,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1878,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1879,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1880,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1881,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1882,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1883,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1884,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1885,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1886,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1887,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1888,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1889,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1890,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1891,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1892,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1893,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1894,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1933,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1934,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1935,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1936,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1937,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1938,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1939,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1940,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1941,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1942,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1943,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1944,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1945,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1946,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1947,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1948,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1949,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1950,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1982,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1983,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1984,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1985,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1986,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1987,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1988,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1989,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1990,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1991,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  1992,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  1993,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  1994,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  1995,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  1996,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2020,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2021,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2022,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2023,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2024,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2025,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2026,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2027,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2028,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2029,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2030,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2031,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2032,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2033,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2034,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2064,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2065,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2066,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2067,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2068,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2069,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2070,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2071,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2072,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2073,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2074,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2075,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2076,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2077,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2078,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2108,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2109,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2110,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2111,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2112,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2113,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2114,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2115,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2116,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2139,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2140,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2141,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2142,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2143,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2144,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2145,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2146,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2147,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2181,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2182,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2183,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2184,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2185,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2186,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2187,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2188,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2189,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2211,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2212,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2213,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2214,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2215,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2216,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2229,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2230,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2231,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2232,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2233,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2234,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2250,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2251,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2252,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2253,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2254,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2255,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2274,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2275,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2276,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2286,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2287,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2288,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2301,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2302,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2303,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2320,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2321,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2325,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   317,   318,
     319,  2326,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
       0,     0,   317,   318,   319,  2327,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,     0,     0,   317,   318,   319,  2331,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,     0,     0,
     317,   318,   319,  2332,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,     0,     0,   317,   318,   319,  2333,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,   317,   318,   319,   634,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,   317,   318,   319,   693,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,   317,   318,   319,
     695,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,   317,   318,
     319,   697,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,   317,
     318,   319,   699,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
     317,   318,   319,   701,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,   317,   318,   319,   703,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,   317,   318,   319,   705,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,   317,   318,   319,   707,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,   317,   318,   319,   709,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,   317,   318,   319,   711,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,   317,   318,   319,   713,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,   317,   318,   319,
     717,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,   317,   318,
     319,   719,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,   317,
     318,   319,   721,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
     317,   318,   319,   723,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,   317,   318,   319,   725,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,   317,   318,   319,   727,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,   317,   318,   319,   799,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,   317,   318,   319,   805,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,   317,   318,   319,   897,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,   317,   318,   319,  1045,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,   317,   318,   319,
    1047,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,   317,   318,
     319,  1049,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,   317,
     318,   319,  1051,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
     317,   318,   319,  1052,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,   317,   318,   319,  1196,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,   528,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   529,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   531,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,   533,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,   534,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   542,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,   584,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,   585,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,   588,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
     594,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,   692,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   694,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   696,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,   698,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,   700,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   702,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,   704,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,   706,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,   708,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
     710,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,   712,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   716,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   718,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,   720,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,   722,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   724,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,   726,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,   762,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,   764,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
     777,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,   778,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,   779,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,   784,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,   785,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,   786,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,   787,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,   788,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,   811,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,   818,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    1044,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,  1046,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,  1048,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,  1050,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,  1117,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,  1223,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,  1251,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,  1358,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,  1362,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  1364,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    1486,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,  1487,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,  1516,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,  1518,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,  1520,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,  1522,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,  1523,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,  1524,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,  1546,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  1656,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    1814,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,  1815,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,  1816,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,  1979,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,  1980,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,  1981,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,  2102,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,  2103,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,  2104,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  2105,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    2106,   317,   318,   319,     0,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,     0,     0,     0,     0,
       0,   331,     0,  2107,   317,   318,   319,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,   331,     0,  2217,   317,   318,   319,
       0,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,     0,     0,     0,     0,     0,   331,     0,  2218,
     317,   318,   319,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,     0,     0,     0,
     331,     0,  2219,   317,   318,   319,     0,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
       0,     0,     0,   331,     0,  2277,   317,   318,   319,     0,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,     0,     0,     0,     0,     0,   331,     0,  2278,   317,
     318,   319,     0,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,     0,     0,     0,     0,     0,   331,
       0,  2279,   317,   318,   319,     0,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,     0,     0,     0,
       0,     0,   331,     0,  2337,   317,   318,   319,     0,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,     0,     0,     0,   331,     0,  2338,   317,   318,
     319,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,     0,     0,     0,   331,     0,
    2339
};

static const short yycheck[] =
{
      25,    71,    72,    25,    96,     5,   376,   310,     5,   346,
     187,   752,     4,   190,     4,     4,    47,    48,     5,     4,
       4,     3,     5,    66,    66,     6,     6,    43,     6,  1337,
       6,  1339,    66,     4,   211,    67,   213,  1242,  1417,     6,
      72,    67,  1421,   105,     4,  1424,    72,    34,    35,    36,
      67,    34,    35,    36,    67,    72,    67,     4,     6,    72,
      67,    72,  1135,    67,    67,    72,     4,     5,    72,    72,
       5,  1144,   188,   189,     6,   188,   189,   199,  1151,     6,
     200,  1118,  1119,    50,   206,   205,   188,   189,   199,   205,
      39,   207,   205,    42,   207,   206,    34,    35,    36,    34,
      35,    36,    50,   205,   199,   207,   188,   189,   133,   134,
     135,   206,   199,   138,   139,    57,    58,   142,   200,   206,
     188,   189,   188,   189,   149,     5,   151,   152,   153,   308,
     155,   199,   157,   158,     0,   160,   217,   199,   206,    67,
     206,   188,   189,   174,    72,   176,     7,  1352,   108,   109,
       6,   182,   177,   178,    34,    35,    36,   199,   199,   206,
     201,   108,   109,   206,   206,   199,     6,   346,   909,   188,
     189,   196,   197,   200,   199,   207,   201,   200,   205,   204,
     205,   207,   205,   199,   190,   191,   192,   206,   525,   199,
     207,   201,   198,     6,   207,     7,   207,   199,   501,   201,
     207,   538,     7,   207,   207,   196,   197,   189,   188,   189,
     188,   189,   188,   189,   206,   169,   206,   206,     6,   206,
     397,   206,   206,   206,   255,   206,     7,   252,   199,   299,
     300,   301,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   201,  1312,   200,     8,     6,   207,
    1353,   205,  1661,   308,  1357,   200,  1665,   199,   310,  1668,
     205,   199,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,  1615,     6,   200,
    1618,     6,  1620,   338,   205,   340,   196,   197,   196,   197,
     345,   346,   199,   203,  1065,   203,   199,   408,   201,   354,
     355,   356,   357,   358,   199,   360,   361,   362,   363,   364,
     365,   366,   373,   374,   196,   197,   525,    67,   199,   201,
       7,   203,    72,   378,   379,   380,   381,   188,   189,   538,
     385,    56,   174,   175,   176,   177,   188,   189,   393,   174,
     175,   176,   177,   199,   205,   375,   376,   402,   375,   376,
    1759,     6,     7,   205,  1763,   199,  1765,   188,   189,     6,
       7,   196,   197,   174,   175,   176,   177,   199,   203,   201,
     737,   188,   189,     8,   205,  1713,     3,   165,   166,  1717,
     168,  1719,   188,   189,    66,   196,   197,   199,   205,   188,
     189,   199,   199,   445,   188,   189,   188,   189,   199,   205,
     201,   768,   502,   188,   189,    47,   205,  1510,  1511,  1512,
    1513,   205,    43,   205,  1517,    43,    45,   178,   179,   180,
     205,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    43,   800,   801,   802,   803,   198,    43,   494,
     188,   189,   497,   199,    42,    43,   207,    45,   503,   501,
       6,   206,   200,   178,   179,   180,    43,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   206,     4,
     525,   526,     6,   198,   188,   189,   190,   191,   192,     6,
     535,   536,   199,   538,   198,   540,   541,   174,   175,   176,
     177,   199,   199,   548,   196,   197,   557,     6,   199,   201,
     201,   203,    39,   558,   559,    42,    43,    43,    45,   196,
     197,   199,   567,   140,   141,   142,   143,   144,   145,   146,
     147,     4,  1625,  1626,   579,     4,  1629,    39,   737,   199,
      42,    43,   199,   742,   634,   590,     5,   592,   593,   199,
     199,   201,   201,   178,   179,   180,  1317,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   199,   768,
     201,   928,   199,   198,   201,   200,   199,     4,   901,   902,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   199,   634,   201,     5,   199,   198,   201,     4,     3,
       4,   800,   801,   802,   803,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   199,
    1723,   201,   178,   179,   180,    39,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   199,   738,   201,
       6,   199,   198,   201,     6,   199,    60,    61,    62,    63,
      64,    65,   199,   199,   201,   201,     6,   196,   197,   714,
     715,   199,   201,   201,   203,   196,   197,   199,   201,   201,
     201,   199,   203,   728,   729,   730,   731,   732,   733,   734,
     206,   199,   737,   201,   199,   199,     6,   742,   199,   206,
     745,    60,    61,    62,    63,   201,    65,   203,   759,   206,
     755,   199,  1102,   125,   126,   127,   128,   129,   205,  1812,
     207,   199,   205,   768,   207,   770,   205,   199,   207,   928,
     205,   205,   207,   207,   199,   205,     6,   207,   206,   205,
     852,   207,   205,     6,   207,   796,   797,   798,   205,   205,
     207,   207,   205,   203,   207,   800,   801,   802,   803,   206,
     206,   806,   807,   206,   111,   810,     6,   205,   205,   207,
     207,   205,   823,   207,     6,   199,   821,   822,     6,     6,
    1873,   832,     3,   199,   188,   189,   205,   205,   207,   207,
     194,   205,   205,   207,   207,   199,   205,   205,   207,   207,
     204,     6,   206,   205,   205,   207,   207,   205,   205,   207,
     207,   199,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   178,   179,
     180,   199,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   199,     6,   897,     5,   205,   198,   207,
     902,   205,   205,   207,   207,   910,   199,   199,   178,   179,
     180,   916,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   928,   205,   930,   207,   932,   198,   180,
     199,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   199,   948,   949,   950,   199,   198,   178,   179,
     180,   199,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   205,   205,   970,   971,   972,   198,   205,
     205,   207,   207,   205,   205,   207,   207,   199,   178,   179,
     180,  1331,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   205,   205,   207,   207,   205,   198,   207,
     205,   205,   207,   207,  2057,   199,   159,  1057,   205,   199,
     207,  1013,   165,   178,   179,   180,   199,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   205,     6,
     207,   199,   205,   198,   207,   188,   199,   199,   199,   199,
     193,   194,   199,   199,   199,   199,     4,   199,  1098,   199,
     199,     6,   199,  1058,   199,   199,   199,   198,   200,     7,
    1071,     7,  1073,   203,   201,  1126,   178,   179,   180,     7,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,  1086,  1087,  1088,  1089,  1157,   198,   206,     7,   200,
       7,     7,  1103,  1098,  1105,   106,  1107,   158,     6,   184,
     185,   186,   187,   188,   189,   190,   191,   192,  1113,  1114,
     108,   206,     5,   198,     5,     5,     5,     5,     5,     5,
    1125,     5,  1102,  1128,     5,  1102,     5,     5,     5,     5,
       5,     5,     5,  1138,     5,     5,     5,     5,     5,     5,
    1145,  1146,  1147,     5,     5,     5,     5,  1152,     5,     3,
       5,  1156,     5,   205,     6,  1160,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,     5,   200,     6,     4,   202,     7,     6,   203,     7,
       7,     7,  1253,  1198,     7,     7,     7,   207,   207,   206,
    1205,   178,   179,   180,   206,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     7,     7,   199,  1224,
       7,   198,   205,   178,   179,   180,   170,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     8,     3,
       4,   203,  1247,   198,  1249,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   205,
     178,   179,   180,     6,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     3,     4,   205,     5,  1350,
     198,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   200,     6,   199,     4,   199,
    1325,  1326,   205,  1334,     6,  1336,     6,  1338,     6,  1334,
       7,  1336,     6,  1338,   206,  1340,  1341,     7,   202,     7,
     205,  1346,   205,   496,     7,     7,     7,   205,   199,   205,
    1355,  1331,   199,     7,  1331,   205,   205,   205,  1363,   205,
     205,   205,   205,  1368,   205,   205,  1371,   205,  1373,  1374,
    1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,   199,   205,   205,   205,  1403,   205,
    1411,   205,   205,  1408,   205,  1410,  1411,  1412,   178,   179,
     180,   205,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   205,   188,   189,   205,   205,   198,   205,
     194,   205,   199,   199,   199,   199,   199,   199,   202,   199,
     204,   199,   206,   199,   199,   178,   179,   180,  1509,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     199,   199,   199,   199,   199,   198,   206,   199,   199,   199,
     188,   189,   199,   199,   199,   199,   194,     7,   201,     7,
       7,   199,     7,     7,   202,     7,   204,  1492,   206,     7,
       7,     4,     6,  1498,     6,     4,  1501,     7,   171,     7,
       3,     3,     3,   190,     3,     3,     3,     3,     3,     3,
       3,  1572,     3,     3,     3,     3,   200,   200,     5,     5,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,
    1545,     3,  1547,     3,  1549,   178,   179,   180,     6,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       4,     6,   203,  1624,     7,   198,     6,     3,     4,     6,
     199,     6,   205,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     6,   199,   206,
       6,     6,   107,   206,   167,  1655,   205,   760,   761,   205,
     763,   200,   765,   766,   205,   200,   200,   205,   205,   205,
     200,   200,   205,   205,   205,   200,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
     205,   205,   205,   205,   205,   808,   809,   205,   205,   812,
       8,  1722,   205,   205,   200,   205,   205,     6,   203,     6,
       4,     6,   206,     6,     6,     6,   829,   830,     6,   202,
       6,     6,   835,   836,     6,     6,     6,     6,     6,   842,
       6,   844,     6,     6,     6,     6,     6,     6,     6,   107,
       7,     3,     6,     3,  1754,     6,  1756,  1768,   190,     6,
       6,     3,     6,     3,     7,     6,  1721,     6,     3,     6,
       3,     3,  1727,     3,  1729,     6,  1731,     4,  1733,  1734,
    1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,
    1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,     6,
    1811,     6,   188,   189,     6,   203,   202,     6,   194,   206,
     104,   200,   200,   199,   205,   207,   202,   920,   204,   922,
     206,   200,   206,   206,   206,   206,     8,   205,   205,   205,
     933,   934,   935,   205,   200,  1835,   205,   940,   941,   942,
     943,   944,   945,   946,   205,   205,   200,   200,   200,   200,
       6,     3,   107,   109,  1809,  1810,     6,     6,     3,     6,
       6,     3,  1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,
    1825,  1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,
     178,   179,   180,     6,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     6,     6,     6,     6,     5,
     198,     6,     5,   207,     6,   206,   206,     6,   205,   200,
       8,   207,   205,   205,  1869,   205,     6,   205,   167,  1874,
    1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,  1884,
    1885,  1886,  1887,  1888,  1889,  1890,  1891,  1892,  1893,  1894,
     205,     6,     6,     6,     6,     6,     6,   200,     6,     6,
       6,     6,   200,  1056,     8,   178,   179,   180,     6,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       6,   205,  1927,     6,  1929,   198,  1931,   200,  1933,  1934,
    1935,  1936,  1937,  1938,  1939,  1940,  1941,  1942,  1943,  1944,
    1945,  1946,  1947,  1948,  1949,  1950,   178,   179,   180,     6,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     5,     5,   206,   205,   205,   198,   206,  1121,   206,
     205,   207,   205,   200,   200,   205,  1129,  1982,  1983,  1984,
    1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,  1993,  1994,
    1995,  1996,   205,     6,   206,  1148,   206,   206,   206,     6,
     205,     6,     6,     6,   104,     6,     6,     5,   206,     6,
       5,   205,  2017,  2018,  2019,  2020,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,  2034,
     178,   179,   180,  1186,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   207,   167,     6,     6,   206,
     198,     6,   206,  2058,   205,  2060,   206,  2062,   200,  2064,
    2065,  2066,  2067,  2068,  2069,  2070,  2071,  2072,  2073,  2074,
    2075,  2076,  2077,  2078,   178,   179,   180,   200,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   206,
       6,   207,   104,     6,   198,     6,     6,     6,     6,     6,
       6,     6,   205,  2108,  2109,  2110,  2111,  2112,  2113,  2114,
    2115,  2116,   207,   206,   205,     6,     6,     6,     6,   172,
     205,   205,     6,   173,   206,   206,   206,   205,  2133,  2134,
    2135,  2136,  2137,  2138,  2139,  2140,  2141,  2142,  2143,  2144,
    2145,  2146,  2147,   178,   179,   180,   200,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     6,     6,
       6,     6,     6,   198,  2169,   205,  2171,   202,  2173,   205,
    2175,   205,  2177,   206,  2179,   206,  2181,  2182,  2183,  2184,
    2185,  2186,  2187,  2188,  2189,   206,     6,     6,     6,   200,
       6,   206,  1345,     6,     6,     6,  1349,   206,   206,     6,
     206,     6,     6,     6,   206,     6,  2211,  2212,  2213,  2214,
    2215,  2216,  1365,   206,   206,   206,   206,     6,   206,   206,
     206,     6,     6,     6,  2229,  2230,  2231,  2232,  2233,  2234,
    2235,  2236,  2237,   206,   206,   206,     6,     6,     6,   636,
       5,     5,    -1,    -1,    -1,  2250,  2251,  2252,  2253,  2254,
    2255,  2256,    -1,  2258,  1061,  2260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2274,
    2275,  2276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2286,  2287,  2288,  2289,  2290,  2291,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2301,  2302,  2303,  2304,
      -1,  2306,    -1,  2308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2319,  2320,  2321,    -1,    -1,    -1,
    2325,  2326,  2327,    -1,    -1,    -1,  2331,  2332,  2333,    -1,
      -1,    -1,    -1,  1486,  1487,    -1,    -1,    -1,  2343,  2344,
    2345,  1494,    -1,    -1,    -1,    -1,    -1,  2352,    -1,  2354,
      -1,  2356,  1505,  1506,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,  1551,  1552,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,    -1,    -1,    -1,  1617,     3,     4,    -1,    -1,  1622,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    -1,    50,    51,    52,    -1,    54,    55,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,   204,    -1,   206,    -1,    -1,
      -1,  1714,    -1,    -1,   101,   102,   103,    -1,    -1,    -1,
      -1,  1724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
     189,    -1,   119,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,   204,    -1,   206,   174,   175,
     176,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,   197,    -1,   199,    -1,   201,    -1,   203,   204,   178,
     179,   180,    -1,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
     188,   189,    -1,    -1,    -1,    -1,   194,    -1,   207,    -1,
    1813,   199,    -1,     3,     4,     5,   204,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    36,   178,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,     3,     4,    -1,   198,    -1,  1872,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,     3,     4,    -1,
      -1,   205,  1925,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    -1,    50,
      51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1978,    -1,   178,   179,   180,
      71,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,   188,   189,
      -1,    -1,    -1,    -1,   194,    -1,   207,    -1,    -1,   199,
     101,   102,   103,  2016,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,     0,
       1,    -1,     3,     4,   178,   179,   180,    -1,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   188,
     189,    -1,    -1,    -1,   198,   194,    -1,    -1,    -1,    -1,
     199,   205,    33,   207,    -1,   204,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,   199,    -1,    -1,   207,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    -1,    50,    51,    52,    -1,    54,    55,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    50,    51,
      52,   119,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    71,
      48,    -1,    50,    51,    52,    -1,    54,    55,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    50,    51,    52,   119,    54,    55,
      -1,    -1,    -1,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,   207,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,    -1,    -1,   101,   102,   103,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    -1,   159,   160,   161,
     162,   163,   164,    -1,    -1,   207,   178,   179,   180,    -1,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   207,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,   207,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,   198,   207,    -1,   100,   101,   102,   103,
     205,    -1,   207,    -1,   108,    -1,   110,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,   207,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,   205,    -1,   207,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
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
      -1,    -1,    -1,    -1,   178,   179,   180,   207,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,   207,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,   207,
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
     198,    -1,    -1,    -1,   178,   179,   180,   205,   182,   183,
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
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,   178,
     179,   180,   202,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
     178,   179,   180,   202,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,   178,   179,   180,   202,   182,   183,   184,   185,   186,
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
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200
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
     199,   199,   199,   206,     6,   330,   330,   330,   330,   330,
     330,   330,   330,   330,     4,   340,   344,   202,     6,   330,
     339,   202,     4,   108,   109,   330,     6,     6,     6,     7,
     201,   341,   343,     6,   330,   200,   205,   332,   338,   338,
       7,   338,     7,   338,   338,   340,   207,   202,   206,   207,
       8,     6,   206,     7,     7,     7,     7,     7,     6,    56,
       7,     7,     7,     7,     7,     7,     7,     4,   205,   205,
     205,   207,   332,   332,   332,     6,   340,   340,   340,   340,
       6,     6,   330,   330,   338,   338,   330,     7,   338,     4,
     205,     8,     8,   200,     7,   171,     3,   330,   330,   332,
       3,     3,   190,     3,     3,   338,   338,     3,   332,     3,
       3,   338,   338,     3,     3,     3,     3,     3,   338,   125,
     126,   127,   128,   129,   329,   338,     3,     5,     5,     3,
       3,     6,   334,     4,     6,   207,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   337,   338,   200,   202,   200,   202,   200,   202,
     200,   202,   202,   200,   200,   200,   302,     7,   302,   303,
     203,     7,     6,   341,   330,   205,   207,     6,   330,     6,
       6,    50,     6,    50,   338,     6,   338,     6,     6,   207,
     340,   330,   330,   338,   338,   338,   199,   199,    57,    58,
     338,   338,   338,   338,   338,   338,   338,     6,     7,   330,
     330,   330,   206,   205,   207,   205,   207,   205,   207,   207,
     207,   207,   207,   205,   205,     6,     6,   200,   199,   206,
     336,   107,   330,   330,   330,   206,   167,   205,   205,   205,
     200,   205,   200,   205,   200,   205,   200,   205,   205,   200,
     205,   200,   200,   205,   205,   205,   205,   205,   205,   200,
     205,   205,   205,   205,   205,   200,   205,   205,   303,     6,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   207,   203,   338,
     344,   330,     6,     4,   342,     6,   202,   341,   205,   332,
     332,     6,     6,   202,   207,   205,     6,     6,     6,   330,
     330,   330,   330,     6,     6,     6,     6,     6,     6,     6,
     330,   344,   207,   200,   205,   207,   307,   332,     6,   316,
     332,     6,   319,   332,     6,   322,     6,     6,     6,     6,
     330,   330,     7,   337,   337,   107,   338,   205,   207,     8,
     207,   200,   330,   210,     3,   330,   338,     6,     3,     6,
     190,     6,   329,     6,     3,   330,     6,     3,     6,     6,
       3,   329,   330,   330,   330,   338,     6,     3,   329,   330,
       3,     3,     6,   330,   334,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   338,   206,     4,     6,     6,     6,     7,     6,   203,
     330,     6,     6,   202,   330,   205,   205,     6,     6,     6,
       6,   206,   330,   207,   205,   206,   205,   206,   205,   206,
     205,   205,   336,   200,   207,   206,   104,   330,   330,   205,
     210,   200,   205,   205,   205,   205,   200,   205,   200,   205,
     200,   200,   200,   205,   200,   205,   200,   200,   205,   205,
     200,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   337,
     200,   341,   109,   205,   205,   330,   330,   307,   205,   207,
     188,   189,   199,   330,   332,    67,    72,   325,   326,   330,
     332,   325,   330,   332,   325,   330,   330,   107,   338,   330,
     207,   207,   338,   210,     6,   336,   329,     3,   330,     6,
     329,     6,     3,     6,     6,     6,   330,     6,   338,     6,
       6,   330,     3,     6,   330,     5,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   207,     6,   330,     5,   200,   200,   207,   330,
     330,   207,   205,     6,   206,   207,   326,   207,   205,   207,
     207,   205,   207,   207,   207,   206,   205,     6,   207,   167,
     205,   205,   205,   205,   200,   200,   200,   205,   200,   200,
     200,   205,   200,   200,   200,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   200,   205,     6,   205,
     205,   338,   338,   207,     6,   317,   330,   338,     6,     6,
     320,   330,     6,     6,   323,   330,     6,     6,     6,   338,
     338,     6,   210,   329,   329,   329,   329,     6,     6,     6,
     329,     6,     6,     6,     5,   225,   228,   231,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   297,
     330,   330,     5,   338,   338,   206,   207,   205,   206,   207,
     206,   207,   205,   207,   210,   205,   205,   200,   200,   205,
     205,   206,   206,   206,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   206,   200,   207,   205,     6,
       6,   325,     6,   318,   338,   325,     6,   321,   325,     6,
     324,   338,   104,   210,   329,   329,     6,     6,   329,     5,
     223,   330,   226,   330,   229,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   295,   344,   300,
       6,     5,   207,   206,   205,   207,   207,   206,   207,   206,
     207,   206,   167,   205,   205,   200,   200,   205,   207,   205,
     207,   205,   207,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   207,   206,   207,     6,   325,
     338,     6,     6,   325,     6,   325,   104,   330,   210,   329,
     338,     6,     6,   330,     6,   330,     6,   330,     6,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     344,     6,   298,   344,     6,   207,   207,   207,   207,   206,
     205,   210,   205,   205,   200,   200,   200,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   207,     6,     6,     6,
       6,   330,   330,   210,   329,   338,   234,   237,   240,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   344,     6,   205,
     207,   172,   205,   205,   206,   206,   206,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   330,     6,   173,   338,   329,
     232,   330,   235,   330,   238,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   207,   205,   200,   205,   207,   205,
     207,   205,   207,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,     6,   338,     6,   330,     6,   330,     6,   330,     6,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   205,   200,
     200,   200,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   338,   243,   246,
     249,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   205,   206,   206,   206,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   338,   241,   330,   244,   330,
     247,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   205,   205,   207,
     205,   207,   205,   207,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   329,
     330,     6,   330,     6,   330,     6,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   200,   200,   200,   200,   200,   200,   200,   205,   205,
     205,   205,   205,   205,   205,   205,   205,     6,   252,   255,
     258,   261,   264,   267,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   206,   206,   206,   206,   206,   206,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   250,   330,
     253,   330,   256,   330,   259,   330,   262,   330,   265,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   205,
     207,   205,   207,   205,   207,   205,   207,   205,   207,   205,
     207,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     330,     6,   330,     6,   330,     6,   330,     6,   330,     6,
     330,     6,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   205,   205,   205,   205,   205,   205,   200,   200,   200,
     330,   330,   330,   330,   330,   330,   288,   291,   294,   205,
     205,   205,   205,   205,   205,   206,   206,   206,   330,   330,
     330,   330,   330,   330,   286,   330,   289,   330,   292,   330,
     205,   205,   205,   205,   205,   205,   205,   207,   205,   207,
     205,   207,   330,   330,   330,   330,   330,   330,   330,     6,
     330,     6,   330,     6,   205,   205,   205,   200,   200,   200,
     330,   330,   330,   279,   282,   285,   205,   205,   205,   206,
     206,   206,   330,   330,   330,   277,   330,   280,   330,   283,
     330,   205,   205,   205,   205,   207,   205,   207,   205,   207,
     330,   330,   330,   330,     6,   330,     6,   330,     6,   205,
     205,   205,   330,   330,   330,   205,   205,   205,   330,   330,
     330,   205,   205,   205,   330,   330,   330,   200,   200,   200,
     270,   273,   276,   206,   206,   206,   268,   330,   271,   330,
     274,   330,   205,   207,   205,   207,   205,   207,   330,     6,
     330,     6,   330,     6
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

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
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
| TOP (included).                                                   |
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

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
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
#line 171 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 177 "Gmsh.y"
    { yyval.d = yyvsp[0].d; ;}
    break;

  case 7:
#line 178 "Gmsh.y"
    { yyval.d = -yyvsp[0].d; ;}
    break;

  case 10:
#line 188 "Gmsh.y"
    {
      yymsg(INFO, "Reading STL solid");
      STL_Surf = Create_Surface(NEWSURFACE(), MSH_SURF_STL);
      STL_Surf->STL = new STL_Data;
      return 1;
    ;}
    break;

  case 11:
#line 202 "Gmsh.y"
    {
      STL_Surf->STL->Add_Facet(yyvsp[-12].d, yyvsp[-11].d, yyvsp[-10].d,
			       yyvsp[-8].d, yyvsp[-7].d, yyvsp[-6].d,
			       yyvsp[-4].d, yyvsp[-3].d, yyvsp[-2].d, CTX.geom.stl_create_elementary);
      return 1;
    ;}
    break;

  case 12:
#line 209 "Gmsh.y"
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
#line 231 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 232 "Gmsh.y"
    { return 1; ;}
    break;

  case 17:
#line 233 "Gmsh.y"
    { return 1; ;}
    break;

  case 18:
#line 238 "Gmsh.y"
    {
      yymsg(INFO, "Reading Step Iso-10303-21 data");
      Create_Step_Solid_BRep();
    ;}
    break;

  case 19:
#line 243 "Gmsh.y"
    {
      Resolve_BREP ();
      yymsg(INFO, "Read Step Iso-10303-21 data");
    ;}
    break;

  case 23:
#line 254 "Gmsh.y"
    {
    ;}
    break;

  case 24:
#line 257 "Gmsh.y"
    {
    ;}
    break;

  case 25:
#line 261 "Gmsh.y"
    {
   ;}
    break;

  case 26:
#line 267 "Gmsh.y"
    {
        Add_Cartesian_Point((int)yyvsp[-8].d, yyvsp[-4].c, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2]);
    ;}
    break;

  case 27:
#line 273 "Gmsh.y"
    {
       Add_BSpline_Curve_With_Knots ((int)yyvsp[-22].d, yyvsp[-18].c, (int) yyvsp[-16].d, yyvsp[-14].l,	yyvsp[-6].l, yyvsp[-4].l, 0., 1.);
    ;}
    break;

  case 28:
#line 280 "Gmsh.y"
    {
      Add_BSpline_Surface_With_Knots ((int)yyvsp[-30].d, yyvsp[-26].c, (int) yyvsp[-24].d, (int) yyvsp[-22].d, yyvsp[-20].l, yyvsp[-10].l,
				      yyvsp[-8].l, yyvsp[-6].l, yyvsp[-4].l, 0., 1., 0., 1. );
    ;}
    break;

  case 29:
#line 286 "Gmsh.y"
    {
      Add_Edge_Curve ((int)yyvsp[-14].d, yyvsp[-10].c , (int)yyvsp[-8].d , (int)yyvsp[-6].d, (int)yyvsp[-4].d);
    ;}
    break;

  case 30:
#line 290 "Gmsh.y"
    {
      Add_Face_Outer_Bound((int)yyvsp[-10].d, yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-2].i, 1);
    ;}
    break;

  case 31:
#line 294 "Gmsh.y"
    {
      // check the norm! Face_Bound : hole outside surface!
      yymsg(INFO, "Found a face bound");
      Add_Face_Outer_Bound((int)yyvsp[-10].d, yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-2].i, 0);
    ;}
    break;

  case 32:
#line 301 "Gmsh.y"
    {
      Add_Oriented_Edge((int)yyvsp[-14].d, yyvsp[-10].c, (int)yyvsp[-4].d, yyvsp[-2].i);
    ;}
    break;

  case 33:
#line 305 "Gmsh.y"
    {
      Add_Edge_Loop((int)yyvsp[-8].d, yyvsp[-4].c, yyvsp[-2].l);
    ;}
    break;

  case 34:
#line 310 "Gmsh.y"
    {
      Add_Advanced_Face((int)yyvsp[-12].d, yyvsp[-8].c, yyvsp[-6].l, (int)yyvsp[-4].d, yyvsp[-2].i);
    ;}
    break;

  case 35:
#line 314 "Gmsh.y"
    {
      Add_Vertex_Point((int)yyvsp[-8].d, yyvsp[-4].c, (int)yyvsp[-2].d);
    ;}
    break;

  case 36:
#line 318 "Gmsh.y"
    {
    ;}
    break;

  case 37:
#line 322 "Gmsh.y"
    {
      Add_Axis2_Placement3D  ((int)yyvsp[-12].d, (int)yyvsp[-4].d, (int)yyvsp[-2].d, (int)yyvsp[-6].d);
    ;}
    break;

  case 38:
#line 326 "Gmsh.y"
    {
      Add_Direction((int)yyvsp[-8].d , yyvsp[-4].c, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2]);
    ;}
    break;

  case 39:
#line 330 "Gmsh.y"
    {
      Add_Plane((int)yyvsp[-8].d, yyvsp[-4].c, (int)yyvsp[-2].d);
    ;}
    break;

  case 40:
#line 334 "Gmsh.y"
    {
      Add_Line ((int)yyvsp[-10].d, yyvsp[-6].c , (int) yyvsp[-4].d, (int)yyvsp[-2].d);
    ;}
    break;

  case 41:
#line 338 "Gmsh.y"
    {
      yymsg(INFO, "Found a closed shell");
      Add_Closed_Shell((int)yyvsp[-8].d, yyvsp[-4].c , yyvsp[-2].l);
    ;}
    break;

  case 42:
#line 344 "Gmsh.y"
    {
    ;}
    break;

  case 43:
#line 347 "Gmsh.y"
    {
    ;}
    break;

  case 44:
#line 350 "Gmsh.y"
    {
      Add_Cylinder ((int)yyvsp[-10].d, yyvsp[-6].c , (int)yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 45:
#line 354 "Gmsh.y"
    {
      Add_Cone ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 46:
#line 358 "Gmsh.y"
    {
      Add_Torus ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 47:
#line 362 "Gmsh.y"
    {
      Add_Circle((int) yyvsp[-10].d, yyvsp[-6].c, (int) yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 48:
#line 366 "Gmsh.y"
    {
      Add_Ellipse((int) yyvsp[-12].d, yyvsp[-8].c, (int) yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 49:
#line 371 "Gmsh.y"
    {
    ;}
    break;

  case 50:
#line 374 "Gmsh.y"
    {
    ;}
    break;

  case 51:
#line 378 "Gmsh.y"
    {
    ;}
    break;

  case 52:
#line 381 "Gmsh.y"
    {
    ;}
    break;

  case 53:
#line 385 "Gmsh.y"
    {
    ;}
    break;

  case 54:
#line 388 "Gmsh.y"
    {
    ;}
    break;

  case 55:
#line 391 "Gmsh.y"
    {
    ;}
    break;

  case 58:
#line 403 "Gmsh.y"
    { return 1; ;}
    break;

  case 59:
#line 404 "Gmsh.y"
    { return 1; ;}
    break;

  case 60:
#line 405 "Gmsh.y"
    { return 1; ;}
    break;

  case 61:
#line 406 "Gmsh.y"
    { return 1; ;}
    break;

  case 62:
#line 407 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 63:
#line 408 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 64:
#line 409 "Gmsh.y"
    { return 1; ;}
    break;

  case 65:
#line 410 "Gmsh.y"
    { return 1; ;}
    break;

  case 66:
#line 411 "Gmsh.y"
    { return 1; ;}
    break;

  case 67:
#line 412 "Gmsh.y"
    { List_Delete(yyvsp[0].l); return 1; ;}
    break;

  case 68:
#line 413 "Gmsh.y"
    { return 1; ;}
    break;

  case 69:
#line 414 "Gmsh.y"
    { return 1; ;}
    break;

  case 70:
#line 415 "Gmsh.y"
    { return 1; ;}
    break;

  case 71:
#line 416 "Gmsh.y"
    { return 1; ;}
    break;

  case 72:
#line 421 "Gmsh.y"
    {
      Msg(DIRECT, yyvsp[-2].c);
    ;}
    break;

  case 73:
#line 425 "Gmsh.y"
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
#line 442 "Gmsh.y"
    { 
      if(!strcmp(yyvsp[-5].c, "View") && !CheckViewErrorFlags(View))
	EndView(View, 1, yyname, yyvsp[-4].c);
    ;}
    break;

  case 75:
#line 447 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-7].c, "View") && !CheckViewErrorFlags(View))
	EndView(View, 1, yyname, yyvsp[-6].c);
    ;}
    break;

  case 76:
#line 455 "Gmsh.y"
    {
      View = BeginView(1); 
      for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++){
	ViewErrorFlags[i] = 0;
      }
    ;}
    break;

  case 104:
#line 492 "Gmsh.y"
    { List_Add(View->SP, &yyvsp[0].d); ;}
    break;

  case 105:
#line 494 "Gmsh.y"
    { List_Add(View->SP, &yyvsp[0].d); ;}
    break;

  case 106:
#line 499 "Gmsh.y"
    { 
      List_Add(View->SP, &yyvsp[-5].d); List_Add(View->SP, &yyvsp[-3].d);
      List_Add(View->SP, &yyvsp[-1].d);      
    ;}
    break;

  case 107:
#line 504 "Gmsh.y"
    {
      View->NbSP++;
    ;}
    break;

  case 108:
#line 511 "Gmsh.y"
    { List_Add(View->VP, &yyvsp[0].d); ;}
    break;

  case 109:
#line 513 "Gmsh.y"
    { List_Add(View->VP, &yyvsp[0].d); ;}
    break;

  case 110:
#line 518 "Gmsh.y"
    { 
      List_Add(View->VP, &yyvsp[-5].d); List_Add(View->VP, &yyvsp[-3].d);
      List_Add(View->VP, &yyvsp[-1].d); 
      ntmp = List_Nbr(View->VP);
    ;}
    break;

  case 111:
#line 524 "Gmsh.y"
    {
      if((List_Nbr(View->VP) - ntmp) % 3) ViewErrorFlags[1]++;
      View->NbVP++;
    ;}
    break;

  case 112:
#line 532 "Gmsh.y"
    { List_Add(View->TP, &yyvsp[0].d); ;}
    break;

  case 113:
#line 534 "Gmsh.y"
    { List_Add(View->TP, &yyvsp[0].d); ;}
    break;

  case 114:
#line 539 "Gmsh.y"
    { 
      List_Add(View->TP, &yyvsp[-5].d); List_Add(View->TP, &yyvsp[-3].d);
      List_Add(View->TP, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TP);
    ;}
    break;

  case 115:
#line 545 "Gmsh.y"
    {
      if((List_Nbr(View->TP) - ntmp) % 9) ViewErrorFlags[2]++;
      View->NbTP++;
    ;}
    break;

  case 116:
#line 553 "Gmsh.y"
    { List_Add(View->SL, &yyvsp[0].d); ;}
    break;

  case 117:
#line 555 "Gmsh.y"
    { List_Add(View->SL, &yyvsp[0].d); ;}
    break;

  case 118:
#line 561 "Gmsh.y"
    { 
      List_Add(View->SL, &yyvsp[-11].d); List_Add(View->SL, &yyvsp[-5].d);
      List_Add(View->SL, &yyvsp[-9].d); List_Add(View->SL, &yyvsp[-3].d);
      List_Add(View->SL, &yyvsp[-7].d); List_Add(View->SL, &yyvsp[-1].d);
      ntmp = List_Nbr(View->SL);
    ;}
    break;

  case 119:
#line 568 "Gmsh.y"
    {
      if((List_Nbr(View->SL) - ntmp) % 2) ViewErrorFlags[3]++;
      View->NbSL++;
    ;}
    break;

  case 120:
#line 576 "Gmsh.y"
    { List_Add(View->VL, &yyvsp[0].d); ;}
    break;

  case 121:
#line 578 "Gmsh.y"
    { List_Add(View->VL, &yyvsp[0].d); ;}
    break;

  case 122:
#line 584 "Gmsh.y"
    { 
      List_Add(View->VL, &yyvsp[-11].d); List_Add(View->VL, &yyvsp[-5].d);
      List_Add(View->VL, &yyvsp[-9].d); List_Add(View->VL, &yyvsp[-3].d);
      List_Add(View->VL, &yyvsp[-7].d); List_Add(View->VL, &yyvsp[-1].d);
      ntmp = List_Nbr(View->VL);
    ;}
    break;

  case 123:
#line 591 "Gmsh.y"
    {
      if((List_Nbr(View->VL) - ntmp) % 6) ViewErrorFlags[4]++;
      View->NbVL++;
    ;}
    break;

  case 124:
#line 599 "Gmsh.y"
    { List_Add(View->TL, &yyvsp[0].d); ;}
    break;

  case 125:
#line 601 "Gmsh.y"
    { List_Add(View->TL, &yyvsp[0].d); ;}
    break;

  case 126:
#line 607 "Gmsh.y"
    { 
      List_Add(View->TL, &yyvsp[-11].d); List_Add(View->TL, &yyvsp[-5].d);
      List_Add(View->TL, &yyvsp[-9].d); List_Add(View->TL, &yyvsp[-3].d);
      List_Add(View->TL, &yyvsp[-7].d); List_Add(View->TL, &yyvsp[-1].d);
      ntmp = List_Nbr(View->TL);
    ;}
    break;

  case 127:
#line 614 "Gmsh.y"
    {
      if((List_Nbr(View->TL) - ntmp) % 18) ViewErrorFlags[5]++;
      View->NbTL++;
    ;}
    break;

  case 128:
#line 622 "Gmsh.y"
    { List_Add(View->ST, &yyvsp[0].d); ;}
    break;

  case 129:
#line 624 "Gmsh.y"
    { List_Add(View->ST, &yyvsp[0].d); ;}
    break;

  case 130:
#line 631 "Gmsh.y"
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
#line 641 "Gmsh.y"
    {
      if((List_Nbr(View->ST) - ntmp) % 3) ViewErrorFlags[6]++;
      View->NbST++;
    ;}
    break;

  case 132:
#line 649 "Gmsh.y"
    { List_Add(View->VT, &yyvsp[0].d); ;}
    break;

  case 133:
#line 651 "Gmsh.y"
    { List_Add(View->VT, &yyvsp[0].d); ;}
    break;

  case 134:
#line 658 "Gmsh.y"
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
#line 668 "Gmsh.y"
    {
      if((List_Nbr(View->VT) - ntmp) % 9) ViewErrorFlags[7]++;
      View->NbVT++;
    ;}
    break;

  case 136:
#line 676 "Gmsh.y"
    { List_Add(View->TT, &yyvsp[0].d); ;}
    break;

  case 137:
#line 678 "Gmsh.y"
    { List_Add(View->TT, &yyvsp[0].d); ;}
    break;

  case 138:
#line 685 "Gmsh.y"
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
#line 695 "Gmsh.y"
    {
      if((List_Nbr(View->TT) - ntmp) % 27) ViewErrorFlags[8]++;
      View->NbTT++;
    ;}
    break;

  case 140:
#line 703 "Gmsh.y"
    { List_Add(View->SQ, &yyvsp[0].d); ;}
    break;

  case 141:
#line 705 "Gmsh.y"
    { List_Add(View->SQ, &yyvsp[0].d); ;}
    break;

  case 142:
#line 713 "Gmsh.y"
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
#line 723 "Gmsh.y"
    {
      if((List_Nbr(View->SQ) - ntmp) % 4) ViewErrorFlags[9]++;
      View->NbSQ++;
    ;}
    break;

  case 144:
#line 731 "Gmsh.y"
    { List_Add(View->VQ, &yyvsp[0].d); ;}
    break;

  case 145:
#line 733 "Gmsh.y"
    { List_Add(View->VQ, &yyvsp[0].d); ;}
    break;

  case 146:
#line 741 "Gmsh.y"
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
#line 751 "Gmsh.y"
    {
      if((List_Nbr(View->VQ) - ntmp) % 12) ViewErrorFlags[10]++;
      View->NbVQ++;
    ;}
    break;

  case 148:
#line 759 "Gmsh.y"
    { List_Add(View->TQ, &yyvsp[0].d); ;}
    break;

  case 149:
#line 761 "Gmsh.y"
    { List_Add(View->TQ, &yyvsp[0].d); ;}
    break;

  case 150:
#line 769 "Gmsh.y"
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
#line 779 "Gmsh.y"
    {
      if((List_Nbr(View->TQ) - ntmp) % 36) ViewErrorFlags[11]++;
      View->NbTQ++;
    ;}
    break;

  case 152:
#line 787 "Gmsh.y"
    { List_Add(View->SS, &yyvsp[0].d); ;}
    break;

  case 153:
#line 789 "Gmsh.y"
    { List_Add(View->SS, &yyvsp[0].d); ;}
    break;

  case 154:
#line 797 "Gmsh.y"
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
#line 807 "Gmsh.y"
    {
      if((List_Nbr(View->SS) - ntmp) % 4) ViewErrorFlags[12]++;
      View->NbSS++;
    ;}
    break;

  case 156:
#line 815 "Gmsh.y"
    { List_Add(View->VS, &yyvsp[0].d); ;}
    break;

  case 157:
#line 817 "Gmsh.y"
    { List_Add(View->VS, &yyvsp[0].d); ;}
    break;

  case 158:
#line 825 "Gmsh.y"
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
#line 835 "Gmsh.y"
    {
      if((List_Nbr(View->VS) - ntmp) % 12) ViewErrorFlags[13]++;
      View->NbVS++;
    ;}
    break;

  case 160:
#line 843 "Gmsh.y"
    { List_Add(View->TS, &yyvsp[0].d); ;}
    break;

  case 161:
#line 845 "Gmsh.y"
    { List_Add(View->TS, &yyvsp[0].d); ;}
    break;

  case 162:
#line 853 "Gmsh.y"
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
#line 863 "Gmsh.y"
    {
      if((List_Nbr(View->TS) - ntmp) % 36) ViewErrorFlags[14]++;
      View->NbTS++;
    ;}
    break;

  case 164:
#line 871 "Gmsh.y"
    { List_Add(View->SH, &yyvsp[0].d); ;}
    break;

  case 165:
#line 873 "Gmsh.y"
    { List_Add(View->SH, &yyvsp[0].d); ;}
    break;

  case 166:
#line 885 "Gmsh.y"
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
#line 901 "Gmsh.y"
    {
      if((List_Nbr(View->SH) - ntmp) % 8) ViewErrorFlags[15]++;
      View->NbSH++;
    ;}
    break;

  case 168:
#line 909 "Gmsh.y"
    { List_Add(View->VH, &yyvsp[0].d); ;}
    break;

  case 169:
#line 911 "Gmsh.y"
    { List_Add(View->VH, &yyvsp[0].d); ;}
    break;

  case 170:
#line 923 "Gmsh.y"
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
#line 939 "Gmsh.y"
    {
      if((List_Nbr(View->VH) - ntmp) % 24) ViewErrorFlags[16]++;
      View->NbVH++;
    ;}
    break;

  case 172:
#line 947 "Gmsh.y"
    { List_Add(View->TH, &yyvsp[0].d); ;}
    break;

  case 173:
#line 949 "Gmsh.y"
    { List_Add(View->TH, &yyvsp[0].d); ;}
    break;

  case 174:
#line 961 "Gmsh.y"
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
#line 977 "Gmsh.y"
    {
      if((List_Nbr(View->TH) - ntmp) % 72) ViewErrorFlags[17]++;
      View->NbTH++;
    ;}
    break;

  case 176:
#line 985 "Gmsh.y"
    { List_Add(View->SI, &yyvsp[0].d); ;}
    break;

  case 177:
#line 987 "Gmsh.y"
    { List_Add(View->SI, &yyvsp[0].d); ;}
    break;

  case 178:
#line 997 "Gmsh.y"
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
#line 1010 "Gmsh.y"
    {
      if((List_Nbr(View->SI) - ntmp) % 6) ViewErrorFlags[18]++;
      View->NbSI++;
    ;}
    break;

  case 180:
#line 1018 "Gmsh.y"
    { List_Add(View->VI, &yyvsp[0].d); ;}
    break;

  case 181:
#line 1020 "Gmsh.y"
    { List_Add(View->VI, &yyvsp[0].d); ;}
    break;

  case 182:
#line 1030 "Gmsh.y"
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
#line 1043 "Gmsh.y"
    {
      if((List_Nbr(View->VI) - ntmp) % 18) ViewErrorFlags[19]++;
      View->NbVI++;
    ;}
    break;

  case 184:
#line 1051 "Gmsh.y"
    { List_Add(View->TI, &yyvsp[0].d); ;}
    break;

  case 185:
#line 1053 "Gmsh.y"
    { List_Add(View->TI, &yyvsp[0].d); ;}
    break;

  case 186:
#line 1063 "Gmsh.y"
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
#line 1076 "Gmsh.y"
    {
      if((List_Nbr(View->TI) - ntmp) % 54) ViewErrorFlags[20]++;
      View->NbTI++;
    ;}
    break;

  case 188:
#line 1084 "Gmsh.y"
    { List_Add(View->SY, &yyvsp[0].d); ;}
    break;

  case 189:
#line 1086 "Gmsh.y"
    { List_Add(View->SY, &yyvsp[0].d); ;}
    break;

  case 190:
#line 1095 "Gmsh.y"
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
#line 1108 "Gmsh.y"
    {
      if((List_Nbr(View->SY) - ntmp) % 5) ViewErrorFlags[21]++;
      View->NbSY++;
    ;}
    break;

  case 192:
#line 1116 "Gmsh.y"
    { List_Add(View->VY, &yyvsp[0].d); ;}
    break;

  case 193:
#line 1118 "Gmsh.y"
    { List_Add(View->VY, &yyvsp[0].d); ;}
    break;

  case 194:
#line 1127 "Gmsh.y"
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
#line 1140 "Gmsh.y"
    {
      if((List_Nbr(View->VY) - ntmp) % 15) ViewErrorFlags[22]++;
      View->NbVY++;
    ;}
    break;

  case 196:
#line 1148 "Gmsh.y"
    { List_Add(View->TY, &yyvsp[0].d); ;}
    break;

  case 197:
#line 1150 "Gmsh.y"
    { List_Add(View->TY, &yyvsp[0].d); ;}
    break;

  case 198:
#line 1159 "Gmsh.y"
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
#line 1172 "Gmsh.y"
    {
      if((List_Nbr(View->TY) - ntmp) % 45) ViewErrorFlags[23]++;
      View->NbTY++;
    ;}
    break;

  case 200:
#line 1180 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 201:
#line 1185 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 202:
#line 1193 "Gmsh.y"
    { 
      List_Add(View->T2D, &yyvsp[-5].d); List_Add(View->T2D, &yyvsp[-3].d);
      List_Add(View->T2D, &yyvsp[-1].d); 
      double d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    ;}
    break;

  case 203:
#line 1200 "Gmsh.y"
    {
      View->NbT2++;
    ;}
    break;

  case 204:
#line 1207 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 205:
#line 1212 "Gmsh.y"
    { 
      for(int i = 0; i < (int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]); 
      Free(yyvsp[0].c);
    ;}
    break;

  case 206:
#line 1220 "Gmsh.y"
    { 
      List_Add(View->T3D, &yyvsp[-7].d); List_Add(View->T3D, &yyvsp[-5].d);
      List_Add(View->T3D, &yyvsp[-3].d); List_Add(View->T3D, &yyvsp[-1].d); 
      double d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    ;}
    break;

  case 207:
#line 1227 "Gmsh.y"
    {
      View->NbT3++;
    ;}
    break;

  case 208:
#line 1235 "Gmsh.y"
    {
      View->adaptive = new Adaptive_Post_View(View, yyvsp[-5].l, yyvsp[-2].l);
    ;}
    break;

  case 209:
#line 1243 "Gmsh.y"
    { yyval.i = 0; ;}
    break;

  case 210:
#line 1244 "Gmsh.y"
    { yyval.i = 1; ;}
    break;

  case 211:
#line 1245 "Gmsh.y"
    { yyval.i = 2; ;}
    break;

  case 212:
#line 1246 "Gmsh.y"
    { yyval.i = 3; ;}
    break;

  case 213:
#line 1247 "Gmsh.y"
    { yyval.i = 4; ;}
    break;

  case 214:
#line 1251 "Gmsh.y"
    { yyval.i = 1; ;}
    break;

  case 215:
#line 1252 "Gmsh.y"
    { yyval.i = -1; ;}
    break;

  case 216:
#line 1260 "Gmsh.y"
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
#line 1288 "Gmsh.y"
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
#line 1324 "Gmsh.y"
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
#line 1373 "Gmsh.y"
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
#line 1389 "Gmsh.y"
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
#line 1399 "Gmsh.y"
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
#line 1417 "Gmsh.y"
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
#line 1430 "Gmsh.y"
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
#line 1446 "Gmsh.y"
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
#line 1471 "Gmsh.y"
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
#line 1497 "Gmsh.y"
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
#line 1510 "Gmsh.y"
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
#line 1526 "Gmsh.y"
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
#line 1539 "Gmsh.y"
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
#line 1555 "Gmsh.y"
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
#line 1574 "Gmsh.y"
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
#line 1596 "Gmsh.y"
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
#line 1605 "Gmsh.y"
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
#line 1623 "Gmsh.y"
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
#line 1639 "Gmsh.y"
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
#line 1655 "Gmsh.y"
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
#line 1674 "Gmsh.y"
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
#line 1693 "Gmsh.y"
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
#line 1711 "Gmsh.y"
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
#line 1729 "Gmsh.y"
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
#line 1747 "Gmsh.y"
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
#line 1773 "Gmsh.y"
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
#line 1791 "Gmsh.y"
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
#line 1818 "Gmsh.y"
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
#line 1836 "Gmsh.y"
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
#line 1860 "Gmsh.y"
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
#line 1884 "Gmsh.y"
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
#line 1910 "Gmsh.y"
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
#line 1927 "Gmsh.y"
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
#line 1945 "Gmsh.y"
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
#line 1964 "Gmsh.y"
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
#line 1983 "Gmsh.y"
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
#line 2022 "Gmsh.y"
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
#line 2048 "Gmsh.y"
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
#line 2070 "Gmsh.y"
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
#line 2087 "Gmsh.y"
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
#line 2106 "Gmsh.y"
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
#line 2123 "Gmsh.y"
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
#line 2139 "Gmsh.y"
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
#line 2158 "Gmsh.y"
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
#line 2175 "Gmsh.y"
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
#line 2192 "Gmsh.y"
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
#line 2213 "Gmsh.y"
    {
      TranslateShapes(yyvsp[-3].v[0], yyvsp[-3].v[1], yyvsp[-3].v[2], yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 264:
#line 2218 "Gmsh.y"
    {
      RotateShapes(yyvsp[-8].v[0], yyvsp[-8].v[1], yyvsp[-8].v[2], yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].d, yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 265:
#line 2223 "Gmsh.y"
    {
      SymmetryShapes(yyvsp[-3].v[0], yyvsp[-3].v[1], yyvsp[-3].v[2], yyvsp[-3].v[3], yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 266:
#line 2228 "Gmsh.y"
    {
      DilatShapes(yyvsp[-6].v[0], yyvsp[-6].v[1], yyvsp[-6].v[2], yyvsp[-4].d, yyvsp[-1].l, 1);
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 267:
#line 2235 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 268:
#line 2236 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 269:
#line 2237 "Gmsh.y"
    { yyval.l = yyvsp[0].l; ;}
    break;

  case 270:
#line 2242 "Gmsh.y"
    {
      yyval.l = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 271:
#line 2246 "Gmsh.y"
    {
      List_Add(yyval.l, &yyvsp[0].s);
    ;}
    break;

  case 272:
#line 2250 "Gmsh.y"
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
#line 2266 "Gmsh.y"
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
#line 2282 "Gmsh.y"
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
#line 2298 "Gmsh.y"
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
#line 2319 "Gmsh.y"
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
#line 2332 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) DuplicateView((int)yyvsp[-2].d, 0);
      yyval.l = NULL;
    ;}
    break;

  case 278:
#line 2343 "Gmsh.y"
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
#line 2352 "Gmsh.y"
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
#line 2362 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-1].c, "Meshes") || !strcmp(yyvsp[-1].c, "All"))
	Init_Mesh(THEM);
    ;}
    break;

  case 281:
#line 2372 "Gmsh.y"
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
#line 2386 "Gmsh.y"
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH : 
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber(yyvsp[-1].c, i, m);
    ;}
    break;

  case 283:
#line 2393 "Gmsh.y"
    {
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber(yyvsp[-1].c, i, 0);
    ;}
    break;

  case 284:
#line 2398 "Gmsh.y"
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
#line 2409 "Gmsh.y"
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
#line 2423 "Gmsh.y"
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
#line 2466 "Gmsh.y"
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
    ;}
    break;

  case 288:
#line 2480 "Gmsh.y"
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
#line 2495 "Gmsh.y"
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
#line 2504 "Gmsh.y"
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
#line 2514 "Gmsh.y"
    {
      exit(0);
    ;}
    break;

  case 292:
#line 2518 "Gmsh.y"
    {
      SetBoundingBox();
    ;}
    break;

  case 293:
#line 2522 "Gmsh.y"
    {
      SetBoundingBox(yyvsp[-12].d, yyvsp[-10].d, yyvsp[-8].d, yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    ;}
    break;

  case 294:
#line 2526 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch) // we're in interactive mode
	Draw();
#endif
    ;}
    break;

  case 295:
#line 2539 "Gmsh.y"
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
#line 2553 "Gmsh.y"
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
#line 2567 "Gmsh.y"
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
#line 2592 "Gmsh.y"
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
#line 2617 "Gmsh.y"
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
#line 2644 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction(yyvsp[0].c, yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", yyvsp[0].c);
      skip_until(NULL, "Return");
    ;}
    break;

  case 301:
#line 2650 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    ;}
    break;

  case 302:
#line 2655 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction(yyvsp[-1].c, &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", yyvsp[-1].c);
    ;}
    break;

  case 303:
#line 2660 "Gmsh.y"
    {
      if(!yyvsp[-1].d) skip_until("If", "EndIf");
    ;}
    break;

  case 304:
#line 2664 "Gmsh.y"
    {
    ;}
    break;

  case 305:
#line 2675 "Gmsh.y"
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
#line 2691 "Gmsh.y"
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
#line 2707 "Gmsh.y"
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
#line 2723 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 309:
#line 2728 "Gmsh.y"
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
#line 2744 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 311:
#line 2749 "Gmsh.y"
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
#line 2765 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 313:
#line 2770 "Gmsh.y"
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
#line 2788 "Gmsh.y"
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
#line 2811 "Gmsh.y"
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
#line 2834 "Gmsh.y"
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
#line 2857 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 318:
#line 2862 "Gmsh.y"
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
#line 2885 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 320:
#line 2890 "Gmsh.y"
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
#line 2913 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 322:
#line 2918 "Gmsh.y"
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
#line 2944 "Gmsh.y"
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
#line 2967 "Gmsh.y"
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
#line 2990 "Gmsh.y"
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
#line 3013 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 327:
#line 3018 "Gmsh.y"
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
#line 3041 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 329:
#line 3047 "Gmsh.y"
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
#line 3070 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    ;}
    break;

  case 331:
#line 3076 "Gmsh.y"
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
#line 3102 "Gmsh.y"
    {
    ;}
    break;

  case 333:
#line 3105 "Gmsh.y"
    {
    ;}
    break;

  case 334:
#line 3111 "Gmsh.y"
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
#line 3137 "Gmsh.y"
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
#line 3161 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 337:
#line 3170 "Gmsh.y"
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
#line 3188 "Gmsh.y"
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
#line 3206 "Gmsh.y"
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
#line 3224 "Gmsh.y"
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
#line 3251 "Gmsh.y"
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
#line 3277 "Gmsh.y"
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
#line 3303 "Gmsh.y"
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
#line 3317 "Gmsh.y"
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
#line 3336 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    ;}
    break;

  case 346:
#line 3340 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    ;}
    break;

  case 347:
#line 3349 "Gmsh.y"
    {yyval.i = 1;;}
    break;

  case 348:
#line 3350 "Gmsh.y"
    {yyval.i = 0;;}
    break;

  case 349:
#line 3351 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 350:
#line 3352 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 351:
#line 3353 "Gmsh.y"
    {yyval.i = -1;;}
    break;

  case 352:
#line 3357 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           ;}
    break;

  case 353:
#line 3358 "Gmsh.y"
    { yyval.d = yyvsp[-1].d;           ;}
    break;

  case 354:
#line 3359 "Gmsh.y"
    { yyval.d = -yyvsp[0].d;          ;}
    break;

  case 355:
#line 3360 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           ;}
    break;

  case 356:
#line 3361 "Gmsh.y"
    { yyval.d = !yyvsp[0].d;          ;}
    break;

  case 357:
#line 3362 "Gmsh.y"
    { yyval.d = yyvsp[-2].d - yyvsp[0].d;      ;}
    break;

  case 358:
#line 3363 "Gmsh.y"
    { yyval.d = yyvsp[-2].d + yyvsp[0].d;      ;}
    break;

  case 359:
#line 3364 "Gmsh.y"
    { yyval.d = yyvsp[-2].d * yyvsp[0].d;      ;}
    break;

  case 360:
#line 3366 "Gmsh.y"
    { 
      if(!yyvsp[0].d)
	yymsg(GERROR, "Division by zero in '%g / %g'", yyvsp[-2].d, yyvsp[0].d);
      else
	yyval.d = yyvsp[-2].d / yyvsp[0].d;     
    ;}
    break;

  case 361:
#line 3372 "Gmsh.y"
    { yyval.d = (int)yyvsp[-2].d % (int)yyvsp[0].d;  ;}
    break;

  case 362:
#line 3373 "Gmsh.y"
    { yyval.d = pow(yyvsp[-2].d, yyvsp[0].d);  ;}
    break;

  case 363:
#line 3374 "Gmsh.y"
    { yyval.d = yyvsp[-2].d < yyvsp[0].d;      ;}
    break;

  case 364:
#line 3375 "Gmsh.y"
    { yyval.d = yyvsp[-2].d > yyvsp[0].d;      ;}
    break;

  case 365:
#line 3376 "Gmsh.y"
    { yyval.d = yyvsp[-2].d <= yyvsp[0].d;     ;}
    break;

  case 366:
#line 3377 "Gmsh.y"
    { yyval.d = yyvsp[-2].d >= yyvsp[0].d;     ;}
    break;

  case 367:
#line 3378 "Gmsh.y"
    { yyval.d = yyvsp[-2].d == yyvsp[0].d;     ;}
    break;

  case 368:
#line 3379 "Gmsh.y"
    { yyval.d = yyvsp[-2].d != yyvsp[0].d;     ;}
    break;

  case 369:
#line 3380 "Gmsh.y"
    { yyval.d = yyvsp[-2].d && yyvsp[0].d;     ;}
    break;

  case 370:
#line 3381 "Gmsh.y"
    { yyval.d = yyvsp[-2].d || yyvsp[0].d;     ;}
    break;

  case 371:
#line 3382 "Gmsh.y"
    { yyval.d = yyvsp[-4].d? yyvsp[-2].d : yyvsp[0].d;  ;}
    break;

  case 372:
#line 3383 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      ;}
    break;

  case 373:
#line 3384 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      ;}
    break;

  case 374:
#line 3385 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    ;}
    break;

  case 375:
#line 3386 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     ;}
    break;

  case 376:
#line 3387 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      ;}
    break;

  case 377:
#line 3388 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     ;}
    break;

  case 378:
#line 3389 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      ;}
    break;

  case 379:
#line 3390 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     ;}
    break;

  case 380:
#line 3391 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      ;}
    break;

  case 381:
#line 3392 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     ;}
    break;

  case 382:
#line 3393 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d, yyvsp[-1].d);;}
    break;

  case 383:
#line 3394 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     ;}
    break;

  case 384:
#line 3395 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     ;}
    break;

  case 385:
#line 3396 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     ;}
    break;

  case 386:
#line 3397 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     ;}
    break;

  case 387:
#line 3398 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    ;}
    break;

  case 388:
#line 3399 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     ;}
    break;

  case 389:
#line 3400 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 390:
#line 3401 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 391:
#line 3402 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); ;}
    break;

  case 392:
#line 3403 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 393:
#line 3405 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      ;}
    break;

  case 394:
#line 3406 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      ;}
    break;

  case 395:
#line 3407 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    ;}
    break;

  case 396:
#line 3408 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     ;}
    break;

  case 397:
#line 3409 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      ;}
    break;

  case 398:
#line 3410 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     ;}
    break;

  case 399:
#line 3411 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      ;}
    break;

  case 400:
#line 3412 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     ;}
    break;

  case 401:
#line 3413 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      ;}
    break;

  case 402:
#line 3414 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     ;}
    break;

  case 403:
#line 3415 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d, yyvsp[-1].d);;}
    break;

  case 404:
#line 3416 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     ;}
    break;

  case 405:
#line 3417 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     ;}
    break;

  case 406:
#line 3418 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     ;}
    break;

  case 407:
#line 3419 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     ;}
    break;

  case 408:
#line 3420 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    ;}
    break;

  case 409:
#line 3421 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     ;}
    break;

  case 410:
#line 3422 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 411:
#line 3423 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d, yyvsp[-1].d); ;}
    break;

  case 412:
#line 3424 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); ;}
    break;

  case 413:
#line 3425 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; ;}
    break;

  case 414:
#line 3434 "Gmsh.y"
    { yyval.d = yyvsp[0].d; ;}
    break;

  case 415:
#line 3435 "Gmsh.y"
    { yyval.d = 3.141592653589793; ;}
    break;

  case 416:
#line 3436 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->rank(); ;}
    break;

  case 417:
#line 3437 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->size(); ;}
    break;

  case 418:
#line 3442 "Gmsh.y"
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
#line 3454 "Gmsh.y"
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
#line 3473 "Gmsh.y"
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
#line 3486 "Gmsh.y"
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
#line 3498 "Gmsh.y"
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
#line 3520 "Gmsh.y"
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
#line 3537 "Gmsh.y"
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
#line 3554 "Gmsh.y"
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
#line 3571 "Gmsh.y"
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
#line 3591 "Gmsh.y"
    {
      memcpy(yyval.v, yyvsp[0].v, 5*sizeof(double));
    ;}
    break;

  case 428:
#line 3595 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) yyval.v[i] = -yyvsp[0].v[i];
    ;}
    break;

  case 429:
#line 3599 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[0].v[i];
    ;}
    break;

  case 430:
#line 3603 "Gmsh.y"
    { 
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[-2].v[i] - yyvsp[0].v[i];
    ;}
    break;

  case 431:
#line 3607 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) yyval.v[i] = yyvsp[-2].v[i] + yyvsp[0].v[i];
    ;}
    break;

  case 432:
#line 3614 "Gmsh.y"
    { 
      yyval.v[0] = yyvsp[-9].d;  yyval.v[1] = yyvsp[-7].d;  yyval.v[2] = yyvsp[-5].d;  yyval.v[3] = yyvsp[-3].d; yyval.v[4] = yyvsp[-1].d;
    ;}
    break;

  case 433:
#line 3618 "Gmsh.y"
    { 
      yyval.v[0] = yyvsp[-7].d;  yyval.v[1] = yyvsp[-5].d;  yyval.v[2] = yyvsp[-3].d;  yyval.v[3] = yyvsp[-1].d; yyval.v[4] = 1.0;
    ;}
    break;

  case 434:
#line 3622 "Gmsh.y"
    {
      yyval.v[0] = yyvsp[-5].d;  yyval.v[1] = yyvsp[-3].d;  yyval.v[2] = yyvsp[-1].d;  yyval.v[3] = 0.0; yyval.v[4] = 1.0;
    ;}
    break;

  case 435:
#line 3626 "Gmsh.y"
    {
      yyval.v[0] = yyvsp[-5].d;  yyval.v[1] = yyvsp[-3].d;  yyval.v[2] = yyvsp[-1].d;  yyval.v[3] = 0.0; yyval.v[4] = 1.0;
    ;}
    break;

  case 436:
#line 3633 "Gmsh.y"
    {
    ;}
    break;

  case 437:
#line 3636 "Gmsh.y"
    {
    ;}
    break;

  case 438:
#line 3642 "Gmsh.y"
    {
    ;}
    break;

  case 439:
#line 3645 "Gmsh.y"
    {
    ;}
    break;

  case 440:
#line 3651 "Gmsh.y"
    {
    ;}
    break;

  case 441:
#line 3654 "Gmsh.y"
    {
       yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 442:
#line 3658 "Gmsh.y"
    {
       yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 443:
#line 3665 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(List_T*));
      List_Add(yyval.l, &(yyvsp[0].l));
    ;}
    break;

  case 444:
#line 3670 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].l));
    ;}
    break;

  case 445:
#line 3678 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 446:
#line 3683 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l;
    ;}
    break;

  case 447:
#line 3687 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 448:
#line 3691 "Gmsh.y"
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
#line 3703 "Gmsh.y"
    { 
      yyval.l = List_Create(2, 1, sizeof(double)); 
      for(double d = yyvsp[-2].d; (yyvsp[-2].d < yyvsp[0].d) ? (d <= yyvsp[0].d) : (d >= yyvsp[0].d); (yyvsp[-2].d < yyvsp[0].d) ? (d += 1.) : (d -= 1.)) 
	List_Add(yyval.l, &d);
    ;}
    break;

  case 450:
#line 3709 "Gmsh.y"
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
#line 3720 "Gmsh.y"
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
#line 3740 "Gmsh.y"
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
#line 3750 "Gmsh.y"
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
#line 3760 "Gmsh.y"
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
#line 3772 "Gmsh.y"
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
#line 3788 "Gmsh.y"
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
#line 3806 "Gmsh.y"
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
#line 3829 "Gmsh.y"
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
#line 3857 "Gmsh.y"
    {
      yyval.l = List_Create(2, 1, sizeof(double));
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 460:
#line 3862 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l;
    ;}
    break;

  case 461:
#line 3866 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].d));
    ;}
    break;

  case 462:
#line 3870 "Gmsh.y"
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
#line 3883 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-7].d, (int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d);
    ;}
    break;

  case 464:
#line 3887 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d, 255);
    ;}
    break;

  case 465:
#line 3899 "Gmsh.y"
    {
      int flag;
      yyval.u = Get_ColorForString(ColorString, -1, yyvsp[0].c, &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", yyvsp[0].c);
    ;}
    break;

  case 466:
#line 3905 "Gmsh.y"
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
#line 3926 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    ;}
    break;

  case 468:
#line 3930 "Gmsh.y"
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
#line 3944 "Gmsh.y"
    {
      yyval.l = List_Create(256, 10, sizeof(unsigned int));
      List_Add(yyval.l, &(yyvsp[0].u));
    ;}
    break;

  case 470:
#line 3949 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].u));
    ;}
    break;

  case 471:
#line 3956 "Gmsh.y"
    {
      yyval.c = yyvsp[0].c;
    ;}
    break;

  case 472:
#line 3960 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-3].c)+strlen(yyvsp[-1].c)+1)*sizeof(char));
      strcpy(yyval.c, yyvsp[-3].c);  
      strcat(yyval.c, yyvsp[-1].c);
      Free(yyvsp[-3].c);
      Free(yyvsp[-1].c);
    ;}
    break;

  case 473:
#line 3968 "Gmsh.y"
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
#line 3982 "Gmsh.y"
    {
      yyval.c = yyvsp[-1].c;
    ;}
    break;

  case 475:
#line 3986 "Gmsh.y"
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
#line 4005 "Gmsh.y"
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
#line 4021 "Gmsh.y"
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

/* Line 1000 of yacc.c.  */
#line 10308 "Gmsh.tab.cpp"

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
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
	  yychar = YYEMPTY;

	}
    }

  /* Else will try to reuse lookahead token after shifting the error
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
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


#line 4038 "Gmsh.y"


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

