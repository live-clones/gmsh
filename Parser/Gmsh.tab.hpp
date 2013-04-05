/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
     tStrFind = 297,
     tTextAttributes = 298,
     tBoundingBox = 299,
     tDraw = 300,
     tToday = 301,
     tSyncModel = 302,
     tCreateTopology = 303,
     tCreateTopologyNoHoles = 304,
     tDistanceFunction = 305,
     tDefineConstant = 306,
     tPoint = 307,
     tCircle = 308,
     tEllipse = 309,
     tLine = 310,
     tSphere = 311,
     tPolarSphere = 312,
     tSurface = 313,
     tSpline = 314,
     tVolume = 315,
     tCharacteristic = 316,
     tLength = 317,
     tParametric = 318,
     tElliptic = 319,
     tRefineMesh = 320,
     tPlane = 321,
     tRuled = 322,
     tTransfinite = 323,
     tComplex = 324,
     tPhysical = 325,
     tCompound = 326,
     tPeriodic = 327,
     tUsing = 328,
     tPlugin = 329,
     tDegenerated = 330,
     tRotate = 331,
     tTranslate = 332,
     tSymmetry = 333,
     tDilate = 334,
     tExtrude = 335,
     tLevelset = 336,
     tRecombine = 337,
     tSmoother = 338,
     tSplit = 339,
     tDelete = 340,
     tCoherence = 341,
     tIntersect = 342,
     tMeshAlgorithm = 343,
     tReverse = 344,
     tLayers = 345,
     tHole = 346,
     tAlias = 347,
     tAliasWithOptions = 348,
     tQuadTriDbl = 349,
     tQuadTriSngl = 350,
     tRecombLaterals = 351,
     tTransfQuadTri = 352,
     tText2D = 353,
     tText3D = 354,
     tInterpolationScheme = 355,
     tTime = 356,
     tCombine = 357,
     tBSpline = 358,
     tBezier = 359,
     tNurbs = 360,
     tNurbsOrder = 361,
     tNurbsKnots = 362,
     tColor = 363,
     tColorTable = 364,
     tFor = 365,
     tIn = 366,
     tEndFor = 367,
     tIf = 368,
     tEndIf = 369,
     tExit = 370,
     tAbort = 371,
     tField = 372,
     tReturn = 373,
     tCall = 374,
     tFunction = 375,
     tShow = 376,
     tHide = 377,
     tGetValue = 378,
     tGetEnv = 379,
     tGetString = 380,
     tHomology = 381,
     tCohomology = 382,
     tBetti = 383,
     tSetOrder = 384,
     tGMSH_MAJOR_VERSION = 385,
     tGMSH_MINOR_VERSION = 386,
     tGMSH_PATCH_VERSION = 387,
     tAFFECTDIVIDE = 388,
     tAFFECTTIMES = 389,
     tAFFECTMINUS = 390,
     tAFFECTPLUS = 391,
     tOR = 392,
     tAND = 393,
     tNOTEQUAL = 394,
     tEQUAL = 395,
     tGREATEROREQUAL = 396,
     tLESSOREQUAL = 397,
     UNARYPREC = 398,
     tMINUSMINUS = 399,
     tPLUSPLUS = 400
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 93 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 1685 of yacc.c  */
#line 208 "Gmsh.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;


