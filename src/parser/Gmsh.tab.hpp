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
     tCharacteristic = 378,
     tLength = 379,
     tParametric = 380,
     tElliptic = 381,
     tRefineMesh = 382,
     tRecombineMesh = 383,
     tAdaptMesh = 384,
     tTransformMesh = 385,
     tRelocateMesh = 386,
     tReorientMesh = 387,
     tSetFactory = 388,
     tThruSections = 389,
     tWedge = 390,
     tFillet = 391,
     tChamfer = 392,
     tPlane = 393,
     tRuled = 394,
     tTransfinite = 395,
     tPhysical = 396,
     tCompound = 397,
     tPeriodic = 398,
     tParent = 399,
     tUsing = 400,
     tPlugin = 401,
     tDegenerated = 402,
     tRecursive = 403,
     tSewing = 404,
     tRotate = 405,
     tTranslate = 406,
     tSymmetry = 407,
     tDilate = 408,
     tExtrude = 409,
     tLevelset = 410,
     tAffine = 411,
     tBooleanUnion = 412,
     tBooleanIntersection = 413,
     tBooleanDifference = 414,
     tBooleanSection = 415,
     tBooleanFragments = 416,
     tThickSolid = 417,
     tRecombine = 418,
     tSmoother = 419,
     tSplit = 420,
     tDelete = 421,
     tCoherence = 422,
     tHealShapes = 423,
     tIntersect = 424,
     tMeshAlgorithm = 425,
     tReverseMesh = 426,
     tMeshSize = 427,
     tMeshSizeFromBoundary = 428,
     tLayers = 429,
     tScaleLast = 430,
     tHole = 431,
     tAlias = 432,
     tAliasWithOptions = 433,
     tCopyOptions = 434,
     tQuadTriAddVerts = 435,
     tQuadTriNoNewVerts = 436,
     tRecombLaterals = 437,
     tTransfQuadTri = 438,
     tText2D = 439,
     tText3D = 440,
     tInterpolationScheme = 441,
     tTime = 442,
     tCombine = 443,
     tBSpline = 444,
     tBezier = 445,
     tNurbs = 446,
     tNurbsOrder = 447,
     tNurbsKnots = 448,
     tColor = 449,
     tColorTable = 450,
     tFor = 451,
     tIn = 452,
     tEndFor = 453,
     tIf = 454,
     tElseIf = 455,
     tElse = 456,
     tEndIf = 457,
     tExit = 458,
     tAbort = 459,
     tField = 460,
     tReturn = 461,
     tCall = 462,
     tSlide = 463,
     tMacro = 464,
     tShow = 465,
     tHide = 466,
     tGetValue = 467,
     tGetStringValue = 468,
     tGetEnv = 469,
     tGetString = 470,
     tGetNumber = 471,
     tUnique = 472,
     tSetMaxTag = 473,
     tHomology = 474,
     tCohomology = 475,
     tBetti = 476,
     tExists = 477,
     tFileExists = 478,
     tGetForced = 479,
     tGetForcedStr = 480,
     tGMSH_MAJOR_VERSION = 481,
     tGMSH_MINOR_VERSION = 482,
     tGMSH_PATCH_VERSION = 483,
     tGmshExecutableName = 484,
     tSetPartition = 485,
     tNameToString = 486,
     tStringToName = 487,
     tUnsplitWindow = 488,
     tAFFECTDIVIDE = 489,
     tAFFECTTIMES = 490,
     tAFFECTMINUS = 491,
     tAFFECTPLUS = 492,
     tOR = 493,
     tAND = 494,
     tNOTEQUAL = 495,
     tEQUAL = 496,
     tGREATERGREATER = 497,
     tLESSLESS = 498,
     tGREATEROREQUAL = 499,
     tLESSOREQUAL = 500,
     UNARYPREC = 501,
     tMINUSMINUS = 502,
     tPLUSPLUS = 503
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
#define tCharacteristic 378
#define tLength 379
#define tParametric 380
#define tElliptic 381
#define tRefineMesh 382
#define tRecombineMesh 383
#define tAdaptMesh 384
#define tTransformMesh 385
#define tRelocateMesh 386
#define tReorientMesh 387
#define tSetFactory 388
#define tThruSections 389
#define tWedge 390
#define tFillet 391
#define tChamfer 392
#define tPlane 393
#define tRuled 394
#define tTransfinite 395
#define tPhysical 396
#define tCompound 397
#define tPeriodic 398
#define tParent 399
#define tUsing 400
#define tPlugin 401
#define tDegenerated 402
#define tRecursive 403
#define tSewing 404
#define tRotate 405
#define tTranslate 406
#define tSymmetry 407
#define tDilate 408
#define tExtrude 409
#define tLevelset 410
#define tAffine 411
#define tBooleanUnion 412
#define tBooleanIntersection 413
#define tBooleanDifference 414
#define tBooleanSection 415
#define tBooleanFragments 416
#define tThickSolid 417
#define tRecombine 418
#define tSmoother 419
#define tSplit 420
#define tDelete 421
#define tCoherence 422
#define tHealShapes 423
#define tIntersect 424
#define tMeshAlgorithm 425
#define tReverseMesh 426
#define tMeshSize 427
#define tMeshSizeFromBoundary 428
#define tLayers 429
#define tScaleLast 430
#define tHole 431
#define tAlias 432
#define tAliasWithOptions 433
#define tCopyOptions 434
#define tQuadTriAddVerts 435
#define tQuadTriNoNewVerts 436
#define tRecombLaterals 437
#define tTransfQuadTri 438
#define tText2D 439
#define tText3D 440
#define tInterpolationScheme 441
#define tTime 442
#define tCombine 443
#define tBSpline 444
#define tBezier 445
#define tNurbs 446
#define tNurbsOrder 447
#define tNurbsKnots 448
#define tColor 449
#define tColorTable 450
#define tFor 451
#define tIn 452
#define tEndFor 453
#define tIf 454
#define tElseIf 455
#define tElse 456
#define tEndIf 457
#define tExit 458
#define tAbort 459
#define tField 460
#define tReturn 461
#define tCall 462
#define tSlide 463
#define tMacro 464
#define tShow 465
#define tHide 466
#define tGetValue 467
#define tGetStringValue 468
#define tGetEnv 469
#define tGetString 470
#define tGetNumber 471
#define tUnique 472
#define tSetMaxTag 473
#define tHomology 474
#define tCohomology 475
#define tBetti 476
#define tExists 477
#define tFileExists 478
#define tGetForced 479
#define tGetForcedStr 480
#define tGMSH_MAJOR_VERSION 481
#define tGMSH_MINOR_VERSION 482
#define tGMSH_PATCH_VERSION 483
#define tGmshExecutableName 484
#define tSetPartition 485
#define tNameToString 486
#define tStringToName 487
#define tUnsplitWindow 488
#define tAFFECTDIVIDE 489
#define tAFFECTTIMES 490
#define tAFFECTMINUS 491
#define tAFFECTPLUS 492
#define tOR 493
#define tAND 494
#define tNOTEQUAL 495
#define tEQUAL 496
#define tGREATERGREATER 497
#define tLESSLESS 498
#define tGREATEROREQUAL 499
#define tLESSOREQUAL 500
#define UNARYPREC 501
#define tMINUSMINUS 502
#define tPLUSPLUS 503




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
#line 556 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

