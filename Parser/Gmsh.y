%{
// $Id: Gmsh.y,v 1.205 2005-03-26 04:09:20 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
#include "Geo.h"
#include "GeoUtils.h"
#include "Nurbs.h"
#include "CAD.h"
#include "Mesh.h"
#include "Draw.h"
#include "Create.h"
#include "Views.h"
#include "StepGeomDatabase.h"
#include "Options.h"
#include "Colors.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "FunctionManager.h"
#include "ColorTable.h"
#include "Timer.h"
#include "CreateFile.h"
#include "Visibility.h"
#include "GmshVersion.h"

Tree_T *Symbol_T = NULL;

extern Context_T CTX;
extern Mesh *THEM;

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
%token tPoint tCircle tEllipse tLine tSurface tSpline tVolume
%token tCharacteristic tLength tParametric tElliptic
%token tPlane tRuled tTriangulation tTransfinite tComplex tPhysical
%token tUsing tBump tProgression tPlugin tDiscrete
%token tRotate tTranslate tSymmetry tDilate tExtrude tDuplicata
%token tLoop tRecombine tDelete tCoherence tIntersect
%token tAttractor tLayers tAlias tAliasWithOptions
%token tText2D tText3D tInterpolationScheme tTime tCombine
%token tBSpline tBezier tNurbs tOrder tWith tBounds tKnots
%token tColor tColorTable tFor tIn tEndFor tIf tEndIf tExit
%token tReturn tCall tFunction tTrimmed tShow tHide tGetValue
%token tGMSH_MAJOR_VERSION tGMSH_MINOR_VERSION tGMSH_PATCH_VERSION

%token tB_SPLINE_SURFACE_WITH_KNOTS
%token tB_SPLINE_CURVE_WITH_KNOTS
%token tCARTESIAN_POINT
%token tTRUE tFALSE tUNSPECIFIED tU tV tEDGE_CURVE tVERTEX_POINT tORIENTED_EDGE tPLANE
%token tFACE_OUTER_BOUND tEDGE_LOOP tADVANCED_FACE tVECTOR tDIRECTION tAXIS2_PLACEMENT_3D
%token tISO tENDISO tENDSEC tDATA tHEADER tFILE_DESCRIPTION tFILE_SCHEMA tFILE_NAME
%token tMANIFOLD_SOLID_BREP tCLOSED_SHELL tADVANCED_BREP_SHAPE_REPRESENTATION
%token tFACE_BOUND tCYLINDRICAL_SURFACE tCONICAL_SURFACE tCIRCLE tTRIMMED_CURVE
%token tGEOMETRIC_SET tCOMPOSITE_CURVE_SEGMENT tCOMPOSITE_CURVE_SEGMENT tCONTINUOUS
%token tCOMPOSITE_CURVE tTOROIDAL_SURFACE tPRODUCT_DEFINITION tPRODUCT_DEFINITION_SHAPE
%token tSHAPE_DEFINITION_REPRESENTATION tELLIPSE

%token tSolid tEndSolid tVertex tFacet tNormal tOuter tLoopSTL tEndLoop tEndFacet

%type <d> FExpr FExpr_Single SignedDouble
%type <v> VExpr VExpr_Single
%type <i> BoolExpr NumericAffectation NumericIncrement
%type <u> ColorExpr
%type <c> StringExpr
%type <l> FExpr_Multi ListOfDouble RecursiveListOfDouble
%type <l> ListOfListOfDouble RecursiveListOfListOfDouble 
%type <l> ListOfColor RecursiveListOfColor 
%type <l> ListOfShapes Duplicata Transform Extrude MultipleShape
%type <l> ListOfStrings
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
%left    tEQUAL tNOTEQUAL tAPPROXEQUAL
%left    '<' tLESSOREQUAL  '>' tGREATEROREQUAL
%left    '+' '-'
%left    '*' '/' '%' tCROSSPRODUCT
%right   '!' tPLUSPLUS tMINUSMINUS UNARYPREC
%right   '^'
%left    '(' ')' '[' ']' '.' '#'

%start All

%%

All : 
    StepFormatItems
  | StlFormatItems
  | GeoFormatItems
  | error tEND { yyerrok; return 1; }
;

//  S T E R E O L I T H O G R A P H Y  ( S T L )

SignedDouble :
    tDOUBLE     { $$ = $1; }
  | '-' tDOUBLE { $$ = -$2; }
;

StlFormatItems : 
    // nothing
  | StlFormatItems StlFormatItem
;

StlFormatItem : 
    tSolid
    {
      yymsg(INFO, "Reading STL solid");
      STLStartSolid();
      return 1;
    }
  | tFacet
    tNormal SignedDouble SignedDouble SignedDouble
    tOuter tLoopSTL
      tVertex SignedDouble SignedDouble SignedDouble
      tVertex SignedDouble SignedDouble SignedDouble
      tVertex SignedDouble SignedDouble SignedDouble
    tEndLoop
    tEndFacet
    {
      STLAddFacet($9, $10, $11, $13, $14, $15, $17, $18, $19,
		  $3, $4, $5);
      return 1;
    }
  | tEndSolid
    {
      STLEndSolid();
      yymsg(INFO, "Read STL solid");
      return 1;
    }
;

// S T E P   I S O - 1 0 3 0 3 - 2 1   F I L E   F O R M A T

// FIXME: The STEP interface is incomplete. All the strings and most
// of the lists are leaked in this (unused and unusable...) part of
// the parser.

StepFormatItems :
    // nothing
  | StepFormatItems StepFormatItem
;

StepFormatItem :
    StepSpecial { return 1; }
  | StepDataItem { return 1; }
  | StepHeaderItem { return 1; }
;

StepSpecial :
    tISO tEND
    {
      yymsg(INFO, "Reading Step Iso-10303-21 data");
      Create_Step_Solid_BRep();
    }
  | tENDISO tEND
    {
      Resolve_BREP ();
      yymsg(INFO, "Read Step Iso-10303-21 data");
    }
  | tDATA tEND
  | tENDSEC tEND
  | tHEADER tEND
;

StepHeaderItem :
    tFILE_DESCRIPTION '(' ListOfStrings ',' tBIGSTR ')' tEND
    {
    }
  | tFILE_SCHEMA '(' ListOfStrings ')' tEND
    {
    }
  | tFILE_NAME '(' tBIGSTR ',' tBIGSTR ',' ListOfStrings ',' 
                    ListOfStrings ',' tBIGSTR ',' tBIGSTR ',' tBIGSTR ')' tEND
    {
    }
;

StepDataItem  :
    tDOUBLE tAFFECT tCARTESIAN_POINT '(' tBIGSTR ',' VExpr ')' tEND
    {
      Add_Cartesian_Point((int)$1, $5, $7[0], $7[1], $7[2]);
    }
  | tDOUBLE tAFFECT tB_SPLINE_CURVE_WITH_KNOTS 
    '(' tBIGSTR ',' FExpr ',' ListOfDouble ',' BoolExpr ',' BoolExpr ',' 
        BoolExpr ',' ListOfDouble ',' ListOfDouble ',' BoolExpr ')' tEND
    {
      Add_BSpline_Curve_With_Knots ((int)$1, $5, (int) $7, $9,	$17, $19, 0., 1.);
    }
  | tDOUBLE tAFFECT tB_SPLINE_SURFACE_WITH_KNOTS 
    '(' tBIGSTR ',' FExpr ',' FExpr ',' ListOfListOfDouble ',' BoolExpr ',' 
        BoolExpr ',' BoolExpr ',' BoolExpr ',' ListOfDouble ',' ListOfDouble ',' 
        ListOfDouble ',' ListOfDouble ',' BoolExpr ')' tEND
    {
      Add_BSpline_Surface_With_Knots ((int)$1, $5, (int) $7, (int) $9, $11, $21,
				      $23, $25, $27, 0., 1., 0., 1. );
    }
  | tDOUBLE tAFFECT tEDGE_CURVE '(' tBIGSTR ',' tDOUBLE ','  tDOUBLE ',' 
                                    tDOUBLE ',' BoolExpr ')' tEND
    {
      Add_Edge_Curve ((int)$1, $5 , (int)$7 , (int)$9, (int)$11);
    }
  | tDOUBLE tAFFECT tFACE_OUTER_BOUND '(' tBIGSTR ',' tDOUBLE ','  BoolExpr  ')' tEND
    {
      Add_Face_Outer_Bound((int)$1, $5, (int)$7, $9, 1);
    }
  | tDOUBLE tAFFECT tFACE_BOUND '(' tBIGSTR ',' tDOUBLE ','  BoolExpr  ')' tEND
    {
      // check the norm! Face_Bound : hole outside surface!
      yymsg(INFO, "Found a face bound");
      Add_Face_Outer_Bound((int)$1, $5, (int)$7, $9, 0);
    }
  | tDOUBLE tAFFECT tORIENTED_EDGE '(' tBIGSTR ',' '*' ','  '*' ','  FExpr ',' 
                                       BoolExpr ')' tEND
    {
      Add_Oriented_Edge((int)$1, $5, (int)$11, $13);
    }
  | tDOUBLE tAFFECT tEDGE_LOOP '(' tBIGSTR ',' ListOfDouble ')' tEND
    {
      Add_Edge_Loop((int)$1, $5, $7);
    }
  | tDOUBLE tAFFECT tADVANCED_FACE '(' tBIGSTR ',' ListOfDouble ',' 
                                       tDOUBLE ',' BoolExpr ')' tEND
    {
      Add_Advanced_Face((int)$1, $5, $7, (int)$9, $11);
    }
  | tDOUBLE tAFFECT tVERTEX_POINT '(' tBIGSTR ',' tDOUBLE ')'  tEND
    {
      Add_Vertex_Point((int)$1, $5, (int)$7);
    }
  | tDOUBLE tAFFECT tVECTOR '(' tBIGSTR ',' tDOUBLE ',' FExpr ')'  tEND
    {
    }
  | tDOUBLE tAFFECT tAXIS2_PLACEMENT_3D '(' tBIGSTR ',' tDOUBLE ',' 
                                            tDOUBLE ',' tDOUBLE ')'  tEND
    {
      Add_Axis2_Placement3D  ((int)$1, (int)$9, (int)$11, (int)$7);
    }
  | tDOUBLE tAFFECT tDIRECTION '(' tBIGSTR ',' VExpr ')' tEND
    {
      Add_Direction((int)$1 , $5, $7[0], $7[1], $7[2]);
    }
  | tDOUBLE tAFFECT tPLANE '(' tBIGSTR ',' tDOUBLE ')' tEND
    {
      Add_Plane((int)$1, $5, (int)$7);
    }
  | tDOUBLE tAFFECT tLine '(' tBIGSTR ',' tDOUBLE ',' tDOUBLE ')'  tEND
    {
      Add_Line ((int)$1, $5 , (int) $7, (int)$9);
    }
  | tDOUBLE tAFFECT tCLOSED_SHELL '(' tBIGSTR ',' ListOfDouble ')' tEND
    {
      yymsg(INFO, "Found a closed shell");
      Add_Closed_Shell((int)$1, $5 , $7);
    }
  | tDOUBLE tAFFECT tADVANCED_BREP_SHAPE_REPRESENTATION
     '(' tBIGSTR ',' ListOfDouble ',' tDOUBLE')' tEND
    {
    }
  | tDOUBLE tAFFECT tMANIFOLD_SOLID_BREP '(' tBIGSTR ',' tDOUBLE ')' tEND
    {
    }
  | tDOUBLE tAFFECT tCYLINDRICAL_SURFACE '(' tBIGSTR ',' tDOUBLE ',' FExpr ')' tEND
    {
      Add_Cylinder ((int)$1, $5 , (int)$7, $9);
    }
  | tDOUBLE tAFFECT tCONICAL_SURFACE '(' tBIGSTR ',' tDOUBLE ',' FExpr ',' FExpr ')' tEND
    {
      Add_Cone ((int)$1, $5 , (int)$7, $9, $11);
    }
  | tDOUBLE tAFFECT tTOROIDAL_SURFACE '(' tBIGSTR ',' tDOUBLE ',' FExpr ',' FExpr ')' tEND
    {
      Add_Torus ((int)$1, $5 , (int)$7, $9, $11);
    }
  | tDOUBLE tAFFECT tCIRCLE '(' tBIGSTR ',' tDOUBLE ',' FExpr ')' tEND
    {
      Add_Circle((int) $1, $5, (int) $7, $9);
    }
  | tDOUBLE tAFFECT tELLIPSE '(' tBIGSTR ',' tDOUBLE ',' FExpr ',' FExpr ')' tEND
    {
      Add_Ellipse((int) $1, $5, (int) $7, $9, $11);
    }
  | tDOUBLE tAFFECT tTRIMMED_CURVE '(' tBIGSTR ',' tDOUBLE ','
            ListOfDouble ',' ListOfDouble ',' BoolExpr ',' BoolExpr ')' tEND
    {
    }
  | tDOUBLE tAFFECT tGEOMETRIC_SET '(' tBIGSTR ',' ListOfDouble')' tEND
    {
    }
  | tDOUBLE tAFFECT tCOMPOSITE_CURVE_SEGMENT 
       '(' tCONTINUOUS ',' BoolExpr ',' tDOUBLE ')' tEND
    {
    }
  | tDOUBLE tAFFECT tCOMPOSITE_CURVE '(' tBIGSTR ',' ListOfDouble ',' BoolExpr ')' tEND
    {
    }
  | tDOUBLE tAFFECT tPRODUCT_DEFINITION 
       '(' tBIGSTR ',' tBIGSTR ',' tDOUBLE',' tDOUBLE ')' tEND
    {
    }
  | tDOUBLE tAFFECT tPRODUCT_DEFINITION_SHAPE '(' tBIGSTR ',' tBIGSTR ',' tDOUBLE ')' tEND
    {
    }
  | tDOUBLE tAFFECT tSHAPE_DEFINITION_REPRESENTATION '(' tDOUBLE ',' tDOUBLE ')' tEND
    {
    }
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
  | Coherence   { return 1; }
  | Loop        { return 1; }
  | Command     { return 1; }
;

Printf :
    tPrintf '(' tBIGSTR ')' tEND
    {
      Msg(DIRECT, $3);
      Free($3);
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

Shape :

  // Points

    tPoint '(' FExpr ')' tAFFECT VExpr tEND
    {
      int num = (int)$3;
      if(FindPoint(num, THEM)){
	yymsg(GERROR, "Point %d already exists", num);
      }
      else{
	Vertex *v = Create_Vertex(num, CTX.geom.scaling_factor * $6[0],
				  CTX.geom.scaling_factor * $6[1],
				  CTX.geom.scaling_factor * $6[2],
				  CTX.geom.scaling_factor * $6[3], 1.0);
	Tree_Add(THEM->Points, &v);
      }
      $$.Type = MSH_POINT;
      $$.Num = num;
    }
  | tPhysical tPoint '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_POINT, THEM)){
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
  | tAttractor tPoint ListOfDouble tAFFECT '{' FExpr ',' FExpr ',' FExpr '}'  tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double p;
      	List_Read($3, i, &p);
        Vertex *v = FindPoint((int)p, THEM);
        if(!v)
	  yymsg(WARNING, "Unknown point %d", (int)p);
	else{
	  Attractor *a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
					  $6, $8, $10, v, NULL, NULL);
	  List_Add(THEM->Metric->Attractors, &a);
        }
      }
      List_Delete($3);
      // dummy values
      $$.Type = 0;
      $$.Num = 0;
    }
  | tCharacteristic tLength ListOfDouble tAFFECT FExpr tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double d;
	List_Read($3, i, &d);
	Vertex *v = FindPoint((int)d, THEM);
	if(!v)
	  yymsg(WARNING, "Unknown point %d", (int)d);
	else
	  v->lc = $5;
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
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_LINE, 1, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_LINE;
      $$.Num = num;
    }
  | tSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_SPLN, 3, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_SPLN;
      $$.Num = num;
    }
  | tCircle '(' FExpr ')'  tAFFECT ListOfDouble tEND
    {
      int num = (int)$3;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_CIRC, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_CIRC;
      $$.Num = num;
    }
  | tCircle '(' FExpr ')'  tAFFECT ListOfDouble tPlane VExpr tEND
    {
      int num = (int)$3;
      if(FindCurve(num, THEM)){
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
	Curve *rc = CreateReversedCurve(THEM, c);
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
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	List_T *temp = ListOfDouble2ListOfInt($6);
	Curve *c = Create_Curve(num, MSH_SEGM_ELLI, 2, temp, NULL,
				-1, -1, 0., 1.);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
	List_Delete(temp);
      }
      List_Delete($6);
      $$.Type = MSH_SEGM_ELLI;
      $$.Num = num;
    }
  | tEllipse '(' FExpr ')'  tAFFECT ListOfDouble tPlane VExpr tEND
    {
      int num = (int)$3;
      if(FindCurve(num, THEM)){
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
	Curve *rc = CreateReversedCurve(THEM, c);
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
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
      }
      else{
	Curve *c = Create_Curve(num, MSH_SEGM_PARAMETRIC, 2, NULL, NULL,
				-1, -1, $7, $9);
	strcpy(c->functu, $11);
	strcpy(c->functv, $13);
	strcpy(c->functw, $15);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
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
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt($6);
	  Curve *c = Create_Curve(num, MSH_SEGM_BSPLN, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
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
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt($6);
	  Curve *c = Create_Curve(num, MSH_SEGM_BEZIER, 2, temp, NULL,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
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
	if(FindCurve(num, THEM)){
	  yymsg(GERROR, "Curve %d already exists", num);
	}
	else{
	  List_T *temp = ListOfDouble2ListOfInt($6);
	  Curve *c = Create_Curve(num, MSH_SEGM_NURBS, (int)$10, temp, $8,
				  -1, -1, 0., 1.);
	  Tree_Add(THEM->Curves, &c);
	  CreateReversedCurve(THEM, c);
	  List_Delete(temp);
	}
      }
      List_Delete($6);
      List_Delete($8);
      $$.Type = MSH_SEGM_NURBS;
      $$.Num = num;
    }
  | tDiscrete tLine '(' FExpr ')' tAFFECT '{' FExpr '}' ListOfDouble tEND
    {
      // define a new line
      int num = (int)$4;
      if(FindCurve(num, THEM)){
	yymsg(GERROR, "Curve %d already exists", num);
	List_Delete($10);
      }
      else{
	Curve *c = Create_Curve(num, MSH_SEGM_DISCRETE, 1, NULL, NULL, -1, -1, 0, 1);
	c->theSegmRep = new SEGM_rep((int)$8, $10);
	Tree_Add(THEM->Curves, &c);
	CreateReversedCurve(THEM, c);
      }
      $$.Type = MSH_SEGM_DISCRETE;
      $$.Num = num;
    }
  | tDiscrete tLine '{' FExpr '}' tAFFECT '{' FExpr '}' ListOfDouble tEND
    {
      // add a poly rep to an existing line
      int num = (int)$4, type = 0;
      Curve *c = FindCurve(num, THEM);
      if(!c) {
	yymsg(GERROR, "Unknown curve %d", num);
	List_Delete($10);
      }
      else{
	c->theSegmRep = new SEGM_rep((int)$8, $10);
	type = c->Typ;
      }
      $$.Type = type;
      $$.Num = num;
    }
  | tLine tLoop '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindEdgeLoop(num, THEM)){
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
  | tAttractor tLine ListOfDouble tAFFECT '{' FExpr ',' FExpr ',' FExpr '}'  tEND
    {
      for(int i = 0; i < List_Nbr($3); i++){
	double p;
      	List_Read($3, i, &p);
	Curve *c = FindCurve((int)p, THEM);
        if(!c)
	  yymsg(WARNING, "Unknown curve %d", (int)p);
	else{
	  Attractor *a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
					  $6, $8, $10, NULL, c, NULL);
	  List_Add(THEM->Metric->Attractors, &a);
        }
      }
      // dummy values
      $$.Type = 0;
      $$.Num = 0;
    }
  | tPhysical tLine '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_LINE, THEM)){
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
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_PLAN);
	List_T *temp = ListOfDouble2ListOfInt($7);
	setSurfaceGeneratrices(s, temp);
	List_Delete(temp);
	s->Support = s;
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
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	double d;
	List_Read($7, 0, &d);
	EdgeLoop *el = FindEdgeLoop((int)fabs(d), THEM);
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
	  s->Support = s;
	  End_Surface(s);
	  Tree_Add(THEM->Surfaces, &s);
	}
      }
      List_Delete($7);
      $$.Type = type;
      $$.Num = num;
    }
  | tTrimmed tSurface '(' FExpr ')' tAFFECT '{' FExpr ',' ListOfDouble '}' tEND
    {
      int num = (int)$4;
      Surface *support = FindSurface((int)$8, THEM);
      if(!support){
	yymsg(GERROR, "Unknown support surface %d", (int)$8);
      }
      else{
	if(FindSurface(num, THEM)){
	  yymsg(GERROR, "Surface %d already exists", num);
	}
	else{
	  Surface *s = Create_Surface(num, MSH_SURF_TRIMMED);
	  List_T *temp = ListOfDouble2ListOfInt($10);
	  setSurfaceGeneratrices(s, temp);
	  List_Delete(temp);
	  s->Support = support;
	  End_Surface(s);
	  Tree_Add(THEM->Surfaces, &s);
	}
      }
      List_Delete($10);
      $$.Type = MSH_SURF_TRIMMED;
      $$.Num = num;
    }
  | tDiscrete tSurface '(' FExpr ')' tAFFECT '{' FExpr ',' FExpr '}' 
       ListOfDouble ListOfDouble tEND
    {
      // define a new surface
      int num = (int)$4;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
	List_Delete($12);
	List_Delete($13);
      }
      else{
	Surface *s = Create_Surface(num, MSH_SURF_DISCRETE);
	s->Support = s;
	s->thePolyRep = new POLY_rep((int)$8, (int)$10, $12, $13);
	End_Surface(s);
	Tree_Add(THEM->Surfaces, &s);
      }
      $$.Type = MSH_SURF_DISCRETE;
      $$.Num = num;
    }
  | tDiscrete tSurface '{' FExpr '}' tAFFECT '{' FExpr ',' FExpr '}' 
       ListOfDouble ListOfDouble tEND
    {
      // add a poly rep to an existing surface
      int num = (int)$4, type = 0;
      Surface *s = FindSurface(num, THEM);
      if(!s) {
	yymsg(GERROR, "Unknown surface %d", num);
	List_Delete($12);
	List_Delete($13);
      }
      else{
	s->thePolyRep = new POLY_rep((int)$8, (int)$10, $12, $13);
	type = s->Typ;
      }
      $$.Type = type;
      $$.Num = num;
    }
  // for backward compatibility:
  | tTriangulation tSurface '(' FExpr ')' tAFFECT '(' FExpr ',' FExpr ')' 
       ListOfDouble ListOfDouble tEND
    {
      int num = (int)$4, type = 0;
      Surface *s = FindSurface(num, THEM);
      if(!s) {
	yymsg(GERROR, "Unknown surface %d", num);
	List_Delete($12);
	List_Delete($13);
      }
      else{
	s->thePolyRep = new POLY_rep((int)$8, (int)$10, $12, $13);
	type = s->Typ;
      }
      $$.Type = type;
      $$.Num = num;
    }
  | tNurbs tSurface tWith tBounds '(' FExpr ')' tAFFECT 
       ListOfListOfDouble tKnots  '{' ListOfDouble ',' ListOfDouble '}'
       tOrder '{' FExpr ',' FExpr '}' tEND
    {
      int num = (int)$6;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	CreateNurbsSurface(num, (int)$18, (int)$20, $9, $12, $14);
      }
      for(int i = 0; i < List_Nbr($9); i++)
	List_Delete((List_T*)List_Pointer($9, i));
      List_Delete($9);
      List_Delete($12);
      List_Delete($14);
      $$.Type = MSH_SURF_NURBS;
      $$.Num = num;
    }
  | tNurbs  tSurface '(' FExpr ')' tAFFECT 
       ListOfListOfDouble tKnots  '{' ListOfDouble ',' ListOfDouble '}'
       tOrder '{' FExpr ',' FExpr '}' tEND
    {
      int num = (int)$4;
      if(FindSurface(num, THEM)){
	yymsg(GERROR, "Surface %d already exists", num);
      }
      else{
	CreateNurbsSurfaceSupport(num, (int)$16, (int)$18, $7, $10, $12);
      }
      for(int i = 0; i < List_Nbr($7); i++)
	List_Delete((List_T*)List_Pointer($7, i));
      List_Delete($7);
      List_Delete($10);
      List_Delete($12);
      $$.Type = MSH_SURF_NURBS;
      $$.Num = num;
    }
  | tSurface tLoop '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindSurfaceLoop(num, THEM)){
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
  | tPhysical tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_SURFACE, THEM)){
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
      if(FindVolume(num, THEM)){
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
      if(FindVolume(num, THEM)){
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
  | tPhysical tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      int num = (int)$4;
      if(FindPhysicalGroup(num, MSH_PHYSICAL_VOLUME, THEM)){
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
	Vertex *v = FindPoint(TheShape.Num, THEM);
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
	Curve *c = FindCurve(TheShape.Num, THEM);
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
	Surface *s = FindSurface(TheShape.Num, THEM);
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
	Volume *v = FindVolume(TheShape.Num, THEM);
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
	Init_Mesh(THEM);
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
      int m = (CTX.visibility_mode == 2) ? VIS_MESH : 
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber($2, i, m);
      Free($2);
    }
  | tHide StringExpr tEND
    {
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber($2, i, 0);
      Free($2);
    }
  | tShow '{' ListOfShapes '}'
    {
      int m = (CTX.visibility_mode == 2) ? VIS_MESH :
	((CTX.visibility_mode == 1) ? VIS_GEOM : VIS_GEOM|VIS_MESH);
      for(int i = 0; i < List_Nbr($3); i++){
	Shape TheShape;
	List_Read($3, i, &TheShape);
	VisibilityShape(TheShape.Type, TheShape.Num, m);
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
	ParseFile(tmpstring, 0, 0, 1);
      }
      else if(!strcmp($1, "Print")){
#if defined(HAVE_FLTK)
	if(!CTX.batch){
	  char tmpstring[1024];
	  FixRelativePath($2, tmpstring);
	  CreateOutputFile(tmpstring, CTX.print.format);
	}
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
	MergeProblem(tmpstring, 1);
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
  | tSTRING FExpr tEND
    {
      if(!strcmp($1, "Sleep")){
	long sleep_time = GetTime();
	while(1){
	  if(GetTime() - sleep_time > (long)($2*1.e6)) break;
	}
      }
      else if(!strcmp($1, "Mesh")){
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
      // for backward compatibility
      if(!strcmp($2, "Views"))
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
      SetBoundingBox();
    } 
   | tBoundingBox '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr '}' tEND
    {
      SetBoundingBox($3, $5, $7, $9, $11, $13);
    } 
   | tDraw tEND
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch) // we're in interactive mode
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

  // Points
    tExtrude tPoint '{' FExpr ',' VExpr '}' tEND
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE, (int)$4, $6[0], $6[1], $6[2],
					  0., 0., 0., 0., 0., 0., 0.,
					  &pc, &prc, 1, NULL);
      TheShape.Type = MSH_POINT;
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'  tEND
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(ROTATE, (int)$4, 0., 0., 0.,
					  $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
					  &pc, &prc, 1, NULL);
      TheShape.Type = MSH_POINT;
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr'}'  tEND
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					  $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
					  &pc, &prc, 1, NULL);
      TheShape.Type = MSH_POINT;
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tPoint '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE, (int)$4, $6[0], $6[1], $6[2],
					  0., 0., 0., 0., 0., 0., 0.,
					  &pc, &prc, 1, &extr);
      TheShape.Type = MSH_POINT;
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(ROTATE, (int)$4, 0., 0., 0.,
					  $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
					  &pc, &prc, 1, &extr);
      TheShape.Type = MSH_POINT;
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr'}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					  $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
					  &pc, &prc, 1, &extr);
      TheShape.Type = MSH_POINT;
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pc){
	TheShape.Num = pc->Num;
	TheShape.Type = pc->Typ;
	List_Add($$, &TheShape);
      }
    }

  // Lines
  | tExtrude tLine '{' FExpr ',' VExpr '}' tEND
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(TRANSLATE, (int)$4, $6[0], $6[1], $6[2],
					  0., 0., 0., 0., 0., 0., 0., 
					  &ps, 1, NULL);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(ROTATE, (int)$4, 0., 0., 0.,
					  $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10, 
					  &ps, 1, NULL);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					  $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12, 
					  &ps, 1, NULL);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tLine '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(TRANSLATE, (int)$4, $6[0], $6[1], $6[2],
					  0., 0., 0., 0., 0., 0., 0., 
					  &ps, 1, &extr);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(ROTATE, (int)$4, 0., 0., 0.,
					  $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10, 
					  &ps, 1, &extr);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Surface *ps;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeCurve(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					  $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12, 
					  &ps, 1, &extr);
      Curve *c = FindCurve(TheShape.Num, THEM);
      if(!c){
	//yymsg(WARNING, "Unknown curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(ps){
	TheShape.Num = ps->Num;
	TheShape.Type = ps->Typ;
	List_Add($$, &TheShape);
      }
    }

  // Surfaces

  | tExtrude tSurface '{' FExpr ',' VExpr '}' tEND
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE, (int)$4, $6[0], $6[1], $6[2],
					    0., 0., 0., 0., 0., 0., 0., 
					    &pv, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(ROTATE, (int)$4, 0., 0., 0.,
					    $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
					    &pv, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					    $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
					    &pv, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tSurface '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                      '{' ExtrudeParameters '}' tEND
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE, (int)$4, $6[0], $6[1], $6[2],
					    0., 0., 0., 0., 0., 0., 0., 
					    &pv, &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' 
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
  
                      '{' ExtrudeParameters '}' tEND
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(ROTATE, (int)$4, 0., 0., 0.,
					    $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10, 
					    &pv, &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add($$, &TheShape);
      }
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
  
                      '{' ExtrudeParameters '}' tEND
    {
      Volume *pv;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					    $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
					    &pv, &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(2, 1, sizeof(Shape));
      List_Add($$, &TheShape);
      if(pv){
	TheShape.Num = pv->Num;
	TheShape.Type = pv->Typ;
	List_Add($$, &TheShape);
      }
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
    tLayers '{' ListOfDouble ',' ListOfDouble ',' ListOfDouble '}' tEND
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr($3);
      if(List_Nbr($3) == List_Nbr($5) && List_Nbr($3) == List_Nbr($7)){
	extr.mesh.NbElmLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.ZonLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.hLayer = (double*)Malloc(extr.mesh.NbLayer*sizeof(double));
	for(int i = 0; i < List_Nbr($3); i++){
	  List_Read($3, i, &d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  List_Read($5, i, &d);
	  extr.mesh.ZonLayer[i] = (int)d;
	  List_Read($7, i, &d);
	  extr.mesh.hLayer[i] = d;
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
  | tLayers '{' ListOfDouble ',' ListOfDouble '}' tEND
    {
      double d;
      extr.mesh.ExtrudeMesh = true;
      extr.mesh.NbLayer = List_Nbr($3);
      if(List_Nbr($3) == List_Nbr($5)){
	extr.mesh.NbElmLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.ZonLayer = (int*)Malloc(extr.mesh.NbLayer*sizeof(int));
	extr.mesh.hLayer = (double*)Malloc(extr.mesh.NbLayer*sizeof(double));
	for(int i = 0; i < List_Nbr($3); i++){
	  List_Read($3, i, &d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  extr.mesh.ZonLayer[i] = 0;
	  List_Read($5, i, &d);
	  extr.mesh.hLayer[i] = d;
	}
      }
      else{
	yymsg(GERROR, "Wrong layer definition {%d, %d}", 
	      List_Nbr($3), List_Nbr($5));
      }
      List_Delete($3);
      List_Delete($5);
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
        Curve *c = FindCurve(j, THEM);
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
        Curve *c = FindCurve(j, THEM);
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
        Curve *c = FindCurve(j, THEM);
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
      Surface *s = FindSurface((int)$4, THEM);
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
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j, THEM);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete($7);
    }
  | tElliptic tSurface '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Surface *s = FindSurface((int)$4, THEM);
      if(!s)
	yymsg(WARNING, "Unknown surface %d", (int)$4);
      else{
        s->Method = ELLIPTIC;
        int k = List_Nbr($7);
        if(k != 4)
	  yymsg(GERROR, "Wrong definition of Elliptic Surface %d: "
		"%d points instead of 4" , (int)$4, k);
        else{
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    Vertex *v = FindPoint(j, THEM);
	    if(!v)
	      yymsg(WARNING, "Unknown point %d", j);
	    else
	      List_Add(s->TrsfPoints, &v);
	  }
	}
      }
      List_Delete($7);
    }
  | tTransfinite tVolume '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Volume *v = FindVolume((int)$4, THEM);
      if(!v)
	yymsg(WARNING, "Unknown volume %d", (int)$4);
      else{
	v->Method = TRANSFINI;
	int k = List_Nbr($7);
	if(k != 6 && k != 8)
	  yymsg(GERROR, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , (int)$4, k);
	else{
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    Vertex *vert = FindPoint(j, THEM);
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
	Surface *s = FindSurface(j, THEM);
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
        Surface *s = FindSurface(j, THEM);
	if(s){
	  s->Recombine = 1;
        }
      }
      List_Delete($3);
    }
;


//  C O H E R E N C E

Coherence : 
    tCoherence tEND
    { 
      ReplaceAllDuplicates(THEM);
    }
  | tIntersect tEND
    { 
      IntersectAllSegmentsTogether();
    }
;


//  G E N E R A L

BoolExpr :
    tTRUE {$$ = 1;}
  | tFALSE {$$ = 0;}
  | tUNSPECIFIED {$$ = -1;}
  | tU {$$ = -1;}
  | tV {$$ = -1;}
;

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
  | tGMSH_MAJOR_VERSION { $$ = GMSH_MAJOR_VERSION; }
  | tGMSH_MINOR_VERSION { $$ = GMSH_MINOR_VERSION; }
  | tGMSH_PATCH_VERSION { $$ = GMSH_PATCH_VERSION; }

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

ListOfStrings :
    // nothing
    {
    }
  | '(' RecursiveListOfStrings ')'
    {
    }
;

RecursiveListOfStrings :
    tBIGSTR
    {
    }
  | RecursiveListOfStrings ',' tBIGSTR
    {
    }
;

ListOfListOfDouble :
    // nothing
    {
    }
  | '{' RecursiveListOfListOfDouble '}'
    {
       $$ = $2;
    }
  | '(' RecursiveListOfListOfDouble ')'
    {
       $$ = $2;
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
      Vertex *v = FindPoint((int)$3, THEM);
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
      // FIXME: The syntax for this is ugly: we get double semi-colons
      // at the end of the line
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
      $$ = PACK_COLOR((int)$2, (int)$4, (int)$6, (int)$8);
    }
  | '{' FExpr ',' FExpr ',' FExpr '}'
    {
      $$ = PACK_COLOR((int)$2, (int)$4, (int)$6, 255);
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
