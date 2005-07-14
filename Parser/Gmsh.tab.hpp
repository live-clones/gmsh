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
/* Line 1249 of yacc.c.  */
#line 372 "Gmsh.tab.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



