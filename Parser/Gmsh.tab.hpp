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
     tSetChanged = 304,
     tToday = 305,
     tCpu = 306,
     tMemory = 307,
     tSyncModel = 308,
     tCreateTopology = 309,
     tCreateTopologyNoHoles = 310,
     tDistanceFunction = 311,
     tDefineConstant = 312,
     tUndefineConstant = 313,
     tPoint = 314,
     tCircle = 315,
     tEllipse = 316,
     tLine = 317,
     tSphere = 318,
     tPolarSphere = 319,
     tSurface = 320,
     tSpline = 321,
     tVolume = 322,
     tCharacteristic = 323,
     tLength = 324,
     tParametric = 325,
     tElliptic = 326,
     tRefineMesh = 327,
     tAdaptMesh = 328,
     tPlane = 329,
     tRuled = 330,
     tTransfinite = 331,
     tComplex = 332,
     tPhysical = 333,
     tCompound = 334,
     tPeriodic = 335,
     tUsing = 336,
     tPlugin = 337,
     tDegenerated = 338,
     tRecursive = 339,
     tRotate = 340,
     tTranslate = 341,
     tSymmetry = 342,
     tDilate = 343,
     tExtrude = 344,
     tLevelset = 345,
     tRecombine = 346,
     tSmoother = 347,
     tSplit = 348,
     tDelete = 349,
     tCoherence = 350,
     tIntersect = 351,
     tMeshAlgorithm = 352,
     tReverse = 353,
     tLayers = 354,
     tScaleLast = 355,
     tHole = 356,
     tAlias = 357,
     tAliasWithOptions = 358,
     tQuadTriAddVerts = 359,
     tQuadTriNoNewVerts = 360,
     tQuadTriSngl = 361,
     tQuadTriDbl = 362,
     tRecombLaterals = 363,
     tTransfQuadTri = 364,
     tText2D = 365,
     tText3D = 366,
     tInterpolationScheme = 367,
     tTime = 368,
     tCombine = 369,
     tBSpline = 370,
     tBezier = 371,
     tNurbs = 372,
     tNurbsOrder = 373,
     tNurbsKnots = 374,
     tColor = 375,
     tColorTable = 376,
     tFor = 377,
     tIn = 378,
     tEndFor = 379,
     tIf = 380,
     tEndIf = 381,
     tExit = 382,
     tAbort = 383,
     tField = 384,
     tReturn = 385,
     tCall = 386,
     tFunction = 387,
     tShow = 388,
     tHide = 389,
     tGetValue = 390,
     tGetEnv = 391,
     tGetString = 392,
     tHomology = 393,
     tCohomology = 394,
     tBetti = 395,
     tSetOrder = 396,
     tGMSH_MAJOR_VERSION = 397,
     tGMSH_MINOR_VERSION = 398,
     tGMSH_PATCH_VERSION = 399,
     tAFFECTDIVIDE = 400,
     tAFFECTTIMES = 401,
     tAFFECTMINUS = 402,
     tAFFECTPLUS = 403,
     tOR = 404,
     tAND = 405,
     tNOTEQUAL = 406,
     tEQUAL = 407,
     tGREATEROREQUAL = 408,
     tLESSOREQUAL = 409,
     UNARYPREC = 410,
     tMINUSMINUS = 411,
     tPLUSPLUS = 412
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
#define tSetChanged 304
#define tToday 305
#define tCpu 306
#define tMemory 307
#define tSyncModel 308
#define tCreateTopology 309
#define tCreateTopologyNoHoles 310
#define tDistanceFunction 311
#define tDefineConstant 312
#define tUndefineConstant 313
#define tPoint 314
#define tCircle 315
#define tEllipse 316
#define tLine 317
#define tSphere 318
#define tPolarSphere 319
#define tSurface 320
#define tSpline 321
#define tVolume 322
#define tCharacteristic 323
#define tLength 324
#define tParametric 325
#define tElliptic 326
#define tRefineMesh 327
#define tAdaptMesh 328
#define tPlane 329
#define tRuled 330
#define tTransfinite 331
#define tComplex 332
#define tPhysical 333
#define tCompound 334
#define tPeriodic 335
#define tUsing 336
#define tPlugin 337
#define tDegenerated 338
#define tRecursive 339
#define tRotate 340
#define tTranslate 341
#define tSymmetry 342
#define tDilate 343
#define tExtrude 344
#define tLevelset 345
#define tRecombine 346
#define tSmoother 347
#define tSplit 348
#define tDelete 349
#define tCoherence 350
#define tIntersect 351
#define tMeshAlgorithm 352
#define tReverse 353
#define tLayers 354
#define tScaleLast 355
#define tHole 356
#define tAlias 357
#define tAliasWithOptions 358
#define tQuadTriAddVerts 359
#define tQuadTriNoNewVerts 360
#define tQuadTriSngl 361
#define tQuadTriDbl 362
#define tRecombLaterals 363
#define tTransfQuadTri 364
#define tText2D 365
#define tText3D 366
#define tInterpolationScheme 367
#define tTime 368
#define tCombine 369
#define tBSpline 370
#define tBezier 371
#define tNurbs 372
#define tNurbsOrder 373
#define tNurbsKnots 374
#define tColor 375
#define tColorTable 376
#define tFor 377
#define tIn 378
#define tEndFor 379
#define tIf 380
#define tEndIf 381
#define tExit 382
#define tAbort 383
#define tField 384
#define tReturn 385
#define tCall 386
#define tFunction 387
#define tShow 388
#define tHide 389
#define tGetValue 390
#define tGetEnv 391
#define tGetString 392
#define tHomology 393
#define tCohomology 394
#define tBetti 395
#define tSetOrder 396
#define tGMSH_MAJOR_VERSION 397
#define tGMSH_MINOR_VERSION 398
#define tGMSH_PATCH_VERSION 399
#define tAFFECTDIVIDE 400
#define tAFFECTTIMES 401
#define tAFFECTMINUS 402
#define tAFFECTPLUS 403
#define tOR 404
#define tAND 405
#define tNOTEQUAL 406
#define tEQUAL 407
#define tGREATEROREQUAL 408
#define tLESSOREQUAL 409
#define UNARYPREC 410
#define tMINUSMINUS 411
#define tPLUSPLUS 412




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
#line 373 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

