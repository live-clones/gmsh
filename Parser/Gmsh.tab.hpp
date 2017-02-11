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
     tPipe = 366,
     tPlane = 367,
     tRuled = 368,
     tTransfinite = 369,
     tComplex = 370,
     tPhysical = 371,
     tCompound = 372,
     tPeriodic = 373,
     tUsing = 374,
     tPlugin = 375,
     tDegenerated = 376,
     tRecursive = 377,
     tRotate = 378,
     tTranslate = 379,
     tSymmetry = 380,
     tDilate = 381,
     tExtrude = 382,
     tLevelset = 383,
     tAffine = 384,
     tBooleanUnion = 385,
     tBooleanIntersection = 386,
     tBooleanDifference = 387,
     tBooleanSection = 388,
     tBooleanFragments = 389,
     tRecombine = 390,
     tSmoother = 391,
     tSplit = 392,
     tDelete = 393,
     tCoherence = 394,
     tIntersect = 395,
     tMeshAlgorithm = 396,
     tReverse = 397,
     tLayers = 398,
     tScaleLast = 399,
     tHole = 400,
     tAlias = 401,
     tAliasWithOptions = 402,
     tCopyOptions = 403,
     tQuadTriAddVerts = 404,
     tQuadTriNoNewVerts = 405,
     tQuadTriSngl = 406,
     tQuadTriDbl = 407,
     tRecombLaterals = 408,
     tTransfQuadTri = 409,
     tText2D = 410,
     tText3D = 411,
     tInterpolationScheme = 412,
     tTime = 413,
     tCombine = 414,
     tBSpline = 415,
     tBezier = 416,
     tNurbs = 417,
     tNurbsOrder = 418,
     tNurbsKnots = 419,
     tColor = 420,
     tColorTable = 421,
     tFor = 422,
     tIn = 423,
     tEndFor = 424,
     tIf = 425,
     tElseIf = 426,
     tElse = 427,
     tEndIf = 428,
     tExit = 429,
     tAbort = 430,
     tField = 431,
     tReturn = 432,
     tCall = 433,
     tSlide = 434,
     tMacro = 435,
     tShow = 436,
     tHide = 437,
     tGetValue = 438,
     tGetStringValue = 439,
     tGetEnv = 440,
     tGetString = 441,
     tGetNumber = 442,
     tHomology = 443,
     tCohomology = 444,
     tBetti = 445,
     tExists = 446,
     tFileExists = 447,
     tGMSH_MAJOR_VERSION = 448,
     tGMSH_MINOR_VERSION = 449,
     tGMSH_PATCH_VERSION = 450,
     tGmshExecutableName = 451,
     tSetPartition = 452,
     tNameToString = 453,
     tStringToName = 454,
     tAFFECTDIVIDE = 455,
     tAFFECTTIMES = 456,
     tAFFECTMINUS = 457,
     tAFFECTPLUS = 458,
     tOR = 459,
     tAND = 460,
     tNOTEQUAL = 461,
     tEQUAL = 462,
     tGREATEROREQUAL = 463,
     tLESSOREQUAL = 464,
     UNARYPREC = 465,
     tMINUSMINUS = 466,
     tPLUSPLUS = 467
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
#define tPipe 366
#define tPlane 367
#define tRuled 368
#define tTransfinite 369
#define tComplex 370
#define tPhysical 371
#define tCompound 372
#define tPeriodic 373
#define tUsing 374
#define tPlugin 375
#define tDegenerated 376
#define tRecursive 377
#define tRotate 378
#define tTranslate 379
#define tSymmetry 380
#define tDilate 381
#define tExtrude 382
#define tLevelset 383
#define tAffine 384
#define tBooleanUnion 385
#define tBooleanIntersection 386
#define tBooleanDifference 387
#define tBooleanSection 388
#define tBooleanFragments 389
#define tRecombine 390
#define tSmoother 391
#define tSplit 392
#define tDelete 393
#define tCoherence 394
#define tIntersect 395
#define tMeshAlgorithm 396
#define tReverse 397
#define tLayers 398
#define tScaleLast 399
#define tHole 400
#define tAlias 401
#define tAliasWithOptions 402
#define tCopyOptions 403
#define tQuadTriAddVerts 404
#define tQuadTriNoNewVerts 405
#define tQuadTriSngl 406
#define tQuadTriDbl 407
#define tRecombLaterals 408
#define tTransfQuadTri 409
#define tText2D 410
#define tText3D 411
#define tInterpolationScheme 412
#define tTime 413
#define tCombine 414
#define tBSpline 415
#define tBezier 416
#define tNurbs 417
#define tNurbsOrder 418
#define tNurbsKnots 419
#define tColor 420
#define tColorTable 421
#define tFor 422
#define tIn 423
#define tEndFor 424
#define tIf 425
#define tElseIf 426
#define tElse 427
#define tEndIf 428
#define tExit 429
#define tAbort 430
#define tField 431
#define tReturn 432
#define tCall 433
#define tSlide 434
#define tMacro 435
#define tShow 436
#define tHide 437
#define tGetValue 438
#define tGetStringValue 439
#define tGetEnv 440
#define tGetString 441
#define tGetNumber 442
#define tHomology 443
#define tCohomology 444
#define tBetti 445
#define tExists 446
#define tFileExists 447
#define tGMSH_MAJOR_VERSION 448
#define tGMSH_MINOR_VERSION 449
#define tGMSH_PATCH_VERSION 450
#define tGmshExecutableName 451
#define tSetPartition 452
#define tNameToString 453
#define tStringToName 454
#define tAFFECTDIVIDE 455
#define tAFFECTTIMES 456
#define tAFFECTMINUS 457
#define tAFFECTPLUS 458
#define tOR 459
#define tAND 460
#define tNOTEQUAL 461
#define tEQUAL 462
#define tGREATEROREQUAL 463
#define tLESSOREQUAL 464
#define UNARYPREC 465
#define tMINUSMINUS 466
#define tPLUSPLUS 467




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
#line 483 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

