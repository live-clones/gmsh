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

#ifndef BISON_GMSH_TAB_HPP
# define BISON_GMSH_TAB_HPP

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
/* Line 1281 of /usr/share/bison/yacc.c.  */
#line 418 "Gmsh.tab.hpp"
# define YYSTYPE yystype
#endif

extern YYSTYPE yylval;


#endif /* not BISON_GMSH_TAB_HPP */

