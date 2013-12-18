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
     tCpu = 307,
     tMemory = 308,
     tSyncModel = 309,
     tCreateTopology = 310,
     tCreateTopologyNoHoles = 311,
     tDistanceFunction = 312,
     tDefineConstant = 313,
     tUndefineConstant = 314,
     tPoint = 315,
     tCircle = 316,
     tEllipse = 317,
     tLine = 318,
     tSphere = 319,
     tPolarSphere = 320,
     tSurface = 321,
     tSpline = 322,
     tVolume = 323,
     tCharacteristic = 324,
     tLength = 325,
     tParametric = 326,
     tElliptic = 327,
     tRefineMesh = 328,
     tAdaptMesh = 329,
     tRelocateMesh = 330,
     tPlane = 331,
     tRuled = 332,
     tTransfinite = 333,
     tComplex = 334,
     tPhysical = 335,
     tCompound = 336,
     tPeriodic = 337,
     tUsing = 338,
     tPlugin = 339,
     tDegenerated = 340,
     tRecursive = 341,
     tRotate = 342,
     tTranslate = 343,
     tSymmetry = 344,
     tDilate = 345,
     tExtrude = 346,
     tLevelset = 347,
     tRecombine = 348,
     tSmoother = 349,
     tSplit = 350,
     tDelete = 351,
     tCoherence = 352,
     tIntersect = 353,
     tMeshAlgorithm = 354,
     tReverse = 355,
     tLayers = 356,
     tScaleLast = 357,
     tHole = 358,
     tAlias = 359,
     tAliasWithOptions = 360,
     tCopyOptions = 361,
     tQuadTriAddVerts = 362,
     tQuadTriNoNewVerts = 363,
     tQuadTriSngl = 364,
     tQuadTriDbl = 365,
     tRecombLaterals = 366,
     tTransfQuadTri = 367,
     tText2D = 368,
     tText3D = 369,
     tInterpolationScheme = 370,
     tTime = 371,
     tCombine = 372,
     tBSpline = 373,
     tBezier = 374,
     tNurbs = 375,
     tNurbsOrder = 376,
     tNurbsKnots = 377,
     tColor = 378,
     tColorTable = 379,
     tFor = 380,
     tIn = 381,
     tEndFor = 382,
     tIf = 383,
     tEndIf = 384,
     tExit = 385,
     tAbort = 386,
     tField = 387,
     tReturn = 388,
     tCall = 389,
     tFunction = 390,
     tShow = 391,
     tHide = 392,
     tGetValue = 393,
     tGetEnv = 394,
     tGetString = 395,
     tHomology = 396,
     tCohomology = 397,
     tBetti = 398,
     tSetOrder = 399,
     tGMSH_MAJOR_VERSION = 400,
     tGMSH_MINOR_VERSION = 401,
     tGMSH_PATCH_VERSION = 402,
     tAFFECTDIVIDE = 403,
     tAFFECTTIMES = 404,
     tAFFECTMINUS = 405,
     tAFFECTPLUS = 406,
     tOR = 407,
     tAND = 408,
     tNOTEQUAL = 409,
     tEQUAL = 410,
     tGREATEROREQUAL = 411,
     tLESSOREQUAL = 412,
     UNARYPREC = 413,
     tMINUSMINUS = 414,
     tPLUSPLUS = 415
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
#define tCpu 307
#define tMemory 308
#define tSyncModel 309
#define tCreateTopology 310
#define tCreateTopologyNoHoles 311
#define tDistanceFunction 312
#define tDefineConstant 313
#define tUndefineConstant 314
#define tPoint 315
#define tCircle 316
#define tEllipse 317
#define tLine 318
#define tSphere 319
#define tPolarSphere 320
#define tSurface 321
#define tSpline 322
#define tVolume 323
#define tCharacteristic 324
#define tLength 325
#define tParametric 326
#define tElliptic 327
#define tRefineMesh 328
#define tAdaptMesh 329
#define tRelocateMesh 330
#define tPlane 331
#define tRuled 332
#define tTransfinite 333
#define tComplex 334
#define tPhysical 335
#define tCompound 336
#define tPeriodic 337
#define tUsing 338
#define tPlugin 339
#define tDegenerated 340
#define tRecursive 341
#define tRotate 342
#define tTranslate 343
#define tSymmetry 344
#define tDilate 345
#define tExtrude 346
#define tLevelset 347
#define tRecombine 348
#define tSmoother 349
#define tSplit 350
#define tDelete 351
#define tCoherence 352
#define tIntersect 353
#define tMeshAlgorithm 354
#define tReverse 355
#define tLayers 356
#define tScaleLast 357
#define tHole 358
#define tAlias 359
#define tAliasWithOptions 360
#define tCopyOptions 361
#define tQuadTriAddVerts 362
#define tQuadTriNoNewVerts 363
#define tQuadTriSngl 364
#define tQuadTriDbl 365
#define tRecombLaterals 366
#define tTransfQuadTri 367
#define tText2D 368
#define tText3D 369
#define tInterpolationScheme 370
#define tTime 371
#define tCombine 372
#define tBSpline 373
#define tBezier 374
#define tNurbs 375
#define tNurbsOrder 376
#define tNurbsKnots 377
#define tColor 378
#define tColorTable 379
#define tFor 380
#define tIn 381
#define tEndFor 382
#define tIf 383
#define tEndIf 384
#define tExit 385
#define tAbort 386
#define tField 387
#define tReturn 388
#define tCall 389
#define tFunction 390
#define tShow 391
#define tHide 392
#define tGetValue 393
#define tGetEnv 394
#define tGetString 395
#define tHomology 396
#define tCohomology 397
#define tBetti 398
#define tSetOrder 399
#define tGMSH_MAJOR_VERSION 400
#define tGMSH_MINOR_VERSION 401
#define tGMSH_PATCH_VERSION 402
#define tAFFECTDIVIDE 403
#define tAFFECTTIMES 404
#define tAFFECTMINUS 405
#define tAFFECTPLUS 406
#define tOR 407
#define tAND 408
#define tNOTEQUAL 409
#define tEQUAL 410
#define tGREATEROREQUAL 411
#define tLESSOREQUAL 412
#define UNARYPREC 413
#define tMINUSMINUS 414
#define tPLUSPLUS 415




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 93 "Gmsh.y"
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
#line 379 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

