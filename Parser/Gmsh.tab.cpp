/* A Bison parser, made by GNU Bison 3.2.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.2.4"

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
#line 1 "Gmsh.y" /* yacc.c:338  */

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


#line 242 "Gmsh.tab.cpp" /* yacc.c:338  */
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
#line 166 "Gmsh.y" /* yacc.c:353  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;

#line 528 "Gmsh.tab.cpp" /* yacc.c:353  */
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
#define YYLAST   16282

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  254
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  612
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   486

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
    3042,  3057,  3085,  3097,  3106,  3113,  3125,  3144,  3148,  3153,
    3157,  3162,  3169,  3176,  3183,  3195,  3268,  3286,  3311,  3326,
    3359,  3371,  3395,  3399,  3404,  3411,  3416,  3426,  3431,  3437,
    3445,  3449,  3453,  3457,  3461,  3470,  3534,  3550,  3567,  3584,
    3606,  3628,  3663,  3671,  3679,  3685,  3692,  3699,  3719,  3745,
    3757,  3768,  3786,  3804,  3823,  3822,  3847,  3846,  3873,  3872,
    3897,  3896,  3919,  3935,  3952,  3969,  3992,  4020,  4023,  4029,
    4041,  4061,  4065,  4069,  4073,  4077,  4081,  4085,  4089,  4098,
    4111,  4112,  4113,  4114,  4115,  4119,  4120,  4121,  4122,  4123,
    4126,  4150,  4169,  4192,  4195,  4211,  4214,  4231,  4234,  4240,
    4243,  4250,  4253,  4260,  4282,  4323,  4367,  4406,  4431,  4443,
    4455,  4467,  4479,  4488,  4518,  4544,  4570,  4602,  4629,  4655,
    4681,  4707,  4733,  4755,  4766,  4814,  4868,  4883,  4895,  4906,
    4913,  4928,  4942,  4943,  4944,  4948,  4954,  4966,  4984,  5012,
    5013,  5014,  5015,  5016,  5017,  5018,  5019,  5020,  5027,  5028,
    5029,  5030,  5031,  5032,  5033,  5034,  5035,  5036,  5037,  5038,
    5039,  5040,  5041,  5042,  5043,  5044,  5045,  5046,  5047,  5048,
    5049,  5050,  5051,  5052,  5053,  5054,  5055,  5056,  5057,  5058,
    5059,  5060,  5061,  5062,  5063,  5064,  5073,  5074,  5075,  5076,
    5077,  5078,  5079,  5080,  5081,  5082,  5083,  5088,  5087,  5095,
    5097,  5102,  5107,  5111,  5116,  5121,  5125,  5129,  5133,  5137,
    5141,  5145,  5151,  5167,  5172,  5178,  5184,  5203,  5224,  5257,
    5261,  5266,  5270,  5274,  5278,  5283,  5288,  5298,  5308,  5313,
    5324,  5333,  5338,  5343,  5371,  5372,  5378,  5379,  5385,  5384,
    5407,  5409,  5414,  5423,  5425,  5431,  5432,  5437,  5441,  5445,
    5449,  5453,  5460,  5464,  5468,  5472,  5479,  5484,  5491,  5496,
    5500,  5505,  5509,  5517,  5528,  5532,  5536,  5550,  5558,  5566,
    5573,  5583,  5606,  5611,  5617,  5622,  5628,  5639,  5645,  5651,
    5657,  5667,  5677,  5687,  5699,  5703,  5708,  5720,  5724,  5728,
    5732,  5750,  5758,  5766,  5795,  5805,  5821,  5832,  5837,  5841,
    5845,  5857,  5861,  5873,  5890,  5900,  5904,  5919,  5924,  5931,
    5935,  5940,  5954,  5970,  5974,  5978,  5982,  5986,  5994,  6000,
    6006,  6012,  6021,  6025,  6029,  6037,  6043,  6049,  6053,  6061,
    6069,  6076,  6085,  6089,  6093,  6108,  6122,  6136,  6148,  6164,
    6173,  6182,  6192,  6203,  6211,  6219,  6223,  6242,  6249,  6255,
    6262,  6270,  6269,  6279,  6303,  6305,  6311,  6316,  6318,  6323,
    6328,  6333,  6335,  6339,  6351,  6365,  6369,  6376,  6384,  6392,
    6403,  6405,  6408
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

#define YYPACT_NINF -1855

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1855)))

#define YYTABLE_NINF -558

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   12041,    51,    37, 12197, -1855, -1855,  -168,    79,   -33,  -108,
     -40,    55,   214,   243,   294,   302,    83,   317,   347,   362,
     378,   161,   191,    26,   -52,   600,   -52,   230,   252,   263,
      62,   270,   275,    69,   315,   320,   356,   357,   380,   397,
     407,   419,   432,   438,   322,   470,   589,   644,   466,   403,
     620,   455,  6498,   464,   485,   505,   615,   -58,   634,    82,
     133,   707,   501,   664,   -30,   529,   348,   348,   537,   404,
      50,   546, -1855, -1855, -1855, -1855, -1855,   558,   446,   713,
     743,    35,    70,   763,   761,   137,   869,   874,   881,  5530,
     900,   688,   695,   715,    41,    81, -1855,   724,   754, -1855,
   -1855,   993,   999,   768, -1855, 11214,   772, 12402,    36,    46,
   -1855, -1855, -1855, 11320,   771, -1855, -1855, -1855, -1855, -1855,
     770, -1855, -1855, -1855, -1855, -1855, -1855, -1855, -1855, -1855,
   -1855,   -88, -1855, -1855, -1855, -1855,    53, -1855,  1013,   769,
    5286,    75,   774,  1014, 11320, 12370, 12370, -1855, 11320, -1855,
   -1855, -1855, -1855, 12370, -1855, -1855, -1855, -1855, -1855, -1855,
     773,   779,  1015, -1855, -1855,  1883,   783,   784,   785,   786,
      26, 11320, 11320, 11320,   788, 11320, 11320, 11320,   789, 11320,
   11320, 11320, 11320, 11320, 11320, 11320, 12370, 11320, 11320, 11320,
   11320,  5530,   790, -1855,  9150, -1855, -1855, -1855,   791,  5530,
    6740, 12370, -1855, -1855, -1855, -1855, -1855,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     477,   -52,   -52,   -52,   -52,   -52,   793,   -52,   -52,   794,
      82, -1855, -1855, -1855,   -52,   -52,    47,   858,   859,   860,
     796,  6740,   922,    82,    82,   802,   -52,   -52,   803,   807,
     808, -1855, -1855, -1855, 11320,  6982, 11320, 11320,  7224,    26,
     871,    48, -1855, -1855,   812, -1855,  4461, -1855, -1855, -1855,
   -1855, -1855,    96, 11320,  9150,  9150,   827,   828,  7466,  5530,
    5530,  5530, -1855, -1855, -1855, -1855, -1855, -1855, -1855, -1855,
     825,  7708,   826,  4222,  1052,  6740,   829,    41,   832,   836,
     348,   348,   348, 11320, 11320,   153, -1855,   211,   348, 10042,
     273,   -73,   831,   851,   852,   854,   855,   856,   857,  9150,
   11320,  5530,  5530,  5530,   861,    12,  1096,   863, -1855,  1097,
    1098, -1855,   862,   882,   883, -1855, -1855,   884,  5530,   892,
     893,   895, -1855, 11320,  5772, -1855,  1100,  1101, 11320, 11320,
   11320,   488, 11320,   894, -1855,   961, 11320, 11320, 11320, -1855,
   -1855, 11320, -1855,   -52,   -52,   -52,   901,   902,   903,   -52,
     -52,   -52,   -52,   -52,   -52,   -52, -1855,   -52, -1855, -1855,
   -1855,   -52,   -52,   904,   906,   -52,   907, -1855,   898,  1146,
    1147,   908, -1855, -1855,  1148,  1150,  1149,  1151,   -52, 11320,
   13898,   117, 12370,  9150, 11320, -1855, -1855,  6740,  6740, -1855,
     912,  1883,   609,  1154, -1855, -1855, -1855, -1855, -1855, -1855,
   11320, 11320,    28,  6740,  1156,   531,  1070,   915,  1158,    29,
     917, -1855,   918,  1670, 11320, -1855,  1786,   -60, -1855,    97,
     -13,  6192, -1855,    99, -1855,   104,  -176,  -166,  1077, -1855,
      26,   916, 11320, 11320, 11320, 11320,   919, 14414, 14439, 14464,
   11320, 14489, 14514, 14539, 11320, 14564, 14589, 14614, 14639, 14664,
   14689, 14714,   923, 14739, 14764, 14789,  4528,  1164, 11320,  9150,
    4505, -1855,   -75, 11320,  1170,  1172,   934, 11320, 11320, 11320,
   11320, 11320, 11320, 11320, 11320, 11320, 11320, 11320, 11320, 11320,
   11320, 11320, 11320,  9150, 11320, 11320, 11320, 11320, 11320, 11320,
    9150,  9150,   932, 11320, 11320, 12370, 11320, 12370,  6740, 12370,
   12370, 12370,   935, 11320,    60, -1855, 10121, 11320,  6740,  5530,
    6740, 12370, 12370,  9150,    26,  1883,    26,   939,  9150,   939,
   -1855,   939, 14814, -1855,     7,   936,   120,  1120, -1855,  1177,
   11320, 11320, 11320, 11320, 11320, 11320, 11320, 11320, 11320, 11320,
   11320, 11320, 11320, 11320,  7950, 11320, 11320, 11320, 11320, 11320,
      26, 11320, 11320,  1183, -1855,   666, 14839,    14,   182, 11320,
   11320, 11320, -1855,  1181,  1182,  1182,   946, 11320, 11320,  1186,
    9150,  9150, 13926,   948,  1188, -1855,   951, -1855, -1855,  -138,
   -1855, -1855,  6434,  6676,   348,   348,    75,    75,  -125, 10042,
   10042, 11320,  4275,   -15, -1855, 11320, 11320, 11320, 11320, 11320,
   11320, 11320, 11320, 11320,   185, 14864,  1193,  1195,  1197, 11320,
    1196, 11320, -1855, 11320,  4476, -1855, -1855,  9150,  9150,  9150,
   11320,  1199, 11320, 11320, 11320, 14889,   957, -1855, -1855, 14914,
   14939, 14964,  1028,  6918, -1855,   960,  4712, 14989, 15014, 14009,
   12370, 12370, 12370, 12370, 12370, 12370, 12370, 12370, 12370, 11320,
   12370, 12370, 12370, 12370,    20,  1883, 12370, 12370, 12370,    26,
      26, -1855, -1855,  9150, -1855,   962, 10483, -1855,   963, 10806,
   11320,   939, 11320, -1855,    26, 11320, 11320,  1183,   966,   249,
   15039, 12413,   964,   281, 11320,  1204,   967,   968,   972,   974,
    6740, 15064, 14036,   152,   978,  1207,  1223, -1855, -1855, -1855,
    9150,   199, -1855, -1855, -1855,    26, 11320, 11320,  1183,   984,
   -1855,   987,   -54,    82,   133,    82, -1855,   985, 13057, -1855,
     174,  9150,    26, 11320, 11320,  1228,  1230,  9150, 11320,  1233,
   12370,    26, 10358,  1228,  1234, -1855,    26,  1238, 12370, 11320,
     989,  1000, -1855, 11320,  7160,  7402,  7644,  7886,  1883,  1240,
    1241,  1242, 15089,  1243,  1244,  1246, 15114,  1247,  1248,  1249,
    1251,  1252,  1253,  1256, -1855,  1258,  1260,  1261, -1855, 11320,
   15139,  9150,   997,  9150, 13086, -1855, -1855,  1263, 13982, 13982,
   13982, 13982, 13982, 13982, 13982, 13982, 13982, 13982, 13982,  8128,
   13982, 13982, 13982, 13982,  1505,   539, 13982, 13982, 13982,  8365,
    8602,  8844,  4505,  1026,  1027,    74,  9150,  9086,  9418,   539,
    9748,   539,  1020,  1023,  1024,   346,  9150, 16039, -1855,   539,
    1029, 13115, 13144, -1855, -1855,  1030,  -115,   539,  -149,  1034,
     340,   326,  1273, -1855,  1228,   539,  1033,  1035,  4980,  5156,
     749,  1314,   594,   594,   395,   395,   395,   395,   395,   395,
     422,   422,  9150,   157, -1855,   157,   157,   939,   939,   939,
    1032, 15164, 14063,  -121,   601,  9150, -1855,  1278,  1039,  1040,
   15189, 15214, 15239, 11320,  6740,  1285,  1304,  9805, 13173, 15264,
   -1855,   494,   497,  9150,  1061, -1855, 11348, -1855, 11478, 11535,
     348, 11320, 11320, -1855, -1855,  1063,  1065, 10042,  5235,  1184,
     329,   348, 11602, 15289, 13202, 15314, 15339, 15364, 15389, 15414,
   15439, 15464,  1067,  1310, 11320,  1313, -1855, 11320, 15489, -1855,
   14090, 14117, -1855,   502,   503,   511, 13231, -1855, 14144, 14171,
    9989, -1855, -1855,  1315,  1316,  1317,  1071, 11320, 11659, 11320,
   11320, -1855, -1855,    49,   201,   240,   201,  1075,  1080,  1073,
     539,   539,  1078, 10073,   539,   539,   539,   539, 11320,   539,
    1319, -1855,  1079,  1088,   297,   633,  1090,   513, -1855, -1855,
   -1855, -1855, 13982,   157, 11726,  1085,   649,  1086,  1157,  1334,
    1189, 10444,  1093,  1099,  1339,  6740, 13260, -1855, 11320, 11320,
   11320, 11320,  1340,   156,   115,  1883, 11320,  1342,  1345,    43,
   -1855,   538,  1306,  1307,  6740,    31,  1104, 15514, 14198,   418,
   11320, 11320,  1106,  1107,  1112,  1109,  8192, -1855, -1855, -1855,
   -1855, 12370,   389,  1108, 15539, 14225, -1855,  1115, -1855,   451,
   10314, -1855, -1855, -1855,  1110, -1855,  1117, -1855,   116, -1855,
   -1855, 16039, -1855,  1358, 13982, 11320, 11320, 11320, 11320,   539,
     348,  6740,  6740,  1356,  6740,  6740,  6740,  1359,  6740,  6740,
    6740,  6740,  6740,  6740,  6740,  6740,  6740,  6740,  1966,  1368,
    9150,  4505, -1855, -1855, -1855, -1855, -1855, -1855, -1855, -1855,
   -1855, -1855, -1855, -1855, -1855, -1855, 11320, -1855, -1855, -1855,
   -1855, -1855, -1855, -1855, -1855, -1855, 11320, 11320, 11320, -1855,
   -1855, -1855,   543, 11320, 11320, -1855, 11320, -1855,  6740, 12370,
   12370, -1855,   548,  1133, -1855, -1855, -1855,  1205, 11320, 11320,
   -1855, -1855, -1855,  1228, -1855,  1228, 11320, 11320,  1143, -1855,
    6740,   -52, -1855, 11320, -1855, 11320, 11320,   550,  1228,  -121,
     -51, -1855, 11320, 11320,   539,   556,  6740,  9150,  9150,  1382,
    1383,  1384,  2735, -1855, -1855,  1386, -1855,  1155, 16039,  1140,
   -1855,  1387,  1388,  1392,   561,  1397, -1855, 11783, -1855, -1855,
     -10, 10637, 10951, -1855, -1855, 13289,  -116,  1290,  1399, 10681,
    1159,  1400,  1161,    38,    42,   -62, -1855,    -6, -1855,   329,
    1401,  1403,  1404,  1406,  1407,  1408,  1409,  1410,  1411,    75,
    6740, 16039, -1855,  2116,  1162,  1418,  1419,  1420,  1327,  1422,
   -1855,  1425,  1426, 11320,  6740,  6740,  6740,  1429, 11837, -1855,
    5211,   720,    58,  1432, -1855,  9150, -1855, -1855, -1855, -1855,
   12370, -1855, -1855, 11320, 12370, -1855, -1855, -1855, -1855, 16039,
   -1855,  1190,  1187, 12370, -1855, 12370, -1855,  1228, 12370,  1192,
   -1855,  1191, -1855,  1228, 11320, 11320,  1194,    82,  1198, 10767,
   -1855,  2518,  1200,  6740, -1855,  1201, -1855, 13318, 13347, 13376,
   13405, -1855, -1855, 11320,  1433,    32, 11320,  1439,  1441,  2791,
   -1855,  1442,    41,  1445,  1206,   539,   -52,   -52,  1447, -1855,
    1211,  1213,  1210, -1855,  1453, -1855, -1855, -1855, -1855, -1855,
    1228,   399,   721, 11320, 14252, 15564, 11320,  8429, 11320,  9150,
    1212,   563,  1454,   180,  1228, -1855,  1215, 11320,  1457, 11320,
    1228, 11004,  9387,   539,  4770,  1220,  1216, -1855,  1462, 15589,
   15614, 15639, 15664,  1464,    22,  1344,  1344,  6740,  1466,  1467,
    1469,  6740,   -94,  1479,  1480,  1481,  1482,  1487,  1488,  1490,
    1494,  1495, -1855,  1498,   566, 13982, 13982, 13982, 13982,   539,
   12397, 12430, 12463,  1262,   539,   539, -1855,  1358,   539, 15689,
   13982,  1264,  -119, 16039, 13982, -1855,  1499,   539, 12496, 16039,
   16039, -1855,   694, -1855,  1502, -1855, 15714, 14279, -1855,   539,
    1504,   585,   586,  6740,  6740,  6740,  1508,  1509, -1855,   203,
   11320,  6740,  1266,  1268,  1501,   371, -1855, 11320, 11320, 11320,
    1270,  1271,  1274,  1275, -1855,  2823,  6740, -1855, 11320, -1855,
    1518, -1855,  1519, -1855, -1855, 10042,   -20,  6014, -1855,  1279,
    1280,  1283,  1284,  1286,  1288,  8666,  1277,  1527, -1855,  9150,
   -1855, -1855, -1855,  1308, 11320, -1855, -1855, 14306,  1548,  1549,
    1381, -1855, 11320, 11320, 11320, -1855,  1556,  1557,  1558,   406,
     460,  1312,  3153,  1318, 11320,    27,   539,  1322,   539,  1320,
   -1855, -1855,  1883,   765, 11320,  1321, -1855, -1855,  2923, -1855,
   -1855,  1324,  1562, -1855, -1855, -1855, -1855,  3101, -1855,   163,
    1325,  1563,  3129, -1855, -1855, -1855,    41, -1855,   595, -1855,
   11320,   203,  1430,  2574, -1855,  1328, 11320, 11320,  6740,  1326,
   -1855,   493,  1592,  1591, 15739,  1593,  1273, 15764,  1349,   597,
   15789,   603,  1596,  1597, -1855, -1855, 12370,  1360,  1601, 15814,
   -1855, 12529,  1366, -1855,  5044, 16039, -1855,  1604,   -52,  7224,
   -1855, -1855, -1855, -1855,  1358, -1855,  1606,  1609,  1610,  1611,
   -1855, -1855,   348,  1612,  1613,  1614, -1855, -1855, -1855,  1615,
     -31,  1524,  1617, -1855, -1855, -1855, -1855, -1855, -1855, -1855,
   -1855, -1855,  1619,  1377, -1855, -1855, -1855, -1855, -1855, 11320,
   11320, 11320, -1855, -1855, -1855,  1216, -1855, -1855, -1855, -1855,
   11320,  1389,  1373, -1855, -1855, 11320, 11320, 11320,   539,  -121,
   -1855, -1855, -1855, -1855,  1385,  1396,  1625,   -94,  1626, 11320,
   -1855,  6740, 16039,  1009,  9150,  9150, 11320, -1855,  9805, 13434,
   15839,  5466,    75,    75, 11320, 11320, -1855,   891,  1394, 15864,
   -1855, -1855, 13463,   192, -1855,  1629,  1630,  6740,   348,   348,
     348,   348,   348,  6256,  1631, -1855, -1855,   604, 11320,  3284,
    1642, -1855, -1855,  6740,  5708,  1357, 15889, -1855, -1855, -1855,
   -1855,  9475, -1855, 12370, 11320, -1855, 12370, 16039,  9717,  1883,
    1398, -1855, -1855, -1855, -1855,  1405,  1402, 11320, 11320, 13492,
   11320, 12413, -1855, 12413,  6740, -1855, -1855,  1883, 11320,  1643,
    1648,    43, -1855,  1647, -1855,    41, 14333,  6740, 12370,  1651,
     539, -1855,  1412,   539, 11320, 12562, 12595,   605, -1855, 11320,
   11320,   413, -1855,  1413, -1855,  1384,  1654,  1656,  1387,  1657,
   -1855, -1855,  1660, 11320, -1855, -1855, 11320, 11083, -1855, -1855,
    1421,  2574,   606,  4438,  1661, -1855, -1855, -1855, -1855, -1855,
     236, -1855, -1855, -1855, -1855,  1423,  1424,  1428, -1855,  1662,
    6740, 13982, 13982, 12628, 13982, -1855,  1434, 12661, 15914, 14360,
   -1855, -1855,  9150,  9150, -1855,  1667, -1855, 16039,  1668,  1437,
   -1855,   613,   614, 13954,  3314,  1675,  1438, -1855, -1855, 11320,
    1440,  1443, 13521, 14387,  1676,  6740,  1681,  1446, 11320, -1855,
   -1855,   619,   194,   196,   200,   208,   219,  8908,   246, -1855,
    1685, 13550, -1855, -1855,  1520, -1855, 11320, 11320, -1855, -1855,
    9150,  3517,  1689,  1451, 13982,   539, 16039, -1855, -1855, -1855,
   -1855,    27, -1855,  1883, -1855, 13579,  1449,  1450,  1452,  1696,
    3587, -1855,  1697,  1701, -1855, -1855,  1458,  1703,   621, -1855,
    1707,  1708,   467, 16039, 11320, 11320,  1455,  6740,   622, 16039,
   15939, -1855, -1855, -1855, -1855, 15964, 12694, -1855,  1133,  1187,
    6740,   539, -1855, 11320,  1883,    26,  9150,  9150, 11320,  1709,
     627, -1855, -1855, 11320,  1373, -1855, 11320, -1855, -1855,   635,
     638, -1855, -1855,  6740,   580,   591,  9150, -1855, -1855,    75,
    5950, -1855, -1855, -1855,  1710, -1855,  1468,  6740, -1855, 13608,
    1713,  9150,   348,   348,   348,   348,   348, -1855, -1855, 11320,
   13637, 13666,   645, -1855, -1855, -1855, -1855, -1855, -1855,  1475,
    1715,  1496, -1855,  1717, -1855, -1855,    41, -1855,  1565, -1855,
   -1855, -1855, -1855, -1855, 11320, 12727, 12760,  6740, -1855,  1743,
   11320,  1503, -1855, 11320,  1506,  1507, -1855, -1855,   382, -1855,
    1510,   647,   653, 13695, -1855,  1511, 12793,  1512, 12826, -1855,
    1513,   654,  1514,   348,  6740,  1754,  1530,   348,  1773,   656,
    1535, -1855, 11320, -1855,  1779,  1653, 11850,  1543, -1855,   663,
     251,   259,   276,   300,   319,  3684, -1855, -1855,  1789,  1790,
   -1855, -1855, -1855,  1793, -1855,  1554, 16039, 11320, 11320,   673,
   -1855, 16039, 12859, -1855, -1855,  1133,  1883,  1560, -1855, -1855,
   -1855, 11320, 11320, -1855, 11320,  9150,  1800,   348,   106, -1855,
   -1855,   348,   166, -1855,  1801, -1855, 13724, -1855, 11320, -1855,
     329, -1855,  1802,  9150,  9150,  9150,  9150,  8908, -1855, -1855,
   -1855, 12413, -1855, 11320, 15989, 12892,    64, 11320,  1561, -1855,
   -1855, 12925, 12958, 12991,   674, -1855,   323, -1855,   325, -1855,
   -1855, -1855,  3877,   305, 11907, -1855,   675,   680,   711,   717,
     330,   740,  1564,   741, -1855, 11320, -1855,  6740, 13753, -1855,
   11320, 11320, 11320, -1855,   348,   348, -1855, -1855, -1855,   329,
    1803,  1805,  1808,  1809,  9150,  1810,  1811,  1812,  1571, 16014,
     742,  1815, 13782, 13982, 13024,   334,   341,   316, -1855, -1855,
   -1855, -1855,   747, -1855, -1855, -1855, 12370, -1855,  1574, -1855,
    1817, -1855, 11320, 11320, 11320, -1855,  1819,   748, -1855,  1578,
    6740, -1855, 13811, 13840, 13869, -1855,  1821, 12370, 12370,   753,
   -1855,  1822,  1823, -1855, -1855,   755, -1855,  1824, -1855, -1855,
    1825, 12370, -1855, -1855, -1855
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   610,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,     0,     0,
     192,     0,     0,   193,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,   321,   322,   323,   324,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   281,     0,     0,   289,
     290,     0,     0,     0,   284,     0,     0,     0,     0,     0,
     372,   373,   374,     0,     0,     5,     6,     7,     8,    10,
       0,    11,    24,    12,    13,    14,    15,    23,    22,    21,
      16,     0,    17,    18,    19,    20,     0,    25,     0,   611,
       0,   218,     0,     0,     0,     0,     0,   266,     0,   268,
     269,   264,   265,     0,   270,   271,   272,   273,   113,   123,
     610,   485,   480,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   274,     0,   203,   204,   205,     0,     0,
       0,     0,   426,   427,   429,   430,   428,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   434,   435,   436,     0,     0,   191,   196,   197,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,   432,   433,     0,     0,     0,     0,     0,     0,
       0,     0,   520,   521,     0,   522,   498,   379,   439,   442,
     303,   499,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   189,   196,   197,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   610,     0,     0,   218,     0,
       0,   369,     0,     0,     0,   200,   201,     0,     0,     0,
       0,     0,   506,     0,     0,   504,     0,     0,     0,     0,
       0,   610,     0,     0,   543,     0,     0,     0,     0,   262,
     263,     0,   562,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   564,     0,   588,   566,
     567,     0,     0,     0,     0,     0,     0,   565,     0,     0,
       0,     0,   282,   283,     0,   218,     0,   218,     0,     0,
       0,   480,     0,     0,     0,   218,   375,     0,     0,    76,
       0,    63,     0,     0,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,     0,   549,   480,
       0,   217,     0,   216,     0,   170,     0,     0,   549,   550,
       0,     0,   600,     0,   601,   550,   111,   111,     0,   478,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     537,   538,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   382,     0,   381,
     507,   383,     0,   500,     0,     0,   480,     0,   515,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,     0,   456,     0,     0,     0,     0,     0,
       0,     0,   304,     0,   337,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,   218,   218,     0,
     489,   488,     0,     0,     0,     0,   218,   218,     0,     0,
       0,     0,   300,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   339,     0,     0,     0,
       0,     0,   243,     0,     0,   241,   370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   347,   261,     0,
       0,     0,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,   285,     0,   248,     0,     0,   250,     0,     0,
       0,   381,     0,   218,     0,     0,     0,     0,     0,     0,
       0,   325,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    72,    73,
       0,     0,   259,    38,   255,     0,     0,     0,     0,     0,
     213,     0,     0,     0,     0,     0,   219,     0,     0,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,   483,
       0,     0,   481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   331,     0,     0,     0,   195,     0,
       0,     0,     0,     0,     0,   365,   366,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   437,   455,     0,
       0,     0,     0,   516,   517,     0,     0,     0,     0,     0,
     474,     0,   380,   501,     0,     0,     0,     0,   509,     0,
     399,   398,   396,   397,   392,   394,   393,   395,   401,   400,
     385,   384,     0,   386,   508,   387,   390,   388,   389,   391,
     481,     0,     0,   482,   459,     0,   523,     0,     0,     0,
       0,     0,     0,     0,     0,   335,     0,     0,     0,     0,
     368,     0,     0,     0,     0,   367,     0,   218,     0,     0,
       0,     0,     0,   491,   490,     0,     0,     0,     0,     0,
       0,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   354,     0,     0,   242,
       0,     0,   237,     0,     0,     0,     0,   364,     0,     0,
       0,   380,   505,     0,     0,     0,     0,     0,     0,     0,
       0,   287,   288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   591,     0,     0,     0,   476,     0,     0,   247,   251,
     249,   253,     0,   386,     0,   481,   459,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,     0,     0,   380,     0,    63,     0,     0,     0,     0,
      79,     0,    63,    64,     0,     0,   481,     0,     0,   459,
       0,     0,     0,   189,     0,     0,     0,   607,    28,    26,
      27,     0,     0,     0,     0,     0,   482,   553,    29,     0,
       0,   256,   602,   603,     0,   604,   553,    74,   114,    75,
     124,   484,   486,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   539,   540,   206,     9,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   425,   412,     0,   414,   415,   416,
     417,   418,   536,   419,   420,   421,     0,     0,     0,   528,
     527,   526,     0,     0,     0,   533,     0,   471,     0,     0,
       0,   473,     0,   128,   454,   512,   511,   199,     0,     0,
     440,   535,   445,     0,   451,     0,     0,     0,     0,   502,
       0,     0,   452,     0,   514,     0,     0,     0,     0,   444,
     443,   466,    70,    71,     0,     0,     0,     0,     0,     0,
       0,   380,   333,   338,   336,     0,   346,     0,   148,   149,
     199,   380,     0,     0,     0,     0,   238,     0,   252,   254,
       0,     0,     0,   207,   209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   307,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   218,
       0,   340,   353,     0,     0,     0,     0,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,   244,
       0,     0,     0,     0,   578,     0,   585,   574,   575,   576,
       0,   590,   589,     0,     0,   579,   580,   581,   587,   594,
     593,     0,   139,     0,   568,     0,   570,     0,     0,     0,
     563,     0,   246,     0,     0,     0,     0,     0,     0,     0,
     326,     0,     0,     0,   376,     0,   608,     0,     0,     0,
       0,   101,    63,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,    61,     0,    39,    40,    41,    42,    43,
       0,   444,   443,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   552,   551,     0,     0,     0,
       0,     0,     0,     0,   135,     0,   131,   132,     0,     0,
       0,     0,     0,     0,     0,   155,   155,     0,     0,     0,
       0,     0,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   343,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   519,     0,     0,     0,
       0,     0,   474,   475,     0,   447,     0,     0,     0,   510,
     402,   503,   460,   458,     0,   457,     0,     0,   524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   345,     0,
       0,     0,     0,     0,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,   312,     0,     0,   311,     0,   314,
       0,   316,     0,   301,   308,     0,     0,     0,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   355,     0,
     240,   239,   371,     0,     0,    35,    36,     0,     0,     0,
       0,   544,     0,     0,     0,   277,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   476,
     477,   572,     0,   460,     0,     0,   218,   327,     0,   328,
     218,     0,     0,   558,   559,   560,   561,     0,    86,     0,
       0,     0,     0,    84,    91,    93,     0,   547,     0,    99,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
      34,   460,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    31,     0,   554,     0,     0,
      32,     0,   554,   605,     0,   115,   120,     0,     0,     0,
     134,   137,   138,   479,     0,    77,     0,     0,     0,     0,
      78,   157,     0,     0,     0,     0,   158,   173,   174,     0,
       0,     0,     0,   159,   184,   175,   179,   180,   176,   177,
     178,   165,     0,     0,   413,   422,   423,   424,   529,     0,
       0,     0,   469,   470,   472,   129,   438,   468,   441,   446,
       0,     0,   474,   185,   453,     0,    70,    71,     0,   465,
     461,   463,   530,   181,     0,     0,     0,   151,     0,     0,
     344,     0,   150,     0,     0,     0,     0,   260,     0,     0,
       0,     0,   218,   218,     0,     0,   313,   498,     0,     0,
     315,   317,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,   182,     0,     0,     0,
       0,   162,   163,     0,     0,     0,     0,   102,   103,   104,
     108,     0,   586,     0,     0,   584,     0,   595,     0,     0,
     140,   141,   592,   569,   571,     0,     0,     0,     0,     0,
       0,   325,   329,   325,     0,   377,    85,    63,     0,     0,
       0,     0,    83,     0,   545,     0,     0,     0,     0,     0,
       0,   598,   597,     0,     0,     0,     0,     0,   496,     0,
       0,   465,   257,   461,   258,     0,     0,     0,     0,     0,
     223,   220,     0,     0,   557,   555,     0,     0,   116,   121,
       0,     0,     0,   537,   538,   133,   348,   349,   350,   351,
     156,   160,   161,   166,   183,     0,     0,     0,   168,     0,
       0,     0,     0,     0,     0,   448,     0,     0,     0,     0,
     525,   467,     0,     0,   167,     0,   186,   334,     0,     0,
     187,     0,     0,     0,     0,     0,     0,   495,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     234,     0,     0,     0,     0,     0,     0,     0,     0,   225,
       0,     0,   352,    37,     0,   542,     0,     0,   279,   278,
       0,     0,     0,     0,     0,     0,   143,   144,   147,   146,
     145,     0,   573,     0,   609,     0,     0,     0,     0,     0,
       0,    96,     0,     0,    97,   548,     0,     0,     0,    88,
       0,     0,     0,    44,     0,     0,     0,     0,     0,    46,
       0,   224,   221,   222,    33,     0,     0,   606,   128,   139,
       0,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,   531,   532,     0,   474,   449,     0,   462,   464,     0,
       0,   169,   190,     0,   341,   341,     0,   109,   110,   218,
       0,   210,   211,   302,     0,   309,     0,     0,   218,     0,
       0,     0,     0,     0,     0,     0,     0,   215,   214,     0,
       0,     0,     0,   105,   106,   577,   583,   582,   142,     0,
       0,     0,   330,     0,    92,    94,     0,   100,     0,    82,
     599,    89,    90,    49,     0,     0,     0,     0,   497,     0,
       0,   462,   556,     0,     0,     0,   118,   596,     0,   125,
       0,     0,     0,     0,   172,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,     0,   319,     0,     0,   296,     0,   226,     0,
       0,     0,     0,     0,     0,     0,   541,   280,     0,     0,
     363,   218,   378,     0,   546,     0,    45,     0,     0,     0,
      62,    47,     0,   117,   122,   128,     0,     0,   153,   154,
     152,     0,     0,   450,     0,     0,     0,     0,     0,   342,
     356,     0,     0,   357,     0,   208,     0,   310,     0,   292,
       0,   218,     0,     0,     0,     0,     0,     0,   164,   107,
     276,   325,    98,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,   188,     0,   360,     0,   361,
     362,   492,     0,     0,   298,   229,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,    59,     0,     0,   119,
       0,     0,     0,   306,     0,     0,   318,   297,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,   227,   332,    50,     0,    57,     0,   267,
       0,   534,     0,     0,     0,   299,     0,     0,    51,     0,
       0,   275,     0,     0,     0,   228,     0,     0,     0,     0,
     518,     0,     0,    54,    52,     0,    55,     0,   358,   359,
       0,     0,    60,    58,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1855, -1855, -1855, -1855,   490, -1855, -1855, -1855, -1855,  -239,
   -1855, -1855, -1855, -1855, -1855, -1855, -1855, -1855, -1855, -1855,
   -1855, -1855,  -713,  -134,  3954,  3148, -1855,  1390, -1855, -1855,
   -1855, -1855, -1855, -1855, -1854, -1855,   441,   265,   -49, -1855,
      -9, -1855,   204,   482,  1840, -1855,    -1,   -53, -1855, -1855,
       6,  -603,  -315, -1855, -1855, -1855, -1855, -1855, -1855, -1855,
   -1855,  1846, -1855, -1855, -1855, -1855, -1211, -1212,  1848, -1684,
    1849, -1855, -1855, -1855,  1259, -1855,   -59, -1855, -1855, -1855,
   -1855,  1965, -1855, -1855, -1381,   354,  1852, -1855,     3,  -695,
   -1855, -1855,   250, -1855, -1645,   -27,  -180,  2591,  1663,  -302,
     138, -1855,   696,   -90, -1855, -1855,   160,   327, -1643,  -152,
    1102, -1855,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   115,  1051,   116,   117,  1035,  1872,  1878,
    1325,  1535,  2025,  2157,  1326,  2128,  2175,  1327,  2159,  1328,
    1329,  1539,   433,   584,   585,  1121,   118,   766,   456,  1888,
    2035,  1889,   457,  1762,  1398,  1355,  1356,  1357,  1496,  1700,
    1701,  1187,  1592,  1583,   746,   596,   270,   271,   348,   199,
     272,   442,   443,   122,   123,   124,   125,   126,   127,   128,
     129,   273,  1219,  2060,  2119,   930,  1215,  1216,   274,  1012,
     275,   133,  1427,  1185,   905,   945,  1995,   134,   135,   136,
     137,   276,   277,  1143,  1158,  1279,   278,   771,   279,   894,
     770,   459,   611,   316,  1737,   355,   356,   281,   554,   363,
    1313,  1528,   452,   448,  1272,   989,  1572,  1730,  1731,   974,
     454,   139,   411
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   453,   120,  1454,   622,   606,   434,   301,  1456,   121,
    1026,   487,  1006,   925,   926,   399,   640,   403,  1034,   494,
     162,  1621,  1821,   644,   160,   280,   161,  1856,  1581,  1857,
     160,  1698,   723,   160,  1974,  1319,  1519,     5,   735,   335,
    1590,   404,   287,  1039,  1449,   361,   287,   160,  1451,   282,
     438,   406,   535,   558,   321,  1849,  1252,     4,   296,   416,
    1057,   147,  1486,  1775,   160,   288,   174,   144,  1066,  1042,
    2106,   764,  1208,   178,   340,   461,   341,   765,   339,   440,
     141,   767,  1776,   580,   142,   365,   282,   765,  1591,  1209,
     696,   364,   699,   143,   614,   615,  1152,  1210,  1211,  1212,
     711,  1153,   400,  1213,  1214,   580,   752,   614,   615,   593,
     594,   595,  2087,   761,  1208,   920,   614,   615,  1891,   428,
     429,   336,  1302,  1352,   306,   163,   704,   164,   927,   460,
     728,  1209,   729,  1441,  1156,  1900,   145,   439,  1149,  1210,
    1211,  1212,   449,   449,   322,  1213,  1214,   441,   323,   307,
     455,   636,   637,   638,   324,   325,   414,   326,   327,  1025,
     415,  1487,  1488,  1302,   342,   308,   309,   466,   651,  1161,
    1717,   625,  2089,   495,   802,   626,   292,   328,   803,   293,
    1048,  2078,   294,   449,   295,   750,  1555,  1453,   282,   428,
     429,   282,   163,   751,   164,    44,   282,   282,   449,  1414,
    1320,  1321,  1322,  1323,   146,  1450,  1032,   724,   725,  1452,
    1302,  1520,  1521,    65,    66,    67,    68,   614,   615,    71,
     149,  1699,   614,   615,   280,   337,   614,   615,    80,  1664,
     297,    83,   756,   298,   345,   299,   114,   346,   931,   532,
     757,  1786,   114,  1437,  1454,   114,   300,  1455,   282,   150,
     347,   114,   539,   540,   614,   615,   863,   114,   641,   114,
     803,   592,   282,   898,   142,   282,   556,   803,  1991,   428,
     429,   988,   555,   736,   599,   737,   114,  -550,   604,   738,
    1324,   282,   282,   338,   405,   282,   282,   282,   282,   362,
     916,  1312,   918,   919,   407,   536,   559,   417,   282,  1253,
     151,   418,   282,   148,   364,   728,   175,   729,   152,   932,
    1303,  1306,  2107,   179,   428,   429,   315,   317,   581,   320,
     582,  1131,  2029,   154,   583,   366,   282,   153,   282,   282,
     282,   715,   424,   425,   426,   427,   428,   429,   614,   615,
     581,   753,   582,   754,   759,   282,   583,   755,   762,   968,
     754,   282,   760,   155,   763,   428,   429,   428,   429,   853,
     163,   705,   164,   706,   163,  1305,   164,   707,   156,   424,
     425,   426,   427,   424,   425,   426,   427,  1647,  1648,   845,
     424,   425,   426,   427,   157,   614,   615,  2102,  1004,  2036,
     712,   713,   428,   429,   577,   578,   428,   429,   614,   615,
     579,   616,  1049,   428,   429,  1050,   726,   158,  1049,   449,
     282,  1050,  1690,  1691,   282,   282,  1033,   425,   426,   427,
     424,   425,   426,   427,   614,   615,   614,   615,   614,   615,
     282,   899,   614,   615,   942,   803,   739,   159,   803,  1208,
     614,   615,   747,   614,   615,  1818,   728,  1931,   729,  1932,
    1208,   614,   615,  1933,   760,   859,  1209,   772,  1401,   617,
    1402,  1934,  2130,  1208,  1210,  1211,  1212,  1209,   614,   615,
    1213,  1214,  1935,  1412,   171,  1210,  1211,  1212,   614,   615,
    1209,  1213,  1214,   614,   615,   728,   282,   729,  1210,  1211,
    1212,   614,   615,  1255,  1213,  1214,   172,   195,  1008,  1936,
     196,   842,   803,   197,  2063,   614,   615,   173,   614,   615,
     282,   592,  2064,   854,   176,  2169,   198,   282,   835,   177,
     976,   624,   449,  1987,   449,   282,   449,   449,   455,  2065,
    1014,   849,   614,   615,  1015,   282,   282,   282,   449,   449,
     282,   162,   728,   162,   729,   282,   331,   858,   332,   860,
    1275,   614,   615,  2066,  2117,   614,   615,   614,   615,   180,
     609,   610,   614,   615,   181,  2155,   614,   615,   618,   623,
     190,   282,  2067,   614,   615,  1159,  2114,   890,  2115,   803,
     311,   312,  1499,  2124,   163,   191,   164,  2153,  1503,  1027,
    1155,  1141,   313,  1156,  2154,   991,   314,   282,   282,   760,
     182,   183,  1197,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,   747,   441,   441,   184,   579,  1466,   572,   573,   702,
     575,   576,   577,   578,  1343,  1541,   311,   312,   579,   428,
     429,   185,   803,   747,   282,   282,   282,  -552,   313,  1557,
     193,   186,   319,   428,   429,  1562,   702,   575,   576,   577,
     578,  -557,  1333,   187,  1285,   579,  -553,   455,   449,   455,
     449,   449,   449,   449,   449,   449,   188,   449,   449,   449,
     449,   990,   189,   449,   449,   449,   162,   996,  1079,   192,
     282,  1044,   995,  1022,   166,   747,  1348,   167,   747,   201,
     168,  1005,   169,   716,   803,   728,   717,   729,   283,   718,
     747,   719,  1963,   803,   194,   286,  1641,   282,  1992,  1993,
    1964,   520,   200,   521,  1994,   160,   372,   282,  1484,  1996,
    1997,   289,  1036,   284,   290,  1994,   291,  1740,   662,  1708,
     142,  -554,  1043,  1192,  1045,   304,  1193,   803,   282,  1053,
     803,  1237,  1238,   285,   282,   803,   803,   455,  1064,  1171,
    1239,   305,  1281,  1068,   803,   449,   803,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   728,   310,   729,   730,
     382,   383,   384,   385,   728,   318,   729,  1315,   386,   387,
     388,   803,  1389,   389,   329,   390,   803,  1396,   282,  1411,
     282,   803,   330,   803,   302,  1419,  1718,   303,   391,   803,
    1434,   392,  1553,   333,   803,  1603,   803,  1189,  1727,   803,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,   282,  1634,  1635,   437,   579,   803,   803,
     334,   447,   450,   282,  1724,  1172,  1747,  1173,  1725,  2093,
     803,   422,  1749,  1830,  1876,  1892,   803,   803,  1877,  1893,
     343,   344,  1914,  1915,   923,   924,   803,   803,  1930,   610,
    1960,  1969,  1877,   349,   760,  1970,  1985,  1183,   350,   282,
    1877,  1454,   482,  1277,  1989,   351,  1278,  1990,   803,  1304,
    1307,   803,   282,  1284,  2018,  1285,  2038,   496,   803,   560,
     803,   282,  2039,  2046,   357,  2054,   803,  1877,  2137,   803,
     282,   728,  2062,   729,   895,   747,   803,   747,   747,   393,
     394,   395,  2076,  2113,  2120,  1454,  1877,   803,   803,  2121,
     396,   747,   358,   803,   397,  1308,   398,   114,  1626,   359,
    1627,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,   360,
    2122,   428,   429,   579,   803,  1485,  2123,   747,   367,  -551,
     803,  1542,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,  1295,  2125,
    2127,  2148,   579,   803,  1970,  1877,  2156,  2166,   368,   369,
     803,  2167,  2177,   747,  2180,   370,  1877,  1318,  2181,  1707,
    1527,  1708,   282,  1799,   371,  1800,   401,   412,   413,   419,
     445,   420,   444,   458,   460,   142,  1314,   462,   463,   464,
     465,   282,   470,   474,   488,  1413,  1415,   528,   531,   493,
    -192,  -193,  -194,   282,   537,   538,   541,   544,   449,  1810,
    1811,   545,   546,   557,  1365,  1366,   603,  1368,  1369,  1370,
     415,  1372,  1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,
    1381,   589,   590,   597,   600,   627,   732,   605,   282,   282,
     607,   282,   282,   282,   608,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   628,   629,   282,   630,   631,
     632,   633,   642,   645,   646,   639,   657,   658,   708,   643,
     647,  1393,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     648,   649,   650,  1406,   579,   282,   449,   449,   652,   653,
    1814,   654,   664,   665,   690,   673,   674,   675,   686,  1420,
     687,   689,   691,   692,   694,   697,   693,   282,   695,   698,
     714,   720,   727,   733,   734,   141,   769,   740,   794,   773,
    1200,   799,   778,   282,   282,   282,   805,  1206,   806,   807,
     836,  1217,   579,   846,   866,   867,   864,   893,   903,   904,
     907,  1711,   910,   914,   915,  1713,   747,  1413,  1415,   917,
     944,   946,   949,  1467,   947,   957,   962,   966,   969,  1013,
    1017,   998,  1000,  1007,  1029,  1018,  1019,  1478,  1479,  1480,
    1020,   839,  1021,   841,  1723,   843,   844,   282,  1028,  1030,
    1040,  1041,  1056,  1046,  1072,   441,  1058,   855,   856,  1061,
    1067,   282,   282,   282,  1069,  1100,  1073,  1080,  1081,  1082,
    1084,  1085,   282,  1086,  1088,  1089,  1090,   449,  1091,  1092,
    1093,   449,  1566,  1094,  1571,  1095,  1511,  1096,  1097,  1104,
     449,  1129,   449,  1138,  1130,   449,  1139,  1140,  1145,  1154,
    1160,  1163,  1168,  1148,  1164,  1176,  1505,  1177,  1178,  1184,
     282,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,   364,
    1186,  1195,  1203,   579,  1204,  1229,  2000,  1230,  1207,  1232,
    1258,  1247,  1244,  1245,  1246,  1259,  1260,  1570,  1271,   449,
    1364,  1263,  1273,  1274,   282,  1283,   282,  1280,  1286,  1287,
    1585,  1288,  1292,  1289,  1589,  1294,  1301,  1293,  1310,  1311,
    1336,   282,  1316,  1317,  1330,  1337,  1338,  1339,  1344,  1347,
    1350,  1351,  1354,  1367,   282,  1837,  1371,   975,   282,   977,
     978,   979,   980,   981,   982,  1383,   984,   985,   986,   987,
    1732,  1732,   992,   993,   994,  1719,  1397,  -195,  1405,  1423,
    1424,  1425,  1428,  1430,  1431,  1432,  1636,  1637,  1638,  1433,
    1429,  1435,  1442,  1443,  1643,  1448,  1447,  1446,  1457,  1458,
    1469,  1459,  1706,  1460,  1461,  1462,  1463,  1464,  1465,  1658,
     282,   282,   282,  1865,  1470,  1471,  1472,  1473,   282,  1474,
    1666,  1475,  1476,  1481,   160,   372,  1489,  1501,  1674,  1518,
    1495,  1494,  1504,   282,  1502,  1523,  1506,  1524,  1510,  1526,
    1512,  1529,  1530,  1534,   282,  1536,  1062,  1537,  1538,  1540,
    1554,  1552,   282,  1560,  1070,  1558,   282,  1573,  1575,  1574,
    1580,  1582,  1586,  1587,  1759,  1588,   373,   374,   375,   376,
     377,   378,   379,   380,   381,  1593,  1594,  1595,  1596,   382,
     383,   384,   385,  1597,  1598,  1791,  1599,   386,   387,   388,
    1600,  1601,   389,  1602,   390,  1623,  1629,  1612,  1646,  1619,
    1633,  1738,  1639,   560,  1644,  1640,  1645,   391,  1652,  1653,
     392,  1655,  1654,   364,  1660,  1661,  1675,  1667,  1668,   455,
     455,  1669,  1670,  1676,  1671,   282,  1672,  1758,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,   449,  1681,  1682,  1678,   579,  1805,  1683,
     422,   282,  1687,  1688,  1689,  1693,   282,  1703,  1715,  1710,
    1721,  1696,  1734,  1278,  1739,  1720,  1868,  1714,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,  1741,  1742,  1746,  1744,
     579,  1842,  1750,  1751,  1753,  1754,  1838,  1791,  1847,  1850,
    1757,  1760,  1766,  2006,  1798,  1767,  1768,  1769,  1771,  1772,
    1773,  1774,  1777,  1778,  1779,  1780,  1156,  1859,   393,   394,
     395,  1794,  1796,  1792,  1785,  1819,  1820,  1829,   282,   396,
    1738,   282,   282,   397,  1793,   398,   114,  1815,  1833,  1861,
    1852,  1851,  1862,  1864,  2023,  1853,  1834,  1869,   441,   441,
    1881,  -555,  1882,  1883,   282,   760,  1884,  1899,  1895,  1890,
     282,  1896,  1897,  1911,  1912,   728,  1898,   729,  1728,  1905,
     282,  1918,  1925,     7,     8,  1913,  1919,  1858,  1927,  1921,
     449,  1937,  1922,   449,  1928,  1944,  1945,  1939,  1951,  1952,
    1867,  1953,  1954,  1967,  1956,  1663,  2071,  1957,  1958,  1959,
     747,   282,   747,  1961,  1962,  1984,  2003,  2004,  1314,  2008,
    2019,  2020,   364,  2022,   282,   455,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   801,
     575,   576,   577,   578,  2021,  2024,  2094,  1342,   579,  2030,
     728,  -556,   729,  1738,  2037,  2033,  2034,  2043,   455,  2041,
    2050,  2045,  2047,  1949,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   282,  2051,  2053,
      41,    42,    43,    44,  2055,  2057,    46,  2058,  1926,   282,
     282,  2061,   749,   741,    53,  2069,  2070,    56,   742,  2072,
     743,   744,  2073,   745,  1979,  2080,  2085,  2090,  2095,  2138,
    2109,  2139,   282,  2126,  2140,  2141,  2143,  2144,  2145,  2146,
      77,  2149,  2160,  2161,   282,  2165,  2168,  2173,  2178,  2179,
    2182,  2183,  1770,  1556,  2103,  1394,  1395,   282,  1615,  1765,
    1975,  1795,  1948,   119,    91,    92,    93,   768,  1584,   130,
    1968,   131,   132,  1705,   906,   138,  1998,   492,  1848,  1863,
    1733,     0,  1063,  1976,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1738,   282,   372,     0,
       0,     0,  1980,   282,   282,     0,     0,     0,     0,     0,
    2005,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,     0,     0,   282,     0,     0,     0,     0,  1822,  1823,
    1824,  1825,  1826,  1828,   282,   441,     0,     0,   282,   373,
     374,   375,   376,   377,   378,   379,   380,   381,     0,     0,
    1738,     0,   382,   383,   384,   385,  2079,   587,   588,     0,
     386,   387,   388,   364,     0,   389,  1491,   390,     0,     0,
    1493,     0,     0,     0,   282,     0,     0,  2049,     0,  1497,
     391,  1498,  1382,   392,  1500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,   634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   747,     0,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,  1543,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,   282,   282,   282,   282,     0,     0,     0,     0,     0,
     747,     0,     0,     0,     0,     0,   709,     0,   410,     0,
    1738,   393,   394,   395,     0,     0,     0,     0,     0,     0,
       0,     0,   396,   747,     0,     0,   397,     0,   398,     0,
       0,     0,     0,     0,   282,   436,     0,     0,     0,   446,
       0,     0,     0,   451,     0,     0,     0,     0,     0,     0,
       0,   282,  1468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1738,     0,     0,   467,   468,   469,     0,
     471,   472,   473,   449,   475,   476,   477,   478,   479,   480,
     481,     0,   483,   484,   485,   486,     0,   282,     0,   490,
       0,     0,     0,     0,   449,   449,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   449,     0,
       0,     0,  2010,  2011,  2012,  2013,  2014,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,   861,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   547,
     549,   551,   552,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2048,     0,     0,     0,  2052,   586,   490,
     490,     0,  1752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   911,   912,     0,     0,     0,   602,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   612,   613,
       0,     0,     0,     0,   613,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   490,   635,     0,  2086,     0,     0,
       0,  2088,     0,     0,     0,     0,     0,     0,     0,     0,
     953,   954,   955,     0,     0,     0,     0,  2100,   655,   490,
       0,     0,     0,   659,   660,   661,     0,   663,     0,     0,
       0,   666,   667,   668,     0,     0,   669,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,   997,     0,     0,   579,
       0,     0,     0,     0,  2135,  2136,     0,     0,     0,     0,
       0,     0,     0,     0,   701,     0,     0,     0,   490,   710,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1843,
       0,     0,  1845,  1031,     0,   721,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   748,
       0,     0,     0,     0,  1052,     0,     0,     0,     0,     0,
    1059,     0,     0,     0,     0,     0,     0,   774,   775,   776,
     777,     0,     0,     0,     0,   782,     0,     0,     0,   786,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   800,   549,     0,     0,     0,   804,     0,
       0,     0,   808,   809,   810,   811,   812,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   822,   823,   824,   826,
     827,   828,   829,   830,   831,   832,   832,     0,   837,   838,
       0,   840,     0,     0,     0,     0,     0,     0,   847,  1132,
       0,   851,   852,     0,     0,     0,     0,     0,   832,  1142,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1509,   868,   869,   870,   871,   872,
     873,   874,   875,   876,   877,   878,   879,   880,   881,   883,
     885,   886,   887,   888,   889,  1167,   891,   892,     0,     0,
       0,     0,     0,     0,   900,   901,   902,     0,  1175,     0,
       0,     0,   908,   909,     0,   490,   490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1194,     0,   160,   372,
       0,     0,     0,     0,   547,   701,   928,     0,     0,     0,
     933,   934,   935,   936,   937,   938,   939,   940,   941,     0,
       0,     0,     0,     0,   948,     0,   950,     0,   951,     0,
       0,     0,   490,   490,   490,   956,     0,   958,   959,   960,
     373,   374,   375,   376,   377,   378,   379,   380,   381,     0,
       0,     0,     0,   382,   383,   384,   385,     0,     0,     0,
       0,   386,   387,   388,   983,     0,   389,     0,   390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   490,     0,
       0,   391,     0,     0,   392,  1002,     0,  1003,     0,     0,
     891,   892,     0,     0,     0,     0,     0,     0,     0,  1016,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,  1037,  1038,     0,   422,     0,     0,     0,     0,  1341,
       0,     0,     0,     0,     0,     0,   490,     0,  1054,  1055,
       0,     0,   490,  1060,     0,     0,     0,  1054,     0,     0,
       0,     0,     0,     0,  1071,     0,     0,     0,  1074,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,  1384,  1098,     0,   883,     0,  1101,     0,
       0,     0,   393,   394,   395,     0,     0,     0,     0,     0,
       0,     0,     0,   396,     0,   491,     0,   397,     0,   398,
     114,     0,     0,     0,     0,     0,     0,  1525,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1728,     0,     0,     0,     0,     0,     0,  1656,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1421,  1422,  2158,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,     0,     0,   550,     0,     0,   491,
     490,     0,     0,  2174,  2176,     0,     0,     0,  1182,  1426,
       0,     0,  1188,     0,     0,   491,   491,  2184,   490,     0,
       0,     0,     0,     0,     0,     0,  1201,  1202,     0,     0,
       0,     0,  1205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1231,
       0,     0,  1233,     0,     0,     0,     0,     0,  1490,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,  1712,
       0,     0,  1248,     0,  1250,  1251,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,     0,     0,     0,     0,
       0,     0,     0,  1269,     0,     0,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,  1291,     0,   579,     0,
       0,     0,     0,  1297,  1298,  1299,  1300,     0,     0,     0,
       0,  1309,     0,     0,     0,     0,     0,     0,     0,     0,
    1549,     0,  1551,     0,   491,  1334,  1335,     0,     0,     0,
       0,   490,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
    1359,  1360,  1361,  1362,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,   490,   579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     550,  1385,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1386,  1387,  1388,     0,     0,     0,     0,  1390,  1391,
       0,  1392,     0,     0,   825,     0,     0,  1716,     0,     0,
       0,   833,   834,  1399,  1400,     0,     0,     0,     0,     0,
       0,  1403,  1404,     0,     0,     0,     0,     0,  1408,     0,
    1409,  1410,  1677,     0,   857,  1722,     0,  1416,  1417,   491,
       0,     0,   490,   490,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,   884,   579,     0,     0,     0,
       0,     0,     0,     0,  1445,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,   491,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     490,     0,     0,     0,     0,     0,     0,     0,  1492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,   491,
     491,     0,     0,     0,     0,     0,     0,     0,     0,  1416,
    1417,     0,     0,     0,  1508,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1517,     0,
       0,  1522,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,     0,     0,     0,     0,     0,
    1832,     0,     0,     0,     0,     0,     0,     0,  1544,     0,
       0,  1547,   490,  1550,   490,     0,     0,  1801,  1802,     0,
       0,     0,  1559,     0,  1561,     0,  1559,  1565,     0,     0,
    1917,   491,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,   491,     0,   579,     0,     0,     0,   491,     0,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,   884,     0,  1102,  1642,   579,     0,   728,     0,
     729,     0,  1649,  1650,  1651,     0,  1694,     0,     0,     0,
       0,  1657,     0,  1659,     0,     0,     0,     0,     0,     0,
    1662,     0,     0,     0,     0,     0,     0,   491,     0,     0,
       0,     0,     0,     0,   490,     0,     0,   491,     0,  1679,
       0,     0,     0,     0,     0,     0,     0,  1684,  1685,  1686,
       0,     0,     0,     0,     0,  1909,  1910,     0,     0,  1697,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1709,
       0,     0,     0,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,     0,     0,     0,
       0,     0,     0,     0,     0,  1726,     0,     0,     0,     0,
       0,  1735,  1736,  1942,   491,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,  1943,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,  1763,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1981,
    1982,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1781,  1782,  1783,     0,     0,  1999,
       0,     0,     0,   731,     0,  1784,     0,     0,     0,     0,
    1787,  1788,  1789,  1955,  2009,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1797,     0,     0,     0,     0,   490,
     490,  1803,     0,  1804,     0,     0,     0,     0,     0,  1812,
    1813,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   491,   490,     0,
       0,     0,     0,  1831,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1841,     0,     0,  1844,
       0,     0,     0,  1846,     0,     0,     0,     0,     0,     0,
       0,     0,  1788,  1789,     0,  1855,     0,     0,     0,     0,
       0,     0,   848,  1860,     0,     0,     0,     0,     0,     0,
    2068,   491,     0,     0,     0,     0,     0,     0,     0,  1873,
       0,     0,     0,     0,  1879,  1880,     0,     0,  2084,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1885,     0,
       0,  1886,  1885,     0,     0,     0,  2096,  2097,  2098,  2099,
    2101,     0,     0,   896,     0,     0,     0,     0,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,   490,   490,     0,
     579,     0,     0,     0,     0,     0,     0,     0,   491,   491,
       0,     0,     0,     0,  1920,     0,     0,     0,     0,     0,
       0,     0,     0,  1929,     0,     0,     0,  2142,     0,     0,
       0,     0,   549,     0,     0,     0,     0,     0,     0,     0,
       0,  1940,  1941,     0,     0,   490,     0,     0,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,     0,     0,     0,     0,     0,     0,     0,     0,  1965,
    1966,     0,     0,     0,     0,     0,   491,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1978,     0,
       0,   490,   490,  1983,     0,     0,     0,     0,  1986,     0,
       0,  1988,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   490,     0,  2116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,     0,  2015,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,   491,  2026,
     491,     0,     0,     0,     0,  2031,     0,     0,  2032,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  1114,  1115,  2056,  1117,  1118,
    1119,  1120,     0,  1122,  1123,  1124,  1125,     0,   165,     0,
     170,     0,     0,     0,     0,     0,     0,  1135,     0,  1137,
       0,     0,  2074,  2075,     0,     0,     0,  1144,     0,     0,
       0,     0,     0,     0,  1150,  1151,  2081,  2082,     0,  2083,
     490,     0,     0,  1162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2092,     0,     0,     0,     0,   490,   490,
     490,   490,   490,     0,     0,     0,     0,     0,  1879,     0,
       0,     0,  2108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2129,     0,     0,     0,     0,  2132,  2133,  2134,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   490,
       0,     0,     0,     0,   435,     0,     0,     0,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,  2162,  2163,  2164,
     579,     0,  1254,  1256,  1257,     0,     0,     0,  1261,  1262,
       0,     0,  1265,  1266,  1267,  1268,     0,  1270,     0,     0,
       0,     0,  1276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1764,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   522,   523,   524,   525,   526,   527,
       0,   529,   530,     0,     0,     0,     0,     0,   533,   534,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     542,   543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1358,     0,     0,   202,   160,  1363,     0,     0,
       0,     0,   203,   204,   205,   491,   491,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   408,   224,   225,   226,   227,   228,
     229,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   237,
     238,     0,     0,     0,     0,   239,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,   244,    23,     0,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1418,     0,     0,     0,     0,   670,   671,   672,
       0,     0,     0,   676,   677,   678,   679,   680,   681,   682,
       0,   683,     0,     0,     0,   684,   685,     0,     0,   688,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   700,     0,     0,     0,     0,     0,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,   491,   491,    41,    42,    43,    44,     0,
       0,    46,     0,     0,     0,     0,     0,     0,   741,    53,
       0,     0,    56,   742,     0,   743,   744,     0,   745,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   550,   255,
       0,     0,     0,   256,     0,    77,     0,     0,   258,   259,
     260,   491,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,  1894,   560,     0,     0,    91,
      92,    93,     0,     0,   264,   409,     0,     0,     0,     0,
       0,   266,     0,  1531,     0,     0,   353,     0,     0,   560,
     601,     0,     0,   269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   491,   491,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1567,     0,     0,     0,     0,     0,   491,     0,     0,
     865,     0,     0,   560,     0,     0,     0,     0,     0,     0,
       0,     0,   491,     0,   929,     0,     0,     0,     0,     0,
       0,     0,     0,  1604,  1605,  1606,  1607,  1608,     0,     0,
       0,     0,  1613,  1614,     0,     0,  1616,     0,  1618,     0,
       0,     0,  1622,     0,     0,  1624,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1632,     0,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     0,     0,     0,    41,    42,    43,    44,
       0,     0,    46,     0,     0,     0,     0,     0,     0,   741,
      53,     0,     0,    56,   742,     0,   743,   744,     0,   745,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,     0,  1692,     0,
    1695,     0,     0,     0,  1702,     0,  1704,     0,     0,     0,
      91,    92,    93,     0,   491,   491,   491,   491,   491,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   801,   575,   576,   577,   578,     0,     0,     0,
    1729,   579,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,     0,     0,     0,     0,
     970,     0,     0,     0,     0,   952,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   801,
     575,   576,   577,   578,     0,     0,     0,     0,   579,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,   202,     6,   372,  1790,   798,     0,     0,
     203,   204,   205,     0,     0,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,  1157,     0,  1568,   374,   375,   376,
     377,   378,   379,   380,   381,   235,   236,   237,   238,   382,
     383,   384,   385,   239,   240,     0,     0,   386,   387,   388,
       0,     0,   389,     0,   390,   241,   242,   243,  1174,     0,
       0,     0,     0,     0,     0,   244,    23,   391,   245,     0,
     392,     0,     0,     0,   246,     0,     0,   247,     0,     0,
     248,     0,   249,     0,     0,     0,     0,     0,  1870,    40,
       0,  1871,     0,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,    54,    55,     0,   252,     0,
     253,     0,     0,   254,     0,     0,     0,     0,    65,    66,
      67,    68,    69,     0,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    80,     0,     0,    83,     0,     0,  1901,
    1902,     0,  1904,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   393,   394,
     395,   256,   257,     0,     0,     0,   258,   259,   260,   396,
     261,   262,   263,   397,     0,   398,   114,     0,  1165,     0,
       0,     0,  1946,  1947,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   353,     0,     0,     0,  1569,     0,
       0,   269,  1353,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1977,
       0,     0,     0,     0,     0,     0,     0,   202,     6,   372,
       0,     0,     0,     0,   203,   204,   205,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     0,     0,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   235,
     236,   237,   238,   382,   383,   384,   385,   239,   240,     0,
       0,   386,   387,   388,     0,  1407,   389,     0,   390,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,   244,
      23,   391,   245,     0,   392,     0,     0,     0,   246,     0,
       0,   247,     0,     0,   248,     0,   249,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,  1166,     0,     0,   251,     0,    54,
      55,     0,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,    71,    72,
      73,    74,    75,    76,     0,     0,     0,    80,     0,     0,
      83,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,  1483,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   393,   394,   395,   256,   257,     0,     0,     0,
     258,   259,   260,   396,   261,   262,   263,   397,     0,   398,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1532,  1533,     0,     0,     0,     0,   264,   265,     0,     0,
       0,  2151,     0,   266,     0,     0,     0,     0,   353,   202,
     160,   372,   268,   421,     0,   269,   203,   204,   205,     0,
       0,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   408,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
       0,     0,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   235,   236,   237,   238,   382,   383,   384,   385,   239,
       0,     0,     0,   386,   387,   388,  1620,     0,   389,     0,
     390,   241,   242,   243,     0,     0,  1628,     0,     0,     0,
       0,   244,    23,   391,   245,     0,   392,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,   423,     0,   579,     0,
     961,     0,     0,   255,   393,   394,   395,   256,   921,     0,
       0,     0,   258,   259,   260,   396,   261,   262,   263,   397,
       0,   398,   114,   424,   425,   426,   427,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   409,
       0,     0,  1761,     0,     0,   266,   428,   429,     0,     0,
     430,     0,   431,   202,     6,   352,   432,   269,     0,     0,
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
       0,     0,     0,    80,     0,     0,    83,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,  1808,     0,     0,     0,  1809,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   256,   257,     0,     0,     0,   258,   259,   260,     0,
     261,   262,   263,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   353,   202,     6,     0,   354,     0,
     656,   269,   203,   204,   205,     0,     0,   206,   207,   208,
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
      75,    76,     0,     0,     0,    80,     0,     0,    83,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,  1835,     0,     0,
       0,  1836,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,   256,   257,     0,     0,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   489,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   353,   202,     6,  1665,
       0,   553,     0,   269,   203,   204,   205,     0,     0,   206,
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
      83,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,  2001,
       0,     0,     0,  2002,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,   256,   257,     0,     0,     0,
     258,   259,   260,     0,   261,   262,   263,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   265,     0,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   353,   202,
       6,     0,   268,     0,     0,   269,   203,   204,   205,     0,
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
       0,     0,    83,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   758,     0,     0,     0,     0,
       0,     0,     0,   255,     0,     0,     0,   256,   257,     0,
       0,     0,   258,   259,   260,     0,   261,   262,   263,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   619,  1827,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
     621,   202,     6,     0,   314,   553,     0,   269,   203,   204,
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
       0,    80,     0,     0,    83,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   921,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,   256,
     257,     0,     0,     0,   258,   259,   260,     0,   261,   262,
     263,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   267,   202,     6,     0,   268,     0,     0,   269,
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
       0,     0,     0,    80,     0,     0,    83,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   922,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   256,   257,     0,     0,     0,   258,   259,   260,     0,
     261,   262,   263,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   353,   202,     6,     0,   268,     0,
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
      75,    76,     0,     0,     0,    80,     0,     0,    83,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   967,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,   256,   257,     0,     0,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   489,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   353,   202,     6,     0,
     548,     0,     0,   269,   203,   204,   205,     0,     0,   206,
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
      83,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1075,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,   256,   257,     0,     0,     0,
     258,   259,   260,     0,   261,   262,   263,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   489,     0,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   353,   202,
       6,     0,     0,   553,     0,   269,   203,   204,   205,     0,
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
       0,     0,    83,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1076,     0,     0,     0,     0,
       0,     0,     0,   255,     0,     0,     0,   256,   257,     0,
       0,     0,   258,   259,   260,     0,   261,   262,   263,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
     591,   202,     6,     0,   268,     0,     0,   269,   203,   204,
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
       0,    80,     0,     0,    83,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1077,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,   256,
     257,     0,     0,     0,   258,   259,   260,     0,   261,   262,
     263,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   598,   202,     6,     0,   268,     0,     0,   269,
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
       0,     0,     0,    80,     0,     0,    83,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1078,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   256,   257,     0,     0,     0,   258,   259,   260,     0,
     261,   262,   263,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   489,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   353,   202,     6,     0,   882,     0,
    1340,   269,   203,   204,   205,     0,     0,   206,   207,   208,
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
      75,    76,     0,     0,     0,    80,     0,     0,    83,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1116,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,   256,   257,     0,     0,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   489,     0,     0,     0,     0,
       0,   266,   202,     6,     0,     0,   353,  1548,     0,   203,
     204,   205,     0,   269,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,   237,   238,     0,     0,
       0,     0,   239,   240,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   242,   243,     0,     0,     0,
       0,     0,     0,     0,   244,    23,     0,   245,     0,     0,
       0,     0,     0,   246,     0,     0,   247,     0,     0,   248,
       0,   249,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,     0,    54,    55,     0,   252,     0,   253,
       0,     0,   254,     0,     0,     0,     0,    65,    66,    67,
      68,    69,     0,    71,    72,    73,    74,    75,    76,     0,
       0,     0,    80,     0,     0,    83,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,     0,     0,   579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1126,     0,
       0,     0,     0,     0,     0,     0,   255,     0,     0,     0,
     256,   257,     0,     0,     0,   258,   259,   260,     0,   261,
     262,   263,     0,     0,     0,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   489,     0,     0,     0,     0,     0,   266,   202,
       6,     0,     0,   353,     0,     0,   203,   204,   205,     0,
     269,   206,   207,   208,   209,   210,   211,   212,   213,   214,
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
       0,     0,    83,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1127,     0,     0,     0,     0,
       0,     0,     0,   255,     0,     0,     0,   256,   257,     0,
       0,     0,   258,   259,   260,     0,   261,   262,   263,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
       0,     0,     0,     0,     0,   266,     0,     0,     0,     0,
     353,   202,     6,     0,  1673,     0,     0,   269,   203,   204,
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
       0,    80,     0,     0,    83,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1128,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,     0,   256,
     257,     0,     0,     0,   258,   259,   260,     0,   261,   262,
     263,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     619,  1827,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,   621,   202,     6,     0,   314,     0,     0,   269,
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
       0,     0,     0,    80,     0,     0,    83,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1133,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   256,   257,     0,     0,     0,   258,   259,   260,     0,
     261,   262,   263,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   489,     0,     0,     0,     0,     0,   266,
     202,   160,   372,     0,   353,     0,     0,   203,   204,   205,
       0,   269,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   408,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   235,   236,   237,   238,   382,   383,   384,   385,
     239,     0,     0,     0,   386,   387,   388,     0,     0,   389,
       0,   390,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,   244,    23,   391,   245,     0,   392,   202,   160,
     372,     0,     0,     0,     0,   203,   204,   205,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   408,   224,   225,
     226,   227,   228,   229,     0,     0,     0,     0,     0,     0,
       0,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     235,   236,   237,   238,   382,   383,   384,   385,   239,     0,
       0,     0,   386,   387,   388,     0,     0,   389,     0,   390,
     241,   242,   243,     0,     0,     0,     0,     0,     0,     0,
     244,    23,   391,   245,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   393,   394,   395,   256,     0,
       0,     0,     0,   258,   259,   260,   396,   261,   262,   263,
     397,     0,   398,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     409,     0,     0,     0,     0,     0,   266,     0,     0,     0,
       0,   353,     0,     0,     0,  1564,     0,     0,   269,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1134,   255,   393,   394,   395,   256,     0,     0,     0,
       0,   258,   259,   260,   396,   261,   262,   263,   397,     0,
     398,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   409,     0,
       0,     0,     0,     0,   266,     0,     0,     0,     0,   353,
     202,   160,   372,  1840,     0,     0,   269,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   408,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,  1568,   374,   375,   376,   377,   378,   379,
     380,   381,   235,   236,   237,   238,   382,   383,   384,   385,
     239,     0,     0,     0,   386,   387,   388,     0,     0,   389,
       0,   390,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,   244,    23,   391,   245,     0,   392,   202,   160,
     372,     0,     0,     0,     0,   203,   204,   205,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   408,   224,   225,
     226,   227,   228,   229,     0,     0,     0,     0,     0,     0,
       0,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     235,   236,   237,   238,   382,   383,   384,   385,   239,     0,
       0,     0,   386,   387,   388,     0,     0,   389,     0,   390,
     241,   242,   243,     0,     0,     0,     0,     0,     0,     0,
     244,    23,   391,   245,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   393,   394,   395,   256,     0,
       0,     0,     0,   258,   259,   260,   396,   261,   262,   263,
     397,     0,   398,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     409,     0,     0,     0,     0,     0,   266,     0,     0,     0,
       0,   353,     0,     0,     0,  1728,     0,     0,   269,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1136,   255,   393,   394,   395,   256,     0,     0,     0,
       0,   258,   259,   260,   396,   261,   262,   263,   397,     0,
     398,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   409,     0,
       0,     0,     0,     0,   266,   202,   160,     0,     0,   353,
       0,     0,   203,   204,   205,     0,   269,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   408,   224,   225,   226,   227,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   237,
     238,     0,     0,     0,     0,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   242,   243,
       0,     0,     0,     0,   202,   160,     0,   244,    23,   850,
     245,   203,   204,   205,     0,     0,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   408,   224,   225,   226,   227,   228,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,   236,   237,   238,
       0,     0,     0,     0,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,   242,   243,     0,
       0,     0,     0,     0,     0,     0,   244,    23,     0,   245,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,     0,   255,
       0,     0,  1243,   256,     0,     0,     0,     0,   258,   259,
     260,     0,   261,   262,   263,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,     0,     0,     0,     0,
       0,   266,     0,     0,     0,     0,   621,     0,     0,     0,
     314,     0,     0,   269,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,     0,   579,     0,   255,     0,
       0,     0,   256,     0,     0,     0,  1264,   258,   259,   260,
       0,   261,   262,   263,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   409,     0,     0,     0,     0,     0,
     266,   202,   160,     0,     0,   353,     0,     0,   203,   204,
     205,     0,   269,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     408,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   235,   236,   237,   238,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,   244,    23,     0,   245,   202,   160,     0,
    1290,     0,     0,     0,   203,   204,   205,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   408,   224,   225,   226,
     227,   228,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,   235,
     236,   237,   238,     0,     0,     0,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,   244,
      23,     0,   245,     0,     0,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,   255,     0,   579,     0,   256,
       0,     0,     0,     0,   258,   259,   260,  1349,   261,   262,
     263,     0,     0,     0,   114,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     264,   409,     0,    41,    42,    43,    44,   266,     0,    46,
       0,     0,   353,  1065,     0,     0,   741,    53,     0,   269,
      56,   742,     0,   743,   744,     0,   745,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,   256,     0,     0,     0,     0,
     258,   259,   260,     0,   261,   262,   263,    91,    92,    93,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   409,     0,     0,
       0,     0,     0,   266,   202,   160,     0,  1444,   353,     0,
       0,   203,   204,   205,     0,   269,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   408,   224,   225,   226,   227,   228,   229,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   999,     0,     0,     0,   235,   236,   237,   238,
       0,     0,     0,     0,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,   242,   243,     0,
       0,     0,     0,     0,     0,     0,   244,    23,     0,   245,
     202,   160,     0,  1507,     0,     0,     0,   203,   204,   205,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   408,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,   235,   236,   237,   238,     0,     0,     0,     0,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,   244,    23,     0,   245,     0,     0,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,   255,     0,
     579,     0,   256,     0,     0,     0,     0,   258,   259,   260,
    1438,   261,   262,   263,     0,     0,     0,   114,     0,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,   264,   409,     0,    41,    42,    43,    44,
     266,     0,    46,     0,     0,   353,     0,     0,     0,   741,
      53,     0,   269,    56,   742,     0,   743,   744,     0,   745,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,     0,   256,     0,
       0,     0,     0,   258,   259,   260,     0,   261,   262,   263,
      91,    92,    93,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     409,     0,     0,     0,     0,     0,   266,   202,   160,     0,
       0,   353,     0,     0,   203,   204,   205,     0,   269,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   408,   224,   225,   226,
     227,   228,   229,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1001,     0,     0,     0,   235,
     236,   237,   238,     0,     0,     0,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,     0,     0,     0,     0,   202,   160,     0,   244,
      23,     0,   245,   203,   204,   205,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   408,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     237,   238,     0,     0,     0,     0,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   242,
     243,     0,     0,     0,     0,     0,     0,     0,   244,    23,
       0,   245,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
       0,   255,     0,     0,  1439,   256,     0,     0,     0,     0,
     258,   259,   260,     0,   261,   262,   263,     0,   160,   372,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   409,     0,     0,
       0,     0,     0,   266,     0,     0,     0,     0,   353,  1563,
       0,     0,     0,     0,     0,   269,     0,     0,     0,     0,
     373,   374,   375,   376,   377,   378,   379,   380,   381,     0,
       0,     0,     0,   382,   383,   384,   385,     0,     0,     0,
     255,   386,   387,   388,   256,     0,   389,     0,   390,   258,
     259,   260,     0,   261,   262,   263,     0,     0,     0,   114,
       0,   391,     0,     0,   392,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,   409,     0,     0,     0,
       0,     0,   266,   202,   160,     0,     0,   353,  1887,     0,
     203,   204,   205,     0,   269,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   408,   224,   225,   226,   227,   228,   229,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   236,   237,   238,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,   244,    23,     0,   245,     0,
       0,     0,   393,   394,   395,     0,     0,     0,     0,     0,
       0,     0,     0,   396,     0,     0,     0,   397,     0,   398,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,     0,     0,    41,    42,
      43,    44,     0,     0,    46,     0,     0,     0,     0,     0,
       0,   741,    53,     0,     0,    56,   742,     0,   743,   744,
       0,   745,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   256,    91,    92,    93,     0,   258,   259,   260,     0,
     261,   262,   263,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,   264,   409,     0,     0,     0,     0,     0,   266,
       0,     0,     0,     0,   353,     0,     0,     0,     0,     0,
       0,   269,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,     0,     0,    41,    42,
      43,    44,     0,     0,    46,     0,     0,  1196,     0,     0,
       0,   741,    53,     0,     0,    56,   742,     0,   743,   744,
       0,   745,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,     0,     0,    41,    42,    43,    44,     0,
       0,    46,    91,    92,    93,     0,     0,     0,   741,    53,
       0,     0,    56,   742,     0,   743,   744,     0,   745,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    91,
      92,    93,    41,    42,    43,    44,     0,     0,    46,     0,
       0,     0,     0,     0,     0,   741,    53,  1198,     0,    56,
     742,     0,   743,   744,     0,   745,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,    41,
      42,    43,    44,     0,     0,    46,    91,    92,    93,     0,
       0,     0,   741,    53,  1199,     0,    56,   742,     0,   743,
     744,     0,   745,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    91,    92,    93,    41,    42,    43,    44,
       0,     0,    46,     0,     0,     0,     0,     0,     0,   741,
      53,  1218,     0,    56,   742,     0,   743,   744,     0,   745,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,     0,     0,    41,    42,    43,    44,     0,     0,    46,
      91,    92,    93,     0,     0,     0,   741,    53,  1249,     0,
      56,   742,     0,   743,   744,     0,   745,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    91,    92,    93,
      41,    42,    43,    44,     0,     0,    46,     0,     0,     0,
       0,     0,     0,   741,    53,  1282,     0,    56,   742,     0,
     743,   744,     0,   745,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,     0,     0,    41,    42,    43,
      44,     0,     0,    46,    91,    92,    93,     0,     0,     0,
     741,    53,  1436,     0,    56,   742,     0,   743,   744,     0,
     745,    -4,     1,     0,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,     0,    77,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,    91,    92,    93,     0,    -4,    -4,     0,     0,     0,
    1482,     0,     0,     0,     0,     0,     0,     0,     0,  2059,
       0,     0,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,  2118,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     6,     0,    -4,    -4,    -4,     0,     0,     0,    -4,
       7,     8,     0,     0,    -4,    -4,    -4,    -4,     0,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,     9,    10,     0,    -4,    -4,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,     0,    -4,     0,     0,
       0,    11,    12,    13,     0,     0,     0,    14,    15,     0,
      16,     0,     0,     0,     0,    17,    18,    19,    20,     0,
      21,    22,     0,    23,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,     0,    40,    41,    42,    43,
      44,    45,     0,    46,     0,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,    86,
      87,    88,     0,     0,     0,    89,     0,     0,     0,     0,
      90,    91,    92,    93,   160,   372,    94,     0,    95,     0,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     110,   111,   112,     0,     0,     0,   402,   372,     0,     0,
       0,   113,     0,   114,     0,     0,   373,   374,   375,   376,
     377,   378,   379,   380,   381,     0,     7,     8,     0,   382,
     383,   384,   385,     0,     0,     0,     0,   386,   387,   388,
       0,     0,   389,     0,   390,     0,     0,     0,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   391,     0,     0,
     392,   382,   383,   384,   385,     0,     0,     0,     0,   386,
     387,   388,     0,     0,   389,     0,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   391,
       0,     0,   392,     0,     0,     0,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,     0,     0,    41,    42,    43,    44,     0,     0,    46,
       0,     0,     0,     0,     0,     0,   741,    53,     0,     0,
      56,   742,     0,   743,   744,     0,   745,     0,     0,     0,
    1010,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,  1011,   393,   394,
     395,     0,     0,     0,     0,     0,     0,     0,     0,   396,
       0,     0,     0,   397,     0,   398,   114,    91,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     393,   394,   395,     0,     0,     0,     0,     0,     0,     0,
       0,   396,     0,     0,     0,   397,     0,   398,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1609,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1610,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,     0,   579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1611,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1625,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1756,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1874,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,     0,     0,   579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1875,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1903,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1906,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1973,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2027,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2028,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,     0,   579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2042,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2044,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2077,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2105,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,     0,     0,   579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2110,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2111,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2112,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2152,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,     0,     0,     0,     0,     0,  1047,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,  1103,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,     0,     0,   579,     0,
       0,     0,     0,     0,  1146,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,  1147,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,     0,   579,     0,     0,     0,
       0,     0,  1190,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,  1221,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
    1240,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,  1296,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,  1440,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,  1513,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,     0,     0,     0,     0,     0,  1514,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,  1515,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,     0,     0,   579,     0,
       0,     0,     0,     0,  1516,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,  1806,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,     0,   579,     0,     0,     0,
       0,     0,  1817,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,  1854,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
    1923,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,  1938,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,  1950,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,     0,  2007,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,     0,     0,     0,     0,     0,  2016,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,  2017,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,     0,     0,   579,     0,
       0,     0,     0,     0,  2040,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,  2091,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,     0,   579,     0,     0,     0,
       0,     0,  2131,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,     0,
       0,  2150,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,     0,     0,
    2170,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,     0,     0,  2171,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,  2172,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,     0,   703,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,     0,   913,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,     0,  1916,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,   728,     0,   729,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,     0,     0,   973,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,  1024,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,     0,   579,     0,     0,     0,
    1170,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,  1235,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,     0,     0,     0,  1236,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,     0,
       0,  1241,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   702,   575,   576,   577,   578,
       0,     0,     0,     0,   579,     0,     0,     0,  1242,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   702,   575,   576,   577,   578,     0,     0,     0,
       0,   579,     0,     0,     0,  1332,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   702,
     575,   576,   577,   578,     0,     0,     0,     0,   579,     0,
       0,     0,  1346,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   702,   575,   576,   577,
     578,     0,     0,     0,     0,   579,     0,     0,     0,  1545,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,     0,     0,  1631,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     702,   575,   576,   577,   578,     0,     0,     0,     0,   579,
       0,     0,     0,  1680,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   702,   575,   576,
     577,   578,     0,     0,     0,     0,   579,     0,     0,     0,
    1866,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   702,   575,   576,   577,   578,     0,
       0,     0,     0,   579,     0,     0,     0,  1908,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   702,   575,   576,   577,   578,     0,     0,     0,     0,
     579,     0,     0,     0,  1924,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   779,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   780,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   781,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   783,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   784,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   785,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   787,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   788,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   789,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   790,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   791,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   792,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   793,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   795,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   796,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   797,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   862,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   897,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   943,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   961,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   963,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   964,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   965,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,   971,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,   972,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1009,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1023,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1083,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1087,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1099,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1169,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1179,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1180,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1181,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1191,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1220,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1222,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1223,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1224,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1225,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1226,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1227,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1228,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1234,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1331,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1345,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1546,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1576,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1577,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1578,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1579,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1617,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1630,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1743,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1745,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1748,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1755,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1807,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1816,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1839,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1907,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  1971,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  1972,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579,     0,  2104,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   702,   575,
     576,   577,   578,     0,     0,     0,     0,   579,     0,  2147,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   702,   575,   576,   577,   578,     0,     0,
       0,     0,   579
};

static const yytype_int16 yycheck[] =
{
       3,   153,     3,  1215,   319,   307,   140,    60,  1219,     3,
     723,   191,   707,   616,   617,   105,     4,   107,   731,   199,
      23,  1402,  1667,   338,     4,    52,    23,  1711,     6,  1713,
       4,     4,     4,     4,  1888,     4,     4,     0,     9,     4,
     134,     5,   100,   738,     6,     4,   100,     4,     6,    52,
     140,     5,     5,     5,     4,  1698,     7,     6,    59,     6,
     755,     6,     4,    94,     4,   123,     4,   100,   763,   123,
       6,   247,   134,     4,     4,   165,     6,   253,    81,     4,
     248,   247,   113,     9,   252,     4,    89,   253,   182,   151,
     405,    94,   407,    14,   232,   233,   245,   159,   160,   161,
     415,   250,   105,   165,   166,     9,     9,   232,   233,   289,
     290,   291,     6,     9,   134,   253,   232,   233,  1761,   240,
     241,    86,     7,     7,   154,   244,     9,   246,   253,     9,
     245,   151,   247,   249,   253,  1780,   244,   140,   253,   159,
     160,   161,   145,   146,    94,   165,   166,   141,    98,   179,
     153,   331,   332,   333,   104,   105,   244,   107,   108,     7,
     248,   103,   104,     7,    94,   195,   196,   170,   348,   864,
       7,   244,     6,   200,   249,   248,    94,   127,   253,    97,
       6,  2035,   100,   186,   102,   245,     6,   249,   191,   240,
     241,   194,   244,   253,   246,   113,   199,   200,   201,   250,
     169,   170,   171,   172,   244,   167,     7,   179,   180,   167,
       7,   179,   180,   138,   139,   140,   141,   232,   233,   144,
       6,   194,   232,   233,   251,   190,   232,   233,   153,   249,
      97,   156,   245,   100,    97,   102,   216,   100,   253,   240,
     253,  1622,   216,   253,  1456,   216,   113,   253,   251,     6,
     113,   216,   253,   254,   232,   233,   249,   216,   246,   216,
     253,   288,   265,   249,   252,   268,   269,   253,  1913,   240,
     241,   251,   269,   244,   301,   246,   216,   248,   305,   250,
     249,   284,   285,   248,   248,   288,   289,   290,   291,   248,
     605,   248,   607,   608,   248,   248,   248,   244,   301,   250,
       6,   248,   305,   248,   307,   245,   244,   247,     6,   624,
    1023,  1024,   248,   244,   240,   241,    66,    67,   244,    69,
     246,   247,  1967,     6,   250,   244,   329,   244,   331,   332,
     333,   421,   217,   218,   219,   220,   240,   241,   232,   233,
     244,   244,   246,   246,   245,   348,   250,   250,   244,   664,
     246,   354,   253,     6,   250,   240,   241,   240,   241,   539,
     244,   244,   246,   246,   244,   250,   246,   250,     6,   217,
     218,   219,   220,   217,   218,   219,   220,     6,     7,   531,
     217,   218,   219,   220,     6,   232,   233,  2071,   703,     7,
     417,   418,   240,   241,   237,   238,   240,   241,   232,   233,
     243,   248,   228,   240,   241,   231,   433,   246,   228,   412,
     413,   231,     6,     7,   417,   418,   217,   218,   219,   220,
     217,   218,   219,   220,   232,   233,   232,   233,   232,   233,
     433,   249,   232,   233,   249,   253,   439,   246,   253,   134,
     232,   233,   443,   232,   233,   253,   245,   253,   247,   253,
     134,   232,   233,   253,   253,   545,   151,   460,  1153,   248,
    1155,   253,  2107,   134,   159,   160,   161,   151,   232,   233,
     165,   166,   253,  1168,   244,   159,   160,   161,   232,   233,
     151,   165,   166,   232,   233,   245,   489,   247,   159,   160,
     161,   232,   233,   253,   165,   166,   244,    94,   249,   253,
      97,   528,   253,   100,   253,   232,   233,   244,   232,   233,
     513,   538,   253,   540,   244,  2160,   113,   520,   521,   244,
     672,   248,   525,  1904,   527,   528,   529,   530,   531,   253,
     249,   534,   232,   233,   253,   538,   539,   540,   541,   542,
     543,   544,   245,   546,   247,   548,   100,   544,   102,   546,
     253,   232,   233,   253,   249,   232,   233,   232,   233,   244,
     310,   311,   232,   233,   244,   249,   232,   233,   318,   319,
     248,   574,   253,   232,   233,   249,   253,   580,   253,   253,
     232,   233,  1277,   253,   244,   115,   246,   253,  1283,   723,
     250,   245,   244,   253,   253,   685,   248,   600,   601,   253,
     244,   244,   917,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   622,   616,   617,   244,   243,  1229,   232,   233,   234,
     235,   236,   237,   238,   245,  1330,   232,   233,   243,   240,
     241,   244,   253,   644,   647,   648,   649,   248,   244,  1344,
       6,   244,   248,   240,   241,  1350,   234,   235,   236,   237,
     238,   248,   244,   244,   246,   243,   248,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   244,   680,   681,   682,
     683,   684,   244,   686,   687,   688,   689,   690,   778,   100,
     693,   744,   689,   720,    94,   696,   245,    97,   699,   244,
     100,   704,   102,    94,   253,   245,    97,   247,   244,   100,
     711,   102,   245,   253,   248,   100,  1429,   720,   138,   139,
     253,   244,   102,   246,   144,     4,     5,   730,     8,   138,
     139,    97,   735,   248,   100,   144,   102,   244,   250,   246,
     252,   248,   743,   249,   745,   244,   249,   253,   751,   752,
     253,   249,   249,   248,   757,   253,   253,   760,   761,   893,
     249,    97,   249,   766,   253,   768,   253,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   245,   248,   247,   248,
      59,    60,    61,    62,   245,   248,   247,   249,    67,    68,
      69,   253,   249,    72,   248,    74,   253,   249,   801,   249,
     803,   253,   244,   253,    97,   249,  1519,   100,    87,   253,
     249,    90,   249,   100,   253,   249,   253,   907,  1531,   253,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   836,   249,   249,   140,   243,   253,   253,
      97,   145,   146,   846,   249,   244,   249,   246,   253,  2060,
     253,   130,   249,   249,   249,   249,   253,   253,   253,   253,
      97,   100,   249,   249,   614,   615,   253,   253,   249,   619,
     249,   249,   253,     4,   253,   253,   249,   904,     4,   882,
     253,  2093,   186,   250,   249,     4,   253,   249,   253,  1023,
    1024,   253,   895,   244,   249,   246,   249,   201,   253,     8,
     253,   904,   249,   249,     4,   249,   253,   253,  2119,   253,
     913,   245,   249,   247,   248,   916,   253,   918,   919,   198,
     199,   200,   249,   249,   249,  2137,   253,   253,   253,   249,
     209,   932,   244,   253,   213,  1025,   215,   216,   244,   244,
     246,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   244,
     249,   240,   241,   243,   253,   245,   249,   968,   244,   248,
     253,   250,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,  1015,   249,
     249,   249,   243,   253,   253,   253,   249,   249,   244,     6,
     253,   253,   249,  1004,   249,     6,   253,  1034,   253,   244,
    1312,   246,  1015,     4,   246,     6,   244,   246,   248,     6,
       6,   252,   248,   244,     9,   252,  1029,   244,   244,   244,
     244,  1034,   244,   244,   244,  1169,  1170,   244,   244,   248,
     182,   182,   182,  1046,   248,   123,   244,   244,  1051,  1652,
    1653,   244,   244,   182,  1081,  1082,     4,  1084,  1085,  1086,
     248,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,   244,   244,   248,   248,   244,     6,   248,  1081,  1082,
     248,  1084,  1085,  1086,   248,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,   244,   244,  1100,   244,   244,
     244,   244,     6,     6,     6,   244,     6,     6,   412,   246,
     248,  1138,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     248,   248,   248,  1160,   243,  1138,  1139,  1140,   246,   246,
     249,   246,   248,   182,   246,   244,   244,   244,   244,  1176,
     244,   244,     6,     6,     6,     6,   248,  1160,     8,     8,
     248,     7,     6,   248,     6,   248,    89,   249,   245,   253,
     920,     7,   253,  1176,  1177,  1178,     6,   927,     6,   245,
     248,   931,   243,   248,    64,     8,   250,     4,     7,     7,
     244,  1506,     6,   245,     6,  1510,  1197,  1331,  1332,   248,
       7,     6,     6,  1230,     7,     6,   249,   179,   248,   245,
       6,   249,   249,   247,     7,   248,   248,  1244,  1245,  1246,
     248,   525,   248,   527,  1526,   529,   530,  1230,   250,     6,
     246,   244,     4,   248,   245,  1229,     6,   541,   542,     6,
       6,  1244,  1245,  1246,     6,   248,   246,     7,     7,     7,
       7,     7,  1255,     7,     7,     7,     7,  1260,     7,     7,
       7,  1264,  1352,     7,  1354,     7,  1293,     7,     7,     6,
    1273,   245,  1275,   253,   247,  1278,   253,   253,   249,   245,
       7,   248,   250,   253,   249,     7,  1287,   248,   248,     4,
    1293,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,  1312,
       6,   250,   249,   243,   249,   248,  1919,     7,   134,     6,
     245,   250,     7,     7,     7,   245,   253,  1354,     9,  1332,
    1080,   253,   253,   245,  1337,   250,  1339,   247,   252,   182,
    1367,     7,   249,   154,  1371,     6,     6,   248,     6,     4,
     244,  1354,    46,    46,   250,   248,   244,   248,   250,   244,
     250,   244,     4,     7,  1367,     8,     7,   671,  1371,   673,
     674,   675,   676,   677,   678,     7,   680,   681,   682,   683,
    1532,  1533,   686,   687,   688,  1519,   253,   182,   245,     7,
       7,     7,     6,   253,     7,     7,  1423,  1424,  1425,     7,
     245,     4,   112,     4,  1431,   244,     6,   248,     7,     6,
     248,     7,  1502,     7,     7,     7,     7,     7,     7,  1446,
    1423,  1424,  1425,  1725,     6,     6,     6,   100,  1431,     7,
    1457,     6,     6,     4,     4,     5,     4,   245,  1465,     6,
     253,   251,   248,  1446,   253,     6,   248,     6,   248,     7,
     249,     6,   246,     6,  1457,   244,   760,   244,   248,     6,
       6,   249,  1465,     6,   768,   250,  1469,   247,     6,   253,
       6,   127,     6,     6,  1564,     6,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     6,     6,     6,     6,    59,
      60,    61,    62,     6,     6,  1629,     6,    67,    68,    69,
       6,     6,    72,     5,    74,     6,     4,   245,     7,   245,
       6,  1538,     4,     8,   248,     6,   248,    87,   248,   248,
      90,   246,   248,  1526,     6,     6,   249,   248,   248,  1532,
    1533,   248,   248,     6,   248,  1538,   248,  1564,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,  1556,     6,     6,   248,   243,  1648,   178,
     130,  1564,     6,     6,     6,   253,  1569,   245,     6,   248,
       7,   253,   244,   253,   248,   250,  1728,   253,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     4,     6,   249,     6,
     243,  1691,     6,     6,   244,     4,   249,  1741,  1698,  1699,
     244,     7,     6,  1928,  1641,     6,     6,     6,     6,     6,
       6,     6,    98,     6,     5,   248,   253,  1717,   198,   199,
     200,     6,     6,   248,   245,     6,     6,     6,  1641,   209,
    1667,  1644,  1645,   213,   248,   215,   216,   253,     6,     6,
     245,   253,     4,     6,  1956,   253,  1683,     6,  1652,  1653,
       6,   248,     6,     6,  1667,   253,     6,     5,     7,   248,
    1673,   248,   248,     6,     6,   245,   248,   247,   248,   245,
    1683,     6,     6,    13,    14,   248,   248,  1714,     7,   249,
    1693,     6,   249,  1696,   248,     6,   245,   177,   249,   249,
    1727,   249,     6,   248,     7,  1455,  2021,     6,   250,     6,
    1711,  1714,  1713,     6,     6,     6,     6,   249,  1721,     6,
     245,     6,  1725,     6,  1727,  1728,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   248,   180,  2061,  1051,   243,     6,
     245,   248,   247,  1780,   244,   249,   249,   245,  1761,   248,
       6,   248,   248,  1853,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,  1780,   248,     6,
     110,   111,   112,   113,   249,     6,   116,   134,  1815,  1792,
    1793,   248,     6,   123,   124,     6,     6,   127,   128,     6,
     130,   131,   248,   133,  1894,   245,     6,     6,     6,     6,
     249,     6,  1815,   249,     6,     6,     6,     6,     6,   248,
     150,     6,   248,     6,  1827,     6,   248,     6,     6,     6,
       6,     6,  1582,  1343,  2073,  1139,  1140,  1840,  1397,  1574,
    1889,  1637,  1851,     3,   174,   175,   176,   457,  1366,     3,
    1877,     3,     3,  1499,   595,     3,  1915,   194,  1698,  1721,
    1533,    -1,   760,  1890,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1877,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1913,  1890,     5,    -1,
      -1,    -1,  1895,  1896,  1897,    -1,    -1,    -1,    -1,    -1,
    1927,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1913,    -1,    -1,  1916,    -1,    -1,    -1,    -1,  1668,  1669,
    1670,  1671,  1672,  1673,  1927,  1919,    -1,    -1,  1931,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
    1967,    -1,    59,    60,    61,    62,  2036,   284,   285,    -1,
      67,    68,    69,  1956,    -1,    72,  1260,    74,    -1,    -1,
    1264,    -1,    -1,    -1,  1967,    -1,    -1,  1994,    -1,  1273,
      87,  1275,     6,    90,  1278,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1994,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2006,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,  1332,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2063,  2064,  2065,  2066,  2067,    -1,    -1,    -1,    -1,    -1,
    2071,    -1,    -1,    -1,    -1,    -1,   413,    -1,   113,    -1,
    2107,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   209,  2094,    -1,    -1,   213,    -1,   215,    -1,
      -1,    -1,    -1,    -1,  2107,   140,    -1,    -1,    -1,   144,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2124,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2160,    -1,    -1,   171,   172,   173,    -1,
     175,   176,   177,  2146,   179,   180,   181,   182,   183,   184,
     185,    -1,   187,   188,   189,   190,    -1,  2160,    -1,   194,
      -1,    -1,    -1,    -1,  2167,  2168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2181,    -1,
      -1,    -1,  1932,  1933,  1934,  1935,  1936,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     265,   266,   267,   268,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1993,    -1,    -1,    -1,  1997,   283,   284,
     285,    -1,  1556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   600,   601,    -1,    -1,    -1,   303,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,   314,
      -1,    -1,    -1,    -1,   319,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   329,   330,    -1,  2047,    -1,    -1,
      -1,  2051,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     647,   648,   649,    -1,    -1,    -1,    -1,  2067,   353,   354,
      -1,    -1,    -1,   358,   359,   360,    -1,   362,    -1,    -1,
      -1,   366,   367,   368,    -1,    -1,   371,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,   693,    -1,    -1,   243,
      -1,    -1,    -1,    -1,  2114,  2115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,   413,   414,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1693,
      -1,    -1,  1696,   730,    -1,   430,   431,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
      -1,    -1,    -1,    -1,   751,    -1,    -1,    -1,    -1,    -1,
     757,    -1,    -1,    -1,    -1,    -1,    -1,   462,   463,   464,
     465,    -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   488,   489,    -1,    -1,    -1,   493,    -1,
      -1,    -1,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,    -1,   523,   524,
      -1,   526,    -1,    -1,    -1,    -1,    -1,    -1,   533,   836,
      -1,   536,   537,    -1,    -1,    -1,    -1,    -1,   543,   846,
      -1,    -1,    -1,   548,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   882,   581,   582,    -1,    -1,
      -1,    -1,    -1,    -1,   589,   590,   591,    -1,   895,    -1,
      -1,    -1,   597,   598,    -1,   600,   601,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   913,    -1,     4,     5,
      -1,    -1,    -1,    -1,   619,   620,   621,    -1,    -1,    -1,
     625,   626,   627,   628,   629,   630,   631,   632,   633,    -1,
      -1,    -1,    -1,    -1,   639,    -1,   641,    -1,   643,    -1,
      -1,    -1,   647,   648,   649,   650,    -1,   652,   653,   654,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,   679,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   693,    -1,
      -1,    87,    -1,    -1,    90,   700,    -1,   702,    -1,    -1,
     705,   706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   714,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   730,    -1,    -1,    -1,    -1,
      -1,   736,   737,    -1,   130,    -1,    -1,    -1,    -1,  1046,
      -1,    -1,    -1,    -1,    -1,    -1,   751,    -1,   753,   754,
      -1,    -1,   757,   758,    -1,    -1,    -1,   762,    -1,    -1,
      -1,    -1,    -1,    -1,   769,    -1,    -1,    -1,   773,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,  1100,   799,    -1,   801,    -1,   803,    -1,
      -1,    -1,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,    -1,   194,    -1,   213,    -1,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,   836,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   846,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1177,  1178,  2146,    -1,    -1,    -1,    -1,   882,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,   268,
     895,    -1,    -1,  2167,  2168,    -1,    -1,    -1,   903,   134,
      -1,    -1,   907,    -1,    -1,   284,   285,  2181,   913,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   921,   922,    -1,    -1,
      -1,    -1,   927,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   944,
      -1,    -1,   947,    -1,    -1,    -1,    -1,    -1,  1255,    -1,
     329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,   967,    -1,   969,   970,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   988,    -1,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,  1011,    -1,   243,    -1,
      -1,    -1,    -1,  1018,  1019,  1020,  1021,    -1,    -1,    -1,
      -1,  1026,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1337,    -1,  1339,    -1,   413,  1040,  1041,    -1,    -1,    -1,
      -1,  1046,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
    1075,  1076,  1077,  1078,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,  1100,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     489,  1116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1126,  1127,  1128,    -1,    -1,    -1,    -1,  1133,  1134,
      -1,  1136,    -1,    -1,   513,    -1,    -1,     6,    -1,    -1,
      -1,   520,   521,  1148,  1149,    -1,    -1,    -1,    -1,    -1,
      -1,  1156,  1157,    -1,    -1,    -1,    -1,    -1,  1163,    -1,
    1165,  1166,  1469,    -1,   543,     6,    -1,  1172,  1173,   548,
      -1,    -1,  1177,  1178,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,   574,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   600,   601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,   648,
     649,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1284,
    1285,    -1,    -1,    -1,  1289,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1303,    -1,
      -1,  1306,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   693,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1333,    -1,
      -1,  1336,  1337,  1338,  1339,    -1,    -1,  1644,  1645,    -1,
      -1,    -1,  1347,    -1,  1349,    -1,  1351,  1352,    -1,    -1,
       6,   730,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,   751,    -1,   243,    -1,    -1,    -1,   757,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   801,    -1,   803,  1430,   243,    -1,   245,    -1,
     247,    -1,  1437,  1438,  1439,    -1,   253,    -1,    -1,    -1,
      -1,  1446,    -1,  1448,    -1,    -1,    -1,    -1,    -1,    -1,
    1455,    -1,    -1,    -1,    -1,    -1,    -1,   836,    -1,    -1,
      -1,    -1,    -1,    -1,  1469,    -1,    -1,   846,    -1,  1474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1482,  1483,  1484,
      -1,    -1,    -1,    -1,    -1,  1792,  1793,    -1,    -1,  1494,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1504,
      -1,    -1,    -1,   882,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   895,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1530,    -1,    -1,    -1,    -1,
      -1,  1536,  1537,  1840,   913,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     6,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,  1569,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,  1896,
    1897,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1609,  1610,  1611,    -1,    -1,  1916,
      -1,    -1,    -1,   435,    -1,  1620,    -1,    -1,    -1,    -1,
    1625,  1626,  1627,     6,  1931,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1639,    -1,    -1,    -1,    -1,  1644,
    1645,  1646,    -1,  1648,    -1,    -1,    -1,    -1,    -1,  1654,
    1655,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1046,  1673,    -1,
      -1,    -1,    -1,  1678,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1691,    -1,    -1,  1694,
      -1,    -1,    -1,  1698,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1707,  1708,    -1,  1710,    -1,    -1,    -1,    -1,
      -1,    -1,   534,  1718,    -1,    -1,    -1,    -1,    -1,    -1,
       6,  1100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1734,
      -1,    -1,    -1,    -1,  1739,  1740,    -1,    -1,  2045,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1753,    -1,
      -1,  1756,  1757,    -1,    -1,    -1,  2063,  2064,  2065,  2066,
    2067,    -1,    -1,   585,    -1,    -1,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,  1792,  1793,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1177,  1178,
      -1,    -1,    -1,    -1,  1809,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1818,    -1,    -1,    -1,  2124,    -1,    -1,
      -1,    -1,  1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1836,  1837,    -1,    -1,  1840,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1874,
    1875,    -1,    -1,    -1,    -1,    -1,  1255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1893,    -1,
      -1,  1896,  1897,  1898,    -1,    -1,    -1,    -1,  1903,    -1,
      -1,  1906,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1916,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1931,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1939,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,  1337,  1964,
    1339,    -1,    -1,    -1,    -1,  1970,    -1,    -1,  1973,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   808,   809,   810,   811,
     812,   813,   814,   815,   816,   817,   818,  2002,   820,   821,
     822,   823,    -1,   825,   826,   827,   828,    -1,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,   839,    -1,   841,
      -1,    -1,  2027,  2028,    -1,    -1,    -1,   849,    -1,    -1,
      -1,    -1,    -1,    -1,   856,   857,  2041,  2042,    -1,  2044,
    2045,    -1,    -1,   865,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2058,    -1,    -1,    -1,    -1,  2063,  2064,
    2065,  2066,  2067,    -1,    -1,    -1,    -1,    -1,  2073,    -1,
      -1,    -1,  2077,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1469,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2105,    -1,    -1,    -1,    -1,  2110,  2111,  2112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2124,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,  2152,  2153,  2154,
     243,    -1,   974,   975,   976,    -1,    -1,    -1,   980,   981,
      -1,    -1,   984,   985,   986,   987,    -1,   989,    -1,    -1,
      -1,    -1,   994,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1569,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,   245,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1074,    -1,    -1,     3,     4,  1079,    -1,    -1,
      -1,    -1,    10,    11,    12,  1644,  1645,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,  1673,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1174,    -1,    -1,    -1,    -1,   373,   374,   375,
      -1,    -1,    -1,   379,   380,   381,   382,   383,   384,   385,
      -1,   387,    -1,    -1,    -1,   391,   392,    -1,    -1,   395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,  1792,  1793,   110,   111,   112,   113,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
      -1,    -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1827,   197,
      -1,    -1,    -1,   201,    -1,   150,    -1,    -1,   206,   207,
     208,  1840,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,     7,     8,    -1,    -1,   174,
     175,   176,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,  1315,    -1,    -1,   244,    -1,    -1,     8,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1896,  1897,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1353,    -1,    -1,    -1,    -1,    -1,  1916,    -1,    -1,
     556,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1931,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1385,  1386,  1387,  1388,  1389,    -1,    -1,
      -1,    -1,  1394,  1395,    -1,    -1,  1398,    -1,  1400,    -1,
      -1,    -1,  1404,    -1,    -1,  1407,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1419,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,    -1,    -1,   127,   128,    -1,   130,   131,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2045,    -1,  1490,    -1,
    1492,    -1,    -1,    -1,  1496,    -1,  1498,    -1,    -1,    -1,
     174,   175,   176,    -1,  2063,  2064,  2065,  2066,  2067,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
    1532,   243,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2124,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,     3,     4,     5,  1628,   249,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   860,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,   894,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    -1,
      90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,  1730,   109,
      -1,  1733,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,
     130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,   156,    -1,    -1,  1781,
    1782,    -1,  1784,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,
     200,   201,   202,    -1,    -1,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,   215,   216,    -1,     8,    -1,
      -1,    -1,  1844,  1845,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,   248,    -1,
      -1,   251,  1068,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1891,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    67,    68,    69,    -1,  1161,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    -1,    90,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,   123,    -1,   125,
     126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     8,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,   198,   199,   200,   201,   202,    -1,    -1,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1316,  1317,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,  2133,    -1,   239,    -1,    -1,    -1,    -1,   244,     3,
       4,     5,   248,     7,    -1,   251,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,  1402,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,  1412,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    -1,    90,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,   190,    -1,   243,    -1,
     245,    -1,    -1,   197,   198,   199,   200,   201,   253,    -1,
      -1,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,    -1,  1568,    -1,    -1,   239,   240,   241,    -1,    -1,
     244,    -1,   246,     3,     4,     5,   250,   251,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,    -1,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,   248,    -1,
       8,   251,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,     3,     4,     5,
      -1,   249,    -1,   251,    10,    11,    12,    -1,    -1,    15,
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
     244,     3,     4,    -1,   248,   249,    -1,   251,    10,    11,
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
       4,    -1,    -1,   249,    -1,   251,    10,    11,    12,    -1,
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
       8,   251,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,   239,     3,     4,    -1,    -1,   244,     8,    -1,    10,
      11,    12,    -1,   251,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,   130,
      -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,   153,    -1,    -1,   156,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
     201,   202,    -1,    -1,    -1,   206,   207,   208,    -1,   210,
     211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,     3,
       4,    -1,    -1,   244,    -1,    -1,    10,    11,    12,    -1,
     251,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
       3,     4,     5,    -1,   244,    -1,    -1,    10,    11,    12,
      -1,   251,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    -1,    90,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,   248,    -1,    -1,   251,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,
       3,     4,     5,   248,    -1,    -1,   251,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    -1,    90,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,   248,    -1,    -1,   251,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,
      -1,    -1,    -1,    -1,   239,     3,     4,    -1,    -1,   244,
      -1,    -1,    10,    11,    12,    -1,   251,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,     3,     4,    -1,    85,    86,     8,
      88,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,   253,   201,    -1,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
     248,    -1,    -1,   251,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,   197,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   253,   206,   207,   208,
      -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,
     239,     3,     4,    -1,    -1,   244,    -1,    -1,    10,    11,
      12,    -1,   251,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,     3,     4,    -1,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,   197,    -1,   243,    -1,   201,
      -1,    -1,    -1,    -1,   206,   207,   208,   253,   210,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     232,   233,    -1,   110,   111,   112,   113,   239,    -1,   116,
      -1,    -1,   244,   245,    -1,    -1,   123,   124,    -1,   251,
     127,   128,    -1,   130,   131,    -1,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,   174,   175,   176,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,     3,     4,    -1,     6,   244,    -1,
      -1,    10,    11,    12,    -1,   251,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    -1,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,   197,    -1,
     243,    -1,   201,    -1,    -1,    -1,    -1,   206,   207,   208,
     253,   210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   232,   233,    -1,   110,   111,   112,   113,
     239,    -1,   116,    -1,    -1,   244,    -1,    -1,    -1,   123,
     124,    -1,   251,   127,   128,    -1,   130,   131,    -1,   133,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,    -1,   210,   211,   212,
     174,   175,   176,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,     3,     4,    -1,
      -1,   244,    -1,    -1,    10,    11,    12,    -1,   251,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,     3,     4,    -1,    85,
      86,    -1,    88,    10,    11,    12,    -1,    -1,    15,    16,
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
     206,   207,   208,    -1,   210,   211,   212,    -1,     4,     5,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
     197,    67,    68,    69,   201,    -1,    72,    -1,    74,   206,
     207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,
      -1,    87,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,
      -1,    -1,   239,     3,     4,    -1,    -1,   244,   245,    -1,
      10,    11,    12,    -1,   251,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,
      -1,    -1,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,    -1,    -1,    -1,   213,    -1,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,    -1,    -1,   127,   128,    -1,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   201,   174,   175,   176,    -1,   206,   207,   208,    -1,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,    -1,    -1,   116,    -1,    -1,   249,    -1,    -1,
      -1,   123,   124,    -1,    -1,   127,   128,    -1,   130,   131,
      -1,   133,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,    -1,
      -1,   116,   174,   175,   176,    -1,    -1,    -1,   123,   124,
      -1,    -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,
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
     131,    -1,   133,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   174,   175,   176,   110,   111,   112,   113,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   249,    -1,   127,   128,    -1,   130,   131,    -1,   133,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,   116,
     174,   175,   176,    -1,    -1,    -1,   123,   124,   249,    -1,
     127,   128,    -1,   130,   131,    -1,   133,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   174,   175,   176,
     110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   249,    -1,   127,   128,    -1,
     130,   131,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,    -1,    -1,   116,   174,   175,   176,    -1,    -1,    -1,
     123,   124,   249,    -1,   127,   128,    -1,   130,   131,    -1,
     133,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,   150,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,   174,   175,   176,    -1,    44,    45,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
     109,   110,   111,   112,   113,   114,   249,   116,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,     4,    -1,   162,   163,   164,    -1,    -1,    -1,   168,
      13,    14,    -1,    -1,   173,   174,   175,   176,    -1,    -1,
     179,    -1,   181,    -1,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    44,    45,    -1,   203,   204,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,    -1,   216,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,    -1,
      73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   109,   110,   111,   112,
     113,   114,    -1,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,   162,
     163,   164,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,
     173,   174,   175,   176,     4,     5,   179,    -1,   181,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   204,   205,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,   214,    -1,   216,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    13,    14,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    87,    -1,    -1,
      90,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,
     127,   128,    -1,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   150,    -1,    -1,    -1,   154,   198,   199,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,
      -1,    -1,    -1,   213,    -1,   215,   216,   174,   175,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     198,   199,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,    -1,    -1,    -1,   213,    -1,   215,   221,   222,
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
      -1,   243,    -1,    -1,    -1,    -1,   248,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,   248,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,   248,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,   245,    -1,   247,
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
      -1,    -1,    -1,   243,    -1,    -1,    -1,   247,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,   247,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243
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
     244,   246,   250,   276,   277,   278,   335,   356,   357,   366,
       4,   304,   305,   306,   248,     6,   335,   356,   357,   366,
     356,   335,   356,   363,   364,   366,   282,   286,   244,   345,
       9,   357,   244,   244,   244,   244,   366,   335,   335,   335,
     244,   335,   335,   335,   244,   335,   335,   335,   335,   335,
     335,   335,   356,   335,   335,   335,   335,   350,   244,   233,
     335,   351,   352,   248,   350,   349,   356,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     244,   246,   278,   278,   278,   278,   278,   278,   244,   278,
     278,   244,   300,   278,   278,     5,   248,   248,   123,   300,
     300,   244,   278,   278,   244,   244,   244,   335,   248,   335,
     351,   335,   335,   249,   352,   342,   366,   182,     5,   248,
       8,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   243,
       9,   244,   246,   250,   277,   278,   335,   352,   352,   244,
     244,   244,   349,   350,   350,   350,   299,   248,   244,   349,
     248,   248,   335,     4,   349,   248,   353,   248,   248,   346,
     346,   346,   335,   335,   232,   233,   248,   248,   346,   232,
     233,   244,   306,   346,   248,   244,   248,   244,   244,   244,
     244,   244,   244,   244,   352,   335,   350,   350,   350,   244,
       4,   246,     6,   246,   306,     6,     6,   248,   248,   248,
     248,   350,   246,   246,   246,   335,     8,     6,     6,   335,
     335,   335,   250,   335,   248,   182,   335,   335,   335,   335,
     278,   278,   278,   244,   244,   244,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   244,   244,   278,   244,
     246,     6,     6,   248,     6,     8,   306,     6,     8,   306,
     278,   335,   234,   248,     9,   244,   246,   250,   356,   352,
     335,   306,   349,   349,   248,   357,    94,    97,   100,   102,
       7,   335,   335,     4,   179,   180,   349,     6,   245,   247,
     248,   279,     6,   248,     6,     9,   244,   246,   250,   366,
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
     335,   335,   249,   352,   352,   352,   335,     6,   335,   335,
     335,   245,   249,   245,   245,   245,   179,   253,   306,   248,
       8,   245,   245,   247,   363,   356,   363,   356,   356,   356,
     356,   356,   356,   335,   356,   356,   356,   356,   251,   359,
     366,   357,   356,   356,   356,   342,   366,   352,   249,   249,
     249,   249,   335,   335,   306,   366,   343,   247,   249,   245,
     137,   154,   323,   245,   249,   253,   335,     6,   248,   248,
     248,   248,   349,   245,   247,     7,   276,   277,   250,     7,
       6,   352,     7,   217,   276,   261,   366,   335,   335,   343,
     246,   244,   123,   300,   301,   300,   248,   249,     6,   228,
     231,   258,   352,   366,   335,   335,     4,   343,     6,   352,
     335,     6,   356,   364,   366,   245,   343,     6,   366,     6,
     356,   335,   245,   246,   335,   253,   253,   253,   253,   357,
       7,     7,     7,   245,     7,     7,     7,   245,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   335,   245,
     248,   335,   351,   249,     6,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   253,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   253,   253,   253,   245,
     247,   247,   352,   253,   253,   279,   253,   279,   253,   253,
     253,   245,   352,   337,   279,   249,   249,   249,   253,   253,
     279,   279,   245,   250,   245,   250,   253,   278,   338,   249,
       7,   343,   279,   248,   249,     8,     8,   352,   250,   245,
     247,   277,   244,   246,   278,   352,     7,   248,   248,   245,
     245,   245,   335,   349,     4,   327,     6,   295,   335,   357,
     249,   245,   249,   249,   352,   250,   249,   306,   249,   249,
     346,   335,   335,   249,   249,   335,   346,   134,   134,   151,
     159,   160,   161,   165,   166,   320,   321,   346,   249,   316,
     245,   249,   245,   245,   245,   245,   245,   245,   245,   248,
       7,   335,     6,   335,   245,   247,   247,   249,   249,   249,
     249,   247,   247,   253,     7,     7,     7,   250,   335,   249,
     335,   335,     7,   250,   279,   253,   279,   279,   245,   245,
     253,   279,   279,   253,   253,   279,   279,   279,   279,   335,
     279,     9,   358,   253,   245,   253,   279,   250,   253,   339,
     247,   249,   249,   250,   244,   246,   252,   182,     7,   154,
       6,   335,   249,   248,     6,   349,   249,   335,   335,   335,
     335,     6,     7,   276,   277,   250,   276,   277,   357,   335,
       6,     4,   248,   354,   366,   249,    46,    46,   349,     4,
     169,   170,   171,   172,   249,   264,   268,   271,   273,   274,
     250,   245,   247,   244,   335,   335,   244,   248,   244,   248,
       8,   352,   356,   245,   250,   245,   247,   244,   245,   253,
     250,   244,     7,   278,     4,   289,   290,   291,   279,   335,
     335,   335,   335,   279,   346,   349,   349,     7,   349,   349,
     349,     7,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,     6,     7,   352,   335,   335,   335,   335,   249,
     335,   335,   335,   349,   356,   356,   249,   253,   288,   335,
     335,   343,   343,   335,   335,   245,   349,   278,   335,   335,
     335,   249,   343,   277,   250,   277,   335,   335,   279,   249,
     349,   352,   352,     7,     7,     7,   134,   326,     6,   245,
     253,     7,     7,     7,   249,     4,   249,   253,   253,   253,
     249,   249,   112,     4,     6,   335,   248,     6,   244,     6,
     167,     6,   167,   249,   321,   253,   320,     7,     6,     7,
       7,     7,     7,     7,     7,     7,   305,   349,     6,   248,
       6,     6,     6,   100,     7,     6,     6,   335,   349,   349,
     349,     4,   253,     8,     8,   245,     4,   103,   104,     4,
     352,   356,   335,   356,   251,   253,   292,   356,   356,   343,
     356,   245,   253,   343,   248,   300,   248,     6,   335,     6,
     248,   349,   249,   249,   249,   249,   249,   335,     6,     4,
     179,   180,   335,     6,     6,     6,     7,   353,   355,     6,
     246,   279,   278,   278,     6,   265,   244,   244,   248,   275,
       6,   343,   250,   356,   335,   247,   245,   335,     8,   352,
     335,   352,   249,   249,     6,     6,   258,   343,   250,   335,
       6,   335,   343,   245,   248,   335,   357,   279,    46,   248,
     349,   357,   360,   247,   253,     6,   245,   245,   245,   245,
       6,     6,   127,   297,   297,   349,     6,     6,     6,   349,
     134,   182,   296,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   249,   279,   279,   279,   279,   279,   253,
     253,   253,   245,   279,   279,   290,   279,   245,   279,   245,
     278,   338,   279,     6,   279,   253,   244,   246,   278,     4,
     245,   247,   279,     6,   249,   249,   349,   349,   349,     4,
       6,   276,   335,   349,   248,   248,     7,     6,     7,   335,
     335,   335,   248,   248,   248,   246,     6,   335,   349,   335,
       6,     6,   335,   346,   249,     5,   349,   248,   248,   248,
     248,   248,   248,   248,   349,   249,     6,   352,   248,   335,
     247,     6,     6,   178,   335,   335,   335,     6,     6,     6,
       6,     7,   279,   253,   253,   279,   253,   335,     4,   194,
     293,   294,   279,   245,   279,   339,   357,   244,   246,   335,
     248,   306,     6,   306,   253,     6,     6,     7,   276,   277,
     250,     7,     6,   353,   249,   253,   335,   276,   248,   279,
     361,   362,   363,   361,   244,   335,   335,   348,   349,   248,
     244,     4,     6,   245,     6,   245,   249,   249,   245,   249,
       6,     6,   356,   244,     4,   245,   253,   244,   349,   357,
       7,   278,   287,   335,   351,   291,     6,     6,     6,     6,
     346,     6,     6,     6,     6,    94,   113,    98,     6,     5,
     248,   335,   335,   335,   335,   245,   338,   335,   335,   335,
     279,   277,   248,   248,     6,   296,     6,   335,   349,     4,
       6,   352,   352,   335,   335,   357,   249,   245,   249,   253,
     305,   305,   335,   335,   249,   253,   245,   249,   253,     6,
       6,   348,   346,   346,   346,   346,   346,   233,   346,     6,
     249,   335,     6,     6,   349,   249,   253,     8,   249,   245,
     248,   335,   357,   356,   335,   356,   335,   357,   360,   362,
     357,   253,   245,   253,   249,   335,   323,   323,   349,   357,
     335,     6,     4,   354,     6,   353,   247,   349,   363,     6,
     279,   279,   262,   335,   253,   253,   249,   253,   263,   335,
     335,     6,     6,     6,     6,   335,   335,   245,   283,   285,
     248,   362,   249,   253,     7,     7,   248,   248,   248,     5,
     348,   279,   279,   253,   279,   245,   253,   245,   247,   352,
     352,     6,     6,   248,   249,   249,   248,     6,     6,   248,
     335,   249,   249,   249,   247,     6,   349,     7,   248,   335,
     249,   253,   253,   253,   253,   253,   253,     6,   249,   177,
     335,   335,   352,     6,     6,   245,   279,   279,   294,   357,
     249,   249,   249,   249,     6,     6,     7,     6,   250,     6,
     249,     6,     6,   245,   253,   335,   335,   248,   349,   249,
     253,   245,   245,   253,   288,   292,   349,   279,   335,   357,
     366,   352,   352,   335,     6,   249,   335,   338,   335,   249,
     249,   348,   138,   139,   144,   330,   138,   139,   330,   352,
     305,   249,   253,     6,   249,   349,   306,   249,     6,   352,
     346,   346,   346,   346,   346,   335,   249,   249,   249,   245,
       6,   248,     6,   353,   180,   266,   335,   253,   253,   348,
       6,   335,   335,   249,   249,   284,     7,   244,   249,   249,
     249,   248,   253,   245,   253,   248,   249,   248,   346,   349,
       6,   248,   346,     6,   249,   249,   335,     6,   134,   249,
     317,   248,   249,   253,   253,   253,   253,   253,     6,     6,
       6,   306,     6,   248,   335,   335,   249,   253,   288,   357,
     245,   335,   335,   335,   352,     6,   346,     6,   346,     6,
       6,   249,   335,   320,   306,     6,   352,   352,   352,   352,
     346,   352,   323,   263,   245,   253,     6,   248,   335,   249,
     253,   253,   253,   249,   253,   253,     6,   249,   249,   318,
     249,   249,   249,   249,   253,   249,   249,   249,   269,   335,
     348,   249,   335,   335,   335,   346,   346,   320,     6,     6,
       6,     6,   352,     6,     6,     6,   248,   245,   249,     6,
     249,   279,   253,   253,   253,   249,   249,   267,   356,   272,
     248,     6,   335,   335,   335,     6,   249,   253,   248,   348,
     249,   249,   249,     6,   356,   270,   356,   249,     6,     6,
     249,   253,     6,     6,   356
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
     308,   308,   308,   308,   309,   309,   310,   311,   311,   311,
     311,   311,   311,   311,   311,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   313,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   315,   315,   315,   316,   315,   317,   315,   318,   315,
     319,   315,   315,   315,   315,   315,   315,   320,   320,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     322,   322,   322,   322,   322,   323,   323,   323,   323,   323,
     324,   324,   325,   326,   326,   327,   327,   328,   328,   329,
     329,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   332,
     332,   332,   333,   333,   333,   334,   334,   334,   334,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   337,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   338,   338,   339,   339,   341,   340,
     342,   342,   343,   344,   344,   345,   345,   346,   346,   346,
     346,   346,   347,   347,   347,   347,   348,   348,   349,   349,
     349,   349,   349,   349,   350,   350,   350,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   352,   352,   352,
     352,   353,   353,   353,   353,   354,   354,   355,   355,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   358,   357,   357,   359,   359,   360,   361,   361,   362,
     363,   363,   363,   363,   364,   364,   364,   365,   365,   365,
     366,   366,   366
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
      14,    14,    14,    14,     8,     8,     6,     4,     5,     6,
       6,     3,     4,     3,     5,     6,     5,     4,     3,     4,
       3,     4,     5,     4,     5,     3,     5,     7,     7,     3,
       7,     3,     2,     2,     2,     2,     2,    15,     2,     2,
       2,     2,     2,     2,     2,    16,    11,     6,     8,     8,
      10,     1,     2,     2,     1,     3,     3,     4,     4,     1,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     9,     2,     3,    10,    13,     1,     2,     5,
       7,     2,     2,     3,     2,     3,     2,     3,     9,     6,
       1,     1,     1,     1,     1,     0,     2,     3,     3,     4,
       9,     4,    14,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     6,     7,     6,     5,     3,     8,     8,
       8,     8,     8,     5,     4,     6,    11,    11,    18,    18,
      12,    12,    12,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     1,
       4,     6,     1,     4,     4,     4,     6,     5,     7,     8,
      10,     4,     4,     6,     4,     3,     2,     5,     5,     3,
       5,     6,     8,     6,     8,     6,     4,     7,     6,     6,
       6,     4,     6,     4,     0,     2,     0,     2,     0,     7,
       1,     3,     1,     1,     2,     0,     3,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     3,     1,     2,     3,     3,
       5,     4,     4,     2,     4,     2,     3,     3,    16,     5,
       1,     1,     1,     3,     5,     7,     4,     4,     4,     6,
       6,     8,     8,     4,    14,     4,     4,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     4,     4,     3,     5,     6,     8,     6,     5,     5,
       5,     5,     1,     4,     1,     1,     1,     1,     4,     6,
       4,     6,     5,     7,     4,     4,     4,     8,     4,     4,
       4,     4,     8,     8,     6,     4,     6,     4,     1,     4,
       4,     0,     6,     4,     2,     4,     4,     1,     1,     3,
       1,     1,     3,     3,     3,     5,     7,     5,     5,     8,
       1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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
#line 269 "Gmsh.y" /* yacc.c:1645  */
    { yyerrok; return 1; }
#line 5836 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 6:
#line 280 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5842 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 7:
#line 281 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5848 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 8:
#line 282 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5854 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 9:
#line 284 "Gmsh.y" /* yacc.c:1645  */
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
#line 5877 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 10:
#line 302 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5883 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 11:
#line 303 "Gmsh.y" /* yacc.c:1645  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 5889 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 12:
#line 304 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5895 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 13:
#line 305 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5901 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 14:
#line 306 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5907 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 15:
#line 307 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5913 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 16:
#line 308 "Gmsh.y" /* yacc.c:1645  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 5919 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 17:
#line 309 "Gmsh.y" /* yacc.c:1645  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 5925 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 18:
#line 310 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5931 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 19:
#line 311 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5937 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 20:
#line 312 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5943 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 21:
#line 313 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5949 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 22:
#line 314 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5955 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 23:
#line 315 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5961 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 24:
#line 316 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5967 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 25:
#line 317 "Gmsh.y" /* yacc.c:1645  */
    { return 1; }
#line 5973 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 26:
#line 322 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = (char*)"w";
    }
#line 5981 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 27:
#line 326 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = (char*)"a";
    }
#line 5989 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 28:
#line 333 "Gmsh.y" /* yacc.c:1645  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 5998 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 29:
#line 338 "Gmsh.y" /* yacc.c:1645  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 6007 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 30:
#line 343 "Gmsh.y" /* yacc.c:1645  */
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
#line 6025 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 31:
#line 357 "Gmsh.y" /* yacc.c:1645  */
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
#line 6042 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 32:
#line 370 "Gmsh.y" /* yacc.c:1645  */
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
#line 6059 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 33:
#line 383 "Gmsh.y" /* yacc.c:1645  */
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
#line 6086 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 34:
#line 411 "Gmsh.y" /* yacc.c:1645  */
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
#line 6104 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 35:
#line 425 "Gmsh.y" /* yacc.c:1645  */
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
#line 6121 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 36:
#line 438 "Gmsh.y" /* yacc.c:1645  */
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
#line 6138 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 37:
#line 451 "Gmsh.y" /* yacc.c:1645  */
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
#line 6157 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 38:
#line 469 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 6167 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 44:
#line 483 "Gmsh.y" /* yacc.c:1645  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6173 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 45:
#line 485 "Gmsh.y" /* yacc.c:1645  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 6179 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 46:
#line 490 "Gmsh.y" /* yacc.c:1645  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6185 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 47:
#line 492 "Gmsh.y" /* yacc.c:1645  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 6191 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 48:
#line 497 "Gmsh.y" /* yacc.c:1645  */
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
#line 6299 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 49:
#line 601 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 6313 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 50:
#line 611 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 6323 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 51:
#line 620 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6334 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 52:
#line 627 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6345 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 53:
#line 637 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 6358 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 54:
#line 646 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 6368 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 55:
#line 655 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6379 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 56:
#line 662 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6390 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 57:
#line 672 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 6402 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 58:
#line 680 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 6412 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 59:
#line 690 "Gmsh.y" /* yacc.c:1645  */
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
#line 6432 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 60:
#line 709 "Gmsh.y" /* yacc.c:1645  */
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
#line 6452 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 61:
#line 728 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 6462 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 62:
#line 734 "Gmsh.y" /* yacc.c:1645  */
    {
    }
#line 6469 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 63:
#line 741 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 0; }
#line 6475 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 64:
#line 742 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 1; }
#line 6481 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 65:
#line 743 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 2; }
#line 6487 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 66:
#line 744 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 3; }
#line 6493 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 67:
#line 745 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 4; }
#line 6499 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 68:
#line 749 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 1; }
#line 6505 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 69:
#line 750 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = -1; }
#line 6511 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 70:
#line 756 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (char*)"("; }
#line 6517 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 71:
#line 756 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (char*)"["; }
#line 6523 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 72:
#line 757 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (char*)")"; }
#line 6529 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 73:
#line 757 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (char*)"]"; }
#line 6535 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 77:
#line 767 "Gmsh.y" /* yacc.c:1645  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 6544 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 78:
#line 772 "Gmsh.y" /* yacc.c:1645  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 6554 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 79:
#line 778 "Gmsh.y" /* yacc.c:1645  */
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
#line 6620 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 80:
#line 840 "Gmsh.y" /* yacc.c:1645  */
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
#line 6639 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 81:
#line 855 "Gmsh.y" /* yacc.c:1645  */
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
#line 6672 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 82:
#line 884 "Gmsh.y" /* yacc.c:1645  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 6683 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 83:
#line 894 "Gmsh.y" /* yacc.c:1645  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6692 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 84:
#line 899 "Gmsh.y" /* yacc.c:1645  */
    {
      incrementVariable((yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6701 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 85:
#line 907 "Gmsh.y" /* yacc.c:1645  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6710 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 86:
#line 912 "Gmsh.y" /* yacc.c:1645  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6719 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 87:
#line 920 "Gmsh.y" /* yacc.c:1645  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 6729 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 88:
#line 929 "Gmsh.y" /* yacc.c:1645  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 6738 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 89:
#line 934 "Gmsh.y" /* yacc.c:1645  */
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
#line 6754 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 90:
#line 946 "Gmsh.y" /* yacc.c:1645  */
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
#line 6772 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 91:
#line 963 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6782 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 92:
#line 969 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6792 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 93:
#line 978 "Gmsh.y" /* yacc.c:1645  */
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
#line 6814 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 94:
#line 996 "Gmsh.y" /* yacc.c:1645  */
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
#line 6836 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 95:
#line 1014 "Gmsh.y" /* yacc.c:1645  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 6849 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 96:
#line 1023 "Gmsh.y" /* yacc.c:1645  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 6862 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 97:
#line 1035 "Gmsh.y" /* yacc.c:1645  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 6871 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 98:
#line 1040 "Gmsh.y" /* yacc.c:1645  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 6880 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 99:
#line 1048 "Gmsh.y" /* yacc.c:1645  */
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
#line 6904 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 100:
#line 1068 "Gmsh.y" /* yacc.c:1645  */
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
#line 6928 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 101:
#line 1091 "Gmsh.y" /* yacc.c:1645  */
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
#line 6952 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 102:
#line 1111 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 6964 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 103:
#line 1119 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Box");
#endif
    }
#line 6975 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 104:
#line 1126 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), "Cylinder");
#endif
    }
#line 6986 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 105:
#line 1133 "Gmsh.y" /* yacc.c:1645  */
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
#line 7012 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 106:
#line 1155 "Gmsh.y" /* yacc.c:1645  */
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
#line 7039 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 107:
#line 1178 "Gmsh.y" /* yacc.c:1645  */
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
#line 7081 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 108:
#line 1216 "Gmsh.y" /* yacc.c:1645  */
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
#line 7103 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 109:
#line 1237 "Gmsh.y" /* yacc.c:1645  */
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
#line 7119 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 110:
#line 1249 "Gmsh.y" /* yacc.c:1645  */
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
#line 7135 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 114:
#line 1267 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 7148 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 115:
#line 1276 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 7161 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 116:
#line 1285 "Gmsh.y" /* yacc.c:1645  */
    { init_options(); }
#line 7167 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 117:
#line 1287 "Gmsh.y" /* yacc.c:1645  */
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
#line 7189 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 118:
#line 1305 "Gmsh.y" /* yacc.c:1645  */
    { init_options(); }
#line 7195 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 119:
#line 1307 "Gmsh.y" /* yacc.c:1645  */
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
#line 7215 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 120:
#line 1323 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 7228 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 121:
#line 1332 "Gmsh.y" /* yacc.c:1645  */
    { init_options(); }
#line 7234 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 122:
#line 1334 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 7248 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 124:
#line 1348 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 7258 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 125:
#line 1356 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7268 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 126:
#line 1362 "Gmsh.y" /* yacc.c:1645  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 7277 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 127:
#line 1367 "Gmsh.y" /* yacc.c:1645  */
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
#line 7306 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 134:
#line 1410 "Gmsh.y" /* yacc.c:1645  */
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
#line 7322 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 135:
#line 1422 "Gmsh.y" /* yacc.c:1645  */
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
#line 7339 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 136:
#line 1435 "Gmsh.y" /* yacc.c:1645  */
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
#line 7357 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 137:
#line 1450 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7369 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 138:
#line 1459 "Gmsh.y" /* yacc.c:1645  */
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
#line 7384 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 143:
#line 1484 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 7395 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 144:
#line 1492 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7407 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 145:
#line 1501 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 7418 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 146:
#line 1509 "Gmsh.y" /* yacc.c:1645  */
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
#line 7435 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 147:
#line 1523 "Gmsh.y" /* yacc.c:1645  */
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
#line 7452 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 148:
#line 1541 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 7460 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 149:
#line 1545 "Gmsh.y" /* yacc.c:1645  */
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[0].c)), dim_entity, t + 1);
      Free((yyvsp[0].c));
    }
#line 7471 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 150:
#line 1552 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), dim_entity, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 7480 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 151:
#line 1560 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = 0;
    }
#line 7488 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 152:
#line 1564 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[-1].d);
      List_Add((yyval.l), &p);
    }
#line 7498 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 153:
#line 1570 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 7506 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 154:
#line 1574 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[-1].l), i));
      List_Delete((yyvsp[-1].l));
    }
#line 7519 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 155:
#line 1585 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 7527 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 156:
#line 1589 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 7535 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 157:
#line 1596 "Gmsh.y" /* yacc.c:1645  */
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
#line 7562 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 158:
#line 1619 "Gmsh.y" /* yacc.c:1645  */
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
#line 7582 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 159:
#line 1635 "Gmsh.y" /* yacc.c:1645  */
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
#line 7602 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 160:
#line 1651 "Gmsh.y" /* yacc.c:1645  */
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
#line 7643 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 161:
#line 1688 "Gmsh.y" /* yacc.c:1645  */
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
#line 7687 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 162:
#line 1728 "Gmsh.y" /* yacc.c:1645  */
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
#line 7707 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 163:
#line 1744 "Gmsh.y" /* yacc.c:1645  */
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
#line 7727 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 164:
#line 1761 "Gmsh.y" /* yacc.c:1645  */
    {
      int num = (int)(yyvsp[-8].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-5].l), tags);
      std::vector<double> seqknots; ListOfDouble2Vector((yyvsp[-3].l), seqknots);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        int degree = (int)(yyvsp[-1].d);
        std::vector<double> weights, knots;
        std::vector<int> mults;
        for(unsigned int i = 0; i < seqknots.size(); i++){
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
#line 7762 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 165:
#line 1792 "Gmsh.y" /* yacc.c:1645  */
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
#line 7782 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 166:
#line 1808 "Gmsh.y" /* yacc.c:1645  */
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
#line 7803 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 167:
#line 1825 "Gmsh.y" /* yacc.c:1645  */
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
#line 7823 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 168:
#line 1841 "Gmsh.y" /* yacc.c:1645  */
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
            for(unsigned int i = 2; i < constraints.size(); i+=2){
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
#line 7877 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 169:
#line 1891 "Gmsh.y" /* yacc.c:1645  */
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
#line 7899 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 170:
#line 1909 "Gmsh.y" /* yacc.c:1645  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7909 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 171:
#line 1915 "Gmsh.y" /* yacc.c:1645  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7919 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 172:
#line 1921 "Gmsh.y" /* yacc.c:1645  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 7930 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 173:
#line 1928 "Gmsh.y" /* yacc.c:1645  */
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
#line 7965 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 174:
#line 1959 "Gmsh.y" /* yacc.c:1645  */
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
#line 7984 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 175:
#line 1974 "Gmsh.y" /* yacc.c:1645  */
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
#line 8010 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 176:
#line 1996 "Gmsh.y" /* yacc.c:1645  */
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
#line 8037 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 177:
#line 2019 "Gmsh.y" /* yacc.c:1645  */
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
#line 8064 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 178:
#line 2042 "Gmsh.y" /* yacc.c:1645  */
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
#line 8091 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 179:
#line 2065 "Gmsh.y" /* yacc.c:1645  */
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
#line 8119 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 180:
#line 2089 "Gmsh.y" /* yacc.c:1645  */
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
#line 8147 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 181:
#line 2113 "Gmsh.y" /* yacc.c:1645  */
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
#line 8175 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 182:
#line 2137 "Gmsh.y" /* yacc.c:1645  */
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() >= 2){
          int in = (int)param[0];
          double offset = param[1];
          std::vector<int> exclude;
          for(unsigned int i = 2; i < param.size(); i++)
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
#line 8205 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 183:
#line 2163 "Gmsh.y" /* yacc.c:1645  */
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
#line 8226 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 184:
#line 2180 "Gmsh.y" /* yacc.c:1645  */
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
#line 8246 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 185:
#line 2196 "Gmsh.y" /* yacc.c:1645  */
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
#line 8268 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 186:
#line 2214 "Gmsh.y" /* yacc.c:1645  */
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
#line 8290 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 187:
#line 2232 "Gmsh.y" /* yacc.c:1645  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-6].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8301 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 188:
#line 2240 "Gmsh.y" /* yacc.c:1645  */
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[-10].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 8312 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 189:
#line 2247 "Gmsh.y" /* yacc.c:1645  */
    {
      dim_entity = (yyvsp[0].i);
    }
#line 8320 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 190:
#line 2251 "Gmsh.y" /* yacc.c:1645  */
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
#line 8347 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 191:
#line 2277 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 0; }
#line 8353 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 192:
#line 2279 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 1; }
#line 8359 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 193:
#line 2281 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 2; }
#line 8365 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 194:
#line 2283 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 3; }
#line 8371 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 195:
#line 2285 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
#line 8380 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 196:
#line 2293 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 1; }
#line 8386 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 197:
#line 2295 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 2; }
#line 8392 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 198:
#line 2297 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 3; }
#line 8398 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 199:
#line 2299 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
#line 8407 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 200:
#line 2307 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 1; }
#line 8413 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 201:
#line 2309 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 2; }
#line 8419 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 202:
#line 2311 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
#line 8428 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 203:
#line 2319 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 0; }
#line 8434 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 204:
#line 2321 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 1; }
#line 8440 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 205:
#line 2323 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 2; }
#line 8446 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 206:
#line 2325 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
#line 8455 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 207:
#line 2335 "Gmsh.y" /* yacc.c:1645  */
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
#line 8475 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 208:
#line 2351 "Gmsh.y" /* yacc.c:1645  */
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
#line 8495 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 209:
#line 2367 "Gmsh.y" /* yacc.c:1645  */
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
#line 8515 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 210:
#line 2383 "Gmsh.y" /* yacc.c:1645  */
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
#line 8535 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 211:
#line 2399 "Gmsh.y" /* yacc.c:1645  */
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
#line 8555 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 212:
#line 2415 "Gmsh.y" /* yacc.c:1645  */
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
#line 8576 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 213:
#line 2432 "Gmsh.y" /* yacc.c:1645  */
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
#line 8617 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 214:
#line 2469 "Gmsh.y" /* yacc.c:1645  */
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
        for(unsigned int i = 0; i < out.size(); i++){
          Shape s;
          s.Type = MSH_POINT;
          s.Num = out[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not intersect line");
      List_Delete((yyvsp[-5].l));
    }
#line 8642 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 215:
#line 2491 "Gmsh.y" /* yacc.c:1645  */
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
        for(unsigned int i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not split line");
      List_Delete((yyvsp[-2].l));
    }
#line 8667 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 216:
#line 2514 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8673 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 217:
#line 2515 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8679 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 218:
#line 2520 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 8687 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 219:
#line 2524 "Gmsh.y" /* yacc.c:1645  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 8695 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 220:
#line 2528 "Gmsh.y" /* yacc.c:1645  */
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
#line 8716 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 221:
#line 2545 "Gmsh.y" /* yacc.c:1645  */
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
#line 8740 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 222:
#line 2565 "Gmsh.y" /* yacc.c:1645  */
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
#line 8764 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 223:
#line 2585 "Gmsh.y" /* yacc.c:1645  */
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
#line 8787 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 224:
#line 2604 "Gmsh.y" /* yacc.c:1645  */
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
#line 8813 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 225:
#line 2631 "Gmsh.y" /* yacc.c:1645  */
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
#line 8836 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 226:
#line 2650 "Gmsh.y" /* yacc.c:1645  */
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
#line 8861 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 227:
#line 2672 "Gmsh.y" /* yacc.c:1645  */
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
#line 8879 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 228:
#line 2687 "Gmsh.y" /* yacc.c:1645  */
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
#line 8898 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 229:
#line 2702 "Gmsh.y" /* yacc.c:1645  */
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
#line 8920 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 230:
#line 2721 "Gmsh.y" /* yacc.c:1645  */
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
#line 8974 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 231:
#line 2772 "Gmsh.y" /* yacc.c:1645  */
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
#line 8998 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 232:
#line 2793 "Gmsh.y" /* yacc.c:1645  */
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
#line 9023 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 233:
#line 2815 "Gmsh.y" /* yacc.c:1645  */
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
#line 9049 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 234:
#line 2837 "Gmsh.y" /* yacc.c:1645  */
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
#line 9158 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 235:
#line 2942 "Gmsh.y" /* yacc.c:1645  */
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
#line 9178 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 236:
#line 2958 "Gmsh.y" /* yacc.c:1645  */
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
#line 9212 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 237:
#line 2993 "Gmsh.y" /* yacc.c:1645  */
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
#line 9238 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 238:
#line 3015 "Gmsh.y" /* yacc.c:1645  */
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
#line 9264 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 239:
#line 3037 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 9274 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 240:
#line 3043 "Gmsh.y" /* yacc.c:1645  */
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
#line 9293 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 241:
#line 3058 "Gmsh.y" /* yacc.c:1645  */
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
#line 9325 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 242:
#line 3086 "Gmsh.y" /* yacc.c:1645  */
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
#line 9341 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 243:
#line 3098 "Gmsh.y" /* yacc.c:1645  */
    {
      gmsh_yynamespaces.clear();
    }
#line 9349 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 244:
#line 3107 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), false);
      List_Delete((yyvsp[-1].l));
    }
#line 9360 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 245:
#line 3114 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), true);
      List_Delete((yyvsp[-1].l));
    }
#line 9371 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 246:
#line 3126 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      for(unsigned int i = 0; i < dimTags.size(); i++){
        GEntity *ge = GModel::current()->getEntityByTag
          (dimTags[i].first, dimTags[i].second);
        if(ge){
          for(unsigned int j = 0; j < ge->getNumMeshElements(); j++)
            ge->getMeshElement(j)->setPartition((int)(yyvsp[-3].d));
        }
      }
      List_Delete((yyvsp[-1].l));
    }
#line 9389 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 247:
#line 3145 "Gmsh.y" /* yacc.c:1645  */
    {
      setVisibility(-1, 1, false);
    }
#line 9397 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 248:
#line 3149 "Gmsh.y" /* yacc.c:1645  */
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[-1].c));
    }
#line 9406 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 249:
#line 3154 "Gmsh.y" /* yacc.c:1645  */
    {
      setVisibility(-1, 0, false);
    }
#line 9414 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 250:
#line 3158 "Gmsh.y" /* yacc.c:1645  */
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[-1].c));
    }
#line 9423 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 251:
#line 3163 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9434 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 252:
#line 3170 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9445 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 253:
#line 3177 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[-1].l));
    }
#line 9456 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 254:
#line 3184 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[-1].l));
    }
#line 9467 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 255:
#line 3196 "Gmsh.y" /* yacc.c:1645  */
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
#line 9544 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 256:
#line 3269 "Gmsh.y" /* yacc.c:1645  */
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
#line 9566 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 257:
#line 3287 "Gmsh.y" /* yacc.c:1645  */
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
#line 9595 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 258:
#line 3312 "Gmsh.y" /* yacc.c:1645  */
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
#line 9614 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 259:
#line 3327 "Gmsh.y" /* yacc.c:1645  */
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
#line 9651 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 260:
#line 3360 "Gmsh.y" /* yacc.c:1645  */
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
#line 9667 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 261:
#line 3372 "Gmsh.y" /* yacc.c:1645  */
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
#line 9695 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 262:
#line 3396 "Gmsh.y" /* yacc.c:1645  */
    {
      Msg::Exit(0);
    }
#line 9703 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 263:
#line 3400 "Gmsh.y" /* yacc.c:1645  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 9712 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 264:
#line 3405 "Gmsh.y" /* yacc.c:1645  */
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
#line 9723 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 265:
#line 3412 "Gmsh.y" /* yacc.c:1645  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 9732 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 266:
#line 3417 "Gmsh.y" /* yacc.c:1645  */
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
#line 9746 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 267:
#line 3427 "Gmsh.y" /* yacc.c:1645  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 9755 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 268:
#line 3432 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 9765 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 269:
#line 3438 "Gmsh.y" /* yacc.c:1645  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 9777 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 270:
#line 3446 "Gmsh.y" /* yacc.c:1645  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 9785 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 271:
#line 3450 "Gmsh.y" /* yacc.c:1645  */
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    }
#line 9793 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 272:
#line 3454 "Gmsh.y" /* yacc.c:1645  */
    {
      GModel::current()->renumberMeshVertices();
    }
#line 9801 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 273:
#line 3458 "Gmsh.y" /* yacc.c:1645  */
    {
      GModel::current()->renumberMeshElements();
    }
#line 9809 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 274:
#line 3462 "Gmsh.y" /* yacc.c:1645  */
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 9822 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 275:
#line 3472 "Gmsh.y" /* yacc.c:1645  */
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
#line 9884 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 276:
#line 3535 "Gmsh.y" /* yacc.c:1645  */
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
#line 9900 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 277:
#line 3551 "Gmsh.y" /* yacc.c:1645  */
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
#line 9921 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 278:
#line 3568 "Gmsh.y" /* yacc.c:1645  */
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
#line 9942 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 279:
#line 3585 "Gmsh.y" /* yacc.c:1645  */
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
#line 9968 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 280:
#line 3607 "Gmsh.y" /* yacc.c:1645  */
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
#line 9994 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 281:
#line 3629 "Gmsh.y" /* yacc.c:1645  */
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
#line 10033 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 282:
#line 3664 "Gmsh.y" /* yacc.c:1645  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10045 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 283:
#line 3672 "Gmsh.y" /* yacc.c:1645  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 10057 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 284:
#line 3680 "Gmsh.y" /* yacc.c:1645  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 10067 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 285:
#line 3686 "Gmsh.y" /* yacc.c:1645  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10078 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 286:
#line 3693 "Gmsh.y" /* yacc.c:1645  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 10089 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 287:
#line 3700 "Gmsh.y" /* yacc.c:1645  */
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
#line 10113 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 288:
#line 3720 "Gmsh.y" /* yacc.c:1645  */
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
#line 10143 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 289:
#line 3746 "Gmsh.y" /* yacc.c:1645  */
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
#line 10159 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 290:
#line 3758 "Gmsh.y" /* yacc.c:1645  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 10169 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 291:
#line 3769 "Gmsh.y" /* yacc.c:1645  */
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
#line 10191 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 292:
#line 3787 "Gmsh.y" /* yacc.c:1645  */
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
#line 10213 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 293:
#line 3805 "Gmsh.y" /* yacc.c:1645  */
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
#line 10235 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 294:
#line 3823 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10245 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 295:
#line 3829 "Gmsh.y" /* yacc.c:1645  */
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
#line 10267 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 296:
#line 3847 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10277 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 297:
#line 3853 "Gmsh.y" /* yacc.c:1645  */
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
#line 10301 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 298:
#line 3873 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10311 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 299:
#line 3879 "Gmsh.y" /* yacc.c:1645  */
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
#line 10333 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 300:
#line 3897 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 10343 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 301:
#line 3903 "Gmsh.y" /* yacc.c:1645  */
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
#line 10364 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 302:
#line 3920 "Gmsh.y" /* yacc.c:1645  */
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
#line 10384 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 303:
#line 3936 "Gmsh.y" /* yacc.c:1645  */
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
#line 10405 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 304:
#line 3953 "Gmsh.y" /* yacc.c:1645  */
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
#line 10426 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 305:
#line 3971 "Gmsh.y" /* yacc.c:1645  */
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
#line 10452 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 306:
#line 3994 "Gmsh.y" /* yacc.c:1645  */
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
#line 10480 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 307:
#line 4021 "Gmsh.y" /* yacc.c:1645  */
    {
    }
#line 10487 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 308:
#line 4024 "Gmsh.y" /* yacc.c:1645  */
    {
    }
#line 10494 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 309:
#line 4030 "Gmsh.y" /* yacc.c:1645  */
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
#line 10510 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 310:
#line 4042 "Gmsh.y" /* yacc.c:1645  */
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
#line 10534 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 311:
#line 4062 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 10542 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 312:
#line 4066 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.Recombine = true;
    }
#line 10550 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 313:
#line 4070 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 10558 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 314:
#line 4074 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 10566 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 315:
#line 4078 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 10574 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 316:
#line 4082 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 10582 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 317:
#line 4086 "Gmsh.y" /* yacc.c:1645  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 10590 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 318:
#line 4090 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      int num = (int)(yyvsp[-6].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[-1].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[-3].l));
    }
#line 10603 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 319:
#line 4099 "Gmsh.y" /* yacc.c:1645  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 10615 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 320:
#line 4111 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = OCC_Internals::Union; }
#line 10621 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 321:
#line 4112 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = OCC_Internals::Intersection; }
#line 10627 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 322:
#line 4113 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = OCC_Internals::Difference; }
#line 10633 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 323:
#line 4114 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = OCC_Internals::Section; }
#line 10639 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 324:
#line 4115 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = OCC_Internals::Fragments; }
#line 10645 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 325:
#line 4119 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 0; }
#line 10651 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 326:
#line 4120 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 1; }
#line 10657 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 327:
#line 4121 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 2; }
#line 10663 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 328:
#line 4122 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = (yyvsp[-1].d) ? 1 : 0; }
#line 10669 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 329:
#line 4123 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = (yyvsp[-1].d) ? 2 : 0; }
#line 10675 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 330:
#line 4128 "Gmsh.y" /* yacc.c:1645  */
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
#line 10702 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 331:
#line 4151 "Gmsh.y" /* yacc.c:1645  */
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
#line 10722 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 332:
#line 4171 "Gmsh.y" /* yacc.c:1645  */
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
#line 10744 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 333:
#line 4192 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 10752 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 334:
#line 4196 "Gmsh.y" /* yacc.c:1645  */
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
#line 10769 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 335:
#line 4211 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = -1; // left
    }
#line 10777 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 336:
#line 4215 "Gmsh.y" /* yacc.c:1645  */
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
#line 10795 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 337:
#line 4231 "Gmsh.y" /* yacc.c:1645  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 10803 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 338:
#line 4235 "Gmsh.y" /* yacc.c:1645  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 10811 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 339:
#line 4240 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = 45;
    }
#line 10819 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 340:
#line 4244 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 10827 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 341:
#line 4250 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 10835 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 342:
#line 4254 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10843 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 343:
#line 4261 "Gmsh.y" /* yacc.c:1645  */
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
#line 10869 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 344:
#line 4283 "Gmsh.y" /* yacc.c:1645  */
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
#line 10914 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 345:
#line 4324 "Gmsh.y" /* yacc.c:1645  */
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
              for(unsigned int j = 0; j < corners.size(); j++){
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
#line 10962 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 346:
#line 4368 "Gmsh.y" /* yacc.c:1645  */
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
              for(unsigned int i = 0; i < corners.size(); i++){
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
#line 11005 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 347:
#line 4407 "Gmsh.y" /* yacc.c:1645  */
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
#line 11034 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 348:
#line 4432 "Gmsh.y" /* yacc.c:1645  */
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
#line 11050 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 349:
#line 4444 "Gmsh.y" /* yacc.c:1645  */
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
#line 11066 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 350:
#line 4456 "Gmsh.y" /* yacc.c:1645  */
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
#line 11082 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 351:
#line 4468 "Gmsh.y" /* yacc.c:1645  */
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
#line 11098 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 352:
#line 4480 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[-1].d);
      }
      List_Delete((yyvsp[-4].l));
    }
#line 11111 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 353:
#line 4489 "Gmsh.y" /* yacc.c:1645  */
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
#line 11145 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 354:
#line 4519 "Gmsh.y" /* yacc.c:1645  */
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
#line 11175 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 355:
#line 4545 "Gmsh.y" /* yacc.c:1645  */
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
#line 11205 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 356:
#line 4572 "Gmsh.y" /* yacc.c:1645  */
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
#line 11240 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 357:
#line 4604 "Gmsh.y" /* yacc.c:1645  */
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
#line 11270 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 358:
#line 4631 "Gmsh.y" /* yacc.c:1645  */
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
#line 11299 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 359:
#line 4657 "Gmsh.y" /* yacc.c:1645  */
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
#line 11328 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 360:
#line 4683 "Gmsh.y" /* yacc.c:1645  */
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
#line 11357 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 361:
#line 4709 "Gmsh.y" /* yacc.c:1645  */
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
#line 11386 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 362:
#line 4735 "Gmsh.y" /* yacc.c:1645  */
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
#line 11411 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 363:
#line 4756 "Gmsh.y" /* yacc.c:1645  */
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
#line 11426 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 364:
#line 4767 "Gmsh.y" /* yacc.c:1645  */
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
#line 11478 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 365:
#line 4815 "Gmsh.y" /* yacc.c:1645  */
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
#line 11536 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 366:
#line 4869 "Gmsh.y" /* yacc.c:1645  */
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
#line 11555 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 367:
#line 4884 "Gmsh.y" /* yacc.c:1645  */
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
#line 11571 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 368:
#line 4896 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-2].i), tags);
      List_Delete((yyvsp[-1].l));
    }
#line 11581 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 369:
#line 4907 "Gmsh.y" /* yacc.c:1645  */
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
#line 11592 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 370:
#line 4914 "Gmsh.y" /* yacc.c:1645  */
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
#line 11611 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 371:
#line 4929 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[-2].l));
    }
#line 11624 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 372:
#line 4942 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (char*)"Homology"; }
#line 11630 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 373:
#line 4943 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 11636 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 374:
#line 4944 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (char*)"Betti"; }
#line 11642 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 375:
#line 4949 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 11652 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 376:
#line 4955 "Gmsh.y" /* yacc.c:1645  */
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
#line 11668 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 377:
#line 4967 "Gmsh.y" /* yacc.c:1645  */
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
#line 11690 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 378:
#line 4985 "Gmsh.y" /* yacc.c:1645  */
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
#line 11717 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 379:
#line 5012 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11723 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 380:
#line 5013 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 11729 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 381:
#line 5014 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 11735 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 382:
#line 5015 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11741 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 383:
#line 5016 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 11747 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 384:
#line 5017 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 11753 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 385:
#line 5018 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 11759 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 386:
#line 5019 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 11765 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 387:
#line 5021 "Gmsh.y" /* yacc.c:1645  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 11776 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 388:
#line 5027 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (int)(yyvsp[-2].d) | (int)(yyvsp[0].d); }
#line 11782 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 389:
#line 5028 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (int)(yyvsp[-2].d) & (int)(yyvsp[0].d); }
#line 11788 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 390:
#line 5029 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d); }
#line 11794 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 391:
#line 5030 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 11800 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 392:
#line 5031 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 11806 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 393:
#line 5032 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 11812 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 394:
#line 5033 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 11818 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 395:
#line 5034 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 11824 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 396:
#line 5035 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 11830 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 397:
#line 5036 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 11836 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 398:
#line 5037 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 11842 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 399:
#line 5038 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 11848 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 400:
#line 5039 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = ((int)(yyvsp[-2].d) >> (int)(yyvsp[0].d)); }
#line 11854 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 401:
#line 5040 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = ((int)(yyvsp[-2].d) << (int)(yyvsp[0].d)); }
#line 11860 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 402:
#line 5041 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 11866 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 403:
#line 5042 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 11872 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 404:
#line 5043 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 11878 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 405:
#line 5044 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 11884 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 406:
#line 5045 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 11890 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 407:
#line 5046 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 11896 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 408:
#line 5047 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 11902 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 409:
#line 5048 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 11908 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 410:
#line 5049 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 11914 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 411:
#line 5050 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 11920 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 412:
#line 5051 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 11926 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 413:
#line 5052 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 11932 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 414:
#line 5053 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 11938 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 415:
#line 5054 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 11944 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 416:
#line 5055 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 11950 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 417:
#line 5056 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 11956 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 418:
#line 5057 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = std::abs((yyvsp[-1].d)); }
#line 11962 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 419:
#line 5058 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 11968 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 420:
#line 5059 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 11974 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 421:
#line 5060 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 11980 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 422:
#line 5061 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 11986 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 423:
#line 5062 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 11992 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 424:
#line 5063 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 11998 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 425:
#line 5064 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 12004 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 426:
#line 5073 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12010 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 427:
#line 5074 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = 3.141592653589793; }
#line 12016 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 428:
#line 5075 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 12022 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 429:
#line 5076 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 12028 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 430:
#line 5077 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 12034 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 431:
#line 5078 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 12040 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 432:
#line 5079 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 12046 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 433:
#line 5080 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 12052 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 434:
#line 5081 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = Cpu(); }
#line 12058 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 435:
#line 5082 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 12064 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 436:
#line 5083 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = TotalRam(); }
#line 12070 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 437:
#line 5088 "Gmsh.y" /* yacc.c:1645  */
    { init_options(); }
#line 12076 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 438:
#line 5090 "Gmsh.y" /* yacc.c:1645  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 12086 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 439:
#line 5096 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[0].d); }
#line 12092 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 440:
#line 5098 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12101 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 441:
#line 5103 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12110 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 442:
#line 5108 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[0].c2).char1, (yyvsp[0].c2).char2);
    }
#line 12118 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 443:
#line 5113 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12126 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 444:
#line 5118 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 12134 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 445:
#line 5122 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-1].c2).char1, (yyvsp[-1].c2).char2, 1, 0, 0., 1);
    }
#line 12142 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 446:
#line 5126 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-3].c2).char1, (yyvsp[-3].c2).char2, (yyvsp[-1].c), 0, 0., 1);
    }
#line 12150 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 447:
#line 5130 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-2].c2).char1, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].d), 2);
    }
#line 12158 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 448:
#line 5134 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].d), 2);
    }
#line 12166 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 449:
#line 5138 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-5].c2).char1, (yyvsp[-5].c2).char2, 2, (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12174 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 450:
#line 5142 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c2).char1, (yyvsp[-7].c2).char2, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 12182 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 451:
#line 5146 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 12192 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 452:
#line 5152 "Gmsh.y" /* yacc.c:1645  */
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
#line 12211 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 453:
#line 5168 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c));
    }
#line 12219 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 454:
#line 5173 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string struct_namespace((yyvsp[-1].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[-1].c));
    }
#line 12229 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 455:
#line 5179 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
#line 12238 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 456:
#line 5185 "Gmsh.y" /* yacc.c:1645  */
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
#line 12261 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 457:
#line 5204 "Gmsh.y" /* yacc.c:1645  */
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
#line 12285 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 458:
#line 5225 "Gmsh.y" /* yacc.c:1645  */
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
#line 12309 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 459:
#line 5258 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12317 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 460:
#line 5262 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12325 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 461:
#line 5267 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12333 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 462:
#line 5271 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12341 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 463:
#line 5275 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12349 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 464:
#line 5279 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12357 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 465:
#line 5284 "Gmsh.y" /* yacc.c:1645  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12366 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 466:
#line 5289 "Gmsh.y" /* yacc.c:1645  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12380 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 467:
#line 5299 "Gmsh.y" /* yacc.c:1645  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 12394 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 468:
#line 5309 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 12403 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 469:
#line 5314 "Gmsh.y" /* yacc.c:1645  */
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
#line 12418 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 470:
#line 5325 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12431 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 471:
#line 5334 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = strlen((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 12440 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 472:
#line 5339 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 12449 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 473:
#line 5344 "Gmsh.y" /* yacc.c:1645  */
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
#line 12477 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 474:
#line 5371 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = 0.; }
#line 12483 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 475:
#line 5373 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.d) = (yyvsp[0].d);}
#line 12489 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 476:
#line 5378 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = NULL; }
#line 12495 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 477:
#line 5380 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (yyvsp[0].c);}
#line 12501 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 478:
#line 5385 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string struct_namespace((yyvsp[-1].c2).char1? (yyvsp[-1].c2).char1 : std::string("")),
        struct_name((yyvsp[-1].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
#line 12512 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 479:
#line 5392 "Gmsh.y" /* yacc.c:1645  */
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
#line 12529 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 480:
#line 5408 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[0].c); }
#line 12535 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 481:
#line 5410 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c2).char1 = (yyvsp[-2].c); (yyval.c2).char2 = (yyvsp[0].c); }
#line 12541 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 482:
#line 5415 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (yyvsp[0].c); flag_tSTRING_alloc = 1; }
#line 12547 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 483:
#line 5424 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 99; }
#line 12553 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 484:
#line 5426 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = (int)(yyvsp[0].d); }
#line 12559 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 485:
#line 5431 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = 0; }
#line 12565 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 486:
#line 5433 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 12571 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 487:
#line 5438 "Gmsh.y" /* yacc.c:1645  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 12579 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 488:
#line 5442 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 12587 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 489:
#line 5446 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 12595 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 490:
#line 5450 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 12603 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 491:
#line 5454 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 12611 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 492:
#line 5461 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 12619 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 493:
#line 5465 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 12627 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 494:
#line 5469 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12635 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 495:
#line 5473 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 12643 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 496:
#line 5480 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12652 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 497:
#line 5485 "Gmsh.y" /* yacc.c:1645  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 12660 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 498:
#line 5492 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12669 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 499:
#line 5497 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12677 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 500:
#line 5501 "Gmsh.y" /* yacc.c:1645  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 12686 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 501:
#line 5506 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12694 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 502:
#line 5510 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12706 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 503:
#line 5518 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 12718 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 504:
#line 5529 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12726 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 505:
#line 5533 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = 0;
    }
#line 12734 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 506:
#line 5537 "Gmsh.y" /* yacc.c:1645  */
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
#line 12749 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 507:
#line 5551 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12761 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 508:
#line 5559 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 12773 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 509:
#line 5567 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 12784 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 510:
#line 5574 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 12798 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 511:
#line 5584 "Gmsh.y" /* yacc.c:1645  */
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
#line 12825 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 512:
#line 5607 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    }
#line 12834 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 513:
#line 5612 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[0].c));
    }
#line 12844 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 514:
#line 5618 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-3].i), (yyval.l));
    }
#line 12853 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 515:
#line 5623 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-1].i), (yyval.l));
      Free((yyvsp[0].c));
    }
#line 12863 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 516:
#line 5629 "Gmsh.y" /* yacc.c:1645  */
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
#line 12878 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 517:
#line 5640 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[-1].i), (yyvsp[0].l), (yyval.l));
      List_Delete((yyvsp[0].l));
    }
#line 12888 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 518:
#line 5647 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[-15].i), (yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d), (yyval.l));
    }
#line 12897 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 519:
#line 5652 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[-3].i), (yyvsp[-1].l), (yyval.l));
      List_Delete((yyvsp[-1].l));
    }
#line 12907 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 520:
#line 5658 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12921 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 521:
#line 5668 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12935 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 522:
#line 5678 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12949 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 523:
#line 5688 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(20, 20, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-2].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-2].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-2].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[-2].c));
    }
#line 12965 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 524:
#line 5700 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 12973 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 525:
#line 5704 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 12981 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 526:
#line 5709 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[-1].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[-1].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-1].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[-1].c));
    }
#line 12997 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 527:
#line 5721 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13005 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 528:
#line 5725 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13013 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 529:
#line 5729 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 13021 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 530:
#line 5733 "Gmsh.y" /* yacc.c:1645  */
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
#line 13043 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 531:
#line 5751 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = (yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1);
	List_Add((yyval.l), &d);
      }
    }
#line 13055 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 532:
#line 5759 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = pow(10,(yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1));
	List_Add((yyval.l), &d);
      }
    }
#line 13067 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 533:
#line 5767 "Gmsh.y" /* yacc.c:1645  */
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
#line 13100 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 534:
#line 5796 "Gmsh.y" /* yacc.c:1645  */
    {
      double x0 = (yyvsp[-11].d), x1 = (yyvsp[-9].d), y0 = (yyvsp[-7].d), y1 = (yyvsp[-5].d), ys = (yyvsp[-3].d);
      int N = (int)(yyvsp[-1].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
#line 13114 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 535:
#line 5806 "Gmsh.y" /* yacc.c:1645  */
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
      for(unsigned int i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    }
#line 13134 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 536:
#line 5822 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[-1].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13146 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 537:
#line 5833 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13155 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 538:
#line 5838 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 13163 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 539:
#line 5842 "Gmsh.y" /* yacc.c:1645  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 13171 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 540:
#line 5846 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13184 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 541:
#line 5858 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 13192 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 542:
#line 5862 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 13200 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 543:
#line 5874 "Gmsh.y" /* yacc.c:1645  */
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
#line 13221 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 544:
#line 5891 "Gmsh.y" /* yacc.c:1645  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 13232 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 545:
#line 5901 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 13240 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 546:
#line 5905 "Gmsh.y" /* yacc.c:1645  */
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
#line 13256 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 547:
#line 5920 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13265 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 548:
#line 5925 "Gmsh.y" /* yacc.c:1645  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 13273 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 549:
#line 5932 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13281 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 550:
#line 5936 "Gmsh.y" /* yacc.c:1645  */
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[0].c));
    }
#line 13290 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 551:
#line 5941 "Gmsh.y" /* yacc.c:1645  */
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
#line 13308 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 552:
#line 5955 "Gmsh.y" /* yacc.c:1645  */
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
#line 13326 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 553:
#line 5971 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13334 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 554:
#line 5975 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 13342 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 555:
#line 5979 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13350 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 556:
#line 5983 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 13358 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 557:
#line 5987 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 13370 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 558:
#line 5995 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13380 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 559:
#line 6001 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13390 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 560:
#line 6007 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13400 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 561:
#line 6013 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 13410 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 562:
#line 6022 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 13418 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 563:
#line 6026 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13426 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 564:
#line 6030 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 13438 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 565:
#line 6038 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 13448 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 566:
#line 6044 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 13458 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 567:
#line 6050 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
#line 13466 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 568:
#line 6054 "Gmsh.y" /* yacc.c:1645  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 13478 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 569:
#line 6062 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13490 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 570:
#line 6070 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 13501 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 571:
#line 6077 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 13513 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 572:
#line 6086 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].c), 2);
    }
#line 13521 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 573:
#line 6090 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].c), 2);
    }
#line 13529 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 574:
#line 6094 "Gmsh.y" /* yacc.c:1645  */
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
#line 13548 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 575:
#line 6109 "Gmsh.y" /* yacc.c:1645  */
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
#line 13566 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 576:
#line 6123 "Gmsh.y" /* yacc.c:1645  */
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
#line 13584 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 577:
#line 6137 "Gmsh.y" /* yacc.c:1645  */
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
#line 13600 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 578:
#line 6149 "Gmsh.y" /* yacc.c:1645  */
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
#line 13620 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 579:
#line 6165 "Gmsh.y" /* yacc.c:1645  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13633 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 580:
#line 6174 "Gmsh.y" /* yacc.c:1645  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13646 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 581:
#line 6183 "Gmsh.y" /* yacc.c:1645  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13660 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 582:
#line 6193 "Gmsh.y" /* yacc.c:1645  */
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
#line 13675 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 583:
#line 6204 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string in = (yyvsp[-5].c);
      std::string out = in.substr((int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c));
    }
#line 13687 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 584:
#line 6212 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string in = (yyvsp[-3].c);
      std::string out = in.substr((int)(yyvsp[-1].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-3].c));
    }
#line 13699 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 585:
#line 6220 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 13707 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 586:
#line 6224 "Gmsh.y" /* yacc.c:1645  */
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
#line 13730 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 587:
#line 6243 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13741 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 588:
#line 6250 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 13751 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 589:
#line 6256 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13762 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 590:
#line 6263 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13773 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 591:
#line 6270 "Gmsh.y" /* yacc.c:1645  */
    { init_options(); }
#line 13779 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 592:
#line 6272 "Gmsh.y" /* yacc.c:1645  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 13791 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 593:
#line 6280 "Gmsh.y" /* yacc.c:1645  */
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
#line 13816 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 594:
#line 6304 "Gmsh.y" /* yacc.c:1645  */
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[0].d); }
#line 13822 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 595:
#line 6306 "Gmsh.y" /* yacc.c:1645  */
    { struct_namespace = (yyvsp[-3].c); Free((yyvsp[-3].c)); (yyval.d) = (yyvsp[0].d); }
#line 13828 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 596:
#line 6312 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 13834 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 597:
#line 6317 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13840 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 598:
#line 6319 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13846 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 599:
#line 6324 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 13852 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 600:
#line 6329 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 13861 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 601:
#line 6334 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13867 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 602:
#line 6336 "Gmsh.y" /* yacc.c:1645  */
    {
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 13875 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 603:
#line 6340 "Gmsh.y" /* yacc.c:1645  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	char* c;
	List_Read((yyvsp[0].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13888 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 604:
#line 6352 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = List_Create(20, 20, sizeof(char *));
      if(!gmsh_yystringsymbols.count((yyvsp[-2].c)))
	yymsg(0, "Unknown string variable '%s'", (yyvsp[-2].c));
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[-2].c)]);
	for(unsigned int i = 0; i < s.size(); i++) {
          char * val_ = strsave((char*)s.at(i).c_str());
	  List_Add((yyval.l), &val_);
        }
      }
      Free((yyvsp[-2].c));
    }
#line 13906 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 605:
#line 6366 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13914 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 606:
#line 6370 "Gmsh.y" /* yacc.c:1645  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13922 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 607:
#line 6377 "Gmsh.y" /* yacc.c:1645  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 13934 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 608:
#line 6385 "Gmsh.y" /* yacc.c:1645  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 13946 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 609:
#line 6393 "Gmsh.y" /* yacc.c:1645  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-5].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-5].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-5].c));
    }
#line 13958 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 610:
#line 6404 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (yyvsp[0].c); }
#line 13964 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 611:
#line 6406 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (yyvsp[0].c); }
#line 13970 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;

  case 612:
#line 6409 "Gmsh.y" /* yacc.c:1645  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 13976 "Gmsh.tab.cpp" /* yacc.c:1645  */
    break;


#line 13980 "Gmsh.tab.cpp" /* yacc.c:1645  */
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 6412 "Gmsh.y" /* yacc.c:1903  */


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
  for(unsigned int i = 0; i < strlen(format); i++)
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
      for(unsigned int i = 0; i < s.value.size(); i++){
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
      for(unsigned int i = 0; i < it->second.size(); i++){
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
  for(unsigned int i = 0; i < v.size(); i++){
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
    for(unsigned int i = 0; i < tags.size(); i++){
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
    for(unsigned int i = 0; i < tags.size(); i++){
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

void getAllElementaryTags(int dim, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++){
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
  for(unsigned int i = 0; i < entities.size(); i++){
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
  for(unsigned int i = 0; i < entities.size(); i++){
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

  for(unsigned int i = 0; i < dimTags.size(); i++){
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

  for(unsigned int i = 0; i < dimTags.size(); i++){
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
    for(unsigned int i = 0; i < out_vector->size(); i++) {
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
    for(unsigned int i = 0; i < out_vector->size(); i++) {
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
