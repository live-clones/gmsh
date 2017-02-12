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
     tPlane = 367,
     tRuled = 368,
     tTransfinite = 369,
     tComplex = 370,
     tPhysical = 371,
     tCompound = 372,
     tPeriodic = 373,
     tUsing = 374,
     tNotUsing = 375,
     tPlugin = 376,
     tDegenerated = 377,
     tRecursive = 378,
     tRotate = 379,
     tTranslate = 380,
     tSymmetry = 381,
     tDilate = 382,
     tExtrude = 383,
     tLevelset = 384,
     tAffine = 385,
     tBooleanUnion = 386,
     tBooleanIntersection = 387,
     tBooleanDifference = 388,
     tBooleanSection = 389,
     tBooleanFragments = 390,
     tThickSolid = 391,
     tRecombine = 392,
     tSmoother = 393,
     tSplit = 394,
     tDelete = 395,
     tCoherence = 396,
     tIntersect = 397,
     tMeshAlgorithm = 398,
     tReverse = 399,
     tLayers = 400,
     tScaleLast = 401,
     tHole = 402,
     tAlias = 403,
     tAliasWithOptions = 404,
     tCopyOptions = 405,
     tQuadTriAddVerts = 406,
     tQuadTriNoNewVerts = 407,
     tQuadTriSngl = 408,
     tQuadTriDbl = 409,
     tRecombLaterals = 410,
     tTransfQuadTri = 411,
     tText2D = 412,
     tText3D = 413,
     tInterpolationScheme = 414,
     tTime = 415,
     tCombine = 416,
     tBSpline = 417,
     tBezier = 418,
     tNurbs = 419,
     tNurbsOrder = 420,
     tNurbsKnots = 421,
     tColor = 422,
     tColorTable = 423,
     tFor = 424,
     tIn = 425,
     tEndFor = 426,
     tIf = 427,
     tElseIf = 428,
     tElse = 429,
     tEndIf = 430,
     tExit = 431,
     tAbort = 432,
     tField = 433,
     tReturn = 434,
     tCall = 435,
     tSlide = 436,
     tMacro = 437,
     tShow = 438,
     tHide = 439,
     tGetValue = 440,
     tGetStringValue = 441,
     tGetEnv = 442,
     tGetString = 443,
     tGetNumber = 444,
     tHomology = 445,
     tCohomology = 446,
     tBetti = 447,
     tExists = 448,
     tFileExists = 449,
     tGMSH_MAJOR_VERSION = 450,
     tGMSH_MINOR_VERSION = 451,
     tGMSH_PATCH_VERSION = 452,
     tGmshExecutableName = 453,
     tSetPartition = 454,
     tNameToString = 455,
     tStringToName = 456,
     tAFFECTDIVIDE = 457,
     tAFFECTTIMES = 458,
     tAFFECTMINUS = 459,
     tAFFECTPLUS = 460,
     tOR = 461,
     tAND = 462,
     tNOTEQUAL = 463,
     tEQUAL = 464,
     tGREATEROREQUAL = 465,
     tLESSOREQUAL = 466,
     UNARYPREC = 467,
     tMINUSMINUS = 468,
     tPLUSPLUS = 469
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
#define tPlane 367
#define tRuled 368
#define tTransfinite 369
#define tComplex 370
#define tPhysical 371
#define tCompound 372
#define tPeriodic 373
#define tUsing 374
#define tNotUsing 375
#define tPlugin 376
#define tDegenerated 377
#define tRecursive 378
#define tRotate 379
#define tTranslate 380
#define tSymmetry 381
#define tDilate 382
#define tExtrude 383
#define tLevelset 384
#define tAffine 385
#define tBooleanUnion 386
#define tBooleanIntersection 387
#define tBooleanDifference 388
#define tBooleanSection 389
#define tBooleanFragments 390
#define tThickSolid 391
#define tRecombine 392
#define tSmoother 393
#define tSplit 394
#define tDelete 395
#define tCoherence 396
#define tIntersect 397
#define tMeshAlgorithm 398
#define tReverse 399
#define tLayers 400
#define tScaleLast 401
#define tHole 402
#define tAlias 403
#define tAliasWithOptions 404
#define tCopyOptions 405
#define tQuadTriAddVerts 406
#define tQuadTriNoNewVerts 407
#define tQuadTriSngl 408
#define tQuadTriDbl 409
#define tRecombLaterals 410
#define tTransfQuadTri 411
#define tText2D 412
#define tText3D 413
#define tInterpolationScheme 414
#define tTime 415
#define tCombine 416
#define tBSpline 417
#define tBezier 418
#define tNurbs 419
#define tNurbsOrder 420
#define tNurbsKnots 421
#define tColor 422
#define tColorTable 423
#define tFor 424
#define tIn 425
#define tEndFor 426
#define tIf 427
#define tElseIf 428
#define tElse 429
#define tEndIf 430
#define tExit 431
#define tAbort 432
#define tField 433
#define tReturn 434
#define tCall 435
#define tSlide 436
#define tMacro 437
#define tShow 438
#define tHide 439
#define tGetValue 440
#define tGetStringValue 441
#define tGetEnv 442
#define tGetString 443
#define tGetNumber 444
#define tHomology 445
#define tCohomology 446
#define tBetti 447
#define tExists 448
#define tFileExists 449
#define tGMSH_MAJOR_VERSION 450
#define tGMSH_MINOR_VERSION 451
#define tGMSH_PATCH_VERSION 452
#define tGmshExecutableName 453
#define tSetPartition 454
#define tNameToString 455
#define tStringToName 456
#define tAFFECTDIVIDE 457
#define tAFFECTTIMES 458
#define tAFFECTMINUS 459
#define tAFFECTPLUS 460
#define tOR 461
#define tAND 462
#define tNOTEQUAL 463
#define tEQUAL 464
#define tGREATEROREQUAL 465
#define tLESSOREQUAL 466
#define UNARYPREC 467
#define tMINUSMINUS 468
#define tPLUSPLUS 469




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
#line 487 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

