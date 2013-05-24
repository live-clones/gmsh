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
     tList = 290,
     tPrintf = 291,
     tError = 292,
     tSprintf = 293,
     tStrCat = 294,
     tStrPrefix = 295,
     tStrRelative = 296,
     tStrReplace = 297,
     tStrFind = 298,
     tTextAttributes = 299,
     tBoundingBox = 300,
     tDraw = 301,
     tToday = 302,
     tSyncModel = 303,
     tCreateTopology = 304,
     tCreateTopologyNoHoles = 305,
     tDistanceFunction = 306,
     tDefineConstant = 307,
     tUndefineConstant = 308,
     tPoint = 309,
     tCircle = 310,
     tEllipse = 311,
     tLine = 312,
     tSphere = 313,
     tPolarSphere = 314,
     tSurface = 315,
     tSpline = 316,
     tVolume = 317,
     tCharacteristic = 318,
     tLength = 319,
     tParametric = 320,
     tElliptic = 321,
     tRefineMesh = 322,
     tPlane = 323,
     tRuled = 324,
     tTransfinite = 325,
     tComplex = 326,
     tPhysical = 327,
     tCompound = 328,
     tPeriodic = 329,
     tUsing = 330,
     tPlugin = 331,
     tDegenerated = 332,
     tRotate = 333,
     tTranslate = 334,
     tSymmetry = 335,
     tDilate = 336,
     tExtrude = 337,
     tLevelset = 338,
     tRecombine = 339,
     tSmoother = 340,
     tSplit = 341,
     tDelete = 342,
     tCoherence = 343,
     tIntersect = 344,
     tMeshAlgorithm = 345,
     tReverse = 346,
     tLayers = 347,
     tHole = 348,
     tAlias = 349,
     tAliasWithOptions = 350,
     tQuadTriDbl = 351,
     tQuadTriSngl = 352,
     tRecombLaterals = 353,
     tTransfQuadTri = 354,
     tText2D = 355,
     tText3D = 356,
     tInterpolationScheme = 357,
     tTime = 358,
     tCombine = 359,
     tBSpline = 360,
     tBezier = 361,
     tNurbs = 362,
     tNurbsOrder = 363,
     tNurbsKnots = 364,
     tColor = 365,
     tColorTable = 366,
     tFor = 367,
     tIn = 368,
     tEndFor = 369,
     tIf = 370,
     tEndIf = 371,
     tExit = 372,
     tAbort = 373,
     tField = 374,
     tReturn = 375,
     tCall = 376,
     tFunction = 377,
     tShow = 378,
     tHide = 379,
     tGetValue = 380,
     tGetEnv = 381,
     tGetString = 382,
     tHomology = 383,
     tCohomology = 384,
     tBetti = 385,
     tSetOrder = 386,
     tGMSH_MAJOR_VERSION = 387,
     tGMSH_MINOR_VERSION = 388,
     tGMSH_PATCH_VERSION = 389,
     tAFFECTDIVIDE = 390,
     tAFFECTTIMES = 391,
     tAFFECTMINUS = 392,
     tAFFECTPLUS = 393,
     tOR = 394,
     tAND = 395,
     tNOTEQUAL = 396,
     tEQUAL = 397,
     tGREATEROREQUAL = 398,
     tLESSOREQUAL = 399,
     UNARYPREC = 400,
     tMINUSMINUS = 401,
     tPLUSPLUS = 402
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
#define tList 290
#define tPrintf 291
#define tError 292
#define tSprintf 293
#define tStrCat 294
#define tStrPrefix 295
#define tStrRelative 296
#define tStrReplace 297
#define tStrFind 298
#define tTextAttributes 299
#define tBoundingBox 300
#define tDraw 301
#define tToday 302
#define tSyncModel 303
#define tCreateTopology 304
#define tCreateTopologyNoHoles 305
#define tDistanceFunction 306
#define tDefineConstant 307
#define tUndefineConstant 308
#define tPoint 309
#define tCircle 310
#define tEllipse 311
#define tLine 312
#define tSphere 313
#define tPolarSphere 314
#define tSurface 315
#define tSpline 316
#define tVolume 317
#define tCharacteristic 318
#define tLength 319
#define tParametric 320
#define tElliptic 321
#define tRefineMesh 322
#define tPlane 323
#define tRuled 324
#define tTransfinite 325
#define tComplex 326
#define tPhysical 327
#define tCompound 328
#define tPeriodic 329
#define tUsing 330
#define tPlugin 331
#define tDegenerated 332
#define tRotate 333
#define tTranslate 334
#define tSymmetry 335
#define tDilate 336
#define tExtrude 337
#define tLevelset 338
#define tRecombine 339
#define tSmoother 340
#define tSplit 341
#define tDelete 342
#define tCoherence 343
#define tIntersect 344
#define tMeshAlgorithm 345
#define tReverse 346
#define tLayers 347
#define tHole 348
#define tAlias 349
#define tAliasWithOptions 350
#define tQuadTriDbl 351
#define tQuadTriSngl 352
#define tRecombLaterals 353
#define tTransfQuadTri 354
#define tText2D 355
#define tText3D 356
#define tInterpolationScheme 357
#define tTime 358
#define tCombine 359
#define tBSpline 360
#define tBezier 361
#define tNurbs 362
#define tNurbsOrder 363
#define tNurbsKnots 364
#define tColor 365
#define tColorTable 366
#define tFor 367
#define tIn 368
#define tEndFor 369
#define tIf 370
#define tEndIf 371
#define tExit 372
#define tAbort 373
#define tField 374
#define tReturn 375
#define tCall 376
#define tFunction 377
#define tShow 378
#define tHide 379
#define tGetValue 380
#define tGetEnv 381
#define tGetString 382
#define tHomology 383
#define tCohomology 384
#define tBetti 385
#define tSetOrder 386
#define tGMSH_MAJOR_VERSION 387
#define tGMSH_MINOR_VERSION 388
#define tGMSH_PATCH_VERSION 389
#define tAFFECTDIVIDE 390
#define tAFFECTTIMES 391
#define tAFFECTMINUS 392
#define tAFFECTPLUS 393
#define tOR 394
#define tAND 395
#define tNOTEQUAL 396
#define tEQUAL 397
#define tGREATEROREQUAL 398
#define tLESSOREQUAL 399
#define UNARYPREC 400
#define tMINUSMINUS 401
#define tPLUSPLUS 402




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 93 "Gmsh.y"
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
#line 353 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

