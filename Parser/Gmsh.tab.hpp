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
     tPrintf = 290,
     tSprintf = 291,
     tStrCat = 292,
     tStrPrefix = 293,
     tStrRelative = 294,
     tBoundingBox = 295,
     tDraw = 296,
     tToday = 297,
     tCreateTopology = 298,
     tPoint = 299,
     tCircle = 300,
     tEllipse = 301,
     tLine = 302,
     tSphere = 303,
     tPolarSphere = 304,
     tSurface = 305,
     tSpline = 306,
     tVolume = 307,
     tCharacteristic = 308,
     tLength = 309,
     tParametric = 310,
     tElliptic = 311,
     tPlane = 312,
     tRuled = 313,
     tTransfinite = 314,
     tComplex = 315,
     tPhysical = 316,
     tCompound = 317,
     tUsing = 318,
     tPlugin = 319,
     tRotate = 320,
     tTranslate = 321,
     tSymmetry = 322,
     tDilate = 323,
     tExtrude = 324,
     tLoop = 325,
     tRecombine = 326,
     tSmoother = 327,
     tSplit = 328,
     tDelete = 329,
     tCoherence = 330,
     tIntersect = 331,
     tLayers = 332,
     tHole = 333,
     tAlias = 334,
     tAliasWithOptions = 335,
     tText2D = 336,
     tText3D = 337,
     tInterpolationScheme = 338,
     tTime = 339,
     tCombine = 340,
     tBSpline = 341,
     tBezier = 342,
     tNurbs = 343,
     tOrder = 344,
     tKnots = 345,
     tColor = 346,
     tColorTable = 347,
     tFor = 348,
     tIn = 349,
     tEndFor = 350,
     tIf = 351,
     tEndIf = 352,
     tExit = 353,
     tField = 354,
     tReturn = 355,
     tCall = 356,
     tFunction = 357,
     tShow = 358,
     tHide = 359,
     tGetValue = 360,
     tGMSH_MAJOR_VERSION = 361,
     tGMSH_MINOR_VERSION = 362,
     tGMSH_PATCH_VERSION = 363,
     tAFFECTDIVIDE = 364,
     tAFFECTTIMES = 365,
     tAFFECTMINUS = 366,
     tAFFECTPLUS = 367,
     tOR = 368,
     tAND = 369,
     tNOTEQUAL = 370,
     tEQUAL = 371,
     tGREATEROREQUAL = 372,
     tLESSOREQUAL = 373,
     UNARYPREC = 374,
     tMINUSMINUS = 375,
     tPLUSPLUS = 376
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
#define tPrintf 290
#define tSprintf 291
#define tStrCat 292
#define tStrPrefix 293
#define tStrRelative 294
#define tBoundingBox 295
#define tDraw 296
#define tToday 297
#define tCreateTopology 298
#define tPoint 299
#define tCircle 300
#define tEllipse 301
#define tLine 302
#define tSphere 303
#define tPolarSphere 304
#define tSurface 305
#define tSpline 306
#define tVolume 307
#define tCharacteristic 308
#define tLength 309
#define tParametric 310
#define tElliptic 311
#define tPlane 312
#define tRuled 313
#define tTransfinite 314
#define tComplex 315
#define tPhysical 316
#define tCompound 317
#define tUsing 318
#define tPlugin 319
#define tRotate 320
#define tTranslate 321
#define tSymmetry 322
#define tDilate 323
#define tExtrude 324
#define tLoop 325
#define tRecombine 326
#define tSmoother 327
#define tSplit 328
#define tDelete 329
#define tCoherence 330
#define tIntersect 331
#define tLayers 332
#define tHole 333
#define tAlias 334
#define tAliasWithOptions 335
#define tText2D 336
#define tText3D 337
#define tInterpolationScheme 338
#define tTime 339
#define tCombine 340
#define tBSpline 341
#define tBezier 342
#define tNurbs 343
#define tOrder 344
#define tKnots 345
#define tColor 346
#define tColorTable 347
#define tFor 348
#define tIn 349
#define tEndFor 350
#define tIf 351
#define tEndIf 352
#define tExit 353
#define tField 354
#define tReturn 355
#define tCall 356
#define tFunction 357
#define tShow 358
#define tHide 359
#define tGetValue 360
#define tGMSH_MAJOR_VERSION 361
#define tGMSH_MINOR_VERSION 362
#define tGMSH_PATCH_VERSION 363
#define tAFFECTDIVIDE 364
#define tAFFECTTIMES 365
#define tAFFECTMINUS 366
#define tAFFECTPLUS 367
#define tOR 368
#define tAND 369
#define tNOTEQUAL 370
#define tEQUAL 371
#define tGREATEROREQUAL 372
#define tLESSOREQUAL 373
#define UNARYPREC 374
#define tMINUSMINUS 375
#define tPLUSPLUS 376




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 72 "Gmsh.y"
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
#line 301 "Gmsh.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE gmsh_yylval;

