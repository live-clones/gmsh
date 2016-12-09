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
     tCatenary = 295,
     tPrintf = 296,
     tError = 297,
     tStr = 298,
     tSprintf = 299,
     tStrCat = 300,
     tStrPrefix = 301,
     tStrRelative = 302,
     tStrReplace = 303,
     tAbsolutePath = 304,
     tDirName = 305,
     tStrSub = 306,
     tStrLen = 307,
     tFind = 308,
     tStrFind = 309,
     tStrCmp = 310,
     tStrChoice = 311,
     tUpperCase = 312,
     tLowerCase = 313,
     tLowerCaseIn = 314,
     tTextAttributes = 315,
     tBoundingBox = 316,
     tDraw = 317,
     tSetChanged = 318,
     tToday = 319,
     tFixRelativePath = 320,
     tCurrentDirectory = 321,
     tSyncModel = 322,
     tNewModel = 323,
     tOnelabAction = 324,
     tOnelabRun = 325,
     tCpu = 326,
     tMemory = 327,
     tTotalMemory = 328,
     tCreateTopology = 329,
     tCreateTopologyNoHoles = 330,
     tDistanceFunction = 331,
     tDefineConstant = 332,
     tUndefineConstant = 333,
     tDefineNumber = 334,
     tDefineString = 335,
     tSetNumber = 336,
     tSetString = 337,
     tPoint = 338,
     tCircle = 339,
     tEllipse = 340,
     tLine = 341,
     tSphere = 342,
     tPolarSphere = 343,
     tSurface = 344,
     tSpline = 345,
     tVolume = 346,
     tCharacteristic = 347,
     tLength = 348,
     tParametric = 349,
     tElliptic = 350,
     tRefineMesh = 351,
     tAdaptMesh = 352,
     tRelocateMesh = 353,
     tPlane = 354,
     tRuled = 355,
     tTransfinite = 356,
     tComplex = 357,
     tPhysical = 358,
     tCompound = 359,
     tPeriodic = 360,
     tUsing = 361,
     tPlugin = 362,
     tDegenerated = 363,
     tRecursive = 364,
     tRotate = 365,
     tTranslate = 366,
     tSymmetry = 367,
     tDilate = 368,
     tExtrude = 369,
     tLevelset = 370,
     tAffine = 371,
     tRecombine = 372,
     tSmoother = 373,
     tSplit = 374,
     tDelete = 375,
     tCoherence = 376,
     tIntersect = 377,
     tMeshAlgorithm = 378,
     tReverse = 379,
     tLayers = 380,
     tScaleLast = 381,
     tHole = 382,
     tAlias = 383,
     tAliasWithOptions = 384,
     tCopyOptions = 385,
     tQuadTriAddVerts = 386,
     tQuadTriNoNewVerts = 387,
     tQuadTriSngl = 388,
     tQuadTriDbl = 389,
     tRecombLaterals = 390,
     tTransfQuadTri = 391,
     tText2D = 392,
     tText3D = 393,
     tInterpolationScheme = 394,
     tTime = 395,
     tCombine = 396,
     tBSpline = 397,
     tBezier = 398,
     tNurbs = 399,
     tNurbsOrder = 400,
     tNurbsKnots = 401,
     tColor = 402,
     tColorTable = 403,
     tFor = 404,
     tIn = 405,
     tEndFor = 406,
     tIf = 407,
     tElseIf = 408,
     tElse = 409,
     tEndIf = 410,
     tExit = 411,
     tAbort = 412,
     tField = 413,
     tReturn = 414,
     tCall = 415,
     tSlide = 416,
     tMacro = 417,
     tShow = 418,
     tHide = 419,
     tGetValue = 420,
     tGetStringValue = 421,
     tGetEnv = 422,
     tGetString = 423,
     tGetNumber = 424,
     tHomology = 425,
     tCohomology = 426,
     tBetti = 427,
     tExists = 428,
     tFileExists = 429,
     tGMSH_MAJOR_VERSION = 430,
     tGMSH_MINOR_VERSION = 431,
     tGMSH_PATCH_VERSION = 432,
     tGmshExecutableName = 433,
     tSetPartition = 434,
     tNameToString = 435,
     tStringToName = 436,
     tAFFECTDIVIDE = 437,
     tAFFECTTIMES = 438,
     tAFFECTMINUS = 439,
     tAFFECTPLUS = 440,
     tOR = 441,
     tAND = 442,
     tNOTEQUAL = 443,
     tEQUAL = 444,
     tGREATEROREQUAL = 445,
     tLESSOREQUAL = 446,
     UNARYPREC = 447,
     tMINUSMINUS = 448,
     tPLUSPLUS = 449
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
#define tCatenary 295
#define tPrintf 296
#define tError 297
#define tStr 298
#define tSprintf 299
#define tStrCat 300
#define tStrPrefix 301
#define tStrRelative 302
#define tStrReplace 303
#define tAbsolutePath 304
#define tDirName 305
#define tStrSub 306
#define tStrLen 307
#define tFind 308
#define tStrFind 309
#define tStrCmp 310
#define tStrChoice 311
#define tUpperCase 312
#define tLowerCase 313
#define tLowerCaseIn 314
#define tTextAttributes 315
#define tBoundingBox 316
#define tDraw 317
#define tSetChanged 318
#define tToday 319
#define tFixRelativePath 320
#define tCurrentDirectory 321
#define tSyncModel 322
#define tNewModel 323
#define tOnelabAction 324
#define tOnelabRun 325
#define tCpu 326
#define tMemory 327
#define tTotalMemory 328
#define tCreateTopology 329
#define tCreateTopologyNoHoles 330
#define tDistanceFunction 331
#define tDefineConstant 332
#define tUndefineConstant 333
#define tDefineNumber 334
#define tDefineString 335
#define tSetNumber 336
#define tSetString 337
#define tPoint 338
#define tCircle 339
#define tEllipse 340
#define tLine 341
#define tSphere 342
#define tPolarSphere 343
#define tSurface 344
#define tSpline 345
#define tVolume 346
#define tCharacteristic 347
#define tLength 348
#define tParametric 349
#define tElliptic 350
#define tRefineMesh 351
#define tAdaptMesh 352
#define tRelocateMesh 353
#define tPlane 354
#define tRuled 355
#define tTransfinite 356
#define tComplex 357
#define tPhysical 358
#define tCompound 359
#define tPeriodic 360
#define tUsing 361
#define tPlugin 362
#define tDegenerated 363
#define tRecursive 364
#define tRotate 365
#define tTranslate 366
#define tSymmetry 367
#define tDilate 368
#define tExtrude 369
#define tLevelset 370
#define tAffine 371
#define tRecombine 372
#define tSmoother 373
#define tSplit 374
#define tDelete 375
#define tCoherence 376
#define tIntersect 377
#define tMeshAlgorithm 378
#define tReverse 379
#define tLayers 380
#define tScaleLast 381
#define tHole 382
#define tAlias 383
#define tAliasWithOptions 384
#define tCopyOptions 385
#define tQuadTriAddVerts 386
#define tQuadTriNoNewVerts 387
#define tQuadTriSngl 388
#define tQuadTriDbl 389
#define tRecombLaterals 390
#define tTransfQuadTri 391
#define tText2D 392
#define tText3D 393
#define tInterpolationScheme 394
#define tTime 395
#define tCombine 396
#define tBSpline 397
#define tBezier 398
#define tNurbs 399
#define tNurbsOrder 400
#define tNurbsKnots 401
#define tColor 402
#define tColorTable 403
#define tFor 404
#define tIn 405
#define tEndFor 406
#define tIf 407
#define tElseIf 408
#define tElse 409
#define tEndIf 410
#define tExit 411
#define tAbort 412
#define tField 413
#define tReturn 414
#define tCall 415
#define tSlide 416
#define tMacro 417
#define tShow 418
#define tHide 419
#define tGetValue 420
#define tGetStringValue 421
#define tGetEnv 422
#define tGetString 423
#define tGetNumber 424
#define tHomology 425
#define tCohomology 426
#define tBetti 427
#define tExists 428
#define tFileExists 429
#define tGMSH_MAJOR_VERSION 430
#define tGMSH_MINOR_VERSION 431
#define tGMSH_PATCH_VERSION 432
#define tGmshExecutableName 433
#define tSetPartition 434
#define tNameToString 435
#define tStringToName 436
#define tAFFECTDIVIDE 437
#define tAFFECTTIMES 438
#define tAFFECTMINUS 439
#define tAFFECTPLUS 440
#define tOR 441
#define tAND 442
#define tNOTEQUAL 443
#define tEQUAL 444
#define tGREATEROREQUAL 445
#define tLESSOREQUAL 446
#define UNARYPREC 447
#define tMINUSMINUS 448
#define tPLUSPLUS 449




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 115 "Gmsh.y"
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
#line 447 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

