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
     tCharacteristic = 353,
     tLength = 354,
     tParametric = 355,
     tElliptic = 356,
     tRefineMesh = 357,
     tAdaptMesh = 358,
     tRelocateMesh = 359,
     tSetFactory = 360,
     tThruSections = 361,
     tPlane = 362,
     tRuled = 363,
     tTransfinite = 364,
     tComplex = 365,
     tPhysical = 366,
     tCompound = 367,
     tPeriodic = 368,
     tUsing = 369,
     tPlugin = 370,
     tDegenerated = 371,
     tRecursive = 372,
     tRotate = 373,
     tTranslate = 374,
     tSymmetry = 375,
     tDilate = 376,
     tExtrude = 377,
     tLevelset = 378,
     tAffine = 379,
     tBooleanUnion = 380,
     tBooleanIntersection = 381,
     tBooleanDifference = 382,
     tBooleanSection = 383,
     tBooleanFragments = 384,
     tRecombine = 385,
     tSmoother = 386,
     tSplit = 387,
     tDelete = 388,
     tCoherence = 389,
     tIntersect = 390,
     tMeshAlgorithm = 391,
     tReverse = 392,
     tLayers = 393,
     tScaleLast = 394,
     tHole = 395,
     tAlias = 396,
     tAliasWithOptions = 397,
     tCopyOptions = 398,
     tQuadTriAddVerts = 399,
     tQuadTriNoNewVerts = 400,
     tQuadTriSngl = 401,
     tQuadTriDbl = 402,
     tRecombLaterals = 403,
     tTransfQuadTri = 404,
     tText2D = 405,
     tText3D = 406,
     tInterpolationScheme = 407,
     tTime = 408,
     tCombine = 409,
     tBSpline = 410,
     tBezier = 411,
     tNurbs = 412,
     tNurbsOrder = 413,
     tNurbsKnots = 414,
     tColor = 415,
     tColorTable = 416,
     tFor = 417,
     tIn = 418,
     tEndFor = 419,
     tIf = 420,
     tElseIf = 421,
     tElse = 422,
     tEndIf = 423,
     tExit = 424,
     tAbort = 425,
     tField = 426,
     tReturn = 427,
     tCall = 428,
     tSlide = 429,
     tMacro = 430,
     tShow = 431,
     tHide = 432,
     tGetValue = 433,
     tGetStringValue = 434,
     tGetEnv = 435,
     tGetString = 436,
     tGetNumber = 437,
     tHomology = 438,
     tCohomology = 439,
     tBetti = 440,
     tExists = 441,
     tFileExists = 442,
     tGMSH_MAJOR_VERSION = 443,
     tGMSH_MINOR_VERSION = 444,
     tGMSH_PATCH_VERSION = 445,
     tGmshExecutableName = 446,
     tSetPartition = 447,
     tNameToString = 448,
     tStringToName = 449,
     tAFFECTDIVIDE = 450,
     tAFFECTTIMES = 451,
     tAFFECTMINUS = 452,
     tAFFECTPLUS = 453,
     tOR = 454,
     tAND = 455,
     tNOTEQUAL = 456,
     tEQUAL = 457,
     tGREATEROREQUAL = 458,
     tLESSOREQUAL = 459,
     UNARYPREC = 460,
     tMINUSMINUS = 461,
     tPLUSPLUS = 462
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
#define tCharacteristic 353
#define tLength 354
#define tParametric 355
#define tElliptic 356
#define tRefineMesh 357
#define tAdaptMesh 358
#define tRelocateMesh 359
#define tSetFactory 360
#define tThruSections 361
#define tPlane 362
#define tRuled 363
#define tTransfinite 364
#define tComplex 365
#define tPhysical 366
#define tCompound 367
#define tPeriodic 368
#define tUsing 369
#define tPlugin 370
#define tDegenerated 371
#define tRecursive 372
#define tRotate 373
#define tTranslate 374
#define tSymmetry 375
#define tDilate 376
#define tExtrude 377
#define tLevelset 378
#define tAffine 379
#define tBooleanUnion 380
#define tBooleanIntersection 381
#define tBooleanDifference 382
#define tBooleanSection 383
#define tBooleanFragments 384
#define tRecombine 385
#define tSmoother 386
#define tSplit 387
#define tDelete 388
#define tCoherence 389
#define tIntersect 390
#define tMeshAlgorithm 391
#define tReverse 392
#define tLayers 393
#define tScaleLast 394
#define tHole 395
#define tAlias 396
#define tAliasWithOptions 397
#define tCopyOptions 398
#define tQuadTriAddVerts 399
#define tQuadTriNoNewVerts 400
#define tQuadTriSngl 401
#define tQuadTriDbl 402
#define tRecombLaterals 403
#define tTransfQuadTri 404
#define tText2D 405
#define tText3D 406
#define tInterpolationScheme 407
#define tTime 408
#define tCombine 409
#define tBSpline 410
#define tBezier 411
#define tNurbs 412
#define tNurbsOrder 413
#define tNurbsKnots 414
#define tColor 415
#define tColorTable 416
#define tFor 417
#define tIn 418
#define tEndFor 419
#define tIf 420
#define tElseIf 421
#define tElse 422
#define tEndIf 423
#define tExit 424
#define tAbort 425
#define tField 426
#define tReturn 427
#define tCall 428
#define tSlide 429
#define tMacro 430
#define tShow 431
#define tHide 432
#define tGetValue 433
#define tGetStringValue 434
#define tGetEnv 435
#define tGetString 436
#define tGetNumber 437
#define tHomology 438
#define tCohomology 439
#define tBetti 440
#define tExists 441
#define tFileExists 442
#define tGMSH_MAJOR_VERSION 443
#define tGMSH_MINOR_VERSION 444
#define tGMSH_PATCH_VERSION 445
#define tGmshExecutableName 446
#define tSetPartition 447
#define tNameToString 448
#define tStringToName 449
#define tAFFECTDIVIDE 450
#define tAFFECTTIMES 451
#define tAFFECTMINUS 452
#define tAFFECTPLUS 453
#define tOR 454
#define tAND 455
#define tNOTEQUAL 456
#define tEQUAL 457
#define tGREATEROREQUAL 458
#define tLESSOREQUAL 459
#define UNARYPREC 460
#define tMINUSMINUS 461
#define tPLUSPLUS 462




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
#line 473 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

