/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED
# define YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gmsh_yydebug;
#endif

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
     tSCOPE = 264,
     tPi = 265,
     tMPI_Rank = 266,
     tMPI_Size = 267,
     tEuclidian = 268,
     tCoordinates = 269,
     tTestLevel = 270,
     tExp = 271,
     tLog = 272,
     tLog10 = 273,
     tSqrt = 274,
     tSin = 275,
     tAsin = 276,
     tCos = 277,
     tAcos = 278,
     tTan = 279,
     tRand = 280,
     tAtan = 281,
     tAtan2 = 282,
     tSinh = 283,
     tCosh = 284,
     tTanh = 285,
     tFabs = 286,
     tAbs = 287,
     tFloor = 288,
     tCeil = 289,
     tRound = 290,
     tFmod = 291,
     tModulo = 292,
     tHypot = 293,
     tList = 294,
     tLinSpace = 295,
     tLogSpace = 296,
     tListFromFile = 297,
     tCatenary = 298,
     tPrintf = 299,
     tError = 300,
     tStr = 301,
     tSprintf = 302,
     tStrCat = 303,
     tStrPrefix = 304,
     tStrRelative = 305,
     tStrReplace = 306,
     tAbsolutePath = 307,
     tDirName = 308,
     tStrSub = 309,
     tStrLen = 310,
     tFind = 311,
     tStrFind = 312,
     tStrCmp = 313,
     tStrChoice = 314,
     tUpperCase = 315,
     tLowerCase = 316,
     tLowerCaseIn = 317,
     tTextAttributes = 318,
     tBoundingBox = 319,
     tDraw = 320,
     tSetChanged = 321,
     tToday = 322,
     tFixRelativePath = 323,
     tCurrentDirectory = 324,
     tSyncModel = 325,
     tNewModel = 326,
     tOnelabAction = 327,
     tOnelabRun = 328,
     tCodeName = 329,
     tCpu = 330,
     tMemory = 331,
     tTotalMemory = 332,
     tCreateTopology = 333,
     tDistanceFunction = 334,
     tDefineConstant = 335,
     tUndefineConstant = 336,
     tDefineNumber = 337,
     tDefineStruct = 338,
     tNameStruct = 339,
     tDimNameSpace = 340,
     tAppend = 341,
     tDefineString = 342,
     tSetNumber = 343,
     tSetTag = 344,
     tSetString = 345,
     tPoint = 346,
     tCircle = 347,
     tEllipse = 348,
     tCurve = 349,
     tSphere = 350,
     tPolarSphere = 351,
     tSurface = 352,
     tSpline = 353,
     tVolume = 354,
     tBox = 355,
     tCylinder = 356,
     tCone = 357,
     tTorus = 358,
     tEllipsoid = 359,
     tQuadric = 360,
     tShapeFromFile = 361,
     tRectangle = 362,
     tDisk = 363,
     tWire = 364,
     tGeoEntity = 365,
     tCharacteristic = 366,
     tLength = 367,
     tParametric = 368,
     tElliptic = 369,
     tRefineMesh = 370,
     tAdaptMesh = 371,
     tRelocateMesh = 372,
     tReorientMesh = 373,
     tSetFactory = 374,
     tThruSections = 375,
     tWedge = 376,
     tFillet = 377,
     tPlane = 378,
     tRuled = 379,
     tTransfinite = 380,
     tPhysical = 381,
     tCompound = 382,
     tPeriodic = 383,
     tUsing = 384,
     tPlugin = 385,
     tDegenerated = 386,
     tRecursive = 387,
     tRotate = 388,
     tTranslate = 389,
     tSymmetry = 390,
     tDilate = 391,
     tExtrude = 392,
     tLevelset = 393,
     tAffine = 394,
     tBooleanUnion = 395,
     tBooleanIntersection = 396,
     tBooleanDifference = 397,
     tBooleanSection = 398,
     tBooleanFragments = 399,
     tThickSolid = 400,
     tRecombine = 401,
     tSmoother = 402,
     tSplit = 403,
     tDelete = 404,
     tCoherence = 405,
     tIntersect = 406,
     tMeshAlgorithm = 407,
     tReverseMesh = 408,
     tLayers = 409,
     tScaleLast = 410,
     tHole = 411,
     tAlias = 412,
     tAliasWithOptions = 413,
     tCopyOptions = 414,
     tQuadTriAddVerts = 415,
     tQuadTriNoNewVerts = 416,
     tRecombLaterals = 417,
     tTransfQuadTri = 418,
     tText2D = 419,
     tText3D = 420,
     tInterpolationScheme = 421,
     tTime = 422,
     tCombine = 423,
     tBSpline = 424,
     tBezier = 425,
     tNurbs = 426,
     tNurbsOrder = 427,
     tNurbsKnots = 428,
     tColor = 429,
     tColorTable = 430,
     tFor = 431,
     tIn = 432,
     tEndFor = 433,
     tIf = 434,
     tElseIf = 435,
     tElse = 436,
     tEndIf = 437,
     tExit = 438,
     tAbort = 439,
     tField = 440,
     tReturn = 441,
     tCall = 442,
     tSlide = 443,
     tMacro = 444,
     tShow = 445,
     tHide = 446,
     tGetValue = 447,
     tGetStringValue = 448,
     tGetEnv = 449,
     tGetString = 450,
     tGetNumber = 451,
     tUnique = 452,
     tHomology = 453,
     tCohomology = 454,
     tBetti = 455,
     tExists = 456,
     tFileExists = 457,
     tGetForced = 458,
     tGetForcedStr = 459,
     tGMSH_MAJOR_VERSION = 460,
     tGMSH_MINOR_VERSION = 461,
     tGMSH_PATCH_VERSION = 462,
     tGmshExecutableName = 463,
     tSetPartition = 464,
     tNameToString = 465,
     tStringToName = 466,
     tAFFECTDIVIDE = 467,
     tAFFECTTIMES = 468,
     tAFFECTMINUS = 469,
     tAFFECTPLUS = 470,
     tOR = 471,
     tAND = 472,
     tNOTEQUAL = 473,
     tEQUAL = 474,
     tGREATERGREATER = 475,
     tLESSLESS = 476,
     tGREATEROREQUAL = 477,
     tLESSOREQUAL = 478,
     UNARYPREC = 479,
     tMINUSMINUS = 480,
     tPLUSPLUS = 481
   };
#endif
<<<<<<< HEAD
/* Tokens.  */
#define tDOUBLE 258
#define tSTRING 259
#define tBIGSTR 260
#define tEND 261
#define tAFFECT 262
#define tDOTS 263
#define tSCOPE 264
#define tPi 265
#define tMPI_Rank 266
#define tMPI_Size 267
#define tEuclidian 268
#define tCoordinates 269
#define tTestLevel 270
#define tExp 271
#define tLog 272
#define tLog10 273
#define tSqrt 274
#define tSin 275
#define tAsin 276
#define tCos 277
#define tAcos 278
#define tTan 279
#define tRand 280
#define tAtan 281
#define tAtan2 282
#define tSinh 283
#define tCosh 284
#define tTanh 285
#define tFabs 286
#define tAbs 287
#define tFloor 288
#define tCeil 289
#define tRound 290
#define tFmod 291
#define tModulo 292
#define tHypot 293
#define tList 294
#define tLinSpace 295
#define tLogSpace 296
#define tListFromFile 297
#define tCatenary 298
#define tPrintf 299
#define tError 300
#define tStr 301
#define tSprintf 302
#define tStrCat 303
#define tStrPrefix 304
#define tStrRelative 305
#define tStrReplace 306
#define tAbsolutePath 307
#define tDirName 308
#define tStrSub 309
#define tStrLen 310
#define tFind 311
#define tStrFind 312
#define tStrCmp 313
#define tStrChoice 314
#define tUpperCase 315
#define tLowerCase 316
#define tLowerCaseIn 317
#define tTextAttributes 318
#define tBoundingBox 319
#define tDraw 320
#define tSetChanged 321
#define tToday 322
#define tFixRelativePath 323
#define tCurrentDirectory 324
#define tSyncModel 325
#define tNewModel 326
#define tOnelabAction 327
#define tOnelabRun 328
#define tCodeName 329
#define tCpu 330
#define tMemory 331
#define tTotalMemory 332
#define tCreateTopology 333
#define tDistanceFunction 334
#define tDefineConstant 335
#define tUndefineConstant 336
#define tDefineNumber 337
#define tDefineStruct 338
#define tNameStruct 339
#define tDimNameSpace 340
#define tAppend 341
#define tDefineString 342
#define tSetNumber 343
#define tSetTag 344
#define tSetString 345
#define tPoint 346
#define tCircle 347
#define tEllipse 348
#define tCurve 349
#define tSphere 350
#define tPolarSphere 351
#define tSurface 352
#define tSpline 353
#define tVolume 354
#define tBox 355
#define tCylinder 356
#define tCone 357
#define tTorus 358
#define tEllipsoid 359
#define tQuadric 360
#define tShapeFromFile 361
#define tRectangle 362
#define tDisk 363
#define tWire 364
#define tGeoEntity 365
#define tCharacteristic 366
#define tLength 367
#define tParametric 368
#define tElliptic 369
#define tRefineMesh 370
#define tAdaptMesh 371
#define tRelocateMesh 372
#define tReorientMesh 373
#define tSetFactory 374
#define tThruSections 375
#define tWedge 376
#define tFillet 377
#define tPlane 378
#define tRuled 379
#define tTransfinite 380
#define tPhysical 381
#define tCompound 382
#define tPeriodic 383
#define tUsing 384
#define tPlugin 385
#define tDegenerated 386
#define tRecursive 387
#define tRotate 388
#define tTranslate 389
#define tSymmetry 390
#define tDilate 391
#define tExtrude 392
#define tLevelset 393
#define tAffine 394
#define tBooleanUnion 395
#define tBooleanIntersection 396
#define tBooleanDifference 397
#define tBooleanSection 398
#define tBooleanFragments 399
#define tThickSolid 400
#define tRecombine 401
#define tSmoother 402
#define tSplit 403
#define tDelete 404
#define tCoherence 405
#define tIntersect 406
#define tMeshAlgorithm 407
#define tReverseMesh 408
#define tLayers 409
#define tScaleLast 410
#define tHole 411
#define tAlias 412
#define tAliasWithOptions 413
#define tCopyOptions 414
#define tQuadTriAddVerts 415
#define tQuadTriNoNewVerts 416
#define tRecombLaterals 417
#define tTransfQuadTri 418
#define tText2D 419
#define tText3D 420
#define tInterpolationScheme 421
#define tTime 422
#define tCombine 423
#define tBSpline 424
#define tBezier 425
#define tNurbs 426
#define tNurbsOrder 427
#define tNurbsKnots 428
#define tColor 429
#define tColorTable 430
#define tFor 431
#define tIn 432
#define tEndFor 433
#define tIf 434
#define tElseIf 435
#define tElse 436
#define tEndIf 437
#define tExit 438
#define tAbort 439
#define tField 440
#define tReturn 441
#define tCall 442
#define tSlide 443
#define tMacro 444
#define tShow 445
#define tHide 446
#define tGetValue 447
#define tGetStringValue 448
#define tGetEnv 449
#define tGetString 450
#define tGetNumber 451
#define tUnique 452
#define tHomology 453
#define tCohomology 454
#define tBetti 455
#define tExists 456
#define tFileExists 457
#define tGetForced 458
#define tGetForcedStr 459
#define tGMSH_MAJOR_VERSION 460
#define tGMSH_MINOR_VERSION 461
#define tGMSH_PATCH_VERSION 462
#define tGmshExecutableName 463
#define tSetPartition 464
#define tNameToString 465
#define tStringToName 466
#define tAFFECTDIVIDE 467
#define tAFFECTTIMES 468
#define tAFFECTMINUS 469
#define tAFFECTPLUS 470
#define tOR 471
#define tAND 472
#define tNOTEQUAL 473
#define tEQUAL 474
#define tGREATERGREATER 475
#define tLESSLESS 476
#define tGREATEROREQUAL 477
#define tLESSOREQUAL 478
#define UNARYPREC 479
#define tMINUSMINUS 480
#define tPLUSPLUS 481


=======
>>>>>>> origin/cgnsUnstructured


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
<<<<<<< HEAD
#line 165 "Gmsh.y"
=======
>>>>>>> origin/cgnsUnstructured
{
/* Line 2058 of yacc.c  */
#line 164 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;


/* Line 2058 of yacc.c  */
#line 295 "Gmsh.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int gmsh_yyparse (void *YYPARSE_PARAM);
#else
int gmsh_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int gmsh_yyparse (void);
#else
int gmsh_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
