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
     tTestLevel = 269,
     tExp = 270,
     tLog = 271,
     tLog10 = 272,
     tSqrt = 273,
     tSin = 274,
     tAsin = 275,
     tCos = 276,
     tAcos = 277,
     tTan = 278,
     tRand = 279,
     tAtan = 280,
     tAtan2 = 281,
     tSinh = 282,
     tCosh = 283,
     tTanh = 284,
     tFabs = 285,
     tFloor = 286,
     tCeil = 287,
     tRound = 288,
     tFmod = 289,
     tModulo = 290,
     tHypot = 291,
     tList = 292,
     tPrintf = 293,
     tError = 294,
     tStr = 295,
     tSprintf = 296,
     tStrCat = 297,
     tStrPrefix = 298,
     tStrRelative = 299,
     tStrReplace = 300,
     tAbsolutePath = 301,
     tDirName = 302,
     tFind = 303,
     tStrFind = 304,
     tStrCmp = 305,
     tStrChoice = 306,
     tUpperCase = 307,
     tLowerCase = 308,
     tLowerCaseIn = 309,
     tTextAttributes = 310,
     tBoundingBox = 311,
     tDraw = 312,
     tSetChanged = 313,
     tToday = 314,
     tFixRelativePath = 315,
     tCurrentDirectory = 316,
     tSyncModel = 317,
     tNewModel = 318,
     tOnelabAction = 319,
     tOnelabRun = 320,
     tCpu = 321,
     tMemory = 322,
     tTotalMemory = 323,
     tCreateTopology = 324,
     tCreateTopologyNoHoles = 325,
     tDistanceFunction = 326,
     tDefineConstant = 327,
     tUndefineConstant = 328,
     tDefineNumber = 329,
     tDefineString = 330,
     tSetNumber = 331,
     tSetString = 332,
     tPoint = 333,
     tCircle = 334,
     tEllipse = 335,
     tLine = 336,
     tSphere = 337,
     tPolarSphere = 338,
     tSurface = 339,
     tSpline = 340,
     tVolume = 341,
     tCharacteristic = 342,
     tLength = 343,
     tParametric = 344,
     tElliptic = 345,
     tRefineMesh = 346,
     tAdaptMesh = 347,
     tRelocateMesh = 348,
     tPlane = 349,
     tRuled = 350,
     tTransfinite = 351,
     tComplex = 352,
     tPhysical = 353,
     tCompound = 354,
     tPeriodic = 355,
     tUsing = 356,
     tPlugin = 357,
     tDegenerated = 358,
     tRecursive = 359,
     tRotate = 360,
     tTranslate = 361,
     tSymmetry = 362,
     tDilate = 363,
     tExtrude = 364,
     tLevelset = 365,
     tAffine = 366,
     tRecombine = 367,
     tSmoother = 368,
     tSplit = 369,
     tDelete = 370,
     tCoherence = 371,
     tIntersect = 372,
     tMeshAlgorithm = 373,
     tReverse = 374,
     tLayers = 375,
     tScaleLast = 376,
     tHole = 377,
     tAlias = 378,
     tAliasWithOptions = 379,
     tCopyOptions = 380,
     tQuadTriAddVerts = 381,
     tQuadTriNoNewVerts = 382,
     tQuadTriSngl = 383,
     tQuadTriDbl = 384,
     tRecombLaterals = 385,
     tTransfQuadTri = 386,
     tText2D = 387,
     tText3D = 388,
     tInterpolationScheme = 389,
     tTime = 390,
     tCombine = 391,
     tBSpline = 392,
     tBezier = 393,
     tNurbs = 394,
     tNurbsOrder = 395,
     tNurbsKnots = 396,
     tColor = 397,
     tColorTable = 398,
     tFor = 399,
     tIn = 400,
     tEndFor = 401,
     tIf = 402,
     tElseIf = 403,
     tElse = 404,
     tEndIf = 405,
     tExit = 406,
     tAbort = 407,
     tField = 408,
     tReturn = 409,
     tCall = 410,
     tMacro = 411,
     tShow = 412,
     tHide = 413,
     tGetValue = 414,
     tGetStringValue = 415,
     tGetEnv = 416,
     tGetString = 417,
     tGetNumber = 418,
     tHomology = 419,
     tCohomology = 420,
     tBetti = 421,
     tExists = 422,
     tFileExists = 423,
     tGMSH_MAJOR_VERSION = 424,
     tGMSH_MINOR_VERSION = 425,
     tGMSH_PATCH_VERSION = 426,
     tGmshExecutableName = 427,
     tSetPartition = 428,
     tNameToString = 429,
     tStringToName = 430,
     tAFFECTDIVIDE = 431,
     tAFFECTTIMES = 432,
     tAFFECTMINUS = 433,
     tAFFECTPLUS = 434,
     tOR = 435,
     tAND = 436,
     tNOTEQUAL = 437,
     tEQUAL = 438,
     tGREATEROREQUAL = 439,
     tLESSOREQUAL = 440,
     UNARYPREC = 441,
     tMINUSMINUS = 442,
     tPLUSPLUS = 443
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
#define tTestLevel 269
#define tExp 270
#define tLog 271
#define tLog10 272
#define tSqrt 273
#define tSin 274
#define tAsin 275
#define tCos 276
#define tAcos 277
#define tTan 278
#define tRand 279
#define tAtan 280
#define tAtan2 281
#define tSinh 282
#define tCosh 283
#define tTanh 284
#define tFabs 285
#define tFloor 286
#define tCeil 287
#define tRound 288
#define tFmod 289
#define tModulo 290
#define tHypot 291
#define tList 292
#define tPrintf 293
#define tError 294
#define tStr 295
#define tSprintf 296
#define tStrCat 297
#define tStrPrefix 298
#define tStrRelative 299
#define tStrReplace 300
#define tAbsolutePath 301
#define tDirName 302
#define tFind 303
#define tStrFind 304
#define tStrCmp 305
#define tStrChoice 306
#define tUpperCase 307
#define tLowerCase 308
#define tLowerCaseIn 309
#define tTextAttributes 310
#define tBoundingBox 311
#define tDraw 312
#define tSetChanged 313
#define tToday 314
#define tFixRelativePath 315
#define tCurrentDirectory 316
#define tSyncModel 317
#define tNewModel 318
#define tOnelabAction 319
#define tOnelabRun 320
#define tCpu 321
#define tMemory 322
#define tTotalMemory 323
#define tCreateTopology 324
#define tCreateTopologyNoHoles 325
#define tDistanceFunction 326
#define tDefineConstant 327
#define tUndefineConstant 328
#define tDefineNumber 329
#define tDefineString 330
#define tSetNumber 331
#define tSetString 332
#define tPoint 333
#define tCircle 334
#define tEllipse 335
#define tLine 336
#define tSphere 337
#define tPolarSphere 338
#define tSurface 339
#define tSpline 340
#define tVolume 341
#define tCharacteristic 342
#define tLength 343
#define tParametric 344
#define tElliptic 345
#define tRefineMesh 346
#define tAdaptMesh 347
#define tRelocateMesh 348
#define tPlane 349
#define tRuled 350
#define tTransfinite 351
#define tComplex 352
#define tPhysical 353
#define tCompound 354
#define tPeriodic 355
#define tUsing 356
#define tPlugin 357
#define tDegenerated 358
#define tRecursive 359
#define tRotate 360
#define tTranslate 361
#define tSymmetry 362
#define tDilate 363
#define tExtrude 364
#define tLevelset 365
#define tAffine 366
#define tRecombine 367
#define tSmoother 368
#define tSplit 369
#define tDelete 370
#define tCoherence 371
#define tIntersect 372
#define tMeshAlgorithm 373
#define tReverse 374
#define tLayers 375
#define tScaleLast 376
#define tHole 377
#define tAlias 378
#define tAliasWithOptions 379
#define tCopyOptions 380
#define tQuadTriAddVerts 381
#define tQuadTriNoNewVerts 382
#define tQuadTriSngl 383
#define tQuadTriDbl 384
#define tRecombLaterals 385
#define tTransfQuadTri 386
#define tText2D 387
#define tText3D 388
#define tInterpolationScheme 389
#define tTime 390
#define tCombine 391
#define tBSpline 392
#define tBezier 393
#define tNurbs 394
#define tNurbsOrder 395
#define tNurbsKnots 396
#define tColor 397
#define tColorTable 398
#define tFor 399
#define tIn 400
#define tEndFor 401
#define tIf 402
#define tElseIf 403
#define tElse 404
#define tEndIf 405
#define tExit 406
#define tAbort 407
#define tField 408
#define tReturn 409
#define tCall 410
#define tMacro 411
#define tShow 412
#define tHide 413
#define tGetValue 414
#define tGetStringValue 415
#define tGetEnv 416
#define tGetString 417
#define tGetNumber 418
#define tHomology 419
#define tCohomology 420
#define tBetti 421
#define tExists 422
#define tFileExists 423
#define tGMSH_MAJOR_VERSION 424
#define tGMSH_MINOR_VERSION 425
#define tGMSH_PATCH_VERSION 426
#define tGmshExecutableName 427
#define tSetPartition 428
#define tNameToString 429
#define tStringToName 430
#define tAFFECTDIVIDE 431
#define tAFFECTTIMES 432
#define tAFFECTMINUS 433
#define tAFFECTPLUS 434
#define tOR 435
#define tAND 436
#define tNOTEQUAL 437
#define tEQUAL 438
#define tGREATEROREQUAL 439
#define tLESSOREQUAL 440
#define UNARYPREC 441
#define tMINUSMINUS 442
#define tPLUSPLUS 443




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 110 "Gmsh.y"
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
#line 435 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

