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
     tCharacteristic = 348,
     tLength = 349,
     tParametric = 350,
     tElliptic = 351,
     tRefineMesh = 352,
     tAdaptMesh = 353,
     tRelocateMesh = 354,
     tSetFactory = 355,
     tThruSections = 356,
     tPlane = 357,
     tRuled = 358,
     tTransfinite = 359,
     tComplex = 360,
     tPhysical = 361,
     tCompound = 362,
     tPeriodic = 363,
     tUsing = 364,
     tPlugin = 365,
     tDegenerated = 366,
     tRecursive = 367,
     tRotate = 368,
     tTranslate = 369,
     tSymmetry = 370,
     tDilate = 371,
     tExtrude = 372,
     tLevelset = 373,
     tAffine = 374,
     tBooleanUnion = 375,
     tBooleanIntersection = 376,
     tBooleanSubtraction = 377,
     tRecombine = 378,
     tSmoother = 379,
     tSplit = 380,
     tDelete = 381,
     tCoherence = 382,
     tIntersect = 383,
     tMeshAlgorithm = 384,
     tReverse = 385,
     tLayers = 386,
     tScaleLast = 387,
     tHole = 388,
     tAlias = 389,
     tAliasWithOptions = 390,
     tCopyOptions = 391,
     tQuadTriAddVerts = 392,
     tQuadTriNoNewVerts = 393,
     tQuadTriSngl = 394,
     tQuadTriDbl = 395,
     tRecombLaterals = 396,
     tTransfQuadTri = 397,
     tText2D = 398,
     tText3D = 399,
     tInterpolationScheme = 400,
     tTime = 401,
     tCombine = 402,
     tBSpline = 403,
     tBezier = 404,
     tNurbs = 405,
     tNurbsOrder = 406,
     tNurbsKnots = 407,
     tColor = 408,
     tColorTable = 409,
     tFor = 410,
     tIn = 411,
     tEndFor = 412,
     tIf = 413,
     tElseIf = 414,
     tElse = 415,
     tEndIf = 416,
     tExit = 417,
     tAbort = 418,
     tField = 419,
     tReturn = 420,
     tCall = 421,
     tSlide = 422,
     tMacro = 423,
     tShow = 424,
     tHide = 425,
     tGetValue = 426,
     tGetStringValue = 427,
     tGetEnv = 428,
     tGetString = 429,
     tGetNumber = 430,
     tHomology = 431,
     tCohomology = 432,
     tBetti = 433,
     tExists = 434,
     tFileExists = 435,
     tGMSH_MAJOR_VERSION = 436,
     tGMSH_MINOR_VERSION = 437,
     tGMSH_PATCH_VERSION = 438,
     tGmshExecutableName = 439,
     tSetPartition = 440,
     tNameToString = 441,
     tStringToName = 442,
     tAFFECTDIVIDE = 443,
     tAFFECTTIMES = 444,
     tAFFECTMINUS = 445,
     tAFFECTPLUS = 446,
     tOR = 447,
     tAND = 448,
     tNOTEQUAL = 449,
     tEQUAL = 450,
     tGREATEROREQUAL = 451,
     tLESSOREQUAL = 452,
     UNARYPREC = 453,
     tMINUSMINUS = 454,
     tPLUSPLUS = 455
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
#define tCharacteristic 348
#define tLength 349
#define tParametric 350
#define tElliptic 351
#define tRefineMesh 352
#define tAdaptMesh 353
#define tRelocateMesh 354
#define tSetFactory 355
#define tThruSections 356
#define tPlane 357
#define tRuled 358
#define tTransfinite 359
#define tComplex 360
#define tPhysical 361
#define tCompound 362
#define tPeriodic 363
#define tUsing 364
#define tPlugin 365
#define tDegenerated 366
#define tRecursive 367
#define tRotate 368
#define tTranslate 369
#define tSymmetry 370
#define tDilate 371
#define tExtrude 372
#define tLevelset 373
#define tAffine 374
#define tBooleanUnion 375
#define tBooleanIntersection 376
#define tBooleanSubtraction 377
#define tRecombine 378
#define tSmoother 379
#define tSplit 380
#define tDelete 381
#define tCoherence 382
#define tIntersect 383
#define tMeshAlgorithm 384
#define tReverse 385
#define tLayers 386
#define tScaleLast 387
#define tHole 388
#define tAlias 389
#define tAliasWithOptions 390
#define tCopyOptions 391
#define tQuadTriAddVerts 392
#define tQuadTriNoNewVerts 393
#define tQuadTriSngl 394
#define tQuadTriDbl 395
#define tRecombLaterals 396
#define tTransfQuadTri 397
#define tText2D 398
#define tText3D 399
#define tInterpolationScheme 400
#define tTime 401
#define tCombine 402
#define tBSpline 403
#define tBezier 404
#define tNurbs 405
#define tNurbsOrder 406
#define tNurbsKnots 407
#define tColor 408
#define tColorTable 409
#define tFor 410
#define tIn 411
#define tEndFor 412
#define tIf 413
#define tElseIf 414
#define tElse 415
#define tEndIf 416
#define tExit 417
#define tAbort 418
#define tField 419
#define tReturn 420
#define tCall 421
#define tSlide 422
#define tMacro 423
#define tShow 424
#define tHide 425
#define tGetValue 426
#define tGetStringValue 427
#define tGetEnv 428
#define tGetString 429
#define tGetNumber 430
#define tHomology 431
#define tCohomology 432
#define tBetti 433
#define tExists 434
#define tFileExists 435
#define tGMSH_MAJOR_VERSION 436
#define tGMSH_MINOR_VERSION 437
#define tGMSH_PATCH_VERSION 438
#define tGmshExecutableName 439
#define tSetPartition 440
#define tNameToString 441
#define tStringToName 442
#define tAFFECTDIVIDE 443
#define tAFFECTTIMES 444
#define tAFFECTMINUS 445
#define tAFFECTPLUS 446
#define tOR 447
#define tAND 448
#define tNOTEQUAL 449
#define tEQUAL 450
#define tGREATEROREQUAL 451
#define tLESSOREQUAL 452
#define UNARYPREC 453
#define tMINUSMINUS 454
#define tPLUSPLUS 455




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
#line 459 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

