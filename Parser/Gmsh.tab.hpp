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
     tTextAttributes = 302,
     tBoundingBox = 303,
     tDraw = 304,
     tSetChanged = 305,
     tToday = 306,
     tSyncModel = 307,
     tOnelabAction = 308,
     tOnelabRun = 309,
     tCpu = 310,
     tMemory = 311,
     tTotalMemory = 312,
     tCreateTopology = 313,
     tCreateTopologyNoHoles = 314,
     tDistanceFunction = 315,
     tDefineConstant = 316,
     tUndefineConstant = 317,
     tDefineNumber = 318,
     tDefineString = 319,
     tPoint = 320,
     tCircle = 321,
     tEllipse = 322,
     tLine = 323,
     tSphere = 324,
     tPolarSphere = 325,
     tSurface = 326,
     tSpline = 327,
     tVolume = 328,
     tCharacteristic = 329,
     tLength = 330,
     tParametric = 331,
     tElliptic = 332,
     tRefineMesh = 333,
     tAdaptMesh = 334,
     tRelocateMesh = 335,
     tPlane = 336,
     tRuled = 337,
     tTransfinite = 338,
     tComplex = 339,
     tPhysical = 340,
     tCompound = 341,
     tPeriodic = 342,
     tUsing = 343,
     tPlugin = 344,
     tDegenerated = 345,
     tRecursive = 346,
     tRotate = 347,
     tTranslate = 348,
     tSymmetry = 349,
     tDilate = 350,
     tExtrude = 351,
     tLevelset = 352,
     tRecombine = 353,
     tSmoother = 354,
     tSplit = 355,
     tDelete = 356,
     tCoherence = 357,
     tIntersect = 358,
     tMeshAlgorithm = 359,
     tReverse = 360,
     tLayers = 361,
     tScaleLast = 362,
     tHole = 363,
     tAlias = 364,
     tAliasWithOptions = 365,
     tCopyOptions = 366,
     tQuadTriAddVerts = 367,
     tQuadTriNoNewVerts = 368,
     tQuadTriSngl = 369,
     tQuadTriDbl = 370,
     tRecombLaterals = 371,
     tTransfQuadTri = 372,
     tText2D = 373,
     tText3D = 374,
     tInterpolationScheme = 375,
     tTime = 376,
     tCombine = 377,
     tBSpline = 378,
     tBezier = 379,
     tNurbs = 380,
     tNurbsOrder = 381,
     tNurbsKnots = 382,
     tColor = 383,
     tColorTable = 384,
     tFor = 385,
     tIn = 386,
     tEndFor = 387,
     tIf = 388,
     tEndIf = 389,
     tExit = 390,
     tAbort = 391,
     tField = 392,
     tReturn = 393,
     tCall = 394,
     tFunction = 395,
     tShow = 396,
     tHide = 397,
     tGetValue = 398,
     tGetEnv = 399,
     tGetString = 400,
     tHomology = 401,
     tCohomology = 402,
     tBetti = 403,
     tSetOrder = 404,
     tExists = 405,
     tFileExists = 406,
     tGMSH_MAJOR_VERSION = 407,
     tGMSH_MINOR_VERSION = 408,
     tGMSH_PATCH_VERSION = 409,
     tAFFECTDIVIDE = 410,
     tAFFECTTIMES = 411,
     tAFFECTMINUS = 412,
     tAFFECTPLUS = 413,
     tOR = 414,
     tAND = 415,
     tNOTEQUAL = 416,
     tEQUAL = 417,
     tGREATEROREQUAL = 418,
     tLESSOREQUAL = 419,
     UNARYPREC = 420,
     tMINUSMINUS = 421,
     tPLUSPLUS = 422
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 100 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;


/* Line 2053 of yacc.c  */
#line 235 "Gmsh.tab.hpp"
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
