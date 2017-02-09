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
     tEllipsoid = 351,
     tQuadric = 352,
     tShapeFromFile = 353,
     tRectangle = 354,
     tDisk = 355,
     tCharacteristic = 356,
     tLength = 357,
     tParametric = 358,
     tElliptic = 359,
     tRefineMesh = 360,
     tAdaptMesh = 361,
     tRelocateMesh = 362,
     tSetFactory = 363,
     tThruSections = 364,
     tPlane = 365,
     tRuled = 366,
     tTransfinite = 367,
     tComplex = 368,
     tPhysical = 369,
     tCompound = 370,
     tPeriodic = 371,
     tUsing = 372,
     tPlugin = 373,
     tDegenerated = 374,
     tRecursive = 375,
     tRotate = 376,
     tTranslate = 377,
     tSymmetry = 378,
     tDilate = 379,
     tExtrude = 380,
     tLevelset = 381,
     tAffine = 382,
     tBooleanUnion = 383,
     tBooleanIntersection = 384,
     tBooleanDifference = 385,
     tBooleanSection = 386,
     tBooleanFragments = 387,
     tRecombine = 388,
     tSmoother = 389,
     tSplit = 390,
     tDelete = 391,
     tCoherence = 392,
     tIntersect = 393,
     tMeshAlgorithm = 394,
     tReverse = 395,
     tLayers = 396,
     tScaleLast = 397,
     tHole = 398,
     tAlias = 399,
     tAliasWithOptions = 400,
     tCopyOptions = 401,
     tQuadTriAddVerts = 402,
     tQuadTriNoNewVerts = 403,
     tQuadTriSngl = 404,
     tQuadTriDbl = 405,
     tRecombLaterals = 406,
     tTransfQuadTri = 407,
     tText2D = 408,
     tText3D = 409,
     tInterpolationScheme = 410,
     tTime = 411,
     tCombine = 412,
     tBSpline = 413,
     tBezier = 414,
     tNurbs = 415,
     tNurbsOrder = 416,
     tNurbsKnots = 417,
     tColor = 418,
     tColorTable = 419,
     tFor = 420,
     tIn = 421,
     tEndFor = 422,
     tIf = 423,
     tElseIf = 424,
     tElse = 425,
     tEndIf = 426,
     tExit = 427,
     tAbort = 428,
     tField = 429,
     tReturn = 430,
     tCall = 431,
     tSlide = 432,
     tMacro = 433,
     tShow = 434,
     tHide = 435,
     tGetValue = 436,
     tGetStringValue = 437,
     tGetEnv = 438,
     tGetString = 439,
     tGetNumber = 440,
     tHomology = 441,
     tCohomology = 442,
     tBetti = 443,
     tExists = 444,
     tFileExists = 445,
     tGMSH_MAJOR_VERSION = 446,
     tGMSH_MINOR_VERSION = 447,
     tGMSH_PATCH_VERSION = 448,
     tGmshExecutableName = 449,
     tSetPartition = 450,
     tNameToString = 451,
     tStringToName = 452,
     tAFFECTDIVIDE = 453,
     tAFFECTTIMES = 454,
     tAFFECTMINUS = 455,
     tAFFECTPLUS = 456,
     tOR = 457,
     tAND = 458,
     tNOTEQUAL = 459,
     tEQUAL = 460,
     tGREATEROREQUAL = 461,
     tLESSOREQUAL = 462,
     UNARYPREC = 463,
     tMINUSMINUS = 464,
     tPLUSPLUS = 465
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
#define tEllipsoid 351
#define tQuadric 352
#define tShapeFromFile 353
#define tRectangle 354
#define tDisk 355
#define tCharacteristic 356
#define tLength 357
#define tParametric 358
#define tElliptic 359
#define tRefineMesh 360
#define tAdaptMesh 361
#define tRelocateMesh 362
#define tSetFactory 363
#define tThruSections 364
#define tPlane 365
#define tRuled 366
#define tTransfinite 367
#define tComplex 368
#define tPhysical 369
#define tCompound 370
#define tPeriodic 371
#define tUsing 372
#define tPlugin 373
#define tDegenerated 374
#define tRecursive 375
#define tRotate 376
#define tTranslate 377
#define tSymmetry 378
#define tDilate 379
#define tExtrude 380
#define tLevelset 381
#define tAffine 382
#define tBooleanUnion 383
#define tBooleanIntersection 384
#define tBooleanDifference 385
#define tBooleanSection 386
#define tBooleanFragments 387
#define tRecombine 388
#define tSmoother 389
#define tSplit 390
#define tDelete 391
#define tCoherence 392
#define tIntersect 393
#define tMeshAlgorithm 394
#define tReverse 395
#define tLayers 396
#define tScaleLast 397
#define tHole 398
#define tAlias 399
#define tAliasWithOptions 400
#define tCopyOptions 401
#define tQuadTriAddVerts 402
#define tQuadTriNoNewVerts 403
#define tQuadTriSngl 404
#define tQuadTriDbl 405
#define tRecombLaterals 406
#define tTransfQuadTri 407
#define tText2D 408
#define tText3D 409
#define tInterpolationScheme 410
#define tTime 411
#define tCombine 412
#define tBSpline 413
#define tBezier 414
#define tNurbs 415
#define tNurbsOrder 416
#define tNurbsKnots 417
#define tColor 418
#define tColorTable 419
#define tFor 420
#define tIn 421
#define tEndFor 422
#define tIf 423
#define tElseIf 424
#define tElse 425
#define tEndIf 426
#define tExit 427
#define tAbort 428
#define tField 429
#define tReturn 430
#define tCall 431
#define tSlide 432
#define tMacro 433
#define tShow 434
#define tHide 435
#define tGetValue 436
#define tGetStringValue 437
#define tGetEnv 438
#define tGetString 439
#define tGetNumber 440
#define tHomology 441
#define tCohomology 442
#define tBetti 443
#define tExists 444
#define tFileExists 445
#define tGMSH_MAJOR_VERSION 446
#define tGMSH_MINOR_VERSION 447
#define tGMSH_PATCH_VERSION 448
#define tGmshExecutableName 449
#define tSetPartition 450
#define tNameToString 451
#define tStringToName 452
#define tAFFECTDIVIDE 453
#define tAFFECTTIMES 454
#define tAFFECTMINUS 455
#define tAFFECTPLUS 456
#define tOR 457
#define tAND 458
#define tNOTEQUAL 459
#define tEQUAL 460
#define tGREATEROREQUAL 461
#define tLESSOREQUAL 462
#define UNARYPREC 463
#define tMINUSMINUS 464
#define tPLUSPLUS 465




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
#line 479 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

