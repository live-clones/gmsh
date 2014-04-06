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
     tPoint = 317,
     tCircle = 318,
     tEllipse = 319,
     tLine = 320,
     tSphere = 321,
     tPolarSphere = 322,
     tSurface = 323,
     tSpline = 324,
     tVolume = 325,
     tCharacteristic = 326,
     tLength = 327,
     tParametric = 328,
     tElliptic = 329,
     tRefineMesh = 330,
     tAdaptMesh = 331,
     tRelocateMesh = 332,
     tPlane = 333,
     tRuled = 334,
     tTransfinite = 335,
     tComplex = 336,
     tPhysical = 337,
     tCompound = 338,
     tPeriodic = 339,
     tUsing = 340,
     tPlugin = 341,
     tDegenerated = 342,
     tRecursive = 343,
     tRotate = 344,
     tTranslate = 345,
     tSymmetry = 346,
     tDilate = 347,
     tExtrude = 348,
     tLevelset = 349,
     tRecombine = 350,
     tSmoother = 351,
     tSplit = 352,
     tDelete = 353,
     tCoherence = 354,
     tIntersect = 355,
     tMeshAlgorithm = 356,
     tReverse = 357,
     tLayers = 358,
     tScaleLast = 359,
     tHole = 360,
     tAlias = 361,
     tAliasWithOptions = 362,
     tCopyOptions = 363,
     tQuadTriAddVerts = 364,
     tQuadTriNoNewVerts = 365,
     tQuadTriSngl = 366,
     tQuadTriDbl = 367,
     tRecombLaterals = 368,
     tTransfQuadTri = 369,
     tText2D = 370,
     tText3D = 371,
     tInterpolationScheme = 372,
     tTime = 373,
     tCombine = 374,
     tBSpline = 375,
     tBezier = 376,
     tNurbs = 377,
     tNurbsOrder = 378,
     tNurbsKnots = 379,
     tColor = 380,
     tColorTable = 381,
     tFor = 382,
     tIn = 383,
     tEndFor = 384,
     tIf = 385,
     tEndIf = 386,
     tExit = 387,
     tAbort = 388,
     tField = 389,
     tReturn = 390,
     tCall = 391,
     tFunction = 392,
     tShow = 393,
     tHide = 394,
     tGetValue = 395,
     tGetEnv = 396,
     tGetString = 397,
     tHomology = 398,
     tCohomology = 399,
     tBetti = 400,
     tSetOrder = 401,
     tExists = 402,
     tGMSH_MAJOR_VERSION = 403,
     tGMSH_MINOR_VERSION = 404,
     tGMSH_PATCH_VERSION = 405,
     tAFFECTDIVIDE = 406,
     tAFFECTTIMES = 407,
     tAFFECTMINUS = 408,
     tAFFECTPLUS = 409,
     tOR = 410,
     tAND = 411,
     tNOTEQUAL = 412,
     tEQUAL = 413,
     tGREATEROREQUAL = 414,
     tLESSOREQUAL = 415,
     UNARYPREC = 416,
     tMINUSMINUS = 417,
     tPLUSPLUS = 418
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
#define tPoint 317
#define tCircle 318
#define tEllipse 319
#define tLine 320
#define tSphere 321
#define tPolarSphere 322
#define tSurface 323
#define tSpline 324
#define tVolume 325
#define tCharacteristic 326
#define tLength 327
#define tParametric 328
#define tElliptic 329
#define tRefineMesh 330
#define tAdaptMesh 331
#define tRelocateMesh 332
#define tPlane 333
#define tRuled 334
#define tTransfinite 335
#define tComplex 336
#define tPhysical 337
#define tCompound 338
#define tPeriodic 339
#define tUsing 340
#define tPlugin 341
#define tDegenerated 342
#define tRecursive 343
#define tRotate 344
#define tTranslate 345
#define tSymmetry 346
#define tDilate 347
#define tExtrude 348
#define tLevelset 349
#define tRecombine 350
#define tSmoother 351
#define tSplit 352
#define tDelete 353
#define tCoherence 354
#define tIntersect 355
#define tMeshAlgorithm 356
#define tReverse 357
#define tLayers 358
#define tScaleLast 359
#define tHole 360
#define tAlias 361
#define tAliasWithOptions 362
#define tCopyOptions 363
#define tQuadTriAddVerts 364
#define tQuadTriNoNewVerts 365
#define tQuadTriSngl 366
#define tQuadTriDbl 367
#define tRecombLaterals 368
#define tTransfQuadTri 369
#define tText2D 370
#define tText3D 371
#define tInterpolationScheme 372
#define tTime 373
#define tCombine 374
#define tBSpline 375
#define tBezier 376
#define tNurbs 377
#define tNurbsOrder 378
#define tNurbsKnots 379
#define tColor 380
#define tColorTable 381
#define tFor 382
#define tIn 383
#define tEndFor 384
#define tIf 385
#define tEndIf 386
#define tExit 387
#define tAbort 388
#define tField 389
#define tReturn 390
#define tCall 391
#define tFunction 392
#define tShow 393
#define tHide 394
#define tGetValue 395
#define tGetEnv 396
#define tGetString 397
#define tHomology 398
#define tCohomology 399
#define tBetti 400
#define tSetOrder 401
#define tExists 402
#define tGMSH_MAJOR_VERSION 403
#define tGMSH_MINOR_VERSION 404
#define tGMSH_PATCH_VERSION 405
#define tAFFECTDIVIDE 406
#define tAFFECTTIMES 407
#define tAFFECTMINUS 408
#define tAFFECTPLUS 409
#define tOR 410
#define tAND 411
#define tNOTEQUAL 412
#define tEQUAL 413
#define tGREATEROREQUAL 414
#define tLESSOREQUAL 415
#define UNARYPREC 416
#define tMINUSMINUS 417
#define tPLUSPLUS 418




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
#line 385 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

