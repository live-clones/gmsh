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
     tPlane = 378,
     tRuled = 379,
     tTransfinite = 380,
     tPhysical = 381,
     tCompound = 382,
     tPeriodic = 383,
     tParent = 384,
     tUsing = 385,
     tPlugin = 386,
     tDegenerated = 387,
     tRecursive = 388,
     tRotate = 389,
     tTranslate = 390,
     tSymmetry = 391,
     tDilate = 392,
     tExtrude = 393,
     tLevelset = 394,
     tAffine = 395,
     tBooleanUnion = 396,
     tBooleanIntersection = 397,
     tBooleanDifference = 398,
     tBooleanSection = 399,
     tBooleanFragments = 400,
     tThickSolid = 401,
     tRecombine = 402,
     tSmoother = 403,
     tSplit = 404,
     tDelete = 405,
     tCoherence = 406,
     tIntersect = 407,
     tMeshAlgorithm = 408,
     tReverseMesh = 409,
     tLayers = 410,
     tScaleLast = 411,
     tHole = 412,
     tAlias = 413,
     tAliasWithOptions = 414,
     tCopyOptions = 415,
     tQuadTriAddVerts = 416,
     tQuadTriNoNewVerts = 417,
     tRecombLaterals = 418,
     tTransfQuadTri = 419,
     tText2D = 420,
     tText3D = 421,
     tInterpolationScheme = 422,
     tTime = 423,
     tCombine = 424,
     tBSpline = 425,
     tBezier = 426,
     tNurbs = 427,
     tNurbsOrder = 428,
     tNurbsKnots = 429,
     tColor = 430,
     tColorTable = 431,
     tFor = 432,
     tIn = 433,
     tEndFor = 434,
     tIf = 435,
     tElseIf = 436,
     tElse = 437,
     tEndIf = 438,
     tExit = 439,
     tAbort = 440,
     tField = 441,
     tReturn = 442,
     tCall = 443,
     tSlide = 444,
     tMacro = 445,
     tShow = 446,
     tHide = 447,
     tGetValue = 448,
     tGetStringValue = 449,
     tGetEnv = 450,
     tGetString = 451,
     tGetNumber = 452,
     tUnique = 453,
     tHomology = 454,
     tCohomology = 455,
     tBetti = 456,
     tExists = 457,
     tFileExists = 458,
     tGetForced = 459,
     tGetForcedStr = 460,
     tGMSH_MAJOR_VERSION = 461,
     tGMSH_MINOR_VERSION = 462,
     tGMSH_PATCH_VERSION = 463,
     tGmshExecutableName = 464,
     tSetPartition = 465,
     tNameToString = 466,
     tStringToName = 467,
     tAFFECTDIVIDE = 468,
     tAFFECTTIMES = 469,
     tAFFECTMINUS = 470,
     tAFFECTPLUS = 471,
     tOR = 472,
     tAND = 473,
     tNOTEQUAL = 474,
     tEQUAL = 475,
     tGREATERGREATER = 476,
     tLESSLESS = 477,
     tGREATEROREQUAL = 478,
     tLESSOREQUAL = 479,
     UNARYPREC = 480,
     tMINUSMINUS = 481,
     tPLUSPLUS = 482
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
#define tPlane 378
#define tRuled 379
#define tTransfinite 380
#define tPhysical 381
#define tCompound 382
#define tPeriodic 383
#define tParent 384
#define tUsing 385
#define tPlugin 386
#define tDegenerated 387
#define tRecursive 388
#define tRotate 389
#define tTranslate 390
#define tSymmetry 391
#define tDilate 392
#define tExtrude 393
#define tLevelset 394
#define tAffine 395
#define tBooleanUnion 396
#define tBooleanIntersection 397
#define tBooleanDifference 398
#define tBooleanSection 399
#define tBooleanFragments 400
#define tThickSolid 401
#define tRecombine 402
#define tSmoother 403
#define tSplit 404
#define tDelete 405
#define tCoherence 406
#define tIntersect 407
#define tMeshAlgorithm 408
#define tReverseMesh 409
#define tLayers 410
#define tScaleLast 411
#define tHole 412
#define tAlias 413
#define tAliasWithOptions 414
#define tCopyOptions 415
#define tQuadTriAddVerts 416
#define tQuadTriNoNewVerts 417
#define tRecombLaterals 418
#define tTransfQuadTri 419
#define tText2D 420
#define tText3D 421
#define tInterpolationScheme 422
#define tTime 423
#define tCombine 424
#define tBSpline 425
#define tBezier 426
#define tNurbs 427
#define tNurbsOrder 428
#define tNurbsKnots 429
#define tColor 430
#define tColorTable 431
#define tFor 432
#define tIn 433
#define tEndFor 434
#define tIf 435
#define tElseIf 436
#define tElse 437
#define tEndIf 438
#define tExit 439
#define tAbort 440
#define tField 441
#define tReturn 442
#define tCall 443
#define tSlide 444
#define tMacro 445
#define tShow 446
#define tHide 447
#define tGetValue 448
#define tGetStringValue 449
#define tGetEnv 450
#define tGetString 451
#define tGetNumber 452
#define tUnique 453
#define tHomology 454
#define tCohomology 455
#define tBetti 456
#define tExists 457
#define tFileExists 458
#define tGetForced 459
#define tGetForcedStr 460
#define tGMSH_MAJOR_VERSION 461
#define tGMSH_MINOR_VERSION 462
#define tGMSH_PATCH_VERSION 463
#define tGmshExecutableName 464
#define tSetPartition 465
#define tNameToString 466
#define tStringToName 467
#define tAFFECTDIVIDE 468
#define tAFFECTTIMES 469
#define tAFFECTMINUS 470
#define tAFFECTPLUS 471
#define tOR 472
#define tAND 473
#define tNOTEQUAL 474
#define tEQUAL 475
#define tGREATERGREATER 476
#define tLESSLESS 477
#define tGREATEROREQUAL 478
#define tLESSOREQUAL 479
#define UNARYPREC 480
#define tMINUSMINUS 481
#define tPLUSPLUS 482




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
#line 514 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

