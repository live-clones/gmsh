/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED
# define YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gmsh_yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tDOUBLE = 258,                 /* tDOUBLE  */
    tSTRING = 259,                 /* tSTRING  */
    tBIGSTR = 260,                 /* tBIGSTR  */
    tEND = 261,                    /* tEND  */
    tAFFECT = 262,                 /* tAFFECT  */
    tDOTS = 263,                   /* tDOTS  */
    tSCOPE = 264,                  /* tSCOPE  */
    tPi = 265,                     /* tPi  */
    tMPI_Rank = 266,               /* tMPI_Rank  */
    tMPI_Size = 267,               /* tMPI_Size  */
    tEuclidian = 268,              /* tEuclidian  */
    tCoordinates = 269,            /* tCoordinates  */
    tTestLevel = 270,              /* tTestLevel  */
    tExp = 271,                    /* tExp  */
    tLog = 272,                    /* tLog  */
    tLog10 = 273,                  /* tLog10  */
    tSqrt = 274,                   /* tSqrt  */
    tSin = 275,                    /* tSin  */
    tAsin = 276,                   /* tAsin  */
    tCos = 277,                    /* tCos  */
    tAcos = 278,                   /* tAcos  */
    tTan = 279,                    /* tTan  */
    tRand = 280,                   /* tRand  */
    tStep = 281,                   /* tStep  */
    tAtan = 282,                   /* tAtan  */
    tAtan2 = 283,                  /* tAtan2  */
    tSinh = 284,                   /* tSinh  */
    tCosh = 285,                   /* tCosh  */
    tTanh = 286,                   /* tTanh  */
    tFabs = 287,                   /* tFabs  */
    tAbs = 288,                    /* tAbs  */
    tFloor = 289,                  /* tFloor  */
    tCeil = 290,                   /* tCeil  */
    tRound = 291,                  /* tRound  */
    tMin = 292,                    /* tMin  */
    tMax = 293,                    /* tMax  */
    tFmod = 294,                   /* tFmod  */
    tModulo = 295,                 /* tModulo  */
    tHypot = 296,                  /* tHypot  */
    tList = 297,                   /* tList  */
    tLinSpace = 298,               /* tLinSpace  */
    tLogSpace = 299,               /* tLogSpace  */
    tListFromFile = 300,           /* tListFromFile  */
    tCatenary = 301,               /* tCatenary  */
    tPrintf = 302,                 /* tPrintf  */
    tError = 303,                  /* tError  */
    tWarning = 304,                /* tWarning  */
    tStr = 305,                    /* tStr  */
    tSprintf = 306,                /* tSprintf  */
    tStrCat = 307,                 /* tStrCat  */
    tStrPrefix = 308,              /* tStrPrefix  */
    tStrRelative = 309,            /* tStrRelative  */
    tStrReplace = 310,             /* tStrReplace  */
    tAbsolutePath = 311,           /* tAbsolutePath  */
    tDirName = 312,                /* tDirName  */
    tStrSub = 313,                 /* tStrSub  */
    tStrLen = 314,                 /* tStrLen  */
    tFind = 315,                   /* tFind  */
    tStrFind = 316,                /* tStrFind  */
    tStrCmp = 317,                 /* tStrCmp  */
    tStrChoice = 318,              /* tStrChoice  */
    tUpperCase = 319,              /* tUpperCase  */
    tLowerCase = 320,              /* tLowerCase  */
    tLowerCaseIn = 321,            /* tLowerCaseIn  */
    tTextAttributes = 322,         /* tTextAttributes  */
    tBoundingBox = 323,            /* tBoundingBox  */
    tDraw = 324,                   /* tDraw  */
    tSetChanged = 325,             /* tSetChanged  */
    tToday = 326,                  /* tToday  */
    tFixRelativePath = 327,        /* tFixRelativePath  */
    tCurrentDirectory = 328,       /* tCurrentDirectory  */
    tCurrentFileName = 329,        /* tCurrentFileName  */
    tSyncModel = 330,              /* tSyncModel  */
    tNewModel = 331,               /* tNewModel  */
    tMass = 332,                   /* tMass  */
    tCenterOfMass = 333,           /* tCenterOfMass  */
    tMatrixOfInertia = 334,        /* tMatrixOfInertia  */
    tOnelabAction = 335,           /* tOnelabAction  */
    tOnelabRun = 336,              /* tOnelabRun  */
    tCodeName = 337,               /* tCodeName  */
    tCpu = 338,                    /* tCpu  */
    tMemory = 339,                 /* tMemory  */
    tTotalMemory = 340,            /* tTotalMemory  */
    tCreateTopology = 341,         /* tCreateTopology  */
    tCreateGeometry = 342,         /* tCreateGeometry  */
    tClassifySurfaces = 343,       /* tClassifySurfaces  */
    tRenumberMeshNodes = 344,      /* tRenumberMeshNodes  */
    tRenumberMeshElements = 345,   /* tRenumberMeshElements  */
    tCreateMeshEdges = 346,        /* tCreateMeshEdges  */
    tCreateMeshFaces = 347,        /* tCreateMeshFaces  */
    tDistanceFunction = 348,       /* tDistanceFunction  */
    tDefineConstant = 349,         /* tDefineConstant  */
    tUndefineConstant = 350,       /* tUndefineConstant  */
    tDefineNumber = 351,           /* tDefineNumber  */
    tDefineStruct = 352,           /* tDefineStruct  */
    tNameStruct = 353,             /* tNameStruct  */
    tDimNameSpace = 354,           /* tDimNameSpace  */
    tAppend = 355,                 /* tAppend  */
    tDefineString = 356,           /* tDefineString  */
    tSetNumber = 357,              /* tSetNumber  */
    tSetTag = 358,                 /* tSetTag  */
    tSetString = 359,              /* tSetString  */
    tPoint = 360,                  /* tPoint  */
    tCircle = 361,                 /* tCircle  */
    tEllipse = 362,                /* tEllipse  */
    tCurve = 363,                  /* tCurve  */
    tSphere = 364,                 /* tSphere  */
    tPolarSphere = 365,            /* tPolarSphere  */
    tSurface = 366,                /* tSurface  */
    tSpline = 367,                 /* tSpline  */
    tVolume = 368,                 /* tVolume  */
    tBox = 369,                    /* tBox  */
    tCylinder = 370,               /* tCylinder  */
    tCone = 371,                   /* tCone  */
    tTorus = 372,                  /* tTorus  */
    tEllipsoid = 373,              /* tEllipsoid  */
    tQuadric = 374,                /* tQuadric  */
    tShapeFromFile = 375,          /* tShapeFromFile  */
    tRectangle = 376,              /* tRectangle  */
    tDisk = 377,                   /* tDisk  */
    tWire = 378,                   /* tWire  */
    tGeoEntity = 379,              /* tGeoEntity  */
    tNormal = 380,                 /* tNormal  */
    tCurvature = 381,              /* tCurvature  */
    tCharacteristic = 382,         /* tCharacteristic  */
    tLength = 383,                 /* tLength  */
    tParametric = 384,             /* tParametric  */
    tElliptic = 385,               /* tElliptic  */
    tRefineMesh = 386,             /* tRefineMesh  */
    tRecombineMesh = 387,          /* tRecombineMesh  */
    tAdaptMesh = 388,              /* tAdaptMesh  */
    tTransformMesh = 389,          /* tTransformMesh  */
    tRelocateMesh = 390,           /* tRelocateMesh  */
    tReorientMesh = 391,           /* tReorientMesh  */
    tSetFactory = 392,             /* tSetFactory  */
    tThruSections = 393,           /* tThruSections  */
    tWedge = 394,                  /* tWedge  */
    tFillet = 395,                 /* tFillet  */
    tChamfer = 396,                /* tChamfer  */
    tPlane = 397,                  /* tPlane  */
    tRuled = 398,                  /* tRuled  */
    tTransfinite = 399,            /* tTransfinite  */
    tPhysical = 400,               /* tPhysical  */
    tCompound = 401,               /* tCompound  */
    tPeriodic = 402,               /* tPeriodic  */
    tParent = 403,                 /* tParent  */
    tUsing = 404,                  /* tUsing  */
    tPlugin = 405,                 /* tPlugin  */
    tDegenerated = 406,            /* tDegenerated  */
    tRecursive = 407,              /* tRecursive  */
    tSewing = 408,                 /* tSewing  */
    tRotate = 409,                 /* tRotate  */
    tTranslate = 410,              /* tTranslate  */
    tSymmetry = 411,               /* tSymmetry  */
    tDilate = 412,                 /* tDilate  */
    tExtrude = 413,                /* tExtrude  */
    tLevelset = 414,               /* tLevelset  */
    tAffine = 415,                 /* tAffine  */
    tClosest = 416,                /* tClosest  */
    tBooleanUnion = 417,           /* tBooleanUnion  */
    tBooleanIntersection = 418,    /* tBooleanIntersection  */
    tBooleanDifference = 419,      /* tBooleanDifference  */
    tBooleanSection = 420,         /* tBooleanSection  */
    tBooleanFragments = 421,       /* tBooleanFragments  */
    tThickSolid = 422,             /* tThickSolid  */
    tRecombine = 423,              /* tRecombine  */
    tSmoother = 424,               /* tSmoother  */
    tSplit = 425,                  /* tSplit  */
    tDelete = 426,                 /* tDelete  */
    tCoherence = 427,              /* tCoherence  */
    tHealShapes = 428,             /* tHealShapes  */
    tIntersect = 429,              /* tIntersect  */
    tMeshAlgorithm = 430,          /* tMeshAlgorithm  */
    tReverseMesh = 431,            /* tReverseMesh  */
    tMeshSize = 432,               /* tMeshSize  */
    tMeshSizeFromBoundary = 433,   /* tMeshSizeFromBoundary  */
    tLayers = 434,                 /* tLayers  */
    tScaleLast = 435,              /* tScaleLast  */
    tHole = 436,                   /* tHole  */
    tAlias = 437,                  /* tAlias  */
    tAliasWithOptions = 438,       /* tAliasWithOptions  */
    tCopyOptions = 439,            /* tCopyOptions  */
    tQuadTriAddVerts = 440,        /* tQuadTriAddVerts  */
    tQuadTriNoNewVerts = 441,      /* tQuadTriNoNewVerts  */
    tRecombLaterals = 442,         /* tRecombLaterals  */
    tTransfQuadTri = 443,          /* tTransfQuadTri  */
    tText2D = 444,                 /* tText2D  */
    tText3D = 445,                 /* tText3D  */
    tInterpolationScheme = 446,    /* tInterpolationScheme  */
    tTime = 447,                   /* tTime  */
    tCombine = 448,                /* tCombine  */
    tBSpline = 449,                /* tBSpline  */
    tBezier = 450,                 /* tBezier  */
    tNurbs = 451,                  /* tNurbs  */
    tNurbsOrder = 452,             /* tNurbsOrder  */
    tNurbsKnots = 453,             /* tNurbsKnots  */
    tColor = 454,                  /* tColor  */
    tColorTable = 455,             /* tColorTable  */
    tFor = 456,                    /* tFor  */
    tIn = 457,                     /* tIn  */
    tEndFor = 458,                 /* tEndFor  */
    tIf = 459,                     /* tIf  */
    tElseIf = 460,                 /* tElseIf  */
    tElse = 461,                   /* tElse  */
    tEndIf = 462,                  /* tEndIf  */
    tExit = 463,                   /* tExit  */
    tAbort = 464,                  /* tAbort  */
    tField = 465,                  /* tField  */
    tReturn = 466,                 /* tReturn  */
    tCall = 467,                   /* tCall  */
    tSlide = 468,                  /* tSlide  */
    tMacro = 469,                  /* tMacro  */
    tShow = 470,                   /* tShow  */
    tHide = 471,                   /* tHide  */
    tGetValue = 472,               /* tGetValue  */
    tGetStringValue = 473,         /* tGetStringValue  */
    tGetEnv = 474,                 /* tGetEnv  */
    tGetString = 475,              /* tGetString  */
    tGetNumber = 476,              /* tGetNumber  */
    tUnique = 477,                 /* tUnique  */
    tSetMaxTag = 478,              /* tSetMaxTag  */
    tHomology = 479,               /* tHomology  */
    tCohomology = 480,             /* tCohomology  */
    tBetti = 481,                  /* tBetti  */
    tExists = 482,                 /* tExists  */
    tFileExists = 483,             /* tFileExists  */
    tGetForced = 484,              /* tGetForced  */
    tGetForcedStr = 485,           /* tGetForcedStr  */
    tGMSH_MAJOR_VERSION = 486,     /* tGMSH_MAJOR_VERSION  */
    tGMSH_MINOR_VERSION = 487,     /* tGMSH_MINOR_VERSION  */
    tGMSH_PATCH_VERSION = 488,     /* tGMSH_PATCH_VERSION  */
    tGmshExecutableName = 489,     /* tGmshExecutableName  */
    tSetPartition = 490,           /* tSetPartition  */
    tNameToString = 491,           /* tNameToString  */
    tStringToName = 492,           /* tStringToName  */
    tUnsplitWindow = 493,          /* tUnsplitWindow  */
    tAFFECTPLUS = 494,             /* tAFFECTPLUS  */
    tAFFECTMINUS = 495,            /* tAFFECTMINUS  */
    tAFFECTTIMES = 496,            /* tAFFECTTIMES  */
    tAFFECTDIVIDE = 497,           /* tAFFECTDIVIDE  */
    tOR = 498,                     /* tOR  */
    tAND = 499,                    /* tAND  */
    tEQUAL = 500,                  /* tEQUAL  */
    tNOTEQUAL = 501,               /* tNOTEQUAL  */
    tLESSOREQUAL = 502,            /* tLESSOREQUAL  */
    tGREATEROREQUAL = 503,         /* tGREATEROREQUAL  */
    tLESSLESS = 504,               /* tLESSLESS  */
    tGREATERGREATER = 505,         /* tGREATERGREATER  */
    tPLUSPLUS = 506,               /* tPLUSPLUS  */
    tMINUSMINUS = 507,             /* tMINUSMINUS  */
    UNARYPREC = 508                /* UNARYPREC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 169 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;

#line 328 "Gmsh.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;


int gmsh_yyparse (void);


#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
