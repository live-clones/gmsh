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
     tSprintf = 293,
     tStrCat = 294,
     tStrPrefix = 295,
     tStrRelative = 296,
     tStrReplace = 297,
     tStrFind = 298,
     tStrCmp = 299,
     tTextAttributes = 300,
     tBoundingBox = 301,
     tDraw = 302,
     tToday = 303,
     tSyncModel = 304,
     tCreateTopology = 305,
     tCreateTopologyNoHoles = 306,
     tDistanceFunction = 307,
     tDefineConstant = 308,
     tUndefineConstant = 309,
     tPoint = 310,
     tCircle = 311,
     tEllipse = 312,
     tLine = 313,
     tSphere = 314,
     tPolarSphere = 315,
     tSurface = 316,
     tSpline = 317,
     tVolume = 318,
     tCharacteristic = 319,
     tLength = 320,
     tParametric = 321,
     tElliptic = 322,
     tRefineMesh = 323,
     tPlane = 324,
     tRuled = 325,
     tTransfinite = 326,
     tComplex = 327,
     tPhysical = 328,
     tCompound = 329,
     tPeriodic = 330,
     tUsing = 331,
     tPlugin = 332,
     tDegenerated = 333,
     tRotate = 334,
     tTranslate = 335,
     tSymmetry = 336,
     tDilate = 337,
     tExtrude = 338,
     tLevelset = 339,
     tRecombine = 340,
     tSmoother = 341,
     tSplit = 342,
     tDelete = 343,
     tCoherence = 344,
     tIntersect = 345,
     tMeshAlgorithm = 346,
     tReverse = 347,
     tLayers = 348,
     tHole = 349,
     tAlias = 350,
     tAliasWithOptions = 351,
     tQuadTriDbl = 352,
     tQuadTriSngl = 353,
     tRecombLaterals = 354,
     tTransfQuadTri = 355,
     tText2D = 356,
     tText3D = 357,
     tInterpolationScheme = 358,
     tTime = 359,
     tCombine = 360,
     tBSpline = 361,
     tBezier = 362,
     tNurbs = 363,
     tNurbsOrder = 364,
     tNurbsKnots = 365,
     tColor = 366,
     tColorTable = 367,
     tFor = 368,
     tIn = 369,
     tEndFor = 370,
     tIf = 371,
     tEndIf = 372,
     tExit = 373,
     tAbort = 374,
     tField = 375,
     tReturn = 376,
     tCall = 377,
     tFunction = 378,
     tShow = 379,
     tHide = 380,
     tGetValue = 381,
     tGetEnv = 382,
     tGetString = 383,
     tHomology = 384,
     tCohomology = 385,
     tBetti = 386,
     tSetOrder = 387,
     tGMSH_MAJOR_VERSION = 388,
     tGMSH_MINOR_VERSION = 389,
     tGMSH_PATCH_VERSION = 390,
     tAFFECTDIVIDE = 391,
     tAFFECTTIMES = 392,
     tAFFECTMINUS = 393,
     tAFFECTPLUS = 394,
     tOR = 395,
     tAND = 396,
     tNOTEQUAL = 397,
     tEQUAL = 398,
     tGREATEROREQUAL = 399,
     tLESSOREQUAL = 400,
     UNARYPREC = 401,
     tMINUSMINUS = 402,
     tPLUSPLUS = 403
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
#define tSprintf 293
#define tStrCat 294
#define tStrPrefix 295
#define tStrRelative 296
#define tStrReplace 297
#define tStrFind 298
#define tStrCmp 299
#define tTextAttributes 300
#define tBoundingBox 301
#define tDraw 302
#define tToday 303
#define tSyncModel 304
#define tCreateTopology 305
#define tCreateTopologyNoHoles 306
#define tDistanceFunction 307
#define tDefineConstant 308
#define tUndefineConstant 309
#define tPoint 310
#define tCircle 311
#define tEllipse 312
#define tLine 313
#define tSphere 314
#define tPolarSphere 315
#define tSurface 316
#define tSpline 317
#define tVolume 318
#define tCharacteristic 319
#define tLength 320
#define tParametric 321
#define tElliptic 322
#define tRefineMesh 323
#define tPlane 324
#define tRuled 325
#define tTransfinite 326
#define tComplex 327
#define tPhysical 328
#define tCompound 329
#define tPeriodic 330
#define tUsing 331
#define tPlugin 332
#define tDegenerated 333
#define tRotate 334
#define tTranslate 335
#define tSymmetry 336
#define tDilate 337
#define tExtrude 338
#define tLevelset 339
#define tRecombine 340
#define tSmoother 341
#define tSplit 342
#define tDelete 343
#define tCoherence 344
#define tIntersect 345
#define tMeshAlgorithm 346
#define tReverse 347
#define tLayers 348
#define tHole 349
#define tAlias 350
#define tAliasWithOptions 351
#define tQuadTriDbl 352
#define tQuadTriSngl 353
#define tRecombLaterals 354
#define tTransfQuadTri 355
#define tText2D 356
#define tText3D 357
#define tInterpolationScheme 358
#define tTime 359
#define tCombine 360
#define tBSpline 361
#define tBezier 362
#define tNurbs 363
#define tNurbsOrder 364
#define tNurbsKnots 365
#define tColor 366
#define tColorTable 367
#define tFor 368
#define tIn 369
#define tEndFor 370
#define tIf 371
#define tEndIf 372
#define tExit 373
#define tAbort 374
#define tField 375
#define tReturn 376
#define tCall 377
#define tFunction 378
#define tShow 379
#define tHide 380
#define tGetValue 381
#define tGetEnv 382
#define tGetString 383
#define tHomology 384
#define tCohomology 385
#define tBetti 386
#define tSetOrder 387
#define tGMSH_MAJOR_VERSION 388
#define tGMSH_MINOR_VERSION 389
#define tGMSH_PATCH_VERSION 390
#define tAFFECTDIVIDE 391
#define tAFFECTTIMES 392
#define tAFFECTMINUS 393
#define tAFFECTPLUS 394
#define tOR 395
#define tAND 396
#define tNOTEQUAL 397
#define tEQUAL 398
#define tGREATEROREQUAL 399
#define tLESSOREQUAL 400
#define UNARYPREC 401
#define tMINUSMINUS 402
#define tPLUSPLUS 403




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
#line 355 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

