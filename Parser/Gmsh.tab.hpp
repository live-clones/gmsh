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
     tPrintf = 293,
     tError = 294,
     tStr = 295,
     tSprintf = 296,
     tStrCat = 297,
     tStrPrefix = 298,
     tStrRelative = 299,
     tStrReplace = 300,
     tAbsolutePath = 301,
     tDirName = 302,
     tStrSub = 303,
     tStrLen = 304,
     tFind = 305,
     tStrFind = 306,
     tStrCmp = 307,
     tStrChoice = 308,
     tUpperCase = 309,
     tLowerCase = 310,
     tLowerCaseIn = 311,
     tTextAttributes = 312,
     tBoundingBox = 313,
     tDraw = 314,
     tSetChanged = 315,
     tToday = 316,
     tFixRelativePath = 317,
     tCurrentDirectory = 318,
     tSyncModel = 319,
     tNewModel = 320,
     tOnelabAction = 321,
     tOnelabRun = 322,
     tCpu = 323,
     tMemory = 324,
     tTotalMemory = 325,
     tCreateTopology = 326,
     tCreateTopologyNoHoles = 327,
     tDistanceFunction = 328,
     tDefineConstant = 329,
     tUndefineConstant = 330,
     tDefineNumber = 331,
     tDefineString = 332,
     tSetNumber = 333,
     tSetString = 334,
     tPoint = 335,
     tCircle = 336,
     tEllipse = 337,
     tLine = 338,
     tSphere = 339,
     tPolarSphere = 340,
     tSurface = 341,
     tSpline = 342,
     tVolume = 343,
     tCharacteristic = 344,
     tLength = 345,
     tParametric = 346,
     tElliptic = 347,
     tRefineMesh = 348,
     tAdaptMesh = 349,
     tRelocateMesh = 350,
     tPlane = 351,
     tRuled = 352,
     tTransfinite = 353,
     tComplex = 354,
     tPhysical = 355,
     tCompound = 356,
     tPeriodic = 357,
     tUsing = 358,
     tPlugin = 359,
     tDegenerated = 360,
     tRecursive = 361,
     tRotate = 362,
     tTranslate = 363,
     tSymmetry = 364,
     tDilate = 365,
     tExtrude = 366,
     tLevelset = 367,
     tAffine = 368,
     tRecombine = 369,
     tSmoother = 370,
     tSplit = 371,
     tDelete = 372,
     tCoherence = 373,
     tIntersect = 374,
     tMeshAlgorithm = 375,
     tReverse = 376,
     tLayers = 377,
     tScaleLast = 378,
     tHole = 379,
     tAlias = 380,
     tAliasWithOptions = 381,
     tCopyOptions = 382,
     tQuadTriAddVerts = 383,
     tQuadTriNoNewVerts = 384,
     tQuadTriSngl = 385,
     tQuadTriDbl = 386,
     tRecombLaterals = 387,
     tTransfQuadTri = 388,
     tText2D = 389,
     tText3D = 390,
     tInterpolationScheme = 391,
     tTime = 392,
     tCombine = 393,
     tBSpline = 394,
     tBezier = 395,
     tNurbs = 396,
     tNurbsOrder = 397,
     tNurbsKnots = 398,
     tColor = 399,
     tColorTable = 400,
     tFor = 401,
     tIn = 402,
     tEndFor = 403,
     tIf = 404,
     tElseIf = 405,
     tElse = 406,
     tEndIf = 407,
     tExit = 408,
     tAbort = 409,
     tField = 410,
     tReturn = 411,
     tCall = 412,
     tSlide = 413,
     tMacro = 414,
     tShow = 415,
     tHide = 416,
     tGetValue = 417,
     tGetStringValue = 418,
     tGetEnv = 419,
     tGetString = 420,
     tGetNumber = 421,
     tHomology = 422,
     tCohomology = 423,
     tBetti = 424,
     tExists = 425,
     tFileExists = 426,
     tGMSH_MAJOR_VERSION = 427,
     tGMSH_MINOR_VERSION = 428,
     tGMSH_PATCH_VERSION = 429,
     tGmshExecutableName = 430,
     tSetPartition = 431,
     tNameToString = 432,
     tStringToName = 433,
     tAFFECTDIVIDE = 434,
     tAFFECTTIMES = 435,
     tAFFECTMINUS = 436,
     tAFFECTPLUS = 437,
     tOR = 438,
     tAND = 439,
     tNOTEQUAL = 440,
     tEQUAL = 441,
     tGREATEROREQUAL = 442,
     tLESSOREQUAL = 443,
     UNARYPREC = 444,
     tMINUSMINUS = 445,
     tPLUSPLUS = 446
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
#define tPrintf 293
#define tError 294
#define tStr 295
#define tSprintf 296
#define tStrCat 297
#define tStrPrefix 298
#define tStrRelative 299
#define tStrReplace 300
#define tAbsolutePath 301
#define tDirName 302
#define tStrSub 303
#define tStrLen 304
#define tFind 305
#define tStrFind 306
#define tStrCmp 307
#define tStrChoice 308
#define tUpperCase 309
#define tLowerCase 310
#define tLowerCaseIn 311
#define tTextAttributes 312
#define tBoundingBox 313
#define tDraw 314
#define tSetChanged 315
#define tToday 316
#define tFixRelativePath 317
#define tCurrentDirectory 318
#define tSyncModel 319
#define tNewModel 320
#define tOnelabAction 321
#define tOnelabRun 322
#define tCpu 323
#define tMemory 324
#define tTotalMemory 325
#define tCreateTopology 326
#define tCreateTopologyNoHoles 327
#define tDistanceFunction 328
#define tDefineConstant 329
#define tUndefineConstant 330
#define tDefineNumber 331
#define tDefineString 332
#define tSetNumber 333
#define tSetString 334
#define tPoint 335
#define tCircle 336
#define tEllipse 337
#define tLine 338
#define tSphere 339
#define tPolarSphere 340
#define tSurface 341
#define tSpline 342
#define tVolume 343
#define tCharacteristic 344
#define tLength 345
#define tParametric 346
#define tElliptic 347
#define tRefineMesh 348
#define tAdaptMesh 349
#define tRelocateMesh 350
#define tPlane 351
#define tRuled 352
#define tTransfinite 353
#define tComplex 354
#define tPhysical 355
#define tCompound 356
#define tPeriodic 357
#define tUsing 358
#define tPlugin 359
#define tDegenerated 360
#define tRecursive 361
#define tRotate 362
#define tTranslate 363
#define tSymmetry 364
#define tDilate 365
#define tExtrude 366
#define tLevelset 367
#define tAffine 368
#define tRecombine 369
#define tSmoother 370
#define tSplit 371
#define tDelete 372
#define tCoherence 373
#define tIntersect 374
#define tMeshAlgorithm 375
#define tReverse 376
#define tLayers 377
#define tScaleLast 378
#define tHole 379
#define tAlias 380
#define tAliasWithOptions 381
#define tCopyOptions 382
#define tQuadTriAddVerts 383
#define tQuadTriNoNewVerts 384
#define tQuadTriSngl 385
#define tQuadTriDbl 386
#define tRecombLaterals 387
#define tTransfQuadTri 388
#define tText2D 389
#define tText3D 390
#define tInterpolationScheme 391
#define tTime 392
#define tCombine 393
#define tBSpline 394
#define tBezier 395
#define tNurbs 396
#define tNurbsOrder 397
#define tNurbsKnots 398
#define tColor 399
#define tColorTable 400
#define tFor 401
#define tIn 402
#define tEndFor 403
#define tIf 404
#define tElseIf 405
#define tElse 406
#define tEndIf 407
#define tExit 408
#define tAbort 409
#define tField 410
#define tReturn 411
#define tCall 412
#define tSlide 413
#define tMacro 414
#define tShow 415
#define tHide 416
#define tGetValue 417
#define tGetStringValue 418
#define tGetEnv 419
#define tGetString 420
#define tGetNumber 421
#define tHomology 422
#define tCohomology 423
#define tBetti 424
#define tExists 425
#define tFileExists 426
#define tGMSH_MAJOR_VERSION 427
#define tGMSH_MINOR_VERSION 428
#define tGMSH_PATCH_VERSION 429
#define tGmshExecutableName 430
#define tSetPartition 431
#define tNameToString 432
#define tStringToName 433
#define tAFFECTDIVIDE 434
#define tAFFECTTIMES 435
#define tAFFECTMINUS 436
#define tAFFECTPLUS 437
#define tOR 438
#define tAND 439
#define tNOTEQUAL 440
#define tEQUAL 441
#define tGREATEROREQUAL 442
#define tLESSOREQUAL 443
#define UNARYPREC 444
#define tMINUSMINUS 445
#define tPLUSPLUS 446




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
#line 441 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

