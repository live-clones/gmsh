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
    tTextAttributes = 304,
    tBoundingBox = 305,
    tDraw = 306,
    tSetChanged = 307,
    tToday = 308,
    tFixRelativePath = 309,
    tCurrentDirectory = 310,
    tSyncModel = 311,
    tNewModel = 312,
    tOnelabAction = 313,
    tOnelabRun = 314,
    tCpu = 315,
    tMemory = 316,
    tTotalMemory = 317,
    tCreateTopology = 318,
    tCreateTopologyNoHoles = 319,
    tDistanceFunction = 320,
    tDefineConstant = 321,
    tUndefineConstant = 322,
    tDefineNumber = 323,
    tDefineString = 324,
    tSetNumber = 325,
    tSetString = 326,
    tPoint = 327,
    tCircle = 328,
    tEllipse = 329,
    tLine = 330,
    tSphere = 331,
    tPolarSphere = 332,
    tSurface = 333,
    tSpline = 334,
    tVolume = 335,
    tCharacteristic = 336,
    tLength = 337,
    tParametric = 338,
    tElliptic = 339,
    tRefineMesh = 340,
    tAdaptMesh = 341,
    tRelocateMesh = 342,
    tPlane = 343,
    tRuled = 344,
    tTransfinite = 345,
    tComplex = 346,
    tPhysical = 347,
    tCompound = 348,
    tPeriodic = 349,
    tUsing = 350,
    tPlugin = 351,
    tDegenerated = 352,
    tRecursive = 353,
    tRotate = 354,
    tTranslate = 355,
    tSymmetry = 356,
    tDilate = 357,
    tExtrude = 358,
    tLevelset = 359,
    tAffine = 360,
    tRecombine = 361,
    tSmoother = 362,
    tSplit = 363,
    tDelete = 364,
    tCoherence = 365,
    tIntersect = 366,
    tMeshAlgorithm = 367,
    tReverse = 368,
    tLayers = 369,
    tScaleLast = 370,
    tHole = 371,
    tAlias = 372,
    tAliasWithOptions = 373,
    tCopyOptions = 374,
    tQuadTriAddVerts = 375,
    tQuadTriNoNewVerts = 376,
    tQuadTriSngl = 377,
    tQuadTriDbl = 378,
    tRecombLaterals = 379,
    tTransfQuadTri = 380,
    tText2D = 381,
    tText3D = 382,
    tInterpolationScheme = 383,
    tTime = 384,
    tCombine = 385,
    tBSpline = 386,
    tBezier = 387,
    tNurbs = 388,
    tNurbsOrder = 389,
    tNurbsKnots = 390,
    tColor = 391,
    tColorTable = 392,
    tFor = 393,
    tIn = 394,
    tEndFor = 395,
    tIf = 396,
    tEndIf = 397,
    tExit = 398,
    tAbort = 399,
    tField = 400,
    tReturn = 401,
    tCall = 402,
    tMacro = 403,
    tShow = 404,
    tHide = 405,
    tGetValue = 406,
    tGetEnv = 407,
    tGetString = 408,
    tGetNumber = 409,
    tHomology = 410,
    tCohomology = 411,
    tBetti = 412,
    tSetOrder = 413,
    tExists = 414,
    tFileExists = 415,
    tGMSH_MAJOR_VERSION = 416,
    tGMSH_MINOR_VERSION = 417,
    tGMSH_PATCH_VERSION = 418,
    tGmshExecutableName = 419,
    tSetPartition = 420,
    tNameFromString = 421,
    tStringFromName = 422,
    tAFFECTPLUS = 423,
    tAFFECTMINUS = 424,
    tAFFECTTIMES = 425,
    tAFFECTDIVIDE = 426,
    tOR = 427,
    tAND = 428,
    tEQUAL = 429,
    tNOTEQUAL = 430,
    tLESSOREQUAL = 431,
    tGREATEROREQUAL = 432,
    tPLUSPLUS = 433,
    tMINUSMINUS = 434,
    UNARYPREC = 435
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

#line 245 "Gmsh.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
