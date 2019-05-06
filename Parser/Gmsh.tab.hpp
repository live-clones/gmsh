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
    tStr = 301,
    tSprintf = 302,
    tStrCat = 303,
    tStrPrefix = 304,
    tStrRelative = 305,
    tStrReplace = 306,
    tAbsolutePath = 307,
    tDirName = 308,
    tStrSub = 309,
    tStrLen = 310,
    tFind = 311,
    tStrFind = 312,
    tStrCmp = 313,
    tStrChoice = 314,
    tUpperCase = 315,
    tLowerCase = 316,
    tLowerCaseIn = 317,
    tTextAttributes = 318,
    tBoundingBox = 319,
    tDraw = 320,
    tSetChanged = 321,
    tToday = 322,
    tFixRelativePath = 323,
    tCurrentDirectory = 324,
    tSyncModel = 325,
    tNewModel = 326,
    tMass = 327,
    tCenterOfMass = 328,
    tOnelabAction = 329,
    tOnelabRun = 330,
    tCodeName = 331,
    tCpu = 332,
    tMemory = 333,
    tTotalMemory = 334,
    tCreateTopology = 335,
    tCreateGeometry = 336,
    tRenumberMeshNodes = 337,
    tRenumberMeshElements = 338,
    tDistanceFunction = 339,
    tDefineConstant = 340,
    tUndefineConstant = 341,
    tDefineNumber = 342,
    tDefineStruct = 343,
    tNameStruct = 344,
    tDimNameSpace = 345,
    tAppend = 346,
    tDefineString = 347,
    tSetNumber = 348,
    tSetTag = 349,
    tSetString = 350,
    tPoint = 351,
    tCircle = 352,
    tEllipse = 353,
    tCurve = 354,
    tSphere = 355,
    tPolarSphere = 356,
    tSurface = 357,
    tSpline = 358,
    tVolume = 359,
    tBox = 360,
    tCylinder = 361,
    tCone = 362,
    tTorus = 363,
    tEllipsoid = 364,
    tQuadric = 365,
    tShapeFromFile = 366,
    tRectangle = 367,
    tDisk = 368,
    tWire = 369,
    tGeoEntity = 370,
    tCharacteristic = 371,
    tLength = 372,
    tParametric = 373,
    tElliptic = 374,
    tRefineMesh = 375,
    tAdaptMesh = 376,
    tRelocateMesh = 377,
    tReorientMesh = 378,
    tSetFactory = 379,
    tThruSections = 380,
    tWedge = 381,
    tFillet = 382,
    tChamfer = 383,
    tPlane = 384,
    tRuled = 385,
    tTransfinite = 386,
    tPhysical = 387,
    tCompound = 388,
    tPeriodic = 389,
    tParent = 390,
    tUsing = 391,
    tPlugin = 392,
    tDegenerated = 393,
    tRecursive = 394,
    tRotate = 395,
    tTranslate = 396,
    tSymmetry = 397,
    tDilate = 398,
    tExtrude = 399,
    tLevelset = 400,
    tAffine = 401,
    tBooleanUnion = 402,
    tBooleanIntersection = 403,
    tBooleanDifference = 404,
    tBooleanSection = 405,
    tBooleanFragments = 406,
    tThickSolid = 407,
    tRecombine = 408,
    tSmoother = 409,
    tSplit = 410,
    tDelete = 411,
    tCoherence = 412,
    tIntersect = 413,
    tMeshAlgorithm = 414,
    tReverseMesh = 415,
    tLayers = 416,
    tScaleLast = 417,
    tHole = 418,
    tAlias = 419,
    tAliasWithOptions = 420,
    tCopyOptions = 421,
    tQuadTriAddVerts = 422,
    tQuadTriNoNewVerts = 423,
    tRecombLaterals = 424,
    tTransfQuadTri = 425,
    tText2D = 426,
    tText3D = 427,
    tInterpolationScheme = 428,
    tTime = 429,
    tCombine = 430,
    tBSpline = 431,
    tBezier = 432,
    tNurbs = 433,
    tNurbsOrder = 434,
    tNurbsKnots = 435,
    tColor = 436,
    tColorTable = 437,
    tFor = 438,
    tIn = 439,
    tEndFor = 440,
    tIf = 441,
    tElseIf = 442,
    tElse = 443,
    tEndIf = 444,
    tExit = 445,
    tAbort = 446,
    tField = 447,
    tReturn = 448,
    tCall = 449,
    tSlide = 450,
    tMacro = 451,
    tShow = 452,
    tHide = 453,
    tGetValue = 454,
    tGetStringValue = 455,
    tGetEnv = 456,
    tGetString = 457,
    tGetNumber = 458,
    tUnique = 459,
    tHomology = 460,
    tCohomology = 461,
    tBetti = 462,
    tExists = 463,
    tFileExists = 464,
    tGetForced = 465,
    tGetForcedStr = 466,
    tGMSH_MAJOR_VERSION = 467,
    tGMSH_MINOR_VERSION = 468,
    tGMSH_PATCH_VERSION = 469,
    tGmshExecutableName = 470,
    tSetPartition = 471,
    tNameToString = 472,
    tStringToName = 473,
    tAFFECTPLUS = 474,
    tAFFECTMINUS = 475,
    tAFFECTTIMES = 476,
    tAFFECTDIVIDE = 477,
    tOR = 478,
    tAND = 479,
    tEQUAL = 480,
    tNOTEQUAL = 481,
    tLESSOREQUAL = 482,
    tGREATEROREQUAL = 483,
    tLESSLESS = 484,
    tGREATERGREATER = 485,
    tPLUSPLUS = 486,
    tMINUSMINUS = 487,
    UNARYPREC = 488
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 167 "Gmsh.y" /* yacc.c:1921  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;

#line 303 "Gmsh.tab.hpp" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
