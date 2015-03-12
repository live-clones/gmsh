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
     tStrFind = 300,
     tStrCmp = 301,
     tStrChoice = 302,
     tTextAttributes = 303,
     tBoundingBox = 304,
     tDraw = 305,
     tSetChanged = 306,
     tToday = 307,
     tFixRelativePath = 308,
     tSyncModel = 309,
     tOnelabAction = 310,
     tOnelabRun = 311,
     tCpu = 312,
     tMemory = 313,
     tTotalMemory = 314,
     tCreateTopology = 315,
     tCreateTopologyNoHoles = 316,
     tDistanceFunction = 317,
     tDefineConstant = 318,
     tUndefineConstant = 319,
     tDefineNumber = 320,
     tDefineString = 321,
     tPoint = 322,
     tCircle = 323,
     tEllipse = 324,
     tLine = 325,
     tSphere = 326,
     tPolarSphere = 327,
     tSurface = 328,
     tSpline = 329,
     tVolume = 330,
     tCharacteristic = 331,
     tLength = 332,
     tParametric = 333,
     tElliptic = 334,
     tRefineMesh = 335,
     tAdaptMesh = 336,
     tRelocateMesh = 337,
     tPlane = 338,
     tRuled = 339,
     tTransfinite = 340,
     tComplex = 341,
     tPhysical = 342,
     tCompound = 343,
     tPeriodic = 344,
     tUsing = 345,
     tPlugin = 346,
     tDegenerated = 347,
     tRecursive = 348,
     tRotate = 349,
     tTranslate = 350,
     tSymmetry = 351,
     tDilate = 352,
     tExtrude = 353,
     tLevelset = 354,
     tRecombine = 355,
     tSmoother = 356,
     tSplit = 357,
     tDelete = 358,
     tCoherence = 359,
     tIntersect = 360,
     tMeshAlgorithm = 361,
     tReverse = 362,
     tLayers = 363,
     tScaleLast = 364,
     tHole = 365,
     tAlias = 366,
     tAliasWithOptions = 367,
     tCopyOptions = 368,
     tQuadTriAddVerts = 369,
     tQuadTriNoNewVerts = 370,
     tQuadTriSngl = 371,
     tQuadTriDbl = 372,
     tRecombLaterals = 373,
     tTransfQuadTri = 374,
     tText2D = 375,
     tText3D = 376,
     tInterpolationScheme = 377,
     tTime = 378,
     tCombine = 379,
     tBSpline = 380,
     tBezier = 381,
     tNurbs = 382,
     tNurbsOrder = 383,
     tNurbsKnots = 384,
     tColor = 385,
     tColorTable = 386,
     tFor = 387,
     tIn = 388,
     tEndFor = 389,
     tIf = 390,
     tEndIf = 391,
     tExit = 392,
     tAbort = 393,
     tField = 394,
     tReturn = 395,
     tCall = 396,
     tFunction = 397,
     tShow = 398,
     tHide = 399,
     tGetValue = 400,
     tGetEnv = 401,
     tGetString = 402,
     tHomology = 403,
     tCohomology = 404,
     tBetti = 405,
     tSetOrder = 406,
     tExists = 407,
     tFileExists = 408,
     tGMSH_MAJOR_VERSION = 409,
     tGMSH_MINOR_VERSION = 410,
     tGMSH_PATCH_VERSION = 411,
     tAFFECTDIVIDE = 412,
     tAFFECTTIMES = 413,
     tAFFECTMINUS = 414,
     tAFFECTPLUS = 415,
     tOR = 416,
     tAND = 417,
     tNOTEQUAL = 418,
     tEQUAL = 419,
     tGREATEROREQUAL = 420,
     tLESSOREQUAL = 421,
     UNARYPREC = 422,
     tMINUSMINUS = 423,
     tPLUSPLUS = 424
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
#line 237 "Gmsh.tab.hpp"
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
