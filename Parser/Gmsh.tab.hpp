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
     tOnelabAction = 311,
     tOnelabRun = 312,
     tCpu = 313,
     tMemory = 314,
     tTotalMemory = 315,
     tCreateTopology = 316,
     tCreateTopologyNoHoles = 317,
     tDistanceFunction = 318,
     tDefineConstant = 319,
     tUndefineConstant = 320,
     tDefineNumber = 321,
     tDefineString = 322,
     tPoint = 323,
     tCircle = 324,
     tEllipse = 325,
     tLine = 326,
     tSphere = 327,
     tPolarSphere = 328,
     tSurface = 329,
     tSpline = 330,
     tVolume = 331,
     tCharacteristic = 332,
     tLength = 333,
     tParametric = 334,
     tElliptic = 335,
     tRefineMesh = 336,
     tAdaptMesh = 337,
     tRelocateMesh = 338,
     tPlane = 339,
     tRuled = 340,
     tTransfinite = 341,
     tComplex = 342,
     tPhysical = 343,
     tCompound = 344,
     tPeriodic = 345,
     tUsing = 346,
     tPlugin = 347,
     tDegenerated = 348,
     tRecursive = 349,
     tRotate = 350,
     tTranslate = 351,
     tSymmetry = 352,
     tDilate = 353,
     tExtrude = 354,
     tLevelset = 355,
     tRecombine = 356,
     tSmoother = 357,
     tSplit = 358,
     tDelete = 359,
     tCoherence = 360,
     tIntersect = 361,
     tMeshAlgorithm = 362,
     tReverse = 363,
     tLayers = 364,
     tScaleLast = 365,
     tHole = 366,
     tAlias = 367,
     tAliasWithOptions = 368,
     tCopyOptions = 369,
     tQuadTriAddVerts = 370,
     tQuadTriNoNewVerts = 371,
     tQuadTriSngl = 372,
     tQuadTriDbl = 373,
     tRecombLaterals = 374,
     tTransfQuadTri = 375,
     tText2D = 376,
     tText3D = 377,
     tInterpolationScheme = 378,
     tTime = 379,
     tCombine = 380,
     tBSpline = 381,
     tBezier = 382,
     tNurbs = 383,
     tNurbsOrder = 384,
     tNurbsKnots = 385,
     tColor = 386,
     tColorTable = 387,
     tFor = 388,
     tIn = 389,
     tEndFor = 390,
     tIf = 391,
     tEndIf = 392,
     tExit = 393,
     tAbort = 394,
     tField = 395,
     tReturn = 396,
     tCall = 397,
     tFunction = 398,
     tShow = 399,
     tHide = 400,
     tGetValue = 401,
     tGetEnv = 402,
     tGetString = 403,
     tHomology = 404,
     tCohomology = 405,
     tBetti = 406,
     tSetOrder = 407,
     tExists = 408,
     tFileExists = 409,
     tGMSH_MAJOR_VERSION = 410,
     tGMSH_MINOR_VERSION = 411,
     tGMSH_PATCH_VERSION = 412,
     tAFFECTDIVIDE = 413,
     tAFFECTTIMES = 414,
     tAFFECTMINUS = 415,
     tAFFECTPLUS = 416,
     tOR = 417,
     tAND = 418,
     tNOTEQUAL = 419,
     tEQUAL = 420,
     tGREATEROREQUAL = 421,
     tLESSOREQUAL = 422,
     UNARYPREC = 423,
     tMINUSMINUS = 424,
     tPLUSPLUS = 425
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
#line 238 "Gmsh.tab.hpp"
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
