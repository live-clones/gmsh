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
     tStep = 281,
     tAtan = 282,
     tAtan2 = 283,
     tSinh = 284,
     tCosh = 285,
     tTanh = 286,
     tFabs = 287,
     tAbs = 288,
     tFloor = 289,
     tCeil = 290,
     tRound = 291,
     tMin = 292,
     tMax = 293,
     tFmod = 294,
     tModulo = 295,
     tHypot = 296,
     tList = 297,
     tLinSpace = 298,
     tLogSpace = 299,
     tListFromFile = 300,
     tCatenary = 301,
     tPrintf = 302,
     tError = 303,
     tWarning = 304,
     tStr = 305,
     tSprintf = 306,
     tStrCat = 307,
     tStrPrefix = 308,
     tStrRelative = 309,
     tStrReplace = 310,
     tAbsolutePath = 311,
     tDirName = 312,
     tStrSub = 313,
     tStrLen = 314,
     tFind = 315,
     tStrFind = 316,
     tStrCmp = 317,
     tStrChoice = 318,
     tUpperCase = 319,
     tLowerCase = 320,
     tLowerCaseIn = 321,
     tTextAttributes = 322,
     tBoundingBox = 323,
     tDraw = 324,
     tSetChanged = 325,
     tToday = 326,
     tFixRelativePath = 327,
     tCurrentDirectory = 328,
     tCurrentFileName = 329,
     tSyncModel = 330,
     tNewModel = 331,
     tMass = 332,
     tCenterOfMass = 333,
     tMatrixOfInertia = 334,
     tOnelabAction = 335,
     tOnelabRun = 336,
     tCodeName = 337,
     tCpu = 338,
     tMemory = 339,
     tTotalMemory = 340,
     tCreateTopology = 341,
     tCreateGeometry = 342,
     tClassifySurfaces = 343,
     tRenumberMeshNodes = 344,
     tRenumberMeshElements = 345,
     tDistanceFunction = 346,
     tDefineConstant = 347,
     tUndefineConstant = 348,
     tDefineNumber = 349,
     tDefineStruct = 350,
     tNameStruct = 351,
     tDimNameSpace = 352,
     tAppend = 353,
     tDefineString = 354,
     tSetNumber = 355,
     tSetTag = 356,
     tSetString = 357,
     tPoint = 358,
     tCircle = 359,
     tEllipse = 360,
     tCurve = 361,
     tSphere = 362,
     tPolarSphere = 363,
     tSurface = 364,
     tSpline = 365,
     tVolume = 366,
     tBox = 367,
     tCylinder = 368,
     tCone = 369,
     tTorus = 370,
     tEllipsoid = 371,
     tQuadric = 372,
     tShapeFromFile = 373,
     tRectangle = 374,
     tDisk = 375,
     tWire = 376,
     tGeoEntity = 377,
     tNormal = 378,
     tCharacteristic = 379,
     tLength = 380,
     tParametric = 381,
     tElliptic = 382,
     tRefineMesh = 383,
     tRecombineMesh = 384,
     tAdaptMesh = 385,
     tTransformMesh = 386,
     tRelocateMesh = 387,
     tReorientMesh = 388,
     tSetFactory = 389,
     tThruSections = 390,
     tWedge = 391,
     tFillet = 392,
     tChamfer = 393,
     tPlane = 394,
     tRuled = 395,
     tTransfinite = 396,
     tPhysical = 397,
     tCompound = 398,
     tPeriodic = 399,
     tParent = 400,
     tUsing = 401,
     tPlugin = 402,
     tDegenerated = 403,
     tRecursive = 404,
     tSewing = 405,
     tRotate = 406,
     tTranslate = 407,
     tSymmetry = 408,
     tDilate = 409,
     tExtrude = 410,
     tLevelset = 411,
     tAffine = 412,
     tClosest = 413,
     tBooleanUnion = 414,
     tBooleanIntersection = 415,
     tBooleanDifference = 416,
     tBooleanSection = 417,
     tBooleanFragments = 418,
     tThickSolid = 419,
     tRecombine = 420,
     tSmoother = 421,
     tSplit = 422,
     tDelete = 423,
     tCoherence = 424,
     tHealShapes = 425,
     tIntersect = 426,
     tMeshAlgorithm = 427,
     tReverseMesh = 428,
     tMeshSize = 429,
     tMeshSizeFromBoundary = 430,
     tLayers = 431,
     tScaleLast = 432,
     tHole = 433,
     tAlias = 434,
     tAliasWithOptions = 435,
     tCopyOptions = 436,
     tQuadTriAddVerts = 437,
     tQuadTriNoNewVerts = 438,
     tRecombLaterals = 439,
     tTransfQuadTri = 440,
     tText2D = 441,
     tText3D = 442,
     tInterpolationScheme = 443,
     tTime = 444,
     tCombine = 445,
     tBSpline = 446,
     tBezier = 447,
     tNurbs = 448,
     tNurbsOrder = 449,
     tNurbsKnots = 450,
     tColor = 451,
     tColorTable = 452,
     tFor = 453,
     tIn = 454,
     tEndFor = 455,
     tIf = 456,
     tElseIf = 457,
     tElse = 458,
     tEndIf = 459,
     tExit = 460,
     tAbort = 461,
     tField = 462,
     tReturn = 463,
     tCall = 464,
     tSlide = 465,
     tMacro = 466,
     tShow = 467,
     tHide = 468,
     tGetValue = 469,
     tGetStringValue = 470,
     tGetEnv = 471,
     tGetString = 472,
     tGetNumber = 473,
     tUnique = 474,
     tSetMaxTag = 475,
     tHomology = 476,
     tCohomology = 477,
     tBetti = 478,
     tExists = 479,
     tFileExists = 480,
     tGetForced = 481,
     tGetForcedStr = 482,
     tGMSH_MAJOR_VERSION = 483,
     tGMSH_MINOR_VERSION = 484,
     tGMSH_PATCH_VERSION = 485,
     tGmshExecutableName = 486,
     tSetPartition = 487,
     tNameToString = 488,
     tStringToName = 489,
     tUnsplitWindow = 490,
     tAFFECTDIVIDE = 491,
     tAFFECTTIMES = 492,
     tAFFECTMINUS = 493,
     tAFFECTPLUS = 494,
     tOR = 495,
     tAND = 496,
     tNOTEQUAL = 497,
     tEQUAL = 498,
     tGREATERGREATER = 499,
     tLESSLESS = 500,
     tGREATEROREQUAL = 501,
     tLESSOREQUAL = 502,
     UNARYPREC = 503,
     tMINUSMINUS = 504,
     tPLUSPLUS = 505
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
#define tStep 281
#define tAtan 282
#define tAtan2 283
#define tSinh 284
#define tCosh 285
#define tTanh 286
#define tFabs 287
#define tAbs 288
#define tFloor 289
#define tCeil 290
#define tRound 291
#define tMin 292
#define tMax 293
#define tFmod 294
#define tModulo 295
#define tHypot 296
#define tList 297
#define tLinSpace 298
#define tLogSpace 299
#define tListFromFile 300
#define tCatenary 301
#define tPrintf 302
#define tError 303
#define tWarning 304
#define tStr 305
#define tSprintf 306
#define tStrCat 307
#define tStrPrefix 308
#define tStrRelative 309
#define tStrReplace 310
#define tAbsolutePath 311
#define tDirName 312
#define tStrSub 313
#define tStrLen 314
#define tFind 315
#define tStrFind 316
#define tStrCmp 317
#define tStrChoice 318
#define tUpperCase 319
#define tLowerCase 320
#define tLowerCaseIn 321
#define tTextAttributes 322
#define tBoundingBox 323
#define tDraw 324
#define tSetChanged 325
#define tToday 326
#define tFixRelativePath 327
#define tCurrentDirectory 328
#define tCurrentFileName 329
#define tSyncModel 330
#define tNewModel 331
#define tMass 332
#define tCenterOfMass 333
#define tMatrixOfInertia 334
#define tOnelabAction 335
#define tOnelabRun 336
#define tCodeName 337
#define tCpu 338
#define tMemory 339
#define tTotalMemory 340
#define tCreateTopology 341
#define tCreateGeometry 342
#define tClassifySurfaces 343
#define tRenumberMeshNodes 344
#define tRenumberMeshElements 345
#define tDistanceFunction 346
#define tDefineConstant 347
#define tUndefineConstant 348
#define tDefineNumber 349
#define tDefineStruct 350
#define tNameStruct 351
#define tDimNameSpace 352
#define tAppend 353
#define tDefineString 354
#define tSetNumber 355
#define tSetTag 356
#define tSetString 357
#define tPoint 358
#define tCircle 359
#define tEllipse 360
#define tCurve 361
#define tSphere 362
#define tPolarSphere 363
#define tSurface 364
#define tSpline 365
#define tVolume 366
#define tBox 367
#define tCylinder 368
#define tCone 369
#define tTorus 370
#define tEllipsoid 371
#define tQuadric 372
#define tShapeFromFile 373
#define tRectangle 374
#define tDisk 375
#define tWire 376
#define tGeoEntity 377
#define tNormal 378
#define tCharacteristic 379
#define tLength 380
#define tParametric 381
#define tElliptic 382
#define tRefineMesh 383
#define tRecombineMesh 384
#define tAdaptMesh 385
#define tTransformMesh 386
#define tRelocateMesh 387
#define tReorientMesh 388
#define tSetFactory 389
#define tThruSections 390
#define tWedge 391
#define tFillet 392
#define tChamfer 393
#define tPlane 394
#define tRuled 395
#define tTransfinite 396
#define tPhysical 397
#define tCompound 398
#define tPeriodic 399
#define tParent 400
#define tUsing 401
#define tPlugin 402
#define tDegenerated 403
#define tRecursive 404
#define tSewing 405
#define tRotate 406
#define tTranslate 407
#define tSymmetry 408
#define tDilate 409
#define tExtrude 410
#define tLevelset 411
#define tAffine 412
#define tClosest 413
#define tBooleanUnion 414
#define tBooleanIntersection 415
#define tBooleanDifference 416
#define tBooleanSection 417
#define tBooleanFragments 418
#define tThickSolid 419
#define tRecombine 420
#define tSmoother 421
#define tSplit 422
#define tDelete 423
#define tCoherence 424
#define tHealShapes 425
#define tIntersect 426
#define tMeshAlgorithm 427
#define tReverseMesh 428
#define tMeshSize 429
#define tMeshSizeFromBoundary 430
#define tLayers 431
#define tScaleLast 432
#define tHole 433
#define tAlias 434
#define tAliasWithOptions 435
#define tCopyOptions 436
#define tQuadTriAddVerts 437
#define tQuadTriNoNewVerts 438
#define tRecombLaterals 439
#define tTransfQuadTri 440
#define tText2D 441
#define tText3D 442
#define tInterpolationScheme 443
#define tTime 444
#define tCombine 445
#define tBSpline 446
#define tBezier 447
#define tNurbs 448
#define tNurbsOrder 449
#define tNurbsKnots 450
#define tColor 451
#define tColorTable 452
#define tFor 453
#define tIn 454
#define tEndFor 455
#define tIf 456
#define tElseIf 457
#define tElse 458
#define tEndIf 459
#define tExit 460
#define tAbort 461
#define tField 462
#define tReturn 463
#define tCall 464
#define tSlide 465
#define tMacro 466
#define tShow 467
#define tHide 468
#define tGetValue 469
#define tGetStringValue 470
#define tGetEnv 471
#define tGetString 472
#define tGetNumber 473
#define tUnique 474
#define tSetMaxTag 475
#define tHomology 476
#define tCohomology 477
#define tBetti 478
#define tExists 479
#define tFileExists 480
#define tGetForced 481
#define tGetForcedStr 482
#define tGMSH_MAJOR_VERSION 483
#define tGMSH_MINOR_VERSION 484
#define tGMSH_PATCH_VERSION 485
#define tGmshExecutableName 486
#define tSetPartition 487
#define tNameToString 488
#define tStringToName 489
#define tUnsplitWindow 490
#define tAFFECTDIVIDE 491
#define tAFFECTTIMES 492
#define tAFFECTMINUS 493
#define tAFFECTPLUS 494
#define tOR 495
#define tAND 496
#define tNOTEQUAL 497
#define tEQUAL 498
#define tGREATERGREATER 499
#define tLESSLESS 500
#define tGREATEROREQUAL 501
#define tLESSOREQUAL 502
#define UNARYPREC 503
#define tMINUSMINUS 504
#define tPLUSPLUS 505




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 169 "Gmsh.y"
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
#line 560 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

