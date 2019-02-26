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
    tOnelabAction = 327,
    tOnelabRun = 328,
    tCodeName = 329,
    tCpu = 330,
    tMemory = 331,
    tTotalMemory = 332,
    tCreateTopology = 333,
    tCreateGeometry = 334,
    tRenumberMeshNodes = 335,
    tRenumberMeshElements = 336,
    tDistanceFunction = 337,
    tDefineConstant = 338,
    tUndefineConstant = 339,
    tDefineNumber = 340,
    tDefineStruct = 341,
    tNameStruct = 342,
    tDimNameSpace = 343,
    tAppend = 344,
    tDefineString = 345,
    tSetNumber = 346,
    tSetTag = 347,
    tSetString = 348,
    tPoint = 349,
    tCircle = 350,
    tEllipse = 351,
    tCurve = 352,
    tSphere = 353,
    tPolarSphere = 354,
    tSurface = 355,
    tSpline = 356,
    tVolume = 357,
    tBox = 358,
    tCylinder = 359,
    tCone = 360,
    tTorus = 361,
    tEllipsoid = 362,
    tQuadric = 363,
    tShapeFromFile = 364,
    tRectangle = 365,
    tDisk = 366,
    tWire = 367,
    tGeoEntity = 368,
    tCharacteristic = 369,
    tLength = 370,
    tParametric = 371,
    tElliptic = 372,
    tRefineMesh = 373,
    tAdaptMesh = 374,
    tRelocateMesh = 375,
    tReorientMesh = 376,
    tSetFactory = 377,
    tThruSections = 378,
    tWedge = 379,
    tFillet = 380,
    tChamfer = 381,
    tPlane = 382,
    tRuled = 383,
    tTransfinite = 384,
    tPhysical = 385,
    tCompound = 386,
    tPeriodic = 387,
    tParent = 388,
    tUsing = 389,
    tPlugin = 390,
    tDegenerated = 391,
    tRecursive = 392,
    tRotate = 393,
    tTranslate = 394,
    tSymmetry = 395,
    tDilate = 396,
    tExtrude = 397,
    tLevelset = 398,
    tAffine = 399,
    tBooleanUnion = 400,
    tBooleanIntersection = 401,
    tBooleanDifference = 402,
    tBooleanSection = 403,
    tBooleanFragments = 404,
    tThickSolid = 405,
    tRecombine = 406,
    tSmoother = 407,
    tSplit = 408,
    tDelete = 409,
    tCoherence = 410,
    tIntersect = 411,
    tMeshAlgorithm = 412,
    tReverseMesh = 413,
    tLayers = 414,
    tScaleLast = 415,
    tHole = 416,
    tAlias = 417,
    tAliasWithOptions = 418,
    tCopyOptions = 419,
    tQuadTriAddVerts = 420,
    tQuadTriNoNewVerts = 421,
    tRecombLaterals = 422,
    tTransfQuadTri = 423,
    tText2D = 424,
    tText3D = 425,
    tInterpolationScheme = 426,
    tTime = 427,
    tCombine = 428,
    tBSpline = 429,
    tBezier = 430,
    tNurbs = 431,
    tNurbsOrder = 432,
    tNurbsKnots = 433,
    tColor = 434,
    tColorTable = 435,
    tFor = 436,
    tIn = 437,
    tEndFor = 438,
    tIf = 439,
    tElseIf = 440,
    tElse = 441,
    tEndIf = 442,
    tExit = 443,
    tAbort = 444,
    tField = 445,
    tReturn = 446,
    tCall = 447,
    tSlide = 448,
    tMacro = 449,
    tShow = 450,
    tHide = 451,
    tGetValue = 452,
    tGetStringValue = 453,
    tGetEnv = 454,
    tGetString = 455,
    tGetNumber = 456,
    tUnique = 457,
    tHomology = 458,
    tCohomology = 459,
    tBetti = 460,
    tExists = 461,
    tFileExists = 462,
    tGetForced = 463,
    tGetForcedStr = 464,
    tGMSH_MAJOR_VERSION = 465,
    tGMSH_MINOR_VERSION = 466,
    tGMSH_PATCH_VERSION = 467,
    tGmshExecutableName = 468,
    tSetPartition = 469,
    tNameToString = 470,
    tStringToName = 471,
    tAFFECTPLUS = 472,
    tAFFECTMINUS = 473,
    tAFFECTTIMES = 474,
    tAFFECTDIVIDE = 475,
    tOR = 476,
    tAND = 477,
    tEQUAL = 478,
    tNOTEQUAL = 479,
    tLESSOREQUAL = 480,
    tGREATEROREQUAL = 481,
    tLESSLESS = 482,
    tGREATERGREATER = 483,
    tPLUSPLUS = 484,
    tMINUSMINUS = 485,
    UNARYPREC = 486
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

#line 301 "Gmsh.tab.hpp" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
