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
     tFmod = 291,
     tModulo = 292,
     tHypot = 293,
     tList = 294,
     tLinSpace = 295,
     tLogSpace = 296,
     tListFromFile = 297,
     tCatenary = 298,
     tPrintf = 299,
     tError = 300,
     tWarning = 301,
     tStr = 302,
     tSprintf = 303,
     tStrCat = 304,
     tStrPrefix = 305,
     tStrRelative = 306,
     tStrReplace = 307,
     tAbsolutePath = 308,
     tDirName = 309,
     tStrSub = 310,
     tStrLen = 311,
     tFind = 312,
     tStrFind = 313,
     tStrCmp = 314,
     tStrChoice = 315,
     tUpperCase = 316,
     tLowerCase = 317,
     tLowerCaseIn = 318,
     tTextAttributes = 319,
     tBoundingBox = 320,
     tDraw = 321,
     tSetChanged = 322,
     tToday = 323,
     tFixRelativePath = 324,
     tCurrentDirectory = 325,
     tCurrentFileName = 326,
     tSyncModel = 327,
     tNewModel = 328,
     tMass = 329,
     tCenterOfMass = 330,
     tOnelabAction = 331,
     tOnelabRun = 332,
     tCodeName = 333,
     tCpu = 334,
     tMemory = 335,
     tTotalMemory = 336,
     tCreateTopology = 337,
     tCreateGeometry = 338,
     tClassifySurfaces = 339,
     tRenumberMeshNodes = 340,
     tRenumberMeshElements = 341,
     tDistanceFunction = 342,
     tDefineConstant = 343,
     tUndefineConstant = 344,
     tDefineNumber = 345,
     tDefineStruct = 346,
     tNameStruct = 347,
     tDimNameSpace = 348,
     tAppend = 349,
     tDefineString = 350,
     tSetNumber = 351,
     tSetTag = 352,
     tSetString = 353,
     tPoint = 354,
     tCircle = 355,
     tEllipse = 356,
     tCurve = 357,
     tSphere = 358,
     tPolarSphere = 359,
     tSurface = 360,
     tSpline = 361,
     tVolume = 362,
     tBox = 363,
     tCylinder = 364,
     tCone = 365,
     tTorus = 366,
     tEllipsoid = 367,
     tQuadric = 368,
     tShapeFromFile = 369,
     tRectangle = 370,
     tDisk = 371,
     tWire = 372,
     tGeoEntity = 373,
     tCharacteristic = 374,
     tLength = 375,
     tParametric = 376,
     tElliptic = 377,
     tRefineMesh = 378,
     tAdaptMesh = 379,
     tRelocateMesh = 380,
     tReorientMesh = 381,
     tSetFactory = 382,
     tThruSections = 383,
     tWedge = 384,
     tFillet = 385,
     tChamfer = 386,
     tPlane = 387,
     tRuled = 388,
     tTransfinite = 389,
     tPhysical = 390,
     tCompound = 391,
     tPeriodic = 392,
     tParent = 393,
     tUsing = 394,
     tPlugin = 395,
     tDegenerated = 396,
     tRecursive = 397,
     tSewing = 398,
     tRotate = 399,
     tTranslate = 400,
     tSymmetry = 401,
     tDilate = 402,
     tExtrude = 403,
     tLevelset = 404,
     tAffine = 405,
     tBooleanUnion = 406,
     tBooleanIntersection = 407,
     tBooleanDifference = 408,
     tBooleanSection = 409,
     tBooleanFragments = 410,
     tThickSolid = 411,
     tRecombine = 412,
     tSmoother = 413,
     tSplit = 414,
     tDelete = 415,
     tCoherence = 416,
     tIntersect = 417,
     tMeshAlgorithm = 418,
     tReverseMesh = 419,
     tMeshSizeFromBoundary = 420,
     tLayers = 421,
     tScaleLast = 422,
     tHole = 423,
     tAlias = 424,
     tAliasWithOptions = 425,
     tCopyOptions = 426,
     tQuadTriAddVerts = 427,
     tQuadTriNoNewVerts = 428,
     tRecombLaterals = 429,
     tTransfQuadTri = 430,
     tText2D = 431,
     tText3D = 432,
     tInterpolationScheme = 433,
     tTime = 434,
     tCombine = 435,
     tBSpline = 436,
     tBezier = 437,
     tNurbs = 438,
     tNurbsOrder = 439,
     tNurbsKnots = 440,
     tColor = 441,
     tColorTable = 442,
     tFor = 443,
     tIn = 444,
     tEndFor = 445,
     tIf = 446,
     tElseIf = 447,
     tElse = 448,
     tEndIf = 449,
     tExit = 450,
     tAbort = 451,
     tField = 452,
     tReturn = 453,
     tCall = 454,
     tSlide = 455,
     tMacro = 456,
     tShow = 457,
     tHide = 458,
     tGetValue = 459,
     tGetStringValue = 460,
     tGetEnv = 461,
     tGetString = 462,
     tGetNumber = 463,
     tUnique = 464,
     tHomology = 465,
     tCohomology = 466,
     tBetti = 467,
     tExists = 468,
     tFileExists = 469,
     tGetForced = 470,
     tGetForcedStr = 471,
     tGMSH_MAJOR_VERSION = 472,
     tGMSH_MINOR_VERSION = 473,
     tGMSH_PATCH_VERSION = 474,
     tGmshExecutableName = 475,
     tSetPartition = 476,
     tNameToString = 477,
     tStringToName = 478,
     tAFFECTDIVIDE = 479,
     tAFFECTTIMES = 480,
     tAFFECTMINUS = 481,
     tAFFECTPLUS = 482,
     tOR = 483,
     tAND = 484,
     tNOTEQUAL = 485,
     tEQUAL = 486,
     tGREATERGREATER = 487,
     tLESSLESS = 488,
     tGREATEROREQUAL = 489,
     tLESSOREQUAL = 490,
     UNARYPREC = 491,
     tMINUSMINUS = 492,
     tPLUSPLUS = 493
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
#define tFmod 291
#define tModulo 292
#define tHypot 293
#define tList 294
#define tLinSpace 295
#define tLogSpace 296
#define tListFromFile 297
#define tCatenary 298
#define tPrintf 299
#define tError 300
#define tWarning 301
#define tStr 302
#define tSprintf 303
#define tStrCat 304
#define tStrPrefix 305
#define tStrRelative 306
#define tStrReplace 307
#define tAbsolutePath 308
#define tDirName 309
#define tStrSub 310
#define tStrLen 311
#define tFind 312
#define tStrFind 313
#define tStrCmp 314
#define tStrChoice 315
#define tUpperCase 316
#define tLowerCase 317
#define tLowerCaseIn 318
#define tTextAttributes 319
#define tBoundingBox 320
#define tDraw 321
#define tSetChanged 322
#define tToday 323
#define tFixRelativePath 324
#define tCurrentDirectory 325
#define tCurrentFileName 326
#define tSyncModel 327
#define tNewModel 328
#define tMass 329
#define tCenterOfMass 330
#define tOnelabAction 331
#define tOnelabRun 332
#define tCodeName 333
#define tCpu 334
#define tMemory 335
#define tTotalMemory 336
#define tCreateTopology 337
#define tCreateGeometry 338
#define tClassifySurfaces 339
#define tRenumberMeshNodes 340
#define tRenumberMeshElements 341
#define tDistanceFunction 342
#define tDefineConstant 343
#define tUndefineConstant 344
#define tDefineNumber 345
#define tDefineStruct 346
#define tNameStruct 347
#define tDimNameSpace 348
#define tAppend 349
#define tDefineString 350
#define tSetNumber 351
#define tSetTag 352
#define tSetString 353
#define tPoint 354
#define tCircle 355
#define tEllipse 356
#define tCurve 357
#define tSphere 358
#define tPolarSphere 359
#define tSurface 360
#define tSpline 361
#define tVolume 362
#define tBox 363
#define tCylinder 364
#define tCone 365
#define tTorus 366
#define tEllipsoid 367
#define tQuadric 368
#define tShapeFromFile 369
#define tRectangle 370
#define tDisk 371
#define tWire 372
#define tGeoEntity 373
#define tCharacteristic 374
#define tLength 375
#define tParametric 376
#define tElliptic 377
#define tRefineMesh 378
#define tAdaptMesh 379
#define tRelocateMesh 380
#define tReorientMesh 381
#define tSetFactory 382
#define tThruSections 383
#define tWedge 384
#define tFillet 385
#define tChamfer 386
#define tPlane 387
#define tRuled 388
#define tTransfinite 389
#define tPhysical 390
#define tCompound 391
#define tPeriodic 392
#define tParent 393
#define tUsing 394
#define tPlugin 395
#define tDegenerated 396
#define tRecursive 397
#define tSewing 398
#define tRotate 399
#define tTranslate 400
#define tSymmetry 401
#define tDilate 402
#define tExtrude 403
#define tLevelset 404
#define tAffine 405
#define tBooleanUnion 406
#define tBooleanIntersection 407
#define tBooleanDifference 408
#define tBooleanSection 409
#define tBooleanFragments 410
#define tThickSolid 411
#define tRecombine 412
#define tSmoother 413
#define tSplit 414
#define tDelete 415
#define tCoherence 416
#define tIntersect 417
#define tMeshAlgorithm 418
#define tReverseMesh 419
#define tMeshSizeFromBoundary 420
#define tLayers 421
#define tScaleLast 422
#define tHole 423
#define tAlias 424
#define tAliasWithOptions 425
#define tCopyOptions 426
#define tQuadTriAddVerts 427
#define tQuadTriNoNewVerts 428
#define tRecombLaterals 429
#define tTransfQuadTri 430
#define tText2D 431
#define tText3D 432
#define tInterpolationScheme 433
#define tTime 434
#define tCombine 435
#define tBSpline 436
#define tBezier 437
#define tNurbs 438
#define tNurbsOrder 439
#define tNurbsKnots 440
#define tColor 441
#define tColorTable 442
#define tFor 443
#define tIn 444
#define tEndFor 445
#define tIf 446
#define tElseIf 447
#define tElse 448
#define tEndIf 449
#define tExit 450
#define tAbort 451
#define tField 452
#define tReturn 453
#define tCall 454
#define tSlide 455
#define tMacro 456
#define tShow 457
#define tHide 458
#define tGetValue 459
#define tGetStringValue 460
#define tGetEnv 461
#define tGetString 462
#define tGetNumber 463
#define tUnique 464
#define tHomology 465
#define tCohomology 466
#define tBetti 467
#define tExists 468
#define tFileExists 469
#define tGetForced 470
#define tGetForcedStr 471
#define tGMSH_MAJOR_VERSION 472
#define tGMSH_MINOR_VERSION 473
#define tGMSH_PATCH_VERSION 474
#define tGmshExecutableName 475
#define tSetPartition 476
#define tNameToString 477
#define tStringToName 478
#define tAFFECTDIVIDE 479
#define tAFFECTTIMES 480
#define tAFFECTMINUS 481
#define tAFFECTPLUS 482
#define tOR 483
#define tAND 484
#define tNOTEQUAL 485
#define tEQUAL 486
#define tGREATERGREATER 487
#define tLESSLESS 488
#define tGREATEROREQUAL 489
#define tLESSOREQUAL 490
#define UNARYPREC 491
#define tMINUSMINUS 492
#define tPLUSPLUS 493




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
#line 536 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

