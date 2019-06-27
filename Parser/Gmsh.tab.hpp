/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    tSCOPE = 264,
    tPi = 265,
    tMPI_Rank = 266,
    tMPI_Size = 267,
    tEuclidian = 268,
    tCoordinates = 269,
    tTestLevel = 270,
    tExp = 271,
    tLog = 272,
    tLog10 = 273,
    tSqrt = 274,
    tSin = 275,
    tAsin = 276,
    tCos = 277,
    tAcos = 278,
    tTan = 279,
    tRand = 280,
    tAtan = 281,
    tAtan2 = 282,
    tSinh = 283,
    tCosh = 284,
    tTanh = 285,
    tFabs = 286,
    tAbs = 287,
    tFloor = 288,
    tCeil = 289,
    tRound = 290,
    tFmod = 291,
    tModulo = 292,
    tHypot = 293,
    tList = 294,
    tLinSpace = 295,
    tLogSpace = 296,
    tListFromFile = 297,
    tCatenary = 298,
    tPrintf = 299,
    tError = 300,
    tWarning = 301,
    tStr = 302,
    tSprintf = 303,
    tStrCat = 304,
    tStrPrefix = 305,
    tStrRelative = 306,
    tStrReplace = 307,
    tAbsolutePath = 308,
    tDirName = 309,
    tStrSub = 310,
    tStrLen = 311,
    tFind = 312,
    tStrFind = 313,
    tStrCmp = 314,
    tStrChoice = 315,
    tUpperCase = 316,
    tLowerCase = 317,
    tLowerCaseIn = 318,
    tTextAttributes = 319,
    tBoundingBox = 320,
    tDraw = 321,
    tSetChanged = 322,
    tToday = 323,
    tFixRelativePath = 324,
    tCurrentDirectory = 325,
    tSyncModel = 326,
    tNewModel = 327,
    tMass = 328,
    tCenterOfMass = 329,
    tOnelabAction = 330,
    tOnelabRun = 331,
    tCodeName = 332,
    tCpu = 333,
    tMemory = 334,
    tTotalMemory = 335,
    tCreateTopology = 336,
    tCreateGeometry = 337,
    tClassifySurfaces = 338,
    tRenumberMeshNodes = 339,
    tRenumberMeshElements = 340,
    tDistanceFunction = 341,
    tDefineConstant = 342,
    tUndefineConstant = 343,
    tDefineNumber = 344,
    tDefineStruct = 345,
    tNameStruct = 346,
    tDimNameSpace = 347,
    tAppend = 348,
    tDefineString = 349,
    tSetNumber = 350,
    tSetTag = 351,
    tSetString = 352,
    tPoint = 353,
    tCircle = 354,
    tEllipse = 355,
    tCurve = 356,
    tSphere = 357,
    tPolarSphere = 358,
    tSurface = 359,
    tSpline = 360,
    tVolume = 361,
    tBox = 362,
    tCylinder = 363,
    tCone = 364,
    tTorus = 365,
    tEllipsoid = 366,
    tQuadric = 367,
    tShapeFromFile = 368,
    tRectangle = 369,
    tDisk = 370,
    tWire = 371,
    tGeoEntity = 372,
    tCharacteristic = 373,
    tLength = 374,
    tParametric = 375,
    tElliptic = 376,
    tRefineMesh = 377,
    tAdaptMesh = 378,
    tRelocateMesh = 379,
    tReorientMesh = 380,
    tSetFactory = 381,
    tThruSections = 382,
    tWedge = 383,
    tFillet = 384,
    tChamfer = 385,
    tPlane = 386,
    tRuled = 387,
    tTransfinite = 388,
    tPhysical = 389,
    tCompound = 390,
    tPeriodic = 391,
    tParent = 392,
    tUsing = 393,
    tPlugin = 394,
    tDegenerated = 395,
    tRecursive = 396,
    tSewing = 397,
    tRotate = 398,
    tTranslate = 399,
    tSymmetry = 400,
    tDilate = 401,
    tExtrude = 402,
    tLevelset = 403,
    tAffine = 404,
    tBooleanUnion = 405,
    tBooleanIntersection = 406,
    tBooleanDifference = 407,
    tBooleanSection = 408,
    tBooleanFragments = 409,
    tThickSolid = 410,
    tRecombine = 411,
    tSmoother = 412,
    tSplit = 413,
    tDelete = 414,
    tCoherence = 415,
    tIntersect = 416,
    tMeshAlgorithm = 417,
    tReverseMesh = 418,
    tLayers = 419,
    tScaleLast = 420,
    tHole = 421,
    tAlias = 422,
    tAliasWithOptions = 423,
    tCopyOptions = 424,
    tQuadTriAddVerts = 425,
    tQuadTriNoNewVerts = 426,
    tRecombLaterals = 427,
    tTransfQuadTri = 428,
    tText2D = 429,
    tText3D = 430,
    tInterpolationScheme = 431,
    tTime = 432,
    tCombine = 433,
    tBSpline = 434,
    tBezier = 435,
    tNurbs = 436,
    tNurbsOrder = 437,
    tNurbsKnots = 438,
    tColor = 439,
    tColorTable = 440,
    tFor = 441,
    tIn = 442,
    tEndFor = 443,
    tIf = 444,
    tElseIf = 445,
    tElse = 446,
    tEndIf = 447,
    tExit = 448,
    tAbort = 449,
    tField = 450,
    tReturn = 451,
    tCall = 452,
    tSlide = 453,
    tMacro = 454,
    tShow = 455,
    tHide = 456,
    tGetValue = 457,
    tGetStringValue = 458,
    tGetEnv = 459,
    tGetString = 460,
    tGetNumber = 461,
    tUnique = 462,
    tHomology = 463,
    tCohomology = 464,
    tBetti = 465,
    tExists = 466,
    tFileExists = 467,
    tGetForced = 468,
    tGetForcedStr = 469,
    tGMSH_MAJOR_VERSION = 470,
    tGMSH_MINOR_VERSION = 471,
    tGMSH_PATCH_VERSION = 472,
    tGmshExecutableName = 473,
    tSetPartition = 474,
    tNameToString = 475,
    tStringToName = 476,
    tAFFECTPLUS = 477,
    tAFFECTMINUS = 478,
    tAFFECTTIMES = 479,
    tAFFECTDIVIDE = 480,
    tOR = 481,
    tAND = 482,
    tEQUAL = 483,
    tNOTEQUAL = 484,
    tLESSOREQUAL = 485,
    tGREATEROREQUAL = 486,
    tLESSLESS = 487,
    tGREATERGREATER = 488,
    tPLUSPLUS = 489,
    tMINUSMINUS = 490,
    UNARYPREC = 491
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 166 "Gmsh.y" /* yacc.c:1921  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;

#line 306 "Gmsh.tab.hpp" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
