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
     tSyncModel = 298,
     tCreateTopology = 299,
     tDistanceFunction = 300,
     tPoint = 301,
     tCircle = 302,
     tEllipse = 303,
     tLine = 304,
     tSphere = 305,
     tPolarSphere = 306,
     tSurface = 307,
     tSpline = 308,
     tVolume = 309,
     tCharacteristic = 310,
     tLength = 311,
     tParametric = 312,
     tElliptic = 313,
     tPlane = 314,
     tRuled = 315,
     tTransfinite = 316,
     tComplex = 317,
     tPhysical = 318,
     tCompound = 319,
     tPeriodic = 320,
     tUsing = 321,
     tPlugin = 322,
     tDegenerated = 323,
     tOCCShape = 324,
     tRotate = 325,
     tTranslate = 326,
     tSymmetry = 327,
     tDilate = 328,
     tExtrude = 329,
     tLevelset = 330,
     tLoop = 331,
     tRecombine = 332,
     tSmoother = 333,
     tSplit = 334,
     tDelete = 335,
     tCoherence = 336,
     tIntersect = 337,
     tLayers = 338,
     tHole = 339,
     tAlias = 340,
     tAliasWithOptions = 341,
     tText2D = 342,
     tText3D = 343,
     tInterpolationScheme = 344,
     tTime = 345,
     tCombine = 346,
     tBSpline = 347,
     tBezier = 348,
     tNurbs = 349,
     tNurbsOrder = 350,
     tNurbsKnots = 351,
     tColor = 352,
     tColorTable = 353,
     tFor = 354,
     tIn = 355,
     tEndFor = 356,
     tIf = 357,
     tEndIf = 358,
     tExit = 359,
     tField = 360,
     tReturn = 361,
     tCall = 362,
     tFunction = 363,
     tShow = 364,
     tHide = 365,
     tGetValue = 366,
     tGMSH_MAJOR_VERSION = 367,
     tGMSH_MINOR_VERSION = 368,
     tGMSH_PATCH_VERSION = 369,
     tHomRank = 370,
     tHomGen = 371,
     tHomCut = 372,
     tHomSeq = 373,
     tAFFECTDIVIDE = 374,
     tAFFECTTIMES = 375,
     tAFFECTMINUS = 376,
     tAFFECTPLUS = 377,
     tOR = 378,
     tAND = 379,
     tNOTEQUAL = 380,
     tEQUAL = 381,
     tGREATEROREQUAL = 382,
     tLESSOREQUAL = 383,
     UNARYPREC = 384,
     tMINUSMINUS = 385,
     tPLUSPLUS = 386
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
#define tSyncModel 298
#define tCreateTopology 299
#define tDistanceFunction 300
#define tPoint 301
#define tCircle 302
#define tEllipse 303
#define tLine 304
#define tSphere 305
#define tPolarSphere 306
#define tSurface 307
#define tSpline 308
#define tVolume 309
#define tCharacteristic 310
#define tLength 311
#define tParametric 312
#define tElliptic 313
#define tPlane 314
#define tRuled 315
#define tTransfinite 316
#define tComplex 317
#define tPhysical 318
#define tCompound 319
#define tPeriodic 320
#define tUsing 321
#define tPlugin 322
#define tDegenerated 323
#define tOCCShape 324
#define tRotate 325
#define tTranslate 326
#define tSymmetry 327
#define tDilate 328
#define tExtrude 329
#define tLevelset 330
#define tLoop 331
#define tRecombine 332
#define tSmoother 333
#define tSplit 334
#define tDelete 335
#define tCoherence 336
#define tIntersect 337
#define tLayers 338
#define tHole 339
#define tAlias 340
#define tAliasWithOptions 341
#define tText2D 342
#define tText3D 343
#define tInterpolationScheme 344
#define tTime 345
#define tCombine 346
#define tBSpline 347
#define tBezier 348
#define tNurbs 349
#define tNurbsOrder 350
#define tNurbsKnots 351
#define tColor 352
#define tColorTable 353
#define tFor 354
#define tIn 355
#define tEndFor 356
#define tIf 357
#define tEndIf 358
#define tExit 359
#define tField 360
#define tReturn 361
#define tCall 362
#define tFunction 363
#define tShow 364
#define tHide 365
#define tGetValue 366
#define tGMSH_MAJOR_VERSION 367
#define tGMSH_MINOR_VERSION 368
#define tGMSH_PATCH_VERSION 369
#define tHomRank 370
#define tHomGen 371
#define tHomCut 372
#define tHomSeq 373
#define tAFFECTDIVIDE 374
#define tAFFECTTIMES 375
#define tAFFECTMINUS 376
#define tAFFECTPLUS 377
#define tOR 378
#define tAND 379
#define tNOTEQUAL 380
#define tEQUAL 381
#define tGREATEROREQUAL 382
#define tLESSOREQUAL 383
#define UNARYPREC 384
#define tMINUSMINUS 385
#define tPLUSPLUS 386




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 85 "Gmsh.y"
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
#line 321 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

