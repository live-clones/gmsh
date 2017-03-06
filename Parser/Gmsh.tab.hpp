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
     tCpu = 329,
     tMemory = 330,
     tTotalMemory = 331,
     tCreateTopology = 332,
     tCreateTopologyNoHoles = 333,
     tDistanceFunction = 334,
     tDefineConstant = 335,
     tUndefineConstant = 336,
     tDefineNumber = 337,
     tDefineStruct = 338,
     tNameStruct = 339,
     tAppend = 340,
     tDefineString = 341,
     tSetNumber = 342,
     tSetString = 343,
     tPoint = 344,
     tCircle = 345,
     tEllipse = 346,
     tLine = 347,
     tSphere = 348,
     tPolarSphere = 349,
     tSurface = 350,
     tSpline = 351,
     tVolume = 352,
     tBlock = 353,
     tCylinder = 354,
     tCone = 355,
     tTorus = 356,
     tEllipsoid = 357,
     tQuadric = 358,
     tShapeFromFile = 359,
     tRectangle = 360,
     tDisk = 361,
     tWire = 362,
     tCharacteristic = 363,
     tLength = 364,
     tParametric = 365,
     tElliptic = 366,
     tRefineMesh = 367,
     tAdaptMesh = 368,
     tRelocateMesh = 369,
     tSetFactory = 370,
     tThruSections = 371,
     tWedge = 372,
     tFillet = 373,
     tChamfer = 374,
     tPlane = 375,
     tRuled = 376,
     tTransfinite = 377,
     tPhysical = 378,
     tCompound = 379,
     tPeriodic = 380,
     tUsing = 381,
     tPlugin = 382,
     tDegenerated = 383,
     tRecursive = 384,
     tRotate = 385,
     tTranslate = 386,
     tSymmetry = 387,
     tDilate = 388,
     tExtrude = 389,
     tLevelset = 390,
     tAffine = 391,
     tBooleanUnion = 392,
     tBooleanIntersection = 393,
     tBooleanDifference = 394,
     tBooleanSection = 395,
     tBooleanFragments = 396,
     tThickSolid = 397,
     tRecombine = 398,
     tSmoother = 399,
     tSplit = 400,
     tDelete = 401,
     tCoherence = 402,
     tIntersect = 403,
     tMeshAlgorithm = 404,
     tReverse = 405,
     tLayers = 406,
     tScaleLast = 407,
     tHole = 408,
     tAlias = 409,
     tAliasWithOptions = 410,
     tCopyOptions = 411,
     tQuadTriAddVerts = 412,
     tQuadTriNoNewVerts = 413,
     tRecombLaterals = 414,
     tTransfQuadTri = 415,
     tText2D = 416,
     tText3D = 417,
     tInterpolationScheme = 418,
     tTime = 419,
     tCombine = 420,
     tBSpline = 421,
     tBezier = 422,
     tNurbs = 423,
     tNurbsOrder = 424,
     tNurbsKnots = 425,
     tColor = 426,
     tColorTable = 427,
     tFor = 428,
     tIn = 429,
     tEndFor = 430,
     tIf = 431,
     tElseIf = 432,
     tElse = 433,
     tEndIf = 434,
     tExit = 435,
     tAbort = 436,
     tField = 437,
     tReturn = 438,
     tCall = 439,
     tSlide = 440,
     tMacro = 441,
     tShow = 442,
     tHide = 443,
     tGetValue = 444,
     tGetStringValue = 445,
     tGetEnv = 446,
     tGetString = 447,
     tGetNumber = 448,
     tUnique = 449,
     tHomology = 450,
     tCohomology = 451,
     tBetti = 452,
     tExists = 453,
     tFileExists = 454,
     tGMSH_MAJOR_VERSION = 455,
     tGMSH_MINOR_VERSION = 456,
     tGMSH_PATCH_VERSION = 457,
     tGmshExecutableName = 458,
     tSetPartition = 459,
     tNameToString = 460,
     tStringToName = 461,
     tAFFECTDIVIDE = 462,
     tAFFECTTIMES = 463,
     tAFFECTMINUS = 464,
     tAFFECTPLUS = 465,
     tOR = 466,
     tAND = 467,
     tNOTEQUAL = 468,
     tEQUAL = 469,
     tGREATEROREQUAL = 470,
     tLESSOREQUAL = 471,
     UNARYPREC = 472,
     tMINUSMINUS = 473,
     tPLUSPLUS = 474
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
#define tCpu 329
#define tMemory 330
#define tTotalMemory 331
#define tCreateTopology 332
#define tCreateTopologyNoHoles 333
#define tDistanceFunction 334
#define tDefineConstant 335
#define tUndefineConstant 336
#define tDefineNumber 337
#define tDefineStruct 338
#define tNameStruct 339
#define tAppend 340
#define tDefineString 341
#define tSetNumber 342
#define tSetString 343
#define tPoint 344
#define tCircle 345
#define tEllipse 346
#define tLine 347
#define tSphere 348
#define tPolarSphere 349
#define tSurface 350
#define tSpline 351
#define tVolume 352
#define tBlock 353
#define tCylinder 354
#define tCone 355
#define tTorus 356
#define tEllipsoid 357
#define tQuadric 358
#define tShapeFromFile 359
#define tRectangle 360
#define tDisk 361
#define tWire 362
#define tCharacteristic 363
#define tLength 364
#define tParametric 365
#define tElliptic 366
#define tRefineMesh 367
#define tAdaptMesh 368
#define tRelocateMesh 369
#define tSetFactory 370
#define tThruSections 371
#define tWedge 372
#define tFillet 373
#define tChamfer 374
#define tPlane 375
#define tRuled 376
#define tTransfinite 377
#define tPhysical 378
#define tCompound 379
#define tPeriodic 380
#define tUsing 381
#define tPlugin 382
#define tDegenerated 383
#define tRecursive 384
#define tRotate 385
#define tTranslate 386
#define tSymmetry 387
#define tDilate 388
#define tExtrude 389
#define tLevelset 390
#define tAffine 391
#define tBooleanUnion 392
#define tBooleanIntersection 393
#define tBooleanDifference 394
#define tBooleanSection 395
#define tBooleanFragments 396
#define tThickSolid 397
#define tRecombine 398
#define tSmoother 399
#define tSplit 400
#define tDelete 401
#define tCoherence 402
#define tIntersect 403
#define tMeshAlgorithm 404
#define tReverse 405
#define tLayers 406
#define tScaleLast 407
#define tHole 408
#define tAlias 409
#define tAliasWithOptions 410
#define tCopyOptions 411
#define tQuadTriAddVerts 412
#define tQuadTriNoNewVerts 413
#define tRecombLaterals 414
#define tTransfQuadTri 415
#define tText2D 416
#define tText3D 417
#define tInterpolationScheme 418
#define tTime 419
#define tCombine 420
#define tBSpline 421
#define tBezier 422
#define tNurbs 423
#define tNurbsOrder 424
#define tNurbsKnots 425
#define tColor 426
#define tColorTable 427
#define tFor 428
#define tIn 429
#define tEndFor 430
#define tIf 431
#define tElseIf 432
#define tElse 433
#define tEndIf 434
#define tExit 435
#define tAbort 436
#define tField 437
#define tReturn 438
#define tCall 439
#define tSlide 440
#define tMacro 441
#define tShow 442
#define tHide 443
#define tGetValue 444
#define tGetStringValue 445
#define tGetEnv 446
#define tGetString 447
#define tGetNumber 448
#define tUnique 449
#define tHomology 450
#define tCohomology 451
#define tBetti 452
#define tExists 453
#define tFileExists 454
#define tGMSH_MAJOR_VERSION 455
#define tGMSH_MINOR_VERSION 456
#define tGMSH_PATCH_VERSION 457
#define tGmshExecutableName 458
#define tSetPartition 459
#define tNameToString 460
#define tStringToName 461
#define tAFFECTDIVIDE 462
#define tAFFECTTIMES 463
#define tAFFECTMINUS 464
#define tAFFECTPLUS 465
#define tOR 466
#define tAND 467
#define tNOTEQUAL 468
#define tEQUAL 469
#define tGREATEROREQUAL 470
#define tLESSOREQUAL 471
#define UNARYPREC 472
#define tMINUSMINUS 473
#define tPLUSPLUS 474




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 147 "Gmsh.y"
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
#line 498 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

