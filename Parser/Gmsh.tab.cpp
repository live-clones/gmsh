/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

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

/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y" /* yacc.c:339  */

// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
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


#line 237 "Gmsh.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
    tCreateTopologyNoHoles = 334,
    tDistanceFunction = 335,
    tDefineConstant = 336,
    tUndefineConstant = 337,
    tDefineNumber = 338,
    tDefineStruct = 339,
    tNameStruct = 340,
    tDimNameSpace = 341,
    tAppend = 342,
    tDefineString = 343,
    tSetNumber = 344,
    tSetString = 345,
    tPoint = 346,
    tCircle = 347,
    tEllipse = 348,
    tLine = 349,
    tSphere = 350,
    tPolarSphere = 351,
    tSurface = 352,
    tSpline = 353,
    tVolume = 354,
    tBlock = 355,
    tCylinder = 356,
    tCone = 357,
    tTorus = 358,
    tEllipsoid = 359,
    tQuadric = 360,
    tShapeFromFile = 361,
    tRectangle = 362,
    tDisk = 363,
    tWire = 364,
    tGeoEntity = 365,
    tCharacteristic = 366,
    tLength = 367,
    tParametric = 368,
    tElliptic = 369,
    tRefineMesh = 370,
    tAdaptMesh = 371,
    tRelocateMesh = 372,
    tSetFactory = 373,
    tThruSections = 374,
    tWedge = 375,
    tFillet = 376,
    tChamfer = 377,
    tPlane = 378,
    tRuled = 379,
    tTransfinite = 380,
    tPhysical = 381,
    tCompound = 382,
    tPeriodic = 383,
    tUsing = 384,
    tPlugin = 385,
    tDegenerated = 386,
    tRecursive = 387,
    tRotate = 388,
    tTranslate = 389,
    tSymmetry = 390,
    tDilate = 391,
    tExtrude = 392,
    tLevelset = 393,
    tAffine = 394,
    tBooleanUnion = 395,
    tBooleanIntersection = 396,
    tBooleanDifference = 397,
    tBooleanSection = 398,
    tBooleanFragments = 399,
    tThickSolid = 400,
    tRecombine = 401,
    tSmoother = 402,
    tSplit = 403,
    tDelete = 404,
    tCoherence = 405,
    tIntersect = 406,
    tMeshAlgorithm = 407,
    tReverse = 408,
    tLayers = 409,
    tScaleLast = 410,
    tHole = 411,
    tAlias = 412,
    tAliasWithOptions = 413,
    tCopyOptions = 414,
    tQuadTriAddVerts = 415,
    tQuadTriNoNewVerts = 416,
    tRecombLaterals = 417,
    tTransfQuadTri = 418,
    tText2D = 419,
    tText3D = 420,
    tInterpolationScheme = 421,
    tTime = 422,
    tCombine = 423,
    tBSpline = 424,
    tBezier = 425,
    tNurbs = 426,
    tNurbsOrder = 427,
    tNurbsKnots = 428,
    tColor = 429,
    tColorTable = 430,
    tFor = 431,
    tIn = 432,
    tEndFor = 433,
    tIf = 434,
    tElseIf = 435,
    tElse = 436,
    tEndIf = 437,
    tExit = 438,
    tAbort = 439,
    tField = 440,
    tReturn = 441,
    tCall = 442,
    tSlide = 443,
    tMacro = 444,
    tShow = 445,
    tHide = 446,
    tGetValue = 447,
    tGetStringValue = 448,
    tGetEnv = 449,
    tGetString = 450,
    tGetNumber = 451,
    tUnique = 452,
    tHomology = 453,
    tCohomology = 454,
    tBetti = 455,
    tExists = 456,
    tFileExists = 457,
    tGetForced = 458,
    tGetForcedStr = 459,
    tGMSH_MAJOR_VERSION = 460,
    tGMSH_MINOR_VERSION = 461,
    tGMSH_PATCH_VERSION = 462,
    tGmshExecutableName = 463,
    tSetPartition = 464,
    tNameToString = 465,
    tStringToName = 466,
    tAFFECTPLUS = 467,
    tAFFECTMINUS = 468,
    tAFFECTTIMES = 469,
    tAFFECTDIVIDE = 470,
    tOR = 471,
    tAND = 472,
    tEQUAL = 473,
    tNOTEQUAL = 474,
    tLESSOREQUAL = 475,
    tGREATEROREQUAL = 476,
    tLESSLESS = 477,
    tGREATERGREATER = 478,
    tPLUSPLUS = 479,
    tMINUSMINUS = 480,
    UNARYPREC = 481
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 164 "Gmsh.y" /* yacc.c:355  */

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;

#line 515 "Gmsh.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE gmsh_yylval;

int gmsh_yyparse (void);

#endif /* !YY_GMSH_YY_GMSH_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 532 "Gmsh.tab.cpp" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   14779

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  587
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2068

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   481

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   246,     2,   231,   233,     2,
     239,   240,   229,   227,   248,   228,   245,   230,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     221,     2,   223,   216,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   241,     2,   242,   238,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   243,   232,   244,   247,     2,     2,     2,
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
     215,   217,   218,   219,   220,   222,   224,   225,   226,   235,
     236,   237
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   266,   266,   267,   272,   274,   278,   279,   280,   281,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   319,   323,   330,   335,
     340,   354,   367,   380,   408,   422,   435,   448,   467,   472,
     473,   474,   475,   476,   480,   482,   487,   489,   495,   599,
     494,   617,   624,   635,   634,   652,   659,   670,   669,   686,
     703,   726,   725,   739,   740,   741,   742,   743,   747,   748,
     754,   754,   755,   755,   761,   762,   763,   764,   769,   775,
     837,   852,   881,   891,   896,   904,   909,   917,   926,   931,
     943,   960,   966,   975,   993,  1011,  1020,  1032,  1037,  1045,
    1065,  1088,  1099,  1107,  1129,  1152,  1190,  1211,  1223,  1237,
    1237,  1239,  1241,  1250,  1260,  1259,  1280,  1279,  1297,  1307,
    1306,  1320,  1322,  1330,  1336,  1341,  1367,  1369,  1372,  1374,
    1378,  1379,  1383,  1395,  1408,  1423,  1432,  1445,  1447,  1451,
    1452,  1457,  1465,  1474,  1482,  1496,  1514,  1518,  1525,  1534,
    1537,  1544,  1547,  1554,  1578,  1594,  1610,  1647,  1687,  1703,
    1719,  1741,  1757,  1776,  1792,  1813,  1824,  1830,  1836,  1843,
    1874,  1889,  1911,  1934,  1957,  1980,  2004,  2028,  2052,  2078,
    2095,  2111,  2129,  2147,  2177,  2207,  2206,  2236,  2238,  2240,
    2242,  2244,  2252,  2254,  2256,  2258,  2266,  2268,  2270,  2278,
    2280,  2282,  2284,  2294,  2310,  2326,  2342,  2358,  2374,  2409,
    2431,  2455,  2456,  2461,  2464,  2468,  2489,  2508,  2529,  2544,
    2560,  2578,  2629,  2650,  2672,  2695,  2800,  2816,  2851,  2873,
    2895,  2901,  2916,  2944,  2956,  2965,  2972,  2984,  3003,  3009,
    3015,  3022,  3029,  3036,  3048,  3121,  3139,  3156,  3171,  3204,
    3216,  3240,  3244,  3249,  3256,  3261,  3271,  3276,  3282,  3290,
    3294,  3298,  3307,  3371,  3387,  3404,  3421,  3443,  3465,  3500,
    3508,  3516,  3522,  3529,  3536,  3556,  3582,  3594,  3605,  3623,
    3641,  3660,  3659,  3684,  3683,  3710,  3709,  3734,  3733,  3756,
    3772,  3789,  3806,  3829,  3832,  3838,  3850,  3870,  3874,  3878,
    3882,  3886,  3890,  3894,  3898,  3907,  3920,  3921,  3922,  3923,
    3924,  3928,  3929,  3930,  3931,  3932,  3935,  3958,  3977,  3999,
    4002,  4018,  4021,  4038,  4041,  4047,  4050,  4057,  4060,  4067,
    4084,  4125,  4169,  4208,  4233,  4242,  4272,  4298,  4324,  4356,
    4383,  4409,  4435,  4461,  4487,  4509,  4520,  4568,  4617,  4629,
    4640,  4644,  4654,  4665,  4666,  4667,  4671,  4677,  4689,  4707,
    4735,  4736,  4737,  4738,  4739,  4740,  4741,  4742,  4743,  4750,
    4751,  4752,  4753,  4754,  4755,  4756,  4757,  4758,  4759,  4760,
    4761,  4762,  4763,  4764,  4765,  4766,  4767,  4768,  4769,  4770,
    4771,  4772,  4773,  4774,  4775,  4776,  4777,  4778,  4779,  4780,
    4781,  4782,  4783,  4784,  4785,  4786,  4787,  4796,  4797,  4798,
    4799,  4800,  4801,  4802,  4803,  4804,  4805,  4806,  4811,  4810,
    4818,  4820,  4825,  4830,  4834,  4839,  4844,  4848,  4852,  4856,
    4860,  4864,  4868,  4874,  4890,  4895,  4901,  4907,  4926,  4947,
    4980,  4984,  4989,  4993,  4997,  5001,  5006,  5011,  5021,  5031,
    5036,  5047,  5056,  5061,  5066,  5094,  5095,  5101,  5102,  5108,
    5107,  5130,  5132,  5137,  5146,  5148,  5154,  5155,  5160,  5164,
    5168,  5172,  5176,  5183,  5187,  5191,  5195,  5202,  5207,  5214,
    5219,  5223,  5228,  5232,  5240,  5251,  5255,  5267,  5275,  5283,
    5290,  5300,  5323,  5329,  5340,  5346,  5356,  5366,  5376,  5389,
    5393,  5399,  5411,  5415,  5419,  5423,  5441,  5449,  5457,  5486,
    5496,  5512,  5523,  5528,  5532,  5536,  5548,  5552,  5564,  5581,
    5591,  5595,  5610,  5615,  5622,  5626,  5631,  5645,  5662,  5666,
    5671,  5675,  5680,  5688,  5694,  5700,  5706,  5715,  5719,  5723,
    5731,  5737,  5743,  5747,  5755,  5763,  5770,  5780,  5785,  5790,
    5805,  5819,  5833,  5845,  5861,  5870,  5879,  5889,  5900,  5908,
    5916,  5920,  5939,  5946,  5952,  5959,  5967,  5966,  5976,  6000,
    6002,  6008,  6013,  6015,  6020,  6025,  6030,  6032,  6036,  6048,
    6062,  6066,  6073,  6081,  6089,  6100,  6102,  6105
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
  "tTotalMemory", "tCreateTopology", "tCreateTopologyNoHoles",
  "tDistanceFunction", "tDefineConstant", "tUndefineConstant",
  "tDefineNumber", "tDefineStruct", "tNameStruct", "tDimNameSpace",
  "tAppend", "tDefineString", "tSetNumber", "tSetString", "tPoint",
  "tCircle", "tEllipse", "tLine", "tSphere", "tPolarSphere", "tSurface",
  "tSpline", "tVolume", "tBlock", "tCylinder", "tCone", "tTorus",
  "tEllipsoid", "tQuadric", "tShapeFromFile", "tRectangle", "tDisk",
  "tWire", "tGeoEntity", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh", "tSetFactory",
  "tThruSections", "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled",
  "tTransfinite", "tPhysical", "tCompound", "tPeriodic", "tUsing",
  "tPlugin", "tDegenerated", "tRecursive", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
  "tBooleanSection", "tBooleanFragments", "tThickSolid", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tReverse", "tLayers", "tScaleLast", "tHole", "tAlias",
  "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
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
  "PhysicalId_per_dim_entity", "InSphereCenter", "CircleOptions", "Shape",
  "$@9", "GeoEntity", "GeoEntity123", "GeoEntity12", "GeoEntity02",
  "Transform", "MultipleShape", "ListOfShapes", "LevelSet", "Delete",
  "Colorify", "SetPartition", "Visibility", "Command", "Slide", "Loop",
  "Extrude", "$@10", "$@11", "$@12", "$@13", "ExtrudeParameters",
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
     465,   466,   467,   468,   469,   470,    63,   471,   472,   473,
     474,    60,   475,    62,   476,   477,   478,    43,    45,    42,
      47,    37,   124,    38,    33,   479,   480,   481,    94,    40,
      41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

#define YYPACT_NINF -1750

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1750)))

#define YYTABLE_NINF -533

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    9874,    77,    43, 10025, -1750, -1750,   -93,    52,    -7,   -71,
     -35,     4,   114,   248,   282,   306,   111,   316,   350,   124,
     129,    23,    88,    88,   138,   149,   173,    40,   178,   194,
      63,   207,   213,   234,   271,   307,   312,   318,   333,   338,
     347,   358,   483,   510,   620,   386,   -10,   401,  5325,   407,
     409,   567,   -59,   394,   568,   518,   296,   432,   591,   -75,
     478,   377,   377,   484,   441,    58, -1750, -1750, -1750, -1750,
   -1750,   500,    83,   649,   653,    20,    57,   664,   669,    67,
     763,   794,   808,  3791,   829,   607,   616,   650,    28,    71,
   -1750,   681,   685, -1750, -1750,   828,   854,   622, -1750, 10223,
     690, 10253,    42,    54, -1750, -1750, -1750,  9586,   675, -1750,
   -1750, -1750, -1750, -1750,   688, -1750, -1750, -1750, -1750, -1750,
   -1750, -1750, -1750, -1750, -1750,   -18, -1750, -1750, -1750, -1750,
      19, -1750,   927,   687,  4612,    66,   692,   930,  9586, 10193,
   10193, -1750,  9586, -1750, -1750, -1750, -1750, 10193, -1750, -1750,
   -1750, -1750,   691,   700,   928, -1750, -1750, 10283,    23,  9586,
    9586,  9586,   701,  9586,  9586,  9586,   702,  9586,  9586,  9586,
    9586,  9586,  9586,  9586, 10193,  9586,  9586,  9586,  9586,  5562,
     703, -1750,  7458, -1750, -1750, -1750,   704,  3791, 10193, -1750,
   -1750, -1750, -1750, -1750,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,   262,    88,    88,
      88,    88,    88,   705,    88,    88,   706, -1750, -1750, -1750,
      88,    88,   707, -1750, -1750, -1750,  5562,   824,   568,   710,
      88,    88,   714,   715,   716, -1750, -1750, -1750,  9586,  5799,
    9586,  9586,  6036,    23,    29, -1750, -1750,   713, -1750,  3411,
   -1750, -1750, -1750, -1750, -1750,   101,  9586,  7458,   719,   720,
    6273,  3791,  3791,  3791, -1750, -1750, -1750, -1750, -1750,   717,
    6510,   718,  8331,   942,  5562,   721,    28,   722,   725,   377,
     377,   377,  9586,  9586,  -151, -1750,   -16,   377,  8408,   195,
     -17,   723,   724,   730,   731,   733,   736,   738,  9586,  3791,
    3791,  3791,   739,    18,   973,   740, -1750,   974,   976, -1750,
     741,   742,   744, -1750, -1750,   745,  3791,   748,   749,   753,
   -1750,  9586, -1750,   977,   992,  9586,  9586,  9586,   376,  9586,
     766, -1750,   833,  9586,  9586,  9586, -1750, -1750,  9586, -1750,
      88,    88,    88,   774,   775,   776,    88,    88,    88,    88,
      88,    88,    88, -1750,    88, -1750, -1750, -1750,    88,    88,
     777,   780,    88,   784, -1750,   793,  1029,  1032,   796, -1750,
   -1750,  1034, -1750,  1035, -1750,    88,  9586, 12500,   108, 10193,
    7458,  9586, -1750, -1750,  5562,  5562, -1750,   799, 10283,   528,
    1036, -1750, -1750, -1750, -1750, -1750, -1750,  9586,  9586,    35,
    5562,  1039,   498,  2139,   803,  1041,    37,   807, -1750,   809,
   10471,  9586, -1750,  2283,  -162, -1750,    59,  -127, 10467, -1750,
    -114, -1750,    60,   -51,     3,   964, -1750,    23,   804,   806,
   13016, 13041, 13066,  9586, 13091, 13116, 13141,  9586, 13166, 13191,
   13216, 13241, 13266, 13291, 13316,   815, 13341, 13366, 13391,  9457,
    1049,  9586,  7458,  8044, -1750,    91,  9586,  1054,   819,  9586,
    9586,  9586,  9586,  9586,  9586,  9586,  9586,  9586,  9586,  9586,
    9586,  9586,  9586,  9586,  9586,  7458,  9586,  9586,  9586,  9586,
    9586,  9586,  7458,  7458,   818,  9586,  9586, 10193,  9586, 10193,
    5562, 10193, 10193, 10193,  9586,    78,  9586,  5562,  3791, 10193,
   10193,  7458,    23, 10283,    23,   825,  7458,   825, -1750,   825,
   13416, -1750,   135,   817,    80, -1750,  1000,  9586,  9586,  9586,
    9586,  9586,  9586,  9586,  9586,  9586,  9586,  9586,  9586,  9586,
    9586,  6747,  9586,  9586,  9586,  9586,  9586,    23,  9586,  9586,
    1061, -1750,   679, 13441,   223,  9586,  9586,  9586, -1750,  1059,
    1060,  1060,   830,  9586,  9586,  1064,  7458,  7458, 12528,   831,
    1066, -1750,   834, -1750, -1750,  -121, -1750, -1750, 10500, 10533,
     377,   377,    66,    66,  -119,  8408,  8408,  9586,  5155,  -105,
   -1750,  9586,  9586,  9586,  9586,  9586,  9586,  9586,  9586,  9586,
   13466,  1071,  1067,  1072,  9586,  1074,  9586, -1750,  9586,  5392,
   -1750, -1750,  7458,  7458,  7458,  9586,  1075,  9586,  9586,  9586,
   13491, -1750, -1750, 13516, 13541, 13566,   908, 10566, -1750,   841,
    8279, 13591, 13616, 12611, 10193, 10193, 10193, 10193, 10193, 10193,
   10193, 10193, 10193,  9586, 10193, 10193, 10193, 10193,     9, 10283,
   10193, 10193, 10193,    23,    23, -1750, -1750,  7458, -1750,  5629,
   -1750,  5866,  9586,   825,  9586, -1750,    23,  9586,  9586,  1061,
     843,   334, 13641, 10406,   846,   370,  9586,  1081,   845,   847,
     848,   849,  9586, 13666, 12638,   145,   844,  1087,  1089, -1750,
   -1750, -1750,  7458,   189, -1750, -1750, -1750,    23,  9586,  9586,
    1061,   855, -1750,   858,   -48,   518, -1750,   867,  9704, -1750,
      34,  7458,    23,  9586,  9586,  1094,  1105,  7458,  9586,  1110,
   10193,    23,  8645,  1094,  1111, -1750,    23,  1112, 10193,  9586,
     879,   882, -1750,  9586, 10283,  1117,  1119,  1121, 13691,  1122,
    1124,  1125, 13716,  1129,  1130,  1132,  1135,  1136,  1138,  1139,
   -1750,  1140,  1141,  1145, -1750,  9586, 13741,  7458,   910,  7458,
   11688, -1750,  1148, 12584, 12584, 12584, 12584, 12584, 12584, 12584,
   12584, 12584, 12584, 12584, 10599, 12584, 12584, 12584, 12584,  2249,
     434, 12584, 12584, 12584, 10632, 10665, 10698,  8044,   915,   914,
      89,  7458, 10731, 10764,   434, 10797,   434,   909,   911,   913,
     -65, 14541, -1750,   434, 11717, -1750,   916,  -110,   434,  -188,
     918,   474,   422,  1155, -1750,  1094,   434,   920,  8363,  8600,
     677,  1415,   554,   554,   468,   468,   468,   468,   468,   468,
     254,   254,  7458,   242, -1750,   242,   242,   825,   825,   825,
     921, 13766, 12665,     5,   531,  7458, -1750,  1158,   925, 13791,
   13816, 13841,  9586,  5562,  1166,  1165,  8099, 11746, 13866, -1750,
     463,   472,  7458,   932, -1750,  6103, -1750,  6340,  6577,   377,
    9586,  9586, -1750, -1750,   929,   934,  8408,  9226,  1051,   289,
     377,  6814, 13891, 11775, 13916, 13941, 13966, 13991, 14016, 14041,
   14066,  1176,  9586,  1175, -1750,  9586, 14091, -1750, 12692, 12719,
   -1750,   515,   516,   517, 11804, -1750, 12746, 12773, 10830, -1750,
    1177,  1179,  1181,   944,  9586,  7051,  9586,  9586, -1750, -1750,
      16,   200,   295,   200,   951,   952,   945,   434,   434,   947,
   10863,   434,   434,   434,   434,  9586,   434,  1163, -1750,   948,
     957,   351,   317,   958,   525, -1750, -1750, 12584,   242,  7288,
     954,   632,   955,  1024,  1197,  1057,  8729,   963,   966,  1204,
    5562, 11833, -1750,  9586,  9586,  9586,  9586,  2315,   159,    81,
   10283,  9586,  1205,  1208,    32, -1750,   545,  1167,  1168,  5562,
      22,   970, 14116, 12800,   438,  9586,  9586,   978,   979,  7458,
   -1750, -1750, -1750, -1750, 10193,   -12,   971, 14141, 12827, -1750,
     981, -1750,   166, 10896, -1750, -1750, -1750,   982, -1750,   983,
   -1750,    72, -1750, -1750, 14541, -1750,  1217, 12584,   434,   377,
    5562,  5562,  1219,  5562,  5562,  5562,  1221,  5562,  5562,  5562,
    5562,  5562,  5562,  5562,  5562,  5562,  5562,  2713,  1222,  7458,
    8044, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750,
   -1750, -1750, -1750, -1750, -1750,  9586, -1750, -1750, -1750, -1750,
   -1750, -1750, -1750, -1750, -1750,  9586,  9586,  9586, -1750, -1750,
   -1750,   546,  9586,  9586, -1750,  9586, -1750,  5562, 10193, 10193,
   -1750,   984, -1750, -1750,  9586,  9586, -1750, -1750, -1750,  1094,
   -1750,  1094,  9586,  9586,   990, -1750,  5562,    88, -1750,  9586,
    9586,  9586,   547,  1094,     5,  -181, -1750,  9586,  9586,   434,
     552,  5562,  7458,  1224,  1226,  1227,  8917, -1750, -1750,  1218,
   -1750,   995, 14541,   988, -1750,  1230,  1231,  1233,   555,  1239,
   -1750,  9614, -1750, -1750,  -103, 10929, 10962, -1750, -1750, 11862,
    -109,  1142,  1240,  8961,  1002,  1243,  1011,    36,    45,   308,
   -1750,   -81, -1750,   289,  1245,  1247,  1248,  1252,  1253,  1259,
    1260,  1261,  1263,  5562, 14541, -1750,  2842,  1028,  1266,  1267,
    1268,  1157,  1269, -1750,  1272,  1276,  9586,  5562,  5562,  5562,
    1279, 10995, -1750,  8676,  1174,  1280,  1281, -1750,  7458, -1750,
   -1750, -1750, -1750, 10193, -1750, -1750,  9586, 10193, -1750, -1750,
   -1750, -1750, 14541, -1750,  1040,  1045, 10193, -1750, 10193, -1750,
    1094, 10193,  1058, -1750,  1052, -1750,  1094,  9586,  9586,  1046,
     568,  1048,  9045, -1750,  3018,  1056,  5562, -1750,  1062, -1750,
   11891, 11920, 11949, 11978, -1750, -1750,  9586,  1291,    44,  9586,
    1295,  1296,  3253, -1750,  1297,    28,  1299,  1070,   434,    88,
      88,  1301, -1750,  1069,  1076,  1073, -1750,  1308, -1750, -1750,
   -1750, -1750, -1750,  1094,   447,  2969,  9586, 12854, 14166,  9586,
    9586,   557,  1311,   122,  1094, -1750,  1077,  9586,  1312,  9586,
    1094,  9277,  7690,   434,  4093,  1082,  1055, -1750,  1317,  1319,
      87,  1203,  1203,  5562,  1322,  1323,  1324,  5562,  1154,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334, -1750,  1336,
     558, 12584, 12584, 12584, 12584,   434, 11028, 11061, 11094,  1103,
     434,   434,  1217,   434, 14191, 12584,  1107,   113, 14541, 12584,
   -1750,  1342,   434, 11127, 14541, 14541, -1750,   651, -1750,  1345,
   -1750, 14216, 12881, -1750,   434,  1344,   560,  5562,  5562,  5562,
    1347,  1348, -1750,   196,  9586,  5562,  1113,  1114,  1351,   686,
   -1750,  9586,  9586,  9586,  1116,  1120,  1123,  1127, -1750,  3380,
    5562, -1750,  9586, -1750,  1354, -1750,  1356, -1750, -1750,  8408,
     413,  4851, -1750,  1126,  1128,  1131,  1133,  1134,  1144,  6984,
    1358, -1750,  7458, -1750, -1750, -1750,  1178,  9586, -1750, -1750,
   12908,  1359,  1364,  1199, -1750,  9586,  9586,  9586, -1750,  1367,
     698,   352,  1137,  8992,  1160,  9586,    24,   434,  1143,   434,
    1161, -1750, -1750, 10283,   672,  9586,  1183, -1750, -1750,  3481,
   -1750, -1750,  1184,  1369, -1750, -1750, -1750, -1750,  3531, -1750,
     185,  1182,  1372,  3844, -1750, -1750, -1750,    28, -1750,   563,
   -1750,  9586,   196,   683,  1053, -1750,  1149,  9586,  9586,  5562,
    1191, -1750,   485,  1377,  1376, 14241,  1378,  1155, 14266, 14291,
    1405, -1750, -1750, 10193,  1196,  1432, 14316, -1750, 11160,  1198,
   -1750,  4375, 14541, -1750,  1433,    88,  6036, -1750, -1750, -1750,
   -1750,  1217, -1750, -1750, -1750,   377,  1435,  1436,  1437, -1750,
   -1750, -1750,  1439,  1352,  1440, -1750, -1750, -1750, -1750, -1750,
   -1750, -1750, -1750, -1750,  1434,  1206, -1750, -1750, -1750, -1750,
   -1750,  9586,  9586,  9586, -1750, -1750, -1750,  1055, -1750, -1750,
   -1750, -1750,  9586,  1212,  1200, -1750, -1750,  9586,  9586,  9586,
     434,     5, -1750, -1750, -1750, -1750,  1211,  1449,  1154,  1451,
    9586, -1750,  5562, 14541,   924,  7458,  7458,  9586, -1750,  8099,
   12007, 14341,  9310,    66,    66,  9586,  9586, -1750,   301,  1210,
   14366, -1750, -1750, 12036,   -70, -1750,  1453,  1454,  5562,   377,
     377,   377,   377,   377,  5088,  1455, -1750,   566,  9586,  4029,
    1456, -1750, -1750,  5562, 10401,  1698, 14391, -1750, -1750,  7776,
   -1750, 10193,  9586, -1750, 10193, 14541,  8013, 10283,  1215, -1750,
   -1750, -1750, -1750,  1225,  1216,  9586,  9586, 12065,  9586, 10406,
   -1750, 10406,  5562, -1750, -1750, 10283,  9586,  1460,  1463,    32,
   -1750,  1462, -1750,    28, 12935,  5562, 10193,  1465,   434, -1750,
    1228,   434,  9586, 11193, 11226,   571, -1750,  9586,  9586,   467,
   -1750,  1229, -1750,  1227,  1230, -1750,  1467,  9586, -1750, -1750,
    9586,  9354, -1750, -1750,  1232,  1053,   572,  7395,  1470, -1750,
     201, -1750, -1750, -1750, -1750,  1236, -1750,  1464,  5562, 12584,
   12584, 11259, 12584, -1750,  1234, 11292, 14416, 12962, -1750, -1750,
    9586, -1750,  1474, -1750, 14541,  1475,  1241, -1750,   573,   574,
   12556,  4131,  1476,  1242, -1750, -1750,  9586,  1244,  1246, 12094,
   12989,  1480,  5562,  1482,  1249,  9586, -1750, -1750,   579,   -58,
     -55,   -33,    -4,   141,  7221,   148, -1750,  1481, 12123, -1750,
   -1750,  1321, -1750,  9586,  9586, -1750, -1750,  7458,  4312,  1485,
    1254, 12584,   434, 14541, -1750, -1750, -1750, -1750,    24, -1750,
   10283, -1750, 12152,  1255,  1256,  1257,  1490,  4485, -1750,  1495,
    1491, -1750, -1750,  1258,  1498,   580, -1750,  1501,  1502,   184,
   14541,  9586,  9586,  1270,  5562,   582, 14541, 14441, -1750, 14466,
   11325, -1750,   984,  1045,  5562,   434, -1750,  9586, 10283,    23,
    9586,  1503,   587, -1750, -1750,  9586,  1200, -1750,  9586, -1750,
   -1750, 12181, -1750, -1750,  5562,   414,   522,  7458, -1750, -1750,
      66, 10434, -1750, -1750, -1750,  1504, -1750,  1271,  5562, -1750,
   12210,  1505,  7458,   377,   377,   377,   377,   377, -1750, -1750,
    9586, 12239, 12268,   592, -1750, -1750, -1750, -1750, -1750, -1750,
    1274,  1506,  1277, -1750,  1511, -1750, -1750,    28, -1750,  1346,
   -1750, -1750, -1750, -1750, -1750,  9586, 11358, 11391,  5562, -1750,
    1513,  9586,  1282, -1750,  9586,  1278,  1283, -1750, -1750,  7722,
   -1750,  1284, 12297, -1750,  1286, 11424,  1290, 11457, -1750,   595,
    1288,   377,  5562,  1520,  1294,   377,  1527,   597,  1298, -1750,
    9586, -1750,  1528,  1409,  9653,  1300, -1750,   600,   157,   188,
     199,   203,   228,  4540, -1750, -1750,  1533,  1534, -1750, -1750,
   -1750,  1535, -1750,  1302, 14541,  9586,  9586,   603, -1750, 14541,
   11490, -1750, -1750,   984, 10283,  1304, -1750,  9586,  9586, -1750,
    9586,  1540,   377,   105, -1750, -1750,   377,   136, -1750,  1542,
   -1750, 12326, -1750,  9586, -1750,   289, -1750,  1545,  7458,  7458,
    7458,  7458,  7221, -1750, -1750, -1750, 10406, -1750,  9586, 14491,
   11523,    31,  9586,  1313, -1750, -1750, 11556, 11589, 11622, -1750,
     233, -1750,   288, -1750, -1750, -1750,  4787,   429,  9744, -1750,
     605,   608,   613,   614,   313,   621,  1314,   624, -1750,  9586,
   -1750,  5562, 12355, -1750,  9586,  9586,  9586,   377,   377, -1750,
   -1750, -1750,   289,  1549,  1554,  1560,  1561,  7458,  1562,  1564,
    1565,  1335, 14516,   626,  1566, 12384, 12584, 11655,   322,   328,
     442, -1750, -1750, -1750, -1750,   635, -1750, -1750, -1750, 10193,
   -1750,  1337, -1750,  1567, -1750,  9586,  9586,  9586, -1750,  1568,
     637, -1750,  1340,  5562, -1750, 12413, 12442, 12471, -1750,  1570,
   10193, 10193,   638, -1750,  1571,  1573, -1750, -1750,   640, -1750,
    1579, -1750, -1750,  1580, 10193, -1750, -1750, -1750
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   585,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,   188,     0,     0,
     189,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,   307,   308,   309,
     310,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,   276,   277,     0,     0,     0,   271,     0,
       0,     0,     0,     0,   353,   354,   355,     0,     0,     5,
       6,     7,     8,    10,     0,    11,    24,    12,    13,    14,
      15,    23,    22,    21,    16,     0,    17,    18,    19,    20,
       0,    25,     0,   586,     0,   213,     0,     0,     0,     0,
       0,   255,     0,   257,   258,   253,   254,     0,   259,   260,
     111,   121,   585,   466,   461,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,   199,   200,   201,     0,     0,     0,   407,
     408,   410,   411,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   415,   416,   417,
       0,     0,   187,   188,   189,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   412,   413,   414,     0,     0,
       0,     0,     0,     0,     0,   495,   496,     0,   497,   479,
     360,   420,   423,   290,   480,   461,     0,     0,     0,     0,
       0,     0,     0,     0,   187,   185,   192,   193,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,     0,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   585,     0,     0,   213,     0,     0,   350,
       0,     0,     0,   196,   197,     0,     0,     0,     0,     0,
     486,     0,   485,     0,     0,     0,     0,     0,   585,     0,
       0,   518,     0,     0,     0,     0,   251,   252,     0,   537,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   539,     0,   563,   541,   542,     0,     0,
       0,     0,     0,     0,   540,     0,     0,     0,     0,   269,
     270,     0,   213,     0,   213,     0,     0,     0,   461,     0,
       0,     0,   213,   356,     0,     0,    76,     0,    63,     0,
       0,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,     0,     0,     0,     0,   524,   461,     0,   212,     0,
     211,     0,   166,     0,     0,   524,   525,     0,     0,   575,
       0,   576,   525,   109,   109,     0,   459,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,   513,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   363,     0,   362,   487,   364,
       0,   481,     0,     0,   461,   492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
       0,   437,     0,     0,     0,     0,     0,     0,   291,     0,
     323,   323,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,     0,   213,   213,     0,   470,   469,     0,     0,
       0,     0,   213,   213,     0,     0,     0,     0,   287,     0,
     213,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   325,     0,     0,     0,     0,     0,   234,     0,     0,
     232,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   333,   250,     0,     0,     0,     0,     0,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   272,     0,   238,     0,
     239,     0,     0,   362,     0,   213,     0,     0,     0,     0,
       0,     0,     0,   311,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      72,    73,     0,     0,   248,    38,   244,     0,     0,     0,
       0,     0,   208,     0,     0,     0,   214,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,   464,
       0,     0,   462,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     317,     0,     0,     0,   191,     0,     0,     0,     0,     0,
       0,   347,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     461,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   418,   436,     0,     0,   493,     0,     0,     0,     0,
       0,   455,     0,   361,   482,     0,     0,     0,   489,     0,
     380,   379,   377,   378,   373,   375,   374,   376,   382,   381,
     366,   365,     0,   367,   488,   368,   371,   369,   370,   372,
     462,     0,     0,   463,   440,     0,   498,     0,     0,     0,
       0,     0,     0,     0,   321,     0,     0,     0,     0,   349,
       0,     0,     0,     0,   348,     0,   213,     0,     0,     0,
       0,     0,   472,   471,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,     0,     0,   233,     0,     0,
     228,     0,     0,     0,     0,   346,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,   274,   275,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   566,     0,
       0,     0,   457,     0,     0,   240,   242,     0,   367,     0,
     462,   440,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,   361,     0,
      63,     0,     0,     0,     0,    79,     0,    63,    64,     0,
       0,   462,     0,     0,   440,     0,     0,     0,     0,     0,
     582,    28,    26,    27,     0,     0,     0,     0,     0,   463,
     528,    29,     0,     0,   245,   577,   578,     0,   579,   528,
      74,   112,    75,   122,   465,   467,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     514,   515,   202,     9,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   406,   393,     0,   395,   396,   397,   398,
     399,   511,   400,   401,   402,     0,     0,     0,   503,   502,
     501,     0,     0,     0,   508,     0,   452,     0,     0,     0,
     454,   126,   435,   491,     0,     0,   421,   510,   426,     0,
     432,     0,     0,     0,     0,   483,     0,     0,   433,     0,
       0,     0,     0,     0,   425,   424,   447,    70,    71,     0,
       0,     0,     0,     0,     0,   361,   319,   324,   322,     0,
     332,     0,   146,   147,   195,   361,     0,     0,     0,     0,
     229,     0,   241,   243,     0,     0,     0,   203,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     293,     0,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   326,   335,     0,     0,     0,     0,
       0,     0,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,   235,     0,     0,     0,     0,   553,     0,   560,
     549,   550,   551,     0,   565,   564,     0,     0,   554,   555,
     556,   562,   569,   568,     0,   137,     0,   543,     0,   545,
       0,     0,     0,   538,     0,   237,     0,     0,     0,     0,
       0,     0,     0,   312,     0,     0,     0,   357,     0,   583,
       0,     0,     0,     0,   101,    63,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,    61,     0,    39,    40,
      41,    42,    43,     0,   425,   424,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,   526,     0,     0,     0,
       0,     0,     0,     0,   133,     0,   129,   130,     0,     0,
       0,   151,   151,     0,     0,     0,     0,     0,   149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   455,   456,     0,
     428,     0,     0,     0,   490,   383,   484,   441,   439,     0,
     438,     0,     0,   499,     0,     0,     0,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,     0,     0,     0,     0,   298,     0,
       0,   297,     0,   300,     0,   302,     0,   288,   294,     0,
       0,     0,   227,     0,     0,     0,     0,     0,     0,     0,
       0,   337,     0,   231,   230,   352,     0,     0,    35,    36,
       0,     0,     0,     0,   519,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,   458,   547,     0,   441,     0,     0,   213,   313,     0,
     314,   213,     0,     0,   533,   534,   535,   536,     0,    86,
       0,     0,     0,     0,    84,    91,    93,     0,   522,     0,
      99,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    34,   441,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    31,     0,   529,     0,     0,    32,     0,   529,
     580,     0,   113,   118,     0,     0,     0,   132,   135,   136,
     460,     0,    77,    78,   153,     0,     0,     0,     0,   154,
     169,   170,     0,     0,     0,   155,   180,   171,   175,   176,
     172,   173,   174,   161,     0,     0,   394,   403,   404,   405,
     504,     0,     0,     0,   450,   451,   453,   127,   419,   449,
     422,   427,     0,     0,   455,   181,   434,     0,    70,    71,
       0,   446,   442,   444,   505,   177,     0,     0,   149,     0,
       0,   330,     0,   148,     0,     0,     0,     0,   249,     0,
       0,     0,     0,   213,   213,     0,     0,   299,   479,     0,
       0,   301,   303,     0,     0,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   178,     0,     0,     0,
       0,   158,   159,     0,     0,     0,     0,   102,   106,     0,
     561,     0,     0,   559,     0,   570,     0,     0,   138,   139,
     567,   544,   546,     0,     0,     0,     0,     0,     0,   311,
     315,   311,     0,   358,    85,    63,     0,     0,     0,     0,
      83,     0,   520,     0,     0,     0,     0,     0,     0,   573,
     572,     0,     0,     0,     0,     0,   477,     0,     0,   446,
     246,   442,   247,     0,     0,   215,     0,     0,   532,   530,
       0,     0,   114,   119,     0,     0,     0,   512,   513,   131,
     152,   156,   157,   162,   179,     0,   164,     0,     0,     0,
       0,     0,     0,   429,     0,     0,     0,     0,   500,   448,
       0,   163,     0,   182,   320,     0,     0,   183,     0,     0,
       0,     0,     0,     0,   476,   475,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   225,     0,     0,
       0,     0,     0,     0,     0,     0,   216,     0,     0,   334,
      37,     0,   517,     0,     0,   266,   265,     0,     0,     0,
       0,     0,     0,   141,   142,   145,   144,   143,     0,   548,
       0,   584,     0,     0,     0,     0,     0,     0,    96,     0,
       0,    97,   523,     0,     0,     0,    88,     0,     0,     0,
      44,     0,     0,     0,     0,     0,    46,     0,    33,     0,
       0,   581,   126,   137,     0,     0,   134,     0,     0,     0,
       0,     0,     0,   506,   507,     0,   455,   430,     0,   443,
     445,     0,   165,   186,     0,   327,   327,     0,   107,   108,
     213,     0,   206,   207,   289,     0,   295,     0,     0,   213,
       0,     0,     0,     0,     0,     0,     0,     0,   210,   209,
       0,     0,     0,     0,   103,   104,   552,   558,   557,   140,
       0,     0,     0,   316,     0,    92,    94,     0,   100,     0,
      82,   574,    89,    90,    49,     0,     0,     0,     0,   478,
       0,     0,   443,   531,     0,     0,     0,   116,   571,     0,
     123,     0,     0,   168,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   474,
       0,   305,     0,     0,   283,     0,   217,     0,     0,     0,
       0,     0,     0,     0,   516,   267,     0,     0,   345,   213,
     359,     0,   521,     0,    45,     0,     0,     0,    62,    47,
       0,   115,   120,   126,     0,     0,   150,     0,     0,   431,
       0,     0,     0,     0,   328,   338,     0,     0,   339,     0,
     204,     0,   296,     0,   279,     0,   213,     0,     0,     0,
       0,     0,     0,   160,   105,   263,   311,    98,     0,     0,
       0,     0,     0,     0,   124,   125,     0,     0,     0,   184,
       0,   342,     0,   343,   344,   473,     0,     0,   285,   220,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
      59,     0,     0,   117,     0,     0,     0,     0,     0,   304,
     284,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,   222,   223,   224,     0,   218,   318,    50,     0,
      57,     0,   256,     0,   509,     0,     0,     0,   286,     0,
       0,    51,     0,     0,   262,     0,     0,     0,   219,     0,
       0,     0,     0,   494,     0,     0,    54,    52,     0,    55,
       0,   340,   341,     0,     0,    60,    58,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1750, -1750, -1750, -1750,   314, -1750, -1750, -1750, -1750,  -370,
   -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750, -1750,
   -1750, -1750,  -678,  -131,  2528,  2635, -1750,  1159, -1750, -1750,
   -1750, -1750, -1750, -1750, -1749, -1750,   267,   100,  -191, -1750,
    -153, -1750,    48,   305,  1596, -1750,    -1,   895, -1750, -1750,
      -2,  -552,  -287, -1750, -1750, -1750, -1750, -1750, -1750, -1750,
   -1750,  1599, -1750, -1750, -1750, -1750, -1148, -1145,  1600, -1605,
    1601, -1750, -1750, -1750,  1044, -1750,  -200, -1750, -1750, -1750,
   -1750,  1731, -1750, -1750, -1318,   191,  1605, -1750,     0,  -650,
   -1750, -1750,   168, -1750, -1566,   -28,  -170,  1043,  1838,  -278,
     -15, -1750,   778,   -43, -1750, -1750,     6,   161, -1571,  -141,
     893, -1750,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   109,   994,   110,   111,   980,  1769,  1775,
    1258,  1456,  1913,  2040,  1259,  2011,  2058,  1260,  2042,  1261,
    1262,  1460,   410,   551,   552,  1060,   112,   726,   433,  1782,
    1923,  1783,   434,  1666,  1323,  1285,  1286,  1287,  1417,  1608,
    1609,  1121,  1504,  1496,   706,   562,   254,   280,   326,   187,
     255,   419,   420,   116,   117,   118,   119,   120,   121,   122,
     123,   256,  1153,  1945,  2002,   879,  1149,  1150,   257,   957,
     258,   127,  1351,  1119,   854,   893,  1883,   128,   129,   130,
     131,   259,   260,  1081,  1094,  1212,   261,   731,   262,   844,
     730,   436,   577,   295,  1645,   332,   333,   264,   522,   340,
    1246,  1449,   429,   425,  1205,   936,  1489,  1638,  1639,   921,
     431,   133,   388
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     134,   115,   114,   411,  1378,  1380,   430,   971,   572,  1533,
     141,   588,  1718,   152,  1753,   979,  1754,   467,   154,   951,
     263,   153,   605,  1185,   313,   393,  1252,   152,  1606,   609,
     874,   875,   338,  1865,   525,  1746,   152,  1990,   269,   685,
     991,   152,  1373,     5,   162,   265,   697,   381,  1440,   269,
     984,  1375,  1088,   275,   405,   406,   376,  1089,   380,   383,
     270,   318,   300,   319,  1339,  1000,   137,   166,   712,   721,
     417,   987,   317,  1009,   285,   342,   580,   581,   710,  1282,
     265,   183,   152,     4,   184,   341,   711,   185,  1235,   437,
     138,   415,   582,  1494,  1785,   659,   377,   661,   547,   286,
     186,   559,   560,   561,   314,   673,   580,   581,   580,   581,
     547,  1971,  1792,   716,   438,   287,   288,   666,   580,   581,
     143,   717,   580,   581,   580,   581,   719,   869,  1472,   876,
     690,   416,   691,   418,   720,  1365,   426,   426,  1085,   601,
     602,   603,  1973,   880,   432,  1361,   580,   581,   320,   301,
     135,   460,   970,   302,   136,   439,   616,   580,   581,   303,
     304,   323,   305,   306,   324,  1097,  1235,  1379,   139,   580,
     581,   426,   580,   581,  1963,  1080,   265,   325,  1715,   265,
     309,   307,   310,   720,   265,   426,  1253,  1254,  1255,  1256,
    1822,   724,  1625,  1823,   580,   581,   977,   725,  1374,    60,
      61,    62,    63,  1235,   140,   315,   526,  1376,   263,   686,
     687,   580,   581,  1607,    74,  1824,  1684,    77,  1441,  1442,
     108,   391,   591,   580,   581,   392,   592,   583,  1273,   294,
     296,   108,   299,   265,   108,  1378,   759,   508,  1879,   108,
     405,   406,   558,   108,  1825,   727,   265,   142,   108,   265,
     524,   725,   565,   523,   144,   935,   570,   992,   394,   606,
     993,  1186,   395,   316,   265,   136,  1257,   265,   265,   265,
     265,   339,   405,   406,  1991,  1245,   698,   265,   699,   163,
    -525,   265,   700,   341,   865,   382,   867,   868,   145,   108,
    1236,  1239,  1917,   401,   402,   403,   404,   384,   713,   722,
     714,   714,   167,   881,   715,   723,   265,   265,   265,   527,
     343,   155,   146,   156,   580,   581,   405,   406,   690,   155,
     691,   156,   148,   265,   405,   406,  1238,   155,   548,   156,
     549,  1070,   580,   581,   550,   758,   405,   406,   805,   759,
     548,   915,   549,   405,   406,   992,   550,   667,   993,   668,
     147,  1986,   155,   669,   156,   677,   149,   401,   402,   403,
     404,  1092,   800,   580,   581,   150,   674,   675,   580,   581,
     151,   401,   402,   403,   404,   580,   581,   159,   949,   814,
     405,   406,   688,   759,   580,   581,   426,   265,   160,  1826,
     281,   265,   265,   282,   405,   406,  1827,   401,   402,   403,
     404,   978,   402,   403,   404,  1948,  1278,   265,   401,   402,
     403,   404,   161,   701,   759,   580,   581,   164,  1142,   707,
     405,   406,   580,   581,  1854,  2013,   580,   581,   580,   581,
     580,   581,  1855,   165,   732,  1143,  1949,  1142,   590,  1326,
     690,  1327,   691,  1144,  1145,  1146,   168,  1950,   720,  1147,
    1148,  1951,   169,  1337,  1143,   580,   581,   575,   576,   265,
     580,   581,  1144,  1145,  1146,   584,   589,   848,  1147,  1148,
     810,   759,   797,   170,   544,   545,  1952,  2052,  1876,   558,
     546,  1997,   265,   664,   542,   543,   544,   545,   271,   265,
     790,   272,   546,   273,   426,   923,   426,   265,   426,   426,
     432,   492,   803,   493,   265,   265,   426,   426,   265,   154,
     171,   154,   809,   265,   811,   580,   581,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   690,  1998,   691,   265,   546,
     580,   581,  1142,  1188,   840,  1711,   172,  1880,  1881,   580,
     581,   173,  1377,  1882,   972,   580,   581,   174,  1142,  1143,
    1420,  2007,  1210,   265,   265,  1211,  1424,  1144,  1145,  1146,
    2036,  1142,   175,  1147,  1148,  1143,  2037,   176,   953,  1131,
     418,   418,   759,  1144,  1145,  1146,   177,   707,  1143,  1147,
    1148,   690,   690,   691,   691,   179,  1144,  1145,  1146,  1208,
     759,   178,  1147,  1148,   290,   291,   938,   180,   707,   265,
     265,   265,   276,  1462,   959,   277,   292,   278,   960,   678,
     293,   626,   679,   136,  1474,   680,   181,   681,   279,   182,
    1479,   432,   426,   432,   426,   426,   426,   426,   426,   426,
     188,   426,   426,   426,   426,   937,   266,   426,   426,   426,
     154,   943,   267,   942,   265,  1884,  1885,  1575,   707,   274,
     707,  1882,   233,   950,   268,   234,  1095,   235,   290,   291,
     759,   283,   707,  2000,   690,  1552,   691,  1266,    41,  1218,
     292,  -528,   405,   406,   298,   284,  2038,   152,   349,   265,
    -527,  1018,  1558,  1559,   981,   539,   540,   664,   542,   543,
     544,   545,   405,   406,  1598,  1599,   546,  1126,   265,   996,
    -532,   759,  1106,   155,   265,   156,  1127,   432,  1007,  1091,
     759,   289,  1092,  1011,  1648,   426,  1616,   297,  -529,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   690,   308,
     691,   692,   359,   360,   361,   362,   311,   312,   872,   873,
     363,   364,   365,   576,   265,   366,   265,   367,   321,  1170,
    1171,  1172,  1626,   759,   759,   759,   322,   327,   368,  1214,
    1107,   369,  1108,   759,  1635,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,   265,  1248,
    1315,  1336,   546,   759,   759,   759,  1344,  1977,   328,  1358,
     759,  1470,  1515,   759,  1546,   759,   759,  1632,   759,   399,
    1727,  1633,   329,  1123,   759,  1773,  1786,  1805,  1806,  1774,
    1787,   759,   759,  1821,  1851,  1117,  1860,  1774,   720,   265,
    1861,  1874,  1378,   334,   346,  1774,  1906,  1237,  1240,  1931,
     759,  1939,   265,  1774,  1947,   759,   335,  1961,   759,  2003,
     265,  1774,  2004,   759,  2020,   336,   759,  2005,  2006,   265,
     347,   759,   759,   348,   707,  2008,   707,   707,  2010,   759,
    2031,  1217,  1861,  1218,  1774,  1378,   370,   371,   372,  2039,
     707,  2049,  2060,   759,  2063,  2050,  1774,   373,  2064,   337,
    1538,   374,  1539,   375,   108,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,  1615,   414,  1616,   707,   546,   389,   424,   427,   690,
     344,   691,   845,   690,   345,   691,  1636,  1241,  1696,   378,
    1697,   390,  1228,   396,   397,   421,   422,   437,   136,   435,
     443,   447,   461,   507,   500,   503,   569,   466,   707,   509,
     506,  1251,   455,   512,   513,   514,   392,   265,   555,   556,
     563,   566,   593,   594,   571,   573,   468,  1448,   574,   595,
     596,  1247,   597,  1338,  1340,   598,   265,   599,   604,   607,
     610,   608,   611,   621,   612,   613,   265,   614,   615,   617,
     618,   426,  1291,  1292,   619,  1294,  1295,  1296,   622,  1298,
    1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,   628,
     629,  1707,  1708,   637,   638,   639,   650,   265,   265,   651,
     265,   265,   265,   653,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   654,   655,   265,  1134,   656,   657,
     658,   660,   676,   682,  1140,   689,   695,   696,  1151,  1319,
     135,   729,   733,   702,   734,   750,   755,   152,   349,   762,
     761,   791,   815,   546,   817,   843,   852,   853,  1331,   856,
     859,   863,   864,   894,   265,   426,   426,   866,   892,   895,
     897,   905,   913,  1345,   916,   952,   958,   962,   963,   973,
     964,   965,   966,   265,   974,   975,   985,   986,   999,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   265,   265,
     989,  1001,   359,   360,   361,   362,  1004,  1010,  1012,  1015,
     363,   364,   365,  1016,  1019,   366,  1020,   367,  1021,  1023,
     707,  1024,  1025,  1338,  1340,  1390,  1027,  1028,   368,  1029,
    1619,   369,  1030,  1031,  1621,  1032,  1033,  1034,  1035,  1401,
    1402,  1403,  1036,  1039,  1043,  1068,  1069,  1077,  1090,  1078,
     265,  1079,  1096,  1099,  1084,  1111,  1103,   670,  1112,  1631,
    1118,  1120,  1204,  1137,   265,   265,   265,  1129,  1138,   399,
    1141,  1165,  1407,  1163,  1177,   265,  1178,  1290,  1179,  1180,
     426,  1191,  1192,  1193,   426,  1196,  1206,  1207,  1432,  1216,
    1213,  1220,  1219,   426,  1221,   426,  1222,  1225,   426,  1226,
    1227,  1243,  1244,  1249,  1250,  1263,  1274,  1269,  1270,  1426,
    1277,  1284,  1281,   265,  1352,   464,  1293,  1280,  1297,  1309,
    1330,  1347,  1322,  1348,  1349,  1353,  1354,  1355,  1356,  1483,
    1357,  1488,   341,  1359,  1367,  1370,   370,   371,   372,  1371,
    1372,  1366,  1381,  1382,  1396,  1383,  1487,   373,  1888,  1384,
    1385,   374,   426,   375,   108,  1498,  1386,  1387,  1388,  1502,
    1389,  1392,  1393,  1394,  1395,   794,  1397,   796,  1398,   798,
     799,   265,  1399,  1404,  1409,  1410,  1415,   806,   807,  1425,
     265,  1427,   518,  1416,   265,   464,  1636,  1439,  1422,  1431,
    1423,  1444,  1445,  1491,  1447,  1450,  1433,  1455,  1457,  1627,
     464,  1451,  1640,  1640,  1461,  1458,  1459,  1471,  1477,  1547,
    1548,  1549,  1475,  1492,  1490,  1493,  1495,  1554,  1499,  1500,
    1501,  1503,  1505,  1506,  1507,  1508,  1509,  1510,  1511,  1512,
    1513,  1514,  1569,  1524,   265,   265,   265,  1531,  1535,  1541,
    1545,  1550,   265,  1577,  1551,  1762,  1555,  1556,  1557,  1563,
    1571,  1585,  1572,  1564,  1586,  1591,  1565,   265,  1566,  1578,
    1592,  1579,  1593,  1597,  1580,  1623,  1581,  1582,   265,  1629,
    1614,  1649,  1650,  1611,  1652,  1601,   265,  1583,  1642,   265,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,  1604,  1211,
    1689,  1655,   546,   922,  1408,   924,   925,   926,   927,   928,
     929,  1588,   931,   932,   933,   934,  1618,  1628,   939,   940,
     941,  1646,  1622,   464,  1647,  1657,  1658,  1661,  1663,  1677,
    1664,  1671,  1672,  1673,   341,  1674,  1676,  1675,  1092,  1678,
     432,   432,  1683,  1662,  1690,  1691,   265,  1693,  1712,  1716,
    1717,  1726,  1730,  1748,  1750,  1749,  1758,  1759,  1761,  1791,
     426,  1766,  -530,  1778,  1797,  1784,   720,  1789,   265,  1790,
    1802,  1803,  1809,   265,  1804,  1810,  1816,  1828,  1812,  1818,
    1813,  1835,  1819,  1830,  1836,  1765,  1845,  1848,  1005,  1842,
    1843,  1844,  1847,  1849,  1850,   518,  1013,  1852,  1853,  1873,
    1891,  1896,  1908,  1858,  1907,  1892,  1702,  1910,  1689,  1918,
    1909,  1912,  1921,  1925,  1695,  -531,  1935,  1922,   780,  1927,
    1929,  1932,  1894,  1938,  1942,   788,   789,  1936,  1943,  1954,
    1955,  1957,  1940,  1946,  1965,  1958,  1969,  1574,  1974,   265,
    1646,  1979,   265,   265,   808,  2021,  1739,  1993,  2009,   464,
    2022,   418,   418,  1744,  1747,  1731,  2023,  2024,  2026,  1911,
    2027,  2028,  2032,  2044,  2048,   265,  2056,  2061,  2029,  2062,
    2043,   265,  1756,  2051,   834,  2065,  2066,  1473,  1987,  1527,
     265,  1669,  1866,   728,  1755,  1839,  1692,  1497,   426,   113,
     988,   426,   124,   125,   126,   855,  1886,  1764,   132,   464,
     464,  1613,  1745,  1006,  1760,  1641,     0,     0,   707,   265,
     707,     0,  1956,     0,     0,     0,  1247,     0,     0,     0,
     341,     0,   265,   432,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
    1646,     0,     0,   546,     0,   464,   464,   464,     0,  1978,
       0,     0,   432,  1670,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,  1817,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,     0,     0,     0,     0,     0,  1734,  1840,     0,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,   464,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1870,  1859,  1719,  1720,  1721,
    1722,  1723,  1725,     0,   464,     0,  1867,     0,     0,     0,
     464,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,  1272,     0,     0,     0,  1646,     0,     0,     0,
       0,   265,     0,     0,     0,     0,  1871,     0,     0,     0,
    1893,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     834,   265,  1041,     0,   265,     0,     0,     0,   418,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1646,     0,     0,     0,   464,     0,     0,     0,   387,     0,
       0,     0,     0,     0,   341,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1934,   265,  1320,  1321,     0,     0,
       0,     0,     0,     0,     0,   413,     0,     0,     0,   423,
       0,     0,     0,   428,     0,   464,     0,     0,     0,   265,
       0,  1964,     0,     0,     0,     0,     0,     0,   464,     0,
     440,   441,   442,   707,   444,   445,   446,     0,   448,   449,
     450,   451,   452,   453,   454,   464,   456,   457,   458,   459,
       0,     0,     0,   463,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1735,     0,     0,   265,   265,   265,   265,   265,
       0,     0,     0,     0,     0,   707,     0,     0,     0,     0,
       0,     0,     0,  1646,     0,     0,     0,     0,     0,     0,
       0,  1412,     0,     0,     0,  1414,     0,   707,     0,   515,
     517,   519,   520,   463,  1418,     0,  1419,     0,   265,  1421,
       0,  1898,  1899,  1900,  1901,  1902,     0,   553,   463,     0,
       0,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   568,     0,  1646,     0,     0,     0,     0,
     465,     0,     0,   578,   579,     0,   426,     0,     0,   579,
       0,     0,   464,     0,     0,     0,     0,     0,     0,   600,
     265,     0,     0,  1464,     0,     0,     0,   426,   426,  1933,
       0,     0,     0,  1937,     0,     0,     0,     0,     0,     0,
       0,   426,   620,     0,     0,     0,   623,   624,   625,     0,
     627,     0,     0,     0,   630,   631,   632,     0,     0,   633,
       0,     0,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1970,     0,     0,     0,  1972,   554,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   663,     0,     0,
    1984,   463,   672,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,   684,
       0,     0,     0,     0,     0,   694,     0,     0,     0,     0,
       0,     0,   708,     0,     0,   464,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2018,  2019,     0,     0,     0,
       0,     0,     0,     0,   738,     0,     0,     0,   742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   756,   517,     0,     0,     0,   760,     0,     0,
     763,   764,   765,   766,   767,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   778,   779,   781,   782,   783,
     784,   785,   786,   787,   787,     0,   792,   793,   671,   795,
       0,   464,     0,     0,     0,   801,     0,   804,     0,     0,
       0,     0,   787,     0,     0,     0,     0,   463,     0,     0,
       0,  1656,     0,     0,     0,     0,     0,   527,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   827,   828,   829,
     830,   831,   833,   835,   836,   837,   838,   839,     0,   841,
     842,     0,     0,     0,     0,     0,   849,   850,   851,   709,
       0,     0,     0,     0,   857,   858,     0,   463,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   515,   663,   877,     0,
       0,  1234,   882,   883,   884,   885,   886,   887,   888,   889,
     890,     0,     0,     0,     0,   896,     0,   898,     0,   899,
       0,     0,     0,   463,   463,   463,   904,     0,   906,   907,
     908,     0,     0,     0,   812,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,   930,     0,     0,   546,     0,  1740,
       0,     0,  1742,     0,     0,     0,     0,     0,   463,     0,
       0,     0,     0,   947,     0,   948,     0,     0,   841,   842,
       0,     0,     0,     0,   860,   861,     0,   961,     0,     0,
       0,     0,     0,   967,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   463,     0,     0,     0,     0,     0,   982,
     983,     0,     0,     0,     0,   464,     0,     0,     0,     0,
       0,     0,   463,     0,   997,   998,     0,     0,   463,  1003,
     901,   902,   903,   997,     0,     0,     0,     0,     0,     0,
    1014,     0,     0,     0,  1017,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   757,   542,
     543,   544,   545,     0,     0,     0,  1037,   546,   833,   690,
    1040,   691,     0,     0,     0,   944,     0,     0,     0,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,   463,     0,     0,     0,     0,     0,     0,  1668,
     976,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,   995,
     157,   158,     0,   546,     0,  1002,     0,     0,     0,     0,
       0,     0,     0,   463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   463,     0,     0,     0,
       0,     0,     0,  1116,     0,     0,     0,  1122,     0,     0,
       0,     0,     0,   463,     0,     0,     0,     0,   464,   464,
       0,  1135,  1136,     0,     0,     0,     0,  1139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1164,     0,     0,  1166,   464,     0,  1071,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1181,     0,  1183,  1184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   412,     0,     0,     0,  1202,     0,     0,     0,
    1102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1110,     0,     0,     0,  1224,     0,     0,
       0,     0,     0,     0,  1230,  1231,  1232,  1233,     0,     0,
    1128,     0,  1242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1267,  1268,     0,  1308,
     463,     0,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   494,   495,   496,   497,   498,
     499,     0,   501,   502,     0,     0,     0,     0,   504,   505,
       0,     0,     0,     0,     0,     0,     0,   518,   510,   511,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,     0,     0,     0,     0,     0,  1311,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1312,  1313,  1314,     0,
       0,     0,     0,  1316,  1317,     0,  1318,  2041,     0,     0,
       0,     0,     0,     0,     0,  1324,  1325,     0,     0,     0,
       0,     0,     0,  1328,  1329,     0,     0,  1271,  2057,  2059,
    1333,  1334,  1335,     0,     0,     0,     0,     0,  1341,  1342,
       0,     0,  2067,   463,     0,     0,     0,     0,  1391,     0,
     464,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   464,     0,     0,     0,     0,
       0,     0,     0,     0,  1369,     0,     0,  1310,   634,   635,
     636,     0,     0,     0,   640,   641,   642,   643,   644,   645,
     646,     0,   647,     0,     0,     0,   648,   649,     0,     0,
     652,     0,     0,     0,     0,     0,     0,  1400,     0,     0,
       0,     0,     0,   662,     0,     0,     0,     0,     0,   463,
       0,     0,     0,     0,     0,     0,     0,  1413,     0,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,  1341,  1342,
    1346,   546,     0,  1429,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1438,     0,     0,
    1443,     0,     0,   152,   349,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   464,   464,   464,   464,     0,  1465,     0,     0,
    1468,  1469,     0,     0,     0,     0,     0,     0,  1476,     0,
    1478,     0,  1476,  1482,     0,   350,   351,   352,   353,   354,
     355,   356,   357,   358,  1430,     0,  1411,     0,   359,   360,
     361,   362,     0,     0,     0,     0,   363,   364,   365,     0,
       0,   366,     0,   367,     0,     0,     0,   693,     0,     0,
     464,     0,   816,     0,   368,     0,     0,   369,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,  1553,     0,     0,     0,     0,
       0,     0,  1560,  1561,  1562,   399,     0,     0,     0,     0,
       0,  1568,     0,  1570,     0,     0,     0,     0,     0,     0,
    1573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   463,     0,     0,     0,     0,  1589,     0,
       0,     0,     0,     0,     0,     0,  1594,  1595,  1596,     0,
     802,     0,     0,     0,     0,     0,  1605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1617,     0,     0,     0,
       0,     0,   370,   371,   372,     0,     0,     0,     0,     0,
       0,     0,     0,   373,     0,     0,     0,   374,     0,   375,
     108,     0,  1634,     0,     0,     0,     0,   846,  1643,  1644,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405,   406,     0,     0,     0,     0,
       0,     0,  -526,     0,  1463,     0,     0,  1667,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1587,     0,     0,     0,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,  1679,  1680,  1681,     0,   546,     0,     0,  1446,
       0,     0,     0,  1682,     0,     0,     0,     0,  1685,  1686,
    1687,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1694,     0,     0,     0,     0,   463,   463,  1700,     0,
    1701,     0,     0,     0,     0,     0,  1709,  1710,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,     0,     0,     0,  1728,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1738,     0,     0,  1741,     0,     0,     0,  1743,     0,  1093,
       0,     0,     0,     0,     0,     0,  1686,  1687,     0,  1752,
       0,     0,     0,     0,     0,     0,     0,  1757,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1109,  1770,     0,     0,     0,     0,  1776,  1777,
       0,     0,     0,     0,     0,     0,  1567,     0,  1779,     0,
       0,  1780,  1779,  1698,  1699,     0,     0,     0,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,     0,
    1056,  1057,  1058,  1059,     0,  1061,  1062,  1063,  1064,   527,
       0,  1801,     0,     0,     0,     0,     0,     0,     0,  1074,
       0,  1076,     0,     0,     0,     0,     0,  1811,  1082,     0,
       0,     0,  1086,  1087,     0,     0,  1820,     0,     0,     0,
       0,  1098,     0,     0,     0,   517,     0,     0,     0,     0,
       0,     0,     0,     0,  1831,  1832,     0,     0,   463,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,  1620,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1856,  1857,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1869,     0,
       0,  1872,     0,     0,     0,     0,  1875,     0,     0,  1877,
       0,     0,     0,     0,     0,     0,     0,  1624,   463,  1283,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   463,     0,     0,  1187,  1189,  1190,     0,
       0,  1903,  1194,  1195,     0,     0,  1198,  1199,  1200,  1201,
       0,  1203,     0,     0,     0,  1833,  1209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1914,     0,     0,     0,
       0,     0,  1919,     0,     0,  1920,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,  1941,     0,     0,     0,  1332,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,  1887,  1959,  1960,     0,   546,
       0,     0,  1288,  1289,     0,     0,     0,     0,  1966,  1967,
    1897,  1968,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1976,     0,     0,     0,     0,   463,
     463,   463,   463,   463,     0,     0,     0,     0,     0,  1776,
       0,     0,     0,  1992,     0,     0,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
    2012,     0,     0,     0,     0,  2015,  2016,  2017,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       0,     0,     0,     0,  1343,     0,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,  2045,  2046,  2047,   546,
       0,     0,     0,     0,     0,     0,     0,  1453,  1454,     0,
       0,     0,     0,     0,     0,     0,  1980,  1981,  1982,  1983,
    1985,     0,     0,     0,   189,     6,   330,     0,     0,     0,
       0,   190,   191,   192,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2025,   222,   223,   224,   225,
    1630,     0,     0,     0,   226,  1532,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1540,   227,   228,   229,     0,
       0,     0,     0,     0,   230,    21,     0,   231,     0,     0,
       0,     0,   232,  1452,     0,   233,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,    50,     0,     0,   237,     0,   238,  1484,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,     0,     0,     0,  1516,  1517,  1518,  1519,
    1520,     0,     0,     0,     0,  1525,  1526,     0,  1528,     0,
    1530,     0,     0,     0,  1534,     0,     0,  1536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1544,
       0,     0,     0,   239,     0,     0,     0,   240,   241,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1665,     0,     0,     0,     0,   248,   249,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     331,     0,     0,     0,   252,  1729,     0,   253,     0,     0,
       0,     0,     0,     0,     0,     0,  1600,     0,  1603,     0,
       0,     0,  1610,     0,  1612,     0,     0,     0,     0,     0,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  1637,     0,
       0,     0,     0,     0,     0,     0,   189,     6,   349,     0,
       0,     0,     0,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,  1808,     0,  1485,
     351,   352,   353,   354,   355,   356,   357,   358,   222,   223,
     224,   225,   359,   360,   361,   362,   226,     0,     0,     0,
     363,   364,   365,     0,     0,   366,     0,   367,   227,   228,
     229,     0,     0,     0,     0,  1688,   230,    21,   368,   231,
       0,   369,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    50,     0,     0,   237,     0,   238,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,  1767,     0,     0,  1768,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   370,   371,   372,   240,
     241,     0,     0,     0,   242,   243,   244,   373,   245,   246,
     247,   374,     0,   375,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1793,  1794,     0,  1796,  1834,     0,
     248,   249,     0,     0,     0,     0,     0,   250,     0,     0,
       0,     0,   331,     0,     0,     0,  1486,     0,     0,   253,
       0,     0,     0,     0,     0,     0,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,  1837,  1838,   189,     6,
     349,     0,     0,     0,     0,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,     0,
    1868,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     222,   223,   224,   225,   359,   360,   361,   362,   226,     0,
       0,     0,   363,   364,   365,     0,     0,   366,     0,   367,
     227,   228,   229,     0,     0,     0,     0,     0,   230,    21,
     368,   231,     0,   369,     0,     0,   232,     0,     0,   233,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,    41,     0,     0,     0,     0,
       0,  1846,     0,     0,   236,     0,    50,     0,     0,   237,
       0,   238,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,     0,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,  1953,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   370,   371,
     372,   240,   241,     0,     0,     0,   242,   243,   244,   373,
     245,   246,   247,   374,     0,   375,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   331,   189,   152,   349,   252,   398,
       0,   253,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   385,   211,   212,   213,   214,   215,
     216,  2034,     0,     0,     0,     0,     0,     0,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   222,   223,   224,
     225,   359,   360,   361,   362,   226,     0,     0,     0,   363,
     364,   365,     0,     0,   366,     0,   367,   227,   228,   229,
       0,     0,     0,     0,     0,   230,    21,   368,   231,     0,
     369,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1999,     0,     0,     0,   400,     0,     0,
       0,     0,     0,     0,   239,   370,   371,   372,   240,     0,
       0,     0,     0,   242,   243,   244,   373,   245,   246,   247,
     374,     0,   375,   108,   401,   402,   403,   404,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     386,     0,     0,     0,     0,     0,   250,   405,   406,     0,
       0,   407,     0,   408,   189,     6,  1576,   409,   253,     0,
       0,   190,   191,   192,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,     0,
       0,     0,     0,     0,   230,    21,     0,   231,     0,     0,
       0,     0,   232,     0,     0,   233,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,    50,     0,     0,   237,     0,   238,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,     0,     0,   240,   241,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     331,   189,     6,     0,   252,     0,     0,   253,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,     0,     0,     7,     8,
       0,   230,    21,     0,   231,     0,     0,     0,     0,   232,
       0,     0,   233,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    50,
       0,     0,   237,     0,   238,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,     0,     0,    66,    67,
      68,    69,    70,     0,     0,     0,    74,     0,     0,    77,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    38,    39,    40,    41,     0,     0,    43,     0,
       0,     0,     0,     0,   703,    49,     0,     0,    51,   704,
     239,    54,   705,     0,   240,   241,     0,     0,     0,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   108,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   585,  1724,     0,     0,     0,
       0,     0,   250,     0,    85,    86,    87,   587,   189,     6,
       0,   293,   521,     0,   253,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   878,
     227,   228,   229,     0,     0,     7,     8,     0,   230,    21,
       0,   231,     0,     0,     0,     0,   232,     0,     0,   233,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,    50,     0,     0,   237,
       0,   238,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,     0,    38,
      39,    40,    41,     0,     0,    43,     0,     0,     0,     0,
       0,   703,    49,     0,     0,    51,   704,   239,    54,   705,
       0,   240,   241,     0,     0,     0,   242,   243,   244,     0,
     245,   246,   247,     0,     0,     0,   108,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,     0,     0,     0,     0,     0,   250,
       0,    85,    86,    87,   251,   189,     6,     0,   252,     0,
       0,   253,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   900,   227,   228,   229,
       0,     0,     7,     8,     0,   230,    21,     0,   231,     0,
       0,     0,     0,   232,     0,     0,   233,     0,     0,   234,
       0,   235,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,    50,     0,     0,   237,     0,   238,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
       0,     0,    66,    67,    68,    69,    70,     0,     0,     0,
      74,     0,     0,    77,     0,     0,     0,     0,     0,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    38,    39,    40,    41,
       0,     0,    43,     0,     0,     0,     0,     0,   703,    49,
       0,     0,    51,   704,   239,    54,   705,     0,   240,   241,
       0,     0,     0,   242,   243,   244,     0,   245,   246,   247,
       0,     0,     0,   108,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,     0,     0,     0,   250,     0,    85,    86,
      87,   331,   189,     6,     0,   252,     0,     0,   253,   190,
     191,   192,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   945,   227,   228,   229,     0,     0,     7,
       8,     0,   230,    21,     0,   231,     0,     0,     0,     0,
     232,     0,     0,   233,     0,     0,   234,     0,   235,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
      50,     0,     0,   237,     0,   238,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,     0,     0,    66,
      67,    68,    69,    70,     0,     0,     0,    74,     0,     0,
      77,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,    41,     0,     0,    43,
       0,     0,     0,     0,     0,   703,    49,     0,     0,    51,
     704,   239,    54,   705,     0,   240,   241,     0,     0,     0,
     242,   243,   244,     0,   245,   246,   247,     0,     0,     0,
     108,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   462,     0,     0,
       0,     0,     0,   250,     0,    85,    86,    87,   331,   189,
       6,     0,   516,     0,     0,   253,   190,   191,   192,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     946,   227,   228,   229,     0,     0,     7,     8,     0,   230,
      21,     0,   231,     0,     0,     0,     0,   232,     0,     0,
     233,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,    50,     0,     0,
     237,     0,   238,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,    41,     0,     0,    43,     0,     0,     0,
       0,     0,   703,    49,     0,     0,    51,   704,   239,    54,
     705,     0,   240,   241,     0,     0,     0,   242,   243,   244,
       0,   245,   246,   247,     0,     0,     0,   108,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   462,     0,     0,     0,     0,     0,
     250,     0,    85,    86,    87,   331,   189,     6,     0,     0,
     521,     0,   253,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1130,   227,   228,
     229,     0,     0,     7,     8,     0,   230,    21,     0,   231,
       0,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    50,     0,     0,   237,     0,   238,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
      41,     0,     0,    43,     0,     0,     0,     0,     0,   703,
      49,     0,     0,    51,   704,   239,    54,   705,     0,   240,
     241,     0,     0,     0,   242,   243,   244,     0,   245,   246,
     247,     0,     0,     0,   108,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,     0,     0,     0,     0,     0,   250,     0,    85,
      86,    87,   557,   189,     6,     0,   252,     0,     0,   253,
     190,   191,   192,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1132,   227,   228,   229,     0,     0,
       7,     8,     0,   230,    21,     0,   231,     0,     0,     0,
       0,   232,     0,     0,   233,     0,     0,   234,     0,   235,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,    50,     0,     0,   237,     0,   238,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,     0,     0,
      66,    67,    68,    69,    70,     0,     0,     0,    74,     0,
       0,    77,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,    41,     0,     0,
      43,     0,     0,     0,     0,     0,   703,    49,     0,     0,
      51,   704,   239,    54,   705,     0,   240,   241,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   108,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,     0,
       0,     0,     0,     0,   250,     0,    85,    86,    87,   564,
     189,     6,     0,   252,     0,     0,   253,   190,   191,   192,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1133,   227,   228,   229,     0,     0,     7,     8,     0,
     230,    21,     0,   231,     0,     0,     0,     0,   232,     0,
       0,   233,     0,     0,   234,     0,   235,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,    50,     0,
       0,   237,     0,   238,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    74,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,    41,     0,     0,    43,     0,     0,
       0,     0,     0,   703,    49,     0,     0,    51,   704,   239,
      54,   705,     0,   240,   241,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   108,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   462,     0,     0,     0,     0,
       0,   250,     0,    85,    86,    87,   331,   189,     6,     0,
     832,     0,     0,   253,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1152,   227,
     228,   229,     0,     0,     7,     8,     0,   230,    21,     0,
     231,     0,     0,     0,     0,   232,     0,     0,   233,     0,
       0,   234,     0,   235,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,   236,     0,    50,     0,     0,   237,     0,
     238,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,     0,     0,    66,    67,    68,    69,    70,     0,
       0,     0,    74,     0,     0,    77,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    38,    39,
      40,    41,     0,     0,    43,     0,     0,     0,     0,     0,
     703,    49,     0,     0,    51,   704,   239,    54,   705,     0,
     240,   241,     0,     0,     0,   242,   243,   244,     0,   245,
     246,   247,     0,     0,     0,   108,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,     0,     0,     0,     0,     0,   250,     0,
      85,    86,    87,   331,   189,     6,     0,  1584,     0,     0,
     253,   190,   191,   192,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1182,   227,   228,   229,     0,
       0,     7,     8,     0,   230,    21,     0,   231,     0,     0,
       0,     0,   232,     0,     0,   233,     0,     0,   234,     0,
     235,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,    50,     0,     0,   237,     0,   238,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    74,
       0,     0,    77,     0,     0,     0,     0,     0,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    38,    39,    40,    41,     0,
       0,    43,  1788,   527,     0,     0,     0,   703,    49,     0,
       0,    51,   704,   239,    54,   705,     0,   240,   241,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   108,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   585,  1724,
       0,     0,     0,     0,     0,   250,     0,    85,    86,    87,
     587,   189,     6,     0,   293,     0,     0,   253,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1215,   227,   228,   229,     0,     0,     0,     0,
       0,   230,    21,     0,   231,     0,     0,     0,     0,   232,
       0,     0,   233,     0,     0,   234,     0,   235,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,    50,
       0,     0,   237,     0,   238,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,     0,     0,    66,    67,
      68,    69,    70,     0,     0,     0,    74,     0,     0,    77,
       0,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   757,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,     0,     0,     0,   240,   241,     0,     0,     0,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   462,     0,     0,     0,
       0,     0,   250,   189,   152,   349,     0,   331,     0,     0,
     190,   191,   192,     0,   253,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   385,   211,   212,   213,   214,   215,   216,  1924,
       0,     0,     0,     0,     0,     0,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   222,   223,   224,   225,   359,
     360,   361,   362,   226,     0,     0,     0,   363,   364,   365,
       0,     0,   366,     0,   367,   227,   228,   229,     0,     0,
       0,     0,     0,   230,    21,   368,   231,     0,   369,   189,
     152,   349,     0,     0,     0,     0,   190,   191,   192,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   385,   211,
     212,   213,   214,   215,   216,     0,     0,     0,     0,     0,
       0,     0,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   222,   223,   224,   225,   359,   360,   361,   362,   226,
       0,     0,     0,   363,   364,   365,     0,     0,   366,     0,
     367,   227,   228,   229,     0,     0,     0,     0,     0,   230,
      21,   368,   231,     0,   369,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   370,   371,   372,   240,     0,     0,     0,
       0,   242,   243,   244,   373,   245,   246,   247,   374,     0,
     375,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   386,     0,
       0,     0,     0,     0,   250,     0,     0,     0,     0,   331,
       0,     0,     0,  1481,     0,     0,   253,     0,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,   239,   370,
     371,   372,   240,     0,     0,     0,     0,   242,   243,   244,
     373,   245,   246,   247,   374,     0,   375,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   386,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,   331,   189,   152,   349,  1737,
       0,     0,   253,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   385,   211,   212,   213,   214,
     215,   216,   527,     0,     0,     0,     0,     0,     0,  1485,
     351,   352,   353,   354,   355,   356,   357,   358,   222,   223,
     224,   225,   359,   360,   361,   362,   226,     0,     0,     0,
     363,   364,   365,     0,     0,   366,     0,   367,   227,   228,
     229,     0,     0,     0,     0,     0,   230,    21,   368,   231,
       0,   369,   189,   152,   349,     0,     0,     0,     0,   190,
     191,   192,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   385,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   222,   223,   224,   225,   359,   360,
     361,   362,   226,     0,     0,     0,   363,   364,   365,     0,
       0,   366,     0,   367,   227,   228,   229,     0,     0,     0,
       0,     0,   230,    21,   368,   231,     0,   369,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   370,   371,   372,   240,
       0,     0,     0,     0,   242,   243,   244,   373,   245,   246,
     247,   374,     0,   375,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   386,     0,     0,     0,     0,     0,   250,     0,     0,
       0,     0,   331,     0,     0,     0,  1636,     0,     0,   253,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   757,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,   917,     0,     0,
       0,   239,   370,   371,   372,   240,     0,     0,     0,     0,
     242,   243,   244,   373,   245,   246,   247,   374,     0,   375,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   386,     0,     0,
       0,     0,     0,   250,   189,   152,     0,     0,   331,     0,
       0,   190,   191,   192,     0,   253,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   385,   211,   212,   213,   214,   215,   216,
       0,  1100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,     0,
       0,   189,   152,     0,   230,    21,     0,   231,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     385,   211,   212,   213,   214,   215,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,     0,     0,     0,     0,
       0,   230,    21,     0,   231,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,   239,     0,     0,     0,   240,     0,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   386,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     331,     0,     0,     0,   567,     0,     0,   253,     0,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
     239,   546,     0,     0,   240,     0,     0,     0,  1101,   242,
     243,   244,     0,   245,   246,   247,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   585,   586,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,   587,   189,   152,
       0,   293,     0,     0,   253,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   385,   211,   212,
     213,   214,   215,   216,  1406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,     0,     0,     0,     0,     0,   230,    21,
       0,   231,   189,   152,     0,  1223,     0,     0,     0,   190,
     191,   192,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   385,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,     0,     0,     0,
       0,     0,   230,    21,     0,   231,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,   239,   546,     0,
       0,   240,     0,     0,     0,     0,   242,   243,   244,     0,
     245,   246,   247,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   386,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   331,  1008,     0,     0,     0,     0,
       0,   253,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,   240,     0,     0,     0,     0,
     242,   243,   244,     0,   245,   246,   247,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   386,     0,     0,
       0,     0,     0,   250,   189,   152,     0,  1368,   331,     0,
       0,   190,   191,   192,     0,   253,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   385,   211,   212,   213,   214,   215,   216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,     0,
       0,     0,     0,     0,   230,    21,  1350,   231,   189,   152,
       0,  1428,     0,     0,     0,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   385,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,     0,     0,     0,     0,     0,   230,    21,
       0,   231,     0,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,   239,     0,   546,     0,   240,     0,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   386,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,     0,   253,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,   690,     0,   691,     0,     0,   239,     0,     0,
    1602,   240,     0,     0,     0,     0,   242,   243,   244,     0,
     245,   246,   247,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   386,     0,     0,     0,     0,     0,   250,
     189,   152,     0,     0,   331,     0,     0,   190,   191,   192,
       0,   253,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   385,
     211,   212,   213,   214,   215,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,     0,     0,   189,   152,     0,
     230,    21,     0,   231,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   385,   211,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,   229,     0,     0,     0,     0,     0,   230,    21,     0,
     231,     0,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   909,     0,     0,   239,
       0,     0,     0,   240,   870,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   386,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,   331,  1480,     0,     0,
       0,     0,     0,   253,     0,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,   239,     0,   546,     0,
     240,     0,     0,     0,  1705,   242,   243,   244,  1706,   245,
     246,   247,     0,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   386,     0,     0,     0,     0,     0,   250,   189,
     152,     0,     0,   331,  1781,     0,   190,   191,   192,     0,
     253,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   385,   211,
     212,   213,   214,   215,   216,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,     0,     0,     7,     8,     0,   230,
      21,     0,   231,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,   754,     0,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,    41,     0,     0,    43,     0,     0,
       0,     0,     0,   703,    49,     0,     0,    51,   704,     0,
      54,   705,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     7,     8,    71,
      38,    39,    40,    41,     0,     0,    43,     0,     0,     0,
       0,     0,   703,    49,     0,     0,    51,   704,   239,    54,
     705,     0,   240,    85,    86,    87,     0,   242,   243,   244,
       0,   245,   246,   247,     0,     0,     0,   108,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   386,     0,     0,     0,     0,     0,
     250,     0,    85,    86,    87,   331,     0,     0,     0,     0,
       0,     0,   253,     0,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    38,    39,    40,    41,     0,     0,    43,  1360,     0,
       0,     0,     0,   703,    49,     0,     0,    51,   704,     0,
      54,   705,     0,     0,    -4,     1,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,    71,
       0,     0,     0,     0,     0,     0,     0,  1944,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,     0,    -4,    -4,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,    -4,    -4,
      -4,     0,   546,     0,    -4,    -4,     0,    -4,   990,     0,
       0,     0,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,  2001,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,
      10,     0,    -4,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,     0,    -4,     0,     0,     0,    11,
      12,    13,     0,     0,     0,    14,    15,     0,    16,     0,
       0,     0,     0,    17,    18,     0,    19,    20,     0,    21,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,    37,    38,    39,    40,    41,    42,     0,    43,     0,
      44,    45,    46,    47,    48,    49,    50,     0,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    80,    81,    82,     0,     0,     0,    83,     0,
       0,     0,     0,    84,    85,    86,    87,   152,   349,    88,
       0,    89,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   152,   349,     0,
       0,     0,     0,     0,   107,     0,   108,     0,     0,   350,
     351,   352,   353,   354,   355,   356,   357,   358,     0,     0,
       0,     0,   359,   360,   361,   362,     0,   379,   349,     0,
     363,   364,   365,     0,     0,   366,     0,   367,     0,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   368,     0,
       0,   369,   359,   360,   361,   362,     0,     0,   349,     0,
     363,   364,   365,     0,     0,   366,     0,   367,     0,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   368,     0,
       0,   369,   359,   360,   361,   362,     0,     0,     0,   399,
     363,   364,   365,     0,     0,   366,     0,   367,     0,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   368,     0,
       0,   369,   359,   360,   361,   362,     0,     0,     0,     0,
     363,   364,   365,     0,     0,   366,     0,   367,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   368,     0,
       0,   369,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,   371,   372,     0,
       0,     0,     0,     0,     0,     0,     0,   373,     0,     0,
       0,   374,     0,   375,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,   371,   372,     7,
       8,     0,     0,     0,     0,     0,     0,   373,     0,     0,
       0,   374,     0,   375,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,   371,   372,     0,
       0,     0,     0,     0,     0,     0,     0,   373,     0,     0,
       0,   374,     0,   375,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,   371,   372,     0,
       0,     0,     0,     0,     7,     8,     0,   373,     0,     0,
       0,   374,     0,   375,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,    38,    39,    40,    41,     0,     0,    43,
       0,     0,     0,     0,     0,   703,    49,     0,     0,    51,
     704,     0,    54,   705,     0,     0,     0,     0,   955,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,     0,     0,     0,   956,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    85,    86,    87,    38,    39,
      40,    41,     0,     0,    43,     0,     0,     0,     0,     0,
     703,    49,     0,     0,    51,   704,     0,    54,   705,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
      85,    86,    87,     0,     0,  1732,     0,     0,     0,  1733,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  1889,     0,
       0,     0,  1890,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   870,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   871,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   914,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1055,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1065,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1066,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1067,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1072,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1073,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1075,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1176,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1197,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1279,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1362,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1363,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1405,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1521,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1522,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1523,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1537,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1660,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1771,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1772,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1795,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1798,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1864,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1915,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1916,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1928,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1930,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1962,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1989,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1994,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1995,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1996,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2035,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1042,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1083,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1124,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  1155,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  1173,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,  1229,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  1364,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  1434,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,  1435,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,  1436,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1437,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1703,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1714,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  1751,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  1814,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,  1829,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  1841,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  1878,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,  1895,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,  1904,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1905,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1926,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1975,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  2014,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  2033,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,  2053,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  2054,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  2055,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,   665,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,   862,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,  1807,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,   690,     0,   691,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,   920,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
     969,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,  1105,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,  1168,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,  1169,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,  1174,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,  1175,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,  1265,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,  1276,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,  1466,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,  1543,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
    1590,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,  1763,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,  1800,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,  1815,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   735,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   736,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   737,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   739,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   740,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   741,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   743,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   744,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   745,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   746,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   747,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   748,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   749,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   751,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   752,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   753,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   813,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   847,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   891,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   909,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   910,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   911,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   912,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   918,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   919,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,   954,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,   968,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1022,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1026,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1038,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1104,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1113,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1114,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1115,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1125,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1154,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1156,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1157,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1158,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1159,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1160,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1161,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1162,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1167,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1264,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1275,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1467,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1529,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1542,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1651,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1653,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1654,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1659,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1704,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1713,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1736,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1799,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1862,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  1863,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,  1988,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,  2030,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546
};

static const yytype_int16 yycheck[] =
{
       3,     3,     3,   134,  1149,  1153,   147,   685,   286,  1327,
       6,   298,  1578,     4,  1619,   693,  1621,   187,    21,   669,
      48,    21,     4,     7,     4,     6,     4,     4,     4,   316,
     582,   583,     4,  1782,     5,  1606,     4,     6,    97,     4,
       6,     4,     6,     0,     4,    48,     9,     5,     4,    97,
     700,     6,   240,    54,   235,   236,    99,   245,   101,     5,
     119,     4,     4,     6,   245,   715,    14,     4,     9,     9,
       4,   119,    75,   723,   149,     4,   227,   228,   240,     7,
      83,    91,     4,     6,    94,    88,   248,    97,     7,     9,
      97,   134,   243,     6,  1665,   382,    99,   384,     9,   174,
     110,   271,   272,   273,    84,   392,   227,   228,   227,   228,
       9,     6,  1678,   240,   157,   190,   191,     9,   227,   228,
       6,   248,   227,   228,   227,   228,   240,   248,     6,   248,
     240,   134,   242,   135,   248,   244,   139,   140,   248,   309,
     310,   311,     6,   248,   147,   248,   227,   228,    91,    91,
     243,   179,     7,    95,   247,   158,   326,   227,   228,   101,
     102,    94,   104,   105,    97,   815,     7,   248,   239,   227,
     228,   174,   227,   228,  1923,   240,   179,   110,   248,   182,
      97,   123,    99,   248,   187,   188,   164,   165,   166,   167,
     248,   242,     7,   248,   227,   228,     7,   248,   162,   133,
     134,   135,   136,     7,   239,   185,   177,   162,   236,   174,
     175,   227,   228,   189,   148,   248,  1534,   151,   174,   175,
     211,   239,   239,   227,   228,   243,   243,   243,   240,    61,
      62,   211,    64,   236,   211,  1380,   248,   238,  1804,   211,
     235,   236,   270,   211,   248,   242,   249,   243,   211,   252,
     253,   248,   280,   253,     6,   246,   284,   223,   239,   241,
     226,   245,   243,   243,   267,   247,   244,   270,   271,   272,
     273,   243,   235,   236,   243,   243,   239,   280,   241,   239,
     243,   284,   245,   286,   571,   243,   573,   574,     6,   211,
     968,   969,  1858,   212,   213,   214,   215,   243,   239,   239,
     241,   241,   239,   590,   245,   245,   309,   310,   311,     8,
     239,   239,     6,   241,   227,   228,   235,   236,   240,   239,
     242,   241,     6,   326,   235,   236,   245,   239,   239,   241,
     241,   242,   227,   228,   245,   244,   235,   236,   508,   248,
     239,   628,   241,   235,   236,   223,   245,   239,   226,   241,
     239,  1956,   239,   245,   241,   398,     6,   212,   213,   214,
     215,   248,   503,   227,   228,   241,   394,   395,   227,   228,
     241,   212,   213,   214,   215,   227,   228,   239,   665,   244,
     235,   236,   410,   248,   227,   228,   389,   390,   239,   248,
      94,   394,   395,    97,   235,   236,   248,   212,   213,   214,
     215,   212,   213,   214,   215,   248,   240,   410,   212,   213,
     214,   215,   239,   416,   248,   227,   228,   239,   129,   420,
     235,   236,   227,   228,   240,  1991,   227,   228,   227,   228,
     227,   228,   248,   239,   437,   146,   248,   129,   243,  1089,
     240,  1091,   242,   154,   155,   156,   239,   248,   248,   160,
     161,   248,   239,  1103,   146,   227,   228,   289,   290,   462,
     227,   228,   154,   155,   156,   297,   298,   244,   160,   161,
     513,   248,   500,   239,   232,   233,   248,  2043,  1796,   507,
     238,   248,   485,   229,   230,   231,   232,   233,    94,   492,
     493,    97,   238,    99,   497,   636,   499,   500,   501,   502,
     503,   239,   505,   241,   507,   508,   509,   510,   511,   512,
     239,   514,   512,   516,   514,   227,   228,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   240,   248,   242,   541,   238,
     227,   228,   129,   248,   547,   244,   239,   133,   134,   227,
     228,   239,   244,   139,   685,   227,   228,   239,   129,   146,
    1210,   248,   245,   566,   567,   248,  1216,   154,   155,   156,
     248,   129,   239,   160,   161,   146,   248,   239,   244,   866,
     582,   583,   248,   154,   155,   156,   239,   588,   146,   160,
     161,   240,   240,   242,   242,   112,   154,   155,   156,   248,
     248,   243,   160,   161,   227,   228,   649,    97,   609,   612,
     613,   614,    94,  1263,   244,    97,   239,    99,   248,    91,
     243,   245,    94,   247,  1274,    97,     6,    99,   110,   243,
    1280,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     239,   644,   645,   646,   647,   648,   239,   650,   651,   652,
     653,   654,   243,   653,   657,   133,   134,   244,   659,    91,
     661,   139,    94,   666,    97,    97,   244,    99,   227,   228,
     248,   239,   673,   244,   240,  1353,   242,   239,   110,   241,
     239,   243,   235,   236,   243,    94,   244,     4,     5,   692,
     243,   734,     6,     7,   697,   227,   228,   229,   230,   231,
     232,   233,   235,   236,     6,     7,   238,   244,   711,   712,
     243,   248,   843,   239,   717,   241,   244,   720,   721,   245,
     248,   243,   248,   726,   239,   728,   241,   243,   243,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   240,   239,
     242,   243,    59,    60,    61,    62,    97,    94,   580,   581,
      67,    68,    69,   585,   757,    72,   759,    74,    94,   244,
     244,   244,  1440,   248,   248,   248,    97,     4,    85,   244,
     239,    88,   241,   248,  1452,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   791,   244,
     244,   244,   238,   248,   248,   248,   244,  1945,     4,   244,
     248,   244,   244,   248,   244,   248,   248,   244,   248,   126,
     244,   248,     4,   856,   248,   244,   244,   244,   244,   248,
     248,   248,   248,   244,   244,   853,   244,   248,   248,   832,
     248,   244,  1977,     4,     6,   248,   244,   968,   969,   244,
     248,   244,   845,   248,   244,   248,   239,   244,   248,   244,
     853,   248,   244,   248,  2002,   239,   248,   244,   244,   862,
       6,   248,   248,   241,   865,   244,   867,   868,   244,   248,
     244,   239,   248,   241,   248,  2020,   193,   194,   195,   244,
     881,   244,   244,   248,   244,   248,   248,   204,   248,   239,
     239,   208,   241,   210,   211,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   239,   134,   241,   915,   238,   241,   139,   140,   240,
     239,   242,   243,   240,   239,   242,   243,   970,     4,   239,
       6,   243,   960,     6,   247,   243,     6,     9,   247,   239,
     239,   239,   239,   119,   239,   239,     4,   243,   949,   239,
     243,   979,   174,   239,   239,   239,   243,   960,   239,   239,
     243,   243,   239,   239,   243,   243,   188,  1245,   243,   239,
     239,   974,   239,  1104,  1105,   239,   979,   239,   239,     6,
       6,   241,     6,     6,   243,   243,   989,   243,   243,   241,
     241,   994,  1020,  1021,   241,  1023,  1024,  1025,     6,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,   243,
     177,  1563,  1564,   239,   239,   239,   239,  1020,  1021,   239,
    1023,  1024,  1025,   239,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,   241,     6,  1039,   869,     6,   243,
       6,     6,   243,     7,   876,     6,   243,     6,   880,  1077,
     243,    87,   248,   244,   248,   240,     7,     4,     5,   240,
       6,   243,   245,   238,    64,     4,     7,     7,  1096,   239,
       6,   240,     6,     6,  1077,  1078,  1079,   243,     7,     7,
       6,     6,   174,  1111,   243,   242,   240,     6,   243,   245,
     243,   243,   243,  1096,     7,     6,   241,   239,     4,    46,
      47,    48,    49,    50,    51,    52,    53,    54,  1111,  1112,
     243,     6,    59,    60,    61,    62,     6,     6,     6,   240,
      67,    68,    69,   241,     7,    72,     7,    74,     7,     7,
    1131,     7,     7,  1264,  1265,  1163,     7,     7,    85,     7,
    1427,    88,     7,     7,  1431,     7,     7,     7,     7,  1177,
    1178,  1179,     7,   243,     6,   240,   242,   248,   240,   248,
    1163,   248,     7,   243,   248,     7,   245,   389,   243,  1447,
       4,     6,     9,   244,  1177,  1178,  1179,   245,   244,   126,
     129,     6,     8,     7,     7,  1188,     7,  1019,     7,   245,
    1193,   240,   240,   248,  1197,   248,   248,   240,  1226,   245,
     242,   177,   247,  1206,     7,  1208,   149,   244,  1211,   243,
       6,     6,     4,    46,    46,   245,   245,   239,   239,  1220,
     239,     4,   239,  1226,     6,   182,     7,   245,     7,     7,
     240,     7,   248,     7,     7,   240,   248,     7,     7,  1282,
       7,  1284,  1245,     4,     4,   243,   193,   194,   195,     6,
     239,   109,     7,     6,    97,     7,  1284,   204,  1810,     7,
       7,   208,  1265,   210,   211,  1293,     7,     7,     7,  1297,
       7,   243,     6,     6,     6,   497,     7,   499,     6,   501,
     502,  1284,     6,     4,     4,     4,   246,   509,   510,   243,
    1293,   243,   249,   248,  1297,   252,   243,     6,   240,   243,
     248,     6,     6,   248,     7,     6,   244,     6,   239,  1440,
     267,   241,  1453,  1454,     6,   239,   243,     6,     6,  1347,
    1348,  1349,   245,     6,   242,     6,   123,  1355,     6,     6,
       6,   177,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     5,  1370,   240,  1347,  1348,  1349,   240,     6,     4,
       6,     4,  1355,  1381,     6,  1633,   243,   243,     7,   243,
       6,  1389,     6,   243,     6,     6,   243,  1370,   241,   243,
       6,   243,   173,     6,   243,     6,   243,   243,  1381,     7,
    1423,     4,     6,   240,     6,   248,  1389,   243,   239,  1392,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   248,   248,
    1541,     6,   238,   635,   240,   637,   638,   639,   640,   641,
     642,   243,   644,   645,   646,   647,   243,   245,   650,   651,
     652,  1459,   248,   390,   243,   239,     4,   239,  1481,     5,
       7,     6,     6,     6,  1447,     6,     6,    95,   248,   243,
    1453,  1454,   240,  1481,   243,     6,  1459,     6,   248,     6,
       6,     6,     6,   248,   248,   240,     6,     4,     6,     5,
    1473,     6,   243,     6,   240,   243,   248,     7,  1481,   243,
       6,     6,     6,  1486,   243,   243,     6,     6,   244,     7,
     244,     6,   243,   172,   240,  1636,     6,     6,   720,   244,
     244,   244,     7,   245,     6,   462,   728,     6,     6,     6,
       6,     6,     6,   243,   240,   244,  1559,     6,  1649,     6,
     243,   175,   244,   239,  1552,   243,     6,   244,   485,   243,
     240,   243,  1819,     6,     6,   492,   493,   243,   129,     6,
       6,     6,   244,   243,   240,   243,     6,  1379,     6,  1552,
    1578,     6,  1555,  1556,   511,     6,  1599,   244,   244,   516,
       6,  1563,  1564,  1606,  1607,  1593,     6,     6,     6,  1847,
       6,     6,     6,     6,     6,  1578,     6,     6,   243,     6,
     243,  1584,  1625,   243,   541,     6,     6,  1273,  1958,  1322,
    1593,  1491,  1783,   434,  1622,  1748,  1548,  1292,  1601,     3,
     705,  1604,     3,     3,     3,   561,  1806,  1635,     3,   566,
     567,  1420,  1606,   720,  1629,  1454,    -1,    -1,  1619,  1622,
    1621,    -1,  1909,    -1,    -1,    -1,  1629,    -1,    -1,    -1,
    1633,    -1,  1635,  1636,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
    1678,    -1,    -1,   238,    -1,   612,   613,   614,    -1,  1946,
      -1,    -1,  1665,  1495,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1678,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1712,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     657,    -1,    -1,    -1,    -1,    -1,     8,  1750,    -1,  1712,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1737,   692,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1788,  1774,  1579,  1580,  1581,
    1582,  1583,  1584,    -1,   711,    -1,  1784,    -1,    -1,    -1,
     717,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1774,   994,    -1,    -1,    -1,  1804,    -1,    -1,    -1,
      -1,  1784,    -1,    -1,    -1,    -1,  1789,    -1,    -1,    -1,
    1818,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     757,  1804,   759,    -1,  1807,    -1,    -1,    -1,  1810,    -1,
      -1,    -1,    -1,    -1,    -1,  1818,    -1,    -1,    -1,  1822,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1858,    -1,    -1,    -1,   791,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,  1847,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1882,  1858,  1078,  1079,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,   138,
      -1,    -1,    -1,   142,    -1,   832,    -1,    -1,    -1,  1882,
      -1,  1924,    -1,    -1,    -1,    -1,    -1,    -1,   845,    -1,
     159,   160,   161,  1894,   163,   164,   165,    -1,   167,   168,
     169,   170,   171,   172,   173,   862,   175,   176,   177,   178,
      -1,    -1,    -1,   182,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,  1948,  1949,  1950,  1951,  1952,
      -1,    -1,    -1,    -1,    -1,  1956,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1991,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1193,    -1,    -1,    -1,  1197,    -1,  1978,    -1,   248,
     249,   250,   251,   252,  1206,    -1,  1208,    -1,  1991,  1211,
      -1,  1823,  1824,  1825,  1826,  1827,    -1,   266,   267,    -1,
      -1,    -1,    -1,    -1,  2007,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,    -1,  2043,    -1,    -1,    -1,    -1,
     182,    -1,    -1,   292,   293,    -1,  2029,    -1,    -1,   298,
      -1,    -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,   308,
    2043,    -1,    -1,  1265,    -1,    -1,    -1,  2050,  2051,  1881,
      -1,    -1,    -1,  1885,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2064,   331,    -1,    -1,    -1,   335,   336,   337,    -1,
     339,    -1,    -1,    -1,   343,   344,   345,    -1,    -1,   348,
      -1,    -1,  1039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1932,    -1,    -1,    -1,  1936,   267,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
    1952,   390,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,   408,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,  1112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1997,  1998,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,   447,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   461,   462,    -1,    -1,    -1,   466,    -1,    -1,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,    -1,   495,   496,   390,   498,
      -1,  1188,    -1,    -1,    -1,   504,    -1,   506,    -1,    -1,
      -1,    -1,   511,    -1,    -1,    -1,    -1,   516,    -1,    -1,
      -1,  1473,    -1,    -1,    -1,    -1,    -1,     8,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,    -1,   548,
     549,    -1,    -1,    -1,    -1,    -1,   555,   556,   557,     6,
      -1,    -1,    -1,    -1,   563,   564,    -1,   566,   567,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   585,   586,   587,    -1,
      -1,     6,   591,   592,   593,   594,   595,   596,   597,   598,
     599,    -1,    -1,    -1,    -1,   604,    -1,   606,    -1,   608,
      -1,    -1,    -1,   612,   613,   614,   615,    -1,   617,   618,
     619,    -1,    -1,    -1,   516,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   643,    -1,    -1,   238,    -1,  1601,
      -1,    -1,  1604,    -1,    -1,    -1,    -1,    -1,   657,    -1,
      -1,    -1,    -1,   662,    -1,   664,    -1,    -1,   667,   668,
      -1,    -1,    -1,    -1,   566,   567,    -1,   676,    -1,    -1,
      -1,    -1,    -1,   682,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   692,    -1,    -1,    -1,    -1,    -1,   698,
     699,    -1,    -1,    -1,    -1,  1392,    -1,    -1,    -1,    -1,
      -1,    -1,   711,    -1,   713,   714,    -1,    -1,   717,   718,
     612,   613,   614,   722,    -1,    -1,    -1,    -1,    -1,    -1,
     729,    -1,    -1,    -1,   733,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,   755,   238,   757,   240,
     759,   242,    -1,    -1,    -1,   657,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,   791,    -1,    -1,    -1,    -1,    -1,    -1,  1486,
     692,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   711,
      22,    23,    -1,   238,    -1,   717,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   832,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   845,    -1,    -1,    -1,
      -1,    -1,    -1,   852,    -1,    -1,    -1,   856,    -1,    -1,
      -1,    -1,    -1,   862,    -1,    -1,    -1,    -1,  1555,  1556,
      -1,   870,   871,    -1,    -1,    -1,    -1,   876,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   892,    -1,    -1,   895,  1584,    -1,   791,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   914,    -1,   916,   917,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,   935,    -1,    -1,    -1,
     832,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   845,    -1,    -1,    -1,   956,    -1,    -1,
      -1,    -1,    -1,    -1,   963,   964,   965,   966,    -1,    -1,
     862,    -1,   971,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   985,   986,    -1,     6,
     989,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    -1,   224,   225,    -1,    -1,    -1,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1724,   240,   241,
    1039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1737,    -1,    -1,    -1,    -1,    -1,  1055,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1065,  1066,  1067,    -1,
      -1,    -1,    -1,  1072,  1073,    -1,  1075,  2029,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1084,  1085,    -1,    -1,    -1,
      -1,    -1,    -1,  1092,  1093,    -1,    -1,   989,  2050,  2051,
    1099,  1100,  1101,    -1,    -1,    -1,    -1,    -1,  1107,  1108,
      -1,    -1,  2064,  1112,    -1,    -1,    -1,    -1,     6,    -1,
    1807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1822,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1143,    -1,    -1,  1039,   350,   351,
     352,    -1,    -1,    -1,   356,   357,   358,   359,   360,   361,
     362,    -1,   364,    -1,    -1,    -1,   368,   369,    -1,    -1,
     372,    -1,    -1,    -1,    -1,    -1,    -1,  1176,    -1,    -1,
      -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,  1188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1196,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,  1217,  1218,
    1112,   238,    -1,  1222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1236,    -1,    -1,
    1239,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1948,  1949,  1950,  1951,  1952,    -1,  1266,    -1,    -1,
    1269,  1270,    -1,    -1,    -1,    -1,    -1,    -1,  1277,    -1,
    1279,    -1,  1281,  1282,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,     6,    -1,  1188,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,   412,    -1,    -1,
    2007,    -1,   524,    -1,    85,    -1,    -1,    88,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,  1354,    -1,    -1,    -1,    -1,
      -1,    -1,  1361,  1362,  1363,   126,    -1,    -1,    -1,    -1,
      -1,  1370,    -1,  1372,    -1,    -1,    -1,    -1,    -1,    -1,
    1379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1392,    -1,    -1,    -1,    -1,  1397,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1405,  1406,  1407,    -1,
     505,    -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1425,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,   208,    -1,   210,
     211,    -1,  1451,    -1,    -1,    -1,    -1,   552,  1457,  1458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,   236,    -1,    -1,    -1,    -1,
      -1,    -1,   243,    -1,   245,    -1,    -1,  1486,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1392,    -1,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,  1521,  1522,  1523,    -1,   238,    -1,    -1,     6,
      -1,    -1,    -1,  1532,    -1,    -1,    -1,    -1,  1537,  1538,
    1539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1550,    -1,    -1,    -1,    -1,  1555,  1556,  1557,    -1,
    1559,    -1,    -1,    -1,    -1,    -1,  1565,  1566,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1584,    -1,    -1,    -1,  1588,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1599,    -1,    -1,  1602,    -1,    -1,    -1,  1606,    -1,   811,
      -1,    -1,    -1,    -1,    -1,    -1,  1615,  1616,    -1,  1618,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1626,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   844,  1642,    -1,    -1,    -1,    -1,  1647,  1648,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,  1657,    -1,
      -1,  1660,  1661,  1555,  1556,    -1,    -1,    -1,   763,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   773,    -1,
     775,   776,   777,   778,    -1,   780,   781,   782,   783,     8,
      -1,  1690,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   794,
      -1,   796,    -1,    -1,    -1,    -1,    -1,  1706,   803,    -1,
      -1,    -1,   807,   808,    -1,    -1,  1715,    -1,    -1,    -1,
      -1,   816,    -1,    -1,    -1,  1724,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1733,  1734,    -1,    -1,  1737,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,     6,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1771,  1772,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1787,    -1,
      -1,  1790,    -1,    -1,    -1,    -1,  1795,    -1,    -1,  1798,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,  1807,  1011,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1822,    -1,    -1,   921,   922,   923,    -1,
      -1,  1830,   927,   928,    -1,    -1,   931,   932,   933,   934,
      -1,   936,    -1,    -1,    -1,  1737,   941,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1855,    -1,    -1,    -1,
      -1,    -1,  1861,    -1,    -1,  1864,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,  1890,    -1,    -1,    -1,  1097,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,  1807,  1915,  1916,    -1,   238,
      -1,    -1,  1017,  1018,    -1,    -1,    -1,    -1,  1927,  1928,
    1822,  1930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1943,    -1,    -1,    -1,    -1,  1948,
    1949,  1950,  1951,  1952,    -1,    -1,    -1,    -1,    -1,  1958,
      -1,    -1,    -1,  1962,    -1,    -1,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
    1989,    -1,    -1,    -1,    -1,  1994,  1995,  1996,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2007,    -1,
      -1,    -1,    -1,    -1,  1109,    -1,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,  2035,  2036,  2037,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1249,  1250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1948,  1949,  1950,  1951,
    1952,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2007,    55,    56,    57,    58,
       6,    -1,    -1,    -1,    63,  1327,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1337,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,  1248,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,    -1,   124,    -1,   126,  1283,    -1,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
      -1,    -1,   151,    -1,    -1,    -1,  1311,  1312,  1313,  1314,
    1315,    -1,    -1,    -1,    -1,  1320,  1321,    -1,  1323,    -1,
    1325,    -1,    -1,    -1,  1329,    -1,    -1,  1332,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1344,
      -1,    -1,    -1,   192,    -1,    -1,    -1,   196,   197,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,   206,   207,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1485,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,   243,     6,    -1,   246,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1411,    -1,  1413,    -1,
      -1,    -1,  1417,    -1,  1419,    -1,    -1,    -1,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,  1453,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     6,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,  1540,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,    -1,   124,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,  1638,    -1,    -1,  1641,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1679,  1680,    -1,  1682,     6,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,   243,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,  1741,  1742,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
    1785,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,   119,    -1,   121,    -1,    -1,   124,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,    -1,    -1,   151,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     6,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,
     195,   196,   197,    -1,    -1,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,   210,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,   239,     3,     4,     5,   243,     7,
      -1,   246,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,  2016,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,
      88,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    -1,   185,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   234,   235,   236,    -1,
      -1,   239,    -1,   241,     3,     4,     5,   245,   246,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,    -1,   124,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
      -1,    -1,   151,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,   196,   197,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,   206,   207,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,     3,     4,    -1,   243,    -1,    -1,   246,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    13,    14,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,
     192,   126,   127,    -1,   196,   197,    -1,    -1,    -1,   201,
     202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,    -1,   169,   170,   171,   239,     3,     4,
      -1,   243,   244,    -1,   246,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
      75,    76,    77,    -1,    -1,    13,    14,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,   124,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,   119,   120,    -1,    -1,   123,   124,   192,   126,   127,
      -1,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,    -1,    -1,    -1,   211,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,   169,   170,   171,   239,     3,     4,    -1,   243,    -1,
      -1,   246,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,    75,    76,    77,
      -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,    -1,    -1,   124,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,
      -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,    -1,   123,   124,   192,   126,   127,    -1,   196,   197,
      -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,   207,
      -1,    -1,    -1,   211,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,   234,    -1,   169,   170,
     171,   239,     3,     4,    -1,   243,    -1,    -1,   246,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,    75,    76,    77,    -1,    -1,    13,
      14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
     121,    -1,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,   140,
     141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,   123,
     124,   192,   126,   127,    -1,   196,   197,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,
     211,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,
      -1,    -1,    -1,   234,    -1,   169,   170,   171,   239,     3,
       4,    -1,   243,    -1,    -1,   246,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,    75,    76,    77,    -1,    -1,    13,    14,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,
     124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,   140,   141,   142,   143,
     144,    -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,    -1,   123,   124,   192,   126,
     127,    -1,   196,   197,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,   206,   207,    -1,    -1,    -1,   211,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,
     234,    -1,   169,   170,   171,   239,     3,     4,    -1,    -1,
     244,    -1,   246,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    75,    76,
      77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,    -1,   124,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,   119,
     120,    -1,    -1,   123,   124,   192,   126,   127,    -1,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,
     207,    -1,    -1,    -1,   211,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,   169,
     170,   171,   239,     3,     4,    -1,   243,    -1,    -1,   246,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    75,    76,    77,    -1,    -1,
      13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,   121,    -1,    -1,   124,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,   143,   144,    -1,    -1,    -1,   148,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,   192,   126,   127,    -1,   196,   197,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,   206,   207,    -1,    -1,
      -1,   211,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,    -1,   169,   170,   171,   239,
       3,     4,    -1,   243,    -1,    -1,   246,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,    75,    76,    77,    -1,    -1,    13,    14,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,
      -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,   140,   141,   142,
     143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,   192,
     126,   127,    -1,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,   169,   170,   171,   239,     3,     4,    -1,
     243,    -1,    -1,   246,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    75,
      76,    77,    -1,    -1,    13,    14,    -1,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,   121,    -1,    -1,   124,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,
     136,   137,    -1,    -1,   140,   141,   142,   143,   144,    -1,
      -1,    -1,   148,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,    -1,   123,   124,   192,   126,   127,    -1,
     196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
     206,   207,    -1,    -1,    -1,   211,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,
     169,   170,   171,   239,     3,     4,    -1,   243,    -1,    -1,
     246,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    75,    76,    77,    -1,
      -1,    13,    14,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,    -1,    -1,   124,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,   143,   144,    -1,    -1,    -1,   148,
      -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,   113,     7,     8,    -1,    -1,    -1,   119,   120,    -1,
      -1,   123,   124,   192,   126,   127,    -1,   196,   197,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,   206,   207,    -1,
      -1,    -1,   211,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,   169,   170,   171,
     239,     3,     4,    -1,   243,    -1,    -1,   246,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
      -1,    -1,   124,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,   135,   136,   137,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,    -1,    -1,   196,   197,    -1,    -1,    -1,   201,
     202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,     3,     4,     5,    -1,   239,    -1,    -1,
      10,    11,    12,    -1,   246,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    -1,    88,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,   243,    -1,    -1,   246,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,   210,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,   239,     3,     4,     5,   243,
      -1,    -1,   246,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,     8,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      -1,    88,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,   243,    -1,    -1,   246,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,   210,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,
      -1,    -1,    -1,   234,     3,     4,    -1,    -1,   239,    -1,
      -1,    10,    11,    12,    -1,   246,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,     3,     4,    -1,    83,    84,    -1,    86,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,   206,   207,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,   243,    -1,    -1,   246,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
     192,   238,    -1,    -1,   196,    -1,    -1,    -1,     8,   201,
     202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,    -1,    -1,    -1,    -1,   239,     3,     4,
      -1,   243,    -1,    -1,   246,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,   192,   238,    -1,
      -1,   196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,
      -1,   246,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,   206,   207,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,
      -1,    -1,    -1,   234,     3,     4,    -1,     6,   239,    -1,
      -1,    10,    11,    12,    -1,   246,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,   129,    86,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,   192,    -1,   238,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,   206,   207,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,   246,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,   240,    -1,   242,    -1,    -1,   192,    -1,    -1,
     248,   196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
       3,     4,    -1,    -1,   239,    -1,    -1,    10,    11,    12,
      -1,   246,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,     3,     4,    -1,
      83,    84,    -1,    86,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      86,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,    -1,    -1,   192,
      -1,    -1,    -1,   196,   248,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,   192,    -1,   238,    -1,
     196,    -1,    -1,    -1,   244,   201,   202,   203,   248,   205,
     206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,     3,
       4,    -1,    -1,   239,   240,    -1,    10,    11,    12,    -1,
     246,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    13,    14,    -1,    83,
      84,    -1,    86,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,    -1,
     126,   127,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    13,    14,   145,
     107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,   119,   120,    -1,    -1,   123,   124,   192,   126,
     127,    -1,   196,   169,   170,   171,    -1,   201,   202,   203,
      -1,   205,   206,   207,    -1,    -1,    -1,   211,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,
     234,    -1,   169,   170,   171,   239,    -1,    -1,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,    -1,   113,   244,    -1,
      -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,    -1,
     126,   127,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,   170,   171,    -1,    -1,    44,    45,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    64,    65,
      66,    -1,   238,    -1,    70,    71,    -1,    73,   244,    -1,
      -1,    -1,    78,    79,    -1,    81,    82,    -1,    84,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
     106,   107,   108,   109,   110,   111,    -1,   113,   244,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,   124,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    -1,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,    -1,     4,
      -1,   157,   158,   159,    -1,    -1,    -1,   163,    13,    14,
      -1,    -1,   168,   169,   170,   171,    -1,    -1,   174,    -1,
     176,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,    -1,    -1,    44,
      45,    -1,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,    -1,   211,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,
      -1,    -1,    -1,    78,    79,    -1,    81,    82,    -1,    84,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,   106,   107,   108,   109,   110,   111,    -1,   113,    -1,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
     125,   126,   127,   128,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    -1,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,     4,     5,   174,
      -1,   176,    -1,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,   199,   200,    -1,     4,     5,    -1,
      -1,    -1,    -1,    -1,   209,    -1,   211,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,     4,     5,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    85,    -1,
      -1,    88,    59,    60,    61,    62,    -1,    -1,     5,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    85,    -1,
      -1,    88,    59,    60,    61,    62,    -1,    -1,    -1,   126,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    85,    -1,
      -1,    88,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,    -1,   210,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,   204,    -1,    -1,
      -1,   208,    -1,   210,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,   123,
     124,    -1,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   169,   170,   171,   107,   108,
     109,   110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
     119,   120,    -1,    -1,   123,   124,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
     169,   170,   171,    -1,    -1,   244,    -1,    -1,    -1,   248,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,   248,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,   244,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,   244,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,   244,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,   244,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,   244,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,   244,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,   244,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,   244,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,   244,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,   243,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,   243,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,   243,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,   240,    -1,   242,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,   242,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
     242,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,   242,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,   242,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,   242,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,   242,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,   242,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,   242,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,   242,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
     242,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,    -1,    -1,   242,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,   242,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,   242,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,   240,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   250,   251,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    79,    81,
      82,    84,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   106,   107,   108,
     109,   110,   111,   113,   115,   116,   117,   118,   119,   120,
     121,   123,   124,   125,   126,   127,   128,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     157,   158,   159,   163,   168,   169,   170,   171,   174,   176,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   198,   199,   200,   209,   211,   252,
     254,   255,   275,   293,   295,   299,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   317,   319,   320,   326,   327,
     328,   329,   335,   360,   361,   243,   247,    14,    97,   239,
     239,     6,   243,     6,     6,     6,     6,   239,     6,     6,
     241,   241,     4,   337,   361,   239,   241,   273,   273,   239,
     239,   239,     4,   239,   239,   239,     4,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   243,   112,
      97,     6,   243,    91,    94,    97,   110,   298,   239,     3,
      10,    11,    12,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    55,    56,    57,    58,    63,    75,    76,    77,
      83,    86,    91,    94,    97,    99,   119,   124,   126,   192,
     196,   197,   201,   202,   203,   205,   206,   207,   227,   228,
     234,   239,   243,   246,   295,   299,   310,   317,   319,   330,
     331,   335,   337,   344,   346,   361,   239,   243,    97,    97,
     119,    94,    97,    99,    91,   295,    94,    97,    99,   110,
     296,    94,    97,   239,    94,   149,   174,   190,   191,   243,
     227,   228,   239,   243,   341,   342,   341,   243,   243,   341,
       4,    91,    95,   101,   102,   104,   105,   123,   239,    97,
      99,    97,    94,     4,    84,   185,   243,   361,     4,     6,
      91,    94,    97,    94,    97,   110,   297,     4,     4,     4,
       5,   239,   344,   345,     4,   239,   239,   239,     4,   243,
     348,   361,     4,   239,   239,   239,     6,     6,   241,     5,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    59,
      60,    61,    62,    67,    68,    69,    72,    74,    85,    88,
     193,   194,   195,   204,   208,   210,   352,   361,   239,     4,
     352,     5,   243,     5,   243,    32,   228,   330,   361,   241,
     243,   239,   243,     6,   239,   243,     6,   247,     7,   126,
     185,   212,   213,   214,   215,   235,   236,   239,   241,   245,
     271,   272,   273,   330,   351,   352,   361,     4,   299,   300,
     301,   243,     6,   330,   351,   352,   361,   351,   330,   351,
     358,   359,   361,   277,   281,   239,   340,     9,   352,   361,
     330,   330,   330,   239,   330,   330,   330,   239,   330,   330,
     330,   330,   330,   330,   330,   351,   330,   330,   330,   330,
     344,   239,   228,   330,   346,   347,   243,   345,   351,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   239,   241,   273,   273,   273,   273,   273,   273,
     239,   273,   273,   239,   273,   273,   243,   119,   295,   239,
     273,   273,   239,   239,   239,   330,   243,   330,   346,   330,
     330,   244,   347,   337,   361,     5,   177,     8,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   238,     9,   239,   241,
     245,   272,   273,   330,   347,   239,   239,   239,   344,   345,
     345,   345,   294,   243,   239,   344,   243,   243,   330,     4,
     344,   243,   348,   243,   243,   341,   341,   341,   330,   330,
     227,   228,   243,   243,   341,   227,   228,   239,   301,   341,
     243,   239,   243,   239,   239,   239,   239,   239,   239,   239,
     330,   345,   345,   345,   239,     4,   241,     6,   241,   301,
       6,     6,   243,   243,   243,   243,   345,   241,   241,   241,
     330,     6,     6,   330,   330,   330,   245,   330,   243,   177,
     330,   330,   330,   330,   273,   273,   273,   239,   239,   239,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     239,   239,   273,   239,   241,     6,     6,   243,     6,   301,
       6,   301,   273,   330,   229,   243,     9,   239,   241,   245,
     351,   347,   330,   301,   344,   344,   243,   352,    91,    94,
      97,    99,     7,   330,   330,     4,   174,   175,   344,     6,
     240,   242,   243,   274,     6,   243,     6,     9,   239,   241,
     245,   361,   244,   119,   124,   127,   293,   295,   330,     6,
     240,   248,     9,   239,   241,   245,   240,   248,   248,   240,
     248,     9,   239,   245,   242,   248,   276,   242,   276,    87,
     339,   336,   361,   248,   248,   240,   240,   240,   330,   240,
     240,   240,   330,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   244,     7,   330,   229,   244,   248,
     330,     6,   240,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     346,   330,   330,   330,   330,   330,   330,   330,   346,   346,
     361,   243,   330,   330,   351,   330,   351,   344,   351,   351,
     358,   330,   274,   361,   330,   345,   351,   351,   346,   337,
     352,   337,   347,   240,   244,   245,   273,    64,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   243,   330,   346,   330,   330,   330,   330,   330,
     361,   330,   330,     4,   338,   243,   274,   240,   244,   330,
     330,   330,     7,     7,   323,   323,   239,   330,   330,     6,
     347,   347,   243,   240,     6,   301,   243,   301,   301,   248,
     248,   248,   341,   341,   300,   300,   248,   330,   244,   314,
     248,   301,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   240,     7,   324,     6,     7,   330,     6,   330,   330,
     244,   347,   347,   347,   330,     6,   330,   330,   330,   240,
     240,   240,   240,   174,   248,   301,   243,     8,   240,   240,
     242,   358,   351,   358,   351,   351,   351,   351,   351,   351,
     330,   351,   351,   351,   351,   246,   354,   361,   352,   351,
     351,   351,   337,   361,   347,   244,   244,   330,   330,   301,
     361,   338,   242,   244,   240,   132,   149,   318,   240,   244,
     248,   330,     6,   243,   243,   243,   243,   330,   240,   242,
       7,   271,   272,   245,     7,     6,   347,     7,   212,   271,
     256,   361,   330,   330,   338,   241,   239,   119,   296,   243,
     244,     6,   223,   226,   253,   347,   361,   330,   330,     4,
     338,     6,   347,   330,     6,   351,   359,   361,   240,   338,
       6,   361,     6,   351,   330,   240,   241,   330,   352,     7,
       7,     7,   240,     7,     7,     7,   240,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   330,   240,   243,
     330,   346,   244,     6,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   248,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   248,   248,   248,   240,   242,
     242,   347,   248,   248,   274,   248,   274,   248,   248,   248,
     240,   332,   274,   244,   248,   248,   274,   274,   240,   245,
     240,   245,   248,   273,   333,   244,     7,   338,   274,   243,
       8,     8,   347,   245,   240,   242,   272,   239,   241,   273,
     347,     7,   243,   240,   240,   240,   330,   344,     4,   322,
       6,   290,   330,   352,   244,   240,   244,   244,   347,   245,
     244,   301,   244,   244,   341,   330,   330,   244,   244,   330,
     341,   129,   129,   146,   154,   155,   156,   160,   161,   315,
     316,   341,   244,   311,   240,   244,   240,   240,   240,   240,
     240,   240,   240,     7,   330,     6,   330,   240,   242,   242,
     244,   244,   244,   244,   242,   242,   248,     7,     7,     7,
     245,   330,   244,   330,   330,     7,   245,   274,   248,   274,
     274,   240,   240,   248,   274,   274,   248,   248,   274,   274,
     274,   274,   330,   274,     9,   353,   248,   240,   248,   274,
     245,   248,   334,   242,   244,   244,   245,   239,   241,   247,
     177,     7,   149,     6,   330,   244,   243,     6,   344,   244,
     330,   330,   330,   330,     6,     7,   271,   272,   245,   271,
     272,   352,   330,     6,     4,   243,   349,   361,   244,    46,
      46,   344,     4,   164,   165,   166,   167,   244,   259,   263,
     266,   268,   269,   245,   240,   242,   239,   330,   330,   239,
     239,   347,   351,   240,   245,   240,   242,   239,   240,   248,
     245,   239,     7,   273,     4,   284,   285,   286,   274,   274,
     341,   344,   344,     7,   344,   344,   344,     7,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,     6,     7,
     347,   330,   330,   330,   330,   244,   330,   330,   330,   344,
     351,   351,   248,   283,   330,   330,   338,   338,   330,   330,
     240,   344,   273,   330,   330,   330,   244,   338,   272,   245,
     272,   330,   330,   274,   244,   344,   347,     7,     7,     7,
     129,   321,     6,   240,   248,     7,     7,     7,   244,     4,
     244,   248,   248,   248,   244,   244,   109,     4,     6,   330,
     243,     6,   239,     6,   162,     6,   162,   244,   316,   248,
     315,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     344,     6,   243,     6,     6,     6,    97,     7,     6,     6,
     330,   344,   344,   344,     4,   248,     8,     8,   240,     4,
       4,   347,   351,   330,   351,   246,   248,   287,   351,   351,
     338,   351,   240,   248,   338,   243,   295,   243,     6,   330,
       6,   243,   344,   244,   244,   244,   244,   244,   330,     6,
       4,   174,   175,   330,     6,     6,     6,     7,   348,   350,
       6,   241,   274,   273,   273,     6,   260,   239,   239,   243,
     270,     6,   338,   245,   351,   330,   242,   240,   330,   330,
     244,     6,     6,   253,   338,   245,   330,     6,   330,   338,
     240,   243,   330,   352,   274,    46,   243,   344,   352,   355,
     242,   248,     6,     6,     6,   123,   292,   292,   344,     6,
       6,     6,   344,   177,   291,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   244,   274,   274,   274,   274,
     274,   248,   248,   248,   240,   274,   274,   285,   274,   240,
     274,   240,   273,   333,   274,     6,   274,   248,   239,   241,
     273,     4,   240,   242,   274,     6,   244,   344,   344,   344,
       4,     6,   271,   330,   344,   243,   243,     7,     6,     7,
     330,   330,   330,   243,   243,   243,   241,     6,   330,   344,
     330,     6,     6,   330,   341,   244,     5,   344,   243,   243,
     243,   243,   243,   243,   243,   344,     6,   347,   243,   330,
     242,     6,     6,   173,   330,   330,   330,     6,     6,     7,
     274,   248,   248,   274,   248,   330,     4,   189,   288,   289,
     274,   240,   274,   334,   352,   239,   241,   330,   243,   301,
       6,   301,   248,     6,     6,     7,   271,   272,   245,     7,
       6,   348,   244,   248,   330,   271,   243,   274,   356,   357,
     358,   356,   239,   330,   330,   343,   344,   243,   239,     4,
       6,   240,     6,   240,   240,     6,   351,   239,     4,   240,
     248,   239,   344,   352,     7,   273,   282,   330,   346,   286,
     341,     6,     6,     6,     6,    95,     6,     5,   243,   330,
     330,   330,   330,   240,   333,   330,   330,   330,   274,   272,
     243,     6,   291,     6,   330,   344,     4,     6,   347,   347,
     330,   330,   352,   244,   240,   244,   248,   300,   300,   330,
     330,   244,   248,   240,   244,   248,     6,     6,   343,   341,
     341,   341,   341,   341,   228,   341,     6,   244,   330,     6,
       6,   344,   244,   248,     8,   244,   240,   243,   330,   352,
     351,   330,   351,   330,   352,   355,   357,   352,   248,   240,
     248,   244,   330,   318,   318,   344,   352,   330,     6,     4,
     349,     6,   348,   242,   344,   358,     6,   274,   274,   257,
     330,   248,   248,   244,   248,   258,   330,   330,     6,   330,
     330,   240,   278,   280,   243,   357,   244,   248,     7,     7,
     243,     5,   343,   274,   274,   248,   274,   240,   248,   240,
     242,   330,     6,     6,   243,   244,   244,   243,     6,     6,
     243,   330,   244,   244,   244,   242,     6,   344,     7,   243,
     330,   244,   248,   248,   248,   248,   248,   248,     6,   244,
     172,   330,   330,   347,     6,     6,   240,   274,   274,   289,
     352,   244,   244,   244,   244,     6,     6,     7,     6,   245,
       6,   244,     6,     6,   240,   248,   330,   330,   243,   344,
     244,   248,   240,   240,   248,   283,   287,   344,   274,   330,
     352,   361,   330,     6,   244,   330,   333,   330,   244,   343,
     133,   134,   139,   325,   133,   134,   325,   347,   300,   244,
     248,     6,   244,   344,   301,   244,     6,   347,   341,   341,
     341,   341,   341,   330,   244,   244,   244,   240,     6,   243,
       6,   348,   175,   261,   330,   248,   248,   343,     6,   330,
     330,   244,   244,   279,     7,   239,   244,   243,   248,   240,
     248,   244,   243,   341,   344,     6,   243,   341,     6,   244,
     244,   330,     6,   129,   244,   312,   243,   244,   248,   248,
     248,   248,   248,     6,     6,     6,   301,     6,   243,   330,
     330,   244,   248,   283,   352,   240,   330,   330,   330,     6,
     341,     6,   341,     6,     6,   244,   330,   315,   301,     6,
     347,   347,   347,   347,   341,   347,   318,   258,   240,   248,
       6,   243,   330,   244,   248,   248,   248,   248,   248,     6,
     244,   244,   313,   244,   244,   244,   244,   248,   244,   244,
     244,   264,   330,   343,   244,   330,   330,   330,   341,   341,
     315,     6,     6,     6,     6,   347,     6,     6,     6,   243,
     240,   244,     6,   244,   274,   248,   248,   248,   244,   244,
     262,   351,   267,   243,     6,   330,   330,   330,     6,   244,
     248,   243,   343,   244,   244,   244,     6,   351,   265,   351,
     244,     6,     6,   244,   248,     6,     6,   351
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   249,   250,   250,   251,   251,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   253,   253,   254,   254,
     254,   254,   254,   254,   255,   255,   255,   255,   256,   256,
     256,   256,   256,   256,   257,   257,   258,   258,   260,   261,
     259,   262,   262,   264,   263,   265,   265,   267,   266,   268,
     268,   270,   269,   271,   271,   271,   271,   271,   272,   272,
     273,   273,   274,   274,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   276,
     276,   277,   277,   277,   278,   277,   279,   277,   277,   280,
     277,   281,   281,   282,   282,   282,   283,   283,   284,   284,
     285,   285,   286,   286,   286,   286,   286,   287,   287,   288,
     288,   289,   289,   289,   289,   289,   290,   290,   290,   291,
     291,   292,   292,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   293,   295,   295,   295,
     295,   295,   296,   296,   296,   296,   297,   297,   297,   298,
     298,   298,   298,   299,   299,   299,   299,   299,   299,   299,
     299,   300,   300,   301,   301,   301,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   303,   303,
     303,   303,   303,   303,   303,   304,   304,   305,   306,   306,
     306,   306,   306,   306,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   310,   310,
     310,   311,   310,   312,   310,   313,   310,   314,   310,   310,
     310,   310,   310,   315,   315,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   317,   317,   317,   317,
     317,   318,   318,   318,   318,   318,   319,   319,   320,   321,
     321,   322,   322,   323,   323,   324,   324,   325,   325,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     327,   327,   327,   328,   328,   328,   329,   329,   329,   329,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   332,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   333,   333,   334,   334,   336,
     335,   337,   337,   338,   339,   339,   340,   340,   341,   341,
     341,   341,   341,   342,   342,   342,   342,   343,   343,   344,
     344,   344,   344,   344,   344,   345,   345,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   347,   347,   347,   347,   348,   348,   348,   348,
     349,   349,   350,   350,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   353,   352,   352,   354,
     354,   355,   356,   356,   357,   358,   358,   358,   358,   359,
     359,   359,   360,   360,   360,   361,   361,   361
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
       9,     5,     7,     9,     9,    11,     7,     9,     9,     0,
       1,     0,     3,     5,     0,     9,     0,    11,     5,     0,
       9,     0,     3,     3,     5,     5,     0,     2,     0,     1,
       1,     3,     2,     1,     4,     2,     2,     0,     2,     1,
       3,     2,     2,     2,     2,     2,     1,     1,     3,     0,
       5,     0,     2,     7,     7,     7,     8,     8,     7,     7,
      11,     7,     8,     8,     8,     9,     3,     4,    10,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     8,
       7,     7,     8,     8,    12,     0,     9,     1,     1,     1,
       1,     4,     1,     1,     1,     4,     1,     1,     4,     1,
       1,     1,     4,     5,    11,     5,     9,     9,     4,     9,
       9,     1,     1,     0,     2,     6,     8,    10,    14,    16,
      12,    14,    14,    14,    14,     8,     8,     6,     4,     5,
       6,     6,     3,     4,     3,     5,     6,     5,     3,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     7,
       3,     2,     2,     2,     2,     2,    15,     2,     2,     2,
       2,     2,    16,    11,     6,     8,     8,    10,     1,     2,
       2,     1,     3,     3,     4,     4,     1,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     9,
       2,     3,    10,     1,     2,     5,     7,     2,     2,     3,
       2,     3,     2,     3,     9,     6,     1,     1,     1,     1,
       1,     0,     2,     3,     3,     4,     9,     4,    14,     0,
       3,     0,     1,     0,     2,     0,     2,     0,     2,     6,
       7,     6,     5,     3,     8,     5,     4,     6,    11,    11,
      18,    18,    12,    12,    12,    10,     4,     4,     4,     4,
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
       1,     2,     3,     4,     5,     1,     1,     2,     3,     3,
       5,     4,     2,     3,    16,     1,     1,     1,     3,     5,
       7,     4,     4,     4,     6,     6,     8,     8,     4,    14,
       4,     4,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     4,     4,     3,     5,
       6,     8,     6,     5,     5,     5,     5,     1,     4,     1,
       1,     1,     1,     4,     6,     4,     6,     5,     7,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     8,     6,
       4,     6,     4,     1,     4,     4,     0,     6,     4,     2,
       4,     4,     1,     1,     3,     1,     1,     3,     3,     3,
       5,     7,     5,     5,     8,     1,     1,     4
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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

  return yystpcpy (yyres, yystr) - yyres;
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
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

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
                  (unsigned long int) yystacksize));

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
#line 267 "Gmsh.y" /* yacc.c:1646  */
    { yyerrok; return 1; }
#line 5485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 278 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5491 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 279 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 280 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 282 "Gmsh.y" /* yacc.c:1646  */
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
#line 5526 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 300 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 301 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 5538 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 302 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5544 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 303 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5550 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 304 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5556 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 305 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5562 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 306 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 5568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 307 "Gmsh.y" /* yacc.c:1646  */
    { List_Delete((yyvsp[0].l)); return 1; }
#line 5574 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 308 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5580 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 309 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5586 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 310 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 311 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5598 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 312 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 313 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5610 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 314 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5616 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 315 "Gmsh.y" /* yacc.c:1646  */
    { return 1; }
#line 5622 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 320 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"w";
    }
#line 5630 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 324 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char*)"a";
    }
#line 5638 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 331 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Direct((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 5647 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 336 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Error((yyvsp[-2].c));
      Free((yyvsp[-2].c));
    }
#line 5656 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 341 "Gmsh.y" /* yacc.c:1646  */
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
#line 5674 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 355 "Gmsh.y" /* yacc.c:1646  */
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
#line 5691 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 368 "Gmsh.y" /* yacc.c:1646  */
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
#line 5708 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 381 "Gmsh.y" /* yacc.c:1646  */
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
#line 5735 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 409 "Gmsh.y" /* yacc.c:1646  */
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
#line 5753 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 423 "Gmsh.y" /* yacc.c:1646  */
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
#line 5770 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 436 "Gmsh.y" /* yacc.c:1646  */
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
#line 5787 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 449 "Gmsh.y" /* yacc.c:1646  */
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
#line 5806 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 467 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
#line 5816 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 481 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 5822 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 483 "Gmsh.y" /* yacc.c:1646  */
    { ViewCoord.push_back((yyvsp[0].d)); }
#line 5828 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 488 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 5834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 490 "Gmsh.y" /* yacc.c:1646  */
    { if(ViewValueList) ViewValueList->push_back((yyvsp[0].d)); }
#line 5840 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 495 "Gmsh.y" /* yacc.c:1646  */
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
#line 5948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 599 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
#line 5962 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 609 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
#line 5972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 618 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 625 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 5994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 635 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[-5].d));
      ViewData->T2D.push_back((yyvsp[-3].d));
      ViewData->T2D.push_back((yyvsp[-1].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
#line 6007 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 644 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
#line 6017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 653 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6028 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 660 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[0].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[0].c)[i]);
#endif
      Free((yyvsp[0].c));
    }
#line 6039 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 670 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[-7].d)); ViewData->T3D.push_back((yyvsp[-5].d));
      ViewData->T3D.push_back((yyvsp[-3].d)); ViewData->T3D.push_back((yyvsp[-1].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
#line 6051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 678 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
#line 6061 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 688 "Gmsh.y" /* yacc.c:1646  */
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
#line 6081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 707 "Gmsh.y" /* yacc.c:1646  */
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
#line 6101 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 726 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
#line 6111 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 732 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 6118 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 739 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 6124 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 740 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 6130 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 741 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 6136 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 742 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 6142 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 743 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 4; }
#line 6148 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 747 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 6154 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 748 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = -1; }
#line 6160 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 754 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"("; }
#line 6166 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 754 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"["; }
#line 6172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 755 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)")"; }
#line 6178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 755 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"]"; }
#line 6184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 765 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabNumber((yyvsp[-4].c), (yyvsp[-2].d));
      Free((yyvsp[-4].c));
    }
#line 6193 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 770 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::SetOnelabString((yyvsp[-4].c), (yyvsp[-2].c));
      Free((yyvsp[-4].c));
      Free((yyvsp[-2].c));
    }
#line 6203 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 776 "Gmsh.y" /* yacc.c:1646  */
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
#line 6269 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 838 "Gmsh.y" /* yacc.c:1646  */
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
#line 6288 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 853 "Gmsh.y" /* yacc.c:1646  */
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
#line 6321 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 882 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariables((yyvsp[-8].c), (yyvsp[-5].l), (yyvsp[-2].i), (yyvsp[-1].l));
      Free((yyvsp[-8].c));
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-1].l));
    }
#line 6332 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 892 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6341 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 897 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6350 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 905 "Gmsh.y" /* yacc.c:1646  */
    {
      assignVariable((yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-2].i), (yyvsp[-1].d));
      Free((yyvsp[-6].c));
    }
#line 6359 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 910 "Gmsh.y" /* yacc.c:1646  */
    {
      incrementVariable((yyvsp[-5].c), (yyvsp[-3].d), (yyvsp[-1].i));
      Free((yyvsp[-5].c));
    }
#line 6368 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 918 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-3].c)] = std::vector<std::string>(1, (yyvsp[-1].c));
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 6378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 927 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yystringsymbols[(yyvsp[-7].c)] = std::vector<std::string>();
      Free((yyvsp[-7].c));
    }
#line 6387 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 932 "Gmsh.y" /* yacc.c:1646  */
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
#line 6403 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 944 "Gmsh.y" /* yacc.c:1646  */
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
#line 6421 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 961 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-5].c), 0, (yyvsp[-3].c), tmp);
      Free((yyvsp[-5].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6431 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 967 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp((yyvsp[-1].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[-8].c), (int)(yyvsp[-6].d), (yyvsp[-3].c), tmp);
      Free((yyvsp[-8].c)); Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 6441 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 976 "Gmsh.y" /* yacc.c:1646  */
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
#line 6463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 994 "Gmsh.y" /* yacc.c:1646  */
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
#line 6485 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1012 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-4].c), 0, (yyvsp[-2].c), d);
      }
      Free((yyvsp[-4].c)); Free((yyvsp[-2].c));
    }
#line 6498 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1021 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d)){
	d += (yyvsp[-1].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), (int)(yyvsp[-5].d), (yyvsp[-2].c), d);
      }
      Free((yyvsp[-7].c)); Free((yyvsp[-2].c));
    }
#line 6511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1033 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-7].c), 0, (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-7].c)); Free((yyvsp[-3].c));
    }
#line 6520 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1038 "Gmsh.y" /* yacc.c:1646  */
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[-10].c), (int)(yyvsp[-8].d), (yyvsp[-3].c), (yyvsp[-1].u));
      Free((yyvsp[-10].c)); Free((yyvsp[-3].c));
    }
#line 6529 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1046 "Gmsh.y" /* yacc.c:1646  */
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
#line 6553 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1066 "Gmsh.y" /* yacc.c:1646  */
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
#line 6577 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1089 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[-4].c),"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)(yyvsp[-1].d));
      else if(!strcmp((yyvsp[-4].c),"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)(yyvsp[-1].d));
      else
	yymsg(0, "Unknown command '%s Field'", (yyvsp[-4].c));
#endif
    }
#line 6592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1100 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[-4].d), (yyvsp[-1].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[-4].d), (yyvsp[-1].c));
#endif
      Free((yyvsp[-1].c));
    }
#line 6604 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1108 "Gmsh.y" /* yacc.c:1646  */
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
#line 6630 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1130 "Gmsh.y" /* yacc.c:1646  */
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
#line 6657 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1153 "Gmsh.y" /* yacc.c:1646  */
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
#line 6699 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1191 "Gmsh.y" /* yacc.c:1646  */
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
#line 6721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1212 "Gmsh.y" /* yacc.c:1646  */
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
#line 6737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1224 "Gmsh.y" /* yacc.c:1646  */
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
#line 6753 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1242 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[0].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[0].c));
    }
#line 6766 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1251 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c));
      std::vector<double> val(1, (yyvsp[0].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[-2].c));
    }
#line 6779 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1260 "Gmsh.y" /* yacc.c:1646  */
    { init_options(); }
#line 6785 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1262 "Gmsh.y" /* yacc.c:1646  */
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
      Free((yyvsp[-3].l));
    }
#line 6807 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1280 "Gmsh.y" /* yacc.c:1646  */
    { init_options(); }
#line 6813 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1282 "Gmsh.y" /* yacc.c:1646  */
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
      Free((yyvsp[-3].l));
    }
#line 6833 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1298 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-2].c)), val((yyvsp[0].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-2].c));
      Free((yyvsp[0].c));
    }
#line 6846 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1307 "Gmsh.y" /* yacc.c:1646  */
    { init_options(); }
#line 6852 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1309 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-6].c)), val((yyvsp[-3].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[-6].c));
      Free((yyvsp[-3].c));
    }
#line 6866 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1323 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name((yyvsp[0].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[0].c));
    }
#line 6876 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1331 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1337 "Gmsh.y" /* yacc.c:1646  */
    {
      doubleXstring v = {(yyvsp[-2].d), (yyvsp[0].c)};
      List_Add((yyval.l), &v);
    }
#line 6895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1342 "Gmsh.y" /* yacc.c:1646  */
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
    }
#line 6923 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1384 "Gmsh.y" /* yacc.c:1646  */
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
#line 6939 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1396 "Gmsh.y" /* yacc.c:1646  */
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
#line 6956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1409 "Gmsh.y" /* yacc.c:1646  */
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
#line 6974 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1424 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 6986 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1433 "Gmsh.y" /* yacc.c:1646  */
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
#line 7001 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1458 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      double val = (yyvsp[0].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[-1].c));
    }
#line 7012 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1466 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key((yyvsp[-1].c));
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[-1].c));
      Free((yyvsp[0].c));
    }
#line 7024 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1475 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string key("Macro");
      std::string val((yyvsp[0].c));
      charOptions[key].push_back(val);
      Free((yyvsp[0].c));
    }
#line 7035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1483 "Gmsh.y" /* yacc.c:1646  */
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
#line 7052 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1497 "Gmsh.y" /* yacc.c:1646  */
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
#line 7069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1515 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 7077 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1519 "Gmsh.y" /* yacc.c:1646  */
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[0].c)), dim_entity, t + 1);
      Free((yyvsp[0].c));
    }
#line 7088 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1526 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[-2].c)), dim_entity, (yyvsp[0].d));
      Free((yyvsp[-2].c));
    }
#line 7097 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1534 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1;
    }
#line 7105 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1538 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
    }
#line 7113 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1544 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
#line 7121 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1548 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 7129 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1555 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[-1].v)[3];
      if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
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
#line 7157 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1579 "Gmsh.y" /* yacc.c:1646  */
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
#line 7177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1595 "Gmsh.y" /* yacc.c:1646  */
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
#line 7197 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1611 "Gmsh.y" /* yacc.c:1646  */
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
#line 7238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1648 "Gmsh.y" /* yacc.c:1646  */
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
#line 7282 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1688 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "BSpline not yet available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->addBSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add BSpline");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    }
#line 7302 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1704 "Gmsh.y" /* yacc.c:1646  */
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
#line 7322 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1721 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-8].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-5].l), tags);
      std::vector<double> knots; ListOfDouble2Vector((yyvsp[-3].l), knots);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Nurbs not available yet with OpenCASCADE geometry kernel");
      }
      else{
        int order = knots.size() - tags.size() - 1;
        if(order != (int)(yyvsp[-1].d))
          yymsg(1, "Incompatible Nurbs order: using %d", order);
        r = GModel::current()->getGEOInternals()->addNurbs(num, tags, knots);
      }
      if(!r) yymsg(0, "Could not add nurbs");
      List_Delete((yyvsp[-5].l));
      List_Delete((yyvsp[-3].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    }
#line 7347 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1742 "Gmsh.y" /* yacc.c:1646  */
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
#line 7367 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1758 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        for(unsigned int i = 0; i < tags.size(); i++)
          tags[i] = std::abs(tags[i]); // all edge tags > 0 for OCC
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
#line 7390 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1777 "Gmsh.y" /* yacc.c:1646  */
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
#line 7410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1793 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-5].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-2].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE face filling requires a single line loop");
        }
        else{
          r = GModel::current()->getOCCInternals()->addSurfaceFilling(num, wires[0]);
        }
      }
      else{
        r = GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[-1].i));
      }
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[-2].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    }
#line 7435 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1814 "Gmsh.y" /* yacc.c:1646  */
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[-5].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[-2].l), wires);
      bool r = GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[-1].i));
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[-2].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    }
#line 7450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1825 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7460 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1831 "Gmsh.y" /* yacc.c:1646  */
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[-1].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
#line 7470 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1837 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-6].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[-3].c), (yyvsp[-2].c), (yyvsp[-1].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
#line 7481 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1844 "Gmsh.y" /* yacc.c:1646  */
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
#line 7516 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1875 "Gmsh.y" /* yacc.c:1646  */
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
#line 7535 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1890 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[-1].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() == 6){
          r = GModel::current()->getOCCInternals()->addBlock
            (num, param[0], param[1], param[2], param[3], param[4], param[5]);
        }
        else{
          yymsg(0, "Block requires 6 parameters");
        }
      }
      else{
        yymsg(0, "Block only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add block");
      List_Delete((yyvsp[-1].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
#line 7561 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1912 "Gmsh.y" /* yacc.c:1646  */
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
#line 7588 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1935 "Gmsh.y" /* yacc.c:1646  */
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
#line 7615 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1958 "Gmsh.y" /* yacc.c:1646  */
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
#line 7642 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1981 "Gmsh.y" /* yacc.c:1646  */
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
#line 7670 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 2005 "Gmsh.y" /* yacc.c:1646  */
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
#line 7698 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 2029 "Gmsh.y" /* yacc.c:1646  */
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
#line 7726 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 2053 "Gmsh.y" /* yacc.c:1646  */
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
#line 7756 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 2079 "Gmsh.y" /* yacc.c:1646  */
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
#line 7777 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 2096 "Gmsh.y" /* yacc.c:1646  */
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
#line 7797 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 2112 "Gmsh.y" /* yacc.c:1646  */
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
#line 7819 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 2130 "Gmsh.y" /* yacc.c:1646  */
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
#line 7841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 2148 "Gmsh.y" /* yacc.c:1646  */
    {
      int num = (int)(yyvsp[-4].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      switch ((yyvsp[-6].i)) {
      case 1:
        {
          bool r = GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
          if(!r) yymsg(0, "Could not add compound line");
        }
        (yyval.s).Type = MSH_SEGM_COMPOUND;
        break;
      case 2:
        {
          bool r = GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
          if(!r) yymsg(0, "Could not add compound surface");
        }
        (yyval.s).Type = MSH_SURF_COMPOUND;
        break;
      case 3:
        {
          bool r = GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
          if(!r) yymsg(0, "Could not add compound volume");
        }
        (yyval.s).Type = MSH_VOLUME_COMPOUND;
        break;
      }
      List_Delete((yyvsp[-1].l));
      (yyval.s).Num = num;
    }
#line 7875 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 2179 "Gmsh.y" /* yacc.c:1646  */
    {
      // Particular case only for dim 2 (Surface)
      if ((yyvsp[-10].i) == 2) {
        int num = (int)(yyvsp[-8].d);
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[-5].l), tags);
        std::vector<int> bndTags[4];
        for(int i = 0; i < List_Nbr((yyvsp[-2].l)); i++){
          if(i < 4)
            ListOfDouble2Vector(*(List_T**)List_Pointer((yyvsp[-2].l), i), bndTags[i]);
          else
            break;
        }
        bool r = GModel::current()->getGEOInternals()->addCompoundSurface
          (num, tags, bndTags);
        if(!r) yymsg(0, "Could not add compound surface");
        List_Delete((yyvsp[-5].l));
        Free((yyvsp[-4].c));
        for (int i = 0; i < List_Nbr((yyvsp[-2].l)); i++)
          List_Delete(*(List_T**)List_Pointer((yyvsp[-2].l), i));
        List_Delete((yyvsp[-2].l));
        (yyval.s).Type = MSH_SURF_COMPOUND;
        (yyval.s).Num = num;
      }
      else {
        yymsg(0, "GeoEntity dim out of range [2,2]");
      }
    }
#line 7907 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 2207 "Gmsh.y" /* yacc.c:1646  */
    {
      dim_entity = (yyvsp[0].i);
    }
#line 7915 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 2211 "Gmsh.y" /* yacc.c:1646  */
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
#line 7942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 2237 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 7948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 2239 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 7954 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 2241 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 7960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 2243 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 7966 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 2245 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
#line 7975 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 2253 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 7981 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 2255 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 7987 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 2257 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 3; }
#line 7993 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 2259 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
#line 8002 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 2267 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 8008 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 2269 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 8014 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 2271 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
#line 8023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 2279 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 8029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 2281 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 8035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 2283 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 8041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 2285 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[-1].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
#line 8050 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 2295 "Gmsh.y" /* yacc.c:1646  */
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
#line 8070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 2311 "Gmsh.y" /* yacc.c:1646  */
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
#line 8090 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 2327 "Gmsh.y" /* yacc.c:1646  */
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
#line 8110 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 2343 "Gmsh.y" /* yacc.c:1646  */
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
#line 8130 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 2359 "Gmsh.y" /* yacc.c:1646  */
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
#line 8150 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 2375 "Gmsh.y" /* yacc.c:1646  */
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
      else if(action == "Boundary" || action == "CombinedBoundary"){
        // boundary operations are performed directly on GModel, which enables
        // to compute the boundary of hybrid CAD models; this also automatically
        // binds all boundary entities for OCC models
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        r = GModel::current()->getBoundaryTags
          (inDimTags, outDimTags, action == "CombinedBoundary");
      }
      else{
        yymsg(0, "Unknown action on multiple shapes '%s'", (yyvsp[-3].c));
      }
      if(!r) yymsg(0, "Could not apply operation on shapes");
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[-3].c));
    }
#line 8189 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 2410 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Intersect line not available with OpenCASCADE");
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
#line 8214 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 2432 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Line not available with OpenCASCADE");
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
#line 8239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 2455 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 2456 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 8251 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 2461 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
#line 8259 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 2465 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &(yyvsp[0].s));
    }
#line 8267 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 2469 "Gmsh.y" /* yacc.c:1646  */
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
    }
#line 8287 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 2490 "Gmsh.y" /* yacc.c:1646  */
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
#line 8310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 2509 "Gmsh.y" /* yacc.c:1646  */
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
#line 8335 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 2531 "Gmsh.y" /* yacc.c:1646  */
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
#line 8353 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 2546 "Gmsh.y" /* yacc.c:1646  */
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
#line 8372 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 2561 "Gmsh.y" /* yacc.c:1646  */
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
#line 8394 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 2580 "Gmsh.y" /* yacc.c:1646  */
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
#line 8448 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 2631 "Gmsh.y" /* yacc.c:1646  */
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
#line 8472 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 2652 "Gmsh.y" /* yacc.c:1646  */
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
#line 8497 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 2674 "Gmsh.y" /* yacc.c:1646  */
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
#line 8523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 2696 "Gmsh.y" /* yacc.c:1646  */
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
#line 8632 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 2801 "Gmsh.y" /* yacc.c:1646  */
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
#line 8652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 2817 "Gmsh.y" /* yacc.c:1646  */
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
#line 8686 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 2852 "Gmsh.y" /* yacc.c:1646  */
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
#line 8712 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 2874 "Gmsh.y" /* yacc.c:1646  */
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
#line 8738 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 2896 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[-2].d));
#endif
    }
#line 8748 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 2902 "Gmsh.y" /* yacc.c:1646  */
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
#line 8767 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 2917 "Gmsh.y" /* yacc.c:1646  */
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
	GModel::current()->deletePhysicalGroups();
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
#line 8799 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 2945 "Gmsh.y" /* yacc.c:1646  */
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
#line 8815 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 2957 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yynamespaces.clear();
    }
#line 8823 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 2966 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), false);
      List_Delete((yyvsp[-1].l));
    }
#line 8834 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 2973 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setColor(dimTags, (yyvsp[-3].u), true);
      List_Delete((yyvsp[-1].l));
    }
#line 8845 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 2985 "Gmsh.y" /* yacc.c:1646  */
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
#line 8863 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 3004 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string what = (yyvsp[-1].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[-1].c));
    }
#line 8873 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 3010 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string what = (yyvsp[-1].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[-1].c));
    }
#line 8883 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 3016 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[-1].l));
    }
#line 8894 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 3023 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[-1].l));
    }
#line 8905 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 3030 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[-1].l));
    }
#line 8916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 3037 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[-1].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[-1].l));
    }
#line 8927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 3049 "Gmsh.y" /* yacc.c:1646  */
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
#line 9004 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 3122 "Gmsh.y" /* yacc.c:1646  */
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
#line 9026 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 3140 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[-6].c), "Save") && !strcmp((yyvsp[-5].c), "View")){
	int index = (int)(yyvsp[-3].d);
	if(index >= 0 && index < (int)PView::list.size()){
          std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
	  PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[-6].c));
#endif
      Free((yyvsp[-6].c)); Free((yyvsp[-5].c)); Free((yyvsp[-1].c));
    }
#line 9047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 3157 "Gmsh.y" /* yacc.c:1646  */
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
#line 9066 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 3172 "Gmsh.y" /* yacc.c:1646  */
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
#line 9103 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 3205 "Gmsh.y" /* yacc.c:1646  */
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
#line 9119 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 3217 "Gmsh.y" /* yacc.c:1646  */
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
#line 9147 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 3241 "Gmsh.y" /* yacc.c:1646  */
    {
      Msg::Exit(0);
    }
#line 9155 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 3245 "Gmsh.y" /* yacc.c:1646  */
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
#line 9164 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 3250 "Gmsh.y" /* yacc.c:1646  */
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
#line 9175 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 3257 "Gmsh.y" /* yacc.c:1646  */
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
#line 9184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 3262 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
#line 9198 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 3272 "Gmsh.y" /* yacc.c:1646  */
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[-12].d), (yyvsp[-10].d), (yyvsp[-8].d), (yyvsp[-6].d), (yyvsp[-4].d), (yyvsp[-2].d));
    }
#line 9207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 3277 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
#line 9217 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 3283 "Gmsh.y" /* yacc.c:1646  */
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
#line 9229 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 3291 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh();
    }
#line 9237 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 3295 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->createTopologyFromMesh(1);
    }
#line 9245 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 3299 "Gmsh.y" /* yacc.c:1646  */
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
#line 9258 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 3309 "Gmsh.y" /* yacc.c:1646  */
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
#line 9320 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 3372 "Gmsh.y" /* yacc.c:1646  */
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
#line 9336 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 3388 "Gmsh.y" /* yacc.c:1646  */
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-1].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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
#line 9357 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 3405 "Gmsh.y" /* yacc.c:1646  */
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-5].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[-1].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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
#line 9378 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 3422 "Gmsh.y" /* yacc.c:1646  */
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-1].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[-6].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-6].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[-3].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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
#line 9404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 3444 "Gmsh.y" /* yacc.c:1646  */
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[-5].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[-3].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[-1].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[-8].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[-8].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[-5].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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
#line 9430 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 3466 "Gmsh.y" /* yacc.c:1646  */
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
	  gmshsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    }
#line 9469 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 3501 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 9481 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 3509 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[0].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[0].c));
      skip(NULL, "Return");
      Free((yyvsp[0].c));
    }
#line 9493 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 3517 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
#line 9503 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 3523 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 9514 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 3530 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[-1].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 9525 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 3537 "Gmsh.y" /* yacc.c:1646  */
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
#line 9549 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 3557 "Gmsh.y" /* yacc.c:1646  */
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
#line 9579 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 3583 "Gmsh.y" /* yacc.c:1646  */
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
#line 9595 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 3595 "Gmsh.y" /* yacc.c:1646  */
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
#line 9605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 3606 "Gmsh.y" /* yacc.c:1646  */
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
#line 9627 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 3624 "Gmsh.y" /* yacc.c:1646  */
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
#line 9649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 3642 "Gmsh.y" /* yacc.c:1646  */
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
#line 9671 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 3660 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9681 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 3666 "Gmsh.y" /* yacc.c:1646  */
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
#line 9703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 3684 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9713 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 3690 "Gmsh.y" /* yacc.c:1646  */
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
#line 9737 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 3710 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9747 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 3716 "Gmsh.y" /* yacc.c:1646  */
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
#line 9769 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 3734 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
#line 9779 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 3740 "Gmsh.y" /* yacc.c:1646  */
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
#line 9800 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 3757 "Gmsh.y" /* yacc.c:1646  */
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
#line 9820 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 3773 "Gmsh.y" /* yacc.c:1646  */
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
#line 9841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 3790 "Gmsh.y" /* yacc.c:1646  */
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
#line 9862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 3807 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        double radius = (yyvsp[-1].d);
        std::vector<int> regions, edges;
        ListOfDouble2Vector((yyvsp[-7].l), regions); ListOfDouble2Vector((yyvsp[-4].l), edges);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->fillet
          (regions, edges, radius, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not fillet shapes");
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-4].l));
    }
#line 9886 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 3830 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9893 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 3833 "Gmsh.y" /* yacc.c:1646  */
    {
    }
#line 9900 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 3839 "Gmsh.y" /* yacc.c:1646  */
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
#line 9916 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 3851 "Gmsh.y" /* yacc.c:1646  */
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
#line 9940 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 3871 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.ScaleLast = true;
    }
#line 9948 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 3875 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = true;
    }
#line 9956 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 3879 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.Recombine = (yyvsp[-1].d) ? true : false;
    }
#line 9964 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 3883 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
#line 9972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 3887 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
#line 9980 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 3891 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
#line 9988 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 3895 "Gmsh.y" /* yacc.c:1646  */
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
#line 9996 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 3899 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-3].l), tags);
      int num = (int)(yyvsp[-6].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[-1].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[-3].l));
    }
#line 10009 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 3908 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-4].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[-2].d);
      else if(!strcmp((yyvsp[-4].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[-2].d);
      Free((yyvsp[-4].c));
    }
#line 10021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 3920 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = OCC_Internals::Union; }
#line 10027 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 3921 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = OCC_Internals::Intersection; }
#line 10033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 3922 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = OCC_Internals::Difference; }
#line 10039 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 3923 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = OCC_Internals::Section; }
#line 10045 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 3924 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = OCC_Internals::Fragments; }
#line 10051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 3928 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 10057 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 3929 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 10063 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 3930 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 2; }
#line 10069 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 3931 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].d) ? 1 : 0; }
#line 10075 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 3932 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].d) ? 2 : 0; }
#line 10081 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 3937 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        ListOfShapes2VectorOfPairs((yyvsp[-6].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[-2].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[-8].i), object, tool, out, (yyvsp[-5].i), (yyvsp[-1].i));
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[-6].l));
      List_Delete((yyvsp[-2].l));
    }
#line 10107 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 3959 "Gmsh.y" /* yacc.c:1646  */
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
#line 10127 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 3979 "Gmsh.y" /* yacc.c:1646  */
    {
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        ListOfShapes2VectorOfPairs((yyvsp[-7].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[-3].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          ((int)(yyvsp[-11].d), (OCC_Internals::BooleanOperator)(yyvsp[-13].i), object, tool, out, (yyvsp[-6].i), (yyvsp[-2].i));
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[-7].l));
      List_Delete((yyvsp[-3].l));
    }
#line 10148 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 3999 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
#line 10156 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 4003 "Gmsh.y" /* yacc.c:1646  */
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
#line 10173 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 4018 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = -1; // left
    }
#line 10181 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 4022 "Gmsh.y" /* yacc.c:1646  */
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
#line 10199 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 4038 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
#line 10207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 4042 "Gmsh.y" /* yacc.c:1646  */
    {
     (yyval.l) = (yyvsp[0].l);
   }
#line 10215 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 4047 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = 45;
    }
#line 10223 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 4051 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.i) = (int)(yyvsp[0].d);
    }
#line 10231 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 4057 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
#line 10239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 4061 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 10247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 4068 "Gmsh.y" /* yacc.c:1646  */
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      for(int i = 0; i < List_Nbr((yyvsp[-3].l)); i++){
	double d;
	List_Read((yyvsp[-3].l), i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[-1].d));
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[-1].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[-1].d));
      }
      List_Delete((yyvsp[-3].l));
    }
#line 10268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 4085 "Gmsh.y" /* yacc.c:1646  */
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
#line 10313 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 4126 "Gmsh.y" /* yacc.c:1646  */
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
                  yymsg(0, "Unknown model vertex with tag %d", corners[j]);
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
#line 10361 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 4170 "Gmsh.y" /* yacc.c:1646  */
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
                  yymsg(0, "Unknown model vertex with tag %d", corners[i]);
              }
            }
          }
        }
        List_Delete((yyvsp[-2].l));
      }
      List_Delete((yyvsp[-1].l));
    }
#line 10404 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 4209 "Gmsh.y" /* yacc.c:1646  */
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
#line 10433 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 4234 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-4].l)); i++){
	double d;
	List_Read((yyvsp[-4].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[-1].d);
      }
      List_Delete((yyvsp[-4].l));
    }
#line 10446 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 4243 "Gmsh.y" /* yacc.c:1646  */
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
#line 10480 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 4273 "Gmsh.y" /* yacc.c:1646  */
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
#line 10510 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 4299 "Gmsh.y" /* yacc.c:1646  */
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
#line 10540 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 4326 "Gmsh.y" /* yacc.c:1646  */
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
#line 10575 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 4358 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-3].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
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
#line 10605 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 4385 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-14].l)) != List_Nbr((yyvsp[-10].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
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
#line 10634 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 4411 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-14].l)) != List_Nbr((yyvsp[-10].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
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
#line 10663 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 4437 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-8].l)) != List_Nbr((yyvsp[-4].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
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
#line 10692 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 4463 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-8].l)) != List_Nbr((yyvsp[-4].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
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
#line 10721 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 4489 "Gmsh.y" /* yacc.c:1646  */
    {
      if (List_Nbr((yyvsp[-7].l)) != List_Nbr((yyvsp[-2].l))){
        yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[-2].l)), List_Nbr((yyvsp[-7].l)));
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
#line 10746 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 4510 "Gmsh.y" /* yacc.c:1646  */
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
#line 10761 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 4521 "Gmsh.y" /* yacc.c:1646  */
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
#line 10813 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 4569 "Gmsh.y" /* yacc.c:1646  */
    {
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
#line 10866 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 4618 "Gmsh.y" /* yacc.c:1646  */
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
#line 10882 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 4630 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-1].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[-2].i), tags);
      List_Delete((yyvsp[-1].l));
    }
#line 10892 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 4641 "Gmsh.y" /* yacc.c:1646  */
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
#line 10900 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 4645 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[-1].c), "Geometry"))
        GModel::current()->getGEOInternals()->removeAllDuplicates();
      else if(!strcmp((yyvsp[-1].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[-1].c));
    }
#line 10914 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 4655 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[-2].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[-2].l));
    }
#line 10924 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 4665 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Homology"; }
#line 10930 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 4666 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Cohomology"; }
#line 10936 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 4667 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (char*)"Betti"; }
#line 10942 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 4672 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[-1].c), domain, subdomain, dim);
    }
#line 10952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 4678 "Gmsh.y" /* yacc.c:1646  */
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
#line 10968 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 4690 "Gmsh.y" /* yacc.c:1646  */
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
#line 10990 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 4708 "Gmsh.y" /* yacc.c:1646  */
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
#line 11017 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 4735 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11023 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 4736 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d);           }
#line 11029 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 4737 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = -(yyvsp[0].d);          }
#line 11035 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 4738 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);           }
#line 11041 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 4739 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = !(yyvsp[0].d);          }
#line 11047 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 4740 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) - (yyvsp[0].d);      }
#line 11053 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 4741 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) + (yyvsp[0].d);      }
#line 11059 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 4742 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) * (yyvsp[0].d);      }
#line 11065 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 4744 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!(yyvsp[0].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[-2].d), (yyvsp[0].d));
      else
	(yyval.d) = (yyvsp[-2].d) / (yyvsp[0].d);
    }
#line 11076 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 4750 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) | (int)(yyvsp[0].d); }
#line 11082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 4751 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) & (int)(yyvsp[0].d); }
#line 11088 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 4752 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (int)(yyvsp[-2].d) % (int)(yyvsp[0].d); }
#line 11094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 4753 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = pow((yyvsp[-2].d), (yyvsp[0].d));  }
#line 11100 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 4754 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) < (yyvsp[0].d);      }
#line 11106 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 4755 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) > (yyvsp[0].d);      }
#line 11112 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 4756 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) <= (yyvsp[0].d);     }
#line 11118 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 4757 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) >= (yyvsp[0].d);     }
#line 11124 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 4758 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) == (yyvsp[0].d);     }
#line 11130 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 4759 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) != (yyvsp[0].d);     }
#line 11136 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 4760 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) && (yyvsp[0].d);     }
#line 11142 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 4761 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-2].d) || (yyvsp[0].d);     }
#line 11148 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 4762 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ((int)(yyvsp[-2].d) >> (int)(yyvsp[0].d)); }
#line 11154 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 4763 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ((int)(yyvsp[-2].d) << (int)(yyvsp[0].d)); }
#line 11160 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 4764 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-4].d) ? (yyvsp[-2].d) : (yyvsp[0].d); }
#line 11166 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 4765 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = exp((yyvsp[-1].d));      }
#line 11172 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 4766 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log((yyvsp[-1].d));      }
#line 11178 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 4767 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = log10((yyvsp[-1].d));    }
#line 11184 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 4768 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-1].d));     }
#line 11190 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 4769 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sin((yyvsp[-1].d));      }
#line 11196 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 4770 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = asin((yyvsp[-1].d));     }
#line 11202 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 4771 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cos((yyvsp[-1].d));      }
#line 11208 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 4772 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = acos((yyvsp[-1].d));     }
#line 11214 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 4773 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tan((yyvsp[-1].d));      }
#line 11220 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 4774 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan((yyvsp[-1].d));     }
#line 11226 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 4775 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = atan2((yyvsp[-3].d), (yyvsp[-1].d));}
#line 11232 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 4776 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sinh((yyvsp[-1].d));     }
#line 11238 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 4777 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = cosh((yyvsp[-1].d));     }
#line 11244 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 4778 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = tanh((yyvsp[-1].d));     }
#line 11250 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 4779 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fabs((yyvsp[-1].d));     }
#line 11256 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 4780 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = std::abs((yyvsp[-1].d)); }
#line 11262 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 4781 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d));    }
#line 11268 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 4782 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = ceil((yyvsp[-1].d));     }
#line 11274 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 4783 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = floor((yyvsp[-1].d) + 0.5); }
#line 11280 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 4784 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 11286 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 4785 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = fmod((yyvsp[-3].d), (yyvsp[-1].d)); }
#line 11292 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 4786 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = sqrt((yyvsp[-3].d) * (yyvsp[-3].d) + (yyvsp[-1].d) * (yyvsp[-1].d)); }
#line 11298 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 4787 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[-1].d) * (double)rand() / (double)RAND_MAX; }
#line 11304 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 4796 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 11310 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 4797 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 3.141592653589793; }
#line 11316 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 4798 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (double)ImbricatedTest; }
#line 11322 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 4799 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommRank(); }
#line 11328 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 4800 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Msg::GetCommSize(); }
#line 11334 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 4801 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMajorVersion(); }
#line 11340 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 4802 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshMinorVersion(); }
#line 11346 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 4803 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetGmshPatchVersion(); }
#line 11352 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 4804 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = Cpu(); }
#line 11358 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 4805 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
#line 11364 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 4806 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = TotalRam(); }
#line 11370 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 4811 "Gmsh.y" /* yacc.c:1646  */
    { init_options(); }
#line 11376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 4813 "Gmsh.y" /* yacc.c:1646  */
    {
      std::vector<double> val(1, (yyvsp[-3].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
#line 11386 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 4819 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d); }
#line 11392 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 4821 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11401 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 4826 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11410 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 4831 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[0].c2).char1, (yyvsp[0].c2).char2);
    }
#line 11418 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 4836 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 11426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 4841 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[-3].c), 2, (int)(yyvsp[-1].d));
    }
#line 11434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 4845 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-1].c2).char1, (yyvsp[-1].c2).char2, 1, 0, 0., 1);
    }
#line 11442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 4849 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-3].c2).char1, (yyvsp[-3].c2).char2, (yyvsp[-1].c), 0, 0., 1);
    }
#line 11450 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 4853 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-2].c2).char1, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].d), 2);
    }
#line 11458 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 4857 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].d), 2);
    }
#line 11466 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 4861 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[-5].c2).char1, (yyvsp[-5].c2).char2, 2, (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 11474 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 4865 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c2).char1, (yyvsp[-7].c2).char2, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[-1].d), 2);
    }
#line 11482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 4869 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[-1].c));
    }
#line 11492 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 4875 "Gmsh.y" /* yacc.c:1646  */
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
#line 11511 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 4891 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c));
    }
#line 11519 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 4896 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string struct_namespace((yyvsp[-1].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[-1].c));
    }
#line 11529 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 4902 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
#line 11538 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 4908 "Gmsh.y" /* yacc.c:1646  */
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
#line 11561 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 4927 "Gmsh.y" /* yacc.c:1646  */
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
#line 11585 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 4948 "Gmsh.y" /* yacc.c:1646  */
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
#line 11609 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 4981 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 11617 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 4985 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 11625 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 4990 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 11633 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 4994 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 11641 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 4998 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 11649 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 5002 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 11657 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 5007 "Gmsh.y" /* yacc.c:1646  */
    {
      NumberOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), (yyval.d));
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 11666 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 5012 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-3].c), 0, (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-3].c), 0, (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 5022 "Gmsh.y" /* yacc.c:1646  */
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d)){
	d += (yyvsp[0].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[-6].c), (int)(yyvsp[-4].d), (yyvsp[-1].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[-6].c)); Free((yyvsp[-1].c));
    }
#line 11694 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 5032 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = Msg::GetValue((yyvsp[-3].c), (yyvsp[-1].d));
      Free((yyvsp[-3].c));
    }
#line 11703 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 5037 "Gmsh.y" /* yacc.c:1646  */
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
#line 11718 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 5048 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s((yyvsp[-3].c)), substr((yyvsp[-1].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11731 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 5057 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strlen((yyvsp[-1].c));
      Free((yyvsp[-1].c));
    }
#line 11740 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 5062 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.d) = strcmp((yyvsp[-3].c), (yyvsp[-1].c));
      Free((yyvsp[-3].c)); Free((yyvsp[-1].c));
    }
#line 11749 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 5067 "Gmsh.y" /* yacc.c:1646  */
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
#line 11777 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 5094 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = 0.; }
#line 11783 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 5096 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.d) = (yyvsp[0].d);}
#line 11789 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 5101 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = NULL; }
#line 11795 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 5103 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c);}
#line 11801 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 5108 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string struct_namespace((yyvsp[-1].c2).char1? (yyvsp[-1].c2).char1 : std::string("")),
        struct_name((yyvsp[-1].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
#line 11812 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 5115 "Gmsh.y" /* yacc.c:1646  */
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
#line 11829 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 5131 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[0].c); }
#line 11835 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 5133 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c2).char1 = (yyvsp[-2].c); (yyval.c2).char2 = (yyvsp[0].c); }
#line 11841 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 5138 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); flag_tSTRING_alloc = 1; }
#line 11847 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 5147 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 99; }
#line 11853 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 5149 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = (int)(yyvsp[0].d); }
#line 11859 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 5154 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 11865 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 5156 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 11871 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 5161 "Gmsh.y" /* yacc.c:1646  */
    {
      memcpy((yyval.v), (yyvsp[0].v), 5*sizeof(double));
    }
#line 11879 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 5165 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[0].v)[i];
    }
#line 11887 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 5169 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[0].v)[i];
    }
#line 11895 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 5173 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] - (yyvsp[0].v)[i];
    }
#line 11903 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 5177 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[-2].v)[i] + (yyvsp[0].v)[i];
    }
#line 11911 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 5184 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-9].d);  (yyval.v)[1] = (yyvsp[-7].d);  (yyval.v)[2] = (yyvsp[-5].d);  (yyval.v)[3] = (yyvsp[-3].d); (yyval.v)[4] = (yyvsp[-1].d);
    }
#line 11919 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 5188 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-7].d);  (yyval.v)[1] = (yyvsp[-5].d);  (yyval.v)[2] = (yyvsp[-3].d);  (yyval.v)[3] = (yyvsp[-1].d); (yyval.v)[4] = 1.0;
    }
#line 11927 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 5192 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11935 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 5196 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.v)[0] = (yyvsp[-5].d);  (yyval.v)[1] = (yyvsp[-3].d);  (yyval.v)[2] = (yyvsp[-1].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
#line 11943 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 5203 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11952 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 5208 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].l)));
    }
#line 11960 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 5215 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 11969 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 5220 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 11977 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 5224 "Gmsh.y" /* yacc.c:1646  */
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
#line 11986 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 5229 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 11994 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 5233 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12006 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 5241 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-4].d);
      }
    }
#line 12018 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 5252 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12026 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 5256 "Gmsh.y" /* yacc.c:1646  */
    {
      if(!strcmp((yyvsp[0].c), "*") || !strcmp((yyvsp[0].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
#line 12039 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 5268 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
#line 12051 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 5276 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[-2].d);
      }
    }
#line 12063 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 5284 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[-2].d); ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d <= (yyvsp[0].d)) : (d >= (yyvsp[0].d));
          ((yyvsp[-2].d) < (yyvsp[0].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
#line 12074 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 5291 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[0].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[-4].d), (yyvsp[-2].d), (yyvsp[0].d));
      }
      else
	for(double d = (yyvsp[-4].d); ((yyvsp[0].d) > 0) ? (d <= (yyvsp[-2].d)) : (d >= (yyvsp[-2].d)); d += (yyvsp[0].d))
	  List_Add((yyval.l), &d);
   }
#line 12088 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 5301 "Gmsh.y" /* yacc.c:1646  */
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
          yymsg(0, "Unknown model vertex with tag %d", tag);
        }
      }
      List_Add((yyval.l), &x);
      List_Add((yyval.l), &y);
      List_Add((yyval.l), &z);
    }
#line 12115 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 5324 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[-1].i), (yyval.l));
      Free((yyvsp[0].c));
    }
#line 12125 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 5330 "Gmsh.y" /* yacc.c:1646  */
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
#line 12140 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 5342 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[-15].i), (yyvsp[-11].d), (yyvsp[-9].d), (yyvsp[-7].d), (yyvsp[-5].d), (yyvsp[-3].d), (yyvsp[-1].d), (yyval.l));
    }
#line 12149 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 5347 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12163 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 5357 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12177 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 5367 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[0].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[0].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12191 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 5377 "Gmsh.y" /* yacc.c:1646  */
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
#line 12207 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 5390 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 12215 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 5394 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 12223 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 5400 "Gmsh.y" /* yacc.c:1646  */
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
#line 12239 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 5412 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12247 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 5416 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12255 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 5420 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-2].l);
    }
#line 12263 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 5424 "Gmsh.y" /* yacc.c:1646  */
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
#line 12285 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 5442 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = (yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1);
	List_Add((yyval.l), &d);
      }
    }
#line 12297 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 5450 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[-1].d); i++) {
	double d = pow(10,(yyvsp[-5].d) + ((yyvsp[-3].d)-(yyvsp[-5].d))*(double)i/((yyvsp[-1].d)-1));
	List_Add((yyval.l), &d);
      }
    }
#line 12309 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 5458 "Gmsh.y" /* yacc.c:1646  */
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
#line 12342 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 5487 "Gmsh.y" /* yacc.c:1646  */
    {
      double x0 = (yyvsp[-11].d), x1 = (yyvsp[-9].d), y0 = (yyvsp[-7].d), y1 = (yyvsp[-5].d), ys = (yyvsp[-3].d);
      int N = (int)(yyvsp[-1].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
#line 12356 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 5497 "Gmsh.y" /* yacc.c:1646  */
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
#line 12376 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 5513 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[-1].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[-1].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12388 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 5524 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12397 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 5529 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[0].l);
    }
#line 12405 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 5533 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].d)));
    }
#line 12413 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 5537 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	double d;
	List_Read((yyvsp[0].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[0].l));
    }
#line 12426 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 5549 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-7].d), (int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
    }
#line 12434 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 5553 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[-5].d), (int)(yyvsp[-3].d), (int)(yyvsp[-1].d), 255);
    }
#line 12442 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 5565 "Gmsh.y" /* yacc.c:1646  */
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
#line 12463 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 5582 "Gmsh.y" /* yacc.c:1646  */
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[-4].c), 0, (yyvsp[0].c), val);
      (yyval.u) = val;
      Free((yyvsp[-4].c)); Free((yyvsp[0].c));
    }
#line 12474 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 5592 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = (yyvsp[-1].l);
    }
#line 12482 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 5596 "Gmsh.y" /* yacc.c:1646  */
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
#line 12498 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 5611 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 12507 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 5616 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].u)));
    }
#line 12515 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 5623 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12523 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 5627 "Gmsh.y" /* yacc.c:1646  */
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[0].c));
    }
#line 12532 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 5632 "Gmsh.y" /* yacc.c:1646  */
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
#line 12550 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 5646 "Gmsh.y" /* yacc.c:1646  */
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
#line 12568 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 5663 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12576 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 5667 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c), (yyvsp[-2].c), (yyvsp[0].c));
    }
#line 12584 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 5672 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12592 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 5676 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-7].c), (yyvsp[-5].c), (yyvsp[-3].c), (int)(yyvsp[-1].d));
    }
#line 12600 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 5681 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[-5].c), (int)(yyvsp[-3].d), (yyvsp[0].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c)); Free((yyvsp[0].c));
    }
#line 12612 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 5689 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 12622 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 5695 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 12632 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 5701 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 12642 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 5707 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[-1].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
#line 12652 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 5716 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[0].c);
    }
#line 12660 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 5720 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12668 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 5724 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
#line 12680 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 5732 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
#line 12690 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 5738 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
#line 12700 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 5744 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
#line 12708 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 5748 "Gmsh.y" /* yacc.c:1646  */
    {
      const char *env = GetEnvironmentVar((yyvsp[-1].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[-1].c));
    }
#line 12720 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 5756 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12732 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 5764 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-1].c));
    }
#line 12743 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 5771 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string s = Msg::GetOnelabString((yyvsp[-3].c), (yyvsp[-1].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[-3].c));
      Free((yyvsp[-1].c));
    }
#line 12755 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 5781 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[-2].c2).char2, 1, 0, (yyvsp[-1].c), 2);
    }
#line 12763 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 5786 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[-4].c2).char1, (yyvsp[-4].c2).char2, (yyvsp[-2].c), 0, (yyvsp[-1].c), 2);
    }
#line 12771 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 5791 "Gmsh.y" /* yacc.c:1646  */
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
#line 12790 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 5806 "Gmsh.y" /* yacc.c:1646  */
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
#line 12808 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 5820 "Gmsh.y" /* yacc.c:1646  */
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
#line 12826 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 5834 "Gmsh.y" /* yacc.c:1646  */
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
#line 12842 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 553:
#line 5846 "Gmsh.y" /* yacc.c:1646  */
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
#line 12862 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 5862 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = toupper((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12875 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 555:
#line 5871 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12888 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 556:
#line 5880 "Gmsh.y" /* yacc.c:1646  */
    {
      int i = 0;
      while ((yyvsp[-1].c)[i]) {
        if (i > 0 && (yyvsp[-1].c)[i-1] != '_')
          (yyvsp[-1].c)[i] = tolower((yyvsp[-1].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12902 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 557:
#line 5890 "Gmsh.y" /* yacc.c:1646  */
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
#line 12917 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 558:
#line 5901 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string in = (yyvsp[-5].c);
      std::string out = in.substr((int)(yyvsp[-3].d), (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-5].c));
    }
#line 12929 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 559:
#line 5909 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string in = (yyvsp[-3].c);
      std::string out = in.substr((int)(yyvsp[-1].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[-3].c));
    }
#line 12941 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 560:
#line 5917 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.c) = (yyvsp[-1].c);
    }
#line 12949 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 561:
#line 5921 "Gmsh.y" /* yacc.c:1646  */
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
#line 12972 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 562:
#line 5940 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 12983 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 563:
#line 5947 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
#line 12993 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 564:
#line 5953 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = SplitFileName((yyvsp[-1].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13004 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 565:
#line 5960 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string tmp = GetAbsolutePath((yyvsp[-1].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[-1].c));
    }
#line 13015 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 566:
#line 5967 "Gmsh.y" /* yacc.c:1646  */
    { init_options(); }
#line 13021 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 567:
#line 5969 "Gmsh.y" /* yacc.c:1646  */
    {
      std::string val((yyvsp[-3].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[-3].c));
    }
#line 13033 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 568:
#line 5977 "Gmsh.y" /* yacc.c:1646  */
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
#line 13058 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 569:
#line 6001 "Gmsh.y" /* yacc.c:1646  */
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[0].d); }
#line 13064 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 570:
#line 6003 "Gmsh.y" /* yacc.c:1646  */
    { struct_namespace = (yyvsp[-3].c); Free((yyvsp[-3].c)); (yyval.d) = (yyvsp[0].d); }
#line 13070 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 571:
#line 6009 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 13076 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 572:
#line 6014 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13082 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 573:
#line 6016 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13088 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 574:
#line 6021 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[-1].l); }
#line 13094 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 575:
#line 6026 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 13103 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 576:
#line 6031 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.l) = (yyvsp[0].l); }
#line 13109 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 577:
#line 6033 "Gmsh.y" /* yacc.c:1646  */
    {
      List_Add((yyval.l), &((yyvsp[0].c)));
    }
#line 13117 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 578:
#line 6037 "Gmsh.y" /* yacc.c:1646  */
    {
      for(int i = 0; i < List_Nbr((yyvsp[0].l)); i++){
	char* c;
	List_Read((yyvsp[0].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[0].l));
    }
#line 13130 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 579:
#line 6049 "Gmsh.y" /* yacc.c:1646  */
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
#line 13148 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 580:
#line 6063 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13156 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 581:
#line 6067 "Gmsh.y" /* yacc.c:1646  */
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[-6].c), (yyvsp[-4].c), (yyvsp[-2].c));
    }
#line 13164 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 582:
#line 6074 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-4].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-4].c));
    }
#line 13176 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 583:
#line 6082 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-4].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[-4].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[-4].c));
    }
#line 13188 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 584:
#line 6090 "Gmsh.y" /* yacc.c:1646  */
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[-1].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[-5].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[-5].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[-5].c));
    }
#line 13200 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 585:
#line 6101 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 13206 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 586:
#line 6103 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[0].c); }
#line 13212 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;

  case 587:
#line 6106 "Gmsh.y" /* yacc.c:1646  */
    { (yyval.c) = (yyvsp[-1].c); }
#line 13218 "Gmsh.tab.cpp" /* yacc.c:1646  */
    break;


#line 13222 "Gmsh.tab.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
#line 6109 "Gmsh.y" /* yacc.c:1906  */


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
    Msg::Error("Could not find edge slave %d or master %d for periodic copy",
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
      yymsg(0, "Unknown model face with tag %d", tag2);
      return;
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gf->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model vertex %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gf->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model edge %d", tags[i]);
      }
    }
  }
  else if(dim2 == 3){
    GRegion *gr = GModel::current()->getRegionByTag(tag2);
    if(!gr){
      yymsg(0, "Unknown model region with tag %d", tag2);
      return;
    }
    for(unsigned int i = 0; i < tags.size(); i++){
      if(dim == 0){
        GVertex *gv = GModel::current()->getVertexByTag(tags[i]);
        if(gv)
          gr->addEmbeddedVertex(gv);
        else
          yymsg(0, "Unknown model vertex with tag %d", tags[i]);
      }
      else if(dim == 1){
        GEdge *ge = GModel::current()->getEdgeByTag(tags[i]);
        if(ge)
          gr->addEmbeddedEdge(ge);
        else
          yymsg(0, "Unknown model edge with tag %d", tags[i]);
      }
      else if(dim == 2){
        GFace *gf = GModel::current()->getFaceByTag(tags[i]);
        if(gf)
          gr->addEmbeddedFace(gf);
        else
          yymsg(0, "Unknown model face with tag %d", tags[i]);
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
        if((int)s.value.size() < index + 1){
          out = val_default;
          if (type_treat == 0) yymsg(0, "Uninitialized variable '%s[%d]'", c2, index);
        }
        else
          out = s.value[index];
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
