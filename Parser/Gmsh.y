%{
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
#include "GeoInterpolation.h"
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


// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, gmsh_yysymbol> gmsh_yysymbols;
std::map<std::string, std::vector<std::string> > gmsh_yystringsymbols;

// Static parser variables (accessible only in this file)
#if defined(HAVE_POST)
static PViewDataList *ViewData;
#endif
static std::vector<double> ViewCoord;
static std::vector<double> *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static gmshSurface *myGmshSurface = 0;
#define MAX_RECUR_TESTS 100
static int statusImbricatedTests[MAX_RECUR_TESTS];
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0, ImbricatedTest = 0;
static gmshfpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static std::string LoopControlVariablesNameTab[MAX_RECUR_LOOPS];
static std::map<std::string, std::vector<double> > floatOptions;
static std::map<std::string, std::vector<std::string> > charOptions;
static std::string factory;

void yyerror(const char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
void skip_until_test(const char *skip, const char *until,
                     const char *until2, int l_until2_sub, int *type_until2);
void assignVariable(const std::string &name, int index, int assignType,
                    double value);
void assignVariables(const std::string &name, List_T *indices, int assignType,
                     List_T *values);
void incrementVariable(const std::string &name, int index, double value);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
void PrintParserSymbols(std::vector<std::string> &vec);
fullMatrix<double> ListOfListOfDouble2Matrix(List_T *list);
void ListOfDouble2Vector(List_T *list, std::vector<int> &v);
void ListOfDouble2Vector(List_T *list, std::vector<double> &v);

void addPeriodicEdge(int, int, const std::vector<double>&);
void addPeriodicFace(int, int, const std::map<int,int>&);
void addPeriodicFace(int, int, const std::vector<double>&);
void computeAffineTransformation(SPoint3&, SPoint3&, double, SPoint3&, std::vector<double>&);
char *strsave(char *ptr);

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
}

%token <d> tDOUBLE
%token <c> tSTRING tBIGSTR

%token tEND tAFFECT tDOTS tPi tMPI_Rank tMPI_Size tEuclidian tCoordinates tTestLevel
%token tExp tLog tLog10 tSqrt tSin tAsin tCos tAcos tTan tRand
%token tAtan tAtan2 tSinh tCosh tTanh tFabs tFloor tCeil tRound
%token tFmod tModulo tHypot tList tLinSpace tLogSpace tListFromFile tCatenary
%token tPrintf tError tStr tSprintf tStrCat tStrPrefix tStrRelative tStrReplace
%token tAbsolutePath tDirName tStrSub tStrLen
%token tFind tStrFind tStrCmp tStrChoice tUpperCase tLowerCase tLowerCaseIn
%token tTextAttributes
%token tBoundingBox tDraw tSetChanged tToday tFixRelativePath tCurrentDirectory
%token tSyncModel tNewModel
%token tOnelabAction tOnelabRun
%token tCpu tMemory tTotalMemory
%token tCreateTopology tCreateTopologyNoHoles
%token tDistanceFunction tDefineConstant tUndefineConstant
%token tDefineNumber tDefineString tSetNumber tSetString
%token tPoint tCircle tEllipse tLine tSphere tPolarSphere tSurface tSpline tVolume
%token tBlock tCylinder tCone tTorus tEllipsoid tQuadric tShapeFromFile
%token tRectangle tDisk tWire
%token tCharacteristic tLength tParametric tElliptic tRefineMesh tAdaptMesh
%token tRelocateMesh tSetFactory tThruSections tWedge tFillet tChamfer
%token tPlane tRuled tTransfinite tComplex tPhysical tCompound tPeriodic
%token tUsing tPlugin tDegenerated tRecursive
%token tRotate tTranslate tSymmetry tDilate tExtrude tLevelset tAffine
%token tBooleanUnion tBooleanIntersection tBooleanDifference tBooleanSection
%token tBooleanFragments tThickSolid
%token tRecombine tSmoother tSplit tDelete tCoherence
%token tIntersect tMeshAlgorithm tReverse
%token tLayers tScaleLast tHole tAlias tAliasWithOptions tCopyOptions
%token tQuadTriAddVerts tQuadTriNoNewVerts tQuadTriSngl tQuadTriDbl
%token tRecombLaterals tTransfQuadTri
%token tText2D tText3D tInterpolationScheme tTime tCombine
%token tBSpline tBezier tNurbs tNurbsOrder tNurbsKnots
%token tColor tColorTable tFor tIn tEndFor tIf tElseIf tElse tEndIf tExit tAbort
%token tField tReturn tCall tSlide tMacro tShow tHide tGetValue tGetStringValue tGetEnv
%token tGetString tGetNumber tUnique
%token tHomology tCohomology tBetti tExists tFileExists
%token tGMSH_MAJOR_VERSION tGMSH_MINOR_VERSION tGMSH_PATCH_VERSION
%token tGmshExecutableName tSetPartition
%token tNameToString tStringToName

%type <d> FExpr FExpr_Single
%type <v> VExpr VExpr_Single CircleOptions TransfiniteType
%type <i> NumericAffectation NumericIncrement BooleanOperator BooleanOption
%type <i> PhysicalId0 PhysicalId1 PhysicalId2 PhysicalId3
%type <i> TransfiniteArrangement RecombineAngle InSphereCenter
%type <u> ColorExpr
%type <c> StringExpr StringExprVar SendToFile HomologyCommand
%type <c> LP RP
%type <c> StringIndex String__Index
%type <l> RecursiveListOfStringExprVar
%type <l> FExpr_Multi ListOfDouble ListOfDoubleOrAll RecursiveListOfDouble
%type <l> RecursiveListOfListOfDouble Enumeration
%type <l> ListOfColor RecursiveListOfColor
%type <l> ListOfShapes Transform Extrude MultipleShape Boolean
%type <l> TransfiniteCorners PeriodicTransform
%type <s> Shape

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
%left    '<' tLESSOREQUAL  '>' tGREATEROREQUAL
%left    '+' '-'
%left    '*' '/' '%'
%right   '!' tPLUSPLUS tMINUSMINUS UNARYPREC
%right   '^'
%left    '(' ')' '[' ']' '.' '#'

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
      // FIXME: when changing to OpenCASCADE, get maxTags from GEO_Internals and
      // add that info in OCC_Internals - same in the other direction
      factory = $3;
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
  | '>' '>'
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
      int i = PrintListOfDouble($3, $5, tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free($3);
      List_Delete($5);
    }
  | tError '(' StringExprVar ',' RecursiveListOfDouble ')' tEND
    {
      char tmpstring[5000];
      int i = PrintListOfDouble($3, $5, tmpstring);
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
      int i = PrintListOfDouble($3, $5, tmpstring);
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
    tSTRING StringExprVar '{' Views '}' tEND
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
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
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

Affectation :

  // Variables

    tDefineConstant '[' DefineConstants ']' tEND
  | tUndefineConstant '[' UndefineConstants ']' tEND
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

  // lists of numbers with bracket notation
  | tSTRING '[' ']' NumericAffectation ListOfDouble tEND
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
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
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
  | StringIndex '[' ']' NumericAffectation ListOfDouble tEND
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
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
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
  | tSTRING '[' FExpr ']' NumericAffectation FExpr tEND
    {
      assignVariable($1, (int)$3, $5, $6);
      Free($1);
    }
  | StringIndex '[' FExpr ']' NumericAffectation FExpr tEND
    {
      assignVariable($1, (int)$3, $5, $6);
      Free($1);
    }
  | tSTRING '[' FExpr ']' NumericIncrement tEND
    {
      incrementVariable($1, $3, $5);
      Free($1);
    }
  | StringIndex '[' FExpr ']' NumericIncrement tEND
    {
      incrementVariable($1, $3, $5);
      Free($1);
    }
  | tSTRING LP '{' RecursiveListOfDouble '}' RP NumericAffectation ListOfDouble tEND
    {
      assignVariables($1, $4, $7, $8);
      Free($1);
      List_Delete($4);
      List_Delete($8);
    }
  | StringIndex LP '{' RecursiveListOfDouble '}' RP NumericAffectation ListOfDouble tEND
    {
      assignVariables($1, $4, $7, $8);
      Free($1);
      List_Delete($4);
      List_Delete($8);
    }

  // lists of numbers with parentheses notation

  | tSTRING '(' ')' NumericAffectation ListOfDouble tEND
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
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
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
  | StringIndex '(' ')' NumericAffectation ListOfDouble tEND
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
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
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
  | tSTRING '(' FExpr ')' NumericAffectation FExpr tEND
    {
      assignVariable($1, (int)$3, $5, $6);
      Free($1);
    }
  | StringIndex '(' FExpr ')' NumericAffectation FExpr tEND
    {
      assignVariable($1, (int)$3, $5, $6);
      Free($1);
    }
  | tSTRING '(' FExpr ')' NumericIncrement tEND
    {
      incrementVariable($1, $3, $5);
      Free($1);
    }
  | StringIndex '(' FExpr ')' NumericIncrement tEND
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

  // lists of strings with bracket notation

  | tSTRING '[' ']' tAFFECT tStr LP RP tEND
    {
      gmsh_yystringsymbols[$1] = std::vector<std::string>();
      Free($1);
    }

  | StringIndex '[' ']' tAFFECT tStr LP RP tEND
    {
      gmsh_yystringsymbols[$1] = std::vector<std::string>();
      Free($1);
    }

  | tSTRING '[' ']' tAFFECT tStr LP RecursiveListOfStringExprVar RP tEND
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

  | StringIndex '[' ']' tAFFECT tStr LP RecursiveListOfStringExprVar RP tEND
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

  | tSTRING '[' ']' tAFFECTPLUS tStr LP RecursiveListOfStringExprVar RP tEND
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

  | StringIndex '[' ']' tAFFECTPLUS tStr LP RecursiveListOfStringExprVar RP tEND
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

  // lists of strings with parentheses notation

  | tSTRING '(' ')' tAFFECT tStr LP RP tEND
    {
      gmsh_yystringsymbols[$1] = std::vector<std::string>();
      Free($1);
    }

  | StringIndex '(' ')' tAFFECT tStr LP RP tEND
    {
      gmsh_yystringsymbols[$1] = std::vector<std::string>();
      Free($1);
    }

  | tSTRING '(' ')' tAFFECT tStr LP RecursiveListOfStringExprVar RP tEND
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

  | StringIndex '(' ')' tAFFECT tStr LP RecursiveListOfStringExprVar RP tEND
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

  | tSTRING '(' ')' tAFFECTPLUS tStr LP RecursiveListOfStringExprVar RP tEND
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

  | StringIndex '(' ')' tAFFECTPLUS tStr LP RecursiveListOfStringExprVar RP tEND
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

  | tSTRING '.' tSTRING tAFFECT StringExpr tEND
    {
      std::string tmp($5);
      StringOption(GMSH_SET|GMSH_GUI, $1, 0, $3, tmp);
      Free($1); Free($3); Free($5);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING tAFFECT StringExpr tEND
    {
      std::string tmp($8);
      StringOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $6, tmp);
      Free($1); Free($6); Free($8);
    }

  // Option Numbers

  | tSTRING '.' tSTRING NumericAffectation FExpr tEND
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
  | tSTRING '[' FExpr ']' '.' tSTRING NumericAffectation FExpr tEND
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
  | tSTRING '.' tSTRING NumericIncrement tEND
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, 0, $3, d)){
	d += $4;
	NumberOption(GMSH_SET|GMSH_GUI, $1, 0, $3, d);
      }
      Free($1); Free($3);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING NumericIncrement tEND
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, (int)$3, $6, d)){
	d += $7;
	NumberOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $6, d);
      }
      Free($1); Free($6);
    }

  // Option Colors

  | tSTRING '.' tColor '.' tSTRING tAFFECT ColorExpr tEND
    {
      ColorOption(GMSH_SET|GMSH_GUI, $1, 0, $5, $7);
      Free($1); Free($5);
    }
  | tSTRING '[' FExpr ']' '.' tColor '.' tSTRING tAFFECT ColorExpr tEND
    {
      ColorOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $8, $10);
      Free($1); Free($8);
    }

  // ColorTable

  | tSTRING '.' tColorTable tAFFECT ListOfColor tEND
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
  | tSTRING '[' FExpr ']' '.' tColorTable tAFFECT ListOfColor tEND
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

  | tSTRING tField tAFFECT FExpr tEND
    {
#if defined(HAVE_MESH)
      if(!strcmp($1,"Background"))
	GModel::current()->getFields()->setBackgroundFieldId((int)$4);
      else if(!strcmp($1,"BoundaryLayer"))
	GModel::current()->getFields()->setBoundaryLayerFieldId((int)$4);
      else
	yymsg(0, "Unknown command %s Field", $1);
#endif
    }
  | tField '[' FExpr ']' tAFFECT tSTRING tEND
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)$3, $6))
	yymsg(0, "Cannot create field %i of type '%s'", (int)$3, $6);
#endif
      Free($6);
    }
  | tField '[' FExpr ']' '.' tSTRING  tAFFECT FExpr tEND
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
  | tField '[' FExpr ']' '.' tSTRING  tAFFECT StringExpr tEND
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
  | tField '[' FExpr ']' '.' tSTRING  tAFFECT '{' RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)$3);
      if(field){
	FieldOption *option = field->options[$6];
	if(option){
	  if (option->getType() == FIELD_OPTION_LIST) {
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
  | tField '[' FExpr ']' '.' tSTRING tEND
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

  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT FExpr tEND
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
  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT StringExpr tEND
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
    { floatOptions.clear(); charOptions.clear(); }
    FloatParameterOptions '}'
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
      Free($6);
    }
  | DefineConstants Comma String__Index '[' ']' tAFFECT '{' ListOfDouble
    { floatOptions.clear(); charOptions.clear(); }
    FloatParameterOptions '}'
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
      Free($8);
    }
  | DefineConstants Comma String__Index '(' ')' tAFFECT '{' ListOfDouble
    { floatOptions.clear(); charOptions.clear(); }
    FloatParameterOptions '}'
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
      Free($8);
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
    { floatOptions.clear(); charOptions.clear(); }
      CharParameterOptions '}'
    {
      std::string key($3), val($6);
      if(!gmsh_yysymbols.count(key)){
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
    }
  ;

FloatParameterOptions :
  | FloatParameterOptions FloatParameterOption
 ;

FloatParameterOption :
    ',' tSTRING ListOfDouble
    {
      std::string key($2);
      for(int i = 0; i < List_Nbr($3); i++){
        double v;
        List_Read($3, i, &v);
        floatOptions[key].push_back(v);
      }
      Free($2);
      List_Delete($3);
    }
  | ',' tSTRING '{' Enumeration '}'
    {
      std::string key($2);
      for(int i = 0; i < List_Nbr($4); i++){
        doubleXstring v;
        List_Read($4, i, &v);
        floatOptions[key].push_back(v.d);
        charOptions[key].push_back(v.s);
      }
      Free($2);
      for(int i = 0; i < List_Nbr($4); i++)
        Free(((doubleXstring*)List_Pointer($4, i))->s);
      List_Delete($4);
    }

  | ',' tSTRING StringExpr
    {
      std::string key($2);
      std::string val($3);
      charOptions[key].push_back(val);
      Free($2);
      Free($3);
    }
 ;

CharParameterOptions :
  | CharParameterOptions CharParameterOption
 ;

CharParameterOption :

    ',' tSTRING FExpr
    {
      std::string key($2);
      double val = $3;
      floatOptions[key].push_back(val);
      Free($2);
    }

  | ',' tSTRING StringExpr
    {
      std::string key($2);
      std::string val($3);
      charOptions[key].push_back(val);
      Free($2);
      Free($3);
    }

  | ',' tMacro StringExpr // Macro is already a reserved keyword
    {
      std::string key("Macro");
      std::string val($3);
      charOptions[key].push_back(val);
      Free($3);
    }

  | ',' tSTRING '{' RecursiveListOfStringExprVar '}'
    {
      std::string key($2);
      for(int i = 0; i < List_Nbr($4); i++){
        char *s;
        List_Read($4, i, &s);
        std::string val(s);
        Free(s);
        charOptions[key].push_back(val);
      }
      Free($2);
      List_Delete($4);
    }
 ;

//  S H A P E

PhysicalId0 :
    FExpr
    {
      $$ = (int)$1;
    }
  | StringExpr
    {
      $$ = GModel::current()->setPhysicalName
        (std::string($1), 0, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free($1);
    }
  | StringExpr ',' FExpr
    {
      $$ = GModel::current()->setPhysicalName(std::string($1), 0, $3);
      Free($1);
    }
;

PhysicalId1 :
    FExpr
    {
      $$ = (int)$1;
    }
  | StringExpr
    {
      $$ = GModel::current()->setPhysicalName
        (std::string($1), 1, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free($1);
    }
  | StringExpr ',' FExpr
    {
      $$ = GModel::current()->setPhysicalName(std::string($1), 1, $3);
      Free($1);
    }
;

PhysicalId2 :
    FExpr
    {
      $$ = (int)$1;
    }
  | StringExpr
    {
      $$ = GModel::current()->setPhysicalName
        (std::string($1), 2, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free($1);
    }
  | StringExpr ',' FExpr
    {
      $$ = GModel::current()->setPhysicalName(std::string($1), 2, $3);
      Free($1);
    }
;

PhysicalId3 :
    FExpr
    {
      $$ = (int)$1;
    }
  | StringExpr
    {
      $$ = GModel::current()->setPhysicalName
        (std::string($1), 3, ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free($1);
    }
  | StringExpr ',' FExpr
    {
      $$ = GModel::current()->setPhysicalName(std::string($1), 3, $3);
      Free($1);
    }
;

InSphereCenter :
    // nothing
    {
      $$ = -1;
    }
  | tIn tSphere '{' FExpr '}'
    {
      $$ = (int)$4;
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

Shape :
    tPoint '(' FExpr ')' tAFFECT VExpr tEND
    {
      int num = (int)$3;
      double x = CTX::instance()->geom.scalingFactor * $6[0];
      double y = CTX::instance()->geom.scalingFactor * $6[1];
      double z = CTX::instance()->geom.scalingFactor * $6[2];
      double lc = CTX::instance()->geom.scalingFactor * $6[3];
      if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addVertex(num, x, y, z, lc);
      }
      else{
        if(!myGmshSurface)
          GModel::current()->getGEOInternals()->addVertex(num, x, y, z, lc);
        else
          GModel::current()->getGEOInternals()->addVertex(num, x, y, myGmshSurface, lc);
      }
      AddToTemporaryBoundingBox(x, y, z);
      $$.Type = MSH_POINT;
      $$.Num = num;
    }
  | tLine '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addLine(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addLine(num, tags);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_LINE;
      $$.Num = num;
    }
  | tDegenerated tLine ListOfDouble tEND
    {
      for (int i = 0; i < List_Nbr($3); i++){
	double dnum;
	List_Read($3, i, &dnum);
	int num = (int) fabs(dnum);
	Curve *c = FindCurve(num);
	if (c){
	  c->degenerated = true;
	}
	else{
	  GEdge *ge = GModel::current()->getEdgeByTag(num);
	  if (!ge){
	    yymsg(0, "Curve %d does not exist", num);
	  }
	  else{
	    ge->setTooSmall(true);
	  }
	}
      }
    }
  | tSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Spline not available with OpenCASCADE factory");
      }
      else{
        GModel::current()->getGEOInternals()->addSpline(num, tags);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_SPLN;
      $$.Num = num;
    }
  | tCircle '(' FExpr ')' tAFFECT ListOfDouble CircleOptions tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(tags.size() == 3){
          GModel::current()->getOCCInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(param.size() >= 4 && param.size() <= 6){
          double r = param[3];
          double a1 = (param.size() >= 5) ? param[4] : 0.;
          double a2 = (param.size() >= 6) ? param[5] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addCircle
            (num, param[0], param[1], param[2], r, a1, a2);
        }
        else{
          yymsg(0, "Circle requires 3 points or 4 to 6 parameters");
        }
      }
      else{
        if(tags.size() == 3){
          GModel::current()->getGEOInternals()->addCircleArc
            (num, tags[0], tags[1], tags[2], $7[0], $7[1], $7[2]);
        }
        else{
          yymsg(0, "Circle requires 3 points");
        }
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_CIRC;
      $$.Num = num;
    }
  | tEllipse '(' FExpr ')' tAFFECT ListOfDouble CircleOptions tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(tags.size() == 3){
          GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(tags.size() == 4){
          GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[3]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() >= 6) ? param[5] : 0.;
          double a2 = (param.size() >= 7) ? param[6] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 3 or 4 points, or 5 to 7 parameters");
        }
      }
      else{
        if(tags.size() == 4){
          GModel::current()->getGEOInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2], tags[3], $7[0], $7[1], $7[2]);
        }
        else{
          yymsg(0, "Ellipse requires 4 points");
        }
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_ELLI;
      $$.Num = num;
    }
  | tBSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addBSpline(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addBSpline(num, tags);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_BSPLN;
      $$.Num = num;
    }
  | tBezier '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addBezier(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addBezier(num, tags);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_BEZIER;
      $$.Num = num;
    }
  | tNurbs  '(' FExpr ')' tAFFECT ListOfDouble tNurbsKnots ListOfDouble
      tNurbsOrder FExpr tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      std::vector<double> knots; ListOfDouble2Vector($8, knots);
      if(factory == "OpenCASCADE"){
        yymsg(0, "Nurbs not available yet with OpenCASCADE factory");
      }
      else{
        int order = knots.size() - tags.size() - 1;
        if(order != (int)$10)
          yymsg(1, "Incompatible Nurbs order: using %d", order);
        GModel::current()->getGEOInternals()->addNurbs(num, tags, knots);
      }
      List_Delete($6);
      List_Delete($8);
      $$.Type = MSH_SEGM_NURBS;
      $$.Num = num;
    }
  | tCompound tLine '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      GModel::current()->getGEOInternals()->addCompoundLine(num, tags);
      List_Delete($7);
      $$.Type = MSH_SEGM_COMPOUND;
      $$.Num = num;
    }
  | tWire '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addWire(num, tags, false);
      }
      else{
        yymsg(0, "Wire only available using OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_LOOP;
      $$.Num = num;
    }
  | tLine tSTRING '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addLineLoop(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addLineLoop(num, tags);
      }
      List_Delete($7);
      Free($2);
      $$.Type = MSH_SEGM_LOOP;
      $$.Num = num;
    }
  | tPlane tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addPlaneSurface(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addPlaneSurface(num, tags);
      }
      List_Delete($7);
      $$.Type = MSH_SURF_PLAN;
      $$.Num = num;
    }
  | tSurface '(' FExpr ')' tAFFECT ListOfDouble InSphereCenter tEND
    {
      int num = (int)$3;
      std::vector<int> wires; ListOfDouble2Vector($6, wires);
      if(factory == "OpenCASCADE"){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE face filling requires a single line loop");
        }
        else{
          GModel::current()->getOCCInternals()->addSurfaceFilling(num, wires[0]);
        }
      }
      else{
        GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, $7);
      }
      List_Delete($6);
      $$.Type = MSH_SURF_REGL;
      $$.Num = num;
    }
  | tRuled tSurface '(' FExpr ')' tAFFECT ListOfDouble InSphereCenter tEND
    {
      yymsg(1, "'Ruled Surface' command is deprecated: use 'Surface' instead");
      int num = (int)$4;
      std::vector<int> wires; ListOfDouble2Vector($7, wires);
      GModel::current()->getGEOInternals()->addSurfaceFilling(num, wires, $8);
      List_Delete($7);
      $$.Type =  MSH_SURF_REGL;
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
      if(param.size() == 4 || param.size() == 5){
        if(factory == "OpenCASCADE"){
          double alpha = (param.size() == 5) ? param[4] : 2.*M_PI;
          GModel::current()->getOCCInternals()->addSphere
            (num, param[0], param[1], param[2], param[3], alpha);
        }
        else{
          yymsg(0, "Sphere only available with OpenCASCADE factory");
        }
        $$.Type = MSH_VOLUME;
      }
      else if(tags.size() == 2){
        myGmshSurface = GModel::current()->getGEOInternals()->newGeometrySphere
          (num, tags[0], tags[1]);
      }
      else{
        yymsg(0, "Sphere requires 2 points or 4 or 5 parameters");
      }
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
  | tBlock '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 6){
          GModel::current()->getOCCInternals()->addBlock
            (num, param[0], param[1], param[2], param[3], param[4], param[5]);
        }
        else{
          yymsg(0, "Block requires 6 parameters");
        }
      }
      else{
        yymsg(0, "Block only available with OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tTorus '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 5 || param.size() == 6){
          double alpha = (param.size() == 6) ? param[5] : 2*M_PI;
          GModel::current()->getOCCInternals()->addTorus
            (num, param[0], param[1], param[2], param[3], param[4], alpha);
        }
        else{
          yymsg(0, "Torus requires 5 ou 6 parameters");
        }
      }
      else{
        yymsg(0, "Torus only available with OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tRectangle '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 6 || param.size() == 7){
          double r = (param.size() == 7) ? param[6] : 0.;
          GModel::current()->getOCCInternals()->addRectangle
            (num, param[0], param[1], param[2], param[3], param[4], param[5], r);
        }
        else{
          yymsg(0, "Rectangle requires 6 ou 7 parameters");
        }
      }
      else{
        yymsg(0, "Rectangle only available with OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_SURF_PLAN;
      $$.Num = num;
    }
  | tDisk '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 4 || param.size() == 5){
          double ry = (param.size() == 5) ? param[4] : param[3];
          GModel::current()->getOCCInternals()->addDisk
            (num, param[0], param[1], param[2], param[3], ry);
        }
        else{
          yymsg(0, "Disk requires 4 or 5 parameters");
        }
      }
      else{
        yymsg(0, "Disk only available with OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_SURF_PLAN;
      $$.Num = num;
    }
  | tCylinder '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 7 || param.size() == 8){
          double angle = (param.size() == 8) ? param[7] : 2*M_PI;
          GModel::current()->getOCCInternals()->addCylinder
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], angle);
        }
        else{
          yymsg(0, "Cylinder requires 7 or 8 parameters");
        }
      }
      else{
        yymsg(0, "Cylinder only available with OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tCone '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 8 || param.size() == 9){
          double alpha = (param.size() == 9) ? param[8] : 2*M_PI;
          GModel::current()->getOCCInternals()->addCone
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6], param[7], alpha);
        }
        else{
          yymsg(0, "Cone requires 8 or 9 parameters");
        }
      }
      else{
        yymsg(0, "Cone only available with OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tWedge '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(param.size() == 7){
          GModel::current()->getOCCInternals()->addWedge
            (num, param[0], param[1], param[2], param[3], param[4], param[5],
             param[6]);
        }
        else{
          yymsg(0, "Wedge requires 7 parameters");
        }
      }
      else{
        yymsg(0, "Wedge only available with OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tThickSolid '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<double> param; ListOfDouble2Vector($6, param);
      if(factory == "OpenCASCADE"){
        if(param.size() >= 2){
          int in = (int)param[0];
          double offset = param[1];
          std::vector<int> exclude;
          for(unsigned int i = 2; i < param.size(); i++)
            exclude.push_back(param[i]);
          GModel::current()->getOCCInternals()->addThickSolid
            (num, in, exclude, offset);
        }
        else{
          yymsg(0, "ThickSolid requires at least 2 parameters");
        }
      }
      else{
        yymsg(0, "ThickSolid only available with OpenCASCADE factory");
      }
      List_Delete($6);
    }
  | tCompound tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags);
      List_Delete($7);
      $$.Type = MSH_SURF_COMPOUND;
      $$.Num = num;
    }
  | tCompound tSurface '(' FExpr ')' tAFFECT ListOfDouble tSTRING
      '{' RecursiveListOfListOfDouble '}' tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      std::vector<int> bndTags[4];
      for(int i = 0; i < List_Nbr($10); i++){
        if(i < 4)
          ListOfDouble2Vector(*(List_T**)List_Pointer($10, i), bndTags[i]);
        else
          break;
      }
      GModel::current()->getGEOInternals()->addCompoundSurface(num, tags, bndTags);
      List_Delete($7);
      Free($8);
      for (int i = 0; i < List_Nbr($10); i++)
        List_Delete(*(List_T**)List_Pointer($10, i));
      List_Delete($10);
      $$.Type = MSH_SURF_COMPOUND;
      $$.Num = num;
    }
  | tSurface tSTRING '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      List_Delete($7);
      Free($2);
      $$.Type = MSH_SURF_LOOP;
      $$.Num = num;
    }
  | tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> tags; ListOfDouble2Vector($6, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tComplex tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      yymsg(1, "'Complex Volume' command is deprecated: use 'Volume' instead");
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addVolume(num, tags);
      }
      else{
        GModel::current()->getGEOInternals()->addVolume(num, tags);
      }
      List_Delete($7);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tThruSections '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      std::vector<int> wires, out[4]; ListOfDouble2Vector($6, wires);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addThruSections
          (num, wires, out, true, false);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tRuled tThruSections '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> wires, out[4]; ListOfDouble2Vector($7, wires);
      if(factory == "OpenCASCADE"){
        GModel::current()->getOCCInternals()->addThruSections
          (num, wires, out, true, true);
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete($7);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tCompound tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      std::vector<int> tags; ListOfDouble2Vector($7, tags);
      GModel::current()->getGEOInternals()->addCompoundVolume(num, tags);
      List_Delete($7);
      $$.Type = MSH_VOLUME_COMPOUND;
      $$.Num = num;
    }
  | tPhysical tPoint '(' PhysicalId0 ')' NumericAffectation ListOfDouble tEND
    {
      int num = (int)$4;
      int op = $6;
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_POINT);
      if(p && op == 0){
	yymsg(0, "Physical point %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical point %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt($7);
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr($7); i++){
          double d;
          List_Read($7, i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr($7); i++){
          double d;
          List_Read($7, i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalPoint(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical point %d", num);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_POINT;
      $$.Num = num;
    }
  | tPhysical tLine '(' PhysicalId1 ')' NumericAffectation ListOfDouble tEND
    {
      int num = (int)$4;
      int op = $6;
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_LINE);
      if(p && op == 0){
	yymsg(0, "Physical line %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical line %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt($7);
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr($7); i++){
          double d;
          List_Read($7, i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr($7); i++){
          double d;
          List_Read($7, i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalLine(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical line %d", num);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_LINE;
      $$.Num = num;
    }
  | tPhysical tSurface '(' PhysicalId2 ')' NumericAffectation ListOfDouble tEND
    {
      int num = (int)$4;
      int op = $6;
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE);
      if(p && op == 0){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical surface %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt($7);
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr($7); i++){
          double d;
          List_Read($7, i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr($7); i++){
          double d;
          List_Read($7, i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalSurface(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical surface %d", num);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_SURFACE;
      $$.Num = num;
    }
  | tPhysical tVolume '(' PhysicalId3 ')' NumericAffectation ListOfDouble tEND
    {
      int num = (int)$4;
      int op = $6;
      PhysicalGroup *p = FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME);
      if(p && op == 0){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else if(!p && op > 0){
	yymsg(0, "Physical volume %d does not exist", num);
      }
      else if(op == 0){
	List_T *temp = ListOfDouble2ListOfInt($7);
	p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      else if(op == 1){
        for(int i = 0; i < List_Nbr($7); i++){
          double d;
          List_Read($7, i, &d);
          int j = (int)d;
          List_Add(p->Entities, &j);
        }
      }
      else if(op == 2){
        for(int i = 0; i < List_Nbr($7); i++){
          double d;
          List_Read($7, i, &d);
          int j = (int)d;
          List_Suppress(p->Entities, &j, fcmp_int);
        }
        if(!List_Nbr(p->Entities)){
          DeletePhysicalVolume(num);
        }
      }
      else{
	yymsg(0, "Unsupported operation on physical volume %d", num);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_VOLUME;
      $$.Num = num;
    }
;

//  T R A N S F O R M

Transform :
    tTranslate VExpr '{' MultipleShape '}'
    {
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr($4); i++){
          List_Read($4, i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->translate(in, $2[0], $2[1], $2[2]);
      }
      else{
        TranslateShapes($2[0], $2[1], $2[2], $4);
      }
      $$ = $4;
    }
  | tRotate '{' VExpr ',' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr($10); i++){
          List_Read($10, i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->rotate(in, $5[0], $5[1], $5[2],
                                                     $3[0], $3[1], $3[2], $7);
      }
      else{
        RotateShapes($3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7, $10);
      }
      $$ = $10;
    }
  | tSymmetry  VExpr '{' MultipleShape '}'
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("TODO OCC Symmetry");
      }
      else{
        SymmetryShapes($2[0], $2[1], $2[2], $2[3], $4);
      }
      $$ = $4;
    }
  | tDilate '{' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("TODO OCC Dilate");
      }
      else{
        DilatShapes($3[0], $3[1], $3[2], $5, $5, $5, $8);
      }
      $$ = $8;
    }
  | tDilate '{' VExpr ',' VExpr '}' '{' MultipleShape '}'
    {
      if(factory == "OpenCASCADE"){
        Msg::Error("TODO OCC Dilate");
      }
      else{
        DilatShapes($3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $8);
      }
      $$ = $8;
    }
  | tSTRING '{' MultipleShape '}'
    {
      $$ = List_Create(3, 3, sizeof(Shape));
      if(!strcmp($1, "Duplicata")){
        if(factory == "OpenCASCADE"){
          std::vector<int> in[4], out[4];
          Shape TheShape;
          for(int i = 0; i < List_Nbr($3); i++){
            List_Read($3, i, &TheShape);
            int dim = TheShape.Type / 100 - 1;
            if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
          }
          GModel::current()->getOCCInternals()->copy(in, out);
          for(int dim = 0; dim < 4; dim++){
            TheShape.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            for(unsigned int i = 0; i < out[dim].size(); i++){
              TheShape.Num = out[dim][i];
              List_Add($$, &TheShape);
            }
          }
        }
        else{
          for(int i = 0; i < List_Nbr($3); i++){
            Shape TheShape;
            List_Read($3, i, &TheShape);
            CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
            List_Add($$, &TheShape);
          }
        }
      }
      else if(!strcmp($1, "Boundary") || !strcmp($1, "CombinedBoundary")){
        if(factory == "OpenCASCADE"){
          std::vector<int> in[4], out[4];
          Shape TheShape;
          for(int i = 0; i < List_Nbr($3); i++){
            List_Read($3, i, &TheShape);
            int dim = TheShape.Type / 100 - 1;
            if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
          }
          GModel::current()->getOCCInternals()->getBoundary
            (in, out, !strcmp($1, "CombinedBoundary") ? true : false);
          for(int dim = 0; dim < 4; dim++){
            TheShape.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            for(unsigned int i = 0; i < out[dim].size(); i++){
              TheShape.Num = out[dim][i];
              List_Add($$, &TheShape);
            }
          }
        }
        else{
          BoundaryShapes($3, $$, !strcmp($1, "CombinedBoundary") ? true : false);
        }
      }
      else{
        yymsg(0, "Unknown command on multiple shapes: '%s'", $1);
      }
      Free($1);
      List_Delete($3);
    }
  | tIntersect tLine '{' RecursiveListOfDouble '}' tSurface '{' FExpr '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        yymsg(0, "Intersect Line not available with OpenCASCADE");
      }
      else{
        IntersectCurvesWithSurface($4, (int)$8, $$);
      }
      List_Delete($4);
    }
  | tSplit tLine '(' FExpr ')' '{' RecursiveListOfDouble '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape*));
      if(factory == "OpenCASCADE"){
        yymsg(0, "Split Line not available with OpenCASCADE");
      }
      else{
        List_T *tmp = ListOfDouble2ListOfInt($7);
        SplitCurve((int)$4, tmp, $$);
        List_Delete(tmp);
      }
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
  | ListOfShapes tPoint '{' RecursiveListOfDouble '}' tEND
    {
      for(int i = 0; i < List_Nbr($4); i++){
	double d;
	List_Read($4, i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(std::abs(TheShape.Num));
	if(v){
	  TheShape.Type = MSH_POINT;
	  List_Add($$, &TheShape);
	}
	else{
	  GVertex *gv = GModel::current()->getVertexByTag(std::abs(TheShape.Num));
	  if(gv){
	    TheShape.Type = MSH_POINT_FROM_GMODEL;
	    List_Add($$, &TheShape);
	  }
	  else{
            if(factory == "OpenCASCADE"){
              TheShape.Type = MSH_POINT_FROM_GMODEL;
              List_Add($$, &TheShape);
            }
            else
              yymsg(1, "Unknown point %d", TheShape.Num);
          }
	}
      }
    }
  | ListOfShapes tLine '{' RecursiveListOfDouble '}' tEND
    {
      for(int i = 0; i < List_Nbr($4); i++){
	double d;
	List_Read($4, i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Curve *c = FindCurve(std::abs(TheShape.Num));
	if(c){
	  TheShape.Type = c->Typ;
	  List_Add($$, &TheShape);
	}
	else{
	  GEdge *ge = GModel::current()->getEdgeByTag(std::abs(TheShape.Num));
	  if(ge){
	    TheShape.Type = MSH_SEGM_FROM_GMODEL;
	    List_Add($$, &TheShape);
	  }
	  else{
            if(factory == "OpenCASCADE"){
              TheShape.Type = MSH_SEGM_FROM_GMODEL;
              List_Add($$, &TheShape);
            }
            else
              yymsg(1, "Unknown curve %d", TheShape.Num);
          }
	}
      }
    }
  | ListOfShapes tSurface '{' RecursiveListOfDouble '}' tEND
    {
      for(int i = 0; i < List_Nbr($4); i++){
	double d;
	List_Read($4, i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Surface *s = FindSurface(std::abs(TheShape.Num));
	if(s){
	  TheShape.Type = s->Typ;
	  List_Add($$, &TheShape);
	}
	else{
	  GFace *gf = GModel::current()->getFaceByTag(std::abs(TheShape.Num));
	  if(gf){
	    TheShape.Type = MSH_SURF_FROM_GMODEL;
	    List_Add($$, &TheShape);
	  }
	  else{
            if(factory == "OpenCASCADE"){
              TheShape.Type = MSH_SURF_FROM_GMODEL;
              List_Add($$, &TheShape);
            }
            else
              yymsg(1, "Unknown surface %d", TheShape.Num);
          }
	}
      }
    }
  | ListOfShapes tVolume '{' RecursiveListOfDouble '}' tEND
    {
      for(int i = 0; i < List_Nbr($4); i++){
	double d;
	List_Read($4, i, &d);
	Shape TheShape;
	TheShape.Num = (int)d;
	Volume *v = FindVolume(std::abs(TheShape.Num));
	if(v){
	  TheShape.Type = v->Typ;
	  List_Add($$, &TheShape);
	}
	else{
	  GRegion *gr = GModel::current()->getRegionByTag(std::abs(TheShape.Num));
	  if(gr){
	    TheShape.Type = MSH_VOLUME_FROM_GMODEL;
	    List_Add($$, &TheShape);
	  }
	  else{
            if(factory == "OpenCASCADE"){
              TheShape.Type = MSH_VOLUME_FROM_GMODEL;
              List_Add($$, &TheShape);
            }
            else
              yymsg(1, "Unknown volume %d", TheShape.Num);
          }
	}
      }
    }
;

//  L E V E L S E T

LevelSet :
    tLevelset tPlane '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr($7) == 4){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[4];
          for(int i = 0; i < 4; i++)
            List_Read($7, i, &d[i]);
          gLevelset *ls = new gLevelsetPlane(d[0], d[1], d[2], d[3], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      List_Delete($7);
#endif
    }
  | tLevelset tPoint '(' FExpr ')' tAFFECT '{' RecursiveListOfListOfDouble '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      int t = (int)$4;
      if(FindLevelSet(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	//Msg::Info("nb = %d \n",List_Nbr($8) );
	fullMatrix<double> centers(List_Nbr($8),3);
	for (int i = 0; i < List_Nbr($8); i++){
	  List_T *l = *(List_T**)List_Pointer($8, i);
	  for (int j = 0; j < List_Nbr(l); j++){
	    //Msg::Info("nb j = %d \n",List_Nbr(l) );
	    centers(i,j) = (double)(*(double*)List_Pointer(l, j));
	  }
	}
        gLevelset *ls = new gLevelsetPoints(centers, t);
        LevelSet *l = Create_LevelSet(ls->getTag(), ls);
        Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
      }
      for(int i = 0; i < List_Nbr($8); i++)
        List_Delete(*(List_T**)List_Pointer($8, i));
      List_Delete($8);
#endif
    }
  | tLevelset tPlane '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                               RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr($12) == 0){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt[3] = {$8[0], $8[1], $8[2]};
          double n[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetPlane(pt, n, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      List_Delete($12);
#endif
    }
  | tLevelset tPlane '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ',' VExpr ','
                                               RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr($14) == 0){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double pt1[3] = {$8[0], $8[1], $8[2]};
          double pt2[3] = {$10[0], $10[1], $10[2]};
          double pt3[3] = {$12[0], $12[1], $12[2]};
          gLevelset *ls = new gLevelsetPlane(pt1, pt2, pt3, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      List_Delete($14);
#endif
    }
  | tLevelset tSphere '(' FExpr ')' tAFFECT '{' VExpr ',' RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr($10) == 1){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read($10, 0, &d);
          gLevelset *ls = new gLevelsetSphere($8[0], $8[1], $8[2], d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      List_Delete($10);
#endif
    }
  | tLevelset tCylinder '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                                RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr($12) == 1){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read($12, 0, &d);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetGenCylinder(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(List_Nbr($12) == 2){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[2];
          for(int i = 0; i < 2; i++)
            List_Read($12, i, &d[i]);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(List_Nbr($12) == 3){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read($12, i, &d[i]);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetCylinder(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      List_Delete($12);
#endif
    }
  | tLevelset tCone '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                                RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr($12) == 1){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read($12, 0, &d);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetCone(pt, dir, d, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      List_Delete($12);
#endif
    }
  | tLevelset tEllipsoid '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                                RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr($12) == 3){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d[3];
          for(int i = 0; i < 3; i++)
            List_Read($12, i, &d[i]);
          double pt[3] = {$8[0], $8[1], $8[2]};
          double dir[3] = {$10[0], $10[1], $10[2]};
          gLevelset *ls = new gLevelsetEllipsoid(pt, dir, d[0], d[1], d[2], t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      List_Delete($12);
#endif
    }
  | tLevelset tQuadric '(' FExpr ')' tAFFECT '{' VExpr ',' VExpr ','
                                                RecursiveListOfDouble '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(List_Nbr($12) == 5){
        int t = (int)$4;
        if(FindLevelSet(t)){
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
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      List_Delete($12);
#endif
    }
  | tLevelset tSTRING '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp($2, "Union")){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr($7); i++) {
            double d; List_Read($7, i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Union %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetUnion(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp($2, "Intersection")){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr($7); i++) {
            double d; List_Read($7, i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Intersection %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetIntersection(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp($2, "Cut")){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr($7); i++) {
            double d; List_Read($7, i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Cut %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCut(vl, true);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp($2, "Crack")){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          std::vector<gLevelset *> vl;
          for(int i = 0; i < List_Nbr($7); i++) {
            double d; List_Read($7, i, &d);
            LevelSet *pl = FindLevelSet((int)d);
	    if(!pl) yymsg(0, "Levelset Crack %d : unknown levelset %d", t, (int)d);
            else vl.push_back(pl->ls);
          }
          gLevelset *ls = new gLevelsetCrack(vl);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else if(!strcmp($2, "Reverse")){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          double d;
          List_Read($7, 0, &d);
          LevelSet *pl = FindLevelSet((int)d);
          gLevelset *ls = NULL;
          if(!pl) yymsg(0, "Levelset Reverse %d : unknown levelset %d", t, (int)d);
          else ls = new gLevelsetReverse(pl->ls);
          LevelSet *l = Create_LevelSet(t, ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
#if defined(HAVE_POST)
      else if(!strcmp($2, "PostView")){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          if(List_Nbr($7) > 0){
            double d; List_Read($7, 0, &d);
            gLevelset *ls = new gLevelsetPostView((int)d, t);
            LevelSet *l = Create_LevelSet(ls->getTag(), ls);
            Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
          }
        }
      }
#endif
      else
        yymsg(0, "Wrong levelset definition (%d)", $4);
      Free($2);
      List_Delete($7);
#endif
    }
  | tLevelset tSTRING '(' FExpr ')' tAFFECT tBIGSTR tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp($2, "MathEval")){
        int t = (int)$4;
        if(FindLevelSet(t)){
	  yymsg(0, "Levelset %d already exists", t);
        }
        else {
          gLevelset *ls = new gLevelsetMathEval($7, t);
          LevelSet *l = Create_LevelSet(ls->getTag(), ls);
          Tree_Add(GModel::current()->getGEOInternals()->LevelSets, &l);
        }
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free($2); Free($7);
#endif
    }
  | tLevelset tSTRING '{' FExpr '}' tEND
    {
#if defined(HAVE_DINTEGRATION)
      if(!strcmp($2, "CutMesh")){
        int t = (int)$4;
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, false);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp($2, "CutMeshTri")){
        int t = (int)$4;
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, true, true);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else if(!strcmp($2, "SplitMesh")){
        int t = (int)$4;
        GModel *GM = GModel::current();
        if(FindLevelSet(t)){
          GM->buildCutGModel(FindLevelSet(t)->ls, false, true);
          GM->setVisibility(0);
        }
        else
          yymsg(0, "Unknown levelset (%d)", t);
      }
      else
        yymsg(0, "Wrong levelset definition");
      Free($2);
#endif
    }
  ;

//  D E L E T E

Delete :
    tDelete '{' ListOfShapes '}'
    {
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr($3); i++){
          List_Read($3, i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->remove(in);
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          Shape TheShape;
          List_Read($3, i, &TheShape);
          DeleteShape(TheShape.Type, TheShape.Num);
        }
      }
      List_Delete($3);
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
      if(!strcmp($2, "Meshes") || !strcmp($2, "All")){
        ClearProject();
      }
      else if(!strcmp($2, "Model")){
	GModel::current()->destroy(true); // destroy, but keep name/filename
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp($2, "Physicals")){
	GModel::current()->getGEOInternals()->resetPhysicalGroups();
	GModel::current()->deletePhysicalGroups();
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
;

//  C O L O R I F Y

Colorify :
    tColor ColorExpr '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($4); i++){
	Shape TheShape;
	List_Read($4, i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, $2, false);
      }
      List_Delete($4);
    }
  | tRecursive tColor ColorExpr '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($5); i++){
	Shape TheShape;
	List_Read($5, i, &TheShape);
	ColorShape(TheShape.Type, TheShape.Num, $3, true);
      }
      List_Delete($5);
    }
;

//  S E T P A R T I T I O N

SetPartition :
    tSetPartition FExpr '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($4); i++){
	Shape TheShape;
	List_Read($4, i, &TheShape);
	SetPartition(TheShape.Type, TheShape.Num, $2);
      }
      List_Delete($4);
    }
;

//  V I S I B I L I T Y

Visibility :
    tShow tBIGSTR tEND
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape($2, i, 1, false);
      Free($2);
    }
  | tHide tBIGSTR tEND
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape($2, i, 0, false);
      Free($2);
    }
  | tShow '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($3); i++){
	Shape TheShape;
	List_Read($3, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, false);
      }
      List_Delete($3);
    }
  | tRecursive tShow '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($4); i++){
	Shape TheShape;
	List_Read($4, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1, true);
      }
      List_Delete($4);
    }
  | tHide '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($3); i++){
	Shape TheShape;
	List_Read($3, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, false);
      }
      List_Delete($3);
    }
  | tRecursive tHide '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($4); i++){
	Shape TheShape;
	List_Read($4, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0, true);
      }
      List_Delete($4);
    }
;

//  C O M M A N D

Command :
    tSTRING StringExpr tEND
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
	// make sure we have the latest data from GEO_Internals in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, $2);
	CreateOutputFile(tmp, CTX::instance()->print.fileFormat);
      }
      else if(!strcmp($1, "Save")){
	GModel::current()->importGEOInternals();
        std::string tmp = FixRelativePath(gmsh_yyname, $2);
	CreateOutputFile(tmp, CTX::instance()->mesh.fileFormat);
      }
      else if(!strcmp($1, "Merge") || !strcmp($1, "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
        // sync model with new DB here, so that if we e.g. import a STEP file,
        // we have the correct entity tags and the numberings don't clash
	GModel::current()->importGEOInternals();
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
  | tSTRING tSTRING '[' FExpr ']' StringExprVar tEND
    {
#if defined(HAVE_POST)
      if(!strcmp($1, "Save") && !strcmp($2, "View")){
	int index = (int)$4;
	if(index >= 0 && index < (int)PView::list.size()){
          std::string tmp = FixRelativePath(gmsh_yyname, $6);
	  PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", $1);
#endif
      Free($1); Free($2); Free($6);
    }
  | tSTRING tSTRING tSTRING '[' FExpr ']' tEND
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp($1, "Background") && !strcmp($2, "Mesh")  && !strcmp($3, "View")){
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
  | tSTRING FExpr tEND
    {
      if(!strcmp($1, "Sleep")){
	SleepInSeconds($2);
      }
      else if(!strcmp($1, "Remesh")){
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp($1, "Mesh")){
	int lock = CTX::instance()->lock;
	CTX::instance()->lock = 0;
	GModel::current()->importGEOInternals();
	GModel::current()->mesh((int)$2);
	CTX::instance()->lock = lock;
      }
      else if(!strcmp($1, "SetOrder")){
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), $2, CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else if(!strcmp($1, "PartitionMesh")){
        GModel::current()->partitionMesh($2);
      }
      else
	yymsg(0, "Unknown command '%s'", $1);
      Free($1);
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
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp($2, "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp($2, "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp($2, "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp($2, "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp($2, "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp($2, "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp($2, "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
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
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
      GModel::current()->importOCCInternals();
    }
   | tNewModel tEND
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    }
   | tBoundingBox tEND
    {
      CTX::instance()->forcedBBox = 0;
      GModel::current()->importGEOInternals();
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
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    }
   | tCreateTopology tEND
    {
      GModel::current()->createTopologyFromMesh();
    }
   | tCreateTopologyNoHoles tEND
    {
      GModel::current()->createTopologyFromMesh(1);
    }
   | tRefineMesh tEND
    {
      GModel::current()->importGEOInternals();
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
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
        yyerror("Need at least one adaptation technique");
      }
      else{
        std::vector<simpleFunction<double>*> f;
        for(int i = 0; i < List_Nbr($6); i++){
          double d;
          List_Read($6, i, &d);
          LevelSet *l = FindLevelSet((int)d);
          if(l) f.push_back(l->ls);
          else yymsg(0, "Unknown Levelset %d", (int)d);
        }
        if(technique.size() != f.size()){
          yyerror("Number of techniques != number of levelsets");
        }
        else{
          if(List_Nbr($9) != (int)f.size()){
            yyerror("Number of parameters != number of levelsets");
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
            GModel::current()->importGEOInternals();
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
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if($3 > $5)
	skip_until("For", "EndFor");
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
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(($7 > 0. && $3 > $5) || ($7 < 0. && $3 < $5))
	skip_until("For", "EndFor");
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
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if($5 > $7)
	skip_until("For", "EndFor");
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
      gmshgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(($9 > 0. && $5 > $7) || ($9 < 0. && $5 < $7))
	skip_until("For", "EndFor");
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
	  gmshsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
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
      skip_until(NULL, "Return");
      Free($2);
    }
  | tMacro StringExpr
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string($2), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", $2);
      skip_until(NULL, "Return");
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
	yymsg(0, "Unknown function %s", $2);
      Free($2);
    }
  | tCall StringExpr tEND
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string($2), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", $2);
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
        skip_until_test("If", "EndIf", "ElseIf", 4, &type_until2);
        if(!type_until2) ImbricatedTest--; // EndIf reached
      }
    }
  | tElseIf '(' FExpr ')'
    {
      if(ImbricatedTest > 0){
        if (statusImbricatedTests[ImbricatedTest]){
          // Last test (If or ElseIf) was true, thus go after EndIf (out of If EndIf)
          skip_until("If", "EndIf");
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
            skip_until_test("If", "EndIf", "ElseIf", 4, &type_until2);
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
          skip_until("If", "EndIf");
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
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4], out[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr($4); i++){
          List_Read($4, i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->extrude(-1, in, $2[0], $2[1], $2[2], out);
        for(int dim = 0; dim < 4; dim++){
          for(unsigned int i = 0; i < out[dim].size(); i++){
            Shape s;
            s.Num = out[dim][i];
            s.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            List_Add($$, &s);
          }
        }
      }
      else{
        ExtrudeShapes(TRANSLATE, $4,
                      $2[0], $2[1], $2[2], 0., 0., 0., 0., 0., 0., 0.,
                      NULL, $$);
      }
      List_Delete($4);
    }
  | tExtrude '{' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4], out[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr($10); i++){
          List_Read($10, i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->revolve(-1, in, $5[0], $5[1], $5[2],
                                                      $3[0], $3[1], $3[2], $7, out);
        for(int dim = 0; dim < 4; dim++){
          for(unsigned int i = 0; i < out[dim].size(); i++){
            Shape s;
            s.Num = out[dim][i];
            s.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            List_Add($$, &s);
          }
        }
      }
      else{
        ExtrudeShapes(ROTATE, $10,
                      0., 0., 0., $3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7,
                      NULL, $$);
      }
      List_Delete($10);
    }
  | tExtrude '{' VExpr ',' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, $12,
		    $3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7[0], $7[1], $7[2], $9,
		    NULL, $$);
      List_Delete($12);
    }
  | tExtrude VExpr '{' ListOfShapes
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                       ExtrudeParameters '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, $4,
		    $2[0], $2[1], $2[2], 0., 0., 0., 0., 0., 0., 0.,
		    &extr, $$);
      List_Delete($4);
    }
  | tExtrude '{' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                                                   ExtrudeParameters '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, $10,
		    0., 0., 0., $3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7,
		    &extr, $$);
      List_Delete($10);
    }
  | tExtrude '{' VExpr ',' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                                                             ExtrudeParameters '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, $12,
		    $3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7[0], $7[1], $7[2], $9,
		    &extr, $$);
      List_Delete($12);
    }
  | tExtrude '{' ListOfShapes
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                       ExtrudeParameters '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, $3, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, $$);
      List_Delete($3);
    }
  | tExtrude '{' ListOfShapes '}' tUsing tWire '{' FExpr '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> in[4], out[4];
        Shape TheShape;
        for(int i = 0; i < List_Nbr($3); i++){
          List_Read($3, i, &TheShape);
          int dim = TheShape.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) in[dim].push_back(TheShape.Num);
        }
        GModel::current()->getOCCInternals()->addPipe(-1, in, (int)$8, out);
        for(int dim = 0; dim < 4; dim++){
          TheShape.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
            (dim == 2) ? MSH_SURF_FROM_GMODEL :
            (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
          for(unsigned int i = 0; i < out[dim].size(); i++){
            TheShape.Num = out[dim][i];
            List_Add($$, &TheShape);
          }
        }
      }
      else{
        yymsg(0, "Pipe only available with OpenCASCADE factory");
      }
      List_Delete($3);
    }
  | tThruSections ListOfDouble
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> wires, out[4]; ListOfDouble2Vector($2, wires);
        GModel::current()->getOCCInternals()->addThruSections(-1, wires, out,
                                                              false, false);
        for(unsigned int i = 0; i < out[2].size(); i++){
          Shape s;
          s.Type = MSH_SURF_FROM_GMODEL;
          s.Num = out[2][i];
          List_Add($$, &s);
        }
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete($2);
    }
  | tRuled tThruSections ListOfDouble
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> wires, out[4]; ListOfDouble2Vector($3, wires);
        GModel::current()->getOCCInternals()->addThruSections(-1, wires, out,
                                                              false, true);
        for(unsigned int i = 0; i < out[2].size(); i++){
          Shape s;
          s.Type = MSH_SURF_REGL;
          s.Num = out[2][i];
          List_Add($$, &s);
        }
      }
      else{
        yymsg(0, "ThruSections only available with OpenCASCADE factory");
      }
      List_Delete($3);
    }
  | tFillet '{' RecursiveListOfDouble '}' '{' RecursiveListOfDouble '}' '{' FExpr '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        double radius = $9;
        std::vector<int> regions, edges, out[4];
        ListOfDouble2Vector($3, regions); ListOfDouble2Vector($6, edges);
        GModel::current()->getOCCInternals()->fillet(regions, edges, radius, out);
        Shape TheShape;
        for(int dim = 0; dim < 4; dim++){
          TheShape.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
            (dim == 2) ? MSH_SURF_FROM_GMODEL :
            (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
          for(unsigned int i = 0; i < out[dim].size(); i++){
            TheShape.Num = out[dim][i];
            List_Add($$, &TheShape);
          }
        }
      }
      else{
        yymsg(0, "Fillet only available with OpenCASCADE factory");
      }
      List_Delete($3);
      List_Delete($6);
    }
  // Deprecated extrude commands (for backward compatibility)
  | tExtrude tPoint '{' FExpr ',' VExpr '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)$4,
		   $6[0], $6[1], $6[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, $$);
    }
  | tExtrude tLine '{' FExpr ',' VExpr '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)$4,
		   $6[0], $6[1], $6[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, $$);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)$4,
		   $6[0], $6[1], $6[2], 0., 0., 0., 0., 0., 0., 0.,
		   NULL, $$);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'  tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)$4,
		   0., 0., 0., $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
		   NULL, $$);
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)$4,
		   0., 0., 0., $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
		   NULL, $$);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)$4,
		   0., 0., 0., $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
		   NULL, $$);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr'}'  tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)$4,
		   $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
		   NULL, $$);
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)$4,
		   $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
		   NULL, $$);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)$4,
		   $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
		   NULL, $$);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                    '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_POINT, (int)$4,
		   $6[0], $6[1], $6[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, $$);
    }
  | tExtrude tLine '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SEGM_LINE, (int)$4,
		   $6[0], $6[1], $6[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, $$);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                      '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE, MSH_SURF_PLAN, (int)$4,
		   $6[0], $6[1], $6[2], 0., 0., 0., 0., 0., 0., 0.,
		   &extr, $$);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                    '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_POINT, (int)$4,
		   0., 0., 0., $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
		   &extr, $$);
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SEGM_LINE, (int)$4,
		   0., 0., 0., $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
		   &extr, $$);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                      '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(ROTATE, MSH_SURF_PLAN, (int)$4,
		   0., 0., 0., $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
		   &extr, $$);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr'}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                    '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_POINT, (int)$4,
		   $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
		   &extr, $$);
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SEGM_LINE, (int)$4,
		   $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
		   &extr, $$);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    }
                      '{' ExtrudeParameters '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShape(TRANSLATE_ROTATE, MSH_SURF_PLAN, (int)$4,
		   $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
		   &extr, $$);
    }
  // End of deprecated Extrude commands
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
  | tLayers '{' ListOfDouble ',' ListOfDouble ',' ListOfDouble '}' tEND
    {
      yymsg(1, "Explicit region numbers in layers are deprecated");
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr($3);
      if(List_Nbr($3) == List_Nbr($5) && List_Nbr($3) == List_Nbr($7)){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr($3); i++){
	  double d;
	  List_Read($3, i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read($7, i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else
	yymsg(0, "Wrong layer definition {%d, %d, %d}", List_Nbr($3),
	      List_Nbr($5), List_Nbr($7));
      List_Delete($3);
      List_Delete($5);
      List_Delete($7);
    }
  //Added by Trevor Strickler 07/07/2013
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
  | tQuadTriSngl tEND
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
  | tQuadTriSngl tRecombLaterals tEND
    {
      yymsg(0, "Keyword 'QuadTriSngl' deprecated. Use 'QuadTriNoNewVerts' instead.");
    }
  | tQuadTriDbl tEND
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
    }
  | tQuadTriDbl tRecombLaterals tEND
    {
      yymsg(0, "Method 'QuadTriDbl' deprecated. Use 'QuadTriAddVerts' instead, "
            "which has no requirement for the number of extrusion layers and meshes "
            "with body-centered vertices.");
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
      int num = (int)$3;
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	extr.mesh.Holes[num].first = $8;
	extr.mesh.Holes[num].second.clear();
	for(int i = 0; i < List_Nbr($6); i++){
	  double d;
	  List_Read($6, i, &d);
	  extr.mesh.Holes[num].second.push_back((int)d);
	}
      }
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
  | tDelete FExpr tEND { $$ = $2; }

Boolean :
    BooleanOperator '{' ListOfShapes BooleanOption '}'
                    '{' ListOfShapes BooleanOption '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr($3); i++){
          Shape s; List_Read($3, i, &s); int dim = s.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) shape[dim].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr($7); i++){
          Shape s; List_Read($7, i, &s);int dim = s.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) tool[dim].push_back(s.Num);
        }
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->applyBooleanOperator
          (-1, (OCC_Internals::BooleanOperator)$1, shape, tool, out, $4, $8);
        for(int dim = 0; dim < 4; dim++){
          for(unsigned int i = 0; i < out[dim].size(); i++){
            Shape s;
            s.Num = out[dim][i];
            s.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
              (dim == 2) ? MSH_SURF_FROM_GMODEL :
              (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
            List_Add($$, &s);
          }
        }
      }
      else{
        yymsg(0, "Boolean operators only available with OpenCASCADE factory");
      }
      List_Delete($3);
      List_Delete($7);
    }
  | tShapeFromFile '(' StringExprVar ')'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      if(factory == "OpenCASCADE"){
        std::vector<int> out[4];
        std::string tmp = FixRelativePath(gmsh_yyname, $3);
        GModel::current()->getOCCInternals()->importShapes(tmp, true, out);
        Shape s;
        for(int dim = 0; dim < 4; dim++){
          s.Type = (dim == 3) ? MSH_VOLUME_FROM_GMODEL :
            (dim == 2) ? MSH_SURF_FROM_GMODEL :
            (dim == 1) ? MSH_SEGM_FROM_GMODEL : MSH_POINT_FROM_GMODEL;
          for(unsigned int i = 0; i < out[dim].size(); i++){
            s.Num = out[dim][i];
            List_Add($$, &s);
          }
        }
      }
      else{
        yymsg(0, "ShapeFromFile only available with OpenCASCADE factory");
      }
      Free($3);
    }
;

BooleanShape :
    BooleanOperator '(' FExpr ')' tAFFECT '{' ListOfShapes BooleanOption '}'
                                          '{' ListOfShapes BooleanOption '}' tEND
    {
      if(factory == "OpenCASCADE"){
        std::vector<int> shape[4], tool[4];
        for(int i = 0; i < List_Nbr($7); i++){
          Shape s; List_Read($7, i, &s); int dim = s.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) shape[dim].push_back(s.Num);
        }
        for(int i = 0; i < List_Nbr($11); i++){
          Shape s; List_Read($11, i, &s);int dim = s.Type / 100 - 1;
          if(dim >= 0 && dim <= 3) tool[dim].push_back(s.Num);
        }
        std::vector<int> out[4];
        GModel::current()->getOCCInternals()->applyBooleanOperator
          ((int)$3, (OCC_Internals::BooleanOperator)$1, shape, tool, out, $8, $12);
      }
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
    tCharacteristic tLength ListOfDouble tAFFECT FExpr tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	Vertex *v = FindPoint((int)d);
	if(v){
	  v->lc = $5;
        }
	else{
	  GVertex *gv = GModel::current()->getVertexByTag((int)d);
	  if(gv)
	    gv->setPrescribedMeshSizeAtVertex($5);
	}
      }
      List_Delete($3);
    }
  | tTransfinite tLine ListOfDoubleOrAll tAFFECT FExpr TransfiniteType tEND
    {
      int type = (int)$6[0];
      double coef = fabs($6[1]);
      if(!$3){
        List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Curve *c;
            List_Read(tmp, i, &c);
            c->Method = MESH_TRANSFINITE;
            c->nbPointsTransfinite = ($5 > 2) ? (int)$5 : 2;
            c->typeTransfinite = type;
            c->coeffTransfinite = coef;
          }
        }
        else{
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.method = MESH_TRANSFINITE;
            (*it)->meshAttributes.nbPointsTransfinite = ($5 > 2) ? (int)$5 : 2;
            (*it)->meshAttributes.typeTransfinite = type;
            (*it)->meshAttributes.coeffTransfinite = coef;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          int j = (int)fabs(d);
          for(int sig = -1; sig <= 1; sig += 2){
            Curve *c = FindCurve(sig * j);
            if(c){
              c->Method = MESH_TRANSFINITE;
              c->nbPointsTransfinite = ($5 > 2) ? (int)$5 : 2;
              c->typeTransfinite = type * gmsh_sign(d);
              c->coeffTransfinite = coef;
            }
            else{
              GEdge *ge = GModel::current()->getEdgeByTag(sig * j);
              if(ge){
                ge->meshAttributes.method = MESH_TRANSFINITE;
                ge->meshAttributes.nbPointsTransfinite = ($5 > 2) ? (int)$5 : 2;
                ge->meshAttributes.typeTransfinite = type * gmsh_sign(d);
                ge->meshAttributes.coeffTransfinite = coef;
              }
              else if(sig > 0)
                yymsg(0, "Unknown line %d", j);
            }
          }
        }
        List_Delete($3);
      }
    }
  | tTransfinite tSurface ListOfDoubleOrAll TransfiniteCorners TransfiniteArrangement tEND
    {
      int k = List_Nbr($4);
      if(k != 0 && k != 3 && k != 4){
        yymsg(0, "Wrong definition of Transfinite Surface: 0, 3 or 4 points needed");
      }
      else{
        if(!$3){
          List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
          if(List_Nbr(tmp)){
            for(int i = 0; i < List_Nbr(tmp); i++){
              Surface *s;
              List_Read(tmp, i, &s);
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = $5;
              List_Reset(s->TrsfPoints);
            }
          }
          else{
            for(GModel::fiter it = GModel::current()->firstFace();
                it != GModel::current()->lastFace(); it++){
              (*it)->meshAttributes.method = MESH_TRANSFINITE;
              (*it)->meshAttributes.transfiniteArrangement = $5;
            }
          }
          List_Delete(tmp);
        }
        else{
          for(int i = 0; i < List_Nbr($3); i++){
            double d;
            List_Read($3, i, &d);
            Surface *s = FindSurface((int)d);
            if(s){
              s->Method = MESH_TRANSFINITE;
              s->Recombine_Dir = $5;
              List_Reset(s->TrsfPoints);
              for(int j = 0; j < k; j++){
                double p;
                List_Read($4, j, &p);
                Vertex *v = FindPoint((int)fabs(p));
                if(v)
                  List_Add(s->TrsfPoints, &v);
                else
                  yymsg(0, "Unknown point %d", (int)fabs(p));
              }
            }
            else{
              GFace *gf = GModel::current()->getFaceByTag((int)d);
              if(gf){
                gf->meshAttributes.method = MESH_TRANSFINITE;
                gf->meshAttributes.transfiniteArrangement = $5;
                for(int j = 0; j < k; j++){
                  double p;
                  List_Read($4, j, &p);
                  GVertex *gv = GModel::current()->getVertexByTag((int)fabs(p));
                  if(gv)
                    gf->meshAttributes.corners.push_back(gv);
                  else
                    yymsg(0, "Unknown point %d", (int)fabs(p));
                }
              }
              else
                yymsg(0, "Unknown surface %d", (int)d);
            }
          }
          List_Delete($3);
        }
      }
      List_Delete($4);
    }
  | tElliptic tSurface '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      yymsg(1, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete($7);
    }
  | tTransfinite tVolume ListOfDoubleOrAll TransfiniteCorners tEND
    {
      int k = List_Nbr($4);
      if(k != 0 && k != 6 && k != 8){
        yymsg(0, "Wrong definition of Transfinite Volume: "
              "%d points instead of 6 or 8", k);
      }
      else{
        if(!$3){
          List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
          if(List_Nbr(tmp)){
            for(int i = 0; i < List_Nbr(tmp); i++){
              Volume *v;
              List_Read(tmp, i, &v);
              v->Method = MESH_TRANSFINITE;
              List_Reset(v->TrsfPoints);
            }
          }
          else{
            for(GModel::riter it = GModel::current()->firstRegion();
                it != GModel::current()->lastRegion(); it++){
              (*it)->meshAttributes.method = MESH_TRANSFINITE;
            }
          }
          List_Delete(tmp);
        }
        else{
          for(int i = 0; i < List_Nbr($3); i++){
            double d;
            List_Read($3, i, &d);
            Volume *v = FindVolume((int)d);
            if(v){
              v->Method = MESH_TRANSFINITE;
              List_Reset(v->TrsfPoints);
              for(int i = 0; i < k; i++){
                double p;
                List_Read($4, i, &p);
                Vertex *vert = FindPoint((int)fabs(p));
                if(vert)
                  List_Add(v->TrsfPoints, &vert);
                else
                  yymsg(0, "Unknown point %d", (int)fabs(p));
              }
            }
            else{
              GRegion *gr = GModel::current()->getRegionByTag((int)d);
              if(gr){
                gr->meshAttributes.method = MESH_TRANSFINITE;
                for(int i = 0; i < k; i++){
                  double p;
                  List_Read($4, i, &p);
                  GVertex *gv = GModel::current()->getVertexByTag((int)fabs(p));
                  if(gv)
                    gr->meshAttributes.corners.push_back(gv);
                  else
                    yymsg(0, "Unknown point %d", (int)fabs(p));
                }
              }
              else
                yymsg(0, "Unknown volume %d", (int)d);
            }
          }
          List_Delete($3);
        }
      }
      List_Delete($4);
    }
  | tTransfQuadTri ListOfDoubleOrAll tEND
    {
      if(!$2){
  	  List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Volume *v;
            List_Read(tmp, i, &v);
            v->QuadTri = TRANSFINITE_QUADTRI_1;
          }
        }
        else{
          for(GModel::riter it = GModel::current()->firstRegion();
              it != GModel::current()->lastRegion(); it++)
            (*it)->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr($2); i++){
          double d;
          List_Read($2, i, &d);
          Volume *v = FindVolume((int)d);
          if(v)
            v->QuadTri = TRANSFINITE_QUADTRI_1;
          else{
            GRegion *gr = GModel::current()->getRegionByTag((int)d);
            if(gr)
              gr->meshAttributes.QuadTri = TRANSFINITE_QUADTRI_1;
            else
              yymsg(1, "Unknown volume %d", (int)d);
          }
        }
        List_Delete($2);
      }
    }
  | tMeshAlgorithm tSurface '{' RecursiveListOfDouble '}' tAFFECT FExpr tEND
    {
      for(int i = 0; i < List_Nbr($4); i++){
	double d;
	List_Read($4, i, &d);
	CTX::instance()->mesh.algo2d_per_face[(int)d] = (int)$7;
      }
    }
  | tRecombine tSurface ListOfDoubleOrAll RecombineAngle tEND
    {
      if(!$3){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Surface *s;
            List_Read(tmp, i, &s);
            s->Recombine = 1;
            s->RecombineAngle = $4;
          }
        }
        else{
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.recombine = 1;
            (*it)->meshAttributes.recombineAngle = $4;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          Surface *s = FindSurface((int)d);
          if(s){
            s->Recombine = 1;
            s->RecombineAngle = $4;
          }
          else{
            GFace *gf = GModel::current()->getFaceByTag((int)d);
            if(gf){
              gf->meshAttributes.recombine = 1;
              gf->meshAttributes.recombineAngle = $4;
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete($3);
      }
    }
  | tRecombine tVolume ListOfDoubleOrAll  tEND
    {
      if(!$3){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Volumes);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Volume *v;
            List_Read(tmp, i, &v);
            v->Recombine3D = 1;
          }
        }
        else{
          for(GModel::riter it = GModel::current()->firstRegion();
              it != GModel::current()->lastRegion(); it++){
            (*it)->meshAttributes.recombine3D = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          Volume *v = FindVolume((int)d);
          if(v){
            v->Recombine3D = 1;
          }
          else{
            GRegion *gr = GModel::current()->getRegionByTag((int)d);
            if(gr){
              gr->meshAttributes.recombine3D = 1;
            }
            else
              yymsg(1, "Unknown volume %d", (int)d);
          }
        }
        List_Delete($3);
      }
    }
  | tSmoother tSurface ListOfDouble tAFFECT FExpr tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
        double d;
        List_Read($3, i, &d);
        int j = (int)d;
        Surface *s = FindSurface(j);
        if(s){
          s->TransfiniteSmoothing = (int)$5;
        }
        else{
          GFace *gf = GModel::current()->getFaceByTag(j);
          if(gf)
            gf->meshAttributes.transfiniteSmoothing = (int)$5;
          else
            yymsg(1, "Unknown surface %d", (int)$5);
        }
      }
      List_Delete($3);
    }
  | tPeriodic tLine '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' PeriodicTransform tEND
    {
      if (List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master lines (%d) different from number of "
              "slaves (%d) ", List_Nbr($8), List_Nbr($4));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr($10) != 0) {
          if (List_Nbr($10) < 12){
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
      if (List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master faces (%d) different from number of "
              "slaves (%d) ", List_Nbr($8), List_Nbr($4));
      }
      else{
        if (List_Nbr($10) < 12){
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
  | tPeriodic tLine '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' tRotate '{' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      if (List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master edges (%d) different from number of "
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
      if (List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master faces (%d) different from number of "
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
  | tPeriodic tLine '{' RecursiveListOfDouble '}' tAFFECT
    '{' RecursiveListOfDouble '}' tTranslate VExpr tEND
    {
      if (List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master edges (%d) different from number of "
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
      if (List_Nbr($4) != List_Nbr($8)){
        yymsg(0, "Number of master faces (%d) different from number of "
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
      if (List_Nbr($5) != List_Nbr($10)){
        yymsg(0, "Number of master surface edges (%d) different from number of "
              "slave (%d) edges", List_Nbr($10), List_Nbr($5));
      }
      else{
        int j_master = (int)$8;
        int j_slave = (int)$3;
        std::map<int,int> edgeCounterParts;
        for (int i = 0; i < List_Nbr($5); i++){
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
  | tPoint '{' RecursiveListOfDouble '}' tIn tSurface '{' FExpr '}' tEND
    {
      Surface *s = FindSurface((int)$8);
      if(s){
	setSurfaceEmbeddedPoints(s, $3);
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)$8);
        if(gf){
          for(int i = 0; i < List_Nbr($3); i++){
            double d;
            List_Read($3, i, &d);
            int iPoint = (int)d;
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
            if(!gv){ // sync model in case the embedded point is a .geo point
              GModel::current()->importGEOInternals();
              gv = GModel::current()->getVertexByTag(iPoint);
            }
            if(gv)
              gf->addEmbeddedVertex(gv);
            else
              yymsg(0, "Unknown point %d", iPoint);
          }
        }
        else
          yymsg(0, "Unknown surface %d", (int)$8);
      }
    }
  | tLine '{' RecursiveListOfDouble '}' tIn tSurface '{' FExpr '}' tEND
    {
      Surface *s = FindSurface((int)$8);
      if(s){
	setSurfaceEmbeddedCurves(s, $3);
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)$8);
        if(gf){
          for(int i = 0; i < List_Nbr($3); i++){
            double d;
            List_Read($3, i, &d);
            int iCurve = (int)d;
            GEdge *ge = GModel::current()->getEdgeByTag(iCurve);
            if(!ge){ // sync model in case the embedded line is a .geo line
              GModel::current()->importGEOInternals();
              ge = GModel::current()->getEdgeByTag(iCurve);
            }
            if(ge)
              gf->addEmbeddedEdge(ge);
            else
              yymsg(0, "Unknown line %d", iCurve);
          }
        }
        else
          yymsg(0, "Unknown surface %d", (int)$8);
      }
    }
  | tPoint '{' RecursiveListOfDouble '}' tIn tVolume '{' FExpr '}' tEND
    {
      Volume *v = FindVolume((int)$8);
      if(v){
	setVolumeEmbeddedPoints(v, $3);
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)$8);
        if(gr){
          for(int i = 0; i < List_Nbr($3); i++){
            double d;
            List_Read($3, i, &d);
            int iPoint = (int)d;
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
            if(!gv){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              gv = GModel::current()->getVertexByTag(iPoint);
            }
            if(gv)
              gr->addEmbeddedVertex(gv);
            else
              yymsg(0, "Unknown Point %d", iPoint);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)$8);
      }
    }
  | tLine '{' RecursiveListOfDouble '}' tIn tVolume '{' FExpr '}' tEND
    {
      Volume *v = FindVolume((int)$8);
      if(v){
	setVolumeEmbeddedCurves(v, $3);
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)$8);
        if(gr){
          for(int i = 0; i < List_Nbr($3); i++){
            double d;
            List_Read($3, i, &d);
            int iLine = (int)d;
            GEdge *ge = GModel::current()->getEdgeByTag(iLine);
            if(!ge){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              ge = GModel::current()->getEdgeByTag(iLine);
            }
            if(ge)
              gr->addEmbeddedEdge(ge);
            else
              yymsg(0, "Unknown Curve %d", iLine);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)$8);
      }
    }
  | tSurface '{' RecursiveListOfDouble '}' tIn tVolume '{' FExpr '}' tEND
    {
      Volume *v = FindVolume((int)$8);
      if(v){
	setVolumeEmbeddedSurfaces(v, $3);
      }
      else{
        GRegion *gr = GModel::current()->getRegionByTag((int)$8);
        if(gr){
          for(int i = 0; i < List_Nbr($3); i++){
            double d;
            List_Read($3, i, &d);
            int iSurface = (int)d;
            GFace *gf = GModel::current()->getFaceByTag(iSurface);
            if(!gf){ // sync model in case the embedded face is a .geo face
              GModel::current()->importGEOInternals();
              gf = GModel::current()->getFaceByTag(iSurface);
            }
            if(gf)
              gr->addEmbeddedFace(gf);
            else
              yymsg(0, "Unknown surface %d", iSurface);
          }
        }
        else
          yymsg(0, "Unknown volume %d", (int)$8);
      }
    }
  | tReverse tSurface ListOfDoubleOrAll tEND
    {
      if(!$3){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Surfaces);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Surface *s;
            List_Read(tmp, i, &s);
            s->ReverseMesh = 1;
          }
        }
        else{
          for(GModel::fiter it = GModel::current()->firstFace();
              it != GModel::current()->lastFace(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          Surface *s = FindSurface((int)d);
          if(s){
            s->ReverseMesh = 1;
          }
          else{
            GFace *gf = GModel::current()->getFaceByTag((int)d);
            if(gf){
              gf->meshAttributes.reverseMesh = 1;
            }
            else
              yymsg(1, "Unknown surface %d", (int)d);
          }
        }
        List_Delete($3);
      }
    }
  | tReverse tLine ListOfDoubleOrAll tEND
    {
      if(!$3){
	List_T *tmp = Tree2List(GModel::current()->getGEOInternals()->Curves);
        if(List_Nbr(tmp)){
          for(int i = 0; i < List_Nbr(tmp); i++){
            Curve *c;
            List_Read(tmp, i, &c);
            c->ReverseMesh = 1;
          }
        }
        else{
          for(GModel::eiter it = GModel::current()->firstEdge();
              it != GModel::current()->lastEdge(); it++){
            (*it)->meshAttributes.reverseMesh = 1;
          }
        }
        List_Delete(tmp);
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          Curve *c = FindCurve((int)d);
          if(c){
            c->ReverseMesh = 1;
          }
          else{
            GEdge *ge = GModel::current()->getEdgeByTag((int)d);
            if(ge){
              ge->meshAttributes.reverseMesh = 1;
            }
            else
              yymsg(1, "Unknown line %d", (int)d);
          }
        }
        List_Delete($3);
      }
    }
  | tRelocateMesh tPoint ListOfDoubleOrAll tEND
    {
      if(!$3){
        for(GModel::viter it = GModel::current()->firstVertex();
            it != GModel::current()->lastVertex(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          GVertex *gv = GModel::current()->getVertexByTag((int)d);
          if(gv){
            gv->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown point %d", (int)d);
        }
        List_Delete($3);
      }
    }
  | tRelocateMesh tLine ListOfDoubleOrAll tEND
    {
      if(!$3){
        for(GModel::eiter it = GModel::current()->firstEdge();
            it != GModel::current()->lastEdge(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          GEdge *ge = GModel::current()->getEdgeByTag((int)d);
          if(ge){
            ge->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown line %d", (int)d);
        }
        List_Delete($3);
      }
    }
  | tRelocateMesh tSurface ListOfDoubleOrAll tEND
    {
      if(!$3){
        for(GModel::fiter it = GModel::current()->firstFace();
            it != GModel::current()->lastFace(); it++)
          (*it)->relocateMeshVertices();
      }
      else{
        for(int i = 0; i < List_Nbr($3); i++){
          double d;
          List_Read($3, i, &d);
          GFace *gf = GModel::current()->getFaceByTag((int)d);
          if(gf){
            gf->relocateMeshVertices();
          }
          else
            yymsg(1, "Unknown surface %d", (int)d);
        }
        List_Delete($3);
      }
    }
  | tCompound tLine ListOfDouble tEND
    {
      std::vector<int> tags; ListOfDouble2Vector($3, tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(1, tags);
      List_Delete($3);
    }
  | tCompound tSurface ListOfDouble tEND
    {
      std::vector<int> tags; ListOfDouble2Vector($3, tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(2, tags);
      List_Delete($3);
    }
  | tCompound tVolume ListOfDouble tEND
    {
      std::vector<int> tags; ListOfDouble2Vector($3, tags);
      GModel::current()->getGEOInternals()->setCompoundMesh(3, tags);
      List_Delete($3);
    }
;


//  C O H E R E N C E

Coherence :
    tCoherence tEND
    {
      ReplaceAllDuplicates();
    }
  | tCoherence tSTRING tEND
    {
      if(!strcmp($2, "Geometry"))
        ReplaceAllDuplicates();
      else if(!strcmp($2, "Mesh"))
        GModel::current()->removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);
      else
        yymsg(0, "Unknown coherence command");
      Free($2);
    }
  | tCoherence tPoint '{' RecursiveListOfDouble '}' tEND
    {
      if(List_Nbr($4) >= 2){
        double d;
        List_Read($4, 0, &d);
        Vertex *target = FindPoint((int)d);
        if(!target)
          yymsg(0, "Could not find Point %d", (int)d);
        else{
          double x = target->Pos.X, y = target->Pos.Y, z = target->Pos.Z;
          for(int i = 1; i < List_Nbr($4); i++){
            List_Read($4, i, &d);
            Vertex *source = FindPoint((int)d);
            if(!source) yymsg(0, "Could not find Point %d", (int)d);
            if(target && source){
              source->Typ = target->Typ;
              source->Pos.X = x;
              source->Pos.Y = y;
              source->Pos.Z = z;
              source->boundaryLayerIndex = target->boundaryLayerIndex;
            }
          }
          ExtrudeParams::normalsCoherence.push_back(SPoint3(x, y, z));
        }
      }
      else
        yymsg(0, "Need at least two points to merge");
      ReplaceAllDuplicates();
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
  | FExpr '%' FExpr                { $$ = (int)$1 % (int)$3;  }
  | FExpr '^' FExpr                { $$ = pow($1, $3);  }
  | FExpr '<' FExpr                { $$ = $1 < $3;      }
  | FExpr '>' FExpr                { $$ = $1 > $3;      }
  | FExpr tLESSOREQUAL FExpr       { $$ = $1 <= $3;     }
  | FExpr tGREATEROREQUAL FExpr    { $$ = $1 >= $3;     }
  | FExpr tEQUAL FExpr             { $$ = $1 == $3;     }
  | FExpr tNOTEQUAL FExpr          { $$ = $1 != $3;     }
  | FExpr tAND FExpr               { $$ = $1 && $3;     }
  | FExpr tOR FExpr                { $$ = $1 || $3;     }
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
  | tFloor  LP FExpr RP            { $$ = floor($3);    }
  | tCeil   LP FExpr RP            { $$ = ceil($3);     }
  | tRound  LP FExpr RP            { $$ = floor($3 + 0.5); }
  | tFmod   LP FExpr ',' FExpr RP  { $$ = fmod($3, $5); }
  | tModulo LP FExpr ',' FExpr RP  { $$ = fmod($3, $5); }
  | tHypot  LP FExpr ',' FExpr RP  { $$ = sqrt($3 * $3 + $5 * $5); }
  | tRand   LP FExpr RP            { $$ = $3 * (double)rand() / (double)RAND_MAX; }
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
    { floatOptions.clear(); charOptions.clear(); }
    FloatParameterOptions RP
    {
      std::vector<double> val(1, $3);
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      $$ = val[0];
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
  | String__Index
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
        else
          $$ = s.value[0];
      }
      Free($1);
    }
  | tSTRING '[' FExpr ']'
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
        else
          $$ = s.value[index];
      }
      Free($1);
    }
  | tSTRING '(' FExpr ')'
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
        else
          $$ = s.value[index];
      }
      Free($1);
    }
  | StringIndex '[' FExpr ']'
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
        else
          $$ = s.value[index];
      }
      Free($1);
    }
  | StringIndex '(' FExpr ')'
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
        else
          $$ = s.value[index];
      }
      Free($1);
    }
  | tExists '(' String__Index ')'
    {
      $$ = gmsh_yysymbols.count($3);
      Free($3);
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
  | tSTRING '[' FExpr ']' NumericIncrement
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
  | tSTRING '(' FExpr ')' NumericIncrement
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
  | StringIndex '[' FExpr ']' NumericIncrement
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
  | StringIndex '(' FExpr ')' NumericIncrement
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

  | tSTRING '.' tSTRING
    {
      NumberOption(GMSH_GET, $1, 0, $3, $$);
      Free($1); Free($3);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING
    {
      NumberOption(GMSH_GET, $1, (int)$3, $6, $$);
      Free($1); Free($6);
    }
  | tSTRING '.' tSTRING NumericIncrement
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, $1, 0, $3, d)){
	d += $4;
	NumberOption(GMSH_SET|GMSH_GUI, $1, 0, $3, d);
	$$ = d;
      }
      Free($1); Free($3);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING NumericIncrement
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
        yyerror("Number of text attributes should be even");
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
  | tBIGSTR
    {
      if(!strcmp($1, "*") || !strcmp($1, "all"))
        $$ = 0;
      else{
        yyerror("Unknown special string for list replacement");
        $$ = List_Create(2, 1, sizeof(double));
      }
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
      // Returns the coordinates of a point and fills a list with it.
      // This allows to ensure e.g. that relative point positions are
      // always conserved
      Vertex *v = FindPoint((int)$3);
      $$ = List_Create(3, 1, sizeof(double));
      if(!v) {
        GVertex *gv = GModel::current()->getVertexByTag((int)$3);
        if(gv){
          double x = gv->x(), y = gv->y(), z = gv->z();
          List_Add($$, &x);
          List_Add($$, &y);
          List_Add($$, &z);
        }
        else{
          yymsg(0, "Unknown point '%d'", (int)$3);
          double d = 0.0;
          List_Add($$, &d);
          List_Add($$, &d);
          List_Add($$, &d);
        }
      }
      else{
	List_Add($$, &v->Pos.X);
	List_Add($$, &v->Pos.Y);
	List_Add($$, &v->Pos.Z);
      }
    }
  | tPoint tBIGSTR
    {
      $$ = GetAllElementaryEntityNumbers(0);
    }
  | tLine tBIGSTR
    {
      $$ = GetAllElementaryEntityNumbers(1);
    }
  | tSurface tBIGSTR
    {
      $$ = GetAllElementaryEntityNumbers(2);
    }
  | tVolume tBIGSTR
    {
      $$ = GetAllElementaryEntityNumbers(3);
    }
  | tPhysical tPoint tBIGSTR
    {
      $$ = GetAllPhysicalEntityNumbers(0);
    }
  | tPhysical tLine tBIGSTR
    {
      $$ = GetAllPhysicalEntityNumbers(1);
    }
  | tPhysical tSurface tBIGSTR
    {
      $$ = GetAllPhysicalEntityNumbers(2);
    }
  | tPhysical tVolume tBIGSTR
    {
      $$ = GetAllPhysicalEntityNumbers(3);
    }
  | tPhysical tPoint '{' RecursiveListOfDouble '}'
    {
      $$ = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr($4); i++){
        double num;
        List_Read($4, i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_POINT);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add($$, &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(0, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add($$, &d);
            }
          }
        }
      }
      List_Delete($4);
    }
  | tPhysical tLine '{' RecursiveListOfDouble '}'
    {
      $$ = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr($4); i++){
        double num;
        List_Read($4, i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_LINE);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add($$, &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(1, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add($$, &d);
            }
          }
        }
      }
      List_Delete($4);
    }
  | tPhysical tSurface '{' RecursiveListOfDouble '}'
    {
      $$ = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr($4); i++){
        double num;
        List_Read($4, i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_SURFACE);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add($$, &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(2, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add($$, &d);
            }
          }
        }
      }
      List_Delete($4);
    }
  | tPhysical tVolume '{' RecursiveListOfDouble '}'
    {
      $$ = List_Create(10, 1, sizeof(double));
      for(int i = 0; i < List_Nbr($4); i++){
        double num;
        List_Read($4, i, &num);
        PhysicalGroup *p = FindPhysicalGroup((int)num, MSH_PHYSICAL_VOLUME);
        if(p){
          for(int j = 0; j < List_Nbr(p->Entities); j++){
            int nume;
            List_Read(p->Entities, j, &nume);
            double d = nume;
            List_Add($$, &d);
          }
        }
        else{
          std::map<int, std::vector<GEntity*> > groups;
          GModel::current()->getPhysicalGroups(3, groups);
          std::map<int, std::vector<GEntity*> >::iterator it = groups.find((int)num);
          if(it != groups.end()){
            for(unsigned j = 0; j < it->second.size(); j++){
              double d = it->second[j]->tag();
              List_Add($$, &d);
            }
          }
        }
      }
      List_Delete($4);
    }
  | tPoint tIn tBoundingBox
      '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}'
    {
      $$ = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box($5, $7, $9, $11, $13, $15);
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 0);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add($$, &d);
      }
    }
  | tLine tIn tBoundingBox
      '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}'
    {
      $$ = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box($5, $7, $9, $11, $13, $15);
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 1);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add($$, &d);
      }
    }
  | tSurface tIn tBoundingBox
      '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}'
    {
      $$ = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box($5, $7, $9, $11, $13, $15);
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 2);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add($$, &d);
      }
    }
  | tVolume tIn tBoundingBox
      '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}'
    {
      $$ = List_Create(10, 1, sizeof(double));
      GModel::current()->importGEOInternals();
      SBoundingBox3d box($5, $7, $9, $11, $13, $15);
      std::vector<GEntity*> entities;
      GModel::current()->getEntitiesInBox(entities, box, 3);
      for(unsigned int i = 0; i < entities.size(); i++){
        double d = entities[i]->tag();
	List_Add($$, &d);
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
  | tSTRING LP RP
    {
      $$ = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1);
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add($$, &s.value[i]);
      }
      Free($1);
    }
  | StringIndex LP RP
    {
      $$ = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1);
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$1]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add($$, &s.value[i]);
      }
      Free($1);
    }
   // for compatibility with GetDP
  | tList '[' String__Index ']'
    {
      $$ = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count($3))
	yymsg(0, "Unknown variable '%s'", $3);
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[$3]);
	for(unsigned int i = 0; i < s.value.size(); i++)
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
  | tList '[' '{' RecursiveListOfDouble '}' ']'
    {
      $$ = $4;
    }
  | tList '(' '{' RecursiveListOfDouble '}' ')'
    {
      $$ = $4;
    }
  | tSTRING LP '{' RecursiveListOfDouble '}' RP
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
  | StringIndex LP '{' RecursiveListOfDouble '}' RP
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
        Msg::Warning("Catenary did not converge, using linear interpolation");
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
      std::vector<double>::iterator last = std::unique(tmp.begin(), tmp.end());
      tmp.erase(last, tmp.end());
      $$ = $3;
      List_Reset($$);
      for(unsigned int i = 0; i < tmp.size(); i++){
        List_Add($$, &tmp[i]);
      }
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
  | tSTRING '[' FExpr ']' '.' tColorTable
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
      std::string val;
      if(!gmsh_yystringsymbols.count($1))
        yymsg(0, "Unknown string variable '%s'", $1);
      else if(gmsh_yystringsymbols[$1].size() == 1)
        val = gmsh_yystringsymbols[$1][0];
      else
        yymsg(0, "Expected single valued string variable '%s'", $1);
      $$ = (char *)Malloc((val.size() + 1) * sizeof(char));
      strcpy($$, val.c_str());
      Free($1);
    }
  | tSTRING '[' FExpr ']'
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
  | StringIndex '[' FExpr ']'
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
  | tSTRING '(' FExpr ')'
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
  | StringIndex '(' FExpr ')'
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
  | tSTRING '.' tSTRING
    {
      std::string out;
      StringOption(GMSH_GET, $1, 0, $3, out);
      $$ = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy($$, out.c_str());
      Free($1); Free($3);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING
    {
      std::string out;
      StringOption(GMSH_GET, $1, (int)$3, $6, out);
      $$ = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy($$, out.c_str());
      Free($1); Free($6);
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
  | tGetEnv '(' StringExprVar ')'
    {
      const char *env = GetEnvironmentVar($3);
      if(!env) env = "";
      $$ = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy($$, env);
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
        if (i > 0 && $3[i-1] != '_')
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
      int i = PrintListOfDouble($3, $5, tmpstring);
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
    { floatOptions.clear(); charOptions.clear(); }
    CharParameterOptions RP
    {
      std::string val($3);
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      $$ = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy($$, val.c_str());
      Free($3);
    }
;

RecursiveListOfStringExprVar :
    StringExprVar
    {
      $$ = List_Create(20,20,sizeof(char*));
      List_Add($$, &($1));
    }
  | RecursiveListOfStringExprVar ',' StringExprVar
    { List_Add($$, &($3)); }
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

int PrintListOfDouble(char *format, List_T *list, char *buffer)
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
      std::string s = it->first + "[] = Str(";
      for(unsigned int i = 0; i < it->second.size(); i++){
        if(i) s += ", ";
        s += std::string("\"") + it->second[i] + "\"";
      }
      s += ");";
      vec.push_back(s);
    }
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
  v.reserve(List_Nbr(list));
  for(int i = 0; i < List_Nbr(list); i++){
    double d;
    List_Read(list, i, &d);
    v.push_back(d);
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
  else{
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::vector<double>& affineTransform)
{
  Surface *target = FindSurface(abs(iTarget));

  if (target) {
    GEO_Internals::MasterFace& mf =
      GModel::current()->getGEOInternals()->periodicFaces[iTarget];
    mf.tag = iSource;
    mf.edgeCounterparts.clear();
    mf.affineTransform = affineTransform;
  }
  else{
    GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
    GFace *source = GModel::current()->getFaceByTag(abs(iSource));
    if (!target || !source) {
      Msg::Error("Could not find edge slave %d or master %d for periodic copy",
                 iTarget, iSource);
    }
    else target->setMeshMaster(source, affineTransform);
  }
}

void addPeriodicFace(int iTarget, int iSource,
                     const std::map<int,int>& edgeCounterparts)
{
  Surface *target = FindSurface(abs(iTarget));

  Msg::Info("Encoding periodic connection between %d and %d", iTarget, iSource);
  std::map<int,int>::const_iterator sIter = edgeCounterparts.begin();
  for (; sIter != edgeCounterparts.end(); ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  if (target) {
    GEO_Internals::MasterFace& mf =
      GModel::current()->getGEOInternals()->periodicFaces[iTarget];
    mf.tag = iSource;
    mf.edgeCounterparts = edgeCounterparts;
    mf.affineTransform.clear();
  }
  else{
    GFace *target = GModel::current()->getFaceByTag(abs(iTarget));
    GFace *source = GModel::current()->getFaceByTag(abs(iSource));
    if (!target || !source) {
      Msg::Error("Could not find surface slave %d or master %d for periodic copy",
                 iTarget,iSource);
		}
		else target->setMeshMaster(source, edgeCounterparts);
  }
}

void addPeriodicEdge(int iTarget,int iSource,
                     const std::vector<double>& affineTransform)
{
  Curve *target = FindCurve(abs(iTarget));
  if (target) {
    GEO_Internals::MasterEdge& me =
      GModel::current()->getGEOInternals()->periodicEdges[iTarget];
    me.tag = iSource;
    me.affineTransform = affineTransform;
  }
  else{
    GEdge *target = GModel::current()->getEdgeByTag(abs(iTarget));
    GEdge *source = GModel::current()->getEdgeByTag(abs(iSource));
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

int NEWPOINT(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals())
    tag = GModel::current()->getGEOInternals()->MaxPointNum + 1;
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(0) + 1);
  return tag;
}

int NEWLINE(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxLineNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(1) + 1);
  return tag;
}

int NEWLINELOOP(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxLineLoopNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-1) + 1);
  return tag;
}

int NEWSURFACE(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxSurfaceNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(2) + 1);
  return tag;
}

int NEWSURFACELOOP(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxSurfaceLoopNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(-2) + 1);
  return tag;
}

int NEWVOLUME(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    if(CTX::instance()->geom.oldNewreg)
      tag = NEWREG();
    else
      tag = GModel::current()->getGEOInternals()->MaxVolumeNum + 1;
  }
  if(GModel::current()->getOCCInternals())
    tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(3) + 1);
  return tag;
}

int NEWREG(void)
{
  int tag = 0;
  if(GModel::current()->getGEOInternals()){
    tag = GModel::current()->getGEOInternals()->MaxLineNum;
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxLineLoopNum);
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxSurfaceNum);
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxSurfaceLoopNum);
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxVolumeNum);
    tag = std::max(tag, GModel::current()->getGEOInternals()->MaxPhysicalNum);
    tag += 1;
  }
  if(GModel::current()->getOCCInternals()){
    for(int i = -2; i < 4; i++)
      tag = std::max(tag, GModel::current()->getOCCInternals()->getMaxTag(i) + 1);
  }
  return tag;
}
