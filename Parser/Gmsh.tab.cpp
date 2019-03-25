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
#include "Generator.h"
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


#line 244 "Gmsh.tab.cpp" /* yacc.c:337  */
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
    tOnelabAction = 327,
    tOnelabRun = 328,
    tCodeName = 329,
    tCpu = 330,
    tMemory = 331,
    tTotalMemory = 332,
    tCreateTopology = 333,
    tCreateGeometry = 334,
    tRenumberMeshNodes = 335,
    tRenumberMeshElements = 336,
    tDistanceFunction = 337,
    tDefineConstant = 338,
    tUndefineConstant = 339,
    tDefineNumber = 340,
    tDefineStruct = 341,
    tNameStruct = 342,
    tDimNameSpace = 343,
    tAppend = 344,
    tDefineString = 345,
    tSetNumber = 346,
    tSetTag = 347,
    tSetString = 348,
    tPoint = 349,
    tCircle = 350,
    tEllipse = 351,
    tCurve = 352,
    tSphere = 353,
    tPolarSphere = 354,
    tSurface = 355,
    tSpline = 356,
    tVolume = 357,
    tBox = 358,
    tCylinder = 359,
    tCone = 360,
    tTorus = 361,
    tEllipsoid = 362,
    tQuadric = 363,
    tShapeFromFile = 364,
    tRectangle = 365,
    tDisk = 366,
    tWire = 367,
    tGeoEntity = 368,
    tCharacteristic = 369,
    tLength = 370,
    tParametric = 371,
    tElliptic = 372,
    tRefineMesh = 373,
    tAdaptMesh = 374,
    tRelocateMesh = 375,
    tReorientMesh = 376,
    tSetFactory = 377,
    tThruSections = 378,
    tWedge = 379,
    tFillet = 380,
    tChamfer = 381,
    tPlane = 382,
    tRuled = 383,
    tTransfinite = 384,
    tPhysical = 385,
    tCompound = 386,
    tPeriodic = 387,
    tParent = 388,
    tUsing = 389,
    tPlugin = 390,
    tDegenerated = 391,
    tRecursive = 392,
    tRotate = 393,
    tTranslate = 394,
    tSymmetry = 395,
    tDilate = 396,
    tExtrude = 397,
    tLevelset = 398,
    tAffine = 399,
    tBooleanUnion = 400,
    tBooleanIntersection = 401,
    tBooleanDifference = 402,
    tBooleanSection = 403,
    tBooleanFragments = 404,
    tThickSolid = 405,
    tRecombine = 406,
    tSmoother = 407,
    tSplit = 408,
    tDelete = 409,
    tCoherence = 410,
    tIntersect = 411,
    tMeshAlgorithm = 412,
    tReverseMesh = 413,
    tLayers = 414,
    tScaleLast = 415,
    tHole = 416,
    tAlias = 417,
    tAliasWithOptions = 418,
    tCopyOptions = 419,
    tQuadTriAddVerts = 420,
    tQuadTriNoNewVerts = 421,
    tRecombLaterals = 422,
    tTransfQuadTri = 423,
    tText2D = 424,
    tText3D = 425,
    tInterpolationScheme = 426,
    tTime = 427,
    tCombine = 428,
    tBSpline = 429,
    tBezier = 430,
    tNurbs = 431,
    tNurbsOrder = 432,
    tNurbsKnots = 433,
    tColor = 434,
    tColorTable = 435,
    tFor = 436,
    tIn = 437,
    tEndFor = 438,
    tIf = 439,
    tElseIf = 440,
    tElse = 441,
    tEndIf = 442,
    tExit = 443,
    tAbort = 444,
    tField = 445,
    tReturn = 446,
    tCall = 447,
    tSlide = 448,
    tMacro = 449,
    tShow = 450,
    tHide = 451,
    tGetValue = 452,
    tGetStringValue = 453,
    tGetEnv = 454,
    tGetString = 455,
    tGetNumber = 456,
    tUnique = 457,
    tHomology = 458,
    tCohomology = 459,
    tBetti = 460,
    tExists = 461,
    tFileExists = 462,
    tGetForced = 463,
    tGetForcedStr = 464,
    tGMSH_MAJOR_VERSION = 465,
    tGMSH_MINOR_VERSION = 466,
    tGMSH_PATCH_VERSION = 467,
    tGmshExecutableName = 468,
    tSetPartition = 469,
    tNameToString = 470,
    tStringToName = 471,
    tAFFECTPLUS = 472,
    tAFFECTMINUS = 473,
    tAFFECTTIMES = 474,
    tAFFECTDIVIDE = 475,
    tOR = 476,
    tAND = 477,
    tEQUAL = 478,
    tNOTEQUAL = 479,
    tLESSOREQUAL = 480,
    tGREATEROREQUAL = 481,
    tLESSLESS = 482,
    tGREATERGREATER = 483,
    tPLUSPLUS = 484,
    tMINUSMINUS = 485,
    UNARYPREC = 486
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 167 "Gmsh.y" /* yacc.c:352  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;

#line 530 "Gmsh.tab.cpp" /* yacc.c:352  */
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
#define YYLAST   16738

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  254
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  611
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2180

#define YYUNDEFTOK  2
#define YYMAXUTOK   486

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
       2,     2,     2,   239,     2,   251,     2,   236,   238,     2,
     244,   245,   234,   232,   253,   233,   250,   235,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     226,     2,   228,   221,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   246,     2,   247,   243,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   248,   237,   249,   252,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   222,   223,   224,   225,
     227,   229,   230,   231,   240,   241,   242
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
    1651,  1688,  1728,  1744,  1760,  1792,  1808,  1825,  1841,  1891,
    1909,  1915,  1921,  1928,  1959,  1974,  1996,  2019,  2042,  2065,
    2089,  2113,  2137,  2163,  2180,  2196,  2214,  2232,  2239,  2248,
    2247,  2277,  2279,  2281,  2283,  2285,  2293,  2295,  2297,  2299,
    2307,  2309,  2311,  2319,  2321,  2323,  2325,  2335,  2351,  2367,
    2383,  2399,  2415,  2432,  2469,  2491,  2515,  2516,  2521,  2524,
    2528,  2545,  2565,  2585,  2604,  2631,  2650,  2671,  2686,  2702,
    2720,  2771,  2792,  2814,  2837,  2942,  2958,  2993,  3015,  3037,
    3049,  3055,  3070,  3098,  3110,  3119,  3126,  3138,  3158,  3162,
    3167,  3171,  3176,  3183,  3190,  3197,  3209,  3282,  3300,  3325,
    3340,  3373,  3385,  3409,  3413,  3418,  3425,  3430,  3440,  3445,
    3451,  3459,  3463,  3467,  3471,  3475,  3484,  3548,  3564,  3581,
    3598,  3620,  3642,  3677,  3685,  3693,  3699,  3706,  3713,  3733,
    3759,  3771,  3782,  3800,  3818,  3837,  3836,  3861,  3860,  3887,
    3886,  3911,  3910,  3933,  3949,  3966,  3983,  4006,  4034,  4037,
    4043,  4055,  4075,  4079,  4083,  4087,  4091,  4095,  4099,  4103,
    4112,  4125,  4126,  4127,  4128,  4129,  4133,  4134,  4135,  4136,
    4137,  4140,  4164,  4183,  4206,  4209,  4225,  4228,  4245,  4248,
    4254,  4257,  4264,  4267,  4274,  4296,  4337,  4381,  4420,  4445,
    4457,  4469,  4481,  4493,  4502,  4532,  4558,  4584,  4616,  4643,
    4669,  4695,  4721,  4747,  4769,  4780,  4828,  4882,  4897,  4909,
    4920,  4927,  4942,  4956,  4957,  4958,  4962,  4968,  4980,  4998,
    5026,  5027,  5028,  5029,  5030,  5031,  5032,  5033,  5034,  5041,
    5042,  5043,  5044,  5045,  5046,  5047,  5048,  5049,  5050,  5051,
    5052,  5053,  5054,  5055,  5056,  5057,  5058,  5059,  5060,  5061,
    5062,  5063,  5064,  5065,  5066,  5067,  5068,  5069,  5070,  5071,
    5072,  5073,  5074,  5075,  5076,  5077,  5078,  5087,  5088,  5089,
    5090,  5091,  5092,  5093,  5094,  5095,  5096,  5097,  5102,  5101,
    5109,  5111,  5116,  5121,  5125,  5130,  5135,  5139,  5143,  5147,
    5151,  5155,  5159,  5165,  5181,  5186,  5192,  5198,  5217,  5238,
    5271,  5275,  5280,  5284,  5288,  5292,  5297,  5302,  5312,  5322,
    5327,  5338,  5347,  5352,  5357,  5385,  5386,  5392,  5393,  5399,
    5398,  5421,  5423,  5428,  5437,  5439,  5445,  5446,  5451,  5455,
    5459,  5463,  5467,  5474,  5478,  5482,  5486,  5493,  5498,  5505,
    5510,  5514,  5519,  5523,  5531,  5542,  5546,  5550,  5564,  5572,
    5580,  5587,  5597,  5620,  5625,  5631,  5636,  5642,  5653,  5659,
    5665,  5671,  5681,  5691,  5701,  5713,  5717,  5722,  5734,  5738,
    5742,  5746,  5764,  5772,  5780,  5809,  5819,  5835,  5846,  5851,
    5855,  5859,  5871,  5875,  5887,  5904,  5914,  5918,  5933,  5938,
    5945,  5949,  5954,  5968,  5984,  5988,  5992,  5996,  6000,  6008,
    6014,  6023,  6027,  6031,  6039,  6045,  6051,  6055,  6063,  6071,
    6078,  6087,  6091,  6095,  6110,  6124,  6138,  6150,  6166,  6175,
    6184,  6194,  6205,  6213,  6221,  6225,  6244,  6251,  6257,  6264,
    6272,  6271,  6281,  6305,  6307,  6313,  6318,  6320,  6325,  6330,
    6335,  6337,  6341,  6353,  6367,  6371,  6378,  6386,  6394,  6405,
    6407,  6410
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
  "tOnelabAction", "tOnelabRun", "tCodeName", "tCpu", "tMemory",
  "tTotalMemory", "tCreateTopology", "tCreateGeometry",
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
     475,    63,   476,   477,   478,   479,    60,   480,    62,   481,
     482,   483,    43,    45,    42,    47,    37,   124,    38,    33,
     484,   485,   486,    94,    40,    41,    91,    93,   123,   125,
      46,    35,   126,    44
};
# endif

#define YYPACT_NINF -1832

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1832)))

#define YYTABLE_NINF -559

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   12590,    58,    87, 12746, -1832, -1832,  -103,    17,     1,  -110,
     -63,    42,   107,   208,   222,   241,   -23,   273,   294,   341,
     375,   178,   204,    18,   -39,   400,   -39,   109,   219,   229,
      33,   236,   259,    34,   265,   277,   327,   350,   359,   434,
     458,   467,   491,   500,    15,   473,   622,   685,   480,   133,
     648,   509,  6980,   545,   520,   551,   712,   -35,   540,   420,
      80,   227,   607,   738,   -99,   597,  -159,  -159,   651,   337,
     388,   689, -1832, -1832, -1832, -1832, -1832,   632,   525,   804,
     843,    19,    52,   848,   853,   143,   950,   953,   954,  6012,
     955,   716,   718,   719,    25,    49, -1832,   720,   721, -1832,
   -1832,   960,   961,   715, -1832,  2736,   724,  3335,    16,    27,
   -1832, -1832, -1832, 11802,   723, -1832, -1832, -1832, -1832, -1832,
     722, -1832, -1832, -1832, -1832, -1832, -1832, -1832, -1832, -1832,
   -1832,   -86, -1832, -1832, -1832, -1832,    51, -1832,   965,   731,
    5763,   313,   725,   966, 11802, 12919, 12919, -1832, 11802, -1832,
   -1832, -1832, -1832, 12919, -1832, -1832, -1832, -1832, -1832, -1832,
     732,   741,   977, -1832, -1832,  3851,   747,   748,   749,   750,
      18, 11802, 11802, 11802,   754, 11802, 11802, 11802,   755, 11802,
   11802, 11802, 11802, 11802, 11802, 11802, 12919, 11802, 11802, 11802,
   11802,  6012,   757, -1832,  9632, -1832, -1832, -1832,   756,  6012,
    7222, 12919, -1832, -1832, -1832, -1832, -1832,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
      11,   -39,   -39,   -39,   -39,   -39,   761,   -39,   -39,   762,
     420, -1832, -1832, -1832,   -39,   -39,    35,   825,   826,   827,
     763,  7222,   887,   420,   420,   768,   -39,   -39,   770,   772,
     773, -1832, -1832, -1832, 11802,  7464, 11802, 11802,  7706,    18,
     837,    36, -1832, -1832,   775, -1832,  4396, -1832, -1832, -1832,
   -1832, -1832,   117, 11802,  9632,  9632,   776,   777,  7948,  6012,
    6012,  6012, -1832, -1832, -1832, -1832, -1832, -1832, -1832, -1832,
     778,  8190,   779,  4805,  1027,  7222,   786,    25,   787,   788,
    -159,  -159,  -159, 11802, 11802,   199, -1832,   302,  -159, 10524,
     344,    96,   795,   796,   800,   801,   802,   805,   807,  9632,
   11802,  6012,  6012,  6012,   808,    24,  1042,   809, -1832,  1047,
    1050, -1832,   811,   812,   813, -1832, -1832,   814,  6012,   819,
     820,   821, -1832, 11802,  6254, -1832,  1051,  1062, 11802, 11802,
   11802,   186, 11802,   822, -1832,   889, 11802, 11802, 11802, -1832,
   -1832, 11802, -1832,   -39,   -39,   -39,   828,   829,   830,   -39,
     -39,   -39,   -39,   -39,   -39,   -39, -1832,   -39, -1832, -1832,
   -1832,   -39,   -39,   831,   832,   -39,   839, -1832,   823,  1089,
    1107,   867, -1832, -1832,  1110,  1111,  1112,  1113,   -39, 11802,
   14354,   130, 12919,  9632, 11802, -1832, -1832,  7222,  7222, -1832,
     872,  3851,   420,  1115, -1832, -1832, -1832, -1832, -1832, -1832,
   11802, 11802,    38,  7222,  1117,   691,   877,  1274,   881,  1124,
      75,   883, -1832,   884, 12940, 11802, -1832,  1533,   -58, -1832,
      57,   182,  6916, -1832,   238, -1832,    68,  -141,   -16,  1043,
   -1832,    18,   885, 11802, 11802, 11802, 11802,   886, 14870, 14895,
   14920, 11802, 14945, 14970, 14995, 11802, 15020, 15045, 15070, 15095,
   15120, 15145, 15170,   895, 15195, 15220, 15245, 13542,  1135, 11802,
    9632,  4917, -1832,   126, 11802,  1139,  1141,   903, 11802, 11802,
   11802, 11802, 11802, 11802, 11802, 11802, 11802, 11802, 11802, 11802,
   11802, 11802, 11802, 11802,  9632, 11802, 11802, 11802, 11802, 11802,
   11802,  9632,  9632,   901, 11802, 11802, 12919, 11802, 12919,  7222,
   12919, 12919, 12919,   902, 11802,    13, -1832, 10603, 11802,  7222,
    6012,  7222, 12919, 12919,  9632,    18,  3851,    18,   908,  9632,
     908, -1832,   908, 15270, -1832,   334,   904,    95,  1088, -1832,
    1145, 11802, 11802, 11802, 11802, 11802, 11802, 11802, 11802, 11802,
   11802, 11802, 11802, 11802, 11802,  8432, 11802, 11802, 11802, 11802,
   11802,    18, 11802, 11802,  1151, -1832,   696, 15295,   351,   366,
   11802, 11802, 11802, -1832,  1150,  1152,  1152,   914, 11802, 11802,
    1154,  9632,  9632, 14382,   916,  1156, -1832,   915, -1832, -1832,
    -161, -1832, -1832,  7158,  7400,  -159,  -159,   313,   313,  -133,
   10524, 10524, 11802,  4466,  -105, -1832, 11802, 11802, 11802, 11802,
   11802, 11802, 11802, 11802, 11802,   414, 15320,  1157,  1159,  1160,
   11802,  1164, 11802, -1832, -1832, 11802,  5815, -1832, -1832,  9632,
    9632,  9632, 11802,  1165, 11802, 11802, 11802, 15345,   917, -1832,
   -1832, 15370, 15395, 15420,   998,  7642, -1832,   931,  5150, 15445,
   15470, 14465, 12919, 12919, 12919, 12919, 12919, 12919, 12919, 12919,
   12919, 11802, 12919, 12919, 12919, 12919,    10,  3851, 12919, 12919,
   12919,    18,    18, -1832, -1832,  9632, -1832,   932, 10965, -1832,
     933, 11288, 11802,   908, 11802, -1832,    18, 11802, 11802,  1151,
     936,   415, 15495, 11611,   935,   441, 11802,  1178,   938,  7222,
   15520, 14492,   165,   939,  1181,  1184, -1832, -1832, -1832,  9632,
      32, 11802, -1832, -1832, -1832,    18, 11802, 11802,  1151,   945,
   -1832,   949,   -33,   420,    80,   420, -1832,   946, 13571, -1832,
     141,  9632,    18, 11802, 11802,  1191,  1194,  9632, 11802,  1195,
   12919,    18, 10840,  1191,  1197, -1832,    18,  1198, 12919, 11802,
     952,   959, -1832, 11802,  7884,  8126,  8368,  8610,  3851,  1199,
    1200,  1201, 15545,  1202,  1203,  1204, 15570,  1205,  1206,  1207,
    1209,  1210,  1211,  1212, -1832,  1213,  1214,  1215, -1832, 11802,
   15595,  9632,   975,  9632, 13600, -1832, -1832,  1218, 14438, 14438,
   14438, 14438, 14438, 14438, 14438, 14438, 14438, 14438, 14438,  8847,
   14438, 14438, 14438, 14438,   594,   566, 14438, 14438, 14438,  9084,
    9326,  9568,  4917,   980,   982,   102,  9632,  9900, 10230,   566,
   10471,   566,   974,   983,   984,   271,  9632, 16495, -1832,   566,
     986, 13629, 13658, -1832, -1832,   985,   155,   566,   298,   994,
     336,   447,  1233, -1832,  1191,   566,   999,   997,  5250,  5279,
     874,  1247,  1109,  1109,   374,   374,   374,   374,   374,   374,
     396,   396,  9632,  -162, -1832,  -162,  -162,   908,   908,   908,
    1000, 15620, 14519,    28,   397,  9632, -1832,  1241,  1001,  1003,
   15645, 15670, 15695, 11802,  7222,  1249,  1248, 10287, 13687, 15720,
   -1832,   455,   457,  9632,  1005, -1832, 11830, -1832, 11960, 12017,
    -159, 11802, 11802, -1832, -1832,  1007,  1009, 10524,  5948,  1125,
     311,  -159, 12084, 15745, 13716, 15770, 15795, 15820, 15845, 15870,
   15895, 15920,  1012,  1255, 11802,  1257, -1832, 11802, 15945, -1832,
   14546, 12141, 14573, -1832,   460,   465,   468, 13745, -1832, 14600,
   14627, 10555, -1832, -1832,  1258,  1259,  1260,  1014, 11802, 12208,
   11802, 11802, -1832, -1832,    39,   391,   405,   391,  1023,  1024,
    1018,   566,   566,  1020, 10796,   566,   566,   566,   566, 11802,
     566,  1265, -1832,  1025,  1031,   406,   163,  1030,   470, -1832,
   -1832, -1832, -1832, 14438,  -162, 12265,  1032,   523,  1033,  1101,
    1277,  1132, 10926,  1038,  1040,  1283,  7222, 13774, -1832, 11802,
    1285,   171,   115,  3851, 11802,  1286,  1289,    26, -1832,   471,
    1250,  1251,  7222, 13803,    31,  1044, 15970, 14654,   118, 11802,
   11802,  1054,  1052,  1057,  1055,  8674, -1832, -1832, -1832, -1832,
   12919,   348,  1045, 15995, 14681, -1832,  1058, -1832,   373, 11119,
   -1832, -1832, -1832,  1076, -1832,  1060, -1832,    76, -1832, -1832,
   16495, -1832,  1301, 14438, 11802, 11802, 11802, 11802,   566,  -159,
    7222,  7222,  1321,  7222,  7222,  7222,  1323,  7222,  7222,  7222,
    7222,  7222,  7222,  7222,  7222,  7222,  7222,  1621,  1326,  9632,
    4917, -1832, -1832, -1832, -1832, -1832, -1832, -1832, -1832, -1832,
   -1832, -1832, -1832, -1832, -1832, 11802, -1832, -1832, -1832, -1832,
   -1832, -1832, -1832, -1832, -1832, 11802, 11802, 11802, -1832, -1832,
   -1832,   476, 11802, 11802, -1832, 11802, -1832,  7222, 12919, 12919,
   -1832,   478,  1097, -1832, -1832, -1832,  1169, 11802, 11802, -1832,
   -1832, -1832,  1191, -1832,  1191, 11802, 11802,  1108, -1832,  7222,
     -39, -1832, 11802, -1832, 11802, 11802,   481,  1191,    28,   215,
   -1832, 11802, 11802,   566,   484,  7222,  9632,  9632,  1347,  1348,
    1349,   550, -1832, -1832,  1351, -1832,  1114, 16495,  1105, -1832,
    1353,  1354,  1356,   487,  1360, -1832, 12332, -1832, -1832,  -101,
   11433, 11670, -1832, -1832, 13832,   -92,  1256,  1363, 11163,  1121,
    1364,  1127,    37,    41,   -36, -1832,   -97, -1832,   311,  1365,
    1367,  1381,  1382,  1386,  1387,  1388,  1389,  1390,   313,  7222,
   16495, -1832,  2151,  1153,  1396, -1832,  1398,  1399,  1306,  1400,
   -1832,  1402,  1403, 11802,  7222,  7222,  7222,  1406, 12386, -1832,
    5458,  1086,    50,  1407, -1832,  9632, -1832, -1832, -1832, -1832,
   12919, -1832, -1832, 11802, 12919, -1832, -1832, -1832, -1832, 16495,
   -1832,  1161,  1163, 12919, -1832, 12919, -1832,  1191, 12919,  1168,
   -1832,  1170, -1832,  1191, 11802, 11802,  1173,   420,  1174, 11249,
   -1832,  2206,  1176,  7222, -1832,  1179, -1832, 13861, -1832, -1832,
   11802,  1411,    40, 11802,  1419,  1421,  2271, -1832,  1423,    25,
    1425,  1186,   566,   -39,   -39,  1427, -1832, -1832,  1190,  1192,
    1187, -1832,  1431, -1832, -1832, -1832, -1832, -1832,  1191,  -180,
     928, 11802, 14708, 16020, 11802,  8911, 11802,  9632,  1189,   492,
    1433,   173,  1191, -1832,  1193, 11802,  1434, 11802,  1191, 11486,
    9869,   566,  5214,  1208,  1196, -1832,  1436, 16045, 16070, 16095,
   16120,  1438,   104,  1319,  1319,  7222,  1442,  1444,  1445,  7222,
     -75,  1447,  1448,  1450,  1451,  1452,  1453,  1455,  1457,  1459,
   -1832,  1461,   493, 14438, 14438, 14438, 14438,   566, 12870, 12915,
   12948,  1222,   566,   566, -1832,  1301,   566, 16145, 14438,  1223,
     -78, 16495, 14438, -1832,  1463,   566, 12981, 16495, 16495, -1832,
     638, -1832,  1482, -1832, 16170, 14735, -1832,   566,  1481,   498,
     503,  7222,  7222,  7222,  1485,  1486, -1832,   203, 11802,  7222,
    1243,  1246,  1506,   524, -1832, 11802, 11802, 11802,  1266,  1267,
    1268,  1273, -1832,  2389,  7222, -1832, 11802, -1832,  1514, -1832,
    1515, -1832, -1832, 10524,     4,  6496, -1832,  1275,  1278,  1279,
    1280,  1281,  1284,  9148,  1282,  1516, -1832,  9632, -1832, -1832,
   -1832,  1287, 11802, -1832, -1832, 14762,  1527,  1528,  1358, -1832,
   11802, 11802, 11802, -1832,  1531,  1532,  1534,   922,   409,  1288,
    3580,  1290, 11802,    29,   566,  1297,   566,  1291, -1832, -1832,
    3851,   649, 11802,  1298, -1832, -1832,  2416, -1832, -1832,  1292,
    1541, -1832,  2957, -1832,   177,  1299,  1544,  2987, -1832, -1832,
   -1832,    25, -1832,   506, -1832, 11802,   203,  2074,  2149, -1832,
    1308, 11802, 11802,  7222,  1305, -1832,   453,  1550,  1549, 16195,
    1551,  1233, 16220,  1309,   511, 16245,   517,  1553,  1554, -1832,
   -1832, 12919,  1318,  1559, 16270, -1832, 13014,  1320, -1832,  5521,
   16495, -1832,  1558,   -39,  7706, -1832, -1832, -1832, -1832,  1301,
   -1832,  1560,  1561,  1562,  1563, -1832, -1832,  -159,  1564,  1565,
    1567, -1832, -1832, -1832,  1568,   -31,  1477,  1571, -1832, -1832,
   -1832, -1832, -1832, -1832, -1832, -1832, -1832,  1573,  1331, -1832,
   -1832, -1832, -1832, -1832, 11802, 11802, 11802, -1832, -1832, -1832,
    1196, -1832, -1832, -1832, -1832, 11802,  1335,  1328, -1832, -1832,
   11802, 11802, 11802,   566,    28, -1832, -1832, -1832, -1832,  1334,
    1336,  1577,   -75,  1579, 11802, -1832,  7222, 16495,   942,  9632,
    9632, 11802, -1832, 10287, 13890, 16295,  6190,   313,   313, 11802,
   11802, -1832,   330,  1333, 16320, -1832, -1832, 13919,   -59, -1832,
    1581,  1582,  7222,  -159,  -159,  -159,  -159,  -159,  6738,  1583,
   -1832, -1832,   541, 11802,  3045,  1584, -1832, -1832,  7222,  6432,
     637, 16345, -1832, -1832, -1832, -1832,  9957, -1832, 12919, 11802,
   -1832, 12919, 16495, 10199,  3851,  1338, -1832, -1832, -1832, -1832,
    1350,  1339, 11802, 11802, 13948, 11802, 11611, -1832, 11611,  7222,
   -1832, -1832,  3851, 11802,  1587,  1592,    26, -1832,  1591, -1832,
      25, 14789,  7222, 12919,  1593,   566, -1832,  1345,   566, 11802,
   13047, 13080,   542, -1832, 11802, 11802,  -132, -1832,  1352, -1832,
    1349,  1595,  1596,  1353,  1597, -1832, -1832,  1598, 11802, -1832,
   -1832, 11802, 11565, -1832, -1832,  1359,  2149,   543,  4160,  1599,
   -1832, -1832, -1832, -1832, -1832,   717, -1832, -1832, -1832, -1832,
    1361,  1362,  1366, -1832,  1603,  7222, 14438, 14438, 13113, 14438,
   -1832,  1368, 13146, 16370, 14816, -1832, -1832,  9632,  9632, -1832,
    1606, -1832, 16495,  1610,  1369, -1832,   548,   554, 14410,  3361,
    1613,  1376, -1832, -1832, 11802,  1377,  1379, 13977, 14843,  1619,
    7222,  1622,  1383, 11802, -1832, -1832,   555,   -47,   -21,   -17,
      -8,     6,  9390,   154, -1832,  1624, 14006, -1832, -1832,  1458,
   -1832, 11802, 11802, -1832, -1832,  9632,  3400,  1626,  1393, 14438,
     566, 16495, -1832, -1832, -1832, -1832,    29, -1832,  3851, -1832,
   14035,  1391,  1394,  1395,  1633,  3547, -1832,  1635,  1640, -1832,
   -1832,  1397,  1642,   556, -1832,  1643,  1646,   412, 16495, 11802,
   11802,  1408,  7222,   557, 16495, 16395, -1832, -1832, -1832, -1832,
   16420, 13179, -1832,  1097,  1163,  7222,   566, -1832, 11802,  3851,
      18,  9632,  9632, 11802,  1648,   585, -1832, -1832, 11802,  1328,
   -1832, 11802, -1832, -1832,   591,   601, -1832, -1832,  7222,   167,
     522,  9632, -1832, -1832,   313,  6674, -1832, -1832, -1832,  1649,
   -1832,  1409,  7222, -1832, 14064,  1651,  9632,  -159,  -159,  -159,
    -159,  -159, -1832, -1832, 11802, 14093, 14122,   603, -1832, -1832,
   -1832, -1832, -1832, -1832,  1415,  1655,  1416, -1832,  1657, -1832,
   -1832,    25, -1832,  1487, -1832, -1832, -1832, -1832, -1832, 11802,
   13212, 13245,  7222, -1832,  1660, 11802,  1420, -1832, 11802,  1424,
    1428, -1832, -1832,  4686, -1832,  1426,   604,   628, 14151, -1832,
    1432, 13278,  1429, 13311, -1832,  1435,   634,  1439,  -159,  7222,
    1663,  1441,  -159,  1666,   636,  1430, -1832, 11802, -1832,  1670,
    1547, 12389,  1443, -1832,   645,   166,   193,   196,   207,   211,
    3950, -1832, -1832,  1676,  1678, -1832, -1832, -1832,  1680, -1832,
    1446, 16495, 11802, 11802,   647, -1832, 16495, 13344, -1832, -1832,
    1097,  3851,  1454, -1832, -1832, -1832, 11802, 11802, -1832, 11802,
    9632,  1684,  -159,   127, -1832, -1832,  -159,   145, -1832,  1686,
   -1832, 14180, -1832, 11802, -1832,   311, -1832,  1687,  9632,  9632,
    9632,  9632,  9390, -1832, -1832, -1832, 11611, -1832, 11802, 16445,
   13377,    44, 11802,  1449, -1832, -1832, 13410, 13443, 13476,   653,
   -1832,   235, -1832,   246, -1832, -1832, -1832,  4118,   347, 12456,
   -1832,   656,   658,   663,   664,   252,   665,  1456,   666, -1832,
   11802, -1832,  7222, 14209, -1832, 11802, 11802, 11802, -1832,  -159,
    -159, -1832, -1832, -1832,   311,  1689,  1690,  1691,  1695,  9632,
    1696,  1697,  1702,  1462, 16470,   671,  1703, 14238, 14438, 13509,
     257,   342,   463, -1832, -1832, -1832, -1832,   672, -1832, -1832,
   -1832, 12919, -1832,  1464, -1832,  1705, -1832, 11802, 11802, 11802,
   -1832,  1708,   674, -1832,  1467,  7222, -1832, 14267, 14296, 14325,
   -1832,  1710, 12919, 12919,   677, -1832,  1712,  1715, -1832, -1832,
     682, -1832,  1716, -1832, -1832,  1717, 12919, -1832, -1832, -1832
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   609,     0,     0,     0,
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
      16,     0,    17,    18,    19,    20,     0,    25,     0,   610,
       0,   218,     0,     0,     0,     0,     0,   267,     0,   269,
     270,   265,   266,     0,   271,   272,   273,   274,   113,   123,
     609,   486,   481,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,     0,   203,   204,   205,     0,     0,
       0,     0,   427,   428,   430,   431,   429,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   435,   436,   437,     0,     0,   191,   196,   197,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   433,   434,     0,     0,     0,     0,     0,     0,
       0,     0,   521,   522,     0,   523,   499,   380,   440,   443,
     304,   500,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   189,   196,   197,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   488,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   609,     0,     0,   218,     0,
       0,   370,     0,     0,     0,   200,   201,     0,     0,     0,
       0,     0,   507,     0,     0,   505,     0,     0,     0,     0,
       0,   609,     0,     0,   544,     0,     0,     0,     0,   263,
     264,     0,   561,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   563,     0,   587,   565,
     566,     0,     0,     0,     0,     0,     0,   564,     0,     0,
       0,     0,   283,   284,     0,   218,     0,   218,     0,     0,
       0,   481,     0,     0,     0,   218,   376,     0,     0,    76,
       0,    63,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,     0,     0,   550,
     481,     0,   217,     0,   216,     0,   170,     0,     0,   550,
     551,     0,     0,   599,     0,   600,   551,   111,   111,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   538,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   514,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   383,     0,
     382,   508,   384,     0,   501,     0,     0,   481,     0,   516,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,   457,     0,     0,     0,     0,
       0,     0,     0,   305,     0,   338,   338,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,     0,   218,   218,
       0,   490,   489,     0,     0,     0,     0,   218,   218,     0,
       0,     0,     0,   301,     0,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   340,     0,     0,
       0,     0,     0,   218,   244,     0,     0,   242,   371,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
     262,     0,     0,     0,     0,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,   286,     0,   249,     0,     0,   251,
       0,     0,     0,   382,     0,   218,     0,     0,     0,     0,
       0,     0,     0,   326,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    72,    73,     0,
       0,     0,   260,    38,   256,     0,     0,     0,     0,     0,
     213,     0,     0,     0,     0,     0,   219,     0,     0,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,   484,
       0,     0,   482,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   332,     0,     0,     0,   195,     0,
       0,     0,     0,     0,     0,   366,   367,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   438,   456,     0,
       0,     0,     0,   517,   518,     0,     0,     0,     0,     0,
     475,     0,   381,   502,     0,     0,     0,     0,   510,     0,
     400,   399,   397,   398,   393,   395,   394,   396,   402,   401,
     386,   385,     0,   387,   509,   388,   391,   389,   390,   392,
     482,     0,     0,   483,   460,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,   336,     0,     0,     0,     0,
     369,     0,     0,     0,     0,   368,     0,   218,     0,     0,
       0,     0,     0,   492,   491,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   355,     0,     0,   243,
       0,     0,     0,   237,     0,     0,     0,     0,   365,     0,
       0,     0,   381,   506,     0,     0,     0,     0,     0,     0,
       0,     0,   288,   289,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,     0,     0,     0,   477,     0,     0,   248,
     252,   250,   254,     0,   387,     0,   482,   460,   611,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,   381,     0,    63,     0,     0,     0,     0,    79,     0,
      63,    64,     0,     0,     0,   482,     0,     0,   460,     0,
       0,     0,   189,     0,     0,     0,   606,    28,    26,    27,
       0,     0,     0,     0,     0,   483,   554,    29,     0,     0,
     257,   601,   602,     0,   603,   554,    74,   114,    75,   124,
     485,   487,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     540,   541,   206,     9,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   426,   413,     0,   415,   416,   417,   418,
     419,   537,   420,   421,   422,     0,     0,     0,   529,   528,
     527,     0,     0,     0,   534,     0,   472,     0,     0,     0,
     474,     0,   128,   455,   513,   512,   199,     0,     0,   441,
     536,   446,     0,   452,     0,     0,     0,     0,   503,     0,
       0,   453,     0,   515,     0,     0,     0,     0,   445,   444,
     467,    70,    71,     0,     0,     0,     0,     0,     0,     0,
     381,   334,   339,   337,     0,   347,     0,   148,   149,   199,
     381,     0,     0,     0,     0,   238,     0,   253,   255,     0,
       0,     0,   207,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     0,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   218,     0,
     341,   354,     0,     0,     0,   239,     0,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     0,     0,     0,   577,     0,   584,   573,   574,   575,
       0,   589,   588,     0,     0,   578,   579,   580,   586,   593,
     592,     0,   139,     0,   567,     0,   569,     0,     0,     0,
     562,     0,   247,     0,     0,     0,     0,     0,     0,     0,
     327,     0,     0,     0,   377,     0,   607,     0,   101,    63,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,   559,    48,     0,     0,
       0,    61,     0,    39,    40,    41,    42,    43,     0,   445,
     444,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   553,   552,     0,     0,     0,     0,     0,
       0,     0,   135,     0,   131,   132,     0,     0,     0,     0,
       0,     0,     0,   155,   155,     0,     0,     0,     0,     0,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     344,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   520,     0,     0,     0,     0,     0,
     475,   476,     0,   448,     0,     0,     0,   511,   403,   504,
     461,   459,     0,   458,     0,     0,   525,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   346,     0,     0,     0,
       0,     0,     0,     0,   246,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,   312,     0,   315,     0,   317,
       0,   302,   309,     0,     0,     0,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,     0,   241,   240,
     372,     0,     0,    35,    36,     0,     0,     0,     0,   545,
       0,     0,     0,   278,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   477,   478,   571,
       0,   461,     0,     0,   218,   328,     0,   329,   218,     0,
       0,   560,     0,    86,     0,     0,     0,     0,    84,    91,
      93,     0,   548,     0,    99,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,    34,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,   555,     0,     0,    32,     0,   555,   604,     0,
     115,   120,     0,     0,     0,   134,   137,   138,   480,     0,
      77,     0,     0,     0,     0,    78,   157,     0,     0,     0,
       0,   158,   173,   174,     0,     0,     0,     0,   159,   184,
     175,   179,   180,   176,   177,   178,   165,     0,     0,   414,
     423,   424,   425,   530,     0,     0,     0,   470,   471,   473,
     129,   439,   469,   442,   447,     0,     0,   475,   185,   454,
       0,    70,    71,     0,   466,   462,   464,   531,   181,     0,
       0,     0,   151,     0,     0,   345,     0,   150,     0,     0,
       0,     0,   261,     0,     0,     0,     0,   218,   218,     0,
       0,   314,   499,     0,     0,   316,   318,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     212,   182,     0,     0,     0,     0,   162,   163,     0,     0,
       0,     0,   102,   103,   104,   108,     0,   585,     0,     0,
     583,     0,   594,     0,     0,   140,   141,   591,   568,   570,
       0,     0,     0,     0,     0,     0,   326,   330,   326,     0,
     378,    85,    63,     0,     0,     0,     0,    83,     0,   546,
       0,     0,     0,     0,     0,     0,   597,   596,     0,     0,
       0,     0,     0,   497,     0,     0,   466,   258,   462,   259,
       0,     0,     0,     0,     0,   223,   220,     0,     0,   558,
     556,     0,     0,   116,   121,     0,     0,     0,   538,   539,
     133,   349,   350,   351,   352,   156,   160,   161,   166,   183,
       0,     0,     0,   168,     0,     0,     0,     0,     0,     0,
     449,     0,     0,     0,     0,   526,   468,     0,     0,   167,
       0,   186,   335,     0,     0,   187,     0,     0,     0,     0,
       0,     0,   496,   495,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   234,     0,     0,     0,     0,
       0,     0,     0,     0,   225,     0,     0,   353,    37,     0,
     543,     0,     0,   280,   279,     0,     0,     0,     0,     0,
       0,   143,   144,   147,   146,   145,     0,   572,     0,   608,
       0,     0,     0,     0,     0,     0,    96,     0,     0,    97,
     549,     0,     0,     0,    88,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    46,     0,   224,   221,   222,    33,
       0,     0,   605,   128,   139,     0,     0,   136,     0,     0,
       0,     0,     0,     0,     0,     0,   532,   533,     0,   475,
     450,     0,   463,   465,     0,     0,   169,   190,     0,   342,
     342,     0,   109,   110,   218,     0,   210,   211,   303,     0,
     310,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   214,     0,     0,     0,     0,   105,   106,
     576,   582,   581,   142,     0,     0,     0,   331,     0,    92,
      94,     0,   100,     0,    82,   598,    89,    90,    49,     0,
       0,     0,     0,   498,     0,     0,   463,   557,     0,     0,
       0,   118,   595,     0,   125,     0,     0,     0,     0,   172,
       0,     0,     0,     0,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,     0,   320,     0,
       0,   297,     0,   226,     0,     0,     0,     0,     0,     0,
       0,   542,   281,     0,     0,   364,   218,   379,     0,   547,
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
      50,     0,    57,     0,   268,     0,   535,     0,     0,     0,
     300,     0,     0,    51,     0,     0,   276,     0,     0,     0,
     228,     0,     0,     0,     0,   519,     0,     0,    54,    52,
       0,    55,     0,   359,   360,     0,     0,    60,    58,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1832, -1832, -1832, -1832,   383, -1832, -1832, -1832, -1832,  -343,
   -1832, -1832, -1832, -1832, -1832, -1832, -1832, -1832, -1832, -1832,
   -1832, -1832,  -712,  -131,  4557,  3680, -1832,  1270, -1832, -1832,
   -1832, -1832, -1832, -1832, -1831, -1832,   352,   174,  -152, -1832,
    -100, -1832,   113,   384,  1746, -1832,   702,   -49, -1832, -1832,
       3,  -615,  -312, -1832, -1832, -1832, -1832, -1832, -1832, -1832,
   -1832,  1747, -1832, -1832, -1832, -1832, -1206, -1210,  1748, -1693,
    1770, -1832, -1832, -1832,  1182, -1832,  -136, -1832, -1832, -1832,
   -1832,  2404, -1832, -1832, -1395,   278,  1776, -1832,     2,  -693,
   -1832, -1832,   123, -1832, -1654,   646,  -172,  2816,  3071,  -306,
      64, -1832,  1801,   -71, -1832, -1832,    88,   254, -1642,  -129,
    1034, -1832,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   115,  1050,   116,   117,  1034,  1867,  1873,
    1323,  1530,  2020,  2152,  1324,  2123,  2170,  1325,  2154,  1326,
    1327,  1534,   433,   585,   586,  1120,   118,   766,   457,  1883,
    2030,  1884,   458,  1757,  1396,  1353,  1354,  1355,  1494,  1695,
    1696,  1186,  1587,  1578,   746,   597,   270,   271,   348,   199,
     272,   443,   444,   122,   123,   124,   125,   126,   127,   128,
     129,   273,  1218,  2055,  2114,   930,  1214,  1215,   274,  1013,
     275,   133,  1425,  1184,   905,   945,  1990,   134,   135,   136,
     137,   276,   277,  1142,  1157,  1279,   278,   771,   279,   894,
     770,   460,   612,   316,  1732,   355,   356,   281,   555,   363,
    1310,  1523,   453,   449,  1272,   990,  1567,  1725,  1726,   975,
     455,   139,   411
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   607,   925,   926,  1452,  1616,   121,   623,  1816,   434,
    1024,   301,  1454,  1851,   160,  1852,  1007,   160,  1032,   488,
     162,   404,   160,   335,   454,   161,   646,   495,   641,   361,
     160,   143,   406,  1693,   399,  1317,   403,   174,   178,  1030,
     536,   559,   722,  1447,  1514,  1038,  1252,  1449,   147,   282,
    2101,  1844,  1969,   365,  1484,   306,   340,   416,   341,  1585,
     428,   429,  1056,  1770,     4,   287,   752,   287,  -553,   439,
    1065,   615,   616,   311,   312,   578,   579,   761,   339,   160,
     307,   580,  1771,  1350,   735,   313,   282,     5,   288,   314,
    1041,   364,   920,   698,   462,   701,   308,   309,  1207,   615,
     616,   144,   400,   713,   461,   336,   764,  1586,   428,   429,
    1576,   581,   765,   149,  1886,  1208,  -558,   594,   595,   596,
     927,  1895,  1299,  1209,  1210,  1211,   581,   615,   616,  1212,
    1213,   615,   616,  2082,   145,   615,   616,   440,  1207,   706,
     615,   616,   450,   450,   442,   141,   342,  1047,   931,   142,
     456,  2084,  1435,  1485,  1486,  1208,  1453,  1439,   414,   637,
     638,   639,   415,  1209,  1210,  1211,   163,   467,   164,  1212,
    1213,  1160,  1023,   615,   616,  1155,   653,   297,  1299,  1550,
     298,   146,   299,   450,  1712,   615,   616,   750,   282,   315,
     317,   282,   320,   300,  1813,   751,   282,   282,   450,  2073,
    1318,  1319,  1320,  1321,  1448,   163,  1926,   164,  1450,   337,
    1299,   615,   616,  1451,   150,   615,   616,   723,   724,  1515,
    1516,   153,  1781,  1694,   615,   616,   114,   195,   151,   114,
     196,   767,  1927,   197,   114,   114,  1928,   765,   615,   616,
     345,   114,   114,   346,  1452,  1929,   198,   152,   282,  1031,
     425,   426,   427,  1659,  1986,   521,   347,   522,   727,  1930,
     728,   989,   282,   190,   405,   282,   557,   338,   428,   429,
     642,   556,   643,   362,  1309,   407,   142,   175,   179,   154,
    1322,   282,   282,   537,   560,   282,   282,   282,   282,  1253,
     148,   114,  2102,   366,   916,   417,   918,   919,   282,   418,
     155,   753,   282,   754,   364,  1987,  1988,   755,  2024,  1300,
    1303,  1989,   762,   932,   754,   428,   429,   441,   763,   736,
     163,   737,   164,  -551,   302,   738,   282,   303,   282,   282,
     282,   951,   424,   425,   426,   427,   615,   616,   561,   163,
     626,   164,   428,   429,   627,   282,   582,   156,   583,  1130,
     717,   282,   584,   171,   969,   428,   429,   428,   429,   615,
     616,   582,  1331,   583,  1285,  1302,  -554,   584,   853,  1048,
     428,   429,  1049,  2097,   707,   802,   708,   615,   616,   803,
     709,   157,   424,   425,   426,   427,   615,   616,   424,   425,
     426,   427,   321,  1005,   424,   425,   426,   427,   615,   616,
     727,  1048,   728,   845,  1049,   428,   429,  1931,  1148,   450,
     282,   428,   429,  1277,   282,   282,  1278,   428,   429,  2058,
     424,   425,   426,   427,   158,   615,   616,   756,   615,   616,
     282,   615,   616,   610,   611,   757,   664,   739,   142,   615,
     616,   619,   624,   615,   616,  1207,  2059,   617,  2125,  2060,
     159,    65,    66,    67,    68,   428,   429,    71,   772,  1399,
    2061,  1400,  1208,   172,  2062,  1412,    80,   615,   616,    83,
    1209,  1210,  1211,   173,  1410,   859,  1212,  1213,   615,   616,
     176,  1207,   322,   759,   615,   616,   323,   282,  2109,   615,
     616,   760,   324,   325,   166,   326,   327,   167,  1208,  2110,
     168,  2164,   169,   177,  1982,  2119,  1209,  1210,  1211,   180,
    2148,   282,  1212,  1213,   292,   328,  1140,   293,   282,   835,
     294,   181,   295,   450,   760,   450,   282,   450,   450,   456,
    1642,  1643,   849,    44,   615,   616,   282,   282,   282,   450,
     450,   282,   162,  1151,   162,   977,   282,   858,  1152,   860,
     618,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   311,
     312,   182,   282,   580,   615,   616,   615,   616,   890,  1809,
     163,   313,   164,   863,  1497,   319,  1154,   803,   191,  1155,
    1501,  1025,   625,  1341,   183,  2149,  2112,  1207,   282,   282,
     898,   803,   561,   184,   803,  1196,   573,   574,   704,   576,
     577,   578,   579,  1464,  1208,   899,   992,   580,  1346,   803,
     442,   442,  1209,  1210,  1211,   331,   803,   332,  1212,  1213,
     704,   576,   577,   578,   579,  1536,   727,   289,   728,   580,
     290,  1171,   291,  1172,   760,  1832,   282,   282,   282,  1552,
     727,   727,   728,   728,   727,  1557,   728,  1958,  1255,  1275,
    1991,  1992,   803,   942,  1009,  1959,  1989,   803,   803,   456,
     450,   456,   450,   450,   450,   450,   450,   450,   185,   450,
     450,   450,   450,   991,  1424,   450,   450,   450,   162,   997,
    1015,   193,   282,   996,  1016,  1043,  1158,  1735,   280,  1703,
     803,  -555,   186,  1006,  1191,   120,  1192,  1078,   803,  1237,
     803,   187,  2150,   803,  1238,  1636,   282,  1239,   803,  1281,
    1312,   803,   192,   803,   803,  1387,   282,  1394,   194,   803,
    1409,   803,  1035,  1417,   803,   188,  1432,   803,   923,   924,
     803,  1548,  1598,   611,   189,   803,   803,  1629,   282,  1052,
     200,   803,  1630,   201,   282,  1719,   803,   456,  1063,  1720,
    1742,   296,  1170,  1067,   803,   450,  1744,  1284,   284,  1285,
     803,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,   283,
    1825,  1871,  1887,   580,   803,  1872,  1888,  1909,   282,   285,
     282,   803,  1713,  1910,  1925,  1955,  1964,   803,  1872,   760,
    1965,   727,   286,   728,  1722,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   801,   576,
     577,   578,   579,   282,  1980,   305,  1188,   580,  1872,   727,
    1984,   728,   436,   282,   803,   310,   496,   436,   436,  2088,
    1985,   304,  2013,  2033,   803,   436,   803,   803,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,   330,  2034,  1452,   282,
     580,   803,  1621,  2041,  1622,  2049,  1833,  1872,   436,   803,
    1301,  1304,   282,  1702,  2057,  1703,  2071,   280,   803,   318,
    1872,   282,  2108,   436,   333,  2115,   803,  2116,  2132,   803,
     282,   803,  2117,  2118,  2120,  2122,   803,   803,   803,  1965,
    2143,  2151,  1452,  2161,  1872,   803,  2172,  2162,  1685,  1686,
    1872,  2175,   160,   372,   593,  2176,   727,   329,   728,   729,
     334,   727,   533,   728,   895,   343,  1794,   600,  1795,   615,
     616,   605,  1305,   344,   349,   540,   541,   350,   351,   357,
     358,   371,   359,   360,   367,   368,   369,   370,   401,   412,
     413,   419,   446,   445,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   420,   142,   459,   461,   382,   383,   384,
     385,   463,   464,   465,   466,   386,   387,   388,   471,   475,
     389,   489,   390,  1522,   494,   529,   532,  -192,  -193,  -194,
     539,   538,   542,   282,   545,   391,   546,   547,   392,   558,
     590,   591,   292,   415,  1311,   293,   598,   601,   294,   282,
     295,   604,  1805,  1806,   606,   608,   609,  1411,  1413,   628,
     629,    44,   282,  1199,   630,   631,   632,   450,   644,   633,
    1205,   634,   640,   647,  1216,   645,   648,   659,   422,   649,
     650,   651,   652,   714,   715,   654,   655,   656,   660,   692,
     666,   667,   675,   676,   677,   688,   689,   282,   282,   725,
     282,   282,   282,   691,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,  1482,   693,   282,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,   694,   436,   695,   696,   580,   699,   697,
     716,   700,   719,   726,   718,   731,   393,   394,   395,   733,
     734,   141,   769,   740,   282,   450,   450,   396,   773,   778,
     794,   397,   799,   398,   114,   805,   747,   806,   807,   836,
     846,   580,   866,   867,   864,   893,   282,   903,   907,   904,
     910,   914,   915,   917,   944,   946,   963,   947,   428,   429,
     949,   958,   282,   282,   282,   842,  -552,   967,  1537,   970,
    1014,   999,  1001,  1008,  1018,   593,  1019,   854,  1027,  1026,
    1028,  1039,  1706,  1040,  1045,  1055,  1708,  1071,  1411,  1413,
    1057,  1060,  1362,  1066,  1068,  1072,  1079,  1080,  1081,  1083,
    1084,  1085,  1087,  1088,  1089,  1718,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1099,  1103,  1128,   282,  1137,   436,  1129,
     436,   442,   436,   436,   436,  1144,  1138,  1139,  1147,  1153,
    1159,   282,   282,   282,   436,   436,  1163,  1162,  1175,  1176,
    1167,  1177,   282,  1183,  1185,  1194,  1202,   450,  1203,  1206,
    1228,   450,  1229,  1231,  1247,  1244,  1245,  1246,  1258,  1259,
     450,  1260,   450,  1263,  1271,   450,  1274,  1280,  1273,  1561,
     732,  1566,  1283,  1287,  1288,  1286,  1289,  1292,  1293,  1294,
     282,  1298,  1307,  1308,  1328,  1342,  1313,  1314,  1334,  1995,
    1335,  1336,  1345,  1337,  1349,  1352,   364,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,   747,  1348,   450,  1365,   580,
    1369,  1483,   282,  1381,   282,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,   747,   282,
    1395,  -195,   580,  1403,  1421,  1422,  1423,  1426,  1428,  1427,
    1429,  1430,   282,  1431,  1433,  1020,   282,  1441,  1440,  1444,
    1445,  1446,  1455,  1456,   436,   436,   436,   436,   436,   436,
     436,   436,   436,  1714,   436,   436,   436,   436,  1457,  1458,
     436,   436,   436,  1459,  1460,  1461,  1462,  1463,  1727,  1727,
     747,  1467,  1468,   747,  1469,  1470,  1471,  1472,  1473,  1474,
    1479,  1487,  1492,  1499,  1860,   747,  1493,  1513,   282,   282,
     282,  1502,  1504,  1500,  1508,  1518,   282,  1519,  1510,  1701,
    1521,  1524,  1525,  1529,  1531,  1533,  1532,  1535,  1547,  1549,
    1555,   282,  1570,  1553,  1575,  1042,  1577,  1044,  1581,  1569,
    1582,  1583,   282,  1588,  1589,  1568,  1590,  1591,  1592,  1593,
     282,  1594,   436,  1595,   282,  1596,  1597,  1607,  1614,  1618,
     436,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,  1624,  1628,  1754,  1634,
     580,  1639,  1635,  1786,  1640,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,  1641,  1647,  1648,  1649,   580,   364,  1650,
    1655,  1656,  1671,  1662,   456,   456,  1663,  1664,  1665,  1666,
     282,  1670,  1667,  1676,  1677,  1673,  1678,  1682,  1683,   749,
    1684,  1688,  1698,  1691,  1278,  1709,  1705,  1710,   450,  1715,
    1182,  1716,  1729,  1734,  1736,  1737,   282,  1739,  1741,  1745,
    1746,   282,  1748,  1749,  1752,  1755,  1761,  1762,  1763,  1764,
    1766,  1767,  1800,  1768,  1769,  1772,  1658,  1773,  1774,  1775,
    1780,  1155,  1787,  1789,  1788,  1791,  1810,  1814,  1815,  1824,
    1828,  1846,  1848,  1856,  1863,  1847,  1857,  1859,   760,  1864,
    -556,  1876,  1877,  1878,  1879,  1786,  1890,  1885,  1894,  1891,
    1892,  2001,  1906,  1900,  1893,  1837,  1907,  1908,   747,  1913,
     747,   747,  1842,  1845,  1914,  1920,  1916,  1380,  1917,  1922,
    1932,  1923,  1939,   282,   747,  1934,   282,   282,  1940,  1949,
    1946,  1854,  1951,  1947,  1948,  2018,  1952,  1953,  1954,  1956,
     442,   442,  1957,   747,  1979,  1998,  1962,  2003,  1999,   282,
    2014,  2015,  1295,  2017,  2016,   282,  2025,  2019,  -557,  2045,
    2032,   747,  2048,  2028,  2038,   282,  2052,  2029,  1315,  2050,
    2036,  2053,  2064,  2040,  2065,   450,  2067,  2042,   450,  2046,
    2080,  2056,  2085,  2090,  2068,  2133,  2134,  2135,  2104,  2075,
    1765,  2136,  2138,  2139,  2066,  2121,   282,   747,  2140,  2144,
    2141,  2156,  2155,  1311,  2160,  2163,  2168,   364,  2173,   282,
     456,  2174,  2177,  2178,  1551,  2098,  1363,  1364,   768,  1366,
    1367,  1368,  1970,  1370,  1371,  1372,  1373,  1374,  1375,  1376,
    1377,  1378,  1379,  1760,  2089,  1790,  1943,  1610,  1579,   119,
     130,   131,   436,   456,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   704,   576,   577,
     578,   579,   282,   132,  1993,  1700,   580,  1944,   906,   138,
    1858,  1843,  1728,  1391,   282,   282,  1817,  1818,  1819,  1820,
    1821,  1823,     0,     0,  1062,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1404,     0,   282,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1974,   282,
       0,  1418,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,     0,
     436,   436,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,     0,   282,
       0,     0,     0,     0,     0,  1465,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,  1975,   282,   282,
    1476,  1477,  1478,     0,     0,     0,     0,     0,   747,     0,
       0,     0,     0,     0,     0,   282,     0,     0,   282,     0,
       0,     0,     0,     0,     0,     0,     0,   442,     0,   282,
       0,     0,     0,   282,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1509,
       0,   438,     0,     0,     0,     0,   448,   451,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
    2074,     0,   436,     0,     0,     0,   436,     0,     0,     0,
       0,     0,     0,     0,     0,   436,     0,   436,     0,     0,
     436,     0,     0,     0,     0,     0,   282,   483,     0,  1503,
       0,     0,     0,     0,     0,     0,     0,     0,  1565,     0,
       0,     0,   497,     0,     0,     0,     0,     0,     0,     0,
       0,  1580,     0,     0,     0,  1584,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   436,     0,     0,     0,     0,   282,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2005,  2006,  2007,  2008,  2009,   282,   282,   282,   282,   282,
       0,     0,     0,     0,     0,     0,     0,  1631,  1632,  1633,
       0,     0,     0,     0,     0,  1638,     0,     0,   160,   372,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1653,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,  1661,     0,     0,     0,     0,     0,     0,     0,  1669,
       0,  2043,     0,     0,     0,  2047,   282,     0,     0,     0,
     373,   374,   375,   376,   377,   378,   379,   380,   381,     0,
       0,     0,     0,   382,   383,   384,   385,     0,   450,     0,
       0,   386,   387,   388,     0,     0,   389,     0,   390,     0,
       0,     0,   282,   160,   372,     0,     0,  1466,     0,   450,
     450,   391,     0,     0,   392,  2081,     0,     0,   292,  2083,
       0,   293,     0,   450,   294,     0,   295,     0,     0,  1733,
       0,     0,     0,     0,     0,  2095,     0,    44,     0,     0,
       0,     0,     0,     0,     0,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   422,  1753,     0,     0,   382,   383,
     384,   385,  1507,   710,     0,     0,   386,   387,   388,     0,
       0,   389,     0,   390,     0,     0,     0,     0,     0,   436,
     436,     0,  2130,  2131,     0,     0,   391,     0,     0,   392,
       0,     0,     0,   292,     0,     0,   293,     0,     0,   294,
       0,   295,     0,   436,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   393,   394,   395,     0,     0,  1520,     0,   422,
       0,     0,  1793,   396,     0,     0,     0,   397,     0,   398,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1733,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   727,
       0,   728,  1723,     0,  1829,     0,     0,   839,     0,   841,
       0,   843,   844,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   855,   856,     0,     0,   393,   394,   395,
       0,     0,     0,     0,     0,  1853,     0,     0,   396,     0,
       0,     0,   397,     0,   398,   114,     0,     0,  1862,     0,
       0,     0,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
     436,     0,     0,   436,   580,  1651,     0,  1723,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   747,     0,
     747,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1733,  1707,     0,     0,   436,     0,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,     0,  1921,     0,   436,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   976,     0,   978,   979,   980,   981,
     982,   983,     0,   985,   986,   987,   988,     0,     0,   993,
     994,   995,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,   410,  1963,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1971,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   437,     0,     0,     0,   447,     0,
       0,     0,   452,     0,  1733,     0,     0,     0,     0,     0,
       0,  1061,     0,     0,     0,     0,     0,     0,  2000,  1069,
       0,     0,     0,     0,     0,   468,   469,   470,     0,   472,
     473,   474,     0,   476,   477,   478,   479,   480,   481,   482,
       0,   484,   485,   486,   487,     0,     0,     0,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1733,     0,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
       0,     0,   580,     0,     0,  2044,     0,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,     0,     0,     0,   548,   550,
     552,   553,   491,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   491,   491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   747,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,     0,
       0,     0,     0,   614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   491,   636,     0,     0,     0,     0,     0,
     160,   372,     0,     0,     0,     0,     0,     0,  1733,     0,
       0,     0,     0,     0,     0,     0,     0,   657,   491,     0,
       0,     0,   661,   662,   663,     0,   665,     0,   747,     0,
     668,   669,   670,     0,     0,   671,     0,     0,     0,     0,
       0,     0,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   747,     0,     0,     0,   382,   383,   384,   385,     0,
       0,  1733,     0,   386,   387,   388,     0,     0,   389,     0,
     390,     0,     0,   703,     0,     0,     0,   491,   712,     0,
       0,     0,     0,   391,     0,     0,   392,     0,     0,     0,
       0,     0,     0,     0,   720,   721,     0,     0,     0,     0,
       0,     0,     0,   436,     0,     0,     0,     0,     0,   748,
       0,  1340,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   436,   436,     0,   774,   775,   776,
     777,     0,     0,     0,     0,   782,     0,     0,   436,   786,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   800,   550,     0,     0,     0,   804,     0,
       0,     0,   808,   809,   810,   811,   812,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   822,   823,   824,   826,
     827,   828,   829,   830,   831,   832,   832,     0,   837,   838,
       0,   840,     0,     0,   393,   394,   395,     0,   847,  1392,
    1393,   851,   852,     0,     0,   396,     0,     0,   832,   397,
       0,   398,   114,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1711,     0,   868,   869,   870,   871,   872,
     873,   874,   875,   876,   877,   878,   879,   880,   881,   883,
     885,   886,   887,   888,   889,     0,   891,   892,     0,     0,
       0,     0,     0,  1717,   900,   901,   902,     0,     0,     0,
       0,     0,   908,   909,     0,   491,   491,     0,     0,     0,
     492,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   548,   703,   928,     0,     0,     0,
     933,   934,   935,   936,   937,   938,   939,   940,   941,     0,
       0,     0,     0,     0,   948,     0,   950,     0,     0,   952,
       0,  1827,     0,   491,   491,   491,   957,     0,   959,   960,
     961,  1489,     0,     0,     0,  1491,     0,     0,     0,     0,
       0,     0,     0,     0,  1495,     0,  1496,     0,     0,  1498,
       0,   551,     0,     0,   492,   984,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   491,
     492,   492,     0,     0,     0,     0,  1003,     0,  1004,     0,
       0,   891,   892,     0,     0,     0,     0,     0,     0,     0,
    1017,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1538,     0,   491,     0,  1033,     0,     0,     0,     0,
    1036,  1037,     0,     0,     0,   492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,     0,  1053,  1054,     0,
       0,   491,  1059,     0,     0,     0,  1053,     0,     0,     0,
     492,     0,     0,  1070,     0,     0,     0,  1073,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,  1097,     0,   883,     0,  1100,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,   492,
     580,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,   491,     0,   580,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   491,
       0,     0,     0,     0,     0,     0,   551,  1181,     0,     0,
       0,  1187,     0,     0,     0,     0,     0,   491,     0,     0,
       0,     0,     0,     0,     0,  1200,  1201,     0,     0,     0,
     825,  1204,     0,     0,     0,     0,     0,   833,   834,   402,
     372,     0,     0,     0,     0,     0,     0,     0,  1230,     0,
       0,  1232,  1747,     0,     0,   588,   589,     0,     0,     0,
     857,     0,     0,     0,     0,   492,     0,  1912,     0,     0,
       0,     0,  1248,     0,  1250,  1251,     0,     0,     0,     0,
       0,   373,   374,   375,   376,   377,   378,   379,   380,   381,
       0,   884,     0,  1269,   382,   383,   384,   385,     0,     0,
     635,     0,   386,   387,   388,     0,  1938,   389,     0,   390,
       0,     0,     0,     0,     0,     0,  1291,   492,   492,     0,
       0,     0,   391,  1297,     0,   392,     0,     0,  1306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1332,  1333,     0,     0,     0,     0,   491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   492,   492,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1357,  1358,
    1359,  1360,     0,     0,   711,     0,     0,     0,     0,  1838,
       0,     0,  1840,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   491,     0,     0,     0,     0,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,  1383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1384,
    1385,  1386,     0,   393,   394,   395,  1388,  1389,     0,  1390,
       0,     0,     0,     0,   396,   492,     0,     0,   397,     0,
     398,  1397,  1398,  1950,     0,     0,     0,     0,     0,  1401,
    1402,     0,     0,     0,     0,     0,  1406,   492,  1407,  1408,
       0,     0,     0,   492,     0,  1414,  1415,     0,     0,     0,
     491,   491,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,     0,     0,
       0,     0,  1443,     0,     0,     0,     0,   884,     0,  1101,
     861,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,  1475,     0,     0,
       0,     0,   492,     0,     0,     0,     0,     0,     0,   491,
       0,     0,   492,     0,     0,     0,     0,  1490,     0,     0,
       0,     0,   911,   912,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1414,  1415,
       0,     0,     0,  1506,     0,     0,     0,     0,   492,     0,
       0,     0,     0,     0,  1512,     0,     0,  1517,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
     954,   955,   956,     0,     0,     0,     0,     0,     0,   492,
       0,     0,     0,     0,     0,  1539,     0,     0,  1542,   491,
    1545,   491,     0,     0,     0,     0,     0,     0,     0,  1554,
       0,  1556,     0,  1554,  1560,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   998,     0,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1029,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,  1051,   580,     0,   727,     0,   728,  1058,     0,
       0,     0,  1637,  1689,     0,     0,     0,     0,     0,  1644,
    1645,  1646,     0,     0,     0,     0,     0,     0,  1652,     0,
    1654,     0,     0,     0,     0,     0,   372,  1657,     0,     0,
       0,   492,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,     0,     0,     0,     0,  1674,     0,     0,     0,
       0,     0,     0,     0,  1679,  1680,  1681,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1692,   373,   374,   375,
     376,   377,   378,   379,   380,   381,  1704,  1131,     0,     0,
     382,   383,   384,   385,     0,   492,     0,  1141,   386,   387,
     388,     0,     0,   389,     0,   390,     0,     0,     0,  1721,
       0,     0,     0,     0,     0,  1730,  1731,     0,   391,     0,
       0,   392,  2153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1166,     0,     0,  2063,     0,     0,     0,
       0,     0,     0,  2169,  2171,     0,  1174,     0,  1758,     0,
       0,     0,     0,     0,     0,     0,     0,  2179,     0,     0,
       0,     0,     0,     0,  1193,     0,     0,     0,     0,     0,
       0,     0,   492,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1776,  1777,
    1778,     0,     0,     0,     0,     0,     0,     0,     0,  1779,
       0,     0,     0,     0,  1782,  1783,  1784,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1792,     0,
       0,     0,     0,   491,   491,  1798,     0,  1799,     0,   393,
     394,   395,     0,  1807,  1808,     0,     0,     0,     0,     0,
     396,     0,     0,     0,   397,     0,   398,     0,     0,     0,
       0,   492,   491,     0,     0,     0,     0,  1826,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1836,     0,     0,  1839,     0,     0,     0,  1841,     0,     0,
       0,     0,     0,     0,     0,     0,  1783,  1784,     0,  1850,
       0,     0,     0,     0,     0,   730,  1339,  1855,     0,     0,
       0,     0,     0,     0,  2111,     0,     0,     0,     0,     0,
       0,     0,     0,  1868,     0,     0,     0,     0,  1874,  1875,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   492,  1880,   492,     0,  1881,  1880,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1889,   561,     0,
    1382,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,   491,   491,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1915,     0,
       0,     0,     0,     0,     0,   848,     0,  1924,     0,     0,
       0,     0,     0,     0,     0,     0,   550,     0,     0,     0,
       0,     0,     0,     0,     0,  1935,  1936,     0,     0,   491,
       0,     0,     0,     0,     0,     0,     0,  1419,  1420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   896,     0,     0,     0,
       0,     0,     0,  1960,  1961,     0,     0,     0,     0,     0,
       0,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,  1973,     0,     0,   491,   491,  1978,     0,     0,
       0,     0,  1981,     0,     0,  1983,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1488,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,  2010,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,  2021,     0,     0,     0,     0,     0,  2026,
       0,     0,  2027,     0,     0,     0,     0,     0,     0,     0,
    1759,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   801,   576,   577,   578,   579,     0,
       0,  2051,     0,   580,   561,     0,  1544,     0,  1546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2069,  2070,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2076,  2077,     0,  2078,   491,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   492,   492,  2087,     0,     0,
       0,     0,   491,   491,   491,   491,   491,     0,     0,     0,
       0,     0,  1874,     0,     0,     0,  2103,     0,     0,     7,
       8,     0,     0,     0,   492,     0,     0,     0,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,     0,
    1116,  1117,  1118,  1119,  2124,  1121,  1122,  1123,  1124,  2127,
    2128,  2129,     0,     0,     0,     0,     0,     0,     0,  1134,
       0,  1136,     0,   491,     0,     0,     0,     0,     0,  1143,
       0,     0,     0,     0,     0,     0,  1149,  1150,  1672,     0,
       0,     0,     0,     0,     0,  1161,     0,     0,     0,     0,
       0,  2157,  2158,  2159,     0,     0,     0,     0,     0,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,     0,     0,    41,    42,    43,    44,
       0,   165,    46,   170,     0,     0,     0,     0,     0,   741,
      53,     0,     0,    56,   742,     0,   743,   744,     0,   745,
       0,     0,     0,   492,   492,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,     0,     0,     0,   551,   580,
      91,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,   492,     0,     0,     0,  1254,  1256,  1257,     0,     0,
       0,  1261,  1262,     0,     0,  1265,  1266,  1267,  1268,     0,
    1270,     0,     0,     0,     0,  1276,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2031,     0,     0,     0,   435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   492,   492,     0,
    1796,  1797,     0,     0,     0,   929,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1356,     0,     0,     0,     0,  1361,     0,
       0,     0,     0,     0,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   523,   524,   525,
     526,   527,   528,     0,   530,   531,     0,     0,     0,     0,
       0,   534,   535,     0,     0,     0,     0,     0,   202,   160,
       0,     0,     0,   543,   544,   203,   204,   205,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   408,   224,   225,
     226,   227,   228,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1416,     0,     0,   492,     0,  1904,  1905,
     235,   236,   237,   238,     0,     0,     0,     0,   239,     0,
       0,     0,     0,     0,   492,   492,   492,   492,   492,     0,
     241,   242,   243,     0,     0,     0,     0,     0,     0,     0,
     244,    23,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1937,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,   561,     0,     0,     0,   580,
     672,   673,   674,     0,     0,   492,   678,   679,   680,   681,
     682,   683,   684,     0,   685,     0,     0,     0,   686,   687,
       0,     0,   690,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1976,  1977,     0,   702,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1994,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1526,     0,     0,     0,     0,  2004,     0,     0,
       0,     0,   255,     0,     0,     0,   256,     0,     0,     0,
       0,   258,   259,   260,     0,   261,   262,   263,     0,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1562,     0,     0,     0,     0,     0,   264,   409,     0,
       0,     0,     0,     0,   266,     0,     0,     0,     0,   353,
       0,     0,     0,   602,     0,     0,   269,     0,     0,     0,
       0,     0,     0,  1599,  1600,  1601,  1602,  1603,     0,     0,
       0,     0,  1608,  1609,     0,     0,  1611,     0,  1613,     0,
       0,     0,  1617,     0,     0,  1619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1627,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2079,     0,     0,   865,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2091,
    2092,  2093,  2094,  2096,     0,     0,     0,     0,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   801,   576,   577,   578,   579,     0,     0,   971,     0,
     580,     0,     0,     0,     0,     0,     0,     0,  1687,     0,
    1690,     0,     0,     0,  1697,     0,  1699,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1724,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     6,   372,
       0,     0,     0,     0,   203,   204,   205,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,  1164,     0,
    1563,   374,   375,   376,   377,   378,   379,   380,   381,   235,
     236,   237,   238,   382,   383,   384,   385,   239,   240,     0,
       0,   386,   387,   388,     0,     0,   389,  1165,   390,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,   244,
      23,   391,   245,  1785,   392,     0,     0,     0,   246,     0,
       0,   247,     0,     0,   248,     0,   249,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,    54,
      55,     0,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,    71,    72,
      73,    74,    75,    76,     0,     0,     0,    80,     0,     0,
      83,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1865,     0,     0,  1866,     0,
       0,   255,   393,   394,   395,   256,   257,  1156,     0,     0,
     258,   259,   260,   396,   261,   262,   263,   397,     0,   398,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   265,     0,     0,
       0,  1173,     0,   266,     0,     0,  1896,  1897,   353,  1899,
       0,     0,  1564,     0,     0,   269,  1481,     0,     0,     0,
       0,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,  1941,
    1942,     0,   580,     0,   202,     6,   372,     0,     0,     0,
       0,   203,   204,   205,     0,     0,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     0,  1972,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   235,   236,   237,   238,
     382,   383,   384,   385,   239,   240,     0,     0,   386,   387,
     388,     0,     0,   389,     0,   390,   241,   242,   243,     0,
       0,     0,     0,     0,     0,     0,   244,    23,   391,   245,
       0,   392,     0,     0,     0,   246,     0,     0,   247,     0,
       0,   248,     0,   249,  1351,     0,     0,     0,     0,     0,
      40,     0,     0,     0,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   251,     0,    54,    55,     0,   252,
       0,   253,     0,     0,   254,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,    71,    72,    73,    74,    75,
      76,     0,     0,     0,    80,     0,     0,    83,     0,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1405,   255,   393,
     394,   395,   256,   257,     0,     0,     0,   258,   259,   260,
     396,   261,   262,   263,   397,     0,   398,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   265,     0,     0,     0,     0,     0,
     266,     0,     0,     0,     0,   353,   202,   160,   372,   268,
     421,     0,   269,   203,   204,   205,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   408,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,     0,  2146,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   235,   236,
     237,   238,   382,   383,   384,   385,   239,     0,     7,     8,
     386,   387,   388,     0,     0,   389,     0,   390,   241,   242,
     243,     0,     0,     0,     0,     0,     0,     0,   244,    23,
     391,   245,     0,   392,     0,     0,     0,   292,     0,     0,
     293,     0,     0,   294,     0,   295,     0,     0,     0,     0,
    1527,  1528,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,     0,     0,    41,    42,    43,    44,     0,
       0,    46,     0,     0,     0,     0,     0,     0,   741,    53,
       0,     0,    56,   742,     0,   743,   744,     0,   745,     0,
       0,     0,     0,   423,     0,     0,     0,  1615,     0,     0,
     255,   393,   394,   395,   256,    77,     0,  1623,     0,   258,
     259,   260,   396,   261,   262,   263,   397,     0,   398,   114,
     424,   425,   426,   427,     0,     0,     0,     0,     0,    91,
      92,    93,     0,     0,     0,   264,   409,     0,     0,     0,
       0,     0,   266,   428,   429,     0,     0,   430,     0,   431,
       0,     0,     0,   432,   269,   202,     6,   352,     0,     0,
       0,     0,   203,   204,   205,     0,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,   953,     0,     0,   235,   236,   237,
     238,     0,     0,     0,     0,   239,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,   244,    23,     0,
     245,     0,     0,     0,     0,     0,   246,     0,     0,   247,
       0,     0,   248,     0,   249,     0,     0,     0,     0,     0,
    1756,    40,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   251,     0,    54,    55,     0,
     252,     0,   253,     0,     0,   254,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,    71,    72,    73,    74,
      75,    76,     0,     0,     0,    80,     0,     0,    83,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,   962,     0,     0,     0,     0,     0,     0,
       0,   921,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,   256,   257,     0,     0,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   265,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   353,   202,     6,     0,
     354,     0,   658,   269,   203,   204,   205,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     236,   237,   238,     0,     0,     0,     0,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,   244,
      23,     0,   245,     0,     0,     0,     0,     0,   246,     0,
       0,   247,     0,     0,   248,     0,   249,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,    54,
      55,     0,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,    71,    72,
      73,    74,    75,    76,     0,     0,     0,    80,     0,     0,
      83,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,  1803,
       0,     0,     0,  1804,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,   256,   257,     0,     0,     0,
     258,   259,   260,     0,   261,   262,   263,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   490,     0,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   353,   202,
       6,  1660,     0,   554,     0,   269,   203,   204,   205,     0,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   236,   237,   238,     0,     0,     0,     0,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,   244,    23,     0,   245,     0,     0,     0,     0,     0,
     246,     0,     0,   247,     0,     0,   248,     0,   249,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   251,
       0,    54,    55,     0,   252,     0,   253,     0,     0,   254,
       0,     0,     0,     0,    65,    66,    67,    68,    69,     0,
      71,    72,    73,    74,    75,    76,     0,     0,     0,    80,
       0,     0,    83,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,     0,
       0,  1830,     0,     0,     0,  1831,     0,     0,     0,     0,
       0,     0,     0,   255,     0,     0,     0,   256,   257,     0,
       0,     0,   258,   259,   260,     0,   261,   262,   263,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
     353,   202,     6,     0,   268,     0,     0,   269,   203,   204,
     205,     0,     0,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,   236,   237,   238,     0,     0,     0,
       0,   239,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,   244,    23,     0,   245,     0,     0,     0,
       0,     0,   246,     0,     0,   247,     0,     0,   248,     0,
     249,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   251,     0,    54,    55,     0,   252,     0,   253,     0,
       0,   254,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,    71,    72,    73,    74,    75,    76,     0,     0,
       0,    80,     0,     0,    83,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,     0,     0,  1996,     0,     0,     0,  1997,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,   256,
     257,     0,     0,     0,   258,   259,   260,     0,   261,   262,
     263,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     620,  1822,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   622,   202,     6,     0,   314,   554,     0,   269,
     203,   204,   205,     0,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   236,   237,   238,     0,
       0,     0,     0,   239,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,   244,    23,     0,   245,     0,
       0,     0,     0,     0,   246,     0,     0,   247,     0,     0,
     248,     0,   249,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,    54,    55,     0,   252,     0,
     253,     0,     0,   254,     0,     0,     0,     0,    65,    66,
      67,    68,    69,     0,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    80,     0,     0,    83,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   758,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   256,   257,     0,     0,     0,   258,   259,   260,     0,
     261,   262,   263,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   267,   202,     6,     0,   268,     0,
       0,   269,   203,   204,   205,     0,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   237,
     238,     0,     0,     0,     0,   239,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,   244,    23,     0,
     245,     0,     0,     0,     0,     0,   246,     0,     0,   247,
       0,     0,   248,     0,   249,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   251,     0,    54,    55,     0,
     252,     0,   253,     0,     0,   254,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,    71,    72,    73,    74,
      75,    76,     0,     0,     0,    80,     0,     0,    83,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   921,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,   256,   257,     0,     0,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   265,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   353,   202,     6,     0,
     268,     0,     0,   269,   203,   204,   205,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     236,   237,   238,     0,     0,     0,     0,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,   244,
      23,     0,   245,     0,     0,     0,     0,     0,   246,     0,
       0,   247,     0,     0,   248,     0,   249,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,    54,
      55,     0,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,    71,    72,
      73,    74,    75,    76,     0,     0,     0,    80,     0,     0,
      83,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   922,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,   256,   257,     0,     0,     0,
     258,   259,   260,     0,   261,   262,   263,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   490,     0,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   353,   202,
       6,     0,   549,     0,     0,   269,   203,   204,   205,     0,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   236,   237,   238,     0,     0,     0,     0,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,   244,    23,     0,   245,     0,     0,     0,     0,     0,
     246,     0,     0,   247,     0,     0,   248,     0,   249,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   251,
       0,    54,    55,     0,   252,     0,   253,     0,     0,   254,
       0,     0,     0,     0,    65,    66,    67,    68,    69,     0,
      71,    72,    73,    74,    75,    76,     0,     0,     0,    80,
       0,     0,    83,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   968,     0,     0,     0,     0,
       0,     0,     0,   255,     0,     0,     0,   256,   257,     0,
       0,     0,   258,   259,   260,     0,   261,   262,   263,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   490,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
     353,   202,     6,     0,     0,   554,     0,   269,   203,   204,
     205,     0,     0,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,   236,   237,   238,     0,     0,     0,
       0,   239,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,   244,    23,     0,   245,     0,     0,     0,
       0,     0,   246,     0,     0,   247,     0,     0,   248,     0,
     249,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   251,     0,    54,    55,     0,   252,     0,   253,     0,
       0,   254,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,    71,    72,    73,    74,    75,    76,     0,     0,
       0,    80,     0,     0,    83,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1074,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,   256,
     257,     0,     0,     0,   258,   259,   260,     0,   261,   262,
     263,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   592,   202,     6,     0,   268,     0,     0,   269,
     203,   204,   205,     0,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   236,   237,   238,     0,
       0,     0,     0,   239,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,   244,    23,     0,   245,     0,
       0,     0,     0,     0,   246,     0,     0,   247,     0,     0,
     248,     0,   249,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,    54,    55,     0,   252,     0,
     253,     0,     0,   254,     0,     0,     0,     0,    65,    66,
      67,    68,    69,     0,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    80,     0,     0,    83,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1075,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   256,   257,     0,     0,     0,   258,   259,   260,     0,
     261,   262,   263,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   599,   202,     6,     0,   268,     0,
       0,   269,   203,   204,   205,     0,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   237,
     238,     0,     0,     0,     0,   239,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,   244,    23,     0,
     245,     0,     0,     0,     0,     0,   246,     0,     0,   247,
       0,     0,   248,     0,   249,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   251,     0,    54,    55,     0,
     252,     0,   253,     0,     0,   254,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,    71,    72,    73,    74,
      75,    76,     0,     0,     0,    80,     0,     0,    83,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1076,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,   256,   257,     0,     0,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   490,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   353,   202,     6,     0,
     882,     0,  1338,   269,   203,   204,   205,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     236,   237,   238,     0,     0,     0,     0,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,   244,
      23,     0,   245,     0,     0,     0,     0,     0,   246,     0,
       0,   247,     0,     0,   248,     0,   249,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,    54,
      55,     0,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,    71,    72,
      73,    74,    75,    76,     0,     0,     0,    80,     0,     0,
      83,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1077,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,   256,   257,     0,     0,     0,
     258,   259,   260,     0,   261,   262,   263,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   490,     0,     0,
       0,     0,     0,   266,   202,     6,     0,     0,   353,  1543,
       0,   203,   204,   205,     0,   269,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   237,   238,
       0,     0,     0,     0,   239,   240,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,   242,   243,     0,
       0,     0,     0,     0,     0,     0,   244,    23,     0,   245,
       0,     0,     0,     0,     0,   246,     0,     0,   247,     0,
       0,   248,     0,   249,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   251,     0,    54,    55,     0,   252,
       0,   253,     0,     0,   254,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,    71,    72,    73,    74,    75,
      76,     0,     0,     0,    80,     0,     0,    83,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1115,     0,     0,     0,     0,     0,     0,     0,   255,     0,
       0,     0,   256,   257,     0,     0,     0,   258,   259,   260,
       0,   261,   262,   263,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   490,     0,     0,     0,     0,     0,
     266,   202,     6,     0,     0,   353,     0,     0,   203,   204,
     205,     0,   269,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,   236,   237,   238,     0,     0,     0,
       0,   239,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,   244,    23,     0,   245,     0,     0,     0,
       0,     0,   246,     0,     0,   247,     0,     0,   248,     0,
     249,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   251,     0,    54,    55,     0,   252,     0,   253,     0,
       0,   254,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,    71,    72,    73,    74,    75,    76,     0,     0,
       0,    80,     0,     0,    83,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1125,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,   256,
     257,     0,     0,     0,   258,   259,   260,     0,   261,   262,
     263,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   353,   202,     6,     0,  1668,     0,     0,   269,
     203,   204,   205,     0,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   236,   237,   238,     0,
       0,     0,     0,   239,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,   244,    23,     0,   245,     0,
       0,     0,     0,     0,   246,     0,     0,   247,     0,     0,
     248,     0,   249,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,    54,    55,     0,   252,     0,
     253,     0,     0,   254,     0,     0,     0,     0,    65,    66,
      67,    68,    69,     0,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    80,     0,     0,    83,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1126,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   256,   257,     0,     0,     0,   258,   259,   260,     0,
     261,   262,   263,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   620,  1822,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   622,   202,     6,     0,   314,     0,
       0,   269,   203,   204,   205,     0,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   237,
     238,     0,     0,     0,     0,   239,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,   244,    23,     0,
     245,     0,     0,     0,     0,     0,   246,     0,     0,   247,
       0,     0,   248,     0,   249,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   251,     0,    54,    55,     0,
     252,     0,   253,     0,     0,   254,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,    71,    72,    73,    74,
      75,    76,     0,     0,     0,    80,     0,     0,    83,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1127,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,   256,   257,     0,     0,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   490,     0,     0,     0,     0,
       0,   266,   202,   160,   372,     0,   353,     0,     0,   203,
     204,   205,     0,   269,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   408,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,     0,     0,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   235,   236,   237,   238,   382,   383,
     384,   385,   239,     0,     0,     0,   386,   387,   388,     0,
       0,   389,     0,   390,   241,   242,   243,     0,     0,     0,
       0,     0,     0,     0,   244,    23,   391,   245,     0,   392,
     202,   160,   372,     0,     0,     0,     0,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   408,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   235,   236,   237,   238,   382,   383,   384,   385,
     239,     0,     0,     0,   386,   387,   388,     0,     0,   389,
       0,   390,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,   244,    23,   391,   245,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   393,   394,   395,
     256,     0,     0,     0,     0,   258,   259,   260,   396,   261,
     262,   263,   397,     0,   398,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   409,     0,     0,     0,     0,     0,   266,     0,
       0,     0,     0,   353,     0,     0,     0,  1559,     0,     0,
     269,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1132,   255,   393,   394,   395,   256,     0,
       0,     0,     0,   258,   259,   260,   396,   261,   262,   263,
     397,     0,   398,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     409,     0,     0,     0,     0,     0,   266,     0,     0,     0,
       0,   353,   202,   160,   372,  1835,     0,     0,   269,   203,
     204,   205,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   408,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,     0,     0,  1563,   374,   375,   376,   377,
     378,   379,   380,   381,   235,   236,   237,   238,   382,   383,
     384,   385,   239,     0,     0,     0,   386,   387,   388,     0,
       0,   389,     0,   390,   241,   242,   243,     0,     0,     0,
       0,     0,     0,     0,   244,    23,   391,   245,     0,   392,
     202,   160,   372,     0,     0,     0,     0,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   408,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   235,   236,   237,   238,   382,   383,   384,   385,
     239,     0,     0,     0,   386,   387,   388,     0,     0,   389,
       0,   390,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,   244,    23,   391,   245,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   393,   394,   395,
     256,     0,     0,     0,     0,   258,   259,   260,   396,   261,
     262,   263,   397,     0,   398,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   409,     0,     0,     0,     0,     0,   266,     0,
       0,     0,     0,   353,     0,     0,     0,  1723,     0,     0,
     269,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1133,   255,   393,   394,   395,   256,     0,
       0,     0,     0,   258,   259,   260,   396,   261,   262,   263,
     397,     0,   398,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     409,     0,     0,     0,     0,     0,   266,   202,   160,     0,
       0,   353,     0,     0,   203,   204,   205,     0,   269,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   408,   224,   225,   226,
     227,   228,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     236,   237,   238,     0,     0,     0,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,     0,     0,     0,     0,   202,   160,     0,   244,
      23,   850,   245,   203,   204,   205,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   408,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   242,
     243,     0,     0,     0,     0,     0,     0,     0,   244,    23,
       0,   245,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,     0,     0,
       0,   255,     0,     0,  1135,   256,     0,     0,     0,     0,
     258,   259,   260,     0,   261,   262,   263,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   620,   621,     0,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   622,     0,
       0,     0,   314,     0,     0,   269,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     255,     0,     0,     0,   256,     0,     0,     0,  1243,   258,
     259,   260,     0,   261,   262,   263,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,   409,     0,     0,     0,
       0,     0,   266,   202,   160,     0,     0,   353,     0,     0,
     203,   204,   205,     0,   269,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   408,   224,   225,   226,   227,   228,   229,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   236,   237,   238,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,   244,    23,     0,   245,   202,
     160,     0,  1290,     0,     0,     0,   203,   204,   205,     0,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   408,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,   235,   236,   237,   238,     0,     0,     0,     0,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,   244,    23,     0,   245,     0,     0,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,   255,     0,   580,
       0,   256,     0,     0,     0,     0,   258,   259,   260,  1264,
     261,   262,   263,     0,     0,     0,   114,     0,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   264,   409,     0,    41,    42,    43,    44,   266,
       0,    46,     0,     0,   353,  1064,     0,     0,   741,    53,
       0,   269,    56,   742,     0,   743,   744,     0,   745,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,   255,     0,     0,     0,   256,     0,     0,
       0,     0,   258,   259,   260,     0,   261,   262,   263,    91,
      92,    93,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   409,
       0,     0,     0,     0,     0,   266,   202,   160,     0,  1442,
     353,     0,     0,   203,   204,   205,     0,   269,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   408,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1000,     0,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   242,
     243,     0,     0,     0,     0,     0,     0,     0,   244,    23,
       0,   245,   202,   160,     0,  1505,     0,     0,     0,   203,
     204,   205,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   408,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,   235,   236,   237,   238,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   242,   243,     0,     0,     0,
       0,     0,     0,     0,   244,    23,     0,   245,     0,     0,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
     255,     0,   580,     0,   256,     0,     0,     0,     0,   258,
     259,   260,  1347,   261,   262,   263,     0,     0,     0,   114,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   264,   409,     0,    41,    42,
      43,    44,   266,     0,    46,     0,     0,   353,     0,     0,
       0,   741,    53,     0,   269,    56,   742,     0,   743,   744,
       0,   745,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,   255,     0,     0,     0,
     256,     0,     0,     0,     0,   258,   259,   260,     0,   261,
     262,   263,    91,    92,    93,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   409,     0,     0,     0,     0,     0,   266,   202,
     160,     0,     0,   353,     0,     0,   203,   204,   205,     0,
     269,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   408,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1002,     0,     0,
       0,   235,   236,   237,   238,     0,     0,     0,     0,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   242,   243,     0,     0,     0,     0,   202,   160,
       0,   244,    23,     0,   245,   203,   204,   205,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   408,   224,   225,
     226,   227,   228,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     235,   236,   237,   238,     7,     8,     0,     0,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,   242,   243,     0,     0,     0,     0,     0,     0,     0,
     244,    23,     0,   245,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   704,   576,   577,
     578,   579,     0,     0,     0,     0,   580,     0,     0,     0,
       0,     0,     0,   255,     0,     0,  1436,   256,     0,     0,
       0,     0,   258,   259,   260,     0,   261,   262,   263,     0,
       0,     0,   114,     0,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   264,   409,
       0,    41,    42,    43,    44,   266,     0,    46,     0,     0,
     353,  1558,     0,     0,   741,    53,     0,   269,    56,   742,
       0,   743,   744,     0,   745,     0,     0,     0,  1011,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,   255,     0,     0,  1012,   256,     0,     0,     0,
       0,   258,   259,   260,     0,   261,   262,   263,     0,     0,
       0,   114,     0,     0,     0,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   409,     0,
       0,     0,     0,     0,   266,   202,   160,     0,     0,   353,
    1882,     0,   203,   204,   205,     0,   269,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   408,   224,   225,   226,   227,   228,
     229,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   237,
     238,     0,     0,     0,     0,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,   244,    23,     0,
     245,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1437,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,     0,     0,
      41,    42,    43,    44,     0,     0,    46,     0,     0,     0,
       0,     0,     0,   741,    53,     0,     0,    56,   742,     0,
     743,   744,     0,   745,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,   256,    91,    92,    93,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,   264,   409,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   353,     0,     0,     0,
       0,     0,     0,   269,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,     0,     0,
      41,    42,    43,    44,     0,     0,    46,     0,     0,  1195,
       0,     0,     0,   741,    53,     0,     0,    56,   742,     0,
     743,   744,     0,   745,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,     0,     0,    41,    42,    43,
      44,     0,     0,    46,    91,    92,    93,     0,     0,     0,
     741,    53,     0,     0,    56,   742,     0,   743,   744,     0,
     745,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    91,    92,    93,    41,    42,    43,    44,     0,     0,
      46,     0,     0,     0,     0,     0,     0,   741,    53,  1197,
       0,    56,   742,     0,   743,   744,     0,   745,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,     0,
       0,    41,    42,    43,    44,     0,     0,    46,    91,    92,
      93,     0,     0,     0,   741,    53,  1198,     0,    56,   742,
       0,   743,   744,     0,   745,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    91,    92,    93,    41,    42,
      43,    44,     0,     0,    46,     0,     0,     0,     0,     0,
       0,   741,    53,  1217,     0,    56,   742,     0,   743,   744,
       0,   745,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,     0,     0,    41,    42,    43,    44,     0,
       0,    46,    91,    92,    93,     0,     0,     0,   741,    53,
    1235,     0,    56,   742,     0,   743,   744,     0,   745,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    91,
      92,    93,    41,    42,    43,    44,     0,     0,    46,     0,
       0,     0,     0,     0,     0,   741,    53,  1249,     0,    56,
     742,     0,   743,   744,     0,   745,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,    41,
      42,    43,    44,     0,     0,    46,    91,    92,    93,     0,
       0,     0,   741,    53,  1282,     0,    56,   742,     0,   743,
     744,     0,   745,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    91,    92,    93,    41,    42,    43,    44,
       0,     0,    46,     0,     0,     0,     0,     0,     0,   741,
      53,  1434,     0,    56,   742,     0,   743,   744,     0,   745,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,    77,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
      91,    92,    93,     0,    -4,    -4,     0,     0,  2054,  1480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,    -4,     0,     0,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,  2113,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       6,     0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,
       8,     0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,
       9,    10,     0,    -4,    -4,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,     0,    -4,     0,     0,     0,
      11,    12,    13,     0,     0,     0,    14,    15,     0,    16,
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
      91,    92,    93,   160,   372,    94,     0,    95,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,   110,
     111,   112,     0,     7,     8,     0,     0,     0,     0,     0,
     113,     0,   114,     0,     0,   373,   374,   375,   376,   377,
     378,   379,   380,   381,     0,     0,     0,     0,   382,   383,
     384,   385,     0,     0,     0,     0,   386,   387,   388,     0,
       0,   389,     0,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   391,     0,     0,   392,
       0,     0,     0,   292,     0,     0,   293,     0,     0,   294,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,     0,   422,
      41,    42,    43,    44,     0,     0,    46,     0,     0,     0,
       0,     0,     0,   741,    53,     0,     0,    56,   742,     0,
     743,   744,     0,   745,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,    91,    92,    93,   393,   394,   395,
       0,     0,     0,  1604,     0,     0,     0,     0,   396,     0,
       0,     0,   397,     0,   398,   114,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1605,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1606,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1620,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1751,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1869,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1870,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   704,   576,   577,
     578,   579,     0,     0,     0,     0,   580,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1898,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1901,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
       0,     0,   580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1968,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2022,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2023,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2037,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2039,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2072,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2100,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2105,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   704,   576,   577,
     578,   579,     0,     0,     0,     0,   580,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2106,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2107,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
       0,     0,   580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2147,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,     0,
       0,   798,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,     0,     0,
    1046,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,  1102,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
       0,     0,   580,     0,     0,     0,     0,     0,  1145,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,  1146,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,     0,     0,     0,  1189,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,  1220,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
       0,     0,     0,     0,  1240,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,     0,     0,  1296,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   704,   576,   577,
     578,   579,     0,     0,     0,     0,   580,     0,     0,     0,
       0,     0,  1316,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,     0,
       0,  1438,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,     0,     0,
    1511,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,  1801,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
       0,     0,   580,     0,     0,     0,     0,     0,  1812,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,  1849,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,     0,     0,     0,  1918,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,  1933,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
       0,     0,     0,     0,  1945,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,     0,     0,  2002,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   704,   576,   577,
     578,   579,     0,     0,     0,     0,   580,     0,     0,     0,
       0,     0,  2011,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,     0,
       0,  2012,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,     0,     0,
    2035,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,     0,  2086,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
       0,     0,   580,     0,     0,     0,     0,     0,  2126,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,     0,     0,  2145,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,     0,     0,     0,  2165,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,     0,     0,  2166,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
       0,     0,     0,     0,  2167,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,     0,   705,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,     0,
     913,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,     0,  1911,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,   727,     0,   728,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
       0,     0,   974,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,  1022,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
       0,     0,   580,     0,     0,     0,  1169,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,  1234,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   704,   576,   577,
     578,   579,     0,     0,     0,     0,   580,     0,     0,     0,
    1236,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,     0,     0,  1241,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   704,   576,   577,   578,   579,     0,     0,     0,     0,
     580,     0,     0,     0,  1242,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   704,   576,
     577,   578,   579,     0,     0,     0,     0,   580,     0,     0,
       0,  1330,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   704,   576,   577,   578,   579,
       0,     0,     0,     0,   580,     0,     0,     0,  1344,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   704,   576,   577,   578,   579,     0,     0,     0,
       0,   580,     0,     0,     0,  1540,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
       0,     0,  1626,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   704,   576,   577,   578,
     579,     0,     0,     0,     0,   580,     0,     0,     0,  1675,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   704,   576,   577,   578,   579,     0,     0,
       0,     0,   580,     0,     0,     0,  1861,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     704,   576,   577,   578,   579,     0,     0,     0,     0,   580,
       0,     0,     0,  1903,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   704,   576,   577,
     578,   579,     0,     0,     0,     0,   580,     0,     0,     0,
    1919,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   779,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     780,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   781,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     783,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   784,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     785,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   787,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     788,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   789,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     790,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   791,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     792,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   793,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     795,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   796,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     797,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   862,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     897,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   943,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     962,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   964,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     965,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   966,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
     972,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,   973,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1010,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1021,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1082,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1086,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1098,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1168,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1178,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1179,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1180,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1190,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1219,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1221,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1222,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1223,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1224,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1225,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1226,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1227,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1233,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1329,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1343,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1541,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1571,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1572,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1573,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1574,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1612,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1625,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1738,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1740,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1743,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1750,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1802,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1811,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1834,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1902,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    1966,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  1967,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580,     0,
    2099,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   704,   576,   577,   578,   579,     0,
       0,     0,     0,   580,     0,  2142,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   704,
     576,   577,   578,   579,     0,     0,     0,     0,   580
};

static const yytype_int16 yycheck[] =
{
       3,   307,   617,   618,  1214,  1400,     3,   319,  1662,   140,
     722,    60,  1218,  1706,     4,  1708,   709,     4,   730,   191,
      23,     5,     4,     4,   153,    23,   338,   199,     4,     4,
       4,    14,     5,     4,   105,     4,   107,     4,     4,     7,
       5,     5,     4,     6,     4,   738,     7,     6,     6,    52,
       6,  1693,  1883,     4,     4,   154,     4,     6,     6,   134,
     240,   241,   755,    94,     6,   100,     9,   100,   248,   140,
     763,   232,   233,   232,   233,   237,   238,     9,    81,     4,
     179,   243,   113,     7,     9,   244,    89,     0,   123,   248,
     123,    94,   253,   405,   165,   407,   195,   196,   134,   232,
     233,   100,   105,   415,     9,    86,   247,   182,   240,   241,
       6,     9,   253,     6,  1756,   151,   248,   289,   290,   291,
     253,  1775,     7,   159,   160,   161,     9,   232,   233,   165,
     166,   232,   233,     6,   244,   232,   233,   140,   134,     9,
     232,   233,   145,   146,   141,   248,    94,     6,   253,   252,
     153,     6,   253,   103,   104,   151,   253,   249,   244,   331,
     332,   333,   248,   159,   160,   161,   244,   170,   246,   165,
     166,   864,     7,   232,   233,   253,   348,    97,     7,     6,
     100,   244,   102,   186,     7,   232,   233,   245,   191,    66,
      67,   194,    69,   113,   253,   253,   199,   200,   201,  2030,
     169,   170,   171,   172,   167,   244,   253,   246,   167,   190,
       7,   232,   233,   249,     6,   232,   233,   179,   180,   179,
     180,   244,  1617,   194,   232,   233,   216,    94,     6,   216,
      97,   247,   253,   100,   216,   216,   253,   253,   232,   233,
      97,   216,   216,   100,  1454,   253,   113,     6,   251,   217,
     218,   219,   220,   249,  1908,   244,   113,   246,   245,   253,
     247,   251,   265,   248,   248,   268,   269,   248,   240,   241,
     246,   269,   248,   248,   248,   248,   252,   244,   244,     6,
     249,   284,   285,   248,   248,   288,   289,   290,   291,   250,
     248,   216,   248,   244,   606,   244,   608,   609,   301,   248,
       6,   244,   305,   246,   307,   138,   139,   250,  1962,  1021,
    1022,   144,   244,   625,   246,   240,   241,     4,   250,   244,
     244,   246,   246,   248,    97,   250,   329,   100,   331,   332,
     333,   643,   217,   218,   219,   220,   232,   233,     8,   244,
     244,   246,   240,   241,   248,   348,   244,     6,   246,   247,
     421,   354,   250,   244,   666,   240,   241,   240,   241,   232,
     233,   244,   244,   246,   246,   250,   248,   250,   540,   228,
     240,   241,   231,  2066,   244,   249,   246,   232,   233,   253,
     250,     6,   217,   218,   219,   220,   232,   233,   217,   218,
     219,   220,     4,   705,   217,   218,   219,   220,   232,   233,
     245,   228,   247,   532,   231,   240,   241,   253,   253,   412,
     413,   240,   241,   250,   417,   418,   253,   240,   241,   253,
     217,   218,   219,   220,   246,   232,   233,   245,   232,   233,
     433,   232,   233,   310,   311,   253,   250,   440,   252,   232,
     233,   318,   319,   232,   233,   134,   253,   248,  2102,   253,
     246,   138,   139,   140,   141,   240,   241,   144,   461,  1152,
     253,  1154,   151,   244,   253,   250,   153,   232,   233,   156,
     159,   160,   161,   244,  1167,   546,   165,   166,   232,   233,
     244,   134,    94,   245,   232,   233,    98,   490,   253,   232,
     233,   253,   104,   105,    94,   107,   108,    97,   151,   253,
     100,  2155,   102,   244,  1899,   253,   159,   160,   161,   244,
     253,   514,   165,   166,    94,   127,   245,    97,   521,   522,
     100,   244,   102,   526,   253,   528,   529,   530,   531,   532,
       6,     7,   535,   113,   232,   233,   539,   540,   541,   542,
     543,   544,   545,   245,   547,   674,   549,   545,   250,   547,
     248,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   232,
     233,   244,   575,   243,   232,   233,   232,   233,   581,   249,
     244,   244,   246,   249,  1277,   248,   250,   253,   115,   253,
    1283,   722,   248,   245,   244,   253,   249,   134,   601,   602,
     249,   253,     8,   244,   253,   917,   232,   233,   234,   235,
     236,   237,   238,  1228,   151,   249,   687,   243,   245,   253,
     617,   618,   159,   160,   161,   100,   253,   102,   165,   166,
     234,   235,   236,   237,   238,  1328,   245,    97,   247,   243,
     100,   244,   102,   246,   253,     8,   649,   650,   651,  1342,
     245,   245,   247,   247,   245,  1348,   247,   245,   253,   253,
     138,   139,   253,   249,   249,   253,   144,   253,   253,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   244,   682,
     683,   684,   685,   686,   134,   688,   689,   690,   691,   692,
     249,     6,   695,   691,   253,   744,   249,   244,    52,   246,
     253,   248,   244,   706,   249,     3,   249,   778,   253,   249,
     253,   244,   249,   253,   249,  1427,   719,   249,   253,   249,
     249,   253,   100,   253,   253,   249,   729,   249,   248,   253,
     249,   253,   735,   249,   253,   244,   249,   253,   615,   616,
     253,   249,   249,   620,   244,   253,   253,   249,   751,   752,
     102,   253,   249,   244,   757,   249,   253,   760,   761,   253,
     249,    59,   893,   766,   253,   768,   249,   244,   248,   246,
     253,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   244,
     249,   249,   249,   243,   253,   253,   253,   249,   801,   248,
     803,   253,  1514,   249,   249,   249,   249,   253,   253,   253,
     253,   245,   100,   247,  1526,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   836,   249,    97,   907,   243,   253,   245,
     249,   247,   140,   846,   253,   248,   200,   145,   146,  2055,
     249,   244,   249,   249,   253,   153,   253,   253,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   244,   249,  2088,   882,
     243,   253,   244,   249,   246,   249,   249,   253,   186,   253,
    1021,  1022,   895,   244,   249,   246,   249,   251,   253,   248,
     253,   904,   249,   201,   100,   249,   253,   249,  2114,   253,
     913,   253,   249,   249,   249,   249,   253,   253,   253,   253,
     249,   249,  2132,   249,   253,   253,   249,   253,     6,     7,
     253,   249,     4,     5,   288,   253,   245,   248,   247,   248,
      97,   245,   240,   247,   248,    97,     4,   301,     6,   232,
     233,   305,  1023,   100,     4,   253,   254,     4,     4,     4,
     244,   246,   244,   244,   244,   244,     6,     6,   244,   246,
     248,     6,     6,   248,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   252,   252,   244,     9,    59,    60,    61,
      62,   244,   244,   244,   244,    67,    68,    69,   244,   244,
      72,   244,    74,  1309,   248,   244,   244,   182,   182,   182,
     123,   248,   244,  1016,   244,    87,   244,   244,    90,   182,
     244,   244,    94,   248,  1027,    97,   248,   248,   100,  1032,
     102,     4,  1647,  1648,   248,   248,   248,  1168,  1169,   244,
     244,   113,  1045,   920,   244,   244,   244,  1050,     6,   244,
     927,   244,   244,     6,   931,   246,     6,     6,   130,   248,
     248,   248,   248,   417,   418,   246,   246,   246,     6,   246,
     248,   182,   244,   244,   244,   244,   244,  1080,  1081,   433,
    1083,  1084,  1085,   244,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     8,     6,  1099,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,   412,   248,     6,   243,     6,     8,
     248,     8,     7,     6,   422,   248,   198,   199,   200,   248,
       6,   248,    89,   249,  1137,  1138,  1139,   209,   253,   253,
     245,   213,     7,   215,   216,     6,   444,     6,   245,   248,
     248,   243,    64,     8,   250,     4,  1159,     7,   244,     7,
       6,   245,     6,   248,     7,     6,   249,     7,   240,   241,
       6,     6,  1175,  1176,  1177,   529,   248,   179,   250,   248,
     245,   249,   249,   247,     6,   539,   248,   541,     7,   250,
       6,   246,  1504,   244,   248,     4,  1508,   245,  1329,  1330,
       6,     6,  1079,     6,     6,   246,     7,     7,     7,     7,
       7,     7,     7,     7,     7,  1521,     7,     7,     7,     7,
       7,     7,     7,   248,     6,   245,  1229,   253,   526,   247,
     528,  1228,   530,   531,   532,   249,   253,   253,   253,   245,
       7,  1244,  1245,  1246,   542,   543,   249,   248,     7,   248,
     250,   248,  1255,     4,     6,   250,   249,  1260,   249,   134,
     248,  1264,     7,     6,   250,     7,     7,     7,   245,   245,
    1273,   253,  1275,   253,     9,  1278,   245,   247,   253,  1350,
       6,  1352,   250,   182,     7,   252,   154,   249,   248,     6,
    1293,     6,     6,     4,   250,   250,    46,    46,   244,  1914,
     248,   244,   244,   248,   244,     4,  1309,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   623,   250,  1330,     7,   243,
       7,   245,  1335,     7,  1337,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   646,  1352,
     253,   182,   243,   245,     7,     7,     7,     6,   253,   245,
       7,     7,  1365,     7,     4,   719,  1369,     4,   112,   248,
       6,   244,     7,     6,   672,   673,   674,   675,   676,   677,
     678,   679,   680,  1514,   682,   683,   684,   685,     7,     7,
     688,   689,   690,     7,     7,     7,     7,     7,  1527,  1528,
     698,   248,     6,   701,     6,     6,   100,     7,     6,     6,
       4,     4,   251,   245,  1720,   713,   253,     6,  1421,  1422,
    1423,   248,   248,   253,   248,     6,  1429,     6,   249,  1500,
       7,     6,   246,     6,   244,   248,   244,     6,   249,     6,
       6,  1444,     6,   250,     6,   743,   127,   745,     6,   253,
       6,     6,  1455,     6,     6,   247,     6,     6,     6,     6,
    1463,     6,   760,     6,  1467,     6,     5,   245,   245,     6,
     768,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     4,     6,  1559,     4,
     243,   248,     6,  1624,   248,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     7,   248,   248,   248,   243,  1521,   246,
       6,     6,     6,   248,  1527,  1528,   248,   248,   248,   248,
    1533,   249,   248,     6,     6,   248,   178,     6,     6,     6,
       6,   253,   245,   253,   253,   253,   248,     6,  1551,   250,
     904,     7,   244,   248,     4,     6,  1559,     6,   249,     6,
       6,  1564,   244,     4,   244,     7,     6,     6,     6,     6,
       6,     6,  1643,     6,     6,    98,  1453,     6,     5,   248,
     245,   253,   248,     6,   248,     6,   253,     6,     6,     6,
       6,   253,   253,     6,  1723,   245,     4,     6,   253,     6,
     248,     6,     6,     6,     6,  1736,     7,   248,     5,   248,
     248,  1923,     6,   245,   248,  1686,     6,   248,   916,     6,
     918,   919,  1693,  1694,   248,     6,   249,     6,   249,     7,
       6,   248,     6,  1636,   932,   177,  1639,  1640,   245,     6,
     249,  1712,     7,   249,   249,  1951,     6,   250,     6,     6,
    1647,  1648,     6,   951,     6,     6,   248,     6,   249,  1662,
     245,     6,  1016,     6,   248,  1668,     6,   180,   248,     6,
     244,   969,     6,   249,   245,  1678,     6,   249,  1032,   249,
     248,   134,     6,   248,     6,  1688,     6,   248,  1691,   248,
       6,   248,     6,     6,   248,     6,     6,     6,   249,   245,
    1577,     6,     6,     6,  2016,   249,  1709,  1005,     6,     6,
     248,     6,   248,  1716,     6,   248,     6,  1720,     6,  1722,
    1723,     6,     6,     6,  1341,  2068,  1080,  1081,   458,  1083,
    1084,  1085,  1884,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1569,  2056,  1632,  1846,  1395,  1364,     3,
       3,     3,  1050,  1756,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,  1775,     3,  1910,  1497,   243,  1848,   596,     3,
    1716,  1693,  1528,  1137,  1787,  1788,  1663,  1664,  1665,  1666,
    1667,  1668,    -1,    -1,   760,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1159,    -1,  1810,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1889,  1822,
      -1,  1175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1835,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1138,  1139,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,  1872,
      -1,    -1,    -1,    -1,    -1,  1229,    -1,    -1,    -1,    -1,
      -1,    -1,  1885,    -1,    -1,    -1,    -1,  1890,  1891,  1892,
    1244,  1245,  1246,    -1,    -1,    -1,    -1,    -1,  1196,    -1,
      -1,    -1,    -1,    -1,    -1,  1908,    -1,    -1,  1911,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1914,    -1,  1922,
      -1,    -1,    -1,  1926,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1293,
      -1,   140,    -1,    -1,    -1,    -1,   145,   146,  1951,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1962,
    2031,    -1,  1260,    -1,    -1,    -1,  1264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1273,    -1,  1275,    -1,    -1,
    1278,    -1,    -1,    -1,    -1,    -1,  1989,   186,    -1,  1287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1352,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1365,    -1,    -1,    -1,  1369,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1330,    -1,    -1,    -1,    -1,  2040,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1927,  1928,  1929,  1930,  1931,  2058,  2059,  2060,  2061,  2062,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1421,  1422,  1423,
      -1,    -1,    -1,    -1,    -1,  1429,    -1,    -1,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2102,
      -1,  1455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1463,
      -1,  1988,    -1,    -1,    -1,  1992,  2119,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,  2141,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,  2155,     4,     5,    -1,    -1,     6,    -1,  2162,
    2163,    87,    -1,    -1,    90,  2042,    -1,    -1,    94,  2046,
      -1,    97,    -1,  2176,   100,    -1,   102,    -1,    -1,  1533,
      -1,    -1,    -1,    -1,    -1,  2062,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,   130,  1559,    -1,    -1,    59,    60,
      61,    62,     6,   412,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,  1527,
    1528,    -1,  2109,  2110,    -1,    -1,    87,    -1,    -1,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,
      -1,   102,    -1,  1551,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   199,   200,    -1,    -1,     6,    -1,   130,
      -1,    -1,  1636,   209,    -1,    -1,    -1,   213,    -1,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1662,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,   247,   248,    -1,  1678,    -1,    -1,   526,    -1,   528,
      -1,   530,   531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   542,   543,    -1,    -1,   198,   199,   200,
      -1,    -1,    -1,    -1,    -1,  1709,    -1,    -1,   209,    -1,
      -1,    -1,   213,    -1,   215,   216,    -1,    -1,  1722,    -1,
      -1,    -1,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
    1688,    -1,    -1,  1691,   243,     6,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1706,    -1,
    1708,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1775,     6,    -1,    -1,  1723,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,  1810,    -1,  1756,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   673,    -1,   675,   676,   677,   678,
     679,   680,    -1,   682,   683,   684,   685,    -1,    -1,   688,
     689,   690,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,   113,  1872,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1885,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,    -1,
      -1,    -1,   148,    -1,  1908,    -1,    -1,    -1,    -1,    -1,
      -1,   760,    -1,    -1,    -1,    -1,    -1,    -1,  1922,   768,
      -1,    -1,    -1,    -1,    -1,   171,   172,   173,    -1,   175,
     176,   177,    -1,   179,   180,   181,   182,   183,   184,   185,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1962,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,  1989,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,
     266,   267,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,   284,   285,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2001,    -1,    -1,    -1,   303,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,    -1,
      -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   329,   330,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,  2102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,   354,    -1,
      -1,    -1,   358,   359,   360,    -1,   362,    -1,  2066,    -1,
     366,   367,   368,    -1,    -1,   371,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,  2089,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,  2155,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    -1,    -1,   409,    -1,    -1,    -1,   413,   414,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   430,   431,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2141,    -1,    -1,    -1,    -1,    -1,   445,
      -1,  1050,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2162,  2163,    -1,   463,   464,   465,
     466,    -1,    -1,    -1,    -1,   471,    -1,    -1,  2176,   475,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   489,   490,    -1,    -1,    -1,   494,    -1,
      -1,    -1,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,    -1,   524,   525,
      -1,   527,    -1,    -1,   198,   199,   200,    -1,   534,  1138,
    1139,   537,   538,    -1,    -1,   209,    -1,    -1,   544,   213,
      -1,   215,   216,   549,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,    -1,   582,   583,    -1,    -1,
      -1,    -1,    -1,     6,   590,   591,   592,    -1,    -1,    -1,
      -1,    -1,   598,   599,    -1,   601,   602,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   620,   621,   622,    -1,    -1,    -1,
     626,   627,   628,   629,   630,   631,   632,   633,   634,    -1,
      -1,    -1,    -1,    -1,   640,    -1,   642,    -1,    -1,   645,
      -1,     6,    -1,   649,   650,   651,   652,    -1,   654,   655,
     656,  1260,    -1,    -1,    -1,  1264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1273,    -1,  1275,    -1,    -1,  1278,
      -1,   265,    -1,    -1,   268,   681,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   695,
     284,   285,    -1,    -1,    -1,    -1,   702,    -1,   704,    -1,
      -1,   707,   708,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1330,    -1,   729,    -1,   731,    -1,    -1,    -1,    -1,
     736,   737,    -1,    -1,    -1,   329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   751,    -1,   753,   754,    -1,
      -1,   757,   758,    -1,    -1,    -1,   762,    -1,    -1,    -1,
     354,    -1,    -1,   769,    -1,    -1,    -1,   773,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,   799,    -1,   801,    -1,   803,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,   413,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     836,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     846,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,   882,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   895,
      -1,    -1,    -1,    -1,    -1,    -1,   490,   903,    -1,    -1,
      -1,   907,    -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   921,   922,    -1,    -1,    -1,
     514,   927,    -1,    -1,    -1,    -1,    -1,   521,   522,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   944,    -1,
      -1,   947,  1551,    -1,    -1,   284,   285,    -1,    -1,    -1,
     544,    -1,    -1,    -1,    -1,   549,    -1,     6,    -1,    -1,
      -1,    -1,   968,    -1,   970,   971,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,   575,    -1,   989,    59,    60,    61,    62,    -1,    -1,
     329,    -1,    67,    68,    69,    -1,     6,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,  1012,   601,   602,    -1,
      -1,    -1,    87,  1019,    -1,    90,    -1,    -1,  1024,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1039,  1040,    -1,    -1,    -1,    -1,  1045,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   649,   650,   651,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1074,  1075,
    1076,  1077,    -1,    -1,   413,    -1,    -1,    -1,    -1,  1688,
      -1,    -1,  1691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1099,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1125,
    1126,  1127,    -1,   198,   199,   200,  1132,  1133,    -1,  1135,
      -1,    -1,    -1,    -1,   209,   729,    -1,    -1,   213,    -1,
     215,  1147,  1148,     6,    -1,    -1,    -1,    -1,    -1,  1155,
    1156,    -1,    -1,    -1,    -1,    -1,  1162,   751,  1164,  1165,
      -1,    -1,    -1,   757,    -1,  1171,  1172,    -1,    -1,    -1,
    1176,  1177,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1208,    -1,    -1,    -1,    -1,   801,    -1,   803,
     549,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,  1243,    -1,    -1,
      -1,    -1,   836,    -1,    -1,    -1,    -1,    -1,    -1,  1255,
      -1,    -1,   846,    -1,    -1,    -1,    -1,  1263,    -1,    -1,
      -1,    -1,   601,   602,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1284,  1285,
      -1,    -1,    -1,  1289,    -1,    -1,    -1,    -1,   882,    -1,
      -1,    -1,    -1,    -1,  1300,    -1,    -1,  1303,    -1,    -1,
      -1,   895,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     649,   650,   651,    -1,    -1,    -1,    -1,    -1,    -1,   913,
      -1,    -1,    -1,    -1,    -1,  1331,    -1,    -1,  1334,  1335,
    1336,  1337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1345,
      -1,  1347,    -1,  1349,  1350,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   695,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     729,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,   751,   243,    -1,   245,    -1,   247,   757,    -1,
      -1,    -1,  1428,   253,    -1,    -1,    -1,    -1,    -1,  1435,
    1436,  1437,    -1,    -1,    -1,    -1,    -1,    -1,  1444,    -1,
    1446,    -1,    -1,    -1,    -1,    -1,     5,  1453,    -1,    -1,
      -1,  1045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1467,    -1,    -1,    -1,    -1,  1472,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1480,  1481,  1482,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1492,    46,    47,    48,
      49,    50,    51,    52,    53,    54,  1502,   836,    -1,    -1,
      59,    60,    61,    62,    -1,  1099,    -1,   846,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,  1525,
      -1,    -1,    -1,    -1,    -1,  1531,  1532,    -1,    87,    -1,
      -1,    90,  2141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   882,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,  2162,  2163,    -1,   895,    -1,  1564,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2176,    -1,    -1,
      -1,    -1,    -1,    -1,   913,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1176,  1177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1604,  1605,
    1606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1615,
      -1,    -1,    -1,    -1,  1620,  1621,  1622,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1634,    -1,
      -1,    -1,    -1,  1639,  1640,  1641,    -1,  1643,    -1,   198,
     199,   200,    -1,  1649,  1650,    -1,    -1,    -1,    -1,    -1,
     209,    -1,    -1,    -1,   213,    -1,   215,    -1,    -1,    -1,
      -1,  1255,  1668,    -1,    -1,    -1,    -1,  1673,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1686,    -1,    -1,  1689,    -1,    -1,    -1,  1693,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1702,  1703,    -1,  1705,
      -1,    -1,    -1,    -1,    -1,   435,  1045,  1713,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1729,    -1,    -1,    -1,    -1,  1734,  1735,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1335,  1748,  1337,    -1,  1751,  1752,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,    -1,
    1099,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,  1787,  1788,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1804,    -1,
      -1,    -1,    -1,    -1,    -1,   535,    -1,  1813,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1822,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1831,  1832,    -1,    -1,  1835,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1176,  1177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,    -1,    -1,
      -1,    -1,    -1,  1869,  1870,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1467,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1888,    -1,    -1,  1891,  1892,  1893,    -1,    -1,
      -1,    -1,  1898,    -1,    -1,  1901,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1911,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1255,    -1,    -1,    -1,
    1926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1934,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,  1959,    -1,    -1,    -1,    -1,    -1,  1965,
      -1,    -1,  1968,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1564,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,  1997,    -1,   243,     8,    -1,  1335,    -1,  1337,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2022,  2023,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2036,  2037,    -1,  2039,  2040,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1639,  1640,  2053,    -1,    -1,
      -1,    -1,  2058,  2059,  2060,  2061,  2062,    -1,    -1,    -1,
      -1,    -1,  2068,    -1,    -1,    -1,  2072,    -1,    -1,    13,
      14,    -1,    -1,    -1,  1668,    -1,    -1,    -1,   808,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   818,    -1,
     820,   821,   822,   823,  2100,   825,   826,   827,   828,  2105,
    2106,  2107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   839,
      -1,   841,    -1,  2119,    -1,    -1,    -1,    -1,    -1,   849,
      -1,    -1,    -1,    -1,    -1,    -1,   856,   857,  1467,    -1,
      -1,    -1,    -1,    -1,    -1,   865,    -1,    -1,    -1,    -1,
      -1,  2147,  2148,  2149,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    24,   116,    26,    -1,    -1,    -1,    -1,    -1,   123,
     124,    -1,    -1,   127,   128,    -1,   130,   131,    -1,   133,
      -1,    -1,    -1,  1787,  1788,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,  1822,   243,
     174,   175,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1835,    -1,    -1,    -1,   975,   976,   977,    -1,    -1,
      -1,   981,   982,    -1,    -1,   985,   986,   987,   988,    -1,
     990,    -1,    -1,    -1,    -1,   995,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1891,  1892,    -1,
    1639,  1640,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1073,    -1,    -1,    -1,    -1,  1078,    -1,
      -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,   245,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,   256,   257,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1173,    -1,    -1,  2040,    -1,  1787,  1788,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,  2058,  2059,  2060,  2061,  2062,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1835,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     8,    -1,    -1,    -1,   243,
     373,   374,   375,    -1,    -1,  2119,   379,   380,   381,   382,
     383,   384,   385,    -1,   387,    -1,    -1,    -1,   391,   392,
      -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1891,  1892,    -1,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1911,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1312,    -1,    -1,    -1,    -1,  1926,    -1,    -1,
      -1,    -1,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,    -1,   210,   211,   212,    -1,    -1,
      -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1351,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,   248,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,  1383,  1384,  1385,  1386,  1387,    -1,    -1,
      -1,    -1,  1392,  1393,    -1,    -1,  1396,    -1,  1398,    -1,
      -1,    -1,  1402,    -1,    -1,  1405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2040,    -1,    -1,   557,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2058,
    2059,  2060,  2061,  2062,    -1,    -1,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,     8,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1488,    -1,
    1490,    -1,    -1,    -1,  1494,    -1,  1496,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1527,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     8,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,     8,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,  1623,    90,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125,
     126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1725,    -1,    -1,  1728,    -1,
      -1,   197,   198,   199,   200,   201,   202,   860,    -1,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,   894,    -1,   239,    -1,    -1,  1776,  1777,   244,  1779,
      -1,    -1,   248,    -1,    -1,   251,     8,    -1,    -1,    -1,
      -1,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,  1839,
    1840,    -1,   243,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,  1886,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,   100,    -1,   102,  1067,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,
      -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   153,    -1,    -1,   156,    -1,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1160,   197,   198,
     199,   200,   201,   202,    -1,    -1,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,   215,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,   244,     3,     4,     5,   248,
       7,    -1,   251,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,  2128,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    13,    14,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,
      97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,
    1313,  1314,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
      -1,    -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,  1400,    -1,    -1,
     197,   198,   199,   200,   201,   150,    -1,  1410,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,    -1,   174,
     175,   176,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,
      -1,    -1,   239,   240,   241,    -1,    -1,   244,    -1,   246,
      -1,    -1,    -1,   250,   251,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
    1563,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,
     128,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
     248,    -1,     8,   251,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125,
     126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,     3,
       4,     5,    -1,   249,    -1,   251,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,   125,   126,    -1,   128,    -1,   130,    -1,    -1,   133,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,   153,
      -1,    -1,   156,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,   201,   202,    -1,
      -1,    -1,   206,   207,   208,    -1,   210,   211,   212,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
     244,     3,     4,    -1,   248,    -1,    -1,   251,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,   125,   126,    -1,   128,    -1,   130,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,   156,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,   206,   207,   208,    -1,   210,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,   244,     3,     4,    -1,   248,   249,    -1,   251,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,
     130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,   156,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,    -1,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,   248,    -1,
      -1,   251,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,
     128,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
     248,    -1,    -1,   251,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125,
     126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,     3,
       4,    -1,   248,    -1,    -1,   251,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,   125,   126,    -1,   128,    -1,   130,    -1,    -1,   133,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,   153,
      -1,    -1,   156,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,   201,   202,    -1,
      -1,    -1,   206,   207,   208,    -1,   210,   211,   212,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
     244,     3,     4,    -1,    -1,   249,    -1,   251,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,   125,   126,    -1,   128,    -1,   130,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,   156,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,   206,   207,   208,    -1,   210,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,   244,     3,     4,    -1,   248,    -1,    -1,   251,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,
     130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,   156,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,    -1,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,   248,    -1,
      -1,   251,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,
     128,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
     248,    -1,     8,   251,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125,
     126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,     3,     4,    -1,    -1,   244,     8,
      -1,    10,    11,    12,    -1,   251,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,
      -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
      -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,
      -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,
     239,     3,     4,    -1,    -1,   244,    -1,    -1,    10,    11,
      12,    -1,   251,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,   125,   126,    -1,   128,    -1,   130,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,   156,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,   206,   207,   208,    -1,   210,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,   244,     3,     4,    -1,   248,    -1,    -1,   251,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,
     130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,   156,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,    -1,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,   248,    -1,
      -1,   251,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,
     128,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,     3,     4,     5,    -1,   244,    -1,    -1,    10,
      11,    12,    -1,   251,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,   200,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,   215,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,   248,    -1,    -1,
     251,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,   244,     3,     4,     5,   248,    -1,    -1,   251,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,   200,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,   215,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,   248,    -1,    -1,
     251,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,     3,     4,    -1,
      -1,   244,    -1,    -1,    10,    11,    12,    -1,   251,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,     3,     4,    -1,    85,
      86,     8,    88,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,   253,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,   248,    -1,    -1,   251,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     197,    -1,    -1,    -1,   201,    -1,    -1,    -1,   253,   206,
     207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,
      -1,    -1,   239,     3,     4,    -1,    -1,   244,    -1,    -1,
      10,    11,    12,    -1,   251,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,     3,
       4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,   197,    -1,   243,
      -1,   201,    -1,    -1,    -1,    -1,   206,   207,   208,   253,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   232,   233,    -1,   110,   111,   112,   113,   239,
      -1,   116,    -1,    -1,   244,   245,    -1,    -1,   123,   124,
      -1,   251,   127,   128,    -1,   130,   131,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,    -1,   210,   211,   212,   174,
     175,   176,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,    -1,    -1,    -1,    -1,   239,     3,     4,    -1,     6,
     244,    -1,    -1,    10,    11,    12,    -1,   251,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
     197,    -1,   243,    -1,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   253,   210,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   232,   233,    -1,   110,   111,
     112,   113,   239,    -1,   116,    -1,    -1,   244,    -1,    -1,
      -1,   123,   124,    -1,   251,   127,   128,    -1,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,    -1,   210,
     211,   212,   174,   175,   176,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,     3,
       4,    -1,    -1,   244,    -1,    -1,    10,    11,    12,    -1,
     251,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,     3,     4,
      -1,    85,    86,    -1,    88,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    13,    14,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,   253,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,    -1,   210,   211,   212,    -1,
      -1,    -1,   216,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   232,   233,
      -1,   110,   111,   112,   113,   239,    -1,   116,    -1,    -1,
     244,   245,    -1,    -1,   123,   124,    -1,   251,   127,   128,
      -1,   130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   197,    -1,    -1,   154,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,    -1,   210,   211,   212,    -1,    -1,
      -1,   216,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,
      -1,    -1,    -1,    -1,   239,     3,     4,    -1,    -1,   244,
     245,    -1,    10,    11,    12,    -1,   251,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,    -1,    -1,   127,   128,    -1,
     130,   131,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   174,   175,   176,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,   251,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,   249,
      -1,    -1,    -1,   123,   124,    -1,    -1,   127,   128,    -1,
     130,   131,    -1,   133,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,    -1,    -1,   116,   174,   175,   176,    -1,    -1,    -1,
     123,   124,    -1,    -1,   127,   128,    -1,   130,   131,    -1,
     133,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   174,   175,   176,   110,   111,   112,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   249,
      -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   150,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,    -1,    -1,   116,   174,   175,
     176,    -1,    -1,    -1,   123,   124,   249,    -1,   127,   128,
      -1,   130,   131,    -1,   133,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   174,   175,   176,   110,   111,
     112,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   249,    -1,   127,   128,    -1,   130,   131,
      -1,   133,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,    -1,
      -1,   116,   174,   175,   176,    -1,    -1,    -1,   123,   124,
     249,    -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   174,
     175,   176,   110,   111,   112,   113,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   249,    -1,   127,
     128,    -1,   130,   131,    -1,   133,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,    -1,    -1,   116,   174,   175,   176,    -1,
      -1,    -1,   123,   124,   249,    -1,   127,   128,    -1,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   174,   175,   176,   110,   111,   112,   113,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   249,    -1,   127,   128,    -1,   130,   131,    -1,   133,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,   150,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
     174,   175,   176,    -1,    44,    45,    -1,    -1,   249,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    -1,    73,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,   109,
     110,   111,   112,   113,   114,   249,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -1,
       4,    -1,   162,   163,   164,    -1,    -1,    -1,   168,    13,
      14,    -1,    -1,   173,   174,   175,   176,    -1,    -1,   179,
      -1,   181,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      44,    45,    -1,   203,   204,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,    -1,   216,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,   109,   110,   111,   112,   113,
     114,    -1,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,   163,
     164,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,   173,
     174,   175,   176,     4,     5,   179,    -1,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,   203,
     204,   205,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
     214,    -1,   216,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,   130,
     110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,    -1,    -1,   127,   128,    -1,
     130,   131,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,   174,   175,   176,   198,   199,   200,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,   209,    -1,
      -1,    -1,   213,    -1,   215,   216,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   249,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
     249,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,   249,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,   249,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   249,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
     249,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,   249,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,   249,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   249,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
     249,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,   248,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
     248,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,   245,    -1,   247,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,   247,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,   247,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,   247,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,   247,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
     247,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,   247,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,   247,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,   247,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,   247,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,   247,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,   247,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,   247,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,   247,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,   247,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
     247,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     245,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   255,   256,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    79,    80,
      81,    83,    84,    86,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     109,   110,   111,   112,   113,   114,   116,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   162,   163,   164,   168,
     173,   174,   175,   176,   179,   181,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     203,   204,   205,   214,   216,   257,   259,   260,   280,   298,
     300,   304,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   322,   324,   325,   331,   332,   333,   334,   340,   365,
     366,   248,   252,    14,   100,   244,   244,     6,   248,     6,
       6,     6,     6,   244,     6,     6,     6,     6,   246,   246,
       4,   342,   366,   244,   246,   278,    94,    97,   100,   102,
     278,   244,   244,   244,     4,   244,   244,   244,     4,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     248,   115,   100,     6,   248,    94,    97,   100,   113,   303,
     102,   244,     3,    10,    11,    12,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    55,    56,    57,    58,    63,
      64,    75,    76,    77,    85,    88,    94,    97,   100,   102,
     113,   123,   128,   130,   133,   197,   201,   202,   206,   207,
     208,   210,   211,   212,   232,   233,   239,   244,   248,   251,
     300,   301,   304,   315,   322,   324,   335,   336,   340,   342,
     349,   351,   366,   244,   248,   248,   100,   100,   123,    97,
     100,   102,    94,    97,   100,   102,   300,    97,   100,   102,
     113,   301,    97,   100,   244,    97,   154,   179,   195,   196,
     248,   232,   233,   244,   248,   346,   347,   346,   248,   248,
     346,     4,    94,    98,   104,   105,   107,   108,   127,   248,
     244,   100,   102,   100,    97,     4,    86,   190,   248,   366,
       4,     6,    94,    97,   100,    97,   100,   113,   302,     4,
       4,     4,     5,   244,   248,   349,   350,     4,   244,   244,
     244,     4,   248,   353,   366,     4,   244,   244,   244,     6,
       6,   246,     5,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    59,    60,    61,    62,    67,    68,    69,    72,
      74,    87,    90,   198,   199,   200,   209,   213,   215,   357,
     366,   244,     4,   357,     5,   248,     5,   248,    32,   233,
     335,   366,   246,   248,   244,   248,     6,   244,   248,     6,
     252,     7,   130,   190,   217,   218,   219,   220,   240,   241,
     244,   246,   250,   276,   277,   278,   300,   335,   356,   357,
     366,     4,   304,   305,   306,   248,     6,   335,   356,   357,
     366,   356,   335,   356,   363,   364,   366,   282,   286,   244,
     345,     9,   357,   244,   244,   244,   244,   366,   335,   335,
     335,   244,   335,   335,   335,   244,   335,   335,   335,   335,
     335,   335,   335,   356,   335,   335,   335,   335,   350,   244,
     233,   335,   351,   352,   248,   350,   349,   356,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   244,   246,   278,   278,   278,   278,   278,   278,   244,
     278,   278,   244,   300,   278,   278,     5,   248,   248,   123,
     300,   300,   244,   278,   278,   244,   244,   244,   335,   248,
     335,   351,   335,   335,   249,   352,   342,   366,   182,     5,
     248,     8,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     243,     9,   244,   246,   250,   277,   278,   335,   352,   352,
     244,   244,   244,   349,   350,   350,   350,   299,   248,   244,
     349,   248,   248,   335,     4,   349,   248,   353,   248,   248,
     346,   346,   346,   335,   335,   232,   233,   248,   248,   346,
     232,   233,   244,   306,   346,   248,   244,   248,   244,   244,
     244,   244,   244,   244,   244,   352,   335,   350,   350,   350,
     244,     4,   246,   248,     6,   246,   306,     6,     6,   248,
     248,   248,   248,   350,   246,   246,   246,   335,     8,     6,
       6,   335,   335,   335,   250,   335,   248,   182,   335,   335,
     335,   335,   278,   278,   278,   244,   244,   244,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   244,   244,
     278,   244,   246,     6,     6,   248,     6,     8,   306,     6,
       8,   306,   278,   335,   234,   248,     9,   244,   246,   250,
     356,   352,   335,   306,   349,   349,   248,   357,   300,     7,
     335,   335,     4,   179,   180,   349,     6,   245,   247,   248,
     279,   248,     6,   248,     6,     9,   244,   246,   250,   366,
     249,   123,   128,   130,   131,   133,   298,   300,   335,     6,
     245,   253,     9,   244,   246,   250,   245,   253,   253,   245,
     253,     9,   244,   250,   247,   253,   281,   247,   281,    89,
     344,   341,   366,   253,   335,   335,   335,   335,   253,   245,
     245,   245,   335,   245,   245,   245,   335,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   249,     7,
     335,   234,   249,   253,   335,     6,     6,   245,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   351,   335,   335,   335,   335,
     335,   335,   335,   351,   351,   366,   248,   335,   335,   356,
     335,   356,   349,   356,   356,   363,   248,   335,   279,   366,
       8,   335,   335,   350,   349,   356,   356,   351,   342,   357,
     342,   352,   245,   249,   250,   278,    64,     8,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   248,   335,   351,   335,   335,   335,   335,   335,
     366,   335,   335,     4,   343,   248,   279,   245,   249,   249,
     335,   335,   335,     7,     7,   328,   328,   244,   335,   335,
       6,   352,   352,   248,   245,     6,   306,   248,   306,   306,
     253,   253,   253,   346,   346,   305,   305,   253,   335,   249,
     319,   253,   306,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   249,   245,     7,   329,     6,     7,   335,     6,
     335,   306,   335,   249,   352,   352,   352,   335,     6,   335,
     335,   335,   245,   249,   245,   245,   245,   179,   253,   306,
     248,     8,   245,   245,   247,   363,   356,   363,   356,   356,
     356,   356,   356,   356,   335,   356,   356,   356,   356,   251,
     359,   366,   357,   356,   356,   356,   342,   366,   352,   249,
     249,   249,   249,   335,   335,   306,   366,   343,   247,   249,
     245,   137,   154,   323,   245,   249,   253,   335,     6,   248,
     349,   245,   247,     7,   276,   277,   250,     7,     6,   352,
       7,   217,   276,   335,   261,   366,   335,   335,   343,   246,
     244,   123,   300,   301,   300,   248,   249,     6,   228,   231,
     258,   352,   366,   335,   335,     4,   343,     6,   352,   335,
       6,   356,   364,   366,   245,   343,     6,   366,     6,   356,
     335,   245,   246,   335,   253,   253,   253,   253,   357,     7,
       7,     7,   245,     7,     7,     7,   245,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   335,   245,   248,
     335,   351,   249,     6,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   253,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   253,   253,   253,   245,   247,
     247,   352,   253,   253,   279,   253,   279,   253,   253,   253,
     245,   352,   337,   279,   249,   249,   249,   253,   253,   279,
     279,   245,   250,   245,   250,   253,   278,   338,   249,     7,
     343,   279,   248,   249,     8,     8,   352,   250,   245,   247,
     277,   244,   246,   278,   352,     7,   248,   248,   245,   245,
     245,   335,   349,     4,   327,     6,   295,   335,   357,   249,
     245,   249,   249,   352,   250,   249,   306,   249,   249,   346,
     335,   335,   249,   249,   335,   346,   134,   134,   151,   159,
     160,   161,   165,   166,   320,   321,   346,   249,   316,   245,
     249,   245,   245,   245,   245,   245,   245,   245,   248,     7,
     335,     6,   335,   245,   247,   249,   247,   249,   249,   249,
     249,   247,   247,   253,     7,     7,     7,   250,   335,   249,
     335,   335,     7,   250,   279,   253,   279,   279,   245,   245,
     253,   279,   279,   253,   253,   279,   279,   279,   279,   335,
     279,     9,   358,   253,   245,   253,   279,   250,   253,   339,
     247,   249,   249,   250,   244,   246,   252,   182,     7,   154,
       6,   335,   249,   248,     6,   349,   249,   335,     6,     7,
     276,   277,   250,   276,   277,   357,   335,     6,     4,   248,
     354,   366,   249,    46,    46,   349,   249,     4,   169,   170,
     171,   172,   249,   264,   268,   271,   273,   274,   250,   245,
     247,   244,   335,   335,   244,   248,   244,   248,     8,   352,
     356,   245,   250,   245,   247,   244,   245,   253,   250,   244,
       7,   278,     4,   289,   290,   291,   279,   335,   335,   335,
     335,   279,   346,   349,   349,     7,   349,   349,   349,     7,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
       6,     7,   352,   335,   335,   335,   335,   249,   335,   335,
     335,   349,   356,   356,   249,   253,   288,   335,   335,   343,
     343,   335,   335,   245,   349,   278,   335,   335,   335,   249,
     343,   277,   250,   277,   335,   335,   279,   249,   349,   352,
     352,     7,     7,     7,   134,   326,     6,   245,   253,     7,
       7,     7,   249,     4,   249,   253,   253,   253,   249,   249,
     112,     4,     6,   335,   248,     6,   244,     6,   167,     6,
     167,   249,   321,   253,   320,     7,     6,     7,     7,     7,
       7,     7,     7,     7,   305,   349,     6,   248,     6,     6,
       6,   100,     7,     6,     6,   335,   349,   349,   349,     4,
     253,     8,     8,   245,     4,   103,   104,     4,   352,   356,
     335,   356,   251,   253,   292,   356,   356,   343,   356,   245,
     253,   343,   248,   300,   248,     6,   335,     6,   248,   349,
     249,   249,   335,     6,     4,   179,   180,   335,     6,     6,
       6,     7,   353,   355,     6,   246,   279,   278,   278,     6,
     265,   244,   244,   248,   275,     6,   343,   250,   356,   335,
     247,   245,   335,     8,   352,   335,   352,   249,   249,     6,
       6,   258,   343,   250,   335,     6,   335,   343,   245,   248,
     335,   357,   279,    46,   248,   349,   357,   360,   247,   253,
       6,   245,   245,   245,   245,     6,     6,   127,   297,   297,
     349,     6,     6,     6,   349,   134,   182,   296,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   249,   279,
     279,   279,   279,   279,   253,   253,   253,   245,   279,   279,
     290,   279,   245,   279,   245,   278,   338,   279,     6,   279,
     253,   244,   246,   278,     4,   245,   247,   279,     6,   249,
     249,   349,   349,   349,     4,     6,   276,   335,   349,   248,
     248,     7,     6,     7,   335,   335,   335,   248,   248,   248,
     246,     6,   335,   349,   335,     6,     6,   335,   346,   249,
       5,   349,   248,   248,   248,   248,   248,   248,   248,   349,
     249,     6,   352,   248,   335,   247,     6,     6,   178,   335,
     335,   335,     6,     6,     6,     6,     7,   279,   253,   253,
     279,   253,   335,     4,   194,   293,   294,   279,   245,   279,
     339,   357,   244,   246,   335,   248,   306,     6,   306,   253,
       6,     6,     7,   276,   277,   250,     7,     6,   353,   249,
     253,   335,   276,   248,   279,   361,   362,   363,   361,   244,
     335,   335,   348,   349,   248,   244,     4,     6,   245,     6,
     245,   249,   249,   245,   249,     6,     6,   356,   244,     4,
     245,   253,   244,   349,   357,     7,   278,   287,   335,   351,
     291,     6,     6,     6,     6,   346,     6,     6,     6,     6,
      94,   113,    98,     6,     5,   248,   335,   335,   335,   335,
     245,   338,   335,   335,   335,   279,   277,   248,   248,     6,
     296,     6,   335,   349,     4,     6,   352,   352,   335,   335,
     357,   249,   245,   249,   253,   305,   305,   335,   335,   249,
     253,   245,   249,   253,     6,     6,   348,   346,   346,   346,
     346,   346,   233,   346,     6,   249,   335,     6,     6,   349,
     249,   253,     8,   249,   245,   248,   335,   357,   356,   335,
     356,   335,   357,   360,   362,   357,   253,   245,   253,   249,
     335,   323,   323,   349,   357,   335,     6,     4,   354,     6,
     353,   247,   349,   363,     6,   279,   279,   262,   335,   253,
     253,   249,   253,   263,   335,   335,     6,     6,     6,     6,
     335,   335,   245,   283,   285,   248,   362,   249,   253,     7,
       7,   248,   248,   248,     5,   348,   279,   279,   253,   279,
     245,   253,   245,   247,   352,   352,     6,     6,   248,   249,
     249,   248,     6,     6,   248,   335,   249,   249,   249,   247,
       6,   349,     7,   248,   335,   249,   253,   253,   253,   253,
     253,   253,     6,   249,   177,   335,   335,   352,     6,     6,
     245,   279,   279,   294,   357,   249,   249,   249,   249,     6,
       6,     7,     6,   250,     6,   249,     6,     6,   245,   253,
     335,   335,   248,   349,   249,   253,   245,   245,   253,   288,
     292,   349,   279,   335,   357,   366,   352,   352,   335,     6,
     249,   335,   338,   335,   249,   249,   348,   138,   139,   144,
     330,   138,   139,   330,   352,   305,   249,   253,     6,   249,
     349,   306,   249,     6,   352,   346,   346,   346,   346,   346,
     335,   249,   249,   249,   245,     6,   248,     6,   353,   180,
     266,   335,   253,   253,   348,     6,   335,   335,   249,   249,
     284,     7,   244,   249,   249,   249,   248,   253,   245,   253,
     248,   249,   248,   346,   349,     6,   248,   346,     6,   249,
     249,   335,     6,   134,   249,   317,   248,   249,   253,   253,
     253,   253,   253,     6,     6,     6,   306,     6,   248,   335,
     335,   249,   253,   288,   357,   245,   335,   335,   335,   352,
       6,   346,     6,   346,     6,     6,   249,   335,   320,   306,
       6,   352,   352,   352,   352,   346,   352,   323,   263,   245,
     253,     6,   248,   335,   249,   253,   253,   253,   249,   253,
     253,     6,   249,   249,   318,   249,   249,   249,   249,   253,
     249,   249,   249,   269,   335,   348,   249,   335,   335,   335,
     346,   346,   320,     6,     6,     6,     6,   352,     6,     6,
       6,   248,   245,   249,     6,   249,   279,   253,   253,   253,
     249,   249,   267,   356,   272,   248,     6,   335,   335,   335,
       6,   249,   253,   248,   348,   249,   249,   249,     6,   356,
     270,   356,   249,     6,     6,   249,   253,     6,     6,   356
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   254,   255,   255,   256,   256,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   258,   258,   259,   259,
     259,   259,   259,   259,   260,   260,   260,   260,   261,   261,
     261,   261,   261,   261,   262,   262,   263,   263,   265,   266,
     264,   267,   267,   269,   268,   270,   270,   272,   271,   273,
     273,   275,   274,   276,   276,   276,   276,   276,   277,   277,
     278,   278,   279,   279,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   281,   281,   282,   282,   282,   283,   282,   284,   282,
     282,   285,   282,   286,   286,   287,   287,   287,   288,   288,
     289,   289,   290,   290,   291,   291,   291,   291,   291,   292,
     292,   293,   293,   294,   294,   294,   294,   294,   295,   295,
     295,   296,   296,   296,   296,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   299,
     298,   300,   300,   300,   300,   300,   301,   301,   301,   301,
     302,   302,   302,   303,   303,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   305,   305,   306,   306,
     306,   306,   306,   306,   306,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   308,   308,   308,
     308,   308,   308,   308,   308,   309,   309,   310,   311,   311,
     311,   311,   311,   311,   311,   311,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   313,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   315,   315,   315,   316,   315,   317,   315,   318,
     315,   319,   315,   315,   315,   315,   315,   315,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   322,   322,   322,   322,   322,   323,   323,   323,   323,
     323,   324,   324,   325,   326,   326,   327,   327,   328,   328,
     329,   329,   330,   330,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     332,   332,   332,   333,   333,   333,   334,   334,   334,   334,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   337,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   338,   338,   339,   339,   341,
     340,   342,   342,   343,   344,   344,   345,   345,   346,   346,
     346,   346,   346,   347,   347,   347,   347,   348,   348,   349,
     349,   349,   349,   349,   349,   350,   350,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   352,   352,
     352,   352,   353,   353,   353,   353,   354,   354,   355,   355,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     358,   357,   357,   359,   359,   360,   361,   361,   362,   363,
     363,   363,   363,   364,   364,   364,   365,   365,   365,   366,
     366,   366
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
       5,     1,     1,     1,     3,     5,     7,     4,     4,     4,
       6,     6,     8,     8,     4,    14,     4,     4,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     4,     4,     3,     5,     6,     8,     6,     4,
       5,     1,     4,     1,     1,     1,     1,     4,     6,     4,
       6,     5,     7,     4,     4,     4,     8,     4,     4,     4,
       4,     8,     8,     6,     4,     6,     4,     1,     4,     4,
       0,     6,     4,     2,     4,     4,     1,     1,     3,     1,
       1,     3,     3,     3,     5,     7,     5,     5,     8,     1,
       1,     4
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
#line 5934 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 281 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5940 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 282 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5946 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 283 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5952 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 5975 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 303 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5981 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 304 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 5987 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 305 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5993 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 306 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 5999 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 307 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6005 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 308 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6011 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 309 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6017 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 310 "Gmsh.y" /* yacc.c:1652  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 6023 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 311 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6029 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 312 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6035 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 313 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6041 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 314 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6047 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 315 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6053 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 316 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6059 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 317 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6065 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 318 "Gmsh.y" /* yacc.c:1652  */
    { return 1; }
#line 6071 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 323 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"w";
    }
#line 6079 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 327 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char*)"a";
    }
#line 6087 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 334 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6096 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 339 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6105 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6123 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6140 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6157 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6184 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6202 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6219 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6236 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6255 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 470 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 6265 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 484 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6271 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 486 "Gmsh.y" /* yacc.c:1652  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6277 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 491 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6283 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 493 "Gmsh.y" /* yacc.c:1652  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6289 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6397 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6411 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 612 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 6421 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 621 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6432 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 628 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6443 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6456 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 647 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 6466 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 656 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6477 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 663 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6488 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6500 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 681 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 6510 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6530 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6550 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 729 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 6560 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 735 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 6567 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 742 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 6573 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 743 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6579 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 744 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 6585 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 745 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 6591 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 746 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 4; }
#line 6597 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 750 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 6603 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 751 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = -1; }
#line 6609 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 757 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"("; }
#line 6615 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 757 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"["; }
#line 6621 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 758 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)")"; }
#line 6627 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 758 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"]"; }
#line 6633 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 77:
#line 768 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 6642 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 78:
#line 773 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 6652 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6718 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6737 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6770 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 82:
#line 885 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 6781 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 83:
#line 895 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6790 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 84:
#line 900 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6799 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 85:
#line 908 "Gmsh.y" /* yacc.c:1652  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6808 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 86:
#line 913 "Gmsh.y" /* yacc.c:1652  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6817 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 87:
#line 921 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 6827 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 88:
#line 930 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 6836 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6852 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6870 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 91:
#line 964 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6880 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 92:
#line 970 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6890 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6912 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6934 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6947 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6960 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 97:
#line 1036 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 6969 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 98:
#line 1041 "Gmsh.y" /* yacc.c:1652  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 6978 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7002 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7026 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7050 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7062 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 103:
#line 1120 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Box");
#endif
    }
#line 7073 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 104:
#line 1127 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Cylinder");
#endif
    }
#line 7084 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7110 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7137 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7179 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7201 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7217 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7233 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7246 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7259 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 116:
#line 1286 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7265 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7287 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 118:
#line 1306 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7293 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7313 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7326 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 121:
#line 1333 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 7332 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7346 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 124:
#line 1349 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 7356 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 125:
#line 1357 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7366 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 126:
#line 1363 "Gmsh.y" /* yacc.c:1652  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7375 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7404 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7420 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7437 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7455 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7467 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7482 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 143:
#line 1485 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 7493 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7505 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 145:
#line 1502 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 7516 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7533 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7550 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 148:
#line 1542 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 7558 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 149:
#line 1546 "Gmsh.y" /* yacc.c:1652  */
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[0].c)), dim_entity, t + 1);
      Free((yyvsp[0].c));
    }
#line 7569 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 150:
#line 1553 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), dim_entity, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 7578 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 151:
#line 1561 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 7586 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 152:
#line 1565 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[-1].d);
      List_Add((yyval.l), &p);
    }
#line 7596 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 153:
#line 1571 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7604 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7617 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 155:
#line 1586 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 7625 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 156:
#line 1590 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 7633 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7660 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7680 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7700 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7741 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 7785 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 162:
#line 1729 "Gmsh.y" /* yacc.c:1652  */
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
#line 7805 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 163:
#line 1745 "Gmsh.y" /* yacc.c:1652  */
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
#line 7825 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 164:
#line 1762 "Gmsh.y" /* yacc.c:1652  */
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
#line 7860 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 165:
#line 1793 "Gmsh.y" /* yacc.c:1652  */
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
#line 7880 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 166:
#line 1809 "Gmsh.y" /* yacc.c:1652  */
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
#line 7901 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 167:
#line 1826 "Gmsh.y" /* yacc.c:1652  */
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
#line 7921 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 168:
#line 1842 "Gmsh.y" /* yacc.c:1652  */
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
#line 7975 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 169:
#line 1892 "Gmsh.y" /* yacc.c:1652  */
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
#line 7997 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 170:
#line 1910 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8007 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 171:
#line 1916 "Gmsh.y" /* yacc.c:1652  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8017 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 172:
#line 1922 "Gmsh.y" /* yacc.c:1652  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 8028 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 173:
#line 1929 "Gmsh.y" /* yacc.c:1652  */
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
#line 8063 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 174:
#line 1960 "Gmsh.y" /* yacc.c:1652  */
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
#line 8082 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 175:
#line 1975 "Gmsh.y" /* yacc.c:1652  */
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
#line 8108 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 176:
#line 1997 "Gmsh.y" /* yacc.c:1652  */
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
#line 8135 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 177:
#line 2020 "Gmsh.y" /* yacc.c:1652  */
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
#line 8162 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 178:
#line 2043 "Gmsh.y" /* yacc.c:1652  */
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
#line 8189 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 179:
#line 2066 "Gmsh.y" /* yacc.c:1652  */
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
#line 8217 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 180:
#line 2090 "Gmsh.y" /* yacc.c:1652  */
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
#line 8245 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 181:
#line 2114 "Gmsh.y" /* yacc.c:1652  */
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
#line 8273 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 182:
#line 2138 "Gmsh.y" /* yacc.c:1652  */
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
#line 8303 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 183:
#line 2164 "Gmsh.y" /* yacc.c:1652  */
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
#line 8324 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 184:
#line 2181 "Gmsh.y" /* yacc.c:1652  */
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
#line 8344 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 185:
#line 2197 "Gmsh.y" /* yacc.c:1652  */
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
#line 8366 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 186:
#line 2215 "Gmsh.y" /* yacc.c:1652  */
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
#line 8388 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 187:
#line 2233 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-6].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8399 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 188:
#line 2241 "Gmsh.y" /* yacc.c:1652  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-10].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8410 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 189:
#line 2248 "Gmsh.y" /* yacc.c:1652  */
    {
      dim_entity = (yyvsp[0].i);
    }
#line 8418 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 190:
#line 2252 "Gmsh.y" /* yacc.c:1652  */
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
#line 8445 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 191:
#line 2278 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8451 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 192:
#line 2280 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8457 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 193:
#line 2282 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8463 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 194:
#line 2284 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8469 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 195:
#line 2286 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
#line 8478 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 196:
#line 2294 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8484 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 197:
#line 2296 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8490 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 198:
#line 2298 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 3; }
#line 8496 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 199:
#line 2300 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
#line 8505 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 200:
#line 2308 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8511 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 201:
#line 2310 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8517 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 202:
#line 2312 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
#line 8526 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 203:
#line 2320 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 8532 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 204:
#line 2322 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 8538 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 205:
#line 2324 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 8544 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 206:
#line 2326 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
#line 8553 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 207:
#line 2336 "Gmsh.y" /* yacc.c:1652  */
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
#line 8573 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 208:
#line 2352 "Gmsh.y" /* yacc.c:1652  */
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
#line 8593 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 209:
#line 2368 "Gmsh.y" /* yacc.c:1652  */
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
#line 8613 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 210:
#line 2384 "Gmsh.y" /* yacc.c:1652  */
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
#line 8633 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 211:
#line 2400 "Gmsh.y" /* yacc.c:1652  */
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
#line 8653 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 212:
#line 2416 "Gmsh.y" /* yacc.c:1652  */
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
#line 8674 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 213:
#line 2433 "Gmsh.y" /* yacc.c:1652  */
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
#line 8715 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 214:
#line 2470 "Gmsh.y" /* yacc.c:1652  */
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
#line 8740 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 215:
#line 2492 "Gmsh.y" /* yacc.c:1652  */
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
#line 8765 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 216:
#line 2515 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8771 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 217:
#line 2516 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8777 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 218:
#line 2521 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 8785 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 219:
#line 2525 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 8793 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 220:
#line 2529 "Gmsh.y" /* yacc.c:1652  */
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
#line 8814 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 221:
#line 2546 "Gmsh.y" /* yacc.c:1652  */
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
#line 8838 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 222:
#line 2566 "Gmsh.y" /* yacc.c:1652  */
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
#line 8862 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 223:
#line 2586 "Gmsh.y" /* yacc.c:1652  */
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
#line 8885 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 224:
#line 2605 "Gmsh.y" /* yacc.c:1652  */
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
#line 8911 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 225:
#line 2632 "Gmsh.y" /* yacc.c:1652  */
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
#line 8934 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 226:
#line 2651 "Gmsh.y" /* yacc.c:1652  */
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
#line 8959 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 227:
#line 2673 "Gmsh.y" /* yacc.c:1652  */
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
#line 8977 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 228:
#line 2688 "Gmsh.y" /* yacc.c:1652  */
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
#line 8996 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 229:
#line 2703 "Gmsh.y" /* yacc.c:1652  */
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
#line 9018 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 230:
#line 2722 "Gmsh.y" /* yacc.c:1652  */
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
#line 9072 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 231:
#line 2773 "Gmsh.y" /* yacc.c:1652  */
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
#line 9096 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 232:
#line 2794 "Gmsh.y" /* yacc.c:1652  */
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
#line 9121 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 233:
#line 2816 "Gmsh.y" /* yacc.c:1652  */
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
#line 9147 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 234:
#line 2838 "Gmsh.y" /* yacc.c:1652  */
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
#line 9256 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 235:
#line 2943 "Gmsh.y" /* yacc.c:1652  */
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
#line 9276 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 236:
#line 2959 "Gmsh.y" /* yacc.c:1652  */
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
#line 9310 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 237:
#line 2994 "Gmsh.y" /* yacc.c:1652  */
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
#line 9336 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 238:
#line 3016 "Gmsh.y" /* yacc.c:1652  */
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
#line 9362 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 239:
#line 3038 "Gmsh.y" /* yacc.c:1652  */
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
#line 9378 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 240:
#line 3050 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 9388 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 241:
#line 3056 "Gmsh.y" /* yacc.c:1652  */
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
#line 9407 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 242:
#line 3071 "Gmsh.y" /* yacc.c:1652  */
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
#line 9439 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 243:
#line 3099 "Gmsh.y" /* yacc.c:1652  */
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
#line 9455 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 244:
#line 3111 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yynamespaces.clear();
    }
#line 9463 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 245:
#line 3120 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), false);
      List_Delete((yyvsp[-1].l));
    }
#line 9474 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 246:
#line 3127 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), true);
      List_Delete((yyvsp[-1].l));
    }
#line 9485 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 247:
#line 3139 "Gmsh.y" /* yacc.c:1652  */
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
#line 9504 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 248:
#line 3159 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
    }
#line 9512 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 249:
#line 3163 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[-1].c));
    }
#line 9521 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 250:
#line 3168 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
    }
#line 9529 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 251:
#line 3172 "Gmsh.y" /* yacc.c:1652  */
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[-1].c));
    }
#line 9538 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 252:
#line 3177 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9549 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 253:
#line 3184 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9560 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 254:
#line 3191 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9571 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 255:
#line 3198 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9582 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 256:
#line 3210 "Gmsh.y" /* yacc.c:1652  */
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
#line 9659 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 257:
#line 3283 "Gmsh.y" /* yacc.c:1652  */
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
#line 9681 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 258:
#line 3301 "Gmsh.y" /* yacc.c:1652  */
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
#line 9710 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 259:
#line 3326 "Gmsh.y" /* yacc.c:1652  */
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
#line 9729 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 260:
#line 3341 "Gmsh.y" /* yacc.c:1652  */
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
#line 9766 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 261:
#line 3374 "Gmsh.y" /* yacc.c:1652  */
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
#line 9782 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 262:
#line 3386 "Gmsh.y" /* yacc.c:1652  */
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
#line 9810 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 263:
#line 3410 "Gmsh.y" /* yacc.c:1652  */
    {
      Msg::Exit(0);
    }
#line 9818 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 264:
#line 3414 "Gmsh.y" /* yacc.c:1652  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 9827 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 265:
#line 3419 "Gmsh.y" /* yacc.c:1652  */
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
#line 9838 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 266:
#line 3426 "Gmsh.y" /* yacc.c:1652  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 9847 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 267:
#line 3431 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
#line 9861 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 268:
#line 3441 "Gmsh.y" /* yacc.c:1652  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 9870 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 269:
#line 3446 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 9880 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 270:
#line 3452 "Gmsh.y" /* yacc.c:1652  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 9892 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 271:
#line 3460 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 9900 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 272:
#line 3464 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    }
#line 9908 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 273:
#line 3468 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshVertices();
    }
#line 9916 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 274:
#line 3472 "Gmsh.y" /* yacc.c:1652  */
    {
      GModel::current()->renumberMeshElements();
    }
#line 9924 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 275:
#line 3476 "Gmsh.y" /* yacc.c:1652  */
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 9937 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 276:
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
#line 9999 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 277:
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
#line 10015 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 278:
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
#line 10036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 279:
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
#line 10057 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 280:
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
#line 10083 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 281:
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
#line 10109 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 282:
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
#line 10148 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 283:
#line 3678 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10160 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 284:
#line 3686 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10172 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 285:
#line 3694 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 10182 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 286:
#line 3700 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10193 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 287:
#line 3707 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10204 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 288:
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
#line 10228 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 289:
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
#line 10258 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 290:
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
#line 10274 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 291:
#line 3772 "Gmsh.y" /* yacc.c:1652  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 10284 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 292:
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
#line 10306 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 293:
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
#line 10328 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 294:
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
#line 10350 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 295:
#line 3837 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10360 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 296:
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
#line 10382 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 297:
#line 3861 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10392 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 298:
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
#line 10416 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 299:
#line 3887 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10426 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 300:
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
#line 10448 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 301:
#line 3911 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10458 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 302:
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
#line 10479 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 303:
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
#line 10499 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 304:
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
#line 10520 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 305:
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
#line 10541 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 306:
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
#line 10567 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 307:
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
#line 10595 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 308:
#line 4035 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10602 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 309:
#line 4038 "Gmsh.y" /* yacc.c:1652  */
    {
    }
#line 10609 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 310:
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
#line 10625 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 311:
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
#line 10649 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 312:
#line 4076 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 10657 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 313:
#line 4080 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = true;
    }
#line 10665 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 314:
#line 4084 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 10673 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 315:
#line 4088 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 10681 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 316:
#line 4092 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 10689 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 317:
#line 4096 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 10697 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 318:
#line 4100 "Gmsh.y" /* yacc.c:1652  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 10705 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 319:
#line 4104 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      int num = (int)(yyvsp[-6].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[-1].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[-3].l));
    }
#line 10718 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 320:
#line 4113 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 10730 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 321:
#line 4125 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Union; }
#line 10736 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 322:
#line 4126 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Intersection; }
#line 10742 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 323:
#line 4127 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Difference; }
#line 10748 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 324:
#line 4128 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Section; }
#line 10754 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 325:
#line 4129 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = OCC_Internals::Fragments; }
#line 10760 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 326:
#line 4133 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 10766 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 327:
#line 4134 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 1; }
#line 10772 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 328:
#line 4135 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 2; }
#line 10778 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 329:
#line 4136 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 1 : 0; }
#line 10784 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 330:
#line 4137 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].d) ? 2 : 0; }
#line 10790 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 331:
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
#line 10817 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 332:
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
#line 10837 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 333:
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
#line 10859 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 334:
#line 4206 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 10867 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 335:
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
#line 10884 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 336:
#line 4225 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = -1; // left
    }
#line 10892 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 337:
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
#line 10910 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 338:
#line 4245 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 10918 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 339:
#line 4249 "Gmsh.y" /* yacc.c:1652  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 10926 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 340:
#line 4254 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = 45;
    }
#line 10934 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 341:
#line 4258 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 10942 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 342:
#line 4264 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 10950 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 343:
#line 4268 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10958 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 344:
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
#line 10984 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 345:
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
#line 11029 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 346:
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
#line 11077 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 347:
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
#line 11120 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 348:
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
#line 11149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 349:
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
#line 11165 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 350:
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
#line 11181 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 351:
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
#line 11197 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 352:
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
#line 11213 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 353:
#line 4494 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[-1].d);
      }
      List_Delete((yyvsp[-4].l));
    }
#line 11226 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 354:
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
#line 11260 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 355:
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
#line 11290 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 356:
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
#line 11320 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 357:
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
#line 11355 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 358:
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
#line 11385 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 359:
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
#line 11414 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 360:
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
#line 11443 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 361:
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
#line 11472 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 362:
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
#line 11501 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 363:
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
#line 11526 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 364:
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
#line 11541 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 365:
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
#line 11593 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 366:
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
#line 11651 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 367:
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
#line 11670 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 368:
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
#line 11686 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 369:
#line 4910 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-2].i), tags);
      List_Delete((yyvsp[-1].l));
    }
#line 11696 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 370:
#line 4921 "Gmsh.y" /* yacc.c:1652  */
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
#line 11707 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 371:
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
#line 11726 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 372:
#line 4943 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[-2].l));
    }
#line 11739 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 373:
#line 4956 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Homology"; }
#line 11745 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 374:
#line 4957 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 11751 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 375:
#line 4958 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (char*)"Betti"; }
#line 11757 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 376:
#line 4963 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 11767 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 377:
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
#line 11783 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 378:
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
#line 11805 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 379:
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
#line 11832 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 380:
#line 5026 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11838 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 381:
#line 5027 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 11844 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 382:
#line 5028 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 11850 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 383:
#line 5029 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11856 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 384:
#line 5030 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 11862 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 385:
#line 5031 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 11868 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 386:
#line 5032 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 11874 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 387:
#line 5033 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 11880 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 388:
#line 5035 "Gmsh.y" /* yacc.c:1652  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 11891 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 389:
#line 5041 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) | (int)(yyvsp[0].d); }
#line 11897 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 390:
#line 5042 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) & (int)(yyvsp[0].d); }
#line 11903 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 391:
#line 5043 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d); }
#line 11909 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 392:
#line 5044 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 11915 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 393:
#line 5045 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 11921 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 394:
#line 5046 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 11927 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 395:
#line 5047 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 11933 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 396:
#line 5048 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 11939 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 397:
#line 5049 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 11945 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 398:
#line 5050 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 11951 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 399:
#line 5051 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 11957 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 400:
#line 5052 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 11963 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 401:
#line 5053 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) >> (int)(yyvsp[0].d)); }
#line 11969 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 402:
#line 5054 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ((int)(yyvsp[-2].d) << (int)(yyvsp[0].d)); }
#line 11975 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 403:
#line 5055 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 11981 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 404:
#line 5056 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 11987 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 405:
#line 5057 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 11993 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 406:
#line 5058 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 11999 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 407:
#line 5059 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 12005 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 408:
#line 5060 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 12011 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 409:
#line 5061 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 12017 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 410:
#line 5062 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 12023 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 411:
#line 5063 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 12029 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 412:
#line 5064 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 12035 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 413:
#line 5065 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 12041 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 414:
#line 5066 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 12047 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 415:
#line 5067 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 12053 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 416:
#line 5068 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 12059 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 417:
#line 5069 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 12065 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 418:
#line 5070 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 12071 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 419:
#line 5071 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = std::abs((yyvsp[-1].d)); }
#line 12077 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 420:
#line 5072 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 12083 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 421:
#line 5073 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 12089 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 422:
#line 5074 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 12095 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 423:
#line 5075 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12101 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 424:
#line 5076 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 12107 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 425:
#line 5077 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 12113 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 426:
#line 5078 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 12119 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 427:
#line 5087 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12125 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 428:
#line 5088 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 3.141592653589793; }
#line 12131 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 429:
#line 5089 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 12137 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 430:
#line 5090 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 12143 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 431:
#line 5091 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 12149 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 432:
#line 5092 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 12155 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 433:
#line 5093 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 12161 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 434:
#line 5094 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 12167 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 435:
#line 5095 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = Cpu(); }
#line 12173 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 436:
#line 5096 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 12179 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 437:
#line 5097 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = TotalRam(); }
#line 12185 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 438:
#line 5102 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 12191 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 439:
#line 5104 "Gmsh.y" /* yacc.c:1652  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 12201 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 440:
#line 5110 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12207 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 441:
#line 5112 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12216 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 442:
#line 5117 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12225 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 443:
#line 5122 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[0].c2).char1, (yyvsp[0].c2).char2);
    }
#line 12233 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 444:
#line 5127 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12241 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 445:
#line 5132 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12249 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 446:
#line 5136 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-1].c2).char1, (yyvsp[-1].c2).char2, 1, 0, 0., 1);
    }
#line 12257 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 447:
#line 5140 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-3].c2).char1, (yyvsp[-3].c2).char2, (yyvsp[-1].c), 0, 0., 1);
    }
#line 12265 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 448:
#line 5144 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-2].c2).char1, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].d), 2);
    }
#line 12273 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 449:
#line 5148 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].d), 2);
    }
#line 12281 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 450:
#line 5152 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-5].c2).char1, (yyvsp[-5].c2).char2, 2, (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12289 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 451:
#line 5156 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c2).char1, (yyvsp[-7].c2).char2, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12297 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 452:
#line 5160 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 12307 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 453:
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
#line 12326 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 454:
#line 5182 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c));
    }
#line 12334 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 455:
#line 5187 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[-1].c));
    }
#line 12344 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 456:
#line 5193 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
#line 12353 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 457:
#line 5199 "Gmsh.y" /* yacc.c:1652  */
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
#line 12376 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 458:
#line 5218 "Gmsh.y" /* yacc.c:1652  */
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
#line 12400 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 459:
#line 5239 "Gmsh.y" /* yacc.c:1652  */
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
#line 12424 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 460:
#line 5272 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12432 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 461:
#line 5276 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12440 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 462:
#line 5281 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12448 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 463:
#line 5285 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12456 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 464:
#line 5289 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12464 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 465:
#line 5293 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12472 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 466:
#line 5298 "Gmsh.y" /* yacc.c:1652  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12481 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 467:
#line 5303 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12495 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 468:
#line 5313 "Gmsh.y" /* yacc.c:1652  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 12509 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 469:
#line 5323 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12518 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 470:
#line 5328 "Gmsh.y" /* yacc.c:1652  */
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
#line 12533 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 471:
#line 5339 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12546 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 472:
#line 5348 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strlen((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12555 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 473:
#line 5353 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12564 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 474:
#line 5358 "Gmsh.y" /* yacc.c:1652  */
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
#line 12592 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 475:
#line 5385 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = 0.; }
#line 12598 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 476:
#line 5387 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.d) = (yyvsp[0].d);}
#line 12604 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 477:
#line 5392 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = NULL; }
#line 12610 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 478:
#line 5394 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c);}
#line 12616 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 479:
#line 5399 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string struct_namespace((yyvsp[-1].c2).char1? (yyvsp[-1].c2).char1 : std::string("")),
        struct_name((yyvsp[-1].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
#line 12627 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 480:
#line 5406 "Gmsh.y" /* yacc.c:1652  */
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
#line 12644 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 481:
#line 5422 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[0].c); }
#line 12650 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 482:
#line 5424 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c2).char1 = (yyvsp[-2].c); (yyval.c2).char2 = (yyvsp[0].c); }
#line 12656 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 483:
#line 5429 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); flag_tSTRING_alloc = 1; }
#line 12662 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 484:
#line 5438 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 99; }
#line 12668 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 485:
#line 5440 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (int)(yyvsp[0].d); }
#line 12674 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 486:
#line 5445 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = 0; }
#line 12680 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 487:
#line 5447 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 12686 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 488:
#line 5452 "Gmsh.y" /* yacc.c:1652  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 12694 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 489:
#line 5456 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 12702 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 490:
#line 5460 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 12710 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 491:
#line 5464 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 12718 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 492:
#line 5468 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 12726 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 493:
#line 5475 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 12734 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 494:
#line 5479 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 12742 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 495:
#line 5483 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12750 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 496:
#line 5487 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12758 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 497:
#line 5494 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12767 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 498:
#line 5499 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12775 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 499:
#line 5506 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12784 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 500:
#line 5511 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12792 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 501:
#line 5515 "Gmsh.y" /* yacc.c:1652  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 12801 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 502:
#line 5520 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12809 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 503:
#line 5524 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12821 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 504:
#line 5532 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 12833 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 505:
#line 5543 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12841 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 506:
#line 5547 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = 0;
    }
#line 12849 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 507:
#line 5551 "Gmsh.y" /* yacc.c:1652  */
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
#line 12864 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 508:
#line 5565 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12876 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 509:
#line 5573 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 12888 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 510:
#line 5581 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 12899 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 511:
#line 5588 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 12913 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 512:
#line 5598 "Gmsh.y" /* yacc.c:1652  */
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
#line 12940 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 513:
#line 5621 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    }
#line 12949 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 514:
#line 5626 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[0].c));
    }
#line 12959 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 515:
#line 5632 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-3].i), (yyval.l));
    }
#line 12968 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 516:
#line 5637 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-1].i), (yyval.l));
      Free((yyvsp[0].c));
    }
#line 12978 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 517:
#line 5643 "Gmsh.y" /* yacc.c:1652  */
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
#line 12993 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 518:
#line 5654 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[-1].i), (yyvsp[0].l), (yyval.l));
      List_Delete((yyvsp[0].l));
    }
#line 13003 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 519:
#line 5661 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[-15].i), (yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d), (yyval.l));
    }
#line 13012 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 520:
#line 5666 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[-3].i), (yyvsp[-1].l), (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 13022 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 521:
#line 5672 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13036 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 522:
#line 5682 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13050 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 523:
#line 5692 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13064 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 524:
#line 5702 "Gmsh.y" /* yacc.c:1652  */
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
#line 13080 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 525:
#line 5714 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13088 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 526:
#line 5718 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13096 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 527:
#line 5723 "Gmsh.y" /* yacc.c:1652  */
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
#line 13112 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 528:
#line 5735 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13120 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 529:
#line 5739 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13128 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 530:
#line 5743 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 13136 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 531:
#line 5747 "Gmsh.y" /* yacc.c:1652  */
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
#line 13158 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 532:
#line 5765 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = (yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1);
	List_Add((yyval.l), &d);
      }
    }
#line 13170 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 533:
#line 5773 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = pow(10,(yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1));
	List_Add((yyval.l), &d);
      }
    }
#line 13182 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 534:
#line 5781 "Gmsh.y" /* yacc.c:1652  */
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
#line 13215 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 535:
#line 5810 "Gmsh.y" /* yacc.c:1652  */
    {
      double x0 = (yyvsp[-11].d), x1 = (yyvsp[-9].d), y0 = (yyvsp[-7].d), y1 = (yyvsp[-5].d), ys = (yyvsp[-3].d);
      int N = (int)(yyvsp[-1].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
#line 13229 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 536:
#line 5820 "Gmsh.y" /* yacc.c:1652  */
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
#line 13249 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 537:
#line 5836 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[-1].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13261 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 538:
#line 5847 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13270 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 539:
#line 5852 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13278 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 540:
#line 5856 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13286 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 541:
#line 5860 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13299 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 542:
#line 5872 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 13307 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 543:
#line 5876 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 13315 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 544:
#line 5888 "Gmsh.y" /* yacc.c:1652  */
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
#line 13336 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 545:
#line 5905 "Gmsh.y" /* yacc.c:1652  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 13347 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 546:
#line 5915 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13355 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 547:
#line 5919 "Gmsh.y" /* yacc.c:1652  */
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
#line 13371 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 548:
#line 5934 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13380 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 549:
#line 5939 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13388 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 550:
#line 5946 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13396 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 551:
#line 5950 "Gmsh.y" /* yacc.c:1652  */
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[0].c));
    }
#line 13405 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 552:
#line 5955 "Gmsh.y" /* yacc.c:1652  */
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
#line 13423 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 553:
#line 5969 "Gmsh.y" /* yacc.c:1652  */
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
#line 13441 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 554:
#line 5985 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13449 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 555:
#line 5989 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13457 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 556:
#line 5993 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13465 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 557:
#line 5997 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13473 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 558:
#line 6001 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 13485 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 559:
#line 6009 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13495 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 560:
#line 6015 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[-3].i), (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13505 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 561:
#line 6024 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13513 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 562:
#line 6028 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13521 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 563:
#line 6032 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 13533 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 564:
#line 6040 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 13543 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 565:
#line 6046 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 13553 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 566:
#line 6052 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
#line 13561 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 567:
#line 6056 "Gmsh.y" /* yacc.c:1652  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 13573 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 568:
#line 6064 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13585 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 569:
#line 6072 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 13596 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 570:
#line 6079 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13608 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 571:
#line 6088 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].c), 2);
    }
#line 13616 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 572:
#line 6092 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].c), 2);
    }
#line 13624 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 573:
#line 6096 "Gmsh.y" /* yacc.c:1652  */
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
#line 13643 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 574:
#line 6111 "Gmsh.y" /* yacc.c:1652  */
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
#line 13661 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 575:
#line 6125 "Gmsh.y" /* yacc.c:1652  */
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
#line 13679 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 576:
#line 6139 "Gmsh.y" /* yacc.c:1652  */
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
#line 13695 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 577:
#line 6151 "Gmsh.y" /* yacc.c:1652  */
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
#line 13715 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 578:
#line 6167 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13728 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 579:
#line 6176 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13741 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 580:
#line 6185 "Gmsh.y" /* yacc.c:1652  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13755 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 581:
#line 6195 "Gmsh.y" /* yacc.c:1652  */
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
#line 13770 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 582:
#line 6206 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-5].c);
      std::string out = in.substr((int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c));
    }
#line 13782 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 583:
#line 6214 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string in = (yyvsp[-3].c);
      std::string out = in.substr((int)(yyvsp[-1].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-3].c));
    }
#line 13794 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 584:
#line 6222 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13802 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 585:
#line 6226 "Gmsh.y" /* yacc.c:1652  */
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
#line 13825 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 586:
#line 6245 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13836 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 587:
#line 6252 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 13846 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 588:
#line 6258 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13857 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 589:
#line 6265 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13868 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 590:
#line 6272 "Gmsh.y" /* yacc.c:1652  */
    { init_options(); }
#line 13874 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 591:
#line 6274 "Gmsh.y" /* yacc.c:1652  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 13886 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 592:
#line 6282 "Gmsh.y" /* yacc.c:1652  */
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
#line 13911 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 593:
#line 6306 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[0].d); }
#line 13917 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 594:
#line 6308 "Gmsh.y" /* yacc.c:1652  */
    { struct_namespace = (yyvsp[-3].c); Free((yyvsp[-3].c)); (yyval.d) = (yyvsp[0].d); }
#line 13923 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 595:
#line 6314 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 13929 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 596:
#line 6319 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13935 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 597:
#line 6321 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13941 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 598:
#line 6326 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 13947 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 599:
#line 6331 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 13956 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 600:
#line 6336 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13962 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 601:
#line 6338 "Gmsh.y" /* yacc.c:1652  */
    {
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 13970 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 602:
#line 6342 "Gmsh.y" /* yacc.c:1652  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	char* c;
	List_Read((yyvsp[0].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13983 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 603:
#line 6354 "Gmsh.y" /* yacc.c:1652  */
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
#line 14001 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 604:
#line 6368 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14009 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 605:
#line 6372 "Gmsh.y" /* yacc.c:1652  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 14017 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 606:
#line 6379 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 14029 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 607:
#line 6387 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 14041 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 608:
#line 6395 "Gmsh.y" /* yacc.c:1652  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-5].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-5].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-5].c));
    }
#line 14053 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 609:
#line 6406 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14059 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 610:
#line 6408 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[0].c); }
#line 14065 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;

  case 611:
#line 6411 "Gmsh.y" /* yacc.c:1652  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 14071 "Gmsh.tab.cpp" /* yacc.c:1652  */
    break;


#line 14075 "Gmsh.tab.cpp" /* yacc.c:1652  */
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
#line 6414 "Gmsh.y" /* yacc.c:1918  */


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
