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
     tFmod = 287,
     tModulo = 288,
     tHypot = 289,
     tList = 290,
     tPrintf = 291,
     tError = 292,
     tStr = 293,
     tSprintf = 294,
     tStrCat = 295,
     tStrPrefix = 296,
     tStrRelative = 297,
     tStrReplace = 298,
     tStrFind = 299,
     tStrCmp = 300,
     tTextAttributes = 301,
     tBoundingBox = 302,
     tDraw = 303,
     tToday = 304,
     tCpu = 305,
     tMemory = 306,
     tSyncModel = 307,
     tCreateTopology = 308,
     tCreateTopologyNoHoles = 309,
     tDistanceFunction = 310,
     tDefineConstant = 311,
     tUndefineConstant = 312,
     tPoint = 313,
     tCircle = 314,
     tEllipse = 315,
     tLine = 316,
     tSphere = 317,
     tPolarSphere = 318,
     tSurface = 319,
     tSpline = 320,
     tVolume = 321,
     tCharacteristic = 322,
     tLength = 323,
     tParametric = 324,
     tElliptic = 325,
     tRefineMesh = 326,
     tAdaptMesh = 327,
     tPlane = 328,
     tRuled = 329,
     tTransfinite = 330,
     tComplex = 331,
     tPhysical = 332,
     tCompound = 333,
     tPeriodic = 334,
     tUsing = 335,
     tPlugin = 336,
     tDegenerated = 337,
     tRecursive = 338,
     tRotate = 339,
     tTranslate = 340,
     tSymmetry = 341,
     tDilate = 342,
     tExtrude = 343,
     tLevelset = 344,
     tRecombine = 345,
     tSmoother = 346,
     tSplit = 347,
     tDelete = 348,
     tCoherence = 349,
     tIntersect = 350,
     tMeshAlgorithm = 351,
     tReverse = 352,
     tLayers = 353,
     tScaleLast = 354,
     tHole = 355,
     tAlias = 356,
     tAliasWithOptions = 357,
     tQuadTriAddVerts = 358,
     tQuadTriNoNewVerts = 359,
     tQuadTriSngl = 360,
     tQuadTriDbl = 361,
     tRecombLaterals = 362,
     tTransfQuadTri = 363,
     tText2D = 364,
     tText3D = 365,
     tInterpolationScheme = 366,
     tTime = 367,
     tCombine = 368,
     tBSpline = 369,
     tBezier = 370,
     tNurbs = 371,
     tNurbsOrder = 372,
     tNurbsKnots = 373,
     tColor = 374,
     tColorTable = 375,
     tFor = 376,
     tIn = 377,
     tEndFor = 378,
     tIf = 379,
     tEndIf = 380,
     tExit = 381,
     tAbort = 382,
     tField = 383,
     tReturn = 384,
     tCall = 385,
     tFunction = 386,
     tShow = 387,
     tHide = 388,
     tGetValue = 389,
     tGetEnv = 390,
     tGetString = 391,
     tHomology = 392,
     tCohomology = 393,
     tBetti = 394,
     tSetOrder = 395,
     tGMSH_MAJOR_VERSION = 396,
     tGMSH_MINOR_VERSION = 397,
     tGMSH_PATCH_VERSION = 398,
     tAFFECTDIVIDE = 399,
     tAFFECTTIMES = 400,
     tAFFECTMINUS = 401,
     tAFFECTPLUS = 402,
     tOR = 403,
     tAND = 404,
     tNOTEQUAL = 405,
     tEQUAL = 406,
     tGREATEROREQUAL = 407,
     tLESSOREQUAL = 408,
     UNARYPREC = 409,
     tMINUSMINUS = 410,
     tPLUSPLUS = 411
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
#define tFmod 287
#define tModulo 288
#define tHypot 289
#define tList 290
#define tPrintf 291
#define tError 292
#define tStr 293
#define tSprintf 294
#define tStrCat 295
#define tStrPrefix 296
#define tStrRelative 297
#define tStrReplace 298
#define tStrFind 299
#define tStrCmp 300
#define tTextAttributes 301
#define tBoundingBox 302
#define tDraw 303
#define tToday 304
#define tCpu 305
#define tMemory 306
#define tSyncModel 307
#define tCreateTopology 308
#define tCreateTopologyNoHoles 309
#define tDistanceFunction 310
#define tDefineConstant 311
#define tUndefineConstant 312
#define tPoint 313
#define tCircle 314
#define tEllipse 315
#define tLine 316
#define tSphere 317
#define tPolarSphere 318
#define tSurface 319
#define tSpline 320
#define tVolume 321
#define tCharacteristic 322
#define tLength 323
#define tParametric 324
#define tElliptic 325
#define tRefineMesh 326
#define tAdaptMesh 327
#define tPlane 328
#define tRuled 329
#define tTransfinite 330
#define tComplex 331
#define tPhysical 332
#define tCompound 333
#define tPeriodic 334
#define tUsing 335
#define tPlugin 336
#define tDegenerated 337
#define tRecursive 338
#define tRotate 339
#define tTranslate 340
#define tSymmetry 341
#define tDilate 342
#define tExtrude 343
#define tLevelset 344
#define tRecombine 345
#define tSmoother 346
#define tSplit 347
#define tDelete 348
#define tCoherence 349
#define tIntersect 350
#define tMeshAlgorithm 351
#define tReverse 352
#define tLayers 353
#define tScaleLast 354
#define tHole 355
#define tAlias 356
#define tAliasWithOptions 357
#define tQuadTriAddVerts 358
#define tQuadTriNoNewVerts 359
#define tQuadTriSngl 360
#define tQuadTriDbl 361
#define tRecombLaterals 362
#define tTransfQuadTri 363
#define tText2D 364
#define tText3D 365
#define tInterpolationScheme 366
#define tTime 367
#define tCombine 368
#define tBSpline 369
#define tBezier 370
#define tNurbs 371
#define tNurbsOrder 372
#define tNurbsKnots 373
#define tColor 374
#define tColorTable 375
#define tFor 376
#define tIn 377
#define tEndFor 378
#define tIf 379
#define tEndIf 380
#define tExit 381
#define tAbort 382
#define tField 383
#define tReturn 384
#define tCall 385
#define tFunction 386
#define tShow 387
#define tHide 388
#define tGetValue 389
#define tGetEnv 390
#define tGetString 391
#define tHomology 392
#define tCohomology 393
#define tBetti 394
#define tSetOrder 395
#define tGMSH_MAJOR_VERSION 396
#define tGMSH_MINOR_VERSION 397
#define tGMSH_PATCH_VERSION 398
#define tAFFECTDIVIDE 399
#define tAFFECTTIMES 400
#define tAFFECTMINUS 401
#define tAFFECTPLUS 402
#define tOR 403
#define tAND 404
#define tNOTEQUAL 405
#define tEQUAL 406
#define tGREATEROREQUAL 407
#define tLESSOREQUAL 408
#define UNARYPREC 409
#define tMINUSMINUS 410
#define tPLUSPLUS 411




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
#line 371 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

