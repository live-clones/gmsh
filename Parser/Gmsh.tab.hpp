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
     tDefineString = 336,
     tSetNumber = 337,
     tSetString = 338,
     tPoint = 339,
     tCircle = 340,
     tEllipse = 341,
     tLine = 342,
     tSphere = 343,
     tPolarSphere = 344,
     tSurface = 345,
     tSpline = 346,
     tVolume = 347,
     tBlock = 348,
     tCylinder = 349,
     tCone = 350,
     tTorus = 351,
     tEllipsoid = 352,
     tQuadric = 353,
     tShapeFromFile = 354,
     tRectangle = 355,
     tDisk = 356,
     tCharacteristic = 357,
     tLength = 358,
     tParametric = 359,
     tElliptic = 360,
     tRefineMesh = 361,
     tAdaptMesh = 362,
     tRelocateMesh = 363,
     tSetFactory = 364,
     tThruSections = 365,
     tWedge = 366,
     tFillet = 367,
     tChamfer = 368,
     tPlane = 369,
     tRuled = 370,
     tTransfinite = 371,
     tComplex = 372,
     tPhysical = 373,
     tCompound = 374,
     tPeriodic = 375,
     tUsing = 376,
     tPlugin = 377,
     tDegenerated = 378,
     tRecursive = 379,
     tRotate = 380,
     tTranslate = 381,
     tSymmetry = 382,
     tDilate = 383,
     tExtrude = 384,
     tLevelset = 385,
     tAffine = 386,
     tBooleanUnion = 387,
     tBooleanIntersection = 388,
     tBooleanDifference = 389,
     tBooleanSection = 390,
     tBooleanFragments = 391,
     tThickSolid = 392,
     tRecombine = 393,
     tSmoother = 394,
     tSplit = 395,
     tDelete = 396,
     tCoherence = 397,
     tIntersect = 398,
     tMeshAlgorithm = 399,
     tReverse = 400,
     tLayers = 401,
     tScaleLast = 402,
     tHole = 403,
     tAlias = 404,
     tAliasWithOptions = 405,
     tCopyOptions = 406,
     tQuadTriAddVerts = 407,
     tQuadTriNoNewVerts = 408,
     tQuadTriSngl = 409,
     tQuadTriDbl = 410,
     tRecombLaterals = 411,
     tTransfQuadTri = 412,
     tText2D = 413,
     tText3D = 414,
     tInterpolationScheme = 415,
     tTime = 416,
     tCombine = 417,
     tBSpline = 418,
     tBezier = 419,
     tNurbs = 420,
     tNurbsOrder = 421,
     tNurbsKnots = 422,
     tColor = 423,
     tColorTable = 424,
     tFor = 425,
     tIn = 426,
     tEndFor = 427,
     tIf = 428,
     tElseIf = 429,
     tElse = 430,
     tEndIf = 431,
     tExit = 432,
     tAbort = 433,
     tField = 434,
     tReturn = 435,
     tCall = 436,
     tSlide = 437,
     tMacro = 438,
     tShow = 439,
     tHide = 440,
     tGetValue = 441,
     tGetStringValue = 442,
     tGetEnv = 443,
     tGetString = 444,
     tGetNumber = 445,
     tUnique = 446,
     tHomology = 447,
     tCohomology = 448,
     tBetti = 449,
     tExists = 450,
     tFileExists = 451,
     tGMSH_MAJOR_VERSION = 452,
     tGMSH_MINOR_VERSION = 453,
     tGMSH_PATCH_VERSION = 454,
     tGmshExecutableName = 455,
     tSetPartition = 456,
     tNameToString = 457,
     tStringToName = 458,
     tAFFECTDIVIDE = 459,
     tAFFECTTIMES = 460,
     tAFFECTMINUS = 461,
     tAFFECTPLUS = 462,
     tOR = 463,
     tAND = 464,
     tNOTEQUAL = 465,
     tEQUAL = 466,
     tGREATEROREQUAL = 467,
     tLESSOREQUAL = 468,
     UNARYPREC = 469,
     tMINUSMINUS = 470,
     tPLUSPLUS = 471
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
#define tDefineString 336
#define tSetNumber 337
#define tSetString 338
#define tPoint 339
#define tCircle 340
#define tEllipse 341
#define tLine 342
#define tSphere 343
#define tPolarSphere 344
#define tSurface 345
#define tSpline 346
#define tVolume 347
#define tBlock 348
#define tCylinder 349
#define tCone 350
#define tTorus 351
#define tEllipsoid 352
#define tQuadric 353
#define tShapeFromFile 354
#define tRectangle 355
#define tDisk 356
#define tCharacteristic 357
#define tLength 358
#define tParametric 359
#define tElliptic 360
#define tRefineMesh 361
#define tAdaptMesh 362
#define tRelocateMesh 363
#define tSetFactory 364
#define tThruSections 365
#define tWedge 366
#define tFillet 367
#define tChamfer 368
#define tPlane 369
#define tRuled 370
#define tTransfinite 371
#define tComplex 372
#define tPhysical 373
#define tCompound 374
#define tPeriodic 375
#define tUsing 376
#define tPlugin 377
#define tDegenerated 378
#define tRecursive 379
#define tRotate 380
#define tTranslate 381
#define tSymmetry 382
#define tDilate 383
#define tExtrude 384
#define tLevelset 385
#define tAffine 386
#define tBooleanUnion 387
#define tBooleanIntersection 388
#define tBooleanDifference 389
#define tBooleanSection 390
#define tBooleanFragments 391
#define tThickSolid 392
#define tRecombine 393
#define tSmoother 394
#define tSplit 395
#define tDelete 396
#define tCoherence 397
#define tIntersect 398
#define tMeshAlgorithm 399
#define tReverse 400
#define tLayers 401
#define tScaleLast 402
#define tHole 403
#define tAlias 404
#define tAliasWithOptions 405
#define tCopyOptions 406
#define tQuadTriAddVerts 407
#define tQuadTriNoNewVerts 408
#define tQuadTriSngl 409
#define tQuadTriDbl 410
#define tRecombLaterals 411
#define tTransfQuadTri 412
#define tText2D 413
#define tText3D 414
#define tInterpolationScheme 415
#define tTime 416
#define tCombine 417
#define tBSpline 418
#define tBezier 419
#define tNurbs 420
#define tNurbsOrder 421
#define tNurbsKnots 422
#define tColor 423
#define tColorTable 424
#define tFor 425
#define tIn 426
#define tEndFor 427
#define tIf 428
#define tElseIf 429
#define tElse 430
#define tEndIf 431
#define tExit 432
#define tAbort 433
#define tField 434
#define tReturn 435
#define tCall 436
#define tSlide 437
#define tMacro 438
#define tShow 439
#define tHide 440
#define tGetValue 441
#define tGetStringValue 442
#define tGetEnv 443
#define tGetString 444
#define tGetNumber 445
#define tUnique 446
#define tHomology 447
#define tCohomology 448
#define tBetti 449
#define tExists 450
#define tFileExists 451
#define tGMSH_MAJOR_VERSION 452
#define tGMSH_MINOR_VERSION 453
#define tGMSH_PATCH_VERSION 454
#define tGmshExecutableName 455
#define tSetPartition 456
#define tNameToString 457
#define tStringToName 458
#define tAFFECTDIVIDE 459
#define tAFFECTTIMES 460
#define tAFFECTMINUS 461
#define tAFFECTPLUS 462
#define tOR 463
#define tAND 464
#define tNOTEQUAL 465
#define tEQUAL 466
#define tGREATEROREQUAL 467
#define tLESSOREQUAL 468
#define UNARYPREC 469
#define tMINUSMINUS 470
#define tPLUSPLUS 471




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 117 "Gmsh.y"
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
#line 491 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

