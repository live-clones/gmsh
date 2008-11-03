/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

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
     tEuclidian = 267,
     tCoordinates = 268,
     tExp = 269,
     tLog = 270,
     tLog10 = 271,
     tSqrt = 272,
     tSin = 273,
     tAsin = 274,
     tCos = 275,
     tAcos = 276,
     tTan = 277,
     tRand = 278,
     tAtan = 279,
     tAtan2 = 280,
     tSinh = 281,
     tCosh = 282,
     tTanh = 283,
     tFabs = 284,
     tFloor = 285,
     tCeil = 286,
     tFmod = 287,
     tModulo = 288,
     tHypot = 289,
     tPrintf = 290,
     tSprintf = 291,
     tStrCat = 292,
     tStrPrefix = 293,
     tStrRelative = 294,
     tBoundingBox = 295,
     tDraw = 296,
     tToday = 297,
     tPoint = 298,
     tCircle = 299,
     tEllipse = 300,
     tLine = 301,
     tSphere = 302,
     tPolarSphere = 303,
     tSurface = 304,
     tSpline = 305,
     tVolume = 306,
     tCharacteristic = 307,
     tLength = 308,
     tParametric = 309,
     tElliptic = 310,
     tPlane = 311,
     tRuled = 312,
     tTransfinite = 313,
     tComplex = 314,
     tPhysical = 315,
     tUsing = 316,
     tPlugin = 317,
     tRotate = 318,
     tTranslate = 319,
     tSymmetry = 320,
     tDilate = 321,
     tExtrude = 322,
     tLoop = 323,
     tRecombine = 324,
     tSmoother = 325,
     tSplit = 326,
     tDelete = 327,
     tCoherence = 328,
     tIntersect = 329,
     tLayers = 330,
     tHole = 331,
     tAlias = 332,
     tAliasWithOptions = 333,
     tText2D = 334,
     tText3D = 335,
     tInterpolationScheme = 336,
     tTime = 337,
     tCombine = 338,
     tBSpline = 339,
     tBezier = 340,
     tNurbs = 341,
     tOrder = 342,
     tKnots = 343,
     tColor = 344,
     tColorTable = 345,
     tFor = 346,
     tIn = 347,
     tEndFor = 348,
     tIf = 349,
     tEndIf = 350,
     tExit = 351,
     tField = 352,
     tReturn = 353,
     tCall = 354,
     tFunction = 355,
     tShow = 356,
     tHide = 357,
     tGetValue = 358,
     tGMSH_MAJOR_VERSION = 359,
     tGMSH_MINOR_VERSION = 360,
     tGMSH_PATCH_VERSION = 361,
     tAFFECTDIVIDE = 362,
     tAFFECTTIMES = 363,
     tAFFECTMINUS = 364,
     tAFFECTPLUS = 365,
     tOR = 366,
     tAND = 367,
     tNOTEQUAL = 368,
     tEQUAL = 369,
     tGREATEROREQUAL = 370,
     tLESSOREQUAL = 371,
     UNARYPREC = 372,
     tMINUSMINUS = 373,
     tPLUSPLUS = 374
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
#define tEuclidian 267
#define tCoordinates 268
#define tExp 269
#define tLog 270
#define tLog10 271
#define tSqrt 272
#define tSin 273
#define tAsin 274
#define tCos 275
#define tAcos 276
#define tTan 277
#define tRand 278
#define tAtan 279
#define tAtan2 280
#define tSinh 281
#define tCosh 282
#define tTanh 283
#define tFabs 284
#define tFloor 285
#define tCeil 286
#define tFmod 287
#define tModulo 288
#define tHypot 289
#define tPrintf 290
#define tSprintf 291
#define tStrCat 292
#define tStrPrefix 293
#define tStrRelative 294
#define tBoundingBox 295
#define tDraw 296
#define tToday 297
#define tPoint 298
#define tCircle 299
#define tEllipse 300
#define tLine 301
#define tSphere 302
#define tPolarSphere 303
#define tSurface 304
#define tSpline 305
#define tVolume 306
#define tCharacteristic 307
#define tLength 308
#define tParametric 309
#define tElliptic 310
#define tPlane 311
#define tRuled 312
#define tTransfinite 313
#define tComplex 314
#define tPhysical 315
#define tUsing 316
#define tPlugin 317
#define tRotate 318
#define tTranslate 319
#define tSymmetry 320
#define tDilate 321
#define tExtrude 322
#define tLoop 323
#define tRecombine 324
#define tSmoother 325
#define tSplit 326
#define tDelete 327
#define tCoherence 328
#define tIntersect 329
#define tLayers 330
#define tHole 331
#define tAlias 332
#define tAliasWithOptions 333
#define tText2D 334
#define tText3D 335
#define tInterpolationScheme 336
#define tTime 337
#define tCombine 338
#define tBSpline 339
#define tBezier 340
#define tNurbs 341
#define tOrder 342
#define tKnots 343
#define tColor 344
#define tColorTable 345
#define tFor 346
#define tIn 347
#define tEndFor 348
#define tIf 349
#define tEndIf 350
#define tExit 351
#define tField 352
#define tReturn 353
#define tCall 354
#define tFunction 355
#define tShow 356
#define tHide 357
#define tGetValue 358
#define tGMSH_MAJOR_VERSION 359
#define tGMSH_MINOR_VERSION 360
#define tGMSH_PATCH_VERSION 361
#define tAFFECTDIVIDE 362
#define tAFFECTTIMES 363
#define tAFFECTMINUS 364
#define tAFFECTPLUS 365
#define tOR 366
#define tAND 367
#define tNOTEQUAL 368
#define tEQUAL 369
#define tGREATEROREQUAL 370
#define tLESSOREQUAL 371
#define UNARYPREC 372
#define tMINUSMINUS 373
#define tPLUSPLUS 374




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 71 "Gmsh.y"
{
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
}
/* Line 1529 of yacc.c.  */
#line 297 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

