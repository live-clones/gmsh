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
     tSyncModel = 310,
     tNewModel = 311,
     tOnelabAction = 312,
     tOnelabRun = 313,
     tCpu = 314,
     tMemory = 315,
     tTotalMemory = 316,
     tCreateTopology = 317,
     tCreateTopologyNoHoles = 318,
     tDistanceFunction = 319,
     tDefineConstant = 320,
     tUndefineConstant = 321,
     tDefineNumber = 322,
     tDefineString = 323,
     tSetNumber = 324,
     tSetString = 325,
     tPoint = 326,
     tCircle = 327,
     tEllipse = 328,
     tLine = 329,
     tSphere = 330,
     tPolarSphere = 331,
     tSurface = 332,
     tSpline = 333,
     tVolume = 334,
     tCharacteristic = 335,
     tLength = 336,
     tParametric = 337,
     tElliptic = 338,
     tRefineMesh = 339,
     tAdaptMesh = 340,
     tRelocateMesh = 341,
     tPlane = 342,
     tRuled = 343,
     tTransfinite = 344,
     tComplex = 345,
     tPhysical = 346,
     tCompound = 347,
     tPeriodic = 348,
     tUsing = 349,
     tPlugin = 350,
     tDegenerated = 351,
     tRecursive = 352,
     tRotate = 353,
     tTranslate = 354,
     tSymmetry = 355,
     tDilate = 356,
     tExtrude = 357,
     tLevelset = 358,
     tRecombine = 359,
     tSmoother = 360,
     tSplit = 361,
     tDelete = 362,
     tCoherence = 363,
     tIntersect = 364,
     tMeshAlgorithm = 365,
     tReverse = 366,
     tLayers = 367,
     tScaleLast = 368,
     tHole = 369,
     tAlias = 370,
     tAliasWithOptions = 371,
     tCopyOptions = 372,
     tQuadTriAddVerts = 373,
     tQuadTriNoNewVerts = 374,
     tQuadTriSngl = 375,
     tQuadTriDbl = 376,
     tRecombLaterals = 377,
     tTransfQuadTri = 378,
     tText2D = 379,
     tText3D = 380,
     tInterpolationScheme = 381,
     tTime = 382,
     tCombine = 383,
     tBSpline = 384,
     tBezier = 385,
     tNurbs = 386,
     tNurbsOrder = 387,
     tNurbsKnots = 388,
     tColor = 389,
     tColorTable = 390,
     tFor = 391,
     tIn = 392,
     tEndFor = 393,
     tIf = 394,
     tEndIf = 395,
     tExit = 396,
     tAbort = 397,
     tField = 398,
     tReturn = 399,
     tCall = 400,
     tMacro = 401,
     tShow = 402,
     tHide = 403,
     tGetValue = 404,
     tGetEnv = 405,
     tGetString = 406,
     tGetNumber = 407,
     tHomology = 408,
     tCohomology = 409,
     tBetti = 410,
     tSetOrder = 411,
     tExists = 412,
     tFileExists = 413,
     tGMSH_MAJOR_VERSION = 414,
     tGMSH_MINOR_VERSION = 415,
     tGMSH_PATCH_VERSION = 416,
     tGmshExecutableName = 417,
     tAFFECTDIVIDE = 418,
     tAFFECTTIMES = 419,
     tAFFECTMINUS = 420,
     tAFFECTPLUS = 421,
     tOR = 422,
     tAND = 423,
     tNOTEQUAL = 424,
     tEQUAL = 425,
     tGREATEROREQUAL = 426,
     tLESSOREQUAL = 427,
     UNARYPREC = 428,
     tMINUSMINUS = 429,
     tPLUSPLUS = 430
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 99 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;


/* Line 2053 of yacc.c  */
#line 243 "Gmsh.tab.hpp"
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
