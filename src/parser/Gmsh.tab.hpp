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
     tCurvature = 379,
     tCharacteristic = 380,
     tLength = 381,
     tParametric = 382,
     tElliptic = 383,
     tRefineMesh = 384,
     tRecombineMesh = 385,
     tAdaptMesh = 386,
     tTransformMesh = 387,
     tRelocateMesh = 388,
     tReorientMesh = 389,
     tSetFactory = 390,
     tThruSections = 391,
     tWedge = 392,
     tFillet = 393,
     tChamfer = 394,
     tPlane = 395,
     tRuled = 396,
     tTransfinite = 397,
     tPhysical = 398,
     tCompound = 399,
     tPeriodic = 400,
     tParent = 401,
     tUsing = 402,
     tPlugin = 403,
     tDegenerated = 404,
     tRecursive = 405,
     tSewing = 406,
     tRotate = 407,
     tTranslate = 408,
     tSymmetry = 409,
     tDilate = 410,
     tExtrude = 411,
     tLevelset = 412,
     tAffine = 413,
     tClosest = 414,
     tBooleanUnion = 415,
     tBooleanIntersection = 416,
     tBooleanDifference = 417,
     tBooleanSection = 418,
     tBooleanFragments = 419,
     tThickSolid = 420,
     tRecombine = 421,
     tSmoother = 422,
     tSplit = 423,
     tDelete = 424,
     tCoherence = 425,
     tHealShapes = 426,
     tIntersect = 427,
     tMeshAlgorithm = 428,
     tReverseMesh = 429,
     tMeshSize = 430,
     tMeshSizeFromBoundary = 431,
     tLayers = 432,
     tScaleLast = 433,
     tHole = 434,
     tAlias = 435,
     tAliasWithOptions = 436,
     tCopyOptions = 437,
     tQuadTriAddVerts = 438,
     tQuadTriNoNewVerts = 439,
     tRecombLaterals = 440,
     tTransfQuadTri = 441,
     tText2D = 442,
     tText3D = 443,
     tInterpolationScheme = 444,
     tTime = 445,
     tCombine = 446,
     tBSpline = 447,
     tBezier = 448,
     tNurbs = 449,
     tNurbsOrder = 450,
     tNurbsKnots = 451,
     tColor = 452,
     tColorTable = 453,
     tFor = 454,
     tIn = 455,
     tEndFor = 456,
     tIf = 457,
     tElseIf = 458,
     tElse = 459,
     tEndIf = 460,
     tExit = 461,
     tAbort = 462,
     tField = 463,
     tReturn = 464,
     tCall = 465,
     tSlide = 466,
     tMacro = 467,
     tShow = 468,
     tHide = 469,
     tGetValue = 470,
     tGetStringValue = 471,
     tGetEnv = 472,
     tGetString = 473,
     tGetNumber = 474,
     tUnique = 475,
     tSetMaxTag = 476,
     tHomology = 477,
     tCohomology = 478,
     tBetti = 479,
     tExists = 480,
     tFileExists = 481,
     tGetForced = 482,
     tGetForcedStr = 483,
     tGMSH_MAJOR_VERSION = 484,
     tGMSH_MINOR_VERSION = 485,
     tGMSH_PATCH_VERSION = 486,
     tGmshExecutableName = 487,
     tSetPartition = 488,
     tNameToString = 489,
     tStringToName = 490,
     tUnsplitWindow = 491,
     tAFFECTDIVIDE = 492,
     tAFFECTTIMES = 493,
     tAFFECTMINUS = 494,
     tAFFECTPLUS = 495,
     tOR = 496,
     tAND = 497,
     tNOTEQUAL = 498,
     tEQUAL = 499,
     tGREATERGREATER = 500,
     tLESSLESS = 501,
     tGREATEROREQUAL = 502,
     tLESSOREQUAL = 503,
     UNARYPREC = 504,
     tMINUSMINUS = 505,
     tPLUSPLUS = 506
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
#define tCurvature 379
#define tCharacteristic 380
#define tLength 381
#define tParametric 382
#define tElliptic 383
#define tRefineMesh 384
#define tRecombineMesh 385
#define tAdaptMesh 386
#define tTransformMesh 387
#define tRelocateMesh 388
#define tReorientMesh 389
#define tSetFactory 390
#define tThruSections 391
#define tWedge 392
#define tFillet 393
#define tChamfer 394
#define tPlane 395
#define tRuled 396
#define tTransfinite 397
#define tPhysical 398
#define tCompound 399
#define tPeriodic 400
#define tParent 401
#define tUsing 402
#define tPlugin 403
#define tDegenerated 404
#define tRecursive 405
#define tSewing 406
#define tRotate 407
#define tTranslate 408
#define tSymmetry 409
#define tDilate 410
#define tExtrude 411
#define tLevelset 412
#define tAffine 413
#define tClosest 414
#define tBooleanUnion 415
#define tBooleanIntersection 416
#define tBooleanDifference 417
#define tBooleanSection 418
#define tBooleanFragments 419
#define tThickSolid 420
#define tRecombine 421
#define tSmoother 422
#define tSplit 423
#define tDelete 424
#define tCoherence 425
#define tHealShapes 426
#define tIntersect 427
#define tMeshAlgorithm 428
#define tReverseMesh 429
#define tMeshSize 430
#define tMeshSizeFromBoundary 431
#define tLayers 432
#define tScaleLast 433
#define tHole 434
#define tAlias 435
#define tAliasWithOptions 436
#define tCopyOptions 437
#define tQuadTriAddVerts 438
#define tQuadTriNoNewVerts 439
#define tRecombLaterals 440
#define tTransfQuadTri 441
#define tText2D 442
#define tText3D 443
#define tInterpolationScheme 444
#define tTime 445
#define tCombine 446
#define tBSpline 447
#define tBezier 448
#define tNurbs 449
#define tNurbsOrder 450
#define tNurbsKnots 451
#define tColor 452
#define tColorTable 453
#define tFor 454
#define tIn 455
#define tEndFor 456
#define tIf 457
#define tElseIf 458
#define tElse 459
#define tEndIf 460
#define tExit 461
#define tAbort 462
#define tField 463
#define tReturn 464
#define tCall 465
#define tSlide 466
#define tMacro 467
#define tShow 468
#define tHide 469
#define tGetValue 470
#define tGetStringValue 471
#define tGetEnv 472
#define tGetString 473
#define tGetNumber 474
#define tUnique 475
#define tSetMaxTag 476
#define tHomology 477
#define tCohomology 478
#define tBetti 479
#define tExists 480
#define tFileExists 481
#define tGetForced 482
#define tGetForcedStr 483
#define tGMSH_MAJOR_VERSION 484
#define tGMSH_MINOR_VERSION 485
#define tGMSH_PATCH_VERSION 486
#define tGmshExecutableName 487
#define tSetPartition 488
#define tNameToString 489
#define tStringToName 490
#define tUnsplitWindow 491
#define tAFFECTDIVIDE 492
#define tAFFECTTIMES 493
#define tAFFECTMINUS 494
#define tAFFECTPLUS 495
#define tOR 496
#define tAND 497
#define tNOTEQUAL 498
#define tEQUAL 499
#define tGREATERGREATER 500
#define tLESSLESS 501
#define tGREATEROREQUAL 502
#define tLESSOREQUAL 503
#define UNARYPREC 504
#define tMINUSMINUS 505
#define tPLUSPLUS 506




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
#line 562 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

