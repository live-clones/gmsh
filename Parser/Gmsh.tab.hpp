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
     tPi = 264,
     tMPI_Rank = 265,
     tMPI_Size = 266,
     tEuclidian = 267,
     tCoordinates = 268,
     tTestLevel = 269,
     tExp = 270,
     tLog = 271,
     tLog10 = 272,
     tSqrt = 273,
     tSin = 274,
     tAsin = 275,
     tCos = 276,
     tAcos = 277,
     tTan = 278,
     tRand = 279,
     tAtan = 280,
     tAtan2 = 281,
     tSinh = 282,
     tCosh = 283,
     tTanh = 284,
     tFabs = 285,
     tFloor = 286,
     tCeil = 287,
     tRound = 288,
     tFmod = 289,
     tModulo = 290,
     tHypot = 291,
     tList = 292,
     tLinSpace = 293,
     tLogSpace = 294,
     tListFromFile = 295,
     tCatenary = 296,
     tPrintf = 297,
     tError = 298,
     tStr = 299,
     tSprintf = 300,
     tStrCat = 301,
     tStrPrefix = 302,
     tStrRelative = 303,
     tStrReplace = 304,
     tAbsolutePath = 305,
     tDirName = 306,
     tStrSub = 307,
     tStrLen = 308,
     tFind = 309,
     tStrFind = 310,
     tStrCmp = 311,
     tStrChoice = 312,
     tUpperCase = 313,
     tLowerCase = 314,
     tLowerCaseIn = 315,
     tTextAttributes = 316,
     tBoundingBox = 317,
     tDraw = 318,
     tSetChanged = 319,
     tToday = 320,
     tFixRelativePath = 321,
     tCurrentDirectory = 322,
     tSyncModel = 323,
     tNewModel = 324,
     tOnelabAction = 325,
     tOnelabRun = 326,
     tCpu = 327,
     tMemory = 328,
     tTotalMemory = 329,
     tCreateTopology = 330,
     tCreateTopologyNoHoles = 331,
     tDistanceFunction = 332,
     tDefineConstant = 333,
     tUndefineConstant = 334,
     tDefineNumber = 335,
     tDefineStruct = 336,
     tNameStruct = 337,
     tDefineString = 338,
     tSetNumber = 339,
     tSetString = 340,
     tPoint = 341,
     tCircle = 342,
     tEllipse = 343,
     tLine = 344,
     tSphere = 345,
     tPolarSphere = 346,
     tSurface = 347,
     tSpline = 348,
     tVolume = 349,
     tBlock = 350,
     tCylinder = 351,
     tCone = 352,
     tTorus = 353,
     tEllipsoid = 354,
     tQuadric = 355,
     tShapeFromFile = 356,
     tRectangle = 357,
     tDisk = 358,
     tWire = 359,
     tCharacteristic = 360,
     tLength = 361,
     tParametric = 362,
     tElliptic = 363,
     tRefineMesh = 364,
     tAdaptMesh = 365,
     tRelocateMesh = 366,
     tSetFactory = 367,
     tThruSections = 368,
     tWedge = 369,
     tFillet = 370,
     tChamfer = 371,
     tPlane = 372,
     tRuled = 373,
     tTransfinite = 374,
     tComplex = 375,
     tPhysical = 376,
     tCompound = 377,
     tPeriodic = 378,
     tUsing = 379,
     tPlugin = 380,
     tDegenerated = 381,
     tRecursive = 382,
     tRotate = 383,
     tTranslate = 384,
     tSymmetry = 385,
     tDilate = 386,
     tExtrude = 387,
     tLevelset = 388,
     tAffine = 389,
     tBooleanUnion = 390,
     tBooleanIntersection = 391,
     tBooleanDifference = 392,
     tBooleanSection = 393,
     tBooleanFragments = 394,
     tThickSolid = 395,
     tRecombine = 396,
     tSmoother = 397,
     tSplit = 398,
     tDelete = 399,
     tCoherence = 400,
     tIntersect = 401,
     tMeshAlgorithm = 402,
     tReverse = 403,
     tLayers = 404,
     tScaleLast = 405,
     tHole = 406,
     tAlias = 407,
     tAliasWithOptions = 408,
     tCopyOptions = 409,
     tQuadTriAddVerts = 410,
     tQuadTriNoNewVerts = 411,
     tRecombLaterals = 412,
     tTransfQuadTri = 413,
     tText2D = 414,
     tText3D = 415,
     tInterpolationScheme = 416,
     tTime = 417,
     tCombine = 418,
     tBSpline = 419,
     tBezier = 420,
     tNurbs = 421,
     tNurbsOrder = 422,
     tNurbsKnots = 423,
     tColor = 424,
     tColorTable = 425,
     tFor = 426,
     tIn = 427,
     tEndFor = 428,
     tIf = 429,
     tElseIf = 430,
     tElse = 431,
     tEndIf = 432,
     tExit = 433,
     tAbort = 434,
     tField = 435,
     tReturn = 436,
     tCall = 437,
     tSlide = 438,
     tMacro = 439,
     tShow = 440,
     tHide = 441,
     tGetValue = 442,
     tGetStringValue = 443,
     tGetEnv = 444,
     tGetString = 445,
     tGetNumber = 446,
     tUnique = 447,
     tHomology = 448,
     tCohomology = 449,
     tBetti = 450,
     tExists = 451,
     tFileExists = 452,
     tGMSH_MAJOR_VERSION = 453,
     tGMSH_MINOR_VERSION = 454,
     tGMSH_PATCH_VERSION = 455,
     tGmshExecutableName = 456,
     tSetPartition = 457,
     tNameToString = 458,
     tStringToName = 459,
     tAFFECTDIVIDE = 460,
     tAFFECTTIMES = 461,
     tAFFECTMINUS = 462,
     tAFFECTPLUS = 463,
     tOR = 464,
     tAND = 465,
     tNOTEQUAL = 466,
     tEQUAL = 467,
     tGREATEROREQUAL = 468,
     tLESSOREQUAL = 469,
     UNARYPREC = 470,
     tMINUSMINUS = 471,
     tPLUSPLUS = 472
   };
#endif
/* Tokens.  */
#define tDOUBLE 258
#define tSTRING 259
#define tBIGSTR 260
#define tEND 261
#define tAFFECT 262
#define tDOTS 263
#define tPi 264
#define tMPI_Rank 265
#define tMPI_Size 266
#define tEuclidian 267
#define tCoordinates 268
#define tTestLevel 269
#define tExp 270
#define tLog 271
#define tLog10 272
#define tSqrt 273
#define tSin 274
#define tAsin 275
#define tCos 276
#define tAcos 277
#define tTan 278
#define tRand 279
#define tAtan 280
#define tAtan2 281
#define tSinh 282
#define tCosh 283
#define tTanh 284
#define tFabs 285
#define tFloor 286
#define tCeil 287
#define tRound 288
#define tFmod 289
#define tModulo 290
#define tHypot 291
#define tList 292
#define tLinSpace 293
#define tLogSpace 294
#define tListFromFile 295
#define tCatenary 296
#define tPrintf 297
#define tError 298
#define tStr 299
#define tSprintf 300
#define tStrCat 301
#define tStrPrefix 302
#define tStrRelative 303
#define tStrReplace 304
#define tAbsolutePath 305
#define tDirName 306
#define tStrSub 307
#define tStrLen 308
#define tFind 309
#define tStrFind 310
#define tStrCmp 311
#define tStrChoice 312
#define tUpperCase 313
#define tLowerCase 314
#define tLowerCaseIn 315
#define tTextAttributes 316
#define tBoundingBox 317
#define tDraw 318
#define tSetChanged 319
#define tToday 320
#define tFixRelativePath 321
#define tCurrentDirectory 322
#define tSyncModel 323
#define tNewModel 324
#define tOnelabAction 325
#define tOnelabRun 326
#define tCpu 327
#define tMemory 328
#define tTotalMemory 329
#define tCreateTopology 330
#define tCreateTopologyNoHoles 331
#define tDistanceFunction 332
#define tDefineConstant 333
#define tUndefineConstant 334
#define tDefineNumber 335
#define tDefineStruct 336
#define tNameStruct 337
#define tDefineString 338
#define tSetNumber 339
#define tSetString 340
#define tPoint 341
#define tCircle 342
#define tEllipse 343
#define tLine 344
#define tSphere 345
#define tPolarSphere 346
#define tSurface 347
#define tSpline 348
#define tVolume 349
#define tBlock 350
#define tCylinder 351
#define tCone 352
#define tTorus 353
#define tEllipsoid 354
#define tQuadric 355
#define tShapeFromFile 356
#define tRectangle 357
#define tDisk 358
#define tWire 359
#define tCharacteristic 360
#define tLength 361
#define tParametric 362
#define tElliptic 363
#define tRefineMesh 364
#define tAdaptMesh 365
#define tRelocateMesh 366
#define tSetFactory 367
#define tThruSections 368
#define tWedge 369
#define tFillet 370
#define tChamfer 371
#define tPlane 372
#define tRuled 373
#define tTransfinite 374
#define tComplex 375
#define tPhysical 376
#define tCompound 377
#define tPeriodic 378
#define tUsing 379
#define tPlugin 380
#define tDegenerated 381
#define tRecursive 382
#define tRotate 383
#define tTranslate 384
#define tSymmetry 385
#define tDilate 386
#define tExtrude 387
#define tLevelset 388
#define tAffine 389
#define tBooleanUnion 390
#define tBooleanIntersection 391
#define tBooleanDifference 392
#define tBooleanSection 393
#define tBooleanFragments 394
#define tThickSolid 395
#define tRecombine 396
#define tSmoother 397
#define tSplit 398
#define tDelete 399
#define tCoherence 400
#define tIntersect 401
#define tMeshAlgorithm 402
#define tReverse 403
#define tLayers 404
#define tScaleLast 405
#define tHole 406
#define tAlias 407
#define tAliasWithOptions 408
#define tCopyOptions 409
#define tQuadTriAddVerts 410
#define tQuadTriNoNewVerts 411
#define tRecombLaterals 412
#define tTransfQuadTri 413
#define tText2D 414
#define tText3D 415
#define tInterpolationScheme 416
#define tTime 417
#define tCombine 418
#define tBSpline 419
#define tBezier 420
#define tNurbs 421
#define tNurbsOrder 422
#define tNurbsKnots 423
#define tColor 424
#define tColorTable 425
#define tFor 426
#define tIn 427
#define tEndFor 428
#define tIf 429
#define tElseIf 430
#define tElse 431
#define tEndIf 432
#define tExit 433
#define tAbort 434
#define tField 435
#define tReturn 436
#define tCall 437
#define tSlide 438
#define tMacro 439
#define tShow 440
#define tHide 441
#define tGetValue 442
#define tGetStringValue 443
#define tGetEnv 444
#define tGetString 445
#define tGetNumber 446
#define tUnique 447
#define tHomology 448
#define tCohomology 449
#define tBetti 450
#define tExists 451
#define tFileExists 452
#define tGMSH_MAJOR_VERSION 453
#define tGMSH_MINOR_VERSION 454
#define tGMSH_PATCH_VERSION 455
#define tGmshExecutableName 456
#define tSetPartition 457
#define tNameToString 458
#define tStringToName 459
#define tAFFECTDIVIDE 460
#define tAFFECTTIMES 461
#define tAFFECTMINUS 462
#define tAFFECTPLUS 463
#define tOR 464
#define tAND 465
#define tNOTEQUAL 466
#define tEQUAL 467
#define tGREATEROREQUAL 468
#define tLESSOREQUAL 469
#define UNARYPREC 470
#define tMINUSMINUS 471
#define tPLUSPLUS 472




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 124 "Gmsh.y"
{
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
}
/* Line 1529 of yacc.c.  */
#line 493 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

