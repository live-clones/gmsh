%{ 

// $Id: Gmsh.y,v 1.116 2002-02-13 09:20:41 stainier Exp $

#include <stdarg.h>
#ifndef _NOPLUGIN
#include "PluginManager.h"
#endif
#include "ParUtil.h"
#include "Gmsh.h"
#include "Numeric.h"
#include "Context.h"
#include "Geo.h"
#include "CAD.h"
#include "DataBase.h"
#include "Mesh.h"
#include "Draw.h"
#include "Create.h"
#include "Views.h"
#include "StepGeomDatabase.h"
#include "Options.h"
#include "Colors.h"
#include "Parser.h"
#include "OpenFile.h"
#include "FunctionManager.h"
#include "ColorTable.h"
#include "Timer.h"
#include "CreateFile.h"
#include "STL.h"

#ifdef __DECCXX // bug in bison
#include <alloca.h>
#endif

List_T *Symbol_L=NULL;

extern Context_T  CTX;
extern Mesh      *THEM;

static FILE          *yyinTab[MAX_OPEN_FILES];
static int            yylinenoTab[MAX_OPEN_FILES];
static fpos_t         yyposImbricatedLoopsTab[MAX_OPEN_FILES];
static int            yylinenoImbricatedLoopsTab[MAX_OPEN_FILES];
static double         LoopControlVariablesTab[MAX_OPEN_FILES][3];
static char*          LoopControlVariablesNameTab[MAX_OPEN_FILES];
static char           yynameTab[MAX_OPEN_FILES][256];
static char           tmpstring[1024];
static Symbol         TheSymbol, *pSymbol;
static Surface       *STL_Surf;
static Shape          TheShape;
static int            i,j,k,flag,RecursionLevel=0,ImbricatedLoop = 0;
static int            Last_NumberOfPoints = 0;
static double         d, *pd;
static ExtrudeParams  extr;
static char           *str;
static StringXString  *pStrCat;
static StringXNumber  *pNumCat;
static StringXColor   *pColCat;
static double         (*pNumOpt)(int num, int action, double value);
static char*          (*pStrOpt)(int num, int action, char *value);
static unsigned int   (*pColOpt)(int num, int action, unsigned int value);
static Post_View      *View;

char *strsave(char *ptr);
void  yyerror (char *s);
void  vyyerror (char *fmt, ...);
void  skip_until (char *skip, char *until);
int PrintListOfDouble(char *format, List_T *list, char *buffer);
%}

%union {
  char    *c;
  int      i;
  unsigned int u;
  double   d;
  double   v[5];
  Shape    s;
  List_T  *l;
}

%token <d> tDOUBLE
%token <c> tSTRING tBIGSTR

%token tEND tAFFECT tDOTS tPi tMPI_Rank tMPI_Size
%token tExp tLog tLog10 tSqrt tSin tAsin tCos tAcos tTan tRand
%token tAtan tAtan2 tSinh tCosh tTanh tFabs tFloor tCeil
%token tFmod tModulo tHypot tPrintf tSprintf tStrCat tStrPrefix tDraw
%token tPoint tCircle tEllipsis tLine tSurface tSpline tVolume
%token tCharacteristic tLength tParametric tElliptic
%token tPlane tRuled tTransfinite tComplex tPhysical
%token tUsing tBump tProgression tPlugin
%token tRotate tTranslate tSymmetry tDilate tExtrude tDuplicata
%token tLoop tRecombine tDelete tCoherence tIntersect
%token tAttractor tLayers
%token tScalarTetrahedron tVectorTetrahedron tTensorTetrahedron
%token tScalarTriangle tVectorTriangle tTensorTriangle
%token tScalarLine tVectorLine tTensorLine
%token tScalarPoint tVectorPoint tTensorPoint
%token tText2D tText3D
%token tBSpline tBezier tNurbs tOrder tWith tBounds tKnots
%token tColor tColorTable tFor tIn tEndFor tIf tEndIf tExit
%token tReturn tCall tFunction tMesh

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
%token tSHAPE_DEFINITION_REPRESENTATION tELLIPSE tTrimmed

%token tSolid tEndSolid tVertex tFacet tNormal tOuter tLoopSTL tEndLoop tEndFacet

%type <d> FExpr FExpr_Single SignedDouble
%type <v> VExpr VExpr_Single
%type <i> BoolExpr NumericAffectation NumericIncrement
%type <u> ColorExpr
%type <c> StringExpr
%type <l> FExpr_Multi ListOfDouble RecursiveListOfDouble
%type <l> ListOfListOfDouble RecursiveListOfListOfDouble 
%type <l> ListOfColor RecursiveListOfColor 
%type <l> ListOfShapes Duplicata Transform MultipleShape
%type <l> ListOfStrings
%type <s> Shape

/* ------------------------------------------------------------------ */
/* Operators (with ascending priority): cf. C language                */
/*                                                                    */
/* Notes: - associativity (%left, %right)                             */
/*        - UNARYPREC is a dummy terminal to resolve ambiguous cases  */ 
/*          for + and - (which exist in both unary and binary form)   */
/* ------------------------------------------------------------------ */
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
%left    '(' ')' '[' ']' '.'
/* ------------------------------------------------------------------ */

%start All

%%

All : 
    StepFormatItems
  | STLFormatItem
  | GeomFormatList
  | error tEND { yyerrok ; return 1; }
;

/*  ----------------------------------------------------------------------
    S T E R E O L I T H O G R A P H Y  ( S T L )
    ---------------------------------------------------------------------- */

SignedDouble :
    tDOUBLE     { $$ = $1; }
  | '-' tDOUBLE { $$ = -$2; }
;

STLFormatItem : 
    tSolid
    {
      Msg(PARSER_INFO,"STL file format");
      STL_Surf = Create_Surface(1,MSH_SURF_STL);
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
      STL_Surf->STL->Add_Facet( $9, $10, $11,
				$13, $14, $15,
				$17, $18, $19);
      return 1;
    }
  | tEndSolid
    {
      Msg(PARSER_INFO,"STL file format read");
      Tree_Add(THEM->Surfaces, &STL_Surf);
      return 1;
    }
;

/*  ----------------------------------------------------------------------
    S T E P   I S O - 1 0 3 0 3 - 2 1   F I L E   F O R M A T
    ---------------------------------------------------------------------- */

StepFormatItems :
    /* nothing */
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
      Msg(PARSER_INFO,"Step Iso-10303-21 file format");
      Create_Step_Solid_BRep();
    }
  | tENDISO tEND
    {
      Msg(PARSER_INFO,"Step Iso-10303-21 file format read");
      Resolve_BREP ();
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
        Add_Cartesian_Point((int)$1,$5,$7[0],$7[1],$7[2]);
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
      Add_Face_Outer_Bound((int)$1,$5,(int)$7,$9,1);
    }
  | tDOUBLE tAFFECT tFACE_BOUND '(' tBIGSTR ',' tDOUBLE ','  BoolExpr  ')' tEND
    {
      /* La je dois voir la norme ! Face_Bound : trou externe a la surface ! */
      Msg(PARSER_INFO,"Found a face bound");
      Add_Face_Outer_Bound((int)$1,$5,(int)$7,$9,0);
    }
  | tDOUBLE tAFFECT tORIENTED_EDGE '(' tBIGSTR ',' '*' ','  '*' ','  FExpr ',' 
                                       BoolExpr ')' tEND
    {
      Add_Oriented_Edge((int)$1,$5,(int)$11,$13);
    }
  | tDOUBLE tAFFECT tEDGE_LOOP '(' tBIGSTR ',' ListOfDouble ')' tEND
    {
      Add_Edge_Loop((int)$1,$5,$7);
    }
  | tDOUBLE tAFFECT tADVANCED_FACE '(' tBIGSTR ',' ListOfDouble ',' 
                                       tDOUBLE ',' BoolExpr ')' tEND
    {
      Add_Advanced_Face((int)$1,$5,$7,(int)$9,$11);
    }
  | tDOUBLE tAFFECT tVERTEX_POINT '(' tBIGSTR ',' tDOUBLE ')'  tEND
    {
      Add_Vertex_Point((int)$1,$5,(int)$7);
    }
  | tDOUBLE tAFFECT tVECTOR '(' tBIGSTR ',' tDOUBLE ',' FExpr ')'  tEND
    {
    }
  | tDOUBLE  tAFFECT tAXIS2_PLACEMENT_3D '(' tBIGSTR ',' tDOUBLE ',' 
                                             tDOUBLE ',' tDOUBLE ')'  tEND
    {
      Add_Axis2_Placement3D  ( (int)$1, (int)$9, (int)$11, (int)$7);
    }
  | tDOUBLE tAFFECT tDIRECTION '(' tBIGSTR ',' VExpr ')' tEND
    {
      Add_Direction((int)$1 , $5, $7[0], $7[1], $7[2]);
    }
  | tDOUBLE tAFFECT tPLANE '(' tBIGSTR ',' tDOUBLE ')' tEND
    {
      Add_Plane((int)$1,$5,(int)$7);
    }
  | tDOUBLE tAFFECT tLine '(' tBIGSTR ',' tDOUBLE ',' tDOUBLE ')'  tEND
    {
      Add_Line ((int)$1, $5 , (int) $7, (int)$9);
    }
  | tDOUBLE tAFFECT tCLOSED_SHELL '(' tBIGSTR ',' ListOfDouble ')' tEND
    {
      Msg(PARSER_INFO,"Found a closed shell");
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
      Add_Cone ((int)$1, $5 , (int)$7, $9,$11);
    }
  | tDOUBLE tAFFECT tTOROIDAL_SURFACE '(' tBIGSTR ',' tDOUBLE ',' FExpr ',' FExpr ')' tEND
    {
      Add_Torus ((int)$1, $5 , (int)$7, $9,$11);
    }
  | tDOUBLE tAFFECT tCIRCLE '(' tBIGSTR ',' tDOUBLE ',' FExpr ')' tEND
    {
      Add_Circle((int) $1, $5, (int) $7, $9);
    }
  | tDOUBLE tAFFECT tELLIPSE '(' tBIGSTR ',' tDOUBLE ',' FExpr ',' FExpr ')' tEND
    {
      Add_Ellipsis((int) $1, $5, (int) $7, $9, $11);
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

/*  ----------------------------------------------------------------------
    G E O   F I L E   F O R M A T
    ---------------------------------------------------------------------- */

GeomFormatList : 
    /* none*/
  {
  }  
  | GeomFormatList GeomFormat
  {
      Msg(PARSER_INFO,"Gmsh file format read");
    }
;

GeomFormat :
    View        { return 1; }
  | Printf      { return 1; }
  | Affectation { return 1; }
  | Shape       { return 1; }
  | Transform   { return 1; }
  | Duplicata   { return 1; }
  | Delete      { return 1; }
  | Extrude     { return 1; }
  | Transfini   { return 1; }
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
      i = PrintListOfDouble($3,$5,tmpstring);
      if(i<0) 
	vyyerror("Too few arguments in Printf");
      else if(i>0)
	vyyerror("Too many arguments (%d) in Printf", i);
      else
	Msg(DIRECT, tmpstring);
      List_Delete($5);
    }
;

/* ------------
   V I E W 
   ------------ */

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
    /* none */
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
  | Views ScalarTetrahedron
  | Views VectorTetrahedron
  | Views TensorTetrahedron
  | Views Text2D
  | Views Text3D
;

ScalarPointValues :
    FExpr
    { List_Add(View->SP, &$1) ; }
  | ScalarPointValues ',' FExpr
    { List_Add(View->SP, &$3) ; }
  ;

ScalarPoint : 
    tScalarPoint '(' FExpr ',' FExpr ',' FExpr ')'
    { 
      List_Add(View->SP, &$3); List_Add(View->SP, &$5);
      List_Add(View->SP, &$7);
    }
    '{' ScalarPointValues '}' tEND
    {
      View->NbSP++ ;
    }
;

VectorPointValues :
    FExpr
    { List_Add(View->VP, &$1) ; }
  | VectorPointValues ',' FExpr
    { List_Add(View->VP, &$3) ; }
  ;

VectorPoint : 
    tVectorPoint '(' FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->VP, &$3); List_Add(View->VP, &$5);
      List_Add(View->VP, &$7); 
    }
    '{' VectorPointValues '}' tEND
    {
      View->NbVP++ ;
    }
;

TensorPointValues :
    FExpr
    { List_Add(View->TP, &$1) ; }
  | TensorPointValues ',' FExpr
    { List_Add(View->TP, &$3) ; }
  ;

TensorPoint :
    tTensorPoint '(' FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(View->TP, &$3); List_Add(View->TP, &$5);
      List_Add(View->TP, &$7);
    }
    '{' TensorPointValues '}' tEND
    {
      View->NbTP++ ;
    }
;

ScalarLineValues :
    FExpr
    { List_Add(View->SL, &$1) ; }
  | ScalarLineValues ',' FExpr
    { List_Add(View->SL, &$3) ; }
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
      View->NbSL++ ;
    }
;

VectorLineValues :
    FExpr
    { List_Add(View->VL, &$1) ; }
  | VectorLineValues ',' FExpr
    { List_Add(View->VL, &$3) ; }
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
      View->NbVL++ ;
    }
;

TensorLineValues :
    FExpr
    { List_Add(View->TL, &$1) ; }
  | TensorLineValues ',' FExpr
    { List_Add(View->TL, &$3) ; }
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
      View->NbTL++ ;
    }
;

ScalarTriangleValues :
    FExpr
    { List_Add(View->ST, &$1) ; }
  | ScalarTriangleValues ',' FExpr
    { List_Add(View->ST, &$3) ; }
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
      View->NbST++ ;
    }
;

VectorTriangleValues :
    FExpr
    { List_Add(View->VT, &$1) ; }
  | VectorTriangleValues ',' FExpr
    { List_Add(View->VT, &$3) ; }
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
      View->NbVT++ ;
    }
;

TensorTriangleValues :
    FExpr
    { List_Add(View->TT, &$1) ; }
  | TensorTriangleValues ',' FExpr
    { List_Add(View->TT, &$3) ; }
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
      View->NbTT++ ;
    }
;

ScalarTetrahedronValues :
    FExpr
    { List_Add(View->SS, &$1) ; }
  | ScalarTetrahedronValues ',' FExpr
    { List_Add(View->SS, &$3) ; }
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
      View->NbSS++ ;
    }
;

VectorTetrahedronValues :
    FExpr
    { List_Add(View->VS, &$1) ; }
  | VectorTetrahedronValues ',' FExpr
    { List_Add(View->VS, &$3) ; }
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
      View->NbVS++ ;
    }
;

TensorTetrahedronValues :
    FExpr
    { List_Add(View->TS, &$1) ; }
  | TensorTetrahedronValues ',' FExpr
    { List_Add(View->TS, &$3) ; }
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
      View->NbTS++ ;
    }
;

Text2DValues :
    StringExpr
    { 
      for(i=0; i<(int)strlen($1)+1; i++) List_Add(View->T2C, &$1[i]) ; 
      Free($1);
    }
  | Text2DValues ',' StringExpr
    { 
      for(i=0; i<(int)strlen($3)+1; i++) List_Add(View->T2C, &$3[i]) ; 
      Free($3);
    }
  ;

Text2D : 
    tText2D '(' FExpr ',' FExpr ',' FExpr ')'
    { 
      List_Add(View->T2D, &$3); List_Add(View->T2D, &$5);
      List_Add(View->T2D, &$7); 
      d = List_Nbr(View->T2C);
      List_Add(View->T2D, &d); 
    }
    '{' Text2DValues '}' tEND
    {
      View->NbT2++ ;
    }
;

Text3DValues :
    StringExpr
    { 
      for(i=0; i<(int)strlen($1)+1; i++) List_Add(View->T3C, &$1[i]) ; 
      Free($1);
    }
  | Text3DValues ',' StringExpr
    { 
      for(i=0; i<(int)strlen($3)+1; i++) List_Add(View->T3C, &$3[i]) ; 
      Free($3);
    }
  ;

Text3D : 
    tText3D '(' FExpr ',' FExpr ',' FExpr ',' FExpr ')'
    { 
      List_Add(View->T3D, &$3); List_Add(View->T3D, &$5);
      List_Add(View->T3D, &$7); List_Add(View->T3D, &$9); 
      d = List_Nbr(View->T3C);
      List_Add(View->T3D, &d); 
    }
    '{' Text3DValues '}' tEND
    {
      View->NbT3++ ;
    }
;


/* -----------------------
    A F F E C T A T I O N
   ----------------------- */

NumericAffectation :
    tAFFECT        { $$ = 0 ; }
  | tAFFECTPLUS    { $$ = 1 ; }
  | tAFFECTMINUS   { $$ = 2 ; }
  | tAFFECTTIMES   { $$ = 3 ; }
  | tAFFECTDIVIDE  { $$ = 4 ; }

NumericIncrement :
    tPLUSPLUS      { $$ = 1 ; }
  | tMINUSMINUS    { $$ = -1 ; }

Affectation :

  /* -------- Variables -------- */ 

    tSTRING NumericAffectation FExpr tEND
    {
      TheSymbol.Name = $1;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	if(!$2){
	  List_Put(TheSymbol.val, 0, &$3);
	  List_Add(Symbol_L, &TheSymbol);
	}
	else
	  vyyerror("Unknown variable '%s'", $1) ;
      }
      else{
	pd = (double*)List_Pointer_Fast(pSymbol->val, 0) ; 
	switch($2){
	case 0 : *pd = $3; break ;
	case 1 : *pd += $3 ; break ;
	case 2 : *pd -= $3 ; break ;
	case 3 : *pd *= $3 ; break ;
	case 4 : 
	  if($3) *pd /= $3 ; 
	  else vyyerror("Division by zero in '%s /= %g'", $1, $3);
	  break;
	}
      }
    }

  | tSTRING '[' FExpr ']' NumericAffectation FExpr tEND
    {
      TheSymbol.Name = $1;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(5,5,sizeof(double));
	if(!$5){
	  List_Put(TheSymbol.val, (int)$3, &$6);
	  List_Add(Symbol_L, &TheSymbol);
	}
	else
	  vyyerror("Unknown variable '%s'", $1) ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3))){
	  switch($5){
	  case 0 : *pd = $6; break ;
	  case 1 : *pd += $6 ; break ;
	  case 2 : *pd -= $6 ; break ;
	  case 3 : *pd *= $6 ; break ;
	  case 4 : 
	    if($6) *pd /= $6 ; 
	    else vyyerror("Division by zero in '%s[%d] /= %g'", $1, (int)$3, $6);
	    break;
	  }
	}
	else{
	  if(!$5)
	    List_Put(pSymbol->val, (int)$3, &$6);
	  else
	    vyyerror("Uninitialized variable '%s[%d]'", $1, (int)$3) ;
	}
      }
    }

  | tSTRING '[' '{' RecursiveListOfDouble '}' ']' NumericAffectation ListOfDouble tEND
    {
      if(List_Nbr($4) != List_Nbr($8))
	vyyerror("Incompatible array dimensions in affectation");
      else{
	TheSymbol.Name = $1;
	if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	  TheSymbol.val = List_Create(5,5,sizeof(double));
	  if(!$7){
	    for(i=0 ; i<List_Nbr($4) ; i++){
	      List_Put(TheSymbol.val, (int)(*(double*)List_Pointer($4,i)),
		       (double*)List_Pointer($8,i));
	    }
	    List_Add(Symbol_L, &TheSymbol);
	  }
	  else
	    vyyerror("Unknown variable '%s'", $1) ;
	}
	else{
	  for(i=0 ; i<List_Nbr($4) ; i++){
	    j = (int)(*(double*)List_Pointer($4,i)) ;
	    d = *(double*)List_Pointer($8,i) ;
	    if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	      switch($7){
	      case 0 : *pd = d; break ;
	      case 1 : *pd += d ; break ;
	      case 2 : *pd -= d ; break ;
	      case 3 : *pd *= d ; break ;
	      case 4 : 
		if($8) *pd /= d ; 
		else vyyerror("Division by zero in '%s[%d] /= %g'", $1, j, d);
		break;
	      }
	    }
	    else{
	      if(!$7)
		List_Put(pSymbol->val, j, &d);
	      else
		vyyerror("Uninitialized variable '%s[%d]'", $1, j) ;	  
	    }
	  }
	}
      }
      List_Delete($4);
      List_Delete($8);
    }

  | tSTRING '[' ']' tAFFECT ListOfDouble tEND
    {
      TheSymbol.Name = $1;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(5,5,sizeof(double));
	List_Copy($5,TheSymbol.val);
	List_Add(Symbol_L, &TheSymbol);
      }
      else{
	List_Reset(pSymbol->val);
	List_Copy($5, pSymbol->val);
      }
      List_Delete($5);
    }

  | tSTRING NumericIncrement tEND
    {
      TheSymbol.Name = $1;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown variable '%s'", $1) ; 
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += $2; 
    }

  | tSTRING '[' FExpr ']' NumericIncrement tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown variable '%s'", $1) ; 
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  *pd += $5 ;
	else
	  vyyerror("Uninitialized variable '%s[%d]'", $1, (int)$3) ;
      }
    }

  /* -------- Option Strings -------- */ 

  | tSTRING '.' tSTRING tAFFECT StringExpr tEND 
    { 
      if(!(pStrCat = Get_StringOptionCategory($1)))
	vyyerror("Unknown string option class '%s'", $1);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($3, pStrCat)))
	  vyyerror("Unknown string option '%s.%s'", $1, $3);
	else
	  pStrOpt(0,GMSH_SET|GMSH_GUI,$5) ;
      }
    }

  | tSTRING '[' FExpr ']' '.' tSTRING tAFFECT StringExpr tEND 
    { 
      if(!(pStrCat = Get_StringOptionCategory($1)))
	vyyerror("Unknown string option class '%s'", $1);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($6, pStrCat)))
	  vyyerror("Unknown string option '%s[%d].%s'", $1, (int)$3, $6);
	else
	  pStrOpt((int)$3,GMSH_SET|GMSH_GUI,$8) ;
      }
    }

  /* -------- Option Numbers -------- */ 

  | tSTRING '.' tSTRING NumericAffectation FExpr tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown numeric option class '%s'", $1);
      else{
	if(!(pNumOpt = (double (*) (int, int, double))Get_NumberOption($3, pNumCat)))
	  vyyerror("Unknown numeric option '%s.%s'", $1, $3);
	else{
	  switch($4){
	  case 0 : d = $5 ; break ;
	  case 1 : d = pNumOpt(0,GMSH_GET,0) + $5 ; break ;
	  case 2 : d = pNumOpt(0,GMSH_GET,0) - $5 ; break ;
	  case 3 : d = pNumOpt(0,GMSH_GET,0) * $5 ; break ;
	  case 4 : 
	    if($5) d = pNumOpt(0,GMSH_GET,0) / $5 ; 
	    else vyyerror("Division by zero in '%s.%s /= %g'", $1, $3, $5);
	    break;
	  }
	  pNumOpt(0,GMSH_SET|GMSH_GUI, d) ;
	}
      }
    }

  | tSTRING '[' FExpr ']' '.' tSTRING NumericAffectation FExpr tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown numeric option class '%s'", $1);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($6, pNumCat)))
	  vyyerror("Unknown numeric option '%s[%d].%s'", $1, (int)$3, $6);
	else{
	  switch($7){
	  case 0 : d = $8; break ;
	  case 1 : d = pNumOpt((int)$3,GMSH_GET,0) + $8 ; break ;
	  case 2 : d = pNumOpt((int)$3,GMSH_GET,0) - $8 ; break ;
	  case 3 : d = pNumOpt((int)$3,GMSH_GET,0) * $8 ; break ;
	  case 4 : 
	    if($8) d = pNumOpt((int)$3,GMSH_GET,0) / $8 ;
	    else vyyerror("Division by zero in '%s[%d].%s /= %g'", 
			  $1, (int)$3, $6, $8);
	    break;
	  }
	  pNumOpt((int)$3,GMSH_SET|GMSH_GUI,d) ;
	}
      }
    }

  | tSTRING '.' tSTRING NumericIncrement tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown numeric option class '%s'", $1);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($3, pNumCat)))
	  vyyerror("Unknown numeric option '%s.%s'", $1, $3);
	else
	  pNumOpt(0,GMSH_SET|GMSH_GUI,pNumOpt(0,GMSH_GET,0)+$4) ;
      }
    }

  | tSTRING '[' FExpr ']' '.' tSTRING NumericIncrement tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown numeric option class '%s'", $1);
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($6, pNumCat)))
	  vyyerror("Unknown numeric option '%s[%d].%s'", $1, (int)$3, $6);
	else
	  pNumOpt((int)$3,GMSH_SET|GMSH_GUI,pNumOpt((int)$3,GMSH_GET,0)+$7) ;
      }
    }

  /* -------- Option Colors -------- */ 

  | tSTRING '.' tColor '.' tSTRING tAFFECT ColorExpr tEND 
    {
      if(!(pColCat = Get_ColorOptionCategory($1)))
	vyyerror("Unknown color option class '%s'", $1);
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption($5, pColCat)))
	  vyyerror("Unknown color option '%s.Color.%s'", $1, $5);
	else
	  pColOpt(0,GMSH_SET|GMSH_GUI,$7) ;
      }
    }

  | tSTRING '[' FExpr ']' '.' tColor '.' tSTRING tAFFECT ColorExpr tEND 
    {
      if(!(pColCat = Get_ColorOptionCategory($1)))
	vyyerror("Unknown color option class '%s'", $1);
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption($8, pColCat)))
	  vyyerror("Unknown color option '%s[%d].Color.%s'", $1, (int)$3, $8);
	else
	  pColOpt((int)$3,GMSH_SET|GMSH_GUI,$10) ;
      }
    }

  /* -------- ColorTable -------- */ 

  | tSTRING '.' tColorTable tAFFECT ListOfColor tEND 
    {
      GmshColorTable *ct = Get_ColorTable(0);
      if(!ct)
	vyyerror("View[%d] does not exist", 0);
      else{
	ct->size = List_Nbr($5);
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  vyyerror("Too many (%d>%d) colors in View[%d].ColorTable", 
		   ct->size, COLORTABLE_NBMAX_COLOR, 0);
	else
	  for(i=0 ; i<ct->size ; i++) List_Read($5, i, &ct->table[i]);
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
	vyyerror("View[%d] does not exist", (int)$3);
      else{
	ct->size = List_Nbr($8);
	if(ct->size > COLORTABLE_NBMAX_COLOR)
	  vyyerror("Too many (%d>%d) colors in View[%d].ColorTable", 
		   ct->size, COLORTABLE_NBMAX_COLOR, (int)$3);
	else
	  for(i=0 ; i<ct->size ; i++) List_Read($8, i, &ct->table[i]);
	if(ct->size == 1){
	  ct->size = 2;
	  ct->table[1] = ct->table[0];
	}
      }
      List_Delete($8);
    }

  /* -------- Plugins -------- */ 

  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT FExpr tEND 
    {
      if(CTX.default_plugins){
	try {
	  GMSH_PluginManager::Instance()->SetPluginOption($3,$6,$8); 
	}
	catch (...) {
	  Msg(WARNING,"Unknown option '%s' or plugin '%s'",$6,$3);
	}
      }
    }

  | tPlugin '(' tSTRING ')' '.' tSTRING tAFFECT StringExpr tEND 
    {
      if(CTX.default_plugins){
	try {
	  GMSH_PluginManager::Instance()->SetPluginOption($3,$6,$8); 
	}
	catch (...) {
	  Msg(WARNING,"Unknown option '%s' or plugin '%s'",$6,$3);
	}
      }
    }
;


/* -----------
    S H A P E
   ----------- */

Shape :

  /* -------- Points -------- */ 

    tPoint '(' FExpr ')' tAFFECT VExpr tEND
    {
      Cdbpts101((int)$3,$6[0],$6[1],$6[2],$6[3],$6[4]);
      $$.Type = MSH_POINT;
      $$.Num  = (int)$3;
    }

  | tPhysical tPoint '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$4,MSH_PHYSICAL_POINT,0,0,0,0,0,NULL,$7,NULL);
      $$.Type = MSH_PHYSICAL_POINT;
      $$.Num  = (int)$4;
    }
  | tAttractor tPoint ListOfDouble tAFFECT '{' FExpr ',' FExpr ',' FExpr '}'  tEND
    {
      Vertex *v;
      Attractor *a;
      double p;
      int ip;
      for(int i=0;i<List_Nbr($3);i++){
      	List_Read($3,i,&p);
        ip = (int)p;
        v = FindPoint(ip,THEM);
        if(!v)
	  vyyerror("Unkown Point %d", ip);
	else{
	  a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
			       $6,$8,$10,v,NULL,NULL);
	  List_Add(THEM->Metric->Attractors,&a);
        }
      }
    }
  | tCharacteristic tLength ListOfDouble tAFFECT FExpr tEND
    {
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	Vertex *v = FindPoint((int)d,THEM);
	if(!v)
	  vyyerror("Unkown Point %d", (int)d);
	else
	  v->lc = $5;
      }
    }  

  /* -------- Lines -------- */ 

  | tLine '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbseg101((int)$3,MSH_SEGM_LINE,1,$6,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      $$.Type = MSH_SEGM_LINE;
      $$.Num  = (int)$3;
    }
  | tSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbseg101((int)$3,MSH_SEGM_SPLN,3,$6,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      $$.Type = MSH_SEGM_SPLN;
      $$.Num  = (int)$3;
    }
  | tAttractor tLine ListOfDouble tAFFECT '{' FExpr ',' FExpr ',' FExpr '}'  tEND
    {
      Curve *c;
      Attractor *a;
      double p;
      int ip;
      for(int i=0;i<List_Nbr($3);i++){
      	List_Read($3,i,&p);
        ip = (int)p;
        c = FindCurve(ip,THEM);
        if(!c)
	  vyyerror("Unkown Curve %d", ip);
	else{
	  a = Create_Attractor(List_Nbr(THEM->Metric->Attractors)+1,
			       $6,$8,$10,NULL,c,NULL);
	  List_Add(THEM->Metric->Attractors,&a);
        }
      }
    }
  | tCircle '(' FExpr ')'  tAFFECT ListOfDouble tEND
    {
      Cdbseg101((int)$3,MSH_SEGM_CIRC,2,$6,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      $$.Type = MSH_SEGM_CIRC ;
      $$.Num  = (int)$3;
    }
  | tEllipsis '(' FExpr ')'  tAFFECT ListOfDouble tEND
    {
      Cdbseg101((int)$3,MSH_SEGM_ELLI,2,$6,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      $$.Type = MSH_SEGM_ELLI ;
      $$.Num  = (int)$3;
    }
  | tCircle '(' FExpr ')'  tAFFECT ListOfDouble tPlane VExpr tEND
    {
      List_T *temp;
      int i,j;
      double d;
      temp = List_Create(List_Nbr($6),1,sizeof(int));
      for(i=0;i<List_Nbr($6);i++){
      	List_Read($6,i,&d);
        j = (int)d;
        List_Add(temp,&j);
      }
      AddCircleInDataBase ((int) $3, MSH_SEGM_CIRC, temp, $8);
      List_Delete(temp);
      $$.Type = MSH_SEGM_CIRC ;
      $$.Num  = (int)$3;
    }
  | tParametric '(' FExpr ')' tAFFECT 
      '{' FExpr ',' FExpr ',' tBIGSTR ',' tBIGSTR ',' tBIGSTR '}' tEND
    {
      Cdbseg101((int)$3,MSH_SEGM_PARAMETRIC,2,NULL,NULL,-1,-1,$7,$9,$11,$13,$15);
      $$.Type = MSH_SEGM_PARAMETRIC ;
      $$.Num  = (int)$3;
    }
  | tPhysical tLine '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$4,MSH_PHYSICAL_LINE,0,0,0,0,0,NULL,$7,NULL);
      $$.Type = MSH_PHYSICAL_LINE;
      $$.Num  = (int)$4;
    }
  | tLine tLoop '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      $$.Type = MSH_SEGM_LOOP;
      Cdbz101((int)$4,$$.Type,0,0,0,0,0,NULL,$7,NULL);
      $$.Num = (int)$4;
    }
  | tBSpline '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      if(List_Nbr($6) > 3){
	Cdbseg101((int)$3,MSH_SEGM_BSPLN,2,$6,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
	$$.Type = MSH_SEGM_BSPLN;
	$$.Num  = (int)$3;
      }
      else
	vyyerror("Too few control points for BSpline %d (%d < 4)", (int)$3, 
		 List_Nbr($6));
    }
  | tBezier '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      if(List_Nbr($6) > 3){
	Cdbseg101((int)$3,MSH_SEGM_BEZIER,2,$6,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
	$$.Type = MSH_SEGM_BSPLN;
	$$.Num  = (int)$3;
      }
      else
	vyyerror("Too few control points for Bezier %d (%d < 4)", (int)$3, 
		 List_Nbr($6));
    }
  | tNurbs  '(' FExpr ')' tAFFECT ListOfDouble tKnots ListOfDouble tOrder FExpr tEND
    {
      List_T *Temp;
      int i;
      double d;
      if(List_Nbr($6) + (int)$10 + 1 != List_Nbr($8)){
	vyyerror("Wrong definition of Nurbs Curve %d: "
		 "got %d Knots, need N + D + 1 = %d + %d + 1 = %d",
		 (int)$3, 
		 List_Nbr($8), List_Nbr($6), (int)$10, List_Nbr($6) + (int)$10 + 1);
      }
      else{
	Temp = List_Create(List_Nbr($6),1,sizeof(int));
	for(i=0;i<List_Nbr($6);i++) {
	  List_Read($6,i,&d);
	  j = (int)d;
	  List_Add(Temp,&j);
	}
	AddCurveInDataBase ((int)$3,MSH_SEGM_NURBS,(int)$10,Temp,$8,-1,-1,0.,1.);
	List_Delete(Temp);
      }
    }

  /* -------- Surfaces -------- */ 

  | tPlane tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$4,MSH_SURF_PLAN,0,0,0,0,0,NULL,$7,NULL);
      $$.Type = MSH_SURF_PLAN;
      $$.Num  = (int)$4;
    }
  | tTrimmed tSurface '(' FExpr ')' tAFFECT '{' FExpr ',' ListOfDouble '}' tEND
    {
      Surface *s,*support;
      support = FindSurface((int)$8,THEM);
      if(!support)
	vyyerror("Unkown Surface %d", (int)$8);
      else{
	Cdbz101((int)$4,MSH_SURF_PLAN,0,0,0,0,0,NULL,$10,NULL);
	s = FindSurface((int)$4,THEM);
	if(!s)
	  vyyerror("Unkown Surface %d", (int)$4);
	else{
	  s->Typ =  MSH_SURF_TRIMMED;
	  s->Support = support;
	  $$.Type = MSH_SURF_TRIMMED;
	  $$.Num  = (int)$4;
	}
      }
    }
  | tRuled tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      List_Read($7,0,&d);
      i = (int)d;
      EdgeLoop *el = FindEdgeLoop(i,THEM);
      if(!el)
	vyyerror("Unkown Line Loop %d", i);
      else{
	j = List_Nbr(el->Curves);
	if(j==4)
	  $$.Type = MSH_SURF_REGL;
	else if(j==3)
	  $$.Type  = MSH_SURF_TRIC;
	else
	  vyyerror("Wrong definition of Ruled Surface %d: "
		   "%d borders instead of 3 or 4", 
		   (int)$4, j);
	Cdbz101((int)$4,$$.Type,0,0,0,0,0,NULL,$7,NULL);
	$$.Num = (int)$4;
      }
    }
  | tNurbs tSurface tWith tBounds '(' FExpr ')' tAFFECT 
    ListOfListOfDouble tKnots  '{' ListOfDouble ',' ListOfDouble '}'
    tOrder '{' FExpr ',' FExpr '}' tEND
    {
      CreateNurbsSurface ( (int) $6 , (int)$18 , (int)$20  , $9, $12, $14);
      $$.Type  = MSH_SURF_NURBS;
      $$.Num = (int)$6;
    }
  | tNurbs  tSurface '(' FExpr ')' tAFFECT 
    ListOfListOfDouble tKnots  '{' ListOfDouble ',' ListOfDouble '}'
    tOrder '{' FExpr ',' FExpr '}' tEND
    {
      CreateNurbsSurfaceSupport ((int)$4, (int) $16 , (int) $18 , $7, $10, $12);
    }
  | tPhysical tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$4,MSH_PHYSICAL_SURFACE,0,0,0,0,0,NULL,$7,NULL);
      $$.Type = MSH_PHYSICAL_SURFACE;
      $$.Num  = (int)$4;
    }
  | tSurface tLoop '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$4,MSH_SURF_LOOP,0,0,0,0,0,NULL,$7,NULL);
      $$.Type = MSH_SURF_LOOP;
      $$.Num  = (int)$4;
    }

  /* -------- Volumes -------- */ 

  | tComplex tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$4,MSH_VOLUME,0,0,0,0,0,NULL,$7,NULL);
      $$.Type = MSH_VOLUME;
      $$.Num  = (int)$4;      
    }
  | tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$3,MSH_VOLUME,0,0,0,0,0,NULL,$6,NULL);
      $$.Type = MSH_VOLUME;
      $$.Num  = (int)$3;
    }
  | tPhysical tVolume '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$4,MSH_PHYSICAL_VOLUME,0,0,0,0,0,NULL,$7,NULL);
      $$.Type = MSH_PHYSICAL_VOLUME;
      $$.Num  = (int)$4;
    }
;

/* -------------------
    T R A N S F O R M
   ------------------- */

Transform :
    tTranslate VExpr '{' MultipleShape '}'
    {
      TranslateShapes ($2[0],$2[1],$2[2],$4,1);
      $$ = $4;
    }
  | tRotate '{' VExpr ',' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      RotateShapes($3[0],$3[1],$3[2],$5[0],$5[1],$5[2],$7,$10);
      $$ = $10;
    }
  | tSymmetry  VExpr   '{' MultipleShape '}'
    {
      SymmetryShapes($2[0],$2[1],$2[2],$2[3],$4,1);
      $$ = $4;
    }
  | tDilate '{' VExpr ',' FExpr '}' '{' MultipleShape '}'
    {
      DilatShapes($3[0],$3[1],$3[2],$5,$8,1);
      $$ = $8;
    }
;

MultipleShape : 
    Duplicata     { $$ = $1; }
  | ListOfShapes  { $$ = $1; }
  | Transform     { $$ = $1; }
;

ListOfShapes : 
    /* none */
    {
      $$ = List_Create(3,3,sizeof(Shape));
    }   
  | ListOfShapes Shape
    {
      List_Add($$,&$2);
      $$ = $1;
    }
  | ListOfShapes tPoint '{' RecursiveListOfDouble '}' tEND
    {
      for(i=0;i<List_Nbr($4);i++){
	List_Read($4, i, &d);
	TheShape.Num = (int)d;
	Vertex *v = FindPoint(TheShape.Num,THEM);
	if(!v)
	  vyyerror("Unknown Point %d", TheShape.Num);
	else{
	  TheShape.Type = MSH_POINT;
	  List_Add($$,&TheShape);
	}
      }
      $$ = $1;
    }
  | ListOfShapes tLine '{' RecursiveListOfDouble '}' tEND
    {
      for(i=0;i<List_Nbr($4);i++){
	List_Read($4, i, &d);
	TheShape.Num = (int)d;
	Curve *c = FindCurve(TheShape.Num,THEM);
	if(!c)
	  vyyerror("Unknown Curve %d", TheShape.Num);
	else{
	  TheShape.Type = c->Typ;
	  List_Add($$,&TheShape);
	}
      }
      $$ = $1;
    }
  | ListOfShapes tSurface '{' RecursiveListOfDouble '}' tEND
    {
      for(i=0;i<List_Nbr($4);i++){
	List_Read($4, i, &d);
	TheShape.Num = (int)d;
	Surface *s = FindSurface(TheShape.Num,THEM);
	if(!s)
	  vyyerror("Unknown Surface %d", TheShape.Num);
	else{
	  TheShape.Type = s->Typ;
	  List_Add($$,&TheShape);
	}
      }
      $$ = $1;
    }
;

/* -------------------
    D U P L I C A T A
   ------------------- */

Duplicata :
    tDuplicata '{' ListOfShapes '}'
    {
      $$ = List_Create(3,3,sizeof(Shape));
      for(i=0;i<List_Nbr($3);i++){
	List_Read ($3,i,&TheShape);
	CopyShape(TheShape.Type,TheShape.Num,&j);
	TheShape.Num = j;
	List_Add($$,&TheShape);
      }
    }
;


/* -------------
    D E L E T E 
   ------------- */

Delete :
    tDelete '{' ListOfShapes '}'
    {
      for(i=0;i<List_Nbr($3);i++){
	List_Read ($3,i,&TheShape);
	DeleteShape(TheShape.Type,TheShape.Num);
      }
    }
    | tDelete tSTRING '[' FExpr ']' tEND
      {
	if(!strcmp($2, "View"))
	  FreeView((int)$4);
      }
    | tDelete tMesh tEND
    {
      Init_Mesh(THEM, 1);
    }
;


/* -----------------
    C O M M A N D  
   ----------------- */

Command :
    tSTRING StringExpr tEND
    {
      if(!strcmp($1, "Include")){

	yyinTab[RecursionLevel++] = yyin;

	strcpy(tmpstring, yyname);
	i = strlen(yyname)-1 ;
	while(i >= 0 && yyname[i] != '/' && yyname[i] != '\\') i-- ;
	tmpstring[i+1] = '\0';
	strcat(tmpstring,$2);

	if((yyin = fopen(tmpstring,"r"))){
	  Msg(INFO, "Including '%s'", tmpstring); 
	  strcpy(yynameTab[RecursionLevel-1],yyname);
	  yylinenoTab[RecursionLevel-1]=yylineno;
	  yylineno=1;
	  strcpy(yyname,tmpstring);
	  while(!feof(yyin)){
	    yyparse();
	  }
	  //
	  //Est-ce grave de laisser le stream ouvert? Si on fait le
	  //fclose, on ne peut pas faire appel a une fonction
	  //(Function) definie en dehors de son fichier de
	  //definition...
	  //
	  //fclose(yyin);
	  yyin = yyinTab[--RecursionLevel];
	  strcpy(yyname,yynameTab[RecursionLevel]);
	  yylineno = yylinenoTab[RecursionLevel];
	}
	else{
	  vyyerror("Unknown file '%s'", tmpstring) ;  
	  yyin = yyinTab[--RecursionLevel];
	}

      }
      else if(!strcmp($1, "Print")){
	if(!CTX.batch) CreateOutputFile($2, CTX.print.format);
      }
      else if(!strcmp($1, "Save")){
	CreateOutputFile($2, CTX.mesh.format);
      }
      else if(!strcmp($1, "Merge")){

	FILE *ff = yyin;
	MergeProblem($2);
	yyin = ff;

      }
      else if(!strcmp($1, "Open")){

	FILE *ff = yyin;
	OpenProblem($2);
	yyin = ff;

      }
      else if(!strcmp($1, "System")){
	
	Msg(PARSER_INFO, "Executing system call \"%s\"", $2);
	system($2);

      }
      else
	vyyerror("Unknown command '%s'", $1);
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

	//Maillage_Dimension_0(THEM);
	//mai3d(THEM,(int)$2);
	vyyerror("Mesh directives are not (yet) allowed in scripts");

      }
      else
	vyyerror("Unknown command '%s'", $1);
    }
   | tPlugin '(' tSTRING ')' '.' tSTRING tEND
   {
#ifndef _NOPLUGIN
    if(CTX.default_plugins)
      GMSH_PluginManager::Instance()->Action($3,$6,0); 
#endif
   }
   | tExit tEND
    {
      exit(0);
    } 
   | tDraw tEND
    {
      if(!CTX.batch){ // we're in interactive mode
	if(Tree_Nbr(THEM->Points) != Last_NumberOfPoints){
	  Last_NumberOfPoints = Tree_Nbr(THEM->Points);
	  Replot();
	  DrawUI();
	}
	else{
	  Draw();
	  DrawUI();
	}
      }
    }
;

/* ---------------
    L O O P  
   --------------- */

Loop :   

    tFor '(' FExpr tDOTS FExpr ')'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $3 ;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5 ;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = "" ;
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
  | tFor '(' FExpr tDOTS FExpr tDOTS FExpr ')'
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $3 ;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5 ;
      LoopControlVariablesTab[ImbricatedLoop][2] = $7 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = "" ;
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr '}' 
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $5 ;
      LoopControlVariablesTab[ImbricatedLoop][1] = $7 ;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = $2 ;
      
      TheSymbol.Name = $2;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	List_Put(TheSymbol.val, 0, &$5);
	List_Add(Symbol_L, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &$5);
      }
      
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr tDOTS FExpr '}' 
    {
      LoopControlVariablesTab[ImbricatedLoop][0] = $5 ;
      LoopControlVariablesTab[ImbricatedLoop][1] = $7 ;
      LoopControlVariablesTab[ImbricatedLoop][2] = $9 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = $2 ;

      TheSymbol.Name = $2;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	List_Put(TheSymbol.val, 0, &$5);
	List_Add(Symbol_L, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &$5);
      }
      
      fgetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop]);
      yylinenoImbricatedLoopsTab[ImbricatedLoop] = yylineno;
      ImbricatedLoop++;
    }
  | tEndFor 
    {
      if(LoopControlVariablesTab[ImbricatedLoop-1][1] >  
	 LoopControlVariablesTab[ImbricatedLoop-1][0]){
	LoopControlVariablesTab[ImbricatedLoop-1][0] +=
	  LoopControlVariablesTab[ImbricatedLoop-1][2];
	
	if(strlen(LoopControlVariablesNameTab[ImbricatedLoop-1])){
	  TheSymbol.Name = LoopControlVariablesNameTab[ImbricatedLoop-1];
	  pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols);
	  *(double*)List_Pointer_Fast(pSymbol->val, 0) += 
	    LoopControlVariablesTab[ImbricatedLoop-1][2] ;
	}
	
	fsetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop-1]);
	yylineno = yylinenoImbricatedLoopsTab[ImbricatedLoop-1];
      }
      else{
	ImbricatedLoop--;
      }
    }
  | tFunction tSTRING
    {
      if(!FunctionManager::Instance()->createFunction($2,yyin,yyname,yylineno))
	vyyerror("Redefinition of function %s",$2);
      skip_until(NULL, "Return");
    }
  | tReturn
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin,yyname,yylineno))
	vyyerror("Error while exiting function");
    } 
  | tCall tSTRING tEND
    {
      if(!FunctionManager::Instance()->enterFunction($2,&yyin,yyname,yylineno))
	vyyerror("Unknown function %s",$2);
    } 
  | tIf '(' FExpr ')'
    {
      if(!$3) skip_until("If", "EndIf");
    }
  | tEndIf
    {
    }
;


/* ---------------
    E X T R U D E 
   --------------- */

Extrude :
  /* -------- Points -------- */ 
    tExtrude tPoint '{' FExpr ',' VExpr '}' tEND
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(TRANSLATE,(int)$4,$6[0],$6[1],$6[2],
			   0.,0.,0.,0.,0.,0.,0.,
			   &pc,&prc,NULL);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(ROTATE,(int)$4,0.,0.,0.,
			   $6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,
			   &pc,&prc,NULL);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr'}' tEND
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(TRANSLATE_ROTATE,(int)$4,$6[0],$6[1],$6[2],
			   $8[0],$8[1],$8[2],$10[0],$10[1],$10[2],$12,
			   &pc,&prc,NULL);
    }
  /* -------- Lines -------- */ 

  | tExtrude tLine '{' FExpr ',' VExpr '}' tEND
    {
      Extrude_ProtudeCurve(TRANSLATE,(int)$4,$6[0],$6[1],$6[2],
			   0.,0.,0.,0.,0.,0.,0.,1,NULL);
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Extrude_ProtudeCurve(ROTATE,(int)$4,0.,0.,0.,
			   $6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,1,NULL);
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Extrude_ProtudeCurve(TRANSLATE_ROTATE,(int)$4,$6[0],$6[1],$6[2],
			   $8[0],$8[1],$8[2],$10[0],$10[1],$10[2],$12,1,NULL);
    }
  | tExtrude tLine '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Extrude_ProtudeCurve(TRANSLATE,(int)$4,$6[0],$6[1],$6[2],
			   0.,0.,0.,0.,0.,0.,0.,1,&extr);
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Extrude_ProtudeCurve(ROTATE,(int)$4,0.,0.,0.,
			   $6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,1,&extr);
    }
  | tExtrude tLine '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                   '{' ExtrudeParameters '}' tEND
    {
      Extrude_ProtudeCurve(TRANSLATE_ROTATE,(int)$4,$6[0],$6[1],$6[2],
			   $8[0],$8[1],$8[2],$10[0],$10[1],$10[2],$12,1,&extr);
    }

  /* -------- Surfaces -------- */ 

  | tExtrude tSurface '{' FExpr ',' VExpr '}' tEND
    {
      Extrude_ProtudeSurface(TRANSLATE,(int)$4,$6[0],$6[1],$6[2],
			     0.,0.,0.,0.,0.,0.,0.,0,NULL);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Extrude_ProtudeSurface(ROTATE,(int)$4,0.,0.,0.,
			     $6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,0,NULL);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Extrude_ProtudeSurface(TRANSLATE_ROTATE,(int)$4,$6[0],$6[1],$6[2],
			     $8[0],$8[1],$8[2],$10[0],$10[1],$10[2],$12,0,NULL);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
                      '{' ExtrudeParameters '}' tEND
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(TRANSLATE,(int)$4,$6[0],$6[1],$6[2],
			     0.,0.,0.,0.,0.,0.,0.,vol,&extr);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' 
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
  
                      '{' ExtrudeParameters '}'tEND
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(ROTATE,(int)$4,0.,0.,0.,
			     $6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,vol,&extr);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' VExpr ',' FExpr '}'
    {
      extr.mesh.ExtrudeMesh = false;
      extr.mesh.Recombine = false;
    }
  
                      '{' ExtrudeParameters '}'tEND
    {
      int vol = NEWREG();
      Extrude_ProtudeSurface(TRANSLATE_ROTATE,(int)$4,$6[0],$6[1],$6[2],
			     $8[0],$8[1],$8[2],$10[0],$10[1],$10[2],$12,vol,&extr);
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
	for(int i=0;i<List_Nbr($3);i++){
	  List_Read($3,i,&d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  List_Read($5,i,&d);
	  extr.mesh.ZonLayer[i] = (int)d;
	  List_Read($7,i,&d);
	  extr.mesh.hLayer[i] = d;
	}
      }
      else{
	vyyerror("Wrong layer definition {%d, %d, %d}", 
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
	for(int i=0;i<List_Nbr($3);i++){
	  List_Read($3,i,&d);
	  extr.mesh.NbElmLayer[i] = (d>0)?(int)d:1;
	  extr.mesh.ZonLayer[i] = 0;
	  List_Read($5,i,&d);
	  extr.mesh.hLayer[i] = d;
	}
      }
      else{
	vyyerror("Wrong layer definition {%d, %d}", 
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

/* -------------------
    T R A N S F I N I
   ------------------- */

Transfini : 
    tTransfinite tLine ListOfDouble tAFFECT FExpr tEND
    {
      Curve *c;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)fabs(d);
        c = FindCurve(j,THEM);
	if(!c)
	  Msg(WARNING, "Unkown Curve %d", j);
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
      Curve *c;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)fabs(d);
        c = FindCurve(j,THEM);
	if(!c)
	  Msg(WARNING, "Unkown Curve %d", j);
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
      Curve *c;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)fabs(d);
        c = FindCurve(j,THEM);
	if(!c)
	  Msg(WARNING, "Unkown Curve %d", j);
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
      Surface *s = FindSurface((int)$4,THEM);
      if(!s)
	Msg(WARNING, "Unkown Surface %d", (int)$4);
      else{
	s->Method = TRANSFINI;
	k = List_Nbr($7);
	if(k!=3 && k!=4){
	  vyyerror("Wrong definition of Transfinite Surface %d: "
		   "%d points instead of 3 or 4" , $4, k) ;
	}
	else{
	  for(i=0;i<k;i++){
	    List_Read($7,i,&d);
	    j = (int)fabs(d);
	    s->ipar[i] = j;
	  }
	}
      }
      List_Delete($7);
    }
  | tElliptic tSurface '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Surface *s = FindSurface((int)$4,THEM);
      if(!s)
	Msg(WARNING, "Unkown Surface %d", (int)$4);
      else{
        s->Method = ELLIPTIC;
        k = List_Nbr($7);
        if(k != 4)
	  vyyerror("Wrong definition of Elliptic Surface %d: "
		   "%d points instead of 4" , $4, k) ;
        else{
	  for(i=0;i<k;i++){
	    List_Read($7,i,&d);
	    j = (int)fabs(d);
	    s->ipar[i] = j;
	  }
	}
      }
      List_Delete($7);
    }
  | tTransfinite tVolume '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Volume *v = FindVolume((int)$4,THEM);
      if(!v)
	Msg(WARNING, "Unkown Volume %d", (int)$4);
      else{
	v->Method = TRANSFINI;
	k = List_Nbr($7);
	if(k!=6 && k!=8)
	  vyyerror("Wrong definition of Transfinite Volume %d: "
		   "%d points instead of 6 or 8" , $4, k) ;
	else{
	  for(i=0;i<k;i++){
	    List_Read($7,i,&d);
	    j = (int)fabs(d);
	    v->ipar[i] = j;
	  }
	}
      }
      List_Delete($7);
    }
  | tRecombine tSurface ListOfDouble tAFFECT FExpr tEND
    {
      Surface *s;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)d;
	s = FindSurface(j,THEM);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = ($5 > 0 && $5 < 90) ? $5 : 90;
	}
      }
      List_Delete($3);
    }
  | tRecombine tSurface ListOfDouble tEND
    {
      Surface *s;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)d;
        s = FindSurface(j,THEM);
	if(s){
	  s->Recombine = 1;
	  s->RecombineAngle = 30.;
        }
      }
      List_Delete($3);
    }
;


/* -------------------
    C O H E R E N C E
   ------------------- */

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


/* ---------------
    G E N E R A L
    --------------- */

BoolExpr :
    tTRUE {$$ = 1;}
  | tFALSE {$$ = 0;}
  | tUNSPECIFIED {$$ = -1;}
  | tU {$$ = -1;}
  | tV {$$ = -1;}
  ;

FExpr :
    FExpr_Single                     { $$ = $1;           }
  | '(' FExpr ')'                    { $$ = $2 ;          }
  | '-' FExpr %prec UNARYPREC        { $$ = -$2 ;         }
  | '+' FExpr %prec UNARYPREC        { $$ = $2;           }
  | '!' FExpr                        { $$ = !$2 ;         }
  | FExpr '-' FExpr                  { $$ = $1 - $3 ;     }
  | FExpr '+' FExpr                  { $$ = $1 + $3 ;     }
  | FExpr '*' FExpr                  { $$ = $1 * $3 ;     }
  | FExpr '/' FExpr
    { 
      if(!$3)
	vyyerror("Division by zero in '%g / %g'", $1, $3);
      else
	$$ = $1 / $3 ;     
    }
  | FExpr '%' FExpr                  { $$ = (int)$1 % (int)$3 ;  }
  | FExpr '^' FExpr                  { $$ = pow($1,$3) ;  }
  | FExpr '<' FExpr                  { $$ = $1 < $3 ;     }
  | FExpr '>' FExpr                  { $$ = $1 > $3 ;     }
  | FExpr tLESSOREQUAL FExpr         { $$ = $1 <= $3 ;    }
  | FExpr tGREATEROREQUAL FExpr      { $$ = $1 >= $3 ;    }
  | FExpr tEQUAL FExpr               { $$ = $1 == $3 ;    }
  | FExpr tNOTEQUAL FExpr            { $$ = $1 != $3 ;    }
  | FExpr tAND FExpr                 { $$ = $1 && $3 ;    }
  | FExpr tOR FExpr                  { $$ = $1 || $3 ;    }
  | FExpr '?' FExpr tDOTS FExpr      { $$ = $1? $3 : $5 ; }
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
  | tAtan2  '(' FExpr ',' FExpr ')'  { $$ = atan2($3,$5); }
  | tSinh   '(' FExpr ')'            { $$ = sinh($3);     }
  | tCosh   '(' FExpr ')'            { $$ = cosh($3);     }
  | tTanh   '(' FExpr ')'            { $$ = tanh($3);     }
  | tFabs   '(' FExpr ')'            { $$ = fabs($3);     }
  | tFloor  '(' FExpr ')'            { $$ = floor($3);    }
  | tCeil   '(' FExpr ')'            { $$ = ceil($3);     }
  | tFmod   '(' FExpr ',' FExpr ')'  { $$ = fmod($3,$5);  }
  | tModulo '(' FExpr ',' FExpr ')'  { $$ = fmod($3,$5);  }
  | tHypot  '(' FExpr ',' FExpr ')'  { $$ = sqrt($3*$3+$5*$5); }
  | tRand   '(' FExpr ')'            { $$ = $3*(double)rand()/(double)RAND_MAX; }
  /* for GetDP compatibility */
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
  | tAtan2  '[' FExpr ',' FExpr ']'  { $$ = atan2($3,$5); }
  | tSinh   '[' FExpr ']'            { $$ = sinh($3);     }
  | tCosh   '[' FExpr ']'            { $$ = cosh($3);     }
  | tTanh   '[' FExpr ']'            { $$ = tanh($3);     }
  | tFabs   '[' FExpr ']'            { $$ = fabs($3);     }
  | tFloor  '[' FExpr ']'            { $$ = floor($3);    }
  | tCeil   '[' FExpr ']'            { $$ = ceil($3);     }
  | tFmod   '[' FExpr ',' FExpr ']'  { $$ = fmod($3,$5);  }
  | tModulo '[' FExpr ',' FExpr ']'  { $$ = fmod($3,$5);  }
  | tHypot  '[' FExpr ',' FExpr ']'  { $$ = sqrt($3*$3+$5*$5); }
  | tRand   '[' FExpr ']'            { $$ = $3*(double)rand()/(double)RAND_MAX; }
;

/* Pour etre vraiment complet, il faudrait encore ajouter +=, -=, *= et /= */

FExpr_Single :

  /* -------- Constants -------- */ 

    tDOUBLE   { $$ = $1; }
  | tPi       { $$ = 3.141592653589793; }
  | tMPI_Rank { $$ = ParUtil::Instance()->rank(); }
  | tMPI_Size { $$ = ParUtil::Instance()->size(); }

  /* -------- Variables -------- */ 

  | tSTRING
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown variable '%s'", $1) ;
	$$ = 0. ;
      }
      else
	$$ = *(double*)List_Pointer_Fast(pSymbol->val, 0) ;
    }

  | tSTRING '[' FExpr ']'
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown variable '%s'", $1) ;
	$$ = 0. ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  $$ = *pd ;
	else{
	  vyyerror("Uninitialized variable '%s[%d]'", $1, (int)$3) ;
	  $$ = 0. ;
	}
      }
    }

  | tSTRING NumericIncrement
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown variable '%s'", $1) ;
	$$ = 0. ;
      }
      else
	$$ = (*(double*)List_Pointer_Fast(pSymbol->val, 0) += $2) ;
    }

  | tSTRING '[' FExpr ']' NumericIncrement
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown variable '%s'", $1) ;
	$$ = 0. ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  $$ = (*pd += $5) ;
	else{
	  vyyerror("Uninitialized variable '%s[%d]'", $1, (int)$3) ;
	  $$ = 0. ;
	}
      }
    }

  /* -------- Option Strings -------- */ 

  | tSTRING '.' tSTRING 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	vyyerror("Unknown numeric option class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($3, pNumCat))){
	  vyyerror("Unknown numeric option '%s.%s'", $1, $3);
	  $$ = 0. ;
	}
	else
	  $$ = pNumOpt(0, GMSH_GET, 0);
      }
    }

  | tSTRING '[' FExpr ']' '.' tSTRING 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	vyyerror("Unknown numeric option class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($6, pNumCat))){
	  vyyerror("Unknown numeric option '%s[%d].%s'", $1, (int)$3, $6);
	  $$ = 0. ;
	}
	else
	  $$ = pNumOpt((int)$3, GMSH_GET, 0);
      }
    }

  | tSTRING '.' tSTRING NumericIncrement
    {
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	vyyerror("Unknown numeric option class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($3, pNumCat))){
	  vyyerror("Unknown numeric option '%s.%s'", $1, $3);
	  $$ = 0. ;
	}
	else
	  $$ = pNumOpt(0, GMSH_SET|GMSH_GUI, pNumOpt(0, GMSH_GET, 0)+$4);
      }
    }

  | tSTRING '[' FExpr ']' '.' tSTRING NumericIncrement
    {
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	vyyerror("Unknown numeric option class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt =  (double (*) (int, int, double))Get_NumberOption($6, pNumCat))){
	  vyyerror("Unknown numeric option '%s[%d].%s'", $1, (int)$3, $6);
	  $$ = 0. ;
	}
	else
	  $$ = pNumOpt((int)$3, GMSH_SET|GMSH_GUI, pNumOpt((int)$3, GMSH_GET, 0)+$7);
      }
    }
;

VExpr :
    VExpr_Single
    {
      memcpy($$, $1, 5*sizeof(double)) ;
    }
  | '-' VExpr %prec UNARYPREC
    {
      for(i=0 ; i<5 ; i++) $$[i] = -$2[i] ;
    }
  | '+' VExpr %prec UNARYPREC
    { 
      for(i=0 ; i<5 ; i++) $$[i] = $2[i];
    }
  | VExpr '-' VExpr
    { 
      for(i=0 ; i<5 ; i++) $$[i] = $1[i] - $3[i] ;
    }
  | VExpr '+' VExpr
    {
      for(i=0 ; i<5 ; i++) $$[i] = $1[i] + $3[i] ;
    }

VExpr_Single :
    '{' FExpr ',' FExpr ',' FExpr ',' FExpr ',' FExpr  '}'
    { 
      $$[0]=$2;  $$[1]=$4;  $$[2]=$6;  $$[3]=$8; $$[4]=$10;
    }
  | '{' FExpr ',' FExpr ',' FExpr ',' FExpr '}'
    { 
      $$[0]=$2;  $$[1]=$4;  $$[2]=$6;  $$[3]=$8; $$[4]=1.0;
    }
  | '{' FExpr ',' FExpr ',' FExpr '}'
    {
      $$[0]=$2;  $$[1]=$4;  $$[2]=$6;  $$[3]=0.0; $$[4]=1.0;
    }
  | '(' FExpr ',' FExpr ',' FExpr ')'
    {
      $$[0]=$2;  $$[1]=$4;  $$[2]=$6;  $$[3]=0.0; $$[4]=1.0;
    }
;

ListOfStrings :
    /* none */
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
    /* none */
    {
    }
  | '{' RecursiveListOfListOfDouble '}'
    {
       $$=$2;
    }
  | '(' RecursiveListOfListOfDouble ')'
    {
       $$=$2;
    }
;

RecursiveListOfListOfDouble :
    ListOfDouble
    {
      $$ = List_Create(2,1,sizeof(List_T*)) ;
      List_Add($$, &($1)) ;
    }
  | RecursiveListOfListOfDouble ',' ListOfDouble
    {
      List_Add($$, &($3)) ;
    }
;


ListOfDouble :
    FExpr
    {
      $$ = List_Create(2,1,sizeof(double)) ;
      List_Add($$, &($1)) ;
    }
  | FExpr_Multi
    {
      $$ = $1 ;
    }
  | '{' RecursiveListOfDouble '}'
    {
      $$=$2;
    }
  | '-' '{' RecursiveListOfDouble '}'
    {
      $$=$3;
      for(i=0 ; i<List_Nbr($$) ; i++){
	pd = (double*)List_Pointer($$, i);
	(*pd) = - (*pd);
      }
    }
;

FExpr_Multi :
    FExpr tDOTS FExpr
    { 
      $$ = List_Create(2,1,sizeof(double)) ; 
      for(d=$1 ; ($1<$3)?(d<=$3):(d>=$3) ; ($1<$3)?(d+=1.):(d-=1.)) 
	List_Add($$, &d) ;
    }
  | FExpr tDOTS FExpr tDOTS FExpr
   {
      $$ = List_Create(2,1,sizeof(double)) ; 
      if(!$5 || ($1<$3 && $5<0) || ($1>$3 && $5>0)){
        vyyerror("Wrong increment in '%g:%g:%g'", $1, $3, $5) ;
	List_Add($$, &($1)) ;
      }
      else
	for(d=$1 ; ($5>0)?(d<=$3):(d>=$3) ; d+=$5)
	  List_Add($$, &d) ;
   }
  | tSTRING '[' ']'
    {
      $$ = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown variable '%s'", $1) ;
	d = 0.0 ;
	List_Add($$, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr(pSymbol->val) ; i++)
	  List_Add($$, (double*)List_Pointer_Fast(pSymbol->val, i)) ;
      }
    }
  | '-' tSTRING '[' ']'
    {
      $$ = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = $2 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown variable '%s'", $2) ;
	d = 0.0 ;
	List_Add($$, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr(pSymbol->val) ; i++){
	  d = - *(double*)List_Pointer_Fast(pSymbol->val, i);
	  List_Add($$, &d) ;
	}
      }
    }
  | tSTRING '[' '{' RecursiveListOfDouble '}' ']'
    {
      $$ = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown variable '%s'", $1) ;
	d = 0.0 ;
	List_Add($$, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr($4) ; i++){
	  j = (int)(*(double*)List_Pointer_Fast($4, i));
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j)))
	    List_Add($$, pd) ;
	  else
	    vyyerror("Uninitialized variable '%s[%d]'", $1, j) ;	  
	}
      }
      List_Delete($4);
    }
  | '-' tSTRING '[' '{' RecursiveListOfDouble '}' ']'
    {
      $$ = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = $2 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown variable '%s'", $2) ;
	d = 0.0 ;
	List_Add($$, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr($5) ; i++){
	  j = (int)(*(double*)List_Pointer_Fast($5, i));
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, j))){
	    d = - *pd;
	    List_Add($$, &d) ;
	  }
	  else
	    vyyerror("Uninitialized variable '%s[%d]'", $2, j) ;	  
	}
      }
      List_Delete($5);
    }
;

RecursiveListOfDouble :
    FExpr
    {
      $$ = List_Create(2,1,sizeof(double)) ;
      List_Add($$, &($1)) ;
    }
  | FExpr_Multi
    {
      $$ = $1 ;
    }
  | RecursiveListOfDouble ',' FExpr
    {
      List_Add($$, &($3)) ;
    }
  | RecursiveListOfDouble ',' FExpr_Multi
    {
      for(i=0 ; i<List_Nbr($3) ; i++){
	List_Read($3, i, &d) ;
	List_Add($$, &d) ;
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
      $$ = Get_ColorForString(ColorString, (int)$4, $2, &flag);
      if(flag) vyyerror("Unknown color '%s'", $2);
    }
*/
  | tSTRING
    {
      $$ = Get_ColorForString(ColorString, -1, $1, &flag);
      if(flag) vyyerror("Unknown color '%s'", $1);
    }
  | tSTRING '.' tColor '.' tSTRING 
    {
      if(!(pColCat = Get_ColorOptionCategory($1))){
	vyyerror("Unknown color option class '%s'", $1);
	$$ = 0 ;
      }
      else{
	if(!(pColOpt =  (unsigned int (*) (int, int, unsigned int))Get_ColorOption($5, pColCat))){
	  vyyerror("Unknown color option '%s.Color.%s'", $1, $5);
	  $$ = 0 ;
	}
	else{
	  $$ = pColOpt(0,GMSH_GET,0) ;
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
      $$ = List_Create(256,10,sizeof(unsigned int)) ;
      GmshColorTable *ct = Get_ColorTable((int)$3);
      if(!ct)
	vyyerror("View[%d] does not exist", (int)$3);
      else{
	for(i=0 ; i<ct->size ; i++) 
	  List_Add($$, &ct->table[i]);
      }
    }
;

RecursiveListOfColor :
    ColorExpr
    {
      $$ = List_Create(256,10,sizeof(unsigned int)) ;
      List_Add($$, &($1)) ;
    }
  | RecursiveListOfColor ',' ColorExpr
    {
      List_Add($$, &($3)) ;
    }
;

StringExpr :
    tBIGSTR
    {
      $$ = $1;
    }
  | tStrCat '(' StringExpr ',' StringExpr ')'
    {
      $$ = (char *)Malloc((strlen($3)+strlen($5)+1)*sizeof(char)) ;
      strcpy($$, $3) ;  
      strcat($$, $5) ;
      Free($3);
      Free($5);
    }
  | tStrPrefix '(' StringExpr ')'
    {
      $$ = (char *)Malloc((strlen($3)+1)*sizeof(char)) ;
      for(i=strlen($3)-1; i>=0; i--){
	if($3[i] == '.'){
	  strncpy($$,$3,i);
	  $$[i]='\0';
	  break;
	}
      }
      if(i<=0) strcpy($$,$3);
      Free($3);
    }
  | tSprintf '(' StringExpr ')'
    {
      $$ = $3;
    }
  | tSprintf '(' StringExpr ',' RecursiveListOfDouble ')'
    {
      i = PrintListOfDouble($3,$5,tmpstring);
      if(i<0){
	vyyerror("Too few arguments in Sprintf");
	$$ = $3;
      }
      else if(i>0){
	vyyerror("Too many arguments (%d) in Sprintf", i);
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
      if(!(pStrCat = Get_StringOptionCategory($3)))
	vyyerror("Unknown string option class '%s'", $3);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($5, pStrCat)))
	  vyyerror("Unknown string option '%s.%s'", $3, $5);
	else{
	  str = pStrOpt(0,GMSH_GET,NULL) ;
	  $$ = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy($$, str);
	}
      }
    }
  | tSprintf '('  tSTRING '[' FExpr ']' '.' tSTRING   ')'
    { 
      if(!(pStrCat = Get_StringOptionCategory($3)))
	vyyerror("Unknown string option class '%s'", $3);
      else{
	if(!(pStrOpt = (char *(*) (int, int, char *))Get_StringOption($8, pStrCat)))
	  vyyerror("Unknown string option '%s[%d].%s'", $3, (int)$5, $8);
	else{
	  str = pStrOpt((int)$5,GMSH_GET,NULL) ;
	  $$ = (char*)Malloc((strlen(str)+1)*sizeof(char));
	  strcpy($$, str);
	}
      }
    }
;

%%

void InitSymbols(void){
  if(!Symbol_L)
    Symbol_L = List_Create(50,10,sizeof(Symbol));
  else
    List_Reset(Symbol_L);
}

void DeleteSymbols(void){
  int i;
  for(i = 0 ; i < List_Nbr(Symbol_L) ; i++)
    List_Delete(((Symbol*)List_Pointer_Fast(Symbol_L,i))->val);
  List_Delete(Symbol_L);
}

int CompareSymbols (const void *a, const void *b){
  return(strcmp(((Symbol*)a)->Name,((Symbol*)b)->Name));
}

int PrintListOfDouble(char *format, List_T *list, char *buffer){
  int i, j, k;
  char tmp1[256], tmp2[256];

  j=0;
  while(format[j]!='%') j++;
  strncpy(buffer, format, j); 
  buffer[j]='\0'; 
  for(i = 0 ; i<List_Nbr(list) ; i++){
    k = j;
    j++;
    if(j<(int)strlen(format)){
      if(format[j]=='%'){
	strcat(buffer, "%");
	j++;
      }
      while(format[j]!='%' && j<(int)strlen(format)) j++;
      if(k != j){
	strncpy(tmp1, &(format[k]),j-k);
	tmp1[j-k]='\0';
	sprintf(tmp2, tmp1, *(double*)List_Pointer(list,i)); 
	strcat(buffer, tmp2);
      }
    }
    else{
      return List_Nbr(list)-i;
      break ;
    }
  }
  if(j != (int)strlen(format))
    return -1;
  return 0;
}
  
void yyerror(char *s){
  Msg(PARSER_ERROR, "'%s', line %d : %s (%s)",yyname,yylineno-1,s,yytext);
  yyerrorstate=1;
}

void vyyerror(char *fmt, ...){
  va_list args;
  char tmp[1024];

  va_start (args, fmt);
  vsprintf (tmp, fmt, args);
  va_end (args);

  Msg(PARSER_ERROR, "'%s', line %d : %s", yyname, yylineno-1, tmp);
  yyerrorstate=1;
}


