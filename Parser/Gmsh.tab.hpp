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
/* Line 1281 of /usr/share/bison/yacc.c.  */
#line 416 "Gmsh.tab.hpp"
# define YYSTYPE yystype
#endif

extern YYSTYPE yylval;


#endif /* not BISON_GMSH_TAB_HPP */

