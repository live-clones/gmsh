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
     tBooleanSubtraction = 382,
     tRecombine = 383,
     tSmoother = 384,
     tSplit = 385,
     tDelete = 386,
     tCoherence = 387,
     tIntersect = 388,
     tMeshAlgorithm = 389,
     tReverse = 390,
     tLayers = 391,
     tScaleLast = 392,
     tHole = 393,
     tAlias = 394,
     tAliasWithOptions = 395,
     tCopyOptions = 396,
     tQuadTriAddVerts = 397,
     tQuadTriNoNewVerts = 398,
     tQuadTriSngl = 399,
     tQuadTriDbl = 400,
     tRecombLaterals = 401,
     tTransfQuadTri = 402,
     tText2D = 403,
     tText3D = 404,
     tInterpolationScheme = 405,
     tTime = 406,
     tCombine = 407,
     tBSpline = 408,
     tBezier = 409,
     tNurbs = 410,
     tNurbsOrder = 411,
     tNurbsKnots = 412,
     tColor = 413,
     tColorTable = 414,
     tFor = 415,
     tIn = 416,
     tEndFor = 417,
     tIf = 418,
     tElseIf = 419,
     tElse = 420,
     tEndIf = 421,
     tExit = 422,
     tAbort = 423,
     tField = 424,
     tReturn = 425,
     tCall = 426,
     tSlide = 427,
     tMacro = 428,
     tShow = 429,
     tHide = 430,
     tGetValue = 431,
     tGetStringValue = 432,
     tGetEnv = 433,
     tGetString = 434,
     tGetNumber = 435,
     tHomology = 436,
     tCohomology = 437,
     tBetti = 438,
     tExists = 439,
     tFileExists = 440,
     tGMSH_MAJOR_VERSION = 441,
     tGMSH_MINOR_VERSION = 442,
     tGMSH_PATCH_VERSION = 443,
     tGmshExecutableName = 444,
     tSetPartition = 445,
     tNameToString = 446,
     tStringToName = 447,
     tAFFECTDIVIDE = 448,
     tAFFECTTIMES = 449,
     tAFFECTMINUS = 450,
     tAFFECTPLUS = 451,
     tOR = 452,
     tAND = 453,
     tNOTEQUAL = 454,
     tEQUAL = 455,
     tGREATEROREQUAL = 456,
     tLESSOREQUAL = 457,
     UNARYPREC = 458,
     tMINUSMINUS = 459,
     tPLUSPLUS = 460
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
#define tBooleanSubtraction 382
#define tRecombine 383
#define tSmoother 384
#define tSplit 385
#define tDelete 386
#define tCoherence 387
#define tIntersect 388
#define tMeshAlgorithm 389
#define tReverse 390
#define tLayers 391
#define tScaleLast 392
#define tHole 393
#define tAlias 394
#define tAliasWithOptions 395
#define tCopyOptions 396
#define tQuadTriAddVerts 397
#define tQuadTriNoNewVerts 398
#define tQuadTriSngl 399
#define tQuadTriDbl 400
#define tRecombLaterals 401
#define tTransfQuadTri 402
#define tText2D 403
#define tText3D 404
#define tInterpolationScheme 405
#define tTime 406
#define tCombine 407
#define tBSpline 408
#define tBezier 409
#define tNurbs 410
#define tNurbsOrder 411
#define tNurbsKnots 412
#define tColor 413
#define tColorTable 414
#define tFor 415
#define tIn 416
#define tEndFor 417
#define tIf 418
#define tElseIf 419
#define tElse 420
#define tEndIf 421
#define tExit 422
#define tAbort 423
#define tField 424
#define tReturn 425
#define tCall 426
#define tSlide 427
#define tMacro 428
#define tShow 429
#define tHide 430
#define tGetValue 431
#define tGetStringValue 432
#define tGetEnv 433
#define tGetString 434
#define tGetNumber 435
#define tHomology 436
#define tCohomology 437
#define tBetti 438
#define tExists 439
#define tFileExists 440
#define tGMSH_MAJOR_VERSION 441
#define tGMSH_MINOR_VERSION 442
#define tGMSH_PATCH_VERSION 443
#define tGmshExecutableName 444
#define tSetPartition 445
#define tNameToString 446
#define tStringToName 447
#define tAFFECTDIVIDE 448
#define tAFFECTTIMES 449
#define tAFFECTMINUS 450
#define tAFFECTPLUS 451
#define tOR 452
#define tAND 453
#define tNOTEQUAL 454
#define tEQUAL 455
#define tGREATEROREQUAL 456
#define tLESSOREQUAL 457
#define UNARYPREC 458
#define tMINUSMINUS 459
#define tPLUSPLUS 460




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
#line 469 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

