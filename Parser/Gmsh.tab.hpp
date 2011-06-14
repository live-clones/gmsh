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
     tCreateTopologyNoHoles = 300,
     tDistanceFunction = 301,
     tPoint = 302,
     tCircle = 303,
     tEllipse = 304,
     tLine = 305,
     tSphere = 306,
     tPolarSphere = 307,
     tSurface = 308,
     tSpline = 309,
     tVolume = 310,
     tCharacteristic = 311,
     tLength = 312,
     tParametric = 313,
     tElliptic = 314,
     tRefineMesh = 315,
     tPlane = 316,
     tRuled = 317,
     tTransfinite = 318,
     tComplex = 319,
     tPhysical = 320,
     tCompound = 321,
     tPeriodic = 322,
     tUsing = 323,
     tPlugin = 324,
     tDegenerated = 325,
     tRotate = 326,
     tTranslate = 327,
     tSymmetry = 328,
     tDilate = 329,
     tExtrude = 330,
     tLevelset = 331,
     tLoop = 332,
     tRecombine = 333,
     tSmoother = 334,
     tSplit = 335,
     tDelete = 336,
     tCoherence = 337,
     tIntersect = 338,
     tLayers = 339,
     tHole = 340,
     tAlias = 341,
     tAliasWithOptions = 342,
     tText2D = 343,
     tText3D = 344,
     tInterpolationScheme = 345,
     tTime = 346,
     tCombine = 347,
     tBSpline = 348,
     tBezier = 349,
     tNurbs = 350,
     tNurbsOrder = 351,
     tNurbsKnots = 352,
     tColor = 353,
     tColorTable = 354,
     tFor = 355,
     tIn = 356,
     tEndFor = 357,
     tIf = 358,
     tEndIf = 359,
     tExit = 360,
     tField = 361,
     tReturn = 362,
     tCall = 363,
     tFunction = 364,
     tShow = 365,
     tHide = 366,
     tGetValue = 367,
     tGetEnv = 368,
     tGetString = 369,
     tGMSH_MAJOR_VERSION = 370,
     tGMSH_MINOR_VERSION = 371,
     tGMSH_PATCH_VERSION = 372,
     tHomRank = 373,
     tHomGen = 374,
     tHomCut = 375,
     tHomSeq = 376,
     tAFFECTDIVIDE = 377,
     tAFFECTTIMES = 378,
     tAFFECTMINUS = 379,
     tAFFECTPLUS = 380,
     tOR = 381,
     tAND = 382,
     tNOTEQUAL = 383,
     tEQUAL = 384,
     tGREATEROREQUAL = 385,
     tLESSOREQUAL = 386,
     UNARYPREC = 387,
     tMINUSMINUS = 388,
     tPLUSPLUS = 389
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
#line 197 "Gmsh.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;


