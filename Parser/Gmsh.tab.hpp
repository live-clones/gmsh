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
     tFloor = 287,
     tCeil = 288,
     tRound = 289,
     tFmod = 290,
     tModulo = 291,
     tHypot = 292,
     tList = 293,
     tLinSpace = 294,
     tLogSpace = 295,
     tListFromFile = 296,
     tCatenary = 297,
     tPrintf = 298,
     tError = 299,
     tStr = 300,
     tSprintf = 301,
     tStrCat = 302,
     tStrPrefix = 303,
     tStrRelative = 304,
     tStrReplace = 305,
     tAbsolutePath = 306,
     tDirName = 307,
     tStrSub = 308,
     tStrLen = 309,
     tFind = 310,
     tStrFind = 311,
     tStrCmp = 312,
     tStrChoice = 313,
     tUpperCase = 314,
     tLowerCase = 315,
     tLowerCaseIn = 316,
     tTextAttributes = 317,
     tBoundingBox = 318,
     tDraw = 319,
     tSetChanged = 320,
     tToday = 321,
     tFixRelativePath = 322,
     tCurrentDirectory = 323,
     tSyncModel = 324,
     tNewModel = 325,
     tOnelabAction = 326,
     tOnelabRun = 327,
     tCpu = 328,
     tMemory = 329,
     tTotalMemory = 330,
     tCreateTopology = 331,
     tCreateTopologyNoHoles = 332,
     tDistanceFunction = 333,
     tDefineConstant = 334,
     tUndefineConstant = 335,
     tDefineNumber = 336,
     tDefineStruct = 337,
     tNameStruct = 338,
     tAppend = 339,
     tDefineString = 340,
     tSetNumber = 341,
     tSetString = 342,
     tPoint = 343,
     tCircle = 344,
     tEllipse = 345,
     tLine = 346,
     tSphere = 347,
     tPolarSphere = 348,
     tSurface = 349,
     tSpline = 350,
     tVolume = 351,
     tBlock = 352,
     tCylinder = 353,
     tCone = 354,
     tTorus = 355,
     tEllipsoid = 356,
     tQuadric = 357,
     tShapeFromFile = 358,
     tRectangle = 359,
     tDisk = 360,
     tWire = 361,
     tCharacteristic = 362,
     tLength = 363,
     tParametric = 364,
     tElliptic = 365,
     tRefineMesh = 366,
     tAdaptMesh = 367,
     tRelocateMesh = 368,
     tSetFactory = 369,
     tThruSections = 370,
     tWedge = 371,
     tFillet = 372,
     tChamfer = 373,
     tPlane = 374,
     tRuled = 375,
     tTransfinite = 376,
     tPhysical = 377,
     tCompound = 378,
     tPeriodic = 379,
     tUsing = 380,
     tPlugin = 381,
     tDegenerated = 382,
     tRecursive = 383,
     tRotate = 384,
     tTranslate = 385,
     tSymmetry = 386,
     tDilate = 387,
     tExtrude = 388,
     tLevelset = 389,
     tAffine = 390,
     tBooleanUnion = 391,
     tBooleanIntersection = 392,
     tBooleanDifference = 393,
     tBooleanSection = 394,
     tBooleanFragments = 395,
     tThickSolid = 396,
     tRecombine = 397,
     tSmoother = 398,
     tSplit = 399,
     tDelete = 400,
     tCoherence = 401,
     tIntersect = 402,
     tMeshAlgorithm = 403,
     tReverse = 404,
     tLayers = 405,
     tScaleLast = 406,
     tHole = 407,
     tAlias = 408,
     tAliasWithOptions = 409,
     tCopyOptions = 410,
     tQuadTriAddVerts = 411,
     tQuadTriNoNewVerts = 412,
     tRecombLaterals = 413,
     tTransfQuadTri = 414,
     tText2D = 415,
     tText3D = 416,
     tInterpolationScheme = 417,
     tTime = 418,
     tCombine = 419,
     tBSpline = 420,
     tBezier = 421,
     tNurbs = 422,
     tNurbsOrder = 423,
     tNurbsKnots = 424,
     tColor = 425,
     tColorTable = 426,
     tFor = 427,
     tIn = 428,
     tEndFor = 429,
     tIf = 430,
     tElseIf = 431,
     tElse = 432,
     tEndIf = 433,
     tExit = 434,
     tAbort = 435,
     tField = 436,
     tReturn = 437,
     tCall = 438,
     tSlide = 439,
     tMacro = 440,
     tShow = 441,
     tHide = 442,
     tGetValue = 443,
     tGetStringValue = 444,
     tGetEnv = 445,
     tGetString = 446,
     tGetNumber = 447,
     tUnique = 448,
     tHomology = 449,
     tCohomology = 450,
     tBetti = 451,
     tExists = 452,
     tFileExists = 453,
     tGMSH_MAJOR_VERSION = 454,
     tGMSH_MINOR_VERSION = 455,
     tGMSH_PATCH_VERSION = 456,
     tGmshExecutableName = 457,
     tSetPartition = 458,
     tNameToString = 459,
     tStringToName = 460,
     tAFFECTDIVIDE = 461,
     tAFFECTTIMES = 462,
     tAFFECTMINUS = 463,
     tAFFECTPLUS = 464,
     tOR = 465,
     tAND = 466,
     tNOTEQUAL = 467,
     tEQUAL = 468,
     tGREATEROREQUAL = 469,
     tLESSOREQUAL = 470,
     UNARYPREC = 471,
     tMINUSMINUS = 472,
     tPLUSPLUS = 473
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
#define tFloor 287
#define tCeil 288
#define tRound 289
#define tFmod 290
#define tModulo 291
#define tHypot 292
#define tList 293
#define tLinSpace 294
#define tLogSpace 295
#define tListFromFile 296
#define tCatenary 297
#define tPrintf 298
#define tError 299
#define tStr 300
#define tSprintf 301
#define tStrCat 302
#define tStrPrefix 303
#define tStrRelative 304
#define tStrReplace 305
#define tAbsolutePath 306
#define tDirName 307
#define tStrSub 308
#define tStrLen 309
#define tFind 310
#define tStrFind 311
#define tStrCmp 312
#define tStrChoice 313
#define tUpperCase 314
#define tLowerCase 315
#define tLowerCaseIn 316
#define tTextAttributes 317
#define tBoundingBox 318
#define tDraw 319
#define tSetChanged 320
#define tToday 321
#define tFixRelativePath 322
#define tCurrentDirectory 323
#define tSyncModel 324
#define tNewModel 325
#define tOnelabAction 326
#define tOnelabRun 327
#define tCpu 328
#define tMemory 329
#define tTotalMemory 330
#define tCreateTopology 331
#define tCreateTopologyNoHoles 332
#define tDistanceFunction 333
#define tDefineConstant 334
#define tUndefineConstant 335
#define tDefineNumber 336
#define tDefineStruct 337
#define tNameStruct 338
#define tAppend 339
#define tDefineString 340
#define tSetNumber 341
#define tSetString 342
#define tPoint 343
#define tCircle 344
#define tEllipse 345
#define tLine 346
#define tSphere 347
#define tPolarSphere 348
#define tSurface 349
#define tSpline 350
#define tVolume 351
#define tBlock 352
#define tCylinder 353
#define tCone 354
#define tTorus 355
#define tEllipsoid 356
#define tQuadric 357
#define tShapeFromFile 358
#define tRectangle 359
#define tDisk 360
#define tWire 361
#define tCharacteristic 362
#define tLength 363
#define tParametric 364
#define tElliptic 365
#define tRefineMesh 366
#define tAdaptMesh 367
#define tRelocateMesh 368
#define tSetFactory 369
#define tThruSections 370
#define tWedge 371
#define tFillet 372
#define tChamfer 373
#define tPlane 374
#define tRuled 375
#define tTransfinite 376
#define tPhysical 377
#define tCompound 378
#define tPeriodic 379
#define tUsing 380
#define tPlugin 381
#define tDegenerated 382
#define tRecursive 383
#define tRotate 384
#define tTranslate 385
#define tSymmetry 386
#define tDilate 387
#define tExtrude 388
#define tLevelset 389
#define tAffine 390
#define tBooleanUnion 391
#define tBooleanIntersection 392
#define tBooleanDifference 393
#define tBooleanSection 394
#define tBooleanFragments 395
#define tThickSolid 396
#define tRecombine 397
#define tSmoother 398
#define tSplit 399
#define tDelete 400
#define tCoherence 401
#define tIntersect 402
#define tMeshAlgorithm 403
#define tReverse 404
#define tLayers 405
#define tScaleLast 406
#define tHole 407
#define tAlias 408
#define tAliasWithOptions 409
#define tCopyOptions 410
#define tQuadTriAddVerts 411
#define tQuadTriNoNewVerts 412
#define tRecombLaterals 413
#define tTransfQuadTri 414
#define tText2D 415
#define tText3D 416
#define tInterpolationScheme 417
#define tTime 418
#define tCombine 419
#define tBSpline 420
#define tBezier 421
#define tNurbs 422
#define tNurbsOrder 423
#define tNurbsKnots 424
#define tColor 425
#define tColorTable 426
#define tFor 427
#define tIn 428
#define tEndFor 429
#define tIf 430
#define tElseIf 431
#define tElse 432
#define tEndIf 433
#define tExit 434
#define tAbort 435
#define tField 436
#define tReturn 437
#define tCall 438
#define tSlide 439
#define tMacro 440
#define tShow 441
#define tHide 442
#define tGetValue 443
#define tGetStringValue 444
#define tGetEnv 445
#define tGetString 446
#define tGetNumber 447
#define tUnique 448
#define tHomology 449
#define tCohomology 450
#define tBetti 451
#define tExists 452
#define tFileExists 453
#define tGMSH_MAJOR_VERSION 454
#define tGMSH_MINOR_VERSION 455
#define tGMSH_PATCH_VERSION 456
#define tGmshExecutableName 457
#define tSetPartition 458
#define tNameToString 459
#define tStringToName 460
#define tAFFECTDIVIDE 461
#define tAFFECTTIMES 462
#define tAFFECTMINUS 463
#define tAFFECTPLUS 464
#define tOR 465
#define tAND 466
#define tNOTEQUAL 467
#define tEQUAL 468
#define tGREATEROREQUAL 469
#define tLESSOREQUAL 470
#define UNARYPREC 471
#define tMINUSMINUS 472
#define tPLUSPLUS 473




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 136 "Gmsh.y"
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
#line 496 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

