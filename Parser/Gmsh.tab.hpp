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
     tSyncModel = 306,
     tCreateTopology = 307,
     tCreateTopologyNoHoles = 308,
     tDistanceFunction = 309,
     tDefineConstant = 310,
     tUndefineConstant = 311,
     tPoint = 312,
     tCircle = 313,
     tEllipse = 314,
     tLine = 315,
     tSphere = 316,
     tPolarSphere = 317,
     tSurface = 318,
     tSpline = 319,
     tVolume = 320,
     tCharacteristic = 321,
     tLength = 322,
     tParametric = 323,
     tElliptic = 324,
     tRefineMesh = 325,
     tAdaptMesh = 326,
     tPlane = 327,
     tRuled = 328,
     tTransfinite = 329,
     tComplex = 330,
     tPhysical = 331,
     tCompound = 332,
     tPeriodic = 333,
     tUsing = 334,
     tPlugin = 335,
     tDegenerated = 336,
     tRotate = 337,
     tTranslate = 338,
     tSymmetry = 339,
     tDilate = 340,
     tExtrude = 341,
     tLevelset = 342,
     tRecombine = 343,
     tSmoother = 344,
     tSplit = 345,
     tDelete = 346,
     tCoherence = 347,
     tIntersect = 348,
     tMeshAlgorithm = 349,
     tReverse = 350,
     tLayers = 351,
     tHole = 352,
     tAlias = 353,
     tAliasWithOptions = 354,
     tQuadTriDbl = 355,
     tQuadTriSngl = 356,
     tRecombLaterals = 357,
     tTransfQuadTri = 358,
     tText2D = 359,
     tText3D = 360,
     tInterpolationScheme = 361,
     tTime = 362,
     tCombine = 363,
     tBSpline = 364,
     tBezier = 365,
     tNurbs = 366,
     tNurbsOrder = 367,
     tNurbsKnots = 368,
     tColor = 369,
     tColorTable = 370,
     tFor = 371,
     tIn = 372,
     tEndFor = 373,
     tIf = 374,
     tEndIf = 375,
     tExit = 376,
     tAbort = 377,
     tField = 378,
     tReturn = 379,
     tCall = 380,
     tFunction = 381,
     tShow = 382,
     tHide = 383,
     tGetValue = 384,
     tGetEnv = 385,
     tGetString = 386,
     tHomology = 387,
     tCohomology = 388,
     tBetti = 389,
     tSetOrder = 390,
     tGMSH_MAJOR_VERSION = 391,
     tGMSH_MINOR_VERSION = 392,
     tGMSH_PATCH_VERSION = 393,
     tAFFECTDIVIDE = 394,
     tAFFECTTIMES = 395,
     tAFFECTMINUS = 396,
     tAFFECTPLUS = 397,
     tOR = 398,
     tAND = 399,
     tNOTEQUAL = 400,
     tEQUAL = 401,
     tGREATEROREQUAL = 402,
     tLESSOREQUAL = 403,
     UNARYPREC = 404,
     tMINUSMINUS = 405,
     tPLUSPLUS = 406
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
#define tSyncModel 306
#define tCreateTopology 307
#define tCreateTopologyNoHoles 308
#define tDistanceFunction 309
#define tDefineConstant 310
#define tUndefineConstant 311
#define tPoint 312
#define tCircle 313
#define tEllipse 314
#define tLine 315
#define tSphere 316
#define tPolarSphere 317
#define tSurface 318
#define tSpline 319
#define tVolume 320
#define tCharacteristic 321
#define tLength 322
#define tParametric 323
#define tElliptic 324
#define tRefineMesh 325
#define tAdaptMesh 326
#define tPlane 327
#define tRuled 328
#define tTransfinite 329
#define tComplex 330
#define tPhysical 331
#define tCompound 332
#define tPeriodic 333
#define tUsing 334
#define tPlugin 335
#define tDegenerated 336
#define tRotate 337
#define tTranslate 338
#define tSymmetry 339
#define tDilate 340
#define tExtrude 341
#define tLevelset 342
#define tRecombine 343
#define tSmoother 344
#define tSplit 345
#define tDelete 346
#define tCoherence 347
#define tIntersect 348
#define tMeshAlgorithm 349
#define tReverse 350
#define tLayers 351
#define tHole 352
#define tAlias 353
#define tAliasWithOptions 354
#define tQuadTriDbl 355
#define tQuadTriSngl 356
#define tRecombLaterals 357
#define tTransfQuadTri 358
#define tText2D 359
#define tText3D 360
#define tInterpolationScheme 361
#define tTime 362
#define tCombine 363
#define tBSpline 364
#define tBezier 365
#define tNurbs 366
#define tNurbsOrder 367
#define tNurbsKnots 368
#define tColor 369
#define tColorTable 370
#define tFor 371
#define tIn 372
#define tEndFor 373
#define tIf 374
#define tEndIf 375
#define tExit 376
#define tAbort 377
#define tField 378
#define tReturn 379
#define tCall 380
#define tFunction 381
#define tShow 382
#define tHide 383
#define tGetValue 384
#define tGetEnv 385
#define tGetString 386
#define tHomology 387
#define tCohomology 388
#define tBetti 389
#define tSetOrder 390
#define tGMSH_MAJOR_VERSION 391
#define tGMSH_MINOR_VERSION 392
#define tGMSH_PATCH_VERSION 393
#define tAFFECTDIVIDE 394
#define tAFFECTTIMES 395
#define tAFFECTMINUS 396
#define tAFFECTPLUS 397
#define tOR 398
#define tAND 399
#define tNOTEQUAL 400
#define tEQUAL 401
#define tGREATEROREQUAL 402
#define tLESSOREQUAL 403
#define UNARYPREC 404
#define tMINUSMINUS 405
#define tPLUSPLUS 406




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
#line 361 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

