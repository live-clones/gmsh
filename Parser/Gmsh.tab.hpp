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
     tStrFind = 300,
     tStrCmp = 301,
     tTextAttributes = 302,
     tBoundingBox = 303,
     tDraw = 304,
     tSetChanged = 305,
     tToday = 306,
     tOnelabAction = 307,
     tSyncModel = 308,
     tCpu = 309,
     tMemory = 310,
     tTotalMemory = 311,
     tCreateTopology = 312,
     tCreateTopologyNoHoles = 313,
     tDistanceFunction = 314,
     tDefineConstant = 315,
     tUndefineConstant = 316,
     tDefineNumber = 317,
     tDefineString = 318,
     tPoint = 319,
     tCircle = 320,
     tEllipse = 321,
     tLine = 322,
     tSphere = 323,
     tPolarSphere = 324,
     tSurface = 325,
     tSpline = 326,
     tVolume = 327,
     tCharacteristic = 328,
     tLength = 329,
     tParametric = 330,
     tElliptic = 331,
     tRefineMesh = 332,
     tAdaptMesh = 333,
     tRelocateMesh = 334,
     tPlane = 335,
     tRuled = 336,
     tTransfinite = 337,
     tComplex = 338,
     tPhysical = 339,
     tCompound = 340,
     tPeriodic = 341,
     tUsing = 342,
     tPlugin = 343,
     tDegenerated = 344,
     tRecursive = 345,
     tRotate = 346,
     tTranslate = 347,
     tSymmetry = 348,
     tDilate = 349,
     tExtrude = 350,
     tLevelset = 351,
     tRecombine = 352,
     tSmoother = 353,
     tSplit = 354,
     tDelete = 355,
     tCoherence = 356,
     tIntersect = 357,
     tMeshAlgorithm = 358,
     tReverse = 359,
     tLayers = 360,
     tScaleLast = 361,
     tHole = 362,
     tAlias = 363,
     tAliasWithOptions = 364,
     tCopyOptions = 365,
     tQuadTriAddVerts = 366,
     tQuadTriNoNewVerts = 367,
     tQuadTriSngl = 368,
     tQuadTriDbl = 369,
     tRecombLaterals = 370,
     tTransfQuadTri = 371,
     tText2D = 372,
     tText3D = 373,
     tInterpolationScheme = 374,
     tTime = 375,
     tCombine = 376,
     tBSpline = 377,
     tBezier = 378,
     tNurbs = 379,
     tNurbsOrder = 380,
     tNurbsKnots = 381,
     tColor = 382,
     tColorTable = 383,
     tFor = 384,
     tIn = 385,
     tEndFor = 386,
     tIf = 387,
     tEndIf = 388,
     tExit = 389,
     tAbort = 390,
     tField = 391,
     tReturn = 392,
     tCall = 393,
     tFunction = 394,
     tShow = 395,
     tHide = 396,
     tGetValue = 397,
     tGetEnv = 398,
     tGetString = 399,
     tHomology = 400,
     tCohomology = 401,
     tBetti = 402,
     tSetOrder = 403,
     tExists = 404,
     tFileExists = 405,
     tGMSH_MAJOR_VERSION = 406,
     tGMSH_MINOR_VERSION = 407,
     tGMSH_PATCH_VERSION = 408,
     tAFFECTDIVIDE = 409,
     tAFFECTTIMES = 410,
     tAFFECTMINUS = 411,
     tAFFECTPLUS = 412,
     tOR = 413,
     tAND = 414,
     tNOTEQUAL = 415,
     tEQUAL = 416,
     tGREATEROREQUAL = 417,
     tLESSOREQUAL = 418,
     UNARYPREC = 419,
     tMINUSMINUS = 420,
     tPLUSPLUS = 421
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
#define tStrFind 300
#define tStrCmp 301
#define tTextAttributes 302
#define tBoundingBox 303
#define tDraw 304
#define tSetChanged 305
#define tToday 306
#define tOnelabAction 307
#define tSyncModel 308
#define tCpu 309
#define tMemory 310
#define tTotalMemory 311
#define tCreateTopology 312
#define tCreateTopologyNoHoles 313
#define tDistanceFunction 314
#define tDefineConstant 315
#define tUndefineConstant 316
#define tDefineNumber 317
#define tDefineString 318
#define tPoint 319
#define tCircle 320
#define tEllipse 321
#define tLine 322
#define tSphere 323
#define tPolarSphere 324
#define tSurface 325
#define tSpline 326
#define tVolume 327
#define tCharacteristic 328
#define tLength 329
#define tParametric 330
#define tElliptic 331
#define tRefineMesh 332
#define tAdaptMesh 333
#define tRelocateMesh 334
#define tPlane 335
#define tRuled 336
#define tTransfinite 337
#define tComplex 338
#define tPhysical 339
#define tCompound 340
#define tPeriodic 341
#define tUsing 342
#define tPlugin 343
#define tDegenerated 344
#define tRecursive 345
#define tRotate 346
#define tTranslate 347
#define tSymmetry 348
#define tDilate 349
#define tExtrude 350
#define tLevelset 351
#define tRecombine 352
#define tSmoother 353
#define tSplit 354
#define tDelete 355
#define tCoherence 356
#define tIntersect 357
#define tMeshAlgorithm 358
#define tReverse 359
#define tLayers 360
#define tScaleLast 361
#define tHole 362
#define tAlias 363
#define tAliasWithOptions 364
#define tCopyOptions 365
#define tQuadTriAddVerts 366
#define tQuadTriNoNewVerts 367
#define tQuadTriSngl 368
#define tQuadTriDbl 369
#define tRecombLaterals 370
#define tTransfQuadTri 371
#define tText2D 372
#define tText3D 373
#define tInterpolationScheme 374
#define tTime 375
#define tCombine 376
#define tBSpline 377
#define tBezier 378
#define tNurbs 379
#define tNurbsOrder 380
#define tNurbsKnots 381
#define tColor 382
#define tColorTable 383
#define tFor 384
#define tIn 385
#define tEndFor 386
#define tIf 387
#define tEndIf 388
#define tExit 389
#define tAbort 390
#define tField 391
#define tReturn 392
#define tCall 393
#define tFunction 394
#define tShow 395
#define tHide 396
#define tGetValue 397
#define tGetEnv 398
#define tGetString 399
#define tHomology 400
#define tCohomology 401
#define tBetti 402
#define tSetOrder 403
#define tExists 404
#define tFileExists 405
#define tGMSH_MAJOR_VERSION 406
#define tGMSH_MINOR_VERSION 407
#define tGMSH_PATCH_VERSION 408
#define tAFFECTDIVIDE 409
#define tAFFECTTIMES 410
#define tAFFECTMINUS 411
#define tAFFECTPLUS 412
#define tOR 413
#define tAND 414
#define tNOTEQUAL 415
#define tEQUAL 416
#define tGREATEROREQUAL 417
#define tLESSOREQUAL 418
#define UNARYPREC 419
#define tMINUSMINUS 420
#define tPLUSPLUS 421




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 100 "Gmsh.y"
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
#line 391 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

