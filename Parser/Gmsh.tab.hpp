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
     tLinSpace = 293,
     tLogSpace = 294,
     tListFromFile = 295,
     tCatenary = 296,
     tPrintf = 297,
     tError = 298,
     tStr = 299,
     tSprintf = 300,
     tStrCat = 301,
     tStrPrefix = 302,
     tStrRelative = 303,
     tStrReplace = 304,
     tAbsolutePath = 305,
     tDirName = 306,
     tStrSub = 307,
     tStrLen = 308,
     tFind = 309,
     tStrFind = 310,
     tStrCmp = 311,
     tStrChoice = 312,
     tUpperCase = 313,
     tLowerCase = 314,
     tLowerCaseIn = 315,
     tTextAttributes = 316,
     tBoundingBox = 317,
     tDraw = 318,
     tSetChanged = 319,
     tToday = 320,
     tFixRelativePath = 321,
     tCurrentDirectory = 322,
     tSyncModel = 323,
     tNewModel = 324,
     tOnelabAction = 325,
     tOnelabRun = 326,
     tCpu = 327,
     tMemory = 328,
     tTotalMemory = 329,
     tCreateTopology = 330,
     tCreateTopologyNoHoles = 331,
     tDistanceFunction = 332,
     tDefineConstant = 333,
     tUndefineConstant = 334,
     tDefineNumber = 335,
     tDefineString = 336,
     tSetNumber = 337,
     tSetString = 338,
     tPoint = 339,
     tCircle = 340,
     tEllipse = 341,
     tLine = 342,
     tSphere = 343,
     tPolarSphere = 344,
     tSurface = 345,
     tSpline = 346,
     tVolume = 347,
     tCharacteristic = 348,
     tLength = 349,
     tParametric = 350,
     tElliptic = 351,
     tRefineMesh = 352,
     tAdaptMesh = 353,
     tRelocateMesh = 354,
     tPlane = 355,
     tRuled = 356,
     tTransfinite = 357,
     tComplex = 358,
     tPhysical = 359,
     tCompound = 360,
     tPeriodic = 361,
     tUsing = 362,
     tPlugin = 363,
     tDegenerated = 364,
     tRecursive = 365,
     tRotate = 366,
     tTranslate = 367,
     tSymmetry = 368,
     tDilate = 369,
     tExtrude = 370,
     tLevelset = 371,
     tAffine = 372,
     tRecombine = 373,
     tSmoother = 374,
     tSplit = 375,
     tDelete = 376,
     tCoherence = 377,
     tIntersect = 378,
     tMeshAlgorithm = 379,
     tReverse = 380,
     tLayers = 381,
     tScaleLast = 382,
     tHole = 383,
     tAlias = 384,
     tAliasWithOptions = 385,
     tCopyOptions = 386,
     tQuadTriAddVerts = 387,
     tQuadTriNoNewVerts = 388,
     tQuadTriSngl = 389,
     tQuadTriDbl = 390,
     tRecombLaterals = 391,
     tTransfQuadTri = 392,
     tText2D = 393,
     tText3D = 394,
     tInterpolationScheme = 395,
     tTime = 396,
     tCombine = 397,
     tBSpline = 398,
     tBezier = 399,
     tNurbs = 400,
     tNurbsOrder = 401,
     tNurbsKnots = 402,
     tColor = 403,
     tColorTable = 404,
     tFor = 405,
     tIn = 406,
     tEndFor = 407,
     tIf = 408,
     tElseIf = 409,
     tElse = 410,
     tEndIf = 411,
     tExit = 412,
     tAbort = 413,
     tField = 414,
     tReturn = 415,
     tCall = 416,
     tSlide = 417,
     tMacro = 418,
     tShow = 419,
     tHide = 420,
     tGetValue = 421,
     tGetStringValue = 422,
     tGetEnv = 423,
     tGetString = 424,
     tGetNumber = 425,
     tHomology = 426,
     tCohomology = 427,
     tBetti = 428,
     tExists = 429,
     tFileExists = 430,
     tGMSH_MAJOR_VERSION = 431,
     tGMSH_MINOR_VERSION = 432,
     tGMSH_PATCH_VERSION = 433,
     tGmshExecutableName = 434,
     tSetPartition = 435,
     tNameToString = 436,
     tStringToName = 437,
     tAFFECTDIVIDE = 438,
     tAFFECTTIMES = 439,
     tAFFECTMINUS = 440,
     tAFFECTPLUS = 441,
     tOR = 442,
     tAND = 443,
     tNOTEQUAL = 444,
     tEQUAL = 445,
     tGREATEROREQUAL = 446,
     tLESSOREQUAL = 447,
     UNARYPREC = 448,
     tMINUSMINUS = 449,
     tPLUSPLUS = 450
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
#define tLinSpace 293
#define tLogSpace 294
#define tListFromFile 295
#define tCatenary 296
#define tPrintf 297
#define tError 298
#define tStr 299
#define tSprintf 300
#define tStrCat 301
#define tStrPrefix 302
#define tStrRelative 303
#define tStrReplace 304
#define tAbsolutePath 305
#define tDirName 306
#define tStrSub 307
#define tStrLen 308
#define tFind 309
#define tStrFind 310
#define tStrCmp 311
#define tStrChoice 312
#define tUpperCase 313
#define tLowerCase 314
#define tLowerCaseIn 315
#define tTextAttributes 316
#define tBoundingBox 317
#define tDraw 318
#define tSetChanged 319
#define tToday 320
#define tFixRelativePath 321
#define tCurrentDirectory 322
#define tSyncModel 323
#define tNewModel 324
#define tOnelabAction 325
#define tOnelabRun 326
#define tCpu 327
#define tMemory 328
#define tTotalMemory 329
#define tCreateTopology 330
#define tCreateTopologyNoHoles 331
#define tDistanceFunction 332
#define tDefineConstant 333
#define tUndefineConstant 334
#define tDefineNumber 335
#define tDefineString 336
#define tSetNumber 337
#define tSetString 338
#define tPoint 339
#define tCircle 340
#define tEllipse 341
#define tLine 342
#define tSphere 343
#define tPolarSphere 344
#define tSurface 345
#define tSpline 346
#define tVolume 347
#define tCharacteristic 348
#define tLength 349
#define tParametric 350
#define tElliptic 351
#define tRefineMesh 352
#define tAdaptMesh 353
#define tRelocateMesh 354
#define tPlane 355
#define tRuled 356
#define tTransfinite 357
#define tComplex 358
#define tPhysical 359
#define tCompound 360
#define tPeriodic 361
#define tUsing 362
#define tPlugin 363
#define tDegenerated 364
#define tRecursive 365
#define tRotate 366
#define tTranslate 367
#define tSymmetry 368
#define tDilate 369
#define tExtrude 370
#define tLevelset 371
#define tAffine 372
#define tRecombine 373
#define tSmoother 374
#define tSplit 375
#define tDelete 376
#define tCoherence 377
#define tIntersect 378
#define tMeshAlgorithm 379
#define tReverse 380
#define tLayers 381
#define tScaleLast 382
#define tHole 383
#define tAlias 384
#define tAliasWithOptions 385
#define tCopyOptions 386
#define tQuadTriAddVerts 387
#define tQuadTriNoNewVerts 388
#define tQuadTriSngl 389
#define tQuadTriDbl 390
#define tRecombLaterals 391
#define tTransfQuadTri 392
#define tText2D 393
#define tText3D 394
#define tInterpolationScheme 395
#define tTime 396
#define tCombine 397
#define tBSpline 398
#define tBezier 399
#define tNurbs 400
#define tNurbsOrder 401
#define tNurbsKnots 402
#define tColor 403
#define tColorTable 404
#define tFor 405
#define tIn 406
#define tEndFor 407
#define tIf 408
#define tElseIf 409
#define tElse 410
#define tEndIf 411
#define tExit 412
#define tAbort 413
#define tField 414
#define tReturn 415
#define tCall 416
#define tSlide 417
#define tMacro 418
#define tShow 419
#define tHide 420
#define tGetValue 421
#define tGetStringValue 422
#define tGetEnv 423
#define tGetString 424
#define tGetNumber 425
#define tHomology 426
#define tCohomology 427
#define tBetti 428
#define tExists 429
#define tFileExists 430
#define tGMSH_MAJOR_VERSION 431
#define tGMSH_MINOR_VERSION 432
#define tGMSH_PATCH_VERSION 433
#define tGmshExecutableName 434
#define tSetPartition 435
#define tNameToString 436
#define tStringToName 437
#define tAFFECTDIVIDE 438
#define tAFFECTTIMES 439
#define tAFFECTMINUS 440
#define tAFFECTPLUS 441
#define tOR 442
#define tAND 443
#define tNOTEQUAL 444
#define tEQUAL 445
#define tGREATEROREQUAL 446
#define tLESSOREQUAL 447
#define UNARYPREC 448
#define tMINUSMINUS 449
#define tPLUSPLUS 450




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 115 "Gmsh.y"
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
#line 449 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

