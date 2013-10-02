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
     tRound = 287,
     tFmod = 288,
     tModulo = 289,
     tHypot = 290,
     tList = 291,
     tPrintf = 292,
     tError = 293,
     tStr = 294,
     tSprintf = 295,
     tStrCat = 296,
     tStrPrefix = 297,
     tStrRelative = 298,
     tStrReplace = 299,
     tStrFind = 300,
     tStrCmp = 301,
     tTextAttributes = 302,
     tBoundingBox = 303,
     tDraw = 304,
     tSetChanged = 305,
     tToday = 306,
     tCpu = 307,
     tMemory = 308,
     tSyncModel = 309,
     tCreateTopology = 310,
     tCreateTopologyNoHoles = 311,
     tDistanceFunction = 312,
     tDefineConstant = 313,
     tUndefineConstant = 314,
     tPoint = 315,
     tCircle = 316,
     tEllipse = 317,
     tLine = 318,
     tSphere = 319,
     tPolarSphere = 320,
     tSurface = 321,
     tSpline = 322,
     tVolume = 323,
     tCharacteristic = 324,
     tLength = 325,
     tParametric = 326,
     tElliptic = 327,
     tRefineMesh = 328,
     tAdaptMesh = 329,
     tPlane = 330,
     tRuled = 331,
     tTransfinite = 332,
     tComplex = 333,
     tPhysical = 334,
     tCompound = 335,
     tPeriodic = 336,
     tUsing = 337,
     tPlugin = 338,
     tDegenerated = 339,
     tRecursive = 340,
     tRotate = 341,
     tTranslate = 342,
     tSymmetry = 343,
     tDilate = 344,
     tExtrude = 345,
     tLevelset = 346,
     tRecombine = 347,
     tSmoother = 348,
     tSplit = 349,
     tDelete = 350,
     tCoherence = 351,
     tIntersect = 352,
     tMeshAlgorithm = 353,
     tReverse = 354,
     tLayers = 355,
     tScaleLast = 356,
     tHole = 357,
     tAlias = 358,
     tAliasWithOptions = 359,
     tCopyOptions = 360,
     tQuadTriAddVerts = 361,
     tQuadTriNoNewVerts = 362,
     tQuadTriSngl = 363,
     tQuadTriDbl = 364,
     tRecombLaterals = 365,
     tTransfQuadTri = 366,
     tText2D = 367,
     tText3D = 368,
     tInterpolationScheme = 369,
     tTime = 370,
     tCombine = 371,
     tBSpline = 372,
     tBezier = 373,
     tNurbs = 374,
     tNurbsOrder = 375,
     tNurbsKnots = 376,
     tColor = 377,
     tColorTable = 378,
     tFor = 379,
     tIn = 380,
     tEndFor = 381,
     tIf = 382,
     tEndIf = 383,
     tExit = 384,
     tAbort = 385,
     tField = 386,
     tReturn = 387,
     tCall = 388,
     tFunction = 389,
     tShow = 390,
     tHide = 391,
     tGetValue = 392,
     tGetEnv = 393,
     tGetString = 394,
     tHomology = 395,
     tCohomology = 396,
     tBetti = 397,
     tSetOrder = 398,
     tGMSH_MAJOR_VERSION = 399,
     tGMSH_MINOR_VERSION = 400,
     tGMSH_PATCH_VERSION = 401,
     tAFFECTDIVIDE = 402,
     tAFFECTTIMES = 403,
     tAFFECTMINUS = 404,
     tAFFECTPLUS = 405,
     tOR = 406,
     tAND = 407,
     tNOTEQUAL = 408,
     tEQUAL = 409,
     tGREATEROREQUAL = 410,
     tLESSOREQUAL = 411,
     UNARYPREC = 412,
     tMINUSMINUS = 413,
     tPLUSPLUS = 414
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
#define tRound 287
#define tFmod 288
#define tModulo 289
#define tHypot 290
#define tList 291
#define tPrintf 292
#define tError 293
#define tStr 294
#define tSprintf 295
#define tStrCat 296
#define tStrPrefix 297
#define tStrRelative 298
#define tStrReplace 299
#define tStrFind 300
#define tStrCmp 301
#define tTextAttributes 302
#define tBoundingBox 303
#define tDraw 304
#define tSetChanged 305
#define tToday 306
#define tCpu 307
#define tMemory 308
#define tSyncModel 309
#define tCreateTopology 310
#define tCreateTopologyNoHoles 311
#define tDistanceFunction 312
#define tDefineConstant 313
#define tUndefineConstant 314
#define tPoint 315
#define tCircle 316
#define tEllipse 317
#define tLine 318
#define tSphere 319
#define tPolarSphere 320
#define tSurface 321
#define tSpline 322
#define tVolume 323
#define tCharacteristic 324
#define tLength 325
#define tParametric 326
#define tElliptic 327
#define tRefineMesh 328
#define tAdaptMesh 329
#define tPlane 330
#define tRuled 331
#define tTransfinite 332
#define tComplex 333
#define tPhysical 334
#define tCompound 335
#define tPeriodic 336
#define tUsing 337
#define tPlugin 338
#define tDegenerated 339
#define tRecursive 340
#define tRotate 341
#define tTranslate 342
#define tSymmetry 343
#define tDilate 344
#define tExtrude 345
#define tLevelset 346
#define tRecombine 347
#define tSmoother 348
#define tSplit 349
#define tDelete 350
#define tCoherence 351
#define tIntersect 352
#define tMeshAlgorithm 353
#define tReverse 354
#define tLayers 355
#define tScaleLast 356
#define tHole 357
#define tAlias 358
#define tAliasWithOptions 359
#define tCopyOptions 360
#define tQuadTriAddVerts 361
#define tQuadTriNoNewVerts 362
#define tQuadTriSngl 363
#define tQuadTriDbl 364
#define tRecombLaterals 365
#define tTransfQuadTri 366
#define tText2D 367
#define tText3D 368
#define tInterpolationScheme 369
#define tTime 370
#define tCombine 371
#define tBSpline 372
#define tBezier 373
#define tNurbs 374
#define tNurbsOrder 375
#define tNurbsKnots 376
#define tColor 377
#define tColorTable 378
#define tFor 379
#define tIn 380
#define tEndFor 381
#define tIf 382
#define tEndIf 383
#define tExit 384
#define tAbort 385
#define tField 386
#define tReturn 387
#define tCall 388
#define tFunction 389
#define tShow 390
#define tHide 391
#define tGetValue 392
#define tGetEnv 393
#define tGetString 394
#define tHomology 395
#define tCohomology 396
#define tBetti 397
#define tSetOrder 398
#define tGMSH_MAJOR_VERSION 399
#define tGMSH_MINOR_VERSION 400
#define tGMSH_PATCH_VERSION 401
#define tAFFECTDIVIDE 402
#define tAFFECTTIMES 403
#define tAFFECTMINUS 404
#define tAFFECTPLUS 405
#define tOR 406
#define tAND 407
#define tNOTEQUAL 408
#define tEQUAL 409
#define tGREATEROREQUAL 410
#define tLESSOREQUAL 411
#define UNARYPREC 412
#define tMINUSMINUS 413
#define tPLUSPLUS 414




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
#line 377 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

