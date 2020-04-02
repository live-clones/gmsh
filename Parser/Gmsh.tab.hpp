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
     tSCOPE = 264,
     tPi = 265,
     tMPI_Rank = 266,
     tMPI_Size = 267,
     tEuclidian = 268,
     tCoordinates = 269,
     tTestLevel = 270,
     tExp = 271,
     tLog = 272,
     tLog10 = 273,
     tSqrt = 274,
     tSin = 275,
     tAsin = 276,
     tCos = 277,
     tAcos = 278,
     tTan = 279,
     tRand = 280,
     tAtan = 281,
     tAtan2 = 282,
     tSinh = 283,
     tCosh = 284,
     tTanh = 285,
     tFabs = 286,
     tAbs = 287,
     tFloor = 288,
     tCeil = 289,
     tRound = 290,
     tMin = 291,
     tMax = 292,
     tFmod = 293,
     tModulo = 294,
     tHypot = 295,
     tList = 296,
     tLinSpace = 297,
     tLogSpace = 298,
     tListFromFile = 299,
     tCatenary = 300,
     tPrintf = 301,
     tError = 302,
     tWarning = 303,
     tStr = 304,
     tSprintf = 305,
     tStrCat = 306,
     tStrPrefix = 307,
     tStrRelative = 308,
     tStrReplace = 309,
     tAbsolutePath = 310,
     tDirName = 311,
     tStrSub = 312,
     tStrLen = 313,
     tFind = 314,
     tStrFind = 315,
     tStrCmp = 316,
     tStrChoice = 317,
     tUpperCase = 318,
     tLowerCase = 319,
     tLowerCaseIn = 320,
     tTextAttributes = 321,
     tBoundingBox = 322,
     tDraw = 323,
     tSetChanged = 324,
     tToday = 325,
     tFixRelativePath = 326,
     tCurrentDirectory = 327,
     tCurrentFileName = 328,
     tSyncModel = 329,
     tNewModel = 330,
     tMass = 331,
     tCenterOfMass = 332,
     tOnelabAction = 333,
     tOnelabRun = 334,
     tCodeName = 335,
     tCpu = 336,
     tMemory = 337,
     tTotalMemory = 338,
     tCreateTopology = 339,
     tCreateGeometry = 340,
     tClassifySurfaces = 341,
     tRenumberMeshNodes = 342,
     tRenumberMeshElements = 343,
     tDistanceFunction = 344,
     tDefineConstant = 345,
     tUndefineConstant = 346,
     tDefineNumber = 347,
     tDefineStruct = 348,
     tNameStruct = 349,
     tDimNameSpace = 350,
     tAppend = 351,
     tDefineString = 352,
     tSetNumber = 353,
     tSetTag = 354,
     tSetString = 355,
     tPoint = 356,
     tCircle = 357,
     tEllipse = 358,
     tCurve = 359,
     tSphere = 360,
     tPolarSphere = 361,
     tSurface = 362,
     tSpline = 363,
     tVolume = 364,
     tBox = 365,
     tCylinder = 366,
     tCone = 367,
     tTorus = 368,
     tEllipsoid = 369,
     tQuadric = 370,
     tShapeFromFile = 371,
     tRectangle = 372,
     tDisk = 373,
     tWire = 374,
     tGeoEntity = 375,
     tCharacteristic = 376,
     tLength = 377,
     tParametric = 378,
     tElliptic = 379,
     tRefineMesh = 380,
     tRecombineMesh = 381,
     tAdaptMesh = 382,
     tRelocateMesh = 383,
     tReorientMesh = 384,
     tSetFactory = 385,
     tThruSections = 386,
     tWedge = 387,
     tFillet = 388,
     tChamfer = 389,
     tPlane = 390,
     tRuled = 391,
     tTransfinite = 392,
     tPhysical = 393,
     tCompound = 394,
     tPeriodic = 395,
     tParent = 396,
     tUsing = 397,
     tPlugin = 398,
     tDegenerated = 399,
     tRecursive = 400,
     tSewing = 401,
     tRotate = 402,
     tTranslate = 403,
     tSymmetry = 404,
     tDilate = 405,
     tExtrude = 406,
     tLevelset = 407,
     tAffine = 408,
     tBooleanUnion = 409,
     tBooleanIntersection = 410,
     tBooleanDifference = 411,
     tBooleanSection = 412,
     tBooleanFragments = 413,
     tThickSolid = 414,
     tRecombine = 415,
     tSmoother = 416,
     tSplit = 417,
     tDelete = 418,
     tCoherence = 419,
     tIntersect = 420,
     tMeshAlgorithm = 421,
     tReverseMesh = 422,
     tMeshSizeFromBoundary = 423,
     tOnlyInitialMesh = 424,
     tLayers = 425,
     tScaleLast = 426,
     tHole = 427,
     tAlias = 428,
     tAliasWithOptions = 429,
     tCopyOptions = 430,
     tQuadTriAddVerts = 431,
     tQuadTriNoNewVerts = 432,
     tRecombLaterals = 433,
     tTransfQuadTri = 434,
     tText2D = 435,
     tText3D = 436,
     tInterpolationScheme = 437,
     tTime = 438,
     tCombine = 439,
     tBSpline = 440,
     tBezier = 441,
     tNurbs = 442,
     tNurbsOrder = 443,
     tNurbsKnots = 444,
     tColor = 445,
     tColorTable = 446,
     tFor = 447,
     tIn = 448,
     tEndFor = 449,
     tIf = 450,
     tElseIf = 451,
     tElse = 452,
     tEndIf = 453,
     tExit = 454,
     tAbort = 455,
     tField = 456,
     tReturn = 457,
     tCall = 458,
     tSlide = 459,
     tMacro = 460,
     tShow = 461,
     tHide = 462,
     tGetValue = 463,
     tGetStringValue = 464,
     tGetEnv = 465,
     tGetString = 466,
     tGetNumber = 467,
     tUnique = 468,
     tHomology = 469,
     tCohomology = 470,
     tBetti = 471,
     tExists = 472,
     tFileExists = 473,
     tGetForced = 474,
     tGetForcedStr = 475,
     tGMSH_MAJOR_VERSION = 476,
     tGMSH_MINOR_VERSION = 477,
     tGMSH_PATCH_VERSION = 478,
     tGmshExecutableName = 479,
     tSetPartition = 480,
     tNameToString = 481,
     tStringToName = 482,
     tAFFECTDIVIDE = 483,
     tAFFECTTIMES = 484,
     tAFFECTMINUS = 485,
     tAFFECTPLUS = 486,
     tOR = 487,
     tAND = 488,
     tNOTEQUAL = 489,
     tEQUAL = 490,
     tGREATERGREATER = 491,
     tLESSLESS = 492,
     tGREATEROREQUAL = 493,
     tLESSOREQUAL = 494,
     UNARYPREC = 495,
     tMINUSMINUS = 496,
     tPLUSPLUS = 497
   };
#endif
/* Tokens.  */
#define tDOUBLE 258
#define tSTRING 259
#define tBIGSTR 260
#define tEND 261
#define tAFFECT 262
#define tDOTS 263
#define tSCOPE 264
#define tPi 265
#define tMPI_Rank 266
#define tMPI_Size 267
#define tEuclidian 268
#define tCoordinates 269
#define tTestLevel 270
#define tExp 271
#define tLog 272
#define tLog10 273
#define tSqrt 274
#define tSin 275
#define tAsin 276
#define tCos 277
#define tAcos 278
#define tTan 279
#define tRand 280
#define tAtan 281
#define tAtan2 282
#define tSinh 283
#define tCosh 284
#define tTanh 285
#define tFabs 286
#define tAbs 287
#define tFloor 288
#define tCeil 289
#define tRound 290
#define tMin 291
#define tMax 292
#define tFmod 293
#define tModulo 294
#define tHypot 295
#define tList 296
#define tLinSpace 297
#define tLogSpace 298
#define tListFromFile 299
#define tCatenary 300
#define tPrintf 301
#define tError 302
#define tWarning 303
#define tStr 304
#define tSprintf 305
#define tStrCat 306
#define tStrPrefix 307
#define tStrRelative 308
#define tStrReplace 309
#define tAbsolutePath 310
#define tDirName 311
#define tStrSub 312
#define tStrLen 313
#define tFind 314
#define tStrFind 315
#define tStrCmp 316
#define tStrChoice 317
#define tUpperCase 318
#define tLowerCase 319
#define tLowerCaseIn 320
#define tTextAttributes 321
#define tBoundingBox 322
#define tDraw 323
#define tSetChanged 324
#define tToday 325
#define tFixRelativePath 326
#define tCurrentDirectory 327
#define tCurrentFileName 328
#define tSyncModel 329
#define tNewModel 330
#define tMass 331
#define tCenterOfMass 332
#define tOnelabAction 333
#define tOnelabRun 334
#define tCodeName 335
#define tCpu 336
#define tMemory 337
#define tTotalMemory 338
#define tCreateTopology 339
#define tCreateGeometry 340
#define tClassifySurfaces 341
#define tRenumberMeshNodes 342
#define tRenumberMeshElements 343
#define tDistanceFunction 344
#define tDefineConstant 345
#define tUndefineConstant 346
#define tDefineNumber 347
#define tDefineStruct 348
#define tNameStruct 349
#define tDimNameSpace 350
#define tAppend 351
#define tDefineString 352
#define tSetNumber 353
#define tSetTag 354
#define tSetString 355
#define tPoint 356
#define tCircle 357
#define tEllipse 358
#define tCurve 359
#define tSphere 360
#define tPolarSphere 361
#define tSurface 362
#define tSpline 363
#define tVolume 364
#define tBox 365
#define tCylinder 366
#define tCone 367
#define tTorus 368
#define tEllipsoid 369
#define tQuadric 370
#define tShapeFromFile 371
#define tRectangle 372
#define tDisk 373
#define tWire 374
#define tGeoEntity 375
#define tCharacteristic 376
#define tLength 377
#define tParametric 378
#define tElliptic 379
#define tRefineMesh 380
#define tRecombineMesh 381
#define tAdaptMesh 382
#define tRelocateMesh 383
#define tReorientMesh 384
#define tSetFactory 385
#define tThruSections 386
#define tWedge 387
#define tFillet 388
#define tChamfer 389
#define tPlane 390
#define tRuled 391
#define tTransfinite 392
#define tPhysical 393
#define tCompound 394
#define tPeriodic 395
#define tParent 396
#define tUsing 397
#define tPlugin 398
#define tDegenerated 399
#define tRecursive 400
#define tSewing 401
#define tRotate 402
#define tTranslate 403
#define tSymmetry 404
#define tDilate 405
#define tExtrude 406
#define tLevelset 407
#define tAffine 408
#define tBooleanUnion 409
#define tBooleanIntersection 410
#define tBooleanDifference 411
#define tBooleanSection 412
#define tBooleanFragments 413
#define tThickSolid 414
#define tRecombine 415
#define tSmoother 416
#define tSplit 417
#define tDelete 418
#define tCoherence 419
#define tIntersect 420
#define tMeshAlgorithm 421
#define tReverseMesh 422
#define tMeshSizeFromBoundary 423
#define tOnlyInitialMesh 424
#define tLayers 425
#define tScaleLast 426
#define tHole 427
#define tAlias 428
#define tAliasWithOptions 429
#define tCopyOptions 430
#define tQuadTriAddVerts 431
#define tQuadTriNoNewVerts 432
#define tRecombLaterals 433
#define tTransfQuadTri 434
#define tText2D 435
#define tText3D 436
#define tInterpolationScheme 437
#define tTime 438
#define tCombine 439
#define tBSpline 440
#define tBezier 441
#define tNurbs 442
#define tNurbsOrder 443
#define tNurbsKnots 444
#define tColor 445
#define tColorTable 446
#define tFor 447
#define tIn 448
#define tEndFor 449
#define tIf 450
#define tElseIf 451
#define tElse 452
#define tEndIf 453
#define tExit 454
#define tAbort 455
#define tField 456
#define tReturn 457
#define tCall 458
#define tSlide 459
#define tMacro 460
#define tShow 461
#define tHide 462
#define tGetValue 463
#define tGetStringValue 464
#define tGetEnv 465
#define tGetString 466
#define tGetNumber 467
#define tUnique 468
#define tHomology 469
#define tCohomology 470
#define tBetti 471
#define tExists 472
#define tFileExists 473
#define tGetForced 474
#define tGetForcedStr 475
#define tGMSH_MAJOR_VERSION 476
#define tGMSH_MINOR_VERSION 477
#define tGMSH_PATCH_VERSION 478
#define tGmshExecutableName 479
#define tSetPartition 480
#define tNameToString 481
#define tStringToName 482
#define tAFFECTDIVIDE 483
#define tAFFECTTIMES 484
#define tAFFECTMINUS 485
#define tAFFECTPLUS 486
#define tOR 487
#define tAND 488
#define tNOTEQUAL 489
#define tEQUAL 490
#define tGREATERGREATER 491
#define tLESSLESS 492
#define tGREATEROREQUAL 493
#define tLESSOREQUAL 494
#define UNARYPREC 495
#define tMINUSMINUS 496
#define tPLUSPLUS 497




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 165 "Gmsh.y"
{
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;
}
/* Line 1529 of yacc.c.  */
#line 544 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

