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
     tMeshSizeFromBoundary = 419,
     tLayers = 420,
     tScaleLast = 421,
     tHole = 422,
     tAlias = 423,
     tAliasWithOptions = 424,
     tCopyOptions = 425,
     tQuadTriAddVerts = 426,
     tQuadTriNoNewVerts = 427,
     tRecombLaterals = 428,
     tTransfQuadTri = 429,
     tText2D = 430,
     tText3D = 431,
     tInterpolationScheme = 432,
     tTime = 433,
     tCombine = 434,
     tBSpline = 435,
     tBezier = 436,
     tNurbs = 437,
     tNurbsOrder = 438,
     tNurbsKnots = 439,
     tColor = 440,
     tColorTable = 441,
     tFor = 442,
     tIn = 443,
     tEndFor = 444,
     tIf = 445,
     tElseIf = 446,
     tElse = 447,
     tEndIf = 448,
     tExit = 449,
     tAbort = 450,
     tField = 451,
     tReturn = 452,
     tCall = 453,
     tSlide = 454,
     tMacro = 455,
     tShow = 456,
     tHide = 457,
     tGetValue = 458,
     tGetStringValue = 459,
     tGetEnv = 460,
     tGetString = 461,
     tGetNumber = 462,
     tUnique = 463,
     tHomology = 464,
     tCohomology = 465,
     tBetti = 466,
     tExists = 467,
     tFileExists = 468,
     tGetForced = 469,
     tGetForcedStr = 470,
     tGMSH_MAJOR_VERSION = 471,
     tGMSH_MINOR_VERSION = 472,
     tGMSH_PATCH_VERSION = 473,
     tGmshExecutableName = 474,
     tSetPartition = 475,
     tNameToString = 476,
     tStringToName = 477,
     tAFFECTDIVIDE = 478,
     tAFFECTTIMES = 479,
     tAFFECTMINUS = 480,
     tAFFECTPLUS = 481,
     tOR = 482,
     tAND = 483,
     tNOTEQUAL = 484,
     tEQUAL = 485,
     tGREATERGREATER = 486,
     tLESSLESS = 487,
     tGREATEROREQUAL = 488,
     tLESSOREQUAL = 489,
     UNARYPREC = 490,
     tMINUSMINUS = 491,
     tPLUSPLUS = 492
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
#define tMeshSizeFromBoundary 419
#define tLayers 420
#define tScaleLast 421
#define tHole 422
#define tAlias 423
#define tAliasWithOptions 424
#define tCopyOptions 425
#define tQuadTriAddVerts 426
#define tQuadTriNoNewVerts 427
#define tRecombLaterals 428
#define tTransfQuadTri 429
#define tText2D 430
#define tText3D 431
#define tInterpolationScheme 432
#define tTime 433
#define tCombine 434
#define tBSpline 435
#define tBezier 436
#define tNurbs 437
#define tNurbsOrder 438
#define tNurbsKnots 439
#define tColor 440
#define tColorTable 441
#define tFor 442
#define tIn 443
#define tEndFor 444
#define tIf 445
#define tElseIf 446
#define tElse 447
#define tEndIf 448
#define tExit 449
#define tAbort 450
#define tField 451
#define tReturn 452
#define tCall 453
#define tSlide 454
#define tMacro 455
#define tShow 456
#define tHide 457
#define tGetValue 458
#define tGetStringValue 459
#define tGetEnv 460
#define tGetString 461
#define tGetNumber 462
#define tUnique 463
#define tHomology 464
#define tCohomology 465
#define tBetti 466
#define tExists 467
#define tFileExists 468
#define tGetForced 469
#define tGetForcedStr 470
#define tGMSH_MAJOR_VERSION 471
#define tGMSH_MINOR_VERSION 472
#define tGMSH_PATCH_VERSION 473
#define tGmshExecutableName 474
#define tSetPartition 475
#define tNameToString 476
#define tStringToName 477
#define tAFFECTDIVIDE 478
#define tAFFECTTIMES 479
#define tAFFECTMINUS 480
#define tAFFECTPLUS 481
#define tOR 482
#define tAND 483
#define tNOTEQUAL 484
#define tEQUAL 485
#define tGREATERGREATER 486
#define tLESSLESS 487
#define tGREATEROREQUAL 488
#define tLESSOREQUAL 489
#define UNARYPREC 490
#define tMINUSMINUS 491
#define tPLUSPLUS 492




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
#line 534 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

