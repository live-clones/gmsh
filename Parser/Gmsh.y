%{
// $Id: Gmsh.y,v 1.162 2004-03-30 18:17:09 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "STL.h"
#include "Visibility.h"

// FIXME: most tSTRING and tBIGSTRING are leaked: Free() them!

Tree_T *Symbol_T = NULL;

extern Context_T CTX;
extern Mesh *THEM;

static Surface *STL_Surf;
static ExtrudeParams extr;
static Post_View *View;

#define MAX_RECUR_LOOPS 100
static int ImbricatedLoop = 0;
static fpos_t yyposImbricatedLoopsTab[MAX_RECUR_LOOPS];
static int yylinenoImbricatedLoopsTab[MAX_RECUR_LOOPS];
static double LoopControlVariablesTab[MAX_RECUR_LOOPS][3];
static char *LoopControlVariablesNameTab[MAX_RECUR_LOOPS];

char *strsave (char *ptr);
void yyerror (char *s);
void yymsg (int type, char *fmt, ...);
void skip_until (char *skip, char *until);
int PrintListOfDouble (char *format, List_T *list, char *buffer);
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
%token tFmod tModulo tHypot tPrintf tSprintf tStrCat tStrPrefix tDraw
%token tPoint tCircle tEllipse tLine tSurface tSpline tVolume
%token tCharacteristic tLength tParametric tElliptic
%token tPlane tRuled tTriangulation tTransfinite tComplex tPhysical
%token tUsing tBump tProgression tPlugin
%token tRotate tTranslate tSymmetry tDilate tExtrude tDuplicata
%token tLoop tRecombine tDelete tCoherence tIntersect
%token tAttractor tLayers
%token tScalarPoint tVectorPoint tTensorPoint
%token tScalarLine tVectorLine tTensorLine
%token tScalarTriangle tVectorTriangle tTensorTriangle
%token tScalarQuadrangle tVectorQuadrangle tTensorQuadrangle
%token tScalarTetrahedron tVectorTetrahedron tTensorTetrahedron
%token tScalarHexahedron tVectorHexahedron tTensorHexahedron
%token tScalarPrism tVectorPrism tTensorPrism
%token tScalarPyramid tVectorPyramid tTensorPyramid
%token tText2D tText3D tCombine
%token tBSpline tBezier tNurbs tOrder tWith tBounds tKnots
%token tColor tColorTable tFor tIn tEndFor tIf tEndIf tExit
%token tReturn tCall tFunction tTrimmed tShow tHide

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
      STL_Surf = Create_Surface(NEWSURFACE(), MSH_SURF_STL);
      STL_Surf->STL = new STL_Data;
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
      STL_Surf->STL->Add_Facet($9, $10, $11,
			       $13, $14, $15,
			       $17, $18, $19, CTX.geom.stl_create_elementary);
      return 1;
    }
  | tEndSolid
    {
      if(CTX.geom.stl_create_elementary){
	STL_Surf->STL->ReplaceDuplicate();
	if(CTX.geom.stl_create_physical)
	  STL_Surf->STL->CreatePhysicalSurface();
      }
      else{
	Tree_Add(THEM->Surfaces, &STL_Surf);
      }
      yymsg(INFO, "Read STL solid");
      return 1;
    }
;

// S T E P   I S O - 1 0 3 0 3 - 2 1   F I L E   F O R M A T

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
      List_Delete($5);
    }
;

// V I E W 

View :
    tSTRING tBIGSTR '{' Views '}' tEND
    { 
      if(!strcmp($1, "View")) EndView(View, 1, yyname, $2); 
    }
  | tSTRING tBIGSTR tSTRING VExpr '{' Views '}' tEND
    {
      if(!strcmp($1, "View")) EndView(View, 1, yyname, $2);
    }  
;

Views :
    // nothing
    {
      View = BeginView(1); 
    }
  | Views ScalarPoint
  | Views VectorPoint
  | Views TensorPoint
  | Views ScalarLine
  | Views VectorLine
  | Views TensorLine
  | Views ScalarTriangle
  | Views VectorTriangle
  | Views TensorTriangle
  | Views ScalarQuadrangle
  | Views VectorQuadrangle
  | Views TensorQuadrangle
  | Views ScalarTetrahedron
  | Views VectorTetrahedron
  | Views TensorTetrahedron
  | Views ScalarHexahedron
  | Views VectorHexahedron
  | Views TensorHexahedron
  | Views ScalarPrism
  | Views VectorPrism
  | Views TensorPrism
  | Views ScalarPyramid
  | Views VectorPyramid
  | Views TensorPyramid
  | Views Text2D
  | Views Text3D
;

ScalarPointValues :
    FExpr
    { List_Add(View->SP, &$1); }
  | ScalarPointValues ',' FExpr
    { List_Add(View->SP, &$3); }
;

ScalarPoint : 
    tScalarPoint '(' FExpr ',' FExpr ',' FExpr ')'
    { 
      List_Add(View->SP, &$3); List_Add(View->SP, &$5);
      List_Add(View->SP, &$7);
    }
    '{' ScalarPointValues '}' tEND
    {
      View->NbSP++;
    }
;

VectorPointValues :
    FExpr
    { List_Add(View->VP, &$1); }
  | VectorPointValues ',' FExpr
    { List_Add(View->VP, &$3); }
;

VectorPoint : 
    tVectorPoint '(' FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VP, &$3); List_Add(View->VP, &$5);
      List_Add(View->VP, &$7); 
    }
    '{' VectorPointValues '}' tEND
    {
      View->NbVP++;
    }
;

TensorPointValues :
    FExpr
    { List_Add(View->TP, &$1); }
  | TensorPointValues ',' FExpr
    { List_Add(View->TP, &$3); }
;

TensorPoint :
    tTensorPoint '(' FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TP, &$3); List_Add(View->TP, &$5);
      List_Add(View->TP, &$7);
    }
    '{' TensorPointValues '}' tEND
    {
      View->NbTP++;
    }
;

ScalarLineValues :
    FExpr
    { List_Add(View->SL, &$1); }
  | ScalarLineValues ',' FExpr
    { List_Add(View->SL, &$3); }
;

ScalarLine : 
    tScalarLine '(' FExpr ',' FExpr ',' FExpr ',' 
                    FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->SL, &$3); List_Add(View->SL, &$9);
      List_Add(View->SL, &$5); List_Add(View->SL, &$11);
      List_Add(View->SL, &$7); List_Add(View->SL, &$13);
    }
    '{' ScalarLineValues '}' tEND
    {
      View->NbSL++;
    }
;

VectorLineValues :
    FExpr
    { List_Add(View->VL, &$1); }
  | VectorLineValues ',' FExpr
    { List_Add(View->VL, &$3); }
;

VectorLine : 
    tVectorLine '(' FExpr ',' FExpr ',' FExpr ',' 
                    FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VL, &$3); List_Add(View->VL, &$9);
      List_Add(View->VL, &$5); List_Add(View->VL, &$11);
      List_Add(View->VL, &$7); List_Add(View->VL, &$13);
    }
    '{' VectorLineValues '}' tEND
    {
      View->NbVL++;
    }
;

TensorLineValues :
    FExpr
    { List_Add(View->TL, &$1); }
  | TensorLineValues ',' FExpr
    { List_Add(View->TL, &$3); }
;

TensorLine :
    tTensorLine '(' FExpr ',' FExpr ',' FExpr ',' 
                    FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TL, &$3); List_Add(View->TL, &$9);
      List_Add(View->TL, &$5); List_Add(View->TL, &$11);
      List_Add(View->TL, &$7); List_Add(View->TL, &$13);
    }
    '{' TensorLineValues '}' tEND
    {
      View->NbTL++;
    }
;

ScalarTriangleValues :
    FExpr
    { List_Add(View->ST, &$1); }
  | ScalarTriangleValues ',' FExpr
    { List_Add(View->ST, &$3); }
;

ScalarTriangle : 
    tScalarTriangle '(' FExpr ',' FExpr ',' FExpr ',' 
                        FExpr ',' FExpr ',' FExpr ','
                        FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->ST, &$3); List_Add(View->ST, &$9);
      List_Add(View->ST, &$15);
      List_Add(View->ST, &$5); List_Add(View->ST, &$11);
      List_Add(View->ST, &$17);
      List_Add(View->ST, &$7); List_Add(View->ST, &$13);
      List_Add(View->ST, &$19);
    }
    '{' ScalarTriangleValues '}' tEND
    {
      View->NbST++;
    }
;

VectorTriangleValues :
    FExpr
    { List_Add(View->VT, &$1); }
  | VectorTriangleValues ',' FExpr
    { List_Add(View->VT, &$3); }
;

VectorTriangle : 
    tVectorTriangle '(' FExpr ',' FExpr ',' FExpr ',' 
                        FExpr ',' FExpr ',' FExpr ','
                        FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VT, &$3); List_Add(View->VT, &$9);
      List_Add(View->VT, &$15);
      List_Add(View->VT, &$5); List_Add(View->VT, &$11);
      List_Add(View->VT, &$17);
      List_Add(View->VT, &$7); List_Add(View->VT, &$13);
      List_Add(View->VT, &$19);
    }
    '{' VectorTriangleValues '}' tEND
    {
      View->NbVT++;
    }
;

TensorTriangleValues :
    FExpr
    { List_Add(View->TT, &$1); }
  | TensorTriangleValues ',' FExpr
    { List_Add(View->TT, &$3); }
;

TensorTriangle :
    tTensorTriangle '(' FExpr ',' FExpr ',' FExpr ',' 
                        FExpr ',' FExpr ',' FExpr ','
                        FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TT, &$3); List_Add(View->TT, &$9);
      List_Add(View->TT, &$15);
      List_Add(View->TT, &$5); List_Add(View->TT, &$11);
      List_Add(View->TT, &$17);
      List_Add(View->TT, &$7); List_Add(View->TT, &$13);
      List_Add(View->TT, &$19);
    }
    '{' TensorTriangleValues '}' tEND
    {
      View->NbTT++;
    }
;

ScalarQuadrangleValues :
    FExpr
    { List_Add(View->SQ, &$1); }
  | ScalarQuadrangleValues ',' FExpr
    { List_Add(View->SQ, &$3); }
;

ScalarQuadrangle : 
    tScalarQuadrangle '(' FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->SQ, &$3);  List_Add(View->SQ, &$9);
      List_Add(View->SQ, &$15); List_Add(View->SQ, &$21);
      List_Add(View->SQ, &$5);  List_Add(View->SQ, &$11);
      List_Add(View->SQ, &$17); List_Add(View->SQ, &$23);
      List_Add(View->SQ, &$7);  List_Add(View->SQ, &$13);
      List_Add(View->SQ, &$19); List_Add(View->SQ, &$25);
    }
    '{' ScalarQuadrangleValues '}' tEND
    {
      View->NbSQ++;
    }
;

VectorQuadrangleValues :
    FExpr
    { List_Add(View->VQ, &$1); }
  | VectorQuadrangleValues ',' FExpr
    { List_Add(View->VQ, &$3); }
;

VectorQuadrangle : 
    tVectorQuadrangle '(' FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VQ, &$3);  List_Add(View->VQ, &$9);
      List_Add(View->VQ, &$15); List_Add(View->VQ, &$21);
      List_Add(View->VQ, &$5);  List_Add(View->VQ, &$11);
      List_Add(View->VQ, &$17); List_Add(View->VQ, &$23);
      List_Add(View->VQ, &$7);  List_Add(View->VQ, &$13);
      List_Add(View->VQ, &$19); List_Add(View->VQ, &$25);
    }
    '{' VectorQuadrangleValues '}' tEND
    {
      View->NbVQ++;
    }
;

TensorQuadrangleValues :
    FExpr
    { List_Add(View->TQ, &$1); }
  | TensorQuadrangleValues ',' FExpr
    { List_Add(View->TQ, &$3); }
;

TensorQuadrangle :
    tTensorQuadrangle '(' FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TQ, &$3);  List_Add(View->TQ, &$9);
      List_Add(View->TQ, &$15); List_Add(View->TQ, &$21);
      List_Add(View->TQ, &$5);  List_Add(View->TQ, &$11);
      List_Add(View->TQ, &$17); List_Add(View->TQ, &$23);
      List_Add(View->TQ, &$7);  List_Add(View->TQ, &$13);
      List_Add(View->TQ, &$19); List_Add(View->TQ, &$25);
    }
    '{' TensorQuadrangleValues '}' tEND
    {
      View->NbTQ++;
    }
;

ScalarTetrahedronValues :
    FExpr
    { List_Add(View->SS, &$1); }
  | ScalarTetrahedronValues ',' FExpr
    { List_Add(View->SS, &$3); }
;

ScalarTetrahedron : 
    tScalarTetrahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ','
                           FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->SS, &$3);  List_Add(View->SS, &$9);
      List_Add(View->SS, &$15); List_Add(View->SS, &$21);
      List_Add(View->SS, &$5);  List_Add(View->SS, &$11);
      List_Add(View->SS, &$17); List_Add(View->SS, &$23);
      List_Add(View->SS, &$7);  List_Add(View->SS, &$13);
      List_Add(View->SS, &$19); List_Add(View->SS, &$25);
    }
    '{' ScalarTetrahedronValues '}' tEND
    {
      View->NbSS++;
    }
;

VectorTetrahedronValues :
    FExpr
    { List_Add(View->VS, &$1); }
  | VectorTetrahedronValues ',' FExpr
    { List_Add(View->VS, &$3); }
;

VectorTetrahedron : 
    tVectorTetrahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ','
                           FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VS, &$3);  List_Add(View->VS, &$9);
      List_Add(View->VS, &$15); List_Add(View->VS, &$21);
      List_Add(View->VS, &$5);  List_Add(View->VS, &$11);
      List_Add(View->VS, &$17); List_Add(View->VS, &$23);
      List_Add(View->VS, &$7);  List_Add(View->VS, &$13);
      List_Add(View->VS, &$19); List_Add(View->VS, &$25);
    }
    '{' VectorTetrahedronValues '}' tEND
    {
      View->NbVS++;
    }
;

TensorTetrahedronValues :
    FExpr
    { List_Add(View->TS, &$1); }
  | TensorTetrahedronValues ',' FExpr
    { List_Add(View->TS, &$3); }
;

TensorTetrahedron :
    tTensorTetrahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ','
                           FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TS, &$3);  List_Add(View->TS, &$9);
      List_Add(View->TS, &$15); List_Add(View->TS, &$21);
      List_Add(View->TS, &$5);  List_Add(View->TS, &$11);
      List_Add(View->TS, &$17); List_Add(View->TS, &$23);
      List_Add(View->TS, &$7);  List_Add(View->TS, &$13);
      List_Add(View->TS, &$19); List_Add(View->TS, &$25);
    }
    '{' TensorTetrahedronValues '}' tEND
    {
      View->NbTS++;
    }
;

ScalarHexahedronValues :
    FExpr
    { List_Add(View->SH, &$1); }
  | ScalarHexahedronValues ',' FExpr
    { List_Add(View->SH, &$3); }
;

ScalarHexahedron : 
    tScalarHexahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->SH, &$3);  List_Add(View->SH, &$9);
      List_Add(View->SH, &$15); List_Add(View->SH, &$21);
      List_Add(View->SH, &$27); List_Add(View->SH, &$33);
      List_Add(View->SH, &$39); List_Add(View->SH, &$45);
      List_Add(View->SH, &$5);  List_Add(View->SH, &$11);
      List_Add(View->SH, &$17); List_Add(View->SH, &$23);
      List_Add(View->SH, &$29); List_Add(View->SH, &$35);
      List_Add(View->SH, &$41); List_Add(View->SH, &$47);
      List_Add(View->SH, &$7);  List_Add(View->SH, &$13);
      List_Add(View->SH, &$19); List_Add(View->SH, &$25);
      List_Add(View->SH, &$31); List_Add(View->SH, &$37);
      List_Add(View->SH, &$43); List_Add(View->SH, &$49);
    }
    '{' ScalarHexahedronValues '}' tEND
    {
      View->NbSH++;
    }
;

VectorHexahedronValues :
    FExpr
    { List_Add(View->VH, &$1); }
  | VectorHexahedronValues ',' FExpr
    { List_Add(View->VH, &$3); }
;

VectorHexahedron : 
    tVectorHexahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VH, &$3);  List_Add(View->VH, &$9);
      List_Add(View->VH, &$15); List_Add(View->VH, &$21);
      List_Add(View->VH, &$27); List_Add(View->VH, &$33);
      List_Add(View->VH, &$39); List_Add(View->VH, &$45);
      List_Add(View->VH, &$5);  List_Add(View->VH, &$11);
      List_Add(View->VH, &$17); List_Add(View->VH, &$23);
      List_Add(View->VH, &$29); List_Add(View->VH, &$35);
      List_Add(View->VH, &$41); List_Add(View->VH, &$47);
      List_Add(View->VH, &$7);  List_Add(View->VH, &$13);
      List_Add(View->VH, &$19); List_Add(View->VH, &$25);
      List_Add(View->VH, &$31); List_Add(View->VH, &$37);
      List_Add(View->VH, &$43); List_Add(View->VH, &$49);
    }
    '{' VectorHexahedronValues '}' tEND
    {
      View->NbVH++;
    }
;

TensorHexahedronValues :
    FExpr
    { List_Add(View->TH, &$1); }
  | TensorHexahedronValues ',' FExpr
    { List_Add(View->TH, &$3); }
;

TensorHexahedron :
    tTensorHexahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ','
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ',' 
                          FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TH, &$3);  List_Add(View->TH, &$9);
      List_Add(View->TH, &$15); List_Add(View->TH, &$21);
      List_Add(View->TH, &$27); List_Add(View->TH, &$33);
      List_Add(View->TH, &$39); List_Add(View->TH, &$45);
      List_Add(View->TH, &$5);  List_Add(View->TH, &$11);
      List_Add(View->TH, &$17); List_Add(View->TH, &$23);
      List_Add(View->TH, &$29); List_Add(View->TH, &$35);
      List_Add(View->TH, &$41); List_Add(View->TH, &$47);
      List_Add(View->TH, &$7);  List_Add(View->TH, &$13);
      List_Add(View->TH, &$19); List_Add(View->TH, &$25);
      List_Add(View->TH, &$31); List_Add(View->TH, &$37);
      List_Add(View->TH, &$43); List_Add(View->TH, &$49);
    }
    '{' TensorHexahedronValues '}' tEND
    {
      View->NbTH++;
    }
;

ScalarPrismValues :
    FExpr
    { List_Add(View->SI, &$1); }
  | ScalarPrismValues ',' FExpr
    { List_Add(View->SI, &$3); }
;

ScalarPrism : 
    tScalarPrism '(' FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ','
                     FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ','
                     FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->SI, &$3);  List_Add(View->SI, &$9);
      List_Add(View->SI, &$15); List_Add(View->SI, &$21);
      List_Add(View->SI, &$27); List_Add(View->SI, &$33);
      List_Add(View->SI, &$5);  List_Add(View->SI, &$11);
      List_Add(View->SI, &$17); List_Add(View->SI, &$23);
      List_Add(View->SI, &$29); List_Add(View->SI, &$35);
      List_Add(View->SI, &$7);  List_Add(View->SI, &$13);
      List_Add(View->SI, &$19); List_Add(View->SI, &$25);
      List_Add(View->SI, &$31); List_Add(View->SI, &$37);
    }
    '{' ScalarPrismValues '}' tEND
    {
      View->NbSI++;
    }
;

VectorPrismValues :
    FExpr
    { List_Add(View->VI, &$1); }
  | VectorPrismValues ',' FExpr
    { List_Add(View->VI, &$3); }
;

VectorPrism : 
    tVectorPrism '(' FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ','
                     FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ','
                     FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VI, &$3);  List_Add(View->VI, &$9);
      List_Add(View->VI, &$15); List_Add(View->VI, &$21);
      List_Add(View->VI, &$27); List_Add(View->VI, &$33);
      List_Add(View->VI, &$5);  List_Add(View->VI, &$11);
      List_Add(View->VI, &$17); List_Add(View->VI, &$23);
      List_Add(View->VI, &$29); List_Add(View->VI, &$35);
      List_Add(View->VI, &$7);  List_Add(View->VI, &$13);
      List_Add(View->VI, &$19); List_Add(View->VI, &$25);
      List_Add(View->VI, &$31); List_Add(View->VI, &$37);
    }
    '{' VectorPrismValues '}' tEND
    {
      View->NbVI++;
    }
;

TensorPrismValues :
    FExpr
    { List_Add(View->TI, &$1); }
  | TensorPrismValues ',' FExpr
    { List_Add(View->TI, &$3); }
;

TensorPrism :
    tTensorPrism '(' FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ','
                     FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ','
                     FExpr ',' FExpr ',' FExpr ',' 
                     FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TI, &$3);  List_Add(View->TI, &$9);
      List_Add(View->TI, &$15); List_Add(View->TI, &$21);
      List_Add(View->TI, &$27); List_Add(View->TI, &$33);
      List_Add(View->TI, &$5);  List_Add(View->TI, &$11);
      List_Add(View->TI, &$17); List_Add(View->TI, &$23);
      List_Add(View->TI, &$29); List_Add(View->TI, &$35);
      List_Add(View->TI, &$7);  List_Add(View->TI, &$13);
      List_Add(View->TI, &$19); List_Add(View->TI, &$25);
      List_Add(View->TI, &$31); List_Add(View->TI, &$37);
    }
    '{' TensorPrismValues '}' tEND
    {
      View->NbTI++;
    }
;

ScalarPyramidValues :
    FExpr
    { List_Add(View->SY, &$1); }
  | ScalarPyramidValues ',' FExpr
    { List_Add(View->SY, &$3); }
;

ScalarPyramid : 
    tScalarPyramid '(' FExpr ',' FExpr ',' FExpr ',' 
                       FExpr ',' FExpr ',' FExpr ','
                       FExpr ',' FExpr ',' FExpr ',' 
                       FExpr ',' FExpr ',' FExpr ','
                       FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->SY, &$3);  List_Add(View->SY, &$9);
      List_Add(View->SY, &$15); List_Add(View->SY, &$21);
      List_Add(View->SY, &$27);
      List_Add(View->SY, &$5);  List_Add(View->SY, &$11);
      List_Add(View->SY, &$17); List_Add(View->SY, &$23);
      List_Add(View->SY, &$29);
      List_Add(View->SY, &$7);  List_Add(View->SY, &$13);
      List_Add(View->SY, &$19); List_Add(View->SY, &$25);
      List_Add(View->SY, &$31);
    }
    '{' ScalarPyramidValues '}' tEND
    {
      View->NbSY++;
    }
;

VectorPyramidValues :
    FExpr
    { List_Add(View->VY, &$1); }
  | VectorPyramidValues ',' FExpr
    { List_Add(View->VY, &$3); }
;

VectorPyramid : 
    tVectorPyramid '(' FExpr ',' FExpr ',' FExpr ',' 
                       FExpr ',' FExpr ',' FExpr ','
                       FExpr ',' FExpr ',' FExpr ',' 
                       FExpr ',' FExpr ',' FExpr ',' 
                       FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VY, &$3);  List_Add(View->VY, &$9);
      List_Add(View->VY, &$15); List_Add(View->VY, &$21);
      List_Add(View->VY, &$27);
      List_Add(View->VY, &$5);  List_Add(View->VY, &$11);
      List_Add(View->VY, &$17); List_Add(View->VY, &$23);
      List_Add(View->VY, &$29);
      List_Add(View->VY, &$7);  List_Add(View->VY, &$13);
      List_Add(View->VY, &$19); List_Add(View->VY, &$25);
      List_Add(View->VY, &$31);
    }
    '{' VectorPyramidValues '}' tEND
    {
      View->NbVY++;
    }
;

TensorPyramidValues :
    FExpr
    { List_Add(View->TY, &$1); }
  | TensorPyramidValues ',' FExpr
    { List_Add(View->TY, &$3); }
;

TensorPyramid :
    tTensorPyramid '(' FExpr ',' FExpr ',' FExpr ',' 
                       FExpr ',' FExpr ',' FExpr ','
                       FExpr ',' FExpr ',' FExpr ',' 
                       FExpr ',' FExpr ',' FExpr ',' 
                       FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TY, &$3);  List_Add(View->TY, &$9);
      List_Add(View->TY, &$15); List_Add(View->TY, &$21);
      List_Add(View->TY, &$27);
      List_Add(View->TY, &$5);  List_Add(View->TY, &$11);
      List_Add(View->TY, &$17); List_Add(View->TY, &$23);
      List_Add(View->TY, &$29);
      List_Add(View->TY, &$7);  List_Add(View->TY, &$13);
      List_Add(View->TY, &$19); List_Add(View->TY, &$25);
      List_Add(View->TY, &$31);
    }
    '{' TensorPyramidValues '}' tEND
    {
      View->NbTY++;
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
	TheSymbol.val = List_Create(1, 1, sizeof(double));
	if(!$2){
	  List_Put(TheSymbol.val, 0, &$3);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else
	  yymsg(GERROR, "Unknown variable '%s'", $1);
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
      }
    }
  | tSTRING '[' FExpr ']' NumericAffectation FExpr tEND
    {
      Symbol TheSymbol;
      TheSymbol.Name = $1;
      Symbol *pSymbol;
      if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	TheSymbol.val = List_Create(5, 5, sizeof(double));
	if(!$5){
	  List_Put(TheSymbol.val, (int)$3, &$6);
	  Tree_Add(Symbol_T, &TheSymbol);
	}
	else
	  yymsg(GERROR, "Unknown variable '%s'", $1);
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
      }
    }
  | tSTRING '[' '{' RecursiveListOfDouble '}' ']' NumericAffectation ListOfDouble tEND
    {
      if(List_Nbr($4) != List_Nbr($8))
	yymsg(GERROR, "Incompatible array dimensions in affectation");
      else{
	Symbol TheSymbol;
	TheSymbol.Name = $1;
	Symbol *pSymbol;
	if(!(pSymbol = (Symbol*)Tree_PQuery(Symbol_T, &TheSymbol))){
	  TheSymbol.val = List_Create(5, 5, sizeof(double));
	  if(!$7){
	    for(int i = 0; i < List_Nbr($4); i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer($4, i)),
		       (double*)List_Pointer($8, i));
	    }
	    Tree_Add(Symbol_T, &TheSymbol);
	  }
	  else
	    yymsg(GERROR, "Unknown variable '%s'", $1);
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
      List_Delete($8);
    }

  // Plugins

  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT FExpr tEND 
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption($3, $6, $8); 
      }
      catch (...) {
	yymsg(WARNING, "Unknown option '%s' or plugin '%s'", $6, $3);
      }
    }
  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT StringExpr tEND 
    {
      try {
	GMSH_PluginManager::instance()->setPluginOption($3, $6, $8); 
      }
      catch (...) {
	yymsg(WARNING, "Unknown option '%s' or plugin '%s'", $6, $3);
      }
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
	  yymsg(WARNING, "Unknown Point %d", (int)p);
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
	  yymsg(WARNING, "Unknown Point %d", (int)d);
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
	  yymsg(WARNING, "Unknown Curve %d", (int)p);
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
	EdgeLoop *el = FindEdgeLoop((int)d, THEM);
	if(!el){
	  yymsg(GERROR, "Unknown Line Loop %d", (int)d);
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
  | tTriangulation tSurface '{' FExpr '}' tAFFECT '(' FExpr ',' FExpr ')' 
       ListOfDouble ListOfDouble tEND
    {
      int num = (int)$4, type = 0;
      Surface *s = FindSurface(num, THEM);
      if(!s) {
	yymsg(GERROR, "Unknown surface %d", num);
      }
      else{
	// FIXME: parameters not used; undocumented
	POLY_rep *rep = new POLY_rep($12, $13);
	s->thePolyRep = rep;
	type = s->Typ;
      }
      //FIXME: do you copy the data?
      //List_Delete($12);
      //List_Delete($13);
      $$.Type = type;
      $$.Num = (int)$4;
    }
  // for backward compatibility only: when we don't create a new entity,
  // we should use braces (and not parentheses)
  | tTriangulation tSurface '(' FExpr ')' tAFFECT '(' FExpr ',' FExpr ')' 
       ListOfDouble ListOfDouble tEND
    {
      int num = (int)$4, type = 0;
      Surface *s = FindSurface(num, THEM);
      if(!s) {
	yymsg(GERROR, "Unknown surface %d", num);
      }
      else{
	POLY_rep *rep = new POLY_rep($12, $13);
	s->thePolyRep = rep;
	type = s->Typ;
      }
      $$.Type = type;
      $$.Num = (int)$4;
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
	  yymsg(WARNING, "Unknown Point %d", TheShape.Num);
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
	  yymsg(WARNING, "Unknown Curve %d", TheShape.Num);
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
	  yymsg(WARNING, "Unknown Surface %d", TheShape.Num);
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
	  yymsg(WARNING, "Unknown Volume %d", TheShape.Num);
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
  | tDuplicata tSTRING '[' FExpr ']' tEND
    {
      if(!strcmp($2, "View")) DuplicateView((int)$4, 0);
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
      if(!strcmp($2, "View")) RemoveViewByIndex((int)$4);
    }
    | tDelete tSTRING tEND
    {
      if(!strcmp($2, "Meshes") || !strcmp($2, "All"))
	Init_Mesh(THEM);
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
    }
  | tHide StringExpr tEND
    {
      for(int i = 2; i < 6; i++)
	SetVisibilityByNumber($2, i, 0);
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
	// Warning: we *don't* close included files. If you need to
	// include many files, use "Merge" instead: some OSes limit
	// the number of files a process can open simultaneously (500
	// for OS X)
	ParseFile(tmpstring, 0, 0);
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
	MergeProblem(tmpstring);
      }
      else if(!strcmp($1, "System")){
	SystemCall($2);
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", $1);
      }
    } 
  | tSTRING tSTRING '[' FExpr ']' StringExpr tEND
    {
      if(!strcmp($1, "Save") && !strcmp($2, "View")){
	Post_View *v = (Post_View *)List_Pointer_Test(CTX.post.list, (int)$4);
	if(v){
	  char tmpstring[1024];
	  FixRelativePath($6, tmpstring);
	  WriteView(v, tmpstring, 0, 0);
	}
      }
      else{
	yymsg(GERROR, "Unknown command '%s'", $1);
      }
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
    }
   | tPlugin '(' tSTRING ')' '.' tSTRING tEND
   {
      try {
	GMSH_PluginManager::instance()->action($3, $6, 0);
      }
      catch(...) {
	yymsg(WARNING, "Unknown action '%s' or plugin '%s'", $6, $3);
      }
   }
   | tCombine tSTRING tEND
    {
      if(!strcmp($2, "Views"))
	CombineViews(1, 0);
      else if(!strcmp($2, "TimeSteps"))
	CombineViews_Time(2, 0);
      else
	yymsg(GERROR, "Unknown Combine command");
    } 
   | tExit tEND
    {
      exit(0);
    } 
   | tDraw tEND
    {
#if defined(HAVE_FLTK)
      if(!CTX.batch){ // we're in interactive mode
	Draw();
	DrawUI();
      }
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
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
    }
  | tFor '(' FExpr tDOTS FExpr tDOTS FExpr ')'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $3;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5;
      LoopControlVariablesTab[ImbricatedLoop][2] = $7;
      LoopControlVariablesNameTab[ImbricatedLoop] = "";
      fgetpos(yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
      if(ImbricatedLoop > MAX_RECUR_LOOPS-1){
	yymsg(GERROR, "Reached maximum number of imbricated loops");
	ImbricatedLoop = MAX_RECUR_LOOPS-1;
      }
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
    }
  | tEndFor 
    {
      if(LoopControlVariablesTab[ImbricatedLoop-1][1] >  
	 LoopControlVariablesTab[ImbricatedLoop-1][0]){
	LoopControlVariablesTab[ImbricatedLoop-1][0] +=
	  LoopControlVariablesTab[ImbricatedLoop-1][2];
	if(strlen(LoopControlVariablesNameTab[ImbricatedLoop-1])){
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
	if(ImbricatedLoop < 0){
	  yymsg(GERROR, "Problem with imbricated loops");
	  ImbricatedLoop = 0;
	}
      }
    }
  | tFunction tSTRING
    {
      if(!FunctionManager::Instance()->createFunction($2, yyin, yyname, yylineno))
	yymsg(GERROR, "Redefinition of function %s", $2);
      skip_until(NULL, "Return");
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
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'  tEND
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(ROTATE, (int)$4, 0., 0., 0.,
					  $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
					  &pc, &prc, 1, NULL);
      TheShape.Type = MSH_POINT;
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr'}'  tEND
    {
      Curve *pc, *prc;
      Shape TheShape;
      TheShape.Num = Extrude_ProtudePoint(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					  $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
					  &pc, &prc, 1, NULL);
      TheShape.Type = MSH_POINT;
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
	//yymsg(WARNING, "Unknown Curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
	//yymsg(WARNING, "Unknown Curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
	//yymsg(WARNING, "Unknown Curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
	//yymsg(WARNING, "Unknown Curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
	//yymsg(WARNING, "Unknown Curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
	//yymsg(WARNING, "Unknown Curve %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = c->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
    }

  // Surfaces

  | tExtrude tSurface '{' FExpr ',' VExpr '}' tEND
    {
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE, (int)$4, $6[0], $6[1], $6[2],
					    0., 0., 0., 0., 0., 0., 0., 
					    0, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown Surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(ROTATE, (int)$4, 0., 0., 0.,
					    $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10,
					    0, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown Surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					    $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
					    0, NULL);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown Surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                      '{' ExtrudeParameters '}' tEND
    {
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE, (int)$4, $6[0], $6[1], $6[2],
					    0., 0., 0., 0., 0., 0., 0., 
					    NEWREG(), &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown Surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' 
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
  
                      '{' ExtrudeParameters '}' tEND
    {
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(ROTATE, (int)$4, 0., 0., 0.,
					    $6[0], $6[1], $6[2], $8[0], $8[1], $8[2], $10, 
					    NEWREG(), &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown Surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
  
                      '{' ExtrudeParameters '}' tEND
    {
      Shape TheShape;
      TheShape.Num = Extrude_ProtudeSurface(TRANSLATE_ROTATE, (int)$4, $6[0], $6[1], $6[2],
					    $8[0], $8[1], $8[2], $10[0], $10[1], $10[2], $12,
					    NEWREG(), &extr);
      Surface *s = FindSurface(TheShape.Num, THEM);
      if(!s){
	//yymsg(WARNING, "Unknown Surface %d", TheShape.Num);
	TheShape.Type = 0;
      }
      else{
	TheShape.Type = s->Typ;
      }
      $$ = List_Create(1, 1, sizeof(Shape));
      List_Add($$, &TheShape);
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
	  yymsg(WARNING, "Unknown Curve %d", j);
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
	  yymsg(WARNING, "Unknown Curve %d", j);
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
	  yymsg(WARNING, "Unknown Curve %d", j);
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
	yymsg(WARNING, "Unknown Surface %d", (int)$4);
      else{
	s->Method = TRANSFINI;
	int k = List_Nbr($7);
	if(k != 3 && k != 4){
	  yymsg(GERROR, "Wrong definition of Transfinite Surface %d: "
		"%d points instead of 3 or 4" , $4, k);
	}
	else{
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    s->ipar[i] = j;
	  }
	}
      }
      List_Delete($7);
    }
  | tElliptic tSurface '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Surface *s = FindSurface((int)$4, THEM);
      if(!s)
	yymsg(WARNING, "Unknown Surface %d", (int)$4);
      else{
        s->Method = ELLIPTIC;
        int k = List_Nbr($7);
        if(k != 4)
	  yymsg(GERROR, "Wrong definition of Elliptic Surface %d: "
		"%d points instead of 4" , $4, k);
        else{
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    s->ipar[i] = j;
	  }
	}
      }
      List_Delete($7);
    }
  | tTransfinite tVolume '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Volume *v = FindVolume((int)$4, THEM);
      if(!v)
	yymsg(WARNING, "Unknown Volume %d", (int)$4);
      else{
	v->Method = TRANSFINI;
	int k = List_Nbr($7);
	if(k != 6 && k != 8)
	  yymsg(GERROR, "Wrong definition of Transfinite Volume %d: "
		"%d points instead of 6 or 8" , $4, k);
	else{
	  for(int i = 0; i < k; i++){
	    double d;
	    List_Read($7, i, &d);
	    int j = (int)fabs(d);
	    v->ipar[i] = j;
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
	  s->RecombineAngle = 30.;
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
      if(!(pStrCat = Get_StringOptionCategory($3)))
	yymsg(GERROR, "Unknown string option class '%s'", $3);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($5, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s.%s'", $3, $5);
	else{
	  char *str = pStrOpt(0, GMSH_GET, NULL);
	  $$ = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy($$, str);
	}
      }
    }
  | tSprintf '('  tSTRING '[' FExpr ']' '.' tSTRING   ')'
    { 
      char* (*pStrOpt)(int num, int action, char *value);
      StringXString *pStrCat;
      if(!(pStrCat = Get_StringOptionCategory($3)))
	yymsg(GERROR, "Unknown string option class '%s'", $3);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($8, pStrCat)))
	  yymsg(GERROR, "Unknown string option '%s[%d].%s'", $3, (int)$5, $8);
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
  while(j < (int)strlen(format) && format[j]!='%') j++;
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
      while(format[j] != '%' && j < (int)strlen(format)) j++;
      if(k != j){
	strncpy(tmp1, &(format[k]), j-k);
	tmp1[j-k]='\0';
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

void yyerror(char *s){
  Msg(GERROR, "'%s', line %d : %s (%s)", yyname, yylineno-1, s, yytext);
  yyerrorstate=1;
}

void yymsg(int type, char *fmt, ...){
  va_list args;
  char tmp[1024];

  va_start (args, fmt);
  vsprintf (tmp, fmt, args);
  va_end (args);

  Msg(type, "'%s', line %d : %s", yyname, yylineno-1, tmp);

  if(type == GERROR) yyerrorstate=1;
}
