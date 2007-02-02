%{
// $Id: Gmsh.y,v 1.258 2007-02-02 17:16:48 remacle Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <stdarg.h>
#include <time.h>
#include "PluginManager.h"
#include "ParUtil.h"
#include "Gmsh.h"
#include "Numeric.h"
#include "Context.h"
#include "GModel.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "GeoUtils.h"
#include "Generator.h"
#include "Draw.h"
#include "Views.h"
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
#include "Attractors.h"

Tree_T *Symbol_T = NULL;

extern Context_T CTX;
extern Mesh *THEM;
extern GModel *GMODEL;

static ExtrudeParams extr;

static Post_View *View;
static List_T *ViewValueList;
static double ViewCoord[100];
static int *ViewNumList, ViewNumNodes, ViewNumComp, ViewNumListTmp;
static int ViewCoordIdx, ViewElementIdx;
static int ViewErrorFlags[VIEW_NB_ELEMENT_TYPES];

#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

void yyerror(char *s);
void yymsg(int type, char *fmt, ...);
void skip_until(char *skip, char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
int CheckViewErrorFlags(Post_View *v);
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

%token tEND tAFFECT tDOTS tPi tMPI_Rank tMPI_Size
%token tExp tLog tLog10 tSqrt tSin tAsin tCos tAcos tTan tRand
%token tAtan tAtan2 tSinh tCosh tTanh tFabs tFloor tCeil
%token tFmod tModulo tHypot 
%token tPrintf tSprintf tStrCat tStrPrefix tStrRelative
%token tBoundingBox tDraw tToday
%token tPoint tCircle tEllipse tLine tSphere tSurface tSpline tVolume
%token tCharacteristic tLength tParametric tElliptic
%token tPlane tRuled tTransfinite tComplex tPhysical
%token tUsing tBump tProgression tPlugin 
%token tRotate tTranslate tSymmetry tDilate tExtrude tDuplicata
%token tLoop tRecombine tDelete tCoherence
%token tAttractor tLayers tAlias tAliasWithOptions
%token tText2D tText3D tInterpolationScheme tTime tGrain tCombine
%token tBSpline tBezier tNurbs tOrder tKnots
%token tColor tColorTable tFor tIn tEndFor tIf tEndIf tExit
%token tReturn tCall tFunction tShow tHide tGetValue
%token tGMSH_MAJOR_VERSION tGMSH_MINOR_VERSION tGMSH_PATCH_VERSION

%type <d> FExpr FExpr_Single 
%type <v> VExpr VExpr_Single
%type <i> NumericAffectation NumericIncrement PhysicalId
%type <u> ColorExpr
%type <c> StringExpr SendToFile
%type <l> FExpr_Multi ListOfDouble RecursiveListOfDouble
%type <l> RecursiveListOfListOfDouble 
%type <l> ListOfColor RecursiveListOfColor 
%type <l> ListOfShapes Duplicata Transform Extrude MultipleShape
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
  | Duplicata   { List_Delete($1); return 1; }
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
      $$ = "w";
    }
  | '>' '>'
    {
      $$ = "a";
    }
;

Printf :
    tPrintf '(' tBIGSTR ')' tEND
    {
      Msg(DIRECT, $3);
      Free($3);
    }
  | tPrintf '(' tBIGSTR ')' SendToFile StringExpr tEND
    {
      char tmpstring[1024];
      FixRelativePath($6, tmpstring);
      FILE *fp = fopen(tmpstring, $5);
      if(!fp){
	yymsg(GERROR, "Unable to open file '%s'", tmpstring);
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
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(GERROR, "%d extra argument%s in Printf", i, (i>1)?"s":"");
      else
	Msg(DIRECT, tmpstring);
      Free($3);
      List_Delete($5);
    }
  | tPrintf '(' tBIGSTR ',' RecursiveListOfDouble ')' SendToFile StringExpr tEND
    {
      char tmpstring[1024];
      int i = PrintListOfDouble($3, $5, tmpstring);
      if(i < 0) 
	yymsg(GERROR, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(GERROR, "%d extra argument%s in Printf", i, (i>1)?"s":"");
      else{
	char tmpstring2[1024];
	FixRelativePath($8, tmpstring2);
	FILE *fp = fopen(tmpstring2, $7);
	if(!fp){
	  yymsg(GERROR, "Unable to open file '%s'", tmpstring2);
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
      if(!strcmp($1, "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, $2);
      }
      Free($1); Free($2);
    }
  | tSTRING tBIGSTR tSTRING VExpr '{' Views '}' tEND
    {
      if(!strcmp($1, "View") && !CheckViewErrorFlags(View)){
	EndView(View, 0, yyname, $2);
      }
      Free($1); Free($2); Free($3);
    }  
;

Views :
    // nothing
    {
      View = BeginView(1); 
      for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++){
	ViewErrorFlags[i] = 0;
      }
    }
  | Views Element
  | Views Text2D
  | Views Text3D
  | Views InterpolationMatrix
  | Views Time
  | Views Grain
;

ElementCoords :
    FExpr
    { ViewCoord[ViewCoordIdx] = $1; ViewCoordIdx++; }
  | ElementCoords ',' FExpr
    { ViewCoord[ViewCoordIdx] = $3; ViewCoordIdx++; }
;

ElementValues :
    FExpr
    { if(ViewValueList) List_Add(ViewValueList, &$1); }
  | ElementValues ',' FExpr
    { if(ViewValueList) List_Add(ViewValueList, &$3); }
;

Element : 
    tSTRING 
    {
      if(!strcmp($1, "SP")){
	ViewElementIdx = 0; ViewNumNodes = 1; ViewNumComp = 1;
	ViewValueList = View->SP; ViewNumList = &View->NbSP;
      }
      else if(!strcmp($1, "VP")){
	ViewElementIdx = 1; ViewNumNodes = 1; ViewNumComp = 3;
	ViewValueList = View->VP; ViewNumList = &View->NbVP;
      }
      else if(!strcmp($1, "TP")){
	ViewElementIdx = 2; ViewNumNodes = 1; ViewNumComp = 9;
	ViewValueList = View->TP; ViewNumList = &View->NbTP;
      }
      else if(!strcmp($1, "SL")){
	ViewElementIdx = 3; ViewNumNodes = 2; ViewNumComp = 1;
	ViewValueList = View->SL; ViewNumList = &View->NbSL;
      }
      else if(!strcmp($1, "VL")){
	ViewElementIdx = 4; ViewNumNodes = 2; ViewNumComp = 3;
	ViewValueList = View->VL; ViewNumList = &View->NbVL;
      }
      else if(!strcmp($1, "TL")){
	ViewElementIdx = 5; ViewNumNodes = 2; ViewNumComp = 9;
	ViewValueList = View->TL; ViewNumList = &View->NbTL;
      }
      else if(!strcmp($1, "ST")){
	ViewElementIdx = 6; ViewNumNodes = 3; ViewNumComp = 1;
	ViewValueList = View->ST; ViewNumList = &View->NbST;
      }
      else if(!strcmp($1, "VT")){
	ViewElementIdx = 7; ViewNumNodes = 3; ViewNumComp = 3;
	ViewValueList = View->VT; ViewNumList = &View->NbVT;
      }
      else if(!strcmp($1, "TT")){
	ViewElementIdx = 8; ViewNumNodes = 3; ViewNumComp = 9;
	ViewValueList = View->TT; ViewNumList = &View->NbTT;
      }
      else if(!strcmp($1, "SQ")){
	ViewElementIdx = 9; ViewNumNodes = 4; ViewNumComp = 1;
	ViewValueList = View->SQ; ViewNumList = &View->NbSQ;
      }
      else if(!strcmp($1, "VQ")){
	ViewElementIdx = 10; ViewNumNodes = 4; ViewNumComp = 3;
	ViewValueList = View->VQ; ViewNumList = &View->NbVQ;
      }
      else if(!strcmp($1, "TQ")){
	ViewElementIdx = 11; ViewNumNodes = 4; ViewNumComp = 9;
	ViewValueList = View->TQ; ViewNumList = &View->NbTQ;
      }
      else if(!strcmp($1, "SS")){
	ViewElementIdx = 12; ViewNumNodes = 4; ViewNumComp = 1;
	ViewValueList = View->SS; ViewNumList = &View->NbSS;
      }
      else if(!strcmp($1, "VS")){
	ViewElementIdx = 13; ViewNumNodes = 4; ViewNumComp = 3;
	ViewValueList = View->VS; ViewNumList = &View->NbVS;
      }
      else if(!strcmp($1, "TS")){
	ViewElementIdx = 14; ViewNumNodes = 4; ViewNumComp = 9;
	ViewValueList = View->TS; ViewNumList = &View->NbTS;
      }
      else if(!strcmp($1, "SH")){
	ViewElementIdx = 15; ViewNumNodes = 8; ViewNumComp = 1;
	ViewValueList = View->SH; ViewNumList = &View->NbSH;
      }
      else if(!strcmp($1, "VH")){
	ViewElementIdx = 16; ViewNumNodes = 8; ViewNumComp = 3;
	ViewValueList = View->VH; ViewNumList = &View->NbVH;
      }
      else if(!strcmp($1, "TH")){
	ViewElementIdx = 17; ViewNumNodes = 8; ViewNumComp = 9;
	ViewValueList = View->TH; ViewNumList = &View->NbTH;
      }
      else if(!strcmp($1, "SI")){
	ViewElementIdx = 18; ViewNumNodes = 6; ViewNumComp = 1;
	ViewValueList = View->SI; ViewNumList = &View->NbSI;
      }
      else if(!strcmp($1, "VI")){
	ViewElementIdx = 19; ViewNumNodes = 6; ViewNumComp = 3;
	ViewValueList = View->VI; ViewNumList = &View->NbVI;
      }
      else if(!strcmp($1, "TI")){
	ViewElementIdx = 20; ViewNumNodes = 6; ViewNumComp = 9;
	ViewValueList = View->TI; ViewNumList = &View->NbTI;
      }
      else if(!strcmp($1, "SY")){
	ViewElementIdx = 21; ViewNumNodes = 5; ViewNumComp = 1;
	ViewValueList = View->SY; ViewNumList = &View->NbSY;
      }
      else if(!strcmp($1, "VY")){
	ViewElementIdx = 22; ViewNumNodes = 5; ViewNumComp = 3;
	ViewValueList = View->VY; ViewNumList = &View->NbVY;
      }
      else if(!strcmp($1, "TY")){
	ViewElementIdx = 23; ViewNumNodes = 5; ViewNumComp = 9;
	ViewValueList = View->TY; ViewNumList = &View->NbTY;
      }
      else if(!strcmp($1, "SL2")){
	ViewElementIdx = 3; ViewNumNodes = 3; ViewNumComp = 1;
	ViewValueList = View->SL2; ViewNumList = &View->NbSL2;
      }
      else if(!strcmp($1, "VL2")){
	ViewElementIdx = 4; ViewNumNodes = 3; ViewNumComp = 3;
	ViewValueList = View->VL2; ViewNumList = &View->NbVL2;
      }
      else if(!strcmp($1, "TL2")){
	ViewElementIdx = 5; ViewNumNodes = 3; ViewNumComp = 9;
	ViewValueList = View->TL2; ViewNumList = &View->NbTL2;
      }
      else if(!strcmp($1, "ST2")){
	ViewElementIdx = 6; ViewNumNodes = 6; ViewNumComp = 1;
	ViewValueList = View->ST2; ViewNumList = &View->NbST2;
      }
      else if(!strcmp($1, "VT2")){
	ViewElementIdx = 7; ViewNumNodes = 6; ViewNumComp = 3;
	ViewValueList = View->VT2; ViewNumList = &View->NbVT2;
      }
      else if(!strcmp($1, "TT2")){
	ViewElementIdx = 8; ViewNumNodes = 6; ViewNumComp = 9;
	ViewValueList = View->TT2; ViewNumList = &View->NbTT2;
      }
      else if(!strcmp($1, "SQ2")){
	ViewElementIdx = 9; ViewNumNodes = 9; ViewNumComp = 1;
	ViewValueList = View->SQ2; ViewNumList = &View->NbSQ2;
      }
      else if(!strcmp($1, "VQ2")){
	ViewElementIdx = 10; ViewNumNodes = 9; ViewNumComp = 3;
	ViewValueList = View->VQ2; ViewNumList = &View->NbVQ2;
      }
      else if(!strcmp($1, "TQ2")){
	ViewElementIdx = 11; ViewNumNodes = 9; ViewNumComp = 9;
	ViewValueList = View->TQ2; ViewNumList = &View->NbTQ2;
      }
      else if(!strcmp($1, "SS2")){
	ViewElementIdx = 12; ViewNumNodes = 10; ViewNumComp = 1;
	ViewValueList = View->SS2; ViewNumList = &View->NbSS2;
      }
      else if(!strcmp($1, "VS2")){
	ViewElementIdx = 13; ViewNumNodes = 10; ViewNumComp = 3;
	ViewValueList = View->VS2; ViewNumList = &View->NbVS2;
      }
      else if(!strcmp($1, "TS2")){
	ViewElementIdx = 14; ViewNumNodes = 10; ViewNumComp = 9;
	ViewValueList = View->TS2; ViewNumList = &View->NbTS2;
      }
      else if(!strcmp($1, "SH2")){
	ViewElementIdx = 15; ViewNumNodes = 27; ViewNumComp = 1;
	ViewValueList = View->SH2; ViewNumList = &View->NbSH2;
      }
      else if(!strcmp($1, "VH2")){
	ViewElementIdx = 16; ViewNumNodes = 27; ViewNumComp = 3;
	ViewValueList = View->VH2; ViewNumList = &View->NbVH2;
      }
      else if(!strcmp($1, "TH2")){
	ViewElementIdx = 17; ViewNumNodes = 27; ViewNumComp = 9;
	ViewValueList = View->TH2; ViewNumList = &View->NbTH2;
      }
      else if(!strcmp($1, "SI2")){
	ViewElementIdx = 18; ViewNumNodes = 18; ViewNumComp = 1;
	ViewValueList = View->SI2; ViewNumList = &View->NbSI2;
      }
      else if(!strcmp($1, "VI2")){
	ViewElementIdx = 19; ViewNumNodes = 18; ViewNumComp = 3;
	ViewValueList = View->VI2; ViewNumList = &View->NbVI2;
      }
      else if(!strcmp($1, "TI2")){
	ViewElementIdx = 20; ViewNumNodes = 18; ViewNumComp = 9;
	ViewValueList = View->TI2; ViewNumList = &View->NbTI2;
      }
      else if(!strcmp($1, "SY2")){
	ViewElementIdx = 21; ViewNumNodes = 14; ViewNumComp = 1;
	ViewValueList = View->SY2; ViewNumList = &View->NbSY2;
      }
      else if(!strcmp($1, "VY2")){
	ViewElementIdx = 22; ViewNumNodes = 14; ViewNumComp = 3;
	ViewValueList = View->VY2; ViewNumList = &View->NbVY2;
      }
      else if(!strcmp($1, "TY2")){
	ViewElementIdx = 23; ViewNumNodes = 14; ViewNumComp = 9;
	ViewValueList = View->TY2; ViewNumList = &View->NbTY2;
      }
      else{
	yymsg(GERROR, "Unknown element type '%s'", $1);	
	ViewElementIdx = -1; ViewNumNodes = 0; ViewNumComp = 0;
	ViewValueList = NULL; ViewNumList = NULL;
      }
      Free($1);
      ViewCoordIdx = 0;
    }
    '(' ElementCoords ')'
    {
      if(ViewValueList){
	if(ViewCoordIdx != 3 * ViewNumNodes){
	  yymsg(GERROR, "Wrong number of node coordinates (%d != %d)", 
		ViewCoordIdx, 3 * ViewNumNodes);
	  double d = 0;
	  for(int i = 0; i < 3 * ViewNumNodes; i++)
	    List_Add(ViewValueList, &d);
	}
	else{
	  for(int i = 0; i < 3; i++)
	    for(int j = 0; j < ViewNumNodes; j++)
	      List_Add(ViewValueList, &ViewCoord[3*j+i]);
	}
	ViewNumListTmp = List_Nbr(ViewValueList);
      }
    }
    '{' ElementValues '}' tEND
    {
      if(ViewValueList){  
	if((List_Nbr(ViewValueList) - ViewNumListTmp) % (ViewNumComp * ViewNumNodes)) 
	  ViewErrorFlags[ViewElementIdx]++;
	(*ViewNumList)++;
      }
    }
;

Text2DValues :
    StringExpr
    { 
      for(int i = 0; i < (int)strlen($1)+1; i++) List_Add(View->T2C, &$1[i]); 
      Free($1);
    }
  | Text2DValues ',' StringExpr
    { 
      for(int i = 0; i < (int)strlen($3)+1; i++) List_Add(View->T2C, &$3[i]); 
      Free($3);
    }
;

Text2D : 
    tText2D '(' FExpr ',' FExpr ',' FExpr ')'
    { 
      List_Add(View->T2D, &$3); List_Add(View->T2D, &$5);
      List_Add(View->T2D, &$7); 
      double d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    }
    '{' Text2DValues '}' tEND
    {
      View->NbT2++;
    }
;

Text3DValues :
    StringExpr
    { 
      for(int i = 0; i < (int)strlen($1)+1; i++) List_Add(View->T3C, &$1[i]); 
      Free($1);
    }
  | Text3DValues ',' StringExpr
    { 
      for(int i = 0; i < (int)strlen($3)+1; i++) List_Add(View->T3C, &$3[i]); 
      Free($3);
    }
;

Text3D : 
    tText3D '(' FExpr ',' FExpr ',' FExpr ',' FExpr ')'
    { 
      List_Add(View->T3D, &$3); List_Add(View->T3D, &$5);
      List_Add(View->T3D, &$7); List_Add(View->T3D, &$9); 
      double d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    }
    '{' Text3DValues '}' tEND
    {
      View->NbT3++;
    }
;

InterpolationMatrix :
    tInterpolationScheme '{' RecursiveListOfListOfDouble '}' 
                         '{' RecursiveListOfListOfDouble '}'  tEND
    {
      View->adaptive = new Adaptive_Post_View(View, $3, $6);
    }
;

Time :
    tTime 
    {
      ViewValueList = View->Time;
    }
   '{' ElementValues '}' tEND
    {
    }
;
Grain :
    tGrain '(' FExpr ')'  ListOfDouble  tEND
    {
      (*View->Grains) [(int)$3] = $5;
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
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	if(!$2){
	  TheSymbol.val = List_Create(1, 1, sizeof(double));
	  List_Put(TheSymbol.val, 0, &$3);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else{
	  yymsg(GERROR, "Unknown variable '%s'", $1);
	  Free($1);
	}
      }
      else{
	double *pd = (double*)List_Pointer_Fast(pSymbol->val, 0); 
	switch($2){
	case 0 : *pd = $3; break;
	case 1 : *pd += $3; break;
	case 2 : *pd -= $3; break;
	case 3 : *pd *= $3; break;
	case 4 : 
	  if($3) *pd /= $3; 
	  else yymsg(GERROR, "Division by zero in '%s /= %g'", $1, $3);
	  break;
	}
	Free($1);
      }
    }
  | tSTRING '[' FExpr ']' NumericAffectation FExpr tEND
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	if(!$5){
	  TheSymbol.val = List_Create(5, 5, sizeof(double));
	  List_Put(TheSymbol.val, (int)$3, &$6);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else{
	  yymsg(GERROR, "Unknown variable '%s'", $1);
	  Free($1);
	}
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3))){
	  switch($5){
	  case 0 : *pd = $6; break;
	  case 1 : *pd += $6; break;
	  case 2 : *pd -= $6; break;
	  case 3 : *pd *= $6; break;
	  case 4 : 
	    if($6) *pd /= $6; 
	    else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", $1, (int)$3, $6);
	    break;
	  }
	}
	else{
	  if(!$5)
	    List_Put(pSymbol->val, (int)$3, &$6);
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", $1, (int)$3);
	}
	Free($1);
      }
    }
  | tSTRING '[' '{' RecursiveListOfDouble '}' ']' NumericAffectation ListOfDouble tEND
    {
      if(List_Nbr($4) != List_Nbr($8)){
	yymsg(GERROR, "Incompatible array dimensions in affectation");
	Free($1);
      }
      else{
	Symbol TheSymbol;
	TheSymbol.Name = $1;
	Symbol *pSymbol;
	if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	  if(!$7){
	    TheSymbol.val = List_Create(5, 5, sizeof(double));
	    for(int i = 0; i < List_Nbr($4); i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer($4, i)),
		       (double*)List_Pointer($8, i));
	    }
	    Tree_Add(Symbol_T, &TheSymbol);
	  }
	  else{
	    yymsg(GERROR, "Unknown variable '%s'", $1);
	    Free($1);
	  }
	}
	else{
	  for(int i = 0; i < List_Nbr($4); i++){
	    int j = (int)(*(double*)List_Pointer($4, i));
	    double d = *(double*)List_Pointer($8, i);
	    double *pd;
	    if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	      switch($7){
	      case 0 : *pd = d; break;
	      case 1 : *pd += d; break;
	      case 2 : *pd -= d; break;
	      case 3 : *pd *= d; break;
	      case 4 : 
		if($8) *pd /= d; 
		else yymsg(GERROR, "Division by zero in '%s[%d] /= %g'", $1, j, d);
		break;
	      }
	    }
	    else{
	      if(!$7)
		List_Put(pSymbol->val, j, &d);
	      else
		yymsg(GERROR, "Uninitialized variable '%s[%d]'", $1, j);	  
	    }
	  }
	  Free($1);
	}
      }
      List_Delete($4);
      List_Delete($8);
    }
  | tSTRING '[' ']' tAFFECT ListOfDouble tEND
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	List_Copy($5, TheSymbol.val);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Reset(pSymbol->val);
	List_Copy($5, pSymbol->val);
	Free($1);
      }
      List_Delete($5);
    }
  | tSTRING '[' ']' tAFFECTPLUS ListOfDouble tEND
    {
      // appends to the list
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	List_Copy($5, TheSymbol.val);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	for(int i = 0; i < List_Nbr($5); i++)
	  List_Add(pSymbol->val, List_Pointer($5, i));
	Free($1);
      }
      List_Delete($5);
    }
  | tSTRING NumericIncrement tEND
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", $1); 
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += $2;
      Free($1);
    }
  | tSTRING '[' FExpr ']' NumericIncrement tEND
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	yymsg(GERROR, "Unknown variable '%s'", $1); 
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  *pd += $5;
	else
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", $1, (int)$3);
      }
      Free($1);
    }

  // Option Strings

  | tSTRING '.' tSTRING tAFFECT StringExpr tEND 
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory($1)))
	yymsg(GERROR, "Unknown string option class '%s'", $1);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($3, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", $1, $3);
	else
	  pStrOpt(0, GMSH_SET|GMSH_GUI, $5);
      }
      Free($1); Free($3); //FIXME: somtimes leak $5
    }
  | tSTRING '[' FExpr ']' '.' tSTRING tAFFECT StringExpr tEND 
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory($1)))
	yymsg(GERROR, "Unknown string option class '%s'", $1);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($6, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", $1, (int)$3, $6);
	else
	  pStrOpt((int)$3, GMSH_SET|GMSH_GUI, $8);
      }
      Free($1); Free($6); //FIXME: somtimes leak $8
    }

  // Option Numbers

  | tSTRING '.' tSTRING NumericAffectation FExpr tEND 
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	yymsg(GERROR, "Unknown numeric option class '%s'", $1);
      else{
	if(!(pNumOpt = (double (*) (int, int, double))Get_NumberOption($3, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", $1, $3);
	else{
	  double d = 0;
	  switch($4){
	  case 0 : d = $5; break;
	  case 1 : d = pNumOpt(0, GMSH_GET, 0) + $5; break;
	  case 2 : d = pNumOpt(0, GMSH_GET, 0) - $5; break;
	  case 3 : d = pNumOpt(0, GMSH_GET, 0) * $5; break;
	  case 4 : 
	    if($5) d = pNumOpt(0, GMSH_GET, 0) / $5; 
	    else yymsg(GERROR, "Division by zero in '%s.%s /= %g'", $1, $3, $5);
	    break;
	  }
	  pNumOpt(0, GMSH_SET|GMSH_GUI, d);
	}
      }
      Free($1); Free($3);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING NumericAffectation FExpr tEND 
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	yymsg(GERROR, "Unknown numeric option class '%s'", $1);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($6, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", $1, (int)$3, $6);
	else{
	  double d = 0;
	  switch($7){
	  case 0 : d = $8; break;
	  case 1 : d = pNumOpt((int)$3, GMSH_GET, 0) + $8; break;
	  case 2 : d = pNumOpt((int)$3, GMSH_GET, 0) - $8; break;
	  case 3 : d = pNumOpt((int)$3, GMSH_GET, 0) * $8; break;
	  case 4 : 
	    if($8) d = pNumOpt((int)$3, GMSH_GET, 0) / $8;
	    else yymsg(GERROR, "Division by zero in '%s[%d].%s /= %g'", 
		       $1, (int)$3, $6, $8);
	    break;
	  }
	  pNumOpt((int)$3, GMSH_SET|GMSH_GUI, d);
	}
      }
      Free($1); Free($6);
    }
  | tSTRING '.' tSTRING NumericIncrement tEND 
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	yymsg(GERROR, "Unknown numeric option class '%s'", $1);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($3, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", $1, $3);
	else
	  pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+$4);
      }
      Free($1); Free($3);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING NumericIncrement tEND 
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	yymsg(GERROR, "Unknown numeric option class '%s'", $1);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($6, pNumCat)))
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", $1, (int)$3, $6);
	else
	  pNumOpt((int)$3, GMSH_SET|GMSH_GUI, pNumOpt((int)$3, GMSH_GET, 0)+$7);
      }
      Free($1); Free($6);
    }

  // Option Colors

  | tSTRING '.' tColor '.' tSTRING tAFFECT ColorExpr tEND 
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory($1)))
	yymsg(GERROR, "Unknown color option class '%s'", $1);
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption($5, pColCat)))
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", $1, $5);
	else
	  pColOpt(0, GMSH_SET|GMSH_GUI, $7);
      }
      Free($1); Free($5);
    }
  | tSTRING '[' FExpr ']' '.' tColor '.' tSTRING tAFFECT ColorExpr tEND 
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory($1)))
	yymsg(GERROR, "Unknown color option class '%s'", $1);
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption($8, pColCat)))
	  yymsg(GERROR, "Unknown color option '%s[%d].Color.%s'", $1, (int)$3, $8);
	else
	  pColOpt((int)$3, GMSH_SET|GMSH_GUI, $10);
      }
      Free($1); Free($8);
    }

  // ColorTable

  | tSTRING '.' tColorTable tAFFECT ListOfColor tEND 
    {
      GmshColorTable *ct = Get_ColorTable(0);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr($5);
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(GERROR, "Too many (%d>%d) colors in View[%d].ColorTable", 
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
      GmshColorTable *ct = Get_ColorTable((int)$3);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)$3);
      else{
	ct->size = List_Nbr($8);
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  yymsg(GERROR, "Too many (%d>%d) colors in View[%d].ColorTable", 
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

  // Plugins

  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT FExpr tEND 
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption($3, $6, $8); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", $6, $3);
      }
      Free($3); Free($6);
    }
  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT StringExpr tEND 
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption($3, $6, $8); 
      }
      catch (...) {
	yymsg(GERROR, "Unknown option '%s' or plugin '%s'", $6, $3);
      }
      Free($3); Free($6); // FIXME: sometimes leak $8
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
      $$ = GMODEL->setPhysicalName(std::string($1), ++THEM->MaxPhysicalNum);
      Free($1);
    }
;


Shape :

  // Points

    tPoint '(' FExpr ')' tAFFECT VExpr tEND
    {
      int num = (int)$3;
      if(FindPoint(num)){
	yymsg(GERROR, "Point %d already exists", num);
      }
      else{
	double x = CTX.geom.scaling_factor * $6[0];
	double y = CTX.geom.scaling_factor * $6[1];
	double z = CTX.geom.scaling_factor * $6[2];
	double lc = CTX.geom.scaling_factor * $6[3];
	Vertex *v = Create_Vertex(num, x, y, z, lc, 1.0);
	Tree_Add(THEM->Points, &v);
	AddToTemporaryBoundingBox(x, y, z);
      }
      $$.Type = MSH_POINT;
      $$.Num = num;
    }
  | tPoint '(' FExpr ')' tIn tSurface '{' FExpr '}' tAFFECT VExpr tEND
    {
      int num = (int)$3;
      if(FindPoint(num)){
	yymsg(GERROR, "Point %d already exists", num);
      }
      else{
	double u = CTX.geom.scaling_factor * $11[0];
	double v = CTX.geom.scaling_factor * $11[1];
	double lc = CTX.geom.scaling_factor * $11[2];
	gmshSurface *surf = gmshSurface::surfaceByTag((int)$8);
	if(!surf)
	  yymsg(GERROR, "gmshSurface %d does not exist", (int)$8);
	Vertex *vt = Create_Vertex(num, u, v, surf, lc);
	Tree_Add(THEM->Points, &vt);
	AddToTemporaryBoundingBox(vt->Pos.X,vt->Pos.Y,vt->Pos.Z);
      }
      $$.Type = MSH_POINT;
      $$.Num = num;
    }
  | tPhysical tPoint '(' PhysicalId ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT)){
	yymsg(GERROR, "Physical point %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_POINT, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_POINT;
      $$.Num = num;
    }
  | tAttractor tPoint ListOfDouble tAFFECT ListOfDouble  tEND
    {
      double pars[] = { CTX.lc/10 , CTX.lc/100. , CTX.lc/20, 10 , 3 };

      for (int i=0;i<List_Nbr($5);i++)
	{
	  if (i > 4) 
	    yymsg(GERROR, "Too many paramaters for attractor line (max = 5)");	  
	  else
	    List_Read($5,i,&pars[i]);
	}

      Attractor *att = tresholdAttractor::New ( pars[0], pars[1],pars[2], pars[4] );

      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	Vertex *v = FindPoint((int)d); 
	
	// treshold attractor, the first parameter is the treshold and the
	// two other parameters are the in and out size fields
	if(v)
	  att->addPoint(v->Pos.X,v->Pos.Y,v->Pos.Z);
	else{
	  GVertex *gv = GMODEL->vertexByTag((int)d);
	  if(gv) 
	    att->addPoint(gv->x(),gv->y(),gv->z());
	}
      }
      att->buildFastSearchStructures();
      $$.Type = MSH_POINT_ATTRACTOR;
      $$.Num = 0;
    }
  | tAttractor tLine ListOfDouble tAFFECT ListOfDouble tEND
    {
      double pars[] = { CTX.lc/10 , CTX.lc/100. , CTX.lc/20, 10 , 3 };

      for (int i=0;i<List_Nbr($5);i++)
	{
	  if (i > 4) 
	    yymsg(GERROR, "Too many paramaters for attractor line (max = 5)");	  
	  else
	    List_Read($5,i,&pars[i]);
	}

      Attractor *att = tresholdAttractor::New ( pars[0], pars[1],pars[2], pars[4]);

      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	Curve *c = FindCurve((int)d); 
	
	// treshold attractor, the first parameter is the treshold and the
	// two other parameters are the in and out size fields
	if(c)
	  {
	    buildListOfPoints( att , c , (int) pars[3] );
	  }
	else{
	  GEdge *ge = GMODEL->edgeByTag((int)d);
	  if(ge) 
	    {
	      buildListOfPoints( att , ge , (int) pars[3] );
	    }
	}
      }
      att->buildFastSearchStructures();
      $$.Type = MSH_LINE_ATTRACTOR;
      $$.Num = 0;
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
	  GVertex *gv = GMODEL->vertexByTag((int)d);
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
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
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
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_SPLN;
      $$.Num = num;
    }
  | tCircle '(' FExpr ')'  tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_CIRC;
      $$.Num = num;
    }
  | tCircle '(' FExpr ')'  tAFFECT ListOfDouble tPlane VExpr tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	c->Circle.n[0] = $8[0];
	c->Circle.n[1] = $8[1];
	c->Circle.n[2] = $8[2];
	End_Curve(c);
	Tree_Add(THEM->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
	rc->Circle.n[0] = $8[0];
	rc->Circle.n[1] = $8[1];
	rc->Circle.n[2] = $8[2];
	End_Curve(rc);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_CIRC;
      $$.Num = num;
    }
  | tEllipse '(' FExpr ')'  tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_ELLI;
      $$.Num = num;
    }
  | tEllipse '(' FExpr ')'  tAFFECT ListOfDouble tPlane VExpr tEND
    {
      int num = (int)$3;
      if(FindCurve(num)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	c->Circle.n[0] = $8[0];
	c->Circle.n[1] = $8[1];
	c->Circle.n[2] = $8[2];
	End_Curve(c);
	Tree_Add(THEM->Curves, &c);
	Curve *rc = CreateReversedCurve(c);
	rc->Circle.n[0] = $8[0];
	rc->Circle.n[1] = $8[1];
	rc->Circle.n[2] = $8[2];
	End_Curve(c);
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
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	Curve *c = Create_Curve(num, MSH_SEGM_PARAMETRIC, 2, NULL, NULL,
				-1, -1, $7, $9);
	strcpy(c->functu, $11);
	strcpy(c->functv, $13);
	strcpy(c->functw, $15);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(c);
      }
      Free($11); Free($13); Free($15);
      $$.Type = MSH_SEGM_PARAMETRIC;
      $$.Num = num;
    }
  | tBSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(List_Nbr($6) < 4){
	yymsg(GERROR, "Too few control points for BSpline %d (%d < 4)", num,
	      List_Nbr($6));
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt($6);
	  Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_BSPLN;
      $$.Num = num;
    }
  | tBezier '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(List_Nbr($6) < 4){
	yymsg(GERROR, "Too few control points for Bezier curve %d (%d < 4)", num,
	      List_Nbr($6));
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt($6);
	  Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(c);
	  List_Delete(temp);
	}
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_BEZIER;
      $$.Num = num;
    }
  | tNurbs  '(' FExpr ')' tAFFECT ListOfDouble tKnots ListOfDouble tOrder FExpr tEND
    {
      int num = (int)$3;
      if(List_Nbr($6) + (int)$10 + 1 != List_Nbr($8)){
	yymsg(GERROR, "Wrong definition of Nurbs Curve %d: "
	      "got %d knots, need N + D + 1 = %d + %d + 1 = %d",
	      (int)$3, List_Nbr($8), List_Nbr($6), (int)$10, List_Nbr($6) + (int)$10 + 1);
      }
      else{
	if(FindCurve(num)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt($6);
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)$10, temp, $8,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
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
	yymsg(GERROR, "Line loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	sortEdgesInLoop(num, temp);
	EdgeLoop *l = Create_EdgeLoop(num, temp);
	Tree_Add(THEM->EdgeLoops, &l);
	List_Delete(temp);
      }
      List_Delete($7);
      $$.Type = MSH_SEGM_LOOP;
      $$.Num = num;
    }
  | tPhysical tLine '(' PhysicalId ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE)){
	yymsg(GERROR, "Physical line %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_LINE, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_LINE;
      $$.Num = num;
    }

  // Surfaces

  | tPlane tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindSurface(num)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt($7);
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	End_Surface(s);
	Tree_Add(THEM->Surfaces, &s);
      }
      List_Delete($7);
      $$.Type = MSH_SURF_PLAN;
      $$.Num = num;
    }
  | tRuled tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4, type = 0;
      if(FindSurface(num)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read($7, 0, &d);
	EdgeLoop *el = FindEdgeLoop((int)fabs(d));
	if(!el){
	  yymsg(GERROR, "Unknown line loop %d", (int)d);
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
	    yymsg(GERROR, "Wrong definition of Ruled Surface %d: "
		  "%d borders instead of 3 or 4", num, j);
	    type = MSH_SURF_PLAN;
	  }
	  Surface *s = Create_Surface(num, type);
	  List_T *temp = ListOfDouble2ListOfInt($7);
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  End_Surface(s);
	  Tree_Add(THEM->Surfaces, &s);
	}
      }
      List_Delete($7);
      $$.Type = type;
      $$.Num = num;
    }
  | tSphere '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3, type = 0;
      if (List_Nbr($6) != 2){
	yymsg(GERROR, "Sphere %d has to be defined using 2 points (center + "
	      "any point) and not %d", num, List_Nbr($6));
      }
      else{
	double p1,p2;
	List_Read($6, 0, &p1);
	List_Read($6, 1, &p2);
	Vertex *v1 = FindPoint((int)p1);
	Vertex *v2 = FindPoint((int)p2);
	if(!v1) yymsg(GERROR, "Sphere %d : unknown point %d", num, (int)p1);
	if(!v2) yymsg(GERROR, "Sphere %d : unknown point %d", num, (int)p2);
	gmshSurface *myGmshSurface = gmshSphere::NewSphere
	  (num, v1->Pos.X, v1->Pos.Y, v1->Pos.Z,
	   sqrt((v2->Pos.X - v1->Pos.X) * (v2->Pos.X - v1->Pos.X) +
		(v2->Pos.Y - v1->Pos.Y) * (v2->Pos.Y - v1->Pos.Y) +
		(v2->Pos.Z - v1->Pos.Z) * (v2->Pos.Z - v1->Pos.Z)));
      }      
    }
  | tSurface tLoop '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindSurfaceLoop(num)){
	yymsg(GERROR, "Surface loop %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	SurfaceLoop *l = Create_SurfaceLoop(num, temp);
	Tree_Add(THEM->SurfaceLoops, &l);
	List_Delete(temp);
      }
      List_Delete($7);
      $$.Type = MSH_SURF_LOOP;
      $$.Num = num;
    }
  | tPhysical tSurface '(' PhysicalId ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE)){
	yymsg(GERROR, "Physical surface %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_SURFACE, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
      }
      List_Delete($7);
      $$.Type = MSH_PHYSICAL_SURFACE;
      $$.Num = num;
    }

  // Volumes

  // for backward compatibility:
  | tComplex tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindVolume(num)){
	yymsg(GERROR, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt($7);
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(THEM->Volumes, &v);
      }
      List_Delete($7);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindVolume(num)){
	yymsg(GERROR, "Volume %d already exists", num);
      }
      else{
	Volume *v = Create_Volume(num, MSH_VOLUME);
	List_T *temp = ListOfDouble2ListOfInt($6);
	setVolumeSurfaces(v, temp);
	List_Delete(temp);
	Tree_Add(THEM->Volumes, &v);
      }
      List_Delete($6);
      $$.Type = MSH_VOLUME;
      $$.Num = num;
    }
  | tPhysical tVolume '(' PhysicalId ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME)){
	yymsg(GERROR, "Physical volume %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($7);
	PhysicalGroup *p = Create_PhysicalGroup(num, MSH_PHYSICAL_VOLUME, temp);
	List_Delete(temp);
	List_Add(THEM->PhysicalGroups, &p);
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
      TranslateShapes($2[0], $2[1], $2[2], $4, 1);
      $$ = $4;
    }
  | tRotate '{' VExpr ',' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      RotateShapes($3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7, $10, 1);
      $$ = $10;
    }
  | tSymmetry  VExpr   '{' MultipleShape '}'
    {
      SymmetryShapes($2[0], $2[1], $2[2], $2[3], $4, 1);
      $$ = $4;
    }
  | tDilate '{' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      DilatShapes($3[0], $3[1], $3[2], $5, $8, 1);
      $$ = $8;
    }
;

MultipleShape : 
    Duplicata     { $$ = $1; }
  | ListOfShapes  { $$ = $1; }
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
	Vertex *v = FindPoint(TheShape.Num);
	if(!v)
	  yymsg(WARNING, "Unknown point %d", TheShape.Num);
	else{
	  TheShape.Type = MSH_POINT;
	  List_Add($$, &TheShape);
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
	Curve *c = FindCurve(TheShape.Num);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	else{
	  TheShape.Type = c->Typ;
	  List_Add($$, &TheShape);
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
	Surface *s = FindSurface(TheShape.Num);
	if(!s)
	  yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	else{
	  TheShape.Type = s->Typ;
	  List_Add($$, &TheShape);
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
	Volume *v = FindVolume(TheShape.Num);
	if(!v)
	  yymsg(WARNING, "Unknown volume %d", TheShape.Num);
	else{
	  TheShape.Type = v->Typ;
	  List_Add($$, &TheShape);
	}
      }
    }
;

//  D U P L I C A T A

Duplicata :
    tDuplicata '{' ListOfShapes '}'
    {
      $$ = List_Create(3, 3, sizeof(Shape));
      for(int i = 0; i < List_Nbr($3); i++){
	Shape TheShape;
	List_Read($3, i, &TheShape);
	int j;
	CopyShape(TheShape.Type, TheShape.Num, &j);
	TheShape.Num = j;
	List_Add($$, &TheShape);
      }
      List_Delete($3);
    }
  // for backward compatibility:
  | tDuplicata tSTRING '[' FExpr ']' tEND
    {
      if(!strcmp($2, "View")) AliasView((int)$4, 0);
      Free($2);
      $$ = NULL;
    }
  | tAlias tSTRING '[' FExpr ']' tEND
    {
      if(!strcmp($2, "View")) AliasView((int)$4, 0);
      Free($2);
      $$ = NULL;
    }
  | tAliasWithOptions tSTRING '[' FExpr ']' tEND
    {
      if(!strcmp($2, "View")) AliasView((int)$4, 1);
      Free($2);
      $$ = NULL;
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
  | tDelete tSTRING '[' FExpr ']' tEND
    {
      if(!strcmp($2, "View")){
	RemoveViewByIndex((int)$4);
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", $2);
      }
      Free($2);
    }
  | tDelete tSTRING tEND
    {
      if(!strcmp($2, "Meshes") || !strcmp($2, "All")){
	GMODEL->destroy();
	THEM->destroy();
      }
      else if(!strcmp($2, "Physicals")){
	List_Action(THEM->PhysicalGroups, Free_PhysicalGroup);
	List_Reset(THEM->PhysicalGroups);
	GMODEL->deletePhysicalGroups();
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s'", $2);
      }
      Free($2);
    }
  | tDelete tSTRING tSTRING tEND
    {
      if(!strcmp($2, "Empty") && !strcmp($3, "Views")){
	for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i--){
	  Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
	  if(v->empty())
	    RemoveViewByIndex(i);
	}
      }
      else{
	yymsg(GERROR, "Unknown command 'Delete %s %s'", $2, $3);
      }
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
    tShow StringExpr tEND
    {
      for(int i = 0; i < 4; i++)
	VisibilityShape($2, i, 1);
      Free($2);
    }
  | tHide StringExpr tEND
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
	Msg(STATUS2, "Reading '%s'", tmpstring);
	ParseFile(tmpstring, 0, 1);
	SetBoundingBox();
	Msg(STATUS2, "Read '%s'", tmpstring);
      }
      else if(!strcmp($1, "Print")){
#if defined(HAVE_FLTK)
	char tmpstring[1024];
	FixRelativePath($2, tmpstring);
	CreateOutputFile(tmpstring, CTX.print.format);
#endif
      }
      else if(!strcmp($1, "Save")){
#if defined(HAVE_FLTK)
	char tmpstring[1024];
	FixRelativePath($2, tmpstring);
	CreateOutputFile(tmpstring, CTX.mesh.format);
#endif
      }
      else if(!strcmp($1, "Merge") || !strcmp($1, "MergeWithBoundingBox")){
	// MergeWithBoundingBox is deprecated
	char tmpstring[1024];
	FixRelativePath($2, tmpstring);
	MergeFile(tmpstring, 1);
      }
      else if(!strcmp($1, "System")){
	SystemCall($2);
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", $1);
      }
      Free($1); Free($2);
    } 
  | tSTRING tSTRING '[' FExpr ']' StringExpr tEND
    {
      if(!strcmp($1, "Save") && !strcmp($2, "View")){
	Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, (int)$4);
	if(vv){
	  char tmpstring[1024];
	  FixRelativePath($6, tmpstring);
	  WriteView(*vv, tmpstring, CTX.post.file_format, 0);
	}
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", $1);
      }
      Free($1); Free($2); Free($6);
    }
  | tSTRING tSTRING tSTRING '[' FExpr ']' tEND
    {
      if(!strcmp($1, "Background") && !strcmp($2, "Mesh")  && !strcmp($3, "View")){
	Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, (int)$5);
	if(vv) BGMWithView(*vv);
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", $1);
      }
      Free($1); Free($2); Free($3);
    }
  | tSTRING FExpr tEND
    {
      if(!strcmp($1, "Sleep")){
	SleepInSeconds($2);
      }
      else if(!strcmp($1, "Remesh")){
	Msg(GERROR, "Surface ReMeshing must be reinterfaced");
	//	ReMesh();
      }
      else if(!strcmp($1, "Mesh")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else if(!strcmp($1, "Status")){
	yymsg(GERROR, "Mesh directives are not (yet) allowed in scripts");
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", $1);
      }
      Free($1);
    }
   | tPlugin '(' tSTRING ')' '.' tSTRING tEND
     {
       try {
	 GMSH_PluginManager::instance()->action($3, $6, 0);
       }
       catch(...) {
	 yymsg(GERROR, "Unknown action '%s' or plugin '%s'", $6, $3);
       }
       Free($3); Free($6);
     }
   | tCombine tSTRING tEND
    {
      if(!strcmp($2, "ElementsFromAllViews"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp($2, "ElementsFromVisibleViews"))
	CombineViews(0, 0, CTX.post.combine_remove_orig);
      else if(!strcmp($2, "ElementsByViewName"))
	CombineViews(0, 2, CTX.post.combine_remove_orig);
      else if(!strcmp($2, "TimeStepsFromAllViews"))
	CombineViews(1, 1, CTX.post.combine_remove_orig);
      else if(!strcmp($2, "TimeStepsFromVisibleViews"))
	CombineViews(1, 0, CTX.post.combine_remove_orig);
      else if(!strcmp($2, "TimeStepsByViewName"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else if(!strcmp($2, "Views"))
	CombineViews(0, 1, CTX.post.combine_remove_orig);
      else if(!strcmp($2, "TimeSteps"))
	CombineViews(1, 2, CTX.post.combine_remove_orig);
      else
	yymsg(GERROR, "Unknown 'Combine' command");
      Free($2);
    } 
   | tExit tEND
    {
      exit(0);
    } 
   | tBoundingBox tEND
    {
      CTX.forced_bbox = 0;
      SetBoundingBox();
    } 
   | tBoundingBox '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}' tEND
    {
      CTX.forced_bbox = 1;
      SetBoundingBox($3, $5, $7, $9, $11, $13);
    } 
   | tDraw tEND
    {
#if defined(HAVE_FLTK)
      Draw();
#endif
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
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if($3 > $5) skip_until("For", "EndFor");
    }
  | tFor '(' FExpr tDOTS FExpr tDOTS FExpr ')'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $3;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5;
      LoopControlVariablesTab[ImbricatedLoop][2] = $7;
      LoopControlVariablesNameTab[ImbricatedLoop] = NULL;
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if(($7 > 0. && $3 > $5) || ($7 < 0. && $3 < $5))
	skip_until("For", "EndFor");
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr '}' 
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $5;
      LoopControlVariablesTab[ImbricatedLoop][1] = $7;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0;
      LoopControlVariablesNameTab[ImbricatedLoop] = $2;
      Symbol TheSymbol;      
      TheSymbol.Name = $2;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	List_Put(TheSymbol.val, 0, &$5);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &$5);
      }
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if($5 > $7) skip_until("For", "EndFor");
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr tDOTS FExpr '}' 
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $5;
      LoopControlVariablesTab[ImbricatedLoop][1] = $7;
      LoopControlVariablesTab[ImbricatedLoop][2] = $9;
      LoopControlVariablesNameTab[ImbricatedLoop] = $2;
      Symbol TheSymbol;
      TheSymbol.Name = $2;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	List_Put(TheSymbol.val, 0, &$5);
	Tree_Add(Symbol_T, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &$5);
      }
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
      if(($9 > 0. && $5 > $7) || ($9 < 0. && $5 < $7))
	skip_until("For", "EndFor");
    }
  | tEndFor 
    {
      if(ImbricatedLoop <= 0){
	yymsg(GERROR, "Invalid For/EndFor loop");
	ImbricatedLoop = 0;
      }
      else{
	double x0 = LoopControlVariablesTab[ImbricatedLoop-1][0];
	double x1 = LoopControlVariablesTab[ImbricatedLoop-1][1];
	double step = LoopControlVariablesTab[ImbricatedLoop-1][2];
	int do_next = (step > 0.) ? (x0+step <= x1) : (x0+step >= x1);
	if(do_next){
	  LoopControlVariablesTab[ImbricatedLoop-1][0] +=
	    LoopControlVariablesTab[ImbricatedLoop-1][2];
	  if(LoopControlVariablesNameTab[ImbricatedLoop-1]){
	    Symbol TheSymbol;
	    TheSymbol.Name = LoopControlVariablesNameTab[ImbricatedLoop-1];
	    Symbol *pSymbol;
	    if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol)))
	      yymsg(GERROR, "Unknown loop variable");
	    else
	      *(double*)List_Pointer_Fast(pSymbol->val, 0) += 
		LoopControlVariablesTab[ImbricatedLoop-1][2];
	  }
	  fsetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop-1]);
	  yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop-1];
	}
	else{
	  ImbricatedLoop--;
	}
      }
    }
  | tFunction tSTRING
    {
      if(!FunctionManager::Instance()->createFunction($2, yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", $2);
      skip_until(NULL, "Return");
      //FIXME: wee leak $2
    }
  | tReturn
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin, yyname, yylineno))
	yymsg(GERROR, "Error while exiting function");
    } 
  | tCall tSTRING tEND
    {
      if(!FunctionManager::Instance()->enterFunction($2, &yyin, yyname, yylineno))
	yymsg(GERROR, "Unknown function %s", $2);
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                                                             ExtrudeParameters '}'
    {
      $$ = List_Create(2, 1, sizeof(Shape));
      ExtrudeShapes(TRANSLATE_ROTATE, $12, 
		    $3[0], $3[1], $3[2], $5[0], $5[1], $5[2], $7[0], $7[1], $7[2], $9,
		    &extr, $$);
      List_Delete($12);
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
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
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr($3);
      if(List_Nbr($3) == List_Nbr($5)){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr($3); i++){
	  List_Read($3, i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read($5, i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d}", 
	      List_Nbr($3), List_Nbr($5));
      }
      List_Delete($3);
      List_Delete($5);
    }
  | tLayers '{' ListOfDouble ',' ListOfDouble ',' ListOfDouble '}' tEND
    {
      yymsg(WARNING, "Explicit region numbers in layers are deprecated");
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr($3);
      if(List_Nbr($3) == List_Nbr($5) && List_Nbr($3) == List_Nbr($7)){
	extr.mesh.NbElmLayer.clear();
	extr.mesh.hLayer.clear();
	for(int i = 0; i < List_Nbr($3); i++){
	  List_Read($3, i, &d);
	  extr.mesh.NbElmLayer.push_back((d > 0) ? (int)d : 1);
	  List_Read($7, i, &d);
	  extr.mesh.hLayer.push_back(d);
	}
      }
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d, %d}", 
	      List_Nbr($3), List_Nbr($5), List_Nbr($7));
      }
      List_Delete($3);
      List_Delete($5);
      List_Delete($7);
    }
  | tRecombine tEND
    {
      extr.mesh.Recombine = true;
    }
;

//  T R A N S F I N I T E

Transfinite : 
    tTransfinite tLine ListOfDouble tAFFECT FExpr tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ($5>2)?(int)$5:2;
	  c->ipar[1] = sign(d);
	  c->dpar[0] = 1.0;
	}
      }
      List_Delete($3);
    }
  | tTransfinite tLine ListOfDouble tAFFECT FExpr tUsing tProgression FExpr tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ($5>2)?(int)$5:2;
	  c->ipar[1] = sign(d); /* Progresion : code 1 ou -1 */
	  c->dpar[0] = fabs($8);
	}
      }
      List_Delete($3);
    }
  | tTransfinite tLine ListOfDouble tAFFECT FExpr tUsing tBump FExpr tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	int j = (int)fabs(d);
        Curve *c = FindCurve(j);
	if(!c)
	  yymsg(WARNING, "Unknown curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = ($5>2)?(int)$5:2;
	  c->ipar[1] = 2*sign(d); /* Bump : code 2 ou -2 */
	  c->dpar[0] = fabs($8);
	}
      }
      List_Delete($3);
    }
  | tTransfinite tSurface '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Surface *s = FindSurface((int)$4);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)$4);
      else{
	s->Method = TRANSFINI;
	s->Recombine_Dir = -1;
	int k = List_Nbr($7);
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)$4, k);
	}
	else{
	  List_Reset(s->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete($7);
    }
  | tTransfinite tSurface '{' FExpr '}' tAFFECT ListOfDouble tSTRING tEND
    {
      Surface *s = FindSurface((int)$4);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)$4);
      else{
	s->Method = TRANSFINI;
	int k = List_Nbr($7);
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , (int)$4, k);
	}
	else{
	  List_Reset(s->TrsfPoints);
	  if (!strcmp($8, "Right"))
	    s->Recombine_Dir = 1;
	  else if (!strcmp($8, "Left"))
	    s->Recombine_Dir = -1;
	  else
	    s->Recombine_Dir = 0;
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete($7);
      Free($8);
    }
  | tElliptic tSurface '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      yymsg(WARNING, "Elliptic Surface is deprecated: use Transfinite instead (with smoothing)");
      List_Delete($7);
    }
  | tTransfinite tVolume '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Volume *v = FindVolume((int)$4);
      if(!v)
	yymsg(WARNING, "Unknown volume %d", (int)$4);
      else{
	v->Method = TRANSFINI;
	int k = List_Nbr($7);
	if(k != 6 && k != 8)
	  yymsg(GERROR, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , (int)$4, k);
	else{
	  List_Reset(v->TrsfPoints);
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    Vertex *vert = FindPoint(j);
	    if(!vert)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(v->TrsfPoints, &vert);
	  }
	}
      }
      List_Delete($7);
    }
  | tRecombine tSurface ListOfDouble tAFFECT FExpr tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	int j = (int)d;
	Surface *s = FindSurface(j);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = ($5 > 0 && $5 < 90) ? $5 : 90;
	}
      }
      List_Delete($3);
    }
  | tRecombine tSurface ListOfDouble tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	int j = (int)d;
        Surface *s = FindSurface(j);
	if(s){
	  s->Recombine = 1;
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
      if(s)
	setSurfaceEmbeddedPoints(s, $3);
    }
  | tLine '{' RecursiveListOfDouble '}' tIn tSurface '{' FExpr '}' tEND
    {
      Surface *s = FindSurface((int)$8);
      if(s)
	setSurfaceEmbeddedCurves(s, $3);
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
	yymsg(GERROR, "Division by zero in '%g / %g'", $1, $3);
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
  | FExpr '?' FExpr tDOTS FExpr      { $$ = $1? $3 : $5;  }
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
  | tHypot  '(' FExpr ',' FExpr ')'  { $$ = sqrt($3*$3+$5*$5); }
  | tRand   '(' FExpr ')'            { $$ = $3*(double)rand()/(double)RAND_MAX; }
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
  | tHypot  '[' FExpr ',' FExpr ']'  { $$ = sqrt($3*$3+$5*$5); }
  | tRand   '[' FExpr ']'            { $$ = $3*(double)rand()/(double)RAND_MAX; }
;

// FIXME: add +=, -=, *= et /=

FExpr_Single :

  // Constants

    tDOUBLE   { $$ = $1; }
  | tPi       { $$ = 3.141592653589793; }
  | tMPI_Rank { $$ = ParUtil::Instance()->rank(); }
  | tMPI_Size { $$ = ParUtil::Instance()->size(); }
  | tGMSH_MAJOR_VERSION { $$ = Get_GmshMajorVersion(); }
  | tGMSH_MINOR_VERSION { $$ = Get_GmshMinorVersion(); }
  | tGMSH_PATCH_VERSION { $$ = Get_GmshPatchVersion(); }

  // Variables

  | tSTRING
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else
	$$ = *(double*)List_Pointer_Fast(pSymbol->val, 0);
      Free($1);
    }
  // This is for GetDP compatibility (we should generalize it so
  // that we can create variables with this syntax, use them
  // recursively, etc., but I don't have time to do it now)
  | tSTRING '~' '{' FExpr '}'
    {
      char tmpstring[1024];
      sprintf(tmpstring, "%s_%d", $1, (int)$4) ;
      Symbol TheSymbol;
      TheSymbol.Name = tmpstring;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", tmpstring);
	$$ = 0.;
      }
      else
	$$ = *(double*)List_Pointer_Fast(pSymbol->val, 0);
      Free($1);
    }
  | tSTRING '[' FExpr ']'
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  $$ = *pd;
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", $1, (int)$3);
	  $$ = 0.;
	}
      }
      Free($1);
    }
  | '#' tSTRING '[' ']'
    {
      Symbol TheSymbol;
      TheSymbol.Name = $2;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $2);
	$$ = 0.;
      }
      else{
	$$ = List_Nbr(pSymbol->val);
      }
      Free($2);
    }
  | tSTRING NumericIncrement
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else
	$$ = (*(double*)List_Pointer_Fast(pSymbol->val, 0) += $2);
      Free($1);
    }
  | tSTRING '[' FExpr ']' NumericIncrement
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $1);
	$$ = 0.;
      }
      else{
	double *pd;
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  $$ = (*pd += $5);
	else{
	  yymsg(GERROR, "Uninitialized variable '%s[%d]'", $1, (int)$3);
	  $$ = 0.;
	}
      }
      Free($1);
    }

  // Option Strings

  | tSTRING '.' tSTRING 
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	yymsg(GERROR, "Unknown numeric option class '%s'", $1);
	$$ = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($3, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", $1, $3);
	  $$ = 0.;
	}
	else
	  $$ = pNumOpt(0, GMSH_GET, 0);
      }
      Free($1); Free($3);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING 
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	yymsg(GERROR, "Unknown numeric option class '%s'", $1);
	$$ = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($6, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", $1, (int)$3, $6);
	  $$ = 0.;
	}
	else
	  $$ = pNumOpt((int)$3, GMSH_GET, 0);
      }
      Free($1); Free($6);
    }
  | tSTRING '.' tSTRING NumericIncrement
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	yymsg(GERROR, "Unknown numeric option class '%s'", $1);
	$$ = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($3, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s.%s'", $1, $3);
	  $$ = 0.;
	}
	else
	  $$ = pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+$4);
      }
      Free($1); Free($3);
    }
  | tSTRING '[' FExpr ']' '.' tSTRING NumericIncrement
    {
      double (*pNumOpt)(int num, int action, double value);
      StringXNumber *pNumCat;
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	yymsg(GERROR, "Unknown numeric option class '%s'", $1);
	$$ = 0.;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($6, pNumCat))){
	  yymsg(GERROR, "Unknown numeric option '%s[%d].%s'", $1, (int)$3, $6);
	  $$ = 0.;
	}
	else
	  $$ = pNumOpt((int)$3, GMSH_SET|GMSH_GUI, pNumOpt((int)$3, GMSH_GET, 0)+$7);
      }
      Free($1); Free($6);
    }
  | tGetValue '(' tBIGSTR ',' FExpr ')'
    { 
      $$ = GetValue($3, $5);
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
      double *pd;
      for(int i = 0; i < List_Nbr($$); i++){
	pd = (double*)List_Pointer($$, i);
	(*pd) = - (*pd);
      }
    }
;

FExpr_Multi :
    FExpr tDOTS FExpr
    { 
      $$ = List_Create(2, 1, sizeof(double)); 
      for(double d = $1; ($1 < $3) ? (d <= $3) : (d >= $3); ($1 < $3) ? (d += 1.) : (d -= 1.)) 
	List_Add($$, &d);
    }
  | FExpr tDOTS FExpr tDOTS FExpr
    {
      $$ = List_Create(2, 1, sizeof(double)); 
      if(!$5 || ($1 < $3 && $5 < 0) || ($1 > $3 && $5 > 0)){
        yymsg(GERROR, "Wrong increment in '%g:%g:%g'", $1, $3, $5);
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
	yymsg(GERROR, "Unknown point '%d'", (int) $3);
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
  | Duplicata
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
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $1);
	double d = 0.0;
	List_Add($$, &d);
      }
      else{
	for(int i = 0; i < List_Nbr(pSymbol->val); i++)
	  List_Add($$, (double*)List_Pointer_Fast(pSymbol->val, i));
      }
      Free($1);
    }
  | '-' tSTRING '[' ']'
    {
      $$ = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = $2;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $2);
	double d = 0.0;
	List_Add($$, &d);
      }
      else{
	for(int i = 0; i < List_Nbr(pSymbol->val); i++){
	  double d = - *(double*)List_Pointer_Fast(pSymbol->val, i);
	  List_Add($$, &d);
	}
      }
      Free($2);
    }
  | tSTRING '[' '{' RecursiveListOfDouble '}' ']'
    {
      $$ = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $1);
	double d = 0.0;
	List_Add($$, &d);
      }
      else{
	for(int i = 0; i < List_Nbr($4); i++){
	  int j = (int)(*(double*)List_Pointer_Fast($4, i));
	  double *pd;
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j)))
	    List_Add($$, pd);
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", $1, j);	  
	}
      }
      Free($1);
      List_Delete($4);
    }
  | '-' tSTRING '[' '{' RecursiveListOfDouble '}' ']'
    {
      $$ = List_Create(2, 1, sizeof(double));
      Symbol TheSymbol;
      TheSymbol.Name = $2;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))) {
	yymsg(GERROR, "Unknown variable '%s'", $2);
	double d = 0.0;
	List_Add($$, &d);
      }
      else{
	for(int i = 0; i < List_Nbr($5); i++){
	  int j = (int)(*(double*)List_Pointer_Fast($5, i));
	  double *pd;
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	    double d = - *pd;
	    List_Add($$, &d);
	  }
	  else
	    yymsg(GERROR, "Uninitialized variable '%s[%d]'", $2, j);	  
	}
      }
      Free($2);
      List_Delete($5);
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
      $$ = CTX.PACK_COLOR((int)$2, (int)$4, (int)$6, (int)$8);
    }
  | '{' FExpr ',' FExpr ',' FExpr '}'
    {
      $$ = CTX.PACK_COLOR((int)$2, (int)$4, (int)$6, 255);
    }
/* shift/reduce conflict
  | '{' tSTRING ',' FExpr '}'
    {
      int flag;
      $$ = Get_ColorForString(ColorString, (int)$4, $2, &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", $2);
    }
*/
  | tSTRING
    {
      int flag;
      $$ = Get_ColorForString(ColorString, -1, $1, &flag);
      if(flag) yymsg(GERROR, "Unknown color '%s'", $1);
      Free($1);
    }
  | tSTRING '.' tColor '.' tSTRING 
    {
      unsigned int (*pColOpt)(int num, int action, unsigned int value);
      StringXColor *pColCat;
      if(!(pColCat = Get_ColorOptionCategory($1))){
	yymsg(GERROR, "Unknown color option class '%s'", $1);
	$$ = 0;
      }
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption($5, pColCat))){
	  yymsg(GERROR, "Unknown color option '%s.Color.%s'", $1, $5);
	  $$ = 0;
	}
	else{
	  $$ = pColOpt(0, GMSH_GET, 0);
	}
      }
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
      GmshColorTable *ct = Get_ColorTable((int)$3);
      if(!ct)
	yymsg(GERROR, "View[%d] does not exist", (int)$3);
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

StringExpr :
    tBIGSTR
    {
      $$ = $1;
    }
  | tToday
    {
      $$ = (char *)Malloc(32*sizeof(char));
      time_t now;
      time(&now);
      strcpy($$, ctime(&now));
      $$[strlen($$) - 1] = '\0';
    }
  | tStrCat '(' StringExpr ',' StringExpr ')'
    {
      $$ = (char *)Malloc((strlen($3)+strlen($5)+1)*sizeof(char));
      strcpy($$, $3);
      strcat($$, $5);
      Free($3);
      Free($5);
    }
  | tStrPrefix '(' StringExpr ')'
    {
      $$ = (char *)Malloc((strlen($3)+1)*sizeof(char));
      int i;
      for(i = strlen($3)-1; i >= 0; i--){
	if($3[i] == '.'){
	  strncpy($$, $3, i);
	  $$[i]='\0';
	  break;
	}
      }
      if(i <= 0) strcpy($$, $3);
      Free($3);
    }
  | tStrRelative '(' StringExpr ')'
    {
      $$ = (char *)Malloc((strlen($3)+1)*sizeof(char));
      int i;
      for(i = strlen($3)-1; i >= 0; i--){
	if($3[i] == '/' || $3[i] == '\\')
	  break;
      }
      if(i <= 0)
	strcpy($$, $3);
      else
	strcpy($$, &$3[i+1]);
      Free($3);
    }
  | tSprintf '(' StringExpr ')'
    {
      $$ = $3;
    }
  | tSprintf '(' StringExpr ',' RecursiveListOfDouble ')'
    {
      char tmpstring[1024];
      int i = PrintListOfDouble($3, $5, tmpstring);
      if(i < 0){
	yymsg(GERROR, "Too few arguments in Sprintf");
	$$ = $3;
      }
      else if(i > 0){
	yymsg(GERROR, "%d extra argument%s in Sprintf", i, (i>1)?"s":"");
	$$ = $3;
      }
      else{
	$$ = (char*)Malloc((strlen(tmpstring)+1)*sizeof(char));
	strcpy($$, tmpstring);
	Free($3);
      }
      List_Delete($5);
    }
  | tSprintf '(' tSTRING '.' tSTRING ')'
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory($3))){
	yymsg(GERROR, "Unknown string option class '%s'", $3);
	$$ = (char*)Malloc(sizeof(char));
	$$[0] = '\0';
      }
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($5, pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s.%s'", $3, $5);
	  $$ = (char*)Malloc(sizeof(char));
	  $$[0] = '\0';
	}
	else{
	  char *str = pStrOpt(0, GMSH_GET, NULL);
	  $$ = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy($$, str);
	}
      }
    }
  | tSprintf '(' tSTRING '[' FExpr ']' '.' tSTRING ')'
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory($3))){
	yymsg(GERROR, "Unknown string option class '%s'", $3);
	$$ = (char*)Malloc(sizeof(char));
	$$[0] = '\0';
      }
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($8, pStrCat))){
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", $3, (int)$5, $8);
	  $$ = (char*)Malloc(sizeof(char));
	  $$[0] = '\0';
	}
	else{
	  char *str = pStrOpt((int)$5, GMSH_GET, NULL);
	  $$ = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy($$, str);
	}
      }
    }
;

%%

void DeleteSymbol(void *a, void *b){
  Symbol *s = (Symbol*)a;
  Free(s->Name);
  List_Delete(s->val);
}

int CompareSymbols (const void *a, const void *b){
  return(strcmp(((Symbol*)a)->Name, ((Symbol*)b)->Name));
}

void InitSymbols(void){
  if(Symbol_T){
    Tree_Action(Symbol_T, DeleteSymbol);
    Tree_Delete(Symbol_T);
  }
  Symbol_T = Tree_Create(sizeof(Symbol), CompareSymbols);
}

int PrintListOfDouble(char *format, List_T *list, char *buffer){
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
    else{
      return List_Nbr(list)-i;
    }
  }
  if(j != (int)strlen(format))
    return -1;
  return 0;
}

int CheckViewErrorFlags(Post_View *v){
  if(View->adaptive) return 0; // hope for the best :-)

  char *name[8] = { "point", "line", "triangle", "quadrangle", 
		    "tetrahedron", "hexahedron", "prism", "pyramid" };
  char *type[3] = { "scalar", "vector", "tensor" };

  if(8 * 3 != VIEW_NB_ELEMENT_TYPES){
    Msg(GERROR, "Please upgrade CheckViewErrorFlags!");
    return 0;
  }
  
  for(int i = 0; i < VIEW_NB_ELEMENT_TYPES; i++)
    if(ViewErrorFlags[i])
      Msg(GERROR, "%d %s %s%s in View[%d] contain%s a wrong number of values",
	  ViewErrorFlags[i], type[i%3], name[i/3], (ViewErrorFlags[i] > 1) ? "s" : "",
	  v->Index, (ViewErrorFlags[i] > 1) ? "" : "s");
  
  return 0;
}

void yyerror(char *s){
  Msg(GERROR, "'%s', line %d : %s (%s)", yyname, yylineno-1, s, yytext);
  yyerrorstate++;
}

void yymsg(int type, char *fmt, ...){
  va_list args;
  char tmp[1024];

  va_start (args, fmt);
  vsprintf (tmp, fmt, args);
  va_end (args);

  Msg(type, "'%s', line %d : %s", yyname, yylineno-1, tmp);

  if(type == GERROR) yyerrorstate++;
}
