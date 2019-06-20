/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

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
#line 1 "Gmsh.y" /* yacc.c:337  */

// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
static int flag_tSTRING_alloc = 0;
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
int printListOfDouble(char *format, List_T *list, char *buffer);
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
   char* val_default = NULL, int type_treat = 0);
char* treat_Struct_FullName_dot_tSTRING_String
  (char* c1, char* c2, char* c3, int index = 0,
   char* val_default = NULL, int type_treat = 0);
List_T * treat_Struct_FullName_dot_tSTRING_ListOfString
  (char* c1, char* c2, char* c3);

struct doubleXstring{
  double d;
  char *s;
};


#line 243 "Gmsh.tab.cpp" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Gmsh.tab.hpp".  */
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
    tMass = 327,
    tCenterOfMass = 328,
    tOnelabAction = 329,
    tOnelabRun = 330,
    tCodeName = 331,
    tCpu = 332,
    tMemory = 333,
    tTotalMemory = 334,
    tCreateTopology = 335,
    tCreateGeometry = 336,
    tClassifySurfaces = 337,
    tRenumberMeshNodes = 338,
    tRenumberMeshElements = 339,
    tDistanceFunction = 340,
    tDefineConstant = 341,
    tUndefineConstant = 342,
    tDefineNumber = 343,
    tDefineStruct = 344,
    tNameStruct = 345,
    tDimNameSpace = 346,
    tAppend = 347,
    tDefineString = 348,
    tSetNumber = 349,
    tSetTag = 350,
    tSetString = 351,
    tPoint = 352,
    tCircle = 353,
    tEllipse = 354,
    tCurve = 355,
    tSphere = 356,
    tPolarSphere = 357,
    tSurface = 358,
    tSpline = 359,
    tVolume = 360,
    tBox = 361,
    tCylinder = 362,
    tCone = 363,
    tTorus = 364,
    tEllipsoid = 365,
    tQuadric = 366,
    tShapeFromFile = 367,
    tRectangle = 368,
    tDisk = 369,
    tWire = 370,
    tGeoEntity = 371,
    tCharacteristic = 372,
    tLength = 373,
    tParametric = 374,
    tElliptic = 375,
    tRefineMesh = 376,
    tAdaptMesh = 377,
    tRelocateMesh = 378,
    tReorientMesh = 379,
    tSetFactory = 380,
    tThruSections = 381,
    tWedge = 382,
    tFillet = 383,
    tChamfer = 384,
    tPlane = 385,
    tRuled = 386,
    tTransfinite = 387,
    tPhysical = 388,
    tCompound = 389,
    tPeriodic = 390,
    tParent = 391,
    tUsing = 392,
    tPlugin = 393,
    tDegenerated = 394,
    tRecursive = 395,
    tSewing = 396,
    tRotate = 397,
    tTranslate = 398,
    tSymmetry = 399,
    tDilate = 400,
    tExtrude = 401,
    tLevelset = 402,
    tAffine = 403,
    tBooleanUnion = 404,
    tBooleanIntersection = 405,
    tBooleanDifference = 406,
    tBooleanSection = 407,
    tBooleanFragments = 408,
    tThickSolid = 409,
    tRecombine = 410,
    tSmoother = 411,
    tSplit = 412,
    tDelete = 413,
    tCoherence = 414,
    tIntersect = 415,
    tMeshAlgorithm = 416,
    tReverseMesh = 417,
    tLayers = 418,
    tScaleLast = 419,
    tHole = 420,
    tAlias = 421,
    tAliasWithOptions = 422,
    tCopyOptions = 423,
    tQuadTriAddVerts = 424,
    tQuadTriNoNewVerts = 425,
    tRecombLaterals = 426,
    tTransfQuadTri = 427,
    tText2D = 428,
    tText3D = 429,
    tInterpolationScheme = 430,
    tTime = 431,
    tCombine = 432,
    tBSpline = 433,
    tBezier = 434,
    tNurbs = 435,
    tNurbsOrder = 436,
    tNurbsKnots = 437,
    tColor = 438,
    tColorTable = 439,
    tFor = 440,
    tIn = 441,
    tEndFor = 442,
    tIf = 443,
    tElseIf = 444,
    tElse = 445,
    tEndIf = 446,
    tExit = 447,
    tAbort = 448,
    tField = 449,
    tReturn = 450,
    tCall = 451,
    tSlide = 452,
    tMacro = 453,
    tShow = 454,
    tHide = 455,
    tGetValue = 456,
    tGetStringValue = 457,
    tGetEnv = 458,
    tGetString = 459,
    tGetNumber = 460,
    tUnique = 461,
    tHomology = 462,
    tCohomology = 463,
    tBetti = 464,
    tExists = 465,
    tFileExists = 466,
    tGetForced = 467,
    tGetForcedStr = 468,
    tGMSH_MAJOR_VERSION = 469,
    tGMSH_MINOR_VERSION = 470,
    tGMSH_PATCH_VERSION = 471,
    tGmshExecutableName = 472,
    tSetPartition = 473,
    tNameToString = 474,
    tStringToName = 475,
    tAFFECTPLUS = 476,
    tAFFECTMINUS = 477,
    tAFFECTTIMES = 478,
    tAFFECTDIVIDE = 479,
    tOR = 480,
    tAND = 481,
    tEQUAL = 482,
    tNOTEQUAL = 483,
    tLESSOREQUAL = 484,
    tGREATEROREQUAL = 485,
    tLESSLESS = 486,
    tGREATERGREATER = 487,
    tPLUSPLUS = 488,
    tMINUSMINUS = 489,
    UNARYPREC = 490
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 166 "Gmsh.y" /* yacc.c:352  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;

#line 533 "Gmsh.tab.cpp" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   17160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  258
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  616
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2202

#define YYUNDEFTOK  2
#define YYMAXUTOK   490

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   243,     2,   255,     2,   240,   242,     2,
     248,   249,   238,   236,   257,   237,   254,   239,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     230,     2,   232,   225,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   250,     2,   251,   247,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   252,   241,   253,   256,     2,     2,     2,
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
     226,   227,   228,   229,   231,   233,   234,   235,   244,   245,
     246
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   270,   270,   271,   276,   278,   282,   283,   284,   285,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   323,   327,   334,   339,
     344,   358,   371,   384,   412,   426,   439,   452,   471,   476,
     477,   478,   479,   480,   484,   486,   491,   493,   499,   603,
     498,   621,   628,   639,   638,   656,   663,   674,   673,   690,
     707,   730,   729,   743,   744,   745,   746,   747,   751,   752,
     758,   758,   759,   759,   765,   766,   767,   768,   773,   779,
     841,   856,   885,   895,   900,   908,   913,   921,   930,   935,
     947,   964,   970,   979,   997,  1015,  1024,  1036,  1041,  1049,
    1069,  1092,  1112,  1120,  1127,  1134,  1156,  1179,  1217,  1238,
    1250,  1264,  1264,  1266,  1268,  1277,  1287,  1286,  1307,  1306,
    1324,  1334,  1333,  1347,  1349,  1357,  1363,  1368,  1395,  1397,
    1400,  1402,  1406,  1407,  1411,  1423,  1436,  1451,  1460,  1473,
    1475,  1479,  1480,  1485,  1493,  1502,  1510,  1524,  1542,  1546,
    1553,  1562,  1565,  1571,  1575,  1587,  1590,  1597,  1600,  1606,
    1629,  1645,  1661,  1698,  1734,  1750,  1766,  1798,  1814,  1831,
    1847,  1897,  1915,  1921,  1927,  1934,  1965,  1980,  2002,  2025,
    2048,  2071,  2095,  2119,  2143,  2169,  2186,  2202,  2220,  2238,
    2245,  2254,  2253,  2283,  2285,  2287,  2289,  2291,  2299,  2301,
    2303,  2305,  2313,  2315,  2317,  2325,  2327,  2329,  2331,  2341,
    2357,  2373,  2389,  2405,  2421,  2438,  2475,  2497,  2521,  2522,
    2527,  2530,  2534,  2551,  2571,  2591,  2610,  2637,  2656,  2677,
    2692,  2708,  2726,  2777,  2798,  2820,  2843,  2948,  2964,  2999,
    3021,  3043,  3055,  3061,  3076,  3104,  3116,  3125,  3132,  3144,
    3164,  3168,  3173,  3177,  3182,  3189,  3196,  3203,  3215,  3288,
    3306,  3331,  3346,  3379,  3391,  3415,  3419,  3424,  3431,  3436,
    3446,  3451,  3457,  3465,  3469,  3473,  3477,  3481,  3485,  3494,
    3558,  3574,  3591,  3608,  3630,  3652,  3687,  3695,  3703,  3709,
    3716,  3723,  3743,  3769,  3781,  3792,  3810,  3828,  3847,  3846,
    3871,  3870,  3897,  3896,  3921,  3920,  3943,  3959,  3976,  3993,
    4016,  4044,  4047,  4053,  4065,  4085,  4089,  4093,  4097,  4101,
    4105,  4109,  4113,  4122,  4135,  4136,  4137,  4138,  4139,  4143,
    4144,  4145,  4146,  4147,  4150,  4174,  4193,  4216,  4219,  4235,
    4238,  4255,  4258,  4264,  4267,  4274,  4277,  4284,  4306,  4347,
    4391,  4430,  4455,  4467,  4479,  4491,  4503,  4512,  4542,  4568,
    4594,  4626,  4653,  4679,  4705,  4731,  4757,  4779,  4790,  4838,
    4892,  4907,  4919,  4930,  4937,  4952,  4966,  4967,  4968,  4972,
    4978,  4990,  5008,  5036,  5037,  5038,  5039,  5040,  5041,  5042,
    5043,  5044,  5051,  5052,  5053,  5054,  5055,  5056,  5057,  5058,
    5059,  5060,  5061,  5062,  5063,  5064,  5065,  5066,  5067,  5068,
    5069,  5070,  5071,  5072,  5073,  5074,  5075,  5076,  5077,  5078,
    5079,  5080,  5081,  5082,  5083,  5084,  5085,  5086,  5087,  5088,
    5097,  5098,  5099,  5100,  5101,  5102,  5103,  5104,  5105,  5106,
    5107,  5112,  5111,  5119,  5121,  5126,  5131,  5135,  5140,  5145,
    5149,  5153,  5157,  5161,  5165,  5169,  5175,  5190,  5194,  5200,
    5205,  5224,  5244,  5275,  5279,  5283,  5287,  5291,  5295,  5299,
    5304,  5314,  5324,  5329,  5340,  5349,  5354,  5359,  5387,  5388,
    5394,  5395,  5401,  5400,  5423,  5425,  5430,  5439,  5441,  5447,
    5448,  5453,  5457,  5461,  5465,  5469,  5476,  5480,  5484,  5488,
    5495,  5500,  5507,  5512,  5516,  5521,  5525,  5533,  5544,  5548,
    5552,  5566,  5574,  5582,  5589,  5599,  5622,  5627,  5633,  5638,
    5644,  5655,  5661,  5667,  5673,  5685,  5699,  5709,  5719,  5729,
    5741,  5745,  5750,  5762,  5766,  5770,  5774,  5792,  5800,  5808,
    5837,  5847,  5863,  5874,  5879,  5883,  5887,  5899,  5903,  5915,
    5932,  5942,  5946,  5961,  5966,  5973,  5977,  5982,  5996,  6012,
    6016,  6020,  6024,  6028,  6036,  6042,  6051,  6055,  6059,  6067,
    6073,  6079,  6083,  6091,  6099,  6106,  6115,  6119,  6123,  6138,
    6152,  6166,  6178,  6194,  6203,  6212,  6222,  6233,  6241,  6249,
    6253,  6272,  6279,  6285,  6292,  6300,  6299,  6309,  6333,  6335,
    6341,  6346,  6348,  6353,  6358,  6363,  6365,  6369,  6381,  6395,
    6399,  6406,  6414,  6422,  6433,  6435,  6438
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tDOUBLE", "tSTRING", "tBIGSTR", "tEND",
  "tAFFECT", "tDOTS", "tSCOPE", "tPi", "tMPI_Rank", "tMPI_Size",
  "tEuclidian", "tCoordinates", "tTestLevel", "tExp", "tLog", "tLog10",
  "tSqrt", "tSin", "tAsin", "tCos", "tAcos", "tTan", "tRand", "tAtan",
  "tAtan2", "tSinh", "tCosh", "tTanh", "tFabs", "tAbs", "tFloor", "tCeil",
  "tRound", "tFmod", "tModulo", "tHypot", "tList", "tLinSpace",
  "tLogSpace", "tListFromFile", "tCatenary", "tPrintf", "tError", "tStr",
  "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative", "tStrReplace",
  "tAbsolutePath", "tDirName", "tStrSub", "tStrLen", "tFind", "tStrFind",
  "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase", "tLowerCaseIn",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tFixRelativePath", "tCurrentDirectory", "tSyncModel", "tNewModel",
  "tMass", "tCenterOfMass", "tOnelabAction", "tOnelabRun", "tCodeName",
  "tCpu", "tMemory", "tTotalMemory", "tCreateTopology", "tCreateGeometry",
  "tClassifySurfaces", "tRenumberMeshNodes", "tRenumberMeshElements",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant",
  "tDefineNumber", "tDefineStruct", "tNameStruct", "tDimNameSpace",
  "tAppend", "tDefineString", "tSetNumber", "tSetTag", "tSetString",
  "tPoint", "tCircle", "tEllipse", "tCurve", "tSphere", "tPolarSphere",
  "tSurface", "tSpline", "tVolume", "tBox", "tCylinder", "tCone", "tTorus",
  "tEllipsoid", "tQuadric", "tShapeFromFile", "tRectangle", "tDisk",
  "tWire", "tGeoEntity", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh",
  "tReorientMesh", "tSetFactory", "tThruSections", "tWedge", "tFillet",
  "tChamfer", "tPlane", "tRuled", "tTransfinite", "tPhysical", "tCompound",
  "tPeriodic", "tParent", "tUsing", "tPlugin", "tDegenerated",
  "tRecursive", "tSewing", "tRotate", "tTranslate", "tSymmetry", "tDilate",
  "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
  "tBooleanIntersection", "tBooleanDifference", "tBooleanSection",
  "tBooleanFragments", "tThickSolid", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverseMesh",
  "tLayers", "tScaleLast", "tHole", "tAlias", "tAliasWithOptions",
  "tCopyOptions", "tQuadTriAddVerts", "tQuadTriNoNewVerts",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tElseIf", "tElse", "tEndIf", "tExit", "tAbort",
  "tField", "tReturn", "tCall", "tSlide", "tMacro", "tShow", "tHide",
  "tGetValue", "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber",
  "tUnique", "tHomology", "tCohomology", "tBetti", "tExists",
  "tFileExists", "tGetForced", "tGetForcedStr", "tGMSH_MAJOR_VERSION",
  "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION", "tGmshExecutableName",
  "tSetPartition", "tNameToString", "tStringToName", "tAFFECTPLUS",
  "tAFFECTMINUS", "tAFFECTTIMES", "tAFFECTDIVIDE", "'?'", "tOR", "tAND",
  "tEQUAL", "tNOTEQUAL", "'<'", "tLESSOREQUAL", "'>'", "tGREATEROREQUAL",
  "tLESSLESS", "tGREATERGREATER", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'",
  "'&'", "'!'", "tPLUSPLUS", "tMINUSMINUS", "UNARYPREC", "'^'", "'('",
  "')'", "'['", "']'", "'{'", "'}'", "'.'", "'#'", "'~'", "','", "$accept",
  "All", "GeoFormatItems", "GeoFormatItem", "SendToFile", "Printf", "View",
  "Views", "ElementCoords", "ElementValues", "Element", "$@1", "$@2",
  "Text2DValues", "Text2D", "$@3", "Text3DValues", "Text3D", "$@4",
  "InterpolationMatrix", "Time", "$@5", "NumericAffectation",
  "NumericIncrement", "LP", "RP", "Affectation", "Comma",
  "DefineConstants", "$@6", "$@7", "$@8", "UndefineConstants",
  "Enumeration", "FloatParameterOptionsOrNone",
  "FloatParameterOptionsOrNone_NoComma", "FloatParameterOptions",
  "FloatParameterOption", "CharParameterOptionsOrNone",
  "CharParameterOptions", "CharParameterOption",
  "PhysicalId_per_dim_entity", "SurfaceConstraints", "CircleOptions",
  "LoopOptions", "Shape", "$@9", "GeoEntity", "GeoEntity123",
  "GeoEntity12", "GeoEntity02", "Transform", "MultipleShape",
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "SetPartition",
  "Visibility", "Command", "Slide", "Loop", "Extrude", "$@10", "$@11",
  "$@12", "$@13", "ExtrudeParameters", "ExtrudeParameter",
  "BooleanOperator", "BooleanOption", "Boolean", "BooleanShape",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "PeriodicTransform", "Constraints", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "$@14",
  "GetForced_Default", "GetForcedStr_Default", "DefineStruct", "$@15",
  "Struct_FullName", "tSTRING_Member", "Append", "AppendOrNot", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
  "ListOfColor", "RecursiveListOfColor", "StringExprVar", "StringExpr",
  "$@16", "NameStruct_Arg", "Str_BracedRecursiveListOfStringExprVar",
  "BracedOrNotRecursiveListOfStringExprVar",
  "BracedRecursiveListOfStringExprVar", "RecursiveListOfStringExprVar",
  "MultiStringExprVar", "StringIndex", "String__Index", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,    63,   480,   481,   482,   483,
      60,   484,    62,   485,   486,   487,    43,    45,    42,    47,
      37,   124,    38,    33,   488,   489,   490,    94,    40,    41,
      91,    93,   123,   125,    46,    35,   126,    44
};
# endif

#define YYPACT_NINF -1877

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1877)))

#define YYTABLE_NINF -564

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   12714,    38,   165, 12874, -1877, -1877,  -167,   168,   -48,   -71,
     -54,    41,   200,   239,   248,   259,    52,   310,   314,   100,
     350,   356,   118,   123,    22,    81,   600,    81,   158,   164,
     173,    61,   185,   192,    62,   203,   254,   287,   294,   313,
     319,   322,   336,   345,   354,   371,   469,   525,   632,   408,
     410,   546,   418,  6809,   425,   433,   439,   598,   -45,   279,
     422,   545,   126,   458,   638,  -101,   492,     1,     1,   505,
     172,   407,   510, -1877, -1877, -1877, -1877, -1877,   544,   359,
     698,   709,    19,    39,   717,   727,   -41,   833,   840,   849,
    5825,   880,   647,   676,   679,    20,    63, -1877,   684,   705,
   -1877, -1877,   882,   980,   741, -1877, 13111,   751, 13170,     5,
      31, -1877, -1877, -1877, 11721,   780, -1877, -1877, -1877, -1877,
   -1877,   795, -1877, -1877, -1877, -1877, -1877, -1877, -1877, -1877,
   -1877, -1877,  -178, -1877, -1877, -1877, -1877,    29, -1877,  1043,
     799,  5572,   456,   804,  1045, 11721, 13051, 13051, -1877, 11721,
   -1877, -1877, -1877, -1877, 13051, -1877, -1877, 11721, -1877, -1877,
   -1877, -1877,   802,   811,  1051, -1877, -1877, 13228,   814,   815,
     816,   818,    22, 11721, 11721, 11721,   819, 11721, 11721, 11721,
     820, 11721, 11721, 11721, 11721, 11721, 11721, 11721, 13051, 11721,
   11721, 11721, 11721,  5825,   821, -1877,  9505, -1877, -1877, -1877,
     823,  5825,  7055, 13051, -1877, -1877, -1877, -1877, -1877,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,   255,    81,    81,    81,    81,    81,   822,    81,
      81,   824,   422,   545,   545, -1877, -1877, -1877,    81,    81,
      36,   885,   887,   890,   825,  7055,   952,   422,   422,   831,
      81,    81,   832,   834,   835, -1877, -1877, -1877, 11721,  7301,
   11721, 11721,  7547,    22,   895,    46, -1877, -1877,   838, -1877,
    4253, -1877, -1877, -1877, -1877, -1877,   109, 11721,  9505,  9505,
     836,   837,  7793,  5825,  5825,  5825, -1877, -1877, -1877, -1877,
   -1877, -1877, -1877, -1877,   842,  8039,   856,  4313,  1082,  7055,
     857,    20,   858,   860,     1,     1,     1, 11721, 11721,   -34,
   -1877,   260,     1, 10415,   338,   -16,   839,   863,   867,   868,
     888,   889,   891,  9505, 11721,  5825,  5825,  5825,   894,    11,
    1132,   898, -1877,  1135,  1137, -1877,   892,   897,   900, -1877,
   -1877,   901,  5825,   904,   905,   906, -1877, 11721,  6071, -1877,
    1144,  1151, 11721, 11721, 11721,   489, 11721,   907, -1877,   972,
   11721, 11721, 11721, -1877, -1877, 11721, -1877,    81,    81,    81,
     912,   913,   914,    81,    81,    81,    81,    81,    81,    81,
   -1877,    81, -1877, -1877, -1877,    81,    81,   915,   917,    81,
     918, -1877,   920,  1161,  1165,   921, -1877, -1877,  1166,  1167,
    1168,  1169,    81, 11721, 14772,   122, 13051,  9505, 11721, -1877,
   -1877,  7055,  7055, -1877,   924, 13228,   422,  1171, -1877, -1877,
   -1877, -1877, -1877, -1877, 11721, 11721,    33,  7055,  1173,   722,
     928,   893,   929,  1176,    30,   931, -1877,   935, 13448, 11721,
   -1877,  1183,  -135, -1877,    74,   -97,   981, -1877,   -61, -1877,
     121,  6499,   -62,   -32,  1092, -1877,    22,   933, 11721, 11721,
   11721, 11721,   934, 15288, 15313, 15338, 11721, 15363, 15388, 15413,
   11721, 15438, 15463, 15488, 15513, 15538, 15563, 15588,   943, 15613,
   15638, 15663, 13873,  1186, 11721,  9505,  4664, -1877,     7, 11721,
    1190,  1191,   949, 11721, 11721, 11721, 11721, 11721, 11721, 11721,
   11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721,  9505,
   11721, 11721, 11721, 11721, 11721, 11721,  9505,  9505,   947, 11721,
   11721, 13051, 11721, 13051,  7055, 13051, 13051, 13051,   953,   973,
     977, 11721,    56, -1877, 10497, 11721,  7055,  5825,  7055, 13051,
   13051,  9505,    22, 13228,    22,   954,  9505,   954, -1877,   954,
   15688, -1877,   212,   946,   130,  1140, -1877,  1224, 11721, 11721,
   11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721,
   11721, 11721,  8285, 11721, 11721, 11721, 11721, 11721,    22, 11721,
   11721,  1229, -1877,   786, 15713,   221,   320, 11721, 11721, 11721,
   -1877,  1228,  1230,  1230,   988, 11721, 11721,  1236,  9505,  9505,
   14800,   994,  1238, -1877,   993, -1877, -1877,  -164, -1877, -1877,
    6745,  6991,     1,     1,   456,   456,  -160, 10415, 10415, 11721,
    3778,  -130, -1877, 11721, 11721, 11721, 11721, 11721, 11721, 11721,
   11721, 11721,   357, 15738,  1239,  1241,  1242, 11721,  1244, 11721,
   -1877, -1877, 11721,  3966, -1877, -1877,  9505,  9505,  9505, 11721,
    1245, 11721, 11721, 11721, 15763,   995, -1877, -1877, 15788, 15813,
   15838,  1069,  7237, -1877,  1001,  4713, 15863, 15888, 14883, 13051,
   13051, 13051, 13051, 13051, 13051, 13051, 13051, 13051, 11721, 13051,
   13051, 13051, 13051,     3, 13228, 13051, 13051, 13051,    22,    22,
   -1877, -1877,  9505, -1877,  1004,  5134, -1877,  1005, 11892, 11721,
     954, 11721, -1877,    22, 11721, 11721,  1229,  1009,   376, 15913,
   13351,  1012,   390, 11721,  1257,  1015,  7055, 15938, 14910,   204,
    1010,  1261,  1263, -1877, -1877, -1877,  9505,   208, 11721, -1877,
   -1877, -1877,    22, 11721, 11721,  1229,  1021, -1877,  1024,   -42,
     422,   545,   422, -1877,  1023, 13902, -1877,   129,  9505,    22,
   11721, 11721,  1269,  1270,  9505, 11721,  1272, 13051,    22, 10738,
    1269, 11721,  1273, -1877,    22,  1276, 13051, 11721,  1035,  1036,
   -1877, 11721,  7483,  7729,  7975,  8221, 13228,  1285,  1286,  1287,
   15963,  1288,  1290,  1291, 15988,  1292,  1293,  1294,  1295,  1297,
    1298,  1299, -1877,  1300,  1301,  1302, -1877, 11721, 16013,  9505,
    1039,  9505, 13931, -1877, -1877,  1304, 14856, 14856, 14856, 14856,
   14856, 14856, 14856, 14856, 14856, 14856, 14856,  8467, 14856, 14856,
   14856, 14856,   631,   395, 14856, 14856, 14856,  8708,  8949,  9195,
    4664,  1062,  1061,    93,  9505,  9441,  9777,   395, 10114,   395,
    1057,  1058,  1059,   -37,  9505, 11721, 11721, 16913, -1877,   395,
    1064, 13960, 13989, -1877, -1877,  1063,  -123,   395,  -139,  1072,
     417,   415,  1316, -1877,  1269,   395,  1074,  1071,  5068,  5261,
    1320,  1478,   728,   728,   512,   512,   512,   512,   512,   512,
     380,   380,  9505,   428, -1877,   428,   428,   954,   954,   954,
    1073, 16038, 14937,   101,   519,  9505, -1877,  1321,  1077,  1078,
   16063, 16088, 16113, 11721,  7055,  1328,  1329, 10174, 14018, 16138,
   -1877,   445,   464,  9505,  1080, -1877, 11960, -1877, 12028, 12096,
       1, 11721, 11721, -1877, -1877,  1084,  1085, 10415,  5481,  1202,
     471,     1, 12164, 16163, 14047, 16188, 16213, 16238, 16263, 16288,
   16313, 16338,  1089,  1335, 11721,  1337, -1877, 11721, 16363, -1877,
   14964, 12232, 14991, -1877,   540,   554,   561, 14076, -1877, 15018,
   15045, 10364, -1877, -1877,  1339,  1341,  1342,  1090, 11721, 12300,
   11721, 11721, -1877, -1877,    49,   166,   358,   166,  1101,  1102,
    1095,   395,   395,  1096, 10446,   395,   395,   395,   395, 11721,
     395,  1345, -1877,  1098,  1107,   462,  -107,  1106,   562, -1877,
   -1877, -1877, -1877, 14856,   428, 12368,  1105,   604,  1104,  1175,
    1355,  1206, 10827,  1112,  1114,  1361,  7055, 14105, -1877, 11721,
    1362,   214,    73, 13228, 11721,  1363,  1366,    21, -1877,   563,
    1325,  1326,  7055, 14134,    34,  1119, 16388, 15072,   470, 11721,
   11721,  1126,  1123,  1129,  1127,  8531, -1877, -1877, -1877, -1877,
   13051,    55,  1124, 16413, 15099, -1877,  1133, -1877,   238, 10694,
   -1877, -1877, -1877,  1128, -1877,  1136, 10769, -1877,    71, -1877,
   -1877, 16913, -1877,  1379, 14856, 11721, 11721, 11721, 11721,   395,
       1,  7055,  7055,  1378,  7055,  7055,  7055,  1380,  7055,  7055,
    7055,  7055,  7055,  7055,  7055,  7055,  7055,  7055,  1256,  1382,
    9505,  4664, -1877, -1877, -1877, -1877, -1877, -1877, -1877, -1877,
   -1877, -1877, -1877, -1877, -1877, -1877, 11721, -1877, -1877, -1877,
   -1877, -1877, -1877, -1877, -1877, -1877, 11721, 11721, 11721, -1877,
   -1877, -1877,   569, 11721, 11721, -1877, 11721, -1877,  7055, 13051,
   13051, -1877,   570, 14163, 14192,  1138, -1877, -1877, -1877,  1200,
   11721, 11721, -1877, -1877, -1877,  1269, -1877,  1269, 11721, 11721,
    1145, -1877,  7055,    81, -1877, 11721, -1877, 11721, 11721,   571,
    1269,   101,   -86, -1877, 11721, 11721,   395,   579,  7055,  9505,
    9505,  1389,  1390,  1391,  3896, -1877, -1877,  1393, -1877,  1152,
   16913,  1143, -1877,  1395,  1396,  1397,   585,  1402, -1877, 12436,
   -1877, -1877,  -120, 11024, 11099, -1877, -1877, 14221,  -104,  1311,
    1423, 11068,  1177,  1422,  1184,    26,    43,   -69, -1877,  -112,
   -1877,   471,  1426,  1431,  1433,  1434,  1436,  1437,  1438,  1439,
    1442,   456,  7055, 16913, -1877,  1284,  1198,  1432, -1877,  1445,
    1446,  1350,  1447, -1877,  1449,  1450, 11721,  7055,  7055,  7055,
    1454, 11347, -1877,  5515,   708,    50,  1455, -1877,  9505, -1877,
   -1877, -1877, -1877, 13051, -1877, -1877, 11721, 13051, -1877, -1877,
   -1877, -1877, 16913, -1877,  1205,  1204, 13051, -1877, 13051, -1877,
    1269, 13051,  1213, -1877,  1207, -1877,  1269, 11721, 11721,  1211,
     422,  1214, 11157, -1877,  1581,  1215,  7055, -1877,  1212, -1877,
   14250, -1877, -1877, 11721,  1463,    44, 11721,  1464,  1465,  1642,
   -1877,  1466,    20,  1468,  1222,   395,    81,    81,  1469, -1877,
   -1877,  1231,  1252,  1225, -1877,  1472, -1877, -1877, -1877, -1877,
   -1877,  1269,   198,  3469, 11721, 15126, 16438, 11721,  8772, 11721,
    9505,  1249,   586,  1498,   142,  1269, -1877,  1251, 11721,  1500,
   11721,  1269, 11398, 11721,  9746,   395,  4969,  1277,  1275, -1877,
    1502, 16463, 16488, 16513, 16538,  1521,    99,  1399,  1399,  7055,
    1524,  1527,  1529,  7055,   -95,  1530,  1531,  1532,  1533,  1536,
    1537,  1538,  1539,  1557, -1877,  1560,   592, 14856, 14856, 14856,
   14856,   395, 11429, 12506, 13109,  1317,   395,   395, -1877, -1877,
   -1877,  1379,   395, 16563, 14856,  1319,   302, 16913, 14856, -1877,
    1563,   395, 13165, 16913, 16913, -1877,   626, -1877,  1566, -1877,
   16588, 15153, -1877,   395,  1568,   593,   622,  7055,  7055,  7055,
    1572,  1571, -1877,   261, 11721,  7055,  1327,  1330,  1565,   909,
   -1877, 11721, 11721, 11721,  1338,  1340,  1343,  1331, -1877,  1757,
    7055, -1877, 11721, -1877,  1574, -1877,  1585, -1877, -1877, 10415,
       9,  6317, -1877,  1344,  1347,  1348,  1349,  1351,  1352,  9013,
    1353,  1587, -1877,  9505, -1877, -1877, -1877,  1356, 11721, -1877,
   -1877, 15180,  1588,  1591,  1420, -1877, 11721, 11721, 11721, -1877,
    1599,  1601,  1603,  1037,   509,  1354,  2960,  1357, 11721,    24,
     395,  1367,   395,  1358, -1877, -1877, 13228,   635, 11721,  1365,
   -1877, -1877,  1857, -1877, -1877,  1364,  1604, -1877,  1914, -1877,
     249,  1368,  1611,  2114, -1877, -1877, -1877,    20, -1877,   624,
   -1877, 11721,   261,  4666, 11768, -1877,  1371, 11721, 11721,  7055,
    1372, -1877,   520,  1616,  1617, 16613,  1619,  1316, 16638,  1374,
     633, 16663,   640,  1622,  1623, -1877, -1877, 13051,  1383,  1626,
   16688, -1877, 13285,  1384, -1877, 14279,  5316, 16913, -1877,  1628,
      81,  7547, -1877, -1877, -1877, -1877,  1379, -1877,  1630,  1631,
    1632,  1633, -1877, -1877,     1,  1634,  1636,  1637, -1877, -1877,
   -1877,  1507,   -28,  1545,  1641, -1877, -1877, -1877, -1877, -1877,
   -1877, -1877, -1877, -1877,  1644,  1404, -1877, -1877, -1877, -1877,
   -1877, 11721, 11721, 11721, -1877, -1877, -1877,  1275, -1877, -1877,
   -1877, -1877, 11721,  1408,  1394, -1877, -1877, 11721, 11721, 11721,
     395,   101, -1877, -1877, -1877, -1877,  1406,  1407,  1654,   -95,
    1655, 11721, -1877,  7055, 16913,   948,  9505,  9505, 11721, -1877,
   10174, 14308, 16713,  5763,   456,   456, 11721, 11721, -1877,   163,
    1405, 16738, -1877, -1877, 14337,   -96, -1877,  1657,  1660,  7055,
       1,     1,     1,     1,     1,  6563,  1662, -1877, -1877,   641,
   11721,  2540,  1663, -1877, -1877,  7055,  6007,   549, 16763, -1877,
   -1877, -1877, -1877,  9837, -1877, 13051, 11721, -1877, 13051, 16913,
   10083, 13228,  1413, -1877, -1877, -1877, -1877,  1424,  1414, 11721,
   11721, 14366, 11721, 13351, -1877, 13351,  7055, -1877, -1877, 13228,
   11721,  1666,  1670,    21, -1877,  1669, -1877,    20, 15207,  7055,
   13051,  1671,   395, -1877,  1421,   395, 11721, 13378, 13411,   643,
   -1877, 11721, 11721,   463, -1877,  1427, -1877,  1391,  1674,  1675,
    1395,  1677, -1877, -1877,  1678, 11721, -1877, -1877, 11721, 11480,
    1679, -1877, -1877,  1435, 11768,   648,  3420,  1681, -1877, -1877,
   -1877, -1877, -1877,   809, -1877, -1877, -1877,  1548,  1680,  1441,
    1443,  1444, -1877,  1685,  7055, 14856, 14856, 13444, 14856, -1877,
    1448, 13477, 16788, 15234, -1877, -1877,  9505,  9505, -1877,  1688,
   -1877, 16913,  1692,  1451, -1877,   650,   651, 14828,  2686,  1693,
    1452, -1877, -1877, 11721,  1471,  1473, 14395, 15261,  1694,  7055,
    1684,  1470, 11721, -1877, -1877,   653,   -74,   -70,   -56,    -6,
      -2,  9259,   150, -1877,  1695, 14424, -1877, -1877,  1540, -1877,
   11721, 11721, -1877, -1877,  9505,  2733,  1721,  1479, 14856,   395,
   16913, -1877, -1877, -1877, -1877,    24, -1877, 13228, -1877, 14453,
    1476,  1480,  1482,  1725,  2872, -1877,  1731,  1726, -1877, -1877,
    1485,  1734,   656, -1877,  1735,  1736,   339, 16913, 11721, 11721,
    1491,  7055,   664, 16913, 16813, -1877, -1877, -1877, -1877, 16838,
   13510, -1877, -1877,  1138,  1204,  7055,   395, -1877, 11721, 13228,
      22, -1877, -1877,  9505,  9505, 11721,  1738,   665, -1877, -1877,
   11721,  1394, -1877, 11721, -1877, -1877,   666,   672, -1877, -1877,
    7055,   652,   662,  9505, -1877, -1877,   456,  6253, -1877, -1877,
   -1877,  1739, -1877,  1493,  7055, -1877, 14482,  1741,  9505,     1,
       1,     1,     1,     1, -1877, -1877, 11721, 14511, 14540,   673,
   -1877, -1877, -1877, -1877, -1877, -1877,  1503,  1743,  1499, -1877,
    1748, -1877, -1877,    20, -1877,  1573, -1877, -1877, -1877, -1877,
   -1877, 11721, 13543, 13576,  7055, -1877,  1749, 11721,  1504, -1877,
   11721,  1505,  1506, -1877, -1877,  3108, -1877,  1512,   719,   739,
   14569, -1877,  1509, 13609,  1513, 13642, -1877,  1514,   744,  1515,
       1,  7055,  1758,  1516,     1,  1759,   745,  1519, -1877, 11721,
   -1877,  1763,  1638, 12504,  1522, -1877,   747,   210,   218,   220,
     243,   252,  3063, -1877, -1877,  1770,  1771, -1877, -1877, -1877,
    1772, -1877,  1528, 16913, 11721, 11721,   752, -1877, 16913, 13675,
   -1877, -1877,  1138, 13228,  1534, -1877, -1877, -1877, 11721, 11721,
   -1877, 11721,  9505,  1773,     1,   103, -1877, -1877,     1,   114,
   -1877,  1775, -1877, 14598, -1877, 11721, -1877,   471, -1877,  1776,
    9505,  9505,  9505,  9505,  9259, -1877, -1877, -1877, 13351, -1877,
   11721, 16863, 13708,    47, 11721,  1541, -1877, -1877, 13741, 13774,
   13807,   754, -1877,   284, -1877,   329, -1877, -1877, -1877,  3252,
     399, 12572, -1877,   755,   757,   760,   762,   335,   767,  1542,
     768, -1877, 11721, -1877,  7055, 14627, -1877, 11721, 11721, 11721,
   -1877,     1,     1, -1877, -1877, -1877,   471,  1778,  1779,  1780,
    1781,  9505,  1783,  1786,  1787,  1544, 16888,   769,  1791, 14656,
   14856, 13840,   346,   375,   494, -1877, -1877, -1877, -1877,   774,
   -1877, -1877, -1877, 13051, -1877,  1546, -1877,  1793, -1877, 11721,
   11721, 11721, -1877,  1794,   775, -1877,  1549,  7055, -1877, 14685,
   14714, 14743, -1877,  1796, 13051, 13051,   776, -1877,  1799,  1818,
   -1877, -1877,   783, -1877,  1819, -1877, -1877,  1821, 13051, -1877,
   -1877, -1877
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,     0,
       0,   194,     0,     0,   195,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,   325,   326,   327,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,     0,     0,
     293,   294,     0,     0,     0,   288,     0,     0,     0,     0,
       0,   376,   377,   378,     0,     0,     5,     6,     7,     8,
      10,     0,    11,    24,    12,    13,    14,    15,    23,    22,
      21,    16,     0,    17,    18,    19,    20,     0,    25,     0,
     615,     0,   220,     0,     0,     0,     0,     0,   269,     0,
     271,   272,   267,   268,     0,   273,   275,     0,   276,   277,
     113,   123,   614,   489,   484,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,     0,   205,   206,   207,
       0,     0,     0,     0,   430,   431,   433,   434,   432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   438,   439,   440,     0,     0,
     193,   198,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   435,   436,   437,     0,     0,
       0,     0,     0,     0,     0,     0,   526,   527,     0,   528,
     502,   383,   443,   446,   307,   503,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     191,   198,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
       0,     0,   220,     0,     0,   373,     0,     0,     0,   202,
     203,     0,     0,     0,     0,     0,   510,     0,     0,   508,
       0,     0,     0,     0,     0,   614,     0,     0,   549,     0,
       0,     0,     0,   265,   266,     0,   566,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     568,     0,   592,   570,   571,     0,     0,     0,     0,     0,
       0,   569,     0,     0,     0,     0,   286,   287,     0,   220,
       0,   220,     0,     0,     0,   484,     0,     0,     0,   220,
     379,     0,     0,    76,     0,    63,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,     0,     0,   555,   484,     0,   219,     0,   218,     0,
     172,     0,     0,   555,   556,     0,     0,   604,     0,   605,
     556,     0,   111,   111,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   543,   544,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   517,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   386,     0,   385,   511,   387,
       0,   504,     0,     0,   484,     0,   519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,   460,     0,     0,     0,     0,     0,     0,     0,
     308,     0,   341,   341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,     0,   220,   220,     0,   493,   492,
       0,     0,     0,     0,   220,   220,     0,     0,     0,     0,
     304,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   343,     0,     0,     0,     0,     0,
     220,   246,     0,     0,   244,   374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   351,   264,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   289,     0,   251,     0,     0,   253,     0,     0,     0,
     385,     0,   220,     0,     0,     0,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    72,    73,     0,     0,     0,   262,
      38,   258,     0,     0,     0,     0,     0,   215,     0,     0,
       0,     0,     0,   221,     0,     0,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,   487,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   335,     0,     0,     0,   197,     0,     0,     0,
       0,     0,     0,   369,   370,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,   459,     0,
       0,     0,     0,   520,   521,     0,     0,     0,     0,     0,
     478,     0,   384,   505,     0,     0,     0,     0,   513,     0,
     403,   402,   400,   401,   396,   398,   397,   399,   405,   404,
     389,   388,     0,   390,   512,   391,   394,   392,   393,   395,
     485,     0,     0,   486,   463,     0,   529,     0,     0,     0,
       0,     0,     0,     0,     0,   339,     0,     0,     0,     0,
     372,     0,     0,     0,     0,   371,     0,   220,     0,     0,
       0,     0,     0,   495,   494,     0,     0,     0,     0,     0,
       0,     0,   298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   358,     0,     0,   245,
       0,     0,     0,   239,     0,     0,     0,     0,   368,     0,
       0,     0,   384,   509,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   595,     0,     0,     0,   480,     0,     0,   250,
     254,   252,   256,     0,   390,     0,   485,   463,   616,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,   384,     0,    63,     0,     0,     0,     0,    79,     0,
      63,    64,     0,     0,     0,   485,     0,     0,   463,     0,
       0,     0,   191,     0,     0,     0,   611,    28,    26,    27,
       0,     0,     0,     0,     0,   486,   559,    29,     0,     0,
     259,   606,   607,     0,   608,   559,     0,    74,   114,    75,
     124,   488,   490,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   545,   546,   208,     9,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   429,   416,     0,   418,   419,   420,
     421,   422,   542,   423,   424,   425,     0,     0,     0,   534,
     533,   532,     0,     0,     0,   539,     0,   475,     0,     0,
       0,   477,     0,     0,     0,   128,   458,   516,   515,   201,
       0,     0,   444,   541,   449,     0,   455,     0,     0,     0,
       0,   506,     0,     0,   456,     0,   518,     0,     0,     0,
       0,   448,   447,   470,    70,    71,     0,     0,     0,     0,
       0,     0,     0,   384,   337,   342,   340,     0,   350,     0,
     148,   149,   201,   384,     0,     0,     0,     0,   240,     0,
     255,   257,     0,     0,     0,   209,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   311,     0,
     295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,   344,   357,     0,     0,     0,   241,     0,
       0,     0,     0,   204,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,     0,     0,     0,   582,     0,   589,
     578,   579,   580,     0,   594,   593,     0,     0,   583,   584,
     585,   591,   598,   597,     0,   139,     0,   572,     0,   574,
       0,     0,     0,   567,     0,   249,     0,     0,     0,     0,
       0,     0,     0,   330,     0,     0,     0,   380,     0,   612,
       0,   101,    63,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,   564,
      48,     0,     0,     0,    61,     0,    39,    40,    41,    42,
      43,     0,   448,   447,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   558,   557,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,   155,   155,     0,
       0,     0,     0,     0,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,   524,
     525,     0,     0,     0,     0,     0,   478,   479,     0,   451,
       0,     0,     0,   514,   406,   507,   464,   462,     0,   461,
       0,     0,   530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,     0,     0,     0,   316,     0,
       0,   315,     0,   318,     0,   320,     0,   305,   312,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   359,     0,   243,   242,   375,     0,     0,    35,
      36,     0,     0,     0,     0,   550,     0,     0,     0,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,   481,   576,     0,   464,     0,     0,
     220,   331,     0,   332,   220,     0,     0,   565,     0,    86,
       0,     0,     0,     0,    84,    91,    93,     0,   553,     0,
      99,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    34,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    31,     0,   560,     0,
       0,    32,     0,   560,   609,     0,     0,   115,   120,     0,
       0,     0,   134,   137,   138,   483,     0,    77,     0,     0,
       0,     0,    78,   159,     0,     0,     0,     0,   160,   175,
     176,   157,     0,     0,     0,   161,   186,   177,   181,   182,
     178,   179,   180,   167,     0,     0,   417,   426,   427,   428,
     535,     0,     0,     0,   473,   474,   476,   129,   442,   472,
     445,   450,     0,     0,   478,   187,   457,     0,    70,    71,
       0,   469,   465,   467,   536,   183,     0,     0,     0,   151,
       0,     0,   348,     0,   150,     0,     0,     0,     0,   263,
       0,     0,     0,     0,   220,   220,     0,     0,   317,   502,
       0,     0,   319,   321,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   184,     0,
       0,     0,     0,   164,   165,     0,     0,     0,     0,   102,
     103,   104,   108,     0,   590,     0,     0,   588,     0,   599,
       0,     0,   140,   141,   596,   573,   575,     0,     0,     0,
       0,     0,     0,   329,   333,   329,     0,   381,    85,    63,
       0,     0,     0,     0,    83,     0,   551,     0,     0,     0,
       0,     0,     0,   602,   601,     0,     0,     0,     0,     0,
     500,     0,     0,   469,   260,   465,   261,     0,     0,     0,
       0,     0,   225,   222,     0,     0,   563,   561,     0,     0,
       0,   116,   121,     0,     0,     0,   543,   544,   133,   352,
     353,   354,   355,   156,   162,   163,   168,     0,     0,     0,
       0,     0,   170,     0,     0,     0,     0,     0,     0,   452,
       0,     0,     0,     0,   531,   471,     0,     0,   169,     0,
     188,   338,     0,     0,   189,     0,     0,     0,     0,     0,
       0,   499,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   236,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,   356,    37,     0,   548,
       0,     0,   283,   282,     0,     0,     0,     0,     0,     0,
     143,   144,   147,   146,   145,     0,   577,     0,   613,     0,
       0,     0,     0,     0,     0,    96,     0,     0,    97,   554,
       0,     0,     0,    88,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    46,     0,   226,   223,   224,    33,     0,
       0,   610,   274,   128,   139,     0,     0,   136,     0,     0,
       0,   158,   185,     0,     0,     0,     0,     0,   537,   538,
       0,   478,   453,     0,   466,   468,     0,     0,   171,   192,
       0,   345,   345,     0,   109,   110,   220,     0,   212,   213,
     306,     0,   313,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,   217,   216,     0,     0,     0,     0,
     105,   106,   581,   587,   586,   142,     0,     0,     0,   334,
       0,    92,    94,     0,   100,     0,    82,   603,    89,    90,
      49,     0,     0,     0,     0,   501,     0,     0,   466,   562,
       0,     0,     0,   118,   600,     0,   125,     0,     0,     0,
       0,   174,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   497,     0,
     323,     0,     0,   300,     0,   228,     0,     0,     0,     0,
       0,     0,     0,   547,   284,     0,     0,   367,   220,   382,
       0,   552,     0,    45,     0,     0,     0,    62,    47,     0,
     117,   122,   128,     0,     0,   153,   154,   152,     0,     0,
     454,     0,     0,     0,     0,     0,   346,   360,     0,     0,
     361,     0,   210,     0,   314,     0,   296,     0,   220,     0,
       0,     0,     0,     0,     0,   166,   107,   280,   329,    98,
       0,     0,     0,     0,     0,     0,   126,   127,     0,     0,
       0,     0,   190,     0,   364,     0,   365,   366,   496,     0,
       0,   302,   231,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    59,     0,     0,   119,     0,     0,     0,
     310,     0,     0,   322,   301,   297,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,   233,   234,   235,     0,
     229,   336,    50,     0,    57,     0,   270,     0,   540,     0,
       0,     0,   303,     0,     0,    51,     0,     0,   279,     0,
       0,     0,   230,     0,     0,     0,     0,   522,     0,     0,
      54,    52,     0,    55,     0,   362,   363,     0,     0,    60,
      58,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1877, -1877, -1877, -1877,   475, -1877, -1877, -1877, -1877,  -260,
   -1877, -1877, -1877, -1877, -1877, -1877, -1877, -1877, -1877, -1877,
   -1877, -1877,  -717,  -140,  4407,  3424, -1877,  1370, -1877, -1877,
   -1877, -1877, -1877, -1877, -1876, -1877,   420,   250,   -67, -1877,
     -31, -1877,   186,   461, -1877,  1837, -1877,   298,   -39, -1877,
   -1877,     0,  -611,  -290, -1877, -1877, -1877, -1877, -1877, -1877,
   -1877, -1877,  1840, -1877, -1877, -1877, -1877, -1222, -1223,  1841,
   -1707,  1842, -1877, -1877, -1877,  1243, -1877,   -85, -1877, -1877,
   -1877, -1877,  2096, -1877, -1877, -1410,   337,  1845, -1877,     6,
    -699, -1877, -1877,   176, -1877, -1671,   859,  -182,  2621,  2512,
    -306,   116, -1877,    45,   -77, -1877, -1877,   143,   308, -1670,
    -152,  1087, -1877,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   116,  1060,   117,   118,  1044,  1886,  1892,
    1336,  1546,  2042,  2174,  1337,  2145,  2192,  1338,  2176,  1339,
    1340,  1550,   437,   592,   593,  1131,   119,   774,   462,  1903,
    2052,  1904,   463,  1775,  1412,  1367,  1368,  1369,  1510,  1712,
    1713,  1199,  1604,  1595,  1788,   753,   604,   274,   275,   352,
     201,   276,   447,   448,   123,   124,   125,   126,   127,   128,
     129,   130,   277,  1231,  2077,  2136,   940,  1227,  1228,   278,
    1023,   279,   134,  1441,  1197,   915,   955,  2012,   135,   136,
     137,   138,   280,   281,  1155,  1170,  1292,   282,   779,   283,
     904,   778,   465,   619,   320,  1749,   359,   360,   285,   562,
     367,  1323,  1539,   457,   453,  1285,  1000,  1584,  1742,  1743,
     985,   459,   140,   415
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     141,   438,   458,   122,  1468,   614,  1633,   162,  1835,  1470,
     408,   493,  1034,   935,   936,   648,  1870,  1017,  1871,   500,
    1042,   164,   305,   339,   365,   162,   162,  1991,  1710,   403,
     163,   407,  1463,   630,   162,   420,   410,   729,  1330,   742,
    1863,   543,  1602,   344,     4,   345,  1048,   148,  1530,  1465,
     286,   566,   653,  2123,  1500,   145,  1265,   310,   291,   349,
     162,   291,   350,  1066,   443,   176,   180,   369,  1220,  1789,
     418,  1075,   622,   623,   419,   351,   622,   623,  1364,   343,
    1312,   292,   311,   759,  1051,   142,  1221,   286,  1790,   143,
     467,  1603,   368,   930,  1222,  1223,  1224,   937,   312,   313,
    1225,  1226,   588,   404,  1906,  1593,   622,   623,   340,  2104,
    1164,   601,   602,   603,   757,  1165,   622,   623,   588,   705,
    2106,   708,   758,  1917,   622,   623,   734,   941,   735,   720,
     768,   713,   622,   623,  1161,  1057,   346,  1451,   444,   466,
     622,   623,   446,   454,   454,  1469,  1220,  1290,  1566,  1455,
    1291,   460,   763,   644,   645,   646,  1501,  1502,   432,   433,
     764,  1832,   622,   623,  1221,     5,   622,   623,  1428,   472,
     660,   568,  1222,  1223,  1224,  1173,  2095,   146,  1225,  1226,
     622,   623,   144,  1948,  1467,   454,   442,  1949,   766,   772,
     286,   452,   455,   286,   147,   773,   767,  1464,   286,   286,
     454,  1950,   622,   623,   539,   540,   150,  1331,  1332,  1333,
    1334,  1033,  1151,   341,  1466,  1040,   730,   731,   624,   775,
     767,  1312,  1711,   115,  1800,   773,   306,  1531,  1532,   307,
     622,   623,   633,   488,   622,   623,   634,   315,   316,   115,
     115,   115,   115,   319,   321,   151,   324,  1468,   502,   317,
     115,  1951,   286,   318,   152,  1952,  1729,   409,   999,  2008,
     810,   649,  1676,   650,   811,   153,   286,   143,  1312,   286,
     564,   342,   366,  1322,   432,   433,   115,   421,   743,   563,
     744,   422,  -556,   411,   745,   286,   286,  1335,   544,   286,
     286,   286,   286,   149,   428,   429,   430,   431,   567,  2124,
     154,   121,   286,  1266,  1354,   734,   286,   735,   368,   177,
     181,   370,   811,  2046,  1313,  1316,   155,   432,   433,   165,
     156,   166,   760,   926,   761,   928,   929,  1315,   762,   165,
     286,   166,   286,   286,   286,   622,   623,   432,   433,   622,
     623,   589,   942,   590,  1141,   432,   433,   591,   724,   286,
     622,   623,   157,   432,   433,   286,   158,   589,   300,   590,
     961,  1058,   159,   591,  1059,   863,   432,   433,   160,   769,
     714,   761,   715,   161,  1058,   770,   716,  1059,   165,   293,
     166,  2119,   294,   979,   295,   853,   622,   623,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   173,  1953,   315,   316,
     587,   325,   174,   454,   286,   734,  1828,   735,   286,   286,
     317,   175,  1015,   767,   323,   428,   429,   430,   431,  1041,
     429,   430,   431,   178,   286,   428,   429,   430,   431,   440,
     179,   746,   432,   433,   440,   440,   622,   623,   432,   433,
    -558,   182,   440,  2147,   622,   623,   622,   623,   432,   433,
     445,   717,   335,   780,   336,   873,  1415,  2080,  1416,   811,
     428,   429,   430,   431,   908,  2081,   869,  2082,   811,   622,
     623,  1426,   428,   429,   430,   431,   440,  1359,   622,   623,
     617,   618,   286,   432,   433,   811,   622,   623,   626,   631,
    2083,   440,   183,   526,   326,   527,  2186,   197,   327,  2084,
     198,  2004,   625,   199,   328,   329,   286,   330,   331,   296,
     622,   623,   297,   286,   843,   298,   200,   299,   454,   987,
     454,   286,   454,   454,   460,   184,  1220,   332,    45,   859,
     538,  2131,   185,   286,   286,   286,   454,   454,   286,   164,
     165,   164,   166,   286,  1221,   547,   548,  1851,   868,  1168,
     870,   186,  1222,  1223,  1224,   622,   623,   187,  1225,  1226,
     188,   622,   623,   909,   622,   623,   847,   811,   849,   286,
     851,   852,   622,   623,   189,   900,  2132,   193,  1980,  1035,
     632,  1513,  2141,   190,   865,   866,  1981,  1517,    66,    67,
      68,    69,   191,  2170,    72,   286,   286,   734,  1220,   735,
     952,   622,   623,    81,   811,  1268,    84,  1002,   711,   583,
     584,   585,   586,   192,   446,   446,  1221,   587,   194,  1019,
    1480,  1220,  2171,   811,  1222,  1223,  1224,  1209,   195,   568,
    1225,  1226,  1552,  1025,   734,   301,   735,  1026,   302,  1221,
     303,   202,  2134,   286,   286,   286,  1568,  1222,  1223,  1224,
     196,   304,  1573,  1225,  1226,   165,   203,   166,  1171,   585,
     586,  1167,   811,   287,  1168,   587,   460,   454,   460,   454,
     454,   454,   454,   454,   454,   288,   454,   454,   454,   454,
    1001,   289,   454,   454,   454,   164,  1007,   168,  1204,   286,
     169,   290,   811,   170,  1006,   171,   308,   432,   433,  1089,
    1016,   734,  1053,   735,   440,  -563,  1498,  1205,  1344,  1288,
    1298,   811,  -559,   286,   725,   986,  1653,   988,   989,   990,
     991,   992,   993,   286,   995,   996,   997,   998,   309,  1045,
    1003,  1004,  1005,   671,   314,   143,   754,  2172,   580,   581,
     711,   583,   584,   585,   586,   286,  1062,   322,   734,   587,
     735,   286,   333,  1183,   460,  1073,   811,  1184,  1752,  1185,
    1720,  1078,  -560,   454,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,   334,  1250,  2009,  2010,   587,   811,   933,   934,
    2011,   337,  1852,   618,  2013,  2014,   286,  1251,   286,   338,
    2011,   811,  1071,  1730,  1252,  1294,  1325,   347,   811,   811,
     811,  1080,  1401,  1408,  1425,  1739,   811,   811,   811,   440,
     348,   440,  1433,   440,   440,   440,   811,   353,  1448,  1564,
    1201,   286,   811,   811,   354,  1615,  1646,   440,   440,   811,
     811,   286,  1297,   355,  1298,  2110,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   809,
     583,   584,   585,   586,  1638,  1647,  1639,  1736,   587,   811,
     734,  1737,   735,  1719,   361,  1720,  1759,  1468,   373,   286,
     811,  1314,  1317,  1761,  1844,   362,  1890,   811,   811,   739,
    1891,  1907,   286,  1931,  1932,  1908,  1947,   811,   811,  1977,
    1891,   286,   284,   767,  2154,  1659,  1660,  1986,  2002,  2006,
     286,  1987,  1891,   811,   363,  2007,  2035,   364,   754,   811,
     811,  1468,   371,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,   754,  1813,   372,  1814,   587,  1318,  1499,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,   734,  2055,   735,   736,   587,   811,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   374,   440,   440,   440,
     440,   375,  2056,   440,   440,   440,   811,  2063,  2071,   405,
    2079,  1891,   811,   754,   811,  2093,   754,  2130,  2137,  1891,
    2138,   811,   811,  2139,   811,  2140,  1538,   811,   754,   811,
    2142,  2144,  2165,   286,   811,  1987,  1891,  2173,  2183,  2194,
     416,   811,  2184,  1891,  1324,   734,  2197,   735,   905,   286,
    2198,  1427,  1429,  1702,  1703,   622,   623,   417,  1052,   423,
    1054,   450,   286,  1824,  1825,   424,   449,   454,   143,   464,
     466,   501,   468,   469,   470,   440,   471,   476,   480,   494,
     534,  -194,   537,  -195,   440,   499,  -196,   545,   546,   549,
     552,   565,   553,   554,   597,   598,   611,   635,   286,   286,
     419,   286,   286,   286,   605,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,  1353,  1212,   286,   608,   613,
     615,   636,   616,  1218,   284,   637,   638,  1229,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,   639,   640,   651,   641,
     587,   654,   647,   655,   656,   286,   454,   454,   652,   657,
     666,   600,   658,   659,   661,   662,   663,   667,   674,   673,
     682,   683,   684,   695,   607,   696,   698,   700,   612,   286,
     699,   701,   703,   702,   706,   704,   723,   707,   726,   733,
     738,   740,   741,   142,   777,   286,   286,   286,   747,   756,
     781,   786,   802,   807,  1406,  1407,   813,   814,   815,   844,
     874,   587,  1427,  1429,   876,   854,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,   754,   855,   754,   754,   587,   856,
    1723,  1735,   877,   903,  1725,   913,   917,   914,   765,   286,
     754,   446,   920,   924,   925,   927,   954,   956,   973,   957,
     959,   968,   977,   980,   286,   286,   286,  1009,  1011,   754,
    1018,  1024,  1394,  1028,  1036,   286,  1376,  1029,  1037,  1038,
     454,  1049,  1050,  1065,   454,  1055,  1067,   754,  1070,  1077,
     721,   722,  1079,   454,  1082,   454,  1083,  1578,   454,  1583,
    1482,  1110,  1090,  1091,  1092,  1094,   732,  1095,  1096,  1098,
    1099,  1100,  1101,   286,  1102,  1103,  1104,  1105,  1106,  1107,
    1114,  1139,  1140,   754,  1148,  1149,  1150,  1157,  1505,   368,
    1160,  1166,  1507,  1172,  1176,  2017,  1175,  1180,  1188,  1189,
    1190,  1511,  1196,  1512,  1207,  1198,  1514,  1215,  1216,  1219,
     454,  1241,  1242,  1244,  1260,   286,  1257,   286,  1258,  1259,
    1271,  1272,  1273,  1276,  1284,  1286,  1287,  1293,   440,  1296,
    1299,  1300,  1301,   286,  1302,  1305,  1306,  1307,  1311,  1320,
    1321,  1326,  1327,  1341,  1347,  1348,   286,  1349,  1355,  1350,
     286,  1358,  1361,  1366,  1362,  1379,  -197,  1383,  1554,  1395,
    1731,  1744,  1744,   850,  1419,  1411,  1437,  1438,  1439,  1442,
    1444,  1443,  1445,  1446,  1447,   600,  1449,   864,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,  1456,  1457,  1461,  1460,
     587,  1879,  1462,  1471,   286,   286,   286,  1472,  1484,  1718,
    1473,  1474,   286,  1475,  1476,  1477,  1478,   440,   440,  1479,
    1483,  1485,  1486,  1487,  1488,  1489,  1490,   286,  1495,  1503,
    1508,  1509,  1515,  1518,  1516,  1526,  1520,  1524,   286,  1529,
    1534,  1535,  1541,  1537,  1540,  1545,   286,  1549,  1551,  1547,
     286,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,  1772,
    1548,  1805,  1563,   587,  1565,  1569,  1571,   754,  1587,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,  1592,  1585,  1594,
    1598,   587,  1586,  1599,   368,  1600,  1605,  1606,  1607,  1608,
     460,   460,  1609,  1610,  1611,  1612,   286,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,  1613,   454,  1614,  1624,   587,  1631,  1635,
    1641,   440,  1658,   286,  1645,   440,  1651,  1652,   286,  1656,
    1672,  1667,  1657,  1819,   440,  1030,   440,  1523,  1882,   440,
    1664,  1673,  1665,  1688,  1693,  1666,  1679,  1694,  1519,  1680,
    1681,  1682,  1695,  1683,  1684,  1699,  1687,  1700,  1690,  1701,
    1727,  1705,  1764,  1805,  1708,  1291,  1715,  1722,  1733,  1746,
    1753,  1726,  1732,  1754,  1751,  1756,  1856,  1758,  1762,  1763,
    1766,  1765,  1769,  1861,  1864,  1773,  1779,  1780,  1781,  1782,
    1784,   440,  1785,  1786,  1787,  1675,  1791,  1792,  1536,  1793,
     286,  1168,  1873,   286,   286,  2023,  1794,  1799,  1806,  1807,
    1808,  1810,  1829,  1833,   446,   446,  1834,  2040,  1843,  1847,
    1865,  1867,  1875,  1866,  1876,  1878,   286,  1883,   767,  -561,
    1895,  1896,   286,  1897,  1898,  1902,  1912,  1905,  1910,  1911,
    1916,  1944,   286,  1913,  1928,  1914,  1915,  1922,  1929,  1935,
    1942,  1954,   454,  1930,  1936,   454,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,  1956,  1945,   286,  1938,   587,  1939,  1961,  1962,  1968,
    1324,  1971,  1974,  1969,   368,  1970,   286,   460,  1973,  1975,
    1976,  1978,  1979,  1984,  2001,  2020,  2021,  2025,  2088,  2037,
    1857,  2038,  2036,  1859,  2039,  2047,  -562,  2041,  2050,  2051,
    2054,  2058,  2060,  1668,  2067,  2070,  2062,  2064,  2068,  2074,
    1783,   460,  2072,  1195,  2078,  2075,  2086,  2087,  2089,  2102,
    2090,  2107,  2112,  2097,  2155,  2156,  2157,  2158,  2111,  2160,
    1966,   286,  2161,  2162,  2126,  2143,  2163,  2166,  2177,  2178,
    2182,  2185,  2190,   286,   286,  2195,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,  2196,  2199,   286,  2200,   587,  1567,
    2120,  1627,  1996,   776,  1965,  1809,  1778,  1992,   286,  1596,
     120,   440,   440,   131,   132,   133,   916,  2015,   139,  1877,
    1717,   286,  1745,  1862,  1072,     0,  1836,  1837,  1838,  1839,
    1840,  1842,     0,  1724,     0,   440,     0,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,  1308,     0,     0,   286,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1328,   286,     0,     0,     0,     0,  1997,     0,     0,
     286,   286,     0,     0,     0,     0,     0,     0,     0,     0,
    1728,     0,     0,     0,     0,     0,     0,   286,     0,     0,
     286,     0,     0,     0,     0,     0,   446,     0,     0,     0,
       0,   286,     0,     0,     0,   286,     0,     0,     0,     0,
    1377,  1378,     0,  1380,  1381,  1382,     0,  1384,  1385,  1386,
    1387,  1388,  1389,  1390,  1391,  1392,  1393,     0,     0,     0,
     368,     0,     0,     0,     0,     0,  2096,     0,     0,     0,
       0,   286,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,   440,   587,     0,   440,  1405,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,   754,     0,     0,     0,     0,     0,     0,
       0,  1420,     0,     0,     0,     0,     0,     0,   440,     0,
       0,     0,     0,     0,     0,     0,     0,  1434,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   440,     0,     0,     0,     0,   286,   286,   286,
     286,   286,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,  1481,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1492,  1493,  1494,     0,
    1734,   286,     0,     0,     0,  2027,  2028,  2029,  2030,  2031,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
     454,   587,     0,     0,     0,  1525,     0,     0,     0,     0,
       0,     0,     0,     0,   286,     0,     0,     0,     0,     0,
       0,   454,   454,     0,     0,     0,  2065,     0,     0,     0,
    2069,     0,     0,     0,     0,   454,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2175,     0,
     414,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1582,     0,     0,     0,  2191,
    2193,     0,     0,     0,     0,     0,     0,   441,  1597,     0,
    2103,   451,  1601,  2201,  2105,   456,     0,     0,     0,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    2117,     0,     0,     0,     0,     0,     0,     0,     0,   473,
     474,   475,     0,   477,   478,   479,     0,   481,   482,   483,
     484,   485,   486,   487,     0,   489,   490,   491,   492,     0,
       0,     0,   496,     0,     0,     0,  1648,  1649,  1650,     0,
       0,     0,     0,     0,  1655,     0,     0,  2152,  2153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1670,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
    1678,     0,     0,     0,     0,     0,     0,     0,  1686,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,   555,   557,   559,   560,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   496,   496,   754,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   610,     0,     0,     0,     0,  1750,   754,
       0,     0,     0,   620,   621,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   496,
     643,     0,     0,     0,     0,  1771,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   664,   496,     0,     0,     0,   668,   669,
     670,   440,   672,     0,     0,     0,   675,   676,   677,     0,
       0,   678,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   440,   440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   710,
       0,     0,  1812,   496,   719,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     727,   728,     0,     0,     0,     0,     0,     0,  1750,     0,
       0,     0,     0,     0,     0,   755,  1846,     0,     0,     0,
       0,     0,     0,     0,  1848,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   782,   783,   784,   785,     0,     0,
       0,     0,   790,     0,     0,     0,   794,     0,     0,     0,
       0,     0,     0,     0,     0,  1872,     0,     0,     0,     0,
     808,   557,     0,     0,     0,   812,     0,     0,  1881,   816,
     817,   818,   819,   820,   821,   822,   823,   824,   825,   826,
     827,   828,   829,   830,   831,   832,   834,   835,   836,   837,
     838,   839,   840,   840,     0,   845,   846,     0,   848,     0,
       0,     0,     0,     0,     0,     0,     0,   857,     0,     0,
     861,   862,     0,     0,     0,     0,     0,   840,     0,     0,
       0,     0,   496,  1750,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   878,   879,   880,   881,   882,   883,
     884,   885,   886,   887,   888,   889,   890,   891,   893,   895,
     896,   897,   898,   899,     0,   901,   902,     0,  1943,     0,
       0,     0,  1934,   910,   911,   912,     0,     0,     0,     0,
       0,   918,   919,     0,   496,   496,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   555,   710,   938,     0,     0,     0,   943,
     944,   945,   946,   947,   948,   949,   950,   951,     0,  1960,
       0,     0,     0,   958,     0,   960,     0,     0,   962,     0,
    1985,     0,   496,   496,   496,   967,     0,   969,   970,   971,
       0,     0,     0,     0,  1993,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,   994,     0,     0,   587,     0,  1750,
       0,     0,     0,     0,     0,     0,     0,     0,   496,     0,
     595,   596,     0,  2022,     0,  1013,     0,  1014,     0,     0,
     901,   902,     0,     0,     0,     0,     0,   497,     0,  1027,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   496,     0,  1043,     0,     0,     0,     0,  1046,
    1047,     0,     0,  1750,     0,   642,     0,     0,     0,     0,
       0,     0,     0,     0,   496,     0,  1063,  1064,     0,     0,
     496,  1069,     0,     0,     0,  1063,     0,  1076,     0,     0,
    2066,     0,     0,  1081,     0,     0,     0,  1084,  1972,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1108,     0,   893,     0,  1111,     0,   497,
     497,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,   718,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,  1153,  1154,     0,   497,     0,     0,     0,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,   497,
     587,     0,     0,  1750,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,     0,     0,     0,     0,     0,     0,     0,  1194,
       0,     0,     0,  1200,     0,     0,     0,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,  1213,  1214,     0,
       0,     0,     0,  1217,     0,     0,  1750,     0,   497,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1243,     0,     0,  1245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   871,  2085,
       0,     0,     0,     0,  1261,     0,  1263,  1264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1282,     0,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,  2053,   558,     0,  1304,   587,
     921,   922,     0,     0,     0,  1310,     0,     0,     0,     0,
    1319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     833,     0,     0,     0,     0,  1345,  1346,   841,   842,     0,
       0,   496,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   964,   965,
     966,     0,   867,     0,     0,     0,     0,   497,     0,     0,
       0,  1371,  1372,  1373,  1374,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,   894,     0,     0,   496,   587,     0,   734,
       0,   735,     0,     0,  1008,     0,     0,  1706,     0,     0,
       0,     0,  1397,     0,     0,     0,     0,     0,     0,   497,
     497,     0,  1398,  1399,  1400,     0,     0,     0,     0,  1402,
    1403,     0,  1404,     0,     0,     0,     0,     0,  1039,     0,
       0,     0,     0,     0,     0,     0,  1413,  1414,  2133,     0,
       0,     0,     0,     0,  1417,  1418,     0,     0,     0,     0,
    1061,  1422,     0,  1423,  1424,     0,  1068,   497,   497,   497,
    1430,  1431,     0,     0,     0,   496,   496,     0,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,  1459,     0,     0,
       0,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,  1491,     0,     0,   587,  1142,   497,     0,     0,
       0,     0,     0,     0,   496,     0,  1152,     0,     0,     0,
       0,     0,  1506,     0,     0,     0,     0,     0,     0,   497,
       0,     0,     0,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,  1430,  1431,     0,     0,     0,  1522,     0,
       0,     0,     0,     0,  1179,     0,     0,     0,     0,  1528,
       0,     0,  1533,     0,     0,     0,     0,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1909,   568,     0,
     894,     0,  1112,     0,     0,  1206,     0,     0,     0,     0,
    1555,     0,     0,  1558,   496,  1561,   496,     0,     0,     0,
       0,     0,     0,     0,  1570,     0,  1572,     0,  1570,  1575,
    1577,     0,     0,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,   162,   376,   497,     0,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,   377,   378,   379,   380,   381,
     382,   383,   384,   385,     0,     0,   497,     0,   386,   387,
     388,   389,     0,     0,     0,     0,   390,   391,   392,     0,
    1654,     0,     0,   393,   497,   394,     0,  1661,  1662,  1663,
       0,     0,     0,     0,     0,     0,  1669,     0,  1671,   395,
       0,     0,   396,     0,     0,  1674,   296,  1352,     0,   297,
       0,     0,   298,     0,   299,     0,     0,     0,     0,   496,
       0,     0,     0,     0,  1691,    45,     0,     0,     0,     0,
       0,     0,  1696,  1697,  1698,     0,     0,     0,     0,     0,
       0,     0,   426,     0,  1709,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1721,     0,     0,     0,     0,     0,
       0,     0,  1396,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1738,     0,     0,
       0,     0,     0,  1747,  1748,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   809,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,   397,   398,   399,     0,     0,   497,  1776,     0,     0,
       0,     0,   400,     0,     0,     0,   401,     0,   402,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1435,  1436,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,   433,     0,     0,  1795,  1796,  1797,
       0,  -557,     0,  1553,     0,     0,     0,     0,  1798,     0,
       0,   497,     0,  1801,  1802,  1803,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1811,     0,     0,
       0,     0,   496,   496,  1817,     0,  1818,     0,     0,     0,
       0,     0,  1826,  1827,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1504,   496,     0,     0,     0,     0,  1845,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,  1855,
       0,     0,  1858,     0,     0,     0,  1860,     0,     0,     0,
     497,   497,     0,     0,     0,  1802,  1803,     0,  1869,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1887,     0,     0,     0,     0,  1893,  1894,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1560,  1899,  1562,   737,  1900,  1899,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,   497,
       0,    42,    43,    44,    45,     0,     0,    47,     0,     0,
       0,     0,   496,   496,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,  1937,
       0,     0,     0,     0,     0,     0,     0,     0,  1946,     0,
       0,     0,    78,     0,     0,     0,     0,   557,     0,     0,
       0,     0,     0,     0,     0,     0,  1957,  1958,     0,     0,
     496,     0,     0,     0,     0,     0,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   858,     0,     0,   497,
       0,   497,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,  1982,  1983,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1689,     0,     0,     0,     0,
       0,     0,     0,     0,  1995,     0,     0,     0,     0,   496,
     496,  2000,     0,     0,     0,     0,  2003,   906,     0,  2005,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   496,
       0,   939,     0,  1440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,     0,  2032,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,  2043,     0,    42,
      43,    44,    45,  2048,     0,    47,  2049,     0,     0,     0,
       0,     0,   748,    54,     0,     0,    57,   749,     0,   750,
     751,     0,   752,     0,   497,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2073,     0,     0,     0,     0,
      78,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
    2091,  2092,     0,   587,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,  2098,  2099,     0,  2100,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1815,  1816,
       0,  2109,     0,     0,     0,     0,   496,   496,   496,   496,
     496,     0,     0,     0,     0,     0,  1893,     0,     0,     0,
    2125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1777,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2146,   963,
       0,     0,     0,  2149,  2150,  2151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   496,     0,     0,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,     0,  1127,  1128,  1129,  1130,     0,  1132,  1133,  1134,
    1135,   568,     0,     0,     0,  2179,  2180,  2181,     0,     0,
       0,  1145,     0,  1147,     0,     0,     0,   497,   497,     0,
       0,     0,     0,  1156,     0,     0,     0,     0,     0,     0,
    1162,  1163,     0,     0,     0,     0,     0,     0,     0,  1174,
       0,     0,     0,     0,     0,     0,   497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   162,  1926,  1927,
       0,     0,     0,   205,   206,   207,     0,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   412,   226,   227,   228,   229,
     230,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1959,     0,   237,   238,
     239,   240,     0,     0,     0,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,     0,   249,     0,     0,     0,     0,  1267,
    1269,  1270,     0,     0,     0,  1274,  1275,     0,     0,  1278,
    1279,  1280,  1281,     0,  1283,  1998,  1999,   497,   497,  1289,
       0,     0,   167,     0,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2016,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2026,     0,   558,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,  1370,     0,
       0,     0,     0,  1375,   259,     0,     0,     0,   260,     0,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
       0,     0,     0,   115,   497,   497,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   439,   268,
     413,     0,     0,     0,   497,     0,   270,     0,     0,     0,
       0,   357,     0,     0,     0,   609,     0,     0,   273,   497,
       0,     0,     0,     0,  2101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2113,  2114,  2115,  2116,  2118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1432,     0,     0,     0,     0,     0,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   528,
     529,   530,   531,   532,   533,     0,   535,   536,     0,     0,
       0,     0,     0,  2159,     0,   541,   542,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,     0,
     162,   376,   568,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   497,   497,   497,   497,   497,     0,     0,     0,     0,
       0,     0,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   981,     0,     0,     0,   386,   387,   388,   389,     0,
       0,     0,     0,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   394,     0,     0,     0,     0,     0,     0,  1542,
       0,     0,     0,     0,     0,     0,   395,     0,     0,   396,
       0,     0,   497,   296,     0,     0,   297,     0,     0,   298,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,   679,   680,   681,     0,     0,  1579,
     685,   686,   687,   688,   689,   690,   691,     0,   692,   426,
       0,     0,   693,   694,     0,     0,   697,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   709,
       0,  1616,  1617,  1618,  1619,  1620,     0,     0,     0,     0,
    1625,  1626,     0,     0,     0,     0,  1628,     0,  1630,     0,
       0,     0,  1634,     0,     0,  1636,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1644,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,   400,
       0,     0,     0,   401,     0,   402,   115,     0,     0,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   809,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,   734,     0,   735,  1740,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1704,     0,
    1707,     0,     0,     0,  1714,     0,  1716,     0,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,  1741,     0,     0,
       0,   875,   204,     6,   376,     0,     0,     0,     0,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,  1580,   378,   379,   380,   381,
     382,   383,   384,   385,   237,   238,   239,   240,   386,   387,
     388,   389,   241,   242,     0,     0,   390,   391,   392,     0,
       0,   243,   244,   393,     0,   394,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,   395,
     249,     0,   396,     0,  1804,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,  1177,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1884,     0,     0,  1885,
     259,   397,   398,   399,   260,   261,     0,     0,     0,   262,
     263,   264,   400,   265,   266,   267,   401,     0,   402,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   269,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   357,     0,  1918,
    1919,  1581,  1921,     0,   273,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,    42,    43,    44,
      45,     0,     0,    47,     0,     0,     0,     0,     0,     0,
     748,    54,     0,     0,    57,   749,     0,   750,   751,  1178,
     752,     0,     0,     0,     0,     0,     0,  1169,     0,     0,
       0,     0,  1963,  1964,     0,     0,     0,     0,    78,     0,
       0,     0,     0,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,  1186,    92,    93,    94,   587,     0,     0,     0,   204,
       6,   376,     0,     0,     0,     0,   205,   206,   207,     0,
    1994,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   237,   238,   239,   240,   386,   387,   388,   389,   241,
     242,     0,     0,   390,   391,   392,     0,  1010,   243,   244,
     393,     0,   394,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,   248,    24,   395,   249,     0,   396,
       0,     0,     0,   250,     0,     0,   251,     0,     0,   252,
       0,   253,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,     0,    55,    56,     0,   256,     0,   257,
       0,     0,   258,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,     0,    72,    73,    74,    75,    76,    77,
       0,     0,     0,    81,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,  1365,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   397,   398,
     399,   260,   261,  1497,     0,     0,   262,   263,   264,   400,
     265,   266,   267,   401,     0,   402,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,   269,     0,     0,     0,     0,     0,   270,
       0,     0,     0,     0,   357,     0,     0,     0,   272,     0,
       0,   273,     0,     0,  2168,   204,   162,   376,     0,   425,
    1421,     0,   205,   206,   207,     0,     0,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   412,   226,   227,   228,   229,   230,
     231,     0,     0,     0,     0,     0,     0,     0,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   237,   238,   239,
     240,   386,   387,   388,   389,   241,     0,     0,     0,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   394,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
     248,    24,   395,   249,     0,   396,     0,     0,     0,   296,
       0,     0,   297,     0,     0,   298,     0,   299,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   426,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
     972,     0,     0,  1543,  1544,     0,     0,     0,   931,     0,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,   427,     0,     0,     0,
       0,     0,     0,   259,   397,   398,   399,   260,     0,     0,
       0,     0,   262,   263,   264,   400,   265,   266,   267,   401,
       0,   402,   115,   428,   429,   430,   431,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   413,
       0,     0,     0,     0,     0,   270,   432,   433,     0,     0,
     434,     0,   435,  1632,     0,     0,   436,   273,   204,     6,
     356,     0,     0,  1640,     0,   205,   206,   207,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,    24,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,   252,     0,
     253,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,    55,    56,     0,   256,     0,   257,     0,
       0,   258,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,     0,    72,    73,    74,    75,    76,    77,     0,
       0,     0,    81,     0,     0,    84,     0,  1774,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1822,     0,     0,     0,
    1823,     0,     0,     0,     0,     0,   259,     0,     0,     0,
     260,   261,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   269,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   357,   204,     6,     0,   358,     0,   665,
     273,   205,   206,   207,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,   244,     0,     0,     0,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
      24,     0,   249,     0,     0,     0,     0,     0,   250,     0,
       0,   251,     0,     0,   252,     0,   253,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,    55,
      56,     0,   256,     0,   257,     0,     0,   258,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,     0,    72,
      73,    74,    75,    76,    77,     0,     0,     0,    81,     0,
       0,    84,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    1849,     0,     0,     0,  1850,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,   260,   261,     0,     0,
       0,   262,   263,   264,     0,   265,   266,   267,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   495,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,   357,
     204,     6,  1677,     0,   561,     0,   273,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,   242,     0,     0,     0,     0,     0,     0,     0,   243,
     244,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,     0,
       0,     0,     0,     0,   250,     0,     0,   251,     0,     0,
     252,     0,   253,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,    55,    56,     0,   256,     0,
     257,     0,     0,   258,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  2018,     0,     0,     0,
    2019,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,     6,     0,   272,
       0,     0,   273,   205,   206,   207,     0,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,     0,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,   244,     0,     0,     0,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,     0,   249,     0,     0,     0,     0,     0,
     250,     0,     0,   251,     0,     0,   252,     0,   253,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,    55,    56,     0,   256,     0,   257,     0,     0,   258,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
       0,    72,    73,    74,    75,    76,    77,     0,     0,     0,
      81,     0,     0,    84,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   771,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,     0,   260,   261,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
       0,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   627,
    1841,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   629,   204,     6,     0,   318,   561,     0,   273,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,   244,     0,     0,     0,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,     0,
     249,     0,     0,     0,     0,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   931,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,     0,   260,   261,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   269,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   271,   204,     6,
       0,   272,     0,     0,   273,   205,   206,   207,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,    24,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,   252,     0,
     253,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,    55,    56,     0,   256,     0,   257,     0,
       0,   258,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,     0,    72,    73,    74,    75,    76,    77,     0,
       0,     0,    81,     0,     0,    84,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   932,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,     0,
     260,   261,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   269,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   357,   204,     6,     0,   272,     0,     0,
     273,   205,   206,   207,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,   244,     0,     0,     0,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
      24,     0,   249,     0,     0,     0,     0,     0,   250,     0,
       0,   251,     0,     0,   252,     0,   253,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,    55,
      56,     0,   256,     0,   257,     0,     0,   258,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,     0,    72,
      73,    74,    75,    76,    77,     0,     0,     0,    81,     0,
       0,    84,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   978,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,   260,   261,     0,     0,
       0,   262,   263,   264,     0,   265,   266,   267,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   495,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,   357,
     204,     6,     0,   556,     0,     0,   273,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,   242,     0,     0,     0,     0,     0,     0,     0,   243,
     244,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,     0,
       0,     0,     0,     0,   250,     0,     0,   251,     0,     0,
     252,     0,   253,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,    55,    56,     0,   256,     0,
     257,     0,     0,   258,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1085,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   495,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,     6,     0,     0,
     561,     0,   273,   205,   206,   207,     0,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,     0,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,   244,     0,     0,     0,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,     0,   249,     0,     0,     0,     0,     0,
     250,     0,     0,   251,     0,     0,   252,     0,   253,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,    55,    56,     0,   256,     0,   257,     0,     0,   258,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
       0,    72,    73,    74,    75,    76,    77,     0,     0,     0,
      81,     0,     0,    84,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1086,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,     0,   260,   261,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
       0,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     269,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   599,   204,     6,     0,   272,     0,     0,   273,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,   244,     0,     0,     0,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,     0,
     249,     0,     0,     0,     0,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1087,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,     0,   260,   261,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   269,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   606,   204,     6,
       0,   272,     0,     0,   273,   205,   206,   207,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,    24,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,   252,     0,
     253,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,    55,    56,     0,   256,     0,   257,     0,
       0,   258,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,     0,    72,    73,    74,    75,    76,    77,     0,
       0,     0,    81,     0,     0,    84,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1088,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,     0,
     260,   261,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   495,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   357,   204,     6,     0,   892,     0,  1351,
     273,   205,   206,   207,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,   244,     0,     0,     0,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
      24,     0,   249,     0,     0,     0,     0,     0,   250,     0,
       0,   251,     0,     0,   252,     0,   253,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,    55,
      56,     0,   256,     0,   257,     0,     0,   258,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,     0,    72,
      73,    74,    75,    76,    77,     0,     0,     0,    81,     0,
       0,    84,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1126,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,   260,   261,     0,     0,
       0,   262,   263,   264,     0,   265,   266,   267,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   495,     0,
       0,     0,     0,     0,   270,   204,     6,     0,     0,   357,
    1559,     0,   205,   206,   207,     0,   273,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,   238,   239,
     240,     0,     0,     0,     0,   241,   242,     0,     0,     0,
       0,     0,     0,     0,   243,   244,     0,     0,     0,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
     248,    24,     0,   249,     0,     0,     0,     0,     0,   250,
       0,     0,   251,     0,     0,   252,     0,   253,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,     0,
      55,    56,     0,   256,     0,   257,     0,     0,   258,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1136,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   495,
       0,     0,     0,     0,     0,   270,   204,     6,     0,     0,
     357,     0,     0,   205,   206,   207,     0,   273,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,     0,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,   244,     0,     0,     0,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,     0,   249,     0,     0,     0,     0,     0,
     250,     0,     0,   251,     0,     0,   252,     0,   253,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,    55,    56,     0,   256,     0,   257,     0,     0,   258,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
       0,    72,    73,    74,    75,    76,    77,     0,     0,     0,
      81,     0,     0,    84,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1137,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,     0,   260,   261,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
       0,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     269,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   357,   204,     6,     0,  1685,     0,     0,   273,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,   244,     0,     0,     0,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,     0,
     249,     0,     0,     0,     0,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1138,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,     0,   260,   261,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   627,  1841,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   629,   204,     6,
       0,   318,     0,     0,   273,   205,   206,   207,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,    24,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,   252,     0,
     253,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,    55,    56,     0,   256,     0,   257,     0,
       0,   258,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,     0,    72,    73,    74,    75,    76,    77,     0,
       0,     0,    81,     0,     0,    84,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1143,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,     0,
     260,   261,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   495,     0,     0,     0,     0,     0,   270,   204,
     162,   376,     0,   357,     0,     0,   205,   206,   207,     0,
     273,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   412,   226,
     227,   228,   229,   230,   231,     0,     0,     0,     0,     0,
       0,     0,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   237,   238,   239,   240,   386,   387,   388,   389,   241,
       0,     0,     0,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   394,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,   248,    24,   395,   249,     0,   396,
     204,   162,   376,     0,     0,     0,     0,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,     0,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   237,   238,   239,   240,   386,   387,   388,   389,
     241,     0,     0,     0,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   394,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,   395,   249,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   397,   398,
     399,   260,     0,     0,     0,     0,   262,   263,   264,   400,
     265,   266,   267,   401,     0,   402,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,   413,     0,     0,     0,     0,     0,   270,
       0,     0,     0,     0,   357,     0,     0,     0,  1576,     0,
       0,   273,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1144,     0,     0,     0,   259,   397,
     398,   399,   260,     0,     0,     0,     0,   262,   263,   264,
     400,   265,   266,   267,   401,     0,   402,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,   162,   376,  1854,
       0,     0,   273,   205,   206,   207,     0,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   412,   226,   227,   228,   229,
     230,   231,     0,     0,     0,     0,     0,     0,     0,  1580,
     378,   379,   380,   381,   382,   383,   384,   385,   237,   238,
     239,   240,   386,   387,   388,   389,   241,     0,     0,     0,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   394,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,   395,   249,     0,   396,   204,   162,   376,
       0,     0,     0,     0,   205,   206,   207,     0,     0,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   412,   226,   227,   228,
     229,   230,   231,     0,     0,     0,     0,     0,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   237,
     238,   239,   240,   386,   387,   388,   389,   241,     0,     0,
       0,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     394,   245,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   248,    24,   395,   249,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   397,   398,   399,   260,     0,
       0,     0,     0,   262,   263,   264,   400,   265,   266,   267,
     401,     0,   402,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     413,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   357,     0,     0,     0,  1740,     0,     0,   273,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1146,     0,     0,     0,   259,   397,   398,   399,   260,
       0,     0,     0,     0,   262,   263,   264,   400,   265,   266,
     267,   401,     0,   402,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,   413,     0,     0,     0,     0,     0,   270,   204,   162,
       0,     0,   357,     0,     0,   205,   206,   207,     0,   273,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   412,   226,   227,
     228,   229,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
     204,   162,     0,   248,    24,   860,   249,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,   259,     0,     0,     0,
     260,  1256,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   627,   628,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   629,     0,     0,     0,   318,     0,     0,
     273,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,   259,     0,
       0,     0,   260,  1277,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,   204,   162,     0,     0,   357,     0,     0,   205,   206,
     207,     0,   273,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     412,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
     204,   162,     0,  1303,     0,     0,     0,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,   259,
       0,   587,     0,   260,     0,     0,     0,     0,   262,   263,
     264,  1360,   265,   266,   267,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,  1074,     0,     0,
       0,     0,     0,   273,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1363,     0,   259,     0,
       0,     0,   260,     0,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,   204,   162,     0,  1458,   357,     0,     0,   205,   206,
     207,     0,   273,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     412,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
     204,   162,     0,  1521,     0,     0,     0,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,   259,
       0,   587,     0,   260,     0,     0,     0,     0,   262,   263,
     264,  1452,   265,   266,   267,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,   273,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1453,     0,   259,     0,
       0,     0,   260,     0,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,   204,   162,     0,     0,   357,     0,     0,   205,   206,
     207,     0,   273,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     412,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,   204,   162,     0,   248,    24,     0,   249,
     205,   206,   207,     0,     0,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   412,   226,   227,   228,   229,   230,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   239,   240,     0,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   248,    24,
       0,   249,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,   259,
       0,     0,     0,   260,  1496,     0,     0,     0,   262,   263,
     264,     0,   265,   266,   267,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,  1574,     0,     0,
       0,     0,     0,   273,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,   259,     0,     0,     0,   260,  1621,     0,     0,     0,
     262,   263,   264,     0,   265,   266,   267,     0,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   413,     0,     0,
       0,     0,     0,   270,   204,   162,     0,     0,   357,  1901,
       0,   205,   206,   207,     0,   273,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   412,   226,   227,   228,   229,   230,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   376,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
      24,     0,   249,     0,   377,   378,   379,   380,   381,   382,
     383,   384,   385,     0,     0,     0,     0,   386,   387,   388,
     389,     0,     0,     0,     0,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   395,     0,
       0,   396,     0,     0,     0,   296,     0,     0,   297,     0,
       0,   298,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,   260,     0,     0,     0,
       0,   262,   263,   264,     0,   265,   266,   267,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   413,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,   357,
     397,   398,   399,     7,     8,     0,   273,     0,     0,     0,
       0,   400,     0,     0,     0,   401,     0,   402,   115,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,    42,    43,    44,    45,     0,
       0,    47,     0,     0,     0,     0,     0,     0,   748,    54,
    1740,     0,    57,   749,     0,   750,   751,     0,   752,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      92,    93,    94,    42,    43,    44,    45,     0,     0,    47,
       0,     0,     0,     0,     0,     0,   748,    54,     0,     0,
      57,   749,     0,   750,   751,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    92,    93,
      94,    42,    43,    44,    45,  1012,     0,    47,     0,     0,
       0,     0,     0,     0,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    92,    93,    94,    42,
      43,    44,    45,  1208,     0,    47,     0,     0,     0,     0,
       0,     0,   748,    54,     0,     0,    57,   749,     0,   750,
     751,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    92,    93,    94,    42,    43,    44,
      45,  1210,     0,    47,     0,     0,     0,     0,     0,     0,
     748,    54,     0,     0,    57,   749,     0,   750,   751,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    92,    93,    94,    42,    43,    44,    45,  1211,
       0,    47,     0,     0,     0,     0,     0,     0,   748,    54,
       0,     0,    57,   749,     0,   750,   751,     0,   752,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      92,    93,    94,    42,    43,    44,    45,  1230,     0,    47,
       0,     0,     0,     0,     0,     0,   748,    54,     0,     0,
      57,   749,     0,   750,   751,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    92,    93,
      94,    42,    43,    44,    45,  1248,     0,    47,     0,     0,
       0,     0,     0,     0,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    92,    93,    94,    42,
      43,    44,    45,  1262,     0,    47,     0,     0,     0,     0,
       0,     0,   748,    54,     0,     0,    57,   749,     0,   750,
     751,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    92,    93,    94,    42,    43,    44,
      45,  1295,     0,    47,     0,     0,     0,     0,     0,     0,
     748,    54,     0,     0,    57,   749,     0,   750,   751,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    92,    93,    94,    42,    43,    44,    45,  1450,
       0,    47,     0,     0,     0,     0,     0,     0,   748,    54,
       0,     0,    57,   749,     0,   750,   751,     0,   752,     0,
       0,     0,     0,     0,    -4,     1,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,    78,    -4,    -4,     0,
       0,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
      92,    93,    94,   587,     0,     0,     0,  2076,    -4,    -4,
       0,     0,     0,  1622,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,    -4,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,  2135,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,
      -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,     0,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,    10,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,     0,    -4,     0,     0,     0,    11,    12,
      13,     0,     0,     0,    14,    15,     0,     0,     0,    16,
       0,     0,     0,     0,    17,    18,    19,    20,    21,     0,
      22,    23,     0,    24,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,     0,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,     0,     0,     0,    90,     0,     0,     0,
       0,    91,    92,    93,    94,   162,   376,    95,     0,    96,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   111,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,   115,     0,     0,   377,   378,   379,
     380,   381,   382,   383,   384,   385,     0,     0,     0,     0,
     386,   387,   388,   389,     0,   162,   376,     0,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,     0,     0,   396,     0,     0,     0,   296,     0,
       0,   297,     0,     0,   298,     0,   299,   377,   378,   379,
     380,   381,   382,   383,   384,   385,     0,    45,     0,     0,
     386,   387,   388,   389,   406,   376,     0,     0,   390,   391,
     392,     0,     0,     0,   426,   393,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   377,   378,   379,   380,
     381,   382,   383,   384,   385,     0,     0,     0,     0,   386,
     387,   388,   389,   376,     0,     0,     0,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   394,     0,     0,     0,
       0,     0,     0,   397,   398,   399,     0,     0,     0,     0,
     395,     0,     0,   396,   400,     0,     0,     0,   401,     0,
     402,   115,     0,     0,   377,   378,   379,   380,   381,   382,
     383,   384,   385,     0,     0,     0,     0,   386,   387,   388,
     389,     0,     0,     0,     0,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   394,     0,     0,     0,     0,     0,
       0,     0,     0,   397,   398,   399,     0,     0,   395,     0,
       0,   396,     0,     0,   400,     0,     0,     0,   401,     0,
     402,   115,     0,     0,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     7,     8,  1623,     0,     0,     0,
       0,     0,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,   400,     0,     0,     0,   401,     0,   402,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1637,     0,     0,     0,     0,     0,     0,     0,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
       0,   400,     0,     0,     0,   401,     0,   402,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     7,     8,     0,    42,    43,    44,    45,     0,     0,
      47,     0,     0,     0,     0,     0,     0,   748,    54,     0,
       0,    57,   749,     0,   750,   751,     0,   752,     0,     0,
       0,  1021,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,  1022,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,    92,
      93,    94,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1768,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,    42,    43,    44,    45,     0,     0,    47,     0,     0,
       0,     0,     0,     0,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,    92,    93,    94,     0,
       0,     0,     0,     0,     0,  1888,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1889,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1920,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1923,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1990,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2044,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2045,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2059,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2061,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2094,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2122,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2127,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2128,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2129,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2169,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,   806,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  1056,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  1113,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  1158,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  1159,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  1202,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    1233,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  1253,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  1309,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  1329,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1409,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  1410,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  1454,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  1527,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  1770,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  1820,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    1831,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  1868,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  1940,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  1955,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1967,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  2024,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  2033,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  2034,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  2057,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  2108,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    2148,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  2167,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  2187,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  2188,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  2189,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,   712,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,   923,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
    1933,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,   734,     0,   735,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,   984,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,  1032,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,  1182,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,  1247,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,  1249,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,  1254,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,  1255,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,  1343,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
    1357,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,  1556,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,  1643,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,  1692,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,  1880,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,  1925,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,  1941,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   787,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   788,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   789,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   791,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   792,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   793,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   795,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   796,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   797,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   798,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   799,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   800,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   801,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   803,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   804,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   805,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   872,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   907,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   953,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   972,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   974,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   975,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   976,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   982,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   983,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1020,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1031,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1093,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1097,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1109,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1181,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1191,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1192,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1193,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1203,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1232,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1234,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1235,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1236,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1237,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1238,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1239,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1240,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1246,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1342,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1356,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1557,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1588,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1589,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1590,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1591,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1629,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1642,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1755,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1757,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1760,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1767,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1821,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1830,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1853,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1924,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1988,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1989,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  2121,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  2164,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587
};

static const yytype_int16 yycheck[] =
{
       3,   141,   154,     3,  1227,   311,  1416,     4,  1679,  1231,
       5,   193,   729,   624,   625,     4,  1723,   716,  1725,   201,
     737,    24,    61,     4,     4,     4,     4,  1903,     4,   106,
      24,   108,     6,   323,     4,     6,     5,     4,     4,     9,
    1710,     5,   137,     4,     6,     6,   745,     6,     4,     6,
      53,     5,   342,     6,     4,   103,     7,   158,   103,   100,
       4,   103,   103,   762,   141,     4,     4,     4,   137,    97,
     248,   770,   236,   237,   252,   116,   236,   237,     7,    82,
       7,   126,   183,     9,   126,   252,   155,    90,   116,   256,
     167,   186,    95,   257,   163,   164,   165,   257,   199,   200,
     169,   170,     9,   106,  1774,     6,   236,   237,    89,     6,
     249,   293,   294,   295,   249,   254,   236,   237,     9,   409,
       6,   411,   257,  1794,   236,   237,   249,   257,   251,   419,
       9,     9,   236,   237,   257,     6,    97,   257,   141,     9,
     236,   237,   142,   146,   147,   257,   137,   254,     6,   253,
     257,   154,   249,   335,   336,   337,   106,   107,   244,   245,
     257,   257,   236,   237,   155,     0,   236,   237,   254,   172,
     352,     8,   163,   164,   165,   874,  2052,   248,   169,   170,
     236,   237,    14,   257,   253,   188,   141,   257,   249,   251,
     193,   146,   147,   196,   248,   257,   257,   171,   201,   202,
     203,   257,   236,   237,   243,   244,     6,   173,   174,   175,
     176,     7,   249,   194,   171,     7,   183,   184,   252,   251,
     257,     7,   198,   220,  1634,   257,   100,   183,   184,   103,
     236,   237,   248,   188,   236,   237,   252,   236,   237,   220,
     220,   220,   220,    67,    68,     6,    70,  1470,   203,   248,
     220,   257,   255,   252,     6,   257,     7,   252,   255,  1930,
     253,   250,   253,   252,   257,     6,   269,   256,     7,   272,
     273,   252,   252,   252,   244,   245,   220,   248,   248,   273,
     250,   252,   252,   252,   254,   288,   289,   253,   252,   292,
     293,   294,   295,   252,   221,   222,   223,   224,   252,   252,
     248,     3,   305,   254,   249,   249,   309,   251,   311,   248,
     248,   248,   257,  1984,  1031,  1032,     6,   244,   245,   248,
       6,   250,   248,   613,   250,   615,   616,   254,   254,   248,
     333,   250,   335,   336,   337,   236,   237,   244,   245,   236,
     237,   248,   632,   250,   251,   244,   245,   254,   425,   352,
     236,   237,   252,   244,   245,   358,     6,   248,    60,   250,
     650,   232,     6,   254,   235,   547,   244,   245,   250,   248,
     248,   250,   250,   250,   232,   254,   254,   235,   248,   100,
     250,  2088,   103,   673,   105,   537,   236,   237,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   248,   257,   236,   237,
     247,     4,   248,   416,   417,   249,   253,   251,   421,   422,
     248,   248,   712,   257,   252,   221,   222,   223,   224,   221,
     222,   223,   224,   248,   437,   221,   222,   223,   224,   141,
     248,   444,   244,   245,   146,   147,   236,   237,   244,   245,
     252,   248,   154,  2124,   236,   237,   236,   237,   244,   245,
       4,   416,   103,   466,   105,   253,  1165,   257,  1167,   257,
     221,   222,   223,   224,   253,   257,   553,   257,   257,   236,
     237,  1180,   221,   222,   223,   224,   188,   249,   236,   237,
     314,   315,   495,   244,   245,   257,   236,   237,   322,   323,
     257,   203,   248,   248,    97,   250,  2177,    97,   101,   257,
     100,  1921,   252,   103,   107,   108,   519,   110,   111,    97,
     236,   237,   100,   526,   527,   103,   116,   105,   531,   681,
     533,   534,   535,   536,   537,   248,   137,   130,   116,   542,
     242,   257,   248,   546,   547,   548,   549,   550,   551,   552,
     248,   554,   250,   556,   155,   257,   258,     8,   552,   257,
     554,   248,   163,   164,   165,   236,   237,   248,   169,   170,
     248,   236,   237,   253,   236,   237,   531,   257,   533,   582,
     535,   536,   236,   237,   248,   588,   257,   118,   249,   729,
     252,  1290,   257,   248,   549,   550,   257,  1296,   142,   143,
     144,   145,   248,   257,   148,   608,   609,   249,   137,   251,
     253,   236,   237,   157,   257,   257,   160,   694,   238,   239,
     240,   241,   242,   252,   624,   625,   155,   247,   103,   253,
    1241,   137,   257,   257,   163,   164,   165,   927,     6,     8,
     169,   170,  1341,   253,   249,   100,   251,   257,   103,   155,
     105,   105,   253,   656,   657,   658,  1355,   163,   164,   165,
     252,   116,  1361,   169,   170,   248,   248,   250,   253,   241,
     242,   254,   257,   248,   257,   247,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   252,   689,   690,   691,   692,
     693,   252,   695,   696,   697,   698,   699,    97,   253,   702,
     100,   103,   257,   103,   698,   105,   248,   244,   245,   786,
     713,   249,   751,   251,   416,   252,     8,   253,   248,   257,
     250,   257,   252,   726,   426,   680,  1443,   682,   683,   684,
     685,   686,   687,   736,   689,   690,   691,   692,   100,   742,
     695,   696,   697,   254,   252,   256,   448,   253,   236,   237,
     238,   239,   240,   241,   242,   758,   759,   252,   249,   247,
     251,   764,   252,   903,   767,   768,   257,   248,   248,   250,
     250,   774,   252,   776,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   248,   253,   142,   143,   247,   257,   622,   623,
     148,   103,   253,   627,   142,   143,   809,   253,   811,   100,
     148,   257,   767,  1530,   253,   253,   253,   100,   257,   257,
     257,   776,   253,   253,   253,  1542,   257,   257,   257,   531,
     103,   533,   253,   535,   536,   537,   257,     4,   253,   253,
     917,   844,   257,   257,     4,   253,   253,   549,   550,   257,
     257,   854,   248,     4,   250,  2077,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   248,   253,   250,   253,   247,   257,
     249,   257,   251,   248,     4,   250,   253,  2110,     6,   892,
     257,  1031,  1032,   253,   253,   248,   253,   257,   257,     6,
     257,   253,   905,   253,   253,   257,   253,   257,   257,   253,
     257,   914,    53,   257,  2136,     6,     7,   253,   253,   253,
     923,   257,   257,   257,   248,   253,   253,   248,   630,   257,
     257,  2154,   248,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   653,     4,   248,     6,   247,  1033,   249,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   249,   253,   251,   252,   247,   257,   679,   680,   681,
     682,   683,   684,   685,   686,   687,     6,   689,   690,   691,
     692,   250,   253,   695,   696,   697,   257,   253,   253,   248,
     253,   257,   257,   705,   257,   253,   708,   253,   253,   257,
     253,   257,   257,   253,   257,   253,  1322,   257,   720,   257,
     253,   253,   253,  1026,   257,   257,   257,   253,   253,   253,
     250,   257,   257,   257,  1037,   249,   253,   251,   252,  1042,
     257,  1181,  1182,     6,     7,   236,   237,   252,   750,     6,
     752,     6,  1055,  1664,  1665,   256,   252,  1060,   256,   248,
       9,   202,   248,   248,   248,   767,   248,   248,   248,   248,
     248,   186,   248,   186,   776,   252,   186,   252,   126,   248,
     248,   186,   248,   248,   248,   248,     4,   248,  1091,  1092,
     252,  1094,  1095,  1096,   252,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1060,   930,  1110,   252,   252,
     252,   248,   252,   937,   255,   248,   248,   941,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   248,   248,     6,   248,
     247,     6,   248,     6,   252,  1148,  1149,  1150,   250,   252,
       6,   292,   252,   252,   250,   250,   250,     6,   186,   252,
     248,   248,   248,   248,   305,   248,   248,     6,   309,  1172,
     250,     6,     6,   252,     6,     8,   252,     8,     7,     6,
     252,   252,     6,   252,    92,  1188,  1189,  1190,   253,     6,
     257,   257,   249,     7,  1149,  1150,     6,     6,   249,   252,
     254,   247,  1342,  1343,    64,   252,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   926,   252,   928,   929,   247,   252,
    1520,  1537,     8,     4,  1524,     7,   248,     7,   257,  1242,
     942,  1241,     6,   249,     6,   252,     7,     6,   253,     7,
       6,     6,   183,   252,  1257,  1258,  1259,   253,   253,   961,
     251,   249,     6,     6,   254,  1268,  1090,   252,     7,     6,
    1273,   250,   248,     4,  1277,   252,     6,   979,     6,     6,
     421,   422,     6,  1286,   249,  1288,   250,  1364,  1291,  1366,
       6,   252,     7,     7,     7,     7,   437,     7,     7,     7,
       7,     7,     7,  1306,     7,     7,     7,     7,     7,     7,
       6,   249,   251,  1015,   257,   257,   257,   253,  1273,  1322,
     257,   249,  1277,     7,   253,  1936,   252,   254,     7,   252,
     252,  1286,     4,  1288,   254,     6,  1291,   253,   253,   137,
    1343,   252,     7,     6,   254,  1348,     7,  1350,     7,     7,
     249,   249,   257,   257,     9,   257,   249,   251,  1060,   254,
     256,   186,     7,  1366,   158,   253,   252,     6,     6,     6,
       4,    46,    46,   254,   248,   252,  1379,   248,   254,   252,
    1383,   248,   254,     4,   248,     7,   186,     7,  1343,     7,
    1530,  1543,  1544,   534,   249,   257,     7,     7,     7,     6,
     257,   249,     7,     7,     7,   546,     4,   548,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   115,     4,     6,   252,
     247,  1737,   248,     7,  1437,  1438,  1439,     6,     6,  1516,
       7,     7,  1445,     7,     7,     7,     7,  1149,  1150,     7,
     252,     6,     6,   103,     7,     6,     6,  1460,     4,     4,
     255,   257,   249,   252,   257,   253,   252,   252,  1471,     6,
       6,     6,   250,     7,     6,     6,  1479,   252,     6,   248,
    1483,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,  1576,
     248,  1641,   253,   247,     6,   254,     6,  1209,     6,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     6,   251,   130,
       6,   247,   257,     6,  1537,     6,     6,     6,     6,     6,
    1543,  1544,     6,     6,     6,     6,  1549,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     6,  1567,     5,   249,   247,   249,     6,
       4,  1273,     7,  1576,     6,  1277,     4,     6,  1581,   252,
       6,   250,   252,  1660,  1286,   726,  1288,     6,  1740,  1291,
     252,     6,   252,     6,     6,   252,   252,     6,  1300,   252,
     252,   252,   182,   252,   252,     6,   253,     6,   252,     6,
       6,   257,  1567,  1753,   257,   257,   249,   252,     7,   248,
       4,   257,   254,     6,   252,     6,  1703,   253,     6,     6,
       4,   248,   248,  1710,  1711,     7,     6,     6,     6,     6,
       6,  1343,     6,     6,   137,  1469,   101,     6,     6,     5,
    1653,   257,  1729,  1656,  1657,  1945,   252,   249,   252,   252,
       6,     6,   257,     6,  1664,  1665,     6,  1973,     6,     6,
     257,   257,     6,   249,     4,     6,  1679,     6,   257,   252,
       6,     6,  1685,     6,     6,     6,     6,   252,     7,   141,
       5,     7,  1695,   252,     6,   252,   252,   249,     6,     6,
       6,     6,  1705,   252,   252,  1708,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   181,   252,  1726,   253,   247,   253,     6,   249,   253,
    1733,     6,     6,   253,  1737,   253,  1739,  1740,     7,   254,
       6,     6,     6,   252,     6,     6,   253,     6,  2038,     6,
    1705,   252,   249,  1708,     6,     6,   252,   184,   253,   253,
     248,   252,   249,     6,     6,     6,   252,   252,   252,     6,
    1594,  1774,   253,   914,   252,   137,     6,     6,     6,     6,
     252,     6,     6,   249,     6,     6,     6,     6,  2078,     6,
    1867,  1794,     6,     6,   253,   253,   252,     6,   252,     6,
       6,   252,     6,  1806,  1807,     6,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     6,     6,  1829,     6,   247,  1354,
    2090,  1411,  1909,   463,  1865,  1649,  1586,  1904,  1841,  1378,
       3,  1543,  1544,     3,     3,     3,   603,  1932,     3,  1733,
    1513,  1854,  1544,  1710,   767,    -1,  1680,  1681,  1682,  1683,
    1684,  1685,    -1,     6,    -1,  1567,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,  1026,    -1,    -1,  1891,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1042,  1905,    -1,    -1,    -1,    -1,  1910,    -1,    -1,
    1913,  1914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,  1930,    -1,    -1,
    1933,    -1,    -1,    -1,    -1,    -1,  1936,    -1,    -1,    -1,
      -1,  1944,    -1,    -1,    -1,  1948,    -1,    -1,    -1,    -1,
    1091,  1092,    -1,  1094,  1095,  1096,    -1,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,    -1,    -1,    -1,
    1973,    -1,    -1,    -1,    -1,    -1,  2053,    -1,    -1,    -1,
      -1,  1984,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,  1705,   247,    -1,  1708,  1148,  2011,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1723,    -1,  1725,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1172,    -1,    -1,    -1,    -1,    -1,    -1,  1740,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2062,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1774,    -1,    -1,    -1,    -1,  2080,  2081,  2082,
    2083,  2084,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,  1242,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1257,  1258,  1259,    -1,
       6,  2124,    -1,    -1,    -1,  1949,  1950,  1951,  1952,  1953,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2141,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
    2163,   247,    -1,    -1,    -1,  1306,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2177,    -1,    -1,    -1,    -1,    -1,
      -1,  2184,  2185,    -1,    -1,    -1,  2010,    -1,    -1,    -1,
    2014,    -1,    -1,    -1,    -1,  2198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2163,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1366,    -1,    -1,    -1,  2184,
    2185,    -1,    -1,    -1,    -1,    -1,    -1,   141,  1379,    -1,
    2064,   145,  1383,  2198,  2068,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,
    2084,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,    -1,   177,   178,   179,    -1,   181,   182,   183,
     184,   185,   186,   187,    -1,   189,   190,   191,   192,    -1,
      -1,    -1,   196,    -1,    -1,    -1,  1437,  1438,  1439,    -1,
      -1,    -1,    -1,    -1,  1445,    -1,    -1,  2131,  2132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1460,
      -1,  2023,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1479,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,   268,   269,   270,   271,   272,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,   289,  2088,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   307,    -1,    -1,    -1,    -1,  1549,  2111,
      -1,    -1,    -1,   317,   318,    -1,    -1,    -1,    -1,   323,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,
     334,    -1,    -1,    -1,    -1,  1576,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,   358,    -1,    -1,    -1,   362,   363,
     364,  2163,   366,    -1,    -1,    -1,   370,   371,   372,    -1,
      -1,   375,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2184,  2185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,
      -1,    -1,  1653,   417,   418,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   435,    -1,    -1,    -1,    -1,    -1,    -1,  1679,    -1,
      -1,    -1,    -1,    -1,    -1,   449,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1695,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   468,   469,   470,   471,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1726,    -1,    -1,    -1,    -1,
     494,   495,    -1,    -1,    -1,   499,    -1,    -1,  1739,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,    -1,   529,   530,    -1,   532,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   541,    -1,    -1,
     544,   545,    -1,    -1,    -1,    -1,    -1,   551,    -1,    -1,
      -1,    -1,   556,  1794,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,    -1,   589,   590,    -1,  1829,    -1,
      -1,    -1,     6,   597,   598,   599,    -1,    -1,    -1,    -1,
      -1,   605,   606,    -1,   608,   609,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   627,   628,   629,    -1,    -1,    -1,   633,
     634,   635,   636,   637,   638,   639,   640,   641,    -1,     6,
      -1,    -1,    -1,   647,    -1,   649,    -1,    -1,   652,    -1,
    1891,    -1,   656,   657,   658,   659,    -1,   661,   662,   663,
      -1,    -1,    -1,    -1,  1905,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,   688,    -1,    -1,   247,    -1,  1930,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   702,    -1,
     288,   289,    -1,  1944,    -1,   709,    -1,   711,    -1,    -1,
     714,   715,    -1,    -1,    -1,    -1,    -1,   196,    -1,   723,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   736,    -1,   738,    -1,    -1,    -1,    -1,   743,
     744,    -1,    -1,  1984,    -1,   333,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   758,    -1,   760,   761,    -1,    -1,
     764,   765,    -1,    -1,    -1,   769,    -1,   771,    -1,    -1,
    2011,    -1,    -1,   777,    -1,    -1,    -1,   781,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   807,    -1,   809,    -1,   811,    -1,   288,
     289,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   417,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,
     844,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     854,   855,   856,    -1,   333,    -1,    -1,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,   358,
     247,    -1,    -1,  2124,    -1,    -1,    -1,    -1,   892,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   905,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   913,
      -1,    -1,    -1,   917,    -1,    -1,    -1,    -1,    -1,   923,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   931,   932,    -1,
      -1,    -1,    -1,   937,    -1,    -1,  2177,    -1,   417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     954,    -1,    -1,   957,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,     6,
      -1,    -1,    -1,    -1,   978,    -1,   980,   981,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   999,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     7,   495,    -1,  1022,   247,
     608,   609,    -1,    -1,    -1,  1029,    -1,    -1,    -1,    -1,
    1034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     519,    -1,    -1,    -1,    -1,  1049,  1050,   526,   527,    -1,
      -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   656,   657,
     658,    -1,   551,    -1,    -1,    -1,    -1,   556,    -1,    -1,
      -1,  1085,  1086,  1087,  1088,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   582,    -1,    -1,  1110,   247,    -1,   249,
      -1,   251,    -1,    -1,   702,    -1,    -1,   257,    -1,    -1,
      -1,    -1,  1126,    -1,    -1,    -1,    -1,    -1,    -1,   608,
     609,    -1,  1136,  1137,  1138,    -1,    -1,    -1,    -1,  1143,
    1144,    -1,  1146,    -1,    -1,    -1,    -1,    -1,   736,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1160,  1161,     6,    -1,
      -1,    -1,    -1,    -1,  1168,  1169,    -1,    -1,    -1,    -1,
     758,  1175,    -1,  1177,  1178,    -1,   764,   656,   657,   658,
    1184,  1185,    -1,    -1,    -1,  1189,  1190,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,  1221,    -1,    -1,
      -1,    -1,    -1,   702,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,  1256,    -1,    -1,   247,   844,   736,    -1,    -1,
      -1,    -1,    -1,    -1,  1268,    -1,   854,    -1,    -1,    -1,
      -1,    -1,  1276,    -1,    -1,    -1,    -1,    -1,    -1,   758,
      -1,    -1,    -1,    -1,    -1,   764,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1297,  1298,    -1,    -1,    -1,  1302,    -1,
      -1,    -1,    -1,    -1,   892,    -1,    -1,    -1,    -1,  1313,
      -1,    -1,  1316,    -1,    -1,    -1,    -1,   905,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,    -1,
     809,    -1,   811,    -1,    -1,   923,    -1,    -1,    -1,    -1,
    1344,    -1,    -1,  1347,  1348,  1349,  1350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1358,    -1,  1360,    -1,  1362,  1363,
    1364,    -1,    -1,    -1,    -1,   844,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,   854,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   892,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,   905,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
    1444,    -1,    -1,    74,   923,    76,    -1,  1451,  1452,  1453,
      -1,    -1,    -1,    -1,    -1,    -1,  1460,    -1,  1462,    90,
      -1,    -1,    93,    -1,    -1,  1469,    97,  1055,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,  1483,
      -1,    -1,    -1,    -1,  1488,   116,    -1,    -1,    -1,    -1,
      -1,    -1,  1496,  1497,  1498,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,  1508,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1541,    -1,    -1,
      -1,    -1,    -1,  1547,  1548,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,   202,   203,   204,    -1,    -1,  1055,  1581,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,   217,    -1,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1189,  1190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,   245,    -1,    -1,  1621,  1622,  1623,
      -1,   252,    -1,   254,    -1,    -1,    -1,    -1,  1632,    -1,
      -1,  1110,    -1,  1637,  1638,  1639,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1651,    -1,    -1,
      -1,    -1,  1656,  1657,  1658,    -1,  1660,    -1,    -1,    -1,
      -1,    -1,  1666,  1667,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1268,  1685,    -1,    -1,    -1,    -1,  1690,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,  1703,
      -1,    -1,  1706,    -1,    -1,    -1,  1710,    -1,    -1,    -1,
    1189,  1190,    -1,    -1,    -1,  1719,  1720,    -1,  1722,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1730,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1746,    -1,    -1,    -1,    -1,  1751,  1752,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1348,  1765,  1350,   439,  1768,  1769,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,  1268,
      -1,   113,   114,   115,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,  1806,  1807,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,  1823,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1832,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,  1841,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1850,  1851,    -1,    -1,
    1854,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,  1348,
      -1,  1350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,  1888,  1889,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1483,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1908,    -1,    -1,    -1,    -1,  1913,
    1914,  1915,    -1,    -1,    -1,    -1,  1920,   593,    -1,  1923,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1933,
      -1,   253,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1948,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    -1,  1981,    -1,   113,
     114,   115,   116,  1987,    -1,   119,  1990,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,   130,   131,    -1,   133,
     134,    -1,   136,    -1,  1483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2019,    -1,    -1,    -1,    -1,
     154,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
    2044,  2045,    -1,   247,   178,   179,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2058,  2059,    -1,  2061,  2062,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1656,  1657,
      -1,  2075,    -1,    -1,    -1,    -1,  2080,  2081,  2082,  2083,
    2084,    -1,    -1,    -1,    -1,    -1,  2090,    -1,    -1,    -1,
    2094,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2122,   253,
      -1,    -1,    -1,  2127,  2128,  2129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2141,    -1,    -1,
     816,   817,   818,   819,   820,   821,   822,   823,   824,   825,
     826,    -1,   828,   829,   830,   831,    -1,   833,   834,   835,
     836,     8,    -1,    -1,    -1,  2169,  2170,  2171,    -1,    -1,
      -1,   847,    -1,   849,    -1,    -1,    -1,  1656,  1657,    -1,
      -1,    -1,    -1,   859,    -1,    -1,    -1,    -1,    -1,    -1,
     866,   867,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   875,
      -1,    -1,    -1,    -1,    -1,    -1,  1685,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,  1806,  1807,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1854,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,   985,
     986,   987,    -1,    -1,    -1,   991,   992,    -1,    -1,   995,
     996,   997,   998,    -1,  1000,  1913,  1914,  1806,  1807,  1005,
      -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1933,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1948,    -1,  1841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1854,    -1,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1084,    -1,
      -1,    -1,    -1,  1089,   201,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
      -1,    -1,    -1,   220,  1913,  1914,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   236,
     237,    -1,    -1,    -1,  1933,    -1,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,   252,    -1,    -1,   255,  1948,
      -1,    -1,    -1,    -1,  2062,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2080,  2081,  2082,  2083,  2084,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1186,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,  2141,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   261,    -1,
       4,     5,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2062,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2080,  2081,  2082,  2083,  2084,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     8,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,  1325,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,  2141,    97,    -1,    -1,   100,    -1,    -1,   103,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,   377,   378,   379,    -1,    -1,  1365,
     383,   384,   385,   386,   387,   388,   389,    -1,   391,   133,
      -1,    -1,   395,   396,    -1,    -1,   399,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,  1397,  1398,  1399,  1400,  1401,    -1,    -1,    -1,    -1,
    1406,  1407,    -1,    -1,    -1,    -1,  1412,    -1,  1414,    -1,
      -1,    -1,  1418,    -1,    -1,  1421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1433,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,   249,    -1,   251,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1504,    -1,
    1506,    -1,    -1,    -1,  1510,    -1,  1512,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,  1543,    -1,    -1,
      -1,   564,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    73,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    -1,    93,    -1,  1640,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,     8,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1742,    -1,    -1,  1745,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,    -1,  1795,
    1796,   252,  1798,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,    -1,   113,   114,   115,
     116,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,   130,   131,    -1,   133,   134,     8,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   870,    -1,    -1,
      -1,    -1,  1858,  1859,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   904,   178,   179,   180,   247,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
    1906,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    67,    68,    69,    -1,   253,    72,    73,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,   146,    -1,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1078,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,   203,
     204,   205,   206,     8,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,    -1,
      -1,   255,    -1,    -1,  2150,     3,     4,     5,    -1,     7,
    1173,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
     249,    -1,    -1,  1326,  1327,    -1,    -1,    -1,   257,    -1,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,    -1,    -1,
     248,    -1,   250,  1416,    -1,    -1,   254,   255,     3,     4,
       5,    -1,    -1,  1426,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,    -1,  1580,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,     3,     4,    -1,   252,    -1,     8,
     255,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,    -1,   131,    -1,   133,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
      -1,   160,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,   206,    -1,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,
       3,     4,     5,    -1,   253,    -1,   255,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,    -1,
     133,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,   157,    -1,    -1,   160,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   205,   206,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,   248,     3,     4,    -1,   252,
      -1,    -1,   255,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,    -1,   131,    -1,   133,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,
      -1,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,   252,   253,    -1,   255,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,     3,     4,
      -1,   252,    -1,    -1,   255,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,     3,     4,    -1,   252,    -1,    -1,
     255,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,    -1,   131,    -1,   133,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
      -1,   160,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,   206,    -1,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,
       3,     4,    -1,   252,    -1,    -1,   255,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,    -1,
     133,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,   157,    -1,    -1,   160,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   205,   206,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,   248,     3,     4,    -1,    -1,
     253,    -1,   255,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,    -1,   131,    -1,   133,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,
      -1,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,   252,    -1,    -1,   255,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,     3,     4,
      -1,   252,    -1,    -1,   255,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,     3,     4,    -1,   252,    -1,     8,
     255,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,    -1,   131,    -1,   133,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
      -1,   160,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,   206,    -1,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,     3,     4,    -1,    -1,   248,
       8,    -1,    10,    11,    12,    -1,   255,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,    -1,   131,    -1,   133,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,    -1,   160,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,    -1,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,   243,     3,     4,    -1,    -1,
     248,    -1,    -1,    10,    11,    12,    -1,   255,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,    -1,   131,    -1,   133,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,
      -1,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,   252,    -1,    -1,   255,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,     3,     4,
      -1,   252,    -1,    -1,   255,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,     3,
       4,     5,    -1,   248,    -1,    -1,    10,    11,    12,    -1,
     255,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,    93,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,    -1,
      -1,   255,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,   248,     3,     4,     5,   252,
      -1,    -1,   255,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    -1,    93,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,   252,    -1,    -1,   255,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,    -1,    -1,    -1,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,    -1,    -1,    -1,    -1,    -1,   243,     3,     4,
      -1,    -1,   248,    -1,    -1,    10,    11,    12,    -1,   255,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    88,    89,     8,    91,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   257,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,   252,    -1,    -1,
     255,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   205,   257,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,     3,     4,    -1,    -1,   248,    -1,    -1,    10,    11,
      12,    -1,   255,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,   201,
      -1,   247,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,
     212,   257,   214,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,
      -1,    -1,    -1,   255,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,   201,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,     3,     4,    -1,     6,   248,    -1,    -1,    10,    11,
      12,    -1,   255,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,   201,
      -1,   247,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,
     212,   257,   214,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,   255,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,   201,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,     3,     4,    -1,    -1,   248,    -1,    -1,    10,    11,
      12,    -1,   255,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    88,    89,    -1,    91,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,   205,   257,    -1,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,
      -1,    -1,    -1,   255,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,   205,   257,    -1,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,
      -1,    -1,    -1,   243,     3,     4,    -1,    -1,   248,   249,
      -1,    10,    11,    12,    -1,   255,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,
     202,   203,   204,    13,    14,    -1,   255,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,   217,    -1,   219,   220,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,   113,   114,   115,   116,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     252,    -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     178,   179,   180,   113,   114,   115,   116,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
     130,   131,    -1,   133,   134,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   178,   179,
     180,   113,   114,   115,   116,   253,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   178,   179,   180,   113,
     114,   115,   116,   253,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,   130,   131,    -1,   133,
     134,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   178,   179,   180,   113,   114,   115,
     116,   253,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,   130,   131,    -1,   133,   134,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   178,   179,   180,   113,   114,   115,   116,   253,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     178,   179,   180,   113,   114,   115,   116,   253,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
     130,   131,    -1,   133,   134,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   178,   179,
     180,   113,   114,   115,   116,   253,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   178,   179,   180,   113,
     114,   115,   116,   253,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,   130,   131,    -1,   133,
     134,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   178,   179,   180,   113,   114,   115,
     116,   253,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,   130,   131,    -1,   133,   134,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   178,   179,   180,   113,   114,   115,   116,   253,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    13,    14,    -1,
      -1,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
     178,   179,   180,   247,    -1,    -1,    -1,   253,    44,    45,
      -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,   253,   112,   113,   114,   115,
     116,   117,    -1,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,     4,    -1,
     166,   167,   168,    -1,    -1,    -1,   172,    13,    14,    -1,
      -1,   177,   178,   179,   180,    -1,    -1,   183,    -1,   185,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    44,    45,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,    -1,   220,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,   112,   113,   114,   115,
     116,   117,    -1,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,   178,   179,   180,     4,     5,   183,    -1,   185,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,    -1,   220,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,     4,     5,    -1,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,   116,    -1,    -1,
      59,    60,    61,    62,     4,     5,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,   133,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,     5,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,   213,    -1,    -1,    -1,   217,    -1,
     219,   220,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,   213,    -1,    -1,    -1,   217,    -1,
     219,   220,    -1,    -1,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,   257,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,    -1,   219,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,   217,    -1,   219,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    13,    14,    -1,   113,   114,   115,   116,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   158,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,   178,
     179,   180,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,   113,   114,   115,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   257,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,   253,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,   253,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,   253,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     253,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,   253,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,   253,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,   253,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     253,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,   253,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,   253,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,   253,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     253,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,   252,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,   252,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
     252,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,   249,    -1,   251,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,   251,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,   251,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   251,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,   251,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,   251,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   251,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,   251,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,   251,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
     251,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,   251,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,   251,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,   251,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   251,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,   251,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,   251,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   259,   260,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    75,    80,    81,    82,
      83,    84,    86,    87,    89,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   112,   113,   114,   115,   116,   117,   119,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   138,   139,   140,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   166,   167,   168,
     172,   177,   178,   179,   180,   183,   185,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   207,   208,   209,   218,   220,   261,   263,   264,   284,
     303,   305,   309,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   327,   329,   330,   336,   337,   338,   339,   345,
     370,   371,   252,   256,    14,   103,   248,   248,     6,   252,
       6,     6,     6,     6,   248,     6,     6,   252,     6,     6,
     250,   250,     4,   347,   371,   248,   250,   282,    97,   100,
     103,   105,   282,   248,   248,   248,     4,   248,   248,   248,
       4,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   252,   118,   103,     6,   252,    97,   100,   103,
     116,   308,   105,   248,     3,    10,    11,    12,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    55,    56,    57,
      58,    63,    64,    72,    73,    77,    78,    79,    88,    91,
      97,   100,   103,   105,   116,   126,   131,   133,   136,   201,
     205,   206,   210,   211,   212,   214,   215,   216,   236,   237,
     243,   248,   252,   255,   305,   306,   309,   320,   327,   329,
     340,   341,   345,   347,   354,   356,   371,   248,   252,   252,
     103,   103,   126,   100,   103,   105,    97,   100,   103,   105,
     305,   100,   103,   105,   116,   306,   100,   103,   248,   100,
     158,   183,   199,   200,   252,   236,   237,   248,   252,   351,
     352,   351,   252,   252,   351,     4,    97,   101,   107,   108,
     110,   111,   130,   252,   248,   103,   105,   103,   100,     4,
      89,   194,   252,   371,     4,     6,    97,   100,   103,   100,
     103,   116,   307,     4,     4,     4,     5,   248,   252,   354,
     355,     4,   248,   248,   248,     4,   252,   358,   371,     4,
     248,   248,   248,     6,     6,   250,     5,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    59,    60,    61,    62,
      67,    68,    69,    74,    76,    90,    93,   202,   203,   204,
     213,   217,   219,   362,   371,   248,     4,   362,     5,   252,
       5,   252,    32,   237,   340,   371,   250,   252,   248,   252,
       6,   248,   252,     6,   256,     7,   133,   194,   221,   222,
     223,   224,   244,   245,   248,   250,   254,   280,   281,   282,
     305,   340,   361,   362,   371,     4,   309,   310,   311,   252,
       6,   340,   361,   362,   371,   361,   340,   361,   368,   369,
     371,   340,   286,   290,   248,   350,     9,   362,   248,   248,
     248,   248,   371,   340,   340,   340,   248,   340,   340,   340,
     248,   340,   340,   340,   340,   340,   340,   340,   361,   340,
     340,   340,   340,   355,   248,   237,   340,   356,   357,   252,
     355,   354,   361,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   248,   250,   282,   282,
     282,   282,   282,   282,   248,   282,   282,   248,   305,   306,
     306,   282,   282,     5,   252,   252,   126,   305,   305,   248,
     282,   282,   248,   248,   248,   340,   252,   340,   356,   340,
     340,   253,   357,   347,   371,   186,     5,   252,     8,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   247,     9,   248,
     250,   254,   281,   282,   340,   357,   357,   248,   248,   248,
     354,   355,   355,   355,   304,   252,   248,   354,   252,   252,
     340,     4,   354,   252,   358,   252,   252,   351,   351,   351,
     340,   340,   236,   237,   252,   252,   351,   236,   237,   248,
     311,   351,   252,   248,   252,   248,   248,   248,   248,   248,
     248,   248,   357,   340,   355,   355,   355,   248,     4,   250,
     252,     6,   250,   311,     6,     6,   252,   252,   252,   252,
     355,   250,   250,   250,   340,     8,     6,     6,   340,   340,
     340,   254,   340,   252,   186,   340,   340,   340,   340,   282,
     282,   282,   248,   248,   248,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   248,   248,   282,   248,   250,
       6,     6,   252,     6,     8,   311,     6,     8,   311,   282,
     340,   238,   252,     9,   248,   250,   254,   361,   357,   340,
     311,   354,   354,   252,   362,   305,     7,   340,   340,     4,
     183,   184,   354,     6,   249,   251,   252,   283,   252,     6,
     252,     6,     9,   248,   250,   254,   371,   253,   126,   131,
     133,   134,   136,   303,   305,   340,     6,   249,   257,     9,
     248,   250,   254,   249,   257,   257,   249,   257,     9,   248,
     254,   257,   251,   257,   285,   251,   285,    92,   349,   346,
     371,   257,   340,   340,   340,   340,   257,   249,   249,   249,
     340,   249,   249,   249,   340,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   253,     7,   340,   238,
     253,   257,   340,     6,     6,   249,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   356,   340,   340,   340,   340,   340,   340,
     340,   356,   356,   371,   252,   340,   340,   361,   340,   361,
     354,   361,   361,   368,   252,   252,   252,   340,   283,   371,
       8,   340,   340,   355,   354,   361,   361,   356,   347,   362,
     347,   357,   249,   253,   254,   282,    64,     8,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   252,   340,   356,   340,   340,   340,   340,   340,
     371,   340,   340,     4,   348,   252,   283,   249,   253,   253,
     340,   340,   340,     7,     7,   333,   333,   248,   340,   340,
       6,   357,   357,   252,   249,     6,   311,   252,   311,   311,
     257,   257,   257,   351,   351,   310,   310,   257,   340,   253,
     324,   257,   311,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   253,   249,     7,   334,     6,     7,   340,     6,
     340,   311,   340,   253,   357,   357,   357,   340,     6,   340,
     340,   340,   249,   253,   249,   249,   249,   183,   257,   311,
     252,     8,   249,   249,   251,   368,   361,   368,   361,   361,
     361,   361,   361,   361,   340,   361,   361,   361,   361,   255,
     364,   371,   362,   361,   361,   361,   347,   371,   357,   253,
     253,   253,   253,   340,   340,   311,   371,   348,   251,   253,
     249,   140,   158,   328,   249,   253,   257,   340,     6,   252,
     354,   249,   251,     7,   280,   281,   254,     7,     6,   357,
       7,   221,   280,   340,   265,   371,   340,   340,   348,   250,
     248,   126,   305,   306,   305,   252,   253,     6,   232,   235,
     262,   357,   371,   340,   340,     4,   348,     6,   357,   340,
       6,   361,   369,   371,   249,   348,   340,     6,   371,     6,
     361,   340,   249,   250,   340,   257,   257,   257,   257,   362,
       7,     7,     7,   249,     7,     7,     7,   249,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   340,   249,
     252,   340,   356,   253,     6,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   257,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   257,   257,   257,   249,
     251,   251,   357,   257,   257,   283,   257,   283,   257,   257,
     257,   249,   357,   340,   340,   342,   283,   253,   253,   253,
     257,   257,   283,   283,   249,   254,   249,   254,   257,   282,
     343,   253,     7,   348,   283,   252,   253,     8,     8,   357,
     254,   249,   251,   281,   248,   250,   282,   357,     7,   252,
     252,   249,   249,   249,   340,   354,     4,   332,     6,   299,
     340,   362,   253,   249,   253,   253,   357,   254,   253,   311,
     253,   253,   351,   340,   340,   253,   253,   340,   351,   137,
     137,   155,   163,   164,   165,   169,   170,   325,   326,   351,
     253,   321,   249,   253,   249,   249,   249,   249,   249,   249,
     249,   252,     7,   340,     6,   340,   249,   251,   253,   251,
     253,   253,   253,   253,   251,   251,   257,     7,     7,     7,
     254,   340,   253,   340,   340,     7,   254,   283,   257,   283,
     283,   249,   249,   257,   283,   283,   257,   257,   283,   283,
     283,   283,   340,   283,     9,   363,   257,   249,   257,   283,
     254,   257,   344,   251,   253,   253,   254,   248,   250,   256,
     186,     7,   158,     6,   340,   253,   252,     6,   354,   253,
     340,     6,     7,   280,   281,   254,   280,   281,   362,   340,
       6,     4,   252,   359,   371,   253,    46,    46,   354,   253,
       4,   173,   174,   175,   176,   253,   268,   272,   275,   277,
     278,   254,   249,   251,   248,   340,   340,   248,   252,   248,
     252,     8,   357,   361,   249,   254,   249,   251,   248,   249,
     257,   254,   248,   257,     7,   282,     4,   293,   294,   295,
     283,   340,   340,   340,   340,   283,   351,   354,   354,     7,
     354,   354,   354,     7,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,     6,     7,   357,   340,   340,   340,
     340,   253,   340,   340,   340,   354,   361,   361,   253,   253,
     253,   257,   292,   340,   340,   348,   348,   340,   340,   249,
     354,   282,   340,   340,   340,   253,   348,   281,   254,   281,
     340,   340,   283,   253,   354,   357,   357,     7,     7,     7,
     137,   331,     6,   249,   257,     7,     7,     7,   253,     4,
     253,   257,   257,   257,   253,   253,   115,     4,     6,   340,
     252,     6,   248,     6,   171,     6,   171,   253,   326,   257,
     325,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     310,   354,     6,   252,     6,     6,     6,   103,     7,     6,
       6,   340,   354,   354,   354,     4,   257,     8,     8,   249,
       4,   106,   107,     4,   357,   361,   340,   361,   255,   257,
     296,   361,   361,   348,   361,   249,   257,   348,   252,   305,
     252,     6,   340,     6,   252,   354,   253,   253,   340,     6,
       4,   183,   184,   340,     6,     6,     6,     7,   358,   360,
       6,   250,   283,   282,   282,     6,   269,   248,   248,   252,
     279,     6,   348,   254,   361,   340,   251,   249,   340,     8,
     357,   340,   357,   253,   253,     6,     6,   262,   348,   254,
     340,     6,   340,   348,   249,   340,   252,   340,   362,   283,
      46,   252,   354,   362,   365,   251,   257,     6,   249,   249,
     249,   249,     6,     6,   130,   301,   301,   354,     6,     6,
       6,   354,   137,   186,   300,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   253,   283,   283,   283,   283,
     283,   257,   257,   257,   249,   283,   283,   294,   283,   249,
     283,   249,   282,   343,   283,     6,   283,   257,   248,   250,
     282,     4,   249,   251,   283,     6,   253,   253,   354,   354,
     354,     4,     6,   280,   340,   354,   252,   252,     7,     6,
       7,   340,   340,   340,   252,   252,   252,   250,     6,   340,
     354,   340,     6,     6,   340,   351,   253,     5,   354,   252,
     252,   252,   252,   252,   252,   252,   354,   253,     6,   357,
     252,   340,   251,     6,     6,   182,   340,   340,   340,     6,
       6,     6,     6,     7,   283,   257,   257,   283,   257,   340,
       4,   198,   297,   298,   283,   249,   283,   344,   362,   248,
     250,   340,   252,   311,     6,   311,   257,     6,     6,     7,
     280,   281,   254,     7,     6,   358,   253,   257,   340,   280,
     252,   283,   366,   367,   368,   366,   248,   340,   340,   353,
     354,   252,   248,     4,     6,   249,     6,   249,   253,   253,
     249,   253,     6,     6,   361,   248,     4,   249,   257,   248,
     253,   354,   362,     7,   282,   291,   340,   356,   295,     6,
       6,     6,     6,   351,     6,     6,     6,   137,   302,    97,
     116,   101,     6,     5,   252,   340,   340,   340,   340,   249,
     343,   340,   340,   340,   283,   281,   252,   252,     6,   300,
       6,   340,   354,     4,     6,   357,   357,   340,   340,   362,
     253,   249,   253,   257,   310,   310,   340,   340,   253,   257,
     249,   253,   257,     6,     6,   353,   351,   351,   351,   351,
     351,   237,   351,     6,   253,   340,     6,     6,   354,   253,
     257,     8,   253,   249,   252,   340,   362,   361,   340,   361,
     340,   362,   365,   367,   362,   257,   249,   257,   253,   340,
     328,   328,   354,   362,   340,     6,     4,   359,     6,   358,
     251,   354,   368,     6,   283,   283,   266,   340,   257,   257,
     253,   257,   267,   340,   340,     6,     6,     6,     6,   340,
     340,   249,     6,   287,   289,   252,   367,   253,   257,     7,
       7,   141,     6,   252,   252,   252,     5,   353,   283,   283,
     257,   283,   249,   257,   249,   251,   357,   357,     6,     6,
     252,   253,   253,   252,     6,     6,   252,   340,   253,   253,
     253,   251,     6,   354,     7,   252,   340,   253,   257,   257,
     257,   257,   257,   257,     6,   253,   181,   340,   340,   357,
       6,     6,   249,   283,   283,   298,   362,   253,   253,   253,
     253,     6,     6,     7,     6,   254,     6,   253,     6,     6,
     249,   257,   340,   340,   252,   354,   253,   257,   249,   249,
     257,   292,   296,   354,   283,   340,   362,   371,   357,   357,
     340,     6,   253,   340,   343,   340,   253,   253,   353,   142,
     143,   148,   335,   142,   143,   335,   357,   310,   253,   257,
       6,   253,   354,   311,   253,     6,   357,   351,   351,   351,
     351,   351,   340,   253,   253,   253,   249,     6,   252,     6,
     358,   184,   270,   340,   257,   257,   353,     6,   340,   340,
     253,   253,   288,     7,   248,   253,   253,   253,   252,   257,
     249,   257,   252,   253,   252,   351,   354,     6,   252,   351,
       6,   253,   253,   340,     6,   137,   253,   322,   252,   253,
     257,   257,   257,   257,   257,     6,     6,     6,   311,     6,
     252,   340,   340,   253,   257,   292,   362,   249,   340,   340,
     340,   357,     6,   351,     6,   351,     6,     6,   253,   340,
     325,   311,     6,   357,   357,   357,   357,   351,   357,   328,
     267,   249,   257,     6,   252,   340,   253,   257,   257,   257,
     253,   257,   257,     6,   253,   253,   323,   253,   253,   253,
     253,   257,   253,   253,   253,   273,   340,   353,   253,   340,
     340,   340,   351,   351,   325,     6,     6,     6,     6,   357,
       6,     6,     6,   252,   249,   253,     6,   253,   283,   257,
     257,   257,   253,   253,   271,   361,   276,   252,     6,   340,
     340,   340,     6,   253,   257,   252,   353,   253,   253,   253,
       6,   361,   274,   361,   253,     6,     6,   253,   257,     6,
       6,   361
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   258,   259,   259,   260,   260,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   262,   262,   263,   263,
     263,   263,   263,   263,   264,   264,   264,   264,   265,   265,
     265,   265,   265,   265,   266,   266,   267,   267,   269,   270,
     268,   271,   271,   273,   272,   274,   274,   276,   275,   277,
     277,   279,   278,   280,   280,   280,   280,   280,   281,   281,
     282,   282,   283,   283,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   285,   285,   286,   286,   286,   287,   286,   288,   286,
     286,   289,   286,   290,   290,   291,   291,   291,   292,   292,
     293,   293,   294,   294,   295,   295,   295,   295,   295,   296,
     296,   297,   297,   298,   298,   298,   298,   298,   299,   299,
     299,   300,   300,   300,   300,   301,   301,   302,   302,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   304,   303,   305,   305,   305,   305,   305,   306,   306,
     306,   306,   307,   307,   307,   308,   308,   308,   308,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   310,   310,
     311,   311,   311,   311,   311,   311,   311,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   314,   314,   315,
     316,   316,   316,   316,   316,   316,   316,   316,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   320,   320,   320,   321,   320,
     322,   320,   323,   320,   324,   320,   320,   320,   320,   320,
     320,   325,   325,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   327,   327,   327,   327,   327,   328,
     328,   328,   328,   328,   329,   329,   330,   331,   331,   332,
     332,   333,   333,   334,   334,   335,   335,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   337,   337,   337,   338,   338,   338,   339,
     339,   339,   339,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   342,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   343,   343,
     344,   344,   346,   345,   347,   347,   348,   349,   349,   350,
     350,   351,   351,   351,   351,   351,   352,   352,   352,   352,
     353,   353,   354,   354,   354,   354,   354,   354,   355,   355,
     355,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   357,   357,   357,   357,   358,   358,   358,
     358,   359,   359,   360,   360,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   363,   362,   362,   364,   364,
     365,   366,   366,   367,   368,   368,   368,   368,   369,   369,
     369,   370,   370,   370,   371,   371,   371
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       7,     7,     7,     9,     6,     6,     6,     8,     0,     2,
       2,     2,     2,     2,     1,     3,     1,     3,     0,     0,
      10,     1,     3,     0,    13,     1,     3,     0,    15,     8,
      14,     0,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     2,     7,     7,     4,
       3,     6,     9,     7,     6,     7,     6,     4,     8,     9,
       9,     6,     9,     6,     9,     5,     8,     8,    11,     6,
       9,     5,     7,     7,     7,     9,     9,    11,     7,     9,
       9,     0,     1,     0,     3,     5,     0,     9,     0,    11,
       5,     0,     9,     0,     3,     3,     5,     5,     0,     2,
       0,     1,     1,     3,     2,     1,     4,     2,     2,     0,
       2,     1,     3,     2,     2,     2,     2,     2,     1,     1,
       3,     0,     5,     5,     5,     0,     2,     0,     2,     7,
       7,     7,     8,     8,     7,     7,    11,     7,     8,     8,
       8,     9,     3,     4,    10,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     9,     7,     7,     8,     8,
      12,     0,     9,     1,     1,     1,     1,     4,     1,     1,
       1,     4,     1,     1,     4,     1,     1,     1,     4,     5,
      11,     5,     9,     9,     7,     4,     9,     9,     1,     1,
       0,     2,     6,     7,     7,     6,     7,     8,    10,    14,
      16,    12,    14,    14,    14,    14,     8,     8,     6,     4,
       5,     5,     6,     6,     3,     4,     3,     5,     6,     5,
       4,     3,     4,     3,     4,     5,     4,     5,     3,     5,
       7,     7,     3,     7,     3,     2,     2,     2,     2,     2,
      15,     2,     2,     2,     9,     2,     2,     2,     2,    16,
      11,     6,     8,     8,    10,     1,     2,     2,     1,     3,
       3,     4,     4,     1,     1,     5,    11,    13,     0,     7,
       0,    13,     0,    15,     0,     6,     9,     2,     3,    10,
      13,     1,     2,     5,     7,     2,     2,     3,     2,     3,
       2,     3,     9,     6,     1,     1,     1,     1,     1,     0,
       2,     3,     3,     4,     9,     4,    14,     0,     3,     0,
       1,     0,     2,     0,     2,     0,     2,     6,     7,     6,
       5,     3,     8,     8,     8,     8,     8,     5,     4,     6,
      11,    11,    18,    18,    12,    12,    12,    10,     4,     4,
       4,     4,     4,     2,     3,     6,     1,     1,     1,     2,
       5,     7,    10,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     1,     4,     6,     1,     4,     4,     4,
       6,     5,     7,     8,    10,     4,     4,     6,     4,     3,
       2,     5,     5,     3,     5,     6,     8,     6,     8,     6,
       4,     7,     6,     6,     6,     4,     6,     4,     0,     2,
       0,     2,     0,     7,     1,     3,     1,     1,     2,     0,
       3,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     1,     3,
       1,     2,     3,     3,     5,     4,     4,     2,     4,     2,
       3,     3,    16,     5,     5,     5,     1,     1,     1,     3,
       5,     7,     4,     4,     4,     6,     6,     8,     8,     4,
      14,     4,     4,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     4,     4,     3,
       5,     6,     8,     6,     4,     5,     1,     4,     1,     1,
       1,     1,     4,     6,     4,     6,     5,     7,     4,     4,
       4,     8,     4,     4,     4,     4,     8,     8,     6,     4,
       6,     4,     1,     4,     4,     0,     6,     4,     2,     4,
       4,     1,     1,     3,     1,     1,     3,     3,     3,     5,
       7,     5,     5,     8,     1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 3:
#line 271 "Gmsh.y" /* yacc.c:1652  */
    { yyerrok; return 1; }
#line 6034 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 282 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6040 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 283 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6046 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 284 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6052 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 286 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yyfactory = (yyvsp[-2].c);
      if(gmsh_yyfactory == "OpenCASCADE"){
        if(!GModel::current()->getOCCInternals())
          GModel::current()->createOCCInternals();
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getOCCInternals()->setMaxTag
            (dim, std::max(GModel::current()->getOCCInternals()->getMaxTag(dim),
                           GModel::current()->getGEOInternals()->getMaxTag(dim)));
      }
      else if(GModel::current()->getOCCInternals()){
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getGEOInternals()->setMaxTag
            (dim, std::max(GModel::current()->getGEOInternals()->getMaxTag(dim),
                           GModel::current()->getOCCInternals()->getMaxTag(dim)));
      }
      Free((yyvsp[-2].c));
    }
#line 6075 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 304 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6081 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 305 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6087 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 306 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6093 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 307 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6099 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 308 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6105 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 309 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6111 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 310 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6117 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 311 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6123 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 312 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6129 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 313 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6135 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 314 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6141 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 315 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6147 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 316 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6153 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 317 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6159 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 318 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6165 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 319 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6171 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 324 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"w";
    }
#line 6179 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 328 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"a";
    }
#line 6187 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 335 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6196 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 340 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6205 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 345 "Gmsh.y" /* yacc.c:1652  */
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
#line 6223 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 359 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    }
#line 6240 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 372 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring);
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    }
#line 6257 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 385 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstring[5000];
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
	  fprintf(fp, "%s\n", tmpstring);
	  fclose(fp);
	}
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[-4].l));
    }
#line 6284 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 413 "Gmsh.y" /* yacc.c:1652  */
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
#line 6302 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 427 "Gmsh.y" /* yacc.c:1652  */
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
#line 6319 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 440 "Gmsh.y" /* yacc.c:1652  */
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
#line 6336 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 453 "Gmsh.y" /* yacc.c:1652  */
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
#line 6355 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 471 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 6365 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 485 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6371 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 487 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6377 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 492 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6383 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 494 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6389 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 499 "Gmsh.y" /* yacc.c:1652  */
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
#line 6497 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 603 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(std::size_t j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 6511 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 613 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 6521 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 622 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6532 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 629 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6543 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 639 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 6556 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 648 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 6566 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 657 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6577 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 664 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6588 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 674 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 6600 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 682 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 6610 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 692 "Gmsh.y" /* yacc.c:1652  */
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
#line 6630 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 711 "Gmsh.y" /* yacc.c:1652  */
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
#line 6650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 730 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 6660 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 736 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 6667 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 743 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 6673 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 744 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6679 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 745 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 6685 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 746 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 6691 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 747 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 4; }
#line 6697 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 751 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6703 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 752 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = -1; }
#line 6709 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 758 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"("; }
#line 6715 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 758 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"["; }
#line 6721 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 759 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)")"; }
#line 6727 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 759 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"]"; }
#line 6733 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 77:
#line 769 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 6742 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 78:
#line 774 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 6752 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 79:
#line 780 "Gmsh.y" /* yacc.c:1652  */
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
              std::vector<double>::iterator it = std::find(s.value.begin(),
                                                           s.value.end(), d);
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
#line 6818 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 80:
#line 842 "Gmsh.y" /* yacc.c:1652  */
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
#line 6837 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 81:
#line 857 "Gmsh.y" /* yacc.c:1652  */
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
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
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
#line 6870 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 82:
#line 886 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 6881 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 83:
#line 896 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6890 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 84:
#line 901 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6899 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 85:
#line 909 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6908 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 86:
#line 914 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6917 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 87:
#line 922 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 6927 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 88:
#line 931 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 6936 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 89:
#line 936 "Gmsh.y" /* yacc.c:1652  */
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
#line 6952 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 90:
#line 948 "Gmsh.y" /* yacc.c:1652  */
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
#line 6970 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 91:
#line 965 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6980 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 92:
#line 971 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6990 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 93:
#line 980 "Gmsh.y" /* yacc.c:1652  */
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
#line 7012 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 94:
#line 998 "Gmsh.y" /* yacc.c:1652  */
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
#line 7034 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 95:
#line 1016 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 7047 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 96:
#line 1025 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 7060 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 97:
#line 1037 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 7069 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 98:
#line 1042 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 7078 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 99:
#line 1050 "Gmsh.y" /* yacc.c:1652  */
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
#line 7102 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 100:
#line 1070 "Gmsh.y" /* yacc.c:1652  */
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
#line 7126 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 101:
#line 1093 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      if(!strcmp((yyvsp[-4].c),"Background")) {
	if (tags.size() > 1)
	  yymsg(0, "Only 1 field can be set as a background field.");
	else if (tags.size() == 0)
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
#line 7150 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 102:
#line 1113 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 7162 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 103:
#line 1121 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Box");
#endif
    }
#line 7173 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 104:
#line 1128 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Cylinder");
#endif
    }
#line 7184 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 105:
#line 1135 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-6].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-3].c)];
	if(option){
	  try { option->numericalValue((yyvsp[-1].d)); }
	  catch(...){
	    yymsg(0, "Cannot assign a numerical value to option '%s' "
		  "in field %i of type '%s'", (yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
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
    }
#line 7210 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 106:
#line 1157 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-6].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-3].c)];
	if(option){
	  try { option->string((yyvsp[-1].c)); }
	  catch (...){
	    yymsg(0, "Cannot assign a string value to  option '%s' "
		  "in field %i of type '%s'", (yyvsp[-3].c), (int)(yyvsp[-6].d), field->getName());
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
      Free((yyvsp[-1].c));
    }
#line 7237 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 107:
#line 1180 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[-8].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[-5].c)];
	if(option){
	  if (option->getType() == FIELD_OPTION_LIST) {
	    std::list<int> vl = option->list();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	      double id;
	      List_Read((yyvsp[-2].l), i, &id);
	      vl.push_back((int)id);
	    }
	    option->list(vl);
	  }
	  else {
	    std::list<double> vl = option->listdouble();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	      double id;
	      List_Read((yyvsp[-2].l), i, &id);
	      vl.push_back(id);
	    }
	    option->listdouble(vl);
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[-5].c), (int)(yyvsp[-8].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[-8].d));
#endif
      Free((yyvsp[-5].c));
      List_Delete((yyvsp[-2].l));
    }
#line 7279 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 108:
#line 1218 "Gmsh.y" /* yacc.c:1652  */
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
#line 7301 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 109:
#line 1239 "Gmsh.y" /* yacc.c:1652  */
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
#line 7317 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 110:
#line 1251 "Gmsh.y" /* yacc.c:1652  */
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
#line 7333 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 114:
#line 1269 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 7346 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 115:
#line 1278 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 7359 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 116:
#line 1287 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7365 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 117:
#line 1289 "Gmsh.y" /* yacc.c:1652  */
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
#line 7387 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 118:
#line 1307 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7393 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 119:
#line 1309 "Gmsh.y" /* yacc.c:1652  */
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
#line 7413 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 120:
#line 1325 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 7426 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 121:
#line 1334 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7432 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 122:
#line 1336 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 7446 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 124:
#line 1350 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 7456 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 125:
#line 1358 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7466 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 126:
#line 1364 "Gmsh.y" /* yacc.c:1652  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7475 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 127:
#line 1369 "Gmsh.y" /* yacc.c:1652  */
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
#line 7504 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 134:
#line 1412 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
        double v;
        List_Read((yyvsp[0].l), i, &v);
        floatOptions[key].push_back(v);
        if (flag_Enum && !i) { member_ValMax = (int)v; }
      }
      Free((yyvsp[-1].c));
      List_Delete((yyvsp[0].l));
    }
#line 7520 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 135:
#line 1424 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[0].c));
      double v;
      if (!flag_Enum) {
        v = 1.;
        if (key == "Enum") flag_Enum = 1;
      }
      else
        v = (double)++member_ValMax;
      floatOptions[key].push_back(v);
      Free((yyvsp[0].c));
    }
#line 7537 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 136:
#line 1437 "Gmsh.y" /* yacc.c:1652  */
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
#line 7555 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 137:
#line 1452 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7567 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 138:
#line 1461 "Gmsh.y" /* yacc.c:1652  */
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
#line 7582 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 143:
#line 1486 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 7593 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 144:
#line 1494 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7605 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 145:
#line 1503 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 7616 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 146:
#line 1511 "Gmsh.y" /* yacc.c:1652  */
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
#line 7633 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 147:
#line 1525 "Gmsh.y" /* yacc.c:1652  */
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
#line 7650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 148:
#line 1543 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 7658 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 149:
#line 1547 "Gmsh.y" /* yacc.c:1652  */
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[0].c)), dim_entity, t + 1);
      Free((yyvsp[0].c));
    }
#line 7669 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 150:
#line 1554 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), dim_entity, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 7678 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 151:
#line 1562 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 7686 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 152:
#line 1566 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[-1].d);
      List_Add((yyval.l), &p);
    }
#line 7696 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 153:
#line 1572 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7704 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 154:
#line 1576 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[-1].l), i));
      List_Delete((yyvsp[-1].l));
    }
#line 7717 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 155:
#line 1587 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 7725 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 156:
#line 1591 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 7733 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 157:
#line 1597 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = 0;
    }
#line 7741 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 158:
#line 1601 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = 1;
    }
#line 7749 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 159:
#line 1607 "Gmsh.y" /* yacc.c:1652  */
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
#line 7776 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 160:
#line 1630 "Gmsh.y" /* yacc.c:1652  */
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
#line 7796 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 161:
#line 1646 "Gmsh.y" /* yacc.c:1652  */
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
#line 7816 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 162:
#line 1662 "Gmsh.y" /* yacc.c:1652  */
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
#line 7857 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 163:
#line 1699 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-5].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-2].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(tags.size() == 3){
          r = GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() == 7) ? param[5] : 0.;
          double a2 = (param.size() == 7) ? param[6] :
            (param.size() == 6) ? param[5] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 3 points, or 5 to 7 parameters");
        }
      }
      else{
        if(tags.size() == 4){
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
#line 7897 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 164:
#line 1735 "Gmsh.y" /* yacc.c:1652  */
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
#line 7917 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 165:
#line 1751 "Gmsh.y" /* yacc.c:1652  */
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
#line 7937 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 166:
#line 1768 "Gmsh.y" /* yacc.c:1652  */
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
#line 7972 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 167:
#line 1799 "Gmsh.y" /* yacc.c:1652  */
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
#line 7992 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 168:
#line 1815 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addLineLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addLineLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add line loop");
      List_Delete((yyvsp[-1].l));
      Free((yyvsp[-6].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    }
#line 8013 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 169:
#line 1832 "Gmsh.y" /* yacc.c:1652  */
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
#line 8033 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 170:
#line 1848 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-5].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-2].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE surface filling requires a single line loop");
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
#line 8087 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 171:
#line 1898 "Gmsh.y" /* yacc.c:1652  */
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
#line 8109 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 172:
#line 1916 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8119 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 173:
#line 1922 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8129 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 174:
#line 1928 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 8140 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 175:
#line 1935 "Gmsh.y" /* yacc.c:1652  */
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
#line 8175 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 176:
#line 1966 "Gmsh.y" /* yacc.c:1652  */
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
#line 8194 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 177:
#line 1981 "Gmsh.y" /* yacc.c:1652  */
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
#line 8220 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 178:
#line 2003 "Gmsh.y" /* yacc.c:1652  */
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
#line 8247 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 179:
#line 2026 "Gmsh.y" /* yacc.c:1652  */
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
#line 8274 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 180:
#line 2049 "Gmsh.y" /* yacc.c:1652  */
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
#line 8301 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 181:
#line 2072 "Gmsh.y" /* yacc.c:1652  */
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
#line 8329 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 182:
#line 2096 "Gmsh.y" /* yacc.c:1652  */
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
#line 8357 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 183:
#line 2120 "Gmsh.y" /* yacc.c:1652  */
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
#line 8385 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 184:
#line 2144 "Gmsh.y" /* yacc.c:1652  */
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
#line 8415 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 185:
#line 2170 "Gmsh.y" /* yacc.c:1652  */
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
#line 8436 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 186:
#line 2187 "Gmsh.y" /* yacc.c:1652  */
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
#line 8456 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 187:
#line 2203 "Gmsh.y" /* yacc.c:1652  */
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
#line 8478 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 188:
#line 2221 "Gmsh.y" /* yacc.c:1652  */
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
#line 8500 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 189:
#line 2239 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-6].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8511 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 190:
#line 2247 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-10].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8522 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 191:
#line 2254 "Gmsh.y" /* yacc.c:1652  */
    {
      dim_entity = (yyvsp[0].i);
    }
#line 8530 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 192:
#line 2258 "Gmsh.y" /* yacc.c:1652  */
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
#line 8557 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 193:
#line 2284 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8563 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 194:
#line 2286 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8569 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 195:
#line 2288 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8575 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 196:
#line 2290 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8581 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 197:
#line 2292 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
#line 8590 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 198:
#line 2300 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8596 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 199:
#line 2302 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8602 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 200:
#line 2304 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8608 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 201:
#line 2306 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
#line 8617 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 202:
#line 2314 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8623 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 203:
#line 2316 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8629 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 204:
#line 2318 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
#line 8638 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 205:
#line 2326 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8644 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 206:
#line 2328 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 207:
#line 2330 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8656 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 208:
#line 2332 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
#line 8665 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 209:
#line 2342 "Gmsh.y" /* yacc.c:1652  */
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
#line 8685 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 210:
#line 2358 "Gmsh.y" /* yacc.c:1652  */
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
#line 8705 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 211:
#line 2374 "Gmsh.y" /* yacc.c:1652  */
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
#line 8725 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 212:
#line 2390 "Gmsh.y" /* yacc.c:1652  */
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
#line 8745 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 213:
#line 2406 "Gmsh.y" /* yacc.c:1652  */
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
#line 8765 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 214:
#line 2422 "Gmsh.y" /* yacc.c:1652  */
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
#line 8786 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 215:
#line 2439 "Gmsh.y" /* yacc.c:1652  */
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
              action == "PointsOf"){
        // boundary operations are performed directly on GModel, which enables
        // to compute the boundary of hybrid CAD models; this also automatically
        // binds all boundary entities for OCC models
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        r = GModel::current()->getBoundaryTags
          (inDimTags, outDimTags, action == "CombinedBoundary", true,
           action == "PointsOf");
      }
      else{
        yymsg(0, "Unknown action on multiple shapes '%s'", (yyvsp[-3].c));
      }
      if(!r) yymsg(0, "Could not apply operation on shapes");
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[-3].c));
    }
#line 8827 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 216:
#line 2476 "Gmsh.y" /* yacc.c:1652  */
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
#line 8852 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 217:
#line 2498 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Line not available with OpenCASCADE geometry kernel");
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
      if(!r) yymsg(0, "Could not split line");
      List_Delete((yyvsp[-2].l));
    }
#line 8877 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 218:
#line 2521 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8883 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 219:
#line 2522 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8889 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 220:
#line 2527 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 8897 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 221:
#line 2531 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 8905 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 222:
#line 2535 "Gmsh.y" /* yacc.c:1652  */
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
#line 8926 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 223:
#line 2552 "Gmsh.y" /* yacc.c:1652  */
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
#line 8950 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 224:
#line 2572 "Gmsh.y" /* yacc.c:1652  */
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
#line 8974 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 225:
#line 2592 "Gmsh.y" /* yacc.c:1652  */
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
#line 8997 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 226:
#line 2611 "Gmsh.y" /* yacc.c:1652  */
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
#line 9023 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 227:
#line 2638 "Gmsh.y" /* yacc.c:1652  */
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
#line 9046 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 228:
#line 2657 "Gmsh.y" /* yacc.c:1652  */
    {
      int t = (int)(yyvsp[-6].d);
      if(gLevelset::find(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	fullMatrix<double> centers(List_Nbr((yyvsp[-2].l)),3);
	for (int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[-2].l), i);
	  for (int j = 0; j < List_Nbr(l); j++){
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
#line 9071 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 229:
#line 2679 "Gmsh.y" /* yacc.c:1652  */
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
#line 9089 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 230:
#line 2694 "Gmsh.y" /* yacc.c:1652  */
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
#line 9108 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 231:
#line 2709 "Gmsh.y" /* yacc.c:1652  */
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
#line 9130 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 232:
#line 2728 "Gmsh.y" /* yacc.c:1652  */
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
#line 9184 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 233:
#line 2779 "Gmsh.y" /* yacc.c:1652  */
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
#line 9208 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 234:
#line 2800 "Gmsh.y" /* yacc.c:1652  */
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
#line 9233 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 235:
#line 2822 "Gmsh.y" /* yacc.c:1652  */
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
#line 9259 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 236:
#line 2844 "Gmsh.y" /* yacc.c:1652  */
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
          gLevelset *ls = NULL;
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
#line 9368 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 237:
#line 2949 "Gmsh.y" /* yacc.c:1652  */
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
#line 9388 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 238:
#line 2965 "Gmsh.y" /* yacc.c:1652  */
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
#line 9422 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 239:
#line 3000 "Gmsh.y" /* yacc.c:1652  */
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
        GModel::current()->remove(dimTags);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 9448 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 240:
#line 3022 "Gmsh.y" /* yacc.c:1652  */
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
        GModel::current()->remove(dimTags, true);
      }
      List_Delete((yyvsp[-1].l));
    }
#line 9474 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 241:
#line 3044 "Gmsh.y" /* yacc.c:1652  */
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
#line 9490 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 242:
#line 3056 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 9500 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 243:
#line 3062 "Gmsh.y" /* yacc.c:1652  */
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
#line 9519 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 244:
#line 3077 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!strcmp((yyvsp[-1].c), "Meshes") || !strcmp((yyvsp[-1].c), "All")){
        ClearProject();
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
#line 9551 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 245:
#line 3105 "Gmsh.y" /* yacc.c:1652  */
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
#line 9567 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 246:
#line 3117 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yynamespaces.clear();
    }
#line 9575 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 247:
#line 3126 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), false);
      List_Delete((yyvsp[-1].l));
    }
#line 9586 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 248:
#line 3133 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), true);
      List_Delete((yyvsp[-1].l));
    }
#line 9597 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 249:
#line 3145 "Gmsh.y" /* yacc.c:1652  */
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
#line 9616 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 250:
#line 3165 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
    }
#line 9624 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 251:
#line 3169 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[-1].c));
    }
#line 9633 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 252:
#line 3174 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
    }
#line 9641 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 253:
#line 3178 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[-1].c));
    }
#line 9650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 254:
#line 3183 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9661 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 255:
#line 3190 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9672 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 256:
#line 3197 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9683 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 257:
#line 3204 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9694 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 258:
#line 3216 "Gmsh.y" /* yacc.c:1652  */
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
#line 9771 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 259:
#line 3289 "Gmsh.y" /* yacc.c:1652  */
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
#line 9793 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 260:
#line 3307 "Gmsh.y" /* yacc.c:1652  */
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
#line 9822 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 261:
#line 3332 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp((yyvsp[-6].c), "Background") && !strcmp((yyvsp[-5].c), "Mesh")  && !strcmp((yyvsp[-4].c), "View")){
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
#line 9841 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 262:
#line 3347 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!strcmp((yyvsp[-2].c), "Sleep")){
	SleepInSeconds((yyvsp[-1].d));
      }
      else if(!strcmp((yyvsp[-2].c), "Remesh")){
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[-2].c), "Mesh")){
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
      else if(!strcmp((yyvsp[-2].c), "SetOrder")){
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), (yyvsp[-1].d), CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else if(!strcmp((yyvsp[-2].c), "PartitionMesh")){
        GModel::current()->partitionMesh((yyvsp[-1].d));
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 9878 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 263:
#line 3380 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_PLUGINS)
       try {
	 PluginManager::instance()->action((yyvsp[-4].c), (yyvsp[-1].c), 0);
       }
       catch(...) {
	 yymsg(0, "Unknown action '%s' or plugin '%s'", (yyvsp[-1].c), (yyvsp[-4].c));
       }
#endif
       Free((yyvsp[-4].c)); Free((yyvsp[-1].c));
     }
#line 9894 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 264:
#line 3392 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-1].c), "ElementsFromAllViews"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[-1].c), "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[-1].c));
    }
#line 9922 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 265:
#line 3416 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Exit(0);
    }
#line 9930 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 266:
#line 3420 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 9939 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 267:
#line 3425 "Gmsh.y" /* yacc.c:1652  */
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
#line 9950 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 268:
#line 3432 "Gmsh.y" /* yacc.c:1652  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 9959 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 269:
#line 3437 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
#line 9973 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 270:
#line 3447 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 9982 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 271:
#line 3452 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 9992 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 272:
#line 3458 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 10004 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 273:
#line 3466 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 10012 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 274:
#line 3470 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->classifySurfaces((yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 10020 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 275:
#line 3474 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    }
#line 10028 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 276:
#line 3478 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshVertices();
    }
#line 10036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 277:
#line 3482 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshElements();
    }
#line 10044 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 278:
#line 3486 "Gmsh.y" /* yacc.c:1652  */
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 10057 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 279:
#line 3496 "Gmsh.y" /* yacc.c:1652  */
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
#line 10119 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 280:
#line 3559 "Gmsh.y" /* yacc.c:1652  */
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
#line 10135 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 281:
#line 3575 "Gmsh.y" /* yacc.c:1652  */
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
#line 10156 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 282:
#line 3592 "Gmsh.y" /* yacc.c:1652  */
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
#line 10177 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 283:
#line 3609 "Gmsh.y" /* yacc.c:1652  */
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
#line 10203 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 284:
#line 3631 "Gmsh.y" /* yacc.c:1652  */
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
#line 10229 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 285:
#line 3653 "Gmsh.y" /* yacc.c:1652  */
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
#line 10268 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 286:
#line 3688 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10280 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 287:
#line 3696 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10292 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 288:
#line 3704 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 10302 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 289:
#line 3710 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10313 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 290:
#line 3717 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10324 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 291:
#line 3724 "Gmsh.y" /* yacc.c:1652  */
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
#line 10348 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 292:
#line 3744 "Gmsh.y" /* yacc.c:1652  */
    {
      if(ImbricatedTest > 0){
        if (statusImbricatedTests[ImbricatedTest]){
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
#line 10378 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 293:
#line 3770 "Gmsh.y" /* yacc.c:1652  */
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
#line 10394 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 294:
#line 3782 "Gmsh.y" /* yacc.c:1652  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 10404 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 295:
#line 3793 "Gmsh.y" /* yacc.c:1652  */
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
#line 10426 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 296:
#line 3811 "Gmsh.y" /* yacc.c:1652  */
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
#line 10448 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 297:
#line 3829 "Gmsh.y" /* yacc.c:1652  */
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
#line 10470 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 298:
#line 3847 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10480 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 299:
#line 3853 "Gmsh.y" /* yacc.c:1652  */
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
#line 10502 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 300:
#line 3871 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10512 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 301:
#line 3877 "Gmsh.y" /* yacc.c:1652  */
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
#line 10536 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 302:
#line 3897 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10546 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 303:
#line 3903 "Gmsh.y" /* yacc.c:1652  */
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
#line 10568 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 304:
#line 3921 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10578 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 305:
#line 3927 "Gmsh.y" /* yacc.c:1652  */
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
#line 10599 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 306:
#line 3944 "Gmsh.y" /* yacc.c:1652  */
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
#line 10619 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 307:
#line 3960 "Gmsh.y" /* yacc.c:1652  */
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
#line 10640 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 308:
#line 3977 "Gmsh.y" /* yacc.c:1652  */
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
#line 10661 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 309:
#line 3995 "Gmsh.y" /* yacc.c:1652  */
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
#line 10687 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 310:
#line 4018 "Gmsh.y" /* yacc.c:1652  */
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
#line 10715 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 311:
#line 4045 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10722 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 312:
#line 4048 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10729 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 313:
#line 4054 "Gmsh.y" /* yacc.c:1652  */
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
#line 10745 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 314:
#line 4066 "Gmsh.y" /* yacc.c:1652  */
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
#line 10769 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 315:
#line 4086 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 10777 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 316:
#line 4090 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = true;
    }
#line 10785 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 317:
#line 4094 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 10793 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 318:
#line 4098 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 10801 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 319:
#line 4102 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 10809 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 320:
#line 4106 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 10817 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 321:
#line 4110 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 10825 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 322:
#line 4114 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      int num = (int)(yyvsp[-6].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[-1].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[-3].l));
    }
#line 10838 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 323:
#line 4123 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 10850 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 324:
#line 4135 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Union; }
#line 10856 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 325:
#line 4136 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Intersection; }
#line 10862 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 326:
#line 4137 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Difference; }
#line 10868 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 327:
#line 4138 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Section; }
#line 10874 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 328:
#line 4139 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Fragments; }
#line 10880 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 329:
#line 4143 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 10886 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 330:
#line 4144 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 10892 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 331:
#line 4145 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 10898 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 332:
#line 4146 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 1 : 0; }
#line 10904 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 333:
#line 4147 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 2 : 0; }
#line 10910 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 334:
#line 4152 "Gmsh.y" /* yacc.c:1652  */
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
#line 10937 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 335:
#line 4175 "Gmsh.y" /* yacc.c:1652  */
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
#line 10957 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 336:
#line 4195 "Gmsh.y" /* yacc.c:1652  */
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
#line 10979 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 337:
#line 4216 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 10987 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 338:
#line 4220 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!strcmp((yyvsp[-1].c), "Progression") || !strcmp((yyvsp[-1].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[-1].c), "Bump"))
        (yyval.v)[0] = 2.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[0].d);
      Free((yyvsp[-1].c));
    }
#line 11004 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 339:
#line 4235 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = -1; // left
    }
#line 11012 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 340:
#line 4239 "Gmsh.y" /* yacc.c:1652  */
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
#line 11030 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 341:
#line 4255 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 11038 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 342:
#line 4259 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 11046 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 343:
#line 4264 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = 45;
    }
#line 11054 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 344:
#line 4268 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 11062 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 345:
#line 4274 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 11070 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 346:
#line 4278 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11078 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 347:
#line 4285 "Gmsh.y" /* yacc.c:1652  */
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
#line 11104 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 348:
#line 4307 "Gmsh.y" /* yacc.c:1652  */
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      int type = (int)(yyvsp[-1].v)[0];
      double coef = fabs((yyvsp[-1].v)[1]);
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
#line 11149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 349:
#line 4348 "Gmsh.y" /* yacc.c:1652  */
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
#line 11197 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 350:
#line 4392 "Gmsh.y" /* yacc.c:1652  */
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
#line 11240 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 351:
#line 4431 "Gmsh.y" /* yacc.c:1652  */
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
#line 11269 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 352:
#line 4456 "Gmsh.y" /* yacc.c:1652  */
    {
      int tag = (int)(yyvsp[-4].d);
      GVertex *gf = GModel::current()->getVertexByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[-2].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown Model Vertex %d",tag);
      }
    }
#line 11285 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 353:
#line 4468 "Gmsh.y" /* yacc.c:1652  */
    {
      int tag = (int)(yyvsp[-4].d);
      GEdge *gf = GModel::current()->getEdgeByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[-2].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown Model Edge %d",tag);
      }
    }
#line 11301 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 354:
#line 4480 "Gmsh.y" /* yacc.c:1652  */
    {
      int tag = (int)(yyvsp[-4].d);
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[-2].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown Model Face %d",tag);
      }
    }
#line 11317 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 355:
#line 4492 "Gmsh.y" /* yacc.c:1652  */
    {
      int tag = (int)(yyvsp[-4].d);
      GRegion *gf = GModel::current()->getRegionByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[-2].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown Model Region %d",tag);
      }
    }
#line 11333 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 356:
#line 4504 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[-1].d);
      }
      List_Delete((yyvsp[-4].l));
    }
#line 11346 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 357:
#line 4513 "Gmsh.y" /* yacc.c:1652  */
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
#line 11380 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 358:
#line 4543 "Gmsh.y" /* yacc.c:1652  */
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
#line 11410 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 359:
#line 4569 "Gmsh.y" /* yacc.c:1652  */
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
#line 11440 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 360:
#line 4596 "Gmsh.y" /* yacc.c:1652  */
    {
      if (List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-3].l))){
        yymsg(0, "Number of master lines (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr((yyvsp[-1].l)) != 0) {
          if (List_Nbr((yyvsp[-1].l)) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries (we have %d)",
                  List_Nbr((yyvsp[-1].l)));
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
#line 11475 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 361:
#line 4628 "Gmsh.y" /* yacc.c:1652  */
    {
      if (List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-3].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-3].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        if (List_Nbr((yyvsp[-1].l)) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries");
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
#line 11505 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 362:
#line 4655 "Gmsh.y" /* yacc.c:1652  */
    {
      if (List_Nbr((yyvsp[-14].l)) != List_Nbr((yyvsp[-10].l))){
        yymsg(0, "Number of master curves (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-10].l)), List_Nbr((yyvsp[-14].l)));
      }
      else{
        SPoint3 axis((yyvsp[-6].v)[0],(yyvsp[-6].v)[1],(yyvsp[-6].v)[2]);
        SPoint3 origin((yyvsp[-4].v)[0],(yyvsp[-4].v)[1],(yyvsp[-4].v)[2]);
        double  angle((yyvsp[-2].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

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
#line 11534 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 363:
#line 4681 "Gmsh.y" /* yacc.c:1652  */
    {
      if (List_Nbr((yyvsp[-14].l)) != List_Nbr((yyvsp[-10].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-10].l)), List_Nbr((yyvsp[-14].l)));
      }
      else{
        SPoint3 origin((yyvsp[-4].v)[0],(yyvsp[-4].v)[1],(yyvsp[-4].v)[2]);
        SPoint3 axis((yyvsp[-6].v)[0],(yyvsp[-6].v)[1],(yyvsp[-6].v)[2]);
        double  angle((yyvsp[-2].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

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
#line 11563 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 364:
#line 4707 "Gmsh.y" /* yacc.c:1652  */
    {
      if (List_Nbr((yyvsp[-8].l)) != List_Nbr((yyvsp[-4].l))){
        yymsg(0, "Number of master curves (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-8].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[-1].v)[0],(yyvsp[-1].v)[1],(yyvsp[-1].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

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
#line 11592 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 365:
#line 4733 "Gmsh.y" /* yacc.c:1652  */
    {
      if (List_Nbr((yyvsp[-8].l)) != List_Nbr((yyvsp[-4].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[-4].l)), List_Nbr((yyvsp[-8].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[-1].v)[0],(yyvsp[-1].v)[1],(yyvsp[-1].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

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
#line 11621 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 366:
#line 4759 "Gmsh.y" /* yacc.c:1652  */
    {
      if (List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-2].l))){
        yymsg(0, "Number of master surface curves (%d) different from number of "
              "slave (%d) curves", List_Nbr((yyvsp[-2].l)), List_Nbr((yyvsp[-7].l)));
      }
      else{
        int j_master = (int)(yyvsp[-4].d);
        int j_slave = (int)(yyvsp[-9].d);
        std::map<int,int> edgeCounterParts;
        for (int i = 0; i < List_Nbr((yyvsp[-7].l)); i++){
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
#line 11646 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 367:
#line 4780 "Gmsh.y" /* yacc.c:1652  */
    {
      if (((yyvsp[-4].i)==2 || (yyvsp[-4].i)==3) && (yyvsp[-9].i)<(yyvsp[-4].i) ) {
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[-7].l), tags);
        addEmbedded((yyvsp[-9].i), tags, (yyvsp[-4].i), (int)(yyvsp[-2].d));
      }
      else {
        yymsg(0, "GeoEntity of dim %d In GeoEntity of dim %d not allowed", (yyvsp[-9].i), (yyvsp[-4].i));
      }
      List_Delete((yyvsp[-7].l));
    }
#line 11661 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 368:
#line 4791 "Gmsh.y" /* yacc.c:1652  */
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
#line 11713 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 369:
#line 4839 "Gmsh.y" /* yacc.c:1652  */
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
#line 11771 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 370:
#line 4893 "Gmsh.y" /* yacc.c:1652  */
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
#line 11790 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 371:
#line 4908 "Gmsh.y" /* yacc.c:1652  */
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
#line 11806 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 372:
#line 4920 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-2].i), tags);
      List_Delete((yyvsp[-1].l));
    }
#line 11816 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 373:
#line 4931 "Gmsh.y" /* yacc.c:1652  */
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
#line 11827 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 374:
#line 4938 "Gmsh.y" /* yacc.c:1652  */
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
#line 11846 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 375:
#line 4953 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[-2].l));
    }
#line 11859 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 376:
#line 4966 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Homology"; }
#line 11865 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 377:
#line 4967 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 11871 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 378:
#line 4968 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Betti"; }
#line 11877 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 379:
#line 4973 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 11887 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 380:
#line 4979 "Gmsh.y" /* yacc.c:1652  */
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
#line 11903 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 381:
#line 4991 "Gmsh.y" /* yacc.c:1652  */
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
#line 11925 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 382:
#line 5009 "Gmsh.y" /* yacc.c:1652  */
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
#line 11952 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 383:
#line 5036 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11958 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 384:
#line 5037 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 11964 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 385:
#line 5038 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 11970 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 386:
#line 5039 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11976 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 387:
#line 5040 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 11982 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 388:
#line 5041 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 11988 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 389:
#line 5042 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 11994 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 390:
#line 5043 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 12000 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 391:
#line 5045 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 12011 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 392:
#line 5051 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) | (int)(yyvsp[0].d); }
#line 12017 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 393:
#line 5052 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) & (int)(yyvsp[0].d); }
#line 12023 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 394:
#line 5053 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d); }
#line 12029 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 395:
#line 5054 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 12035 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 396:
#line 5055 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 12041 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 397:
#line 5056 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 12047 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 398:
#line 5057 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 12053 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 399:
#line 5058 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 12059 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 400:
#line 5059 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 12065 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 401:
#line 5060 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 12071 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 402:
#line 5061 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 12077 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 403:
#line 5062 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 12083 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 404:
#line 5063 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) >> (int)(yyvsp[0].d)); }
#line 12089 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 405:
#line 5064 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) << (int)(yyvsp[0].d)); }
#line 12095 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 406:
#line 5065 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 12101 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 407:
#line 5066 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 12107 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 408:
#line 5067 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 12113 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 409:
#line 5068 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 12119 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 410:
#line 5069 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 12125 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 411:
#line 5070 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 12131 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 412:
#line 5071 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 12137 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 413:
#line 5072 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 12143 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 414:
#line 5073 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 12149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 415:
#line 5074 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 12155 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 416:
#line 5075 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 12161 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 417:
#line 5076 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 12167 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 418:
#line 5077 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 12173 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 419:
#line 5078 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 12179 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 420:
#line 5079 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 12185 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 421:
#line 5080 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 12191 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 422:
#line 5081 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = std::abs((yyvsp[-1].d)); }
#line 12197 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 423:
#line 5082 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 12203 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 424:
#line 5083 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 12209 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 425:
#line 5084 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 12215 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 426:
#line 5085 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12221 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 427:
#line 5086 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12227 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 428:
#line 5087 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 12233 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 429:
#line 5088 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 12239 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 430:
#line 5097 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12245 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 431:
#line 5098 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 3.141592653589793; }
#line 12251 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 432:
#line 5099 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 12257 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 433:
#line 5100 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 12263 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 434:
#line 5101 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 12269 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 435:
#line 5102 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 12275 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 436:
#line 5103 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 12281 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 437:
#line 5104 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 12287 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 438:
#line 5105 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Cpu(); }
#line 12293 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 439:
#line 5106 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 12299 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 440:
#line 5107 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = TotalRam(); }
#line 12305 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 441:
#line 5112 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 12311 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 442:
#line 5114 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 12321 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 443:
#line 5120 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12327 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 444:
#line 5122 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12336 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 445:
#line 5127 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12345 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 446:
#line 5132 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[0].c2).char1, (yyvsp[0].c2).char2);
    }
#line 12353 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 447:
#line 5137 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12361 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 448:
#line 5142 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12369 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 449:
#line 5146 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-1].c2).char1, (yyvsp[-1].c2).char2, 1, 0, 0., 1);
    }
#line 12377 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 450:
#line 5150 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-3].c2).char1, (yyvsp[-3].c2).char2, (yyvsp[-1].c), 0, 0., 1);
    }
#line 12385 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 451:
#line 5154 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-2].c2).char1, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].d), 2);
    }
#line 12393 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 452:
#line 5158 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].d), 2);
    }
#line 12401 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 453:
#line 5162 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-5].c2).char1, (yyvsp[-5].c2).char2, 2, (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12409 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 454:
#line 5166 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c2).char1, (yyvsp[-7].c2).char2, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12417 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 455:
#line 5170 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 12427 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 456:
#line 5176 "Gmsh.y" /* yacc.c:1652  */
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
#line 12446 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 457:
#line 5191 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c));
    }
#line 12454 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 458:
#line 5195 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[-1].c));
    }
#line 12464 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 459:
#line 5201 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
#line 12473 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 460:
#line 5206 "Gmsh.y" /* yacc.c:1652  */
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
#line 12496 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 461:
#line 5225 "Gmsh.y" /* yacc.c:1652  */
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
#line 12520 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 462:
#line 5245 "Gmsh.y" /* yacc.c:1652  */
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
#line 12544 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 463:
#line 5276 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12552 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 464:
#line 5280 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12560 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 465:
#line 5284 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12568 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 466:
#line 5288 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12576 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 467:
#line 5292 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12584 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 468:
#line 5296 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12592 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 469:
#line 5300 "Gmsh.y" /* yacc.c:1652  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12601 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 470:
#line 5305 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12615 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 471:
#line 5315 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 12629 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 472:
#line 5325 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12638 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 473:
#line 5330 "Gmsh.y" /* yacc.c:1652  */
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
#line 12653 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 474:
#line 5341 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12666 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 475:
#line 5350 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strlen((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12675 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 476:
#line 5355 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12684 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 477:
#line 5360 "Gmsh.y" /* yacc.c:1652  */
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
#line 12712 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 478:
#line 5387 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 0.; }
#line 12718 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 479:
#line 5389 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);}
#line 12724 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 480:
#line 5394 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = NULL; }
#line 12730 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 481:
#line 5396 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c);}
#line 12736 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 482:
#line 5401 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c2).char1? (yyvsp[-1].c2).char1 : std::string("")),
        struct_name((yyvsp[-1].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
#line 12747 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 483:
#line 5408 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-5].c2).char1? (yyvsp[-5].c2).char1 : std::string("")),
        struct_name((yyvsp[-5].c2).char2);
      Free((yyvsp[-5].c2).char1); Free((yyvsp[-5].c2).char2);
      int tag_out;
      if (gmsh_yynamespaces.defStruct(struct_namespace, struct_name,
                                      floatOptions, charOptions,
                                      tag_out, member_ValMax, (yyvsp[-4].i)))
        yymsg(0, "Redefinition of Struct '%s::%s'",
              struct_namespace.c_str(), struct_name.c_str());
      (yyval.d) = (double)tag_out;
    }
#line 12764 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 484:
#line 5424 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[0].c); }
#line 12770 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 485:
#line 5426 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = (yyvsp[-2].c); (yyval.c2).char2 = (yyvsp[0].c); }
#line 12776 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 486:
#line 5431 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); flag_tSTRING_alloc = 1; }
#line 12782 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 487:
#line 5440 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 99; }
#line 12788 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 488:
#line 5442 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (int)(yyvsp[0].d); }
#line 12794 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 489:
#line 5447 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 12800 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 490:
#line 5449 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 12806 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 491:
#line 5454 "Gmsh.y" /* yacc.c:1652  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 12814 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 492:
#line 5458 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 12822 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 493:
#line 5462 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 12830 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 494:
#line 5466 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 12838 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 495:
#line 5470 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 12846 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 496:
#line 5477 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 12854 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 497:
#line 5481 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 12862 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 498:
#line 5485 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12870 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 499:
#line 5489 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12878 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 500:
#line 5496 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12887 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 501:
#line 5501 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12895 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 502:
#line 5508 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12904 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 503:
#line 5513 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12912 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 504:
#line 5517 "Gmsh.y" /* yacc.c:1652  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 12921 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 505:
#line 5522 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12929 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 506:
#line 5526 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12941 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 507:
#line 5534 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 12953 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 508:
#line 5545 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12961 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 509:
#line 5549 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 12969 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 510:
#line 5553 "Gmsh.y" /* yacc.c:1652  */
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
#line 12984 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 511:
#line 5567 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12996 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 512:
#line 5575 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 13008 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 513:
#line 5583 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 13019 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 514:
#line 5590 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 13033 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 515:
#line 5600 "Gmsh.y" /* yacc.c:1652  */
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
#line 13060 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 516:
#line 5623 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    }
#line 13069 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 517:
#line 5628 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[0].c));
    }
#line 13079 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 518:
#line 5634 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-3].i), (yyval.l));
    }
#line 13088 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 519:
#line 5639 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-1].i), (yyval.l));
      Free((yyvsp[0].c));
    }
#line 13098 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 520:
#line 5645 "Gmsh.y" /* yacc.c:1652  */
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
#line 13113 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 521:
#line 5656 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[-1].i), (yyvsp[0].l), (yyval.l));
      List_Delete((yyvsp[0].l));
    }
#line 13123 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 522:
#line 5663 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[-15].i), (yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d), (yyval.l));
    }
#line 13132 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 523:
#line 5668 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[-3].i), (yyvsp[-1].l), (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 13142 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 524:
#line 5674 "Gmsh.y" /* yacc.c:1652  */
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
#line 13158 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 525:
#line 5686 "Gmsh.y" /* yacc.c:1652  */
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
#line 13176 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 526:
#line 5700 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13190 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 527:
#line 5710 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13204 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 528:
#line 5720 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13218 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 529:
#line 5730 "Gmsh.y" /* yacc.c:1652  */
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
#line 13234 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 530:
#line 5742 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13242 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 531:
#line 5746 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13250 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 532:
#line 5751 "Gmsh.y" /* yacc.c:1652  */
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
#line 13266 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 533:
#line 5763 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13274 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 534:
#line 5767 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13282 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 535:
#line 5771 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 13290 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 536:
#line 5775 "Gmsh.y" /* yacc.c:1652  */
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
#line 13312 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 537:
#line 5793 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = (yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1);
	List_Add((yyval.l), &d);
      }
    }
#line 13324 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 538:
#line 5801 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = pow(10,(yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1));
	List_Add((yyval.l), &d);
      }
    }
#line 13336 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 539:
#line 5809 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Barrier();
      FILE *File;
      (yyval.l) = List_Create(100, 100, sizeof(double));
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      if(!(File = Fopen(tmp.c_str(), "rb"))){
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
            char dummy[1024];
            fscanf(File, "%s", dummy);
            yymsg(0, "Ignoring '%s' in file '%s'", dummy, (yyvsp[-1].c));
          }
        }
	fclose(File);
      }
      Free((yyvsp[-1].c));
    }
#line 13369 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 540:
#line 5838 "Gmsh.y" /* yacc.c:1652  */
    {
      double x0 = (yyvsp[-11].d), x1 = (yyvsp[-9].d), y0 = (yyvsp[-7].d), y1 = (yyvsp[-5].d), ys = (yyvsp[-3].d);
      int N = (int)(yyvsp[-1].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
#line 13383 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 541:
#line 5848 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<double> tmp;
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double d; List_Read((yyvsp[-1].l), i, &d);
        tmp.push_back(d);
      }
      std::sort(tmp.begin(), tmp.end());
      std::vector<double>::iterator last = std::unique(tmp.begin(), tmp.end());
      tmp.erase(last, tmp.end());
      (yyval.l) = (yyvsp[-1].l);
      List_Reset((yyval.l));
      for(std::size_t i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    }
#line 13403 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 542:
#line 5864 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[-1].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13415 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 543:
#line 5875 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13424 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 544:
#line 5880 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13432 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 545:
#line 5884 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13440 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 546:
#line 5888 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13453 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 547:
#line 5900 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 13461 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 548:
#line 5904 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 13469 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 549:
#line 5916 "Gmsh.y" /* yacc.c:1652  */
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
#line 13490 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 550:
#line 5933 "Gmsh.y" /* yacc.c:1652  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 13501 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 551:
#line 5943 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13509 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 552:
#line 5947 "Gmsh.y" /* yacc.c:1652  */
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
#line 13525 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 553:
#line 5962 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13534 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 554:
#line 5967 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13542 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 555:
#line 5974 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13550 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 556:
#line 5978 "Gmsh.y" /* yacc.c:1652  */
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[0].c));
    }
#line 13559 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 557:
#line 5983 "Gmsh.y" /* yacc.c:1652  */
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
#line 13577 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 558:
#line 5997 "Gmsh.y" /* yacc.c:1652  */
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
#line 13595 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 559:
#line 6013 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13603 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 560:
#line 6017 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13611 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 561:
#line 6021 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13619 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 562:
#line 6025 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13627 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 563:
#line 6029 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 13639 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 564:
#line 6037 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13649 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 565:
#line 6043 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13659 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 566:
#line 6052 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13667 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 567:
#line 6056 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13675 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 568:
#line 6060 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 13687 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 569:
#line 6068 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 13697 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 570:
#line 6074 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 13707 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 571:
#line 6080 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
#line 13715 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 572:
#line 6084 "Gmsh.y" /* yacc.c:1652  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 13727 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 573:
#line 6092 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13739 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 574:
#line 6100 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 13750 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 575:
#line 6107 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13762 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 576:
#line 6116 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].c), 2);
    }
#line 13770 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 577:
#line 6120 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].c), 2);
    }
#line 13778 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 578:
#line 6124 "Gmsh.y" /* yacc.c:1652  */
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
#line 13797 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 579:
#line 6139 "Gmsh.y" /* yacc.c:1652  */
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
#line 13815 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 580:
#line 6153 "Gmsh.y" /* yacc.c:1652  */
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
	strcpy((yyval.c), &(yyvsp[-1].c)[i+1]);
      Free((yyvsp[-1].c));
    }
#line 13833 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 581:
#line 6167 "Gmsh.y" /* yacc.c:1652  */
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
#line 13849 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 582:
#line 6179 "Gmsh.y" /* yacc.c:1652  */
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
#line 13869 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 583:
#line 6195 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13882 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 584:
#line 6204 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13895 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 585:
#line 6213 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13909 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 586:
#line 6223 "Gmsh.y" /* yacc.c:1652  */
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
#line 13924 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 587:
#line 6234 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-5].c);
      std::string out = in.substr((int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c));
    }
#line 13936 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 588:
#line 6242 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-3].c);
      std::string out = in.substr((int)(yyvsp[-1].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-3].c));
    }
#line 13948 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 589:
#line 6250 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13956 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 590:
#line 6254 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstring[5000];
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
	(yyval.c) = (char*)Malloc((strlen(tmpstring) + 1) * sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[-3].c));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 13979 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 591:
#line 6273 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13990 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 592:
#line 6280 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 14000 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 593:
#line 6286 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 14011 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 594:
#line 6293 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 14022 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 595:
#line 6300 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 14028 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 596:
#line 6302 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 14040 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 597:
#line 6310 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string out;
      const std::string * key_struct = NULL;
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
#line 14065 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 598:
#line 6334 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[0].d); }
#line 14071 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 599:
#line 6336 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = (yyvsp[-3].c); Free((yyvsp[-3].c)); (yyval.d) = (yyvsp[0].d); }
#line 14077 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 600:
#line 6342 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 14083 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 601:
#line 6347 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14089 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 602:
#line 6349 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14095 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 603:
#line 6354 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 14101 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 604:
#line 6359 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 14110 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 605:
#line 6364 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14116 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 606:
#line 6366 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 14124 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 607:
#line 6370 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	char* c;
	List_Read((yyvsp[0].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[0].l));
    }
#line 14137 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 608:
#line 6382 "Gmsh.y" /* yacc.c:1652  */
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
#line 14155 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 609:
#line 6396 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14163 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 610:
#line 6400 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14171 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 611:
#line 6407 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 14183 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 612:
#line 6415 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 14195 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 613:
#line 6423 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-5].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-5].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-5].c));
    }
#line 14207 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 614:
#line 6434 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14213 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 615:
#line 6436 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14219 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 616:
#line 6439 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 14225 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;


#line 14229 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 6442 "Gmsh.y" /* yacc.c:1918  */


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

int printListOfDouble(char *format, List_T *list, char *buffer)
{
  // if format does not contain formatting characters, dump the list (useful for
  // quick debugging of lists)
  int numFormats = 0;
  for(std::size_t i = 0; i < strlen(format); i++)
    if(format[i] == '%') numFormats++;
  if(!numFormats){
    strcpy(buffer, format);
    for(int i = 0; i < List_Nbr(list); i++){
      double d;
      List_Read(list, i, &d);
      char tmp[256];
      sprintf(tmp, " [%d]%g", i, d);
      strcat(buffer, tmp);
    }
    return 0;
  }

  char tmp1[256], tmp2[256];
  int j = 0, k = 0;
  buffer[j] = '\0';

  while(j < (int)strlen(format) && format[j] != '%') j++;
  strncpy(buffer, format, j);
  buffer[j] = '\0';
  for(int i = 0; i < List_Nbr(list); i++){
    k = j;
    j++;
    if(j < (int)strlen(format)){
      if(format[j] == '%'){
	strcat(buffer, "%");
	j++;
      }
      while(j < (int)strlen(format) && format[j] != '%') j++;
      if(k != j){
	strncpy(tmp1, &(format[k]), j-k);
	tmp1[j-k] = '\0';
	sprintf(tmp2, tmp1, *(double*)List_Pointer(list, i));
	strcat(buffer, tmp2);
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
  for(std::map<std::string, gmsh_yysymbol>::iterator it = gmsh_yysymbols.begin();
      it != gmsh_yysymbols.end(); it++){
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
  for(std::map<std::string, std::vector<std::string> >::iterator it =
        gmsh_yystringsymbols.begin(); it != gmsh_yystringsymbols.end(); it++){
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
  if (gmsh_yynamespaces.size()){
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
    if(dim >= 0 && dim <= 3) v.push_back(std::pair<int, int>(dim, s.Num));
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
  Msg::Error("'%s', line %d : %s (%s)", gmsh_yyname.c_str(), gmsh_yylineno - 1,
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
    Msg::Error("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
    gmsh_yyerrorstate++;
  }
  else if(level == 1){
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
  else{
    Msg::Info("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
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
  if (!target || !source) {
    Msg::Error("Could not find curve slave %d or master %d for periodic copy",
               iTarget, iSource);
  }
  else target->setMeshMaster(source, affineTransform);
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
  std::map<int,int>::const_iterator sIter = edgeCounterparts.begin();
  for (; sIter != edgeCounterparts.end(); ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  GFace *target = GModel::current()->getFaceByTag(std::abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(std::abs(iSource));
  if (!target || !source) {
    Msg::Error("Could not find surface slave %d or master %d for periodic copy",
               iTarget,iSource);
  }
  else target->setMeshMaster(source, edgeCounterparts);
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
  if (!target || !source)
    Msg::Error("Could not find surface %d or %d for periodic copy",
               iTarget,iSource);
  if (affineTransform.size() >= 12) {
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

  tfo[0*4+0] = ca + ux*ux*(1.-ca);
  tfo[0*4+1] = ux*uy*(1.-ca) - uz * sa;
  tfo[0*4+2] = ux*uz*(1.-ca) + uy * sa;

  tfo[1*4+0] = ux*uy*(1.-ca) + uz * sa;
  tfo[1*4+1] = ca + uy*uy*(1.-ca);
  tfo[1*4+2] = uy*uz*(1.-ca) - ux * sa;

  tfo[2*4+0] = ux*uz*(1.-ca) - uy * sa;
  tfo[2*4+1] = uy*uz*(1.-ca) + ux * sa;
  tfo[2*4+2] = ca + uz*uz*(1.-ca);

  int idx = 0;
  for (size_t i = 0; i < 3; i++,idx++) {
    int tIdx = i*4+3;
    tfo[tIdx] = origin[i] + translation[i];
    for (int j = 0; j < 3; j++,idx++) tfo[tIdx] -= tfo[idx] * origin[j];
  }

  for (int i = 0; i < 4; i++) tfo[12+i] = 0;
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
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::map<int, std::vector<GEntity*> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  for(std::map<int, std::vector<GEntity*> >::iterator it = groups.begin();
      it != groups.end(); it++){
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
    std::map<int, std::vector<GEntity*> >::iterator it = groups.find(num);
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
    if (type_treat == 1) out = 1.; // Exists (type_treat == 1)
    else { // Get (0) or GetForced (2)
      if (type_var == 1) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(s.value.empty()){
          out = val_default;
          if (type_treat == 0) yymsg(0, "Uninitialized variable '%s'", c2);
        }
        else
          out = s.value[0];
      }
      else if (type_var == 2) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(index < 0 || (int)s.value.size() < index + 1){
          out = val_default;
          if (type_treat == 0) yymsg(0, "Uninitialized variable '%s[%d]'", c2, index);
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
    if (type_var == 1) {
      std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
      if(gmsh_yynamespaces.getTag(struct_namespace, struct_name, out)) {
        out = val_default;
        if (type_treat == 0) yymsg(0, "Unknown variable '%s'", struct_name.c_str());
      }
    }
    else {
      out = val_default;
      if (type_treat == 0) yymsg(0, "Unknown variable '%s(.)'", c2);
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
    if (type_treat == 1) out = 1.; // Exists (type_treat == 1)
    break;
  case 1:
    if (!NumberOption(GMSH_GET, c2, 0, c3, out, type_treat==0))
      out = val_default;
    break;
  case 2:
    if (type_treat != 0) {
      const std::string * out_dummy = NULL;
      out = (gmsh_yynamespaces.getMember
             (struct_namespace, struct_name, key_member, out_dummy))?
        val_default : 1.;
    }
    else {
      out = val_default;
      if (type_treat == 0)
        yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    }
    break;
  case 3:
    out = val_default;
    if (type_treat == 0)
      yymsg(0, "Index %d out of range", index);
    break;
  }
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out;
}

List_T * treat_Struct_FullName_dot_tSTRING_ListOfFloat
(char* c1, char* c2, char* c3)
{
  List_T * out, * val_default = NULL;
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
  if (flag_tSTRING_alloc) Free(c3);
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
  if (flag_tSTRING_alloc) Free(c3);
  return out;
}

char * treat_Struct_FullName_String
(char* c1, char* c2, int type_var, int index, char * val_default, int type_treat)
{
  std::string string_default(val_default? val_default : std::string(""));
  const std::string * out = NULL;
  std::string out_tmp;
  if(!c1 && gmsh_yystringsymbols.count(c2)){
    // Get (0) or GetForced (2)
    if(gmsh_yystringsymbols[c2].size() != 1){
      out = &string_default;
      if (type_treat == 0)
        yymsg(0, "Expected single valued string variable '%s'", c2);
    }
    else {
      out_tmp = gmsh_yystringsymbols[c2][0];
      out = &out_tmp;
    }
  }
  else{
    out = &string_default;
    if (type_treat == 0) yymsg(0, "Unknown string variable '%s'", c2);
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
  const std::string * out = NULL;
  std::string out_tmp; // PD: we should avoid that -> StringOption() to be changed
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember
          (struct_namespace, struct_name, key_member, out, index)) {
  case 0:
    break;
  case 1:
    if (StringOption(GMSH_GET, c2, 0, c3, out_tmp, type_treat==0))
      out = &out_tmp;
    else
      out = &string_default;
    break;
  case 2:
    out = &string_default;
    if (type_treat == 0)
      yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  case 3:
    out = &string_default;
    if (type_treat == 0)
      yymsg(0, "Index %d out of range", index);
    break;
  }
  char* out_c = (char*)Malloc((out->size() + 1) * sizeof(char));
  strcpy(out_c, out->c_str());
  Free(c1); Free(c2);
  if (flag_tSTRING_alloc) Free(c3);
  return out_c;
}

List_T * treat_Struct_FullName_dot_tSTRING_ListOfString
(char* c1, char* c2, char* c3)
{
  List_T * out, * val_default = NULL;
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
  if (flag_tSTRING_alloc) Free(c3);
  return out;
}
