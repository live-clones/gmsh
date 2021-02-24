%{
// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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

%}

%union {
  char *c;
  int i;
  unsigned int u;
  double d;
  double v[5];
  Shape s;
  List_T *l;
  struct TwoChar c2;
}

%token <d> tDOUBLE
%token <c> tSTRING tBIGSTR

%token tEND tAFFECT tDOTS tSCOPE tPi tMPI_Rank tMPI_Size tEuclidian tCoordinates tTestLevel
%token tExp tLog tLog10 tSqrt tSin tAsin tCos tAcos tTan tRand
%token tAtan tAtan2 tSinh tCosh tTanh tFabs tAbs tFloor tCeil tRound tMin tMax
%token tFmod tModulo tHypot tList tLinSpace tLogSpace tListFromFile tCatenary
%token tPrintf tError tWarning tStr tSprintf tStrCat tStrPrefix tStrRelative tStrReplace
%token tAbsolutePath tDirName tStrSub tStrLen
%token tFind tStrFind tStrCmp tStrChoice tUpperCase tLowerCase tLowerCaseIn
%token tTextAttributes
%token tBoundingBox tDraw tSetChanged tToday tFixRelativePath
%token tCurrentDirectory tCurrentFileName
%token tSyncModel tNewModel tMass tCenterOfMass tMatrixOfInertia
%token tOnelabAction tOnelabRun tCodeName
%token tCpu tMemory tTotalMemory
%token tCreateTopology tCreateGeometry tClassifySurfaces
%token tRenumberMeshNodes tRenumberMeshElements
%token tDistanceFunction tDefineConstant tUndefineConstant
%token tDefineNumber tDefineStruct tNameStruct tDimNameSpace tAppend
%token tDefineString tSetNumber tSetTag tSetString
%token tPoint tCircle tEllipse tCurve tSphere tPolarSphere tSurface tSpline tVolume
%token tBox tCylinder tCone tTorus tEllipsoid tQuadric tShapeFromFile
%token tRectangle tDisk tWire tGeoEntity
%token tCharacteristic tLength tParametric tElliptic
%token tRefineMesh tRecombineMesh tAdaptMesh
%token tRelocateMesh tReorientMesh tSetFactory tThruSections tWedge tFillet tChamfer
%token tPlane tRuled tTransfinite tPhysical tCompound tPeriodic tParent
%token tUsing tPlugin tDegenerated tRecursive tSewing
%token tRotate tTranslate tSymmetry tDilate tExtrude tLevelset tAffine
%token tBooleanUnion tBooleanIntersection tBooleanDifference tBooleanSection
%token tBooleanFragments tThickSolid
%token tRecombine tSmoother tSplit tDelete tCoherence
%token tIntersect tMeshAlgorithm tReverseMesh tMeshSize tMeshSizeFromBoundary
%token tLayers tScaleLast tHole tAlias tAliasWithOptions tCopyOptions
%token tQuadTriAddVerts tQuadTriNoNewVerts
%token tRecombLaterals tTransfQuadTri
%token tText2D tText3D tInterpolationScheme tTime tCombine
%token tBSpline tBezier tNurbs tNurbsOrder tNurbsKnots
%token tColor tColorTable tFor tIn tEndFor tIf tElseIf tElse tEndIf tExit tAbort
%token tField tReturn tCall tSlide tMacro tShow tHide tGetValue tGetStringValue tGetEnv
%token tGetString tGetNumber tUnique tSetMaxTag
%token tHomology tCohomology tBetti tExists tFileExists tGetForced tGetForcedStr
%token tGMSH_MAJOR_VERSION tGMSH_MINOR_VERSION tGMSH_PATCH_VERSION
%token tGmshExecutableName tSetPartition
%token tNameToString tStringToName tUnsplitWindow

%type <d> FExpr FExpr_Single DefineStruct NameStruct_Arg GetForced_Default
%type <d> LoopOptions
%type <v> VExpr VExpr_Single CircleOptions TransfiniteType
%type <i> NumericAffectation NumericIncrement BooleanOperator BooleanOption
%type <i> PhysicalId_per_dim_entity GeoEntity GeoEntity123 GeoEntity12 GeoEntity02
%type <i> TransfiniteArrangement RecombineAngle
%type <i> Append AppendOrNot
%type <u> ColorExpr
%type <c> StringExpr StringExprVar SendToFile HomologyCommand
%type <c> LP RP tSTRING_Reserved GetForcedStr_Default
%type <c> StringIndex String__Index
%type <l> MultiStringExprVar SurfaceConstraints
%type <l> RecursiveListOfStringExprVar Str_BracedRecursiveListOfStringExprVar
%type <l> BracedOrNotRecursiveListOfStringExprVar BracedRecursiveListOfStringExprVar
%type <l> FExpr_Multi ListOfDouble ListOfDoubleOrAll RecursiveListOfDouble
%type <l> RecursiveListOfListOfDouble Enumeration
%type <l> ListOfColor RecursiveListOfColor
%type <l> ListOfShapes Transform Extrude MultipleShape Boolean
%type <l> TransfiniteCorners PeriodicTransform
%type <s> Shape
%type <c2> Struct_FullName

// Operators (with ascending priority): cf. C language
//
// Notes: - associativity (%left, %right)
//        - UNARYPREC is a dummy terminal to resolve ambiguous cases
//          for + and - (which exist in both unary and binary form)

%right   tAFFECT tAFFECTPLUS tAFFECTMINUS tAFFECTTIMES tAFFECTDIVIDE
%right   '?' tDOTS
%left    tOR
%left    tAND
%left    tEQUAL tNOTEQUAL
%left    '<' tLESSOREQUAL  '>' tGREATEROREQUAL tLESSLESS tGREATERGREATER
%left    '+' '-'
%left    '*' '/' '%'
%left    '|' '&'
%right   '!' tPLUSPLUS tMINUSMINUS UNARYPREC
%right   '^'
%left    '(' ')' '[' ']' '{' '}' '.' '#'
%left    '~'
%left    tSCOPE

%start All

%%

All :
    GeoFormatItems
  | error tEND { yyerrok; return 1; }
;

//  G E O   F I L E   F O R M A T

GeoFormatItems :
    // nothing
  | GeoFormatItems GeoFormatItem
;

GeoFormatItem :
    Printf      { return 1; }
  | View        { return 1; }
  | Affectation { return 1; }
  | tSetFactory '(' StringExprVar ')' tEND
    {
      gmsh_yyfactory = $3;
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
          yymsg(1, "Unknown factory \"%s\" - using \"Built-in\" instead", $3);
        if(GModel::current()->getOCCInternals()){
          for(int dim = -2; dim <= 3; dim++)
            GModel::current()->getGEOInternals()->setMaxTag
              (dim, std::max(GModel::current()->getGEOInternals()->getMaxTag(dim),
                             GModel::current()->getOCCInternals()->getMaxTag(dim)));
        }
      }
      Free($3);
    }
  | Shape       { return 1; }
  | Transform   { List_Delete($1); return 1; }
  | Delete      { return 1; }
  | Colorify    { return 1; }
  | SetPartition{ return 1; }
  | Visibility  { return 1; }
  | Extrude     { List_Delete($1); return 1; }
  | Boolean     { List_Delete($1); return 1; }
  | BooleanShape{ return 1; }
  | Constraints { return 1; }
  | Coherence   { return 1; }
  | Loop        { return 1; }
  | Slide       { return 1; }
  | Command     { return 1; }
  | LevelSet    { return 1; }
  | Homology    { return 1; }
;

SendToFile :
    '>'
    {
      $$ = (char*)"w";
    }
  | tGREATERGREATER
    {
      $$ = (char*)"a";
    }
;

Printf :
    tPrintf '(' StringExprVar ')' tEND
    {
      Msg::Direct($3);
      Free($3);
    }
  | tWarning '(' StringExprVar ')' tEND
    {
      Msg::Warning($3);
      Free($3);
    }
  | tError '(' StringExprVar ')' tEND
    {
      Msg::Error($3);
      Free($3);
    }
  | tPrintf '(' StringExprVar ')' SendToFile StringExprVar tEND
    {
      std::string tmp = FixRelativePath(gmsh_yyname, $6);
      FILE *fp = Fopen(tmp.c_str(), $5);
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmp.c_str());
      }
      else{
	fprintf(fp, "%s\n", $3);
	fclose(fp);
      }
      Free($3);
      Free($6);
    }
  | tPrintf '(' StringExprVar ',' RecursiveListOfDouble ')' tEND
    {
      char tmpstring[5000];
      int i = printListOfDouble($3, $5, tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free($3);
      List_Delete($5);
    }
  | tWarning '(' StringExprVar ',' RecursiveListOfDouble ')' tEND
    {
      char tmpstring[5000];
      int i = printListOfDouble($3, $5, tmpstring);
      if(i < 0)
	yymsg(1, "Too few arguments in Error");
      else if(i > 0)
	yymsg(1, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Warning(tmpstring);
      Free($3);
      List_Delete($5);
    }
  | tError '(' StringExprVar ',' RecursiveListOfDouble ')' tEND
    {
      char tmpstring[5000];
      int i = printListOfDouble($3, $5, tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring);
      Free($3);
      List_Delete($5);
    }
  | tPrintf '(' StringExprVar ',' RecursiveListOfDouble ')' SendToFile StringExprVar tEND
    {
      char tmpstring[5000];
      int i = printListOfDouble($3, $5, tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
        std::string tmp = FixRelativePath(gmsh_yyname, $8);
	FILE *fp = Fopen(tmp.c_str(), $7);
	if(!fp){
	  yymsg(0, "Unable to open file '%s'", tmp.c_str());
	}
	else{
	  fprintf(fp, "%s\n", tmpstring);
	  fclose(fp);
	}
      }
      Free($3);
      Free($8);
      List_Delete($5);
    }
;

// V I E W

View :
    String__Index StringExprVar '{' Views '}' tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($1, "View") && ViewData->finalize()){
	ViewData->setName($2);
	ViewData->setFileName(gmsh_yyname);
	ViewData->setFileIndex(gmsh_yyviewindex++);
	new PView(ViewData);
      }
      else
	delete ViewData;
#endif
      Free($1); Free($2);
    }
  | tAlias tSTRING '[' FExpr ']' tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($2, "View")){
	int index = (int)$4;
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free($2);
    }
  | tAliasWithOptions tSTRING '[' FExpr ']' tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($2, "View")){
	int index = (int)$4;
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
        else
	  yymsg(0, "Unknown view %d", index);
      }
#endif
      Free($2);
    }
  | tCopyOptions tSTRING '[' FExpr ',' FExpr ']' tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($2, "View")){
	int index = (int)$4, index2 = (int)$6;
	if(index >= 0 && index < (int)PView::list.size() &&
           index2 >= 0 && index2 < (int)PView::list.size()){
          PView::list[index2]->setOptions(PView::list[index]->getOptions());
        }
        else
	  yymsg(0, "Unknown view %d or %d", index, index2);
      }
#endif
      Free($2);
    }
;

Views :
    // nothing
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    }
  | Views Element
  | Views Text2D
  | Views Text3D
  | Views InterpolationMatrix
  | Views Time
  | Views Loop
;

ElementCoords :
    FExpr
    { ViewCoord.push_back($1); }
  | ElementCoords ',' FExpr
    { ViewCoord.push_back($3); }
;

ElementValues :
    FExpr
    { if(ViewValueList) ViewValueList->push_back($1); }
  | ElementValues ',' FExpr
    { if(ViewValueList) ViewValueList->push_back($3); }
;

Element :
    tSTRING
    {
#if defined(HAVE_POST)
      if(!strncmp($1, "SP", 2)){
	ViewValueList = &ViewData->SP; ViewNumList = &ViewData->NbSP;
      }
      else if(!strncmp($1, "VP", 2)){
	ViewValueList = &ViewData->VP; ViewNumList = &ViewData->NbVP;
      }
      else if(!strncmp($1, "TP", 2)){
	ViewValueList = &ViewData->TP; ViewNumList = &ViewData->NbTP;
      }
      else if(!strncmp($1, "SL", 2)){
	ViewValueList = &ViewData->SL; ViewNumList = &ViewData->NbSL;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp($1, "VL", 2)){
	ViewValueList = &ViewData->VL; ViewNumList = &ViewData->NbVL;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp($1, "TL", 2)){
	ViewValueList = &ViewData->TL; ViewNumList = &ViewData->NbTL;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_LIN);
      }
      else if(!strncmp($1, "ST", 2)){
	ViewValueList = &ViewData->ST; ViewNumList = &ViewData->NbST;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp($1, "VT", 2)){
	ViewValueList = &ViewData->VT; ViewNumList = &ViewData->NbVT;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp($1, "TT", 2)){
	ViewValueList = &ViewData->TT; ViewNumList = &ViewData->NbTT;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_TRI);
      }
      else if(!strncmp($1, "SQ", 2)){
	ViewValueList = &ViewData->SQ; ViewNumList = &ViewData->NbSQ;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp($1, "VQ", 2)){
	ViewValueList = &ViewData->VQ; ViewNumList = &ViewData->NbVQ;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp($1, "TQ", 2)){
	ViewValueList = &ViewData->TQ; ViewNumList = &ViewData->NbTQ;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_QUA);
      }
      else if(!strncmp($1, "SS", 2)){
	ViewValueList = &ViewData->SS; ViewNumList = &ViewData->NbSS;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp($1, "VS", 2)){
	ViewValueList = &ViewData->VS; ViewNumList = &ViewData->NbVS;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp($1, "TS", 2)){
	ViewValueList = &ViewData->TS; ViewNumList = &ViewData->NbTS;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_TET);
      }
      else if(!strncmp($1, "SH", 2)){
	ViewValueList = &ViewData->SH; ViewNumList = &ViewData->NbSH;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp($1, "VH", 2)){
	ViewValueList = &ViewData->VH; ViewNumList = &ViewData->NbVH;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp($1, "TH", 2)){
	ViewValueList = &ViewData->TH; ViewNumList = &ViewData->NbTH;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_HEX);
      }
      else if(!strncmp($1, "SI", 2)){
	ViewValueList = &ViewData->SI; ViewNumList = &ViewData->NbSI;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp($1, "VI", 2)){
	ViewValueList = &ViewData->VI; ViewNumList = &ViewData->NbVI;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp($1, "TI", 2)){
	ViewValueList = &ViewData->TI; ViewNumList = &ViewData->NbTI;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_PRI);
      }
      else if(!strncmp($1, "SY", 2)){
	ViewValueList = &ViewData->SY; ViewNumList = &ViewData->NbSY;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp($1, "VY", 2)){
	ViewValueList = &ViewData->VY; ViewNumList = &ViewData->NbVY;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else if(!strncmp($1, "TY", 2)){
	ViewValueList = &ViewData->TY; ViewNumList = &ViewData->NbTY;
        if(strlen($1) > 2) ViewData->setOrder2(TYPE_PYR);
      }
      else{
	yymsg(0, "Unknown element type '%s'", $1);
	ViewValueList = 0; ViewNumList = 0;
      }
#endif
      ViewCoord.clear();
      Free($1);
    }
    '(' ElementCoords ')'
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(std::size_t j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
    '{' ElementValues '}' tEND
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
;

Text2DValues :
    StringExprVar
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen($1) + 1; i++) ViewData->T2C.push_back($1[i]);
#endif
      Free($1);
    }
  | Text2DValues ',' StringExprVar
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen($3) + 1; i++) ViewData->T2C.push_back($3[i]);
#endif
      Free($3);
    }
;

Text2D :
    tText2D '(' FExpr ',' FExpr ',' FExpr ')'
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back($3);
      ViewData->T2D.push_back($5);
      ViewData->T2D.push_back($7);
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    }
    '{' Text2DValues '}' tEND
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    }
;

Text3DValues :
    StringExprVar
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen($1) + 1; i++) ViewData->T3C.push_back($1[i]);
#endif
      Free($1);
    }
  | Text3DValues ',' StringExprVar
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen($3) + 1; i++) ViewData->T3C.push_back($3[i]);
#endif
      Free($3);
    }
;

Text3D :
    tText3D '(' FExpr ',' FExpr ',' FExpr ',' FExpr ')'
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back($3); ViewData->T3D.push_back($5);
      ViewData->T3D.push_back($7); ViewData->T3D.push_back($9);
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    }
    '{' Text3DValues '}' tEND
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    }
;

InterpolationMatrix :
    tInterpolationScheme '{' RecursiveListOfListOfDouble '}'
                         '{' RecursiveListOfListOfDouble '}'  tEND
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
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix($3),
                                         ListOfListOfDouble2Matrix($6));
#endif
    }
 |  tInterpolationScheme '{' RecursiveListOfListOfDouble '}'
                         '{' RecursiveListOfListOfDouble '}'
                         '{' RecursiveListOfListOfDouble '}'
                         '{' RecursiveListOfListOfDouble '}'  tEND
    {
#if defined(HAVE_POST)
      int type =
	(ViewData->NbSL || ViewData->NbVL) ? TYPE_LIN :
	(ViewData->NbST || ViewData->NbVT) ? TYPE_TRI :
	(ViewData->NbSQ || ViewData->NbVQ) ? TYPE_QUA :
	(ViewData->NbSS || ViewData->NbVS) ? TYPE_TET :
      	(ViewData->NbSH || ViewData->NbVH) ? TYPE_HEX :
	0;
      ViewData->setInterpolationMatrices(type, ListOfListOfDouble2Matrix($3),
                                         ListOfListOfDouble2Matrix($6),
                                         ListOfListOfDouble2Matrix($9),
                                         ListOfListOfDouble2Matrix($12));
#endif
    }
;

Time :
    tTime
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    }
   '{' ElementValues '}' tEND
    {
    }
;

//  A F F E C T A T I O N

NumericAffectation :
    tAFFECT        { $$ = 0; }
  | tAFFECTPLUS    { $$ = 1; }
  | tAFFECTMINUS   { $$ = 2; }
  | tAFFECTTIMES   { $$ = 3; }
  | tAFFECTDIVIDE  { $$ = 4; }
;

NumericIncrement :
    tPLUSPLUS      { $$ = 1; }
  | tMINUSMINUS    { $$ = -1; }
;

// these are for compatibility with the syntax in GetDP (square brackets instead
// of parentheses)

LP : '(' { $$ = (char*)"("; } | '[' { $$ = (char*)"["; } ;

RP : ')' { $$ = (char*)")"; } | ']' { $$ = (char*)"]"; } ;

// this is to allow reserved keywords in option names, fields, structs, ...

tSTRING_Reserved:
   tSTRING   { $$ = $1; }
 | tMin      { $$ = (char *)Malloc(4 * sizeof(char)); strcpy($$, "Min"); }
 | tMax      { $$ = (char *)Malloc(4 * sizeof(char)); strcpy($$, "Max"); }
 | tBox      { $$ = (char *)Malloc(4 * sizeof(char)); strcpy($$, "Box"); }
 | tCylinder { $$ = (char *)Malloc(9 * sizeof(char)); strcpy($$, "Cylinder"); }

Affectation :

  // Variables

    tDefineConstant '[' DefineConstants ']' tEND
  | tUndefineConstant '[' UndefineConstants ']' tEND
  | DefineStruct tEND
  | tSetNumber LP StringExpr ',' FExpr RP tEND
    {
      Msg::SetOnelabNumber($3, $5);
      Free($3);
    }
  | tSetString LP String__Index ',' StringExpr RP tEND
    {
      Msg::SetOnelabString($3, $5);
      Free($3);
      Free($5);
    }
  | String__Index NumericAffectation ListOfDouble tEND
    {
      if(!gmsh_yysymbols.count($1) && $2 && List_Nbr($3) == 1){
        yymsg(0, "Unknown variable '%s'", $1);
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
        if(!$2) s.list = (List_Nbr($3) != 1); // list if 0 or > 1 elements
        if(!s.list){ // single expression
          if(List_Nbr($3) != 1){
            yymsg(0, "Cannot assign list to variable '%s'", $1);
          }
          else{
            double d;
            List_Read($3, 0, &d);
            if(s.value.empty()){
              if($2) yymsg(1, "Uninitialized variable '%s'", $1);
              s.value.resize(1, 0.);
            }
            switch($2){
            case 0 : s.value[0] = d; break;
            case 1 : s.value[0] += d; break;
            case 2 : s.value[0] -= d; break;
            case 3 : s.value[0] *= d; break;
            case 4 :
              if(d) s.value[0] /= d;
              else yymsg(0, "Division by zero in '%s /= %g'", $1, d);
              break;
            }
          }
        }
        else{
          // list of expressions; this is not recommended (should use [] or ()
          // notation instead)
          switch($2){
          case 0: // affect
            s.value.clear(); // fall-through
          case 1: // append
            for(int i = 0; i < List_Nbr($3); i++){
              double d;
              List_Read($3, i, &d);
              s.value.push_back(d);
            }
            break;
          case 2: // remove
            for(int i = 0; i < List_Nbr($3); i++){
              double d;
              List_Read($3, i, &d);
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
      Free($1);
      List_Delete($3);
    }
  | String__Index NumericIncrement tEND
    {
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1);
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
        if(!s.list && s.value.empty())
          yymsg(0, "Uninitialized variable '%s'", $1);
        else if(!s.list)
          s.value[0] += $2;
        else
          yymsg(0, "Variable '%s' is a list", $1);
      }
      Free($1);
    }
  | String__Index LP RP NumericAffectation ListOfDouble tEND
    {
      gmsh_yysymbol &s(gmsh_yysymbols[$1]);
      s.list = true;
      double d;
      switch($4){
      case 0: // affect
        s.value.clear(); // fall-through
      case 1: // append
        for(int i = 0; i < List_Nbr($5); i++){
          List_Read($5, i, &d);
          s.value.push_back(d);
        }
        break;
      case 2: // remove
        for(int i = 0; i < List_Nbr($5); i++){
          List_Read($5, i, &d);
          auto it = std::find(s.value.begin(), s.value.end(), d);
          if(it != s.value.end()) s.value.erase(it);
        }
        break;
      default:
        yymsg(0, "Operators *= and /= not available for lists");
        break;
      }
      Free($1);
      List_Delete($5);
    }
  | String__Index LP '{' RecursiveListOfDouble '}' RP NumericAffectation ListOfDouble tEND
    {
      assignVariables($1, $4, $7, $8);
      Free($1);
      List_Delete($4);
      List_Delete($8);
    }

  //+++ TO FIX
  // lists of numbers with bracket notation
  | String__Index '[' FExpr ']' NumericAffectation FExpr tEND
    {
      assignVariable($1, (int)$3, $5, $6);
      Free($1);
    }
  | String__Index '[' FExpr ']' NumericIncrement tEND
    {
      incrementVariable($1, (int)$3, $5);
      Free($1);
    }

  // lists of numbers with parentheses notation

  | String__Index '(' FExpr ')' NumericAffectation FExpr tEND
    {
      assignVariable($1, (int)$3, $5, $6);
      Free($1);
    }
  | String__Index '(' FExpr ')' NumericIncrement tEND
    {
      incrementVariable($1, $3, $5);
      Free($1);
    }

  // strings

  | String__Index tAFFECT StringExpr tEND
    {
      gmsh_yystringsymbols[$1] = std::vector<std::string>(1, $3);
      Free($1);
      Free($3);
    }

  // lists of strings

  | String__Index LP RP tAFFECT tStr LP RP tEND
    {
      gmsh_yystringsymbols[$1] = std::vector<std::string>();
      Free($1);
    }
  | String__Index LP RP tAFFECT tStr LP BracedOrNotRecursiveListOfStringExprVar RP tEND
    {
      std::vector<std::string> s;
      for(int i = 0; i < List_Nbr($7); i++){
        char **c = (char**)List_Pointer($7, i);
        s.push_back(*c);
        Free(*c);
      }
      gmsh_yystringsymbols[$1] = s;
      Free($1);
      List_Delete($7);
    }
  | String__Index LP RP tAFFECTPLUS tStr LP BracedOrNotRecursiveListOfStringExprVar RP tEND
    {
      if(gmsh_yystringsymbols.count($1)){
        for(int i = 0; i < List_Nbr($7); i++){
          char **c = (char**)List_Pointer($7, i);
          gmsh_yystringsymbols[$1].push_back(*c);
          Free(*c);
        }
      }
      else
        yymsg(0, "Uninitialized variable '%s'", $1);
      Free($1);
      List_Delete($7);
    }

  // Option Strings

  | String__Index '.' tSTRING_Reserved tAFFECT StringExpr tEND
    {
      std::string tmp($5);
      StringOption(GMSH_SET|GMSH_GUI, $1, 0, $3, tmp);
      Free($1); Free($3); Free($5);
    }
  | String__Index '[' FExpr ']' '.' tSTRING_Reserved tAFFECT StringExpr tEND
    {
      std::string tmp($8);
      StringOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $6, tmp);
      Free($1); Free($6); Free($8);
    }

  // Option Numbers

  | String__Index '.' tSTRING_Reserved NumericAffectation FExpr tEND
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, 0, $3, d)){
	switch($4){
	case 0 : d = $5; break;
	case 1 : d += $5; break;
	case 2 : d -= $5; break;
	case 3 : d *= $5; break;
	case 4 :
	  if($5) d /= $5;
	  else yymsg(0, "Division by zero in '%s.%s /= %g'", $1, $3, $5);
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, $1, 0, $3, d);
      }
      Free($1); Free($3);
    }
  | String__Index '[' FExpr ']' '.' tSTRING_Reserved NumericAffectation FExpr tEND
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, (int)$3, $6, d)){
	switch($7){
	case 0 : d = $8; break;
	case 1 : d += $8; break;
	case 2 : d -= $8; break;
	case 3 : d *= $8; break;
	case 4 :
	  if($8) d /= $8;
	  else yymsg(0, "Division by zero in '%s[%d].%s /= %g'", $1, (int)$3, $6, $8);
	  break;
	}
	NumberOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $6, d);
      }
      Free($1); Free($6);
    }
  | String__Index '.' tSTRING_Reserved NumericIncrement tEND
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, 0, $3, d)){
	d += $4;
	NumberOption(GMSH_SET|GMSH_GUI, $1, 0, $3, d);
      }
      Free($1); Free($3);
    }
  | String__Index '[' FExpr ']' '.' tSTRING_Reserved NumericIncrement tEND
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, (int)$3, $6, d)){
	d += $7;
	NumberOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $6, d);
      }
      Free($1); Free($6);
    }

  // Option Colors

  | String__Index '.' tColor '.' tSTRING_Reserved tAFFECT ColorExpr tEND
    {
      ColorOption(GMSH_SET|GMSH_GUI, $1, 0, $5, $7);
      Free($1); Free($5);
    }
  | String__Index '[' FExpr ']' '.' tColor '.' tSTRING_Reserved tAFFECT ColorExpr tEND
    {
      ColorOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $8, $10);
      Free($1); Free($8);
    }

  // ColorTable

  | String__Index '.' tColorTable tAFFECT ListOfColor tEND
    {
      GmshColorTable *ct = GetColorTable(0);
      if(!ct)
	yymsg(0, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr($5);
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(int i = 0; i < ct->size; i++) List_Read($5, i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free($1);
      List_Delete($5);
    }
  | String__Index '[' FExpr ']' '.' tColorTable tAFFECT ListOfColor tEND
    {
      GmshColorTable *ct = GetColorTable((int)$3);
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)$3);
      else{
	ct->size = List_Nbr($8);
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(0, "Too many (%d>%d) colors in View[%d].ColorTable",
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)$3);
	else
	  for(int i = 0; i < ct->size; i++) List_Read($8, i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      Free($1);
      List_Delete($8);
    }

  // Fields

  | String__Index tField tAFFECT ListOfDouble tEND
    {
#if defined(HAVE_MESH)
      std::vector<int> tags; ListOfDouble2Vector($4, tags);
      if(!strcmp($1,"Background")) {
	if(tags.size() > 1)
	  yymsg(0, "Only 1 field can be set as a background field.");
	else if(tags.size() == 0)
	  yymsg(1, "No field given (Background Field).");
	else
	  GModel::current()->getFields()->setBackgroundFieldId((int)tags[0]);
      }
      else if(!strcmp($1,"BoundaryLayer"))
	GModel::current()->getFields()->addBoundaryLayerFieldId(tags);
      else
	yymsg(0, "Unknown command '%s Field'", $1);
#endif
      Free($1);
      List_Delete($4);
    }
  | tField '[' FExpr ']' tAFFECT tSTRING_Reserved tEND
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)$3, $6))
	yymsg(0, "Cannot create field %i of type '%s'", (int)$3, $6);
#endif
      Free($6);
    }
  | tField '[' FExpr ']' '.' tSTRING_Reserved  tAFFECT FExpr tEND
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)$3);
      if(field){
	FieldOption *option = field->options[$6];
	if(option){
	  try { option->numericalValue($8); }
	  catch(...){
	    yymsg(0, "Cannot assign a numerical value to option '%s' "
		  "in field %i of type '%s'", $6, (int)$3, field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		$6, (int)$3, field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)$3);
#endif
      Free($6);
    }
  | tField '[' FExpr ']' '.' tSTRING_Reserved  tAFFECT StringExpr tEND
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)$3);
      if(field){
	FieldOption *option = field->options[$6];
	if(option){
	  try { option->string($8); }
	  catch (...){
	    yymsg(0, "Cannot assign a string value to  option '%s' "
		  "in field %i of type '%s'", $6, (int)$3, field->getName());
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		$6, (int)$3, field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)$3);
#endif
      Free($6);
      Free($8);
    }
  | tField '[' FExpr ']' '.' tSTRING_Reserved  tAFFECT '{' RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)$3);
      if(field){
	FieldOption *option = field->options[$6];
	if(option){
	  if(option->getType() == FIELD_OPTION_LIST) {
	    std::list<int> vl = option->list();
	    vl.clear();
	    for(int i = 0; i < List_Nbr($9); i++){
	      double id;
	      List_Read($9, i, &id);
	      vl.push_back((int)id);
	    }
	    option->list(vl);
	  }
	  else {
	    std::list<double> vl = option->listdouble();
	    vl.clear();
	    for(int i = 0; i < List_Nbr($9); i++){
	      double id;
	      List_Read($9, i, &id);
	      vl.push_back(id);
	    }
	    option->listdouble(vl);
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		$6, (int)$3, field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)$3);
#endif
      Free($6);
      List_Delete($9);
    }
  | tField '[' FExpr ']' '.' tSTRING_Reserved tEND
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)$3);
      if(field){
        FieldCallback *callback = field->callbacks[$6];
        if(callback) {
          callback->run();
        }
        else
          yymsg(0, "Unknown callback '%s' in field %i of type '%s'",
              $6, (int)$3, field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)$3);
#endif
      Free($6);
    }

  // Plugins

  | tPlugin '(' tSTRING ')' '.' tSTRING_Reserved tAFFECT FExpr tEND
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption($3, $6, $8);
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", $6, $3);
      }
#endif
      Free($3); Free($6);
    }
  | tPlugin '(' tSTRING ')' '.' tSTRING_Reserved tAFFECT StringExpr tEND
    {
#if defined(HAVE_PLUGINS)
      try {
	PluginManager::instance()->setPluginOption($3, $6, $8);
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", $6, $3);
      }
#endif
      Free($3); Free($6); Free($8);
    }
;

Comma : /* none */ | ',' ;

DefineConstants :
    /* none */
  | DefineConstants Comma String__Index
    {
      std::string key($3);
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free($3);
    }
  | DefineConstants Comma String__Index tAFFECT FExpr
    {
      std::string key($3);
      std::vector<double> val(1, $5);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free($3);
    }
  | DefineConstants Comma String__Index tAFFECT '{' ListOfDouble
    { init_options(); }
    FloatParameterOptionsOrNone '}'
    {
      if(List_Nbr($6) != 1)
	yymsg(1, "List notation should be used to define list '%s[]'", $3);
      std::string key($3);
      std::vector<double> val;
      for(int i = 0; i < List_Nbr($6); i++){
        double d;
        List_Read($6, i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free($3);
      List_Delete($6);
    }
  | DefineConstants Comma String__Index LP RP tAFFECT '{' ListOfDouble
    { init_options(); }
    FloatParameterOptionsOrNone '}'
    {
      std::string key($3);
      std::vector<double> val;
      for(int i = 0; i < List_Nbr($8); i++){
        double d;
        List_Read($8, i, &d);
        val.push_back(d);
      }
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yysymbols[key].value = val;
      }
      Free($3);
      List_Delete($8);
    }
  | DefineConstants Comma String__Index tAFFECT StringExpr
    {
      std::string key($3), val($5);
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free($3);
      Free($5);
    }
  | DefineConstants Comma String__Index tAFFECT '{' StringExpr
    { init_options(); }
      CharParameterOptionsOrNone '}'
    {
      std::string key($3), val($6);
      if(!gmsh_yystringsymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free($3);
      Free($6);
    }
 ;

UndefineConstants :
    /* none */
  | UndefineConstants Comma StringExprVar
    {
      std::string name($3);
      Msg::UndefineOnelabParameter(name);
      Free($3);
    }

Enumeration :
    FExpr tAFFECT StringExpr
    {
      $$ = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {$1, $3};
      List_Add($$, &v);
    }
  | Enumeration ',' FExpr tAFFECT StringExpr
    {
      doubleXstring v = {$3, $5};
      List_Add($$, &v);
    }
  | FExpr_Multi tAFFECT String__Index '(' ')'
    {
      $$ = List_Create(20,20,sizeof(doubleXstring));
      int n = List_Nbr($1);
      if(!gmsh_yystringsymbols.count($3)){
	yymsg(0, "Unknown string variable '%s'", $3);
      }
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[$3]);
        int m = s.size();
        if(n == m){
          for(int i = 0; i < n; i++){
            double d;
            List_Read($1, i, &d);
            doubleXstring v = {d, strsave((char*)s[i].c_str())};
            List_Add($$, &v);
          }
        }
        else{
          yymsg(0, "Size mismatch in enumeration: %d != %d", n, m);
        }
      }
      List_Delete($1);
      Free($3);
    }
  ;

FloatParameterOptionsOrNone :
    // none
  | ',' FloatParameterOptions
 ;

FloatParameterOptionsOrNone_NoComma :
    // none
  | FloatParameterOptions
 ;

FloatParameterOptions :
    FloatParameterOption
  | FloatParameterOptions ',' FloatParameterOption
 ;

FloatParameterOption :
    tSTRING ListOfDouble
    {
      std::string key($1);
      for(int i = 0; i < List_Nbr($2); i++){
        double v;
        List_Read($2, i, &v);
        floatOptions[key].push_back(v);
        if(flag_Enum && !i) { member_ValMax = (int)v; }
      }
      Free($1);
      List_Delete($2);
    }
  | tMin FExpr
    {
      floatOptions["Min"].push_back($2);
    }
  | tMax FExpr
    {
      floatOptions["Max"].push_back($2);
    }
  | tSTRING
    {
      std::string key($1);
      double v;
      if(!flag_Enum) {
        v = 1.;
        if(key == "Enum") flag_Enum = 1;
      }
      else
        v = (double)++member_ValMax;
      floatOptions[key].push_back(v);
      Free($1);
    }
  | tSTRING '{' Enumeration '}'
    {
      std::string key($1);
      for(int i = 0; i < List_Nbr($3); i++){
        doubleXstring v;
        List_Read($3, i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free($1);
      for(int i = 0; i < List_Nbr($3); i++)
        Free(((doubleXstring*)List_Pointer($3, i))->s);
      List_Delete($3);
    }
  | tSTRING StringExpr
    {
      std::string key($1);
      std::string val($2);
      charOptions[key].push_back(val);
      Free($1);
      Free($2);
    }
  | tSTRING Str_BracedRecursiveListOfStringExprVar
    {
      std::string key($1);
      for(int i = 0; i < List_Nbr($2); i++){
        char *v;
        List_Read($2, i, &v);
        charOptions[key].push_back(v);
      }
      Free($1);
      List_Delete($2);
    }
 ;

CharParameterOptionsOrNone :
    // none
  | ',' CharParameterOptions
 ;

CharParameterOptions :
    CharParameterOption
  | CharParameterOptions ',' CharParameterOption
 ;

CharParameterOption :

    tSTRING FExpr
    {
      std::string key($1);
      double val = $2;
      floatOptions[key].push_back(val);
      Free($1);
    }

  | tSTRING StringExpr
    {
      std::string key($1);
      std::string val($2);
      charOptions[key].push_back(val);
      Free($1);
      Free($2);
    }

  | tMacro StringExpr // Macro is already a reserved keyword
    {
      std::string key("Macro");
      std::string val($2);
      charOptions[key].push_back(val);
      Free($2);
    }

  | tSTRING BracedRecursiveListOfStringExprVar
    {
      std::string key($1);
      for(int i = 0; i < List_Nbr($2); i++){
        char *s;
        List_Read($2, i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free($1);
      List_Delete($2);
    }

  | tSTRING Str_BracedRecursiveListOfStringExprVar
    {
      std::string key($1);
      for(int i = 0; i < List_Nbr($2); i++){
        char *s;
        List_Read($2, i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free($1);
      List_Delete($2);
    }
 ;

//  S H A P E

PhysicalId_per_dim_entity :
    FExpr
    {
      $$ = (int)$1;
    }
  | StringExpr
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      $$ = GModel::current()->setPhysicalName(std::string($1), dim_entity, t + 1);
      Free($1);
    }
  | StringExpr ',' FExpr
    {
      $$ = GModel::current()->setPhysicalName(std::string($1), dim_entity, $3);
      Free($1);
    }
;

SurfaceConstraints :
    // nothing
    {
      $$ = 0;
    }
  | tIn tSphere '{' FExpr '}'
    {
      $$ = List_Create(1, 1, sizeof(double));
      double p = $4;
      List_Add($$, &p);
    }
  | tUsing tPoint '{' RecursiveListOfDouble '}'
    {
      $$ = $4;
    }
  | tUsing tGeoEntity '{' RecursiveListOfDouble '}'
    {
      $$ = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add($$, &flag);
      for(int i = 0; i < List_Nbr($4); i++)
        List_Add($$, List_Pointer($4, i));
      List_Delete($4);
    }
;

CircleOptions :
    {
      for(int i = 0; i < 4; i++) $$[i] = 0.;
    }
  | tPlane VExpr
    {
      for(int i = 0; i < 4; i++) $$[i] = $2[i];
    }
;

LoopOptions :
    {
      $$ = 0;
    }
  | tUsing tSewing
    {
      $$ = 1;
    }

Shape :
    tPoint '(' FExpr ')' tAFFECT VExpr tEND
    {
      int num = (int)$3;
      double x = CTX::instance()->geom.scalingFactor * $6[0];
      double y = CTX::instance()->geom.scalingFactor * $6[1];
      double z = CTX::instance()->geom.scalingFactor * $6[2];
      double lc = CTX::instance()->geom.scalingFactor * $6[3];
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
      $$.Type = MSH_POINT;
      $$.Num = num;
    }
  | tCurve '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addLine(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addLine(num, tags);
      }
      if(!r) yymsg(0, "Could not add line");
      List_Delete($6);
      $$.Type = MSH_SEGM_LINE;
      $$.Num = num;
    }
  | tSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSpline(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add spline");
      List_Delete($6);
      $$.Type = MSH_SEGM_SPLN;
      $$.Num = num;
    }
  | tCompound tSpline '(' FExpr ')' tAFFECT ListOfDouble tUsing FExpr tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Compound spline only available with built-in geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->addCompoundSpline(num, tags,
                                                                    (int)$9);
      }
      if(!r) yymsg(0, "Could not add compound spline");
      List_Delete($7);
      $$.Type = MSH_SEGM_SPLN;
      $$.Num = num;
    }
  | tCompound tBSpline '(' FExpr ')' tAFFECT ListOfDouble tUsing FExpr tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Compound spline only available with built-in geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->addCompoundBSpline(num, tags,
                                                                     (int)$9);
      }
      if(!r) yymsg(0, "Could not add compound spline");
      List_Delete($7);
      $$.Type = MSH_SEGM_BSPLN;
      $$.Num = num;
    }
  | tCircle '(' FExpr ')' tAFFECT ListOfDouble CircleOptions tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
            (num, tags[0], tags[1], tags[2], $7[0], $7[1], $7[2]);
        }
        else{
          yymsg(0, "Circle requires 3 points");
        }
      }
      if(!r) yymsg(0, "Could not add circle");
      List_Delete($6);
      $$.Type = MSH_SEGM_CIRC;
      $$.Num = num;
    }
  | tEllipse '(' FExpr ')' tAFFECT ListOfDouble CircleOptions tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
            (num, tags[0], tags[1], tags[0], tags[2], $7[0], $7[1], $7[2]);
        }
        else if(tags.size() == 4){
          r = GModel::current()->getGEOInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2], tags[3], $7[0], $7[1], $7[2]);
        }
        else{
          yymsg(0, "Ellipse requires 4 points");
        }
      }
      if(!r) yymsg(0, "Could not add ellipse");
      List_Delete($6);
      $$.Type = MSH_SEGM_ELLI;
      $$.Num = num;
    }
  | tBSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addBSpline(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBSpline(num, tags);
      }
      if(!r) yymsg(0, "Could not add BSpline");
      List_Delete($6);
      $$.Type = MSH_SEGM_BSPLN;
      $$.Num = num;
    }
  | tBezier '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addBezier(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addBezier(num, tags);
      }
      if(!r) yymsg(0, "Could not add Bezier");
      List_Delete($6);
      $$.Type = MSH_SEGM_BEZIER;
      $$.Num = num;
    }
  | tNurbs  '(' FExpr ')' tAFFECT ListOfDouble tNurbsKnots ListOfDouble
      tNurbsOrder FExpr tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      std::vector<double> seqknots; ListOfDouble2Vector($8, seqknots);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        int degree = (int)$10;
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
      List_Delete($6);
      List_Delete($8);
      $$.Type = MSH_SEGM_NURBS;
      $$.Num = num;
    }
  | tWire '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addWire(num, tags, false);
      }
      else{
        yymsg(0, "Wire only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add wire");
      List_Delete($6);
      $$.Type = MSH_SEGM_LOOP;
      $$.Num = num;
    }
  | tCurve tSTRING '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addCurveLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addCurveLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add line loop");
      List_Delete($7);
      Free($2);
      $$.Type = MSH_SEGM_LOOP;
      $$.Num = num;
    }
  | tPlane tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPlaneSurface(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addPlaneSurface(num, tags);
      }
      if(!r) yymsg(0, "Could not add plane surface");
      List_Delete($7);
      $$.Type = MSH_SURF_PLAN;
      $$.Num = num;
    }
  | tSurface '(' FExpr ')' tAFFECT ListOfDouble SurfaceConstraints tEND
    {
      int num = (int)$3;
      std::vector<int> wires; ListOfDouble2Vector($6, wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE surface filling requires a single line loop");
        }
        else{
          std::vector<int> constraints; ListOfDouble2Vector($7, constraints);
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
        if(List_Nbr($7) == 1){
          double d; List_Read($7, 0, &d);
          sphereCenter = (int)d;
        }
        r = GModel::current()->getGEOInternals()->addSurfaceFilling
          (num, wires, sphereCenter);
      }
      if(!r) yymsg(0, "Could not add surface");
      List_Delete($6);
      List_Delete($7);
      $$.Type = MSH_SURF_REGL;
      $$.Num = num;
    }
  | tRuled tSurface '(' FExpr ')' tAFFECT ListOfDouble SurfaceConstraints tEND
    {
      yymsg(2, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)$4;
      std::vector<int> wires; ListOfDouble2Vector($7, wires);
      int sphereCenter = -1;
      if(List_Nbr($8) == 1){
        double d; List_Read($8, 0, &d);
        sphereCenter = (int)d;
      }
      bool r = GModel::current()->getGEOInternals()->addSurfaceFilling
        (num, wires, sphereCenter);
      if(!r) yymsg(0, "Could not add surface");
      List_Delete($7);
      List_Delete($8);
      $$.Type =  MSH_SURF_REGL;
      $$.Num = num;
    }
  | tBSpline tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> wires; ListOfDouble2Vector($7, wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1) {
          yymsg(0, "OpenCASCADE BSpline filling requires a single line loop");
        }
        else {
          r = GModel::current()->getOCCInternals()->addBSplineFilling(num, wires[0]);
        }
      }
      else{
        yymsg(0, "BSpline surface only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add BSpline surface");
      List_Delete($7);
      $$.Type = MSH_SURF_REGL;
      $$.Num = num;
    }
  | tBezier tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> wires; ListOfDouble2Vector($7, wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1) {
          yymsg(0, "OpenCASCADE BSpline filling requires a single line loop");
        }
        else {
          r = GModel::current()->getOCCInternals()->addBezierFilling(num, wires[0]);
        }
      }
      else{
        yymsg(0, "Bezier surface only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add Bezier surface");
      List_Delete($7);
      $$.Type = MSH_SURF_REGL;
      $$.Num = num;
    }
  | tEuclidian tCoordinates tEND
    {
      myGmshSurface = 0;
      $$.Type = 0;
      $$.Num = 0;
    }
  | tCoordinates tSurface FExpr tEND
    {
      myGmshSurface = gmshSurface::getSurface((int)$3);
      $$.Type = 0;
      $$.Num = 0;
    }
  | tParametric tSurface '(' FExpr ')' tAFFECT tBIGSTR tBIGSTR tBIGSTR tEND
    {
      int num = (int)$4;
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, $7, $8, $9);
      $$.Type = 0;
      $$.Num = num;
    }
  | tSphere '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      std::vector<double> param; ListOfDouble2Vector($6, param);
      $$.Type = 0;
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
        $$.Type = MSH_VOLUME;
      }
      else if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometrySphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "Sphere requires 2 points or from 4 to 7 parameters");
      }
      if(!r) yymsg(0, "Could not add sphere");
      List_Delete($6);
      $$.Num = num;
    }
  | tPolarSphere '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometryPolarSphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "PolarSphere requires 2 points");
      }
      List_Delete($6);
      $$.Type = 0;
      $$.Num = num;
    }
  | tBox '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tTorus '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tRectangle '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
      List_Delete($6);
      $$.Type = MSH_SURF_PLAN;
      $$.Num = num;
    }
  | tDisk '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
      List_Delete($6);
      $$.Type = MSH_SURF_PLAN;
      $$.Num = num;
    }
  | tCylinder '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tCone '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tWedge '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tThickSolid '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
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
      List_Delete($6);
    }
  | tSurface tSTRING '(' FExpr ')' tAFFECT ListOfDouble LoopOptions tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags, $8);
      }
      else{
        r = GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add surface loop");
      List_Delete($7);
      Free($2);
      $$.Type = MSH_SURF_LOOP;
      $$.Num = num;
    }
  | tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      if(!r) yymsg(0, "Could not add volume");
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tThruSections '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> wires; ListOfDouble2Vector($6, wires);
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
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tRuled tThruSections '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> wires; ListOfDouble2Vector($7, wires);
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
      List_Delete($7);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tCompound GeoEntity123 '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      if($2 == 1)
        yymsg(0, "`Compound Line (...) = {...};' is deprecated: use `Compound "
              "Spline|BSpline (...) = {...} Using ...;' instead, or the compound "
              "meshing constraint `Compound Curve {...};'");
      else
        yymsg(0, "`Compound Surface (...) = {...};' is deprecated: use the "
              "compound meshing constraint `Compound Surface {...};' instead");
      $$.Type = 0;
      $$.Num = 0;
    }
  | tCompound GeoEntity123 '(' FExpr ')' tAFFECT ListOfDouble tSTRING
      '{' RecursiveListOfListOfDouble '}' tEND
    {
      if($2 == 1)
        yymsg(0, "`Compound Line (...) = {...};' is deprecated: use `Compound "
              "Spline|BSpline (...) = {...} Using ...;' instead, or the compound "
              "meshing constraint `Compound Curve {...};'");
      else
        yymsg(0, "`Compound Surface (...) = {...};' is deprecated: use the "
              "compound meshing constraint `Compound Surface {...};' instead");
      $$.Type = 0;
      $$.Num = 0;
    }
  | tPhysical GeoEntity
    {
      dim_entity = $2;
    }
    '(' PhysicalId_per_dim_entity ')' NumericAffectation ListOfDouble tEND
    {
      int num = (int)$5;
      int op = $7;
      std::vector<int> tags; ListOfDouble2Vector($8, tags);
      bool r = GModel::current()->getGEOInternals()->modifyPhysicalGroup
        ($2, num, op, tags);
      if(!r)
        switch ($2) {
        case 0: yymsg(0, "Could not modify physical point"); break;
        case 1: yymsg(0, "Could not modify physical line"); break;
        case 2: yymsg(0, "Could not modify physical surface"); break;
        case 3: yymsg(0, "Could not modify physical volume"); break;
        }
      List_Delete($8);
      switch ($2) {
      case 0: $$.Type = MSH_PHYSICAL_POINT  ; break;
      case 1: $$.Type = MSH_PHYSICAL_LINE   ; break;
      case 2: $$.Type = MSH_PHYSICAL_SURFACE; break;
      case 3: $$.Type = MSH_PHYSICAL_VOLUME ; break;
      }
      $$.Num = num;
    }
;

GeoEntity :
    tPoint
    { $$ = 0; }
  | tCurve
    { $$ = 1; }
  | tSurface
    { $$ = 2; }
  | tVolume
    { $$ = 3; }
  | tGeoEntity '{' FExpr '}'
    {
      $$ = (int)$3;
      if($$ < 0 || $$ > 3) yymsg(0, "GeoEntity dim out of range [0,3]");
    }
;

GeoEntity123 :
    tCurve
    { $$ = 1; }
  | tSurface
    { $$ = 2; }
  | tVolume
    { $$ = 3; }
  | tGeoEntity '{' FExpr '}'
    {
      $$ = (int)$3;
      if($$<1 || $$>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    }
;

GeoEntity12 :
    tCurve
    { $$ = 1; }
  | tSurface
    { $$ = 2; }
  | tGeoEntity '{' FExpr '}'
    {
      $$ = (int)$3;
      if($$<1 || $$>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    }
;

GeoEntity02 :
    tPoint
    { $$ = 0; }
  | tCurve
    { $$ = 1; }
  | tSurface
    { $$ = 2; }
  | tGeoEntity '{' FExpr '}'
    {
      $$ = (int)$3;
      if($$ < 0 || $$ > 2) yymsg(0, "GeoEntity dim out of range [0,2]");
    }
;

//  T R A N S F O R M

Transform :
    tTranslate VExpr '{' MultipleShape '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($4, dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->translate
          (dimTags, $2[0], $2[1], $2[2]);
      }
      else{
        r = GModel::current()->getGEOInternals()->translate
          (dimTags, $2[0], $2[1], $2[2]);
      }
      if(!r) yymsg(0, "Could not translate shapes");
      $$ = $4;
    }
  | tRotate '{' VExpr ',' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($10, dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->rotate
          (dimTags, $5[0], $5[1], $5[2], $3[0], $3[1], $3[2], $7);
      }
      else{
        r = GModel::current()->getGEOInternals()->rotate
          (dimTags, $5[0], $5[1], $5[2], $3[0], $3[1], $3[2], $7);
      }
      if(!r) yymsg(0, "Could not rotate shapes");
      $$ = $10;
    }
  | tSymmetry  VExpr '{' MultipleShape '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($4, dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->symmetry
          (dimTags, $2[0], $2[1], $2[2], $2[3]);
      }
      else{
        r = GModel::current()->getGEOInternals()->symmetry
          (dimTags, $2[0], $2[1], $2[2], $2[3]);
      }
      if(!r) yymsg(0, "Could not apply symmetry transform");
      $$ = $4;
    }
  | tDilate '{' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($8, dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->dilate
          (dimTags, $3[0], $3[1], $3[2], $5, $5, $5);
      }
      else{
        r = GModel::current()->getGEOInternals()->dilate
          (dimTags, $3[0], $3[1], $3[2], $5, $5, $5);
      }
      if(!r) yymsg(0, "Could not dilate shapes");
      $$ = $8;
    }
  | tDilate '{' VExpr ',' VExpr '}' '{' MultipleShape '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($8, dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->dilate
          (dimTags, $3[0], $3[1], $3[2], $5[0], $5[1], $5[2]);
      }
      else{
        r = GModel::current()->getGEOInternals()->dilate
          (dimTags, $3[0], $3[1], $3[2], $5[0], $5[1], $5[2]);
      }
      if(!r) yymsg(0, "Could not dilate shapes");
      $$ = $8;
    }
  | tAffine '{' RecursiveListOfDouble '}' '{' MultipleShape '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($6, dimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<double> mat;
        ListOfDouble2Vector($3, mat);
        r = GModel::current()->getOCCInternals()->affine(dimTags, mat);
      }
      else{
        yymsg(0, "Affine transform only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not transform shapes");
      List_Delete($3);
      $$ = $6;
    }
  | tSTRING '{' MultipleShape '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($3, inDimTags);
      $$ = $3;
      List_Reset($$);
      std::string action($1);
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
        yymsg(0, "Unknown action on multiple shapes '%s'", $1);
      }
      if(!r) yymsg(0, "Could not apply operation on shapes");
      VectorOfPairs2ListOfShapes(outDimTags, $$);
      Free($1);
    }
  | tIntersect tCurve '{' RecursiveListOfDouble '}' tSurface '{' FExpr '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Intersect line not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> in, out; ListOfDouble2Vector($4, in);
        r = GModel::current()->getGEOInternals()->intersectCurvesWithSurface
          (in, (int)$8, out);
        for(std::size_t i = 0; i < out.size(); i++){
          Shape s;
          s.Type = MSH_POINT;
          s.Num = out[i];
          List_Add($$, &s);
        }
      }
      if(!r) yymsg(0, "Could not intersect line");
      List_Delete($4);
    }
  | tSplit tCurve '{' FExpr '}' tPoint '{' RecursiveListOfDouble '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Curve not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector($8, vertices);
        r = GModel::current()->getGEOInternals()->splitCurve
          ((int)$4, vertices, curves);
        for(std::size_t i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add($$, &s);
        }
      }
      if(!r) yymsg(0, "Could not split curve");
      List_Delete($8);
    }
  | tSplit tCurve '(' FExpr ')' '{' RecursiveListOfDouble '}' tEND
    {
      yymsg(2, "'Split Curve(c) {...}' is deprecated: "
            "use 'Split Curve {c} Point {...}' instead");
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Curve not available with OpenCASCADE geometry kernel");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector($7, vertices);
        r = GModel::current()->getGEOInternals()->splitCurve
          ((int)$4, vertices, curves);
        for(std::size_t i = 0; i < curves.size(); i++){
          Shape s;
          s.Type = MSH_SEGM_LINE;
          s.Num = curves[i];
          List_Add($$, &s);
        }
      }
      if(!r) yymsg(0, "Could not split curve");
      List_Delete($7);
    }
;

MultipleShape :
    ListOfShapes  { $$ = $1; }
  | Transform     { $$ = $1; }
;

ListOfShapes :
    // nothing
    {
      $$ = List_Create(3, 3, sizeof(Shape));
    }
  | ListOfShapes Shape
    {
      List_Add($$, &$2);
    }
  | ListOfShapes GeoEntity '{' RecursiveListOfDouble '}' tEND
    {
      for(int i = 0; i < List_Nbr($4); i++){
	double d;
	List_Read($4, i, &d);
	Shape s;
	s.Num = (int)d;
        switch ($2) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add($$, &s);
      }
      List_Delete($4);
    }
  | ListOfShapes tPhysical GeoEntity '{' RecursiveListOfDouble '}' tEND
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getElementaryTagsForPhysicalGroups($3, $5, tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ($3) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add($$, &s);
      }
      List_Delete(tmp);
      List_Delete($5);
    }
  | ListOfShapes tParent GeoEntity '{' RecursiveListOfDouble '}' tEND
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getParentTags($3, $5, tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ($3) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add($$, &s);
      }
      List_Delete(tmp);
      List_Delete($5);
    }
  | ListOfShapes GeoEntity '{' tDOTS '}' tEND
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      getAllElementaryTags($2, tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
	Shape s;
	s.Num = (int)d;
        switch ($2) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add($$, &s);
      }
      List_Delete(tmp);
    }
  | ListOfShapes tPhysical GeoEntity '{' tDOTS '}' tEND
    {
      List_T *tmp = List_Create(10, 10, sizeof(double));
      List_T *tmp2 = List_Create(10, 10, sizeof(double));
      getAllPhysicalTags($3, tmp2);
      getElementaryTagsForPhysicalGroups($3, tmp2, tmp);
      for(int i = 0; i < List_Nbr(tmp); i++){
	double d;
	List_Read(tmp, i, &d);
 	Shape s;
	s.Num = (int)d; // FIXME
        switch ($3) {
        case 0: s.Type = MSH_POINT    ; break;
        case 1: s.Type = MSH_SEGM_LINE; break;
        case 2: s.Type = MSH_SURF_PLAN; break; // we don't care about the actual type
        case 3: s.Type = MSH_VOLUME   ; break;
        }
        List_Add($$, &s);
      }
      List_Delete(tmp);
      List_Delete(tmp2);
    }
;

//  L E V E L S E T S

LevelSet :
    tLevelset tPlane '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      if(List_Nbr($7) == 4){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read($7, i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete($7);
    }
  | tLevelset tPoint '(' FExpr ')' tAFFECT '{' RecursiveListOfListOfDouble '}' tEND
    {
      int t = (int)$4;
      if(gLevelset::find(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	fullMatrix<double> centers(List_Nbr($8),3);
	for(int i = 0; i < List_Nbr($8); i++){
	  List_T *l = *(List_T**)List_Pointer($8, i);
	  for(int j = 0; j < List_Nbr(l); j++){
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
        gLevelset *ls = new gLevelsetPoints(centers, t);
        gLevelset::add(ls);
      }
      for(int i = 0; i < List_Nbr($8); i++)
        List_Delete(*(List_T**)List_Pointer($8, i));
      List_Delete($8);
    }
  | tLevelset tPlane '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                               RecursiveListOfDouble '}' tEND
    {
      int t = (int)$4;
      if(gLevelset::find(t)){
        yymsg(0, "Levelset %d already exists", t);
      }
      else {
        double pt[3] = {$8[0], $8[1], $8[2]};
        double n[3] = {$10[0], $10[1], $10[2]};
        gLevelset *ls = new gLevelsetPlane(pt, n, t);
        gLevelset::add(ls);
      }
      List_Delete($12);
    }
  | tLevelset tPlane '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ',' VExpr ','
                                               RecursiveListOfDouble '}' tEND
    {
      int t = (int)$4;
      if(gLevelset::find(t)){
        yymsg(0, "Levelset %d already exists", t);
      }
      else {
        double pt1[3] = {$8[0], $8[1], $8[2]};
        double pt2[3] = {$10[0], $10[1], $10[2]};
        double pt3[3] = {$12[0], $12[1], $12[2]};
        gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
        gLevelset::add(ls);
      }
      List_Delete($14);
    }
  | tLevelset tSphere '(' FExpr ')' tAFFECT '{' VExpr ',' RecursiveListOfDouble '}' tEND
    {
      if(List_Nbr($10) == 1){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read($10, 0, &d);
          gLevelset *ls = new gLevelsetSphere($8[0], $8[1], $8[2], d, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete($10);
    }
  | tLevelset tCylinder '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                                RecursiveListOfDouble '}' tEND
    {
      if(List_Nbr($12) == 1){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read($12, 0, &d);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          gLevelset::add(ls);
        }
      }
      else if(List_Nbr($12) == 2){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read($12, i, &d[i]);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          gLevelset::add(ls);
        }
      }
      else if(List_Nbr($12) == 3){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read($12, i, &d[i]);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete($12);
    }
  | tLevelset tCone '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                                RecursiveListOfDouble '}' tEND
    {
      if(List_Nbr($12) == 1){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read($12, 0, &d);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete($12);
    }
  | tLevelset tEllipsoid '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                                RecursiveListOfDouble '}' tEND
    {
      if(List_Nbr($12) == 3){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read($12, i, &d[i]);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete($12);
    }
  | tLevelset tQuadric '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                                RecursiveListOfDouble '}' tEND
    {
      if(List_Nbr($12) == 5){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[5];
          for(int i = 0; i < 5; i++)
            List_Read($12, i, &d[i]);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetGeneralQuadric(pt, dir, d[0], d[1],
                                                      d[2], d[3], d[4], t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      List_Delete($12);
    }
  | tLevelset tSTRING '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      if(!strcmp($2, "Union")){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr($7); i++) {
            double d; List_Read($7, i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp($2, "Intersection")){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr($7); i++) {
            double d; List_Read($7, i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp($2, "Cut")){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr($7); i++) {
            double d; List_Read($7, i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetCut(vl, true, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp($2, "Crack")){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr($7); i++) {
            double d; List_Read($7, i, &d);
            gLevelset *pl = gLevelset::find((int)d);
	    if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
            else vl.push_back(pl);
          }
          gLevelset *ls = new gLevelsetCrack(vl, false, t);
          gLevelset::add(ls);
        }
      }
      else if(!strcmp($2, "Reverse")){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read($7, 0, &d);
          gLevelset *pl = gLevelset::find((int)d);
          gLevelset *ls = nullptr;
          if(!pl) yymsg(0, "Unknown levelset %d", (int)d);
          else ls = new gLevelsetReverse(pl, t);
          if(ls) gLevelset::add(ls);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp($2, "PostView")){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr($7) > 0){
            double d; List_Read($7, 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            gLevelset::add(ls);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong number of arguments for levelset definition");
      Free($2);
      List_Delete($7);
    }
  | tLevelset tSTRING '(' FExpr ')' tAFFECT tBIGSTR tEND
    {
      if(!strcmp($2, "MathEval")){
        int t = (int)$4;
        if(gLevelset::find(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval($7, t);
          gLevelset::add(ls);
        }
      }
      else
        yymsg(0, "Unknown levelset '%s'", $2);
      Free($2); Free($7);
    }
  | tLevelset tSTRING '{' FExpr '}' tEND
    {
      if(!strcmp($2, "CutMesh")){
        int t = (int)$4;
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), true, false);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else if(!strcmp($2, "CutMeshTri")){
        int t = (int)$4;
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), true, true);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else if(!strcmp($2, "SplitMesh")){
        int t = (int)$4;
        if(gLevelset::find(t)){
          GModel::current()->buildCutGModel(gLevelset::find(t), false, true);
        }
        else
          yymsg(0, "Unknown levelset %d", t);
      }
      else
        yymsg(0, "Unknown levelset '%s'", $2);
      Free($2);
    }
  ;

//  D E L E T E

Delete :
    tDelete '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($3, dimTags);
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
      List_Delete($3);
    }
  | tRecursive tDelete '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($4, dimTags);
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
      List_Delete($4);
    }
  | tDelete tSTRING '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($4, dimTags);
      if(!strcmp($2, "Embedded")){
        removeEmbedded(dimTags, -1);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", $2);
      List_Delete($4);
      Free($2);
    }
  | tDelete tField '[' FExpr ']' tEND
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)$4);
#endif
    }
  | tDelete tSTRING '[' FExpr ']' tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($2, "View")){
	int index = (int)$4;
	if(index >= 0 && index < (int)PView::list.size())
	  delete PView::list[index];
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command 'Delete %s'", $2);
#endif
      Free($2);
    }
  | tDelete String__Index tEND
    {
      if(!strcmp($2, "All")){
        ClearProject();
      }
      else if(!strcmp($2, "Meshes")){
	GModel::current()->deleteMesh();
      }
      else if(!strcmp($2, "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp($2, "Physicals")){
	GModel::current()->getGEOInternals()->resetPhysicalGroups();
	GModel::current()->removePhysicalGroups();
      }
      else if(!strcmp($2, "Variables")){
	gmsh_yysymbols.clear();
      }
      else if(!strcmp($2, "Options")){
        ReInitOptions(0);
        InitOptionsGUI(0);
      }
      else{
	if(gmsh_yysymbols.count($2))
	  gmsh_yysymbols.erase($2);
	else
	  yymsg(0, "Unknown object or expression to delete '%s'", $2);
      }
      Free($2);
    }
  | tDelete tSTRING tSTRING tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($2, "Empty") && !strcmp($3, "Views")){
	for(int i = PView::list.size() - 1; i >= 0; i--)
	  if(PView::list[i]->getData()->empty()) delete PView::list[i];
      }
      else
	yymsg(0, "Unknown command 'Delete %s %s'", $2, $3);
#endif
      Free($2); Free($3);
    }
  | tDelete tDefineStruct tEND
    {
      gmsh_yynamespaces.clear();
    }
;

//  C O L O R I F Y

Colorify :
    tColor ColorExpr '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($4, dimTags);
      setColor(dimTags, $2, false);
      List_Delete($4);
    }
  | tRecursive tColor ColorExpr '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($5, dimTags);
      setColor(dimTags, $3, true);
      List_Delete($5);
    }
;

//  S E T P A R T I T I O N

SetPartition :
    tSetPartition FExpr '{' ListOfShapes '}'
    {
      yymsg(2, "'SetPartition' command is deprecated");
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($4, dimTags);
      for(std::size_t i = 0; i < dimTags.size(); i++){
        GEntity *ge = GModel::current()->getEntityByTag
          (dimTags[i].first, dimTags[i].second);
        if(ge){
          for(std::size_t j = 0; j < ge->getNumMeshElements(); j++)
            ge->getMeshElement(j)->setPartition((int)$2);
        }
      }
      List_Delete($4);
    }
;

//  V I S I B I L I T Y

Visibility :
    tShow '{' tDOTS '}'
    {
      setVisibility(-1, 1, false);
    }
  | tShow tBIGSTR tEND // deprecated: use {:} instead
    {
      setVisibility(-1, 1, false);
      Free($2);
    }
  | tHide '{' tDOTS '}'
    {
      setVisibility(-1, 0, false);
    }
  | tHide tBIGSTR tEND // deprecated: use {:} instead
    {
      setVisibility(-1, 0, false);
      Free($2);
    }
  | tShow '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($3, dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete($3);
    }
  | tRecursive tShow '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($4, dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete($4);
    }
  | tHide '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($3, dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete($3);
    }
  | tRecursive tHide '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($4, dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete($4);
    }
;

//  C O M M A N D

Command :
    String__Index StringExpr tEND
    {
      if(!strcmp($1, "Include")){
        std::string tmp = FixRelativePath(gmsh_yyname, $2);
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
      else if(!strcmp($1, "Print")){
	// make sure we have the latest data from CAD internals in GModel (fixes
	// bug where we would have no geometry in the picture if the print
	// command is in the same file as the geometry)
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, $2);
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp($1, "Save")){
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, $2);
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp($1, "Merge") || !strcmp($1, "MergeWithBoundingBox")){
	// sync CAD internals here, so that if we e.g. import a STEP file, we
        // have the correct entity tags and the numberings don't clash
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
        std::string tmp = FixRelativePath(gmsh_yyname, $2);
        MergeFile(tmp, true);
      }
      else if(!strcmp($1, "NonBlockingSystemCall")){
	SystemCall($2);
      }
      else if(!strcmp($1, "System") || !strcmp($1, "SystemCall")){
	SystemCall($2, true);
      }
      else if(!strcmp($1, "SetName")){
	GModel::current()->setName($2);
      }
      else if(!strcmp($1, "CreateDir")){
        std::string tmp = FixRelativePath(gmsh_yyname, $2);
	CreateSingleDir(tmp);
      }
      else if(!strcmp($1, "OnelabRun")){
        Msg::RunOnelabClient($2);
      }
      else if(!strcmp($1, "OptimizeMesh")){
        GModel::current()->optimizeMesh($2);
      }
      else{
	yymsg(0, "Unknown command '%s'", $1);
      }
      Free($1); Free($2);
    }
  | tOnelabRun '(' RecursiveListOfStringExprVar ')' tEND
    {
      int n = List_Nbr($3);
      if(n == 1){
        char *s; List_Read($3, 0, &s);
        Msg::RunOnelabClient(s);
        Free(s);
      }
      else if(n == 2){
        char *s, *t; List_Read($3, 0, &s); List_Read($3, 1, &t);
        Msg::RunOnelabClient(s, t);
        Free(s); Free(t);
      }
      else{
        yymsg(0, "OnelabRun takes one or two arguments");
      }
      List_Delete($3);
    }
  | String__Index String__Index '[' FExpr ']' StringExprVar tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($2, "View")){
	int index = (int)$4;
	if(index >= 0 && index < (int)PView::list.size()){
          if(!strcmp($1, "Save")){
            std::string tmp = FixRelativePath(gmsh_yyname, $6);
            PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
          }
          else if(!strcmp($1, "SendToServer")){
            PView::list[index]->sendToServer($6);
          }
          else{
            yymsg(0, "Unknown operation '%s' on view %d", $1, index);
          }
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s %s'", $1, $2);
#endif
      Free($1); Free($2); Free($6);
    }
  | String__Index String__Index String__Index '[' FExpr ']' tEND
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp($1, "Background") && !strcmp($2, "Mesh") && !strcmp($3, "View")){
	int index = (int)$5;
	if(index >= 0 && index < (int)PView::list.size())
	  GModel::current()->getFields()->setBackgroundMesh(index);
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", $1);
#endif
      Free($1); Free($2); Free($3);
    }
  | String__Index FExpr tEND
    {
      if(!strcmp($1, "Sleep")) {
	SleepInSeconds($2);
      }
      else if(!strcmp($1, "Remesh")) {
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp($1, "Mesh")) {
	int lock = CTX::instance()->lock;
	CTX::instance()->lock = 0;
        if(GModel::current()->getOCCInternals() &&
           GModel::current()->getOCCInternals()->getChanged())
          GModel::current()->getOCCInternals()->synchronize(GModel::current());
        if(GModel::current()->getGEOInternals()->getChanged())
          GModel::current()->getGEOInternals()->synchronize(GModel::current());
	GModel::current()->mesh((int)$2);
	CTX::instance()->lock = lock;
      }
      else if(!strcmp($1, "SetOrder")) {
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), $2, CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else if(!strcmp($1, "PartitionMesh")) {
        GModel::current()->partitionMesh($2);
      }
      else if(!strcmp($1, "SetCurrentWindow")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->setCurrentOpenglWindow((int)$2);
#endif
      }
      else if(!strcmp($1, "SplitCurrentWindowHorizontal")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->splitCurrentOpenglWindow('h', $2);
#endif
      }
      else if(!strcmp($1, "SplitCurrentWindowVertical")) {
#if defined(HAVE_FLTK)
        FlGui::instance()->splitCurrentOpenglWindow('v', $2);
#endif
      }
      else {
	yymsg(0, "Unknown command '%s'", $1);
      }
      Free($1);
    }
  | tUnsplitWindow tEND
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    }
  | tPlugin '(' tSTRING ')' '.' tSTRING tEND
     {
#if defined(HAVE_PLUGINS)
       try {
	 PluginManager::instance()->action($3, $6, 0);
       }
       catch(...) {
	 yymsg(0, "Unknown action '%s' or plugin '%s'", $6, $3);
       }
#endif
       Free($3); Free($6);
     }
   | tCombine tSTRING tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($2, "ElementsFromAllViews"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp($2, "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp($2, "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp($2, "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp($2, "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp($2, "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp($2, "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else if(!strcmp($2, "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig,
                       CTX::instance()->post.combineCopyOptions);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free($2);
    }
   | tExit tEND
    {
      Msg::Exit(0);
    }
   | tAbort tEND
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    }
   | tSyncModel tEND
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    }
   | tNewModel tEND
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
   | tBoundingBox tEND
    {
      CTX::instance()->forcedBBox = 0;
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      SetBoundingBox();
    }
   | tBoundingBox '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}' tEND
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox($3, $5, $7, $9, $11, $13);
    }
   | tDraw tEND
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    }
  | tSetChanged tEND
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
  | tCreateTopology '{' FExpr ',' FExpr '}' tEND
    {
      if($3) {
        GModel::current()->makeDiscreteRegionsSimplyConnected();
        GModel::current()->makeDiscreteFacesSimplyConnected();
      }
      GModel::current()->createTopologyFromMesh();
      if($5) {
        GModel::current()->exportDiscreteGEOInternals();
      }
    }
   | tCreateTopology tEND
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    }
  | tClassifySurfaces '{' FExpr ',' FExpr ',' FExpr '}' tEND
    {
      GModel::current()->classifySurfaces($3, $5, $7, M_PI);
    }
  | tClassifySurfaces '{' FExpr ',' FExpr ',' FExpr ',' FExpr '}' tEND
    {
      GModel::current()->classifySurfaces($3, $5, $7, $9);
    }
   | tCreateGeometry tEND
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    }
   | tCreateGeometry '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs($3, dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete($3);
    }
   | tRenumberMeshNodes tEND
    {
      GModel::current()->renumberMeshVertices();
    }
   | tRenumberMeshElements tEND
    {
      GModel::current()->renumberMeshElements();
    }
   | tRefineMesh tEND
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
   | tRecombineMesh tEND
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    }
  | tAdaptMesh '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}'
               '{' RecursiveListOfListOfDouble '}' '{' FExpr ',' FExpr '}' tEND
    {
      int lock = CTX::instance()->lock;
      CTX::instance()->lock = 0;
      std::vector<int> technique;
      for(int i = 0; i < List_Nbr($3); i++){
        double d;
        List_Read($3, i, &d);
        technique.push_back((int)d);
      }
      if(technique.empty()){
        yymsg(0, "Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr($6); i++){
          double d;
          List_Read($6, i, &d);
          gLevelset *l = gLevelset::find((int)d);
          if(l) f.push_back(l);
          else yymsg(0, "Unknown levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yymsg(0, "Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr($9) != (int)f.size()){
            yymsg(0, "Number of parameters != number of levelsets");
          }
          else{
            std::vector<std::vector<double> > parameters;
            parameters.resize(List_Nbr($9));
            for(int i = 0; i < List_Nbr($9); i++){
              List_T *l = *(List_T**)List_Pointer($9, i);
              for(int j = 0; j < List_Nbr(l); j++){
                double d;
                List_Read(l, j, &d);
                parameters[i].push_back(d);
              }
            }
            int niter = (int)$12;
            bool meshAll = ($14 == 0) ? false : true;
            if(GModel::current()->getOCCInternals() &&
               GModel::current()->getOCCInternals()->getChanged())
              GModel::current()->getOCCInternals()->synchronize(GModel::current());
            if(GModel::current()->getGEOInternals()->getChanged())
              GModel::current()->getGEOInternals()->synchronize(GModel::current());
            GModel::current()->adaptMesh(technique, f, parameters, niter, meshAll);
          }
        }
      }
      List_Delete($3);
      List_Delete($6);
      for(int i = 0; i < List_Nbr($9); i++)
        List_Delete(*(List_T**)List_Pointer($9, i));
      List_Delete($9);
      CTX::instance()->lock = lock;
    }
;

// S L I D E

Slide :
     tSlide '(' '{' RecursiveListOfDouble '}' ',' StringExpr ',' StringExpr ')'  tEND
     {
#if defined(HAVE_POPPLER)
       std::vector<int> is;
       for(int i = 0; i < List_Nbr($4); i++){
	 double d;
	 List_Read($4, i, &d);
	 is.push_back ((int) d);
       }
       gmshPopplerWrapper::instance()->setMacroForPages(is, $7, $9 );
#endif
     }

// L O O P

Loop :
    tFor '(' FExpr tDOTS FExpr ')'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $3;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if($3 > $5)
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
  | tFor '(' FExpr tDOTS FExpr tDOTS FExpr ')'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $3;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5;
      LoopControlVariablesTab[ImbricatedLoop][2] = $7;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(($7 > 0. && $3 > $5) || ($7 < 0. && $3 < $5))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr '}'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $5;
      LoopControlVariablesTab[ImbricatedLoop][1] = $7;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = $2;
      gmsh_yysymbol &s(gmsh_yysymbols[$2]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = $5;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if($5 > $7)
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free($2);
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr tDOTS FExpr '}'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $5;
      LoopControlVariablesTab[ImbricatedLoop][1] = $7;
      LoopControlVariablesTab[ImbricatedLoop][2] = $9;
      LoopControlVariablesNameTab[ImbricatedLoop] = $2;
      gmsh_yysymbol &s(gmsh_yysymbols[$2]);
      s.list = false;
      s.value.resize(1);
      s.value[0] = $5;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(($9 > 0. && $5 > $7) || ($9 < 0. && $5 < $7))
	skip("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
      Free($2);
    }
  | tEndFor
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
  | tMacro tSTRING
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string($2), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", $2);
      skip(nullptr, "Return");
      Free($2);
    }
  | tMacro StringExpr
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string($2), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", $2);
      skip(nullptr, "Return");
      Free($2);
    }
  | tReturn
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    }
  | tCall String__Index tEND
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string($2), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", $2);
      Free($2);
    }
  | tCall StringExpr tEND
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string($2), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", $2);
      Free($2);
    }
  | tIf '(' FExpr ')'
    {
      ImbricatedTest++;
      if(ImbricatedTest > MAX_RECUR_TESTS-1){
	yymsg(0, "Reached maximum number of imbricated tests");
        ImbricatedTest = MAX_RECUR_TESTS-1;
      }

      if($3){
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
  | tElseIf '(' FExpr ')'
    {
      if(ImbricatedTest > 0){
        if(statusImbricatedTests[ImbricatedTest]){
          // Last test (If or ElseIf) was true, thus go after EndIf (out of If EndIf)
          skip("If", "EndIf");
          ImbricatedTest--;
        }
        else{
          // Previous test(s) (If and ElseIf) not yet true
          if($3){
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
  | tElse
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
  | tEndIf
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    }
;

//  E X T R U D E

Extrude :
    tExtrude VExpr '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($4, inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->extrude
          (inDimTags, $2[0], $2[1], $2[2], outDimTags);
      }
      else{
        r = GModel::current()->getGEOInternals()->extrude
          (inDimTags, $2[0], $2[1], $2[2], outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      $$ = $4;
      List_Reset($$);
      VectorOfPairs2ListOfShapes(outDimTags, $$);
    }
  | tExtrude '{' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($10, inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->revolve
          (inDimTags, $5[0], $5[1], $5[2], $3[0], $3[1], $3[2], $7, outDimTags);
      }
      else{
        r = GModel::current()->getGEOInternals()->revolve
          (inDimTags, $5[0], $5[1], $5[2], $3[0], $3[1], $3[2], $7, outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      $$ = $10;
      List_Reset($$);
      VectorOfPairs2ListOfShapes(outDimTags, $$);
    }
  | tExtrude '{' VExpr ',' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($12, inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->twist
          (inDimTags, $7[0], $7[1], $7[2], $3[0], $3[1], $3[2], $5[0], $5[1], $5[2],
           $9, outDimTags);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      $$ = $12;
      List_Reset($$);
      VectorOfPairs2ListOfShapes(outDimTags, $$);
    }
  | tExtrude VExpr '{' ListOfShapes
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                       ExtrudeParameters '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($4, inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->extrude
          (inDimTags, $2[0], $2[1], $2[2], outDimTags, &extr);
      }
      else{
        r = GModel::current()->getGEOInternals()->extrude
          (inDimTags, $2[0], $2[1], $2[2], outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      $$ = $4;
      List_Reset($$);
      VectorOfPairs2ListOfShapes(outDimTags, $$);
    }
  | tExtrude '{' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                                                   ExtrudeParameters '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($10, inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->revolve
          (inDimTags, $5[0], $5[1], $5[2], $3[0], $3[1], $3[2], $7, outDimTags,
           &extr);
      }
      else{
        r = GModel::current()->getGEOInternals()->revolve
          (inDimTags, $5[0], $5[1], $5[2], $3[0], $3[1], $3[2], $7, outDimTags,
           &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      $$ = $10;
      List_Reset($$);
      VectorOfPairs2ListOfShapes(outDimTags, $$);
    }
  | tExtrude '{' VExpr ',' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                                                             ExtrudeParameters '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($12, inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Twisting extrude not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->twist
          (inDimTags, $7[0], $7[1], $7[2], $3[0], $3[1], $3[2], $5[0], $5[1], $5[2],
           $9,  outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      $$ = $12;
      List_Reset($$);
      VectorOfPairs2ListOfShapes(outDimTags, $$);
    }
  | tExtrude '{' ListOfShapes
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                       ExtrudeParameters '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($3, inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Boundary layer extrusion not available with OpenCASCADE geometry kernel");
      }
      else{
        r = GModel::current()->getGEOInternals()->boundaryLayer
          (inDimTags, outDimTags, &extr);
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      $$ = $3;
      List_Reset($$);
      VectorOfPairs2ListOfShapes(outDimTags, $$);
    }
  | tExtrude '{' ListOfShapes '}' tUsing tWire '{' FExpr '}'
    {
      std::vector<std::pair<int, int> > inDimTags, outDimTags;
      ListOfShapes2VectorOfPairs($3, inDimTags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addPipe(inDimTags, (int)$8, outDimTags);
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not extrude shapes");
      $$ = $3;
      List_Reset($$);
      VectorOfPairs2ListOfShapes(outDimTags, $$);
    }
  | tThruSections ListOfDouble
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector($2, wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, false, false, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, $$);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add thrusections");
      List_Delete($2);
    }
  | tRuled tThruSections ListOfDouble
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> wires; ListOfDouble2Vector($3, wires);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->addThruSections
          (-1, wires, false, true, outDimTags);
        VectorOfPairs2ListOfShapes(outDimTags, $$);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not add ruled thrusections");
      List_Delete($3);
    }
  | tFillet '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}'
            '{' RecursiveListOfDouble '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> regions, edges;
        ListOfDouble2Vector($3, regions); ListOfDouble2Vector($6, edges);
        std::vector<double> radii;
        ListOfDouble2Vector($9, radii);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->fillet
          (regions, edges, radii, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, $$);
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not fillet shapes");
      List_Delete($3);
      List_Delete($6);
      List_Delete($9);
    }
  | tChamfer '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}'
             '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<int> regions, edges, surfaces;
        ListOfDouble2Vector($3, regions); ListOfDouble2Vector($6, edges);
        ListOfDouble2Vector($9, surfaces);
        std::vector<double> distances;
        ListOfDouble2Vector($12, distances);
        std::vector<std::pair<int, int> > outDimTags;
        r = GModel::current()->getOCCInternals()->chamfer
          (regions, edges, surfaces, distances, outDimTags, true);
        VectorOfPairs2ListOfShapes(outDimTags, $$);
      }
      else{
        yymsg(0, "Chamfer only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not chamfer shapes");
      List_Delete($3);
      List_Delete($6);
      List_Delete($9);
      List_Delete($12);
    }
;

ExtrudeParameters :
    ExtrudeParameter
    {
    }
  | ExtrudeParameters ExtrudeParameter
    {
    }
;

ExtrudeParameter :
    tLayers '{' FExpr '}' tEND
    {
      int n = (int)fabs($3);
      if(n){ // we accept n==0 to easily disable layers
        extr.mesh.ExtrudeMesh = true;
        extr.mesh.NbLayer = 1;
        extr.mesh.NbElmLayer.clear();
        extr.mesh.hLayer.clear();
        extr.mesh.NbElmLayer.push_back((int)fabs($3));
        extr.mesh.hLayer.push_back(1.);
      }
    }
  | tLayers '{' ListOfDouble ',' ListOfDouble '}' tEND
    {
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr($3);
      if(List_Nbr($3) == List_Nbr($5)){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr($3); i++){
	  double d;
	  List_Read($3, i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read($5, i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d}", List_Nbr($3), List_Nbr($5));
      List_Delete($3);
      List_Delete($5);
    }
  | tScaleLast tEND
    {
      extr.mesh.ScaleLast = true;
    }
  | tRecombine tEND
    {
      extr.mesh.Recombine = true;
    }
  | tRecombine FExpr tEND
    {
      extr.mesh.Recombine = $2 ? true : false;
    }
  | tQuadTriAddVerts tEND
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    }
  | tQuadTriAddVerts tRecombLaterals tEND
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    }
  | tQuadTriNoNewVerts tEND
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    }
  | tQuadTriNoNewVerts tRecombLaterals tEND
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    }
  | tHole '(' FExpr ')' tAFFECT ListOfDouble tUsing FExpr tEND
    {
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      int num = (int)$3;
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = $8;
      extr.mesh.Holes[num].second = tags;
      List_Delete($6);
    }
  | tUsing tSTRING '[' FExpr ']' tEND
    {
      if(!strcmp($2, "Index"))
        extr.mesh.BoundaryLayerIndex = $4;
      else if(!strcmp($2, "View"))
        extr.mesh.ViewIndex = $4;
      Free($2);
    }
;

//  B O O L E A N

BooleanOperator :
    tBooleanUnion { $$ = OCC_Internals::Union; }
  | tBooleanIntersection { $$ = OCC_Internals::Intersection; }
  | tBooleanDifference { $$ = OCC_Internals::Difference; }
  | tBooleanSection { $$ = OCC_Internals::Section; }
  | tBooleanFragments { $$ = OCC_Internals::Fragments; }
;

BooleanOption :
  { $$ = 0; }
  | tDelete tEND { $$ = 1; }
  | tRecursive tDelete tEND { $$ = 2; }
  | tDelete FExpr tEND { $$ = $2 ? 1 : 0; }
  | tRecursive tDelete FExpr tEND { $$ = $3 ? 2 : 0; }

Boolean :
    BooleanOperator '{' ListOfShapes BooleanOption '}'
                    '{' ListOfShapes BooleanOption '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int > > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs($3, object);
        ListOfShapes2VectorOfPairs($7, tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          (-1, (OCC_Internals::BooleanOperator)$1, object, tool, out, outMap, $4, $8);
        VectorOfPairs2ListOfShapes(out, $$);
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete($3);
      List_Delete($7);
    }
  | tShapeFromFile '(' StringExprVar ')'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > out;
        std::string tmp = FixRelativePath(gmsh_yyname, $3);
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        VectorOfPairs2ListOfShapes(out, $$);
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Could import shape");
      Free($3);
    }
;

BooleanShape :
    BooleanOperator '(' FExpr ')' tAFFECT '{' ListOfShapes BooleanOption '}'
                                          '{' ListOfShapes BooleanOption '}' tEND
    {
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<std::pair<int, int> > object, tool, out;
        std::vector<std::vector<std::pair<int, int > > > outMap;
        ListOfShapes2VectorOfPairs($7, object);
        ListOfShapes2VectorOfPairs($11, tool);
        // currently we don't distinguish between Delete and Recursive Delete:
        // we always delete recursively. Let us know if you have examples where
        // having the choice would be interesting
        r = GModel::current()->getOCCInternals()->booleanOperator
          ((int)$3, (OCC_Internals::BooleanOperator)$1, object, tool, out, outMap, $8, $12);
      }
      if(!r) yymsg(0, "Could not apply boolean operator");
      List_Delete($7);
      List_Delete($11);
    }

//  M E S H I N G   C O N S T R A I N T S   ( T R A N S F I N I T E ,   . . . )

TransfiniteType :
    {
      $$[0] = $$[1] = 1.;
    }
  | tUsing tSTRING FExpr
    {
      if(!strcmp($2, "Progression") || !strcmp($2, "Power"))
        $$[0] = 1.;
      else if(!strcmp($2, "Bump"))
        $$[0] = 2.;
      else if(!strcmp($2, "Beta"))
        $$[0] = 3.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        $$[0] = 1.;
      }
      $$[1] = $3;
      Free($2);
    }
;

TransfiniteArrangement :
    {
      $$ = -1; // left
    }
  | tSTRING
    {
      if(!strcmp($1, "Right"))
        $$ = 1;
      else if(!strcmp($1, "Left"))
	$$ = -1;
      else if(!strcmp($1, "AlternateRight"))
	$$ = 2;
      else if(!strcmp($1, "AlternateLeft"))
	$$ = -2;
      else // "Alternate" -> "Alternate Right"
	$$ = 2;
      Free($1);
    }
;

TransfiniteCorners :
   {
     $$ = List_Create(1, 1, sizeof(double));
   }
 | tAFFECT ListOfDouble
   {
     $$ = $2;
   }

RecombineAngle :
    {
      $$ = 45;
    }
  | tAFFECT FExpr
    {
      $$ = (int)$2;
    }
;

PeriodicTransform :
    {
      $$ = List_Create(1, 1, sizeof(double));
    }
  | tAffine ListOfDouble
    {
      $$ = $2;
    }
;

Constraints :
    tMeshSize ListOfDoubleOrAll tAFFECT FExpr tEND
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
      List_T *tmp = $2;
      if(!$2){
        tmp = List_Create(100, 100, sizeof(double));
        getAllElementaryTags(0, tmp);
      }
      for(int i = 0; i < List_Nbr(tmp); i++){
        double d;
        List_Read(tmp, i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, $4);
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, $4);
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex($4);
      }
      List_Delete(tmp);
    }
  // deprecated syntax: use MeshSize instead
  | tCharacteristic tLength ListOfDoubleOrAll tAFFECT FExpr tEND
    {
      List_T *tmp = $3;
      if(!$3){
        tmp = List_Create(100, 100, sizeof(double));
        getAllElementaryTags(0, tmp);
      }
      for(int i = 0; i < List_Nbr(tmp); i++){
        double d;
        List_Read(tmp, i, &d);
        int tag = (int)d;
        if(GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->setMeshSize(0, tag, $5);
        GModel::current()->getGEOInternals()->setMeshSize(0, tag, $5);
        GVertex *gv = GModel::current()->getVertexByTag(tag);
        if(gv) gv->setPrescribedMeshSizeAtVertex($5);
      }
      List_Delete(tmp);
    }
  | tTransfinite tCurve ListOfDoubleOrAll tAFFECT FExpr TransfiniteType tEND
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      int type = (int)$6[0];
      double coef = fabs($6[1]);
      int npoints = ((int)$5 < 2) ? 2 : (int)$5;
      if(!$3){
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
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
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
        List_Delete($3);
      }
    }
  | tTransfinite tSurface ListOfDoubleOrAll TransfiniteCorners TransfiniteArrangement tEND
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      std::vector<int> corners; ListOfDouble2Vector($4, corners);
      if(!$3){
        GModel::current()->getGEOInternals()->setTransfiniteSurface(0, $5, corners);
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
          (*it)->meshAttributes.transfiniteArrangement = $5;
        }
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteSurface(tag, $5, corners);
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf){
            gf->meshAttributes.method = MESH_TRANSFINITE;
            gf->meshAttributes.transfiniteArrangement = $5;
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
        List_Delete($3);
      }
      List_Delete($4);
    }
  | tTransfinite tVolume ListOfDoubleOrAll TransfiniteCorners tEND
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      std::vector<int> corners; ListOfDouble2Vector($4, corners);
      if(!$3){
        GModel::current()->getGEOInternals()->setTransfiniteVolume(0, corners);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++){
          (*it)->meshAttributes.method = MESH_TRANSFINITE;
        }
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
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
        List_Delete($3);
      }
      List_Delete($4);
    }
  | tTransfQuadTri ListOfDoubleOrAll tEND
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!$2){
        GModel::current()->getGEOInternals()->setTransfiniteVolumeQuadTri(0);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++)
          (*it)->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
      }
      else{
        for(int i = 0; i < List_Nbr($2); i++){
          double d;
          List_Read($2, i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setTransfiniteVolumeQuadTri(tag);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr) gr->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
        }
        List_Delete($2);
      }
    }
  | tSetTag GeoEntity '(' FExpr ',' FExpr ')' tEND
    {
      int dim = (int)$2;
      int tag = (int)$4;
      GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
      if(ge){
	int new_tag = (int)$6;
	ge->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model entity of dimension %d and tag %d", dim, tag);
      }
    }
  | tSetMaxTag GeoEntity '(' FExpr ')' tEND
    {
      int dim = (int)$2;
      int tag = (int)$4;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->setMaxTag(dim, tag);
      }
      else {
        GModel::current()->getGEOInternals()->setMaxTag(dim, tag);
      }
    }
  | tMeshAlgorithm tSurface '{' RecursiveListOfDouble '}' tAFFECT FExpr tEND
    {
      // mesh algorithm constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr($4); i++){
        double d;
        List_Read($4, i, &d);
        int tag = (int)d;
        GModel::current()->getGEOInternals()->setMeshAlgorithm(2, tag, (int)$7);
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(gf) gf->setMeshingAlgo((int)$7);
      }
      List_Delete($4);
    }
  | tMeshSizeFromBoundary tSurface '{' RecursiveListOfDouble '}' tAFFECT FExpr tEND
    {
      // lcExtendFromBoundary onstraints are stored in GEO internals in addition
      // to GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr($4); i++){
        double d;
        List_Read($4, i, &d);
        int tag = (int)d;
        GModel::current()->getGEOInternals()->setMeshSizeFromBoundary(2, tag, (int)$7);
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(gf) gf->setMeshSizeFromBoundary((int)$7);
      }
      List_Delete($4);
    }
  | tRecombine tSurface ListOfDoubleOrAll RecombineAngle tEND
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!$3){
        GModel::current()->getGEOInternals()->setRecombine(2, 0, $4);
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.recombine = 1;
          (*it)->meshAttributes.recombineAngle = $4;
        }
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setRecombine(2, tag, $4);
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf){
            gf->meshAttributes.recombine = 1;
            gf->meshAttributes.recombineAngle = $4;
          }
        }
        List_Delete($3);
      }
    }
  | tRecombine tVolume ListOfDoubleOrAll tEND
    {
      // recombine constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!$3){
        GModel::current()->getGEOInternals()->setRecombine(3, 0, 0.);
        for(GModel::riter it = GModel::current()->firstRegion();
            it != GModel::current()->lastRegion(); it++){
          (*it)->meshAttributes.recombine3D = 1;
        }
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setRecombine(3, tag, 0.);
          GRegion *gr = GModel::current()->getRegionByTag(tag);
          if(gr) gr->meshAttributes.recombine3D = 1;
        }
        List_Delete($3);
      }
    }
  | tSmoother tSurface ListOfDoubleOrAll tAFFECT FExpr tEND
    {
      // smoothing constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!$3){
        GModel::current()->getGEOInternals()->setSmoothing(0, (int)$5);
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++){
          (*it)->meshAttributes.transfiniteSmoothing = (int)$5;
        }
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          int tag = (int)d;
          GModel::current()->getGEOInternals()->setSmoothing(tag, (int)$5);
          GFace *gf = GModel::current()->getFaceByTag(tag);
          if(gf) gf->meshAttributes.transfiniteSmoothing = (int)$5;
        }
        List_Delete($3);
      }
    }
  | tPeriodic tCurve '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' PeriodicTransform tEND
    {
      if(List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master lines (%d) different from number of "
              "slaves (%d) ", List_Nbr($8), List_Nbr($4));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr($10) != 0) {
          if(List_Nbr($10) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries (we have %d)",
                  List_Nbr($10));
          }
          else {
            transfo.resize(List_Nbr($10));
            for(int i = 0; i < List_Nbr($10); i++)
              List_Read($10, i, &transfo[i]);
          }
        }
        for(int i = 0; i < List_Nbr($4); i++){
          double d_master, d_slave;
          List_Read($8, i, &d_master);
          List_Read($4, i, &d_slave);
          int j_master = (int)d_master;
          int j_slave  = (int)d_slave;
          addPeriodicEdge(j_slave, j_master, transfo);
        }
      }
      List_Delete($4);
      List_Delete($8);
    }
  | tPeriodic tSurface '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' PeriodicTransform tEND
    {
      if(List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr($8), List_Nbr($4));
      }
      else{
        if(List_Nbr($10) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries");
        }
        else {
          std::vector<double> transfo(16,0);
          for(int i = 0; i < List_Nbr($10); i++)
            List_Read($10, i, &transfo[i]);
          for(int i = 0; i < List_Nbr($4); i++){
            double d_master, d_slave;
            List_Read($8, i, &d_master);
            List_Read($4, i, &d_slave);
            addPeriodicFace(d_slave, d_master, transfo);
          }
        }
      }
      List_Delete($4);
      List_Delete($8);
    }
  | tPeriodic tCurve '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' tRotate '{' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      if(List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master curves (%d) different from number of "
              "slaves (%d) ", List_Nbr($8), List_Nbr($4));
      }
      else{
        SPoint3 axis($12[0],$12[1],$12[2]);
        SPoint3 origin($14[0],$14[1],$14[2]);
        double  angle($16);
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr($4); i++){
          double d_master, d_slave;
          List_Read($8, i, &d_master);
          List_Read($4, i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete($4);
      List_Delete($8);
    }
  | tPeriodic tSurface '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' tRotate '{' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      if(List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr($8), List_Nbr($4));
      }
      else{
        SPoint3 origin($14[0],$14[1],$14[2]);
        SPoint3 axis($12[0],$12[1],$12[2]);
        double  angle($16);
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr($4); i++){
          double d_master, d_slave;
          List_Read($8, i, &d_master);
          List_Read($4, i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete($4);
      List_Delete($8);
    }
  | tPeriodic tCurve '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' tTranslate VExpr tEND
    {
      if(List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master curves (%d) different from number of "
              "slaves (%d) ", List_Nbr($8), List_Nbr($4));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation($11[0],$11[1],$11[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr($4); i++){
          double d_master, d_slave;
          List_Read($8, i, &d_master);
          List_Read($4, i, &d_slave);
          addPeriodicEdge(d_slave,d_master,transfo);
        }
      }
      List_Delete($4);
      List_Delete($8);
    }
  | tPeriodic tSurface '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' tTranslate VExpr tEND
    {
      if(List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr($8), List_Nbr($4));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation($11[0],$11[1],$11[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

        for(int i = 0; i < List_Nbr($4); i++){
          double d_master, d_slave;
          List_Read($8, i, &d_master);
          List_Read($4, i, &d_slave);
          addPeriodicFace(d_slave, d_master, transfo);
        }
      }
      List_Delete($4);
      List_Delete($8);
    }
  | tPeriodic tSurface FExpr '{' RecursiveListOfDouble '}'
    tAFFECT FExpr '{' RecursiveListOfDouble '}' tEND
    {
      if(List_Nbr($5) != List_Nbr($10)){
        yymsg(0, "Number of master surface curves (%d) different from number of "
              "slave (%d) curves", List_Nbr($10), List_Nbr($5));
      }
      else{
        int j_master = (int)$8;
        int j_slave = (int)$3;
        std::map<int,int> edgeCounterParts;
        for(int i = 0; i < List_Nbr($5); i++){
          double ds,dm;
          List_Read($5,i,&ds);
          List_Read($10,i,&dm);
          edgeCounterParts[(int) ds] = (int) dm;
        }
        addPeriodicFace(j_slave, j_master, edgeCounterParts);
      }
      List_Delete($5);
      List_Delete($10);
    }
  | GeoEntity '{' RecursiveListOfDouble '}' tIn GeoEntity '{' FExpr '}' tEND
    {
      if(($6==2 || $6==3) && $1<$6 ) {
        std::vector<int> tags; ListOfDouble2Vector($3, tags);
        addEmbedded($1, tags, $6, (int)$8);
      }
      else {
        yymsg(0, "GeoEntity of dim %d In GeoEntity of dim %d not allowed", $1, $6);
      }
      List_Delete($3);
    }
  | tReverseMesh GeoEntity12 ListOfDoubleOrAll tEND
    {
      // reverse mesh constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(!$3){
        GModel::current()->getGEOInternals()->setReverseMesh($2, 0);
        switch ($2) {
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
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          int num = (int)d;
          GModel::current()->getGEOInternals()->setReverseMesh($2, num);
          switch ($2) {
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
        List_Delete($3);
      }
    }
  | tRelocateMesh GeoEntity02 ListOfDoubleOrAll tEND
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      if(!$3){
        switch ($2) {
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
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          switch ($2) {
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
        List_Delete($3);
      }
    }
  | tReorientMesh tVolume ListOfDouble tEND
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      for(int i = 0; i < List_Nbr($3); i++){
        double d;
        List_Read($3, i, &d);
        GRegion *gr = GModel::current()->getRegionByTag((int)d);
        if(gr) gr->setOutwardOrientationMeshConstraint();
      }
      List_Delete($3);
    }
  | tDegenerated tCurve ListOfDouble tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double dnum;
	List_Read($3, i, &dnum);
	int num = (int)dnum;
        GModel::current()->getGEOInternals()->setDegenerated(1, num);
        GEdge *ge = GModel::current()->getEdgeByTag(num);
        if(ge) ge->setTooSmall(true);
      }
      List_Delete($3);
    }
  | tCompound GeoEntity123 ListOfDouble tEND
    {
      std::vector<int> tags; ListOfDouble2Vector($3, tags);
      GModel::current()->getGEOInternals()->setCompoundMesh($2, tags);
      List_Delete($3);
    }
;

//  C O H E R E N C E

Coherence :
    tCoherence tEND
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    }
  | tCoherence tSTRING tEND
    {
      if(!strcmp($2, "Geometry")){
        if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
          GModel::current()->getOCCInternals()->removeAllDuplicates();
        else
          GModel::current()->getGEOInternals()->removeAllDuplicates();
      }
      else if(!strcmp($2, "Mesh")){
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      }
      else
        yymsg(0, "Unknown coherence command");
      Free($2);
    }
  | tCoherence tPoint '{' RecursiveListOfDouble '}' tEND
    {
      std::vector<int> tags; ListOfDouble2Vector($4, tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete($4);
    }
;

//  H O M O L O G Y

HomologyCommand :
    tHomology { $$ = (char*)"Homology"; }
  | tCohomology { $$ = (char*)"Cohomology"; }
  | tBetti { $$ = (char*)"Betti"; }
 ;

Homology :
    HomologyCommand tEND
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest($1, domain, subdomain, dim);
    }
  | HomologyCommand '{' ListOfDouble '}' tEND
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr($3); i++){
        double d;
        List_Read($3, i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest($1, domain, subdomain, dim);
      List_Delete($3);
    }
  | HomologyCommand '{' ListOfDouble ',' ListOfDouble '}' tEND
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr($3); i++){
        double d;
        List_Read($3, i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr($5); i++){
        double d;
        List_Read($5, i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest($1, domain, subdomain, dim);
      List_Delete($3);
      List_Delete($5);
    }
  | HomologyCommand '(' ListOfDouble ')' '{' ListOfDouble ',' ListOfDouble '}' tEND
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < List_Nbr($6); i++){
        double d;
        List_Read($6, i, &d);
        domain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr($8); i++){
        double d;
        List_Read($8, i, &d);
        subdomain.push_back((int)d);
      }
      for(int i = 0; i < List_Nbr($3); i++){
        double d;
        List_Read($3, i, &d);
        dim.push_back((int)d);
      }
      GModel::current()->addHomologyRequest($1, domain, subdomain, dim);
      List_Delete($6);
      List_Delete($8);
      List_Delete($3);
    }
 ;

//  G E N E R A L

FExpr :
    FExpr_Single                  { $$ = $1;           }
  | '(' FExpr ')'                 { $$ = $2;           }
  | '-' FExpr %prec UNARYPREC     { $$ = -$2;          }
  | '+' FExpr %prec UNARYPREC     { $$ = $2;           }
  | '!' FExpr                     { $$ = !$2;          }
  | FExpr '-' FExpr               { $$ = $1 - $3;      }
  | FExpr '+' FExpr               { $$ = $1 + $3;      }
  | FExpr '*' FExpr               { $$ = $1 * $3;      }
  | FExpr '/' FExpr
    {
      if(!$3)
	yymsg(0, "Division by zero in '%g / %g'", $1, $3);
      else
	$$ = $1 / $3;
    }
  | FExpr '|' FExpr                { $$ = (int)$1 | (int)$3; }
  | FExpr '&' FExpr                { $$ = (int)$1 & (int)$3; }
  | FExpr '%' FExpr                { $$ = (int)$1 % (int)$3; }
  | FExpr '^' FExpr                { $$ = pow($1, $3);  }
  | FExpr '<' FExpr                { $$ = $1 < $3;      }
  | FExpr '>' FExpr                { $$ = $1 > $3;      }
  | FExpr tLESSOREQUAL FExpr       { $$ = $1 <= $3;     }
  | FExpr tGREATEROREQUAL FExpr    { $$ = $1 >= $3;     }
  | FExpr tEQUAL FExpr             { $$ = $1 == $3;     }
  | FExpr tNOTEQUAL FExpr          { $$ = $1 != $3;     }
  | FExpr tAND FExpr               { $$ = $1 && $3;     }
  | FExpr tOR FExpr                { $$ = $1 || $3;     }
  | FExpr tGREATERGREATER FExpr    { $$ = ((int)$1 >> (int)$3); }
  | FExpr tLESSLESS FExpr          { $$ = ((int)$1 << (int)$3); }
  | FExpr '?' FExpr tDOTS FExpr    { $$ = $1 ? $3 : $5; }
  | tExp    LP FExpr RP            { $$ = exp($3);      }
  | tLog    LP FExpr RP            { $$ = log($3);      }
  | tLog10  LP FExpr RP            { $$ = log10($3);    }
  | tSqrt   LP FExpr RP            { $$ = sqrt($3);     }
  | tSin    LP FExpr RP            { $$ = sin($3);      }
  | tAsin   LP FExpr RP            { $$ = asin($3);     }
  | tCos    LP FExpr RP            { $$ = cos($3);      }
  | tAcos   LP FExpr RP            { $$ = acos($3);     }
  | tTan    LP FExpr RP            { $$ = tan($3);      }
  | tAtan   LP FExpr RP            { $$ = atan($3);     }
  | tAtan2  LP FExpr ',' FExpr RP  { $$ = atan2($3, $5);}
  | tSinh   LP FExpr RP            { $$ = sinh($3);     }
  | tCosh   LP FExpr RP            { $$ = cosh($3);     }
  | tTanh   LP FExpr RP            { $$ = tanh($3);     }
  | tFabs   LP FExpr RP            { $$ = fabs($3);     }
  | tAbs    LP FExpr RP            { $$ = std::abs($3); }
  | tFloor  LP FExpr RP            { $$ = floor($3);    }
  | tCeil   LP FExpr RP            { $$ = ceil($3);     }
  | tRound  LP FExpr RP            { $$ = floor($3 + 0.5); }
  | tFmod   LP FExpr ',' FExpr RP  { $$ = fmod($3, $5); }
  | tModulo LP FExpr ',' FExpr RP  { $$ = fmod($3, $5); }
  | tHypot  LP FExpr ',' FExpr RP  { $$ = sqrt($3 * $3 + $5 * $5); }
  | tRand   LP FExpr RP            { $$ = $3 * (double)rand() / (double)RAND_MAX; }
  | tMax    LP FExpr ',' FExpr RP  { $$ = std::max($3, $5); }
  | tMin    LP FExpr ',' FExpr RP  { $$ = std::min($3, $5); }
;

// FIXME: add +=, -=, *= et /=

FExpr_Single :

  // Constants

    tDOUBLE   { $$ = $1; }
  | tPi       { $$ = 3.141592653589793; }
  | tTestLevel { $$ = (double)ImbricatedTest; }
  | tMPI_Rank { $$ = Msg::GetCommRank(); }
  | tMPI_Size { $$ = Msg::GetCommSize(); }
  | tGMSH_MAJOR_VERSION { $$ = GetGmshMajorVersion(); }
  | tGMSH_MINOR_VERSION { $$ = GetGmshMinorVersion(); }
  | tGMSH_PATCH_VERSION { $$ = GetGmshPatchVersion(); }
  | tCpu { $$ = Cpu(); }
  | tMemory { $$ = GetMemoryUsage()/1024./1024.; }
  | tTotalMemory { $$ = TotalRam(); }

  // Variables

  | tDefineNumber LP FExpr
    { init_options(); }
    FloatParameterOptionsOrNone RP
    {
      std::vector<double> val(1, $3);
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      $$ = val[0];
    }
  | DefineStruct
    {
      $$ = $1;
    }
  | tGetNumber LP StringExprVar RP
    {
      $$ = Msg::GetOnelabNumber($3);
      Free($3);
    }
  | tGetNumber LP StringExprVar ',' FExpr RP
    {
      $$ = Msg::GetOnelabNumber($3, $5);
      Free($3);
    }
  | Struct_FullName
    {
      $$ = treat_Struct_FullName_Float($1.char1, $1.char2);
    }
  | String__Index '[' FExpr ']'
    //  | Struct_FullName '[' FExpr ']'
    {
      $$ = treat_Struct_FullName_Float(nullptr, $1, 2, (int)$3);
    }
  | String__Index '(' FExpr ')'
    //  | Struct_FullName '(' FExpr ')'
    {
      $$ = treat_Struct_FullName_Float(nullptr, $1, 2, (int)$3);
    }
  | tExists '(' Struct_FullName ')'
    {
      $$ = treat_Struct_FullName_Float($3.char1, $3.char2, 1, 0, 0., 1);
    }
  | tExists '(' Struct_FullName '.' tSTRING_Reserved ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float($3.char1, $3.char2, $5, 0, 0., 1);
    }
  | tGetForced '(' Struct_FullName GetForced_Default ')'
    {
      $$ = treat_Struct_FullName_Float($3.char1, $3.char2, 1, 0, $4, 2);
    }
  | tGetForced '(' Struct_FullName '.' tSTRING_Reserved GetForced_Default ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float($3.char1, $3.char2, $5, 0, $6, 2);
    }
  | tGetForced '(' Struct_FullName LP FExpr RP GetForced_Default ')'
    {
      $$ = treat_Struct_FullName_Float($3.char1, $3.char2, 2, (int)$5, $7, 2);
    }
  | tGetForced '(' Struct_FullName '.' tSTRING_Reserved LP FExpr RP GetForced_Default ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float($3.char1, $3.char2, $5, (int)$7, $9, 2);
    }
  | tFileExists '(' StringExpr ')'
    {
      std::string tmp = FixRelativePath(gmsh_yyname, $3);
      $$ = !StatFile(tmp);
      Free($3);
    }
  | '#' String__Index LP RP
    {
      if(gmsh_yysymbols.count($2)){
        gmsh_yysymbol &s(gmsh_yysymbols[$2]);
	$$ = s.value.size();
      }
      else if(gmsh_yystringsymbols.count($2)){
	$$ = gmsh_yystringsymbols[$2].size();
      }
      else{
        yymsg(0, "Unknown variable '%s'", $2);
	$$ = 0.;
      }
      Free($2);
    }
  | '#' Struct_FullName '.' tSTRING_Reserved LP RP
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float_getDim($2.char1, $2.char2, $4);
    }
  | tDimNameSpace LP String__Index RP
    {
      std::string struct_namespace($3);
      $$ = (double)gmsh_yynamespaces[struct_namespace].size();
      Free($3);
    }
  | tDimNameSpace LP RP
    {
      std::string struct_namespace(std::string(""));
      $$ = (double)gmsh_yynamespaces[struct_namespace].size();
    }
  | String__Index NumericIncrement
    {
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
        if(s.value.empty()){
          yymsg(0, "Uninitialized variable '%s'", $1);
          $$ = 0.;
        }
        else{
          $$ = s.value[0];
          s.value[0] += $2;
        }
      }
      Free($1);
    }
  | String__Index '[' FExpr ']' NumericIncrement
    {
      int index = (int)$3;
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", $1, index);
          $$ = 0.;
        }
        else{
          $$ = s.value[index];
          s.value[index] += $5;
        }
      }
      Free($1);
    }
  | String__Index '(' FExpr ')' NumericIncrement
    {
      int index = (int)$3;
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
        if((int)s.value.size() < index + 1){
          yymsg(0, "Uninitialized variable '%s[%d]'", $1, index);
          $$ = 0.;
        }
        else{
          $$ = s.value[index];
          s.value[index] += $5;
        }
      }
      Free($1);
    }
  // Option Strings
  | String__Index '.' tSTRING_Reserved
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float(nullptr, $1, $3);
    }
  | String__Index tSCOPE String__Index '.' tSTRING_Reserved
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float($1, $3, $5);
    }
  | String__Index '.' tSTRING_Reserved '(' FExpr ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float(nullptr, $1, $3, (int)$5);
    }
  | String__Index tSCOPE String__Index '.' tSTRING_Reserved '(' FExpr ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float($1, $3, $5, (int)$7);
    }
  | String__Index '.' tSTRING_Reserved '[' FExpr ']'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float(nullptr, $1, $3, (int)$5);
    }
  | String__Index tSCOPE String__Index '.' tSTRING_Reserved '[' FExpr ']'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_Float($1, $3, $5, (int)$7);
    }
  | String__Index '[' FExpr ']' '.' tSTRING_Reserved
    {
      NumberOption(GMSH_GET, $1, (int)$3, $6, $$);
      Free($1); Free($6);
    }
  | String__Index '.' tSTRING_Reserved NumericIncrement
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, 0, $3, d)){
	d += $4;
	NumberOption(GMSH_SET|GMSH_GUI, $1, 0, $3, d);
	$$ = d;
      }
      Free($1); Free($3);
    }
  | String__Index '[' FExpr ']' '.' tSTRING_Reserved NumericIncrement
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, (int)$3, $6, d)){
	d += $7;
	NumberOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $6, d);
	$$ = d;
      }
      Free($1); Free($6);
    }
  | tGetValue '(' StringExprVar ',' FExpr ')'
    {
      $$ = Msg::GetValue($3, $5);
      Free($3);
    }
  | tFind '(' ListOfDouble ',' ListOfDouble ')'
    {
      int matches = 0;
      for(int i = 0; i < List_Nbr($3); i++){
        double d;
        List_Read($3, i, &d);
        matches += List_Search($5, &d, fcmp_double);
      }
      $$ = matches;
      Free($3); Free($5);
    }
  | tStrFind LP StringExprVar ',' StringExprVar RP
    {
      std::string s($3), substr($5);
      if(s.find(substr) != std::string::npos)
        $$ = 1.;
      else
        $$ = 0.;
      Free($3); Free($5);
    }
  | tStrLen LP StringExprVar RP
    {
      $$ = strlen($3);
      Free($3);
    }
  | tStrCmp LP StringExprVar ',' StringExprVar RP
    {
      $$ = strcmp($3, $5);
      Free($3); Free($5);
    }
  | tTextAttributes '(' RecursiveListOfStringExprVar ')'
    {
      int align = 0, font = 0, fontsize = CTX::instance()->glFontSize;
      if(List_Nbr($3) % 2){
        yymsg(0, "Number of text attributes should be even");
      }
      else{
        for(int i = 0 ; i < List_Nbr($3); i += 2){
          char *s1, *s2; List_Read($3, i, &s1); List_Read($3, i + 1, &s2);
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
      List_Delete($3);
      $$ = (double)((align<<16)|(font<<8)|(fontsize));
    }
;

GetForced_Default :
    // none
    { $$ = 0.; }
  | ',' FExpr
    { $$ = $2;}
;

GetForcedStr_Default :
    // none
    { $$ = nullptr; }
  | ',' StringExprVar
    { $$ = $2;}
;

DefineStruct :
    tDefineStruct Struct_FullName AppendOrNot
    {
      std::string struct_namespace($2.char1? $2.char1 : std::string("")),
        struct_name($2.char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    }
    '[' FloatParameterOptionsOrNone_NoComma ']'
    {
      std::string struct_namespace($2.char1? $2.char1 : std::string("")),
        struct_name($2.char2);
      Free($2.char1); Free($2.char2);
      int tag_out;
      if(gmsh_yynamespaces.defStruct(struct_namespace, struct_name,
                                      floatOptions, charOptions,
                                      tag_out, member_ValMax, $3))
        yymsg(0, "Redefinition of Struct '%s::%s'",
              struct_namespace.c_str(), struct_name.c_str());
      $$ = (double)tag_out;
    }
;

Struct_FullName :
    String__Index
    { $$.char1 = nullptr; $$.char2 = $1; }
  | String__Index tSCOPE String__Index
    { $$.char1 = $1; $$.char2 = $3; }
;

Append :
    tAppend
    { $$ = 99; } // Default: max level
  | tAppend FExpr
    { $$ = (int)$2; }
  ;

AppendOrNot :
    /* none */
    { $$ = 0; }
  | '(' Append ')'
    { $$ = $2; }
  ;

VExpr :
    VExpr_Single
    {
      memcpy($$, $1, 5*sizeof(double));
    }
  | '-' VExpr %prec UNARYPREC
    {
      for(int i = 0; i < 5; i++) $$[i] = -$2[i];
    }
  | '+' VExpr %prec UNARYPREC
    {
      for(int i = 0; i < 5; i++) $$[i] = $2[i];
    }
  | VExpr '-' VExpr
    {
      for(int i = 0; i < 5; i++) $$[i] = $1[i] - $3[i];
    }
  | VExpr '+' VExpr
    {
      for(int i = 0; i < 5; i++) $$[i] = $1[i] + $3[i];
    }
;

VExpr_Single :
    '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr  '}'
    {
      $$[0] = $2;  $$[1] = $4;  $$[2] = $6;  $$[3] = $8; $$[4] = $10;
    }
  | '{' FExpr ',' FExpr ',' FExpr ',' FExpr '}'
    {
      $$[0] = $2;  $$[1] = $4;  $$[2] = $6;  $$[3] = $8; $$[4] = 1.0;
    }
  | '{' FExpr ',' FExpr ',' FExpr '}'
    {
      $$[0] = $2;  $$[1] = $4;  $$[2] = $6;  $$[3] = 0.0; $$[4] = 1.0;
    }
  | '(' FExpr ',' FExpr ',' FExpr ')'
    {
      $$[0] = $2;  $$[1] = $4;  $$[2] = $6;  $$[3] = 0.0; $$[4] = 1.0;
    }
;

RecursiveListOfListOfDouble :
    ListOfDouble
    {
      $$ = List_Create(2, 1, sizeof(List_T*));
      List_Add($$, &($1));
    }
  | RecursiveListOfListOfDouble ',' ListOfDouble
    {
      List_Add($$, &($3));
    }
;

ListOfDouble :
    FExpr
    {
      $$ = List_Create(2, 1, sizeof(double));
      List_Add($$, &($1));
    }
  | FExpr_Multi
    {
      $$ = $1;
    }
  | '{' '}'
    {
      // creates an empty list
      $$ = List_Create(2, 1, sizeof(double));
    }
  | '{' RecursiveListOfDouble '}'
    {
      $$ = $2;
    }
  | '-' '{' RecursiveListOfDouble '}'
    {
      $$ = $3;
      for(int i = 0; i < List_Nbr($$); i++){
	double *pd = (double*)List_Pointer($$, i);
	(*pd) = - (*pd);
      }
    }
  | FExpr '*' '{' RecursiveListOfDouble '}'
    {
      $$ = $4;
      for(int i = 0; i < List_Nbr($$); i++){
	double *pd = (double*)List_Pointer($$, i);
	(*pd) *= $1;
      }
    }
;

ListOfDoubleOrAll :
    ListOfDouble
    {
      $$ = $1;
    }
  | '{' tDOTS '}'
    {
      $$ = 0;
    }
  | tBIGSTR // deprecated: use {:} instead
    {
      if(!strcmp($1, "*") || !strcmp($1, "all")){
        $$ = 0;
      }
      else{
        yyerror("Unknown special string for list replacement");
        $$ = List_Create(2, 1, sizeof(double));
      }
      Free($1);
    }
;

FExpr_Multi :
    '-' FExpr_Multi %prec UNARYPREC
    {
      $$ = $2;
      for(int i = 0; i < List_Nbr($$); i++){
	double *pd = (double*)List_Pointer($$, i);
	(*pd) = - (*pd);
      }
    }
  | FExpr '*' FExpr_Multi
    {
      $$ = $3;
      for(int i = 0; i < List_Nbr($$); i++){
	double *pd = (double*)List_Pointer($$, i);
	(*pd) *= $1;
      }
    }
  | FExpr tDOTS FExpr
    {
      $$ = List_Create(2, 1, sizeof(double));
      for(double d = $1; ($1 < $3) ? (d <= $3) : (d >= $3);
          ($1 < $3) ? (d += 1.) : (d -= 1.))
	List_Add($$, &d);
    }
  | FExpr tDOTS FExpr tDOTS FExpr
    {
      $$ = List_Create(2, 1, sizeof(double));
      if(!$5){  //|| ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)
        yymsg(0, "Wrong increment in '%g:%g:%g'", $1, $3, $5);
      }
      else
	for(double d = $1; ($5 > 0) ? (d <= $3) : (d >= $3); d += $5)
	  List_Add($$, &d);
   }
  | tPoint '{' FExpr '}'
    {
      $$ = List_Create(3, 1, sizeof(double));
      int tag = (int)$3;
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
      List_Add($$, &x);
      List_Add($$, &y);
      List_Add($$, &z);
    }
  | tPoint '{' tDOTS '}'
    {
      $$ = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, $$);
    }
  | tPoint tBIGSTR // deprecated syntax: use {:} instead
    {
      $$ = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, $$);
      Free($2);
    }
  | GeoEntity123 '{' tDOTS '}'
    {
      $$ = List_Create(10, 10, sizeof(double));
      getAllElementaryTags($1, $$);
    }
  | GeoEntity123 tBIGSTR // deprecated syntax: use {:} instead
    {
      $$ = List_Create(10, 10, sizeof(double));
      getAllElementaryTags($1, $$);
      Free($2);
    }
  | tPhysical GeoEntity ListOfDoubleOrAll
    {
      $$ = List_Create(10, 10, sizeof(double));
      if(!$3){
        getAllPhysicalTags($2, $$);
      }
      else{
        getElementaryTagsForPhysicalGroups($2, $3, $$);
        List_Delete($3);
      }
    }
  | tParent GeoEntity ListOfDouble
    {
      $$ = List_Create(10, 10, sizeof(double));
      getParentTags($2, $3, $$);
      List_Delete($3);
    }
   | GeoEntity tIn tBoundingBox ListOfDouble
    {
      $$ = List_Create(10, 10, sizeof(double));
      if(List_Nbr($4) < 6) {
        yymsg(0, "Bounding box should be {xmin, ymin, zmin, xmax, ymax, zmax}");
      }
      else {
        double bb[6];
        for(int i = 0; i < 6; i++) List_Read($4, i, &bb[i]);
        getElementaryTagsInBoundingBox
          ($1, bb[0], bb[1], bb[2], bb[3], bb[4], bb[5], $$);
      }
      List_Delete($4);
    }
   | tBoundingBox GeoEntity '{' RecursiveListOfDouble '}'
    {
      $$ = List_Create(10, 10, sizeof(double));
      getBoundingBox($2, $4, $$);
      List_Delete($4);
    }
   | tMass GeoEntity123 '{' FExpr '}'
    {
      $$ = List_Create(1, 1, sizeof(double));
      double m = 0;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->getMass($2, (int)$4, m);
      }
      else{
        yymsg(0, "Mass only available with OpenCASCADE geometry kernel");
      }
      List_Add($$, &m);
    }
   | tCenterOfMass GeoEntity123 '{' FExpr '}'
    {
      $$ = List_Create(3, 1, sizeof(double));
      double x = 0., y = 0., z = 0.;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        GModel::current()->getOCCInternals()->getCenterOfMass($2, (int)$4, x, y, z);
      }
      else{
        yymsg(0, "CenterOfMass only available with OpenCASCADE geometry kernel");
      }
      List_Add($$, &x);
      List_Add($$, &y);
      List_Add($$, &z);
    }
   | tMatrixOfInertia GeoEntity123 '{' FExpr '}'
    {
      $$ = List_Create(9, 1, sizeof(double));
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        std::vector<double> mat;
        GModel::current()->getOCCInternals()->getMatrixOfInertia($2, (int)$4, mat);
        for(std::size_t i = 0; i < mat.size(); i++)
          List_Add($$, &mat[i]);
      }
      else{
        yymsg(0, "MatrixOfInertia only available with OpenCASCADE geometry kernel");
      }
    }
  | Transform
    {
      $$ = List_Create(List_Nbr($1), 1, sizeof(double));
      for(int i = 0; i < List_Nbr($1); i++){
	Shape *s = (Shape*) List_Pointer($1, i);
	double d = s->Num;
	List_Add($$, &d);
      }
      List_Delete($1);
    }
  | Extrude
    {
      $$ = List_Create(List_Nbr($1), 1, sizeof(double));
      for(int i = 0; i < List_Nbr($1); i++){
	Shape *s = (Shape*) List_Pointer($1, i);
	double d = s->Num;
	List_Add($$, &d);
      }
      List_Delete($1);
    }
  | Boolean
    {
      $$ = List_Create(List_Nbr($1), 1, sizeof(double));
      for(int i = 0; i < List_Nbr($1); i++){
	Shape *s = (Shape*) List_Pointer($1, i);
	double d = s->Num;
	List_Add($$, &d);
      }
      List_Delete($1);
    }
  | String__Index LP RP
    {
      $$ = List_Create(20, 20, sizeof(double));
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1);
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
	for(std::size_t i = 0; i < s.value.size(); i++)
	  List_Add($$, &s.value[i]);
      }
      Free($1);
    }
  | String__Index '.' tSTRING_Reserved LP RP
    {
      $$ = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, $1, $3);
    }
  | String__Index tSCOPE String__Index '.' tSTRING_Reserved LP RP
    {
      $$ = treat_Struct_FullName_dot_tSTRING_ListOfFloat($1, $3, $5);
    }
   // for compatibility with GetDP
  | tList '[' String__Index ']'
    {
      $$ = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count($3))
	yymsg(0, "Unknown variable '%s'", $3);
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$3]);
	for(std::size_t i = 0; i < s.value.size(); i++)
	  List_Add($$, &s.value[i]);
      }
      Free($3);
    }
  | tList '[' FExpr_Multi ']'
    {
      $$ = $3;
    }
  | tList '(' FExpr_Multi ')'
    {
      $$ = $3;
    }
  | tList LP '{' RecursiveListOfDouble '}' RP
    {
      $$ = $4;
    }
  | String__Index LP '{' RecursiveListOfDouble '}' RP
    {
      $$ = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1);
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
	for(int i = 0; i < List_Nbr($4); i++){
	  int index = (int)(*(double*)List_Pointer_Fast($4, i));
	  if((int)s.value.size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", $1, index);
	  else
	    List_Add($$, &s.value[index]);
	}
      }
      Free($1);
      List_Delete($4);
    }
  | tLinSpace LP FExpr ',' FExpr ',' FExpr RP
    {
      $$ = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)$7; i++) {
	double d = $3 + ($5-$3)*(double)i/($7-1);
	List_Add($$, &d);
      }
    }
  | tLogSpace LP FExpr ',' FExpr ',' FExpr RP
    {
      $$ = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)$7; i++) {
	double d = pow(10,$3 + ($5-$3)*(double)i/($7-1));
	List_Add($$, &d);
      }
    }
  | tListFromFile LP StringExprVar RP
    {
      Msg::Barrier();
      FILE *File;
      $$ = List_Create(100, 100, sizeof(double));
      std::string tmp = FixRelativePath(gmsh_yyname, $3);
      if(!(File = Fopen(tmp.c_str(), "rb"))){
        yymsg(0, "Could not open file '%s'", $3);
      }
      else{
	double d;
	while(!feof(File)){
          int ret = fscanf(File, "%lf", &d);
	  if(ret == 1){
	    List_Add($$, &d);
          }
          else if(ret == EOF){
            break;
          }
          else{
            char dummy[1024];
            fscanf(File, "%s", dummy);
            yymsg(0, "Ignoring '%s' in file '%s'", dummy, $3);
          }
        }
	fclose(File);
      }
      Free($3);
    }
  | tCatenary LP FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr RP
    {
      double x0 = $3, x1 = $5, y0 = $7, y1 = $9, ys = $11;
      int N = (int)$13;
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        yymsg(1, "Catenary did not converge, using linear interpolation");
      $$ = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add($$, &y[i]);
    }
  | tUnique LP FExpr_Multi RP
    {
      std::vector<double> tmp;
      for(int i = 0; i < List_Nbr($3); i++){
        double d; List_Read($3, i, &d);
        tmp.push_back(d);
      }
      std::sort(tmp.begin(), tmp.end());
      auto last = std::unique(tmp.begin(), tmp.end());
      tmp.erase(last, tmp.end());
      $$ = $3;
      List_Reset($$);
      for(std::size_t i = 0; i < tmp.size(); i++){
        List_Add($$, &tmp[i]);
      }
    }
  | tAbs LP FExpr_Multi RP
    {
      for(int i = 0; i < List_Nbr($3); i++){
        double *d = (double*)List_Pointer($3, i);
        *d = std::abs(*d);
      }
      $$ = $3;
    }
;

RecursiveListOfDouble :
    FExpr
    {
      $$ = List_Create(2, 1, sizeof(double));
      List_Add($$, &($1));
    }
  | FExpr_Multi
    {
      $$ = $1;
    }
  | RecursiveListOfDouble ',' FExpr
    {
      List_Add($$, &($3));
    }
  | RecursiveListOfDouble ',' FExpr_Multi
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	List_Add($$, &d);
      }
      List_Delete($3);
    }
;

ColorExpr :
    '{' FExpr ',' FExpr ',' FExpr ',' FExpr '}'
    {
      $$ = CTX::instance()->packColor((int)$2, (int)$4, (int)$6, (int)$8);
    }
  | '{' FExpr ',' FExpr ',' FExpr '}'
    {
      $$ = CTX::instance()->packColor((int)$2, (int)$4, (int)$6, 255);
    }
/* shift/reduce conflict
  | '{' tSTRING ',' FExpr '}'
    {
      int flag;
      $$ = GetColorForString((int)$4, $2, &flag);
      if(flag) yymsg(0, "Unknown color '%s'", $2);
    }
*/
  | String__Index
    {
      int flag = 0;
      if(gmsh_yystringsymbols.count($1)){
        if(gmsh_yystringsymbols[$1].size()){
          $$ = GetColorForString(-1, gmsh_yystringsymbols[$1][0].c_str(), &flag);
        }
        else{
          yymsg(0, "Unknown color '%s'", $1);
          $$ = 0;
        }
      }
      else
        $$ = GetColorForString(-1, $1, &flag);
      if(flag) yymsg(0, "Unknown color '%s'", $1);
      Free($1);
    }
  | tSTRING '.' tColor '.' tSTRING
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, $1, 0, $5, val);
      $$ = val;
      Free($1); Free($5);
    }
;

ListOfColor :
    '{' RecursiveListOfColor '}'
    {
      $$ = $2;
    }
  | String__Index '[' FExpr ']' '.' tColorTable
    {
      $$ = List_Create(256, 10, sizeof(unsigned int));
      GmshColorTable *ct = GetColorTable((int)$3);
      if(!ct)
	yymsg(0, "View[%d] does not exist", (int)$3);
      else{
	for(int i = 0; i < ct->size; i++)
	  List_Add($$, &ct->table[i]);
      }
      Free($1);
    }
;

RecursiveListOfColor :
    ColorExpr
    {
      $$ = List_Create(256, 10, sizeof(unsigned int));
      List_Add($$, &($1));
    }
  | RecursiveListOfColor ',' ColorExpr
    {
      List_Add($$, &($3));
    }
;

StringExprVar :
    StringExpr
    {
      $$ = $1;
    }
  | String__Index
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      $$ = treat_Struct_FullName_String(nullptr, $1);
    }
  | String__Index '[' FExpr ']'
    {
      std::string val;
      int j = (int)$3;
      if(!gmsh_yystringsymbols.count($1))
        yymsg(0, "Unknown string variable '%s'", $1);
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[$1].size())
        val = gmsh_yystringsymbols[$1][j];
      else
        yymsg(0, "Index %d out of range", j);
      $$ = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy($$, val.c_str());
      Free($1);
    }
  | String__Index '(' FExpr ')'
    {
      std::string val;
      int j = (int)$3;
      if(!gmsh_yystringsymbols.count($1))
        yymsg(0, "Unknown string variable '%s'", $1);
      else if(j >= 0 && j < (int)gmsh_yystringsymbols[$1].size())
        val = gmsh_yystringsymbols[$1][j];
      else
        yymsg(0, "Index %d out of range", j);
      $$ = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy($$, val.c_str());
      Free($1);
    }
  | String__Index '.' tSTRING_Reserved
    {
      $$ = treat_Struct_FullName_dot_tSTRING_String(nullptr, $1, $3);
    }
  | String__Index tSCOPE String__Index '.' tSTRING_Reserved
    {
      $$ = treat_Struct_FullName_dot_tSTRING_String($1, $3, $5);
    }
  | String__Index '.' tSTRING_Reserved '(' FExpr ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_String(nullptr, $1, $3, (int)$5);
    }
  | String__Index tSCOPE String__Index '.' tSTRING_Reserved '(' FExpr ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_String($1, $3, $5, (int)$7);
    }
  | String__Index '[' FExpr ']' '.' tSTRING
    {
      std::string out;
      StringOption(GMSH_GET, $1, (int)$3, $6, out);
      $$ = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy($$, out.c_str());
      Free($1); Free($6);
    }
  | GeoEntity '{' FExpr '}'
    {
      std::string name = GModel::current()->getElementaryName($1, (int)$3);
      $$ = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy($$, name.c_str());
    }
  | tPhysical GeoEntity '{' FExpr '}'
    {
      std::string name = GModel::current()->getPhysicalName($2, (int)$4);
      $$ = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy($$, name.c_str());
    }
;

StringExpr :
    tBIGSTR
    {
      $$ = $1;
    }
  | tNameToString '[' String__Index ']'
    {
      $$ = $3;
    }
  | tToday
    {
      $$ = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy($$, ctime(&now));
      $$[strlen($$) - 1] = '\0';
    }
  | tGmshExecutableName
    {
      std::string exe = Msg::GetExecutableName();
      $$ = (char *)Malloc(exe.size() + 1);
      strcpy($$, exe.c_str());
    }
  | tOnelabAction
    {
      std::string action = Msg::GetOnelabAction();
      $$ = (char *)Malloc(action.size() + 1);
      strcpy($$, action.c_str());
    }
  | tCodeName
    {
      $$ = strsave((char*)"Gmsh");
    }
  | tGetEnv '(' StringExprVar ')'
    {
      std::string env = GetEnvironmentVar($3);
      $$ = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy($$, env.c_str());
      Free($3);
    }
  | tGetStringValue '(' StringExprVar ',' StringExprVar ')'
    {
      std::string s = Msg::GetString($3, $5);
      $$ = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy($$, s.c_str());
      Free($3);
      Free($5);
    }
  | tGetString LP StringExprVar RP
    {
      std::string s = Msg::GetOnelabString($3);
      $$ = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy($$, s.c_str());
      Free($3);
    }
  | tGetString LP StringExprVar ',' StringExprVar RP
    {
      std::string s = Msg::GetOnelabString($3, $5);
      $$ = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy($$, s.c_str());
      Free($3);
      Free($5);
    }
    //+++ No need to extend to Struct_FullName (a Tag is not a String), but...
  | tGetForcedStr '(' Struct_FullName GetForcedStr_Default ')'
    {
      $$ = treat_Struct_FullName_String(nullptr, $3.char2, 1, 0, $4, 2);
    }
  | tGetForcedStr '(' Struct_FullName '.' tSTRING_Reserved GetForcedStr_Default ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_String($3.char1, $3.char2, $5, 0, $6, 2);
    }
  | tStrCat LP RecursiveListOfStringExprVar RP
    {
      int size = 1;
      for(int i = 0; i < List_Nbr($3); i++)
        size += strlen(*(char**)List_Pointer($3, i)) + 1;
      $$ = (char*)Malloc(size * sizeof(char));
      $$[0] = '\0';
      for(int i = 0; i < List_Nbr($3); i++){
        char *s;
        List_Read($3, i, &s);
        strcat($$, s);
        Free(s);
      }
      List_Delete($3);
    }
  | tStrPrefix '(' StringExprVar ')'
    {
      $$ = (char *)Malloc((strlen($3) + 1) * sizeof(char));
      int i;
      for(i = strlen($3) - 1; i >= 0; i--){
	if($3[i] == '.'){
	  strncpy($$, $3, i);
	  $$[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy($$, $3);
      Free($3);
    }
  | tStrRelative '(' StringExprVar ')'
    {
      $$ = (char *)Malloc((strlen($3) + 1) * sizeof(char));
      int i;
      for(i = strlen($3) - 1; i >= 0; i--){
	if($3[i] == '/' || $3[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy($$, $3);
      else
	strcpy($$, &$3[i+1]);
      Free($3);
    }
  | tStrReplace '(' StringExprVar ',' StringExprVar ',' StringExprVar ')'
    {
      std::string input = $3;
      std::string substr_old = $5;
      std::string substr_new = $7;
      std::string ret = ReplaceSubString(substr_old, substr_new, input);
      $$ = (char *)Malloc((ret.size() + 1) * sizeof(char));
      strcpy($$, ret.c_str());
      Free($3);
      Free($5);
      Free($7);
    }
  | tStr LP RecursiveListOfStringExprVar RP
    {
      int size = 1;
      for(int i = 0; i < List_Nbr($3); i++)
        size += strlen(*(char**)List_Pointer($3, i)) + 1;
      $$ = (char*)Malloc(size * sizeof(char));
      $$[0] = '\0';
      for(int i = 0; i < List_Nbr($3); i++){
        char *s;
        List_Read($3, i, &s);
        strcat($$, s);
        Free(s);
        if(i != List_Nbr($3) - 1) strcat($$, "\n");
      }
      List_Delete($3);
    }
  | tUpperCase LP StringExprVar RP
    {
      int i = 0;
      while ($3[i]) {
        $3[i] = toupper($3[i]);
        i++;
      }
      $$ = $3;
    }
  | tLowerCase LP StringExprVar RP
    {
      int i = 0;
      while ($3[i]) {
        $3[i] = tolower($3[i]);
        i++;
      }
      $$ = $3;
    }
  | tLowerCaseIn LP StringExprVar RP
    {
      int i = 0;
      while ($3[i]) {
        if(i > 0 && $3[i-1] != '_')
          $3[i] = tolower($3[i]);
        i++;
      }
      $$ = $3;
    }
  | tStrChoice LP FExpr ',' StringExprVar ',' StringExprVar RP
    {
      if($3){
        $$ = $5;
        Free($7);
      }
      else{
        $$ = $7;
        Free($5);
      }
    }
  | tStrSub LP StringExprVar ',' FExpr ',' FExpr RP
    {
      std::string in = $3;
      std::string out = in.substr((int)$5, (int)$7);
      $$ = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy($$, out.c_str());
      Free($3);
    }
  | tStrSub LP StringExprVar ',' FExpr RP
    {
      std::string in = $3;
      std::string out = in.substr((int)$5, std::string::npos);
      $$ = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy($$, out.c_str());
      Free($3);
    }
  | tSprintf LP StringExprVar RP
    {
      $$ = $3;
    }
  | tSprintf LP StringExprVar ',' RecursiveListOfDouble RP
    {
      char tmpstring[5000];
      int i = printListOfDouble($3, $5, tmpstring);
      if(i < 0){
	yymsg(0, "Too few arguments in Sprintf");
	$$ = $3;
      }
      else if(i > 0){
	yymsg(0, "%d extra argument%s in Sprintf", i, (i > 1) ? "s" : "");
	$$ = $3;
      }
      else{
	$$ = (char*)Malloc((strlen(tmpstring) + 1) * sizeof(char));
	strcpy($$, tmpstring);
	Free($3);
      }
      List_Delete($5);
    }
  | tFixRelativePath LP StringExprVar RP
    {
      std::string tmp = FixRelativePath(gmsh_yyname, $3);
      $$ = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy($$, tmp.c_str());
      Free($3);
    }
  | tCurrentDirectory
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      $$ = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy($$, tmp.c_str());
    }
  | tCurrentFileName
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      $$ = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy($$, tmp.c_str());
    }
  | tDirName LP StringExprVar RP
    {
      std::string tmp = SplitFileName($3)[0];
      $$ = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy($$, tmp.c_str());
      Free($3);
    }
  | tAbsolutePath LP StringExprVar RP
    {
      std::string tmp = GetAbsolutePath($3);
      $$ = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy($$, tmp.c_str());
      Free($3);
    }
  | tDefineString LP StringExpr
    { init_options(); }
    CharParameterOptionsOrNone RP
    {
      std::string val($3);
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      $$ = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy($$, val.c_str());
      Free($3);
    }
  | tNameStruct LP NameStruct_Arg RP
    {
      std::string out;
      const std::string * key_struct = nullptr;
      switch (gmsh_yynamespaces.get_key_struct_from_tag(struct_namespace,
                                                        (int)$3, key_struct)) {
      case 0:
        out = *key_struct;
        break;
      case 1:
        yymsg(1, "Unknown NameSpace '%s' of Struct", struct_namespace.c_str());
        break;
      case 2:
        yymsg(1, "Unknown Struct of index %d", (int)$3);
        break;
      default:
        break;
      }
      $$ = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy($$, out.c_str());
    }
;

NameStruct_Arg :
    '#' FExpr
    { struct_namespace = std::string(""); $$ = $2; }
  | String__Index tSCOPE '#' FExpr
    { struct_namespace = $1; Free($1); $$ = $4; }
;


Str_BracedRecursiveListOfStringExprVar :
    tStr LP BracedRecursiveListOfStringExprVar RP
    { $$ = $3; }
 ;

BracedOrNotRecursiveListOfStringExprVar :
    RecursiveListOfStringExprVar
    { $$ = $1; }
  | BracedRecursiveListOfStringExprVar
    { $$ = $1; }
 ;

BracedRecursiveListOfStringExprVar :
    '{' RecursiveListOfStringExprVar '}'
    { $$ = $2; }
 ;

RecursiveListOfStringExprVar :
    StringExprVar
    {
      $$ = List_Create(20,20,sizeof(char*));
      List_Add($$, &($1));
    }
  | MultiStringExprVar
    { $$ = $1; }
  | RecursiveListOfStringExprVar ',' StringExprVar
    {
      List_Add($$, &($3));
    }
  | RecursiveListOfStringExprVar ',' MultiStringExprVar
    {
      for(int i = 0; i < List_Nbr($3); i++){
	char* c;
	List_Read($3, i, &c);
	List_Add($$, &c);
      }
      List_Delete($3);
    }
 ;

MultiStringExprVar :
    String__Index '(' ')'
    {
      $$ = List_Create(20, 20, sizeof(char *));
      if(!gmsh_yystringsymbols.count($1))
	yymsg(0, "Unknown string variable '%s'", $1);
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[$1]);
	for(std::size_t i = 0; i < s.size(); i++) {
          char * val_ = strsave((char*)s.at(i).c_str());
	  List_Add($$, &val_);
        }
      }
      Free($1);
    }
  | String__Index '.' tSTRING_Reserved '(' ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, $1, $3);
    }
  | String__Index tSCOPE String__Index '.' tSTRING_Reserved '(' ')'
    {
      $$ = treat_Struct_FullName_dot_tSTRING_ListOfString($1, $3, $5);
    }
;

StringIndex :
    tSTRING '~' '{' FExpr '}'
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)$4);
      $$ = (char *)Malloc((strlen($1)+strlen(tmpstr)+1)*sizeof(char));
      strcpy($$, $1); strcat($$, tmpstr);
      Free($1);
    }
  | StringIndex '~' '{' FExpr '}'
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)$4);
      $$ = (char *)Malloc((strlen($1)+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy($$, $1) ; strcat($$, tmpstr) ;
      Free($1);
    }
  | tStringToName '[' StringExprVar ']' '~' '{' FExpr '}'
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)$7);
      $$ = (char *)Malloc((strlen($3)+strlen(tmpstr)+1)*sizeof(char));
      strcpy($$, $3); strcat($$, tmpstr);
      Free($3);
    }
 ;

String__Index :
    tSTRING
    { $$ = $1; }
  | StringIndex
    { $$ = $1; }
  // Create a name from any string
  | tStringToName '[' StringExprVar ']'
    { $$ = $3; }
 ;

%%

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
  for(size_t i = 0; i < 3; i++,idx++) {
    int tIdx = i*4+3;
    tfo[tIdx] = origin[i] + translation[i];
    for(int j = 0; j < 3; j++,idx++) tfo[tIdx] -= tfo[idx] * origin[j];
  }

  for(int i = 0; i < 4; i++) tfo[12+i] = 0;
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
