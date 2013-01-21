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
     tBoundingBox = 298,
     tDraw = 299,
     tToday = 300,
     tSyncModel = 301,
     tCreateTopology = 302,
     tCreateTopologyNoHoles = 303,
     tDistanceFunction = 304,
     tDefineConstant = 305,
     tPoint = 306,
     tCircle = 307,
     tEllipse = 308,
     tLine = 309,
     tSphere = 310,
     tPolarSphere = 311,
     tSurface = 312,
     tSpline = 313,
     tVolume = 314,
     tCharacteristic = 315,
     tLength = 316,
     tParametric = 317,
     tElliptic = 318,
     tRefineMesh = 319,
     tPlane = 320,
     tRuled = 321,
     tTransfinite = 322,
     tComplex = 323,
     tPhysical = 324,
     tCompound = 325,
     tPeriodic = 326,
     tUsing = 327,
     tPlugin = 328,
     tDegenerated = 329,
     tRotate = 330,
     tTranslate = 331,
     tSymmetry = 332,
     tDilate = 333,
     tExtrude = 334,
     tLevelset = 335,
     tRecombine = 336,
     tSmoother = 337,
     tSplit = 338,
     tDelete = 339,
     tCoherence = 340,
     tIntersect = 341,
     tMeshAlgorithm = 342,
     tLayers = 343,
     tHole = 344,
     tAlias = 345,
     tAliasWithOptions = 346,
     tQuadTriDbl = 347,
     tQuadTriSngl = 348,
     tRecombLaterals = 349,
     tTransfQuadTri = 350,
     tText2D = 351,
     tText3D = 352,
     tInterpolationScheme = 353,
     tTime = 354,
     tCombine = 355,
     tBSpline = 356,
     tBezier = 357,
     tNurbs = 358,
     tNurbsOrder = 359,
     tNurbsKnots = 360,
     tColor = 361,
     tColorTable = 362,
     tFor = 363,
     tIn = 364,
     tEndFor = 365,
     tIf = 366,
     tEndIf = 367,
     tExit = 368,
     tAbort = 369,
     tField = 370,
     tReturn = 371,
     tCall = 372,
     tFunction = 373,
     tShow = 374,
     tHide = 375,
     tGetValue = 376,
     tGetEnv = 377,
     tGetString = 378,
     tHomology = 379,
     tCohomology = 380,
     tGMSH_MAJOR_VERSION = 381,
     tGMSH_MINOR_VERSION = 382,
     tGMSH_PATCH_VERSION = 383,
     tAFFECTDIVIDE = 384,
     tAFFECTTIMES = 385,
     tAFFECTMINUS = 386,
     tAFFECTPLUS = 387,
     tOR = 388,
     tAND = 389,
     tNOTEQUAL = 390,
     tEQUAL = 391,
     tGREATEROREQUAL = 392,
     tLESSOREQUAL = 393,
     UNARYPREC = 394,
     tMINUSMINUS = 395,
     tPLUSPLUS = 396
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 92 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 1685 of yacc.c  */
#line 204 "Gmsh.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;


