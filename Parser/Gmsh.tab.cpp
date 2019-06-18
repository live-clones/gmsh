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
    tRotate = 396,
    tTranslate = 397,
    tSymmetry = 398,
    tDilate = 399,
    tExtrude = 400,
    tLevelset = 401,
    tAffine = 402,
    tBooleanUnion = 403,
    tBooleanIntersection = 404,
    tBooleanDifference = 405,
    tBooleanSection = 406,
    tBooleanFragments = 407,
    tThickSolid = 408,
    tRecombine = 409,
    tSmoother = 410,
    tSplit = 411,
    tDelete = 412,
    tCoherence = 413,
    tIntersect = 414,
    tMeshAlgorithm = 415,
    tReverseMesh = 416,
    tLayers = 417,
    tScaleLast = 418,
    tHole = 419,
    tAlias = 420,
    tAliasWithOptions = 421,
    tCopyOptions = 422,
    tQuadTriAddVerts = 423,
    tQuadTriNoNewVerts = 424,
    tRecombLaterals = 425,
    tTransfQuadTri = 426,
    tText2D = 427,
    tText3D = 428,
    tInterpolationScheme = 429,
    tTime = 430,
    tCombine = 431,
    tBSpline = 432,
    tBezier = 433,
    tNurbs = 434,
    tNurbsOrder = 435,
    tNurbsKnots = 436,
    tColor = 437,
    tColorTable = 438,
    tFor = 439,
    tIn = 440,
    tEndFor = 441,
    tIf = 442,
    tElseIf = 443,
    tElse = 444,
    tEndIf = 445,
    tExit = 446,
    tAbort = 447,
    tField = 448,
    tReturn = 449,
    tCall = 450,
    tSlide = 451,
    tMacro = 452,
    tShow = 453,
    tHide = 454,
    tGetValue = 455,
    tGetStringValue = 456,
    tGetEnv = 457,
    tGetString = 458,
    tGetNumber = 459,
    tUnique = 460,
    tHomology = 461,
    tCohomology = 462,
    tBetti = 463,
    tExists = 464,
    tFileExists = 465,
    tGetForced = 466,
    tGetForcedStr = 467,
    tGMSH_MAJOR_VERSION = 468,
    tGMSH_MINOR_VERSION = 469,
    tGMSH_PATCH_VERSION = 470,
    tGmshExecutableName = 471,
    tSetPartition = 472,
    tNameToString = 473,
    tStringToName = 474,
    tAFFECTPLUS = 475,
    tAFFECTMINUS = 476,
    tAFFECTTIMES = 477,
    tAFFECTDIVIDE = 478,
    tOR = 479,
    tAND = 480,
    tEQUAL = 481,
    tNOTEQUAL = 482,
    tLESSOREQUAL = 483,
    tGREATEROREQUAL = 484,
    tLESSLESS = 485,
    tGREATERGREATER = 486,
    tPLUSPLUS = 487,
    tMINUSMINUS = 488,
    UNARYPREC = 489
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

#line 532 "Gmsh.tab.cpp" /* yacc.c:352  */
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
#define YYLAST   17096

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  257
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  614
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2199

#define YYUNDEFTOK  2
#define YYMAXUTOK   489

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
       2,     2,     2,   242,     2,   254,     2,   239,   241,     2,
     247,   248,   237,   235,   256,   236,   253,   238,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     229,     2,   231,   224,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   249,     2,   250,   246,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   251,   240,   252,   255,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   225,
     226,   227,   228,   230,   232,   233,   234,   243,   244,   245
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   269,   269,   270,   275,   277,   281,   282,   283,   284,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   322,   326,   333,   338,
     343,   357,   370,   383,   411,   425,   438,   451,   470,   475,
     476,   477,   478,   479,   483,   485,   490,   492,   498,   602,
     497,   620,   627,   638,   637,   655,   662,   673,   672,   689,
     706,   729,   728,   742,   743,   744,   745,   746,   750,   751,
     757,   757,   758,   758,   764,   765,   766,   767,   772,   778,
     840,   855,   884,   894,   899,   907,   912,   920,   929,   934,
     946,   963,   969,   978,   996,  1014,  1023,  1035,  1040,  1048,
    1068,  1091,  1111,  1119,  1126,  1133,  1155,  1178,  1216,  1237,
    1249,  1263,  1263,  1265,  1267,  1276,  1286,  1285,  1306,  1305,
    1323,  1333,  1332,  1346,  1348,  1356,  1362,  1367,  1394,  1396,
    1399,  1401,  1405,  1406,  1410,  1422,  1435,  1450,  1459,  1472,
    1474,  1478,  1479,  1484,  1492,  1501,  1509,  1523,  1541,  1545,
    1552,  1561,  1564,  1570,  1574,  1586,  1589,  1596,  1619,  1635,
    1651,  1688,  1724,  1740,  1756,  1788,  1804,  1821,  1837,  1887,
    1905,  1911,  1917,  1924,  1955,  1970,  1992,  2015,  2038,  2061,
    2085,  2109,  2133,  2159,  2176,  2192,  2210,  2228,  2235,  2244,
    2243,  2273,  2275,  2277,  2279,  2281,  2289,  2291,  2293,  2295,
    2303,  2305,  2307,  2315,  2317,  2319,  2321,  2331,  2347,  2363,
    2379,  2395,  2411,  2428,  2465,  2487,  2511,  2512,  2517,  2520,
    2524,  2541,  2561,  2581,  2600,  2627,  2646,  2667,  2682,  2698,
    2716,  2767,  2788,  2810,  2833,  2938,  2954,  2989,  3011,  3033,
    3045,  3051,  3066,  3094,  3106,  3115,  3122,  3134,  3154,  3158,
    3163,  3167,  3172,  3179,  3186,  3193,  3205,  3278,  3296,  3321,
    3336,  3369,  3381,  3405,  3409,  3414,  3421,  3426,  3436,  3441,
    3447,  3455,  3459,  3463,  3467,  3471,  3475,  3484,  3548,  3564,
    3581,  3598,  3620,  3642,  3677,  3685,  3693,  3699,  3706,  3713,
    3733,  3759,  3771,  3782,  3800,  3818,  3837,  3836,  3861,  3860,
    3887,  3886,  3911,  3910,  3933,  3949,  3966,  3983,  4006,  4034,
    4037,  4043,  4055,  4075,  4079,  4083,  4087,  4091,  4095,  4099,
    4103,  4112,  4125,  4126,  4127,  4128,  4129,  4133,  4134,  4135,
    4136,  4137,  4140,  4164,  4183,  4206,  4209,  4225,  4228,  4245,
    4248,  4254,  4257,  4264,  4267,  4274,  4296,  4337,  4381,  4420,
    4445,  4457,  4469,  4481,  4493,  4502,  4532,  4558,  4584,  4616,
    4643,  4669,  4695,  4721,  4747,  4769,  4780,  4828,  4882,  4897,
    4909,  4920,  4927,  4942,  4956,  4957,  4958,  4962,  4968,  4980,
    4998,  5026,  5027,  5028,  5029,  5030,  5031,  5032,  5033,  5034,
    5041,  5042,  5043,  5044,  5045,  5046,  5047,  5048,  5049,  5050,
    5051,  5052,  5053,  5054,  5055,  5056,  5057,  5058,  5059,  5060,
    5061,  5062,  5063,  5064,  5065,  5066,  5067,  5068,  5069,  5070,
    5071,  5072,  5073,  5074,  5075,  5076,  5077,  5078,  5087,  5088,
    5089,  5090,  5091,  5092,  5093,  5094,  5095,  5096,  5097,  5102,
    5101,  5109,  5111,  5116,  5121,  5125,  5130,  5135,  5139,  5143,
    5147,  5151,  5155,  5159,  5165,  5180,  5184,  5190,  5195,  5214,
    5234,  5265,  5269,  5273,  5277,  5281,  5285,  5289,  5294,  5304,
    5314,  5319,  5330,  5339,  5344,  5349,  5377,  5378,  5384,  5385,
    5391,  5390,  5413,  5415,  5420,  5429,  5431,  5437,  5438,  5443,
    5447,  5451,  5455,  5459,  5466,  5470,  5474,  5478,  5485,  5490,
    5497,  5502,  5506,  5511,  5515,  5523,  5534,  5538,  5542,  5556,
    5564,  5572,  5579,  5589,  5612,  5617,  5623,  5628,  5634,  5645,
    5651,  5657,  5663,  5675,  5689,  5699,  5709,  5719,  5731,  5735,
    5740,  5752,  5756,  5760,  5764,  5782,  5790,  5798,  5827,  5837,
    5853,  5864,  5869,  5873,  5877,  5889,  5893,  5905,  5922,  5932,
    5936,  5951,  5956,  5963,  5967,  5972,  5986,  6002,  6006,  6010,
    6014,  6018,  6026,  6032,  6041,  6045,  6049,  6057,  6063,  6069,
    6073,  6081,  6089,  6096,  6105,  6109,  6113,  6128,  6142,  6156,
    6168,  6184,  6193,  6202,  6212,  6223,  6231,  6239,  6243,  6262,
    6269,  6275,  6282,  6290,  6289,  6299,  6323,  6325,  6331,  6336,
    6338,  6343,  6348,  6353,  6355,  6359,  6371,  6385,  6389,  6396,
    6404,  6412,  6423,  6425,  6428
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
  "tRecursive", "tRotate", "tTranslate", "tSymmetry", "tDilate",
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
  "Shape", "$@9", "GeoEntity", "GeoEntity123", "GeoEntity12",
  "GeoEntity02", "Transform", "MultipleShape", "ListOfShapes", "LevelSet",
  "Delete", "Colorify", "SetPartition", "Visibility", "Command", "Slide",
  "Loop", "Extrude", "$@10", "$@11", "$@12", "$@13", "ExtrudeParameters",
  "ExtrudeParameter", "BooleanOperator", "BooleanOption", "Boolean",
  "BooleanShape", "TransfiniteType", "TransfiniteArrangement",
  "TransfiniteCorners", "RecombineAngle", "PeriodicTransform",
  "Constraints", "Coherence", "HomologyCommand", "Homology", "FExpr",
  "FExpr_Single", "$@14", "GetForced_Default", "GetForcedStr_Default",
  "DefineStruct", "$@15", "Struct_FullName", "tSTRING_Member", "Append",
  "AppendOrNot", "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble",
  "ListOfDouble", "ListOfDoubleOrAll", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "$@16",
  "NameStruct_Arg", "Str_BracedRecursiveListOfStringExprVar",
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
     475,   476,   477,   478,    63,   479,   480,   481,   482,    60,
     483,    62,   484,   485,   486,    43,    45,    42,    47,    37,
     124,    38,    33,   487,   488,   489,    94,    40,    41,    91,
      93,   123,   125,    46,    35,   126,    44
};
# endif

#define YYPACT_NINF -1863

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1863)))

#define YYTABLE_NINF -562

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   12559,    54,   104, 12718, -1863, -1863,   127,   120,   133,    14,
      40,     4,   308,   318,   325,   331,    60,   346,   358,    91,
     370,   390,   161,   180,    26,   -69,   160,   -69,   193,   256,
     282,    31,   295,   314,    32,   337,   416,   426,   438,   444,
     469,   475,   512,   527,   547,   211,   399,   465,   568,   342,
     501,   697,   599,  7118,   622,   511,   576,   785,   -42,   364,
     518,   422,   146,   659,   812,   -99,   673,  -142,  -142,   684,
     375,    66,   695, -1863, -1863, -1863, -1863, -1863,   700,   393,
     841,   848,    25,    48,   849,   847,   138,   965,   966,   967,
    6138,   969,   727,   728,   729,    23,    33, -1863,   739,   744,
   -1863, -1863,   986,   990,   748, -1863, 12954,   751, 13014,    13,
      37, -1863, -1863, -1863, 11690,   750, -1863, -1863, -1863, -1863,
   -1863,   749, -1863, -1863, -1863, -1863, -1863, -1863, -1863, -1863,
   -1863, -1863,   -68, -1863, -1863, -1863, -1863,    58, -1863,   995,
     747,  5891,    69,   753,   999, 11690, 12894, 12894, -1863, 11690,
   -1863, -1863, -1863, -1863, 12894, -1863, -1863, 11690, -1863, -1863,
   -1863, -1863,   752,   761,  1000, -1863, -1863, 13072,   763,   764,
     765,   767,    26, 11690, 11690, 11690,   768, 11690, 11690, 11690,
     769, 11690, 11690, 11690, 11690, 11690, 11690, 11690, 12894, 11690,
   11690, 11690, 11690,  6138,   770, -1863,  9803, -1863, -1863, -1863,
     771,  6138,  7363, 12894, -1863, -1863, -1863, -1863, -1863,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   425,   -69,   -69,   -69,   -69,   -69,   772,   -69,
     -69,   773,   518,   422,   422, -1863, -1863, -1863,   -69,   -69,
      42,   836,   839,   840,   776,  7363,   903,   518,   518,   781,
     -69,   -69,   783,   784,   786, -1863, -1863, -1863, 11690,  7608,
   11690, 11690,  7853,    26,   850,    43, -1863, -1863,   787, -1863,
    5317, -1863, -1863, -1863, -1863, -1863,   110, 11690,  9803,  9803,
     789,   790,  8098,  6138,  6138,  6138, -1863, -1863, -1863, -1863,
   -1863, -1863, -1863, -1863,   792,  8343,   793,  2256,  1028,  7363,
     794,    23,   795,   796,  -142,  -142,  -142, 11690, 11690,  -109,
   -1863,   176,  -142,  4694,   352,   132,   802,   804,   806,   807,
     811,   813,   814,  9803, 11690,  6138,  6138,  6138,   815,    22,
    1034,   810, -1863,  1057,  1058, -1863,   816,   817,   818, -1863,
   -1863,   819,  6138,   822,   824,   826, -1863, 11690,  6383, -1863,
    1070,  1071, 11690, 11690, 11690,   515, 11690,   827, -1863,   894,
   11690, 11690, 11690, -1863, -1863, 11690, -1863,   -69,   -69,   -69,
     833,   834,   835,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
   -1863,   -69, -1863, -1863, -1863,   -69,   -69,   837,   838,   -69,
     843, -1863,   845,  1077,  1080,   857, -1863, -1863,  1081,  1098,
    1103,  1102,   -69, 11690, 10667,   137, 12894,  9803, 11690, -1863,
   -1863,  7363,  7363, -1863,   860, 13072,   518,  1105, -1863, -1863,
   -1863, -1863, -1863, -1863, 11690, 11690,    47,  7363,  1107,   377,
     863,  2347,   864,  1110,    92,   866, -1863,   867, 13206, 11690,
   -1863,  2389,  -170, -1863,    68,  -138,  7544, -1863,   -59, -1863,
     140,  7789,  -119,   -29,  1026, -1863,    26,   868, 11690, 11690,
   11690, 11690,   888, 15225, 15250, 15275, 11690, 15300, 15325, 15350,
   11690, 15375, 15400, 15425, 15450, 15475, 15500, 15525,   872, 15550,
   15575, 15600,  5127,  1115, 11690,  9803,  5578, -1863,   136, 11690,
    1117,  1143,   904, 11690, 11690, 11690, 11690, 11690, 11690, 11690,
   11690, 11690, 11690, 11690, 11690, 11690, 11690, 11690, 11690,  9803,
   11690, 11690, 11690, 11690, 11690, 11690,  9803,  9803,   899, 11690,
   11690, 12894, 11690, 12894,  7363, 12894, 12894, 12894,   900,   905,
     906, 11690,    34, -1863, 10470, 11690,  7363,  6138,  7363, 12894,
   12894,  9803,    26, 13072,    26,   907,  9803,   907, -1863,   907,
   15625, -1863,   190,   908,    76,  1091, -1863,  1150, 11690, 11690,
   11690, 11690, 11690, 11690, 11690, 11690, 11690, 11690, 11690, 11690,
   11690, 11690,  8588, 11690, 11690, 11690, 11690, 11690,    26, 11690,
   11690,  1155, -1863,   450, 15650,   199,   344, 11690, 11690, 11690,
   -1863,  1153,  1156,  1156,   917, 11690, 11690,  1159,  9803,  9803,
   10996,   918,  1161, -1863,   919, -1863, -1863,  -167, -1863, -1863,
    8034,  8279,  -142,  -142,    69,    69,  -161,  4694,  4694, 11690,
    1661,  -100, -1863, 11690, 11690, 11690, 11690, 11690, 11690, 11690,
   11690, 11690,   360, 15675,  1164,  1162,  1165, 11690,  1167, 11690,
   -1863, -1863, 11690,  4179, -1863, -1863,  9803,  9803,  9803, 11690,
    1168, 11690, 11690, 11690, 15700,   924, -1863, -1863, 15725, 15750,
   15775,   996,  8524, -1863,   926,  5812, 15800, 15825, 14820, 12894,
   12894, 12894, 12894, 12894, 12894, 12894, 12894, 12894, 11690, 12894,
   12894, 12894, 12894,    18, 13072, 12894, 12894, 12894,    26,    26,
   -1863, -1863,  9803, -1863,   928,  5193, -1863,   929, 11718, 11690,
     907, 11690, -1863,    26, 11690, 11690,  1155,   932,   392, 15850,
   13078,   935,   395, 11690,  1178,   937,  7363, 15875, 14847,   177,
     936,  1183,  1185, -1863, -1863, -1863,  9803,   215, 11690, -1863,
   -1863, -1863,    26, 11690, 11690,  1155,   943, -1863,   946,   -38,
     518,   422,   518, -1863,   945, 13895, -1863,   135,  9803,    26,
   11690, 11690,  1193,  1192,  9803, 11690,  1198, 12894,    26, 10710,
    1193, 11690,  1199, -1863,    26,  1200, 12894, 11690,   951,   958,
   -1863, 11690,  8769,  9009,  9249,  9494, 13072,  1201,  1202,  1203,
   15900,  1204,  1205,  1206, 15925,  1207,  1208,  1209,  1211,  1212,
    1213,  1215, -1863,  1216,  1218,  1222, -1863, 11690, 15950,  9803,
     979,  9803, 13924, -1863, -1863,  1225, 14793, 14793, 14793, 14793,
   14793, 14793, 14793, 14793, 14793, 14793, 14793,  9739, 14793, 14793,
   14793, 14793,  1869,   657, 14793, 14793, 14793, 10074, 10410, 10741,
    5578,   984,   983,   124,  9803, 11070, 11318,   657, 11399,   657,
     978,   980,   981,    -9,  9803, 11690, 11690, 16850, -1863,   657,
     989, 13953, 13982, -1863, -1863,   982,    90,   657,  -131,   987,
     396,   405,  1235, -1863,  1193,   657,   992,   993,  5837,  6074,
     726,  1285,  1252,  1252,   400,   400,   400,   400,   400,   400,
     466,   466,  9803,  -174, -1863,  -174,  -174,   907,   907,   907,
     991, 15975, 14874,   173,   683,  9803, -1863,  1239,   997,   998,
   16000, 16025, 16050, 11690,  7363,  1246,  1245, 10379, 14011, 16075,
   -1863,   414,   419,  9803,  1004, -1863, 11815, -1863, 11922, 11989,
    -142, 11690, 11690, -1863, -1863,  1001,  1006,  4694,  2724,  1123,
     -39,  -142, 12046, 16100, 14040, 16125, 16150, 16175, 16200, 16225,
   16250, 16275,  1010,  1255, 11690,  1257, -1863, 11690, 16300, -1863,
   14901, 12113, 14928, -1863,   463,   493,   498, 14069, -1863, 14955,
   14982, 11558, -1863, -1863,  1259,  1260,  1261,  1011, 11690, 12170,
   11690, 11690, -1863, -1863,    50,   252,   327,   252,  1021,  1023,
    1016,   657,   657,  1017, 11749,   657,   657,   657,   657, 11690,
     657,  1243, -1863,  1019,  1030,   461,   504,  1031,   543, -1863,
   -1863, -1863, -1863, 14793,  -174, 12237,  1027,   689,  1029,  1097,
    1269,  1129, 10799,  1035,  1038,  1284,  7363, 14098, -1863, 11690,
    1287,   181,    75, 13072, 11690,  1288,  1291,    24, -1863,   544,
    1250,  1251,  7363, 14127,    29,  1045, 16325, 15009,   -83, 11690,
   11690,  1053,  1051,  1059,  1054,  8833, -1863, -1863, -1863, -1863,
   12894,   100,  1055, 16350, 15036, -1863,  1062, -1863,   209, 12352,
   -1863, -1863, -1863,  1061, -1863,  1063, 13012, -1863,    73, -1863,
   -1863, 16850, -1863,  1300, 14793, 11690, 11690, 11690, 11690,   657,
    -142,  7363,  7363,  1304,  7363,  7363,  7363,  1305,  7363,  7363,
    7363,  7363,  7363,  7363,  7363,  7363,  7363,  7363,  2938,  1308,
    9803,  5578, -1863, -1863, -1863, -1863, -1863, -1863, -1863, -1863,
   -1863, -1863, -1863, -1863, -1863, -1863, 11690, -1863, -1863, -1863,
   -1863, -1863, -1863, -1863, -1863, -1863, 11690, 11690, 11690, -1863,
   -1863, -1863,   545, 11690, 11690, -1863, 11690, -1863,  7363, 12894,
   12894, -1863,   551, 14156, 14185,  1060, -1863, -1863, -1863,  1132,
   11690, 11690, -1863, -1863, -1863,  1193, -1863,  1193, 11690, 11690,
    1072, -1863,  7363,   -69, -1863, 11690, -1863, 11690, 11690,   553,
    1193,   173,   -72, -1863, 11690, 11690,   657,   558,  7363,  9803,
    9803,  1314,  1316,  1318,  4837, -1863, -1863,  1320, -1863,  1079,
   16850,  1073, -1863,  1321,  1323,  1325,   559,  1330, -1863, 12294,
   -1863, -1863,   -96, 13136, 13169, -1863, -1863, 14214,  -145,  1220,
    1333, 11039,  1087,  1335,  1092,    38,    39,   321, -1863,   -74,
   -1863,   -39,  1336,  1338,  1339,  1341,  1342,  1343,  1344,  1345,
    1346,    69,  7363, 16850, -1863,  3275,  1104,  1348, -1863,  1350,
    1351,  1262,  1353, -1863,  1356,  1358, 11690,  7363,  7363,  7363,
    1362, 13202, -1863,  6319,  1982,    51,  1363, -1863,  9803, -1863,
   -1863, -1863, -1863, 12894, -1863, -1863, 11690, 12894, -1863, -1863,
   -1863, -1863, 16850, -1863,  1088,  1112, 12894, -1863, 12894, -1863,
    1193, 12894,  1121, -1863,  1114, -1863,  1193, 11690, 11690,  1120,
     518,  1122, 11128, -1863,  3330,  1124,  7363, -1863,  1125, -1863,
   14243, -1863, -1863, 11690,  1366,    49, 11690,  1368,  1372,  3471,
   -1863,  1374,    23,  1373,  1133,   657,   -69,   -69,  1377, -1863,
   -1863,  1137,  1138,  1135, -1863,  1381, -1863, -1863, -1863, -1863,
   -1863,  1193,   164,  2317, 11690, 15063, 16375, 11690,  9073, 11690,
    9803,  1139,   561,  1383,   141,  1193, -1863,  1140, 11690,  1386,
   11690,  1193, 11368, 11690,  4967,   657,  5380,  1144,  1145, -1863,
    1389, 16400, 16425, 16450, 16475,  1390,   115,  1270,  1270,  7363,
    1393,  1396,  1397,  7363,   -88,  1400,  1401,  1402,  1403,  1404,
    1405,  1406,  1407,  1408, -1863,  1410,   564, 14793, 14793, 14793,
   14793,   657, 13235, 13268, 13301,  1169,   657,   657, -1863, -1863,
   -1863,  1300,   657, 16500, 14793,  1171,   -97, 16850, 14793, -1863,
    1414,   657, 13334, 16850, 16850, -1863,   692, -1863,  1417, -1863,
   16525, 15090, -1863,   657,  1416,   566,   567,  7363,  7363,  7363,
    1419,  1418, -1863,   227, 11690,  7363,  1174,  1175,  1420,   261,
   -1863, 11690, 11690, 11690,  1179,  1180,  1181,  1184, -1863,  3795,
    7363, -1863, 11690, -1863,  1423, -1863,  1431, -1863, -1863,  4694,
     350,  6628, -1863,  1187,  1188,  1189,  1190,  1194,  1195,  9313,
    1191,  1438, -1863,  9803, -1863, -1863, -1863,  1210, 11690, -1863,
   -1863, 15117,  1443,  1444,  1271, -1863, 11690, 11690, 11690, -1863,
    1447,  1448,  1449,   855,   470,  1214,  6564,  1217, 11690,    27,
     657,  1219,   657,  1221, -1863, -1863, 13072,   693, 11690,  1223,
   -1863, -1863,  3823, -1863, -1863,  1240,  1450, -1863,  3857, -1863,
     210,  1226,  1451,  4228, -1863, -1863, -1863,    23, -1863,   572,
   -1863, 11690,   227,  3689,  3272, -1863,  1224, 11690, 11690,  7363,
    1227, -1863,   303,  1455,  1454, 16550,  1456,  1235, 16575,  1247,
     574, 16600,   580,  1457,  1458, -1863, -1863, 12894,  1228,  1461,
   16625, -1863, 13367,  1248, -1863, 14272,  5639, 16850, -1863,  1459,
     -69,  7853, -1863, -1863, -1863, -1863,  1300, -1863,  1463,  1466,
    1491,  1494, -1863, -1863,  -142,  1496,  1497,  1498, -1863, -1863,
   -1863,  1499,   -35,  1409,  1500, -1863, -1863, -1863, -1863, -1863,
   -1863, -1863, -1863, -1863,  1503,  1258, -1863, -1863, -1863, -1863,
   -1863, 11690, 11690, 11690, -1863, -1863, -1863,  1145, -1863, -1863,
   -1863, -1863, 11690,  1279,  1272, -1863, -1863, 11690, 11690, 11690,
     657,   173, -1863, -1863, -1863, -1863,  1278,  1281,  1527,   -88,
    1529, 11690, -1863,  7363, 16850,   939,  9803,  9803, 11690, -1863,
   10379, 14301, 16650,  6809,    69,    69, 11690, 11690, -1863,   552,
    1280, 16675, -1863, -1863, 14330,   -30, -1863,  1531,  1532,  7363,
    -142,  -142,  -142,  -142,  -142,  6873,  1533, -1863, -1863,   586,
   11690,  4262,  1536, -1863, -1863,  7363,  7054,   902, 16700, -1863,
   -1863, -1863, -1863, 10043, -1863, 12894, 11690, -1863, 12894, 16850,
   10134, 13072,  1289, -1863, -1863, -1863, -1863,  1295,  1292, 11690,
   11690, 14359, 11690, 13078, -1863, 13078,  7363, -1863, -1863, 13072,
   11690,  1538,  1543,    24, -1863,  1544, -1863,    23, 15144,  7363,
   12894,  1545,   657, -1863,  1293,   657, 11690, 13400, 13433,   587,
   -1863, 11690, 11690,   500, -1863,  1301, -1863,  1318,  1547,  1548,
    1321,  1549, -1863, -1863,  1550, 11690, -1863, -1863, 11690, 11450,
    1551, -1863, -1863,  1307,  3272,   588,  3363,  1552, -1863, -1863,
   -1863, -1863, -1863,   275, -1863, -1863, -1863, -1863,  1309,  1310,
    1311, -1863,  1558,  7363, 14793, 14793, 13466, 14793, -1863,  1317,
   13499, 16725, 15171, -1863, -1863,  9803,  9803, -1863,  1560, -1863,
   16850,  1561,  1319, -1863,   593,   601, 14765,  4291,  1562,  1326,
   -1863, -1863, 11690,  1322,  1324, 14388, 15198,  1563,  7363,  1565,
    1328, 11690, -1863, -1863,   602,   -21,   -16,   170,   187,   224,
    9558,   235, -1863,  1574, 14417, -1863, -1863,  1411, -1863, 11690,
   11690, -1863, -1863,  9803,  4562,  1575,  1334, 14793,   657, 16850,
   -1863, -1863, -1863, -1863,    27, -1863, 13072, -1863, 14446,  1331,
    1340,  1347,  1579,  4608, -1863,  1580,  1582, -1863, -1863,  1337,
    1587,   604, -1863,  1591,  1594,   226, 16850, 11690, 11690,  1352,
    7363,   607, 16850, 16750, -1863, -1863, -1863, -1863, 16775, 13532,
   -1863, -1863,  1060,  1112,  7363,   657, -1863, 11690, 13072,    26,
    9803,  9803, 11690,  1595,   612, -1863, -1863, 11690,  1272, -1863,
   11690, -1863, -1863,   615,   618, -1863, -1863,  7363,   611,   625,
    9803, -1863, -1863,    69,  7299, -1863, -1863, -1863,  1596, -1863,
    1354,  7363, -1863, 14475,  1598,  9803,  -142,  -142,  -142,  -142,
    -142, -1863, -1863, 11690, 14504, 14533,   620, -1863, -1863, -1863,
   -1863, -1863, -1863,  1357,  1601,  1359, -1863,  1602, -1863, -1863,
      23, -1863,  1426, -1863, -1863, -1863, -1863, -1863, 11690, 13565,
   13598,  7363, -1863,  1605, 11690,  1364, -1863, 11690,  1370,  1371,
   -1863, -1863,  5040, -1863,  1367,   623,   626, 14562, -1863,  1375,
   13631,  1376, 13664, -1863,  1378,   628,  1379,  -142,  7363,  1619,
    1380,  -142,  1621,   629,  1382, -1863, 11690, -1863,  1622,  1495,
   12361,  1384, -1863,   631,   237,   241,   243,   259,   270,  4881,
   -1863, -1863,  1627,  1630, -1863, -1863, -1863,  1631, -1863,  1391,
   16850, 11690, 11690,   634, -1863, 16850, 13697, -1863, -1863,  1060,
   13072,  1392, -1863, -1863, -1863, 11690, 11690, -1863, 11690,  9803,
    1637,  -142,   126, -1863, -1863,  -142,   159, -1863,  1638, -1863,
   14591, -1863, 11690, -1863,   -39, -1863,  1641,  9803,  9803,  9803,
    9803,  9558, -1863, -1863, -1863, 13078, -1863, 11690, 16800, 13730,
      53, 11690,  1399, -1863, -1863, 13763, 13796, 13829,   642, -1863,
     285, -1863,   301, -1863, -1863, -1863,  4906,   445, 12418, -1863,
     643,   644,   645,   652,   330,   661,  1413,   662, -1863, 11690,
   -1863,  7363, 14620, -1863, 11690, 11690, 11690, -1863,  -142,  -142,
   -1863, -1863, -1863,   -39,  1642,  1643,  1646,  1649,  9803,  1650,
    1651,  1652,  1412, 16825,   663,  1653, 14649, 14793, 13862,   334,
     336,   496, -1863, -1863, -1863, -1863,   669, -1863, -1863, -1863,
   12894, -1863,  1415, -1863,  1654, -1863, 11690, 11690, 11690, -1863,
    1656,   670, -1863,  1421,  7363, -1863, 14678, 14707, 14736, -1863,
    1663, 12894, 12894,   675, -1863,  1667,  1671, -1863, -1863,   677,
   -1863,  1672, -1863, -1863,  1673, 12894, -1863, -1863, -1863
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,     0,
       0,   192,     0,     0,   193,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,   323,   324,   325,   326,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   283,     0,     0,
     291,   292,     0,     0,     0,   286,     0,     0,     0,     0,
       0,   374,   375,   376,     0,     0,     5,     6,     7,     8,
      10,     0,    11,    24,    12,    13,    14,    15,    23,    22,
      21,    16,     0,    17,    18,    19,    20,     0,    25,     0,
     613,     0,   218,     0,     0,     0,     0,     0,   267,     0,
     269,   270,   265,   266,     0,   271,   273,     0,   274,   275,
     113,   123,   612,   487,   482,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,     0,   203,   204,   205,
       0,     0,     0,     0,   428,   429,   431,   432,   430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   436,   437,   438,     0,     0,
     191,   196,   197,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,   434,   435,     0,     0,
       0,     0,     0,     0,     0,     0,   524,   525,     0,   526,
     500,   381,   441,   444,   305,   501,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   192,   193,   194,
     189,   196,   197,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     489,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   612,
       0,     0,   218,     0,     0,   371,     0,     0,     0,   200,
     201,     0,     0,     0,     0,     0,   508,     0,     0,   506,
       0,     0,     0,     0,     0,   612,     0,     0,   547,     0,
       0,     0,     0,   263,   264,     0,   564,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     566,     0,   590,   568,   569,     0,     0,     0,     0,     0,
       0,   567,     0,     0,     0,     0,   284,   285,     0,   218,
       0,   218,     0,     0,     0,   482,     0,     0,     0,   218,
     377,     0,     0,    76,     0,    63,     0,     0,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,     0,     0,   553,   482,     0,   217,     0,   216,     0,
     170,     0,     0,   553,   554,     0,     0,   602,     0,   603,
     554,     0,   111,   111,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   541,   542,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   515,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,     0,   383,   509,   385,
       0,   502,     0,     0,   482,     0,   517,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,   458,     0,     0,     0,     0,     0,     0,     0,
     306,     0,   339,   339,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,     0,   218,   218,     0,   491,   490,
       0,     0,     0,     0,   218,   218,     0,     0,     0,     0,
     302,     0,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   341,     0,     0,     0,     0,     0,
     218,   244,     0,     0,   242,   372,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   349,   262,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   287,     0,   249,     0,     0,   251,     0,     0,     0,
     383,     0,   218,     0,     0,     0,     0,     0,     0,     0,
     327,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    72,    73,     0,     0,     0,   260,
      38,   256,     0,     0,     0,     0,     0,   213,     0,     0,
       0,     0,     0,   219,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,   485,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   333,     0,     0,     0,   195,     0,     0,     0,
       0,     0,     0,   367,   368,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   482,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   439,   457,     0,
       0,     0,     0,   518,   519,     0,     0,     0,     0,     0,
     476,     0,   382,   503,     0,     0,     0,     0,   511,     0,
     401,   400,   398,   399,   394,   396,   395,   397,   403,   402,
     387,   386,     0,   388,   510,   389,   392,   390,   391,   393,
     483,     0,     0,   484,   461,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,   337,     0,     0,     0,     0,
     370,     0,     0,     0,     0,   369,     0,   218,     0,     0,
       0,     0,     0,   493,   492,     0,     0,     0,     0,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,     0,     0,   243,
       0,     0,     0,   237,     0,     0,     0,     0,   366,     0,
       0,     0,   382,   507,     0,     0,     0,     0,     0,     0,
       0,     0,   289,   290,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   593,     0,     0,     0,   478,     0,     0,   248,
     252,   250,   254,     0,   388,     0,   483,   461,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,   382,     0,    63,     0,     0,     0,     0,    79,     0,
      63,    64,     0,     0,     0,   483,     0,     0,   461,     0,
       0,     0,   189,     0,     0,     0,   609,    28,    26,    27,
       0,     0,     0,     0,     0,   484,   557,    29,     0,     0,
     257,   604,   605,     0,   606,   557,     0,    74,   114,    75,
     124,   486,   488,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   543,   544,   206,     9,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   427,   414,     0,   416,   417,   418,
     419,   420,   540,   421,   422,   423,     0,     0,     0,   532,
     531,   530,     0,     0,     0,   537,     0,   473,     0,     0,
       0,   475,     0,     0,     0,   128,   456,   514,   513,   199,
       0,     0,   442,   539,   447,     0,   453,     0,     0,     0,
       0,   504,     0,     0,   454,     0,   516,     0,     0,     0,
       0,   446,   445,   468,    70,    71,     0,     0,     0,     0,
       0,     0,     0,   382,   335,   340,   338,     0,   348,     0,
     148,   149,   199,   382,     0,     0,     0,     0,   238,     0,
     253,   255,     0,     0,     0,   207,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   309,     0,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   218,     0,   342,   355,     0,     0,     0,   239,     0,
       0,     0,     0,   202,     0,     0,     0,     0,     0,     0,
       0,     0,   245,     0,     0,     0,     0,   580,     0,   587,
     576,   577,   578,     0,   592,   591,     0,     0,   581,   582,
     583,   589,   596,   595,     0,   139,     0,   570,     0,   572,
       0,     0,     0,   565,     0,   247,     0,     0,     0,     0,
       0,     0,     0,   328,     0,     0,     0,   378,     0,   610,
       0,   101,    63,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,   562,
      48,     0,     0,     0,    61,     0,    39,    40,    41,    42,
      43,     0,   446,   445,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   556,   555,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,   155,   155,     0,
       0,     0,     0,     0,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   521,   522,
     523,     0,     0,     0,     0,     0,   476,   477,     0,   449,
       0,     0,     0,   512,   404,   505,   462,   460,     0,   459,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   347,     0,     0,     0,     0,     0,     0,     0,
     246,     0,     0,     0,     0,     0,     0,     0,   314,     0,
       0,   313,     0,   316,     0,   318,     0,   303,   310,     0,
       0,     0,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   357,     0,   241,   240,   373,     0,     0,    35,
      36,     0,     0,     0,     0,   548,     0,     0,     0,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   478,   479,   574,     0,   462,     0,     0,
     218,   329,     0,   330,   218,     0,     0,   563,     0,    86,
       0,     0,     0,     0,    84,    91,    93,     0,   551,     0,
      99,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    34,   462,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    31,     0,   558,     0,
       0,    32,     0,   558,   607,     0,     0,   115,   120,     0,
       0,     0,   134,   137,   138,   481,     0,    77,     0,     0,
       0,     0,    78,   157,     0,     0,     0,     0,   158,   173,
     174,     0,     0,     0,     0,   159,   184,   175,   179,   180,
     176,   177,   178,   165,     0,     0,   415,   424,   425,   426,
     533,     0,     0,     0,   471,   472,   474,   129,   440,   470,
     443,   448,     0,     0,   476,   185,   455,     0,    70,    71,
       0,   467,   463,   465,   534,   181,     0,     0,     0,   151,
       0,     0,   346,     0,   150,     0,     0,     0,     0,   261,
       0,     0,     0,     0,   218,   218,     0,     0,   315,   500,
       0,     0,   317,   319,     0,     0,   297,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   212,   182,     0,
       0,     0,     0,   162,   163,     0,     0,     0,     0,   102,
     103,   104,   108,     0,   588,     0,     0,   586,     0,   597,
       0,     0,   140,   141,   594,   571,   573,     0,     0,     0,
       0,     0,     0,   327,   331,   327,     0,   379,    85,    63,
       0,     0,     0,     0,    83,     0,   549,     0,     0,     0,
       0,     0,     0,   600,   599,     0,     0,     0,     0,     0,
     498,     0,     0,   467,   258,   463,   259,     0,     0,     0,
       0,     0,   223,   220,     0,     0,   561,   559,     0,     0,
       0,   116,   121,     0,     0,     0,   541,   542,   133,   350,
     351,   352,   353,   156,   160,   161,   166,   183,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,   450,     0,
       0,     0,     0,   529,   469,     0,     0,   167,     0,   186,
     336,     0,     0,   187,     0,     0,     0,     0,     0,     0,
     497,   496,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   234,     0,     0,     0,     0,     0,     0,
       0,     0,   225,     0,     0,   354,    37,     0,   546,     0,
       0,   281,   280,     0,     0,     0,     0,     0,     0,   143,
     144,   147,   146,   145,     0,   575,     0,   611,     0,     0,
       0,     0,     0,     0,    96,     0,     0,    97,   552,     0,
       0,     0,    88,     0,     0,     0,    44,     0,     0,     0,
       0,     0,    46,     0,   224,   221,   222,    33,     0,     0,
     608,   272,   128,   139,     0,     0,   136,     0,     0,     0,
       0,     0,     0,     0,     0,   535,   536,     0,   476,   451,
       0,   464,   466,     0,     0,   169,   190,     0,   343,   343,
       0,   109,   110,   218,     0,   210,   211,   304,     0,   311,
       0,     0,   218,     0,     0,     0,     0,     0,     0,     0,
       0,   215,   214,     0,     0,     0,     0,   105,   106,   579,
     585,   584,   142,     0,     0,     0,   332,     0,    92,    94,
       0,   100,     0,    82,   601,    89,    90,    49,     0,     0,
       0,     0,   499,     0,     0,   464,   560,     0,     0,     0,
     118,   598,     0,   125,     0,     0,     0,     0,   172,     0,
       0,     0,     0,   307,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   495,     0,   321,     0,     0,
     298,     0,   226,     0,     0,     0,     0,     0,     0,     0,
     545,   282,     0,     0,   365,   218,   380,     0,   550,     0,
      45,     0,     0,     0,    62,    47,     0,   117,   122,   128,
       0,     0,   153,   154,   152,     0,     0,   452,     0,     0,
       0,     0,     0,   344,   358,     0,     0,   359,     0,   208,
       0,   312,     0,   294,     0,   218,     0,     0,     0,     0,
       0,     0,   164,   107,   278,   327,    98,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,     0,   188,
       0,   362,     0,   363,   364,   494,     0,     0,   300,   229,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
      59,     0,     0,   119,     0,     0,     0,   308,     0,     0,
     320,   299,   295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,   231,   232,   233,     0,   227,   334,    50,
       0,    57,     0,   268,     0,   538,     0,     0,     0,   301,
       0,     0,    51,     0,     0,   277,     0,     0,     0,   228,
       0,     0,     0,     0,   520,     0,     0,    54,    52,     0,
      55,     0,   360,   361,     0,     0,    60,    58,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1863, -1863, -1863, -1863,   326, -1863, -1863, -1863, -1863,  -406,
   -1863, -1863, -1863, -1863, -1863, -1863, -1863, -1863, -1863, -1863,
   -1863, -1863,  -705,  -140,  2497,  3826, -1863,  1230, -1863, -1863,
   -1863, -1863, -1863, -1863, -1862, -1863,   272,    98,  -218, -1863,
    -178, -1863,    41,   309,  1685, -1863,   298,   -49, -1863, -1863,
       6,  -609,  -303, -1863, -1863, -1863, -1863, -1863, -1863, -1863,
   -1863,  1686, -1863, -1863, -1863, -1863, -1224, -1214,  1688, -1700,
    1691, -1863, -1863, -1863,  1093, -1863,  -234, -1863, -1863, -1863,
   -1863,  2498, -1863, -1863, -1411,   184,  1695, -1863,    10,  -699,
   -1863, -1863,   -64, -1863, -1665,   870,  -182,  3023,    11,  -309,
     -34, -1863,    45,   -65, -1863, -1863,   -10,   157, -1654,  -146,
     940, -1863,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   116,  1060,   117,   118,  1044,  1885,  1891,
    1336,  1546,  2039,  2171,  1337,  2142,  2189,  1338,  2173,  1339,
    1340,  1550,   437,   592,   593,  1131,   119,   774,   462,  1902,
    2049,  1903,   463,  1775,  1412,  1367,  1368,  1369,  1510,  1712,
    1713,  1199,  1604,  1595,   753,   604,   274,   275,   352,   201,
     276,   447,   448,   123,   124,   125,   126,   127,   128,   129,
     130,   277,  1231,  2074,  2133,   940,  1227,  1228,   278,  1023,
     279,   134,  1441,  1197,   915,   955,  2009,   135,   136,   137,
     138,   280,   281,  1155,  1170,  1292,   282,   779,   283,   904,
     778,   465,   619,   320,  1749,   359,   360,   285,   562,   367,
    1323,  1539,   457,   453,  1285,  1000,  1584,  1742,  1743,   985,
     459,   140,   415
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     141,   438,   614,   319,   321,  1633,   324,  1470,   458,   122,
     148,   493,   305,  1468,  1834,   935,   936,  1017,   408,   500,
     630,   164,   162,  1869,  1034,  1870,   648,   365,   162,   339,
     162,  1710,  1042,  1330,   163,   176,   180,   369,   162,   653,
    1988,   403,   410,   407,  1463,  1465,  1048,   543,   566,  1602,
     286,   729,   344,  1530,   345,  1500,  1862,  1265,   310,  2120,
       4,   291,  1788,  1066,   420,   291,   585,   586,   622,   623,
     325,  1075,   587,   445,   622,   623,   443,   759,   757,   343,
    1364,  1789,  1312,   311,   292,   466,   758,   286,  1051,   930,
     622,   623,   368,   315,   316,   937,   162,  1603,  1220,   312,
     313,   742,   467,   404,     5,   317,   705,  1455,   708,   318,
     763,   601,   602,   603,   340,  1221,   720,  1164,   764,   588,
    1905,  1593,  1165,  1222,  1223,  1224,   622,   623,  1914,  1225,
    1226,   772,  2101,   588,   144,   622,   623,   773,   444,   622,
     623,  1057,   624,   454,   454,   346,   713,  1566,   446,   768,
     165,   460,   166,   644,   645,   646,   941,  1501,  1502,  1168,
    1451,   622,   623,   326,  1344,  2103,  1298,   327,  -557,   472,
     660,   432,   433,   328,   329,  1173,   330,   331,   165,   418,
     166,  1428,  1469,   419,  1033,   454,   442,  2092,  1312,   766,
     286,   452,   455,   286,   539,   540,   332,   767,   286,   286,
     454,  1331,  1332,  1333,  1334,   622,   623,   498,  1464,  1466,
      66,    67,    68,    69,   622,   623,    72,  1729,   341,   622,
     623,   775,  1040,  1799,  1711,    81,  1831,   773,    84,   730,
     731,  1531,  1532,   488,  1312,  1945,   145,   115,   349,  1151,
    1946,   350,   115,   115,   115,   115,   306,   767,   502,   307,
     617,   618,   286,   115,   351,   149,  1468,   168,   626,   631,
     169,   146,  2005,   170,   409,   171,   286,  1659,  1660,   286,
     564,   649,   999,   650,   366,  1322,   342,   143,   177,   181,
     370,  1335,   734,   563,   735,   286,   286,   147,   411,   286,
     286,   286,   286,   544,   567,   428,   429,   430,   431,   595,
     596,   121,   286,  1266,  2121,   421,   286,   154,   368,   422,
     926,   115,   928,   929,   150,   760,  2043,   761,   432,   433,
     165,   762,   166,   165,   151,   166,  1313,  1316,  1315,   942,
     286,   152,   286,   286,   286,   432,   433,   153,   734,   743,
     735,   744,   157,  -554,   642,   745,  1161,   961,  1354,   286,
     622,   623,   155,   432,   433,   286,   811,   589,   300,   590,
     724,   622,   623,   591,   156,   863,  1058,   432,   433,  1059,
     979,   589,  1058,   590,  1141,  1059,   158,   591,   142,   633,
     432,   433,   143,   634,   714,  2116,   715,   769,   810,   761,
     716,   853,   811,   770,   622,   623,   159,   428,   429,   430,
     431,   428,   429,   430,   431,   622,   623,   432,   433,  1015,
     160,   622,   623,   454,   286,  -556,   432,   433,   286,   286,
     432,   433,   622,   623,   432,   433,  1947,   625,   718,   161,
     428,   429,   430,   431,   286,  1041,   429,   430,   431,   440,
     173,   746,   873,  1948,   440,   440,   811,   428,   429,   430,
     431,   908,   440,   432,   433,   811,  2144,  1359,  1220,   622,
     623,   717,   192,   780,   293,   811,  1415,   294,  1416,   295,
     622,   623,   622,   623,  1977,  1221,   622,   623,   622,   623,
    1949,  1426,  1978,  1222,  1223,  1224,   440,  1220,   869,  1225,
    1226,  1950,   286,  2077,   622,   623,   335,  2078,   336,  2079,
     734,   440,   735,   174,  1221,   622,   623,  2001,   767,  2183,
     622,   623,  1222,  1223,  1224,  2080,   286,   193,  1225,  1226,
     622,   623,   301,   286,   843,   302,  2081,   303,   454,   175,
     454,   286,   454,   454,   460,   987,   622,   623,   304,   859,
     538,  2128,   178,   286,   286,   286,   454,   454,   286,   164,
    1752,   164,  1720,   286,  -558,   547,   548,  2129,   933,   934,
     568,   179,   868,   618,   870,   622,   623,   871,   194,   622,
     623,   622,   623,  1467,   195,   734,   847,   735,   849,   286,
     851,   852,  1220,  1268,   182,   900,  2138,   622,   623,  1035,
    2167,  1513,  2168,   196,   865,   866,   909,  1517,   197,  1221,
     811,   198,  1676,   632,   199,   286,   286,  1222,  1223,  1224,
     315,   316,   952,  1225,  1226,   296,   811,   200,   297,   921,
     922,   298,   317,   299,  1209,   734,   323,   735,   736,  1002,
     446,   446,  1480,  1220,    45,   580,   581,   711,   583,   584,
     585,   586,  1552,   165,  1019,   166,   587,  1025,   811,  1167,
    1221,  1026,  1168,   286,   286,   286,  1568,  1171,  1222,  1223,
    1224,   811,  1573,   183,  1225,  1226,  1204,   964,   965,   966,
     811,  1205,   526,   184,   527,   811,   460,   454,   460,   454,
     454,   454,   454,   454,   454,   185,   454,   454,   454,   454,
    1001,   186,   454,   454,   454,   164,  1007,  2131,   734,   286,
     735,   905,  1053,   711,   583,   584,   585,   586,  1006,   734,
    1016,   735,   587,  1008,   440,  1250,   187,  1288,   734,   811,
     735,  1089,   188,   286,   725,   986,   811,   988,   989,   990,
     991,   992,   993,   286,   995,   996,   997,   998,  1653,  1045,
    1003,  1004,  1005,   432,   433,  1251,   754,  1039,  2169,   811,
    1252,  -561,  2006,  2007,   811,   286,  1062,  1290,  2008,   189,
    1291,   286,   288,  1183,   460,  1073,  2010,  2011,   671,  1061,
     143,  1078,  2008,   454,   190,  1068,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   191,  1294,  1325,  1401,   587,   811,
     811,   811,   202,  1408,  1827,  1425,   286,   811,   286,   811,
    1433,  1448,  1071,  1564,   811,   811,  1615,   811,  1646,  1647,
     811,  1080,   811,   811,  1736,  1730,  1759,   289,  1737,   440,
     811,   440,  1761,   440,   440,   440,   811,  1739,  1843,  1889,
    1906,   286,   811,  1890,  1907,  1928,   203,   440,   440,   811,
    2107,   286,  1201,  1929,  1944,  1142,  1974,   811,  1890,  1983,
     767,  1702,  1703,  1984,  1999,  1152,  1212,  2003,  1890,   287,
    2004,   811,  2032,  1218,   811,  2052,   811,  1229,  2053,   811,
    2060,  2068,   811,  2076,  1890,   811,  2090,   811,   290,   286,
    1890,  1314,  1317,  1468,  2127,  2134,  2135,  2136,   811,   811,
     811,   811,   286,  1179,  2137,   734,   308,   735,   811,  2151,
    1850,   286,   309,  2139,  2141,  2162,  1187,   811,  1984,  1890,
     286,  2170,  2180,   284,   314,   811,  2181,  2191,   754,  2194,
    1184,  1890,  1185,  2195,  1206,   322,  1297,  1468,  1298,  1638,
    1719,  1639,  1720,  1812,   337,  1813,   333,   334,   338,   347,
     348,   754,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,  1318,   353,
     354,   355,   587,   361,   362,   363,   364,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   371,   440,   440,   440,
     440,   372,   373,   440,   440,   440,   374,   375,   405,   416,
     417,   423,   424,   754,   449,   450,   754,   143,   464,   466,
     468,   469,   470,  1538,   471,   476,   480,   494,   754,   534,
     537,  -192,   499,   286,  -193,  -194,  1376,   545,   549,   546,
     552,   553,   611,   554,  1324,   565,   597,   598,   419,   286,
     651,  1427,  1429,   605,   608,   613,   615,   616,  1052,   635,
    1054,   636,   286,   637,   638,  1823,  1824,   454,   639,   652,
     640,   641,   647,   654,   655,   440,  1352,   656,   657,   658,
     659,   661,   501,   662,   440,   663,   666,   667,   673,   674,
     682,   683,   684,   700,   695,   696,   701,   703,   286,   286,
     698,   286,   286,   286,   699,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,  1353,   704,   286,   702,   706,
     707,   723,   726,   733,   738,   740,   741,   142,   777,   747,
     802,  1396,   807,   813,   781,   284,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,   786,   286,   454,   454,   587,   814,
     844,   854,   815,   587,  1851,   876,   855,   856,   877,   903,
     913,   874,   600,   914,   917,   920,   924,   925,   956,   286,
     927,   954,   957,   959,   968,   607,   973,   980,   977,   612,
    1009,  1011,  1018,  1024,  1028,   286,   286,   286,  1029,  1036,
    1037,  1038,  1049,  1050,  1406,  1407,  1055,  1065,  1067,  1082,
    1435,  1436,  1427,  1429,  1070,  1077,  1079,  1083,  1090,  1091,
    1092,  1094,  1095,  1096,  1098,  1099,  1100,  1723,  1101,  1102,
    1103,  1725,  1104,  1105,   754,  1106,   754,   754,  1735,  1107,
    1110,  1114,  1139,  1140,  1148,  1166,  1149,  1150,  1160,   286,
     754,  1157,  1172,  1175,  1180,  1176,  1188,   446,  1189,  1190,
    1196,  1198,  1284,  1215,   286,   286,   286,  1207,  1216,   754,
    1219,  1241,  1242,  1244,  1260,   286,  1257,  1258,  1259,  1271,
     454,  1272,  1273,  1276,   454,  1286,  1301,   754,  1287,  1504,
    1296,  1293,  1300,   454,  1299,   454,  1302,  1305,   454,  1306,
    1307,   721,   722,  1311,  1320,  1321,  1326,  1327,  1341,  1578,
    1347,  1583,  1348,   286,  1366,  1350,  1349,   732,  1355,  1358,
    1362,  1379,  1383,   754,  1361,  1395,  1411,  -195,  1505,   368,
    1419,  1437,  1507,  1438,  2014,  1439,  1442,  1443,  1445,  1444,
    1446,  1511,  1447,  1512,  1449,  1456,  1514,  1457,  1460,  1462,
     454,  1461,  1508,  1471,  1472,   286,  1473,   286,  1474,  1475,
    1476,  1477,  1478,  1479,  1484,  1483,  1485,  1486,   440,  1560,
    1488,  1562,  1489,   286,  1490,  1487,  1495,  1503,  1509,  1515,
    1516,  1518,  1529,  1520,  1534,  1524,   286,  1526,  1535,  1540,
     286,  1537,  1541,  1545,  1547,  1548,  1549,  1551,  1554,  1565,
    1731,  1563,  1571,  1569,  1585,  1587,  1592,  1744,  1744,  1598,
    1594,  1586,  1599,  1600,   850,  1675,  1605,  1606,  1607,  1608,
    1609,  1610,  1611,  1612,  1613,  1614,   600,  1624,   864,  1631,
    1635,  1641,  1645,  1651,  1652,  1656,  1657,  1658,  1878,  1672,
    1664,  1665,  1666,  1667,   286,   286,   286,  1673,  1679,  1680,
    1681,  1682,   286,  1687,  1688,  1683,  1684,   440,   440,  1693,
    1694,  1718,  1695,  1699,  1700,  1701,  1727,   286,  1733,  1753,
    1754,  1690,  1756,  1762,  1763,  1766,  1773,  1715,   286,  1779,
    1705,  1746,  1780,  1708,  1722,  1765,   286,  1291,  1751,  1732,
     286,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,  1689,  1769,  1726,  1781,   587,  1758,
    1782,  1804,  1784,  1785,  1786,  1787,  1791,   754,  1792,  1793,
    1790,  1772,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,  1798,  1168,  1805,
    1783,   587,  1806,  1807,   368,  1809,  1828,  1832,  1833,  1842,
     460,   460,  1846,  1865,  1874,  1864,   286,  1875,  1866,   767,
    1877,  1882,  -559,  1894,  1895,  1896,  1897,  1901,  1904,  1909,
    1910,  1911,  1912,  1913,   454,  1919,  1925,  1926,  1932,  1939,
    1927,   440,  1941,   286,  1935,   440,  1936,  1933,   286,  1942,
    1951,  1958,  1959,  1965,   440,  1968,   440,  1970,  1971,   440,
    1972,  1953,  1966,  1973,  1881,  1818,  1030,  1975,  1519,  1967,
    1976,  1998,  2017,  1981,  2022,  2033,  2018,  2034,  2036,  2038,
    2035,  2044,  1764,  1804,  2051,  -560,  1835,  1836,  1837,  1838,
    1839,  1841,  2047,  2048,  2057,  2064,  2055,  2067,  2071,  2059,
    2061,  2065,  2072,  2083,  2069,  2075,  2084,  2086,  1855,  2020,
    2094,   440,  2087,  2099,  2104,  1860,  1863,  2109,  2152,  2153,
     286,  2123,  2154,   286,   286,  2155,  2157,  2158,  2159,  2163,
    2175,  2037,  2179,  2160,  1872,  2140,  2174,  1814,  1815,  2187,
     446,   446,  2182,  2192,     7,     8,   286,  2193,  2196,  2197,
    1567,  2117,   286,  1627,  1778,  1989,  1962,  1596,   120,   131,
    1808,   132,   286,   776,   133,  2012,   916,  1717,   139,  1876,
    1861,  1745,   454,     0,     0,   454,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,     0,     0,     0,
    1324,     0,  2085,     0,   368,     0,   286,   460,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1856,     0,     0,  1858,     0,     0,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,   460,  2108,     0,    42,    43,    44,    45,     0,     0,
      47,     0,     0,     0,  1195,     0,     0,   748,    54,     0,
     286,    57,   749,     0,   750,   751,     0,   752,     0,     0,
       0,  1963,   286,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,  1923,  1924,     0,     0,
       0,     0,     0,     0,     0,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,    92,    93,
      94,   440,   440,  1993,     0,     0,     0,     0,     0,     0,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1956,   440,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   568,     0,     0,
       0,     0,  2024,  2025,  2026,  2027,  2028,   286,     0,     0,
       0,     0,     0,     0,     0,     0,  1308,     0,     0,     0,
       0,   286,     0,     0,     0,     0,  1994,   286,   286,     0,
       0,     0,  1328,   939,     0,     0,     0,     0,     0,     0,
       0,  1995,  1996,     0,   286,     0,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   446,
       0,  2013,   286,  2062,     0,     0,     0,  2066,     0,     0,
       0,     0,     0,     0,     0,     0,  2023,     0,     0,     0,
       0,  1377,  1378,     0,  1380,  1381,  1382,   368,  1384,  1385,
    1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,   286,     0,
       0,     0,     0,     0,     0,  2093,     0,     0,     0,     0,
    1498,     0,     0,     0,     0,     0,     0,  2100,     0,     0,
       0,  2102,     0,   440,     0,   286,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2114,  1405,     0,
       0,   754,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   440,     0,
       0,     0,  1420,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,     0,  1434,     0,
       0,     0,     0,     0,  2149,  2150,     0,     0,     0,     0,
    2098,     0,   440,     0,   286,   286,   286,   286,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2110,  2111,
    2112,  2113,  2115,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   809,   583,   584,   585,
     586,     0,  1481,     0,     0,   587,     0,   734,   286,   735,
       0,     0,     0,     0,     0,     0,     0,  1492,  1493,  1494,
       0,     0,     0,     0,     0,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2156,
       0,     0,     0,     0,     0,     0,     0,   454,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,     0,  1525,     0,   454,   454,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   454,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2172,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,  2188,  2190,   587,     0,
    1499,     0,     0,     0,     0,     0,  1582,     0,     0,     0,
    2198,     0,     0,     0,     0,     0,     0,     0,     0,  1597,
       0,     0,     0,  1601,     0,     0,     0,     0,     0,   204,
     162,     0,     0,     0,     0,     0,   205,   206,   207,     0,
       0,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   412,   226,
     227,   228,   229,   230,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1648,  1649,  1650,
       0,   237,   238,   239,   240,  1655,     0,     0,   754,   241,
       0,   162,   376,     0,     0,     0,     0,     0,     0,     0,
    1670,     0,     0,   245,   246,   247,     0,     0,     0,     0,
       0,  1678,     0,     0,   248,    24,     0,   249,     0,  1686,
       0,     0,     0,   739,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   377,   378,   379,   380,   381,   382,   383,
     384,   385,     0,     0,     0,     0,   386,   387,   388,   389,
       0,     0,     0,   754,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   394,     0,   756,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   754,   395,     0,     0,
     396,     0,     0,     0,   296,     0,     0,   297,     0,  1750,
     298,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1771,     0,     0,     0,
     426,     0,     0,     0,     0,     0,   259,     0,   440,     0,
     260,     0,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,   440,
     440,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   413,   440,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   357,     0,     0,     0,   609,     0,     0,
     273,     0,     0,     0,     0,     0,     0,     0,   397,   398,
     399,     0,   167,  1811,   172,     0,     0,     0,     0,   400,
       0,     0,     0,   401,     0,   402,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1750,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   433,     0,     0,     0,  1847,     0,     0,  -555,     0,
    1553,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,  1871,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1880,
       0,     0,   414,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,   439,   441,
       0,     0,     0,   451,     0,     0,     0,   456,     0,     0,
       0,     0,     0,     0,     0,   461,     0,     0,     0,     0,
       0,     0,     0,  1750,     0,     0,     0,     0,     0,     0,
       0,   473,   474,   475,     0,   477,   478,   479,     0,   481,
     482,   483,   484,   485,   486,   487,     0,   489,   490,   491,
     492,     0,     0,     0,   496,     0,     0,     0,  1940,     0,
       0,     0,     0,     0,     0,     0,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   528,
     529,   530,   531,   532,   533,     0,   535,   536,     0,     0,
       0,     0,     0,     0,     0,   541,   542,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,     0,
    1982,     0,     0,     0,     0,     0,   555,   557,   559,   560,
     496,     0,     0,     0,  1990,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   496,   496,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1750,     0,     0,
       0,     0,     0,     0,     0,   610,     0,     0,     0,     0,
       0,  2019,     0,     0,     0,   620,   621,     0,     0,     0,
       0,   621,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,   643,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1750,     0,     0,     0,   664,   496,     0,     0,     0,
     668,   669,   670,     0,   672,     0,     0,     0,   675,   676,
     677,     0,     0,   678,   679,   680,   681,     0,  2063,     0,
     685,   686,   687,   688,   689,   690,   691,     0,   692,     0,
       0,     0,   693,   694,     0,     0,   697,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   709,
       0,   710,     0,     0,     0,   496,   719,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   727,   728,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1394,     0,     0,   755,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,   782,   783,   784,   785,
     587,     0,   972,     0,   790,     0,     0,     0,   794,     0,
     931,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1750,   808,   557,     0,     0,     0,   812,     0,     0,
       0,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     825,   826,   827,   828,   829,   830,   831,   832,   834,   835,
     836,   837,   838,   839,   840,   840,     0,   845,   846,     0,
     848,     0,     0,     0,     0,     0,     0,     0,     0,   857,
       0,     0,   861,   862,  1750,     0,     0,     0,     0,   840,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,   875,     0,     0,     0,     0,   878,   879,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   891,
     893,   895,   896,   897,   898,   899,     0,   901,   902,     0,
       0,     0,     0,     0,     0,   910,   911,   912,     0,     0,
       0,     0,     0,   918,   919,     0,   496,   496,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   555,   710,   938,     0,     0,
       0,   943,   944,   945,   946,   947,   948,   949,   950,   951,
       0,     0,     0,     0,     0,   958,     0,   960,     0,     0,
     962,     0,     0,     0,   496,   496,   496,   967,     0,   969,
     970,   971,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,   994,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,  1013,     0,  1014,
       0,     0,   901,   902,     0,     0,     0,     0,     0,   497,
       0,  1027,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   496,     0,  1043,     0,     0,     0,
       0,  1046,  1047,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   496,     0,  1063,  1064,
       0,     0,   496,  1069,     0,     0,     0,  1063,     0,  1076,
       0,     0,     0,     0,     0,  1081,   162,   376,     0,  1084,
       0,  1482,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1108,     0,   893,     0,  1111,
       0,   497,   497,     0,     0,     0,     0,     0,   377,   378,
     379,   380,   381,   382,   383,   384,   385,     0,     0,     0,
       0,   386,   387,   388,   389,     0,  1523,     0,     0,   390,
     391,   392,   496,     0,     0,     0,   393,     0,   394,     0,
       0,     0,   496,  1153,  1154,     0,   497,     0,     0,     0,
       0,     0,   395,     0,     0,   396,     0,  1169,     0,   296,
    1908,   568,   297,     0,     0,   298,     0,   299,     0,     0,
       0,   497,     0,     0,     0,     0,     0,     0,    45,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1186,     0,   496,     0,   426,     0,     0,     0,     0,
       0,  1194,     0,     0,     0,  1200,     0,     0,     0,     0,
       0,   496,     0,     0,     0,     0,     0,     0,     0,  1213,
    1214,     0,     0,     0,     0,  1217,     0,     0,     0,     0,
     497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1243,     0,     0,  1245,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   397,   398,   399,  1261,  1536,  1263,  1264,
       0,     0,     0,     0,   400,     0,     0,     0,   401,     0,
     402,   115,     0,     0,     0,     0,     0,  1282,     0,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,   558,     0,
    1304,   587,     0,  1740,     0,     0,     0,  1310,     0,     0,
       0,     0,  1319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   833,     0,     0,     0,     0,  1345,  1346,   841,
     842,     0,     0,   496,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,   867,  1365,   587,     0,     0,   497,
       0,     0,     0,  1371,  1372,  1373,  1374,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     809,   583,   584,   585,   586,   894,     0,     0,   496,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1397,     0,     0,     0,     0,     0,
       0,   497,   497,     0,  1398,  1399,  1400,     0,     0,     0,
       0,  1402,  1403,     0,  1404,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1413,  1414,
       0,     0,     0,     0,     0,     0,  1417,  1418,     0,     0,
    1421,     0,     0,  1422,     0,  1423,  1424,     0,     0,   497,
     497,   497,  1430,  1431,     0,     0,     0,   496,   496,     0,
       0,     0,     0,   162,   376,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,  1459,
       0,     0,     0,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   377,   378,   379,   380,   381,
     382,   383,   384,   385,     0,     0,     0,     0,   386,   387,
     388,   389,     0,     0,  1491,     0,   390,   391,   392,   497,
       0,     0,     0,   393,     0,   394,   496,     0,     0,     0,
       0,     0,     0,     0,  1506,     0,     0,     0,     0,   395,
       0,   497,   396,     0,     0,     0,   296,   497,     0,   297,
       0,     0,   298,     0,   299,  1430,  1431,     0,     0,     0,
    1522,  1668,     0,     0,     0,    45,     0,     0,     0,     0,
       0,  1528,     0,     0,  1533,     0,     0,     0,     0,     0,
       0,     0,   426,  1543,  1544,     0,     0,     0,     0,  1724,
       0,     0,   894,     0,  1112,     0,     0,     0,     0,     0,
       0,     0,  1555,     0,     0,  1558,   496,  1561,   496,     0,
       0,     0,     0,     0,     0,     0,  1570,     0,  1572,     0,
    1570,  1575,  1577,  1728,     0,     0,     0,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
       0,   400,     0,     0,     0,   401,     0,   402,   115,     0,
       0,     0,     0,  1632,     0,   497,     0,     0,     0,     0,
       0,     0,     0,  1640,     0,     0,     0,     0,   497,     0,
       0,     0,     0,     0,     0,     0,     0,   734,     0,   735,
    1740,     0,  1654,     0,     0,     0,   497,     0,     0,  1661,
    1662,  1663,     0,     0,     0,     0,     0,     0,  1669,     0,
    1671,     0,     0,     0,     0,     0,     0,  1674,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,     0,     0,     0,     0,  1691,     0,     0,     0,
       0,     0,     0,     0,  1696,  1697,  1698,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1709,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1721,     0,     0,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,  1738,
       0,   587,     0,     0,     0,  1747,  1748,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,  1774,   497,  1776,
       0,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1794,
    1795,  1796,     0,     0,     0,     0,     0,     0,     0,     0,
    1797,     0,     0,   497,     0,  1800,  1801,  1802,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1810,
       0,     0,     0,     0,   496,   496,  1816,     0,  1817,     0,
       0,     0,     0,     0,  1825,  1826,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   496,     0,     0,     0,     0,  1844,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,  1854,     0,     0,  1857,     0,     0,     0,  1859,     0,
       0,     0,   497,   497,     0,     0,     0,  1801,  1802,     0,
    1868,     0,     0,     0,     0,     0,     0,     0,  1873,     0,
       0,     0,     0,     0,  1734,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1886,     0,     0,     0,     0,  1892,
    1893,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1898,     0,   737,  1899,  1898,  1845,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       0,   497,    42,    43,    44,    45,     0,  1931,    47,     0,
       0,     0,     0,   496,   496,   748,    54,     0,     0,    57,
     749,     0,   750,   751,     0,   752,     0,     0,     0,     0,
    1934,     0,     0,     0,     0,     0,     0,     0,     0,  1943,
       0,     0,    78,     0,     0,     0,     0,     0,   557,     0,
       0,     0,     0,     0,     0,     0,     0,  1954,  1955,     0,
       0,   496,     0,     0,     0,     0,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   858,     0,
       0,   497,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1979,  1980,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1992,     0,     0,   496,   496,
    1997,     0,     0,     0,     0,  2000,     0,     0,  2002,   906,
       0,     0,     0,     0,     0,     0,     0,     0,   496,     0,
       0,   963,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   496,     0,     0,     0,     0,     0,     0,
       0,  2029,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,  2040,     0,     0,     0,
       0,     0,  2045,     0,     0,  2046,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,   497,     0,   587,     0,
       0,     0,     0,     0,  2070,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,  2088,
    2089,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2095,  2096,     0,  2097,   496,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1957,     0,
    2106,     0,     0,     0,     0,   496,   496,   496,   496,   496,
       0,     0,     0,     0,     0,  1892,     0,     0,     0,  2122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1777,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1969,     0,     0,  2143,     0,     0,
       0,     0,  2146,  2147,  2148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   496,     0,     0,     0,
       0,     0,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,     0,  1127,  1128,  1129,  1130,     0,  1132,
    1133,  1134,  1135,     0,  2176,  2177,  2178,     0,     0,     0,
       0,     0,     0,  1145,     0,  1147,     0,     0,     0,   497,
     497,     0,     0,     0,     0,  1156,     0,     0,     0,     0,
       0,     0,  1162,  1163,     0,     0,     0,   204,   162,     0,
       0,  1174,     0,     0,   205,   206,   207,     0,   497,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   412,   226,   227,   228,
     229,   230,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   237,
     238,   239,   240,     0,     0,     0,     0,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   248,    24,     0,   249,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,  1267,  1269,  1270,     0,     0,     0,  1274,  1275,     0,
       0,  1278,  1279,  1280,  1281,     0,  1283,     0,   497,   497,
       0,  1289,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,   558,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2082,     0,     0,
       0,     0,     0,     0,   259,     0,     0,     0,   260,     0,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
    1370,     0,  2130,   115,     0,  1375,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   627,
     628,     0,     0,   497,   497,     0,   270,     0,     0,     0,
       0,   629,     0,     0,     0,   318,     0,     0,   273,     0,
       0,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   497,     0,
     204,   162,   376,     0,  1440,     0,     0,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,  1432,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   237,   238,   239,   240,   386,   387,   388,   389,
     241,     0,     0,     0,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   394,   245,   246,   247,  2050,     0,     0,
       0,     0,     0,     0,     0,   248,    24,   395,   249,     0,
     396,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,   497,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     497,   497,   497,   497,   497,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,  1542,   587,     0,     0,     0,     0,     0,     0,     0,
       0,   497,     0,     0,     0,     0,     0,   259,   397,   398,
     399,   260,     0,     0,     0,     0,   262,   263,   264,   400,
     265,   266,   267,   401,     0,   402,   115,     0,     0,     0,
       0,  1579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,   413,     0,     0,     7,     8,     0,   270,
       0,     0,     0,     0,   357,     0,     0,     0,  1576,     0,
       0,   273,     0,  1616,  1617,  1618,  1619,  1620,     0,     0,
       0,     0,  1625,  1626,     0,     0,     0,     0,  1628,     0,
    1630,     0,     0,     0,  1634,     0,     0,  1636,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1644,
       0,     0,     0,     0,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,    42,    43,    44,    45,
       0,     0,    47,     0,     0,     0,     0,     0,     0,   748,
      54,     0,     0,    57,   749,   568,   750,   751,     0,   752,
    1704,     0,  1707,     0,     0,     0,  1714,     0,  1716,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,  1741,
      92,    93,    94,   587,     0,     0,     0,     0,     0,   806,
       0,     0,     0,   204,     6,   376,     0,     0,     0,     0,
     205,   206,   207,     0,     0,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,  1580,   378,   379,   380,
     381,   382,   383,   384,   385,   237,   238,   239,   240,   386,
     387,   388,   389,   241,   242,  1010,     0,   390,   391,   392,
       0,     0,   243,   244,   393,     0,   394,   245,   246,   247,
       0,     0,     0,     0,     0,     0,  1803,     0,   248,    24,
     395,   249,     0,   396,     0,     0,     0,   250,     0,     0,
     251,     0,     0,   252,     0,   253,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,    55,    56,
       0,   256,     0,   257,     0,     0,   258,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
       0,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,  1883,     0,
       0,  1884,     0,     0,     0,     0,     0,     0,     0,     0,
     259,   397,   398,   399,   260,   261,   568,     0,     0,   262,
     263,   264,   400,   265,   266,   267,   401,     0,   402,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   269,     0,     0,     0,
    1915,  1916,   270,  1918,     0,     0,     0,   357,     0,     0,
       0,  1581,     0,     0,   273,     0,     0,     0,     0,     0,
       0,     0,   204,     6,   376,     0,     0,     0,     0,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,  1960,  1961,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   237,   238,   239,   240,   386,   387,
     388,   389,   241,   242,     0,     0,   390,   391,   392,     0,
       0,   243,   244,   393,     0,   394,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,   395,
     249,  1991,   396,     0,     0,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
      66,    67,    68,    69,    70,     0,    72,    73,    74,    75,
      76,    77,     0,     0,     0,    81,     0,     0,    84,     0,
       0,     0,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   809,   583,   584,   585,   586,
     981,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     397,   398,   399,   260,   261,  1177,     0,     0,   262,   263,
     264,   400,   265,   266,   267,   401,     0,   402,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   269,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,     0,     0,     0,
     272,     0,     0,   273,   204,   162,   376,     0,   425,     0,
       0,   205,   206,   207,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   412,   226,   227,   228,   229,   230,   231,
       0,     0,     0,     0,     0,     0,     0,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   237,   238,   239,   240,
     386,   387,   388,   389,   241,     0,     0,     0,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   394,   245,   246,
     247,     0,     0,  2165,     0,     0,     0,     0,     0,   248,
      24,   395,   249,     0,   396,     0,     0,     0,   296,     0,
       0,   297,     0,     0,   298,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   426,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,  1178,   587,   427,     0,     0,     0,     0,     0,
       0,   259,   397,   398,   399,   260,     0,     0,     0,     0,
     262,   263,   264,   400,   265,   266,   267,   401,     0,   402,
     115,   428,   429,   430,   431,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   413,     0,     0,
       0,     0,     0,   270,   432,   433,     0,     0,   434,     0,
     435,   204,     6,   356,   436,   273,     0,     0,   205,   206,
     207,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     243,   244,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
       0,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,   253,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,    55,    56,     0,   256,
       0,   257,     0,     0,   258,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,  1497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,     6,     0,   358,
       0,   665,   273,   205,   206,   207,     0,     0,   208,   209,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   495,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
     357,   204,     6,  1677,     0,   561,     0,   273,   205,   206,
     207,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     243,   244,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
       0,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,   253,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,    55,    56,     0,   256,
       0,   257,     0,     0,   258,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   734,     0,   735,     0,     0,     0,     0,     0,
    1706,     0,     0,     0,     0,     0,     0,     0,   259,     0,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  1821,     0,     0,     0,  1822,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   627,  1840,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
     629,   204,     6,     0,   318,   561,     0,   273,   205,   206,
     207,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     243,   244,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
       0,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,   253,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,    55,    56,     0,   256,
       0,   257,     0,     0,   258,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1848,     0,     0,     0,
    1849,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   271,   204,     6,     0,   272,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  2015,     0,     0,     0,  2016,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   269,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
     357,   204,     6,     0,   272,     0,     0,   273,   205,   206,
     207,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     243,   244,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
       0,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,   253,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,    55,    56,     0,   256,
       0,   257,     0,     0,   258,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     765,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   495,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,     6,     0,   556,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   771,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   495,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
     357,   204,     6,     0,     0,   561,     0,   273,   205,   206,
     207,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     243,   244,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
       0,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,   253,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,    55,    56,     0,   256,
       0,   257,     0,     0,   258,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     931,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   599,   204,     6,     0,   272,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   932,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   269,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
     606,   204,     6,     0,   272,     0,     0,   273,   205,   206,
     207,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     243,   244,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
       0,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,   253,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,    55,    56,     0,   256,
       0,   257,     0,     0,   258,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     978,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   495,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,     6,     0,   892,
       0,  1351,   273,   205,   206,   207,     0,     0,   208,   209,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1085,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   495,
       0,     0,     0,     0,     0,   270,   204,     6,     0,     0,
     357,  1559,     0,   205,   206,   207,     0,   273,   208,   209,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1086,     0,     0,     0,     0,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1087,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   269,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
     357,   204,     6,     0,  1685,     0,     0,   273,   205,   206,
     207,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     243,   244,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
       0,     0,     0,     0,     0,   250,     0,     0,   251,     0,
       0,   252,     0,   253,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,    55,    56,     0,   256,
       0,   257,     0,     0,   258,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1088,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   627,  1840,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   629,   204,     6,     0,   318,
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
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1126,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   495,
       0,     0,     0,     0,     0,   270,   204,   162,   376,     0,
     357,     0,     0,   205,   206,   207,     0,   273,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   412,   226,   227,   228,   229,
     230,   231,     0,     0,     0,     0,     0,     0,     0,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   237,   238,
     239,   240,   386,   387,   388,   389,   241,     0,     0,     0,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   394,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,   395,   249,     0,   396,   204,   162,   376,
       0,     0,     0,     0,   205,   206,   207,     0,     0,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   412,   226,   227,   228,
     229,   230,   231,     0,     0,     0,     0,     0,     0,     0,
    1580,   378,   379,   380,   381,   382,   383,   384,   385,   237,
     238,   239,   240,   386,   387,   388,   389,   241,     0,     0,
       0,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     394,   245,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   248,    24,   395,   249,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   397,   398,   399,   260,     0,     0,
       0,     0,   262,   263,   264,   400,   265,   266,   267,   401,
       0,   402,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   413,
       0,     0,     0,     0,     0,   270,     0,     0,     0,     0,
     357,     0,     0,     0,  1853,     0,     0,   273,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1136,     0,     0,     0,   259,   397,   398,   399,   260,     0,
       0,     0,     0,   262,   263,   264,   400,   265,   266,   267,
     401,     0,   402,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     413,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   357,   204,   162,   376,  1740,     0,     0,   273,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   412,   226,   227,   228,   229,   230,   231,     0,     0,
       0,     0,     0,     0,     0,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   237,   238,   239,   240,   386,   387,
     388,   389,   241,     0,     0,     0,   390,   391,   392,     0,
       0,     0,     0,   393,     0,   394,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,   395,
     249,     0,   396,   204,   162,     0,     0,     0,   860,     0,
     205,   206,   207,     0,     0,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   412,   226,   227,   228,   229,   230,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   239,   240,     0,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   248,    24,
       0,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     397,   398,   399,   260,     0,     0,     0,     0,   262,   263,
     264,   400,   265,   266,   267,   401,     0,   402,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,   273,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1137,     0,     0,     0,
     259,     0,     0,     0,   260,     0,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   413,     0,     0,     0,
       0,     0,   270,   204,   162,     0,     0,   357,     0,     0,
     205,   206,   207,     0,   273,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   412,   226,   227,   228,   229,   230,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   239,   240,     0,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   248,    24,
       0,   249,   204,   162,     0,  1303,     0,     0,     0,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   412,   226,   227,   228,   229,   230,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,     0,
     249,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
     259,     0,     0,   587,   260,     0,     0,     0,   712,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   413,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   357,  1074,     0,
       0,     0,     0,     0,   273,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1138,     0,   259,
       0,     0,     0,   260,     0,     0,     0,     0,   262,   263,
     264,     0,   265,   266,   267,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,   204,   162,     0,  1458,   357,     0,     0,   205,
     206,   207,     0,   273,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   412,   226,   227,   228,   229,   230,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,     0,
     249,   204,   162,     0,  1521,     0,     0,     0,   205,   206,
     207,     0,     0,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     412,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,   259,
       0,     0,   587,   260,     0,     0,     0,   923,   262,   263,
     264,     0,   265,   266,   267,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,   273,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1143,     0,   259,     0,
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
       0,     0,     0,     0,   587,     0,     0,     0,   259,     0,
       0,     0,   260,     0,  1144,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,  1574,     0,     0,     0,
       0,     0,   273,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
     259,     0,     0,     0,   260,  1146,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   413,     0,     0,     0,
       0,     0,   270,   204,   162,     0,     0,   357,  1900,     0,
     205,   206,   207,     0,   273,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   412,   226,   227,   228,   229,   230,   231,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   239,   240,     0,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   248,    24,
       0,   249,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1256,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     7,     8,
       0,    42,    43,    44,    45,     0,     0,    47,     0,     0,
       0,     0,     0,     0,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,     0,   260,    92,    93,    94,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,   268,   413,     0,    42,    43,
      44,    45,   270,     0,    47,     7,     8,   357,     0,     0,
       0,   748,    54,     0,   273,    57,   749,     0,   750,   751,
       0,   752,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
    1012,     0,     0,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,    92,    93,    94,   587,     0,     0,     0,     0,
       0,     0,     7,     8,     0,  1277,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,    42,    43,    44,    45,     0,
       0,    47,     0,     0,     0,     0,     0,     0,   748,    54,
       0,     0,    57,   749,     0,   750,   751,     0,   752,     7,
       8,     0,     0,     0,     0,     0,     0,  1208,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    92,
      93,    94,    42,    43,    44,    45,     0,     0,    47,     0,
       0,     0,     0,     0,     0,   748,    54,     0,     0,    57,
     749,     0,   750,   751,     0,   752,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,    42,
      43,    44,    45,     0,     0,    47,    92,    93,    94,     0,
       0,     0,   748,    54,  1210,     0,    57,   749,     0,   750,
     751,     0,   752,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    92,    93,    94,    42,    43,    44,    45,
       0,     0,    47,     0,     0,     0,     0,     0,     0,   748,
      54,  1211,     0,    57,   749,     0,   750,   751,     0,   752,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,     0,     0,    42,    43,    44,    45,     0,     0,    47,
      92,    93,    94,     0,     0,     0,   748,    54,  1230,     0,
      57,   749,     0,   750,   751,     0,   752,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    92,    93,    94,
      42,    43,    44,    45,     0,     0,    47,     0,     0,     0,
       0,     0,     0,   748,    54,  1248,     0,    57,   749,     0,
     750,   751,     0,   752,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,    42,    43,    44,
      45,     0,     0,    47,    92,    93,    94,     0,     0,     0,
     748,    54,  1262,     0,    57,   749,     0,   750,   751,     0,
     752,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    92,    93,    94,    42,    43,    44,    45,     0,     0,
      47,     0,     0,     0,     0,     0,     0,   748,    54,  1295,
       0,    57,   749,     0,   750,   751,     0,   752,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,    42,    43,    44,    45,     0,     0,    47,    92,    93,
      94,     0,     0,     0,   748,    54,  1450,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,    -4,
       1,     0,     0,    -4,     0,     0,     0,     0,     0,     0,
       0,    78,    -4,    -4,     0,     0,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,    92,    93,    94,   587,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,  1360,     0,
       0,     0,     0,  2073,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,     0,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
    2132,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     6,     0,    -4,    -4,    -4,     0,     0,     0,
      -4,     7,     8,     0,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,     9,    10,     0,    -4,    -4,    -4,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,     0,    -4,     0,
       0,     0,    11,    12,    13,     0,     0,     0,    14,    15,
       0,     0,     0,    16,     0,     0,     0,     0,    17,    18,
      19,    20,    21,     0,    22,    23,     0,    24,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
      41,    42,    43,    44,    45,    46,     0,    47,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,    87,    88,    89,     0,     0,     0,    90,
       0,     0,     0,     0,    91,    92,    93,    94,   162,   376,
      95,     0,    96,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   111,   112,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,   115,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   384,   385,     0,
       0,     0,     0,   386,   387,   388,   389,     0,   162,   376,
       0,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     394,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,     0,     0,   396,     0,     0,
       0,   296,     0,     0,   297,     0,     0,   298,     0,   299,
     377,   378,   379,   380,   381,   382,   383,   384,   385,     0,
      45,     0,     0,   386,   387,   388,   389,     0,   406,   376,
       0,   390,   391,   392,     0,     0,     0,   426,   393,     0,
     394,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,     0,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   384,   385,     0,
       0,     0,     0,   386,   387,   388,   389,   376,     0,     0,
       0,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     394,     7,     8,     0,     0,   397,   398,   399,     0,     0,
       0,     0,     0,     0,   395,     0,   400,   396,     0,     0,
     401,     0,   402,   115,     0,     0,     0,     0,   377,   378,
     379,   380,   381,   382,   383,   384,   385,     0,     0,     0,
       0,   386,   387,   388,   389,     0,     0,     0,     0,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   394,     0,
       0,     0,     0,     0,     0,   397,   398,   399,     0,     0,
       0,     0,   395,     0,     0,   396,   400,     0,     0,     0,
     401,     0,   402,   115,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,    42,    43,    44,    45,     0,     0,    47,     0,     0,
       0,     0,     0,     0,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,   397,   398,   399,  1021,     7,
       8,     0,     0,     0,     0,     0,   400,     0,     0,     0,
     401,    78,   402,     0,     0,  1022,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,    92,    93,    94,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1363,     0,
       0,     0,     0,   397,   398,   399,     0,     0,     0,     0,
       0,     0,     0,     0,   400,     0,     0,     0,   401,     0,
     402,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,    42,
      43,    44,    45,     0,     0,    47,     0,     0,     0,     0,
       0,     0,   748,    54,     0,     0,    57,   749,     0,   750,
     751,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,    92,    93,    94,     0,     0,     0,     0,
       0,     0,  1452,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1453,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1496,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1621,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1622,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1623,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1637,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1768,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1887,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1888,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1917,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1920,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1987,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2041,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2042,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2056,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2058,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2091,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2119,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2124,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2125,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2126,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2166,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  1056,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1113,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  1158,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  1159,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  1202,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  1233,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  1253,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    1309,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  1329,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  1409,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  1410,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1454,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  1527,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  1770,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  1819,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  1830,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  1867,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    1937,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  1952,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  1964,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  2021,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  2030,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  2031,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  2054,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  2105,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  2145,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  2164,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    2184,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  2185,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  2186,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,  1930,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,   734,     0,   735,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
     984,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,  1032,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,  1182,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,  1247,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,  1249,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,  1254,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,  1255,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,  1343,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,  1357,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,  1556,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
    1643,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,  1692,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,  1879,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,  1922,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,  1938,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   787,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   788,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   789,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   791,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   792,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   793,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   795,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   796,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   797,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   798,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   799,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   800,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   801,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   803,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   804,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   805,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   872,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   907,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   953,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   972,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   974,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   975,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   976,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,   982,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,   983,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1020,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1031,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1093,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1097,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1109,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1181,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1191,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1192,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1193,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1203,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1232,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1234,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1235,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1236,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1237,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1238,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1239,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1240,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1246,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1342,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1356,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1557,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1588,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1589,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1590,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1591,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1629,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1642,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1755,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1757,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1760,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1767,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1820,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1829,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1852,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1921,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  1985,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  1986,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,  2118,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,  2161,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587
};

static const yytype_int16 yycheck[] =
{
       3,   141,   311,    67,    68,  1416,    70,  1231,   154,     3,
       6,   193,    61,  1227,  1679,   624,   625,   716,     5,   201,
     323,    24,     4,  1723,   729,  1725,     4,     4,     4,     4,
       4,     4,   737,     4,    24,     4,     4,     4,     4,   342,
    1902,   106,     5,   108,     6,     6,   745,     5,     5,   137,
      53,     4,     4,     4,     6,     4,  1710,     7,   157,     6,
       6,   103,    97,   762,     6,   103,   240,   241,   235,   236,
       4,   770,   246,     4,   235,   236,   141,     9,   248,    82,
       7,   116,     7,   182,   126,     9,   256,    90,   126,   256,
     235,   236,    95,   235,   236,   256,     4,   185,   137,   198,
     199,     9,   167,   106,     0,   247,   409,   252,   411,   251,
     248,   293,   294,   295,    89,   154,   419,   248,   256,     9,
    1774,     6,   253,   162,   163,   164,   235,   236,  1793,   168,
     169,   250,     6,     9,    14,   235,   236,   256,   141,   235,
     236,     6,   251,   146,   147,    97,     9,     6,   142,     9,
     247,   154,   249,   335,   336,   337,   256,   106,   107,   256,
     256,   235,   236,    97,   247,     6,   249,   101,   251,   172,
     352,   243,   244,   107,   108,   874,   110,   111,   247,   247,
     249,   253,   256,   251,     7,   188,   141,  2049,     7,   248,
     193,   146,   147,   196,   243,   244,   130,   256,   201,   202,
     203,   172,   173,   174,   175,   235,   236,   196,   170,   170,
     141,   142,   143,   144,   235,   236,   147,     7,   193,   235,
     236,   250,     7,  1634,   197,   156,   256,   256,   159,   182,
     183,   182,   183,   188,     7,   256,   103,   219,   100,   248,
     256,   103,   219,   219,   219,   219,   100,   256,   203,   103,
     314,   315,   255,   219,   116,   251,  1470,    97,   322,   323,
     100,   247,  1927,   103,   251,   105,   269,     6,     7,   272,
     273,   249,   254,   251,   251,   251,   251,   255,   247,   247,
     247,   252,   248,   273,   250,   288,   289,   247,   251,   292,
     293,   294,   295,   251,   251,   220,   221,   222,   223,   288,
     289,     3,   305,   253,   251,   247,   309,   247,   311,   251,
     613,   219,   615,   616,     6,   247,  1981,   249,   243,   244,
     247,   253,   249,   247,     6,   249,  1031,  1032,   253,   632,
     333,     6,   335,   336,   337,   243,   244,     6,   248,   247,
     250,   249,   251,   251,   333,   253,   256,   650,   248,   352,
     235,   236,     6,   243,   244,   358,   256,   247,    60,   249,
     425,   235,   236,   253,     6,   547,   231,   243,   244,   234,
     673,   247,   231,   249,   250,   234,     6,   253,   251,   247,
     243,   244,   255,   251,   247,  2085,   249,   247,   252,   249,
     253,   537,   256,   253,   235,   236,     6,   220,   221,   222,
     223,   220,   221,   222,   223,   235,   236,   243,   244,   712,
     249,   235,   236,   416,   417,   251,   243,   244,   421,   422,
     243,   244,   235,   236,   243,   244,   256,   251,   417,   249,
     220,   221,   222,   223,   437,   220,   221,   222,   223,   141,
     247,   444,   252,   256,   146,   147,   256,   220,   221,   222,
     223,   252,   154,   243,   244,   256,  2121,   248,   137,   235,
     236,   416,   251,   466,   100,   256,  1165,   103,  1167,   105,
     235,   236,   235,   236,   248,   154,   235,   236,   235,   236,
     256,  1180,   256,   162,   163,   164,   188,   137,   553,   168,
     169,   256,   495,   256,   235,   236,   103,   256,   105,   256,
     248,   203,   250,   247,   154,   235,   236,  1918,   256,  2174,
     235,   236,   162,   163,   164,   256,   519,   118,   168,   169,
     235,   236,   100,   526,   527,   103,   256,   105,   531,   247,
     533,   534,   535,   536,   537,   681,   235,   236,   116,   542,
     242,   256,   247,   546,   547,   548,   549,   550,   551,   552,
     247,   554,   249,   556,   251,   257,   258,   256,   622,   623,
       8,   247,   552,   627,   554,   235,   236,   556,   103,   235,
     236,   235,   236,   252,     6,   248,   531,   250,   533,   582,
     535,   536,   137,   256,   247,   588,   256,   235,   236,   729,
     256,  1290,   256,   251,   549,   550,   252,  1296,    97,   154,
     256,   100,   252,   251,   103,   608,   609,   162,   163,   164,
     235,   236,   252,   168,   169,    97,   256,   116,   100,   608,
     609,   103,   247,   105,   927,   248,   251,   250,   251,   694,
     624,   625,  1241,   137,   116,   235,   236,   237,   238,   239,
     240,   241,  1341,   247,   252,   249,   246,   252,   256,   253,
     154,   256,   256,   656,   657,   658,  1355,   252,   162,   163,
     164,   256,  1361,   247,   168,   169,   252,   656,   657,   658,
     256,   252,   247,   247,   249,   256,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   247,   689,   690,   691,   692,
     693,   247,   695,   696,   697,   698,   699,   252,   248,   702,
     250,   251,   751,   237,   238,   239,   240,   241,   698,   248,
     713,   250,   246,   702,   416,   252,   247,   256,   248,   256,
     250,   786,   247,   726,   426,   680,   256,   682,   683,   684,
     685,   686,   687,   736,   689,   690,   691,   692,  1443,   742,
     695,   696,   697,   243,   244,   252,   448,   736,   252,   256,
     252,   251,   141,   142,   256,   758,   759,   253,   147,   247,
     256,   764,   251,   903,   767,   768,   141,   142,   253,   758,
     255,   774,   147,   776,   247,   764,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   247,   252,   252,   252,   246,   256,
     256,   256,   105,   252,   252,   252,   809,   256,   811,   256,
     252,   252,   767,   252,   256,   256,   252,   256,   252,   252,
     256,   776,   256,   256,   252,  1530,   252,   251,   256,   531,
     256,   533,   252,   535,   536,   537,   256,  1542,   252,   252,
     252,   844,   256,   256,   256,   252,   247,   549,   550,   256,
    2074,   854,   917,   252,   252,   844,   252,   256,   256,   252,
     256,     6,     7,   256,   252,   854,   930,   252,   256,   247,
     252,   256,   252,   937,   256,   252,   256,   941,   252,   256,
     252,   252,   256,   252,   256,   256,   252,   256,   103,   892,
     256,  1031,  1032,  2107,   252,   252,   252,   252,   256,   256,
     256,   256,   905,   892,   252,   248,   247,   250,   256,  2133,
       8,   914,   100,   252,   252,   252,   905,   256,   256,   256,
     923,   252,   252,    53,   251,   256,   256,   252,   630,   252,
     247,   256,   249,   256,   923,   251,   247,  2151,   249,   247,
     247,   249,   249,     4,   103,     6,   251,   247,   100,   100,
     103,   653,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,  1033,     4,
       4,     4,   246,     4,   247,   247,   247,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   247,   689,   690,   691,
     692,   247,     6,   695,   696,   697,     6,   249,   247,   249,
     251,     6,   255,   705,   251,     6,   708,   255,   247,     9,
     247,   247,   247,  1322,   247,   247,   247,   247,   720,   247,
     247,   185,   251,  1026,   185,   185,  1090,   251,   247,   126,
     247,   247,     4,   247,  1037,   185,   247,   247,   251,  1042,
       6,  1181,  1182,   251,   251,   251,   251,   251,   750,   247,
     752,   247,  1055,   247,   247,  1664,  1665,  1060,   247,   249,
     247,   247,   247,     6,     6,   767,  1055,   251,   251,   251,
     251,   249,   202,   249,   776,   249,     6,     6,   251,   185,
     247,   247,   247,     6,   247,   247,     6,     6,  1091,  1092,
     247,  1094,  1095,  1096,   249,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1060,     8,  1110,   251,     6,
       8,   251,     7,     6,   251,   251,     6,   251,    92,   252,
     248,  1110,     7,     6,   256,   255,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   256,  1148,  1149,  1150,   246,     6,
     251,   251,   248,   246,   252,    64,   251,   251,     8,     4,
       7,   253,   292,     7,   247,     6,   248,     6,     6,  1172,
     251,     7,     7,     6,     6,   305,   252,   251,   182,   309,
     252,   252,   250,   248,     6,  1188,  1189,  1190,   251,   253,
       7,     6,   249,   247,  1149,  1150,   251,     4,     6,   248,
    1189,  1190,  1342,  1343,     6,     6,     6,   249,     7,     7,
       7,     7,     7,     7,     7,     7,     7,  1520,     7,     7,
       7,  1524,     7,     7,   926,     7,   928,   929,  1537,     7,
     251,     6,   248,   250,   256,   248,   256,   256,   256,  1242,
     942,   252,     7,   251,   253,   252,     7,  1241,   251,   251,
       4,     6,     9,   252,  1257,  1258,  1259,   253,   252,   961,
     137,   251,     7,     6,   253,  1268,     7,     7,     7,   248,
    1273,   248,   256,   256,  1277,   256,     7,   979,   248,  1268,
     253,   250,   185,  1286,   255,  1288,   157,   252,  1291,   251,
       6,   421,   422,     6,     6,     4,    46,    46,   253,  1364,
     247,  1366,   251,  1306,     4,   251,   247,   437,   253,   247,
     247,     7,     7,  1015,   253,     7,   256,   185,  1273,  1322,
     248,     7,  1277,     7,  1933,     7,     6,   248,     7,   256,
       7,  1286,     7,  1288,     4,   115,  1291,     4,   251,   247,
    1343,     6,   254,     7,     6,  1348,     7,  1350,     7,     7,
       7,     7,     7,     7,     6,   251,     6,     6,  1060,  1348,
       7,  1350,     6,  1366,     6,   103,     4,     4,   256,   248,
     256,   251,     6,   251,     6,   251,  1379,   252,     6,     6,
    1383,     7,   249,     6,   247,   247,   251,     6,  1343,     6,
    1530,   252,     6,   253,   250,     6,     6,  1543,  1544,     6,
     130,   256,     6,     6,   534,  1469,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     5,   546,   248,   548,   248,
       6,     4,     6,     4,     6,   251,   251,     7,  1737,     6,
     251,   251,   251,   249,  1437,  1438,  1439,     6,   251,   251,
     251,   251,  1445,   252,     6,   251,   251,  1149,  1150,     6,
       6,  1516,   181,     6,     6,     6,     6,  1460,     7,     4,
       6,   251,     6,     6,     6,     4,     7,   248,  1471,     6,
     256,   247,     6,   256,   251,   247,  1479,   256,   251,   253,
    1483,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,  1483,   247,   256,     6,   246,   252,
       6,  1641,     6,     6,     6,     6,     6,  1209,     5,   251,
     101,  1576,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   248,   256,   251,
    1594,   246,   251,     6,  1537,     6,   256,     6,     6,     6,
    1543,  1544,     6,   248,     6,   256,  1549,     4,   256,   256,
       6,     6,   251,     6,     6,     6,     6,     6,   251,     7,
     251,   251,   251,     5,  1567,   248,     6,     6,     6,     6,
     251,  1273,     7,  1576,   252,  1277,   252,   251,  1581,   251,
       6,     6,   248,   252,  1286,     6,  1288,     7,     6,  1291,
     253,   180,   252,     6,  1740,  1660,   726,     6,  1300,   252,
       6,     6,     6,   251,     6,   248,   252,     6,     6,   183,
     251,     6,  1567,  1753,   247,   251,  1680,  1681,  1682,  1683,
    1684,  1685,   252,   252,   248,     6,   251,     6,     6,   251,
     251,   251,   137,     6,   252,   251,     6,     6,  1703,  1942,
     248,  1343,   251,     6,     6,  1710,  1711,     6,     6,     6,
    1653,   252,     6,  1656,  1657,     6,     6,     6,     6,     6,
       6,  1970,     6,   251,  1729,   252,   251,  1656,  1657,     6,
    1664,  1665,   251,     6,    13,    14,  1679,     6,     6,     6,
    1354,  2087,  1685,  1411,  1586,  1903,  1864,  1378,     3,     3,
    1649,     3,  1695,   463,     3,  1929,   603,  1513,     3,  1733,
    1710,  1544,  1705,    -1,    -1,  1708,    -1,   767,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1726,    -1,    -1,    -1,    -1,    -1,    -1,
    1733,    -1,  2035,    -1,  1737,    -1,  1739,  1740,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1705,    -1,    -1,  1708,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,  1774,  2075,    -1,   113,   114,   115,   116,    -1,    -1,
     119,    -1,    -1,    -1,   914,    -1,    -1,   126,   127,    -1,
    1793,   130,   131,    -1,   133,   134,    -1,   136,    -1,    -1,
      -1,  1866,  1805,  1806,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,    -1,  1805,  1806,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1828,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1840,   177,   178,
     179,  1543,  1544,  1908,    -1,    -1,    -1,    -1,    -1,    -1,
    1853,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1853,  1567,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,  1946,  1947,  1948,  1949,  1950,  1890,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1026,    -1,    -1,    -1,
      -1,  1904,    -1,    -1,    -1,    -1,  1909,  1910,  1911,    -1,
      -1,    -1,  1042,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1910,  1911,    -1,  1927,    -1,    -1,  1930,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1941,  1933,
      -1,  1930,  1945,  2007,    -1,    -1,    -1,  2011,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1945,    -1,    -1,    -1,
      -1,  1091,  1092,    -1,  1094,  1095,  1096,  1970,  1098,  1099,
    1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1981,    -1,
      -1,    -1,    -1,    -1,    -1,  2050,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,  2061,    -1,    -1,
      -1,  2065,    -1,  1705,    -1,  2008,  1708,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2081,  1148,    -1,
      -1,  1723,    -1,  1725,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1740,    -1,
      -1,    -1,  1172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2059,    -1,  1188,    -1,
      -1,    -1,    -1,    -1,  2128,  2129,    -1,    -1,    -1,    -1,
    2059,    -1,  1774,    -1,  2077,  2078,  2079,  2080,  2081,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2077,  2078,
    2079,  2080,  2081,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,  1242,    -1,    -1,   246,    -1,   248,  2121,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1257,  1258,  1259,
      -1,    -1,    -1,    -1,    -1,  2138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2174,    -1,    -1,    -1,    -1,  1306,    -1,  2181,  2182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2160,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,  2181,  2182,   246,    -1,
     248,    -1,    -1,    -1,    -1,    -1,  1366,    -1,    -1,    -1,
    2195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1379,
      -1,    -1,    -1,  1383,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1437,  1438,  1439,
      -1,    55,    56,    57,    58,  1445,    -1,    -1,  2020,    63,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1460,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,  1471,    -1,    -1,    88,    89,    -1,    91,    -1,  1479,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,  2085,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    -1,    76,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2108,    90,    -1,    -1,
      93,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,  1549,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1576,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   200,    -1,  2160,    -1,
     204,    -1,    -1,    -1,    -1,   209,   210,   211,    -1,   213,
     214,   215,    -1,    -1,    -1,   219,    -1,    -1,    -1,  2181,
    2182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,   236,  2195,    -1,    -1,    -1,    -1,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,   251,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,    25,  1653,    27,    -1,    -1,    -1,    -1,   212,
      -1,    -1,    -1,   216,    -1,   218,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1679,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,  1695,    -1,    -1,   251,    -1,
     253,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,  1726,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1739,
      -1,    -1,   114,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,   141,   141,
      -1,    -1,    -1,   145,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1793,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,    -1,   177,   178,   179,    -1,   181,
     182,   183,   184,   185,   186,   187,    -1,   189,   190,   191,
     192,    -1,    -1,    -1,   196,    -1,    -1,    -1,  1828,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   261,    -1,
    1890,    -1,    -1,    -1,    -1,    -1,   268,   269,   270,   271,
     272,    -1,    -1,    -1,  1904,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,   288,   289,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1927,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   307,    -1,    -1,    -1,    -1,
      -1,  1941,    -1,    -1,    -1,   317,   318,    -1,    -1,    -1,
      -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   333,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1981,    -1,    -1,    -1,   357,   358,    -1,    -1,    -1,
     362,   363,   364,    -1,   366,    -1,    -1,    -1,   370,   371,
     372,    -1,    -1,   375,   377,   378,   379,    -1,  2008,    -1,
     383,   384,   385,   386,   387,   388,   389,    -1,   391,    -1,
      -1,    -1,   395,   396,    -1,    -1,   399,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,   413,    -1,    -1,    -1,   417,   418,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   434,   435,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,   449,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   468,   469,   470,   471,
     246,    -1,   248,    -1,   476,    -1,    -1,    -1,   480,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2121,   494,   495,    -1,    -1,    -1,   499,    -1,    -1,
      -1,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,    -1,   529,   530,    -1,
     532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   541,
      -1,    -1,   544,   545,  2174,    -1,    -1,    -1,    -1,   551,
      -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,
      -1,   564,    -1,    -1,    -1,    -1,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,    -1,   589,   590,    -1,
      -1,    -1,    -1,    -1,    -1,   597,   598,   599,    -1,    -1,
      -1,    -1,    -1,   605,   606,    -1,   608,   609,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   627,   628,   629,    -1,    -1,
      -1,   633,   634,   635,   636,   637,   638,   639,   640,   641,
      -1,    -1,    -1,    -1,    -1,   647,    -1,   649,    -1,    -1,
     652,    -1,    -1,    -1,   656,   657,   658,   659,    -1,   661,
     662,   663,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,   688,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     702,    -1,    -1,    -1,    -1,    -1,    -1,   709,    -1,   711,
      -1,    -1,   714,   715,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   723,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   736,    -1,   738,    -1,    -1,    -1,
      -1,   743,   744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   758,    -1,   760,   761,
      -1,    -1,   764,   765,    -1,    -1,    -1,   769,    -1,   771,
      -1,    -1,    -1,    -1,    -1,   777,     4,     5,    -1,   781,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   807,    -1,   809,    -1,   811,
      -1,   288,   289,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,     6,    -1,    -1,    67,
      68,    69,   844,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,   854,   855,   856,    -1,   333,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,    -1,   870,    -1,    97,
       7,     8,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,
      -1,   358,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
     892,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   904,    -1,   905,    -1,   133,    -1,    -1,    -1,    -1,
      -1,   913,    -1,    -1,    -1,   917,    -1,    -1,    -1,    -1,
      -1,   923,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   931,
     932,    -1,    -1,    -1,    -1,   937,    -1,    -1,    -1,    -1,
     417,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   954,    -1,    -1,   957,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,   203,   978,     6,   980,   981,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,   216,    -1,
     218,   219,    -1,    -1,    -1,    -1,    -1,   999,    -1,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,   495,    -1,
    1022,   246,    -1,   251,    -1,    -1,    -1,  1029,    -1,    -1,
      -1,    -1,  1034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   519,    -1,    -1,    -1,    -1,  1049,  1050,   526,
     527,    -1,    -1,  1055,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,   551,  1078,   246,    -1,    -1,   556,
      -1,    -1,    -1,  1085,  1086,  1087,  1088,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   582,    -1,    -1,  1110,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1126,    -1,    -1,    -1,    -1,    -1,
      -1,   608,   609,    -1,  1136,  1137,  1138,    -1,    -1,    -1,
      -1,  1143,  1144,    -1,  1146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1160,  1161,
      -1,    -1,    -1,    -1,    -1,    -1,  1168,  1169,    -1,    -1,
    1173,    -1,    -1,  1175,    -1,  1177,  1178,    -1,    -1,   656,
     657,   658,  1184,  1185,    -1,    -1,    -1,  1189,  1190,    -1,
      -1,    -1,    -1,     4,     5,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,  1221,
      -1,    -1,    -1,    -1,    -1,   702,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,  1256,    -1,    67,    68,    69,   736,
      -1,    -1,    -1,    74,    -1,    76,  1268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1276,    -1,    -1,    -1,    -1,    90,
      -1,   758,    93,    -1,    -1,    -1,    97,   764,    -1,   100,
      -1,    -1,   103,    -1,   105,  1297,  1298,    -1,    -1,    -1,
    1302,     6,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,  1313,    -1,    -1,  1316,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,  1326,  1327,    -1,    -1,    -1,    -1,     6,
      -1,    -1,   809,    -1,   811,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1344,    -1,    -1,  1347,  1348,  1349,  1350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1358,    -1,  1360,    -1,
    1362,  1363,  1364,     6,    -1,    -1,    -1,   844,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   854,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,   216,    -1,   218,   219,    -1,
      -1,    -1,    -1,  1416,    -1,   892,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1426,    -1,    -1,    -1,    -1,   905,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,   250,
     251,    -1,  1444,    -1,    -1,    -1,   923,    -1,    -1,  1451,
    1452,  1453,    -1,    -1,    -1,    -1,    -1,    -1,  1460,    -1,
    1462,    -1,    -1,    -1,    -1,    -1,    -1,  1469,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1483,    -1,    -1,    -1,    -1,  1488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1496,  1497,  1498,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1508,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1518,    -1,    -1,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,  1541,
      -1,   246,    -1,    -1,    -1,  1547,  1548,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1580,  1055,  1581,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1621,
    1622,  1623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1632,    -1,    -1,  1110,    -1,  1637,  1638,  1639,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1651,
      -1,    -1,    -1,    -1,  1656,  1657,  1658,    -1,  1660,    -1,
      -1,    -1,    -1,    -1,  1666,  1667,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1685,    -1,    -1,    -1,    -1,  1690,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1703,    -1,    -1,  1706,    -1,    -1,    -1,  1710,    -1,
      -1,    -1,  1189,  1190,    -1,    -1,    -1,  1719,  1720,    -1,
    1722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1730,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1746,    -1,    -1,    -1,    -1,  1751,
    1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1765,    -1,   439,  1768,  1769,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    -1,
      -1,  1268,   113,   114,   115,   116,    -1,     6,   119,    -1,
      -1,    -1,    -1,  1805,  1806,   126,   127,    -1,    -1,   130,
     131,    -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,
    1822,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1831,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,  1840,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1849,  1850,    -1,
      -1,  1853,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,
      -1,  1348,    -1,  1350,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1887,  1888,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1907,    -1,    -1,  1910,  1911,
    1912,    -1,    -1,    -1,    -1,  1917,    -1,    -1,  1920,   593,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1930,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1945,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1953,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,  1978,    -1,    -1,    -1,
      -1,    -1,  1984,    -1,    -1,  1987,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,  1483,    -1,   246,    -1,
      -1,    -1,    -1,    -1,  2016,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,  2041,
    2042,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2055,  2056,    -1,  2058,  2059,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
    2072,    -1,    -1,    -1,    -1,  2077,  2078,  2079,  2080,  2081,
      -1,    -1,    -1,    -1,    -1,  2087,    -1,    -1,    -1,  2091,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1581,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,  2119,    -1,    -1,
      -1,    -1,  2124,  2125,  2126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2138,    -1,    -1,    -1,
      -1,    -1,   816,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,    -1,   828,   829,   830,   831,    -1,   833,
     834,   835,   836,    -1,  2166,  2167,  2168,    -1,    -1,    -1,
      -1,    -1,    -1,   847,    -1,   849,    -1,    -1,    -1,  1656,
    1657,    -1,    -1,    -1,    -1,   859,    -1,    -1,    -1,    -1,
      -1,    -1,   866,   867,    -1,    -1,    -1,     3,     4,    -1,
      -1,   875,    -1,    -1,    10,    11,    12,    -1,  1685,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    -1,    91,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,   985,   986,   987,    -1,    -1,    -1,   991,   992,    -1,
      -1,   995,   996,   997,   998,    -1,  1000,    -1,  1805,  1806,
      -1,  1005,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1840,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1853,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,   204,    -1,
      -1,    -1,    -1,   209,   210,   211,    -1,   213,   214,   215,
    1084,    -1,     6,   219,    -1,  1089,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
     236,    -1,    -1,  1910,  1911,    -1,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,   251,    -1,    -1,   254,    -1,
      -1,    -1,    -1,  1930,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1945,    -1,
       3,     4,     5,    -1,   137,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,  1186,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    -1,    76,    77,    78,    79,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,
      93,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,  2059,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2077,  2078,  2079,  2080,  2081,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
      -1,  1325,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2138,    -1,    -1,    -1,    -1,    -1,   200,   201,   202,
     203,   204,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,    -1,   218,   219,    -1,    -1,    -1,
      -1,  1365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,   236,    -1,    -1,    13,    14,    -1,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   251,    -1,
      -1,   254,    -1,  1397,  1398,  1399,  1400,  1401,    -1,    -1,
      -1,    -1,  1406,  1407,    -1,    -1,    -1,    -1,  1412,    -1,
    1414,    -1,    -1,    -1,  1418,    -1,    -1,  1421,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1433,
      -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    -1,    -1,    -1,   113,   114,   115,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,   130,   131,     8,   133,   134,    -1,   136,
    1504,    -1,  1506,    -1,    -1,    -1,  1510,    -1,  1512,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,  1543,
     177,   178,   179,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   252,    -1,    67,    68,    69,
      -1,    -1,    72,    73,    74,    -1,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,  1640,    -1,    88,    89,
      90,    91,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,
     100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
      -1,   131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,
      -1,   141,   142,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,  1742,    -1,
      -1,  1745,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   201,   202,   203,   204,   205,     8,    -1,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   218,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,
    1794,  1795,   242,  1797,    -1,    -1,    -1,   247,    -1,    -1,
      -1,   251,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,  1857,  1858,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    73,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,  1905,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       8,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,     8,    -1,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,   218,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
     251,    -1,    -1,   254,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    -1,    76,    77,    78,
      79,    -1,    -1,  2147,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,     8,   246,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,   218,
     219,   220,   221,   222,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   235,   236,    -1,    -1,
      -1,    -1,    -1,   242,   243,   244,    -1,    -1,   247,    -1,
     249,     3,     4,     5,   253,   254,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,
      -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,    -1,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,   247,     3,     4,    -1,   251,
      -1,     8,   254,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,
     247,     3,     4,     5,    -1,   252,    -1,   254,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,
      -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,   248,    -1,   250,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,    -1,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,   247,     3,     4,    -1,   251,
      -1,    -1,   254,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,
     247,     3,     4,    -1,   251,   252,    -1,   254,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,
      -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,    -1,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,   247,     3,     4,    -1,   251,
      -1,    -1,   254,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,
     247,     3,     4,    -1,   251,    -1,    -1,   254,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,
      -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,    -1,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,   247,     3,     4,    -1,   251,
      -1,    -1,   254,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,
     247,     3,     4,    -1,    -1,   252,    -1,   254,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,
      -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,    -1,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,   247,     3,     4,    -1,   251,
      -1,    -1,   254,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,
     247,     3,     4,    -1,   251,    -1,    -1,   254,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,
      -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,    -1,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,   247,     3,     4,    -1,   251,
      -1,     8,   254,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,    -1,
     247,     8,    -1,    10,    11,    12,    -1,   254,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,    -1,
     247,    -1,    -1,    10,    11,    12,    -1,   254,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,
     247,     3,     4,    -1,   251,    -1,    -1,   254,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,
      -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,    -1,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,   247,     3,     4,    -1,   251,
      -1,    -1,   254,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    -1,   204,   205,    -1,
      -1,    -1,   209,   210,   211,    -1,   213,   214,   215,    -1,
      -1,    -1,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,     3,     4,     5,    -1,
     247,    -1,    -1,    10,    11,    12,    -1,   254,    15,    16,
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
      -1,    -1,    -1,   200,   201,   202,   203,   204,    -1,    -1,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,   251,    -1,    -1,   254,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,   200,   201,   202,   203,   204,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
     236,    -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,
      -1,   247,     3,     4,     5,   251,    -1,    -1,   254,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    -1,    93,     3,     4,    -1,    -1,    -1,     8,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,   202,   203,   204,    -1,    -1,    -1,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,   218,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
     200,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,
      -1,    -1,   242,     3,     4,    -1,    -1,   247,    -1,    -1,
      10,    11,    12,    -1,   254,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
     200,    -1,    -1,   246,   204,    -1,    -1,    -1,   251,   209,
     210,   211,    -1,   213,   214,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,
      -1,    -1,   242,    -1,    -1,    -1,    -1,   247,   248,    -1,
      -1,    -1,    -1,    -1,   254,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,   200,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,   209,   210,
     211,    -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,   242,     3,     4,    -1,     6,   247,    -1,    -1,    10,
      11,    12,    -1,   254,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,     3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,   200,
      -1,    -1,   246,   204,    -1,    -1,    -1,   251,   209,   210,
     211,    -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,   200,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,     3,     4,    -1,    -1,   247,    -1,    -1,    10,    11,
      12,    -1,   254,    15,    16,    17,    18,    19,    20,    21,
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
      -1,    91,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,    -1,   256,    -1,    -1,   209,   210,   211,
      -1,   213,   214,   215,    -1,    -1,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,
      -1,    -1,   254,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,   204,   256,    -1,    -1,    -1,   209,
     210,   211,    -1,   213,   214,   215,    -1,    -1,    -1,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,
      -1,    -1,   242,     3,     4,    -1,    -1,   247,   248,    -1,
      10,    11,    12,    -1,   254,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    13,    14,
      -1,   113,   114,   115,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,   204,   177,   178,   179,    -1,   209,
     210,   211,    -1,   213,   214,   215,    -1,    -1,    -1,   219,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   235,   236,    -1,   113,   114,
     115,   116,   242,    -1,   119,    13,    14,   247,    -1,    -1,
      -1,   126,   127,    -1,   254,   130,   131,    -1,   133,   134,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,
     252,    -1,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,   177,   178,   179,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,   113,   114,   115,   116,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,   130,   131,    -1,   133,   134,    -1,   136,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   177,
     178,   179,   113,   114,   115,   116,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,
     131,    -1,   133,   134,    -1,   136,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   153,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    -1,    -1,    -1,   113,
     114,   115,   116,    -1,    -1,   119,   177,   178,   179,    -1,
      -1,    -1,   126,   127,   252,    -1,   130,   131,    -1,   133,
     134,    -1,   136,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   177,   178,   179,   113,   114,   115,   116,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   252,    -1,   130,   131,    -1,   133,   134,    -1,   136,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      -1,    -1,    -1,   113,   114,   115,   116,    -1,    -1,   119,
     177,   178,   179,    -1,    -1,    -1,   126,   127,   252,    -1,
     130,   131,    -1,   133,   134,    -1,   136,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   177,   178,   179,
     113,   114,   115,   116,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   252,    -1,   130,   131,    -1,
     133,   134,    -1,   136,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,    -1,   113,   114,   115,
     116,    -1,    -1,   119,   177,   178,   179,    -1,    -1,    -1,
     126,   127,   252,    -1,   130,   131,    -1,   133,   134,    -1,
     136,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   177,   178,   179,   113,   114,   115,   116,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   252,
      -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,   113,   114,   115,   116,    -1,    -1,   119,   177,   178,
     179,    -1,    -1,    -1,   126,   127,   252,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    13,    14,    -1,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,   177,   178,   179,   246,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    -1,    86,    87,    -1,    89,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    -1,
     252,   112,   113,   114,   115,   116,   117,    -1,   119,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,    -1,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,     4,    -1,   165,   166,   167,    -1,    -1,    -1,
     171,    13,    14,    -1,    -1,   176,   177,   178,   179,    -1,
      -1,   182,    -1,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    -1,    44,    45,    -1,   206,   207,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,   219,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    86,    87,    -1,    89,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,   113,   114,   115,   116,   117,    -1,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    -1,    -1,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,   176,   177,   178,   179,     4,     5,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,    -1,    -1,   206,   207,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,   219,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,     4,     5,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,   105,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
     116,    -1,    -1,    59,    60,    61,    62,    -1,     4,     5,
      -1,    67,    68,    69,    -1,    -1,    -1,   133,    74,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,     5,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,
      76,    13,    14,    -1,    -1,   201,   202,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,   212,    93,    -1,    -1,
     216,    -1,   218,   219,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    93,   212,    -1,    -1,    -1,
     216,    -1,   218,   219,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,   113,   114,   115,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,   201,   202,   203,   140,    13,
      14,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
     216,   153,   218,    -1,    -1,   157,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,   177,   178,   179,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,   216,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    -1,    -1,    -1,   113,
     114,   115,   116,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,   130,   131,    -1,   133,
     134,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
      -1,    -1,   246,   177,   178,   179,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,    -1,   252,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,   252,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,   252,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,   252,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,    -1,   252,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,   252,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,   252,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
     252,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,   252,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,   252,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,    -1,   252,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,   252,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,   252,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,   252,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,    -1,   252,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,   252,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,   252,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
     252,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,   252,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,   252,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,    -1,   252,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,    -1,   252,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,   252,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,    -1,   252,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,    -1,   252,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,    -1,   252,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,   252,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,
     252,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,   252,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,   252,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,   251,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,
      -1,   248,    -1,   250,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
     250,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,   250,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,   250,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,   250,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,   250,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,   250,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,   250,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,   250,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,   250,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,   250,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
     250,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,   250,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,   250,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,   250,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,   250,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246,    -1,   248,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,    -1,    -1,
      -1,   246,    -1,   248,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,    -1,    -1,    -1,   246
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   258,   259,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    75,    80,    81,    82,
      83,    84,    86,    87,    89,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   112,   113,   114,   115,   116,   117,   119,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   165,   166,   167,
     171,   176,   177,   178,   179,   182,   184,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   206,   207,   208,   217,   219,   260,   262,   263,   283,
     301,   303,   307,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   325,   327,   328,   334,   335,   336,   337,   343,
     368,   369,   251,   255,    14,   103,   247,   247,     6,   251,
       6,     6,     6,     6,   247,     6,     6,   251,     6,     6,
     249,   249,     4,   345,   369,   247,   249,   281,    97,   100,
     103,   105,   281,   247,   247,   247,     4,   247,   247,   247,
       4,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   251,   118,   103,     6,   251,    97,   100,   103,
     116,   306,   105,   247,     3,    10,    11,    12,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    55,    56,    57,
      58,    63,    64,    72,    73,    77,    78,    79,    88,    91,
      97,   100,   103,   105,   116,   126,   131,   133,   136,   200,
     204,   205,   209,   210,   211,   213,   214,   215,   235,   236,
     242,   247,   251,   254,   303,   304,   307,   318,   325,   327,
     338,   339,   343,   345,   352,   354,   369,   247,   251,   251,
     103,   103,   126,   100,   103,   105,    97,   100,   103,   105,
     303,   100,   103,   105,   116,   304,   100,   103,   247,   100,
     157,   182,   198,   199,   251,   235,   236,   247,   251,   349,
     350,   349,   251,   251,   349,     4,    97,   101,   107,   108,
     110,   111,   130,   251,   247,   103,   105,   103,   100,     4,
      89,   193,   251,   369,     4,     6,    97,   100,   103,   100,
     103,   116,   305,     4,     4,     4,     5,   247,   251,   352,
     353,     4,   247,   247,   247,     4,   251,   356,   369,     4,
     247,   247,   247,     6,     6,   249,     5,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    59,    60,    61,    62,
      67,    68,    69,    74,    76,    90,    93,   201,   202,   203,
     212,   216,   218,   360,   369,   247,     4,   360,     5,   251,
       5,   251,    32,   236,   338,   369,   249,   251,   247,   251,
       6,   247,   251,     6,   255,     7,   133,   193,   220,   221,
     222,   223,   243,   244,   247,   249,   253,   279,   280,   281,
     303,   338,   359,   360,   369,     4,   307,   308,   309,   251,
       6,   338,   359,   360,   369,   359,   338,   359,   366,   367,
     369,   338,   285,   289,   247,   348,     9,   360,   247,   247,
     247,   247,   369,   338,   338,   338,   247,   338,   338,   338,
     247,   338,   338,   338,   338,   338,   338,   338,   359,   338,
     338,   338,   338,   353,   247,   236,   338,   354,   355,   251,
     353,   352,   359,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   247,   249,   281,   281,
     281,   281,   281,   281,   247,   281,   281,   247,   303,   304,
     304,   281,   281,     5,   251,   251,   126,   303,   303,   247,
     281,   281,   247,   247,   247,   338,   251,   338,   354,   338,
     338,   252,   355,   345,   369,   185,     5,   251,     8,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   246,     9,   247,
     249,   253,   280,   281,   338,   355,   355,   247,   247,   247,
     352,   353,   353,   353,   302,   251,   247,   352,   251,   251,
     338,     4,   352,   251,   356,   251,   251,   349,   349,   349,
     338,   338,   235,   236,   251,   251,   349,   235,   236,   247,
     309,   349,   251,   247,   251,   247,   247,   247,   247,   247,
     247,   247,   355,   338,   353,   353,   353,   247,     4,   249,
     251,     6,   249,   309,     6,     6,   251,   251,   251,   251,
     353,   249,   249,   249,   338,     8,     6,     6,   338,   338,
     338,   253,   338,   251,   185,   338,   338,   338,   338,   281,
     281,   281,   247,   247,   247,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   247,   247,   281,   247,   249,
       6,     6,   251,     6,     8,   309,     6,     8,   309,   281,
     338,   237,   251,     9,   247,   249,   253,   359,   355,   338,
     309,   352,   352,   251,   360,   303,     7,   338,   338,     4,
     182,   183,   352,     6,   248,   250,   251,   282,   251,     6,
     251,     6,     9,   247,   249,   253,   369,   252,   126,   131,
     133,   134,   136,   301,   303,   338,     6,   248,   256,     9,
     247,   249,   253,   248,   256,   256,   248,   256,     9,   247,
     253,   256,   250,   256,   284,   250,   284,    92,   347,   344,
     369,   256,   338,   338,   338,   338,   256,   248,   248,   248,
     338,   248,   248,   248,   338,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   252,     7,   338,   237,
     252,   256,   338,     6,     6,   248,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   354,   338,   338,   338,   338,   338,   338,
     338,   354,   354,   369,   251,   338,   338,   359,   338,   359,
     352,   359,   359,   366,   251,   251,   251,   338,   282,   369,
       8,   338,   338,   353,   352,   359,   359,   354,   345,   360,
     345,   355,   248,   252,   253,   281,    64,     8,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   251,   338,   354,   338,   338,   338,   338,   338,
     369,   338,   338,     4,   346,   251,   282,   248,   252,   252,
     338,   338,   338,     7,     7,   331,   331,   247,   338,   338,
       6,   355,   355,   251,   248,     6,   309,   251,   309,   309,
     256,   256,   256,   349,   349,   308,   308,   256,   338,   252,
     322,   256,   309,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   252,   248,     7,   332,     6,     7,   338,     6,
     338,   309,   338,   252,   355,   355,   355,   338,     6,   338,
     338,   338,   248,   252,   248,   248,   248,   182,   256,   309,
     251,     8,   248,   248,   250,   366,   359,   366,   359,   359,
     359,   359,   359,   359,   338,   359,   359,   359,   359,   254,
     362,   369,   360,   359,   359,   359,   345,   369,   355,   252,
     252,   252,   252,   338,   338,   309,   369,   346,   250,   252,
     248,   140,   157,   326,   248,   252,   256,   338,     6,   251,
     352,   248,   250,     7,   279,   280,   253,     7,     6,   355,
       7,   220,   279,   338,   264,   369,   338,   338,   346,   249,
     247,   126,   303,   304,   303,   251,   252,     6,   231,   234,
     261,   355,   369,   338,   338,     4,   346,     6,   355,   338,
       6,   359,   367,   369,   248,   346,   338,     6,   369,     6,
     359,   338,   248,   249,   338,   256,   256,   256,   256,   360,
       7,     7,     7,   248,     7,     7,     7,   248,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   338,   248,
     251,   338,   354,   252,     6,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   256,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   256,   256,   256,   248,
     250,   250,   355,   256,   256,   282,   256,   282,   256,   256,
     256,   248,   355,   338,   338,   340,   282,   252,   252,   252,
     256,   256,   282,   282,   248,   253,   248,   253,   256,   281,
     341,   252,     7,   346,   282,   251,   252,     8,     8,   355,
     253,   248,   250,   280,   247,   249,   281,   355,     7,   251,
     251,   248,   248,   248,   338,   352,     4,   330,     6,   298,
     338,   360,   252,   248,   252,   252,   355,   253,   252,   309,
     252,   252,   349,   338,   338,   252,   252,   338,   349,   137,
     137,   154,   162,   163,   164,   168,   169,   323,   324,   349,
     252,   319,   248,   252,   248,   248,   248,   248,   248,   248,
     248,   251,     7,   338,     6,   338,   248,   250,   252,   250,
     252,   252,   252,   252,   250,   250,   256,     7,     7,     7,
     253,   338,   252,   338,   338,     7,   253,   282,   256,   282,
     282,   248,   248,   256,   282,   282,   256,   256,   282,   282,
     282,   282,   338,   282,     9,   361,   256,   248,   256,   282,
     253,   256,   342,   250,   252,   252,   253,   247,   249,   255,
     185,     7,   157,     6,   338,   252,   251,     6,   352,   252,
     338,     6,     7,   279,   280,   253,   279,   280,   360,   338,
       6,     4,   251,   357,   369,   252,    46,    46,   352,   252,
       4,   172,   173,   174,   175,   252,   267,   271,   274,   276,
     277,   253,   248,   250,   247,   338,   338,   247,   251,   247,
     251,     8,   355,   359,   248,   253,   248,   250,   247,   248,
     256,   253,   247,   256,     7,   281,     4,   292,   293,   294,
     282,   338,   338,   338,   338,   282,   349,   352,   352,     7,
     352,   352,   352,     7,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,     6,     7,   355,   338,   338,   338,
     338,   252,   338,   338,   338,   352,   359,   359,   252,   252,
     252,   256,   291,   338,   338,   346,   346,   338,   338,   248,
     352,   281,   338,   338,   338,   252,   346,   280,   253,   280,
     338,   338,   282,   252,   352,   355,   355,     7,     7,     7,
     137,   329,     6,   248,   256,     7,     7,     7,   252,     4,
     252,   256,   256,   256,   252,   252,   115,     4,     6,   338,
     251,     6,   247,     6,   170,     6,   170,   252,   324,   256,
     323,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     308,   352,     6,   251,     6,     6,     6,   103,     7,     6,
       6,   338,   352,   352,   352,     4,   256,     8,     8,   248,
       4,   106,   107,     4,   355,   359,   338,   359,   254,   256,
     295,   359,   359,   346,   359,   248,   256,   346,   251,   303,
     251,     6,   338,     6,   251,   352,   252,   252,   338,     6,
       4,   182,   183,   338,     6,     6,     6,     7,   356,   358,
       6,   249,   282,   281,   281,     6,   268,   247,   247,   251,
     278,     6,   346,   253,   359,   338,   250,   248,   338,     8,
     355,   338,   355,   252,   252,     6,     6,   261,   346,   253,
     338,     6,   338,   346,   248,   338,   251,   338,   360,   282,
      46,   251,   352,   360,   363,   250,   256,     6,   248,   248,
     248,   248,     6,     6,   130,   300,   300,   352,     6,     6,
       6,   352,   137,   185,   299,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   252,   282,   282,   282,   282,
     282,   256,   256,   256,   248,   282,   282,   293,   282,   248,
     282,   248,   281,   341,   282,     6,   282,   256,   247,   249,
     281,     4,   248,   250,   282,     6,   252,   252,   352,   352,
     352,     4,     6,   279,   338,   352,   251,   251,     7,     6,
       7,   338,   338,   338,   251,   251,   251,   249,     6,   338,
     352,   338,     6,     6,   338,   349,   252,     5,   352,   251,
     251,   251,   251,   251,   251,   251,   352,   252,     6,   355,
     251,   338,   250,     6,     6,   181,   338,   338,   338,     6,
       6,     6,     6,     7,   282,   256,   256,   282,   256,   338,
       4,   197,   296,   297,   282,   248,   282,   342,   360,   247,
     249,   338,   251,   309,     6,   309,   256,     6,     6,     7,
     279,   280,   253,     7,     6,   356,   252,   256,   338,   279,
     251,   282,   364,   365,   366,   364,   247,   338,   338,   351,
     352,   251,   247,     4,     6,   248,     6,   248,   252,   252,
     248,   252,     6,     6,   359,   247,     4,   248,   256,   247,
     252,   352,   360,     7,   281,   290,   338,   354,   294,     6,
       6,     6,     6,   349,     6,     6,     6,     6,    97,   116,
     101,     6,     5,   251,   338,   338,   338,   338,   248,   341,
     338,   338,   338,   282,   280,   251,   251,     6,   299,     6,
     338,   352,     4,     6,   355,   355,   338,   338,   360,   252,
     248,   252,   256,   308,   308,   338,   338,   252,   256,   248,
     252,   256,     6,     6,   351,   349,   349,   349,   349,   349,
     236,   349,     6,   252,   338,     6,     6,   352,   252,   256,
       8,   252,   248,   251,   338,   360,   359,   338,   359,   338,
     360,   363,   365,   360,   256,   248,   256,   252,   338,   326,
     326,   352,   360,   338,     6,     4,   357,     6,   356,   250,
     352,   366,     6,   282,   282,   265,   338,   256,   256,   252,
     256,   266,   338,   338,     6,     6,     6,     6,   338,   338,
     248,     6,   286,   288,   251,   365,   252,   256,     7,     7,
     251,   251,   251,     5,   351,   282,   282,   256,   282,   248,
     256,   248,   250,   355,   355,     6,     6,   251,   252,   252,
     251,     6,     6,   251,   338,   252,   252,   252,   250,     6,
     352,     7,   251,   338,   252,   256,   256,   256,   256,   256,
     256,     6,   252,   180,   338,   338,   355,     6,     6,   248,
     282,   282,   297,   360,   252,   252,   252,   252,     6,     6,
       7,     6,   253,     6,   252,     6,     6,   248,   256,   338,
     338,   251,   352,   252,   256,   248,   248,   256,   291,   295,
     352,   282,   338,   360,   369,   355,   355,   338,     6,   252,
     338,   341,   338,   252,   252,   351,   141,   142,   147,   333,
     141,   142,   333,   355,   308,   252,   256,     6,   252,   352,
     309,   252,     6,   355,   349,   349,   349,   349,   349,   338,
     252,   252,   252,   248,     6,   251,     6,   356,   183,   269,
     338,   256,   256,   351,     6,   338,   338,   252,   252,   287,
       7,   247,   252,   252,   252,   251,   256,   248,   256,   251,
     252,   251,   349,   352,     6,   251,   349,     6,   252,   252,
     338,     6,   137,   252,   320,   251,   252,   256,   256,   256,
     256,   256,     6,     6,     6,   309,     6,   251,   338,   338,
     252,   256,   291,   360,   248,   338,   338,   338,   355,     6,
     349,     6,   349,     6,     6,   252,   338,   323,   309,     6,
     355,   355,   355,   355,   349,   355,   326,   266,   248,   256,
       6,   251,   338,   252,   256,   256,   256,   252,   256,   256,
       6,   252,   252,   321,   252,   252,   252,   252,   256,   252,
     252,   252,   272,   338,   351,   252,   338,   338,   338,   349,
     349,   323,     6,     6,     6,     6,   355,     6,     6,     6,
     251,   248,   252,     6,   252,   282,   256,   256,   256,   252,
     252,   270,   359,   275,   251,     6,   338,   338,   338,     6,
     252,   256,   251,   351,   252,   252,   252,     6,   359,   273,
     359,   252,     6,     6,   252,   256,     6,     6,   359
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   257,   258,   258,   259,   259,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   261,   261,   262,   262,
     262,   262,   262,   262,   263,   263,   263,   263,   264,   264,
     264,   264,   264,   264,   265,   265,   266,   266,   268,   269,
     267,   270,   270,   272,   271,   273,   273,   275,   274,   276,
     276,   278,   277,   279,   279,   279,   279,   279,   280,   280,
     281,   281,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   284,   285,   285,   285,   286,   285,   287,   285,
     285,   288,   285,   289,   289,   290,   290,   290,   291,   291,
     292,   292,   293,   293,   294,   294,   294,   294,   294,   295,
     295,   296,   296,   297,   297,   297,   297,   297,   298,   298,
     298,   299,   299,   299,   299,   300,   300,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   302,
     301,   303,   303,   303,   303,   303,   304,   304,   304,   304,
     305,   305,   305,   306,   306,   306,   306,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   308,   308,   309,   309,
     309,   309,   309,   309,   309,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   311,   311,   311,
     311,   311,   311,   311,   311,   312,   312,   313,   314,   314,
     314,   314,   314,   314,   314,   314,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   318,   318,   318,   319,   318,   320,   318,
     321,   318,   322,   318,   318,   318,   318,   318,   318,   323,
     323,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   325,   325,   325,   325,   325,   326,   326,   326,
     326,   326,   327,   327,   328,   329,   329,   330,   330,   331,
     331,   332,   332,   333,   333,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   335,   335,   335,   336,   336,   336,   337,   337,   337,
     337,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   340,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   341,   341,   342,   342,
     344,   343,   345,   345,   346,   347,   347,   348,   348,   349,
     349,   349,   349,   349,   350,   350,   350,   350,   351,   351,
     352,   352,   352,   352,   352,   352,   353,   353,   353,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   355,   355,   355,   355,   356,   356,   356,   356,   357,
     357,   358,   358,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   360,   360,   361,   360,   360,   362,   362,   363,   364,
     364,   365,   366,   366,   366,   366,   367,   367,   367,   368,
     368,   368,   369,   369,   369
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
       3,     0,     5,     5,     5,     0,     2,     7,     7,     7,
       8,     8,     7,     7,    11,     7,     8,     8,     8,     9,
       3,     4,    10,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     8,     7,     7,     8,     8,    12,     0,
       9,     1,     1,     1,     1,     4,     1,     1,     1,     4,
       1,     1,     4,     1,     1,     1,     4,     5,    11,     5,
       9,     9,     7,     4,     9,     9,     1,     1,     0,     2,
       6,     7,     7,     6,     7,     8,    10,    14,    16,    12,
      14,    14,    14,    14,     8,     8,     6,     4,     5,     5,
       6,     6,     3,     4,     3,     5,     6,     5,     4,     3,
       4,     3,     4,     5,     4,     5,     3,     5,     7,     7,
       3,     7,     3,     2,     2,     2,     2,     2,    15,     2,
       2,     2,     9,     2,     2,     2,     2,    16,    11,     6,
       8,     8,    10,     1,     2,     2,     1,     3,     3,     4,
       4,     1,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     9,     2,     3,    10,    13,     1,
       2,     5,     7,     2,     2,     3,     2,     3,     2,     3,
       9,     6,     1,     1,     1,     1,     1,     0,     2,     3,
       3,     4,     9,     4,    14,     0,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     6,     7,     6,     5,     3,
       8,     8,     8,     8,     8,     5,     4,     6,    11,    11,
      18,    18,    12,    12,    12,    10,     4,     4,     4,     4,
       4,     2,     3,     6,     1,     1,     1,     2,     5,     7,
      10,     1,     3,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     1,     4,     6,     1,     4,     4,     4,     6,     5,
       7,     8,    10,     4,     4,     6,     4,     3,     2,     5,
       5,     3,     5,     6,     8,     6,     8,     6,     4,     7,
       6,     6,     6,     4,     6,     4,     0,     2,     0,     2,
       0,     7,     1,     3,     1,     1,     2,     0,     3,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     3,     1,     2,
       3,     3,     5,     4,     4,     2,     4,     2,     3,     3,
      16,     5,     5,     5,     1,     1,     1,     3,     5,     7,
       4,     4,     4,     6,     6,     8,     8,     4,    14,     4,
       4,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     4,     4,     3,     5,     6,
       8,     6,     4,     5,     1,     4,     1,     1,     1,     1,
       4,     6,     4,     6,     5,     7,     4,     4,     4,     8,
       4,     4,     4,     4,     8,     8,     6,     4,     6,     4,
       1,     4,     4,     0,     6,     4,     2,     4,     4,     1,
       1,     3,     1,     1,     3,     3,     3,     5,     7,     5,
       5,     8,     1,     1,     4
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
#line 270 "Gmsh.y" /* yacc.c:1652  */
    { yyerrok; return 1; }
#line 6015 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 281 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6021 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 282 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6027 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 283 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6033 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 285 "Gmsh.y" /* yacc.c:1652  */
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
#line 6056 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 303 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6062 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 304 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6068 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 305 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6074 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 306 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6080 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 307 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6086 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 308 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6092 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 309 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6098 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 310 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6104 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 311 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6110 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 312 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6116 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 313 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6122 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 314 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6128 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 315 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6134 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 316 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6140 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 317 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6146 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 318 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6152 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 323 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"w";
    }
#line 6160 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 327 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"a";
    }
#line 6168 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 334 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6177 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 339 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6186 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 344 "Gmsh.y" /* yacc.c:1652  */
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
#line 6204 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 358 "Gmsh.y" /* yacc.c:1652  */
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
#line 6221 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 371 "Gmsh.y" /* yacc.c:1652  */
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
#line 6238 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 384 "Gmsh.y" /* yacc.c:1652  */
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
#line 6265 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 412 "Gmsh.y" /* yacc.c:1652  */
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
#line 6283 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 426 "Gmsh.y" /* yacc.c:1652  */
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
#line 6300 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 439 "Gmsh.y" /* yacc.c:1652  */
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
#line 6317 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 452 "Gmsh.y" /* yacc.c:1652  */
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
#line 6336 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 470 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 6346 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 484 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6352 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 486 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6358 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 491 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6364 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 493 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6370 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 498 "Gmsh.y" /* yacc.c:1652  */
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
#line 6478 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 602 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(std::size_t j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 6492 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 612 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 6502 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 621 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6513 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 628 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6524 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 638 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 6537 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 647 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 6547 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 656 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6558 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 663 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6569 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 673 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 6581 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 681 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 6591 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 691 "Gmsh.y" /* yacc.c:1652  */
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
#line 6611 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 710 "Gmsh.y" /* yacc.c:1652  */
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
#line 6631 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 729 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 6641 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 735 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 6648 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 742 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 6654 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 743 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6660 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 744 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 6666 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 745 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 6672 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 746 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 4; }
#line 6678 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 750 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6684 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 751 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = -1; }
#line 6690 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 757 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"("; }
#line 6696 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 757 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"["; }
#line 6702 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 758 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)")"; }
#line 6708 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 758 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"]"; }
#line 6714 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 77:
#line 768 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 6723 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 78:
#line 773 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 6733 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 79:
#line 779 "Gmsh.y" /* yacc.c:1652  */
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
#line 6799 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 80:
#line 841 "Gmsh.y" /* yacc.c:1652  */
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
#line 6818 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 81:
#line 856 "Gmsh.y" /* yacc.c:1652  */
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
#line 6851 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 82:
#line 885 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 6862 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 83:
#line 895 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6871 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 84:
#line 900 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6880 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 85:
#line 908 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6889 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 86:
#line 913 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6898 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 87:
#line 921 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 6908 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 88:
#line 930 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 6917 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 89:
#line 935 "Gmsh.y" /* yacc.c:1652  */
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
#line 6933 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 90:
#line 947 "Gmsh.y" /* yacc.c:1652  */
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
#line 6951 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 91:
#line 964 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6961 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 92:
#line 970 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6971 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 93:
#line 979 "Gmsh.y" /* yacc.c:1652  */
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
#line 6993 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 94:
#line 997 "Gmsh.y" /* yacc.c:1652  */
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
#line 7015 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 95:
#line 1015 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 7028 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 96:
#line 1024 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 7041 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 97:
#line 1036 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 7050 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 98:
#line 1041 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 7059 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 99:
#line 1049 "Gmsh.y" /* yacc.c:1652  */
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
#line 7083 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 100:
#line 1069 "Gmsh.y" /* yacc.c:1652  */
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
#line 7107 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 101:
#line 1092 "Gmsh.y" /* yacc.c:1652  */
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
#line 7131 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 102:
#line 1112 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 7143 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 103:
#line 1120 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Box");
#endif
    }
#line 7154 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 104:
#line 1127 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Cylinder");
#endif
    }
#line 7165 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 105:
#line 1134 "Gmsh.y" /* yacc.c:1652  */
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
#line 7191 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 106:
#line 1156 "Gmsh.y" /* yacc.c:1652  */
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
#line 7218 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 107:
#line 1179 "Gmsh.y" /* yacc.c:1652  */
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
#line 7260 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 108:
#line 1217 "Gmsh.y" /* yacc.c:1652  */
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
#line 7282 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 109:
#line 1238 "Gmsh.y" /* yacc.c:1652  */
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
#line 7298 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 110:
#line 1250 "Gmsh.y" /* yacc.c:1652  */
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
#line 7314 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 114:
#line 1268 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 7327 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 115:
#line 1277 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 7340 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 116:
#line 1286 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7346 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 117:
#line 1288 "Gmsh.y" /* yacc.c:1652  */
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
#line 7368 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 118:
#line 1306 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7374 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 119:
#line 1308 "Gmsh.y" /* yacc.c:1652  */
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
#line 7394 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 120:
#line 1324 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 7407 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 121:
#line 1333 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7413 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 122:
#line 1335 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 7427 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 124:
#line 1349 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 7437 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 125:
#line 1357 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7447 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 126:
#line 1363 "Gmsh.y" /* yacc.c:1652  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7456 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 127:
#line 1368 "Gmsh.y" /* yacc.c:1652  */
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
#line 7485 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 134:
#line 1411 "Gmsh.y" /* yacc.c:1652  */
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
#line 7501 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 135:
#line 1423 "Gmsh.y" /* yacc.c:1652  */
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
#line 7518 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 136:
#line 1436 "Gmsh.y" /* yacc.c:1652  */
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
#line 7536 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 137:
#line 1451 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7548 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 138:
#line 1460 "Gmsh.y" /* yacc.c:1652  */
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
#line 7563 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 143:
#line 1485 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 7574 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 144:
#line 1493 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7586 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 145:
#line 1502 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 7597 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 146:
#line 1510 "Gmsh.y" /* yacc.c:1652  */
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
#line 7614 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 147:
#line 1524 "Gmsh.y" /* yacc.c:1652  */
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
#line 7631 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 148:
#line 1542 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 7639 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 149:
#line 1546 "Gmsh.y" /* yacc.c:1652  */
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[0].c)), dim_entity, t + 1);
      Free((yyvsp[0].c));
    }
#line 7650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 150:
#line 1553 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), dim_entity, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 7659 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 151:
#line 1561 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 7667 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 152:
#line 1565 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[-1].d);
      List_Add((yyval.l), &p);
    }
#line 7677 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 153:
#line 1571 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7685 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 154:
#line 1575 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[-1].l), i));
      List_Delete((yyvsp[-1].l));
    }
#line 7698 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 155:
#line 1586 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 7706 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 156:
#line 1590 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 7714 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 157:
#line 1597 "Gmsh.y" /* yacc.c:1652  */
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
#line 7741 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 158:
#line 1620 "Gmsh.y" /* yacc.c:1652  */
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
#line 7761 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 159:
#line 1636 "Gmsh.y" /* yacc.c:1652  */
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
#line 7781 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 160:
#line 1652 "Gmsh.y" /* yacc.c:1652  */
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
#line 7822 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 161:
#line 1689 "Gmsh.y" /* yacc.c:1652  */
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
#line 7862 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 162:
#line 1725 "Gmsh.y" /* yacc.c:1652  */
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
#line 7882 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 163:
#line 1741 "Gmsh.y" /* yacc.c:1652  */
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
#line 7902 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 164:
#line 1758 "Gmsh.y" /* yacc.c:1652  */
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
#line 7937 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 165:
#line 1789 "Gmsh.y" /* yacc.c:1652  */
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
#line 7957 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 166:
#line 1805 "Gmsh.y" /* yacc.c:1652  */
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
#line 7978 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 167:
#line 1822 "Gmsh.y" /* yacc.c:1652  */
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
#line 7998 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 168:
#line 1838 "Gmsh.y" /* yacc.c:1652  */
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
#line 8052 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 169:
#line 1888 "Gmsh.y" /* yacc.c:1652  */
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
#line 8074 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 170:
#line 1906 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8084 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 171:
#line 1912 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8094 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 172:
#line 1918 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 8105 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 173:
#line 1925 "Gmsh.y" /* yacc.c:1652  */
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
#line 8140 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 174:
#line 1956 "Gmsh.y" /* yacc.c:1652  */
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
#line 8159 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 175:
#line 1971 "Gmsh.y" /* yacc.c:1652  */
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
#line 8185 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 176:
#line 1993 "Gmsh.y" /* yacc.c:1652  */
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
#line 8212 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 177:
#line 2016 "Gmsh.y" /* yacc.c:1652  */
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
#line 8239 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 178:
#line 2039 "Gmsh.y" /* yacc.c:1652  */
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
#line 8266 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 179:
#line 2062 "Gmsh.y" /* yacc.c:1652  */
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
#line 8294 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 180:
#line 2086 "Gmsh.y" /* yacc.c:1652  */
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
#line 8322 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 181:
#line 2110 "Gmsh.y" /* yacc.c:1652  */
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
#line 8350 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 182:
#line 2134 "Gmsh.y" /* yacc.c:1652  */
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
#line 8380 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 183:
#line 2160 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add surface loop");
      List_Delete((yyvsp[-1].l));
      Free((yyvsp[-6].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    }
#line 8401 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 184:
#line 2177 "Gmsh.y" /* yacc.c:1652  */
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
#line 8421 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 185:
#line 2193 "Gmsh.y" /* yacc.c:1652  */
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
#line 8443 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 186:
#line 2211 "Gmsh.y" /* yacc.c:1652  */
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
#line 8465 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 187:
#line 2229 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-6].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8476 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 188:
#line 2237 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-10].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8487 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 189:
#line 2244 "Gmsh.y" /* yacc.c:1652  */
    {
      dim_entity = (yyvsp[0].i);
    }
#line 8495 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 190:
#line 2248 "Gmsh.y" /* yacc.c:1652  */
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
#line 8522 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 191:
#line 2274 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8528 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 192:
#line 2276 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8534 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 193:
#line 2278 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8540 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 194:
#line 2280 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8546 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 195:
#line 2282 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
#line 8555 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 196:
#line 2290 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8561 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 197:
#line 2292 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8567 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 198:
#line 2294 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8573 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 199:
#line 2296 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
#line 8582 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 200:
#line 2304 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8588 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 201:
#line 2306 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8594 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 202:
#line 2308 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
#line 8603 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 203:
#line 2316 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8609 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 204:
#line 2318 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8615 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 205:
#line 2320 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8621 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 206:
#line 2322 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
#line 8630 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 207:
#line 2332 "Gmsh.y" /* yacc.c:1652  */
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
#line 8650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 208:
#line 2348 "Gmsh.y" /* yacc.c:1652  */
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
#line 8670 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 209:
#line 2364 "Gmsh.y" /* yacc.c:1652  */
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
#line 8690 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 210:
#line 2380 "Gmsh.y" /* yacc.c:1652  */
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
#line 8710 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 211:
#line 2396 "Gmsh.y" /* yacc.c:1652  */
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
#line 8730 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 212:
#line 2412 "Gmsh.y" /* yacc.c:1652  */
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
#line 8751 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 213:
#line 2429 "Gmsh.y" /* yacc.c:1652  */
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
#line 8792 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 214:
#line 2466 "Gmsh.y" /* yacc.c:1652  */
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
#line 8817 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 215:
#line 2488 "Gmsh.y" /* yacc.c:1652  */
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
#line 8842 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 216:
#line 2511 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8848 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 217:
#line 2512 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8854 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 218:
#line 2517 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 8862 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 219:
#line 2521 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 8870 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 220:
#line 2525 "Gmsh.y" /* yacc.c:1652  */
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
#line 8891 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 221:
#line 2542 "Gmsh.y" /* yacc.c:1652  */
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
#line 8915 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 222:
#line 2562 "Gmsh.y" /* yacc.c:1652  */
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
#line 8939 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 223:
#line 2582 "Gmsh.y" /* yacc.c:1652  */
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
#line 8962 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 224:
#line 2601 "Gmsh.y" /* yacc.c:1652  */
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
#line 8988 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 225:
#line 2628 "Gmsh.y" /* yacc.c:1652  */
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
#line 9011 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 226:
#line 2647 "Gmsh.y" /* yacc.c:1652  */
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
#line 9036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 227:
#line 2669 "Gmsh.y" /* yacc.c:1652  */
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
#line 9054 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 228:
#line 2684 "Gmsh.y" /* yacc.c:1652  */
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
#line 9073 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 229:
#line 2699 "Gmsh.y" /* yacc.c:1652  */
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
#line 9095 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 230:
#line 2718 "Gmsh.y" /* yacc.c:1652  */
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
#line 9149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 231:
#line 2769 "Gmsh.y" /* yacc.c:1652  */
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
#line 9173 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 232:
#line 2790 "Gmsh.y" /* yacc.c:1652  */
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
#line 9198 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 233:
#line 2812 "Gmsh.y" /* yacc.c:1652  */
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
#line 9224 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 234:
#line 2834 "Gmsh.y" /* yacc.c:1652  */
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
#line 9333 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 235:
#line 2939 "Gmsh.y" /* yacc.c:1652  */
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
#line 9353 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 236:
#line 2955 "Gmsh.y" /* yacc.c:1652  */
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
#line 9387 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 237:
#line 2990 "Gmsh.y" /* yacc.c:1652  */
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
#line 9413 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 238:
#line 3012 "Gmsh.y" /* yacc.c:1652  */
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
#line 9439 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 239:
#line 3034 "Gmsh.y" /* yacc.c:1652  */
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
#line 9455 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 240:
#line 3046 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 9465 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 241:
#line 3052 "Gmsh.y" /* yacc.c:1652  */
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
#line 9484 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 242:
#line 3067 "Gmsh.y" /* yacc.c:1652  */
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
#line 9516 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 243:
#line 3095 "Gmsh.y" /* yacc.c:1652  */
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
#line 9532 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 244:
#line 3107 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yynamespaces.clear();
    }
#line 9540 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 245:
#line 3116 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), false);
      List_Delete((yyvsp[-1].l));
    }
#line 9551 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 246:
#line 3123 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), true);
      List_Delete((yyvsp[-1].l));
    }
#line 9562 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 247:
#line 3135 "Gmsh.y" /* yacc.c:1652  */
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
#line 9581 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 248:
#line 3155 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
    }
#line 9589 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 249:
#line 3159 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[-1].c));
    }
#line 9598 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 250:
#line 3164 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
    }
#line 9606 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 251:
#line 3168 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[-1].c));
    }
#line 9615 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 252:
#line 3173 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9626 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 253:
#line 3180 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9637 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 254:
#line 3187 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9648 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 255:
#line 3194 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9659 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 256:
#line 3206 "Gmsh.y" /* yacc.c:1652  */
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
#line 9736 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 257:
#line 3279 "Gmsh.y" /* yacc.c:1652  */
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
#line 9758 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 258:
#line 3297 "Gmsh.y" /* yacc.c:1652  */
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
#line 9787 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 259:
#line 3322 "Gmsh.y" /* yacc.c:1652  */
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
#line 9806 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 260:
#line 3337 "Gmsh.y" /* yacc.c:1652  */
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
#line 9843 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 261:
#line 3370 "Gmsh.y" /* yacc.c:1652  */
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
#line 9859 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 262:
#line 3382 "Gmsh.y" /* yacc.c:1652  */
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
#line 9887 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 263:
#line 3406 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Exit(0);
    }
#line 9895 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 264:
#line 3410 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 9904 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 265:
#line 3415 "Gmsh.y" /* yacc.c:1652  */
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
#line 9915 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 266:
#line 3422 "Gmsh.y" /* yacc.c:1652  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 9924 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 267:
#line 3427 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
#line 9938 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 268:
#line 3437 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 9947 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 269:
#line 3442 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 9957 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 270:
#line 3448 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 9969 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 271:
#line 3456 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 9977 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 272:
#line 3460 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->classifySurfaces((yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 9985 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 273:
#line 3464 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    }
#line 9993 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 274:
#line 3468 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshVertices();
    }
#line 10001 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 275:
#line 3472 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshElements();
    }
#line 10009 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 276:
#line 3476 "Gmsh.y" /* yacc.c:1652  */
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 10022 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 277:
#line 3486 "Gmsh.y" /* yacc.c:1652  */
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
#line 10084 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 278:
#line 3549 "Gmsh.y" /* yacc.c:1652  */
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
#line 10100 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 279:
#line 3565 "Gmsh.y" /* yacc.c:1652  */
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
#line 10121 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 280:
#line 3582 "Gmsh.y" /* yacc.c:1652  */
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
#line 10142 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 281:
#line 3599 "Gmsh.y" /* yacc.c:1652  */
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
#line 10168 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 282:
#line 3621 "Gmsh.y" /* yacc.c:1652  */
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
#line 10194 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 283:
#line 3643 "Gmsh.y" /* yacc.c:1652  */
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
#line 10233 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 284:
#line 3678 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10245 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 285:
#line 3686 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10257 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 286:
#line 3694 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 10267 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 287:
#line 3700 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10278 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 288:
#line 3707 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10289 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 289:
#line 3714 "Gmsh.y" /* yacc.c:1652  */
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
#line 10313 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 290:
#line 3734 "Gmsh.y" /* yacc.c:1652  */
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
#line 10343 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 291:
#line 3760 "Gmsh.y" /* yacc.c:1652  */
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
#line 10359 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 292:
#line 3772 "Gmsh.y" /* yacc.c:1652  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 10369 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 293:
#line 3783 "Gmsh.y" /* yacc.c:1652  */
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
#line 10391 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 294:
#line 3801 "Gmsh.y" /* yacc.c:1652  */
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
#line 10413 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 295:
#line 3819 "Gmsh.y" /* yacc.c:1652  */
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
#line 10435 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 296:
#line 3837 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10445 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 297:
#line 3843 "Gmsh.y" /* yacc.c:1652  */
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
#line 10467 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 298:
#line 3861 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10477 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 299:
#line 3867 "Gmsh.y" /* yacc.c:1652  */
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
#line 10501 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 300:
#line 3887 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10511 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 301:
#line 3893 "Gmsh.y" /* yacc.c:1652  */
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
#line 10533 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 302:
#line 3911 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10543 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 303:
#line 3917 "Gmsh.y" /* yacc.c:1652  */
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
#line 10564 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 304:
#line 3934 "Gmsh.y" /* yacc.c:1652  */
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
#line 10584 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 305:
#line 3950 "Gmsh.y" /* yacc.c:1652  */
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
#line 10605 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 306:
#line 3967 "Gmsh.y" /* yacc.c:1652  */
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
#line 10626 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 307:
#line 3985 "Gmsh.y" /* yacc.c:1652  */
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
#line 10652 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 308:
#line 4008 "Gmsh.y" /* yacc.c:1652  */
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
#line 10680 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 309:
#line 4035 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10687 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 310:
#line 4038 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10694 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 311:
#line 4044 "Gmsh.y" /* yacc.c:1652  */
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
#line 10710 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 312:
#line 4056 "Gmsh.y" /* yacc.c:1652  */
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
#line 10734 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 313:
#line 4076 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 10742 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 314:
#line 4080 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = true;
    }
#line 10750 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 315:
#line 4084 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 10758 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 316:
#line 4088 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 10766 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 317:
#line 4092 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 10774 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 318:
#line 4096 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 10782 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 319:
#line 4100 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 10790 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 320:
#line 4104 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      int num = (int)(yyvsp[-6].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[-1].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[-3].l));
    }
#line 10803 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 321:
#line 4113 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 10815 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 322:
#line 4125 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Union; }
#line 10821 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 323:
#line 4126 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Intersection; }
#line 10827 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 324:
#line 4127 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Difference; }
#line 10833 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 325:
#line 4128 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Section; }
#line 10839 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 326:
#line 4129 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Fragments; }
#line 10845 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 327:
#line 4133 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 10851 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 328:
#line 4134 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 10857 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 329:
#line 4135 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 10863 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 330:
#line 4136 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 1 : 0; }
#line 10869 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 331:
#line 4137 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 2 : 0; }
#line 10875 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 332:
#line 4142 "Gmsh.y" /* yacc.c:1652  */
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
#line 10902 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 333:
#line 4165 "Gmsh.y" /* yacc.c:1652  */
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
#line 10922 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 334:
#line 4185 "Gmsh.y" /* yacc.c:1652  */
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
#line 10944 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 335:
#line 4206 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 10952 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 336:
#line 4210 "Gmsh.y" /* yacc.c:1652  */
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
#line 10969 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 337:
#line 4225 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = -1; // left
    }
#line 10977 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 338:
#line 4229 "Gmsh.y" /* yacc.c:1652  */
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
#line 10995 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 339:
#line 4245 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 11003 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 340:
#line 4249 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 11011 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 341:
#line 4254 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = 45;
    }
#line 11019 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 342:
#line 4258 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 11027 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 343:
#line 4264 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 11035 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 344:
#line 4268 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11043 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 345:
#line 4275 "Gmsh.y" /* yacc.c:1652  */
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
#line 11069 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 346:
#line 4297 "Gmsh.y" /* yacc.c:1652  */
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
#line 11114 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 347:
#line 4338 "Gmsh.y" /* yacc.c:1652  */
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
#line 11162 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 348:
#line 4382 "Gmsh.y" /* yacc.c:1652  */
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
#line 11205 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 349:
#line 4421 "Gmsh.y" /* yacc.c:1652  */
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
#line 11234 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 350:
#line 4446 "Gmsh.y" /* yacc.c:1652  */
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
#line 11250 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 351:
#line 4458 "Gmsh.y" /* yacc.c:1652  */
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
#line 11266 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 352:
#line 4470 "Gmsh.y" /* yacc.c:1652  */
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
#line 11282 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 353:
#line 4482 "Gmsh.y" /* yacc.c:1652  */
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
#line 11298 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 354:
#line 4494 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[-1].d);
      }
      List_Delete((yyvsp[-4].l));
    }
#line 11311 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 355:
#line 4503 "Gmsh.y" /* yacc.c:1652  */
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
#line 11345 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 356:
#line 4533 "Gmsh.y" /* yacc.c:1652  */
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
#line 11375 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 357:
#line 4559 "Gmsh.y" /* yacc.c:1652  */
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
#line 11405 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 358:
#line 4586 "Gmsh.y" /* yacc.c:1652  */
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
#line 11440 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 359:
#line 4618 "Gmsh.y" /* yacc.c:1652  */
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
#line 11470 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 360:
#line 4645 "Gmsh.y" /* yacc.c:1652  */
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
#line 11499 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 361:
#line 4671 "Gmsh.y" /* yacc.c:1652  */
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
#line 11528 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 362:
#line 4697 "Gmsh.y" /* yacc.c:1652  */
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
#line 11557 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 363:
#line 4723 "Gmsh.y" /* yacc.c:1652  */
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
#line 11586 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 364:
#line 4749 "Gmsh.y" /* yacc.c:1652  */
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
#line 11611 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 365:
#line 4770 "Gmsh.y" /* yacc.c:1652  */
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
#line 11626 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 366:
#line 4781 "Gmsh.y" /* yacc.c:1652  */
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
#line 11678 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 367:
#line 4829 "Gmsh.y" /* yacc.c:1652  */
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
#line 11736 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 368:
#line 4883 "Gmsh.y" /* yacc.c:1652  */
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
#line 11755 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 369:
#line 4898 "Gmsh.y" /* yacc.c:1652  */
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
#line 11771 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 370:
#line 4910 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-2].i), tags);
      List_Delete((yyvsp[-1].l));
    }
#line 11781 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 371:
#line 4921 "Gmsh.y" /* yacc.c:1652  */
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
#line 11792 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 372:
#line 4928 "Gmsh.y" /* yacc.c:1652  */
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
#line 11811 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 373:
#line 4943 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[-2].l));
    }
#line 11824 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 374:
#line 4956 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Homology"; }
#line 11830 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 375:
#line 4957 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 11836 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 376:
#line 4958 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Betti"; }
#line 11842 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 377:
#line 4963 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 11852 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 378:
#line 4969 "Gmsh.y" /* yacc.c:1652  */
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
#line 11868 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 379:
#line 4981 "Gmsh.y" /* yacc.c:1652  */
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
#line 11890 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 380:
#line 4999 "Gmsh.y" /* yacc.c:1652  */
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
#line 11917 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 381:
#line 5026 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11923 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 382:
#line 5027 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 11929 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 383:
#line 5028 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 11935 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 384:
#line 5029 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11941 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 385:
#line 5030 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 11947 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 386:
#line 5031 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 11953 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 387:
#line 5032 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 11959 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 388:
#line 5033 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 11965 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 389:
#line 5035 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 11976 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 390:
#line 5041 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) | (int)(yyvsp[0].d); }
#line 11982 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 391:
#line 5042 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) & (int)(yyvsp[0].d); }
#line 11988 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 392:
#line 5043 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d); }
#line 11994 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 393:
#line 5044 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 12000 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 394:
#line 5045 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 12006 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 395:
#line 5046 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 12012 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 396:
#line 5047 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 12018 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 397:
#line 5048 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 12024 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 398:
#line 5049 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 12030 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 399:
#line 5050 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 12036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 400:
#line 5051 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 12042 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 401:
#line 5052 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 12048 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 402:
#line 5053 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) >> (int)(yyvsp[0].d)); }
#line 12054 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 403:
#line 5054 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) << (int)(yyvsp[0].d)); }
#line 12060 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 404:
#line 5055 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 12066 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 405:
#line 5056 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 12072 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 406:
#line 5057 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 12078 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 407:
#line 5058 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 12084 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 408:
#line 5059 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 12090 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 409:
#line 5060 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 12096 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 410:
#line 5061 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 12102 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 411:
#line 5062 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 12108 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 412:
#line 5063 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 12114 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 413:
#line 5064 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 12120 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 414:
#line 5065 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 12126 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 415:
#line 5066 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 12132 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 416:
#line 5067 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 12138 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 417:
#line 5068 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 12144 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 418:
#line 5069 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 12150 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 419:
#line 5070 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 12156 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 420:
#line 5071 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = std::abs((yyvsp[-1].d)); }
#line 12162 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 421:
#line 5072 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 12168 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 422:
#line 5073 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 12174 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 423:
#line 5074 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 12180 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 424:
#line 5075 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12186 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 425:
#line 5076 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12192 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 426:
#line 5077 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 12198 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 427:
#line 5078 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 12204 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 428:
#line 5087 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12210 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 429:
#line 5088 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 3.141592653589793; }
#line 12216 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 430:
#line 5089 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 12222 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 431:
#line 5090 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 12228 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 432:
#line 5091 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 12234 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 433:
#line 5092 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 12240 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 434:
#line 5093 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 12246 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 435:
#line 5094 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 12252 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 436:
#line 5095 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Cpu(); }
#line 12258 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 437:
#line 5096 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 12264 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 438:
#line 5097 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = TotalRam(); }
#line 12270 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 439:
#line 5102 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 12276 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 440:
#line 5104 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 12286 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 441:
#line 5110 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12292 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 442:
#line 5112 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12301 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 443:
#line 5117 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12310 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 444:
#line 5122 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[0].c2).char1, (yyvsp[0].c2).char2);
    }
#line 12318 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 445:
#line 5127 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12326 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 446:
#line 5132 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12334 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 447:
#line 5136 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-1].c2).char1, (yyvsp[-1].c2).char2, 1, 0, 0., 1);
    }
#line 12342 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 448:
#line 5140 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-3].c2).char1, (yyvsp[-3].c2).char2, (yyvsp[-1].c), 0, 0., 1);
    }
#line 12350 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 449:
#line 5144 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-2].c2).char1, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].d), 2);
    }
#line 12358 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 450:
#line 5148 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].d), 2);
    }
#line 12366 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 451:
#line 5152 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-5].c2).char1, (yyvsp[-5].c2).char2, 2, (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12374 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 452:
#line 5156 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c2).char1, (yyvsp[-7].c2).char2, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12382 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 453:
#line 5160 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 12392 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 454:
#line 5166 "Gmsh.y" /* yacc.c:1652  */
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
#line 12411 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 455:
#line 5181 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c));
    }
#line 12419 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 456:
#line 5185 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[-1].c));
    }
#line 12429 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 457:
#line 5191 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
#line 12438 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 458:
#line 5196 "Gmsh.y" /* yacc.c:1652  */
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
#line 12461 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 459:
#line 5215 "Gmsh.y" /* yacc.c:1652  */
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
#line 12485 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 460:
#line 5235 "Gmsh.y" /* yacc.c:1652  */
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
#line 12509 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 461:
#line 5266 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12517 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 462:
#line 5270 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12525 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 463:
#line 5274 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12533 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 464:
#line 5278 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12541 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 465:
#line 5282 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12549 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 466:
#line 5286 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12557 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 467:
#line 5290 "Gmsh.y" /* yacc.c:1652  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12566 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 468:
#line 5295 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12580 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 469:
#line 5305 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 12594 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 470:
#line 5315 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12603 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 471:
#line 5320 "Gmsh.y" /* yacc.c:1652  */
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
#line 12618 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 472:
#line 5331 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12631 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 473:
#line 5340 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strlen((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12640 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 474:
#line 5345 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12649 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 475:
#line 5350 "Gmsh.y" /* yacc.c:1652  */
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
#line 12677 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 476:
#line 5377 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 0.; }
#line 12683 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 477:
#line 5379 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);}
#line 12689 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 478:
#line 5384 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = NULL; }
#line 12695 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 479:
#line 5386 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c);}
#line 12701 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 480:
#line 5391 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c2).char1? (yyvsp[-1].c2).char1 : std::string("")),
        struct_name((yyvsp[-1].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
#line 12712 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 481:
#line 5398 "Gmsh.y" /* yacc.c:1652  */
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
#line 12729 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 482:
#line 5414 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[0].c); }
#line 12735 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 483:
#line 5416 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = (yyvsp[-2].c); (yyval.c2).char2 = (yyvsp[0].c); }
#line 12741 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 484:
#line 5421 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); flag_tSTRING_alloc = 1; }
#line 12747 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 485:
#line 5430 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 99; }
#line 12753 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 486:
#line 5432 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (int)(yyvsp[0].d); }
#line 12759 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 487:
#line 5437 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 12765 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 488:
#line 5439 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 12771 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 489:
#line 5444 "Gmsh.y" /* yacc.c:1652  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 12779 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 490:
#line 5448 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 12787 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 491:
#line 5452 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 12795 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 492:
#line 5456 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 12803 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 493:
#line 5460 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 12811 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 494:
#line 5467 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 12819 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 495:
#line 5471 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 12827 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 496:
#line 5475 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12835 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 497:
#line 5479 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12843 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 498:
#line 5486 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12852 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 499:
#line 5491 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12860 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 500:
#line 5498 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12869 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 501:
#line 5503 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12877 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 502:
#line 5507 "Gmsh.y" /* yacc.c:1652  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 12886 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 503:
#line 5512 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12894 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 504:
#line 5516 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12906 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 505:
#line 5524 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 12918 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 506:
#line 5535 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12926 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 507:
#line 5539 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 12934 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 508:
#line 5543 "Gmsh.y" /* yacc.c:1652  */
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
#line 12949 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 509:
#line 5557 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12961 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 510:
#line 5565 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 12973 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 511:
#line 5573 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 12984 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 512:
#line 5580 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 12998 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 513:
#line 5590 "Gmsh.y" /* yacc.c:1652  */
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
#line 13025 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 514:
#line 5613 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    }
#line 13034 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 515:
#line 5618 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[0].c));
    }
#line 13044 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 516:
#line 5624 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-3].i), (yyval.l));
    }
#line 13053 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 517:
#line 5629 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-1].i), (yyval.l));
      Free((yyvsp[0].c));
    }
#line 13063 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 518:
#line 5635 "Gmsh.y" /* yacc.c:1652  */
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
#line 13078 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 519:
#line 5646 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[-1].i), (yyvsp[0].l), (yyval.l));
      List_Delete((yyvsp[0].l));
    }
#line 13088 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 520:
#line 5653 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[-15].i), (yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d), (yyval.l));
    }
#line 13097 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 521:
#line 5658 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[-3].i), (yyvsp[-1].l), (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 13107 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 522:
#line 5664 "Gmsh.y" /* yacc.c:1652  */
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
#line 13123 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 523:
#line 5676 "Gmsh.y" /* yacc.c:1652  */
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
#line 13141 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 524:
#line 5690 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13155 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 525:
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
#line 13169 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 526:
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
#line 13183 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 527:
#line 5720 "Gmsh.y" /* yacc.c:1652  */
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
#line 13199 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 528:
#line 5732 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13207 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 529:
#line 5736 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13215 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 530:
#line 5741 "Gmsh.y" /* yacc.c:1652  */
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
#line 13231 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 531:
#line 5753 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13239 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 532:
#line 5757 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13247 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 533:
#line 5761 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 13255 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 534:
#line 5765 "Gmsh.y" /* yacc.c:1652  */
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
#line 13277 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 535:
#line 5783 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = (yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1);
	List_Add((yyval.l), &d);
      }
    }
#line 13289 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 536:
#line 5791 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = pow(10,(yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1));
	List_Add((yyval.l), &d);
      }
    }
#line 13301 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 537:
#line 5799 "Gmsh.y" /* yacc.c:1652  */
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
#line 13334 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 538:
#line 5828 "Gmsh.y" /* yacc.c:1652  */
    {
      double x0 = (yyvsp[-11].d), x1 = (yyvsp[-9].d), y0 = (yyvsp[-7].d), y1 = (yyvsp[-5].d), ys = (yyvsp[-3].d);
      int N = (int)(yyvsp[-1].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
#line 13348 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 539:
#line 5838 "Gmsh.y" /* yacc.c:1652  */
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
#line 13368 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 540:
#line 5854 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[-1].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13380 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 541:
#line 5865 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13389 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 542:
#line 5870 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13397 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 543:
#line 5874 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13405 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 544:
#line 5878 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13418 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 545:
#line 5890 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 13426 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 546:
#line 5894 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 13434 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 547:
#line 5906 "Gmsh.y" /* yacc.c:1652  */
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
#line 13455 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 548:
#line 5923 "Gmsh.y" /* yacc.c:1652  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 13466 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 549:
#line 5933 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13474 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 550:
#line 5937 "Gmsh.y" /* yacc.c:1652  */
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
#line 13490 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 551:
#line 5952 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13499 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 552:
#line 5957 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13507 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 553:
#line 5964 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13515 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 554:
#line 5968 "Gmsh.y" /* yacc.c:1652  */
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[0].c));
    }
#line 13524 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 555:
#line 5973 "Gmsh.y" /* yacc.c:1652  */
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
#line 13542 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 556:
#line 5987 "Gmsh.y" /* yacc.c:1652  */
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
#line 13560 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 557:
#line 6003 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13568 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 558:
#line 6007 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13576 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 559:
#line 6011 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13584 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 560:
#line 6015 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13592 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 561:
#line 6019 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 13604 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 562:
#line 6027 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13614 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 563:
#line 6033 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13624 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 564:
#line 6042 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13632 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 565:
#line 6046 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13640 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 566:
#line 6050 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 13652 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 567:
#line 6058 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 13662 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 568:
#line 6064 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 13672 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 569:
#line 6070 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
#line 13680 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 570:
#line 6074 "Gmsh.y" /* yacc.c:1652  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 13692 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 571:
#line 6082 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13704 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 572:
#line 6090 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 13715 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 573:
#line 6097 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13727 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 574:
#line 6106 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].c), 2);
    }
#line 13735 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 575:
#line 6110 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].c), 2);
    }
#line 13743 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 576:
#line 6114 "Gmsh.y" /* yacc.c:1652  */
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
#line 13762 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 577:
#line 6129 "Gmsh.y" /* yacc.c:1652  */
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
#line 13780 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 578:
#line 6143 "Gmsh.y" /* yacc.c:1652  */
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
#line 13798 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 579:
#line 6157 "Gmsh.y" /* yacc.c:1652  */
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
#line 13814 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 580:
#line 6169 "Gmsh.y" /* yacc.c:1652  */
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
#line 13834 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 581:
#line 6185 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13847 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 582:
#line 6194 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13860 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 583:
#line 6203 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13874 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 584:
#line 6213 "Gmsh.y" /* yacc.c:1652  */
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
#line 13889 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 585:
#line 6224 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-5].c);
      std::string out = in.substr((int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c));
    }
#line 13901 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 586:
#line 6232 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-3].c);
      std::string out = in.substr((int)(yyvsp[-1].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-3].c));
    }
#line 13913 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 587:
#line 6240 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13921 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 588:
#line 6244 "Gmsh.y" /* yacc.c:1652  */
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
#line 13944 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 589:
#line 6263 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13955 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 590:
#line 6270 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 13965 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 591:
#line 6276 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13976 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 592:
#line 6283 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13987 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 593:
#line 6290 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 13993 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 594:
#line 6292 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 14005 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 595:
#line 6300 "Gmsh.y" /* yacc.c:1652  */
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
#line 14030 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 596:
#line 6324 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[0].d); }
#line 14036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 597:
#line 6326 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = (yyvsp[-3].c); Free((yyvsp[-3].c)); (yyval.d) = (yyvsp[0].d); }
#line 14042 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 598:
#line 6332 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 14048 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 599:
#line 6337 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14054 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 600:
#line 6339 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14060 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 601:
#line 6344 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 14066 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 602:
#line 6349 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 14075 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 603:
#line 6354 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14081 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 604:
#line 6356 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 14089 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 605:
#line 6360 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	char* c;
	List_Read((yyvsp[0].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[0].l));
    }
#line 14102 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 606:
#line 6372 "Gmsh.y" /* yacc.c:1652  */
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
#line 14120 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 607:
#line 6386 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14128 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 608:
#line 6390 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14136 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 609:
#line 6397 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 14148 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 610:
#line 6405 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 14160 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 611:
#line 6413 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-5].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-5].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-5].c));
    }
#line 14172 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 612:
#line 6424 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14178 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 613:
#line 6426 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14184 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 614:
#line 6429 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 14190 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;


#line 14194 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6432 "Gmsh.y" /* yacc.c:1918  */


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
