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
     tCharacteristic = 354,
     tLength = 355,
     tParametric = 356,
     tElliptic = 357,
     tRefineMesh = 358,
     tAdaptMesh = 359,
     tRelocateMesh = 360,
     tSetFactory = 361,
     tThruSections = 362,
     tPlane = 363,
     tRuled = 364,
     tTransfinite = 365,
     tComplex = 366,
     tPhysical = 367,
     tCompound = 368,
     tPeriodic = 369,
     tUsing = 370,
     tPlugin = 371,
     tDegenerated = 372,
     tRecursive = 373,
     tRotate = 374,
     tTranslate = 375,
     tSymmetry = 376,
     tDilate = 377,
     tExtrude = 378,
     tLevelset = 379,
     tAffine = 380,
     tBooleanUnion = 381,
     tBooleanIntersection = 382,
     tBooleanDifference = 383,
     tBooleanSection = 384,
     tBooleanFragments = 385,
     tRecombine = 386,
     tSmoother = 387,
     tSplit = 388,
     tDelete = 389,
     tCoherence = 390,
     tIntersect = 391,
     tMeshAlgorithm = 392,
     tReverse = 393,
     tLayers = 394,
     tScaleLast = 395,
     tHole = 396,
     tAlias = 397,
     tAliasWithOptions = 398,
     tCopyOptions = 399,
     tQuadTriAddVerts = 400,
     tQuadTriNoNewVerts = 401,
     tQuadTriSngl = 402,
     tQuadTriDbl = 403,
     tRecombLaterals = 404,
     tTransfQuadTri = 405,
     tText2D = 406,
     tText3D = 407,
     tInterpolationScheme = 408,
     tTime = 409,
     tCombine = 410,
     tBSpline = 411,
     tBezier = 412,
     tNurbs = 413,
     tNurbsOrder = 414,
     tNurbsKnots = 415,
     tColor = 416,
     tColorTable = 417,
     tFor = 418,
     tIn = 419,
     tEndFor = 420,
     tIf = 421,
     tElseIf = 422,
     tElse = 423,
     tEndIf = 424,
     tExit = 425,
     tAbort = 426,
     tField = 427,
     tReturn = 428,
     tCall = 429,
     tSlide = 430,
     tMacro = 431,
     tShow = 432,
     tHide = 433,
     tGetValue = 434,
     tGetStringValue = 435,
     tGetEnv = 436,
     tGetString = 437,
     tGetNumber = 438,
     tHomology = 439,
     tCohomology = 440,
     tBetti = 441,
     tExists = 442,
     tFileExists = 443,
     tGMSH_MAJOR_VERSION = 444,
     tGMSH_MINOR_VERSION = 445,
     tGMSH_PATCH_VERSION = 446,
     tGmshExecutableName = 447,
     tSetPartition = 448,
     tNameToString = 449,
     tStringToName = 450,
     tAFFECTDIVIDE = 451,
     tAFFECTTIMES = 452,
     tAFFECTMINUS = 453,
     tAFFECTPLUS = 454,
     tOR = 455,
     tAND = 456,
     tNOTEQUAL = 457,
     tEQUAL = 458,
     tGREATEROREQUAL = 459,
     tLESSOREQUAL = 460,
     UNARYPREC = 461,
     tMINUSMINUS = 462,
     tPLUSPLUS = 463
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
#define tCharacteristic 354
#define tLength 355
#define tParametric 356
#define tElliptic 357
#define tRefineMesh 358
#define tAdaptMesh 359
#define tRelocateMesh 360
#define tSetFactory 361
#define tThruSections 362
#define tPlane 363
#define tRuled 364
#define tTransfinite 365
#define tComplex 366
#define tPhysical 367
#define tCompound 368
#define tPeriodic 369
#define tUsing 370
#define tPlugin 371
#define tDegenerated 372
#define tRecursive 373
#define tRotate 374
#define tTranslate 375
#define tSymmetry 376
#define tDilate 377
#define tExtrude 378
#define tLevelset 379
#define tAffine 380
#define tBooleanUnion 381
#define tBooleanIntersection 382
#define tBooleanDifference 383
#define tBooleanSection 384
#define tBooleanFragments 385
#define tRecombine 386
#define tSmoother 387
#define tSplit 388
#define tDelete 389
#define tCoherence 390
#define tIntersect 391
#define tMeshAlgorithm 392
#define tReverse 393
#define tLayers 394
#define tScaleLast 395
#define tHole 396
#define tAlias 397
#define tAliasWithOptions 398
#define tCopyOptions 399
#define tQuadTriAddVerts 400
#define tQuadTriNoNewVerts 401
#define tQuadTriSngl 402
#define tQuadTriDbl 403
#define tRecombLaterals 404
#define tTransfQuadTri 405
#define tText2D 406
#define tText3D 407
#define tInterpolationScheme 408
#define tTime 409
#define tCombine 410
#define tBSpline 411
#define tBezier 412
#define tNurbs 413
#define tNurbsOrder 414
#define tNurbsKnots 415
#define tColor 416
#define tColorTable 417
#define tFor 418
#define tIn 419
#define tEndFor 420
#define tIf 421
#define tElseIf 422
#define tElse 423
#define tEndIf 424
#define tExit 425
#define tAbort 426
#define tField 427
#define tReturn 428
#define tCall 429
#define tSlide 430
#define tMacro 431
#define tShow 432
#define tHide 433
#define tGetValue 434
#define tGetStringValue 435
#define tGetEnv 436
#define tGetString 437
#define tGetNumber 438
#define tHomology 439
#define tCohomology 440
#define tBetti 441
#define tExists 442
#define tFileExists 443
#define tGMSH_MAJOR_VERSION 444
#define tGMSH_MINOR_VERSION 445
#define tGMSH_PATCH_VERSION 446
#define tGmshExecutableName 447
#define tSetPartition 448
#define tNameToString 449
#define tStringToName 450
#define tAFFECTDIVIDE 451
#define tAFFECTTIMES 452
#define tAFFECTMINUS 453
#define tAFFECTPLUS 454
#define tOR 455
#define tAND 456
#define tNOTEQUAL 457
#define tEQUAL 458
#define tGREATEROREQUAL 459
#define tLESSOREQUAL 460
#define UNARYPREC 461
#define tMINUSMINUS 462
#define tPLUSPLUS 463




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
#line 475 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

