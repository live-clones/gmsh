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
     tOnelabAction = 327,
     tOnelabRun = 328,
     tCodeName = 329,
     tCpu = 330,
     tMemory = 331,
     tTotalMemory = 332,
     tCreateTopology = 333,
     tCreateGeometry = 334,
     tRenumberMeshNodes = 335,
     tRenumberMeshElements = 336,
     tDistanceFunction = 337,
     tDefineConstant = 338,
     tUndefineConstant = 339,
     tDefineNumber = 340,
     tDefineStruct = 341,
     tNameStruct = 342,
     tDimNameSpace = 343,
     tAppend = 344,
     tDefineString = 345,
     tSetNumber = 346,
     tSetTag = 347,
     tSetString = 348,
     tPoint = 349,
     tCircle = 350,
     tEllipse = 351,
     tCurve = 352,
     tSphere = 353,
     tPolarSphere = 354,
     tSurface = 355,
     tSpline = 356,
     tVolume = 357,
     tBox = 358,
     tCylinder = 359,
     tCone = 360,
     tTorus = 361,
     tEllipsoid = 362,
     tQuadric = 363,
     tShapeFromFile = 364,
     tRectangle = 365,
     tDisk = 366,
     tWire = 367,
     tGeoEntity = 368,
     tCharacteristic = 369,
     tLength = 370,
     tParametric = 371,
     tElliptic = 372,
     tRefineMesh = 373,
     tAdaptMesh = 374,
     tRelocateMesh = 375,
     tReorientMesh = 376,
     tSetFactory = 377,
     tThruSections = 378,
     tWedge = 379,
     tFillet = 380,
     tChamfer = 381,
     tPlane = 382,
     tRuled = 383,
     tTransfinite = 384,
     tPhysical = 385,
     tCompound = 386,
     tPeriodic = 387,
     tParent = 388,
     tUsing = 389,
     tPlugin = 390,
     tDegenerated = 391,
     tRecursive = 392,
     tRotate = 393,
     tTranslate = 394,
     tSymmetry = 395,
     tDilate = 396,
     tExtrude = 397,
     tLevelset = 398,
     tAffine = 399,
     tBooleanUnion = 400,
     tBooleanIntersection = 401,
     tBooleanDifference = 402,
     tBooleanSection = 403,
     tBooleanFragments = 404,
     tThickSolid = 405,
     tRecombine = 406,
     tSmoother = 407,
     tSplit = 408,
     tDelete = 409,
     tCoherence = 410,
     tIntersect = 411,
     tMeshAlgorithm = 412,
     tReverseMesh = 413,
     tLayers = 414,
     tScaleLast = 415,
     tHole = 416,
     tAlias = 417,
     tAliasWithOptions = 418,
     tCopyOptions = 419,
     tQuadTriAddVerts = 420,
     tQuadTriNoNewVerts = 421,
     tRecombLaterals = 422,
     tTransfQuadTri = 423,
     tText2D = 424,
     tText3D = 425,
     tInterpolationScheme = 426,
     tTime = 427,
     tCombine = 428,
     tBSpline = 429,
     tBezier = 430,
     tNurbs = 431,
     tNurbsOrder = 432,
     tNurbsKnots = 433,
     tColor = 434,
     tColorTable = 435,
     tFor = 436,
     tIn = 437,
     tEndFor = 438,
     tIf = 439,
     tElseIf = 440,
     tElse = 441,
     tEndIf = 442,
     tExit = 443,
     tAbort = 444,
     tField = 445,
     tReturn = 446,
     tCall = 447,
     tSlide = 448,
     tMacro = 449,
     tShow = 450,
     tHide = 451,
     tGetValue = 452,
     tGetStringValue = 453,
     tGetEnv = 454,
     tGetString = 455,
     tGetNumber = 456,
     tUnique = 457,
     tHomology = 458,
     tCohomology = 459,
     tBetti = 460,
     tExists = 461,
     tFileExists = 462,
     tGetForced = 463,
     tGetForcedStr = 464,
     tGMSH_MAJOR_VERSION = 465,
     tGMSH_MINOR_VERSION = 466,
     tGMSH_PATCH_VERSION = 467,
     tGmshExecutableName = 468,
     tSetPartition = 469,
     tNameToString = 470,
     tStringToName = 471,
     tAFFECTDIVIDE = 472,
     tAFFECTTIMES = 473,
     tAFFECTMINUS = 474,
     tAFFECTPLUS = 475,
     tOR = 476,
     tAND = 477,
     tNOTEQUAL = 478,
     tEQUAL = 479,
     tGREATERGREATER = 480,
     tLESSLESS = 481,
     tGREATEROREQUAL = 482,
     tLESSOREQUAL = 483,
     UNARYPREC = 484,
     tMINUSMINUS = 485,
     tPLUSPLUS = 486
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
#define tOnelabAction 327
#define tOnelabRun 328
#define tCodeName 329
#define tCpu 330
#define tMemory 331
#define tTotalMemory 332
#define tCreateTopology 333
#define tCreateGeometry 334
#define tRenumberMeshNodes 335
#define tRenumberMeshElements 336
#define tDistanceFunction 337
#define tDefineConstant 338
#define tUndefineConstant 339
#define tDefineNumber 340
#define tDefineStruct 341
#define tNameStruct 342
#define tDimNameSpace 343
#define tAppend 344
#define tDefineString 345
#define tSetNumber 346
#define tSetTag 347
#define tSetString 348
#define tPoint 349
#define tCircle 350
#define tEllipse 351
#define tCurve 352
#define tSphere 353
#define tPolarSphere 354
#define tSurface 355
#define tSpline 356
#define tVolume 357
#define tBox 358
#define tCylinder 359
#define tCone 360
#define tTorus 361
#define tEllipsoid 362
#define tQuadric 363
#define tShapeFromFile 364
#define tRectangle 365
#define tDisk 366
#define tWire 367
#define tGeoEntity 368
#define tCharacteristic 369
#define tLength 370
#define tParametric 371
#define tElliptic 372
#define tRefineMesh 373
#define tAdaptMesh 374
#define tRelocateMesh 375
#define tReorientMesh 376
#define tSetFactory 377
#define tThruSections 378
#define tWedge 379
#define tFillet 380
#define tChamfer 381
#define tPlane 382
#define tRuled 383
#define tTransfinite 384
#define tPhysical 385
#define tCompound 386
#define tPeriodic 387
#define tParent 388
#define tUsing 389
#define tPlugin 390
#define tDegenerated 391
#define tRecursive 392
#define tRotate 393
#define tTranslate 394
#define tSymmetry 395
#define tDilate 396
#define tExtrude 397
#define tLevelset 398
#define tAffine 399
#define tBooleanUnion 400
#define tBooleanIntersection 401
#define tBooleanDifference 402
#define tBooleanSection 403
#define tBooleanFragments 404
#define tThickSolid 405
#define tRecombine 406
#define tSmoother 407
#define tSplit 408
#define tDelete 409
#define tCoherence 410
#define tIntersect 411
#define tMeshAlgorithm 412
#define tReverseMesh 413
#define tLayers 414
#define tScaleLast 415
#define tHole 416
#define tAlias 417
#define tAliasWithOptions 418
#define tCopyOptions 419
#define tQuadTriAddVerts 420
#define tQuadTriNoNewVerts 421
#define tRecombLaterals 422
#define tTransfQuadTri 423
#define tText2D 424
#define tText3D 425
#define tInterpolationScheme 426
#define tTime 427
#define tCombine 428
#define tBSpline 429
#define tBezier 430
#define tNurbs 431
#define tNurbsOrder 432
#define tNurbsKnots 433
#define tColor 434
#define tColorTable 435
#define tFor 436
#define tIn 437
#define tEndFor 438
#define tIf 439
#define tElseIf 440
#define tElse 441
#define tEndIf 442
#define tExit 443
#define tAbort 444
#define tField 445
#define tReturn 446
#define tCall 447
#define tSlide 448
#define tMacro 449
#define tShow 450
#define tHide 451
#define tGetValue 452
#define tGetStringValue 453
#define tGetEnv 454
#define tGetString 455
#define tGetNumber 456
#define tUnique 457
#define tHomology 458
#define tCohomology 459
#define tBetti 460
#define tExists 461
#define tFileExists 462
#define tGetForced 463
#define tGetForcedStr 464
#define tGMSH_MAJOR_VERSION 465
#define tGMSH_MINOR_VERSION 466
#define tGMSH_PATCH_VERSION 467
#define tGmshExecutableName 468
#define tSetPartition 469
#define tNameToString 470
#define tStringToName 471
#define tAFFECTDIVIDE 472
#define tAFFECTTIMES 473
#define tAFFECTMINUS 474
#define tAFFECTPLUS 475
#define tOR 476
#define tAND 477
#define tNOTEQUAL 478
#define tEQUAL 479
#define tGREATERGREATER 480
#define tLESSLESS 481
#define tGREATEROREQUAL 482
#define tLESSOREQUAL 483
#define UNARYPREC 484
#define tMINUSMINUS 485
#define tPLUSPLUS 486




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
#line 522 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

