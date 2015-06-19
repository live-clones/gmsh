/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gmsh_yydebug;
#endif

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
     tLines = 336,
     tSurfaces = 337,
     tCharacteristic = 338,
     tLength = 339,
     tParametric = 340,
     tElliptic = 341,
     tRefineMesh = 342,
     tAdaptMesh = 343,
     tRelocateMesh = 344,
     tPlane = 345,
     tRuled = 346,
     tTransfinite = 347,
     tComplex = 348,
     tPhysical = 349,
     tCompound = 350,
     tPeriodic = 351,
     tTransform = 352,
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
     tRecombine = 363,
     tSmoother = 364,
     tSplit = 365,
     tDelete = 366,
     tCoherence = 367,
     tIntersect = 368,
     tMeshAlgorithm = 369,
     tReverse = 370,
     tLayers = 371,
     tScaleLast = 372,
     tHole = 373,
     tAlias = 374,
     tAliasWithOptions = 375,
     tCopyOptions = 376,
     tQuadTriAddVerts = 377,
     tQuadTriNoNewVerts = 378,
     tQuadTriSngl = 379,
     tQuadTriDbl = 380,
     tRecombLaterals = 381,
     tTransfQuadTri = 382,
     tText2D = 383,
     tText3D = 384,
     tInterpolationScheme = 385,
     tTime = 386,
     tCombine = 387,
     tBSpline = 388,
     tBezier = 389,
     tNurbs = 390,
     tNurbsOrder = 391,
     tNurbsKnots = 392,
     tColor = 393,
     tColorTable = 394,
     tFor = 395,
     tIn = 396,
     tEndFor = 397,
     tIf = 398,
     tEndIf = 399,
     tExit = 400,
     tAbort = 401,
     tField = 402,
     tReturn = 403,
     tCall = 404,
     tMacro = 405,
     tShow = 406,
     tHide = 407,
     tGetValue = 408,
     tGetEnv = 409,
     tGetString = 410,
     tGetNumber = 411,
     tHomology = 412,
     tCohomology = 413,
     tBetti = 414,
     tSetOrder = 415,
     tExists = 416,
     tFileExists = 417,
     tGMSH_MAJOR_VERSION = 418,
     tGMSH_MINOR_VERSION = 419,
     tGMSH_PATCH_VERSION = 420,
     tGmshExecutableName = 421,
     tSetPartition = 422,
     tAFFECTDIVIDE = 423,
     tAFFECTTIMES = 424,
     tAFFECTMINUS = 425,
     tAFFECTPLUS = 426,
     tOR = 427,
     tAND = 428,
     tNOTEQUAL = 429,
     tEQUAL = 430,
     tGREATEROREQUAL = 431,
     tLESSOREQUAL = 432,
     UNARYPREC = 433,
     tMINUSMINUS = 434,
     tPLUSPLUS = 435
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 105 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;


/* Line 2053 of yacc.c  */
#line 248 "Gmsh.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE gmsh_yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int gmsh_yyparse (void *YYPARSE_PARAM);
#else
int gmsh_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int gmsh_yyparse (void);
#else
int gmsh_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */
