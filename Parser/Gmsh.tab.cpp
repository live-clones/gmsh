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
    tWarning = 301,
    tStr = 302,
    tSprintf = 303,
    tStrCat = 304,
    tStrPrefix = 305,
    tStrRelative = 306,
    tStrReplace = 307,
    tAbsolutePath = 308,
    tDirName = 309,
    tStrSub = 310,
    tStrLen = 311,
    tFind = 312,
    tStrFind = 313,
    tStrCmp = 314,
    tStrChoice = 315,
    tUpperCase = 316,
    tLowerCase = 317,
    tLowerCaseIn = 318,
    tTextAttributes = 319,
    tBoundingBox = 320,
    tDraw = 321,
    tSetChanged = 322,
    tToday = 323,
    tFixRelativePath = 324,
    tCurrentDirectory = 325,
    tSyncModel = 326,
    tNewModel = 327,
    tMass = 328,
    tCenterOfMass = 329,
    tOnelabAction = 330,
    tOnelabRun = 331,
    tCodeName = 332,
    tCpu = 333,
    tMemory = 334,
    tTotalMemory = 335,
    tCreateTopology = 336,
    tCreateGeometry = 337,
    tClassifySurfaces = 338,
    tRenumberMeshNodes = 339,
    tRenumberMeshElements = 340,
    tDistanceFunction = 341,
    tDefineConstant = 342,
    tUndefineConstant = 343,
    tDefineNumber = 344,
    tDefineStruct = 345,
    tNameStruct = 346,
    tDimNameSpace = 347,
    tAppend = 348,
    tDefineString = 349,
    tSetNumber = 350,
    tSetTag = 351,
    tSetString = 352,
    tPoint = 353,
    tCircle = 354,
    tEllipse = 355,
    tCurve = 356,
    tSphere = 357,
    tPolarSphere = 358,
    tSurface = 359,
    tSpline = 360,
    tVolume = 361,
    tBox = 362,
    tCylinder = 363,
    tCone = 364,
    tTorus = 365,
    tEllipsoid = 366,
    tQuadric = 367,
    tShapeFromFile = 368,
    tRectangle = 369,
    tDisk = 370,
    tWire = 371,
    tGeoEntity = 372,
    tCharacteristic = 373,
    tLength = 374,
    tParametric = 375,
    tElliptic = 376,
    tRefineMesh = 377,
    tAdaptMesh = 378,
    tRelocateMesh = 379,
    tReorientMesh = 380,
    tSetFactory = 381,
    tThruSections = 382,
    tWedge = 383,
    tFillet = 384,
    tChamfer = 385,
    tPlane = 386,
    tRuled = 387,
    tTransfinite = 388,
    tPhysical = 389,
    tCompound = 390,
    tPeriodic = 391,
    tParent = 392,
    tUsing = 393,
    tPlugin = 394,
    tDegenerated = 395,
    tRecursive = 396,
    tSewing = 397,
    tRotate = 398,
    tTranslate = 399,
    tSymmetry = 400,
    tDilate = 401,
    tExtrude = 402,
    tLevelset = 403,
    tAffine = 404,
    tBooleanUnion = 405,
    tBooleanIntersection = 406,
    tBooleanDifference = 407,
    tBooleanSection = 408,
    tBooleanFragments = 409,
    tThickSolid = 410,
    tRecombine = 411,
    tSmoother = 412,
    tSplit = 413,
    tDelete = 414,
    tCoherence = 415,
    tIntersect = 416,
    tMeshAlgorithm = 417,
    tReverseMesh = 418,
    tLayers = 419,
    tScaleLast = 420,
    tHole = 421,
    tAlias = 422,
    tAliasWithOptions = 423,
    tCopyOptions = 424,
    tQuadTriAddVerts = 425,
    tQuadTriNoNewVerts = 426,
    tRecombLaterals = 427,
    tTransfQuadTri = 428,
    tText2D = 429,
    tText3D = 430,
    tInterpolationScheme = 431,
    tTime = 432,
    tCombine = 433,
    tBSpline = 434,
    tBezier = 435,
    tNurbs = 436,
    tNurbsOrder = 437,
    tNurbsKnots = 438,
    tColor = 439,
    tColorTable = 440,
    tFor = 441,
    tIn = 442,
    tEndFor = 443,
    tIf = 444,
    tElseIf = 445,
    tElse = 446,
    tEndIf = 447,
    tExit = 448,
    tAbort = 449,
    tField = 450,
    tReturn = 451,
    tCall = 452,
    tSlide = 453,
    tMacro = 454,
    tShow = 455,
    tHide = 456,
    tGetValue = 457,
    tGetStringValue = 458,
    tGetEnv = 459,
    tGetString = 460,
    tGetNumber = 461,
    tUnique = 462,
    tHomology = 463,
    tCohomology = 464,
    tBetti = 465,
    tExists = 466,
    tFileExists = 467,
    tGetForced = 468,
    tGetForcedStr = 469,
    tGMSH_MAJOR_VERSION = 470,
    tGMSH_MINOR_VERSION = 471,
    tGMSH_PATCH_VERSION = 472,
    tGmshExecutableName = 473,
    tSetPartition = 474,
    tNameToString = 475,
    tStringToName = 476,
    tAFFECTPLUS = 477,
    tAFFECTMINUS = 478,
    tAFFECTTIMES = 479,
    tAFFECTDIVIDE = 480,
    tOR = 481,
    tAND = 482,
    tEQUAL = 483,
    tNOTEQUAL = 484,
    tLESSOREQUAL = 485,
    tGREATEROREQUAL = 486,
    tLESSLESS = 487,
    tGREATERGREATER = 488,
    tPLUSPLUS = 489,
    tMINUSMINUS = 490,
    UNARYPREC = 491
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

#line 534 "Gmsh.tab.cpp" /* yacc.c:352  */
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
#define YYLAST   17270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  259
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  618
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2211

#define YYUNDEFTOK  2
#define YYMAXUTOK   491

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
       2,     2,     2,   244,     2,   256,     2,   241,   243,     2,
     249,   250,   239,   237,   258,   238,   255,   240,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     231,     2,   233,   226,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   251,     2,   252,   248,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   253,   242,   254,   257,     2,     2,     2,
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
     225,   227,   228,   229,   230,   232,   234,   235,   236,   245,
     246,   247
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   270,   270,   271,   276,   278,   282,   283,   284,   285,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   323,   327,   334,   339,
     344,   349,   363,   376,   389,   402,   430,   444,   457,   470,
     489,   494,   495,   496,   497,   498,   502,   504,   509,   511,
     517,   621,   516,   639,   646,   657,   656,   674,   681,   692,
     691,   708,   725,   748,   747,   761,   762,   763,   764,   765,
     769,   770,   776,   776,   777,   777,   783,   784,   785,   786,
     791,   797,   859,   874,   903,   913,   918,   926,   931,   939,
     948,   953,   965,   982,   988,   997,  1015,  1033,  1042,  1054,
    1059,  1067,  1087,  1110,  1130,  1138,  1145,  1152,  1174,  1197,
    1235,  1256,  1268,  1282,  1282,  1284,  1286,  1295,  1305,  1304,
    1325,  1324,  1342,  1352,  1351,  1365,  1367,  1375,  1381,  1386,
    1413,  1415,  1418,  1420,  1424,  1425,  1429,  1441,  1454,  1469,
    1478,  1491,  1493,  1497,  1498,  1503,  1511,  1520,  1528,  1542,
    1560,  1564,  1571,  1580,  1583,  1589,  1593,  1605,  1608,  1615,
    1618,  1624,  1647,  1663,  1679,  1716,  1760,  1776,  1792,  1824,
    1840,  1857,  1873,  1923,  1941,  1947,  1953,  1960,  1991,  2006,
    2028,  2051,  2074,  2097,  2121,  2145,  2169,  2195,  2212,  2228,
    2246,  2264,  2271,  2280,  2279,  2309,  2311,  2313,  2315,  2317,
    2325,  2327,  2329,  2331,  2339,  2341,  2343,  2351,  2353,  2355,
    2357,  2367,  2383,  2399,  2415,  2431,  2447,  2464,  2501,  2523,
    2547,  2548,  2553,  2556,  2560,  2577,  2597,  2617,  2636,  2663,
    2682,  2703,  2718,  2734,  2752,  2803,  2824,  2846,  2869,  2974,
    2990,  3025,  3047,  3069,  3081,  3087,  3102,  3130,  3142,  3151,
    3158,  3170,  3190,  3194,  3199,  3203,  3208,  3215,  3222,  3229,
    3241,  3314,  3332,  3357,  3372,  3405,  3417,  3441,  3445,  3450,
    3457,  3462,  3472,  3477,  3483,  3491,  3495,  3499,  3503,  3507,
    3511,  3520,  3584,  3600,  3617,  3634,  3656,  3678,  3713,  3721,
    3729,  3735,  3742,  3749,  3769,  3795,  3807,  3818,  3836,  3854,
    3873,  3872,  3897,  3896,  3923,  3922,  3947,  3946,  3969,  3985,
    4002,  4019,  4042,  4070,  4073,  4079,  4091,  4111,  4115,  4119,
    4123,  4127,  4131,  4135,  4139,  4148,  4161,  4162,  4163,  4164,
    4165,  4169,  4170,  4171,  4172,  4173,  4176,  4200,  4219,  4242,
    4245,  4261,  4264,  4281,  4284,  4290,  4293,  4300,  4303,  4310,
    4332,  4373,  4417,  4456,  4481,  4493,  4505,  4517,  4529,  4538,
    4568,  4594,  4620,  4652,  4679,  4705,  4731,  4757,  4783,  4805,
    4816,  4864,  4918,  4933,  4945,  4956,  4963,  4978,  4992,  4993,
    4994,  4998,  5004,  5016,  5034,  5062,  5063,  5064,  5065,  5066,
    5067,  5068,  5069,  5070,  5077,  5078,  5079,  5080,  5081,  5082,
    5083,  5084,  5085,  5086,  5087,  5088,  5089,  5090,  5091,  5092,
    5093,  5094,  5095,  5096,  5097,  5098,  5099,  5100,  5101,  5102,
    5103,  5104,  5105,  5106,  5107,  5108,  5109,  5110,  5111,  5112,
    5113,  5114,  5123,  5124,  5125,  5126,  5127,  5128,  5129,  5130,
    5131,  5132,  5133,  5138,  5137,  5145,  5147,  5152,  5157,  5161,
    5166,  5171,  5175,  5179,  5183,  5187,  5191,  5195,  5201,  5216,
    5220,  5226,  5231,  5250,  5270,  5301,  5305,  5309,  5313,  5317,
    5321,  5325,  5330,  5340,  5350,  5355,  5366,  5375,  5380,  5385,
    5413,  5414,  5420,  5421,  5427,  5426,  5449,  5451,  5456,  5465,
    5467,  5473,  5474,  5479,  5483,  5487,  5491,  5495,  5502,  5506,
    5510,  5514,  5521,  5526,  5533,  5538,  5542,  5547,  5551,  5559,
    5570,  5574,  5578,  5592,  5600,  5608,  5615,  5625,  5648,  5653,
    5659,  5664,  5670,  5681,  5687,  5693,  5699,  5711,  5725,  5735,
    5745,  5755,  5767,  5771,  5776,  5788,  5792,  5796,  5800,  5818,
    5826,  5834,  5863,  5873,  5889,  5900,  5905,  5909,  5913,  5925,
    5929,  5941,  5958,  5968,  5972,  5987,  5992,  5999,  6003,  6008,
    6022,  6038,  6042,  6046,  6050,  6054,  6062,  6068,  6077,  6081,
    6085,  6093,  6099,  6105,  6109,  6117,  6125,  6132,  6141,  6145,
    6149,  6164,  6178,  6192,  6204,  6220,  6229,  6238,  6248,  6259,
    6267,  6275,  6279,  6298,  6305,  6311,  6318,  6326,  6325,  6335,
    6359,  6361,  6367,  6372,  6374,  6379,  6384,  6389,  6391,  6395,
    6407,  6421,  6425,  6432,  6440,  6448,  6459,  6461,  6464
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
  "tLogSpace", "tListFromFile", "tCatenary", "tPrintf", "tError",
  "tWarning", "tStr", "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative",
  "tStrReplace", "tAbsolutePath", "tDirName", "tStrSub", "tStrLen",
  "tFind", "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase",
  "tLowerCaseIn", "tTextAttributes", "tBoundingBox", "tDraw",
  "tSetChanged", "tToday", "tFixRelativePath", "tCurrentDirectory",
  "tSyncModel", "tNewModel", "tMass", "tCenterOfMass", "tOnelabAction",
  "tOnelabRun", "tCodeName", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateGeometry", "tClassifySurfaces",
  "tRenumberMeshNodes", "tRenumberMeshElements", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineStruct",
  "tNameStruct", "tDimNameSpace", "tAppend", "tDefineString", "tSetNumber",
  "tSetTag", "tSetString", "tPoint", "tCircle", "tEllipse", "tCurve",
  "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume", "tBox",
  "tCylinder", "tCone", "tTorus", "tEllipsoid", "tQuadric",
  "tShapeFromFile", "tRectangle", "tDisk", "tWire", "tGeoEntity",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tReorientMesh", "tSetFactory",
  "tThruSections", "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled",
  "tTransfinite", "tPhysical", "tCompound", "tPeriodic", "tParent",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tSewing", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
  "tBooleanSection", "tBooleanFragments", "tThickSolid", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tReverseMesh", "tLayers", "tScaleLast", "tHole",
  "tAlias", "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tRecombLaterals", "tTransfQuadTri", "tText2D",
  "tText3D", "tInterpolationScheme", "tTime", "tCombine", "tBSpline",
  "tBezier", "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor",
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tElseIf", "tElse",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tSlide",
  "tMacro", "tShow", "tHide", "tGetValue", "tGetStringValue", "tGetEnv",
  "tGetString", "tGetNumber", "tUnique", "tHomology", "tCohomology",
  "tBetti", "tExists", "tFileExists", "tGetForced", "tGetForcedStr",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tGmshExecutableName", "tSetPartition", "tNameToString", "tStringToName",
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
  "Affectation", "Comma", "DefineConstants", "$@6", "$@7", "$@8",
  "UndefineConstants", "Enumeration", "FloatParameterOptionsOrNone",
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
     475,   476,   477,   478,   479,   480,    63,   481,   482,   483,
     484,    60,   485,    62,   486,   487,   488,    43,    45,    42,
      47,    37,   124,    38,    33,   489,   490,   491,    94,    40,
      41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

#define YYPACT_NINF -1858

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1858)))

#define YYTABLE_NINF -566

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   12954,    94,   110, 13115, -1858, -1858,   -54,   115,    53,  -111,
     -34,   -12,    33,   184,   199,   277,   289,    -5,   308,   325,
      87,   347,   371,   132,   138,    22,    79,   401,    79,   147,
     233,   243,    15,   276,   281,    49,   291,   296,   316,   321,
     389,   421,   439,   445,   456,   506,   333,   382,   331,   601,
     338,     5,   553,   516,  7160,   550,   492,   556,   706,   -45,
     571,   328,   278,   123,   592,   724,  -116,   589,    -2,    -2,
     595,   367,    57,   604, -1858, -1858, -1858, -1858, -1858,   616,
     336,   768,   789,    17,    52,   798,   808,    63,   917,   941,
     948,  6172,   951,   709,   714,   715,    21,    50, -1858,   716,
     718, -1858, -1858,   956,   960,   719, -1858,  6039,   720, 13353,
      26,    36, -1858, -1858, -1858, 12101,   723, -1858, -1858, -1858,
   -1858, -1858,   722, -1858, -1858, -1858, -1858, -1858, -1858, -1858,
   -1858, -1858, -1858,   458, -1858, -1858, -1858, -1858,    27, -1858,
     962,   721,  5923,    73,   726,   965, 12101, 13293, 13293, 13293,
   -1858, 12101, -1858, -1858, -1858, -1858, 13293, -1858, -1858, 12101,
   -1858, -1858, -1858, -1858,   733,   728,   971, -1858, -1858, 13388,
     732,   746,   747,   767,    22, 12101, 12101, 12101,   769, 12101,
   12101, 12101,   770, 12101, 12101, 12101, 12101, 12101, 12101, 12101,
   13293, 12101, 12101, 12101, 12101,  6172,   773, -1858,  9867, -1858,
   -1858, -1858,   771,  6172,  7407, 13293, -1858, -1858, -1858, -1858,
   -1858,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,   388,    79,    79,    79,    79,    79,
     774,    79,    79,   776,   328,   278,   278, -1858, -1858, -1858,
      79,    79,    37,   834,   839,   840,   777,  7407,   902,   328,
     328,   782,    79,    79,   783,   784,   785, -1858, -1858, -1858,
   12101,  7654, 12101, 12101,  7901,    22,   848,    43, -1858, -1858,
     787, -1858,  4548, -1858, -1858, -1858, -1858, -1858,   182, 12101,
    9867,  9867,   788,   792,  8148,  6172,  6172,  6172, -1858, -1858,
   -1858, -1858, -1858, -1858, -1858, -1858,   790,  8395,   793, 10540,
    1032,  7407,   794,    21,   795,   796,    -2,    -2,    -2, 12101,
   12101,  -113, -1858,   -28,    -2, 10787,   201,   472,   801,   804,
     805,   806,   807,   809,   810,  9867, 12101,  6172,  6172,  6172,
     811,    16,  1036,   812, -1858,  1039,  1055, -1858,   813,   814,
     815, -1858, -1858,   816,  6172,   819,   823,   824, -1858, 12101,
    6419, -1858,  1058,  1059, 12101, 12101, 12101,   410, 12101,   825,
   -1858,   889, 12101, 12101, 12101, -1858, -1858, 12101, -1858,    79,
      79,    79,   828,   830,   835,    79,    79,    79,    79,    79,
      79,    79, -1858,    79, -1858, -1858, -1858,    79,    79,   836,
     837,    79,   838, -1858,   832,  1083,  1084,   841, -1858, -1858,
    1085,  1089,  1087,  1093,    79, 12101, 11069,   204, 13293,  9867,
   12101, -1858, -1858,  7407,  7407, -1858,   859, 13388,   328,  1106,
   -1858, -1858, -1858, -1858, -1858, -1858, 12101, 12101,    45,  7407,
    1124,   697,   879,  1270,   880,  1129,    56,   883, -1858,   884,
   13609, 12101, -1858,  1293,  -175, -1858,    78,  -153,   -98,  6602,
   -1858,   -88, -1858,   103,  6849,  -186,  -138,  1044, -1858,    22,
     881, 12101, 12101, 12101, 12101,   882, 15397, 15422, 15447, 12101,
   15472, 15497, 15522, 12101, 15547, 15572, 15597, 15622, 15647, 15672,
   15697,   892, 15722, 15747, 15772,  3265,  1136, 12101,  9867,  4595,
   -1858,    -8, 12101,  1138,  1139,   896, 12101, 12101, 12101, 12101,
   12101, 12101, 12101, 12101, 12101, 12101, 12101, 12101, 12101, 12101,
   12101, 12101,  9867, 12101, 12101, 12101, 12101, 12101, 12101,  9867,
    9867,   894, 12101, 12101, 13293, 12101, 13293,  7407, 13293, 13293,
   13293,   895,   897,   898, 12101,    32, -1858, 10870, 12101,  7407,
    6172,  7407, 13293, 13293,  9867,    22, 13388,    22,   901,  9867,
     901, -1858,   901, 15797, -1858,   360,   900,    92,  1091, -1858,
    1149, 12101, 12101, 12101, 12101, 12101, 12101, 12101, 12101, 12101,
   12101, 12101, 12101, 12101, 12101,  8642, 12101, 12101, 12101, 12101,
   12101,    22, 12101, 12101,  1154, -1858,   701, 15822,   489,   490,
   12101, 12101, 12101, -1858,  1152,  1153,  1153,   912, 12101, 12101,
    1156,  9867,  9867, 11401,   914,  1159, -1858,   913, -1858, -1858,
    -139, -1858, -1858,  7096,  7343,    -2,    -2,    73,    73,  -121,
   10787, 10787, 12101,  3575,  -110, -1858, 12101, 12101, 12101, 12101,
   12101, 12101, 12101, 12101, 12101,   495, 15847,  1160,  1162,  1163,
   12101,  1165, 12101, -1858, -1858, 12101,  4308, -1858, -1858,  9867,
    9867,  9867, 12101,  1166, 12101, 12101, 12101, 15872,   915, -1858,
   -1858, 15897, 15922, 15947,   989,  7590, -1858,   921,  4784, 15972,
   15997, 14992, 13293, 13293, 13293, 13293, 13293, 13293, 13293, 13293,
   13293, 12101, 13293, 13293, 13293, 13293,    19, 13388, 13293, 13293,
   13293,    22,    22, -1858, -1858,  9867, -1858,   923,  4959, -1858,
     924,  5116, 12101,   901, 12101, -1858,    22, 12101, 12101,  1154,
     927,   496, 16022, 13511,   925,   498, 12101,  1174,   928,  7407,
   16047, 15019,   238,   929,  1175,  1177, -1858, -1858, -1858,  9867,
     168, 12101, -1858, -1858, -1858,    22, 12101, 12101,  1154,   934,
   -1858,   938,   -33,   328,   278,   328, -1858,   935, 14067, -1858,
      70,  9867,    22, 12101, 12101,  1185,  1184,  9867,  1189,  9867,
   12101,  1190, 13293,    22, 11112,  1185, 12101,  1191, -1858,    22,
    1193, 13293, 12101,   969,   940, -1858, 12101,  7837,  8084,  8331,
    8578, 13388,  1213,  1214,  1215, 16072,  1217,  1219,  1220, 16097,
    1221,  1222,  1224,  1225,  1228,  1229,  1230, -1858,  1231,  1233,
    1234, -1858, 12101, 16122,  9867,   991,  9867, 14096, -1858, -1858,
    1239, 14965, 14965, 14965, 14965, 14965, 14965, 14965, 14965, 14965,
   14965, 14965,  8825, 14965, 14965, 14965, 14965,   555,   462, 14965,
   14965, 14965,  9067,  9309,  9556,  4595,  1000,  1002,    93,  9867,
    9803, 10140,   462, 10479,   462,   997,   998,   999,   172,  9867,
   12101, 12101, 17022, -1858,   462,  1004, 14125, 14154, -1858, -1858,
    1001,   136,   462,  -108,  1010,   411,   503,  1257, -1858,  1185,
     462,  1014,  1015,  5087,  5146,   772,   886,  2200,  2200,   491,
     491,   491,   491,   491,   491,   403,   403,  9867,   326, -1858,
     326,   326,   901,   901,   901,  1013, 16147, 15046,   -69,   486,
    9867, -1858,  1263,  1018,  1020, 16172, 16197, 16222, 12101,  7407,
    1271,  1268, 10448, 14183, 16247, -1858,   509,   514,  9867,  1023,
   -1858, 12129, -1858, 12227, 12335,    -2, 12101, 12101, -1858, -1858,
    1025,  1026, 10787,  5612,  1144,   -75,    -2, 12403, 16272, 14212,
   16297, 16322, 16347, 16372, 16397, 16422, 16447,  1030,  1277, 12101,
    1279, -1858, 12101, 16472, -1858, 15073, 12471, 15100, -1858,   517,
     519,   546, 14241, -1858, 15127, 15154, 10737, -1858, -1858,  1280,
    1281,  1282,  1031, 12101, 12539, 12101, 12101, -1858, -1858,    30,
     303,   342,   303,  1041,  1043,  1038,   462,   462,  1040, 10819,
     462,   462,   462,   462, 12101,   462,  1285, -1858,  1042,  1047,
     361,   248,  1049,   548, -1858, -1858, -1858, -1858, 14965,   326,
   12607,  1048,   511,  1045,  1117,  1298,  1147, 11202,  1053,  1056,
    1302,  7407, 14270, -1858, 12101,  1305,   245,   101, 13388, 12101,
    1306,  1309,    28, -1858,   554,  1267,  1269,  7407, 14299,     9,
    1060, 16497, 15181,   425, 12101, 12101,  1068,  1065,  1070,  1067,
    8889, -1858, -1858, -1858, -1858, 13293,   337,  1066, 16522, 15208,
   -1858,  1073, -1858,   348, -1858,   374, 11143, -1858, -1858, -1858,
    1069, -1858,  1076, 11475, -1858,    66, -1858, -1858, 17022, -1858,
    1341, 14965, 12101, 12101, 12101, 12101,   462,    -2,  7407,  7407,
    1343,  7407,  7407,  7407,  1344,  7407,  7407,  7407,  7407,  7407,
    7407,  7407,  7407,  7407,  7407,  1376,  1346,  9867,  4595, -1858,
   -1858, -1858, -1858, -1858, -1858, -1858, -1858, -1858, -1858, -1858,
   -1858, -1858, -1858, 12101, -1858, -1858, -1858, -1858, -1858, -1858,
   -1858, -1858, -1858, 12101, 12101, 12101, -1858, -1858, -1858,   561,
   12101, 12101, -1858, 12101, -1858,  7407, 13293, 13293, -1858,   562,
   14328, 14357,  1090, -1858, -1858, -1858,  1168, 12101, 12101, -1858,
   -1858, -1858,  1185, -1858,  1185, 12101, 12101,  1107, -1858,  7407,
      79, -1858, 12101, -1858, 12101, 12101,   563,  1185,   -69,  -176,
   -1858, 12101, 12101,   462,   564,  7407,  9867,  9867,  1349,  1351,
    1352,  1101, -1858, -1858,  1354, -1858,  1111, 17022,  1104, -1858,
    1356,  1358,  1359,   569,  1363, -1858, 12675, -1858, -1858,  -104,
   11726, 11808, -1858, -1858, 14386,   256,  1252,  1366, 11444,  1119,
    1367,  1125,    34,    39,   358, -1858,  -102, -1858,   -75,  1368,
    1370,  1372,  1374,  1378,  1379,  1380,  1382,  1383,    73,  7407,
   17022, -1858,  1816,  1130,  1371, -1858,  1385,  1386,  1289,  1387,
   -1858,  1398,  1403, 12101,  7407,  7407,  7407,  1406, 11968, -1858,
    5344,   975,    74,  1410, -1858,  9867, -1858, -1858, -1858, -1858,
   13293, -1858, -1858, 12101, 13293, -1858, -1858, -1858, -1858, 17022,
   -1858,  1161,  1157, 13293, -1858, 13293, -1858,  1185, 13293,  1169,
   -1858,  1158, -1858,  1185, 12101, 12101,  1167,   328,  1170, 11534,
   -1858,  2018,  1172,  7407, -1858,  1173, -1858, 14415, -1858, -1858,
   12101,  1416,    48, 12101,  1426,  1427,  2134, -1858,  1428,    21,
    1431,  1187,   462,    79,    79,  1433, -1858, -1858,  1192,  1196,
    1194, -1858,  1434, -1858, -1858, -1858, -1858, -1858,  1185,   418,
    2104, 12101, 15235, 16547, 12101,  9131, 12101,  9867,  1195,   570,
    1440,    86,  1185, -1858,  1197, 12101,  1442,  1445, 12101,  1185,
   11776, 12101,  4907,   462,  5395,  1201,  1199, -1858,  1448, 16572,
   16597, 16622, 16647,  1452,    18,  1328,  1328,  7407,  1454,  1455,
    1456,  7407,   -76,  1457,  1458,  1461,  1463,  1464,  1465,  1468,
    1469,  1471, -1858,  1473,   576, 14965, 14965, 14965, 14965,   462,
   12161, 12745, 13301,  1232,   462,   462, -1858, -1858, -1858,  1341,
     462, 16672, 14965,  1236,  -100, 17022, 14965, -1858,  1474,   462,
   13445, 17022, 17022, -1858,   580, -1858,  1475, -1858, 16697, 15262,
   -1858,   462,  1477,   578,   585,  7407,  7407,  7407,  1483,  1484,
   -1858,   293, 12101,  7407,  1238,  1240,  1482,   646, -1858, 12101,
   12101, 12101,  1242,  1261,  1262,  1241, -1858,  2172,  7407, -1858,
   12101, -1858,  1510, -1858,  1531, -1858, -1858, 10787,   419,  6666,
   -1858,  1286,  1287,  1292,  1294,  1297,  1299,  9373,  1227,  1532,
   -1858,  9867, -1858, -1858, -1858,  1300, 12101, -1858, -1858, 15289,
    1540,  1545,  1373, -1858, 12101, 12101, 12101, -1858,  1549,  1551,
    1552,   717,   365,  1301,  2042,  1303, 12101,    40,   462,  1310,
     462,  1304, -1858, -1858, 13388,   598, 12101,  1311, -1858, -1858,
    2419, -1858, -1858,  1307,  1557, -1858,  2586, -1858,   252,  1312,
    1559,  3070, -1858, -1858, -1858,    21, -1858,   586, -1858, 12101,
     293,  2461,  3770, -1858,  1320, 12101, 12101,  7407,  1317, -1858,
     469,  1567,  1568, 16722,  1569,  1257, 16747,  1319,   600, 16772,
     605,  1570,  1571, -1858, -1858, 13293,  1331,  1577, 16797, -1858,
   -1858, 13539,  1335, -1858, 14444,  5676, 17022, -1858,  1578,    79,
    7901, -1858, -1858, -1858, -1858,  1341, -1858,  1580,  1582,  1583,
    1584, -1858, -1858,    -2,  1585,  1587,  1589, -1858, -1858, -1858,
    1460,   -31,  1494,  1593, -1858, -1858, -1858, -1858, -1858, -1858,
   -1858, -1858, -1858,  1595,  1369, -1858, -1858, -1858, -1858, -1858,
   12101, 12101, 12101, -1858, -1858, -1858,  1199, -1858, -1858, -1858,
   -1858, 12101,  1375,  1362, -1858, -1858, 12101, 12101, 12101,   462,
     -69, -1858, -1858, -1858, -1858,  1384,  1388,  1615,   -76,  1617,
   12101, -1858,  7407, 17022,   955,  9867,  9867, 12101, -1858, 10448,
   14473, 16822,  4238,    73,    73, 12101, 12101, -1858,   133,  1390,
   16847, -1858, -1858, 14502,   -44, -1858,  1620,  1622,  7407,    -2,
      -2,    -2,    -2,    -2,  6913,  1623, -1858, -1858,   610, 12101,
    3169,  1630, -1858, -1858,  7407,  6108,   171, 16872, -1858, -1858,
   -1858, -1858, 10109, -1858, 13293, 12101, -1858, 13293, 17022, 10201,
   13388,  1392, -1858, -1858, -1858, -1858,  1393,  1394, 12101, 12101,
   14531, 12101, 13511, -1858, 13511,  7407, -1858, -1858, 13388, 12101,
    1632,  1636,    28, -1858,  1639, -1858,    21, 15316,  7407, 13293,
    1645,   462, -1858,  1395,   462, 12101, 13572, 13605,   612, -1858,
   12101, 12101,   455, -1858,  1389, -1858,  1352,  1648,  1651,  1356,
    1652, -1858, -1858,  1655, 12101, -1858, -1858, 12101, 11859,  1658,
   -1858, -1858,  1412,  3770,   613,  4103,  1659, -1858, -1858, -1858,
   -1858, -1858,   542, -1858, -1858, -1858,  1525,  1662,  1418,  1419,
    1422, -1858,  1664,  7407, 14965, 14965, 13638, 14965, -1858,  1432,
   13671, 16897, 15343, -1858, -1858,  9867,  9867, -1858,  1670, -1858,
   17022,  1671,  1425, -1858,   619,   620, 14937,  3211,  1675,  1430,
   -1858, -1858, 12101,  1435,  1436, 14560, 15370,  1678,  7407,  1679,
    1439, 12101, -1858, -1858,   621,   -30,   -17,   186,   214,   220,
    9620,   227, -1858,  1681, 14589, -1858, -1858,  1506, -1858, 12101,
   12101, -1858, -1858,  9867,  3408,  1687,  1444, 14965,   462, 17022,
   -1858, -1858, -1858, -1858,    40, -1858, 13388, -1858, 14618,  1441,
    1446,  1449,  1692,  3766, -1858,  1695,  1693, -1858, -1858,  1450,
    1698,   626, -1858,  1700,  1701,   383, 17022, 12101, 12101,  1459,
    7407,   627, 17022, 16922, -1858, -1858, -1858, -1858, 16947, 13704,
   -1858, -1858,  1090,  1157,  7407,   462, -1858, 12101, 13388,    22,
   -1858, -1858,  9867,  9867, 12101,  1702,   628, -1858, -1858, 12101,
    1362, -1858, 12101, -1858, -1858,   634,   637, -1858, -1858,  7407,
     566,   597,  9867, -1858, -1858,    73,  6355, -1858, -1858, -1858,
    1703, -1858,  1462,  7407, -1858, 14647,  1704,  9867,    -2,    -2,
      -2,    -2,    -2, -1858, -1858, 12101, 14676, 14705,   639, -1858,
   -1858, -1858, -1858, -1858, -1858,  1467,  1707,  1466, -1858,  1709,
   -1858, -1858,    21, -1858,  1533, -1858, -1858, -1858, -1858, -1858,
   12101, 13737, 13770,  7407, -1858,  1714, 12101,  1472, -1858, 12101,
    1470,  1476, -1858, -1858,  4426, -1858,  1478,   642,   644, 14734,
   -1858,  1481, 13803,  1479, 13836, -1858,  1485,   647,  1487,    -2,
    7407,  1715,  1489,    -2,  1716,   650,  1490, -1858, 12101, -1858,
    1720,  1590, 12743,  1500, -1858,   656,   242,   250,   274,   283,
     301,  3798, -1858, -1858,  1725,  1729, -1858, -1858, -1858,  1730,
   -1858,  1511, 17022, 12101, 12101,   657, -1858, 17022, 13869, -1858,
   -1858,  1090, 13388,  1515, -1858, -1858, -1858, 12101, 12101, -1858,
   12101,  9867,  1731,    -2,    23, -1858, -1858,    -2,   112, -1858,
    1761, -1858, 14763, -1858, 12101, -1858,   -75, -1858,  1762,  9867,
    9867,  9867,  9867,  9620, -1858, -1858, -1858, 13511, -1858, 12101,
   16972, 13902,    44, 12101,  1516, -1858, -1858, 13935, 13968, 14001,
     659, -1858,   306, -1858,   335, -1858, -1858, -1858,  3983,   465,
   12811, -1858,   665,   666,   668,   673,   339,   674,  1517,   680,
   -1858, 12101, -1858,  7407, 14792, -1858, 12101, 12101, 12101, -1858,
      -2,    -2, -1858, -1858, -1858,   -75,  1763,  1766,  1769,  1770,
    9867,  1771,  1773,  1775,  1529, 16997,   681,  1777, 14821, 14965,
   14034,   341,   343,   484, -1858, -1858, -1858, -1858,   682, -1858,
   -1858, -1858, 13293, -1858,  1534, -1858,  1778, -1858, 12101, 12101,
   12101, -1858,  1779,   683, -1858,  1535,  7407, -1858, 14850, 14879,
   14908, -1858,  1780, 13293, 13293,   688, -1858,  1784,  1785, -1858,
   -1858,   690, -1858,  1789, -1858, -1858,  1790, 13293, -1858, -1858,
   -1858
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
       0,     0,   196,     0,     0,   197,     0,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   326,   327,   328,   329,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,   295,   296,     0,     0,     0,   290,     0,     0,     0,
       0,     0,   378,   379,   380,     0,     0,     5,     6,     7,
       8,    10,     0,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   617,     0,   222,     0,     0,     0,     0,     0,     0,
     271,     0,   273,   274,   269,   270,     0,   275,   277,     0,
     278,   279,   115,   125,   616,   491,   486,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,     0,   207,
     208,   209,     0,     0,     0,     0,   432,   433,   435,   436,
     434,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   440,   441,   442,
       0,     0,   195,   200,   201,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   437,   438,   439,
       0,     0,     0,     0,     0,     0,     0,     0,   528,   529,
       0,   530,   504,   385,   445,   448,   309,   505,   486,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,   196,
     197,   198,   193,   200,   201,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   616,     0,     0,   222,     0,     0,   375,     0,     0,
       0,   204,   205,     0,     0,     0,     0,     0,   512,     0,
       0,   510,     0,     0,     0,     0,     0,   616,     0,     0,
     551,     0,     0,     0,     0,   267,   268,     0,   568,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   570,     0,   594,   572,   573,     0,     0,     0,
       0,     0,     0,   571,     0,     0,     0,     0,   288,   289,
       0,   222,     0,   222,     0,     0,     0,   486,     0,     0,
       0,   222,   381,     0,     0,    78,     0,    65,     0,     0,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,   557,   486,     0,   221,     0,
     220,     0,   174,     0,     0,   557,   558,     0,     0,     0,
     606,     0,   607,   558,     0,   113,   113,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   545,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   388,     0,
     387,   513,   389,     0,   506,     0,     0,   486,     0,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,   462,     0,     0,     0,     0,
       0,     0,     0,   310,     0,   343,   343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,   222,   222,
       0,   495,   494,     0,     0,     0,     0,   222,   222,     0,
       0,     0,     0,   306,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   345,     0,     0,
       0,     0,     0,   222,   248,     0,     0,   246,   376,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   353,
     266,     0,     0,     0,     0,     0,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   292,   291,     0,   253,     0,     0,   255,
       0,     0,     0,   387,     0,   222,     0,     0,     0,     0,
       0,     0,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    74,    75,     0,
       0,     0,   264,    40,   260,     0,     0,     0,     0,     0,
     217,     0,     0,     0,     0,     0,   223,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,   489,     0,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   337,     0,     0,
       0,   199,     0,     0,     0,     0,     0,     0,   371,   372,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   486,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   443,   461,     0,     0,     0,     0,   522,   523,
       0,     0,     0,     0,     0,   480,     0,   386,   507,     0,
       0,     0,     0,   515,     0,   405,   404,   402,   403,   398,
     400,   399,   401,   407,   406,   391,   390,     0,   392,   514,
     393,   396,   394,   395,   397,   487,     0,     0,   488,   465,
       0,   531,     0,     0,     0,     0,     0,     0,     0,     0,
     341,     0,     0,     0,     0,   374,     0,     0,     0,     0,
     373,     0,   222,     0,     0,     0,     0,     0,   497,   496,
       0,     0,     0,     0,     0,     0,     0,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,     0,     0,   247,     0,     0,     0,   241,     0,
       0,     0,     0,   370,     0,     0,     0,   386,   511,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   597,     0,     0,
       0,   482,     0,     0,   252,   256,   254,   258,     0,   392,
       0,   487,   465,   618,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,   386,     0,    65,     0,
       0,     0,     0,    81,     0,    65,    66,     0,     0,     0,
     487,     0,     0,   465,     0,     0,     0,   193,     0,     0,
       0,   613,    28,    26,    27,     0,     0,     0,     0,     0,
     488,   561,    30,     0,    29,     0,     0,   261,   608,   609,
       0,   610,   561,     0,    76,   116,    77,   126,   490,   492,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   547,   548,
     210,     9,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   431,   418,     0,   420,   421,   422,   423,   424,   544,
     425,   426,   427,     0,     0,     0,   536,   535,   534,     0,
       0,     0,   541,     0,   477,     0,     0,     0,   479,     0,
       0,     0,   130,   460,   518,   517,   203,     0,     0,   446,
     543,   451,     0,   457,     0,     0,     0,     0,   508,     0,
       0,   458,     0,   520,     0,     0,     0,     0,   450,   449,
     472,    72,    73,     0,     0,     0,     0,     0,     0,     0,
     386,   339,   344,   342,     0,   352,     0,   150,   151,   203,
     386,     0,     0,     0,     0,   242,     0,   257,   259,     0,
       0,     0,   211,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   313,     0,   297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
     346,   359,     0,     0,     0,   243,     0,     0,     0,     0,
     206,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,     0,     0,   584,     0,   591,   580,   581,   582,
       0,   596,   595,     0,     0,   585,   586,   587,   593,   600,
     599,     0,   141,     0,   574,     0,   576,     0,     0,     0,
     569,     0,   251,     0,     0,     0,     0,     0,     0,     0,
     332,     0,     0,     0,   382,     0,   614,     0,   103,    65,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,   566,    50,     0,     0,
       0,    63,     0,    41,    42,    43,    44,    45,     0,   450,
     449,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   560,   559,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,   133,   134,     0,     0,
       0,     0,     0,     0,     0,   157,   157,     0,     0,     0,
       0,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   525,   526,   527,     0,
       0,     0,     0,     0,   480,   481,     0,   453,     0,     0,
       0,   516,   408,   509,   466,   464,     0,   463,     0,     0,
     532,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     351,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,     0,     0,     0,   318,     0,     0,   317,
       0,   320,     0,   322,     0,   307,   314,     0,     0,     0,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     361,     0,   245,   244,   377,     0,     0,    37,    38,     0,
       0,     0,     0,   552,     0,     0,     0,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   482,   483,   578,     0,   466,     0,     0,   222,   333,
       0,   334,   222,     0,     0,   567,     0,    88,     0,     0,
       0,     0,    86,    93,    95,     0,   555,     0,   101,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,    36,
     466,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,   562,     0,     0,    34,
      33,     0,   562,   611,     0,     0,   117,   122,     0,     0,
       0,   136,   139,   140,   485,     0,    79,     0,     0,     0,
       0,    80,   161,     0,     0,     0,     0,   162,   177,   178,
     159,     0,     0,     0,   163,   188,   179,   183,   184,   180,
     181,   182,   169,     0,     0,   419,   428,   429,   430,   537,
       0,     0,     0,   475,   476,   478,   131,   444,   474,   447,
     452,     0,     0,   480,   189,   459,     0,    72,    73,     0,
     471,   467,   469,   538,   185,     0,     0,     0,   153,     0,
       0,   350,     0,   152,     0,     0,     0,     0,   265,     0,
       0,     0,     0,   222,   222,     0,     0,   319,   504,     0,
       0,   321,   323,     0,     0,   301,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   186,     0,     0,
       0,     0,   166,   167,     0,     0,     0,     0,   104,   105,
     106,   110,     0,   592,     0,     0,   590,     0,   601,     0,
       0,   142,   143,   598,   575,   577,     0,     0,     0,     0,
       0,     0,   331,   335,   331,     0,   383,    87,    65,     0,
       0,     0,     0,    85,     0,   553,     0,     0,     0,     0,
       0,     0,   604,   603,     0,     0,     0,     0,     0,   502,
       0,     0,   471,   262,   467,   263,     0,     0,     0,     0,
       0,   227,   224,     0,     0,   565,   563,     0,     0,     0,
     118,   123,     0,     0,     0,   545,   546,   135,   354,   355,
     356,   357,   158,   164,   165,   170,     0,     0,     0,     0,
       0,   172,     0,     0,     0,     0,     0,     0,   454,     0,
       0,     0,     0,   533,   473,     0,     0,   171,     0,   190,
     340,     0,     0,   191,     0,     0,     0,     0,     0,     0,
     501,   500,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   238,     0,     0,     0,     0,     0,     0,
       0,     0,   229,     0,     0,   358,    39,     0,   550,     0,
       0,   285,   284,     0,     0,     0,     0,     0,     0,   145,
     146,   149,   148,   147,     0,   579,     0,   615,     0,     0,
       0,     0,     0,     0,    98,     0,     0,    99,   556,     0,
       0,     0,    90,     0,     0,     0,    46,     0,     0,     0,
       0,     0,    48,     0,   228,   225,   226,    35,     0,     0,
     612,   276,   130,   141,     0,     0,   138,     0,     0,     0,
     160,   187,     0,     0,     0,     0,     0,   539,   540,     0,
     480,   455,     0,   468,   470,     0,     0,   173,   194,     0,
     347,   347,     0,   111,   112,   222,     0,   214,   215,   308,
       0,   315,     0,     0,   222,     0,     0,     0,     0,     0,
       0,     0,     0,   219,   218,     0,     0,     0,     0,   107,
     108,   583,   589,   588,   144,     0,     0,     0,   336,     0,
      94,    96,     0,   102,     0,    84,   605,    91,    92,    51,
       0,     0,     0,     0,   503,     0,     0,   468,   564,     0,
       0,     0,   120,   602,     0,   127,     0,     0,     0,     0,
     176,     0,     0,     0,     0,   311,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,   325,
       0,     0,   302,     0,   230,     0,     0,     0,     0,     0,
       0,     0,   549,   286,     0,     0,   369,   222,   384,     0,
     554,     0,    47,     0,     0,     0,    64,    49,     0,   119,
     124,   130,     0,     0,   155,   156,   154,     0,     0,   456,
       0,     0,     0,     0,     0,   348,   362,     0,     0,   363,
       0,   212,     0,   316,     0,   298,     0,   222,     0,     0,
       0,     0,     0,     0,   168,   109,   282,   331,   100,     0,
       0,     0,     0,     0,     0,   128,   129,     0,     0,     0,
       0,   192,     0,   366,     0,   367,   368,   498,     0,     0,
     304,   233,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    61,     0,     0,   121,     0,     0,     0,   312,
       0,     0,   324,   303,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,   235,   236,   237,     0,   231,
     338,    52,     0,    59,     0,   272,     0,   542,     0,     0,
       0,   305,     0,     0,    53,     0,     0,   281,     0,     0,
       0,   232,     0,     0,     0,     0,   524,     0,     0,    56,
      54,     0,    57,     0,   364,   365,     0,     0,    62,    60,
      58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1858, -1858, -1858, -1858,   436, -1858, -1858, -1858, -1858,  -301,
   -1858, -1858, -1858, -1858, -1858, -1858, -1858, -1858, -1858, -1858,
   -1858, -1858,  -724,  -107,  4484,  3760, -1858,  1333, -1858, -1858,
   -1858, -1858, -1858, -1858, -1857, -1858,   384,   206,  -106, -1858,
     -72, -1858,   148,   422, -1858,  1802, -1858,   713,   -48, -1858,
   -1858,     0,  -622,  -298, -1858, -1858, -1858, -1858, -1858, -1858,
   -1858, -1858,  1806, -1858, -1858, -1858, -1858, -1236, -1230,  1807,
   -1717,  1808, -1858, -1858, -1858,  1208, -1858,  -126, -1858, -1858,
   -1858, -1858,  2430, -1858, -1858, -1417,   295,  1814, -1858,     3,
    -701, -1858, -1858,   -59, -1858, -1677,   649,  -165,  2957,  1182,
    -312,    76, -1858,   299,    54, -1858, -1858,   100,   268, -1662,
    -122,  1051, -1858,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   117,  1065,   118,   119,  1049,  1895,  1901,
    1343,  1554,  2051,  2183,  1344,  2154,  2201,  1345,  2185,  1346,
    1347,  1558,   439,   595,   596,  1138,   120,   779,   465,  1912,
    2061,  1913,   466,  1784,  1420,  1375,  1376,  1377,  1518,  1721,
    1722,  1206,  1613,  1604,  1797,   756,   607,   276,   277,   354,
     203,   278,   449,   450,   124,   125,   126,   127,   128,   129,
     130,   131,   279,  1238,  2086,  2145,   945,  1234,  1235,   280,
    1028,   281,   135,  1449,  1204,   920,   960,  2021,   136,   137,
     138,   139,   282,   283,  1162,  1177,  1299,   284,   784,   285,
     909,   783,   468,   622,   322,  1758,   361,   362,   287,   565,
     369,  1330,  1547,   460,   455,  1292,  1005,  1593,  1751,  1752,
     990,   462,   141,   417
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     142,   617,  1478,   123,  1476,   940,   941,  1642,  1039,   321,
     323,  1844,   326,  1337,   307,  1879,  1047,  1880,  1022,   178,
     651,   341,   166,   164,  1602,   367,   164,   633,   165,  2113,
     496,   410,   164,   422,   461,   440,   164,  1272,   503,   150,
    1471,   412,   546,   312,  1719,  1473,   656,  1053,   569,   732,
    2132,   288,  1538,   182,   371,  2000,   346,  1872,   347,   293,
     164,   327,  1611,  1227,  1071,   745,   777,  1798,   313,   434,
     435,   293,   778,  1372,  1082,   760,  1062,   447,  1508,  1436,
     345,  1228,   294,   761,   314,   315,  1799,   762,   288,  1229,
    1230,  1231,  1574,   370,  1056,  1232,  1233,   766,   625,   626,
       4,   469,   591,   199,   406,   767,   200,   342,  1319,   201,
       5,  1612,   773,   708,   780,   711,   625,   626,  2115,   935,
     778,  1915,   202,   723,   625,   626,  1926,   625,   626,   145,
     604,   605,   606,   625,   626,   625,   626,   942,   147,   446,
     627,   571,  1171,   448,   456,   456,   456,  1172,   946,   167,
     348,   168,   768,   463,  1459,   328,  1477,   146,  1175,   329,
     769,   405,   771,   409,   351,   330,   331,   352,   332,   333,
     772,   475,   647,   648,   649,  1045,   434,   435,  1180,  1860,
     353,  1509,  1510,  1338,  1339,  1340,  1341,   456,   334,   663,
     152,   591,   288,   625,   626,   288,   445,   542,   543,   143,
     288,   288,   456,   144,  2104,   153,  1472,   625,   626,   625,
     626,  1474,   343,   716,  1841,   148,    67,    68,    69,    70,
     625,   626,    73,   470,   308,   628,  1809,   309,  1957,   733,
     734,    82,  1539,  1540,    85,   317,   318,   149,   116,  1720,
     116,  1958,   116,   116,   156,  1038,   815,   319,  1476,   116,
     816,   320,  1319,   116,   288,   625,   626,   620,   621,  1738,
     625,   626,  2017,  1342,   179,   629,   634,   652,   288,   653,
     344,   288,   567,   144,   368,  1004,   423,   116,   566,   411,
     424,  1329,   737,   154,   738,  1273,   151,   288,   288,   413,
     547,   288,   288,   288,   288,   155,   570,  2133,   183,   372,
    1319,   434,   435,  1063,   288,   746,  1064,   747,   288,  -558,
     370,   748,  1320,  1323,   157,   167,  2055,   168,   931,  1063,
     933,   934,  1064,   430,   431,   432,   433,   763,   167,   764,
     168,   158,   288,   765,   288,   288,   288,   947,   434,   435,
     159,   167,   592,   168,   593,  1148,   434,   435,   594,   625,
     626,   288,   774,   160,   764,   966,  1322,   288,   775,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   161,   984,   303,
    2128,   590,   304,   162,   305,   868,   737,  1837,   738,   163,
    1046,   431,   432,   433,  1168,   306,   175,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,   456,   288,  1020,   858,   590,
     288,   288,  1158,   625,   626,  1861,   298,   434,   435,   299,
     772,   592,   300,   593,   301,   196,   288,   594,   625,   626,
     337,   444,   338,   749,  1959,    46,   454,   457,   458,   434,
     435,   625,   626,   717,   635,   718,  2156,   625,   626,   719,
     430,   431,   432,   433,   625,   626,   785,   430,   431,   432,
     433,  1423,  1960,  1424,   430,   431,   432,   433,  1961,   625,
     626,   727,   176,   434,   435,  1962,  1434,   625,   626,   491,
     434,   435,   177,   625,   626,   288,  1227,   434,   435,   170,
    2089,   195,   171,  1297,   505,   172,  1298,   173,  2090,  2195,
    1463,   625,   626,  2013,  1228,   430,   431,   432,   433,   288,
     625,   626,  1229,  1230,  1231,   180,   288,   848,  1232,  1233,
     181,   456,  2091,   456,   288,   456,   456,   463,   625,   626,
     184,  2092,   864,   625,   626,   185,   288,   288,   288,   456,
     456,   288,   166,   737,   166,   738,   288,  1227,   873,  2093,
     875,   772,   992,   571,  2140,   186,   938,   939,   588,   589,
     187,   621,   625,   626,   590,  1228,   625,   626,   625,   626,
     625,   626,   288,  1229,  1230,  1231,   194,  1361,   905,  1232,
    1233,   198,   737,  2141,   738,   816,  1521,  2150,  1366,  2179,
    1275,  2180,  1525,  1227,   317,   318,   816,   197,   288,   288,
     874,   737,  1475,   738,   878,   737,   319,   738,   816,  1295,
     325,  1228,  1227,   816,  1367,  1040,  1488,   448,   448,  1229,
    1230,  1231,   816,  1989,  1216,  1232,  1233,   529,   188,   530,
    1228,  1990,   714,   586,   587,   588,   589,  1560,  1229,  1230,
    1231,   590,  1668,  1669,  1232,  1233,   288,   288,   288,   204,
     167,  1576,   168,   434,   435,   674,  1174,   144,  1582,  1175,
     189,  -560,   295,  1685,  1351,   296,  1305,   297,  -561,   463,
     456,   463,   456,   456,   456,   456,   456,   456,   190,   456,
     456,   456,   456,  1006,   191,   456,   456,   456,   166,  1012,
     434,   435,   288,   286,  1011,   192,  1058,   420,  -565,  2018,
    2019,   421,   737,  1021,   738,  2020,   122,   720,  1761,  2143,
    1729,   636,  -562,  1711,  1712,   637,   288,  1662,   583,   584,
     714,   586,   587,   588,   589,  1191,   288,  1192,  2181,   590,
    2022,  2023,  1050,   913,   914,   290,  2020,   816,   816,   957,
    1024,  1007,  1030,   816,   816,   193,  1031,  1178,   288,  1067,
    1304,   816,  1305,  1211,   288,   205,   288,   816,  1212,   463,
    1080,  1257,   816,  1258,   302,   816,  1085,   816,   456,   625,
     626,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   814,   586,   587,   588,   589,   289,
    1259,  1190,  1301,   590,   816,   737,   816,   738,  1332,   291,
     292,   288,   816,   288,  1739,  1409,  1416,  1433,  1441,   816,
     816,   816,   816,  1456,  1572,   311,  1748,   816,   816,  1647,
    1624,  1648,  1655,   852,   816,   854,   816,   856,   857,  1656,
    1745,   310,   316,   816,  1746,  1096,   288,  1728,   324,  1729,
    2119,   870,   871,   504,  1768,   442,   288,   335,   816,  1770,
     442,   442,   442,   816,  1853,   336,  1899,  1916,   816,   442,
    1900,  1917,   339,  1940,  1941,  1956,  1219,   816,   816,  1900,
    1986,  1995,  2011,  1225,   772,  1996,  1900,  1236,  2015,  1476,
     340,  2016,   816,  2044,   288,   816,  2064,   816,  2065,   349,
     816,  2072,   816,   442,  2080,  1900,   286,   288,   816,  2163,
    2088,  2102,   350,  2139,   816,  1900,   288,   816,   442,  2146,
    2147,   355,  2148,   816,   816,   288,   816,  2149,  2151,  1321,
    1324,   816,   816,  1476,  2153,  2174,  2182,  2192,  1996,  1900,
     816,  2193,  2203,   603,  2206,   356,  1900,   737,  2207,   738,
     739,   737,   357,   738,   910,   363,   610,   541,   364,  1822,
     615,  1823,   375,   365,   366,   373,   376,   374,   425,   407,
     377,   452,   550,   551,   418,   419,  1208,   467,   426,   451,
     469,   471,   991,  1506,   993,   994,   995,   996,   997,   998,
     144,  1000,  1001,  1002,  1003,   472,   473,  1008,  1009,  1010,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,   474,  1546,   479,   483,
     590,  -196,   497,   537,   502,   540,  -197,  -198,   288,   549,
     548,   552,   555,   556,   557,   568,   614,   600,  1384,  1331,
     421,   601,   654,   608,   288,   657,   611,   616,   618,   619,
     638,  1833,  1834,   639,   640,   641,   642,   288,   643,   644,
     650,   658,   456,   655,   669,   670,   659,   660,   661,   662,
     664,  1078,   724,   725,   665,   666,   677,   685,   676,   686,
    1087,  1435,  1437,   702,   687,   698,   699,   701,   735,   703,
     704,   706,  1325,   709,   705,   288,   288,   707,   288,   288,
     288,   710,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   726,   729,   288,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
     736,   442,   741,   743,   590,   744,   143,   782,   750,   786,
     791,   728,   807,   812,   818,   819,   820,   849,   859,   590,
     860,   861,   288,   456,   456,   879,   881,   882,   908,   918,
     919,   922,   925,   757,   929,   930,   932,   959,   961,   978,
     962,   964,   973,   982,   985,  1029,   288,  1014,  1016,  1023,
    1033,  1034,  1042,  1043,  1041,  1054,   855,  1055,  1060,  1070,
    1072,  1090,   288,   288,   288,  1074,  1077,  1084,   603,  1086,
     869,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,  1089,
    1097,  1098,  1099,   590,  1101,  1507,  1102,  1103,  1105,  1106,
    1732,  1107,  1108,  1744,  1734,  1109,  1110,  1111,  1112,  1448,
    1113,  1114,  1435,  1437,  1117,  1121,   288,   442,   448,   442,
    1146,   442,   442,   442,  1147,  1155,  1156,  1157,  1164,  1167,
    1173,   288,   288,   288,  1179,   442,   442,  1182,  1187,  1183,
    1195,  1196,   288,  1197,  1205,  1203,   742,   456,  1214,  1222,
    1223,   456,  1226,  1248,  1249,  1251,  1267,  1264,  1265,  1266,
     456,  1278,   456,  1279,  1291,   456,  1280,  1294,  1283,   759,
    1293,  1300,  1306,  1303,  1307,  1308,  1309,  1312,  1314,  1313,
     288,  1318,  1327,  1328,  1333,  1348,  1334,  1354,  1355,  1356,
    1357,  1362,  1365,  2026,  1369,  1370,   370,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,  1374,   757,   456,  1419,   590,
    1387,  1391,   288,  1403,   288,  -199,  1445,  1427,  1446,  1447,
    1450,  1451,  1452,  1453,  1360,  1454,  1455,  1457,  1464,   757,
    1465,   288,  1468,  1469,  1470,  1479,  1480,  1492,  1035,  1481,
     501,  1482,  1402,  1491,   288,  1483,  1484,  1485,   288,  1486,
    1487,  1493,  1494,  1495,  1496,   442,   442,   442,   442,   442,
     442,   442,   442,   442,  1497,   442,   442,   442,   442,  1498,
    1503,   442,   442,   442,  1511,  1517,  1524,  1516,  1684,  1523,
    1526,   757,  1537,  1528,   757,  1532,  1587,  1534,  1592,  1753,
    1753,  1740,  1542,  1543,  1888,  1545,   757,  1548,  1549,  1553,
    1559,  1555,   288,   288,   288,  1556,  1573,  1557,  1579,  1571,
     288,  1580,  1577,  1594,  1596,  1414,  1415,  1595,  1601,  1603,
    1607,  1608,  1609,  1614,  1615,   288,  1057,  1616,  1059,  1617,
    1618,  1619,   598,   599,  1620,  1621,   288,  1622,  1623,  1650,
    1644,  1696,  1633,  1654,   288,   442,  1640,  1660,   288,  1667,
    1661,  1665,  1676,  1666,   442,  1673,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,  1674,  1675,  1681,   645,   590,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,  1682,  1697,  1688,
    1689,   590,   370,  1814,  1792,  1690,  1702,  1691,   463,   463,
    1692,  1703,  1693,  1699,   288,  1708,  1704,  1709,  1710,  1714,
    1724,  1717,  1298,  1736,  1731,  1735,  1742,  1741,  1202,  1755,
    1760,  1762,   456,  1767,  1763,  1765,  1771,  1772,  1727,  1513,
    1774,  1775,   288,  1515,  1778,  1782,  1788,   288,  1789,  1790,
    1791,  1793,  1519,  1794,  1520,  1795,  1800,  1522,  1796,  1801,
    1802,   721,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
    1175,  1817,  1803,  1819,   590,  1808,  1842,  1891,  1843,  1852,
    1845,  1846,  1847,  1848,  1849,  1851,  1856,  1815,  1884,  1781,
    1885,  1816,  -563,  1875,   757,  1887,   757,   757,  1838,  1562,
    1874,  1892,  1876,   772,  1904,  1814,  2032,  1905,  1906,   288,
     757,  1907,   288,   288,  1911,  1914,  1919,  1920,  1921,  1925,
    2049,  1922,  1923,   448,   448,  1924,  1937,  1938,  1939,   757,
    1315,  1944,  1931,  1945,  1951,   288,  1953,  1963,  1965,  1947,
    1948,   288,  1954,  1970,  1971,  1977,  1335,   757,  1980,  1983,
    1978,   288,  1982,  1979,  1985,  1984,  1987,  1988,  2010,  2029,
    2034,   456,  1993,  2046,   456,  2048,  2030,  2045,  2050,  2047,
    2056,  2076,  2079,  1828,  2059,  -564,  2083,  2063,  2084,  2069,
    2060,  2095,   288,   757,  2067,  2096,  2098,  2111,  2071,  1331,
    2073,   876,  2077,   370,  2081,   288,   463,  1385,  1386,  2097,
    1388,  1389,  1390,  2087,  1392,  1393,  1394,  1395,  1396,  1397,
    1398,  1399,  1400,  1401,  2099,  2106,  1865,  2116,  2121,  2164,
    2135,  2152,  2165,  1870,  1873,  2166,  2167,  2169,   442,  2170,
     463,  2171,  2172,  2175,  2187,  2191,  2199,  2186,  2194,  2120,
    2204,  2205,  1882,   926,   927,  2208,  2209,  1575,  2129,   781,
     288,  1787,  1974,  1636,  1413,   121,  1818,  2001,  1605,   132,
     133,   134,   288,   288,   921,  2024,  1726,   140,  1886,  1871,
    1754,     0,  1490,  1079,     0,     0,     0,     0,  1428,     0,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
       0,   969,   970,   971,  1442,     0,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,     0,     0,     0,     0,   442,
     442,     0,     0,     0,  1773,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1013,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   288,  1489,  2036,
    2037,  2038,  2039,  2040,     0,     0,     0,     0,     0,     0,
       0,   288,     0,  1500,  1501,  1502,  2006,     0,     0,   288,
     288,  1044,     0,     0,     0,     0,     0,     0,     0,   757,
    1975,     0,     0,     0,     0,     0,   288,     0,     0,   288,
       0,     0,     0,  1066,     0,   448,     0,     0,     0,  1073,
     288,  1075,     0,     0,   288,     0,     0,     0,     0,     0,
    2074,     0,  1533,     0,  2078,     0,     0,     0,     0,     0,
       0,     0,  2005,     0,     0,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,     0,     0,   442,     0,     0,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,   442,     0,   442,     0,
       0,   442,     0,  1866,  2112,     0,  1868,   288,  2114,     0,
    1527,     0,     0,  1591,  1531,     0,     0,     0,     0,     0,
       0,  1149,     0,     0,  2126,     0,  1606,     0,     0,     0,
    1610,  1159,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,   442,   590,     0,     0,     0,   288,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1186,
       0,  2161,  2162,     0,     0,     0,   288,   288,   288,   288,
     288,     0,  1194,     0,  1657,  1658,  1659,     0,     0,     0,
       0,     0,  1664,     0,     0,     0,     0,     0,   164,   378,
    1213,     0,     0,     0,     0,     0,  2105,  1679,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1687,     0,
     288,     0,     0,     0,     0,     0,  1695,     0,     0,     0,
    1544,     0,     0,     0,     0,     0,     0,   288,     0,     0,
       0,   379,   380,   381,   382,   383,   384,   385,   386,   387,
       0,     0,     0,     0,   388,   389,   390,   391,     0,   456,
       0,     0,   392,   393,   394,     0,     0,     0,  1677,   395,
       0,   396,     0,   288,     0,     0,     0,     0,     0,     0,
     456,   456,     0,     0,     0,   397,     0,     0,   398,     0,
       0,     0,   298,     0,   456,   299,  1759,     0,   300,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1780,     0,     0,     0,   428,     0,
       0,     0,  1359,     0,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,   442,   442,   590,     0,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,   442,     0,
     590,     0,   737,     0,   738,     0,     0,     0,     0,  1404,
    1715,     0,     0,     0,     0,     0,     0,   399,   400,   401,
       0,  1821,     0,     0,     0,     0,     0,     0,   402,     0,
       0,     0,   403,     0,   404,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1759,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   434,
     435,     0,     0,  1857,     0,     0,     0,  -559,     0,  1561,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,  1443,  1444,
       0,     0,   590,     0,  1881,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1890,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,  1733,     0,   442,     0,     0,
     442,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,   757,     0,   757,   590,     0,
       0,     0,  1759,     0,     0,     0,     0,  1512,     0,     0,
       0,     0,   442,     0,     0,   164,   378,     0,     0,     0,
       0,  2184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1952,     0,     0,
       0,     0,  2200,  2202,     0,     0,   442,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2210,     0,   379,   380,
     381,   382,   383,   384,   385,   386,   387,     0,     0,     0,
       0,   388,   389,   390,   391,     0,     0,     0,     0,   392,
     393,   394,     0,     0,     0,     0,   395,  1568,   396,  1570,
       0,     0,     0,     0,     0,   416,     0,     0,     0,  1994,
       0,     0,   397,     0,     0,   398,     0,     0,     0,   298,
       0,     0,   299,  2002,     0,   300,     0,   301,     0,     0,
       0,     0,   443,     0,     0,     0,   453,     0,    46,     0,
       0,   459,     0,     0,     0,     0,     0,     0,  1759,   464,
       0,     0,  1737,     0,     0,   428,     0,     0,     0,     0,
       0,     0,  2031,     0,     0,   476,   477,   478,     0,   480,
     481,   482,     0,   484,   485,   486,   487,   488,   489,   490,
       0,   492,   493,   494,   495,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1759,     0,     0,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,   399,   400,   401,   590,     0,  2075,
       0,     0,     0,  1698,     0,   402,     0,     0,     0,   403,
       0,   404,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   560,   562,   563,   499,     0,     0,     0,     0,     0,
       0,   737,     0,   738,  1749,     0,     0,     0,     0,   597,
     499,   499,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
       0,     0,     0,     0,     0,   757,     0,     0,     0,   623,
     624,     0,     0,     0,     0,   624,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,   646,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1759,     0,     0,     0,     0,     0,     0,   667,
     499,     0,     0,     0,   671,   672,   673,     0,   675,     0,
       0,     0,   678,   679,   680,     0,     0,   681,     0,     0,
     757,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,   757,   590,  1759,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   713,     0,  1824,  1825,   499,
     722,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   730,   731,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   758,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   787,   788,   789,   790,     0,   442,   442,     0,   795,
       0,     0,     0,   799,     0,     0,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,   813,   560,     0,
       0,     0,   817,     0,     0,     0,   821,   822,   823,   824,
     825,   826,   827,   828,   829,   830,   831,   832,   833,   834,
     835,   836,   837,   839,   840,   841,   842,   843,   844,   845,
     845,     0,   850,   851,     0,   853,     0,     0,     0,     0,
       0,     0,     0,     0,   862,     0,     0,   866,   867,     0,
       0,     0,     0,     0,   845,     0,     0,     0,     0,   499,
       0,     0,     0,     0,     0,     0,     0,  1935,  1936,     0,
       0,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     892,   893,   894,   895,   896,   898,   900,   901,   902,   903,
     904,     0,   906,   907,     0,     0,     0,     0,     0,     0,
     915,   916,   917,     0,     0,     0,     0,     0,   923,   924,
       0,   499,   499,     0,     0,  1968,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,   713,   943,     0,     0,     0,   948,   949,   950,   951,
     952,   953,   954,   955,   956,     0,  1743,     0,     0,     0,
     963,     0,   965,     0,     0,   967,     0,     0,     0,   499,
     499,   499,   972,     0,   974,   975,   976,     0,     0,     0,
       0,     0,     0,     0,  2007,  2008,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   999,     0,     0,  2025,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,     0,     0,     0,  2035,
       0,     0,  1018,     0,  1019,     0,     0,   906,   907,     0,
       0,     0,     0,     0,     0,   500,  1032,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,  1048,     0,     0,     0,  1855,  1051,  1052,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   499,     0,  1068,  1069,     0,     0,   499,     0,   499,
    1076,     0,     0,     0,  1068,     0,  1083,     0,     0,     0,
       0,     0,  1088,     0,     0,     0,  1091,  1943,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   561,     0,
       0,   500,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1115,     0,   898,     0,  1118,   500,   500,     0,
       0,     0,     0,  2110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2122,  2123,  2124,  2125,  2127,     0,     0,     0,   499,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
    1160,  1161,   500,     0,     0,     0,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,   500,   590,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,  2168,     0,     0,     0,     0,     0,     0,     0,
     499,     0,     0,     0,     0,     0,     0,     0,  1201,     0,
       0,     0,  1207,     0,     0,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,  1220,  1221,     0,     0,
       0,     0,  1224,     0,     0,     0,   500,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1250,
       0,     0,  1252,     0,     0,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,  1268,  1969,  1270,  1271,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1289,     0,     0,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,   561,     0,  1311,     0,   590,
       0,     0,     0,     0,  1317,     0,     0,     0,     0,  1326,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   838,
       0,     0,     0,     0,  1352,  1353,   846,   847,     0,     0,
     499,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,   872,     0,   590,     0,     0,   500,     0,     0,   811,
       0,     0,  1379,  1380,  1381,  1382,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   899,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1405,     0,     0,     0,     0,   500,   500,
       0,     0,     0,  1406,  1407,  1408,     0,     0,     0,     0,
    1410,  1411,     0,  1412,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,  1421,  1422,     0,
       0,     0,     0,     0,     0,  1425,  1426,     0,     0,     0,
       0,     0,  1430,     0,  1431,  1432,   500,   500,   500,     0,
       0,  1438,  1439,     0,     0,     0,   499,   499,     0,     0,
       0,     0,     0,     0,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,  1467,     0,
       0,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,  1499,     0,    48,   500,     0,     0,     0,
       0,     0,   751,    55,     0,   499,    58,   752,     0,   753,
     754,     0,   755,  1514,     0,     0,     0,     0,   500,     0,
       0,     0,     0,     0,   500,     0,   500,     0,     0,     0,
      79,     0,     0,     0,  1438,  1439,     0,     0,     0,  1530,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1536,     0,     0,  1541,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   899,  1981,  1119,   164,   378,     0,     0,     0,     0,
       0,  1563,     0,     0,  1566,   499,  1569,   499,     0,     0,
       0,     0,     0,     0,     0,  1578,     0,     0,  1581,     0,
    1578,  1584,  1586,     0,  2094,     0,   500,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,   379,   380,   381,
     382,   383,   384,   385,   386,   387,     0,     0,     0,   944,
     388,   389,   390,   391,     0,     0,     0,     0,   392,   393,
     394,     0,     0,     0,     0,   395,     0,   396,     0,     0,
       0,     0,     0,     0,   500,     0,     0,     0,     0,     0,
       0,   397,     0,     0,   398,     0,     0,   500,   298,     0,
       0,   299,     0,     0,   300,     0,   301,     0,     0,     0,
       0,     0,  1663,     0,     0,   500,     0,    46,     0,  1670,
    1671,  1672,     0,     0,     0,     0,     0,     0,  1678,     0,
    1680,     0,     0,     0,   428,     0,     0,  1683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   499,     0,     0,     0,     0,  1700,     0,     0,     0,
       0,     0,     0,     0,  1705,  1706,  1707,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1718,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1730,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   399,   400,   401,     0,     0,     0,  1747,
       0,     0,     0,     0,   402,  1756,  1757,     0,   403,  2142,
     404,   116,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,   500,     0,     0,
    1785,     0,     0,  1749,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1804,  1805,  1806,     0,     0,     0,     0,     0,     0,     0,
       0,  1807,     0,     0,   500,     0,  1810,  1811,  1812,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1820,     0,     0,     0,     0,   499,   499,  1826,     0,  1827,
       0,     0,     0,     0,     0,  1835,  1836,     0,     0,     0,
    1918,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   499,     0,     0,     0,     0,  1854,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1864,     0,     0,  1867,     0,     0,     0,  1869,
       0,     0,     0,   500,   500,     0,     0,     0,  1811,  1812,
       0,  1878,     0,     0,     0,     0,     0,     0,     0,  1883,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1896,     0,     0,     0,     0,
    1902,  1903,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   740,     0,     0,  1908,     0,     0,  1909,  1908,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1946,     0,     0,     0,     0,     0,     0,     0,
       0,  1955,     0,     0,     0,     0,     0,     0,     0,     0,
     560,     0,     0,     0,     0,     0,     0,     0,     0,  1966,
    1967,     0,     0,   499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   863,     0,     0,     0,     0,
       0,     0,   500,     0,   500,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,  1991,  1992,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   814,   586,   587,   588,   589,  2004,     0,     0,
       0,   590,   499,   499,  2009,     0,   911,     0,     0,  2012,
       0,     0,  2014,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   499,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,  2041,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
    2052,     0,    43,    44,    45,    46,  2057,     0,    48,  2058,
       0,     0,     0,  2062,     0,   751,    55,     0,     0,    58,
     752,     0,   753,   754,     0,   755,     0,     0,   500,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2082,     0,
       0,     0,     0,    79,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,  2100,  2101,     0,   590,    93,    94,    95,
       0,     0,  1831,     0,     0,     0,  1832,  2107,  2108,     0,
    2109,   499,     0,     0,     0,     0,     0,     0,     0,     0,
     169,     0,   174,     0,  2118,     0,     0,     0,     0,   499,
     499,   499,   499,   499,     0,     0,     0,     0,     0,  1902,
       0,     0,     0,  2134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1786,     0,     0,
       0,     0,     0,     0,     0,     0,   571,     0,     0,     0,
       0,  2155,   968,     0,     0,     0,  2158,  2159,  2160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     499,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,
    1131,  1132,     0,  1134,  1135,  1136,  1137,     0,  1139,  1140,
    1141,  1142,     0,   571,     0,     0,     0,     0,  2188,  2189,
    2190,     0,  1152,     0,  1154,     0,     0,     0,     0,     0,
       0,     0,   500,   500,  1163,     0,   441,     0,     0,     0,
       0,  1169,  1170,     0,     0,     0,     0,     0,     0,     0,
    1181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   500,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   531,   532,
     533,   534,   535,   536,     0,   538,   539,     0,     0,     0,
       0,     0,     0,     0,   544,   545,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   553,   554,     0,     0,
    1274,  1276,  1277,     0,     0,     0,  1281,  1282,     0,     0,
    1285,  1286,  1287,  1288,     0,  1290,     0,     0,     0,     0,
    1296,     0,   500,   500,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   986,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   561,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     500,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   814,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
       0,  1378,     0,     0,     0,     0,  1383,     0,     0,     0,
       0,     0,     0,   682,   683,   684,     0,     0,     0,   688,
     689,   690,   691,   692,   693,   694,     0,   695,     0,   500,
     500,   696,   697,     0,     0,   700,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   712,   500,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     206,   164,   378,     0,   500,     0,     0,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   414,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,  1440,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   239,   240,   241,   242,   388,   389,   390,
     391,   243,     7,     8,     0,   392,   393,   394,     0,     0,
       0,     0,   395,     0,   396,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,    25,   397,   251,
       0,   398,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,   500,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,   500,   500,   500,
     500,   880,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,   751,    55,     0,     0,
      58,   752,  1550,   753,   754,  1184,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   500,     0,   261,
     399,   400,   401,   262,    79,     0,     0,     0,   264,   265,
     266,   402,   267,   268,   269,   403,     0,   404,   116,     7,
       8,     0,     0,  1588,     0,     0,     0,     0,    93,    94,
      95,     0,     0,     0,   270,   415,     0,     0,     0,     0,
       0,   272,     0,     0,  1185,     0,   359,     0,     0,     0,
    1585,     0,     0,   275,     0,  1625,  1626,  1627,  1628,  1629,
       0,     0,     0,     0,  1634,  1635,     0,     0,     0,     0,
    1637,     0,  1639,     0,     0,     0,  1643,     0,     0,  1645,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1653,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1015,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,   751,    55,     0,     0,    58,   752,     0,
     753,   754,     0,   755,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,  1713,     0,  1716,     0,     0,     0,  1723,     0,
    1725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1750,     0,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1505,     0,     0,     0,     0,     0,     0,  1176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1017,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,  1193,   590,     0,     0,     0,   206,     6,
     378,     0,     0,     0,     0,   207,   208,   209,     0,  1813,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,  1589,   380,   381,   382,   383,   384,   385,   386,
     387,   239,   240,   241,   242,   388,   389,   390,   391,   243,
     244,     0,     0,   392,   393,   394,     0,     0,   245,   246,
     395,     0,   396,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,   250,    25,   397,   251,     0,   398,
       0,     0,     0,   252,     0,     0,   253,     0,     0,   254,
       0,   255,     0,     0,     0,     0,     0,     0,    42,     0,
       0,  1893,   256,     0,  1894,     0,     0,     0,     0,     0,
       0,     0,   257,     0,    56,    57,     0,   258,     0,   259,
       0,     0,   260,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,     0,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    82,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,  1927,  1928,     0,  1930,     0,  1373,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,   261,   399,   400,
     401,   262,   263,     0,     0,     0,   264,   265,   266,   402,
     267,   268,   269,   403,     0,   404,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1972,  1973,     0,
       0,     0,   270,   271,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,   359,     0,     0,     0,  1590,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1429,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2003,     0,     0,     0,   206,
       6,   378,     0,     0,     0,     0,   207,   208,   209,     0,
       0,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   239,   240,   241,   242,   388,   389,   390,   391,
     243,   244,     0,     0,   392,   393,   394,     0,     0,   245,
     246,   395,     0,   396,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,   250,    25,   397,   251,     0,
     398,     0,     0,     0,   252,     0,     0,   253,     0,     0,
     254,     0,   255,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,     0,    56,    57,     0,   258,     0,
     259,     0,     0,   260,     0,     0,     0,  1551,  1552,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   977,     0,     0,     0,     0,     0,     0,     0,
     936,     0,     0,     0,     0,     0,     0,     0,   261,   399,
     400,   401,   262,   263,     0,     0,     0,   264,   265,   266,
     402,   267,   268,   269,   403,     0,   404,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1641,     0,
       0,     0,     0,   270,   271,     0,     0,     0,  1649,  2177,
     272,     0,     0,     0,     0,   359,   206,   164,   378,   274,
     427,     0,   275,   207,   208,   209,     0,     0,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   414,   228,   229,   230,   231,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   239,
     240,   241,   242,   388,   389,   390,   391,   243,     0,     0,
       0,   392,   393,   394,     0,     0,     0,     0,   395,     0,
     396,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   250,    25,   397,   251,     0,   398,     0,     0,
       0,   298,     0,     0,   299,     0,     0,   300,     0,   301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,   164,   378,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   428,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1783,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   379,   380,   381,   382,
     383,   384,   385,   386,   387,     0,     0,     0,     0,   388,
     389,   390,   391,     0,     0,     0,     0,   392,   393,   394,
       0,     0,     0,     0,   395,     0,   396,     0,   429,     0,
       0,     0,     0,     0,     0,   261,   399,   400,   401,   262,
     397,     0,     0,   398,   264,   265,   266,   402,   267,   268,
     269,   403,     0,   404,   116,   430,   431,   432,   433,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,   415,     0,     0,     0,     0,     0,   272,   434,   435,
       0,     0,   436,     0,   437,   206,     6,   358,   438,   275,
       0,     0,   207,   208,   209,     0,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,   244,     0,     0,
       0,     0,   399,   400,   401,   245,   246,     0,     0,     0,
     247,   248,   249,   402,     0,     0,     0,   403,     0,   404,
     116,   250,    25,     0,   251,     0,     0,     0,     0,     0,
     252,     0,     0,   253,     0,     0,   254,     0,   255,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,    56,    57,     0,   258,     0,   259,     0,     0,   260,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,  1858,     0,     0,     0,  1859,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   262,   263,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     271,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   359,   206,     6,     0,   360,     0,   668,   275,   207,
     208,   209,     0,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    25,
       0,   251,     0,     0,     0,     0,     0,   252,     0,     0,
     253,     0,     0,   254,     0,   255,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,    56,    57,
       0,   258,     0,   259,     0,     0,   260,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,  2027,
       0,     0,     0,  2028,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,   262,   263,     0,     0,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   498,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   359,   206,
       6,  1686,     0,   564,     0,   275,   207,   208,   209,     0,
       0,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   240,   241,   242,     0,     0,     0,     0,
     243,   244,     0,     0,     0,     0,     0,     0,     0,   245,
     246,     0,     0,     0,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,   250,    25,     0,   251,     0,
       0,     0,     0,     0,   252,     0,     0,   253,     0,     0,
     254,     0,   255,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,     0,    56,    57,     0,   258,     0,
     259,     0,     0,   260,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     770,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,   262,   263,     0,     0,     0,   264,   265,   266,
       0,   267,   268,   269,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   271,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   359,   206,     6,     0,   274,
       0,     0,   275,   207,   208,   209,     0,     0,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
     240,   241,   242,     0,     0,     0,     0,   243,   244,     0,
       0,     0,     0,     0,     0,     0,   245,   246,     0,     0,
       0,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   250,    25,     0,   251,     0,     0,     0,     0,
       0,   252,     0,     0,   253,     0,     0,   254,     0,   255,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,    56,    57,     0,   258,     0,   259,     0,     0,
     260,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    82,     0,     0,    85,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   776,     0,     0,
       0,     0,     0,     0,     0,   261,     0,     0,     0,   262,
     263,     0,     0,     0,   264,   265,   266,     0,   267,   268,
     269,     0,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,  1850,     0,     0,     0,     0,     0,   272,     0,     0,
       0,     0,   632,   206,     6,     0,   320,   564,     0,   275,
     207,   208,   209,     0,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,   242,
       0,     0,     0,     0,   243,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,     0,     0,     0,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,     0,   251,     0,     0,     0,     0,     0,   252,     0,
       0,   253,     0,     0,   254,     0,   255,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,     0,    56,
      57,     0,   258,     0,   259,     0,     0,   260,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   936,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,   262,   263,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   271,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   273,
     206,     6,     0,   274,     0,     0,   275,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   240,   241,   242,     0,     0,     0,
       0,   243,   244,     0,     0,     0,     0,     0,     0,     0,
     245,   246,     0,     0,     0,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,    25,     0,   251,
       0,     0,     0,     0,     0,   252,     0,     0,   253,     0,
       0,   254,     0,   255,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,    56,    57,     0,   258,
       0,   259,     0,     0,   260,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    82,     0,     0,    85,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   937,     0,     0,     0,     0,     0,     0,     0,   261,
       0,     0,     0,   262,   263,     0,     0,     0,   264,   265,
     266,     0,   267,   268,   269,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   271,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,   359,   206,     6,     0,
     274,     0,     0,   275,   207,   208,   209,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,   244,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,     0,   251,     0,     0,     0,
       0,     0,   252,     0,     0,   253,     0,     0,   254,     0,
     255,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,    56,    57,     0,   258,     0,   259,     0,
       0,   260,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    82,     0,     0,    85,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   983,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
     262,   263,     0,     0,     0,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   498,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   359,   206,     6,     0,   559,     0,     0,
     275,   207,   208,   209,     0,     0,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   240,   241,
     242,     0,     0,     0,     0,   243,   244,     0,     0,     0,
       0,     0,     0,     0,   245,   246,     0,     0,     0,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     250,    25,     0,   251,     0,     0,     0,     0,     0,   252,
       0,     0,   253,     0,     0,   254,     0,   255,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,     0,
      56,    57,     0,   258,     0,   259,     0,     0,   260,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    82,
       0,     0,    85,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1092,     0,     0,     0,     0,
       0,     0,     0,   261,     0,     0,     0,   262,   263,     0,
       0,     0,   264,   265,   266,     0,   267,   268,   269,     0,
       0,     0,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   498,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
     359,   206,     6,     0,     0,   564,     0,   275,   207,   208,
     209,     0,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   240,   241,   242,     0,     0,
       0,     0,   243,   244,     0,     0,     0,     0,     0,     0,
       0,   245,   246,     0,     0,     0,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,   250,    25,     0,
     251,     0,     0,     0,     0,     0,   252,     0,     0,   253,
       0,     0,   254,     0,   255,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,     0,    56,    57,     0,
     258,     0,   259,     0,     0,   260,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1093,     0,     0,     0,     0,     0,     0,     0,
     261,     0,     0,     0,   262,   263,     0,     0,     0,   264,
     265,   266,     0,   267,   268,   269,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   271,     0,     0,     0,
       0,     0,   272,     0,     0,     0,     0,   602,   206,     6,
       0,   274,     0,     0,   275,   207,   208,   209,     0,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   240,   241,   242,     0,     0,     0,     0,   243,
     244,     0,     0,     0,     0,     0,     0,     0,   245,   246,
       0,     0,     0,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,   250,    25,     0,   251,     0,     0,
       0,     0,     0,   252,     0,     0,   253,     0,     0,   254,
       0,   255,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     0,    56,    57,     0,   258,     0,   259,
       0,     0,   260,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,     0,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    82,     0,     0,    85,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1094,
       0,     0,     0,     0,     0,     0,     0,   261,     0,     0,
       0,   262,   263,     0,     0,     0,   264,   265,   266,     0,
     267,   268,   269,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   271,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,   609,   206,     6,     0,   274,     0,
       0,   275,   207,   208,   209,     0,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,   244,     0,     0,
       0,     0,     0,     0,     0,   245,   246,     0,     0,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,     0,     0,     0,     0,     0,
     252,     0,     0,   253,     0,     0,   254,     0,   255,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,    56,    57,     0,   258,     0,   259,     0,     0,   260,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1095,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   262,   263,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     498,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   359,   206,     6,     0,   897,     0,  1358,   275,   207,
     208,   209,     0,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    25,
       0,   251,     0,     0,     0,     0,     0,   252,     0,     0,
     253,     0,     0,   254,     0,   255,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,    56,    57,
       0,   258,     0,   259,     0,     0,   260,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1133,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,   262,   263,     0,     0,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   498,     0,     0,
       0,     0,     0,   272,   206,     6,     0,     0,   359,  1567,
       0,   207,   208,   209,     0,   275,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   240,   241,
     242,     0,     0,     0,     0,   243,   244,     0,     0,     0,
       0,     0,     0,     0,   245,   246,     0,     0,     0,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     250,    25,     0,   251,     0,     0,     0,     0,     0,   252,
       0,     0,   253,     0,     0,   254,     0,   255,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,     0,
      56,    57,     0,   258,     0,   259,     0,     0,   260,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    82,
       0,     0,    85,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1143,     0,     0,     0,     0,
       0,     0,     0,   261,     0,     0,     0,   262,   263,     0,
       0,     0,   264,   265,   266,     0,   267,   268,   269,     0,
       0,     0,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   498,
       0,     0,     0,     0,     0,   272,   206,     6,     0,     0,
     359,     0,     0,   207,   208,   209,     0,   275,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
     240,   241,   242,     0,     0,     0,     0,   243,   244,     0,
       0,     0,     0,     0,     0,     0,   245,   246,     0,     0,
       0,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   250,    25,     0,   251,     0,     0,     0,     0,
       0,   252,     0,     0,   253,     0,     0,   254,     0,   255,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,    56,    57,     0,   258,     0,   259,     0,     0,
     260,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    82,     0,     0,    85,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1144,     0,     0,
       0,     0,     0,     0,     0,   261,     0,     0,     0,   262,
     263,     0,     0,     0,   264,   265,   266,     0,   267,   268,
     269,     0,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,   271,     0,     0,     0,     0,     0,   272,     0,     0,
       0,     0,   359,   206,     6,     0,  1694,     0,     0,   275,
     207,   208,   209,     0,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,   242,
       0,     0,     0,     0,   243,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,     0,     0,     0,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,     0,   251,     0,     0,     0,     0,     0,   252,     0,
       0,   253,     0,     0,   254,     0,   255,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,     0,    56,
      57,     0,   258,     0,   259,     0,     0,   260,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1145,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,   262,   263,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   630,  1850,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   632,
     206,     6,     0,   320,     0,     0,   275,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   240,   241,   242,     0,     0,     0,
       0,   243,   244,     0,     0,     0,     0,     0,     0,     0,
     245,   246,     0,     0,     0,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,    25,     0,   251,
       0,     0,     0,     0,     0,   252,     0,     0,   253,     0,
       0,   254,     0,   255,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,    56,    57,     0,   258,
       0,   259,     0,     0,   260,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    82,     0,     0,    85,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1150,     0,     0,     0,     0,     0,     0,     0,   261,
       0,     0,     0,   262,   263,     0,     0,     0,   264,   265,
     266,     0,   267,   268,   269,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   498,     0,     0,     0,     0,
       0,   272,   206,   164,   378,     0,   359,     0,     0,   207,
     208,   209,     0,   275,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   414,   228,   229,   230,   231,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   239,   240,   241,   242,   388,
     389,   390,   391,   243,     0,     0,     0,   392,   393,   394,
       0,     0,     0,     0,   395,     0,   396,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    25,
     397,   251,     0,   398,   206,   164,   378,     0,     0,     0,
       0,   207,   208,   209,     0,     0,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   414,   228,   229,   230,   231,   232,   233,
       0,     0,     0,     0,     0,     0,     0,     0,  1589,   380,
     381,   382,   383,   384,   385,   386,   387,   239,   240,   241,
     242,   388,   389,   390,   391,   243,     0,     0,     0,   392,
     393,   394,     0,     0,     0,     0,   395,     0,   396,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     250,    25,   397,   251,     0,   398,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,   399,   400,   401,   262,     0,     0,     0,     0,
     264,   265,   266,   402,   267,   268,   269,   403,     0,   404,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   415,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   359,     0,
       0,     0,  1863,     0,     0,   275,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1151,     0,
       0,     0,     0,   261,   399,   400,   401,   262,     0,     0,
       0,     0,   264,   265,   266,   402,   267,   268,   269,   403,
       0,   404,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   415,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
     359,   206,   164,   378,  1749,     0,     0,   275,   207,   208,
     209,     0,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     414,   228,   229,   230,   231,   232,   233,     0,     0,     0,
       0,     0,     0,     0,     0,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   239,   240,   241,   242,   388,   389,
     390,   391,   243,     0,     0,     0,   392,   393,   394,     0,
       0,     0,     0,   395,     0,   396,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,   250,    25,   397,
     251,     0,   398,   206,   164,     0,     0,     0,     0,     0,
     207,   208,   209,     0,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   414,   228,   229,   230,   231,   232,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,   242,
       0,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,     0,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     261,   399,   400,   401,   262,     0,     0,     0,     0,   264,
     265,   266,   402,   267,   268,   269,   403,     0,   404,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   415,     0,     0,     0,
       0,     0,   272,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,   275,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1153,     0,     0,
       0,     0,   261,     0,     0,     0,   262,     0,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   415,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   359,
     206,   164,     0,   612,     0,     0,   275,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   414,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   240,   241,   242,     0,     0,     0,
       0,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,   248,   249,     0,     0,
       0,     0,     0,   206,   164,     0,   250,    25,   865,   251,
     207,   208,   209,     0,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   414,   228,   229,   230,   231,   232,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,   242,
       0,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,     0,   251,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,   261,
       0,     0,     0,   262,     0,  1263,     0,     0,   264,   265,
     266,     0,   267,   268,   269,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   630,   631,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,   632,     0,     0,     0,
     320,     0,     0,   275,     0,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,   261,     0,     0,     0,   262,  1284,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   415,     0,
       0,     0,     0,     0,   272,   206,   164,     0,     0,   359,
       0,     0,   207,   208,   209,     0,   275,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   414,   228,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,   206,   164,     0,  1310,     0,
       0,     0,   207,   208,   209,     0,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   414,   228,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,   261,     0,     0,   590,   262,     0,
       0,     0,   715,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     415,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   359,  1081,     0,     0,     0,     0,     0,   275,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1368,     0,     0,   261,     0,     0,     0,   262,     0,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     415,     0,     0,     0,     0,     0,   272,   206,   164,     0,
    1466,   359,     0,     0,   207,   208,   209,     0,   275,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   414,   228,   229,   230,
     231,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,     0,   251,   206,   164,     0,
    1529,     0,     0,     0,   207,   208,   209,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   414,   228,   229,   230,
     231,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,     0,   251,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,   261,     0,     0,   590,
     262,     0,     0,     0,   928,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   415,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   359,     0,     0,     0,     0,     0,     0,
     275,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1371,     0,     0,   261,     0,     0,     0,
     262,     0,     0,     0,     0,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   415,     0,     0,     0,     0,     0,   272,   206,
     164,     0,     0,   359,     0,     0,   207,   208,   209,     0,
     275,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   414,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   240,   241,   242,     0,     0,     0,     0,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   248,   249,     0,     0,     0,
       0,     0,   206,   164,     0,   250,    25,     0,   251,   207,
     208,   209,     0,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   414,   228,   229,   230,   231,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,   242,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    25,
       0,   251,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,   261,     0,
       0,     0,   262,     0,  1460,     0,     0,   264,   265,   266,
       0,   267,   268,   269,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   415,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   359,  1583,     0,     0,     0,
       0,     0,   275,     0,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,   261,     0,     0,     0,   262,  1461,     0,     0,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   415,     0,     0,
       0,     0,     0,   272,   206,   164,     0,     0,   359,  1910,
       0,   207,   208,   209,     0,   275,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   414,   228,   229,   230,   231,   232,   233,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   240,   241,
     242,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     250,    25,     0,   251,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1504,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       7,     8,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,   751,    55,     0,     0,
      58,   752,     0,   753,   754,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   261,     0,     0,     0,   262,    93,    94,
      95,     0,   264,   265,   266,     0,   267,   268,   269,     0,
       0,     0,   116,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   270,   415,
       0,    43,    44,    45,    46,   272,     0,    48,     7,     8,
     359,     0,     0,     0,   751,    55,     0,   275,    58,   752,
       0,   753,   754,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,  1215,     0,     0,     0,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,    93,    94,    95,   590,
       0,     0,     0,     0,     0,     0,     7,     8,     0,  1630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,   751,    55,     0,     0,    58,   752,     0,   753,
     754,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,  1217,     0,     0,     7,     8,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    93,    94,    95,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     751,    55,     0,     0,    58,   752,     0,   753,   754,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    93,    94,    95,    43,    44,    45,    46,  1218,
       0,    48,     0,     0,     0,     0,     0,     0,   751,    55,
       0,     0,    58,   752,     0,   753,   754,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      93,    94,    95,    43,    44,    45,    46,  1237,     0,    48,
       0,     0,     0,     0,     0,     0,   751,    55,     0,     0,
      58,   752,     0,   753,   754,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    93,    94,
      95,    43,    44,    45,    46,  1255,     0,    48,     0,     0,
       0,     0,     0,     0,   751,    55,     0,     0,    58,   752,
       0,   753,   754,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    93,    94,    95,    43,
      44,    45,    46,  1269,     0,    48,     0,     0,     0,     0,
       0,     0,   751,    55,     0,     0,    58,   752,     0,   753,
     754,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    93,    94,    95,    43,    44,    45,
      46,  1302,     0,    48,     0,     0,     0,     0,     0,     0,
     751,    55,     0,     0,    58,   752,     0,   753,   754,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    93,    94,    95,    43,    44,    45,    46,  1458,
       0,    48,     0,     0,     0,     0,     0,     0,   751,    55,
       0,     0,    58,   752,     0,   753,   754,     0,   755,     0,
       0,     0,     0,     0,    -4,     1,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,    79,    -4,    -4,     0,
       0,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
      93,    94,    95,   590,     0,     0,     0,  2085,    -4,    -4,
      -4,     0,     0,  1631,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,     0,     0,     0,
      -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,  2144,     0,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,
      10,    11,    -4,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,     0,    -4,     0,     0,     0,     0,
      12,    13,    14,     0,     0,     0,    15,    16,     0,     0,
       0,    17,     0,     0,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,     0,    25,     0,     0,     0,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,    42,    43,
      44,    45,    46,    47,     0,    48,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,     0,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,    89,    90,     0,     0,     0,    91,     0,
       0,     0,     0,    92,    93,    94,    95,   164,   378,    96,
       0,    97,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,   115,     0,   116,     0,     0,     0,
     379,   380,   381,   382,   383,   384,   385,   386,   387,     0,
       0,     0,     0,   388,   389,   390,   391,   408,   378,     0,
       0,   392,   393,   394,     0,     0,     0,     0,   395,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   397,     0,     0,   398,     0,     0,
       0,   298,     0,   378,   299,     0,     0,   300,     0,   301,
     379,   380,   381,   382,   383,   384,   385,   386,   387,     0,
      46,     0,     0,   388,   389,   390,   391,     0,     0,     0,
       0,   392,   393,   394,     0,     0,     0,   428,   395,     0,
     396,     0,     0,     0,     0,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   397,     0,     0,   398,   388,   389,
     390,   391,     0,     0,     0,     0,   392,   393,   394,     0,
       0,     0,     0,   395,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   397,
       0,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   399,   400,   401,     0,
       0,     0,     0,     0,     0,     0,     0,   402,     0,     0,
       0,   403,     0,   404,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,   399,   400,   401,  1632,
       0,     0,     0,     0,     0,     0,     0,   402,     0,     0,
       0,   403,     0,   404,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   399,   400,   401,     0,     0,     0,     0,     0,     0,
       0,     0,   402,     0,     0,     0,   403,     0,   404,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     7,     8,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   751,    55,
       0,     0,    58,   752,     0,   753,   754,     0,   755,     0,
       0,     0,  1026,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
    1027,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
      93,    94,    95,   590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1646,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,   751,    55,     0,     0,
      58,   752,     0,   753,   754,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,    93,    94,
      95,     0,     0,     0,     0,     0,     0,  1777,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1897,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1898,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1929,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1932,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1999,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2053,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2054,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2068,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2070,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2103,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2131,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2136,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2137,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2138,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2178,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,  1061,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
    1120,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,  1165,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,  1166,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,  1209,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,  1240,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,  1260,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,  1316,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,  1336,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,  1417,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,  1418,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
    1462,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,  1535,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,  1779,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,  1829,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,  1840,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,  1877,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,  1949,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,  1964,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,  1976,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,  2033,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
    2042,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,  2043,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,  2066,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,  2117,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,  2157,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,  2176,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,  2196,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,  2197,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,  2198,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
    1942,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,   737,     0,   738,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,   989,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,  1037,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,  1189,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,  1254,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,  1256,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,  1261,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,  1262,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,  1350,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
    1364,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,  1564,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,  1652,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,  1701,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,  1889,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,  1934,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,  1950,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   792,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   793,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   794,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   796,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   797,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   798,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   800,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   801,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   802,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   803,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   804,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   805,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   806,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   808,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   809,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   810,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   877,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   912,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   958,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   977,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   979,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   980,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   981,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   987,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   988,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1025,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1036,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1100,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1104,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1116,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1188,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1198,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1199,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1200,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1210,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1239,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1241,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1242,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1243,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1244,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1245,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1246,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1247,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1253,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1349,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1363,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1565,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1597,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1598,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1599,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1600,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1638,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1651,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1764,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1766,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1769,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1776,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1830,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1839,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1862,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1933,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1997,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1998,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  2130,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  2173,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590
};

static const yytype_int16 yycheck[] =
{
       3,   313,  1238,     3,  1234,   627,   628,  1424,   732,    68,
      69,  1688,    71,     4,    62,  1732,   740,  1734,   719,     4,
       4,     4,    25,     4,     6,     4,     4,   325,    25,     6,
     195,     5,     4,     6,   156,   142,     4,     7,   203,     6,
       6,     5,     5,   159,     4,     6,   344,   748,     5,     4,
       6,    54,     4,     4,     4,  1912,     4,  1719,     6,   104,
       4,     4,   138,   138,   765,     9,   252,    98,   184,   245,
     246,   104,   258,     7,   775,   250,     6,     4,     4,   255,
      83,   156,   127,   258,   200,   201,   117,     9,    91,   164,
     165,   166,     6,    96,   127,   170,   171,   250,   237,   238,
       6,     9,     9,    98,   107,   258,   101,    90,     7,   104,
       0,   187,     9,   411,   252,   413,   237,   238,     6,   258,
     258,  1783,   117,   421,   237,   238,  1803,   237,   238,    14,
     295,   296,   297,   237,   238,   237,   238,   258,   249,   142,
     253,     8,   250,   143,   147,   148,   149,   255,   258,   249,
      98,   251,   250,   156,   258,    98,   258,   104,   258,   102,
     258,   107,   250,   109,   101,   108,   109,   104,   111,   112,
     258,   174,   337,   338,   339,     7,   245,   246,   879,     8,
     117,   107,   108,   174,   175,   176,   177,   190,   131,   354,
       6,     9,   195,   237,   238,   198,   142,   245,   246,   253,
     203,   204,   205,   257,  2061,     6,   172,   237,   238,   237,
     238,   172,   195,     9,   258,   249,   143,   144,   145,   146,
     237,   238,   149,   169,   101,   253,  1643,   104,   258,   184,
     185,   158,   184,   185,   161,   237,   238,   249,   221,   199,
     221,   258,   221,   221,   249,     7,   254,   249,  1478,   221,
     258,   253,     7,   221,   257,   237,   238,   316,   317,     7,
     237,   238,  1939,   254,   249,   324,   325,   251,   271,   253,
     253,   274,   275,   257,   253,   256,   249,   221,   275,   253,
     253,   253,   250,     6,   252,   255,   253,   290,   291,   253,
     253,   294,   295,   296,   297,     6,   253,   253,   249,   249,
       7,   245,   246,   233,   307,   249,   236,   251,   311,   253,
     313,   255,  1036,  1037,     6,   249,  1993,   251,   616,   233,
     618,   619,   236,   222,   223,   224,   225,   249,   249,   251,
     251,     6,   335,   255,   337,   338,   339,   635,   245,   246,
     253,   249,   249,   251,   251,   252,   245,   246,   255,   237,
     238,   354,   249,     6,   251,   653,   255,   360,   255,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     6,   676,   101,
    2097,   248,   104,   251,   106,   550,   250,   254,   252,   251,
     222,   223,   224,   225,   258,   117,   249,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   418,   419,   715,   540,   248,
     423,   424,   250,   237,   238,   254,    98,   245,   246,   101,
     258,   249,   104,   251,   106,   104,   439,   255,   237,   238,
     104,   142,   106,   446,   258,   117,   147,   148,   149,   245,
     246,   237,   238,   249,   253,   251,  2133,   237,   238,   255,
     222,   223,   224,   225,   237,   238,   469,   222,   223,   224,
     225,  1172,   258,  1174,   222,   223,   224,   225,   258,   237,
     238,   427,   249,   245,   246,   258,  1187,   237,   238,   190,
     245,   246,   249,   237,   238,   498,   138,   245,   246,    98,
     258,   119,   101,   255,   205,   104,   258,   106,   258,  2186,
     254,   237,   238,  1930,   156,   222,   223,   224,   225,   522,
     237,   238,   164,   165,   166,   249,   529,   530,   170,   171,
     249,   534,   258,   536,   537,   538,   539,   540,   237,   238,
     249,   258,   545,   237,   238,   249,   549,   550,   551,   552,
     553,   554,   555,   250,   557,   252,   559,   138,   555,   258,
     557,   258,   684,     8,   258,   249,   625,   626,   242,   243,
     249,   630,   237,   238,   248,   156,   237,   238,   237,   238,
     237,   238,   585,   164,   165,   166,   253,   250,   591,   170,
     171,   253,   250,   258,   252,   258,  1297,   258,   250,   258,
     258,   258,  1303,   138,   237,   238,   258,     6,   611,   612,
     556,   250,   254,   252,   254,   250,   249,   252,   258,   258,
     253,   156,   138,   258,   250,   732,  1248,   627,   628,   164,
     165,   166,   258,   250,   932,   170,   171,   249,   249,   251,
     156,   258,   239,   240,   241,   242,   243,  1348,   164,   165,
     166,   248,     6,     7,   170,   171,   659,   660,   661,   106,
     249,  1362,   251,   245,   246,   255,   255,   257,  1369,   258,
     249,   253,   101,   254,   249,   104,   251,   106,   253,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   249,   692,
     693,   694,   695,   696,   249,   698,   699,   700,   701,   702,
     245,   246,   705,    54,   701,   249,   754,   249,   253,   143,
     144,   253,   250,   716,   252,   149,     3,   418,   249,   254,
     251,   249,   253,     6,     7,   253,   729,  1451,   237,   238,
     239,   240,   241,   242,   243,   249,   739,   251,   254,   248,
     143,   144,   745,   254,   254,   253,   149,   258,   258,   254,
     254,   697,   254,   258,   258,   249,   258,   254,   761,   762,
     249,   258,   251,   254,   767,   249,   769,   258,   254,   772,
     773,   254,   258,   254,    61,   258,   779,   258,   781,   237,
     238,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   249,
     254,   908,   254,   248,   258,   250,   258,   252,   254,   253,
     104,   814,   258,   816,  1538,   254,   254,   254,   254,   258,
     258,   258,   258,   254,   254,   101,  1550,   258,   258,   249,
     254,   251,   254,   534,   258,   536,   258,   538,   539,   254,
     254,   249,   253,   258,   258,   791,   849,   249,   253,   251,
    2086,   552,   553,   204,   254,   142,   859,   253,   258,   254,
     147,   148,   149,   258,   254,   249,   254,   254,   258,   156,
     258,   258,   104,   254,   254,   254,   935,   258,   258,   258,
     254,   254,   254,   942,   258,   258,   258,   946,   254,  2119,
     101,   254,   258,   254,   897,   258,   254,   258,   254,   101,
     258,   254,   258,   190,   254,   258,   257,   910,   258,  2145,
     254,   254,   104,   254,   258,   258,   919,   258,   205,   254,
     254,     4,   254,   258,   258,   928,   258,   254,   254,  1036,
    1037,   258,   258,  2163,   254,   254,   254,   254,   258,   258,
     258,   258,   254,   294,   254,     4,   258,   250,   258,   252,
     253,   250,     4,   252,   253,     4,   307,   244,   249,     4,
     311,     6,     6,   249,   249,   249,     6,   249,     6,   249,
     251,     6,   259,   260,   251,   253,   922,   249,   257,   253,
       9,   249,   683,     8,   685,   686,   687,   688,   689,   690,
     257,   692,   693,   694,   695,   249,   249,   698,   699,   700,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   249,  1329,   249,   249,
     248,   187,   249,   249,   253,   249,   187,   187,  1031,   127,
     253,   249,   249,   249,   249,   187,     4,   249,  1097,  1042,
     253,   249,     6,   253,  1047,     6,   253,   253,   253,   253,
     249,  1673,  1674,   249,   249,   249,   249,  1060,   249,   249,
     249,     6,  1065,   251,     6,     6,   253,   253,   253,   253,
     251,   772,   423,   424,   251,   251,   187,   249,   253,   249,
     781,  1188,  1189,   251,   249,   249,   249,   249,   439,     6,
       6,     6,  1038,     6,   253,  1098,  1099,     8,  1101,  1102,
    1103,     8,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,   253,     7,  1117,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       6,   418,   253,   253,   248,     6,   253,    93,   254,   258,
     258,   428,   250,     7,     6,     6,   250,   253,   253,   248,
     253,   253,  1155,  1156,  1157,   255,    65,     8,     4,     7,
       7,   249,     6,   450,   250,     6,   253,     7,     6,   254,
       7,     6,     6,   184,   253,   250,  1179,   254,   254,   252,
       6,   253,     7,     6,   255,   251,   537,   249,   253,     4,
       6,   251,  1195,  1196,  1197,     6,     6,     6,   549,     6,
     551,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   250,
       7,     7,     7,   248,     7,   250,     7,     7,     7,     7,
    1528,     7,     7,  1545,  1532,     7,     7,     7,     7,   138,
       7,     7,  1349,  1350,   253,     6,  1249,   534,  1248,   536,
     250,   538,   539,   540,   252,   258,   258,   258,   254,   258,
     250,  1264,  1265,  1266,     7,   552,   553,   253,   255,   254,
       7,   253,  1275,   253,     6,     4,     6,  1280,   255,   254,
     254,  1284,   138,   253,     7,     6,   255,     7,     7,     7,
    1293,   250,  1295,   250,     9,  1298,   258,   250,   258,     6,
     258,   252,   257,   255,   187,     7,   159,   254,     6,   253,
    1313,     6,     6,     4,    47,   255,    47,   249,   253,   249,
     253,   255,   249,  1945,   255,   249,  1329,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     4,   633,  1350,   258,   248,
       7,     7,  1355,     7,  1357,   187,     7,   250,     7,     7,
       6,   250,   258,     7,  1065,     7,     7,     4,   116,   656,
       4,  1374,   253,     6,   249,     7,     6,     6,   729,     7,
     198,     7,     6,   253,  1387,     7,     7,     7,  1391,     7,
       7,     6,     6,   104,     7,   682,   683,   684,   685,   686,
     687,   688,   689,   690,     6,   692,   693,   694,   695,     6,
       4,   698,   699,   700,     4,   258,   258,   256,  1477,   250,
     253,   708,     6,   253,   711,   253,  1372,   254,  1374,  1551,
    1552,  1538,     6,     6,  1746,     7,   723,     6,   251,     6,
       6,   249,  1445,  1446,  1447,   249,     6,   253,     6,   254,
    1453,     6,   255,   252,     6,  1156,  1157,   258,     6,   131,
       6,     6,     6,     6,     6,  1468,   753,     6,   755,     6,
       6,     6,   290,   291,     6,     6,  1479,     6,     5,     4,
       6,   254,   250,     6,  1487,   772,   250,     4,  1491,     7,
       6,   253,   251,   253,   781,   253,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   253,   253,     6,   335,   248,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     6,     6,   253,
     253,   248,  1545,  1650,  1603,   253,     6,   253,  1551,  1552,
     253,     6,   253,   253,  1557,     6,   183,     6,     6,   258,
     250,   258,   258,     6,   253,   258,     7,   255,   919,   249,
     253,     4,  1575,   254,     6,     6,     6,     6,  1524,  1280,
     249,     4,  1585,  1284,   249,     7,     6,  1590,     6,     6,
       6,     6,  1293,     6,  1295,     6,   102,  1298,   138,     6,
       5,   419,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     258,     6,   253,     6,   248,   250,     6,  1749,     6,     6,
    1689,  1690,  1691,  1692,  1693,  1694,     6,   253,     6,  1585,
       4,   253,   253,   250,   931,     6,   933,   934,   258,  1350,
     258,     6,   258,   258,     6,  1762,  1954,     6,     6,  1662,
     947,     6,  1665,  1666,     6,   253,     7,   142,     6,     5,
    1982,   253,   253,  1673,  1674,   253,     6,     6,   253,   966,
    1031,     6,   250,   253,     6,  1688,     7,     6,   182,   254,
     254,  1694,   253,     6,   250,   254,  1047,   984,     6,     6,
     254,  1704,     7,   254,     6,   255,     6,     6,     6,     6,
       6,  1714,   253,     6,  1717,     6,   254,   250,   185,   253,
       6,     6,     6,  1669,   254,   253,     6,   249,   138,   250,
     254,     6,  1735,  1020,   253,     6,     6,     6,   253,  1742,
     253,   559,   253,  1746,   254,  1748,  1749,  1098,  1099,  2047,
    1101,  1102,  1103,   253,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,   253,   250,  1712,     6,     6,     6,
     254,   254,     6,  1719,  1720,     6,     6,     6,  1065,     6,
    1783,     6,   253,     6,     6,     6,     6,   253,   253,  2087,
       6,     6,  1738,   611,   612,     6,     6,  1361,  2099,   466,
    1803,  1595,  1874,  1419,  1155,     3,  1658,  1913,  1386,     3,
       3,     3,  1815,  1816,   606,  1941,  1521,     3,  1742,  1719,
    1552,    -1,     6,   772,    -1,    -1,    -1,    -1,  1179,    -1,
      -1,    -1,    -1,    -1,    -1,  1838,    -1,    -1,    -1,    -1,
      -1,   659,   660,   661,  1195,    -1,    -1,  1850,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1863,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1156,
    1157,    -1,    -1,    -1,  1575,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   705,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1900,  1249,  1958,
    1959,  1960,  1961,  1962,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1914,    -1,  1264,  1265,  1266,  1919,    -1,    -1,  1922,
    1923,   739,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1216,
    1876,    -1,    -1,    -1,    -1,    -1,  1939,    -1,    -1,  1942,
      -1,    -1,    -1,   761,    -1,  1945,    -1,    -1,    -1,   767,
    1953,   769,    -1,    -1,  1957,    -1,    -1,    -1,    -1,    -1,
    2019,    -1,  1313,    -1,  2023,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1918,    -1,    -1,    -1,    -1,    -1,    -1,  1982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1993,    -1,    -1,  1280,    -1,    -1,    -1,  1284,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1293,    -1,  1295,    -1,
      -1,  1298,    -1,  1714,  2073,    -1,  1717,  2020,  2077,    -1,
    1307,    -1,    -1,  1374,     6,    -1,    -1,    -1,    -1,    -1,
      -1,   849,    -1,    -1,  2093,    -1,  1387,    -1,    -1,    -1,
    1391,   859,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,  1350,   248,    -1,    -1,    -1,  2071,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   897,
      -1,  2140,  2141,    -1,    -1,    -1,  2089,  2090,  2091,  2092,
    2093,    -1,   910,    -1,  1445,  1446,  1447,    -1,    -1,    -1,
      -1,    -1,  1453,    -1,    -1,    -1,    -1,    -1,     4,     5,
     928,    -1,    -1,    -1,    -1,    -1,  2062,  1468,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1479,    -1,
    2133,    -1,    -1,    -1,    -1,    -1,  1487,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,  2150,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,  2172,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,     6,    75,
      -1,    77,    -1,  2186,    -1,    -1,    -1,    -1,    -1,    -1,
    2193,  2194,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,  2207,   101,  1557,    -1,   104,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1585,    -1,    -1,    -1,   134,    -1,
      -1,    -1,  1060,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,  1551,  1552,   248,    -1,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,  1575,    -1,
     248,    -1,   250,    -1,   252,    -1,    -1,    -1,    -1,  1117,
     258,    -1,    -1,    -1,    -1,    -1,    -1,   203,   204,   205,
      -1,  1662,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,   218,    -1,   220,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,    -1,    -1,  1704,    -1,    -1,    -1,   253,    -1,   255,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,  1196,  1197,
      -1,    -1,   248,    -1,  1735,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1748,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,     6,    -1,  1714,    -1,    -1,
    1717,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,  1732,    -1,  1734,   248,    -1,
      -1,    -1,  1803,    -1,    -1,    -1,    -1,  1275,    -1,    -1,
      -1,    -1,  1749,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,  2172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1838,    -1,    -1,
      -1,    -1,  2193,  2194,    -1,    -1,  1783,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2207,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,  1355,    77,  1357,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,  1900,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,   101,  1914,    -1,   104,    -1,   106,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,   146,    -1,   117,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,  1939,   159,
      -1,    -1,     6,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,  1953,    -1,    -1,   175,   176,   177,    -1,   179,
     180,   181,    -1,   183,   184,   185,   186,   187,   188,   189,
      -1,   191,   192,   193,   194,    -1,    -1,    -1,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1993,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,   203,   204,   205,   248,    -1,  2020,
      -1,    -1,    -1,  1491,    -1,   214,    -1,    -1,    -1,   218,
      -1,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,   271,   272,   273,   274,    -1,    -1,    -1,    -1,    -1,
      -1,   250,    -1,   252,   253,    -1,    -1,    -1,    -1,   289,
     290,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,
      -1,    -1,    -1,    -1,    -1,  2032,    -1,    -1,    -1,   319,
     320,    -1,    -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   335,   336,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2133,    -1,    -1,    -1,    -1,    -1,    -1,   359,
     360,    -1,    -1,    -1,   364,   365,   366,    -1,   368,    -1,
      -1,    -1,   372,   373,   374,    -1,    -1,   377,    -1,    -1,
    2097,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,  2120,   248,  2186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   415,    -1,  1665,  1666,   419,
     420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,   437,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,    -1,    -1,    -1,  2172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   471,   472,   473,   474,    -1,  2193,  2194,    -1,   479,
      -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,    -1,
    2207,    -1,    -1,    -1,    -1,    -1,    -1,   497,   498,    -1,
      -1,    -1,   502,    -1,    -1,    -1,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,    -1,   532,   533,    -1,   535,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   544,    -1,    -1,   547,   548,    -1,
      -1,    -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,   559,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1815,  1816,    -1,
      -1,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,    -1,   592,   593,    -1,    -1,    -1,    -1,    -1,    -1,
     600,   601,   602,    -1,    -1,    -1,    -1,    -1,   608,   609,
      -1,   611,   612,    -1,    -1,  1863,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     630,   631,   632,    -1,    -1,    -1,   636,   637,   638,   639,
     640,   641,   642,   643,   644,    -1,     6,    -1,    -1,    -1,
     650,    -1,   652,    -1,    -1,   655,    -1,    -1,    -1,   659,
     660,   661,   662,    -1,   664,   665,   666,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1922,  1923,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   691,    -1,    -1,  1942,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   705,    -1,    -1,    -1,  1957,
      -1,    -1,   712,    -1,   714,    -1,    -1,   717,   718,    -1,
      -1,    -1,    -1,    -1,    -1,   198,   726,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   739,
      -1,   741,    -1,    -1,    -1,     6,   746,   747,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   761,    -1,   763,   764,    -1,    -1,   767,    -1,   769,
     770,    -1,    -1,    -1,   774,    -1,   776,    -1,    -1,    -1,
      -1,    -1,   782,    -1,    -1,    -1,   786,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   812,    -1,   814,    -1,   816,   290,   291,    -1,
      -1,    -1,    -1,  2071,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2089,  2090,  2091,  2092,  2093,    -1,    -1,    -1,   849,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   859,
     860,   861,   335,    -1,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,   360,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   897,    -1,    -1,
      -1,    -1,  2150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     910,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,    -1,
      -1,    -1,   922,    -1,    -1,    -1,    -1,    -1,   928,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   936,   937,    -1,    -1,
      -1,    -1,   942,    -1,    -1,    -1,   419,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   959,
      -1,    -1,   962,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   983,     6,   985,   986,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1004,    -1,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   498,    -1,  1027,    -1,   248,
      -1,    -1,    -1,    -1,  1034,    -1,    -1,    -1,    -1,  1039,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,
      -1,    -1,    -1,    -1,  1054,  1055,   529,   530,    -1,    -1,
    1060,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,   554,    -1,   248,    -1,    -1,   559,    -1,    -1,   254,
      -1,    -1,  1092,  1093,  1094,  1095,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,    -1,    -1,  1117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1133,    -1,    -1,    -1,    -1,   611,   612,
      -1,    -1,    -1,  1143,  1144,  1145,    -1,    -1,    -1,    -1,
    1150,  1151,    -1,  1153,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1167,  1168,    -1,
      -1,    -1,    -1,    -1,    -1,  1175,  1176,    -1,    -1,    -1,
      -1,    -1,  1182,    -1,  1184,  1185,   659,   660,   661,    -1,
      -1,  1191,  1192,    -1,    -1,    -1,  1196,  1197,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,  1228,    -1,
      -1,    -1,   705,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,   114,
     115,   116,   117,  1263,    -1,   120,   739,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,  1275,   131,   132,    -1,   134,
     135,    -1,   137,  1283,    -1,    -1,    -1,    -1,   761,    -1,
      -1,    -1,    -1,    -1,   767,    -1,   769,    -1,    -1,    -1,
     155,    -1,    -1,    -1,  1304,  1305,    -1,    -1,    -1,  1309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1320,    -1,    -1,  1323,   179,   180,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   814,     6,   816,     4,     5,    -1,    -1,    -1,    -1,
      -1,  1351,    -1,    -1,  1354,  1355,  1356,  1357,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1365,    -1,    -1,  1368,    -1,
    1370,  1371,  1372,    -1,     6,    -1,   849,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   859,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,   254,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   897,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,   910,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,  1452,    -1,    -1,   928,    -1,   117,    -1,  1459,
    1460,  1461,    -1,    -1,    -1,    -1,    -1,    -1,  1468,    -1,
    1470,    -1,    -1,    -1,   134,    -1,    -1,  1477,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1491,    -1,    -1,    -1,    -1,  1496,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1504,  1505,  1506,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1516,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1526,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,   204,   205,    -1,    -1,    -1,  1549,
      -1,    -1,    -1,    -1,   214,  1555,  1556,    -1,   218,     6,
     220,   221,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,  1060,    -1,    -1,
    1590,    -1,    -1,   253,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1630,  1631,  1632,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1641,    -1,    -1,  1117,    -1,  1646,  1647,  1648,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1660,    -1,    -1,    -1,    -1,  1665,  1666,  1667,    -1,  1669,
      -1,    -1,    -1,    -1,    -1,  1675,  1676,    -1,    -1,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1694,    -1,    -1,    -1,    -1,  1699,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1712,    -1,    -1,  1715,    -1,    -1,    -1,  1719,
      -1,    -1,    -1,  1196,  1197,    -1,    -1,    -1,  1728,  1729,
      -1,  1731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1739,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1755,    -1,    -1,    -1,    -1,
    1760,  1761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   441,    -1,    -1,  1774,    -1,    -1,  1777,  1778,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,  1275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1815,  1816,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1832,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1850,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1859,
    1860,    -1,    -1,  1863,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,
      -1,    -1,  1355,    -1,  1357,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,  1897,  1898,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,  1917,    -1,    -1,
      -1,   248,  1922,  1923,  1924,    -1,   596,    -1,    -1,  1929,
      -1,    -1,  1932,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1942,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1957,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1965,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
    1990,    -1,   114,   115,   116,   117,  1996,    -1,   120,  1999,
      -1,    -1,    -1,     7,    -1,   127,   128,    -1,    -1,   131,
     132,    -1,   134,   135,    -1,   137,    -1,    -1,  1491,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2028,    -1,
      -1,    -1,    -1,   155,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,  2053,  2054,    -1,   248,   179,   180,   181,
      -1,    -1,   254,    -1,    -1,    -1,   258,  2067,  2068,    -1,
    2070,  2071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,    -1,  2084,    -1,    -1,    -1,    -1,  2089,
    2090,  2091,  2092,  2093,    -1,    -1,    -1,    -1,    -1,  2099,
      -1,    -1,    -1,  2103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1590,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,  2131,   254,    -1,    -1,    -1,  2136,  2137,  2138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2150,   821,   822,   823,   824,   825,   826,   827,   828,   829,
     830,   831,    -1,   833,   834,   835,   836,    -1,   838,   839,
     840,   841,    -1,     8,    -1,    -1,    -1,    -1,  2178,  2179,
    2180,    -1,   852,    -1,   854,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1665,  1666,   864,    -1,   142,    -1,    -1,    -1,
      -1,   871,   872,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     880,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1694,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,    -1,   241,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   250,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,   263,    -1,    -1,
     990,   991,   992,    -1,    -1,    -1,   996,   997,    -1,    -1,
    1000,  1001,  1002,  1003,    -1,  1005,    -1,    -1,    -1,    -1,
    1010,    -1,  1815,  1816,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     8,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1850,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1863,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1091,    -1,    -1,    -1,    -1,  1096,    -1,    -1,    -1,
      -1,    -1,    -1,   379,   380,   381,    -1,    -1,    -1,   385,
     386,   387,   388,   389,   390,   391,    -1,   393,    -1,  1922,
    1923,   397,   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,  1942,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,  1957,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1193,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    13,    14,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    75,    -1,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,  2071,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2089,  2090,  2091,  2092,
    2093,   567,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,   114,   115,   116,   117,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,  1332,   134,   135,     8,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2150,    -1,   202,
     203,   204,   205,   206,   155,    -1,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,   220,   221,    13,
      14,    -1,    -1,  1373,    -1,    -1,    -1,    -1,   179,   180,
     181,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,     8,    -1,   249,    -1,    -1,    -1,
     253,    -1,    -1,   256,    -1,  1405,  1406,  1407,  1408,  1409,
      -1,    -1,    -1,    -1,  1414,  1415,    -1,    -1,    -1,    -1,
    1420,    -1,  1422,    -1,    -1,    -1,  1426,    -1,    -1,  1429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,    -1,
     114,   115,   116,   117,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,
     134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,  1512,    -1,  1514,    -1,    -1,    -1,  1518,    -1,
    1520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1551,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,   875,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,   909,   248,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,  1649,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    68,    69,    70,    -1,    -1,    73,    74,
      75,    -1,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    -1,    94,
      -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,  1751,   117,    -1,  1754,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,   134,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1804,  1805,    -1,  1807,    -1,  1085,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,   206,   207,    -1,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,   220,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1867,  1868,    -1,
      -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1915,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    69,    70,    -1,    -1,    73,
      74,    75,    -1,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,  1333,  1334,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,   206,   207,    -1,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,   220,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1424,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,  1434,  2159,
     244,    -1,    -1,    -1,    -1,   249,     3,     4,     5,   253,
       7,    -1,   256,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    -1,    94,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1589,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    75,    -1,    77,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,   206,
      91,    -1,    -1,    94,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,   220,   221,   222,   223,   224,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,   238,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
      -1,    -1,   249,    -1,   251,     3,     4,     5,   255,   256,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,   203,   204,   205,    73,    74,    -1,    -1,    -1,
      78,    79,    80,   214,    -1,    -1,    -1,   218,    -1,   220,
     221,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,     3,     4,    -1,   253,    -1,     8,   256,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
      -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,
     161,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,     3,
       4,     5,    -1,   254,    -1,   256,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    -1,   206,   207,    -1,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,   249,     3,     4,    -1,   253,
      -1,    -1,   256,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,
     137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,    -1,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,
     207,    -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,   249,     3,     4,    -1,   253,   254,    -1,   256,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,
       3,     4,    -1,   253,    -1,    -1,   256,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,
      -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,   249,     3,     4,    -1,
     253,    -1,    -1,   256,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,    -1,   132,    -1,   134,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,
     206,   207,    -1,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,     3,     4,    -1,   253,    -1,    -1,
     256,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   207,    -1,
      -1,    -1,   211,   212,   213,    -1,   215,   216,   217,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
     249,     3,     4,    -1,    -1,   254,    -1,   256,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,
     132,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,    -1,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,   249,     3,     4,
      -1,   253,    -1,    -1,   256,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,   134,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,
      -1,   206,   207,    -1,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,   249,     3,     4,    -1,   253,    -1,
      -1,   256,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,     3,     4,    -1,   253,    -1,     8,   256,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
      -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,
     161,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,     3,     4,    -1,    -1,   249,     8,
      -1,    10,    11,    12,    -1,   256,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   207,    -1,
      -1,    -1,   211,   212,   213,    -1,   215,   216,   217,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,
      -1,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,    -1,
     249,    -1,    -1,    10,    11,    12,    -1,   256,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,
     137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,    -1,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,
     207,    -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,   249,     3,     4,    -1,   253,    -1,    -1,   256,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,
       3,     4,    -1,   253,    -1,    -1,   256,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,
      -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,     3,     4,     5,    -1,   249,    -1,    -1,    10,
      11,    12,    -1,   256,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    75,    -1,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    -1,    94,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,    -1,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    -1,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,   220,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,   253,    -1,    -1,   256,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,   202,   203,   204,   205,   206,    -1,    -1,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
     249,     3,     4,     5,   253,    -1,    -1,   256,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    -1,    94,     3,     4,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,   220,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,
       3,     4,    -1,   253,    -1,    -1,   256,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    89,    90,     8,    92,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   202,
      -1,    -1,    -1,   206,    -1,   258,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
     253,    -1,    -1,   256,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,   258,    -1,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,    -1,   249,
      -1,    -1,    10,    11,    12,    -1,   256,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,     3,     4,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,   202,    -1,    -1,   248,   206,    -1,
      -1,    -1,   253,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,   250,    -1,    -1,    -1,    -1,    -1,   256,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,   202,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
       6,   249,    -1,    -1,    10,    11,    12,    -1,   256,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,     3,     4,    -1,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,   202,    -1,    -1,   248,
     206,    -1,    -1,    -1,   253,   211,   212,   213,    -1,   215,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,     3,
       4,    -1,    -1,   249,    -1,    -1,    10,    11,    12,    -1,
     256,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    89,    90,    -1,    92,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    92,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   202,    -1,
      -1,    -1,   206,    -1,   258,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,
      -1,    -1,   256,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,   258,    -1,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,     3,     4,    -1,    -1,   249,   250,
      -1,    10,    11,    12,    -1,   256,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    92,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      13,    14,    -1,   114,   115,   116,   117,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   179,   180,
     181,    -1,   211,   212,   213,    -1,   215,   216,   217,    -1,
      -1,    -1,   221,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   237,   238,
      -1,   114,   115,   116,   117,   244,    -1,   120,    13,    14,
     249,    -1,    -1,    -1,   127,   128,    -1,   256,   131,   132,
      -1,   134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   254,    -1,    -1,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,   179,   180,   181,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,   114,
     115,   116,   117,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   179,   180,   181,   114,   115,   116,
     117,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   179,   180,   181,   114,   115,   116,   117,   254,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     179,   180,   181,   114,   115,   116,   117,   254,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   179,   180,
     181,   114,   115,   116,   117,   254,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   179,   180,   181,   114,
     115,   116,   117,   254,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   179,   180,   181,   114,   115,   116,
     117,   254,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   179,   180,   181,   114,   115,   116,   117,   254,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    13,    14,    -1,
      -1,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
     179,   180,   181,   248,    -1,    -1,    -1,   254,    44,    45,
      46,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   254,    -1,   113,   114,   115,
     116,   117,   118,    -1,   120,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,    -1,    -1,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    -1,     4,
      -1,   167,   168,   169,    -1,    -1,    -1,   173,    13,    14,
      -1,    -1,   178,   179,   180,   181,    -1,    -1,   184,    -1,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    -1,    -1,    -1,    44,
      45,    46,   208,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,   221,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,   113,   114,
     115,   116,   117,   118,    -1,   120,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    -1,    -1,   139,   140,   141,    -1,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,   167,   168,   169,    -1,    -1,    -1,   173,    -1,
      -1,    -1,    -1,   178,   179,   180,   181,     4,     5,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,    -1,   221,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,     4,     5,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    98,    -1,     5,   101,    -1,    -1,   104,    -1,   106,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
     117,    -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,   134,    75,    -1,
      77,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    91,    -1,    -1,    94,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   204,   205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,   218,    -1,   220,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,   203,   204,   205,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,   218,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,   218,    -1,   220,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    13,    14,    -1,   114,   115,   116,   117,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,
      -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
     159,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
     179,   180,   181,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,   114,   115,   116,   117,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,   179,   180,
     181,    -1,    -1,    -1,    -1,    -1,    -1,   258,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,   254,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     254,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,   254,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     254,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,   254,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     254,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     253,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,   250,    -1,   252,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,   252,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,   252,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,   252,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,   252,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,   252,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,   252,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
     252,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,   252,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,   252,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,   252,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,   252,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,   252,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   260,   261,     6,     0,     4,    13,    14,    44,
      45,    46,    65,    66,    67,    71,    72,    76,    81,    82,
      83,    84,    85,    87,    88,    90,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   113,   114,   115,   116,   117,   118,   120,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   139,   140,   141,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   167,   168,
     169,   173,   178,   179,   180,   181,   184,   186,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   208,   209,   210,   219,   221,   262,   264,   265,
     285,   304,   306,   310,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   328,   330,   331,   337,   338,   339,   340,
     346,   371,   372,   253,   257,    14,   104,   249,   249,   249,
       6,   253,     6,     6,     6,     6,   249,     6,     6,   253,
       6,     6,   251,   251,     4,   348,   372,   249,   251,   283,
      98,   101,   104,   106,   283,   249,   249,   249,     4,   249,
     249,   249,     4,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   253,   119,   104,     6,   253,    98,
     101,   104,   117,   309,   106,   249,     3,    10,    11,    12,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    56,
      57,    58,    59,    64,    65,    73,    74,    78,    79,    80,
      89,    92,    98,   101,   104,   106,   117,   127,   132,   134,
     137,   202,   206,   207,   211,   212,   213,   215,   216,   217,
     237,   238,   244,   249,   253,   256,   306,   307,   310,   321,
     328,   330,   341,   342,   346,   348,   355,   357,   372,   249,
     253,   253,   104,   104,   127,   101,   104,   106,    98,   101,
     104,   106,   306,   101,   104,   106,   117,   307,   101,   104,
     249,   101,   159,   184,   200,   201,   253,   237,   238,   249,
     253,   352,   353,   352,   253,   253,   352,     4,    98,   102,
     108,   109,   111,   112,   131,   253,   249,   104,   106,   104,
     101,     4,    90,   195,   253,   372,     4,     6,    98,   101,
     104,   101,   104,   117,   308,     4,     4,     4,     5,   249,
     253,   355,   356,     4,   249,   249,   249,     4,   253,   359,
     372,     4,   249,   249,   249,     6,     6,   251,     5,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    60,    61,
      62,    63,    68,    69,    70,    75,    77,    91,    94,   203,
     204,   205,   214,   218,   220,   363,   372,   249,     4,   363,
       5,   253,     5,   253,    32,   238,   341,   372,   251,   253,
     249,   253,     6,   249,   253,     6,   257,     7,   134,   195,
     222,   223,   224,   225,   245,   246,   249,   251,   255,   281,
     282,   283,   306,   341,   362,   363,   372,     4,   310,   311,
     312,   253,     6,   341,   362,   363,   372,   362,   362,   341,
     362,   369,   370,   372,   341,   287,   291,   249,   351,     9,
     363,   249,   249,   249,   249,   372,   341,   341,   341,   249,
     341,   341,   341,   249,   341,   341,   341,   341,   341,   341,
     341,   362,   341,   341,   341,   341,   356,   249,   238,   341,
     357,   358,   253,   356,   355,   362,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   249,
     251,   283,   283,   283,   283,   283,   283,   249,   283,   283,
     249,   306,   307,   307,   283,   283,     5,   253,   253,   127,
     306,   306,   249,   283,   283,   249,   249,   249,   341,   253,
     341,   357,   341,   341,   254,   358,   348,   372,   187,     5,
     253,     8,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     248,     9,   249,   251,   255,   282,   283,   341,   358,   358,
     249,   249,   249,   355,   356,   356,   356,   305,   253,   249,
     355,   253,   253,   341,     4,   355,   253,   359,   253,   253,
     352,   352,   352,   341,   341,   237,   238,   253,   253,   352,
     237,   238,   249,   312,   352,   253,   249,   253,   249,   249,
     249,   249,   249,   249,   249,   358,   341,   356,   356,   356,
     249,     4,   251,   253,     6,   251,   312,     6,     6,   253,
     253,   253,   253,   356,   251,   251,   251,   341,     8,     6,
       6,   341,   341,   341,   255,   341,   253,   187,   341,   341,
     341,   341,   283,   283,   283,   249,   249,   249,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   249,   249,
     283,   249,   251,     6,     6,   253,     6,     8,   312,     6,
       8,   312,   283,   341,   239,   253,     9,   249,   251,   255,
     362,   358,   341,   312,   355,   355,   253,   363,   306,     7,
     341,   341,     4,   184,   185,   355,     6,   250,   252,   253,
     284,   253,     6,   253,     6,     9,   249,   251,   255,   372,
     254,   127,   132,   134,   135,   137,   304,   306,   341,     6,
     250,   258,     9,   249,   251,   255,   250,   258,   250,   258,
     258,   250,   258,     9,   249,   255,   258,   252,   258,   286,
     252,   286,    93,   350,   347,   372,   258,   341,   341,   341,
     341,   258,   250,   250,   250,   341,   250,   250,   250,   341,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   254,     7,   341,   239,   254,   258,   341,     6,     6,
     250,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   357,   341,
     341,   341,   341,   341,   341,   341,   357,   357,   372,   253,
     341,   341,   362,   341,   362,   355,   362,   362,   369,   253,
     253,   253,   341,   284,   372,     8,   341,   341,   356,   355,
     362,   362,   357,   348,   363,   348,   358,   250,   254,   255,
     283,    65,     8,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   253,   341,   357,
     341,   341,   341,   341,   341,   372,   341,   341,     4,   349,
     253,   284,   250,   254,   254,   341,   341,   341,     7,     7,
     334,   334,   249,   341,   341,     6,   358,   358,   253,   250,
       6,   312,   253,   312,   312,   258,   258,   258,   352,   352,
     311,   311,   258,   341,   254,   325,   258,   312,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   254,   250,     7,
     335,     6,     7,   341,     6,   341,   312,   341,   254,   358,
     358,   358,   341,     6,   341,   341,   341,   250,   254,   250,
     250,   250,   184,   258,   312,   253,     8,   250,   250,   252,
     369,   362,   369,   362,   362,   362,   362,   362,   362,   341,
     362,   362,   362,   362,   256,   365,   372,   363,   362,   362,
     362,   348,   372,   358,   254,   254,   254,   254,   341,   341,
     312,   372,   349,   252,   254,   250,   141,   159,   329,   250,
     254,   258,   341,     6,   253,   355,   250,   252,     7,   281,
     282,   255,     7,     6,   358,     7,   222,   281,   341,   266,
     372,   341,   341,   349,   251,   249,   127,   306,   307,   306,
     253,   254,     6,   233,   236,   263,   358,   372,   341,   341,
       4,   349,     6,   358,     6,   358,   341,     6,   362,   370,
     372,   250,   349,   341,     6,   372,     6,   362,   341,   250,
     251,   341,   258,   258,   258,   258,   363,     7,     7,     7,
     250,     7,     7,     7,   250,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   341,   250,   253,   341,   357,
     254,     6,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   258,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   258,   258,   258,   250,   252,   252,   358,
     258,   258,   284,   258,   284,   258,   258,   258,   250,   358,
     341,   341,   343,   284,   254,   254,   254,   258,   258,   284,
     284,   250,   255,   250,   255,   258,   283,   344,   254,     7,
     349,   284,   253,   254,     8,     8,   358,   255,   250,   252,
     282,   249,   251,   283,   358,     7,   253,   253,   250,   250,
     250,   341,   355,     4,   333,     6,   300,   341,   363,   254,
     250,   254,   254,   358,   255,   254,   312,   254,   254,   352,
     341,   341,   254,   254,   341,   352,   138,   138,   156,   164,
     165,   166,   170,   171,   326,   327,   352,   254,   322,   250,
     254,   250,   250,   250,   250,   250,   250,   250,   253,     7,
     341,     6,   341,   250,   252,   254,   252,   254,   254,   254,
     254,   252,   252,   258,     7,     7,     7,   255,   341,   254,
     341,   341,     7,   255,   284,   258,   284,   284,   250,   250,
     258,   284,   284,   258,   258,   284,   284,   284,   284,   341,
     284,     9,   364,   258,   250,   258,   284,   255,   258,   345,
     252,   254,   254,   255,   249,   251,   257,   187,     7,   159,
       6,   341,   254,   253,     6,   355,   254,   341,     6,     7,
     281,   282,   255,   281,   282,   363,   341,     6,     4,   253,
     360,   372,   254,    47,    47,   355,   254,     4,   174,   175,
     176,   177,   254,   269,   273,   276,   278,   279,   255,   250,
     252,   249,   341,   341,   249,   253,   249,   253,     8,   358,
     362,   250,   255,   250,   252,   249,   250,   250,   258,   255,
     249,   258,     7,   283,     4,   294,   295,   296,   284,   341,
     341,   341,   341,   284,   352,   355,   355,     7,   355,   355,
     355,     7,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,     6,     7,   358,   341,   341,   341,   341,   254,
     341,   341,   341,   355,   362,   362,   254,   254,   254,   258,
     293,   341,   341,   349,   349,   341,   341,   250,   355,   283,
     341,   341,   341,   254,   349,   282,   255,   282,   341,   341,
     284,   254,   355,   358,   358,     7,     7,     7,   138,   332,
       6,   250,   258,     7,     7,     7,   254,     4,   254,   258,
     258,   258,   254,   254,   116,     4,     6,   341,   253,     6,
     249,     6,   172,     6,   172,   254,   327,   258,   326,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   311,   355,
       6,   253,     6,     6,     6,   104,     7,     6,     6,   341,
     355,   355,   355,     4,   258,     8,     8,   250,     4,   107,
     108,     4,   358,   362,   341,   362,   256,   258,   297,   362,
     362,   349,   362,   250,   258,   349,   253,   306,   253,     6,
     341,     6,   253,   355,   254,   254,   341,     6,     4,   184,
     185,   341,     6,     6,     6,     7,   359,   361,     6,   251,
     284,   283,   283,     6,   270,   249,   249,   253,   280,     6,
     349,   255,   362,   341,   252,   250,   341,     8,   358,   341,
     358,   254,   254,     6,     6,   263,   349,   255,   341,     6,
       6,   341,   349,   250,   341,   253,   341,   363,   284,    47,
     253,   355,   363,   366,   252,   258,     6,   250,   250,   250,
     250,     6,     6,   131,   302,   302,   355,     6,     6,     6,
     355,   138,   187,   301,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     5,   254,   284,   284,   284,   284,   284,
     258,   258,   258,   250,   284,   284,   295,   284,   250,   284,
     250,   283,   344,   284,     6,   284,   258,   249,   251,   283,
       4,   250,   252,   284,     6,   254,   254,   355,   355,   355,
       4,     6,   281,   341,   355,   253,   253,     7,     6,     7,
     341,   341,   341,   253,   253,   253,   251,     6,   341,   355,
     341,     6,     6,   341,   352,   254,     5,   355,   253,   253,
     253,   253,   253,   253,   253,   355,   254,     6,   358,   253,
     341,   252,     6,     6,   183,   341,   341,   341,     6,     6,
       6,     6,     7,   284,   258,   258,   284,   258,   341,     4,
     199,   298,   299,   284,   250,   284,   345,   363,   249,   251,
     341,   253,   312,     6,   312,   258,     6,     6,     7,   281,
     282,   255,     7,     6,   359,   254,   258,   341,   281,   253,
     284,   367,   368,   369,   367,   249,   341,   341,   354,   355,
     253,   249,     4,     6,   250,     6,   250,   254,   254,   250,
     254,     6,     6,   362,   249,     4,   250,   258,   249,   254,
     355,   363,     7,   283,   292,   341,   357,   296,     6,     6,
       6,     6,   352,     6,     6,     6,   138,   303,    98,   117,
     102,     6,     5,   253,   341,   341,   341,   341,   250,   344,
     341,   341,   341,   284,   282,   253,   253,     6,   301,     6,
     341,   355,     4,     6,   358,   358,   341,   341,   363,   254,
     250,   254,   258,   311,   311,   341,   341,   254,   258,   250,
     254,   258,     6,     6,   354,   352,   352,   352,   352,   352,
     238,   352,     6,   254,   341,     6,     6,   355,   254,   258,
       8,   254,   250,   253,   341,   363,   362,   341,   362,   341,
     363,   366,   368,   363,   258,   250,   258,   254,   341,   329,
     329,   355,   363,   341,     6,     4,   360,     6,   359,   252,
     355,   369,     6,   284,   284,   267,   341,   258,   258,   254,
     258,   268,   341,   341,     6,     6,     6,     6,   341,   341,
     250,     6,   288,   290,   253,   368,   254,   258,     7,     7,
     142,     6,   253,   253,   253,     5,   354,   284,   284,   258,
     284,   250,   258,   250,   252,   358,   358,     6,     6,   253,
     254,   254,   253,     6,     6,   253,   341,   254,   254,   254,
     252,     6,   355,     7,   253,   341,   254,   258,   258,   258,
     258,   258,   258,     6,   254,   182,   341,   341,   358,     6,
       6,   250,   284,   284,   299,   363,   254,   254,   254,   254,
       6,     6,     7,     6,   255,     6,   254,     6,     6,   250,
     258,   341,   341,   253,   355,   254,   258,   250,   250,   258,
     293,   297,   355,   284,   341,   363,   372,   358,   358,   341,
       6,   254,   341,   344,   341,   254,   254,   354,   143,   144,
     149,   336,   143,   144,   336,   358,   311,   254,   258,     6,
     254,   355,   312,   254,     6,   358,   352,   352,   352,   352,
     352,   341,   254,   254,   254,   250,     6,   253,     6,   359,
     185,   271,   341,   258,   258,   354,     6,   341,   341,   254,
     254,   289,     7,   249,   254,   254,   254,   253,   258,   250,
     258,   253,   254,   253,   352,   355,     6,   253,   352,     6,
     254,   254,   341,     6,   138,   254,   323,   253,   254,   258,
     258,   258,   258,   258,     6,     6,     6,   312,     6,   253,
     341,   341,   254,   258,   293,   363,   250,   341,   341,   341,
     358,     6,   352,     6,   352,     6,     6,   254,   341,   326,
     312,     6,   358,   358,   358,   358,   352,   358,   329,   268,
     250,   258,     6,   253,   341,   254,   258,   258,   258,   254,
     258,   258,     6,   254,   254,   324,   254,   254,   254,   254,
     258,   254,   254,   254,   274,   341,   354,   254,   341,   341,
     341,   352,   352,   326,     6,     6,     6,     6,   358,     6,
       6,     6,   253,   250,   254,     6,   254,   284,   258,   258,
     258,   254,   254,   272,   362,   277,   253,     6,   341,   341,
     341,     6,   254,   258,   253,   354,   254,   254,   254,     6,
     362,   275,   362,   254,     6,     6,   254,   258,     6,     6,
     362
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   259,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   263,   263,   264,   264,
     264,   264,   264,   264,   264,   264,   265,   265,   265,   265,
     266,   266,   266,   266,   266,   266,   267,   267,   268,   268,
     270,   271,   269,   272,   272,   274,   273,   275,   275,   277,
     276,   278,   278,   280,   279,   281,   281,   281,   281,   281,
     282,   282,   283,   283,   284,   284,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   286,   286,   287,   287,   287,   288,   287,
     289,   287,   287,   290,   287,   291,   291,   292,   292,   292,
     293,   293,   294,   294,   295,   295,   296,   296,   296,   296,
     296,   297,   297,   298,   298,   299,   299,   299,   299,   299,
     300,   300,   300,   301,   301,   301,   301,   302,   302,   303,
     303,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   305,   304,   306,   306,   306,   306,   306,
     307,   307,   307,   307,   308,   308,   308,   309,   309,   309,
     309,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     311,   311,   312,   312,   312,   312,   312,   312,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   314,   314,   314,   314,   314,   314,   314,   314,   315,
     315,   316,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   319,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   321,   321,   321,
     322,   321,   323,   321,   324,   321,   325,   321,   321,   321,
     321,   321,   321,   326,   326,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   328,   328,   328,   328,
     328,   329,   329,   329,   329,   329,   330,   330,   331,   332,
     332,   333,   333,   334,   334,   335,   335,   336,   336,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   338,   338,   338,   339,   339,
     339,   340,   340,   340,   340,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   343,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     344,   344,   345,   345,   347,   346,   348,   348,   349,   350,
     350,   351,   351,   352,   352,   352,   352,   352,   353,   353,
     353,   353,   354,   354,   355,   355,   355,   355,   355,   355,
     356,   356,   356,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   358,   358,   358,   358,   359,
     359,   359,   359,   360,   360,   361,   361,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   364,   363,   363,
     365,   365,   366,   367,   367,   368,   369,   369,   369,   369,
     370,   370,   370,   371,   371,   371,   372,   372,   372
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     7,     7,     7,     7,     9,     6,     6,     6,     8,
       0,     2,     2,     2,     2,     2,     1,     3,     1,     3,
       0,     0,    10,     1,     3,     0,    13,     1,     3,     0,
      15,     8,    14,     0,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     2,     7,
       7,     4,     3,     6,     9,     7,     6,     7,     6,     4,
       8,     9,     9,     6,     9,     6,     9,     5,     8,     8,
      11,     6,     9,     5,     7,     7,     7,     9,     9,    11,
       7,     9,     9,     0,     1,     0,     3,     5,     0,     9,
       0,    11,     5,     0,     9,     0,     3,     3,     5,     5,
       0,     2,     0,     1,     1,     3,     2,     1,     4,     2,
       2,     0,     2,     1,     3,     2,     2,     2,     2,     2,
       1,     1,     3,     0,     5,     5,     5,     0,     2,     0,
       2,     7,     7,     7,     8,     8,     7,     7,    11,     7,
       8,     8,     8,     9,     3,     4,    10,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     9,     7,     7,
       8,     8,    12,     0,     9,     1,     1,     1,     1,     4,
       1,     1,     1,     4,     1,     1,     4,     1,     1,     1,
       4,     5,    11,     5,     9,     9,     7,     4,     9,     9,
       1,     1,     0,     2,     6,     7,     7,     6,     7,     8,
      10,    14,    16,    12,    14,    14,    14,    14,     8,     8,
       6,     4,     5,     5,     6,     6,     3,     4,     3,     5,
       6,     5,     4,     3,     4,     3,     4,     5,     4,     5,
       3,     5,     7,     7,     3,     7,     3,     2,     2,     2,
       2,     2,    15,     2,     2,     2,     9,     2,     2,     2,
       2,    16,    11,     6,     8,     8,    10,     1,     2,     2,
       1,     3,     3,     4,     4,     1,     1,     5,    11,    13,
       0,     7,     0,    13,     0,    15,     0,     6,     9,     2,
       3,    10,    13,     1,     2,     5,     7,     2,     2,     3,
       2,     3,     2,     3,     9,     6,     1,     1,     1,     1,
       1,     0,     2,     3,     3,     4,     9,     4,    14,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     6,
       7,     6,     5,     3,     8,     8,     8,     8,     8,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
       4,     4,     4,     4,     4,     2,     3,     6,     1,     1,
       1,     2,     5,     7,    10,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     1,     4,     6,     1,     4,
       4,     4,     6,     5,     7,     8,    10,     4,     4,     6,
       4,     3,     2,     5,     5,     3,     5,     6,     8,     6,
       8,     6,     4,     7,     6,     6,     6,     4,     6,     4,
       0,     2,     0,     2,     0,     7,     1,     3,     1,     1,
       2,     0,     3,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     3,     1,     2,     3,     3,     5,     4,     4,     2,
       4,     2,     3,     3,    16,     5,     5,     5,     1,     1,
       1,     3,     5,     7,     4,     4,     4,     6,     6,     8,
       8,     4,    14,     4,     4,     1,     1,     3,     3,     9,
       7,     1,     5,     3,     6,     1,     3,     1,     1,     4,
       4,     3,     5,     6,     8,     6,     4,     5,     1,     4,
       1,     1,     1,     1,     4,     6,     4,     6,     5,     7,
       4,     4,     4,     8,     4,     4,     4,     4,     8,     8,
       6,     4,     6,     4,     1,     4,     4,     0,     6,     4,
       2,     4,     4,     1,     1,     3,     1,     1,     3,     3,
       3,     5,     7,     5,     5,     8,     1,     1,     4
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
#line 6060 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 282 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6066 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 283 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6072 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 284 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6078 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6101 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 304 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6107 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 305 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6113 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 306 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6119 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 307 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6125 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 308 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6131 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 309 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6137 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 310 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6143 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 311 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 312 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6155 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 313 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6161 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 314 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6167 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 315 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6173 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 316 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6179 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 317 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6185 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 318 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6191 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 319 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6197 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 324 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"w";
    }
#line 6205 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 328 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"a";
    }
#line 6213 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 335 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6222 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 340 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Warning((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6231 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 345 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6240 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 350 "Gmsh.y" /* yacc.c:1652  */
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
#line 6258 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 364 "Gmsh.y" /* yacc.c:1652  */
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
#line 6275 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 377 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[-4].c), (yyvsp[-2].l), tmpstring);
      if(i < 0)
	yymsg(1, "Too few arguments in Error");
      else if(i > 0)
	yymsg(1, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Warning(tmpstring);
      Free((yyvsp[-4].c));
      List_Delete((yyvsp[-2].l));
    }
#line 6292 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 390 "Gmsh.y" /* yacc.c:1652  */
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
#line 6309 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 403 "Gmsh.y" /* yacc.c:1652  */
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
#line 6336 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 431 "Gmsh.y" /* yacc.c:1652  */
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
#line 6354 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 445 "Gmsh.y" /* yacc.c:1652  */
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
#line 6371 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 458 "Gmsh.y" /* yacc.c:1652  */
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
#line 6388 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 471 "Gmsh.y" /* yacc.c:1652  */
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
#line 6407 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 489 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 6417 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 503 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6423 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 505 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6429 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 510 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6435 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 512 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6441 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 517 "Gmsh.y" /* yacc.c:1652  */
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
#line 6549 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 621 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(std::size_t j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 6563 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 631 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 6573 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 640 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6584 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 647 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6595 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 657 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 6608 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 666 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 6618 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 675 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6629 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 682 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6640 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 692 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 6652 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 700 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 6662 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 710 "Gmsh.y" /* yacc.c:1652  */
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
#line 6682 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 729 "Gmsh.y" /* yacc.c:1652  */
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
#line 6702 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 748 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 6712 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 754 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 6719 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 761 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 6725 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 762 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6731 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 763 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 6737 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 764 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 6743 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 765 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 4; }
#line 6749 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 769 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6755 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 770 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = -1; }
#line 6761 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 776 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"("; }
#line 6767 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 776 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"["; }
#line 6773 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 74:
#line 777 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)")"; }
#line 6779 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 75:
#line 777 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"]"; }
#line 6785 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 79:
#line 787 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 6794 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 80:
#line 792 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 6804 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 81:
#line 798 "Gmsh.y" /* yacc.c:1652  */
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
#line 6870 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 82:
#line 860 "Gmsh.y" /* yacc.c:1652  */
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
#line 6889 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 83:
#line 875 "Gmsh.y" /* yacc.c:1652  */
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
#line 6922 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 84:
#line 904 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 6933 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 85:
#line 914 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6942 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 86:
#line 919 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6951 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 87:
#line 927 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6960 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 88:
#line 932 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6969 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 89:
#line 940 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 6979 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 90:
#line 949 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 6988 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 91:
#line 954 "Gmsh.y" /* yacc.c:1652  */
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
#line 7004 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 92:
#line 966 "Gmsh.y" /* yacc.c:1652  */
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
#line 7022 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 93:
#line 983 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 7032 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 94:
#line 989 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 7042 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 95:
#line 998 "Gmsh.y" /* yacc.c:1652  */
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
#line 7064 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 96:
#line 1016 "Gmsh.y" /* yacc.c:1652  */
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
#line 7086 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 97:
#line 1034 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 7099 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 98:
#line 1043 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 7112 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 99:
#line 1055 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 7121 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 100:
#line 1060 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 7130 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 101:
#line 1068 "Gmsh.y" /* yacc.c:1652  */
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
#line 7154 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 102:
#line 1088 "Gmsh.y" /* yacc.c:1652  */
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
#line 7178 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 103:
#line 1111 "Gmsh.y" /* yacc.c:1652  */
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
#line 7202 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 104:
#line 1131 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 7214 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 105:
#line 1139 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Box");
#endif
    }
#line 7225 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 106:
#line 1146 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Cylinder");
#endif
    }
#line 7236 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 107:
#line 1153 "Gmsh.y" /* yacc.c:1652  */
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
#line 7262 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 108:
#line 1175 "Gmsh.y" /* yacc.c:1652  */
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
#line 7289 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 109:
#line 1198 "Gmsh.y" /* yacc.c:1652  */
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
#line 7331 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 110:
#line 1236 "Gmsh.y" /* yacc.c:1652  */
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
#line 7353 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 111:
#line 1257 "Gmsh.y" /* yacc.c:1652  */
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
#line 7369 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 112:
#line 1269 "Gmsh.y" /* yacc.c:1652  */
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
#line 7385 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 116:
#line 1287 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 7398 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 117:
#line 1296 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 7411 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 118:
#line 1305 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7417 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 119:
#line 1307 "Gmsh.y" /* yacc.c:1652  */
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
#line 7439 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 120:
#line 1325 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7445 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 121:
#line 1327 "Gmsh.y" /* yacc.c:1652  */
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
#line 7465 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 122:
#line 1343 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 7478 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 123:
#line 1352 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7484 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 124:
#line 1354 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 7498 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 126:
#line 1368 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 7508 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 127:
#line 1376 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7518 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 128:
#line 1382 "Gmsh.y" /* yacc.c:1652  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7527 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 129:
#line 1387 "Gmsh.y" /* yacc.c:1652  */
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
#line 7556 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 136:
#line 1430 "Gmsh.y" /* yacc.c:1652  */
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
#line 7572 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 137:
#line 1442 "Gmsh.y" /* yacc.c:1652  */
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
#line 7589 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 138:
#line 1455 "Gmsh.y" /* yacc.c:1652  */
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
#line 7607 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 139:
#line 1470 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7619 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 140:
#line 1479 "Gmsh.y" /* yacc.c:1652  */
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
#line 7634 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 145:
#line 1504 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 7645 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 146:
#line 1512 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7657 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 147:
#line 1521 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 7668 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 148:
#line 1529 "Gmsh.y" /* yacc.c:1652  */
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
#line 7685 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 149:
#line 1543 "Gmsh.y" /* yacc.c:1652  */
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
#line 7702 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 150:
#line 1561 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 7710 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 151:
#line 1565 "Gmsh.y" /* yacc.c:1652  */
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[0].c)), dim_entity, t + 1);
      Free((yyvsp[0].c));
    }
#line 7721 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 152:
#line 1572 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), dim_entity, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 7730 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 153:
#line 1580 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 7738 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 154:
#line 1584 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[-1].d);
      List_Add((yyval.l), &p);
    }
#line 7748 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 155:
#line 1590 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7756 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 156:
#line 1594 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[-1].l), i));
      List_Delete((yyvsp[-1].l));
    }
#line 7769 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 157:
#line 1605 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 7777 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 158:
#line 1609 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 7785 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 159:
#line 1615 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = 0;
    }
#line 7793 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 160:
#line 1619 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = 1;
    }
#line 7801 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 161:
#line 1625 "Gmsh.y" /* yacc.c:1652  */
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
#line 7828 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 162:
#line 1648 "Gmsh.y" /* yacc.c:1652  */
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
#line 7848 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 163:
#line 1664 "Gmsh.y" /* yacc.c:1652  */
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
#line 7868 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 164:
#line 1680 "Gmsh.y" /* yacc.c:1652  */
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
#line 7909 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 165:
#line 1717 "Gmsh.y" /* yacc.c:1652  */
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
#line 7957 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 166:
#line 1761 "Gmsh.y" /* yacc.c:1652  */
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
#line 7977 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 167:
#line 1777 "Gmsh.y" /* yacc.c:1652  */
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
#line 7997 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 168:
#line 1794 "Gmsh.y" /* yacc.c:1652  */
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
#line 8032 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 169:
#line 1825 "Gmsh.y" /* yacc.c:1652  */
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
#line 8052 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 170:
#line 1841 "Gmsh.y" /* yacc.c:1652  */
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
#line 8073 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 171:
#line 1858 "Gmsh.y" /* yacc.c:1652  */
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
#line 8093 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 172:
#line 1874 "Gmsh.y" /* yacc.c:1652  */
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
#line 8147 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 173:
#line 1924 "Gmsh.y" /* yacc.c:1652  */
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
#line 8169 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 174:
#line 1942 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8179 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 175:
#line 1948 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8189 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 176:
#line 1954 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 8200 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 177:
#line 1961 "Gmsh.y" /* yacc.c:1652  */
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
#line 8235 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 178:
#line 1992 "Gmsh.y" /* yacc.c:1652  */
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
#line 8254 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 179:
#line 2007 "Gmsh.y" /* yacc.c:1652  */
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
#line 8280 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 180:
#line 2029 "Gmsh.y" /* yacc.c:1652  */
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
#line 8307 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 181:
#line 2052 "Gmsh.y" /* yacc.c:1652  */
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
#line 8334 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 182:
#line 2075 "Gmsh.y" /* yacc.c:1652  */
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
#line 8361 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 183:
#line 2098 "Gmsh.y" /* yacc.c:1652  */
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
#line 8389 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 184:
#line 2122 "Gmsh.y" /* yacc.c:1652  */
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
#line 8417 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 185:
#line 2146 "Gmsh.y" /* yacc.c:1652  */
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
#line 8445 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 186:
#line 2170 "Gmsh.y" /* yacc.c:1652  */
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
#line 8475 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 187:
#line 2196 "Gmsh.y" /* yacc.c:1652  */
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
#line 8496 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 188:
#line 2213 "Gmsh.y" /* yacc.c:1652  */
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
#line 8516 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 189:
#line 2229 "Gmsh.y" /* yacc.c:1652  */
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
#line 8538 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 190:
#line 2247 "Gmsh.y" /* yacc.c:1652  */
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
#line 8560 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 191:
#line 2265 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-6].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8571 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 192:
#line 2273 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-10].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8582 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 193:
#line 2280 "Gmsh.y" /* yacc.c:1652  */
    {
      dim_entity = (yyvsp[0].i);
    }
#line 8590 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 194:
#line 2284 "Gmsh.y" /* yacc.c:1652  */
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
#line 8617 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 195:
#line 2310 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8623 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 196:
#line 2312 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8629 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 197:
#line 2314 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8635 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 198:
#line 2316 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8641 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 199:
#line 2318 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
#line 8650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 200:
#line 2326 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8656 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 201:
#line 2328 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8662 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 202:
#line 2330 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8668 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 203:
#line 2332 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
#line 8677 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 204:
#line 2340 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8683 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 205:
#line 2342 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8689 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 206:
#line 2344 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
#line 8698 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 207:
#line 2352 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8704 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 208:
#line 2354 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8710 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 209:
#line 2356 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8716 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 210:
#line 2358 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
#line 8725 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 211:
#line 2368 "Gmsh.y" /* yacc.c:1652  */
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
#line 8745 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 212:
#line 2384 "Gmsh.y" /* yacc.c:1652  */
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
#line 8765 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 213:
#line 2400 "Gmsh.y" /* yacc.c:1652  */
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
#line 8785 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 214:
#line 2416 "Gmsh.y" /* yacc.c:1652  */
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
#line 8805 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 215:
#line 2432 "Gmsh.y" /* yacc.c:1652  */
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
#line 8825 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 216:
#line 2448 "Gmsh.y" /* yacc.c:1652  */
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
#line 8846 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 217:
#line 2465 "Gmsh.y" /* yacc.c:1652  */
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
#line 8887 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 218:
#line 2502 "Gmsh.y" /* yacc.c:1652  */
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
#line 8912 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 219:
#line 2524 "Gmsh.y" /* yacc.c:1652  */
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
#line 8937 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 220:
#line 2547 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8943 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 221:
#line 2548 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8949 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 222:
#line 2553 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 8957 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 223:
#line 2557 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 8965 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 224:
#line 2561 "Gmsh.y" /* yacc.c:1652  */
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
#line 8986 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 225:
#line 2578 "Gmsh.y" /* yacc.c:1652  */
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
#line 9010 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 226:
#line 2598 "Gmsh.y" /* yacc.c:1652  */
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
#line 9034 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 227:
#line 2618 "Gmsh.y" /* yacc.c:1652  */
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
#line 9057 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 228:
#line 2637 "Gmsh.y" /* yacc.c:1652  */
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
#line 9083 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 229:
#line 2664 "Gmsh.y" /* yacc.c:1652  */
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
#line 9106 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 230:
#line 2683 "Gmsh.y" /* yacc.c:1652  */
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
#line 9131 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 231:
#line 2705 "Gmsh.y" /* yacc.c:1652  */
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
#line 9149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 232:
#line 2720 "Gmsh.y" /* yacc.c:1652  */
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
#line 9168 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 233:
#line 2735 "Gmsh.y" /* yacc.c:1652  */
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
#line 9190 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 234:
#line 2754 "Gmsh.y" /* yacc.c:1652  */
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
#line 9244 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 235:
#line 2805 "Gmsh.y" /* yacc.c:1652  */
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
#line 9268 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 236:
#line 2826 "Gmsh.y" /* yacc.c:1652  */
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
#line 9293 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 237:
#line 2848 "Gmsh.y" /* yacc.c:1652  */
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
#line 9319 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 238:
#line 2870 "Gmsh.y" /* yacc.c:1652  */
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
#line 9428 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 239:
#line 2975 "Gmsh.y" /* yacc.c:1652  */
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
#line 9448 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 240:
#line 2991 "Gmsh.y" /* yacc.c:1652  */
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
#line 9482 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 241:
#line 3026 "Gmsh.y" /* yacc.c:1652  */
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
#line 9508 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 242:
#line 3048 "Gmsh.y" /* yacc.c:1652  */
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
#line 9534 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 243:
#line 3070 "Gmsh.y" /* yacc.c:1652  */
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
#line 9550 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 244:
#line 3082 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 9560 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 245:
#line 3088 "Gmsh.y" /* yacc.c:1652  */
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
#line 9579 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 246:
#line 3103 "Gmsh.y" /* yacc.c:1652  */
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
#line 9611 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 247:
#line 3131 "Gmsh.y" /* yacc.c:1652  */
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
#line 9627 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 248:
#line 3143 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yynamespaces.clear();
    }
#line 9635 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 249:
#line 3152 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), false);
      List_Delete((yyvsp[-1].l));
    }
#line 9646 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 250:
#line 3159 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), true);
      List_Delete((yyvsp[-1].l));
    }
#line 9657 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 251:
#line 3171 "Gmsh.y" /* yacc.c:1652  */
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
#line 9676 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 252:
#line 3191 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
    }
#line 9684 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 253:
#line 3195 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[-1].c));
    }
#line 9693 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 254:
#line 3200 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
    }
#line 9701 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 255:
#line 3204 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[-1].c));
    }
#line 9710 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 256:
#line 3209 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9721 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 257:
#line 3216 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9732 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 258:
#line 3223 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9743 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 259:
#line 3230 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9754 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 260:
#line 3242 "Gmsh.y" /* yacc.c:1652  */
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
#line 9831 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 261:
#line 3315 "Gmsh.y" /* yacc.c:1652  */
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
#line 9853 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 262:
#line 3333 "Gmsh.y" /* yacc.c:1652  */
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
#line 9882 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 263:
#line 3358 "Gmsh.y" /* yacc.c:1652  */
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
#line 9901 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 264:
#line 3373 "Gmsh.y" /* yacc.c:1652  */
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
#line 9938 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 265:
#line 3406 "Gmsh.y" /* yacc.c:1652  */
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
#line 9954 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 266:
#line 3418 "Gmsh.y" /* yacc.c:1652  */
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
#line 9982 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 267:
#line 3442 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Exit(0);
    }
#line 9990 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 268:
#line 3446 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 9999 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 269:
#line 3451 "Gmsh.y" /* yacc.c:1652  */
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
#line 10010 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 270:
#line 3458 "Gmsh.y" /* yacc.c:1652  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 10019 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 271:
#line 3463 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
#line 10033 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 272:
#line 3473 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 10042 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 273:
#line 3478 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 10052 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 274:
#line 3484 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 10064 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 275:
#line 3492 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 10072 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 276:
#line 3496 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->classifySurfaces((yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 10080 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 277:
#line 3500 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    }
#line 10088 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 278:
#line 3504 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshVertices();
    }
#line 10096 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 279:
#line 3508 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshElements();
    }
#line 10104 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 280:
#line 3512 "Gmsh.y" /* yacc.c:1652  */
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 10117 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 281:
#line 3522 "Gmsh.y" /* yacc.c:1652  */
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
#line 10179 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 282:
#line 3585 "Gmsh.y" /* yacc.c:1652  */
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
#line 10195 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 283:
#line 3601 "Gmsh.y" /* yacc.c:1652  */
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
#line 10216 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 284:
#line 3618 "Gmsh.y" /* yacc.c:1652  */
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
#line 10237 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 285:
#line 3635 "Gmsh.y" /* yacc.c:1652  */
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
#line 10263 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 286:
#line 3657 "Gmsh.y" /* yacc.c:1652  */
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
#line 10289 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 287:
#line 3679 "Gmsh.y" /* yacc.c:1652  */
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
#line 10328 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 288:
#line 3714 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10340 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 289:
#line 3722 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10352 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 290:
#line 3730 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 10362 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 291:
#line 3736 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10373 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 292:
#line 3743 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10384 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 293:
#line 3750 "Gmsh.y" /* yacc.c:1652  */
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
#line 10408 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 294:
#line 3770 "Gmsh.y" /* yacc.c:1652  */
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
#line 10438 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 295:
#line 3796 "Gmsh.y" /* yacc.c:1652  */
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
#line 10454 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 296:
#line 3808 "Gmsh.y" /* yacc.c:1652  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 10464 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 297:
#line 3819 "Gmsh.y" /* yacc.c:1652  */
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
#line 10486 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 298:
#line 3837 "Gmsh.y" /* yacc.c:1652  */
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
#line 10508 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 299:
#line 3855 "Gmsh.y" /* yacc.c:1652  */
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
#line 10530 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 300:
#line 3873 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10540 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 301:
#line 3879 "Gmsh.y" /* yacc.c:1652  */
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
#line 10562 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 302:
#line 3897 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10572 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 303:
#line 3903 "Gmsh.y" /* yacc.c:1652  */
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
#line 10596 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 304:
#line 3923 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10606 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 305:
#line 3929 "Gmsh.y" /* yacc.c:1652  */
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
#line 10628 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 306:
#line 3947 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10638 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 307:
#line 3953 "Gmsh.y" /* yacc.c:1652  */
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
#line 10659 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 308:
#line 3970 "Gmsh.y" /* yacc.c:1652  */
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
#line 10679 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 309:
#line 3986 "Gmsh.y" /* yacc.c:1652  */
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
#line 10700 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 310:
#line 4003 "Gmsh.y" /* yacc.c:1652  */
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
#line 10721 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 311:
#line 4021 "Gmsh.y" /* yacc.c:1652  */
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
#line 10747 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 312:
#line 4044 "Gmsh.y" /* yacc.c:1652  */
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
#line 10775 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 313:
#line 4071 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10782 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 314:
#line 4074 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10789 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 315:
#line 4080 "Gmsh.y" /* yacc.c:1652  */
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
#line 10805 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 316:
#line 4092 "Gmsh.y" /* yacc.c:1652  */
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
#line 10829 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 317:
#line 4112 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 10837 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 318:
#line 4116 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = true;
    }
#line 10845 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 319:
#line 4120 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 10853 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 320:
#line 4124 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 10861 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 321:
#line 4128 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 10869 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 322:
#line 4132 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 10877 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 323:
#line 4136 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 10885 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 324:
#line 4140 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      int num = (int)(yyvsp[-6].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[-1].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[-3].l));
    }
#line 10898 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 325:
#line 4149 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 10910 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 326:
#line 4161 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Union; }
#line 10916 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 327:
#line 4162 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Intersection; }
#line 10922 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 328:
#line 4163 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Difference; }
#line 10928 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 329:
#line 4164 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Section; }
#line 10934 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 330:
#line 4165 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Fragments; }
#line 10940 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 331:
#line 4169 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 10946 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 332:
#line 4170 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 10952 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 333:
#line 4171 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 10958 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 334:
#line 4172 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 1 : 0; }
#line 10964 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 335:
#line 4173 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 2 : 0; }
#line 10970 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 336:
#line 4178 "Gmsh.y" /* yacc.c:1652  */
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
#line 10997 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 337:
#line 4201 "Gmsh.y" /* yacc.c:1652  */
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
#line 11017 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 338:
#line 4221 "Gmsh.y" /* yacc.c:1652  */
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
#line 11039 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 339:
#line 4242 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 11047 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 340:
#line 4246 "Gmsh.y" /* yacc.c:1652  */
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
#line 11064 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 341:
#line 4261 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = -1; // left
    }
#line 11072 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 342:
#line 4265 "Gmsh.y" /* yacc.c:1652  */
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
#line 11090 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 343:
#line 4281 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 11098 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 344:
#line 4285 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 11106 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 345:
#line 4290 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = 45;
    }
#line 11114 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 346:
#line 4294 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 11122 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 347:
#line 4300 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 11130 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 348:
#line 4304 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11138 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 349:
#line 4311 "Gmsh.y" /* yacc.c:1652  */
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
#line 11164 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 350:
#line 4333 "Gmsh.y" /* yacc.c:1652  */
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
#line 11209 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 351:
#line 4374 "Gmsh.y" /* yacc.c:1652  */
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
#line 11257 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 352:
#line 4418 "Gmsh.y" /* yacc.c:1652  */
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
#line 11300 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 353:
#line 4457 "Gmsh.y" /* yacc.c:1652  */
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
#line 11329 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 354:
#line 4482 "Gmsh.y" /* yacc.c:1652  */
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
#line 11345 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 355:
#line 4494 "Gmsh.y" /* yacc.c:1652  */
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
#line 11361 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 356:
#line 4506 "Gmsh.y" /* yacc.c:1652  */
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
#line 11377 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 357:
#line 4518 "Gmsh.y" /* yacc.c:1652  */
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
#line 11393 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 358:
#line 4530 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[-1].d);
      }
      List_Delete((yyvsp[-4].l));
    }
#line 11406 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 359:
#line 4539 "Gmsh.y" /* yacc.c:1652  */
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
#line 11440 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 360:
#line 4569 "Gmsh.y" /* yacc.c:1652  */
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
#line 11470 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 361:
#line 4595 "Gmsh.y" /* yacc.c:1652  */
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
#line 11500 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 362:
#line 4622 "Gmsh.y" /* yacc.c:1652  */
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
#line 11535 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 363:
#line 4654 "Gmsh.y" /* yacc.c:1652  */
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
#line 11565 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 364:
#line 4681 "Gmsh.y" /* yacc.c:1652  */
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
#line 11594 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 365:
#line 4707 "Gmsh.y" /* yacc.c:1652  */
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
#line 11623 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 366:
#line 4733 "Gmsh.y" /* yacc.c:1652  */
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
#line 11652 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 367:
#line 4759 "Gmsh.y" /* yacc.c:1652  */
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
#line 11681 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 368:
#line 4785 "Gmsh.y" /* yacc.c:1652  */
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
#line 11706 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 369:
#line 4806 "Gmsh.y" /* yacc.c:1652  */
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
#line 11721 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 370:
#line 4817 "Gmsh.y" /* yacc.c:1652  */
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
#line 11773 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 371:
#line 4865 "Gmsh.y" /* yacc.c:1652  */
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
#line 11831 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 372:
#line 4919 "Gmsh.y" /* yacc.c:1652  */
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
#line 11850 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 373:
#line 4934 "Gmsh.y" /* yacc.c:1652  */
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
#line 11866 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 374:
#line 4946 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-2].i), tags);
      List_Delete((yyvsp[-1].l));
    }
#line 11876 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 375:
#line 4957 "Gmsh.y" /* yacc.c:1652  */
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
#line 11887 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 376:
#line 4964 "Gmsh.y" /* yacc.c:1652  */
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
#line 11906 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 377:
#line 4979 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[-2].l));
    }
#line 11919 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 378:
#line 4992 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Homology"; }
#line 11925 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 379:
#line 4993 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 11931 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 380:
#line 4994 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Betti"; }
#line 11937 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 381:
#line 4999 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 11947 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 382:
#line 5005 "Gmsh.y" /* yacc.c:1652  */
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
#line 11963 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 383:
#line 5017 "Gmsh.y" /* yacc.c:1652  */
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
#line 11985 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 384:
#line 5035 "Gmsh.y" /* yacc.c:1652  */
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
#line 12012 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 385:
#line 5062 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 12018 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 386:
#line 5063 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 12024 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 387:
#line 5064 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 12030 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 388:
#line 5065 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 12036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 389:
#line 5066 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 12042 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 390:
#line 5067 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 12048 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 391:
#line 5068 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 12054 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 392:
#line 5069 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 12060 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 393:
#line 5071 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 12071 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 394:
#line 5077 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) | (int)(yyvsp[0].d); }
#line 12077 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 395:
#line 5078 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) & (int)(yyvsp[0].d); }
#line 12083 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 396:
#line 5079 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d); }
#line 12089 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 397:
#line 5080 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 12095 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 398:
#line 5081 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 12101 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 399:
#line 5082 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 12107 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 400:
#line 5083 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 12113 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 401:
#line 5084 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 12119 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 402:
#line 5085 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 12125 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 403:
#line 5086 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 12131 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 404:
#line 5087 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 12137 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 405:
#line 5088 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 12143 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 406:
#line 5089 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) >> (int)(yyvsp[0].d)); }
#line 12149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 407:
#line 5090 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) << (int)(yyvsp[0].d)); }
#line 12155 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 408:
#line 5091 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 12161 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 409:
#line 5092 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 12167 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 410:
#line 5093 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 12173 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 411:
#line 5094 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 12179 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 412:
#line 5095 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 12185 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 413:
#line 5096 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 12191 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 414:
#line 5097 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 12197 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 415:
#line 5098 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 12203 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 416:
#line 5099 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 12209 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 417:
#line 5100 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 12215 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 418:
#line 5101 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 12221 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 419:
#line 5102 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 12227 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 420:
#line 5103 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 12233 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 421:
#line 5104 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 12239 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 422:
#line 5105 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 12245 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 423:
#line 5106 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 12251 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 424:
#line 5107 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = std::abs((yyvsp[-1].d)); }
#line 12257 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 425:
#line 5108 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 12263 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 426:
#line 5109 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 12269 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 427:
#line 5110 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 12275 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 428:
#line 5111 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12281 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 429:
#line 5112 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12287 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 430:
#line 5113 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 12293 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 431:
#line 5114 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 12299 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 432:
#line 5123 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12305 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 433:
#line 5124 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 3.141592653589793; }
#line 12311 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 434:
#line 5125 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 12317 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 435:
#line 5126 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 12323 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 436:
#line 5127 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 12329 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 437:
#line 5128 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 12335 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 438:
#line 5129 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 12341 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 439:
#line 5130 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 12347 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 440:
#line 5131 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Cpu(); }
#line 12353 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 441:
#line 5132 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 12359 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 442:
#line 5133 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = TotalRam(); }
#line 12365 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 443:
#line 5138 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 12371 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 444:
#line 5140 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 12381 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 445:
#line 5146 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12387 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 446:
#line 5148 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12396 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 447:
#line 5153 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12405 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 448:
#line 5158 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[0].c2).char1, (yyvsp[0].c2).char2);
    }
#line 12413 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 449:
#line 5163 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12421 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 450:
#line 5168 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12429 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 451:
#line 5172 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-1].c2).char1, (yyvsp[-1].c2).char2, 1, 0, 0., 1);
    }
#line 12437 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 452:
#line 5176 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-3].c2).char1, (yyvsp[-3].c2).char2, (yyvsp[-1].c), 0, 0., 1);
    }
#line 12445 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 453:
#line 5180 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-2].c2).char1, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].d), 2);
    }
#line 12453 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 454:
#line 5184 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].d), 2);
    }
#line 12461 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 455:
#line 5188 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-5].c2).char1, (yyvsp[-5].c2).char2, 2, (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12469 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 456:
#line 5192 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c2).char1, (yyvsp[-7].c2).char2, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12477 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 457:
#line 5196 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 12487 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 458:
#line 5202 "Gmsh.y" /* yacc.c:1652  */
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
#line 12506 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 459:
#line 5217 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c));
    }
#line 12514 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 460:
#line 5221 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[-1].c));
    }
#line 12524 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 461:
#line 5227 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
#line 12533 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 462:
#line 5232 "Gmsh.y" /* yacc.c:1652  */
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
#line 12556 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 463:
#line 5251 "Gmsh.y" /* yacc.c:1652  */
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
#line 12580 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 464:
#line 5271 "Gmsh.y" /* yacc.c:1652  */
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
#line 12604 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 465:
#line 5302 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12612 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 466:
#line 5306 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12620 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 467:
#line 5310 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12628 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 468:
#line 5314 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12636 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 469:
#line 5318 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12644 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 470:
#line 5322 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12652 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 471:
#line 5326 "Gmsh.y" /* yacc.c:1652  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12661 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 472:
#line 5331 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12675 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 473:
#line 5341 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 12689 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 474:
#line 5351 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12698 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 475:
#line 5356 "Gmsh.y" /* yacc.c:1652  */
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
#line 12713 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 476:
#line 5367 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12726 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 477:
#line 5376 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strlen((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12735 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 478:
#line 5381 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12744 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 479:
#line 5386 "Gmsh.y" /* yacc.c:1652  */
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
#line 12772 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 480:
#line 5413 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 0.; }
#line 12778 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 481:
#line 5415 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);}
#line 12784 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 482:
#line 5420 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = NULL; }
#line 12790 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 483:
#line 5422 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c);}
#line 12796 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 484:
#line 5427 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c2).char1? (yyvsp[-1].c2).char1 : std::string("")),
        struct_name((yyvsp[-1].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
#line 12807 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 485:
#line 5434 "Gmsh.y" /* yacc.c:1652  */
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
#line 12824 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 486:
#line 5450 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[0].c); }
#line 12830 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 487:
#line 5452 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = (yyvsp[-2].c); (yyval.c2).char2 = (yyvsp[0].c); }
#line 12836 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 488:
#line 5457 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); flag_tSTRING_alloc = 1; }
#line 12842 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 489:
#line 5466 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 99; }
#line 12848 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 490:
#line 5468 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (int)(yyvsp[0].d); }
#line 12854 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 491:
#line 5473 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 12860 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 492:
#line 5475 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 12866 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 493:
#line 5480 "Gmsh.y" /* yacc.c:1652  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 12874 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 494:
#line 5484 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 12882 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 495:
#line 5488 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 12890 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 496:
#line 5492 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 12898 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 497:
#line 5496 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 12906 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 498:
#line 5503 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 12914 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 499:
#line 5507 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 12922 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 500:
#line 5511 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12930 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 501:
#line 5515 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12938 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 502:
#line 5522 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12947 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 503:
#line 5527 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12955 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 504:
#line 5534 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12964 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 505:
#line 5539 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12972 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 506:
#line 5543 "Gmsh.y" /* yacc.c:1652  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 12981 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 507:
#line 5548 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12989 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 508:
#line 5552 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 13001 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 509:
#line 5560 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 13013 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 510:
#line 5571 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13021 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 511:
#line 5575 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 13029 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 512:
#line 5579 "Gmsh.y" /* yacc.c:1652  */
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
#line 13044 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 513:
#line 5593 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 13056 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 514:
#line 5601 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 13068 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 515:
#line 5609 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 13079 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 516:
#line 5616 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 13093 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 517:
#line 5626 "Gmsh.y" /* yacc.c:1652  */
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
#line 13120 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 518:
#line 5649 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    }
#line 13129 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 519:
#line 5654 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[0].c));
    }
#line 13139 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 520:
#line 5660 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-3].i), (yyval.l));
    }
#line 13148 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 521:
#line 5665 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-1].i), (yyval.l));
      Free((yyvsp[0].c));
    }
#line 13158 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 522:
#line 5671 "Gmsh.y" /* yacc.c:1652  */
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
#line 13173 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 523:
#line 5682 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[-1].i), (yyvsp[0].l), (yyval.l));
      List_Delete((yyvsp[0].l));
    }
#line 13183 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 524:
#line 5689 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[-15].i), (yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d), (yyval.l));
    }
#line 13192 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 525:
#line 5694 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[-3].i), (yyvsp[-1].l), (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 13202 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 526:
#line 5700 "Gmsh.y" /* yacc.c:1652  */
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
#line 13218 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 527:
#line 5712 "Gmsh.y" /* yacc.c:1652  */
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
#line 13236 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 528:
#line 5726 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13250 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 529:
#line 5736 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13264 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 530:
#line 5746 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13278 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 531:
#line 5756 "Gmsh.y" /* yacc.c:1652  */
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
#line 13294 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 532:
#line 5768 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13302 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 533:
#line 5772 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13310 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 534:
#line 5777 "Gmsh.y" /* yacc.c:1652  */
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
#line 13326 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 535:
#line 5789 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13334 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 536:
#line 5793 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13342 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 537:
#line 5797 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 13350 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 538:
#line 5801 "Gmsh.y" /* yacc.c:1652  */
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
#line 13372 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 539:
#line 5819 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = (yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1);
	List_Add((yyval.l), &d);
      }
    }
#line 13384 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 540:
#line 5827 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = pow(10,(yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1));
	List_Add((yyval.l), &d);
      }
    }
#line 13396 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 541:
#line 5835 "Gmsh.y" /* yacc.c:1652  */
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
#line 13429 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 542:
#line 5864 "Gmsh.y" /* yacc.c:1652  */
    {
      double x0 = (yyvsp[-11].d), x1 = (yyvsp[-9].d), y0 = (yyvsp[-7].d), y1 = (yyvsp[-5].d), ys = (yyvsp[-3].d);
      int N = (int)(yyvsp[-1].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
#line 13443 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 543:
#line 5874 "Gmsh.y" /* yacc.c:1652  */
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
#line 13463 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 544:
#line 5890 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[-1].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13475 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 545:
#line 5901 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13484 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 546:
#line 5906 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13492 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 547:
#line 5910 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13500 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 548:
#line 5914 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13513 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 549:
#line 5926 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 13521 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 550:
#line 5930 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 13529 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 551:
#line 5942 "Gmsh.y" /* yacc.c:1652  */
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
#line 13550 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 552:
#line 5959 "Gmsh.y" /* yacc.c:1652  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 13561 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 553:
#line 5969 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13569 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 554:
#line 5973 "Gmsh.y" /* yacc.c:1652  */
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
#line 13585 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 555:
#line 5988 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13594 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 556:
#line 5993 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13602 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 557:
#line 6000 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13610 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 558:
#line 6004 "Gmsh.y" /* yacc.c:1652  */
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[0].c));
    }
#line 13619 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 559:
#line 6009 "Gmsh.y" /* yacc.c:1652  */
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
#line 13637 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 560:
#line 6023 "Gmsh.y" /* yacc.c:1652  */
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
#line 13655 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 561:
#line 6039 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13663 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 562:
#line 6043 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13671 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 563:
#line 6047 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13679 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 564:
#line 6051 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13687 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 565:
#line 6055 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 13699 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 566:
#line 6063 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13709 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 567:
#line 6069 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13719 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 568:
#line 6078 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13727 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 569:
#line 6082 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13735 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 570:
#line 6086 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 13747 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 571:
#line 6094 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 13757 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 572:
#line 6100 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 13767 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 573:
#line 6106 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
#line 13775 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 574:
#line 6110 "Gmsh.y" /* yacc.c:1652  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 13787 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 575:
#line 6118 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13799 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 576:
#line 6126 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 13810 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 577:
#line 6133 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13822 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 578:
#line 6142 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].c), 2);
    }
#line 13830 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 579:
#line 6146 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].c), 2);
    }
#line 13838 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 580:
#line 6150 "Gmsh.y" /* yacc.c:1652  */
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
#line 13857 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 581:
#line 6165 "Gmsh.y" /* yacc.c:1652  */
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
#line 13875 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 582:
#line 6179 "Gmsh.y" /* yacc.c:1652  */
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
#line 13893 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 583:
#line 6193 "Gmsh.y" /* yacc.c:1652  */
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
#line 13909 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 584:
#line 6205 "Gmsh.y" /* yacc.c:1652  */
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
#line 13929 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 585:
#line 6221 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13942 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 586:
#line 6230 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13955 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 587:
#line 6239 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13969 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 588:
#line 6249 "Gmsh.y" /* yacc.c:1652  */
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
#line 13984 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 589:
#line 6260 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-5].c);
      std::string out = in.substr((int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c));
    }
#line 13996 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 590:
#line 6268 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-3].c);
      std::string out = in.substr((int)(yyvsp[-1].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-3].c));
    }
#line 14008 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 591:
#line 6276 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 14016 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 592:
#line 6280 "Gmsh.y" /* yacc.c:1652  */
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
#line 14039 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 593:
#line 6299 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 14050 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 594:
#line 6306 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 14060 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 595:
#line 6312 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 14071 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 596:
#line 6319 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 14082 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 597:
#line 6326 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 14088 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 598:
#line 6328 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 14100 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 599:
#line 6336 "Gmsh.y" /* yacc.c:1652  */
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
#line 14125 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 600:
#line 6360 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[0].d); }
#line 14131 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 601:
#line 6362 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = (yyvsp[-3].c); Free((yyvsp[-3].c)); (yyval.d) = (yyvsp[0].d); }
#line 14137 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 602:
#line 6368 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 14143 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 603:
#line 6373 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 604:
#line 6375 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14155 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 605:
#line 6380 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 14161 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 606:
#line 6385 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 14170 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 607:
#line 6390 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14176 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 608:
#line 6392 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 14184 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 609:
#line 6396 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	char* c;
	List_Read((yyvsp[0].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[0].l));
    }
#line 14197 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 610:
#line 6408 "Gmsh.y" /* yacc.c:1652  */
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
#line 14215 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 611:
#line 6422 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14223 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 612:
#line 6426 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14231 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 613:
#line 6433 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 14243 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 614:
#line 6441 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 14255 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 615:
#line 6449 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-5].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-5].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-5].c));
    }
#line 14267 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 616:
#line 6460 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14273 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 617:
#line 6462 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14279 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 618:
#line 6465 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 14285 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;


#line 14289 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6468 "Gmsh.y" /* yacc.c:1918  */


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
