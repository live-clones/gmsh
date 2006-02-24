/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     tAFFECTDIVIDE = 361,
     tAFFECTTIMES = 362,
     tAFFECTMINUS = 363,
     tAFFECTPLUS = 364,
     tOR = 365,
     tAND = 366,
     tAPPROXEQUAL = 367,
     tNOTEQUAL = 368,
     tEQUAL = 369,
     tGREATEROREQUAL = 370,
     tLESSOREQUAL = 371,
     tCROSSPRODUCT = 372,
     UNARYPREC = 373,
     tMINUSMINUS = 374,
     tPLUSPLUS = 375
   };
#endif
/* Tokens.  */
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
#define tAFFECTDIVIDE 361
#define tAFFECTTIMES 362
#define tAFFECTMINUS 363
#define tAFFECTPLUS 364
#define tOR 365
#define tAND 366
#define tAPPROXEQUAL 367
#define tNOTEQUAL 368
#define tEQUAL 369
#define tGREATEROREQUAL 370
#define tLESSOREQUAL 371
#define tCROSSPRODUCT 372
#define UNARYPREC 373
#define tMINUSMINUS 374
#define tPLUSPLUS 375




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 78 "Gmsh.y"
typedef union YYSTYPE {
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 288 "Gmsh.tab.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



