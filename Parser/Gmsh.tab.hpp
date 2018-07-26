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
     tDistanceFunction = 334,
     tDefineConstant = 335,
     tUndefineConstant = 336,
     tDefineNumber = 337,
     tDefineStruct = 338,
     tNameStruct = 339,
     tDimNameSpace = 340,
     tAppend = 341,
     tDefineString = 342,
     tSetNumber = 343,
     tSetTag = 344,
     tSetString = 345,
     tPoint = 346,
     tCircle = 347,
     tEllipse = 348,
     tCurve = 349,
     tSphere = 350,
     tPolarSphere = 351,
     tSurface = 352,
     tSpline = 353,
     tVolume = 354,
     tBox = 355,
     tCylinder = 356,
     tCone = 357,
     tTorus = 358,
     tEllipsoid = 359,
     tQuadric = 360,
     tShapeFromFile = 361,
     tRectangle = 362,
     tDisk = 363,
     tWire = 364,
     tGeoEntity = 365,
     tCharacteristic = 366,
     tLength = 367,
     tParametric = 368,
     tElliptic = 369,
     tRefineMesh = 370,
     tAdaptMesh = 371,
     tRelocateMesh = 372,
     tReorientMesh = 373,
     tSetFactory = 374,
     tThruSections = 375,
     tWedge = 376,
     tFillet = 377,
     tChamfer = 378,
     tPlane = 379,
     tRuled = 380,
     tTransfinite = 381,
     tPhysical = 382,
     tCompound = 383,
     tPeriodic = 384,
     tParent = 385,
     tUsing = 386,
     tPlugin = 387,
     tDegenerated = 388,
     tRecursive = 389,
     tRotate = 390,
     tTranslate = 391,
     tSymmetry = 392,
     tDilate = 393,
     tExtrude = 394,
     tLevelset = 395,
     tAffine = 396,
     tBooleanUnion = 397,
     tBooleanIntersection = 398,
     tBooleanDifference = 399,
     tBooleanSection = 400,
     tBooleanFragments = 401,
     tThickSolid = 402,
     tRecombine = 403,
     tSmoother = 404,
     tSplit = 405,
     tDelete = 406,
     tCoherence = 407,
     tIntersect = 408,
     tMeshAlgorithm = 409,
     tReverseMesh = 410,
     tLayers = 411,
     tScaleLast = 412,
     tHole = 413,
     tAlias = 414,
     tAliasWithOptions = 415,
     tCopyOptions = 416,
     tQuadTriAddVerts = 417,
     tQuadTriNoNewVerts = 418,
     tRecombLaterals = 419,
     tTransfQuadTri = 420,
     tText2D = 421,
     tText3D = 422,
     tInterpolationScheme = 423,
     tTime = 424,
     tCombine = 425,
     tBSpline = 426,
     tBezier = 427,
     tNurbs = 428,
     tNurbsOrder = 429,
     tNurbsKnots = 430,
     tColor = 431,
     tColorTable = 432,
     tFor = 433,
     tIn = 434,
     tEndFor = 435,
     tIf = 436,
     tElseIf = 437,
     tElse = 438,
     tEndIf = 439,
     tExit = 440,
     tAbort = 441,
     tField = 442,
     tReturn = 443,
     tCall = 444,
     tSlide = 445,
     tMacro = 446,
     tShow = 447,
     tHide = 448,
     tGetValue = 449,
     tGetStringValue = 450,
     tGetEnv = 451,
     tGetString = 452,
     tGetNumber = 453,
     tUnique = 454,
     tHomology = 455,
     tCohomology = 456,
     tBetti = 457,
     tExists = 458,
     tFileExists = 459,
     tGetForced = 460,
     tGetForcedStr = 461,
     tGMSH_MAJOR_VERSION = 462,
     tGMSH_MINOR_VERSION = 463,
     tGMSH_PATCH_VERSION = 464,
     tGmshExecutableName = 465,
     tSetPartition = 466,
     tNameToString = 467,
     tStringToName = 468,
     tAFFECTDIVIDE = 469,
     tAFFECTTIMES = 470,
     tAFFECTMINUS = 471,
     tAFFECTPLUS = 472,
     tOR = 473,
     tAND = 474,
     tNOTEQUAL = 475,
     tEQUAL = 476,
     tGREATERGREATER = 477,
     tLESSLESS = 478,
     tGREATEROREQUAL = 479,
     tLESSOREQUAL = 480,
     UNARYPREC = 481,
     tMINUSMINUS = 482,
     tPLUSPLUS = 483
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
#define tDistanceFunction 334
#define tDefineConstant 335
#define tUndefineConstant 336
#define tDefineNumber 337
#define tDefineStruct 338
#define tNameStruct 339
#define tDimNameSpace 340
#define tAppend 341
#define tDefineString 342
#define tSetNumber 343
#define tSetTag 344
#define tSetString 345
#define tPoint 346
#define tCircle 347
#define tEllipse 348
#define tCurve 349
#define tSphere 350
#define tPolarSphere 351
#define tSurface 352
#define tSpline 353
#define tVolume 354
#define tBox 355
#define tCylinder 356
#define tCone 357
#define tTorus 358
#define tEllipsoid 359
#define tQuadric 360
#define tShapeFromFile 361
#define tRectangle 362
#define tDisk 363
#define tWire 364
#define tGeoEntity 365
#define tCharacteristic 366
#define tLength 367
#define tParametric 368
#define tElliptic 369
#define tRefineMesh 370
#define tAdaptMesh 371
#define tRelocateMesh 372
#define tReorientMesh 373
#define tSetFactory 374
#define tThruSections 375
#define tWedge 376
#define tFillet 377
#define tChamfer 378
#define tPlane 379
#define tRuled 380
#define tTransfinite 381
#define tPhysical 382
#define tCompound 383
#define tPeriodic 384
#define tParent 385
#define tUsing 386
#define tPlugin 387
#define tDegenerated 388
#define tRecursive 389
#define tRotate 390
#define tTranslate 391
#define tSymmetry 392
#define tDilate 393
#define tExtrude 394
#define tLevelset 395
#define tAffine 396
#define tBooleanUnion 397
#define tBooleanIntersection 398
#define tBooleanDifference 399
#define tBooleanSection 400
#define tBooleanFragments 401
#define tThickSolid 402
#define tRecombine 403
#define tSmoother 404
#define tSplit 405
#define tDelete 406
#define tCoherence 407
#define tIntersect 408
#define tMeshAlgorithm 409
#define tReverseMesh 410
#define tLayers 411
#define tScaleLast 412
#define tHole 413
#define tAlias 414
#define tAliasWithOptions 415
#define tCopyOptions 416
#define tQuadTriAddVerts 417
#define tQuadTriNoNewVerts 418
#define tRecombLaterals 419
#define tTransfQuadTri 420
#define tText2D 421
#define tText3D 422
#define tInterpolationScheme 423
#define tTime 424
#define tCombine 425
#define tBSpline 426
#define tBezier 427
#define tNurbs 428
#define tNurbsOrder 429
#define tNurbsKnots 430
#define tColor 431
#define tColorTable 432
#define tFor 433
#define tIn 434
#define tEndFor 435
#define tIf 436
#define tElseIf 437
#define tElse 438
#define tEndIf 439
#define tExit 440
#define tAbort 441
#define tField 442
#define tReturn 443
#define tCall 444
#define tSlide 445
#define tMacro 446
#define tShow 447
#define tHide 448
#define tGetValue 449
#define tGetStringValue 450
#define tGetEnv 451
#define tGetString 452
#define tGetNumber 453
#define tUnique 454
#define tHomology 455
#define tCohomology 456
#define tBetti 457
#define tExists 458
#define tFileExists 459
#define tGetForced 460
#define tGetForcedStr 461
#define tGMSH_MAJOR_VERSION 462
#define tGMSH_MINOR_VERSION 463
#define tGMSH_PATCH_VERSION 464
#define tGmshExecutableName 465
#define tSetPartition 466
#define tNameToString 467
#define tStringToName 468
#define tAFFECTDIVIDE 469
#define tAFFECTTIMES 470
#define tAFFECTMINUS 471
#define tAFFECTPLUS 472
#define tOR 473
#define tAND 474
#define tNOTEQUAL 475
#define tEQUAL 476
#define tGREATERGREATER 477
#define tLESSLESS 478
#define tGREATEROREQUAL 479
#define tLESSOREQUAL 480
#define UNARYPREC 481
#define tMINUSMINUS 482
#define tPLUSPLUS 483




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
#line 516 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

