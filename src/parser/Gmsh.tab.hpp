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
     tBooleanUnion = 413,
     tBooleanIntersection = 414,
     tBooleanDifference = 415,
     tBooleanSection = 416,
     tBooleanFragments = 417,
     tThickSolid = 418,
     tRecombine = 419,
     tSmoother = 420,
     tSplit = 421,
     tDelete = 422,
     tCoherence = 423,
     tHealShapes = 424,
     tIntersect = 425,
     tMeshAlgorithm = 426,
     tReverseMesh = 427,
     tMeshSize = 428,
     tMeshSizeFromBoundary = 429,
     tLayers = 430,
     tScaleLast = 431,
     tHole = 432,
     tAlias = 433,
     tAliasWithOptions = 434,
     tCopyOptions = 435,
     tQuadTriAddVerts = 436,
     tQuadTriNoNewVerts = 437,
     tRecombLaterals = 438,
     tTransfQuadTri = 439,
     tText2D = 440,
     tText3D = 441,
     tInterpolationScheme = 442,
     tTime = 443,
     tCombine = 444,
     tBSpline = 445,
     tBezier = 446,
     tNurbs = 447,
     tNurbsOrder = 448,
     tNurbsKnots = 449,
     tColor = 450,
     tColorTable = 451,
     tFor = 452,
     tIn = 453,
     tEndFor = 454,
     tIf = 455,
     tElseIf = 456,
     tElse = 457,
     tEndIf = 458,
     tExit = 459,
     tAbort = 460,
     tField = 461,
     tReturn = 462,
     tCall = 463,
     tSlide = 464,
     tMacro = 465,
     tShow = 466,
     tHide = 467,
     tGetValue = 468,
     tGetStringValue = 469,
     tGetEnv = 470,
     tGetString = 471,
     tGetNumber = 472,
     tUnique = 473,
     tSetMaxTag = 474,
     tHomology = 475,
     tCohomology = 476,
     tBetti = 477,
     tExists = 478,
     tFileExists = 479,
     tGetForced = 480,
     tGetForcedStr = 481,
     tGMSH_MAJOR_VERSION = 482,
     tGMSH_MINOR_VERSION = 483,
     tGMSH_PATCH_VERSION = 484,
     tGmshExecutableName = 485,
     tSetPartition = 486,
     tNameToString = 487,
     tStringToName = 488,
     tUnsplitWindow = 489,
     tAFFECTDIVIDE = 490,
     tAFFECTTIMES = 491,
     tAFFECTMINUS = 492,
     tAFFECTPLUS = 493,
     tOR = 494,
     tAND = 495,
     tNOTEQUAL = 496,
     tEQUAL = 497,
     tGREATERGREATER = 498,
     tLESSLESS = 499,
     tGREATEROREQUAL = 500,
     tLESSOREQUAL = 501,
     UNARYPREC = 502,
     tMINUSMINUS = 503,
     tPLUSPLUS = 504
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
#define tBooleanUnion 413
#define tBooleanIntersection 414
#define tBooleanDifference 415
#define tBooleanSection 416
#define tBooleanFragments 417
#define tThickSolid 418
#define tRecombine 419
#define tSmoother 420
#define tSplit 421
#define tDelete 422
#define tCoherence 423
#define tHealShapes 424
#define tIntersect 425
#define tMeshAlgorithm 426
#define tReverseMesh 427
#define tMeshSize 428
#define tMeshSizeFromBoundary 429
#define tLayers 430
#define tScaleLast 431
#define tHole 432
#define tAlias 433
#define tAliasWithOptions 434
#define tCopyOptions 435
#define tQuadTriAddVerts 436
#define tQuadTriNoNewVerts 437
#define tRecombLaterals 438
#define tTransfQuadTri 439
#define tText2D 440
#define tText3D 441
#define tInterpolationScheme 442
#define tTime 443
#define tCombine 444
#define tBSpline 445
#define tBezier 446
#define tNurbs 447
#define tNurbsOrder 448
#define tNurbsKnots 449
#define tColor 450
#define tColorTable 451
#define tFor 452
#define tIn 453
#define tEndFor 454
#define tIf 455
#define tElseIf 456
#define tElse 457
#define tEndIf 458
#define tExit 459
#define tAbort 460
#define tField 461
#define tReturn 462
#define tCall 463
#define tSlide 464
#define tMacro 465
#define tShow 466
#define tHide 467
#define tGetValue 468
#define tGetStringValue 469
#define tGetEnv 470
#define tGetString 471
#define tGetNumber 472
#define tUnique 473
#define tSetMaxTag 474
#define tHomology 475
#define tCohomology 476
#define tBetti 477
#define tExists 478
#define tFileExists 479
#define tGetForced 480
#define tGetForcedStr 481
#define tGMSH_MAJOR_VERSION 482
#define tGMSH_MINOR_VERSION 483
#define tGMSH_PATCH_VERSION 484
#define tGmshExecutableName 485
#define tSetPartition 486
#define tNameToString 487
#define tStringToName 488
#define tUnsplitWindow 489
#define tAFFECTDIVIDE 490
#define tAFFECTTIMES 491
#define tAFFECTMINUS 492
#define tAFFECTPLUS 493
#define tOR 494
#define tAND 495
#define tNOTEQUAL 496
#define tEQUAL 497
#define tGREATERGREATER 498
#define tLESSLESS 499
#define tGREATEROREQUAL 500
#define tLESSOREQUAL 501
#define UNARYPREC 502
#define tMINUSMINUS 503
#define tPLUSPLUS 504




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
#line 558 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

