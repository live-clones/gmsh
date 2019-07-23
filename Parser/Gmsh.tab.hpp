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
     tClassifySurfaces = 337,
     tRenumberMeshNodes = 338,
     tRenumberMeshElements = 339,
     tDistanceFunction = 340,
     tDefineConstant = 341,
     tUndefineConstant = 342,
     tDefineNumber = 343,
     tDefineStruct = 344,
     tNameStruct = 345,
     tDimNameSpace = 346,
     tAppend = 347,
     tDefineString = 348,
     tSetNumber = 349,
     tSetTag = 350,
     tSetString = 351,
     tPoint = 352,
     tCircle = 353,
     tEllipse = 354,
     tCurve = 355,
     tSphere = 356,
     tPolarSphere = 357,
     tSurface = 358,
     tSpline = 359,
     tVolume = 360,
     tBox = 361,
     tCylinder = 362,
     tCone = 363,
     tTorus = 364,
     tEllipsoid = 365,
     tQuadric = 366,
     tShapeFromFile = 367,
     tRectangle = 368,
     tDisk = 369,
     tWire = 370,
     tGeoEntity = 371,
     tCharacteristic = 372,
     tLength = 373,
     tParametric = 374,
     tElliptic = 375,
     tRefineMesh = 376,
     tAdaptMesh = 377,
     tRelocateMesh = 378,
     tReorientMesh = 379,
     tSetFactory = 380,
     tThruSections = 381,
     tWedge = 382,
     tFillet = 383,
     tChamfer = 384,
     tPlane = 385,
     tRuled = 386,
     tTransfinite = 387,
     tPhysical = 388,
     tCompound = 389,
     tPeriodic = 390,
     tParent = 391,
     tUsing = 392,
     tPlugin = 393,
     tDegenerated = 394,
     tRecursive = 395,
     tSewing = 396,
     tRotate = 397,
     tTranslate = 398,
     tSymmetry = 399,
     tDilate = 400,
     tExtrude = 401,
     tLevelset = 402,
     tAffine = 403,
     tBooleanUnion = 404,
     tBooleanIntersection = 405,
     tBooleanDifference = 406,
     tBooleanSection = 407,
     tBooleanFragments = 408,
     tThickSolid = 409,
     tRecombine = 410,
     tSmoother = 411,
     tSplit = 412,
     tDelete = 413,
     tCoherence = 414,
     tIntersect = 415,
     tMeshAlgorithm = 416,
     tReverseMesh = 417,
     tLayers = 418,
     tScaleLast = 419,
     tHole = 420,
     tAlias = 421,
     tAliasWithOptions = 422,
     tCopyOptions = 423,
     tQuadTriAddVerts = 424,
     tQuadTriNoNewVerts = 425,
     tRecombLaterals = 426,
     tTransfQuadTri = 427,
     tText2D = 428,
     tText3D = 429,
     tInterpolationScheme = 430,
     tTime = 431,
     tCombine = 432,
     tBSpline = 433,
     tBezier = 434,
     tNurbs = 435,
     tNurbsOrder = 436,
     tNurbsKnots = 437,
     tColor = 438,
     tColorTable = 439,
     tFor = 440,
     tIn = 441,
     tEndFor = 442,
     tIf = 443,
     tElseIf = 444,
     tElse = 445,
     tEndIf = 446,
     tExit = 447,
     tAbort = 448,
     tField = 449,
     tReturn = 450,
     tCall = 451,
     tSlide = 452,
     tMacro = 453,
     tShow = 454,
     tHide = 455,
     tGetValue = 456,
     tGetStringValue = 457,
     tGetEnv = 458,
     tGetString = 459,
     tGetNumber = 460,
     tUnique = 461,
     tHomology = 462,
     tCohomology = 463,
     tBetti = 464,
     tExists = 465,
     tFileExists = 466,
     tGetForced = 467,
     tGetForcedStr = 468,
     tGMSH_MAJOR_VERSION = 469,
     tGMSH_MINOR_VERSION = 470,
     tGMSH_PATCH_VERSION = 471,
     tGmshExecutableName = 472,
     tSetPartition = 473,
     tNameToString = 474,
     tStringToName = 475,
     tAFFECTDIVIDE = 476,
     tAFFECTTIMES = 477,
     tAFFECTMINUS = 478,
     tAFFECTPLUS = 479,
     tOR = 480,
     tAND = 481,
     tNOTEQUAL = 482,
     tEQUAL = 483,
     tGREATERGREATER = 484,
     tLESSLESS = 485,
     tGREATEROREQUAL = 486,
     tLESSOREQUAL = 487,
     UNARYPREC = 488,
     tMINUSMINUS = 489,
     tPLUSPLUS = 490
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
#define tClassifySurfaces 337
#define tRenumberMeshNodes 338
#define tRenumberMeshElements 339
#define tDistanceFunction 340
#define tDefineConstant 341
#define tUndefineConstant 342
#define tDefineNumber 343
#define tDefineStruct 344
#define tNameStruct 345
#define tDimNameSpace 346
#define tAppend 347
#define tDefineString 348
#define tSetNumber 349
#define tSetTag 350
#define tSetString 351
#define tPoint 352
#define tCircle 353
#define tEllipse 354
#define tCurve 355
#define tSphere 356
#define tPolarSphere 357
#define tSurface 358
#define tSpline 359
#define tVolume 360
#define tBox 361
#define tCylinder 362
#define tCone 363
#define tTorus 364
#define tEllipsoid 365
#define tQuadric 366
#define tShapeFromFile 367
#define tRectangle 368
#define tDisk 369
#define tWire 370
#define tGeoEntity 371
#define tCharacteristic 372
#define tLength 373
#define tParametric 374
#define tElliptic 375
#define tRefineMesh 376
#define tAdaptMesh 377
#define tRelocateMesh 378
#define tReorientMesh 379
#define tSetFactory 380
#define tThruSections 381
#define tWedge 382
#define tFillet 383
#define tChamfer 384
#define tPlane 385
#define tRuled 386
#define tTransfinite 387
#define tPhysical 388
#define tCompound 389
#define tPeriodic 390
#define tParent 391
#define tUsing 392
#define tPlugin 393
#define tDegenerated 394
#define tRecursive 395
#define tSewing 396
#define tRotate 397
#define tTranslate 398
#define tSymmetry 399
#define tDilate 400
#define tExtrude 401
#define tLevelset 402
#define tAffine 403
#define tBooleanUnion 404
#define tBooleanIntersection 405
#define tBooleanDifference 406
#define tBooleanSection 407
#define tBooleanFragments 408
#define tThickSolid 409
#define tRecombine 410
#define tSmoother 411
#define tSplit 412
#define tDelete 413
#define tCoherence 414
#define tIntersect 415
#define tMeshAlgorithm 416
#define tReverseMesh 417
#define tLayers 418
#define tScaleLast 419
#define tHole 420
#define tAlias 421
#define tAliasWithOptions 422
#define tCopyOptions 423
#define tQuadTriAddVerts 424
#define tQuadTriNoNewVerts 425
#define tRecombLaterals 426
#define tTransfQuadTri 427
#define tText2D 428
#define tText3D 429
#define tInterpolationScheme 430
#define tTime 431
#define tCombine 432
#define tBSpline 433
#define tBezier 434
#define tNurbs 435
#define tNurbsOrder 436
#define tNurbsKnots 437
#define tColor 438
#define tColorTable 439
#define tFor 440
#define tIn 441
#define tEndFor 442
#define tIf 443
#define tElseIf 444
#define tElse 445
#define tEndIf 446
#define tExit 447
#define tAbort 448
#define tField 449
#define tReturn 450
#define tCall 451
#define tSlide 452
#define tMacro 453
#define tShow 454
#define tHide 455
#define tGetValue 456
#define tGetStringValue 457
#define tGetEnv 458
#define tGetString 459
#define tGetNumber 460
#define tUnique 461
#define tHomology 462
#define tCohomology 463
#define tBetti 464
#define tExists 465
#define tFileExists 466
#define tGetForced 467
#define tGetForcedStr 468
#define tGMSH_MAJOR_VERSION 469
#define tGMSH_MINOR_VERSION 470
#define tGMSH_PATCH_VERSION 471
#define tGmshExecutableName 472
#define tSetPartition 473
#define tNameToString 474
#define tStringToName 475
#define tAFFECTDIVIDE 476
#define tAFFECTTIMES 477
#define tAFFECTMINUS 478
#define tAFFECTPLUS 479
#define tOR 480
#define tAND 481
#define tNOTEQUAL 482
#define tEQUAL 483
#define tGREATERGREATER 484
#define tLESSLESS 485
#define tGREATEROREQUAL 486
#define tLESSOREQUAL 487
#define UNARYPREC 488
#define tMINUSMINUS 489
#define tPLUSPLUS 490




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
#line 530 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

