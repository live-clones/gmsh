/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

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
#define yylval          gmsh_yylval
#define yychar          gmsh_yychar
#define yydebug         gmsh_yydebug
#define yynerrs         gmsh_yynerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "Gmsh.y"

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


/* Line 371 of yacc.c  */
#line 238 "Gmsh.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
     tBox = 355,
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
     tAFFECTDIVIDE = 467,
     tAFFECTTIMES = 468,
     tAFFECTMINUS = 469,
     tAFFECTPLUS = 470,
     tOR = 471,
     tAND = 472,
     tNOTEQUAL = 473,
     tEQUAL = 474,
     tGREATERGREATER = 475,
     tLESSLESS = 476,
     tGREATEROREQUAL = 477,
     tLESSOREQUAL = 478,
     UNARYPREC = 479,
     tMINUSMINUS = 480,
     tPLUSPLUS = 481
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 164 "Gmsh.y"

  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;


/* Line 387 of yacc.c  */
#line 519 "Gmsh.tab.cpp"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 547 "Gmsh.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   14793

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  589
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2072

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   481

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   246,     2,   231,   233,     2,
     239,   240,   229,   227,   248,   228,   245,   230,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     221,     2,   222,   216,     2,     2,     2,     2,     2,     2,
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
     215,   217,   218,   219,   220,   223,   224,   225,   226,   235,
     236,   237
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      24,    26,    28,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    54,    56,    58,    60,    66,
      72,    80,    88,    96,   106,   113,   120,   127,   136,   137,
     140,   143,   146,   149,   152,   154,   158,   160,   164,   165,
     166,   177,   179,   183,   184,   198,   200,   204,   205,   221,
     230,   245,   246,   253,   255,   257,   259,   261,   263,   265,
     267,   269,   271,   273,   275,   281,   287,   290,   298,   306,
     311,   315,   322,   332,   340,   347,   355,   362,   367,   376,
     386,   396,   403,   413,   420,   430,   436,   445,   454,   466,
     473,   483,   489,   497,   505,   513,   523,   533,   545,   553,
     563,   573,   574,   576,   577,   581,   587,   588,   598,   599,
     611,   617,   618,   628,   629,   633,   637,   643,   649,   650,
     653,   654,   656,   658,   662,   665,   667,   672,   675,   678,
     679,   682,   684,   688,   691,   694,   697,   700,   703,   705,
     707,   711,   712,   718,   719,   722,   730,   738,   746,   755,
     764,   772,   780,   792,   800,   809,   818,   827,   837,   841,
     846,   857,   865,   873,   881,   889,   897,   905,   913,   921,
     929,   937,   946,   954,   962,   971,   980,   993,   994,  1004,
    1006,  1008,  1010,  1012,  1017,  1019,  1021,  1023,  1028,  1030,
    1032,  1037,  1039,  1041,  1043,  1048,  1054,  1066,  1072,  1082,
    1092,  1097,  1107,  1117,  1119,  1121,  1122,  1125,  1132,  1141,
    1152,  1167,  1184,  1197,  1212,  1227,  1242,  1257,  1266,  1275,
    1282,  1287,  1293,  1300,  1307,  1311,  1316,  1320,  1326,  1333,
    1339,  1343,  1347,  1352,  1358,  1363,  1369,  1373,  1379,  1387,
    1395,  1399,  1407,  1411,  1414,  1417,  1420,  1423,  1426,  1442,
    1445,  1448,  1451,  1454,  1457,  1474,  1486,  1493,  1502,  1511,
    1522,  1524,  1527,  1530,  1532,  1536,  1540,  1545,  1550,  1552,
    1554,  1560,  1572,  1586,  1587,  1595,  1596,  1610,  1611,  1627,
    1628,  1635,  1645,  1648,  1652,  1663,  1665,  1668,  1674,  1682,
    1685,  1688,  1692,  1695,  1699,  1702,  1706,  1716,  1723,  1725,
    1727,  1729,  1731,  1733,  1734,  1737,  1741,  1745,  1750,  1760,
    1765,  1780,  1781,  1785,  1786,  1788,  1789,  1792,  1793,  1796,
    1797,  1800,  1807,  1815,  1822,  1828,  1832,  1841,  1847,  1852,
    1859,  1871,  1883,  1902,  1921,  1934,  1947,  1960,  1971,  1976,
    1981,  1986,  1991,  1994,  1998,  2005,  2007,  2009,  2011,  2014,
    2020,  2028,  2039,  2041,  2045,  2048,  2051,  2054,  2058,  2062,
    2066,  2070,  2074,  2078,  2082,  2086,  2090,  2094,  2098,  2102,
    2106,  2110,  2114,  2118,  2122,  2126,  2132,  2137,  2142,  2147,
    2152,  2157,  2162,  2167,  2172,  2177,  2182,  2189,  2194,  2199,
    2204,  2209,  2214,  2219,  2224,  2229,  2236,  2243,  2250,  2255,
    2257,  2259,  2261,  2263,  2265,  2267,  2269,  2271,  2273,  2275,
    2277,  2278,  2285,  2287,  2292,  2299,  2301,  2306,  2311,  2316,
    2323,  2329,  2337,  2346,  2357,  2362,  2367,  2374,  2379,  2383,
    2386,  2392,  2398,  2402,  2408,  2415,  2424,  2431,  2440,  2447,
    2452,  2460,  2467,  2474,  2481,  2486,  2493,  2498,  2499,  2502,
    2503,  2506,  2507,  2515,  2517,  2521,  2523,  2525,  2528,  2529,
    2533,  2535,  2538,  2541,  2545,  2549,  2561,  2571,  2579,  2587,
    2589,  2593,  2595,  2597,  2600,  2604,  2609,  2615,  2617,  2619,
    2622,  2626,  2630,  2636,  2641,  2644,  2648,  2665,  2667,  2669,
    2671,  2675,  2681,  2689,  2694,  2699,  2704,  2711,  2718,  2727,
    2736,  2741,  2756,  2761,  2766,  2768,  2770,  2774,  2778,  2788,
    2796,  2798,  2804,  2808,  2815,  2817,  2821,  2823,  2825,  2830,
    2835,  2839,  2845,  2852,  2861,  2868,  2874,  2880,  2886,  2892,
    2894,  2899,  2901,  2903,  2905,  2907,  2912,  2919,  2924,  2931,
    2937,  2945,  2950,  2955,  2960,  2969,  2974,  2979,  2984,  2989,
    2998,  3007,  3014,  3019,  3026,  3031,  3033,  3038,  3043,  3044,
    3051,  3056,  3059,  3064,  3069,  3071,  3073,  3077,  3079,  3081,
    3085,  3089,  3093,  3099,  3107,  3113,  3119,  3128,  3130,  3132
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     250,     0,    -1,   251,    -1,     1,     6,    -1,    -1,   251,
     252,    -1,   254,    -1,   255,    -1,   275,    -1,   118,   239,
     351,   240,     6,    -1,   293,    -1,   299,    -1,   303,    -1,
     304,    -1,   305,    -1,   306,    -1,   310,    -1,   319,    -1,
     320,    -1,   326,    -1,   327,    -1,   309,    -1,   308,    -1,
     307,    -1,   302,    -1,   329,    -1,   222,    -1,   223,    -1,
      44,   239,   351,   240,     6,    -1,    45,   239,   351,   240,
       6,    -1,    44,   239,   351,   240,   253,   351,     6,    -1,
      44,   239,   351,   248,   347,   240,     6,    -1,    45,   239,
     351,   248,   347,   240,     6,    -1,    44,   239,   351,   248,
     347,   240,   253,   351,     6,    -1,   361,   351,   243,   256,
     244,     6,    -1,   157,     4,   241,   330,   242,     6,    -1,
     158,     4,   241,   330,   242,     6,    -1,   159,     4,   241,
     330,   248,   330,   242,     6,    -1,    -1,   256,   259,    -1,
     256,   263,    -1,   256,   266,    -1,   256,   268,    -1,   256,
     269,    -1,   330,    -1,   257,   248,   330,    -1,   330,    -1,
     258,   248,   330,    -1,    -1,    -1,     4,   260,   239,   257,
     240,   261,   243,   258,   244,     6,    -1,   351,    -1,   262,
     248,   351,    -1,    -1,   164,   239,   330,   248,   330,   248,
     330,   240,   264,   243,   262,   244,     6,    -1,   351,    -1,
     265,   248,   351,    -1,    -1,   165,   239,   330,   248,   330,
     248,   330,   248,   330,   240,   267,   243,   265,   244,     6,
      -1,   166,   243,   343,   244,   243,   343,   244,     6,    -1,
     166,   243,   343,   244,   243,   343,   244,   243,   343,   244,
     243,   343,   244,     6,    -1,    -1,   167,   270,   243,   258,
     244,     6,    -1,     7,    -1,   215,    -1,   214,    -1,   213,
      -1,   212,    -1,   237,    -1,   236,    -1,   239,    -1,   241,
      -1,   240,    -1,   242,    -1,    81,   241,   277,   242,     6,
      -1,    82,   241,   281,   242,     6,    -1,   335,     6,    -1,
      89,   273,   352,   248,   330,   274,     6,    -1,    90,   273,
     361,   248,   352,   274,     6,    -1,   361,   271,   344,     6,
      -1,   361,   272,     6,    -1,   361,   273,   274,   271,   344,
       6,    -1,   361,   273,   243,   347,   244,   274,   271,   344,
       6,    -1,   361,   241,   330,   242,   271,   330,     6,    -1,
     361,   241,   330,   242,   272,     6,    -1,   361,   239,   330,
     240,   271,   330,     6,    -1,   361,   239,   330,   240,   272,
       6,    -1,   361,     7,   352,     6,    -1,   361,   273,   274,
       7,    46,   273,   274,     6,    -1,   361,   273,   274,     7,
      46,   273,   356,   274,     6,    -1,   361,   273,   274,   215,
      46,   273,   356,   274,     6,    -1,   361,   245,     4,     7,
     352,     6,    -1,   361,   241,   330,   242,   245,     4,     7,
     352,     6,    -1,   361,   245,     4,   271,   330,     6,    -1,
     361,   241,   330,   242,   245,     4,   271,   330,     6,    -1,
     361,   245,     4,   272,     6,    -1,   361,   241,   330,   242,
     245,     4,   272,     6,    -1,   361,   245,   174,   245,     4,
       7,   348,     6,    -1,   361,   241,   330,   242,   245,   174,
     245,     4,     7,   348,     6,    -1,   361,   245,   175,     7,
     349,     6,    -1,   361,   241,   330,   242,   245,   175,     7,
     349,     6,    -1,   361,   185,     7,   330,     6,    -1,   185,
     241,   330,   242,     7,     4,     6,    -1,   185,   241,   330,
     242,     7,   100,     6,    -1,   185,   241,   330,   242,     7,
     101,     6,    -1,   185,   241,   330,   242,   245,     4,     7,
     330,     6,    -1,   185,   241,   330,   242,   245,     4,     7,
     352,     6,    -1,   185,   241,   330,   242,   245,     4,     7,
     243,   347,   244,     6,    -1,   185,   241,   330,   242,   245,
       4,     6,    -1,   130,   239,     4,   240,   245,     4,     7,
     330,     6,    -1,   130,   239,     4,   240,   245,     4,     7,
     352,     6,    -1,    -1,   248,    -1,    -1,   277,   276,   361,
      -1,   277,   276,   361,     7,   330,    -1,    -1,   277,   276,
     361,     7,   243,   344,   278,   283,   244,    -1,    -1,   277,
     276,   361,   273,   274,     7,   243,   344,   279,   283,   244,
      -1,   277,   276,   361,     7,   352,    -1,    -1,   277,   276,
     361,     7,   243,   352,   280,   287,   244,    -1,    -1,   281,
     276,   351,    -1,   330,     7,   352,    -1,   282,   248,   330,
       7,   352,    -1,   346,     7,   361,   239,   240,    -1,    -1,
     248,   285,    -1,    -1,   285,    -1,   286,    -1,   285,   248,
     286,    -1,     4,   344,    -1,     4,    -1,     4,   243,   282,
     244,    -1,     4,   352,    -1,     4,   355,    -1,    -1,   248,
     288,    -1,   289,    -1,   288,   248,   289,    -1,     4,   330,
      -1,     4,   352,    -1,   189,   352,    -1,     4,   357,    -1,
       4,   355,    -1,   330,    -1,   352,    -1,   352,   248,   330,
      -1,    -1,   177,    95,   243,   330,   244,    -1,    -1,   123,
     341,    -1,    91,   239,   330,   240,     7,   341,     6,    -1,
      94,   239,   330,   240,     7,   344,     6,    -1,    98,   239,
     330,   240,     7,   344,     6,    -1,    92,   239,   330,   240,
       7,   344,   292,     6,    -1,    93,   239,   330,   240,     7,
     344,   292,     6,    -1,   169,   239,   330,   240,     7,   344,
       6,    -1,   170,   239,   330,   240,     7,   344,     6,    -1,
     171,   239,   330,   240,     7,   344,   173,   344,   172,   330,
       6,    -1,   109,   239,   330,   240,     7,   344,     6,    -1,
      94,     4,   239,   330,   240,     7,   344,     6,    -1,   123,
      97,   239,   330,   240,     7,   344,     6,    -1,    97,   239,
     330,   240,     7,   344,   291,     6,    -1,   124,    97,   239,
     330,   240,     7,   344,   291,     6,    -1,    13,    14,     6,
      -1,    14,    97,   330,     6,    -1,   113,    97,   239,   330,
     240,     7,     5,     5,     5,     6,    -1,    95,   239,   330,
     240,     7,   344,     6,    -1,    96,   239,   330,   240,     7,
     344,     6,    -1,   100,   239,   330,   240,     7,   344,     6,
      -1,   103,   239,   330,   240,     7,   344,     6,    -1,   107,
     239,   330,   240,     7,   344,     6,    -1,   108,   239,   330,
     240,     7,   344,     6,    -1,   101,   239,   330,   240,     7,
     344,     6,    -1,   102,   239,   330,   240,     7,   344,     6,
      -1,   120,   239,   330,   240,     7,   344,     6,    -1,   145,
     239,   330,   240,     7,   344,     6,    -1,    97,     4,   239,
     330,   240,     7,   344,     6,    -1,    99,   239,   330,   240,
       7,   344,     6,    -1,   119,   239,   330,   240,     7,   344,
       6,    -1,   124,   119,   239,   330,   240,     7,   344,     6,
      -1,   127,   296,   239,   330,   240,     7,   344,     6,    -1,
     127,   296,   239,   330,   240,     7,   344,     4,   243,   343,
     244,     6,    -1,    -1,   126,   295,   294,   239,   290,   240,
     271,   344,     6,    -1,    91,    -1,    94,    -1,    97,    -1,
      99,    -1,   110,   243,   330,   244,    -1,    94,    -1,    97,
      -1,    99,    -1,   110,   243,   330,   244,    -1,    94,    -1,
      97,    -1,   110,   243,   330,   244,    -1,    91,    -1,    94,
      -1,    97,    -1,   110,   243,   330,   244,    -1,   134,   341,
     243,   300,   244,    -1,   133,   243,   341,   248,   341,   248,
     330,   244,   243,   300,   244,    -1,   135,   341,   243,   300,
     244,    -1,   136,   243,   341,   248,   330,   244,   243,   300,
     244,    -1,   136,   243,   341,   248,   341,   244,   243,   300,
     244,    -1,     4,   243,   300,   244,    -1,   151,    94,   243,
     347,   244,    97,   243,   330,   244,    -1,   148,    94,   239,
     330,   240,   243,   347,   244,     6,    -1,   301,    -1,   299,
      -1,    -1,   301,   293,    -1,   301,   295,   243,   347,   244,
       6,    -1,   138,   123,   239,   330,   240,     7,   344,     6,
      -1,   138,    91,   239,   330,   240,     7,   243,   343,   244,
       6,    -1,   138,   123,   239,   330,   240,     7,   243,   341,
     248,   341,   248,   347,   244,     6,    -1,   138,   123,   239,
     330,   240,     7,   243,   341,   248,   341,   248,   341,   248,
     347,   244,     6,    -1,   138,    95,   239,   330,   240,     7,
     243,   341,   248,   347,   244,     6,    -1,   138,   101,   239,
     330,   240,     7,   243,   341,   248,   341,   248,   347,   244,
       6,    -1,   138,   102,   239,   330,   240,     7,   243,   341,
     248,   341,   248,   347,   244,     6,    -1,   138,   104,   239,
     330,   240,     7,   243,   341,   248,   341,   248,   347,   244,
       6,    -1,   138,   105,   239,   330,   240,     7,   243,   341,
     248,   341,   248,   347,   244,     6,    -1,   138,     4,   239,
     330,   240,     7,   344,     6,    -1,   138,     4,   239,   330,
     240,     7,     5,     6,    -1,   138,     4,   243,   330,   244,
       6,    -1,   149,   243,   301,   244,    -1,   132,   149,   243,
     301,   244,    -1,   149,   185,   241,   330,   242,     6,    -1,
     149,     4,   241,   330,   242,     6,    -1,   149,   361,     6,
      -1,   149,     4,     4,     6,    -1,   149,    84,     6,    -1,
     174,   348,   243,   301,   244,    -1,   132,   174,   348,   243,
     301,   244,    -1,   209,   330,   243,   301,   244,    -1,   190,
       5,     6,    -1,   191,     5,     6,    -1,   190,   243,   301,
     244,    -1,   132,   190,   243,   301,   244,    -1,   191,   243,
     301,   244,    -1,   132,   191,   243,   301,   244,    -1,   361,
     352,     6,    -1,    73,   239,   358,   240,     6,    -1,   361,
     361,   241,   330,   242,   351,     6,    -1,   361,   361,   361,
     241,   330,   242,     6,    -1,   361,   330,     6,    -1,   130,
     239,     4,   240,   245,     4,     6,    -1,   168,     4,     6,
      -1,   183,     6,    -1,   184,     6,    -1,    70,     6,    -1,
      71,     6,    -1,    64,     6,    -1,    64,   243,   330,   248,
     330,   248,   330,   248,   330,   248,   330,   248,   330,   244,
       6,    -1,    65,     6,    -1,    66,     6,    -1,    78,     6,
      -1,    79,     6,    -1,   115,     6,    -1,   116,   243,   347,
     244,   243,   347,   244,   243,   343,   244,   243,   330,   248,
     330,   244,     6,    -1,   188,   239,   243,   347,   244,   248,
     352,   248,   352,   240,     6,    -1,   176,   239,   330,     8,
     330,   240,    -1,   176,   239,   330,     8,   330,     8,   330,
     240,    -1,   176,     4,   177,   243,   330,     8,   330,   244,
      -1,   176,     4,   177,   243,   330,     8,   330,     8,   330,
     244,    -1,   178,    -1,   189,     4,    -1,   189,   352,    -1,
     186,    -1,   187,   361,     6,    -1,   187,   352,     6,    -1,
     179,   239,   330,   240,    -1,   180,   239,   330,   240,    -1,
     181,    -1,   182,    -1,   137,   341,   243,   301,   244,    -1,
     137,   243,   341,   248,   341,   248,   330,   244,   243,   301,
     244,    -1,   137,   243,   341,   248,   341,   248,   341,   248,
     330,   244,   243,   301,   244,    -1,    -1,   137,   341,   243,
     301,   311,   315,   244,    -1,    -1,   137,   243,   341,   248,
     341,   248,   330,   244,   243,   301,   312,   315,   244,    -1,
      -1,   137,   243,   341,   248,   341,   248,   341,   248,   330,
     244,   243,   301,   313,   315,   244,    -1,    -1,   137,   243,
     301,   314,   315,   244,    -1,   137,   243,   301,   244,   129,
     109,   243,   330,   244,    -1,   119,   344,    -1,   124,   119,
     344,    -1,   121,   243,   347,   244,   243,   347,   244,   243,
     330,   244,    -1,   316,    -1,   315,   316,    -1,   154,   243,
     330,   244,     6,    -1,   154,   243,   344,   248,   344,   244,
       6,    -1,   155,     6,    -1,   146,     6,    -1,   146,   330,
       6,    -1,   160,     6,    -1,   160,   162,     6,    -1,   161,
       6,    -1,   161,   162,     6,    -1,   156,   239,   330,   240,
       7,   344,   129,   330,     6,    -1,   129,     4,   241,   330,
     242,     6,    -1,   140,    -1,   141,    -1,   142,    -1,   143,
      -1,   144,    -1,    -1,   149,     6,    -1,   132,   149,     6,
      -1,   149,   330,     6,    -1,   132,   149,   330,     6,    -1,
     317,   243,   301,   318,   244,   243,   301,   318,   244,    -1,
     106,   239,   351,   240,    -1,   317,   239,   330,   240,     7,
     243,   301,   318,   244,   243,   301,   318,   244,     6,    -1,
      -1,   129,     4,   330,    -1,    -1,     4,    -1,    -1,     7,
     344,    -1,    -1,     7,   330,    -1,    -1,   139,   344,    -1,
     111,   112,   344,     7,   330,     6,    -1,   125,    94,   345,
       7,   330,   321,     6,    -1,   125,    97,   345,   323,   322,
       6,    -1,   125,    99,   345,   323,     6,    -1,   163,   345,
       6,    -1,   152,    97,   243,   347,   244,     7,   330,     6,
      -1,   146,    97,   345,   324,     6,    -1,   146,    99,   345,
       6,    -1,   147,    97,   345,     7,   330,     6,    -1,   128,
      94,   243,   347,   244,     7,   243,   347,   244,   325,     6,
      -1,   128,    97,   243,   347,   244,     7,   243,   347,   244,
     325,     6,    -1,   128,    94,   243,   347,   244,     7,   243,
     347,   244,   133,   243,   341,   248,   341,   248,   330,   244,
       6,    -1,   128,    97,   243,   347,   244,     7,   243,   347,
     244,   133,   243,   341,   248,   341,   248,   330,   244,     6,
      -1,   128,    94,   243,   347,   244,     7,   243,   347,   244,
     134,   341,     6,    -1,   128,    97,   243,   347,   244,     7,
     243,   347,   244,   134,   341,     6,    -1,   128,    97,   330,
     243,   347,   244,     7,   330,   243,   347,   244,     6,    -1,
     295,   243,   347,   244,   177,   295,   243,   330,   244,     6,
      -1,   153,   297,   345,     6,    -1,   117,   298,   345,     6,
      -1,   131,    94,   344,     6,    -1,   127,   296,   344,     6,
      -1,   150,     6,    -1,   150,     4,     6,    -1,   150,    91,
     243,   347,   244,     6,    -1,   198,    -1,   199,    -1,   200,
      -1,   328,     6,    -1,   328,   243,   344,   244,     6,    -1,
     328,   243,   344,   248,   344,   244,     6,    -1,   328,   239,
     344,   240,   243,   344,   248,   344,   244,     6,    -1,   331,
      -1,   239,   330,   240,    -1,   228,   330,    -1,   227,   330,
      -1,   234,   330,    -1,   330,   228,   330,    -1,   330,   227,
     330,    -1,   330,   229,   330,    -1,   330,   230,   330,    -1,
     330,   232,   330,    -1,   330,   233,   330,    -1,   330,   231,
     330,    -1,   330,   238,   330,    -1,   330,   221,   330,    -1,
     330,   222,   330,    -1,   330,   226,   330,    -1,   330,   225,
     330,    -1,   330,   220,   330,    -1,   330,   219,   330,    -1,
     330,   218,   330,    -1,   330,   217,   330,    -1,   330,   223,
     330,    -1,   330,   224,   330,    -1,   330,   216,   330,     8,
     330,    -1,    16,   273,   330,   274,    -1,    17,   273,   330,
     274,    -1,    18,   273,   330,   274,    -1,    19,   273,   330,
     274,    -1,    20,   273,   330,   274,    -1,    21,   273,   330,
     274,    -1,    22,   273,   330,   274,    -1,    23,   273,   330,
     274,    -1,    24,   273,   330,   274,    -1,    26,   273,   330,
     274,    -1,    27,   273,   330,   248,   330,   274,    -1,    28,
     273,   330,   274,    -1,    29,   273,   330,   274,    -1,    30,
     273,   330,   274,    -1,    31,   273,   330,   274,    -1,    32,
     273,   330,   274,    -1,    33,   273,   330,   274,    -1,    34,
     273,   330,   274,    -1,    35,   273,   330,   274,    -1,    36,
     273,   330,   248,   330,   274,    -1,    37,   273,   330,   248,
     330,   274,    -1,    38,   273,   330,   248,   330,   274,    -1,
      25,   273,   330,   274,    -1,     3,    -1,    10,    -1,    15,
      -1,    11,    -1,    12,    -1,   205,    -1,   206,    -1,   207,
      -1,    75,    -1,    76,    -1,    77,    -1,    -1,    83,   273,
     330,   332,   283,   274,    -1,   335,    -1,   196,   273,   351,
     274,    -1,   196,   273,   351,   248,   330,   274,    -1,   337,
      -1,   361,   241,   330,   242,    -1,   361,   239,   330,   240,
      -1,   201,   239,   337,   240,    -1,   201,   239,   337,   245,
     338,   240,    -1,   203,   239,   337,   333,   240,    -1,   203,
     239,   337,   245,   338,   333,   240,    -1,   203,   239,   337,
     273,   330,   274,   333,   240,    -1,   203,   239,   337,   245,
     338,   273,   330,   274,   333,   240,    -1,   202,   239,   352,
     240,    -1,   246,   361,   273,   274,    -1,   246,   337,   245,
     338,   273,   274,    -1,    86,   273,   361,   274,    -1,    86,
     273,   274,    -1,   361,   272,    -1,   361,   241,   330,   242,
     272,    -1,   361,   239,   330,   240,   272,    -1,   361,   245,
     338,    -1,   361,     9,   361,   245,   338,    -1,   361,   245,
     338,   239,   330,   240,    -1,   361,     9,   361,   245,   338,
     239,   330,   240,    -1,   361,   245,   338,   241,   330,   242,
      -1,   361,     9,   361,   245,   338,   241,   330,   242,    -1,
     361,   241,   330,   242,   245,     4,    -1,   361,   245,     4,
     272,    -1,   361,   241,   330,   242,   245,     4,   272,    -1,
     192,   239,   351,   248,   330,   240,    -1,    56,   239,   344,
     248,   344,   240,    -1,    57,   273,   351,   248,   351,   274,
      -1,    55,   273,   351,   274,    -1,    58,   273,   351,   248,
     351,   274,    -1,    63,   239,   358,   240,    -1,    -1,   248,
     330,    -1,    -1,   248,   351,    -1,    -1,    84,   337,   340,
     336,   241,   284,   242,    -1,   361,    -1,   361,     9,   361,
      -1,     4,    -1,    87,    -1,    87,   330,    -1,    -1,   239,
     339,   240,    -1,   342,    -1,   228,   341,    -1,   227,   341,
      -1,   341,   228,   341,    -1,   341,   227,   341,    -1,   243,
     330,   248,   330,   248,   330,   248,   330,   248,   330,   244,
      -1,   243,   330,   248,   330,   248,   330,   248,   330,   244,
      -1,   243,   330,   248,   330,   248,   330,   244,    -1,   239,
     330,   248,   330,   248,   330,   240,    -1,   344,    -1,   343,
     248,   344,    -1,   330,    -1,   346,    -1,   243,   244,    -1,
     243,   347,   244,    -1,   228,   243,   347,   244,    -1,   330,
     229,   243,   347,   244,    -1,   344,    -1,     5,    -1,   228,
     346,    -1,   330,   229,   346,    -1,   330,     8,   330,    -1,
     330,     8,   330,     8,   330,    -1,    91,   243,   330,   244,
      -1,   295,     5,    -1,   126,   295,   345,    -1,   295,   177,
      64,   243,   330,   248,   330,   248,   330,   248,   330,   248,
     330,   248,   330,   244,    -1,   299,    -1,   310,    -1,   319,
      -1,   361,   273,   274,    -1,   361,   245,   338,   273,   274,
      -1,   361,     9,   361,   245,   338,   273,   274,    -1,    39,
     241,   361,   242,    -1,    39,   241,   346,   242,    -1,    39,
     239,   346,   240,    -1,    39,   273,   243,   347,   244,   274,
      -1,   361,   273,   243,   347,   244,   274,    -1,    40,   273,
     330,   248,   330,   248,   330,   274,    -1,    41,   273,   330,
     248,   330,   248,   330,   274,    -1,    42,   273,   351,   274,
      -1,    43,   273,   330,   248,   330,   248,   330,   248,   330,
     248,   330,   248,   330,   274,    -1,   197,   273,   346,   274,
      -1,    32,   273,   346,   274,    -1,   330,    -1,   346,    -1,
     347,   248,   330,    -1,   347,   248,   346,    -1,   243,   330,
     248,   330,   248,   330,   248,   330,   244,    -1,   243,   330,
     248,   330,   248,   330,   244,    -1,   361,    -1,     4,   245,
     174,   245,     4,    -1,   243,   350,   244,    -1,   361,   241,
     330,   242,   245,   175,    -1,   348,    -1,   350,   248,   348,
      -1,   352,    -1,   361,    -1,   361,   241,   330,   242,    -1,
     361,   239,   330,   240,    -1,   361,   245,   338,    -1,   361,
       9,   361,   245,   338,    -1,   361,   245,   338,   239,   330,
     240,    -1,   361,     9,   361,   245,   338,   239,   330,   240,
      -1,   361,   241,   330,   242,   245,     4,    -1,   126,    91,
     243,   330,   244,    -1,   126,    94,   243,   330,   244,    -1,
     126,    97,   243,   330,   244,    -1,   126,    99,   243,   330,
     244,    -1,     5,    -1,   210,   241,   361,   242,    -1,    67,
      -1,   208,    -1,    72,    -1,    74,    -1,   194,   239,   351,
     240,    -1,   193,   239,   351,   248,   351,   240,    -1,   195,
     273,   351,   274,    -1,   195,   273,   351,   248,   351,   274,
      -1,   204,   239,   337,   334,   240,    -1,   204,   239,   337,
     245,   338,   334,   240,    -1,    48,   273,   358,   274,    -1,
      49,   239,   351,   240,    -1,    50,   239,   351,   240,    -1,
      51,   239,   351,   248,   351,   248,   351,   240,    -1,    46,
     273,   358,   274,    -1,    60,   273,   351,   274,    -1,    61,
     273,   351,   274,    -1,    62,   273,   351,   274,    -1,    59,
     273,   330,   248,   351,   248,   351,   274,    -1,    54,   273,
     351,   248,   330,   248,   330,   274,    -1,    54,   273,   351,
     248,   330,   274,    -1,    47,   273,   351,   274,    -1,    47,
     273,   351,   248,   347,   274,    -1,    68,   273,   351,   274,
      -1,    69,    -1,    53,   273,   351,   274,    -1,    52,   273,
     351,   274,    -1,    -1,    88,   273,   352,   353,   287,   274,
      -1,    85,   273,   354,   274,    -1,   246,   330,    -1,   361,
       9,   246,   330,    -1,    46,   273,   357,   274,    -1,   358,
      -1,   357,    -1,   243,   358,   244,    -1,   351,    -1,   359,
      -1,   358,   248,   351,    -1,   358,   248,   359,    -1,   361,
     239,   240,    -1,   361,   245,   338,   239,   240,    -1,   361,
       9,   361,   245,   338,   239,   240,    -1,     4,   247,   243,
     330,   244,    -1,   360,   247,   243,   330,   244,    -1,   211,
     241,   351,   242,   247,   243,   330,   244,    -1,     4,    -1,
     360,    -1,   211,   241,   351,   242,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
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
    1065,  1088,  1099,  1107,  1114,  1121,  1143,  1166,  1204,  1225,
    1237,  1251,  1251,  1253,  1255,  1264,  1274,  1273,  1294,  1293,
    1311,  1321,  1320,  1334,  1336,  1344,  1350,  1355,  1381,  1383,
    1386,  1388,  1392,  1393,  1397,  1409,  1422,  1437,  1446,  1459,
    1461,  1465,  1466,  1471,  1479,  1488,  1496,  1510,  1528,  1532,
    1539,  1548,  1551,  1558,  1561,  1568,  1592,  1608,  1624,  1661,
    1701,  1717,  1733,  1755,  1771,  1790,  1806,  1827,  1838,  1844,
    1850,  1857,  1888,  1903,  1925,  1948,  1971,  1994,  2018,  2042,
    2066,  2092,  2109,  2125,  2143,  2161,  2191,  2221,  2220,  2250,
    2252,  2254,  2256,  2258,  2266,  2268,  2270,  2272,  2280,  2282,
    2284,  2292,  2294,  2296,  2298,  2308,  2324,  2340,  2356,  2372,
    2388,  2425,  2447,  2471,  2472,  2477,  2480,  2484,  2505,  2524,
    2545,  2560,  2576,  2594,  2645,  2666,  2688,  2711,  2816,  2832,
    2867,  2889,  2911,  2917,  2932,  2960,  2972,  2981,  2988,  3000,
    3019,  3025,  3031,  3038,  3045,  3052,  3064,  3138,  3156,  3173,
    3188,  3221,  3233,  3257,  3261,  3266,  3273,  3278,  3288,  3293,
    3299,  3307,  3311,  3315,  3324,  3388,  3404,  3421,  3438,  3460,
    3482,  3517,  3525,  3533,  3539,  3546,  3553,  3573,  3599,  3611,
    3622,  3640,  3658,  3677,  3676,  3701,  3700,  3727,  3726,  3751,
    3750,  3773,  3789,  3806,  3823,  3846,  3849,  3855,  3867,  3887,
    3891,  3895,  3899,  3903,  3907,  3911,  3915,  3924,  3937,  3938,
    3939,  3940,  3941,  3945,  3946,  3947,  3948,  3949,  3952,  3976,
    3995,  4018,  4021,  4037,  4040,  4057,  4060,  4066,  4069,  4076,
    4079,  4086,  4103,  4144,  4188,  4227,  4252,  4261,  4291,  4317,
    4343,  4375,  4402,  4428,  4454,  4480,  4506,  4528,  4539,  4587,
    4636,  4648,  4659,  4663,  4673,  4684,  4685,  4686,  4690,  4696,
    4708,  4726,  4754,  4755,  4756,  4757,  4758,  4759,  4760,  4761,
    4762,  4769,  4770,  4771,  4772,  4773,  4774,  4775,  4776,  4777,
    4778,  4779,  4780,  4781,  4782,  4783,  4784,  4785,  4786,  4787,
    4788,  4789,  4790,  4791,  4792,  4793,  4794,  4795,  4796,  4797,
    4798,  4799,  4800,  4801,  4802,  4803,  4804,  4805,  4806,  4815,
    4816,  4817,  4818,  4819,  4820,  4821,  4822,  4823,  4824,  4825,
    4830,  4829,  4837,  4839,  4844,  4849,  4853,  4858,  4863,  4867,
    4871,  4875,  4879,  4883,  4887,  4893,  4909,  4914,  4920,  4926,
    4945,  4966,  4999,  5003,  5008,  5012,  5016,  5020,  5025,  5030,
    5040,  5050,  5055,  5066,  5075,  5080,  5085,  5113,  5114,  5120,
    5121,  5127,  5126,  5149,  5151,  5156,  5165,  5167,  5173,  5174,
    5179,  5183,  5187,  5191,  5195,  5202,  5206,  5210,  5214,  5221,
    5226,  5233,  5238,  5242,  5247,  5251,  5259,  5270,  5274,  5286,
    5294,  5302,  5309,  5319,  5342,  5348,  5359,  5365,  5375,  5385,
    5395,  5407,  5411,  5416,  5428,  5432,  5436,  5440,  5458,  5466,
    5474,  5503,  5513,  5529,  5540,  5545,  5549,  5553,  5565,  5569,
    5581,  5598,  5608,  5612,  5627,  5632,  5639,  5643,  5648,  5662,
    5678,  5682,  5686,  5690,  5694,  5702,  5708,  5714,  5720,  5729,
    5733,  5737,  5745,  5751,  5757,  5761,  5769,  5777,  5784,  5793,
    5797,  5801,  5816,  5830,  5844,  5856,  5872,  5881,  5890,  5900,
    5911,  5919,  5927,  5931,  5950,  5957,  5963,  5970,  5978,  5977,
    5987,  6011,  6013,  6019,  6024,  6026,  6031,  6036,  6041,  6043,
    6047,  6059,  6073,  6077,  6084,  6092,  6100,  6111,  6113,  6116
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
  "tSpline", "tVolume", "tBox", "tCylinder", "tCone", "tTorus",
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
  "tAFFECTDIVIDE", "tAFFECTTIMES", "tAFFECTMINUS", "tAFFECTPLUS", "'?'",
  "tOR", "tAND", "tNOTEQUAL", "tEQUAL", "'<'", "'>'", "tGREATERGREATER",
  "tLESSLESS", "tGREATEROREQUAL", "tLESSOREQUAL", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'|'", "'&'", "'!'", "UNARYPREC", "tMINUSMINUS",
  "tPLUSPLUS", "'^'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'.'",
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
  "MultiStringExprVar", "StringIndex", "String__Index", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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
     474,    60,    62,   475,   476,   477,   478,    43,    45,    42,
      47,    37,   124,    38,    33,   479,   480,   481,    94,    40,
      41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

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
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   276,   276,   277,   277,   277,   278,   277,   279,   277,
     277,   280,   277,   281,   281,   282,   282,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   286,   286,   286,   287,
     287,   288,   288,   289,   289,   289,   289,   289,   290,   290,
     290,   291,   291,   292,   292,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   294,   293,   295,
     295,   295,   295,   295,   296,   296,   296,   296,   297,   297,
     297,   298,   298,   298,   298,   299,   299,   299,   299,   299,
     299,   299,   299,   300,   300,   301,   301,   301,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     303,   303,   303,   303,   303,   303,   303,   304,   304,   305,
     306,   306,   306,   306,   306,   306,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   308,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     310,   310,   310,   311,   310,   312,   310,   313,   310,   314,
     310,   310,   310,   310,   310,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   317,   317,
     317,   317,   317,   318,   318,   318,   318,   318,   319,   319,
     320,   321,   321,   322,   322,   323,   323,   324,   324,   325,
     325,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   327,   327,   327,   328,   328,   328,   329,   329,
     329,   329,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     332,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   333,   333,   334,
     334,   336,   335,   337,   337,   338,   339,   339,   340,   340,
     341,   341,   341,   341,   341,   342,   342,   342,   342,   343,
     343,   344,   344,   344,   344,   344,   344,   345,   345,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   347,   347,   347,   347,   348,   348,
     348,   348,   349,   349,   350,   350,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   353,   352,
     352,   354,   354,   355,   356,   356,   357,   358,   358,   358,
     358,   359,   359,   359,   360,   360,   360,   361,   361,   361
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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
       3,     0,     5,     0,     2,     7,     7,     7,     8,     8,
       7,     7,    11,     7,     8,     8,     8,     9,     3,     4,
      10,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     8,     7,     7,     8,     8,    12,     0,     9,     1,
       1,     1,     1,     4,     1,     1,     1,     4,     1,     1,
       4,     1,     1,     1,     4,     5,    11,     5,     9,     9,
       4,     9,     9,     1,     1,     0,     2,     6,     8,    10,
      14,    16,    12,    14,    14,    14,    14,     8,     8,     6,
       4,     5,     6,     6,     3,     4,     3,     5,     6,     5,
       3,     3,     4,     5,     4,     5,     3,     5,     7,     7,
       3,     7,     3,     2,     2,     2,     2,     2,    15,     2,
       2,     2,     2,     2,    16,    11,     6,     8,     8,    10,
       1,     2,     2,     1,     3,     3,     4,     4,     1,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     9,     2,     3,    10,     1,     2,     5,     7,     2,
       2,     3,     2,     3,     2,     3,     9,     6,     1,     1,
       1,     1,     1,     0,     2,     3,     3,     4,     9,     4,
      14,     0,     3,     0,     1,     0,     2,     0,     2,     0,
       2,     6,     7,     6,     5,     3,     8,     5,     4,     6,
      11,    11,    18,    18,    12,    12,    12,    10,     4,     4,
       4,     4,     2,     3,     6,     1,     1,     1,     2,     5,
       7,    10,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     1,     4,     6,     1,     4,     4,     4,     6,
       5,     7,     8,    10,     4,     4,     6,     4,     3,     2,
       5,     5,     3,     5,     6,     8,     6,     8,     6,     4,
       7,     6,     6,     6,     4,     6,     4,     0,     2,     0,
       2,     0,     7,     1,     3,     1,     1,     2,     0,     3,
       1,     2,     2,     3,     3,    11,     9,     7,     7,     1,
       3,     1,     1,     2,     3,     4,     5,     1,     1,     2,
       3,     3,     5,     4,     2,     3,    16,     1,     1,     1,
       3,     5,     7,     4,     4,     4,     6,     6,     8,     8,
       4,    14,     4,     4,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     4,     4,
       3,     5,     6,     8,     6,     5,     5,     5,     5,     1,
       4,     1,     1,     1,     1,     4,     6,     4,     6,     5,
       7,     4,     4,     4,     8,     4,     4,     4,     4,     8,
       8,     6,     4,     6,     4,     1,     4,     4,     0,     6,
       4,     2,     4,     4,     1,     1,     3,     1,     1,     3,
       3,     3,     5,     7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,   190,     0,     0,
     191,     0,   192,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,   309,   310,   311,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,   278,   279,     0,     0,     0,   273,     0,
       0,     0,     0,     0,   355,   356,   357,     0,     0,     5,
       6,     7,     8,    10,     0,    11,    24,    12,    13,    14,
      15,    23,    22,    21,    16,     0,    17,    18,    19,    20,
       0,    25,     0,   588,     0,   215,     0,     0,     0,     0,
       0,   257,     0,   259,   260,   255,   256,     0,   261,   262,
     113,   123,   587,   468,   463,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,     0,   201,   202,   203,     0,     0,     0,   409,
     410,   412,   413,   411,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,   418,   419,
       0,     0,   189,   190,   191,   192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   414,   415,   416,     0,     0,
       0,     0,     0,     0,     0,   497,   498,     0,   499,   481,
     362,   422,   425,   292,   482,   463,     0,     0,     0,     0,
       0,     0,     0,     0,   189,   187,   194,   195,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   470,     0,     0,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   587,     0,     0,   215,     0,     0,   352,
       0,     0,     0,   198,   199,     0,     0,     0,     0,     0,
     488,     0,   487,     0,     0,     0,     0,     0,   587,     0,
       0,   520,     0,     0,     0,     0,   253,   254,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   541,     0,   565,   543,   544,     0,     0,
       0,     0,     0,     0,   542,     0,     0,     0,     0,   271,
     272,     0,   215,     0,   215,     0,     0,     0,   463,     0,
       0,     0,   215,   358,     0,     0,    76,     0,    63,     0,
       0,    67,    66,    65,    64,    69,    68,    70,    71,     0,
       0,     0,     0,     0,     0,   526,   463,     0,   214,     0,
     213,     0,   168,     0,     0,   526,   527,     0,     0,   577,
       0,   578,   527,   111,   111,     0,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   514,   515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,     0,   364,   489,   366,
       0,   483,     0,     0,   463,   494,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
       0,   439,     0,     0,     0,     0,     0,     0,   293,     0,
     325,   325,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   215,     0,   215,   215,     0,   472,   471,     0,     0,
       0,     0,   215,   215,     0,     0,     0,     0,   289,     0,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   327,     0,     0,     0,     0,     0,   236,     0,     0,
     234,   353,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   335,   252,     0,     0,     0,     0,     0,   215,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,   274,     0,   240,     0,
     241,     0,     0,   364,     0,   215,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      72,    73,     0,     0,   250,    38,   246,     0,     0,     0,
       0,     0,   210,     0,     0,     0,   216,     0,     0,   169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,   466,
       0,     0,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,     0,     0,   193,     0,     0,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   420,   438,     0,     0,   495,     0,     0,     0,     0,
       0,   457,     0,   363,   484,     0,     0,     0,   491,     0,
     382,   381,   380,   379,   375,   376,   383,   384,   378,   377,
     368,   367,     0,   369,   490,   370,   373,   371,   372,   374,
     464,     0,     0,   465,   442,     0,   500,     0,     0,     0,
       0,     0,     0,     0,   323,     0,     0,     0,     0,   351,
       0,     0,     0,     0,   350,     0,   215,     0,     0,     0,
       0,     0,   474,   473,     0,     0,     0,     0,     0,     0,
       0,   283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   338,     0,     0,   235,     0,     0,
     230,     0,     0,     0,     0,   348,     0,     0,     0,   363,
       0,     0,     0,     0,     0,     0,     0,     0,   276,   277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   568,     0,
       0,     0,   459,     0,     0,   242,   244,     0,   369,     0,
     464,   442,   589,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,   363,     0,
      63,     0,     0,     0,     0,    79,     0,    63,    64,     0,
       0,   464,     0,     0,   442,     0,     0,     0,     0,     0,
     584,    28,    26,    27,     0,     0,     0,     0,     0,   465,
     530,    29,     0,     0,   247,   579,   580,     0,   581,   530,
      74,   114,    75,   124,   467,   469,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     516,   517,   204,     9,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   408,   395,     0,   397,   398,   399,   400,
     401,   513,   402,   403,   404,     0,     0,     0,   505,   504,
     503,     0,     0,     0,   510,     0,   454,     0,     0,     0,
     456,   128,   437,   493,     0,     0,   423,   512,   428,     0,
     434,     0,     0,     0,     0,   485,     0,     0,   435,     0,
       0,     0,     0,     0,   427,   426,   449,    70,    71,     0,
       0,     0,     0,     0,     0,   363,   321,   326,   324,     0,
     334,     0,   148,   149,   197,   363,     0,     0,     0,     0,
     231,     0,   243,   245,     0,     0,     0,   205,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   328,   337,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,   237,     0,     0,     0,     0,   555,     0,   562,
     551,   552,   553,     0,   567,   566,     0,     0,   556,   557,
     558,   564,   571,   570,     0,   139,     0,   545,     0,   547,
       0,     0,     0,   540,     0,   239,     0,     0,     0,     0,
       0,     0,     0,   314,     0,     0,     0,   359,     0,   585,
       0,     0,     0,     0,   101,    63,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,    61,     0,    39,    40,
      41,    42,    43,     0,   427,   426,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   529,   528,     0,     0,     0,
       0,     0,     0,     0,   135,     0,   131,   132,     0,     0,
       0,   153,   153,     0,     0,     0,     0,     0,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   457,   458,     0,
     430,     0,     0,     0,   492,   385,   486,   443,   441,     0,
     440,     0,     0,   501,     0,     0,     0,     0,     0,     0,
       0,     0,   333,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,     0,     0,     0,     0,     0,   300,     0,
       0,   299,     0,   302,     0,   304,     0,   290,   296,     0,
       0,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,   339,     0,   233,   232,   354,     0,     0,    35,    36,
       0,     0,     0,     0,   521,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   459,   460,   549,     0,   443,     0,     0,   215,
     315,     0,   316,   215,     0,     0,   535,   536,   537,   538,
       0,    86,     0,     0,     0,     0,    84,    91,    93,     0,
     524,     0,    99,     0,     0,     0,     0,    81,     0,     0,
       0,     0,     0,    34,   443,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    31,     0,   531,     0,     0,    32,
       0,   531,   582,     0,   115,   120,     0,     0,     0,   134,
     137,   138,   462,     0,    77,    78,   155,     0,     0,     0,
       0,   156,   171,   172,     0,     0,     0,   157,   182,   173,
     177,   178,   174,   175,   176,   163,     0,     0,   396,   405,
     406,   407,   506,     0,     0,     0,   452,   453,   455,   129,
     421,   451,   424,   429,     0,     0,   457,   183,   436,     0,
      70,    71,     0,   448,   444,   446,   507,   179,     0,     0,
     151,     0,     0,   332,     0,   150,     0,     0,     0,     0,
     251,     0,     0,     0,     0,   215,   215,     0,     0,   301,
     481,     0,     0,   303,   305,     0,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,     0,
       0,     0,     0,   160,   161,     0,     0,     0,     0,   102,
     103,   104,   108,     0,   563,     0,     0,   561,     0,   572,
       0,     0,   140,   141,   569,   546,   548,     0,     0,     0,
       0,     0,     0,   313,   317,   313,     0,   360,    85,    63,
       0,     0,     0,     0,    83,     0,   522,     0,     0,     0,
       0,     0,     0,   575,   574,     0,     0,     0,     0,     0,
     479,     0,     0,   448,   248,   444,   249,     0,     0,   217,
       0,     0,   534,   532,     0,     0,   116,   121,     0,     0,
       0,   514,   515,   133,   154,   158,   159,   164,   181,     0,
     166,     0,     0,     0,     0,     0,     0,   431,     0,     0,
       0,     0,   502,   450,     0,   165,     0,   184,   322,     0,
       0,   185,     0,     0,     0,     0,     0,     0,   478,   477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   227,     0,     0,     0,     0,     0,     0,     0,     0,
     218,     0,     0,   336,    37,     0,   519,     0,     0,   268,
     267,     0,     0,     0,     0,     0,     0,   143,   144,   147,
     146,   145,     0,   550,     0,   586,     0,     0,     0,     0,
       0,     0,    96,     0,     0,    97,   525,     0,     0,     0,
      88,     0,     0,     0,    44,     0,     0,     0,     0,     0,
      46,     0,    33,     0,     0,   583,   128,   139,     0,     0,
     136,     0,     0,     0,     0,     0,     0,   508,   509,     0,
     457,   432,     0,   445,   447,     0,   167,   188,     0,   329,
     329,     0,   109,   110,   215,     0,   208,   209,   291,     0,
     297,     0,     0,   215,     0,     0,     0,     0,     0,     0,
       0,     0,   212,   211,     0,     0,     0,     0,   105,   106,
     554,   560,   559,   142,     0,     0,     0,   318,     0,    92,
      94,     0,   100,     0,    82,   576,    89,    90,    49,     0,
       0,     0,     0,   480,     0,     0,   445,   533,     0,     0,
       0,   118,   573,     0,   125,     0,     0,   170,     0,     0,
       0,     0,   294,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   476,     0,   307,     0,     0,   285,     0,
     219,     0,     0,     0,     0,     0,     0,     0,   518,   269,
       0,     0,   347,   215,   361,     0,   523,     0,    45,     0,
       0,     0,    62,    47,     0,   117,   122,   128,     0,     0,
     152,     0,     0,   433,     0,     0,     0,     0,   330,   340,
       0,     0,   341,     0,   206,     0,   298,     0,   281,     0,
     215,     0,     0,     0,     0,     0,     0,   162,   107,   265,
     313,    98,     0,     0,     0,     0,     0,     0,   126,   127,
       0,     0,     0,   186,     0,   344,     0,   345,   346,   475,
       0,     0,   287,   222,     0,     0,     0,     0,     0,     0,
       0,     0,    53,     0,    59,     0,     0,   119,     0,     0,
       0,     0,     0,   306,   286,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   223,   224,   225,   226,     0,
     220,   320,    50,     0,    57,     0,   258,     0,   511,     0,
       0,     0,   288,     0,     0,    51,     0,     0,   264,     0,
       0,     0,   221,     0,     0,     0,     0,   496,     0,     0,
      54,    52,     0,    55,     0,   342,   343,     0,     0,    60,
      58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   109,   994,   110,   111,   980,  1773,  1779,
    1258,  1458,  1917,  2044,  1259,  2015,  2062,  1260,  2046,  1261,
    1262,  1462,   410,   551,   552,  1060,   112,   726,   433,  1786,
    1927,  1787,   434,  1670,  1323,  1285,  1286,  1287,  1419,  1612,
    1613,  1121,  1506,  1498,   706,   562,   254,   280,   326,   187,
     255,   419,   420,   116,   117,   118,   119,   120,   121,   122,
     123,   256,  1153,  1949,  2006,   879,  1149,  1150,   257,   957,
     258,   127,  1351,  1119,   854,   893,  1887,   128,   129,   130,
     131,   259,   260,  1081,  1094,  1212,   261,   731,   262,   844,
     730,   436,   577,   295,  1649,   332,   333,   264,   522,   340,
    1246,  1451,   429,   425,  1205,   936,  1491,  1642,  1643,   921,
     431,   133,   388
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1754
static const yytype_int16 yypact[] =
{
   10058,    63,    60, 10209, -1754, -1754,   115,   161,     4,   -85,
     -37,    48,   211,   220,   234,   296,    66,   364,   374,   153,
     177,    28,   167,   167,   182,   218,   230,    24,   236,   239,
      43,   262,   276,   311,   332,   333,   356,   367,   381,   388,
     401,   181,   477,   506,   553,   370,   246,   407,  5870,   434,
     410,   595,   -61,   625,   508,   567,   102,   437,   571,   -24,
     461,   -45,   -45,   484,   319,   372, -1754, -1754, -1754, -1754,
   -1754,   495,   351,   652,   646,    18,    44,   658,   666,    68,
     735,   762,   763,  5159,   774,   547,   575,   607,    11,    62,
   -1754,   612,   613, -1754, -1754,   801,   815,   616, -1754, 10407,
     639,  3344,    19,    32, -1754, -1754, -1754,  9887,   653, -1754,
   -1754, -1754, -1754, -1754,   633, -1754, -1754, -1754, -1754, -1754,
   -1754, -1754, -1754, -1754, -1754,   -71, -1754, -1754, -1754, -1754,
      49, -1754,   878,   669,  4897,   320,   672,   889,  9887, 10377,
   10377, -1754,  9887, -1754, -1754, -1754, -1754, 10377, -1754, -1754,
   -1754, -1754,   682,   691,   925, -1754, -1754, 10437,    28,  9887,
    9887,  9887,   698,  9887,  9887,  9887,   702,  9887,  9887,  9887,
    9887,  9887,  9887,  9887, 10377,  9887,  9887,  9887,  9887,  6107,
     705, -1754,  8003, -1754, -1754, -1754,   703,  5159, 10377, -1754,
   -1754, -1754, -1754, -1754,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   355,   167,   167,
     167,   167,   167,   706,   167,   167,   708, -1754, -1754, -1754,
     167,   167,   707, -1754, -1754, -1754,  6107,   830,   508,   713,
     167,   167,   714,   715,   716, -1754, -1754, -1754,  9887,  6344,
    9887,  9887,  6581,    28,    41, -1754, -1754,   717, -1754,  4814,
   -1754, -1754, -1754, -1754, -1754,   118,  9887,  8003,   719,   720,
    6818,  5159,  5159,  5159, -1754, -1754, -1754, -1754, -1754,   718,
    7055,   721,  4351,   952,  6107,   722,    11,   723,   724,   -45,
     -45,   -45,  9887,  9887,  -151, -1754,   260,   -45,  8876,   440,
     373,   730,   731,   733,   734,   739,   741,   742,  9887,  5159,
    5159,  5159,   743,    31,   957,   744, -1754,   968,   977, -1754,
     747,   751,   755, -1754, -1754,   766,  5159,   746,   769,   770,
   -1754,  9887, -1754,   978,  1006,  9887,  9887,  9887,   337,  9887,
     771, -1754,   836,  9887,  9887,  9887, -1754, -1754,  9887, -1754,
     167,   167,   167,   776,   777,   780,   167,   167,   167,   167,
     167,   167,   167, -1754,   167, -1754, -1754, -1754,   167,   167,
     784,   795,   167,   796, -1754,   797,  1031,  1033,   798, -1754,
   -1754,  1034, -1754,  1036, -1754,   167,  9887, 12514,   132, 10377,
    8003,  9887, -1754, -1754,  6107,  6107, -1754,   800, 10437,   591,
    1040, -1754, -1754, -1754, -1754, -1754, -1754,  9887,  9887,    36,
    6107,  1042,    17,  1993,   807,  1045,    74,   810, -1754,   808,
   10625,  9887, -1754,  2419,  -128, -1754,    54,  -108,  9450, -1754,
     -12, -1754,    59,    84,   142,   967, -1754,    28,   812,   816,
   13030, 13055, 13080,  9887, 13105, 13130, 13155,  9887, 13180, 13205,
   13230, 13255, 13280, 13305, 13330,   823, 13355, 13380, 13405, 11644,
    1049,  9887,  8003,  4837, -1754,   382,  9887,  1059,   826,  9887,
    9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,
    9887,  9887,  9887,  9887,  9887,  8003,  9887,  9887,  9887,  9887,
    9887,  9887,  8003,  8003,   824,  9887,  9887, 10377,  9887, 10377,
    6107, 10377, 10377, 10377,  9887,    34,  9887,  6107,  5159, 10377,
   10377,  8003,    28, 10437,    28,   831,  8003,   831, -1754,   831,
   13430, -1754,   426,   825,    73, -1754,  1007,  9887,  9887,  9887,
    9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,
    9887,  7292,  9887,  9887,  9887,  9887,  9887,    28,  9887,  9887,
    1068, -1754,   620, 13455,   447,  9887,  9887,  9887, -1754,  1066,
    1070,  1070,   841,  9887,  9887,  1075,  8003,  8003, 12542,   842,
    1078, -1754,   843, -1754, -1754,  -157, -1754, -1754,  9534,  9759,
     -45,   -45,   320,   320,  -129,  8876,  8876,  9887,  2927,  -124,
   -1754,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,
   13480,  1082,  1084,  1085,  9887,  1089,  9887, -1754,  9887,  5226,
   -1754, -1754,  8003,  8003,  8003,  9887,  1091,  9887,  9887,  9887,
   13505, -1754, -1754, 13530, 13555, 13580,   917, 10310, -1754,   855,
    4928, 13605, 13630, 12625, 10377, 10377, 10377, 10377, 10377, 10377,
   10377, 10377, 10377,  9887, 10377, 10377, 10377, 10377,     5, 10437,
   10377, 10377, 10377,    28,    28, -1754, -1754,  8003, -1754,  5463,
   -1754,  5700,  9887,   831,  9887, -1754,    28,  9887,  9887,  1068,
     868,   462, 13655, 10560,   871,   472,  9887,  1110,   874,   876,
     880,   881,  9887, 13680, 12652,   186,   883,  1119,  1123, -1754,
   -1754, -1754,  8003,   197, -1754, -1754, -1754,    28,  9887,  9887,
    1068,   890, -1754,   893,   -46,   567, -1754,   891, 11673, -1754,
      21,  8003,    28,  9887,  9887,  1129,  1130,  8003,  9887,  1131,
   10377,    28,  8953,  1129,  1133, -1754,    28,  1134, 10377,  9887,
     903,   904, -1754,  9887, 10437,  1137,  1140,  1141, 13705,  1145,
    1146,  1147, 13730,  1148,  1149,  1150,  1151,  1152,  1154,  1155,
   -1754,  1156,  1157,  1158, -1754,  9887, 13755,  8003,   924,  8003,
   11702, -1754,  1162, 12598, 12598, 12598, 12598, 12598, 12598, 12598,
   12598, 12598, 12598, 12598, 10555, 12598, 12598, 12598, 12598,  2034,
     545, 12598, 12598, 12598, 10588, 10621, 10654,  4837,   931,   930,
      97,  8003, 10687, 10720,   545, 10753,   545,   929,   932,   933,
      87, 14555, -1754,   545, 11731, -1754,   934,   222,   545,    13,
     938,   430,   511,  1166, -1754,  1129,   545,   940,  7939,  8266,
    1420,   570,  1003,  1003,   469,   469,   469,   469,   469,   469,
     515,   515,  8003,   304, -1754,   304,   304,   831,   831,   831,
     939, 13780, 12679,   -94,   667,  8003, -1754,  1179,   944, 13805,
   13830, 13855,  9887,  6107,  1184,  1183,  8644, 11760, 13880, -1754,
     517,   520,  8003,   946, -1754,  5937, -1754,  6174,  6411,   -45,
    9887,  9887, -1754, -1754,   948,   949,  8876,  4055,  1067,   414,
     -45,  6648, 13905, 11789, 13930, 13955, 13980, 14005, 14030, 14055,
   14080,  1188,  9887,  1191, -1754,  9887, 14105, -1754, 12706, 12733,
   -1754,   525,   527,   528, 11818, -1754, 12760, 12787, 10786, -1754,
    1192,  1194,  1197,   961,  9887,  6885,  9887,  9887, -1754, -1754,
      35,   343,   377,   343,   969,   970,   959,   545,   545,   963,
   10819,   545,   545,   545,   545,  9887,   545,  1203, -1754,   965,
     974,   463,  -164,   973,   533, -1754, -1754, 12598,   304,  7122,
     971,   668,   975,  1041,  1210,  1071,  9185,   996,  1000,  1215,
    6107, 11847, -1754,  9887,  9887,  9887,  9887,  2444,   190,   116,
   10437,  9887,  1238,  1241,    30, -1754,   535,  1204,  1205,  6107,
      22,  1004, 14130, 12814,   140,  9887,  9887,  1013,  1014,  8003,
   -1754, -1754, -1754, -1754, 10377,   124,  1009, 14155, 12841, -1754,
    1016, -1754,   145, 10852, -1754, -1754, -1754,  1015, -1754,  1019,
   -1754,    79, -1754, -1754, 14555, -1754,  1255, 12598,   545,   -45,
    6107,  6107,  1259,  6107,  6107,  6107,  1260,  6107,  6107,  6107,
    6107,  6107,  6107,  6107,  6107,  6107,  6107,  2579,  1261,  8003,
    4837, -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754,
   -1754, -1754, -1754, -1754, -1754,  9887, -1754, -1754, -1754, -1754,
   -1754, -1754, -1754, -1754, -1754,  9887,  9887,  9887, -1754, -1754,
   -1754,   536,  9887,  9887, -1754,  9887, -1754,  6107, 10377, 10377,
   -1754,  1022, -1754, -1754,  9887,  9887, -1754, -1754, -1754,  1129,
   -1754,  1129,  9887,  9887,  1032, -1754,  6107,   167, -1754,  9887,
    9887,  9887,   561,  1129,   -94,   -13, -1754,  9887,  9887,   545,
     562,  6107,  8003,  1264,  1266,  1267,  2489, -1754, -1754,  1269,
   -1754,  1037, 14555,  1028, -1754,  1271,  1272,  1273,   568,  1278,
   -1754,  7359, -1754, -1754,  -114, 10885, 10918, -1754, -1754, 11876,
     -98,  1174,  1281,  9269,  1043,  1283,  1048,    33,    38,   -67,
   -1754,   -89, -1754,   414,  1284,  1286,  1291,  1293,  1294,  1296,
    1297,  1298,  1299,  6107, 14555, -1754,  2619,  1064,  1302,  1303,
    1304,  1214,  1307, -1754,  1309,  1310,  9887,  6107,  6107,  6107,
    1313, 10951, -1754,  8589,  1682,    57,  1314, -1754,  8003, -1754,
   -1754, -1754, -1754, 10377, -1754, -1754,  9887, 10377, -1754, -1754,
   -1754, -1754, 14555, -1754,  1076,  1077, 10377, -1754, 10377, -1754,
    1129, 10377,  1083, -1754,  1080, -1754,  1129,  9887,  9887,  1081,
     508,  1086,  9501, -1754,  2967,  1087,  6107, -1754,  1088, -1754,
   11905, 11934, 11963, 11992, -1754, -1754,  9887,  1320,    45,  9887,
    1325,  1327,  3112, -1754,  1328,    11,  1330,  1093,   545,   167,
     167,  1331, -1754,  1099,  1100,  1097, -1754,  1335, -1754, -1754,
   -1754, -1754, -1754,  1129,   450,   851,  9887, 12868, 14180,  9887,
    9887,   574,  1341,    25,  1129, -1754,  1103,  9887,  1343,  9887,
    1129,  9578,  8235,   545,  4105,  1108,  1107, -1754,  1345,  1351,
      94,  1235,  1235,  6107,  1353,  1354,  1356,  6107,  1186,  1358,
    1359,  1360,  1362,  1363,  1364,  1365,  1366,  1367, -1754,  1369,
     576, 12598, 12598, 12598, 12598,   545, 10984, 11017, 11050,  1135,
     545,   545,  1255,   545, 14205, 12598,  1136,  -174, 14555, 12598,
   -1754,  1371,   545, 11083, 14555, 14555, -1754,   694, -1754,  1375,
   -1754, 14230, 12895, -1754,   545,  1377,   579,  6107,  6107,  6107,
    1378,  1379, -1754,   228,  9887,  6107,  1144,  1153,  1381,   283,
   -1754,  9887,  9887,  9887,  1159,  1160,  1161,  1143, -1754,  3350,
    6107, -1754,  9887, -1754,  1384, -1754,  1385, -1754, -1754,  8876,
     -39,  5396, -1754,  1163,  1164,  1165,  1167,  1168,  1169,  7529,
    1386, -1754,  8003, -1754, -1754, -1754,  1170,  9887, -1754, -1754,
   12922,  1387,  1388,  1222, -1754,  9887,  9887,  9887, -1754,  1391,
    1392,  1393,   429,   473,  1171,  8825,  1172,  9887,    26,   545,
    1175,   545,  1173, -1754, -1754, 10437,   699,  9887,  1189, -1754,
   -1754,  3518, -1754, -1754,  1193,  1394, -1754, -1754, -1754, -1754,
    3552, -1754,   202,  1195,  1398,  3754, -1754, -1754, -1754,    11,
   -1754,   582, -1754,  9887,   228,  1053,  1376, -1754,  1178,  9887,
    9887,  6107,  1196, -1754,   519,  1405,  1408, 14255,  1412,  1166,
   14280, 14305,  1425, -1754, -1754, 10377,  1208,  1430, 14330, -1754,
   11116,  1212, -1754,  4613, 14555, -1754,  1435,   167,  6581, -1754,
   -1754, -1754, -1754,  1255, -1754, -1754, -1754,   -45,  1443,  1448,
    1450, -1754, -1754, -1754,  1451,  1368,  1453, -1754, -1754, -1754,
   -1754, -1754, -1754, -1754, -1754, -1754,  1455,  1219, -1754, -1754,
   -1754, -1754, -1754,  9887,  9887,  9887, -1754, -1754, -1754,  1107,
   -1754, -1754, -1754, -1754,  9887,  1225,  1218, -1754, -1754,  9887,
    9887,  9887,   545,   -94, -1754, -1754, -1754, -1754,  1224,  1462,
    1186,  1463,  9887, -1754,  6107, 14555,   809,  8003,  8003,  9887,
   -1754,  8644, 12021, 14355,  8909,   320,   320,  9887,  9887, -1754,
     301,  1223, 14380, -1754, -1754, 12050,   -75, -1754,  1464,  1467,
    6107,   -45,   -45,   -45,   -45,   -45,  5633,  1468, -1754,   584,
    9887,  3780,  1469, -1754, -1754,  6107,  9141,  1866, 14405, -1754,
   -1754, -1754, -1754,  8321, -1754, 10377,  9887, -1754, 10377, 14555,
    8558, 10437,  1228, -1754, -1754, -1754, -1754,  1237,  1233,  9887,
    9887, 12079,  9887, 10560, -1754, 10560,  6107, -1754, -1754, 10437,
    9887,  1476,  1479,    30, -1754,  1478, -1754,    11, 12949,  6107,
   10377,  1480,   545, -1754,  1239,   545,  9887, 11149, 11182,   587,
   -1754,  9887,  9887,   514, -1754,  1245, -1754,  1267,  1271, -1754,
    1483,  9887, -1754, -1754,  9887,  9810, -1754, -1754,  1247,  1376,
     589,  4650,  1484, -1754,   256, -1754, -1754, -1754, -1754,  1249,
   -1754,  1489,  6107, 12598, 12598, 11215, 12598, -1754,  1256, 11248,
   14430, 12976, -1754, -1754,  9887, -1754,  1492, -1754, 14555,  1493,
    1252, -1754,   590,   592, 12570,  3814,  1494,  1258, -1754, -1754,
    9887,  1262,  1263, 12108, 13003,  1497,  6107,  1498,  1265,  9887,
   -1754, -1754,   597,   -58,   -47,   -36,   -21,   -14,  7766,   117,
   -1754,  1503, 12137, -1754, -1754,  1332, -1754,  9887,  9887, -1754,
   -1754,  8003,  3839,  1504,  1274, 12598,   545, 14555, -1754, -1754,
   -1754, -1754,    26, -1754, 10437, -1754, 12166,  1268,  1275,  1276,
    1505,  4222, -1754,  1506,  1509, -1754, -1754,  1277,  1510,   599,
   -1754,  1512,  1517,   185, 14555,  9887,  9887,  1282,  6107,   600,
   14555, 14455, -1754, 14480, 11281, -1754,  1022,  1077,  6107,   545,
   -1754,  9887, 10437,    28,  9887,  1518,   605, -1754, -1754,  9887,
    1218, -1754,  9887, -1754, -1754, 12195, -1754, -1754,  6107,   415,
     523,  8003, -1754, -1754,   320,  9216, -1754, -1754, -1754,  1521,
   -1754,  1287,  6107, -1754, 12224,  1524,  8003,   -45,   -45,   -45,
     -45,   -45, -1754, -1754,  9887, 12253, 12282,   610, -1754, -1754,
   -1754, -1754, -1754, -1754,  1292,  1527,  1295, -1754,  1528, -1754,
   -1754,    11, -1754,  1370, -1754, -1754, -1754, -1754, -1754,  9887,
   11314, 11347,  6107, -1754,  1529,  9887,  1300, -1754,  9887,  1305,
    1306, -1754, -1754,  4776, -1754,  1301, 12311, -1754,  1315, 11380,
    1308, 11413, -1754,   621,  1316,   -45,  6107,  1531,  1317,   -45,
    1533,   624,  1312, -1754,  9887, -1754,  1535,  1413,  7596,  1318,
   -1754,   626,   147,   201,   233,   238,   264,  4288, -1754, -1754,
    1538,  1540, -1754, -1754, -1754,  1547, -1754,  1319, 14555,  9887,
    9887,   627, -1754, 14555, 11446, -1754, -1754,  1022, 10437,  1333,
   -1754,  9887,  9887, -1754,  9887,  1551,   -45,   120, -1754, -1754,
     -45,   122, -1754,  1559, -1754, 12340, -1754,  9887, -1754,   414,
   -1754,  1566,  8003,  8003,  8003,  8003,  7766, -1754, -1754, -1754,
   10560, -1754,  9887, 14505, 11479,    51,  9887,  1337, -1754, -1754,
   11512, 11545, 11578, -1754,   313, -1754,   325, -1754, -1754, -1754,
    4549,   291,  7833, -1754,   629,   635,   637,   642,   328,   643,
    1338,   645, -1754,  9887, -1754,  6107, 12369, -1754,  9887,  9887,
    9887,   -45,   -45, -1754, -1754, -1754,   414,  1568,  1569,  1570,
    1573,  8003,  1579,  1582,  1583,  1347, 14530,   648,  1585, 12398,
   12598, 11611,   338,   350,   468, -1754, -1754, -1754, -1754,   673,
   -1754, -1754, -1754, 10377, -1754,  1350, -1754,  1588, -1754,  9887,
    9887,  9887, -1754,  1589,   678, -1754,  1357,  6107, -1754, 12427,
   12456, 12485, -1754,  1591, 10377, 10377,   680, -1754,  1593,  1595,
   -1754, -1754,   683, -1754,  1597, -1754, -1754,  1598, 10377, -1754,
   -1754, -1754
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1754, -1754, -1754, -1754,   334, -1754, -1754, -1754, -1754,  -356,
   -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754, -1754,
   -1754, -1754,  -672,   -26,  3016,  3153, -1754,  1176, -1754, -1754,
   -1754, -1754, -1754, -1754, -1753, -1754,   286,   119,  -178, -1754,
    -139, -1754,    64,   323,  1613, -1754,    -1,   912, -1754, -1754,
      -2,  -577,  -287, -1754, -1754, -1754, -1754, -1754, -1754, -1754,
   -1754,  1615, -1754, -1754, -1754, -1754, -1145, -1142,  1617, -1609,
    1618, -1754, -1754, -1754,  1072, -1754,  -185, -1754, -1754, -1754,
   -1754,  1899, -1754, -1754, -1315,   206,  1626, -1754,     2,  -659,
   -1754, -1754,    99, -1754, -1537,   -28,  -162,  2067,  1311,  -283,
      23, -1754,    91,   -82, -1754, -1754,    47,   175, -1551,  -143,
     915, -1754,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -535
static const yytype_int16 yytable[] =
{
     134,   115,   114,   572,   430,   874,   875,  1378,  1380,   152,
     951,   588,  1535,   971,  1757,   338,  1758,   376,   154,   380,
     263,   979,   313,   153,   381,   467,  1252,   991,   162,   609,
    1610,  1474,   152,  1869,   152,   605,   269,   383,   152,  1373,
     685,   984,  1185,  1722,  1375,   265,   525,   166,   318,  1442,
     319,   269,   415,   275,   141,   393,  1000,  1994,   270,  1750,
       5,  1409,  1142,   712,  1009,   155,   342,   156,   721,     4,
     580,   581,   317,   987,  1092,   438,   580,   581,   152,  1143,
     265,  1210,   437,   697,  1211,   341,  1282,  1144,  1145,  1146,
    1142,   869,   582,  1147,  1148,   659,   377,   661,   580,   581,
    1496,   138,   314,   580,   581,   673,   547,  1143,   411,   559,
     560,   561,   710,   580,   581,  1144,  1145,  1146,  1789,   876,
     711,  1147,  1148,  1235,   880,   285,  1975,   547,  1977,   580,
     581,   416,   716,   418,  1361,   320,   426,   426,   580,   581,
     717,   666,   405,   406,   432,  1796,  1365,   601,   602,   603,
     286,   460,   580,   581,   139,   439,  1097,  1410,  1411,  1379,
     294,   296,   323,   299,   616,   324,   287,   288,   391,   580,
     581,   426,   392,  1719,  1967,   137,   265,  1377,   325,   265,
     580,   581,   290,   291,   265,   426,  1253,  1254,  1255,  1256,
    1826,   580,   581,   970,   292,  1374,   281,  1235,   293,   282,
    1376,  1827,   140,   315,   977,  1577,   580,   581,   263,  1629,
     686,   687,  1828,   580,   581,  1611,   108,   143,   526,  1443,
    1444,  1688,   108,   405,   406,   414,   144,  1829,   719,   108,
     424,   427,  1339,   265,  1830,  1235,   720,   508,  1378,   108,
     145,   108,   558,   992,   993,   108,   265,   992,   993,   265,
     524,   935,   565,  1088,   339,   523,   570,   690,  1089,   691,
     692,   316,   382,   163,   265,   455,  1257,   265,   265,   265,
     265,  1883,   606,  1245,   690,   384,   691,   265,   136,   468,
    1186,   265,   167,   341,   865,   108,   867,   868,   394,  1560,
    1561,   142,   395,   713,  1995,   714,  1236,  1239,   722,   715,
     714,   343,   146,   881,   723,   147,   265,   265,   265,   527,
     405,   406,   155,   698,   156,   699,   677,  -527,   155,   700,
     156,   580,   581,   265,   417,  1921,   724,  1080,   401,   402,
     403,   404,   725,   405,   406,   720,   548,   183,   549,  1070,
     184,   915,   550,   185,   580,   581,   805,   580,   581,   580,
     581,  1990,   405,   406,   405,   406,   186,   548,   135,   549,
     800,  1238,   136,   550,  1273,  1831,   674,   675,   405,   406,
     148,   667,   759,   668,   580,   581,   300,   669,   949,  1266,
     149,  1218,   688,  -530,   727,  1278,   426,   265,   575,   576,
     725,   265,   265,   759,   150,  1952,   584,   589,   401,   402,
     403,   404,   401,   402,   403,   404,   155,   265,   156,   401,
     402,   403,   978,   701,   401,   402,   403,   404,   151,   707,
    1142,   159,   405,   406,   178,  1858,   405,   406,   580,   581,
    1326,   810,  1327,  1859,   732,  1602,  1603,  1143,   405,   406,
     401,   402,   403,   404,  1337,  1144,  1145,  1146,   309,  1953,
     310,  1147,  1148,    60,    61,    62,    63,   160,  2017,   265,
     580,   581,   690,   301,   691,   580,   581,   302,    74,   161,
    1085,    77,   797,   303,   304,   164,   305,   306,   165,   558,
     670,  1954,   265,   580,   581,  1880,  1955,   580,   581,   265,
     790,   580,   581,   923,   426,   307,   426,   265,   426,   426,
     432,   168,   803,   583,   265,   265,   426,   426,   265,   154,
    2056,   154,  1956,   265,   809,   169,   811,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,  2004,   544,   545,   265,   546,
     580,   581,   546,  1142,   840,  1715,   290,   291,  1884,  1885,
     170,  1422,   580,   581,  1886,   580,   581,  1426,   292,   181,
    1143,  2001,   298,   265,   265,   580,   581,   938,  1144,  1145,
    1146,   171,   172,  2002,  1147,  1148,  2011,   580,   581,  1131,
     418,   418,   626,   690,   136,   691,  2040,   707,   794,   179,
     796,   720,   798,   799,   492,   173,   493,  1142,  2041,   274,
     806,   807,   233,   180,  1464,   234,   174,   235,   707,   265,
     265,   265,   591,   182,  1143,  1476,   592,   690,    41,   691,
     175,  1481,  1144,  1145,  1146,  1188,   758,   176,  1147,  1148,
     759,   432,   426,   432,   426,   426,   426,   426,   426,   426,
     177,   426,   426,   426,   426,   937,   188,   426,   426,   426,
     154,   943,  1018,   267,   265,   942,  1888,  1889,   707,   972,
     707,   276,  1886,   950,   277,   284,   278,   580,   581,   155,
     814,   156,   707,   266,   759,  1091,   283,   279,  1092,   872,
     873,  1554,   678,   590,   576,   679,   405,   406,   680,   265,
     681,   848,   268,  -529,   981,   759,   539,   540,   664,   542,
     543,   544,   545,   690,   289,   691,   953,   546,   265,   996,
     759,  1208,  2042,   690,   265,   691,   959,   432,  1007,   271,
     960,   759,   272,  1011,   273,   426,   922,   297,   924,   925,
     926,   927,   928,   929,   308,   931,   932,   933,   934,   327,
     312,   939,   940,   941,   664,   542,   543,   544,   545,   311,
     405,   406,   321,   546,   265,  1095,   265,  -534,  1652,   759,
    1620,  1126,  -531,   322,  1127,   759,   328,   329,   759,  1170,
    1630,  1171,  1172,   759,  1123,   759,   759,  1214,   334,  1248,
    1315,   759,  1639,   759,   759,   690,   335,   691,   265,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,  1981,  1336,  1344,   346,   546,   759,
     759,  1005,  1358,  1700,   336,  1701,   759,  1106,  1472,  1013,
    1517,   347,   759,  1548,   759,  1117,  1636,   759,  1731,   265,
    1637,  1777,   759,  1790,  1809,  1778,  1810,  1791,   759,  1378,
     759,  1825,   265,  1855,  1864,  1778,   337,   720,  1865,  1878,
     265,   344,   345,  1778,  1910,   152,   349,   348,   759,   265,
     690,  2024,   691,   845,   707,  1935,   707,   707,  1943,  1778,
    1951,  1965,   759,  2007,   759,  1778,   390,   759,   378,  2008,
     707,  2009,  1378,   759,   396,   759,  2010,  2012,  1241,  2014,
     759,   759,  2035,  1865,   389,   422,  1778,   350,   351,   352,
     353,   354,   355,   356,   357,   358,  1107,  1217,  1108,  1218,
     359,   360,   361,   362,   707,   421,   397,  2043,   363,   364,
     365,   759,  2053,   366,  2064,   367,  2054,  2067,  1778,   136,
     435,  2068,  1228,  1540,   437,  1541,   368,   443,  1619,   369,
    1620,   447,  1237,  1240,   461,   500,   466,   503,   707,   507,
     506,  1251,   509,   512,   513,   514,   569,   265,   555,   556,
     392,   563,  1450,   607,   566,   571,   573,   574,  1134,   593,
     594,  1247,   595,   596,   610,  1140,   265,   399,   597,  1151,
     598,   599,   604,   611,   621,   608,   265,   617,  1711,  1712,
     612,   426,  1291,  1292,   613,  1294,  1295,  1296,   614,  1298,
    1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,   615,
     618,   619,   622,   629,   628,   637,   638,   265,   265,   639,
     265,   265,   265,   650,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   651,   653,   265,   655,   654,   656,
     658,   657,   660,   676,   370,   371,   372,   682,   689,  1319,
     695,   696,   702,   135,   729,   373,   755,   152,   349,   374,
     733,   375,   108,   750,   734,   761,   762,   791,  1331,   546,
     815,   817,   843,   852,   265,   426,   426,   853,  1338,  1340,
     856,   859,   863,  1345,   864,  1272,   866,   405,   406,   892,
     894,   913,   895,   265,  -528,   897,  1465,   905,   916,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   265,   265,
     952,   958,   359,   360,   361,   362,   962,   963,  1290,   964,
     363,   364,   365,   965,   966,   366,   974,   367,   973,   975,
     707,   985,   986,   999,   989,  1390,  1001,  1004,   368,  1010,
    1012,   369,  1623,  1015,  1019,  1016,  1625,  1020,  1021,  1401,
    1402,  1403,  1023,  1024,  1025,  1027,  1028,  1029,  1030,  1031,
     265,  1032,  1033,  1034,  1035,  1036,  1635,  1039,  1043,  1320,
    1321,  1068,  1069,  1096,   265,   265,   265,  1077,  1090,   399,
    1078,  1079,  1084,  1099,  1103,   265,  1111,  1112,  1118,  1120,
     426,  1129,  1137,  1138,   426,  1163,  1141,  1165,  1434,  1177,
    1485,  1178,  1490,   426,  1179,   426,  1180,  1193,   426,  1191,
    1192,  1196,  1204,  1206,  1207,  1213,  1216,  1221,  1220,  1428,
    1222,  1227,  1219,   265,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,  1892,  1338,  1340,
    1225,   546,   341,  1226,  1243,  1244,   370,   371,   372,  1263,
    1249,  1250,  1269,  1270,  1274,  1277,  1489,   373,  1281,  1284,
    1280,   374,   426,   375,   108,  1500,  1293,  1297,  1309,  1504,
    1322,  1347,  1330,  1348,  1349,  1352,  1354,  1353,  1355,  1356,
    1357,   265,  1359,  1366,  1414,  1367,  1370,  1372,  1416,  1371,
     265,  1381,  1382,   690,   265,   691,  1640,  1420,  1383,  1421,
    1384,  1385,  1423,  1386,  1387,  1388,  1389,  1392,  1393,  1394,
    1395,  1396,  1644,  1644,  1397,  1398,  1399,  1404,  1412,  1549,
    1550,  1551,  1417,  1424,  1427,  1418,  1441,  1556,  1425,  1429,
    1433,  1446,  1435,  1447,  1453,  1449,  1452,  1457,  1459,  1460,
    1461,  1463,  1571,  1618,   265,   265,   265,  1473,  1477,  1479,
    1492,  1494,   265,  1579,  1766,  1493,  1466,  1495,  1497,  1501,
    1502,  1587,  1503,  1505,  1507,  1508,  1509,   265,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1526,  1533,  1537,   265,  1543,
     152,   349,  1552,  1547,  1568,  1553,   265,  1557,  1559,   265,
    1573,  1574,  1588,  1593,  1594,  1595,  1558,  1599,  1600,  1601,
    1627,  1667,  1565,  1566,  1567,  1633,  1580,  1581,  1582,  1653,
    1583,  1584,  1585,  1590,  1654,  1615,  1631,  1646,  1656,  1605,
    1608,  1211,   350,   351,   352,   353,   354,   355,   356,   357,
     358,  1659,  1622,  1650,  1662,   359,   360,   361,   362,  1651,
    1632,  1626,  1668,   363,   364,   365,   341,  1661,   366,  1675,
     367,  1665,   432,   432,  1676,  1666,  1677,  1678,   265,  1680,
    1681,   368,  1682,  1679,   369,  1687,  1092,  1694,  1695,  1697,
    1720,  1716,   426,  1721,  1730,  1734,  1752,  1753,  1576,  1706,
     265,  1754,  1762,  1763,  1765,   265,  1770,   720,  -532,  1782,
    1788,  1793,  1794,   465,  1795,  1808,  1801,  1769,  1806,  1807,
    1813,  1814,   399,  1820,  1834,  1822,  1816,  1817,  1823,  1832,
    1839,  1849,  1846,  1851,  1840,  1852,  1854,  1693,  1856,  1847,
    1848,  1743,  1853,  1857,  1877,  1862,  1699,  1895,  1748,  1751,
    1900,  1896,  1911,  1912,  1914,  1922,  1898,  1939,  1913,  1942,
    1929,  1946,  1947,  -533,  1958,  1916,  1959,  1760,  1933,  1925,
    1926,   265,  1650,  1961,   265,   265,  1944,  1973,  1931,  1936,
    1940,  1950,  1962,   418,   418,  1978,  1660,  1735,  1915,   370,
     371,   372,  1983,  1969,  2025,  2026,  2027,   265,   554,  2028,
     373,  1997,  2013,   265,   374,  2030,   375,   108,  2031,  2032,
    2033,  2036,   265,  2047,  2048,  2052,  1674,  2060,  1759,  2065,
    2055,  2066,   426,  2069,  2070,   426,  1991,  1475,  1529,  1870,
     728,  1768,  1673,  1843,  1696,  1499,   113,   988,   124,  1640,
     125,   126,   707,   265,   707,  1890,  1960,  1693,  1617,   132,
    1247,  1645,     0,   855,   341,  1006,   265,   432,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,  1650,     0,  1764,  1749,   546,     0,
       0,     0,     0,  1982,     0,     0,   432,     0,     0,     0,
       0,     0,  1844,     0,     0,     0,     0,     0,     0,   265,
    1723,  1724,  1725,  1726,  1727,  1729,     0,     0,  1821,     0,
    1407,     0,     0,     0,     0,     0,  1744,     0,     0,  1746,
       0,   671,     0,     0,     0,     0,     0,     0,     0,     0,
    1874,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1863,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1871,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
    1650,     0,     0,     0,     0,   265,     0,     0,     0,     0,
    1875,     0,     0,     0,  1897,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,   265,     0,
       0,     0,   418,     0,     0,     0,     0,     0,     0,   265,
       0,     0,     0,   265,     0,     0,     0,   812,     0,     0,
       0,     0,     0,     0,  1650,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1968,     0,   341,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1938,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1738,     0,     0,   860,   861,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   707,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,  1408,   901,   902,   903,  1902,  1903,  1904,  1905,
    1906,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     265,   265,   265,   265,     0,     0,     0,     0,     0,   707,
       0,     0,     0,     0,     0,     0,     0,  1650,   944,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   707,     0,     0,  1937,     0,     0,     0,  1941,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,   694,
       0,     0,     0,   976,     0,     0,   387,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1650,
       0,     0,   995,     0,     0,     0,     0,     0,  1002,     0,
     426,     0,     0,   413,     0,  1974,     0,   423,     0,  1976,
       0,   428,   527,     0,   265,     0,     0,     0,     0,     0,
       0,   426,   426,     0,     0,  1988,     0,     0,   440,   441,
     442,     0,   444,   445,   446,   426,   448,   449,   450,   451,
     452,   453,   454,     0,   456,   457,   458,   459,     0,     0,
       0,   463,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
    2022,  2023,  1071,     0,   546,     0,     0,     0,     0,     0,
    1739,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2045,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1102,     0,  2061,  2063,   515,   517,   519,
     520,   463,     0,     0,     0,     0,  1110,     0,     0,  2071,
       0,     0,     0,     0,     0,   553,   463,     0,     0,     0,
       0,     0,     0,  1128,     0,     0,     0,     0,     0,     0,
       0,   568,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   578,   579,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,     0,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
     620,   546,     0,     0,   623,   624,   625,     0,   627,     0,
       0,     0,   630,   631,   632,     0,     0,   633,     0,   464,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   757,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,   690,     0,   691,     0,     0,     0,
       0,     0,     0,     0,     0,   663,     0,     0,     0,   463,
     672,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1271,     0,     0,     0,     0,     0,   683,   684,     0,     0,
       0,     0,     0,     0,     0,     0,   518,     0,     0,   464,
     708,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,     0,     0,     0,     0,     0,
       0,     0,   738,     0,     0,     0,   742,     0,     0,     0,
    1310,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     756,   517,     0,     0,     0,   760,     0,     0,   763,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   773,   774,
     775,   776,   777,   778,   779,   781,   782,   783,   784,   785,
     786,   787,   787,     0,   792,   793,     0,   795,     0,     0,
       0,     0,     0,   801,     0,   804,     0,     0,     0,     0,
     787,     0,     0,     0,     0,   463,     0,     0,     0,     0,
       0,     0,     0,  1346,     0,   709,   818,   819,   820,   821,
     822,   823,   824,   825,   826,   827,   828,   829,   830,   831,
     833,   835,   836,   837,   838,   839,     0,   841,   842,     0,
    1234,     0,     0,     0,   849,   850,   851,   464,     0,     0,
       0,     0,   857,   858,     0,   463,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   515,   663,   877,     0,     0,     0,
     882,   883,   884,   885,   886,   887,   888,   889,   890,  1413,
       0,     0,     0,   896,     0,   898,     0,   899,     0,     0,
       0,   463,   463,   463,   904,     0,   906,   907,   908,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   930,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   780,     0,     0,     0,   463,     0,     0,   788,
     789,   947,     0,   948,     0,     0,   841,   842,     0,     0,
       0,     0,     0,     0,     0,   961,     0,     0,   808,     0,
       0,   967,     0,   464,     0,  1308,     0,     0,     0,     0,
       0,   463,     0,     0,     0,     0,     0,   982,   983,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   834,     0,
     463,     0,   997,   998,     0,     0,   463,  1003,  1350,     0,
       0,   997,     0,     0,     0,  1391,     0,     0,  1014,     0,
       0,     0,  1017,   464,   464,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,  1037,     0,   833,   546,  1040,     0,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,   464,
     464,   464,   546,     0,     0,     0,     0,     0,     0,     0,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1589,     0,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,   464,     0,     0,   546,     0,     0,
       0,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   463,     0,     0,     0,     0,     0,
       0,  1116,     0,     0,     0,  1122,     0,     0,     0,   464,
       0,   463,     0,     0,     0,     0,     0,     0,     0,  1135,
    1136,     0,     0,     0,     0,  1139,     0,     0,   464,     0,
       0,     0,     0,     0,   464,     0,     0,     0,     0,     0,
       0,  1164,     0,     0,  1166,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,  1181,     0,  1183,  1184,   546,     0,     0,
       0,     0,     0,     0,   834,     0,  1041,     0,     0,     0,
       0,     0,     0,     0,  1202,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,  1224,     0,   546,   464,     0,
       0,     0,  1230,  1231,  1232,  1233,     0,     0,  1702,  1703,
    1242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1267,  1268,     0,     0,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1312,  1313,  1314,     0,     0,     0,
       0,  1316,  1317,  1432,  1318,     0,     0,     0,     0,     0,
       0,     0,     0,  1324,  1325,     0,     0,     0,     0,     0,
       0,  1328,  1329,     0,     0,     0,     0,     0,  1333,  1334,
    1335,     0,     0,     0,     0,     0,  1341,  1342,     0,     0,
       0,   463,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    38,    39,    40,    41,   157,   158,
      43,     0,  1369,     0,     0,     0,   703,    49,     0,     0,
      51,   704,  1837,    54,   705,     0,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,  1400,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   463,     0,     0,
       0,     0,     0,     0,     0,  1415,    85,    86,    87,     0,
       0,     0,     0,     0,     0,     0,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1341,  1342,  1448,     0,
       0,  1431,  1891,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1440,     0,  1901,  1445,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     412,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1467,     0,     0,  1470,  1471,
       0,   878,     0,     0,     0,     0,  1478,     0,  1480,   464,
    1478,  1484,     0,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   494,   495,   496,   497,   498,   499,     0,
     501,   502,     0,     0,     0,     0,   504,   505,     0,     0,
       0,     0,     0,  1555,     0,   464,   510,   511,     0,     0,
    1562,  1563,  1564,  1984,  1985,  1986,  1987,  1989,     0,  1570,
       0,  1572,     0,     0,     0,     0,     0,     0,  1575,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   463,     0,     0,     0,     0,  1591,     0,     0,     0,
       0,     0,     0,     0,  1596,  1597,  1598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1609,     0,     0,     0,
       0,     0,  2029,     0,     0,     0,  1621,     0,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,   379,   349,
     546,     0,  1638,     0,     0,     0,  1569,     0,  1647,  1648,
       0,     0,     0,     0,     0,     0,   634,   635,   636,     0,
       0,     0,   640,   641,   642,   643,   644,   645,   646,     0,
     647,     0,     0,     0,   648,   649,     0,  1671,   652,     0,
     350,   351,   352,   353,   354,   355,   356,   357,   358,     0,
       0,   662,     0,   359,   360,   361,   362,     0,     0,     0,
       0,   363,   364,   365,     0,     0,   366,     0,   367,     0,
       0,     0,  1683,  1684,  1685,     0,     0,     0,     0,   368,
       0,     0,   369,  1686,     0,     0,     0,     0,  1689,  1690,
    1691,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1698,     0,     0,     0,     0,   463,   463,  1704,   464,
    1705,     0,     0,     0,     0,     0,  1713,  1714,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,     0,     0,     0,  1732,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1742,     0,     0,  1745,     0,     0,     0,  1747,
       0,     0,     0,     0,     0,     0,     0,     0,  1690,  1691,
       0,  1756,     0,     0,  1624,     0,     0,     0,     0,  1761,
       0,     0,     0,     0,     0,     0,     0,   370,   371,   372,
     816,     0,     0,     0,     0,  1774,     0,     0,   373,     0,
    1780,  1781,   374,     0,   375,  1672,     0,     0,  1628,     0,
    1783,     0,     0,  1784,  1783,   693,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,  1805,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1815,
       0,     0,     0,     0,     0,     0,     0,     0,  1824,     0,
       0,     0,     0,     0,   464,   464,     0,   517,     0,     0,
       0,     0,     0,     0,     0,     0,  1835,  1836,     0,     0,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   464,     0,     0,     0,     0,   802,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1860,  1861,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1873,     0,     0,  1876,     0,     0,     0,     0,  1879,     0,
       0,  1881,     0,     0,     0,   846,     0,     0,     0,     0,
     463,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,     0,     0,     0,     0,
       0,     0,     0,  1907,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,  1918,     0,
    1634,     0,     0,     0,  1923,     0,     0,  1924,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,  1733,     0,     0,     0,
     546,     0,     0,  1945,     0,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1963,  1964,
    1812,     0,     0,     0,     0,     0,     0,  1093,     0,     0,
    1970,  1971,     0,  1972,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1838,  1980,     0,     0,     0,
       0,   463,   463,   463,   463,   463,     0,     0,     0,     0,
    1109,  1780,     0,     0,     0,  1996,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2016,   464,     0,     0,     0,  2019,  2020,  2021,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     463,     0,     0,     0,     0,     0,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,     0,  1056,  1057,
    1058,  1059,     0,  1061,  1062,  1063,  1064,     0,  2049,  2050,
    2051,     0,     0,     0,     0,     0,     0,  1074,     0,  1076,
       0,     0,     0,     0,     0,     0,  1082,     0,     0,     0,
    1086,  1087,     0,     0,     0,     0,     0,     0,     0,  1098,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,   464,
     464,   464,   464,   464,     0,     0,     0,  1283,     0,     0,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,  1187,  1189,  1190,   546,   464,     0,
    1194,  1195,     0,     0,  1198,  1199,  1200,  1201,     0,  1203,
       0,     0,     0,     0,  1209,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   189,     6,
     349,     0,     0,  1332,     0,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,     0,
       0,  1487,   351,   352,   353,   354,   355,   356,   357,   358,
     222,   223,   224,   225,   359,   360,   361,   362,   226,     0,
    1288,  1289,   363,   364,   365,     0,     0,   366,     0,   367,
     227,   228,   229,     0,     0,     0,     0,     0,   230,    21,
     368,   231,     0,   369,     0,     0,   232,     0,     0,   233,
       0,     0,   234,     0,   235,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,    50,     0,  1850,   237,
       0,   238,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    74,     0,     0,    77,     0,     0,     0,
       0,     0,  1343,     0,     0,  1455,  1456,     0,     0,     0,
       0,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,  1957,   909,     0,   239,   370,   371,
     372,   240,   241,   870,     0,     0,   242,   243,   244,   373,
     245,   246,   247,   374,     0,   375,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,     0,     0,     0,     0,     0,   250,
       0,     0,     0,  1534,   331,     0,     0,     0,  1488,     0,
       0,   253,     0,  1542,   189,   152,     0,     0,     0,     0,
       0,   190,   191,   192,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   385,   211,   212,   213,   214,   215,   216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1454,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,   229,     0,
       0,     0,     0,     0,   230,    21,  1486,   231,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,  1518,  1519,  1520,  1521,  1522,     0,
       0,     0,     0,  1527,  1528,     0,  1530,     0,  1532,     0,
       0,     0,  1536,     0,     0,  1538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1546,     0,     0,
       0,     0,     0,  1669,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,     0,     0,   240,     0,     0,
       0,     0,   242,   243,   244,  2003,   245,   246,   247,     0,
       0,     0,   108,     0,     0,     0,  1604,     0,  1607,     0,
       0,     0,  1614,     0,  1616,     0,     0,     0,   248,   386,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     331,     0,     0,     0,   567,     0,     0,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1641,     0,
       0,     0,     0,     0,     0,     0,   189,     6,   349,     0,
       0,     0,     0,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,  1792,   527,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   222,   223,
     224,   225,   359,   360,   361,   362,   226,     0,     0,     0,
     363,   364,   365,     0,     0,   366,     0,   367,   227,   228,
     229,     0,     0,     0,     0,  1692,   230,    21,   368,   231,
       0,   369,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    50,     0,     0,   237,     0,   238,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,  1928,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,  1771,     0,     0,  1772,     0,
       0,     0,     0,     0,     0,   239,   370,   371,   372,   240,
     241,     0,     0,     0,   242,   243,   244,   373,   245,   246,
     247,   374,   527,   375,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1797,  1798,     0,  1800,
     248,   249,     0,     0,     0,   527,     0,   250,     0,     0,
       0,     0,   331,     0,     0,     0,   252,     0,     0,   253,
       0,     0,     0,     0,     0,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   757,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1841,  1842,
     189,   152,   349,     0,   398,     0,     0,   190,   191,   192,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   385,
     211,   212,   213,   214,   215,   216,   917,     0,     0,     0,
       0,     0,  1872,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   222,   223,   224,   225,   359,   360,   361,   362,
     226,     0,     0,     0,   363,   364,   365,     0,     0,   366,
       0,   367,   227,   228,   229,     0,     0,     0,     0,     0,
     230,    21,   368,   231,     0,   369,     0,     0,     0,     0,
       0,     0,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,     0,     0,
       0,     0,   546,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   757,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,     0,   239,
     370,   371,   372,   240,     0,     0,     0,     0,   242,   243,
     244,   373,   245,   246,   247,   374,     0,   375,   108,   401,
     402,   403,   404,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   386,     0,     0,     0,     0,
       0,   250,     0,   405,   406,     0,   407,     0,   408,     0,
       0,     0,   409,   253,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,   189,     6,   330,     0,   546,     0,     0,   190,
     191,   192,     0,  2038,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,     0,     0,     7,
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
       0,     0,     0,     0,     0,     0,   248,   249,     0,     0,
       0,     0,     0,   250,     0,    85,    86,    87,   331,   189,
       6,  1578,   252,     0,     0,   253,   190,   191,   192,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     900,   227,   228,   229,     0,     0,     7,     8,     0,   230,
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
       0,     0,     0,   248,   249,     0,     0,     0,     0,     0,
     250,     0,    85,    86,    87,   331,   189,     6,     0,   252,
       0,     0,   253,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   945,   227,   228,
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
     585,  1728,     0,     0,     0,     0,     0,   250,     0,    85,
      86,    87,   587,   189,     6,     0,   293,   521,     0,   253,
     190,   191,   192,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   946,   227,   228,   229,     0,     0,
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
       0,     0,     0,     0,   250,     0,    85,    86,    87,   251,
     189,     6,     0,   252,     0,     0,   253,   190,   191,   192,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1130,   227,   228,   229,     0,     0,     7,     8,     0,
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
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,   250,     0,    85,    86,    87,   331,   189,     6,     0,
     252,     0,     0,   253,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
     223,   224,   225,     0,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1132,   227,
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
       0,   248,   462,     0,     0,     0,     0,     0,   250,     0,
      85,    86,    87,   331,   189,     6,     0,   516,     0,     0,
     253,   190,   191,   192,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   223,   224,   225,
       0,     0,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1133,   227,   228,   229,     0,
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
       0,    43,     0,     0,     0,     0,     0,   703,    49,     0,
       0,    51,   704,   239,    54,   705,     0,   240,   241,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   108,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   462,
       0,     0,     0,     0,     0,   250,     0,    85,    86,    87,
     331,   189,     6,     0,     0,   521,     0,   253,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,     0,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1152,   227,   228,   229,     0,     0,     7,     8,
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
       0,     0,     0,     0,     0,   248,   249,     0,     0,     0,
       0,     0,   250,     0,    85,    86,    87,   557,   189,     6,
       0,   252,     0,     0,   253,   190,   191,   192,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1182,
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
       0,    85,    86,    87,   564,   189,     6,     0,   252,     0,
       0,   253,   190,   191,   192,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,   223,   224,
     225,     0,     0,     0,     0,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1215,   227,   228,   229,
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
     462,     0,     0,     0,     0,     0,   250,     0,    85,    86,
      87,   331,   189,     6,     0,   832,     0,     0,   253,   190,
     191,   192,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1360,   227,   228,   229,     0,     0,     7,
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
       0,     0,     0,     0,     0,     0,   248,   249,     0,     0,
       0,     0,     0,   250,     0,    85,    86,    87,   331,   189,
       6,     0,  1586,     0,     0,   253,   190,   191,   192,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1948,   227,   228,   229,     0,     0,     7,     8,     0,   230,
      21,     0,   231,     0,     0,     0,     0,   232,     0,     0,
     233,     0,     0,   234,     0,   235,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,   236,     0,    50,     0,     0,
     237,     0,   238,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,    74,     0,     0,    77,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      38,    39,    40,    41,     0,     0,    43,  1100,     0,     0,
       0,     0,   703,    49,     0,     0,    51,   704,   239,    54,
     705,     0,   240,   241,     0,     0,     0,   242,   243,   244,
       0,   245,   246,   247,     0,     0,     0,   108,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   585,  1728,     0,     0,     0,     0,     0,
     250,     0,    85,    86,    87,   587,   189,     6,     0,   293,
       0,     0,   253,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2005,   227,   228,
     229,     0,     0,     0,     0,     0,   230,    21,     0,   231,
       0,     0,     0,     0,   232,     0,     0,   233,     0,     0,
     234,     0,   235,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    50,     0,     0,   237,     0,   238,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    74,     0,     0,    77,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,     0,     0,     0,   240,
     241,     0,     0,     0,   242,   243,   244,     0,   245,   246,
     247,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   462,     0,     0,     0,     0,     0,   250,   189,   152,
     349,     0,   331,     0,     0,   190,   191,   192,     0,   253,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   385,   211,   212,
     213,   214,   215,   216,  1101,     0,     0,     0,     0,     0,
       0,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     222,   223,   224,   225,   359,   360,   361,   362,   226,     0,
       0,     0,   363,   364,   365,     0,     0,   366,     0,   367,
     227,   228,   229,     0,     0,     0,     0,     0,   230,    21,
     368,   231,     0,   369,   189,   152,   349,     0,     0,     0,
       0,   190,   191,   192,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   385,   211,   212,   213,   214,   215,   216,
       0,     0,     0,     0,     0,     0,     0,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   222,   223,   224,   225,
     359,   360,   361,   362,   226,     0,     0,     0,   363,   364,
     365,     0,     0,   366,     0,   367,   227,   228,   229,     0,
       0,     0,     0,     0,   230,    21,   368,   231,     0,   369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   370,   371,
     372,   240,     0,     0,     0,     0,   242,   243,   244,   373,
     245,   246,   247,   374,     0,   375,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   386,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   331,     0,     0,     0,  1483,     0,
       0,   253,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   370,   371,   372,   240,     0,     0,
       0,     0,   242,   243,   244,   373,   245,   246,   247,   374,
       0,   375,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   386,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     331,   189,   152,   349,  1741,     0,     0,   253,   190,   191,
     192,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     385,   211,   212,   213,   214,   215,   216,  1406,     0,     0,
       0,     0,     0,     0,  1487,   351,   352,   353,   354,   355,
     356,   357,   358,   222,   223,   224,   225,   359,   360,   361,
     362,   226,     0,     0,     0,   363,   364,   365,     0,     0,
     366,     0,   367,   227,   228,   229,     0,     0,     0,     0,
       0,   230,    21,   368,   231,     0,   369,   189,   152,   349,
       0,     0,     0,     0,   190,   191,   192,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   385,   211,   212,   213,
     214,   215,   216,     0,     0,     0,     0,     0,     0,     0,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   222,
     223,   224,   225,   359,   360,   361,   362,   226,     0,     0,
       0,   363,   364,   365,     0,     0,   366,     0,   367,   227,
     228,   229,     0,     0,     0,     0,     0,   230,    21,   368,
     231,     0,   369,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   370,   371,   372,   240,     0,     0,     0,     0,   242,
     243,   244,   373,   245,   246,   247,   374,     0,   375,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   386,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,   331,     0,     0,
       0,  1640,     0,     0,   253,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   370,   371,   372,
     240,     0,     0,     0,     0,   242,   243,   244,   373,   245,
     246,   247,   374,     0,   375,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   386,     0,     0,     0,     0,     0,   250,   189,
     152,     0,     0,   331,     0,     0,   190,   191,   192,     0,
     253,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   385,   211,
     212,   213,   214,   215,   216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,     0,     0,   189,   152,     0,   230,
      21,     0,   231,   190,   191,   192,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   385,   211,   212,   213,   214,
     215,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   223,
     224,   225,     0,     0,     0,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,   228,
     229,     0,     0,     0,     0,     0,   230,    21,     0,   231,
       0,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   690,     0,   691,   239,     0,
       0,     0,   240,  1606,     0,     0,     0,   242,   243,   244,
       0,   245,   246,   247,     0,     0,     0,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   585,   586,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,   587,     0,     0,     0,   293,
       0,     0,   253,     0,     0,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,   239,     0,   546,     0,   240,
       0,     0,     0,  1709,   242,   243,   244,  1710,   245,   246,
     247,     0,     0,     0,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   386,     0,     0,     0,     0,     0,   250,   189,   152,
       0,  1223,   331,  1008,     0,   190,   191,   192,     0,   253,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   385,   211,   212,
     213,   214,   215,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,   228,   229,     0,     0,     0,     0,     0,   230,    21,
       0,   231,   189,   152,     0,  1368,     0,     0,     0,   190,
     191,   192,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   385,   211,   212,   213,   214,   215,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   223,   224,   225,     0,     0,
       0,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,     0,     0,     0,
       0,     0,   230,    21,     0,   231,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,   239,     0,   546,
       0,   240,     0,     0,     0,  1736,   242,   243,   244,  1737,
     245,   246,   247,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   386,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
       0,   253,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1893,   239,     0,     0,  1894,   240,     0,     0,     0,     0,
     242,   243,   244,     0,   245,   246,   247,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   386,     0,     0,
       0,     0,     0,   250,   189,   152,     0,  1430,   331,     0,
       0,   190,   191,   192,     0,   253,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   385,   211,   212,   213,   214,   215,   216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   230,    21,     0,   231,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,   239,     0,     0,     0,   240,   718,     0,
       0,     0,   242,   243,   244,     0,   245,   246,   247,     0,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   386,
       0,     0,     0,     0,     0,   250,     0,     0,     0,     0,
     331,     0,     0,     0,     0,     0,     0,   253,     0,     0,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
     239,     0,   546,     0,   240,     0,     0,     0,     0,   242,
     243,   244,   870,   245,   246,   247,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   386,     0,     0,     0,
       0,     0,   250,   189,   152,     0,     0,   331,  1482,     0,
     190,   191,   192,     0,   253,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   385,   211,   212,   213,   214,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,   223,   224,   225,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   229,     0,     0,
     189,   152,     0,   230,    21,     0,   231,   190,   191,   192,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   385,
     211,   212,   213,   214,   215,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,     0,     0,     0,     0,
     226,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,     0,     0,     0,     0,     0,
     230,    21,     0,   231,     0,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,   239,     0,     0,     0,   240,   871,     0,     0,
       0,   242,   243,   244,     0,   245,   246,   247,     0,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   386,     0,
       0,     0,     0,     0,   250,     0,     0,     0,     0,   331,
    1785,     0,     0,     0,     0,     0,   253,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,     0,     0,     0,     0,     0,     0,   239,
       0,     0,     0,   240,     0,     0,     0,     0,   242,   243,
     244,     0,   245,   246,   247,     0,     0,     0,   108,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   386,     0,     0,     0,     0,
       0,   250,    -4,    -4,    -4,     0,   331,     0,    -4,    -4,
       0,    -4,     0,   253,     0,     0,    -4,    -4,     0,    -4,
      -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     7,     8,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,     9,    10,     0,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,    11,    12,    13,     0,     0,     0,    14,
      15,     0,    16,     0,     0,     0,     0,    17,    18,     0,
      19,    20,     0,    21,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,    37,    38,    39,    40,    41,
      42,     0,    43,     0,    44,    45,    46,    47,    48,    49,
      50,     0,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    80,    81,    82,     0,
       0,     0,    83,     0,     0,     0,     0,    84,    85,    86,
      87,   152,   349,    88,     0,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   152,   349,     0,     0,     0,     0,     0,   107,     0,
     108,     0,     0,   350,   351,   352,   353,   354,   355,   356,
     357,   358,     0,     0,     0,     0,   359,   360,   361,   362,
       0,     0,   349,     0,   363,   364,   365,     0,     0,   366,
       0,   367,     0,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   368,     0,     0,   369,   359,   360,   361,   362,
       0,     0,     0,     0,   363,   364,   365,     0,     0,   366,
       0,   367,     0,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   368,     0,     0,   369,   359,   360,   361,   362,
       0,     0,     0,   399,   363,   364,   365,     0,     0,   366,
       0,   367,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   368,     0,     0,   369,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   914,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,     7,     8,     0,     0,     0,     0,     0,
       0,   373,     0,     0,     0,   374,     0,   375,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,     0,     0,     0,     0,     0,     0,     0,
       0,   373,     0,     0,     0,   374,     0,   375,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,   371,   372,     0,     0,     0,     0,     0,     7,     8,
       0,   373,     0,     0,     0,   374,     0,   375,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    38,    39,    40,
      41,     0,     0,    43,     0,     0,     0,     0,     0,   703,
      49,     0,     0,    51,   704,     0,    54,   705,     0,     0,
       0,     0,   955,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,   956,
       0,     0,     0,     0,     0,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    85,
      86,    87,    38,    39,    40,    41,     0,     0,    43,     0,
       0,     0,     0,     0,   703,    49,     0,     0,    51,   704,
       0,    54,   705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,    85,    86,    87,     0,     0,     0,
       0,     0,     0,  1055,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1065,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1066,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1067,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1072,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1073,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1075,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1176,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1197,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1279,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1362,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1363,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1405,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1523,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1524,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1525,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1539,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1664,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1775,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1776,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1799,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1802,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1868,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1919,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1920,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1932,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1934,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1966,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1993,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1998,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1999,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2000,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2039,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,   754,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,   990,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  1042,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  1083,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,  1124,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,  1155,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1173,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1229,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1364,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  1436,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  1437,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,  1438,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  1439,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  1707,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,  1718,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,  1755,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  1818,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  1833,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    1845,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  1882,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,     0,  1899,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,     0,     0,  1908,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,     0,  1909,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,  1930,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,     0,  1979,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,     0,     0,  2018,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
       0,     0,  2037,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,     0,
       0,  2057,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,     0,     0,
    2058,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,     0,     0,  2059,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,     0,   665,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,     0,   862,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,     0,  1811,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,   690,     0,
     691,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,   920,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,   969,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,  1105,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,  1168,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,  1169,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
       0,     0,  1174,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   664,   542,   543,   544,
     545,     0,     0,     0,     0,   546,     0,     0,     0,  1175,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   664,   542,   543,   544,   545,     0,     0,
       0,     0,   546,     0,     0,     0,  1265,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     664,   542,   543,   544,   545,     0,     0,     0,     0,   546,
       0,     0,     0,  1276,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   664,   542,   543,
     544,   545,     0,     0,     0,     0,   546,     0,     0,     0,
    1468,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,     0,     0,  1545,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   664,   542,   543,   544,   545,     0,     0,     0,     0,
     546,     0,     0,     0,  1592,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   664,   542,
     543,   544,   545,     0,     0,     0,     0,   546,     0,     0,
       0,  1767,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   664,   542,   543,   544,   545,
       0,     0,     0,     0,   546,     0,     0,     0,  1804,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   664,   542,   543,   544,   545,     0,     0,     0,
       0,   546,     0,     0,     0,  1819,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     735,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   736,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     737,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   739,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     740,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   741,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     743,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   744,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     745,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   746,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     747,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   748,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     749,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   751,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     752,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   753,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     813,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   847,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     891,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   909,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     910,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   911,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     912,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   918,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     919,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,   954,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
     968,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1022,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1026,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1038,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1104,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1113,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1114,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1115,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1125,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1154,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1156,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1157,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1158,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1159,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1160,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1161,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1162,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1167,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1264,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1275,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1469,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1531,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1544,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1655,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1657,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1658,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1663,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1708,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1717,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1740,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1803,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1866,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    1867,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546,     0,  1992,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   664,
     542,   543,   544,   545,     0,     0,     0,     0,   546,     0,
    2034,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   664,   542,   543,   544,   545,     0,
       0,     0,     0,   546
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1754)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,     3,   286,   147,   582,   583,  1149,  1153,     4,
     669,   298,  1327,   685,  1623,     4,  1625,    99,    21,   101,
      48,   693,     4,    21,     5,   187,     4,     6,     4,   316,
       4,     6,     4,  1786,     4,     4,    97,     5,     4,     6,
       4,   700,     7,  1580,     6,    48,     5,     4,     4,     4,
       6,    97,   134,    54,     6,     6,   715,     6,   119,  1610,
       0,     4,   129,     9,   723,   239,     4,   241,     9,     6,
     227,   228,    75,   119,   248,   157,   227,   228,     4,   146,
      83,   245,     9,     9,   248,    88,     7,   154,   155,   156,
     129,   248,   243,   160,   161,   382,    99,   384,   227,   228,
       6,    97,    84,   227,   228,   392,     9,   146,   134,   271,
     272,   273,   240,   227,   228,   154,   155,   156,  1669,   248,
     248,   160,   161,     7,   248,   149,     6,     9,     6,   227,
     228,   134,   240,   135,   248,    91,   139,   140,   227,   228,
     248,     9,   236,   237,   147,  1682,   244,   309,   310,   311,
     174,   179,   227,   228,   239,   158,   815,   100,   101,   248,
      61,    62,    94,    64,   326,    97,   190,   191,   239,   227,
     228,   174,   243,   248,  1927,    14,   179,   244,   110,   182,
     227,   228,   227,   228,   187,   188,   164,   165,   166,   167,
     248,   227,   228,     7,   239,   162,    94,     7,   243,    97,
     162,   248,   239,   185,     7,   244,   227,   228,   236,     7,
     174,   175,   248,   227,   228,   189,   211,     6,   177,   174,
     175,  1536,   211,   236,   237,   134,     6,   248,   240,   211,
     139,   140,   245,   236,   248,     7,   248,   238,  1380,   211,
       6,   211,   270,   222,   223,   211,   249,   222,   223,   252,
     253,   246,   280,   240,   243,   253,   284,   240,   245,   242,
     243,   243,   243,   239,   267,   174,   244,   270,   271,   272,
     273,  1808,   241,   243,   240,   243,   242,   280,   247,   188,
     245,   284,   239,   286,   571,   211,   573,   574,   239,     6,
       7,   243,   243,   239,   243,   241,   968,   969,   239,   245,
     241,   239,     6,   590,   245,   239,   309,   310,   311,     8,
     236,   237,   239,   239,   241,   241,   398,   243,   239,   245,
     241,   227,   228,   326,     4,  1862,   242,   240,   212,   213,
     214,   215,   248,   236,   237,   248,   239,    91,   241,   242,
      94,   628,   245,    97,   227,   228,   508,   227,   228,   227,
     228,  1960,   236,   237,   236,   237,   110,   239,   243,   241,
     503,   245,   247,   245,   240,   248,   394,   395,   236,   237,
       6,   239,   248,   241,   227,   228,     4,   245,   665,   239,
       6,   241,   410,   243,   242,   240,   389,   390,   289,   290,
     248,   394,   395,   248,   241,   248,   297,   298,   212,   213,
     214,   215,   212,   213,   214,   215,   239,   410,   241,   212,
     213,   214,   215,   416,   212,   213,   214,   215,   241,   420,
     129,   239,   236,   237,   243,   240,   236,   237,   227,   228,
    1089,   513,  1091,   248,   437,     6,     7,   146,   236,   237,
     212,   213,   214,   215,  1103,   154,   155,   156,    97,   248,
      99,   160,   161,   133,   134,   135,   136,   239,  1995,   462,
     227,   228,   240,    91,   242,   227,   228,    95,   148,   239,
     248,   151,   500,   101,   102,   239,   104,   105,   239,   507,
     389,   248,   485,   227,   228,  1800,   248,   227,   228,   492,
     493,   227,   228,   636,   497,   123,   499,   500,   501,   502,
     503,   239,   505,   243,   507,   508,   509,   510,   511,   512,
    2047,   514,   248,   516,   512,   239,   514,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   244,   232,   233,   541,   238,
     227,   228,   238,   129,   547,   244,   227,   228,   133,   134,
     239,  1210,   227,   228,   139,   227,   228,  1216,   239,     6,
     146,   248,   243,   566,   567,   227,   228,   649,   154,   155,
     156,   239,   239,   248,   160,   161,   248,   227,   228,   866,
     582,   583,   245,   240,   247,   242,   248,   588,   497,   112,
     499,   248,   501,   502,   239,   239,   241,   129,   248,    91,
     509,   510,    94,    97,  1263,    97,   239,    99,   609,   612,
     613,   614,   239,   243,   146,  1274,   243,   240,   110,   242,
     239,  1280,   154,   155,   156,   248,   244,   239,   160,   161,
     248,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     239,   644,   645,   646,   647,   648,   239,   650,   651,   652,
     653,   654,   734,   243,   657,   653,   133,   134,   659,   685,
     661,    94,   139,   666,    97,    94,    99,   227,   228,   239,
     244,   241,   673,   239,   248,   245,   239,   110,   248,   580,
     581,  1353,    91,   243,   585,    94,   236,   237,    97,   692,
      99,   244,    97,   243,   697,   248,   227,   228,   229,   230,
     231,   232,   233,   240,   243,   242,   244,   238,   711,   712,
     248,   248,   244,   240,   717,   242,   244,   720,   721,    94,
     248,   248,    97,   726,    99,   728,   635,   243,   637,   638,
     639,   640,   641,   642,   239,   644,   645,   646,   647,     4,
      94,   650,   651,   652,   229,   230,   231,   232,   233,    97,
     236,   237,    94,   238,   757,   244,   759,   243,   239,   248,
     241,   244,   243,    97,   244,   248,     4,     4,   248,   244,
    1442,   244,   244,   248,   856,   248,   248,   244,     4,   244,
     244,   248,  1454,   248,   248,   240,   239,   242,   791,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,  1949,   244,   244,     6,   238,   248,
     248,   720,   244,     4,   239,     6,   248,   843,   244,   728,
     244,     6,   248,   244,   248,   853,   244,   248,   244,   832,
     248,   244,   248,   244,   244,   248,   244,   248,   248,  1981,
     248,   244,   845,   244,   244,   248,   239,   248,   248,   244,
     853,   239,   239,   248,   244,     4,     5,   241,   248,   862,
     240,  2006,   242,   243,   865,   244,   867,   868,   244,   248,
     244,   244,   248,   244,   248,   248,   243,   248,   239,   244,
     881,   244,  2024,   248,     6,   248,   244,   244,   970,   244,
     248,   248,   244,   248,   241,     6,   248,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   239,   239,   241,   241,
      59,    60,    61,    62,   915,   243,   247,   244,    67,    68,
      69,   248,   244,    72,   244,    74,   248,   244,   248,   247,
     239,   248,   960,   239,     9,   241,    85,   239,   239,    88,
     241,   239,   968,   969,   239,   239,   243,   239,   949,   119,
     243,   979,   239,   239,   239,   239,     4,   960,   239,   239,
     243,   243,  1245,     6,   243,   243,   243,   243,   869,   239,
     239,   974,   239,   239,     6,   876,   979,   126,   239,   880,
     239,   239,   239,     6,     6,   241,   989,   241,  1565,  1566,
     243,   994,  1020,  1021,   243,  1023,  1024,  1025,   243,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,   243,
     241,   241,     6,   177,   243,   239,   239,  1020,  1021,   239,
    1023,  1024,  1025,   239,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,   239,   239,  1039,     6,   241,     6,
       6,   243,     6,   243,   193,   194,   195,     7,     6,  1077,
     243,     6,   244,   243,    87,   204,     7,     4,     5,   208,
     248,   210,   211,   240,   248,     6,   240,   243,  1096,   238,
     245,    64,     4,     7,  1077,  1078,  1079,     7,  1104,  1105,
     239,     6,   240,  1111,     6,   994,   243,   236,   237,     7,
       6,   174,     7,  1096,   243,     6,   245,     6,   243,    46,
      47,    48,    49,    50,    51,    52,    53,    54,  1111,  1112,
     242,   240,    59,    60,    61,    62,     6,   243,  1019,   243,
      67,    68,    69,   243,   243,    72,     7,    74,   245,     6,
    1131,   241,   239,     4,   243,  1163,     6,     6,    85,     6,
       6,    88,  1429,   240,     7,   241,  1433,     7,     7,  1177,
    1178,  1179,     7,     7,     7,     7,     7,     7,     7,     7,
    1163,     7,     7,     7,     7,     7,  1449,   243,     6,  1078,
    1079,   240,   242,     7,  1177,  1178,  1179,   248,   240,   126,
     248,   248,   248,   243,   245,  1188,     7,   243,     4,     6,
    1193,   245,   244,   244,  1197,     7,   129,     6,  1226,     7,
    1282,     7,  1284,  1206,     7,  1208,   245,   248,  1211,   240,
     240,   248,     9,   248,   240,   242,   245,     7,   177,  1220,
     149,     6,   247,  1226,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,  1814,  1264,  1265,
     244,   238,  1245,   243,     6,     4,   193,   194,   195,   245,
      46,    46,   239,   239,   245,   239,  1284,   204,   239,     4,
     245,   208,  1265,   210,   211,  1293,     7,     7,     7,  1297,
     248,     7,   240,     7,     7,     6,   248,   240,     7,     7,
       7,  1284,     4,   109,  1193,     4,   243,   239,  1197,     6,
    1293,     7,     6,   240,  1297,   242,   243,  1206,     7,  1208,
       7,     7,  1211,     7,     7,     7,     7,   243,     6,     6,
       6,    97,  1455,  1456,     7,     6,     6,     4,     4,  1347,
    1348,  1349,   246,   240,   243,   248,     6,  1355,   248,   243,
     243,     6,   244,     6,   241,     7,     6,     6,   239,   239,
     243,     6,  1370,  1425,  1347,  1348,  1349,     6,   245,     6,
     242,     6,  1355,  1381,  1637,   248,  1265,     6,   123,     6,
       6,  1389,     6,   177,     6,     6,     6,  1370,     6,     6,
       6,     6,     6,     6,     5,   240,   240,     6,  1381,     4,
       4,     5,     4,     6,   241,     6,  1389,   243,     7,  1392,
       6,     6,     6,     6,     6,   173,   243,     6,     6,     6,
       6,  1483,   243,   243,   243,     7,   243,   243,   243,     4,
     243,   243,   243,   243,     6,   240,  1442,   239,     6,   248,
     248,   248,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     6,   243,  1461,     4,    59,    60,    61,    62,   243,
     245,   248,     7,    67,    68,    69,  1449,   239,    72,     6,
      74,   239,  1455,  1456,     6,  1483,     6,     6,  1461,     6,
       5,    85,   243,    95,    88,   240,   248,   243,     6,     6,
       6,   248,  1475,     6,     6,     6,   248,   240,  1379,  1561,
    1483,   248,     6,     4,     6,  1488,     6,   248,   243,     6,
     243,     7,   243,   182,     5,   243,   240,  1640,     6,     6,
       6,   243,   126,     6,   172,     7,   244,   244,   243,     6,
       6,     6,   244,     7,   240,     6,     6,  1543,     6,   244,
     244,  1603,   245,     6,     6,   243,  1554,     6,  1610,  1611,
       6,   244,   240,     6,     6,     6,  1823,     6,   243,     6,
     239,     6,   129,   243,     6,   175,     6,  1629,   240,   244,
     244,  1554,  1580,     6,  1557,  1558,   244,     6,   243,   243,
     243,   243,   243,  1565,  1566,     6,  1475,  1595,  1851,   193,
     194,   195,     6,   240,     6,     6,     6,  1580,   267,     6,
     204,   244,   244,  1586,   208,     6,   210,   211,     6,     6,
     243,     6,  1595,   243,     6,     6,  1497,     6,  1626,     6,
     243,     6,  1605,     6,     6,  1608,  1962,  1273,  1322,  1787,
     434,  1639,  1493,  1752,  1550,  1292,     3,   705,     3,   243,
       3,     3,  1623,  1626,  1625,  1810,  1913,  1653,  1422,     3,
    1633,  1456,    -1,   561,  1637,   720,  1639,  1640,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,  1682,    -1,  1633,  1610,   238,    -1,
      -1,    -1,    -1,  1950,    -1,    -1,  1669,    -1,    -1,    -1,
      -1,    -1,  1754,    -1,    -1,    -1,    -1,    -1,    -1,  1682,
    1581,  1582,  1583,  1584,  1585,  1586,    -1,    -1,  1716,    -1,
       8,    -1,    -1,    -1,    -1,    -1,  1605,    -1,    -1,  1608,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1792,    -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1728,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1741,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1778,    -1,    -1,    -1,    -1,
    1808,    -1,    -1,    -1,    -1,  1788,    -1,    -1,    -1,    -1,
    1793,    -1,    -1,    -1,  1822,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1808,    -1,    -1,  1811,    -1,
      -1,    -1,  1814,    -1,    -1,    -1,    -1,    -1,    -1,  1822,
      -1,    -1,    -1,  1826,    -1,    -1,    -1,   516,    -1,    -1,
      -1,    -1,    -1,    -1,  1862,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1928,    -1,  1851,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1886,  1862,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,   566,   567,    -1,
      -1,    -1,    -1,  1886,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1898,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,   240,   612,   613,   614,  1827,  1828,  1829,  1830,
    1831,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1952,
    1953,  1954,  1955,  1956,    -1,    -1,    -1,    -1,    -1,  1960,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1995,   657,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1982,    -1,    -1,  1885,    -1,    -1,    -1,  1889,    -1,
      -1,    -1,  1995,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,   692,    -1,    -1,   107,    -1,  2011,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2047,
      -1,    -1,   711,    -1,    -1,    -1,    -1,    -1,   717,    -1,
    2033,    -1,    -1,   134,    -1,  1936,    -1,   138,    -1,  1940,
      -1,   142,     8,    -1,  2047,    -1,    -1,    -1,    -1,    -1,
      -1,  2054,  2055,    -1,    -1,  1956,    -1,    -1,   159,   160,
     161,    -1,   163,   164,   165,  2068,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,   176,   177,   178,    -1,    -1,
      -1,   182,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
    2001,  2002,   791,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2033,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   832,    -1,  2054,  2055,   248,   249,   250,
     251,   252,    -1,    -1,    -1,    -1,   845,    -1,    -1,  2068,
      -1,    -1,    -1,    -1,    -1,   266,   267,    -1,    -1,    -1,
      -1,    -1,    -1,   862,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   292,   293,    -1,    -1,    -1,    -1,   298,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
     331,   238,    -1,    -1,   335,   336,   337,    -1,   339,    -1,
      -1,    -1,   343,   344,   345,    -1,    -1,   348,    -1,   182,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,   240,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,   390,
     391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     989,    -1,    -1,    -1,    -1,    -1,   407,   408,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,   447,    -1,    -1,    -1,
    1039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     461,   462,    -1,    -1,    -1,   466,    -1,    -1,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,    -1,   495,   496,    -1,   498,    -1,    -1,
      -1,    -1,    -1,   504,    -1,   506,    -1,    -1,    -1,    -1,
     511,    -1,    -1,    -1,    -1,   516,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1112,    -1,     6,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,    -1,   548,   549,    -1,
       6,    -1,    -1,    -1,   555,   556,   557,   390,    -1,    -1,
      -1,    -1,   563,   564,    -1,   566,   567,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   585,   586,   587,    -1,    -1,    -1,
     591,   592,   593,   594,   595,   596,   597,   598,   599,  1188,
      -1,    -1,    -1,   604,    -1,   606,    -1,   608,    -1,    -1,
      -1,   612,   613,   614,   615,    -1,   617,   618,   619,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   485,    -1,    -1,    -1,   657,    -1,    -1,   492,
     493,   662,    -1,   664,    -1,    -1,   667,   668,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,   511,    -1,
      -1,   682,    -1,   516,    -1,     6,    -1,    -1,    -1,    -1,
      -1,   692,    -1,    -1,    -1,    -1,    -1,   698,   699,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   541,    -1,
     711,    -1,   713,   714,    -1,    -1,   717,   718,   129,    -1,
      -1,   722,    -1,    -1,    -1,     6,    -1,    -1,   729,    -1,
      -1,    -1,   733,   566,   567,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   755,    -1,   757,   238,   759,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,   612,
     613,   614,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     791,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1392,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   657,    -1,    -1,   238,    -1,    -1,
      -1,   832,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   845,    -1,    -1,    -1,    -1,    -1,
      -1,   852,    -1,    -1,    -1,   856,    -1,    -1,    -1,   692,
      -1,   862,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   870,
     871,    -1,    -1,    -1,    -1,   876,    -1,    -1,   711,    -1,
      -1,    -1,    -1,    -1,   717,    -1,    -1,    -1,    -1,    -1,
      -1,   892,    -1,    -1,   895,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   914,    -1,   916,   917,   238,    -1,    -1,
      -1,    -1,    -1,    -1,   757,    -1,   759,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   935,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,   956,    -1,   238,   791,    -1,
      -1,    -1,   963,   964,   965,   966,    -1,    -1,  1557,  1558,
     971,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   985,   986,    -1,    -1,   989,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   832,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   845,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   862,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1039,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1055,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1065,  1066,  1067,    -1,    -1,    -1,
      -1,  1072,  1073,     6,  1075,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1084,  1085,    -1,    -1,    -1,    -1,    -1,
      -1,  1092,  1093,    -1,    -1,    -1,    -1,    -1,  1099,  1100,
    1101,    -1,    -1,    -1,    -1,    -1,  1107,  1108,    -1,    -1,
      -1,  1112,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    22,    23,
     113,    -1,  1143,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,  1741,   126,   127,    -1,   989,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,  1176,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1196,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1039,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1217,  1218,     6,    -1,
      -1,  1222,  1811,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1236,    -1,  1826,  1239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1266,    -1,    -1,  1269,  1270,
      -1,   244,    -1,    -1,    -1,    -1,  1277,    -1,  1279,  1112,
    1281,  1282,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
     224,   225,    -1,    -1,    -1,    -1,   230,   231,    -1,    -1,
      -1,    -1,    -1,  1354,    -1,  1188,   240,   241,    -1,    -1,
    1361,  1362,  1363,  1952,  1953,  1954,  1955,  1956,    -1,  1370,
      -1,  1372,    -1,    -1,    -1,    -1,    -1,    -1,  1379,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1392,    -1,    -1,    -1,    -1,  1397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1405,  1406,  1407,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1417,    -1,    -1,    -1,
      -1,    -1,  2011,    -1,    -1,    -1,  1427,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,     4,     5,
     238,    -1,  1453,    -1,    -1,    -1,     6,    -1,  1459,  1460,
      -1,    -1,    -1,    -1,    -1,    -1,   350,   351,   352,    -1,
      -1,    -1,   356,   357,   358,   359,   360,   361,   362,    -1,
     364,    -1,    -1,    -1,   368,   369,    -1,  1488,   372,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,   385,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,  1523,  1524,  1525,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,  1534,    -1,    -1,    -1,    -1,  1539,  1540,
    1541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1552,    -1,    -1,    -1,    -1,  1557,  1558,  1559,  1392,
    1561,    -1,    -1,    -1,    -1,    -1,  1567,  1568,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1586,    -1,    -1,    -1,  1590,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1603,    -1,    -1,  1606,    -1,    -1,    -1,  1610,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1619,  1620,
      -1,  1622,    -1,    -1,     6,    -1,    -1,    -1,    -1,  1630,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
     524,    -1,    -1,    -1,    -1,  1646,    -1,    -1,   204,    -1,
    1651,  1652,   208,    -1,   210,  1488,    -1,    -1,     6,    -1,
    1661,    -1,    -1,  1664,  1665,   412,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,  1694,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1710,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1719,    -1,
      -1,    -1,    -1,    -1,  1557,  1558,    -1,  1728,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1737,  1738,    -1,    -1,
    1741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1586,    -1,    -1,    -1,    -1,   505,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1775,  1776,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1791,    -1,    -1,  1794,    -1,    -1,    -1,    -1,  1799,    -1,
      -1,  1802,    -1,    -1,    -1,   552,    -1,    -1,    -1,    -1,
    1811,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1826,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1834,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,  1859,    -1,
       6,    -1,    -1,    -1,  1865,    -1,    -1,  1868,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     6,    -1,    -1,    -1,
     238,    -1,    -1,  1894,    -1,  1728,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1741,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1919,  1920,
       6,    -1,    -1,    -1,    -1,    -1,    -1,   811,    -1,    -1,
    1931,  1932,    -1,  1934,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,  1947,    -1,    -1,    -1,
      -1,  1952,  1953,  1954,  1955,  1956,    -1,    -1,    -1,    -1,
     844,  1962,    -1,    -1,    -1,  1966,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1811,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1993,  1826,    -1,    -1,    -1,  1998,  1999,  2000,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2011,    -1,    -1,    -1,    -1,    -1,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   773,    -1,   775,   776,
     777,   778,    -1,   780,   781,   782,   783,    -1,  2039,  2040,
    2041,    -1,    -1,    -1,    -1,    -1,    -1,   794,    -1,   796,
      -1,    -1,    -1,    -1,    -1,    -1,   803,    -1,    -1,    -1,
     807,   808,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   816,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,  1952,
    1953,  1954,  1955,  1956,    -1,    -1,    -1,  1011,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,    -1,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,   921,   922,   923,   238,  2011,    -1,
     927,   928,    -1,    -1,   931,   932,   933,   934,    -1,   936,
      -1,    -1,    -1,    -1,   941,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,  1097,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
    1017,  1018,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,   121,    -1,     6,   124,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,   143,   144,
      -1,    -1,    -1,   148,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,  1109,    -1,    -1,  1249,  1250,    -1,    -1,    -1,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,     6,   240,    -1,   192,   193,   194,
     195,   196,   197,   248,    -1,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,   210,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,  1327,   239,    -1,    -1,    -1,   243,    -1,
      -1,   246,    -1,  1337,     3,     4,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1248,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,  1283,    86,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,  1311,  1312,  1313,  1314,  1315,    -1,
      -1,    -1,    -1,  1320,  1321,    -1,  1323,    -1,  1325,    -1,
      -1,    -1,  1329,    -1,    -1,  1332,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1344,    -1,    -1,
      -1,    -1,    -1,  1487,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,     6,   205,   206,   207,    -1,
      -1,    -1,   211,    -1,    -1,    -1,  1413,    -1,  1415,    -1,
      -1,    -1,  1419,    -1,  1421,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,   243,    -1,    -1,   246,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     7,     8,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,  1542,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,    -1,   124,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,     7,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1642,    -1,    -1,  1645,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,     8,   210,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1683,  1684,    -1,  1686,
     227,   228,    -1,    -1,    -1,     8,    -1,   234,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,   243,    -1,    -1,   246,
      -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1745,  1746,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     8,    -1,    -1,    -1,
      -1,    -1,  1789,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,   238,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,   236,   237,    -1,   239,    -1,   241,    -1,
      -1,    -1,   245,   246,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     3,     4,     5,    -1,   238,    -1,    -1,    10,
      11,    12,    -1,  2020,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    13,
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
       4,     5,   243,    -1,    -1,   246,    10,    11,    12,    -1,
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
     234,    -1,   169,   170,   171,   239,     3,     4,    -1,   243,
      -1,    -1,   246,    10,    11,    12,    -1,    -1,    15,    16,
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
     170,   171,   239,     3,     4,    -1,   243,   244,    -1,   246,
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
      -1,   113,    -1,    -1,    -1,    -1,    -1,   119,   120,    -1,
      -1,   123,   124,   192,   126,   127,    -1,   196,   197,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,   206,   207,    -1,
      -1,    -1,   211,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,   169,   170,   171,
     239,     3,     4,    -1,    -1,   244,    -1,   246,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    75,    76,    77,    -1,    -1,    13,    14,
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
      -1,   243,    -1,    -1,   246,    10,    11,    12,    -1,    -1,
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
     107,   108,   109,   110,    -1,    -1,   113,     8,    -1,    -1,
      -1,    -1,   119,   120,    -1,    -1,   123,   124,   192,   126,
     127,    -1,   196,   197,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,   206,   207,    -1,    -1,    -1,   211,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,
     234,    -1,   169,   170,   171,   239,     3,     4,    -1,   243,
      -1,    -1,   246,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,    -1,    -1,   124,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,   143,   144,    -1,    -1,
      -1,   148,    -1,    -1,   151,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,
     207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,     3,     4,
       5,    -1,   239,    -1,    -1,    10,    11,    12,    -1,   246,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    -1,    88,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,   210,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,   243,    -1,
      -1,   246,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,     3,     4,     5,   243,    -1,    -1,   246,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    -1,    88,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,   210,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,   243,    -1,    -1,   246,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,   210,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,     3,
       4,    -1,    -1,   239,    -1,    -1,    10,    11,    12,    -1,
     246,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,     3,     4,    -1,    83,
      84,    -1,    86,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,    -1,   242,   192,    -1,
      -1,    -1,   196,   248,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,   243,
      -1,    -1,   246,    -1,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,   192,    -1,   238,    -1,   196,
      -1,    -1,    -1,   244,   201,   202,   203,   248,   205,   206,
     207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,     3,     4,
      -1,     6,   239,   240,    -1,    10,    11,    12,    -1,   246,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    83,    84,    -1,    86,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,   192,    -1,   238,
      -1,   196,    -1,    -1,    -1,   244,   201,   202,   203,   248,
     205,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
     244,   192,    -1,    -1,   248,   196,    -1,    -1,    -1,    -1,
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
      -1,     3,     4,    -1,    83,    84,    -1,    86,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,   196,   248,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,   206,   207,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
     192,    -1,   238,    -1,   196,    -1,    -1,    -1,    -1,   201,
     202,   203,   248,   205,   206,   207,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,   234,     3,     4,    -1,    -1,   239,   240,    -1,
      10,    11,    12,    -1,   246,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
       3,     4,    -1,    83,    84,    -1,    86,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,   192,    -1,    -1,    -1,   196,   248,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,   206,   207,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,    -1,    -1,    -1,   211,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,    64,    65,    66,    -1,   239,    -1,    70,    71,
      -1,    73,    -1,   246,    -1,    -1,    78,    79,    -1,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,   106,   107,   108,   109,   110,   111,
      -1,   113,    -1,   115,   116,   117,   118,   119,   120,   121,
      -1,   123,   124,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    -1,     4,    -1,   157,   158,   159,    -1,    -1,
      -1,   163,    13,    14,    -1,    -1,   168,   169,   170,   171,
      -1,    -1,   174,    -1,   176,    -1,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,    -1,    -1,    44,    45,    -1,   198,   199,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,    -1,   211,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,
      81,    82,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,   106,   107,   108,   109,   110,
     111,    -1,   113,    -1,   115,   116,   117,   118,   119,   120,
     121,    -1,   123,   124,   125,   126,   127,   128,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,     4,     5,   174,    -1,   176,    -1,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,   199,   200,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,   209,    -1,
     211,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,     5,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    85,    -1,    -1,    88,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    85,    -1,    -1,    88,    59,    60,    61,    62,
      -1,    -1,    -1,   126,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    88,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,   204,    -1,    -1,    -1,   208,    -1,   210,    -1,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,   119,
     120,    -1,    -1,   123,   124,    -1,   126,   127,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   169,
     170,   171,   107,   108,   109,   110,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,   169,   170,   171,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   248,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
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
      -1,    -1,   238,    -1,    -1,    -1,    -1,   243,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,   243,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,   243,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,   238,    -1,   240,    -1,
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
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,   242,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,   242,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238,    -1,   240,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,   238,    -1,
     240,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,   238
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
     185,   212,   213,   214,   215,   236,   237,   239,   241,   245,
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
       7,   271,   272,   245,     7,     6,   347,     7,   215,   271,
     256,   361,   330,   330,   338,   241,   239,   119,   296,   243,
     244,     6,   222,   223,   253,   347,   361,   330,   330,     4,
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
     100,   101,     4,   347,   351,   330,   351,   246,   248,   287,
     351,   351,   338,   351,   240,   248,   338,   243,   295,   243,
       6,   330,     6,   243,   344,   244,   244,   244,   244,   244,
     330,     6,     4,   174,   175,   330,     6,     6,     6,     7,
     348,   350,     6,   241,   274,   273,   273,     6,   260,   239,
     239,   243,   270,     6,   338,   245,   351,   330,   242,   240,
     330,   330,   244,     6,     6,   253,   338,   245,   330,     6,
     330,   338,   240,   243,   330,   352,   274,    46,   243,   344,
     352,   355,   242,   248,     6,     6,     6,   123,   292,   292,
     344,     6,     6,     6,   344,   177,   291,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   244,   274,   274,
     274,   274,   274,   248,   248,   248,   240,   274,   274,   285,
     274,   240,   274,   240,   273,   333,   274,     6,   274,   248,
     239,   241,   273,     4,   240,   242,   274,     6,   244,   344,
     344,   344,     4,     6,   271,   330,   344,   243,   243,     7,
       6,     7,   330,   330,   330,   243,   243,   243,   241,     6,
     330,   344,   330,     6,     6,   330,   341,   244,     5,   344,
     243,   243,   243,   243,   243,   243,   243,   344,     6,   347,
     243,   330,   242,     6,     6,   173,   330,   330,   330,     6,
       6,     6,     6,     7,   274,   248,   248,   274,   248,   330,
       4,   189,   288,   289,   274,   240,   274,   334,   352,   239,
     241,   330,   243,   301,     6,   301,   248,     6,     6,     7,
     271,   272,   245,     7,     6,   348,   244,   248,   330,   271,
     243,   274,   356,   357,   358,   356,   239,   330,   330,   343,
     344,   243,   239,     4,     6,   240,     6,   240,   240,     6,
     351,   239,     4,   240,   248,   239,   344,   352,     7,   273,
     282,   330,   346,   286,   341,     6,     6,     6,     6,    95,
       6,     5,   243,   330,   330,   330,   330,   240,   333,   330,
     330,   330,   274,   272,   243,     6,   291,     6,   330,   344,
       4,     6,   347,   347,   330,   330,   352,   244,   240,   244,
     248,   300,   300,   330,   330,   244,   248,   240,   244,   248,
       6,     6,   343,   341,   341,   341,   341,   341,   228,   341,
       6,   244,   330,     6,     6,   344,   244,   248,     8,   244,
     240,   243,   330,   352,   351,   330,   351,   330,   352,   355,
     357,   352,   248,   240,   248,   244,   330,   318,   318,   344,
     352,   330,     6,     4,   349,     6,   348,   242,   344,   358,
       6,   274,   274,   257,   330,   248,   248,   244,   248,   258,
     330,   330,     6,   330,   330,   240,   278,   280,   243,   357,
     244,   248,     7,     7,   243,     5,   343,   274,   274,   248,
     274,   240,   248,   240,   242,   330,     6,     6,   243,   244,
     244,   243,     6,     6,   243,   330,   244,   244,   244,   242,
       6,   344,     7,   243,   330,   244,   248,   248,   248,   248,
     248,   248,     6,   244,   172,   330,   330,   347,     6,     6,
     240,   274,   274,   289,   352,   244,   244,   244,   244,     6,
       6,     7,     6,   245,     6,   244,     6,     6,   240,   248,
     330,   330,   243,   344,   244,   248,   240,   240,   248,   283,
     287,   344,   274,   330,   352,   361,   330,     6,   244,   330,
     333,   330,   244,   343,   133,   134,   139,   325,   133,   134,
     325,   347,   300,   244,   248,     6,   244,   344,   301,   244,
       6,   347,   341,   341,   341,   341,   341,   330,   244,   244,
     244,   240,     6,   243,     6,   348,   175,   261,   330,   248,
     248,   343,     6,   330,   330,   244,   244,   279,     7,   239,
     244,   243,   248,   240,   248,   244,   243,   341,   344,     6,
     243,   341,     6,   244,   244,   330,     6,   129,   244,   312,
     243,   244,   248,   248,   248,   248,   248,     6,     6,     6,
     301,     6,   243,   330,   330,   244,   248,   283,   352,   240,
     330,   330,   330,     6,   341,     6,   341,     6,     6,   244,
     330,   315,   301,     6,   347,   347,   347,   347,   341,   347,
     318,   258,   240,   248,     6,   243,   330,   244,   248,   248,
     248,   248,   248,     6,   244,   244,   313,   244,   244,   244,
     244,   248,   244,   244,   244,   264,   330,   343,   244,   330,
     330,   330,   341,   341,   315,     6,     6,     6,     6,   347,
       6,     6,     6,   243,   240,   244,     6,   244,   274,   248,
     248,   248,   244,   244,   262,   351,   267,   243,     6,   330,
     330,   330,     6,   244,   248,   243,   343,   244,   244,   244,
       6,   351,   265,   351,   244,     6,     6,   244,   248,     6,
       6,   351
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 267 "Gmsh.y"
    { yyerrok; return 1; }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 278 "Gmsh.y"
    { return 1; }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 279 "Gmsh.y"
    { return 1; }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 280 "Gmsh.y"
    { return 1; }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 282 "Gmsh.y"
    {
      gmsh_yyfactory = (yyvsp[(3) - (5)].c);
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
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 300 "Gmsh.y"
    { return 1; }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 301 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 302 "Gmsh.y"
    { return 1; }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 303 "Gmsh.y"
    { return 1; }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 304 "Gmsh.y"
    { return 1; }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 305 "Gmsh.y"
    { return 1; }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 306 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 307 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 308 "Gmsh.y"
    { return 1; }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 309 "Gmsh.y"
    { return 1; }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 310 "Gmsh.y"
    { return 1; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 311 "Gmsh.y"
    { return 1; }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 312 "Gmsh.y"
    { return 1; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 313 "Gmsh.y"
    { return 1; }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 314 "Gmsh.y"
    { return 1; }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 315 "Gmsh.y"
    { return 1; }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 320 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 324 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 331 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 336 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 341 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
      FILE *fp = Fopen(tmp.c_str(), (yyvsp[(5) - (7)].c));
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmp.c_str());
      }
      else{
	fprintf(fp, "%s\n", (yyvsp[(3) - (7)].c));
	fclose(fp);
      }
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 355 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 368 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 381 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (9)].c), (yyvsp[(5) - (9)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(8) - (9)].c));
	FILE *fp = Fopen(tmp.c_str(), (yyvsp[(7) - (9)].c));
	if(!fp){
	  yymsg(0, "Unable to open file '%s'", tmp.c_str());
	}
	else{
	  fprintf(fp, "%s\n", tmpstring);
	  fclose(fp);
	}
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
      List_Delete((yyvsp[(5) - (9)].l));
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 409 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(1) - (6)].c), "View") && ViewData->finalize()){
	ViewData->setName((yyvsp[(2) - (6)].c));
	ViewData->setFileName(gmsh_yyname);
	ViewData->setFileIndex(gmsh_yyviewindex++);
	new PView(ViewData);
      }
      else
	delete ViewData;
#endif
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 423 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 436 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 449 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (8)].c), "View")){
	int index = (int)(yyvsp[(4) - (8)].d), index2 = (int)(yyvsp[(6) - (8)].d);
	if(index >= 0 && index < (int)PView::list.size() &&
           index2 >= 0 && index2 < (int)PView::list.size()){
          PView::list[index2]->setOptions(PView::list[index]->getOptions());
        }
        else
	  yymsg(0, "Unknown view %d or %d", index, index2);
      }
#endif
      Free((yyvsp[(2) - (8)].c));
    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 467 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 481 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 483 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 488 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 490 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 495 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strncmp((yyvsp[(1) - (1)].c), "SP", 2)){
	ViewValueList = &ViewData->SP; ViewNumList = &ViewData->NbSP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VP", 2)){
	ViewValueList = &ViewData->VP; ViewNumList = &ViewData->NbVP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TP", 2)){
	ViewValueList = &ViewData->TP; ViewNumList = &ViewData->NbTP;
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SL", 2)){
	ViewValueList = &ViewData->SL; ViewNumList = &ViewData->NbSL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VL", 2)){
	ViewValueList = &ViewData->VL; ViewNumList = &ViewData->NbVL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TL", 2)){
	ViewValueList = &ViewData->TL; ViewNumList = &ViewData->NbTL;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "ST", 2)){
	ViewValueList = &ViewData->ST; ViewNumList = &ViewData->NbST;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VT", 2)){
	ViewValueList = &ViewData->VT; ViewNumList = &ViewData->NbVT;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TT", 2)){
	ViewValueList = &ViewData->TT; ViewNumList = &ViewData->NbTT;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SQ", 2)){
	ViewValueList = &ViewData->SQ; ViewNumList = &ViewData->NbSQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VQ", 2)){
	ViewValueList = &ViewData->VQ; ViewNumList = &ViewData->NbVQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TQ", 2)){
	ViewValueList = &ViewData->TQ; ViewNumList = &ViewData->NbTQ;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SS", 2)){
	ViewValueList = &ViewData->SS; ViewNumList = &ViewData->NbSS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VS", 2)){
	ViewValueList = &ViewData->VS; ViewNumList = &ViewData->NbVS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TS", 2)){
	ViewValueList = &ViewData->TS; ViewNumList = &ViewData->NbTS;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SH", 2)){
	ViewValueList = &ViewData->SH; ViewNumList = &ViewData->NbSH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VH", 2)){
	ViewValueList = &ViewData->VH; ViewNumList = &ViewData->NbVH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TH", 2)){
	ViewValueList = &ViewData->TH; ViewNumList = &ViewData->NbTH;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SI", 2)){
	ViewValueList = &ViewData->SI; ViewNumList = &ViewData->NbSI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VI", 2)){
	ViewValueList = &ViewData->VI; ViewNumList = &ViewData->NbVI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TI", 2)){
	ViewValueList = &ViewData->TI; ViewNumList = &ViewData->NbTI;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "SY", 2)){
	ViewValueList = &ViewData->SY; ViewNumList = &ViewData->NbSY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "VY", 2)){
	ViewValueList = &ViewData->VY; ViewNumList = &ViewData->NbVY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp((yyvsp[(1) - (1)].c), "TY", 2)){
	ViewValueList = &ViewData->TY; ViewNumList = &ViewData->NbTY;
        if(strlen((yyvsp[(1) - (1)].c)) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else{
	yymsg(0, "Unknown element type '%s'", (yyvsp[(1) - (1)].c));
	ViewValueList = 0; ViewNumList = 0;
      }
#endif
      ViewCoord.clear();
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 599 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 609 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 618 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 625 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 635 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 644 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 653 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 660 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 670 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 678 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 688 "Gmsh.y"
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
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (8)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (8)].l)));
#endif
    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 707 "Gmsh.y"
    {
#if defined(HAVE_POST)
      int type =
	(ViewData->NbSL || ViewData->NbVL) ? TYPE_LIN :
	(ViewData->NbST || ViewData->NbVT) ? TYPE_TRI :
	(ViewData->NbSQ || ViewData->NbVQ) ? TYPE_QUA :
	(ViewData->NbSS || ViewData->NbVS) ? TYPE_TET :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix((yyvsp[(3) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(6) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(9) - (14)].l)),
                                         ListOfListOfDouble2Matrix((yyvsp[(12) - (14)].l)));
#endif
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 726 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 732 "Gmsh.y"
    {
    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 739 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 740 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 741 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 742 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 743 "Gmsh.y"
    { (yyval.i) = 4; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 747 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 748 "Gmsh.y"
    { (yyval.i) = -1; }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 754 "Gmsh.y"
    { (yyval.c) = (char*)"("; }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 754 "Gmsh.y"
    { (yyval.c) = (char*)"["; }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 755 "Gmsh.y"
    { (yyval.c) = (char*)")"; }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 755 "Gmsh.y"
    { (yyval.c) = (char*)"]"; }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 765 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 770 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 776 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (4)].c)) && (yyvsp[(2) - (4)].i) && List_Nbr((yyvsp[(3) - (4)].l)) == 1){
        yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (4)].c));
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (4)].c)]);
        if(!(yyvsp[(2) - (4)].i)) s.list = (List_Nbr((yyvsp[(3) - (4)].l)) != 1); // list if 0 or > 1 elements
        if(!s.list){ // single expression
          if(List_Nbr((yyvsp[(3) - (4)].l)) != 1){
            yymsg(0, "Cannot assign list to variable '%s'", (yyvsp[(1) - (4)].c));
          }
          else{
            double d;
            List_Read((yyvsp[(3) - (4)].l), 0, &d);
            if(s.value.empty()){
              if((yyvsp[(2) - (4)].i)) yymsg(1, "Uninitialized variable '%s'", (yyvsp[(1) - (4)].c));
              s.value.resize(1, 0.);
            }
            switch((yyvsp[(2) - (4)].i)){
            case 0 : s.value[0] = d; break;
            case 1 : s.value[0] += d; break;
            case 2 : s.value[0] -= d; break;
            case 3 : s.value[0] *= d; break;
            case 4 :
              if(d) s.value[0] /= d;
              else yymsg(0, "Division by zero in '%s /= %g'", (yyvsp[(1) - (4)].c), d);
              break;
            }
          }
        }
        else{
          // list of expressions; this is not recommended (should use [] or ()
          // notation instead)
          switch((yyvsp[(2) - (4)].i)){
          case 0: // affect
            s.value.clear(); // fall-through
          case 1: // append
            for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
              double d;
              List_Read((yyvsp[(3) - (4)].l), i, &d);
              s.value.push_back(d);
            }
            break;
          case 2: // remove
            for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
              double d;
              List_Read((yyvsp[(3) - (4)].l), i, &d);
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
      Free((yyvsp[(1) - (4)].c));
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 838 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
        if(!s.list && s.value.empty())
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (3)].c));
        else if(!s.list)
          s.value[0] += (yyvsp[(2) - (3)].i);
        else
          yymsg(0, "Variable '%s' is a list", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 853 "Gmsh.y"
    {
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
      s.list = true;
      double d;
      switch((yyvsp[(4) - (6)].i)){
      case 0: // affect
        s.value.clear(); // fall-through
      case 1: // append
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
          List_Read((yyvsp[(5) - (6)].l), i, &d);
          s.value.push_back(d);
        }
        break;
      case 2: // remove
        for(int i = 0; i < List_Nbr((yyvsp[(5) - (6)].l)); i++){
          List_Read((yyvsp[(5) - (6)].l), i, &d);
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
          if(it != s.value.end()) s.value.erase(it);
        }
        break;
      default:
        yymsg(0, "Operators *= and /= not available for lists");
        break;
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 882 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 892 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 897 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 905 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 910 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 918 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 927 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 932 "Gmsh.y"
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
        char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)] = s;
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 944 "Gmsh.y"
    {
      if(gmsh_yystringsymbols.count((yyvsp[(1) - (9)].c))){
        for(int i = 0; i < List_Nbr((yyvsp[(7) - (9)].l)); i++){
          char **c = (char**)List_Pointer((yyvsp[(7) - (9)].l), i);
          gmsh_yystringsymbols[(yyvsp[(1) - (9)].c)].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (9)].c));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(7) - (9)].l));
    }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 961 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 967 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 976 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), d)){
	switch((yyvsp[(4) - (6)].i)){
	case 0 : d = (yyvsp[(5) - (6)].d); break;
	case 1 : d += (yyvsp[(5) - (6)].d); break;
	case 2 : d -= (yyvsp[(5) - (6)].d); break;
	case 3 : d *= (yyvsp[(5) - (6)].d); break;
	case 4 :
	  if((yyvsp[(5) - (6)].d)) d /= (yyvsp[(5) - (6)].d);
	  else yymsg(0, "Division by zero in '%s.%s /= %g'", (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), d);
      }
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 994 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), d)){
	switch((yyvsp[(7) - (9)].i)){
	case 0 : d = (yyvsp[(8) - (9)].d); break;
	case 1 : d += (yyvsp[(8) - (9)].d); break;
	case 2 : d -= (yyvsp[(8) - (9)].d); break;
	case 3 : d *= (yyvsp[(8) - (9)].d); break;
	case 4 :
	  if((yyvsp[(8) - (9)].d)) d /= (yyvsp[(8) - (9)].d);
	  else yymsg(0, "Division by zero in '%s[%d].%s /= %g'", (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d));
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), d);
      }
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1012 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1021 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 1033 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1038 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1046 "Gmsh.y"
    {
      GmshColorTable *ct = GetColorTable(0);
      if(!ct)
	yymsg(0, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr((yyvsp[(5) - (6)].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[(5) - (6)].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 1066 "Gmsh.y"
    {
      GmshColorTable *ct = GetColorTable((int)(yyvsp[(3) - (9)].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[(3) - (9)].d));
      else{
	ct->size = List_Nbr((yyvsp[(8) - (9)].l));
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)(yyvsp[(3) - (9)].d));
	else
	  for(int i = 0; i < ct->size; i++) List_Read((yyvsp[(8) - (9)].l), i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(8) - (9)].l));
    }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 1089 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (5)].c),"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)(yyvsp[(4) - (5)].d));
      else if(!strcmp((yyvsp[(1) - (5)].c),"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)(yyvsp[(4) - (5)].d));
      else
	yymsg(0, "Unknown command '%s Field'", (yyvsp[(1) - (5)].c));
#endif
    }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 1100 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 1108 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 1115 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 1122 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->numericalValue((yyvsp[(8) - (9)].d)); }
	  catch(...){
	    yymsg(0, "Cannot assign a numerical value to option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (9)].d));
#endif
      Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 1144 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->string((yyvsp[(8) - (9)].c)); }
	  catch (...){
	    yymsg(0, "Cannot assign a string value to  option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (9)].d));
#endif
      Free((yyvsp[(6) - (9)].c));
      Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 1167 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  if (option->getType() == FIELD_OPTION_LIST) {
	    std::list<int> vl = option->list();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	      double id;
	      List_Read((yyvsp[(9) - (11)].l), i, &id);
	      vl.push_back((int)id);
	    }
	    option->list(vl);
	  }
	  else {
	    std::list<double> vl = option->listdouble();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	      double id;
	      List_Read((yyvsp[(9) - (11)].l), i, &id);
	      vl.push_back(id);
	    }
	    option->listdouble(vl);
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (11)].c), (int)(yyvsp[(3) - (11)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (11)].d));
#endif
      Free((yyvsp[(6) - (11)].c));
      List_Delete((yyvsp[(9) - (11)].l));
    }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 1205 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (7)].d));
      if(field){
        FieldCallback *callback = field->callbacks[(yyvsp[(6) - (7)].c)];
        if(callback) {
          callback->run();
        }
        else
          yymsg(0, "Unknown callback '%s' in field %i of type '%s'",
              (yyvsp[(6) - (7)].c), (int)(yyvsp[(3) - (7)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (7)].d));
#endif
      Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 1226 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].d));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 1238 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption((yyvsp[(3) - (9)].c), (yyvsp[(6) - (9)].c), (yyvsp[(8) - (9)].c));
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", (yyvsp[(6) - (9)].c), (yyvsp[(3) - (9)].c));
      }
#endif
      Free((yyvsp[(3) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 1256 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 1265 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 1274 "Gmsh.y"
    { init_options(); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 1276 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(6) - (9)].l)) != 1)
	yymsg(1, "List notation should be used to define list '%s[]'", (yyvsp[(3) - (9)].c));
      std::string key((yyvsp[(3) - (9)].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[(6) - (9)].l)); i++){
        double d;
        List_Read((yyvsp[(6) - (9)].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].l));
    }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 1294 "Gmsh.y"
    { init_options(); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 1296 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (11)].c));
      std::vector<double> val;
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (11)].l)); i++){
        double d;
        List_Read((yyvsp[(8) - (11)].l), i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (11)].c));
      Free((yyvsp[(8) - (11)].l));
    }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 1312 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 1321 "Gmsh.y"
    { init_options(); }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 1323 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 1337 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 1345 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 1351 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 1356 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      int n = List_Nbr((yyvsp[(1) - (5)].l));
      if(!gmsh_yystringsymbols.count((yyvsp[(3) - (5)].c))){
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(3) - (5)].c));
      }
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[(3) - (5)].c)]);
        int m = s.size();
        if(n == m){
          for(int i = 0; i < n; i++){
            double d;
            List_Read((yyvsp[(1) - (5)].l), i, &d);
            doubleXstring v = {d, strsave((char*)s[i].c_str())};
            List_Add((yyval.l), &v);
          }
        }
        else{
          yymsg(0, "Size mismatch in enumeration: %d != %d", n, m);
        }
      }
      List_Delete((yyvsp[(1) - (5)].l));
    }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1398 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        double v;
        List_Read((yyvsp[(2) - (2)].l), i, &v);
        floatOptions[key].push_back(v);
        if (flag_Enum && !i) { member_ValMax = (int)v; }
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1410 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (1)].c));
      double v;
      if (!flag_Enum) {
        v = 1.;
        if (key == "Enum") flag_Enum = 1;
      }
      else
        v = (double)++member_ValMax;
      floatOptions[key].push_back(v);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1423 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (4)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        doubleXstring v;
        List_Read((yyvsp[(3) - (4)].l), i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free((yyvsp[(1) - (4)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++)
        Free(((doubleXstring*)List_Pointer((yyvsp[(3) - (4)].l), i))->s);
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1438 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1447 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *v;
        List_Read((yyvsp[(2) - (2)].l), i, &v);
        charOptions[key].push_back(v);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1472 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1480 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1489 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1497 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *s;
        List_Read((yyvsp[(2) - (2)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1511 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        char *s;
        List_Read((yyvsp[(2) - (2)].l), i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1529 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1533 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1540 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1548 "Gmsh.y"
    {
      (yyval.i) = -1;
    }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1552 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(4) - (5)].d);
    }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1558 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1562 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1569 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      double x = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[0];
      double y = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[1];
      double z = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[2];
      double lc = CTX::instance()->geom.scalingFactor * (yyvsp[(6) - (7)].v)[3];
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
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1593 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addLine(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addLine(num, tags);
      }
      if(!r) yymsg(0, "Could not add line");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LINE;
      (yyval.s).Num = num;
    }
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1609 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSpline(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add spline");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_SPLN;
      (yyval.s).Num = num;
    }
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1625 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
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
            (num, tags[0], tags[1], tags[2], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else{
          yymsg(0, "Circle requires 3 points");
        }
      }
      if(!r) yymsg(0, "Could not add circle");
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_CIRC;
      (yyval.s).Num = num;
    }
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1662 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
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
            (num, tags[0], tags[1], tags[2], tags[3], (yyvsp[(7) - (8)].v)[0], (yyvsp[(7) - (8)].v)[1], (yyvsp[(7) - (8)].v)[2]);
        }
        else{
          yymsg(0, "Ellipse requires 4 points");
        }
      }
      if(!r) yymsg(0, "Could not add ellipse");
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SEGM_ELLI;
      (yyval.s).Num = num;
    }
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1702 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "BSpline not yet available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->addBSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add BSpline");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BSPLN;
      (yyval.s).Num = num;
    }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1718 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addBezier(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBezier(num, tags);
      }
      if(!r) yymsg(0, "Could not add Bezier");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_BEZIER;
      (yyval.s).Num = num;
    }
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1735 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (11)].l), tags);
      std::vector<double> knots; ListOfDouble2Vector((yyvsp[(8) - (11)].l), knots);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Nurbs not available yet with OpenCASCADE geometry kernel");
      }
      else{
        int order = knots.size() - tags.size() - 1;
        if(order != (int)(yyvsp[(10) - (11)].d))
          yymsg(1, "Incompatible Nurbs order: using %d", order);
        r = GModel::current()->getGEOInternals()->addNurbs(num, tags, knots);
      }
      if(!r) yymsg(0, "Could not add nurbs");
      List_Delete((yyvsp[(6) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
      (yyval.s).Type = MSH_SEGM_NURBS;
      (yyval.s).Num = num;
    }
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1756 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addWire(num, tags, false);
      }
      else{
        yymsg(0, "Wire only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add wire");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    }
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1772 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
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
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    }
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1791 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPlaneSurface(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addPlaneSurface(num, tags);
      }
      if(!r) yymsg(0, "Could not add plane surface");
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    }
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1807 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
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
        r = GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(7) - (8)].i));
      }
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[(6) - (8)].l));
      (yyval.s).Type = MSH_SURF_REGL;
      (yyval.s).Num = num;
    }
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1828 "Gmsh.y"
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)(yyvsp[(4) - (9)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (9)].l), wires);
      bool r = GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, (yyvsp[(8) - (9)].i));
      if(!r) yymsg(0, "Could not add surface");
      List_Delete((yyvsp[(7) - (9)].l));
      (yyval.s).Type =  MSH_SURF_REGL;
      (yyval.s).Num = num;
    }
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1839 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1845 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    }
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1851 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1858 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Num = num;
    }
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1889 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometryPolarSphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "PolarSphere requires 2 points");
      }
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    }
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1904 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1926 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1949 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    }
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1972 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_SURF_PLAN;
      (yyval.s).Num = num;
    }
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1995 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 2019 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 2043 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 2067 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
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
      List_Delete((yyvsp[(6) - (7)].l));
    }
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 2093 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add surface loop");
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    }
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 2110 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (7)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      if(!r) yymsg(0, "Could not add volume");
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 2126 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (7)].l), wires);
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
      List_Delete((yyvsp[(6) - (7)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 2144 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
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
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Type = MSH_VOLUME;
      (yyval.s).Num = num;
    }
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 2162 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      switch ((yyvsp[(2) - (8)].i)) {
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
      List_Delete((yyvsp[(7) - (8)].l));
      (yyval.s).Num = num;
    }
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 2193 "Gmsh.y"
    {
      // Particular case only for dim 2 (Surface)
      if ((yyvsp[(2) - (12)].i) == 2) {
        int num = (int)(yyvsp[(4) - (12)].d);
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (12)].l), tags);
        std::vector<int> bndTags[4];
        for(int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++){
          if(i < 4)
            ListOfDouble2Vector(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i), bndTags[i]);
          else
            break;
        }
        bool r = GModel::current()->getGEOInternals()->addCompoundSurface
          (num, tags, bndTags);
        if(!r) yymsg(0, "Could not add compound surface");
        List_Delete((yyvsp[(7) - (12)].l));
        Free((yyvsp[(8) - (12)].c));
        for (int i = 0; i < List_Nbr((yyvsp[(10) - (12)].l)); i++)
          List_Delete(*(List_T**)List_Pointer((yyvsp[(10) - (12)].l), i));
        List_Delete((yyvsp[(10) - (12)].l));
        (yyval.s).Type = MSH_SURF_COMPOUND;
        (yyval.s).Num = num;
      }
      else {
        yymsg(0, "GeoEntity dim out of range [2,2]");
      }
    }
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 2221 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    }
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 2225 "Gmsh.y"
    {
      int num = (int)(yyvsp[(5) - (9)].i);
      int op = (yyvsp[(7) - (9)].i);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(8) - (9)].l), tags);
      bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
        ((yyvsp[(2) - (9)].i), num, op, tags);
      if(!r)
        switch ((yyvsp[(2) - (9)].i)) {
        case 0: yymsg(0, "Could not modify physical point"); break;
        case 1: yymsg(0, "Could not modify physical line"); break;
        case 2: yymsg(0, "Could not modify physical surface"); break;
        case 3: yymsg(0, "Could not modify physical volume"); break;
        }
      List_Delete((yyvsp[(8) - (9)].l));
      switch ((yyvsp[(2) - (9)].i)) {
      case 0: (yyval.s).Type = MSH_PHYSICAL_POINT  ; break;
      case 1: (yyval.s).Type = MSH_PHYSICAL_LINE   ; break;
      case 2: (yyval.s).Type = MSH_PHYSICAL_SURFACE; break;
      case 3: (yyval.s).Type = MSH_PHYSICAL_VOLUME ; break;
      }
      (yyval.s).Num = num;
    }
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 2251 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 2253 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 2255 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 2257 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 2259 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 2267 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 2269 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 2271 "Gmsh.y"
    { (yyval.i) = 3; }
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 2273 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 2281 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 2283 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 2285 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 2293 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 2295 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 2297 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 2299 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 2309 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->translate
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      else{
        r = GModel::current()->getGEOInternals()->translate
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2]);
      }
      if(!r) yymsg(0, "Could not translate shapes");
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 2325 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (11)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->rotate
          (dimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      else{
        r = GModel::current()->getGEOInternals()->rotate
          (dimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d));
      }
      if(!r) yymsg(0, "Could not rotate shapes");
      (yyval.l) = (yyvsp[(10) - (11)].l);
    }
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 2341 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->symmetry
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      else{
        r = GModel::current()->getGEOInternals()->symmetry
          (dimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], (yyvsp[(2) - (5)].v)[3]);
      }
      if(!r) yymsg(0, "Could not apply symmetry transform");
      (yyval.l) = (yyvsp[(4) - (5)].l);
    }
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 2357 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d));
      }
      else{
        r = GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(5) - (9)].d));
      }
      if(!r) yymsg(0, "Could not dilate shapes");
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 2373 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(8) - (9)].l), dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2]);
      }
      else{
        r = GModel::current()->getGEOInternals()->dilate
          (dimTags, (yyvsp[(3) - (9)].v)[0], (yyvsp[(3) - (9)].v)[1], (yyvsp[(3) - (9)].v)[2], (yyvsp[(5) - (9)].v)[0], (yyvsp[(5) - (9)].v)[1], (yyvsp[(5) - (9)].v)[2]);
      }
      if(!r) yymsg(0, "Could not dilate shapes");
      (yyval.l) = (yyvsp[(8) - (9)].l);
    }
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 2389 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), inDimTags);
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      std::string action((yyvsp[(1) - (4)].c));
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
        yymsg(0, "Unknown action on multiple shapes '%s'", (yyvsp[(1) - (4)].c));
      }
      if(!r) yymsg(0, "Could not apply operation on shapes");
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      Free((yyvsp[(1) - (4)].c));
    }
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 2426 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Intersect line not available with OpenCASCADE");
      }
      else{
        std::vector<int> in, out; ListOfDouble2Vector((yyvsp[(4) - (9)].l), in);
        r = GModel::current()->getGEOInternals()->intersectCurvesWithSurface
          (in, (int)(yyvsp[(8) - (9)].d), out);
        for(unsigned int i = 0; i < out.size(); i++){
          Shape s;
          s.Type = MSH_POINT;
          s.Num = out[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not intersect line");
      List_Delete((yyvsp[(4) - (9)].l));
    }
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 2448 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Line not available with OpenCASCADE");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector((yyvsp[(7) - (9)].l), vertices);
        r = GModel::current()->getGEOInternals()->splitCurve
          ((int)(yyvsp[(4) - (9)].d), vertices, curves);
        for(unsigned int i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add((yyval.l), &s);
        }
      }
      if(!r) yymsg(0, "Could not split line");
      List_Delete((yyvsp[(7) - (9)].l));
    }
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 2471 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 2472 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 2477 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    }
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 2481 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    }
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 2485 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (6)].l), i, &d);
	Shape s;
	s.Num = (int)d;
        switch ((yyvsp[(2) - (6)].i)) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add((yyval.l), &s);
      }
    }
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 2506 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(7) - (8)].l)) == 4){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read((yyvsp[(7) - (8)].l), i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 2525 "Gmsh.y"
    {
      int t = (int)(yyvsp[(4) - (10)].d);
      if(gLevelset::find(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	fullMatrix<double> centers(List_Nbr((yyvsp[(8) - (10)].l)),3);
	for (int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i);
	  for (int j = 0; j < List_Nbr(l); j++){
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
        gLevelset *ls = new gLevelsetPoints(centers, t);
        gLevelset::add(ls);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i));
      List_Delete((yyvsp[(8) - (10)].l));
    }
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 2547 "Gmsh.y"
    {
      int t = (int)(yyvsp[(4) - (14)].d);
      if(gLevelset::find(t)){
        yymsg(0, "Levelset %d already exists", t);
      }
      else {
        double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
        double n[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
        gLevelset *ls = new gLevelsetPlane(pt, n, t);
        gLevelset::add(ls);
      }
      List_Delete((yyvsp[(12) - (14)].l));
    }
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 2562 "Gmsh.y"
    {
      int t = (int)(yyvsp[(4) - (16)].d);
      if(gLevelset::find(t)){
        yymsg(0, "Levelset %d already exists", t);
      }
      else {
        double pt1[3] = {(yyvsp[(8) - (16)].v)[0], (yyvsp[(8) - (16)].v)[1], (yyvsp[(8) - (16)].v)[2]};
        double pt2[3] = {(yyvsp[(10) - (16)].v)[0], (yyvsp[(10) - (16)].v)[1], (yyvsp[(10) - (16)].v)[2]};
        double pt3[3] = {(yyvsp[(12) - (16)].v)[0], (yyvsp[(12) - (16)].v)[1], (yyvsp[(12) - (16)].v)[2]};
        gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
        gLevelset::add(ls);
      }
      List_Delete((yyvsp[(14) - (16)].l));
    }
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 2577 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(10) - (12)].l)) == 1){
        int t = (int)(yyvsp[(4) - (12)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(10) - (12)].l), 0, &d);
          gLevelset *ls = new gLevelsetSphere((yyvsp[(8) - (12)].v)[0], (yyvsp[(8) - (12)].v)[1], (yyvsp[(8) - (12)].v)[2], d, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(10) - (12)].l));
    }
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 2596 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          gLevelset::add(ls);
        }
      }
      else if(List_Nbr((yyvsp[(12) - (14)].l)) == 2){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          gLevelset::add(ls);
        }
      }
      else if(List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(12) - (14)].l));
    }
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 2647 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 1){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(12) - (14)].l), 0, &d);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(12) - (14)].l));
    }
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 2668 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 3){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(12) - (14)].l));
    }
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 2690 "Gmsh.y"
    {
      if(List_Nbr((yyvsp[(12) - (14)].l)) == 5){
        int t = (int)(yyvsp[(4) - (14)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[5];
          for(int i = 0; i < 5; i++)
            List_Read((yyvsp[(12) - (14)].l), i, &d[i]);
          double pt[3] = {(yyvsp[(8) - (14)].v)[0], (yyvsp[(8) - (14)].v)[1], (yyvsp[(8) - (14)].v)[2]};
          double dir[3] = {(yyvsp[(10) - (14)].v)[0], (yyvsp[(10) - (14)].v)[1], (yyvsp[(10) - (14)].v)[2]};
          gLevelset *ls = new gLevelsetGeneralQuadric(pt, dir, d[0], d[1],
                                                      d[2], d[3], d[4], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete((yyvsp[(12) - (14)].l));
    }
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 2712 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (8)].c), "Union")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Intersection")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Cut")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetCut(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Crack")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr((yyvsp[(7) - (8)].l)); i++) {
            double d; List_Read((yyvsp[(7) - (8)].l), i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetCrack(vl, false, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp((yyvsp[(2) - (8)].c), "Reverse")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read((yyvsp[(7) - (8)].l), 0, &d);
          gLevelset *pl = gLevelset::find((int)d);
          gLevelset *ls = NULL;
          if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
          else ls = new gLevelsetReverse(pl, t);
          if(ls) gLevelset::add(ls);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp((yyvsp[(2) - (8)].c), "PostView")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr((yyvsp[(7) - (8)].l)) > 0){
            double d; List_Read((yyvsp[(7) - (8)].l), 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            gLevelset::add(ls);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      Free((yyvsp[(2) - (8)].c));
      List_Delete((yyvsp[(7) - (8)].l));
    }
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 2817 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (8)].c), "MathEval")){
        int t = (int)(yyvsp[(4) - (8)].d);
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval((yyvsp[(7) - (8)].c), t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Unknown levelset '%s'", (yyvsp[(2) - (8)].c));
      Free((yyvsp[(2) - (8)].c)); Free((yyvsp[(7) - (8)].c));
    }
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 2833 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "CutMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), true, false);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "CutMeshTri")){
        int t = (int)(yyvsp[(4) - (6)].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), true, true);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else if(!strcmp((yyvsp[(2) - (6)].c), "SplitMesh")){
        int t = (int)(yyvsp[(4) - (6)].d);
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), false, true);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else
        yymsg(0, "Unknown levelset '%s'", (yyvsp[(2) - (6)].c));
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 2868 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
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
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 2890 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
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
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 2912 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    }
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 2918 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (6)].c), "View")){
	int index = (int)(yyvsp[(4) - (6)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  delete PView::list[index];
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", (yyvsp[(2) - (6)].c));
#endif
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 2933 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Physicals")){
	GModel::current()->getGEOInternals()->resetPhysicalGroups();
	GModel::current()->deletePhysicalGroups();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Variables")){
	gmsh_yysymbols.clear();
      }
      else if(!strcmp((yyvsp[(2) - (3)].c), "Options")){
        ReInitOptions(0);
        InitOptionsGUI(0);
      }
      else{
	if(gmsh_yysymbols.count((yyvsp[(2) - (3)].c)))
	  gmsh_yysymbols.erase((yyvsp[(2) - (3)].c));
	else
	  yymsg(0, "Unknown object or expression to delete '%s'", (yyvsp[(2) - (3)].c));
      }
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 2961 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (4)].c), "Empty") && !strcmp((yyvsp[(3) - (4)].c), "Views")){
	for(int i = PView::list.size() - 1; i >= 0; i--)
	  if(PView::list[i]->getData()->empty()) delete PView::list[i];
      }
      else
	yymsg(0, "Unknown command 'Delete %s %s'", (yyvsp[(2) - (4)].c), (yyvsp[(3) - (4)].c));
#endif
      Free((yyvsp[(2) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 2973 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    }
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 2982 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 2989 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 3001 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      for(unsigned int i = 0; i < dimTags.size(); i++){
        GEntity *ge = GModel::current()->getEntityByTag
          (dimTags[i].first, dimTags[i].second);
        if(ge){
          for(unsigned int j = 0; j < ge->getNumMeshElements(); j++)
            ge->getMeshElement(j)->setPartition((int)(yyvsp[(2) - (5)].d));
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 240:
/* Line 1792 of yacc.c  */
#line 3020 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 241:
/* Line 1792 of yacc.c  */
#line 3026 "Gmsh.y"
    {
      std::string what = (yyvsp[(2) - (3)].c);
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 242:
/* Line 1792 of yacc.c  */
#line 3032 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 3039 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 3046 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 3053 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 3065 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "Print")){
	// make sure we have the latest data from CAD internals in GModel (fixes
	// bug where we would have no geometry in the picture if the print
	// command is in the same file as the geometry)
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Save")){
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Merge") || !strcmp((yyvsp[(1) - (3)].c), "MergeWithBoundingBox")){
	// sync CAD internals here, so that if we e.g. import a STEP file, we
        // have the correct entity tags and the numberings don't clash
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
				// CTX::instance()->geom.matchGeomAndMesh = 1;
				MergeFile(tmp, true);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "NonBlockingSystemCall")){
	SystemCall((yyvsp[(2) - (3)].c));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "System") || !strcmp((yyvsp[(1) - (3)].c), "SystemCall")){
	SystemCall((yyvsp[(2) - (3)].c), true);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetName")){
	GModel::current()->setName((yyvsp[(2) - (3)].c));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "CreateDir")){
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(2) - (3)].c));
	CreateSingleDir(tmp);
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "OnelabRun")){
        Msg::RunOnelabClient((yyvsp[(2) - (3)].c));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "OptimizeMesh")){
        GModel::current()->optimizeMesh((yyvsp[(2) - (3)].c));
      }
      else{
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      }
      Free((yyvsp[(1) - (3)].c)); Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 3139 "Gmsh.y"
    {
      int n = List_Nbr((yyvsp[(3) - (5)].l));
      if(n == 1){
        char *s; List_Read((yyvsp[(3) - (5)].l), 0, &s);
        Msg::RunOnelabClient(s);
        Free(s);
      }
      else if(n == 2){
        char *s, *t; List_Read((yyvsp[(3) - (5)].l), 0, &s); List_Read((yyvsp[(3) - (5)].l), 1, &t);
        Msg::RunOnelabClient(s, t);
        Free(s); Free(t);
      }
      else{
        yymsg(0, "OnelabRun takes one or two arguments");
      }
      List_Delete((yyvsp[(3) - (5)].l));
    }
    break;

  case 248:
/* Line 1792 of yacc.c  */
#line 3157 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
          std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
	  PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 249:
/* Line 1792 of yacc.c  */
#line 3174 "Gmsh.y"
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
	int index = (int)(yyvsp[(5) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size())
	  GModel::current()->getFields()->setBackgroundMesh(index);
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(3) - (7)].c));
    }
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 3189 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")){
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")){
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Mesh")){
	int lock = CTX::instance()->lock;
	CTX::instance()->lock = 0;
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
	GModel::current()->mesh((int)(yyvsp[(2) - (3)].d));
	CTX::instance()->lock = lock;
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetOrder")){
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "PartitionMesh")){
        GModel::current()->partitionMesh((yyvsp[(2) - (3)].d));
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 3222 "Gmsh.y"
    {
#if defined(HAVE_PLUGINS)
       try {
	 PluginManager::instance()->action((yyvsp[(3) - (7)].c), (yyvsp[(6) - (7)].c), 0);
       }
       catch(...) {
	 yymsg(0, "Unknown action '%s' or plugin '%s'", (yyvsp[(6) - (7)].c), (yyvsp[(3) - (7)].c));
       }
#endif
       Free((yyvsp[(3) - (7)].c)); Free((yyvsp[(6) - (7)].c));
     }
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 3234 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromAllViews"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 3258 "Gmsh.y"
    {
      Msg::Exit(0);
    }
    break;

  case 254:
/* Line 1792 of yacc.c  */
#line 3262 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
    break;

  case 255:
/* Line 1792 of yacc.c  */
#line 3267 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
    break;

  case 256:
/* Line 1792 of yacc.c  */
#line 3274 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
    break;

  case 257:
/* Line 1792 of yacc.c  */
#line 3279 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
    break;

  case 258:
/* Line 1792 of yacc.c  */
#line 3289 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    }
    break;

  case 259:
/* Line 1792 of yacc.c  */
#line 3294 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
    break;

  case 260:
/* Line 1792 of yacc.c  */
#line 3300 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
    break;

  case 261:
/* Line 1792 of yacc.c  */
#line 3308 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    }
    break;

  case 262:
/* Line 1792 of yacc.c  */
#line 3312 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh(1);
    }
    break;

  case 263:
/* Line 1792 of yacc.c  */
#line 3316 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    }
    break;

  case 264:
/* Line 1792 of yacc.c  */
#line 3326 "Gmsh.y"
    {
      int lock = CTX::instance()->lock;
      CTX::instance()->lock = 0;
      std::vector<int> technique;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (16)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (16)].l), i, &d);
        technique.push_back((int)d);
      }
      if(technique.empty()){
        yymsg(0, "Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr((yyvsp[(6) - (16)].l)); i++){
          double d;
          List_Read((yyvsp[(6) - (16)].l), i, &d);
          gLevelset *l = gLevelset::find((int)d);
          if(l) f.push_back(l);
          else yymsg(0, "Unknown levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yymsg(0, "Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr((yyvsp[(9) - (16)].l)) != (int)f.size()){
            yymsg(0, "Number of parameters != number of levelsets");
          }
          else{
            std::vector<std::vector<double> > parameters;
            parameters.resize(List_Nbr((yyvsp[(9) - (16)].l)));
            for(int i = 0; i < List_Nbr((yyvsp[(9) - (16)].l)); i++){
              List_T *l = *(List_T**)List_Pointer((yyvsp[(9) - (16)].l), i);
              for(int j = 0; j < List_Nbr(l); j++){
                double d;
                List_Read(l, j, &d);
                parameters[i].push_back(d);
              }
            }
            int niter = (int)(yyvsp[(12) - (16)].d);
            bool meshAll = ((yyvsp[(14) - (16)].d) == 0) ? false : true;
            if(GModel::current()->getOCCInternals() &&
               GModel::current()->getOCCInternals()->getChanged())
              GModel::current()->getOCCInternals()->synchronize(GModel::current());
            if(GModel::current()->getGEOInternals()->getChanged())
              GModel::current()->getGEOInternals()->synchronize(GModel::current());
            GModel::current()->adaptMesh(technique, f, parameters, niter, meshAll);
          }
        }
      }
      List_Delete((yyvsp[(3) - (16)].l));
      List_Delete((yyvsp[(6) - (16)].l));
      for(int i = 0; i < List_Nbr((yyvsp[(9) - (16)].l)); i++)
        List_Delete(*(List_T**)List_Pointer((yyvsp[(9) - (16)].l), i));
      List_Delete((yyvsp[(9) - (16)].l));
      CTX::instance()->lock = lock;
    }
    break;

  case 265:
/* Line 1792 of yacc.c  */
#line 3389 "Gmsh.y"
    {
#if defined(HAVE_POPPLER)
       std::vector<int> is;
       for(int i = 0; i < List_Nbr((yyvsp[(4) - (11)].l)); i++){
	 double d;
	 List_Read((yyvsp[(4) - (11)].l), i, &d);
	 is.push_back ((int) d);
       }
       gmshPopplerWrapper::instance()->setMacroForPages(is, (yyvsp[(7) - (11)].c), (yyvsp[(9) - (11)].c) );
#endif
     }
    break;

  case 266:
/* Line 1792 of yacc.c  */
#line 3405 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (6)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(3) - (6)].d) > (yyvsp[(5) - (6)].d))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
    break;

  case 267:
/* Line 1792 of yacc.c  */
#line 3422 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(3) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(7) - (8)].d) > 0. && (yyvsp[(3) - (8)].d) > (yyvsp[(5) - (8)].d)) || ((yyvsp[(7) - (8)].d) < 0. && (yyvsp[(3) - (8)].d) < (yyvsp[(5) - (8)].d)))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
    break;

  case 268:
/* Line 1792 of yacc.c  */
#line 3439 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (8)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (8)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (8)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (8)].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if((yyvsp[(5) - (8)].d) > (yyvsp[(7) - (8)].d))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free((yyvsp[(2) - (8)].c));
    }
    break;

  case 269:
/* Line 1792 of yacc.c  */
#line 3461 "Gmsh.y"
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = (yyvsp[(5) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][1] = (yyvsp[(7) - (10)].d);
      LoopControlVariablesTab[ImbricatedLoop][2] = (yyvsp[(9) - (10)].d);
      LoopControlVariablesNameTab[ImbricatedLoop] = (yyvsp[(2) - (10)].c);
      gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (10)].c)]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = (yyvsp[(5) - (10)].d);
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(((yyvsp[(9) - (10)].d) > 0. && (yyvsp[(5) - (10)].d) > (yyvsp[(7) - (10)].d)) || ((yyvsp[(9) - (10)].d) < 0. && (yyvsp[(5) - (10)].d) < (yyvsp[(7) - (10)].d)))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free((yyvsp[(2) - (10)].c));
    }
    break;

  case 270:
/* Line 1792 of yacc.c  */
#line 3483 "Gmsh.y"
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
    break;

  case 271:
/* Line 1792 of yacc.c  */
#line 3518 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 3526 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 273:
/* Line 1792 of yacc.c  */
#line 3534 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
    break;

  case 274:
/* Line 1792 of yacc.c  */
#line 3540 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 275:
/* Line 1792 of yacc.c  */
#line 3547 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 276:
/* Line 1792 of yacc.c  */
#line 3554 "Gmsh.y"
    {
      ImbricatedTest++;
      if(ImbricatedTest > MAX_RECUR_TESTS-1){
	yymsg(0, "Reached maximum number of imbricated tests");
        ImbricatedTest = MAX_RECUR_TESTS-1;
      }

      if((yyvsp[(3) - (4)].d)){
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
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 3574 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if (statusImbricatedTests[ImbricatedTest]){
          // Last test (If or ElseIf) was true, thus go after EndIf (out of If EndIf)
          skip("If", "EndIf");
          ImbricatedTest--;
        }
        else{
          // Previous test(s) (If and ElseIf) not yet true
          if((yyvsp[(3) - (4)].d)){
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
    break;

  case 278:
/* Line 1792 of yacc.c  */
#line 3600 "Gmsh.y"
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
    break;

  case 279:
/* Line 1792 of yacc.c  */
#line 3612 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
    break;

  case 280:
/* Line 1792 of yacc.c  */
#line 3623 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->extrude
          (inDimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], outDimTags);
      }
      else{
        r = GModel::current()->getGEOInternals()->extrude
          (inDimTags, (yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(4) - (5)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
    break;

  case 281:
/* Line 1792 of yacc.c  */
#line 3641 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (11)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->revolve
          (inDimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), outDimTags);
      }
      else{
        r = GModel::current()->getGEOInternals()->revolve
          (inDimTags, (yyvsp[(5) - (11)].v)[0], (yyvsp[(5) - (11)].v)[1], (yyvsp[(5) - (11)].v)[2], (yyvsp[(3) - (11)].v)[0], (yyvsp[(3) - (11)].v)[1], (yyvsp[(3) - (11)].v)[2], (yyvsp[(7) - (11)].d), outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(10) - (11)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
    break;

  case 282:
/* Line 1792 of yacc.c  */
#line 3659 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(12) - (13)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->twist
          (inDimTags, (yyvsp[(7) - (13)].v)[0], (yyvsp[(7) - (13)].v)[1], (yyvsp[(7) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2],
           (yyvsp[(9) - (13)].d), outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(12) - (13)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 3677 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 3683 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (7)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->extrude
          (inDimTags, (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], outDimTags, &extr);
      }
      else{
        r = GModel::current()->getGEOInternals()->extrude
          (inDimTags, (yyvsp[(2) - (7)].v)[0], (yyvsp[(2) - (7)].v)[1], (yyvsp[(2) - (7)].v)[2], outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(4) - (7)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
    break;

  case 285:
/* Line 1792 of yacc.c  */
#line 3701 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 286:
/* Line 1792 of yacc.c  */
#line 3707 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(10) - (13)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->revolve
          (inDimTags, (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(7) - (13)].d), outDimTags,
           &extr);
      }
      else{
        r = GModel::current()->getGEOInternals()->revolve
          (inDimTags, (yyvsp[(5) - (13)].v)[0], (yyvsp[(5) - (13)].v)[1], (yyvsp[(5) - (13)].v)[2], (yyvsp[(3) - (13)].v)[0], (yyvsp[(3) - (13)].v)[1], (yyvsp[(3) - (13)].v)[2], (yyvsp[(7) - (13)].d), outDimTags,
           &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(10) - (13)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
    break;

  case 287:
/* Line 1792 of yacc.c  */
#line 3727 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 288:
/* Line 1792 of yacc.c  */
#line 3733 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(12) - (15)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->twist
          (inDimTags, (yyvsp[(7) - (15)].v)[0], (yyvsp[(7) - (15)].v)[1], (yyvsp[(7) - (15)].v)[2], (yyvsp[(3) - (15)].v)[0], (yyvsp[(3) - (15)].v)[1], (yyvsp[(3) - (15)].v)[2], (yyvsp[(5) - (15)].v)[0], (yyvsp[(5) - (15)].v)[1], (yyvsp[(5) - (15)].v)[2],
           (yyvsp[(9) - (15)].d),  outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(12) - (15)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
    break;

  case 289:
/* Line 1792 of yacc.c  */
#line 3751 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
    break;

  case 290:
/* Line 1792 of yacc.c  */
#line 3757 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (6)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Boundary layer extrusion not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->boundaryLayer
          (inDimTags, outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(3) - (6)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
    break;

  case 291:
/* Line 1792 of yacc.c  */
#line 3774 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPipe(inDimTags, (int)(yyvsp[(8) - (9)].d), outDimTags);
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      (yyval.l) = (yyvsp[(3) - (9)].l);
      List_Reset((yyval.l));
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    }
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 3790 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[(2) - (2)].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, false, false, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add thrusections");
      List_Delete((yyvsp[(2) - (2)].l));
    }
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 3807 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector((yyvsp[(3) - (3)].l), wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, false, true, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add ruled thrusections");
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 3824 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        double radius = (yyvsp[(9) - (10)].d);
        std::vector<int> regions, edges;
        ListOfDouble2Vector((yyvsp[(3) - (10)].l), regions); ListOfDouble2Vector((yyvsp[(6) - (10)].l), edges);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->fillet
          (regions, edges, radius, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not fillet shapes");
      List_Delete((yyvsp[(3) - (10)].l));
      List_Delete((yyvsp[(6) - (10)].l));
    }
    break;

  case 295:
/* Line 1792 of yacc.c  */
#line 3847 "Gmsh.y"
    {
    }
    break;

  case 296:
/* Line 1792 of yacc.c  */
#line 3850 "Gmsh.y"
    {
    }
    break;

  case 297:
/* Line 1792 of yacc.c  */
#line 3856 "Gmsh.y"
    {
      int n = (int)fabs((yyvsp[(3) - (5)].d));
      if(n){ // we accept n==0 to easily disable layers
        extr.mesh.ExtrudeMesh = true;
        extr.mesh.NbLayer = 1;
        extr.mesh.NbElmLayer.clear();
        extr.mesh.hLayer.clear();
        extr.mesh.NbElmLayer.push_back((int)fabs((yyvsp[(3) - (5)].d)));
        extr.mesh.hLayer.push_back(1.);
      }
    }
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 3868 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr((yyvsp[(3) - (7)].l));
      if(List_Nbr((yyvsp[(3) - (7)].l)) == List_Nbr((yyvsp[(5) - (7)].l))){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
	  double d;
	  List_Read((yyvsp[(3) - (7)].l), i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read((yyvsp[(5) - (7)].l), i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d}", List_Nbr((yyvsp[(3) - (7)].l)), List_Nbr((yyvsp[(5) - (7)].l)));
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    }
    break;

  case 299:
/* Line 1792 of yacc.c  */
#line 3888 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    }
    break;

  case 300:
/* Line 1792 of yacc.c  */
#line 3892 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    }
    break;

  case 301:
/* Line 1792 of yacc.c  */
#line 3896 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    }
    break;

  case 302:
/* Line 1792 of yacc.c  */
#line 3900 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
    break;

  case 303:
/* Line 1792 of yacc.c  */
#line 3904 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
    break;

  case 304:
/* Line 1792 of yacc.c  */
#line 3908 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
    break;

  case 305:
/* Line 1792 of yacc.c  */
#line 3912 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
    break;

  case 306:
/* Line 1792 of yacc.c  */
#line 3916 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    }
    break;

  case 307:
/* Line 1792 of yacc.c  */
#line 3925 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    }
    break;

  case 308:
/* Line 1792 of yacc.c  */
#line 3937 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; }
    break;

  case 309:
/* Line 1792 of yacc.c  */
#line 3938 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; }
    break;

  case 310:
/* Line 1792 of yacc.c  */
#line 3939 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; }
    break;

  case 311:
/* Line 1792 of yacc.c  */
#line 3940 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; }
    break;

  case 312:
/* Line 1792 of yacc.c  */
#line 3941 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; }
    break;

  case 313:
/* Line 1792 of yacc.c  */
#line 3945 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 314:
/* Line 1792 of yacc.c  */
#line 3946 "Gmsh.y"
    { (yyval.i) = 1; }
    break;

  case 315:
/* Line 1792 of yacc.c  */
#line 3947 "Gmsh.y"
    { (yyval.i) = 2; }
    break;

  case 316:
/* Line 1792 of yacc.c  */
#line 3948 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; }
    break;

  case 317:
/* Line 1792 of yacc.c  */
#line 3949 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; }
    break;

  case 318:
/* Line 1792 of yacc.c  */
#line 3954 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs((yyvsp[(3) - (9)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (9)].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          (-1, (OCC_Internals::BooleanOperator)(yyvsp[(1) - (9)].i), object, tool, out, outMap, (yyvsp[(4) - (9)].i), (yyvsp[(8) - (9)].i));
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[(3) - (9)].l));
      List_Delete((yyvsp[(7) - (9)].l));
    }
    break;

  case 319:
/* Line 1792 of yacc.c  */
#line 3977 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > out;
        std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        VectorOfPairs2ListOfShapes(out, (yyval.l));
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could import shape");
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 320:
/* Line 1792 of yacc.c  */
#line 3997 "Gmsh.y"
    {
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs((yyvsp[(7) - (14)].l), object);
        ListOfShapes2VectorOfPairs((yyvsp[(11) - (14)].l), tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          ((int)(yyvsp[(3) - (14)].d), (OCC_Internals::BooleanOperator)(yyvsp[(1) - (14)].i), object, tool, out, outMap, (yyvsp[(8) - (14)].i), (yyvsp[(12) - (14)].i));
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete((yyvsp[(7) - (14)].l));
      List_Delete((yyvsp[(11) - (14)].l));
    }
    break;

  case 321:
/* Line 1792 of yacc.c  */
#line 4018 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    }
    break;

  case 322:
/* Line 1792 of yacc.c  */
#line 4022 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Progression") || !strcmp((yyvsp[(2) - (3)].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Bump"))
        (yyval.v)[0] = 2.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[(3) - (3)].d);
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 323:
/* Line 1792 of yacc.c  */
#line 4037 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    }
    break;

  case 324:
/* Line 1792 of yacc.c  */
#line 4041 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "Right"))
        (yyval.i) = 1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "Left"))
	(yyval.i) = -1;
      else if(!strcmp((yyvsp[(1) - (1)].c), "AlternateRight"))
	(yyval.i) = 2;
      else if(!strcmp((yyvsp[(1) - (1)].c), "AlternateLeft"))
	(yyval.i) = -2;
      else // "Alternate" -> "Alternate Right"
	(yyval.i) = 2;
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 325:
/* Line 1792 of yacc.c  */
#line 4057 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   }
    break;

  case 326:
/* Line 1792 of yacc.c  */
#line 4061 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   }
    break;

  case 327:
/* Line 1792 of yacc.c  */
#line 4066 "Gmsh.y"
    {
      (yyval.i) = 45;
    }
    break;

  case 328:
/* Line 1792 of yacc.c  */
#line 4070 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    }
    break;

  case 329:
/* Line 1792 of yacc.c  */
#line 4076 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    }
    break;

  case 330:
/* Line 1792 of yacc.c  */
#line 4080 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    }
    break;

  case 331:
/* Line 1792 of yacc.c  */
#line 4087 "Gmsh.y"
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (6)].l), i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, (yyvsp[(5) - (6)].d));
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex((yyvsp[(5) - (6)].d));
      }
      List_Delete((yyvsp[(3) - (6)].l));
    }
    break;

  case 332:
/* Line 1792 of yacc.c  */
#line 4104 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      int type = (int)(yyvsp[(6) - (7)].v)[0];
      double coef = fabs((yyvsp[(6) - (7)].v)[1]);
      int npoints = ((int)(yyvsp[(5) - (7)].d) < 2) ? 2 : (int)(yyvsp[(5) - (7)].d);
      if(!(yyvsp[(3) - (7)].l)){
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
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (7)].l), i, &d);
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
        List_Delete((yyvsp[(3) - (7)].l));
      }
    }
    break;

  case 333:
/* Line 1792 of yacc.c  */
#line 4145 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      std::vector<int> corners; ListOfDouble2Vector((yyvsp[(4) - (6)].l), corners);
      if(!(yyvsp[(3) - (6)].l)){
        GModel::current()->getGEOInternals()->setTransfiniteSurface(0, (yyvsp[(5) - (6)].i), corners);
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
          (*it)->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (6)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteSurface(tag, (yyvsp[(5) - (6)].i), corners);
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf){
            gf->meshAttributes.method = MESH_TRANSFINITE;
            gf->meshAttributes.transfiniteArrangement = (yyvsp[(5) - (6)].i);
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
        List_Delete((yyvsp[(3) - (6)].l));
      }
      List_Delete((yyvsp[(4) - (6)].l));
    }
    break;

  case 334:
/* Line 1792 of yacc.c  */
#line 4189 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      std::vector<int> corners; ListOfDouble2Vector((yyvsp[(4) - (5)].l), corners);
      if(!(yyvsp[(3) - (5)].l)){
        GModel::current()->getGEOInternals()->setTransfiniteVolume(0, corners);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (5)].l), i, &d);
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
        List_Delete((yyvsp[(3) - (5)].l));
      }
      List_Delete((yyvsp[(4) - (5)].l));
    }
    break;

  case 335:
/* Line 1792 of yacc.c  */
#line 4228 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(2) - (3)].l)){
        GModel::current()->getGEOInternals()->setTransfiniteVolumeQuadTri(0);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++)
          (*it)->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(2) - (3)].l)); i++){
          double d;
          List_Read((yyvsp[(2) - (3)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteVolumeQuadTri(tag);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr) gr->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
        }
        List_Delete((yyvsp[(2) - (3)].l));
      }
    }
    break;

  case 336:
/* Line 1792 of yacc.c  */
#line 4253 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    }
    break;

  case 337:
/* Line 1792 of yacc.c  */
#line 4262 "Gmsh.y"
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (5)].l)){
        GModel::current()->getGEOInternals()->setRecombine(2, 0, (yyvsp[(4) - (5)].i));
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.recombine = 1;
          (*it)->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (5)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setRecombine(2, tag, (yyvsp[(4) - (5)].i));
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf){
            gf->meshAttributes.recombine = 1;
            gf->meshAttributes.recombineAngle = (yyvsp[(4) - (5)].i);
          }
        }
        List_Delete((yyvsp[(3) - (5)].l));
      }
    }
    break;

  case 338:
/* Line 1792 of yacc.c  */
#line 4292 "Gmsh.y"
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        GModel::current()->getGEOInternals()->setRecombine(3, 0, 0.);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++){
          (*it)->meshAttributes.recombine3D = 1;
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setRecombine(3, tag, 0.);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr) gr->meshAttributes.recombine3D = 1;
        }
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 339:
/* Line 1792 of yacc.c  */
#line 4318 "Gmsh.y"
    {
      // smoothing constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (6)].l)){
        GModel::current()->getGEOInternals()->setSmoothing(0, (int)(yyvsp[(5) - (6)].d));
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.transfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
        }
      }
      else{
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (6)].l), i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setSmoothing(tag, (int)(yyvsp[(5) - (6)].d));
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf) gf->meshAttributes.transfiniteSmoothing = (int)(yyvsp[(5) - (6)].d);
        }
        List_Delete((yyvsp[(3) - (6)].l));
      }
    }
    break;

  case 340:
/* Line 1792 of yacc.c  */
#line 4345 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master lines (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr((yyvsp[(10) - (11)].l)) != 0) {
          if (List_Nbr((yyvsp[(10) - (11)].l)) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries (we have %d)",
                  List_Nbr((yyvsp[(10) - (11)].l)));
          }
          else {
            transfo.resize(List_Nbr((yyvsp[(10) - (11)].l)));
            for(int i = 0; i < List_Nbr((yyvsp[(10) - (11)].l)); i++)
              List_Read((yyvsp[(10) - (11)].l), i, &transfo[i]);
          }
        }
        for(int i = 0; i < List_Nbr((yyvsp[(4) - (11)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (11)].l), i, &d_master);
          List_Read((yyvsp[(4) - (11)].l), i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          addPeriodicEdge(j_slave, j_master, transfo);
        }
      }
      List_Delete((yyvsp[(4) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
    }
    break;

  case 341:
/* Line 1792 of yacc.c  */
#line 4377 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        if (List_Nbr((yyvsp[(10) - (11)].l)) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries");
        }
        else {
          std::vector<double> transfo(16,0);
          for(int i = 0; i < List_Nbr((yyvsp[(10) - (11)].l)); i++)
            List_Read((yyvsp[(10) - (11)].l), i, &transfo[i]);
          for(int i = 0; i < List_Nbr((yyvsp[(4) - (11)].l)); i++){
            double d_master, d_slave;
            List_Read((yyvsp[(8) - (11)].l), i, &d_master);
            List_Read((yyvsp[(4) - (11)].l), i, &d_slave);
            addPeriodicFace(d_slave, d_master, transfo);
          }
        }
      }
      List_Delete((yyvsp[(4) - (11)].l));
      List_Delete((yyvsp[(8) - (11)].l));
    }
    break;

  case 342:
/* Line 1792 of yacc.c  */
#line 4404 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 axis((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
        SPoint3 origin((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (18)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (18)].l), i, &d_master);
          List_Read((yyvsp[(4) - (18)].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (18)].l));
      List_Delete((yyvsp[(8) - (18)].l));
    }
    break;

  case 343:
/* Line 1792 of yacc.c  */
#line 4430 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 origin((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
        SPoint3 axis((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (18)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (18)].l), i, &d_master);
          List_Read((yyvsp[(4) - (18)].l), i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete((yyvsp[(4) - (18)].l));
      List_Delete((yyvsp[(8) - (18)].l));
    }
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 4456 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master edges (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0],(yyvsp[(11) - (12)].v)[1],(yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (12)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (12)].l), i, &d_master);
          List_Read((yyvsp[(4) - (12)].l), i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete((yyvsp[(4) - (12)].l));
      List_Delete((yyvsp[(8) - (12)].l));
    }
    break;

  case 345:
/* Line 1792 of yacc.c  */
#line 4482 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0],(yyvsp[(11) - (12)].v)[1],(yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr((yyvsp[(4) - (12)].l)); i++){
          double d_master, d_slave;
          List_Read((yyvsp[(8) - (12)].l), i, &d_master);
          List_Read((yyvsp[(4) - (12)].l), i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete((yyvsp[(4) - (12)].l));
      List_Delete((yyvsp[(8) - (12)].l));
    }
    break;

  case 346:
/* Line 1792 of yacc.c  */
#line 4508 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
        yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (12)].d);
        int j_slave = (int)(yyvsp[(3) - (12)].d);
        std::map<int,int> edgeCounterParts;
        for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
          double ds,dm;
          List_Read((yyvsp[(5) - (12)].l),i,&ds);
          List_Read((yyvsp[(10) - (12)].l),i,&dm);
          edgeCounterParts[(int) ds] = (int) dm;
        }
        addPeriodicFace(j_slave, j_master, edgeCounterParts);
      }
      List_Delete((yyvsp[(5) - (12)].l));
      List_Delete((yyvsp[(10) - (12)].l));
    }
    break;

  case 347:
/* Line 1792 of yacc.c  */
#line 4529 "Gmsh.y"
    {
      if (((yyvsp[(6) - (10)].i)==2 || (yyvsp[(6) - (10)].i)==3) && (yyvsp[(1) - (10)].i)<(yyvsp[(6) - (10)].i) ) {
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
        addEmbedded((yyvsp[(1) - (10)].i), tags, (yyvsp[(6) - (10)].i), (int)(yyvsp[(8) - (10)].d));
      }
      else {
        yymsg(0, "GeoEntity of dim %d In GeoEntity of dim %d not allowed", (yyvsp[(1) - (10)].i), (yyvsp[(6) - (10)].i));
      }
      List_Delete((yyvsp[(3) - (10)].l));
    }
    break;

  case 348:
/* Line 1792 of yacc.c  */
#line 4540 "Gmsh.y"
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!(yyvsp[(3) - (4)].l)){
        GModel::current()->getGEOInternals()->setReverseMesh((yyvsp[(2) - (4)].i), 0);
        switch ((yyvsp[(2) - (4)].i)) {
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
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          int num = (int)d;
          GModel::current()->getGEOInternals()->setReverseMesh((yyvsp[(2) - (4)].i), num);
          switch ((yyvsp[(2) - (4)].i)) {
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
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 349:
/* Line 1792 of yacc.c  */
#line 4588 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (4)].l)){
        switch ((yyvsp[(2) - (4)].i)) {
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
        for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
          double d;
          List_Read((yyvsp[(3) - (4)].l), i, &d);
          switch ((yyvsp[(2) - (4)].i)) {
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
        List_Delete((yyvsp[(3) - (4)].l));
      }
    }
    break;

  case 350:
/* Line 1792 of yacc.c  */
#line 4637 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
	double dnum;
	List_Read((yyvsp[(3) - (4)].l), i, &dnum);
	int num = (int)dnum;
        GModel::current()->getGEOInternals()->setDegenerated(1, num);
        GEdge *ge = GModel::current()->getEdgeByTag(num);
        if(ge) ge->setTooSmall(true);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 351:
/* Line 1792 of yacc.c  */
#line 4649 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 352:
/* Line 1792 of yacc.c  */
#line 4660 "Gmsh.y"
    {
      GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
    break;

  case 353:
/* Line 1792 of yacc.c  */
#line 4664 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Geometry"))
        GModel::current()->getGEOInternals()->removeAllDuplicates();
      else if(!strcmp((yyvsp[(2) - (3)].c), "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free((yyvsp[(2) - (3)].c));
    }
    break;

  case 354:
/* Line 1792 of yacc.c  */
#line 4674 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    }
    break;

  case 355:
/* Line 1792 of yacc.c  */
#line 4684 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; }
    break;

  case 356:
/* Line 1792 of yacc.c  */
#line 4685 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; }
    break;

  case 357:
/* Line 1792 of yacc.c  */
#line 4686 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; }
    break;

  case 358:
/* Line 1792 of yacc.c  */
#line 4691 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    }
    break;

  case 359:
/* Line 1792 of yacc.c  */
#line 4697 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (5)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (5)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (5)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (5)].l));
    }
    break;

  case 360:
/* Line 1792 of yacc.c  */
#line 4709 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (7)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (7)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(5) - (7)].l)); i++){
        double d;
        List_Read((yyvsp[(5) - (7)].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (7)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(3) - (7)].l));
      List_Delete((yyvsp[(5) - (7)].l));
    }
    break;

  case 361:
/* Line 1792 of yacc.c  */
#line 4727 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr((yyvsp[(6) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(6) - (10)].l), i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(8) - (10)].l), i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (10)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (10)].l), i, &d);
        dim.push_back((int)d);
      }
      GModel::current()->addHomologyRequest((yyvsp[(1) - (10)].c), domain, subdomain, dim);
      List_Delete((yyvsp[(6) - (10)].l));
      List_Delete((yyvsp[(8) - (10)].l));
      List_Delete((yyvsp[(3) - (10)].l));
    }
    break;

  case 362:
/* Line 1792 of yacc.c  */
#line 4754 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           }
    break;

  case 363:
/* Line 1792 of yacc.c  */
#line 4755 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           }
    break;

  case 364:
/* Line 1792 of yacc.c  */
#line 4756 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          }
    break;

  case 365:
/* Line 1792 of yacc.c  */
#line 4757 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           }
    break;

  case 366:
/* Line 1792 of yacc.c  */
#line 4758 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          }
    break;

  case 367:
/* Line 1792 of yacc.c  */
#line 4759 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      }
    break;

  case 368:
/* Line 1792 of yacc.c  */
#line 4760 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      }
    break;

  case 369:
/* Line 1792 of yacc.c  */
#line 4761 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      }
    break;

  case 370:
/* Line 1792 of yacc.c  */
#line 4763 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    }
    break;

  case 371:
/* Line 1792 of yacc.c  */
#line 4769 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); }
    break;

  case 372:
/* Line 1792 of yacc.c  */
#line 4770 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); }
    break;

  case 373:
/* Line 1792 of yacc.c  */
#line 4771 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); }
    break;

  case 374:
/* Line 1792 of yacc.c  */
#line 4772 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  }
    break;

  case 375:
/* Line 1792 of yacc.c  */
#line 4773 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      }
    break;

  case 376:
/* Line 1792 of yacc.c  */
#line 4774 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      }
    break;

  case 377:
/* Line 1792 of yacc.c  */
#line 4775 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     }
    break;

  case 378:
/* Line 1792 of yacc.c  */
#line 4776 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     }
    break;

  case 379:
/* Line 1792 of yacc.c  */
#line 4777 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     }
    break;

  case 380:
/* Line 1792 of yacc.c  */
#line 4778 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     }
    break;

  case 381:
/* Line 1792 of yacc.c  */
#line 4779 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     }
    break;

  case 382:
/* Line 1792 of yacc.c  */
#line 4780 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     }
    break;

  case 383:
/* Line 1792 of yacc.c  */
#line 4781 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); }
    break;

  case 384:
/* Line 1792 of yacc.c  */
#line 4782 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); }
    break;

  case 385:
/* Line 1792 of yacc.c  */
#line 4783 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); }
    break;

  case 386:
/* Line 1792 of yacc.c  */
#line 4784 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      }
    break;

  case 387:
/* Line 1792 of yacc.c  */
#line 4785 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      }
    break;

  case 388:
/* Line 1792 of yacc.c  */
#line 4786 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    }
    break;

  case 389:
/* Line 1792 of yacc.c  */
#line 4787 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     }
    break;

  case 390:
/* Line 1792 of yacc.c  */
#line 4788 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      }
    break;

  case 391:
/* Line 1792 of yacc.c  */
#line 4789 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     }
    break;

  case 392:
/* Line 1792 of yacc.c  */
#line 4790 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      }
    break;

  case 393:
/* Line 1792 of yacc.c  */
#line 4791 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     }
    break;

  case 394:
/* Line 1792 of yacc.c  */
#line 4792 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      }
    break;

  case 395:
/* Line 1792 of yacc.c  */
#line 4793 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     }
    break;

  case 396:
/* Line 1792 of yacc.c  */
#line 4794 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));}
    break;

  case 397:
/* Line 1792 of yacc.c  */
#line 4795 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     }
    break;

  case 398:
/* Line 1792 of yacc.c  */
#line 4796 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     }
    break;

  case 399:
/* Line 1792 of yacc.c  */
#line 4797 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     }
    break;

  case 400:
/* Line 1792 of yacc.c  */
#line 4798 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     }
    break;

  case 401:
/* Line 1792 of yacc.c  */
#line 4799 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); }
    break;

  case 402:
/* Line 1792 of yacc.c  */
#line 4800 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    }
    break;

  case 403:
/* Line 1792 of yacc.c  */
#line 4801 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     }
    break;

  case 404:
/* Line 1792 of yacc.c  */
#line 4802 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); }
    break;

  case 405:
/* Line 1792 of yacc.c  */
#line 4803 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 406:
/* Line 1792 of yacc.c  */
#line 4804 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); }
    break;

  case 407:
/* Line 1792 of yacc.c  */
#line 4805 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); }
    break;

  case 408:
/* Line 1792 of yacc.c  */
#line 4806 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; }
    break;

  case 409:
/* Line 1792 of yacc.c  */
#line 4815 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 410:
/* Line 1792 of yacc.c  */
#line 4816 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; }
    break;

  case 411:
/* Line 1792 of yacc.c  */
#line 4817 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; }
    break;

  case 412:
/* Line 1792 of yacc.c  */
#line 4818 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); }
    break;

  case 413:
/* Line 1792 of yacc.c  */
#line 4819 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); }
    break;

  case 414:
/* Line 1792 of yacc.c  */
#line 4820 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); }
    break;

  case 415:
/* Line 1792 of yacc.c  */
#line 4821 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); }
    break;

  case 416:
/* Line 1792 of yacc.c  */
#line 4822 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); }
    break;

  case 417:
/* Line 1792 of yacc.c  */
#line 4823 "Gmsh.y"
    { (yyval.d) = Cpu(); }
    break;

  case 418:
/* Line 1792 of yacc.c  */
#line 4824 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; }
    break;

  case 419:
/* Line 1792 of yacc.c  */
#line 4825 "Gmsh.y"
    { (yyval.d) = TotalRam(); }
    break;

  case 420:
/* Line 1792 of yacc.c  */
#line 4830 "Gmsh.y"
    { init_options(); }
    break;

  case 421:
/* Line 1792 of yacc.c  */
#line 4832 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    }
    break;

  case 422:
/* Line 1792 of yacc.c  */
#line 4838 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); }
    break;

  case 423:
/* Line 1792 of yacc.c  */
#line 4840 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 424:
/* Line 1792 of yacc.c  */
#line 4845 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 425:
/* Line 1792 of yacc.c  */
#line 4850 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    }
    break;

  case 426:
/* Line 1792 of yacc.c  */
#line 4855 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    }
    break;

  case 427:
/* Line 1792 of yacc.c  */
#line 4860 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    }
    break;

  case 428:
/* Line 1792 of yacc.c  */
#line 4864 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    }
    break;

  case 429:
/* Line 1792 of yacc.c  */
#line 4868 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    }
    break;

  case 430:
/* Line 1792 of yacc.c  */
#line 4872 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    }
    break;

  case 431:
/* Line 1792 of yacc.c  */
#line 4876 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    }
    break;

  case 432:
/* Line 1792 of yacc.c  */
#line 4880 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    }
    break;

  case 433:
/* Line 1792 of yacc.c  */
#line 4884 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    }
    break;

  case 434:
/* Line 1792 of yacc.c  */
#line 4888 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 435:
/* Line 1792 of yacc.c  */
#line 4894 "Gmsh.y"
    {
      if(gmsh_yysymbols.count((yyvsp[(2) - (4)].c))){
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(2) - (4)].c)]);
	(yyval.d) = s.value.size();
      }
      else if(gmsh_yystringsymbols.count((yyvsp[(2) - (4)].c))){
	(yyval.d) = gmsh_yystringsymbols[(yyvsp[(2) - (4)].c)].size();
      }
      else{
        yymsg(0, "Unknown variable '%s'", (yyvsp[(2) - (4)].c));
	(yyval.d) = 0.;
      }
      Free((yyvsp[(2) - (4)].c));
    }
    break;

  case 436:
/* Line 1792 of yacc.c  */
#line 4910 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    }
    break;

  case 437:
/* Line 1792 of yacc.c  */
#line 4915 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 438:
/* Line 1792 of yacc.c  */
#line 4921 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    }
    break;

  case 439:
/* Line 1792 of yacc.c  */
#line 4927 "Gmsh.y"
    {
      if(!gmsh_yysymbols.count((yyvsp[(1) - (2)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (2)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (2)].c)]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", (yyvsp[(1) - (2)].c));
          (yyval.d) = 0.;
        }
        else{
          (yyval.d) = s.value[0];
          s.value[0] += (yyvsp[(2) - (2)].i);
        }
      }
      Free((yyvsp[(1) - (2)].c));
    }
    break;

  case 440:
/* Line 1792 of yacc.c  */
#line 4946 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (5)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
          (yyval.d) = 0.;
        }
        else{
          (yyval.d) = s.value[index];
          s.value[index] += (yyvsp[(5) - (5)].i);
        }
      }
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 441:
/* Line 1792 of yacc.c  */
#line 4967 "Gmsh.y"
    {
      int index = (int)(yyvsp[(3) - (5)].d);
      if(!gmsh_yysymbols.count((yyvsp[(1) - (5)].c))){
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (5)].c));
	(yyval.d) = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (5)].c)]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (5)].c), index);
          (yyval.d) = 0.;
        }
        else{
          (yyval.d) = s.value[index];
          s.value[index] += (yyvsp[(5) - (5)].i);
        }
      }
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 442:
/* Line 1792 of yacc.c  */
#line 5000 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    }
    break;

  case 443:
/* Line 1792 of yacc.c  */
#line 5004 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    }
    break;

  case 444:
/* Line 1792 of yacc.c  */
#line 5009 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    }
    break;

  case 445:
/* Line 1792 of yacc.c  */
#line 5013 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    }
    break;

  case 446:
/* Line 1792 of yacc.c  */
#line 5017 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    }
    break;

  case 447:
/* Line 1792 of yacc.c  */
#line 5021 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    }
    break;

  case 448:
/* Line 1792 of yacc.c  */
#line 5026 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 449:
/* Line 1792 of yacc.c  */
#line 5031 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d)){
	d += (yyvsp[(4) - (4)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (4)].c), 0, (yyvsp[(3) - (4)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (4)].c)); Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 450:
/* Line 1792 of yacc.c  */
#line 5041 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d)){
	d += (yyvsp[(7) - (7)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c), d);
	(yyval.d) = d;
      }
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    }
    break;

  case 451:
/* Line 1792 of yacc.c  */
#line 5051 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 452:
/* Line 1792 of yacc.c  */
#line 5056 "Gmsh.y"
    {
      int matches = 0;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (6)].l)); i++){
        double d;
        List_Read((yyvsp[(3) - (6)].l), i, &d);
        matches += List_Search((yyvsp[(5) - (6)].l), &d, fcmp_double);
      }
      (yyval.d) = matches;
      Free((yyvsp[(3) - (6)].l)); Free((yyvsp[(5) - (6)].l));
    }
    break;

  case 453:
/* Line 1792 of yacc.c  */
#line 5067 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 454:
/* Line 1792 of yacc.c  */
#line 5076 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 455:
/* Line 1792 of yacc.c  */
#line 5081 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 456:
/* Line 1792 of yacc.c  */
#line 5086 "Gmsh.y"
    {
      int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
      if(List_Nbr((yyvsp[(3) - (4)].l)) % 2){
        yymsg(0, "Number of text attributes should be even");
      }
      else{
        for(int i = 0 ; i < List_Nbr((yyvsp[(3) - (4)].l)); i += 2){
          char *s1, *s2; List_Read((yyvsp[(3) - (4)].l), i, &s1); List_Read((yyvsp[(3) - (4)].l), i + 1, &s2);
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
      List_Delete((yyvsp[(3) - (4)].l));
      (yyval.d) = (double)((align<<16)|(font<<8)|(fontsize));
    }
    break;

  case 457:
/* Line 1792 of yacc.c  */
#line 5113 "Gmsh.y"
    { (yyval.d) = 0.; }
    break;

  case 458:
/* Line 1792 of yacc.c  */
#line 5115 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);}
    break;

  case 459:
/* Line 1792 of yacc.c  */
#line 5120 "Gmsh.y"
    { (yyval.c) = NULL; }
    break;

  case 460:
/* Line 1792 of yacc.c  */
#line 5122 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);}
    break;

  case 461:
/* Line 1792 of yacc.c  */
#line 5127 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
    break;

  case 462:
/* Line 1792 of yacc.c  */
#line 5134 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (7)].c2).char1? (yyvsp[(2) - (7)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (7)].c2).char2);
      Free((yyvsp[(2) - (7)].c2).char1); Free((yyvsp[(2) - (7)].c2).char2);
      int tag_out;
      if (gmsh_yynamespaces.defStruct(struct_namespace, struct_name,
                                      floatOptions, charOptions,
                                      tag_out, member_ValMax, (yyvsp[(3) - (7)].i)))
        yymsg(0, "Redefinition of Struct '%s::%s'",
              struct_namespace.c_str(), struct_name.c_str());
      (yyval.d) = (double)tag_out;
    }
    break;

  case 463:
/* Line 1792 of yacc.c  */
#line 5150 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); }
    break;

  case 464:
/* Line 1792 of yacc.c  */
#line 5152 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); }
    break;

  case 465:
/* Line 1792 of yacc.c  */
#line 5157 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; }
    break;

  case 466:
/* Line 1792 of yacc.c  */
#line 5166 "Gmsh.y"
    { (yyval.i) = 99; }
    break;

  case 467:
/* Line 1792 of yacc.c  */
#line 5168 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); }
    break;

  case 468:
/* Line 1792 of yacc.c  */
#line 5173 "Gmsh.y"
    { (yyval.i) = 0; }
    break;

  case 469:
/* Line 1792 of yacc.c  */
#line 5175 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); }
    break;

  case 470:
/* Line 1792 of yacc.c  */
#line 5180 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    }
    break;

  case 471:
/* Line 1792 of yacc.c  */
#line 5184 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 472:
/* Line 1792 of yacc.c  */
#line 5188 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    }
    break;

  case 473:
/* Line 1792 of yacc.c  */
#line 5192 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 474:
/* Line 1792 of yacc.c  */
#line 5196 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    }
    break;

  case 475:
/* Line 1792 of yacc.c  */
#line 5203 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    }
    break;

  case 476:
/* Line 1792 of yacc.c  */
#line 5207 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    }
    break;

  case 477:
/* Line 1792 of yacc.c  */
#line 5211 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 478:
/* Line 1792 of yacc.c  */
#line 5215 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    }
    break;

  case 479:
/* Line 1792 of yacc.c  */
#line 5222 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    }
    break;

  case 480:
/* Line 1792 of yacc.c  */
#line 5227 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    }
    break;

  case 481:
/* Line 1792 of yacc.c  */
#line 5234 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 482:
/* Line 1792 of yacc.c  */
#line 5239 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 483:
/* Line 1792 of yacc.c  */
#line 5243 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    }
    break;

  case 484:
/* Line 1792 of yacc.c  */
#line 5248 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 485:
/* Line 1792 of yacc.c  */
#line 5252 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 486:
/* Line 1792 of yacc.c  */
#line 5260 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    }
    break;

  case 487:
/* Line 1792 of yacc.c  */
#line 5271 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 488:
/* Line 1792 of yacc.c  */
#line 5275 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (1)].c), "*") || !strcmp((yyvsp[(1) - (1)].c), "all"))
        (yyval.l) = 0;
      else{
        yyerror("Unknown special string for list replacement");
        (yyval.l) = List_Create(2, 1, sizeof(double));
      }
    }
    break;

  case 489:
/* Line 1792 of yacc.c  */
#line 5287 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    }
    break;

  case 490:
/* Line 1792 of yacc.c  */
#line 5295 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    }
    break;

  case 491:
/* Line 1792 of yacc.c  */
#line 5303 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    }
    break;

  case 492:
/* Line 1792 of yacc.c  */
#line 5310 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!(yyvsp[(5) - (5)].d)){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", (yyvsp[(1) - (5)].d), (yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].d));
      }
      else
	for(double d = (yyvsp[(1) - (5)].d); ((yyvsp[(5) - (5)].d) > 0) ? (d <= (yyvsp[(3) - (5)].d)) : (d >= (yyvsp[(3) - (5)].d)); d += (yyvsp[(5) - (5)].d))
	  List_Add((yyval.l), &d);
   }
    break;

  case 493:
/* Line 1792 of yacc.c  */
#line 5320 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 1, sizeof(double));
      int tag = (int)(yyvsp[(3) - (4)].d);
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
    break;

  case 494:
/* Line 1792 of yacc.c  */
#line 5343 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    }
    break;

  case 495:
/* Line 1792 of yacc.c  */
#line 5349 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      if(!(yyvsp[(3) - (3)].l)){
        getAllPhysicalTags((yyvsp[(2) - (3)].i), (yyval.l));
      }
      else{
        getElementaryTagsForPhysicalGroups((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
        List_Delete((yyvsp[(3) - (3)].l));
      }
    }
    break;

  case 496:
/* Line 1792 of yacc.c  */
#line 5361 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    }
    break;

  case 497:
/* Line 1792 of yacc.c  */
#line 5366 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    }
    break;

  case 498:
/* Line 1792 of yacc.c  */
#line 5376 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    }
    break;

  case 499:
/* Line 1792 of yacc.c  */
#line 5386 "Gmsh.y"
    {
      (yyval.l) = List_Create(List_Nbr((yyvsp[(1) - (1)].l)), 1, sizeof(double));
      for(int i = 0; i < List_Nbr((yyvsp[(1) - (1)].l)); i++){
	Shape *s = (Shape*) List_Pointer((yyvsp[(1) - (1)].l), i);
	double d = s->Num;
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(1) - (1)].l));
    }
    break;

  case 500:
/* Line 1792 of yacc.c  */
#line 5396 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 501:
/* Line 1792 of yacc.c  */
#line 5408 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    }
    break;

  case 502:
/* Line 1792 of yacc.c  */
#line 5412 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    }
    break;

  case 503:
/* Line 1792 of yacc.c  */
#line 5417 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(3) - (4)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(3) - (4)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(3) - (4)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 504:
/* Line 1792 of yacc.c  */
#line 5429 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    }
    break;

  case 505:
/* Line 1792 of yacc.c  */
#line 5433 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    }
    break;

  case 506:
/* Line 1792 of yacc.c  */
#line 5437 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    }
    break;

  case 507:
/* Line 1792 of yacc.c  */
#line 5441 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (6)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (6)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (6)].c)]);
	for(int i = 0; i < List_Nbr((yyvsp[(4) - (6)].l)); i++){
	  int index = (int)(*(double*)List_Pointer_Fast((yyvsp[(4) - (6)].l), i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", (yyvsp[(1) - (6)].c), index);
	  else
	    List_Add((yyval.l), &s.value[index]);
	}
      }
      Free((yyvsp[(1) - (6)].c));
      List_Delete((yyvsp[(4) - (6)].l));
    }
    break;

  case 508:
/* Line 1792 of yacc.c  */
#line 5459 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 509:
/* Line 1792 of yacc.c  */
#line 5467 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    }
    break;

  case 510:
/* Line 1792 of yacc.c  */
#line 5475 "Gmsh.y"
    {
      Msg::Barrier();
      FILE *File;
      (yyval.l) = List_Create(100, 100, sizeof(double));
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      if(!(File = Fopen(tmp.c_str(), "rb"))){
        yymsg(0, "Could not open file '%s'", (yyvsp[(3) - (4)].c));
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
            yymsg(0, "Ignoring '%s' in file '%s'", dummy, (yyvsp[(3) - (4)].c));
          }
        }
	fclose(File);
      }
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 511:
/* Line 1792 of yacc.c  */
#line 5504 "Gmsh.y"
    {
      double x0 = (yyvsp[(3) - (14)].d), x1 = (yyvsp[(5) - (14)].d), y0 = (yyvsp[(7) - (14)].d), y1 = (yyvsp[(9) - (14)].d), ys = (yyvsp[(11) - (14)].d);
      int N = (int)(yyvsp[(13) - (14)].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    }
    break;

  case 512:
/* Line 1792 of yacc.c  */
#line 5514 "Gmsh.y"
    {
      std::vector<double> tmp;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double d; List_Read((yyvsp[(3) - (4)].l), i, &d);
        tmp.push_back(d);
      }
      std::sort(tmp.begin(), tmp.end());
      std::vector<double>::iterator last = std::unique(tmp.begin(), tmp.end());
      tmp.erase(last, tmp.end());
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      for(unsigned int i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    }
    break;

  case 513:
/* Line 1792 of yacc.c  */
#line 5530 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    }
    break;

  case 514:
/* Line 1792 of yacc.c  */
#line 5541 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    }
    break;

  case 515:
/* Line 1792 of yacc.c  */
#line 5546 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    }
    break;

  case 516:
/* Line 1792 of yacc.c  */
#line 5550 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    }
    break;

  case 517:
/* Line 1792 of yacc.c  */
#line 5554 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 518:
/* Line 1792 of yacc.c  */
#line 5566 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    }
    break;

  case 519:
/* Line 1792 of yacc.c  */
#line 5570 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    }
    break;

  case 520:
/* Line 1792 of yacc.c  */
#line 5582 "Gmsh.y"
    {
      int flag = 0;
      if(gmsh_yystringsymbols.count((yyvsp[(1) - (1)].c))){
        if(gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)].size()){
          (yyval.u) = GetColorForString(-1, gmsh_yystringsymbols[(yyvsp[(1) - (1)].c)][0].c_str(), &flag);
        }
        else{
          yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
          (yyval.u) = 0;
        }
      }
      else
        (yyval.u) = GetColorForString(-1, (yyvsp[(1) - (1)].c), &flag);
      if(flag) yymsg(0, "Unknown color '%s'", (yyvsp[(1) - (1)].c));
      Free((yyvsp[(1) - (1)].c));
    }
    break;

  case 521:
/* Line 1792 of yacc.c  */
#line 5599 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    }
    break;

  case 522:
/* Line 1792 of yacc.c  */
#line 5609 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    }
    break;

  case 523:
/* Line 1792 of yacc.c  */
#line 5613 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = GetColorTable((int)(yyvsp[(3) - (6)].d));
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)(yyvsp[(3) - (6)].d));
      else{
	for(int i = 0; i < ct->size; i++)
	  List_Add((yyval.l), &ct->table[i]);
      }
      Free((yyvsp[(1) - (6)].c));
    }
    break;

  case 524:
/* Line 1792 of yacc.c  */
#line 5628 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    }
    break;

  case 525:
/* Line 1792 of yacc.c  */
#line 5633 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    }
    break;

  case 526:
/* Line 1792 of yacc.c  */
#line 5640 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 527:
/* Line 1792 of yacc.c  */
#line 5644 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    }
    break;

  case 528:
/* Line 1792 of yacc.c  */
#line 5649 "Gmsh.y"
    {
      std::string val;
      int j = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (4)].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (4)].c));
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(1) - (4)].c));
    }
    break;

  case 529:
/* Line 1792 of yacc.c  */
#line 5663 "Gmsh.y"
    {
      std::string val;
      int j = (int)(yyvsp[(3) - (4)].d);
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (4)].c)))
        yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (4)].c));
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)].size())
        val = gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)][j];
      else
        yymsg(0, "Index %d out of range", j);
      (yyval.c) = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(1) - (4)].c));
    }
    break;

  case 530:
/* Line 1792 of yacc.c  */
#line 5679 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    }
    break;

  case 531:
/* Line 1792 of yacc.c  */
#line 5683 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    }
    break;

  case 532:
/* Line 1792 of yacc.c  */
#line 5687 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    }
    break;

  case 533:
/* Line 1792 of yacc.c  */
#line 5691 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    }
    break;

  case 534:
/* Line 1792 of yacc.c  */
#line 5695 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    }
    break;

  case 535:
/* Line 1792 of yacc.c  */
#line 5703 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
    break;

  case 536:
/* Line 1792 of yacc.c  */
#line 5709 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
    break;

  case 537:
/* Line 1792 of yacc.c  */
#line 5715 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
    break;

  case 538:
/* Line 1792 of yacc.c  */
#line 5721 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    }
    break;

  case 539:
/* Line 1792 of yacc.c  */
#line 5730 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    }
    break;

  case 540:
/* Line 1792 of yacc.c  */
#line 5734 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 541:
/* Line 1792 of yacc.c  */
#line 5738 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    }
    break;

  case 542:
/* Line 1792 of yacc.c  */
#line 5746 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    }
    break;

  case 543:
/* Line 1792 of yacc.c  */
#line 5752 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    }
    break;

  case 544:
/* Line 1792 of yacc.c  */
#line 5758 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    }
    break;

  case 545:
/* Line 1792 of yacc.c  */
#line 5762 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 546:
/* Line 1792 of yacc.c  */
#line 5770 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 547:
/* Line 1792 of yacc.c  */
#line 5778 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 548:
/* Line 1792 of yacc.c  */
#line 5785 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    }
    break;

  case 549:
/* Line 1792 of yacc.c  */
#line 5794 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    }
    break;

  case 550:
/* Line 1792 of yacc.c  */
#line 5798 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    }
    break;

  case 551:
/* Line 1792 of yacc.c  */
#line 5802 "Gmsh.y"
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[(3) - (4)].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        char *s;
        List_Read((yyvsp[(3) - (4)].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 552:
/* Line 1792 of yacc.c  */
#line 5817 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[(3) - (4)].c)) - 1; i >= 0; i--){
	if((yyvsp[(3) - (4)].c)[i] == '.'){
	  strncpy((yyval.c), (yyvsp[(3) - (4)].c), i);
	  (yyval.c)[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy((yyval.c), (yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 553:
/* Line 1792 of yacc.c  */
#line 5831 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (4)].c)) + 1) * sizeof(char));
      int i;
      for(i = strlen((yyvsp[(3) - (4)].c)) - 1; i >= 0; i--){
	if((yyvsp[(3) - (4)].c)[i] == '/' || (yyvsp[(3) - (4)].c)[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy((yyval.c), (yyvsp[(3) - (4)].c));
      else
	strcpy((yyval.c), &(yyvsp[(3) - (4)].c)[i+1]);
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 554:
/* Line 1792 of yacc.c  */
#line 5845 "Gmsh.y"
    {
      std::string input = (yyvsp[(3) - (8)].c);
      std::string substr_old = (yyvsp[(5) - (8)].c);
      std::string substr_new = (yyvsp[(7) - (8)].c);
      std::string ret = ReplaceSubString(substr_old, substr_new, input);
      (yyval.c) = (char *)Malloc((ret.size() + 1) * sizeof(char));
      strcpy((yyval.c), ret.c_str());
      Free((yyvsp[(3) - (8)].c));
      Free((yyvsp[(5) - (8)].c));
      Free((yyvsp[(7) - (8)].c));
    }
    break;

  case 555:
/* Line 1792 of yacc.c  */
#line 5857 "Gmsh.y"
    {
      int size = 1;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++)
        size += strlen(*(char**)List_Pointer((yyvsp[(3) - (4)].l), i)) + 1;
      (yyval.c) = (char*)Malloc(size * sizeof(char));
      (yyval.c)[0] = '\0';
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        char *s;
        List_Read((yyvsp[(3) - (4)].l), i, &s);
        strcat((yyval.c), s);
        Free(s);
        if(i != List_Nbr((yyvsp[(3) - (4)].l)) - 1) strcat((yyval.c), "\n");
      }
      List_Delete((yyvsp[(3) - (4)].l));
    }
    break;

  case 556:
/* Line 1792 of yacc.c  */
#line 5873 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 557:
/* Line 1792 of yacc.c  */
#line 5882 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 558:
/* Line 1792 of yacc.c  */
#line 5891 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        if (i > 0 && (yyvsp[(3) - (4)].c)[i-1] != '_')
          (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 559:
/* Line 1792 of yacc.c  */
#line 5901 "Gmsh.y"
    {
      if((yyvsp[(3) - (8)].d)){
        (yyval.c) = (yyvsp[(5) - (8)].c);
        Free((yyvsp[(7) - (8)].c));
      }
      else{
        (yyval.c) = (yyvsp[(7) - (8)].c);
        Free((yyvsp[(5) - (8)].c));
      }
    }
    break;

  case 560:
/* Line 1792 of yacc.c  */
#line 5912 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    }
    break;

  case 561:
/* Line 1792 of yacc.c  */
#line 5920 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 562:
/* Line 1792 of yacc.c  */
#line 5928 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    }
    break;

  case 563:
/* Line 1792 of yacc.c  */
#line 5932 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].l), tmpstring);
      if(i < 0){
	yymsg(0, "Too few arguments in Sprintf");
	(yyval.c) = (yyvsp[(3) - (6)].c);
      }
      else if(i > 0){
	yymsg(0, "%d extra argument%s in Sprintf", i, (i > 1) ? "s" : "");
	(yyval.c) = (yyvsp[(3) - (6)].c);
      }
      else{
	(yyval.c) = (char*)Malloc((strlen(tmpstring) + 1) * sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[(3) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    }
    break;

  case 564:
/* Line 1792 of yacc.c  */
#line 5951 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 565:
/* Line 1792 of yacc.c  */
#line 5958 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    }
    break;

  case 566:
/* Line 1792 of yacc.c  */
#line 5964 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 567:
/* Line 1792 of yacc.c  */
#line 5971 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    }
    break;

  case 568:
/* Line 1792 of yacc.c  */
#line 5978 "Gmsh.y"
    { init_options(); }
    break;

  case 569:
/* Line 1792 of yacc.c  */
#line 5980 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    }
    break;

  case 570:
/* Line 1792 of yacc.c  */
#line 5988 "Gmsh.y"
    {
      std::string out;
      const std::string * key_struct = NULL;
      switch (gmsh_yynamespaces.get_key_struct_from_tag(struct_namespace,
                                                        (int)(yyvsp[(3) - (4)].d), key_struct)) {
      case 0:
        out = *key_struct;
        break;
      case 1:
        yymsg(1, "Unknown NameSpace '%s' of Struct", struct_namespace.c_str());
        break;
      case 2:
        yymsg(1, "Unknown Struct of index %d", (int)(yyvsp[(3) - (4)].d));
        break;
      default:
        break;
      }
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
    }
    break;

  case 571:
/* Line 1792 of yacc.c  */
#line 6012 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); }
    break;

  case 572:
/* Line 1792 of yacc.c  */
#line 6014 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); }
    break;

  case 573:
/* Line 1792 of yacc.c  */
#line 6020 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); }
    break;

  case 574:
/* Line 1792 of yacc.c  */
#line 6025 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 575:
/* Line 1792 of yacc.c  */
#line 6027 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 576:
/* Line 1792 of yacc.c  */
#line 6032 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); }
    break;

  case 577:
/* Line 1792 of yacc.c  */
#line 6037 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    }
    break;

  case 578:
/* Line 1792 of yacc.c  */
#line 6042 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); }
    break;

  case 579:
/* Line 1792 of yacc.c  */
#line 6044 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    }
    break;

  case 580:
/* Line 1792 of yacc.c  */
#line 6048 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    }
    break;

  case 581:
/* Line 1792 of yacc.c  */
#line 6060 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(char *));
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.size(); i++) {
          char * val_ = strsave((char*)s.at(i).c_str());
	  List_Add((yyval.l), &val_);
        }
      }
      Free((yyvsp[(1) - (3)].c));
    }
    break;

  case 582:
/* Line 1792 of yacc.c  */
#line 6074 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    }
    break;

  case 583:
/* Line 1792 of yacc.c  */
#line 6078 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    }
    break;

  case 584:
/* Line 1792 of yacc.c  */
#line 6085 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 585:
/* Line 1792 of yacc.c  */
#line 6093 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    }
    break;

  case 586:
/* Line 1792 of yacc.c  */
#line 6101 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    }
    break;

  case 587:
/* Line 1792 of yacc.c  */
#line 6112 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 588:
/* Line 1792 of yacc.c  */
#line 6114 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 589:
/* Line 1792 of yacc.c  */
#line 6117 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); }
    break;


/* Line 1792 of yacc.c  */
#line 13754 "Gmsh.tab.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 6120 "Gmsh.y"


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
