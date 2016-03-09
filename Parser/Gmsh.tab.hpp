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
    tTestLevel = 269,
    tExp = 270,
    tLog = 271,
    tLog10 = 272,
    tSqrt = 273,
    tSin = 274,
    tAsin = 275,
    tCos = 276,
    tAcos = 277,
    tTan = 278,
    tRand = 279,
    tAtan = 280,
    tAtan2 = 281,
    tSinh = 282,
    tCosh = 283,
    tTanh = 284,
    tFabs = 285,
    tFloor = 286,
    tCeil = 287,
    tRound = 288,
    tFmod = 289,
    tModulo = 290,
    tHypot = 291,
    tList = 292,
    tPrintf = 293,
    tError = 294,
    tStr = 295,
    tSprintf = 296,
    tStrCat = 297,
    tStrPrefix = 298,
    tStrRelative = 299,
    tStrReplace = 300,
    tAbsolutePath = 301,
    tDirName = 302,
    tFind = 303,
    tStrFind = 304,
    tStrCmp = 305,
    tStrChoice = 306,
    tUpperCase = 307,
    tLowerCase = 308,
    tLowerCaseIn = 309,
    tTextAttributes = 310,
    tBoundingBox = 311,
    tDraw = 312,
    tSetChanged = 313,
    tToday = 314,
    tFixRelativePath = 315,
    tCurrentDirectory = 316,
    tSyncModel = 317,
    tNewModel = 318,
    tOnelabAction = 319,
    tOnelabRun = 320,
    tCpu = 321,
    tMemory = 322,
    tTotalMemory = 323,
    tCreateTopology = 324,
    tCreateTopologyNoHoles = 325,
    tDistanceFunction = 326,
    tDefineConstant = 327,
    tUndefineConstant = 328,
    tDefineNumber = 329,
    tDefineString = 330,
    tSetNumber = 331,
    tSetString = 332,
    tPoint = 333,
    tCircle = 334,
    tEllipse = 335,
    tLine = 336,
    tSphere = 337,
    tPolarSphere = 338,
    tSurface = 339,
    tSpline = 340,
    tVolume = 341,
    tCharacteristic = 342,
    tLength = 343,
    tParametric = 344,
    tElliptic = 345,
    tRefineMesh = 346,
    tAdaptMesh = 347,
    tRelocateMesh = 348,
    tPlane = 349,
    tRuled = 350,
    tTransfinite = 351,
    tComplex = 352,
    tPhysical = 353,
    tCompound = 354,
    tPeriodic = 355,
    tUsing = 356,
    tPlugin = 357,
    tDegenerated = 358,
    tRecursive = 359,
    tRotate = 360,
    tTranslate = 361,
    tSymmetry = 362,
    tDilate = 363,
    tExtrude = 364,
    tLevelset = 365,
    tAffine = 366,
    tRecombine = 367,
    tSmoother = 368,
    tSplit = 369,
    tDelete = 370,
    tCoherence = 371,
    tIntersect = 372,
    tMeshAlgorithm = 373,
    tReverse = 374,
    tLayers = 375,
    tScaleLast = 376,
    tHole = 377,
    tAlias = 378,
    tAliasWithOptions = 379,
    tCopyOptions = 380,
    tQuadTriAddVerts = 381,
    tQuadTriNoNewVerts = 382,
    tQuadTriSngl = 383,
    tQuadTriDbl = 384,
    tRecombLaterals = 385,
    tTransfQuadTri = 386,
    tText2D = 387,
    tText3D = 388,
    tInterpolationScheme = 389,
    tTime = 390,
    tCombine = 391,
    tBSpline = 392,
    tBezier = 393,
    tNurbs = 394,
    tNurbsOrder = 395,
    tNurbsKnots = 396,
    tColor = 397,
    tColorTable = 398,
    tFor = 399,
    tIn = 400,
    tEndFor = 401,
    tIf = 402,
    tElseIf = 403,
    tElse = 404,
    tEndIf = 405,
    tExit = 406,
    tAbort = 407,
    tField = 408,
    tReturn = 409,
    tCall = 410,
    tMacro = 411,
    tShow = 412,
    tHide = 413,
    tGetValue = 414,
    tGetStringValue = 415,
    tGetEnv = 416,
    tGetString = 417,
    tGetNumber = 418,
    tHomology = 419,
    tCohomology = 420,
    tBetti = 421,
    tExists = 422,
    tFileExists = 423,
    tGMSH_MAJOR_VERSION = 424,
    tGMSH_MINOR_VERSION = 425,
    tGMSH_PATCH_VERSION = 426,
    tGmshExecutableName = 427,
    tSetPartition = 428,
    tNameToString = 429,
    tStringToName = 430,
    tAFFECTPLUS = 431,
    tAFFECTMINUS = 432,
    tAFFECTTIMES = 433,
    tAFFECTDIVIDE = 434,
    tOR = 435,
    tAND = 436,
    tEQUAL = 437,
    tNOTEQUAL = 438,
    tLESSOREQUAL = 439,
    tGREATEROREQUAL = 440,
    tPLUSPLUS = 441,
    tMINUSMINUS = 442,
    UNARYPREC = 443
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 109 "Gmsh.y" /* yacc.c:1909  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;

#line 253 "Gmsh.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
