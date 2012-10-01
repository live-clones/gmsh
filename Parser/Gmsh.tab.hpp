/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
     tBoundingBox = 297,
     tDraw = 298,
     tToday = 299,
     tSyncModel = 300,
     tCreateTopology = 301,
     tCreateTopologyNoHoles = 302,
     tDistanceFunction = 303,
     tDefineConstant = 304,
     tPoint = 305,
     tCircle = 306,
     tEllipse = 307,
     tLine = 308,
     tSphere = 309,
     tPolarSphere = 310,
     tSurface = 311,
     tSpline = 312,
     tVolume = 313,
     tCharacteristic = 314,
     tLength = 315,
     tParametric = 316,
     tElliptic = 317,
     tRefineMesh = 318,
     tPlane = 319,
     tRuled = 320,
     tTransfinite = 321,
     tComplex = 322,
     tPhysical = 323,
     tCompound = 324,
     tPeriodic = 325,
     tUsing = 326,
     tPlugin = 327,
     tDegenerated = 328,
     tRotate = 329,
     tTranslate = 330,
     tSymmetry = 331,
     tDilate = 332,
     tExtrude = 333,
     tLevelset = 334,
     tRecombine = 335,
     tSmoother = 336,
     tSplit = 337,
     tDelete = 338,
     tCoherence = 339,
     tIntersect = 340,
     tMeshAlgorithm = 341,
     tLayers = 342,
     tHole = 343,
     tAlias = 344,
     tAliasWithOptions = 345,
     tQuadTriDbl = 346,
     tQuadTriSngl = 347,
     tRecombLaterals = 348,
     tTransfQuadTri = 349,
     tText2D = 350,
     tText3D = 351,
     tInterpolationScheme = 352,
     tTime = 353,
     tCombine = 354,
     tBSpline = 355,
     tBezier = 356,
     tNurbs = 357,
     tNurbsOrder = 358,
     tNurbsKnots = 359,
     tColor = 360,
     tColorTable = 361,
     tFor = 362,
     tIn = 363,
     tEndFor = 364,
     tIf = 365,
     tEndIf = 366,
     tExit = 367,
     tField = 368,
     tReturn = 369,
     tCall = 370,
     tFunction = 371,
     tShow = 372,
     tHide = 373,
     tGetValue = 374,
     tGetEnv = 375,
     tGetString = 376,
     tHomology = 377,
     tCohomology = 378,
     tGMSH_MAJOR_VERSION = 379,
     tGMSH_MINOR_VERSION = 380,
     tGMSH_PATCH_VERSION = 381,
     tAFFECTDIVIDE = 382,
     tAFFECTTIMES = 383,
     tAFFECTMINUS = 384,
     tAFFECTPLUS = 385,
     tOR = 386,
     tAND = 387,
     tNOTEQUAL = 388,
     tEQUAL = 389,
     tGREATEROREQUAL = 390,
     tLESSOREQUAL = 391,
     UNARYPREC = 392,
     tMINUSMINUS = 393,
     tPLUSPLUS = 394
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 92 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 2068 of yacc.c  */
#line 201 "Gmsh.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;


