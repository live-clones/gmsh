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
     tInterpolationMatrix = 354,
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
#define tInterpolationMatrix 354
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
/* Line 1252 of yacc.c.  */
#line 423 "Gmsh.tab.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



