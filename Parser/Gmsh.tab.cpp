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
     tTransfinite = 306,
     tComplex = 307,
     tPhysical = 308,
     tUsing = 309,
     tBump = 310,
     tProgression = 311,
     tPlugin = 312,
     tRotate = 313,
     tTranslate = 314,
     tSymmetry = 315,
     tDilate = 316,
     tExtrude = 317,
     tDuplicata = 318,
     tLoop = 319,
     tRecombine = 320,
     tDelete = 321,
     tCoherence = 322,
     tIntersect = 323,
     tAttractor = 324,
     tLayers = 325,
     tScalarPoint = 326,
     tVectorPoint = 327,
     tTensorPoint = 328,
     tScalarLine = 329,
     tVectorLine = 330,
     tTensorLine = 331,
     tScalarTriangle = 332,
     tVectorTriangle = 333,
     tTensorTriangle = 334,
     tScalarQuadrangle = 335,
     tVectorQuadrangle = 336,
     tTensorQuadrangle = 337,
     tScalarTetrahedron = 338,
     tVectorTetrahedron = 339,
     tTensorTetrahedron = 340,
     tScalarHexahedron = 341,
     tVectorHexahedron = 342,
     tTensorHexahedron = 343,
     tScalarPrism = 344,
     tVectorPrism = 345,
     tTensorPrism = 346,
     tScalarPyramid = 347,
     tVectorPyramid = 348,
     tTensorPyramid = 349,
     tText2D = 350,
     tText3D = 351,
     tBSpline = 352,
     tBezier = 353,
     tNurbs = 354,
     tOrder = 355,
     tWith = 356,
     tBounds = 357,
     tKnots = 358,
     tColor = 359,
     tColorTable = 360,
     tFor = 361,
     tIn = 362,
     tEndFor = 363,
     tIf = 364,
     tEndIf = 365,
     tExit = 366,
     tReturn = 367,
     tCall = 368,
     tFunction = 369,
     tMesh = 370,
     tB_SPLINE_SURFACE_WITH_KNOTS = 371,
     tB_SPLINE_CURVE_WITH_KNOTS = 372,
     tCARTESIAN_POINT = 373,
     tTRUE = 374,
     tFALSE = 375,
     tUNSPECIFIED = 376,
     tU = 377,
     tV = 378,
     tEDGE_CURVE = 379,
     tVERTEX_POINT = 380,
     tORIENTED_EDGE = 381,
     tPLANE = 382,
     tFACE_OUTER_BOUND = 383,
     tEDGE_LOOP = 384,
     tADVANCED_FACE = 385,
     tVECTOR = 386,
     tDIRECTION = 387,
     tAXIS2_PLACEMENT_3D = 388,
     tISO = 389,
     tENDISO = 390,
     tENDSEC = 391,
     tDATA = 392,
     tHEADER = 393,
     tFILE_DESCRIPTION = 394,
     tFILE_SCHEMA = 395,
     tFILE_NAME = 396,
     tMANIFOLD_SOLID_BREP = 397,
     tCLOSED_SHELL = 398,
     tADVANCED_BREP_SHAPE_REPRESENTATION = 399,
     tFACE_BOUND = 400,
     tCYLINDRICAL_SURFACE = 401,
     tCONICAL_SURFACE = 402,
     tCIRCLE = 403,
     tTRIMMED_CURVE = 404,
     tGEOMETRIC_SET = 405,
     tCOMPOSITE_CURVE_SEGMENT = 406,
     tCONTINUOUS = 407,
     tCOMPOSITE_CURVE = 408,
     tTOROIDAL_SURFACE = 409,
     tPRODUCT_DEFINITION = 410,
     tPRODUCT_DEFINITION_SHAPE = 411,
     tSHAPE_DEFINITION_REPRESENTATION = 412,
     tELLIPSE = 413,
     tTrimmed = 414,
     tSolid = 415,
     tEndSolid = 416,
     tVertex = 417,
     tFacet = 418,
     tNormal = 419,
     tOuter = 420,
     tLoopSTL = 421,
     tEndLoop = 422,
     tEndFacet = 423,
     tAFFECTDIVIDE = 424,
     tAFFECTTIMES = 425,
     tAFFECTMINUS = 426,
     tAFFECTPLUS = 427,
     tOR = 428,
     tAND = 429,
     tAPPROXEQUAL = 430,
     tNOTEQUAL = 431,
     tEQUAL = 432,
     tGREATEROREQUAL = 433,
     tLESSOREQUAL = 434,
     tCROSSPRODUCT = 435,
     UNARYPREC = 436,
     tMINUSMINUS = 437,
     tPLUSPLUS = 438
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
#define tTransfinite 306
#define tComplex 307
#define tPhysical 308
#define tUsing 309
#define tBump 310
#define tProgression 311
#define tPlugin 312
#define tRotate 313
#define tTranslate 314
#define tSymmetry 315
#define tDilate 316
#define tExtrude 317
#define tDuplicata 318
#define tLoop 319
#define tRecombine 320
#define tDelete 321
#define tCoherence 322
#define tIntersect 323
#define tAttractor 324
#define tLayers 325
#define tScalarPoint 326
#define tVectorPoint 327
#define tTensorPoint 328
#define tScalarLine 329
#define tVectorLine 330
#define tTensorLine 331
#define tScalarTriangle 332
#define tVectorTriangle 333
#define tTensorTriangle 334
#define tScalarQuadrangle 335
#define tVectorQuadrangle 336
#define tTensorQuadrangle 337
#define tScalarTetrahedron 338
#define tVectorTetrahedron 339
#define tTensorTetrahedron 340
#define tScalarHexahedron 341
#define tVectorHexahedron 342
#define tTensorHexahedron 343
#define tScalarPrism 344
#define tVectorPrism 345
#define tTensorPrism 346
#define tScalarPyramid 347
#define tVectorPyramid 348
#define tTensorPyramid 349
#define tText2D 350
#define tText3D 351
#define tBSpline 352
#define tBezier 353
#define tNurbs 354
#define tOrder 355
#define tWith 356
#define tBounds 357
#define tKnots 358
#define tColor 359
#define tColorTable 360
#define tFor 361
#define tIn 362
#define tEndFor 363
#define tIf 364
#define tEndIf 365
#define tExit 366
#define tReturn 367
#define tCall 368
#define tFunction 369
#define tMesh 370
#define tB_SPLINE_SURFACE_WITH_KNOTS 371
#define tB_SPLINE_CURVE_WITH_KNOTS 372
#define tCARTESIAN_POINT 373
#define tTRUE 374
#define tFALSE 375
#define tUNSPECIFIED 376
#define tU 377
#define tV 378
#define tEDGE_CURVE 379
#define tVERTEX_POINT 380
#define tORIENTED_EDGE 381
#define tPLANE 382
#define tFACE_OUTER_BOUND 383
#define tEDGE_LOOP 384
#define tADVANCED_FACE 385
#define tVECTOR 386
#define tDIRECTION 387
#define tAXIS2_PLACEMENT_3D 388
#define tISO 389
#define tENDISO 390
#define tENDSEC 391
#define tDATA 392
#define tHEADER 393
#define tFILE_DESCRIPTION 394
#define tFILE_SCHEMA 395
#define tFILE_NAME 396
#define tMANIFOLD_SOLID_BREP 397
#define tCLOSED_SHELL 398
#define tADVANCED_BREP_SHAPE_REPRESENTATION 399
#define tFACE_BOUND 400
#define tCYLINDRICAL_SURFACE 401
#define tCONICAL_SURFACE 402
#define tCIRCLE 403
#define tTRIMMED_CURVE 404
#define tGEOMETRIC_SET 405
#define tCOMPOSITE_CURVE_SEGMENT 406
#define tCONTINUOUS 407
#define tCOMPOSITE_CURVE 408
#define tTOROIDAL_SURFACE 409
#define tPRODUCT_DEFINITION 410
#define tPRODUCT_DEFINITION_SHAPE 411
#define tSHAPE_DEFINITION_REPRESENTATION 412
#define tELLIPSE 413
#define tTrimmed 414
#define tSolid 415
#define tEndSolid 416
#define tVertex 417
#define tFacet 418
#define tNormal 419
#define tOuter 420
#define tLoopSTL 421
#define tEndLoop 422
#define tEndFacet 423
#define tAFFECTDIVIDE 424
#define tAFFECTTIMES 425
#define tAFFECTMINUS 426
#define tAFFECTPLUS 427
#define tOR 428
#define tAND 429
#define tAPPROXEQUAL 430
#define tNOTEQUAL 431
#define tEQUAL 432
#define tGREATEROREQUAL 433
#define tLESSOREQUAL 434
#define tCROSSPRODUCT 435
#define UNARYPREC 436
#define tMINUSMINUS 437
#define tPLUSPLUS 438




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"
 

// $Id: Gmsh.tab.cpp,v 1.148 2003-01-24 23:13:35 geuzaine Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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
#ifndef _NOPLUGIN
#include "PluginManager.h"
#endif
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
#include "FunctionManager.h"
#include "ColorTable.h"
#include "Timer.h"
#include "CreateFile.h"
#include "STL.h"

#ifdef __DECCXX // bug in bison
#include <alloca.h>
#endif

List_T *Symbol_L=NULL;

extern Context_T  CTX;
extern Mesh      *THEM;

static FILE          *yyinTab[MAX_OPEN_FILES];
static int            yylinenoTab[MAX_OPEN_FILES];
static fpos_t         yyposImbricatedLoopsTab[MAX_OPEN_FILES];
static int            yylinenoImbricatedLoopsTab[MAX_OPEN_FILES];
static double         LoopControlVariablesTab[MAX_OPEN_FILES][3];
static char*          LoopControlVariablesNameTab[MAX_OPEN_FILES];
static char           yynameTab[MAX_OPEN_FILES][256];
static char           tmpstring[1024];
static Symbol         TheSymbol, *pSymbol;
static Surface       *STL_Surf;
static Shape          TheShape;
static int            i,j,k,flag,RecursionLevel=0,ImbricatedLoop = 0;
static int            Last_NumberOfPoints = 0;
static double         d, *pd;
static ExtrudeParams  extr;
static char           *str;
static StringXString  *pStrCat;
static StringXNumber  *pNumCat;
static StringXColor   *pColCat;
static double         (*pNumOpt)(int num, int action, double value);
static char*          (*pStrOpt)(int num, int action, char *value);
static unsigned int   (*pColOpt)(int num, int action, unsigned int value);
static Post_View      *View;

char *strsave(char *ptr);
void  yyerror (char *s);
void  yymsg (int type, char *fmt, ...);
void  skip_until (char *skip, char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);


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
#line 90 "Gmsh.y"
typedef union {
  char    *c;
  int      i;
  unsigned int u;
  double   d;
  double   v[5];
  Shape    s;
  List_T  *l;
} yystype;
/* Line 193 of /usr/share/bison/yacc.c.  */
#line 538 "Gmsh.tab.cpp"
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
#line 559 "Gmsh.tab.cpp"

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
#define YYLAST   13072

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  202
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  131
/* YYNRULES -- Number of rules. */
#define YYNRULES  449
/* YYNRULES -- Number of states. */
#define YYNSTATES  2257

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   438

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   189,     2,     2,     2,   187,     2,     2,
     194,   195,   185,   183,   199,   184,   198,   186,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     179,     2,   180,   173,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   196,     2,   197,   193,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   200,     2,   201,     2,     2,     2,     2,
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
     165,   166,   167,   168,   169,   170,   171,   172,   174,   175,
     176,   177,   178,   181,   182,   188,   190,   191,   192
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
    1909,  1918,  1927,  1935,  1943,  1955,  1964,  1977,  1986,  2009,
    2030,  2039,  2048,  2057,  2065,  2074,  2080,  2092,  2098,  2108,
    2110,  2112,  2114,  2115,  2118,  2125,  2132,  2139,  2144,  2151,
    2156,  2163,  2167,  2173,  2177,  2181,  2189,  2192,  2195,  2202,
    2211,  2220,  2231,  2233,  2236,  2238,  2242,  2247,  2249,  2258,
    2271,  2286,  2295,  2308,  2323,  2324,  2337,  2338,  2355,  2356,
    2375,  2384,  2397,  2412,  2413,  2426,  2427,  2444,  2445,  2464,
    2466,  2469,  2479,  2487,  2490,  2497,  2507,  2517,  2526,  2535,
    2544,  2551,  2556,  2559,  2562,  2564,  2566,  2568,  2570,  2572,
    2574,  2578,  2581,  2584,  2587,  2591,  2595,  2599,  2603,  2607,
    2611,  2615,  2619,  2623,  2627,  2631,  2635,  2639,  2643,  2649,
    2654,  2659,  2664,  2669,  2674,  2679,  2684,  2689,  2694,  2699,
    2706,  2711,  2716,  2721,  2726,  2731,  2736,  2743,  2750,  2757,
    2762,  2767,  2772,  2777,  2782,  2787,  2792,  2797,  2802,  2807,
    2812,  2819,  2824,  2829,  2834,  2839,  2844,  2849,  2856,  2863,
    2870,  2875,  2877,  2879,  2881,  2883,  2885,  2890,  2893,  2899,
    2903,  2910,  2915,  2923,  2925,  2928,  2931,  2935,  2939,  2951,
    2961,  2969,  2977,  2978,  2982,  2984,  2988,  2989,  2993,  2997,
    2999,  3003,  3005,  3007,  3011,  3016,  3020,  3026,  3030,  3035,
    3042,  3050,  3052,  3054,  3058,  3062,  3072,  3080,  3082,  3088,
    3092,  3099,  3101,  3105,  3107,  3114,  3119,  3124,  3131,  3138
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     203,     0,    -1,   206,    -1,   205,    -1,   211,    -1,     1,
       6,    -1,     3,    -1,   184,     3,    -1,   160,    -1,   163,
     164,   204,   204,   204,   165,   166,   162,   204,   204,   204,
     162,   204,   204,   204,   162,   204,   204,   204,   167,   168,
      -1,   161,    -1,    -1,   206,   207,    -1,   208,    -1,   210,
      -1,   209,    -1,   134,     6,    -1,   135,     6,    -1,   137,
       6,    -1,   136,     6,    -1,   138,     6,    -1,   139,   194,
     322,   199,     5,   195,     6,    -1,   140,   194,   322,   195,
       6,    -1,   141,   194,     5,   199,     5,   199,   322,   199,
     322,   199,     5,   199,     5,   199,     5,   195,     6,    -1,
       3,     7,   118,   194,     5,   199,   320,   195,     6,    -1,
       3,     7,   117,   194,     5,   199,   318,   199,   326,   199,
     317,   199,   317,   199,   317,   199,   326,   199,   326,   199,
     317,   195,     6,    -1,     3,     7,   116,   194,     5,   199,
     318,   199,   318,   199,   324,   199,   317,   199,   317,   199,
     317,   199,   317,   199,   326,   199,   326,   199,   326,   199,
     326,   199,   317,   195,     6,    -1,     3,     7,   124,   194,
       5,   199,     3,   199,     3,   199,     3,   199,   317,   195,
       6,    -1,     3,     7,   128,   194,     5,   199,     3,   199,
     317,   195,     6,    -1,     3,     7,   145,   194,     5,   199,
       3,   199,   317,   195,     6,    -1,     3,     7,   126,   194,
       5,   199,   185,   199,   185,   199,   318,   199,   317,   195,
       6,    -1,     3,     7,   129,   194,     5,   199,   326,   195,
       6,    -1,     3,     7,   130,   194,     5,   199,   326,   199,
       3,   199,   317,   195,     6,    -1,     3,     7,   125,   194,
       5,   199,     3,   195,     6,    -1,     3,     7,   131,   194,
       5,   199,     3,   199,   318,   195,     6,    -1,     3,     7,
     133,   194,     5,   199,     3,   199,     3,   199,     3,   195,
       6,    -1,     3,     7,   132,   194,     5,   199,   320,   195,
       6,    -1,     3,     7,   127,   194,     5,   199,     3,   195,
       6,    -1,     3,     7,    41,   194,     5,   199,     3,   199,
       3,   195,     6,    -1,     3,     7,   143,   194,     5,   199,
     326,   195,     6,    -1,     3,     7,   144,   194,     5,   199,
     326,   199,     3,   195,     6,    -1,     3,     7,   142,   194,
       5,   199,     3,   195,     6,    -1,     3,     7,   146,   194,
       5,   199,     3,   199,   318,   195,     6,    -1,     3,     7,
     147,   194,     5,   199,     3,   199,   318,   199,   318,   195,
       6,    -1,     3,     7,   154,   194,     5,   199,     3,   199,
     318,   199,   318,   195,     6,    -1,     3,     7,   148,   194,
       5,   199,     3,   199,   318,   195,     6,    -1,     3,     7,
     158,   194,     5,   199,     3,   199,   318,   199,   318,   195,
       6,    -1,     3,     7,   149,   194,     5,   199,     3,   199,
     326,   199,   326,   199,   317,   199,   317,   195,     6,    -1,
       3,     7,   150,   194,     5,   199,   326,   195,     6,    -1,
       3,     7,   151,   194,   152,   199,   317,   199,     3,   195,
       6,    -1,     3,     7,   153,   194,     5,   199,   326,   199,
     317,   195,     6,    -1,     3,     7,   155,   194,     5,   199,
       5,   199,     3,   199,     3,   195,     6,    -1,     3,     7,
     156,   194,     5,   199,     5,   199,     3,   195,     6,    -1,
       3,     7,   157,   194,     3,   199,     3,   195,     6,    -1,
      -1,   211,   212,    -1,   214,    -1,   213,    -1,   296,    -1,
     297,    -1,   298,    -1,   301,    -1,   302,    -1,   303,    -1,
     306,    -1,   315,    -1,   316,    -1,   305,    -1,   304,    -1,
      33,   194,     5,   195,     6,    -1,    33,   194,     5,   199,
     328,   195,     6,    -1,     4,     5,   200,   215,   201,     6,
      -1,     4,     5,     4,   320,   200,   215,   201,     6,    -1,
      -1,   215,   217,    -1,   215,   220,    -1,   215,   223,    -1,
     215,   226,    -1,   215,   229,    -1,   215,   232,    -1,   215,
     235,    -1,   215,   238,    -1,   215,   241,    -1,   215,   244,
      -1,   215,   247,    -1,   215,   250,    -1,   215,   253,    -1,
     215,   256,    -1,   215,   259,    -1,   215,   262,    -1,   215,
     265,    -1,   215,   268,    -1,   215,   271,    -1,   215,   274,
      -1,   215,   277,    -1,   215,   280,    -1,   215,   283,    -1,
     215,   286,    -1,   215,   289,    -1,   215,   292,    -1,   318,
      -1,   216,   199,   318,    -1,    -1,    71,   194,   318,   199,
     318,   199,   318,   195,   218,   200,   216,   201,     6,    -1,
     318,    -1,   219,   199,   318,    -1,    -1,    72,   194,   318,
     199,   318,   199,   318,   195,   221,   200,   219,   201,     6,
      -1,   318,    -1,   222,   199,   318,    -1,    -1,    73,   194,
     318,   199,   318,   199,   318,   195,   224,   200,   222,   201,
       6,    -1,   318,    -1,   225,   199,   318,    -1,    -1,    74,
     194,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   195,   227,   200,   225,   201,     6,    -1,   318,
      -1,   228,   199,   318,    -1,    -1,    75,   194,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   195,
     230,   200,   228,   201,     6,    -1,   318,    -1,   231,   199,
     318,    -1,    -1,    76,   194,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   195,   233,   200,   231,
     201,     6,    -1,   318,    -1,   234,   199,   318,    -1,    -1,
      77,   194,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   195,
     236,   200,   234,   201,     6,    -1,   318,    -1,   237,   199,
     318,    -1,    -1,    78,   194,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   195,   239,   200,   237,   201,     6,    -1,   318,
      -1,   240,   199,   318,    -1,    -1,    79,   194,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   195,   242,   200,   240,   201,
       6,    -1,   318,    -1,   243,   199,   318,    -1,    -1,    80,
     194,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   195,   245,   200,   243,   201,     6,
      -1,   318,    -1,   246,   199,   318,    -1,    -1,    81,   194,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   195,   248,   200,   246,   201,     6,    -1,
     318,    -1,   249,   199,   318,    -1,    -1,    82,   194,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   195,   251,   200,   249,   201,     6,    -1,   318,
      -1,   252,   199,   318,    -1,    -1,    83,   194,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   195,   254,   200,   252,   201,     6,    -1,   318,    -1,
     255,   199,   318,    -1,    -1,    84,   194,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     195,   257,   200,   255,   201,     6,    -1,   318,    -1,   258,
     199,   318,    -1,    -1,    85,   194,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   195,
     260,   200,   258,   201,     6,    -1,   318,    -1,   261,   199,
     318,    -1,    -1,    86,   194,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   195,   263,   200,   261,   201,     6,    -1,   318,
      -1,   264,   199,   318,    -1,    -1,    87,   194,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   195,   266,   200,   264,   201,
       6,    -1,   318,    -1,   267,   199,   318,    -1,    -1,    88,
     194,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   195,   269,
     200,   267,   201,     6,    -1,   318,    -1,   270,   199,   318,
      -1,    -1,    89,   194,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   195,
     272,   200,   270,   201,     6,    -1,   318,    -1,   273,   199,
     318,    -1,    -1,    90,   194,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     195,   275,   200,   273,   201,     6,    -1,   318,    -1,   276,
     199,   318,    -1,    -1,    91,   194,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   195,   278,   200,   276,   201,     6,    -1,   318,    -1,
     279,   199,   318,    -1,    -1,    92,   194,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   195,   281,   200,   279,
     201,     6,    -1,   318,    -1,   282,   199,   318,    -1,    -1,
      93,   194,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   199,
     318,   195,   284,   200,   282,   201,     6,    -1,   318,    -1,
     285,   199,   318,    -1,    -1,    94,   194,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   199,   318,   199,   318,
     199,   318,   199,   318,   199,   318,   195,   287,   200,   285,
     201,     6,    -1,   332,    -1,   288,   199,   332,    -1,    -1,
      95,   194,   318,   199,   318,   199,   318,   195,   290,   200,
     288,   201,     6,    -1,   332,    -1,   291,   199,   332,    -1,
      -1,    96,   194,   318,   199,   318,   199,   318,   199,   318,
     195,   293,   200,   291,   201,     6,    -1,     7,    -1,   172,
      -1,   171,    -1,   170,    -1,   169,    -1,   192,    -1,   191,
      -1,     4,   294,   318,     6,    -1,     4,   196,   318,   197,
     294,   318,     6,    -1,     4,   196,   200,   328,   201,   197,
     294,   326,     6,    -1,     4,   196,   197,     7,   326,     6,
      -1,     4,   295,     6,    -1,     4,   196,   318,   197,   295,
       6,    -1,     4,   198,     4,     7,   332,     6,    -1,     4,
     196,   318,   197,   198,     4,     7,   332,     6,    -1,     4,
     198,     4,   294,   318,     6,    -1,     4,   196,   318,   197,
     198,     4,   294,   318,     6,    -1,     4,   198,     4,   295,
       6,    -1,     4,   196,   318,   197,   198,     4,   295,     6,
      -1,     4,   198,   104,   198,     4,     7,   329,     6,    -1,
       4,   196,   318,   197,   198,   104,   198,     4,     7,   329,
       6,    -1,     4,   198,   105,     7,   330,     6,    -1,     4,
     196,   318,   197,   198,   105,     7,   330,     6,    -1,    57,
     194,     4,   195,   198,     4,     7,   318,     6,    -1,    57,
     194,     4,   195,   198,     4,     7,   332,     6,    -1,    38,
     194,   318,   195,     7,   320,     6,    -1,    53,    38,   194,
     318,   195,     7,   326,     6,    -1,    69,    38,   326,     7,
     200,   318,   199,   318,   199,   318,   201,     6,    -1,    45,
      46,   326,     7,   318,     6,    -1,    41,   194,   318,   195,
       7,   326,     6,    -1,    43,   194,   318,   195,     7,   326,
       6,    -1,    69,    41,   326,     7,   200,   318,   199,   318,
     199,   318,   201,     6,    -1,    39,   194,   318,   195,     7,
     326,     6,    -1,    40,   194,   318,   195,     7,   326,     6,
      -1,    39,   194,   318,   195,     7,   326,    49,   320,     6,
      -1,    47,   194,   318,   195,     7,   200,   318,   199,   318,
     199,     5,   199,     5,   199,     5,   201,     6,    -1,    53,
      41,   194,   318,   195,     7,   326,     6,    -1,    41,    64,
     194,   318,   195,     7,   326,     6,    -1,    97,   194,   318,
     195,     7,   326,     6,    -1,    98,   194,   318,   195,     7,
     326,     6,    -1,    99,   194,   318,   195,     7,   326,   103,
     326,   100,   318,     6,    -1,    49,    42,   194,   318,   195,
       7,   326,     6,    -1,   159,    42,   194,   318,   195,     7,
     200,   318,   199,   326,   201,     6,    -1,    50,    42,   194,
     318,   195,     7,   326,     6,    -1,    99,    42,   101,   102,
     194,   318,   195,     7,   324,   103,   200,   326,   199,   326,
     201,   100,   200,   318,   199,   318,   201,     6,    -1,    99,
      42,   194,   318,   195,     7,   324,   103,   200,   326,   199,
     326,   201,   100,   200,   318,   199,   318,   201,     6,    -1,
      53,    42,   194,   318,   195,     7,   326,     6,    -1,    42,
      64,   194,   318,   195,     7,   326,     6,    -1,    52,    44,
     194,   318,   195,     7,   326,     6,    -1,    44,   194,   318,
     195,     7,   326,     6,    -1,    53,    44,   194,   318,   195,
       7,   326,     6,    -1,    59,   320,   200,   299,   201,    -1,
      58,   200,   320,   199,   320,   199,   318,   201,   200,   299,
     201,    -1,    60,   320,   200,   299,   201,    -1,    61,   200,
     320,   199,   318,   201,   200,   299,   201,    -1,   301,    -1,
     300,    -1,   298,    -1,    -1,   300,   297,    -1,   300,    38,
     200,   328,   201,     6,    -1,   300,    41,   200,   328,   201,
       6,    -1,   300,    42,   200,   328,   201,     6,    -1,    63,
     200,   300,   201,    -1,    63,     4,   196,   318,   197,     6,
      -1,    66,   200,   300,   201,    -1,    66,     4,   196,   318,
     197,     6,    -1,    66,   115,     6,    -1,   104,   329,   200,
     300,   201,    -1,     4,   332,     6,    -1,     4,   318,     6,
      -1,    57,   194,     4,   195,   198,     4,     6,    -1,   111,
       6,    -1,    37,     6,    -1,   106,   194,   318,     8,   318,
     195,    -1,   106,   194,   318,     8,   318,     8,   318,   195,
      -1,   106,     4,   107,   200,   318,     8,   318,   201,    -1,
     106,     4,   107,   200,   318,     8,   318,     8,   318,   201,
      -1,   108,    -1,   114,     4,    -1,   112,    -1,   113,     4,
       6,    -1,   109,   194,   318,   195,    -1,   110,    -1,    62,
      38,   200,   318,   199,   320,   201,     6,    -1,    62,    38,
     200,   318,   199,   320,   199,   320,   199,   318,   201,     6,
      -1,    62,    38,   200,   318,   199,   320,   199,   320,   199,
     320,   199,   318,   201,     6,    -1,    62,    41,   200,   318,
     199,   320,   201,     6,    -1,    62,    41,   200,   318,   199,
     320,   199,   320,   199,   318,   201,     6,    -1,    62,    41,
     200,   318,   199,   320,   199,   320,   199,   320,   199,   318,
     201,     6,    -1,    -1,    62,    41,   200,   318,   199,   320,
     201,   307,   200,   313,   201,     6,    -1,    -1,    62,    41,
     200,   318,   199,   320,   199,   320,   199,   318,   201,   308,
     200,   313,   201,     6,    -1,    -1,    62,    41,   200,   318,
     199,   320,   199,   320,   199,   320,   199,   318,   201,   309,
     200,   313,   201,     6,    -1,    62,    42,   200,   318,   199,
     320,   201,     6,    -1,    62,    42,   200,   318,   199,   320,
     199,   320,   199,   318,   201,     6,    -1,    62,    42,   200,
     318,   199,   320,   199,   320,   199,   320,   199,   318,   201,
       6,    -1,    -1,    62,    42,   200,   318,   199,   320,   201,
     310,   200,   313,   201,     6,    -1,    -1,    62,    42,   200,
     318,   199,   320,   199,   320,   199,   318,   201,   311,   200,
     313,   201,     6,    -1,    -1,    62,    42,   200,   318,   199,
     320,   199,   320,   199,   320,   199,   318,   201,   312,   200,
     313,   201,     6,    -1,   314,    -1,   313,   314,    -1,    70,
     200,   326,   199,   326,   199,   326,   201,     6,    -1,    70,
     200,   326,   199,   326,   201,     6,    -1,    65,     6,    -1,
      51,    41,   326,     7,   318,     6,    -1,    51,    41,   326,
       7,   318,    54,    56,   318,     6,    -1,    51,    41,   326,
       7,   318,    54,    55,   318,     6,    -1,    51,    42,   200,
     318,   201,     7,   326,     6,    -1,    48,    42,   200,   318,
     201,     7,   326,     6,    -1,    51,    44,   200,   318,   201,
       7,   326,     6,    -1,    65,    42,   326,     7,   318,     6,
      -1,    65,    42,   326,     6,    -1,    67,     6,    -1,    68,
       6,    -1,   119,    -1,   120,    -1,   121,    -1,   122,    -1,
     123,    -1,   319,    -1,   194,   318,   195,    -1,   184,   318,
      -1,   183,   318,    -1,   189,   318,    -1,   318,   184,   318,
      -1,   318,   183,   318,    -1,   318,   185,   318,    -1,   318,
     186,   318,    -1,   318,   187,   318,    -1,   318,   193,   318,
      -1,   318,   179,   318,    -1,   318,   180,   318,    -1,   318,
     182,   318,    -1,   318,   181,   318,    -1,   318,   178,   318,
      -1,   318,   177,   318,    -1,   318,   175,   318,    -1,   318,
     174,   318,    -1,   318,   173,   318,     8,   318,    -1,    12,
     194,   318,   195,    -1,    13,   194,   318,   195,    -1,    14,
     194,   318,   195,    -1,    15,   194,   318,   195,    -1,    16,
     194,   318,   195,    -1,    17,   194,   318,   195,    -1,    18,
     194,   318,   195,    -1,    19,   194,   318,   195,    -1,    20,
     194,   318,   195,    -1,    22,   194,   318,   195,    -1,    23,
     194,   318,   199,   318,   195,    -1,    24,   194,   318,   195,
      -1,    25,   194,   318,   195,    -1,    26,   194,   318,   195,
      -1,    27,   194,   318,   195,    -1,    28,   194,   318,   195,
      -1,    29,   194,   318,   195,    -1,    30,   194,   318,   199,
     318,   195,    -1,    31,   194,   318,   199,   318,   195,    -1,
      32,   194,   318,   199,   318,   195,    -1,    21,   194,   318,
     195,    -1,    12,   196,   318,   197,    -1,    13,   196,   318,
     197,    -1,    14,   196,   318,   197,    -1,    15,   196,   318,
     197,    -1,    16,   196,   318,   197,    -1,    17,   196,   318,
     197,    -1,    18,   196,   318,   197,    -1,    19,   196,   318,
     197,    -1,    20,   196,   318,   197,    -1,    22,   196,   318,
     197,    -1,    23,   196,   318,   199,   318,   197,    -1,    24,
     196,   318,   197,    -1,    25,   196,   318,   197,    -1,    26,
     196,   318,   197,    -1,    27,   196,   318,   197,    -1,    28,
     196,   318,   197,    -1,    29,   196,   318,   197,    -1,    30,
     196,   318,   199,   318,   197,    -1,    31,   196,   318,   199,
     318,   197,    -1,    32,   196,   318,   199,   318,   197,    -1,
      21,   196,   318,   197,    -1,     3,    -1,     9,    -1,    10,
      -1,    11,    -1,     4,    -1,     4,   196,   318,   197,    -1,
       4,   295,    -1,     4,   196,   318,   197,   295,    -1,     4,
     198,     4,    -1,     4,   196,   318,   197,   198,     4,    -1,
       4,   198,     4,   295,    -1,     4,   196,   318,   197,   198,
       4,   295,    -1,   321,    -1,   184,   320,    -1,   183,   320,
      -1,   320,   184,   320,    -1,   320,   183,   320,    -1,   200,
     318,   199,   318,   199,   318,   199,   318,   199,   318,   201,
      -1,   200,   318,   199,   318,   199,   318,   199,   318,   201,
      -1,   200,   318,   199,   318,   199,   318,   201,    -1,   194,
     318,   199,   318,   199,   318,   195,    -1,    -1,   194,   323,
     195,    -1,     5,    -1,   323,   199,     5,    -1,    -1,   200,
     325,   201,    -1,   194,   325,   195,    -1,   326,    -1,   325,
     199,   326,    -1,   318,    -1,   327,    -1,   200,   328,   201,
      -1,   184,   200,   328,   201,    -1,   318,     8,   318,    -1,
     318,     8,   318,     8,   318,    -1,     4,   196,   197,    -1,
     184,     4,   196,   197,    -1,     4,   196,   200,   328,   201,
     197,    -1,   184,     4,   196,   200,   328,   201,   197,    -1,
     318,    -1,   327,    -1,   328,   199,   318,    -1,   328,   199,
     327,    -1,   200,   318,   199,   318,   199,   318,   199,   318,
     201,    -1,   200,   318,   199,   318,   199,   318,   201,    -1,
       4,    -1,     4,   198,   104,   198,     4,    -1,   200,   331,
     201,    -1,     4,   196,   318,   197,   198,   105,    -1,   329,
      -1,   331,   199,   329,    -1,     5,    -1,    35,   194,   332,
     199,   332,   195,    -1,    36,   194,   332,   195,    -1,    34,
     194,   332,   195,    -1,    34,   194,   332,   199,   328,   195,
      -1,    34,   194,     4,   198,     4,   195,    -1,    34,   194,
       4,   196,   318,   197,   198,     4,   195,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   175,   175,   177,   178,   179,   184,   186,   189,   197,
     211,   221,   223,   226,   228,   229,   232,   238,   243,   244,
     245,   248,   252,   255,   261,   266,   272,   280,   285,   289,
     295,   300,   304,   309,   313,   316,   321,   325,   329,   333,
     338,   342,   345,   349,   353,   357,   361,   365,   369,   372,
     376,   379,   383,   386,   393,   397,   403,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   419,
     424,   439,   444,   450,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     483,   486,   492,   490,   502,   505,   511,   509,   521,   524,
     530,   528,   540,   543,   550,   547,   561,   564,   571,   568,
     582,   585,   592,   589,   603,   606,   614,   610,   628,   631,
     639,   635,   653,   656,   664,   660,   678,   681,   690,   685,
     704,   707,   716,   711,   730,   733,   742,   737,   756,   759,
     768,   763,   782,   785,   794,   789,   808,   811,   820,   815,
     834,   837,   850,   841,   870,   873,   886,   877,   906,   909,
     922,   913,   942,   945,   956,   949,   973,   976,   987,   980,
    1004,  1007,  1018,  1011,  1035,  1038,  1048,  1042,  1065,  1068,
    1078,  1072,  1095,  1098,  1108,  1102,  1125,  1131,  1140,  1138,
    1152,  1158,  1167,  1165,  1182,  1184,  1185,  1186,  1187,  1190,
    1192,  1195,  1226,  1260,  1307,  1322,  1331,  1346,  1358,  1372,
    1395,  1419,  1431,  1445,  1457,  1471,  1491,  1513,  1525,  1541,
    1552,  1558,  1577,  1591,  1597,  1603,  1622,  1628,  1634,  1650,
    1657,  1663,  1669,  1680,  1691,  1716,  1722,  1741,  1762,  1770,
    1776,  1782,  1791,  1797,  1803,  1813,  1819,  1824,  1829,  1836,
    1838,  1839,  1842,  1847,  1852,  1867,  1882,  1901,  1912,  1921,
    1929,  1933,  1941,  1953,  2029,  2049,  2056,  2060,  2080,  2092,
    2102,  2123,  2144,  2165,  2171,  2176,  2181,  2185,  2193,  2204,
    2211,  2221,  2226,  2231,  2237,  2236,  2247,  2246,  2257,  2256,
    2269,  2274,  2279,  2285,  2284,  2296,  2295,  2308,  2307,  2321,
    2325,  2330,  2357,  2381,  2389,  2408,  2426,  2444,  2466,  2487,
    2508,  2522,  2541,  2546,  2555,  2557,  2558,  2559,  2560,  2563,
    2565,  2566,  2567,  2568,  2569,  2570,  2571,  2572,  2579,  2580,
    2581,  2582,  2583,  2584,  2585,  2586,  2587,  2588,  2589,  2590,
    2591,  2592,  2593,  2594,  2595,  2596,  2597,  2598,  2599,  2600,
    2601,  2602,  2603,  2604,  2605,  2606,  2607,  2608,  2609,  2610,
    2612,  2613,  2614,  2615,  2616,  2617,  2618,  2619,  2620,  2621,
    2622,  2623,  2624,  2625,  2626,  2627,  2628,  2629,  2630,  2631,
    2632,  2637,  2642,  2643,  2644,  2648,  2659,  2676,  2687,  2706,
    2722,  2738,  2754,  2771,  2776,  2780,  2784,  2788,  2794,  2799,
    2803,  2807,  2813,  2817,  2822,  2826,  2831,  2835,  2839,  2845,
    2851,  2858,  2864,  2868,  2872,  2882,  2889,  2900,  2914,  2930,
    2950,  2974,  2980,  2984,  2988,  2999,  3004,  3015,  3020,  3038,
    3043,  3056,  3062,  3068,  3073,  3081,  3094,  3098,  3116,  3130
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
  "tParametric", "tElliptic", "tPlane", "tRuled", "tTransfinite", 
  "tComplex", "tPhysical", "tUsing", "tBump", "tProgression", "tPlugin", 
  "tRotate", "tTranslate", "tSymmetry", "tDilate", "tExtrude", 
  "tDuplicata", "tLoop", "tRecombine", "tDelete", "tCoherence", 
  "tIntersect", "tAttractor", "tLayers", "tScalarPoint", "tVectorPoint", 
  "tTensorPoint", "tScalarLine", "tVectorLine", "tTensorLine", 
  "tScalarTriangle", "tVectorTriangle", "tTensorTriangle", 
  "tScalarQuadrangle", "tVectorQuadrangle", "tTensorQuadrangle", 
  "tScalarTetrahedron", "tVectorTetrahedron", "tTensorTetrahedron", 
  "tScalarHexahedron", "tVectorHexahedron", "tTensorHexahedron", 
  "tScalarPrism", "tVectorPrism", "tTensorPrism", "tScalarPyramid", 
  "tVectorPyramid", "tTensorPyramid", "tText2D", "tText3D", "tBSpline", 
  "tBezier", "tNurbs", "tOrder", "tWith", "tBounds", "tKnots", "tColor", 
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tEndIf", "tExit", 
  "tReturn", "tCall", "tFunction", "tMesh", 
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
  "tELLIPSE", "tTrimmed", "tSolid", "tEndSolid", "tVertex", "tFacet", 
  "tNormal", "tOuter", "tLoopSTL", "tEndLoop", "tEndFacet", 
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'", 
  "tOR", "tAND", "tAPPROXEQUAL", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", 
  "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'", "'/'", "'%'", 
  "tCROSSPRODUCT", "'!'", "UNARYPREC", "tMINUSMINUS", "tPLUSPLUS", "'^'", 
  "'('", "')'", "'['", "']'", "'.'", "','", "'{'", "'}'", "$accept", 
  "All", "SignedDouble", "STLFormatItem", "StepFormatItems", 
  "StepFormatItem", "StepSpecial", "StepHeaderItem", "StepDataItem", 
  "GeomFormatList", "GeomFormat", "Printf", "View", "Views", 
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
  "NumericAffectation", "NumericIncrement", "Affectation", "Shape", 
  "Transform", "MultipleShape", "ListOfShapes", "Duplicata", "Delete", 
  "Colorify", "Command", "Loop", "Extrude", "@27", "@28", "@29", "@30", 
  "@31", "@32", "ExtrudeParameters", "ExtrudeParameter", "Transfini", 
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
     425,   426,   427,    63,   428,   429,   430,   431,   432,    60,
      62,   433,   434,    43,    45,    42,    47,    37,   435,    33,
     436,   437,   438,    94,    40,    41,    91,    93,    46,    44,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   202,   203,   203,   203,   203,   204,   204,   205,   205,
     205,   206,   206,   207,   207,   207,   208,   208,   208,   208,
     208,   209,   209,   209,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   211,   211,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   213,
     213,   214,   214,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     216,   216,   218,   217,   219,   219,   221,   220,   222,   222,
     224,   223,   225,   225,   227,   226,   228,   228,   230,   229,
     231,   231,   233,   232,   234,   234,   236,   235,   237,   237,
     239,   238,   240,   240,   242,   241,   243,   243,   245,   244,
     246,   246,   248,   247,   249,   249,   251,   250,   252,   252,
     254,   253,   255,   255,   257,   256,   258,   258,   260,   259,
     261,   261,   263,   262,   264,   264,   266,   265,   267,   267,
     269,   268,   270,   270,   272,   271,   273,   273,   275,   274,
     276,   276,   278,   277,   279,   279,   281,   280,   282,   282,
     284,   283,   285,   285,   287,   286,   288,   288,   290,   289,
     291,   291,   293,   292,   294,   294,   294,   294,   294,   295,
     295,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   298,   298,   298,   298,   299,
     299,   299,   300,   300,   300,   300,   300,   301,   301,   302,
     302,   302,   303,   304,   304,   304,   304,   304,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   306,   306,
     306,   306,   306,   306,   307,   306,   308,   306,   309,   306,
     306,   306,   306,   310,   306,   311,   306,   312,   306,   313,
     313,   314,   314,   314,   315,   315,   315,   315,   315,   315,
     315,   315,   316,   316,   317,   317,   317,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   320,   320,   320,   320,   320,   321,   321,
     321,   321,   322,   322,   323,   323,   324,   324,   324,   325,
     325,   326,   326,   326,   326,   327,   327,   327,   327,   327,
     327,   328,   328,   328,   328,   329,   329,   329,   329,   330,
     330,   331,   331,   332,   332,   332,   332,   332,   332,   332
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
       8,     8,     7,     7,    11,     8,    12,     8,    22,    20,
       8,     8,     8,     7,     8,     5,    11,     5,     9,     1,
       1,     1,     0,     2,     6,     6,     6,     4,     6,     4,
       6,     3,     5,     3,     3,     7,     2,     2,     6,     8,
       8,    10,     1,     2,     1,     3,     4,     1,     8,    12,
      14,     8,    12,    14,     0,    12,     0,    16,     0,    18,
       8,    12,    14,     0,    12,     0,    16,     0,    18,     1,
       2,     9,     7,     2,     6,     9,     9,     8,     8,     8,
       6,     4,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     1,     1,     1,     1,     1,     4,     2,     5,     3,
       6,     4,     7,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     0,     3,     1,     3,     0,     3,     3,     1,
       3,     1,     1,     3,     4,     3,     5,     3,     4,     6,
       7,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     6,     4,     4,     6,     6,     9
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
     282,     0,   287,     0,   284,     0,     0,     0,    55,    57,
      56,    58,    59,    60,    61,    62,    63,    68,    67,    64,
      65,    66,     6,     0,     0,     0,    16,    17,    19,    18,
      20,   412,   412,     0,   391,   395,   443,   204,   392,   393,
     394,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,   207,   206,   205,     0,
       0,     0,   210,   209,     0,     0,     0,     0,     0,     0,
     329,     0,     0,   277,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   403,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,   262,   322,   323,     0,     0,     0,     0,
       0,     0,   437,     0,     0,     0,     0,     0,   276,     0,
     283,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     397,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   332,   331,
     333,     0,     0,     0,     0,     0,     0,     0,     0,   215,
     274,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   395,     0,     0,   421,
       0,   422,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   405,   404,     0,     0,
       0,     0,   262,   262,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     414,     0,     0,     0,     0,     0,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   443,     0,     0,     0,   330,     0,     0,   431,
     432,     0,     0,   204,     0,     0,     0,     0,   211,     0,
     347,   346,   345,   344,   340,   341,   343,   342,   335,   334,
     336,   337,   338,   339,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   395,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   407,   406,   261,     0,
     260,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,   263,   321,     0,     0,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   413,     0,     0,    22,     0,   396,   401,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   349,   370,   350,   371,   351,   372,   352,
     373,   353,   374,   354,   375,   355,   376,   356,   377,   357,
     378,   369,   390,   358,   379,     0,     0,   360,   381,   361,
     382,   362,   383,   363,   384,   364,   385,   365,   386,     0,
       0,     0,     0,     0,     0,     0,     0,   446,     0,     0,
     445,     0,     0,     0,     0,     0,     0,     0,     0,   221,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   427,     0,     0,     0,   423,
     425,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   415,     0,   412,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     433,   434,     0,     0,     0,     0,     0,   216,   217,   219,
       0,     0,   441,     0,   225,   348,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,     0,   424,     0,
     232,     0,     0,     0,     0,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,     0,     0,     0,   320,   270,     0,     0,
       0,     0,     0,   416,     0,   438,     0,     0,     0,   278,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   324,   325,   326,   327,   328,
       0,     0,     0,     0,     0,     0,     0,    21,     0,   400,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   380,   366,
     387,   367,   388,   368,   389,     0,   448,   447,   444,     0,
     204,     0,     0,     0,     0,   212,     0,     0,     0,   439,
      70,   229,   236,     0,   237,     0,   233,     0,   234,   253,
       0,     0,   426,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,     0,     0,
       0,   262,     0,     0,     0,   294,     0,   303,     0,     0,
       0,     0,     0,   242,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   412,   402,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
       0,   223,     0,   442,     0,   241,   251,   429,     0,     0,
     318,   245,   247,     0,     0,   317,   319,   252,   230,   240,
     250,   254,     0,     0,     0,   411,     0,   410,     0,     0,
     288,     0,   291,     0,     0,   300,     0,   264,   265,   266,
       0,     0,   416,     0,   419,     0,     0,     0,     0,   436,
       0,   280,   279,     0,     0,     0,     0,     0,    24,     0,
      33,     0,    37,     0,    31,     0,     0,    36,     0,    41,
      39,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   218,   220,     0,   226,     0,   238,
     430,     0,   316,   315,   227,   228,   262,     0,   258,     0,
       0,     0,     0,     0,     0,     0,     0,   418,     0,   417,
       0,     0,     0,     0,     0,     0,     0,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,     0,   440,     0,     0,     0,
     409,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,   420,     0,
       0,   435,   281,     0,     0,    38,     0,     0,     0,     0,
      28,     0,    34,     0,    40,    29,    42,     0,    45,     0,
      49,    50,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,     0,   256,     0,     0,     0,     0,
     296,     0,   313,     0,     0,   310,   305,     0,     0,     0,
       0,     0,     0,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   106,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,     0,     0,   408,   289,     0,   292,     0,
       0,     0,   295,   301,     0,     0,   304,   231,   235,     0,
       0,   246,     0,     0,     0,     0,     0,    32,    35,    43,
       0,    44,    51,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,     0,     0,   307,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,     0,   290,     0,   293,     0,     0,     0,
     302,     0,     0,     0,     0,     0,     0,    27,    30,     0,
       0,     0,   100,     0,   104,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   297,     0,     0,   312,
     306,     0,     0,     0,     0,     0,     0,    47,    23,   101,
     103,   105,   107,   109,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   199,     0,   200,
     239,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     118,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   299,   311,   308,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   203,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,   112,     0,   116,     0,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,     0,    25,   113,   115,   117,
     119,   121,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,   130,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,   128,     0,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   127,   129,   131,   133,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   142,   146,   150,   154,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,   140,     0,   144,     0,   148,     0,
     152,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   139,   141,   143,   145,   147,   149,
     151,   153,   155,   157,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   190,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   184,     0,
     188,     0,   192,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   185,   187,   189,   191,   193,   195,     0,     0,     0,
     174,   178,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   172,
       0,   176,     0,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   175,   177,   179,
     181,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   166,   170,     0,     0,     0,     0,     0,     0,     0,
     160,     0,   164,     0,   168,     0,     0,     0,     0,     0,
       0,   161,   163,   165,   167,   169,   171
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     5,    84,     6,     7,    21,    22,    23,    24,     8,
      68,    69,    70,   418,  1581,   627,  1495,  1583,   628,  1496,
    1585,   629,  1497,  1793,   630,  1740,  1795,   631,  1741,  1797,
     632,  1742,  1929,   633,  1891,  1931,   634,  1892,  1933,   635,
    1893,  2041,   636,  2011,  2043,   637,  2012,  2045,   638,  2013,
    2047,   639,  2014,  2049,   640,  2015,  2051,   641,  2016,  2239,
     642,  2233,  2241,   643,  2234,  2243,   644,  2235,  2188,   645,
    2176,  2190,   646,  2177,  2192,   647,  2178,  2137,   648,  2119,
    2139,   649,  2120,  2141,   650,  2121,  1608,   651,  1519,  1698,
     652,  1610,   137,   240,    71,   542,   528,   529,   530,   531,
      75,    76,    77,    78,    79,  1163,  1469,  1567,  1166,  1474,
    1571,  1340,  1341,    80,    81,   950,   329,   140,   346,   172,
     235,   411,  1058,  1173,  1174,   331,   471,   194,   713,   863,
     141
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1304
static const short yypact[] =
{
    2658,    30, -1304, -1304,  -121,    61, -1304,   262,  2875, -1304,
      10, -1304,    59,    69,    90,   123,   130,   141,  -124,   -80,
     -72, -1304, -1304, -1304, -1304,  2274,   -38,   168,   -11,    -1,
      23,   -39,   197,   117,   135,   248,   163,   309,   337,   344,
     465,   343,   116,   226,   192,    -4,    -4,   221,   174,     4,
     399,     3,   420,   442,   164,   257,   260,   -24,     6,    15,
   -1304,   261, -1304,   454, -1304,   468,   472,   423, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304,   466,    10,  2983, -1304, -1304, -1304, -1304,
   -1304,   288,   288,   493, -1304,   265,     7, -1304, -1304, -1304,
   -1304,  -106,   212,   223,   270,   281,   300,   316,   317,   327,
     333,   340,   341,   362,   363,   409,   430,   431,   449,   458,
     459,   462,   291,   294,   303, -1304, -1304, -1304, -1304,  2375,
    2375,  2375, -1304, -1304,  2375,   570,    26,  2375,   508,   734,
   -1304,   509,   513, -1304,  2375,  2375,  2375,   328,  2375,   334,
    2375,  2375,  1177,  2375,   331,   349,   378,  1177,   338,   404,
     413,   414,   418,   434,   437,   640,    -4,    -4,    -4,  2375,
    2375,  -127, -1304,  -107,    -4,   457,   463,   471,   453, -1304,
    1177,   479,   672, -1304, -1304, -1304,  1177,  1177,  2375,  2375,
     -70,  2375,   489,  2375,   488,   592,  2375,  2375, -1304,   711,
   -1304,   534, -1304,    10,   539,   540,   554,   563,   571,   575,
     582,   589,   590,   617,   621,   646,   669,   683,   684,   685,
     686,   687,   688,   689,   690,   692,   693,   694,   695,   696,
     700,   701,   702,   703,   713,   538,   704,   670,  2375,   894,
   -1304,    -4, -1304,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,    64,    67,    67,   545,   545,
     545, 11062,   893,  2405, 10495,   253,   705,   895,   959, -1304,
   -1304,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375, -1304,   -82, 11085, 11108,
   11131,  2375, 11154,  2375, 11177, 11200,   282,  1463,  2405,   367,
     897, -1304, 11223,  2375,  2375,  2375,   899,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,   706,  -120, -1304, -1304,  3342,  3365,
      -4,    -4,   369,   369,    -7,  2375,  2375,  2375,  2375,   948,
     101,  2375, -1304,  2690,   903,   915, 11246, 11269,   821,  2375,
   11292,   820,  3388, -1304,   725,   664, 11315, -1304,  2375,   761,
     923,   924,   925,   926,   931,   957,   958,   961,   962,   963,
     964,   965,   966,   967,   968,   969,   970,   972,   973,   974,
     975,   976,   978,   782,   979,   980,   989,   991,   996,  1000,
   -1304,   -57,  1001,  1002,  1004, 10516,    79,   -35,  2964, 11338,
   10537, 11361, 10558, 11384, 10579, 11407, 10600, 11430, 10621, 11453,
   10642, 11476, 10663, 11499, 10684, 11522, 10705, 11545, 10726, 11568,
   10747,  3411,  3434, 11591, 10768, 11614, 10789, 11637, 10810, 11660,
   10831, 11683, 10852, 11706, 10873,  3457,  3480,  3503,  3526,  3549,
    3572,   380, -1304,    98,   765,   812, -1304,  1177,  2495,   367,
   -1304,   460,   154,    67,  2375,  1008,  1006,     8, -1304,  2355,
     455,   526,   384,   384,   198,   198,   198,   198,   162,   162,
     545,   545,   545,   545,  1010,  2405,  1011,  1012,  1013, 11729,
    1014, 11752,  1015,  1016,   929,   295,  2405,   461,  2375,  2375,
    1017,  1142, 11775, 11798,  2375,  2689,  2774, 11821, 11844, 11867,
   11890, 11913,   827,    -4,  2375,  2375, -1304, -1304, -1304,   828,
      42, -1304,   829,  2375,  3595,  3618,  3641, 10894,  -160,   -48,
     -41, -1304, -1304, -1304,  2375, 10915, -1304,   831,   832,  1026,
    1027,   841, 11936,  1029,   839,  2375,  2762,  2375,  2375, -1304,
   11959,   873,   843,   845,   849,   850,   851,   853,   854,   855,
     856,   857,   858,   862,   863,   864,   865,   867,   868,   869,
     871,   872,   900,   901,   902,   904,   905,   906,   907,   909,
     910,   911, -1304,  1035,   877, -1304,   912,  -139, -1304, -1304,
     908,   921,   922,   927,   928,   930,   933,   934,   936,   941,
     953,   960,   988,   990,  1019,  1031,  1032,  1033,  1038,  1039,
    1042,  1044,  1047,  1048,  1049,  1050,  1111, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304,  2375,  2375, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  1115, -1304,  2405,    67,
   -1304,  1114,  2405,   986,    28,  2375,  1119,  1179,  1037, -1304,
    1238,  1051,     6,  1242,  2375, -1304,   100,    -4,  1177,  1177,
    1243,  1177,  1244,  1177,  1177, -1304,  2405,  1147,   475, -1304,
    2430,  1393,  1052,  1246,  1247,  1249,   436,  1250,  1251,  1252,
    1253,  1254,  1255,  1257,  1245,   108,  3664,  3687, -1304, -1304,
    2817,    -4,    -4,    -4,  1259,  2405,  2405,  2405,  1591,  1260,
    2375,  2375,  1177,  1177,  2375,  1262,  1177,  1263,  3710, -1304,
    2447,   639,  1265,  1108,  1296,  2375,  2375,    -4,  1297,  1300,
    1120,  1306,  1307,  1177,  1177,  1308,    -4,  1309,  1310,  1177,
    1177,  1311,  1329,  1330,  1331,  1334,  1177,   382,  1177,  1335,
    1337,  1340,  1336,  1343, -1304,  1342,   288,  1345, -1304,  2990,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375, -1304, 11982, 10936, 12005,
   10957, 12028, 10978, 12051, 10999, 11020,  1145,   105,  1155, -1304,
     367, -1304,    17,   267,  1153,  1346,  1647, -1304, -1304, -1304,
       6,  2375, -1304,   480, -1304, 12879,  1348,    14,    29,  1349,
    1177,  1350,  1177,  1351,  1352,   483, -1304,  2405, -1304,  2375,
   -1304,  2375,  1177,  1177,  1177, -1304,   250,  1177,  1177,  1177,
    1177,  1177,  1177,  1177,   403,  2375,  2375,  2375,  1152,   138,
     194,   206, -1304,   484,   492,   495, -1304, -1304,  3733,  3756,
    1353,  1356, 12074,  -129,  1261, -1304,  2375,  2375,  2375, -1304,
    1163,    10,  1166,  3779,  3802,   -68,  1168,  1173,  1170,  1175,
    1174,  1180,  1181,  1182,   -33,  1183,  1184,  1188,  1186,  1189,
    1191,  1192,  1195,  1197,  1202, -1304, -1304, -1304, -1304, -1304,
    1199,  1201,  1203,  1204,  1205,  1206,  1207, -1304,  1208,    79,
    1366,  3825,  3848,  3871,  3894,  3917,  3940,  3963,  3986,  4009,
    4032,  4055,  4078,  4101,  4124,  4147,  4170,  4193,  4216,  4239,
    4262,  4285,  4308,  4331,  4354,  4377,  4400, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304,  1176, -1304, -1304, -1304,  1177,
      67,  2375,  1370,  1374,     8, -1304,  1381, 11041,     6, -1304,
   -1304, -1304, -1304,    -4, -1304,  1399, -1304,  1402, -1304, -1304,
    1212,   496, 12879,  4423,  1404,  1405,  1406,  2375,  2375,  1407,
    1408,  1409,  1431,  1433,  1434,  1435, -1304,  2308,  2969, 12097,
    2399,   369,    -4,  1436,    -4,  1452,    -4,  1453,  1454,  1455,
    1456,  2375,  2375, -1304, -1304,  1457,  1177,  1177,  1365,  1177,
    2464,   187, 12120,  2375,    10,  1467,  2375,  1177,  1490,  1494,
    1492,  1314,  1495,   382,  1496,  1497,  2375,  1498,  1500,  1499,
    1501,  1503,   382,  2375,  2375,  2375,  1177,  1502,  1506,   382,
    2375,  1507,  1508,  1534,  2375,   288, -1304, -1304,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  1535,  1563,  1575,  1730, -1304,  1576,
    1579, -1304,  1384, -1304,    16, -1304, -1304, -1304,  1344,  2375,
   -1304, -1304, -1304,  1775,  1843, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304,  2052,  1581,  1388, -1304,  2375, -1304,  1389,   144,
   -1304,   151, -1304,  1391,   157, -1304,  1392, -1304, -1304, -1304,
    4446,  4469,  -129,   143, -1304,   499,  1395,  1489,  2375, -1304,
    2375, -1304, -1304,  4492,    10,  1398,  4515,  1397, -1304,  1400,
   -1304,  1428, -1304,  1403, -1304,  1430, 12143, -1304,  1432, -1304,
   -1304,  1410,  1437, 12166,  4538, 12189,  1438, -1304,  1439,  1440,
    4561,  1441,  1443, -1304,  4584,  1444,  4607,  4630,  4653,  4676,
    4699,  4722,  4745,  4768,  4791,  4814,  4837,  4860,  4883,  4906,
    4929,  4952,  4975,  4998,  5021,  5044,  5067,  5090,  5113,  5136,
    5159,  5182,  1447, -1304, -1304, -1304,     6, -1304,  1525, -1304,
   -1304,  5205, -1304, -1304, -1304, -1304,   369,  2655, -1304,  1533,
    1533,   -20,  1533,   -20,  2375,  2375,  1530, -1304,  1177, -1304,
    1177,  2375,  2994,  3023,  1177,  1477,  1595,  -129,   382,  1600,
    2375,  1638,   382,  1639,  1645,  1643,  1644,  1648,  2375,  1649,
    1177,  1650,  1652,  2375,  1656,  1654,  2375,  1646,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375, -1304,  1655, -1304,  1657,  1464,  2375,
   -1304,  1533,  1533,  2375,  3048,   232,  3078,   263,  1660,  1468,
     -32, -1304,  3103,   269,   -26,  3132,  3157,  1469, -1304,  1473,
    2079, -1304, -1304,  1466,    10, -1304,  1474,  1475,  1476,  5228,
   -1304,  1481, -1304,  1482, -1304, -1304, -1304, 12212, -1304,  1479,
   -1304, -1304, 12235,  1486, -1304, 12258,  1483, 12281, 12304, 12327,
    5251,  5274,  5297,  5320,  5343,  5366,  5389,  5412,  5435,  5458,
    5481,  5504,  5527,  5550,  5573,  5596,  5619,  5642,  5665,  5688,
    5711, 12350,  5734, -1304,  1485, -1304,  3186,  1270,  1677,  2375,
    1679,  2375, -1304,  1177,  1680, -1304,  1699,  2375,  1700,  1701,
    1702,  1177,  1177, -1304,  1703,    10,   382,   382,   382,   382,
    1704,  1705,  1706,   382,  1707,  1708,  1709,  1713, -1304, -1304,
   -1304,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375, -1304,  2375,  1714, -1304, -1304,  3217, -1304,  1520,
    3242,  1522, -1304, -1304,  1523,  3267, -1304, -1304, -1304,  1526,
    1527, -1304,    10,  1531,  1532,  1529,  1537, -1304, -1304, -1304,
    1536, -1304, -1304, -1304,  1538,  1539,  1540,  1541,  5757,  5780,
    5803,  5826,  5849,  5872,  5895,  5918,  5941,  5964,  5987,  6010,
    6033,  6056,  6079,  6102,  6125,  6148,  6171,  6194,  6217,  1542,
   12373,  1568,  1720,   -20,  1723,  1177,   -20,  1728,  1177,  1682,
    1617,   382,   382,  1774,  1777,   382,  1780,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,    67, -1304,  1781, -1304,   -23, -1304,  1587,   515,   -19,
   -1304,  1588,  1589,  1592,    10,  1590,  1594, -1304, -1304,  1596,
    1599,   524, 12879,   525, 12879,   528, 12879,  6240,  6263,  6286,
    6309,  6332,  6355,  6378,  6401,  6424,  6447,  6470,  6493,  6516,
    6539,  6562,  6585,  6608,  6631,  6654,  6677,  6700,   543, -1304,
    1598,  1618,  1790,   -20,  1177,  1794,  1817,   -20,  1735,  2375,
      10,   382,  1177,  1830,  1831,  2375,  1832,  2375,  1833,  2375,
    1835,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,    67,  1836,    67,  1837, -1304,   -16,  1664, -1304,
   -1304,   -10,  1666,  6723,    10,  1668,  1669, -1304, -1304, 12879,
   -1304, 12879, -1304, 12879, -1304, 12396, 12419, 12442,  6746,  6769,
    6792,  6815,  6838,  6861,  6884,  6907,  6930,  6953,  6976,  6999,
    7022,  7045,  7068,  7091,  7114,  7137, -1304, -1304,   544, -1304,
   -1304,  1838,  1839,  1840,  2375,  2375,  1681,   382,  1177, -1304,
   -1304, -1304,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
      67,  1841, -1304, -1304, -1304,  7160,  3292,  1710,  1670,  1671,
    1672,  1673,  1674,  7183,  7206,  7229,  7252,  7275,  7298,  7321,
    7344,  7367,  7390,  7413,  7436,  7459,  7482,  7505,  7528,  7551,
    7574, -1304, -1304,  2375,  1865, -1304,  1177,   382,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  3317,
   -1304,  1676,  1684,   548, 12879,   557, 12879,   561, 12879,  7597,
    7620,  7643,  7666,  7689,  7712,  7735,  7758,  7781,  7804,  7827,
    7850,  7873,  7896,  7919,  7942,  7965,  7988,  1870,  1177,  1871,
    2375,  1874,  2375,  1875,  2375,  1876,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375, -1304,  1685, -1304, 12879, -1304, 12879,
   -1304, 12879, -1304, 12465, 12488, 12511,  8011,  8034,  8057,  8080,
    8103,  8126,  8149,  8172,  8195,  8218,  8241,  8264,  8287,  8310,
    8333,  1177, -1304, -1304, -1304,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    1719,  1683,  1721,  1722,  8356,  8379,  8402,  8425,  8448,  8471,
    8494,  8517,  8540,  8563,  8586,  8609,  8632,  8655,  8678,  1177,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  1725,   562,
   12879,   567, 12879,   572, 12879,  8701,  8724,  8747,  8770,  8793,
    8816,  8839,  8862,  8885,  8908,  8931,  8954,  8977,  9000,  9023,
     382,  2375,  1900,  2375,  1913,  2375,  1914,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  1732, 12879, -1304, 12879, -1304, 12879, -1304, 12534,
   12557, 12580, 12603, 12626, 12649,  9046,  9069,  9092,  9115,  9138,
    9161,  9184,  9207,  9230,  1919, -1304, -1304, -1304, -1304, -1304,
   -1304,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
   -1304,  1729,  1731,  1747,  1763,  1764,  1765,  9253,  9276,  9299,
    9322,  9345,  9368,  9391,  9414,  9437,  2375,  2375,  2375,  2375,
    2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,   573, 12879,   576, 12879,   580, 12879,   581, 12879,   628,
   12879,   629, 12879,  9460,  9483,  9506,  9529,  9552,  9575,  9598,
    9621,  9644,  2375,  1960,  2375,  1961,  2375,  1963,  2375,  1964,
    2375,  1965,  2375,  1966,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  2375,  2375, 12879, -1304, 12879, -1304, 12879, -1304, 12879,
   -1304, 12879, -1304, 12879, -1304,  9667,  9690,  9713,  9736,  9759,
    9782, 12672, 12695, 12718,  2375,  2375,  2375,  2375,  2375,  2375,
   -1304, -1304, -1304,  9805,  9828,  9851,  9874,  9897,  9920,  1773,
    1785,  1786,  2375,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    2375,  9943,  9966,  9989, 10012, 10035, 10058,   634, 12879,   654,
   12879,   659, 12879,  2375,  2375,  2375,  2375,  2375,  2375,  2375,
    1968,  2375,  1969,  2375,  1981, 10081, 10104, 10127, 12741, 12764,
   12787, 12879, -1304, 12879, -1304, 12879, -1304,  2375,  2375,  2375,
   -1304, -1304, -1304, 10150, 10173, 10196,  1788,  1789,  1791,  2375,
    2375,  2375,  2375,  2375,  2375, 10219, 10242, 10265,   660, 12879,
     663, 12879,   666, 12879,  2375,  2375,  2375,  2375,  1984,  2375,
    1986,  2375,  1987, 10288, 10311, 10334, 12879, -1304, 12879, -1304,
   12879, -1304,  2375,  2375,  2375, 10357, 10380, 10403,  2375,  2375,
    2375, 10426, 10449, 10472,  2375,  2375,  2375, 12810, 12833, 12856,
   -1304, -1304, -1304,  1795,  1796,  1797,  2375,  2375,  2375,   667,
   12879,   674, 12879,   675, 12879,  2375,  1988,  2375,  1992,  2375,
    1993, 12879, -1304, 12879, -1304, 12879, -1304
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -1304, -1304,   -36, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304,  1401, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1304,  -291,   -22, -1304,  2011,  2023,  -351,  -162,  2024,
   -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304, -1304,
   -1304, -1254, -1303, -1304, -1304, -1015,   -25, -1304,   -31, -1304,
     -91, -1304, -1143,   977,  1484,  -231,  -322,  -707,  1034, -1304,
    -259
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -55
static const short yytable[] =
{
     139,   236,   532,   138,   474,   862,   507,   181,   178,  1344,
     192,   241,   711,    82,   171,   173,   147,   359,   190,   195,
    1011,   363,  1249,   149,    97,   147,   463,   464,   465,  1266,
     295,   368,   853,  1338,   144,  1012,     9,  1415,  1339,  1338,
     755,  1415,  1338,    10,  1339,  1338,  1338,  1339,   203,  1338,
    1339,  1339,   132,   133,  1339,  1338,   350,   351,  1193,   807,
    1339,    11,   470,   350,   351,  1056,    85,  1202,   461,   462,
      91,  1057,   462,   352,  1209,    86,   350,   351,  1013,   523,
     538,    29,    30,   539,   540,    33,    34,    35,   243,    36,
     244,    38,    39,   353,    41,    42,    87,   470,   122,   123,
     124,   122,   123,   124,   288,   289,   290,   543,   544,   291,
     294,    54,   298,   494,    92,   350,   351,   495,   182,   318,
     319,   320,    93,   322,   369,   324,   325,  1068,   332,    88,
     296,   297,   854,   855,  1356,   345,    89,   347,   592,    55,
      56,    57,   593,   354,   348,   349,   148,    90,   350,   351,
     350,   351,   756,  1006,   161,   148,   142,   162,   163,   757,
     164,    97,  1077,   366,   367,   599,   370,   379,   372,  1414,
     191,   375,   376,   716,   143,  1418,   350,   351,  1612,   167,
     168,   705,  1616,   144,   728,  1701,   125,   126,   127,   128,
     169,  1703,   533,   145,    83,  1180,   170,   350,   351,   350,
     351,    67,   186,   183,   179,   187,   193,   242,   712,   196,
     417,   556,   175,   415,   707,   176,   177,   146,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     473,   149,  1415,  1357,   470,    12,  1415,  1361,   469,  1565,
     132,   133,  1569,   475,  1000,   470,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   350,   351,   697,   152,   866,   499,   698,   501,   702,
     997,  1133,   289,   469,   702,  1027,  1028,   895,   511,   512,
     513,   150,   515,   516,   517,   518,   519,   520,   521,   526,
     527,   350,   351,   125,   126,   127,   128,   350,   351,   151,
     534,   535,   536,   537,   350,   351,   545,  1042,  1267,  1043,
     350,   351,  1268,  1259,   552,   132,   133,   312,   313,   314,
    1260,   154,   704,   560,  1415,   315,  1262,   153,  1415,  1657,
     301,   302,   303,  1661,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   508,   847,   350,   351,   155,
     315,   310,   311,   312,   313,   314,   156,   160,  1181,   350,
     351,   315,   166,  1044,   598,  1045,    13,    14,    15,    16,
      17,    18,    19,    20,   875,  1046,   245,  1047,   246,  1036,
    1037,  1483,  1484,  1485,  1486,   350,   351,   247,  1490,   248,
     165,   174,   125,   126,   127,   128,   184,    44,    45,    46,
      47,  1409,    49,   903,   904,   905,   125,   126,   127,   128,
     848,   180,   885,   289,   132,   133,   350,   351,   185,   708,
     706,   188,   350,   351,   189,   197,   132,   133,   132,   133,
     198,   238,  1411,   239,   249,   201,   250,   470,  1417,   202,
     469,   851,   199,   132,   133,   251,   200,   252,   504,   415,
     239,   469,   234,   730,   731,   285,   132,   133,   286,   736,
     886,   727,   745,   239,   253,   470,   254,   287,   237,   746,
     747,   945,   946,   947,   948,   949,   157,   158,   750,   159,
     255,   257,   256,   258,   299,   316,  1575,  1576,   317,   758,
    1579,   259,   321,   260,   470,   470,   470,   261,   323,   262,
     768,   333,   770,   771,   263,   265,   264,   266,   337,  1325,
     301,   302,   303,   334,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,  1021,   267,   269,   268,   270,
     315,   999,  1001,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   335,    94,    95,   808,   695,   315,   696,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   271,   338,   272,  1665,   339,   340,   301,
     302,   303,   341,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   273,   275,   274,   276,   342,   315,
     303,   343,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   277,   344,   278,   470,   918,   315,   358,
     837,   838,   279,   281,   280,   282,   283,   355,   284,   702,
     702,   703,   729,   356,   839,   840,   841,   842,   843,   844,
     845,   357,   558,   469,   702,   361,   878,   850,   362,  1008,
     856,  1009,   702,   702,  1020,  1048,   867,   371,   373,   865,
    1158,   702,  1738,  1049,   702,   702,  1050,  1138,  1268,   374,
    1269,   469,   415,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,  1614,   958,  1615,   377,   410,   315,
     899,   900,   901,  1625,  1627,  1626,  1628,  1629,   378,  1630,
     469,   469,   469,   380,   381,   908,   909,   412,   315,   912,
     300,  1126,  1652,  1730,  1653,  1731,   925,  1820,   382,  1821,
     923,   924,  1792,   129,   130,   934,  1822,   383,  1823,   131,
    1824,  1951,  1825,  1952,   134,   384,  1953,   292,  1954,   385,
     293,  1955,  2062,  1956,  2063,  2064,   386,  2065,  1153,  2066,
    2068,  2067,  2069,   387,   388,   961,   962,   963,   964,   965,
     966,   967,   968,   969,   970,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   980,   981,   982,   983,   984,   985,
     986,   389,   301,   302,   303,   390,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,  2070,  2072,  2071,
    2073,  1002,   315,  2149,   919,  2150,  1007,   301,   302,   303,
     391,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   469,  2151,  1022,  2152,  1023,   315,  2153,  2197,
    2154,  2198,  2199,   392,  2200,  2201,  2245,  2202,  2246,   414,
    1038,  1039,  1040,  2247,  2249,  2248,  2250,   393,   394,   395,
     396,   397,   398,   399,   400,  1064,   401,   402,   403,   404,
     405,  1060,  1061,  1062,   406,   407,   408,   409,   416,   413,
     467,   522,   477,   476,   509,  1328,   514,   301,   302,   303,
     547,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   548,   551,   554,   557,   561,   315,   562,   563,
     564,   565,    94,    95,   585,  1972,   566,  1096,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   567,   568,   699,   478,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,  1127,   579,   580,   581,
     582,   583,  1134,   584,   586,   587,   538,    29,    30,   539,
     540,    33,    34,    35,   588,    36,   589,    38,    39,   590,
      41,    42,  1143,  1144,  1215,   591,   594,   700,   595,   596,
     710,  1159,  1152,  1161,   709,  1164,   715,    54,   717,   718,
     719,   721,   723,   724,   732,   744,  1170,  1171,  1184,   748,
     749,   760,   761,   762,   763,   764,   766,   767,  1183,   773,
     804,  1186,   774,   859,   775,    55,    56,    57,   776,   777,
     778,  1196,   779,   780,   781,   782,   783,   784,  1203,  1204,
    1205,   785,   786,   787,   788,  1210,   789,   790,   791,  1214,
     792,   793,   805,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,
    1233,  1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,   794,
     795,   796,   810,   797,   798,   799,   800,    67,   801,   802,
     803,   806,   129,   130,  1251,   811,   812,   836,   131,   846,
     849,   813,   814,   134,   815,   857,   725,   816,   817,   726,
     818,  1257,   301,   302,   303,   819,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   820,  1275,   541,
      94,    95,   315,  1272,   821,  1273,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      94,   326,   822,   852,   823,   858,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     301,   302,   303,   824,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   825,   826,   827,  1335,  1337,
     315,  1343,   828,   829,  1334,  1336,   830,  1342,   831,  1345,
    1346,   832,   833,   834,   835,   860,  1350,   861,   864,   894,
     870,   872,   881,   882,   883,  1359,   884,   887,   888,   889,
     890,   891,   892,  1367,   893,   902,   907,   915,  1372,   913,
     921,  1375,   920,  1377,  1378,  1379,  1380,  1381,  1382,  1383,
    1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,
    1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,   922,
     926,   347,  1609,   927,  1406,   928,   288,   289,  1407,   929,
     930,   933,   935,   936,   939,   301,   302,   303,  1425,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     129,   130,   940,   941,   942,   315,   131,   943,   952,   955,
     996,   134,   953,   733,   876,   954,   956,   877,   957,   959,
     998,  1003,  1041,  1004,  1010,  1014,  1016,  1018,  1019,  1053,
     129,   327,  1054,  1063,  1059,  1065,   131,  1069,  1070,  1071,
    1072,   134,  1097,  1073,  1124,  1074,  1128,   328,  1129,  1079,
    1075,  1076,  1078,  1080,  1467,  1081,  1470,  1131,  1082,  1482,
    1083,  1084,  1475,  1696,  1085,  1699,  1086,  1087,  1088,   880,
    1089,  1093,  1090,  1091,  1092,  1135,  1094,  1095,  1136,  1137,
    1140,  1141,  1142,  1145,  1146,  1147,  1498,  1499,  1500,  1501,
    1502,  1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1517,  1518,  1148,  1520,  1149,
    1150,  1151,  1160,   301,   302,   303,  1530,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,  1162,  1165,
    1167,  1168,  1169,   315,  1172,   466,    94,   505,  1176,   524,
    1185,  1761,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,  1188,  1189,  1190,  1191,
    1195,  1192,  1194,  1198,  1197,  1199,  1201,  1200,  1207,  1208,
    1211,  1212,  1582,  1584,  1586,  1587,  1588,  1589,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,
    1602,  1603,  1604,  1605,  1606,  1607,    94,    95,  1620,  1242,
    1213,  1250,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   301,   302,   303,  1243,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,  1244,  1248,  1246,  1664,  1247,   315,  1255,  1256,  1271,
    1258,  1261,  1263,  1276,  1663,  1270,  1278,   906,  1281,  1279,
    1669,  1355,  1671,  1358,  1673,  1285,  1675,  1676,  1677,  1678,
    1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
    1689,  1690,  1691,  1692,  1693,  1694,  1695,  1280,  1706,  1282,
    1326,  1284,  1286,  1347,  1291,  1292,   330,  1290,  1295,  1354,
    1294,   336,  1324,  1297,  1360,  1362,   129,   130,  1363,  1364,
    1365,  1376,   131,  1005,  1366,  1368,  1370,   134,  1371,  1373,
    1374,  1403,  1404,   506,   360,  1405,  1412,  1424,  1413,  1421,
     364,   365,  1422,  1426,  1427,  1428,  1430,  1431,  1433,  1735,
    1736,  1435,  1437,  1466,  1464,  1468,  1472,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,  1473,  1476,  1477,  1478,  1481,
    1487,  1488,  1489,  1491,  1492,  1493,  1331,  1332,  1494,  1521,
    1523,  1525,   131,  1526,  1533,  1528,  1564,  1333,  1529,  1566,
    1531,  1532,  1534,   170,  1570,  1535,  1245,  1536,  1789,  1537,
    1538,  1539,  1561,  1794,  1796,  1798,  1799,  1800,  1801,  1802,
    1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,
    1813,  1814,  1815,  1816,   301,   302,   303,  1563,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,  1574,
    1577,  1252,  1573,  1578,   315,  1580,  1611,  1613,  1617,  1621,
    1618,  1623,  1619,  1622,  1624,  1847,  1656,  1849,  1654,  1851,
    1659,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,
    1862,  1863,  1864,  1865,  1866,  1867,  1868,  1869,  1870,  1655,
     301,   302,   303,  1660,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,  1662,  1667,  1668,  1670,  1672,
     315,  1674,  1697,  1700,  1732,  1733,  1734,  1762,  1737,  1253,
    1894,  1895,  1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,
    1904,  1905,  1906,  1907,  1908,  1702,  1704,  1707,  1708,  1766,
    1767,  1790,  1768,  1769,  1770,  1818,  1844,  1846,  1765,  1819,
    1848,  1850,  1852,  1910,  1871,  1930,  1932,  1934,  1935,  1936,
    1937,  1938,  1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,
    1947,  1948,  1949,   301,   302,   303,  1974,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,  1909,  1976,
    1978,  1911,  1912,   315,  1950,  2010,  1973,  1994,  1975,  2026,
    1977,  2027,  1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,
    1987,  1988,  1989,  1990,  1991,  1992,  1993,  2028,   301,   302,
     303,   701,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,  2029,  2030,  2031,  2084,  2086,   315,  2088,
    2090,  2092,  2094,  2128,  2162,  2164,  2017,  2018,  2019,  2020,
    2021,  2022,  2023,  2024,  2025,  2129,  2130,  2166,  2182,  2183,
    2207,  2184,  2209,  2211,  2252,  2236,  2237,  2238,  2254,  2256,
     809,  2042,  2044,  2046,  2048,  2050,  2052,  2053,  2054,  2055,
    2056,  2057,  2058,  2059,  2060,  2061,   301,   302,   303,    72,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    73,    74,     0,  1175,     0,   315,  2083,  1130,  2085,
       0,  2087,     0,  2089,     0,  2091,     0,  2093,     0,  2095,
    2096,  2097,  2098,  2099,  2100,  2101,  2102,  2103,  1254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2113,
    2114,  2115,  2116,  2117,  2118,  1423,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2131,  2132,  2133,
    2134,  2135,  2136,  2138,  2140,  2142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2155,  2156,
    2157,  2158,  2159,  2160,  2161,     0,  2163,     0,  2165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2173,  2174,  2175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2185,  2186,  2187,  2189,  2191,  2193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2203,
    2204,  2205,  2206,     0,  2208,     0,  2210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2215,  2216,  2217,
       0,     0,     0,  2221,  2222,  2223,     0,     0,     0,  2227,
    2228,  2229,   868,   869,     0,   871,     0,   873,   874,     0,
       0,  2240,  2242,  2244,     0,     0,     0,     0,     0,     0,
    2251,     0,  2253,     0,  2255,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,   910,   911,     0,     0,
     914,     0,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   931,   932,     0,
       0,     0,   315,   937,   938,     0,     0,    94,    95,    96,
     944,    97,   951,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,   122,   123,
     124,    94,    95,   462,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1015,     0,  1017,     0,     0,     0,
       0,     0,     0,   714,     0,     0,  1024,  1025,  1026,     0,
       0,  1029,  1030,  1031,  1032,  1033,  1034,  1035,    94,    95,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    94,   326,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   879,     0,
       0,     0,     0,   125,   126,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,   917,     0,   129,   130,     0,
       0,     0,     0,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1125,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,   131,    94,   505,
       0,     0,   134,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,  1177,     0,     0,     0,     0,   315,     0,
       0,  1187,     0,     0,     0,     0,     0,     0,   129,   130,
       0,     0,     0,     0,   131,     0,     0,     0,     0,   134,
    1206,     0,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,   129,   468,
       0,     0,   315,     0,   131,     0,     0,     0,  1156,   134,
    1157,     0,     0,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
     301,   302,   303,   315,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,   301,   302,   303,
     315,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,   -11,     1,
       0,   -11,   -54,  1178,     0,  1179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
       0,     0,     0,     0,   131,     0,     0,     0,     0,   134,
       0,   -54,     0,     0,     0,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,     0,     0,     0,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,   538,    29,
      30,   539,   540,    33,    34,    35,     0,    36,     0,    38,
      39,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,     0,  1348,     0,  1349,   -54,   -54,   -54,  1353,    54,
       0,     0,   -54,     0,   -54,     0,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,     0,  1369,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
       0,     0,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     538,    29,    30,   539,   540,    33,    34,    35,     0,    36,
       0,    38,    39,     0,    41,    42,     0,   -54,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     0,   301,   302,
     303,    54,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,    67,
       0,     0,     0,     0,  1329,     0,  1330,     0,     0,    55,
      56,    57,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,    25,
       0,     0,   315,     0,     0,     0,     0,     0,     0,     0,
     737,   546,     0,     0,     0,     0,     0,  1471,     0,     0,
       0,     0,     0,     0,     0,  1479,  1480,     0,    26,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    67,    36,    37,    38,    39,    40,    41,    42,     0,
       0,     0,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,     0,     0,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,   769,     0,     0,     0,   315,     0,     0,
       0,     0,    55,    56,    57,   738,     0,     0,     0,    58,
       0,    59,     0,    60,    61,    62,    63,    64,    65,    66,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,  1568,
     315,     0,  1572,     0,     0,     0,     0,     0,   898,     0,
       0,     0,     0,     0,   204,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1658,   205,
     206,   207,     0,     0,     0,     0,  1666,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,     0,   228,   229,   230,   231,
     232,   233,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   626,     0,   301,   302,   303,
    1154,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
       0,   960,  1739,     0,     0,  1351,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,     0,
       0,   301,   302,   303,  1352,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,     0,     0,     0,     0,     0,  1408,
    1791,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,     0,     0,   301,   302,   303,  1410,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,     0,
       0,     0,  1845,     0,  1416,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,     0,     0,
     301,   302,   303,  1419,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,  1890,     0,     0,  1420,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,     0,     0,     0,     0,     0,  1465,     0,     0,
     301,   302,   303,  1928,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,   301,   302,   303,  1522,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,     0,     0,
     301,   302,   303,  1524,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,   301,   302,   303,  1527,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,     0,     0,
     301,   302,   303,  1764,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,     0,     0,   301,   302,   303,  1817,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,   524,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,   525,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,   555,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
     675,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,   676,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,   689,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,   690,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,   691,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,   692,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,   693,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,   694,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,   751,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,   752,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
     753,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,   896,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,   897,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,   916,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1051,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1052,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1066,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1067,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1098,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1099,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1100,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1101,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1102,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1103,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1104,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1105,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1106,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1107,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1108,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1109,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1110,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1111,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1112,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1113,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1114,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1115,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1116,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1117,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1118,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1119,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1120,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1121,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1122,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1123,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1139,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1264,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1265,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1274,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1277,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1288,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1293,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1296,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1298,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1299,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1300,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1301,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1302,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1304,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1305,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1306,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1307,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1308,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1309,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1310,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1311,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1312,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1313,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1314,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1315,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1316,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1317,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1318,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1319,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1320,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1321,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1322,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1323,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1327,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1429,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1441,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1442,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1443,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1444,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1445,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1446,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1447,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1448,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1449,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1450,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1451,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1452,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1453,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1454,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1455,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1456,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1457,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1458,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1459,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1460,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1461,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1463,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1540,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1541,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1542,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1543,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1544,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1545,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1546,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1547,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1548,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1549,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1550,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1551,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1552,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1553,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1554,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1555,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1556,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1557,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1558,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1559,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1560,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1631,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1632,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1633,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1634,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1635,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1636,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1637,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1638,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1639,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1640,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1641,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1642,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1643,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1644,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1645,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1646,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1647,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1648,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1649,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1650,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1651,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1705,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1712,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1713,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1714,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1715,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1716,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1717,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1718,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1719,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1720,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1721,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1722,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1723,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1724,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1725,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1726,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1727,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1728,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1729,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1763,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1771,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1772,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1773,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1774,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1775,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1776,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1777,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1778,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1779,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1780,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1781,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1782,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1783,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1784,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1785,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1786,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1787,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1788,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1826,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1827,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1828,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1829,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1830,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1831,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1832,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1833,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1834,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1835,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1836,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1837,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1838,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1839,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1840,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1841,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1842,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1843,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1875,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1876,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1877,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1878,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1879,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1880,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1881,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1882,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1883,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1884,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1885,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1886,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1887,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1888,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1889,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1913,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1914,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1915,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1916,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1917,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1918,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1919,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1920,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1921,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1922,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1923,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1924,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1925,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1926,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1927,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1957,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1958,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1959,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1960,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1961,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  1962,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  1963,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  1964,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  1965,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  1966,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    1967,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  1968,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  1969,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  1970,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  1971,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  2001,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  2002,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  2003,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  2004,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  2005,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    2006,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  2007,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  2008,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  2009,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  2032,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  2033,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  2034,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  2035,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  2036,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  2037,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    2038,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  2039,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  2040,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  2074,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  2075,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  2076,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  2077,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  2078,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  2079,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  2080,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    2081,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  2082,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  2104,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  2105,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  2106,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  2107,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  2108,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  2109,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  2122,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  2123,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    2124,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  2125,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  2126,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  2127,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  2143,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  2144,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  2145,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  2146,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  2147,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  2148,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    2167,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  2168,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  2169,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  2179,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  2180,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  2181,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  2194,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  2195,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
       0,   301,   302,   303,  2196,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,     0,   301,   302,   303,  2212,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,     0,   301,   302,   303,
    2213,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,     0,
     301,   302,   303,  2214,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,     0,   301,   302,   303,  2218,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,     0,   301,   302,   303,  2219,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,     0,   301,
     302,   303,  2220,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,     0,   301,   302,   303,  2224,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,     0,   301,   302,   303,  2225,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,     0,   301,   302,
     303,  2226,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,   301,
     302,   303,   472,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
     301,   302,   303,   597,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,   301,   302,   303,   654,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,   301,   302,   303,   656,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,   301,   302,   303,   658,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,   301,   302,   303,   660,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,   301,   302,   303,   662,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,   301,   302,   303,   664,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,   301,   302,   303,
     666,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,   301,   302,
     303,   668,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,   301,
     302,   303,   670,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
     301,   302,   303,   672,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,   301,   302,   303,   674,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,   301,   302,   303,   678,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,   301,   302,   303,   680,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,   301,   302,   303,   682,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,   301,   302,   303,   684,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,   301,   302,   303,   686,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,   301,   302,   303,
     688,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,   301,   302,
     303,   754,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,   301,
     302,   303,   759,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
     301,   302,   303,   988,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,   301,   302,   303,   990,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,   301,   302,   303,   992,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,   301,   302,   303,   994,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,   301,   302,   303,   995,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,   301,   302,   303,  1132,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,   466,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
     496,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,   497,   301,   302,   303,     0,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,   498,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,   500,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,   502,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,   503,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,   510,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,   549,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,   550,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,   553,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
     559,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,   653,   301,   302,   303,     0,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,   655,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,   657,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,   659,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,   661,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,   663,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,   665,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,   667,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,   669,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
     671,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,   673,   301,   302,   303,     0,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,   677,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,   679,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,   681,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,   683,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,   685,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,   687,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,   720,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,   722,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
     734,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,   735,   301,   302,   303,     0,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,   739,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,   740,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,   741,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,   742,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,   743,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,   765,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,   772,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,   987,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
     989,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,   991,   301,   302,   303,     0,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,   993,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,  1055,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,  1155,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,  1182,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,  1283,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,  1287,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,  1289,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,  1432,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
    1434,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,  1436,   301,   302,   303,     0,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,  1438,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,  1439,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,  1440,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,  1462,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,  1562,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,  1709,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,  1710,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,  1711,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
    1872,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,  1873,   301,   302,   303,     0,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,  1874,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,  1995,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,  1996,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,  1997,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,  1998,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,  1999,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315,     0,  2000,   301,   302,   303,     0,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
       0,     0,     0,     0,     0,   315,     0,  2110,   301,   302,
     303,     0,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,     0,     0,     0,     0,     0,   315,     0,
    2111,   301,   302,   303,     0,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,     0,     0,     0,     0,
       0,   315,     0,  2112,   301,   302,   303,     0,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,     0,
       0,     0,     0,     0,   315,     0,  2170,   301,   302,   303,
       0,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,     0,     0,     0,     0,     0,   315,     0,  2171,
     301,   302,   303,     0,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,     0,     0,     0,     0,     0,
     315,     0,  2172,   301,   302,   303,     0,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   315,     0,  2230,   301,   302,   303,     0,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,     0,     0,     0,     0,     0,   315,     0,  2231,   301,
     302,   303,     0,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,     0,   315,
       0,  2232,   301,   302,   303,     0,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,     0,     0,     0,
       0,     0,   315
};

static const short yycheck[] =
{
      25,    92,   353,    25,   295,   712,   328,     4,     4,  1263,
       4,     4,     4,     3,    45,    46,    64,   179,    42,     4,
       6,   183,     6,    64,     7,    64,   285,   286,   287,  1172,
       4,   101,     4,    65,   194,     6,     6,  1340,    70,    65,
     200,  1344,    65,   164,    70,    65,    65,    70,    84,    65,
      70,    70,   191,   192,    70,    65,   183,   184,  1073,   198,
      70,     0,   293,   183,   184,   194,     7,  1082,     4,     5,
     194,   200,     5,   200,  1089,     6,   183,   184,    49,   199,
      38,    39,    40,    41,    42,    43,    44,    45,   194,    47,
     196,    49,    50,   200,    52,    53,     6,   328,    34,    35,
      36,    34,    35,    36,   129,   130,   131,     6,     7,   134,
     135,    69,   137,   195,   194,   183,   184,   199,   115,   144,
     145,   146,   194,   148,   194,   150,   151,   195,   153,     6,
     104,   105,   104,   105,  1277,   166,     6,   168,   195,    97,
      98,    99,   199,   174,   169,   170,   194,     6,   183,   184,
     183,   184,   200,   860,    38,   194,   194,    41,    42,   200,
      44,     7,   195,   188,   189,   200,   191,   203,   193,   201,
     194,   196,   197,   495,     6,   201,   183,   184,   201,   183,
     184,   472,   201,   194,   506,   201,   169,   170,   171,   172,
     194,   201,   199,   194,   184,     8,   200,   183,   184,   183,
     184,   159,    38,   200,   200,    41,   200,   200,   200,   194,
     241,   373,    38,   238,   473,    41,    42,   194,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
       7,    64,  1565,  1278,   495,     3,  1569,  1282,   293,  1523,
     191,   192,  1526,   295,     7,   506,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   183,   184,   195,    46,   195,   321,   199,   323,   199,
     195,  1008,   327,   328,   199,    55,    56,   199,   333,   334,
     335,   194,   337,   338,   339,   340,   341,   342,   343,   350,
     351,   183,   184,   169,   170,   171,   172,   183,   184,   194,
     355,   356,   357,   358,   183,   184,   361,   199,   195,   201,
     183,   184,   199,   199,   369,   191,   192,   185,   186,   187,
     199,    42,   198,   378,  1657,   193,   199,   194,  1661,  1613,
     173,   174,   175,  1617,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,     8,   698,   183,   184,    42,
     193,   183,   184,   185,   186,   187,    42,    44,   201,   183,
     184,   193,   200,   199,   416,   201,   134,   135,   136,   137,
     138,   139,   140,   141,   726,   199,   194,   201,   196,     6,
       7,  1426,  1427,  1428,  1429,   183,   184,   194,  1433,   196,
     194,   200,   169,   170,   171,   172,     6,    58,    59,    60,
      61,   199,    63,   755,   756,   757,   169,   170,   171,   172,
     699,    42,     6,   468,   191,   192,   183,   184,     6,   474,
     472,   194,   183,   184,   194,   194,   191,   192,   191,   192,
       6,   196,   199,   198,   194,    42,   196,   698,   199,     3,
     495,   702,     4,   191,   192,   194,     4,   196,   196,   504,
     198,   506,   194,   508,   509,   194,   191,   192,   194,   514,
      54,   196,   523,   198,   194,   726,   196,   194,     5,   524,
     525,   119,   120,   121,   122,   123,    41,    42,   533,    44,
     194,   194,   196,   196,     6,     6,  1531,  1532,     5,   544,
    1535,   194,   194,   196,   755,   756,   757,   194,   194,   196,
     555,   200,   557,   558,   194,   194,   196,   196,   200,  1246,
     173,   174,   175,   194,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   877,   194,   194,   196,   196,
     193,   852,   853,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   194,     3,     4,   597,   196,   193,   198,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   194,   200,   196,  1621,   194,   194,   173,
     174,   175,   194,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   194,   194,   196,   196,   194,   193,
     175,   194,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   194,     4,   196,   877,     8,   193,   196,
     675,   676,   194,   194,   196,   196,   194,   200,   196,   199,
     199,   201,   201,   200,   689,   690,   691,   692,   693,   694,
     695,   200,     8,   698,   199,   196,   201,   702,     6,   199,
     705,   201,   199,   199,   201,   201,   717,   198,   200,   714,
    1041,   199,  1707,   201,   199,   199,   201,   201,   199,   107,
     201,   726,   727,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   199,   806,   201,     6,     5,   193,
     751,   752,   753,   199,   199,   201,   201,   199,   194,   201,
     755,   756,   757,   194,   194,   760,   761,   199,   193,   764,
       6,  1000,   199,   199,   201,   201,   777,   199,   194,   201,
     775,   776,  1767,   183,   184,   786,   199,   194,   201,   189,
     199,   199,   201,   201,   194,   194,   199,   197,   201,   194,
     200,   199,   199,   201,   201,   199,   194,   201,  1037,   199,
     199,   201,   201,   194,   194,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     825,   826,   827,   828,   829,   830,   831,   832,   833,   834,
     835,   194,   173,   174,   175,   194,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   199,   199,   201,
     201,   853,   193,   199,   195,   201,   861,   173,   174,   175,
     194,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   877,   199,   879,   201,   881,   193,   199,   199,
     201,   201,   199,   194,   201,   199,   199,   201,   201,   199,
     895,   896,   897,   199,   199,   201,   201,   194,   194,   194,
     194,   194,   194,   194,   194,   921,   194,   194,   194,   194,
     194,   916,   917,   918,   194,   194,   194,   194,     4,   195,
       7,   195,     7,   198,     7,  1256,     7,   173,   174,   175,
       7,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     7,   102,   104,   200,   165,   193,     5,     5,
       5,     5,     3,     4,   152,  1950,     5,   959,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     5,     5,   199,     6,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,  1001,     5,     5,     5,
       5,     5,  1013,     5,     5,     5,    38,    39,    40,    41,
      42,    43,    44,    45,     5,    47,     5,    49,    50,     3,
      52,    53,  1027,  1028,  1095,     5,     5,   195,     6,     5,
       4,  1042,  1037,  1044,     6,  1046,     6,    69,     7,     7,
       7,     7,     7,     7,     7,   198,  1051,  1052,  1064,   201,
     201,   200,   200,     7,     7,   194,     7,   198,  1063,   166,
       5,  1066,   199,     6,   199,    97,    98,    99,   199,   199,
     199,  1076,   199,   199,   199,   199,   199,   199,  1083,  1084,
    1085,   199,   199,   199,   199,  1090,   199,   199,   199,  1094,
     199,   199,   195,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,   199,
     199,   199,   194,   199,   199,   199,   199,   159,   199,   199,
     199,   199,   183,   184,  1139,   194,   194,     6,   189,     4,
       6,   194,   194,   194,   194,     6,   197,   194,   194,   200,
     194,  1156,   173,   174,   175,   194,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   194,  1184,   201,
       3,     4,   193,  1178,   194,  1180,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       3,     4,   194,   197,   194,     6,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     173,   174,   175,   194,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   194,   194,   194,  1259,  1260,
     193,  1262,   194,   194,  1259,  1260,   194,  1262,   194,  1264,
    1265,   194,   194,   194,   194,     7,  1271,   196,     6,     4,
       7,     7,   200,     7,     7,  1280,     7,     7,     7,     7,
       7,     7,     7,  1288,     7,     6,     6,     4,  1293,     7,
     162,  1296,     7,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,     3,
       3,  1332,  1561,     3,  1329,   185,  1331,  1332,  1333,     3,
       3,     3,     3,     3,     3,   173,   174,   175,  1354,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     183,   184,     3,     3,     3,   193,   189,     3,     3,     3,
     195,   194,     5,   201,   197,     5,     3,   200,     6,     4,
     195,   198,   200,     7,     6,     6,     6,     6,     6,     6,
     183,   184,     6,   200,   103,   199,   189,   199,   195,   199,
     195,   194,     6,   199,   198,   195,     6,   200,     4,   195,
     199,   199,   199,   195,  1409,   199,  1411,     6,   199,  1425,
     199,   199,  1417,  1652,   199,  1654,   199,   195,   199,     6,
     199,   195,   199,   199,   199,     6,   199,   199,     6,   197,
       6,     6,     6,     6,     6,     6,  1441,  1442,  1443,  1444,
    1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1453,  1454,
    1455,  1456,  1457,  1458,  1459,  1460,  1461,     6,  1463,     6,
       6,     6,     6,   173,   174,   175,  1482,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     6,     6,
       6,     6,     6,   193,     7,   195,     3,     4,   103,   199,
       3,  1730,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     6,     3,     6,   185,
       3,     6,     6,     3,     6,     6,     3,     6,     6,     3,
       3,     3,  1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,
    1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,
    1555,  1556,  1557,  1558,  1559,  1560,     3,     4,  1574,     4,
       6,   197,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   173,   174,   175,     6,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     6,   198,     7,  1620,     6,   193,     6,   200,   100,
     201,   200,   200,   195,  1619,   200,   199,     6,   195,   199,
    1625,     6,  1627,     3,  1629,   195,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,   199,  1664,   199,
     105,   199,   195,   103,   195,   195,   152,   199,   195,   162,
     199,   157,   195,   199,     6,     6,   183,   184,     3,     6,
       6,     5,   189,     6,     6,     6,     6,   194,     6,     3,
       6,     6,     5,   200,   180,   201,     6,   201,   200,   200,
     186,   187,   199,   199,   199,   199,   195,   195,   199,  1704,
    1705,   195,   199,     6,   199,     6,     6,  1712,  1713,  1714,
    1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,   183,   184,     5,     5,
     200,   199,   189,   200,   195,   199,     6,   194,   201,     6,
     199,   199,   195,   200,     6,   199,     6,   199,  1763,   200,
     200,   200,   200,  1768,  1769,  1770,  1771,  1772,  1773,  1774,
    1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,
    1785,  1786,  1787,  1788,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   162,
       6,     6,   100,     6,   193,     5,     5,   200,   200,   199,
     201,   195,   200,   199,   195,  1820,     6,  1822,   200,  1824,
       6,  1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,
    1835,  1836,  1837,  1838,  1839,  1840,  1841,  1842,  1843,   201,
     173,   174,   175,     6,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   100,     6,     6,     6,     6,
     193,     6,     6,     6,     6,     6,     6,     6,   167,     6,
    1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,  1884,
    1885,  1886,  1887,  1888,  1889,   201,   200,   199,   199,   199,
     199,     6,   200,   200,   200,   199,     6,     6,   168,   195,
       6,     6,     6,   200,   199,  1910,  1911,  1912,  1913,  1914,
    1915,  1916,  1917,  1918,  1919,  1920,  1921,  1922,  1923,  1924,
    1925,  1926,  1927,   173,   174,   175,     6,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   199,     6,
       6,   200,   200,   193,   199,     6,  1951,   195,  1953,   200,
    1955,   200,  1957,  1958,  1959,  1960,  1961,  1962,  1963,  1964,
    1965,  1966,  1967,  1968,  1969,  1970,  1971,   200,   173,   174,
     175,   467,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   200,   200,   200,     6,     6,   193,     6,
       6,     6,     6,   200,     6,     6,  2001,  2002,  2003,  2004,
    2005,  2006,  2007,  2008,  2009,   200,   200,     6,   200,   200,
       6,   200,     6,     6,     6,   200,   200,   200,     6,     6,
     599,  2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,  2034,
    2035,  2036,  2037,  2038,  2039,  2040,   173,   174,   175,     8,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     8,     8,    -1,  1057,    -1,   193,  2062,  1004,  2064,
      -1,  2066,    -1,  2068,    -1,  2070,    -1,  2072,    -1,  2074,
    2075,  2076,  2077,  2078,  2079,  2080,  2081,  2082,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2104,
    2105,  2106,  2107,  2108,  2109,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2122,  2123,  2124,
    2125,  2126,  2127,  2128,  2129,  2130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2143,  2144,
    2145,  2146,  2147,  2148,  2149,    -1,  2151,    -1,  2153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2167,  2168,  2169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2179,  2180,  2181,  2182,  2183,  2184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2194,
    2195,  2196,  2197,    -1,  2199,    -1,  2201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2212,  2213,  2214,
      -1,    -1,    -1,  2218,  2219,  2220,    -1,    -1,    -1,  2224,
    2225,  2226,   718,   719,    -1,   721,    -1,   723,   724,    -1,
      -1,  2236,  2237,  2238,    -1,    -1,    -1,    -1,    -1,    -1,
    2245,    -1,  2247,    -1,  2249,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,   762,   763,    -1,    -1,
     766,    -1,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   783,   784,    -1,
      -1,    -1,   193,   789,   790,    -1,    -1,     3,     4,     5,
     796,     7,   798,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    35,
      36,     3,     4,     5,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   870,    -1,   872,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,   882,   883,   884,    -1,
      -1,   887,   888,   889,   890,   891,   892,   893,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     8,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,   183,   184,    -1,
      -1,    -1,    -1,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   999,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,    -1,    -1,    -1,    -1,   189,     3,     4,
      -1,    -1,   194,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,  1059,    -1,    -1,    -1,    -1,   193,    -1,
      -1,  1067,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,
    1086,    -1,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,   183,   184,
      -1,    -1,   193,    -1,   189,    -1,    -1,    -1,   199,   194,
     201,    -1,    -1,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
     173,   174,   175,   193,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,   173,   174,   175,
     193,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,     0,     1,
      -1,     3,     4,   199,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
      -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,   194,
      -1,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    -1,    49,
      50,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1268,    -1,  1270,    97,    98,    99,  1274,    69,
      -1,    -1,   104,    -1,   106,    -1,   108,   109,   110,   111,
     112,   113,   114,    -1,  1290,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    47,
      -1,    49,    50,    -1,    52,    53,    -1,   159,   160,   161,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   173,   174,
     175,    69,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,   159,
      -1,    -1,    -1,    -1,   199,    -1,   201,    -1,    -1,    97,
      98,    99,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,     4,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,   201,    -1,    -1,    -1,    -1,    -1,  1413,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1421,  1422,    -1,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   159,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      65,    66,    67,    68,    69,    -1,    -1,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,   201,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    97,    98,    99,   201,    -1,    -1,    -1,   104,
      -1,   106,    -1,   108,   109,   110,   111,   112,   113,   114,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,  1525,
     193,    -1,  1528,    -1,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1614,   116,
     117,   118,    -1,    -1,    -1,    -1,  1622,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   201,    -1,   173,   174,   175,
     201,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,   201,  1708,    -1,    -1,   201,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,   173,   174,   175,   201,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
    1766,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,    -1,   173,   174,   175,   201,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,
      -1,    -1,  1818,    -1,   201,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
     173,   174,   175,   201,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,  1871,    -1,    -1,   201,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
     173,   174,   175,  1909,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,   173,   174,   175,   201,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
     173,   174,   175,   201,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,   173,   174,   175,   201,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,
     173,   174,   175,   201,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,    -1,    -1,   173,   174,   175,   201,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
      -1,   173,   174,   175,   199,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,    -1,   173,   174,   175,   199,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,
     199,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
     173,   174,   175,   199,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,    -1,   173,   174,   175,   199,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,
     174,   175,   199,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,    -1,   173,   174,   175,   199,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,    -1,   173,   174,   175,   199,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,   173,   174,
     175,   199,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,   173,
     174,   175,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
     173,   174,   175,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,   173,   174,   175,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,   173,   174,   175,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,   173,   174,   175,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,   173,   174,   175,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,   173,   174,   175,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,   173,   174,   175,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,   173,   174,   175,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,   173,   174,
     175,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,   173,
     174,   175,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
     173,   174,   175,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,   173,   174,   175,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,   173,   174,   175,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,   173,   174,   175,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,   173,   174,   175,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,   173,   174,   175,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,   173,   174,   175,   197,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,   173,   174,   175,
     197,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,   173,   174,
     175,   197,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,   173,
     174,   175,   197,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
     173,   174,   175,   197,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,   173,   174,   175,   197,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,   173,   174,   175,   197,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,   173,   174,   175,   197,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,   173,   174,   175,   197,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,   173,   174,   175,   197,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
      -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,
     175,    -1,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,
     195,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,   193,    -1,   195,   173,   174,   175,    -1,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
     193,    -1,   195,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,   193,    -1,   195,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,    -1,    -1,   193,    -1,   195,   173,
     174,   175,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,   193,
      -1,   195,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      -1,    -1,   193
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     1,   160,   161,   163,   203,   205,   206,   211,     6,
     164,     0,     3,   134,   135,   136,   137,   138,   139,   140,
     141,   207,   208,   209,   210,     4,    33,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    47,    48,    49,    50,
      51,    52,    53,    57,    58,    59,    60,    61,    62,    63,
      65,    66,    67,    68,    69,    97,    98,    99,   104,   106,
     108,   109,   110,   111,   112,   113,   114,   159,   212,   213,
     214,   296,   297,   298,   301,   302,   303,   304,   305,   306,
     315,   316,     3,   184,   204,     7,     6,     6,     6,     6,
       6,   194,   194,   194,     3,     4,     5,     7,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    34,    35,    36,   169,   170,   171,   172,   183,
     184,   189,   191,   192,   194,   196,   198,   294,   295,   318,
     319,   332,   194,     6,   194,   194,   194,    64,   194,    64,
     194,   194,    46,   194,    42,    42,    42,    41,    42,    44,
      44,    38,    41,    42,    44,   194,   200,   183,   184,   194,
     200,   320,   321,   320,   200,    38,    41,    42,     4,   200,
      42,     4,   115,   200,     6,     6,    38,    41,   194,   194,
      42,   194,     4,   200,   329,     4,   194,   194,     6,     4,
       4,    42,     3,   204,    41,   116,   117,   118,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   153,   154,
     155,   156,   157,   158,   194,   322,   322,     5,   196,   198,
     295,     4,   200,   194,   196,   194,   196,   194,   196,   194,
     196,   194,   196,   194,   196,   194,   196,   194,   196,   194,
     196,   194,   196,   194,   196,   194,   196,   194,   196,   194,
     196,   194,   196,   194,   196,   194,   196,   194,   196,   194,
     196,   194,   196,   194,   196,   194,   194,   194,   318,   318,
     318,   318,   197,   200,   318,     4,   104,   105,   318,     6,
       6,   173,   174,   175,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   193,     6,     5,   318,   318,
     318,   194,   318,   194,   318,   318,     4,   184,   200,   318,
     326,   327,   318,   200,   194,   194,   326,   200,   200,   194,
     194,   194,   194,   194,     4,   320,   320,   320,   318,   318,
     183,   184,   200,   200,   320,   200,   200,   200,   196,   300,
     326,   196,     6,   300,   326,   326,   318,   318,   101,   194,
     318,   198,   318,   200,   107,   318,   318,     6,   194,   204,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
       5,   323,   199,   195,   199,   318,     4,   320,   215,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,     4,     5,   332,   332,   332,   195,     7,   184,   318,
     327,   328,   197,     7,   294,   295,   198,     7,     6,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   195,   199,   195,   195,   195,   318,
     195,   318,   195,   195,   196,     4,   200,   328,     8,     7,
     195,   318,   318,   318,     7,   318,   318,   318,   318,   318,
     318,   318,   195,   199,   199,   199,   320,   320,   298,   299,
     300,   301,   299,   199,   318,   318,   318,   318,    38,    41,
      42,   201,   297,     6,     7,   318,   201,     7,     7,   195,
     195,   102,   318,   195,   104,   199,   300,   200,     8,   195,
     318,   165,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,   152,     5,     5,     5,     5,
       3,     5,   195,   199,     5,     6,     5,   197,   295,   200,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   201,   217,   220,   223,
     226,   229,   232,   235,   238,   241,   244,   247,   250,   253,
     256,   259,   262,   265,   268,   271,   274,   277,   280,   283,
     286,   289,   292,   195,   197,   195,   197,   195,   197,   195,
     197,   195,   197,   195,   197,   195,   197,   195,   197,   195,
     197,   195,   197,   195,   197,   199,   199,   195,   197,   195,
     197,   195,   197,   195,   197,   195,   197,   195,   197,   199,
     199,   199,   199,   199,   199,   196,   198,   195,   199,   199,
     195,   326,   199,   201,   198,   294,   295,   332,   318,     6,
       4,     4,   200,   330,     8,     6,   328,     7,     7,     7,
     195,     7,   195,     7,     7,   197,   200,   196,   328,   201,
     318,   318,     7,   201,   195,   195,   318,   201,   201,   195,
     195,   195,   195,   195,   198,   320,   318,   318,   201,   201,
     318,   199,   199,   199,   197,   200,   200,   200,   318,   197,
     200,   200,     7,     7,   194,   195,     7,   198,   318,   201,
     318,   318,   195,   166,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,     5,   195,   199,   198,   295,   215,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,     6,   318,   318,   318,
     318,   318,   318,   318,   318,   318,     4,   328,   332,     6,
     318,   327,   197,     4,   104,   105,   318,     6,     6,     6,
       7,   196,   329,   331,     6,   318,   195,   320,   326,   326,
       7,   326,     7,   326,   326,   328,   197,   200,   201,     8,
       6,   200,     7,     7,     7,     6,    54,     7,     7,     7,
       7,     7,     7,     7,     4,   199,   199,   199,   201,   320,
     320,   320,     6,   328,   328,   328,     6,     6,   318,   318,
     326,   326,   318,     7,   326,     4,   199,     8,     8,   195,
       7,   162,     3,   318,   318,   320,     3,     3,   185,     3,
       3,   326,   326,     3,   320,     3,     3,   326,   326,     3,
       3,     3,     3,     3,   326,   119,   120,   121,   122,   123,
     317,   326,     3,     5,     5,     3,     3,     6,   322,     4,
     201,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   195,   197,   195,
     197,   195,   197,   195,   197,   197,   195,   195,   195,   294,
       7,   294,   295,   198,     7,     6,   329,   318,   199,   201,
       6,     6,     6,    49,     6,   326,     6,   326,     6,     6,
     201,   328,   318,   318,   326,   326,   326,    55,    56,   326,
     326,   326,   326,   326,   326,   326,     6,     7,   318,   318,
     318,   200,   199,   201,   199,   201,   199,   201,   201,   201,
     201,   199,   199,     6,     6,   195,   194,   200,   324,   103,
     318,   318,   318,   200,   204,   199,   199,   199,   195,   199,
     195,   199,   195,   199,   195,   199,   199,   195,   199,   195,
     195,   199,   199,   199,   199,   199,   199,   195,   199,   199,
     199,   199,   199,   195,   199,   199,   295,     6,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   198,   326,   332,   318,     6,     4,
     330,     6,   197,   329,   320,     6,     6,   197,   201,   199,
       6,     6,     6,   318,   318,     6,     6,     6,     6,     6,
       6,     6,   318,   332,   201,   195,   199,   201,   299,   320,
       6,   320,     6,   307,   320,     6,   310,     6,     6,     6,
     318,   318,     7,   325,   326,   325,   103,   326,   199,   201,
       8,   201,   195,   318,   204,     3,   318,   326,     6,     3,
       6,   185,     6,   317,     6,     3,   318,     6,     3,     6,
       6,     3,   317,   318,   318,   318,   326,     6,     3,   317,
     318,     3,     3,     6,   318,   322,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,     4,     6,     6,     6,     7,     6,   198,     6,
     197,   318,     6,     6,     6,     6,   200,   318,   201,   199,
     199,   200,   199,   200,   199,   199,   324,   195,   199,   201,
     200,   100,   318,   318,   199,   204,   195,   199,   199,   199,
     199,   195,   199,   195,   199,   195,   195,   195,   199,   195,
     199,   195,   195,   199,   199,   195,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   195,   329,   105,   199,   299,   199,
     201,   183,   184,   194,   318,   320,   318,   320,    65,    70,
     313,   314,   318,   320,   313,   318,   318,   103,   326,   326,
     318,   201,   201,   326,   162,     6,   324,   317,     3,   318,
       6,   317,     6,     3,     6,     6,     6,   318,     6,   326,
       6,     6,   318,     3,     6,   318,     5,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,     6,     5,   201,   318,   318,   201,   199,
     201,   199,     6,   200,   201,   314,   201,   199,   201,   201,
     201,   200,   199,     6,   201,   204,   199,   199,   199,   199,
     195,   195,   195,   199,   195,   195,   195,   199,   195,   195,
     195,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   195,   199,   199,   201,     6,   318,     6,   308,
     318,   326,     6,     6,   311,   318,     6,     6,     6,   326,
     326,     6,   204,   317,   317,   317,   317,     6,     6,     6,
     317,     6,     6,     6,     5,   218,   221,   224,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   290,
     318,     5,   201,   200,   201,   199,   200,   201,   199,   201,
     204,   199,   199,   195,   195,   199,   199,   200,   200,   200,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   200,   195,   199,     6,   313,     6,   309,   326,   313,
       6,   312,   326,   100,   162,   317,   317,     6,     6,   317,
       5,   216,   318,   219,   318,   222,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   288,   332,
     293,     5,   201,   200,   199,   201,   201,   200,   201,   200,
     204,   199,   199,   195,   195,   199,   201,   199,   201,   199,
     201,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   201,   200,   201,     6,   313,   326,     6,
       6,   313,   100,   318,   204,   317,   326,     6,     6,   318,
       6,   318,     6,   318,     6,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   332,     6,   291,   332,
       6,   201,   201,   201,   200,   199,   204,   199,   199,   195,
     195,   195,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   201,     6,     6,     6,   318,   318,   167,   317,   326,
     227,   230,   233,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   332,     6,   199,   201,   168,   199,   199,   200,   200,
     200,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   318,
       6,   326,   317,   225,   318,   228,   318,   231,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   201,   199,   195,
     199,   201,   199,   201,   199,   201,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,     6,   326,     6,   318,     6,   318,
       6,   318,     6,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   199,   195,   195,   195,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     326,   236,   239,   242,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   199,
     200,   200,   200,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   326,   234,
     318,   237,   318,   240,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     199,   199,   201,   199,   201,   199,   201,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   317,   318,     6,   318,     6,   318,     6,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   195,   195,   195,   195,   195,   195,
     195,   199,   199,   199,   199,   199,   199,   199,   199,   199,
       6,   245,   248,   251,   254,   257,   260,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   200,   200,   200,   200,
     200,   200,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   243,   318,   246,   318,   249,   318,   252,   318,   255,
     318,   258,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   199,   201,   199,   201,   199,   201,   199,   201,
     199,   201,   199,   201,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   318,     6,   318,     6,   318,     6,   318,
       6,   318,     6,   318,     6,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   199,   199,   199,   199,   199,   199,
     195,   195,   195,   318,   318,   318,   318,   318,   318,   281,
     284,   287,   199,   199,   199,   199,   199,   199,   200,   200,
     200,   318,   318,   318,   318,   318,   318,   279,   318,   282,
     318,   285,   318,   199,   199,   199,   199,   199,   199,   199,
     201,   199,   201,   199,   201,   318,   318,   318,   318,   318,
     318,   318,     6,   318,     6,   318,     6,   199,   199,   199,
     195,   195,   195,   318,   318,   318,   272,   275,   278,   199,
     199,   199,   200,   200,   200,   318,   318,   318,   270,   318,
     273,   318,   276,   318,   199,   199,   199,   199,   201,   199,
     201,   199,   201,   318,   318,   318,   318,     6,   318,     6,
     318,     6,   199,   199,   199,   318,   318,   318,   199,   199,
     199,   318,   318,   318,   199,   199,   199,   318,   318,   318,
     195,   195,   195,   263,   266,   269,   200,   200,   200,   261,
     318,   264,   318,   267,   318,   199,   201,   199,   201,   199,
     201,   318,     6,   318,     6,   318,     6
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
#line 179 "Gmsh.y"
    { yyerrok ; return 1; }
    break;

  case 6:
#line 185 "Gmsh.y"
    { yyval.d = yyvsp[0].d; }
    break;

  case 7:
#line 186 "Gmsh.y"
    { yyval.d = -yyvsp[0].d; }
    break;

  case 8:
#line 191 "Gmsh.y"
    {
      yymsg(INFO, "STL file format");
      STL_Surf = Create_Surface(1,MSH_SURF_STL);
      STL_Surf->STL = new STL_Data;
      return 1;
    }
    break;

  case 9:
#line 205 "Gmsh.y"
    {
      STL_Surf->STL->Add_Facet( yyvsp[-12].d, yyvsp[-11].d, yyvsp[-10].d,
				yyvsp[-8].d, yyvsp[-7].d, yyvsp[-6].d,
				yyvsp[-4].d, yyvsp[-3].d, yyvsp[-2].d);
      return 1;
    }
    break;

  case 10:
#line 212 "Gmsh.y"
    {
      yymsg(INFO, "STL file format read");
      Tree_Add(THEM->Surfaces, &STL_Surf);
      return 1;
    }
    break;

  case 13:
#line 227 "Gmsh.y"
    { return 1; }
    break;

  case 14:
#line 228 "Gmsh.y"
    { return 1; }
    break;

  case 15:
#line 229 "Gmsh.y"
    { return 1; }
    break;

  case 16:
#line 234 "Gmsh.y"
    {
      yymsg(INFO, "Step Iso-10303-21 file format");
      Create_Step_Solid_BRep();
    }
    break;

  case 17:
#line 239 "Gmsh.y"
    {
      yymsg(INFO, "Step Iso-10303-21 file format read");
      Resolve_BREP ();
    }
    break;

  case 21:
#line 250 "Gmsh.y"
    {
    }
    break;

  case 22:
#line 253 "Gmsh.y"
    {
    }
    break;

  case 23:
#line 257 "Gmsh.y"
    {
   }
    break;

  case 24:
#line 263 "Gmsh.y"
    {
        Add_Cartesian_Point((int)yyvsp[-8].d,yyvsp[-4].c,yyvsp[-2].v[0],yyvsp[-2].v[1],yyvsp[-2].v[2]);
    }
    break;

  case 25:
#line 269 "Gmsh.y"
    {
       Add_BSpline_Curve_With_Knots ((int)yyvsp[-22].d, yyvsp[-18].c, (int) yyvsp[-16].d, yyvsp[-14].l,	yyvsp[-6].l, yyvsp[-4].l, 0., 1.);
    }
    break;

  case 26:
#line 276 "Gmsh.y"
    {
      Add_BSpline_Surface_With_Knots ((int)yyvsp[-30].d, yyvsp[-26].c, (int) yyvsp[-24].d, (int) yyvsp[-22].d, yyvsp[-20].l, yyvsp[-10].l,
				      yyvsp[-8].l, yyvsp[-6].l, yyvsp[-4].l, 0., 1., 0., 1. );
    }
    break;

  case 27:
#line 282 "Gmsh.y"
    {
      Add_Edge_Curve ((int)yyvsp[-14].d, yyvsp[-10].c , (int)yyvsp[-8].d , (int)yyvsp[-6].d, (int)yyvsp[-4].d);
    }
    break;

  case 28:
#line 286 "Gmsh.y"
    {
      Add_Face_Outer_Bound((int)yyvsp[-10].d,yyvsp[-6].c,(int)yyvsp[-4].d,yyvsp[-2].i,1);
    }
    break;

  case 29:
#line 290 "Gmsh.y"
    {
      // check the norm! Face_Bound : hole outside surface!
      yymsg(INFO, "Found a face bound");
      Add_Face_Outer_Bound((int)yyvsp[-10].d,yyvsp[-6].c,(int)yyvsp[-4].d,yyvsp[-2].i,0);
    }
    break;

  case 30:
#line 297 "Gmsh.y"
    {
      Add_Oriented_Edge((int)yyvsp[-14].d,yyvsp[-10].c,(int)yyvsp[-4].d,yyvsp[-2].i);
    }
    break;

  case 31:
#line 301 "Gmsh.y"
    {
      Add_Edge_Loop((int)yyvsp[-8].d,yyvsp[-4].c,yyvsp[-2].l);
    }
    break;

  case 32:
#line 306 "Gmsh.y"
    {
      Add_Advanced_Face((int)yyvsp[-12].d,yyvsp[-8].c,yyvsp[-6].l,(int)yyvsp[-4].d,yyvsp[-2].i);
    }
    break;

  case 33:
#line 310 "Gmsh.y"
    {
      Add_Vertex_Point((int)yyvsp[-8].d,yyvsp[-4].c,(int)yyvsp[-2].d);
    }
    break;

  case 34:
#line 314 "Gmsh.y"
    {
    }
    break;

  case 35:
#line 318 "Gmsh.y"
    {
      Add_Axis2_Placement3D  ( (int)yyvsp[-12].d, (int)yyvsp[-4].d, (int)yyvsp[-2].d, (int)yyvsp[-6].d);
    }
    break;

  case 36:
#line 322 "Gmsh.y"
    {
      Add_Direction((int)yyvsp[-8].d , yyvsp[-4].c, yyvsp[-2].v[0], yyvsp[-2].v[1], yyvsp[-2].v[2]);
    }
    break;

  case 37:
#line 326 "Gmsh.y"
    {
      Add_Plane((int)yyvsp[-8].d,yyvsp[-4].c,(int)yyvsp[-2].d);
    }
    break;

  case 38:
#line 330 "Gmsh.y"
    {
      Add_Line ((int)yyvsp[-10].d, yyvsp[-6].c , (int) yyvsp[-4].d, (int)yyvsp[-2].d);
    }
    break;

  case 39:
#line 334 "Gmsh.y"
    {
      yymsg(INFO, "Found a closed shell");
      Add_Closed_Shell((int)yyvsp[-8].d, yyvsp[-4].c , yyvsp[-2].l);
    }
    break;

  case 40:
#line 340 "Gmsh.y"
    {
    }
    break;

  case 41:
#line 343 "Gmsh.y"
    {
    }
    break;

  case 42:
#line 346 "Gmsh.y"
    {
      Add_Cylinder ((int)yyvsp[-10].d, yyvsp[-6].c , (int)yyvsp[-4].d, yyvsp[-2].d);
    }
    break;

  case 43:
#line 350 "Gmsh.y"
    {
      Add_Cone ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d,yyvsp[-2].d);
    }
    break;

  case 44:
#line 354 "Gmsh.y"
    {
      Add_Torus ((int)yyvsp[-12].d, yyvsp[-8].c , (int)yyvsp[-6].d, yyvsp[-4].d,yyvsp[-2].d);
    }
    break;

  case 45:
#line 358 "Gmsh.y"
    {
      Add_Circle((int) yyvsp[-10].d, yyvsp[-6].c, (int) yyvsp[-4].d, yyvsp[-2].d);
    }
    break;

  case 46:
#line 362 "Gmsh.y"
    {
      Add_Ellipse((int) yyvsp[-12].d, yyvsp[-8].c, (int) yyvsp[-6].d, yyvsp[-4].d, yyvsp[-2].d);
    }
    break;

  case 47:
#line 367 "Gmsh.y"
    {
    }
    break;

  case 48:
#line 370 "Gmsh.y"
    {
    }
    break;

  case 49:
#line 374 "Gmsh.y"
    {
    }
    break;

  case 50:
#line 377 "Gmsh.y"
    {
    }
    break;

  case 51:
#line 381 "Gmsh.y"
    {
    }
    break;

  case 52:
#line 384 "Gmsh.y"
    {
    }
    break;

  case 53:
#line 387 "Gmsh.y"
    {
    }
    break;

  case 54:
#line 395 "Gmsh.y"
    {
  }
    break;

  case 55:
#line 398 "Gmsh.y"
    {
      yymsg(INFO, "Gmsh file format read");
    }
    break;

  case 56:
#line 404 "Gmsh.y"
    { return 1; }
    break;

  case 57:
#line 405 "Gmsh.y"
    { return 1; }
    break;

  case 58:
#line 406 "Gmsh.y"
    { return 1; }
    break;

  case 59:
#line 407 "Gmsh.y"
    { return 1; }
    break;

  case 60:
#line 408 "Gmsh.y"
    { return 1; }
    break;

  case 61:
#line 409 "Gmsh.y"
    { return 1; }
    break;

  case 62:
#line 410 "Gmsh.y"
    { return 1; }
    break;

  case 63:
#line 411 "Gmsh.y"
    { return 1; }
    break;

  case 64:
#line 412 "Gmsh.y"
    { return 1; }
    break;

  case 65:
#line 413 "Gmsh.y"
    { return 1; }
    break;

  case 66:
#line 414 "Gmsh.y"
    { return 1; }
    break;

  case 67:
#line 415 "Gmsh.y"
    { return 1; }
    break;

  case 68:
#line 416 "Gmsh.y"
    { return 1; }
    break;

  case 69:
#line 421 "Gmsh.y"
    {
      Msg(DIRECT, yyvsp[-2].c);
    }
    break;

  case 70:
#line 425 "Gmsh.y"
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
#line 441 "Gmsh.y"
    { 
      if(!strcmp(yyvsp[-5].c, "View")) EndView(View, 1, yyname, yyvsp[-4].c); 
    }
    break;

  case 72:
#line 445 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-7].c, "View")) EndView(View, 1, yyname, yyvsp[-6].c);
    }
    break;

  case 73:
#line 452 "Gmsh.y"
    {
      View = BeginView(1); 
    }
    break;

  case 100:
#line 485 "Gmsh.y"
    { List_Add(View->SP, &yyvsp[0].d) ; }
    break;

  case 101:
#line 487 "Gmsh.y"
    { List_Add(View->SP, &yyvsp[0].d) ; }
    break;

  case 102:
#line 492 "Gmsh.y"
    { 
      List_Add(View->SP, &yyvsp[-5].d); List_Add(View->SP, &yyvsp[-3].d);
      List_Add(View->SP, &yyvsp[-1].d);
    }
    break;

  case 103:
#line 497 "Gmsh.y"
    {
      View->NbSP++ ;
    }
    break;

  case 104:
#line 504 "Gmsh.y"
    { List_Add(View->VP, &yyvsp[0].d) ; }
    break;

  case 105:
#line 506 "Gmsh.y"
    { List_Add(View->VP, &yyvsp[0].d) ; }
    break;

  case 106:
#line 511 "Gmsh.y"
    { 
      List_Add(View->VP, &yyvsp[-5].d); List_Add(View->VP, &yyvsp[-3].d);
      List_Add(View->VP, &yyvsp[-1].d); 
    }
    break;

  case 107:
#line 516 "Gmsh.y"
    {
      View->NbVP++ ;
    }
    break;

  case 108:
#line 523 "Gmsh.y"
    { List_Add(View->TP, &yyvsp[0].d) ; }
    break;

  case 109:
#line 525 "Gmsh.y"
    { List_Add(View->TP, &yyvsp[0].d) ; }
    break;

  case 110:
#line 530 "Gmsh.y"
    { 
      List_Add(View->TP, &yyvsp[-5].d); List_Add(View->TP, &yyvsp[-3].d);
      List_Add(View->TP, &yyvsp[-1].d);
    }
    break;

  case 111:
#line 535 "Gmsh.y"
    {
      View->NbTP++ ;
    }
    break;

  case 112:
#line 542 "Gmsh.y"
    { List_Add(View->SL, &yyvsp[0].d) ; }
    break;

  case 113:
#line 544 "Gmsh.y"
    { List_Add(View->SL, &yyvsp[0].d) ; }
    break;

  case 114:
#line 550 "Gmsh.y"
    { 
      List_Add(View->SL, &yyvsp[-11].d); List_Add(View->SL, &yyvsp[-5].d);
      List_Add(View->SL, &yyvsp[-9].d); List_Add(View->SL, &yyvsp[-3].d);
      List_Add(View->SL, &yyvsp[-7].d); List_Add(View->SL, &yyvsp[-1].d);
    }
    break;

  case 115:
#line 556 "Gmsh.y"
    {
      View->NbSL++ ;
    }
    break;

  case 116:
#line 563 "Gmsh.y"
    { List_Add(View->VL, &yyvsp[0].d) ; }
    break;

  case 117:
#line 565 "Gmsh.y"
    { List_Add(View->VL, &yyvsp[0].d) ; }
    break;

  case 118:
#line 571 "Gmsh.y"
    { 
      List_Add(View->VL, &yyvsp[-11].d); List_Add(View->VL, &yyvsp[-5].d);
      List_Add(View->VL, &yyvsp[-9].d); List_Add(View->VL, &yyvsp[-3].d);
      List_Add(View->VL, &yyvsp[-7].d); List_Add(View->VL, &yyvsp[-1].d);
    }
    break;

  case 119:
#line 577 "Gmsh.y"
    {
      View->NbVL++ ;
    }
    break;

  case 120:
#line 584 "Gmsh.y"
    { List_Add(View->TL, &yyvsp[0].d) ; }
    break;

  case 121:
#line 586 "Gmsh.y"
    { List_Add(View->TL, &yyvsp[0].d) ; }
    break;

  case 122:
#line 592 "Gmsh.y"
    { 
      List_Add(View->TL, &yyvsp[-11].d); List_Add(View->TL, &yyvsp[-5].d);
      List_Add(View->TL, &yyvsp[-9].d); List_Add(View->TL, &yyvsp[-3].d);
      List_Add(View->TL, &yyvsp[-7].d); List_Add(View->TL, &yyvsp[-1].d);
    }
    break;

  case 123:
#line 598 "Gmsh.y"
    {
      View->NbTL++ ;
    }
    break;

  case 124:
#line 605 "Gmsh.y"
    { List_Add(View->ST, &yyvsp[0].d) ; }
    break;

  case 125:
#line 607 "Gmsh.y"
    { List_Add(View->ST, &yyvsp[0].d) ; }
    break;

  case 126:
#line 614 "Gmsh.y"
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
#line 623 "Gmsh.y"
    {
      View->NbST++ ;
    }
    break;

  case 128:
#line 630 "Gmsh.y"
    { List_Add(View->VT, &yyvsp[0].d) ; }
    break;

  case 129:
#line 632 "Gmsh.y"
    { List_Add(View->VT, &yyvsp[0].d) ; }
    break;

  case 130:
#line 639 "Gmsh.y"
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
#line 648 "Gmsh.y"
    {
      View->NbVT++ ;
    }
    break;

  case 132:
#line 655 "Gmsh.y"
    { List_Add(View->TT, &yyvsp[0].d) ; }
    break;

  case 133:
#line 657 "Gmsh.y"
    { List_Add(View->TT, &yyvsp[0].d) ; }
    break;

  case 134:
#line 664 "Gmsh.y"
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
#line 673 "Gmsh.y"
    {
      View->NbTT++ ;
    }
    break;

  case 136:
#line 680 "Gmsh.y"
    { List_Add(View->SQ, &yyvsp[0].d) ; }
    break;

  case 137:
#line 682 "Gmsh.y"
    { List_Add(View->SQ, &yyvsp[0].d) ; }
    break;

  case 138:
#line 690 "Gmsh.y"
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
#line 699 "Gmsh.y"
    {
      View->NbSQ++ ;
    }
    break;

  case 140:
#line 706 "Gmsh.y"
    { List_Add(View->VQ, &yyvsp[0].d) ; }
    break;

  case 141:
#line 708 "Gmsh.y"
    { List_Add(View->VQ, &yyvsp[0].d) ; }
    break;

  case 142:
#line 716 "Gmsh.y"
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
#line 725 "Gmsh.y"
    {
      View->NbVQ++ ;
    }
    break;

  case 144:
#line 732 "Gmsh.y"
    { List_Add(View->TQ, &yyvsp[0].d) ; }
    break;

  case 145:
#line 734 "Gmsh.y"
    { List_Add(View->TQ, &yyvsp[0].d) ; }
    break;

  case 146:
#line 742 "Gmsh.y"
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
#line 751 "Gmsh.y"
    {
      View->NbTQ++ ;
    }
    break;

  case 148:
#line 758 "Gmsh.y"
    { List_Add(View->SS, &yyvsp[0].d) ; }
    break;

  case 149:
#line 760 "Gmsh.y"
    { List_Add(View->SS, &yyvsp[0].d) ; }
    break;

  case 150:
#line 768 "Gmsh.y"
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
#line 777 "Gmsh.y"
    {
      View->NbSS++ ;
    }
    break;

  case 152:
#line 784 "Gmsh.y"
    { List_Add(View->VS, &yyvsp[0].d) ; }
    break;

  case 153:
#line 786 "Gmsh.y"
    { List_Add(View->VS, &yyvsp[0].d) ; }
    break;

  case 154:
#line 794 "Gmsh.y"
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
#line 803 "Gmsh.y"
    {
      View->NbVS++ ;
    }
    break;

  case 156:
#line 810 "Gmsh.y"
    { List_Add(View->TS, &yyvsp[0].d) ; }
    break;

  case 157:
#line 812 "Gmsh.y"
    { List_Add(View->TS, &yyvsp[0].d) ; }
    break;

  case 158:
#line 820 "Gmsh.y"
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
#line 829 "Gmsh.y"
    {
      View->NbTS++ ;
    }
    break;

  case 160:
#line 836 "Gmsh.y"
    { List_Add(View->SH, &yyvsp[0].d) ; }
    break;

  case 161:
#line 838 "Gmsh.y"
    { List_Add(View->SH, &yyvsp[0].d) ; }
    break;

  case 162:
#line 850 "Gmsh.y"
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
#line 865 "Gmsh.y"
    {
      View->NbSH++ ;
    }
    break;

  case 164:
#line 872 "Gmsh.y"
    { List_Add(View->VH, &yyvsp[0].d) ; }
    break;

  case 165:
#line 874 "Gmsh.y"
    { List_Add(View->VH, &yyvsp[0].d) ; }
    break;

  case 166:
#line 886 "Gmsh.y"
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
#line 901 "Gmsh.y"
    {
      View->NbVH++ ;
    }
    break;

  case 168:
#line 908 "Gmsh.y"
    { List_Add(View->TH, &yyvsp[0].d) ; }
    break;

  case 169:
#line 910 "Gmsh.y"
    { List_Add(View->TH, &yyvsp[0].d) ; }
    break;

  case 170:
#line 922 "Gmsh.y"
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
#line 937 "Gmsh.y"
    {
      View->NbTH++ ;
    }
    break;

  case 172:
#line 944 "Gmsh.y"
    { List_Add(View->SI, &yyvsp[0].d) ; }
    break;

  case 173:
#line 946 "Gmsh.y"
    { List_Add(View->SI, &yyvsp[0].d) ; }
    break;

  case 174:
#line 956 "Gmsh.y"
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
#line 968 "Gmsh.y"
    {
      View->NbSI++ ;
    }
    break;

  case 176:
#line 975 "Gmsh.y"
    { List_Add(View->VI, &yyvsp[0].d) ; }
    break;

  case 177:
#line 977 "Gmsh.y"
    { List_Add(View->VI, &yyvsp[0].d) ; }
    break;

  case 178:
#line 987 "Gmsh.y"
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
#line 999 "Gmsh.y"
    {
      View->NbVI++ ;
    }
    break;

  case 180:
#line 1006 "Gmsh.y"
    { List_Add(View->TI, &yyvsp[0].d) ; }
    break;

  case 181:
#line 1008 "Gmsh.y"
    { List_Add(View->TI, &yyvsp[0].d) ; }
    break;

  case 182:
#line 1018 "Gmsh.y"
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
#line 1030 "Gmsh.y"
    {
      View->NbTI++ ;
    }
    break;

  case 184:
#line 1037 "Gmsh.y"
    { List_Add(View->SY, &yyvsp[0].d) ; }
    break;

  case 185:
#line 1039 "Gmsh.y"
    { List_Add(View->SY, &yyvsp[0].d) ; }
    break;

  case 186:
#line 1048 "Gmsh.y"
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
#line 1060 "Gmsh.y"
    {
      View->NbSY++ ;
    }
    break;

  case 188:
#line 1067 "Gmsh.y"
    { List_Add(View->VY, &yyvsp[0].d) ; }
    break;

  case 189:
#line 1069 "Gmsh.y"
    { List_Add(View->VY, &yyvsp[0].d) ; }
    break;

  case 190:
#line 1078 "Gmsh.y"
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
#line 1090 "Gmsh.y"
    {
      View->NbVY++ ;
    }
    break;

  case 192:
#line 1097 "Gmsh.y"
    { List_Add(View->TY, &yyvsp[0].d) ; }
    break;

  case 193:
#line 1099 "Gmsh.y"
    { List_Add(View->TY, &yyvsp[0].d) ; }
    break;

  case 194:
#line 1108 "Gmsh.y"
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
#line 1120 "Gmsh.y"
    {
      View->NbTY++ ;
    }
    break;

  case 196:
#line 1127 "Gmsh.y"
    { 
      for(i=0; i<(int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]) ; 
      Free(yyvsp[0].c);
    }
    break;

  case 197:
#line 1132 "Gmsh.y"
    { 
      for(i=0; i<(int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T2C, &yyvsp[0].c[i]) ; 
      Free(yyvsp[0].c);
    }
    break;

  case 198:
#line 1140 "Gmsh.y"
    { 
      List_Add(View->T2D, &yyvsp[-5].d); List_Add(View->T2D, &yyvsp[-3].d);
      List_Add(View->T2D, &yyvsp[-1].d); 
      d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    }
    break;

  case 199:
#line 1147 "Gmsh.y"
    {
      View->NbT2++ ;
    }
    break;

  case 200:
#line 1154 "Gmsh.y"
    { 
      for(i=0; i<(int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]) ; 
      Free(yyvsp[0].c);
    }
    break;

  case 201:
#line 1159 "Gmsh.y"
    { 
      for(i=0; i<(int)strlen(yyvsp[0].c)+1; i++) List_Add(View->T3C, &yyvsp[0].c[i]) ; 
      Free(yyvsp[0].c);
    }
    break;

  case 202:
#line 1167 "Gmsh.y"
    { 
      List_Add(View->T3D, &yyvsp[-7].d); List_Add(View->T3D, &yyvsp[-5].d);
      List_Add(View->T3D, &yyvsp[-3].d); List_Add(View->T3D, &yyvsp[-1].d); 
      d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    }
    break;

  case 203:
#line 1174 "Gmsh.y"
    {
      View->NbT3++ ;
    }
    break;

  case 204:
#line 1183 "Gmsh.y"
    { yyval.i = 0 ; }
    break;

  case 205:
#line 1184 "Gmsh.y"
    { yyval.i = 1 ; }
    break;

  case 206:
#line 1185 "Gmsh.y"
    { yyval.i = 2 ; }
    break;

  case 207:
#line 1186 "Gmsh.y"
    { yyval.i = 3 ; }
    break;

  case 208:
#line 1187 "Gmsh.y"
    { yyval.i = 4 ; }
    break;

  case 209:
#line 1191 "Gmsh.y"
    { yyval.i = 1 ; }
    break;

  case 210:
#line 1192 "Gmsh.y"
    { yyval.i = -1 ; }
    break;

  case 211:
#line 1200 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-3].c;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	if(!yyvsp[-2].i){
	  List_Put(TheSymbol.val, 0, &yyvsp[-1].d);
	  List_Add(Symbol_L, &TheSymbol);
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
#line 1227 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-6].c;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(5,5,sizeof(double));
	if(!yyvsp[-2].i){
	  List_Put(TheSymbol.val, (int)yyvsp[-4].d, &yyvsp[-1].d);
	  List_Add(Symbol_L, &TheSymbol);
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
#line 1261 "Gmsh.y"
    {
      if(List_Nbr(yyvsp[-5].l) != List_Nbr(yyvsp[-1].l))
	yymsg(GERROR, "Incompatible array dimensions in affectation");
      else{
	TheSymbol.Name = yyvsp[-8].c;
	if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	  TheSymbol.val = List_Create(5,5,sizeof(double));
	  if(!yyvsp[-2].i){
	    for(i=0 ; i<List_Nbr(yyvsp[-5].l) ; i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer(yyvsp[-5].l,i)),
		       (double*)List_Pointer(yyvsp[-1].l,i));
	    }
	    List_Add(Symbol_L, &TheSymbol);
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
#line 1308 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-5].c;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(5,5,sizeof(double));
	List_Copy(yyvsp[-1].l,TheSymbol.val);
	List_Add(Symbol_L, &TheSymbol);
      }
      else{
	List_Reset(pSymbol->val);
	List_Copy(yyvsp[-1].l, pSymbol->val);
      }
      List_Delete(yyvsp[-1].l);
    }
    break;

  case 215:
#line 1323 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-2].c;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-2].c) ; 
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += yyvsp[-1].i; 
    }
    break;

  case 216:
#line 1332 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-5].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
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
#line 1347 "Gmsh.y"
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
#line 1359 "Gmsh.y"
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
#line 1373 "Gmsh.y"
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
#line 1396 "Gmsh.y"
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
#line 1420 "Gmsh.y"
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
#line 1432 "Gmsh.y"
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
#line 1446 "Gmsh.y"
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
#line 1458 "Gmsh.y"
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
#line 1472 "Gmsh.y"
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
#line 1492 "Gmsh.y"
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
#line 1514 "Gmsh.y"
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
#line 1526 "Gmsh.y"
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
#line 1546 "Gmsh.y"
    {
      Cdbpts101((int)yyvsp[-4].d,yyvsp[-1].v[0],yyvsp[-1].v[1],yyvsp[-1].v[2],yyvsp[-1].v[3],yyvsp[-1].v[4]);
      yyval.s.Type = MSH_POINT;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 230:
#line 1553 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_PHYSICAL_POINT,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_PHYSICAL_POINT;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 231:
#line 1559 "Gmsh.y"
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
#line 1578 "Gmsh.y"
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
#line 1592 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_LINE,1,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      yyval.s.Type = MSH_SEGM_LINE;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 234:
#line 1598 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_SPLN,3,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      yyval.s.Type = MSH_SEGM_SPLN;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 235:
#line 1604 "Gmsh.y"
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
#line 1623 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_CIRC,2,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      yyval.s.Type = MSH_SEGM_CIRC ;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 237:
#line 1629 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-4].d,MSH_SEGM_ELLI,2,yyvsp[-1].l,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      yyval.s.Type = MSH_SEGM_ELLI ;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 238:
#line 1635 "Gmsh.y"
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
#line 1652 "Gmsh.y"
    {
      Cdbseg101((int)yyvsp[-14].d,MSH_SEGM_PARAMETRIC,2,NULL,NULL,-1,-1,yyvsp[-10].d,yyvsp[-8].d,yyvsp[-6].c,yyvsp[-4].c,yyvsp[-2].c);
      yyval.s.Type = MSH_SEGM_PARAMETRIC ;
      yyval.s.Num  = (int)yyvsp[-14].d;
    }
    break;

  case 240:
#line 1658 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_PHYSICAL_LINE,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_PHYSICAL_LINE;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 241:
#line 1664 "Gmsh.y"
    {
      yyval.s.Type = MSH_SEGM_LOOP;
      Cdbz101((int)yyvsp[-4].d,yyval.s.Type,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Num = (int)yyvsp[-4].d;
    }
    break;

  case 242:
#line 1670 "Gmsh.y"
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
#line 1681 "Gmsh.y"
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
#line 1692 "Gmsh.y"
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
#line 1717 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_SURF_PLAN,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_SURF_PLAN;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 246:
#line 1723 "Gmsh.y"
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
#line 1742 "Gmsh.y"
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
#line 1765 "Gmsh.y"
    {
      CreateNurbsSurface ( (int) yyvsp[-16].d , (int)yyvsp[-4].d , (int)yyvsp[-2].d  , yyvsp[-13].l, yyvsp[-10].l, yyvsp[-8].l);
      yyval.s.Type  = MSH_SURF_NURBS;
      yyval.s.Num = (int)yyvsp[-16].d;
    }
    break;

  case 249:
#line 1773 "Gmsh.y"
    {
      CreateNurbsSurfaceSupport ((int)yyvsp[-16].d, (int) yyvsp[-4].d , (int) yyvsp[-2].d , yyvsp[-13].l, yyvsp[-10].l, yyvsp[-8].l);
    }
    break;

  case 250:
#line 1777 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_PHYSICAL_SURFACE,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_PHYSICAL_SURFACE;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 251:
#line 1783 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_SURF_LOOP,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_SURF_LOOP;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 252:
#line 1792 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_VOLUME,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_VOLUME;
      yyval.s.Num  = (int)yyvsp[-4].d;      
    }
    break;

  case 253:
#line 1798 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_VOLUME,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_VOLUME;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 254:
#line 1804 "Gmsh.y"
    {
      Cdbz101((int)yyvsp[-4].d,MSH_PHYSICAL_VOLUME,0,0,0,0,0,NULL,yyvsp[-1].l,NULL);
      yyval.s.Type = MSH_PHYSICAL_VOLUME;
      yyval.s.Num  = (int)yyvsp[-4].d;
    }
    break;

  case 255:
#line 1815 "Gmsh.y"
    {
      TranslateShapes (yyvsp[-3].v[0],yyvsp[-3].v[1],yyvsp[-3].v[2],yyvsp[-1].l,1);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 256:
#line 1820 "Gmsh.y"
    {
      RotateShapes(yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].d,yyvsp[-1].l);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 257:
#line 1825 "Gmsh.y"
    {
      SymmetryShapes(yyvsp[-3].v[0],yyvsp[-3].v[1],yyvsp[-3].v[2],yyvsp[-3].v[3],yyvsp[-1].l,1);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 258:
#line 1830 "Gmsh.y"
    {
      DilatShapes(yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].d,yyvsp[-1].l,1);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 259:
#line 1837 "Gmsh.y"
    { yyval.l = yyvsp[0].l; }
    break;

  case 260:
#line 1838 "Gmsh.y"
    { yyval.l = yyvsp[0].l; }
    break;

  case 261:
#line 1839 "Gmsh.y"
    { yyval.l = yyvsp[0].l; }
    break;

  case 262:
#line 1844 "Gmsh.y"
    {
      yyval.l = List_Create(3,3,sizeof(Shape));
    }
    break;

  case 263:
#line 1848 "Gmsh.y"
    {
      List_Add(yyval.l,&yyvsp[0].s);
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 264:
#line 1853 "Gmsh.y"
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

  case 265:
#line 1868 "Gmsh.y"
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

  case 266:
#line 1883 "Gmsh.y"
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

  case 267:
#line 1903 "Gmsh.y"
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

  case 268:
#line 1913 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) DuplicateView((int)yyvsp[-2].d,0);
    }
    break;

  case 269:
#line 1923 "Gmsh.y"
    {
      for(i=0;i<List_Nbr(yyvsp[-1].l);i++){
	List_Read (yyvsp[-1].l,i,&TheShape);
	DeleteShape(TheShape.Type,TheShape.Num);
      }
    }
    break;

  case 270:
#line 1930 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-4].c, "View")) FreeView((int)yyvsp[-2].d);
    }
    break;

  case 271:
#line 1934 "Gmsh.y"
    {
      Init_Mesh(THEM, 1);
    }
    break;

  case 272:
#line 1943 "Gmsh.y"
    {
      for(i=0;i<List_Nbr(yyvsp[-1].l);i++){
	List_Read (yyvsp[-1].l,i,&TheShape);
	ColorShape(TheShape.Type,TheShape.Num,yyvsp[-3].u);
      }
    }
    break;

  case 273:
#line 1955 "Gmsh.y"
    {
      if(!strcmp(yyvsp[-2].c, "Include")){

	yyinTab[RecursionLevel++] = yyin;

	strcpy(tmpstring, yyname);
	i = strlen(yyname)-1 ;
	while(i >= 0 && yyname[i] != '/' && yyname[i] != '\\') i-- ;
	tmpstring[i+1] = '\0';
	strcat(tmpstring,yyvsp[-1].c);

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
#ifndef _BLACKBOX
	if(!CTX.batch) CreateOutputFile(yyvsp[-1].c, CTX.print.format);
#endif
      }
      else if(!strcmp(yyvsp[-2].c, "Save")){
#ifndef _BLACKBOX
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
	
	Msg(INFO, "Executing system call \"%s\"", yyvsp[-1].c);
	SystemCall(yyvsp[-1].c);

      }
      else
	yymsg(GERROR, "Unknown command '%s'", yyvsp[-2].c);
    }
    break;

  case 274:
#line 2030 "Gmsh.y"
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

  case 275:
#line 2050 "Gmsh.y"
    {
#ifndef _NOPLUGIN
    if(CTX.default_plugins)
      GMSH_PluginManager::Instance()->Action(yyvsp[-4].c,yyvsp[-1].c,0); 
#endif
   }
    break;

  case 276:
#line 2057 "Gmsh.y"
    {
      exit(0);
    }
    break;

  case 277:
#line 2061 "Gmsh.y"
    {
#ifndef _BLACKBOX
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

  case 278:
#line 2083 "Gmsh.y"
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

  case 279:
#line 2093 "Gmsh.y"
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

  case 280:
#line 2103 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-3].d ;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-1].d ;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = yyvsp[-6].c ;
      
      TheSymbol.Name = yyvsp[-6].c;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	List_Put(TheSymbol.val, 0, &yyvsp[-3].d);
	List_Add(Symbol_L, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &yyvsp[-3].d);
      }
      
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
    break;

  case 281:
#line 2124 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = yyvsp[-5].d ;
      LoopControlVariablesTab[ImbricatedLoop][1] = yyvsp[-3].d ;
      LoopControlVariablesTab[ImbricatedLoop][2] = yyvsp[-1].d ;
      LoopControlVariablesNameTab[ImbricatedLoop] = yyvsp[-8].c ;

      TheSymbol.Name = yyvsp[-8].c;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	List_Put(TheSymbol.val, 0, &yyvsp[-5].d);
	List_Add(Symbol_L, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &yyvsp[-5].d);
      }
      
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
    break;

  case 282:
#line 2145 "Gmsh.y"
    {
      if(LoopControlVariablesTab[ImbricatedLoop-1][1] >  
	 LoopControlVariablesTab[ImbricatedLoop-1][0]){
	LoopControlVariablesTab[ImbricatedLoop-1][0] +=
	  LoopControlVariablesTab[ImbricatedLoop-1][2];
	
	if(strlen(LoopControlVariablesNameTab[ImbricatedLoop-1])){
	  TheSymbol.Name = LoopControlVariablesNameTab[ImbricatedLoop-1];
	  pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols);
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

  case 283:
#line 2166 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction(yyvsp[0].c,yyin,yyname,yylineno))
	yymsg(GERROR, "Redefinition of function %s",yyvsp[0].c);
      skip_until(NULL, "Return");
    }
    break;

  case 284:
#line 2172 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin,yyname,yylineno))
	yymsg(GERROR, "Error while exiting function");
    }
    break;

  case 285:
#line 2177 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction(yyvsp[-1].c,&yyin,yyname,yylineno))
	yymsg(GERROR, "Unknown function %s",yyvsp[-1].c);
    }
    break;

  case 286:
#line 2182 "Gmsh.y"
    {
      if(!yyvsp[-1].d) skip_until("If", "EndIf");
    }
    break;

  case 287:
#line 2186 "Gmsh.y"
    {
    }
    break;

  case 288:
#line 2198 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(TRANSLATE,(int)yyvsp[-4].d,yyvsp[-2].v[0],yyvsp[-2].v[1],yyvsp[-2].v[2],
			   0.,0.,0.,0.,0.,0.,0.,
			   &pc,&prc,NULL);
    }
    break;

  case 289:
#line 2205 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(ROTATE,(int)yyvsp[-8].d,0.,0.,0.,
			   yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,
			   &pc,&prc,NULL);
    }
    break;

  case 290:
#line 2212 "Gmsh.y"
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(TRANSLATE_ROTATE,(int)yyvsp[-10].d,yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],
			   yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,
			   &pc,&prc,NULL);
    }
    break;

  case 291:
#line 2222 "Gmsh.y"
    {
      Extrude_ProtudeCurve(TRANSLATE,(int)yyvsp[-4].d,yyvsp[-2].v[0],yyvsp[-2].v[1],yyvsp[-2].v[2],
			   0.,0.,0.,0.,0.,0.,0.,1,NULL);
    }
    break;

  case 292:
#line 2227 "Gmsh.y"
    {
      Extrude_ProtudeCurve(ROTATE,(int)yyvsp[-8].d,0.,0.,0.,
			   yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,1,NULL);
    }
    break;

  case 293:
#line 2232 "Gmsh.y"
    {
      Extrude_ProtudeCurve(TRANSLATE_ROTATE,(int)yyvsp[-10].d,yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],
			   yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,1,NULL);
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
      Extrude_ProtudeCurve(TRANSLATE,(int)yyvsp[-8].d,yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],
			   0.,0.,0.,0.,0.,0.,0.,1,&extr);
    }
    break;

  case 296:
#line 2247 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 297:
#line 2252 "Gmsh.y"
    {
      Extrude_ProtudeCurve(ROTATE,(int)yyvsp[-12].d,0.,0.,0.,
			   yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,1,&extr);
    }
    break;

  case 298:
#line 2257 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 299:
#line 2262 "Gmsh.y"
    {
      Extrude_ProtudeCurve(TRANSLATE_ROTATE,(int)yyvsp[-14].d,yyvsp[-12].v[0],yyvsp[-12].v[1],yyvsp[-12].v[2],
			   yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,1,&extr);
    }
    break;

  case 300:
#line 2270 "Gmsh.y"
    {
      Extrude_ProtudeSurface(TRANSLATE,(int)yyvsp[-4].d,yyvsp[-2].v[0],yyvsp[-2].v[1],yyvsp[-2].v[2],
			     0.,0.,0.,0.,0.,0.,0.,0,NULL);
    }
    break;

  case 301:
#line 2275 "Gmsh.y"
    {
      Extrude_ProtudeSurface(ROTATE,(int)yyvsp[-8].d,0.,0.,0.,
			     yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,0,NULL);
    }
    break;

  case 302:
#line 2280 "Gmsh.y"
    {
      Extrude_ProtudeSurface(TRANSLATE_ROTATE,(int)yyvsp[-10].d,yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],
			     yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],yyvsp[-4].v[0],yyvsp[-4].v[1],yyvsp[-4].v[2],yyvsp[-2].d,0,NULL);
    }
    break;

  case 303:
#line 2285 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 304:
#line 2290 "Gmsh.y"
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(TRANSLATE,(int)yyvsp[-8].d,yyvsp[-6].v[0],yyvsp[-6].v[1],yyvsp[-6].v[2],
			     0.,0.,0.,0.,0.,0.,0.,vol,&extr);
    }
    break;

  case 305:
#line 2296 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 306:
#line 2302 "Gmsh.y"
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(ROTATE,(int)yyvsp[-12].d,0.,0.,0.,
			     yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,vol,&extr);
    }
    break;

  case 307:
#line 2308 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
    break;

  case 308:
#line 2314 "Gmsh.y"
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(TRANSLATE_ROTATE,(int)yyvsp[-14].d,yyvsp[-12].v[0],yyvsp[-12].v[1],yyvsp[-12].v[2],
			     yyvsp[-10].v[0],yyvsp[-10].v[1],yyvsp[-10].v[2],yyvsp[-8].v[0],yyvsp[-8].v[1],yyvsp[-8].v[2],yyvsp[-6].d,vol,&extr);
    }
    break;

  case 309:
#line 2323 "Gmsh.y"
    {
    }
    break;

  case 310:
#line 2326 "Gmsh.y"
    {
    }
    break;

  case 311:
#line 2332 "Gmsh.y"
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

  case 312:
#line 2358 "Gmsh.y"
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

  case 313:
#line 2382 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 314:
#line 2391 "Gmsh.y"
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

  case 315:
#line 2409 "Gmsh.y"
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

  case 316:
#line 2427 "Gmsh.y"
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

  case 317:
#line 2445 "Gmsh.y"
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

  case 318:
#line 2467 "Gmsh.y"
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

  case 319:
#line 2488 "Gmsh.y"
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

  case 320:
#line 2509 "Gmsh.y"
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

  case 321:
#line 2523 "Gmsh.y"
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

  case 322:
#line 2543 "Gmsh.y"
    { 
      ReplaceAllDuplicates(THEM);
    }
    break;

  case 323:
#line 2547 "Gmsh.y"
    { 
      IntersectAllSegmentsTogether();
    }
    break;

  case 324:
#line 2556 "Gmsh.y"
    {yyval.i = 1;}
    break;

  case 325:
#line 2557 "Gmsh.y"
    {yyval.i = 0;}
    break;

  case 326:
#line 2558 "Gmsh.y"
    {yyval.i = -1;}
    break;

  case 327:
#line 2559 "Gmsh.y"
    {yyval.i = -1;}
    break;

  case 328:
#line 2560 "Gmsh.y"
    {yyval.i = -1;}
    break;

  case 329:
#line 2564 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           }
    break;

  case 330:
#line 2565 "Gmsh.y"
    { yyval.d = yyvsp[-1].d ;          }
    break;

  case 331:
#line 2566 "Gmsh.y"
    { yyval.d = -yyvsp[0].d ;         }
    break;

  case 332:
#line 2567 "Gmsh.y"
    { yyval.d = yyvsp[0].d;           }
    break;

  case 333:
#line 2568 "Gmsh.y"
    { yyval.d = !yyvsp[0].d ;         }
    break;

  case 334:
#line 2569 "Gmsh.y"
    { yyval.d = yyvsp[-2].d - yyvsp[0].d ;     }
    break;

  case 335:
#line 2570 "Gmsh.y"
    { yyval.d = yyvsp[-2].d + yyvsp[0].d ;     }
    break;

  case 336:
#line 2571 "Gmsh.y"
    { yyval.d = yyvsp[-2].d * yyvsp[0].d ;     }
    break;

  case 337:
#line 2573 "Gmsh.y"
    { 
      if(!yyvsp[0].d)
	yymsg(GERROR, "Division by zero in '%g / %g'", yyvsp[-2].d, yyvsp[0].d);
      else
	yyval.d = yyvsp[-2].d / yyvsp[0].d ;     
    }
    break;

  case 338:
#line 2579 "Gmsh.y"
    { yyval.d = (int)yyvsp[-2].d % (int)yyvsp[0].d ;  }
    break;

  case 339:
#line 2580 "Gmsh.y"
    { yyval.d = pow(yyvsp[-2].d,yyvsp[0].d) ;  }
    break;

  case 340:
#line 2581 "Gmsh.y"
    { yyval.d = yyvsp[-2].d < yyvsp[0].d ;     }
    break;

  case 341:
#line 2582 "Gmsh.y"
    { yyval.d = yyvsp[-2].d > yyvsp[0].d ;     }
    break;

  case 342:
#line 2583 "Gmsh.y"
    { yyval.d = yyvsp[-2].d <= yyvsp[0].d ;    }
    break;

  case 343:
#line 2584 "Gmsh.y"
    { yyval.d = yyvsp[-2].d >= yyvsp[0].d ;    }
    break;

  case 344:
#line 2585 "Gmsh.y"
    { yyval.d = yyvsp[-2].d == yyvsp[0].d ;    }
    break;

  case 345:
#line 2586 "Gmsh.y"
    { yyval.d = yyvsp[-2].d != yyvsp[0].d ;    }
    break;

  case 346:
#line 2587 "Gmsh.y"
    { yyval.d = yyvsp[-2].d && yyvsp[0].d ;    }
    break;

  case 347:
#line 2588 "Gmsh.y"
    { yyval.d = yyvsp[-2].d || yyvsp[0].d ;    }
    break;

  case 348:
#line 2589 "Gmsh.y"
    { yyval.d = yyvsp[-4].d? yyvsp[-2].d : yyvsp[0].d ; }
    break;

  case 349:
#line 2590 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      }
    break;

  case 350:
#line 2591 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      }
    break;

  case 351:
#line 2592 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    }
    break;

  case 352:
#line 2593 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     }
    break;

  case 353:
#line 2594 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      }
    break;

  case 354:
#line 2595 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     }
    break;

  case 355:
#line 2596 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      }
    break;

  case 356:
#line 2597 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     }
    break;

  case 357:
#line 2598 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      }
    break;

  case 358:
#line 2599 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     }
    break;

  case 359:
#line 2600 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d,yyvsp[-1].d); }
    break;

  case 360:
#line 2601 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     }
    break;

  case 361:
#line 2602 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     }
    break;

  case 362:
#line 2603 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     }
    break;

  case 363:
#line 2604 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     }
    break;

  case 364:
#line 2605 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    }
    break;

  case 365:
#line 2606 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     }
    break;

  case 366:
#line 2607 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d,yyvsp[-1].d);  }
    break;

  case 367:
#line 2608 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d,yyvsp[-1].d);  }
    break;

  case 368:
#line 2609 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); }
    break;

  case 369:
#line 2610 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; }
    break;

  case 370:
#line 2612 "Gmsh.y"
    { yyval.d = exp(yyvsp[-1].d);      }
    break;

  case 371:
#line 2613 "Gmsh.y"
    { yyval.d = log(yyvsp[-1].d);      }
    break;

  case 372:
#line 2614 "Gmsh.y"
    { yyval.d = log10(yyvsp[-1].d);    }
    break;

  case 373:
#line 2615 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-1].d);     }
    break;

  case 374:
#line 2616 "Gmsh.y"
    { yyval.d = sin(yyvsp[-1].d);      }
    break;

  case 375:
#line 2617 "Gmsh.y"
    { yyval.d = asin(yyvsp[-1].d);     }
    break;

  case 376:
#line 2618 "Gmsh.y"
    { yyval.d = cos(yyvsp[-1].d);      }
    break;

  case 377:
#line 2619 "Gmsh.y"
    { yyval.d = acos(yyvsp[-1].d);     }
    break;

  case 378:
#line 2620 "Gmsh.y"
    { yyval.d = tan(yyvsp[-1].d);      }
    break;

  case 379:
#line 2621 "Gmsh.y"
    { yyval.d = atan(yyvsp[-1].d);     }
    break;

  case 380:
#line 2622 "Gmsh.y"
    { yyval.d = atan2(yyvsp[-3].d,yyvsp[-1].d); }
    break;

  case 381:
#line 2623 "Gmsh.y"
    { yyval.d = sinh(yyvsp[-1].d);     }
    break;

  case 382:
#line 2624 "Gmsh.y"
    { yyval.d = cosh(yyvsp[-1].d);     }
    break;

  case 383:
#line 2625 "Gmsh.y"
    { yyval.d = tanh(yyvsp[-1].d);     }
    break;

  case 384:
#line 2626 "Gmsh.y"
    { yyval.d = fabs(yyvsp[-1].d);     }
    break;

  case 385:
#line 2627 "Gmsh.y"
    { yyval.d = floor(yyvsp[-1].d);    }
    break;

  case 386:
#line 2628 "Gmsh.y"
    { yyval.d = ceil(yyvsp[-1].d);     }
    break;

  case 387:
#line 2629 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d,yyvsp[-1].d);  }
    break;

  case 388:
#line 2630 "Gmsh.y"
    { yyval.d = fmod(yyvsp[-3].d,yyvsp[-1].d);  }
    break;

  case 389:
#line 2631 "Gmsh.y"
    { yyval.d = sqrt(yyvsp[-3].d*yyvsp[-3].d+yyvsp[-1].d*yyvsp[-1].d); }
    break;

  case 390:
#line 2632 "Gmsh.y"
    { yyval.d = yyvsp[-1].d*(double)rand()/(double)RAND_MAX; }
    break;

  case 391:
#line 2641 "Gmsh.y"
    { yyval.d = yyvsp[0].d; }
    break;

  case 392:
#line 2642 "Gmsh.y"
    { yyval.d = 3.141592653589793; }
    break;

  case 393:
#line 2643 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->rank(); }
    break;

  case 394:
#line 2644 "Gmsh.y"
    { yyval.d = ParUtil::Instance()->size(); }
    break;

  case 395:
#line 2649 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[0].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[0].c) ;
	yyval.d = 0. ;
      }
      else
	yyval.d = *(double*)List_Pointer_Fast(pSymbol->val, 0) ;
    }
    break;

  case 396:
#line 2660 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-3].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
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

  case 397:
#line 2677 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-1].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	yymsg(GERROR, "Unknown variable '%s'", yyvsp[-1].c) ;
	yyval.d = 0. ;
      }
      else
	yyval.d = (*(double*)List_Pointer_Fast(pSymbol->val, 0) += yyvsp[0].i) ;
    }
    break;

  case 398:
#line 2688 "Gmsh.y"
    {
      TheSymbol.Name = yyvsp[-4].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
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

  case 399:
#line 2707 "Gmsh.y"
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

  case 400:
#line 2723 "Gmsh.y"
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

  case 401:
#line 2739 "Gmsh.y"
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

  case 402:
#line 2755 "Gmsh.y"
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

  case 403:
#line 2773 "Gmsh.y"
    {
      memcpy(yyval.v, yyvsp[0].v, 5*sizeof(double)) ;
    }
    break;

  case 404:
#line 2777 "Gmsh.y"
    {
      for(i=0 ; i<5 ; i++) yyval.v[i] = -yyvsp[0].v[i] ;
    }
    break;

  case 405:
#line 2781 "Gmsh.y"
    { 
      for(i=0 ; i<5 ; i++) yyval.v[i] = yyvsp[0].v[i];
    }
    break;

  case 406:
#line 2785 "Gmsh.y"
    { 
      for(i=0 ; i<5 ; i++) yyval.v[i] = yyvsp[-2].v[i] - yyvsp[0].v[i] ;
    }
    break;

  case 407:
#line 2789 "Gmsh.y"
    {
      for(i=0 ; i<5 ; i++) yyval.v[i] = yyvsp[-2].v[i] + yyvsp[0].v[i] ;
    }
    break;

  case 408:
#line 2796 "Gmsh.y"
    { 
      yyval.v[0]=yyvsp[-9].d;  yyval.v[1]=yyvsp[-7].d;  yyval.v[2]=yyvsp[-5].d;  yyval.v[3]=yyvsp[-3].d; yyval.v[4]=yyvsp[-1].d;
    }
    break;

  case 409:
#line 2800 "Gmsh.y"
    { 
      yyval.v[0]=yyvsp[-7].d;  yyval.v[1]=yyvsp[-5].d;  yyval.v[2]=yyvsp[-3].d;  yyval.v[3]=yyvsp[-1].d; yyval.v[4]=1.0;
    }
    break;

  case 410:
#line 2804 "Gmsh.y"
    {
      yyval.v[0]=yyvsp[-5].d;  yyval.v[1]=yyvsp[-3].d;  yyval.v[2]=yyvsp[-1].d;  yyval.v[3]=0.0; yyval.v[4]=1.0;
    }
    break;

  case 411:
#line 2808 "Gmsh.y"
    {
      yyval.v[0]=yyvsp[-5].d;  yyval.v[1]=yyvsp[-3].d;  yyval.v[2]=yyvsp[-1].d;  yyval.v[3]=0.0; yyval.v[4]=1.0;
    }
    break;

  case 412:
#line 2815 "Gmsh.y"
    {
    }
    break;

  case 413:
#line 2818 "Gmsh.y"
    {
    }
    break;

  case 414:
#line 2824 "Gmsh.y"
    {
    }
    break;

  case 415:
#line 2827 "Gmsh.y"
    {
    }
    break;

  case 416:
#line 2833 "Gmsh.y"
    {
    }
    break;

  case 417:
#line 2836 "Gmsh.y"
    {
       yyval.l=yyvsp[-1].l;
    }
    break;

  case 418:
#line 2840 "Gmsh.y"
    {
       yyval.l=yyvsp[-1].l;
    }
    break;

  case 419:
#line 2847 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(List_T*)) ;
      List_Add(yyval.l, &(yyvsp[0].l)) ;
    }
    break;

  case 420:
#line 2852 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].l)) ;
    }
    break;

  case 421:
#line 2860 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      List_Add(yyval.l, &(yyvsp[0].d)) ;
    }
    break;

  case 422:
#line 2865 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l ;
    }
    break;

  case 423:
#line 2869 "Gmsh.y"
    {
      yyval.l=yyvsp[-1].l;
    }
    break;

  case 424:
#line 2873 "Gmsh.y"
    {
      yyval.l=yyvsp[-1].l;
      for(i=0 ; i<List_Nbr(yyval.l) ; i++){
	pd = (double*)List_Pointer(yyval.l, i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 425:
#line 2884 "Gmsh.y"
    { 
      yyval.l = List_Create(2,1,sizeof(double)) ; 
      for(d=yyvsp[-2].d ; (yyvsp[-2].d<yyvsp[0].d)?(d<=yyvsp[0].d):(d>=yyvsp[0].d) ; (yyvsp[-2].d<yyvsp[0].d)?(d+=1.):(d-=1.)) 
	List_Add(yyval.l, &d) ;
    }
    break;

  case 426:
#line 2890 "Gmsh.y"
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

  case 427:
#line 2901 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = yyvsp[-2].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
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

  case 428:
#line 2915 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = yyvsp[-2].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
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

  case 429:
#line 2931 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = yyvsp[-5].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
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

  case 430:
#line 2951 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = yyvsp[-5].c ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
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

  case 431:
#line 2976 "Gmsh.y"
    {
      yyval.l = List_Create(2,1,sizeof(double)) ;
      List_Add(yyval.l, &(yyvsp[0].d)) ;
    }
    break;

  case 432:
#line 2981 "Gmsh.y"
    {
      yyval.l = yyvsp[0].l ;
    }
    break;

  case 433:
#line 2985 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].d)) ;
    }
    break;

  case 434:
#line 2989 "Gmsh.y"
    {
      for(i=0 ; i<List_Nbr(yyvsp[0].l) ; i++){
	List_Read(yyvsp[0].l, i, &d) ;
	List_Add(yyval.l, &d) ;
      }
      List_Delete(yyvsp[0].l);
    }
    break;

  case 435:
#line 3001 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-7].d, (int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d);
    }
    break;

  case 436:
#line 3005 "Gmsh.y"
    {
      yyval.u = PACK_COLOR((int)yyvsp[-5].d, (int)yyvsp[-3].d, (int)yyvsp[-1].d, 255);
    }
    break;

  case 437:
#line 3016 "Gmsh.y"
    {
      yyval.u = Get_ColorForString(ColorString, -1, yyvsp[0].c, &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", yyvsp[0].c);
    }
    break;

  case 438:
#line 3021 "Gmsh.y"
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

  case 439:
#line 3040 "Gmsh.y"
    {
      yyval.l = yyvsp[-1].l;
    }
    break;

  case 440:
#line 3044 "Gmsh.y"
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

  case 441:
#line 3058 "Gmsh.y"
    {
      yyval.l = List_Create(256,10,sizeof(unsigned int)) ;
      List_Add(yyval.l, &(yyvsp[0].u)) ;
    }
    break;

  case 442:
#line 3063 "Gmsh.y"
    {
      List_Add(yyval.l, &(yyvsp[0].u)) ;
    }
    break;

  case 443:
#line 3070 "Gmsh.y"
    {
      yyval.c = yyvsp[0].c;
    }
    break;

  case 444:
#line 3074 "Gmsh.y"
    {
      yyval.c = (char *)Malloc((strlen(yyvsp[-3].c)+strlen(yyvsp[-1].c)+1)*sizeof(char)) ;
      strcpy(yyval.c, yyvsp[-3].c) ;  
      strcat(yyval.c, yyvsp[-1].c) ;
      Free(yyvsp[-3].c);
      Free(yyvsp[-1].c);
    }
    break;

  case 445:
#line 3082 "Gmsh.y"
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

  case 446:
#line 3095 "Gmsh.y"
    {
      yyval.c = yyvsp[-1].c;
    }
    break;

  case 447:
#line 3099 "Gmsh.y"
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

  case 448:
#line 3117 "Gmsh.y"
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

  case 449:
#line 3131 "Gmsh.y"
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
#line 9036 "Gmsh.tab.cpp"

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


#line 3146 "Gmsh.y"


void InitSymbols(void){
  if(!Symbol_L)
    Symbol_L = List_Create(50,10,sizeof(Symbol));
  else
    List_Reset(Symbol_L);
}

void DeleteSymbols(void){
  int i;
  for(i = 0 ; i < List_Nbr(Symbol_L) ; i++)
    List_Delete(((Symbol*)List_Pointer_Fast(Symbol_L,i))->val);
  List_Delete(Symbol_L);
}

int CompareSymbols (const void *a, const void *b){
  return(strcmp(((Symbol*)a)->Name,((Symbol*)b)->Name));
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



