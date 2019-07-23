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
     tSyncModel = 326,
     tNewModel = 327,
     tMass = 328,
     tCenterOfMass = 329,
     tOnelabAction = 330,
     tOnelabRun = 331,
     tCodeName = 332,
     tCpu = 333,
     tMemory = 334,
     tTotalMemory = 335,
     tCreateTopology = 336,
     tCreateGeometry = 337,
     tClassifySurfaces = 338,
     tRenumberMeshNodes = 339,
     tRenumberMeshElements = 340,
     tDistanceFunction = 341,
     tDefineConstant = 342,
     tUndefineConstant = 343,
     tDefineNumber = 344,
     tDefineStruct = 345,
     tNameStruct = 346,
     tDimNameSpace = 347,
     tAppend = 348,
     tDefineString = 349,
     tSetNumber = 350,
     tSetTag = 351,
     tSetString = 352,
     tPoint = 353,
     tCircle = 354,
     tEllipse = 355,
     tCurve = 356,
     tSphere = 357,
     tPolarSphere = 358,
     tSurface = 359,
     tSpline = 360,
     tVolume = 361,
     tBox = 362,
     tCylinder = 363,
     tCone = 364,
     tTorus = 365,
     tEllipsoid = 366,
     tQuadric = 367,
     tShapeFromFile = 368,
     tRectangle = 369,
     tDisk = 370,
     tWire = 371,
     tGeoEntity = 372,
     tCharacteristic = 373,
     tLength = 374,
     tParametric = 375,
     tElliptic = 376,
     tRefineMesh = 377,
     tAdaptMesh = 378,
     tRelocateMesh = 379,
     tReorientMesh = 380,
     tSetFactory = 381,
     tThruSections = 382,
     tWedge = 383,
     tFillet = 384,
     tChamfer = 385,
     tPlane = 386,
     tRuled = 387,
     tTransfinite = 388,
     tPhysical = 389,
     tCompound = 390,
     tPeriodic = 391,
     tParent = 392,
     tUsing = 393,
     tPlugin = 394,
     tDegenerated = 395,
     tRecursive = 396,
     tSewing = 397,
     tRotate = 398,
     tTranslate = 399,
     tSymmetry = 400,
     tDilate = 401,
     tExtrude = 402,
     tLevelset = 403,
     tAffine = 404,
     tBooleanUnion = 405,
     tBooleanIntersection = 406,
     tBooleanDifference = 407,
     tBooleanSection = 408,
     tBooleanFragments = 409,
     tThickSolid = 410,
     tRecombine = 411,
     tSmoother = 412,
     tSplit = 413,
     tDelete = 414,
     tCoherence = 415,
     tIntersect = 416,
     tMeshAlgorithm = 417,
     tReverseMesh = 418,
     tLayers = 419,
     tScaleLast = 420,
     tHole = 421,
     tAlias = 422,
     tAliasWithOptions = 423,
     tCopyOptions = 424,
     tQuadTriAddVerts = 425,
     tQuadTriNoNewVerts = 426,
     tRecombLaterals = 427,
     tTransfQuadTri = 428,
     tText2D = 429,
     tText3D = 430,
     tInterpolationScheme = 431,
     tTime = 432,
     tCombine = 433,
     tBSpline = 434,
     tBezier = 435,
     tNurbs = 436,
     tNurbsOrder = 437,
     tNurbsKnots = 438,
     tColor = 439,
     tColorTable = 440,
     tFor = 441,
     tIn = 442,
     tEndFor = 443,
     tIf = 444,
     tElseIf = 445,
     tElse = 446,
     tEndIf = 447,
     tExit = 448,
     tAbort = 449,
     tField = 450,
     tReturn = 451,
     tCall = 452,
     tSlide = 453,
     tMacro = 454,
     tShow = 455,
     tHide = 456,
     tGetValue = 457,
     tGetStringValue = 458,
     tGetEnv = 459,
     tGetString = 460,
     tGetNumber = 461,
     tUnique = 462,
     tHomology = 463,
     tCohomology = 464,
     tBetti = 465,
     tExists = 466,
     tFileExists = 467,
     tGetForced = 468,
     tGetForcedStr = 469,
     tGMSH_MAJOR_VERSION = 470,
     tGMSH_MINOR_VERSION = 471,
     tGMSH_PATCH_VERSION = 472,
     tGmshExecutableName = 473,
     tSetPartition = 474,
     tNameToString = 475,
     tStringToName = 476,
     tAFFECTDIVIDE = 477,
     tAFFECTTIMES = 478,
     tAFFECTMINUS = 479,
     tAFFECTPLUS = 480,
     tOR = 481,
     tAND = 482,
     tNOTEQUAL = 483,
     tEQUAL = 484,
     tGREATERGREATER = 485,
     tLESSLESS = 486,
     tGREATEROREQUAL = 487,
     tLESSOREQUAL = 488,
     UNARYPREC = 489,
     tMINUSMINUS = 490,
     tPLUSPLUS = 491
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
#define tSyncModel 326
#define tNewModel 327
#define tMass 328
#define tCenterOfMass 329
#define tOnelabAction 330
#define tOnelabRun 331
#define tCodeName 332
#define tCpu 333
#define tMemory 334
#define tTotalMemory 335
#define tCreateTopology 336
#define tCreateGeometry 337
#define tClassifySurfaces 338
#define tRenumberMeshNodes 339
#define tRenumberMeshElements 340
#define tDistanceFunction 341
#define tDefineConstant 342
#define tUndefineConstant 343
#define tDefineNumber 344
#define tDefineStruct 345
#define tNameStruct 346
#define tDimNameSpace 347
#define tAppend 348
#define tDefineString 349
#define tSetNumber 350
#define tSetTag 351
#define tSetString 352
#define tPoint 353
#define tCircle 354
#define tEllipse 355
#define tCurve 356
#define tSphere 357
#define tPolarSphere 358
#define tSurface 359
#define tSpline 360
#define tVolume 361
#define tBox 362
#define tCylinder 363
#define tCone 364
#define tTorus 365
#define tEllipsoid 366
#define tQuadric 367
#define tShapeFromFile 368
#define tRectangle 369
#define tDisk 370
#define tWire 371
#define tGeoEntity 372
#define tCharacteristic 373
#define tLength 374
#define tParametric 375
#define tElliptic 376
#define tRefineMesh 377
#define tAdaptMesh 378
#define tRelocateMesh 379
#define tReorientMesh 380
#define tSetFactory 381
#define tThruSections 382
#define tWedge 383
#define tFillet 384
#define tChamfer 385
#define tPlane 386
#define tRuled 387
#define tTransfinite 388
#define tPhysical 389
#define tCompound 390
#define tPeriodic 391
#define tParent 392
#define tUsing 393
#define tPlugin 394
#define tDegenerated 395
#define tRecursive 396
#define tSewing 397
#define tRotate 398
#define tTranslate 399
#define tSymmetry 400
#define tDilate 401
#define tExtrude 402
#define tLevelset 403
#define tAffine 404
#define tBooleanUnion 405
#define tBooleanIntersection 406
#define tBooleanDifference 407
#define tBooleanSection 408
#define tBooleanFragments 409
#define tThickSolid 410
#define tRecombine 411
#define tSmoother 412
#define tSplit 413
#define tDelete 414
#define tCoherence 415
#define tIntersect 416
#define tMeshAlgorithm 417
#define tReverseMesh 418
#define tLayers 419
#define tScaleLast 420
#define tHole 421
#define tAlias 422
#define tAliasWithOptions 423
#define tCopyOptions 424
#define tQuadTriAddVerts 425
#define tQuadTriNoNewVerts 426
#define tRecombLaterals 427
#define tTransfQuadTri 428
#define tText2D 429
#define tText3D 430
#define tInterpolationScheme 431
#define tTime 432
#define tCombine 433
#define tBSpline 434
#define tBezier 435
#define tNurbs 436
#define tNurbsOrder 437
#define tNurbsKnots 438
#define tColor 439
#define tColorTable 440
#define tFor 441
#define tIn 442
#define tEndFor 443
#define tIf 444
#define tElseIf 445
#define tElse 446
#define tEndIf 447
#define tExit 448
#define tAbort 449
#define tField 450
#define tReturn 451
#define tCall 452
#define tSlide 453
#define tMacro 454
#define tShow 455
#define tHide 456
#define tGetValue 457
#define tGetStringValue 458
#define tGetEnv 459
#define tGetString 460
#define tGetNumber 461
#define tUnique 462
#define tHomology 463
#define tCohomology 464
#define tBetti 465
#define tExists 466
#define tFileExists 467
#define tGetForced 468
#define tGetForcedStr 469
#define tGMSH_MAJOR_VERSION 470
#define tGMSH_MINOR_VERSION 471
#define tGMSH_PATCH_VERSION 472
#define tGmshExecutableName 473
#define tSetPartition 474
#define tNameToString 475
#define tStringToName 476
#define tAFFECTDIVIDE 477
#define tAFFECTTIMES 478
#define tAFFECTMINUS 479
#define tAFFECTPLUS 480
#define tOR 481
#define tAND 482
#define tNOTEQUAL 483
#define tEQUAL 484
#define tGREATERGREATER 485
#define tLESSLESS 486
#define tGREATEROREQUAL 487
#define tLESSOREQUAL 488
#define UNARYPREC 489
#define tMINUSMINUS 490
#define tPLUSPLUS 491




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
#line 532 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

