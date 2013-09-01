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
     tHole = 354,
     tAlias = 355,
     tAliasWithOptions = 356,
     tQuadTriDbl = 357,
     tQuadTriSngl = 358,
     tRecombLaterals = 359,
     tTransfQuadTri = 360,
     tText2D = 361,
     tText3D = 362,
     tInterpolationScheme = 363,
     tTime = 364,
     tCombine = 365,
     tBSpline = 366,
     tBezier = 367,
     tNurbs = 368,
     tNurbsOrder = 369,
     tNurbsKnots = 370,
     tColor = 371,
     tColorTable = 372,
     tFor = 373,
     tIn = 374,
     tEndFor = 375,
     tIf = 376,
     tEndIf = 377,
     tExit = 378,
     tAbort = 379,
     tField = 380,
     tReturn = 381,
     tCall = 382,
     tFunction = 383,
     tShow = 384,
     tHide = 385,
     tGetValue = 386,
     tGetEnv = 387,
     tGetString = 388,
     tHomology = 389,
     tCohomology = 390,
     tBetti = 391,
     tSetOrder = 392,
     tGMSH_MAJOR_VERSION = 393,
     tGMSH_MINOR_VERSION = 394,
     tGMSH_PATCH_VERSION = 395,
     tAFFECTDIVIDE = 396,
     tAFFECTTIMES = 397,
     tAFFECTMINUS = 398,
     tAFFECTPLUS = 399,
     tOR = 400,
     tAND = 401,
     tNOTEQUAL = 402,
     tEQUAL = 403,
     tGREATEROREQUAL = 404,
     tLESSOREQUAL = 405,
     UNARYPREC = 406,
     tMINUSMINUS = 407,
     tPLUSPLUS = 408
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
#define tHole 354
#define tAlias 355
#define tAliasWithOptions 356
#define tQuadTriDbl 357
#define tQuadTriSngl 358
#define tRecombLaterals 359
#define tTransfQuadTri 360
#define tText2D 361
#define tText3D 362
#define tInterpolationScheme 363
#define tTime 364
#define tCombine 365
#define tBSpline 366
#define tBezier 367
#define tNurbs 368
#define tNurbsOrder 369
#define tNurbsKnots 370
#define tColor 371
#define tColorTable 372
#define tFor 373
#define tIn 374
#define tEndFor 375
#define tIf 376
#define tEndIf 377
#define tExit 378
#define tAbort 379
#define tField 380
#define tReturn 381
#define tCall 382
#define tFunction 383
#define tShow 384
#define tHide 385
#define tGetValue 386
#define tGetEnv 387
#define tGetString 388
#define tHomology 389
#define tCohomology 390
#define tBetti 391
#define tSetOrder 392
#define tGMSH_MAJOR_VERSION 393
#define tGMSH_MINOR_VERSION 394
#define tGMSH_PATCH_VERSION 395
#define tAFFECTDIVIDE 396
#define tAFFECTTIMES 397
#define tAFFECTMINUS 398
#define tAFFECTPLUS 399
#define tOR 400
#define tAND 401
#define tNOTEQUAL 402
#define tEQUAL 403
#define tGREATEROREQUAL 404
#define tLESSOREQUAL 405
#define UNARYPREC 406
#define tMINUSMINUS 407
#define tPLUSPLUS 408




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
#line 365 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

