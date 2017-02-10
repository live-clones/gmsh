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
     tPlane = 366,
     tRuled = 367,
     tTransfinite = 368,
     tComplex = 369,
     tPhysical = 370,
     tCompound = 371,
     tPeriodic = 372,
     tUsing = 373,
     tPlugin = 374,
     tDegenerated = 375,
     tRecursive = 376,
     tRotate = 377,
     tTranslate = 378,
     tSymmetry = 379,
     tDilate = 380,
     tExtrude = 381,
     tLevelset = 382,
     tAffine = 383,
     tBooleanUnion = 384,
     tBooleanIntersection = 385,
     tBooleanDifference = 386,
     tBooleanSection = 387,
     tBooleanFragments = 388,
     tRecombine = 389,
     tSmoother = 390,
     tSplit = 391,
     tDelete = 392,
     tCoherence = 393,
     tIntersect = 394,
     tMeshAlgorithm = 395,
     tReverse = 396,
     tLayers = 397,
     tScaleLast = 398,
     tHole = 399,
     tAlias = 400,
     tAliasWithOptions = 401,
     tCopyOptions = 402,
     tQuadTriAddVerts = 403,
     tQuadTriNoNewVerts = 404,
     tQuadTriSngl = 405,
     tQuadTriDbl = 406,
     tRecombLaterals = 407,
     tTransfQuadTri = 408,
     tText2D = 409,
     tText3D = 410,
     tInterpolationScheme = 411,
     tTime = 412,
     tCombine = 413,
     tBSpline = 414,
     tBezier = 415,
     tNurbs = 416,
     tNurbsOrder = 417,
     tNurbsKnots = 418,
     tColor = 419,
     tColorTable = 420,
     tFor = 421,
     tIn = 422,
     tEndFor = 423,
     tIf = 424,
     tElseIf = 425,
     tElse = 426,
     tEndIf = 427,
     tExit = 428,
     tAbort = 429,
     tField = 430,
     tReturn = 431,
     tCall = 432,
     tSlide = 433,
     tMacro = 434,
     tShow = 435,
     tHide = 436,
     tGetValue = 437,
     tGetStringValue = 438,
     tGetEnv = 439,
     tGetString = 440,
     tGetNumber = 441,
     tHomology = 442,
     tCohomology = 443,
     tBetti = 444,
     tExists = 445,
     tFileExists = 446,
     tGMSH_MAJOR_VERSION = 447,
     tGMSH_MINOR_VERSION = 448,
     tGMSH_PATCH_VERSION = 449,
     tGmshExecutableName = 450,
     tSetPartition = 451,
     tNameToString = 452,
     tStringToName = 453,
     tAFFECTDIVIDE = 454,
     tAFFECTTIMES = 455,
     tAFFECTMINUS = 456,
     tAFFECTPLUS = 457,
     tOR = 458,
     tAND = 459,
     tNOTEQUAL = 460,
     tEQUAL = 461,
     tGREATEROREQUAL = 462,
     tLESSOREQUAL = 463,
     UNARYPREC = 464,
     tMINUSMINUS = 465,
     tPLUSPLUS = 466
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
#define tPlane 366
#define tRuled 367
#define tTransfinite 368
#define tComplex 369
#define tPhysical 370
#define tCompound 371
#define tPeriodic 372
#define tUsing 373
#define tPlugin 374
#define tDegenerated 375
#define tRecursive 376
#define tRotate 377
#define tTranslate 378
#define tSymmetry 379
#define tDilate 380
#define tExtrude 381
#define tLevelset 382
#define tAffine 383
#define tBooleanUnion 384
#define tBooleanIntersection 385
#define tBooleanDifference 386
#define tBooleanSection 387
#define tBooleanFragments 388
#define tRecombine 389
#define tSmoother 390
#define tSplit 391
#define tDelete 392
#define tCoherence 393
#define tIntersect 394
#define tMeshAlgorithm 395
#define tReverse 396
#define tLayers 397
#define tScaleLast 398
#define tHole 399
#define tAlias 400
#define tAliasWithOptions 401
#define tCopyOptions 402
#define tQuadTriAddVerts 403
#define tQuadTriNoNewVerts 404
#define tQuadTriSngl 405
#define tQuadTriDbl 406
#define tRecombLaterals 407
#define tTransfQuadTri 408
#define tText2D 409
#define tText3D 410
#define tInterpolationScheme 411
#define tTime 412
#define tCombine 413
#define tBSpline 414
#define tBezier 415
#define tNurbs 416
#define tNurbsOrder 417
#define tNurbsKnots 418
#define tColor 419
#define tColorTable 420
#define tFor 421
#define tIn 422
#define tEndFor 423
#define tIf 424
#define tElseIf 425
#define tElse 426
#define tEndIf 427
#define tExit 428
#define tAbort 429
#define tField 430
#define tReturn 431
#define tCall 432
#define tSlide 433
#define tMacro 434
#define tShow 435
#define tHide 436
#define tGetValue 437
#define tGetStringValue 438
#define tGetEnv 439
#define tGetString 440
#define tGetNumber 441
#define tHomology 442
#define tCohomology 443
#define tBetti 444
#define tExists 445
#define tFileExists 446
#define tGMSH_MAJOR_VERSION 447
#define tGMSH_MINOR_VERSION 448
#define tGMSH_PATCH_VERSION 449
#define tGmshExecutableName 450
#define tSetPartition 451
#define tNameToString 452
#define tStringToName 453
#define tAFFECTDIVIDE 454
#define tAFFECTTIMES 455
#define tAFFECTMINUS 456
#define tAFFECTPLUS 457
#define tOR 458
#define tAND 459
#define tNOTEQUAL 460
#define tEQUAL 461
#define tGREATEROREQUAL 462
#define tLESSOREQUAL 463
#define UNARYPREC 464
#define tMINUSMINUS 465
#define tPLUSPLUS 466




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
#line 481 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

