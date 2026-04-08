/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         gmsh_yyparse
#define yylex           gmsh_yylex
#define yyerror         gmsh_yyerror
#define yydebug         gmsh_yydebug
#define yynerrs         gmsh_yynerrs
#define yylval          gmsh_yylval
#define yychar          gmsh_yychar

/* First part of user prologue.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <map>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "fullMatrix.h"
#include "MallocUtils.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "StringUtils.h"
#include "Numeric.h"
#include "Context.h"
#include "GModel.h"
#include "GModelIO_GEO.h"
#include "GModelIO_OCC.h"
#include "GeoDefines.h"
#include "ExtrudeParams.h"
#include "Options.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "FunctionManager.h"
#include "ColorTable.h"
#include "OS.h"
#include "CreateFile.h"
#include "gmshSurface.h"
#include "gmshLevelset.h"
#include "fullMatrix.h"

#if defined(HAVE_MESH)
#include "Field.h"
#include "BackgroundMesh.h"
#include "HighOrder.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewDataList.h"
#endif

#if defined(HAVE_PLUGINS)
#include "PluginManager.h"
#endif

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

#if defined(HAVE_POPPLER)
#include "gmshPopplerWrapper.h"
#endif

#define MAX_RECUR_TESTS 100
#define MAX_RECUR_LOOPS 100

// global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;
std::string gmsh_yyfactory;
NameSpaces gmsh_yynamespaces;

// static parser variables (accessible only in this file)
#if defined(HAVE_POST)
static PViewDataList *ViewData = 0;
#endif
static std::vector<double> ViewCoord;
static std::vector<double> *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static gmshSurface *myGmshSurface = 0;
static int statusImbricatedTests[MAX_RECUR_TESTS];
static int ImbricatedLoop = 0, ImbricatedTest = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static std::string LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::string struct_name, struct_namespace;
static int dim_entity;

static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;
static int flag_Enum, member_ValMax;

void init_options(int member_ValMax_ = 0)
{
  floatOptions.clear(); charOptions.clear();
  flag_Enum = 0; member_ValMax = member_ValMax_;
}

// parser functions defined at the end of this file
void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
char *strsave(char *ptr);
void skip(const char *skip, const char *until);
void skipTest(const char *skip, const char *until,
              const char *until2, int l_until2_sub, int *type_until2);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int printListOfDouble(const char *format, List_T *list, std::string &buffer);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);
void ListOfDouble2Vector(List_T *list, std::vector<int> &v);
void ListOfDouble2Vector(List_T *list, std::vector<double> &v);
void ListOfShapes2VectorOfPairs(List_T *list, std::vector<std::pair<int, int> > &v);
void VectorOfPairs2ListOfShapes(const std::vector<std::pair<int, int> > &v, List_T *list);
void addPeriodicEdge(int, int, const std::vector<double>&);
void addPeriodicFace(int, int, const std::map<int, int>&);
void addPeriodicFace(int, int, const std::vector<double>&);
void computeAffineTransformation(SPoint3&, SPoint3&, double, SPoint3&,
                                 std::vector<double>&);
void addEmbedded(int dim, std::vector<int> tags, int dim2, int tag2);
void removeEmbedded(const std::vector<std::pair<int, int> > &dimTags, int dim);
void getAllElementaryTags(int dim, List_T *in);
void getAllPhysicalTags(int dim, List_T *in);
void getElementaryTagsForPhysicalGroups(int dim, List_T *in, List_T *out);
void getElementaryTagsInBoundingBox(int dim, double x1, double y1, double z1,
                                    double x2, double y2, double z2, List_T *out);
void getParentTags(int dim, List_T *in, List_T *out);
void getBoundingBox(int dim, List_T *in, List_T *out);
void setVisibility(int dim, int visible, bool recursive);
void setVisibility(const std::vector<std::pair<int, int> > &dimTags, int visible,
                   bool recursive);
void setColor(const std::vector<std::pair<int, int> > &dimTags, unsigned int val,
              bool recursive);

double treat_Struct_FullName_Float
  (char* c1, char* c2, int type_var = 1, int index = 0,
   double val_default = 0., int type_treat = 0);
double treat_Struct_FullName_dot_tSTRING_Float
  (char* c1, char* c2, char* c3, int index = 0,
   double val_default = 0., int type_treat = 0);
List_T * treat_Struct_FullName_dot_tSTRING_ListOfFloat
  (char* c1, char* c2, char* c3);
int treat_Struct_FullName_dot_tSTRING_Float_getDim
  (char* c1, char* c2, char* c3);
char* treat_Struct_FullName_String
  (char* c1, char* c2, int type_var = 1, int index = 0,
   char* val_default = nullptr, int type_treat = 0);
char* treat_Struct_FullName_dot_tSTRING_String
  (char* c1, char* c2, char* c3, int index = 0,
   char* val_default = nullptr, int type_treat = 0);
List_T * treat_Struct_FullName_dot_tSTRING_ListOfString
  (char* c1, char* c2, char* c3);

struct doubleXstring{
  double d;
  char *s;
};


#line 246 "Gmsh.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Gmsh.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tDOUBLE = 3,                    /* tDOUBLE  */
  YYSYMBOL_tSTRING = 4,                    /* tSTRING  */
  YYSYMBOL_tBIGSTR = 5,                    /* tBIGSTR  */
  YYSYMBOL_tEND = 6,                       /* tEND  */
  YYSYMBOL_tAFFECT = 7,                    /* tAFFECT  */
  YYSYMBOL_tDOTS = 8,                      /* tDOTS  */
  YYSYMBOL_tSCOPE = 9,                     /* tSCOPE  */
  YYSYMBOL_tPi = 10,                       /* tPi  */
  YYSYMBOL_tMPI_Rank = 11,                 /* tMPI_Rank  */
  YYSYMBOL_tMPI_Size = 12,                 /* tMPI_Size  */
  YYSYMBOL_tEuclidian = 13,                /* tEuclidian  */
  YYSYMBOL_tCoordinates = 14,              /* tCoordinates  */
  YYSYMBOL_tTestLevel = 15,                /* tTestLevel  */
  YYSYMBOL_tExp = 16,                      /* tExp  */
  YYSYMBOL_tLog = 17,                      /* tLog  */
  YYSYMBOL_tLog10 = 18,                    /* tLog10  */
  YYSYMBOL_tSqrt = 19,                     /* tSqrt  */
  YYSYMBOL_tSin = 20,                      /* tSin  */
  YYSYMBOL_tAsin = 21,                     /* tAsin  */
  YYSYMBOL_tCos = 22,                      /* tCos  */
  YYSYMBOL_tAcos = 23,                     /* tAcos  */
  YYSYMBOL_tTan = 24,                      /* tTan  */
  YYSYMBOL_tRand = 25,                     /* tRand  */
  YYSYMBOL_tStep = 26,                     /* tStep  */
  YYSYMBOL_tAtan = 27,                     /* tAtan  */
  YYSYMBOL_tAtan2 = 28,                    /* tAtan2  */
  YYSYMBOL_tSinh = 29,                     /* tSinh  */
  YYSYMBOL_tCosh = 30,                     /* tCosh  */
  YYSYMBOL_tTanh = 31,                     /* tTanh  */
  YYSYMBOL_tFabs = 32,                     /* tFabs  */
  YYSYMBOL_tAbs = 33,                      /* tAbs  */
  YYSYMBOL_tFloor = 34,                    /* tFloor  */
  YYSYMBOL_tCeil = 35,                     /* tCeil  */
  YYSYMBOL_tRound = 36,                    /* tRound  */
  YYSYMBOL_tMin = 37,                      /* tMin  */
  YYSYMBOL_tMax = 38,                      /* tMax  */
  YYSYMBOL_tFmod = 39,                     /* tFmod  */
  YYSYMBOL_tModulo = 40,                   /* tModulo  */
  YYSYMBOL_tHypot = 41,                    /* tHypot  */
  YYSYMBOL_tList = 42,                     /* tList  */
  YYSYMBOL_tLinSpace = 43,                 /* tLinSpace  */
  YYSYMBOL_tLogSpace = 44,                 /* tLogSpace  */
  YYSYMBOL_tListFromFile = 45,             /* tListFromFile  */
  YYSYMBOL_tCatenary = 46,                 /* tCatenary  */
  YYSYMBOL_tPrintf = 47,                   /* tPrintf  */
  YYSYMBOL_tError = 48,                    /* tError  */
  YYSYMBOL_tWarning = 49,                  /* tWarning  */
  YYSYMBOL_tStr = 50,                      /* tStr  */
  YYSYMBOL_tSprintf = 51,                  /* tSprintf  */
  YYSYMBOL_tStrCat = 52,                   /* tStrCat  */
  YYSYMBOL_tStrPrefix = 53,                /* tStrPrefix  */
  YYSYMBOL_tStrRelative = 54,              /* tStrRelative  */
  YYSYMBOL_tStrReplace = 55,               /* tStrReplace  */
  YYSYMBOL_tAbsolutePath = 56,             /* tAbsolutePath  */
  YYSYMBOL_tDirName = 57,                  /* tDirName  */
  YYSYMBOL_tStrSub = 58,                   /* tStrSub  */
  YYSYMBOL_tStrLen = 59,                   /* tStrLen  */
  YYSYMBOL_tFind = 60,                     /* tFind  */
  YYSYMBOL_tStrFind = 61,                  /* tStrFind  */
  YYSYMBOL_tStrCmp = 62,                   /* tStrCmp  */
  YYSYMBOL_tStrChoice = 63,                /* tStrChoice  */
  YYSYMBOL_tUpperCase = 64,                /* tUpperCase  */
  YYSYMBOL_tLowerCase = 65,                /* tLowerCase  */
  YYSYMBOL_tLowerCaseIn = 66,              /* tLowerCaseIn  */
  YYSYMBOL_tTextAttributes = 67,           /* tTextAttributes  */
  YYSYMBOL_tBoundingBox = 68,              /* tBoundingBox  */
  YYSYMBOL_tDraw = 69,                     /* tDraw  */
  YYSYMBOL_tSetChanged = 70,               /* tSetChanged  */
  YYSYMBOL_tToday = 71,                    /* tToday  */
  YYSYMBOL_tFixRelativePath = 72,          /* tFixRelativePath  */
  YYSYMBOL_tCurrentDirectory = 73,         /* tCurrentDirectory  */
  YYSYMBOL_tCurrentFileName = 74,          /* tCurrentFileName  */
  YYSYMBOL_tSyncModel = 75,                /* tSyncModel  */
  YYSYMBOL_tNewModel = 76,                 /* tNewModel  */
  YYSYMBOL_tMass = 77,                     /* tMass  */
  YYSYMBOL_tCenterOfMass = 78,             /* tCenterOfMass  */
  YYSYMBOL_tMatrixOfInertia = 79,          /* tMatrixOfInertia  */
  YYSYMBOL_tOnelabAction = 80,             /* tOnelabAction  */
  YYSYMBOL_tOnelabRun = 81,                /* tOnelabRun  */
  YYSYMBOL_tCodeName = 82,                 /* tCodeName  */
  YYSYMBOL_tCpu = 83,                      /* tCpu  */
  YYSYMBOL_tMemory = 84,                   /* tMemory  */
  YYSYMBOL_tTotalMemory = 85,              /* tTotalMemory  */
  YYSYMBOL_tCreateTopology = 86,           /* tCreateTopology  */
  YYSYMBOL_tCreateGeometry = 87,           /* tCreateGeometry  */
  YYSYMBOL_tClassifySurfaces = 88,         /* tClassifySurfaces  */
  YYSYMBOL_tRenumberMeshNodes = 89,        /* tRenumberMeshNodes  */
  YYSYMBOL_tRenumberMeshElements = 90,     /* tRenumberMeshElements  */
  YYSYMBOL_tCreateMeshEdges = 91,          /* tCreateMeshEdges  */
  YYSYMBOL_tCreateMeshFaces = 92,          /* tCreateMeshFaces  */
  YYSYMBOL_tDistanceFunction = 93,         /* tDistanceFunction  */
  YYSYMBOL_tDefineConstant = 94,           /* tDefineConstant  */
  YYSYMBOL_tUndefineConstant = 95,         /* tUndefineConstant  */
  YYSYMBOL_tDefineNumber = 96,             /* tDefineNumber  */
  YYSYMBOL_tDefineStruct = 97,             /* tDefineStruct  */
  YYSYMBOL_tNameStruct = 98,               /* tNameStruct  */
  YYSYMBOL_tDimNameSpace = 99,             /* tDimNameSpace  */
  YYSYMBOL_tAppend = 100,                  /* tAppend  */
  YYSYMBOL_tDefineString = 101,            /* tDefineString  */
  YYSYMBOL_tSetNumber = 102,               /* tSetNumber  */
  YYSYMBOL_tSetTag = 103,                  /* tSetTag  */
  YYSYMBOL_tSetString = 104,               /* tSetString  */
  YYSYMBOL_tPoint = 105,                   /* tPoint  */
  YYSYMBOL_tCircle = 106,                  /* tCircle  */
  YYSYMBOL_tEllipse = 107,                 /* tEllipse  */
  YYSYMBOL_tCurve = 108,                   /* tCurve  */
  YYSYMBOL_tSphere = 109,                  /* tSphere  */
  YYSYMBOL_tPolarSphere = 110,             /* tPolarSphere  */
  YYSYMBOL_tSurface = 111,                 /* tSurface  */
  YYSYMBOL_tSpline = 112,                  /* tSpline  */
  YYSYMBOL_tVolume = 113,                  /* tVolume  */
  YYSYMBOL_tBox = 114,                     /* tBox  */
  YYSYMBOL_tCylinder = 115,                /* tCylinder  */
  YYSYMBOL_tCone = 116,                    /* tCone  */
  YYSYMBOL_tTorus = 117,                   /* tTorus  */
  YYSYMBOL_tEllipsoid = 118,               /* tEllipsoid  */
  YYSYMBOL_tQuadric = 119,                 /* tQuadric  */
  YYSYMBOL_tShapeFromFile = 120,           /* tShapeFromFile  */
  YYSYMBOL_tRectangle = 121,               /* tRectangle  */
  YYSYMBOL_tDisk = 122,                    /* tDisk  */
  YYSYMBOL_tWire = 123,                    /* tWire  */
  YYSYMBOL_tGeoEntity = 124,               /* tGeoEntity  */
  YYSYMBOL_tNormal = 125,                  /* tNormal  */
  YYSYMBOL_tCurvature = 126,               /* tCurvature  */
  YYSYMBOL_tCharacteristic = 127,          /* tCharacteristic  */
  YYSYMBOL_tLength = 128,                  /* tLength  */
  YYSYMBOL_tParametric = 129,              /* tParametric  */
  YYSYMBOL_tElliptic = 130,                /* tElliptic  */
  YYSYMBOL_tRefineMesh = 131,              /* tRefineMesh  */
  YYSYMBOL_tRecombineMesh = 132,           /* tRecombineMesh  */
  YYSYMBOL_tAdaptMesh = 133,               /* tAdaptMesh  */
  YYSYMBOL_tTransformMesh = 134,           /* tTransformMesh  */
  YYSYMBOL_tRelocateMesh = 135,            /* tRelocateMesh  */
  YYSYMBOL_tReorientMesh = 136,            /* tReorientMesh  */
  YYSYMBOL_tSetFactory = 137,              /* tSetFactory  */
  YYSYMBOL_tThruSections = 138,            /* tThruSections  */
  YYSYMBOL_tWedge = 139,                   /* tWedge  */
  YYSYMBOL_tFillet = 140,                  /* tFillet  */
  YYSYMBOL_tChamfer = 141,                 /* tChamfer  */
  YYSYMBOL_tPlane = 142,                   /* tPlane  */
  YYSYMBOL_tRuled = 143,                   /* tRuled  */
  YYSYMBOL_tTransfinite = 144,             /* tTransfinite  */
  YYSYMBOL_tPhysical = 145,                /* tPhysical  */
  YYSYMBOL_tCompound = 146,                /* tCompound  */
  YYSYMBOL_tPeriodic = 147,                /* tPeriodic  */
  YYSYMBOL_tParent = 148,                  /* tParent  */
  YYSYMBOL_tUsing = 149,                   /* tUsing  */
  YYSYMBOL_tPlugin = 150,                  /* tPlugin  */
  YYSYMBOL_tDegenerated = 151,             /* tDegenerated  */
  YYSYMBOL_tRecursive = 152,               /* tRecursive  */
  YYSYMBOL_tSewing = 153,                  /* tSewing  */
  YYSYMBOL_tRotate = 154,                  /* tRotate  */
  YYSYMBOL_tTranslate = 155,               /* tTranslate  */
  YYSYMBOL_tSymmetry = 156,                /* tSymmetry  */
  YYSYMBOL_tDilate = 157,                  /* tDilate  */
  YYSYMBOL_tExtrude = 158,                 /* tExtrude  */
  YYSYMBOL_tLevelset = 159,                /* tLevelset  */
  YYSYMBOL_tAffine = 160,                  /* tAffine  */
  YYSYMBOL_tClosest = 161,                 /* tClosest  */
  YYSYMBOL_tBooleanUnion = 162,            /* tBooleanUnion  */
  YYSYMBOL_tBooleanIntersection = 163,     /* tBooleanIntersection  */
  YYSYMBOL_tBooleanDifference = 164,       /* tBooleanDifference  */
  YYSYMBOL_tBooleanSection = 165,          /* tBooleanSection  */
  YYSYMBOL_tBooleanFragments = 166,        /* tBooleanFragments  */
  YYSYMBOL_tThickSolid = 167,              /* tThickSolid  */
  YYSYMBOL_tRecombine = 168,               /* tRecombine  */
  YYSYMBOL_tSmoother = 169,                /* tSmoother  */
  YYSYMBOL_tSplit = 170,                   /* tSplit  */
  YYSYMBOL_tDelete = 171,                  /* tDelete  */
  YYSYMBOL_tCoherence = 172,               /* tCoherence  */
  YYSYMBOL_tHealShapes = 173,              /* tHealShapes  */
  YYSYMBOL_tIntersect = 174,               /* tIntersect  */
  YYSYMBOL_tMeshAlgorithm = 175,           /* tMeshAlgorithm  */
  YYSYMBOL_tReverseMesh = 176,             /* tReverseMesh  */
  YYSYMBOL_tMeshSize = 177,                /* tMeshSize  */
  YYSYMBOL_tMeshSizeFromBoundary = 178,    /* tMeshSizeFromBoundary  */
  YYSYMBOL_tLayers = 179,                  /* tLayers  */
  YYSYMBOL_tScaleLast = 180,               /* tScaleLast  */
  YYSYMBOL_tHole = 181,                    /* tHole  */
  YYSYMBOL_tAlias = 182,                   /* tAlias  */
  YYSYMBOL_tAliasWithOptions = 183,        /* tAliasWithOptions  */
  YYSYMBOL_tCopyOptions = 184,             /* tCopyOptions  */
  YYSYMBOL_tQuadTriAddVerts = 185,         /* tQuadTriAddVerts  */
  YYSYMBOL_tQuadTriNoNewVerts = 186,       /* tQuadTriNoNewVerts  */
  YYSYMBOL_tRecombLaterals = 187,          /* tRecombLaterals  */
  YYSYMBOL_tTransfQuadTri = 188,           /* tTransfQuadTri  */
  YYSYMBOL_tText2D = 189,                  /* tText2D  */
  YYSYMBOL_tText3D = 190,                  /* tText3D  */
  YYSYMBOL_tInterpolationScheme = 191,     /* tInterpolationScheme  */
  YYSYMBOL_tTime = 192,                    /* tTime  */
  YYSYMBOL_tCombine = 193,                 /* tCombine  */
  YYSYMBOL_tBSpline = 194,                 /* tBSpline  */
  YYSYMBOL_tBezier = 195,                  /* tBezier  */
  YYSYMBOL_tNurbs = 196,                   /* tNurbs  */
  YYSYMBOL_tNurbsOrder = 197,              /* tNurbsOrder  */
  YYSYMBOL_tNurbsKnots = 198,              /* tNurbsKnots  */
  YYSYMBOL_tColor = 199,                   /* tColor  */
  YYSYMBOL_tColorTable = 200,              /* tColorTable  */
  YYSYMBOL_tFor = 201,                     /* tFor  */
  YYSYMBOL_tIn = 202,                      /* tIn  */
  YYSYMBOL_tEndFor = 203,                  /* tEndFor  */
  YYSYMBOL_tIf = 204,                      /* tIf  */
  YYSYMBOL_tElseIf = 205,                  /* tElseIf  */
  YYSYMBOL_tElse = 206,                    /* tElse  */
  YYSYMBOL_tEndIf = 207,                   /* tEndIf  */
  YYSYMBOL_tExit = 208,                    /* tExit  */
  YYSYMBOL_tAbort = 209,                   /* tAbort  */
  YYSYMBOL_tField = 210,                   /* tField  */
  YYSYMBOL_tReturn = 211,                  /* tReturn  */
  YYSYMBOL_tCall = 212,                    /* tCall  */
  YYSYMBOL_tSlide = 213,                   /* tSlide  */
  YYSYMBOL_tMacro = 214,                   /* tMacro  */
  YYSYMBOL_tShow = 215,                    /* tShow  */
  YYSYMBOL_tHide = 216,                    /* tHide  */
  YYSYMBOL_tGetValue = 217,                /* tGetValue  */
  YYSYMBOL_tGetStringValue = 218,          /* tGetStringValue  */
  YYSYMBOL_tGetEnv = 219,                  /* tGetEnv  */
  YYSYMBOL_tGetString = 220,               /* tGetString  */
  YYSYMBOL_tGetNumber = 221,               /* tGetNumber  */
  YYSYMBOL_tUnique = 222,                  /* tUnique  */
  YYSYMBOL_tSetMaxTag = 223,               /* tSetMaxTag  */
  YYSYMBOL_tHomology = 224,                /* tHomology  */
  YYSYMBOL_tCohomology = 225,              /* tCohomology  */
  YYSYMBOL_tBetti = 226,                   /* tBetti  */
  YYSYMBOL_tExists = 227,                  /* tExists  */
  YYSYMBOL_tFileExists = 228,              /* tFileExists  */
  YYSYMBOL_tGetForced = 229,               /* tGetForced  */
  YYSYMBOL_tGetForcedStr = 230,            /* tGetForcedStr  */
  YYSYMBOL_tGMSH_MAJOR_VERSION = 231,      /* tGMSH_MAJOR_VERSION  */
  YYSYMBOL_tGMSH_MINOR_VERSION = 232,      /* tGMSH_MINOR_VERSION  */
  YYSYMBOL_tGMSH_PATCH_VERSION = 233,      /* tGMSH_PATCH_VERSION  */
  YYSYMBOL_tGmshExecutableName = 234,      /* tGmshExecutableName  */
  YYSYMBOL_tSetPartition = 235,            /* tSetPartition  */
  YYSYMBOL_tNameToString = 236,            /* tNameToString  */
  YYSYMBOL_tStringToName = 237,            /* tStringToName  */
  YYSYMBOL_tUnsplitWindow = 238,           /* tUnsplitWindow  */
  YYSYMBOL_tAFFECTPLUS = 239,              /* tAFFECTPLUS  */
  YYSYMBOL_tAFFECTMINUS = 240,             /* tAFFECTMINUS  */
  YYSYMBOL_tAFFECTTIMES = 241,             /* tAFFECTTIMES  */
  YYSYMBOL_tAFFECTDIVIDE = 242,            /* tAFFECTDIVIDE  */
  YYSYMBOL_243_ = 243,                     /* '?'  */
  YYSYMBOL_tOR = 244,                      /* tOR  */
  YYSYMBOL_tAND = 245,                     /* tAND  */
  YYSYMBOL_tEQUAL = 246,                   /* tEQUAL  */
  YYSYMBOL_tNOTEQUAL = 247,                /* tNOTEQUAL  */
  YYSYMBOL_248_ = 248,                     /* '<'  */
  YYSYMBOL_tLESSOREQUAL = 249,             /* tLESSOREQUAL  */
  YYSYMBOL_250_ = 250,                     /* '>'  */
  YYSYMBOL_tGREATEROREQUAL = 251,          /* tGREATEROREQUAL  */
  YYSYMBOL_tLESSLESS = 252,                /* tLESSLESS  */
  YYSYMBOL_tGREATERGREATER = 253,          /* tGREATERGREATER  */
  YYSYMBOL_254_ = 254,                     /* '+'  */
  YYSYMBOL_255_ = 255,                     /* '-'  */
  YYSYMBOL_256_ = 256,                     /* '*'  */
  YYSYMBOL_257_ = 257,                     /* '/'  */
  YYSYMBOL_258_ = 258,                     /* '%'  */
  YYSYMBOL_259_ = 259,                     /* '|'  */
  YYSYMBOL_260_ = 260,                     /* '&'  */
  YYSYMBOL_261_ = 261,                     /* '!'  */
  YYSYMBOL_tPLUSPLUS = 262,                /* tPLUSPLUS  */
  YYSYMBOL_tMINUSMINUS = 263,              /* tMINUSMINUS  */
  YYSYMBOL_UNARYPREC = 264,                /* UNARYPREC  */
  YYSYMBOL_265_ = 265,                     /* '^'  */
  YYSYMBOL_266_ = 266,                     /* '('  */
  YYSYMBOL_267_ = 267,                     /* ')'  */
  YYSYMBOL_268_ = 268,                     /* '['  */
  YYSYMBOL_269_ = 269,                     /* ']'  */
  YYSYMBOL_270_ = 270,                     /* '{'  */
  YYSYMBOL_271_ = 271,                     /* '}'  */
  YYSYMBOL_272_ = 272,                     /* '.'  */
  YYSYMBOL_273_ = 273,                     /* '#'  */
  YYSYMBOL_274_ = 274,                     /* '~'  */
  YYSYMBOL_275_ = 275,                     /* ','  */
  YYSYMBOL_YYACCEPT = 276,                 /* $accept  */
  YYSYMBOL_All = 277,                      /* All  */
  YYSYMBOL_GeoFormatItems = 278,           /* GeoFormatItems  */
  YYSYMBOL_GeoFormatItem = 279,            /* GeoFormatItem  */
  YYSYMBOL_SendToFile = 280,               /* SendToFile  */
  YYSYMBOL_Printf = 281,                   /* Printf  */
  YYSYMBOL_View = 282,                     /* View  */
  YYSYMBOL_Views = 283,                    /* Views  */
  YYSYMBOL_ElementCoords = 284,            /* ElementCoords  */
  YYSYMBOL_ElementValues = 285,            /* ElementValues  */
  YYSYMBOL_Element = 286,                  /* Element  */
  YYSYMBOL_287_1 = 287,                    /* $@1  */
  YYSYMBOL_288_2 = 288,                    /* $@2  */
  YYSYMBOL_Text2DValues = 289,             /* Text2DValues  */
  YYSYMBOL_Text2D = 290,                   /* Text2D  */
  YYSYMBOL_291_3 = 291,                    /* $@3  */
  YYSYMBOL_Text3DValues = 292,             /* Text3DValues  */
  YYSYMBOL_Text3D = 293,                   /* Text3D  */
  YYSYMBOL_294_4 = 294,                    /* $@4  */
  YYSYMBOL_InterpolationMatrix = 295,      /* InterpolationMatrix  */
  YYSYMBOL_Time = 296,                     /* Time  */
  YYSYMBOL_297_5 = 297,                    /* $@5  */
  YYSYMBOL_NumericAffectation = 298,       /* NumericAffectation  */
  YYSYMBOL_NumericIncrement = 299,         /* NumericIncrement  */
  YYSYMBOL_LP = 300,                       /* LP  */
  YYSYMBOL_RP = 301,                       /* RP  */
  YYSYMBOL_tSTRING_Reserved = 302,         /* tSTRING_Reserved  */
  YYSYMBOL_Affectation = 303,              /* Affectation  */
  YYSYMBOL_Comma = 304,                    /* Comma  */
  YYSYMBOL_DefineConstants = 305,          /* DefineConstants  */
  YYSYMBOL_306_6 = 306,                    /* $@6  */
  YYSYMBOL_307_7 = 307,                    /* $@7  */
  YYSYMBOL_308_8 = 308,                    /* $@8  */
  YYSYMBOL_UndefineConstants = 309,        /* UndefineConstants  */
  YYSYMBOL_Enumeration = 310,              /* Enumeration  */
  YYSYMBOL_FloatParameterOptionsOrNone = 311, /* FloatParameterOptionsOrNone  */
  YYSYMBOL_FloatParameterOptionsOrNone_NoComma = 312, /* FloatParameterOptionsOrNone_NoComma  */
  YYSYMBOL_FloatParameterOptions = 313,    /* FloatParameterOptions  */
  YYSYMBOL_FloatParameterOption = 314,     /* FloatParameterOption  */
  YYSYMBOL_CharParameterOptionsOrNone = 315, /* CharParameterOptionsOrNone  */
  YYSYMBOL_CharParameterOptions = 316,     /* CharParameterOptions  */
  YYSYMBOL_CharParameterOption = 317,      /* CharParameterOption  */
  YYSYMBOL_PhysicalId_per_dim_entity = 318, /* PhysicalId_per_dim_entity  */
  YYSYMBOL_SurfaceConstraints = 319,       /* SurfaceConstraints  */
  YYSYMBOL_CircleOptions = 320,            /* CircleOptions  */
  YYSYMBOL_LoopOptions = 321,              /* LoopOptions  */
  YYSYMBOL_Shape = 322,                    /* Shape  */
  YYSYMBOL_323_9 = 323,                    /* $@9  */
  YYSYMBOL_GeoEntity = 324,                /* GeoEntity  */
  YYSYMBOL_GeoEntity123 = 325,             /* GeoEntity123  */
  YYSYMBOL_GeoEntity12 = 326,              /* GeoEntity12  */
  YYSYMBOL_GeoEntity012 = 327,             /* GeoEntity012  */
  YYSYMBOL_Transform = 328,                /* Transform  */
  YYSYMBOL_MultipleShape = 329,            /* MultipleShape  */
  YYSYMBOL_ListOfShapes = 330,             /* ListOfShapes  */
  YYSYMBOL_LevelSet = 331,                 /* LevelSet  */
  YYSYMBOL_Delete = 332,                   /* Delete  */
  YYSYMBOL_Colorify = 333,                 /* Colorify  */
  YYSYMBOL_SetPartition = 334,             /* SetPartition  */
  YYSYMBOL_Visibility = 335,               /* Visibility  */
  YYSYMBOL_Command = 336,                  /* Command  */
  YYSYMBOL_Slide = 337,                    /* Slide  */
  YYSYMBOL_Loop = 338,                     /* Loop  */
  YYSYMBOL_Extrude = 339,                  /* Extrude  */
  YYSYMBOL_340_10 = 340,                   /* $@10  */
  YYSYMBOL_341_11 = 341,                   /* $@11  */
  YYSYMBOL_342_12 = 342,                   /* $@12  */
  YYSYMBOL_343_13 = 343,                   /* $@13  */
  YYSYMBOL_ExtrudeParameters = 344,        /* ExtrudeParameters  */
  YYSYMBOL_ExtrudeParameter = 345,         /* ExtrudeParameter  */
  YYSYMBOL_BooleanOperator = 346,          /* BooleanOperator  */
  YYSYMBOL_BooleanOption = 347,            /* BooleanOption  */
  YYSYMBOL_Boolean = 348,                  /* Boolean  */
  YYSYMBOL_BooleanShape = 349,             /* BooleanShape  */
  YYSYMBOL_TransfiniteType = 350,          /* TransfiniteType  */
  YYSYMBOL_TransfiniteArrangement = 351,   /* TransfiniteArrangement  */
  YYSYMBOL_TransfiniteCorners = 352,       /* TransfiniteCorners  */
  YYSYMBOL_RecombineAngle = 353,           /* RecombineAngle  */
  YYSYMBOL_PeriodicTransform = 354,        /* PeriodicTransform  */
  YYSYMBOL_Constraints = 355,              /* Constraints  */
  YYSYMBOL_Coherence = 356,                /* Coherence  */
  YYSYMBOL_HomologyCommand = 357,          /* HomologyCommand  */
  YYSYMBOL_Homology = 358,                 /* Homology  */
  YYSYMBOL_FExpr = 359,                    /* FExpr  */
  YYSYMBOL_FExpr_Single = 360,             /* FExpr_Single  */
  YYSYMBOL_361_14 = 361,                   /* $@14  */
  YYSYMBOL_GetForced_Default = 362,        /* GetForced_Default  */
  YYSYMBOL_GetForcedStr_Default = 363,     /* GetForcedStr_Default  */
  YYSYMBOL_DefineStruct = 364,             /* DefineStruct  */
  YYSYMBOL_365_15 = 365,                   /* $@15  */
  YYSYMBOL_Struct_FullName = 366,          /* Struct_FullName  */
  YYSYMBOL_Append = 367,                   /* Append  */
  YYSYMBOL_AppendOrNot = 368,              /* AppendOrNot  */
  YYSYMBOL_VExpr = 369,                    /* VExpr  */
  YYSYMBOL_VExpr_Single = 370,             /* VExpr_Single  */
  YYSYMBOL_RecursiveListOfListOfDouble = 371, /* RecursiveListOfListOfDouble  */
  YYSYMBOL_ListOfDouble = 372,             /* ListOfDouble  */
  YYSYMBOL_ListOfDoubleWithBraces = 373,   /* ListOfDoubleWithBraces  */
  YYSYMBOL_ListOfDoubleOrAll = 374,        /* ListOfDoubleOrAll  */
  YYSYMBOL_FExpr_Multi = 375,              /* FExpr_Multi  */
  YYSYMBOL_RecursiveListOfDouble = 376,    /* RecursiveListOfDouble  */
  YYSYMBOL_ColorExpr = 377,                /* ColorExpr  */
  YYSYMBOL_ListOfColor = 378,              /* ListOfColor  */
  YYSYMBOL_RecursiveListOfColor = 379,     /* RecursiveListOfColor  */
  YYSYMBOL_StringExprVar = 380,            /* StringExprVar  */
  YYSYMBOL_StringExpr = 381,               /* StringExpr  */
  YYSYMBOL_382_16 = 382,                   /* $@16  */
  YYSYMBOL_NameStruct_Arg = 383,           /* NameStruct_Arg  */
  YYSYMBOL_Str_BracedRecursiveListOfStringExprVar = 384, /* Str_BracedRecursiveListOfStringExprVar  */
  YYSYMBOL_BracedOrNotRecursiveListOfStringExprVar = 385, /* BracedOrNotRecursiveListOfStringExprVar  */
  YYSYMBOL_BracedRecursiveListOfStringExprVar = 386, /* BracedRecursiveListOfStringExprVar  */
  YYSYMBOL_RecursiveListOfStringExprVar = 387, /* RecursiveListOfStringExprVar  */
  YYSYMBOL_MultiStringExprVar = 388,       /* MultiStringExprVar  */
  YYSYMBOL_StringIndex = 389,              /* StringIndex  */
  YYSYMBOL_String__Index = 390             /* String__Index  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   19079

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  276
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  657
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2367

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   508


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   261,     2,   273,     2,   258,   260,     2,
     266,   267,   256,   254,   275,   255,   272,   257,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     248,     2,   250,   243,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   268,     2,   269,   265,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   270,   259,   271,   274,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   244,   245,
     246,   247,   249,   251,   252,   253,   262,   263,   264
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   275,   275,   276,   281,   283,   287,   288,   289,   290,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   338,   342,   349,   354,
     359,   364,   378,   391,   404,   417,   445,   459,   472,   485,
     504,   509,   510,   511,   512,   513,   514,   518,   520,   525,
     527,   533,   637,   532,   655,   662,   673,   672,   690,   697,
     708,   707,   724,   741,   764,   763,   777,   778,   779,   780,
     781,   785,   786,   792,   792,   794,   794,   799,   800,   801,
     802,   803,   804,   810,   811,   812,   813,   818,   824,   885,
     900,   928,   938,   943,   951,   956,   964,   973,   978,   990,
    1007,  1013,  1022,  1040,  1058,  1067,  1079,  1084,  1092,  1112,
    1135,  1155,  1163,  1180,  1198,  1236,  1257,  1269,  1283,  1283,
    1285,  1287,  1296,  1306,  1305,  1326,  1325,  1343,  1353,  1352,
    1366,  1368,  1376,  1382,  1387,  1414,  1416,  1419,  1421,  1425,
    1426,  1430,  1442,  1446,  1450,  1454,  1467,  1481,  1489,  1502,
    1504,  1508,  1509,  1514,  1522,  1531,  1539,  1553,  1571,  1575,
    1586,  1595,  1598,  1604,  1608,  1620,  1623,  1630,  1633,  1639,
    1662,  1678,  1694,  1711,  1728,  1765,  1809,  1825,  1841,  1873,
    1889,  1906,  1922,  1972,  1990,  2011,  2032,  2038,  2044,  2051,
    2082,  2097,  2119,  2142,  2165,  2188,  2212,  2236,  2260,  2286,
    2303,  2319,  2337,  2355,  2367,  2381,  2380,  2410,  2412,  2414,
    2416,  2418,  2426,  2428,  2430,  2432,  2440,  2442,  2444,  2452,
    2454,  2456,  2458,  2468,  2484,  2500,  2516,  2532,  2548,  2565,
    2591,  2633,  2654,  2675,  2701,  2702,  2707,  2710,  2714,  2731,
    2751,  2771,  2790,  2817,  2836,  2857,  2872,  2888,  2906,  2957,
    2978,  3000,  3023,  3128,  3144,  3179,  3204,  3229,  3241,  3247,
    3262,  3293,  3305,  3314,  3321,  3333,  3353,  3357,  3362,  3366,
    3371,  3378,  3385,  3392,  3404,  3477,  3495,  3520,  3535,  3587,
    3593,  3605,  3637,  3641,  3645,  3650,  3657,  3662,  3672,  3677,
    3683,  3691,  3702,  3710,  3714,  3718,  3722,  3729,  3733,  3737,
    3741,  3745,  3757,  3766,  3825,  3845,  3871,  3887,  3904,  3921,
    3943,  3965,  4000,  4008,  4016,  4022,  4029,  4036,  4056,  4082,
    4094,  4105,  4123,  4141,  4160,  4159,  4184,  4183,  4210,  4209,
    4234,  4233,  4256,  4272,  4289,  4306,  4329,  4357,  4360,  4366,
    4378,  4398,  4402,  4406,  4410,  4414,  4418,  4422,  4426,  4435,
    4448,  4449,  4450,  4451,  4452,  4456,  4457,  4458,  4459,  4460,
    4463,  4487,  4506,  4529,  4532,  4560,  4563,  4580,  4583,  4589,
    4592,  4599,  4602,  4609,  4632,  4651,  4692,  4737,  4777,  4802,
    4809,  4820,  4837,  4854,  4884,  4910,  4936,  4968,  4996,  5022,
    5048,  5074,  5100,  5122,  5134,  5182,  5236,  5251,  5263,  5269,
    5281,  5288,  5303,  5312,  5333,  5334,  5335,  5339,  5345,  5357,
    5375,  5403,  5404,  5405,  5406,  5407,  5408,  5409,  5410,  5411,
    5418,  5419,  5420,  5421,  5422,  5423,  5424,  5425,  5426,  5427,
    5428,  5429,  5430,  5431,  5432,  5433,  5434,  5435,  5436,  5437,
    5438,  5439,  5440,  5441,  5442,  5443,  5444,  5445,  5446,  5447,
    5448,  5449,  5450,  5451,  5452,  5453,  5454,  5455,  5456,  5457,
    5458,  5467,  5468,  5469,  5470,  5471,  5472,  5473,  5474,  5475,
    5476,  5477,  5482,  5481,  5489,  5493,  5498,  5503,  5507,  5512,
    5517,  5521,  5525,  5529,  5533,  5537,  5541,  5547,  5562,  5566,
    5572,  5577,  5596,  5616,  5637,  5641,  5645,  5649,  5653,  5657,
    5661,  5666,  5676,  5686,  5691,  5702,  5711,  5716,  5721,  5749,
    5750,  5756,  5757,  5763,  5762,  5785,  5787,  5792,  5794,  5800,
    5801,  5806,  5810,  5814,  5818,  5822,  5829,  5833,  5837,  5841,
    5848,  5853,  5860,  5865,  5869,  5873,  5877,  5885,  5896,  5900,
    5904,  5915,  5919,  5923,  5937,  5945,  5953,  5960,  5970,  5993,
    5998,  6004,  6009,  6015,  6026,  6032,  6046,  6052,  6064,  6078,
    6091,  6121,  6144,  6164,  6183,  6203,  6220,  6230,  6240,  6250,
    6262,  6266,  6271,  6283,  6287,  6291,  6295,  6313,  6321,  6329,
    6358,  6368,  6384,  6395,  6400,  6404,  6408,  6420,  6424,  6436,
    6453,  6463,  6467,  6482,  6487,  6494,  6498,  6503,  6517,  6531,
    6535,  6539,  6543,  6547,  6555,  6561,  6570,  6574,  6578,  6586,
    6592,  6598,  6602,  6609,  6617,  6624,  6633,  6637,  6641,  6656,
    6670,  6684,  6696,  6712,  6721,  6730,  6740,  6751,  6759,  6767,
    6771,  6789,  6796,  6802,  6808,  6815,  6823,  6822,  6832,  6856,
    6858,  6864,  6869,  6871,  6876,  6881,  6886,  6888,  6892,  6904,
    6918,  6922,  6929,  6937,  6945,  6956,  6958,  6961
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tDOUBLE", "tSTRING",
  "tBIGSTR", "tEND", "tAFFECT", "tDOTS", "tSCOPE", "tPi", "tMPI_Rank",
  "tMPI_Size", "tEuclidian", "tCoordinates", "tTestLevel", "tExp", "tLog",
  "tLog10", "tSqrt", "tSin", "tAsin", "tCos", "tAcos", "tTan", "tRand",
  "tStep", "tAtan", "tAtan2", "tSinh", "tCosh", "tTanh", "tFabs", "tAbs",
  "tFloor", "tCeil", "tRound", "tMin", "tMax", "tFmod", "tModulo",
  "tHypot", "tList", "tLinSpace", "tLogSpace", "tListFromFile",
  "tCatenary", "tPrintf", "tError", "tWarning", "tStr", "tSprintf",
  "tStrCat", "tStrPrefix", "tStrRelative", "tStrReplace", "tAbsolutePath",
  "tDirName", "tStrSub", "tStrLen", "tFind", "tStrFind", "tStrCmp",
  "tStrChoice", "tUpperCase", "tLowerCase", "tLowerCaseIn",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tFixRelativePath", "tCurrentDirectory", "tCurrentFileName",
  "tSyncModel", "tNewModel", "tMass", "tCenterOfMass", "tMatrixOfInertia",
  "tOnelabAction", "tOnelabRun", "tCodeName", "tCpu", "tMemory",
  "tTotalMemory", "tCreateTopology", "tCreateGeometry",
  "tClassifySurfaces", "tRenumberMeshNodes", "tRenumberMeshElements",
  "tCreateMeshEdges", "tCreateMeshFaces", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineStruct",
  "tNameStruct", "tDimNameSpace", "tAppend", "tDefineString", "tSetNumber",
  "tSetTag", "tSetString", "tPoint", "tCircle", "tEllipse", "tCurve",
  "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume", "tBox",
  "tCylinder", "tCone", "tTorus", "tEllipsoid", "tQuadric",
  "tShapeFromFile", "tRectangle", "tDisk", "tWire", "tGeoEntity",
  "tNormal", "tCurvature", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tRecombineMesh", "tAdaptMesh",
  "tTransformMesh", "tRelocateMesh", "tReorientMesh", "tSetFactory",
  "tThruSections", "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled",
  "tTransfinite", "tPhysical", "tCompound", "tPeriodic", "tParent",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tSewing", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tClosest", "tBooleanUnion", "tBooleanIntersection",
  "tBooleanDifference", "tBooleanSection", "tBooleanFragments",
  "tThickSolid", "tRecombine", "tSmoother", "tSplit", "tDelete",
  "tCoherence", "tHealShapes", "tIntersect", "tMeshAlgorithm",
  "tReverseMesh", "tMeshSize", "tMeshSizeFromBoundary", "tLayers",
  "tScaleLast", "tHole", "tAlias", "tAliasWithOptions", "tCopyOptions",
  "tQuadTriAddVerts", "tQuadTriNoNewVerts", "tRecombLaterals",
  "tTransfQuadTri", "tText2D", "tText3D", "tInterpolationScheme", "tTime",
  "tCombine", "tBSpline", "tBezier", "tNurbs", "tNurbsOrder",
  "tNurbsKnots", "tColor", "tColorTable", "tFor", "tIn", "tEndFor", "tIf",
  "tElseIf", "tElse", "tEndIf", "tExit", "tAbort", "tField", "tReturn",
  "tCall", "tSlide", "tMacro", "tShow", "tHide", "tGetValue",
  "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber", "tUnique",
  "tSetMaxTag", "tHomology", "tCohomology", "tBetti", "tExists",
  "tFileExists", "tGetForced", "tGetForcedStr", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameToString", "tStringToName", "tUnsplitWindow",
  "tAFFECTPLUS", "tAFFECTMINUS", "tAFFECTTIMES", "tAFFECTDIVIDE", "'?'",
  "tOR", "tAND", "tEQUAL", "tNOTEQUAL", "'<'", "tLESSOREQUAL", "'>'",
  "tGREATEROREQUAL", "tLESSLESS", "tGREATERGREATER", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'|'", "'&'", "'!'", "tPLUSPLUS", "tMINUSMINUS",
  "UNARYPREC", "'^'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'.'",
  "'#'", "'~'", "','", "$accept", "All", "GeoFormatItems", "GeoFormatItem",
  "SendToFile", "Printf", "View", "Views", "ElementCoords",
  "ElementValues", "Element", "$@1", "$@2", "Text2DValues", "Text2D",
  "$@3", "Text3DValues", "Text3D", "$@4", "InterpolationMatrix", "Time",
  "$@5", "NumericAffectation", "NumericIncrement", "LP", "RP",
  "tSTRING_Reserved", "Affectation", "Comma", "DefineConstants", "$@6",
  "$@7", "$@8", "UndefineConstants", "Enumeration",
  "FloatParameterOptionsOrNone", "FloatParameterOptionsOrNone_NoComma",
  "FloatParameterOptions", "FloatParameterOption",
  "CharParameterOptionsOrNone", "CharParameterOptions",
  "CharParameterOption", "PhysicalId_per_dim_entity", "SurfaceConstraints",
  "CircleOptions", "LoopOptions", "Shape", "$@9", "GeoEntity",
  "GeoEntity123", "GeoEntity12", "GeoEntity012", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "SetPartition", "Visibility", "Command", "Slide", "Loop", "Extrude",
  "$@10", "$@11", "$@12", "$@13", "ExtrudeParameters", "ExtrudeParameter",
  "BooleanOperator", "BooleanOption", "Boolean", "BooleanShape",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "PeriodicTransform", "Constraints", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "$@14",
  "GetForced_Default", "GetForcedStr_Default", "DefineStruct", "$@15",
  "Struct_FullName", "Append", "AppendOrNot", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleWithBraces",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "$@16", "NameStruct_Arg", "Str_BracedRecursiveListOfStringExprVar",
  "BracedOrNotRecursiveListOfStringExprVar",
  "BracedRecursiveListOfStringExprVar", "RecursiveListOfStringExprVar",
  "MultiStringExprVar", "StringIndex", "String__Index", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-2016)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-604)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   14126,    52,    69, 14340, -2016, -2016,  -137,   118,   -33,  -166,
     -79,   -65,    11,   221,   238,   278,   281,   -29,    25,    28,
     104,   391,   402,   433,   445,    75,   200,    32,   351,    33,
     351,   209,   222,   225,    80,   256,   268,    86,   275,   286,
     298,   310,   320,   325,   332,   358,   368,   407,   192,   521,
     548,   703,   747,   477,   489,   515,   683,   510,  7326,   560,
     561,   572,   799,   -67,   775,    33,   -25,    12,   656,   759,
     -94,   643,   -40,   -40,   645,   412,    63,   653,   655, -2016,
   -2016, -2016, -2016, -2016,   665,   448,   835,   846,    29,    53,
     953,   853,   851,   105,  6259,   865,   973,   981,   983,  6259,
     991,   -83,   -73,   737,    15,    88, -2016,   745,   764, -2016,
   -2016, 11464,   998,   797, -2016, 14597,   766, 14660,    36,    38,
      33, -2016, -2016, -2016, 13140,   800,  1011, -2016, -2016, -2016,
   -2016, -2016,   796, -2016, -2016, -2016, -2016, -2016, -2016, -2016,
   -2016, -2016, -2016,   -74, -2016, -2016, -2016, -2016,    59, -2016,
    1082,   838,  5974,   491,   832,  1104, 13140, 14533, 14533, 14533,
   -2016, 13140, -2016, -2016, -2016, -2016, 14533, -2016, 13140, -2016,
   -2016, 13140, -2016, -2016, -2016, -2016, -2016, -2016,   844,   855,
    1119, -2016, -2016, 14722, -2016, -2016, -2016, -2016,   863, 14722,
   13140, 13140, 13140,   900, 13140, 13140, 13140,   910, 13140, 13140,
   13140, 13140, 13140, 13140, 13140, 14533, 13140, 13140, 13140, 13140,
    6259,   929, -2016, -2016, 10484, 10484, -2016, -2016, -2016,   860,
    6259,  7590, 14533, -2016, -2016, -2016, -2016, -2016,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   442,   351,   351,   351,   351,   351,
     930,   351,   351,   932,    33,   379,   379,   379, -2016, -2016,
   -2016,   351,   351,    40,  1006,  1007,  1008,   941,  1105,   159,
     -16,  7590,  1079,    33,    33,   379,   958,   351,   351,   959,
     960,   961, -2016, -2016, -2016, 13140,  7854, 13140, 13140,  8118,
      32,  1026,    41, -2016, -2016,   965, -2016,  6470, -2016, -2016,
   -2016, -2016, -2016,   101, 13140, 10484, 10484,   970,   971,  8382,
    6259,  6259,  6259, -2016, -2016, -2016,   972, -2016,   969,   974,
    8646,   975, 11554,  1237,  7590,   976,    15,   978,   979,   -40,
     -40,   -40, 13140, 13140,   -64, -2016,   326,   -40, 11818,   429,
     116,   977,   985,   987,   989,   990,   992,   993, 10484, 10484,
   13140,  6259,  6259,  6259,   216,    18,  1236,   996, -2016,  1238,
    1255, -2016,   995, -2016,   999,  1000, -2016, -2016,  1001,  6259,
   -2016, 13140,  6534, -2016,  1259,  1002,  1009,  1010,  1014,  1262,
    1268,  1017, 13140,  1018, 13140, 13140,   458, 13140,  1005, -2016,
    1074, 13140, 13140, 13140, -2016,   351, 13140,   791,   126, -2016,
   13140, -2016,   351,   351,   351,  1019,  1020,  1021,   351,   351,
     351,   351,   351,   351,   351, -2016,   351, -2016, -2016, -2016,
   -2016,   351,   351,  1022,  1023,   351,  1024, -2016,  1025,  1285,
    1286,  1047, -2016, -2016,  1289,  1288,  1312,  1311,  1054, 16623,
   14533, -2016, 10484, 13140, -2016, -2016,  7590,  7590, -2016,  1052,
   14722,    33,  1316, -2016, -2016, -2016, -2016, -2016, -2016, 13140,
   13140,   441,  7590,  1318,   341,  1057,   827,  1058,  1323,    72,
    1060, -2016,  1061, 14743, 13140, -2016,  1056,  -105, -2016,    73,
     -91,   -78,  8842, -2016,   -44, -2016,    85,  9106,  4468,  9365,
    -215,  -171,  1231, -2016,    32,  1059, 13140,  1063, 17139, 17164,
   17189, 13140, 17214, 17239, 17264, 13140, 17289, 17314, 17339, 17364,
   17389, 17414, 17439,  1066, 17464, 17489, 17514, 15376,  1328, 13140,
   10484,  6730, -2016,   229,   393, 13140,  1330,  1334,  1075, 13140,
   13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140,
   13140, 13140, 13140, 13140, 13140, 13140, 10484, 13140, 13140, 13140,
   13140, 13140, 13140, 13140, 13140, 10484, 10484,  1076, 13140, 13140,
   14533, 13140, 14533,  7590, 14533, 14533, 14533,  1077,  1078,  1080,
    1081, 13140,    57, -2016, 11908, 13140,  1083,  1084,  1085,   105,
    1087,  7590,  6259,  7590,  1092, 14533, 14533, 10484,    32, 14722,
      32,  1098, 10484,  1098, -2016,  1098, 17539, -2016,   460,  1094,
      64,  1281, -2016,  1344, 13140, 13140, 13140, 13140, 13140, 13140,
   13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140,  8910, 13140,
   13140, 13140, 13140, 13140,    32, 13140, 13140,    71, -2016,   419,
   17564,   503,   565, 13140, 13140, 13140, -2016,  1363,  1365,  1365,
    1107, 13140, 13140, 13140, 13140,    20, 10484, 10484, 16651,  1108,
    1368, -2016,  1111, -2016, -2016,  -205, -2016, -2016,  9624,  9888,
     -40,   -40,   491,   491,  -148, 11818, 11818, 13140, 11519,  -136,
   -2016, 13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140, 13140,
     649,   663, 17589,  1370,  1372,  1375, 13140, 13140,  1378, 13140,
   -2016, -2016, 13140, 11873, -2016, -2016, 10484, 10484, 10484, 13140,
    1381, 17614,  1121, 13140, 10484, 13140, 13140, 13140, -2016, -2016,
   13140, 17639, 13140, 17664, 17689,  1191, 10152, -2016,  1123,  6994,
   17714, 17739, 13140,  1098, -2016, 13140,    32, 13140, 13140,    71,
   16734, 14533, 14533, 14533, 14533, 14533, 14533, 14533, 14533, 14533,
   13140, 14533, 14533, 14533, 14533,    16, 14722, 14533, 14533, 14533,
      32,    32, -2016, -2016, 10484, -2016,  1124, 13276, -2016,  1125,
   13339, 13140, -2016,  1128,   668, 17764,  4848,  1131,   680, 13140,
    1393,  1130,  7590, 17789, 16761, -2016, -2016, -2016, -2016, -2016,
   -2016,  1129,  1395,   196,  1397, -2016, -2016, -2016, 10484,   160,
   13140, -2016, -2016, -2016,    32, 13140, 13140,    71,  1136, -2016,
    1139,   -58,    33,   -25,    33, -2016,  1138, 15405, -2016,    21,
   10484,    32, 13140, 13140,    71,  1400, 10484,  1403, 10484, 13140,
    1404, 14533,    32, 12167,    71, 13140, -2016, 13140,  1407, -2016,
      32,  1408, 14533, 13140,  1148,  1150, -2016, 13140, 10416, 14722,
    1409,  1410,  1418, 17814,  1419,  1420,  1439, 17839,  1441,  1444,
    1446,  1447,  1448,  1449,  1450, -2016,  1451,  1452,  1453, -2016,
   13140, 17864, 10484,  1192, 10484,    58, 15434, -2016, -2016,  1455,
   16707, 16707, 16707, 16707, 16707, 16707, 16707, 16707, 16707, 16707,
   16707, 16707, 10774, 16707, 16707, 16707, 16707,   647,   366, 16707,
   16707, 16707, 11137, 11495, 11849, 12122, 12198,  6730,  1196,  1195,
     115, 10484, 12478, 12738,   366, 12998,   366,  1190,  1193,  1194,
     -21, 10484, 13140, 13140, 13140, 18814, -2016,   366,  1200, 15463,
   15492, 13140, 13140, 13140,  1197, 13140, -2016, -2016, 13140,  1198,
     418,   366,  -156,  1199,   260,   708,  1467, -2016,    71,   366,
    7590,  1204,  7258,  7522,  1184,   534,   554,   554,   713,   713,
     713,   713,   713,   713,   622,   622, 10484,   397, -2016,   397,
     397,  1098,  1098,  1098,  1205, 17889, 16788,   674, 10484, -2016,
    1469,  1208,  1209, 17914, 17939, 17964, 13140,  7590,  1476,  1475,
   11205, 17989, 15521, 18014, 18039, -2016, 13140,   711,   717, 10484,
    1210, -2016, 13403, -2016, 13466, 13530,   -40, 13140, 13140, -2016,
   -2016,  1213,  1214, 11818,  5856,  1337,   511,   -40, 13593, 18064,
   15550, 18089, 18114, 18139, 18164, 18189, 18214, 18239,  1218,  1219,
    1483, 13140,  1485, -2016, 13140, 18264, 15579, -2016, 16815, 13657,
   16842, -2016,   719,   722,   727, 15608, -2016, -2016, -2016,  1382,
     730, 16869, 16896, 13074, 18289,  1487, 18314,  1488,  1489,  1220,
   13140, 13720, 13140, 13140, -2016, -2016, 16707,   397,  1225,   682,
      49,   431,   496,   431,  1232,  1233,  1223,   366,   366,  1226,
   13901,   366,   366,   366,   366, 13140,   366,  1493, -2016,  1228,
    1240,   563,   121,  1250,   735, -2016, -2016, -2016, -2016, 18339,
   13784,  1235,  1303,  1522,  1360, 12264,  1263,  1265,  1527,  7590,
   15637, -2016, 13140,  1531,   202,   108,    71,    31, 14722, 13140,
    1532, -2016,   738,  1490,  1491,  7590, 15666,    44,  1271, 18364,
   16923,   507, 13140, 13140,  1278,  1276,  1282,  1277,  9174, -2016,
   -2016, -2016, -2016, 14533,   188,  1283, 18389, 16950,  1287, -2016,
     279, -2016,   299, 14125, -2016, -2016, -2016,  1284, -2016,  1291,
   15695, 14668, -2016,     7, -2016, -2016, 18814, -2016,   162, 16707,
   13140,   366,   -40,  7590,  7590,  1542,  7590,  7590,  7590,  1547,
    7590,  7590,  7590,  7590,  7590,  7590,  7590,  7590,  7590,  7590,
    2137,  1554, 10484,  6730, -2016, -2016,   491, -2016, -2016, -2016,
   -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016,
   -2016, 13140, -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016,
   -2016, 13140, 13140, 13140, 13140, 13140, -2016, -2016, -2016,   741,
   13140, 13140, -2016, 13140, -2016,  7590, 14533, 14533, -2016,   743,
   15724, 15753, 15782,  1290, -2016, -2016, -2016,  1361, 15811, 15840,
   15869, 13140, 15898, 15927, 13140, 13140, -2016, -2016, -2016,    71,
   -2016,    71, 13140, 13140,  1295, -2016,  7590,   351, -2016, -2016,
   -2016, 13140, 13140,   748,    71,   439,   194, 13140, 13140, -2016,
     366,   749,  7590, 10484, 10484,  1557,  1559,  1560,  3221, -2016,
   -2016,  1562, -2016,  1302, 18814,  1296,  1563, -2016,  1565,  1566,
    2405,  1567,  1568,   751,   110, -2016, 13847, -2016, -2016,  -125,
   14716, 14749, -2016, -2016, 15956,  -192,  1456,  1572, 12523,  1308,
    1574,  1319,    23,    45,   331, -2016,   -95, -2016,   511,  1575,
    1578,  1579,  1580,  1582,  1583,  1585,  1586,  1587,   491,   491,
    7590, 18814, -2016,  2496,  1325,  1492,  1592, -2016,  1593,  1596,
    1494,  1597, -2016, -2016,  1599,  1601,  1602, 13140,  1603,  7590,
    1606,  7590,  7590,  1605, 14782, -2016,  7786,   469,    71, 13140,
   13140,    71,    71, -2016, 10484, -2016, -2016, -2016, -2016, 14533,
   -2016, -2016, 13140, 14533, -2016, -2016, -2016, -2016, 18814, -2016,
    1342,  1341, 14533, -2016, 14533, -2016,    71, 14533,  1336, -2016,
    1343,  1611, -2016,  1349,    33,  1350, 12620, -2016,  2568,  1351,
    7590, -2016,  1352, -2016, 15985, -2016, -2016, 13140,  1616,   470,
   13140,  1637,  1638,    15,  1640,  1376,  1644,  2619, -2016,   366,
     351,   351,  1645, -2016, -2016,  1388,  1389,  1387, -2016,  1652,
   -2016, -2016, -2016, -2016, -2016, -2016,    71,     2,  1149, 13140,
   16977, 18414, 13140,  9433, 13140, 10484,  1390,   754,  1653,   122,
      71, -2016,  1394, 13140,  1654,  1656, 13140,    71, 12783,  1661,
   13140, 10743,   366,  5439, 13140, 13140, 13140,  1402,  1398, -2016,
    1663, 18439,  1666,   107,  1533,  1533,  7590,  1668,  1670,  1671,
    7590,  -107,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
    1680, -2016,  1682,   756,  1421, 16707, 16707, 16707, 16707, 16707,
   16707,   366, 14815, 14848, 14881,  1422,   366,   366, -2016, -2016,
   -2016, -2016,   162,   366,  1561,  1564,  1569, 16014,  1495, -2016,
   18464, 16707,  1424,  -123, 18814, 16707, -2016,  1688,   366, 18814,
   18814, -2016,   494, -2016,    71, -2016, 18489, 17004, -2016,   366,
    1689,   783,   784,  7590,  7590,  7590,  1692,  1694, -2016,   164,
   13140,  7590,  7590,  7590, -2016,  1431,  1432,  1696,  1699,  1700,
   -2016, 13140, 13140, 13140,  1436,  1438,  1440,  1443, -2016,  2983,
    7590, -2016, 13140, -2016,  1703, -2016,  1706, -2016, -2016, 11818,
     334,  6798, -2016,  1445,  1463,  1464,  1466,  1468,  1470,  9692,
    1442,  1471,  1708, -2016, 10484,  1473, -2016, -2016, -2016,  1474,
   13140, 13140, -2016, -2016, 17031,  7590,  1712,  7590,  1716,  1539,
   -2016, 13140, 13140, 13140, -2016,   575,  1733,   869,   642,  1472,
    5375,  1477, 13140,    43,   366,  1478,   366,  1479, -2016, -2016,
   14722, -2016, 13140,  1480, -2016, -2016,  3327, -2016, -2016,  1481,
    1735, -2016,  3457, -2016,  1496,  1741,   231,  3656, -2016,    15,
   -2016,   786, -2016, 13140, -2016, -2016,   164,  2210,  4765, -2016,
    1498, 13140, 13140,  7590,  1497, -2016,   180,   127,  1743, 18514,
    1745,  1467, 18539,  1482,   789, 18564,   792,  1749,  1751, -2016,
   -2016, 14533,  1499,  1762, 18589, -2016, -2016, 14914,  1503, -2016,
   -2016,  6195,  5703, 18814, -2016,  1763,   351,  8118, -2016, -2016,
   -2016, 18814, 18814, 18814, -2016,   162, -2016,  1766, -2016, -2016,
     -40,  1769,  1770,  1771, -2016, -2016, -2016,  1630,   -31,  1681,
    1774, -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016,
    1776,  1512,  1778, -2016, -2016, -2016, -2016, -2016, -2016, -2016,
   13140, 13140, 13140, -2016, -2016, -2016,  1398, -2016,  1515,  1516,
    1521, -2016,  1684, -2016, -2016, -2016, 13140,  1525,  1518, -2016,
   -2016, 13140, 13140,   366,   439, -2016, -2016, -2016, -2016,  1528,
    1529,  1791,  -107,  1794, 13140, -2016,  7590, 18814,  1655,  1657,
     864, 10484, 10484, 13140, -2016, 11205, 16043, 18614,  8050,   491,
     491, 13140, 13140, -2016,   169,  1530, 18639, -2016, -2016, 16072,
     -81, -2016,  1797,  1801,  7590,   -40,   -40,   -40,   -40,   -40,
    7062,  1804, -2016, -2016, -2016,   818, 10484, 13140,  3821,  4549,
    1806,  1807, -2016,  1808, -2016,  7590,  8314,   601, 18664, 13140,
   13140, -2016, -2016, 10842, -2016, 14533, 13140, -2016, 14533, 18814,
   11106, 14722,  1540, -2016, -2016, -2016, -2016,  1549,  1543, 16101,
   13140,  4848, -2016,  4848,  7590, -2016, -2016,    71,    31, 14722,
   13140,  1813, -2016,  1818, -2016,    15, 17058,  7590, 14533,  1820,
     366, -2016,  1552,   366, 13140, 14947, 14980,   820, -2016, 13140,
   13140,  1558, -2016,  1570, -2016,  1560,  1823,  1825,  1566,  1827,
   -2016, -2016,  1828, 13140, -2016, -2016, 13140, 12880,  1829, 13140,
   -2016, -2016,  1571,  4765,   823,  1641,  1830, -2016, -2016,   630,
   -2016, -2016, -2016,  1683,  1832,  1573,  1576,  1577, -2016,  1834,
    7590, -2016, 16707, 16707, 15013, 13140, 13140, 13140,  1581, 16707,
   -2016,  1588, 18689, 17085, -2016, -2016, 10484, 10484, -2016,  1838,
   -2016, 18814,  1842, 13140, 13140,  1584, -2016,   825,   826, 16679,
    4649,  1843,  1589, -2016, -2016, 13140,  1591,  1595, 16130, 17112,
    1844,  7590,  1845,  1590, 13140, -2016, -2016,   828,     5,   155,
     177,   206,   230,  9956,   243, -2016,  1847,   833, 16159, -2016,
   -2016, -2016, -2016, -2016,  1659, -2016, 13140, 13140, -2016, -2016,
   13043, 10220,  4672,  1851,  1852,  1600, 16707,   366, 18814, -2016,
   -2016, -2016, -2016,    43, -2016, 14722, -2016, 16188,  1607,  1608,
    1609,  1856,  1858,  1862,  4837, -2016, -2016, -2016,  1598,  1865,
     834, -2016,  1867,  1870,   337, 18814, 13140, 13140,  1612,  7590,
     836, 18814, 18714, -2016, -2016, -2016, -2016, 18739, 15046, -2016,
   -2016, 16217,  1290,  1341,  7590,   366, -2016, 13140, 14722,    32,
   -2016, -2016, 10484, 10484, 13140,  1871,   842, -2016, -2016, 13140,
   15079, 16246, 15112, 13140,  1518, -2016, -2016, -2016,   848,   849,
   -2016, -2016,  4865,  5092,  7590,   661,   798, 10484, -2016, -2016,
     491,  8578, -2016, -2016, -2016,  1875, -2016,  1632,  7590, -2016,
   16275,  1901, 10484,   -40,   -40,   -40,   -40,   -40, -2016,  1902,
   -2016, 13140, 16304, 16333, 10484, -2016,   856, -2016, -2016, -2016,
   -2016, -2016, -2016, -2016,  1642,  1905,  1643, -2016,  1908,    15,
   -2016, -2016, -2016,  1715, -2016, -2016, -2016, -2016, -2016, 13140,
   15145, 15178,  7590, -2016,  1910, 13140,  1647, -2016, 13140,  1912,
    1648,  1649, -2016, -2016,  5889, -2016,  1658,   866,   867, 16362,
   -2016,  1651, 15211, 13140, -2016, 13140, 16391,  1662, -2016,  1660,
   -2016, -2016,   868,  1664,   -40,  7590,  1916,  1665,   -40,  1917,
     873,  1667, -2016, 13140, -2016,  1919,  1777, 13911,  1669, -2016,
     874,   276,   290,   293,   303,   328, -2016,  5132, -2016, -2016,
     875, -2016,  1922, -2016, -2016, -2016,  1925, -2016,  1685, 18814,
   13140, 13140,   876, -2016, 18814, 15244, -2016, -2016, -2016,  1290,
   14722,  1687, -2016, -2016, -2016, 13140, 13140, 16420, 16449, -2016,
   -2016, 10484,  1926,   -40,   111, -2016, -2016,   -40,   136, -2016,
    1927, -2016, 16478, -2016, 13140, -2016,   511, -2016,  1930, 10484,
   10484, 10484, 10484,  9956, -2016, -2016, -2016,  4848, -2016, 13140,
   18764, 15277,    66, 13140,  1686, -2016, -2016, 15310, 15343, -2016,
   -2016,   881, -2016,   352, -2016,   361, -2016, -2016, -2016,  5635,
     357, 13974, -2016,   884,   886,   887,   889,   367,   892,  1690,
     894, -2016, 13140, -2016,  7590, 16507, -2016, 13140, 13140, -2016,
     -40,   -40, -2016, -2016, -2016,   511,  1931,  1934,  1935,  1936,
   10484,  1939,  1940,  1941,  1693, 18789,   897,  1942, 16536, 16707,
     375,   383,   495, -2016, -2016, -2016, -2016,   916, -2016, -2016,
   -2016, 14533, -2016,  1695, -2016,  1943, -2016, 13140, 13140, -2016,
    1944,   917, -2016,  1697,  7590, -2016, 16565, 16594, -2016,  1945,
   14533, 14533,   919,  1946,  1950, -2016, -2016,   922, -2016,  1952,
   -2016, -2016,  1954, 14533, -2016, -2016, -2016
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   655,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,   208,     0,     0,   209,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
     351,   352,   353,   354,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   311,     0,     0,   319,
     320,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   404,   405,   406,     0,     0,     0,     5,     6,     7,
       8,    10,     0,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   656,     0,   236,     0,     0,     0,     0,     0,     0,
     287,     0,   289,   290,   285,   286,     0,   292,     0,   295,
     236,     0,   297,   298,   299,   300,   120,   130,   655,   519,
     515,    73,    74,     0,   207,   208,   209,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   301,   302,     0,     0,   219,   220,   221,     0,
       0,     0,     0,   461,   462,   464,   465,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   469,   470,
     471,     0,     0,   207,   212,   213,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   466,   467,   468,     0,     0,     0,     0,     0,
       0,     0,     0,   566,   567,     0,   568,   532,   411,   474,
     477,   333,   533,   515,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,   212,   213,     0,   214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   521,     0,     0,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   655,     0,     0,   236,     0,
       0,   400,     0,   403,     0,     0,   216,   217,     0,     0,
     543,     0,     0,   541,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   655,     0,     0,   589,
       0,     0,     0,     0,   282,     0,     0,     0,   515,   284,
       0,   606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   608,     0,   632,   633,   610,
     611,     0,     0,     0,     0,     0,     0,   609,     0,     0,
       0,     0,   312,   313,     0,   236,     0,   236,     0,     0,
       0,   279,     0,     0,   236,   407,     0,     0,    85,     0,
      66,     0,     0,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,   595,   515,
       0,   235,     0,   234,     0,   186,     0,     0,   595,   596,
       0,     0,     0,   645,     0,   646,   596,     0,     0,     0,
     118,   118,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   583,   584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   550,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   414,     0,   413,   544,   415,     0,   534,     0,     0,
     515,     0,   552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,   491,     0,
       0,     0,     0,     0,     0,     0,   334,     0,   367,   367,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,   236,   236,     0,   523,   522,     0,     0,
       0,     0,   236,   236,     0,     0,     0,     0,   330,     0,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   369,     0,     0,     0,     0,     0,     0,
     236,   262,     0,     0,   260,   401,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   378,   281,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,     0,   413,   283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   316,   315,     0,   267,     0,     0,   269,     0,
       0,     0,   236,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    80,    78,    79,    81,
      82,     0,     0,     0,     0,    89,    75,    76,     0,     0,
       0,   278,    40,   274,     0,     0,     0,     0,     0,   230,
       0,     0,     0,     0,     0,   237,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   296,     0,     0,   119,
       0,     0,     0,   517,     0,     0,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   361,     0,     0,     0,   211,
       0,     0,     0,     0,     0,     0,     0,   395,   396,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     515,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,   490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   553,   554,     0,     0,
       0,     0,     0,     0,   509,     0,   412,   535,     0,     0,
       0,     0,   546,     0,   431,   430,   428,   429,   424,   426,
     425,   427,   433,   432,   417,   416,     0,   418,   545,   419,
     422,   420,   421,   423,   516,     0,     0,   494,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,   398,     0,     0,     0,     0,
       0,   397,     0,   236,     0,     0,     0,     0,     0,   525,
     524,     0,     0,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   384,     0,     0,     0,   261,     0,     0,
       0,   255,     0,     0,     0,     0,   394,   412,   542,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,   318,     0,   418,   516,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   636,     0,
       0,     0,   511,     0,     0,   266,   270,   268,   272,     0,
       0,   657,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,   412,     0,     0,     0,    66,     0,
       0,    88,     0,    66,    67,     0,     0,     0,   516,     0,
       0,   494,     0,     0,     0,   205,     0,     0,     0,   652,
      28,    26,    27,     0,     0,     0,     0,     0,   599,    30,
       0,    29,     0,     0,   275,   647,   648,     0,   649,   599,
       0,     0,    83,   121,    84,   131,   518,   520,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   585,   586,   304,   236,   222,     9,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   458,   435,
     445,     0,   447,   448,   449,   450,   451,   582,   452,   453,
     454,     0,     0,     0,     0,     0,   574,   573,   572,     0,
       0,     0,   579,     0,   506,     0,     0,     0,   508,     0,
       0,     0,     0,   135,   489,   549,   548,   215,     0,     0,
       0,     0,     0,     0,     0,     0,   475,   581,   480,     0,
     486,     0,     0,     0,     0,   536,     0,     0,   487,   555,
     551,     0,     0,     0,     0,   479,   478,    73,    74,   501,
       0,     0,     0,     0,     0,     0,     0,   412,   363,   368,
     366,     0,   377,     0,   158,   159,     0,   215,     0,   412,
       0,     0,     0,     0,     0,   256,     0,   271,   273,     0,
       0,     0,   223,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   337,     0,   321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   236,
       0,   370,   383,     0,     0,     0,     0,   257,     0,     0,
       0,     0,   218,   373,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,   622,     0,   629,   618,   619,   620,     0,
     635,   634,     0,     0,   623,   624,   625,   631,   639,   638,
       0,   149,     0,   612,     0,   614,     0,     0,     0,   607,
       0,     0,   265,     0,     0,     0,     0,   356,     0,     0,
       0,   408,     0,   653,     0,   110,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,     0,   604,    51,     0,     0,     0,    64,     0,
      41,    42,    43,    44,    45,    46,     0,   479,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,   138,   139,
       0,     0,     0,     0,   165,   165,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   556,   557,
     558,   559,     0,     0,     0,     0,     0,     0,     0,   565,
       0,     0,     0,   509,   510,     0,   482,     0,     0,   547,
     434,   537,   495,   493,     0,   492,     0,     0,   570,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   376,     0,
       0,     0,     0,     0,   399,     0,     0,     0,    77,     0,
     264,     0,     0,     0,     0,     0,     0,     0,   342,     0,
       0,   341,     0,   344,     0,   346,     0,   331,   338,     0,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,     0,     0,   259,   258,   402,     0,
       0,     0,    37,    38,     0,     0,     0,     0,     0,     0,
     590,     0,     0,     0,   307,   495,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   616,
       0,   380,     0,     0,   236,   357,     0,   358,   236,     0,
       0,   605,     0,    95,     0,     0,     0,     0,    93,     0,
     593,     0,   108,     0,   100,   102,     0,     0,     0,    90,
       0,     0,     0,     0,     0,    36,   495,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,   600,     0,     0,    34,    33,     0,   600,   650,
     291,     0,     0,   122,   127,     0,     0,     0,   141,   147,
     148,   144,   142,   143,   514,     0,    86,     0,    87,   169,
       0,     0,     0,     0,   170,   189,   190,   167,     0,     0,
       0,   171,   200,   191,   195,   196,   192,   193,   194,   179,
       0,     0,     0,   446,   460,   459,   455,   456,   457,   575,
       0,     0,     0,   504,   505,   507,   136,   473,     0,     0,
       0,   560,     0,   503,   476,   481,     0,     0,   509,   201,
     488,    73,    74,     0,   500,   496,   498,   576,   197,     0,
       0,     0,   161,     0,     0,   375,     0,   160,     0,     0,
       0,     0,     0,     0,   280,     0,     0,     0,     0,   236,
     236,     0,     0,   343,   532,     0,     0,   345,   347,     0,
       0,   325,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,   229,   198,     0,     0,     0,     0,     0,
       0,     0,   176,     0,   177,     0,     0,     0,     0,     0,
       0,   111,   115,     0,   630,     0,     0,   628,     0,   640,
       0,     0,   150,   151,   637,   613,   615,     0,     0,     0,
       0,   355,   359,   355,     0,   409,    94,     0,     0,    66,
       0,     0,    92,     0,   591,     0,     0,     0,     0,     0,
       0,   643,   642,     0,     0,     0,     0,     0,   530,     0,
       0,    77,   276,   496,   277,     0,     0,     0,     0,     0,
     241,   238,     0,     0,   603,   601,     0,     0,     0,     0,
     123,   128,     0,     0,     0,   583,   584,   140,   379,   166,
     174,   175,   180,     0,     0,     0,     0,     0,   182,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
     483,     0,     0,     0,   571,   502,     0,     0,   181,     0,
     202,   364,     0,     0,     0,     0,   203,     0,     0,     0,
       0,     0,     0,   529,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   252,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,   381,
     382,    39,   184,   185,     0,   588,     0,     0,   309,   308,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   154,
     157,   156,   155,     0,   617,     0,   654,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   594,     0,     0,
       0,    97,     0,     0,     0,    47,     0,     0,     0,     0,
       0,    49,     0,   242,   239,   240,    35,     0,     0,   651,
     293,     0,   135,   149,     0,     0,   146,     0,     0,     0,
     168,   199,     0,     0,     0,     0,     0,   577,   578,     0,
       0,     0,     0,     0,   509,   484,   497,   499,     0,     0,
     183,   206,     0,     0,     0,   371,   371,     0,   116,   117,
     236,     0,   226,   227,   332,     0,   339,     0,     0,   236,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
     231,     0,     0,     0,     0,   538,     0,   112,   114,   113,
     621,   627,   626,   152,     0,     0,     0,   360,     0,     0,
     109,   101,   103,     0,    91,   644,    98,    99,    52,     0,
       0,     0,     0,   531,     0,     0,   497,   602,     0,     0,
       0,     0,   125,   641,     0,   132,     0,     0,     0,     0,
     188,     0,     0,     0,   563,     0,     0,     0,   335,     0,
     172,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   527,     0,   349,     0,     0,   326,     0,   244,
       0,     0,     0,     0,     0,     0,   232,     0,   587,   310,
       0,   539,     0,   393,   236,   410,     0,   592,     0,    48,
       0,     0,     0,    65,    50,     0,   294,   124,   129,   135,
       0,     0,   163,   164,   162,     0,     0,     0,     0,   564,
     485,     0,     0,     0,     0,   372,   386,     0,     0,   387,
       0,   224,     0,   340,     0,   322,     0,   236,     0,     0,
       0,     0,     0,     0,   178,   540,   306,   355,   107,     0,
       0,     0,     0,     0,     0,   133,   134,     0,     0,   561,
     562,     0,   204,     0,   390,     0,   391,   392,   526,     0,
       0,   328,   247,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,    62,     0,     0,   126,     0,     0,   336,
       0,     0,   348,   327,   323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,   250,   251,     0,   245,   362,
      53,     0,    60,     0,   288,     0,   580,     0,     0,   329,
       0,     0,    54,     0,     0,   303,     0,     0,   246,     0,
       0,     0,     0,     0,     0,    57,    55,     0,    58,     0,
     388,   389,     0,     0,    63,    61,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2016, -2016, -2016, -2016,   505, -2016, -2016, -2016, -2016,  -297,
   -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016, -2016,
   -2016, -2016,  -792,  -150,  5006,  3224,  -439, -2016,  1484, -2016,
   -2016, -2016, -2016, -2016, -2016, -2015, -2016,   447,   255,   -82,
   -2016,   -41, -2016,   191,   490, -2016,  1971, -2016,   769,   -45,
    1392, -2016,    22,  -667,  -140, -2016, -2016, -2016, -2016, -2016,
   -2016, -2016,   850,  1973, -2016, -2016, -2016, -2016, -1316, -1314,
    1975, -1850,  1976, -2016, -2016, -2016,  1333, -2016,  -103, -2016,
   -2016, -2016, -2016,  2377, -2016, -2016, -1525,   347,  1983, -2016,
     -23, -2016, -2016,   -57, -2016, -1805,   543, -2016,   -59,  2965,
    3064,  -333,   119, -2016,  2049,   -49, -2016, -2016,   138,   321,
   -1811,  -143,  1159, -2016,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   127,  1143,   128,   129,  1127,  2034,  2040,
    1440,  1670,  2208,  2341,  1441,  2314,  2357,  1442,  2343,  1443,
    1444,  1674,   472,   638,   639,  1216,  1774,   130,   840,   500,
    2052,  2219,  2053,   501,  1914,  1523,  1477,  1478,  1479,  1634,
    1852,  1853,  1293,  1730,  1721,  1924,   815,   650,   301,   302,
     379,   220,   303,   482,   483,   134,   135,   136,   137,   138,
     139,   140,   141,   304,  1328,  2246,  2305,  1016,  1324,  1325,
     305,  1106,   306,   145,  1557,  1291,   988,  1032,  2176,   146,
     147,   148,   149,   307,   308,  1243,  1264,  1398,   309,   845,
     310,   844,   503,   667,   345,  1887,   383,  2003,   384,   312,
     608,   398,  1424,  1661,   493,   488,  1391,  1086,  1710,  1880,
    1881,  1071,   495,   151,   408
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     152,  1119,   473,   662,   179,  1011,  1012,  1125,  1767,  1977,
    1588,  2018,  1590,  2019,  1471,   344,   346,   160,   349,   396,
     178,   330,   698,   494,   180,   133,   995,  1140,   391,  1583,
     498,   167,   793,   365,   169,   178,   178,  2150,   393,  2011,
     389,   444,  1728,   446,   318,   583,   612,  1850,  1434,   670,
     671,  1585,   589,   318,   838,   313,  1371,   370,     4,   371,
     839,   178,   670,   671,  1195,   455,   439,   350,   443,     5,
    1006,   319,  2293,   504,  1925,   785,   178,   335,   156,  1575,
    1134,   804,   821,   324,   193,   369,   325,   326,   327,   590,
     197,   313,   400,  1926,   832,  1729,   313,   786,   841,   328,
     157,   399,  2055,   478,   839,   336,   670,   671,   787,   788,
     634,  1258,   440,  1719,  1568,  1416,  1259,  2274,   670,   671,
     331,   337,   338,   332,   634,  2066,   366,  1013,  1690,   670,
     671,  1891,   155,   153,   505,   736,   786,   154,   184,  1017,
     507,   185,  2276,   181,   186,   182,   187,   787,   788,   479,
    1571,   528,  1262,   786,   489,   489,   489,    48,   372,   670,
     671,   536,   819,   496,   787,   788,  1473,  1123,   351,   329,
     820,  1416,   352,   670,   671,   481,   825,   614,   353,   354,
    1589,   355,   356,   392,   826,   789,   790,   158,  1474,   827,
     670,   671,   453,   394,  1974,   996,   454,   828,   977,  1475,
    1476,   159,   489,  1118,  2264,   357,   672,   313,   678,  1416,
    1584,   313,   313,   376,   340,   341,   377,   313,   313,   489,
     578,   579,   580,   830,   789,   790,   342,   162,   703,   378,
     343,   831,  1586,  1435,  1436,  1437,  1438,   166,  1869,   367,
     594,   789,   790,  1941,   163,   105,  1238,   106,   107,   108,
     109,   110,   125,   125,   831,   114,   115,  1851,   117,   670,
     671,   647,   648,   649,   467,   468,   125,   587,   125,   125,
     588,  1141,  -598,   181,  1142,   182,  1588,   609,   313,  2172,
    2102,   161,   665,   666,   164,   397,   699,   165,   700,  1085,
     674,   679,   154,   313,   125,   168,   313,   610,   170,   368,
    1069,  1423,   693,   694,   695,   767,   445,   770,   447,   125,
     584,   613,   313,   313,   776,  1439,   313,   313,   313,   313,
     710,  1372,  1417,  1420,   796,   456,   797,   313,  1196,   457,
     181,   313,   182,   399,   467,   468,  2294,  2212,   805,   822,
     806,   823,  -596,   176,   807,   824,   194,   463,   464,   465,
     466,   833,   198,   823,   401,   313,   313,   834,   313,   313,
     313,   670,   671,   467,   468,   670,   671,   635,  1131,   636,
     467,   468,  1141,   637,   171,  1142,   313,   467,   468,   313,
    1419,   635,   681,   636,  1228,  1148,   682,   637,   467,   468,
     670,   671,   737,  1396,   738,  1159,  1397,   172,   739,  1124,
     464,   465,   466,   463,   464,   465,   466,  2289,   173,   670,
     671,   780,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
    2103,   670,   671,   920,   633,   463,   464,   465,   466,   174,
    1970,   463,   464,   465,   466,   785,  1890,   489,  1840,   313,
    -600,   175,  2104,   313,   313,  1459,   467,   468,   467,   468,
     670,   671,   209,   874,   467,   468,  1544,   786,   177,   313,
     463,   464,   465,   466,   785,   190,   808,  1623,   787,   788,
    1317,  2105,   696,  1317,   670,   671,   697,   324,   191,  2316,
     325,   192,   327,   467,   468,   480,   786,   670,   671,  1318,
     873,   846,  1318,   328,   874,  2106,  1317,   787,   788,  1267,
    1319,  1320,  1321,  1319,  1320,  1321,  1322,  1323,  2107,  1322,
    1323,  1002,   195,  1004,  1005,  1318,   181,   313,   182,  1504,
     670,   671,  1261,   936,   196,  1262,  1319,  1320,  1321,  2352,
    1018,   199,  1322,  1323,   670,   671,  1464,   670,   671,  2167,
     943,  2249,   200,   313,   874,   789,   790,   670,   671,   361,
    1039,   362,   313,   910,   201,  2250,  1465,   489,  2251,   489,
     313,   489,   489,   496,   874,   942,   202,   944,  2252,   927,
     670,   671,   670,   671,   789,   790,   203,  1061,   313,   313,
     313,   204,   489,   489,   313,   180,   673,   180,   205,   313,
    1073,   311,  1587,  2253,  2138,  1811,   670,   671,   796,  1997,
     797,   798,  2139,  1009,  1010,   670,   671,   181,   666,   182,
     216,   670,   671,   217,   206,   313,   218,  2300,  2303,   670,
     671,   974,  1100,   796,   207,   797,  2301,   670,   671,   219,
     791,   792,  2310,  1120,  1317,    71,    72,    73,    74,   210,
    2337,    77,    78,   313,   313,   614,   631,   632,  2338,   211,
    1317,    87,   633,  1318,   875,    91,   340,   341,   874,  1654,
    1655,  1600,  1601,   208,  1319,  1320,  1321,  1422,   342,  1318,
    1322,  1323,   348,   670,   671,   796,   796,   797,   797,   978,
    1319,  1320,  1321,  1255,   481,   481,  1322,  1323,   796,   680,
     797,   467,   468,   313,   313,   313,   831,  1088,   565,   212,
     566,   313,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
     725,   947,   154,  1068,   633,   874,  1624,  1092,   496,   489,
     496,   489,   489,   489,   489,   489,   489,   214,   489,   489,
     489,   489,  1087,   213,   489,   489,   489,   180,  1093,   215,
    1771,   313,  1772,   796,   537,   797,  2339,  1786,  1136,   467,
     468,  1374,   132,  1449,   981,  1370,   222,  -599,   874,   313,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,   313,   221,   734,   188,   633,
    1171,  1128,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,  2173,  2174,   313,  1145,   633,
    1532,  2175,  1533,   313,   311,   313,   314,  1279,   496,  1157,
     796,   315,   797,   801,   323,  1542,   982,  1163,  1394,   489,
     874,  1839,   316,  1840,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,   646,  1306,  1870,  1569,   633,   334,  1955,   313,
    1956,   313,  1998,   655,  1877,  1842,  1843,   660,   735,   629,
     630,   631,   632,   320,   670,   671,   321,   633,   322,   448,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   872,   629,   630,   631,   632,   313,   796,
     317,   797,   633,   339,   796,   347,   797,   874,   313,  1279,
    1028,   475,   333,   358,   874,   359,   475,   475,   475,  1625,
    2280,   360,  1626,  1627,  1029,   475,   467,   468,   874,  1102,
    1277,  1295,  1278,   874,   467,   468,   363,   313,  1369,  1309,
    1370,  1108,  2177,  2178,   364,  1109,  1315,  1637,  2175,   373,
    1326,   374,   375,   313,  1418,  1421,  1588,   626,   627,   735,
     629,   630,   631,   632,   475,   313,   385,   386,   633,  1265,
    1656,  1279,  1301,   874,   313,   387,   874,   388,  1302,  2322,
    1349,   475,   874,  1350,   874,   390,   313,   874,  1351,   777,
     778,  1354,   874,   395,   409,   874,  1400,  1676,  1588,  1429,
     874,   402,  1511,   874,  1518,   794,   874,   451,   874,  1541,
    1549,  1692,  1567,   874,   874,  1688,   874,  1741,  1698,   874,
     403,   874,   441,   577,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,   592,   593,  1779,  1780,   633,  1874,   874,   874,
    1897,  1875,   818,  1899,   874,   410,   452,   874,   450,  1426,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,   458,  1986,
    1660,  2038,   633,   874,  2056,  2039,  2085,  2086,  2057,  2101,
     874,   874,   484,  2039,  2109,  2135,   313,  2144,   874,   831,
     485,  2145,   459,  2161,  1425,  1483,   917,  2039,   154,  2168,
    2169,   502,   313,   874,   874,  1543,  1545,  2201,   504,   506,
     535,   874,  1966,  1967,   646,   313,   937,  2222,  2223,  2232,
     489,   874,   874,  2039,  2240,  2248,  2255,  2262,   874,   874,
     874,  2039,  2299,   178,   411,  2306,   874,  2307,  2308,   874,
    2309,   874,   874,  2311,   874,  2313,   511,   874,  2333,  2145,
     313,   313,  2039,   313,   313,   313,   515,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,  2340,  2349,   313,
    2359,   874,  2350,  2362,  2039,   529,   573,  2363,   576,   412,
     413,   414,   415,   416,   417,   418,   419,   420,  -208,  -209,
    -210,   585,   421,   422,   423,   424,   586,   591,   481,   475,
     425,   426,   427,   428,   595,   598,   599,   600,   611,   429,
     781,   430,   313,   489,   489,   454,   643,   644,   651,   652,
     653,   659,   701,   683,   704,   656,   661,   431,   663,   664,
     432,   684,   816,   685,   184,   686,   687,   185,   688,   689,
     186,   705,   187,   313,   702,   706,   713,   816,   718,   707,
     708,   709,   714,    48,   719,   727,   728,   715,   716,   313,
     313,   313,   717,   720,   722,   744,   745,   746,   757,   758,
     760,   762,   763,   761,   461,   765,   766,  1543,  1545,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,   764,   768,   769,
     771,   633,   779,   782,   795,  1113,  1873,   800,   802,   803,
     153,   843,   809,   865,   847,   870,   877,   313,   849,   475,
     878,   475,   879,   475,   475,   475,   911,   921,   922,   950,
     923,   924,   951,   931,   932,   933,   313,   935,   313,   313,
     481,   481,   938,   633,   475,   475,   948,   433,   434,   435,
     986,   313,   987,   990,  1001,  1000,   489,  1031,  1033,   436,
     489,  1003,  1034,   437,  1037,   438,   125,  1046,  1353,   489,
    1059,   489,  1048,  1062,   489,  1095,  1097,  1101,  1107,  1111,
    1112,  1116,  1117,  1121,  1132,  1133,  1149,   313,  1138,  1151,
    1154,   467,   468,  1162,  1164,  1167,  1172,  1173,  1168,  -597,
     399,  1677,  1704,  2181,  1709,  1174,  1176,  1177,  2021,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,   489,  1178,   816,  1180,   633,
     313,  1181,   313,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1198,  1192,  1226,  1227,  1235,  1260,  1251,  1236,  1237,
     313,  1245,   816,  1254,  1266,  1270,  1282,  1274,  1283,  1284,
    1290,  1292,  1304,   313,  1312,  1313,  1316,   313,  1338,  1339,
    1340,  1342,  1363,  1269,  1359,  1361,  1362,  1368,  1379,  1377,
    1378,  1382,  1390,  1392,  1861,  1404,  1871,  1393,  1863,  1403,
     475,   475,   475,   475,   475,   475,   475,   475,   475,  1399,
     475,   475,   475,   475,  1882,  1882,   475,   475,   475,  1405,
    1289,  1406,  1810,  1411,  1409,  1410,   816,  1415,  1428,   816,
    1430,  1431,  2027,  1446,  1452,   816,  1453,  1455,  1454,  1486,
     313,   313,   313,  1463,  1490,  1460,  1467,  1468,   313,   313,
     313,  1502,  1536,  -211,  1553,  1522,  1554,  1555,  1558,  1559,
    1561,  1560,  1562,  1563,  1565,  1566,  1577,   313,  1580,  1576,
    1581,  1135,  1591,  1137,  1592,  1582,  1593,  1594,   313,  1595,
    1596,  1858,  1597,  1598,  1599,  1604,   313,  1605,  1606,  1607,
     475,   313,  1608,  1639,  1610,  1609,  1611,  1612,  1613,  1620,
    1615,   475,   313,  1617,   313,  1632,  1633,  1641,  1640,  1642,
    1644,  1648,  1653,  1650,  1945,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,  1658,  1663,  1659,  1662,   633,  2058,   614,
    1664,  1669,  1412,  1911,  1671,  1672,   399,  1673,  1675,  1689,
    1695,  1687,  1696,  1919,   496,   496,  1693,  1700,  1432,  1716,
     313,  1714,  1718,  1715,  1724,  1720,  1725,  1726,  1731,  1732,
    1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,   489,  1753,
    1758,  1765,  1742,  1759,  1769,  1778,  1784,  1762,  1760,   313,
    1785,  1791,  1792,  1793,   313,  1794,  1799,  1795,  1800,  1807,
    1801,  1802,  1808,  1822,  1824,  1814,  1484,  1485,  1832,  1487,
    1488,  1489,  1834,  1491,  1492,  1493,  1494,  1495,  1496,  1497,
    1498,  1499,  1500,  1815,  1816,  2030,  1817,  1835,  1818,  1841,
    1819,  1865,  1823,  1826,  1827,  1855,  1961,  1845,  1868,  1892,
    1860,  1894,  1848,  1896,  1397,  1900,  1864,  1901,  1978,  1979,
    1980,  1981,  1982,  1984,  1884,  1903,  1904,  1889,  1867,  1907,
    1912,   816,  1918,   816,   816,  1920,  1921,  1922,  1515,  1923,
    1928,  1929,  1930,   313,  1931,  1935,  1936,   816,   313,   313,
    1927,  1937,  1940,  1262,  2004,  1938,  2206,  1948,  1946,  1947,
    1950,  2009,  2012,  1975,  1953,  1971,  1954,  1976,   816,  1537,
    1985,   313,  1991,  1992,  1993,  2013,  2014,   313,  2015,  2025,
    2023,   481,   481,   313,  2026,  1550,  2031,   831,  -603,  2043,
     816,  2044,   313,  2045,  2046,  2050,  2060,  2059,  2061,  2065,
    -601,  2054,   489,  2062,  2080,   489,  2063,  2064,  2081,  2089,
    2096,  2073,  2098,  2108,  2084,  2075,  2111,  2118,  2119,  2090,
    2099,   313,  2092,  2129,  2130,  1425,  2093,  2120,  2131,   816,
    2133,  2134,   399,  2136,   313,   496,  2137,  2160,  2126,  2127,
    2128,  2184,  2142,  1602,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   872,   629,   630,
     631,   632,  1616,  2185,  1618,  1619,   633,  2189,  2196,  2202,
     496,  2203,   475,  2204,  2205,  2207,  2213,  -602,  2216,  2217,
    2218,  2225,  2236,  2239,  2221,  2243,  2244,   313,  2256,  2230,
    2231,  2258,  2272,  2277,  2233,  2237,  2282,  2323,  2241,  2247,
    2324,  2325,  2326,   313,   313,  2328,  2329,  2330,  2334,  2345,
    2348,  2355,  2360,  1649,  2266,  2259,  2361,  2296,  2364,  2187,
    2365,  2312,  2290,  2331,  1691,  2344,  2124,  2351,   313,  1756,
    1917,  2151,  2123,  1949,   131,  1722,   142,  1445,   143,   144,
     313,   934,   989,  2179,  1857,   842,   150,  2022,  2010,  1883,
    1156,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,     0,     0,     0,     0,   475,   475,     0,     0,  2155,
       0,     0,     0,     0,     0,     0,  1708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1723,
       0,     0,     0,  1727,     0,     0,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2191,  2192,  2193,  2194,
    2195,   313,     0,     0,     0,     0,  2156,     0,     0,   313,
     313,     0,     0,     0,  2257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   816,     0,     0,     0,     0,
       0,   313,     0,     0,   313,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   313,  1781,  1782,  1783,   313,
       0,     0,     0,     0,  1788,  1789,  1790,  2281,     0,     0,
       0,   313,   481,     0,     0,     0,     0,  2234,     0,     0,
       0,  2238,     0,  1805,     0,     0,   399,     0,     0,     0,
       0,     0,     0,     0,  1813,     0,     0,     0,     0,   313,
       0,     0,  1821,  1501,     0,     0,     0,     0,   475,     0,
       0,     0,   475,     0,     0,     0,     0,     0,  1831,     0,
    1833,   475,     0,   475,     0,     0,   475,     0,     0,     0,
       0,  2265,   313,  1643,     0,     0,  2273,     0,     0,     0,
    2275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2287,     0,     0,     0,
       0,   477,     0,     0,     0,     0,   487,   490,   491,     0,
       0,     0,     0,     0,   178,   411,  1888,   475,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2320,  2321,  1910,   313,   313,   313,   313,
     313,     0,     0,     0,   523,     0,     0,     0,     0,     0,
     412,   413,   414,   415,   416,   417,   418,   419,   420,     0,
       0,   538,     0,   421,   422,   423,   424,     0,     0,     0,
       0,   425,   426,   427,   428,     0,     0,     0,     0,     0,
     429,   313,   430,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,   431,     0,
       0,   432,     0,     0,     0,   184,     0,     0,   185,     0,
       0,   186,     0,   187,     0,     0,     0,     0,   489,  1952,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,   313,     0,     0,     0,     0,     0,   489,   489,     0,
       0,     0,     0,     0,     0,   461,     0,  1888,     0,     0,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1994,     0,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,  2020,     0,     0,
       0,  1564,     0,     0,     0,     0,     0,     0,     0,     0,
    2029,     0,     0,     0,     0,     0,     0,     0,   433,   434,
     435,     0,     0,     0,     0,     0,   475,   475,     0,     0,
     436,     0,     0,     0,   437,     0,   438,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1888,     0,     0,     0,   796,     0,   797,
    1878,     0,     0,     0,     0,     0,     0,     0,   407,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   773,
       0,   449,  1603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2097,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   476,
       0,     0,     0,   486,     0,     0,     0,     0,   492,     0,
       0,     0,     0,     0,     0,   497,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,   509,   510,
       0,   512,   513,   514,  1647,   516,   517,   518,   519,   520,
     521,   522,  2143,   524,   525,   526,   527,     0,     0,     0,
       0,   531,   531,     0,     0,     0,     0,  2152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   475,     0,     0,   475,     0,   914,
       0,   916,     0,   918,   919,  1665,     0,  1888,     0,     0,
     816,     0,   816,     0,     0,     0,     0,     0,     0,     0,
       0,  2186,     0,     0,   939,   940,     0,   475,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,   601,   603,   605,   606,   531,     0,     0,     0,
       0,     0,   475,     0,     0,  1888,     0,     0,     0,     0,
       0,   640,   531,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   658,
       0,     0,     0,     0,     0,     0,     0,     0,  2235,   668,
     669,     0,     0,     0,     0,   669,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   531,   531,   692,     0,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,   711,   531,
       0,   633,     0,     0,     0,     0,     0,     0,     0,   721,
       0,   723,   724,     0,   726,     0,     0,     0,   729,   730,
     731,     0,     0,   733,     0,     0,     0,   740,     0,     0,
       0,  1072,     0,  1074,  1075,  1076,  1077,  1078,  1079,     0,
    1081,  1082,  1083,  1084,     0,     0,  1089,  1090,  1091,     0,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,   531,
     775,     0,     0,   633,     0,     0,     0,  1888,     0,     0,
       0,     0,     0,     0,     0,     0,   783,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   817,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
    1155,     0,     0,   848,   633,     0,     0,  1888,   853,     0,
       0,  1165,   857,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   871,   603,     0,     0,
       0,     0,   876,     0,     0,     0,   880,   881,   882,   883,
     884,   885,   886,   887,   888,   889,   890,   891,   892,   893,
     894,   895,   896,   897,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   907,     0,   912,   913,     0,   915,     0,
       0,     0,     0,     0,     0,     0,   816,     0,   925,     0,
       0,   929,   930,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   907,     0,     0,     0,     0,   531,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1803,
       0,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   967,   969,   970,   971,   972,
     973,     0,   975,   976,     0,     0,     0,     0,     0,     0,
     983,   984,   985,     0,     0,     0,   816,     0,   991,   992,
     993,   994,     0,   531,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     816,     0,   601,   733,  1014,     0,     0,     0,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,     0,     0,     0,
       0,     0,     0,  1035,  1036,     0,  1038,     0,     0,  1040,
       0,     0,     0,   531,   531,   531,  1045,     0,     0,     0,
    1049,   531,  1051,  1052,  1053,     0,     0,  1054,     0,  1056,
     475,     0,     0,     0,     0,     0,     0,     0,     0,  1066,
       0,     0,  1067,     0,   975,   976,     0,     0,     0,   475,
     475,     0,     0,     0,     0,     0,     0,  1080,     0,     0,
       0,     0,   475,     0,     0,     0,     0,     0,     0,     0,
       0,   531,     0,     0,     0,     0,     0,     0,  1099,     0,
       0,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   531,     0,  1126,     0,   532,
     532,     0,  1129,  1130,     0,     0,     0,     0,     0,     0,
       0,     0,  1458,     0,     0,     0,     0,   531,     0,  1146,
    1147,     0,     0,   531,     0,   531,  1153,     0,     0,     0,
    1146,     0,  1160,     0,  1161,     0,     0,     0,     0,     0,
    1166,     0,     0,     0,  1169,     0,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,  1190,   633,   967,
       0,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,     0,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   533,   534,
     532,   532,     0,     0,     0,  1516,  1517,     0,   531,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   531,  1240,
    1241,  1242,     0,     0,     0,     0,     0,     0,  1248,  1249,
    1250,     0,  1252,     0,     0,  1253,     0,     0,     0,     0,
       0,     0,     0,   532,   532,     0,     0,     0,     0,     0,
       0,     0,     0,  1862,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   531,     0,     0,     0,   532,     0,     0,
       0,     0,     0,     0,     0,   531,     0,     0,     0,     0,
       0,     0,     0,  1288,     0,     0,     0,  1294,     0,     0,
    1556,     0,     0,  1300,     0,     0,   531,     0,     0,   641,
     642,     0,     0,     0,  1310,  1311,     0,     0,     0,     0,
    1314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1341,     0,
       0,  1343,     0,     0,     0,     0,     0,   532,     0,     0,
       0,     0,   690,   691,     0,     0,     0,     0,  1629,     0,
       0,     0,  1631,     0,     0,     0,     0,  1364,     0,  1366,
    1367,  1635,     0,  1636,     0,     0,  1638,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1388,  1866,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,  1408,     0,     0,     0,   633,     0,     0,  1414,
       0,     0,     0,     0,     0,   604,  1427,  1678,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1450,
    1451,     0,     0,     0,     0,   531,   774,     0,     0,     0,
       0,   898,     0,     0,     0,     0,     0,     0,     0,     0,
     908,   909,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1481,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   941,     0,     0,     0,     0,   532,     0,   531,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,  1505,     0,
       0,     0,   633,   968,     0,     0,     0,     0,  1506,  1507,
    1508,  1509,  1510,     0,     0,     0,     0,  1512,  1513,     0,
    1514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   532,   532,     0,     0,     0,     0,     0,  1527,     0,
       0,  1530,  1531,     0,     0,     0,     0,     0,     0,  1534,
    1535,     0,     0,     0,     0,     0,     0,     0,  1539,  1540,
       0,     0,     0,     0,  1546,  1547,     0,     0,     0,     0,
     531,   531,  1872,     0,     0,     0,   945,     0,     0,     0,
       0,   532,   532,   532,     0,     0,     0,     0,     0,   532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1579,     0,     0,   799,     0,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
     997,   998,   633,     0,     0,     0,     0,     0,     0,   532,
       0,     0,     0,     0,  1614,     0,     0,     0,     0,     0,
    1902,     0,     0,     0,     0,     0,  1546,  1547,     0,     0,
       0,   531,     0,     0,     0,     0,     0,     0,     0,  1630,
       0,     0,     0,   532,     0,     0,     0,     0,     0,     0,
    1042,  1043,  1044,     0,     0,     0,     0,     0,  1050,     0,
       0,     0,     0,  1646,     0,   532,     0,     0,     0,     0,
       0,   532,     0,   532,  1652,     0,     0,  1657,     0,     0,
       0,     0,     0,     0,     0,     0,   926,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1679,  1989,  1094,  1682,
     531,  1685,   531,     0,     0,     0,     0,   968,     0,  1194,
    1694,     0,     0,  1697,     0,  1694,     0,  1701,  1703,     0,
       0,  1711,  1712,  1713,     0,     0,     0,     0,     0,     0,
       0,     0,  1122,   979,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,     0,  1144,     0,   532,     0,     0,     0,
    1150,     0,  1152,     0,  2005,     0,     0,  2007,     0,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   532,     0,     0,     0,     0,     0,  1787,     0,     0,
       0,     0,     0,   532,     0,     0,     0,     0,  1796,  1797,
    1798,     0,     0,     0,     0,     0,     0,  1804,     0,  1806,
       0,     0,     0,     0,   532,     0,  1809,     0,     0,     0,
       0,     0,     0,     0,     0,  1229,     0,     0,     0,     0,
       0,   531,     0,     0,     0,  1239,     0,  1828,  1829,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1836,  1837,
    1838,     0,     0,     0,     0,     0,     0,     0,     0,  1849,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1859,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1273,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1876,     0,  1281,     0,     0,     0,     0,     0,  1885,  1886,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1303,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,  1915,     0,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   532,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,     0,  1212,  1213,  1214,
    1215,     0,  1217,  1218,  1219,  1220,     0,  1932,  1933,  1934,
       0,     0,     0,     0,     0,     0,     0,     0,  1232,     0,
    1234,     0,     0,  1939,     0,     0,     0,     0,  1942,  1943,
       0,  1244,     0,     0,     0,     0,     0,   532,     0,     0,
       0,  1951,     0,     0,  1256,  1257,     0,     0,   531,   531,
    1959,     0,  1960,  1268,     0,     0,     0,     0,  1968,  1969,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   531,     0,     0,
       0,     0,  1457,   531,  1988,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1942,  1943,     0,     0,
    2002,     0,     0,  2006,     0,     0,     0,  2008,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2017,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2024,   532,   532,
       0,     0,     0,     0,     0,     0,  1503,     0,     0,     0,
       0,  2035,     0,     0,     0,     0,  2041,  2042,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2047,     0,     0,  2048,  2047,     0,  2051,     0,     0,     0,
       0,     0,     0,     0,     0,  1373,  1375,  1376,     0,     0,
       0,  1380,  1381,     0,     0,  1384,  1385,  1386,  1387,     0,
    1389,     0,  2070,  2071,  2072,  1395,     0,     0,     0,     0,
       0,     0,     0,   531,   531,     0,     0,     0,     0,     0,
    2082,  2083,     0,     0,     0,     0,     0,     0,     0,   532,
       0,     0,  2091,     0,     0,     0,     0,  1551,  1552,     0,
       0,  2100,     0,     0,     0,     0,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2112,  2113,     0,     0,   733,   531,     0,
    2342,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1480,     0,  1482,     0,     0,     0,  2356,
    2358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2366,  2140,  2141,     0,     0,     0,   532,     0,
     532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2154,     0,     0,     0,  1628,   531,
     531,  2159,     0,     0,     0,     0,  2162,     0,     0,     0,
    2166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   531,
       0,     7,     8,     0,     0,     0,     0,     0,  2197,     0,
       0,   531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2209,  1684,     0,  1686,
       0,     0,  2214,     0,     0,  2215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2227,     0,  2228,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1990,     0,     0,     0,     0,
    2242,     0,     0,     0,     0,     0,     0,     0,     0,   532,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,  2260,  2261,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
       0,     0,  2267,  2268,     0,     0,   810,    59,   531,     0,
      62,   811,     0,   812,   813,     0,   814,     0,     0,     0,
       0,  2279,     0,     0,     0,     0,   531,   531,   531,   531,
     531,     0,     0,     0,     0,    84,  2041,     0,     0,     0,
    2295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1666,     0,  2088,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,     0,     0,  1825,  2315,
       0,     0,  1916,     0,  2318,  2319,     0,     0,  2117,     0,
       0,     0,     0,     0,     0,     0,     0,   531,     0,     0,
       0,     0,     0,     0,     0,     0,  1705,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2346,  2347,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1743,
    1744,  1745,  1746,  1747,  1748,  1749,     0,     0,     0,   836,
    1754,  1755,     0,     0,     0,     0,     0,  1757,     0,     0,
       0,     0,     0,     0,     0,  1764,   532,   532,     0,  1768,
       0,     0,  1770,     0,     0,     0,     0,     0,     0,   178,
     411,     0,     0,  1777,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   532,     0,     0,     0,     0,
       0,   532,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,   412,   413,   414,   415,   416,
     417,   418,   419,   420,     0,     0,     0,     0,   421,   422,
     423,   424,     0,     0,     0,     0,   425,   426,   427,   428,
       0,     0,     0,  2132,     0,   429,     0,   430,     0,     0,
       0,     0,  1844,     0,  1847,  1957,  1958,     0,  1854,     0,
    1856,     7,     8,   431,     0,     0,   432,     0,     0,     0,
     184,  2170,     0,   185,     0,     0,   186,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
    1987,  1879,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
     461,   532,   532,     0,   633,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   604,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   532,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,   433,   434,   435,   810,    59,     0,     0,
      62,   811,     0,   812,   813,   436,   814,  1944,     0,   437,
    1104,   438,   125,     0,     0,     0,     0,     0,     0,     0,
    2078,  2079,     0,     0,     0,    84,     0,     0,     0,  1105,
       0,     0,     0,     0,     0,     0,     0,   532,   532,     0,
       0,     0,     0,     0,   183,  1878,   189,     0,     0,     0,
       0,     0,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   532,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2116,     0,   532,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   532,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,  2171,     0,
       0,     0,   633,     0,  2032,     0,     0,  2033,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,  2157,  2158,     0,     0,
     633,     0,     0,     0,     0,     0,     0,     0,  2254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2180,     0,     0,     0,     0,  2067,  2068,   474,     0,
       0,     0,     0,  2074,     0,     0,  2190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   532,   532,   532,   532,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2121,  2122,     0,     0,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     567,   568,   569,   570,   571,   572,     0,   574,   575,     0,
       0,     0,     0,     0,     0,   532,     0,   581,   582,  2153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   596,   597,  2271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2283,  2284,  2285,  2286,  2288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2327,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   732,     0,     0,     0,     0,     0,     0,   741,   742,
     743,     0,     0,     0,   747,   748,   749,   750,   751,   752,
     753,     0,   754,     0,     0,     0,     0,   755,   756,     0,
       0,   759,   223,     6,   411,     0,     0,     0,     0,   224,
     225,   226,     0,     0,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,     0,     0,     0,  1706,
     413,   414,   415,   416,   417,   418,   419,   420,   259,   260,
     261,   262,   421,   422,   423,   424,   263,   264,     0,     0,
     425,   426,   427,   428,     0,     0,   265,   266,   267,   429,
       0,   430,   268,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,    27,   431,   272,     0,
     432,     0,     0,  2336,   273,     0,     0,   274,     0,     0,
     275,     0,   276,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,   277,   278,   279,     0,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,    60,
      61,     0,   282,     0,   283,     0,     0,   284,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    75,     0,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,    87,
       0,     0,     0,    91,     0,     0,   949,     0,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,   285,     0,
     633,  2302,   796,     0,   797,     0,     0,     0,     0,     0,
    1846,     0,     0,     0,     0,     0,   286,   433,   434,   435,
     287,   288,     0,     0,     0,     0,   289,   290,   291,   436,
     292,   293,   294,   437,     0,   438,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,   296,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,   381,   223,     6,   411,  1707,
       0,     0,   300,   224,   225,   226,     0,     0,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
       0,     0,     0,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   259,   260,   261,   262,   421,   422,   423,   424,
     263,   264,     0,     0,   425,   426,   427,   428,     0,     0,
     265,   266,   267,   429,     0,   430,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
      27,   431,   272,     0,   432,     0,     0,     0,   273,     0,
       0,   274,     0,     0,   275,     0,   276,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   277,   278,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,    60,    61,     0,   282,     0,   283,     0,
       0,   284,     0,     0,     0,     0,     0,    71,    72,    73,
      74,    75,     0,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,    87,     0,     0,     0,    91,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,  2220,     0,     0,     0,
     633,     0,   285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   433,   434,   435,   287,   288,     0,     0,     0,     0,
     289,   290,   291,   436,   292,   293,   294,   437,     0,   438,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1263,     0,     0,     0,     0,     0,     0,   295,   296,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   381,
       0,     0,     0,   299,     0,     0,   300,   223,   178,   411,
       0,   460,     0,  1280,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   405,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   259,   260,   261,   262,   421,   422,   423,
     424,   263,     0,     0,     0,   425,   426,   427,   428,     0,
       0,     0,     0,     0,   429,     0,   430,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,   431,   272,     0,   432,     0,     0,     0,   184,
       0,     0,   185,     0,     0,   186,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,   461,
       0,   633,     0,  1047,     0,     0,     0,     0,     0,     0,
       0,  1007,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1472,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   462,     0,     0,     0,     0,     0,
       0,   286,   433,   434,   435,   287,     0,     0,     0,     0,
       0,   289,   290,   291,   436,   292,   293,   294,   437,     0,
     438,   125,     0,   463,   464,   465,   466,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   406,
       0,     0,     0,     0,     0,   297,   467,   468,     0,     0,
     469,     0,   470,     0,     0,     0,   471,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   223,     6,   380,     0,     0,     0,     0,   224,
     225,   226,     0,  1538,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   260,
     261,   262,     0,     0,     0,     0,   263,   264,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   266,   267,     0,
       0,     0,   268,   269,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,    27,     0,   272,     0,
       0,     0,     0,     0,   273,     0,     0,   274,     0,     0,
     275,     0,   276,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,   277,   278,   279,     0,     0,   280,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,    60,
      61,     0,   282,     0,   283,     0,     0,   284,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    75,     0,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,    87,
       0,     0,     0,    91,     0,     0,  1667,  1668,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,   285,     0,
     633,     0,     0,     0,     0,     0,  1908,     0,     0,     0,
    1909,     0,     0,     0,     0,     0,   286,     0,   614,     0,
     287,   288,     0,     0,     0,     0,   289,   290,   291,     0,
     292,   293,   294,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,   296,     0,     0,     0,     0,     0,
     297,     0,     0,     0,     0,   381,     0,     0,     0,   382,
       0,     0,   300,     0,     0,     0,     0,   223,     6,  1766,
       0,     0,   712,     0,   224,   225,   226,     0,  1773,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,   276,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   277,   278,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,    60,    61,     0,   282,     0,   283,
       0,     0,   284,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    87,     0,     0,     0,    91,     0,
       0,     0,  1913,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,     0,     0,   285,     0,   633,     0,     0,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,   288,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   530,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     381,   223,     6,  1812,     0,   607,     0,   300,   224,   225,
     226,     0,     0,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,     0,     0,
       0,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,    27,     0,   272,     0,     0,
       0,     0,     0,   273,     0,     0,   274,     0,     0,   275,
       0,   276,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   277,   278,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,   281,     0,    60,    61,
       0,   282,     0,   283,     0,     0,   284,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,     0,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,    87,     0,
       0,     0,    91,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   872,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,   285,     0,     0,
       0,     0,  1063,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,     0,     0,     0,   287,
     288,     0,     0,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   296,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,   381,   223,     6,     0,   299,     0,
       0,   300,   224,   225,   226,     0,     0,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   260,   261,   262,     0,     0,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,     0,     0,     0,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    27,
       0,   272,     0,     0,     0,     0,     0,   273,     0,     0,
     274,     0,     0,   275,     0,   276,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   277,   278,   279,     0,
       0,   280,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,    60,    61,     0,   282,     0,   283,     0,     0,
     284,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,    87,     0,     0,     0,    91,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   285,     0,     0,     0,     0,  1271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,   287,   288,     0,     0,     0,     0,   289,
     290,   291,     0,   292,   293,   294,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   675,  1983,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,   677,   223,
       6,     0,   343,   607,     0,   300,   224,   225,   226,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,   262,     0,
       0,     0,     0,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,     0,     0,     0,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,    27,     0,   272,     0,     0,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,   276,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     277,   278,   279,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,    60,    61,     0,   282,
       0,   283,     0,     0,   284,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,     0,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,    87,     0,     0,     0,
      91,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,   285,     0,     0,     0,     0,
    1272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,   287,   288,     0,
       0,     0,     0,   289,   290,   291,     0,   292,   293,   294,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   296,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   298,   223,     6,     0,   299,     0,     0,   300,
     224,   225,   226,     0,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,     0,     0,     0,     0,   273,     0,     0,   274,     0,
       0,   275,     0,   276,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   277,   278,   279,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
      60,    61,     0,   282,     0,   283,     0,     0,   284,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,     0,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
      87,     0,     0,     0,    91,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,   285,
       0,     0,     0,     0,  1622,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   288,     0,     0,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   296,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   381,   223,     6,     0,
     299,     0,     0,   300,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,   276,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   277,   278,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,    60,    61,     0,   282,     0,   283,
       0,     0,   284,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    87,     0,     0,     0,    91,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,   285,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,   288,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   530,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     381,   223,     6,     0,   602,     0,     0,   300,   224,   225,
     226,     0,     0,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,     0,     0,
       0,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,    27,     0,   272,     0,     0,
       0,     0,     0,   273,     0,     0,   274,     0,     0,   275,
       0,   276,     0,     0,     0,     0,     0,     0,    44,     0,
       0,     0,   277,   278,   279,     0,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,   281,     0,    60,    61,
       0,   282,     0,   283,     0,     0,   284,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,     0,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,    87,     0,
       0,     0,    91,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,   285,     0,     0,
       0,  1964,     0,     0,     0,  1965,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,     0,     0,     0,   287,
     288,     0,     0,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   530,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,   381,   223,     6,     0,     0,   607,
       0,   300,   224,   225,   226,     0,     0,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   260,   261,   262,     0,     0,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,     0,     0,     0,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    27,
       0,   272,     0,     0,     0,     0,     0,   273,     0,     0,
     274,     0,     0,   275,     0,   276,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   277,   278,   279,     0,
       0,   280,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,    60,    61,     0,   282,     0,   283,     0,     0,
     284,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,    87,     0,     0,     0,    91,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   285,     0,     0,     0,  1995,     0,     0,     0,  1996,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,   287,   288,     0,     0,     0,     0,   289,
     290,   291,     0,   292,   293,   294,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,   296,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,   645,   223,
       6,     0,   299,     0,     0,   300,   224,   225,   226,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,   262,     0,
       0,     0,     0,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,     0,     0,     0,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,    27,     0,   272,     0,     0,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,   276,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     277,   278,   279,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,    60,    61,     0,   282,
       0,   283,     0,     0,   284,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,     0,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,    87,     0,     0,     0,
      91,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,   285,     0,     0,     0,  2182,
       0,     0,     0,  2183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,   287,   288,     0,
       0,     0,     0,   289,   290,   291,     0,   292,   293,   294,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   296,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   654,   223,     6,     0,   299,     0,     0,   300,
     224,   225,   226,     0,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,     0,     0,     0,     0,   273,     0,     0,   274,     0,
       0,   275,     0,   276,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   277,   278,   279,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
      60,    61,     0,   282,     0,   283,     0,     0,   284,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,     0,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
      87,     0,     0,     0,    91,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,   285,
       0,     0,     0,     0,     0,     0,     0,   829,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   288,     0,     0,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   530,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   381,   223,     6,     0,
     966,     0,  1456,   300,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,   276,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   277,   278,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,    60,    61,     0,   282,     0,   283,
       0,     0,   284,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    87,     0,     0,     0,    91,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,   285,     0,     0,     0,     0,     0,     0,
       0,   835,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,   288,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   530,
       0,     0,     0,     0,     0,   297,   223,     6,     0,     0,
     381,  1683,     0,   224,   225,   226,     0,   300,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,   262,     0,     0,     0,     0,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   266,   267,     0,     0,     0,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
      27,     0,   272,     0,     0,     0,     0,     0,   273,     0,
       0,   274,     0,     0,   275,     0,   276,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,   277,   278,   279,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,    60,    61,     0,   282,     0,   283,     0,
       0,   284,     0,     0,     0,     0,     0,    71,    72,    73,
      74,    75,     0,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,    87,     0,     0,     0,    91,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,   285,     0,     0,     0,     0,     0,     0,     0,
     837,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,     0,     0,     0,   287,   288,     0,     0,     0,     0,
     289,   290,   291,     0,   292,   293,   294,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   530,     0,
       0,     0,     0,     0,   297,   223,     6,     0,     0,   381,
       0,     0,   224,   225,   226,     0,   300,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   260,   261,   262,     0,     0,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,     0,     0,     0,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    27,
       0,   272,     0,     0,     0,     0,     0,   273,     0,     0,
     274,     0,     0,   275,     0,   276,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,   277,   278,   279,     0,
       0,   280,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,    60,    61,     0,   282,     0,   283,     0,     0,
     284,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,    87,     0,     0,     0,    91,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   285,     0,     0,     0,     0,     0,     0,     0,  1007,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,   287,   288,     0,     0,     0,     0,   289,
     290,   291,     0,   292,   293,   294,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,   296,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,   381,   223,
       6,     0,  1820,     0,     0,   300,   224,   225,   226,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,   262,     0,
       0,     0,     0,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,     0,     0,     0,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,    27,     0,   272,     0,     0,     0,     0,
       0,   273,     0,     0,   274,     0,     0,   275,     0,   276,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
     277,   278,   279,     0,     0,   280,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,    60,    61,     0,   282,
       0,   283,     0,     0,   284,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,     0,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,    87,     0,     0,     0,
      91,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,   285,     0,     0,     0,     0,
       0,     0,     0,  1008,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,   287,   288,     0,
       0,     0,     0,   289,   290,   291,     0,   292,   293,   294,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     675,  1983,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   677,   223,     6,     0,   343,     0,     0,   300,
     224,   225,   226,     0,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,     0,     0,     0,     0,   273,     0,     0,   274,     0,
       0,   275,     0,   276,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,   277,   278,   279,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
      60,    61,     0,   282,     0,   283,     0,     0,   284,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,     0,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
      87,     0,     0,     0,    91,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,   285,
       0,     0,     0,     0,     0,     0,     0,  1060,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   288,     0,     0,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   530,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,   381,   223,     6,     0,
       0,  2115,     0,   300,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,     0,     0,     0,     0,   273,
       0,     0,   274,     0,     0,   275,     0,   276,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,   277,   278,
     279,     0,     0,   280,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,    60,    61,     0,   282,     0,   283,
       0,     0,   284,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    87,     0,     0,     0,    91,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,   285,     0,     0,     0,     0,     0,     0,
       0,  1170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,   288,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   530,
       0,     0,     0,     0,     0,   297,   223,   178,   411,     0,
     381,     0,     0,   224,   225,   226,     0,   300,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   405,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   259,   260,   261,   262,   421,   422,   423,   424,
     263,     0,     0,     0,   425,   426,   427,   428,     0,     0,
       0,     0,     0,   429,     0,   430,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
      27,   431,   272,     0,   432,   223,   178,   411,     0,     0,
       0,     0,   224,   225,   226,     0,     0,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   405,   246,   247,   248,   249,
     250,   251,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   259,   260,   261,   262,   421,   422,   423,   424,   263,
       0,     0,     0,   425,   426,   427,   428,     0,     0,     0,
       0,     0,   429,     0,   430,   268,   269,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,    27,
     431,   272,     0,   432,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   433,   434,   435,   287,     0,     0,     0,     0,     0,
     289,   290,   291,   436,   292,   293,   294,   437,     0,   438,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   406,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   381,
       0,     0,     0,  1702,     0,     0,   300,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
     433,   434,   435,   287,     0,     0,     0,     0,     0,   289,
     290,   291,   436,   292,   293,   294,   437,     0,   438,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,  2000,     0,     0,
       0,     0,     0,   297,     0,     0,     0,     0,   381,   223,
     178,   411,  2001,     0,     0,   300,   224,   225,   226,     0,
       0,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   405,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,     0,  1706,   413,   414,   415,
     416,   417,   418,   419,   420,   259,   260,   261,   262,   421,
     422,   423,   424,   263,     0,     0,     0,   425,   426,   427,
     428,     0,     0,     0,     0,     0,   429,     0,   430,   268,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,    27,   431,   272,     0,   432,   223,   178,
     411,     0,     0,     0,     0,   224,   225,   226,     0,     0,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   405,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   259,   260,   261,   262,   421,   422,
     423,   424,   263,     0,     0,     0,   425,   426,   427,   428,
       0,     0,     0,     0,     0,   429,     0,   430,   268,   269,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,    27,   431,   272,     0,   432,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   433,   434,   435,   287,     0,     0,
       0,     0,     0,   289,   290,   291,   436,   292,   293,   294,
     437,     0,   438,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   406,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,   381,     0,     0,     0,  1878,     0,     0,   300,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   433,   434,   435,   287,     0,     0,     0,
       0,     0,   289,   290,   291,   436,   292,   293,   294,   437,
       0,   438,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
     406,     0,     0,     0,     0,     0,   297,   223,   178,     0,
     404,   381,     0,     0,   224,   225,   226,     0,   300,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   405,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,   223,   178,     0,
     271,    27,     0,   272,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   405,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   268,   269,   270,
      45,    46,    47,    48,     0,     0,     0,     0,    50,     0,
     271,    27,     0,   272,     0,     0,     0,   810,    59,     0,
       0,    62,   811,     0,   812,   813,     0,   814,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,    84,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,     0,   295,   406,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     381,     0,     0,     0,     0,     0,     0,   300,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1222,   286,     0,     0,     0,   287,     0,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
    1015,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   406,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
     381,   223,   178,     0,   657,     0,     0,   300,   224,   225,
     226,     0,     0,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   405,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,   263,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   269,   270,     0,     0,     0,     0,     0,     0,
       0,   223,   178,     0,   271,    27,   928,   272,   224,   225,
     226,     0,     0,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   405,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,   263,     0,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   268,   269,   270,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,   271,    27,     0,   272,     0,     0,
       0,   810,    59,     0,     0,    62,   811,     0,   812,   813,
       0,   814,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,     0,     0,     0,   287,
      84,     0,     0,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,     0,   675,   676,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,   677,     0,     0,     0,   343,     0,
       0,   300,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1223,   286,     0,     0,     0,   287,
       0,     0,     0,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,  1041,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   406,     0,     0,     0,     0,     0,   297,
     223,   178,     0,     0,   381,     0,     0,   224,   225,   226,
       0,   300,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     405,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,   260,   261,   262,
       0,     0,     0,     0,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,   269,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,    27,     0,   272,   223,   178,     0,
    1407,     0,     0,     0,   224,   225,   226,     0,     0,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   405,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,     0,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   269,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,    27,     0,   272,     0,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,   286,     0,     0,   633,   287,     0,
       0,     0,     0,     0,   289,   290,   291,  1224,   292,   293,
     294,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,   406,     0,     0,     0,     0,     0,   297,     0,
       0,     0,     0,   381,  1158,     0,     0,     0,     0,     0,
     300,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1225,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,   287,     0,     0,     0,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,   406,
       0,     0,     0,     0,     0,   297,   223,   178,     0,  1578,
     381,     0,     0,   224,   225,   226,     0,   300,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   405,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,   262,     0,     0,     0,     0,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   269,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
      27,     0,   272,   223,   178,     0,  1645,     0,     0,     0,
     224,   225,   226,     0,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   405,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
     286,     0,     0,   633,   287,     0,     0,     0,     0,     0,
     289,   290,   291,  1230,   292,   293,   294,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   406,     0,
       0,     0,     0,     0,   297,     0,   223,   178,     0,   381,
       0,     0,     0,   224,   225,   226,   300,     0,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   405,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   259,   260,   261,   262,     0,   289,   290,   291,
     263,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   269,   270,     0,
       0,     0,     0,     0,   295,   406,     0,     0,     0,   271,
      27,   297,   272,   223,   178,     0,   381,     0,     0,     0,
     224,   225,   226,   300,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   405,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
     286,     0,     0,   633,   287,     0,     0,     0,     0,     0,
     289,   290,   291,  1231,   292,   293,   294,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   406,     0,
       0,     0,     0,     0,   297,     0,   223,   178,     0,   381,
    1699,     0,     0,   224,   225,   226,   300,     0,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   405,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,     0,     0,
       0,   287,   259,   260,   261,   262,     0,   289,   290,   291,
     263,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   269,   270,     0,
       0,     0,     0,     0,   295,   406,     0,     0,     0,   271,
      27,   297,   272,   223,   178,     0,   381,  2049,     0,     0,
     224,   225,   226,   300,     0,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   405,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,    27,     0,   272,
       0,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
     286,     0,     0,   633,   287,     0,     0,     0,     0,     0,
     289,   290,   291,  1233,   292,   293,   294,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,   295,   406,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,   381,
       0,     0,     0,  2114,     0,     0,   300,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1357,
       0,     0,     7,     8,     0,     0,     0,   286,     0,     0,
       0,   287,     0,     0,     0,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,   125,     0,     0,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   295,   406,     0,    45,    46,    47,
      48,   297,     0,     0,     0,    50,   381,     0,     0,     0,
       0,     0,     0,   300,   810,    59,     7,     8,    62,   811,
       0,   812,   813,     0,   814,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
      45,    46,    47,    48,     0,     0,     0,     0,    50,     0,
     101,   102,   103,     0,     0,     0,     0,   810,    59,     7,
       8,    62,   811,     0,   812,   813,     0,   814,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,   101,   102,   103,     0,     0,     0,     0,
       0,   810,    59,     7,     8,    62,   811,  1096,   812,   813,
       0,   814,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,     0,     0,    45,    46,    47,
      48,     0,     0,     0,     0,    50,     0,   101,   102,   103,
       0,     0,     0,     0,   810,    59,     7,     8,    62,   811,
    1098,   812,   813,     0,   814,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
     101,   102,   103,     0,     0,     0,     0,     0,   810,    59,
       7,     8,    62,   811,  1305,   812,   813,     0,   814,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,   101,   102,   103,     0,     0,     0,
       0,   810,    59,     7,     8,    62,   811,  1307,   812,   813,
       0,   814,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,    45,    46,
      47,    48,     0,     0,     0,     0,    50,   101,   102,   103,
       0,     0,     0,     0,     0,   810,    59,     7,     8,    62,
     811,  1308,   812,   813,     0,   814,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,     0,    50,
       0,   101,   102,   103,     0,     0,     0,     0,   810,    59,
       7,     8,    62,   811,  1327,   812,   813,     0,   814,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,   101,   102,   103,     0,     0,     0,
       0,     0,   810,    59,     7,     8,    62,   811,  1347,   812,
     813,     0,   814,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,     0,    45,    46,
      47,    48,     0,     0,     0,     0,    50,     0,   101,   102,
     103,     0,     0,     0,     0,   810,    59,     7,     8,    62,
     811,  1365,   812,   813,     0,   814,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
       0,     0,    45,    46,    47,    48,     0,     0,     0,     0,
      50,   101,   102,   103,     0,     0,     0,     0,     0,   810,
      59,     0,     0,    62,   811,  1402,   812,   813,     0,   814,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     0,    45,    46,    47,    48,     0,
       0,     0,     0,    50,     0,   101,   102,   103,     0,     0,
       0,     0,   810,    59,     0,     0,    62,   811,  1570,   812,
     813,     0,   814,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,    84,     0,     0,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,   101,   102,
     103,     0,     0,    -4,    -4,    -4,  1383,     0,     0,     0,
       0,     0,  2245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,    -4,     0,     0,     0,
       0,    -4,    -4,     0,     0,     0,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,  2304,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     6,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,     0,     0,     0,     0,     0,
       0,    -4,     0,    -4,    -4,     0,     0,     0,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     9,    10,    11,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1466,     0,     0,     0,     0,     0,     0,     0,    12,    13,
      14,     0,     0,     0,     0,    15,    16,     0,     0,     0,
       0,    17,     0,     0,     0,     0,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,     0,    27,     0,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,     0,
      44,    45,    46,    47,    48,     0,     0,    49,     0,    50,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
      68,    69,    70,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    96,    97,    98,     0,     0,     0,    99,     0,
       0,     0,     0,   100,   101,   102,   103,   178,   411,   104,
       0,   105,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,   120,   121,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,   125,   126,     0,
       0,     0,     0,   412,   413,   414,   415,   416,   417,   418,
     419,   420,     0,     0,     0,     0,   421,   422,   423,   424,
       0,   178,   411,     0,   425,   426,   427,   428,     0,     0,
       0,     0,     0,   429,     0,   430,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,     0,     0,   432,     0,     0,     0,   184,     0,
       0,   185,     0,     0,   186,     0,   187,   412,   413,   414,
     415,   416,   417,   418,   419,   420,     0,    48,     0,     0,
     421,   422,   423,   424,   442,   411,     0,     0,   425,   426,
     427,   428,     0,     0,     0,     0,     0,   429,   461,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,     0,   432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     412,   413,   414,   415,   416,   417,   418,   419,   420,     0,
       0,     0,     0,   421,   422,   423,   424,   411,     0,     0,
       0,   425,   426,   427,   428,     0,     0,     0,     0,     0,
     429,     0,   430,     0,     0,     0,     0,     0,     0,     0,
       0,   433,   434,   435,     0,     0,     7,     8,   431,     0,
       0,   432,     0,   436,     0,     0,     0,   437,     0,   438,
     125,     0,   412,   413,   414,   415,   416,   417,   418,   419,
     420,     0,     0,     0,     0,   421,   422,   423,   424,     0,
       0,     0,     0,   425,   426,   427,   428,     0,     0,     0,
       0,     0,   429,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,   434,   435,     0,     0,
     431,     0,     0,   432,     0,     0,     0,   436,     0,     0,
       0,   437,     0,   438,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,   433,   434,
     435,   810,    59,     0,     0,    62,   811,     0,   812,   813,
     436,   814,     0,     0,   437,     0,   438,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,   101,   102,   103,
     433,   434,   435,  1470,     0,     0,     0,     0,     0,     0,
       0,     0,   436,     0,     0,     0,   437,     0,   438,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1572,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1573,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1621,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1750,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1751,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1752,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1906,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2036,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2037,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2069,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2148,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2163,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2165,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2210,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2211,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2226,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2263,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2292,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2297,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2298,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,   869,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  1139,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  1197,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,  1246,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,  1247,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,  1297,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,  1330,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
    1345,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,  1352,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,  1413,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  1433,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  1469,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  1519,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,  1520,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,  1521,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,  1524,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,  1525,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
    1526,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,  1528,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,  1529,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  1574,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  1651,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  1761,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,  1962,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,  1973,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,  2016,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,  2094,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
    2110,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,  2125,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,  2149,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  2164,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  2188,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  2198,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,     0,  2199,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,  2224,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,     0,  2229,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,     0,
       0,  2269,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
    2270,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,  2278,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,     0,     0,  2317,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,     0,     0,  2335,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,     0,     0,  2353,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,     0,     0,  2354,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,     0,   772,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
       0,   999,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,     0,  2087,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,   796,     0,   797,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,  1070,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
    1115,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,  1276,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,  1346,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,  1348,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,     0,     0,  1355,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   735,   629,   630,   631,   632,     0,     0,     0,
       0,   633,     0,     0,     0,  1356,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   735,
     629,   630,   631,   632,     0,     0,     0,     0,   633,     0,
       0,     0,  1448,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   735,   629,   630,   631,
     632,     0,     0,     0,     0,   633,     0,     0,     0,  1462,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   735,   629,   630,   631,   632,     0,     0,
       0,     0,   633,     0,     0,     0,  1680,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,     0,     0,  1776,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   735,   629,   630,
     631,   632,     0,     0,     0,     0,   633,     0,     0,     0,
    1830,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   735,   629,   630,   631,   632,     0,
       0,     0,     0,   633,     0,     0,     0,  2028,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   735,   629,   630,   631,   632,     0,     0,     0,     0,
     633,     0,     0,     0,  2077,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   735,   629,
     630,   631,   632,     0,     0,     0,     0,   633,     0,     0,
       0,  2095,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   850,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   851,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   852,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   854,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   855,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   856,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   858,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   859,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   860,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   861,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   862,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   863,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   864,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   866,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   867,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   868,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,   946,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,   980,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1030,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1047,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1055,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1057,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1058,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1064,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1065,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1103,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1114,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1175,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1179,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1191,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1275,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1285,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1286,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1287,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1296,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1298,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1299,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1329,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1331,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1332,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1333,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1334,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1335,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1336,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1337,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1344,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1358,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1360,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1401,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1447,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1461,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1681,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1717,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1763,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1775,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1893,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1895,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1898,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1905,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1963,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  1972,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  1999,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  2076,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  2146,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  2147,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633,
       0,  2291,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   735,   629,   630,   631,   632,
       0,     0,     0,     0,   633,     0,  2332,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     735,   629,   630,   631,   632,     0,     0,     0,     0,   633
};

static const yytype_int16 yycheck[] =
{
       3,   793,   152,   336,    27,   672,   673,   799,  1533,  1814,
    1324,  1861,  1328,  1863,     7,    72,    73,     6,    75,     4,
       4,    66,     4,   166,    27,     3,     6,     6,   111,     6,
     170,     6,   471,     4,     6,     4,     4,  2052,   111,  1850,
      99,     5,   149,     5,   111,     5,     5,     4,     4,   254,
     255,     6,    68,   111,   269,    58,     7,     4,     6,     6,
     275,     4,   254,   255,     6,     6,   115,     4,   117,     0,
     275,   138,     6,     9,   105,     4,     4,   171,   111,   271,
     138,     9,     9,   108,     4,    88,   111,   112,   113,   105,
       4,    94,     4,   124,     9,   202,    99,    26,   269,   124,
     266,   104,  1913,   152,   275,   199,   254,   255,    37,    38,
       9,   267,   115,     6,     4,     7,   272,     6,   254,   255,
     108,   215,   216,   111,     9,  1930,    97,   275,     6,   254,
     255,     4,    14,   270,   183,     9,    26,   274,   105,   275,
     189,   108,     6,   266,   111,   268,   113,    37,    38,   152,
     275,   210,   275,    26,   157,   158,   159,   124,   105,   254,
     255,   220,   267,   166,    37,    38,     4,     7,   105,   194,
     275,     7,   109,   254,   255,   153,   267,     8,   115,   116,
     275,   118,   119,   266,   275,   114,   115,   266,    26,   267,
     254,   255,   266,   266,   275,   175,   270,   275,   637,    37,
      38,   266,   205,     7,  2219,   142,   270,   210,   348,     7,
     187,   214,   215,   108,   254,   255,   111,   220,   221,   222,
     265,   266,   267,   267,   114,   115,   266,     6,   368,   124,
     270,   275,   187,   189,   190,   191,   192,   266,     7,   210,
     285,   114,   115,  1768,     6,   201,   267,   203,   204,   205,
     206,   207,   237,   237,   275,   211,   212,   214,   214,   254,
     255,   320,   321,   322,   262,   263,   237,   108,   237,   237,
     111,   250,   270,   266,   253,   268,  1590,   300,   281,  2084,
     275,   270,   339,   340,     6,   270,   268,     6,   270,   273,
     347,   348,   274,   296,   237,   270,   299,   300,   270,   270,
     739,   270,   361,   362,   363,   445,   270,   447,   270,   237,
     270,   270,   315,   316,   454,   271,   319,   320,   321,   322,
     379,   272,  1114,  1115,   267,   266,   269,   330,   270,   270,
     266,   334,   268,   336,   262,   263,   270,  2142,   266,   266,
     268,   268,   270,   268,   272,   272,   266,   239,   240,   241,
     242,   266,   266,   268,   266,   358,   359,   272,   361,   362,
     363,   254,   255,   262,   263,   254,   255,   266,   807,   268,
     262,   263,   250,   272,   270,   253,   379,   262,   263,   382,
     272,   266,   266,   268,   269,   824,   270,   272,   262,   263,
     254,   255,   266,   272,   268,   834,   275,     6,   272,   239,
     240,   241,   242,   239,   240,   241,   242,  2257,     6,   254,
     255,   460,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     275,   254,   255,   576,   265,   239,   240,   241,   242,     6,
     271,   239,   240,   241,   242,     4,   266,   450,   268,   452,
     270,     6,   275,   456,   457,   267,   262,   263,   262,   263,
     254,   255,   270,   275,   262,   263,   272,    26,   268,   472,
     239,   240,   241,   242,     4,   266,   479,     8,    37,    38,
     149,   275,   266,   149,   254,   255,   270,   108,   266,  2294,
     111,   266,   113,   262,   263,     4,    26,   254,   255,   168,
     271,   504,   168,   124,   275,   275,   149,    37,    38,   948,
     179,   180,   181,   179,   180,   181,   185,   186,   275,   185,
     186,   661,   266,   663,   664,   168,   266,   530,   268,  1196,
     254,   255,   272,   592,   266,   275,   179,   180,   181,  2344,
     680,   266,   185,   186,   254,   255,   267,   254,   255,  2074,
     599,   275,   266,   556,   275,   114,   115,   254,   255,   111,
     700,   113,   565,   566,   266,   275,   267,   570,   275,   572,
     573,   574,   575,   576,   275,   598,   266,   600,   275,   582,
     254,   255,   254,   255,   114,   115,   266,   727,   591,   592,
     593,   266,   595,   596,   597,   598,   270,   600,   266,   602,
     743,    58,   271,   275,   267,   271,   254,   255,   267,     8,
     269,   270,   275,   670,   671,   254,   255,   266,   675,   268,
     105,   254,   255,   108,   266,   628,   111,   275,   271,   254,
     255,   634,   772,   267,   266,   269,   275,   254,   255,   124,
     199,   200,   275,   793,   149,   154,   155,   156,   157,   128,
     275,   160,   161,   656,   657,     8,   259,   260,   275,   111,
     149,   170,   265,   168,   271,   174,   254,   255,   275,   199,
     200,  1338,  1339,   266,   179,   180,   181,  1116,   266,   168,
     185,   186,   270,   254,   255,   267,   267,   269,   269,   270,
     179,   180,   181,   275,   672,   673,   185,   186,   267,   270,
     269,   262,   263,   706,   707,   708,   275,   756,   266,     6,
     268,   714,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     272,   271,   274,   736,   265,   275,   267,   760,   741,   742,
     743,   744,   745,   746,   747,   748,   749,   270,   751,   752,
     753,   754,   755,     6,   757,   758,   759,   760,   761,   270,
     266,   764,   268,   267,   221,   269,   271,  1559,   813,   262,
     263,   275,     3,   266,   271,   268,   266,   270,   275,   782,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   798,   113,     6,    29,   265,
     849,   804,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   154,   155,   820,   821,   265,
    1259,   160,  1261,   826,   281,   828,   266,   977,   831,   832,
     267,   270,   269,     6,    65,  1274,   271,   840,   275,   842,
     275,   266,   270,   268,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   319,  1003,  1656,  1304,   265,   108,     4,   872,
       6,   874,   271,   330,  1666,     6,     7,   334,   256,   257,
     258,   259,   260,   108,   254,   255,   111,   265,   113,   120,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   911,   267,
     111,   269,   265,   270,   267,   270,   269,   275,   921,  1069,
     271,   152,   266,   270,   275,   270,   157,   158,   159,  1368,
    2246,   266,  1371,  1372,   271,   166,   262,   263,   275,   271,
     266,   990,   268,   275,   262,   263,   111,   950,   266,  1006,
     268,   271,   154,   155,   108,   275,  1013,  1396,   160,     6,
    1017,   108,   111,   966,  1114,  1115,  2280,   254,   255,   256,
     257,   258,   259,   260,   205,   978,   111,     4,   265,   271,
    1419,  1131,   271,   275,   987,     4,   275,     4,   271,  2305,
     271,   222,   275,   271,   275,     4,   999,   275,   271,   456,
     457,   271,   275,   266,     6,   275,   271,  1446,  2322,   271,
     275,   266,   271,   275,   271,   472,   275,     6,   275,   271,
     271,  1460,   271,   275,   275,   271,   275,   271,  1467,   275,
     266,   275,   266,   264,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   283,   284,   271,   271,   265,   271,   275,   275,
     271,   275,     6,   271,   275,   268,   270,   275,   268,  1118,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,     6,   271,
    1423,   271,   265,   275,   271,   275,   271,   271,   275,   271,
     275,   275,   270,   275,   271,   271,  1109,   271,   275,   275,
       6,   275,   274,   271,  1117,  1172,   573,   275,   274,   271,
     271,   266,  1125,   275,   275,  1275,  1276,   271,     9,   266,
     270,   275,  1799,  1800,   591,  1138,   593,   271,   271,   271,
    1143,   275,   275,   275,   271,   271,   271,   271,   275,   275,
     275,   275,   271,     4,     5,   271,   275,   271,   271,   275,
     271,   275,   275,   271,   275,   271,   266,   275,   271,   275,
    1173,  1174,   275,  1176,  1177,  1178,   266,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,   271,   271,  1192,
     271,   275,   275,   271,   275,   266,   266,   275,   266,    50,
      51,    52,    53,    54,    55,    56,    57,    58,   202,   202,
     202,   270,    63,    64,    65,    66,   111,   138,  1196,   450,
      71,    72,    73,    74,   266,   266,   266,   266,   202,    80,
     461,    82,  1235,  1236,  1237,   270,   266,   266,   266,   270,
     266,     4,     6,   266,     6,   270,   270,    98,   270,   270,
     101,   266,   483,   266,   105,   266,   266,   108,   266,   266,
     111,     6,   113,  1266,   268,   270,     7,   498,     6,   270,
     270,   270,   270,   124,     6,   270,   202,   268,   268,  1282,
    1283,  1284,   268,   266,   266,   266,   266,   266,   266,   266,
     266,     6,     6,   268,   145,     6,     8,  1447,  1448,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   270,     6,     8,
     266,   265,   270,     7,     6,   782,  1659,   270,   270,     6,
     270,   100,   271,   267,   275,     7,     6,  1340,   275,   570,
       6,   572,   267,   574,   575,   576,   270,   270,   270,    68,
     270,   270,     8,   270,   270,   270,  1359,   270,  1361,  1362,
    1338,  1339,   270,   265,   595,   596,   272,   218,   219,   220,
       7,  1374,     7,   266,     6,   267,  1379,     7,     6,   230,
    1383,   270,     7,   234,     6,   236,   237,     6,     6,  1392,
     199,  1394,   271,   270,  1397,   271,   271,   269,   267,     6,
     270,   272,     7,     6,   268,   266,     6,  1410,   270,     6,
       6,   262,   263,     6,     6,   267,     7,     7,   268,   270,
    1423,   272,  1471,  2090,  1473,     7,     7,     7,  1867,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,  1448,     7,   678,     7,   265,
    1453,     7,  1455,     7,     7,     7,     7,     7,     7,     7,
       7,     6,   270,   267,   269,   275,   267,   270,   275,   275,
    1473,   271,   703,   275,     7,   271,     7,   272,   270,   270,
       4,     6,   272,  1486,   271,   271,   149,  1490,   270,   270,
       7,     6,   272,   950,     7,     7,     7,   272,   275,   267,
     267,   275,     9,   275,  1644,   202,  1656,   267,  1648,   274,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   269,
     751,   752,   753,   754,  1667,  1668,   757,   758,   759,     7,
     987,   171,  1589,     6,   271,   270,   767,     6,     6,   770,
      50,    50,  1875,   272,   266,   776,   270,   270,   266,     7,
    1553,  1554,  1555,   266,     7,   272,   272,   266,  1561,  1562,
    1563,     7,   267,   202,     7,   275,     7,     7,     6,   267,
       7,   275,     7,     7,     7,     7,     4,  1580,   270,   123,
       6,   812,     7,   814,     6,   266,     7,     7,  1591,     7,
       7,  1640,     7,     7,     7,   270,  1599,   105,     6,     6,
     831,  1604,     6,   267,     7,   111,     7,     6,     6,     4,
       7,   842,  1615,     7,  1617,   273,   275,     6,   275,   270,
     270,   270,     6,   271,  1774,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,     6,   268,     7,     6,   265,     7,     8,
       6,     6,  1109,  1702,   266,   266,  1659,   270,     6,     6,
       6,   271,     6,  1720,  1667,  1668,   272,     6,  1125,     6,
    1673,   269,     6,   275,     6,   142,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,  1691,   267,
     129,   267,   271,   129,     6,     6,     4,   202,   129,  1702,
       6,   270,   270,     7,  1707,     6,   270,     7,   270,     6,
     270,   268,     6,   271,     6,   270,  1173,  1174,     6,  1176,
    1177,  1178,     6,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,   270,   270,  1878,   270,   198,   270,     6,
     270,     6,   271,   270,   270,   267,  1795,   275,     7,     6,
     270,     6,   275,   271,   275,     6,   275,     6,  1815,  1816,
    1817,  1818,  1819,  1820,   266,   266,     4,   270,   272,   266,
       7,  1002,     6,  1004,  1005,     6,     6,     6,  1235,   149,
       6,     5,   270,  1786,     6,   270,   270,  1018,  1791,  1792,
     109,   270,   267,   275,  1843,   111,  2129,     6,   270,   270,
       6,  1850,  1851,     6,   149,   275,   149,     6,  1039,  1266,
       6,  1814,     6,     6,     6,   275,   267,  1820,   275,     6,
    1869,  1799,  1800,  1826,     6,  1282,     6,   275,   270,     6,
    1061,     6,  1835,     6,     6,     6,   153,     7,     6,     5,
     270,   270,  1845,   270,     6,  1848,   270,   270,     6,     6,
       6,   270,     7,     6,   270,   267,   197,     6,     6,   270,
     270,  1864,   271,     7,     6,  1868,   271,   267,     6,  1100,
     272,     6,  1875,     6,  1877,  1878,     6,     6,   271,   271,
     271,     6,   270,  1340,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,  1359,   271,  1361,  1362,   265,     6,     6,   267,
    1913,     6,  1143,   270,     6,   200,     6,   270,     6,   271,
     271,   270,     6,     6,   266,     6,   149,  1930,     6,   267,
     270,     6,     6,     6,   270,   270,     6,     6,   271,   270,
       6,     6,     6,  1946,  1947,     6,     6,     6,     6,     6,
       6,     6,     6,  1410,   267,   270,     6,   271,     6,  2099,
       6,   271,  2259,   270,  1459,   270,  2015,   270,  1971,  1522,
    1715,  2053,  2013,  1782,     3,  1485,     3,  1127,     3,     3,
    1983,   589,   649,  2086,  1637,   501,     3,  1868,  1850,  1668,
     831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2001,    -1,
      -1,    -1,    -1,    -1,    -1,  1236,  1237,    -1,    -1,  2058,
      -1,    -1,    -1,    -1,    -1,    -1,  1473,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1486,
      -1,    -1,    -1,  1490,    -1,    -1,  2039,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2103,  2104,  2105,  2106,
    2107,  2054,    -1,    -1,    -1,    -1,  2059,    -1,    -1,  2062,
    2063,    -1,    -1,    -1,  2204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1306,    -1,    -1,    -1,    -1,
      -1,  2084,    -1,    -1,  2087,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2098,  1553,  1554,  1555,  2102,
      -1,    -1,    -1,    -1,  1561,  1562,  1563,  2247,    -1,    -1,
      -1,  2114,  2090,    -1,    -1,    -1,    -1,  2174,    -1,    -1,
      -1,  2178,    -1,  1580,    -1,    -1,  2129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1591,    -1,    -1,    -1,    -1,  2142,
      -1,    -1,  1599,     6,    -1,    -1,    -1,    -1,  1379,    -1,
      -1,    -1,  1383,    -1,    -1,    -1,    -1,    -1,  1615,    -1,
    1617,  1392,    -1,  1394,    -1,    -1,  1397,    -1,    -1,    -1,
      -1,  2220,  2175,  1404,    -1,    -1,  2233,    -1,    -1,    -1,
    2237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2253,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,     4,     5,  1673,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2300,  2301,  1702,  2249,  2250,  2251,  2252,
    2253,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,   222,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,  2294,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2310,    98,    -1,
      -1,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,  2331,  1786,
      -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,  2344,    -1,    -1,    -1,    -1,    -1,  2350,  2351,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,  1814,    -1,    -1,
    2363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1835,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,  1864,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1877,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,    -1,    -1,    -1,    -1,    -1,  1667,  1668,    -1,    -1,
     230,    -1,    -1,    -1,   234,    -1,   236,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1930,    -1,    -1,    -1,   267,    -1,   269,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,
      -1,   124,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1971,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
      -1,   194,   195,   196,     6,   198,   199,   200,   201,   202,
     203,   204,  2039,   206,   207,   208,   209,    -1,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,    -1,  2054,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1845,    -1,    -1,  1848,    -1,   570,
      -1,   572,    -1,   574,   575,     6,    -1,  2084,    -1,    -1,
    1861,    -1,  1863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2098,    -1,    -1,   595,   596,    -1,  1878,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,   295,   296,   297,   298,   299,    -1,    -1,    -1,
      -1,    -1,  1913,    -1,    -1,  2142,    -1,    -1,    -1,    -1,
      -1,   314,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2175,   342,
     343,    -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,   359,   360,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,   381,   382,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,
      -1,   394,   395,    -1,   397,    -1,    -1,    -1,   401,   402,
     403,    -1,    -1,   406,    -1,    -1,    -1,   410,    -1,    -1,
      -1,   742,    -1,   744,   745,   746,   747,   748,   749,    -1,
     751,   752,   753,   754,    -1,    -1,   757,   758,   759,    -1,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   452,
     453,    -1,    -1,   265,    -1,    -1,    -1,  2294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   469,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     831,    -1,    -1,   506,   265,    -1,    -1,  2344,   511,    -1,
      -1,   842,   515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   529,   530,    -1,    -1,
      -1,    -1,   535,    -1,    -1,    -1,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,    -1,   568,   569,    -1,   571,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2187,    -1,   581,    -1,
      -1,   584,   585,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   597,    -1,    -1,    -1,    -1,   602,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,    -1,   635,   636,    -1,    -1,    -1,    -1,    -1,    -1,
     643,   644,   645,    -1,    -1,    -1,  2257,    -1,   651,   652,
     653,   654,    -1,   656,   657,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2281,    -1,   675,   676,   677,    -1,    -1,    -1,   681,   682,
     683,   684,   685,   686,   687,   688,   689,    -1,    -1,    -1,
      -1,    -1,    -1,   696,   697,    -1,   699,    -1,    -1,   702,
      -1,    -1,    -1,   706,   707,   708,   709,    -1,    -1,    -1,
     713,   714,   715,   716,   717,    -1,    -1,   720,    -1,   722,
    2331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   732,
      -1,    -1,   735,    -1,   737,   738,    -1,    -1,    -1,  2350,
    2351,    -1,    -1,    -1,    -1,    -1,    -1,   750,    -1,    -1,
      -1,    -1,  2363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   764,    -1,    -1,    -1,    -1,    -1,    -1,   771,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   798,    -1,   800,    -1,   214,
     215,    -1,   805,   806,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1143,    -1,    -1,    -1,    -1,   820,    -1,   822,
     823,    -1,    -1,   826,    -1,   828,   829,    -1,    -1,    -1,
     833,    -1,   835,    -1,   837,    -1,    -1,    -1,    -1,    -1,
     843,    -1,    -1,    -1,   847,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,   870,   265,   872,
      -1,   874,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296,    -1,    -1,   299,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
     315,   316,    -1,    -1,    -1,  1236,  1237,    -1,   911,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   921,   922,
     923,   924,    -1,    -1,    -1,    -1,    -1,    -1,   931,   932,
     933,    -1,   935,    -1,    -1,   938,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   358,   359,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   966,    -1,    -1,    -1,   382,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   978,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   986,    -1,    -1,    -1,   990,    -1,    -1,
     149,    -1,    -1,   996,    -1,    -1,   999,    -1,    -1,   315,
     316,    -1,    -1,    -1,  1007,  1008,    -1,    -1,    -1,    -1,
    1013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1031,    -1,
      -1,  1034,    -1,    -1,    -1,    -1,    -1,   452,    -1,    -1,
      -1,    -1,   358,   359,    -1,    -1,    -1,    -1,  1379,    -1,
      -1,    -1,  1383,    -1,    -1,    -1,    -1,  1060,    -1,  1062,
    1063,  1392,    -1,  1394,    -1,    -1,  1397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1085,     6,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,  1105,    -1,    -1,    -1,   265,    -1,    -1,  1112,
      -1,    -1,    -1,    -1,    -1,   530,  1119,  1448,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1132,
    1133,    -1,    -1,    -1,    -1,  1138,   452,    -1,    -1,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     565,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   597,    -1,    -1,    -1,    -1,   602,    -1,  1192,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,  1211,    -1,
      -1,    -1,   265,   628,    -1,    -1,    -1,    -1,  1221,  1222,
    1223,  1224,  1225,    -1,    -1,    -1,    -1,  1230,  1231,    -1,
    1233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   656,   657,    -1,    -1,    -1,    -1,    -1,  1251,    -1,
      -1,  1254,  1255,    -1,    -1,    -1,    -1,    -1,    -1,  1262,
    1263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1271,  1272,
      -1,    -1,    -1,    -1,  1277,  1278,    -1,    -1,    -1,    -1,
    1283,  1284,     6,    -1,    -1,    -1,   602,    -1,    -1,    -1,
      -1,   706,   707,   708,    -1,    -1,    -1,    -1,    -1,   714,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1318,    -1,    -1,   474,    -1,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
     656,   657,   265,    -1,    -1,    -1,    -1,    -1,    -1,   764,
      -1,    -1,    -1,    -1,  1357,    -1,    -1,    -1,    -1,    -1,
    1691,    -1,    -1,    -1,    -1,    -1,  1369,  1370,    -1,    -1,
      -1,  1374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1382,
      -1,    -1,    -1,   798,    -1,    -1,    -1,    -1,    -1,    -1,
     706,   707,   708,    -1,    -1,    -1,    -1,    -1,   714,    -1,
      -1,    -1,    -1,  1406,    -1,   820,    -1,    -1,    -1,    -1,
      -1,   826,    -1,   828,  1417,    -1,    -1,  1420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1449,     6,   764,  1452,
    1453,  1454,  1455,    -1,    -1,    -1,    -1,   872,    -1,   874,
    1463,    -1,    -1,  1466,    -1,  1468,    -1,  1470,  1471,    -1,
      -1,  1474,  1475,  1476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   798,   639,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   911,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   820,    -1,   921,    -1,    -1,    -1,
     826,    -1,   828,    -1,  1845,    -1,    -1,  1848,    -1,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   966,    -1,    -1,    -1,    -1,    -1,  1560,    -1,    -1,
      -1,    -1,    -1,   978,    -1,    -1,    -1,    -1,  1571,  1572,
    1573,    -1,    -1,    -1,    -1,    -1,    -1,  1580,    -1,  1582,
      -1,    -1,    -1,    -1,   999,    -1,  1589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   911,    -1,    -1,    -1,    -1,
      -1,  1604,    -1,    -1,    -1,   921,    -1,  1610,  1611,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1621,  1622,
    1623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1632,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1642,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     966,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1663,    -1,   978,    -1,    -1,    -1,    -1,    -1,  1671,  1672,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   999,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,  1707,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1138,   880,   881,   882,   883,   884,   885,
     886,   887,   888,   889,   890,   891,    -1,   893,   894,   895,
     896,    -1,   898,   899,   900,   901,    -1,  1750,  1751,  1752,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   914,    -1,
     916,    -1,    -1,  1766,    -1,    -1,    -1,    -1,  1771,  1772,
      -1,   927,    -1,    -1,    -1,    -1,    -1,  1192,    -1,    -1,
      -1,  1784,    -1,    -1,   940,   941,    -1,    -1,  1791,  1792,
    1793,    -1,  1795,   949,    -1,    -1,    -1,    -1,  1801,  1802,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,
      -1,    -1,  1138,  1826,  1827,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1839,  1840,    -1,    -1,
    1843,    -1,    -1,  1846,    -1,    -1,    -1,  1850,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1860,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1870,  1283,  1284,
      -1,    -1,    -1,    -1,    -1,    -1,  1192,    -1,    -1,    -1,
      -1,  1884,    -1,    -1,    -1,    -1,  1889,  1890,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1903,    -1,    -1,  1906,  1907,    -1,  1909,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1071,  1072,  1073,    -1,    -1,
      -1,  1077,  1078,    -1,    -1,  1081,  1082,  1083,  1084,    -1,
    1086,    -1,  1935,  1936,  1937,  1091,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1946,  1947,    -1,    -1,    -1,    -1,    -1,
    1953,  1954,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1374,
      -1,    -1,  1965,    -1,    -1,    -1,    -1,  1283,  1284,    -1,
      -1,  1974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1996,  1997,    -1,    -1,  2000,  2001,    -1,
    2331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1169,    -1,  1171,    -1,    -1,    -1,  2350,
    2351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2363,  2036,  2037,    -1,    -1,    -1,  1453,    -1,
    1455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2057,    -1,    -1,    -1,  1374,  2062,
    2063,  2064,    -1,    -1,    -1,    -1,  2069,    -1,    -1,    -1,
    2073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2087,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2102,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,  2111,    -1,
      -1,  2114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2139,  1453,    -1,  1455,
      -1,    -1,  2145,    -1,    -1,  2148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2163,    -1,  2165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
    2183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1604,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    -1,  2210,  2211,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,  2225,  2226,    -1,    -1,   138,   139,  2231,    -1,
     142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,    -1,
      -1,  2244,    -1,    -1,    -1,    -1,  2249,  2250,  2251,  2252,
    2253,    -1,    -1,    -1,    -1,   167,  2259,    -1,    -1,    -1,
    2263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1429,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,   196,    -1,    -1,    -1,  1604,  2292,
      -1,    -1,  1707,    -1,  2297,  2298,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2310,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1472,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2337,  2338,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1505,
    1506,  1507,  1508,  1509,  1510,  1511,    -1,    -1,    -1,   271,
    1516,  1517,    -1,    -1,    -1,    -1,    -1,  1523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1531,  1791,  1792,    -1,  1535,
      -1,    -1,  1538,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,  1549,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,    -1,    -1,
      -1,  1826,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,     6,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,  1628,    -1,  1630,  1791,  1792,    -1,  1634,    -1,
    1636,    13,    14,    98,    -1,    -1,   101,    -1,    -1,    -1,
     105,     6,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,
    1826,  1667,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     145,  1946,  1947,    -1,   265,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1983,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,  2001,    -1,    -1,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,   138,   139,    -1,    -1,
     142,   143,    -1,   145,   146,   230,   148,  1773,    -1,   234,
     152,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1946,  1947,    -1,    -1,    -1,   167,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2062,  2063,    -1,
      -1,    -1,    -1,    -1,    28,   270,    30,    -1,    -1,    -1,
      -1,    -1,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2087,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2001,    -1,  2102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2114,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,     6,    -1,
      -1,    -1,   265,    -1,  1880,    -1,    -1,  1883,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,  2062,  2063,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2087,    -1,    -1,    -1,    -1,  1932,  1933,   152,    -1,
      -1,    -1,    -1,  1939,    -1,    -1,  2102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2249,  2250,  2251,  2252,  2253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2006,  2007,    -1,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,    -1,
      -1,    -1,    -1,    -1,    -1,  2310,    -1,   271,   272,  2055,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,  2231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2249,  2250,  2251,  2252,  2253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2310,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,   412,   413,
     414,    -1,    -1,    -1,   418,   419,   420,   421,   422,   423,
     424,    -1,   426,    -1,    -1,    -1,    -1,   431,   432,    -1,
      -1,   435,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
     101,    -1,    -1,  2319,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,    -1,   610,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,   199,    -1,
     265,     6,   267,    -1,   269,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,   230,
     231,   232,   233,   234,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   266,     3,     4,     5,   270,
      -1,    -1,   273,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,    -1,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,     7,    -1,    -1,    -1,
     265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     944,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,   270,    -1,    -1,   273,     3,     4,     5,
      -1,     7,    -1,   977,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   145,
      -1,   265,    -1,   267,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,   230,   231,   232,   233,   234,    -1,
     236,   237,    -1,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,   262,   263,    -1,    -1,
     266,    -1,   268,    -1,    -1,    -1,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,  1267,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,
     111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,
     141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,    -1,  1430,  1431,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,   199,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,   217,    -1,     8,    -1,
     221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,
     231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,   270,
      -1,    -1,   273,    -1,    -1,    -1,    -1,     3,     4,  1533,
      -1,    -1,     8,    -1,    10,    11,    12,    -1,  1542,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,
      -1,    -1,  1706,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   199,    -1,   265,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,     3,     4,     5,    -1,   271,    -1,   273,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,    -1,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,   199,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     222,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,     3,     4,    -1,   270,    -1,
      -1,   273,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   199,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,   227,
     228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,     3,
       4,    -1,   270,   271,    -1,   273,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,    -1,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,   233,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,     3,     4,    -1,   270,    -1,    -1,   273,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,   199,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,     3,     4,    -1,
     270,    -1,    -1,   273,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,     3,     4,    -1,   270,    -1,    -1,   273,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,    -1,    -1,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   140,   141,
      -1,   143,    -1,   145,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,    -1,   160,   161,
     162,   163,   164,   165,   166,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,   199,    -1,    -1,
      -1,   271,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     222,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,     3,     4,    -1,    -1,   271,
      -1,   273,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   199,    -1,    -1,    -1,   271,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,   227,
     228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,     3,
       4,    -1,   270,    -1,    -1,   273,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,    -1,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,   271,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,   233,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,     3,     4,    -1,   270,    -1,    -1,   273,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,     3,     4,    -1,
     270,    -1,     8,   273,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,    -1,
     266,     8,    -1,    10,    11,    12,    -1,   273,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,    -1,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,
     227,   228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,     3,     4,    -1,    -1,   266,
      -1,    -1,    10,    11,    12,    -1,   273,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,   124,   125,   126,    -1,
      -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,   140,   141,    -1,   143,    -1,   145,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,    -1,   160,   161,   162,   163,   164,   165,   166,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,   227,
     228,   229,    -1,   231,   232,   233,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,     3,
       4,    -1,   270,    -1,    -1,   273,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,   141,    -1,   143,
      -1,   145,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,    -1,   160,   161,   162,   163,
     164,   165,   166,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,    -1,   227,   228,   229,    -1,   231,   232,   233,
      -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,     3,     4,    -1,   270,    -1,    -1,   273,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,   124,   125,   126,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
     140,   141,    -1,   143,    -1,   145,    -1,    -1,   148,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,    -1,
     160,   161,   162,   163,   164,   165,   166,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,   222,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,     3,     4,    -1,
      -1,   271,    -1,   273,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,   124,   125,
     126,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,   140,   141,    -1,   143,    -1,   145,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,    -1,   160,   161,   162,   163,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,     3,     4,     5,    -1,
     266,    -1,    -1,    10,    11,    12,    -1,   273,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,   101,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,   270,    -1,    -1,   273,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,    -1,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,     3,
       4,     5,   270,    -1,    -1,   273,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,   101,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,    -1,   227,   228,   229,   230,   231,   232,   233,
     234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,    -1,    -1,    -1,   270,    -1,    -1,   273,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,
       6,   266,    -1,    -1,    10,    11,    12,    -1,   273,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      96,    97,    -1,    99,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    83,    84,    85,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
      96,    97,    -1,    99,    -1,    -1,    -1,   138,   139,    -1,
      -1,   142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,   167,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,   196,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,   273,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
     271,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
     266,     3,     4,    -1,   270,    -1,    -1,   273,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    96,    97,     8,    99,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    83,    84,    85,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    96,    97,    -1,    99,    -1,    -1,
      -1,   138,   139,    -1,    -1,   142,   143,    -1,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,   221,
     167,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,   196,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,   270,    -1,
      -1,   273,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,   231,
     232,   233,    -1,    -1,   271,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,
       3,     4,    -1,    -1,   266,    -1,    -1,    10,    11,    12,
      -1,   273,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    -1,    99,     3,     4,    -1,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    -1,    99,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,   217,    -1,    -1,   265,   221,    -1,
      -1,    -1,    -1,    -1,   227,   228,   229,   275,   231,   232,
     233,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,   266,   267,    -1,    -1,    -1,    -1,    -1,
     273,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,   227,   228,   229,    -1,   231,   232,   233,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,     6,
     266,    -1,    -1,    10,    11,    12,    -1,   273,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    -1,    99,     3,     4,    -1,     6,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
     217,    -1,    -1,   265,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,   275,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,     3,     4,    -1,   266,
      -1,    -1,    -1,    10,    11,    12,   273,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    59,    60,    61,    62,    -1,   227,   228,   229,
      67,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    96,
      97,   261,    99,     3,     4,    -1,   266,    -1,    -1,    -1,
      10,    11,    12,   273,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
     217,    -1,    -1,   265,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,   275,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,     3,     4,    -1,   266,
     267,    -1,    -1,    10,    11,    12,   273,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    59,    60,    61,    62,    -1,   227,   228,   229,
      67,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    96,
      97,   261,    99,     3,     4,    -1,   266,   267,    -1,    -1,
      10,    11,    12,   273,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
     217,    -1,    -1,   265,   221,    -1,    -1,    -1,    -1,    -1,
     227,   228,   229,   275,   231,   232,   233,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,   270,    -1,    -1,   273,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    13,    14,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,   227,   228,   229,
      -1,   231,   232,   233,    -1,    -1,    -1,   237,    -1,    -1,
      -1,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   254,   255,    -1,   121,   122,   123,
     124,   261,    -1,    -1,    -1,   129,   266,    -1,    -1,    -1,
      -1,    -1,    -1,   273,   138,   139,    13,    14,   142,   143,
      -1,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,    -1,
     194,   195,   196,    -1,    -1,    -1,    -1,   138,   139,    13,
      14,   142,   143,    -1,   145,   146,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,   194,   195,   196,    -1,    -1,    -1,    -1,
      -1,   138,   139,    13,    14,   142,   143,   271,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,   129,    -1,   194,   195,   196,
      -1,    -1,    -1,    -1,   138,   139,    13,    14,   142,   143,
     271,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
     194,   195,   196,    -1,    -1,    -1,    -1,    -1,   138,   139,
      13,    14,   142,   143,   271,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,   194,   195,   196,    -1,    -1,    -1,
      -1,   138,   139,    13,    14,   142,   143,   271,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,   194,   195,   196,
      -1,    -1,    -1,    -1,    -1,   138,   139,    13,    14,   142,
     143,   271,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
      -1,   194,   195,   196,    -1,    -1,    -1,    -1,   138,   139,
      13,    14,   142,   143,   271,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,   194,   195,   196,    -1,    -1,    -1,
      -1,    -1,   138,   139,    13,    14,   142,   143,   271,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,   129,    -1,   194,   195,
     196,    -1,    -1,    -1,    -1,   138,   139,    13,    14,   142,
     143,   271,   145,   146,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     129,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,   138,
     139,    -1,    -1,   142,   143,   271,   145,   146,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   129,    -1,   194,   195,   196,    -1,    -1,
      -1,    -1,   138,   139,    -1,    -1,   142,   143,   271,   145,
     146,    -1,   148,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,   167,    -1,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,   194,   195,
     196,    -1,    -1,    47,    48,    49,   275,    -1,    -1,    -1,
      -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    -1,   271,   120,   121,   122,   123,
     124,    -1,    -1,   127,    -1,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,    -1,   150,   151,   152,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,   193,
     194,   195,   196,    -1,    -1,   199,    -1,   201,    -1,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,     4,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,   237,   238,    -1,    -1,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    47,    48,    49,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
     120,   121,   122,   123,   124,    -1,    -1,   127,    -1,   129,
      -1,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,    -1,    -1,
     150,   151,   152,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,     4,     5,   199,
      -1,   201,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,   237,   238,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,     4,     5,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,   111,    -1,   113,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,   124,    -1,    -1,
      63,    64,    65,    66,     4,     5,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,   145,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,     5,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   218,   219,   220,    -1,    -1,    13,    14,    98,    -1,
      -1,   101,    -1,   230,    -1,    -1,    -1,   234,    -1,   236,
     237,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,   230,    -1,    -1,
      -1,   234,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   138,   139,    -1,    -1,   142,   143,    -1,   145,   146,
     230,   148,    -1,    -1,   234,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,   194,   195,   196,
     218,   219,   220,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,   234,    -1,   236,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     275,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   275,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,   271,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,   271,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   271,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
     271,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,   271,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,   271,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   271,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
     271,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,   271,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,   271,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   271,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
     271,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,   271,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,   271,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   271,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
     271,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,   270,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,   270,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,   270,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,   267,    -1,   269,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,   269,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
     269,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,   269,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,   269,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   269,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,   269,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,   269,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,   269,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,   269,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,   269,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,   269,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
     269,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,   269,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,   269,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   269,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,
      -1,   267,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    -1,   267,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,    -1,   265
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,   277,   278,     6,     0,     4,    13,    14,    47,
      48,    49,    68,    69,    70,    75,    76,    81,    86,    87,
      88,    89,    90,    91,    92,    94,    95,    97,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   120,   121,   122,   123,   124,   127,
     129,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   150,   151,
     152,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   182,   183,   184,   188,
     193,   194,   195,   196,   199,   201,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     223,   224,   225,   226,   235,   237,   238,   279,   281,   282,
     303,   322,   324,   328,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   346,   348,   349,   355,   356,   357,   358,
     364,   389,   390,   270,   274,    14,   111,   266,   266,   266,
       6,   270,     6,     6,     6,     6,   266,     6,   270,     6,
     270,   270,     6,     6,     6,     6,   268,   268,     4,   366,
     390,   266,   268,   300,   105,   108,   111,   113,   324,   300,
     266,   266,   266,     4,   266,   266,   266,     4,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   270,
     128,   111,     6,     6,   270,   270,   105,   108,   111,   124,
     327,   113,   266,     3,    10,    11,    12,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    59,
      60,    61,    62,    67,    68,    77,    78,    79,    83,    84,
      85,    96,    99,   105,   108,   111,   113,   124,   125,   126,
     129,   138,   143,   145,   148,   199,   217,   221,   222,   227,
     228,   229,   231,   232,   233,   254,   255,   261,   266,   270,
     273,   324,   325,   328,   339,   346,   348,   359,   360,   364,
     366,   372,   375,   390,   266,   270,   270,   111,   111,   138,
     108,   111,   113,   324,   108,   111,   112,   113,   124,   194,
     325,   108,   111,   266,   108,   171,   199,   215,   216,   270,
     254,   255,   266,   270,   369,   370,   369,   270,   270,   369,
       4,   105,   109,   115,   116,   118,   119,   142,   270,   270,
     266,   111,   113,   111,   108,     4,    97,   210,   270,   390,
       4,     6,   105,     6,   108,   111,   108,   111,   124,   326,
       5,   266,   270,   372,   374,   111,     4,     4,     4,   374,
       4,   111,   266,   111,   266,   266,     4,   270,   377,   390,
       4,   266,   266,   266,     6,    33,   255,   359,   390,     6,
     268,     5,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    63,    64,    65,    66,    71,    72,    73,    74,    80,
      82,    98,   101,   218,   219,   220,   230,   234,   236,   381,
     390,   266,     4,   381,     5,   270,     5,   270,   324,   359,
     268,     6,   270,   266,   270,     6,   266,   270,     6,   274,
       7,   145,   210,   239,   240,   241,   242,   262,   263,   266,
     268,   272,   298,   299,   300,   324,   359,   380,   381,   390,
       4,   328,   329,   330,   270,     6,   359,   380,   381,   390,
     380,   380,   359,   380,   387,   388,   390,   359,   330,   359,
     305,   309,   266,   368,     9,   381,   266,   381,   359,   359,
     359,   266,   359,   359,   359,   266,   359,   359,   359,   359,
     359,   359,   359,   380,   359,   359,   359,   359,   374,   266,
     255,   359,   375,   376,   376,   270,   374,   372,   380,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   266,   268,   300,   300,   300,
     300,   300,   300,   266,   300,   300,   266,   324,   325,   325,
     325,   300,   300,     5,   270,   270,   111,   108,   111,    68,
     105,   138,   324,   324,   325,   266,   300,   300,   266,   266,
     266,   359,   270,   359,   375,   359,   359,   271,   376,   366,
     390,   202,     5,   270,     8,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   265,     9,   266,   268,   272,   299,   300,
     359,   376,   376,   266,   266,   266,   372,   374,   374,   374,
     323,   266,   270,   266,   266,   372,   270,   270,   359,     4,
     372,   270,   377,   270,   270,   369,   369,   369,   359,   359,
     254,   255,   270,   270,   369,   254,   255,   266,   330,   369,
     270,   266,   270,   266,   266,   266,   266,   266,   266,   266,
     376,   376,   359,   374,   374,   374,   266,   270,     4,   268,
     270,     6,   268,   330,     6,     6,   270,   270,   270,   270,
     374,   359,     8,     7,   270,   268,   268,   268,     6,     6,
     266,   359,   266,   359,   359,   272,   359,   270,   202,   359,
     359,   359,   300,   359,     6,   256,     9,   266,   268,   272,
     359,   300,   300,   300,   266,   266,   266,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   266,   266,   300,
     266,   268,     6,     6,   270,     6,     8,   330,     6,     8,
     330,   266,   270,   380,   376,   359,   330,   372,   372,   270,
     381,   324,     7,   359,   359,     4,    26,    37,    38,   114,
     115,   199,   200,   302,   372,     6,   267,   269,   270,   301,
     270,     6,   270,     6,     9,   266,   268,   272,   390,   271,
     138,   143,   145,   146,   148,   322,   324,   359,     6,   267,
     275,     9,   266,   268,   272,   267,   275,   267,   275,   275,
     267,   275,     9,   266,   272,   275,   271,   275,   269,   275,
     304,   269,   304,   100,   367,   365,   390,   275,   359,   275,
     267,   267,   267,   359,   267,   267,   267,   359,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   271,
       7,   359,   256,   271,   275,   271,   359,     6,     6,   267,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   375,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   375,   375,
     390,   270,   359,   359,   380,   359,   380,   372,   380,   380,
     387,   270,   270,   270,   270,   359,   301,   390,     8,   359,
     359,   270,   270,   270,   326,   270,   374,   372,   270,   380,
     380,   375,   366,   381,   366,   376,   267,   271,   272,   300,
      68,     8,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   270,   359,   375,   359,
     359,   359,   359,   359,   390,   359,   359,   302,   270,   301,
     267,   271,   271,   359,   359,   359,     7,     7,   352,   352,
     266,   359,   359,   359,   359,     6,   175,   376,   376,   270,
     267,     6,   330,   270,   330,   330,   275,   275,   275,   369,
     369,   329,   329,   275,   359,   271,   343,   275,   330,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   271,   271,
     267,     7,   353,     6,     7,   359,   359,     6,   359,   330,
     359,   271,   376,   376,   376,   359,     6,   267,   271,   359,
     376,   359,   359,   359,   359,   267,   359,   267,   267,   199,
     275,   330,   270,     8,   267,   267,   359,   359,   390,   302,
     269,   387,   380,   387,   380,   380,   380,   380,   380,   380,
     359,   380,   380,   380,   380,   273,   383,   390,   381,   380,
     380,   380,   366,   390,   376,   271,   271,   271,   271,   359,
     330,   269,   271,   267,   152,   171,   347,   267,   271,   275,
     359,     6,   270,   372,   267,   269,   272,     7,     7,   298,
     299,     6,   376,     7,   239,   298,   359,   283,   390,   359,
     359,   302,   268,   266,   138,   324,   325,   324,   270,   271,
       6,   250,   253,   280,   376,   390,   359,   359,   302,     6,
     376,     6,   376,   359,     6,   380,   388,   390,   267,   302,
     359,   359,     6,   390,     6,   380,   359,   267,   268,   359,
     275,   381,     7,     7,     7,   267,     7,     7,     7,   267,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     359,   267,   270,   359,   375,     6,   270,   271,     6,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   275,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   275,   275,   275,   275,   275,   267,   269,   269,   376,
     275,   275,   301,   275,   301,   275,   275,   275,   267,   376,
     359,   359,   359,   361,   301,   271,   271,   271,   359,   359,
     359,   270,   359,   359,   275,   275,   301,   301,   267,   272,
     267,   272,   275,   300,   362,   271,     7,   302,   301,   372,
     271,     8,     8,   376,   272,   267,   269,   266,   268,   299,
     300,   376,     7,   270,   270,   267,   267,   267,   359,   372,
       4,   351,     6,   318,   359,   381,   267,   271,   267,   267,
     359,   271,   271,   376,   272,   271,   330,   271,   271,   369,
     359,   359,   271,   271,   359,   369,   149,   149,   168,   179,
     180,   181,   185,   186,   344,   345,   369,   271,   340,   267,
     271,   267,   267,   267,   267,   267,   267,   267,   270,   270,
       7,   359,     6,   359,   267,   271,   269,   271,   269,   271,
     271,   271,   271,     6,   271,   269,   269,   275,   267,     7,
     267,     7,     7,   272,   359,   271,   359,   359,   272,   266,
     268,     7,   272,   301,   275,   301,   301,   267,   267,   275,
     301,   301,   275,   275,   301,   301,   301,   301,   359,   301,
       9,   382,   275,   267,   275,   301,   272,   275,   363,   269,
     271,   267,   271,   274,   202,     7,   171,     6,   359,   271,
     270,     6,   372,   271,   359,     6,     7,   298,   299,   272,
     298,   299,   302,   270,   378,   390,   381,   359,     6,   271,
      50,    50,   372,   271,     4,   189,   190,   191,   192,   271,
     286,   290,   293,   295,   296,   338,   272,   267,   269,   266,
     359,   359,   266,   270,   266,   270,     8,   376,   380,   267,
     272,   267,   269,   266,   267,   267,   275,   272,   266,   271,
     275,     7,   300,     4,    26,    37,    38,   312,   313,   314,
     301,   359,   301,   369,   372,   372,     7,   372,   372,   372,
       7,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,     6,     7,   376,   329,   359,   359,   359,   359,   359,
     359,   271,   359,   359,   359,   372,   380,   380,   271,   271,
     271,   271,   275,   311,   271,   271,   271,   359,   271,   271,
     359,   359,   302,   302,   359,   359,   267,   372,   300,   359,
     359,   271,   302,   299,   272,   299,   359,   359,   301,   271,
     372,   376,   376,     7,     7,     7,   149,   350,     6,   267,
     275,     7,     7,     7,     6,     7,     7,   271,     4,   302,
     271,   275,   275,   275,   271,   271,   123,     4,     6,   359,
     270,     6,   266,     6,   187,     6,   187,   271,   345,   275,
     344,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     329,   329,   372,     6,   270,   105,     6,     6,     6,   111,
       7,     7,     6,     6,   359,     7,   372,     7,   372,   372,
       4,   275,     8,     8,   267,   302,   302,   302,   376,   380,
     359,   380,   273,   275,   315,   380,   380,   302,   380,   267,
     275,     6,   270,   324,   270,     6,   359,     6,   270,   372,
     271,   271,   359,     6,   199,   200,   302,   359,     6,     7,
     377,   379,     6,   268,     6,     6,   301,   300,   300,     6,
     287,   266,   266,   270,   297,     6,   302,   272,   380,   359,
     269,   267,   359,     8,   376,   359,   376,   271,   271,     6,
       6,   280,   302,   272,   359,     6,     6,   359,   302,   267,
       6,   359,   270,   359,   381,   301,    50,   270,   372,   381,
     384,   359,   359,   359,   269,   275,     6,   267,     6,     6,
     142,   320,   320,   372,     6,     6,     6,   372,   149,   202,
     319,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   271,   271,   301,   301,   301,   301,   301,   301,   301,
     275,   275,   275,   267,   301,   301,   313,   301,   129,   129,
     129,   271,   202,   267,   301,   267,   300,   362,   301,     6,
     301,   266,   268,   300,   302,   267,   269,   301,     6,   271,
     271,   372,   372,   372,     4,     6,   298,   359,   372,   372,
     372,   270,   270,     7,     6,     7,   359,   359,   359,   270,
     270,   270,   268,     6,   359,   372,   359,     6,     6,   359,
     369,   271,     5,   372,   270,   270,   270,   270,   270,   270,
     270,   372,   271,   271,     6,   376,   270,   270,   359,   359,
     269,   372,     6,   372,     6,   198,   359,   359,   359,   266,
     268,     6,     6,     7,   301,   275,   275,   301,   275,   359,
       4,   214,   316,   317,   301,   267,   301,   363,   381,   359,
     270,   330,     6,   330,   275,     6,     6,   272,     7,     7,
     298,   299,     6,   377,   271,   275,   359,   298,   270,   301,
     385,   386,   387,   385,   266,   359,   359,   371,   372,   270,
     266,     4,     6,   267,     6,   267,   271,   271,   267,   271,
       6,     6,   380,   266,     4,   267,   275,   266,   271,   275,
     372,   381,     7,   300,   310,   359,   375,   314,     6,   369,
       6,     6,     6,   149,   321,   105,   124,   109,     6,     5,
     270,     6,   359,   359,   359,   270,   270,   270,   111,   359,
     267,   362,   359,   359,   301,   299,   270,   270,     6,   319,
       6,   359,   372,   149,   149,     4,     6,   376,   376,   359,
     359,   381,   271,   267,   271,   275,   329,   329,   359,   359,
     271,   275,   267,   271,   275,     6,     6,   371,   369,   369,
     369,   369,   369,   255,   369,     6,   271,   376,   359,     6,
       6,     6,     6,     6,   372,   271,   275,     8,   271,   267,
     255,   270,   359,   373,   381,   380,   359,   380,   359,   381,
     384,   386,   381,   275,   267,   275,   271,   359,   347,   347,
     372,   302,   378,   381,   359,     6,     6,   377,   269,   372,
     387,     6,   301,   301,   284,   359,   275,   275,   271,   275,
     285,   359,   359,     6,     6,     6,     6,   359,   359,   267,
       6,   359,   306,   308,   270,   386,   271,   275,     7,     7,
     153,     6,   270,   270,   270,     5,   371,   301,   301,   275,
     359,   359,   359,   270,   301,   267,   267,   269,   376,   376,
       6,     6,   359,   359,   270,   271,   271,   270,     6,     6,
     270,   359,   271,   271,   271,   269,     6,   372,     7,   270,
     359,   271,   275,   275,   275,   275,   275,   275,     6,   271,
     271,   197,   359,   359,   270,   271,   376,     6,     6,     6,
     267,   301,   301,   317,   381,   271,   271,   271,   271,     7,
       6,     6,     6,   272,     6,   271,     6,     6,   267,   275,
     359,   359,   270,   372,   271,   275,   267,   267,   275,   271,
     311,   315,   372,   301,   359,   381,   390,   376,   376,   359,
       6,   271,   359,   275,   271,   275,   359,   362,   271,   271,
       6,     6,   371,   154,   155,   160,   354,   154,   155,   354,
     376,   329,   271,   275,     6,   271,   372,   330,   271,     6,
     376,   369,   369,   369,   369,   369,     6,   359,   271,   271,
     376,   271,   267,     6,   270,     6,   377,   200,   288,   359,
     275,   275,   371,     6,   359,   359,     6,   271,   271,   307,
       7,   266,   271,   271,   271,   270,   275,   359,   359,   271,
     267,   270,   271,   270,   369,   372,     6,   270,   369,     6,
     271,   271,   359,     6,   149,   271,   341,   270,   271,   275,
     275,   275,   275,   275,     6,   271,     6,   330,     6,   270,
     359,   359,   271,   275,   311,   381,   267,   359,   359,   271,
     271,   376,     6,   369,     6,   369,     6,     6,   271,   359,
     344,   330,     6,   376,   376,   376,   376,   369,   376,   347,
     285,   267,   275,     6,   270,   359,   271,   275,   275,   271,
     275,   275,     6,   271,   271,   342,   271,   271,   271,   271,
     275,   271,   271,   271,   291,   359,   371,   271,   359,   359,
     369,   369,   344,     6,     6,     6,     6,   376,     6,     6,
       6,   270,   267,   271,     6,   271,   301,   275,   275,   271,
     271,   289,   380,   294,   270,     6,   359,   359,     6,   271,
     275,   270,   371,   271,   271,     6,   380,   292,   380,   271,
       6,     6,   271,   275,     6,     6,   380
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   276,   277,   277,   278,   278,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   280,   280,   281,   281,
     281,   281,   281,   281,   281,   281,   282,   282,   282,   282,
     283,   283,   283,   283,   283,   283,   283,   284,   284,   285,
     285,   287,   288,   286,   289,   289,   291,   290,   292,   292,
     294,   293,   295,   295,   297,   296,   298,   298,   298,   298,
     298,   299,   299,   300,   300,   301,   301,   302,   302,   302,
     302,   302,   302,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   304,   304,
     305,   305,   305,   306,   305,   307,   305,   305,   308,   305,
     309,   309,   310,   310,   310,   311,   311,   312,   312,   313,
     313,   314,   314,   314,   314,   314,   314,   314,   314,   315,
     315,   316,   316,   317,   317,   317,   317,   317,   318,   318,
     318,   319,   319,   319,   319,   320,   320,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   323,   322,   324,   324,   324,
     324,   324,   325,   325,   325,   325,   326,   326,   326,   327,
     327,   327,   327,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   329,   329,   330,   330,   330,   330,
     330,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   332,   332,   332,   332,   332,
     332,   332,   332,   333,   333,   334,   335,   335,   335,   335,
     335,   335,   335,   335,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   337,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   339,   339,   339,   340,   339,   341,   339,   342,   339,
     343,   339,   339,   339,   339,   339,   339,   344,   344,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     346,   346,   346,   346,   346,   347,   347,   347,   347,   347,
     348,   348,   349,   350,   350,   351,   351,   352,   352,   353,
     353,   354,   354,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     356,   356,   356,   356,   357,   357,   357,   358,   358,   358,
     358,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   361,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   362,
     362,   363,   363,   365,   364,   366,   366,   367,   367,   368,
     368,   369,   369,   369,   369,   369,   370,   370,   370,   370,
     371,   371,   372,   372,   372,   372,   372,   372,   373,   373,
     373,   374,   374,   374,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   376,   376,   376,   376,   377,   377,   377,
     377,   378,   378,   379,   379,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   382,   381,   381,   383,
     383,   384,   385,   385,   386,   387,   387,   387,   387,   388,
     388,   388,   389,   389,   389,   390,   390,   390
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     7,     7,     7,     7,     9,     6,     6,     6,     8,
       0,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       3,     0,     0,    10,     1,     3,     0,    13,     1,     3,
       0,    15,     8,    14,     0,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     2,     7,     7,     4,     3,
       6,     9,     7,     6,     7,     6,     4,     8,     9,     9,
       6,     9,     6,     9,     5,     8,     8,    11,     6,     9,
       5,     7,     9,     9,     9,     7,     9,     9,     0,     1,
       0,     3,     5,     0,     9,     0,    11,     5,     0,     9,
       0,     3,     3,     5,     5,     0,     2,     0,     1,     1,
       3,     2,     2,     2,     2,     1,     4,     2,     2,     0,
       2,     1,     3,     2,     2,     2,     2,     2,     1,     1,
       3,     0,     5,     5,     5,     0,     2,     0,     2,     7,
       7,     7,    10,    10,     8,     8,     7,     7,    11,     7,
       8,     8,     8,     9,     8,     8,     3,     4,    10,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     9,
       7,     7,     8,     8,    12,     0,     9,     1,     1,     1,
       1,     4,     1,     1,     1,     4,     1,     1,     4,     1,
       1,     1,     4,     5,    11,     5,     9,     9,     7,     7,
       4,     9,    10,     9,     1,     1,     0,     2,     6,     7,
       7,     6,     7,     8,    10,    14,    16,    12,    14,    14,
      14,    14,     8,     8,     6,     4,     5,     5,     6,     6,
       3,     4,     3,     5,     6,     5,     4,     3,     4,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     2,
       7,     3,     2,     3,     2,     2,     2,     2,    15,     2,
       2,     7,     2,     9,    11,     2,     4,     2,     2,     2,
       2,     2,     2,    16,     5,     8,    11,     6,     8,     8,
      10,     1,     2,     2,     1,     3,     3,     4,     4,     1,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     9,     2,     3,    10,    13,     1,     2,     5,
       7,     2,     2,     3,     2,     3,     2,     3,     9,     6,
       1,     1,     1,     1,     1,     0,     2,     3,     3,     4,
       9,     4,    14,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     5,     6,     7,     6,     5,     3,     8,
       6,     8,     8,     5,     4,     6,    11,    11,    18,    18,
      12,    12,    12,    10,     4,     4,     4,     4,     4,     6,
       2,     3,     6,     2,     1,     1,     1,     2,     5,     7,
      10,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     6,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     1,     4,     6,     1,     4,     4,
       4,     6,     5,     7,     8,    10,     4,     4,     6,     4,
       3,     2,     5,     5,     3,     5,     6,     8,     6,     8,
       6,     4,     7,     6,     6,     6,     4,     6,     4,     0,
       2,     0,     2,     0,     7,     1,     3,     1,     2,     0,
       3,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     2,     3,
       4,     1,     3,     1,     2,     3,     3,     5,     4,     4,
       2,     4,     2,     3,     3,     4,     5,     5,     5,     5,
       6,    11,    11,     9,    10,     5,     1,     1,     1,     3,
       5,     7,     4,     4,     4,     6,     6,     8,     8,     4,
      14,     4,     4,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     4,     4,     3,
       5,     6,     8,     6,     4,     5,     1,     4,     1,     1,
       1,     1,     4,     6,     4,     6,     5,     7,     4,     4,
       4,     8,     4,     4,     4,     4,     8,     8,     6,     4,
       6,     4,     1,     1,     4,     4,     0,     6,     4,     2,
       4,     4,     1,     1,     3,     1,     1,     3,     3,     3,
       5,     7,     5,     5,     8,     1,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* All: error tEND  */
#line 276 "Gmsh.y"
               { yyerrok; return 1; }
#line 6453 "Gmsh.tab.cpp"
    break;

  case 6: /* GeoFormatItem: Printf  */
#line 287 "Gmsh.y"
                { return 1; }
#line 6459 "Gmsh.tab.cpp"
    break;

  case 7: /* GeoFormatItem: View  */
#line 288 "Gmsh.y"
                { return 1; }
#line 6465 "Gmsh.tab.cpp"
    break;

  case 8: /* GeoFormatItem: Affectation  */
#line 289 "Gmsh.y"
                { return 1; }
#line 6471 "Gmsh.tab.cpp"
    break;

  case 9: /* GeoFormatItem: tSetFactory '(' StringExprVar ')' tEND  */
#line 291 "Gmsh.y"
    {
      // synchronize with GModel before switching kernel
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      gmsh_yyfactory = (yyvsp[-2].c);
      if(gmsh_yyfactory == "OpenCASCADE"){
        if(!GModel::current()->getOCCInternals())
          GModel::current()->createOCCInternals();
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getOCCInternals()->setMaxTag
            (dim, std::max(GModel::current()->getOCCInternals()->getMaxTag(dim),
                           GModel::current()->getGEOInternals()->getMaxTag(dim)));
      }
      else {
        if(gmsh_yyfactory != "Built-in" && gmsh_yyfactory != "Gmsh")
          yymsg(1, "Unknown factory \"%s\" - using \"Built-in\" instead", (yyvsp[-2].c));
        if(GModel::current()->getOCCInternals()){
          for(int dim = -2; dim <= 3; dim++)
            GModel::current()->getGEOInternals()->setMaxTag
              (dim, std::max(GModel::current()->getGEOInternals()->getMaxTag(dim),
                             GModel::current()->getOCCInternals()->getMaxTag(dim)));
        }
      }
      Free((yyvsp[-2].c));
    }
#line 6504 "Gmsh.tab.cpp"
    break;

  case 10: /* GeoFormatItem: Shape  */
#line 319 "Gmsh.y"
                { return 1; }
#line 6510 "Gmsh.tab.cpp"
    break;

  case 11: /* GeoFormatItem: Transform  */
#line 320 "Gmsh.y"
                { List_Delete((yyvsp[0].l)); return 1; }
#line 6516 "Gmsh.tab.cpp"
    break;

  case 12: /* GeoFormatItem: Delete  */
#line 321 "Gmsh.y"
                { return 1; }
#line 6522 "Gmsh.tab.cpp"
    break;

  case 13: /* GeoFormatItem: Colorify  */
#line 322 "Gmsh.y"
                { return 1; }
#line 6528 "Gmsh.tab.cpp"
    break;

  case 14: /* GeoFormatItem: SetPartition  */
#line 323 "Gmsh.y"
                { return 1; }
#line 6534 "Gmsh.tab.cpp"
    break;

  case 15: /* GeoFormatItem: Visibility  */
#line 324 "Gmsh.y"
                { return 1; }
#line 6540 "Gmsh.tab.cpp"
    break;

  case 16: /* GeoFormatItem: Extrude  */
#line 325 "Gmsh.y"
                { List_Delete((yyvsp[0].l)); return 1; }
#line 6546 "Gmsh.tab.cpp"
    break;

  case 17: /* GeoFormatItem: Boolean  */
#line 326 "Gmsh.y"
                { List_Delete((yyvsp[0].l)); return 1; }
#line 6552 "Gmsh.tab.cpp"
    break;

  case 18: /* GeoFormatItem: BooleanShape  */
#line 327 "Gmsh.y"
                { return 1; }
#line 6558 "Gmsh.tab.cpp"
    break;

  case 19: /* GeoFormatItem: Constraints  */
#line 328 "Gmsh.y"
                { return 1; }
#line 6564 "Gmsh.tab.cpp"
    break;

  case 20: /* GeoFormatItem: Coherence  */
#line 329 "Gmsh.y"
                { return 1; }
#line 6570 "Gmsh.tab.cpp"
    break;

  case 21: /* GeoFormatItem: Loop  */
#line 330 "Gmsh.y"
                { return 1; }
#line 6576 "Gmsh.tab.cpp"
    break;

  case 22: /* GeoFormatItem: Slide  */
#line 331 "Gmsh.y"
                { return 1; }
#line 6582 "Gmsh.tab.cpp"
    break;

  case 23: /* GeoFormatItem: Command  */
#line 332 "Gmsh.y"
                { return 1; }
#line 6588 "Gmsh.tab.cpp"
    break;

  case 24: /* GeoFormatItem: LevelSet  */
#line 333 "Gmsh.y"
                { return 1; }
#line 6594 "Gmsh.tab.cpp"
    break;

  case 25: /* GeoFormatItem: Homology  */
#line 334 "Gmsh.y"
                { return 1; }
#line 6600 "Gmsh.tab.cpp"
    break;

  case 26: /* SendToFile: '>'  */
#line 339 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
#line 6608 "Gmsh.tab.cpp"
    break;

  case 27: /* SendToFile: tGREATERGREATER  */
#line 343 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
#line 6616 "Gmsh.tab.cpp"
    break;

  case 28: /* Printf: tPrintf '(' StringExprVar ')' tEND  */
#line 350 "Gmsh.y"
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6625 "Gmsh.tab.cpp"
    break;

  case 29: /* Printf: tWarning '(' StringExprVar ')' tEND  */
#line 355 "Gmsh.y"
    {
      Msg::Warning((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6634 "Gmsh.tab.cpp"
    break;

  case 30: /* Printf: tError '(' StringExprVar ')' tEND  */
#line 360 "Gmsh.y"
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6643 "Gmsh.tab.cpp"
    break;

  case 31: /* Printf: tPrintf '(' StringExprVar ')' SendToFile StringExprVar tEND  */
#line 365 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      FILE *fp = Fopen(tmp.c_str(), (yyvsp[-2].c));
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmp.c_str());
      }
      else{
	fprintf(fp, "%s\n", (yyvsp[-4].c));
	fclose(fp);
      }
      Free((yyvsp[-4].c));
      Free((yyvsp[-1].c));
    }
#line 6661 "Gmsh.tab.cpp"
    break;

  case 32: /* Printf: tPrintf '(' StringExprVar ',' RecursiveListOfDouble ')' tEND  */
#line 379 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring.c_str());
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    }
#line 6678 "Gmsh.tab.cpp"
    break;

  case 33: /* Printf: tWarning '(' StringExprVar ',' RecursiveListOfDouble ')' tEND  */
#line 392 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0)
	yymsg(1, "Too few arguments in Error");
      else if(i > 0)
	yymsg(1, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Warning(tmpstring.c_str());
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    }
#line 6695 "Gmsh.tab.cpp"
    break;

  case 34: /* Printf: tError '(' StringExprVar ',' RecursiveListOfDouble ')' tEND  */
#line 405 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring.c_str());
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    }
#line 6712 "Gmsh.tab.cpp"
    break;

  case 35: /* Printf: tPrintf '(' StringExprVar ',' RecursiveListOfDouble ')' SendToFile StringExprVar tEND  */
#line 418 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[-6].c), (yyvsp[-4].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	FILE *fp = Fopen(tmp.c_str(), (yyvsp[-2].c));
	if(!fp){
	  yymsg(0, "Unable to open file '%s'", tmp.c_str());
	}
	else{
	  fprintf(fp, "%s\n", tmpstring.c_str());
	  fclose(fp);
	}
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[-4].l));
    }
#line 6739 "Gmsh.tab.cpp"
    break;

  case 36: /* View: String__Index StringExprVar '{' Views '}' tEND  */
#line 446 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-5].c), "View") && ViewData->finalize()){
	ViewData->setName((yyvsp[-4].c));
	ViewData->setFileName(gmsh_yyname);
	ViewData->setFileIndex(gmsh_yyviewindex++);
	new PView(ViewData);
      }
      else
	delete ViewData;
#endif
      Free((yyvsp[-5].c)); Free((yyvsp[-4].c));
    }
#line 6757 "Gmsh.tab.cpp"
    break;

  case 37: /* View: tAlias tSTRING '[' FExpr ']' tEND  */
#line 460 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-4].c), "View")){
	int index = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[-4].c));
    }
#line 6774 "Gmsh.tab.cpp"
    break;

  case 38: /* View: tAliasWithOptions tSTRING '[' FExpr ']' tEND  */
#line 473 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-4].c), "View")){
	int index = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[-4].c));
    }
#line 6791 "Gmsh.tab.cpp"
    break;

  case 39: /* View: tCopyOptions tSTRING '[' FExpr ',' FExpr ']' tEND  */
#line 486 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-6].c), "View")){
	int index = (int)(yyvsp[-4].d), index2 = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size() &&
           index2 >= 0 && index2 < (int)PView::list.size()){
          PView::list[index2]->setOptions(PView::list[index]->getOptions());
        }
        else
	  yymsg(0, "Unknown view %d or %d", index, index2);
      }
#endif
      Free((yyvsp[-6].c));
    }
#line 6810 "Gmsh.tab.cpp"
    break;

  case 40: /* Views: %empty  */
#line 504 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 6820 "Gmsh.tab.cpp"
    break;

  case 47: /* ElementCoords: FExpr  */
#line 519 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6826 "Gmsh.tab.cpp"
    break;

  case 48: /* ElementCoords: ElementCoords ',' FExpr  */
#line 521 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6832 "Gmsh.tab.cpp"
    break;

  case 49: /* ElementValues: FExpr  */
#line 526 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6838 "Gmsh.tab.cpp"
    break;

  case 50: /* ElementValues: ElementValues ',' FExpr  */
#line 528 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6844 "Gmsh.tab.cpp"
    break;

  case 51: /* $@1: %empty  */
#line 533 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strncmp((yyvsp[0].c), "SP", 2)){
	ViewValueList = &ViewData->SP; ViewNumList = &ViewData->NbSP;
      }
      else if(!strncmp((yyvsp[0].c), "VP", 2)){
	ViewValueList = &ViewData->VP; ViewNumList = &ViewData->NbVP;
      }
      else if(!strncmp((yyvsp[0].c), "TP", 2)){
	ViewValueList = &ViewData->TP; ViewNumList = &ViewData->NbTP;
      }
      else if(!strncmp((yyvsp[0].c), "SL", 2)){
	ViewValueList = &ViewData->SL; ViewNumList = &ViewData->NbSL;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[0].c), "VL", 2)){
	ViewValueList = &ViewData->VL; ViewNumList = &ViewData->NbVL;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[0].c), "TL", 2)){
	ViewValueList = &ViewData->TL; ViewNumList = &ViewData->NbTL;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[0].c), "ST", 2)){
	ViewValueList = &ViewData->ST; ViewNumList = &ViewData->NbST;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[0].c), "VT", 2)){
	ViewValueList = &ViewData->VT; ViewNumList = &ViewData->NbVT;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[0].c), "TT", 2)){
	ViewValueList = &ViewData->TT; ViewNumList = &ViewData->NbTT;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[0].c), "SQ", 2)){
	ViewValueList = &ViewData->SQ; ViewNumList = &ViewData->NbSQ;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[0].c), "VQ", 2)){
	ViewValueList = &ViewData->VQ; ViewNumList = &ViewData->NbVQ;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[0].c), "TQ", 2)){
	ViewValueList = &ViewData->TQ; ViewNumList = &ViewData->NbTQ;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[0].c), "SS", 2)){
	ViewValueList = &ViewData->SS; ViewNumList = &ViewData->NbSS;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[0].c), "VS", 2)){
	ViewValueList = &ViewData->VS; ViewNumList = &ViewData->NbVS;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[0].c), "TS", 2)){
	ViewValueList = &ViewData->TS; ViewNumList = &ViewData->NbTS;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[0].c), "SH", 2)){
	ViewValueList = &ViewData->SH; ViewNumList = &ViewData->NbSH;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[0].c), "VH", 2)){
	ViewValueList = &ViewData->VH; ViewNumList = &ViewData->NbVH;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[0].c), "TH", 2)){
	ViewValueList = &ViewData->TH; ViewNumList = &ViewData->NbTH;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[0].c), "SI", 2)){
	ViewValueList = &ViewData->SI; ViewNumList = &ViewData->NbSI;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[0].c), "VI", 2)){
	ViewValueList = &ViewData->VI; ViewNumList = &ViewData->NbVI;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[0].c), "TI", 2)){
	ViewValueList = &ViewData->TI; ViewNumList = &ViewData->NbTI;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[0].c), "SY", 2)){
	ViewValueList = &ViewData->SY; ViewNumList = &ViewData->NbSY;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[0].c), "VY", 2)){
	ViewValueList = &ViewData->VY; ViewNumList = &ViewData->NbVY;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[0].c), "TY", 2)){
	ViewValueList = &ViewData->TY; ViewNumList = &ViewData->NbTY;
        if(strlen((yyvsp[0].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else{
	yymsg(0, "Unknown element type '%s'", (yyvsp[0].c));
	ViewValueList = 0; ViewNumList = 0;
      }
#endif
      ViewCoord.clear();
      Free((yyvsp[0].c));
    }
#line 6952 "Gmsh.tab.cpp"
    break;

  case 52: /* $@2: %empty  */
#line 637 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(std::size_t j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 6966 "Gmsh.tab.cpp"
    break;

  case 53: /* Element: tSTRING $@1 '(' ElementCoords ')' $@2 '{' ElementValues '}' tEND  */
#line 647 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 6976 "Gmsh.tab.cpp"
    break;

  case 54: /* Text2DValues: StringExprVar  */
#line 656 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6987 "Gmsh.tab.cpp"
    break;

  case 55: /* Text2DValues: Text2DValues ',' StringExprVar  */
#line 663 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6998 "Gmsh.tab.cpp"
    break;

  case 56: /* $@3: %empty  */
#line 673 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 7011 "Gmsh.tab.cpp"
    break;

  case 57: /* Text2D: tText2D '(' FExpr ',' FExpr ',' FExpr ')' $@3 '{' Text2DValues '}' tEND  */
#line 682 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 7021 "Gmsh.tab.cpp"
    break;

  case 58: /* Text3DValues: StringExprVar  */
#line 691 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 7032 "Gmsh.tab.cpp"
    break;

  case 59: /* Text3DValues: Text3DValues ',' StringExprVar  */
#line 698 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 7043 "Gmsh.tab.cpp"
    break;

  case 60: /* $@4: %empty  */
#line 708 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 7055 "Gmsh.tab.cpp"
    break;

  case 61: /* Text3D: tText3D '(' FExpr ',' FExpr ',' FExpr ',' FExpr ')' $@4 '{' Text3DValues '}' tEND  */
#line 716 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 7065 "Gmsh.tab.cpp"
    break;

  case 62: /* InterpolationMatrix: tInterpolationScheme '{' RecursiveListOfListOfDouble '}' '{' RecursiveListOfListOfDouble '}' tEND  */
#line 726 "Gmsh.y"
    {
#if defined(HAVE_POST)
      int type =
	(ViewData->NbSL || ViewData->NbVL) ? TYPE_LIN :
	(ViewData->NbST || ViewData->NbVT) ? TYPE_TRI :
	(ViewData->NbSQ || ViewData->NbVQ) ? TYPE_QUA :
	(ViewData->NbSS || ViewData->NbVS) ? TYPE_TET :
	(ViewData->NbSY || ViewData->NbVY) ? TYPE_PYR :
	(ViewData->NbSI || ViewData->NbVI) ? TYPE_PRI :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[-5].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[-2].l)));
#endif
    }
#line 7085 "Gmsh.tab.cpp"
    break;

  case 63: /* InterpolationMatrix: tInterpolationScheme '{' RecursiveListOfListOfDouble '}' '{' RecursiveListOfListOfDouble '}' '{' RecursiveListOfListOfDouble '}' '{' RecursiveListOfListOfDouble '}' tEND  */
#line 745 "Gmsh.y"
    {
#if defined(HAVE_POST)
      int type =
	(ViewData->NbSL || ViewData->NbVL) ? TYPE_LIN :
	(ViewData->NbST || ViewData->NbVT) ? TYPE_TRI :
	(ViewData->NbSQ || ViewData->NbVQ) ? TYPE_QUA :
	(ViewData->NbSS || ViewData->NbVS) ? TYPE_TET :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[-11].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[-8].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[-5].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[-2].l)));
#endif
    }
#line 7105 "Gmsh.tab.cpp"
    break;

  case 64: /* $@5: %empty  */
#line 764 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 7115 "Gmsh.tab.cpp"
    break;

  case 65: /* Time: tTime $@5 '{' ElementValues '}' tEND  */
#line 770 "Gmsh.y"
    {
    }
#line 7122 "Gmsh.tab.cpp"
    break;

  case 66: /* NumericAffectation: tAFFECT  */
#line 777 "Gmsh.y"
                   { (yyval.i) = 0; }
#line 7128 "Gmsh.tab.cpp"
    break;

  case 67: /* NumericAffectation: tAFFECTPLUS  */
#line 778 "Gmsh.y"
                   { (yyval.i) = 1; }
#line 7134 "Gmsh.tab.cpp"
    break;

  case 68: /* NumericAffectation: tAFFECTMINUS  */
#line 779 "Gmsh.y"
                   { (yyval.i) = 2; }
#line 7140 "Gmsh.tab.cpp"
    break;

  case 69: /* NumericAffectation: tAFFECTTIMES  */
#line 780 "Gmsh.y"
                   { (yyval.i) = 3; }
#line 7146 "Gmsh.tab.cpp"
    break;

  case 70: /* NumericAffectation: tAFFECTDIVIDE  */
#line 781 "Gmsh.y"
                   { (yyval.i) = 4; }
#line 7152 "Gmsh.tab.cpp"
    break;

  case 71: /* NumericIncrement: tPLUSPLUS  */
#line 785 "Gmsh.y"
                   { (yyval.i) = 1; }
#line 7158 "Gmsh.tab.cpp"
    break;

  case 72: /* NumericIncrement: tMINUSMINUS  */
#line 786 "Gmsh.y"
                   { (yyval.i) = -1; }
#line 7164 "Gmsh.tab.cpp"
    break;

  case 73: /* LP: '('  */
#line 792 "Gmsh.y"
         { (yyval.c) = (char*)"("; }
#line 7170 "Gmsh.tab.cpp"
    break;

  case 74: /* LP: '['  */
#line 792 "Gmsh.y"
                                    { (yyval.c) = (char*)"["; }
#line 7176 "Gmsh.tab.cpp"
    break;

  case 75: /* RP: ')'  */
#line 794 "Gmsh.y"
         { (yyval.c) = (char*)")"; }
#line 7182 "Gmsh.tab.cpp"
    break;

  case 76: /* RP: ']'  */
#line 794 "Gmsh.y"
                                    { (yyval.c) = (char*)"]"; }
#line 7188 "Gmsh.tab.cpp"
    break;

  case 77: /* tSTRING_Reserved: tSTRING  */
#line 799 "Gmsh.y"
             { (yyval.c) = (yyvsp[0].c); }
#line 7194 "Gmsh.tab.cpp"
    break;

  case 78: /* tSTRING_Reserved: tMin  */
#line 800 "Gmsh.y"
             { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); }
#line 7200 "Gmsh.tab.cpp"
    break;

  case 79: /* tSTRING_Reserved: tMax  */
#line 801 "Gmsh.y"
             { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); }
#line 7206 "Gmsh.tab.cpp"
    break;

  case 80: /* tSTRING_Reserved: tStep  */
#line 802 "Gmsh.y"
             { (yyval.c) = (char *)Malloc(5 * sizeof(char)); strcpy((yyval.c), "Step"); }
#line 7212 "Gmsh.tab.cpp"
    break;

  case 81: /* tSTRING_Reserved: tBox  */
#line 803 "Gmsh.y"
             { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); }
#line 7218 "Gmsh.tab.cpp"
    break;

  case 82: /* tSTRING_Reserved: tCylinder  */
#line 804 "Gmsh.y"
             { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); }
#line 7224 "Gmsh.tab.cpp"
    break;

  case 86: /* Affectation: tSetNumber LP StringExpr ',' FExpr RP tEND  */
#line 814 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 7233 "Gmsh.tab.cpp"
    break;

  case 87: /* Affectation: tSetString LP StringExpr ',' StringExpr RP tEND  */
#line 819 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 7243 "Gmsh.tab.cpp"
    break;

  case 88: /* Affectation: String__Index NumericAffectation ListOfDouble tEND  */
#line 825 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[-3].c)) && (yyvsp[-2].i) && List_Nbr((yyvsp[-1].l)) == 1){
        yymsg(0, "Unknown variable '%s'", (yyvsp[-3].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-3].c)]);
        if(!(yyvsp[-2].i)) s.list = (List_Nbr((yyvsp[-1].l)) != 1); // list if 0 or > 1 elements
        if(!s.list){ // single expression
          if(List_Nbr((yyvsp[-1].l)) != 1){
            yymsg(0, "Cannot assign list to variable '%s'", (yyvsp[-3].c));
          }
          else{
            double d;
            List_Read((yyvsp[-1].l), 0, &d);
            if(s.value.empty()){
              if((yyvsp[-2].i)) yymsg(1, "Uninitialized variable '%s'", (yyvsp[-3].c));
              s.value.resize(1, 0.);
            }
            switch((yyvsp[-2].i)){
            case 0 : s.value[0] = d; break;
            case 1 : s.value[0] += d; break;
            case 2 : s.value[0] -= d; break;
            case 3 : s.value[0] *= d; break;
            case 4 :
              if(d) s.value[0] /= d;
              else yymsg(0, "Division by zero in '%s /= %g'", (yyvsp[-3].c), d);
              break;
            }
          }
        }
        else{
          // list of expressions; this is not recommended (should use [] or ()
          // notation instead)
          switch((yyvsp[-2].i)){
          case 0: // affect
            s.value.clear(); // fall-through
          case 1: // append
            for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
              double d;
              List_Read((yyvsp[-1].l), i, &d);
              s.value.push_back(d);
            }
            break;
          case 2: // remove
            for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
              double d;
              List_Read((yyvsp[-1].l), i, &d);
              auto it = std::find(s.value.begin(), s.value.end(), d);
              if(it != s.value.end()) s.value.erase(it);
            }
            break;
          default:
            yymsg(0, "Operators *= and /= not available for lists");
            break;
          }
        }
      }
      Free((yyvsp[-3].c));
      List_Delete((yyvsp[-1].l));
    }
#line 7308 "Gmsh.tab.cpp"
    break;

  case 89: /* Affectation: String__Index NumericIncrement tEND  */
#line 886 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[-2].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
        if(!s.list && s.value.empty())
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[-2].c));
        else if(!s.list)
          s.value[0] += (yyvsp[-1].i);
        else
          yymsg(0, "Variable '%s' is a list", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c));
    }
#line 7327 "Gmsh.tab.cpp"
    break;

  case 90: /* Affectation: String__Index LP RP NumericAffectation ListOfDouble tEND  */
#line 901 "Gmsh.y"
    {
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-5].c)]);
      s.list = true;
      double d;
      switch((yyvsp[-2].i)){
      case 0: // affect
        s.value.clear(); // fall-through
      case 1: // append
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          List_Read((yyvsp[-1].l), i, &d);
          s.value.push_back(d);
        }
        break;
      case 2: // remove
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          List_Read((yyvsp[-1].l), i, &d);
          auto it = std::find(s.value.begin(), s.value.end(), d);
          if(it != s.value.end()) s.value.erase(it);
        }
        break;
      default:
        yymsg(0, "Operators *= and /= not available for lists");
        break;
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-1].l));
    }
#line 7359 "Gmsh.tab.cpp"
    break;

  case 91: /* Affectation: String__Index LP '{' RecursiveListOfDouble '}' RP NumericAffectation ListOfDouble tEND  */
#line 929 "Gmsh.y"
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 7370 "Gmsh.tab.cpp"
    break;

  case 92: /* Affectation: String__Index '[' FExpr ']' NumericAffectation FExpr tEND  */
#line 939 "Gmsh.y"
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 7379 "Gmsh.tab.cpp"
    break;

  case 93: /* Affectation: String__Index '[' FExpr ']' NumericIncrement tEND  */
#line 944 "Gmsh.y"
    {
      incrementVariable((yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 7388 "Gmsh.tab.cpp"
    break;

  case 94: /* Affectation: String__Index '(' FExpr ')' NumericAffectation FExpr tEND  */
#line 952 "Gmsh.y"
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 7397 "Gmsh.tab.cpp"
    break;

  case 95: /* Affectation: String__Index '(' FExpr ')' NumericIncrement tEND  */
#line 957 "Gmsh.y"
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 7406 "Gmsh.tab.cpp"
    break;

  case 96: /* Affectation: String__Index tAFFECT StringExpr tEND  */
#line 965 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 7416 "Gmsh.tab.cpp"
    break;

  case 97: /* Affectation: String__Index LP RP tAFFECT tStr LP RP tEND  */
#line 974 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 7425 "Gmsh.tab.cpp"
    break;

  case 98: /* Affectation: String__Index LP RP tAFFECT tStr LP BracedOrNotRecursiveListOfStringExprVar RP tEND  */
#line 979 "Gmsh.y"
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[-2].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[-8].c)] = s;
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 7441 "Gmsh.tab.cpp"
    break;

  case 99: /* Affectation: String__Index LP RP tAFFECTPLUS tStr LP BracedOrNotRecursiveListOfStringExprVar RP tEND  */
#line 991 "Gmsh.y"
    {
      if(gmsh_yystringsymbols.count((yyvsp[-8].c))){
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[-2].l), i);
          gmsh_yystringsymbols[(yyvsp[-8].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[-8].c));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-2].l));
    }
#line 7459 "Gmsh.tab.cpp"
    break;

  case 100: /* Affectation: String__Index '.' tSTRING_Reserved tAFFECT StringExpr tEND  */
#line 1008 "Gmsh.y"
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 7469 "Gmsh.tab.cpp"
    break;

  case 101: /* Affectation: String__Index '[' FExpr ']' '.' tSTRING_Reserved tAFFECT StringExpr tEND  */
#line 1014 "Gmsh.y"
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 7479 "Gmsh.tab.cpp"
    break;

  case 102: /* Affectation: String__Index '.' tSTRING_Reserved NumericAffectation FExpr tEND  */
#line 1023 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-5].c), 0, (yyvsp[-3].c), d)){
	switch((yyvsp[-2].i)){
	case 0 : d = (yyvsp[-1].d); break;
	case 1 : d += (yyvsp[-1].d); break;
	case 2 : d -= (yyvsp[-1].d); break;
	case 3 : d *= (yyvsp[-1].d); break;
	case 4 :
	  if((yyvsp[-1].d)) d /= (yyvsp[-1].d);
	  else yymsg(0, "Division by zero in '%s.%s /= %g'", (yyvsp[-5].c), (yyvsp[-3].c), (yyvsp[-1].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), d);
      }
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c));
    }
#line 7501 "Gmsh.tab.cpp"
    break;

  case 103: /* Affectation: String__Index '[' FExpr ']' '.' tSTRING_Reserved NumericAffectation FExpr tEND  */
#line 1041 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), d)){
	switch((yyvsp[-2].i)){
	case 0 : d = (yyvsp[-1].d); break;
	case 1 : d += (yyvsp[-1].d); break;
	case 2 : d -= (yyvsp[-1].d); break;
	case 3 : d *= (yyvsp[-1].d); break;
	case 4 :
	  if((yyvsp[-1].d)) d /= (yyvsp[-1].d);
	  else yymsg(0, "Division by zero in '%s[%d].%s /= %g'", (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), (yyvsp[-1].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), d);
      }
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c));
    }
#line 7523 "Gmsh.tab.cpp"
    break;

  case 104: /* Affectation: String__Index '.' tSTRING_Reserved NumericIncrement tEND  */
#line 1059 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 7536 "Gmsh.tab.cpp"
    break;

  case 105: /* Affectation: String__Index '[' FExpr ']' '.' tSTRING_Reserved NumericIncrement tEND  */
#line 1068 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 7549 "Gmsh.tab.cpp"
    break;

  case 106: /* Affectation: String__Index '.' tColor '.' tSTRING_Reserved tAFFECT ColorExpr tEND  */
#line 1080 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 7558 "Gmsh.tab.cpp"
    break;

  case 107: /* Affectation: String__Index '[' FExpr ']' '.' tColor '.' tSTRING_Reserved tAFFECT ColorExpr tEND  */
#line 1085 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 7567 "Gmsh.tab.cpp"
    break;

  case 108: /* Affectation: String__Index '.' tColorTable tAFFECT ListOfColor tEND  */
#line 1093 "Gmsh.y"
    {
      GmshColorTable *ct = GetColorTable(0);
      if(!ct)
	yymsg(0, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr((yyvsp[-1].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[-1].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-1].l));
    }
#line 7591 "Gmsh.tab.cpp"
    break;

  case 109: /* Affectation: String__Index '[' FExpr ']' '.' tColorTable tAFFECT ListOfColor tEND  */
#line 1113 "Gmsh.y"
    {
      GmshColorTable *ct = GetColorTable((int)(yyvsp[-6].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[-6].d));
      else{
	ct->size = List_Nbr((yyvsp[-1].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)(yyvsp[-6].d));
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[-1].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-1].l));
    }
#line 7615 "Gmsh.tab.cpp"
    break;

  case 110: /* Affectation: String__Index tField tAFFECT ListOfDouble tEND  */
#line 1136 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      if(!strcmp((yyvsp[-4].c),"Background")) {
	if(tags.size() > 1)
	  yymsg(0, "Only 1 field can be set as a background field.");
	else if(tags.size() == 0)
	  yymsg(1, "No field given (Background Field).");
	else
	  GModel::current()->getFields()->setBackgroundFieldId((int)tags[0]);
      }
      else if(!strcmp((yyvsp[-4].c),"BoundaryLayer"))
	GModel::current()->getFields()->addBoundaryLayerFieldId(tags);
      else
	yymsg(0, "Unknown command '%s Field'", (yyvsp[-4].c));
#endif
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-1].l));
    }
#line 7639 "Gmsh.tab.cpp"
    break;

  case 111: /* Affectation: tField '[' FExpr ']' tAFFECT tSTRING_Reserved tEND  */
#line 1156 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 7651 "Gmsh.tab.cpp"
    break;

  case 112: /* Affectation: tField '[' FExpr ']' '.' tSTRING_Reserved tAFFECT FExpr tEND  */
#line 1164 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-6].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-3].c)];
	if(option)
	  option->numericalValue((yyvsp[-1].d));
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-6].d));
#endif
      Free((yyvsp[-3].c));
    }
#line 7672 "Gmsh.tab.cpp"
    break;

  case 113: /* Affectation: tField '[' FExpr ']' '.' tSTRING_Reserved tAFFECT StringExpr tEND  */
#line 1181 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-6].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-3].c)];
	if(option)
	  option->string((yyvsp[-1].c));
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-6].d));
#endif
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 7694 "Gmsh.tab.cpp"
    break;

  case 114: /* Affectation: tField '[' FExpr ']' '.' tSTRING_Reserved tAFFECT ListOfDoubleWithBraces tEND  */
#line 1199 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-6].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-3].c)];
	if(option){
	  if(option->getType() == FIELD_OPTION_LIST) {
	    std::list<int> vl = option->list();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	      double id;
	      List_Read((yyvsp[-1].l), i, &id);
	      vl.push_back((int)id);
	    }
	    option->list(vl);
	  }
	  else {
	    std::list<double> vl = option->listdouble();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	      double id;
	      List_Read((yyvsp[-1].l), i, &id);
	      vl.push_back(id);
	    }
	    option->listdouble(vl);
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-6].d));
#endif
      Free((yyvsp[-3].c));
      List_Delete((yyvsp[-1].l));
    }
#line 7736 "Gmsh.tab.cpp"
    break;

  case 115: /* Affectation: tField '[' FExpr ']' '.' tSTRING_Reserved tEND  */
#line 1237 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-4].d));
      if(field){
        FieldCallback *callback = field->callbacks[(yyvsp[-1].c)];
        if(callback) {
          callback->run();
        }
        else
          yymsg(0, "Unknown callback '%s' in field %i of type '%s'",
              (yyvsp[-1].c), (int)(yyvsp[-4].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-4].d));
#endif
      Free((yyvsp[-1].c));
    }
#line 7758 "Gmsh.tab.cpp"
    break;

  case 116: /* Affectation: tPlugin '(' tSTRING ')' '.' tSTRING_Reserved tAFFECT FExpr tEND  */
#line 1258 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[-6].c), (yyvsp[-3].c), (yyvsp[-1].d));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[-3].c), (yyvsp[-6].c));
      }
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-3].c));
    }
#line 7774 "Gmsh.tab.cpp"
    break;

  case 117: /* Affectation: tPlugin '(' tSTRING ')' '.' tSTRING_Reserved tAFFECT StringExpr tEND  */
#line 1270 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[-6].c), (yyvsp[-3].c), (yyvsp[-1].c));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[-3].c), (yyvsp[-6].c));
      }
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 7790 "Gmsh.tab.cpp"
    break;

  case 121: /* DefineConstants: DefineConstants Comma String__Index  */
#line 1288 "Gmsh.y"
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 7803 "Gmsh.tab.cpp"
    break;

  case 122: /* DefineConstants: DefineConstants Comma String__Index tAFFECT FExpr  */
#line 1297 "Gmsh.y"
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 7816 "Gmsh.tab.cpp"
    break;

  case 123: /* $@6: %empty  */
#line 1306 "Gmsh.y"
    { init_options(); }
#line 7822 "Gmsh.tab.cpp"
    break;

  case 124: /* DefineConstants: DefineConstants Comma String__Index tAFFECT '{' ListOfDouble $@6 FloatParameterOptionsOrNone '}'  */
#line 1308 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-3].l)) != 1)
	yymsg(1, "List notation should be used to define list '%s[]'", (yyvsp[-6].c));
      std::string key((yyvsp[-6].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
        double d;
        List_Read((yyvsp[-3].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-6].c));
      List_Delete((yyvsp[-3].l));
    }
#line 7844 "Gmsh.tab.cpp"
    break;

  case 125: /* $@7: %empty  */
#line 1326 "Gmsh.y"
    { init_options(); }
#line 7850 "Gmsh.tab.cpp"
    break;

  case 126: /* DefineConstants: DefineConstants Comma String__Index LP RP tAFFECT '{' ListOfDouble $@7 FloatParameterOptionsOrNone '}'  */
#line 1328 "Gmsh.y"
    {
      std::string key((yyvsp[-8].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
        double d;
        List_Read((yyvsp[-3].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-3].l));
    }
#line 7870 "Gmsh.tab.cpp"
    break;

  case 127: /* DefineConstants: DefineConstants Comma String__Index tAFFECT StringExpr  */
#line 1344 "Gmsh.y"
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 7883 "Gmsh.tab.cpp"
    break;

  case 128: /* $@8: %empty  */
#line 1353 "Gmsh.y"
    { init_options(); }
#line 7889 "Gmsh.tab.cpp"
    break;

  case 129: /* DefineConstants: DefineConstants Comma String__Index tAFFECT '{' StringExpr $@8 CharParameterOptionsOrNone '}'  */
#line 1355 "Gmsh.y"
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 7903 "Gmsh.tab.cpp"
    break;

  case 131: /* UndefineConstants: UndefineConstants Comma StringExprVar  */
#line 1369 "Gmsh.y"
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 7913 "Gmsh.tab.cpp"
    break;

  case 132: /* Enumeration: FExpr tAFFECT StringExpr  */
#line 1377 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7923 "Gmsh.tab.cpp"
    break;

  case 133: /* Enumeration: Enumeration ',' FExpr tAFFECT StringExpr  */
#line 1383 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7932 "Gmsh.tab.cpp"
    break;

  case 134: /* Enumeration: FExpr_Multi tAFFECT String__Index '(' ')'  */
#line 1388 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      int n = List_Nbr((yyvsp[-4].l));
      if(!gmsh_yystringsymbols.count((yyvsp[-2].c))){
	yymsg(0, "Unknown string variable '%s'", (yyvsp[-2].c));
      }
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[-2].c)]);
        int m = s.size();
        if(n == m){
          for(int i = 0; i < n; i++){
            double d;
            List_Read((yyvsp[-4].l), i, &d);
            doubleXstring v = {d, strsave((char*)s[i].c_str())};
            List_Add((yyval.l), &v);
          }
        }
        else{
          yymsg(0, "Size mismatch in enumeration: %d != %d", n, m);
        }
      }
      List_Delete((yyvsp[-4].l));
      Free((yyvsp[-2].c));
    }
#line 7961 "Gmsh.tab.cpp"
    break;

  case 141: /* FloatParameterOption: tSTRING ListOfDouble  */
#line 1431 "Gmsh.y"
    {
      std::string key((yyvsp[-1].c));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
        double v;
        List_Read((yyvsp[0].l), i, &v);
        floatOptions[key].push_back(v);
        if(flag_Enum && !i) { member_ValMax = (int)v; }
      }
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[0].l));
    }
#line 7977 "Gmsh.tab.cpp"
    break;

  case 142: /* FloatParameterOption: tMin FExpr  */
#line 1443 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[0].d));
    }
#line 7985 "Gmsh.tab.cpp"
    break;

  case 143: /* FloatParameterOption: tMax FExpr  */
#line 1447 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[0].d));
    }
#line 7993 "Gmsh.tab.cpp"
    break;

  case 144: /* FloatParameterOption: tStep FExpr  */
#line 1451 "Gmsh.y"
    {
      floatOptions["Step"].push_back((yyvsp[0].d));
    }
#line 8001 "Gmsh.tab.cpp"
    break;

  case 145: /* FloatParameterOption: tSTRING  */
#line 1455 "Gmsh.y"
    {
      std::string key((yyvsp[0].c));
      double v;
      if(!flag_Enum) {
        v = 1.;
        if(key == "Enum") flag_Enum = 1;
      }
      else
        v = (double)++member_ValMax;
      floatOptions[key].push_back(v);
      Free((yyvsp[0].c));
    }
#line 8018 "Gmsh.tab.cpp"
    break;

  case 146: /* FloatParameterOption: tSTRING '{' Enumeration '}'  */
#line 1468 "Gmsh.y"
    {
      std::string key((yyvsp[-3].c));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        doubleXstring v;
        List_Read((yyvsp[-1].l), i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free((yyvsp[-3].c));
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        Free(((doubleXstring*)List_Pointer((yyvsp[-1].l), i))->s);
      List_Delete((yyvsp[-1].l));
    }
#line 8036 "Gmsh.tab.cpp"
    break;

  case 147: /* FloatParameterOption: tSTRING StringExpr  */
#line 1482 "Gmsh.y"
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 8048 "Gmsh.tab.cpp"
    break;

  case 148: /* FloatParameterOption: tSTRING Str_BracedRecursiveListOfStringExprVar  */
#line 1490 "Gmsh.y"
    {
      std::string key((yyvsp[-1].c));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
        char *v;
        List_Read((yyvsp[0].l), i, &v);
        charOptions[key].push_back(v);
      }
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[0].l));
    }
#line 8063 "Gmsh.tab.cpp"
    break;

  case 153: /* CharParameterOption: tSTRING FExpr  */
#line 1515 "Gmsh.y"
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 8074 "Gmsh.tab.cpp"
    break;

  case 154: /* CharParameterOption: tSTRING StringExpr  */
#line 1523 "Gmsh.y"
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 8086 "Gmsh.tab.cpp"
    break;

  case 155: /* CharParameterOption: tMacro StringExpr  */
#line 1532 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 8097 "Gmsh.tab.cpp"
    break;

  case 156: /* CharParameterOption: tSTRING BracedRecursiveListOfStringExprVar  */
#line 1540 "Gmsh.y"
    {
      std::string key((yyvsp[-1].c));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
        char *s;
        List_Read((yyvsp[0].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[0].l));
    }
#line 8114 "Gmsh.tab.cpp"
    break;

  case 157: /* CharParameterOption: tSTRING Str_BracedRecursiveListOfStringExprVar  */
#line 1554 "Gmsh.y"
    {
      std::string key((yyvsp[-1].c));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
        char *s;
        List_Read((yyvsp[0].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[0].l));
    }
#line 8131 "Gmsh.tab.cpp"
    break;

  case 158: /* PhysicalId_per_dim_entity: FExpr  */
#line 1572 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 8139 "Gmsh.tab.cpp"
    break;

  case 159: /* PhysicalId_per_dim_entity: StringExpr  */
#line 1576 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->getPhysicalNumber(dim_entity, std::string((yyvsp[0].c)));

      if ((yyval.i) < 0) {
        int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
        GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
        (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[0].c)), dim_entity, t + 1);
      }
      Free((yyvsp[0].c));
    }
#line 8154 "Gmsh.tab.cpp"
    break;

  case 160: /* PhysicalId_per_dim_entity: StringExpr ',' FExpr  */
#line 1587 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), dim_entity, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 8163 "Gmsh.tab.cpp"
    break;

  case 161: /* SurfaceConstraints: %empty  */
#line 1595 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
#line 8171 "Gmsh.tab.cpp"
    break;

  case 162: /* SurfaceConstraints: tIn tSphere '{' FExpr '}'  */
#line 1599 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[-1].d);
      List_Add((yyval.l), &p);
    }
#line 8181 "Gmsh.tab.cpp"
    break;

  case 163: /* SurfaceConstraints: tUsing tPoint '{' RecursiveListOfDouble '}'  */
#line 1605 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 8189 "Gmsh.tab.cpp"
    break;

  case 164: /* SurfaceConstraints: tUsing tGeoEntity '{' RecursiveListOfDouble '}'  */
#line 1609 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[-1].l), i));
      List_Delete((yyvsp[-1].l));
    }
#line 8202 "Gmsh.tab.cpp"
    break;

  case 165: /* CircleOptions: %empty  */
#line 1620 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 8210 "Gmsh.tab.cpp"
    break;

  case 166: /* CircleOptions: tPlane VExpr  */
#line 1624 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 8218 "Gmsh.tab.cpp"
    break;

  case 167: /* LoopOptions: %empty  */
#line 1630 "Gmsh.y"
    {
      (yyval.d) = 0;
    }
#line 8226 "Gmsh.tab.cpp"
    break;

  case 168: /* LoopOptions: tUsing tSewing  */
#line 1634 "Gmsh.y"
    {
      (yyval.d) = 1;
    }
#line 8234 "Gmsh.tab.cpp"
    break;

  case 169: /* Shape: tPoint '(' FExpr ')' tAFFECT VExpr tEND  */
#line 1640 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[3];
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addVertex(num, x, y, z, lc);
      }
      else{
        if(!myGmshSurface)
          r = GModel::current()->getGEOInternals()->addVertex(num, x, y, z, lc);
        else
          r = GModel::current()->getGEOInternals()->addVertex(num, x, y,
                                                              myGmshSurface, lc);
      }
      if(!r) yymsg(0, "Could not add point");
      AddToTemporaryBoundingBox(x, y, z);
      (yyval.s).Type = MSH_POINT;
      (yyval.s).Num = num;
    }
#line 8261 "Gmsh.tab.cpp"
    break;

  case 170: /* Shape: tCurve '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 1663 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addLine(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addLine(num, tags);
      }
      if(!r) yymsg(0, "Could not add line");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    }
#line 8281 "Gmsh.tab.cpp"
    break;

  case 171: /* Shape: tSpline '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 1679 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSpline(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add spline");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    }
#line 8301 "Gmsh.tab.cpp"
    break;

  case 172: /* Shape: tCompound tSpline '(' FExpr ')' tAFFECT ListOfDouble tUsing FExpr tEND  */
#line 1695 "Gmsh.y"
    {
      int num = (int)(yyvsp[-6].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Compound spline only available with built-in geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->addCompoundSpline(num, tags,
                                                                    (int)(yyvsp[-1].d));
      }
      if(!r) yymsg(0, "Could not add compound spline");
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    }
#line 8322 "Gmsh.tab.cpp"
    break;

  case 173: /* Shape: tCompound tBSpline '(' FExpr ')' tAFFECT ListOfDouble tUsing FExpr tEND  */
#line 1712 "Gmsh.y"
    {
      int num = (int)(yyvsp[-6].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Compound spline only available with built-in geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->addCompoundBSpline(num, tags,
                                                                     (int)(yyvsp[-1].d));
      }
      if(!r) yymsg(0, "Could not add compound spline");
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    }
#line 8343 "Gmsh.tab.cpp"
    break;

  case 174: /* Shape: tCircle '(' FExpr ')' tAFFECT ListOfDouble CircleOptions tEND  */
#line 1729 "Gmsh.y"
    {
      int num = (int)(yyvsp[-5].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-2].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(tags.size() == 3){
          r = GModel::current()->getOCCInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(param.size() >= 4 && param.size() <= 6){
          double r = param[3];
          double a1 = (param.size() == 6) ? param[4] : 0.;
          double a2 = (param.size() == 6) ? param[5] :
            (param.size() == 5) ? param[4] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addCircle
            (num, param[0], param[1], param[2], r, a1, a2);
        }
        else{
          yymsg(0, "Circle requires 3 points or 4 to 6 parameters");
        }
      }
      else{
        if(tags.size() == 3){
          r = GModel::current()->getGEOInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2], (yyvsp[-1].v)[0], (yyvsp[-1].v)[1], (yyvsp[-1].v)[2]);
        }
        else{
          yymsg(0, "Circle requires 3 points");
        }
      }
      if(!r) yymsg(0, "Could not add circle");
      List_Delete((yyvsp[-2].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    }
#line 8384 "Gmsh.tab.cpp"
    break;

  case 175: /* Shape: tEllipse '(' FExpr ')' tAFFECT ListOfDouble CircleOptions tEND  */
#line 1766 "Gmsh.y"
    {
      int num = (int)(yyvsp[-5].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-2].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(tags.size() == 3){ // keep this for backward compatibility
          r = GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[0], tags[2]);
        }
        else if(tags.size() == 4){
          r = GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2], tags[3]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() == 7) ? param[5] : 0.;
          double a2 = (param.size() == 7) ? param[6] :
            (param.size() == 6) ? param[5] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 4 points, or 5 to 7 parameters");
        }
      }
      else{
        if(tags.size() == 3){ // to match occ
          r = GModel::current()->getGEOInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[0], tags[2], (yyvsp[-1].v)[0], (yyvsp[-1].v)[1], (yyvsp[-1].v)[2]);
        }
        else if(tags.size() == 4){
          r = GModel::current()->getGEOInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2], tags[3], (yyvsp[-1].v)[0], (yyvsp[-1].v)[1], (yyvsp[-1].v)[2]);
        }
        else{
          yymsg(0, "Ellipse requires 4 points");
        }
      }
      if(!r) yymsg(0, "Could not add ellipse");
      List_Delete((yyvsp[-2].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    }
#line 8432 "Gmsh.tab.cpp"
    break;

  case 176: /* Shape: tBSpline '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 1810 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addBSpline(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add BSpline");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    }
#line 8452 "Gmsh.tab.cpp"
    break;

  case 177: /* Shape: tBezier '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 1826 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addBezier(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBezier(num, tags);
      }
      if(!r) yymsg(0, "Could not add Bezier");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    }
#line 8472 "Gmsh.tab.cpp"
    break;

  case 178: /* Shape: tNurbs '(' FExpr ')' tAFFECT ListOfDouble tNurbsKnots ListOfDouble tNurbsOrder FExpr tEND  */
#line 1843 "Gmsh.y"
    {
      int num = (int)(yyvsp[-8].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-5].l), tags);
      std::vector<double> seqknots; ListOfDouble2Vector((yyvsp[-3].l), seqknots);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        int degree = (int)(yyvsp[-1].d);
        std::vector<double> weights, knots;
        std::vector<int> mults;
        for(std::size_t i = 0; i < seqknots.size(); i++){
          if(!i || (i && fabs(seqknots[i] - seqknots[i - 1]) > 1e-12)){
            knots.push_back(seqknots[i]);
            mults.push_back(1);
          }
          else{
            mults.back() += 1;
          }
        }
        r = GModel::current()->getOCCInternals()->addBSpline
          (num, tags, degree, weights, knots, mults);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBSpline(num, tags, seqknots);
      }
      if(!r) yymsg(0, "Could not add nurbs");
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    }
#line 8507 "Gmsh.tab.cpp"
    break;

  case 179: /* Shape: tWire '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 1874 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addWire(num, tags, false);
      }
      else{
        yymsg(0, "Wire only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add wire");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    }
#line 8527 "Gmsh.tab.cpp"
    break;

  case 180: /* Shape: tCurve tSTRING '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 1890 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addCurveLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addCurveLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add curve loop");
      List_Delete((yyvsp[-1].l));
      Free((yyvsp[-6].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    }
#line 8548 "Gmsh.tab.cpp"
    break;

  case 181: /* Shape: tPlane tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 1907 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPlaneSurface(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addPlaneSurface(num, tags);
      }
      if(!r) yymsg(0, "Could not add plane surface");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    }
#line 8568 "Gmsh.tab.cpp"
    break;

  case 182: /* Shape: tSurface '(' FExpr ')' tAFFECT ListOfDouble SurfaceConstraints tEND  */
#line 1923 "Gmsh.y"
    {
      int num = (int)(yyvsp[-5].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-2].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE surface filling requires a single curve loop");
        }
        else{
          std::vector<int> constraints; ListOfDouble2Vector((yyvsp[-1].l), constraints);
          std::vector<int> points, surfaces, continuity;
          if(constraints.size() >= 3 && constraints[0] < 0){
            // {-1, type, ent, type, ent, ...}
            for(std::size_t i = 2; i < constraints.size(); i+=2){
              int type = constraints[i - 1];
              if(type == 0){
                points.push_back(constraints[i]);
              }
              else if(type == 1 || type == 2){
                surfaces.push_back(constraints[i]);
                continuity.push_back(type);
              }
              else
                yymsg(0, "Unknown type of constraint for surface filling");
            }
          }
          else if(constraints.size() > 0){
            // {point, point, ...}
            points = constraints;
          }
          r = GModel::current()->getOCCInternals()->addSurfaceFilling
            (num, wires[0], points, surfaces, continuity);
        }
      }
      else{
        int sphereCenter = -1;
        if(List_Nbr((yyvsp[-1].l)) == 1){
          double d; List_Read((yyvsp[-1].l), 0, &d);
          sphereCenter = (int)d;
        }
        r = GModel::current()->getGEOInternals()->addSurfaceFilling
          (num, wires, sphereCenter);
      }
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[-2].l));
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    }
#line 8622 "Gmsh.tab.cpp"
    break;

  case 183: /* Shape: tRuled tSurface '(' FExpr ')' tAFFECT ListOfDouble SurfaceConstraints tEND  */
#line 1973 "Gmsh.y"
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[-5].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-2].l), wires);
      int sphereCenter = -1;
      if(List_Nbr((yyvsp[-1].l)) == 1){
        double d; List_Read((yyvsp[-1].l), 0, &d);
        sphereCenter = (int)d;
      }
      bool r = GModel::current()->getGEOInternals()->addSurfaceFilling
        (num, wires, sphereCenter);
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[-2].l));
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    }
#line 8644 "Gmsh.tab.cpp"
    break;

  case 184: /* Shape: tBSpline tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 1991 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-1].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1) {
          yymsg(0, "OpenCASCADE BSpline filling requires a single curve loop");
        }
        else {
          r = GModel::current()->getOCCInternals()->addBSplineFilling(num, wires[0]);
        }
      }
      else{
        yymsg(0, "BSpline surface only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add BSpline surface");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    }
#line 8669 "Gmsh.tab.cpp"
    break;

  case 185: /* Shape: tBezier tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2012 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-1].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1) {
          yymsg(0, "OpenCASCADE BSpline filling requires a single curve loop");
        }
        else {
          r = GModel::current()->getOCCInternals()->addBezierFilling(num, wires[0]);
        }
      }
      else{
        yymsg(0, "Bezier surface only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add Bezier surface");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    }
#line 8694 "Gmsh.tab.cpp"
    break;

  case 186: /* Shape: tEuclidian tCoordinates tEND  */
#line 2033 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8704 "Gmsh.tab.cpp"
    break;

  case 187: /* Shape: tCoordinates tSurface FExpr tEND  */
#line 2039 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8714 "Gmsh.tab.cpp"
    break;

  case 188: /* Shape: tParametric tSurface '(' FExpr ')' tAFFECT tBIGSTR tBIGSTR tBIGSTR tEND  */
#line 2045 "Gmsh.y"
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 8725 "Gmsh.tab.cpp"
    break;

  case 189: /* Shape: tSphere '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2052 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      (yyval.s).Type = 0;
      bool r = true;
      if(param.size() >= 4 && param.size() <= 7){
        if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          double a1 = (param.size() >= 5) ? param[4] : -M_PI/2;
          double a2 = (param.size() >= 6) ? param[5] : M_PI/2;
          double a3 = (param.size() >= 7) ? param[6] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addSphere
            (num, param[0], param[1], param[2], param[3], a1, a2, a3);
        }
        else{
          yymsg(0, "Sphere only available with OpenCASCADE geometry kernel");
        }
        (yyval.s).Type = MSH_VOLUME;
      }
      else if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometrySphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "Sphere requires 2 points or from 4 to 7 parameters");
      }
      if(!r) yymsg(0, "Could not add sphere");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Num = num;
    }
#line 8760 "Gmsh.tab.cpp"
    break;

  case 190: /* Shape: tPolarSphere '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2083 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometryPolarSphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "PolarSphere requires 2 points");
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 8779 "Gmsh.tab.cpp"
    break;

  case 191: /* Shape: tBox '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2098 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6){
          r = GModel::current()->getOCCInternals()->addBox
            (num, param[0], param[1], param[2], param[3], param[4], param[5]);
        }
        else{
          yymsg(0, "Box requires 6 parameters");
        }
      }
      else{
        yymsg(0, "Box only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add block");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 8805 "Gmsh.tab.cpp"
    break;

  case 192: /* Shape: tTorus '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2120 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 5 || param.size() == 6){
          double alpha = (param.size() == 6) ? param[5] : 2*M_PI;
          r = GModel::current()->getOCCInternals()->addTorus
            (num, param[0], param[1], param[2], param[3], param[4], alpha);
        }
        else{
          yymsg(0, "Torus requires 5 ou 6 parameters");
        }
      }
      else{
        yymsg(0, "Torus only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add torus");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 8832 "Gmsh.tab.cpp"
    break;

  case 193: /* Shape: tRectangle '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2143 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 5 || param.size() == 6){
          double r = (param.size() == 6) ? param[5] : 0.;
          r = GModel::current()->getOCCInternals()->addRectangle
            (num, param[0], param[1], param[2], param[3], param[4], r);
        }
        else{
          yymsg(0, "Rectangle requires 5 ou 6 parameters");
        }
      }
      else{
        yymsg(0, "Rectangle only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add rectangle");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    }
#line 8859 "Gmsh.tab.cpp"
    break;

  case 194: /* Shape: tDisk '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2166 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 4 || param.size() == 5){
          double ry = (param.size() == 5) ? param[4] : param[3];
          r = GModel::current()->getOCCInternals()->addDisk
            (num, param[0], param[1], param[2], param[3], ry);
        }
        else{
          yymsg(0, "Disk requires 4 or 5 parameters");
        }
      }
      else{
        yymsg(0, "Disk only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add disk");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    }
#line 8886 "Gmsh.tab.cpp"
    break;

  case 195: /* Shape: tCylinder '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2189 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 7 || param.size() == 8){
          double angle = (param.size() == 8) ? param[7] : 2*M_PI;
          r = GModel::current()->getOCCInternals()->addCylinder
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], angle);
        }
        else{
          yymsg(0, "Cylinder requires 7 or 8 parameters");
        }
      }
      else{
        yymsg(0, "Cylinder only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add cylinder");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 8914 "Gmsh.tab.cpp"
    break;

  case 196: /* Shape: tCone '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2213 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 8 || param.size() == 9){
          double alpha = (param.size() == 9) ? param[8] : 2*M_PI;
          r = GModel::current()->getOCCInternals()->addCone
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], param[7], alpha);
        }
        else{
          yymsg(0, "Cone requires 8 or 9 parameters");
        }
      }
      else{
        yymsg(0, "Cone only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add cone");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 8942 "Gmsh.tab.cpp"
    break;

  case 197: /* Shape: tWedge '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2237 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6 || param.size() == 7){
          double ltx = (param.size() == 7) ? param[6] : 0.;
          r = GModel::current()->getOCCInternals()->addWedge
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             ltx);
        }
        else{
          yymsg(0, "Wedge requires 7 parameters");
        }
      }
      else{
        yymsg(0, "Wedge only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add wedge");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 8970 "Gmsh.tab.cpp"
    break;

  case 198: /* Shape: tThickSolid '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2261 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() >= 2){
          int in = (int)param[0];
          double offset = param[1];
          std::vector<int> exclude;
          for(std::size_t i = 2; i < param.size(); i++)
            exclude.push_back(param[i]);
          std::vector<std::pair<int, int> > outDimTags;
          r = GModel::current()->getOCCInternals()->addThickSolid
            (num, in, exclude, offset, outDimTags);
        }
        else{
          yymsg(0, "ThickSolid requires at least 2 parameters");
        }
      }
      else{
        yymsg(0, "ThickSolid only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add thick solid");
      List_Delete((yyvsp[-1].l));
    }
#line 9000 "Gmsh.tab.cpp"
    break;

  case 199: /* Shape: tSurface tSTRING '(' FExpr ')' tAFFECT ListOfDouble LoopOptions tEND  */
#line 2287 "Gmsh.y"
    {
      int num = (int)(yyvsp[-5].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags, (yyvsp[-1].d));
      }
      else{
        r = GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add surface loop");
      List_Delete((yyvsp[-2].l));
      Free((yyvsp[-7].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    }
#line 9021 "Gmsh.tab.cpp"
    break;

  case 200: /* Shape: tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2304 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      if(!r) yymsg(0, "Could not add volume");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 9041 "Gmsh.tab.cpp"
    break;

  case 201: /* Shape: tThruSections '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2320 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-1].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (num, wires, true, false, outDimTags);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add thrusections");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 9063 "Gmsh.tab.cpp"
    break;

  case 202: /* Shape: tRuled tThruSections '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2338 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-1].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (num, wires, true, true, outDimTags);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add ruled thrusections");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 9085 "Gmsh.tab.cpp"
    break;

  case 203: /* Shape: tCompound GeoEntity123 '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2356 "Gmsh.y"
    {
      if((yyvsp[-6].i) == 1)
        yymsg(0, "`Compound Line (...) = {...};' is deprecated: use `Compound "
              "Spline|BSpline (...) = {...} Using ...;' instead, or the compound "
              "meshing constraint `Compound Curve {...};'");
      else
        yymsg(0, "`Compound Surface (...) = {...};' is deprecated: use the "
              "compound meshing constraint `Compound Surface {...};' instead");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 9101 "Gmsh.tab.cpp"
    break;

  case 204: /* Shape: tCompound GeoEntity123 '(' FExpr ')' tAFFECT ListOfDouble tSTRING '{' RecursiveListOfListOfDouble '}' tEND  */
#line 2369 "Gmsh.y"
    {
      if((yyvsp[-10].i) == 1)
        yymsg(0, "`Compound Line (...) = {...};' is deprecated: use `Compound "
              "Spline|BSpline (...) = {...} Using ...;' instead, or the compound "
              "meshing constraint `Compound Curve {...};'");
      else
        yymsg(0, "`Compound Surface (...) = {...};' is deprecated: use the "
              "compound meshing constraint `Compound Surface {...};' instead");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 9117 "Gmsh.tab.cpp"
    break;

  case 205: /* $@9: %empty  */
#line 2381 "Gmsh.y"
    {
      dim_entity = (yyvsp[0].i);
    }
#line 9125 "Gmsh.tab.cpp"
    break;

  case 206: /* Shape: tPhysical GeoEntity $@9 '(' PhysicalId_per_dim_entity ')' NumericAffectation ListOfDouble tEND  */
#line 2385 "Gmsh.y"
    {
      int num = (int)(yyvsp[-4].i);
      int op = (yyvsp[-2].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
        ((yyvsp[-7].i), num, op, tags);
      if(!r)
        switch ((yyvsp[-7].i)) {
        case 0: yymsg(0, "Could not modify physical point"); break;
        case 1: yymsg(0, "Could not modify physical line"); break;
        case 2: yymsg(0, "Could not modify physical surface"); break;
        case 3: yymsg(0, "Could not modify physical volume"); break;
        }
      List_Delete((yyvsp[-1].l));
      switch ((yyvsp[-7].i)) {
      case 0: (yyval.s).Type = MSH_PHYSICAL_POINT  ; break;
      case 1: (yyval.s).Type = MSH_PHYSICAL_LINE   ; break;
      case 2: (yyval.s).Type = MSH_PHYSICAL_SURFACE; break;
      case 3: (yyval.s).Type = MSH_PHYSICAL_VOLUME ; break;
      }
      (yyval.s).Num = num;
    }
#line 9152 "Gmsh.tab.cpp"
    break;

  case 207: /* GeoEntity: tPoint  */
#line 2411 "Gmsh.y"
    { (yyval.i) = 0; }
#line 9158 "Gmsh.tab.cpp"
    break;

  case 208: /* GeoEntity: tCurve  */
#line 2413 "Gmsh.y"
    { (yyval.i) = 1; }
#line 9164 "Gmsh.tab.cpp"
    break;

  case 209: /* GeoEntity: tSurface  */
#line 2415 "Gmsh.y"
    { (yyval.i) = 2; }
#line 9170 "Gmsh.tab.cpp"
    break;

  case 210: /* GeoEntity: tVolume  */
#line 2417 "Gmsh.y"
    { (yyval.i) = 3; }
#line 9176 "Gmsh.tab.cpp"
    break;

  case 211: /* GeoEntity: tGeoEntity '{' FExpr '}'  */
#line 2419 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if((yyval.i) < 0 || (yyval.i) > 3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
#line 9185 "Gmsh.tab.cpp"
    break;

  case 212: /* GeoEntity123: tCurve  */
#line 2427 "Gmsh.y"
    { (yyval.i) = 1; }
#line 9191 "Gmsh.tab.cpp"
    break;

  case 213: /* GeoEntity123: tSurface  */
#line 2429 "Gmsh.y"
    { (yyval.i) = 2; }
#line 9197 "Gmsh.tab.cpp"
    break;

  case 214: /* GeoEntity123: tVolume  */
#line 2431 "Gmsh.y"
    { (yyval.i) = 3; }
#line 9203 "Gmsh.tab.cpp"
    break;

  case 215: /* GeoEntity123: tGeoEntity '{' FExpr '}'  */
#line 2433 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
#line 9212 "Gmsh.tab.cpp"
    break;

  case 216: /* GeoEntity12: tCurve  */
#line 2441 "Gmsh.y"
    { (yyval.i) = 1; }
#line 9218 "Gmsh.tab.cpp"
    break;

  case 217: /* GeoEntity12: tSurface  */
#line 2443 "Gmsh.y"
    { (yyval.i) = 2; }
#line 9224 "Gmsh.tab.cpp"
    break;

  case 218: /* GeoEntity12: tGeoEntity '{' FExpr '}'  */
#line 2445 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
#line 9233 "Gmsh.tab.cpp"
    break;

  case 219: /* GeoEntity012: tPoint  */
#line 2453 "Gmsh.y"
    { (yyval.i) = 0; }
#line 9239 "Gmsh.tab.cpp"
    break;

  case 220: /* GeoEntity012: tCurve  */
#line 2455 "Gmsh.y"
    { (yyval.i) = 1; }
#line 9245 "Gmsh.tab.cpp"
    break;

  case 221: /* GeoEntity012: tSurface  */
#line 2457 "Gmsh.y"
    { (yyval.i) = 2; }
#line 9251 "Gmsh.tab.cpp"
    break;

  case 222: /* GeoEntity012: tGeoEntity '{' FExpr '}'  */
#line 2459 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if((yyval.i) < 0 || (yyval.i) > 2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
#line 9260 "Gmsh.tab.cpp"
    break;

  case 223: /* Transform: tTranslate VExpr '{' MultipleShape '}'  */
#line 2469 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->translate
          (dimTags, (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2]);
      }
      else{
        r = GModel::current()->getGEOInternals()->translate
          (dimTags, (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2]);
      }
      if(!r) yymsg(0, "Could not translate shapes");
      (yyval.l) = (yyvsp[-1].l);
    }
#line 9280 "Gmsh.tab.cpp"
    break;

  case 224: /* Transform: tRotate '{' VExpr ',' VExpr ',' FExpr '}' '{' MultipleShape '}'  */
#line 2485 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->rotate
          (dimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-4].d));
      }
      else{
        r = GModel::current()->getGEOInternals()->rotate
          (dimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-4].d));
      }
      if(!r) yymsg(0, "Could not rotate shapes");
      (yyval.l) = (yyvsp[-1].l);
    }
#line 9300 "Gmsh.tab.cpp"
    break;

  case 225: /* Transform: tSymmetry VExpr '{' MultipleShape '}'  */
#line 2501 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->symmetry
          (dimTags, (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3]);
      }
      else{
        r = GModel::current()->getGEOInternals()->symmetry
          (dimTags, (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], (yyvsp[-3].v)[3]);
      }
      if(!r) yymsg(0, "Could not apply symmetry transform");
      (yyval.l) = (yyvsp[-1].l);
    }
#line 9320 "Gmsh.tab.cpp"
    break;

  case 226: /* Transform: tDilate '{' VExpr ',' FExpr '}' '{' MultipleShape '}'  */
#line 2517 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->dilate
          (dimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d));
      }
      else{
        r = GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].d), (yyvsp[-4].d), (yyvsp[-4].d));
      }
      if(!r) yymsg(0, "Could not dilate shapes");
      (yyval.l) = (yyvsp[-1].l);
    }
#line 9340 "Gmsh.tab.cpp"
    break;

  case 227: /* Transform: tDilate '{' VExpr ',' VExpr '}' '{' MultipleShape '}'  */
#line 2533 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->dilate
          (dimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]);
      }
      else{
        r = GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]);
      }
      if(!r) yymsg(0, "Could not dilate shapes");
      (yyval.l) = (yyvsp[-1].l);
    }
#line 9360 "Gmsh.tab.cpp"
    break;

  case 228: /* Transform: tAffine '{' RecursiveListOfDouble '}' '{' MultipleShape '}'  */
#line 2549 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<double> mat;
        ListOfDouble2Vector((yyvsp[-4].l), mat);
        r = GModel::current()->getOCCInternals()->affine(dimTags, mat);
      }
      else{
        yymsg(0, "Affine transform only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not transform shapes");
      List_Delete((yyvsp[-4].l));
      (yyval.l) = (yyvsp[-1].l);
    }
#line 9381 "Gmsh.tab.cpp"
    break;

  case 229: /* Transform: tClosest '{' RecursiveListOfDouble '}' '{' MultipleShape '}'  */
#line 2566 "Gmsh.y"
    {
      std::vector<double> xyz; ListOfDouble2Vector((yyvsp[-4].l), xyz);
      std::vector<std::pair<int, int> > dimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      (yyval.l) = (yyvsp[-1].l);
      List_Reset((yyval.l));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(xyz.size() == 3) {
          std::vector<double> dist, coord;
          r = GModel::current()->getOCCInternals()->getClosestEntities
            (xyz[0], xyz[1], xyz[2], dimTags, outDimTags, dist, coord,
             (int)dimTags.size());
        }
        else {
          yymsg(0, "Closest first argument should contain 3 coordinates");
        }
      }
      else{
        yymsg(0, "Closest entity only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Closest entity search failed");
      else VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      List_Delete((yyvsp[-4].l));
    }
#line 9411 "Gmsh.tab.cpp"
    break;

  case 230: /* Transform: tSTRING '{' MultipleShape '}'  */
#line 2592 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), inDimTags);
      (yyval.l) = (yyvsp[-1].l);
      List_Reset((yyval.l));
      std::string action((yyvsp[-3].c));
      bool r = true;
      if(action == "Duplicata"){
        if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
          r = GModel::current()->getOCCInternals()->copy(inDimTags, outDimTags);
        }
        else{
          r = GModel::current()->getGEOInternals()->copy(inDimTags, outDimTags);
        }
      }
      else if(action == "Boundary" || action == "CombinedBoundary" ||
              action == "OrientedBoundary" || action == "OrientedCombinedBoundary" ||
              action == "PointsOf"){
        // boundary operations are performed directly on GModel, which enables
        // to compute the boundary of hybrid CAD models; this also automatically
        // binds all boundary entities for OCC models
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        bool combined = (action == "CombinedBoundary" ||
                         action == "OrientedCombinedBoundary");
        bool oriented = (action == "OrientedBoundary" ||
                         action == "OrientedCombinedBoundary");
        bool recursive = action == "PointsOf";
        r = GModel::current()->getBoundaryTags
          (inDimTags, outDimTags, combined, oriented, recursive);
      }
      else{
        yymsg(0, "Unknown action on multiple shapes '%s'", (yyvsp[-3].c));
      }
      if(!r) yymsg(0, "Could not apply operation on shapes");
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[-3].c));
    }
#line 9457 "Gmsh.tab.cpp"
    break;

  case 231: /* Transform: tIntersect tCurve '{' RecursiveListOfDouble '}' tSurface '{' FExpr '}'  */
#line 2634 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Intersect line not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> in, out; ListOfDouble2Vector((yyvsp[-5].l), in);
        r = GModel::current()->getGEOInternals()->intersectCurvesWithSurface
          (in, (int)(yyvsp[-1].d), out);
        for(std::size_t i = 0; i < out.size(); i++){
          Shape s;
          s.Type = MSH_POINT;
          s.Num = out[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not intersect line");
      List_Delete((yyvsp[-5].l));
    }
#line 9482 "Gmsh.tab.cpp"
    break;

  case 232: /* Transform: tSplit tCurve '{' FExpr '}' tPoint '{' RecursiveListOfDouble '}' tEND  */
#line 2655 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Curve not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector((yyvsp[-2].l), vertices);
        r = GModel::current()->getGEOInternals()->splitCurve
          ((int)(yyvsp[-6].d), vertices, curves);
        for(std::size_t i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not split curve");
      List_Delete((yyvsp[-2].l));
    }
#line 9507 "Gmsh.tab.cpp"
    break;

  case 233: /* Transform: tSplit tCurve '(' FExpr ')' '{' RecursiveListOfDouble '}' tEND  */
#line 2676 "Gmsh.y"
    {
      yymsg(2, "'Split Curve(c) {...}' is deprecated: "
            "use 'Split Curve {c} Point {...}' instead");
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Curve not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector((yyvsp[-2].l), vertices);
        r = GModel::current()->getGEOInternals()->splitCurve
          ((int)(yyvsp[-5].d), vertices, curves);
        for(std::size_t i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not split curve");
      List_Delete((yyvsp[-2].l));
    }
#line 9534 "Gmsh.tab.cpp"
    break;

  case 234: /* MultipleShape: ListOfShapes  */
#line 2701 "Gmsh.y"
                  { (yyval.l) = (yyvsp[0].l); }
#line 9540 "Gmsh.tab.cpp"
    break;

  case 235: /* MultipleShape: Transform  */
#line 2702 "Gmsh.y"
                  { (yyval.l) = (yyvsp[0].l); }
#line 9546 "Gmsh.tab.cpp"
    break;

  case 236: /* ListOfShapes: %empty  */
#line 2707 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 9554 "Gmsh.tab.cpp"
    break;

  case 237: /* ListOfShapes: ListOfShapes Shape  */
#line 2711 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 9562 "Gmsh.tab.cpp"
    break;

  case 238: /* ListOfShapes: ListOfShapes GeoEntity '{' RecursiveListOfDouble '}' tEND  */
#line 2715 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	double d;
	List_Read((yyvsp[-2].l), i, &d);
	Shape s;
	s.Num = (int)d;
        switch ((yyvsp[-4].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete((yyvsp[-2].l));
    }
#line 9583 "Gmsh.tab.cpp"
    break;

  case 239: /* ListOfShapes: ListOfShapes tPhysical GeoEntity '{' RecursiveListOfDouble '}' tEND  */
#line 2732 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getElementaryTagsForPhysicalGroups((yyvsp[-4].i), (yyvsp[-2].l), tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ((yyvsp[-4].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete(tmp);
      List_Delete((yyvsp[-2].l));
    }
#line 9607 "Gmsh.tab.cpp"
    break;

  case 240: /* ListOfShapes: ListOfShapes tParent GeoEntity '{' RecursiveListOfDouble '}' tEND  */
#line 2752 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[-4].i), (yyvsp[-2].l), tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ((yyvsp[-4].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete(tmp);
      List_Delete((yyvsp[-2].l));
    }
#line 9631 "Gmsh.tab.cpp"
    break;

  case 241: /* ListOfShapes: ListOfShapes GeoEntity '{' tDOTS '}' tEND  */
#line 2772 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-4].i), tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
	Shape s;
	s.Num = (int)d;
        switch ((yyvsp[-4].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete(tmp);
    }
#line 9654 "Gmsh.tab.cpp"
    break;

  case 242: /* ListOfShapes: ListOfShapes tPhysical GeoEntity '{' tDOTS '}' tEND  */
#line 2791 "Gmsh.y"
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      List_T *tmp2 = List_Create(10, 10, sizeof(double));
      getAllPhysicalTags((yyvsp[-4].i), tmp2);
      getElementaryTagsForPhysicalGroups((yyvsp[-4].i), tmp2, tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ((yyvsp[-4].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
      List_Delete(tmp);
      List_Delete(tmp2);
    }
#line 9680 "Gmsh.tab.cpp"
    break;

  case 243: /* LevelSet: tLevelset tPlane '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 2818 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-1].l)) == 4){
        int t = (int)(yyvsp[-4].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read((yyvsp[-1].l), i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[-1].l));
    }
#line 9703 "Gmsh.tab.cpp"
    break;

  case 244: /* LevelSet: tLevelset tPoint '(' FExpr ')' tAFFECT '{' RecursiveListOfListOfDouble '}' tEND  */
#line 2837 "Gmsh.y"
    {
      int t = (int)(yyvsp[-6].d);
      if(gLevelset::find(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	fullMatrix<double> centers(List_Nbr((yyvsp[-2].l)),3);
	for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[-2].l), i);
	  for(int j = 0; j < List_Nbr(l); j++){
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
        gLevelset *ls = new gLevelsetPoints(centers, t);
        gLevelset::add(ls);
      }
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[-2].l), i));
      List_Delete((yyvsp[-2].l));
    }
#line 9728 "Gmsh.tab.cpp"
    break;

  case 245: /* LevelSet: tLevelset tPlane '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ',' RecursiveListOfDouble '}' tEND  */
#line 2859 "Gmsh.y"
    {
      int t = (int)(yyvsp[-10].d);
      if(gLevelset::find(t)){
        yymsg(0, "Levelset %d already exists", t);
      }
      else {
        double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
        double n[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
        gLevelset *ls = new gLevelsetPlane(pt, n, t);
        gLevelset::add(ls);
      }
      List_Delete((yyvsp[-2].l));
    }
#line 9746 "Gmsh.tab.cpp"
    break;

  case 246: /* LevelSet: tLevelset tPlane '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ',' VExpr ',' RecursiveListOfDouble '}' tEND  */
#line 2874 "Gmsh.y"
    {
      int t = (int)(yyvsp[-12].d);
      if(gLevelset::find(t)){
        yymsg(0, "Levelset %d already exists", t);
      }
      else {
        double pt1[3] = {(yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2]};
        double pt2[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
        double pt3[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
        gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
        gLevelset::add(ls);
      }
      List_Delete((yyvsp[-2].l));
    }
#line 9765 "Gmsh.tab.cpp"
    break;

  case 247: /* LevelSet: tLevelset tSphere '(' FExpr ')' tAFFECT '{' VExpr ',' RecursiveListOfDouble '}' tEND  */
#line 2889 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-2].l)) == 1){
        int t = (int)(yyvsp[-8].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[-2].l), 0, &d);
          gLevelset *ls = new gLevelsetSphere((yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2], d, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[-2].l));
    }
#line 9787 "Gmsh.tab.cpp"
    break;

  case 248: /* LevelSet: tLevelset tCylinder '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ',' RecursiveListOfDouble '}' tEND  */
#line 2908 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-2].l)) == 1){
        int t = (int)(yyvsp[-10].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[-2].l), 0, &d);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          gLevelset::add(ls);
        }
      }
      else if(List_Nbr((yyvsp[-2].l)) == 2){
        int t = (int)(yyvsp[-10].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read((yyvsp[-2].l), i, &d[i]);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          gLevelset::add(ls);
        }
      }
      else if(List_Nbr((yyvsp[-2].l)) == 3){
        int t = (int)(yyvsp[-10].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[-2].l), i, &d[i]);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[-2].l));
    }
#line 9841 "Gmsh.tab.cpp"
    break;

  case 249: /* LevelSet: tLevelset tCone '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ',' RecursiveListOfDouble '}' tEND  */
#line 2959 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-2].l)) == 1){
        int t = (int)(yyvsp[-10].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[-2].l), 0, &d);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[-2].l));
    }
#line 9865 "Gmsh.tab.cpp"
    break;

  case 250: /* LevelSet: tLevelset tEllipsoid '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ',' RecursiveListOfDouble '}' tEND  */
#line 2980 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-2].l)) == 3){
        int t = (int)(yyvsp[-10].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[-2].l), i, &d[i]);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[-2].l));
    }
#line 9890 "Gmsh.tab.cpp"
    break;

  case 251: /* LevelSet: tLevelset tQuadric '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ',' RecursiveListOfDouble '}' tEND  */
#line 3002 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-2].l)) == 5){
        int t = (int)(yyvsp[-10].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[5];
          for(int i = 0; i < 5; i++)
            List_Read((yyvsp[-2].l), i, &d[i]);
          double pt[3] = {(yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]};
          double dir[3] = {(yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]};
          gLevelset *ls = new gLevelsetGeneralQuadric(pt, dir, d[0], d[1],
                                                      d[2], d[3], d[4], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[-2].l));
    }
#line 9916 "Gmsh.tab.cpp"
    break;

  case 252: /* LevelSet: tLevelset tSTRING '(' FExpr ')' tAFFECT ListOfDouble tEND  */
#line 3024 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-6].c), "Union")){
        int t = (int)(yyvsp[-4].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++) {
            double d; List_Read((yyvsp[-1].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[-6].c), "Intersection")){
        int t = (int)(yyvsp[-4].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++) {
            double d; List_Read((yyvsp[-1].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[-6].c), "Cut")){
        int t = (int)(yyvsp[-4].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++) {
            double d; List_Read((yyvsp[-1].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetCut(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[-6].c), "Crack")){
        int t = (int)(yyvsp[-4].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++) {
            double d; List_Read((yyvsp[-1].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetCrack(vl, false, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[-6].c), "Reverse")){
        int t = (int)(yyvsp[-4].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[-1].l), 0, &d);
          gLevelset *pl = gLevelset::find((int)d);
          gLevelset *ls = nullptr;
          if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
          else ls = new gLevelsetReverse(pl, t);
          if(ls) gLevelset::add(ls);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp((yyvsp[-6].c), "PostView")){
        int t = (int)(yyvsp[-4].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr((yyvsp[-1].l)) > 0){
            double d; List_Read((yyvsp[-1].l), 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            gLevelset::add(ls);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      Free((yyvsp[-6].c));
      List_Delete((yyvsp[-1].l));
    }
#line 10025 "Gmsh.tab.cpp"
    break;

  case 253: /* LevelSet: tLevelset tSTRING '(' FExpr ')' tAFFECT tBIGSTR tEND  */
#line 3129 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-6].c), "MathEval")){
        int t = (int)(yyvsp[-4].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval((yyvsp[-1].c), t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Unknown levelset '%s'", (yyvsp[-6].c));
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 10045 "Gmsh.tab.cpp"
    break;

  case 254: /* LevelSet: tLevelset tSTRING '{' FExpr '}' tEND  */
#line 3145 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "CutMesh")){
        int t = (int)(yyvsp[-2].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), true, false);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else if(!strcmp((yyvsp[-4].c), "CutMeshTri")){
        int t = (int)(yyvsp[-2].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), true, true);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else if(!strcmp((yyvsp[-4].c), "SplitMesh")){
        int t = (int)(yyvsp[-2].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), false, true);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else
        yymsg(0, "Unknown levelset '%s'", (yyvsp[-4].c));
      Free((yyvsp[-4].c));
    }
#line 10079 "Gmsh.tab.cpp"
    break;

  case 255: /* Delete: tDelete '{' ListOfShapes '}'  */
#line 3180 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      bool changed = false;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->remove(dimTags);
        changed = GModel::current()->getOCCInternals()->getChanged();
        if(changed)
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
      }
      else{
        GModel::current()->getGEOInternals()->remove(dimTags);
        changed = GModel::current()->getGEOInternals()->getChanged();
        if(changed)
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
      }
      if(!changed){
        std::vector<GEntity*> removed;
        GModel::current()->remove(dimTags, removed);
        Msg::Debug("Destroying %zu entities in model", removed.size());
        for(std::size_t i = 0; i < removed.size(); i++) delete removed[i];
      }
      List_Delete((yyvsp[-1].l));
    }
#line 10108 "Gmsh.tab.cpp"
    break;

  case 256: /* Delete: tRecursive tDelete '{' ListOfShapes '}'  */
#line 3205 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      bool changed = false;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->remove(dimTags, true);
        changed = GModel::current()->getOCCInternals()->getChanged();
        if(changed)
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
      }
      else{
        GModel::current()->getGEOInternals()->remove(dimTags, true);
        changed = GModel::current()->getGEOInternals()->getChanged();
        if(changed)
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
      }
      if(!changed){
        std::vector<GEntity*> removed;
        GModel::current()->remove(dimTags, removed, true);
        Msg::Debug("Destroying %zu entities in model", removed.size());
        for(std::size_t i = 0; i < removed.size(); i++) delete removed[i];
      }
      List_Delete((yyvsp[-1].l));
    }
#line 10137 "Gmsh.tab.cpp"
    break;

  case 257: /* Delete: tDelete tSTRING '{' ListOfShapes '}'  */
#line 3230 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      if(!strcmp((yyvsp[-3].c), "Embedded")){
        removeEmbedded(dimTags, -1);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", (yyvsp[-3].c));
      List_Delete((yyvsp[-1].l));
      Free((yyvsp[-3].c));
    }
#line 10153 "Gmsh.tab.cpp"
    break;

  case 258: /* Delete: tDelete tField '[' FExpr ']' tEND  */
#line 3242 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 10163 "Gmsh.tab.cpp"
    break;

  case 259: /* Delete: tDelete tSTRING '[' FExpr ']' tEND  */
#line 3248 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-4].c), "View")){
	int index = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size())
	  delete PView::list[index];
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", (yyvsp[-4].c));
#endif
      Free((yyvsp[-4].c));
    }
#line 10182 "Gmsh.tab.cpp"
    break;

  case 260: /* Delete: tDelete String__Index tEND  */
#line 3263 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-1].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[-1].c), "Meshes")){
	GModel::current()->deleteMesh();
      }
      else if(!strcmp((yyvsp[-1].c), "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp((yyvsp[-1].c), "Physicals")){
	GModel::current()->getGEOInternals()->resetPhysicalGroups();
	GModel::current()->removePhysicalGroups();
      }
      else if(!strcmp((yyvsp[-1].c), "Variables")){
	gmsh_yysymbols.clear();
      }
      else if(!strcmp((yyvsp[-1].c), "Options")){
        ReInitOptions(0);
        InitOptionsGUI(0);
      }
      else{
	if(gmsh_yysymbols.count((yyvsp[-1].c)))
	  gmsh_yysymbols.erase((yyvsp[-1].c));
	else
	  yymsg(0, "Unknown object or expression to delete '%s'", (yyvsp[-1].c));
      }
      Free((yyvsp[-1].c));
    }
#line 10217 "Gmsh.tab.cpp"
    break;

  case 261: /* Delete: tDelete tSTRING tSTRING tEND  */
#line 3294 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-2].c), "Empty") && !strcmp((yyvsp[-1].c), "Views")){
	for(int i = PView::list.size() - 1; i >= 0; i--)
	  if(PView::list[i]->getData()->empty()) delete PView::list[i];
      }
      else
	yymsg(0, "Unknown command 'Delete %s %s'", (yyvsp[-2].c), (yyvsp[-1].c));
#endif
      Free((yyvsp[-2].c)); Free((yyvsp[-1].c));
    }
#line 10233 "Gmsh.tab.cpp"
    break;

  case 262: /* Delete: tDelete tDefineStruct tEND  */
#line 3306 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    }
#line 10241 "Gmsh.tab.cpp"
    break;

  case 263: /* Colorify: tColor ColorExpr '{' ListOfShapes '}'  */
#line 3315 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), false);
      List_Delete((yyvsp[-1].l));
    }
#line 10252 "Gmsh.tab.cpp"
    break;

  case 264: /* Colorify: tRecursive tColor ColorExpr '{' ListOfShapes '}'  */
#line 3322 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), true);
      List_Delete((yyvsp[-1].l));
    }
#line 10263 "Gmsh.tab.cpp"
    break;

  case 265: /* SetPartition: tSetPartition FExpr '{' ListOfShapes '}'  */
#line 3334 "Gmsh.y"
    {
      yymsg(2, "'SetPartition' command is deprecated");
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      for(std::size_t i = 0; i < dimTags.size(); i++){
        GEntity *ge = GModel::current()->getEntityByTag
          (dimTags[i].first, dimTags[i].second);
        if(ge){
          for(std::size_t j = 0; j < ge->getNumMeshElements(); j++)
            ge->getMeshElement(j)->setPartition((int)(yyvsp[-3].d));
        }
      }
      List_Delete((yyvsp[-1].l));
    }
#line 10282 "Gmsh.tab.cpp"
    break;

  case 266: /* Visibility: tShow '{' tDOTS '}'  */
#line 3354 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    }
#line 10290 "Gmsh.tab.cpp"
    break;

  case 267: /* Visibility: tShow tBIGSTR tEND  */
#line 3358 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[-1].c));
    }
#line 10299 "Gmsh.tab.cpp"
    break;

  case 268: /* Visibility: tHide '{' tDOTS '}'  */
#line 3363 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    }
#line 10307 "Gmsh.tab.cpp"
    break;

  case 269: /* Visibility: tHide tBIGSTR tEND  */
#line 3367 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[-1].c));
    }
#line 10316 "Gmsh.tab.cpp"
    break;

  case 270: /* Visibility: tShow '{' ListOfShapes '}'  */
#line 3372 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[-1].l));
    }
#line 10327 "Gmsh.tab.cpp"
    break;

  case 271: /* Visibility: tRecursive tShow '{' ListOfShapes '}'  */
#line 3379 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[-1].l));
    }
#line 10338 "Gmsh.tab.cpp"
    break;

  case 272: /* Visibility: tHide '{' ListOfShapes '}'  */
#line 3386 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[-1].l));
    }
#line 10349 "Gmsh.tab.cpp"
    break;

  case 273: /* Visibility: tRecursive tHide '{' ListOfShapes '}'  */
#line 3393 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[-1].l));
    }
#line 10360 "Gmsh.tab.cpp"
    break;

  case 274: /* Command: String__Index StringExpr tEND  */
#line 3405 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-2].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	Msg::StatusBar(true, "Reading '%s'...", tmp.c_str());
	// Warning: we explicitly ask ParseFile not to fclose() the included
        // file, in order to allow user functions definitions in these files.
        // The files will be closed in the next time OpenFile terminates. If
        // you need to include many many files and don't have functions in
        // the files, use "Merge" instead of "Include", as some OSes limit
        // the number of files a process can open simultaneously. (A better
        // solution would be to modify FunctionManager to reopen the files
        // instead of using the FILE pointer...)
	ParseFile(tmp, false, true);
	SetBoundingBox();
	Msg::StatusBar(true, "Done reading '%s'", tmp.c_str());
      }
      else if(!strcmp((yyvsp[-2].c), "Print")){
	// make sure we have the latest data from CAD internals in GModel (fixes
	// bug where we would have no geometry in the picture if the print
	// command is in the same file as the geometry)
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[-2].c), "Save")){
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp((yyvsp[-2].c), "Merge") || !strcmp((yyvsp[-2].c), "MergeWithBoundingBox")){
	// sync CAD internals here, so that if we e.g. import a STEP file, we
        // have the correct entity tags and the numberings don't clash
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
        MergeFile(tmp, true);
      }
      else if(!strcmp((yyvsp[-2].c), "NonBlockingSystemCall")){
	SystemCall((yyvsp[-1].c));
      }
      else if(!strcmp((yyvsp[-2].c), "System") || !strcmp((yyvsp[-2].c), "SystemCall")){
	SystemCall((yyvsp[-1].c), true);
      }
      else if(!strcmp((yyvsp[-2].c), "SetName")){
	GModel::current()->setName((yyvsp[-1].c));
      }
      else if(!strcmp((yyvsp[-2].c), "CreateDir")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	CreateSingleDir(tmp);
      }
      else if(!strcmp((yyvsp[-2].c), "OnelabRun")){
        Msg::RunOnelabClient((yyvsp[-1].c));
      }
      else if(!strcmp((yyvsp[-2].c), "OptimizeMesh")){
        GModel::current()->optimizeMesh((yyvsp[-1].c));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c)); Free((yyvsp[-1].c));
    }
#line 10437 "Gmsh.tab.cpp"
    break;

  case 275: /* Command: tOnelabRun '(' RecursiveListOfStringExprVar ')' tEND  */
#line 3478 "Gmsh.y"
    {
      int n = List_Nbr((yyvsp[-2].l));
      if(n == 1){
        char *s; List_Read((yyvsp[-2].l), 0, &s);
        Msg::RunOnelabClient(s);
        Free(s);
      }
      else if(n == 2){
        char *s, *t; List_Read((yyvsp[-2].l), 0, &s); List_Read((yyvsp[-2].l), 1, &t);
        Msg::RunOnelabClient(s, t);
        Free(s); Free(t);
      }
      else{
        yymsg(0, "OnelabRun takes one or two arguments");
      }
      List_Delete((yyvsp[-2].l));
    }
#line 10459 "Gmsh.tab.cpp"
    break;

  case 276: /* Command: String__Index String__Index '[' FExpr ']' StringExprVar tEND  */
#line 3496 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-5].c), "View")){
	int index = (int)(yyvsp[-3].d);
	if(index >= 0 && index < (int)PView::list.size()){
          if(!strcmp((yyvsp[-6].c), "Save")){
            std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
            PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
          }
          else if(!strcmp((yyvsp[-6].c), "SendToServer")){
            PView::list[index]->sendToServer((yyvsp[-1].c));
          }
          else{
            yymsg(0, "Unknown operation '%s' on view %d", (yyvsp[-6].c), index);
          }
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s %s'", (yyvsp[-6].c), (yyvsp[-5].c));
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-5].c)); Free((yyvsp[-1].c));
    }
#line 10488 "Gmsh.tab.cpp"
    break;

  case 277: /* Command: String__Index String__Index String__Index '[' FExpr ']' tEND  */
#line 3521 "Gmsh.y"
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp((yyvsp[-6].c), "Background") && !strcmp((yyvsp[-5].c), "Mesh") && !strcmp((yyvsp[-4].c), "View")){
	int index = (int)(yyvsp[-2].d);
	if(index >= 0 && index < (int)PView::list.size())
	  GModel::current()->getFields()->setBackgroundMesh(index);
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[-6].c));
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-5].c)); Free((yyvsp[-4].c));
    }
#line 10507 "Gmsh.tab.cpp"
    break;

  case 278: /* Command: String__Index FExpr tEND  */
#line 3536 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-2].c), "Sleep")) {
	SleepInSeconds((yyvsp[-1].d));
      }
      else if(!strcmp((yyvsp[-2].c), "Remesh")) {
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[-2].c), "Mesh")) {
	int lock = CTX::instance()->lock;
	CTX::instance()->lock = 0;
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
	GModel::current()->mesh((int)(yyvsp[-1].d));
	CTX::instance()->lock = lock;
      }
      else if(!strcmp((yyvsp[-2].c), "SetOrder")) {
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), (yyvsp[-1].d), CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else if(!strcmp((yyvsp[-2].c), "PartitionMesh")) {
        GModel::current()->partitionMesh((yyvsp[-1].d));
      }
      else if(!strcmp((yyvsp[-2].c), "CreateOverlaps")) {
        GModel::current()->createOverlaps((yyvsp[-1].d));
      }
      else if(!strcmp((yyvsp[-2].c), "SetCurrentWindow")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->setCurrentOpenglWindow((int)(yyvsp[-1].d));
#endif
      }
      else if(!strcmp((yyvsp[-2].c), "SplitCurrentWindowHorizontal")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->splitCurrentOpenglWindow('h', (yyvsp[-1].d));
#endif
      }
      else if(!strcmp((yyvsp[-2].c), "SplitCurrentWindowVertical")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->splitCurrentOpenglWindow('v', (yyvsp[-1].d));
#endif
      }
      else {
	yymsg(0, "Unknown command '%s'", (yyvsp[-2].c));
      }
      Free((yyvsp[-2].c));
    }
#line 10563 "Gmsh.tab.cpp"
    break;

  case 279: /* Command: tUnsplitWindow tEND  */
#line 3588 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    }
#line 10573 "Gmsh.tab.cpp"
    break;

  case 280: /* Command: tPlugin '(' tSTRING ')' '.' tSTRING tEND  */
#line 3594 "Gmsh.y"
     {
#if defined(HAVE_PLUGINS)
       try {
	 PluginManager::instance()->action((yyvsp[-4].c), (yyvsp[-1].c), 0);
       }
       catch(...) {
	 yymsg(0, "Failed action '%s' or unknown plugin '%s'", (yyvsp[-1].c), (yyvsp[-4].c));
       }
#endif
       Free((yyvsp[-4].c)); Free((yyvsp[-1].c));
     }
#line 10589 "Gmsh.tab.cpp"
    break;

  case 281: /* Command: tCombine tSTRING tEND  */
#line 3606 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-1].c), "ElementsFromAllViews"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[-1].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[-1].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[-1].c), "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp((yyvsp[-1].c), "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[-1].c));
    }
#line 10625 "Gmsh.tab.cpp"
    break;

  case 282: /* Command: tExit tEND  */
#line 3638 "Gmsh.y"
    {
      Msg::Exit(0, false); // will return 0 only if no meshing error occurred
    }
#line 10633 "Gmsh.tab.cpp"
    break;

  case 283: /* Command: tExit FExpr tEND  */
#line 3642 "Gmsh.y"
    {
      Msg::Exit((int)(yyvsp[-1].d), true); // will always return the specified value
    }
#line 10641 "Gmsh.tab.cpp"
    break;

  case 284: /* Command: tAbort tEND  */
#line 3646 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 10650 "Gmsh.tab.cpp"
    break;

  case 285: /* Command: tSyncModel tEND  */
#line 3651 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
#line 10661 "Gmsh.tab.cpp"
    break;

  case 286: /* Command: tNewModel tEND  */
#line 3658 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 10670 "Gmsh.tab.cpp"
    break;

  case 287: /* Command: tBoundingBox tEND  */
#line 3663 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
#line 10684 "Gmsh.tab.cpp"
    break;

  case 288: /* Command: tBoundingBox '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}' tEND  */
#line 3673 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 10693 "Gmsh.tab.cpp"
    break;

  case 289: /* Command: tDraw tEND  */
#line 3678 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    }
#line 10703 "Gmsh.tab.cpp"
    break;

  case 290: /* Command: tSetChanged tEND  */
#line 3684 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 10715 "Gmsh.tab.cpp"
    break;

  case 291: /* Command: tCreateTopology '{' FExpr ',' FExpr '}' tEND  */
#line 3692 "Gmsh.y"
    {
      if((yyvsp[-4].d)) {
        GModel::current()->makeDiscreteRegionsSimplyConnected();
        GModel::current()->makeDiscreteFacesSimplyConnected();
      }
      GModel::current()->createTopologyFromMesh();
      if((yyvsp[-2].d)) {
        GModel::current()->exportDiscreteGEOInternals();
      }
    }
#line 10730 "Gmsh.tab.cpp"
    break;

  case 292: /* Command: tCreateTopology tEND  */
#line 3703 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    }
#line 10742 "Gmsh.tab.cpp"
    break;

  case 293: /* Command: tClassifySurfaces '{' FExpr ',' FExpr ',' FExpr '}' tEND  */
#line 3711 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d), M_PI);
    }
#line 10750 "Gmsh.tab.cpp"
    break;

  case 294: /* Command: tClassifySurfaces '{' FExpr ',' FExpr ',' FExpr ',' FExpr '}' tEND  */
#line 3715 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 10758 "Gmsh.tab.cpp"
    break;

  case 295: /* Command: tCreateGeometry tEND  */
#line 3719 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    }
#line 10766 "Gmsh.tab.cpp"
    break;

  case 296: /* Command: tCreateGeometry '{' ListOfShapes '}'  */
#line 3723 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[-1].l));
    }
#line 10777 "Gmsh.tab.cpp"
    break;

  case 297: /* Command: tRenumberMeshNodes tEND  */
#line 3730 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    }
#line 10785 "Gmsh.tab.cpp"
    break;

  case 298: /* Command: tRenumberMeshElements tEND  */
#line 3734 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    }
#line 10793 "Gmsh.tab.cpp"
    break;

  case 299: /* Command: tCreateMeshEdges tEND  */
#line 3738 "Gmsh.y"
    {
      GModel::current()->createMEdges();
    }
#line 10801 "Gmsh.tab.cpp"
    break;

  case 300: /* Command: tCreateMeshFaces tEND  */
#line 3742 "Gmsh.y"
    {
      GModel::current()->createMFaces();
    }
#line 10809 "Gmsh.tab.cpp"
    break;

  case 301: /* Command: tRefineMesh tEND  */
#line 3746 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                                    CTX::instance()->mesh.algoSubdivide == 1,
                                    CTX::instance()->mesh.algoSubdivide == 2,
                                    CTX::instance()->mesh.algoSubdivide == 3);
    }
#line 10825 "Gmsh.tab.cpp"
    break;

  case 302: /* Command: tRecombineMesh tEND  */
#line 3758 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    }
#line 10838 "Gmsh.tab.cpp"
    break;

  case 303: /* Command: tAdaptMesh '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}' '{' RecursiveListOfListOfDouble '}' '{' FExpr ',' FExpr '}' tEND  */
#line 3768 "Gmsh.y"
    {
      int lock = CTX::instance()->lock;
      CTX::instance()->lock = 0;
      std::vector<int> technique;
      for(int i = 0; i < List_Nbr((yyvsp[-13].l)); i++){
        double d;
        List_Read((yyvsp[-13].l), i, &d);
        technique.push_back((int)d);
      }
      if(technique.empty()){
        yymsg(0, "Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr((yyvsp[-10].l)); i++){
          double d;
          List_Read((yyvsp[-10].l), i, &d);
          gLevelset *l = gLevelset::find((int)d);
          if(l) f.push_back(l);
          else yymsg(0, "Unknown levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yymsg(0, "Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr((yyvsp[-7].l)) != (int)f.size()){
            yymsg(0, "Number of parameters != number of levelsets");
          }
          else{
            std::vector<std::vector<double> > parameters;
            parameters.resize(List_Nbr((yyvsp[-7].l)));
            for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
              List_T *l = *(List_T**)List_Pointer((yyvsp[-7].l), i);
              for(int j = 0; j < List_Nbr(l); j++){
                double d;
                List_Read(l, j, &d);
                parameters[i].push_back(d);
              }
            }
            int niter = (int)(yyvsp[-4].d);
            bool meshAll = ((yyvsp[-2].d) == 0) ? false : true;
            if(GModel::current()->getOCCInternals() &&
               GModel::current()->getOCCInternals()->getChanged())
              GModel::current()->getOCCInternals()->synchronize(GModel::current());
            if(GModel::current()->getGEOInternals()->getChanged())
              GModel::current()->getGEOInternals()->synchronize(GModel::current());
            GModel::current()->adaptMesh(technique, f, parameters, niter, meshAll);
          }
        }
      }
      List_Delete((yyvsp[-13].l));
      List_Delete((yyvsp[-10].l));
      for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[-7].l), i));
      List_Delete((yyvsp[-7].l));
      CTX::instance()->lock = lock;
    }
#line 10900 "Gmsh.tab.cpp"
    break;

  case 304: /* Command: tTransformMesh '{' RecursiveListOfDouble '}' tEND  */
#line 3826 "Gmsh.y"
    {
      std::vector<double> affineTransform;
      ListOfDouble2Vector((yyvsp[-2].l), affineTransform);
      if(affineTransform.size() >= 12) {
        std::vector<GEntity *> entities;
        GModel::current()->getEntities(entities);
        for(auto e : entities) {
          for(std::size_t j = 0; j < e->getNumMeshVertices(); j++) {
            MVertex *v = e->getMeshVertex(j);
            SPoint3 pt = v->point();
            pt.transform(affineTransform);
            v->setXYZ(pt);
          }
        }
      }
      else
        yymsg(0, "Affine transform matrix requires at least 12 entries");
      List_Delete((yyvsp[-2].l));
    }
#line 10924 "Gmsh.tab.cpp"
    break;

  case 305: /* Command: tTransformMesh '{' RecursiveListOfDouble '}' '{' MultipleShape '}' tEND  */
#line 3846 "Gmsh.y"
    {
      std::vector<double> affineTransform;
      ListOfDouble2Vector((yyvsp[-5].l), affineTransform);
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-2].l), dimTags);
      for(std::size_t i = 0; i < dimTags.size(); i++) {
        GEntity *e = GModel::current()->getEntityByTag
          (dimTags[i].first, dimTags[i].second);
        if(e){
          for(std::size_t j = 0; j < e->getNumMeshVertices(); j++) {
            MVertex *v = e->getMeshVertex(j);
            SPoint3 pt = v->point();
            pt.transform(affineTransform);
            v->setXYZ(pt);
          }
        }
      }
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-2].l));
    }
#line 10949 "Gmsh.tab.cpp"
    break;

  case 306: /* Slide: tSlide '(' '{' RecursiveListOfDouble '}' ',' StringExpr ',' StringExpr ')' tEND  */
#line 3872 "Gmsh.y"
     {
#if defined(HAVE_POPPLER)
       std::vector<int> is;
       for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
	 double d;
	 List_Read((yyvsp[-7].l), i, &d);
	 is.push_back ((int) d);
       }
       gmshPopplerWrapper::instance()->setMacroForPages(is, (yyvsp[-4].c), (yyvsp[-2].c) );
#endif
     }
#line 10965 "Gmsh.tab.cpp"
    break;

  case 307: /* Loop: tFor '(' FExpr tDOTS FExpr ')'  */
#line 3888 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-1].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[-3].d) > (yyvsp[-1].d))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
#line 10986 "Gmsh.tab.cpp"
    break;

  case 308: /* Loop: tFor '(' FExpr tDOTS FExpr tDOTS FExpr ')'  */
#line 3905 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-5].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[-1].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[-1].d) > 0. && (yyvsp[-5].d) > (yyvsp[-3].d)) || ((yyvsp[-1].d) < 0. && (yyvsp[-5].d) < (yyvsp[-3].d)))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
#line 11007 "Gmsh.tab.cpp"
    break;

  case 309: /* Loop: tFor tSTRING tIn '{' FExpr tDOTS FExpr '}'  */
#line 3922 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-1].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[-6].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-6].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[-3].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[-3].d) > (yyvsp[-1].d))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free((yyvsp[-6].c));
    }
#line 11033 "Gmsh.tab.cpp"
    break;

  case 310: /* Loop: tFor tSTRING tIn '{' FExpr tDOTS FExpr tDOTS FExpr '}'  */
#line 3944 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-5].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[-1].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[-8].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-8].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[-5].d);
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[-1].d) > 0. && (yyvsp[-5].d) > (yyvsp[-3].d)) || ((yyvsp[-1].d) < 0. && (yyvsp[-5].d) < (yyvsp[-3].d)))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free((yyvsp[-8].c));
    }
#line 11059 "Gmsh.tab.cpp"
    break;

  case 311: /* Loop: tEndFor  */
#line 3966 "Gmsh.y"
    {
      if(ImbricatedLoop <= 0){
	yymsg(0, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double step = LoopControlVariablesTab[ImbricatedLoop - 1][2];
        std::string name = LoopControlVariablesNameTab[ImbricatedLoop - 1];
        if(name.size()){
          if(!gmsh_yysymbols.count(name))
            yymsg(0, "Unknown loop variable '%s'", name.c_str());
          else{
            gmsh_yysymbol &s(gmsh_yysymbols[name]);
            if(!s.list && s.value.size()){
              s.value[0] += step;
              LoopControlVariablesTab[ImbricatedLoop - 1][0] = s.value[0];
            }
            else
              yymsg(0, "Bad loop variable %s", name.c_str());
          }
        }
        else{
          LoopControlVariablesTab[ImbricatedLoop - 1][0] += step;
        }
	double x0 = LoopControlVariablesTab[ImbricatedLoop - 1][0];
	double x1 = LoopControlVariablesTab[ImbricatedLoop - 1][1];
        if((step > 0. && x0 <= x1) || (step < 0. && x0 >= x1)){
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    }
#line 11098 "Gmsh.tab.cpp"
    break;

  case 312: /* Loop: tMacro tSTRING  */
#line 4001 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(nullptr, "Return");
      Free((yyvsp[0].c));
    }
#line 11110 "Gmsh.tab.cpp"
    break;

  case 313: /* Loop: tMacro StringExpr  */
#line 4009 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(nullptr, "Return");
      Free((yyvsp[0].c));
    }
#line 11122 "Gmsh.tab.cpp"
    break;

  case 314: /* Loop: tReturn  */
#line 4017 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 11132 "Gmsh.tab.cpp"
    break;

  case 315: /* Loop: tCall String__Index tEND  */
#line 4023 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11143 "Gmsh.tab.cpp"
    break;

  case 316: /* Loop: tCall StringExpr tEND  */
#line 4030 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11154 "Gmsh.tab.cpp"
    break;

  case 317: /* Loop: tIf '(' FExpr ')'  */
#line 4037 "Gmsh.y"
    {
      ImbricatedTest++;
      if(ImbricatedTest > MAX_RECUR_TESTS-1){
	yymsg(0, "Reached maximum number of imbricated tests");
        ImbricatedTest = MAX_RECUR_TESTS-1;
      }

      if((yyvsp[-1].d)){
        // Current test is true
        statusImbricatedTests[ImbricatedTest] = 1;
      }
      else{
        statusImbricatedTests[ImbricatedTest] = 0;
        // Go after the next ElseIf or Else or EndIf
        int type_until2 = 0;
        skipTest("If", "EndIf", "ElseIf", 4, &type_until2);
        if(!type_until2) ImbricatedTest--; // EndIf reached
      }
    }
#line 11178 "Gmsh.tab.cpp"
    break;

  case 318: /* Loop: tElseIf '(' FExpr ')'  */
#line 4057 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if(statusImbricatedTests[ImbricatedTest]){
          // Last test (If or ElseIf) was true, thus go after EndIf (out of If EndIf)
          skip("If", "EndIf");
          ImbricatedTest--;
        }
        else{
          // Previous test(s) (If and ElseIf) not yet true
          if((yyvsp[-1].d)){
            statusImbricatedTests[ImbricatedTest] = 1;
          }
          else{
            // Current test still not true: statusImbricatedTests[ImbricatedTest] = 0;
            // Go after the next ElseIf or Else or EndIf
            int type_until2 = 0;
            skipTest("If", "EndIf", "ElseIf", 4, &type_until2);
            if(!type_until2) ImbricatedTest--;
          }
        }
      }
      else{
	yymsg(0, "Orphan ElseIf");
      }
    }
#line 11208 "Gmsh.tab.cpp"
    break;

  case 319: /* Loop: tElse  */
#line 4083 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if(statusImbricatedTests[ImbricatedTest]){
          skip("If", "EndIf");
          ImbricatedTest--;
        }
      }
      else{
	yymsg(0, "Orphan Else");
      }
    }
#line 11224 "Gmsh.tab.cpp"
    break;

  case 320: /* Loop: tEndIf  */
#line 4095 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 11234 "Gmsh.tab.cpp"
    break;

  case 321: /* Extrude: tExtrude VExpr '{' ListOfShapes '}'  */
#line 4106 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->extrude
          (inDimTags, (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], outDimTags);
      }
      else{
        r = GModel::current()->getGEOInternals()->extrude
          (inDimTags, (yyvsp[-3].v)[0], (yyvsp[-3].v)[1], (yyvsp[-3].v)[2], outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[-1].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
#line 11256 "Gmsh.tab.cpp"
    break;

  case 322: /* Extrude: tExtrude '{' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes '}'  */
#line 4124 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->revolve
          (inDimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-4].d), outDimTags);
      }
      else{
        r = GModel::current()->getGEOInternals()->revolve
          (inDimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-4].d), outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[-1].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
#line 11278 "Gmsh.tab.cpp"
    break;

  case 323: /* Extrude: tExtrude '{' VExpr ',' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes '}'  */
#line 4142 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->twist
          (inDimTags, (yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2],
           (yyvsp[-4].d), outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[-1].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
#line 11300 "Gmsh.tab.cpp"
    break;

  case 324: /* $@10: %empty  */
#line 4160 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 11310 "Gmsh.tab.cpp"
    break;

  case 325: /* Extrude: tExtrude VExpr '{' ListOfShapes $@10 ExtrudeParameters '}'  */
#line 4166 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-3].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->extrude
          (inDimTags, (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], outDimTags, &extr);
      }
      else{
        r = GModel::current()->getGEOInternals()->extrude
          (inDimTags, (yyvsp[-5].v)[0], (yyvsp[-5].v)[1], (yyvsp[-5].v)[2], outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[-3].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
#line 11332 "Gmsh.tab.cpp"
    break;

  case 326: /* $@11: %empty  */
#line 4184 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 11342 "Gmsh.tab.cpp"
    break;

  case 327: /* Extrude: tExtrude '{' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes $@11 ExtrudeParameters '}'  */
#line 4190 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-3].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->revolve
          (inDimTags, (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-6].d), outDimTags,
           &extr);
      }
      else{
        r = GModel::current()->getGEOInternals()->revolve
          (inDimTags, (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2], (yyvsp[-6].d), outDimTags,
           &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[-3].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
#line 11366 "Gmsh.tab.cpp"
    break;

  case 328: /* $@12: %empty  */
#line 4210 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 11376 "Gmsh.tab.cpp"
    break;

  case 329: /* Extrude: tExtrude '{' VExpr ',' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes $@12 ExtrudeParameters '}'  */
#line 4216 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-3].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->twist
          (inDimTags, (yyvsp[-8].v)[0], (yyvsp[-8].v)[1], (yyvsp[-8].v)[2], (yyvsp[-12].v)[0], (yyvsp[-12].v)[1], (yyvsp[-12].v)[2], (yyvsp[-10].v)[0], (yyvsp[-10].v)[1], (yyvsp[-10].v)[2],
           (yyvsp[-6].d),  outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[-3].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
#line 11398 "Gmsh.tab.cpp"
    break;

  case 330: /* $@13: %empty  */
#line 4234 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 11408 "Gmsh.tab.cpp"
    break;

  case 331: /* Extrude: tExtrude '{' ListOfShapes $@13 ExtrudeParameters '}'  */
#line 4240 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-3].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Boundary layer extrusion not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->boundaryLayer
          (inDimTags, outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[-3].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
#line 11429 "Gmsh.tab.cpp"
    break;

  case 332: /* Extrude: tExtrude '{' ListOfShapes '}' tUsing tWire '{' FExpr '}'  */
#line 4257 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-6].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPipe(inDimTags, (int)(yyvsp[-1].d), outDimTags);
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[-6].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
#line 11449 "Gmsh.tab.cpp"
    break;

  case 333: /* Extrude: tThruSections ListOfDouble  */
#line 4273 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[0].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, false, false, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add thrusections");
      List_Delete((yyvsp[0].l));
    }
#line 11470 "Gmsh.tab.cpp"
    break;

  case 334: /* Extrude: tRuled tThruSections ListOfDouble  */
#line 4290 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[0].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, false, true, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add ruled thrusections");
      List_Delete((yyvsp[0].l));
    }
#line 11491 "Gmsh.tab.cpp"
    break;

  case 335: /* Extrude: tFillet '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}'  */
#line 4308 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> regions, edges;
        ListOfDouble2Vector((yyvsp[-7].l), regions); ListOfDouble2Vector((yyvsp[-4].l), edges);
        std::vector<double> radii;
        ListOfDouble2Vector((yyvsp[-1].l), radii);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->fillet
          (regions, edges, radii, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not fillet shapes");
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-1].l));
    }
#line 11517 "Gmsh.tab.cpp"
    break;

  case 336: /* Extrude: tChamfer '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}'  */
#line 4331 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> regions, edges, surfaces;
        ListOfDouble2Vector((yyvsp[-10].l), regions); ListOfDouble2Vector((yyvsp[-7].l), edges);
        ListOfDouble2Vector((yyvsp[-4].l), surfaces);
        std::vector<double> distances;
        ListOfDouble2Vector((yyvsp[-1].l), distances);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->chamfer
          (regions, edges, surfaces, distances, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Chamfer only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not chamfer shapes");
      List_Delete((yyvsp[-10].l));
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-1].l));
    }
#line 11545 "Gmsh.tab.cpp"
    break;

  case 337: /* ExtrudeParameters: ExtrudeParameter  */
#line 4358 "Gmsh.y"
    {
    }
#line 11552 "Gmsh.tab.cpp"
    break;

  case 338: /* ExtrudeParameters: ExtrudeParameters ExtrudeParameter  */
#line 4361 "Gmsh.y"
    {
    }
#line 11559 "Gmsh.tab.cpp"
    break;

  case 339: /* ExtrudeParameter: tLayers '{' FExpr '}' tEND  */
#line 4367 "Gmsh.y"
    {
      int n = (int)fabs((yyvsp[-2].d));
      if(n){ // we accept n==0 to easily disable layers
        extr.mesh.ExtrudeMesh = true;
        extr.mesh.NbLayer = 1;
        extr.mesh.NbElmLayer.clear();
        extr.mesh.hLayer.clear();
        extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[-2].d)));
        extr.mesh.hLayer.push_back(1.);
      }
    }
#line 11575 "Gmsh.tab.cpp"
    break;

  case 340: /* ExtrudeParameter: tLayers '{' ListOfDouble ',' ListOfDouble '}' tEND  */
#line 4379 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[-4].l));
      if(List_Nbr((yyvsp[-4].l)) == List_Nbr((yyvsp[-2].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	  double d;
	  List_Read((yyvsp[-4].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[-2].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d}", List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-2].l)));
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
    }
#line 11599 "Gmsh.tab.cpp"
    break;

  case 341: /* ExtrudeParameter: tScaleLast tEND  */
#line 4399 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
#line 11607 "Gmsh.tab.cpp"
    break;

  case 342: /* ExtrudeParameter: tRecombine tEND  */
#line 4403 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
#line 11615 "Gmsh.tab.cpp"
    break;

  case 343: /* ExtrudeParameter: tRecombine FExpr tEND  */
#line 4407 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 11623 "Gmsh.tab.cpp"
    break;

  case 344: /* ExtrudeParameter: tQuadTriAddVerts tEND  */
#line 4411 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 11631 "Gmsh.tab.cpp"
    break;

  case 345: /* ExtrudeParameter: tQuadTriAddVerts tRecombLaterals tEND  */
#line 4415 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 11639 "Gmsh.tab.cpp"
    break;

  case 346: /* ExtrudeParameter: tQuadTriNoNewVerts tEND  */
#line 4419 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 11647 "Gmsh.tab.cpp"
    break;

  case 347: /* ExtrudeParameter: tQuadTriNoNewVerts tRecombLaterals tEND  */
#line 4423 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 11655 "Gmsh.tab.cpp"
    break;

  case 348: /* ExtrudeParameter: tHole '(' FExpr ')' tAFFECT ListOfDouble tUsing FExpr tEND  */
#line 4427 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      int num = (int)(yyvsp[-6].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[-1].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[-3].l));
    }
#line 11668 "Gmsh.tab.cpp"
    break;

  case 349: /* ExtrudeParameter: tUsing tSTRING '[' FExpr ']' tEND  */
#line 4436 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 11680 "Gmsh.tab.cpp"
    break;

  case 350: /* BooleanOperator: tBooleanUnion  */
#line 4448 "Gmsh.y"
                  { (yyval.i) = OCC_Internals::Union; }
#line 11686 "Gmsh.tab.cpp"
    break;

  case 351: /* BooleanOperator: tBooleanIntersection  */
#line 4449 "Gmsh.y"
                         { (yyval.i) = OCC_Internals::Intersection; }
#line 11692 "Gmsh.tab.cpp"
    break;

  case 352: /* BooleanOperator: tBooleanDifference  */
#line 4450 "Gmsh.y"
                       { (yyval.i) = OCC_Internals::Difference; }
#line 11698 "Gmsh.tab.cpp"
    break;

  case 353: /* BooleanOperator: tBooleanSection  */
#line 4451 "Gmsh.y"
                    { (yyval.i) = OCC_Internals::Section; }
#line 11704 "Gmsh.tab.cpp"
    break;

  case 354: /* BooleanOperator: tBooleanFragments  */
#line 4452 "Gmsh.y"
                      { (yyval.i) = OCC_Internals::Fragments; }
#line 11710 "Gmsh.tab.cpp"
    break;

  case 355: /* BooleanOption: %empty  */
#line 4456 "Gmsh.y"
  { (yyval.i) = 0; }
#line 11716 "Gmsh.tab.cpp"
    break;

  case 356: /* BooleanOption: tDelete tEND  */
#line 4457 "Gmsh.y"
                 { (yyval.i) = 1; }
#line 11722 "Gmsh.tab.cpp"
    break;

  case 357: /* BooleanOption: tRecursive tDelete tEND  */
#line 4458 "Gmsh.y"
                            { (yyval.i) = 2; }
#line 11728 "Gmsh.tab.cpp"
    break;

  case 358: /* BooleanOption: tDelete FExpr tEND  */
#line 4459 "Gmsh.y"
                       { (yyval.i) = (yyvsp[-1].d) ? 1 : 0; }
#line 11734 "Gmsh.tab.cpp"
    break;

  case 359: /* BooleanOption: tRecursive tDelete FExpr tEND  */
#line 4460 "Gmsh.y"
                                  { (yyval.i) = (yyvsp[-1].d) ? 2 : 0; }
#line 11740 "Gmsh.tab.cpp"
    break;

  case 360: /* Boolean: BooleanOperator '{' ListOfShapes BooleanOption '}' '{' ListOfShapes BooleanOption '}'  */
#line 4465 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs((yyvsp[-6].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[-2].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[-8].i), object, tool, out, outMap, (yyvsp[-5].i), (yyvsp[-1].i));
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[-6].l));
      List_Delete((yyvsp[-2].l));
    }
#line 11767 "Gmsh.tab.cpp"
    break;

  case 361: /* Boolean: tShapeFromFile '(' StringExprVar ')'  */
#line 4488 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > out;
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could import shape");
      Free((yyvsp[-1].c));
    }
#line 11787 "Gmsh.tab.cpp"
    break;

  case 362: /* BooleanShape: BooleanOperator '(' FExpr ')' tAFFECT '{' ListOfShapes BooleanOption '}' '{' ListOfShapes BooleanOption '}' tEND  */
#line 4508 "Gmsh.y"
    {
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs((yyvsp[-7].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[-3].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          ((int)(yyvsp[-11].d), (OCC_Internals::BooleanOperator)(yyvsp[-13].i), object, tool, out, outMap, (yyvsp[-6].i), (yyvsp[-2].i));
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-3].l));
    }
#line 11809 "Gmsh.tab.cpp"
    break;

  case 363: /* TransfiniteType: %empty  */
#line 4529 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 11817 "Gmsh.tab.cpp"
    break;

  case 364: /* TransfiniteType: tUsing tSTRING FExpr  */
#line 4533 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-1].c), "Progression") || !strcmp((yyvsp[-1].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[-1].c), "Bump"))
        (yyval.v)[0] = 2.;
      else if(!strcmp((yyvsp[-1].c), "Beta"))
        (yyval.v)[0] = 3.;
      else if(!strcmp((yyvsp[-1].c), "Progression_HWall"))
        (yyval.v)[0] = 5.;
      else if(!strcmp((yyvsp[-1].c), "Bump_HWall"))
        (yyval.v)[0] = 6.;
      else if(!strcmp((yyvsp[-1].c), "Beta_HWall"))
        (yyval.v)[0] = 7.;
      else if(!strcmp((yyvsp[-1].c), "Beta_Symmetrical"))
        (yyval.v)[0] = 8.;
      else if(!strcmp((yyvsp[-1].c), "Beta_Symmetrical_HWall"))
        (yyval.v)[0] = 9.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[0].d);
      Free((yyvsp[-1].c));
    }
#line 11846 "Gmsh.tab.cpp"
    break;

  case 365: /* TransfiniteArrangement: %empty  */
#line 4560 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
#line 11854 "Gmsh.tab.cpp"
    break;

  case 366: /* TransfiniteArrangement: tSTRING  */
#line 4564 "Gmsh.y"
    {
      if(!strcmp((yyvsp[0].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[0].c), "Left"))
	(yyval.i) = -1;
      else if(!strcmp((yyvsp[0].c), "AlternateRight"))
	(yyval.i) = 2;
      else if(!strcmp((yyvsp[0].c), "AlternateLeft"))
	(yyval.i) = -2;
      else // "Alternate" -> "Alternate Right"
	(yyval.i) = 2;
      Free((yyvsp[0].c));
    }
#line 11872 "Gmsh.tab.cpp"
    break;

  case 367: /* TransfiniteCorners: %empty  */
#line 4580 "Gmsh.y"
   {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 11880 "Gmsh.tab.cpp"
    break;

  case 368: /* TransfiniteCorners: tAFFECT ListOfDouble  */
#line 4584 "Gmsh.y"
   {
     (yyval.l) = (yyvsp[0].l);
   }
#line 11888 "Gmsh.tab.cpp"
    break;

  case 369: /* RecombineAngle: %empty  */
#line 4589 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
#line 11896 "Gmsh.tab.cpp"
    break;

  case 370: /* RecombineAngle: tAFFECT FExpr  */
#line 4593 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 11904 "Gmsh.tab.cpp"
    break;

  case 371: /* PeriodicTransform: %empty  */
#line 4599 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 11912 "Gmsh.tab.cpp"
    break;

  case 372: /* PeriodicTransform: tAffine ListOfDouble  */
#line 4603 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11920 "Gmsh.tab.cpp"
    break;

  case 373: /* Constraints: tMeshSize ListOfDoubleOrAll tAFFECT FExpr tEND  */
#line 4610 "Gmsh.y"
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      List_T *tmp = (yyvsp[-3].l);
      if(!(yyvsp[-3].l)){
        tmp = List_Create(100, 100, sizeof(double));
        getAllElementaryTags(0, tmp);
      }
      for(int i = 0; i < List_Nbr(tmp); i++){
        double d;
        List_Read(tmp, i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[-1].d));
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[-1].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[-1].d));
      }
      List_Delete(tmp);
    }
#line 11946 "Gmsh.tab.cpp"
    break;

  case 374: /* Constraints: tCharacteristic tLength ListOfDoubleOrAll tAFFECT FExpr tEND  */
#line 4633 "Gmsh.y"
    {
      List_T *tmp = (yyvsp[-3].l);
      if(!(yyvsp[-3].l)){
        tmp = List_Create(100, 100, sizeof(double));
        getAllElementaryTags(0, tmp);
      }
      for(int i = 0; i < List_Nbr(tmp); i++){
        double d;
        List_Read(tmp, i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[-1].d));
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[-1].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[-1].d));
      }
      List_Delete(tmp);
    }
#line 11969 "Gmsh.tab.cpp"
    break;

  case 375: /* Constraints: tTransfinite tCurve ListOfDoubleOrAll tAFFECT FExpr TransfiniteType tEND  */
#line 4652 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      int type = (int)(yyvsp[-1].v)[0];
      double coef = (yyvsp[-1].v)[1];
      int npoints = ((int)(yyvsp[-2].d) < 2) ? 2 : (int)(yyvsp[-2].d);
      if(!(yyvsp[-4].l)){
        GModel::current()->getGEOInternals()->setTransfiniteLine
          (0, npoints, type, coef);
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
          (*it)->meshAttributes.nbPointsTransfinite = npoints;
          (*it)->meshAttributes.typeTransfinite = type;
          (*it)->meshAttributes.coeffTransfinite = coef;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
          double d;
          List_Read((yyvsp[-4].l), i, &d);
          int j = (int)fabs(d);
          for(int sig = -1; sig <= 1; sig += 2){
            GModel::current()->getGEOInternals()->setTransfiniteLine
              (sig * j, npoints, type * gmsh_sign(d), coef);
            GEdge *ge = GModel::current()->getEdgeByTag(sig * j);
            if(ge){
              ge->meshAttributes.method = MESH_TRANSFINITE;
              ge->meshAttributes.nbPointsTransfinite = npoints;
              ge->meshAttributes.typeTransfinite = type * gmsh_sign(d);
              ge->meshAttributes.coeffTransfinite = coef;
            }
          }
        }
        List_Delete((yyvsp[-4].l));
      }
    }
#line 12014 "Gmsh.tab.cpp"
    break;

  case 376: /* Constraints: tTransfinite tSurface ListOfDoubleOrAll TransfiniteCorners TransfiniteArrangement tEND  */
#line 4693 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      std::vector<int> corners; ListOfDouble2Vector((yyvsp[-2].l), corners);
      if(!(yyvsp[-3].l)){
        GModel::current()->getGEOInternals()->setTransfiniteSurface(0, (yyvsp[-1].i), corners);
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
          (*it)->meshAttributes.transfiniteArrangement = (yyvsp[-1].i);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
          double d;
          List_Read((yyvsp[-3].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteSurface(tag, (yyvsp[-1].i), corners);
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf){
            gf->meshAttributes.method = MESH_TRANSFINITE;
            gf->meshAttributes.transfiniteArrangement = (yyvsp[-1].i);
            gf->meshAttributes.corners.clear();
            if(corners.empty() || corners.size() == 3 || corners.size() == 4){
              for(std::size_t j = 0; j < corners.size(); j++){
                GVertex *gv = GModel::current()->getVertexByTag(corners[j]);
                if(gv)
                  gf->meshAttributes.corners.push_back(gv);
                else
                  yymsg(0, "Unknown model point with tag %d", corners[j]);
              }
            }
            else{
              yymsg(0, "Transfinite surface requires 3 or 4 corners vertices");
            }
          }
        }
        List_Delete((yyvsp[-3].l));
      }
      List_Delete((yyvsp[-2].l));
    }
#line 12063 "Gmsh.tab.cpp"
    break;

  case 377: /* Constraints: tTransfinite tVolume ListOfDoubleOrAll TransfiniteCorners tEND  */
#line 4738 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      std::vector<int> corners; ListOfDouble2Vector((yyvsp[-1].l), corners);
      if(!(yyvsp[-2].l)){
        GModel::current()->getGEOInternals()->setTransfiniteVolume(0, corners);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          double d;
          List_Read((yyvsp[-2].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteVolume(tag, corners);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr){
            gr->meshAttributes.method = MESH_TRANSFINITE;
            gr->meshAttributes.corners.clear();
            if(corners.empty() || corners.size() == 6 || corners.size() == 8){
              for(std::size_t i = 0; i < corners.size(); i++){
                GVertex *gv = GModel::current()->getVertexByTag(corners[i]);
                if(gv)
                  gr->meshAttributes.corners.push_back(gv);
                else
                  yymsg(0, "Unknown model point with tag %d", corners[i]);
              }
            }
          }
        }
        List_Delete((yyvsp[-2].l));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 12107 "Gmsh.tab.cpp"
    break;

  case 378: /* Constraints: tTransfQuadTri ListOfDoubleOrAll tEND  */
#line 4778 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[-1].l)){
        GModel::current()->getGEOInternals()->setTransfiniteVolumeQuadTri(0);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++)
          (*it)->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteVolumeQuadTri(tag);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr) gr->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
        }
        List_Delete((yyvsp[-1].l));
      }
    }
#line 12136 "Gmsh.tab.cpp"
    break;

  case 379: /* Constraints: tSetTag GeoEntity '(' FExpr ',' FExpr ')' tEND  */
#line 4803 "Gmsh.y"
    {
      int dim = (int)(yyvsp[-6].i);
      int tag = (int)(yyvsp[-4].d);
      int new_tag = (int)(yyvsp[-2].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    }
#line 12147 "Gmsh.tab.cpp"
    break;

  case 380: /* Constraints: tSetMaxTag GeoEntity '(' FExpr ')' tEND  */
#line 4810 "Gmsh.y"
    {
      int dim = (int)(yyvsp[-4].i);
      int tag = (int)(yyvsp[-2].d);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->setMaxTag(dim, tag);
      }
      else {
        GModel::current()->getGEOInternals()->setMaxTag(dim, tag);
      }
    }
#line 12162 "Gmsh.tab.cpp"
    break;

  case 381: /* Constraints: tMeshAlgorithm tSurface '{' RecursiveListOfDouble '}' tAFFECT FExpr tEND  */
#line 4821 "Gmsh.y"
    {
      // mesh algorithm constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
        double d;
        List_Read((yyvsp[-4].l), i, &d);
        int tag = (int)d;
        GModel::current()->getGEOInternals()->setMeshAlgorithm(2, tag, (int)(yyvsp[-1].d));
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(gf) gf->setMeshingAlgo((int)(yyvsp[-1].d));
      }
      List_Delete((yyvsp[-4].l));
    }
#line 12183 "Gmsh.tab.cpp"
    break;

  case 382: /* Constraints: tMeshSizeFromBoundary tSurface '{' RecursiveListOfDouble '}' tAFFECT FExpr tEND  */
#line 4838 "Gmsh.y"
    {
      // mesh size from boundary onstraints are stored in GEO internals in
      // addition to GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
        double d;
        List_Read((yyvsp[-4].l), i, &d);
        int tag = (int)d;
        GModel::current()->getGEOInternals()->setMeshSizeFromBoundary(2, tag, (int)(yyvsp[-1].d));
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(gf) gf->setMeshSizeFromBoundary((int)(yyvsp[-1].d));
      }
      List_Delete((yyvsp[-4].l));
    }
#line 12204 "Gmsh.tab.cpp"
    break;

  case 383: /* Constraints: tRecombine tSurface ListOfDoubleOrAll RecombineAngle tEND  */
#line 4855 "Gmsh.y"
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[-2].l)){
        GModel::current()->getGEOInternals()->setRecombine(2, 0, (yyvsp[-1].i));
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.recombine = 1;
          (*it)->meshAttributes.recombineAngle = (yyvsp[-1].i);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          double d;
          List_Read((yyvsp[-2].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setRecombine(2, tag, (yyvsp[-1].i));
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf){
            gf->meshAttributes.recombine = 1;
            gf->meshAttributes.recombineAngle = (yyvsp[-1].i);
          }
        }
        List_Delete((yyvsp[-2].l));
      }
    }
#line 12238 "Gmsh.tab.cpp"
    break;

  case 384: /* Constraints: tRecombine tVolume ListOfDoubleOrAll tEND  */
#line 4885 "Gmsh.y"
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[-1].l)){
        GModel::current()->getGEOInternals()->setRecombine(3, 0, 0.);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++){
          (*it)->meshAttributes.recombine3D = 1;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setRecombine(3, tag, 0.);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr) gr->meshAttributes.recombine3D = 1;
        }
        List_Delete((yyvsp[-1].l));
      }
    }
#line 12268 "Gmsh.tab.cpp"
    break;

  case 385: /* Constraints: tSmoother tSurface ListOfDoubleOrAll tAFFECT FExpr tEND  */
#line 4911 "Gmsh.y"
    {
      // smoothing constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[-3].l)){
        GModel::current()->getGEOInternals()->setSmoothing(0, (int)(yyvsp[-1].d));
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.transfiniteSmoothing = (int)(yyvsp[-1].d);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
          double d;
          List_Read((yyvsp[-3].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setSmoothing(tag, (int)(yyvsp[-1].d));
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf) gf->meshAttributes.transfiniteSmoothing = (int)(yyvsp[-1].d);
        }
        List_Delete((yyvsp[-3].l));
      }
    }
#line 12298 "Gmsh.tab.cpp"
    break;

  case 386: /* Constraints: tPeriodic tCurve '{' RecursiveListOfDouble '}' tAFFECT '{' RecursiveListOfDouble '}' PeriodicTransform tEND  */
#line 4938 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-3].l))){
        yymsg(0, "Wrong number of curves in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr((yyvsp[-1].l)) != 0) {
          if(List_Nbr((yyvsp[-1].l)) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries "
                  "(%d provided)", List_Nbr((yyvsp[-1].l)));
          }
          else {
            transfo.resize(List_Nbr((yyvsp[-1].l)));
            for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
              List_Read((yyvsp[-1].l), i, &transfo[i]);
          }
        }
        for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-3].l), i, &d_master);
          List_Read((yyvsp[-7].l), i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          addPeriodicEdge(j_slave, j_master, transfo);
        }
      }
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-3].l));
    }
#line 12333 "Gmsh.tab.cpp"
    break;

  case 387: /* Constraints: tPeriodic tSurface '{' RecursiveListOfDouble '}' tAFFECT '{' RecursiveListOfDouble '}' PeriodicTransform tEND  */
#line 4970 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-3].l))){
        yymsg(0, "Wrong number surfaces in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        if(List_Nbr((yyvsp[-1].l)) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries "
                "(%d provided)", List_Nbr((yyvsp[-1].l)));
        }
        else {
          std::vector<double> transfo(16,0);
          for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
            List_Read((yyvsp[-1].l), i, &transfo[i]);
          for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
            double d_master, d_slave;
            List_Read((yyvsp[-3].l), i, &d_master);
            List_Read((yyvsp[-7].l), i, &d_slave);
            addPeriodicFace(d_slave, d_master, transfo);
          }
        }
      }
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-3].l));
    }
#line 12364 "Gmsh.tab.cpp"
    break;

  case 388: /* Constraints: tPeriodic tCurve '{' RecursiveListOfDouble '}' tAFFECT '{' RecursiveListOfDouble '}' tRotate '{' VExpr ',' VExpr ',' FExpr '}' tEND  */
#line 4998 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-14].l)) != List_Nbr((yyvsp[-10].l))){
        yymsg(0, "Wrong number of curves in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[-10].l)), List_Nbr((yyvsp[-14].l)));
      }
      else{
        SPoint3 axis((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]);
        SPoint3 origin((yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]);
        double  angle((yyvsp[-2].d));
        SPoint3 translation(0, 0, 0);

        std::vector<double> transfo;
        computeAffineTransformation(origin, axis, angle, translation, transfo);

        for(int i = 0; i < List_Nbr((yyvsp[-14].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-10].l), i, &d_master);
          List_Read((yyvsp[-14].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[-14].l));
      List_Delete((yyvsp[-10].l));
    }
#line 12393 "Gmsh.tab.cpp"
    break;

  case 389: /* Constraints: tPeriodic tSurface '{' RecursiveListOfDouble '}' tAFFECT '{' RecursiveListOfDouble '}' tRotate '{' VExpr ',' VExpr ',' FExpr '}' tEND  */
#line 5024 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-14].l)) != List_Nbr((yyvsp[-10].l))){
        yymsg(0, "Wrong number of surfaces in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[-10].l)), List_Nbr((yyvsp[-14].l)));
      }
      else{
        SPoint3 origin((yyvsp[-4].v)[0], (yyvsp[-4].v)[1], (yyvsp[-4].v)[2]);
        SPoint3 axis((yyvsp[-6].v)[0], (yyvsp[-6].v)[1], (yyvsp[-6].v)[2]);
        double  angle((yyvsp[-2].d));
        SPoint3 translation(0, 0, 0);

        std::vector<double> transfo;
        computeAffineTransformation(origin, axis, angle, translation, transfo);

        for(int i = 0; i < List_Nbr((yyvsp[-14].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-10].l), i, &d_master);
          List_Read((yyvsp[-14].l), i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete((yyvsp[-14].l));
      List_Delete((yyvsp[-10].l));
    }
#line 12422 "Gmsh.tab.cpp"
    break;

  case 390: /* Constraints: tPeriodic tCurve '{' RecursiveListOfDouble '}' tAFFECT '{' RecursiveListOfDouble '}' tTranslate VExpr tEND  */
#line 5050 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-8].l)) != List_Nbr((yyvsp[-4].l))){
        yymsg(0, "Wrong number of curves in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-8].l)));
      }
      else{
        SPoint3 origin(0, 0, 0);
        SPoint3 axis(0, 0, 0);
        double  angle(0);
        SPoint3 translation((yyvsp[-1].v)[0], (yyvsp[-1].v)[1], (yyvsp[-1].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin, axis, angle, translation, transfo);

        for(int i = 0; i < List_Nbr((yyvsp[-8].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-4].l), i, &d_master);
          List_Read((yyvsp[-8].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[-8].l));
      List_Delete((yyvsp[-4].l));
    }
#line 12451 "Gmsh.tab.cpp"
    break;

  case 391: /* Constraints: tPeriodic tSurface '{' RecursiveListOfDouble '}' tAFFECT '{' RecursiveListOfDouble '}' tTranslate VExpr tEND  */
#line 5076 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-8].l)) != List_Nbr((yyvsp[-4].l))){
        yymsg(0, "Wrong number of surfaces in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-8].l)));
      }
      else{
        SPoint3 origin(0, 0, 0);
        SPoint3 axis(0, 0, 0);
        double  angle(0);
        SPoint3 translation((yyvsp[-1].v)[0], (yyvsp[-1].v)[1], (yyvsp[-1].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin, axis, angle, translation, transfo);

        for(int i = 0; i < List_Nbr((yyvsp[-8].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[-4].l), i, &d_master);
          List_Read((yyvsp[-8].l), i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete((yyvsp[-8].l));
      List_Delete((yyvsp[-4].l));
    }
#line 12480 "Gmsh.tab.cpp"
    break;

  case 392: /* Constraints: tPeriodic tSurface FExpr '{' RecursiveListOfDouble '}' tAFFECT FExpr '{' RecursiveListOfDouble '}' tEND  */
#line 5102 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-2].l))){
        yymsg(0, "Wrong number of surface curves in periodicity constraint (%d -> %d)",
              List_Nbr((yyvsp[-2].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        int j_master = (int)(yyvsp[-4].d);
        int j_slave = (int)(yyvsp[-9].d);
        std::map<int,int> edgeCounterParts;
        for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
          double ds,dm;
          List_Read((yyvsp[-7].l),i,&ds);
          List_Read((yyvsp[-2].l),i,&dm);
          edgeCounterParts[(int) ds] = (int) dm;
        }
        addPeriodicFace(j_slave, j_master, edgeCounterParts);
      }
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-2].l));
    }
#line 12505 "Gmsh.tab.cpp"
    break;

  case 393: /* Constraints: GeoEntity '{' RecursiveListOfDouble '}' tIn GeoEntity '{' FExpr '}' tEND  */
#line 5123 "Gmsh.y"
    {
      if(((yyvsp[-4].i) == 2 || (yyvsp[-4].i) == 3) && (yyvsp[-9].i) < (yyvsp[-4].i)) {
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[-7].l), tags);
        addEmbedded((yyvsp[-9].i), tags, (yyvsp[-4].i), (int)(yyvsp[-2].d));
      }
      else {
        yymsg(0, "Entity of dimension %d cannot be embedded in entity of dimension %d",
              (yyvsp[-9].i), (yyvsp[-4].i));
      }
      List_Delete((yyvsp[-7].l));
    }
#line 12521 "Gmsh.tab.cpp"
    break;

  case 394: /* Constraints: tReverseMesh GeoEntity12 ListOfDoubleOrAll tEND  */
#line 5135 "Gmsh.y"
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[-1].l)){
        GModel::current()->getGEOInternals()->setReverseMesh((yyvsp[-2].i), 0);
        switch ((yyvsp[-2].i)) {
        case 1:
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
          break;
        case 2:
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
          break;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          int num = (int)d;
          GModel::current()->getGEOInternals()->setReverseMesh((yyvsp[-2].i), num);
          switch ((yyvsp[-2].i)) {
          case 1:
            {
              GEdge *ge = GModel::current()->getEdgeByTag(num);
              if(ge) ge->meshAttributes.reverseMesh = 1;
            }
            break;
          case 2:
            {
              GFace *gf = GModel::current()->getFaceByTag(num);
              if(gf) gf->meshAttributes.reverseMesh = 1;
            }
            break;
          }
        }
        List_Delete((yyvsp[-1].l));
      }
    }
#line 12573 "Gmsh.tab.cpp"
    break;

  case 395: /* Constraints: tRelocateMesh GeoEntity012 ListOfDoubleOrAll tEND  */
#line 5183 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      if(!(yyvsp[-1].l)){
        switch ((yyvsp[-2].i)) {
        case 0:
          for(GModel::viter it = GModel::current()->firstVertex();
              it != GModel::current()->lastVertex(); it++)
            (*it)->relocateMeshVertices();
          break;
        case 1:
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++)
            (*it)->relocateMeshVertices();
          break;
        case 2:
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++)
            (*it)->relocateMeshVertices();
          break;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
          double d;
          List_Read((yyvsp[-1].l), i, &d);
          switch ((yyvsp[-2].i)) {
          case 0:
            {
              GVertex *gv = GModel::current()->getVertexByTag((int)d);
              if(gv) gv->relocateMeshVertices();
            }
            break;
          case 1:
            {
              GEdge *ge = GModel::current()->getEdgeByTag((int)d);
              if(ge) ge->relocateMeshVertices();
            }
            break;
          case 2:
            {
              GFace *gf = GModel::current()->getFaceByTag((int)d);
              if(gf) gf->relocateMeshVertices();
            }
            break;
          }
        }
        List_Delete((yyvsp[-1].l));
      }
    }
#line 12631 "Gmsh.tab.cpp"
    break;

  case 396: /* Constraints: tReorientMesh tVolume ListOfDouble tEND  */
#line 5237 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double d;
        List_Read((yyvsp[-1].l), i, &d);
        GRegion *gr = GModel::current()->getRegionByTag((int)d);
        if(gr) gr->setOutwardOrientationMeshConstraint();
      }
      List_Delete((yyvsp[-1].l));
    }
#line 12650 "Gmsh.tab.cpp"
    break;

  case 397: /* Constraints: tDegenerated tCurve ListOfDouble tEND  */
#line 5252 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
	double dnum;
	List_Read((yyvsp[-1].l), i, &dnum);
	int num = (int)dnum;
        GModel::current()->getGEOInternals()->setDegenerated(1, num);
        GEdge *ge = GModel::current()->getEdgeByTag(num);
        if(ge) ge->setTooSmall(true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 12666 "Gmsh.tab.cpp"
    break;

  case 398: /* Constraints: tCompound GeoEntity123 ListOfDouble tEND  */
#line 5264 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-2].i), tags);
      List_Delete((yyvsp[-1].l));
    }
#line 12676 "Gmsh.tab.cpp"
    break;

  case 399: /* Constraints: tCompound GeoEntity123 ListOfDouble tMeshAlgorithm FExpr tEND  */
#line 5270 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      tags.push_back(- (int) (yyvsp[-1].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-4].i), tags);
      List_Delete((yyvsp[-3].l));
    }
#line 12687 "Gmsh.tab.cpp"
    break;

  case 400: /* Coherence: tCoherence tEND  */
#line 5282 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
#line 12698 "Gmsh.tab.cpp"
    break;

  case 401: /* Coherence: tCoherence tSTRING tEND  */
#line 5289 "Gmsh.y"
    {
      if(!strcmp((yyvsp[-1].c), "Geometry")){
        if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->removeAllDuplicates();
        else
          GModel::current()->getGEOInternals()->removeAllDuplicates();
      }
      else if(!strcmp((yyvsp[-1].c), "Mesh")){
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      }
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 12717 "Gmsh.tab.cpp"
    break;

  case 402: /* Coherence: tCoherence tPoint '{' RecursiveListOfDouble '}' tEND  */
#line 5304 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[-2].l));
    }
#line 12730 "Gmsh.tab.cpp"
    break;

  case 403: /* Coherence: tHealShapes tEND  */
#line 5313 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()) {
        std::vector<std::pair<int, int> > in, out;
        GModel::current()->getOCCInternals()->healShapes
          (in, out, CTX::instance()->geom.tolerance,
           CTX::instance()->geom.occFixDegenerated,
           CTX::instance()->geom.occFixSmallEdges,
           CTX::instance()->geom.occFixSmallFaces,
           CTX::instance()->geom.occSewFaces,
           CTX::instance()->geom.occMakeSolids);
      }
      else {
        yymsg(0, "HealShapes only available with OpenCASCADE geometry kernel");
      }
    }
#line 12750 "Gmsh.tab.cpp"
    break;

  case 404: /* HomologyCommand: tHomology  */
#line 5333 "Gmsh.y"
              { (yyval.c) = (char*)"Homology"; }
#line 12756 "Gmsh.tab.cpp"
    break;

  case 405: /* HomologyCommand: tCohomology  */
#line 5334 "Gmsh.y"
                { (yyval.c) = (char*)"Cohomology"; }
#line 12762 "Gmsh.tab.cpp"
    break;

  case 406: /* HomologyCommand: tBetti  */
#line 5335 "Gmsh.y"
           { (yyval.c) = (char*)"Betti"; }
#line 12768 "Gmsh.tab.cpp"
    break;

  case 407: /* Homology: HomologyCommand tEND  */
#line 5340 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 12778 "Gmsh.tab.cpp"
    break;

  case 408: /* Homology: HomologyCommand '{' ListOfDouble '}' tEND  */
#line 5346 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        double d;
        List_Read((yyvsp[-2].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-4].c), domain, subdomain, dim);
      List_Delete((yyvsp[-2].l));
    }
#line 12794 "Gmsh.tab.cpp"
    break;

  case 409: /* Homology: HomologyCommand '{' ListOfDouble ',' ListOfDouble '}' tEND  */
#line 5358 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
        double d;
        List_Read((yyvsp[-4].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        double d;
        List_Read((yyvsp[-2].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-6].c), domain, subdomain, dim);
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
    }
#line 12816 "Gmsh.tab.cpp"
    break;

  case 410: /* Homology: HomologyCommand '(' ListOfDouble ')' '{' ListOfDouble ',' ListOfDouble '}' tEND  */
#line 5376 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
        double d;
        List_Read((yyvsp[-4].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
        double d;
        List_Read((yyvsp[-2].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
        double d;
        List_Read((yyvsp[-7].l), i, &d);
        dim.push_back((int)d);
      }
      GModel::current()->addHomologyRequest((yyvsp[-9].c), domain, subdomain, dim);
      List_Delete((yyvsp[-4].l));
      List_Delete((yyvsp[-2].l));
      List_Delete((yyvsp[-7].l));
    }
#line 12843 "Gmsh.tab.cpp"
    break;

  case 411: /* FExpr: FExpr_Single  */
#line 5403 "Gmsh.y"
                                  { (yyval.d) = (yyvsp[0].d);           }
#line 12849 "Gmsh.tab.cpp"
    break;

  case 412: /* FExpr: '(' FExpr ')'  */
#line 5404 "Gmsh.y"
                                  { (yyval.d) = (yyvsp[-1].d);           }
#line 12855 "Gmsh.tab.cpp"
    break;

  case 413: /* FExpr: '-' FExpr  */
#line 5405 "Gmsh.y"
                                  { (yyval.d) = -(yyvsp[0].d);          }
#line 12861 "Gmsh.tab.cpp"
    break;

  case 414: /* FExpr: '+' FExpr  */
#line 5406 "Gmsh.y"
                                  { (yyval.d) = (yyvsp[0].d);           }
#line 12867 "Gmsh.tab.cpp"
    break;

  case 415: /* FExpr: '!' FExpr  */
#line 5407 "Gmsh.y"
                                  { (yyval.d) = !(yyvsp[0].d);          }
#line 12873 "Gmsh.tab.cpp"
    break;

  case 416: /* FExpr: FExpr '-' FExpr  */
#line 5408 "Gmsh.y"
                                  { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 12879 "Gmsh.tab.cpp"
    break;

  case 417: /* FExpr: FExpr '+' FExpr  */
#line 5409 "Gmsh.y"
                                  { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 12885 "Gmsh.tab.cpp"
    break;

  case 418: /* FExpr: FExpr '*' FExpr  */
#line 5410 "Gmsh.y"
                                  { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 12891 "Gmsh.tab.cpp"
    break;

  case 419: /* FExpr: FExpr '/' FExpr  */
#line 5412 "Gmsh.y"
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 12902 "Gmsh.tab.cpp"
    break;

  case 420: /* FExpr: FExpr '|' FExpr  */
#line 5418 "Gmsh.y"
                                   { (yyval.d) = (int)(yyvsp[-2].d) | (int)(yyvsp[0].d); }
#line 12908 "Gmsh.tab.cpp"
    break;

  case 421: /* FExpr: FExpr '&' FExpr  */
#line 5419 "Gmsh.y"
                                   { (yyval.d) = (int)(yyvsp[-2].d) & (int)(yyvsp[0].d); }
#line 12914 "Gmsh.tab.cpp"
    break;

  case 422: /* FExpr: FExpr '%' FExpr  */
#line 5420 "Gmsh.y"
                                   { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d); }
#line 12920 "Gmsh.tab.cpp"
    break;

  case 423: /* FExpr: FExpr '^' FExpr  */
#line 5421 "Gmsh.y"
                                   { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 12926 "Gmsh.tab.cpp"
    break;

  case 424: /* FExpr: FExpr '<' FExpr  */
#line 5422 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 12932 "Gmsh.tab.cpp"
    break;

  case 425: /* FExpr: FExpr '>' FExpr  */
#line 5423 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 12938 "Gmsh.tab.cpp"
    break;

  case 426: /* FExpr: FExpr tLESSOREQUAL FExpr  */
#line 5424 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 12944 "Gmsh.tab.cpp"
    break;

  case 427: /* FExpr: FExpr tGREATEROREQUAL FExpr  */
#line 5425 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 12950 "Gmsh.tab.cpp"
    break;

  case 428: /* FExpr: FExpr tEQUAL FExpr  */
#line 5426 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 12956 "Gmsh.tab.cpp"
    break;

  case 429: /* FExpr: FExpr tNOTEQUAL FExpr  */
#line 5427 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 12962 "Gmsh.tab.cpp"
    break;

  case 430: /* FExpr: FExpr tAND FExpr  */
#line 5428 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 12968 "Gmsh.tab.cpp"
    break;

  case 431: /* FExpr: FExpr tOR FExpr  */
#line 5429 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 12974 "Gmsh.tab.cpp"
    break;

  case 432: /* FExpr: FExpr tGREATERGREATER FExpr  */
#line 5430 "Gmsh.y"
                                   { (yyval.d) = ((int)(yyvsp[-2].d) >> (int)(yyvsp[0].d)); }
#line 12980 "Gmsh.tab.cpp"
    break;

  case 433: /* FExpr: FExpr tLESSLESS FExpr  */
#line 5431 "Gmsh.y"
                                   { (yyval.d) = ((int)(yyvsp[-2].d) << (int)(yyvsp[0].d)); }
#line 12986 "Gmsh.tab.cpp"
    break;

  case 434: /* FExpr: FExpr '?' FExpr tDOTS FExpr  */
#line 5432 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 12992 "Gmsh.tab.cpp"
    break;

  case 435: /* FExpr: tStep LP FExpr RP  */
#line 5433 "Gmsh.y"
                                   { (yyval.d) = ((yyvsp[-1].d) < 0) ? 0 : 1; }
#line 12998 "Gmsh.tab.cpp"
    break;

  case 436: /* FExpr: tExp LP FExpr RP  */
#line 5434 "Gmsh.y"
                                   { (yyval.d) = exp((yyvsp[-1].d));      }
#line 13004 "Gmsh.tab.cpp"
    break;

  case 437: /* FExpr: tLog LP FExpr RP  */
#line 5435 "Gmsh.y"
                                   { (yyval.d) = log((yyvsp[-1].d));      }
#line 13010 "Gmsh.tab.cpp"
    break;

  case 438: /* FExpr: tLog10 LP FExpr RP  */
#line 5436 "Gmsh.y"
                                   { (yyval.d) = log10((yyvsp[-1].d));    }
#line 13016 "Gmsh.tab.cpp"
    break;

  case 439: /* FExpr: tSqrt LP FExpr RP  */
#line 5437 "Gmsh.y"
                                   { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 13022 "Gmsh.tab.cpp"
    break;

  case 440: /* FExpr: tSin LP FExpr RP  */
#line 5438 "Gmsh.y"
                                   { (yyval.d) = sin((yyvsp[-1].d));      }
#line 13028 "Gmsh.tab.cpp"
    break;

  case 441: /* FExpr: tAsin LP FExpr RP  */
#line 5439 "Gmsh.y"
                                   { (yyval.d) = asin((yyvsp[-1].d));     }
#line 13034 "Gmsh.tab.cpp"
    break;

  case 442: /* FExpr: tCos LP FExpr RP  */
#line 5440 "Gmsh.y"
                                   { (yyval.d) = cos((yyvsp[-1].d));      }
#line 13040 "Gmsh.tab.cpp"
    break;

  case 443: /* FExpr: tAcos LP FExpr RP  */
#line 5441 "Gmsh.y"
                                   { (yyval.d) = acos((yyvsp[-1].d));     }
#line 13046 "Gmsh.tab.cpp"
    break;

  case 444: /* FExpr: tTan LP FExpr RP  */
#line 5442 "Gmsh.y"
                                   { (yyval.d) = tan((yyvsp[-1].d));      }
#line 13052 "Gmsh.tab.cpp"
    break;

  case 445: /* FExpr: tAtan LP FExpr RP  */
#line 5443 "Gmsh.y"
                                   { (yyval.d) = atan((yyvsp[-1].d));     }
#line 13058 "Gmsh.tab.cpp"
    break;

  case 446: /* FExpr: tAtan2 LP FExpr ',' FExpr RP  */
#line 5444 "Gmsh.y"
                                   { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 13064 "Gmsh.tab.cpp"
    break;

  case 447: /* FExpr: tSinh LP FExpr RP  */
#line 5445 "Gmsh.y"
                                   { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 13070 "Gmsh.tab.cpp"
    break;

  case 448: /* FExpr: tCosh LP FExpr RP  */
#line 5446 "Gmsh.y"
                                   { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 13076 "Gmsh.tab.cpp"
    break;

  case 449: /* FExpr: tTanh LP FExpr RP  */
#line 5447 "Gmsh.y"
                                   { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 13082 "Gmsh.tab.cpp"
    break;

  case 450: /* FExpr: tFabs LP FExpr RP  */
#line 5448 "Gmsh.y"
                                   { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 13088 "Gmsh.tab.cpp"
    break;

  case 451: /* FExpr: tAbs LP FExpr RP  */
#line 5449 "Gmsh.y"
                                   { (yyval.d) = std::abs((yyvsp[-1].d)); }
#line 13094 "Gmsh.tab.cpp"
    break;

  case 452: /* FExpr: tFloor LP FExpr RP  */
#line 5450 "Gmsh.y"
                                   { (yyval.d) = floor((yyvsp[-1].d));    }
#line 13100 "Gmsh.tab.cpp"
    break;

  case 453: /* FExpr: tCeil LP FExpr RP  */
#line 5451 "Gmsh.y"
                                   { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 13106 "Gmsh.tab.cpp"
    break;

  case 454: /* FExpr: tRound LP FExpr RP  */
#line 5452 "Gmsh.y"
                                   { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 13112 "Gmsh.tab.cpp"
    break;

  case 455: /* FExpr: tFmod LP FExpr ',' FExpr RP  */
#line 5453 "Gmsh.y"
                                   { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 13118 "Gmsh.tab.cpp"
    break;

  case 456: /* FExpr: tModulo LP FExpr ',' FExpr RP  */
#line 5454 "Gmsh.y"
                                   { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 13124 "Gmsh.tab.cpp"
    break;

  case 457: /* FExpr: tHypot LP FExpr ',' FExpr RP  */
#line 5455 "Gmsh.y"
                                   { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 13130 "Gmsh.tab.cpp"
    break;

  case 458: /* FExpr: tRand LP FExpr RP  */
#line 5456 "Gmsh.y"
                                   { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 13136 "Gmsh.tab.cpp"
    break;

  case 459: /* FExpr: tMax LP FExpr ',' FExpr RP  */
#line 5457 "Gmsh.y"
                                   { (yyval.d) = std::max((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 13142 "Gmsh.tab.cpp"
    break;

  case 460: /* FExpr: tMin LP FExpr ',' FExpr RP  */
#line 5458 "Gmsh.y"
                                   { (yyval.d) = std::min((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 13148 "Gmsh.tab.cpp"
    break;

  case 461: /* FExpr_Single: tDOUBLE  */
#line 5467 "Gmsh.y"
              { (yyval.d) = (yyvsp[0].d); }
#line 13154 "Gmsh.tab.cpp"
    break;

  case 462: /* FExpr_Single: tPi  */
#line 5468 "Gmsh.y"
              { (yyval.d) = 3.141592653589793; }
#line 13160 "Gmsh.tab.cpp"
    break;

  case 463: /* FExpr_Single: tTestLevel  */
#line 5469 "Gmsh.y"
               { (yyval.d) = (double)ImbricatedTest; }
#line 13166 "Gmsh.tab.cpp"
    break;

  case 464: /* FExpr_Single: tMPI_Rank  */
#line 5470 "Gmsh.y"
              { (yyval.d) = Msg::GetCommRank(); }
#line 13172 "Gmsh.tab.cpp"
    break;

  case 465: /* FExpr_Single: tMPI_Size  */
#line 5471 "Gmsh.y"
              { (yyval.d) = Msg::GetCommSize(); }
#line 13178 "Gmsh.tab.cpp"
    break;

  case 466: /* FExpr_Single: tGMSH_MAJOR_VERSION  */
#line 5472 "Gmsh.y"
                        { (yyval.d) = GetGmshMajorVersion(); }
#line 13184 "Gmsh.tab.cpp"
    break;

  case 467: /* FExpr_Single: tGMSH_MINOR_VERSION  */
#line 5473 "Gmsh.y"
                        { (yyval.d) = GetGmshMinorVersion(); }
#line 13190 "Gmsh.tab.cpp"
    break;

  case 468: /* FExpr_Single: tGMSH_PATCH_VERSION  */
#line 5474 "Gmsh.y"
                        { (yyval.d) = GetGmshPatchVersion(); }
#line 13196 "Gmsh.tab.cpp"
    break;

  case 469: /* FExpr_Single: tCpu  */
#line 5475 "Gmsh.y"
         { (yyval.d) = Cpu(); }
#line 13202 "Gmsh.tab.cpp"
    break;

  case 470: /* FExpr_Single: tMemory  */
#line 5476 "Gmsh.y"
            { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 13208 "Gmsh.tab.cpp"
    break;

  case 471: /* FExpr_Single: tTotalMemory  */
#line 5477 "Gmsh.y"
                 { (yyval.d) = TotalRam(); }
#line 13214 "Gmsh.tab.cpp"
    break;

  case 472: /* $@14: %empty  */
#line 5482 "Gmsh.y"
    { init_options(); }
#line 13220 "Gmsh.tab.cpp"
    break;

  case 473: /* FExpr_Single: tDefineNumber LP FExpr $@14 FloatParameterOptionsOrNone RP  */
#line 5484 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 13230 "Gmsh.tab.cpp"
    break;

  case 474: /* FExpr_Single: DefineStruct  */
#line 5490 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[0].d);
    }
#line 13238 "Gmsh.tab.cpp"
    break;

  case 475: /* FExpr_Single: tGetNumber LP StringExprVar RP  */
#line 5494 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 13247 "Gmsh.tab.cpp"
    break;

  case 476: /* FExpr_Single: tGetNumber LP StringExprVar ',' FExpr RP  */
#line 5499 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 13256 "Gmsh.tab.cpp"
    break;

  case 477: /* FExpr_Single: Struct_FullName  */
#line 5504 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[0].c2).char1, (yyvsp[0].c2).char2);
    }
#line 13264 "Gmsh.tab.cpp"
    break;

  case 478: /* FExpr_Single: String__Index '[' FExpr ']'  */
#line 5509 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 13272 "Gmsh.tab.cpp"
    break;

  case 479: /* FExpr_Single: String__Index '(' FExpr ')'  */
#line 5514 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 13280 "Gmsh.tab.cpp"
    break;

  case 480: /* FExpr_Single: tExists '(' Struct_FullName ')'  */
#line 5518 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-1].c2).char1, (yyvsp[-1].c2).char2, 1, 0, 0., 1);
    }
#line 13288 "Gmsh.tab.cpp"
    break;

  case 481: /* FExpr_Single: tExists '(' Struct_FullName '.' tSTRING_Reserved ')'  */
#line 5522 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-3].c2).char1, (yyvsp[-3].c2).char2, (yyvsp[-1].c), 0, 0., 1);
    }
#line 13296 "Gmsh.tab.cpp"
    break;

  case 482: /* FExpr_Single: tGetForced '(' Struct_FullName GetForced_Default ')'  */
#line 5526 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-2].c2).char1, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].d), 2);
    }
#line 13304 "Gmsh.tab.cpp"
    break;

  case 483: /* FExpr_Single: tGetForced '(' Struct_FullName '.' tSTRING_Reserved GetForced_Default ')'  */
#line 5530 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].d), 2);
    }
#line 13312 "Gmsh.tab.cpp"
    break;

  case 484: /* FExpr_Single: tGetForced '(' Struct_FullName LP FExpr RP GetForced_Default ')'  */
#line 5534 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-5].c2).char1, (yyvsp[-5].c2).char2, 2, (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 13320 "Gmsh.tab.cpp"
    break;

  case 485: /* FExpr_Single: tGetForced '(' Struct_FullName '.' tSTRING_Reserved LP FExpr RP GetForced_Default ')'  */
#line 5538 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c2).char1, (yyvsp[-7].c2).char2, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 13328 "Gmsh.tab.cpp"
    break;

  case 486: /* FExpr_Single: tFileExists '(' StringExpr ')'  */
#line 5542 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 13338 "Gmsh.tab.cpp"
    break;

  case 487: /* FExpr_Single: '#' String__Index LP RP  */
#line 5548 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[-2].c))){
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
	(yyval.d) = s.value.size();
      }
      else if(gmsh_yystringsymbols.count((yyvsp[-2].c))){
	(yyval.d) = gmsh_yystringsymbols[(yyvsp[-2].c)].size();
      }
      else{
        yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
	(yyval.d) = 0.;
      }
      Free((yyvsp[-2].c));
    }
#line 13357 "Gmsh.tab.cpp"
    break;

  case 488: /* FExpr_Single: '#' Struct_FullName '.' tSTRING_Reserved LP RP  */
#line 5563 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c));
    }
#line 13365 "Gmsh.tab.cpp"
    break;

  case 489: /* FExpr_Single: tDimNameSpace LP String__Index RP  */
#line 5567 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[-1].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[-1].c));
    }
#line 13375 "Gmsh.tab.cpp"
    break;

  case 490: /* FExpr_Single: tDimNameSpace LP RP  */
#line 5573 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
#line 13384 "Gmsh.tab.cpp"
    break;

  case 491: /* FExpr_Single: String__Index NumericIncrement  */
#line 5578 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[-1].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-1].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-1].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[-1].c));
          (yyval.d) = 0.;
        }
        else{
          (yyval.d) = s.value[0];
          s.value[0] += (yyvsp[0].i);
        }
      }
      Free((yyvsp[-1].c));
    }
#line 13407 "Gmsh.tab.cpp"
    break;

  case 492: /* FExpr_Single: String__Index '[' FExpr ']' NumericIncrement  */
#line 5597 "Gmsh.y"
    {
      int index = (int)(yyvsp[-2].d);
      if(!gmsh_yysymbols.count((yyvsp[-4].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-4].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-4].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-4].c), index);
          (yyval.d) = 0.;
        }
        else{
          (yyval.d) = s.value[index];
          s.value[index] += (yyvsp[0].i);
        }
      }
      Free((yyvsp[-4].c));
    }
#line 13431 "Gmsh.tab.cpp"
    break;

  case 493: /* FExpr_Single: String__Index '(' FExpr ')' NumericIncrement  */
#line 5617 "Gmsh.y"
    {
      int index = (int)(yyvsp[-2].d);
      if(!gmsh_yysymbols.count((yyvsp[-4].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[-4].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-4].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-4].c), index);
          (yyval.d) = 0.;
        }
        else{
          (yyval.d) = s.value[index];
          s.value[index] += (yyvsp[0].i);
        }
      }
      Free((yyvsp[-4].c));
    }
#line 13455 "Gmsh.tab.cpp"
    break;

  case 494: /* FExpr_Single: String__Index '.' tSTRING_Reserved  */
#line 5638 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13463 "Gmsh.tab.cpp"
    break;

  case 495: /* FExpr_Single: String__Index tSCOPE String__Index '.' tSTRING_Reserved  */
#line 5642 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13471 "Gmsh.tab.cpp"
    break;

  case 496: /* FExpr_Single: String__Index '.' tSTRING_Reserved '(' FExpr ')'  */
#line 5646 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13479 "Gmsh.tab.cpp"
    break;

  case 497: /* FExpr_Single: String__Index tSCOPE String__Index '.' tSTRING_Reserved '(' FExpr ')'  */
#line 5650 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13487 "Gmsh.tab.cpp"
    break;

  case 498: /* FExpr_Single: String__Index '.' tSTRING_Reserved '[' FExpr ']'  */
#line 5654 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13495 "Gmsh.tab.cpp"
    break;

  case 499: /* FExpr_Single: String__Index tSCOPE String__Index '.' tSTRING_Reserved '[' FExpr ']'  */
#line 5658 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13503 "Gmsh.tab.cpp"
    break;

  case 500: /* FExpr_Single: String__Index '[' FExpr ']' '.' tSTRING_Reserved  */
#line 5662 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 13512 "Gmsh.tab.cpp"
    break;

  case 501: /* FExpr_Single: String__Index '.' tSTRING_Reserved NumericIncrement  */
#line 5667 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 13526 "Gmsh.tab.cpp"
    break;

  case 502: /* FExpr_Single: String__Index '[' FExpr ']' '.' tSTRING_Reserved NumericIncrement  */
#line 5677 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 13540 "Gmsh.tab.cpp"
    break;

  case 503: /* FExpr_Single: tGetValue '(' StringExprVar ',' FExpr ')'  */
#line 5687 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 13549 "Gmsh.tab.cpp"
    break;

  case 504: /* FExpr_Single: tFind '(' ListOfDouble ',' ListOfDouble ')'  */
#line 5692 "Gmsh.y"
    {
      int matches = 0;
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
        double d;
        List_Read((yyvsp[-3].l), i, &d);
        matches += List_Search((yyvsp[-1].l), &d, fcmp_double);
      }
      (yyval.d) = matches;
      Free((yyvsp[-3].l)); Free((yyvsp[-1].l));
    }
#line 13564 "Gmsh.tab.cpp"
    break;

  case 505: /* FExpr_Single: tStrFind LP StringExprVar ',' StringExprVar RP  */
#line 5703 "Gmsh.y"
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 13577 "Gmsh.tab.cpp"
    break;

  case 506: /* FExpr_Single: tStrLen LP StringExprVar RP  */
#line 5712 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 13586 "Gmsh.tab.cpp"
    break;

  case 507: /* FExpr_Single: tStrCmp LP StringExprVar ',' StringExprVar RP  */
#line 5717 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 13595 "Gmsh.tab.cpp"
    break;

  case 508: /* FExpr_Single: tTextAttributes '(' RecursiveListOfStringExprVar ')'  */
#line 5722 "Gmsh.y"
    {
      int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
      if(List_Nbr((yyvsp[-1].l)) % 2){
        yymsg(0, "Number of text attributes should be even");
      }
      else{
        for(int i = 0 ; i < List_Nbr((yyvsp[-1].l)); i += 2){
          char *s1, *s2; List_Read((yyvsp[-1].l), i, &s1); List_Read((yyvsp[-1].l), i + 1, &s2);
          std::string key(s1), val(s2);
          Free(s1); Free(s2);
#if defined(HAVE_OPENGL)
          if(key == "Font")
            font = drawContext::global()->getFontIndex(val.c_str());
          else if(key == "FontSize")
            fontsize = atoi(val.c_str());
          else if(key == "Align")
            align = drawContext::global()->getFontAlign(val.c_str());
#endif
        }
      }
      List_Delete((yyvsp[-1].l));
      (yyval.d) = (double)((align<<16)|(font<<8)|(fontsize));
    }
#line 13623 "Gmsh.tab.cpp"
    break;

  case 509: /* GetForced_Default: %empty  */
#line 5749 "Gmsh.y"
    { (yyval.d) = 0.; }
#line 13629 "Gmsh.tab.cpp"
    break;

  case 510: /* GetForced_Default: ',' FExpr  */
#line 5751 "Gmsh.y"
    { (yyval.d) = (yyvsp[0].d);}
#line 13635 "Gmsh.tab.cpp"
    break;

  case 511: /* GetForcedStr_Default: %empty  */
#line 5756 "Gmsh.y"
    { (yyval.c) = nullptr; }
#line 13641 "Gmsh.tab.cpp"
    break;

  case 512: /* GetForcedStr_Default: ',' StringExprVar  */
#line 5758 "Gmsh.y"
    { (yyval.c) = (yyvsp[0].c);}
#line 13647 "Gmsh.tab.cpp"
    break;

  case 513: /* $@15: %empty  */
#line 5763 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[-1].c2).char1? (yyvsp[-1].c2).char1 : std::string("")),
        struct_name((yyvsp[-1].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
#line 13658 "Gmsh.tab.cpp"
    break;

  case 514: /* DefineStruct: tDefineStruct Struct_FullName AppendOrNot $@15 '[' FloatParameterOptionsOrNone_NoComma ']'  */
#line 5770 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[-5].c2).char1? (yyvsp[-5].c2).char1 : std::string("")),
        struct_name((yyvsp[-5].c2).char2);
      Free((yyvsp[-5].c2).char1); Free((yyvsp[-5].c2).char2);
      int tag_out;
      if(gmsh_yynamespaces.defStruct(struct_namespace, struct_name,
                                      floatOptions, charOptions,
                                      tag_out, member_ValMax, (yyvsp[-4].i)))
        yymsg(0, "Redefinition of Struct '%s::%s'",
              struct_namespace.c_str(), struct_name.c_str());
      (yyval.d) = (double)tag_out;
    }
#line 13675 "Gmsh.tab.cpp"
    break;

  case 515: /* Struct_FullName: String__Index  */
#line 5786 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[0].c); }
#line 13681 "Gmsh.tab.cpp"
    break;

  case 516: /* Struct_FullName: String__Index tSCOPE String__Index  */
#line 5788 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[-2].c); (yyval.c2).char2 = (yyvsp[0].c); }
#line 13687 "Gmsh.tab.cpp"
    break;

  case 517: /* Append: tAppend  */
#line 5793 "Gmsh.y"
    { (yyval.i) = 99; }
#line 13693 "Gmsh.tab.cpp"
    break;

  case 518: /* Append: tAppend FExpr  */
#line 5795 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[0].d); }
#line 13699 "Gmsh.tab.cpp"
    break;

  case 519: /* AppendOrNot: %empty  */
#line 5800 "Gmsh.y"
    { (yyval.i) = 0; }
#line 13705 "Gmsh.tab.cpp"
    break;

  case 520: /* AppendOrNot: '(' Append ')'  */
#line 5802 "Gmsh.y"
    { (yyval.i) = (yyvsp[-1].i); }
#line 13711 "Gmsh.tab.cpp"
    break;

  case 521: /* VExpr: VExpr_Single  */
#line 5807 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[0].v), 5 * sizeof(double));
    }
#line 13719 "Gmsh.tab.cpp"
    break;

  case 522: /* VExpr: '-' VExpr  */
#line 5811 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 13727 "Gmsh.tab.cpp"
    break;

  case 523: /* VExpr: '+' VExpr  */
#line 5815 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 13735 "Gmsh.tab.cpp"
    break;

  case 524: /* VExpr: VExpr '-' VExpr  */
#line 5819 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 13743 "Gmsh.tab.cpp"
    break;

  case 525: /* VExpr: VExpr '+' VExpr  */
#line 5823 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 13751 "Gmsh.tab.cpp"
    break;

  case 526: /* VExpr_Single: '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}'  */
#line 5830 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 13759 "Gmsh.tab.cpp"
    break;

  case 527: /* VExpr_Single: '{' FExpr ',' FExpr ',' FExpr ',' FExpr '}'  */
#line 5834 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 13767 "Gmsh.tab.cpp"
    break;

  case 528: /* VExpr_Single: '{' FExpr ',' FExpr ',' FExpr '}'  */
#line 5838 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 13775 "Gmsh.tab.cpp"
    break;

  case 529: /* VExpr_Single: '(' FExpr ',' FExpr ',' FExpr ')'  */
#line 5842 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 13783 "Gmsh.tab.cpp"
    break;

  case 530: /* RecursiveListOfListOfDouble: ListOfDouble  */
#line 5849 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 13792 "Gmsh.tab.cpp"
    break;

  case 531: /* RecursiveListOfListOfDouble: RecursiveListOfListOfDouble ',' ListOfDouble  */
#line 5854 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 13800 "Gmsh.tab.cpp"
    break;

  case 532: /* ListOfDouble: FExpr  */
#line 5861 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13809 "Gmsh.tab.cpp"
    break;

  case 533: /* ListOfDouble: FExpr_Multi  */
#line 5866 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13817 "Gmsh.tab.cpp"
    break;

  case 534: /* ListOfDouble: '{' '}'  */
#line 5870 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 13825 "Gmsh.tab.cpp"
    break;

  case 535: /* ListOfDouble: '{' RecursiveListOfDouble '}'  */
#line 5874 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13833 "Gmsh.tab.cpp"
    break;

  case 536: /* ListOfDouble: '-' '{' RecursiveListOfDouble '}'  */
#line 5878 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 13845 "Gmsh.tab.cpp"
    break;

  case 537: /* ListOfDouble: FExpr '*' '{' RecursiveListOfDouble '}'  */
#line 5886 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 13857 "Gmsh.tab.cpp"
    break;

  case 538: /* ListOfDoubleWithBraces: '{' '}'  */
#line 5897 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 13865 "Gmsh.tab.cpp"
    break;

  case 539: /* ListOfDoubleWithBraces: '{' RecursiveListOfDouble '}'  */
#line 5901 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13873 "Gmsh.tab.cpp"
    break;

  case 540: /* ListOfDoubleWithBraces: '-' '{' RecursiveListOfDouble '}'  */
#line 5905 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 13885 "Gmsh.tab.cpp"
    break;

  case 541: /* ListOfDoubleOrAll: ListOfDouble  */
#line 5916 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13893 "Gmsh.tab.cpp"
    break;

  case 542: /* ListOfDoubleOrAll: '{' tDOTS '}'  */
#line 5920 "Gmsh.y"
    {
      (yyval.l) = 0;
    }
#line 13901 "Gmsh.tab.cpp"
    break;

  case 543: /* ListOfDoubleOrAll: tBIGSTR  */
#line 5924 "Gmsh.y"
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all")){
        (yyval.l) = 0;
      }
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
      Free((yyvsp[0].c));
    }
#line 13916 "Gmsh.tab.cpp"
    break;

  case 544: /* FExpr_Multi: '-' FExpr_Multi  */
#line 5938 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 13928 "Gmsh.tab.cpp"
    break;

  case 545: /* FExpr_Multi: FExpr '*' FExpr_Multi  */
#line 5946 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 13940 "Gmsh.tab.cpp"
    break;

  case 546: /* FExpr_Multi: FExpr tDOTS FExpr  */
#line 5954 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 13951 "Gmsh.tab.cpp"
    break;

  case 547: /* FExpr_Multi: FExpr tDOTS FExpr tDOTS FExpr  */
#line 5961 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 13965 "Gmsh.tab.cpp"
    break;

  case 548: /* FExpr_Multi: tPoint '{' FExpr '}'  */
#line 5971 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 1, sizeof(double));
      int tag = (int)(yyvsp[-1].d);
      double x = 0., y = 0., z = 0.;
      bool found = GModel::current()->getGEOInternals()->getVertex(tag, x, y, z);
      if(!found && GModel::current()->getOCCInternals())
        found = GModel::current()->getOCCInternals()->getVertex(tag, x, y, z);
      if(!found){
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv){
          x = gv->x();
          y = gv->y();
          z = gv->z();
        }
        else{
          yymsg(0, "Unknown model point with tag %d", tag);
        }
      }
      List_Add((yyval.l), &x);
      List_Add((yyval.l), &y);
      List_Add((yyval.l), &z);
    }
#line 13992 "Gmsh.tab.cpp"
    break;

  case 549: /* FExpr_Multi: tPoint '{' tDOTS '}'  */
#line 5994 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    }
#line 14001 "Gmsh.tab.cpp"
    break;

  case 550: /* FExpr_Multi: tPoint tBIGSTR  */
#line 5999 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[0].c));
    }
#line 14011 "Gmsh.tab.cpp"
    break;

  case 551: /* FExpr_Multi: GeoEntity123 '{' tDOTS '}'  */
#line 6005 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-3].i), (yyval.l));
    }
#line 14020 "Gmsh.tab.cpp"
    break;

  case 552: /* FExpr_Multi: GeoEntity123 tBIGSTR  */
#line 6010 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-1].i), (yyval.l));
      Free((yyvsp[0].c));
    }
#line 14030 "Gmsh.tab.cpp"
    break;

  case 553: /* FExpr_Multi: tPhysical GeoEntity ListOfDoubleOrAll  */
#line 6016 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[0].l)){
        getAllPhysicalTags((yyvsp[-1].i), (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups((yyvsp[-1].i), (yyvsp[0].l), (yyval.l));
        List_Delete((yyvsp[0].l));
      }
    }
#line 14045 "Gmsh.tab.cpp"
    break;

  case 554: /* FExpr_Multi: tParent GeoEntity ListOfDouble  */
#line 6027 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[-1].i), (yyvsp[0].l), (yyval.l));
      List_Delete((yyvsp[0].l));
    }
#line 14055 "Gmsh.tab.cpp"
    break;

  case 555: /* FExpr_Multi: GeoEntity tIn tBoundingBox ListOfDouble  */
#line 6033 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(List_Nbr((yyvsp[0].l)) < 6) {
        yymsg(0, "Bounding box should be {xmin, ymin, zmin, xmax, ymax, zmax}");
      }
      else {
        double bb[6];
        for(int i = 0; i < 6; i++) List_Read((yyvsp[0].l), i, &bb[i]);
        getElementaryTagsInBoundingBox
          ((yyvsp[-3].i), bb[0], bb[1], bb[2], bb[3], bb[4], bb[5], (yyval.l));
      }
      List_Delete((yyvsp[0].l));
    }
#line 14073 "Gmsh.tab.cpp"
    break;

  case 556: /* FExpr_Multi: tBoundingBox GeoEntity '{' RecursiveListOfDouble '}'  */
#line 6047 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[-3].i), (yyvsp[-1].l), (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 14083 "Gmsh.tab.cpp"
    break;

  case 557: /* FExpr_Multi: tMass GeoEntity123 '{' FExpr '}'  */
#line 6053 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double m = 0;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->getMass((yyvsp[-3].i), (int)(yyvsp[-1].d), m);
      }
      else{
        yymsg(0, "Mass only available with OpenCASCADE geometry kernel");
      }
      List_Add((yyval.l), &m);
    }
#line 14099 "Gmsh.tab.cpp"
    break;

  case 558: /* FExpr_Multi: tCenterOfMass GeoEntity123 '{' FExpr '}'  */
#line 6065 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 1, sizeof(double));
      double x = 0., y = 0., z = 0.;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->getCenterOfMass((yyvsp[-3].i), (int)(yyvsp[-1].d), x, y, z);
      }
      else{
        yymsg(0, "CenterOfMass only available with OpenCASCADE geometry kernel");
      }
      List_Add((yyval.l), &x);
      List_Add((yyval.l), &y);
      List_Add((yyval.l), &z);
    }
#line 14117 "Gmsh.tab.cpp"
    break;

  case 559: /* FExpr_Multi: tMatrixOfInertia GeoEntity123 '{' FExpr '}'  */
#line 6079 "Gmsh.y"
    {
      (yyval.l) = List_Create(9, 1, sizeof(double));
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<double> mat;
        GModel::current()->getOCCInternals()->getMatrixOfInertia((yyvsp[-3].i), (int)(yyvsp[-1].d), mat);
        for(std::size_t i = 0; i < mat.size(); i++)
          List_Add((yyval.l), &mat[i]);
      }
      else{
        yymsg(0, "MatrixOfInertia only available with OpenCASCADE geometry kernel");
      }
    }
#line 14134 "Gmsh.tab.cpp"
    break;

  case 560: /* FExpr_Multi: tParametric tBoundingBox GeoEntity12 '{' FExpr '}'  */
#line 6092 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      GEntity *entity = GModel::current()->getEntityByTag((yyvsp[-3].i), (int)(yyvsp[-1].d));
      if(!entity) {
        yymsg(0, "%s %d does not exist", ((yyvsp[-3].i) == 1) ? "Curve" : "Surface",
              (int)(yyvsp[-1].d));
      }
      else {
        Range<double> u = entity->parBounds(0);
        double umin = u.low(), umax = u.high();
        if((yyvsp[-3].i) == 1) {
          List_Add((yyval.l), &umin);
          List_Add((yyval.l), &umax);
        }
        else {
          Range<double> v = entity->parBounds(1);
          double vmin = v.low(), vmax = v.high();
          List_Add((yyval.l), &umin);
          List_Add((yyval.l), &vmin);
          List_Add((yyval.l), &umax);
          List_Add((yyval.l), &vmax);
        }
      }
    }
#line 14168 "Gmsh.tab.cpp"
    break;

  case 561: /* FExpr_Multi: tNormal tSurface '{' FExpr '}' tParametric '{' FExpr ',' FExpr '}'  */
#line 6122 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      int tag = (int)(yyvsp[-7].d);
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf) {
        SPoint2 param((yyvsp[-3].d), (yyvsp[-1].d));
        SVector3 n = gf->normal(param);
        double x = n.x(), y = n.y(), z = n.z();
        List_Add((yyval.l), &x);
        List_Add((yyval.l), &y);
        List_Add((yyval.l), &z);
      }
      else {
        yymsg(0, "Surface %d does not exist", tag);
      }
    }
#line 14194 "Gmsh.tab.cpp"
    break;

  case 562: /* FExpr_Multi: tCurvature tSurface '{' FExpr '}' tParametric '{' FExpr ',' FExpr '}'  */
#line 6145 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      int tag = (int)(yyvsp[-7].d);
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf) {
        SPoint2 param((yyvsp[-3].d), (yyvsp[-1].d));
        double c = gf->curvatureMax(param);
        List_Add((yyval.l), &c);
      }
      else {
        yymsg(0, "Surface %d does not exist", tag);
      }
    }
#line 14217 "Gmsh.tab.cpp"
    break;

  case 563: /* FExpr_Multi: tCurvature tCurve '{' FExpr '}' tParametric '{' FExpr '}'  */
#line 6165 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      int tag = (int)(yyvsp[-5].d);
      GEdge *ge = GModel::current()->getEdgeByTag(tag);
      if(ge) {
        double c = ge->curvature(8);
        List_Add((yyval.l), &c);
      }
      else {
        yymsg(0, "Curve %d does not exist", tag);
      }
    }
#line 14239 "Gmsh.tab.cpp"
    break;

  case 564: /* FExpr_Multi: tParametric tPoint '{' FExpr '}' tIn tSurface '{' FExpr '}'  */
#line 6184 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      GVertex *gv = GModel::current()->getVertexByTag((int)(yyvsp[-6].d));
      GFace *gf = GModel::current()->getFaceByTag((int)(yyvsp[-1].d));
      if(gv && gf) {
        SPoint2 p = gv->reparamOnFace(gf, 0);
        double u = p.x(), v = p.y();
        List_Add((yyval.l), &u);
        List_Add((yyval.l), &v);
      }
      else {
        yymsg(0, "Point %d or surface %d does not exist", (int)(yyvsp[-6].d), (int)(yyvsp[-1].d));
      }
    }
#line 14263 "Gmsh.tab.cpp"
    break;

  case 565: /* FExpr_Multi: tColor GeoEntity123 '{' FExpr '}'  */
#line 6204 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 1, sizeof(double));
      double r = 0., g = 0., b = 0., a = 0.;
      GEntity *ge = GModel::current()->getEntityByTag((yyvsp[-3].i), (int)(yyvsp[-1].d));
      if(ge){
        unsigned int value = ge->getColor();
        r = CTX::instance()->unpackRed(value);
        g = CTX::instance()->unpackGreen(value);
        b = CTX::instance()->unpackBlue(value);
        a = CTX::instance()->unpackAlpha(value);
        List_Add((yyval.l), &r);
        List_Add((yyval.l), &g);
        List_Add((yyval.l), &b);
        List_Add((yyval.l), &a);
      }
    }
#line 14284 "Gmsh.tab.cpp"
    break;

  case 566: /* FExpr_Multi: Transform  */
#line 6221 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 14298 "Gmsh.tab.cpp"
    break;

  case 567: /* FExpr_Multi: Extrude  */
#line 6231 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 14312 "Gmsh.tab.cpp"
    break;

  case 568: /* FExpr_Multi: Boolean  */
#line 6241 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 14326 "Gmsh.tab.cpp"
    break;

  case 569: /* FExpr_Multi: String__Index LP RP  */
#line 6251 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-2].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
	for(std::size_t i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[-2].c));
    }
#line 14342 "Gmsh.tab.cpp"
    break;

  case 570: /* FExpr_Multi: String__Index '.' tSTRING_Reserved LP RP  */
#line 6263 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14350 "Gmsh.tab.cpp"
    break;

  case 571: /* FExpr_Multi: String__Index tSCOPE String__Index '.' tSTRING_Reserved LP RP  */
#line 6267 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14358 "Gmsh.tab.cpp"
    break;

  case 572: /* FExpr_Multi: tList '[' String__Index ']'  */
#line 6272 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-1].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-1].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-1].c)]);
	for(std::size_t i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[-1].c));
    }
#line 14374 "Gmsh.tab.cpp"
    break;

  case 573: /* FExpr_Multi: tList '[' FExpr_Multi ']'  */
#line 6284 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 14382 "Gmsh.tab.cpp"
    break;

  case 574: /* FExpr_Multi: tList '(' FExpr_Multi ')'  */
#line 6288 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 14390 "Gmsh.tab.cpp"
    break;

  case 575: /* FExpr_Multi: tList LP '{' RecursiveListOfDouble '}' RP  */
#line 6292 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 14398 "Gmsh.tab.cpp"
    break;

  case 576: /* FExpr_Multi: String__Index LP '{' RecursiveListOfDouble '}' RP  */
#line 6296 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-5].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-5].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-5].c)]);
	for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[-2].l), i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[-5].c), index);
	  else
	    List_Add((yyval.l), &s.value[index]);
	}
      }
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-2].l));
    }
#line 14420 "Gmsh.tab.cpp"
    break;

  case 577: /* FExpr_Multi: tLinSpace LP FExpr ',' FExpr ',' FExpr RP  */
#line 6314 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = (yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1);
	List_Add((yyval.l), &d);
      }
    }
#line 14432 "Gmsh.tab.cpp"
    break;

  case 578: /* FExpr_Multi: tLogSpace LP FExpr ',' FExpr ',' FExpr RP  */
#line 6322 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = pow(10,(yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1));
	List_Add((yyval.l), &d);
      }
    }
#line 14444 "Gmsh.tab.cpp"
    break;

  case 579: /* FExpr_Multi: tListFromFile LP StringExprVar RP  */
#line 6330 "Gmsh.y"
    {
      Msg::Barrier();
      FILE *File;
      (yyval.l) = List_Create(100, 100, sizeof(double));
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      if(!(File = Fopen(tmp.c_str(), "r"))){
        yymsg(0, "Could not open file '%s'", (yyvsp[-1].c));
      }
      else{
	double d;
	while(!feof(File)){
          int ret = fscanf(File, "%lf", &d);
	  if(ret == 1){
	    List_Add((yyval.l), &d);
          }
          else if(ret == EOF){
            break;
          }
          else{
            char dummy[65];
            if(fscanf(File, "%64s", dummy) == 1)
              yymsg(1, "Ignoring '%s' in file '%s'", dummy, (yyvsp[-1].c));
          }
        }
	fclose(File);
      }
      Free((yyvsp[-1].c));
    }
#line 14477 "Gmsh.tab.cpp"
    break;

  case 580: /* FExpr_Multi: tCatenary LP FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr RP  */
#line 6359 "Gmsh.y"
    {
      double x0 = (yyvsp[-11].d), x1 = (yyvsp[-9].d), y0 = (yyvsp[-7].d), y1 = (yyvsp[-5].d), ys = (yyvsp[-3].d);
      int N = (int)(yyvsp[-1].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        yymsg(1, "Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
#line 14491 "Gmsh.tab.cpp"
    break;

  case 581: /* FExpr_Multi: tUnique LP FExpr_Multi RP  */
#line 6369 "Gmsh.y"
    {
      std::vector<double> tmp;
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double d; List_Read((yyvsp[-1].l), i, &d);
        tmp.push_back(d);
      }
      std::sort(tmp.begin(), tmp.end());
      auto last = std::unique(tmp.begin(), tmp.end());
      tmp.erase(last, tmp.end());
      (yyval.l) = (yyvsp[-1].l);
      List_Reset((yyval.l));
      for(std::size_t i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    }
#line 14511 "Gmsh.tab.cpp"
    break;

  case 582: /* FExpr_Multi: tAbs LP FExpr_Multi RP  */
#line 6385 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[-1].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[-1].l);
    }
#line 14523 "Gmsh.tab.cpp"
    break;

  case 583: /* RecursiveListOfDouble: FExpr  */
#line 6396 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 14532 "Gmsh.tab.cpp"
    break;

  case 584: /* RecursiveListOfDouble: FExpr_Multi  */
#line 6401 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 14540 "Gmsh.tab.cpp"
    break;

  case 585: /* RecursiveListOfDouble: RecursiveListOfDouble ',' FExpr  */
#line 6405 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 14548 "Gmsh.tab.cpp"
    break;

  case 586: /* RecursiveListOfDouble: RecursiveListOfDouble ',' FExpr_Multi  */
#line 6409 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 14561 "Gmsh.tab.cpp"
    break;

  case 587: /* ColorExpr: '{' FExpr ',' FExpr ',' FExpr ',' FExpr '}'  */
#line 6421 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 14569 "Gmsh.tab.cpp"
    break;

  case 588: /* ColorExpr: '{' FExpr ',' FExpr ',' FExpr '}'  */
#line 6425 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 14577 "Gmsh.tab.cpp"
    break;

  case 589: /* ColorExpr: String__Index  */
#line 6437 "Gmsh.y"
    {
      int flag = 0;
      if(gmsh_yystringsymbols.count((yyvsp[0].c))){
        if(gmsh_yystringsymbols[(yyvsp[0].c)].size()){
          (yyval.u) = GetColorForString(-1, gmsh_yystringsymbols[(yyvsp[0].c)][0].c_str(), &flag);
        }
        else{
          yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
          (yyval.u) = 0;
        }
      }
      else
        (yyval.u) = GetColorForString(-1, (yyvsp[0].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[0].c));
      Free((yyvsp[0].c));
    }
#line 14598 "Gmsh.tab.cpp"
    break;

  case 590: /* ColorExpr: tSTRING '.' tColor '.' tSTRING  */
#line 6454 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 14609 "Gmsh.tab.cpp"
    break;

  case 591: /* ListOfColor: '{' RecursiveListOfColor '}'  */
#line 6464 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 14617 "Gmsh.tab.cpp"
    break;

  case 592: /* ListOfColor: String__Index '[' FExpr ']' '.' tColorTable  */
#line 6468 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = GetColorTable((int)(yyvsp[-3].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[-3].d));
      else{
	for(int i = 0; i < ct->size; i++)
	  List_Add((yyval.l), &ct->table[i]);
      }
      Free((yyvsp[-5].c));
    }
#line 14633 "Gmsh.tab.cpp"
    break;

  case 593: /* RecursiveListOfColor: ColorExpr  */
#line 6483 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 14642 "Gmsh.tab.cpp"
    break;

  case 594: /* RecursiveListOfColor: RecursiveListOfColor ',' ColorExpr  */
#line 6488 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 14650 "Gmsh.tab.cpp"
    break;

  case 595: /* StringExprVar: StringExpr  */
#line 6495 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 14658 "Gmsh.tab.cpp"
    break;

  case 596: /* StringExprVar: String__Index  */
#line 6499 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[0].c));
    }
#line 14667 "Gmsh.tab.cpp"
    break;

  case 597: /* StringExprVar: String__Index '[' FExpr ']'  */
#line 6504 "Gmsh.y"
    {
      std::string val;
      int j = (int)(yyvsp[-1].d);
      if(!gmsh_yystringsymbols.count((yyvsp[-3].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[-3].c));
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[(yyvsp[-3].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[-3].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 14685 "Gmsh.tab.cpp"
    break;

  case 598: /* StringExprVar: String__Index '(' FExpr ')'  */
#line 6518 "Gmsh.y"
    {
      std::string val;
      int j = (int)(yyvsp[-1].d);
      if(!gmsh_yystringsymbols.count((yyvsp[-3].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[-3].c));
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[(yyvsp[-3].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[-3].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 14703 "Gmsh.tab.cpp"
    break;

  case 599: /* StringExprVar: String__Index '.' tSTRING_Reserved  */
#line 6532 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 14711 "Gmsh.tab.cpp"
    break;

  case 600: /* StringExprVar: String__Index tSCOPE String__Index '.' tSTRING_Reserved  */
#line 6536 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 14719 "Gmsh.tab.cpp"
    break;

  case 601: /* StringExprVar: String__Index '.' tSTRING_Reserved '(' FExpr ')'  */
#line 6540 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 14727 "Gmsh.tab.cpp"
    break;

  case 602: /* StringExprVar: String__Index tSCOPE String__Index '.' tSTRING_Reserved '(' FExpr ')'  */
#line 6544 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 14735 "Gmsh.tab.cpp"
    break;

  case 603: /* StringExprVar: String__Index '[' FExpr ']' '.' tSTRING  */
#line 6548 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 14747 "Gmsh.tab.cpp"
    break;

  case 604: /* StringExprVar: GeoEntity '{' FExpr '}'  */
#line 6556 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 14757 "Gmsh.tab.cpp"
    break;

  case 605: /* StringExprVar: tPhysical GeoEntity '{' FExpr '}'  */
#line 6562 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 14767 "Gmsh.tab.cpp"
    break;

  case 606: /* StringExpr: tBIGSTR  */
#line 6571 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 14775 "Gmsh.tab.cpp"
    break;

  case 607: /* StringExpr: tNameToString '[' String__Index ']'  */
#line 6575 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 14783 "Gmsh.tab.cpp"
    break;

  case 608: /* StringExpr: tToday  */
#line 6579 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 14795 "Gmsh.tab.cpp"
    break;

  case 609: /* StringExpr: tGmshExecutableName  */
#line 6587 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 14805 "Gmsh.tab.cpp"
    break;

  case 610: /* StringExpr: tOnelabAction  */
#line 6593 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 14815 "Gmsh.tab.cpp"
    break;

  case 611: /* StringExpr: tCodeName  */
#line 6599 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
#line 14823 "Gmsh.tab.cpp"
    break;

  case 612: /* StringExpr: tGetEnv '(' StringExprVar ')'  */
#line 6603 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[-1].c));
    }
#line 14834 "Gmsh.tab.cpp"
    break;

  case 613: /* StringExpr: tGetStringValue '(' StringExprVar ',' StringExprVar ')'  */
#line 6610 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 14846 "Gmsh.tab.cpp"
    break;

  case 614: /* StringExpr: tGetString LP StringExprVar RP  */
#line 6618 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 14857 "Gmsh.tab.cpp"
    break;

  case 615: /* StringExpr: tGetString LP StringExprVar ',' StringExprVar RP  */
#line 6625 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 14869 "Gmsh.tab.cpp"
    break;

  case 616: /* StringExpr: tGetForcedStr '(' Struct_FullName GetForcedStr_Default ')'  */
#line 6634 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].c), 2);
    }
#line 14877 "Gmsh.tab.cpp"
    break;

  case 617: /* StringExpr: tGetForcedStr '(' Struct_FullName '.' tSTRING_Reserved GetForcedStr_Default ')'  */
#line 6638 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].c), 2);
    }
#line 14885 "Gmsh.tab.cpp"
    break;

  case 618: /* StringExpr: tStrCat LP RecursiveListOfStringExprVar RP  */
#line 6642 "Gmsh.y"
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[-1].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        char *s;
        List_Read((yyvsp[-1].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 14904 "Gmsh.tab.cpp"
    break;

  case 619: /* StringExpr: tStrPrefix '(' StringExprVar ')'  */
#line 6657 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-1].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[-1].c)) - 1; i >= 0; i--){
	if((yyvsp[-1].c)[i] == '.'){
	  strncpy((yyval.c), (yyvsp[-1].c), i);
	  (yyval.c)[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy((yyval.c), (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 14922 "Gmsh.tab.cpp"
    break;

  case 620: /* StringExpr: tStrRelative '(' StringExprVar ')'  */
#line 6671 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-1].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[-1].c)) - 1; i >= 0; i--){
	if((yyvsp[-1].c)[i] == '/' || (yyvsp[-1].c)[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy((yyval.c), (yyvsp[-1].c));
      else
	strcpy((yyval.c), &(yyvsp[-1].c)[i + 1]);
      Free((yyvsp[-1].c));
    }
#line 14940 "Gmsh.tab.cpp"
    break;

  case 621: /* StringExpr: tStrReplace '(' StringExprVar ',' StringExprVar ',' StringExprVar ')'  */
#line 6685 "Gmsh.y"
    {
      std::string input = (yyvsp[-5].c);
      std::string substr_old = (yyvsp[-3].c);
      std::string substr_new = (yyvsp[-1].c);
      std::string ret = ReplaceSubString(substr_old, substr_new, input);
      (yyval.c) = (char *)Malloc((ret.size() + 1) * sizeof(char));
      strcpy((yyval.c), ret.c_str());
      Free((yyvsp[-5].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 14956 "Gmsh.tab.cpp"
    break;

  case 622: /* StringExpr: tStr LP RecursiveListOfStringExprVar RP  */
#line 6697 "Gmsh.y"
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[-1].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        char *s;
        List_Read((yyvsp[-1].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
        if(i != List_Nbr((yyvsp[-1].l)) - 1) strcat((yyval.c), "\n");
      }
      List_Delete((yyvsp[-1].l));
    }
#line 14976 "Gmsh.tab.cpp"
    break;

  case 623: /* StringExpr: tUpperCase LP StringExprVar RP  */
#line 6713 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 14989 "Gmsh.tab.cpp"
    break;

  case 624: /* StringExpr: tLowerCase LP StringExprVar RP  */
#line 6722 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 15002 "Gmsh.tab.cpp"
    break;

  case 625: /* StringExpr: tLowerCaseIn LP StringExprVar RP  */
#line 6731 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if(i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 15016 "Gmsh.tab.cpp"
    break;

  case 626: /* StringExpr: tStrChoice LP FExpr ',' StringExprVar ',' StringExprVar RP  */
#line 6741 "Gmsh.y"
    {
      if((yyvsp[-5].d)){
        (yyval.c) = (yyvsp[-3].c);
        Free((yyvsp[-1].c));
      }
      else{
        (yyval.c) = (yyvsp[-1].c);
        Free((yyvsp[-3].c));
      }
    }
#line 15031 "Gmsh.tab.cpp"
    break;

  case 627: /* StringExpr: tStrSub LP StringExprVar ',' FExpr ',' FExpr RP  */
#line 6752 "Gmsh.y"
    {
      std::string in = (yyvsp[-5].c);
      std::string out = in.substr((int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c));
    }
#line 15043 "Gmsh.tab.cpp"
    break;

  case 628: /* StringExpr: tStrSub LP StringExprVar ',' FExpr RP  */
#line 6760 "Gmsh.y"
    {
      std::string in = (yyvsp[-3].c);
      std::string out = in.substr((int)(yyvsp[-1].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-3].c));
    }
#line 15055 "Gmsh.tab.cpp"
    break;

  case 629: /* StringExpr: tSprintf LP StringExprVar RP  */
#line 6768 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 15063 "Gmsh.tab.cpp"
    break;

  case 630: /* StringExpr: tSprintf LP StringExprVar ',' RecursiveListOfDouble RP  */
#line 6772 "Gmsh.y"
    {
      std::string tmpstring;
      int i = printListOfDouble((yyvsp[-3].c), (yyvsp[-1].l), tmpstring);
      if(i < 0){
	yymsg(0, "Too few arguments in Sprintf");
	(yyval.c) = (yyvsp[-3].c);
      }
      else if(i > 0){
	yymsg(0, "%d extra argument%s in Sprintf", i, (i > 1) ? "s" : "");
	(yyval.c) = (yyvsp[-3].c);
      }
      else{
	(yyval.c) = strsave((char*)tmpstring.c_str());
	Free((yyvsp[-3].c));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 15085 "Gmsh.tab.cpp"
    break;

  case 631: /* StringExpr: tFixRelativePath LP StringExprVar RP  */
#line 6790 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 15096 "Gmsh.tab.cpp"
    break;

  case 632: /* StringExpr: tCurrentDirectory  */
#line 6797 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 15106 "Gmsh.tab.cpp"
    break;

  case 633: /* StringExpr: tCurrentFileName  */
#line 6803 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 15116 "Gmsh.tab.cpp"
    break;

  case 634: /* StringExpr: tDirName LP StringExprVar RP  */
#line 6809 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 15127 "Gmsh.tab.cpp"
    break;

  case 635: /* StringExpr: tAbsolutePath LP StringExprVar RP  */
#line 6816 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 15138 "Gmsh.tab.cpp"
    break;

  case 636: /* $@16: %empty  */
#line 6823 "Gmsh.y"
    { init_options(); }
#line 15144 "Gmsh.tab.cpp"
    break;

  case 637: /* StringExpr: tDefineString LP StringExpr $@16 CharParameterOptionsOrNone RP  */
#line 6825 "Gmsh.y"
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 15156 "Gmsh.tab.cpp"
    break;

  case 638: /* StringExpr: tNameStruct LP NameStruct_Arg RP  */
#line 6833 "Gmsh.y"
    {
      std::string out;
      const std::string * key_struct = nullptr;
      switch (gmsh_yynamespaces.get_key_struct_from_tag(struct_namespace,
                                                        (int)(yyvsp[-1].d), key_struct)) {
      case 0:
        out = *key_struct;
        break;
      case 1:
        yymsg(1, "Unknown NameSpace '%s' of Struct", struct_namespace.c_str());
        break;
      case 2:
        yymsg(1, "Unknown Struct of index %d", (int)(yyvsp[-1].d));
        break;
      default:
        break;
      }
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
    }
#line 15181 "Gmsh.tab.cpp"
    break;

  case 639: /* NameStruct_Arg: '#' FExpr  */
#line 6857 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[0].d); }
#line 15187 "Gmsh.tab.cpp"
    break;

  case 640: /* NameStruct_Arg: String__Index tSCOPE '#' FExpr  */
#line 6859 "Gmsh.y"
    { struct_namespace = (yyvsp[-3].c); Free((yyvsp[-3].c)); (yyval.d) = (yyvsp[0].d); }
#line 15193 "Gmsh.tab.cpp"
    break;

  case 641: /* Str_BracedRecursiveListOfStringExprVar: tStr LP BracedRecursiveListOfStringExprVar RP  */
#line 6865 "Gmsh.y"
    { (yyval.l) = (yyvsp[-1].l); }
#line 15199 "Gmsh.tab.cpp"
    break;

  case 642: /* BracedOrNotRecursiveListOfStringExprVar: RecursiveListOfStringExprVar  */
#line 6870 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); }
#line 15205 "Gmsh.tab.cpp"
    break;

  case 643: /* BracedOrNotRecursiveListOfStringExprVar: BracedRecursiveListOfStringExprVar  */
#line 6872 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); }
#line 15211 "Gmsh.tab.cpp"
    break;

  case 644: /* BracedRecursiveListOfStringExprVar: '{' RecursiveListOfStringExprVar '}'  */
#line 6877 "Gmsh.y"
    { (yyval.l) = (yyvsp[-1].l); }
#line 15217 "Gmsh.tab.cpp"
    break;

  case 645: /* RecursiveListOfStringExprVar: StringExprVar  */
#line 6882 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 15226 "Gmsh.tab.cpp"
    break;

  case 646: /* RecursiveListOfStringExprVar: MultiStringExprVar  */
#line 6887 "Gmsh.y"
    { (yyval.l) = (yyvsp[0].l); }
#line 15232 "Gmsh.tab.cpp"
    break;

  case 647: /* RecursiveListOfStringExprVar: RecursiveListOfStringExprVar ',' StringExprVar  */
#line 6889 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 15240 "Gmsh.tab.cpp"
    break;

  case 648: /* RecursiveListOfStringExprVar: RecursiveListOfStringExprVar ',' MultiStringExprVar  */
#line 6893 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	char* c;
	List_Read((yyvsp[0].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[0].l));
    }
#line 15253 "Gmsh.tab.cpp"
    break;

  case 649: /* MultiStringExprVar: String__Index '(' ')'  */
#line 6905 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(char *));
      if(!gmsh_yystringsymbols.count((yyvsp[-2].c)))
	yymsg(0, "Unknown string variable '%s'", (yyvsp[-2].c));
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[-2].c)]);
	for(std::size_t i = 0; i < s.size(); i++) {
          char * val_ = strsave((char*)s.at(i).c_str());
	  List_Add((yyval.l), &val_);
        }
      }
      Free((yyvsp[-2].c));
    }
#line 15271 "Gmsh.tab.cpp"
    break;

  case 650: /* MultiStringExprVar: String__Index '.' tSTRING_Reserved '(' ')'  */
#line 6919 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 15279 "Gmsh.tab.cpp"
    break;

  case 651: /* MultiStringExprVar: String__Index tSCOPE String__Index '.' tSTRING_Reserved '(' ')'  */
#line 6923 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 15287 "Gmsh.tab.cpp"
    break;

  case 652: /* StringIndex: tSTRING '~' '{' FExpr '}'  */
#line 6930 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 15299 "Gmsh.tab.cpp"
    break;

  case 653: /* StringIndex: StringIndex '~' '{' FExpr '}'  */
#line 6938 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 15311 "Gmsh.tab.cpp"
    break;

  case 654: /* StringIndex: tStringToName '[' StringExprVar ']' '~' '{' FExpr '}'  */
#line 6946 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-5].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[-5].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-5].c));
    }
#line 15323 "Gmsh.tab.cpp"
    break;

  case 655: /* String__Index: tSTRING  */
#line 6957 "Gmsh.y"
    { (yyval.c) = (yyvsp[0].c); }
#line 15329 "Gmsh.tab.cpp"
    break;

  case 656: /* String__Index: StringIndex  */
#line 6959 "Gmsh.y"
    { (yyval.c) = (yyvsp[0].c); }
#line 15335 "Gmsh.tab.cpp"
    break;

  case 657: /* String__Index: tStringToName '[' StringExprVar ']'  */
#line 6962 "Gmsh.y"
    { (yyval.c) = (yyvsp[-1].c); }
#line 15341 "Gmsh.tab.cpp"
    break;


#line 15345 "Gmsh.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 6965 "Gmsh.y"


void assignVariable(const std::string &name, int index, int assignType,
                    double value)
{
  if(!gmsh_yysymbols.count(name)){
    if(!assignType){
      gmsh_yysymbol &s(gmsh_yysymbols[name]);
      s.list = true;
      s.value.resize(index + 1, 0.);
      s.value[index] = value;
    }
    else
      yymsg(0, "Unknown variable '%s'", name.c_str());
  }
  else{
    gmsh_yysymbol &s(gmsh_yysymbols[name]);
    if(s.list){
      if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
      switch(assignType){
      case 0 : s.value[index] = value; break;
      case 1 : s.value[index] += value; break;
      case 2 : s.value[index] -= value; break;
      case 3 : s.value[index] *= value; break;
      case 4 :
        if(value) s.value[index] /= value;
        else yymsg(0, "Division by zero in '%s[%d] /= %g'",
                   name.c_str(), index, value);
        break;
      }
    }
    else
      yymsg(0, "Variable '%s' is not a list", name.c_str());
  }
}

void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values)
{
  if(List_Nbr(indices) != List_Nbr(values)){
    yymsg(0, "Incompatible array dimensions in affectation");
  }
  else{
    if(!gmsh_yysymbols.count(name)){
      if(!assignType){
        gmsh_yysymbol &s(gmsh_yysymbols[name]);
        s.list = true;
        for(int i = 0; i < List_Nbr(indices); i++){
          int index = (int)(*(double*)List_Pointer(indices, i));
          s.value.resize(index + 1, 0.);
          s.value[index] = *(double*)List_Pointer(values, i);
        }
      }
      else
        yymsg(0, "Unknown variable '%s'", name.c_str());
    }
    else{
      gmsh_yysymbol &s(gmsh_yysymbols[name]);
      if(s.list){
        for(int i = 0; i < List_Nbr(indices); i++){
          int index = (int)(*(double*)List_Pointer(indices, i));
          double d = *(double*)List_Pointer(values, i);
          if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
          switch(assignType){
          case 0 : s.value[index] = d; break;
          case 1 : s.value[index] += d; break;
          case 2 : s.value[index] -= d; break;
          case 3 : s.value[index] *= d; break;
          case 4 :
            if(d) s.value[index] /= d;
            else yymsg(0, "Division by zero in '%s[%d] /= %g'", name.c_str(), index, d);
            break;
          }
        }
      }
      else
        yymsg(0, "Variable '%s' is not a list", name.c_str());
    }
  }
}

void incrementVariable(const std::string &name, int index, double value)
{
  if(!gmsh_yysymbols.count(name))
    yymsg(0, "Unknown variable '%s'", name.c_str());
  else{
    gmsh_yysymbol &s(gmsh_yysymbols[name]);
    if(s.list){
      if((int)s.value.size() < index + 1) s.value.resize(index + 1, 0.);
      s.value[index] += value;
    }
    else
      yymsg(0, "Variable '%s' is not a list", name.c_str());
  }
}

int printListOfDouble(const char *format, List_T *list, std::string &buffer)
{
  buffer = format;

  int numFormats = 0;
  for(std::size_t i = 0; i < strlen(format); i++) {
    if(format[i] == '%') numFormats++;
  }

  // if format does not contain formatting characters, dump the list (useful for
  // quick debugging of lists)
  if(!numFormats){
    for(int i = 0; i < List_Nbr(list); i++){
      double d;
      List_Read(list, i, &d);
      char tmp[256];
      sprintf(tmp, " [%d]%g", i, d);
      buffer += tmp;
    }
    return 0;
  }

  char tmp1[256], tmp2[256];
  int j = 0, k = 0;

  while(j < (int)strlen(format) && format[j] != '%') j++;
  buffer.resize(j);

  for(int i = 0; i < List_Nbr(list); i++){
    k = j;
    j++;
    if(j < (int)strlen(format)){
      if(format[j] == '%'){
	buffer += "%";
	j++;
      }
      while(j < (int)strlen(format) && format[j] != '%') j++;
      if(k != j){
	strncpy(tmp1, &(format[k]), j-k);
	tmp1[j-k] = '\0';
	sprintf(tmp2, tmp1, *(double*)List_Pointer(list, i));
	buffer += tmp2;
      }
    }
    else
      return List_Nbr(list) - i;
  }
  if(j != (int)strlen(format))
    return -1;
  return 0;
}

void PrintParserSymbols(bool help, std::vector<std::string> &vec)
{
  if(help){
    vec.push_back("//");
    vec.push_back("// Numbers");
    vec.push_back("//");
  }
  for(auto it = gmsh_yysymbols.begin(); it != gmsh_yysymbols.end(); it++){
    gmsh_yysymbol s(it->second);
    std::ostringstream sstream;
    sstream.precision(12);
    sstream << it->first;
    if(s.list){
      sstream << "[] = {";
      for(std::size_t i = 0; i < s.value.size(); i++){
        if(i) sstream << ", ";
        sstream << s.value[i];
      }
      sstream << "}";
    }
    else
      sstream << " = " << s.value[0];
    sstream << ";";
    vec.push_back(sstream.str());
  }
  if(help){
    vec.push_back("//");
    vec.push_back("// Strings");
    vec.push_back("//");
  }
  for(auto it = gmsh_yystringsymbols.begin(); it != gmsh_yystringsymbols.end();
      it++){
    if(it->second.size() == 1)
      vec.push_back(it->first + " = \"" + it->second[0] + "\";");
    else{
      std::string s = it->first + "[] = Str({";
      for(std::size_t i = 0; i < it->second.size(); i++){
        if(i) s += ", ";
        s += std::string("\"") + it->second[i] + "\"";
      }
      s += "});";
      vec.push_back(s);
    }
  }
  if(gmsh_yynamespaces.size()){
    if(help){
      vec.push_back("//");
      vec.push_back("// Structures");
      vec.push_back("//");
    }
    std::vector<std::string> strs;
    gmsh_yynamespaces.sprint(strs);
    vec.insert(vec.end(), strs.begin(), strs.end());
  }
}

fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list)
{
  // Warning: this returns a fullMatrix copy, and deletes the input list
  int M = List_Nbr(list);
  int N = 0;
  for(int i = 0; i < M; i++){
    List_T *line = *(List_T**)List_Pointer_Fast(list, i);
    N = std::max(N, List_Nbr(line));
  }
  fullMatrix<double> mat(M, N);
  for(int i = 0; i < M; i++){
    List_T *line = *(List_T**)List_Pointer_Fast(list, i);
    for(int j = 0; j < List_Nbr(line); j++){
      double val;
      List_Read(line, j, &val);
      mat(i, j) = val;
    }
  }
  for(int i = 0; i < List_Nbr(list); i++)
    List_Delete(*(List_T**)List_Pointer(list, i));
  List_Delete(list);
  return mat;
}

void ListOfDouble2Vector(List_T *list, std::vector<int> &v)
{
  v.clear();
  if(!list) return;
  v.reserve(List_Nbr(list));
  for(int i = 0; i < List_Nbr(list); i++){
    double d;
    List_Read(list, i, &d);
    v.push_back((int)d);
  }
}

void ListOfDouble2Vector(List_T *list, std::vector<double> &v)
{
  v.clear();
  if(!list) return;
  v.reserve(List_Nbr(list));
  for(int i = 0; i < List_Nbr(list); i++){
    double d;
    List_Read(list, i, &d);
    v.push_back(d);
  }
}

void ListOfShapes2VectorOfPairs(List_T *list, std::vector<std::pair<int, int> > &v)
{
  for(int i = 0; i < List_Nbr(list); i++){
    Shape s;
    List_Read(list, i, &s);
    int dim = s.Type / 100 - 1;
    if(dim >= 0 && dim <= 3) v.push_back(std::make_pair(dim, s.Num));
  }
}

void VectorOfPairs2ListOfShapes(const std::vector<std::pair<int, int> > &v, List_T *list)
{
  for(std::size_t i = 0; i < v.size(); i++){
    int dim = v[i].first;
    int tag = v[i].second;
    Shape s;
    s.Type = (dim == 3) ? MSH_VOLUME : (dim == 2) ? MSH_SURF_PLAN :
      (dim == 1) ? MSH_SEGM_LINE : MSH_POINT;
    s.Num = tag;
    List_Add(list, &s);
  }
}

void yyerror(const char *s)
{
  if(gmsh_yyname.empty())
    Msg::Error("%s (%s)", s, gmsh_yytext);
  else
    Msg::Error("'%s', line %d: %s (%s)", gmsh_yyname.c_str(), gmsh_yylineno - 1,
               s, gmsh_yytext);
  gmsh_yyerrorstate++;
}

void yymsg(int level, const char *fmt, ...)
{
  va_list args;
  char tmp[1024];

  va_start(args, fmt);
  vsprintf(tmp, fmt, args);
  va_end(args);

  if(level == 0){
    if(gmsh_yyname.empty())
      Msg::Error("%s", tmp);
    else
      Msg::Error("'%s', line %d: %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
    gmsh_yyerrorstate++;
  }
  else if(level == 1){
    if(gmsh_yyname.empty())
      Msg::Warning("%s", tmp);
    else
      Msg::Warning("'%s', line %d: %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
  else{
    if(gmsh_yyname.empty())
      Msg::Info("%s", tmp);
    else
      Msg::Info("'%s', line %d: %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::vector<double>& affineTransform)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  GFace *target = GModel::current()->getFaceByTag(std::abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(std::abs(iSource));
  if(!target || !source) {
    Msg::Error("Could not find surface %d or %d for periodic copy",
               iTarget, iSource);
    return;
  }
  target->setMeshMaster(source, affineTransform);
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::map<int,int>& edgeCounterparts)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  Msg::Info("Encoding periodic connection between %d and %d", iTarget, iSource);
  for(auto sIter = edgeCounterparts.begin(); sIter != edgeCounterparts.end();
      ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  GFace *target = GModel::current()->getFaceByTag(std::abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(std::abs(iSource));
  if(!target || !source) {
    Msg::Error("Could not find surface %d or %d for periodic copy",
               iTarget,iSource);
    return;
  }
  target->setMeshMaster(source, edgeCounterparts);
}

void addPeriodicEdge(int iTarget,int iSource,
                     const std::vector<double>& affineTransform)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  GEdge *target = GModel::current()->getEdgeByTag(std::abs(iTarget));
  GEdge *source = GModel::current()->getEdgeByTag(std::abs(iSource));
  if(!target || !source) {
    Msg::Error("Could not find curve %d or %d for periodic copy",
               iTarget,iSource);
    return;
  }
  if(affineTransform.size() >= 12) {
    target->setMeshMaster(source, affineTransform);
  }
  else {
    target->setMeshMaster(source, iSource * iTarget < 0 ? -1 : 1);
  }
}

void computeAffineTransformation(SPoint3& origin, SPoint3& axis,
                                 double angle, SPoint3& translation,
                                 std::vector<double>& tfo)
{
  tfo.resize(16,0.0);

  double ca = cos(angle);
  double sa = sin(angle);

  double ux = axis.x();
  double uy = axis.y();
  double uz = axis.z();

  tfo.resize(16);

  tfo[0 * 4 + 0] = ca + ux * ux * (1. - ca);
  tfo[0 * 4 + 1] = ux * uy * (1. - ca) - uz * sa;
  tfo[0 * 4 + 2] = ux * uz * (1. - ca) + uy * sa;

  tfo[1 * 4 + 0] = ux * uy * (1. - ca) + uz * sa;
  tfo[1 * 4 + 1] = ca + uy * uy * (1. - ca);
  tfo[1 * 4 + 2] = uy * uz * (1. - ca) - ux * sa;

  tfo[2 * 4 + 0] = ux * uz * (1. - ca) - uy * sa;
  tfo[2 * 4 + 1] = uy * uz * (1. - ca) + ux * sa;
  tfo[2 * 4 + 2] = ca + uz * uz * (1. - ca);

  int idx = 0;
  for(size_t i = 0; i < 3; i++,idx++) {
    int tIdx = i * 4 + 3;
    tfo[tIdx] = origin[i] + translation[i];
    for(int j = 0; j < 3; j++,idx++) tfo[tIdx] -= tfo[idx] * origin[j];
  }

  for(int i = 0; i < 4; i++) tfo[12 + i] = 0;
  tfo[15] = 1;
}

void addEmbedded(int dim, std::vector<int> tags, int dim2, int tag2)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  if(dim2 == 2){
    GFace *gf = GModel::current()->getFaceByTag(tag2);
    if(!gf){
      yymsg(0, "Unknown model surface with tag %d", tag2);
      return;
    }
    for(std::size_t i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gf->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model point %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gf->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model curve %d", tags[i]);
      }
    }
  }
  else if(dim2 == 3){
    GRegion *gr = GModel::current()->getRegionByTag(tag2);
    if(!gr){
      yymsg(0, "Unknown model volume with tag %d", tag2);
      return;
    }
    for(std::size_t i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gr->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model point with tag %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gr->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model curve with tag %d", tags[i]);
      }
      else if(dim == 2){
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(gf)
          gr->addEmbeddedFace(gf);
        else
          yymsg(0, "Unknown model surface with tag %d", tags[i]);
      }
    }
  }
}

void removeEmbedded(const std::vector<std::pair<int, int> > &dimTags,
                    int rdim)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(std::size_t i = 0; i < dimTags.size(); i++){
    int dim = dimTags[i].first, tag = dimTags[i].second;
    if(dim == 2){
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf) {
        if(rdim < 0 || rdim == 1) gf->embeddedEdges().clear();
        if(rdim < 0 || rdim == 0) gf->embeddedVertices().clear();
      }
      else
        yymsg(0, "Unknown model surface with tag %d", tag);
    }
    else if(dimTags[i].first == 3){
      GRegion *gr = GModel::current()->getRegionByTag(tag);
      if(gr) {
        if(rdim < 0 || rdim == 2) gr->embeddedFaces().clear();
        if(rdim < 0 || rdim == 1) gr->embeddedEdges().clear();
        if(rdim < 0 || rdim == 0) gr->embeddedVertices().clear();
      }
      else
        yymsg(0, "Unknown model volume with tag %d", tag);
    }
  }
}

void getAllElementaryTags(int dim, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(std::size_t i = 0; i < entities.size(); i++){
    double tag = entities[i]->tag();
    List_Add(out, &tag);
  }
}

void getAllPhysicalTags(int dim, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  for(auto it = groups.begin(); it != groups.end(); it++){
    double d = it->first;
    List_Add(out, &d);
  }
}

void getElementaryTagsForPhysicalGroups(int dim, List_T *in, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  for(int i = 0; i < List_Nbr(in); i++){
    double num;
    List_Read(in, i, &num);
    auto it = groups.find(num);
    if(it != groups.end()){
      for(unsigned j = 0; j < it->second.size(); j++){
        double d = it->second[j]->tag();
        List_Add(out, &d);
      }
    }
  }
}

void getElementaryTagsInBoundingBox(int dim, double x1, double y1, double z1,
                                    double x2, double y2, double z2, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  SBoundingBox3d box(x1, y1, z1, x2, y2, z2);
  std::vector<GEntity*> entities;
  GModel::current()->getEntitiesInBox(entities, box, dim);
  for(std::size_t i = 0; i < entities.size(); i++){
    double d = entities[i]->tag();
    List_Add(out, &d);
  }
}

void getParentTags(int dim, List_T *in, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(int i = 0; i < List_Nbr(in); i++){
    double num;
    List_Read(in, i, &num);
    GEntity *ge = GModel::current()->getEntityByTag(dim, (int)num);
    if(ge){
      GEntity *parent = ge->getParentEntity();
      if(parent){
        double tag = parent->tag();
        List_Add(out, &tag);
      }
    }
  }
}

void getBoundingBox(int dim, List_T *in, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  SBoundingBox3d box;
  for(int i = 0; i < List_Nbr(in); i++){
    double num;
    List_Read(in, i, &num);
    GEntity *ge = GModel::current()->getEntityByTag(dim, (int)num);
    if(ge) box += ge->bounds();
  }
  if(!box.empty()){
    double b[6] = {box.min().x(), box.min().y(), box.min().z(),
                   box.max().x(), box.max().y(), box.max().z()};
    for(int i = 0; i < 6; i++)
      List_Add(out, &b[i]);
  }
}

void setVisibility(int dim, int visible, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(std::size_t i = 0; i < entities.size(); i++){
    entities[i]->setVisibility(visible);
  }
}

void setVisibility(const std::vector<std::pair<int, int> > &dimTags,
                   int visible, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(std::size_t i = 0; i < dimTags.size(); i++){
    GEntity *ge = GModel::current()->getEntityByTag
      (dimTags[i].first, std::abs(dimTags[i].second));
    if(ge) ge->setVisibility(visible, recursive);
  }
}

void setColor(const std::vector<std::pair<int, int> > &dimTags,
              unsigned int val, bool recursive)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  for(std::size_t i = 0; i < dimTags.size(); i++){
    GEntity *ge = GModel::current()->getEntityByTag
      (dimTags[i].first, std::abs(dimTags[i].second));
    if(ge) ge->setColor(val, recursive);
  }
}

double treat_Struct_FullName_Float
(char* c1, char* c2, int type_var, int index, double val_default, int type_treat)
{
  double out;
  if(!c1 && gmsh_yysymbols.count(c2)){
    if(type_treat == 1) out = 1.; // Exists (type_treat == 1)
    else { // Get (0) or GetForced (2)
      if(type_var == 1) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(s.value.empty()){
          out = val_default;
          if(type_treat == 0) yymsg(0, "Uninitialized variable '%s'", c2);
        }
        else
          out = s.value[0];
      }
      else if(type_var == 2) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(index < 0 || (int)s.value.size() < index + 1){
          out = val_default;
          if(type_treat == 0) yymsg(0, "Uninitialized variable '%s[%d]'", c2, index);
        }
        else{
          out = s.value[index];
        }
      }
      else {
        out = val_default;
      }
    }
  }
  else if(!c1 && type_treat == 1 && gmsh_yystringsymbols.count(c2)) {
    out = 1.;
  }
  else{
    if(type_var == 1) {
      std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
      if(gmsh_yynamespaces.getTag(struct_namespace, struct_name, out)) {
        out = val_default;
        if(type_treat == 0) yymsg(0, "Unknown variable '%s'", struct_name.c_str());
      }
    }
    else {
      out = val_default;
      if(type_treat == 0) yymsg(0, "Unknown variable '%s(.)'", c2);
    }
  }
  Free(c1); Free(c2);
  return out;
}

double treat_Struct_FullName_dot_tSTRING_Float
(char* c1, char* c2, char* c3, int index, double val_default, int type_treat)
{
  double out;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember
          (struct_namespace, struct_name, key_member, out, index)) {
  case 0:
    if(type_treat == 1) out = 1.; // Exists (type_treat == 1)
    break;
  case 1:
    if(!NumberOption(GMSH_GET, c2, 0, c3, out, type_treat==0))
      out = val_default;
    break;
  case 2:
    if(type_treat != 0) {
      const std::string * out_dummy = nullptr;
      out = (gmsh_yynamespaces.getMember
             (struct_namespace, struct_name, key_member, out_dummy))?
        val_default : 1.;
    }
    else {
      out = val_default;
      if(type_treat == 0)
        yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    }
    break;
  case 3:
    out = val_default;
    if(type_treat == 0)
      yymsg(0, "Index %d out of range", index);
    break;
  }
  Free(c1); Free(c2);
  Free(c3);
  return out;
}

List_T * treat_Struct_FullName_dot_tSTRING_ListOfFloat
(char* c1, char* c2, char* c3)
{
  List_T * out, * val_default = nullptr;
  const std::vector<double> * out_vector; double val_;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember_Vector
          (struct_namespace, struct_name, key_member, out_vector)) {
  case 0:
    out = List_Create(out_vector->size(), 1, sizeof(double));
    for(std::size_t i = 0; i < out_vector->size(); i++) {
      val_ = out_vector->at(i);
      List_Add(out, &val_);
    }
    break;
  case 1:
    yymsg(0, "Unknown Struct: %s", struct_name.c_str());
    out = val_default;
    break;
  case 2:
    out = val_default;
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }
  Free(c1); Free(c2);
  Free(c3);
  return out;
}

int treat_Struct_FullName_dot_tSTRING_Float_getDim
(char* c1, char* c2, char* c3)
{
  int out;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember_Dim
          (struct_namespace, struct_name, key_member, out)) {
  case 0:
    break;
  case 1:
    out = 0;
    break;
  case 2:
    out = 0;
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }
  Free(c1); Free(c2);
  Free(c3);
  return out;
}

char * treat_Struct_FullName_String
(char* c1, char* c2, int type_var, int index, char * val_default, int type_treat)
{
  std::string string_default(val_default? val_default : std::string(""));
  const std::string * out = nullptr;
  std::string out_tmp;
  if(!c1 && gmsh_yystringsymbols.count(c2)){
    // Get (0) or GetForced (2)
    if(gmsh_yystringsymbols[c2].size() != 1){
      out = &string_default;
      if(type_treat == 0)
        yymsg(0, "Expected single valued string variable '%s'", c2);
    }
    else {
      out_tmp = gmsh_yystringsymbols[c2][0];
      out = &out_tmp;
    }
  }
  else{
    out = &string_default;
    if(type_treat == 0) yymsg(0, "Unknown string variable '%s'", c2);
  }
  char* out_c = (char*)Malloc((out->size() + 1) * sizeof(char));
  strcpy(out_c, out->c_str());
  Free(c1); Free(c2);
  return out_c;
}

char* treat_Struct_FullName_dot_tSTRING_String
(char* c1, char* c2, char* c3, int index, char * val_default, int type_treat)
{
  std::string string_default(val_default? val_default : std::string(""));
  const std::string * out = nullptr;
  std::string out_tmp; // PD: we should avoid that -> StringOption() to be changed
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember
          (struct_namespace, struct_name, key_member, out, index)) {
  case 0:
    break;
  case 1:
    if(StringOption(GMSH_GET, c2, 0, c3, out_tmp, type_treat==0))
      out = &out_tmp;
    else
      out = &string_default;
    break;
  case 2:
    out = &string_default;
    if(type_treat == 0)
      yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  case 3:
    out = &string_default;
    if(type_treat == 0)
      yymsg(0, "Index %d out of range", index);
    break;
  }
  char* out_c = (char*)Malloc((out->size() + 1) * sizeof(char));
  strcpy(out_c, out->c_str());
  Free(c1); Free(c2);
  Free(c3);
  return out_c;
}

List_T * treat_Struct_FullName_dot_tSTRING_ListOfString
(char* c1, char* c2, char* c3)
{
  List_T * out, * val_default = nullptr;
  const std::vector<std::string> * out_vector; char * val_;
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember_Vector
          (struct_namespace, struct_name, key_member, out_vector)) {
  case 0:
    out = List_Create(out_vector->size(), 1, sizeof(char *));
    for(std::size_t i = 0; i < out_vector->size(); i++) {
      val_ = strsave((char*)out_vector->at(i).c_str());
      List_Add(out, &val_);
    }
    break;
  case 1:
    yymsg(0, "Unknown Struct: %s", struct_name.c_str());
    out = val_default;
    break;
  case 2:
    out = val_default;
    yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  }
  Free(c1); Free(c2);
  Free(c3);
  return out;
}
