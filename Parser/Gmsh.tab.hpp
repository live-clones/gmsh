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
     tSyncModel = 305,
     tCreateTopology = 306,
     tCreateTopologyNoHoles = 307,
     tDistanceFunction = 308,
     tDefineConstant = 309,
     tUndefineConstant = 310,
     tPoint = 311,
     tCircle = 312,
     tEllipse = 313,
     tLine = 314,
     tSphere = 315,
     tPolarSphere = 316,
     tSurface = 317,
     tSpline = 318,
     tVolume = 319,
     tCharacteristic = 320,
     tLength = 321,
     tParametric = 322,
     tElliptic = 323,
     tRefineMesh = 324,
     tAdaptMesh = 325,
     tPlane = 326,
     tRuled = 327,
     tTransfinite = 328,
     tComplex = 329,
     tPhysical = 330,
     tCompound = 331,
     tPeriodic = 332,
     tUsing = 333,
     tPlugin = 334,
     tDegenerated = 335,
     tRotate = 336,
     tTranslate = 337,
     tSymmetry = 338,
     tDilate = 339,
     tExtrude = 340,
     tLevelset = 341,
     tRecombine = 342,
     tSmoother = 343,
     tSplit = 344,
     tDelete = 345,
     tCoherence = 346,
     tIntersect = 347,
     tMeshAlgorithm = 348,
     tReverse = 349,
     tLayers = 350,
     tHole = 351,
     tAlias = 352,
     tAliasWithOptions = 353,
     tQuadTriDbl = 354,
     tQuadTriSngl = 355,
     tRecombLaterals = 356,
     tTransfQuadTri = 357,
     tText2D = 358,
     tText3D = 359,
     tInterpolationScheme = 360,
     tTime = 361,
     tCombine = 362,
     tBSpline = 363,
     tBezier = 364,
     tNurbs = 365,
     tNurbsOrder = 366,
     tNurbsKnots = 367,
     tColor = 368,
     tColorTable = 369,
     tFor = 370,
     tIn = 371,
     tEndFor = 372,
     tIf = 373,
     tEndIf = 374,
     tExit = 375,
     tAbort = 376,
     tField = 377,
     tReturn = 378,
     tCall = 379,
     tFunction = 380,
     tShow = 381,
     tHide = 382,
     tGetValue = 383,
     tGetEnv = 384,
     tGetString = 385,
     tHomology = 386,
     tCohomology = 387,
     tBetti = 388,
     tSetOrder = 389,
     tGMSH_MAJOR_VERSION = 390,
     tGMSH_MINOR_VERSION = 391,
     tGMSH_PATCH_VERSION = 392,
     tAFFECTDIVIDE = 393,
     tAFFECTTIMES = 394,
     tAFFECTMINUS = 395,
     tAFFECTPLUS = 396,
     tOR = 397,
     tAND = 398,
     tNOTEQUAL = 399,
     tEQUAL = 400,
     tGREATEROREQUAL = 401,
     tLESSOREQUAL = 402,
     UNARYPREC = 403,
     tMINUSMINUS = 404,
     tPLUSPLUS = 405
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
#define tSyncModel 305
#define tCreateTopology 306
#define tCreateTopologyNoHoles 307
#define tDistanceFunction 308
#define tDefineConstant 309
#define tUndefineConstant 310
#define tPoint 311
#define tCircle 312
#define tEllipse 313
#define tLine 314
#define tSphere 315
#define tPolarSphere 316
#define tSurface 317
#define tSpline 318
#define tVolume 319
#define tCharacteristic 320
#define tLength 321
#define tParametric 322
#define tElliptic 323
#define tRefineMesh 324
#define tAdaptMesh 325
#define tPlane 326
#define tRuled 327
#define tTransfinite 328
#define tComplex 329
#define tPhysical 330
#define tCompound 331
#define tPeriodic 332
#define tUsing 333
#define tPlugin 334
#define tDegenerated 335
#define tRotate 336
#define tTranslate 337
#define tSymmetry 338
#define tDilate 339
#define tExtrude 340
#define tLevelset 341
#define tRecombine 342
#define tSmoother 343
#define tSplit 344
#define tDelete 345
#define tCoherence 346
#define tIntersect 347
#define tMeshAlgorithm 348
#define tReverse 349
#define tLayers 350
#define tHole 351
#define tAlias 352
#define tAliasWithOptions 353
#define tQuadTriDbl 354
#define tQuadTriSngl 355
#define tRecombLaterals 356
#define tTransfQuadTri 357
#define tText2D 358
#define tText3D 359
#define tInterpolationScheme 360
#define tTime 361
#define tCombine 362
#define tBSpline 363
#define tBezier 364
#define tNurbs 365
#define tNurbsOrder 366
#define tNurbsKnots 367
#define tColor 368
#define tColorTable 369
#define tFor 370
#define tIn 371
#define tEndFor 372
#define tIf 373
#define tEndIf 374
#define tExit 375
#define tAbort 376
#define tField 377
#define tReturn 378
#define tCall 379
#define tFunction 380
#define tShow 381
#define tHide 382
#define tGetValue 383
#define tGetEnv 384
#define tGetString 385
#define tHomology 386
#define tCohomology 387
#define tBetti 388
#define tSetOrder 389
#define tGMSH_MAJOR_VERSION 390
#define tGMSH_MINOR_VERSION 391
#define tGMSH_PATCH_VERSION 392
#define tAFFECTDIVIDE 393
#define tAFFECTTIMES 394
#define tAFFECTMINUS 395
#define tAFFECTPLUS 396
#define tOR 397
#define tAND 398
#define tNOTEQUAL 399
#define tEQUAL 400
#define tGREATEROREQUAL 401
#define tLESSOREQUAL 402
#define UNARYPREC 403
#define tMINUSMINUS 404
#define tPLUSPLUS 405




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
#line 359 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

