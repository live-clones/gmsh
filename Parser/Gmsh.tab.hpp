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
     tAdaptMesh = 324,
     tPlane = 325,
     tRuled = 326,
     tTransfinite = 327,
     tComplex = 328,
     tPhysical = 329,
     tCompound = 330,
     tPeriodic = 331,
     tUsing = 332,
     tPlugin = 333,
     tDegenerated = 334,
     tRotate = 335,
     tTranslate = 336,
     tSymmetry = 337,
     tDilate = 338,
     tExtrude = 339,
     tLevelset = 340,
     tRecombine = 341,
     tSmoother = 342,
     tSplit = 343,
     tDelete = 344,
     tCoherence = 345,
     tIntersect = 346,
     tMeshAlgorithm = 347,
     tReverse = 348,
     tLayers = 349,
     tHole = 350,
     tAlias = 351,
     tAliasWithOptions = 352,
     tQuadTriDbl = 353,
     tQuadTriSngl = 354,
     tRecombLaterals = 355,
     tTransfQuadTri = 356,
     tText2D = 357,
     tText3D = 358,
     tInterpolationScheme = 359,
     tTime = 360,
     tCombine = 361,
     tBSpline = 362,
     tBezier = 363,
     tNurbs = 364,
     tNurbsOrder = 365,
     tNurbsKnots = 366,
     tColor = 367,
     tColorTable = 368,
     tFor = 369,
     tIn = 370,
     tEndFor = 371,
     tIf = 372,
     tEndIf = 373,
     tExit = 374,
     tAbort = 375,
     tField = 376,
     tReturn = 377,
     tCall = 378,
     tFunction = 379,
     tShow = 380,
     tHide = 381,
     tGetValue = 382,
     tGetEnv = 383,
     tGetString = 384,
     tHomology = 385,
     tCohomology = 386,
     tBetti = 387,
     tSetOrder = 388,
     tGMSH_MAJOR_VERSION = 389,
     tGMSH_MINOR_VERSION = 390,
     tGMSH_PATCH_VERSION = 391,
     tAFFECTDIVIDE = 392,
     tAFFECTTIMES = 393,
     tAFFECTMINUS = 394,
     tAFFECTPLUS = 395,
     tOR = 396,
     tAND = 397,
     tNOTEQUAL = 398,
     tEQUAL = 399,
     tGREATEROREQUAL = 400,
     tLESSOREQUAL = 401,
     UNARYPREC = 402,
     tMINUSMINUS = 403,
     tPLUSPLUS = 404
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
#define tAdaptMesh 324
#define tPlane 325
#define tRuled 326
#define tTransfinite 327
#define tComplex 328
#define tPhysical 329
#define tCompound 330
#define tPeriodic 331
#define tUsing 332
#define tPlugin 333
#define tDegenerated 334
#define tRotate 335
#define tTranslate 336
#define tSymmetry 337
#define tDilate 338
#define tExtrude 339
#define tLevelset 340
#define tRecombine 341
#define tSmoother 342
#define tSplit 343
#define tDelete 344
#define tCoherence 345
#define tIntersect 346
#define tMeshAlgorithm 347
#define tReverse 348
#define tLayers 349
#define tHole 350
#define tAlias 351
#define tAliasWithOptions 352
#define tQuadTriDbl 353
#define tQuadTriSngl 354
#define tRecombLaterals 355
#define tTransfQuadTri 356
#define tText2D 357
#define tText3D 358
#define tInterpolationScheme 359
#define tTime 360
#define tCombine 361
#define tBSpline 362
#define tBezier 363
#define tNurbs 364
#define tNurbsOrder 365
#define tNurbsKnots 366
#define tColor 367
#define tColorTable 368
#define tFor 369
#define tIn 370
#define tEndFor 371
#define tIf 372
#define tEndIf 373
#define tExit 374
#define tAbort 375
#define tField 376
#define tReturn 377
#define tCall 378
#define tFunction 379
#define tShow 380
#define tHide 381
#define tGetValue 382
#define tGetEnv 383
#define tGetString 384
#define tHomology 385
#define tCohomology 386
#define tBetti 387
#define tSetOrder 388
#define tGMSH_MAJOR_VERSION 389
#define tGMSH_MINOR_VERSION 390
#define tGMSH_PATCH_VERSION 391
#define tAFFECTDIVIDE 392
#define tAFFECTTIMES 393
#define tAFFECTMINUS 394
#define tAFFECTPLUS 395
#define tOR 396
#define tAND 397
#define tNOTEQUAL 398
#define tEQUAL 399
#define tGREATEROREQUAL 400
#define tLESSOREQUAL 401
#define UNARYPREC 402
#define tMINUSMINUS 403
#define tPLUSPLUS 404




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
#line 357 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

