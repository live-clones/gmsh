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
     tFixRelativePath = 307,
     tSyncModel = 308,
     tOnelabAction = 309,
     tOnelabRun = 310,
     tCpu = 311,
     tMemory = 312,
     tTotalMemory = 313,
     tCreateTopology = 314,
     tCreateTopologyNoHoles = 315,
     tDistanceFunction = 316,
     tDefineConstant = 317,
     tUndefineConstant = 318,
     tDefineNumber = 319,
     tDefineString = 320,
     tPoint = 321,
     tCircle = 322,
     tEllipse = 323,
     tLine = 324,
     tSphere = 325,
     tPolarSphere = 326,
     tSurface = 327,
     tSpline = 328,
     tVolume = 329,
     tCharacteristic = 330,
     tLength = 331,
     tParametric = 332,
     tElliptic = 333,
     tRefineMesh = 334,
     tAdaptMesh = 335,
     tRelocateMesh = 336,
     tPlane = 337,
     tRuled = 338,
     tTransfinite = 339,
     tComplex = 340,
     tPhysical = 341,
     tCompound = 342,
     tPeriodic = 343,
     tUsing = 344,
     tPlugin = 345,
     tDegenerated = 346,
     tRecursive = 347,
     tRotate = 348,
     tTranslate = 349,
     tSymmetry = 350,
     tDilate = 351,
     tExtrude = 352,
     tLevelset = 353,
     tRecombine = 354,
     tSmoother = 355,
     tSplit = 356,
     tDelete = 357,
     tCoherence = 358,
     tIntersect = 359,
     tMeshAlgorithm = 360,
     tReverse = 361,
     tLayers = 362,
     tScaleLast = 363,
     tHole = 364,
     tAlias = 365,
     tAliasWithOptions = 366,
     tCopyOptions = 367,
     tQuadTriAddVerts = 368,
     tQuadTriNoNewVerts = 369,
     tQuadTriSngl = 370,
     tQuadTriDbl = 371,
     tRecombLaterals = 372,
     tTransfQuadTri = 373,
     tText2D = 374,
     tText3D = 375,
     tInterpolationScheme = 376,
     tTime = 377,
     tCombine = 378,
     tBSpline = 379,
     tBezier = 380,
     tNurbs = 381,
     tNurbsOrder = 382,
     tNurbsKnots = 383,
     tColor = 384,
     tColorTable = 385,
     tFor = 386,
     tIn = 387,
     tEndFor = 388,
     tIf = 389,
     tEndIf = 390,
     tExit = 391,
     tAbort = 392,
     tField = 393,
     tReturn = 394,
     tCall = 395,
     tFunction = 396,
     tShow = 397,
     tHide = 398,
     tGetValue = 399,
     tGetEnv = 400,
     tGetString = 401,
     tHomology = 402,
     tCohomology = 403,
     tBetti = 404,
     tSetOrder = 405,
     tExists = 406,
     tFileExists = 407,
     tGMSH_MAJOR_VERSION = 408,
     tGMSH_MINOR_VERSION = 409,
     tGMSH_PATCH_VERSION = 410,
     tAFFECTDIVIDE = 411,
     tAFFECTTIMES = 412,
     tAFFECTMINUS = 413,
     tAFFECTPLUS = 414,
     tOR = 415,
     tAND = 416,
     tNOTEQUAL = 417,
     tEQUAL = 418,
     tGREATEROREQUAL = 419,
     tLESSOREQUAL = 420,
     UNARYPREC = 421,
     tMINUSMINUS = 422,
     tPLUSPLUS = 423
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
#define tFixRelativePath 307
#define tSyncModel 308
#define tOnelabAction 309
#define tOnelabRun 310
#define tCpu 311
#define tMemory 312
#define tTotalMemory 313
#define tCreateTopology 314
#define tCreateTopologyNoHoles 315
#define tDistanceFunction 316
#define tDefineConstant 317
#define tUndefineConstant 318
#define tDefineNumber 319
#define tDefineString 320
#define tPoint 321
#define tCircle 322
#define tEllipse 323
#define tLine 324
#define tSphere 325
#define tPolarSphere 326
#define tSurface 327
#define tSpline 328
#define tVolume 329
#define tCharacteristic 330
#define tLength 331
#define tParametric 332
#define tElliptic 333
#define tRefineMesh 334
#define tAdaptMesh 335
#define tRelocateMesh 336
#define tPlane 337
#define tRuled 338
#define tTransfinite 339
#define tComplex 340
#define tPhysical 341
#define tCompound 342
#define tPeriodic 343
#define tUsing 344
#define tPlugin 345
#define tDegenerated 346
#define tRecursive 347
#define tRotate 348
#define tTranslate 349
#define tSymmetry 350
#define tDilate 351
#define tExtrude 352
#define tLevelset 353
#define tRecombine 354
#define tSmoother 355
#define tSplit 356
#define tDelete 357
#define tCoherence 358
#define tIntersect 359
#define tMeshAlgorithm 360
#define tReverse 361
#define tLayers 362
#define tScaleLast 363
#define tHole 364
#define tAlias 365
#define tAliasWithOptions 366
#define tCopyOptions 367
#define tQuadTriAddVerts 368
#define tQuadTriNoNewVerts 369
#define tQuadTriSngl 370
#define tQuadTriDbl 371
#define tRecombLaterals 372
#define tTransfQuadTri 373
#define tText2D 374
#define tText3D 375
#define tInterpolationScheme 376
#define tTime 377
#define tCombine 378
#define tBSpline 379
#define tBezier 380
#define tNurbs 381
#define tNurbsOrder 382
#define tNurbsKnots 383
#define tColor 384
#define tColorTable 385
#define tFor 386
#define tIn 387
#define tEndFor 388
#define tIf 389
#define tEndIf 390
#define tExit 391
#define tAbort 392
#define tField 393
#define tReturn 394
#define tCall 395
#define tFunction 396
#define tShow 397
#define tHide 398
#define tGetValue 399
#define tGetEnv 400
#define tGetString 401
#define tHomology 402
#define tCohomology 403
#define tBetti 404
#define tSetOrder 405
#define tExists 406
#define tFileExists 407
#define tGMSH_MAJOR_VERSION 408
#define tGMSH_MINOR_VERSION 409
#define tGMSH_PATCH_VERSION 410
#define tAFFECTDIVIDE 411
#define tAFFECTTIMES 412
#define tAFFECTMINUS 413
#define tAFFECTPLUS 414
#define tOR 415
#define tAND 416
#define tNOTEQUAL 417
#define tEQUAL 418
#define tGREATEROREQUAL 419
#define tLESSOREQUAL 420
#define UNARYPREC 421
#define tMINUSMINUS 422
#define tPLUSPLUS 423




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 99 "Gmsh.y"
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
#line 395 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

