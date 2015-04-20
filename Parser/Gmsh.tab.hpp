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
     tPoint = 324,
     tCircle = 325,
     tEllipse = 326,
     tLine = 327,
     tSphere = 328,
     tPolarSphere = 329,
     tSurface = 330,
     tSpline = 331,
     tVolume = 332,
     tCharacteristic = 333,
     tLength = 334,
     tParametric = 335,
     tElliptic = 336,
     tRefineMesh = 337,
     tAdaptMesh = 338,
     tRelocateMesh = 339,
     tPlane = 340,
     tRuled = 341,
     tTransfinite = 342,
     tComplex = 343,
     tPhysical = 344,
     tCompound = 345,
     tPeriodic = 346,
     tUsing = 347,
     tPlugin = 348,
     tDegenerated = 349,
     tRecursive = 350,
     tRotate = 351,
     tTranslate = 352,
     tSymmetry = 353,
     tDilate = 354,
     tExtrude = 355,
     tLevelset = 356,
     tRecombine = 357,
     tSmoother = 358,
     tSplit = 359,
     tDelete = 360,
     tCoherence = 361,
     tIntersect = 362,
     tMeshAlgorithm = 363,
     tReverse = 364,
     tLayers = 365,
     tScaleLast = 366,
     tHole = 367,
     tAlias = 368,
     tAliasWithOptions = 369,
     tCopyOptions = 370,
     tQuadTriAddVerts = 371,
     tQuadTriNoNewVerts = 372,
     tQuadTriSngl = 373,
     tQuadTriDbl = 374,
     tRecombLaterals = 375,
     tTransfQuadTri = 376,
     tText2D = 377,
     tText3D = 378,
     tInterpolationScheme = 379,
     tTime = 380,
     tCombine = 381,
     tBSpline = 382,
     tBezier = 383,
     tNurbs = 384,
     tNurbsOrder = 385,
     tNurbsKnots = 386,
     tColor = 387,
     tColorTable = 388,
     tFor = 389,
     tIn = 390,
     tEndFor = 391,
     tIf = 392,
     tEndIf = 393,
     tExit = 394,
     tAbort = 395,
     tField = 396,
     tReturn = 397,
     tCall = 398,
     tFunction = 399,
     tShow = 400,
     tHide = 401,
     tGetValue = 402,
     tGetEnv = 403,
     tGetString = 404,
     tHomology = 405,
     tCohomology = 406,
     tBetti = 407,
     tSetOrder = 408,
     tExists = 409,
     tFileExists = 410,
     tGMSH_MAJOR_VERSION = 411,
     tGMSH_MINOR_VERSION = 412,
     tGMSH_PATCH_VERSION = 413,
     tAFFECTDIVIDE = 414,
     tAFFECTTIMES = 415,
     tAFFECTMINUS = 416,
     tAFFECTPLUS = 417,
     tOR = 418,
     tAND = 419,
     tNOTEQUAL = 420,
     tEQUAL = 421,
     tGREATEROREQUAL = 422,
     tLESSOREQUAL = 423,
     UNARYPREC = 424,
     tMINUSMINUS = 425,
     tPLUSPLUS = 426
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
#line 239 "Gmsh.tab.hpp"
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
