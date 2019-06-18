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
    tClassifySurfaces = 337,
    tRenumberMeshNodes = 338,
    tRenumberMeshElements = 339,
    tDistanceFunction = 340,
    tDefineConstant = 341,
    tUndefineConstant = 342,
    tDefineNumber = 343,
    tDefineStruct = 344,
    tNameStruct = 345,
    tDimNameSpace = 346,
    tAppend = 347,
    tDefineString = 348,
    tSetNumber = 349,
    tSetTag = 350,
    tSetString = 351,
    tPoint = 352,
    tCircle = 353,
    tEllipse = 354,
    tCurve = 355,
    tSphere = 356,
    tPolarSphere = 357,
    tSurface = 358,
    tSpline = 359,
    tVolume = 360,
    tBox = 361,
    tCylinder = 362,
    tCone = 363,
    tTorus = 364,
    tEllipsoid = 365,
    tQuadric = 366,
    tShapeFromFile = 367,
    tRectangle = 368,
    tDisk = 369,
    tWire = 370,
    tGeoEntity = 371,
    tCharacteristic = 372,
    tLength = 373,
    tParametric = 374,
    tElliptic = 375,
    tRefineMesh = 376,
    tAdaptMesh = 377,
    tRelocateMesh = 378,
    tReorientMesh = 379,
    tSetFactory = 380,
    tThruSections = 381,
    tWedge = 382,
    tFillet = 383,
    tChamfer = 384,
    tPlane = 385,
    tRuled = 386,
    tTransfinite = 387,
    tPhysical = 388,
    tCompound = 389,
    tPeriodic = 390,
    tParent = 391,
    tUsing = 392,
    tPlugin = 393,
    tDegenerated = 394,
    tRecursive = 395,
    tRotate = 396,
    tTranslate = 397,
    tSymmetry = 398,
    tDilate = 399,
    tExtrude = 400,
    tLevelset = 401,
    tAffine = 402,
    tBooleanUnion = 403,
    tBooleanIntersection = 404,
    tBooleanDifference = 405,
    tBooleanSection = 406,
    tBooleanFragments = 407,
    tThickSolid = 408,
    tRecombine = 409,
    tSmoother = 410,
    tSplit = 411,
    tDelete = 412,
    tCoherence = 413,
    tIntersect = 414,
    tMeshAlgorithm = 415,
    tReverseMesh = 416,
    tLayers = 417,
    tScaleLast = 418,
    tHole = 419,
    tAlias = 420,
    tAliasWithOptions = 421,
    tCopyOptions = 422,
    tQuadTriAddVerts = 423,
    tQuadTriNoNewVerts = 424,
    tRecombLaterals = 425,
    tTransfQuadTri = 426,
    tText2D = 427,
    tText3D = 428,
    tInterpolationScheme = 429,
    tTime = 430,
    tCombine = 431,
    tBSpline = 432,
    tBezier = 433,
    tNurbs = 434,
    tNurbsOrder = 435,
    tNurbsKnots = 436,
    tColor = 437,
    tColorTable = 438,
    tFor = 439,
    tIn = 440,
    tEndFor = 441,
    tIf = 442,
    tElseIf = 443,
    tElse = 444,
    tEndIf = 445,
    tExit = 446,
    tAbort = 447,
    tField = 448,
    tReturn = 449,
    tCall = 450,
    tSlide = 451,
    tMacro = 452,
    tShow = 453,
    tHide = 454,
    tGetValue = 455,
    tGetStringValue = 456,
    tGetEnv = 457,
    tGetString = 458,
    tGetNumber = 459,
    tUnique = 460,
    tHomology = 461,
    tCohomology = 462,
    tBetti = 463,
    tExists = 464,
    tFileExists = 465,
    tGetForced = 466,
    tGetForcedStr = 467,
    tGMSH_MAJOR_VERSION = 468,
    tGMSH_MINOR_VERSION = 469,
    tGMSH_PATCH_VERSION = 470,
    tGmshExecutableName = 471,
    tSetPartition = 472,
    tNameToString = 473,
    tStringToName = 474,
    tAFFECTPLUS = 475,
    tAFFECTMINUS = 476,
    tAFFECTTIMES = 477,
    tAFFECTDIVIDE = 478,
    tOR = 479,
    tAND = 480,
    tEQUAL = 481,
    tNOTEQUAL = 482,
    tLESSOREQUAL = 483,
    tGREATEROREQUAL = 484,
    tLESSLESS = 485,
    tGREATERGREATER = 486,
    tPLUSPLUS = 487,
    tMINUSMINUS = 488,
    UNARYPREC = 489
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

#line 304 "Gmsh.tab.hpp" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
