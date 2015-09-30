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
    tLowerCase = 305,
    tLowerCaseIn = 306,
    tTextAttributes = 307,
    tBoundingBox = 308,
    tDraw = 309,
    tSetChanged = 310,
    tToday = 311,
    tFixRelativePath = 312,
    tCurrentDirectory = 313,
    tSyncModel = 314,
    tNewModel = 315,
    tOnelabAction = 316,
    tOnelabRun = 317,
    tCpu = 318,
    tMemory = 319,
    tTotalMemory = 320,
    tCreateTopology = 321,
    tCreateTopologyNoHoles = 322,
    tDistanceFunction = 323,
    tDefineConstant = 324,
    tUndefineConstant = 325,
    tDefineNumber = 326,
    tDefineString = 327,
    tSetNumber = 328,
    tSetString = 329,
    tPoint = 330,
    tCircle = 331,
    tEllipse = 332,
    tLine = 333,
    tSphere = 334,
    tPolarSphere = 335,
    tSurface = 336,
    tSpline = 337,
    tVolume = 338,
    tCharacteristic = 339,
    tLength = 340,
    tParametric = 341,
    tElliptic = 342,
    tRefineMesh = 343,
    tAdaptMesh = 344,
    tRelocateMesh = 345,
    tPlane = 346,
    tRuled = 347,
    tTransfinite = 348,
    tComplex = 349,
    tPhysical = 350,
    tCompound = 351,
    tPeriodic = 352,
    tUsing = 353,
    tPlugin = 354,
    tDegenerated = 355,
    tRecursive = 356,
    tRotate = 357,
    tTranslate = 358,
    tSymmetry = 359,
    tDilate = 360,
    tExtrude = 361,
    tLevelset = 362,
    tAffine = 363,
    tRecombine = 364,
    tSmoother = 365,
    tSplit = 366,
    tDelete = 367,
    tCoherence = 368,
    tIntersect = 369,
    tMeshAlgorithm = 370,
    tReverse = 371,
    tLayers = 372,
    tScaleLast = 373,
    tHole = 374,
    tAlias = 375,
    tAliasWithOptions = 376,
    tCopyOptions = 377,
    tQuadTriAddVerts = 378,
    tQuadTriNoNewVerts = 379,
    tQuadTriSngl = 380,
    tQuadTriDbl = 381,
    tRecombLaterals = 382,
    tTransfQuadTri = 383,
    tText2D = 384,
    tText3D = 385,
    tInterpolationScheme = 386,
    tTime = 387,
    tCombine = 388,
    tBSpline = 389,
    tBezier = 390,
    tNurbs = 391,
    tNurbsOrder = 392,
    tNurbsKnots = 393,
    tColor = 394,
    tColorTable = 395,
    tFor = 396,
    tIn = 397,
    tEndFor = 398,
    tIf = 399,
    tEndIf = 400,
    tExit = 401,
    tAbort = 402,
    tField = 403,
    tReturn = 404,
    tCall = 405,
    tMacro = 406,
    tShow = 407,
    tHide = 408,
    tGetValue = 409,
    tGetEnv = 410,
    tGetString = 411,
    tGetNumber = 412,
    tHomology = 413,
    tCohomology = 414,
    tBetti = 415,
    tSetOrder = 416,
    tExists = 417,
    tFileExists = 418,
    tGMSH_MAJOR_VERSION = 419,
    tGMSH_MINOR_VERSION = 420,
    tGMSH_PATCH_VERSION = 421,
    tGmshExecutableName = 422,
    tSetPartition = 423,
    tNameFromString = 424,
    tStringFromName = 425,
    tAFFECTPLUS = 426,
    tAFFECTMINUS = 427,
    tAFFECTTIMES = 428,
    tAFFECTDIVIDE = 429,
    tOR = 430,
    tAND = 431,
    tEQUAL = 432,
    tNOTEQUAL = 433,
    tLESSOREQUAL = 434,
    tGREATEROREQUAL = 435,
    tPLUSPLUS = 436,
    tMINUSMINUS = 437,
    UNARYPREC = 438
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

#line 248 "Gmsh.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
