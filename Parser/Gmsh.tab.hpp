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
     tFind = 301,
     tStrFind = 302,
     tStrCmp = 303,
     tStrChoice = 304,
     tUpperCase = 305,
     tLowerCase = 306,
     tLowerCaseIn = 307,
     tTextAttributes = 308,
     tBoundingBox = 309,
     tDraw = 310,
     tSetChanged = 311,
     tToday = 312,
     tFixRelativePath = 313,
     tCurrentDirectory = 314,
     tSyncModel = 315,
     tNewModel = 316,
     tOnelabAction = 317,
     tOnelabRun = 318,
     tCpu = 319,
     tMemory = 320,
     tTotalMemory = 321,
     tCreateTopology = 322,
     tCreateTopologyNoHoles = 323,
     tDistanceFunction = 324,
     tDefineConstant = 325,
     tUndefineConstant = 326,
     tDefineNumber = 327,
     tDefineString = 328,
     tSetNumber = 329,
     tSetString = 330,
     tPoint = 331,
     tCircle = 332,
     tEllipse = 333,
     tLine = 334,
     tSphere = 335,
     tPolarSphere = 336,
     tSurface = 337,
     tSpline = 338,
     tVolume = 339,
     tCharacteristic = 340,
     tLength = 341,
     tParametric = 342,
     tElliptic = 343,
     tRefineMesh = 344,
     tAdaptMesh = 345,
     tRelocateMesh = 346,
     tPlane = 347,
     tRuled = 348,
     tTransfinite = 349,
     tComplex = 350,
     tPhysical = 351,
     tCompound = 352,
     tPeriodic = 353,
     tUsing = 354,
     tPlugin = 355,
     tDegenerated = 356,
     tRecursive = 357,
     tRotate = 358,
     tTranslate = 359,
     tSymmetry = 360,
     tDilate = 361,
     tExtrude = 362,
     tLevelset = 363,
     tAffine = 364,
     tRecombine = 365,
     tSmoother = 366,
     tSplit = 367,
     tDelete = 368,
     tCoherence = 369,
     tIntersect = 370,
     tMeshAlgorithm = 371,
     tReverse = 372,
     tLayers = 373,
     tScaleLast = 374,
     tHole = 375,
     tAlias = 376,
     tAliasWithOptions = 377,
     tCopyOptions = 378,
     tQuadTriAddVerts = 379,
     tQuadTriNoNewVerts = 380,
     tQuadTriSngl = 381,
     tQuadTriDbl = 382,
     tRecombLaterals = 383,
     tTransfQuadTri = 384,
     tText2D = 385,
     tText3D = 386,
     tInterpolationScheme = 387,
     tTime = 388,
     tCombine = 389,
     tBSpline = 390,
     tBezier = 391,
     tNurbs = 392,
     tNurbsOrder = 393,
     tNurbsKnots = 394,
     tColor = 395,
     tColorTable = 396,
     tFor = 397,
     tIn = 398,
     tEndFor = 399,
     tIf = 400,
     tElseIf = 401,
     tElse = 402,
     tEndIf = 403,
     tExit = 404,
     tAbort = 405,
     tField = 406,
     tReturn = 407,
     tCall = 408,
     tMacro = 409,
     tShow = 410,
     tHide = 411,
     tGetValue = 412,
     tGetEnv = 413,
     tGetString = 414,
     tGetNumber = 415,
     tHomology = 416,
     tCohomology = 417,
     tBetti = 418,
     tSetOrder = 419,
     tExists = 420,
     tFileExists = 421,
     tGMSH_MAJOR_VERSION = 422,
     tGMSH_MINOR_VERSION = 423,
     tGMSH_PATCH_VERSION = 424,
     tGmshExecutableName = 425,
     tSetPartition = 426,
     tNameFromString = 427,
     tStringFromName = 428,
     tAFFECTDIVIDE = 429,
     tAFFECTTIMES = 430,
     tAFFECTMINUS = 431,
     tAFFECTPLUS = 432,
     tOR = 433,
     tAND = 434,
     tNOTEQUAL = 435,
     tEQUAL = 436,
     tGREATEROREQUAL = 437,
     tLESSOREQUAL = 438,
     UNARYPREC = 439,
     tMINUSMINUS = 440,
     tPLUSPLUS = 441
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
#define tFind 301
#define tStrFind 302
#define tStrCmp 303
#define tStrChoice 304
#define tUpperCase 305
#define tLowerCase 306
#define tLowerCaseIn 307
#define tTextAttributes 308
#define tBoundingBox 309
#define tDraw 310
#define tSetChanged 311
#define tToday 312
#define tFixRelativePath 313
#define tCurrentDirectory 314
#define tSyncModel 315
#define tNewModel 316
#define tOnelabAction 317
#define tOnelabRun 318
#define tCpu 319
#define tMemory 320
#define tTotalMemory 321
#define tCreateTopology 322
#define tCreateTopologyNoHoles 323
#define tDistanceFunction 324
#define tDefineConstant 325
#define tUndefineConstant 326
#define tDefineNumber 327
#define tDefineString 328
#define tSetNumber 329
#define tSetString 330
#define tPoint 331
#define tCircle 332
#define tEllipse 333
#define tLine 334
#define tSphere 335
#define tPolarSphere 336
#define tSurface 337
#define tSpline 338
#define tVolume 339
#define tCharacteristic 340
#define tLength 341
#define tParametric 342
#define tElliptic 343
#define tRefineMesh 344
#define tAdaptMesh 345
#define tRelocateMesh 346
#define tPlane 347
#define tRuled 348
#define tTransfinite 349
#define tComplex 350
#define tPhysical 351
#define tCompound 352
#define tPeriodic 353
#define tUsing 354
#define tPlugin 355
#define tDegenerated 356
#define tRecursive 357
#define tRotate 358
#define tTranslate 359
#define tSymmetry 360
#define tDilate 361
#define tExtrude 362
#define tLevelset 363
#define tAffine 364
#define tRecombine 365
#define tSmoother 366
#define tSplit 367
#define tDelete 368
#define tCoherence 369
#define tIntersect 370
#define tMeshAlgorithm 371
#define tReverse 372
#define tLayers 373
#define tScaleLast 374
#define tHole 375
#define tAlias 376
#define tAliasWithOptions 377
#define tCopyOptions 378
#define tQuadTriAddVerts 379
#define tQuadTriNoNewVerts 380
#define tQuadTriSngl 381
#define tQuadTriDbl 382
#define tRecombLaterals 383
#define tTransfQuadTri 384
#define tText2D 385
#define tText3D 386
#define tInterpolationScheme 387
#define tTime 388
#define tCombine 389
#define tBSpline 390
#define tBezier 391
#define tNurbs 392
#define tNurbsOrder 393
#define tNurbsKnots 394
#define tColor 395
#define tColorTable 396
#define tFor 397
#define tIn 398
#define tEndFor 399
#define tIf 400
#define tElseIf 401
#define tElse 402
#define tEndIf 403
#define tExit 404
#define tAbort 405
#define tField 406
#define tReturn 407
#define tCall 408
#define tMacro 409
#define tShow 410
#define tHide 411
#define tGetValue 412
#define tGetEnv 413
#define tGetString 414
#define tGetNumber 415
#define tHomology 416
#define tCohomology 417
#define tBetti 418
#define tSetOrder 419
#define tExists 420
#define tFileExists 421
#define tGMSH_MAJOR_VERSION 422
#define tGMSH_MINOR_VERSION 423
#define tGMSH_PATCH_VERSION 424
#define tGmshExecutableName 425
#define tSetPartition 426
#define tNameFromString 427
#define tStringFromName 428
#define tAFFECTDIVIDE 429
#define tAFFECTTIMES 430
#define tAFFECTMINUS 431
#define tAFFECTPLUS 432
#define tOR 433
#define tAND 434
#define tNOTEQUAL 435
#define tEQUAL 436
#define tGREATEROREQUAL 437
#define tLESSOREQUAL 438
#define UNARYPREC 439
#define tMINUSMINUS 440
#define tPLUSPLUS 441




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 110 "Gmsh.y"
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
#line 431 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

