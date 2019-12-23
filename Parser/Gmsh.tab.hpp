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
     tAdaptMesh = 381,
     tRelocateMesh = 382,
     tReorientMesh = 383,
     tSetFactory = 384,
     tThruSections = 385,
     tWedge = 386,
     tFillet = 387,
     tChamfer = 388,
     tPlane = 389,
     tRuled = 390,
     tTransfinite = 391,
     tPhysical = 392,
     tCompound = 393,
     tPeriodic = 394,
     tParent = 395,
     tUsing = 396,
     tPlugin = 397,
     tDegenerated = 398,
     tRecursive = 399,
     tSewing = 400,
     tRotate = 401,
     tTranslate = 402,
     tSymmetry = 403,
     tDilate = 404,
     tExtrude = 405,
     tLevelset = 406,
     tAffine = 407,
     tBooleanUnion = 408,
     tBooleanIntersection = 409,
     tBooleanDifference = 410,
     tBooleanSection = 411,
     tBooleanFragments = 412,
     tThickSolid = 413,
     tRecombine = 414,
     tSmoother = 415,
     tSplit = 416,
     tDelete = 417,
     tCoherence = 418,
     tIntersect = 419,
     tMeshAlgorithm = 420,
     tReverseMesh = 421,
     tMeshSizeFromBoundary = 422,
     tLayers = 423,
     tScaleLast = 424,
     tHole = 425,
     tAlias = 426,
     tAliasWithOptions = 427,
     tCopyOptions = 428,
     tQuadTriAddVerts = 429,
     tQuadTriNoNewVerts = 430,
     tRecombLaterals = 431,
     tTransfQuadTri = 432,
     tText2D = 433,
     tText3D = 434,
     tInterpolationScheme = 435,
     tTime = 436,
     tCombine = 437,
     tBSpline = 438,
     tBezier = 439,
     tNurbs = 440,
     tNurbsOrder = 441,
     tNurbsKnots = 442,
     tColor = 443,
     tColorTable = 444,
     tFor = 445,
     tIn = 446,
     tEndFor = 447,
     tIf = 448,
     tElseIf = 449,
     tElse = 450,
     tEndIf = 451,
     tExit = 452,
     tAbort = 453,
     tField = 454,
     tReturn = 455,
     tCall = 456,
     tSlide = 457,
     tMacro = 458,
     tShow = 459,
     tHide = 460,
     tGetValue = 461,
     tGetStringValue = 462,
     tGetEnv = 463,
     tGetString = 464,
     tGetNumber = 465,
     tUnique = 466,
     tHomology = 467,
     tCohomology = 468,
     tBetti = 469,
     tExists = 470,
     tFileExists = 471,
     tGetForced = 472,
     tGetForcedStr = 473,
     tGMSH_MAJOR_VERSION = 474,
     tGMSH_MINOR_VERSION = 475,
     tGMSH_PATCH_VERSION = 476,
     tGmshExecutableName = 477,
     tSetPartition = 478,
     tNameToString = 479,
     tStringToName = 480,
     tAFFECTDIVIDE = 481,
     tAFFECTTIMES = 482,
     tAFFECTMINUS = 483,
     tAFFECTPLUS = 484,
     tOR = 485,
     tAND = 486,
     tNOTEQUAL = 487,
     tEQUAL = 488,
     tGREATERGREATER = 489,
     tLESSLESS = 490,
     tGREATEROREQUAL = 491,
     tLESSOREQUAL = 492,
     UNARYPREC = 493,
     tMINUSMINUS = 494,
     tPLUSPLUS = 495
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
#define tAdaptMesh 381
#define tRelocateMesh 382
#define tReorientMesh 383
#define tSetFactory 384
#define tThruSections 385
#define tWedge 386
#define tFillet 387
#define tChamfer 388
#define tPlane 389
#define tRuled 390
#define tTransfinite 391
#define tPhysical 392
#define tCompound 393
#define tPeriodic 394
#define tParent 395
#define tUsing 396
#define tPlugin 397
#define tDegenerated 398
#define tRecursive 399
#define tSewing 400
#define tRotate 401
#define tTranslate 402
#define tSymmetry 403
#define tDilate 404
#define tExtrude 405
#define tLevelset 406
#define tAffine 407
#define tBooleanUnion 408
#define tBooleanIntersection 409
#define tBooleanDifference 410
#define tBooleanSection 411
#define tBooleanFragments 412
#define tThickSolid 413
#define tRecombine 414
#define tSmoother 415
#define tSplit 416
#define tDelete 417
#define tCoherence 418
#define tIntersect 419
#define tMeshAlgorithm 420
#define tReverseMesh 421
#define tMeshSizeFromBoundary 422
#define tLayers 423
#define tScaleLast 424
#define tHole 425
#define tAlias 426
#define tAliasWithOptions 427
#define tCopyOptions 428
#define tQuadTriAddVerts 429
#define tQuadTriNoNewVerts 430
#define tRecombLaterals 431
#define tTransfQuadTri 432
#define tText2D 433
#define tText3D 434
#define tInterpolationScheme 435
#define tTime 436
#define tCombine 437
#define tBSpline 438
#define tBezier 439
#define tNurbs 440
#define tNurbsOrder 441
#define tNurbsKnots 442
#define tColor 443
#define tColorTable 444
#define tFor 445
#define tIn 446
#define tEndFor 447
#define tIf 448
#define tElseIf 449
#define tElse 450
#define tEndIf 451
#define tExit 452
#define tAbort 453
#define tField 454
#define tReturn 455
#define tCall 456
#define tSlide 457
#define tMacro 458
#define tShow 459
#define tHide 460
#define tGetValue 461
#define tGetStringValue 462
#define tGetEnv 463
#define tGetString 464
#define tGetNumber 465
#define tUnique 466
#define tHomology 467
#define tCohomology 468
#define tBetti 469
#define tExists 470
#define tFileExists 471
#define tGetForced 472
#define tGetForcedStr 473
#define tGMSH_MAJOR_VERSION 474
#define tGMSH_MINOR_VERSION 475
#define tGMSH_PATCH_VERSION 476
#define tGmshExecutableName 477
#define tSetPartition 478
#define tNameToString 479
#define tStringToName 480
#define tAFFECTDIVIDE 481
#define tAFFECTTIMES 482
#define tAFFECTMINUS 483
#define tAFFECTPLUS 484
#define tOR 485
#define tAND 486
#define tNOTEQUAL 487
#define tEQUAL 488
#define tGREATERGREATER 489
#define tLESSLESS 490
#define tGREATEROREQUAL 491
#define tLESSOREQUAL 492
#define UNARYPREC 493
#define tMINUSMINUS 494
#define tPLUSPLUS 495




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 166 "Gmsh.y"
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
#line 540 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

