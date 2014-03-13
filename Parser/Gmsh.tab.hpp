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
     tCpu = 308,
     tMemory = 309,
     tSyncModel = 310,
     tCreateTopology = 311,
     tCreateTopologyNoHoles = 312,
     tDistanceFunction = 313,
     tDefineConstant = 314,
     tUndefineConstant = 315,
     tPoint = 316,
     tCircle = 317,
     tEllipse = 318,
     tLine = 319,
     tSphere = 320,
     tPolarSphere = 321,
     tSurface = 322,
     tSpline = 323,
     tVolume = 324,
     tCharacteristic = 325,
     tLength = 326,
     tParametric = 327,
     tElliptic = 328,
     tRefineMesh = 329,
     tAdaptMesh = 330,
     tRelocateMesh = 331,
     tPlane = 332,
     tRuled = 333,
     tTransfinite = 334,
     tComplex = 335,
     tPhysical = 336,
     tCompound = 337,
     tPeriodic = 338,
     tUsing = 339,
     tPlugin = 340,
     tDegenerated = 341,
     tRecursive = 342,
     tRotate = 343,
     tTranslate = 344,
     tSymmetry = 345,
     tDilate = 346,
     tExtrude = 347,
     tLevelset = 348,
     tRecombine = 349,
     tSmoother = 350,
     tSplit = 351,
     tDelete = 352,
     tCoherence = 353,
     tIntersect = 354,
     tMeshAlgorithm = 355,
     tReverse = 356,
     tLayers = 357,
     tScaleLast = 358,
     tHole = 359,
     tAlias = 360,
     tAliasWithOptions = 361,
     tCopyOptions = 362,
     tQuadTriAddVerts = 363,
     tQuadTriNoNewVerts = 364,
     tQuadTriSngl = 365,
     tQuadTriDbl = 366,
     tRecombLaterals = 367,
     tTransfQuadTri = 368,
     tText2D = 369,
     tText3D = 370,
     tInterpolationScheme = 371,
     tTime = 372,
     tCombine = 373,
     tBSpline = 374,
     tBezier = 375,
     tNurbs = 376,
     tNurbsOrder = 377,
     tNurbsKnots = 378,
     tColor = 379,
     tColorTable = 380,
     tFor = 381,
     tIn = 382,
     tEndFor = 383,
     tIf = 384,
     tEndIf = 385,
     tExit = 386,
     tAbort = 387,
     tField = 388,
     tReturn = 389,
     tCall = 390,
     tFunction = 391,
     tShow = 392,
     tHide = 393,
     tGetValue = 394,
     tGetEnv = 395,
     tGetString = 396,
     tHomology = 397,
     tCohomology = 398,
     tBetti = 399,
     tSetOrder = 400,
     tGMSH_MAJOR_VERSION = 401,
     tGMSH_MINOR_VERSION = 402,
     tGMSH_PATCH_VERSION = 403,
     tAFFECTDIVIDE = 404,
     tAFFECTTIMES = 405,
     tAFFECTMINUS = 406,
     tAFFECTPLUS = 407,
     tOR = 408,
     tAND = 409,
     tNOTEQUAL = 410,
     tEQUAL = 411,
     tGREATEROREQUAL = 412,
     tLESSOREQUAL = 413,
     UNARYPREC = 414,
     tMINUSMINUS = 415,
     tPLUSPLUS = 416
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
#define tCpu 308
#define tMemory 309
#define tSyncModel 310
#define tCreateTopology 311
#define tCreateTopologyNoHoles 312
#define tDistanceFunction 313
#define tDefineConstant 314
#define tUndefineConstant 315
#define tPoint 316
#define tCircle 317
#define tEllipse 318
#define tLine 319
#define tSphere 320
#define tPolarSphere 321
#define tSurface 322
#define tSpline 323
#define tVolume 324
#define tCharacteristic 325
#define tLength 326
#define tParametric 327
#define tElliptic 328
#define tRefineMesh 329
#define tAdaptMesh 330
#define tRelocateMesh 331
#define tPlane 332
#define tRuled 333
#define tTransfinite 334
#define tComplex 335
#define tPhysical 336
#define tCompound 337
#define tPeriodic 338
#define tUsing 339
#define tPlugin 340
#define tDegenerated 341
#define tRecursive 342
#define tRotate 343
#define tTranslate 344
#define tSymmetry 345
#define tDilate 346
#define tExtrude 347
#define tLevelset 348
#define tRecombine 349
#define tSmoother 350
#define tSplit 351
#define tDelete 352
#define tCoherence 353
#define tIntersect 354
#define tMeshAlgorithm 355
#define tReverse 356
#define tLayers 357
#define tScaleLast 358
#define tHole 359
#define tAlias 360
#define tAliasWithOptions 361
#define tCopyOptions 362
#define tQuadTriAddVerts 363
#define tQuadTriNoNewVerts 364
#define tQuadTriSngl 365
#define tQuadTriDbl 366
#define tRecombLaterals 367
#define tTransfQuadTri 368
#define tText2D 369
#define tText3D 370
#define tInterpolationScheme 371
#define tTime 372
#define tCombine 373
#define tBSpline 374
#define tBezier 375
#define tNurbs 376
#define tNurbsOrder 377
#define tNurbsKnots 378
#define tColor 379
#define tColorTable 380
#define tFor 381
#define tIn 382
#define tEndFor 383
#define tIf 384
#define tEndIf 385
#define tExit 386
#define tAbort 387
#define tField 388
#define tReturn 389
#define tCall 390
#define tFunction 391
#define tShow 392
#define tHide 393
#define tGetValue 394
#define tGetEnv 395
#define tGetString 396
#define tHomology 397
#define tCohomology 398
#define tBetti 399
#define tSetOrder 400
#define tGMSH_MAJOR_VERSION 401
#define tGMSH_MINOR_VERSION 402
#define tGMSH_PATCH_VERSION 403
#define tAFFECTDIVIDE 404
#define tAFFECTTIMES 405
#define tAFFECTMINUS 406
#define tAFFECTPLUS 407
#define tOR 408
#define tAND 409
#define tNOTEQUAL 410
#define tEQUAL 411
#define tGREATEROREQUAL 412
#define tLESSOREQUAL 413
#define UNARYPREC 414
#define tMINUSMINUS 415
#define tPLUSPLUS 416




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
#line 381 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

