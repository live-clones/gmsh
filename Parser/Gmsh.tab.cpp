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
    tRenumberMeshNodes = 337,
    tRenumberMeshElements = 338,
    tDistanceFunction = 339,
    tDefineConstant = 340,
    tUndefineConstant = 341,
    tDefineNumber = 342,
    tDefineStruct = 343,
    tNameStruct = 344,
    tDimNameSpace = 345,
    tAppend = 346,
    tDefineString = 347,
    tSetNumber = 348,
    tSetTag = 349,
    tSetString = 350,
    tPoint = 351,
    tCircle = 352,
    tEllipse = 353,
    tCurve = 354,
    tSphere = 355,
    tPolarSphere = 356,
    tSurface = 357,
    tSpline = 358,
    tVolume = 359,
    tBox = 360,
    tCylinder = 361,
    tCone = 362,
    tTorus = 363,
    tEllipsoid = 364,
    tQuadric = 365,
    tShapeFromFile = 366,
    tRectangle = 367,
    tDisk = 368,
    tWire = 369,
    tGeoEntity = 370,
    tCharacteristic = 371,
    tLength = 372,
    tParametric = 373,
    tElliptic = 374,
    tRefineMesh = 375,
    tAdaptMesh = 376,
    tRelocateMesh = 377,
    tReorientMesh = 378,
    tSetFactory = 379,
    tThruSections = 380,
    tWedge = 381,
    tFillet = 382,
    tChamfer = 383,
    tPlane = 384,
    tRuled = 385,
    tTransfinite = 386,
    tPhysical = 387,
    tCompound = 388,
    tPeriodic = 389,
    tParent = 390,
    tUsing = 391,
    tPlugin = 392,
    tDegenerated = 393,
    tRecursive = 394,
    tRotate = 395,
    tTranslate = 396,
    tSymmetry = 397,
    tDilate = 398,
    tExtrude = 399,
    tLevelset = 400,
    tAffine = 401,
    tBooleanUnion = 402,
    tBooleanIntersection = 403,
    tBooleanDifference = 404,
    tBooleanSection = 405,
    tBooleanFragments = 406,
    tThickSolid = 407,
    tRecombine = 408,
    tSmoother = 409,
    tSplit = 410,
    tDelete = 411,
    tCoherence = 412,
    tIntersect = 413,
    tMeshAlgorithm = 414,
    tReverseMesh = 415,
    tLayers = 416,
    tScaleLast = 417,
    tHole = 418,
    tAlias = 419,
    tAliasWithOptions = 420,
    tCopyOptions = 421,
    tQuadTriAddVerts = 422,
    tQuadTriNoNewVerts = 423,
    tRecombLaterals = 424,
    tTransfQuadTri = 425,
    tText2D = 426,
    tText3D = 427,
    tInterpolationScheme = 428,
    tTime = 429,
    tCombine = 430,
    tBSpline = 431,
    tBezier = 432,
    tNurbs = 433,
    tNurbsOrder = 434,
    tNurbsKnots = 435,
    tColor = 436,
    tColorTable = 437,
    tFor = 438,
    tIn = 439,
    tEndFor = 440,
    tIf = 441,
    tElseIf = 442,
    tElse = 443,
    tEndIf = 444,
    tExit = 445,
    tAbort = 446,
    tField = 447,
    tReturn = 448,
    tCall = 449,
    tSlide = 450,
    tMacro = 451,
    tShow = 452,
    tHide = 453,
    tGetValue = 454,
    tGetStringValue = 455,
    tGetEnv = 456,
    tGetString = 457,
    tGetNumber = 458,
    tUnique = 459,
    tHomology = 460,
    tCohomology = 461,
    tBetti = 462,
    tExists = 463,
    tFileExists = 464,
    tGetForced = 465,
    tGetForcedStr = 466,
    tGMSH_MAJOR_VERSION = 467,
    tGMSH_MINOR_VERSION = 468,
    tGMSH_PATCH_VERSION = 469,
    tGmshExecutableName = 470,
    tSetPartition = 471,
    tNameToString = 472,
    tStringToName = 473,
    tAFFECTPLUS = 474,
    tAFFECTMINUS = 475,
    tAFFECTTIMES = 476,
    tAFFECTDIVIDE = 477,
    tOR = 478,
    tAND = 479,
    tEQUAL = 480,
    tNOTEQUAL = 481,
    tLESSOREQUAL = 482,
    tGREATEROREQUAL = 483,
    tLESSLESS = 484,
    tGREATERGREATER = 485,
    tPLUSPLUS = 486,
    tMINUSMINUS = 487,
    UNARYPREC = 488
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

#line 531 "Gmsh.tab.cpp" /* yacc.c:352  */
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
#define YYLAST   16917

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  256
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  613
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2190

#define YYUNDEFTOK  2
#define YYMAXUTOK   488

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   241,     2,   253,     2,   238,   240,     2,
     246,   247,   236,   234,   255,   235,   252,   237,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     228,     2,   230,   223,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   248,     2,   249,   245,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   250,   239,   251,   254,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   224,   225,
     226,   227,   229,   231,   232,   233,   242,   243,   244
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   268,   268,   269,   274,   276,   280,   281,   282,   283,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   321,   325,   332,   337,
     342,   356,   369,   382,   410,   424,   437,   450,   469,   474,
     475,   476,   477,   478,   482,   484,   489,   491,   497,   601,
     496,   619,   626,   637,   636,   654,   661,   672,   671,   688,
     705,   728,   727,   741,   742,   743,   744,   745,   749,   750,
     756,   756,   757,   757,   763,   764,   765,   766,   771,   777,
     839,   854,   883,   893,   898,   906,   911,   919,   928,   933,
     945,   962,   968,   977,   995,  1013,  1022,  1034,  1039,  1047,
    1067,  1090,  1110,  1118,  1125,  1132,  1154,  1177,  1215,  1236,
    1248,  1262,  1262,  1264,  1266,  1275,  1285,  1284,  1305,  1304,
    1322,  1332,  1331,  1345,  1347,  1355,  1361,  1366,  1393,  1395,
    1398,  1400,  1404,  1405,  1409,  1421,  1434,  1449,  1458,  1471,
    1473,  1477,  1478,  1483,  1491,  1500,  1508,  1522,  1540,  1544,
    1551,  1560,  1563,  1569,  1573,  1585,  1588,  1595,  1618,  1634,
    1650,  1687,  1727,  1743,  1759,  1791,  1807,  1824,  1840,  1890,
    1908,  1914,  1920,  1927,  1958,  1973,  1995,  2018,  2041,  2064,
    2088,  2112,  2136,  2162,  2179,  2195,  2213,  2231,  2238,  2247,
    2246,  2276,  2278,  2280,  2282,  2284,  2292,  2294,  2296,  2298,
    2306,  2308,  2310,  2318,  2320,  2322,  2324,  2334,  2350,  2366,
    2382,  2398,  2414,  2431,  2468,  2490,  2514,  2515,  2520,  2523,
    2527,  2544,  2564,  2584,  2603,  2630,  2649,  2670,  2685,  2701,
    2719,  2770,  2791,  2813,  2836,  2941,  2957,  2992,  3014,  3036,
    3048,  3054,  3069,  3097,  3109,  3118,  3125,  3137,  3157,  3161,
    3166,  3170,  3175,  3182,  3189,  3196,  3208,  3281,  3299,  3324,
    3339,  3372,  3384,  3408,  3412,  3417,  3424,  3429,  3439,  3444,
    3450,  3458,  3462,  3466,  3470,  3474,  3483,  3547,  3563,  3580,
    3597,  3619,  3641,  3676,  3684,  3692,  3698,  3705,  3712,  3732,
    3758,  3770,  3781,  3799,  3817,  3836,  3835,  3860,  3859,  3886,
    3885,  3910,  3909,  3932,  3948,  3965,  3982,  4005,  4033,  4036,
    4042,  4054,  4074,  4078,  4082,  4086,  4090,  4094,  4098,  4102,
    4111,  4124,  4125,  4126,  4127,  4128,  4132,  4133,  4134,  4135,
    4136,  4139,  4163,  4182,  4205,  4208,  4224,  4227,  4244,  4247,
    4253,  4256,  4263,  4266,  4273,  4295,  4336,  4380,  4419,  4444,
    4456,  4468,  4480,  4492,  4501,  4531,  4557,  4583,  4615,  4642,
    4668,  4694,  4720,  4746,  4768,  4779,  4827,  4881,  4896,  4908,
    4919,  4926,  4941,  4955,  4956,  4957,  4961,  4967,  4979,  4997,
    5025,  5026,  5027,  5028,  5029,  5030,  5031,  5032,  5033,  5040,
    5041,  5042,  5043,  5044,  5045,  5046,  5047,  5048,  5049,  5050,
    5051,  5052,  5053,  5054,  5055,  5056,  5057,  5058,  5059,  5060,
    5061,  5062,  5063,  5064,  5065,  5066,  5067,  5068,  5069,  5070,
    5071,  5072,  5073,  5074,  5075,  5076,  5077,  5086,  5087,  5088,
    5089,  5090,  5091,  5092,  5093,  5094,  5095,  5096,  5101,  5100,
    5108,  5110,  5115,  5120,  5124,  5129,  5134,  5138,  5142,  5146,
    5150,  5154,  5158,  5164,  5179,  5183,  5189,  5194,  5213,  5233,
    5264,  5268,  5272,  5276,  5280,  5284,  5288,  5293,  5303,  5313,
    5318,  5329,  5338,  5343,  5348,  5376,  5377,  5383,  5384,  5390,
    5389,  5412,  5414,  5419,  5428,  5430,  5436,  5437,  5442,  5446,
    5450,  5454,  5458,  5465,  5469,  5473,  5477,  5484,  5489,  5496,
    5501,  5505,  5510,  5514,  5522,  5533,  5537,  5541,  5555,  5563,
    5571,  5578,  5588,  5611,  5616,  5622,  5627,  5633,  5644,  5650,
    5656,  5662,  5674,  5688,  5698,  5708,  5718,  5730,  5734,  5739,
    5751,  5755,  5759,  5763,  5781,  5789,  5797,  5826,  5836,  5852,
    5863,  5868,  5872,  5876,  5888,  5892,  5904,  5921,  5931,  5935,
    5950,  5955,  5962,  5966,  5971,  5985,  6001,  6005,  6009,  6013,
    6017,  6025,  6031,  6040,  6044,  6048,  6056,  6062,  6068,  6072,
    6080,  6088,  6095,  6104,  6108,  6112,  6127,  6141,  6155,  6167,
    6183,  6192,  6201,  6211,  6222,  6230,  6238,  6242,  6261,  6268,
    6274,  6281,  6289,  6288,  6298,  6322,  6324,  6330,  6335,  6337,
    6342,  6347,  6352,  6354,  6358,  6370,  6384,  6388,  6395,  6403,
    6411,  6422,  6424,  6427
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
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tRotate",
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
     475,   476,   477,    63,   478,   479,   480,   481,    60,   482,
      62,   483,   484,   485,    43,    45,    42,    47,    37,   124,
      38,    33,   486,   487,   488,    94,    40,    41,    91,    93,
     123,   125,    46,    35,   126,    44
};
# endif

#define YYPACT_NINF -1859

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1859)))

#define YYTABLE_NINF -561

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   12416,    63,    87, 12574, -1859, -1859,   116,    99,    34,   -80,
     -66,    48,   140,   150,   181,   214,     1,   249,   260,   271,
     288,    90,   110,    40,   341,   286,   341,   102,   126,   135,
      56,   167,   172,    57,   221,   227,   269,   301,   308,   313,
     324,   348,   361,   381,   202,   270,   404,   616,   384,   385,
     527,   395,  6603,   411,   410,   438,   624,   -46,   566,   557,
     567,   405,   472,   655,   -59,   507,   276,   276,   515,   408,
     376,   516, -1859, -1859, -1859, -1859, -1859,   503,    -1,   671,
     677,    23,    58,   686,   705,    69,   786,   804,   810,  5627,
     817,   593,   599,   608,    24,    59, -1859,   622,   676, -1859,
   -1859,   897,   900,   689, -1859,  8424,   694,  6960,    31,    35,
   -1859, -1859, -1859, 11473,   715, -1859, -1859, -1859, -1859, -1859,
     695, -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859,
   -1859,   -60, -1859, -1859, -1859, -1859,    47, -1859,   943,   699,
    4719,   322,   716,   959, 11473, 12749, 12749, -1859, 11473, -1859,
   -1859, -1859, -1859, 12749, -1859, -1859, -1859, -1859, -1859, -1859,
     713,   723,   961, -1859, -1859,  7204,   725,   726,   727,   729,
      40, 11473, 11473, 11473,   730, 11473, 11473, 11473,   731, 11473,
   11473, 11473, 11473, 11473, 11473, 11473, 12749, 11473, 11473, 11473,
   11473,  5627,   732, -1859,  9277, -1859, -1859, -1859,   742,  5627,
    6847, 12749, -1859, -1859, -1859, -1859, -1859,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     486,   341,   341,   341,   341,   341,   733,   341,   341,   734,
     557,   567,   567, -1859, -1859, -1859,   341,   341,    41,   798,
     809,   811,   744,  6847,   875,   557,   557,   756,   341,   341,
     757,   761,   762, -1859, -1859, -1859, 11473,  7091, 11473, 11473,
    7335,    40,   826,    42, -1859, -1859,   764, -1859,  5319, -1859,
   -1859, -1859, -1859, -1859,    65, 11473,  9277,  9277,   766,   769,
    7579,  5627,  5627,  5627, -1859, -1859, -1859, -1859, -1859, -1859,
   -1859, -1859,   767,  7823,   768,  2169,  1016,  6847,   772,    24,
     773,   774,   276,   276,   276, 11473, 11473,   -40, -1859,   -16,
     276, 10179,   188,    15,   779,   781,   782,   785,   788,   791,
     792,  9277, 11473,  5627,  5627,  5627,   794,    22,  1026,   796,
   -1859,  1039,  1040, -1859,   797,   799,   800, -1859, -1859,   801,
    5627,   806,   808,   813, -1859, 11473,  5871, -1859,  1051,  1052,
   11473, 11473, 11473,   179, 11473,   812, -1859,   879, 11473, 11473,
   11473, -1859, -1859, 11473, -1859,   341,   341,   341,   818,   819,
     820,   341,   341,   341,   341,   341,   341,   341, -1859,   341,
   -1859, -1859, -1859,   341,   341,   821,   822,   341,   827, -1859,
     824,  1053,  1068,   828, -1859, -1859,  1071,  1072,  1073,  1074,
     341, 11473, 14531,   117, 12749,  9277, 11473, -1859, -1859,  6847,
    6847, -1859,   835,  7204,   557,  1082, -1859, -1859, -1859, -1859,
   -1859, -1859, 11473, 11473,    27,  6847,  1095,   697,   853,  1094,
     854,  1099,    91,   856, -1859,   857, 12873, 11473, -1859,  2064,
    -196, -1859,    72,  -175,  8725, -1859,  -106, -1859,    73,   -79,
     -74,  1018, -1859,    40,   852, 11473, 11473, 11473, 11473,   855,
   15047, 15072, 15097, 11473, 15122, 15147, 15172, 11473, 15197, 15222,
   15247, 15272, 15297, 15322, 15347,   864, 15372, 15397, 15422, 13661,
    1105, 11473,  9277,  5563, -1859,   196, 11473,  1107,  1125,   885,
   11473, 11473, 11473, 11473, 11473, 11473, 11473, 11473, 11473, 11473,
   11473, 11473, 11473, 11473, 11473, 11473,  9277, 11473, 11473, 11473,
   11473, 11473, 11473,  9277,  9277,   883, 11473, 11473, 12749, 11473,
   12749,  6847, 12749, 12749, 12749,   886,   893,   894, 11473,    33,
   -1859, 10260, 11473,  6847,  5627,  6847, 12749, 12749,  9277,    40,
    7204,    40,   901,  9277,   901, -1859,   901, 15447, -1859,   283,
     895,    81,  1081, -1859,  1141, 11473, 11473, 11473, 11473, 11473,
   11473, 11473, 11473, 11473, 11473, 11473, 11473, 11473, 11473,  8067,
   11473, 11473, 11473, 11473, 11473,    40, 11473, 11473,  1146, -1859,
     701, 15472,   393,   490, 11473, 11473, 11473, -1859,  1144,  1150,
    1150,   907, 11473, 11473,  1152,  9277,  9277, 14559,   912,  1154,
   -1859,   911, -1859, -1859,  -130, -1859, -1859,  8969,  9213,   276,
     276,   322,   322,  -107, 10179, 10179, 11473,  4969,  -100, -1859,
   11473, 11473, 11473, 11473, 11473, 11473, 11473, 11473, 11473,   492,
   15497,  1155,  1157,  1158, 11473,  1160, 11473, -1859, -1859, 11473,
   11441, -1859, -1859,  9277,  9277,  9277, 11473,  1161, 11473, 11473,
   11473, 15522,   917, -1859, -1859, 15547, 15572, 15597,   988,  9547,
   -1859,   920,  5807, 15622, 15647, 14642, 12749, 12749, 12749, 12749,
   12749, 12749, 12749, 12749, 12749, 11473, 12749, 12749, 12749, 12749,
      10,  7204, 12749, 12749, 12749,    40,    40, -1859, -1859,  9277,
   -1859,   921, 11598, -1859,   922, 11655, 11473,   901, 11473, -1859,
      40, 11473, 11473,  1146,   925,   493, 15672, 12770,   928,   495,
   11473,  1170,   927,  6847, 15697, 14669,    11,   926,  1172,  1177,
   -1859, -1859, -1859,  9277,   157, 11473, -1859, -1859, -1859,    40,
   11473, 11473,  1146,   938, -1859,   939,   -29,   557,   567,   557,
   -1859,   940, 13690, -1859,   134,  9277,    40, 11473, 11473,  1185,
    1186,  9277, 11473,  1189, 12749,    40, 10499,  1185,  1208, -1859,
      40,  1209, 12749, 11473,   944,   968, -1859, 11473,  9881, 10128,
   10210, 10455,  7204,  1210,  1212,  1213, 15722,  1214,  1215,  1218,
   15747,  1219,  1220,  1221,  1223,  1224,  1225,  1226, -1859,  1228,
    1231,  1233, -1859, 11473, 15772,  9277,   991,  9277, 13719, -1859,
   -1859,  1236, 14615, 14615, 14615, 14615, 14615, 14615, 14615, 14615,
   14615, 14615, 14615, 10530, 14615, 14615, 14615, 14615,  1393,   491,
   14615, 14615, 14615, 10782, 10857, 11102,  5563,   996,   997,   103,
    9277, 11184, 11397,   491, 12209,   491,   992,   993,   998,   -95,
    9277, 11473, 11473, 16672, -1859,   491,  1003, 13748, 13777, -1859,
   -1859,  1000,    95,   491,   -31,  1009,   371,   500,  1250, -1859,
    1185,   491,  1013,  1008,  6051,  6295,   890,  1315,   596,   596,
     466,   466,   466,   466,   466,   466,   476,   476,  9277,   332,
   -1859,   332,   332,   901,   901,   901,  1012, 15797, 14696,   281,
     574,  9277, -1859,  1259,  1017,  1020, 15822, 15847, 15872, 11473,
    6847,  1264,  1265,  9940, 13806, 15897, -1859,   505,   508,  9277,
    1021, -1859, 11722, -1859, 11779, 11846,   276, 11473, 11473, -1859,
   -1859,  1023,  1024, 10179,  7515,  1140,   430,   276, 11903, 15922,
   13835, 15947, 15972, 15997, 16022, 16047, 16072, 16097,  1027,  1272,
   11473,  1275, -1859, 11473, 16122, -1859, 14723, 11970, 14750, -1859,
     517,   520,   523, 13864, -1859, 14777, 14804, 12803, -1859, -1859,
    1277,  1278,  1279,  1030, 11473, 12027, 11473, 11473, -1859, -1859,
      26,   137,   314,   137,  1041,  1042,  1032,   491,   491,  1035,
   12836,   491,   491,   491,   491, 11473,   491,  1282, -1859,  1037,
    1046,   369,   280,  1045,   540, -1859, -1859, -1859, -1859, 14615,
     332, 12094,  1043,   706,  1048,  1112,  1290,  1143, 10587,  1055,
    1054,  1301,  6847, 13893, -1859, 11473,  1302,   206,    17,  7204,
   11473,  1304,  1307,    25, -1859,   545,  1266,  1267,  6847, 13922,
      28,  1063, 16147, 14831,   483, 11473, 11473,  1090,  1087,  1092,
    1091,  8311, -1859, -1859, -1859, -1859, 12749,   -70,  1098, 16172,
   14858, -1859,  1100, -1859,   -30, 12869, -1859, -1859, -1859,  1101,
   -1859,  1109, -1859,    64, -1859, -1859, 16672, -1859,  1340, 14615,
   11473, 11473, 11473, 11473,   491,   276,  6847,  6847,  1344,  6847,
    6847,  6847,  1349,  6847,  6847,  6847,  6847,  6847,  6847,  6847,
    6847,  6847,  6847,  2202,  1351,  9277,  5563, -1859, -1859, -1859,
   -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859,
   -1859, 11473, -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859,
   -1859, 11473, 11473, 11473, -1859, -1859, -1859,   546, 11473, 11473,
   -1859, 11473, -1859,  6847, 12749, 12749, -1859,   548, 13951, 13980,
    1104, -1859, -1859, -1859,  1176, 11473, 11473, -1859, -1859, -1859,
    1185, -1859,  1185, 11473, 11473,  1116, -1859,  6847,   341, -1859,
   11473, -1859, 11473, 11473,   554,  1185,   281,  -144, -1859, 11473,
   11473,   491,   555,  6847,  9277,  9277,  1357,  1358,  1359,  4766,
   -1859, -1859,  1361, -1859,  1122, 16672,  1118, -1859,  1364,  1368,
    1369,   561,  1373, -1859, 12151, -1859, -1859,   -90, 12902, 12935,
   -1859, -1859, 14009,   -72,  1268,  1374, 10826,  1129,  1378,  1134,
      36,    37,   -47, -1859,   -11, -1859,   430,  1380,  1379,  1381,
    1382,  1383,  1384,  1387,  1388,  1389,   322,  6847, 16672, -1859,
    2359,  1147,  1392, -1859,  1394,  1396,  1303,  1397, -1859,  1400,
    1401, 11473,  6847,  6847,  6847,  1399, 12968, -1859,  6539,  1804,
      53,  1404, -1859,  9277, -1859, -1859, -1859, -1859, 12749, -1859,
   -1859, 11473, 12749, -1859, -1859, -1859, -1859, 16672, -1859,  1156,
    1159, 12749, -1859, 12749, -1859,  1185, 12749,  1163, -1859,  1162,
   -1859,  1185, 11473, 11473,  1165,   557,  1166, 10914, -1859,  2453,
    1168,  6847, -1859,  1169, -1859, 14038, -1859, -1859, 11473,  1405,
      30, 11473,  1407,  1413,  2491, -1859,  1414,    24,  1419,  1179,
     491,   341,   341,  1425, -1859, -1859,  1187,  1188,  1182, -1859,
    1429, -1859, -1859, -1859, -1859, -1859,  1185,  -167,  3572, 11473,
   14885, 16197, 11473,  8550, 11473,  9277,  1190,   562,  1431,   141,
    1185, -1859,  1191, 11473,  1433, 11473,  1185, 11153,  9516,   491,
    5139,  1195,  1192, -1859,  1434, 16222, 16247, 16272, 16297,  1439,
      88,  1317,  1317,  6847,  1442,  1443,  1444,  6847,   -91,  1446,
    1447,  1448,  1450,  1451,  1452,  1453,  1454,  1455, -1859,  1458,
     564, 14615, 14615, 14615, 14615,   491, 13001, 13034, 13067,  1217,
     491,   491, -1859, -1859, -1859,  1340,   491, 16322, 14615,  1222,
    -178, 16672, 14615, -1859,  1460,   491, 13100, 16672, 16672, -1859,
     710, -1859,  1463, -1859, 16347, 14912, -1859,   491,  1462,   587,
     589,  6847,  6847,  6847,  1467,  1466, -1859,   222, 11473,  6847,
    1227,  1229,  1468,   606, -1859, 11473, 11473, 11473,  1230,  1232,
    1234,  1235, -1859,  2555,  6847, -1859, 11473, -1859,  1470, -1859,
    1472, -1859, -1859, 10179,   -44,  6115, -1859,  1237,  1238,  1239,
    1240,  1255,  1256,  8789,  1249,  1475, -1859,  9277, -1859, -1859,
   -1859,  1260, 11473, -1859, -1859, 14939,  1479,  1505,  1293, -1859,
   11473, 11473, 11473, -1859,  1506,  1507,  1509,   691,   470,  1261,
    7271,  1263, 11473,    18,   491,  1274,   491,  1269, -1859, -1859,
    7204,   711, 11473,  1276, -1859, -1859,  3000, -1859, -1859,  1270,
    1513, -1859,  3117, -1859,   215,  1284,  1515,  3199, -1859, -1859,
   -1859,    24, -1859,   595, -1859, 11473,   222,  4294,   937, -1859,
    1281, 11473, 11473,  6847,  1280, -1859,   489,  1525,  1531, 16372,
    1532,  1250, 16397,  1288,   597, 16422,   600,  1550,  1551, -1859,
   -1859, 12749,  1285,  1555, 16447, -1859, 13133,  1319, -1859,  5383,
   16672, -1859,  1554,   341,  7335, -1859, -1859, -1859, -1859,  1340,
   -1859,  1557,  1561,  1562,  1563, -1859, -1859,   276,  1564,  1566,
    1567, -1859, -1859, -1859,  1568,   -48,  1476,  1569, -1859, -1859,
   -1859, -1859, -1859, -1859, -1859, -1859, -1859,  1572,  1328, -1859,
   -1859, -1859, -1859, -1859, 11473, 11473, 11473, -1859, -1859, -1859,
    1192, -1859, -1859, -1859, -1859, 11473,  1333,  1326, -1859, -1859,
   11473, 11473, 11473,   491,   281, -1859, -1859, -1859, -1859,  1332,
    1334,  1577,   -91,  1579, 11473, -1859,  6847, 16672,   958,  9277,
    9277, 11473, -1859,  9940, 14067, 16472,  7759,   322,   322, 11473,
   11473, -1859,   170,  1331, 16497, -1859, -1859, 14096,   185, -1859,
    1583,  1584,  6847,   276,   276,   276,   276,   276,  6359,  1585,
   -1859, -1859,   602, 11473,  3526,  1586, -1859, -1859,  6847,  8003,
     973, 16522, -1859, -1859, -1859, -1859,  9606, -1859, 12749, 11473,
   -1859, 12749, 16672,  9850,  7204,  1338, -1859, -1859, -1859, -1859,
    1347,  1341, 11473, 11473, 14125, 11473, 12770, -1859, 12770,  6847,
   -1859, -1859,  7204, 11473,  1589,  1593,    25, -1859,  1594, -1859,
      24, 14966,  6847, 12749,  1595,   491, -1859,  1348,   491, 11473,
   13166, 13199,   605, -1859, 11473, 11473,   251, -1859,  1352, -1859,
    1359,  1599,  1600,  1364,  1601, -1859, -1859,  1602, 11473, -1859,
   -1859, 11473, 11234, -1859, -1859,  1365,   937,   610,  5078,  1592,
   -1859, -1859, -1859, -1859, -1859,   475, -1859, -1859, -1859, -1859,
    1385,  1386,  1402, -1859,  1629,  6847, 14615, 14615, 13232, 14615,
   -1859,  1390, 13265, 16547, 14993, -1859, -1859,  9277,  9277, -1859,
    1633, -1859, 16672,  1638,  1406, -1859,   612,   615, 14587,  3701,
    1644,  1410, -1859, -1859, 11473,  1403,  1411, 14154, 15020,  1645,
    6847,  1648,  1415, 11473, -1859, -1859,   620,   195,   211,   220,
     235,   244,  9033,   257, -1859,  1651, 14183, -1859, -1859,  1484,
   -1859, 11473, 11473, -1859, -1859,  9277,  3887,  1658,  1421, 14615,
     491, 16672, -1859, -1859, -1859, -1859,    18, -1859,  7204, -1859,
   14212,  1420,  1427,  1428,  1660,  4473, -1859,  1663,  1666, -1859,
   -1859,  1424,  1674,   625, -1859,  1675,  1676,   -20, 16672, 11473,
   11473,  1436,  6847,   626, 16672, 16572, -1859, -1859, -1859, -1859,
   16597, 13298, -1859,  1104,  1159,  6847,   491, -1859, 11473,  7204,
      40,  9277,  9277, 11473,  1677,   627, -1859, -1859, 11473,  1326,
   -1859, 11473, -1859, -1859,   628,   633, -1859, -1859,  6847,   499,
     582,  9277, -1859, -1859,   322,  8486, -1859, -1859, -1859,  1678,
   -1859,  1437,  6847, -1859, 14241,  1681,  9277,   276,   276,   276,
     276,   276, -1859, -1859, 11473, 14270, 14299,   636, -1859, -1859,
   -1859, -1859, -1859, -1859,  1445,  1683,  1440, -1859,  1685, -1859,
   -1859,    24, -1859,  1511, -1859, -1859, -1859, -1859, -1859, 11473,
   13331, 13364,  6847, -1859,  1688, 11473,  1449, -1859, 11473,  1456,
    1457, -1859, -1859,  2725, -1859,  1459,   638,   639, 14328, -1859,
    1461, 13397,  1465, 13430, -1859,  1464,   641,  1469,   276,  6847,
    1690,  1471,   276,  1691,   644,  1473, -1859, 11473, -1859,  1694,
    1565, 12218,  1478, -1859,   649,   282,   284,   318,   323,   330,
    4646, -1859, -1859,  1696,  1697, -1859, -1859, -1859,  1698, -1859,
    1481, 16672, 11473, 11473,   650, -1859, 16672, 13463, -1859, -1859,
    1104,  7204,  1485, -1859, -1859, -1859, 11473, 11473, -1859, 11473,
    9277,  1700,   276,   101, -1859, -1859,   276,   127, -1859,  1703,
   -1859, 14357, -1859, 11473, -1859,   430, -1859,  1704,  9277,  9277,
    9277,  9277,  9033, -1859, -1859, -1859, 12770, -1859, 11473, 16622,
   13496,    49, 11473,  1474, -1859, -1859, 13529, 13562, 13595,   657,
   -1859,   333, -1859,   340, -1859, -1859, -1859,  4813,   335, 12275,
   -1859,   658,   660,   663,   666,   346,   668,  1482,   669, -1859,
   11473, -1859,  6847, 14386, -1859, 11473, 11473, 11473, -1859,   276,
     276, -1859, -1859, -1859,   430,  1707,  1709,  1711,  1712,  9277,
    1714,  1716,  1720,  1486, 16647,   674,  1728, 14415, 14615, 13628,
     365,   374,   443, -1859, -1859, -1859, -1859,   680, -1859, -1859,
   -1859, 12749, -1859,  1488, -1859,  1729, -1859, 11473, 11473, 11473,
   -1859,  1735,   681, -1859,  1492,  6847, -1859, 14444, 14473, 14502,
   -1859,  1737, 12749, 12749,   683, -1859,  1738,  1739, -1859, -1859,
     688, -1859,  1740, -1859, -1859,  1741, 12749, -1859, -1859, -1859
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,     0,     0,
     192,     0,     0,   193,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   321,   322,   323,   324,   325,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,     0,   290,
     291,     0,     0,     0,   285,     0,     0,     0,     0,     0,
     373,   374,   375,     0,     0,     5,     6,     7,     8,    10,
       0,    11,    24,    12,    13,    14,    15,    23,    22,    21,
      16,     0,    17,    18,    19,    20,     0,    25,     0,   612,
       0,   218,     0,     0,     0,     0,     0,   267,     0,   269,
     270,   265,   266,     0,   271,   272,   273,   274,   113,   123,
     611,   486,   481,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,     0,   203,   204,   205,     0,     0,
       0,     0,   427,   428,   430,   431,   429,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   435,   436,   437,     0,     0,   191,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,   433,   434,     0,     0,     0,     0,
       0,     0,     0,     0,   523,   524,     0,   525,   499,   380,
     440,   443,   304,   500,   481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   192,   193,   194,   189,   196,
     197,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,     0,
       0,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   611,     0,     0,
     218,     0,     0,   370,     0,     0,     0,   200,   201,     0,
       0,     0,     0,     0,   507,     0,     0,   505,     0,     0,
       0,     0,     0,   611,     0,     0,   546,     0,     0,     0,
       0,   263,   264,     0,   563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,     0,
     589,   567,   568,     0,     0,     0,     0,     0,     0,   566,
       0,     0,     0,     0,   283,   284,     0,   218,     0,   218,
       0,     0,     0,   481,     0,     0,     0,   218,   376,     0,
       0,    76,     0,    63,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,     0,     0,     0,     0,
       0,   552,   481,     0,   217,     0,   216,     0,   170,     0,
       0,   552,   553,     0,     0,   601,     0,   602,   553,   111,
     111,     0,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   540,   541,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     514,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   383,     0,   382,   508,   384,     0,   501,     0,
       0,   481,     0,   516,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,     0,   457,
       0,     0,     0,     0,     0,     0,     0,   305,     0,   338,
     338,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,     0,   218,   218,     0,   490,   489,     0,     0,     0,
       0,   218,   218,     0,     0,     0,     0,   301,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   340,     0,     0,     0,     0,     0,   218,   244,     0,
       0,   242,   371,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   348,   262,     0,     0,     0,     0,     0,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   286,     0,
     249,     0,     0,   251,     0,     0,     0,   382,     0,   218,
       0,     0,     0,     0,     0,     0,     0,   326,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    72,    73,     0,     0,     0,   260,    38,   256,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
     219,     0,     0,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,   484,     0,     0,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   332,     0,
       0,     0,   195,     0,     0,     0,     0,     0,     0,   366,
     367,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   481,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   438,   456,     0,     0,     0,     0,   517,
     518,     0,     0,     0,     0,     0,   475,     0,   381,   502,
       0,     0,     0,     0,   510,     0,   400,   399,   397,   398,
     393,   395,   394,   396,   402,   401,   386,   385,     0,   387,
     509,   388,   391,   389,   390,   392,   482,     0,     0,   483,
     460,     0,   526,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,     0,     0,     0,   369,     0,     0,     0,
       0,   368,     0,   218,     0,     0,     0,     0,     0,   492,
     491,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   355,     0,     0,   243,     0,     0,     0,   237,
       0,     0,     0,     0,   365,     0,     0,     0,   381,   506,
       0,     0,     0,     0,     0,     0,     0,     0,   288,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   592,     0,
       0,     0,   477,     0,     0,   248,   252,   250,   254,     0,
     387,     0,   482,   460,   613,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,   381,     0,    63,
       0,     0,     0,     0,    79,     0,    63,    64,     0,     0,
       0,   482,     0,     0,   460,     0,     0,     0,   189,     0,
       0,     0,   608,    28,    26,    27,     0,     0,     0,     0,
       0,   483,   556,    29,     0,     0,   257,   603,   604,     0,
     605,   556,    74,   114,    75,   124,   485,   487,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   542,   543,   206,     9,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   426,
     413,     0,   415,   416,   417,   418,   419,   539,   420,   421,
     422,     0,     0,     0,   531,   530,   529,     0,     0,     0,
     536,     0,   472,     0,     0,     0,   474,     0,     0,     0,
     128,   455,   513,   512,   199,     0,     0,   441,   538,   446,
       0,   452,     0,     0,     0,     0,   503,     0,     0,   453,
       0,   515,     0,     0,     0,     0,   445,   444,   467,    70,
      71,     0,     0,     0,     0,     0,     0,     0,   381,   334,
     339,   337,     0,   347,     0,   148,   149,   199,   381,     0,
       0,     0,     0,   238,     0,   253,   255,     0,     0,     0,
     207,   209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,     0,   341,   354,
       0,     0,     0,   239,     0,     0,     0,     0,   202,     0,
       0,     0,     0,     0,     0,     0,     0,   245,     0,     0,
       0,     0,   579,     0,   586,   575,   576,   577,     0,   591,
     590,     0,     0,   580,   581,   582,   588,   595,   594,     0,
     139,     0,   569,     0,   571,     0,     0,     0,   564,     0,
     247,     0,     0,     0,     0,     0,     0,     0,   327,     0,
       0,     0,   377,     0,   609,     0,   101,    63,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,   561,    48,     0,     0,     0,    61,
       0,    39,    40,    41,    42,    43,     0,   445,   444,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,   554,     0,     0,     0,     0,     0,     0,     0,
     135,     0,   131,   132,     0,     0,     0,     0,     0,     0,
       0,   155,   155,     0,     0,     0,     0,     0,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   344,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   520,   521,   522,     0,     0,     0,     0,     0,
     475,   476,     0,   448,     0,     0,     0,   511,   403,   504,
     461,   459,     0,   458,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   346,     0,     0,     0,
       0,     0,     0,     0,   246,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,   312,     0,   315,     0,   317,
       0,   302,   309,     0,     0,     0,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,     0,   241,   240,
     372,     0,     0,    35,    36,     0,     0,     0,     0,   547,
       0,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   477,   478,   573,
       0,   461,     0,     0,   218,   328,     0,   329,   218,     0,
       0,   562,     0,    86,     0,     0,     0,     0,    84,    91,
      93,     0,   550,     0,    99,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,    34,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,   557,     0,     0,    32,     0,   557,   606,     0,
     115,   120,     0,     0,     0,   134,   137,   138,   480,     0,
      77,     0,     0,     0,     0,    78,   157,     0,     0,     0,
       0,   158,   173,   174,     0,     0,     0,     0,   159,   184,
     175,   179,   180,   176,   177,   178,   165,     0,     0,   414,
     423,   424,   425,   532,     0,     0,     0,   470,   471,   473,
     129,   439,   469,   442,   447,     0,     0,   475,   185,   454,
       0,    70,    71,     0,   466,   462,   464,   533,   181,     0,
       0,     0,   151,     0,     0,   345,     0,   150,     0,     0,
       0,     0,   261,     0,     0,     0,     0,   218,   218,     0,
       0,   314,   499,     0,     0,   316,   318,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     212,   182,     0,     0,     0,     0,   162,   163,     0,     0,
       0,     0,   102,   103,   104,   108,     0,   587,     0,     0,
     585,     0,   596,     0,     0,   140,   141,   593,   570,   572,
       0,     0,     0,     0,     0,     0,   326,   330,   326,     0,
     378,    85,    63,     0,     0,     0,     0,    83,     0,   548,
       0,     0,     0,     0,     0,     0,   599,   598,     0,     0,
       0,     0,     0,   497,     0,     0,   466,   258,   462,   259,
       0,     0,     0,     0,     0,   223,   220,     0,     0,   560,
     558,     0,     0,   116,   121,     0,     0,     0,   540,   541,
     133,   349,   350,   351,   352,   156,   160,   161,   166,   183,
       0,     0,     0,   168,     0,     0,     0,     0,     0,     0,
     449,     0,     0,     0,     0,   528,   468,     0,     0,   167,
       0,   186,   335,     0,     0,   187,     0,     0,     0,     0,
       0,     0,   496,   495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   234,     0,     0,     0,     0,
       0,     0,     0,     0,   225,     0,     0,   353,    37,     0,
     545,     0,     0,   280,   279,     0,     0,     0,     0,     0,
       0,   143,   144,   147,   146,   145,     0,   574,     0,   610,
       0,     0,     0,     0,     0,     0,    96,     0,     0,    97,
     551,     0,     0,     0,    88,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    46,     0,   224,   221,   222,    33,
       0,     0,   607,   128,   139,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,   534,   535,     0,   475,
     450,     0,   463,   465,     0,     0,   169,   190,     0,   342,
     342,     0,   109,   110,   218,     0,   210,   211,   303,     0,
     310,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   214,     0,     0,     0,     0,   105,   106,
     578,   584,   583,   142,     0,     0,     0,   331,     0,    92,
      94,     0,   100,     0,    82,   600,    89,    90,    49,     0,
       0,     0,     0,   498,     0,     0,   463,   559,     0,     0,
       0,   118,   597,     0,   125,     0,     0,     0,     0,   172,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,     0,   320,     0,
       0,   297,     0,   226,     0,     0,     0,     0,     0,     0,
       0,   544,   281,     0,     0,   364,   218,   379,     0,   549,
       0,    45,     0,     0,     0,    62,    47,     0,   117,   122,
     128,     0,     0,   153,   154,   152,     0,     0,   451,     0,
       0,     0,     0,     0,   343,   357,     0,     0,   358,     0,
     208,     0,   311,     0,   293,     0,   218,     0,     0,     0,
       0,     0,     0,   164,   107,   277,   326,    98,     0,     0,
       0,     0,     0,     0,   126,   127,     0,     0,     0,     0,
     188,     0,   361,     0,   362,   363,   493,     0,     0,   299,
     229,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,    59,     0,     0,   119,     0,     0,     0,   307,     0,
       0,   319,   298,   294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,     0,   227,   333,
      50,     0,    57,     0,   268,     0,   537,     0,     0,     0,
     300,     0,     0,    51,     0,     0,   276,     0,     0,     0,
     228,     0,     0,     0,     0,   519,     0,     0,    54,    52,
       0,    55,     0,   359,   360,     0,     0,    60,    58,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1859, -1859, -1859, -1859,   399, -1859, -1859, -1859, -1859,  -329,
   -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859, -1859,
   -1859, -1859,  -713,  -101,  2253,  3158, -1859,  1291, -1859, -1859,
   -1859, -1859, -1859, -1859, -1858, -1859,   345,   173,  -140, -1859,
     -99, -1859,   113,   386,  1753, -1859,   815,   -49, -1859, -1859,
      16,  -615,  -256, -1859, -1859, -1859, -1859, -1859, -1859, -1859,
   -1859,  1756, -1859, -1859, -1859, -1859, -1222, -1212,  1757, -1701,
    1758, -1859, -1859, -1859,  1164, -1859,  -158, -1859, -1859, -1859,
   -1859,  2562, -1859, -1859, -1401,   258,  1763, -1859,     0,  -701,
   -1859, -1859,   -64, -1859, -1656,   881,  -161,  3190,     9,  -308,
      43, -1859,   100,   -55, -1859, -1859,    68,   229, -1678,  -145,
    1004, -1859,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   115,  1056,   116,   117,  1040,  1877,  1883,
    1331,  1540,  2030,  2162,  1332,  2133,  2180,  1333,  2164,  1334,
    1335,  1544,   435,   589,   590,  1126,   118,   770,   459,  1893,
    2040,  1894,   460,  1767,  1406,  1361,  1362,  1363,  1504,  1705,
    1706,  1194,  1597,  1588,   750,   601,   272,   273,   350,   199,
     274,   445,   446,   122,   123,   124,   125,   126,   127,   128,
     129,   275,  1226,  2065,  2124,   936,  1222,  1223,   276,  1019,
     277,   133,  1435,  1192,   911,   951,  2000,   134,   135,   136,
     137,   278,   279,  1150,  1165,  1287,   280,   775,   281,   900,
     774,   462,   616,   318,  1742,   357,   358,   283,   559,   365,
    1318,  1533,   455,   451,  1280,   996,  1577,  1735,  1736,   981,
     457,   139,   413
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   611,   317,   319,  1464,   322,   931,   932,   456,  1626,
    1462,   303,  1013,  1030,   160,  1861,  1826,  1862,  1029,   121,
     162,  1038,  1703,   161,  1307,  1854,   645,   337,   363,   160,
     490,   726,  1325,  1260,  1524,  1979,   406,   160,   497,   436,
     408,  1044,  1457,  1459,   160,  1595,   540,   563,  1780,   284,
     401,   754,   405,   418,   147,  2111,   289,  1494,  1062,   755,
     174,   178,   342,   367,   343,   627,  1071,  1781,   163,     4,
     164,  1358,   760,   289,   585,   430,   431,  1163,   341,   290,
     761,   756,   765,  -555,   650,   441,   284,     5,  1896,  1215,
     463,   366,  1215,  1596,  1586,   160,  1047,   308,   430,   431,
     739,   333,   402,   334,   619,   620,  1216,  2092,  1422,  1216,
     464,   338,   585,   143,  1217,  1218,  1219,  1217,  1218,  1219,
    1220,  1221,   309,  1220,  1221,   926,   710,   619,   620,  1905,
     598,   599,   600,  2094,   619,   620,   144,   442,   310,   311,
    1053,   763,   452,   452,   619,   620,   149,  1560,   933,   764,
     458,   702,  1146,   705,   344,   937,   150,   444,  1495,  1496,
     764,   717,   619,   620,  1036,  1445,   145,   469,   347,  1168,
     768,   348,   641,   642,   643,   771,   769,  1349,   565,  1449,
     146,   769,  2083,   452,   349,   807,   416,   151,   284,   657,
     417,   284,   536,   537,   619,   620,   284,   284,   452,  1326,
    1327,  1328,  1329,   495,  1461,  1458,  1460,  1669,   727,   728,
     621,  1525,  1526,  1307,  1704,   339,  1159,  1354,   619,   620,
     152,  1160,  1722,   619,   620,   807,  1791,  1968,   114,  1307,
     426,   427,   428,   429,   622,  1969,   426,   427,   428,   429,
     440,   114,   114,   114,  1463,   450,   453,   153,   614,   615,
     284,   114,  1462,   430,   431,   154,   623,   628,   114,   430,
     431,   630,  1996,   995,   284,   631,   155,   284,   561,  1310,
     646,   560,   647,   340,   364,  1317,   142,   156,  1261,  1330,
     731,   407,   732,   284,   284,   409,   485,   284,   284,   284,
     284,   541,   564,   419,   157,   592,   593,   420,   148,  2112,
     284,   499,   175,   179,   284,   368,   366,   430,   431,   114,
     163,   586,   164,   587,  1308,  1311,  2034,   588,   757,   766,
     758,   758,   619,   620,   759,   767,   443,   163,   284,   164,
     284,   284,   284,   430,   431,   619,   620,   740,   158,   741,
     639,  -553,   731,   742,   732,   430,   431,   284,   171,   586,
    1156,   587,  1136,   284,   922,   588,   924,   925,   159,   430,
     431,   619,   620,   711,  1054,   712,   141,  1055,   721,   713,
     142,  1054,   172,   938,  1055,  2107,  1037,   427,   428,   429,
     323,   173,   166,   859,   731,   167,   732,   191,   168,   849,
     169,   957,   764,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   452,   284,   176,   975,   584,   284,   284,   177,   619,
     620,  1819,   619,   620,   715,   426,   427,   428,   429,   619,
     620,   668,   284,   142,   426,   427,   428,   429,   629,   743,
    1823,   426,   427,   428,   429,   619,   620,   806,   430,   431,
    1936,   807,   190,  1011,   619,   620,  2135,   430,   431,  1409,
     776,  1410,    65,    66,    67,    68,  1937,   180,    71,   619,
     620,  1215,   324,   181,  1420,  1938,   325,    80,   619,   620,
      83,   195,   326,   327,   196,   328,   329,   197,  1216,   284,
    1939,   619,   620,   430,   431,   865,  1217,  1218,  1219,  1940,
     198,  -560,  1220,  1221,   304,   330,   192,   305,  1992,  2174,
     313,   314,  1941,   284,   714,   182,   619,   620,   619,   620,
     284,   839,   315,   430,   431,   452,   316,   452,   284,   452,
     452,   458,  1285,   983,   869,  1286,   855,  2068,   807,  2069,
     284,   284,   284,   452,   452,   284,   162,   183,   162,   864,
     284,   866,   619,   620,   184,   929,   930,   619,   620,   185,
     615,   731,   867,   732,   619,   620,  1215,   619,   620,  1263,
     186,   582,   583,  2070,   619,   620,   284,   584,  2071,  1215,
     619,   620,   896,  1216,  1507,  2072,  2122,   163,  2119,   164,
    1511,  1217,  1218,  1219,   187,  2120,  1216,  1220,  1221,   619,
     620,  2129,   284,   284,  1217,  1218,  1219,   188,   619,   620,
    1220,  1221,  1652,  1653,   917,   918,   731,   163,   732,   164,
    2158,  1474,   193,  1162,  1283,  1031,  1163,   189,   843,  2159,
     845,   200,   847,   848,   194,  1546,   998,   444,   444,  1997,
    1998,   201,   313,   314,   904,  1999,   861,   862,   807,  1562,
     284,   284,   284,   294,   315,  1567,   295,   285,   321,   296,
     286,   297,   960,   961,   962,   291,   299,  1204,   292,   300,
     293,   301,    44,   458,   452,   458,   452,   452,   452,   452,
     452,   452,   302,   452,   452,   452,   452,   997,   287,   452,
     452,   452,   162,  1003,  2160,  1002,   284,  1695,  1696,  1049,
     577,   578,   708,   580,   581,   582,   583,  1012,  1004,   619,
     620,   584,   708,   580,   581,   582,   583,   731,   306,   732,
     284,   584,  2001,  2002,  1646,   807,   288,  1084,  1999,  1339,
     284,  1293,   523,  -556,   524,  1745,  1041,  1713,   731,  -557,
     732,   905,  1035,   948,  1015,   807,  1021,   807,   807,   332,
    1022,  1166,   284,  1058,   307,   807,  1199,   312,   284,  1200,
     807,   458,  1069,   807,  1057,   320,   331,  1073,  1245,   452,
    1064,  1246,   807,   335,  1247,   807,   336,   982,   807,   984,
     985,   986,   987,   988,   989,   345,   991,   992,   993,   994,
     351,  1289,   999,  1000,  1001,   807,  1320,  1395,  1178,  1402,
     807,   807,   284,   807,   284,  1419,  1427,   346,   352,   807,
     807,  1723,  1442,  1558,   353,  1608,   807,   807,   120,   807,
    1179,   359,  1180,  1732,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,   284,  1639,   360,
    1640,   584,   807,  2098,   807,   361,  1729,   284,  1752,  1137,
    1730,  1754,   807,  1835,   362,   807,  1881,   807,  1196,  1147,
    1882,  1897,  1207,  1919,  1067,  1898,  1920,   807,   369,  1213,
     807,  1935,  1075,  1224,   298,  1882,  1965,  1974,  1990,  1994,
     764,  1975,  1882,   807,  1995,   284,  1462,  2023,   807,  2043,
    2044,   807,  2051,   807,   807,  2059,  1882,  1174,   284,   807,
    2067,  2081,  2142,   371,   807,  1882,   372,   284,  2118,  2125,
    1182,  2126,   807,   807,  2127,   807,   284,  2128,   807,  2130,
    2132,   807,   370,   807,  1975,  2153,  1309,  1312,  1201,  1882,
    1462,  2161,  2171,   282,  2182,   807,  2172,   373,  1882,  2185,
     403,   160,   374,  2186,   731,   415,   732,   733,   731,   421,
     732,   901,  1292,   422,  1293,   438,  1631,  1712,  1632,  1713,
     438,   438,  1804,   414,  1805,   448,   447,   142,   438,   461,
     463,   465,   466,   467,  1313,   468,   473,   477,   491,   531,
     534,  1842,  -192,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   496,  -193,   542,  -194,   384,   385,   386,   387,
     543,   438,   546,   549,   388,   389,   390,   550,   551,  1532,
     562,   391,   594,   392,   417,   595,   438,   602,   605,   284,
     608,  1370,   610,   612,   613,   632,   393,   633,   634,   394,
    1319,   635,   648,   294,   636,   284,   295,   637,   638,   296,
     644,   297,  1815,  1816,   649,   651,   652,   653,   284,   654,
     655,   656,    44,   452,   658,   535,   659,   663,   664,   697,
    1347,   660,   670,   671,   679,   680,   681,   692,   693,   424,
     544,   545,   696,   695,   698,  1421,  1423,   700,   699,   703,
     701,   498,   704,   284,   284,   720,   284,   284,   284,   723,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     736,   730,   284,   735,   737,   738,   141,   777,   744,   773,
     782,   798,   803,   809,  1390,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,   810,   811,   840,   282,   584,   850,   395,   396,   397,
     284,   452,   452,   851,   852,   872,   584,   870,   398,   873,
     899,   909,   399,   913,   400,   114,  1348,   910,   916,   920,
     921,   923,   950,   952,   284,   953,   955,   964,   969,   973,
     976,   597,  1005,  1007,  1014,  1020,  1024,  1025,  1032,  1033,
     284,   284,   284,  1034,   604,  1046,  1045,  1733,   609,  1061,
    1051,  1077,  1063,  1429,  1430,  1066,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,  1072,  1074,  1078,  1085,   584,  1086,
    1087,  1089,  1090,  1728,  1843,  1091,  1093,  1094,  1095,   438,
    1096,  1097,  1098,  1099,   284,  1100,  1421,  1423,  1101,   722,
    1102,  1105,  1109,  1134,  1400,  1401,  1135,  1143,  1144,   284,
     284,   284,   444,  1145,  1152,  1155,  1161,  1167,  1716,  1171,
     284,   751,  1718,  1170,  1175,   452,  1183,  1184,  1191,   452,
    1185,  1193,  1498,  1202,  1210,  1211,  1214,  1236,   452,  1237,
     452,  1239,  1255,   452,  1252,  1253,  1254,  1268,  1266,  1267,
    1271,  1279,  1281,  1282,  1288,  1291,  1295,  1296,   284,  1297,
     718,   719,  1294,  1571,  1301,  1576,  1300,  1302,  1306,  2005,
    1315,  1316,  1321,  1322,   366,  1336,   729,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,   452,  1342,  1343,  1344,   584,
     284,  1345,   284,   438,  1360,   438,  1353,   438,   438,   438,
    1350,  1373,  1554,  1356,  1556,  1357,  1377,   284,  1389,  1405,
    -195,   438,   438,  1413,  1431,  1432,  1433,  1436,  1499,  1437,
     284,  1439,  1501,  1438,   284,  1440,  1441,  1443,  1451,  1454,
    1456,  1505,  1450,  1506,  1455,  1466,  1508,  1465,  1467,  1468,
    1469,  1470,  1737,  1737,  1471,  1472,  1473,  1477,  1478,  1668,
    1479,   565,  1480,  1489,  1482,  1481,  1483,  1484,  1497,  1502,
    1509,  1523,   846,  1528,  1503,  1512,  1514,  1510,  1518,  1529,
    1520,  1531,  1870,  1724,   597,  1534,   860,  1535,   284,   284,
     284,  1539,  1543,  1541,  1542,  1545,   284,  1559,  1548,  1565,
    1580,  1557,   751,  1563,  1578,  1585,  1587,  1579,  1591,  1592,
    1593,   284,  1598,  1599,  1600,  1711,  1601,  1602,  1603,  1604,
    1605,  1606,   284,  1607,  1617,   751,  1628,  1634,  1638,  1624,
     284,  1644,  1645,  1688,   284,  1651,  1665,  1649,  1666,  1650,
    1657,  1681,  1658,  1660,  1659,  1686,  1682,  1672,  1673,  1674,
    1675,   438,   438,   438,   438,   438,   438,   438,   438,   438,
    1680,   438,   438,   438,   438,  1676,  1677,   438,   438,   438,
    1683,  1687,  1692,  1693,  1764,  1694,  1698,   751,  1701,  1720,
     751,  1708,  1726,  1775,  1286,  1719,  1715,  1739,   366,  1746,
    1744,  1758,   751,  1796,   458,   458,  1725,  1747,  1749,  1751,
     284,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,  1755,  1756,   452,  1759,
     584,  1765,  1048,  1771,  1050,  1762,   284,  1772,  1773,  1774,
    1776,   284,  1777,  1778,  1779,  1783,  1782,  1784,  1785,   438,
    1790,  1163,  1797,  1799,  1798,  1801,  1820,   438,  1873,  1824,
    1825,  1834,  1838,  1856,  1857,  1866,  1858,  1867,  1810,  1900,
    1869,  1874,  -558,   764,  1026,  1886,  1887,  1888,  1889,  1827,
    1828,  1829,  1830,  1831,  1833,  1895,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   805,
     580,   581,   582,   583,  1904,  1901,  1902,  1910,   584,  1916,
     731,  1847,   732,   284,  1917,  1796,   284,   284,  1852,  1855,
    1923,  1930,  1903,  2028,  1926,  1932,  1918,  1942,  1806,  1807,
    1924,  1757,  1927,  1944,  1949,  1933,  1959,  1864,  1950,   284,
    1961,  1956,  1962,   444,   444,   284,  1963,  2011,  1957,  1958,
    1964,  1966,  1967,  1989,  2008,   284,  1972,  2013,  2009,  2025,
    2026,  2027,  2024,  2029,  2035,   452,  2055,  2058,   452,  -559,
    2062,  2063,  2074,  2075,  2077,  2042,  2090,  2038,  2039,  2095,
    2100,  2046,  2048,  2143,  2050,  2144,   284,  2145,  2146,  2052,
    2148,  2056,  2149,  1319,  2060,  2114,  2150,   366,  2066,   284,
     458,  2078,  2085,  2131,  2154,  2166,  2151,   751,  2165,   751,
     751,  2170,  2173,  2178,  2183,  2184,  2187,  2188,  1561,  2108,
    1620,   772,  1770,   751,  1980,  1800,   119,  1953,  1589,   130,
     131,   132,  2003,   458,   912,  1710,   138,  1738,  1068,  1868,
    2076,  1853,   751,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,     0,     0,     0,
     751,  1190,     0,     0,   284,   284,     0,     0,  1848,     0,
       0,  1850,     0,  1954,     0,     0,  1914,  1915,     0,     0,
    2099,     0,  1492,     0,     0,     0,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,   751,     0,     0,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,  1984,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1947,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,     0,  2015,  2016,  2017,  2018,  2019,     0,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,  1985,   284,   284,
       0,     0,     0,  1303,     0,     0,     0,     0,     0,     0,
    1986,  1987,     0,     0,     0,   284,     0,     0,   284,  1323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
    2004,     0,     0,   284,  2053,     0,     0,     0,  2057,     0,
     444,     0,     0,     0,     0,  2014,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   366,   438,
     438,     0,     0,     0,     0,     0,     0,  1371,  1372,   284,
    1374,  1375,  1376,     0,  1378,  1379,  1380,  1381,  1382,  1383,
    1384,  1385,  1386,  1387,     0,     0,  2084,     0,  2091,     0,
       0,     0,  2093,     0,     0,     0,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   751,
       0,     0,     0,     0,  1399,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,   284,  1414,   584,
       0,  1493,     0,     0,     0,  2140,  2141,     0,     0,  2089,
       0,     0,     0,     0,  1428,   284,   284,   284,   284,   284,
     753,     0,     0,     0,     0,     0,     0,  2101,  2102,  2103,
    2104,  2106,     0,   438,     0,     0,     0,   438,     0,     0,
       0,     0,     0,     0,     0,     0,   438,     0,   438,     0,
       0,   438,     0,     0,     0,     0,     0,     0,     0,   284,
    1513,     0,     0,     0,     0,     0,     0,     0,  1475,     0,
       0,     0,     0,     0,     0,     0,   284,     0,     0,     0,
       0,     0,     0,  1486,  1487,  1488,     0,     0,  2147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,     0,
       0,     0,     0,   438,     0,     0,     0,     0,     0,     0,
       0,     0,   284,     0,     0,     0,     0,     0,     0,   452,
     452,     0,   202,   160,     0,     0,     0,     0,     0,   203,
     204,   205,  1519,   452,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   410,   224,   225,   226,   227,   228,   229,  1388,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,   237,   238,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,  1575,     0,     0,     0,     0,   243,   244,   245,     0,
       0,  2163,     0,     0,  1590,     0,   246,    23,  1594,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2179,  2181,     0,     0,     0,   165,     0,   170,
       0,     0,     0,     0,     0,     0,  2189,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,     0,     0,   584,
       0,     0,  1641,  1642,  1643,     0,     0,     0,     0,     0,
    1648,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1663,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1671,     0,     0,     0,
       0,     0,   438,   438,  1679,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1476,     0,     0,   257,     0,
       0,     0,   258,     0,     0,     0,   438,   260,   261,   262,
       0,   263,   264,   265,     0,     0,     0,   114,     0,     0,
       0,     0,     0,   437,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,   411,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,   355,     0,     0,     0,   606,
       0,     0,   271,     0,  1743,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
    1763,     0,     0,     0,     0,     0,     0,     0,     0,  1517,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   525,   526,   527,   528,   529,   530,     0,
     532,   533,     0,     0,     0,     0,     0,  1530,     0,   538,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   547,   548,   438,     0,     0,   438,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1803,     0,     0,
       0,   751,     0,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   438,     0,
       0,     0,     0,  1743,     0,     0,     0,     0,     0,     0,
       0,  1661,     0,     0,     0,     0,     0,     0,     0,  1839,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   438,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
    1863,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,     0,  1872,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   676,   677,
     678,     0,     0,     0,   682,   683,   684,   685,   686,   687,
     688,     0,   689,     0,     0,     0,   690,   691,     0,     0,
     694,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   706,     0,     0,  1743,     0,     0,     0,
       0,     0,     0,     0,     0,   412,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,  1931,   439,     0,     0,     0,   449,     0,     0,     0,
     454,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,  2041,   470,   471,   472,   584,   474,   475,   476,
       0,   478,   479,   480,   481,   482,   483,   484,     0,   486,
     487,   488,   489,     0,     0,     0,   493,     0,     0,     0,
       0,     0,     0,  1973,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1981,     0,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,  1743,
     584,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2010,   871,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   751,     0,   552,   554,
     556,   557,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   591,   493,   493,
       0,     0,     0,  1743,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,     0,
    2054,     0,     0,   618,     0,     0,     0,     0,     0,     0,
       0,   751,     0,   493,   640,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   751,     0,     0,   661,   493,     0,
       0,     0,   665,   666,   667,     0,   669,     0,     0,     0,
     672,   673,   674,     0,     0,   675,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,   438,     0,     0,     0,
     584,     0,     0,   707,     0,     0,     0,   493,   716,     0,
       0,     0,     0,     0,     0,     0,     0,   438,   438,     0,
       0,     0,     0,  1743,   724,   725,     0,     0,     0,     0,
       0,   438,     0,     0,     0,     0,  1717,     0,     0,   752,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   778,   779,   780,
     781,     0,     0,     0,     0,   786,     0,     0,     0,   790,
       0,     0,     0,     0,     0,     0,  1743,     0,     0,     0,
       0,     0,     0,   804,   554,     0,     0,     0,   808,     0,
       0,     0,   812,   813,   814,   815,   816,   817,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   827,   828,   830,
     831,   832,   833,   834,   835,   836,   836,     0,   841,   842,
       0,   844,     0,     0,     0,     0,     0,     0,     0,     0,
     853,     0,     0,   857,   858,     0,     0,     0,     0,     0,
     836,     0,     0,     0,     0,   493,     0,     0,     0,  1164,
       0,     0,     0,  1721,     0,     0,     0,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
     887,   889,   891,   892,   893,   894,   895,     0,   897,   898,
       0,     0,     0,  1181,     0,     0,   906,   907,   908,     0,
       0,     0,     0,     0,   914,   915,     0,   493,   493,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   552,   707,   934,     0,
       0,     0,   939,   940,   941,   942,   943,   944,   945,   946,
     947,     0,     0,     0,     0,  1727,   954,     0,   956,     0,
       0,   958,     0,     0,     0,   493,   493,   493,   963,     0,
     965,   966,   967,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,   990,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,     0,     0,     0,     0,     0,     0,  1009,     0,
    1010,     0,     0,   897,   898,     0,     0,     0,     0,     0,
       0,     0,  1023,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,     0,  1039,     0,     0,
       0,     0,  1042,  1043,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   493,     0,  1059,
    1060,     0,     0,   493,  1065,     0,  1359,     0,  1059,     0,
       0,     0,     0,     0,     0,  1076,     0,     0,     0,  1079,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,  1103,     0,   889,     0,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   494,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,  1148,  1149,     0,     0,     0,     0,     0,
       0,  1415,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
     493,     0,     0,     0,     0,     0,     0,   555,     0,     0,
     494,     0,     0,   493,     0,     0,     0,     0,     0,     0,
       0,  1189,     0,     0,     0,  1195,   494,   494,     0,     0,
       0,   493,     0,     0,     0,     0,     0,     0,     0,  1208,
    1209,     0,     0,     0,     0,  1212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1238,     0,     0,  1240,     0,     0,     0,     0,
       0,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1837,     0,     0,     0,  1256,     0,  1258,  1259,
       0,     0,     0,     0,     0,     0,   494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1537,  1538,   160,   374,     0,     0,
    1299,     0,     0,     0,     0,     0,     0,  1305,     0,     0,
       0,     0,  1314,     0,     0,   734,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   494,     0,  1340,  1341,     0,
       0,     0,     0,   493,     0,     0,     0,     0,   375,   376,
     377,   378,   379,   380,   381,   382,   383,     0,     0,     0,
       0,   384,   385,   386,   387,     0,     0,     0,     0,   388,
     389,   390,  1365,  1366,  1367,  1368,   391,     0,   392,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   393,     0,  1625,   394,     0,     0,   493,   294,     0,
       0,   295,     0,  1633,   296,     0,   297,     0,     0,     0,
       0,     0,   555,  1391,     0,     0,     0,    44,     0,     0,
       0,     0,     0,  1392,  1393,  1394,     0,   854,     0,     0,
    1396,  1397,     0,  1398,   424,     0,   829,  1922,     0,     0,
       0,     0,     0,   837,   838,     0,     0,  1407,  1408,     0,
       0,     0,     0,     0,     0,  1411,  1412,     0,     0,     0,
       0,     0,  1416,     0,  1417,  1418,     0,     0,   863,     0,
       0,  1424,  1425,   494,     0,     0,   493,   493,   902,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,   890,
       0,   584,   395,   396,   397,     0,     0,     0,  1453,     0,
       0,     0,     0,   398,     0,     0,     0,   399,     0,   400,
     114,     0,     0,     0,     0,   494,   494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1485,   430,   431,     0,     0,     0,     0,
       0,     0,  -554,     0,  1547,   493,  1766,     0,     0,     0,
       0,     0,     0,  1500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,   494,   494,     0,     0,     0,     0,
       0,     0,     0,     0,  1424,  1425,     0,     0,     0,  1516,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1522,     0,     0,  1527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   494,
       0,     0,     0,  1948,     0,     0,     0,     0,     0,     0,
       0,  1549,     0,     0,  1552,   493,  1555,   493,     0,     0,
       0,     0,     0,     0,     0,  1564,     0,  1566,     0,  1564,
    1570,     0,     0,   494,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,   494,   584,     0,     0,     0,
       0,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1110,  1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,  1119,
    1120,     0,  1122,  1123,  1124,  1125,     0,  1127,  1128,  1129,
    1130,     0,     0,     0,     0,   890,     0,  1107,     0,     0,
    1647,  1140,     0,  1142,     0,     0,     0,  1654,  1655,  1656,
       0,     0,     0,  1151,     0,     0,  1662,     0,  1664,     0,
    1157,  1158,     0,     0,     0,  1667,     0,     0,     0,  1169,
     494,     0,     0,     0,     0,     0,     0,     0,     0,   493,
     494,     0,     0,     0,  1684,     0,     0,     0,     0,     0,
       0,     0,  1689,  1690,  1691,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1702,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1714,     0,     0,     0,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,     0,     0,     0,     0,     0,  1731,     0,     0,
       0,     0,     0,  1740,  1741,     0,     0,     0,     0,   494,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,  1768,     0,     0,  1262,
    1264,  1265,     0,     0,     0,  1269,  1270,     0,     0,  1273,
    1274,  1275,  1276,     0,  1278,     0,     0,     0,     0,  1284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1786,  1787,  1788,     0,
       0,     0,     0,     0,     0,     0,     0,  1789,     0,     0,
       0,     0,  1792,  1793,  1794,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1802,     0,     0,     0,
       0,   493,   493,  1808,     0,  1809,     0,     0,     0,     0,
       0,  1817,  1818,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1364,     0,     0,
     493,   494,  1369,     0,     0,  1836,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1846,     0,
       0,  1849,     0,     0,     0,  1851,     0,     0,     0,     0,
       0,     0,     0,     0,  1793,  1794,     0,  1860,     0,     0,
       0,     0,     0,     0,     0,  1865,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   494,     0,     0,   160,   374,
       0,  1878,     0,     0,     0,     0,  1884,  1885,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1890,     0,     0,  1891,  1890,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1426,
     375,   376,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,   384,   385,   386,   387,     0,     0,   493,
     493,   388,   389,   390,     0,     0,     0,     0,   391,     0,
     392,     0,     0,     0,   494,   494,  1925,     0,     0,     0,
       0,     0,     0,   393,     0,  1934,   394,     0,     0,     0,
     294,     0,     0,   295,   554,     0,   296,     0,   297,     0,
       0,     0,     0,  1945,  1946,     0,     0,   493,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   424,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1970,  1971,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,     0,     0,     0,     0,     0,     0,
    1983,     0,     0,   493,   493,  1988,     0,     0,     0,     0,
    1991,     0,     0,  1993,     0,     0,     0,     0,  1536,  1960,
       0,     0,     0,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,   396,   397,     0,   493,     0,
       0,     0,     0,     0,     0,   398,  2020,     0,     0,   399,
       0,   400,   114,     0,     0,     0,     0,  1572,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2031,     0,   494,     0,   494,     0,  2036,     0,     0,
    2037,   731,     0,   732,  1733,     0,     0,     0,     0,  1609,
    1610,  1611,  1612,  1613,     0,     0,     0,     0,  1618,  1619,
       0,     0,     0,     0,  1621,     0,  1623,     0,     0,  2061,
    1627,     0,     0,  1629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1637,     0,     0,     0,     0,
       0,     0,     0,     0,  2079,  2080,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2086,  2087,
       0,  2088,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2097,     0,     0,     0,     0,
     493,   493,   493,   493,   493,     0,     0,     0,     0,     0,
    1884,     0,     0,     0,  2113,     0,     0,     0,     0,     0,
       0,     0,  2073,     0,     0,     0,  1697,     0,  1700,     0,
       0,     0,  1707,     0,  1709,     0,     0,   494,     0,     0,
       0,     0,  2134,     0,     0,     0,     0,  2137,  2138,  2139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,     0,     0,     0,  1734,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,  2167,
    2168,  2169,   202,   160,   374,     0,   423,     0,     0,   203,
     204,   205,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   410,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,     0,  1769,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   235,   236,   237,   238,   384,   385,
     386,   387,   239,     0,     0,     0,   388,   389,   390,     0,
       0,  1795,     0,   391,     0,   392,   243,   244,   245,     0,
       0,     0,     0,     0,     0,     0,   246,    23,   393,   247,
       0,   394,     0,     0,     0,   294,     0,     0,   295,  2121,
       0,   296,     0,   297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,   494,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   424,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,  1875,     0,     0,  1876,     0,     0,     0,
       0,     0,  1434,     0,     0,     0,     0,     0,     0,     0,
       0,   425,     0,     0,     0,     0,     0,     0,   257,   395,
     396,   397,   258,     0,     0,     0,     0,   260,   261,   262,
     398,   263,   264,   265,   399,     0,   400,   114,   426,   427,
     428,   429,     0,     0,  1906,  1907,     0,  1909,     0,     0,
       0,     0,     0,   266,   411,     0,     0,     0,     0,     0,
     268,   430,   431,     0,     0,   432,     0,   433,     0,     0,
       0,   434,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,   494,   494,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,  1951,  1952,     0,
       0,   584,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   555,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   494,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,  1982,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,     0,
       0,    41,    42,    43,    44,  1899,   565,    46,     0,     0,
       0,   494,   494,     0,   745,    53,     0,     0,    56,   746,
       0,   747,   748,     0,   749,     0,     0,     0,     0,     0,
       0,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,   494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,     6,   374,    91,    92,    93,     0,   203,
     204,   205,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     0,     0,  1573,   376,   377,   378,   379,
     380,   381,   382,   383,   235,   236,   237,   238,   384,   385,
     386,   387,   239,   240,     0,     0,   388,   389,   390,     0,
       0,   241,   242,   391,     0,   392,   243,   244,   245,     0,
     935,     0,     0,     0,     0,     0,   246,    23,   393,   247,
       0,   394,     0,     0,     0,   248,     0,     0,   249,     0,
     494,   250,     0,   251,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,   252,     0,     0,     0,   494,   494,
     494,   494,   494,     0,   253,     0,    54,    55,     0,   254,
       0,   255,     0,     0,   256,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,    71,    72,    73,    74,    75,
      76,     0,     0,     0,    80,     0,  2156,    83,     0,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   805,   580,   581,   582,   583,   494,
       0,     0,     0,   584,     0,     0,     0,   565,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,   395,
     396,   397,   258,   259,     0,     0,     0,   260,   261,   262,
     398,   263,   264,   265,   399,     0,   400,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,   267,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,   355,   202,     6,   374,  1574,
       0,     0,   271,   203,   204,   205,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     0,     0,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   235,   236,
     237,   238,   384,   385,   386,   387,   239,   240,     0,     0,
     388,   389,   390,     0,     0,   241,   242,   391,     0,   392,
     243,   244,   245,     0,     0,     0,     0,     0,     0,     0,
     246,    23,   393,   247,     0,   394,     0,     0,     0,   248,
       0,     0,   249,     0,     0,   250,     0,   251,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,     0,
      54,    55,     0,   254,     0,   255,     0,     0,   256,     0,
       0,     0,     0,    65,    66,    67,    68,    69,     0,    71,
      72,    73,    74,    75,    76,     0,     0,     0,    80,     0,
       0,    83,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,   565,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,   395,   396,   397,   258,   259,     0,     0,
       0,   260,   261,   262,   398,   263,   264,   265,   399,     0,
     400,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   267,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,   355,
     202,     6,   354,   270,     0,     0,   271,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   236,   237,   238,     0,     0,     0,     0,
     239,   240,     0,     0,     0,     0,     0,     0,     0,   241,
     242,     0,     0,     0,   243,   244,   245,     0,     0,     0,
       0,     0,     0,     0,   246,    23,     0,   247,     0,     0,
       0,     0,     0,   248,     0,     0,   249,     0,     0,   250,
       0,   251,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,    54,    55,     0,   254,     0,   255,
       0,     0,   256,     0,     0,     0,     0,    65,    66,    67,
      68,    69,     0,    71,    72,    73,    74,    75,    76,     0,
       0,     0,    80,     0,     0,    83,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   805,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,   977,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
     258,   259,     0,     0,     0,   260,   261,   262,     0,   263,
     264,   265,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,   267,     0,     0,     0,     0,     0,   268,     0,
       0,     0,     0,   355,   202,     6,     0,   356,     0,   662,
     271,   203,   204,   205,     0,     0,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   237,   238,
       0,     0,     0,     0,   239,   240,     0,     0,     0,     0,
       0,     0,     0,   241,   242,     0,     0,     0,   243,   244,
     245,     0,     0,     0,     0,     0,     0,     0,   246,    23,
       0,   247,     0,     0,     0,     0,     0,   248,     0,     0,
     249,     0,     0,   250,     0,   251,     0,     0,     0,     0,
       0,     0,    40,     0,     0,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,     0,    54,    55,
       0,   254,     0,   255,     0,     0,   256,     0,     0,     0,
       0,    65,    66,    67,    68,    69,     0,    71,    72,    73,
      74,    75,    76,     0,     0,     0,    80,     0,     0,    83,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,  1172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,     0,   258,   259,     0,     0,     0,   260,
     261,   262,     0,   263,   264,   265,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,   492,     0,     0,     0,
       0,     0,   268,     0,     0,     0,     0,   355,   202,     6,
    1670,     0,   558,     0,   271,   203,   204,   205,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     235,   236,   237,   238,     0,     0,     0,     0,   239,   240,
       0,     0,     0,     0,     0,     0,     0,   241,   242,     0,
       0,     0,   243,   244,   245,     0,     0,     0,     0,     0,
       0,     0,   246,    23,     0,   247,     0,     0,     0,     0,
       0,   248,     0,     0,   249,     0,     0,   250,     0,   251,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,    54,    55,     0,   254,     0,   255,     0,     0,
     256,     0,     0,     0,     0,    65,    66,    67,    68,    69,
       0,    71,    72,    73,    74,    75,    76,     0,     0,     0,
      80,     0,     0,    83,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,  1173,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,     0,     0,   258,   259,
       0,     0,     0,   260,   261,   262,     0,   263,   264,   265,
       0,     0,     0,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
     267,     0,     0,     0,     0,     0,   268,     0,     0,     0,
       0,   355,   202,     6,     0,   270,     0,     0,   271,   203,
     204,   205,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,   237,   238,     0,     0,
       0,     0,   239,   240,     0,     0,     0,     0,     0,     0,
       0,   241,   242,     0,     0,     0,   243,   244,   245,     0,
       0,     0,     0,     0,     0,     0,   246,    23,     0,   247,
       0,     0,     0,     0,     0,   248,     0,     0,   249,     0,
       0,   250,     0,   251,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,    54,    55,     0,   254,
       0,   255,     0,     0,   256,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,    71,    72,    73,    74,    75,
      76,     0,     0,     0,    80,     0,     0,    83,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,  1491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,     0,
       0,     0,   258,   259,     0,     0,     0,   260,   261,   262,
       0,   263,   264,   265,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   624,  1832,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,   626,   202,     6,     0,   316,
     558,     0,   271,   203,   204,   205,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   239,   240,     0,     0,
       0,     0,     0,     0,     0,   241,   242,     0,     0,     0,
     243,   244,   245,     0,     0,     0,     0,     0,     0,     0,
     246,    23,     0,   247,     0,     0,     0,     0,     0,   248,
       0,     0,   249,     0,     0,   250,     0,   251,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,     0,
      54,    55,     0,   254,     0,   255,     0,     0,   256,     0,
       0,     0,     0,    65,    66,    67,    68,    69,     0,    71,
      72,    73,    74,    75,    76,     0,     0,     0,    80,     0,
       0,    83,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     0,     0,     0,   258,   259,     0,     0,
       0,   260,   261,   262,     0,   263,   264,   265,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   267,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,   269,
     202,     6,     0,   270,     0,     0,   271,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   236,   237,   238,     0,     0,     0,     0,
     239,   240,     0,     0,     0,     0,     0,     0,     0,   241,
     242,     0,     0,     0,   243,   244,   245,     0,     0,     0,
       0,     0,     0,     0,   246,    23,     0,   247,     0,     0,
       0,     0,     0,   248,     0,     0,   249,     0,     0,   250,
       0,   251,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,   252,     0,   404,   374,     0,     0,     0,     0,
       0,     0,   253,     0,    54,    55,     0,   254,     0,   255,
       0,     0,   256,     0,     0,     0,     0,    65,    66,    67,
      68,    69,     0,    71,    72,    73,    74,    75,    76,     0,
       0,     0,    80,     0,     0,    83,   375,   376,   377,   378,
     379,   380,   381,   382,   383,     0,     0,     0,     0,   384,
     385,   386,   387,     0,     0,     0,     0,   388,   389,   390,
       0,     0,     0,     0,   391,     0,   392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,   393,
     258,   259,   394,     0,     0,   260,   261,   262,     0,   263,
     264,   265,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,   267,     0,     0,     0,     0,     0,   268,     0,
       0,     0,     0,   355,   202,     6,     0,   270,     0,     0,
     271,   203,   204,   205,     0,     0,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   237,   238,
       0,     0,     0,     0,   239,   240,     0,     0,     0,     0,
     395,   396,   397,   241,   242,     0,     0,     0,   243,   244,
     245,   398,     0,     0,     0,   399,     0,   400,   246,    23,
       0,   247,     0,     0,     0,     0,     0,   248,     0,     0,
     249,     0,     0,   250,     0,   251,     0,     0,     0,     0,
       0,     0,    40,     0,     0,     0,   252,     0,     0,   374,
       0,     0,     0,     0,     0,     0,   253,     0,    54,    55,
       0,   254,     0,   255,     0,     0,   256,     0,     0,     0,
       0,    65,    66,    67,    68,    69,     0,    71,    72,    73,
      74,    75,    76,     0,     0,     0,    80,     0,     0,    83,
     375,   376,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,   384,   385,   386,   387,     0,     0,     0,
       0,   388,   389,   390,     0,     0,     0,     0,   391,     0,
     392,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,   393,   258,   259,   394,     0,     0,   260,
     261,   262,     0,   263,   264,   265,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,   492,     0,     0,     0,
       0,     0,   268,     0,     0,     0,     0,   355,   202,     6,
       0,   553,     0,     0,   271,   203,   204,   205,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     235,   236,   237,   238,     0,     0,     0,     0,   239,   240,
       0,     0,     0,     0,   395,   396,   397,   241,   242,     0,
       0,     0,   243,   244,   245,   398,     0,     0,     0,   399,
       0,   400,   246,    23,     0,   247,     0,     0,     0,     0,
       0,   248,     0,     0,   249,     0,     0,   250,     0,   251,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,    54,    55,     0,   254,     0,   255,     0,     0,
     256,     0,     0,     0,     0,    65,    66,    67,    68,    69,
       0,    71,    72,    73,    74,    75,    76,     0,     0,     0,
      80,     0,     0,    83,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,   731,     0,
     732,     0,     0,     0,     0,     0,  1699,     0,     0,     0,
       0,     0,     0,     0,   257,     0,     0,     0,   258,   259,
       0,     0,     0,   260,   261,   262,     0,   263,   264,   265,
       0,     0,     0,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
     492,     0,     0,     0,     0,     0,   268,     0,     0,     0,
       0,   355,   202,     6,     0,     0,   558,     0,   271,   203,
     204,   205,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,   237,   238,     0,     0,
       0,     0,   239,   240,     0,     0,     0,     0,     0,     0,
       0,   241,   242,     0,     0,     0,   243,   244,   245,     0,
       0,     0,     0,     0,     0,     0,   246,    23,     0,   247,
       0,     0,     0,     0,     0,   248,     0,     0,   249,     0,
       0,   250,     0,   251,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,    54,    55,     0,   254,
       0,   255,     0,     0,   256,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,    71,    72,    73,    74,    75,
      76,     0,     0,     0,    80,     0,     0,    83,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,   968,     0,     0,     0,     0,     0,     0,     0,
     927,     0,     0,     0,     0,     0,     0,     0,   257,     0,
       0,     0,   258,   259,     0,     0,     0,   260,   261,   262,
       0,   263,   264,   265,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,   267,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,   596,   202,     6,     0,   270,
       0,     0,   271,   203,   204,   205,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   239,   240,     0,     0,
       0,     0,     0,     0,     0,   241,   242,     0,     0,     0,
     243,   244,   245,     0,     0,     0,     0,     0,     0,     0,
     246,    23,     0,   247,     0,     0,     0,     0,     0,   248,
       0,     0,   249,     0,     0,   250,     0,   251,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,     0,
      54,    55,     0,   254,     0,   255,     0,     0,   256,     0,
       0,     0,     0,    65,    66,    67,    68,    69,     0,    71,
      72,    73,    74,    75,    76,     0,     0,     0,    80,     0,
       0,    83,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
    1813,     0,     0,     0,  1814,     0,     0,     0,     0,     0,
       0,     0,   257,     0,     0,     0,   258,   259,     0,     0,
       0,   260,   261,   262,     0,   263,   264,   265,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   267,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,   603,
     202,     6,     0,   270,     0,     0,   271,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   236,   237,   238,     0,     0,     0,     0,
     239,   240,     0,     0,     0,     0,     0,     0,     0,   241,
     242,     0,     0,     0,   243,   244,   245,     0,     0,     0,
       0,     0,     0,     0,   246,    23,     0,   247,     0,     0,
       0,     0,     0,   248,     0,     0,   249,     0,     0,   250,
       0,   251,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,    54,    55,     0,   254,     0,   255,
       0,     0,   256,     0,     0,     0,     0,    65,    66,    67,
      68,    69,     0,    71,    72,    73,    74,    75,    76,     0,
       0,     0,    80,     0,     0,    83,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,  1840,     0,     0,     0,  1841,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
     258,   259,     0,     0,     0,   260,   261,   262,     0,   263,
     264,   265,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,   492,     0,     0,     0,     0,     0,   268,     0,
       0,     0,     0,   355,   202,     6,     0,   888,     0,  1346,
     271,   203,   204,   205,     0,     0,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   237,   238,
       0,     0,     0,     0,   239,   240,     0,     0,     0,     0,
       0,     0,     0,   241,   242,     0,     0,     0,   243,   244,
     245,     0,     0,     0,     0,     0,     0,     0,   246,    23,
       0,   247,     0,     0,     0,     0,     0,   248,     0,     0,
     249,     0,     0,   250,     0,   251,     0,     0,     0,     0,
       0,     0,    40,     0,     0,     0,   252,     0,   160,   374,
       0,     0,     0,     0,     0,     0,   253,     0,    54,    55,
       0,   254,     0,   255,     0,     0,   256,     0,     0,     0,
       0,    65,    66,    67,    68,    69,     0,    71,    72,    73,
      74,    75,    76,     0,     0,     0,    80,     0,     0,    83,
     375,   376,   377,   378,   379,   380,   381,   382,   383,     0,
       0,     0,     0,   384,   385,   386,   387,     0,     0,     0,
       0,   388,   389,   390,     0,     0,     0,     0,   391,     0,
     392,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,   393,   258,   259,   394,     0,     0,   260,
     261,   262,     0,   263,   264,   265,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,   492,     0,     0,     0,
       0,     0,   268,   202,     6,     0,     0,   355,  1553,     0,
     203,   204,   205,     0,   271,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   236,   237,   238,     0,
       0,     0,     0,   239,   240,     0,     0,     0,     0,     0,
       0,     0,   241,   242,   395,   396,   397,   243,   244,   245,
       0,     0,     0,     0,     0,   398,     0,   246,    23,   399,
     247,   400,   114,     0,     0,     0,   248,     0,     0,   249,
       0,     0,   250,     0,   251,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,     0,    54,    55,     0,
     254,     0,   255,     0,     0,   256,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,    71,    72,    73,    74,
      75,    76,     0,     0,     0,    80,     0,     0,    83,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,  2006,     0,     0,
       0,  2007,     0,     0,     0,     0,     0,     0,     0,   257,
       0,     0,     0,   258,   259,     0,     0,     0,   260,   261,
     262,     0,   263,   264,   265,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,   492,     0,     0,     0,     0,
       0,   268,   202,     6,     0,     0,   355,     0,     0,   203,
     204,   205,     0,   271,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,   237,   238,     0,     0,
       0,     0,   239,   240,     0,     0,     0,     0,     0,     0,
       0,   241,   242,     0,     0,     0,   243,   244,   245,     0,
       0,     0,     0,     0,     0,     0,   246,    23,     0,   247,
       0,     0,     0,     0,     0,   248,     0,     0,   249,     0,
       0,   250,     0,   251,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,     0,    54,    55,     0,   254,
       0,   255,     0,     0,   256,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,    71,    72,    73,    74,    75,
      76,     0,     0,     0,    80,     0,     0,    83,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     762,     0,     0,     0,     0,     0,     0,     0,   257,     0,
       0,     0,   258,   259,     0,     0,     0,   260,   261,   262,
       0,   263,   264,   265,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,   267,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,   355,   202,     6,     0,  1678,
       0,     0,   271,   203,   204,   205,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   239,   240,     0,     0,
       0,     0,     0,     0,     0,   241,   242,     0,     0,     0,
     243,   244,   245,     0,     0,     0,     0,     0,     0,     0,
     246,    23,     0,   247,     0,     0,     0,     0,     0,   248,
       0,     0,   249,     0,     0,   250,     0,   251,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,     0,
      54,    55,     0,   254,     0,   255,     0,     0,   256,     0,
       0,     0,     0,    65,    66,    67,    68,    69,     0,    71,
      72,    73,    74,    75,    76,     0,     0,     0,    80,     0,
       0,    83,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   927,     0,     0,     0,     0,     0,
       0,     0,   257,     0,     0,     0,   258,   259,     0,     0,
       0,   260,   261,   262,     0,   263,   264,   265,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   624,  1832,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,   626,
     202,     6,     0,   316,     0,     0,   271,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   236,   237,   238,     0,     0,     0,     0,
     239,   240,     0,     0,     0,     0,     0,     0,     0,   241,
     242,     0,     0,     0,   243,   244,   245,     0,     0,     0,
       0,     0,     0,     0,   246,    23,     0,   247,     0,     0,
       0,     0,     0,   248,     0,     0,   249,     0,     0,   250,
       0,   251,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,     0,    54,    55,     0,   254,     0,   255,
       0,     0,   256,     0,     0,     0,     0,    65,    66,    67,
      68,    69,     0,    71,    72,    73,    74,    75,    76,     0,
       0,     0,    80,     0,     0,    83,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   928,     0,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
     258,   259,     0,     0,     0,   260,   261,   262,     0,   263,
     264,   265,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,   492,     0,     0,     0,     0,     0,   268,   202,
     160,   374,     0,   355,     0,     0,   203,   204,   205,     0,
     271,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   410,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   235,   236,   237,   238,   384,   385,   386,   387,   239,
       0,     0,     0,   388,   389,   390,     0,     0,     0,     0,
     391,     0,   392,   243,   244,   245,     0,     0,     0,     0,
       0,     0,     0,   246,    23,   393,   247,     0,   394,   202,
     160,   374,     0,     0,     0,     0,   203,   204,   205,     0,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   410,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   235,   236,   237,   238,   384,   385,   386,   387,   239,
       0,     0,     0,   388,   389,   390,     0,     0,     0,     0,
     391,     0,   392,   243,   244,   245,     0,     0,     0,     0,
       0,     0,     0,   246,    23,   393,   247,     0,   394,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,   395,   396,   397,   258,
       0,     0,     0,     0,   260,   261,   262,   398,   263,   264,
     265,   399,     0,   400,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266,   411,     0,     0,     0,     0,     0,   268,     0,     0,
       0,     0,   355,     0,     0,     0,  1569,     0,     0,   271,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   974,     0,     0,   257,   395,   396,   397,   258,
       0,     0,     0,     0,   260,   261,   262,   398,   263,   264,
     265,   399,     0,   400,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266,   411,     0,     0,     0,     0,     0,   268,     0,     0,
       0,     0,   355,   202,   160,   374,  1845,     0,     0,   271,
     203,   204,   205,     0,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   410,   224,   225,   226,   227,   228,   229,     0,
       0,     0,     0,     0,     0,     0,  1573,   376,   377,   378,
     379,   380,   381,   382,   383,   235,   236,   237,   238,   384,
     385,   386,   387,   239,     0,     0,     0,   388,   389,   390,
       0,     0,     0,     0,   391,     0,   392,   243,   244,   245,
       0,     0,     0,     0,     0,     0,     0,   246,    23,   393,
     247,     0,   394,   202,   160,   374,     0,     0,     0,     0,
     203,   204,   205,     0,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   410,   224,   225,   226,   227,   228,   229,     0,
       0,     0,     0,     0,     0,     0,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   235,   236,   237,   238,   384,
     385,   386,   387,   239,     0,     0,     0,   388,   389,   390,
       0,     0,     0,     0,   391,     0,   392,   243,   244,   245,
       0,     0,     0,     0,     0,     0,     0,   246,    23,   393,
     247,     0,   394,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
     395,   396,   397,   258,     0,     0,     0,     0,   260,   261,
     262,   398,   263,   264,   265,   399,     0,   400,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,   411,     0,     0,     0,     0,
       0,   268,     0,     0,     0,     0,   355,     0,     0,     0,
    1733,     0,     0,   271,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1080,     0,     0,   257,
     395,   396,   397,   258,     0,     0,     0,     0,   260,   261,
     262,   398,   263,   264,   265,   399,     0,   400,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,   411,     0,     0,     0,     0,
       0,   268,   202,   160,     0,     0,   355,     0,     0,   203,
     204,   205,     0,   271,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   410,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,   237,   238,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,   244,   245,     0,
       0,     0,     0,   202,   160,     0,   246,    23,   856,   247,
     203,   204,   205,     0,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   410,   224,   225,   226,   227,   228,   229,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   236,   237,   238,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,   244,   245,
       0,     0,     0,     0,     0,     0,     0,   246,    23,     0,
     247,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   708,   580,   581,   582,   583,     0,
       0,     0,     0,   584,     0,     0,     0,     0,   257,     0,
       0,     0,   258,  1081,     0,     0,     0,   260,   261,   262,
       0,   263,   264,   265,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   624,   625,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,   626,     0,     0,     0,   316,
       0,     0,   271,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,   257,
       0,     0,     0,   258,     0,  1082,     0,     0,   260,   261,
     262,     0,   263,   264,   265,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,   411,     0,     0,     0,     0,
       0,   268,   202,   160,     0,     0,   355,     0,     0,   203,
     204,   205,     0,   271,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   410,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,   237,   238,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,   244,   245,     0,
       0,     0,     0,     0,     0,     0,   246,    23,     0,   247,
     202,   160,     0,  1298,     0,     0,     0,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   410,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   236,   237,   238,     0,     0,     0,     0,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   243,   244,   245,     0,     0,     0,
       0,     0,     0,     0,   246,    23,     0,   247,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,   257,     0,
     584,     0,   258,     0,     0,     0,     0,   260,   261,   262,
    1083,   263,   264,   265,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,   411,     0,     0,     0,     0,     0,
     268,     0,     0,     0,     0,   355,  1070,     0,     0,     0,
       0,     0,   271,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1121,   257,     0,     0,     0,
     258,     0,     0,     0,     0,   260,   261,   262,     0,   263,
     264,   265,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,   411,     0,     0,     0,     0,     0,   268,   202,
     160,     0,  1452,   355,     0,     0,   203,   204,   205,     0,
     271,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   410,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   236,   237,   238,     0,     0,     0,     0,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,   244,   245,     0,     0,     0,     0,
       0,     0,     0,   246,    23,     0,   247,   202,   160,     0,
    1515,     0,     0,     0,   203,   204,   205,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   410,   224,   225,   226,
     227,   228,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     236,   237,   238,     0,     0,     0,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,   244,   245,     0,     0,     0,     0,     0,     0,
       0,   246,    23,     0,   247,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,   257,     0,   584,     0,   258,
       0,     0,     0,     0,   260,   261,   262,  1131,   263,   264,
     265,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266,   411,     0,     0,     0,     0,     0,   268,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   271,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1132,   257,     0,     0,     0,   258,     0,     0,
       0,     0,   260,   261,   262,     0,   263,   264,   265,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   266,   411,
       0,     0,     0,     0,     0,   268,   202,   160,     0,     0,
     355,     0,     0,   203,   204,   205,     0,   271,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   410,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     243,   244,   245,     0,     0,     0,     0,   202,   160,     0,
     246,    23,     0,   247,   203,   204,   205,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   410,   224,   225,   226,
     227,   228,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     236,   237,   238,     0,     0,     0,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,   244,   245,     0,     0,     0,     0,     0,     0,
       0,   246,    23,     0,   247,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,     0,   257,     0,     0,     0,   258,  1133,     0,     0,
       0,   260,   261,   262,     0,   263,   264,   265,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   411,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,   355,
    1568,     0,     0,     0,     0,     0,   271,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,     0,     0,   584,
       0,     0,     0,   257,     0,     0,     0,   258,     0,  1138,
       0,     0,   260,   261,   262,     0,   263,   264,   265,     0,
       0,     0,   114,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   266,   411,
       0,     0,     0,     0,     0,   268,   202,   160,     0,     0,
     355,  1892,     0,   203,   204,   205,     0,   271,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   410,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   239,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     243,   244,   245,    41,    42,    43,    44,     0,     0,    46,
     246,    23,     0,   247,     0,     0,   745,    53,     0,     0,
      56,   746,     0,   747,   748,     0,   749,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,    91,    92,    93,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,   257,     0,     0,     0,   258,     0,     0,     0,
       0,   260,   261,   262,     0,   263,   264,   265,     0,     0,
       0,   114,   959,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   266,   411,     0,
      41,    42,    43,    44,   268,     0,    46,     0,     0,   355,
       0,     0,     0,   745,    53,     0,   271,    56,   746,     0,
     747,   748,     0,   749,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,     0,     0,    41,    42,    43,
      44,     0,     0,    46,    91,    92,    93,     0,     0,     0,
     745,    53,     0,     0,    56,   746,     0,   747,   748,     0,
     749,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    91,    92,    93,    41,    42,    43,    44,     0,     0,
      46,     0,     0,     0,     0,     0,     0,   745,    53,  1006,
       0,    56,   746,     0,   747,   748,     0,   749,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,     0,
       0,    41,    42,    43,    44,     0,     0,    46,    91,    92,
      93,     0,     0,     0,   745,    53,  1008,     0,    56,   746,
       0,   747,   748,     0,   749,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    91,    92,    93,    41,    42,
      43,    44,     0,     0,    46,     0,     0,     0,     0,     0,
       0,   745,    53,  1203,     0,    56,   746,     0,   747,   748,
       0,   749,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,     0,     0,    41,    42,    43,    44,     0,
       0,    46,    91,    92,    93,     0,     0,     0,   745,    53,
    1205,     0,    56,   746,     0,   747,   748,     0,   749,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    91,
      92,    93,    41,    42,    43,    44,     0,     0,    46,     0,
       0,     0,     0,     0,     0,   745,    53,  1206,     0,    56,
     746,     0,   747,   748,     0,   749,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,    41,
      42,    43,    44,     0,     0,    46,    91,    92,    93,     0,
       0,     0,   745,    53,  1225,     0,    56,   746,     0,   747,
     748,     0,   749,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    91,    92,    93,    41,    42,    43,    44,
       0,     0,    46,     0,     0,     0,     0,     0,     0,   745,
      53,  1243,     0,    56,   746,     0,   747,   748,     0,   749,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,     0,     0,    41,    42,    43,    44,     0,     0,    46,
      91,    92,    93,     0,     0,     0,   745,    53,  1257,     0,
      56,   746,     0,   747,   748,     0,   749,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    91,    92,    93,
      41,    42,    43,    44,     0,     0,    46,     0,     0,     0,
       0,     0,     0,   745,    53,  1290,     0,    56,   746,     0,
     747,   748,     0,   749,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,     0,     0,    41,    42,    43,
      44,     0,     0,    46,    91,    92,    93,     0,     0,     0,
     745,    53,  1444,     0,    56,   746,     0,   747,   748,     0,
     749,     0,     0,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,    77,     0,    -4,
      -4,     0,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,    91,    92,    93,   584,     0,     0,     0,     0,     0,
      -4,    -4,     0,     0,  1141,     0,     0,     0,     0,  2064,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,     0,     0,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,    -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,  2123,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,
      -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,     0,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,    10,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,     0,    -4,     0,     0,     0,    11,    12,
      13,     0,     0,     0,    14,    15,     0,     0,     0,    16,
       0,     0,     0,     0,    17,    18,    19,    20,     0,    21,
      22,     0,    23,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,     0,    40,    41,    42,    43,    44,
      45,     0,    46,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,     0,    86,    87,
      88,     0,     0,     0,    89,     0,     0,     0,     0,    90,
      91,    92,    93,   160,   374,    94,     0,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,   110,
     111,   112,     0,     7,     8,     0,     0,     0,     0,     0,
     113,     0,   114,     0,     0,   375,   376,   377,   378,   379,
     380,   381,   382,   383,     0,     0,     0,     0,   384,   385,
     386,   387,     0,     0,     0,     0,   388,   389,   390,     0,
       0,     0,     0,   391,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   393,     0,
       0,   394,     0,     0,     0,   294,     0,     0,   295,     0,
       0,   296,     0,   297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
       0,   424,    41,    42,    43,    44,     7,     8,    46,     0,
       0,     0,     0,     0,     0,   745,    53,     0,     0,    56,
     746,     0,   747,   748,     0,   749,     0,     0,     0,  1017,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,     0,     0,     0,  1018,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,   395,
     396,   397,     0,     0,     0,     0,     0,     0,     0,     0,
     398,     0,     0,     0,   399,     0,   400,   114,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,     0,     0,    41,    42,    43,    44,     0,
       0,    46,     0,     0,     0,     0,     0,     0,   745,    53,
       0,     0,    56,   746,     0,   747,   748,     0,   749,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,    91,
      92,    93,     0,     0,     0,     0,     0,     0,  1251,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1272,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1355,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1446,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1447,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   708,   580,   581,   582,   583,     0,
       0,     0,     0,   584,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1490,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1614,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,     0,     0,   584,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1615,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1616,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1630,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1761,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1879,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1880,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1908,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1911,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   708,   580,   581,   582,   583,     0,
       0,     0,     0,   584,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1978,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2032,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,     0,     0,   584,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2033,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2047,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2049,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2082,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2110,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2115,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2116,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2117,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   708,   580,   581,   582,   583,     0,
       0,     0,     0,   584,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2157,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,   802,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,  1052,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
    1108,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   708,   580,   581,   582,   583,     0,
       0,     0,     0,   584,     0,     0,     0,     0,     0,  1153,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,  1154,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,  1197,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,  1228,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,     0,     0,   584,
       0,     0,     0,     0,     0,  1248,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,  1304,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,     0,     0,  1324,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,  1403,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,  1404,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
    1448,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   708,   580,   581,   582,   583,     0,
       0,     0,     0,   584,     0,     0,     0,     0,     0,  1521,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,  1811,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,  1822,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,  1859,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,     0,     0,   584,
       0,     0,     0,     0,     0,  1928,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,  1943,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,     0,     0,  1955,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,  2012,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,     0,
       0,  2021,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,     0,
    2022,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   708,   580,   581,   582,   583,     0,
       0,     0,     0,   584,     0,     0,     0,     0,     0,  2045,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,  2096,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,     0,     0,  2136,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,  2155,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,     0,     0,   584,
       0,     0,     0,     0,     0,  2175,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,     0,     0,  2176,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,     0,     0,  2177,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
       0,   709,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,     0,   919,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,     0,  1921,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,   731,     0,   732,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,   980,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,  1028,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,  1177,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,  1242,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,  1244,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,     0,     0,  1249,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     708,   580,   581,   582,   583,     0,     0,     0,     0,   584,
       0,     0,     0,  1250,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   708,   580,   581,
     582,   583,     0,     0,     0,     0,   584,     0,     0,     0,
    1338,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   708,   580,   581,   582,   583,     0,
       0,     0,     0,   584,     0,     0,     0,  1352,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   708,   580,   581,   582,   583,     0,     0,     0,     0,
     584,     0,     0,     0,  1550,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,     0,
       0,  1636,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   708,   580,   581,   582,   583,
       0,     0,     0,     0,   584,     0,     0,     0,  1685,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   708,   580,   581,   582,   583,     0,     0,     0,
       0,   584,     0,     0,     0,  1871,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   708,
     580,   581,   582,   583,     0,     0,     0,     0,   584,     0,
       0,     0,  1913,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   708,   580,   581,   582,
     583,     0,     0,     0,     0,   584,     0,     0,     0,  1929,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   783,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   784,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   785,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   787,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   788,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   789,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   791,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   792,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   793,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   794,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   795,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   796,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   797,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   799,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   800,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   801,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   868,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   903,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   949,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   968,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   970,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   971,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   972,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,   978,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,   979,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1016,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1027,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1088,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1092,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1104,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1176,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1186,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1187,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1188,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1198,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1227,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1229,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1230,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1231,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1232,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1233,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1234,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1235,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1241,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1337,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1351,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1551,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1581,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1582,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1583,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1584,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1622,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1635,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1748,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1750,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1753,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1760,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1812,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1821,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1844,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1912,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  1976,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  1977,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584,     0,  2109,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   708,   580,   581,   582,   583,     0,     0,
       0,     0,   584,     0,  2152,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   708,   580,
     581,   582,   583,     0,     0,     0,     0,   584
};

static const yytype_int16 yycheck[] =
{
       3,   309,    66,    67,  1226,    69,   621,   622,   153,  1410,
    1222,    60,   713,   726,     4,  1716,  1672,  1718,     7,     3,
      23,   734,     4,    23,     7,  1703,     4,     4,     4,     4,
     191,     4,     4,     7,     4,  1893,     5,     4,   199,   140,
       5,   742,     6,     6,     4,   136,     5,     5,    96,    52,
     105,   247,   107,     6,     6,     6,   102,     4,   759,   255,
       4,     4,     4,     4,     6,   321,   767,   115,   246,     6,
     248,     7,   247,   102,     9,   242,   243,   255,    81,   125,
     255,     9,     9,   250,   340,   140,    89,     0,  1766,   136,
       9,    94,   136,   184,     6,     4,   125,   156,   242,   243,
       9,   102,   105,   104,   234,   235,   153,     6,   252,   153,
     165,    88,     9,    14,   161,   162,   163,   161,   162,   163,
     167,   168,   181,   167,   168,   255,     9,   234,   235,  1785,
     291,   292,   293,     6,   234,   235,   102,   140,   197,   198,
       6,   247,   145,   146,   234,   235,     6,     6,   255,   255,
     153,   407,   247,   409,    96,   255,     6,   141,   105,   106,
     255,   417,   234,   235,     7,   255,   246,   170,    99,   870,
     249,   102,   333,   334,   335,   249,   255,   247,     8,   251,
     246,   255,  2040,   186,   115,   255,   246,     6,   191,   350,
     250,   194,   241,   242,   234,   235,   199,   200,   201,   171,
     172,   173,   174,   194,   251,   169,   169,   251,   181,   182,
     250,   181,   182,     7,   196,   192,   247,   247,   234,   235,
       6,   252,     7,   234,   235,   255,  1627,   247,   218,     7,
     219,   220,   221,   222,   250,   255,   219,   220,   221,   222,
     140,   218,   218,   218,   255,   145,   146,   246,   312,   313,
     253,   218,  1464,   242,   243,     6,   320,   321,   218,   242,
     243,   246,  1918,   253,   267,   250,     6,   270,   271,   252,
     248,   271,   250,   250,   250,   250,   254,     6,   252,   251,
     247,   250,   249,   286,   287,   250,   186,   290,   291,   292,
     293,   250,   250,   246,     6,   286,   287,   250,   250,   250,
     303,   201,   246,   246,   307,   246,   309,   242,   243,   218,
     246,   246,   248,   248,  1027,  1028,  1972,   252,   246,   246,
     248,   248,   234,   235,   252,   252,     4,   246,   331,   248,
     333,   334,   335,   242,   243,   234,   235,   246,   248,   248,
     331,   250,   247,   252,   249,   242,   243,   350,   246,   246,
     255,   248,   249,   356,   610,   252,   612,   613,   248,   242,
     243,   234,   235,   246,   230,   248,   250,   233,   423,   252,
     254,   230,   246,   629,   233,  2076,   219,   220,   221,   222,
       4,   246,    96,   544,   247,    99,   249,   117,   102,   534,
     104,   647,   255,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   414,   415,   246,   670,   245,   419,   420,   246,   234,
     235,   251,   234,   235,   415,   219,   220,   221,   222,   234,
     235,   252,   435,   254,   219,   220,   221,   222,   250,   442,
     255,   219,   220,   221,   222,   234,   235,   251,   242,   243,
     255,   255,   250,   709,   234,   235,  2112,   242,   243,  1160,
     463,  1162,   140,   141,   142,   143,   255,   246,   146,   234,
     235,   136,    96,   246,  1175,   255,   100,   155,   234,   235,
     158,    96,   106,   107,    99,   109,   110,   102,   153,   492,
     255,   234,   235,   242,   243,   550,   161,   162,   163,   255,
     115,   250,   167,   168,    99,   129,   102,   102,  1909,  2165,
     234,   235,   255,   516,   414,   246,   234,   235,   234,   235,
     523,   524,   246,   242,   243,   528,   250,   530,   531,   532,
     533,   534,   252,   678,   251,   255,   539,   255,   255,   255,
     543,   544,   545,   546,   547,   548,   549,   246,   551,   549,
     553,   551,   234,   235,   246,   619,   620,   234,   235,   246,
     624,   247,   553,   249,   234,   235,   136,   234,   235,   255,
     246,   239,   240,   255,   234,   235,   579,   245,   255,   136,
     234,   235,   585,   153,  1285,   255,   251,   246,   255,   248,
    1291,   161,   162,   163,   246,   255,   153,   167,   168,   234,
     235,   255,   605,   606,   161,   162,   163,   246,   234,   235,
     167,   168,     6,     7,   605,   606,   247,   246,   249,   248,
     255,  1236,     6,   252,   255,   726,   255,   246,   528,   255,
     530,   104,   532,   533,   250,  1336,   691,   621,   622,   140,
     141,   246,   234,   235,   251,   146,   546,   547,   255,  1350,
     653,   654,   655,    96,   246,  1356,    99,   246,   250,   102,
     250,   104,   653,   654,   655,    99,    99,   923,   102,   102,
     104,   104,   115,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   115,   686,   687,   688,   689,   690,   250,   692,
     693,   694,   695,   696,   251,   695,   699,     6,     7,   748,
     234,   235,   236,   237,   238,   239,   240,   710,   699,   234,
     235,   245,   236,   237,   238,   239,   240,   247,   246,   249,
     723,   245,   140,   141,  1437,   255,   102,   782,   146,   246,
     733,   248,   246,   250,   248,   246,   739,   248,   247,   250,
     249,   251,   733,   251,   251,   255,   251,   255,   255,   246,
     255,   251,   755,   756,    99,   255,   251,   250,   761,   251,
     255,   764,   765,   255,   755,   250,   250,   770,   251,   772,
     761,   251,   255,   102,   251,   255,    99,   677,   255,   679,
     680,   681,   682,   683,   684,    99,   686,   687,   688,   689,
       4,   251,   692,   693,   694,   255,   251,   251,   899,   251,
     255,   255,   805,   255,   807,   251,   251,   102,     4,   255,
     255,  1524,   251,   251,     4,   251,   255,   255,     3,   255,
     246,     4,   248,  1536,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   840,   251,   246,
     251,   245,   255,  2065,   255,   246,   251,   850,   251,   840,
     255,   251,   255,   251,   246,   255,   251,   255,   913,   850,
     255,   251,   926,   251,   764,   255,   251,   255,   246,   933,
     255,   251,   772,   937,    59,   255,   251,   251,   251,   251,
     255,   255,   255,   255,   251,   888,  2098,   251,   255,   251,
     251,   255,   251,   255,   255,   251,   255,   888,   901,   255,
     251,   251,  2124,     6,   255,   255,     6,   910,   251,   251,
     901,   251,   255,   255,   251,   255,   919,   251,   255,   251,
     251,   255,   246,   255,   255,   251,  1027,  1028,   919,   255,
    2142,   251,   251,    52,   251,   255,   255,   248,   255,   251,
     246,     4,     5,   255,   247,   250,   249,   250,   247,     6,
     249,   250,   246,   254,   248,   140,   246,   246,   248,   248,
     145,   146,     4,   248,     6,     6,   250,   254,   153,   246,
       9,   246,   246,   246,  1029,   246,   246,   246,   246,   246,
     246,     8,   184,    46,    47,    48,    49,    50,    51,    52,
      53,    54,   250,   184,   250,   184,    59,    60,    61,    62,
     125,   186,   246,   246,    67,    68,    69,   246,   246,  1317,
     184,    74,   246,    76,   250,   246,   201,   250,   250,  1022,
       4,  1085,   250,   250,   250,   246,    89,   246,   246,    92,
    1033,   246,     6,    96,   246,  1038,    99,   246,   246,   102,
     246,   104,  1657,  1658,   248,     6,     6,   250,  1051,   250,
     250,   250,   115,  1056,   248,   240,   248,     6,     6,     6,
    1051,   248,   250,   184,   246,   246,   246,   246,   246,   132,
     255,   256,   248,   246,     6,  1176,  1177,     6,   250,     6,
       8,   200,     8,  1086,  1087,   250,  1089,  1090,  1091,     7,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
       6,     6,  1105,   250,   250,     6,   250,   255,   251,    91,
     255,   247,     7,     6,  1105,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     6,   247,   250,   253,   245,   250,   200,   201,   202,
    1143,  1144,  1145,   250,   250,    64,   245,   252,   211,     8,
       4,     7,   215,   246,   217,   218,  1056,     7,     6,   247,
       6,   250,     7,     6,  1167,     7,     6,     6,   251,   181,
     250,   290,   251,   251,   249,   247,     6,   250,   252,     7,
    1183,  1184,  1185,     6,   303,   246,   248,   250,   307,     4,
     250,   247,     6,  1184,  1185,     6,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     6,     6,   248,     7,   245,     7,
       7,     7,     7,  1531,   251,     7,     7,     7,     7,   414,
       7,     7,     7,     7,  1237,     7,  1337,  1338,     7,   424,
       7,   250,     6,   247,  1144,  1145,   249,   255,   255,  1252,
    1253,  1254,  1236,   255,   251,   255,   247,     7,  1514,   251,
    1263,   446,  1518,   250,   252,  1268,     7,   250,     4,  1272,
     250,     6,  1263,   252,   251,   251,   136,   250,  1281,     7,
    1283,     6,   252,  1286,     7,     7,     7,   255,   247,   247,
     255,     9,   255,   247,   249,   252,   184,     7,  1301,   156,
     419,   420,   254,  1358,   250,  1360,   251,     6,     6,  1924,
       6,     4,    46,    46,  1317,   252,   435,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,  1338,   246,   250,   246,   245,
    1343,   250,  1345,   528,     4,   530,   246,   532,   533,   534,
     252,     7,  1343,   252,  1345,   246,     7,  1360,     7,   255,
     184,   546,   547,   247,     7,     7,     7,     6,  1268,   247,
    1373,     7,  1272,   255,  1377,     7,     7,     4,     4,   250,
     246,  1281,   114,  1283,     6,     6,  1286,     7,     7,     7,
       7,     7,  1537,  1538,     7,     7,     7,   250,     6,  1463,
       6,     8,     6,     4,     7,   102,     6,     6,     4,   253,
     247,     6,   531,     6,   255,   250,   250,   255,   250,     6,
     251,     7,  1730,  1524,   543,     6,   545,   248,  1431,  1432,
    1433,     6,   250,   246,   246,     6,  1439,     6,  1338,     6,
       6,   251,   627,   252,   249,     6,   129,   255,     6,     6,
       6,  1454,     6,     6,     6,  1510,     6,     6,     6,     6,
       6,     6,  1465,     5,   247,   650,     6,     4,     6,   247,
    1473,     4,     6,   180,  1477,     7,     6,   250,     6,   250,
     250,     6,   250,   248,   250,     6,  1477,   250,   250,   250,
     250,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     251,   686,   687,   688,   689,   250,   250,   692,   693,   694,
     250,     6,     6,     6,  1569,     6,   255,   702,   255,     6,
     705,   247,     7,  1587,   255,   255,   250,   246,  1531,     4,
     250,   246,   717,  1634,  1537,  1538,   252,     6,     6,   251,
    1543,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     6,     6,  1561,     4,
     245,     7,   747,     6,   749,   246,  1569,     6,     6,     6,
       6,  1574,     6,     6,     6,     6,   100,     5,   250,   764,
     247,   255,   250,     6,   250,     6,   255,   772,  1733,     6,
       6,     6,     6,   255,   247,     6,   255,     4,  1653,     7,
       6,     6,   250,   255,   723,     6,     6,     6,     6,  1673,
    1674,  1675,  1676,  1677,  1678,   250,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     5,   250,   250,   247,   245,     6,
     247,  1696,   249,  1646,     6,  1746,  1649,  1650,  1703,  1704,
       6,     6,   250,  1961,   251,     7,   250,     6,  1649,  1650,
     250,  1561,   251,   179,     6,   250,     6,  1722,   247,  1672,
       7,   251,     6,  1657,  1658,  1678,   252,  1933,   251,   251,
       6,     6,     6,     6,     6,  1688,   250,     6,   251,     6,
     250,     6,   247,   182,     6,  1698,     6,     6,  1701,   250,
       6,   136,     6,     6,     6,   246,     6,   251,   251,     6,
       6,   250,   247,     6,   250,     6,  1719,     6,     6,   250,
       6,   250,     6,  1726,   251,   251,     6,  1730,   250,  1732,
    1733,   250,   247,   251,     6,     6,   250,   922,   250,   924,
     925,     6,   250,     6,     6,     6,     6,     6,  1349,  2078,
    1405,   460,  1579,   938,  1894,  1642,     3,  1856,  1372,     3,
       3,     3,  1920,  1766,   600,  1507,     3,  1538,   764,  1726,
    2026,  1703,   957,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1785,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     975,   910,    -1,    -1,  1797,  1798,    -1,    -1,  1698,    -1,
      -1,  1701,    -1,  1858,    -1,    -1,  1797,  1798,    -1,    -1,
    2066,    -1,     8,    -1,    -1,    -1,    -1,  1820,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1011,    -1,    -1,  1832,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1845,    -1,  1899,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1845,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1056,    -1,  1937,  1938,  1939,  1940,  1941,    -1,  1882,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1895,    -1,    -1,    -1,    -1,  1900,  1901,  1902,
      -1,    -1,    -1,  1022,    -1,    -1,    -1,    -1,    -1,    -1,
    1901,  1902,    -1,    -1,    -1,  1918,    -1,    -1,  1921,  1038,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1932,
    1921,    -1,    -1,  1936,  1998,    -1,    -1,    -1,  2002,    -1,
    1924,    -1,    -1,    -1,    -1,  1936,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1961,  1144,
    1145,    -1,    -1,    -1,    -1,    -1,    -1,  1086,  1087,  1972,
    1089,  1090,  1091,    -1,  1093,  1094,  1095,  1096,  1097,  1098,
    1099,  1100,  1101,  1102,    -1,    -1,  2041,    -1,  2052,    -1,
      -1,    -1,  2056,    -1,    -1,    -1,  1999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2072,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1204,
      -1,    -1,    -1,    -1,  1143,    -1,    -1,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,  2050,  1167,   245,
      -1,   247,    -1,    -1,    -1,  2119,  2120,    -1,    -1,  2050,
      -1,    -1,    -1,    -1,  1183,  2068,  2069,  2070,  2071,  2072,
       6,    -1,    -1,    -1,    -1,    -1,    -1,  2068,  2069,  2070,
    2071,  2072,    -1,  1268,    -1,    -1,    -1,  1272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1281,    -1,  1283,    -1,
      -1,  1286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2112,
    1295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1237,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2129,    -1,    -1,    -1,
      -1,    -1,    -1,  1252,  1253,  1254,    -1,    -1,  2129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2151,    -1,
      -1,    -1,    -1,  1338,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2165,    -1,    -1,    -1,    -1,    -1,    -1,  2172,
    2173,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,  1301,  2186,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1360,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,  2151,    -1,    -1,  1373,    -1,    87,    88,  1377,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2172,  2173,    -1,    -1,    -1,    24,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,  2186,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,  1431,  1432,  1433,    -1,    -1,    -1,    -1,    -1,
    1439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1454,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1465,    -1,    -1,    -1,
      -1,    -1,  1537,  1538,  1473,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,   199,    -1,
      -1,    -1,   203,    -1,    -1,    -1,  1561,   208,   209,   210,
      -1,   212,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,   250,
      -1,    -1,   253,    -1,  1543,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
    1569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,    -1,
     237,   238,    -1,    -1,    -1,    -1,    -1,     6,    -1,   246,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   259,  1698,    -1,    -1,  1701,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1646,    -1,    -1,
      -1,  1716,    -1,  1718,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1733,    -1,
      -1,    -1,    -1,  1672,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1688,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1766,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
    1719,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1732,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   375,   376,
     377,    -1,    -1,    -1,   381,   382,   383,   384,   385,   386,
     387,    -1,   389,    -1,    -1,    -1,   393,   394,    -1,    -1,
     397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   410,    -1,    -1,  1785,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,  1820,   140,    -1,    -1,    -1,   144,    -1,    -1,    -1,
     148,    -1,    -1,    -1,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     7,   171,   172,   173,   245,   175,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,  1882,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1895,    -1,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,  1918,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1932,   561,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2011,    -1,   266,   267,
     268,   269,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,   286,   287,
      -1,    -1,    -1,  1972,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   315,   316,    -1,
    1999,    -1,    -1,   321,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2076,    -1,   331,   332,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2099,    -1,    -1,   355,   356,    -1,
      -1,    -1,   360,   361,   362,    -1,   364,    -1,    -1,    -1,
     368,   369,   370,    -1,    -1,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,  2151,    -1,    -1,    -1,
     245,    -1,    -1,   411,    -1,    -1,    -1,   415,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2172,  2173,    -1,
      -1,    -1,    -1,  2112,   432,   433,    -1,    -1,    -1,    -1,
      -1,  2186,    -1,    -1,    -1,    -1,     6,    -1,    -1,   447,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,   466,   467,
     468,    -1,    -1,    -1,    -1,   473,    -1,    -1,    -1,   477,
      -1,    -1,    -1,    -1,    -1,    -1,  2165,    -1,    -1,    -1,
      -1,    -1,    -1,   491,   492,    -1,    -1,    -1,   496,    -1,
      -1,    -1,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,    -1,   526,   527,
      -1,   529,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     538,    -1,    -1,   541,   542,    -1,    -1,    -1,    -1,    -1,
     548,    -1,    -1,    -1,    -1,   553,    -1,    -1,    -1,   866,
      -1,    -1,    -1,     6,    -1,    -1,    -1,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,    -1,   586,   587,
      -1,    -1,    -1,   900,    -1,    -1,   594,   595,   596,    -1,
      -1,    -1,    -1,    -1,   602,   603,    -1,   605,   606,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   624,   625,   626,    -1,
      -1,    -1,   630,   631,   632,   633,   634,   635,   636,   637,
     638,    -1,    -1,    -1,    -1,     6,   644,    -1,   646,    -1,
      -1,   649,    -1,    -1,    -1,   653,   654,   655,   656,    -1,
     658,   659,   660,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,   685,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   699,    -1,    -1,    -1,    -1,    -1,    -1,   706,    -1,
     708,    -1,    -1,   711,   712,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   733,    -1,   735,    -1,    -1,
      -1,    -1,   740,   741,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   755,    -1,   757,
     758,    -1,    -1,   761,   762,    -1,  1073,    -1,   766,    -1,
      -1,    -1,    -1,    -1,    -1,   773,    -1,    -1,    -1,   777,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,   803,    -1,   805,    -1,   807,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   840,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   850,   851,   852,    -1,    -1,    -1,    -1,    -1,
      -1,  1168,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     888,    -1,    -1,    -1,    -1,    -1,    -1,   267,    -1,    -1,
     270,    -1,    -1,   901,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   909,    -1,    -1,    -1,   913,   286,   287,    -1,    -1,
      -1,   919,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   927,
     928,    -1,    -1,    -1,    -1,   933,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   950,    -1,    -1,   953,    -1,    -1,    -1,    -1,
      -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,   974,    -1,   976,   977,
      -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   995,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1321,  1322,     4,     5,    -1,    -1,
    1018,    -1,    -1,    -1,    -1,    -1,    -1,  1025,    -1,    -1,
      -1,    -1,  1030,    -1,    -1,   437,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   415,    -1,  1045,  1046,    -1,
      -1,    -1,    -1,  1051,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,  1080,  1081,  1082,  1083,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,  1410,    92,    -1,    -1,  1105,    96,    -1,
      -1,    99,    -1,  1420,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,   492,  1121,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,  1131,  1132,  1133,    -1,   539,    -1,    -1,
    1138,  1139,    -1,  1141,   132,    -1,   516,     6,    -1,    -1,
      -1,    -1,    -1,   523,   524,    -1,    -1,  1155,  1156,    -1,
      -1,    -1,    -1,    -1,    -1,  1163,  1164,    -1,    -1,    -1,
      -1,    -1,  1170,    -1,  1172,  1173,    -1,    -1,   548,    -1,
      -1,  1179,  1180,   553,    -1,    -1,  1184,  1185,   590,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,   579,
      -1,   245,   200,   201,   202,    -1,    -1,    -1,  1216,    -1,
      -1,    -1,    -1,   211,    -1,    -1,    -1,   215,    -1,   217,
     218,    -1,    -1,    -1,    -1,   605,   606,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1251,   242,   243,    -1,    -1,    -1,    -1,
      -1,    -1,   250,    -1,   252,  1263,  1573,    -1,    -1,    -1,
      -1,    -1,    -1,  1271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   653,   654,   655,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1292,  1293,    -1,    -1,    -1,  1297,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1308,    -1,    -1,  1311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   699,
      -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1339,    -1,    -1,  1342,  1343,  1344,  1345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1353,    -1,  1355,    -1,  1357,
    1358,    -1,    -1,   733,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,   755,   245,    -1,    -1,    -1,
      -1,   761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     812,   813,   814,   815,   816,   817,   818,   819,   820,   821,
     822,    -1,   824,   825,   826,   827,    -1,   829,   830,   831,
     832,    -1,    -1,    -1,    -1,   805,    -1,   807,    -1,    -1,
    1438,   843,    -1,   845,    -1,    -1,    -1,  1445,  1446,  1447,
      -1,    -1,    -1,   855,    -1,    -1,  1454,    -1,  1456,    -1,
     862,   863,    -1,    -1,    -1,  1463,    -1,    -1,    -1,   871,
     840,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1477,
     850,    -1,    -1,    -1,  1482,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1490,  1491,  1492,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1502,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1512,    -1,    -1,    -1,   888,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   901,    -1,    -1,    -1,    -1,    -1,  1535,    -1,    -1,
      -1,    -1,    -1,  1541,  1542,    -1,    -1,    -1,    -1,   919,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,  1574,    -1,    -1,   981,
     982,   983,    -1,    -1,    -1,   987,   988,    -1,    -1,   991,
     992,   993,   994,    -1,   996,    -1,    -1,    -1,    -1,  1001,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1614,  1615,  1616,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1625,    -1,    -1,
      -1,    -1,  1630,  1631,  1632,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1644,    -1,    -1,    -1,
      -1,  1649,  1650,  1651,    -1,  1653,    -1,    -1,    -1,    -1,
      -1,  1659,  1660,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1079,    -1,    -1,
    1678,  1051,  1084,    -1,    -1,  1683,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,
      -1,  1699,    -1,    -1,    -1,  1703,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1712,  1713,    -1,  1715,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1723,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1105,    -1,    -1,     4,     5,
      -1,  1739,    -1,    -1,    -1,    -1,  1744,  1745,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1758,    -1,    -1,  1761,  1762,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1181,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,  1797,
    1798,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    -1,  1184,  1185,  1814,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,  1823,    92,    -1,    -1,    -1,
      96,    -1,    -1,    99,  1832,    -1,   102,    -1,   104,    -1,
      -1,    -1,    -1,  1841,  1842,    -1,    -1,  1845,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1879,  1880,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1263,    -1,    -1,    -1,    -1,    -1,    -1,
    1898,    -1,    -1,  1901,  1902,  1903,    -1,    -1,    -1,    -1,
    1908,    -1,    -1,  1911,    -1,    -1,    -1,    -1,  1320,     6,
      -1,    -1,    -1,  1921,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   201,   202,    -1,  1936,    -1,
      -1,    -1,    -1,    -1,    -1,   211,  1944,    -1,    -1,   215,
      -1,   217,   218,    -1,    -1,    -1,    -1,  1359,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1969,    -1,  1343,    -1,  1345,    -1,  1975,    -1,    -1,
    1978,   247,    -1,   249,   250,    -1,    -1,    -1,    -1,  1391,
    1392,  1393,  1394,  1395,    -1,    -1,    -1,    -1,  1400,  1401,
      -1,    -1,    -1,    -1,  1406,    -1,  1408,    -1,    -1,  2007,
    1412,    -1,    -1,  1415,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2032,  2033,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2046,  2047,
      -1,  2049,  2050,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2063,    -1,    -1,    -1,    -1,
    2068,  2069,  2070,  2071,  2072,    -1,    -1,    -1,    -1,    -1,
    2078,    -1,    -1,    -1,  2082,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,  1498,    -1,  1500,    -1,
      -1,    -1,  1504,    -1,  1506,    -1,    -1,  1477,    -1,    -1,
      -1,    -1,  2110,    -1,    -1,    -1,    -1,  2115,  2116,  2117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2129,    -1,    -1,    -1,  1537,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,  2157,
    2158,  2159,     3,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,  1574,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,  1633,    -1,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,     6,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,  1649,
    1650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1678,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,  1735,    -1,    -1,  1738,    -1,    -1,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,
     201,   202,   203,    -1,    -1,    -1,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,   217,   218,   219,   220,
     221,   222,    -1,    -1,  1786,  1787,    -1,  1789,    -1,    -1,
      -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,
     241,   242,   243,    -1,    -1,   246,    -1,   248,    -1,    -1,
      -1,   252,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,  1797,  1798,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,  1849,  1850,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1832,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1845,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,  1896,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,     7,     8,   118,    -1,    -1,
      -1,  1901,  1902,    -1,   125,   126,    -1,    -1,   129,   130,
      -1,   132,   133,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,  1921,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,  1936,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,   176,   177,   178,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    73,    74,    -1,    76,    77,    78,    79,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
    2050,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,   115,    -1,    -1,    -1,  2068,  2069,
    2070,  2071,  2072,    -1,   125,    -1,   127,   128,    -1,   130,
      -1,   132,    -1,    -1,   135,    -1,    -1,    -1,    -1,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,    -1,  2138,   158,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,  2129,
      -1,    -1,    -1,   245,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,
     201,   202,   203,   204,    -1,    -1,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,   217,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,     3,     4,     5,   250,
      -1,    -1,   253,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    73,    74,    -1,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    90,    -1,    92,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
     127,   128,    -1,   130,    -1,   132,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,    -1,
      -1,   158,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   200,   201,   202,   203,   204,    -1,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
     217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,   246,
       3,     4,     5,   250,    -1,    -1,   253,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    -1,   127,   128,    -1,   130,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,   155,    -1,    -1,   158,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
     203,   204,    -1,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,   246,     3,     4,    -1,   250,    -1,     8,
     253,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      99,    -1,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,
      -1,   130,    -1,   132,    -1,    -1,   135,    -1,    -1,    -1,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,   158,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,   203,   204,    -1,    -1,    -1,   208,
     209,   210,    -1,   212,   213,   214,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,   246,     3,     4,
       5,    -1,   251,    -1,   253,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    99,    -1,    -1,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,   127,   128,    -1,   130,    -1,   132,    -1,    -1,
     135,    -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,   158,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,   203,   204,
      -1,    -1,    -1,   208,   209,   210,    -1,   212,   213,   214,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     235,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,   246,     3,     4,    -1,   250,    -1,    -1,   253,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,   130,
      -1,   132,    -1,    -1,   135,    -1,    -1,    -1,    -1,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,    -1,    -1,   158,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,   203,   204,    -1,    -1,    -1,   208,   209,   210,
      -1,   212,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,     3,     4,    -1,   250,
     251,    -1,   253,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
     127,   128,    -1,   130,    -1,   132,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,    -1,
      -1,   158,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,   203,   204,    -1,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,   246,
       3,     4,    -1,   250,    -1,    -1,   253,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,   115,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    -1,   127,   128,    -1,   130,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,   155,    -1,    -1,   158,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    89,
     203,   204,    92,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,   246,     3,     4,    -1,   250,    -1,    -1,
     253,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
     200,   201,   202,    72,    73,    -1,    -1,    -1,    77,    78,
      79,   211,    -1,    -1,    -1,   215,    -1,   217,    87,    88,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      99,    -1,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,
      -1,   130,    -1,   132,    -1,    -1,   135,    -1,    -1,    -1,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,   158,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    89,   203,   204,    92,    -1,    -1,   208,
     209,   210,    -1,   212,   213,   214,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,   246,     3,     4,
      -1,   250,    -1,    -1,   253,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,   200,   201,   202,    72,    73,    -1,
      -1,    -1,    77,    78,    79,   211,    -1,    -1,    -1,   215,
      -1,   217,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    99,    -1,    -1,   102,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,   127,   128,    -1,   130,    -1,   132,    -1,    -1,
     135,    -1,    -1,    -1,    -1,   140,   141,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,   158,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,    -1,
     249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,   203,   204,
      -1,    -1,    -1,   208,   209,   210,    -1,   212,   213,   214,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     235,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,   246,     3,     4,    -1,    -1,   251,    -1,   253,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,   130,
      -1,   132,    -1,    -1,   135,    -1,    -1,    -1,    -1,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,    -1,    -1,   158,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,   203,   204,    -1,    -1,    -1,   208,   209,   210,
      -1,   212,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,     3,     4,    -1,   250,
      -1,    -1,   253,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
     127,   128,    -1,   130,    -1,   132,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,    -1,
      -1,   158,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,   203,   204,    -1,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,   246,
       3,     4,    -1,   250,    -1,    -1,   253,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    -1,   127,   128,    -1,   130,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,   155,    -1,    -1,   158,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
     203,   204,    -1,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,   246,     3,     4,    -1,   250,    -1,     8,
     253,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      99,    -1,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,
      -1,   130,    -1,   132,    -1,    -1,   135,    -1,    -1,    -1,
      -1,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,   158,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    89,   203,   204,    92,    -1,    -1,   208,
     209,   210,    -1,   212,   213,   214,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,     3,     4,    -1,    -1,   246,     8,    -1,
      10,    11,    12,    -1,   253,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,   200,   201,   202,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,   211,    -1,    87,    88,   215,
      90,   217,   218,    -1,    -1,    -1,    96,    -1,    -1,    99,
      -1,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,
     130,    -1,   132,    -1,    -1,   135,    -1,    -1,    -1,    -1,
     140,   141,   142,   143,   144,    -1,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,   155,    -1,    -1,   158,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,   203,   204,    -1,    -1,    -1,   208,   209,
     210,    -1,   212,   213,   214,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,
      -1,   241,     3,     4,    -1,    -1,   246,    -1,    -1,    10,
      11,    12,    -1,   253,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,   127,   128,    -1,   130,
      -1,   132,    -1,    -1,   135,    -1,    -1,    -1,    -1,   140,
     141,   142,   143,   144,    -1,   146,   147,   148,   149,   150,
     151,    -1,    -1,    -1,   155,    -1,    -1,   158,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,   203,   204,    -1,    -1,    -1,   208,   209,   210,
      -1,   212,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,     3,     4,    -1,   250,
      -1,    -1,   253,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,   102,    -1,   104,    -1,    -1,
      -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
     127,   128,    -1,   130,    -1,   132,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,    -1,    -1,    -1,   155,    -1,
      -1,   158,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,   203,   204,    -1,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,   246,
       3,     4,    -1,   250,    -1,    -1,   253,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,   102,
      -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    -1,   127,   128,    -1,   130,    -1,   132,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,    -1,   146,   147,   148,   149,   150,   151,    -1,
      -1,    -1,   155,    -1,    -1,   158,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
     203,   204,    -1,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   235,    -1,    -1,    -1,    -1,    -1,   241,     3,
       4,     5,    -1,   246,    -1,    -1,    10,    11,    12,    -1,
     253,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    -1,    92,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   199,   200,   201,   202,   203,
      -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,   250,    -1,    -1,   253,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,   199,   200,   201,   202,   203,
      -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,   246,     3,     4,     5,   250,    -1,    -1,   253,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    -1,    92,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    -1,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
     200,   201,   202,   203,    -1,    -1,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   217,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
     250,    -1,    -1,   253,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,   199,
     200,   201,   202,   203,    -1,    -1,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,    -1,   217,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,
      -1,   241,     3,     4,    -1,    -1,   246,    -1,    -1,    10,
      11,    12,    -1,   253,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,     3,     4,    -1,    87,    88,     8,    90,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,   203,   255,    -1,    -1,    -1,   208,   209,   210,
      -1,   212,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,   250,
      -1,    -1,   253,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   199,
      -1,    -1,    -1,   203,    -1,   255,    -1,    -1,   208,   209,
     210,    -1,   212,   213,   214,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,
      -1,   241,     3,     4,    -1,    -1,   246,    -1,    -1,    10,
      11,    12,    -1,   253,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,   199,    -1,
     245,    -1,   203,    -1,    -1,    -1,    -1,   208,   209,   210,
     255,   212,   213,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   234,   235,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   246,   247,    -1,    -1,    -1,
      -1,    -1,   253,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   255,   199,    -1,    -1,    -1,
     203,    -1,    -1,    -1,    -1,   208,   209,   210,    -1,   212,
     213,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   234,   235,    -1,    -1,    -1,    -1,    -1,   241,     3,
       4,    -1,     6,   246,    -1,    -1,    10,    11,    12,    -1,
     253,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    90,     3,     4,    -1,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,   199,    -1,   245,    -1,   203,
      -1,    -1,    -1,    -1,   208,   209,   210,   255,   212,   213,
     214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,   253,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,   199,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,   208,   209,   210,    -1,   212,   213,   214,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,
      -1,    -1,    -1,    -1,    -1,   241,     3,     4,    -1,    -1,
     246,    -1,    -1,    10,    11,    12,    -1,   253,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,     3,     4,    -1,
      87,    88,    -1,    90,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,   203,   255,    -1,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,    -1,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,   246,
     247,    -1,    -1,    -1,    -1,    -1,   253,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,   199,    -1,    -1,    -1,   203,    -1,   255,
      -1,    -1,   208,   209,   210,    -1,   212,   213,   214,    -1,
      -1,    -1,   218,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,
      -1,    -1,    -1,    -1,    -1,   241,     3,     4,    -1,    -1,
     246,   247,    -1,    10,    11,    12,    -1,   253,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      77,    78,    79,   112,   113,   114,   115,    -1,    -1,   118,
      87,    88,    -1,    90,    -1,    -1,   125,   126,    -1,    -1,
     129,   130,    -1,   132,   133,    -1,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,   176,   177,   178,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,   199,    -1,    -1,    -1,   203,    -1,    -1,    -1,
      -1,   208,   209,   210,    -1,   212,   213,   214,    -1,    -1,
      -1,   218,   251,    -1,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   234,   235,    -1,
     112,   113,   114,   115,   241,    -1,   118,    -1,    -1,   246,
      -1,    -1,    -1,   125,   126,    -1,   253,   129,   130,    -1,
     132,   133,    -1,   135,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,    -1,    -1,   118,   176,   177,   178,    -1,    -1,    -1,
     125,   126,    -1,    -1,   129,   130,    -1,   132,   133,    -1,
     135,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   176,   177,   178,   112,   113,   114,   115,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   251,
      -1,   129,   130,    -1,   132,   133,    -1,   135,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,    -1,    -1,   118,   176,   177,
     178,    -1,    -1,    -1,   125,   126,   251,    -1,   129,   130,
      -1,   132,   133,    -1,   135,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   176,   177,   178,   112,   113,
     114,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   251,    -1,   129,   130,    -1,   132,   133,
      -1,   135,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,    -1,
      -1,   118,   176,   177,   178,    -1,    -1,    -1,   125,   126,
     251,    -1,   129,   130,    -1,   132,   133,    -1,   135,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   176,
     177,   178,   112,   113,   114,   115,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   251,    -1,   129,
     130,    -1,   132,   133,    -1,   135,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,    -1,    -1,   118,   176,   177,   178,    -1,
      -1,    -1,   125,   126,   251,    -1,   129,   130,    -1,   132,
     133,    -1,   135,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   176,   177,   178,   112,   113,   114,   115,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   251,    -1,   129,   130,    -1,   132,   133,    -1,   135,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   152,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,    -1,    -1,   118,
     176,   177,   178,    -1,    -1,    -1,   125,   126,   251,    -1,
     129,   130,    -1,   132,   133,    -1,   135,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   176,   177,   178,
     112,   113,   114,   115,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   251,    -1,   129,   130,    -1,
     132,   133,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,    -1,    -1,   118,   176,   177,   178,    -1,    -1,    -1,
     125,   126,   251,    -1,   129,   130,    -1,   132,   133,    -1,
     135,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,    13,
      14,    -1,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,   176,   177,   178,   245,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,   255,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    80,    81,    82,    83,
      -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,   251,   111,   112,   113,
     114,   115,   116,    -1,   118,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,    -1,    -1,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    -1,     4,    -1,
     164,   165,   166,    -1,    -1,    -1,   170,    13,    14,    -1,
      -1,   175,   176,   177,   178,    -1,    -1,   181,    -1,   183,
      -1,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    -1,    -1,    -1,    44,    45,
      -1,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,    -1,   218,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,   112,   113,   114,   115,
     116,    -1,   118,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,   164,   165,
     166,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,   175,
     176,   177,   178,     4,     5,   181,    -1,   183,    -1,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     206,   207,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
     216,    -1,   218,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,
      -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
      -1,   132,   112,   113,   114,   115,    13,    14,   118,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,   129,
     130,    -1,   132,   133,    -1,   135,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,   156,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   177,   178,   200,
     201,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,   215,    -1,   217,   218,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
      -1,    -1,   129,   130,    -1,   132,   133,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,   176,
     177,   178,    -1,    -1,    -1,    -1,    -1,    -1,   255,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   255,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   255,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     255,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   255,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   255,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   255,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   255,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   255,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     255,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   255,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   255,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   255,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   255,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   255,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   255,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     255,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   255,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   251,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,   251,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     251,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,   251,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,   251,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   251,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,   251,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     251,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,   251,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,   251,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   251,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
      -1,   251,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,
     251,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,   251,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,    -1,   251,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,    -1,    -1,   251,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,    -1,   251,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,   251,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,    -1,   251,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,   250,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   250,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,   250,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,   247,    -1,   249,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,   249,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   249,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,   249,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,   249,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   249,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,   249,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,   249,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
     249,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,   249,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,
     245,    -1,    -1,    -1,   249,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,   249,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
      -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   249,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,   249,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,   249,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,   249,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245,    -1,   247,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,   245,    -1,   247,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,    -1,    -1,    -1,    -1,   245
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   257,   258,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    75,    80,    81,    82,
      83,    85,    86,    88,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     111,   112,   113,   114,   115,   116,   118,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   164,   165,   166,   170,
     175,   176,   177,   178,   181,   183,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     205,   206,   207,   216,   218,   259,   261,   262,   282,   300,
     302,   306,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   324,   326,   327,   333,   334,   335,   336,   342,   367,
     368,   250,   254,    14,   102,   246,   246,     6,   250,     6,
       6,     6,     6,   246,     6,     6,     6,     6,   248,   248,
       4,   344,   368,   246,   248,   280,    96,    99,   102,   104,
     280,   246,   246,   246,     4,   246,   246,   246,     4,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     250,   117,   102,     6,   250,    96,    99,   102,   115,   305,
     104,   246,     3,    10,    11,    12,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    55,    56,    57,    58,    63,
      64,    72,    73,    77,    78,    79,    87,    90,    96,    99,
     102,   104,   115,   125,   130,   132,   135,   199,   203,   204,
     208,   209,   210,   212,   213,   214,   234,   235,   241,   246,
     250,   253,   302,   303,   306,   317,   324,   326,   337,   338,
     342,   344,   351,   353,   368,   246,   250,   250,   102,   102,
     125,    99,   102,   104,    96,    99,   102,   104,   302,    99,
     102,   104,   115,   303,    99,   102,   246,    99,   156,   181,
     197,   198,   250,   234,   235,   246,   250,   348,   349,   348,
     250,   250,   348,     4,    96,   100,   106,   107,   109,   110,
     129,   250,   246,   102,   104,   102,    99,     4,    88,   192,
     250,   368,     4,     6,    96,    99,   102,    99,   102,   115,
     304,     4,     4,     4,     5,   246,   250,   351,   352,     4,
     246,   246,   246,     4,   250,   355,   368,     4,   246,   246,
     246,     6,     6,   248,     5,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    59,    60,    61,    62,    67,    68,
      69,    74,    76,    89,    92,   200,   201,   202,   211,   215,
     217,   359,   368,   246,     4,   359,     5,   250,     5,   250,
      32,   235,   337,   368,   248,   250,   246,   250,     6,   246,
     250,     6,   254,     7,   132,   192,   219,   220,   221,   222,
     242,   243,   246,   248,   252,   278,   279,   280,   302,   337,
     358,   359,   368,     4,   306,   307,   308,   250,     6,   337,
     358,   359,   368,   358,   337,   358,   365,   366,   368,   284,
     288,   246,   347,     9,   359,   246,   246,   246,   246,   368,
     337,   337,   337,   246,   337,   337,   337,   246,   337,   337,
     337,   337,   337,   337,   337,   358,   337,   337,   337,   337,
     352,   246,   235,   337,   353,   354,   250,   352,   351,   358,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   246,   248,   280,   280,   280,   280,   280,
     280,   246,   280,   280,   246,   302,   303,   303,   280,   280,
       5,   250,   250,   125,   302,   302,   246,   280,   280,   246,
     246,   246,   337,   250,   337,   353,   337,   337,   251,   354,
     344,   368,   184,     5,   250,     8,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   245,     9,   246,   248,   252,   279,
     280,   337,   354,   354,   246,   246,   246,   351,   352,   352,
     352,   301,   250,   246,   351,   250,   250,   337,     4,   351,
     250,   355,   250,   250,   348,   348,   348,   337,   337,   234,
     235,   250,   250,   348,   234,   235,   246,   308,   348,   250,
     246,   250,   246,   246,   246,   246,   246,   246,   246,   354,
     337,   352,   352,   352,   246,     4,   248,   250,     6,   248,
     308,     6,     6,   250,   250,   250,   250,   352,   248,   248,
     248,   337,     8,     6,     6,   337,   337,   337,   252,   337,
     250,   184,   337,   337,   337,   337,   280,   280,   280,   246,
     246,   246,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   246,   246,   280,   246,   248,     6,     6,   250,
       6,     8,   308,     6,     8,   308,   280,   337,   236,   250,
       9,   246,   248,   252,   358,   354,   337,   308,   351,   351,
     250,   359,   302,     7,   337,   337,     4,   181,   182,   351,
       6,   247,   249,   250,   281,   250,     6,   250,     6,     9,
     246,   248,   252,   368,   251,   125,   130,   132,   133,   135,
     300,   302,   337,     6,   247,   255,     9,   246,   248,   252,
     247,   255,   255,   247,   255,     9,   246,   252,   249,   255,
     283,   249,   283,    91,   346,   343,   368,   255,   337,   337,
     337,   337,   255,   247,   247,   247,   337,   247,   247,   247,
     337,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   251,     7,   337,   236,   251,   255,   337,     6,
       6,   247,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   353,
     337,   337,   337,   337,   337,   337,   337,   353,   353,   368,
     250,   337,   337,   358,   337,   358,   351,   358,   358,   365,
     250,   250,   250,   337,   281,   368,     8,   337,   337,   352,
     351,   358,   358,   353,   344,   359,   344,   354,   247,   251,
     252,   280,    64,     8,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   250,   337,
     353,   337,   337,   337,   337,   337,   368,   337,   337,     4,
     345,   250,   281,   247,   251,   251,   337,   337,   337,     7,
       7,   330,   330,   246,   337,   337,     6,   354,   354,   250,
     247,     6,   308,   250,   308,   308,   255,   255,   255,   348,
     348,   307,   307,   255,   337,   251,   321,   255,   308,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   251,   247,
       7,   331,     6,     7,   337,     6,   337,   308,   337,   251,
     354,   354,   354,   337,     6,   337,   337,   337,   247,   251,
     247,   247,   247,   181,   255,   308,   250,     8,   247,   247,
     249,   365,   358,   365,   358,   358,   358,   358,   358,   358,
     337,   358,   358,   358,   358,   253,   361,   368,   359,   358,
     358,   358,   344,   368,   354,   251,   251,   251,   251,   337,
     337,   308,   368,   345,   249,   251,   247,   139,   156,   325,
     247,   251,   255,   337,     6,   250,   351,   247,   249,     7,
     278,   279,   252,     7,     6,   354,     7,   219,   278,   337,
     263,   368,   337,   337,   345,   248,   246,   125,   302,   303,
     302,   250,   251,     6,   230,   233,   260,   354,   368,   337,
     337,     4,   345,     6,   354,   337,     6,   358,   366,   368,
     247,   345,     6,   368,     6,   358,   337,   247,   248,   337,
     255,   255,   255,   255,   359,     7,     7,     7,   247,     7,
       7,     7,   247,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   337,   247,   250,   337,   353,   251,     6,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   255,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   255,   255,   255,   247,   249,   249,   354,   255,   255,
     281,   255,   281,   255,   255,   255,   247,   354,   337,   337,
     339,   281,   251,   251,   251,   255,   255,   281,   281,   247,
     252,   247,   252,   255,   280,   340,   251,     7,   345,   281,
     250,   251,     8,     8,   354,   252,   247,   249,   279,   246,
     248,   280,   354,     7,   250,   250,   247,   247,   247,   337,
     351,     4,   329,     6,   297,   337,   359,   251,   247,   251,
     251,   354,   252,   251,   308,   251,   251,   348,   337,   337,
     251,   251,   337,   348,   136,   136,   153,   161,   162,   163,
     167,   168,   322,   323,   348,   251,   318,   247,   251,   247,
     247,   247,   247,   247,   247,   247,   250,     7,   337,     6,
     337,   247,   249,   251,   249,   251,   251,   251,   251,   249,
     249,   255,     7,     7,     7,   252,   337,   251,   337,   337,
       7,   252,   281,   255,   281,   281,   247,   247,   255,   281,
     281,   255,   255,   281,   281,   281,   281,   337,   281,     9,
     360,   255,   247,   255,   281,   252,   255,   341,   249,   251,
     251,   252,   246,   248,   254,   184,     7,   156,     6,   337,
     251,   250,     6,   351,   251,   337,     6,     7,   278,   279,
     252,   278,   279,   359,   337,     6,     4,   250,   356,   368,
     251,    46,    46,   351,   251,     4,   171,   172,   173,   174,
     251,   266,   270,   273,   275,   276,   252,   247,   249,   246,
     337,   337,   246,   250,   246,   250,     8,   354,   358,   247,
     252,   247,   249,   246,   247,   255,   252,   246,     7,   280,
       4,   291,   292,   293,   281,   337,   337,   337,   337,   281,
     348,   351,   351,     7,   351,   351,   351,     7,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,     6,     7,
     354,   337,   337,   337,   337,   251,   337,   337,   337,   351,
     358,   358,   251,   251,   251,   255,   290,   337,   337,   345,
     345,   337,   337,   247,   351,   280,   337,   337,   337,   251,
     345,   279,   252,   279,   337,   337,   281,   251,   351,   354,
     354,     7,     7,     7,   136,   328,     6,   247,   255,     7,
       7,     7,   251,     4,   251,   255,   255,   255,   251,   251,
     114,     4,     6,   337,   250,     6,   246,     6,   169,     6,
     169,   251,   323,   255,   322,     7,     6,     7,     7,     7,
       7,     7,     7,     7,   307,   351,     6,   250,     6,     6,
       6,   102,     7,     6,     6,   337,   351,   351,   351,     4,
     255,     8,     8,   247,     4,   105,   106,     4,   354,   358,
     337,   358,   253,   255,   294,   358,   358,   345,   358,   247,
     255,   345,   250,   302,   250,     6,   337,     6,   250,   351,
     251,   251,   337,     6,     4,   181,   182,   337,     6,     6,
       6,     7,   355,   357,     6,   248,   281,   280,   280,     6,
     267,   246,   246,   250,   277,     6,   345,   252,   358,   337,
     249,   247,   337,     8,   354,   337,   354,   251,   251,     6,
       6,   260,   345,   252,   337,     6,   337,   345,   247,   250,
     337,   359,   281,    46,   250,   351,   359,   362,   249,   255,
       6,   247,   247,   247,   247,     6,     6,   129,   299,   299,
     351,     6,     6,     6,   351,   136,   184,   298,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   251,   281,
     281,   281,   281,   281,   255,   255,   255,   247,   281,   281,
     292,   281,   247,   281,   247,   280,   340,   281,     6,   281,
     255,   246,   248,   280,     4,   247,   249,   281,     6,   251,
     251,   351,   351,   351,     4,     6,   278,   337,   351,   250,
     250,     7,     6,     7,   337,   337,   337,   250,   250,   250,
     248,     6,   337,   351,   337,     6,     6,   337,   348,   251,
       5,   351,   250,   250,   250,   250,   250,   250,   250,   351,
     251,     6,   354,   250,   337,   249,     6,     6,   180,   337,
     337,   337,     6,     6,     6,     6,     7,   281,   255,   255,
     281,   255,   337,     4,   196,   295,   296,   281,   247,   281,
     341,   359,   246,   248,   337,   250,   308,     6,   308,   255,
       6,     6,     7,   278,   279,   252,     7,     6,   355,   251,
     255,   337,   278,   250,   281,   363,   364,   365,   363,   246,
     337,   337,   350,   351,   250,   246,     4,     6,   247,     6,
     247,   251,   251,   247,   251,     6,     6,   358,   246,     4,
     247,   255,   246,   351,   359,     7,   280,   289,   337,   353,
     293,     6,     6,     6,     6,   348,     6,     6,     6,     6,
      96,   115,   100,     6,     5,   250,   337,   337,   337,   337,
     247,   340,   337,   337,   337,   281,   279,   250,   250,     6,
     298,     6,   337,   351,     4,     6,   354,   354,   337,   337,
     359,   251,   247,   251,   255,   307,   307,   337,   337,   251,
     255,   247,   251,   255,     6,     6,   350,   348,   348,   348,
     348,   348,   235,   348,     6,   251,   337,     6,     6,   351,
     251,   255,     8,   251,   247,   250,   337,   359,   358,   337,
     358,   337,   359,   362,   364,   359,   255,   247,   255,   251,
     337,   325,   325,   351,   359,   337,     6,     4,   356,     6,
     355,   249,   351,   365,     6,   281,   281,   264,   337,   255,
     255,   251,   255,   265,   337,   337,     6,     6,     6,     6,
     337,   337,   247,   285,   287,   250,   364,   251,   255,     7,
       7,   250,   250,   250,     5,   350,   281,   281,   255,   281,
     247,   255,   247,   249,   354,   354,     6,     6,   250,   251,
     251,   250,     6,     6,   250,   337,   251,   251,   251,   249,
       6,   351,     7,   250,   337,   251,   255,   255,   255,   255,
     255,   255,     6,   251,   179,   337,   337,   354,     6,     6,
     247,   281,   281,   296,   359,   251,   251,   251,   251,     6,
       6,     7,     6,   252,     6,   251,     6,     6,   247,   255,
     337,   337,   250,   351,   251,   255,   247,   247,   255,   290,
     294,   351,   281,   337,   359,   368,   354,   354,   337,     6,
     251,   337,   340,   337,   251,   251,   350,   140,   141,   146,
     332,   140,   141,   332,   354,   307,   251,   255,     6,   251,
     351,   308,   251,     6,   354,   348,   348,   348,   348,   348,
     337,   251,   251,   251,   247,     6,   250,     6,   355,   182,
     268,   337,   255,   255,   350,     6,   337,   337,   251,   251,
     286,     7,   246,   251,   251,   251,   250,   255,   247,   255,
     250,   251,   250,   348,   351,     6,   250,   348,     6,   251,
     251,   337,     6,   136,   251,   319,   250,   251,   255,   255,
     255,   255,   255,     6,     6,     6,   308,     6,   250,   337,
     337,   251,   255,   290,   359,   247,   337,   337,   337,   354,
       6,   348,     6,   348,     6,     6,   251,   337,   322,   308,
       6,   354,   354,   354,   354,   348,   354,   325,   265,   247,
     255,     6,   250,   337,   251,   255,   255,   255,   251,   255,
     255,     6,   251,   251,   320,   251,   251,   251,   251,   255,
     251,   251,   251,   271,   337,   350,   251,   337,   337,   337,
     348,   348,   322,     6,     6,     6,     6,   354,     6,     6,
       6,   250,   247,   251,     6,   251,   281,   255,   255,   255,
     251,   251,   269,   358,   274,   250,     6,   337,   337,   337,
       6,   251,   255,   250,   350,   251,   251,   251,     6,   358,
     272,   358,   251,     6,     6,   251,   255,     6,     6,   358
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   256,   257,   257,   258,   258,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   260,   260,   261,   261,
     261,   261,   261,   261,   262,   262,   262,   262,   263,   263,
     263,   263,   263,   263,   264,   264,   265,   265,   267,   268,
     266,   269,   269,   271,   270,   272,   272,   274,   273,   275,
     275,   277,   276,   278,   278,   278,   278,   278,   279,   279,
     280,   280,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   283,   283,   284,   284,   284,   285,   284,   286,   284,
     284,   287,   284,   288,   288,   289,   289,   289,   290,   290,
     291,   291,   292,   292,   293,   293,   293,   293,   293,   294,
     294,   295,   295,   296,   296,   296,   296,   296,   297,   297,
     297,   298,   298,   298,   298,   299,   299,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   301,
     300,   302,   302,   302,   302,   302,   303,   303,   303,   303,
     304,   304,   304,   305,   305,   305,   305,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   307,   307,   308,   308,
     308,   308,   308,   308,   308,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   310,   310,   310,
     310,   310,   310,   310,   310,   311,   311,   312,   313,   313,
     313,   313,   313,   313,   313,   313,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   315,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   317,   317,   317,   318,   317,   319,   317,   320,
     317,   321,   317,   317,   317,   317,   317,   317,   322,   322,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   324,   324,   324,   324,   324,   325,   325,   325,   325,
     325,   326,   326,   327,   328,   328,   329,   329,   330,   330,
     331,   331,   332,   332,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     334,   334,   334,   335,   335,   335,   336,   336,   336,   336,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   339,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   340,   340,   341,   341,   343,
     342,   344,   344,   345,   346,   346,   347,   347,   348,   348,
     348,   348,   348,   349,   349,   349,   349,   350,   350,   351,
     351,   351,   351,   351,   351,   352,   352,   352,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     354,   354,   354,   354,   355,   355,   355,   355,   356,   356,
     357,   357,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   360,   359,   359,   361,   361,   362,   363,   363,
     364,   365,   365,   365,   365,   366,   366,   366,   367,   367,
     367,   368,   368,   368
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
       2,     2,     2,     2,     2,     2,    16,    11,     6,     8,
       8,    10,     1,     2,     2,     1,     3,     3,     4,     4,
       1,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     9,     2,     3,    10,    13,     1,     2,
       5,     7,     2,     2,     3,     2,     3,     2,     3,     9,
       6,     1,     1,     1,     1,     1,     0,     2,     3,     3,
       4,     9,     4,    14,     0,     3,     0,     1,     0,     2,
       0,     2,     0,     2,     6,     7,     6,     5,     3,     8,
       8,     8,     8,     8,     5,     4,     6,    11,    11,    18,
      18,    12,    12,    12,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       1,     4,     6,     1,     4,     4,     4,     6,     5,     7,
       8,    10,     4,     4,     6,     4,     3,     2,     5,     5,
       3,     5,     6,     8,     6,     8,     6,     4,     7,     6,
       6,     6,     4,     6,     4,     0,     2,     0,     2,     0,
       7,     1,     3,     1,     1,     2,     0,     3,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     3,     1,     2,     3,
       3,     5,     4,     4,     2,     4,     2,     3,     3,    16,
       5,     5,     5,     1,     1,     1,     3,     5,     7,     4,
       4,     4,     6,     6,     8,     8,     4,    14,     4,     4,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     4,     4,     3,     5,     6,     8,
       6,     4,     5,     1,     4,     1,     1,     1,     1,     4,
       6,     4,     6,     5,     7,     4,     4,     4,     8,     4,
       4,     4,     4,     8,     8,     6,     4,     6,     4,     1,
       4,     4,     0,     6,     4,     2,     4,     4,     1,     1,
       3,     1,     1,     3,     3,     3,     5,     7,     5,     5,
       8,     1,     1,     4
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
#line 269 "Gmsh.y" /* yacc.c:1652  */
    { yyerrok; return 1; }
#line 5974 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 280 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5980 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 281 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5986 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 282 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5992 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 284 "Gmsh.y" /* yacc.c:1652  */
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
#line 6015 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 302 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6021 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 303 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6027 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 304 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6033 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 305 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6039 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 306 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6045 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 307 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6051 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 308 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6057 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 309 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6063 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 310 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6069 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 311 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6075 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 312 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6081 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 313 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6087 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 314 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6093 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 315 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6099 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 316 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6105 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 317 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6111 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 322 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"w";
    }
#line 6119 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 326 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"a";
    }
#line 6127 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 333 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6136 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 338 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6145 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 343 "Gmsh.y" /* yacc.c:1652  */
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
#line 6163 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 357 "Gmsh.y" /* yacc.c:1652  */
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
#line 6180 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 370 "Gmsh.y" /* yacc.c:1652  */
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
#line 6197 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 383 "Gmsh.y" /* yacc.c:1652  */
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
#line 6224 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 411 "Gmsh.y" /* yacc.c:1652  */
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
#line 6242 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 425 "Gmsh.y" /* yacc.c:1652  */
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
#line 6259 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 438 "Gmsh.y" /* yacc.c:1652  */
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
#line 6276 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 451 "Gmsh.y" /* yacc.c:1652  */
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
#line 6295 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 469 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 6305 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 483 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6311 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 485 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6317 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 490 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6323 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 492 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6329 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 497 "Gmsh.y" /* yacc.c:1652  */
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
#line 6437 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 601 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(std::size_t j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 6451 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 611 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 6461 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 620 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6472 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 627 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6483 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 637 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 6496 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 646 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 6506 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 655 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6517 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 662 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6528 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 672 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 6540 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 680 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 6550 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 690 "Gmsh.y" /* yacc.c:1652  */
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
#line 6570 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 709 "Gmsh.y" /* yacc.c:1652  */
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
#line 6590 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 728 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 6600 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 734 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 6607 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 741 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 6613 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 742 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6619 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 743 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 6625 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 744 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 6631 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 745 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 4; }
#line 6637 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 749 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6643 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 750 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = -1; }
#line 6649 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 756 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"("; }
#line 6655 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 756 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"["; }
#line 6661 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 757 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)")"; }
#line 6667 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 757 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"]"; }
#line 6673 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 77:
#line 767 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 6682 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 78:
#line 772 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 6692 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 79:
#line 778 "Gmsh.y" /* yacc.c:1652  */
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
#line 6758 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 80:
#line 840 "Gmsh.y" /* yacc.c:1652  */
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
#line 6777 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 81:
#line 855 "Gmsh.y" /* yacc.c:1652  */
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
#line 6810 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 82:
#line 884 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 6821 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 83:
#line 894 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6830 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 84:
#line 899 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6839 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 85:
#line 907 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6848 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 86:
#line 912 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6857 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 87:
#line 920 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 6867 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 88:
#line 929 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 6876 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 89:
#line 934 "Gmsh.y" /* yacc.c:1652  */
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
#line 6892 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 90:
#line 946 "Gmsh.y" /* yacc.c:1652  */
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
#line 6910 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 91:
#line 963 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6920 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 92:
#line 969 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6930 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 93:
#line 978 "Gmsh.y" /* yacc.c:1652  */
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
#line 6952 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 94:
#line 996 "Gmsh.y" /* yacc.c:1652  */
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
#line 6974 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 95:
#line 1014 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 6987 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 96:
#line 1023 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 7000 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 97:
#line 1035 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 7009 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 98:
#line 1040 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 7018 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 99:
#line 1048 "Gmsh.y" /* yacc.c:1652  */
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
#line 7042 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 100:
#line 1068 "Gmsh.y" /* yacc.c:1652  */
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
#line 7066 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 101:
#line 1091 "Gmsh.y" /* yacc.c:1652  */
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
#line 7090 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 102:
#line 1111 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 7102 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 103:
#line 1119 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Box");
#endif
    }
#line 7113 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 104:
#line 1126 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Cylinder");
#endif
    }
#line 7124 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 105:
#line 1133 "Gmsh.y" /* yacc.c:1652  */
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
#line 7150 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 106:
#line 1155 "Gmsh.y" /* yacc.c:1652  */
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
#line 7177 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 107:
#line 1178 "Gmsh.y" /* yacc.c:1652  */
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
#line 7219 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 108:
#line 1216 "Gmsh.y" /* yacc.c:1652  */
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
#line 7241 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 109:
#line 1237 "Gmsh.y" /* yacc.c:1652  */
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
#line 7257 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 110:
#line 1249 "Gmsh.y" /* yacc.c:1652  */
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
#line 7273 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 114:
#line 1267 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 7286 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 115:
#line 1276 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 7299 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 116:
#line 1285 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7305 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 117:
#line 1287 "Gmsh.y" /* yacc.c:1652  */
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
#line 7327 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 118:
#line 1305 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7333 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 119:
#line 1307 "Gmsh.y" /* yacc.c:1652  */
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
#line 7353 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 120:
#line 1323 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 7366 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 121:
#line 1332 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7372 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 122:
#line 1334 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 7386 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 124:
#line 1348 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 7396 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 125:
#line 1356 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7406 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 126:
#line 1362 "Gmsh.y" /* yacc.c:1652  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7415 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 127:
#line 1367 "Gmsh.y" /* yacc.c:1652  */
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
#line 7444 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 134:
#line 1410 "Gmsh.y" /* yacc.c:1652  */
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
#line 7460 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 135:
#line 1422 "Gmsh.y" /* yacc.c:1652  */
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
#line 7477 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 136:
#line 1435 "Gmsh.y" /* yacc.c:1652  */
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
#line 7495 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 137:
#line 1450 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7507 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 138:
#line 1459 "Gmsh.y" /* yacc.c:1652  */
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
#line 7522 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 143:
#line 1484 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 7533 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 144:
#line 1492 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7545 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 145:
#line 1501 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 7556 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 146:
#line 1509 "Gmsh.y" /* yacc.c:1652  */
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
#line 7573 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 147:
#line 1523 "Gmsh.y" /* yacc.c:1652  */
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
#line 7590 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 148:
#line 1541 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 7598 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 149:
#line 1545 "Gmsh.y" /* yacc.c:1652  */
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[0].c)), dim_entity, t + 1);
      Free((yyvsp[0].c));
    }
#line 7609 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 150:
#line 1552 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), dim_entity, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 7618 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 151:
#line 1560 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 7626 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 152:
#line 1564 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[-1].d);
      List_Add((yyval.l), &p);
    }
#line 7636 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 153:
#line 1570 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7644 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 154:
#line 1574 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[-1].l), i));
      List_Delete((yyvsp[-1].l));
    }
#line 7657 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 155:
#line 1585 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 7665 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 156:
#line 1589 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 7673 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 157:
#line 1596 "Gmsh.y" /* yacc.c:1652  */
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
#line 7700 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 158:
#line 1619 "Gmsh.y" /* yacc.c:1652  */
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
#line 7720 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 159:
#line 1635 "Gmsh.y" /* yacc.c:1652  */
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
#line 7740 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 160:
#line 1651 "Gmsh.y" /* yacc.c:1652  */
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
#line 7781 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 161:
#line 1688 "Gmsh.y" /* yacc.c:1652  */
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
        else if(tags.size() == 4){
          r = GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[3]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() == 7) ? param[5] : 0.;
          double a2 = (param.size() == 7) ? param[6] :
            (param.size() == 6) ? param[5] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 3 or 4 points, or 5 to 7 parameters");
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
#line 7825 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 162:
#line 1728 "Gmsh.y" /* yacc.c:1652  */
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
#line 7845 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 163:
#line 1744 "Gmsh.y" /* yacc.c:1652  */
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
#line 7865 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 164:
#line 1761 "Gmsh.y" /* yacc.c:1652  */
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
#line 7900 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 165:
#line 1792 "Gmsh.y" /* yacc.c:1652  */
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
#line 7920 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 166:
#line 1808 "Gmsh.y" /* yacc.c:1652  */
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
#line 7941 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 167:
#line 1825 "Gmsh.y" /* yacc.c:1652  */
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
#line 7961 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 168:
#line 1841 "Gmsh.y" /* yacc.c:1652  */
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
#line 8015 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 169:
#line 1891 "Gmsh.y" /* yacc.c:1652  */
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
#line 8037 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 170:
#line 1909 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8047 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 171:
#line 1915 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8057 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 172:
#line 1921 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 8068 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 173:
#line 1928 "Gmsh.y" /* yacc.c:1652  */
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
#line 8103 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 174:
#line 1959 "Gmsh.y" /* yacc.c:1652  */
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
#line 8122 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 175:
#line 1974 "Gmsh.y" /* yacc.c:1652  */
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
#line 8148 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 176:
#line 1996 "Gmsh.y" /* yacc.c:1652  */
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
#line 8175 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 177:
#line 2019 "Gmsh.y" /* yacc.c:1652  */
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
#line 8202 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 178:
#line 2042 "Gmsh.y" /* yacc.c:1652  */
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
#line 8229 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 179:
#line 2065 "Gmsh.y" /* yacc.c:1652  */
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
#line 8257 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 180:
#line 2089 "Gmsh.y" /* yacc.c:1652  */
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
#line 8285 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 181:
#line 2113 "Gmsh.y" /* yacc.c:1652  */
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
#line 8313 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 182:
#line 2137 "Gmsh.y" /* yacc.c:1652  */
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
#line 8343 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 183:
#line 2163 "Gmsh.y" /* yacc.c:1652  */
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
#line 8364 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 184:
#line 2180 "Gmsh.y" /* yacc.c:1652  */
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
#line 8384 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 185:
#line 2196 "Gmsh.y" /* yacc.c:1652  */
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
#line 8406 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 186:
#line 2214 "Gmsh.y" /* yacc.c:1652  */
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
#line 8428 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 187:
#line 2232 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-6].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8439 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 188:
#line 2240 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-10].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8450 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 189:
#line 2247 "Gmsh.y" /* yacc.c:1652  */
    {
      dim_entity = (yyvsp[0].i);
    }
#line 8458 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 190:
#line 2251 "Gmsh.y" /* yacc.c:1652  */
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
#line 8485 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 191:
#line 2277 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8491 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 192:
#line 2279 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8497 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 193:
#line 2281 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8503 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 194:
#line 2283 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8509 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 195:
#line 2285 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
#line 8518 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 196:
#line 2293 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8524 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 197:
#line 2295 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8530 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 198:
#line 2297 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8536 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 199:
#line 2299 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
#line 8545 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 200:
#line 2307 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8551 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 201:
#line 2309 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8557 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 202:
#line 2311 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
#line 8566 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 203:
#line 2319 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8572 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 204:
#line 2321 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8578 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 205:
#line 2323 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8584 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 206:
#line 2325 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
#line 8593 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 207:
#line 2335 "Gmsh.y" /* yacc.c:1652  */
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
#line 8613 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 208:
#line 2351 "Gmsh.y" /* yacc.c:1652  */
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
#line 8633 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 209:
#line 2367 "Gmsh.y" /* yacc.c:1652  */
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
#line 8653 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 210:
#line 2383 "Gmsh.y" /* yacc.c:1652  */
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
#line 8673 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 211:
#line 2399 "Gmsh.y" /* yacc.c:1652  */
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
#line 8693 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 212:
#line 2415 "Gmsh.y" /* yacc.c:1652  */
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
#line 8714 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 213:
#line 2432 "Gmsh.y" /* yacc.c:1652  */
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
#line 8755 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 214:
#line 2469 "Gmsh.y" /* yacc.c:1652  */
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
#line 8780 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 215:
#line 2491 "Gmsh.y" /* yacc.c:1652  */
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
#line 8805 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 216:
#line 2514 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8811 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 217:
#line 2515 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8817 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 218:
#line 2520 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 8825 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 219:
#line 2524 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 8833 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 220:
#line 2528 "Gmsh.y" /* yacc.c:1652  */
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
#line 8854 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 221:
#line 2545 "Gmsh.y" /* yacc.c:1652  */
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
#line 8878 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 222:
#line 2565 "Gmsh.y" /* yacc.c:1652  */
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
#line 8902 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 223:
#line 2585 "Gmsh.y" /* yacc.c:1652  */
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
#line 8925 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 224:
#line 2604 "Gmsh.y" /* yacc.c:1652  */
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
#line 8951 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 225:
#line 2631 "Gmsh.y" /* yacc.c:1652  */
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
#line 8974 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 226:
#line 2650 "Gmsh.y" /* yacc.c:1652  */
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
#line 8999 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 227:
#line 2672 "Gmsh.y" /* yacc.c:1652  */
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
#line 9017 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 228:
#line 2687 "Gmsh.y" /* yacc.c:1652  */
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
#line 9036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 229:
#line 2702 "Gmsh.y" /* yacc.c:1652  */
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
#line 9058 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 230:
#line 2721 "Gmsh.y" /* yacc.c:1652  */
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
#line 9112 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 231:
#line 2772 "Gmsh.y" /* yacc.c:1652  */
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
#line 9136 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 232:
#line 2793 "Gmsh.y" /* yacc.c:1652  */
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
#line 9161 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 233:
#line 2815 "Gmsh.y" /* yacc.c:1652  */
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
#line 9187 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 234:
#line 2837 "Gmsh.y" /* yacc.c:1652  */
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
#line 9296 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 235:
#line 2942 "Gmsh.y" /* yacc.c:1652  */
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
#line 9316 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 236:
#line 2958 "Gmsh.y" /* yacc.c:1652  */
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
#line 9350 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 237:
#line 2993 "Gmsh.y" /* yacc.c:1652  */
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
#line 9376 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 238:
#line 3015 "Gmsh.y" /* yacc.c:1652  */
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
#line 9402 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 239:
#line 3037 "Gmsh.y" /* yacc.c:1652  */
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
#line 9418 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 240:
#line 3049 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 9428 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 241:
#line 3055 "Gmsh.y" /* yacc.c:1652  */
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
#line 9447 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 242:
#line 3070 "Gmsh.y" /* yacc.c:1652  */
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
#line 9479 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 243:
#line 3098 "Gmsh.y" /* yacc.c:1652  */
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
#line 9495 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 244:
#line 3110 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yynamespaces.clear();
    }
#line 9503 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 245:
#line 3119 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), false);
      List_Delete((yyvsp[-1].l));
    }
#line 9514 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 246:
#line 3126 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), true);
      List_Delete((yyvsp[-1].l));
    }
#line 9525 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 247:
#line 3138 "Gmsh.y" /* yacc.c:1652  */
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
#line 9544 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 248:
#line 3158 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
    }
#line 9552 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 249:
#line 3162 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[-1].c));
    }
#line 9561 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 250:
#line 3167 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
    }
#line 9569 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 251:
#line 3171 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[-1].c));
    }
#line 9578 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 252:
#line 3176 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9589 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 253:
#line 3183 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9600 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 254:
#line 3190 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9611 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 255:
#line 3197 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9622 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 256:
#line 3209 "Gmsh.y" /* yacc.c:1652  */
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
#line 9699 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 257:
#line 3282 "Gmsh.y" /* yacc.c:1652  */
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
#line 9721 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 258:
#line 3300 "Gmsh.y" /* yacc.c:1652  */
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
#line 9750 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 259:
#line 3325 "Gmsh.y" /* yacc.c:1652  */
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
#line 9769 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 260:
#line 3340 "Gmsh.y" /* yacc.c:1652  */
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
#line 9806 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 261:
#line 3373 "Gmsh.y" /* yacc.c:1652  */
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
#line 9822 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 262:
#line 3385 "Gmsh.y" /* yacc.c:1652  */
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
#line 9850 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 263:
#line 3409 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Exit(0);
    }
#line 9858 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 264:
#line 3413 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 9867 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 265:
#line 3418 "Gmsh.y" /* yacc.c:1652  */
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
#line 9878 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 266:
#line 3425 "Gmsh.y" /* yacc.c:1652  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 9887 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 267:
#line 3430 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
#line 9901 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 268:
#line 3440 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 9910 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 269:
#line 3445 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 9920 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 270:
#line 3451 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 9932 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 271:
#line 3459 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 9940 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 272:
#line 3463 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    }
#line 9948 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 273:
#line 3467 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshVertices();
    }
#line 9956 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 274:
#line 3471 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshElements();
    }
#line 9964 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 275:
#line 3475 "Gmsh.y" /* yacc.c:1652  */
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 9977 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 276:
#line 3485 "Gmsh.y" /* yacc.c:1652  */
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
#line 10039 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 277:
#line 3548 "Gmsh.y" /* yacc.c:1652  */
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
#line 10055 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 278:
#line 3564 "Gmsh.y" /* yacc.c:1652  */
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
#line 10076 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 279:
#line 3581 "Gmsh.y" /* yacc.c:1652  */
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
#line 10097 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 280:
#line 3598 "Gmsh.y" /* yacc.c:1652  */
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
#line 10123 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 281:
#line 3620 "Gmsh.y" /* yacc.c:1652  */
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
#line 10149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 282:
#line 3642 "Gmsh.y" /* yacc.c:1652  */
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
#line 10188 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 283:
#line 3677 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10200 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 284:
#line 3685 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10212 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 285:
#line 3693 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 10222 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 286:
#line 3699 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10233 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 287:
#line 3706 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10244 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 288:
#line 3713 "Gmsh.y" /* yacc.c:1652  */
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
#line 10268 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 289:
#line 3733 "Gmsh.y" /* yacc.c:1652  */
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
#line 10298 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 290:
#line 3759 "Gmsh.y" /* yacc.c:1652  */
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
#line 10314 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 291:
#line 3771 "Gmsh.y" /* yacc.c:1652  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 10324 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 292:
#line 3782 "Gmsh.y" /* yacc.c:1652  */
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
#line 10346 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 293:
#line 3800 "Gmsh.y" /* yacc.c:1652  */
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
#line 10368 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 294:
#line 3818 "Gmsh.y" /* yacc.c:1652  */
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
#line 10390 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 295:
#line 3836 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10400 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 296:
#line 3842 "Gmsh.y" /* yacc.c:1652  */
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
#line 10422 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 297:
#line 3860 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10432 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 298:
#line 3866 "Gmsh.y" /* yacc.c:1652  */
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
#line 10456 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 299:
#line 3886 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10466 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 300:
#line 3892 "Gmsh.y" /* yacc.c:1652  */
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
#line 10488 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 301:
#line 3910 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10498 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 302:
#line 3916 "Gmsh.y" /* yacc.c:1652  */
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
#line 10519 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 303:
#line 3933 "Gmsh.y" /* yacc.c:1652  */
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
#line 10539 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 304:
#line 3949 "Gmsh.y" /* yacc.c:1652  */
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
#line 10560 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 305:
#line 3966 "Gmsh.y" /* yacc.c:1652  */
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
#line 10581 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 306:
#line 3984 "Gmsh.y" /* yacc.c:1652  */
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
#line 10607 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 307:
#line 4007 "Gmsh.y" /* yacc.c:1652  */
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
#line 10635 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 308:
#line 4034 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10642 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 309:
#line 4037 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10649 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 310:
#line 4043 "Gmsh.y" /* yacc.c:1652  */
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
#line 10665 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 311:
#line 4055 "Gmsh.y" /* yacc.c:1652  */
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
#line 10689 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 312:
#line 4075 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 10697 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 313:
#line 4079 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = true;
    }
#line 10705 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 314:
#line 4083 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 10713 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 315:
#line 4087 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 10721 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 316:
#line 4091 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 10729 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 317:
#line 4095 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 10737 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 318:
#line 4099 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 10745 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 319:
#line 4103 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      int num = (int)(yyvsp[-6].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[-1].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[-3].l));
    }
#line 10758 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 320:
#line 4112 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 10770 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 321:
#line 4124 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Union; }
#line 10776 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 322:
#line 4125 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Intersection; }
#line 10782 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 323:
#line 4126 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Difference; }
#line 10788 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 324:
#line 4127 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Section; }
#line 10794 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 325:
#line 4128 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Fragments; }
#line 10800 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 326:
#line 4132 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 10806 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 327:
#line 4133 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 10812 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 328:
#line 4134 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 10818 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 329:
#line 4135 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 1 : 0; }
#line 10824 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 330:
#line 4136 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 2 : 0; }
#line 10830 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 331:
#line 4141 "Gmsh.y" /* yacc.c:1652  */
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
#line 10857 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 332:
#line 4164 "Gmsh.y" /* yacc.c:1652  */
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
#line 10877 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 333:
#line 4184 "Gmsh.y" /* yacc.c:1652  */
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
#line 10899 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 334:
#line 4205 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 10907 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 335:
#line 4209 "Gmsh.y" /* yacc.c:1652  */
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
#line 10924 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 336:
#line 4224 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = -1; // left
    }
#line 10932 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 337:
#line 4228 "Gmsh.y" /* yacc.c:1652  */
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
#line 10950 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 338:
#line 4244 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 10958 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 339:
#line 4248 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 10966 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 340:
#line 4253 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = 45;
    }
#line 10974 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 341:
#line 4257 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 10982 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 342:
#line 4263 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 10990 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 343:
#line 4267 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10998 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 344:
#line 4274 "Gmsh.y" /* yacc.c:1652  */
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
#line 11024 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 345:
#line 4296 "Gmsh.y" /* yacc.c:1652  */
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
#line 11069 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 346:
#line 4337 "Gmsh.y" /* yacc.c:1652  */
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
#line 11117 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 347:
#line 4381 "Gmsh.y" /* yacc.c:1652  */
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
#line 11160 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 348:
#line 4420 "Gmsh.y" /* yacc.c:1652  */
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
#line 11189 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 349:
#line 4445 "Gmsh.y" /* yacc.c:1652  */
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
#line 11205 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 350:
#line 4457 "Gmsh.y" /* yacc.c:1652  */
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
#line 11221 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 351:
#line 4469 "Gmsh.y" /* yacc.c:1652  */
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
#line 11237 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 352:
#line 4481 "Gmsh.y" /* yacc.c:1652  */
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
#line 11253 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 353:
#line 4493 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[-1].d);
      }
      List_Delete((yyvsp[-4].l));
    }
#line 11266 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 354:
#line 4502 "Gmsh.y" /* yacc.c:1652  */
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
#line 11300 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 355:
#line 4532 "Gmsh.y" /* yacc.c:1652  */
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
#line 11330 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 356:
#line 4558 "Gmsh.y" /* yacc.c:1652  */
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
#line 11360 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 357:
#line 4585 "Gmsh.y" /* yacc.c:1652  */
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
#line 11395 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 358:
#line 4617 "Gmsh.y" /* yacc.c:1652  */
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
#line 11425 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 359:
#line 4644 "Gmsh.y" /* yacc.c:1652  */
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
#line 11454 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 360:
#line 4670 "Gmsh.y" /* yacc.c:1652  */
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
#line 11483 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 361:
#line 4696 "Gmsh.y" /* yacc.c:1652  */
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
#line 11512 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 362:
#line 4722 "Gmsh.y" /* yacc.c:1652  */
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
#line 11541 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 363:
#line 4748 "Gmsh.y" /* yacc.c:1652  */
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
#line 11566 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 364:
#line 4769 "Gmsh.y" /* yacc.c:1652  */
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
#line 11581 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 365:
#line 4780 "Gmsh.y" /* yacc.c:1652  */
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
#line 11633 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 366:
#line 4828 "Gmsh.y" /* yacc.c:1652  */
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
#line 11691 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 367:
#line 4882 "Gmsh.y" /* yacc.c:1652  */
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
#line 11710 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 368:
#line 4897 "Gmsh.y" /* yacc.c:1652  */
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
#line 11726 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 369:
#line 4909 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-2].i), tags);
      List_Delete((yyvsp[-1].l));
    }
#line 11736 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 370:
#line 4920 "Gmsh.y" /* yacc.c:1652  */
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
#line 11747 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 371:
#line 4927 "Gmsh.y" /* yacc.c:1652  */
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
#line 11766 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 372:
#line 4942 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[-2].l));
    }
#line 11779 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 373:
#line 4955 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Homology"; }
#line 11785 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 374:
#line 4956 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 11791 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 375:
#line 4957 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Betti"; }
#line 11797 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 376:
#line 4962 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 11807 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 377:
#line 4968 "Gmsh.y" /* yacc.c:1652  */
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
#line 11823 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 378:
#line 4980 "Gmsh.y" /* yacc.c:1652  */
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
#line 11845 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 379:
#line 4998 "Gmsh.y" /* yacc.c:1652  */
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
#line 11872 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 380:
#line 5025 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11878 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 381:
#line 5026 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 11884 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 382:
#line 5027 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 11890 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 383:
#line 5028 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11896 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 384:
#line 5029 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 11902 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 385:
#line 5030 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 11908 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 386:
#line 5031 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 11914 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 387:
#line 5032 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 11920 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 388:
#line 5034 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 11931 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 389:
#line 5040 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) | (int)(yyvsp[0].d); }
#line 11937 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 390:
#line 5041 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) & (int)(yyvsp[0].d); }
#line 11943 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 391:
#line 5042 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d); }
#line 11949 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 392:
#line 5043 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 11955 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 393:
#line 5044 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 11961 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 394:
#line 5045 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 11967 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 395:
#line 5046 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 11973 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 396:
#line 5047 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 11979 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 397:
#line 5048 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 11985 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 398:
#line 5049 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 11991 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 399:
#line 5050 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 11997 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 400:
#line 5051 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 12003 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 401:
#line 5052 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) >> (int)(yyvsp[0].d)); }
#line 12009 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 402:
#line 5053 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) << (int)(yyvsp[0].d)); }
#line 12015 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 403:
#line 5054 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 12021 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 404:
#line 5055 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 12027 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 405:
#line 5056 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 12033 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 406:
#line 5057 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 12039 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 407:
#line 5058 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 12045 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 408:
#line 5059 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 12051 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 409:
#line 5060 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 12057 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 410:
#line 5061 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 12063 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 411:
#line 5062 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 12069 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 412:
#line 5063 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 12075 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 413:
#line 5064 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 12081 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 414:
#line 5065 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 12087 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 415:
#line 5066 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 12093 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 416:
#line 5067 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 12099 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 417:
#line 5068 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 12105 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 418:
#line 5069 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 12111 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 419:
#line 5070 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = std::abs((yyvsp[-1].d)); }
#line 12117 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 420:
#line 5071 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 12123 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 421:
#line 5072 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 12129 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 422:
#line 5073 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 12135 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 423:
#line 5074 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12141 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 424:
#line 5075 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12147 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 425:
#line 5076 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 12153 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 426:
#line 5077 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 12159 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 427:
#line 5086 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12165 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 428:
#line 5087 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 3.141592653589793; }
#line 12171 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 429:
#line 5088 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 12177 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 430:
#line 5089 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 12183 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 431:
#line 5090 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 12189 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 432:
#line 5091 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 12195 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 433:
#line 5092 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 12201 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 434:
#line 5093 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 12207 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 435:
#line 5094 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Cpu(); }
#line 12213 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 436:
#line 5095 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 12219 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 437:
#line 5096 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = TotalRam(); }
#line 12225 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 438:
#line 5101 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 12231 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 439:
#line 5103 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 12241 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 440:
#line 5109 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12247 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 441:
#line 5111 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12256 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 442:
#line 5116 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12265 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 443:
#line 5121 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[0].c2).char1, (yyvsp[0].c2).char2);
    }
#line 12273 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 444:
#line 5126 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12281 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 445:
#line 5131 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12289 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 446:
#line 5135 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-1].c2).char1, (yyvsp[-1].c2).char2, 1, 0, 0., 1);
    }
#line 12297 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 447:
#line 5139 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-3].c2).char1, (yyvsp[-3].c2).char2, (yyvsp[-1].c), 0, 0., 1);
    }
#line 12305 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 448:
#line 5143 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-2].c2).char1, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].d), 2);
    }
#line 12313 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 449:
#line 5147 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].d), 2);
    }
#line 12321 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 450:
#line 5151 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-5].c2).char1, (yyvsp[-5].c2).char2, 2, (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12329 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 451:
#line 5155 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c2).char1, (yyvsp[-7].c2).char2, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12337 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 452:
#line 5159 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 12347 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 453:
#line 5165 "Gmsh.y" /* yacc.c:1652  */
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
#line 12366 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 454:
#line 5180 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c));
    }
#line 12374 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 455:
#line 5184 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[-1].c));
    }
#line 12384 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 456:
#line 5190 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
#line 12393 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 457:
#line 5195 "Gmsh.y" /* yacc.c:1652  */
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
#line 12416 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 458:
#line 5214 "Gmsh.y" /* yacc.c:1652  */
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
#line 12440 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 459:
#line 5234 "Gmsh.y" /* yacc.c:1652  */
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
#line 12464 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 460:
#line 5265 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12472 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 461:
#line 5269 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12480 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 462:
#line 5273 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12488 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 463:
#line 5277 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12496 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 464:
#line 5281 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12504 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 465:
#line 5285 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12512 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 466:
#line 5289 "Gmsh.y" /* yacc.c:1652  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12521 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 467:
#line 5294 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12535 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 468:
#line 5304 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 12549 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 469:
#line 5314 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12558 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 470:
#line 5319 "Gmsh.y" /* yacc.c:1652  */
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
#line 12573 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 471:
#line 5330 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12586 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 472:
#line 5339 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strlen((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12595 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 473:
#line 5344 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12604 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 474:
#line 5349 "Gmsh.y" /* yacc.c:1652  */
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
#line 12632 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 475:
#line 5376 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 0.; }
#line 12638 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 476:
#line 5378 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);}
#line 12644 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 477:
#line 5383 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = NULL; }
#line 12650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 478:
#line 5385 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c);}
#line 12656 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 479:
#line 5390 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c2).char1? (yyvsp[-1].c2).char1 : std::string("")),
        struct_name((yyvsp[-1].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
#line 12667 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 480:
#line 5397 "Gmsh.y" /* yacc.c:1652  */
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
#line 12684 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 481:
#line 5413 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[0].c); }
#line 12690 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 482:
#line 5415 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = (yyvsp[-2].c); (yyval.c2).char2 = (yyvsp[0].c); }
#line 12696 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 483:
#line 5420 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); flag_tSTRING_alloc = 1; }
#line 12702 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 484:
#line 5429 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 99; }
#line 12708 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 485:
#line 5431 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (int)(yyvsp[0].d); }
#line 12714 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 486:
#line 5436 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 12720 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 487:
#line 5438 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 12726 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 488:
#line 5443 "Gmsh.y" /* yacc.c:1652  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 12734 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 489:
#line 5447 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 12742 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 490:
#line 5451 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 12750 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 491:
#line 5455 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 12758 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 492:
#line 5459 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 12766 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 493:
#line 5466 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 12774 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 494:
#line 5470 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 12782 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 495:
#line 5474 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12790 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 496:
#line 5478 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12798 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 497:
#line 5485 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12807 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 498:
#line 5490 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12815 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 499:
#line 5497 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12824 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 500:
#line 5502 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12832 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 501:
#line 5506 "Gmsh.y" /* yacc.c:1652  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 12841 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 502:
#line 5511 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12849 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 503:
#line 5515 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12861 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 504:
#line 5523 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 12873 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 505:
#line 5534 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12881 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 506:
#line 5538 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 12889 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 507:
#line 5542 "Gmsh.y" /* yacc.c:1652  */
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
#line 12904 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 508:
#line 5556 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12916 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 509:
#line 5564 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 12928 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 510:
#line 5572 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 12939 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 511:
#line 5579 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 12953 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 512:
#line 5589 "Gmsh.y" /* yacc.c:1652  */
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
#line 12980 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 513:
#line 5612 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    }
#line 12989 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 514:
#line 5617 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[0].c));
    }
#line 12999 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 515:
#line 5623 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-3].i), (yyval.l));
    }
#line 13008 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 516:
#line 5628 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-1].i), (yyval.l));
      Free((yyvsp[0].c));
    }
#line 13018 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 517:
#line 5634 "Gmsh.y" /* yacc.c:1652  */
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
#line 13033 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 518:
#line 5645 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[-1].i), (yyvsp[0].l), (yyval.l));
      List_Delete((yyvsp[0].l));
    }
#line 13043 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 519:
#line 5652 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[-15].i), (yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d), (yyval.l));
    }
#line 13052 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 520:
#line 5657 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[-3].i), (yyvsp[-1].l), (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 13062 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 521:
#line 5663 "Gmsh.y" /* yacc.c:1652  */
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
#line 13078 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 522:
#line 5675 "Gmsh.y" /* yacc.c:1652  */
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
#line 13096 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 523:
#line 5689 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13110 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 524:
#line 5699 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13124 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 525:
#line 5709 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13138 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 526:
#line 5719 "Gmsh.y" /* yacc.c:1652  */
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
#line 13154 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 527:
#line 5731 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13162 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 528:
#line 5735 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13170 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 529:
#line 5740 "Gmsh.y" /* yacc.c:1652  */
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
#line 13186 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 530:
#line 5752 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13194 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 531:
#line 5756 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13202 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 532:
#line 5760 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 13210 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 533:
#line 5764 "Gmsh.y" /* yacc.c:1652  */
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
#line 13232 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 534:
#line 5782 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = (yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1);
	List_Add((yyval.l), &d);
      }
    }
#line 13244 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 535:
#line 5790 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = pow(10,(yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1));
	List_Add((yyval.l), &d);
      }
    }
#line 13256 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 536:
#line 5798 "Gmsh.y" /* yacc.c:1652  */
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
#line 13289 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 537:
#line 5827 "Gmsh.y" /* yacc.c:1652  */
    {
      double x0 = (yyvsp[-11].d), x1 = (yyvsp[-9].d), y0 = (yyvsp[-7].d), y1 = (yyvsp[-5].d), ys = (yyvsp[-3].d);
      int N = (int)(yyvsp[-1].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
#line 13303 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 538:
#line 5837 "Gmsh.y" /* yacc.c:1652  */
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
#line 13323 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 539:
#line 5853 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[-1].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13335 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 540:
#line 5864 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13344 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 541:
#line 5869 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13352 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 542:
#line 5873 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13360 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 543:
#line 5877 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13373 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 544:
#line 5889 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 13381 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 545:
#line 5893 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 13389 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 546:
#line 5905 "Gmsh.y" /* yacc.c:1652  */
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
#line 13410 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 547:
#line 5922 "Gmsh.y" /* yacc.c:1652  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 13421 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 548:
#line 5932 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13429 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 549:
#line 5936 "Gmsh.y" /* yacc.c:1652  */
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
#line 13445 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 550:
#line 5951 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13454 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 551:
#line 5956 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13462 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 552:
#line 5963 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13470 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 553:
#line 5967 "Gmsh.y" /* yacc.c:1652  */
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[0].c));
    }
#line 13479 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 554:
#line 5972 "Gmsh.y" /* yacc.c:1652  */
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
#line 13497 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 555:
#line 5986 "Gmsh.y" /* yacc.c:1652  */
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
#line 13515 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 556:
#line 6002 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13523 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 557:
#line 6006 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13531 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 558:
#line 6010 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13539 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 559:
#line 6014 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13547 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 560:
#line 6018 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 13559 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 561:
#line 6026 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13569 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 562:
#line 6032 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13579 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 563:
#line 6041 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13587 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 564:
#line 6045 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13595 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 565:
#line 6049 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 13607 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 566:
#line 6057 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 13617 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 567:
#line 6063 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 13627 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 568:
#line 6069 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
#line 13635 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 569:
#line 6073 "Gmsh.y" /* yacc.c:1652  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 13647 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 570:
#line 6081 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13659 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 571:
#line 6089 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 13670 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 572:
#line 6096 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13682 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 573:
#line 6105 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].c), 2);
    }
#line 13690 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 574:
#line 6109 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].c), 2);
    }
#line 13698 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 575:
#line 6113 "Gmsh.y" /* yacc.c:1652  */
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
#line 13717 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 576:
#line 6128 "Gmsh.y" /* yacc.c:1652  */
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
#line 13735 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 577:
#line 6142 "Gmsh.y" /* yacc.c:1652  */
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
#line 13753 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 578:
#line 6156 "Gmsh.y" /* yacc.c:1652  */
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
#line 13769 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 579:
#line 6168 "Gmsh.y" /* yacc.c:1652  */
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
#line 13789 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 580:
#line 6184 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13802 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 581:
#line 6193 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13815 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 582:
#line 6202 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13829 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 583:
#line 6212 "Gmsh.y" /* yacc.c:1652  */
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
#line 13844 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 584:
#line 6223 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-5].c);
      std::string out = in.substr((int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c));
    }
#line 13856 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 585:
#line 6231 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-3].c);
      std::string out = in.substr((int)(yyvsp[-1].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-3].c));
    }
#line 13868 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 586:
#line 6239 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13876 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 587:
#line 6243 "Gmsh.y" /* yacc.c:1652  */
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
#line 13899 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 588:
#line 6262 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13910 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 589:
#line 6269 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 13920 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 590:
#line 6275 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13931 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 591:
#line 6282 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13942 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 592:
#line 6289 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 13948 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 593:
#line 6291 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 13960 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 594:
#line 6299 "Gmsh.y" /* yacc.c:1652  */
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
#line 13985 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 595:
#line 6323 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[0].d); }
#line 13991 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 596:
#line 6325 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = (yyvsp[-3].c); Free((yyvsp[-3].c)); (yyval.d) = (yyvsp[0].d); }
#line 13997 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 597:
#line 6331 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 14003 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 598:
#line 6336 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14009 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 599:
#line 6338 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14015 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 600:
#line 6343 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 14021 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 601:
#line 6348 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 14030 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 602:
#line 6353 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 14036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 603:
#line 6355 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 14044 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 604:
#line 6359 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	char* c;
	List_Read((yyvsp[0].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[0].l));
    }
#line 14057 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 605:
#line 6371 "Gmsh.y" /* yacc.c:1652  */
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
#line 14075 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 606:
#line 6385 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14083 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 607:
#line 6389 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14091 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 608:
#line 6396 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 14103 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 609:
#line 6404 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 14115 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 610:
#line 6412 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-5].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-5].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-5].c));
    }
#line 14127 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 611:
#line 6423 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14133 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 612:
#line 6425 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14139 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 613:
#line 6428 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 14145 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;


#line 14149 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6431 "Gmsh.y" /* yacc.c:1918  */


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
