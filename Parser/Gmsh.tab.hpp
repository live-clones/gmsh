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
     tRotate = 338,
     tTranslate = 339,
     tSymmetry = 340,
     tDilate = 341,
     tExtrude = 342,
     tLevelset = 343,
     tRecombine = 344,
     tSmoother = 345,
     tSplit = 346,
     tDelete = 347,
     tCoherence = 348,
     tIntersect = 349,
     tMeshAlgorithm = 350,
     tReverse = 351,
     tLayers = 352,
     tHole = 353,
     tAlias = 354,
     tAliasWithOptions = 355,
     tQuadTriDbl = 356,
     tQuadTriSngl = 357,
     tRecombLaterals = 358,
     tTransfQuadTri = 359,
     tText2D = 360,
     tText3D = 361,
     tInterpolationScheme = 362,
     tTime = 363,
     tCombine = 364,
     tBSpline = 365,
     tBezier = 366,
     tNurbs = 367,
     tNurbsOrder = 368,
     tNurbsKnots = 369,
     tColor = 370,
     tColorTable = 371,
     tFor = 372,
     tIn = 373,
     tEndFor = 374,
     tIf = 375,
     tEndIf = 376,
     tExit = 377,
     tAbort = 378,
     tField = 379,
     tReturn = 380,
     tCall = 381,
     tFunction = 382,
     tShow = 383,
     tHide = 384,
     tGetValue = 385,
     tGetEnv = 386,
     tGetString = 387,
     tHomology = 388,
     tCohomology = 389,
     tBetti = 390,
     tSetOrder = 391,
     tGMSH_MAJOR_VERSION = 392,
     tGMSH_MINOR_VERSION = 393,
     tGMSH_PATCH_VERSION = 394,
     tAFFECTDIVIDE = 395,
     tAFFECTTIMES = 396,
     tAFFECTMINUS = 397,
     tAFFECTPLUS = 398,
     tOR = 399,
     tAND = 400,
     tNOTEQUAL = 401,
     tEQUAL = 402,
     tGREATEROREQUAL = 403,
     tLESSOREQUAL = 404,
     UNARYPREC = 405,
     tMINUSMINUS = 406,
     tPLUSPLUS = 407
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
#define tRotate 338
#define tTranslate 339
#define tSymmetry 340
#define tDilate 341
#define tExtrude 342
#define tLevelset 343
#define tRecombine 344
#define tSmoother 345
#define tSplit 346
#define tDelete 347
#define tCoherence 348
#define tIntersect 349
#define tMeshAlgorithm 350
#define tReverse 351
#define tLayers 352
#define tHole 353
#define tAlias 354
#define tAliasWithOptions 355
#define tQuadTriDbl 356
#define tQuadTriSngl 357
#define tRecombLaterals 358
#define tTransfQuadTri 359
#define tText2D 360
#define tText3D 361
#define tInterpolationScheme 362
#define tTime 363
#define tCombine 364
#define tBSpline 365
#define tBezier 366
#define tNurbs 367
#define tNurbsOrder 368
#define tNurbsKnots 369
#define tColor 370
#define tColorTable 371
#define tFor 372
#define tIn 373
#define tEndFor 374
#define tIf 375
#define tEndIf 376
#define tExit 377
#define tAbort 378
#define tField 379
#define tReturn 380
#define tCall 381
#define tFunction 382
#define tShow 383
#define tHide 384
#define tGetValue 385
#define tGetEnv 386
#define tGetString 387
#define tHomology 388
#define tCohomology 389
#define tBetti 390
#define tSetOrder 391
#define tGMSH_MAJOR_VERSION 392
#define tGMSH_MINOR_VERSION 393
#define tGMSH_PATCH_VERSION 394
#define tAFFECTDIVIDE 395
#define tAFFECTTIMES 396
#define tAFFECTMINUS 397
#define tAFFECTPLUS 398
#define tOR 399
#define tAND 400
#define tNOTEQUAL 401
#define tEQUAL 402
#define tGREATEROREQUAL 403
#define tLESSOREQUAL 404
#define UNARYPREC 405
#define tMINUSMINUS 406
#define tPLUSPLUS 407




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
#line 363 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

