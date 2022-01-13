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
     tMatrixOfInertia = 333,
     tOnelabAction = 334,
     tOnelabRun = 335,
     tCodeName = 336,
     tCpu = 337,
     tMemory = 338,
     tTotalMemory = 339,
     tCreateTopology = 340,
     tCreateGeometry = 341,
     tClassifySurfaces = 342,
     tRenumberMeshNodes = 343,
     tRenumberMeshElements = 344,
     tDistanceFunction = 345,
     tDefineConstant = 346,
     tUndefineConstant = 347,
     tDefineNumber = 348,
     tDefineStruct = 349,
     tNameStruct = 350,
     tDimNameSpace = 351,
     tAppend = 352,
     tDefineString = 353,
     tSetNumber = 354,
     tSetTag = 355,
     tSetString = 356,
     tPoint = 357,
     tCircle = 358,
     tEllipse = 359,
     tCurve = 360,
     tSphere = 361,
     tPolarSphere = 362,
     tSurface = 363,
     tSpline = 364,
     tVolume = 365,
     tBox = 366,
     tCylinder = 367,
     tCone = 368,
     tTorus = 369,
     tEllipsoid = 370,
     tQuadric = 371,
     tShapeFromFile = 372,
     tRectangle = 373,
     tDisk = 374,
     tWire = 375,
     tGeoEntity = 376,
     tCharacteristic = 377,
     tLength = 378,
     tParametric = 379,
     tElliptic = 380,
     tRefineMesh = 381,
     tRecombineMesh = 382,
     tAdaptMesh = 383,
     tTransformMesh = 384,
     tRelocateMesh = 385,
     tReorientMesh = 386,
     tSetFactory = 387,
     tThruSections = 388,
     tWedge = 389,
     tFillet = 390,
     tChamfer = 391,
     tPlane = 392,
     tRuled = 393,
     tTransfinite = 394,
     tPhysical = 395,
     tCompound = 396,
     tPeriodic = 397,
     tParent = 398,
     tUsing = 399,
     tPlugin = 400,
     tDegenerated = 401,
     tRecursive = 402,
     tSewing = 403,
     tRotate = 404,
     tTranslate = 405,
     tSymmetry = 406,
     tDilate = 407,
     tExtrude = 408,
     tLevelset = 409,
     tAffine = 410,
     tBooleanUnion = 411,
     tBooleanIntersection = 412,
     tBooleanDifference = 413,
     tBooleanSection = 414,
     tBooleanFragments = 415,
     tThickSolid = 416,
     tRecombine = 417,
     tSmoother = 418,
     tSplit = 419,
     tDelete = 420,
     tCoherence = 421,
     tIntersect = 422,
     tMeshAlgorithm = 423,
     tReverseMesh = 424,
     tMeshSize = 425,
     tMeshSizeFromBoundary = 426,
     tLayers = 427,
     tScaleLast = 428,
     tHole = 429,
     tAlias = 430,
     tAliasWithOptions = 431,
     tCopyOptions = 432,
     tQuadTriAddVerts = 433,
     tQuadTriNoNewVerts = 434,
     tRecombLaterals = 435,
     tTransfQuadTri = 436,
     tText2D = 437,
     tText3D = 438,
     tInterpolationScheme = 439,
     tTime = 440,
     tCombine = 441,
     tBSpline = 442,
     tBezier = 443,
     tNurbs = 444,
     tNurbsOrder = 445,
     tNurbsKnots = 446,
     tColor = 447,
     tColorTable = 448,
     tFor = 449,
     tIn = 450,
     tEndFor = 451,
     tIf = 452,
     tElseIf = 453,
     tElse = 454,
     tEndIf = 455,
     tExit = 456,
     tAbort = 457,
     tField = 458,
     tReturn = 459,
     tCall = 460,
     tSlide = 461,
     tMacro = 462,
     tShow = 463,
     tHide = 464,
     tGetValue = 465,
     tGetStringValue = 466,
     tGetEnv = 467,
     tGetString = 468,
     tGetNumber = 469,
     tUnique = 470,
     tSetMaxTag = 471,
     tHomology = 472,
     tCohomology = 473,
     tBetti = 474,
     tExists = 475,
     tFileExists = 476,
     tGetForced = 477,
     tGetForcedStr = 478,
     tGMSH_MAJOR_VERSION = 479,
     tGMSH_MINOR_VERSION = 480,
     tGMSH_PATCH_VERSION = 481,
     tGmshExecutableName = 482,
     tSetPartition = 483,
     tNameToString = 484,
     tStringToName = 485,
     tUnsplitWindow = 486,
     tAFFECTDIVIDE = 487,
     tAFFECTTIMES = 488,
     tAFFECTMINUS = 489,
     tAFFECTPLUS = 490,
     tOR = 491,
     tAND = 492,
     tNOTEQUAL = 493,
     tEQUAL = 494,
     tGREATERGREATER = 495,
     tLESSLESS = 496,
     tGREATEROREQUAL = 497,
     tLESSOREQUAL = 498,
     UNARYPREC = 499,
     tMINUSMINUS = 500,
     tPLUSPLUS = 501
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
#define tMatrixOfInertia 333
#define tOnelabAction 334
#define tOnelabRun 335
#define tCodeName 336
#define tCpu 337
#define tMemory 338
#define tTotalMemory 339
#define tCreateTopology 340
#define tCreateGeometry 341
#define tClassifySurfaces 342
#define tRenumberMeshNodes 343
#define tRenumberMeshElements 344
#define tDistanceFunction 345
#define tDefineConstant 346
#define tUndefineConstant 347
#define tDefineNumber 348
#define tDefineStruct 349
#define tNameStruct 350
#define tDimNameSpace 351
#define tAppend 352
#define tDefineString 353
#define tSetNumber 354
#define tSetTag 355
#define tSetString 356
#define tPoint 357
#define tCircle 358
#define tEllipse 359
#define tCurve 360
#define tSphere 361
#define tPolarSphere 362
#define tSurface 363
#define tSpline 364
#define tVolume 365
#define tBox 366
#define tCylinder 367
#define tCone 368
#define tTorus 369
#define tEllipsoid 370
#define tQuadric 371
#define tShapeFromFile 372
#define tRectangle 373
#define tDisk 374
#define tWire 375
#define tGeoEntity 376
#define tCharacteristic 377
#define tLength 378
#define tParametric 379
#define tElliptic 380
#define tRefineMesh 381
#define tRecombineMesh 382
#define tAdaptMesh 383
#define tTransformMesh 384
#define tRelocateMesh 385
#define tReorientMesh 386
#define tSetFactory 387
#define tThruSections 388
#define tWedge 389
#define tFillet 390
#define tChamfer 391
#define tPlane 392
#define tRuled 393
#define tTransfinite 394
#define tPhysical 395
#define tCompound 396
#define tPeriodic 397
#define tParent 398
#define tUsing 399
#define tPlugin 400
#define tDegenerated 401
#define tRecursive 402
#define tSewing 403
#define tRotate 404
#define tTranslate 405
#define tSymmetry 406
#define tDilate 407
#define tExtrude 408
#define tLevelset 409
#define tAffine 410
#define tBooleanUnion 411
#define tBooleanIntersection 412
#define tBooleanDifference 413
#define tBooleanSection 414
#define tBooleanFragments 415
#define tThickSolid 416
#define tRecombine 417
#define tSmoother 418
#define tSplit 419
#define tDelete 420
#define tCoherence 421
#define tIntersect 422
#define tMeshAlgorithm 423
#define tReverseMesh 424
#define tMeshSize 425
#define tMeshSizeFromBoundary 426
#define tLayers 427
#define tScaleLast 428
#define tHole 429
#define tAlias 430
#define tAliasWithOptions 431
#define tCopyOptions 432
#define tQuadTriAddVerts 433
#define tQuadTriNoNewVerts 434
#define tRecombLaterals 435
#define tTransfQuadTri 436
#define tText2D 437
#define tText3D 438
#define tInterpolationScheme 439
#define tTime 440
#define tCombine 441
#define tBSpline 442
#define tBezier 443
#define tNurbs 444
#define tNurbsOrder 445
#define tNurbsKnots 446
#define tColor 447
#define tColorTable 448
#define tFor 449
#define tIn 450
#define tEndFor 451
#define tIf 452
#define tElseIf 453
#define tElse 454
#define tEndIf 455
#define tExit 456
#define tAbort 457
#define tField 458
#define tReturn 459
#define tCall 460
#define tSlide 461
#define tMacro 462
#define tShow 463
#define tHide 464
#define tGetValue 465
#define tGetStringValue 466
#define tGetEnv 467
#define tGetString 468
#define tGetNumber 469
#define tUnique 470
#define tSetMaxTag 471
#define tHomology 472
#define tCohomology 473
#define tBetti 474
#define tExists 475
#define tFileExists 476
#define tGetForced 477
#define tGetForcedStr 478
#define tGMSH_MAJOR_VERSION 479
#define tGMSH_MINOR_VERSION 480
#define tGMSH_PATCH_VERSION 481
#define tGmshExecutableName 482
#define tSetPartition 483
#define tNameToString 484
#define tStringToName 485
#define tUnsplitWindow 486
#define tAFFECTDIVIDE 487
#define tAFFECTTIMES 488
#define tAFFECTMINUS 489
#define tAFFECTPLUS 490
#define tOR 491
#define tAND 492
#define tNOTEQUAL 493
#define tEQUAL 494
#define tGREATERGREATER 495
#define tLESSLESS 496
#define tGREATEROREQUAL 497
#define tLESSOREQUAL 498
#define UNARYPREC 499
#define tMINUSMINUS 500
#define tPLUSPLUS 501




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
#line 552 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

