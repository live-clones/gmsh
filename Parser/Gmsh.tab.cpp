/* A Bison parser, made from Gmsh.y, by GNU bison 1.75.  */

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
#define YYBISON	1

/* Pure parsers.  */
#define YYPURE	0

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
     tDraw = 292,
     tPoint = 293,
     tCircle = 294,
     tEllipse = 295,
     tLine = 296,
     tSurface = 297,
     tSpline = 298,
     tVolume = 299,
     tCharacteristic = 300,
     tLength = 301,
     tParametric = 302,
     tElliptic = 303,
     tPlane = 304,
     tRuled = 305,
     tTriangulation = 306,
     tTransfinite = 307,
     tComplex = 308,
     tPhysical = 309,
     tUsing = 310,
     tBump = 311,
     tProgression = 312,
     tPlugin = 313,
     tRotate = 314,
     tTranslate = 315,
     tSymmetry = 316,
     tDilate = 317,
     tExtrude = 318,
     tDuplicata = 319,
     tLoop = 320,
     tRecombine = 321,
     tDelete = 322,
     tCoherence = 323,
     tIntersect = 324,
     tAttractor = 325,
     tLayers = 326,
     tScalarPoint = 327,
     tVectorPoint = 328,
     tTensorPoint = 329,
     tScalarLine = 330,
     tVectorLine = 331,
     tTensorLine = 332,
     tScalarTriangle = 333,
     tVectorTriangle = 334,
     tTensorTriangle = 335,
     tScalarQuadrangle = 336,
     tVectorQuadrangle = 337,
     tTensorQuadrangle = 338,
     tScalarTetrahedron = 339,
     tVectorTetrahedron = 340,
     tTensorTetrahedron = 341,
     tScalarHexahedron = 342,
     tVectorHexahedron = 343,
     tTensorHexahedron = 344,
     tScalarPrism = 345,
     tVectorPrism = 346,
     tTensorPrism = 347,
     tScalarPyramid = 348,
     tVectorPyramid = 349,
     tTensorPyramid = 350,
     tText2D = 351,
     tText3D = 352,
     tBSpline = 353,
     tBezier = 354,
     tNurbs = 355,
     tOrder = 356,
     tWith = 357,
     tBounds = 358,
     tKnots = 359,
     tColor = 360,
     tColorTable = 361,
     tFor = 362,
     tIn = 363,
     tEndFor = 364,
     tIf = 365,
     tEndIf = 366,
     tExit = 367,
     tReturn = 368,
     tCall = 369,
     tFunction = 370,
     tMesh = 371,
     tTrimmed = 372,
     tB_SPLINE_SURFACE_WITH_KNOTS = 373,
     tB_SPLINE_CURVE_WITH_KNOTS = 374,
     tCARTESIAN_POINT = 375,
     tTRUE = 376,
     tFALSE = 377,
     tUNSPECIFIED = 378,
     tU = 379,
     tV = 380,
     tEDGE_CURVE = 381,
     tVERTEX_POINT = 382,
     tORIENTED_EDGE = 383,
     tPLANE = 384,
     tFACE_OUTER_BOUND = 385,
     tEDGE_LOOP = 386,
     tADVANCED_FACE = 387,
     tVECTOR = 388,
     tDIRECTION = 389,
     tAXIS2_PLACEMENT_3D = 390,
     tISO = 391,
     tENDISO = 392,
     tENDSEC = 393,
     tDATA = 394,
     tHEADER = 395,
     tFILE_DESCRIPTION = 396,
     tFILE_SCHEMA = 397,
     tFILE_NAME = 398,
     tMANIFOLD_SOLID_BREP = 399,
     tCLOSED_SHELL = 400,
     tADVANCED_BREP_SHAPE_REPRESENTATION = 401,
     tFACE_BOUND = 402,
     tCYLINDRICAL_SURFACE = 403,
     tCONICAL_SURFACE = 404,
     tCIRCLE = 405,
     tTRIMMED_CURVE = 406,
     tGEOMETRIC_SET = 407,
     tCOMPOSITE_CURVE_SEGMENT = 408,
     tCONTINUOUS = 409,
     tCOMPOSITE_CURVE = 410,
     tTOROIDAL_SURFACE = 411,
     tPRODUCT_DEFINITION = 412,
     tPRODUCT_DEFINITION_SHAPE = 413,
     tSHAPE_DEFINITION_REPRESENTATION = 414,
     tELLIPSE = 415,
     tSolid = 416,
     tEndSolid = 417,
     tVertex = 418,
     tFacet = 419,
     tNormal = 420,
     tOuter = 421,
     tLoopSTL = 422,
     tEndLoop = 423,
     tEndFacet = 424,
     tAFFECTDIVIDE = 425,
     tAFFECTTIMES = 426,
     tAFFECTMINUS = 427,
     tAFFECTPLUS = 428,
     tOR = 429,
     tAND = 430,
     tAPPROXEQUAL = 431,
     tNOTEQUAL = 432,
     tEQUAL = 433,
     tGREATEROREQUAL = 434,
     tLESSOREQUAL = 435,
     tCROSSPRODUCT = 436,
     UNARYPREC = 437,
     tMINUSMINUS = 438,
     tPLUSPLUS = 439
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
#define tDraw 292
#define tPoint 293
#define tCircle 294
#define tEllipse 295
#define tLine 296
#define tSurface 297
#define tSpline 298
#define tVolume 299
#define tCharacteristic 300
#define tLength 301
#define tParametric 302
#define tElliptic 303
#define tPlane 304
#define tRuled 305
#define tTriangulation 306
#define tTransfinite 307
#define tComplex 308
#define tPhysical 309
#define tUsing 310
#define tBump 311
#define tProgression 312
#define tPlugin 313
#define tRotate 314
#define tTranslate 315
#define tSymmetry 316
#define tDilate 317
#define tExtrude 318
#define tDuplicata 319
#define tLoop 320
#define tRecombine 321
#define tDelete 322
#define tCoherence 323
#define tIntersect 324
#define tAttractor 325
#define tLayers 326
#define tScalarPoint 327
#define tVectorPoint 328
#define tTensorPoint 329
#define tScalarLine 330
#define tVectorLine 331
#define tTensorLine 332
#define tScalarTriangle 333
#define tVectorTriangle 334
#define tTensorTriangle 335
#define tScalarQuadrangle 336
#define tVectorQuadrangle 337
#define tTensorQuadrangle 338
#define tScalarTetrahedron 339
#define tVectorTetrahedron 340
#define tTensorTetrahedron 341
#define tScalarHexahedron 342
#define tVectorHexahedron 343
#define tTensorHexahedron 344
#define tScalarPrism 345
#define tVectorPrism 346
#define tTensorPrism 347
#define tScalarPyramid 348
#define tVectorPyramid 349
#define tTensorPyramid 350
#define tText2D 351
#define tText3D 352
#define tBSpline 353
#define tBezier 354
#define tNurbs 355
#define tOrder 356
#define tWith 357
#define tBounds 358
#define tKnots 359
#define tColor 360
#define tColorTable 361
#define tFor 362
#define tIn 363
#define tEndFor 364
#define tIf 365
#define tEndIf 366
#define tExit 367
#define tReturn 368
#define tCall 369
#define tFunction 370
#define tMesh 371
#define tTrimmed 372
#define tB_SPLINE_SURFACE_WITH_KNOTS 373
#define tB_SPLINE_CURVE_WITH_KNOTS 374
#define tCARTESIAN_POINT 375
#define tTRUE 376
#define tFALSE 377
#define tUNSPECIFIED 378
#define tU 379
#define tV 380
#define tEDGE_CURVE 381
#define tVERTEX_POINT 382
#define tORIENTED_EDGE 383
#define tPLANE 384
#define tFACE_OUTER_BOUND 385
#define tEDGE_LOOP 386
#define tADVANCED_FACE 387
#define tVECTOR 388
#define tDIRECTION 389
#define tAXIS2_PLACEMENT_3D 390
#define tISO 391
#define tENDISO 392
#define tENDSEC 393
#define tDATA 394
#define tHEADER 395
#define tFILE_DESCRIPTION 396
#define tFILE_SCHEMA 397
#define tFILE_NAME 398
#define tMANIFOLD_SOLID_BREP 399
#define tCLOSED_SHELL 400
#define tADVANCED_BREP_SHAPE_REPRESENTATION 401
#define tFACE_BOUND 402
#define tCYLINDRICAL_SURFACE 403
#define tCONICAL_SURFACE 404
#define tCIRCLE 405
#define tTRIMMED_CURVE 406
#define tGEOMETRIC_SET 407
#define tCOMPOSITE_CURVE_SEGMENT 408
#define tCONTINUOUS 409
#define tCOMPOSITE_CURVE 410
#define tTOROIDAL_SURFACE 411
#define tPRODUCT_DEFINITION 412
#define tPRODUCT_DEFINITION_SHAPE 413
#define tSHAPE_DEFINITION_REPRESENTATION 414
#define tELLIPSE 415
#define tSolid 416
#define tEndSolid 417
#define tVertex 418
#define tFacet 419
#define tNormal 420
#define tOuter 421
#define tLoopSTL 422
#define tEndLoop 423
#define tEndFacet 424
#define tAFFECTDIVIDE 425
#define tAFFECTTIMES 426
#define tAFFECTMINUS 427
#define tAFFECTPLUS 428
#define tOR 429
#define tAND 430
#define tAPPROXEQUAL 431
#define tNOTEQUAL 432
#define tEQUAL 433
#define tGREATEROREQUAL 434
#define tLESSOREQUAL 435
#define tCROSSPRODUCT 436
#define UNARYPREC 437
#define tMINUSMINUS 438
#define tPLUSPLUS 439




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"
 

// $Id: Gmsh.tab.cpp,v 1.160 2003-09-05 14:22:34 remacle Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include <stdarg.h>
#include "PluginManager.h"
#include "ParUtil.h"
#include "Gmsh.h"
#include "Numeric.h"
#include "Context.h"
#include "Geo.h"
#include "CAD.h"
#include "DataBase.h"
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

Tree_T *Symbol_T = NULL;

extern Context_T CTX;
extern Mesh *THEM;

static FILE *yyinTab[MAX_OPEN_FILES];
static int yylinenoTab[MAX_OPEN_FILES];
static fpos_t yyposImbricatedLoopsTab[MAX_OPEN_FILES];
static int yylinenoImbricatedLoopsTab[MAX_OPEN_FILES];
static double LoopControlVariablesTab[MAX_OPEN_FILES][3];
static char *LoopControlVariablesNameTab[MAX_OPEN_FILES];
static char yynameTab[MAX_OPEN_FILES][256];
static char tmpstring[1024];
static Symbol TheSymbol, *pSymbol;
static Surface *STL_Surf;
static Shape TheShape;
static int i, j, k, flag, RecursionLevel = 0, ImbricatedLoop = 0;
static int Last_NumberOfPoints = 0;
static double d, *pd;
static ExtrudeParams extr;
static char *str;
static StringXString *pStrCat;
static StringXNumber *pNumCat;
static StringXColor *pColCat;
static double (*pNumOpt)(int num, int action, double value);
static char* (*pStrOpt)(int num, int action, char *value);
static unsigned int (*pColOpt)(int num, int action, unsigned int value);
static Post_View *View;

char *strsave (char *ptr);
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

#ifndef YYSTYPE
#line 85 "Gmsh.y"
typedef union {
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
} yystype;
/* Line 193 of /usr/share/bison/yacc.c.  */
#line 535 "Gmsh.tab.cpp"
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} yyltype;
# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */


/* Line 213 of /usr/share/bison/yacc.c.  */
#line 556 "Gmsh.tab.cpp"

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
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)

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
	    (To)[yyi] = (From)[yyi];	\
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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
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
#define YYFINAL  11
#define YYLAST   13250

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  203
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  134
/* YYNRULES -- Number of rules. */
#define YYNRULES  458
/* YYNRULES -- Number of states. */
#define YYNSTATES  2291

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   439

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   190,     2,     2,     2,   188,     2,     2,
     195,   196,   186,   184,   200,   185,   199,   187,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     180,     2,   181,   174,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   197,     2,   198,   194,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   201,     2,   202,     2,     2,     2,     2,
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   175,
     176,   177,   178,   179,   182,   183,   189,   191,   192,   193
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    17,    19,
      41,    43,    44,    47,    49,    51,    53,    56,    59,    62,
      65,    68,    76,    82,   100,   110,   134,   166,   182,   194,
     206,   222,   232,   246,   256,   268,   282,   292,   302,   314,
     324,   336,   346,   358,   372,   386,   398,   412,   430,   440,
     452,   464,   478,   490,   500,   501,   504,   506,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   526,   528,   530,
     536,   544,   551,   560,   561,   564,   567,   570,   573,   576,
     579,   582,   585,   588,   591,   594,   597,   600,   603,   606,
     609,   612,   615,   618,   621,   624,   627,   630,   633,   636,
     639,   641,   645,   646,   660,   662,   666,   667,   681,   683,
     687,   688,   702,   704,   708,   709,   729,   731,   735,   736,
     756,   758,   762,   763,   783,   785,   789,   790,   816,   818,
     822,   823,   849,   851,   855,   856,   882,   884,   888,   889,
     921,   923,   927,   928,   960,   962,   966,   967,   999,  1001,
    1005,  1006,  1038,  1040,  1044,  1045,  1077,  1079,  1083,  1084,
    1116,  1118,  1122,  1123,  1179,  1181,  1185,  1186,  1242,  1244,
    1248,  1249,  1305,  1307,  1311,  1312,  1356,  1358,  1362,  1363,
    1407,  1409,  1413,  1414,  1458,  1460,  1464,  1465,  1503,  1505,
    1509,  1510,  1548,  1550,  1554,  1555,  1593,  1595,  1599,  1600,
    1614,  1616,  1620,  1621,  1637,  1639,  1641,  1643,  1645,  1647,
    1649,  1651,  1656,  1664,  1674,  1681,  1685,  1692,  1699,  1709,
    1716,  1726,  1732,  1741,  1750,  1762,  1769,  1779,  1789,  1799,
    1807,  1816,  1829,  1836,  1844,  1852,  1865,  1873,  1881,  1891,
    1909,  1918,  1927,  1935,  1943,  1955,  1964,  1977,  1986,  2001,
    2024,  2045,  2054,  2063,  2072,  2080,  2089,  2095,  2107,  2113,
    2123,  2125,  2127,  2129,  2130,  2133,  2140,  2147,  2154,  2159,
    2166,  2171,  2178,  2182,  2188,  2192,  2196,  2204,  2207,  2210,
    2217,  2226,  2235,  2246,  2248,  2251,  2253,  2257,  2262,  2264,
    2273,  2286,  2301,  2302,  2315,  2316,  2333,  2334,  2353,  2362,
    2375,  2390,  2391,  2404,  2405,  2422,  2423,  2442,  2451,  2464,
    2479,  2480,  2493,  2494,  2511,  2512,  2531,  2533,  2536,  2546,
    2554,  2557,  2564,  2574,  2584,  2593,  2602,  2611,  2618,  2623,
    2626,  2629,  2631,  2633,  2635,  2637,  2639,  2641,  2645,  2648,
    2651,  2654,  2658,  2662,  2666,  2670,  2674,  2678,  2682,  2686,
    2690,  2694,  2698,  2702,  2706,  2710,  2716,  2721,  2726,  2731,
    2736,  2741,  2746,  2751,  2756,  2761,  2766,  2773,  2778,  2783,
    2788,  2793,  2798,  2803,  2810,  2817,  2824,  2829,  2834,  2839,
    2844,  2849,  2854,  2859,  2864,  2869,  2874,  2879,  2886,  2891,
    2896,  2901,  2906,  2911,  2916,  2923,  2930,  2937,  2942,  2944,
    2946,  2948,  2950,  2952,  2957,  2960,  2966,  2970,  2977,  2982,
    2990,  2992,  2995,  2998,  3002,  3006,  3018,  3028,  3036,  3044,
    3045,  3049,  3051,  3055,  3056,  3060,  3064,  3066,  3070,  3072,
    3074,  3078,  3083,  3085,  3089,  3095,  3100,  3104,  3109,  3116,
    3124,  3126,  3128,  3132,  3136,  3146,  3154,  3156,  3162,  3166,
    3173,  3175,  3179,  3181,  3188,  3193,  3198,  3205,  3212
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     204,     0,    -1,   207,    -1,   206,    -1,   212,    -1,     1,
       6,    -1,     3,    -1,   185,     3,    -1,   161,    -1,   164,
     165,   205,   205,   205,   166,   167,   163,   205,   205,   205,
     163,   205,   205,   205,   163,   205,   205,   205,   168,   169,
      -1,   162,    -1,    -1,   207,   208,    -1,   209,    -1,   211,
      -1,   210,    -1,   136,     6,    -1,   137,     6,    -1,   139,
       6,    -1,   138,     6,    -1,   140,     6,    -1,   141,   195,
     326,   200,     5,   196,     6,    -1,   142,   195,   326,   196,
       6,    -1,   143,   195,     5,   200,     5,   200,   326,   200,
     326,   200,     5,   200,     5,   200,     5,   196,     6,    -1,
       3,     7,   120,   195,     5,   200,   324,   196,     6,    -1,
       3,     7,   119,   195,     5,   200,   322,   200,   330,   200,
     321,   200,   321,   200,   321,   200,   330,   200,   330,   200,
     321,   196,     6,    -1,     3,     7,   118,   195,     5,   200,
     322,   200,   322,   200,   328,   200,   321,   200,   321,   200,
     321,   200,   321,   200,   330,   200,   330,   200,   330,   200,
     330,   200,   321,   196,     6,    -1,     3,     7,   126,   195,
       5,   200,     3,   200,     3,   200,     3,   200,   321,   196,
       6,    -1,     3,     7,   130,   195,     5,   200,     3,   200,
     321,   196,     6,    -1,     3,     7,   147,   195,     5,   200,
       3,   200,   321,   196,     6,    -1,     3,     7,   128,   195,
       5,   200,   186,   200,   186,   200,   322,   200,   321,   196,
       6,    -1,     3,     7,   131,   195,     5,   200,   330,   196,
       6,    -1,     3,     7,   132,   195,     5,   200,   330,   200,
       3,   200,   321,   196,     6,    -1,     3,     7,   127,   195,
       5,   200,     3,   196,     6,    -1,     3,     7,   133,   195,
       5,   200,     3,   200,   322,   196,     6,    -1,     3,     7,
     135,   195,     5,   200,     3,   200,     3,   200,     3,   196,
       6,    -1,     3,     7,   134,   195,     5,   200,   324,   196,
       6,    -1,     3,     7,   129,   195,     5,   200,     3,   196,
       6,    -1,     3,     7,    41,   195,     5,   200,     3,   200,
       3,   196,     6,    -1,     3,     7,   145,   195,     5,   200,
     330,   196,     6,    -1,     3,     7,   146,   195,     5,   200,
     330,   200,     3,   196,     6,    -1,     3,     7,   144,   195,
       5,   200,     3,   196,     6,    -1,     3,     7,   148,   195,
       5,   200,     3,   200,   322,   196,     6,    -1,     3,     7,
     149,   195,     5,   200,     3,   200,   322,   200,   322,   196,
       6,    -1,     3,     7,   156,   195,     5,   200,     3,   200,
     322,   200,   322,   196,     6,    -1,     3,     7,   150,   195,
       5,   200,     3,   200,   322,   196,     6,    -1,     3,     7,
     160,   195,     5,   200,     3,   200,   322,   200,   322,   196,
       6,    -1,     3,     7,   151,   195,     5,   200,     3,   200,
     330,   200,   330,   200,   321,   200,   321,   196,     6,    -1,
       3,     7,   152,   195,     5,   200,   330,   196,     6,    -1,
       3,     7,   153,   195,   154,   200,   321,   200,     3,   196,
       6,    -1,     3,     7,   155,   195,     5,   200,   330,   200,
     321,   196,     6,    -1,     3,     7,   157,   195,     5,   200,
       5,   200,     3,   200,     3,   196,     6,    -1,     3,     7,
     158,   195,     5,   200,     5,   200,     3,   196,     6,    -1,
       3,     7,   159,   195,     3,   200,     3,   196,     6,    -1,
      -1,   212,   213,    -1,   215,    -1,   214,    -1,   297,    -1,
     298,    -1,   299,    -1,   302,    -1,   303,    -1,   304,    -1,
     307,    -1,   319,    -1,   320,    -1,   306,    -1,   305,    -1,
      33,   195,     5,   196,     6,    -1,    33,   195,     5,   200,
     332,   196,     6,    -1,     4,     5,   201,   216,   202,     6,
      -1,     4,     5,     4,   324,   201,   216,   202,     6,    -1,
      -1,   216,   218,    -1,   216,   221,    -1,   216,   224,    -1,
     216,   227,    -1,   216,   230,    -1,   216,   233,    -1,   216,
     236,    -1,   216,   239,    -1,   216,   242,    -1,   216,   245,
      -1,   216,   248,    -1,   216,   251,    -1,   216,   254,    -1,
     216,   257,    -1,   216,   260,    -1,   216,   263,    -1,   216,
     266,    -1,   216,   269,    -1,   216,   272,    -1,   216,   275,
      -1,   216,   278,    -1,   216,   281,    -1,   216,   284,    -1,
     216,   287,    -1,   216,   290,    -1,   216,   293,    -1,   322,
      -1,   217,   200,   322,    -1,    -1,    72,   195,   322,   200,
     322,   200,   322,   196,   219,   201,   217,   202,     6,    -1,
     322,    -1,   220,   200,   322,    -1,    -1,    73,   195,   322,
     200,   322,   200,   322,   196,   222,   201,   220,   202,     6,
      -1,   322,    -1,   223,   200,   322,    -1,    -1,    74,   195,
     322,   200,   322,   200,   322,   196,   225,   201,   223,   202,
       6,    -1,   322,    -1,   226,   200,   322,    -1,    -1,    75,
     195,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   196,   228,   201,   226,   202,     6,    -1,   322,
      -1,   229,   200,   322,    -1,    -1,    76,   195,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   196,
     231,   201,   229,   202,     6,    -1,   322,    -1,   232,   200,
     322,    -1,    -1,    77,   195,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   196,   234,   201,   232,
     202,     6,    -1,   322,    -1,   235,   200,   322,    -1,    -1,
      78,   195,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   196,
     237,   201,   235,   202,     6,    -1,   322,    -1,   238,   200,
     322,    -1,    -1,    79,   195,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   196,   240,   201,   238,   202,     6,    -1,   322,
      -1,   241,   200,   322,    -1,    -1,    80,   195,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   196,   243,   201,   241,   202,
       6,    -1,   322,    -1,   244,   200,   322,    -1,    -1,    81,
     195,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   196,   246,   201,   244,   202,     6,
      -1,   322,    -1,   247,   200,   322,    -1,    -1,    82,   195,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   196,   249,   201,   247,   202,     6,    -1,
     322,    -1,   250,   200,   322,    -1,    -1,    83,   195,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   196,   252,   201,   250,   202,     6,    -1,   322,
      -1,   253,   200,   322,    -1,    -1,    84,   195,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   196,   255,   201,   253,   202,     6,    -1,   322,    -1,
     256,   200,   322,    -1,    -1,    85,   195,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     196,   258,   201,   256,   202,     6,    -1,   322,    -1,   259,
     200,   322,    -1,    -1,    86,   195,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   196,
     261,   201,   259,   202,     6,    -1,   322,    -1,   262,   200,
     322,    -1,    -1,    87,   195,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   196,   264,   201,   262,   202,     6,    -1,   322,
      -1,   265,   200,   322,    -1,    -1,    88,   195,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   196,   267,   201,   265,   202,
       6,    -1,   322,    -1,   268,   200,   322,    -1,    -1,    89,
     195,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   196,   270,
     201,   268,   202,     6,    -1,   322,    -1,   271,   200,   322,
      -1,    -1,    90,   195,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   196,
     273,   201,   271,   202,     6,    -1,   322,    -1,   274,   200,
     322,    -1,    -1,    91,   195,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     196,   276,   201,   274,   202,     6,    -1,   322,    -1,   277,
     200,   322,    -1,    -1,    92,   195,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   196,   279,   201,   277,   202,     6,    -1,   322,    -1,
     280,   200,   322,    -1,    -1,    93,   195,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   196,   282,   201,   280,
     202,     6,    -1,   322,    -1,   283,   200,   322,    -1,    -1,
      94,   195,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   200,   322,   200,   322,   200,   322,   200,   322,   200,
     322,   196,   285,   201,   283,   202,     6,    -1,   322,    -1,
     286,   200,   322,    -1,    -1,    95,   195,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   200,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   196,   288,   201,   286,
     202,     6,    -1,   336,    -1,   289,   200,   336,    -1,    -1,
      96,   195,   322,   200,   322,   200,   322,   196,   291,   201,
     289,   202,     6,    -1,   336,    -1,   292,   200,   336,    -1,
      -1,    97,   195,   322,   200,   322,   200,   322,   200,   322,
     196,   294,   201,   292,   202,     6,    -1,     7,    -1,   173,
      -1,   172,    -1,   171,    -1,   170,    -1,   193,    -1,   192,
      -1,     4,   295,   322,     6,    -1,     4,   197,   322,   198,
     295,   322,     6,    -1,     4,   197,   201,   332,   202,   198,
     295,   330,     6,    -1,     4,   197,   198,     7,   330,     6,
      -1,     4,   296,     6,    -1,     4,   197,   322,   198,   296,
       6,    -1,     4,   199,     4,     7,   336,     6,    -1,     4,
     197,   322,   198,   199,     4,     7,   336,     6,    -1,     4,
     199,     4,   295,   322,     6,    -1,     4,   197,   322,   198,
     199,     4,   295,   322,     6,    -1,     4,   199,     4,   296,
       6,    -1,     4,   197,   322,   198,   199,     4,   296,     6,
      -1,     4,   199,   105,   199,     4,     7,   333,     6,    -1,
       4,   197,   322,   198,   199,   105,   199,     4,     7,   333,
       6,    -1,     4,   199,   106,     7,   334,     6,    -1,     4,
     197,   322,   198,   199,   106,     7,   334,     6,    -1,    58,
     195,     4,   196,   199,     4,     7,   322,     6,    -1,    58,
     195,     4,   196,   199,     4,     7,   336,     6,    -1,    38,
     195,   322,   196,     7,   324,     6,    -1,    54,    38,   195,
     322,   196,     7,   330,     6,    -1,    70,    38,   330,     7,
     201,   322,   200,   322,   200,   322,   202,     6,    -1,    45,
      46,   330,     7,   322,     6,    -1,    41,   195,   322,   196,
       7,   330,     6,    -1,    43,   195,   322,   196,     7,   330,
       6,    -1,    70,    41,   330,     7,   201,   322,   200,   322,
     200,   322,   202,     6,    -1,    39,   195,   322,   196,     7,
     330,     6,    -1,    40,   195,   322,   196,     7,   330,     6,
      -1,    39,   195,   322,   196,     7,   330,    49,   324,     6,
      -1,    47,   195,   322,   196,     7,   201,   322,   200,   322,
     200,     5,   200,     5,   200,     5,   202,     6,    -1,    54,
      41,   195,   322,   196,     7,   330,     6,    -1,    41,    65,
     195,   322,   196,     7,   330,     6,    -1,    98,   195,   322,
     196,     7,   330,     6,    -1,    99,   195,   322,   196,     7,
     330,     6,    -1,   100,   195,   322,   196,     7,   330,   104,
     330,   101,   322,     6,    -1,    49,    42,   195,   322,   196,
       7,   330,     6,    -1,   117,    42,   195,   322,   196,     7,
     201,   322,   200,   330,   202,     6,    -1,    50,    42,   195,
     322,   196,     7,   330,     6,    -1,    51,    42,   195,   322,
     196,     7,   195,   322,   200,   322,   196,   330,   330,     6,
      -1,   100,    42,   102,   103,   195,   322,   196,     7,   328,
     104,   201,   330,   200,   330,   202,   101,   201,   322,   200,
     322,   202,     6,    -1,   100,    42,   195,   322,   196,     7,
     328,   104,   201,   330,   200,   330,   202,   101,   201,   322,
     200,   322,   202,     6,    -1,    54,    42,   195,   322,   196,
       7,   330,     6,    -1,    42,    65,   195,   322,   196,     7,
     330,     6,    -1,    53,    44,   195,   322,   196,     7,   330,
       6,    -1,    44,   195,   322,   196,     7,   330,     6,    -1,
      54,    44,   195,   322,   196,     7,   330,     6,    -1,    60,
     324,   201,   300,   202,    -1,    59,   201,   324,   200,   324,
     200,   322,   202,   201,   300,   202,    -1,    61,   324,   201,
     300,   202,    -1,    62,   201,   324,   200,   322,   202,   201,
     300,   202,    -1,   302,    -1,   301,    -1,   299,    -1,    -1,
     301,   298,    -1,   301,    38,   201,   332,   202,     6,    -1,
     301,    41,   201,   332,   202,     6,    -1,   301,    42,   201,
     332,   202,     6,    -1,    64,   201,   301,   202,    -1,    64,
       4,   197,   322,   198,     6,    -1,    67,   201,   301,   202,
      -1,    67,     4,   197,   322,   198,     6,    -1,    67,   116,
       6,    -1,   105,   333,   201,   301,   202,    -1,     4,   336,
       6,    -1,     4,   322,     6,    -1,    58,   195,     4,   196,
     199,     4,     6,    -1,   112,     6,    -1,    37,     6,    -1,
     107,   195,   322,     8,   322,   196,    -1,   107,   195,   322,
       8,   322,     8,   322,   196,    -1,   107,     4,   108,   201,
     322,     8,   322,   202,    -1,   107,     4,   108,   201,   322,
       8,   322,     8,   322,   202,    -1,   109,    -1,   115,     4,
      -1,   113,    -1,   114,     4,     6,    -1,   110,   195,   322,
     196,    -1,   111,    -1,    63,    38,   201,   322,   200,   324,
     202,     6,    -1,    63,    38,   201,   322,   200,   324,   200,
     324,   200,   322,   202,     6,    -1,    63,    38,   201,   322,
     200,   324,   200,   324,   200,   324,   200,   322,   202,     6,
      -1,    -1,    63,    38,   201,   322,   200,   324,   202,   308,
     201,   317,   202,     6,    -1,    -1,    63,    38,   201,   322,
     200,   324,   200,   324,   200,   322,   202,   309,   201,   317,
     202,     6,    -1,    -1,    63,    38,   201,   322,   200,   324,
     200,   324,   200,   324,   200,   322,   202,   310,   201,   317,
     202,     6,    -1,    63,    41,   201,   322,   200,   324,   202,
       6,    -1,    63,    41,   201,   322,   200,   324,   200,   324,
     200,   322,   202,     6,    -1,    63,    41,   201,   322,   200,
     324,   200,   324,   200,   324,   200,   322,   202,     6,    -1,
      -1,    63,    41,   201,   322,   200,   324,   202,   311,   201,
     317,   202,     6,    -1,    -1,    63,    41,   201,   322,   200,
     324,   200,   324,   200,   322,   202,   312,   201,   317,   202,
       6,    -1,    -1,    63,    41,   201,   322,   200,   324,   200,
     324,   200,   324,   200,   322,   202,   313,   201,   317,   202,
       6,    -1,    63,    42,   201,   322,   200,   324,   202,     6,
      -1,    63,    42,   201,   322,   200,   324,   200,   324,   200,
     322,   202,     6,    -1,    63,    42,   201,   322,   200,   324,
     200,   324,   200,   324,   200,   322,   202,     6,    -1,    -1,
      63,    42,   201,   322,   200,   324,   202,   314,   201,   317,
     202,     6,    -1,    -1,    63,    42,   201,   322,   200,   324,
     200,   324,   200,   322,   202,   315,   201,   317,   202,     6,
      -1,    -1,    63,    42,   201,   322,   200,   324,   200,   324,
     200,   324,   200,   322,   202,   316,   201,   317,   202,     6,
      -1,   318,    -1,   317,   318,    -1,    71,   201,   330,   200,
     330,   200,   330,   202,     6,    -1,    71,   201,   330,   200,
     330,   202,     6,    -1,    66,     6,    -1,    52,    41,   330,
       7,   322,     6,    -1,    52,    41,   330,     7,   322,    55,
      57,   322,     6,    -1,    52,    41,   330,     7,   322,    55,
      56,   322,     6,    -1,    52,    42,   201,   322,   202,     7,
     330,     6,    -1,    48,    42,   201,   322,   202,     7,   330,
       6,    -1,    52,    44,   201,   322,   202,     7,   330,     6,
      -1,    66,    42,   330,     7,   322,     6,    -1,    66,    42,
     330,     6,    -1,    68,     6,    -1,    69,     6,    -1,   121,
      -1,   122,    -1,   123,    -1,   124,    -1,   125,    -1,   323,
      -1,   195,   322,   196,    -1,   185,   322,    -1,   184,   322,
      -1,   190,   322,    -1,   322,   185,   322,    -1,   322,   184,
     322,    -1,   322,   186,   322,    -1,   322,   187,   322,    -1,
     322,   188,   322,    -1,   322,   194,   322,    -1,   322,   180,
     322,    -1,   322,   181,   322,    -1,   322,   183,   322,    -1,
     322,   182,   322,    -1,   322,   179,   322,    -1,   322,   178,
     322,    -1,   322,   176,   322,    -1,   322,   175,   322,    -1,
     322,   174,   322,     8,   322,    -1,    12,   195,   322,   196,
      -1,    13,   195,   322,   196,    -1,    14,   195,   322,   196,
      -1,    15,   195,   322,   196,    -1,    16,   195,   322,   196,
      -1,    17,   195,   322,   196,    -1,    18,   195,   322,   196,
      -1,    19,   195,   322,   196,    -1,    20,   195,   322,   196,
      -1,    22,   195,   322,   196,    -1,    23,   195,   322,   200,
     322,   196,    -1,    24,   195,   322,   196,    -1,    25,   195,
     322,   196,    -1,    26,   195,   322,   196,    -1,    27,   195,
     322,   196,    -1,    28,   195,   322,   196,    -1,    29,   195,
     322,   196,    -1,    30,   195,   322,   200,   322,   196,    -1,
      31,   195,   322,   200,   322,   196,    -1,    32,   195,   322,
     200,   322,   196,    -1,    21,   195,   322,   196,    -1,    12,
     197,   322,   198,    -1,    13,   197,   322,   198,    -1,    14,
     197,   322,   198,    -1,    15,   197,   322,   198,    -1,    16,
     197,   322,   198,    -1,    17,   197,   322,   198,    -1,    18,
     197,   322,   198,    -1,    19,   197,   322,   198,    -1,    20,
     197,   322,   198,    -1,    22,   197,   322,   198,    -1,    23,
     197,   322,   200,   322,   198,    -1,    24,   197,   322,   198,
      -1,    25,   197,   322,   198,    -1,    26,   197,   322,   198,
      -1,    27,   197,   322,   198,    -1,    28,   197,   322,   198,
      -1,    29,   197,   322,   198,    -1,    30,   197,   322,   200,
     322,   198,    -1,    31,   197,   322,   200,   322,   198,    -1,
      32,   197,   322,   200,   322,   198,    -1,    21,   197,   322,
     198,    -1,     3,    -1,     9,    -1,    10,    -1,    11,    -1,
       4,    -1,     4,   197,   322,   198,    -1,     4,   296,    -1,
       4,   197,   322,   198,   296,    -1,     4,   199,     4,    -1,
       4,   197,   322,   198,   199,     4,    -1,     4,   199,     4,
     296,    -1,     4,   197,   322,   198,   199,     4,   296,    -1,
     325,    -1,   185,   324,    -1,   184,   324,    -1,   324,   185,
     324,    -1,   324,   184,   324,    -1,   201,   322,   200,   322,
     200,   322,   200,   322,   200,   322,   202,    -1,   201,   322,
     200,   322,   200,   322,   200,   322,   202,    -1,   201,   322,
     200,   322,   200,   322,   202,    -1,   195,   322,   200,   322,
     200,   322,   196,    -1,    -1,   195,   327,   196,    -1,     5,
      -1,   327,   200,     5,    -1,    -1,   201,   329,   202,    -1,
     195,   329,   196,    -1,   330,    -1,   329,   200,   330,    -1,
     322,    -1,   331,    -1,   201,   332,   202,    -1,   185,   201,
     332,   202,    -1,   300,    -1,   322,     8,   322,    -1,   322,
       8,   322,     8,   322,    -1,    38,   195,   322,   196,    -1,
       4,   197,   198,    -1,   185,     4,   197,   198,    -1,     4,
     197,   201,   332,   202,   198,    -1,   185,     4,   197,   201,
     332,   202,   198,    -1,   322,    -1,   331,    -1,   332,   200,
     322,    -1,   332,   200,   331,    -1,   201,   322,   200,   322,
     200,   322,   200,   322,   202,    -1,   201,   322,   200,   322,
     200,   322,   202,    -1,     4,    -1,     4,   199,   105,   199,
       4,    -1,   201,   335,   202,    -1,     4,   197,   322,   198,
     199,   106,    -1,   333,    -1,   335,   200,   333,    -1,     5,
      -1,    35,   195,   336,   200,   336,   196,    -1,    36,   195,
     336,   196,    -1,    34,   195,   336,   196,    -1,    34,   195,
     336,   200,   332,   196,    -1,    34,   195,     4,   199,     4,
     196,    -1,    34,   195,     4,   197,   322,   198,   199,     4,
     196,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   170,   170,   172,   173,   174,   179,   181,   184,   192,
     206,   216,   218,   221,   223,   224,   227,   233,   238,   239,
     240,   243,   247,   250,   256,   261,   267,   275,   280,   284,
     290,   295,   299,   304,   308,   311,   316,   320,   324,   328,
     333,   337,   340,   344,   348,   352,   356,   360,   364,   367,
     371,   374,   378,   381,   388,   392,   398,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   414,
     419,   434,   439,   445,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     478,   481,   487,   485,   497,   500,   506,   504,   516,   519,
     525,   523,   535,   538,   545,   542,   556,   559,   566,   563,
     577,   580,   587,   584,   598,   601,   609,   605,   623,   626,
     634,   630,   648,   651,   659,   655,   673,   676,   685,   680,
     699,   702,   711,   706,   725,   728,   737,   732,   751,   754,
     763,   758,   777,   780,   789,   784,   803,   806,   815,   810,
     829,   832,   845,   836,   865,   868,   881,   872,   901,   904,
     917,   908,   937,   940,   951,   944,   968,   971,   982,   975,
     999,  1002,  1013,  1006,  1030,  1033,  1043,  1037,  1060,  1063,
    1073,  1067,  1090,  1093,  1103,  1097,  1120,  1126,  1135,  1133,
    1147,  1153,  1162,  1160,  1177,  1179,  1180,  1181,  1182,  1185,
    1187,  1190,  1221,  1255,  1302,  1317,  1326,  1341,  1353,  1367,
    1390,  1414,  1426,  1440,  1452,  1466,  1486,  1508,  1520,  1536,
    1547,  1553,  1572,  1586,  1592,  1598,  1617,  1623,  1629,  1645,
    1652,  1658,  1664,  1675,  1686,  1711,  1717,  1736,  1758,  1764,
    1772,  1778,  1784,  1793,  1799,  1805,  1815,  1821,  1826,  1831,
    1838,  1840,  1841,  1844,  1849,  1854,  1869,  1884,  1903,  1914,
    1923,  1931,  1935,  1943,  1955,  2037,  2057,  2062,  2066,  2086,
    2098,  2108,  2129,  2150,  2171,  2177,  2182,  2187,  2191,  2199,
    2210,  2217,  2225,  2224,  2237,  2236,  2249,  2248,  2263,  2268,
    2273,  2279,  2278,  2289,  2288,  2299,  2298,  2311,  2316,  2321,
    2327,  2326,  2338,  2337,  2350,  2349,  2363,  2367,  2372,  2399,
    2423,  2431,  2450,  2468,  2486,  2508,  2529,  2550,  2564,  2583,
    2588,  2597,  2599,  2600,  2601,  2602,  2605,  2607,  2608,  2609,
    2610,  2611,  2612,  2613,  2614,  2621,  2622,  2623,  2624,  2625,
    2626,  2627,  2628,  2629,  2630,  2631,  2632,  2633,  2634,  2635,
    2636,  2637,  2638,  2639,  2640,  2641,  2642,  2643,  2644,  2645,
    2646,  2647,  2648,  2649,  2650,  2651,  2652,  2654,  2655,  2656,
    2657,  2658,  2659,  2660,  2661,  2662,  2663,  2664,  2665,  2666,
    2667,  2668,  2669,  2670,  2671,  2672,  2673,  2674,  2679,  2684,
    2685,  2686,  2690,  2701,  2718,  2729,  2748,  2764,  2780,  2796,
    2813,  2818,  2822,  2826,  2830,  2836,  2841,  2845,  2849,  2855,
    2859,  2864,  2868,  2873,  2877,  2881,  2887,  2893,  2900,  2906,
    2910,  2914,  2922,  2934,  2941,  2952,  2974,  2988,  3004,  3024,
    3048,  3054,  3058,  3062,  3073,  3078,  3089,  3094,  3112,  3117,
    3130,  3136,  3142,  3147,  3155,  3168,  3172,  3190,  3204
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
  "tStrPrefix", "tDraw", "tPoint", "tCircle", "tEllipse", "tLine", 
  "tSurface", "tSpline", "tVolume", "tCharacteristic", "tLength", 
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
  "tVectorPyramid", "tTensorPyramid", "tText2D", "tText3D", "tBSpline", 
  "tBezier", "tNurbs", "tOrder", "tWith", "tBounds", "tKnots", "tColor", 
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tEndIf", "tExit", 
  "tReturn", "tCall", "tFunction", "tMesh", "tTrimmed", 
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
  "'['", "']'", "'.'", "','", "'{'", "'}'", "$accept", "All", 
  "SignedDouble", "STLFormatItem", "StepFormatItems", "StepFormatItem", 
  "StepSpecial", "StepHeaderItem", "StepDataItem", "GeomFormatList", 
  "GeomFormat", "Printf", "View", "Views", "ScalarPointValues", 
  "ScalarPoint", "@1", "VectorPointValues", "VectorPoint", "@2", 
  "TensorPointValues", "TensorPoint", "@3", "ScalarLineValues", 
  "ScalarLine", "@4", "VectorLineValues", "VectorLine", "@5", 
  "TensorLineValues", "TensorLine", "@6", "ScalarTriangleValues", 
  "ScalarTriangle", "@7", "VectorTriangleValues", "VectorTriangle", "@8", 
  "TensorTriangleValues", "TensorTriangle", "@9", 
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
  "NumericAffectation", "NumericIncrement", "Affectation", "Shape", 
  "Transform", "MultipleShape", "ListOfShapes", "Duplicata", "Delete", 
  "Colorify", "Command", "Loop", "Extrude", "@27", "@28", "@29", "@30", 
  "@31", "@32", "@33", "@34", "@35", "ExtrudeParameters", 
  "ExtrudeParameter", "Transfini", "Coherence", "BoolExpr", "FExpr", 
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
     425,   426,   427,   428,    63,   429,   430,   431,   432,   433,
      60,    62,   434,   435,    43,    45,    42,    47,    37,   436,
      33,   437,   438,   439,    94,    40,    41,    91,    93,    46,
      44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   203,   204,   204,   204,   204,   205,   205,   206,   206,
     206,   207,   207,   208,   208,   208,   209,   209,   209,   209,
     209,   210,   210,   210,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   212,   212,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   214,
     214,   215,   215,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     217,   217,   219,   218,   220,   220,   222,   221,   223,   223,
     225,   224,   226,   226,   228,   227,   229,   229,   231,   230,
     232,   232,   234,   233,   235,   235,   237,   236,   238,   238,
     240,   239,   241,   241,   243,   242,   244,   244,   246,   245,
     247,   247,   249,   248,   250,   250,   252,   251,   253,   253,
     255,   254,   256,   256,   258,   257,   259,   259,   261,   260,
     262,   262,   264,   263,   265,   265,   267,   266,   268,   268,
     270,   269,   271,   271,   273,   272,   274,   274,   276,   275,
     277,   277,   279,   278,   280,   280,   282,   281,   283,   283,
     285,   284,   286,   286,   288,   287,   289,   289,   291,   290,
     292,   292,   294,   293,   295,   295,   295,   295,   295,   296,
     296,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   299,   299,   299,   299,
     300,   300,   300,   301,   301,   301,   301,   301,   302,   302,
     303,   303,   303,   304,   305,   305,   305,   305,   305,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   307,
     307,   307,   308,   307,   309,   307,   310,   307,   307,   307,
     307,   311,   307,   312,   307,   313,   307,   307,   307,   307,
     314,   307,   315,   307,   316,   307,   317,   317,   318,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   320,
     320,   321,   321,   321,   321,   321,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     324,   324,   324,   324,   324,   325,   325,   325,   325,   326,
     326,   327,   327,   328,   328,   328,   329,   329,   330,   330,
     330,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     332,   332,   332,   332,   333,   333,   333,   333,   334,   334,
     335,   335,   336,   336,   336,   336,   336,   336,   336
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     2,     1,    21,
       1,     0,     2,     1,     1,     1,     2,     2,     2,     2,
       2,     7,     5,    17,     9,    23,    31,    15,    11,    11,
      15,     9,    13,     9,    11,    13,     9,     9,    11,     9,
      11,     9,    11,    13,    13,    11,    13,    17,     9,    11,
      11,    13,    11,     9,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       7,     6,     8,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     3,     0,    13,     1,     3,     0,    13,     1,     3,
       0,    13,     1,     3,     0,    19,     1,     3,     0,    19,
       1,     3,     0,    19,     1,     3,     0,    25,     1,     3,
       0,    25,     1,     3,     0,    25,     1,     3,     0,    31,
       1,     3,     0,    31,     1,     3,     0,    31,     1,     3,
       0,    31,     1,     3,     0,    31,     1,     3,     0,    31,
       1,     3,     0,    55,     1,     3,     0,    55,     1,     3,
       0,    55,     1,     3,     0,    43,     1,     3,     0,    43,
       1,     3,     0,    43,     1,     3,     0,    37,     1,     3,
       0,    37,     1,     3,     0,    37,     1,     3,     0,    13,
       1,     3,     0,    15,     1,     1,     1,     1,     1,     1,
       1,     4,     7,     9,     6,     3,     6,     6,     9,     6,
       9,     5,     8,     8,    11,     6,     9,     9,     9,     7,
       8,    12,     6,     7,     7,    12,     7,     7,     9,    17,
       8,     8,     7,     7,    11,     8,    12,     8,    14,    22,
      20,     8,     8,     8,     7,     8,     5,    11,     5,     9,
       1,     1,     1,     0,     2,     6,     6,     6,     4,     6,
       4,     6,     3,     5,     3,     3,     7,     2,     2,     6,
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
       1,     1,     1,     4,     2,     5,     3,     6,     4,     7,
       1,     2,     2,     3,     3,    11,     9,     7,     7,     0,
       3,     1,     3,     0,     3,     3,     1,     3,     1,     1,
       3,     4,     1,     3,     5,     4,     3,     4,     6,     7,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     6,     4,     4,     6,     6,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     8,    10,     0,     0,     3,     2,     4,     5,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    15,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   283,     0,   288,     0,   285,     0,     0,     0,    55,
      57,    56,    58,    59,    60,    61,    62,    63,    68,    67,
      64,    65,    66,     6,     0,     0,     0,    16,    17,    19,
      18,    20,   419,   419,     0,   398,   402,   452,   204,   399,
     400,   401,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   207,   206,   205,
       0,     0,     0,   210,   209,     0,     0,     0,     0,     0,
       0,   336,     0,     0,   278,     0,     0,     0,     0,     0,
       0,     0,     0,   263,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   410,     0,     0,     0,     0,     0,
       0,   263,   263,     0,     0,   263,   329,   330,   263,   263,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
     277,     0,   284,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   404,     0,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     339,   338,   340,     0,     0,     0,     0,     0,     0,     0,
       0,   215,   275,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   402,     0,
       0,     0,   262,   432,   261,   260,   428,     0,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   412,   411,     0,     0,     0,     0,
     263,   263,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,     0,     0,     0,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   421,     0,
       0,     0,     0,     0,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     452,     0,     0,     0,   337,   263,     0,   440,   441,     0,
       0,   204,     0,     0,     0,     0,   211,     0,   354,   353,
     352,   351,   347,   348,   350,   349,   342,   341,   343,   344,
     345,   346,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,     0,     0,     0,     0,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     414,   413,     0,     0,     0,     0,     0,     0,     0,   268,
     328,     0,     0,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   420,
       0,     0,    22,     0,   403,   408,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     356,   377,   357,   378,   358,   379,   359,   380,   360,   381,
     361,   382,   362,   383,   363,   384,   364,   385,   376,   397,
     365,   386,     0,     0,   367,   388,   368,   389,   369,   390,
     370,   391,   371,   392,   372,   393,     0,     0,     0,     0,
       0,     0,     0,     0,   455,     0,     0,   454,     0,     0,
       0,     0,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,    69,     0,     0,   263,   263,     0,   263,     0,
     263,   263,   436,     0,     0,     0,     0,   430,     0,     0,
       0,   433,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,   258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   263,     0,     0,   263,     0,     0,   273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   263,     0,     0,     0,     0,   263,   263,
       0,     0,     0,     0,     0,   263,     0,   263,     0,     0,
       0,     0,     0,   422,     0,   419,     0,   405,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,   442,
     443,     0,     0,     0,     0,     0,   216,   217,   219,     0,
       0,   450,     0,   225,   355,     0,     0,     0,     0,   263,
       0,   263,     0,     0,     0,   435,   437,     0,   431,     0,
       0,     0,     0,   232,     0,   263,   263,   263,     0,   321,
       0,   263,   263,   263,   263,   263,   263,   263,     0,     0,
       0,     0,     0,     0,     0,     0,   269,   327,   271,     0,
       0,     0,     0,     0,   423,     0,   447,     0,     0,     0,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,   332,   333,   334,
     335,     0,     0,     0,     0,     0,     0,     0,    21,     0,
     407,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   366,   387,
     373,   394,   374,   395,   375,   396,     0,   457,   456,   453,
     263,   204,     0,     0,     0,     0,   212,     0,     0,     0,
     448,    70,   229,   236,     0,   237,     0,   233,     0,   234,
     254,     0,     0,     0,     0,     0,   434,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,     0,     0,   263,     0,   292,     0,
     301,     0,   310,     0,     0,   242,   243,     0,   263,   263,
       0,   263,     0,     0,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,     0,
       0,     0,     0,     0,     0,     0,     0,   419,   409,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,     0,     0,   223,     0,   451,     0,   241,   252,   438,
       0,   265,   266,   267,     0,   325,   245,   247,     0,     0,
       0,   324,   326,   253,   230,   240,   251,   255,     0,     0,
       0,   418,     0,   417,     0,     0,   289,     0,     0,   298,
       0,     0,   307,     0,     0,     0,   423,     0,   426,     0,
       0,     0,     0,   445,     0,   281,   280,     0,     0,     0,
       0,     0,    24,     0,    33,     0,    37,     0,    31,     0,
       0,    36,     0,    41,    39,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,   218,   220,
       0,   226,     0,   238,   439,     0,     0,   323,   322,   227,
     228,   263,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   425,   263,   424,   263,     0,     0,     0,
     263,     0,     0,   423,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     458,     0,   449,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,   316,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   427,     0,     0,   444,
     282,     0,     0,    38,     0,     0,     0,     0,    28,     0,
      34,     0,    40,    29,    42,     0,    45,     0,    49,    50,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,     0,   263,   257,     0,     0,   294,     0,   320,
     263,     0,   317,   303,     0,     0,   312,     0,     0,     0,
       0,   263,   263,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   106,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,     0,     0,   263,   415,   290,     0,     0,
       0,   293,   299,     0,     0,   302,   308,     0,     0,   311,
     231,   235,     0,     0,   246,     0,     0,     0,     0,     0,
      32,    35,    43,     0,    44,    51,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   296,   263,     0,
     305,     0,   314,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,   248,
       0,   291,     0,     0,     0,   300,     0,     0,   309,     0,
       0,     0,     0,     0,     0,    27,    30,     0,     0,     0,
     100,     0,   104,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
       0,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,   319,
     304,     0,   313,     0,     0,     0,     0,     0,     0,    47,
      23,   101,   103,   105,   107,   109,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   199,
       0,   200,   239,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   114,   118,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,   318,   306,   315,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   203,     0,     0,     9,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     0,     0,     0,   112,     0,
     116,     0,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,     0,
      25,   113,   115,   117,   119,   121,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,   126,   130,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,   128,     0,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   127,   129,
     131,   133,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     142,   146,   150,   154,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,     0,   140,     0,
     144,     0,   148,     0,   152,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   139,   141,
     143,   145,   147,   149,   151,   153,   155,   157,   159,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   190,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,     0,   188,     0,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,   187,   189,   191,   193,
     195,     0,     0,     0,   174,   178,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,     0,   176,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   175,   177,   179,   181,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,   166,   170,     0,     0,     0,
       0,     0,     0,     0,   160,     0,   164,     0,   168,     0,
       0,     0,     0,     0,     0,   161,   163,   165,   167,   169,
     171
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     5,    85,     6,     7,    21,    22,    23,    24,     8,
      69,    70,    71,   426,  1609,   634,  1518,  1611,   635,  1519,
    1613,   636,  1520,  1827,   637,  1774,  1829,   638,  1775,  1831,
     639,  1776,  1963,   640,  1925,  1965,   641,  1926,  1967,   642,
    1927,  2075,   643,  2045,  2077,   644,  2046,  2079,   645,  2047,
    2081,   646,  2048,  2083,   647,  2049,  2085,   648,  2050,  2273,
     649,  2267,  2275,   650,  2268,  2277,   651,  2269,  2222,   652,
    2210,  2224,   653,  2211,  2226,   654,  2212,  2171,   655,  2153,
    2173,   656,  2154,  2175,   657,  2155,  1636,   658,  1542,  1730,
     659,  1638,   138,   242,    72,   520,   332,   333,   334,   335,
      76,    77,    78,    79,    80,  1177,  1488,  1592,  1180,  1493,
    1596,  1183,  1497,  1599,  1355,  1356,    81,    82,   961,   336,
     141,   354,   174,   237,   419,  1070,  1187,  1188,   338,   479,
     196,   720,   872,   142
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1324
static const short yypact[] =
{
    2806,    28, -1324, -1324,  -104,    87, -1324,   290,  3030, -1324,
      19, -1324,    97,   113,   142,   178,   192,   202,   -55,    77,
     101, -1324, -1324, -1324, -1324,  2342,   106,   205,   112,   152,
     168,   -37,   249,   186,   212,   327,   221,   354,   358,   380,
     393,   435,   333,   547,   244,   251,   -41,   -41,   254,   235,
       4,   417,     9,   458,   474,   134,   296,   300,   -18,     5,
       6, -1324,   307, -1324,   511, -1324,   520,   521,   499, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324,   529,    19,  2634, -1324, -1324, -1324,
   -1324, -1324,   352,   352,   560, -1324,   301,     8, -1324, -1324,
   -1324, -1324,  -162,  -153,  -124,   -42,   156,   163,   174,   226,
     239,   304,   326,   338,   366,   372,   373,   379,   428,   454,
     457,   468,   471,   365,   385,   386, -1324, -1324, -1324, -1324,
    2539,  2539,  2539, -1324, -1324,  2539,   948,    26,  2539,   578,
     553, -1324,   584,   619, -1324,  2539,  2539,  2539,   434,  2539,
     446,  2539,  2539,   583,  2539,   455,   460,   475,   487,   583,
     508,   524,   503,   526,   531,   535,   548,   690,   -41,   -41,
     -41,  2539,  2539,   128, -1324,   158,   -41,   545,   557,   592,
     509, -1324,   583,   515,   764, -1324, -1324, -1324,   583,   583,
    2539,  2539,   -61,  2539,   625,  2539,   648,   735,  2539,  2539,
   -1324,   858, -1324,   670, -1324,    19,   687,   698,   701,   704,
     705,   706,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   721,   725,   737,   738,   739,   740,   741,   744,
     745,   746,   747,   748,   750,   752,   878,   749,   742,   753,
    2539,   946, -1324,   -41, -1324,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,    42,    45,    45,
     760,   760,   760, 11170,   949,  2450, 10603,    10,   782,   975,
     647, -1324, -1324,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539, -1324,   -84,
   11193, 11216, 11239,  2539, 11262,  2539, 11285, 11308,   323,   788,
    1560,  2450, -1324, -1324,  2886, -1324,  1679,   977, -1324, 11331,
    2539,  2539,  2539,  2539,   978,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,   790,   119, -1324, -1324,  3427,  3450,   -41,   -41,
     600,   600,   165,  2539,  2539,  2539,  2539,  2012,   256,  2539,
   -1324,  2574,   984,   996, 11354, 11377,   901,  2539, 11400,   900,
    3473, -1324,   806,  1763, 11423, -1324,  2539,   843,  1005,  1006,
    1007,  1008,  1009,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,   886,  1036,  1038,  1039,  1040,  1043,  1042, -1324,   -63,
    1044,  1045,  1047, 10624,   135,   161,  2805, 11446, 10645, 11469,
   10666, 11492, 10687, 11515, 10708, 11538, 10729, 11561, 10750, 11584,
   10771, 11607, 10792, 11630, 10813, 11653, 10834, 11676, 10855,  3496,
    3519, 11699, 10876, 11722, 10897, 11745, 10918, 11768, 10939, 11791,
   10960, 11814, 10981,  3542,  3565,  3588,  3611,  3634,  3657,   470,
   -1324,   -33,   848,   859, -1324,   583,  2638,  1679, -1324,   479,
     138,    45,  2539,  1048,  1052,    12, -1324,  1809,   262,   693,
     324,   324,   298,   298,   298,   298,   218,   218,   760,   760,
     760,   760,  1051,  2450,  1053,  1054,  1055, 11837,  1057, 11860,
    1058,  1059,  1194,  2539,   337,  2450,   483,  -126,   -39,   -50,
   -1324,  2539,  2539,  1060,  2863, 11883, 11906, 11929,  2539,  2986,
    3011, 11952, 11975, 11998, 12021, 12044,   860,   -41,  2539,  2539,
   -1324, -1324,   856,   866,  2539,  3680,  3703,  3726, 11002, -1324,
   -1324,  2539, 11023, -1324,   868,   872,  1067,  1068,   881, 12067,
    1071,   880,  2539,  2639,  2539,  2539, -1324, 12090,   913,   882,
     883,   884,   911,   912,   917,   930,   935,   936,   937,   939,
     941,   942,   944,   945,   950,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   965, -1324,
    1108,   970, -1324,   968,  -107, -1324, -1324,   982,   994,   995,
     997,  1001,  1004,  1033,  1034,  1035,  1037,  1041,  1049,  1050,
    1062,  1063,  1064,  1065,  1066,  1069,  1070,  1072,  1073,  1074,
    1075,  1077,  1078,  1134, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324,  2539,  2539, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  1144, -1324,  2450,    45, -1324,  1167,  2450,
     993,    33,  2539,  1195,  1221,   672, -1324,  1193,  1046,     5,
    1225,  2539, -1324,    -4,   -41,   583,   583,  1226,   583,  1227,
     583,   583, -1324,  2450, 12113,  1330,   486, -1324,  2450,  2450,
    2450,  2085,   743,  1076,  1228,  1230,  1231,  1232,   370,  1233,
    1235,  1239,  1240,  1241,  1243,  1245,  1250,   172,  3749,  3772,
   -1324, -1324,  3036,   -41,   -41,   -41,  1257,   814,  1260,  2539,
    2539,   583,   583,  2539,  1267,   583,  1271,  3795, -1324,  2113,
     452,  1269,  1115,  1277,  2539,  2539,   -41,  1278,  1279,  1097,
    1282,  1283,   583,   583,  1285,   -41,  1312,  1313,   583,   583,
    1315,  1316,  1317,  1319,  1323,   583,   495,   583,  1324,  1325,
    1326,  1329,  1332, -1324,  1331,   352,  1362, -1324,  2936,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539, -1324, 12136, 11044, 12159, 11065,
   12182, 11086, 12205, 11107, 11128,  1133,    18,  1140, -1324,  1679,
   -1324,    16,   162,  1181,  1374,   940, -1324, -1324, -1324,     5,
    2539, -1324,   489, -1324, 13056,  1376,    15,    25,  1379,   583,
    1380,   583,  1381,  1382,   490, -1324, -1324,  2450, -1324,   493,
     497,   501,  2539, -1324,  2539,   583,   583,   583,  1196, -1324,
     335,   583,   583,   583,   583,   583,   583,   583,   404,  2539,
    2539,  2539,  1192,  -132,  -118,   -43, -1324, -1324, -1324,  3818,
    3841,  1384,  1388, 12228,   -87,  1292, -1324,  2539,  2539,  2539,
   -1324,  1197,    19,  1199,  3864,  3887,   -35,  1200,  1201,  1202,
    1205,  1204,  1209,  1206,  1207,   213,  1208,  1214,  1218,  1216,
    1217,  1219,  1220,  1222,  1223,  1234, -1324, -1324, -1324, -1324,
   -1324,  1224,  1229,  1259,  1261,  1262,  1236,  1263, -1324,  1265,
     135,  1412,  3910,  3933,  3956,  3979,  4002,  4025,  4048,  4071,
    4094,  4117,  4140,  4163,  4186,  4209,  4232,  4255,  4278,  4301,
    4324,  4347,  4370,  4393,  4416,  4439,  4462,  4485, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324,  1258, -1324, -1324, -1324,
     583,    45,  2539,  1415,  1422,    12, -1324,  1421, 11149,     5,
   -1324, -1324, -1324, -1324,   -41, -1324,  1427, -1324,  1428, -1324,
   -1324,  1237,   502,  1454,  1461,  1463, 13056,  4508,  1464,  1466,
    1470,  2539,  2539,  2539,  1482,  1483,  1484,  1485,  1486,  1505,
    1506, -1324,  2416,  3061, 12251,   -85,   600,   -41,  1507,   -41,
    1512,   -41,  1513,  2539,  2539, -1324, -1324,  1510,   583,   583,
    1417,   583,  2520,   287, 12274,  2539,    19,  1425,  2539,   583,
    1516,  1520,  1518,  1340,  1521,   495,  1523,  1527,  2539,  1526,
    1530,  1528,  1529,  1533,   495,  2539,  2539,  2539,   583,  1555,
    1559,   495,  2539,  1562,  1563,  1561,  2539,   352, -1324, -1324,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  1592,  1602,  1603,  1000,
   -1324,  1604,  1606, -1324,  1411, -1324,    32, -1324, -1324, -1324,
    1416, -1324, -1324, -1324,  2539, -1324, -1324, -1324,  4531,  1189,
    1322, -1324, -1324, -1324, -1324, -1324, -1324, -1324,  1419,  1609,
    1418, -1324,  2539, -1324,  1420,   182, -1324,  1424,   190, -1324,
    1426,   194, -1324,  1432,  4554,  4577,   -87,    68, -1324,   505,
    1434,  1517,  2539, -1324,  2539, -1324, -1324,  4600,    19,  1430,
    4623,  1423, -1324,  1429, -1324,  1457, -1324,  1462, -1324,  1459,
   12297, -1324,  1460, -1324, -1324,  1465,  1467, 12320,  4646, 12343,
    1468, -1324,  1469,  1471,  4669,  1472,  1473, -1324,  4692,  1474,
    4715,  4738,  4761,  4784,  4807,  4830,  4853,  4876,  4899,  4922,
    4945,  4968,  4991,  5014,  5037,  5060,  5083,  5106,  5129,  5152,
    5175,  5198,  5221,  5244,  5267,  5290,  1475, -1324, -1324, -1324,
       5, -1324,  1514, -1324, -1324,  5313,  2539, -1324, -1324, -1324,
   -1324,   600,  2931, -1324,  2310,    52,  2310,    52,  2310,    52,
    2539,  2539,  1524, -1324,   583, -1324,   583,  2539,  3086,  3111,
     583,  1458,  1611,   -87,   495,  1663,  2539,  1667,   495,  1669,
    1673,  1671,  1672,  1674,  2539,  1676,   583,  1678,  1680,  2539,
    1685,  1683,  2539,  1686,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
   -1324,  1684, -1324,  1687, 12366,  1477,  2539, -1324,  2310,  2310,
    2539,  3140,   199,  1688,  1494,   -26, -1324,  3165,   201,   -23,
    3190,   203,   -17,  3215,  3244,  1495, -1324,  1497,  1625, -1324,
   -1324,  1496,    19, -1324,  1501,  1502,  1503,  5336, -1324,  1508,
   -1324,  1509, -1324, -1324, -1324, 12389, -1324,  1515, -1324, -1324,
   12412,  1522, -1324, 12435,  1519, 12458, 12481, 12504,  5359,  5382,
    5405,  5428,  5451,  5474,  5497,  5520,  5543,  5566,  5589,  5612,
    5635,  5658,  5681,  5704,  5727,  5750,  5773,  5796,  5819, 12527,
    5842, -1324,  1538,   583, -1324,  3277,  1299,  1700,  2539, -1324,
     583,  1701, -1324,  1702,  2539,  1703,  1704,  2539,  1705,  1708,
    1710,   583,   583, -1324,  1711,    19,   495,   495,   495,   495,
    1733,  1734,  1735,   495,  1736,  1737,  1740,  1742, -1324, -1324,
   -1324,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539, -1324,  2539,  1743,   583, -1324, -1324,  1548,  3302,
    1551, -1324, -1324,  1552,  3327, -1324, -1324,  1553,  3352, -1324,
   -1324, -1324,  1557,  1550, -1324,    19,  1558,  1564,  1566,  1567,
   -1324, -1324, -1324,  1565, -1324, -1324, -1324,  1568,  1569,  1572,
    1573,  5865,  5888,  5911,  5934,  5957,  5980,  6003,  6026,  6049,
    6072,  6095,  6118,  6141,  6164,  6187,  6210,  6233,  6256,  6279,
    6302,  6325,  1574, 12550,  1576,  1753,    52,  1754,   583,    52,
    1760,    52,  1761,   583,  1668,  1635,   495,   495,  1796,  1808,
     495,  1810,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,    45, -1324,  1811, -1324,
     -11, -1324,  1617,   516,    -9, -1324,  1619,    -8, -1324,  1620,
    1621,  1623,    19,  1622,  1626, -1324, -1324,  1629,  1631,   517,
   13056,   522, 13056,   550, 13056,  6348,  6371,  6394,  6417,  6440,
    6463,  6486,  6509,  6532,  6555,  6578,  6601,  6624,  6647,  6670,
    6693,  6716,  6739,  6762,  6785,  6808,   551, -1324,  1627,  1628,
    1826,    52,   583,  1828,  1850,    52,  1862,    52,  1768,  2539,
      19,   495,   583,  1864,  1865,  2539,  1866,  2539,  1868,  2539,
    1869,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,    45,  1870,    45,  1871, -1324,    -7,  1677, -1324,
   -1324,    17, -1324,    64,  1681,  6831,    19,  1699,  1706, -1324,
   -1324, 13056, -1324, 13056, -1324, 13056, -1324, 12573, 12596, 12619,
    6854,  6877,  6900,  6923,  6946,  6969,  6992,  7015,  7038,  7061,
    7084,  7107,  7130,  7153,  7176,  7199,  7222,  7245, -1324, -1324,
     554, -1324, -1324,  1872,  1874,  1875,  1877,  2539,  2539,  1732,
     495,   583, -1324, -1324, -1324,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,    45,  1895, -1324, -1324, -1324, -1324,  7268,
    3377,  1738,  1709,  1712,  1707,  1713,  1714,  7291,  7314,  7337,
    7360,  7383,  7406,  7429,  7452,  7475,  7498,  7521,  7544,  7567,
    7590,  7613,  7636,  7659,  7682, -1324, -1324,  2539,  1896, -1324,
     583,   495,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  3402, -1324,  1716,  1715,   555, 13056,   561,
   13056,   562, 13056,  7705,  7728,  7751,  7774,  7797,  7820,  7843,
    7866,  7889,  7912,  7935,  7958,  7981,  8004,  8027,  8050,  8073,
    8096,  1897,   583,  1898,  2539,  1899,  2539,  1904,  2539,  1907,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539, -1324,  1717,
   -1324, 13056, -1324, 13056, -1324, 13056, -1324, 12642, 12665, 12688,
    8119,  8142,  8165,  8188,  8211,  8234,  8257,  8280,  8303,  8326,
    8349,  8372,  8395,  8418,  8441,   583, -1324, -1324, -1324,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  1718,  1739,  1751,  1752,  8464,  8487,
    8510,  8533,  8556,  8579,  8602,  8625,  8648,  8671,  8694,  8717,
    8740,  8763,  8786,   583,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  1755,   569, 13056,   574, 13056,   575, 13056,  8809,
    8832,  8855,  8878,  8901,  8924,  8947,  8970,  8993,  9016,  9039,
    9062,  9085,  9108,  9131,   495,  2539,  1948,  2539,  1950,  2539,
    1952,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  1765, 13056, -1324, 13056,
   -1324, 13056, -1324, 12711, 12734, 12757, 12780, 12803, 12826,  9154,
    9177,  9200,  9223,  9246,  9269,  9292,  9315,  9338,  1953, -1324,
   -1324, -1324, -1324, -1324, -1324,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539, -1324,  1762,  1764,  1780,  1781,  1797,
    1798,  9361,  9384,  9407,  9430,  9453,  9476,  9499,  9522,  9545,
    2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,   579, 13056,   580, 13056,   585,
   13056,   586, 13056,   589, 13056,   590, 13056,  9568,  9591,  9614,
    9637,  9660,  9683,  9706,  9729,  9752,  2539,  1994,  2539,  1995,
    2539,  1996,  2539,  1998,  2539,  1999,  2539,  2000,  2539,  2539,
    2539,  2539,  2539,  2539,  2539,  2539,  2539, 13056, -1324, 13056,
   -1324, 13056, -1324, 13056, -1324, 13056, -1324, 13056, -1324,  9775,
    9798,  9821,  9844,  9867,  9890, 12849, 12872, 12895,  2539,  2539,
    2539,  2539,  2539,  2539, -1324, -1324, -1324,  9913,  9936,  9959,
    9982, 10005, 10028,  1806,  1807,  1818,  2539,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2539, 10051, 10074, 10097, 10120, 10143,
   10166,   636, 13056,   637, 13056,   642, 13056,  2539,  2539,  2539,
    2539,  2539,  2539,  2539,  2003,  2539,  2014,  2539,  2015, 10189,
   10212, 10235, 12918, 12941, 12964, 13056, -1324, 13056, -1324, 13056,
   -1324,  2539,  2539,  2539, -1324, -1324, -1324, 10258, 10281, 10304,
    1821,  1822,  1823,  2539,  2539,  2539,  2539,  2539,  2539, 10327,
   10350, 10373,   661, 13056,   668, 13056,   688, 13056,  2539,  2539,
    2539,  2539,  2019,  2539,  2020,  2539,  2021, 10396, 10419, 10442,
   13056, -1324, 13056, -1324, 13056, -1324,  2539,  2539,  2539, 10465,
   10488, 10511,  2539,  2539,  2539, 10534, 10557, 10580,  2539,  2539,
    2539, 12987, 13010, 13033, -1324, -1324, -1324,  1827,  1829,  1830,
    2539,  2539,  2539,   689, 13056,   692, 13056,   695, 13056,  2539,
    2023,  2539,  2026,  2539,  2027, 13056, -1324, 13056, -1324, 13056,
   -1324
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -1324, -1324,   -34, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324,  1452, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324,  -283,   -22, -1324,  2052,  2056,  -356,  -174,  2059,
   -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324, -1324,
   -1324, -1324, -1324, -1324, -1252, -1323, -1324, -1324, -1029,   -25,
   -1324,   407, -1324,   -92, -1324, -1157,   999,  1511,  -167,  -325,
    -717,  1061, -1324,  -269
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -55
static const short yytable[] =
{
     140,   238,   871,   139,   542,   543,   516,   367,   180,   194,
     197,   371,   243,   183,   482,   150,   718,   481,   471,   472,
     473,  1022,    83,    98,   192,  1359,   148,  1362,   148,  1282,
     297,  1023,  1432,   245,     9,   246,  1432,   862,  1263,  1432,
    1353,   376,   247,  1353,   248,  1354,   469,   470,  1354,  1353,
     470,   205,   358,   359,  1354,  1353,  1207,  1353,  1353,  1353,
    1354,    10,  1354,  1354,  1354,  1216,   358,   359,  1057,   145,
    1058,   249,  1223,   250,  1024,   738,   123,   124,   125,   123,
     124,   125,  1059,  1353,  1060,   133,   134,    11,  1354,   303,
     304,   305,   816,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    86,   290,   291,   292,  1068,   317,
     293,   296,   502,   300,  1069,  1172,   503,  1173,  1353,    87,
     320,   321,   322,  1354,   324,   184,   326,   327,   478,   339,
    1353,   298,   299,   599,   377,  1354,  1374,   600,   863,   864,
      92,   358,   359,   169,   170,    98,   356,   357,    88,   358,
     359,   740,  1017,   251,   171,   252,   149,  1061,   149,  1062,
     172,  1080,   739,   704,   478,   374,   375,   705,   378,  1011,
     380,   387,   188,   383,   384,   189,  1431,   193,   723,  1435,
     126,   127,   128,   129,    89,  1438,   126,   127,   128,   129,
     736,  1640,   875,  1644,  1646,  1733,   709,   712,    90,   358,
     359,   198,   133,   134,    84,   181,   195,   563,    91,   244,
     185,   144,   714,   719,  1008,   423,   358,   359,   709,  1735,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   550,   551,  1283,  1375,  1736,  1432,  1284,  1379,
     477,  1432,    93,   177,  1432,   483,   178,   179,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,    12,  1590,  1194,    94,  1594,   507,  1597,
     509,   143,  1145,   358,   359,   291,   477,   145,   126,   127,
     128,   129,   358,   359,   150,   524,   525,   526,   527,   537,
     529,   530,   531,   532,   533,   534,   535,   133,   134,   360,
     133,   134,   126,   127,   128,   129,   478,   711,   545,   546,
     547,   548,   358,   359,   552,   358,   359,   146,   478,   358,
     359,   253,   559,   254,   133,   134,   358,   359,   255,   361,
     256,   567,   606,   147,  1432,   544,   358,   359,  1432,   257,
    1432,   258,   909,   153,   358,   359,   899,   162,   358,   359,
     856,   151,  1274,   358,   359,   358,   359,   358,   359,  1687,
    1276,  1042,  1043,  1691,  1278,  1693,   155,   358,   359,  1428,
     156,  1434,   605,  1437,   314,   315,   316,   152,   884,  1089,
    1051,  1052,   317,   889,   890,   891,   154,  1506,  1507,  1508,
    1509,   259,   157,   260,  1513,   900,    13,    14,    15,    16,
      17,    18,    19,    20,   261,   158,   262,   857,   305,   167,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   291,   168,   173,   175,   176,   317,   715,   713,   182,
     929,   303,   304,   305,   186,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   159,   160,   477,   161,
     187,   317,   312,   313,   314,   315,   316,   423,   734,  1195,
     477,   190,   317,   133,   134,   191,   741,   742,   240,   263,
     241,   264,   199,   748,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   758,   759,   133,   134,   200,   317,   762,
     512,   265,   241,   266,   201,   202,   767,  1603,  1604,   133,
     134,  1607,   204,   267,   735,   268,   241,   777,   478,   779,
     780,   203,   860,  1341,   303,   304,   305,   236,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   302,
     287,   269,  1032,   270,   317,   239,   478,   271,   273,   272,
     274,   478,   478,   478,   275,   353,   276,   355,  1010,  1012,
     288,   289,   817,   362,   301,   163,    95,   328,   164,   165,
     318,   166,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   956,   957,   958,   959,
     960,   329,  1697,   277,   319,   278,   303,   304,   305,   323,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   325,    45,    46,    47,    48,   317,    50,   930,   279,
     425,   280,   281,   486,   282,   341,   340,   846,   847,    45,
      46,    47,    48,   283,    50,   284,   285,   702,   286,   703,
     342,   848,   849,   850,   851,   852,   853,   854,   868,   709,
     477,   710,   343,   709,   859,   737,   709,   865,   888,  1019,
     709,  1020,  1031,   709,   352,  1033,   874,   709,   347,  1034,
    1174,   709,   709,  1035,  1150,  1284,   366,  1285,   477,   345,
     423,  1772,   369,   477,   477,   477,  1642,  1655,  1643,  1656,
     478,   348,  1657,   969,  1658,   346,   349,   303,   304,   305,
     350,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,  1138,   351,   919,   920,   363,   317,   923,   893,
    1659,  1682,  1660,  1683,  1763,  1854,  1764,  1855,   364,   934,
     935,  1856,  1858,  1857,  1859,   540,   541,   130,   330,  1985,
     370,  1986,  1826,   132,  1987,  1989,  1988,  1990,   135,  2096,
    2098,  2097,  2099,  1169,   331,  2100,  2102,  2101,  2103,  2104,
    2106,  2105,  2107,   365,   972,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,   997,
     917,   303,   304,   305,   379,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,  2183,  2185,  2184,  2186,
    1013,   317,  2187,   382,  2188,  1018,   303,   304,   305,   381,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,  2231,   477,  2232,   385,   386,   317,  1036,  2233,  1037,
    2234,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   388,   418,  1053,  1054,  1055,   317,  2235,  2279,
    2236,  2280,  2281,   389,  2282,  2283,   390,  2284,  1076,   391,
     392,   393,  1072,  1073,  1074,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,  1345,   404,   303,   304,   305,
     405,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   406,   407,   408,   409,   410,   317,   421,   411,
     412,   413,   414,   415,   757,   416,  1016,   417,  1108,   420,
     424,    95,    96,   422,   317,  2006,   475,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   484,   485,   513,   522,   528,   536,  1139,   303,   304,
     305,   554,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   555,   558,   561,  1259,   564,   317,   568,
     569,   570,   571,   572,   573,  1229,  1158,  1159,  1160,   574,
     575,   576,   577,   578,   579,   580,   581,  1168,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,  1184,  1185,
     592,   593,  1198,   594,   595,   596,   597,   598,   706,   601,
    1197,   602,   603,  1200,   716,   707,   717,   722,   760,   756,
     724,   725,   726,  1210,   728,   730,   731,   743,   761,   769,
    1217,  1218,  1219,   770,   771,   772,   773,  1224,   775,   776,
     782,  1228,   783,   784,   785,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1255,   786,   787,   813,   303,   304,   305,   788,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,  1265,
     789,   876,   130,   131,   317,   790,   791,   792,   132,   793,
     845,   794,   795,   135,   796,   797,   294,  1272,   855,   295,
     798,   799,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809,   810,   811,  1291,   812,   814,  1288,   815,  1289,
     913,   914,   915,   858,   303,   304,   305,   819,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   820,
     821,   861,   822,   936,   317,  1267,   823,    95,    96,   824,
     869,   866,   945,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   867,   825,   826,
     827,   873,   828,   879,   881,   895,   829,   896,   897,   898,
     901,  1344,   902,   870,   830,   831,   903,   904,   905,  1351,
     906,  1357,   907,  1360,   908,  1363,  1364,   832,   833,   834,
     835,   836,  1368,   916,   837,   838,   918,   839,   840,   841,
     842,  1377,   843,   844,   924,   926,   931,   894,   932,  1385,
     933,   937,   938,   939,  1390,   940,   941,  1393,   944,  1395,
    1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,  1405,
    1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,
    1416,  1417,  1418,  1419,  1420,   946,   947,  1637,   950,   951,
     952,  1425,   953,   290,   291,  1426,   954,   963,  1268,  1007,
     964,   965,   966,    95,    96,   967,  1009,   968,  1445,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   303,   304,   305,   970,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   130,   131,
    1014,  1015,  1021,   317,   132,  1025,  1027,  1029,  1030,   135,
    1065,  1041,   732,  1056,  1066,   733,  1071,  1082,  1075,  1077,
    1081,  1084,  1083,  1489,  1085,  1086,  1087,  1088,  1090,  1494,
    1091,  1505,  1498,  1728,  1092,  1731,  1093,  1094,  1109,  1095,
    1096,  1140,  1097,  1098,  1100,  1269,  1141,  1143,  1199,  1101,
    1099,  1146,  1105,  1147,  1148,  1149,  1521,  1522,  1523,  1524,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1538,  1539,  1540,  1541,  1136,  1543,  1102,
    1151,  1103,  1104,  1106,  1175,  1107,  1178,  1152,  1181,  1153,
    1155,  1555,  1156,   303,   304,   305,  1157,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,  1161,  1162,
    1163,  1164,  1165,   317,  1795,   474,   303,   304,   305,   538,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,  1166,  1167,  1176,   130,   131,   317,  1186,  1179,  1182,
     132,  1190,  1202,  1203,  1204,   135,  1205,  1206,   886,  1208,
    1209,   887,  1211,  1212,  1213,  1214,  1215,  1610,  1612,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1221,  1222,    95,   514,  1225,  1226,  1227,  1650,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   303,   304,   305,  1256,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,  1257,  1258,
    1262,  1260,  1261,   317,  1264,  1270,  1696,  1373,  1287,  1271,
    1342,  1372,  1273,  1294,  1695,  1275,  1292,  1277,  1365,  1295,
    1701,  1443,  1703,  1279,  1705,  1286,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,
    1721,  1722,  1723,  1724,  1725,  1726,  1727,  1296,  1297,  1298,
    1300,  1301,  1739,  1302,   337,  1307,  1376,  1308,  1306,  1311,
     344,  1340,  1310,  1378,  1313,  1380,  1381,  1382,  1383,  1424,
    1384,  1352,  1386,  1358,  1388,  1361,  1389,   521,  1391,  1392,
    1421,  1394,  1422,   368,  1429,  1430,  1441,  1442,  1444,   372,
     373,  1446,  1447,  1448,  1450,  1451,  1487,  1491,  1492,  1495,
    1496,  1499,  1769,  1770,  1500,  1453,  1501,  1504,  1455,  1457,
    1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,
    1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,  1484,  1510,
    1511,  1512,  1514,  1515,   130,   131,  1516,  1517,  1544,  1546,
     132,  1548,  1554,  1549,  1551,   135,   355,  1553,  1556,  1589,
    1591,   515,  1558,  1559,  1557,  1560,  1595,  1598,  1561,  1601,
    1562,   565,  1823,  1563,  1564,  1586,  1588,  1828,  1830,  1832,
    1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1602,   303,
     304,   305,  1605,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,  1606,  1608,  1639,   721,  1641,   317,
    1645,  1647,  1651,  1648,  1649,  1653,  1652,  1654,  1684,  1881,
    1685,  1883,  1686,  1885,  1689,  1887,  1888,  1889,  1890,  1891,
    1892,  1893,  1894,  1895,  1896,  1897,  1898,  1899,  1900,  1901,
    1902,  1903,  1904,   303,   304,   305,  1690,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,  1692,  1694,
    1699,  1700,  1702,   317,  1704,  1706,  1729,  1732,  1765,  1734,
    1766,  1767,  1737,  1768,  1928,  1929,  1930,  1931,  1932,  1933,
    1934,  1935,  1936,  1937,  1938,  1939,  1940,  1941,  1942,  1740,
    1771,  1796,  1824,  1878,  1880,  1882,  1741,  1799,  1802,  1800,
    1884,  1853,  1801,  1886,  1803,  1804,  1852,  1905,  1943,  1964,
    1966,  1968,  1969,  1970,  1971,  1972,  1973,  1974,  1975,  1976,
    1977,  1978,  1979,  1980,  1981,  1982,  1983,   303,   304,   305,
    1944,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,  1945,  1946,  2008,  1984,  2010,   317,  2012,  2044,
    2007,  2028,  2009,  2060,  2011,  2061,  2013,  2014,  2015,  2016,
    2017,  2018,  2019,  2020,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2062,  2063,   303,   304,   305,   708,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,  2064,  2065,
    2118,  2120,  2122,   317,  2124,  2126,  2128,  2162,  2163,  2196,
    2051,  2052,  2053,  2054,  2055,  2056,  2057,  2058,  2059,  2164,
    2198,  2200,  2216,  2217,  2218,  2241,  2243,  2245,  2270,  2286,
    2271,  2272,  2288,  2290,     0,  2076,  2078,  2080,  2082,  2084,
    2086,  2087,  2088,  2089,  2090,  2091,  2092,  2093,  2094,  2095,
     517,    29,    30,   518,   519,    33,    34,    35,   818,    36,
      73,    38,    39,    40,    74,    42,    43,    75,  1189,     0,
       0,  2117,     0,  2119,     0,  2121,  1142,  2123,     0,  2125,
       0,  2127,    55,  2129,  2130,  2131,  2132,  2133,  2134,  2135,
    2136,  2137,     0,   892,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    58,  2147,  2148,  2149,  2150,  2151,  2152,     0,
       0,   928,     0,     0,     0,     0,     0,     0,     0,    68,
       0,  2165,  2166,  2167,  2168,  2169,  2170,  2172,  2174,  2176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2189,  2190,  2191,  2192,  2193,  2194,  2195,     0,
    2197,     0,  2199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2207,  2208,  2209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2219,  2220,
    2221,  2223,  2225,  2227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2237,  2238,  2239,  2240,     0,  2242,     0,
    2244,     0,     0,     0,   549,     0,     0,     0,     0,     0,
       0,  2249,  2250,  2251,     0,     0,     0,  2255,  2256,  2257,
       0,     0,     0,  2261,  2262,  2263,   877,   878,     0,   880,
       0,   882,   883,     0,     0,  2274,  2276,  2278,     0,     0,
       0,     0,     0,     0,  2285,     0,  2287,     0,  2289,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   921,   922,     0,     0,   925,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,   942,   943,     0,     0,   317,     0,   948,
     949,     0,     0,    95,    96,     0,   955,     0,   962,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,    95,    96,    97,     0,    98,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,   124,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1026,     0,  1028,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1038,  1039,  1040,     0,
       0,     0,  1044,  1045,  1046,  1047,  1048,  1049,  1050,    95,
      96,   470,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,   124,   125,    95,   328,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,  1348,  1349,     0,     0,     0,     0,
     132,     0,     0,     0,     0,  1350,     0,     0,     0,     0,
       0,   172,   126,   127,   128,   129,     0,     0,     0,     0,
       0,  1137,     0,     0,     0,     0,   130,   131,     0,     0,
       0,     0,   132,     0,   133,   134,     0,   135,     0,   136,
       0,   137,    95,    96,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1191,     0,     0,     0,     0,     0,     0,     0,
    1201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,     0,     0,     0,     0,   132,     0,     0,  1220,
       0,   135,   517,    29,    30,   518,   519,    33,    34,    35,
       0,    36,     0,    38,    39,    40,     0,    42,    43,     0,
       0,     0,     0,     0,   130,   476,     0,     0,     0,     0,
     132,    95,   514,     0,    55,   135,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,    56,    57,    58,   206,     0,   517,    29,    30,
     518,   519,    33,    34,    35,     0,    36,     0,    38,    39,
      40,    68,    42,    43,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    55,
       0,     0,     0,     0,   317,     0,     0,     0,     0,     0,
    1192,     0,  1193,   130,   131,     0,     0,     0,     0,   132,
       0,     0,     0,     0,   135,     0,     0,    56,    57,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   207,   208,   209,     0,    68,     0,     0,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,   553,     0,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   233,   234,   235,  1366,     0,  1367,     0,     0,
       0,  1371,     0,     0,     0,     0,   -11,     1,     0,   -11,
     -54,     0,     0,     0,     0,     0,     0,  1387,     0,     0,
       0,     0,   130,   131,     0,     0,     0,     0,   132,     0,
       0,     0,     0,   135,     0,     0,     0,     0,     0,   -54,
       0,   778,     0,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,     0,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,     0,   -54,   -54,   -54,   -54,   -54,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,     0,   -54,   -54,   -54,     0,     0,     0,
       0,   -54,     0,   -54,     0,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,     0,   -54,   517,    29,    30,   518,   519,    33,
      34,    35,     0,    36,  1485,    38,    39,    40,     0,    42,
      43,  1490,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
       0,     0,  1502,  1503,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1545,     0,     0,     0,
       0,     0,     0,    68,     0,     0,     0,   633,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,    25,     0,     0,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,  1593,
       0,     0,     0,    26,  1600,   744,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     0,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,    44,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,    54,
      55,     0,     0,     0,     0,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,    56,    57,
      58,  1346,     0,  1347,     0,    59,     0,    60,   971,    61,
      62,    63,    64,    65,    66,    67,     0,    68,     0,     0,
       0,     0,     0,  1688,     0,     0,     0,     0,     0,     0,
     303,   304,   305,  1698,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,     0,     0,   303,   304,   305,   749,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,     0,     0,
     303,   304,   305,   750,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,     0,     0,   303,   304,   305,   912,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,  1773,     0,     0,   317,     0,     0,     0,     0,
     303,   304,   305,  1170,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,     0,     0,   303,   304,   305,  1369,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,     0,     0,
       0,  1825,     0,  1370,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,     0,     0,   303,
     304,   305,  1427,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,     0,  1879,   303,   304,   305,  1433,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,     0,     0,   303,
     304,   305,  1436,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,     0,     0,     0,     0,  1924,  1439,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,     0,     0,     0,     0,     0,  1440,     0,     0,     0,
       0,   303,   304,   305,  1962,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,     0,     0,   303,   304,   305,  1486,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,     0,
       0,   303,   304,   305,  1547,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,     0,     0,   303,   304,   305,  1550,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,     0,
       0,   303,   304,   305,  1552,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,     0,     0,   303,   304,   305,  1798,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,     0,
       0,   303,   304,   305,  1851,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,   538,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
     539,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,   562,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,   682,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,   683,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,   696,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,   697,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,   698,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,   699,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,   700,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,   701,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
     763,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,   764,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,   765,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,   910,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,   911,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,   927,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1063,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1064,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1078,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1079,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1110,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1111,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1112,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1113,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1114,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1115,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1116,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1117,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1118,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1119,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1120,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1121,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1122,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1123,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1124,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1125,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1126,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1127,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1128,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1129,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1130,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1131,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1132,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1133,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1134,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1135,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1154,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1266,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1280,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1281,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1290,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1293,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1304,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1309,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1312,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1314,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1315,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1316,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1317,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1318,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1319,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1320,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1321,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1322,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1323,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1324,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1325,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1326,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1327,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1328,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1329,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1330,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1331,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1332,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1333,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1334,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1335,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1336,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1337,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1338,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1339,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1343,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1449,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1461,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1462,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1463,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1464,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1465,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1466,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1467,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1468,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1469,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1470,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1471,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1472,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1473,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1474,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1475,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1476,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1477,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1478,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1479,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1480,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1481,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1483,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1565,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1566,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1567,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1568,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1569,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1570,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1571,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1572,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1573,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1574,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1575,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1576,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1577,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1578,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1579,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1580,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1581,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1582,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1583,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1584,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1585,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1661,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1662,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1663,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1664,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1665,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1666,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1667,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1668,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1669,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1670,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1671,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1672,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1673,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1674,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1675,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1676,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1677,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1678,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1679,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1680,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1681,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1738,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1745,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1746,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1747,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1748,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1749,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1750,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1751,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1752,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1753,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1754,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1755,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1756,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1757,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1758,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1759,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1760,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1761,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1762,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1797,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1805,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1806,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1807,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1808,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1809,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1810,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1811,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1812,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1813,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1814,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1815,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1816,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1817,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1818,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1819,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1820,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1821,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1822,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1860,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1861,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1862,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1863,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1864,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1865,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1866,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1867,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1868,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1869,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1870,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1871,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1872,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1873,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1874,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1875,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1876,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1877,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1909,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1910,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1911,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1912,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1913,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1914,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1915,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1916,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1917,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1918,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1919,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1920,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1921,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1922,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1923,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1947,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1948,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1949,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1950,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1951,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1952,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1953,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1954,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1955,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1956,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1957,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1958,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1959,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1960,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  1961,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  1991,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  1992,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  1993,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  1994,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  1995,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  1996,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  1997,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    1998,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  1999,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  2000,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  2001,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  2002,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  2003,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  2004,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  2005,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  2035,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  2036,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    2037,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  2038,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  2039,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  2040,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  2041,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  2042,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  2043,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  2066,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  2067,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  2068,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    2069,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  2070,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  2071,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  2072,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  2073,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  2074,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  2108,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  2109,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  2110,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  2111,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    2112,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  2113,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  2114,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  2115,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  2116,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  2138,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  2139,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  2140,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  2141,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  2142,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    2143,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  2156,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  2157,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  2158,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  2159,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  2160,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  2161,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  2177,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  2178,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  2179,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    2180,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  2181,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  2182,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  2201,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  2202,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  2203,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  2213,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  2214,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  2215,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  2228,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    2229,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,     0,
     303,   304,   305,  2230,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,     0,   303,   304,   305,  2246,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,     0,   303,   304,   305,  2247,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,     0,   303,
     304,   305,  2248,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,     0,   303,   304,   305,  2252,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,     0,   303,   304,   305,  2253,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,     0,   303,   304,
     305,  2254,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
       0,   303,   304,   305,  2258,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,     0,   303,   304,   305,  2259,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,     0,   303,   304,   305,
    2260,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,   303,   304,
     305,   480,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,   303,
     304,   305,   604,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
     303,   304,   305,   661,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,   303,   304,   305,   663,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,   303,   304,   305,   665,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,   303,   304,   305,   667,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,   303,   304,   305,   669,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,   303,   304,   305,   671,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,   303,   304,   305,   673,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,   303,   304,   305,
     675,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,   303,   304,
     305,   677,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,   303,
     304,   305,   679,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
     303,   304,   305,   681,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,   303,   304,   305,   685,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,   303,   304,   305,   687,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,   303,   304,   305,   689,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,   303,   304,   305,   691,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,   303,   304,   305,   693,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,   303,   304,   305,   695,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,   303,   304,   305,
     766,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,   303,   304,
     305,   768,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,   303,
     304,   305,   999,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
     303,   304,   305,  1001,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,   303,   304,   305,  1003,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,   303,   304,   305,  1005,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,   303,   304,   305,  1006,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,   303,   304,   305,  1144,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,   474,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,   504,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,   505,   303,   304,   305,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,   506,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,   508,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,   510,   303,   304,   305,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,   511,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,   523,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
     556,   303,   304,   305,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,   557,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,   560,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,   566,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,   660,   303,   304,   305,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,   662,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,   664,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,   666,   303,   304,   305,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,   668,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,   670,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
     672,   303,   304,   305,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,   674,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,   676,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,   678,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,   680,   303,   304,   305,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,   684,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,   686,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,   688,   303,   304,   305,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,   690,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,   692,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
     694,   303,   304,   305,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,   727,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,   729,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,   745,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,   746,   303,   304,   305,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,   747,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,   751,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,   752,   303,   304,   305,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,   753,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,   754,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
     755,   303,   304,   305,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,   774,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,   781,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,   885,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,   998,   303,   304,   305,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,  1000,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,  1002,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,  1004,   303,   304,   305,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,  1067,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,  1171,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
    1196,   303,   304,   305,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,  1299,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,  1303,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,  1305,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,  1423,   303,   304,   305,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,  1452,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,  1454,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,  1456,   303,   304,   305,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,  1458,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,  1459,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
    1460,   303,   304,   305,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,  1482,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,  1587,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,  1742,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,  1743,   303,   304,   305,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,  1744,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,  1906,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,  1907,   303,   304,   305,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,  1908,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,  2029,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
    2030,   303,   304,   305,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,  2031,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,  2032,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,  2033,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317,     0,  2034,   303,   304,   305,     0,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     0,     0,
       0,     0,     0,   317,     0,  2144,   303,   304,   305,     0,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     0,     0,     0,     0,     0,   317,     0,  2145,   303,
     304,   305,     0,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,     0,     0,     0,     0,     0,   317,
       0,  2146,   303,   304,   305,     0,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,   317,     0,  2204,   303,   304,   305,     0,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
       0,     0,     0,     0,     0,   317,     0,  2205,   303,   304,
     305,     0,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     0,     0,     0,     0,     0,   317,     0,
    2206,   303,   304,   305,     0,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     0,     0,     0,     0,
       0,   317,     0,  2264,   303,   304,   305,     0,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     0,
       0,     0,     0,     0,   317,     0,  2265,   303,   304,   305,
       0,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     0,     0,     0,     0,     0,   317,     0,  2266,
     303,   304,   305,     0,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     0,     0,     0,     0,     0,
     317
};

static const short yycheck[] =
{
      25,    93,   719,    25,   360,   361,   331,   181,     4,     4,
       4,   185,     4,     4,   297,    65,     4,     7,   287,   288,
     289,     6,     3,     7,    42,  1277,    65,  1279,    65,  1186,
       4,     6,  1355,   195,     6,   197,  1359,     4,     6,  1362,
      66,   102,   195,    66,   197,    71,     4,     5,    71,    66,
       5,    85,   184,   185,    71,    66,  1085,    66,    66,    66,
      71,   165,    71,    71,    71,  1094,   184,   185,   200,   195,
     202,   195,  1101,   197,    49,   201,    34,    35,    36,    34,
      35,    36,   200,    66,   202,   192,   193,     0,    71,   174,
     175,   176,   199,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     7,   130,   131,   132,   195,   194,
     135,   136,   196,   138,   201,   200,   200,   202,    66,     6,
     145,   146,   147,    71,   149,   116,   151,   152,   295,   154,
      66,   105,   106,   196,   195,    71,  1293,   200,   105,   106,
     195,   184,   185,   184,   185,     7,   171,   172,     6,   184,
     185,   201,   869,   195,   195,   197,   195,   200,   195,   202,
     201,   196,   201,   196,   331,   190,   191,   200,   193,     7,
     195,   205,    38,   198,   199,    41,   202,   195,   503,   202,
     170,   171,   172,   173,     6,   202,   170,   171,   172,   173,
     515,   202,   196,   202,   202,   202,   200,   480,     6,   184,
     185,   195,   192,   193,   185,   201,   201,   381,     6,   201,
     201,     6,   481,   201,   196,   240,   184,   185,   200,   202,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,     6,     7,   196,  1294,   202,  1590,   200,  1298,
     295,  1594,   195,    38,  1597,   297,    41,    42,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,     3,  1546,     8,   195,  1549,   323,  1551,
     325,   195,  1019,   184,   185,   330,   331,   195,   170,   171,
     172,   173,   184,   185,    65,   340,   341,   342,   343,   200,
     345,   346,   347,   348,   349,   350,   351,   192,   193,   201,
     192,   193,   170,   171,   172,   173,   503,   199,   363,   364,
     365,   366,   184,   185,   369,   184,   185,   195,   515,   184,
     185,   195,   377,   197,   192,   193,   184,   185,   195,   201,
     197,   386,   201,   195,  1687,   200,   184,   185,  1691,   195,
    1693,   197,   200,    46,   184,   185,     6,    44,   184,   185,
     705,   195,   200,   184,   185,   184,   185,   184,   185,  1641,
     200,    56,    57,  1645,   200,  1647,    42,   184,   185,   200,
      42,   200,   424,   200,   186,   187,   188,   195,   733,   196,
       6,     7,   194,   738,   739,   740,   195,  1446,  1447,  1448,
    1449,   195,    42,   197,  1453,    55,   136,   137,   138,   139,
     140,   141,   142,   143,   195,    42,   197,   706,   176,   195,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   476,   201,    46,    47,   201,   194,   482,   480,    42,
       8,   174,   175,   176,     6,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    41,    42,   503,    44,
       6,   194,   184,   185,   186,   187,   188,   512,   513,   202,
     515,   195,   194,   192,   193,   195,   521,   522,   197,   195,
     199,   197,   195,   528,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   538,   539,   192,   193,     6,   194,   544,
     197,   195,   199,   197,     4,     4,   551,  1556,  1557,   192,
     193,  1560,     3,   195,   197,   197,   199,   562,   705,   564,
     565,    42,   709,  1260,   174,   175,   176,   195,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     6,
     195,   195,   887,   197,   194,     5,   733,   195,   195,   197,
     197,   738,   739,   740,   195,   168,   197,   170,   861,   862,
     195,   195,   604,   176,     6,    38,     3,     4,    41,    42,
       6,    44,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   121,   122,   123,   124,
     125,    38,  1651,   195,     5,   197,   174,   175,   176,   195,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   195,    59,    60,    61,    62,   194,    64,   196,   195,
     243,   197,   195,     6,   197,   195,   201,   682,   683,    59,
      60,    61,    62,   195,    64,   197,   195,   197,   197,   199,
     195,   696,   697,   698,   699,   700,   701,   702,     6,   200,
     705,   202,   195,   200,   709,   202,   200,   712,   202,   200,
     200,   202,   202,   200,     4,   202,   721,   200,   195,   202,
    1056,   200,   200,   202,   202,   200,   197,   202,   733,   201,
     735,  1740,   197,   738,   739,   740,   200,   200,   202,   202,
     887,   195,   200,   815,   202,   201,   195,   174,   175,   176,
     195,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,  1011,   195,   769,   770,   201,   194,   773,     6,
     200,   200,   202,   202,   200,   200,   202,   202,   201,   784,
     785,   200,   200,   202,   202,   358,   359,   184,   185,   200,
       6,   202,  1801,   190,   200,   200,   202,   202,   195,   200,
     200,   202,   202,  1052,   201,   200,   200,   202,   202,   200,
     200,   202,   202,   201,   819,   820,   821,   822,   823,   824,
     825,   826,   827,   828,   829,   830,   831,   832,   833,   834,
     835,   836,   837,   838,   839,   840,   841,   842,   843,   844,
       6,   174,   175,   176,   199,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   200,   200,   202,   202,
     862,   194,   200,   108,   202,   870,   174,   175,   176,   201,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   200,   887,   202,     6,   195,   194,   892,   200,   894,
     202,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   195,     5,   909,   910,   911,   194,   200,   200,
     202,   202,   200,   195,   202,   200,   195,   202,   932,   195,
     195,   195,   927,   928,   929,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,  1271,   195,   174,   175,   176,
     195,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   195,   195,   195,   195,   195,   194,   196,   195,
     195,   195,   195,   195,   537,   195,     6,   195,   970,   200,
       4,     3,     4,   200,   194,  1984,     7,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   199,     7,   195,     7,     7,   196,  1012,   174,   175,
     176,     7,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     7,   103,   105,     6,   201,   194,   166,
       5,     5,     5,     5,     5,  1107,  1041,  1042,  1043,     5,
       5,     5,     5,     5,     5,     5,     5,  1052,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,  1063,  1064,
     154,     5,  1076,     5,     5,     5,     3,     5,   200,     5,
    1075,     6,     5,  1078,     6,   196,     4,     6,   202,   199,
       7,     7,     7,  1088,     7,     7,     7,     7,   202,   201,
    1095,  1096,  1097,   201,     7,     7,   195,  1102,     7,   199,
     167,  1106,   200,   200,   200,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,   200,   200,     5,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,  1154,
     200,   724,   184,   185,   194,   200,   200,   200,   190,   200,
       6,   200,   200,   195,   200,   200,   198,  1172,     4,   201,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,  1198,   200,   196,  1192,   200,  1194,
     763,   764,   765,     6,   174,   175,   176,   195,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   195,
     195,   198,   195,   786,   194,     6,   195,     3,     4,   195,
       7,     6,   795,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     6,   195,   195,
     195,     6,   195,     7,     7,     7,   195,     7,     7,     7,
       7,  1266,     7,   197,   195,   195,     7,     7,     7,  1274,
       7,  1276,     7,  1278,     4,  1280,  1281,   195,   195,   195,
     195,   195,  1287,     6,   195,   195,     6,   195,   195,   195,
     195,  1296,   195,   195,     7,     4,     7,   201,   163,  1304,
       3,     3,     3,   186,  1309,     3,     3,  1312,     3,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,  1337,  1338,  1339,     3,     3,  1586,     3,     3,
       3,  1346,     3,  1348,  1349,  1350,     3,     3,     6,   196,
       5,     5,     3,     3,     4,     3,   196,     6,  1372,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   174,   175,   176,     4,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   184,   185,
     199,     7,     6,   194,   190,     6,     6,     6,     6,   195,
       6,   195,   198,   201,     6,   201,   104,   196,   201,   200,
     200,   196,   200,  1428,   200,   196,   200,   200,   200,  1434,
     196,  1445,  1437,  1682,   196,  1684,   200,   200,     6,   200,
     200,     6,   200,   200,   200,     6,     4,     6,     3,   200,
     196,  1024,   196,     6,     6,   198,  1461,  1462,  1463,  1464,
    1465,  1466,  1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,
    1475,  1476,  1477,  1478,  1479,  1480,  1481,   199,  1483,   200,
       6,   200,   200,   200,  1057,   200,  1059,     6,  1061,     6,
       6,  1505,     6,   174,   175,   176,     6,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     6,     6,
       6,     6,     6,   194,  1763,   196,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     6,     6,     6,   184,   185,   194,     7,     6,     6,
     190,   104,     6,     3,     6,   195,   186,     6,   198,     6,
       3,   201,     6,     3,     6,     6,     3,  1562,  1563,  1564,
    1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,     6,     3,     3,     4,     3,     3,     6,  1602,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   174,   175,   176,     4,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     6,     6,
     199,     7,     6,   194,   198,     6,  1650,     6,   101,   201,
     106,   163,   202,   200,  1649,   201,   196,   201,   104,   200,
    1655,     6,  1657,   201,  1659,   201,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1680,  1681,   200,   196,   200,
     200,   196,  1696,   196,   153,   196,     3,   196,   200,   196,
     159,   196,   200,     6,   200,     6,     3,     6,     6,   202,
       6,  1274,     6,  1276,     6,  1278,     6,     8,     3,     6,
       6,     5,     5,   182,     6,   201,   201,   200,   202,   188,
     189,   200,   200,   200,   196,   196,     6,     6,     6,     6,
       6,     6,  1737,  1738,     6,   200,     6,     6,   196,   200,
    1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,
    1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,   200,     6,
       6,     6,     6,     6,   184,   185,     6,     5,     5,   201,
     190,   200,   202,   201,   201,   195,  1349,   200,   200,     6,
       6,   201,   196,   196,   200,   200,     6,     6,   200,   101,
     201,     8,  1797,   201,   201,   201,   200,  1802,  1803,  1804,
    1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,
    1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,   163,   174,
     175,   176,     6,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     6,     5,     5,     8,   201,   194,
     201,   201,   200,   202,   201,   196,   200,   196,   201,  1854,
     202,  1856,     6,  1858,     6,  1860,  1861,  1862,  1863,  1864,
    1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,  1874,
    1875,  1876,  1877,   174,   175,   176,     6,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     6,   101,
       6,     6,     6,   194,     6,     6,     6,     6,     6,   202,
       6,     6,   201,     6,  1909,  1910,  1911,  1912,  1913,  1914,
    1915,  1916,  1917,  1918,  1919,  1920,  1921,  1922,  1923,   200,
     168,     6,     6,     6,     6,     6,   200,   169,   201,   200,
       6,   196,   200,     6,   201,   201,   200,   200,   200,  1944,
    1945,  1946,  1947,  1948,  1949,  1950,  1951,  1952,  1953,  1954,
    1955,  1956,  1957,  1958,  1959,  1960,  1961,   174,   175,   176,
     201,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   201,   201,     6,   200,     6,   194,     6,     6,
    1985,   196,  1987,   201,  1989,   201,  1991,  1992,  1993,  1994,
    1995,  1996,  1997,  1998,  1999,  2000,  2001,  2002,  2003,  2004,
    2005,   201,   201,   174,   175,   176,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   201,   201,
       6,     6,     6,   194,     6,     6,     6,   201,   201,     6,
    2035,  2036,  2037,  2038,  2039,  2040,  2041,  2042,  2043,   201,
       6,     6,   201,   201,   201,     6,     6,     6,   201,     6,
     201,   201,     6,     6,    -1,  2060,  2061,  2062,  2063,  2064,
    2065,  2066,  2067,  2068,  2069,  2070,  2071,  2072,  2073,  2074,
      38,    39,    40,    41,    42,    43,    44,    45,   606,    47,
       8,    49,    50,    51,     8,    53,    54,     8,  1069,    -1,
      -1,  2096,    -1,  2098,    -1,  2100,  1015,  2102,    -1,  2104,
      -1,  2106,    70,  2108,  2109,  2110,  2111,  2112,  2113,  2114,
    2115,  2116,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,   100,  2138,  2139,  2140,  2141,  2142,  2143,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2177,  2178,  2179,  2180,  2181,  2182,  2183,    -1,
    2185,    -1,  2187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2201,  2202,  2203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2213,  2214,
    2215,  2216,  2217,  2218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2228,  2229,  2230,  2231,    -1,  2233,    -1,
    2235,    -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,
      -1,  2246,  2247,  2248,    -1,    -1,    -1,  2252,  2253,  2254,
      -1,    -1,    -1,  2258,  2259,  2260,   725,   726,    -1,   728,
      -1,   730,   731,    -1,    -1,  2270,  2271,  2272,    -1,    -1,
      -1,    -1,    -1,    -1,  2279,    -1,  2281,    -1,  2283,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   771,   772,    -1,    -1,   775,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,   792,   793,    -1,    -1,   194,    -1,   798,
     799,    -1,    -1,     3,     4,    -1,   805,    -1,   807,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     879,    -1,   881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   895,   896,   897,    -1,
      -1,    -1,   901,   902,   903,   904,   905,   906,   907,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    35,    36,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,   184,   185,    -1,    -1,    -1,    -1,
     190,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,
      -1,   201,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,  1010,    -1,    -1,    -1,    -1,   184,   185,    -1,    -1,
      -1,    -1,   190,    -1,   192,   193,    -1,   195,    -1,   197,
      -1,   199,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1079,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   185,    -1,    -1,    -1,    -1,   190,    -1,    -1,  1098,
      -1,   195,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    47,    -1,    49,    50,    51,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,   184,   185,    -1,    -1,    -1,    -1,
     190,     3,     4,    -1,    70,   195,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    98,    99,   100,    41,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    47,    -1,    49,    50,
      51,   117,    53,    54,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    70,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
     200,    -1,   202,   184,   185,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,    -1,   117,    -1,    -1,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,   160,  1284,    -1,  1286,    -1,    -1,
      -1,  1290,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,  1306,    -1,    -1,
      -1,    -1,   184,   185,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    33,
      -1,   202,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    98,    99,   100,    -1,    -1,    -1,
      -1,   105,    -1,   107,    -1,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    47,  1423,    49,    50,    51,    -1,    53,
      54,  1430,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,  1441,  1442,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1485,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,   202,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     4,    -1,    -1,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,  1548,
      -1,    -1,    -1,    33,  1553,   202,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    98,    99,
     100,   200,    -1,   202,    -1,   105,    -1,   107,   202,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,    -1,  1642,    -1,    -1,    -1,    -1,    -1,    -1,
     174,   175,   176,  1652,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   174,   175,   176,   202,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     174,   175,   176,   202,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   174,   175,   176,   202,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,  1741,    -1,    -1,   194,    -1,    -1,    -1,    -1,
     174,   175,   176,   202,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,   174,   175,   176,   202,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,  1800,    -1,   202,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   174,
     175,   176,   202,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,  1852,   174,   175,   176,   202,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,   174,
     175,   176,   202,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,    -1,    -1,  1905,   202,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,
      -1,   174,   175,   176,  1943,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   174,   175,   176,   202,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   174,   175,   176,   202,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   174,   175,   176,   202,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   174,   175,   176,   202,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,   174,   175,   176,   202,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,   174,   175,   176,   202,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
     174,   175,   176,   200,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,   174,   175,   176,   200,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,
     175,   176,   200,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,   174,   175,   176,   200,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,   174,   175,   176,   200,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,
     176,   200,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
      -1,   174,   175,   176,   200,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,   174,   175,   176,   200,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,   174,   175,   176,
     200,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,   174,   175,
     176,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,   174,
     175,   176,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
     174,   175,   176,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,   174,   175,   176,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,   174,   175,   176,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,   174,   175,   176,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,   174,   175,   176,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,   174,   175,   176,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,   174,   175,   176,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,   174,   175,   176,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,   174,   175,
     176,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,   174,
     175,   176,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
     174,   175,   176,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,   174,   175,   176,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,   174,   175,   176,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,   174,   175,   176,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,   174,   175,   176,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,   174,   175,   176,   198,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,   174,   175,   176,   198,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,   174,   175,   176,
     198,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,   174,   175,
     176,   198,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,   174,
     175,   176,   198,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
     174,   175,   176,   198,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,   174,   175,   176,   198,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,   174,   175,   176,   198,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,   174,   175,   176,   198,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,   174,   175,   176,   198,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   174,   175,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   174,   175,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   174,   175,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   174,   175,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   174,   175,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   174,   175,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   174,   175,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   174,   175,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   174,   175,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   174,   175,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   174,   175,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   174,   175,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   174,   175,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   174,   175,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,   174,   175,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,    -1,    -1,
      -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,
     175,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,
      -1,   196,   174,   175,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,   194,    -1,   196,   174,   175,   176,    -1,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,
     196,   174,   175,   176,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,
      -1,   194,    -1,   196,   174,   175,   176,    -1,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,    -1,
      -1,    -1,    -1,    -1,   194,    -1,   196,   174,   175,   176,
      -1,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,    -1,    -1,    -1,    -1,    -1,   194,    -1,   196,
     174,   175,   176,    -1,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,    -1,    -1,    -1,    -1,    -1,
     194
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,   161,   162,   164,   204,   206,   207,   212,     6,
     165,     0,     3,   136,   137,   138,   139,   140,   141,   142,
     143,   208,   209,   210,   211,     4,    33,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    47,    48,    49,    50,
      51,    52,    53,    54,    58,    59,    60,    61,    62,    63,
      64,    66,    67,    68,    69,    70,    98,    99,   100,   105,
     107,   109,   110,   111,   112,   113,   114,   115,   117,   213,
     214,   215,   297,   298,   299,   302,   303,   304,   305,   306,
     307,   319,   320,     3,   185,   205,     7,     6,     6,     6,
       6,     6,   195,   195,   195,     3,     4,     5,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    34,    35,    36,   170,   171,   172,   173,
     184,   185,   190,   192,   193,   195,   197,   199,   295,   296,
     322,   323,   336,   195,     6,   195,   195,   195,    65,   195,
      65,   195,   195,    46,   195,    42,    42,    42,    42,    41,
      42,    44,    44,    38,    41,    42,    44,   195,   201,   184,
     185,   195,   201,   324,   325,   324,   201,    38,    41,    42,
       4,   201,    42,     4,   116,   201,     6,     6,    38,    41,
     195,   195,    42,   195,     4,   201,   333,     4,   195,   195,
       6,     4,     4,    42,     3,   205,    41,   118,   119,   120,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     155,   156,   157,   158,   159,   160,   195,   326,   326,     5,
     197,   199,   296,     4,   201,   195,   197,   195,   197,   195,
     197,   195,   197,   195,   197,   195,   197,   195,   197,   195,
     197,   195,   197,   195,   197,   195,   197,   195,   197,   195,
     197,   195,   197,   195,   197,   195,   197,   195,   197,   195,
     197,   195,   197,   195,   197,   195,   197,   195,   195,   195,
     322,   322,   322,   322,   198,   201,   322,     4,   105,   106,
     322,     6,     6,   174,   175,   176,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   194,     6,     5,
     322,   322,   322,   195,   322,   195,   322,   322,     4,    38,
     185,   201,   299,   300,   301,   302,   322,   330,   331,   322,
     201,   195,   195,   195,   330,   201,   201,   195,   195,   195,
     195,   195,     4,   324,   324,   324,   322,   322,   184,   185,
     201,   201,   324,   201,   201,   201,   197,   301,   330,   197,
       6,   301,   330,   330,   322,   322,   102,   195,   322,   199,
     322,   201,   108,   322,   322,     6,   195,   205,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,     5,   327,
     200,   196,   200,   322,     4,   324,   216,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,     4,
       5,   336,   336,   336,   196,     7,   185,   322,   331,   332,
     198,     7,   295,   296,   199,     7,     6,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   196,   200,   196,   196,   196,   322,   196,   322,
     196,   196,   197,   195,     4,   201,   332,    38,    41,    42,
     298,     8,     7,   196,   322,   322,   322,   322,     7,   322,
     322,   322,   322,   322,   322,   322,   196,   200,   200,   200,
     324,   324,   300,   300,   200,   322,   322,   322,   322,   202,
       6,     7,   322,   202,     7,     7,   196,   196,   103,   322,
     196,   105,   200,   301,   201,     8,   196,   322,   166,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,   154,     5,     5,     5,     5,     3,     5,   196,
     200,     5,     6,     5,   198,   296,   201,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,   202,   218,   221,   224,   227,   230,   233,
     236,   239,   242,   245,   248,   251,   254,   257,   260,   263,
     266,   269,   272,   275,   278,   281,   284,   287,   290,   293,
     196,   198,   196,   198,   196,   198,   196,   198,   196,   198,
     196,   198,   196,   198,   196,   198,   196,   198,   196,   198,
     196,   198,   200,   200,   196,   198,   196,   198,   196,   198,
     196,   198,   196,   198,   196,   198,   200,   200,   200,   200,
     200,   200,   197,   199,   196,   200,   200,   196,   330,   200,
     202,   199,   295,   296,   336,   322,     6,     4,     4,   201,
     334,     8,     6,   332,     7,     7,     7,   196,     7,   196,
       7,     7,   198,   201,   322,   197,   332,   202,   201,   201,
     201,   322,   322,     7,   202,   196,   196,   196,   322,   202,
     202,   196,   196,   196,   196,   196,   199,   324,   322,   322,
     202,   202,   322,   200,   200,   200,   198,   322,   198,   201,
     201,     7,     7,   195,   196,     7,   199,   322,   202,   322,
     322,   196,   167,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,     5,   196,   200,   199,   296,   216,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,     6,   322,   322,   322,   322,
     322,   322,   322,   322,   322,     4,   332,   336,     6,   322,
     331,   198,     4,   105,   106,   322,     6,     6,     6,     7,
     197,   333,   335,     6,   322,   196,   324,   330,   330,     7,
     330,     7,   330,   330,   332,   196,   198,   201,   202,   332,
     332,   332,     8,     6,   201,     7,     7,     7,     7,     6,
      55,     7,     7,     7,     7,     7,     7,     7,     4,   200,
     200,   200,   202,   324,   324,   324,     6,     6,     6,   322,
     322,   330,   330,   322,     7,   330,     4,   200,     8,     8,
     196,     7,   163,     3,   322,   322,   324,     3,     3,   186,
       3,     3,   330,   330,     3,   324,     3,     3,   330,   330,
       3,     3,     3,     3,     3,   330,   121,   122,   123,   124,
     125,   321,   330,     3,     5,     5,     3,     3,     6,   326,
       4,   202,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   196,   198,
     196,   198,   196,   198,   196,   198,   198,   196,   196,   196,
     295,     7,   295,   296,   199,     7,     6,   333,   322,   200,
     202,     6,     6,     6,    49,     6,   330,     6,   330,     6,
       6,   202,   332,   202,   202,   202,   322,   322,   330,   330,
     330,   195,    56,    57,   330,   330,   330,   330,   330,   330,
     330,     6,     7,   322,   322,   322,   201,   200,   202,   200,
     202,   200,   202,   200,   200,     6,     6,   196,   195,   201,
     328,   104,   322,   322,   322,   201,   205,   200,   200,   200,
     196,   200,   196,   200,   196,   200,   196,   200,   200,   196,
     200,   196,   196,   200,   200,   200,   200,   200,   200,   196,
     200,   200,   200,   200,   200,   196,   200,   200,   296,     6,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   199,   330,   336,   322,
       6,     4,   334,     6,   198,   333,   324,     6,     6,   198,
     202,     6,     6,     6,   200,     6,     6,     6,   322,   322,
     322,     6,     6,     6,     6,     6,     6,     6,   322,   336,
     202,   196,   200,   202,   300,   324,     6,   308,   324,     6,
     311,   324,     6,   314,   322,   322,     7,   329,   330,   329,
     104,   330,   200,   202,     8,   202,   196,   322,   205,     3,
     322,   330,     6,     3,     6,   186,     6,   321,     6,     3,
     322,     6,     3,     6,     6,     3,   321,   322,   322,   322,
     330,     6,     3,   321,   322,     3,     3,     6,   322,   326,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,     4,     6,     6,     6,
       7,     6,   199,     6,   198,   322,   200,     6,     6,     6,
       6,   201,   322,   202,   200,   201,   200,   201,   200,   201,
     200,   200,   328,   196,   200,   202,   201,   101,   322,   322,
     200,   205,   196,   200,   200,   200,   200,   196,   200,   196,
     200,   196,   196,   196,   200,   196,   200,   196,   196,   200,
     200,   196,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     196,   333,   106,   200,   322,   300,   200,   202,   184,   185,
     195,   322,   324,    66,    71,   317,   318,   322,   324,   317,
     322,   324,   317,   322,   322,   104,   330,   330,   322,   202,
     202,   330,   163,     6,   328,   321,     3,   322,     6,   321,
       6,     3,     6,     6,     6,   322,     6,   330,     6,     6,
     322,     3,     6,   322,     5,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,     6,     5,   196,   202,   322,   322,   202,   200,     6,
     201,   202,   318,   202,   200,   202,   202,   200,   202,   202,
     202,   201,   200,     6,   202,   205,   200,   200,   200,   200,
     196,   196,   196,   200,   196,   196,   196,   200,   196,   196,
     196,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   196,   200,   200,   330,   202,     6,   309,   322,
     330,     6,     6,   312,   322,     6,     6,   315,   322,     6,
       6,     6,   330,   330,     6,   205,   321,   321,   321,   321,
       6,     6,     6,   321,     6,     6,     6,     5,   219,   222,
     225,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   291,   322,     5,   330,   201,   202,   200,   201,
     202,   201,   202,   200,   202,   205,   200,   200,   196,   196,
     200,   200,   201,   201,   201,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   201,   196,   200,     6,
     317,     6,   310,   330,   317,     6,   313,   317,     6,   316,
     330,   101,   163,   321,   321,     6,     6,   321,     5,   217,
     322,   220,   322,   223,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   289,   336,   294,     5,
     202,   201,   200,   202,   202,   201,   202,   201,   202,   201,
     205,   200,   200,   196,   196,   200,   202,   200,   202,   200,
     202,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   202,   201,   202,     6,   317,   330,     6,
       6,   317,     6,   317,   101,   322,   205,   321,   330,     6,
       6,   322,     6,   322,     6,   322,     6,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   336,     6,
     292,   336,     6,   202,   202,   202,   202,   201,   200,   205,
     200,   200,   196,   196,   196,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   202,     6,     6,     6,     6,   322,
     322,   168,   321,   330,   228,   231,   234,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   336,     6,   200,   202,   169,
     200,   200,   201,   201,   201,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   322,     6,   330,   321,   226,   322,   229,
     322,   232,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   202,   200,   196,   200,   202,   200,   202,   200,   202,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,     6,   330,
       6,   322,     6,   322,     6,   322,     6,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   200,   196,   196,   196,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   330,   237,   240,   243,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   200,   201,   201,   201,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   330,   235,   322,   238,   322,   241,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   200,   200,   202,   200,   202,   200,
     202,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   321,   322,     6,   322,
       6,   322,     6,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   196,   196,
     196,   196,   196,   196,   196,   200,   200,   200,   200,   200,
     200,   200,   200,   200,     6,   246,   249,   252,   255,   258,
     261,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     201,   201,   201,   201,   201,   201,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   244,   322,   247,   322,   250,
     322,   253,   322,   256,   322,   259,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   200,   202,   200,   202,
     200,   202,   200,   202,   200,   202,   200,   202,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   322,     6,   322,
       6,   322,     6,   322,     6,   322,     6,   322,     6,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   200,   200,
     200,   200,   200,   200,   196,   196,   196,   322,   322,   322,
     322,   322,   322,   282,   285,   288,   200,   200,   200,   200,
     200,   200,   201,   201,   201,   322,   322,   322,   322,   322,
     322,   280,   322,   283,   322,   286,   322,   200,   200,   200,
     200,   200,   200,   200,   202,   200,   202,   200,   202,   322,
     322,   322,   322,   322,   322,   322,     6,   322,     6,   322,
       6,   200,   200,   200,   196,   196,   196,   322,   322,   322,
     273,   276,   279,   200,   200,   200,   201,   201,   201,   322,
     322,   322,   271,   322,   274,   322,   277,   322,   200,   200,
     200,   200,   202,   200,   202,   200,   202,   322,   322,   322,
     322,     6,   322,     6,   322,     6,   200,   200,   200,   322,
     322,   322,   200,   200,   200,   322,   322,   322,   200,   200,
     200,   322,   322,   322,   196,   196,   196,   264,   267,   270,
     201,   201,   201,   262,   322,   265,   322,   268,   322,   200,
     202,   200,   202,   200,   202,   322,     6,   322,     6,   322,
       6
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
#define YYEMPTY		-2
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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)           \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#define YYLEX	yylex ()

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
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
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
/*-----------------------------.
| Print this symbol on YYOUT.  |
`-----------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue)
#else
yysymprint (yyout, yytype, yyvalue)
    FILE* yyout;
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyout, yytoknum[yytype], yyvalue);
# endif
    }
  else
    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyout, ")");
}
#endif /* YYDEBUG. */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yydestruct (int yytype, YYSTYPE yyvalue)
#else
yydestruct (yytype, yyvalue)
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  switch (yytype)
    {
      default:
        break;
    }
}



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of parse errors so far.  */
int yynerrs;


int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

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

  if (yyssp >= yyss + yystacksize - 1)
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
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
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

      if (yyssp >= yyss + yystacksize - 1)
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

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with.  */

  if (yychar <= 0)		/* This means end of input.  */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more.  */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

      /* We have to keep this `#if YYDEBUG', since we use variables
	 which are defined only if `YYDEBUG' is set.  */
      YYDPRINTF ((stderr, "Next token is "));
      YYDSYMPRINT ((stderr, yychar1, yylval));
      YYDPRINTF ((stderr, "\n"));
    }

  /* If the proper action on seeing token YYCHAR1 is to reduce or to
     detect an error, take that action.  */
  yyn += yychar1;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
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
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

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



#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn - 1, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif
  switch (yyn)
    {
        case 5:
#line 174 "Gmsh.y"
    { yyerrok ; return 1; }
    break;

  case 6:
#line 180 "Gmsh.y"
    { yyval.d = yyvsp[0].d; }
    break;

  case 7:
#line 181 "Gmsh.y"
    { yyval.d = -yyvsp[0].d; }
    break;

  case 8:
#line 186 "Gmsh.y"
    {
      yymsg(INFO, "STL file format");
      STL_Surf = Create_Surface(1,MSH_SURF_STL);
      STL_Surf->STL = new STL_Data;
      return 1;
    }
    break;

  case 9:
#line 200 "Gmsh.y"
    {
      STL_Surf->STL->Add_Facet( yyvsp[-12].d, yyvsp[-11].d, yyvsp[-10].d,
				yyvsp[-8].d, yyvsp[-7].d, yyvsp[-6].d,
				yyvsp[-4].d, yyvsp[-3].d, yyvsp[-2].d);
      return 1;
    }
    break;

  case 10:
#line 207 "Gmsh.y"
    {
      yymsg(INFO, "STL file format read");
      Tree_Add(THEM->Surfaces, &STL_Surf);
      return 1;
    }
    break;

  case 13:
#line 222 "Gmsh.y"
    { return 1; }
    break;

  case 14:
#line 223 "Gmsh.y"
    { return 1; }
    break;

  case 15:
#line 224 "Gmsh.y"
    { return 1; }
    break;

  case 16:
#line 229 "Gmsh.y"
    {
      yymsg(INFO, "Step Iso-10303-21 file format");
      Create_Step_Solid_BRep();
    }
    break;

  case 17:
#line 234 "Gmsh.y"
    {
      yymsg(INFO, "Step Iso-10303-21 file format read");
      Resolve_BREP ();
    }
    break;

  case 21:
#line 245 "Gmsh.y"
    {
    }
    break;

  case 22:
#line 248 "Gmsh.y"
    {
    }
    break;

  case 23:
#line 252 "Gmsh.y"
    {
   }
    break;

  case 24:
#line 258 "Gmsh.y"
    {
        Add_Cartesian_Point((int)yyvsp[-8].d,yyvsp[-4].c,yyvsp[-2].v[0],yyvsp[-2].v[1],yyvsp[-2].v[2]);
    }
    break;

  case 25:
#line 264 "Gmsh.y"
    {
       Add_BSpline_Curve_With_Knots ((int)yyvsp[-22].d, yyvsp[-18].c, (int) yyvsp[-16].d, yyvsp[-14].l,	yyvsp[-6].l, yyvsp[-4].l, 0., 1.);
    }
    break;

  case 26:
#line 271 "Gmsh.y"
    {
      Add_BSpline_Surface_With_Knots ((int)yyvsp[-30].d, yyvsp[-26].c, (int) yyvsp[-24].d, (int) yyvsp[-22].d, yyvsp[-20].l, yyvsp[-10].l,
				      yyvsp[-8].l, yyvsp[-6].l, yyvsp[-4].l, 0., 1., 0., 1. );
    }
    break;

  case 27:
#line 277 "Gmsh.y"
    {
      Add_Edge_Curve ((int)yyvsp[-14].d, yyvsp[-10].c , (int)yyvsp[-8].d , (int)yyvsp[-6].d, (int)yyvsp[-4].d);
    }
    break;

  case 28:
#line 281 "Gmsh.y"
    {
      Add_Face_Outer_Bound((int)yyvsp[-10].d,yyvsp[-6].c,(int)yyvsp[-4].d,yyvsp[-2].i,1);
    }
    break;

  case 29:
#line 285 "Gmsh.y"
    {
      // check the norm! Face_Bound : hole outside surface!
      yymsg(INFO, "Found a face bound");
      Add_Face_Outer_Bound((int)yyvsp[-10].d,yyvsp[-6].c,(int)yyvsp[-4].d,yyvsp[-2].i,0);
    }
    break;

  case 30:
#line 292 "Gmsh.y"
    {
      Add_Oriented_Edge((int)yyvsp[-14].d,yyvsp[-10].c,(int)yyvsp[-4].d,yyvsp[-2].i);
    }
    break;

  case 31:
#line 296 "Gmsh.y"
    {
      Add_Edge_Loop((int)yyvsp[-8].d,yyvsp[-4].c,yyvsp[-2].l);
    }
    break;

  case 32:
#line 301 "Gmsh.y"
    {
      Add_Advanced_Face((int)yyvsp[-12].d,yyvsp[-8].c,yyvsp[-6].l,(int)yyvsp[-4].d,yyvsp[-2].i);
    }
    break;

  case 33:
#line 305 "Gmsh.y"
    {
      Add_Vertex_Point((int)yyvsp[-8].d,yyvsp[-4].c,(int)yyvsp[-2].d);
    }
    break;

  case 34:
#line 309 "Gmsh.y"
    {
    }
    break;

  case 35:
#line 313 "Gmsh.y"
    {
      Add_Axis2_Placement3D  ( (int)yyvsp[-12].d, (int)yyvsp[-4].d, (int)yyvsp[-2].d, (int)yyvsp[-6].d);
    }
    break;

  case 36:
#line 317 "Gmsh.y"
    {
      Add_Direction((int)yyvsp[-8].d , yyvsp[-4].c, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2]);
    }
    break;

  case 37:
#line 321 "Gmsh.y"
    {
      Add_Plane((int)yyvsp[-8].d,yyvsp[-4].c,(int)yyvsp[-2].d);
    }
    break;

  case 38:
#line 325 "Gmsh.y"
    {
      Add_Line ((int)yyvsp[-10].d, yyvsp[-6].c , (int) yyvsp[-4].d, (int)yyvsp[-2].d);
    }
    break;

  case 39:
#line 329 "Gmsh.y"
    {
      yymsg(INFO, "Found a closed shell");
      Add_Closed_Shell((int)yyvsp[-8].d, yyvsp[-4].c , yyvsp[-2].l);
    }
    break;

  case 40:
#line 335 "Gmsh.y"
    {
    }
    break;

  case 41:
#line 338 "Gmsh.y"
    {
    }
    break;

  case 42:
#line 341 "Gmsh.y"
    {
      Add_Cylinder ((int)yyvsp[-10].d, yyvsp[-6].c , (int)yyvsp[-4].d, yyvsp[-2].d);
    }
    break;

  case 43:
#line 345 "Gmsh.y"
    {
      Add_Cone ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d,yyvsp[-2].d);
    }
    break;

  case 44:
#line 349 "Gmsh.y"
    {
      Add_Torus ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d,yyvsp[-2].d);
    }
    break;

  case 45:
#line 353 "Gmsh.y"
    {
      Add_Circle((int) yyvsp[-10].d, yyvsp[-6].c, (int) yyvsp[-4].d, yyvsp[-2].d);
    }
    break;

  case 46:
#line 357 "Gmsh.y"
    {
      Add_Ellipse((int) yyvsp[-12].d, yyvsp[-8].c, (int) yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    }
    break;

  case 47:
#line 362 "Gmsh.y"
    {
    }
    break;

  case 48:
#line 365 "Gmsh.y"
    {
    }
    break;

  case 49:
#line 369 "Gmsh.y"
    {
    }
    break;

  case 50:
#line 372 "Gmsh.y"
    {
    }
    break;

  case 51:
#line 376 "Gmsh.y"
    {
    }
    break;

  case 52:
#line 379 "Gmsh.y"
    {
    }
    break;

  case 53:
#line 382 "Gmsh.y"
    {
    }
    break;

  case 54:
#line 390 "Gmsh.y"
    {
  }
    break;

  case 55:
#line 393 "Gmsh.y"
    {
    yymsg(INFO, "Gmsh file format read");
  }
    break;

  case 56:
#line 399 "Gmsh.y"
    { return 1; }
    break;

  case 57:
#line 400 "Gmsh.y"
    { return 1; }
    break;

  case 58:
#line 401 "Gmsh.y"
    { return 1; }
    break;

  case 59:
#line 402 "Gmsh.y"
    { return 1; }
    break;

  case 60:
#line 403 "Gmsh.y"
    { return 1; }
    break;

  case 61:
#line 404 "Gmsh.y"
    { return 1; }
    break;

  case 62:
#line 405 "Gmsh.y"
    { return 1; }
    break;

  case 63:
#line 406 "Gmsh.y"
    { return 1; }
    break;

  case 64:
#line 407 "Gmsh.y"
    { return 1; }
    break;

  case 65:
#line 408 "Gmsh.y"
    { return 1; }
    break;

  case 66:
#line 409 "Gmsh.y"
    { return 1; }
    break;

  case 67:
#line 410 "Gmsh.y"
    { return 1; }
    break;

  case 68:
#line 411 "Gmsh.y"
    { return 1; }
    break;

  case 69:
#line 416 "Gmsh.y"
    {
      Msg(DIRECT, yyvsp[-2].c);
    }
    break;

  case 70:
#line 420 "Gmsh.y"
    {
      i = PrintListOfDouble(yyvsp[-4].c,yyvsp[-2].l,tmpstring);
      if(i<0) 
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i>0)
	yymsg(GERROR, "Too many arguments (%d) in Printf", i);
      else
	Msg(DIRECT, tmpstring);
      List_Delete(yyvsp[-2].l);
    }
    break;

  case 71:
#line 436 "Gmsh.y"
    { 
      if(!strcmp(yyvsp[-5].c, "View")) EndView(View, 1, yyname, yyvsp[-4].c); 
    }
    break;

  case 72:
#line 440 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-7].c, "View")) EndView(View, 1, yyname, yyvsp[-6].c);
    }
    break;

  case 73:
#line 447 "Gmsh.y"
    {
      View = BeginView(1); 
    }
    break;

  case 100:
#line 480 "Gmsh.y"
    { List_Add(View->SP, &yyvsp[0].d) ; }
    break;

  case 101:
#line 482 "Gmsh.y"
    { List_Add(View->SP, &yyvsp[0].d) ; }
    break;

  case 102:
#line 487 "Gmsh.y"
    { 
      List_Add(View->SP, &yyvsp[-5].d); List_Add(View->SP, &yyvsp[-3].d);
      List_Add(View->SP, &yyvsp[-1].d);
    }
    break;

  case 103:
#line 492 "Gmsh.y"
    {
      View->NbSP++ ;
    }
    break;

  case 104:
#line 499 "Gmsh.y"
    { List_Add(View->VP, &yyvsp[0].d) ; }
    break;

  case 105:
#line 501 "Gmsh.y"
    { List_Add(View->VP, &yyvsp[0].d) ; }
    break;

  case 106:
#line 506 "Gmsh.y"
    { 
      List_Add(View->VP, &yyvsp[-5].d); List_Add(View->VP, &yyvsp[-3].d);
      List_Add(View->VP, &yyvsp[-1].d); 
    }
    break;

  case 107:
#line 511 "Gmsh.y"
    {
      View->NbVP++ ;
    }
    break;

  case 108:
#line 518 "Gmsh.y"
    { List_Add(View->TP, &yyvsp[0].d) ; }
    break;

  case 109:
#line 520 "Gmsh.y"
    { List_Add(View->TP, &yyvsp[0].d) ; }
    break;

  case 110:
#line 525 "Gmsh.y"
    { 
      List_Add(View->TP, &yyvsp[-5].d); List_Add(View->TP, &yyvsp[-3].d);
      List_Add(View->TP, &yyvsp[-1].d);
    }
    break;

  case 111:
#line 530 "Gmsh.y"
    {
      View->NbTP++ ;
    }
    break;

  case 112:
#line 537 "Gmsh.y"
    { List_Add(View->SL, &yyvsp[0].d) ; }
    break;

  case 113:
#line 539 "Gmsh.y"
    { List_Add(View->SL, &yyvsp[0].d) ; }
    break;

  case 114:
#line 545 "Gmsh.y"
    { 
      List_Add(View->SL, &yyvsp[-11].d); List_Add(View->SL, &yyvsp[-5].d);
      List_Add(View->SL, &yyvsp[-9].d); List_Add(View->SL, &yyvsp[-3].d);
      List_Add(View->SL, &yyvsp[-7].d); List_Add(View->SL, &yyvsp[-1].d);
    }
    break;

  case 115:
#line 551 "Gmsh.y"
    {
      View->NbSL++ ;
    }
    break;

  case 116:
#line 558 "Gmsh.y"
    { List_Add(View->VL, &yyvsp[0].d) ; }
    break;

  case 117:
#line 560 "Gmsh.y"
    { List_Add(View->VL, &yyvsp[0].d) ; }
    break;

  case 118:
#line 566 "Gmsh.y"
    { 
      List_Add(View->VL, &yyvsp[-11].d); List_Add(View->VL, &yyvsp[-5].d);
      List_Add(View->VL, &yyvsp[-9].d); List_Add(View->VL, &yyvsp[-3].d);
      List_Add(View->VL, &yyvsp[-7].d); List_Add(View->VL, &yyvsp[-1].d);
    }
    break;

  case 119:
#line 572 "Gmsh.y"
    {
      View->NbVL++ ;
    }
    break;

  case 120:
#line 579 "Gmsh.y"
    { List_Add(View->TL, &yyvsp[0].d) ; }
    break;

  case 121:
#line 581 "Gmsh.y"
    { List_Add(View->TL, &yyvsp[0].d) ; }
    break;

  case 122:
#line 587 "Gmsh.y"
    { 
      List_Add(View->TL, &yyvsp[-11].d); List_Add(View->TL, &yyvsp[-5].d);
      List_Add(View->TL, &yyvsp[-9].d); List_Add(View->TL, &yyvsp[-3].d);
      List_Add(View->TL, &yyvsp[-7].d); List_Add(View->TL, &yyvsp[-1].d);
    }
    break;

  case 123:
#line 593 "Gmsh.y"
    {
      View->NbTL++ ;
    }
    break;

  case 124:
#line 600 "Gmsh.y"
    { List_Add(View->ST, &yyvsp[0].d) ; }
    break;

  case 125:
#line 602 "Gmsh.y"
    { List_Add(View->ST, &yyvsp[0].d) ; }
    break;

  case 126:
#line 609 "Gmsh.y"
    { 
      List_Add(View->ST, &yyvsp[-17].d); List_Add(View->ST, &yyvsp[-11].d);
      List_Add(View->ST, &yyvsp[-5].d);
      List_Add(View->ST, &yyvsp[-15].d); List_Add(View->ST, &yyvsp[-9].d);
      List_Add(View->ST, &yyvsp[-3].d);
      List_Add(View->ST, &yyvsp[-13].d); List_Add(View->ST, &yyvsp[-7].d);
      List_Add(View->ST, &yyvsp[-1].d);
    }
    break;

  case 127:
#line 618 "Gmsh.y"
    {
      View->NbST++ ;
    }
    break;

  case 128:
#line 625 "Gmsh.y"
    { List_Add(View->VT, &yyvsp[0].d) ; }
    break;

  case 129:
#line 627 "Gmsh.y"
    { List_Add(View->VT, &yyvsp[0].d) ; }
    break;

  case 130:
#line 634 "Gmsh.y"
    { 
      List_Add(View->VT, &yyvsp[-17].d); List_Add(View->VT, &yyvsp[-11].d);
      List_Add(View->VT, &yyvsp[-5].d);
      List_Add(View->VT, &yyvsp[-15].d); List_Add(View->VT, &yyvsp[-9].d);
      List_Add(View->VT, &yyvsp[-3].d);
      List_Add(View->VT, &yyvsp[-13].d); List_Add(View->VT, &yyvsp[-7].d);
      List_Add(View->VT, &yyvsp[-1].d);
    }
    break;

  case 131:
#line 643 "Gmsh.y"
    {
      View->NbVT++ ;
    }
    break;

  case 132:
#line 650 "Gmsh.y"
    { List_Add(View->TT, &yyvsp[0].d) ; }
    break;

  case 133:
#line 652 "Gmsh.y"
    { List_Add(View->TT, &yyvsp[0].d) ; }
    break;

  case 134:
#line 659 "Gmsh.y"
    { 
      List_Add(View->TT, &yyvsp[-17].d); List_Add(View->TT, &yyvsp[-11].d);
      List_Add(View->TT, &yyvsp[-5].d);
      List_Add(View->TT, &yyvsp[-15].d); List_Add(View->TT, &yyvsp[-9].d);
      List_Add(View->TT, &yyvsp[-3].d);
      List_Add(View->TT, &yyvsp[-13].d); List_Add(View->TT, &yyvsp[-7].d);
      List_Add(View->TT, &yyvsp[-1].d);
    }
    break;

  case 135:
#line 668 "Gmsh.y"
    {
      View->NbTT++ ;
    }
    break;

  case 136:
#line 675 "Gmsh.y"
    { List_Add(View->SQ, &yyvsp[0].d) ; }
    break;

  case 137:
#line 677 "Gmsh.y"
    { List_Add(View->SQ, &yyvsp[0].d) ; }
    break;

  case 138:
#line 685 "Gmsh.y"
    { 
      List_Add(View->SQ, &yyvsp[-23].d);  List_Add(View->SQ, &yyvsp[-17].d);
      List_Add(View->SQ, &yyvsp[-11].d); List_Add(View->SQ, &yyvsp[-5].d);
      List_Add(View->SQ, &yyvsp[-21].d);  List_Add(View->SQ, &yyvsp[-15].d);
      List_Add(View->SQ, &yyvsp[-9].d); List_Add(View->SQ, &yyvsp[-3].d);
      List_Add(View->SQ, &yyvsp[-19].d);  List_Add(View->SQ, &yyvsp[-13].d);
      List_Add(View->SQ, &yyvsp[-7].d); List_Add(View->SQ, &yyvsp[-1].d);
    }
    break;

  case 139:
#line 694 "Gmsh.y"
    {
      View->NbSQ++ ;
    }
    break;

  case 140:
#line 701 "Gmsh.y"
    { List_Add(View->VQ, &yyvsp[0].d) ; }
    break;

  case 141:
#line 703 "Gmsh.y"
    { List_Add(View->VQ, &yyvsp[0].d) ; }
    break;

  case 142:
#line 711 "Gmsh.y"
    { 
      List_Add(View->VQ, &yyvsp[-23].d);  List_Add(View->VQ, &yyvsp[-17].d);
      List_Add(View->VQ, &yyvsp[-11].d); List_Add(View->VQ, &yyvsp[-5].d);
      List_Add(View->VQ, &yyvsp[-21].d);  List_Add(View->VQ, &yyvsp[-15].d);
      List_Add(View->VQ, &yyvsp[-9].d); List_Add(View->VQ, &yyvsp[-3].d);
      List_Add(View->VQ, &yyvsp[-19].d);  List_Add(View->VQ, &yyvsp[-13].d);
      List_Add(View->VQ, &yyvsp[-7].d); List_Add(View->VQ, &yyvsp[-1].d);
    }
    break;

  case 143:
#line 720 "Gmsh.y"
    {
      View->NbVQ++ ;
    }
    break;

  case 144:
#line 727 "Gmsh.y"
    { List_Add(View->TQ, &yyvsp[0].d) ; }
    break;

  case 145:
#line 729 "Gmsh.y"
    { List_Add(View->TQ, &yyvsp[0].d) ; }
    break;

  case 146:
#line 737 "Gmsh.y"
    { 
      List_Add(View->TQ, &yyvsp[-23].d);  List_Add(View->TQ, &yyvsp[-17].d);
      List_Add(View->TQ, &yyvsp[-11].d); List_Add(View->TQ, &yyvsp[-5].d);
      List_Add(View->TQ, &yyvsp[-21].d);  List_Add(View->TQ, &yyvsp[-15].d);
      List_Add(View->TQ, &yyvsp[-9].d); List_Add(View->TQ, &yyvsp[-3].d);
      List_Add(View->TQ, &yyvsp[-19].d);  List_Add(View->TQ, &yyvsp[-13].d);
      List_Add(View->TQ, &yyvsp[-7].d); List_Add(View->TQ, &yyvsp[-1].d);
    }
    break;

  case 147:
#line 746 "Gmsh.y"
    {
      View->NbTQ++ ;
    }
    break;

  case 148:
#line 753 "Gmsh.y"
    { List_Add(View->SS, &yyvsp[0].d) ; }
    break;

  case 149:
#line 755 "Gmsh.y"
    { List_Add(View->SS, &yyvsp[0].d) ; }
    break;

  case 150:
#line 763 "Gmsh.y"
    { 
      List_Add(View->SS, &yyvsp[-23].d);  List_Add(View->SS, &yyvsp[-17].d);
      List_Add(View->SS, &yyvsp[-11].d); List_Add(View->SS, &yyvsp[-5].d);
      List_Add(View->SS, &yyvsp[-21].d);  List_Add(View->SS, &yyvsp[-15].d);
      List_Add(View->SS, &yyvsp[-9].d); List_Add(View->SS, &yyvsp[-3].d);
      List_Add(View->SS, &yyvsp[-19].d);  List_Add(View->SS, &yyvsp[-13].d);
      List_Add(View->SS, &yyvsp[-7].d); List_Add(View->SS, &yyvsp[-1].d);
    }
    break;

  case 151:
#line 772 "Gmsh.y"
    {
      View->NbSS++ ;
    }
    break;

  case 152:
#line 779 "Gmsh.y"
    { List_Add(View->VS, &yyvsp[0].d) ; }
    break;

  case 153:
#line 781 "Gmsh.y"
    { List_Add(View->VS, &yyvsp[0].d) ; }
    break;

  case 154:
#line 789 "Gmsh.y"
    { 
      List_Add(View->VS, &yyvsp[-23].d);  List_Add(View->VS, &yyvsp[-17].d);
      List_Add(View->VS, &yyvsp[-11].d); List_Add(View->VS, &yyvsp[-5].d);
      List_Add(View->VS, &yyvsp[-21].d);  List_Add(View->VS, &yyvsp[-15].d);
      List_Add(View->VS, &yyvsp[-9].d); List_Add(View->VS, &yyvsp[-3].d);
      List_Add(View->VS, &yyvsp[-19].d);  List_Add(View->VS, &yyvsp[-13].d);
      List_Add(View->VS, &yyvsp[-7].d); List_Add(View->VS, &yyvsp[-1].d);
    }
    break;

  case 155:
#line 798 "Gmsh.y"
    {
      View->NbVS++ ;
    }
    break;

  case 156:
#line 805 "Gmsh.y"
    { List_Add(View->TS, &yyvsp[0].d) ; }
    break;

  case 157:
#line 807 "Gmsh.y"
    { List_Add(View->TS, &yyvsp[0].d) ; }
    break;

  case 158:
#line 815 "Gmsh.y"
    { 
      List_Add(View->TS, &yyvsp[-23].d);  List_Add(View->TS, &yyvsp[-17].d);
      List_Add(View->TS, &yyvsp[-11].d); List_Add(View->TS, &yyvsp[-5].d);
      List_Add(View->TS, &yyvsp[-21].d);  List_Add(View->TS, &yyvsp[-15].d);
      List_Add(View->TS, &yyvsp[-9].d); List_Add(View->TS, &yyvsp[-3].d);
      List_Add(View->TS, &yyvsp[-19].d);  List_Add(View->TS, &yyvsp[-13].d);
      List_Add(View->TS, &yyvsp[-7].d); List_Add(View->TS, &yyvsp[-1].d);
    }
    break;

  case 159:
#line 824 "Gmsh.y"
    {
      View->NbTS++ ;
    }
    break;

  case 160:
#line 831 "Gmsh.y"
    { List_Add(View->SH, &yyvsp[0].d) ; }
    break;

  case 161:
#line 833 "Gmsh.y"
    { List_Add(View->SH, &yyvsp[0].d) ; }
    break;

  case 162:
#line 845 "Gmsh.y"
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
    }
    break;

  case 163:
#line 860 "Gmsh.y"
    {
      View->NbSH++ ;
    }
    break;

  case 164:
#line 867 "Gmsh.y"
    { List_Add(View->VH, &yyvsp[0].d) ; }
    break;

  case 165:
#line 869 "Gmsh.y"
    { List_Add(View->VH, &yyvsp[0].d) ; }
    break;

  case 166:
#line 881 "Gmsh.y"
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
    }
    break;

  case 167:
#line 896 "Gmsh.y"
    {
      View->NbVH++ ;
    }
    break;

  case 168:
#line 903 "Gmsh.y"
    { List_Add(View->TH, &yyvsp[0].d) ; }
    break;

  case 169:
#line 905 "Gmsh.y"
    { List_Add(View->TH, &yyvsp[0].d) ; }
    break;

  case 170:
#line 917 "Gmsh.y"
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
    }
    break;

  case 171:
#line 932 "Gmsh.y"
    {
      View->NbTH++ ;
    }
    break;

  case 172:
#line 939 "Gmsh.y"
    { List_Add(View->SI, &yyvsp[0].d) ; }
    break;

  case 173:
#line 941 "Gmsh.y"
    { List_Add(View->SI, &yyvsp[0].d) ; }
    break;

  case 174:
#line 951 "Gmsh.y"
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
    }
    break;

  case 175:
#line 963 "Gmsh.y"
    {
      View->NbSI++ ;
    }
    break;

  case 176:
#line 970 "Gmsh.y"
    { List_Add(View->VI, &yyvsp[0].d) ; }
    break;

  case 177:
#line 972 "Gmsh.y"
    { List_Add(View->VI, &yyvsp[0].d) ; }
    break;

  case 178:
#line 982 "Gmsh.y"
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
    }
    break;

  case 179:
#line 994 "Gmsh.y"
    {
      View->NbVI++ ;
    }
    break;

  case 180:
#line 1001 "Gmsh.y"
    { List_Add(View->TI, &yyvsp[0].d) ; }
    break;

  case 181:
#line 1003 "Gmsh.y"
    { List_Add(View->TI, &yyvsp[0].d) ; }
    break;

  case 182:
#line 1013 "Gmsh.y"
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
    }
    break;

  case 183:
#line 1025 "Gmsh.y"
    {
      View->NbTI++ ;
    }
    break;

  case 184:
#line 1032 "Gmsh.y"
    { List_Add(View->SY, &yyvsp[0].d) ; }
    break;

  case 185:
#line 1034 "Gmsh.y"
    { List_Add(View->SY, &yyvsp[0].d) ; }
    break;

  case 186:
#line 1043 "Gmsh.y"
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
    }
    break;

  case 187:
#line 1055 "Gmsh.y"
    {
      View->NbSY++ ;
    }
    break;

  case 188:
#line 1062 "Gmsh.y"
    { List_Add(View->VY, &yyvsp[0].d) ; }
    break;

  case 189:
#line 1064 "Gmsh.y"
    { List_Add(View->VY, &yyvsp[0].d) ; }
    break;

  case 190:
#line 1073 "Gmsh.y"
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
    }
    break;

  case 191:
#line 1085 "Gmsh.y"
    {
      View->NbVY++ ;
    }
    break;

  case 192:
#line 1092 "Gmsh.y"
    { List_Add(View->TY, &yyvsp[0].d) ; }
    break;

  case 193:
#line 1094 "Gmsh.y"
    { List_Add(View->TY, &yyvsp[0].d) ; }
    break;

  case 194:
#line 1103 "Gmsh.y"
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
    }
    break;

  case 195:
#line 1115 "Gmsh.y"
    {
      View->NbTY++ ;
    }
    break;

  case 196:
#line 1122 "Gmsh.y"
    { 
      for(i=0; i<(int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]) ; 
      Free(yyvsp[0].c);
    }
    break;

  case 197:
#line 1127 "Gmsh.y"
    { 
      for(i=0; i<(int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]) ; 
      Free(yyvsp[0].c);
    }
    break;

  case 198:
#line 1135 "Gmsh.y"
    { 
      List_Add(View->T2D, &yyvsp[-5].d); List_Add(View->T2D, &yyvsp[-3].d);
      List_Add(View->T2D, &yyvsp[-1].d); 
      d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    }
    break;

  case 199:
#line 1142 "Gmsh.y"
    {
      View->NbT2++ ;
    }
    break;

  case 200:
#line 1149 "Gmsh.y"
    { 
      for(i=0; i<(int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]) ; 
      Free(yyvsp[0].c);
    }
    break;

  case 201:
#line 1154 "Gmsh.y"
    { 
      for(i=0; i<(int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]) ; 
      Free(yyvsp[0].c);
    }
    break;

  case 202:
#line 1162 "Gmsh.y"
    { 
      List_Add(View->T3D, &yyvsp[-7].d); List_Add(View->T3D, &yyvsp[-5].d);
      List_Add(View->T3D, &yyvsp[-3].d); List_Add(View->T3D, &yyvsp[-1].d); 
      d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    }
    break;

  case 203:
#line 1169 "Gmsh.y"
    {
      View->NbT3++ ;
    }
    break;

  case 204:
#line 1178 "Gmsh.y"
    { yyval.i = 0 ; }
    break;

  case 205:
#line 1179 "Gmsh.y"
    { yyval.i = 1 ; }
    break;

  case 206:
#line 1180 "Gmsh.y"
    { yyval.i = 2 ; }
    break;

  case 207:
#line 1181 "Gmsh.y"
    { yyval.i = 3 ; }
    break;

  case 208:
#line 1182 "Gmsh.y"
    { yyval.i = 4 ; }
    break;

  case 209:
#line 1186 "Gmsh.y"
    { yyval.i = 1 ; }
    break;

  case 210:
#line 1187 "Gmsh.y"
    { yyval.i = -1 ; }
    break;

  case 211:
#line 1195 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-3].c;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	if(!yyvsp[-2].i){
	  List_Put(TheSymbol.val, 0, &yyvsp[-1].d);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else
	  yymsg(GERROR, "Unknown variable '%s'", yyvsp[-3].c) ;
      }
      else{
	pd = (double*)List_Pointer_Fast(pSymbol->val, 0) ; 
	switch(yyvsp[-2].i){
	case 0 : *pd = yyvsp[-1].d; break ;
	case 1 : *pd += yyvsp[-1].d ; break ;
	case 2 : *pd -= yyvsp[-1].d ; break ;
	case 3 : *pd *= yyvsp[-1].d ; break ;
	case 4 : 
	  if(yyvsp[-1].d) *pd /= yyvsp[-1].d ; 
	  else yymsg(GERROR, "Division by zero in '%s /= %g'", yyvsp[-3].c, yyvsp[-1].d);
	  break;
	}
      }
    }
    break;

  case 212:
#line 1222 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-6].c;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5,5,sizeof(double));
	if(!yyvsp[-2].i){
	  List_Put(TheSymbol.val, (int)yyvsp[-4].d, &yyvsp[-1].d);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else
	  yymsg(GERROR, "Unknown variable '%s'", yyvsp[-6].c) ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)yyvsp[-4].d))){
	  switch(yyvsp[-2].i){
	  case 0 : *pd = yyvsp[-1].d; break ;
	  case 1 : *pd += yyvsp[-1].d ; break ;
	  case 2 : *pd -= yyvsp[-1].d ; break ;
	  case 3 : *pd *= yyvsp[-1].d ; break ;
	  case 4 : 
	    if(yyvsp[-1].d) *pd /= yyvsp[-1].d ; 
	    else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-1].d);
	    break;
	  }
	}
	else{
	  if(!yyvsp[-2].i)
	    List_Put(pSymbol->val, (int)yyvsp[-4].d, &yyvsp[-1].d);
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-6].c, (int)yyvsp[-4].d) ;
	}
      }
    }
    break;

  case 213:
#line 1256 "Gmsh.y"
    {
      if(List_Nbr(yyvsp[-5].l) != List_Nbr(yyvsp[-1].l))
	yymsg(GERROR, "Incompatible array dimensions in affectation");
      else{
	TheSymbol.Name = yyvsp[-8].c;
	if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	  TheSymbol.val = List_Create(5,5,sizeof(double));
	  if(!yyvsp[-2].i){
	    for(i=0 ; i<List_Nbr(yyvsp[-5].l) ; i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer(yyvsp[-5].l,i)),
		       (double*)List_Pointer(yyvsp[-1].l,i));
	    }
	    Tree_Add(Symbol_T, &TheSymbol);
	  }
	  else
	    yymsg(GERROR, "Unknown variable '%s'", yyvsp[-8].c) ;
	}
	else{
	  for(i=0 ; i<List_Nbr(yyvsp[-5].l) ; i++){
	    j = (int)(*(double*)List_Pointer(yyvsp[-5].l,i)) ;
	    d = *(double*)List_Pointer(yyvsp[-1].l,i) ;
	    if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	      switch(yyvsp[-2].i){
	      case 0 : *pd = d; break ;
	      case 1 : *pd += d ; break ;
	      case 2 : *pd -= d ; break ;
	      case 3 : *pd *= d ; break ;
	      case 4 : 
		if(yyvsp[-1].l) *pd /= d ; 
		else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", yyvsp[-8].c, j, d);
		break;
	      }
	    }
	    else{
	      if(!yyvsp[-2].i)
		List_Put(pSymbol->val, j, &d);
	      else
		yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-8].c, j) ;	  
	    }
	  }
	}
      }
      List_Delete(yyvsp[-5].l);
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 214:
#line 1303 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-5].c;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5,5,sizeof(double));
	List_Copy(yyvsp[-1].l,TheSymbol.val);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Reset(pSymbol->val);
	List_Copy(yyvsp[-1].l, pSymbol->val);
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 215:
#line 1318 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-2].c;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c) ; 
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += yyvsp[-1].i; 
    }
    break;

  case 216:
#line 1327 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-5].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-5].c) ; 
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)yyvsp[-3].d)))
	  *pd += yyvsp[-1].i ;
	else
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-5].c, (int)yyvsp[-3].d) ;
      }
    }
    break;

  case 217:
#line 1342 "Gmsh.y"
    { 
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-5].c)))
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-5].c);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-3].c, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", yyvsp[-5].c, yyvsp[-3].c);
	else
	  pStrOpt(0,GMSH_SET|GMSH_GUI,yyvsp[-1].c) ;
      }
    }
    break;

  case 218:
#line 1354 "Gmsh.y"
    { 
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-8].c)))
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-8].c);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-3].c, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", yyvsp[-8].c, (int)yyvsp[-6].d, yyvsp[-3].c);
	else
	  pStrOpt((int)yyvsp[-6].d,GMSH_SET|GMSH_GUI,yyvsp[-1].c) ;
      }
    }
    break;

  case 219:
#line 1368 "Gmsh.y"
    {
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-5].c)))
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-5].c);
      else{
	if(!(pNumOpt = (double (*) (int, int, double))Get_NumberOption(yyvsp[-3].c, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", yyvsp[-5].c, yyvsp[-3].c);
	else{
	  switch(yyvsp[-2].i){
	  case 0 : d = yyvsp[-1].d ; break ;
	  case 1 : d = pNumOpt(0,GMSH_GET,0) + yyvsp[-1].d ; break ;
	  case 2 : d = pNumOpt(0,GMSH_GET,0) - yyvsp[-1].d ; break ;
	  case 3 : d = pNumOpt(0,GMSH_GET,0) * yyvsp[-1].d ; break ;
	  case 4 : 
	    if(yyvsp[-1].d) d = pNumOpt(0,GMSH_GET,0) / yyvsp[-1].d ; 
	    else yymsg(GERROR, "Division by zero in '%s.%s /= %g'", yyvsp[-5].c, yyvsp[-3].c, yyvsp[-1].d);
	    break;
	  }
	  pNumOpt(0,GMSH_SET|GMSH_GUI, d) ;
	}
      }
    }
    break;

  case 220:
#line 1391 "Gmsh.y"
    {
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-8].c)))
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-8].c);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-3].c, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", yyvsp[-8].c, (int)yyvsp[-6].d, yyvsp[-3].c);
	else{
	  switch(yyvsp[-2].i){
	  case 0 : d = yyvsp[-1].d; break ;
	  case 1 : d = pNumOpt((int)yyvsp[-6].d,GMSH_GET,0) + yyvsp[-1].d ; break ;
	  case 2 : d = pNumOpt((int)yyvsp[-6].d,GMSH_GET,0) - yyvsp[-1].d ; break ;
	  case 3 : d = pNumOpt((int)yyvsp[-6].d,GMSH_GET,0) * yyvsp[-1].d ; break ;
	  case 4 : 
	    if(yyvsp[-1].d) d = pNumOpt((int)yyvsp[-6].d,GMSH_GET,0) / yyvsp[-1].d ;
	    else yymsg(GERROR, "Division by zero in '%s[%d].%s /= %g'", 
		       yyvsp[-8].c, (int)yyvsp[-6].d, yyvsp[-3].c, yyvsp[-1].d);
	    break;
	  }
	  pNumOpt((int)yyvsp[-6].d,GMSH_SET|GMSH_GUI,d) ;
	}
      }
    }
    break;

  case 221:
#line 1415 "Gmsh.y"
    {
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-4].c)))
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-4].c);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-2].c, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", yyvsp[-4].c, yyvsp[-2].c);
	else
	  pNumOpt(0,GMSH_SET|GMSH_GUI,pNumOpt(0,GMSH_GET,0)+yyvsp[-1].i) ;
      }
    }
    break;

  case 222:
#line 1427 "Gmsh.y"
    {
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-7].c)))
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-7].c);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-2].c, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", yyvsp[-7].c, (int)yyvsp[-5].d, yyvsp[-2].c);
	else
	  pNumOpt((int)yyvsp[-5].d,GMSH_SET|GMSH_GUI,pNumOpt((int)yyvsp[-5].d,GMSH_GET,0)+yyvsp[-1].i) ;
      }
    }
    break;

  case 223:
#line 1441 "Gmsh.y"
    {
      if(!(pColCat = Get_ColorOptionCategory(yyvsp[-7].c)))
	yymsg(GERROR, "Unknown color option class '%s'", yyvsp[-7].c);
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption(yyvsp[-3].c, pColCat)))
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", yyvsp[-7].c, yyvsp[-3].c);
	else
	  pColOpt(0,GMSH_SET|GMSH_GUI,yyvsp[-1].u) ;
      }
    }
    break;

  case 224:
#line 1453 "Gmsh.y"
    {
      if(!(pColCat = Get_ColorOptionCategory(yyvsp[-10].c)))
	yymsg(GERROR, "Unknown color option class '%s'", yyvsp[-10].c);
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption(yyvsp[-3].c, pColCat)))
	  yymsg(GERROR, "Unknown color option '%s[%d].Color.%s'", yyvsp[-10].c, (int)yyvsp[-8].d, yyvsp[-3].c);
	else
	  pColOpt((int)yyvsp[-8].d,GMSH_SET|GMSH_GUI,yyvsp[-1].u) ;
      }
    }
    break;

  case 225:
#line 1467 "Gmsh.y"
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
	  for(i=0 ; i<ct->size ; i++) List_Read(yyvsp[-1].l, i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 226:
#line 1487 "Gmsh.y"
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
	  for(i=0 ; i<ct->size ; i++) List_Read(yyvsp[-1].l, i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 227:
#line 1509 "Gmsh.y"
    {
      if(CTX.default_plugins){
	try {
	  GMSH_PluginManager::Instance()->SetPluginOption(yyvsp[-6].c,yyvsp[-3].c,yyvsp[-1].d); 
	}
	catch (...) {
	  yymsg(WARNING, "Unknown option '%s' or plugin '%s'",yyvsp[-3].c,yyvsp[-6].c);
	}
      }
    }
    break;

  case 228:
#line 1521 "Gmsh.y"
    {
      if(CTX.default_plugins){
	try {
	  GMSH_PluginManager::Instance()->SetPluginOption(yyvsp[-6].c,yyvsp[-3].c,yyvsp[-1].c); 
	}
	catch (...) {
	  yymsg(WARNING, "Unknown option '%s' or plugin '%s'",yyvsp[-3].c,yyvsp[-6].c);
	}
      }
    }
    break;

  case 229:
#line 1541 "Gmsh.y"
    {
      Cdbpts101((int)yyvsp[-4].d,yyvsp[-1].v[0],yyvsp[-1].v[1],yyvsp[-1].v[2],yyvsp[-1].v[3],yyvsp[-1].v[4]);
      yyval.s.Type = MSH_POINT;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 230:
#line 1548 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_PHYSICAL_POINT,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_PHYSICAL_POINT;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 231:
#line 1554 "Gmsh.y"
    {
      Vertex *v;
      Attractor *a;
      double p;
      int ip;
      for(int i=0;i<List_Nbr(yyvsp[-9].l);i++){
      	List_Read(yyvsp[-9].l,i,&p);
        ip = (int)p;
        v = FindPoint(ip,THEM);
        if(!v)
	  yymsg(WARNING, "Unknown Point %d", ip);
	else{
	  a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
			       yyvsp[-6].d,yyvsp[-4].d,yyvsp[-2].d,v,NULL,NULL);
	  List_Add(THEM->Metric->Attractors,&a);
        }
      }
    }
    break;

  case 232:
#line 1573 "Gmsh.y"
    {
      for(i=0;i<List_Nbr(yyvsp[-3].l);i++){
	List_Read(yyvsp[-3].l,i,&d);
	Vertex *v = FindPoint((int)d,THEM);
	if(!v)
	  yymsg(WARNING, "Unknown Point %d", (int)d);
	else
	  v->lc = yyvsp[-1].d;
      }
    }
    break;

  case 233:
#line 1587 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_LINE,1,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      yyval.s.Type = MSH_SEGM_LINE;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 234:
#line 1593 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_SPLN,3,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      yyval.s.Type = MSH_SEGM_SPLN;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 235:
#line 1599 "Gmsh.y"
    {
      Curve *c;
      Attractor *a;
      double p;
      int ip;
      for(int i=0;i<List_Nbr(yyvsp[-9].l);i++){
      	List_Read(yyvsp[-9].l,i,&p);
        ip = (int)p;
        c = FindCurve(ip,THEM);
        if(!c)
	  yymsg(WARNING, "Unknown Curve %d", ip);
	else{
	  a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
			       yyvsp[-6].d,yyvsp[-4].d,yyvsp[-2].d,NULL,c,NULL);
	  List_Add(THEM->Metric->Attractors,&a);
        }
      }
    }
    break;

  case 236:
#line 1618 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_CIRC,2,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      yyval.s.Type = MSH_SEGM_CIRC ;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 237:
#line 1624 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_ELLI,2,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      yyval.s.Type = MSH_SEGM_ELLI ;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 238:
#line 1630 "Gmsh.y"
    {
      List_T *temp;
      int i,j;
      double d;
      temp = List_Create(List_Nbr(yyvsp[-3].l),1,sizeof(int));
      for(i=0;i<List_Nbr(yyvsp[-3].l);i++){
      	List_Read(yyvsp[-3].l,i,&d);
        j = (int)d;
        List_Add(temp,&j);
      }
      AddCircleInDataBase ((int) yyvsp[-6].d, MSH_SEGM_CIRC, temp, yyvsp[-1].v);
      List_Delete(temp);
      yyval.s.Type = MSH_SEGM_CIRC ;
      yyval.s.Num  = (int)yyvsp[-6].d;
    }
    break;

  case 239:
#line 1647 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-14].d,MSH_SEGM_PARAMETRIC,2,NULL,NULL,-1,-1,yyvsp[-10].d,yyvsp[-8].d,yyvsp[-6].c,yyvsp[-4].c,yyvsp[-2].c);
      yyval.s.Type = MSH_SEGM_PARAMETRIC ;
      yyval.s.Num  = (int)yyvsp[-14].d;
    }
    break;

  case 240:
#line 1653 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_PHYSICAL_LINE,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_PHYSICAL_LINE;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 241:
#line 1659 "Gmsh.y"
    {
      yyval.s.Type = MSH_SEGM_LOOP;
      Cdbz101((int)yyvsp[-4].d,yyval.s.Type,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Num = (int)yyvsp[-4].d;
    }
    break;

  case 242:
#line 1665 "Gmsh.y"
    {
      if(List_Nbr(yyvsp[-1].l) > 3){
	Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_BSPLN,2,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
	yyval.s.Type = MSH_SEGM_BSPLN;
	yyval.s.Num  = (int)yyvsp[-4].d;
      }
      else
	yymsg(GERROR, "Too few control points for BSpline %d (%d < 4)", (int)yyvsp[-4].d, 
	      List_Nbr(yyvsp[-1].l));
    }
    break;

  case 243:
#line 1676 "Gmsh.y"
    {
      if(List_Nbr(yyvsp[-1].l) > 3){
	Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_BEZIER,2,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
	yyval.s.Type = MSH_SEGM_BSPLN;
	yyval.s.Num  = (int)yyvsp[-4].d;
      }
      else
	yymsg(GERROR, "Too few control points for Bezier %d (%d < 4)", (int)yyvsp[-4].d, 
	      List_Nbr(yyvsp[-1].l));
    }
    break;

  case 244:
#line 1687 "Gmsh.y"
    {
      List_T *Temp;
      int i;
      double d;
      if(List_Nbr(yyvsp[-5].l) + (int)yyvsp[-1].d + 1 != List_Nbr(yyvsp[-3].l)){
	yymsg(GERROR, "Wrong definition of Nurbs Curve %d: "
	      "got %d Knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)yyvsp[-8].d, 
	      List_Nbr(yyvsp[-3].l), List_Nbr(yyvsp[-5].l), (int)yyvsp[-1].d, List_Nbr(yyvsp[-5].l) + (int)yyvsp[-1].d + 1);
      }
      else{
	Temp = List_Create(List_Nbr(yyvsp[-5].l),1,sizeof(int));
	for(i=0;i<List_Nbr(yyvsp[-5].l);i++) {
	  List_Read(yyvsp[-5].l,i,&d);
	  j = (int)d;
	  List_Add(Temp,&j);
	}
	AddCurveInDataBase ((int)yyvsp[-8].d,MSH_SEGM_NURBS,(int)yyvsp[-1].d,Temp,yyvsp[-3].l,-1,-1,0.,1.);
	List_Delete(Temp);
      }
    }
    break;

  case 245:
#line 1712 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_SURF_PLAN,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_SURF_PLAN;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 246:
#line 1718 "Gmsh.y"
    {
      Surface *s,*support;
      support = FindSurface((int)yyvsp[-4].d,THEM);
      if(!support)
	yymsg(GERROR, "Unknown Surface %d", (int)yyvsp[-4].d);
      else{
	Cdbz101((int)yyvsp[-8].d,MSH_SURF_PLAN,0,0,0,0,0,NULL,yyvsp[-2].l,NULL);
	s = FindSurface((int)yyvsp[-8].d,THEM);
	if(!s)
	  yymsg(GERROR, "Unknown Surface %d", (int)yyvsp[-8].d);
	else{
	  s->Typ =  MSH_SURF_TRIMMED;
	  s->Support = support;
	  yyval.s.Type = MSH_SURF_TRIMMED;
	  yyval.s.Num  = (int)yyvsp[-8].d;
	}
      }
    }
    break;

  case 247:
#line 1737 "Gmsh.y"
    {
      List_Read(yyvsp[-1].l,0,&d);
      i = (int)d;
      EdgeLoop *el = FindEdgeLoop(i,THEM);
      if(!el)
	yymsg(GERROR, "Unknown Line Loop %d", i);
      else{
	j = List_Nbr(el->Curves);
	if(j==4)
	  yyval.s.Type = MSH_SURF_REGL;
	else if(j==3)
	  yyval.s.Type  = MSH_SURF_TRIC;
	else
	  yymsg(GERROR, "Wrong definition of Ruled Surface %d: "
		   "%d borders instead of 3 or 4", 
		   (int)yyvsp[-4].d, j);
	Cdbz101((int)yyvsp[-4].d,yyval.s.Type,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
	yyval.s.Num = (int)yyvsp[-4].d;
      }
    }
    break;

  case 248:
#line 1759 "Gmsh.y"
    {
    AddTriangulationToSurface ((int) yyvsp[-10].d, (int) yyvsp[-6].d, (int) yyvsp[-4].d,yyvsp[-2].l,yyvsp[-1].l);
    yyval.s.Num = (int)yyvsp[-10].d;
  }
    break;

  case 249:
#line 1767 "Gmsh.y"
    {
      CreateNurbsSurface ( (int) yyvsp[-16].d , (int)yyvsp[-4].d , (int)yyvsp[-2].d  , yyvsp[-13].l, yyvsp[-10].l, yyvsp[-8].l);
      yyval.s.Type  = MSH_SURF_NURBS;
      yyval.s.Num = (int)yyvsp[-16].d;
    }
    break;

  case 250:
#line 1775 "Gmsh.y"
    {
      CreateNurbsSurfaceSupport ((int)yyvsp[-16].d, (int) yyvsp[-4].d , (int) yyvsp[-2].d , yyvsp[-13].l, yyvsp[-10].l, yyvsp[-8].l);
    }
    break;

  case 251:
#line 1779 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_PHYSICAL_SURFACE,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_PHYSICAL_SURFACE;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 252:
#line 1785 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_SURF_LOOP,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_SURF_LOOP;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 253:
#line 1794 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_VOLUME,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_VOLUME;
      yyval.s.Num  = (int)yyvsp[-4].d;      
    }
    break;

  case 254:
#line 1800 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_VOLUME,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_VOLUME;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 255:
#line 1806 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_PHYSICAL_VOLUME,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_PHYSICAL_VOLUME;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 256:
#line 1817 "Gmsh.y"
    {
      TranslateShapes (yyvsp[-3].v[0],yyvsp[-3].v[1],yyvsp[-3].v[2],yyvsp[-1].l,1);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 257:
#line 1822 "Gmsh.y"
    {
      RotateShapes(yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].d,yyvsp[-1].l,1);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 258:
#line 1827 "Gmsh.y"
    {
      SymmetryShapes(yyvsp[-3].v[0],yyvsp[-3].v[1],yyvsp[-3].v[2],yyvsp[-3].v[3],yyvsp[-1].l,1);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 259:
#line 1832 "Gmsh.y"
    {
      DilatShapes(yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].d,yyvsp[-1].l,1);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 260:
#line 1839 "Gmsh.y"
    { yyval.l = yyvsp[0].l; }
    break;

  case 261:
#line 1840 "Gmsh.y"
    { yyval.l = yyvsp[0].l; }
    break;

  case 262:
#line 1841 "Gmsh.y"
    { yyval.l = yyvsp[0].l; }
    break;

  case 263:
#line 1846 "Gmsh.y"
    {
      yyval.l = List_Create(3,3,sizeof(Shape));
    }
    break;

  case 264:
#line 1850 "Gmsh.y"
    {
      List_Add(yyval.l,&yyvsp[0].s);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 265:
#line 1855 "Gmsh.y"
    {
      for(i=0;i<List_Nbr(yyvsp[-2].l);i++){
	List_Read(yyvsp[-2].l, i, &d);
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(TheShape.Num,THEM);
	if(!v)
	  yymsg(WARNING, "Unknown Point %d", TheShape.Num);
	else{
	  TheShape.Type = MSH_POINT;
	  List_Add(yyval.l,&TheShape);
	}
      }
      yyval.l = yyvsp[-5].l;
    }
    break;

  case 266:
#line 1870 "Gmsh.y"
    {
      for(i=0;i<List_Nbr(yyvsp[-2].l);i++){
	List_Read(yyvsp[-2].l, i, &d);
	TheShape.Num = (int)d;
	Curve *c = FindCurve(TheShape.Num,THEM);
	if(!c)
	  yymsg(WARNING, "Unknown Curve %d", TheShape.Num);
	else{
	  TheShape.Type = c->Typ;
	  List_Add(yyval.l,&TheShape);
	}
      }
      yyval.l = yyvsp[-5].l;
    }
    break;

  case 267:
#line 1885 "Gmsh.y"
    {
      for(i=0;i<List_Nbr(yyvsp[-2].l);i++){
	List_Read(yyvsp[-2].l, i, &d);
	TheShape.Num = (int)d;
	Surface *s = FindSurface(TheShape.Num,THEM);
	if(!s)
	  yymsg(WARNING, "Unknown Surface %d", TheShape.Num);
	else{
	  TheShape.Type = s->Typ;
	  List_Add(yyval.l,&TheShape);
	}
      }
      yyval.l = yyvsp[-5].l;
    }
    break;

  case 268:
#line 1905 "Gmsh.y"
    {
      yyval.l = List_Create(3,3,sizeof(Shape));
      for(i=0;i<List_Nbr(yyvsp[-1].l);i++){
	List_Read (yyvsp[-1].l,i,&TheShape);
	CopyShape(TheShape.Type,TheShape.Num,&j);
	TheShape.Num = j;
	List_Add(yyval.l,&TheShape);
      }
    }
    break;

  case 269:
#line 1915 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) DuplicateView((int)yyvsp[-2].d,0);
    }
    break;

  case 270:
#line 1925 "Gmsh.y"
    {
      for(i=0;i<List_Nbr(yyvsp[-1].l);i++){
	List_Read (yyvsp[-1].l,i,&TheShape);
	DeleteShape(TheShape.Type,TheShape.Num);
      }
    }
    break;

  case 271:
#line 1932 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) FreeView((int)yyvsp[-2].d);
    }
    break;

  case 272:
#line 1936 "Gmsh.y"
    {
      Init_Mesh(THEM, 1);
    }
    break;

  case 273:
#line 1945 "Gmsh.y"
    {
      for(i=0;i<List_Nbr(yyvsp[-1].l);i++){
	List_Read (yyvsp[-1].l,i,&TheShape);
	ColorShape(TheShape.Type,TheShape.Num,yyvsp[-3].u);
      }
    }
    break;

  case 274:
#line 1957 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-2].c, "Include")){

	yyinTab[RecursionLevel++] = yyin;

	if(yyvsp[-1].c[0] == '/' || yyvsp[-1].c[0] == '\\' || (strlen(yyvsp[-1].c)>2 && yyvsp[-1].c[1] == ':')){
	  // do nothing:  is an absolute path
	  strcpy(tmpstring, yyvsp[-1].c);
	}
	else{
	  // append  to the path of the parent file
	  strcpy(tmpstring, yyname);
	  i = strlen(yyname)-1 ;
	  while(i >= 0 && yyname[i] != '/' && yyname[i] != '\\') i-- ;
	  tmpstring[i+1] = '\0';
	  strcat(tmpstring, yyvsp[-1].c);
	}

	if((yyin = fopen(tmpstring,"r"))){
	  Msg(INFO, "Including '%s'", tmpstring); 
	  strcpy(yynameTab[RecursionLevel-1],yyname);
	  yylinenoTab[RecursionLevel-1]=yylineno;
	  yylineno=1;
	  strcpy(yyname,tmpstring);
	  while(!feof(yyin)){
	    yyparse();
	  }
	  // FIXME: If we do fclose, we cannot call a Function defined
	  // in another file...
	  //fclose(yyin);
	  yyin = yyinTab[--RecursionLevel];
	  strcpy(yyname,yynameTab[RecursionLevel]);
	  yylineno = yylinenoTab[RecursionLevel];
	}
	else{
	  yymsg(GERROR, "Unknown file '%s'", tmpstring) ;  
	  yyin = yyinTab[--RecursionLevel];
	}

      }
      else if(!strcmp(yyvsp[-2].c, "Print")){
#if defined(HAVE_FLTK)
	if(!CTX.batch) CreateOutputFile(yyvsp[-1].c, CTX.print.format);
#endif
      }
      else if(!strcmp(yyvsp[-2].c, "Save")){
#if defined(HAVE_FLTK)
	CreateOutputFile(yyvsp[-1].c, CTX.mesh.format);
#endif
      }

      else if(!strcmp(yyvsp[-2].c, "Merge")){

	FILE *ff = yyin;
	MergeProblem(yyvsp[-1].c);
	yyin = ff;

      }
      else if(!strcmp(yyvsp[-2].c, "MergeWithBoundingBox")){

	FILE *ff = yyin;
	MergeProblemWithBoundingBox(yyvsp[-1].c);
	yyin = ff;

      }
      else if(!strcmp(yyvsp[-2].c, "Open")){

	FILE *ff = yyin;
	OpenProblem(yyvsp[-1].c);
	yyin = ff;

      }
      else if(!strcmp(yyvsp[-2].c, "System")){
	
	SystemCall(yyvsp[-1].c);

      }
      else
	yymsg(GERROR, "Unknown command '%s'", yyvsp[-2].c);
    }
    break;

  case 275:
#line 2038 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-2].c, "Sleep")){

	long sleep_time = GetTime();
	while(1){
	  if(GetTime() - sleep_time > (long)(yyvsp[-1].d*1.e6)) break;
	}
      
      }
      else if(!strcmp(yyvsp[-2].c, "Mesh")){

	//Maillage_Dimension_0(THEM);
	//mai3d(THEM,(int));
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");

      }
      else
	yymsg(GERROR, "Unknown command '%s'", yyvsp[-2].c);
    }
    break;

  case 276:
#line 2058 "Gmsh.y"
    {
    if(CTX.default_plugins)
      GMSH_PluginManager::Instance()->Action(yyvsp[-4].c,yyvsp[-1].c,0); 
   }
    break;

  case 277:
#line 2063 "Gmsh.y"
    {
      exit(0);
    }
    break;

  case 278:
#line 2067 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch){ // we're in interactive mode
	if(Tree_Nbr(THEM->Points) != Last_NumberOfPoints){
	  Last_NumberOfPoints = Tree_Nbr(THEM->Points);
	  Replot();
	  DrawUI();
	}
	else{
	  Draw();
	  DrawUI();
	}
      }
#endif
    }
    break;

  case 279:
#line 2089 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-3].d ;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-1].d ;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = "" ;
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
    break;

  case 280:
#line 2099 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-5].d ;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-3].d ;
      LoopControlVariablesTab[ImbricatedLoop][2] = yyvsp[-1].d ;
      LoopControlVariablesNameTab[ImbricatedLoop] = "" ;
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
    break;

  case 281:
#line 2109 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-3].d ;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-1].d ;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = yyvsp[-6].c ;
      
      TheSymbol.Name = yyvsp[-6].c;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	List_Put(TheSymbol.val, 0, &yyvsp[-3].d);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &yyvsp[-3].d);
      }
      
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
    break;

  case 282:
#line 2130 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-5].d ;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-3].d ;
      LoopControlVariablesTab[ImbricatedLoop][2] = yyvsp[-1].d ;
      LoopControlVariablesNameTab[ImbricatedLoop] = yyvsp[-8].c ;

      TheSymbol.Name = yyvsp[-8].c;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	List_Put(TheSymbol.val, 0, &yyvsp[-5].d);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &yyvsp[-5].d);
      }
      
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
    break;

  case 283:
#line 2151 "Gmsh.y"
    {
      if(LoopControlVariablesTab[ImbricatedLoop-1][1] >  
	 LoopControlVariablesTab[ImbricatedLoop-1][0]){
	LoopControlVariablesTab[ImbricatedLoop-1][0] +=
	  LoopControlVariablesTab[ImbricatedLoop-1][2];
	
	if(strlen(LoopControlVariablesNameTab[ImbricatedLoop-1])){
	  TheSymbol.Name = LoopControlVariablesNameTab[ImbricatedLoop-1];
	  pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol);
	  *(double*)List_Pointer_Fast(pSymbol->val, 0) += 
	    LoopControlVariablesTab[ImbricatedLoop-1][2] ;
	}
	
	fsetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop-1]);
	yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop-1];
      }
      else{
	ImbricatedLoop--;
      }
    }
    break;

  case 284:
#line 2172 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction(yyvsp[0].c,yyin,yyname,yylineno))
	yymsg(GERROR, "Redefinition of function %s",yyvsp[0].c);
      skip_until(NULL, "Return");
    }
    break;

  case 285:
#line 2178 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin,yyname,yylineno))
	yymsg(GERROR, "Error while exiting function");
    }
    break;

  case 286:
#line 2183 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction(yyvsp[-1].c,&yyin,yyname,yylineno))
	yymsg(GERROR, "Unknown function %s",yyvsp[-1].c);
    }
    break;

  case 287:
#line 2188 "Gmsh.y"
    {
      if(!yyvsp[-1].d) skip_until("If", "EndIf");
    }
    break;

  case 288:
#line 2192 "Gmsh.y"
    {
    }
    break;

  case 289:
#line 2204 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(TRANSLATE,(int)yyvsp[-4].d,yyvsp[-2].v[0],yyvsp[-2].v[1],yyvsp[-2].v[2],
			   0.,0.,0.,0.,0.,0.,0.,
			   &pc,&prc,1,NULL);
    }
    break;

  case 290:
#line 2211 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(ROTATE,(int)yyvsp[-8].d,0.,0.,0.,
			   yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,
			   &pc,&prc,1,NULL);
    }
    break;

  case 291:
#line 2218 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(TRANSLATE_ROTATE,(int)yyvsp[-10].d,yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],
			   yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,
			   &pc,&prc,1,NULL);
    }
    break;

  case 292:
#line 2225 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 293:
#line 2230 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(TRANSLATE,(int)yyvsp[-8].d,yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],
			   0.,0.,0.,0.,0.,0.,0.,
			   &pc,&prc,1,&extr);
    }
    break;

  case 294:
#line 2237 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 295:
#line 2242 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(ROTATE,(int)yyvsp[-12].d,0.,0.,0.,
			   yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,
			   &pc,&prc,1,&extr);
    }
    break;

  case 296:
#line 2249 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 297:
#line 2254 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(TRANSLATE_ROTATE,(int)yyvsp[-14].d,yyvsp[-12].v[0],yyvsp[-12].v[1],yyvsp[-12].v[2],
			   yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,
			   &pc,&prc,1,&extr);
    }
    break;

  case 298:
#line 2264 "Gmsh.y"
    {
      Extrude_ProtudeCurve(TRANSLATE,(int)yyvsp[-4].d,yyvsp[-2].v[0],yyvsp[-2].v[1],yyvsp[-2].v[2],
			   0.,0.,0.,0.,0.,0.,0.,1,NULL);
    }
    break;

  case 299:
#line 2269 "Gmsh.y"
    {
      Extrude_ProtudeCurve(ROTATE,(int)yyvsp[-8].d,0.,0.,0.,
			   yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,1,NULL);
    }
    break;

  case 300:
#line 2274 "Gmsh.y"
    {
      Extrude_ProtudeCurve(TRANSLATE_ROTATE,(int)yyvsp[-10].d,yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],
			   yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,1,NULL);
    }
    break;

  case 301:
#line 2279 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 302:
#line 2284 "Gmsh.y"
    {
      Extrude_ProtudeCurve(TRANSLATE,(int)yyvsp[-8].d,yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],
			   0.,0.,0.,0.,0.,0.,0.,1,&extr);
    }
    break;

  case 303:
#line 2289 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 304:
#line 2294 "Gmsh.y"
    {
      Extrude_ProtudeCurve(ROTATE,(int)yyvsp[-12].d,0.,0.,0.,
			   yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,1,&extr);
    }
    break;

  case 305:
#line 2299 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 306:
#line 2304 "Gmsh.y"
    {
      Extrude_ProtudeCurve(TRANSLATE_ROTATE,(int)yyvsp[-14].d,yyvsp[-12].v[0],yyvsp[-12].v[1],yyvsp[-12].v[2],
			   yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,1,&extr);
    }
    break;

  case 307:
#line 2312 "Gmsh.y"
    {
      Extrude_ProtudeSurface(TRANSLATE,(int)yyvsp[-4].d,yyvsp[-2].v[0],yyvsp[-2].v[1],yyvsp[-2].v[2],
			     0.,0.,0.,0.,0.,0.,0.,0,NULL);
    }
    break;

  case 308:
#line 2317 "Gmsh.y"
    {
      Extrude_ProtudeSurface(ROTATE,(int)yyvsp[-8].d,0.,0.,0.,
			     yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,0,NULL);
    }
    break;

  case 309:
#line 2322 "Gmsh.y"
    {
      Extrude_ProtudeSurface(TRANSLATE_ROTATE,(int)yyvsp[-10].d,yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],
			     yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,0,NULL);
    }
    break;

  case 310:
#line 2327 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 311:
#line 2332 "Gmsh.y"
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(TRANSLATE,(int)yyvsp[-8].d,yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],
			     0.,0.,0.,0.,0.,0.,0.,vol,&extr);
    }
    break;

  case 312:
#line 2338 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 313:
#line 2344 "Gmsh.y"
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(ROTATE,(int)yyvsp[-12].d,0.,0.,0.,
			     yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,vol,&extr);
    }
    break;

  case 314:
#line 2350 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 315:
#line 2356 "Gmsh.y"
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(TRANSLATE_ROTATE,(int)yyvsp[-14].d,yyvsp[-12].v[0],yyvsp[-12].v[1],yyvsp[-12].v[2],
			     yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,vol,&extr);
    }
    break;

  case 316:
#line 2365 "Gmsh.y"
    {
    }
    break;

  case 317:
#line 2368 "Gmsh.y"
    {
    }
    break;

  case 318:
#line 2374 "Gmsh.y"
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr(yyvsp[-6].l);
      if(List_Nbr(yyvsp[-6].l) == List_Nbr(yyvsp[-4].l) && List_Nbr(yyvsp[-6].l) == List_Nbr(yyvsp[-2].l)){
	extr.mesh.NbElmLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.ZonLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.hLayer = (double*)Malloc(extr.mesh.NbLayer*sizeof(double));
	for(int i=0;i<List_Nbr(yyvsp[-6].l);i++){
	  List_Read(yyvsp[-6].l,i,&d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  List_Read(yyvsp[-4].l,i,&d);
	  extr.mesh.ZonLayer[i] = (int)d;
	  List_Read(yyvsp[-2].l,i,&d);
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
    }
    break;

  case 319:
#line 2400 "Gmsh.y"
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr(yyvsp[-4].l);
      if(List_Nbr(yyvsp[-4].l) == List_Nbr(yyvsp[-2].l)){
	extr.mesh.NbElmLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.ZonLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.hLayer = (double*)Malloc(extr.mesh.NbLayer*sizeof(double));
	for(int i=0;i<List_Nbr(yyvsp[-4].l);i++){
	  List_Read(yyvsp[-4].l,i,&d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  extr.mesh.ZonLayer[i] = 0;
	  List_Read(yyvsp[-2].l,i,&d);
	  extr.mesh.hLayer[i] = d;
	}
      }
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d}", 
	      List_Nbr(yyvsp[-4].l), List_Nbr(yyvsp[-2].l));
      }
      List_Delete(yyvsp[-4].l);
      List_Delete(yyvsp[-2].l);
    }
    break;

  case 320:
#line 2424 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 321:
#line 2433 "Gmsh.y"
    {
      Curve *c;
      for(i=0;i<List_Nbr(yyvsp[-3].l);i++){
	List_Read(yyvsp[-3].l,i,&d);
	j = (int)fabs(d);
        c = FindCurve(j,THEM);
	if(!c)
	  yymsg(WARNING, "Unknown Curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (yyvsp[-1].d>2)?(int)yyvsp[-1].d:2;
	  c->ipar[1] = sign(d);
	  c->dpar[0] = 1.0;
	}
      }
      List_Delete(yyvsp[-3].l);
    }
    break;

  case 322:
#line 2451 "Gmsh.y"
    {
      Curve *c;
      for(i=0;i<List_Nbr(yyvsp[-6].l);i++){
	List_Read(yyvsp[-6].l,i,&d);
	j = (int)fabs(d);
        c = FindCurve(j,THEM);
	if(!c)
	  yymsg(WARNING, "Unknown Curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (yyvsp[-4].d>2)?(int)yyvsp[-4].d:2;
	  c->ipar[1] = sign(d); /* Progresion : code 1 ou -1 */
	  c->dpar[0] = fabs(yyvsp[-1].d);
	}
      }
      List_Delete(yyvsp[-6].l);
    }
    break;

  case 323:
#line 2469 "Gmsh.y"
    {
      Curve *c;
      for(i=0;i<List_Nbr(yyvsp[-6].l);i++){
	List_Read(yyvsp[-6].l,i,&d);
	j = (int)fabs(d);
        c = FindCurve(j,THEM);
	if(!c)
	  yymsg(WARNING, "Unknown Curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (yyvsp[-4].d>2)?(int)yyvsp[-4].d:2;
	  c->ipar[1] = 2*sign(d); /* Bump : code 2 ou -2 */
	  c->dpar[0] = fabs(yyvsp[-1].d);
	}
      }
      List_Delete(yyvsp[-6].l);
    }
    break;

  case 324:
#line 2487 "Gmsh.y"
    {
      Surface *s = FindSurface((int)yyvsp[-4].d,THEM);
      if(!s)
	yymsg(WARNING, "Unknown Surface %d", (int)yyvsp[-4].d);
      else{
	s->Method = TRANSFINI;
	k = List_Nbr(yyvsp[-1].l);
	if(k!=3 && k!=4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , yyvsp[-4].d, k) ;
	}
	else{
	  for(i=0;i<k;i++){
	    List_Read(yyvsp[-1].l,i,&d);
	    j = (int)fabs(d);
	    s->ipar[i] = j;
	  }
	}
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 325:
#line 2509 "Gmsh.y"
    {
      Surface *s = FindSurface((int)yyvsp[-4].d,THEM);
      if(!s)
	yymsg(WARNING, "Unknown Surface %d", (int)yyvsp[-4].d);
      else{
        s->Method = ELLIPTIC;
        k = List_Nbr(yyvsp[-1].l);
        if(k != 4)
	  yymsg(GERROR, "Wrong definition of Elliptic Surface %d: "
		"%d points instead of 4" , yyvsp[-4].d, k) ;
        else{
	  for(i=0;i<k;i++){
	    List_Read(yyvsp[-1].l,i,&d);
	    j = (int)fabs(d);
	    s->ipar[i] = j;
	  }
	}
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 326:
#line 2530 "Gmsh.y"
    {
      Volume *v = FindVolume((int)yyvsp[-4].d,THEM);
      if(!v)
	yymsg(WARNING, "Unknown Volume %d", (int)yyvsp[-4].d);
      else{
	v->Method = TRANSFINI;
	k = List_Nbr(yyvsp[-1].l);
	if(k!=6 && k!=8)
	  yymsg(GERROR, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , yyvsp[-4].d, k) ;
	else{
	  for(i=0;i<k;i++){
	    List_Read(yyvsp[-1].l,i,&d);
	    j = (int)fabs(d);
	    v->ipar[i] = j;
	  }
	}
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 327:
#line 2551 "Gmsh.y"
    {
      Surface *s;
      for(i=0;i<List_Nbr(yyvsp[-3].l);i++){
	List_Read(yyvsp[-3].l,i,&d);
	j = (int)d;
	s = FindSurface(j,THEM);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = (yyvsp[-1].d > 0 && yyvsp[-1].d < 90) ? yyvsp[-1].d : 90;
	}
      }
      List_Delete(yyvsp[-3].l);
    }
    break;

  case 328:
#line 2565 "Gmsh.y"
    {
      Surface *s;
      for(i=0;i<List_Nbr(yyvsp[-1].l);i++){
	List_Read(yyvsp[-1].l,i,&d);
	j = (int)d;
        s = FindSurface(j,THEM);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = 30.;
        }
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 329:
#line 2585 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    }
    break;

  case 330:
#line 2589 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    }
    break;

  case 331:
#line 2598 "Gmsh.y"
    {yyval.i = 1;}
    break;

  case 332:
#line 2599 "Gmsh.y"
    {yyval.i = 0;}
    break;

  case 333:
#line 2600 "Gmsh.y"
    {yyval.i = -1;}
    break;

  case 334:
#line 2601 "Gmsh.y"
    {yyval.i = -1;}
    break;

  case 335:
#line 2602 "Gmsh.y"
    {yyval.i = -1;}
    break;

  case 336:
#line 2606 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           }
    break;

  case 337:
#line 2607 "Gmsh.y"
    { yyval.d = yyvsp[-1].d ;          }
    break;

  case 338:
#line 2608 "Gmsh.y"
    { yyval.d = -yyvsp[0].d ;         }
    break;

  case 339:
#line 2609 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           }
    break;

  case 340:
#line 2610 "Gmsh.y"
    { yyval.d = !yyvsp[0].d ;         }
    break;

  case 341:
#line 2611 "Gmsh.y"
    { yyval.d = yyvsp[-2].d - yyvsp[0].d ;     }
    break;

  case 342:
#line 2612 "Gmsh.y"
    { yyval.d = yyvsp[-2].d + yyvsp[0].d ;     }
    break;

  case 343:
#line 2613 "Gmsh.y"
    { yyval.d = yyvsp[-2].d * yyvsp[0].d ;     }
    break;

  case 344:
#line 2615 "Gmsh.y"
    { 
      if(!yyvsp[0].d)
	yymsg(GERROR, "Division by zero in '%g / %g'", yyvsp[-2].d, yyvsp[0].d);
      else
	yyval.d = yyvsp[-2].d / yyvsp[0].d ;     
    }
    break;

  case 345:
#line 2621 "Gmsh.y"
    { yyval.d = (int)yyvsp[-2].d % (int)yyvsp[0].d ;  }
    break;

  case 346:
#line 2622 "Gmsh.y"
    { yyval.d = pow(yyvsp[-2].d,yyvsp[0].d) ;  }
    break;

  case 347:
#line 2623 "Gmsh.y"
    { yyval.d = yyvsp[-2].d < yyvsp[0].d ;     }
    break;

  case 348:
#line 2624 "Gmsh.y"
    { yyval.d = yyvsp[-2].d > yyvsp[0].d ;     }
    break;

  case 349:
#line 2625 "Gmsh.y"
    { yyval.d = yyvsp[-2].d <= yyvsp[0].d ;    }
    break;

  case 350:
#line 2626 "Gmsh.y"
    { yyval.d = yyvsp[-2].d >= yyvsp[0].d ;    }
    break;

  case 351:
#line 2627 "Gmsh.y"
    { yyval.d = yyvsp[-2].d == yyvsp[0].d ;    }
    break;

  case 352:
#line 2628 "Gmsh.y"
    { yyval.d = yyvsp[-2].d != yyvsp[0].d ;    }
    break;

  case 353:
#line 2629 "Gmsh.y"
    { yyval.d = yyvsp[-2].d && yyvsp[0].d ;    }
    break;

  case 354:
#line 2630 "Gmsh.y"
    { yyval.d = yyvsp[-2].d || yyvsp[0].d ;    }
    break;

  case 355:
#line 2631 "Gmsh.y"
    { yyval.d = yyvsp[-4].d? yyvsp[-2].d : yyvsp[0].d ; }
    break;

  case 356:
#line 2632 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      }
    break;

  case 357:
#line 2633 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      }
    break;

  case 358:
#line 2634 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    }
    break;

  case 359:
#line 2635 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     }
    break;

  case 360:
#line 2636 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      }
    break;

  case 361:
#line 2637 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     }
    break;

  case 362:
#line 2638 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      }
    break;

  case 363:
#line 2639 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     }
    break;

  case 364:
#line 2640 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      }
    break;

  case 365:
#line 2641 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     }
    break;

  case 366:
#line 2642 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d,yyvsp[-1].d); }
    break;

  case 367:
#line 2643 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     }
    break;

  case 368:
#line 2644 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     }
    break;

  case 369:
#line 2645 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     }
    break;

  case 370:
#line 2646 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     }
    break;

  case 371:
#line 2647 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    }
    break;

  case 372:
#line 2648 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     }
    break;

  case 373:
#line 2649 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d,yyvsp[-1].d);  }
    break;

  case 374:
#line 2650 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d,yyvsp[-1].d);  }
    break;

  case 375:
#line 2651 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); }
    break;

  case 376:
#line 2652 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; }
    break;

  case 377:
#line 2654 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      }
    break;

  case 378:
#line 2655 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      }
    break;

  case 379:
#line 2656 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    }
    break;

  case 380:
#line 2657 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     }
    break;

  case 381:
#line 2658 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      }
    break;

  case 382:
#line 2659 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     }
    break;

  case 383:
#line 2660 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      }
    break;

  case 384:
#line 2661 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     }
    break;

  case 385:
#line 2662 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      }
    break;

  case 386:
#line 2663 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     }
    break;

  case 387:
#line 2664 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d,yyvsp[-1].d); }
    break;

  case 388:
#line 2665 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     }
    break;

  case 389:
#line 2666 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     }
    break;

  case 390:
#line 2667 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     }
    break;

  case 391:
#line 2668 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     }
    break;

  case 392:
#line 2669 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    }
    break;

  case 393:
#line 2670 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     }
    break;

  case 394:
#line 2671 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d,yyvsp[-1].d);  }
    break;

  case 395:
#line 2672 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d,yyvsp[-1].d);  }
    break;

  case 396:
#line 2673 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); }
    break;

  case 397:
#line 2674 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; }
    break;

  case 398:
#line 2683 "Gmsh.y"
    { yyval.d = yyvsp[0].d; }
    break;

  case 399:
#line 2684 "Gmsh.y"
    { yyval.d = 3.141592653589793; }
    break;

  case 400:
#line 2685 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->rank(); }
    break;

  case 401:
#line 2686 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->size(); }
    break;

  case 402:
#line 2691 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[0].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[0].c) ;
	yyval.d = 0. ;
      }
      else
	yyval.d = *(double*)List_Pointer_Fast(pSymbol->val, 0) ;
    }
    break;

  case 403:
#line 2702 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-3].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-3].c) ;
	yyval.d = 0. ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)yyvsp[-1].d)))
	  yyval.d = *pd ;
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-3].c, (int)yyvsp[-1].d) ;
	  yyval.d = 0. ;
	}
      }
    }
    break;

  case 404:
#line 2719 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-1].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-1].c) ;
	yyval.d = 0. ;
      }
      else
	yyval.d = (*(double*)List_Pointer_Fast(pSymbol->val, 0) += yyvsp[0].i) ;
    }
    break;

  case 405:
#line 2730 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-4].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-4].c) ;
	yyval.d = 0. ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)yyvsp[-2].d)))
	  yyval.d = (*pd += yyvsp[0].i) ;
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-4].c, (int)yyvsp[-2].d) ;
	  yyval.d = 0. ;
	}
      }
    }
    break;

  case 406:
#line 2749 "Gmsh.y"
    {
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-2].c))){
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-2].c);
	yyval.d = 0. ;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[0].c, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", yyvsp[-2].c, yyvsp[0].c);
	  yyval.d = 0. ;
	}
	else
	  yyval.d = pNumOpt(0, GMSH_GET, 0);
      }
    }
    break;

  case 407:
#line 2765 "Gmsh.y"
    {
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-5].c))){
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-5].c);
	yyval.d = 0. ;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[0].c, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", yyvsp[-5].c, (int)yyvsp[-3].d, yyvsp[0].c);
	  yyval.d = 0. ;
	}
	else
	  yyval.d = pNumOpt((int)yyvsp[-3].d, GMSH_GET, 0);
      }
    }
    break;

  case 408:
#line 2781 "Gmsh.y"
    {
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-3].c))){
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-3].c);
	yyval.d = 0. ;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-1].c, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", yyvsp[-3].c, yyvsp[-1].c);
	  yyval.d = 0. ;
	}
	else
	  yyval.d = pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+yyvsp[0].i);
      }
    }
    break;

  case 409:
#line 2797 "Gmsh.y"
    {
      if(!(pNumCat = Get_NumberOptionCategory(yyvsp[-6].c))){
	yymsg(GERROR, "Unknown numeric option class '%s'", yyvsp[-6].c);
	yyval.d = 0. ;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption(yyvsp[-1].c, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-1].c);
	  yyval.d = 0. ;
	}
	else
	  yyval.d = pNumOpt((int)yyvsp[-4].d, GMSH_SET|GMSH_GUI, pNumOpt((int)yyvsp[-4].d, GMSH_GET, 0)+yyvsp[0].i);
      }
    }
    break;

  case 410:
#line 2815 "Gmsh.y"
    {
      memcpy(yyval.v, yyvsp[0].v, 5*sizeof(double)) ;
    }
    break;

  case 411:
#line 2819 "Gmsh.y"
    {
      for(i=0 ; i<5 ; i++) yyval.v[i] = -yyvsp[0].v[i] ;
    }
    break;

  case 412:
#line 2823 "Gmsh.y"
    { 
      for(i=0 ; i<5 ; i++) yyval.v[i] = yyvsp[0].v[i];
    }
    break;

  case 413:
#line 2827 "Gmsh.y"
    { 
      for(i=0 ; i<5 ; i++) yyval.v[i] = yyvsp[-2].v[i] - yyvsp[0].v[i] ;
    }
    break;

  case 414:
#line 2831 "Gmsh.y"
    {
      for(i=0 ; i<5 ; i++) yyval.v[i] = yyvsp[-2].v[i] + yyvsp[0].v[i] ;
    }
    break;

  case 415:
#line 2838 "Gmsh.y"
    { 
      yyval.v[0]=yyvsp[-9].d;  yyval.v[1]=yyvsp[-7].d;  yyval.v[2]=yyvsp[-5].d;  yyval.v[3]=yyvsp[-3].d; yyval.v[4]=yyvsp[-1].d;
    }
    break;

  case 416:
#line 2842 "Gmsh.y"
    { 
      yyval.v[0]=yyvsp[-7].d;  yyval.v[1]=yyvsp[-5].d;  yyval.v[2]=yyvsp[-3].d;  yyval.v[3]=yyvsp[-1].d; yyval.v[4]=1.0;
    }
    break;

  case 417:
#line 2846 "Gmsh.y"
    {
      yyval.v[0]=yyvsp[-5].d;  yyval.v[1]=yyvsp[-3].d;  yyval.v[2]=yyvsp[-1].d;  yyval.v[3]=0.0; yyval.v[4]=1.0;
    }
    break;

  case 418:
#line 2850 "Gmsh.y"
    {
      yyval.v[0]=yyvsp[-5].d;  yyval.v[1]=yyvsp[-3].d;  yyval.v[2]=yyvsp[-1].d;  yyval.v[3]=0.0; yyval.v[4]=1.0;
    }
    break;

  case 419:
#line 2857 "Gmsh.y"
    {
    }
    break;

  case 420:
#line 2860 "Gmsh.y"
    {
    }
    break;

  case 421:
#line 2866 "Gmsh.y"
    {
    }
    break;

  case 422:
#line 2869 "Gmsh.y"
    {
    }
    break;

  case 423:
#line 2875 "Gmsh.y"
    {
    }
    break;

  case 424:
#line 2878 "Gmsh.y"
    {
       yyval.l=yyvsp[-1].l;
    }
    break;

  case 425:
#line 2882 "Gmsh.y"
    {
       yyval.l=yyvsp[-1].l;
    }
    break;

  case 426:
#line 2889 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(List_T*)) ;
      List_Add(yyval.l, &(yyvsp[0].l)) ;
    }
    break;

  case 427:
#line 2894 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].l)) ;
    }
    break;

  case 428:
#line 2902 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      List_Add(yyval.l, &(yyvsp[0].d)) ;
    }
    break;

  case 429:
#line 2907 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l ;
    }
    break;

  case 430:
#line 2911 "Gmsh.y"
    {
      yyval.l=yyvsp[-1].l;
    }
    break;

  case 431:
#line 2915 "Gmsh.y"
    {
      yyval.l=yyvsp[-1].l;
      for(i=0 ; i<List_Nbr(yyval.l) ; i++){
	pd = (double*)List_Pointer(yyval.l, i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 432:
#line 2923 "Gmsh.y"
    {
    yyval.l = List_Create(List_Nbr(yyvsp[0].l),1,sizeof(double)) ;
    for (int i=0;i<List_Nbr(yyvsp[0].l);i++)
      {
	Shape *s = (Shape*) List_Pointer(yyvsp[0].l,i);
	double d = s->Num;
	List_Add(yyval.l,&d);
      }
  }
    break;

  case 433:
#line 2936 "Gmsh.y"
    { 
      yyval.l = List_Create(2,1,sizeof(double)) ; 
      for(d=yyvsp[-2].d ; (yyvsp[-2].d<yyvsp[0].d)?(d<=yyvsp[0].d):(d>=yyvsp[0].d) ; (yyvsp[-2].d<yyvsp[0].d)?(d+=1.):(d-=1.)) 
	List_Add(yyval.l, &d) ;
    }
    break;

  case 434:
#line 2942 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ; 
      if(!yyvsp[0].d || (yyvsp[-4].d<yyvsp[-2].d && yyvsp[0].d<0) || (yyvsp[-4].d>yyvsp[-2].d && yyvsp[0].d>0)){
        yymsg(GERROR, "Wrong increment in '%g:%g:%g'", yyvsp[-4].d, yyvsp[-2].d, yyvsp[0].d) ;
	List_Add(yyval.l, &(yyvsp[-4].d)) ;
      }
      else
	for(d=yyvsp[-4].d ; (yyvsp[0].d>0)?(d<=yyvsp[-2].d):(d>=yyvsp[-2].d) ; d+=yyvsp[0].d)
	  List_Add(yyval.l, &d) ;
   }
    break;

  case 435:
#line 2953 "Gmsh.y"
    {
      /// JF Remacle, sept. 2003
      /// returns the coordinates of a point 
      /// and fills a list with it
      /// This allows to ensure e.g. that relative
      /// point positions are always conserved 
      Vertex *v = FindPoint((int)yyvsp[-1].d,THEM);
      yyval.l = List_Create(3,1,sizeof(double)) ;      
      if (!v) {
	yymsg(GERROR, "Unknown point '%d'", (int) yyvsp[-1].d) ;
	double d = 0.0 ;
	List_Add(yyval.l, &d);
	List_Add(yyval.l, &d);
	List_Add(yyval.l, &d);
      }
      else{
	List_Add(yyval.l, &v->Pos.X) ;
	List_Add(yyval.l, &v->Pos.Y) ;
	List_Add(yyval.l, &v->Pos.Z) ;
      }
    }
    break;

  case 436:
#line 2975 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = yyvsp[-2].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c) ;
	d = 0.0 ;
	List_Add(yyval.l, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr(pSymbol->val) ; i++)
	  List_Add(yyval.l, (double*)List_Pointer_Fast(pSymbol->val, i)) ;
      }
    }
    break;

  case 437:
#line 2989 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = yyvsp[-2].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c) ;
	d = 0.0 ;
	List_Add(yyval.l, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr(pSymbol->val) ; i++){
	  d = - *(double*)List_Pointer_Fast(pSymbol->val, i);
	  List_Add(yyval.l, &d) ;
	}
      }
    }
    break;

  case 438:
#line 3005 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = yyvsp[-5].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-5].c) ;
	d = 0.0 ;
	List_Add(yyval.l, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr(yyvsp[-2].l) ; i++){
	  j = (int)(*(double*)List_Pointer_Fast(yyvsp[-2].l, i));
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j)))
	    List_Add(yyval.l, pd) ;
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-5].c, j) ;	  
	}
      }
      List_Delete(yyvsp[-2].l);
    }
    break;

  case 439:
#line 3025 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = yyvsp[-5].c ;
      if (!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-5].c) ;
	d = 0.0 ;
	List_Add(yyval.l, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr(yyvsp[-2].l) ; i++){
	  j = (int)(*(double*)List_Pointer_Fast(yyvsp[-2].l, i));
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	    d = - *pd;
	    List_Add(yyval.l, &d) ;
	  }
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", yyvsp[-5].c, j) ;	  
	}
      }
      List_Delete(yyvsp[-2].l);
    }
    break;

  case 440:
#line 3050 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      List_Add(yyval.l, &(yyvsp[0].d)) ;
    }
    break;

  case 441:
#line 3055 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l ;
    }
    break;

  case 442:
#line 3059 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].d)) ;
    }
    break;

  case 443:
#line 3063 "Gmsh.y"
    {
      for(i=0 ; i<List_Nbr(yyvsp[0].l) ; i++){
	List_Read(yyvsp[0].l, i, &d) ;
	List_Add(yyval.l, &d) ;
      }
      List_Delete(yyvsp[0].l);
    }
    break;

  case 444:
#line 3075 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-7].d, (int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d);
    }
    break;

  case 445:
#line 3079 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d, 255);
    }
    break;

  case 446:
#line 3090 "Gmsh.y"
    {
      yyval.u = Get_ColorForString(ColorString, -1, yyvsp[0].c, &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", yyvsp[0].c);
    }
    break;

  case 447:
#line 3095 "Gmsh.y"
    {
      if(!(pColCat = Get_ColorOptionCategory(yyvsp[-4].c))){
	yymsg(GERROR, "Unknown color option class '%s'", yyvsp[-4].c);
	yyval.u = 0 ;
      }
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption(yyvsp[0].c, pColCat))){
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", yyvsp[-4].c, yyvsp[0].c);
	  yyval.u = 0 ;
	}
	else{
	  yyval.u = pColOpt(0,GMSH_GET,0) ;
	}
      }
    }
    break;

  case 448:
#line 3114 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 449:
#line 3118 "Gmsh.y"
    {
      yyval.l = List_Create(256,10,sizeof(unsigned int)) ;
      GmshColorTable *ct = Get_ColorTable((int)yyvsp[-3].d);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)yyvsp[-3].d);
      else{
	for(i=0 ; i<ct->size ; i++) 
	  List_Add(yyval.l, &ct->table[i]);
      }
    }
    break;

  case 450:
#line 3132 "Gmsh.y"
    {
      yyval.l = List_Create(256,10,sizeof(unsigned int)) ;
      List_Add(yyval.l, &(yyvsp[0].u)) ;
    }
    break;

  case 451:
#line 3137 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].u)) ;
    }
    break;

  case 452:
#line 3144 "Gmsh.y"
    {
      yyval.c = yyvsp[0].c;
    }
    break;

  case 453:
#line 3148 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-3].c)+strlen(yyvsp[-1].c)+1)*sizeof(char)) ;
      strcpy(yyval.c, yyvsp[-3].c) ;  
      strcat(yyval.c, yyvsp[-1].c) ;
      Free(yyvsp[-3].c);
      Free(yyvsp[-1].c);
    }
    break;

  case 454:
#line 3156 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-1].c)+1)*sizeof(char)) ;
      for(i=strlen(yyvsp[-1].c)-1; i>=0; i--){
	if(yyvsp[-1].c[i] == '.'){
	  strncpy(yyval.c,yyvsp[-1].c,i);
	  yyval.c[i]='\0';
	  break;
	}
      }
      if(i<=0) strcpy(yyval.c,yyvsp[-1].c);
      Free(yyvsp[-1].c);
    }
    break;

  case 455:
#line 3169 "Gmsh.y"
    {
      yyval.c = yyvsp[-1].c;
    }
    break;

  case 456:
#line 3173 "Gmsh.y"
    {
      i = PrintListOfDouble(yyvsp[-3].c,yyvsp[-1].l,tmpstring);
      if(i<0){
	yymsg(GERROR, "Too few arguments in Sprintf");
	yyval.c = yyvsp[-3].c;
      }
      else if(i>0){
	yymsg(GERROR, "Too many arguments (%d) in Sprintf", i);
	yyval.c = yyvsp[-3].c;
      }
      else{
	yyval.c = (char*)Malloc((strlen(tmpstring)+1)*sizeof(char));
	strcpy(yyval.c, tmpstring);
	Free(yyvsp[-3].c);
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 457:
#line 3191 "Gmsh.y"
    { 
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-3].c)))
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-3].c);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-1].c, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", yyvsp[-3].c, yyvsp[-1].c);
	else{
	  str = pStrOpt(0,GMSH_GET,NULL) ;
	  yyval.c = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy(yyval.c, str);
	}
      }
    }
    break;

  case 458:
#line 3205 "Gmsh.y"
    { 
      if(!(pStrCat = Get_StringOptionCategory(yyvsp[-6].c)))
	yymsg(GERROR, "Unknown string option class '%s'", yyvsp[-6].c);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption(yyvsp[-1].c, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", yyvsp[-6].c, (int)yyvsp[-4].d, yyvsp[-1].c);
	else{
	  str = pStrOpt((int)yyvsp[-4].d,GMSH_GET,NULL) ;
	  yyval.c = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy(yyval.c, str);
	}
      }
    }
    break;


    }

/* Line 1016 of /usr/share/bison/yacc.c.  */
#line 9198 "Gmsh.tab.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

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
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
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
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
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
	  while (yyssp > yyss)
	    {
	      YYDPRINTF ((stderr, "Error: popping "));
	      YYDSYMPRINT ((stderr,
			    yystos[*yyssp],
			    *yyvsp));
	      YYDPRINTF ((stderr, "\n"));
	      yydestruct (yystos[*yyssp], *yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yydestruct (yychar1, yylval);
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

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

      YYDPRINTF ((stderr, "Error: popping "));
      YYDSYMPRINT ((stderr,
		    yystos[*yyssp], *yyvsp));
      YYDPRINTF ((stderr, "\n"));

      yydestruct (yystos[yystate], *yyvsp);
      yyvsp--;
      yystate = *--yyssp;


#if YYDEBUG
      if (yydebug)
	{
	  short *yyssp1 = yyss - 1;
	  YYFPRINTF (stderr, "Error: state stack now");
	  while (yyssp1 != yyssp)
	    YYFPRINTF (stderr, " %d", *++yyssp1);
	  YYFPRINTF (stderr, "\n");
	}
#endif
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


#line 3220 "Gmsh.y"


void DeleteSymbol(void *a, void *b){
  Symbol *s = (Symbol*)a;
  Free(s->Name);
  List_Delete(s->val);
}

int CompareSymbols (const void *a, const void *b){
  return(strcmp(((Symbol*)a)->Name,((Symbol*)b)->Name));
}

void InitSymbols(void){
  if(Symbol_T){
    Tree_Action(Symbol_T, DeleteSymbol);
    Tree_Delete(Symbol_T);
  }
  Symbol_T = Tree_Create(sizeof(Symbol), CompareSymbols);
}

int PrintListOfDouble(char *format, List_T *list, char *buffer){
  int i, j, k;
  char tmp1[256], tmp2[256];

  j=0;
  while(format[j]!='%') j++;
  strncpy(buffer, format, j); 
  buffer[j]='\0'; 
  for(i = 0 ; i<List_Nbr(list) ; i++){
    k = j;
    j++;
    if(j<(int)strlen(format)){
      if(format[j]=='%'){
	strcat(buffer, "%");
	j++;
      }
      while(format[j]!='%' && j<(int)strlen(format)) j++;
      if(k != j){
	strncpy(tmp1, &(format[k]),j-k);
	tmp1[j-k]='\0';
	sprintf(tmp2, tmp1, *(double*)List_Pointer(list,i)); 
	strcat(buffer, tmp2);
      }
    }
    else{
      return List_Nbr(list)-i;
      break ;
    }
  }
  if(j != (int)strlen(format))
    return -1;
  return 0;
}

void yyerror(char *s){
  Msg(GERROR, "'%s', line %d : %s (%s)",yyname,yylineno-1,s,yytext);
  yyerrorstate=1;
}

void yymsg(int type, char *fmt, ...){
  va_list args;
  char tmp[1024];

  va_start (args, fmt);
  vsprintf (tmp, fmt, args);
  va_end (args);

  Msg(type, "'%s', line %d : %s", yyname, yylineno-1, tmp);

  if(type == GERROR) yyerrorstate=1;
}



