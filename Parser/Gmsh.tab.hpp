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
     tFixRelativePath = 307,
     tSyncModel = 308,
     tOnelabAction = 309,
     tOnelabRun = 310,
     tCpu = 311,
     tMemory = 312,
     tTotalMemory = 313,
     tCreateTopology = 314,
     tCreateTopologyNoHoles = 315,
     tDistanceFunction = 316,
     tDefineConstant = 317,
     tUndefineConstant = 318,
     tDefineNumber = 319,
     tDefineString = 320,
     tPoint = 321,
     tCircle = 322,
     tEllipse = 323,
     tLine = 324,
     tSphere = 325,
     tPolarSphere = 326,
     tSurface = 327,
     tSpline = 328,
     tVolume = 329,
     tCharacteristic = 330,
     tLength = 331,
     tParametric = 332,
     tElliptic = 333,
     tRefineMesh = 334,
     tAdaptMesh = 335,
     tRelocateMesh = 336,
     tPlane = 337,
     tRuled = 338,
     tTransfinite = 339,
     tComplex = 340,
     tPhysical = 341,
     tCompound = 342,
     tPeriodic = 343,
     tUsing = 344,
     tPlugin = 345,
     tDegenerated = 346,
     tRecursive = 347,
     tRotate = 348,
     tTranslate = 349,
     tSymmetry = 350,
     tDilate = 351,
     tExtrude = 352,
     tLevelset = 353,
     tRecombine = 354,
     tSmoother = 355,
     tSplit = 356,
     tDelete = 357,
     tCoherence = 358,
     tIntersect = 359,
     tMeshAlgorithm = 360,
     tReverse = 361,
     tLayers = 362,
     tScaleLast = 363,
     tHole = 364,
     tAlias = 365,
     tAliasWithOptions = 366,
     tCopyOptions = 367,
     tQuadTriAddVerts = 368,
     tQuadTriNoNewVerts = 369,
     tQuadTriSngl = 370,
     tQuadTriDbl = 371,
     tRecombLaterals = 372,
     tTransfQuadTri = 373,
     tText2D = 374,
     tText3D = 375,
     tInterpolationScheme = 376,
     tTime = 377,
     tCombine = 378,
     tBSpline = 379,
     tBezier = 380,
     tNurbs = 381,
     tNurbsOrder = 382,
     tNurbsKnots = 383,
     tColor = 384,
     tColorTable = 385,
     tFor = 386,
     tIn = 387,
     tEndFor = 388,
     tIf = 389,
     tEndIf = 390,
     tExit = 391,
     tAbort = 392,
     tField = 393,
     tReturn = 394,
     tCall = 395,
     tFunction = 396,
     tShow = 397,
     tHide = 398,
     tGetValue = 399,
     tGetEnv = 400,
     tGetString = 401,
     tHomology = 402,
     tCohomology = 403,
     tBetti = 404,
     tSetOrder = 405,
     tExists = 406,
     tFileExists = 407,
     tGMSH_MAJOR_VERSION = 408,
     tGMSH_MINOR_VERSION = 409,
     tGMSH_PATCH_VERSION = 410,
     tAFFECTDIVIDE = 411,
     tAFFECTTIMES = 412,
     tAFFECTMINUS = 413,
     tAFFECTPLUS = 414,
     tOR = 415,
     tAND = 416,
     tNOTEQUAL = 417,
     tEQUAL = 418,
     tGREATEROREQUAL = 419,
     tLESSOREQUAL = 420,
     UNARYPREC = 421,
     tMINUSMINUS = 422,
     tPLUSPLUS = 423
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
#line 236 "Gmsh.tab.hpp"
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
