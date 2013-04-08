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
     tUndefineConstant = 307,
     tPoint = 308,
     tCircle = 309,
     tEllipse = 310,
     tLine = 311,
     tSphere = 312,
     tPolarSphere = 313,
     tSurface = 314,
     tSpline = 315,
     tVolume = 316,
     tCharacteristic = 317,
     tLength = 318,
     tParametric = 319,
     tElliptic = 320,
     tRefineMesh = 321,
     tPlane = 322,
     tRuled = 323,
     tTransfinite = 324,
     tComplex = 325,
     tPhysical = 326,
     tCompound = 327,
     tPeriodic = 328,
     tUsing = 329,
     tPlugin = 330,
     tDegenerated = 331,
     tRotate = 332,
     tTranslate = 333,
     tSymmetry = 334,
     tDilate = 335,
     tExtrude = 336,
     tLevelset = 337,
     tRecombine = 338,
     tSmoother = 339,
     tSplit = 340,
     tDelete = 341,
     tCoherence = 342,
     tIntersect = 343,
     tMeshAlgorithm = 344,
     tReverse = 345,
     tLayers = 346,
     tHole = 347,
     tAlias = 348,
     tAliasWithOptions = 349,
     tQuadTriDbl = 350,
     tQuadTriSngl = 351,
     tRecombLaterals = 352,
     tTransfQuadTri = 353,
     tText2D = 354,
     tText3D = 355,
     tInterpolationScheme = 356,
     tTime = 357,
     tCombine = 358,
     tBSpline = 359,
     tBezier = 360,
     tNurbs = 361,
     tNurbsOrder = 362,
     tNurbsKnots = 363,
     tColor = 364,
     tColorTable = 365,
     tFor = 366,
     tIn = 367,
     tEndFor = 368,
     tIf = 369,
     tEndIf = 370,
     tExit = 371,
     tAbort = 372,
     tField = 373,
     tReturn = 374,
     tCall = 375,
     tFunction = 376,
     tShow = 377,
     tHide = 378,
     tGetValue = 379,
     tGetEnv = 380,
     tGetString = 381,
     tHomology = 382,
     tCohomology = 383,
     tBetti = 384,
     tSetOrder = 385,
     tGMSH_MAJOR_VERSION = 386,
     tGMSH_MINOR_VERSION = 387,
     tGMSH_PATCH_VERSION = 388,
     tAFFECTDIVIDE = 389,
     tAFFECTTIMES = 390,
     tAFFECTMINUS = 391,
     tAFFECTPLUS = 392,
     tOR = 393,
     tAND = 394,
     tNOTEQUAL = 395,
     tEQUAL = 396,
     tGREATEROREQUAL = 397,
     tLESSOREQUAL = 398,
     UNARYPREC = 399,
     tMINUSMINUS = 400,
     tPLUSPLUS = 401
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
#line 209 "Gmsh.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;


