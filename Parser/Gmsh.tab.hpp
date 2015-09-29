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
     tExp = 269,
     tLog = 270,
     tLog10 = 271,
     tSqrt = 272,
     tSin = 273,
     tAsin = 274,
     tCos = 275,
     tAcos = 276,
     tTan = 277,
     tRand = 278,
     tAtan = 279,
     tAtan2 = 280,
     tSinh = 281,
     tCosh = 282,
     tTanh = 283,
     tFabs = 284,
     tFloor = 285,
     tCeil = 286,
     tRound = 287,
     tFmod = 288,
     tModulo = 289,
     tHypot = 290,
     tList = 291,
     tPrintf = 292,
     tError = 293,
     tStr = 294,
     tSprintf = 295,
     tStrCat = 296,
     tStrPrefix = 297,
     tStrRelative = 298,
     tStrReplace = 299,
     tFind = 300,
     tStrFind = 301,
     tStrCmp = 302,
     tStrChoice = 303,
     tUpperCase = 304,
     tLowerCase = 305,
     tLowerCaseIn = 306,
     tTextAttributes = 307,
     tBoundingBox = 308,
     tDraw = 309,
     tSetChanged = 310,
     tToday = 311,
     tFixRelativePath = 312,
     tCurrentDirectory = 313,
     tSyncModel = 314,
     tNewModel = 315,
     tOnelabAction = 316,
     tOnelabRun = 317,
     tCpu = 318,
     tMemory = 319,
     tTotalMemory = 320,
     tCreateTopology = 321,
     tCreateTopologyNoHoles = 322,
     tDistanceFunction = 323,
     tDefineConstant = 324,
     tUndefineConstant = 325,
     tDefineNumber = 326,
     tDefineString = 327,
     tSetNumber = 328,
     tSetString = 329,
     tPoint = 330,
     tCircle = 331,
     tEllipse = 332,
     tLine = 333,
     tSphere = 334,
     tPolarSphere = 335,
     tSurface = 336,
     tSpline = 337,
     tVolume = 338,
     tCharacteristic = 339,
     tLength = 340,
     tParametric = 341,
     tElliptic = 342,
     tRefineMesh = 343,
     tAdaptMesh = 344,
     tRelocateMesh = 345,
     tPlane = 346,
     tRuled = 347,
     tTransfinite = 348,
     tComplex = 349,
     tPhysical = 350,
     tCompound = 351,
     tPeriodic = 352,
     tUsing = 353,
     tPlugin = 354,
     tDegenerated = 355,
     tRecursive = 356,
     tRotate = 357,
     tTranslate = 358,
     tSymmetry = 359,
     tDilate = 360,
     tExtrude = 361,
     tLevelset = 362,
     tAffine = 363,
     tRecombine = 364,
     tSmoother = 365,
     tSplit = 366,
     tDelete = 367,
     tCoherence = 368,
     tIntersect = 369,
     tMeshAlgorithm = 370,
     tReverse = 371,
     tLayers = 372,
     tScaleLast = 373,
     tHole = 374,
     tAlias = 375,
     tAliasWithOptions = 376,
     tCopyOptions = 377,
     tQuadTriAddVerts = 378,
     tQuadTriNoNewVerts = 379,
     tQuadTriSngl = 380,
     tQuadTriDbl = 381,
     tRecombLaterals = 382,
     tTransfQuadTri = 383,
     tText2D = 384,
     tText3D = 385,
     tInterpolationScheme = 386,
     tTime = 387,
     tCombine = 388,
     tBSpline = 389,
     tBezier = 390,
     tNurbs = 391,
     tNurbsOrder = 392,
     tNurbsKnots = 393,
     tColor = 394,
     tColorTable = 395,
     tFor = 396,
     tIn = 397,
     tEndFor = 398,
     tIf = 399,
     tEndIf = 400,
     tExit = 401,
     tAbort = 402,
     tField = 403,
     tReturn = 404,
     tCall = 405,
     tMacro = 406,
     tShow = 407,
     tHide = 408,
     tGetValue = 409,
     tGetEnv = 410,
     tGetString = 411,
     tGetNumber = 412,
     tHomology = 413,
     tCohomology = 414,
     tBetti = 415,
     tSetOrder = 416,
     tExists = 417,
     tFileExists = 418,
     tGMSH_MAJOR_VERSION = 419,
     tGMSH_MINOR_VERSION = 420,
     tGMSH_PATCH_VERSION = 421,
     tGmshExecutableName = 422,
     tSetPartition = 423,
     tNameFromString = 424,
     tStringFromName = 425,
     tAFFECTDIVIDE = 426,
     tAFFECTTIMES = 427,
     tAFFECTMINUS = 428,
     tAFFECTPLUS = 429,
     tOR = 430,
     tAND = 431,
     tNOTEQUAL = 432,
     tEQUAL = 433,
     tGREATEROREQUAL = 434,
     tLESSOREQUAL = 435,
     UNARYPREC = 436,
     tMINUSMINUS = 437,
     tPLUSPLUS = 438
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
#define tExp 269
#define tLog 270
#define tLog10 271
#define tSqrt 272
#define tSin 273
#define tAsin 274
#define tCos 275
#define tAcos 276
#define tTan 277
#define tRand 278
#define tAtan 279
#define tAtan2 280
#define tSinh 281
#define tCosh 282
#define tTanh 283
#define tFabs 284
#define tFloor 285
#define tCeil 286
#define tRound 287
#define tFmod 288
#define tModulo 289
#define tHypot 290
#define tList 291
#define tPrintf 292
#define tError 293
#define tStr 294
#define tSprintf 295
#define tStrCat 296
#define tStrPrefix 297
#define tStrRelative 298
#define tStrReplace 299
#define tFind 300
#define tStrFind 301
#define tStrCmp 302
#define tStrChoice 303
#define tUpperCase 304
#define tLowerCase 305
#define tLowerCaseIn 306
#define tTextAttributes 307
#define tBoundingBox 308
#define tDraw 309
#define tSetChanged 310
#define tToday 311
#define tFixRelativePath 312
#define tCurrentDirectory 313
#define tSyncModel 314
#define tNewModel 315
#define tOnelabAction 316
#define tOnelabRun 317
#define tCpu 318
#define tMemory 319
#define tTotalMemory 320
#define tCreateTopology 321
#define tCreateTopologyNoHoles 322
#define tDistanceFunction 323
#define tDefineConstant 324
#define tUndefineConstant 325
#define tDefineNumber 326
#define tDefineString 327
#define tSetNumber 328
#define tSetString 329
#define tPoint 330
#define tCircle 331
#define tEllipse 332
#define tLine 333
#define tSphere 334
#define tPolarSphere 335
#define tSurface 336
#define tSpline 337
#define tVolume 338
#define tCharacteristic 339
#define tLength 340
#define tParametric 341
#define tElliptic 342
#define tRefineMesh 343
#define tAdaptMesh 344
#define tRelocateMesh 345
#define tPlane 346
#define tRuled 347
#define tTransfinite 348
#define tComplex 349
#define tPhysical 350
#define tCompound 351
#define tPeriodic 352
#define tUsing 353
#define tPlugin 354
#define tDegenerated 355
#define tRecursive 356
#define tRotate 357
#define tTranslate 358
#define tSymmetry 359
#define tDilate 360
#define tExtrude 361
#define tLevelset 362
#define tAffine 363
#define tRecombine 364
#define tSmoother 365
#define tSplit 366
#define tDelete 367
#define tCoherence 368
#define tIntersect 369
#define tMeshAlgorithm 370
#define tReverse 371
#define tLayers 372
#define tScaleLast 373
#define tHole 374
#define tAlias 375
#define tAliasWithOptions 376
#define tCopyOptions 377
#define tQuadTriAddVerts 378
#define tQuadTriNoNewVerts 379
#define tQuadTriSngl 380
#define tQuadTriDbl 381
#define tRecombLaterals 382
#define tTransfQuadTri 383
#define tText2D 384
#define tText3D 385
#define tInterpolationScheme 386
#define tTime 387
#define tCombine 388
#define tBSpline 389
#define tBezier 390
#define tNurbs 391
#define tNurbsOrder 392
#define tNurbsKnots 393
#define tColor 394
#define tColorTable 395
#define tFor 396
#define tIn 397
#define tEndFor 398
#define tIf 399
#define tEndIf 400
#define tExit 401
#define tAbort 402
#define tField 403
#define tReturn 404
#define tCall 405
#define tMacro 406
#define tShow 407
#define tHide 408
#define tGetValue 409
#define tGetEnv 410
#define tGetString 411
#define tGetNumber 412
#define tHomology 413
#define tCohomology 414
#define tBetti 415
#define tSetOrder 416
#define tExists 417
#define tFileExists 418
#define tGMSH_MAJOR_VERSION 419
#define tGMSH_MINOR_VERSION 420
#define tGMSH_PATCH_VERSION 421
#define tGmshExecutableName 422
#define tSetPartition 423
#define tNameFromString 424
#define tStringFromName 425
#define tAFFECTDIVIDE 426
#define tAFFECTTIMES 427
#define tAFFECTMINUS 428
#define tAFFECTPLUS 429
#define tOR 430
#define tAND 431
#define tNOTEQUAL 432
#define tEQUAL 433
#define tGREATEROREQUAL 434
#define tLESSOREQUAL 435
#define UNARYPREC 436
#define tMINUSMINUS 437
#define tPLUSPLUS 438




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 105 "Gmsh.y"
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
#line 425 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

