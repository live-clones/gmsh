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
     tDistanceFunction = 335,
     tDefineConstant = 336,
     tUndefineConstant = 337,
     tDefineNumber = 338,
     tDefineStruct = 339,
     tNameStruct = 340,
     tDimNameSpace = 341,
     tAppend = 342,
     tDefineString = 343,
     tSetNumber = 344,
     tSetTag = 345,
     tSetString = 346,
     tPoint = 347,
     tCircle = 348,
     tEllipse = 349,
     tCurve = 350,
     tSphere = 351,
     tPolarSphere = 352,
     tSurface = 353,
     tSpline = 354,
     tVolume = 355,
     tBox = 356,
     tCylinder = 357,
     tCone = 358,
     tTorus = 359,
     tEllipsoid = 360,
     tQuadric = 361,
     tShapeFromFile = 362,
     tRectangle = 363,
     tDisk = 364,
     tWire = 365,
     tGeoEntity = 366,
     tCharacteristic = 367,
     tLength = 368,
     tParametric = 369,
     tElliptic = 370,
     tRefineMesh = 371,
     tAdaptMesh = 372,
     tRelocateMesh = 373,
     tReorientMesh = 374,
     tSetFactory = 375,
     tThruSections = 376,
     tWedge = 377,
     tFillet = 378,
     tChamfer = 379,
     tPlane = 380,
     tRuled = 381,
     tTransfinite = 382,
     tPhysical = 383,
     tCompound = 384,
     tPeriodic = 385,
     tParent = 386,
     tUsing = 387,
     tPlugin = 388,
     tDegenerated = 389,
     tRecursive = 390,
     tRotate = 391,
     tTranslate = 392,
     tSymmetry = 393,
     tDilate = 394,
     tExtrude = 395,
     tLevelset = 396,
     tAffine = 397,
     tBooleanUnion = 398,
     tBooleanIntersection = 399,
     tBooleanDifference = 400,
     tBooleanSection = 401,
     tBooleanFragments = 402,
     tThickSolid = 403,
     tRecombine = 404,
     tSmoother = 405,
     tSplit = 406,
     tDelete = 407,
     tCoherence = 408,
     tIntersect = 409,
     tMeshAlgorithm = 410,
     tReverseMesh = 411,
     tLayers = 412,
     tScaleLast = 413,
     tHole = 414,
     tAlias = 415,
     tAliasWithOptions = 416,
     tCopyOptions = 417,
     tQuadTriAddVerts = 418,
     tQuadTriNoNewVerts = 419,
     tRecombLaterals = 420,
     tTransfQuadTri = 421,
     tText2D = 422,
     tText3D = 423,
     tInterpolationScheme = 424,
     tTime = 425,
     tCombine = 426,
     tBSpline = 427,
     tBezier = 428,
     tNurbs = 429,
     tNurbsOrder = 430,
     tNurbsKnots = 431,
     tColor = 432,
     tColorTable = 433,
     tFor = 434,
     tIn = 435,
     tEndFor = 436,
     tIf = 437,
     tElseIf = 438,
     tElse = 439,
     tEndIf = 440,
     tExit = 441,
     tAbort = 442,
     tField = 443,
     tReturn = 444,
     tCall = 445,
     tSlide = 446,
     tMacro = 447,
     tShow = 448,
     tHide = 449,
     tGetValue = 450,
     tGetStringValue = 451,
     tGetEnv = 452,
     tGetString = 453,
     tGetNumber = 454,
     tUnique = 455,
     tHomology = 456,
     tCohomology = 457,
     tBetti = 458,
     tExists = 459,
     tFileExists = 460,
     tGetForced = 461,
     tGetForcedStr = 462,
     tGMSH_MAJOR_VERSION = 463,
     tGMSH_MINOR_VERSION = 464,
     tGMSH_PATCH_VERSION = 465,
     tGmshExecutableName = 466,
     tSetPartition = 467,
     tNameToString = 468,
     tStringToName = 469,
     tAFFECTDIVIDE = 470,
     tAFFECTTIMES = 471,
     tAFFECTMINUS = 472,
     tAFFECTPLUS = 473,
     tOR = 474,
     tAND = 475,
     tNOTEQUAL = 476,
     tEQUAL = 477,
     tGREATERGREATER = 478,
     tLESSLESS = 479,
     tGREATEROREQUAL = 480,
     tLESSOREQUAL = 481,
     UNARYPREC = 482,
     tMINUSMINUS = 483,
     tPLUSPLUS = 484
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
#define tDistanceFunction 335
#define tDefineConstant 336
#define tUndefineConstant 337
#define tDefineNumber 338
#define tDefineStruct 339
#define tNameStruct 340
#define tDimNameSpace 341
#define tAppend 342
#define tDefineString 343
#define tSetNumber 344
#define tSetTag 345
#define tSetString 346
#define tPoint 347
#define tCircle 348
#define tEllipse 349
#define tCurve 350
#define tSphere 351
#define tPolarSphere 352
#define tSurface 353
#define tSpline 354
#define tVolume 355
#define tBox 356
#define tCylinder 357
#define tCone 358
#define tTorus 359
#define tEllipsoid 360
#define tQuadric 361
#define tShapeFromFile 362
#define tRectangle 363
#define tDisk 364
#define tWire 365
#define tGeoEntity 366
#define tCharacteristic 367
#define tLength 368
#define tParametric 369
#define tElliptic 370
#define tRefineMesh 371
#define tAdaptMesh 372
#define tRelocateMesh 373
#define tReorientMesh 374
#define tSetFactory 375
#define tThruSections 376
#define tWedge 377
#define tFillet 378
#define tChamfer 379
#define tPlane 380
#define tRuled 381
#define tTransfinite 382
#define tPhysical 383
#define tCompound 384
#define tPeriodic 385
#define tParent 386
#define tUsing 387
#define tPlugin 388
#define tDegenerated 389
#define tRecursive 390
#define tRotate 391
#define tTranslate 392
#define tSymmetry 393
#define tDilate 394
#define tExtrude 395
#define tLevelset 396
#define tAffine 397
#define tBooleanUnion 398
#define tBooleanIntersection 399
#define tBooleanDifference 400
#define tBooleanSection 401
#define tBooleanFragments 402
#define tThickSolid 403
#define tRecombine 404
#define tSmoother 405
#define tSplit 406
#define tDelete 407
#define tCoherence 408
#define tIntersect 409
#define tMeshAlgorithm 410
#define tReverseMesh 411
#define tLayers 412
#define tScaleLast 413
#define tHole 414
#define tAlias 415
#define tAliasWithOptions 416
#define tCopyOptions 417
#define tQuadTriAddVerts 418
#define tQuadTriNoNewVerts 419
#define tRecombLaterals 420
#define tTransfQuadTri 421
#define tText2D 422
#define tText3D 423
#define tInterpolationScheme 424
#define tTime 425
#define tCombine 426
#define tBSpline 427
#define tBezier 428
#define tNurbs 429
#define tNurbsOrder 430
#define tNurbsKnots 431
#define tColor 432
#define tColorTable 433
#define tFor 434
#define tIn 435
#define tEndFor 436
#define tIf 437
#define tElseIf 438
#define tElse 439
#define tEndIf 440
#define tExit 441
#define tAbort 442
#define tField 443
#define tReturn 444
#define tCall 445
#define tSlide 446
#define tMacro 447
#define tShow 448
#define tHide 449
#define tGetValue 450
#define tGetStringValue 451
#define tGetEnv 452
#define tGetString 453
#define tGetNumber 454
#define tUnique 455
#define tHomology 456
#define tCohomology 457
#define tBetti 458
#define tExists 459
#define tFileExists 460
#define tGetForced 461
#define tGetForcedStr 462
#define tGMSH_MAJOR_VERSION 463
#define tGMSH_MINOR_VERSION 464
#define tGMSH_PATCH_VERSION 465
#define tGmshExecutableName 466
#define tSetPartition 467
#define tNameToString 468
#define tStringToName 469
#define tAFFECTDIVIDE 470
#define tAFFECTTIMES 471
#define tAFFECTMINUS 472
#define tAFFECTPLUS 473
#define tOR 474
#define tAND 475
#define tNOTEQUAL 476
#define tEQUAL 477
#define tGREATERGREATER 478
#define tLESSLESS 479
#define tGREATEROREQUAL 480
#define tLESSOREQUAL 481
#define UNARYPREC 482
#define tMINUSMINUS 483
#define tPLUSPLUS 484




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
#line 518 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

