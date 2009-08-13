%{
// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshMatrix.h"
#include "MallocUtils.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "Numeric.h"
#include "Context.h"
#include "GModel.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Generator.h"
#include "Draw.h"
#include "Options.h"
#include "Colors.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "FunctionManager.h"
#include "ColorTable.h"
#include "OS.h"
#include "CreateFile.h"
#include "gmshSurface.h"
#include "Field.h"
#include "BackgroundMesh.h"
#if !defined(HAVE_NO_POST)
#include "PView.h"
#include "PViewDataList.h"
#include "PluginManager.h"
#endif

// Global parser variables
std::string gmsh_yyname;
int gmsh_yyerrorstate = 0;
int gmsh_yyviewindex = 0;
std::map<std::string, std::vector<double> > gmsh_yysymbols;

// Static parser variables (accessible only in this file)
static std::map<std::string, std::string > gmsh_yystringsymbols;
#if !defined(HAVE_NO_POST)
static PViewDataList *ViewData;
#endif
static std::vector<double> ViewCoord;
static std::vector<double> *ViewValueList = 0;
static int *ViewNumList = 0;
static ExtrudeParams extr;
static int curPhysDim = 0;
static gmshSurface *myGmshSurface = 0;
#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

void yyerror(char *s);
void yymsg(int level, const char *fmt, ...);
void skip_until(const char *skip, const char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
gmshMatrix<double> ListOfListOfDouble2Matrix(List_T *list);
void FixRelativePath(const char *in, char *out);
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

%token tEND tAFFECT tDOTS tPi tMPI_Rank tMPI_Size tEuclidian tCoordinates
%token tExp tLog tLog10 tSqrt tSin tAsin tCos tAcos tTan tRand
%token tAtan tAtan2 tSinh tCosh tTanh tFabs tFloor tCeil
%token tFmod tModulo tHypot 
%token tPrintf tSprintf tStrCat tStrPrefix tStrRelative
%token tBoundingBox tDraw tToday tSyncModel tCreateTopology
%token tPoint tCircle tEllipse tLine tSphere tPolarSphere tSurface tSpline tVolume
%token tCharacteristic tLength tParametric tElliptic
%token tPlane tRuled tTransfinite tComplex tPhysical tCompound
%token tUsing tPlugin
%token tRotate tTranslate tSymmetry tDilate tExtrude
%token tLoop tRecombine tSmoother tSplit tDelete tCoherence tIntersect
%token tLayers tHole tAlias tAliasWithOptions
%token tText2D tText3D tInterpolationScheme  tTime tCombine
%token tBSpline tBezier tNurbs tOrder tKnots
%token tColor tColorTable tFor tIn tEndFor tIf tEndIf tExit
%token tField tReturn tCall tFunction tShow tHide tGetValue
%token tGMSH_MAJOR_VERSION tGMSH_MINOR_VERSION tGMSH_PATCH_VERSION

%type <d> FExpr FExpr_Single 
%type <v> VExpr VExpr_Single CircleOptions TransfiniteType
%type <i> NumericAffectation NumericIncrement PhysicalId
%type <i> TransfiniteArrangement RecombineAngle
%type <u> ColorExpr
%type <c> StringExpr StringExprVar SendToFile
%type <l> FExpr_Multi ListOfDouble ListOfDoubleOrAll RecursiveListOfDouble
%type <l> RecursiveListOfListOfDouble 
%type <l> ListOfColor RecursiveListOfColor 
%type <l> ListOfShapes Transform Extrude MultipleShape 
%type <l> TransfiniteCorners InSphereCenter
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
    View        { return 1; }
  | Printf      { return 1; }
  | Affectation { return 1; }
  | Shape       { return 1; }
  | Transform   { List_Delete($1); return 1; }
  | Delete      { return 1; }
  | Colorify    { return 1; }
  | Visibility  { return 1; }
  | Extrude     { List_Delete($1); return 1; }
  | Transfinite { return 1; }
  | Embedding   { return 1; }
  | Coherence   { return 1; }
  | Loop        { return 1; }
  | Command     { return 1; }
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
    tPrintf '(' tBIGSTR ')' tEND
    {
      Msg::Direct($3);
      Free($3);
    }
  | tPrintf '(' tBIGSTR ')' SendToFile StringExprVar tEND
    {
      char tmpstring[1024];
      FixRelativePath($6, tmpstring);
      FILE *fp = fopen(tmpstring, $5);
      if(!fp){
	yymsg(0, "Unable to open file '%s'", tmpstring);
      }
      else{
	fprintf(fp, "%s\n", $3);
	fclose(fp);
      }
      Free($3);
      Free($6);
    }
  | tPrintf '(' tBIGSTR ',' RecursiveListOfDouble ')' tEND
    {
      char tmpstring[1024];
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
  | tPrintf '(' tBIGSTR ',' RecursiveListOfDouble ')' SendToFile StringExprVar tEND
    {
      char tmpstring[1024];
      int i = PrintListOfDouble($3, $5, tmpstring);
      if(i < 0) 
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else{
	char tmpstring2[1024];
	FixRelativePath($8, tmpstring2);
	FILE *fp = fopen(tmpstring2, $7);
	if(!fp){
	  yymsg(0, "Unable to open file '%s'", tmpstring2);
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
    tSTRING tBIGSTR '{' Views '}' tEND
    { 
#if !defined(HAVE_NO_POST)
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
#if !defined(HAVE_NO_POST)
      if(!strcmp($2, "View")){
	int index = (int)$4;
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], false);
      }
#endif
      Free($2);
    }
  | tAliasWithOptions tSTRING '[' FExpr ']' tEND
    {
#if !defined(HAVE_NO_POST)
      if(!strcmp($2, "View")){
	int index = (int)$4;
	if(index >= 0 && index < (int)PView::list.size())
	  new PView(PView::list[index], true);
      }
#endif
      Free($2);
    }
;

Views :
    // nothing
    {
#if !defined(HAVE_NO_POST)
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
#if !defined(HAVE_NO_POST)
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
#if !defined(HAVE_NO_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(int j = 0; j < ViewCoord.size() / 3; j++) 
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    }
    '{' ElementValues '}' tEND
    {
#if !defined(HAVE_NO_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    }
;

Text2DValues :
    StringExprVar
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen($1) + 1; i++) ViewData->T2C.push_back($1[i]);
#endif
      Free($1);
    }
  | Text2DValues ',' StringExprVar
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen($3) + 1; i++) ViewData->T2C.push_back($3[i]);
#endif
      Free($3);
    }
;

Text2D : 
    tText2D '(' FExpr ',' FExpr ',' FExpr ')'
    { 
#if !defined(HAVE_NO_POST)
      ViewData->T2D.push_back($3); 
      ViewData->T2D.push_back($5);
      ViewData->T2D.push_back($7); 
      ViewData->T2D.push_back(ViewData->T2C.size()); 
#endif
    }
    '{' Text2DValues '}' tEND
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT2++;
#endif
    }
;

Text3DValues :
    StringExprVar
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen($1) + 1; i++) ViewData->T3C.push_back($1[i]);
#endif
      Free($1);
    }
  | Text3DValues ',' StringExprVar
    { 
#if !defined(HAVE_NO_POST)
      for(int i = 0; i < (int)strlen($3) + 1; i++) ViewData->T3C.push_back($3[i]);
#endif
      Free($3);
    }
;

Text3D : 
    tText3D '(' FExpr ',' FExpr ',' FExpr ',' FExpr ')'
    { 
#if !defined(HAVE_NO_POST)
      ViewData->T3D.push_back($3); ViewData->T3D.push_back($5);
      ViewData->T3D.push_back($7); ViewData->T3D.push_back($9);
      ViewData->T3D.push_back(ViewData->T3C.size()); 
#endif
    }
    '{' Text3DValues '}' tEND
    {
#if !defined(HAVE_NO_POST)
      ViewData->NbT3++;
#endif
    }
;

InterpolationMatrix :
    tInterpolationScheme '{' RecursiveListOfListOfDouble '}' 
                         '{' RecursiveListOfListOfDouble '}'  tEND
    {
#if !defined(HAVE_NO_POST)
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
#if !defined(HAVE_NO_POST)
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
#if !defined(HAVE_NO_POST)
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

Affectation :

  // Variables

    tSTRING NumericAffectation FExpr tEND
    {
      if(!gmsh_yysymbols.count($1)){
	if(!$2)
	  gmsh_yysymbols[$1].push_back($3);
	else
	  yymsg(0, "Unknown variable '%s'", $1);
      }
      else{
	switch($2){
	case 0 : gmsh_yysymbols[$1][0] = $3; break;
	case 1 : gmsh_yysymbols[$1][0] += $3; break;
	case 2 : gmsh_yysymbols[$1][0] -= $3; break;
	case 3 : gmsh_yysymbols[$1][0] *= $3; break;
	case 4 : 
	  if($3) gmsh_yysymbols[$1][0] /= $3; 
	  else yymsg(0, "Division by zero in '%s /= %g'", $1, $3);
	  break;
	}
      }
      Free($1);
    }
  | tSTRING '[' FExpr ']' NumericAffectation FExpr tEND
    {
      int index = (int)$3;
      if(!gmsh_yysymbols.count($1)){
	if(!$5){
	  gmsh_yysymbols[$1].resize(index + 1, 0.);
	  gmsh_yysymbols[$1][index] = $6;
	}
	else
	  yymsg(0, "Unknown variable '%s'", $1);
      }
      else{
	if(gmsh_yysymbols[$1].size() < index + 1)
	  gmsh_yysymbols[$1].resize(index + 1, 0.);
	switch($5){
	case 0 : gmsh_yysymbols[$1][index] = $6; break;
	case 1 : gmsh_yysymbols[$1][index] += $6; break;
	case 2 : gmsh_yysymbols[$1][index] -= $6; break;
	case 3 : gmsh_yysymbols[$1][index] *= $6; break;
	case 4 : 
	  if($6) gmsh_yysymbols[$1][index] /= $6; 
	  else yymsg(0, "Division by zero in '%s[%d] /= %g'", $1, index, $6);
	  break;
	}
      }
      Free($1);
    }
  | tSTRING '[' '{' RecursiveListOfDouble '}' ']' NumericAffectation ListOfDouble tEND
    {
      if(List_Nbr($4) != List_Nbr($8)){
	yymsg(0, "Incompatible array dimensions in affectation");
      }
      else{
	if(!gmsh_yysymbols.count($1)){
	  if(!$7){
	    for(int i = 0; i < List_Nbr($4); i++){
	      int index = (int)(*(double*)List_Pointer($4, i));
	      gmsh_yysymbols[$1].resize(index + 1, 0.);
	      gmsh_yysymbols[$1][index] = *(double*)List_Pointer($8, i);
	    }
	  }
	  else
	    yymsg(0, "Unknown variable '%s'", $1);
	}
	else{
	  for(int i = 0; i < List_Nbr($4); i++){
	    int index = (int)(*(double*)List_Pointer($4, i));
	    double d = *(double*)List_Pointer($8, i);
	    if(gmsh_yysymbols[$1].size() < index + 1)
	      gmsh_yysymbols[$1].resize(index + 1, 0.);
	    switch($7){
	    case 0 : gmsh_yysymbols[$1][index] = d; break;
	    case 1 : gmsh_yysymbols[$1][index] += d; break;
	    case 2 : gmsh_yysymbols[$1][index] -= d; break;
	    case 3 : gmsh_yysymbols[$1][index] *= d; break;
	    case 4 : 
	      if($8) gmsh_yysymbols[$1][index] /= d; 
	      else yymsg(0, "Division by zero in '%s[%d] /= %g'", $1, index, d);
	      break;
	    }
	  }
	}
      }
      Free($1);
      List_Delete($4);
      List_Delete($8);
    }
  | tSTRING '[' ']' tAFFECT ListOfDouble tEND
    {
      if(gmsh_yysymbols.count($1))
	gmsh_yysymbols[$1].clear();
      gmsh_yysymbols[$1] = std::vector<double>();
      for(int i = 0; i < List_Nbr($5); i++)
        gmsh_yysymbols[$1].push_back(*(double*)List_Pointer($5, i));
      Free($1);
      List_Delete($5);
    }
  | tSTRING '[' ']' tAFFECTPLUS ListOfDouble tEND
    {
      // appends to the list
      for(int i = 0; i < List_Nbr($5); i++)
	gmsh_yysymbols[$1].push_back(*(double*)List_Pointer($5, i));
      Free($1);
      List_Delete($5);
    }
  | tSTRING NumericIncrement tEND
    {
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1); 
      else
	gmsh_yysymbols[$1][0] += $2;
      Free($1);
    }
  | tSTRING '[' FExpr ']' NumericIncrement tEND
    {
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1); 
      else{
	int index = (int)$3;
	if(gmsh_yysymbols[$1].size() < index + 1)
	  gmsh_yysymbols[$1].resize(index + 1, 0.);
	gmsh_yysymbols[$1][index] += $5;
      }
      Free($1);
    }
  | tSTRING tAFFECT StringExpr tEND 
    { 
      gmsh_yystringsymbols[$1] = std::string($3);
      Free($1);
      Free($3);
    }

  // Option Strings

  | tSTRING '.' tSTRING tAFFECT StringExpr tEND 
    { 
      std::string tmp($5);
      StringOption(GMSH_SET|GMSH_GUI, $1, 0, $3, tmp);
      Free($1); Free($3); Free($5)
    }
  | tSTRING '[' FExpr ']' '.' tSTRING tAFFECT StringExpr tEND 
    { 
      std::string tmp($8);
      StringOption(GMSH_SET|GMSH_GUI, $1, (int)$3, $6, tmp);
      Free($1); Free($6); Free($8)
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
      if(!strcmp($1,"Background"))
	GModel::current()->getFields()->background_field = (int)$4;
      else
	yymsg(0, "Unknown command %s Field", $1);
    }
  | tField '[' FExpr ']' tAFFECT tSTRING tEND
    {
      if(!GModel::current()->getFields()->newField((int)$3, $6))
	yymsg(0, "Cannot create field %i of type '%s'", (int)$3, $6);
      Free($6);
    }
  | tField '[' FExpr ']' '.' tSTRING  tAFFECT FExpr tEND
    {
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
      Free($6);
    }
  | tField '[' FExpr ']' '.' tSTRING  tAFFECT StringExpr tEND
    {
      Field *field = GModel::current()->getFields()->get((int)$3);
      if(field){
	FieldOption *option = field->options[$6];
	if(option){
	  try { option->string() = $8; }
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
      Free($6);
      Free($8);
    }
  | tField '[' FExpr ']' '.' tSTRING  tAFFECT '{' RecursiveListOfDouble '}' tEND
    {
      Field *field = GModel::current()->getFields()->get((int)$3);
      if(field){
	FieldOption *option = field->options[$6];
	if(option){
	  std::list<int> &vl = option->list();
	  vl.clear();
	  for(int i = 0; i < List_Nbr($9); i++){
	    double id;
	    List_Read($9, i, &id);
	    vl.push_back((int)id);
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		$6, (int)$3, field->getName());
      }
      else 
	yymsg(0, "No field with id %i", (int)$3);
      Free($6);
      List_Delete($9);
    }

  // Plugins

  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT FExpr tEND 
    {
#if !defined(HAVE_NO_POST)
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
#if !defined(HAVE_NO_POST)
      try {
	PluginManager::instance()->setPluginOption($3, $6, $8); 
      }
      catch (...) {
	yymsg(0, "Unknown option '%s' or plugin '%s'", $6, $3);
      }
#endif
      Free($3); Free($6);
    }
;

//  S H A P E

PhysicalId :
    FExpr
    { 
      $$ = (int)$1; 
    }
  | StringExpr
    { 
      $$ = GModel::current()->setPhysicalName
        (std::string($1), curPhysDim, 
         ++GModel::current()->getGEOInternals()->MaxPhysicalNum);
      Free($1);
    }
;

InSphereCenter :
    // nothing
    {
      $$ = 0;
    }
  | tIn tSphere '{' FExpr '}'
    {
      $$ = List_Create(1, 1, sizeof(Vertex*));
      Vertex *v = FindPoint((int)$4);
      if(!v)
	yymsg(0, "Unknown point %d", (int)$4);
      else{
	List_Add($$, &v);
      }
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

  // Points

    tPoint '(' FExpr ')' tAFFECT VExpr tEND
    {
      int num = (int)$3;
      if(FindPoint(num)){
	yymsg(0, "Point %d already exists", num);
      }
      else{
	double x = CTX::instance()->geom.scalingFactor * $6[0];
	double y = CTX::instance()->geom.scalingFactor * $6[1];
	double z = CTX::instance()->geom.scalingFactor * $6[2];
	double lc = CTX::instance()->geom.scalingFactor * $6[3];
	if(lc == 0.) lc = MAX_LC; // no mesh size given at the point
	Vertex *v;
	if(!myGmshSurface)
	  v = Create_Vertex(num, x, y, z, lc, 1.0);
	else
	  v = Create_Vertex(num, x, y, myGmshSurface, lc);
	Tree_Add(GModel::current()->getGEOInternals()->Points, &v);
	AddToTemporaryBoundingBox(v->Pos.X, v->Pos.Y, v->Pos.Z);
      }
      $$.Type = MSH_POINT;
      $$.Num = num;
    }
  | tPhysical tPoint 
    {
      curPhysDim = 0;
    }
    '(' PhysicalId ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$5;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(0, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($8);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete($8);
      $$.Type = MSH_PHYSICAL_POINT;
      $$.Num = num;
    }
  | tCharacteristic tLength ListOfDouble tAFFECT FExpr tEND
    {      
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	Vertex *v = FindPoint((int)d); 	 
	if(v)
	  v->lc = $5;
	else{
	  GVertex *gv = GModel::current()->getVertexByTag((int)d);
	  if(gv) 
	    gv->setPrescribedMeshSizeAtVertex($5);
	}
      }
      List_Delete($3);
      // dummy values
      $$.Type = 0;
      $$.Num = 0;
    }  

  // Lines

  | tLine '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_LINE;
      $$.Num = num;
    }
  | tSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_SPLN;
      $$.Num = num;
    }
  | tCircle '(' FExpr ')'  tAFFECT ListOfDouble CircleOptions tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
        if($7[0] || $7[1] || $7[2]){
          c->Circle.n[0] = $7[0];
          c->Circle.n[1] = $7[1];
          c->Circle.n[2] = $7[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if($7[0] || $7[1] || $7[2]){
          rc->Circle.n[0] = $7[0];
          rc->Circle.n[1] = $7[1];
          rc->Circle.n[2] = $7[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_CIRC;
      $$.Num = num;
    }
  | tEllipse '(' FExpr ')'  tAFFECT ListOfDouble CircleOptions tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
        if($7[0] || $7[1] || $7[2]){
          c->Circle.n[0] = $7[0];
          c->Circle.n[1] = $7[1];
          c->Circle.n[2] = $7[2];
          End_Curve(c);
        }
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
        if($7[0] || $7[1] || $7[2]){
          rc->Circle.n[0] = $7[0];
          rc->Circle.n[1] = $7[1];
          rc->Circle.n[2] = $7[2];
          End_Curve(rc);
        }
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_ELLI;
      $$.Num = num;
    }
  | tParametric '(' FExpr ')' tAFFECT 
      '{' FExpr ',' FExpr ',' tBIGSTR ',' tBIGSTR ',' tBIGSTR '}' tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	Curve *c = Create_Curve(num, MSH_SEGM_PARAMETRIC, 2, NULL, NULL,
				-1, -1, $7, $9);
	strcpy(c->functu, $11);
	strcpy(c->functv, $13);
	strcpy(c->functw, $15);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
      }
      Free($11); Free($13); Free($15);
      $$.Type = MSH_SEGM_PARAMETRIC;
      $$.Num = num;
    }
  | tBSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_BSPLN;
      $$.Num = num;
    }
  | tBezier '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(0, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_BEZIER;
      $$.Num = num;
    }
  | tNurbs  '(' FExpr ')' tAFFECT ListOfDouble tKnots ListOfDouble tOrder FExpr tEND
    {
      int num = (int)$3;
      if(List_Nbr($6) + (int)$10 + 1 != List_Nbr($8)){
	yymsg(0, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)$3, List_Nbr($8), List_Nbr($6), (int)$10, List_Nbr($6) + (int)$10 + 1);
      }
      else{
	if(FindCurve(num)){
	  yymsg(0, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt($6);
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)$10, temp, $8,
				  -1, -1, 0., 1.);
	  Tree_Add(GModel::current()->getGEOInternals()->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete($6);
      List_Delete($8);
      $$.Type = MSH_SEGM_NURBS;
      $$.Num = num;
    }
  | tLine tLoop '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindEdgeLoop(num)){
	yymsg(0, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete($7);
      $$.Type = MSH_SEGM_LOOP;
      $$.Num = num;
    }
  | tPhysical tLine 
    {
      curPhysDim = 1;
    }
    '(' PhysicalId ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$5;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($8);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete($8);
      $$.Type = MSH_PHYSICAL_LINE;
      $$.Num = num;
    }

  // Surfaces

  | tPlane tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt($7);
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	End_Surface(s);
	Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
      }
      List_Delete($7);
      $$.Type = MSH_SURF_PLAN;
      $$.Num = num;
    }
  | tRuled tSurface '(' FExpr ')' tAFFECT ListOfDouble InSphereCenter tEND
    {
      int num = (int)$4, type = 0;
      if(FindSurface(num)){
	yymsg(0, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read($7, 0, &d);
	EdgeLoop *el = FindEdgeLoop((int)fabs(d));
	if(!el){
	  yymsg(0, "Unknown line loop %d", (int)d);
	}
	else{
	  int j = List_Nbr(el->Curves);
	  if(j == 4){
	    type = MSH_SURF_REGL;
	  }
	  else if(j == 3){
	    type = MSH_SURF_TRIC;
	  }
	  else{
	    yymsg(0, "Wrong definition of Ruled Surface %d: "
		  "%d borders instead of 3 or 4", num, j);
	    type = MSH_SURF_PLAN;
	  }
	  Surface *s = Create_Surface(num, type);
	  List_T *temp = ListOfDouble2ListOfInt($7);
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  End_Surface(s);
	  s->InSphereCenter = $8;
	  Tree_Add(GModel::current()->getGEOInternals()->Surfaces, &s);
	}
      }
      List_Delete($7);
      $$.Type = type;
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
      if (List_Nbr($6) != 2){
	yymsg(0, "Sphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr($6));
      }
      else{
	double p1,p2;
	List_Read($6, 0, &p1);
	List_Read($6, 1, &p2);
	Vertex *v1 = FindPoint((int)p1);
	Vertex *v2 = FindPoint((int)p2);
	if(!v1) yymsg(0, "Sphere %d : unknown point %d", num, (int)p1);
	if(!v2) yymsg(0, "Sphere %d : unknown point %d", num, (int)p2);
	if(v1 && v2)
	  myGmshSurface = gmshSphere::NewSphere
	    (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
	     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
		  (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
		  (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
      }
      $$.Type = 0;
      $$.Num = num;
    }
  | tPolarSphere '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if (List_Nbr($6) != 2){
	yymsg(0, "PolarSphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr($6));
      }
      else{
	double p1,p2;
	List_Read($6, 0, &p1);
	List_Read($6, 1, &p2);
	Vertex *v1 = FindPoint((int)p1);
	Vertex *v2 = FindPoint((int)p2);
	if(!v1) yymsg(0, "PolarSphere %d : unknown point %d", num, (int)p1);
	if(!v2) yymsg(0, "PolarSphere %d : unknown point %d", num, (int)p2);
	if(v1 && v2)
	  myGmshSurface = gmshPolarSphere::NewPolarSphere
	    (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
	     sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
		  (v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
		  (v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
      }
      $$.Type = 0;
      $$.Num = num;
    }
  | tSurface tLoop '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindSurfaceLoop(num)){
	yymsg(0, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(GModel::current()->getGEOInternals()->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete($7);
      $$.Type = MSH_SURF_LOOP;
      $$.Num = num;
    }
  | tPhysical tSurface 
    {
      curPhysDim = 2;
    }
    '(' PhysicalId ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$5;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($8);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete($8);
      $$.Type = MSH_PHYSICAL_SURFACE;
      $$.Num = num;
    }

  | tCompound tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	List_T *S[4] = {temp, 0, 0, 0};
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp, S);
	List_Delete(temp);
        List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_VOLUME;
      $$.Num = num;
    }

  | tCompound tSurface '(' FExpr ')' tAFFECT ListOfDouble tSTRING '{' RecursiveListOfListOfDouble '}' tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	List_T *S[4] = {0, 0, 0, 0};
	for (int i = 0; i < List_Nbr($10); i++){
	  List_T *ll;
	  List_Read($10, i, &ll);
	  S[i] = ListOfDouble2ListOfInt(ll);
          List_Delete(ll);
	}
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp, S);
	List_Delete(temp);
	for (int i = 0; i < List_Nbr($10); i++)
	  List_Delete(S[i]);
        List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete($7);
      List_Delete($10);
      Free($8);
      $$.Type = MSH_PHYSICAL_SURFACE;
      $$.Num = num;
    }
 //EMI ADDED
 | tCompound tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(0, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	List_T *S[4] = {0, 0, 0, 0};
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp, S);
	List_Delete(temp);
        List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_SURFACE;
      $$.Num = num;
    }
 // END EMI ADDED

  | tCompound tLine '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(0, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	List_T *S[4] = {temp, 0, 0, 0};
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp, S);
	List_Delete(temp);
        List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_LINE;
      $$.Num = num;
    }
  // Volumes

  // for backward compatibility:
  | tComplex tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      yymsg(0, "'Complex Volume' command is deprecated: use 'Volume' instead");
      int num = (int)$4;
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt($7);
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete($7);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindVolume(num)){
	yymsg(0, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt($6);
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(GModel::current()->getGEOInternals()->Volumes, &v);
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tPhysical tVolume 
    {
      curPhysDim = 3;
    }
    '(' PhysicalId ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$5;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(0, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($8);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(GModel::current()->getGEOInternals()->PhysicalGroups, &p);
      }
      List_Delete($8);
      $$.Type = MSH_PHYSICAL_VOLUME;
      $$.Num = num;
    }
;

//  T R A N S F O R M

Transform :
    tTranslate VExpr '{' MultipleShape '}'
    {
      TranslateShapes($2[0], $2[1], $2[2], $4);
      $$ = $4;
    }
  | tRotate '{' VExpr ',' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      RotateShapes($3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7, $10);
      $$ = $10;
    }
  | tSymmetry  VExpr '{' MultipleShape '}'
    {
      SymmetryShapes($2[0], $2[1], $2[2], $2[3], $4);
      $$ = $4;
    }
  | tDilate '{' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      DilatShapes($3[0], $3[1], $3[2], $5, $8);
      $$ = $8;
    }
  | tSTRING '{' MultipleShape '}'
    {
      $$ = List_Create(3, 3, sizeof(Shape));
      if(!strcmp($1, "Duplicata")){
        for(int i = 0; i < List_Nbr($3); i++){
          Shape TheShape;
          List_Read($3, i, &TheShape);
          CopyShape(TheShape.Type, TheShape.Num, &TheShape.Num);
          List_Add($$, &TheShape);
        }
      }
      else if(!strcmp($1, "Boundary")){
        BoundaryShapes($3, $$);
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
      IntersectCurvesWithSurface($4, (int)$8, $$);
      List_Delete($4);
    }
  | tSplit tLine '(' FExpr ')' '{' RecursiveListOfDouble '}' tEND
    {
      $$ = List_Create(2, 1, sizeof(Shape*));
      List_T *tmp = ListOfDouble2ListOfInt($7);
      List_Delete($7);
      SplitCurve((int)$4, tmp, $$);
      List_Delete(tmp);
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
	  else
	    yymsg(1, "Unknown point %d", TheShape.Num);
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
	  else
	    yymsg(1, "Unknown curve %d", TheShape.Num);
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
	  else
	    yymsg(1, "Unknown surface %d", TheShape.Num);
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
	  else
	    yymsg(1, "Unknown volume %d", TheShape.Num);
	}
      }
    }
;

//  D E L E T E

Delete :
    tDelete '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($3); i++){
	Shape TheShape;
	List_Read($3, i, &TheShape);
	DeleteShape(TheShape.Type, TheShape.Num);
      }
      List_Delete($3);
    }
  | tDelete tField '[' FExpr ']' tEND
    {
      GModel::current()->getFields()->deleteField((int)$4);
    }
  | tDelete tSTRING '[' FExpr ']' tEND
    {
#if !defined(HAVE_NO_POST)
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
  | tDelete tSTRING tEND
    {
      if(!strcmp($2, "Meshes") || !strcmp($2, "All")){
        for(unsigned int i = 0; i < GModel::list.size(); i++){
          GModel::list[i]->destroy();
          GModel::list[i]->getGEOInternals()->destroy();
        }
      }
      else if(!strcmp($2, "Model")){
	GModel::current()->destroy();
	GModel::current()->getGEOInternals()->destroy();
      }
      else if(!strcmp($2, "Physicals")){
	GModel::current()->getGEOInternals()->reset_physicals();
	GModel::current()->deletePhysicalGroups();
      }
      else if(!strcmp($2, "Variables")){
	gmsh_yysymbols.clear();
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
#if !defined(HAVE_NO_POST)
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
	ColorShape(TheShape.Type, TheShape.Num, $2);
      }
      List_Delete($4);      
    }
;

//  V I S I B I L I T Y

Visibility :
    tShow tBIGSTR tEND
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape($2, i, 1);
      Free($2);
    }
  | tHide tBIGSTR tEND
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape($2, i, 0);
      Free($2);
    }
  | tShow '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($3); i++){
	Shape TheShape;
	List_Read($3, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 1);
      }
      List_Delete($3);
    }
  | tHide '{' ListOfShapes '}'
    {
      for(int i = 0; i < List_Nbr($3); i++){
	Shape TheShape;
	List_Read($3, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, 0);
      }
      List_Delete($3);
    }
;

//  C O M M A N D  

Command :
    tSTRING StringExpr tEND
    {
      if(!strcmp($1, "Include")){
	char tmpstring[1024];
	FixRelativePath($2, tmpstring);
	// Warning: we *don't* close included files (to allow user
	// functions in these files). If you need to include many many
	// files and don't have functions in the files, use "Merge"
	// instead: some OSes limit the number of files a process can
	// open simultaneously. The right solution would be of course
	// to modify FunctionManager to reopen the files instead of
	// using the FILE pointer, but hey, I'm lazy...
	Msg::StatusBar(2, true, "Reading '%s'", tmpstring);
	ParseFile(tmpstring, false, true);
	SetBoundingBox();
	Msg::StatusBar(2, true, "Read '%s'", tmpstring);
      }
      else if(!strcmp($1, "Print")){
#if defined(HAVE_FLTK)
	// make sure we have the latest data from GEO_Internals in GModel
	// (fixes bug where we would have no geometry in the picture if
	// the print command is in the same file as the geometry)
	GModel::current()->importGEOInternals();
	char tmpstring[1024];
	FixRelativePath($2, tmpstring);
	CreateOutputFile(tmpstring, CTX::instance()->print.format);
#endif
      }
      else if(!strcmp($1, "Save")){
#if defined(HAVE_FLTK)
	GModel::current()->importGEOInternals();
	char tmpstring[1024];
	FixRelativePath($2, tmpstring);
	CreateOutputFile(tmpstring, CTX::instance()->mesh.format);
#endif
      }
      else if(!strcmp($1, "Merge") || !strcmp($1, "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
	char tmpstring[1024];
	FixRelativePath($2, tmpstring);
	MergeFile(tmpstring, true);
      }
      else if(!strcmp($1, "System"))
	SystemCall($2);
      else
	yymsg(0, "Unknown command '%s'", $1);
      Free($1); Free($2);
    } 
  | tSTRING tSTRING '[' FExpr ']' StringExprVar tEND
    {
#if !defined(HAVE_NO_POST)
      if(!strcmp($1, "Save") && !strcmp($2, "View")){
	int index = (int)$4;
	if(index >= 0 && index < (int)PView::list.size()){
	  char tmpstring[1024];
	  FixRelativePath($6, tmpstring);
	  PView::list[index]->write(tmpstring, CTX::instance()->post.fileFormat);
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
#if !defined(HAVE_NO_POST)
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
      else
	yymsg(0, "Unknown command '%s'", $1);
      Free($1);
    }
   | tPlugin '(' tSTRING ')' '.' tSTRING tEND
     {
#if !defined(HAVE_NO_POST)
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
#if !defined(HAVE_NO_POST)
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
      exit(0);
    } 
   | tSyncModel tEND
    {
      // FIXME: this is a hack to force a transfer from the old DB to
      // the new DB. This will become unnecessary if/when we fill the 
      // GModel directly during parsing.
      GModel::current()->importGEOInternals();
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
#if defined(HAVE_FLTK)
      Draw();
#endif
    }
   | tCreateTopology tEND
    {
       GModel::current()->createTopologyFromMesh();
    }
;

// L O O P  

Loop :
    tFor '(' FExpr tDOTS FExpr ')'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $3;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
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
      gmsh_yysymbols[$2].resize(1);
      gmsh_yysymbols[$2][0] = $5;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if($5 > $7) 
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr tDOTS FExpr '}' 
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $5;
      LoopControlVariablesTab[ImbricatedLoop][1] = $7;
      LoopControlVariablesTab[ImbricatedLoop][2] = $9;
      LoopControlVariablesNameTab[ImbricatedLoop] = $2;
      gmsh_yysymbols[$2].resize(1);
      gmsh_yysymbols[$2][0] = $5;
      fgetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = gmsh_yylineno;
      if(($9 > 0. && $5 > $7) || ($9 < 0. && $5 < $7))
	skip_until("For", "EndFor");
      else
	ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS - 1){
	yymsg(0, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS - 1;
      }
    }
  | tEndFor 
    {
      if(ImbricatedLoop <= 0){
	yymsg(0, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double x0 = LoopControlVariablesTab[ImbricatedLoop - 1][0];
	double x1 = LoopControlVariablesTab[ImbricatedLoop - 1][1];
	double step = LoopControlVariablesTab[ImbricatedLoop - 1][2];
	int do_next = (step > 0.) ? (x0 + step <= x1) : (x0 + step >= x1);
	if(do_next){
	  LoopControlVariablesTab[ImbricatedLoop - 1][0] +=
	    LoopControlVariablesTab[ImbricatedLoop - 1][2];
	  if(LoopControlVariablesNameTab[ImbricatedLoop - 1]){
	    if(!gmsh_yysymbols.count(LoopControlVariablesNameTab[ImbricatedLoop - 1]))
	      yymsg(0, "Unknown loop variable");
	    else
	      gmsh_yysymbols[LoopControlVariablesNameTab[ImbricatedLoop - 1]][0] +=
		LoopControlVariablesTab[ImbricatedLoop - 1][2];
	  }
	  fsetpos(gmsh_yyin, &yyposImbricatedLoopsTab[ImbricatedLoop - 1]);
	  gmsh_yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop - 1];
	}
	else
	  ImbricatedLoop--;
      }
    }
  | tFunction tSTRING
    {
      if(!FunctionManager::Instance()->createFunction
         ($2, gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", $2);
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    }
  | tReturn
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    } 
  | tCall tSTRING tEND
    {
      if(!FunctionManager::Instance()->enterFunction
         ($2, &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function %s", $2);
      //FIXME: wee leak $2
    } 
  | tIf '(' FExpr ')'
    {
      if(!$3) skip_until("If", "EndIf");
    }
  | tEndIf
    {
    }
;


//  E X T R U D E 

Extrude :
    tExtrude VExpr '{' ListOfShapes '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE, $4, 
		    $2[0], $2[1], $2[2], 0., 0., 0., 0., 0., 0., 0.,
		    NULL, $$);
      List_Delete($4);
    }
  | tExtrude '{' VExpr ',' VExpr ',' FExpr '}' '{' ListOfShapes '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(ROTATE, $10, 
		    0., 0., 0., $3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7,
		    NULL, $$);
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
    }
                       ExtrudeParameters '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(BOUNDARY_LAYER, $3, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0.,
		    &extr, $$);
      List_Delete($3);
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
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = 1;
      extr.mesh.NbElmLayer.clear();
      extr.mesh.hLayer.clear();
      extr.mesh.NbElmLayer.push_back((int)fabs($3));
      extr.mesh.hLayer.push_back(1.);
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
      yymsg(0, "Explicit region numbers in layers are deprecated");
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
  | tRecombine tEND
    {
      extr.mesh.Recombine = true;
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
;

//  T R A N S F I N I T E ,   R E C O M B I N E   &   S M O O T H I N G

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
      else // alternated
        $$ = 0;
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

Transfinite : 
    tTransfinite tLine ListOfDoubleOrAll tAFFECT FExpr TransfiniteType tEND
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
            (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
          for(int sign = -1; sign <= 1; sign += 2){
            Curve *c = FindCurve(sign * j);
            if(c){
              c->Method = MESH_TRANSFINITE;
              c->nbPointsTransfinite = ($5 > 2) ? (int)$5 : 2;
              c->typeTransfinite = type * sign(d);
              c->coeffTransfinite = coef;
            }
            else{
              GEdge *ge = GModel::current()->getEdgeByTag(sign * j);
              if(ge){
                ge->meshAttributes.Method = MESH_TRANSFINITE;
                ge->meshAttributes.nbPointsTransfinite = ($5 > 2) ? (int)$5 : 2;
                ge->meshAttributes.typeTransfinite = type * sign(d);
                ge->meshAttributes.coeffTransfinite = coef;
              }
              else if(sign > 0)
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
              (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
                gf->meshAttributes.Method = MESH_TRANSFINITE;
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
              (*it)->meshAttributes.Method = MESH_TRANSFINITE;
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
                gr->meshAttributes.Method = MESH_TRANSFINITE;
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
;

//  E M B E D D I N G  C U R V E S   A N D  P O I N T S   I N T O   S U R F A C E S  
//    A N D   V O L U M E S

Embedding : 
    tPoint '{' RecursiveListOfDouble '}' tIn tSurface '{' FExpr '}' tEND
    { 
      Surface *s = FindSurface((int)$8);
      if(s){
	setSurfaceEmbeddedPoints(s, $3);
      }
      else{
        GFace *gf = GModel::current()->getFaceByTag((int)$8);
        if(gf){
          for(int i = 0; i < List_Nbr($3); i++){
            int iPoint;
            List_Read($3, i, &iPoint);
            GVertex *gv = GModel::current()->getVertexByTag(iPoint);
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
            int iCurve;
            List_Read($3, i, &iCurve);
            GEdge *ge = GModel::current()->getEdgeByTag(iCurve);
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
  | tLine '{' RecursiveListOfDouble '}' tIn tVolume '{' FExpr '}' tEND
    {
    }
  | tSurface '{' RecursiveListOfDouble '}' tIn tVolume '{' FExpr '}' tEND
    {
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
;


//  G E N E R A L

FExpr :
    FExpr_Single                     { $$ = $1;           }
  | '(' FExpr ')'                    { $$ = $2;           }
  | '-' FExpr %prec UNARYPREC        { $$ = -$2;          }
  | '+' FExpr %prec UNARYPREC        { $$ = $2;           }
  | '!' FExpr                        { $$ = !$2;          }
  | FExpr '-' FExpr                  { $$ = $1 - $3;      }
  | FExpr '+' FExpr                  { $$ = $1 + $3;      }
  | FExpr '*' FExpr                  { $$ = $1 * $3;      }
  | FExpr '/' FExpr
    { 
      if(!$3)
	yymsg(0, "Division by zero in '%g / %g'", $1, $3);
      else
	$$ = $1 / $3;     
    }
  | FExpr '%' FExpr                  { $$ = (int)$1 % (int)$3;  }
  | FExpr '^' FExpr                  { $$ = pow($1, $3);  }
  | FExpr '<' FExpr                  { $$ = $1 < $3;      }
  | FExpr '>' FExpr                  { $$ = $1 > $3;      }
  | FExpr tLESSOREQUAL FExpr         { $$ = $1 <= $3;     }
  | FExpr tGREATEROREQUAL FExpr      { $$ = $1 >= $3;     }
  | FExpr tEQUAL FExpr               { $$ = $1 == $3;     }
  | FExpr tNOTEQUAL FExpr            { $$ = $1 != $3;     }
  | FExpr tAND FExpr                 { $$ = $1 && $3;     }
  | FExpr tOR FExpr                  { $$ = $1 || $3;     }
  | FExpr '?' FExpr tDOTS FExpr      { $$ = $1 ? $3 : $5; }
  | tExp    '(' FExpr ')'            { $$ = exp($3);      }
  | tLog    '(' FExpr ')'            { $$ = log($3);      }
  | tLog10  '(' FExpr ')'            { $$ = log10($3);    }
  | tSqrt   '(' FExpr ')'            { $$ = sqrt($3);     }
  | tSin    '(' FExpr ')'            { $$ = sin($3);      }
  | tAsin   '(' FExpr ')'            { $$ = asin($3);     }
  | tCos    '(' FExpr ')'            { $$ = cos($3);      }
  | tAcos   '(' FExpr ')'            { $$ = acos($3);     }
  | tTan    '(' FExpr ')'            { $$ = tan($3);      }
  | tAtan   '(' FExpr ')'            { $$ = atan($3);     }
  | tAtan2  '(' FExpr ',' FExpr ')'  { $$ = atan2($3, $5);}
  | tSinh   '(' FExpr ')'            { $$ = sinh($3);     }
  | tCosh   '(' FExpr ')'            { $$ = cosh($3);     }
  | tTanh   '(' FExpr ')'            { $$ = tanh($3);     }
  | tFabs   '(' FExpr ')'            { $$ = fabs($3);     }
  | tFloor  '(' FExpr ')'            { $$ = floor($3);    }
  | tCeil   '(' FExpr ')'            { $$ = ceil($3);     }
  | tFmod   '(' FExpr ',' FExpr ')'  { $$ = fmod($3, $5); }
  | tModulo '(' FExpr ',' FExpr ')'  { $$ = fmod($3, $5); }
  | tHypot  '(' FExpr ',' FExpr ')'  { $$ = sqrt($3 * $3 + $5 * $5); }
  | tRand   '(' FExpr ')'            { $$ = $3 * (double)rand() / (double)RAND_MAX; }
  // The following is for GetDP compatibility
  | tExp    '[' FExpr ']'            { $$ = exp($3);      }
  | tLog    '[' FExpr ']'            { $$ = log($3);      }
  | tLog10  '[' FExpr ']'            { $$ = log10($3);    }
  | tSqrt   '[' FExpr ']'            { $$ = sqrt($3);     }
  | tSin    '[' FExpr ']'            { $$ = sin($3);      }
  | tAsin   '[' FExpr ']'            { $$ = asin($3);     }
  | tCos    '[' FExpr ']'            { $$ = cos($3);      }
  | tAcos   '[' FExpr ']'            { $$ = acos($3);     }
  | tTan    '[' FExpr ']'            { $$ = tan($3);      }
  | tAtan   '[' FExpr ']'            { $$ = atan($3);     }
  | tAtan2  '[' FExpr ',' FExpr ']'  { $$ = atan2($3, $5);}
  | tSinh   '[' FExpr ']'            { $$ = sinh($3);     }
  | tCosh   '[' FExpr ']'            { $$ = cosh($3);     }
  | tTanh   '[' FExpr ']'            { $$ = tanh($3);     }
  | tFabs   '[' FExpr ']'            { $$ = fabs($3);     }
  | tFloor  '[' FExpr ']'            { $$ = floor($3);    }
  | tCeil   '[' FExpr ']'            { $$ = ceil($3);     }
  | tFmod   '[' FExpr ',' FExpr ']'  { $$ = fmod($3, $5); }
  | tModulo '[' FExpr ',' FExpr ']'  { $$ = fmod($3, $5); }
  | tHypot  '[' FExpr ',' FExpr ']'  { $$ = sqrt($3 * $3 + $5 * $5); }
  | tRand   '[' FExpr ']'            { $$ = $3 * (double)rand() / (double)RAND_MAX; }
;

// FIXME: add +=, -=, *= et /=

FExpr_Single :

  // Constants

    tDOUBLE   { $$ = $1; }
  | tPi       { $$ = 3.141592653589793; }
  | tMPI_Rank { $$ = Msg::GetCommRank(); }
  | tMPI_Size { $$ = Msg::GetCommSize(); }
  | tGMSH_MAJOR_VERSION { $$ = GetGmshMajorVersion(); }
  | tGMSH_MINOR_VERSION { $$ = GetGmshMinorVersion(); }
  | tGMSH_PATCH_VERSION { $$ = GetGmshPatchVersion(); }

  // Variables

  | tSTRING
    {
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else
	$$ = gmsh_yysymbols[$1][0];
      Free($1);
    }
  // This is for GetDP compatibility (we should generalize it so
  // that we can create variables with this syntax, use them
  // recursively, etc., but I don't have time to do it now)
  | tSTRING '~' '{' FExpr '}'
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", $1, (int)$4) ;
      if(!gmsh_yysymbols.count(tmpstring)){
	yymsg(0, "Unknown variable '%s'", tmpstring);
	$$ = 0.;
      }
      else
	$$ = gmsh_yysymbols[tmpstring][0];
      Free($1);
    }
  | tSTRING '[' FExpr ']'
    {
      int index = (int)$3;
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else if(gmsh_yysymbols[$1].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", $1, index);
	$$ = 0.;
      }
      else
	$$ = gmsh_yysymbols[$1][index];
      Free($1);
    }
  | '#' tSTRING '[' ']'
    {
      if(!gmsh_yysymbols.count($2)){
	yymsg(0, "Unknown variable '%s'", $2);
	$$ = 0.;
      }
      else
	$$ = gmsh_yysymbols[$2].size();
      Free($2);
    }
  | tSTRING NumericIncrement
    {
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else
	$$ = (gmsh_yysymbols[$1][0] += $2);
      Free($1);
    }
  | tSTRING '[' FExpr ']' NumericIncrement
    {
      int index = (int)$3;
      if(!gmsh_yysymbols.count($1)){
	yymsg(0, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else if(gmsh_yysymbols[$1].size() < index + 1){
	yymsg(0, "Uninitialized variable '%s[%d]'", $1, index);
	$$ = 0.;
      }
      else
	$$ = (gmsh_yysymbols[$1][index] += $5);
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
  | tGetValue '(' tBIGSTR ',' FExpr ')'
    { 
      $$ = Msg::GetValue($3, $5);
      Free($3);
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
      if(!$5 || ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)){
        yymsg(0, "Wrong increment in '%g:%g:%g'", $1, $3, $5);
	List_Add($$, &($1));
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
	yymsg(0, "Unknown point '%d'", (int)$3);
	double d = 0.0;
	List_Add($$, &d);
	List_Add($$, &d);
	List_Add($$, &d);
      }
      else{
	List_Add($$, &v->Pos.X);
	List_Add($$, &v->Pos.Y);
	List_Add($$, &v->Pos.Z);
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
  | tSTRING '[' ']'
    {
      $$ = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1);
      else
	for(unsigned int i = 0; i < gmsh_yysymbols[$1].size(); i++)
	  List_Add($$, &gmsh_yysymbols[$1][i]);
      Free($1);
    }
  | tSTRING '[' '{' RecursiveListOfDouble '}' ']'
    {
      $$ = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count($1))
	yymsg(0, "Unknown variable '%s'", $1);
      else{
	for(int i = 0; i < List_Nbr($4); i++){
	  int index = (int)(*(double*)List_Pointer_Fast($4, i));
	  if(gmsh_yysymbols[$1].size() < index + 1)
	    yymsg(0, "Uninitialized variable '%s[%d]'", $1, index);
	  else
	    List_Add($$, &gmsh_yysymbols[$1][index]);
	}
      }
      Free($1);
      List_Delete($4);
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
      $$ = GetColorForString(ColorString, (int)$4, $2, &flag);
      if(flag) yymsg(0, "Unknown color '%s'", $2);
    }
*/
  | tSTRING
    {
      int flag;
      $$ = GetColorForString(ColorString, -1, $1, &flag);
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
  | tSTRING
    {
      if(!gmsh_yystringsymbols.count($1)){
	yymsg(0, "Unknown string variable '%s'", $1);
	$$ = $1;
      }
      else{
	std::string val = gmsh_yystringsymbols[$1];
	$$ = (char *)Malloc((val.size() + 1) * sizeof(char));
	strcpy($$, val.c_str());
	Free($1);
      }
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
  | tToday
    {
      $$ = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy($$, ctime(&now));
      $$[strlen($$) - 1] = '\0';
    }
  | tStrCat '(' StringExprVar ',' StringExprVar ')'
    {
      $$ = (char *)Malloc((strlen($3) + strlen($5) + 1) * sizeof(char));
      strcpy($$, $3);
      strcat($$, $5);
      Free($3);
      Free($5);
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
  | tSprintf '(' StringExprVar ')'
    {
      $$ = $3;
    }
  | tSprintf '(' StringExprVar ',' RecursiveListOfDouble ')'
    {
      char tmpstring[1024];
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
;

%%

int PrintListOfDouble(char *format, List_T *list, char *buffer)
{
  int j, k;
  char tmp1[256], tmp2[256];

  j = 0;
  buffer[j] = '\0';

  while(j < (int)strlen(format) && format[j] != '%') j++;
  strncpy(buffer, format, j); 
  buffer[j]='\0'; 
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
      return List_Nbr(list)-i;
  }
  if(j != (int)strlen(format))
    return -1;
  return 0;
}

gmshMatrix<double> ListOfListOfDouble2Matrix(List_T *list)
{
  int M = List_Nbr(list);
  int N = 0;
  for(int i = 0; i < M; i++){
    List_T *line = *(List_T**)List_Pointer_Fast(list, i);
    N = std::max(N, List_Nbr(line));
  }
  gmshMatrix<double> mat(M, N);
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

void FixRelativePath(const char *in, char *out)
{
  if(in[0] == '/' || in[0] == '\\' || (strlen(in)>2 && in[1] == ':')){
    // do nothing: 'in' is an absolute path
    strcpy(out, in);
  }
  else{
    // append 'in' to the path of the parent file
    strcpy(out, gmsh_yyname.c_str());
    int i = strlen(out) - 1 ;
    while(i >= 0 && gmsh_yyname.c_str()[i] != '/' && 
          gmsh_yyname.c_str()[i] != '\\') i-- ;
    out[i+1] = '\0';
    strcat(out, in);
  }
}

void yyerror(char *s)
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
  else
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
}
