/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gmsh_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    tRound = 287,
    tFmod = 288,
    tModulo = 289,
    tHypot = 290,
    tList = 291,
    tPrintf = 292,
    tError = 293,
    tStr = 294,
    tSprintf = 295,
    tStrCat = 296,
    tStrPrefix = 297,
    tStrRelative = 298,
    tStrReplace = 299,
    tFind = 300,
    tStrFind = 301,
    tStrCmp = 302,
    tStrChoice = 303,
    tUpperCase = 304,
    tTextAttributes = 305,
    tBoundingBox = 306,
    tDraw = 307,
    tSetChanged = 308,
    tToday = 309,
    tFixRelativePath = 310,
    tCurrentDirectory = 311,
    tSyncModel = 312,
    tNewModel = 313,
    tOnelabAction = 314,
    tOnelabRun = 315,
    tCpu = 316,
    tMemory = 317,
    tTotalMemory = 318,
    tCreateTopology = 319,
    tCreateTopologyNoHoles = 320,
    tDistanceFunction = 321,
    tDefineConstant = 322,
    tUndefineConstant = 323,
    tDefineNumber = 324,
    tDefineString = 325,
    tSetNumber = 326,
    tSetString = 327,
    tPoint = 328,
    tCircle = 329,
    tEllipse = 330,
    tLine = 331,
    tSphere = 332,
    tPolarSphere = 333,
    tSurface = 334,
    tSpline = 335,
    tVolume = 336,
    tCharacteristic = 337,
    tLength = 338,
    tParametric = 339,
    tElliptic = 340,
    tRefineMesh = 341,
    tAdaptMesh = 342,
    tRelocateMesh = 343,
    tPlane = 344,
    tRuled = 345,
    tTransfinite = 346,
    tComplex = 347,
    tPhysical = 348,
    tCompound = 349,
    tPeriodic = 350,
    tUsing = 351,
    tPlugin = 352,
    tDegenerated = 353,
    tRecursive = 354,
    tRotate = 355,
    tTranslate = 356,
    tSymmetry = 357,
    tDilate = 358,
    tExtrude = 359,
    tLevelset = 360,
    tAffine = 361,
    tRecombine = 362,
    tSmoother = 363,
    tSplit = 364,
    tDelete = 365,
    tCoherence = 366,
    tIntersect = 367,
    tMeshAlgorithm = 368,
    tReverse = 369,
    tLayers = 370,
    tScaleLast = 371,
    tHole = 372,
    tAlias = 373,
    tAliasWithOptions = 374,
    tCopyOptions = 375,
    tQuadTriAddVerts = 376,
    tQuadTriNoNewVerts = 377,
    tQuadTriSngl = 378,
    tQuadTriDbl = 379,
    tRecombLaterals = 380,
    tTransfQuadTri = 381,
    tText2D = 382,
    tText3D = 383,
    tInterpolationScheme = 384,
    tTime = 385,
    tCombine = 386,
    tBSpline = 387,
    tBezier = 388,
    tNurbs = 389,
    tNurbsOrder = 390,
    tNurbsKnots = 391,
    tColor = 392,
    tColorTable = 393,
    tFor = 394,
    tIn = 395,
    tEndFor = 396,
    tIf = 397,
    tEndIf = 398,
    tExit = 399,
    tAbort = 400,
    tField = 401,
    tReturn = 402,
    tCall = 403,
    tMacro = 404,
    tShow = 405,
    tHide = 406,
    tGetValue = 407,
    tGetEnv = 408,
    tGetString = 409,
    tGetNumber = 410,
    tHomology = 411,
    tCohomology = 412,
    tBetti = 413,
    tSetOrder = 414,
    tExists = 415,
    tFileExists = 416,
    tGMSH_MAJOR_VERSION = 417,
    tGMSH_MINOR_VERSION = 418,
    tGMSH_PATCH_VERSION = 419,
    tGmshExecutableName = 420,
    tSetPartition = 421,
    tNameFromString = 422,
    tStringFromName = 423,
    tAFFECTPLUS = 424,
    tAFFECTMINUS = 425,
    tAFFECTTIMES = 426,
    tAFFECTDIVIDE = 427,
    tOR = 428,
    tAND = 429,
    tEQUAL = 430,
    tNOTEQUAL = 431,
    tLESSOREQUAL = 432,
    tGREATEROREQUAL = 433,
    tPLUSPLUS = 434,
    tMINUSMINUS = 435,
    UNARYPREC = 436
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 105 "Gmsh.y" /* yacc.c:1909  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;

#line 246 "Gmsh.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
