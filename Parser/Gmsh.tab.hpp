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
     tPrintf = 290,
     tSprintf = 291,
     tStrCat = 292,
     tStrPrefix = 293,
     tStrRelative = 294,
     tBoundingBox = 295,
     tDraw = 296,
     tToday = 297,
     tSyncModel = 298,
     tCreateTopology = 299,
     tDistanceFunction = 300,
     tPoint = 301,
     tCircle = 302,
     tEllipse = 303,
     tLine = 304,
     tSphere = 305,
     tPolarSphere = 306,
     tSurface = 307,
     tSpline = 308,
     tVolume = 309,
     tCharacteristic = 310,
     tLength = 311,
     tParametric = 312,
     tElliptic = 313,
     tRefineMesh = 314,
     tPlane = 315,
     tRuled = 316,
     tTransfinite = 317,
     tComplex = 318,
     tPhysical = 319,
     tCompound = 320,
     tPeriodic = 321,
     tUsing = 322,
     tPlugin = 323,
     tDegenerated = 324,
     tRotate = 325,
     tTranslate = 326,
     tSymmetry = 327,
     tDilate = 328,
     tExtrude = 329,
     tLevelset = 330,
     tLoop = 331,
     tRecombine = 332,
     tSmoother = 333,
     tSplit = 334,
     tDelete = 335,
     tCoherence = 336,
     tIntersect = 337,
     tLayers = 338,
     tHole = 339,
     tAlias = 340,
     tAliasWithOptions = 341,
     tText2D = 342,
     tText3D = 343,
     tInterpolationScheme = 344,
     tTime = 345,
     tCombine = 346,
     tBSpline = 347,
     tBezier = 348,
     tNurbs = 349,
     tNurbsOrder = 350,
     tNurbsKnots = 351,
     tColor = 352,
     tColorTable = 353,
     tFor = 354,
     tIn = 355,
     tEndFor = 356,
     tIf = 357,
     tEndIf = 358,
     tExit = 359,
     tField = 360,
     tReturn = 361,
     tCall = 362,
     tFunction = 363,
     tShow = 364,
     tHide = 365,
     tGetValue = 366,
     tGetEnv = 367,
     tGetString = 368,
     tGMSH_MAJOR_VERSION = 369,
     tGMSH_MINOR_VERSION = 370,
     tGMSH_PATCH_VERSION = 371,
     tHomRank = 372,
     tHomGen = 373,
     tHomCut = 374,
     tHomSeq = 375,
     tAFFECTDIVIDE = 376,
     tAFFECTTIMES = 377,
     tAFFECTMINUS = 378,
     tAFFECTPLUS = 379,
     tOR = 380,
     tAND = 381,
     tNOTEQUAL = 382,
     tEQUAL = 383,
     tGREATEROREQUAL = 384,
     tLESSOREQUAL = 385,
     UNARYPREC = 386,
     tMINUSMINUS = 387,
     tPLUSPLUS = 388
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 88 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;



/* Line 1685 of yacc.c  */
#line 196 "Gmsh.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;


