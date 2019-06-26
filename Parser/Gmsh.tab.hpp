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
     tStr = 301,
     tSprintf = 302,
     tStrCat = 303,
     tStrPrefix = 304,
     tStrRelative = 305,
     tStrReplace = 306,
     tAbsolutePath = 307,
     tDirName = 308,
     tStrSub = 309,
     tStrLen = 310,
     tFind = 311,
     tStrFind = 312,
     tStrCmp = 313,
     tStrChoice = 314,
     tUpperCase = 315,
     tLowerCase = 316,
     tLowerCaseIn = 317,
     tTextAttributes = 318,
     tBoundingBox = 319,
     tDraw = 320,
     tSetChanged = 321,
     tToday = 322,
     tFixRelativePath = 323,
     tCurrentDirectory = 324,
     tSyncModel = 325,
     tNewModel = 326,
     tMass = 327,
     tCenterOfMass = 328,
     tOnelabAction = 329,
     tOnelabRun = 330,
     tCodeName = 331,
     tCpu = 332,
     tMemory = 333,
     tTotalMemory = 334,
     tCreateTopology = 335,
     tCreateGeometry = 336,
     tRenumberMeshNodes = 337,
     tRenumberMeshElements = 338,
     tDistanceFunction = 339,
     tDefineConstant = 340,
     tUndefineConstant = 341,
     tDefineNumber = 342,
     tDefineStruct = 343,
     tNameStruct = 344,
     tDimNameSpace = 345,
     tAppend = 346,
     tDefineString = 347,
     tSetNumber = 348,
     tSetTag = 349,
     tSetString = 350,
     tPoint = 351,
     tCircle = 352,
     tEllipse = 353,
     tCurve = 354,
     tSphere = 355,
     tPolarSphere = 356,
     tSurface = 357,
     tSpline = 358,
     tVolume = 359,
     tBox = 360,
     tCylinder = 361,
     tCone = 362,
     tTorus = 363,
     tEllipsoid = 364,
     tQuadric = 365,
     tShapeFromFile = 366,
     tRectangle = 367,
     tDisk = 368,
     tWire = 369,
     tGeoEntity = 370,
     tCharacteristic = 371,
     tLength = 372,
     tParametric = 373,
     tElliptic = 374,
     tRefineMesh = 375,
     tAdaptMesh = 376,
     tRelocateMesh = 377,
     tReorientMesh = 378,
     tSetFactory = 379,
     tThruSections = 380,
     tWedge = 381,
     tFillet = 382,
     tChamfer = 383,
     tPlane = 384,
     tRuled = 385,
     tTransfinite = 386,
     tPhysical = 387,
     tCompound = 388,
     tPeriodic = 389,
     tParent = 390,
     tUsing = 391,
     tPlugin = 392,
     tDegenerated = 393,
     tRecursive = 394,
     tRotate = 395,
     tTranslate = 396,
     tSymmetry = 397,
     tDilate = 398,
     tExtrude = 399,
     tLevelset = 400,
     tAffine = 401,
     tBooleanUnion = 402,
     tBooleanIntersection = 403,
     tBooleanDifference = 404,
     tBooleanSection = 405,
     tBooleanFragments = 406,
     tThickSolid = 407,
     tRecombine = 408,
     tSmoother = 409,
     tSplit = 410,
     tDelete = 411,
     tCoherence = 412,
     tIntersect = 413,
     tMeshAlgorithm = 414,
     tReverseMesh = 415,
     tLayers = 416,
     tScaleLast = 417,
     tHole = 418,
     tAlias = 419,
     tAliasWithOptions = 420,
     tCopyOptions = 421,
     tQuadTriAddVerts = 422,
     tQuadTriNoNewVerts = 423,
     tRecombLaterals = 424,
     tTransfQuadTri = 425,
     tText2D = 426,
     tText3D = 427,
     tInterpolationScheme = 428,
     tTime = 429,
     tCombine = 430,
     tBSpline = 431,
     tBezier = 432,
     tNurbs = 433,
     tNurbsOrder = 434,
     tNurbsKnots = 435,
     tColor = 436,
     tColorTable = 437,
     tFor = 438,
     tIn = 439,
     tEndFor = 440,
     tIf = 441,
     tElseIf = 442,
     tElse = 443,
     tEndIf = 444,
     tExit = 445,
     tAbort = 446,
     tField = 447,
     tReturn = 448,
     tCall = 449,
     tSlide = 450,
     tMacro = 451,
     tShow = 452,
     tHide = 453,
     tGetValue = 454,
     tGetStringValue = 455,
     tGetEnv = 456,
     tGetString = 457,
     tGetNumber = 458,
     tUnique = 459,
     tHomology = 460,
     tCohomology = 461,
     tBetti = 462,
     tExists = 463,
     tFileExists = 464,
     tGetForced = 465,
     tGetForcedStr = 466,
     tGMSH_MAJOR_VERSION = 467,
     tGMSH_MINOR_VERSION = 468,
     tGMSH_PATCH_VERSION = 469,
     tGmshExecutableName = 470,
     tSetPartition = 471,
     tNameToString = 472,
     tStringToName = 473,
     tAFFECTDIVIDE = 474,
     tAFFECTTIMES = 475,
     tAFFECTMINUS = 476,
     tAFFECTPLUS = 477,
     tOR = 478,
     tAND = 479,
     tNOTEQUAL = 480,
     tEQUAL = 481,
     tGREATERGREATER = 482,
     tLESSLESS = 483,
     tGREATEROREQUAL = 484,
     tLESSOREQUAL = 485,
     UNARYPREC = 486,
     tMINUSMINUS = 487,
     tPLUSPLUS = 488
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
#define tStr 301
#define tSprintf 302
#define tStrCat 303
#define tStrPrefix 304
#define tStrRelative 305
#define tStrReplace 306
#define tAbsolutePath 307
#define tDirName 308
#define tStrSub 309
#define tStrLen 310
#define tFind 311
#define tStrFind 312
#define tStrCmp 313
#define tStrChoice 314
#define tUpperCase 315
#define tLowerCase 316
#define tLowerCaseIn 317
#define tTextAttributes 318
#define tBoundingBox 319
#define tDraw 320
#define tSetChanged 321
#define tToday 322
#define tFixRelativePath 323
#define tCurrentDirectory 324
#define tSyncModel 325
#define tNewModel 326
#define tMass 327
#define tCenterOfMass 328
#define tOnelabAction 329
#define tOnelabRun 330
#define tCodeName 331
#define tCpu 332
#define tMemory 333
#define tTotalMemory 334
#define tCreateTopology 335
#define tCreateGeometry 336
#define tRenumberMeshNodes 337
#define tRenumberMeshElements 338
#define tDistanceFunction 339
#define tDefineConstant 340
#define tUndefineConstant 341
#define tDefineNumber 342
#define tDefineStruct 343
#define tNameStruct 344
#define tDimNameSpace 345
#define tAppend 346
#define tDefineString 347
#define tSetNumber 348
#define tSetTag 349
#define tSetString 350
#define tPoint 351
#define tCircle 352
#define tEllipse 353
#define tCurve 354
#define tSphere 355
#define tPolarSphere 356
#define tSurface 357
#define tSpline 358
#define tVolume 359
#define tBox 360
#define tCylinder 361
#define tCone 362
#define tTorus 363
#define tEllipsoid 364
#define tQuadric 365
#define tShapeFromFile 366
#define tRectangle 367
#define tDisk 368
#define tWire 369
#define tGeoEntity 370
#define tCharacteristic 371
#define tLength 372
#define tParametric 373
#define tElliptic 374
#define tRefineMesh 375
#define tAdaptMesh 376
#define tRelocateMesh 377
#define tReorientMesh 378
#define tSetFactory 379
#define tThruSections 380
#define tWedge 381
#define tFillet 382
#define tChamfer 383
#define tPlane 384
#define tRuled 385
#define tTransfinite 386
#define tPhysical 387
#define tCompound 388
#define tPeriodic 389
#define tParent 390
#define tUsing 391
#define tPlugin 392
#define tDegenerated 393
#define tRecursive 394
#define tRotate 395
#define tTranslate 396
#define tSymmetry 397
#define tDilate 398
#define tExtrude 399
#define tLevelset 400
#define tAffine 401
#define tBooleanUnion 402
#define tBooleanIntersection 403
#define tBooleanDifference 404
#define tBooleanSection 405
#define tBooleanFragments 406
#define tThickSolid 407
#define tRecombine 408
#define tSmoother 409
#define tSplit 410
#define tDelete 411
#define tCoherence 412
#define tIntersect 413
#define tMeshAlgorithm 414
#define tReverseMesh 415
#define tLayers 416
#define tScaleLast 417
#define tHole 418
#define tAlias 419
#define tAliasWithOptions 420
#define tCopyOptions 421
#define tQuadTriAddVerts 422
#define tQuadTriNoNewVerts 423
#define tRecombLaterals 424
#define tTransfQuadTri 425
#define tText2D 426
#define tText3D 427
#define tInterpolationScheme 428
#define tTime 429
#define tCombine 430
#define tBSpline 431
#define tBezier 432
#define tNurbs 433
#define tNurbsOrder 434
#define tNurbsKnots 435
#define tColor 436
#define tColorTable 437
#define tFor 438
#define tIn 439
#define tEndFor 440
#define tIf 441
#define tElseIf 442
#define tElse 443
#define tEndIf 444
#define tExit 445
#define tAbort 446
#define tField 447
#define tReturn 448
#define tCall 449
#define tSlide 450
#define tMacro 451
#define tShow 452
#define tHide 453
#define tGetValue 454
#define tGetStringValue 455
#define tGetEnv 456
#define tGetString 457
#define tGetNumber 458
#define tUnique 459
#define tHomology 460
#define tCohomology 461
#define tBetti 462
#define tExists 463
#define tFileExists 464
#define tGetForced 465
#define tGetForcedStr 466
#define tGMSH_MAJOR_VERSION 467
#define tGMSH_MINOR_VERSION 468
#define tGMSH_PATCH_VERSION 469
#define tGmshExecutableName 470
#define tSetPartition 471
#define tNameToString 472
#define tStringToName 473
#define tAFFECTDIVIDE 474
#define tAFFECTTIMES 475
#define tAFFECTMINUS 476
#define tAFFECTPLUS 477
#define tOR 478
#define tAND 479
#define tNOTEQUAL 480
#define tEQUAL 481
#define tGREATERGREATER 482
#define tLESSLESS 483
#define tGREATEROREQUAL 484
#define tLESSOREQUAL 485
#define UNARYPREC 486
#define tMINUSMINUS 487
#define tPLUSPLUS 488




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
#line 526 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

