%{ /* $Id: Gmsh.y,v 1.40 2000-12-11 16:23:15 geuzaine Exp $ */

#include <stdarg.h>

#include "Gmsh.h"
#include "Const.h"
#include "Context.h"
#include "Geo.h"
#include "CAD.h"
#include "DataBase.h"
#include "Mesh.h"
#include "Create.h"
#include "Views.h"
#include "StepGeomDatabase.h"
#include "Options.h"
#include "Colors.h"
#include "Parser.h"
#include "Main.h"
#include "FunctionManager.h"
#include "ColorTable.h"

#ifdef __DECCXX // bug in bison
#include <alloca.h>
#endif

int     Force_ViewNumber = 0 ;
List_T *Symbol_L;

extern Mesh      *THEM;
extern Post_View *ActualView;
extern char       ThePathForIncludes[NAME_STR_L];

static FILE          *yyinTab[MAX_OPEN_FILES];
static int            yylinenoTab[MAX_OPEN_FILES];
static fpos_t         yyposImbricatedLoopsTab[MAX_OPEN_FILES];
static double         LoopControlVariablesTab[MAX_OPEN_FILES][3];
static char*          LoopControlVariablesNameTab[MAX_OPEN_FILES];
static char           yynameTab[MAX_OPEN_FILES][NAME_STR_L];
static char           tmpstring[NAME_STR_L];
static Symbol         TheSymbol, *pSymbol;
static Surface       *STL_Surf;
static Shape          TheShape;
static int            i,j,k,flag,RecursionLevel=0,ImbricatedLoop = 0;
static int            Last_NumberOfPoints = 0;
static double         d, *pd;
static ExtrudeParams  extr;
static List_T         *ListOfDouble_L,*ListOfDouble2_L;
static List_T         *ListOfListOfDouble_L, *ListOfColor_L=NULL;

static void           *pNumOpt, *pArrOpt;
static char          **pStrOpt, *pStrViewOpt;
static unsigned int   *pColOpt;
static StringXString  *pStrCat;
static StringXNumber  *pNumCat;
static StringXArray   *pArrCat;
static StringXColor   *pColCat;

void yyerror (char *s);
void vyyerror (char *fmt, ...);
void skip_until (char *until);

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

%token tEND tAFFECT tDOTS tPi
%token tExp tLog tLog10 tSqrt tSin tAsin tCos tAcos tTan tRand
%token tAtan tAtan2 tSinh tCosh tTanh tFabs tFloor tCeil
%token tFmod tModulo tHypot tPrintf tSprintf tDraw
%token tPoint tCircle tEllipsis tLine tSurface tSpline tVolume
%token tCharacteristic tLength tParametric tElliptic
%token tPlane tRuled tTransfinite tComplex tPhysical
%token tUsing tBump tProgression
%token tRotate tTranslate tSymmetry tDilate tExtrude tDuplicata
%token tLoop tRecombine tDelete tCoherence
%token tView tAttractor tLayers
%token tScalarTetrahedron tVectorTetrahedron tTensorTetrahedron
%token tScalarTriangle tVectorTriangle tTensorTriangle
%token tScalarLine tVectorLine tTensorLine
%token tScalarPoint tVectorPoint tTensorPoint
%token tBSpline tNurbs tOrder tWith tBounds tKnots
%token tColor tFor tIn tEndFor tIf tEndIf tExit tMerge
%token tReturn tCall tFunction

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

%type <d> FExpr FExpr_Single
%type <v> VExpr VExpr_Single
%type <i> BoolExpr
%type <u> ColorExpr
%type <c> StringExpr
%type <l> ListOfShapes Duplicata Transform MultipleShape
%type <l> ListOfStrings ListOfDouble ListOfListOfDouble ListOfColor
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
;

/*  ----------------------------------------------------------------------
    S T E R E O L I T H O G R A P H Y  ( S T L )
    ---------------------------------------------------------------------- */

STLFormatItem : 
    tSolid
    {
      Msg(PARSER_INFO,"STL File Format");
      STL_Surf = Create_Surface(1,MSH_SURF_STL,1);
      STL_Surf->STL = new STL_Data;
      return 1;
    }
  | tFacet
    tNormal FExpr FExpr FExpr
    tOuter tLoopSTL
      tVertex FExpr FExpr FExpr
      tVertex FExpr FExpr FExpr
      tVertex FExpr FExpr FExpr
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
      Msg(PARSER_INFO,"STL File Format Read");
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
  | error tEND { yyerrok ; return 1; }
;

StepSpecial :
    tISO tEND
    {
      Msg(PARSER_INFO,"Step Iso-10303-21 File Format");
      Create_Step_Solid_BRep();
    }
  | tENDISO tEND
    {
      Msg(PARSER_INFO,"Step Iso-10303-21 File Format Read");
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
      Msg(PARSER_INFO,"Found a Face Bound");
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
      Msg(PARSER_INFO,"Found a Closed shell");
      Add_Closed_Shell((int)$1, $5 , $7);
    }
  | tDOUBLE tAFFECT tADVANCED_BREP_SHAPE_REPRESENTATION
     '(' tBIGSTR ',' ListOfDouble ',' tDOUBLE')' tEND
    {
    }
  | tDOUBLE tAFFECT tMANIFOLD_SOLID_BREP '(' tBIGSTR ',' tDOUBLE ')' tEND
    {
    }
  | tDOUBLE tAFFECT tCYLINDRICAL_SURFACE '(' tBIGSTR ',' tDOUBLE ','FExpr ')' tEND
    {
      Add_Cylinder ((int)$1, $5 , (int)$7, $9);
    }
  | tDOUBLE tAFFECT tCONICAL_SURFACE '(' tBIGSTR ',' tDOUBLE ','FExpr ','FExpr ')' tEND
    {
      Add_Cone ((int)$1, $5 , (int)$7, $9,$11);
    }
  | tDOUBLE tAFFECT tTOROIDAL_SURFACE '(' tBIGSTR ',' tDOUBLE ','FExpr ','FExpr ')' tEND
    {
      Add_Torus ((int)$1, $5 , (int)$7, $9,$11);
    }
  | tDOUBLE tAFFECT tCIRCLE '(' tBIGSTR ',' tDOUBLE ','FExpr ')' tEND
    {
      Add_Circle((int) $1, $5, (int) $7, $9);
    }
  | tDOUBLE tAFFECT tELLIPSE '(' tBIGSTR ',' tDOUBLE ','FExpr ',' FExpr ')' tEND
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
      Msg(PARSER_INFO,"Gmsh File Format Read");
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
  | Loop        {return 1;}
/*  | Script      { return 1; }*/
  | Command     { return 1; }
  | error tEND  { yyerrok; return 1;}
;

Printf :
    tPrintf '(' tBIGSTR ')' tEND
    {
      Msg(PARSER_INFO, $3); 
    }
  | tPrintf '(' tBIGSTR ',' FExpr ')' tEND
    {
      Msg(PARSER_INFO, $3, $5); 
    }
;

/* ------------
   V I E W 
   ------------ */

View :
    tView tBIGSTR '{' Views '}' tEND
    { 
      EndView(1, Force_ViewNumber,yyname,$2,0.,0.,0.); 
    }
  | tView tBIGSTR tSTRING VExpr '{' Views '}' tEND
    {
      EndView(1, Force_ViewNumber,yyname,$2,$4[0],$4[1],$4[2]);
    }  
;

Views :
    /* none */
    {
      BeginView(1); 
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
;

ScalarPointValues :
    FExpr
    { List_Add(ActualView->SP, &$1) ; }
  | ScalarPointValues ',' FExpr
    { List_Add(ActualView->SP, &$3) ; }
  ;

ScalarPoint : 
    tScalarPoint '(' FExpr ',' FExpr ',' FExpr ')'
    { 
      List_Add(ActualView->SP, &$3); List_Add(ActualView->SP, &$5);
      List_Add(ActualView->SP, &$7);
    }
    '{' ScalarPointValues '}' tEND
    {
      ActualView->NbSP++ ;
    }
;

VectorPointValues :
    FExpr
    { List_Add(ActualView->VP, &$1) ; }
  | VectorPointValues ',' FExpr
    { List_Add(ActualView->VP, &$3) ; }
  ;

VectorPoint : 
    tVectorPoint '(' FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->VP, &$3); List_Add(ActualView->VP, &$5);
      List_Add(ActualView->VP, &$7); 
    }
    '{' VectorPointValues '}' tEND
    {
      ActualView->NbVP++ ;
    }
;

TensorPointValues :
    FExpr
    { List_Add(ActualView->TP, &$1) ; }
  | TensorPointValues ',' FExpr
    { List_Add(ActualView->TP, &$3) ; }
  ;

TensorPoint :
    tTensorPoint '(' FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->TP, &$3); List_Add(ActualView->TP, &$5);
      List_Add(ActualView->TP, &$7);
    }
    '{' TensorPointValues '}' tEND
    {
      ActualView->NbTP++ ;
    }
;

ScalarLineValues :
    FExpr
    { List_Add(ActualView->SL, &$1) ; }
  | ScalarLineValues ',' FExpr
    { List_Add(ActualView->SL, &$3) ; }
  ;

ScalarLine : 
    tScalarLine '(' FExpr ',' FExpr ',' FExpr ',' 
                    FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->SL, &$3); List_Add(ActualView->SL, &$9);
      List_Add(ActualView->SL, &$5); List_Add(ActualView->SL, &$11);
      List_Add(ActualView->SL, &$7); List_Add(ActualView->SL, &$13);
    }
    '{' ScalarLineValues '}' tEND
    {
      ActualView->NbSL++ ;
    }
;

VectorLineValues :
    FExpr
    { List_Add(ActualView->VL, &$1) ; }
  | VectorLineValues ',' FExpr
    { List_Add(ActualView->VL, &$3) ; }
  ;

VectorLine : 
    tVectorLine '(' FExpr ',' FExpr ',' FExpr ',' 
                    FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->SL, &$3); List_Add(ActualView->SL, &$9);
      List_Add(ActualView->SL, &$5); List_Add(ActualView->SL, &$11);
      List_Add(ActualView->SL, &$7); List_Add(ActualView->SL, &$13);
    }
    '{' VectorLineValues '}' tEND
    {
      ActualView->NbVL++ ;
    }
;

TensorLineValues :
    FExpr
    { List_Add(ActualView->TL, &$1) ; }
  | TensorLineValues ',' FExpr
    { List_Add(ActualView->TL, &$3) ; }
  ;

TensorLine :
    tTensorLine '(' FExpr ',' FExpr ',' FExpr ',' 
                    FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->SL, &$3); List_Add(ActualView->SL, &$9);
      List_Add(ActualView->SL, &$5); List_Add(ActualView->SL, &$11);
      List_Add(ActualView->SL, &$7); List_Add(ActualView->SL, &$13);
    }
    '{' TensorLineValues '}' tEND
    {
      ActualView->NbTL++ ;
    }
;

ScalarTriangleValues :
    FExpr
    { List_Add(ActualView->ST, &$1) ; }
  | ScalarTriangleValues ',' FExpr
    { List_Add(ActualView->ST, &$3) ; }
  ;

ScalarTriangle : 
    tScalarTriangle '(' FExpr ',' FExpr ',' FExpr ',' 
                        FExpr ',' FExpr ',' FExpr ','
                        FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->ST, &$3); List_Add(ActualView->ST, &$9);
      List_Add(ActualView->ST, &$15);
      List_Add(ActualView->ST, &$5); List_Add(ActualView->ST, &$11);
      List_Add(ActualView->ST, &$17);
      List_Add(ActualView->ST, &$7); List_Add(ActualView->ST, &$13);
      List_Add(ActualView->ST, &$19);
    }
    '{' ScalarTriangleValues '}' tEND
    {
      ActualView->NbST++ ;
    }
;

VectorTriangleValues :
    FExpr
    { List_Add(ActualView->VT, &$1) ; }
  | VectorTriangleValues ',' FExpr
    { List_Add(ActualView->VT, &$3) ; }
  ;

VectorTriangle : 
    tVectorTriangle '(' FExpr ',' FExpr ',' FExpr ',' 
                        FExpr ',' FExpr ',' FExpr ','
                        FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->VT, &$3); List_Add(ActualView->VT, &$9);
      List_Add(ActualView->VT, &$15);
      List_Add(ActualView->VT, &$5); List_Add(ActualView->VT, &$11);
      List_Add(ActualView->VT, &$17);
      List_Add(ActualView->VT, &$7); List_Add(ActualView->VT, &$13);
      List_Add(ActualView->VT, &$19);
    }
    '{' VectorTriangleValues '}' tEND
    {
      ActualView->NbVT++ ;
    }
;

TensorTriangleValues :
    FExpr
    { List_Add(ActualView->TT, &$1) ; }
  | TensorTriangleValues ',' FExpr
    { List_Add(ActualView->TT, &$3) ; }
  ;

TensorTriangle :
    tTensorTriangle '(' FExpr ',' FExpr ',' FExpr ',' 
                        FExpr ',' FExpr ',' FExpr ','
                        FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->TT, &$3); List_Add(ActualView->TT, &$9);
      List_Add(ActualView->TT, &$15);
      List_Add(ActualView->TT, &$5); List_Add(ActualView->TT, &$11);
      List_Add(ActualView->TT, &$17);
      List_Add(ActualView->TT, &$7); List_Add(ActualView->TT, &$13);
      List_Add(ActualView->TT, &$19);
    }
    '{' TensorTriangleValues '}' tEND
    {
      ActualView->NbTT++ ;
    }
;

ScalarTetrahedronValues :
    FExpr
    { List_Add(ActualView->SS, &$1) ; }
  | ScalarTetrahedronValues ',' FExpr
    { List_Add(ActualView->SS, &$3) ; }
  ;

ScalarTetrahedron : 
    tScalarTetrahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ','
                           FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->SS, &$3);  List_Add(ActualView->SS, &$9);
      List_Add(ActualView->SS, &$15); List_Add(ActualView->SS, &$21);
      List_Add(ActualView->SS, &$5);  List_Add(ActualView->SS, &$11);
      List_Add(ActualView->SS, &$17); List_Add(ActualView->SS, &$23);
      List_Add(ActualView->SS, &$7);  List_Add(ActualView->SS, &$13);
      List_Add(ActualView->SS, &$19); List_Add(ActualView->SS, &$25);
    }
    '{' ScalarTetrahedronValues '}' tEND
    {
      ActualView->NbSS++ ;
    }
;

VectorTetrahedronValues :
    FExpr
    { List_Add(ActualView->VS, &$1) ; }
  | VectorTetrahedronValues ',' FExpr
    { List_Add(ActualView->VS, &$3) ; }
  ;

VectorTetrahedron : 
    tVectorTetrahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ','
                           FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->VS, &$3);  List_Add(ActualView->VS, &$9);
      List_Add(ActualView->VS, &$15); List_Add(ActualView->VS, &$21);
      List_Add(ActualView->VS, &$5);  List_Add(ActualView->VS, &$11);
      List_Add(ActualView->VS, &$17); List_Add(ActualView->VS, &$23);
      List_Add(ActualView->VS, &$7);  List_Add(ActualView->VS, &$13);
      List_Add(ActualView->VS, &$19); List_Add(ActualView->VS, &$25);
    }
    '{' VectorTetrahedronValues '}' tEND
    {
      ActualView->NbVS++ ;
    }
;

TensorTetrahedronValues :
    FExpr
    { List_Add(ActualView->TS, &$1) ; }
  | TensorTetrahedronValues ',' FExpr
    { List_Add(ActualView->TS, &$3) ; }
  ;

TensorTetrahedron :
    tTensorTetrahedron '(' FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ','
                           FExpr ',' FExpr ',' FExpr ',' 
                           FExpr ',' FExpr ',' FExpr ')' 
    { 
      List_Add(ActualView->TS, &$3);  List_Add(ActualView->TS, &$9);
      List_Add(ActualView->TS, &$15); List_Add(ActualView->TS, &$21);
      List_Add(ActualView->TS, &$5);  List_Add(ActualView->TS, &$11);
      List_Add(ActualView->TS, &$17); List_Add(ActualView->TS, &$23);
      List_Add(ActualView->TS, &$7);  List_Add(ActualView->TS, &$13);
      List_Add(ActualView->TS, &$19); List_Add(ActualView->TS, &$25);
    }
    '{' TensorTetrahedronValues '}' tEND
    {
      ActualView->NbTS++ ;
    }
;



/* -----------------------
    A F F E C T A T I O N
   ----------------------- */

Affectation :

  /* -------- Variables -------- */ 

    tSTRING tAFFECT FExpr tEND
    {
      TheSymbol.Name = $1;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(1,1,sizeof(double));
	List_Put(TheSymbol.val, 0, &$3);
	List_Add(Symbol_L, &TheSymbol);
      }
      else{
	List_Write(pSymbol->val, 0, &$3);
      }
    }
  | tSTRING '[' FExpr ']' tAFFECT FExpr tEND
    {
      TheSymbol.Name = $1;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))){
	TheSymbol.val = List_Create(5,5,sizeof(double));
	List_Put(TheSymbol.val, (int)$3, &$6);
	List_Add(Symbol_L, &TheSymbol);
      }
      else{
	List_Put(pSymbol->val, (int)$3, &$6);
      }
    }
  | tSTRING tPLUSPLUS tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else{
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += 1.0 ;
      }
    }
  | tSTRING '[' FExpr ']' tPLUSPLUS tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  *pd += 1.0 ;
	else
	  vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
      }
    }
  | tSTRING tMINUSMINUS tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) -= 1. ;
    }
  | tSTRING '[' FExpr ']' tMINUSMINUS tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  *pd -= 1.0 ;
	else
	  vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
      }
    }
  | tSTRING tAFFECTPLUS FExpr tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) += $3 ;
    }
  | tSTRING '[' FExpr ']' tAFFECTPLUS FExpr tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  *pd += $6 ;
	else
	  vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
      }
    }
  | tSTRING tAFFECTMINUS FExpr tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) -= $3 ;
    }
  | tSTRING '[' FExpr ']' tAFFECTMINUS FExpr tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  *pd -= $6 ;
	else
	  vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
      }
    }
  | tSTRING tAFFECTTIMES FExpr tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else
	*(double*)List_Pointer_Fast(pSymbol->val, 0) *= $3 ;
    }
  | tSTRING '[' FExpr ']' tAFFECTTIMES FExpr tEND
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	vyyerror("Unknown Variable '%s'", $1) ;
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  *pd *= $6 ;
	else
	  vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
      }
    }
  | tSTRING tAFFECTDIVIDE FExpr tEND
    {
      if(!$3)
	vyyerror("Division by Zero in '%s /= %g'", $1, $3);
      else{
	TheSymbol.Name = $1 ;
	if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	  vyyerror("Unknown Variable '%s'", $1) ;
	else
	  *(double*)List_Pointer_Fast(pSymbol->val, 0) /= $3 ;
      }
    }
  | tSTRING '[' FExpr ']' tAFFECTDIVIDE FExpr tEND
    {
      if(!$6)
	vyyerror("Division by Zero in '%s[%d] /= %g'", $1, (int)$3, $6);
      else{
	TheSymbol.Name = $1 ;
	if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols)))
	  vyyerror("Unknown Variable '%s'", $1) ;
	else{
	  if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	    *pd /= $6 ;
	  else
	    vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
	}
      }
    }

  /* -------- Option Strings -------- */ 

  | tSTRING '.' tSTRING tAFFECT tBIGSTR tEND 
    { 
      if(!(pStrCat = Get_StringOptionCategory($1)))
	vyyerror("Unknown String Option Class '%s'", $1);
      else{
	if(!(pStrOpt = Get_StringOption($3, pStrCat)))
	  vyyerror("Unknown String Option '%s.%s'", $1, $3);
	else{
	  *pStrOpt = $5 ;
	}
      }
    }

  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECT tBIGSTR tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pStrViewOpt = Get_StringViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown String Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  strcpy(pStrViewOpt, $10) ;
	}
      }
    }

  /* -------- Option Numbers -------- */ 

  | tSTRING '.' tSTRING tAFFECT FExpr tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown Numeric Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i)))
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt = $5 ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt = (float)$5 ; break ;
	  case GMSH_LONG : *(long*)pNumOpt = (long)$5 ; break ;
	  case GMSH_INT : *(int*)pNumOpt = (int)$5 ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECT FExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt = $10 ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt = (float)$10 ; break ;
	  case GMSH_LONG : *(long*)pNumOpt = (long)$10 ; break ;
	  case GMSH_INT : *(int*)pNumOpt = (int)$10 ; break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tAFFECTPLUS FExpr tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown Numeric Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i)))
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt += $5 ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt += (float)$5 ; break ;
	  case GMSH_LONG : *(long*)pNumOpt += (long)$5 ; break ;
	  case GMSH_INT : *(int*)pNumOpt += (int)$5 ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECTPLUS FExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt += $10 ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt += (float)$10 ; break ;
	  case GMSH_LONG : *(long*)pNumOpt += (long)$10 ; break ;
	  case GMSH_INT : *(int*)pNumOpt += (int)$10 ; break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tAFFECTMINUS FExpr tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown Numeric Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i)))
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt -= $5 ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt -= (float)$5 ; break ;
	  case GMSH_LONG : *(long*)pNumOpt -= (long)$5 ; break ;
	  case GMSH_INT : *(int*)pNumOpt -= (int)$5 ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECTMINUS FExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt -= $10 ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt -= (float)$10 ; break ;
	  case GMSH_LONG : *(long*)pNumOpt -= (long)$10 ; break ;
	  case GMSH_INT : *(int*)pNumOpt -= (int)$10 ; break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tAFFECTTIMES FExpr tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown Numeric Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i)))
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt *= $5 ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt *= (float)$5 ; break ;
	  case GMSH_LONG : *(long*)pNumOpt *= (long)$5 ; break ;
	  case GMSH_INT : *(int*)pNumOpt *= (int)$5 ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECTTIMES FExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt *= $10 ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt *= (float)$10 ; break ;
	  case GMSH_LONG : *(long*)pNumOpt *= (long)$10 ; break ;
	  case GMSH_INT : *(int*)pNumOpt *= (int)$10 ; break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tAFFECTDIVIDE FExpr tEND 
    {
      if(!$5)
	vyyerror("Division by Zero in '%s.%s /= %g'", $1, $3, $5);
      else{
	if(!(pNumCat = Get_NumberOptionCategory($1)))
	  vyyerror("Unknown Numeric Option Class '%s'", $1);
	else{
	  if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i)))
	    vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	  else{
	    switch(i){
	    case GMSH_DOUBLE : *(double*)pNumOpt /= $5 ; break ;
	    case GMSH_FLOAT : *(float*)pNumOpt /= (float)$5 ; break ;
	    case GMSH_LONG : *(long*)pNumOpt /= (long)$5 ; break ;
	    case GMSH_INT : *(int*)pNumOpt /= (int)$5 ; break ;
	    }
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECTDIVIDE FExpr tEND 
    {
      if(!$10)
	vyyerror("Division by Zero in '%s.View[%d].%s /= %g'", 
		 $1, (int)$5, $8, $10);
      else{
	if(strcmp($1, "PostProcessing"))
	  vyyerror("Unknown View Option Class '%s'", $1);
	else{
	  if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	    if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	    else      vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			       $1, (int)$5, $8);
	  }
	  else{
	    switch(i){
	    case GMSH_DOUBLE : *(double*)pNumOpt /= $10 ; break ;
	    case GMSH_FLOAT : *(float*)pNumOpt /= (float)$10 ; break ;
	    case GMSH_LONG : *(long*)pNumOpt /= (long)$10 ; break ;
	    case GMSH_INT : *(int*)pNumOpt /= (int)$10 ; break ;
	    }
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tPLUSPLUS tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown Numeric Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i)))
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt += 1. ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt += 1. ; break ;
	  case GMSH_LONG : *(long*)pNumOpt += 1 ; break ;
	  case GMSH_INT : *(int*)pNumOpt += 1 ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tPLUSPLUS FExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt += 1. ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt += 1. ; break ;
	  case GMSH_LONG : *(long*)pNumOpt += 1 ; break ;
	  case GMSH_INT : *(int*)pNumOpt += 1 ; break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tMINUSMINUS tEND 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1)))
	vyyerror("Unknown Numeric Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i)))
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt -= 1. ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt -= 1. ; break ;
	  case GMSH_LONG : *(long*)pNumOpt -= 1 ; break ;
	  case GMSH_INT : *(int*)pNumOpt -= 1 ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tMINUSMINUS FExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : *(double*)pNumOpt -= 1. ; break ;
	  case GMSH_FLOAT : *(float*)pNumOpt -= 1. ; break ;
	  case GMSH_LONG : *(long*)pNumOpt -= 1 ; break ;
	  case GMSH_INT : *(int*)pNumOpt -= 1 ; break ;
	  }
	}
      }
    }

  /* -------- Option Arrays -------- */ 

  | tSTRING '.' tSTRING tAFFECT VExpr tEND 
    {
      if(!(pArrCat = Get_ArrayOptionCategory($1)))
	vyyerror("Unknown Array Option Class '%s'", $1);
      else{
	if(!(pArrOpt = Get_ArrayOption($3, pArrCat, &i)))
	  vyyerror("Unknown Array Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE :
	    for(j=0 ; j<4; j++) ((double*)pArrOpt)[j] = $5[j] ;
	    break ;
	  case GMSH_FLOAT :
	    for(j=0 ; j<4; j++) ((float*)pArrOpt)[j] = (float)$5[j] ;
	    break ;
	  case GMSH_LONG :
	    for(j=0 ; j<4; j++) ((long*)pArrOpt)[j] = (long)$5[j] ;
	    break ;
	  case GMSH_INT :
	    for(j=0 ; j<4; j++) ((int*)pArrOpt)[j] = (int)$5[j] ;
	    break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECT VExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pArrOpt = Get_ArrayViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Array Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE :
	    for(j=0 ; j<3; j++) ((double*)pArrOpt)[j] = $10[j] ;
	    break ;
	  case GMSH_FLOAT :
	    for(j=0 ; j<3; j++) ((float*)pArrOpt)[j] = (float)$10[j] ;
	    break ;
	  case GMSH_LONG :
	    for(j=0 ; j<3; j++) ((long*)pArrOpt)[j] = (long)$10[j] ;
	    break ;
	  case GMSH_INT :
	    for(j=0 ; j<3; j++) ((int*)pArrOpt)[j] = (int)$10[j] ;
	    break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tAFFECTPLUS VExpr tEND 
    {
      if(!(pArrCat = Get_ArrayOptionCategory($1)))
	vyyerror("Unknown Array Option Class '%s'", $1);
      else{
	if(!(pArrOpt = Get_ArrayOption($3, pArrCat, &i)))
	  vyyerror("Unknown Array Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE :
	    for(j=0 ; j<4; j++) ((double*)pArrOpt)[j] += $5[j] ;
	    break ;
	  case GMSH_FLOAT :
	    for(j=0 ; j<4; j++) ((float*)pArrOpt)[j] += (float)$5[j] ;
	    break ;
	  case GMSH_LONG :
	    for(j=0 ; j<4; j++) ((long*)pArrOpt)[j] += (long)$5[j] ;
	    break ;
	  case GMSH_INT :
	    for(j=0 ; j<4; j++) ((int*)pArrOpt)[j] += (int)$5[j] ;
	    break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECTPLUS VExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pArrOpt = Get_ArrayViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Array Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE :
	    for(j=0 ; j<3; j++) ((double*)pArrOpt)[j] += $10[j] ;
	    break ;
	  case GMSH_FLOAT :
	    for(j=0 ; j<3; j++) ((float*)pArrOpt)[j] += (float)$10[j] ;
	    break ;
	  case GMSH_LONG :
	    for(j=0 ; j<3; j++) ((long*)pArrOpt)[j] += (long)$10[j] ;
	    break ;
	  case GMSH_INT :
	    for(j=0 ; j<3; j++) ((int*)pArrOpt)[j] += (int)$10[j] ;
	    break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tAFFECTMINUS VExpr tEND 
    {
      if(!(pArrCat = Get_ArrayOptionCategory($1)))
	vyyerror("Unknown Array Option Class '%s'", $1);
      else{
	if(!(pArrOpt = Get_ArrayOption($3, pArrCat, &i)))
	  vyyerror("Unknown Array Option '%s.%s'", $1, $3);
	else{
	  switch(i){
	  case GMSH_DOUBLE :
	    for(j=0 ; j<4; j++) ((double*)pArrOpt)[j] -= $5[j] ;
	    break ;
	  case GMSH_FLOAT :
	    for(j=0 ; j<4; j++) ((float*)pArrOpt)[j] -= (float)$5[j] ;
	    break ;
	  case GMSH_LONG :
	    for(j=0 ; j<4; j++) ((long*)pArrOpt)[j] -= (long)$5[j] ;
	    break ;
	  case GMSH_INT :
	    for(j=0 ; j<4; j++) ((int*)pArrOpt)[j] -= (int)$5[j] ;
	    break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tAFFECTMINUS VExpr tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	if(!(pArrOpt = Get_ArrayViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Array Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE :
	    for(j=0 ; j<3; j++) ((double*)pArrOpt)[j] -= $10[j] ;
	    break ;
	  case GMSH_FLOAT :
	    for(j=0 ; j<3; j++) ((float*)pArrOpt)[j] -= (float)$10[j] ;
	    break ;
	  case GMSH_LONG :
	    for(j=0 ; j<3; j++) ((long*)pArrOpt)[j] -= (long)$10[j] ;
	    break ;
	  case GMSH_INT :
	    for(j=0 ; j<3; j++) ((int*)pArrOpt)[j] -= (int)$10[j] ;
	    break ;
	  }
	}
      }
    }

  /* -------- Option Colors -------- */ 

  | tSTRING '.' tColor '.' tSTRING tAFFECT ColorExpr tEND 
    {
      if(!(pColCat = Get_ColorOptionCategory($1)))
	vyyerror("Unknown Color Option Class '%s'", $1);
      else{
	if(!(pColOpt = Get_ColorOption($5, pColCat)))
	  vyyerror("Unknown Color Option '%s.%s'", $1, $5);
	else{
	  *pColOpt = $7 ;
	}
      }
    }

  | tSTRING '.' tView '[' FExpr ']' '.' tColor tAFFECT ListOfColor tEND 
    {
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	ColorTable *ct = Get_ColorTableViewOption((int)$5);
	if(!ct)
	  vyyerror("PostProcessing View %d does not Exist", (int)$5);
	else{
	  ct->size = List_Nbr($10);
	  if(ct->size > COLORTABLE_NBMAX_COLOR)
	    vyyerror("Too Many (%d>%d) Colors in Post.View[%d].Color", 
		     ct->size, COLORTABLE_NBMAX_COLOR, (int)$5);
	  else
	    for(i=0 ; i<ct->size ; i++) List_Read($10, i, &ct->table[i]);
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
        v = FindVertex(ip,THEM);
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
	Vertex *v = FindVertex((int)d,THEM);
	if(!v)
	  vyyerror("Unkown Point %d", (int)d);
	else
	  v->lc = $5;
      }
    }  
  | tPoint '{' FExpr '}' tEND
    {
      $$.Type = MSH_POINT;
      $$.Num  = (int)$3;
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
  | tEllipsis '(' FExpr ')'  tAFFECT ListOfDouble tEND
    {
      Cdbseg101((int)$3,MSH_SEGM_ELLI,2,$6,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      $$.Type = MSH_SEGM_ELLI ;
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
      Cdbseg101((int)$3,MSH_SEGM_BSPLN,2,$6,NULL,-1,-1,0.,1.,NULL,NULL,NULL);
      $$.Type = MSH_SEGM_BSPLN;
      $$.Num  = (int)$3;
    }
  | tNurbs  '(' FExpr ')' tAFFECT ListOfDouble tKnots ListOfDouble tOrder FExpr tEND
    {
      List_T *Temp;
      int i;
      double d;
      if((int)$10 + 1 + List_Nbr($6) != List_Nbr($8)){
	vyyerror("Wrong Definition of Nurbs Curve %d: "
		"[Degree]%d + 1 + [NbPts]%d != [NbKnots]%d",
		(int)$3, (int)$10, List_Nbr($6), List_Nbr($8));
      }
      Temp = List_Create(List_Nbr($6),1,sizeof(int));
      for(i=0;i<List_Nbr($6);i++) {
      	List_Read($6,i,&d);
        j = (int)d;
        List_Add(Temp,&j);
      }
      AddCurveInDataBase ((int)$3,MSH_SEGM_NURBS,(int)$10,Temp,$8,-1,-1,0.,1.);
      List_Delete(Temp);
    }
  | tLine '{' FExpr '}' tEND
    {
      $$.Num = (int)$3;
      Curve *c = FindCurve($$.Num,THEM);
      if(!c)
	vyyerror("Unkown Curve %d", $$.Num);
      else
	$$.Type = c->Typ;
    }

  /* -------- Surfaces -------- */ 

  | tPlane tSurface '(' FExpr ')' tAFFECT ListOfDouble tEND
    {
      Cdbz101((int)$4,MSH_SURF_PLAN,0,0,0,0,0,NULL,$7,NULL);
      $$.Type = MSH_SURF_PLAN;
      $$.Num  = (int)$4;
    }
  | tTrimmed tSurface '(' FExpr ')' tAFFECT FExpr ListOfDouble tEND
    {
      Surface *s,*support;
      support = FindSurface((int)$7,THEM);
      if(!support)
	vyyerror("Unkown Surface %d", (int)$7);
      else{
	Cdbz101((int)$4,MSH_SURF_PLAN,0,0,0,0,0,NULL,$8,NULL);
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
	vyyerror("Unkown Loop %d", i);
      else{
	j = List_Nbr(el->Curves);
	if(j==4)
	  $$.Type = MSH_SURF_REGL;
	else if(j==3)
	  $$.Type  = MSH_SURF_TRIC;
	else
	  vyyerror("Wrong Definition of Ruled Surface %d: "
		   "%d Borders Instead of 3 or 4", 
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
  | tSurface '{' FExpr '}' tEND
    {
      $$.Num = (int)$3;
      Surface *s = FindSurface($$.Num,THEM);
      if(!s)
	vyyerror("Unknown Surface %d", $$.Num);
      else
	$$.Type = s->Typ;
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
  | tDilate '{' VExpr ',' FExpr '}'  '{' MultipleShape '}'
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
;


/* -----------------
    C O M M A N D  
   ----------------- */

Command :
    tSTRING StringExpr tEND
    {
      if(!strcmp($1, "Include")){

	yyinTab[RecursionLevel++] = yyin;
	strcpy(tmpstring, ThePathForIncludes);
	if((yyin = fopen(strcat(tmpstring,$2),"r"))){
	  strcpy(yynameTab[RecursionLevel-1],yyname);
	  yylinenoTab[RecursionLevel-1]=yylineno;
	  yylineno=1;
	  strcpy(yyname,$2);
	  while(!feof(yyin)){
	    yyparse();
	  }
	  fclose(yyin);
	  yyin = yyinTab[--RecursionLevel];
	  strcpy(yyname,yynameTab[RecursionLevel]);
	  yylineno = yylinenoTab[RecursionLevel];
	}
	else{
	  vyyerror("Unknown File '%s'", $2) ;  
	  yyin = yyinTab[--RecursionLevel];
	}

      }
      else if(!strcmp($1, "Print")){

	if(!CTX.interactive){ // we're in interactive mode
	  char ext[6];
	  strcpy(ext,$2+(strlen($2)-4));
	  Replot();
	  extern void CreateImage (char *name, FILE *fp);
	  FILE *fp = 0;
	  if(!strcmp(ext,".gif")){
	    fp = fopen($2,"wb");
	    CTX.print.type = PRINT_GL2GIF;
	  }
	  else if(!strcmp(ext,".eps")){
	    fp = fopen($2,"w");
	    CTX.print.type =  PRINT_GL2PS_RECURSIVE;
	  } 
	  else if(!strcmp(ext,".xpm")){
	    fp = fopen($2,"wb");
	    CTX.print.type =  PRINT_XDUMP;
	    CTX.print.format = FORMAT_XPM;
	  } 
	  if(fp){
	    CreateImage($2,fp);
	    fclose(fp);
	  }
	  else{
	    vyyerror("Unable to Open File '%s'", $2);
	  }
	}
	
      }
      else if(!strcmp($1, "Merge")){

	FILE *ff = yyin;
	MergeProblem($2);
	yyin = ff;

      }
      else if(!strcmp($1, "Save")){

	Print_Mesh(THEM, $2, CTX.mesh.format);

      }
      else
	vyyerror("Unknown Command '%s'", $1);
    } 
  | tSTRING FExpr tEND
    {
      if(!strcmp($1, "Sleep")){

	extern long Get_AnimTime();
	long sleep_time = Get_AnimTime();
	while(1){
	  if(Get_AnimTime() - sleep_time > (long)($2*1.e6)) break;
	}
      
      }
      else if(!strcmp($1, "Mesh")){

	Maillage_Dimension_0(THEM);
	mai3d(THEM,(int)$2);
  
      }
      else
	vyyerror("Unknown Command '%s'", $1);
    }
  | tExit tEND
    {
      exit(0);
    } 
  | tDraw tEND
    {
      if(!CTX.interactive){ // we're in interactive mode
	if(Tree_Nbr(THEM->Points) != Last_NumberOfPoints){
	  Last_NumberOfPoints = Tree_Nbr(THEM->Points);
	  Replot();
	}
	else{
	  Init();
	  Draw();
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
      FILE* ff;
      if(RecursionLevel)
	ff = yyinTab[RecursionLevel-1];
      else
	ff = yyin;
      // here, we seek remember the position in yyin
      LoopControlVariablesTab[ImbricatedLoop][0] = $3 ;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5 ;
      LoopControlVariablesTab[ImbricatedLoop][2] = 1.0 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = "" ;
      fgetpos( ff, &yyposImbricatedLoopsTab[ImbricatedLoop++]);
    }
  | tFor '(' FExpr tDOTS FExpr tDOTS FExpr ')'
    {
      FILE* ff;
      if(RecursionLevel)
	ff = yyinTab[RecursionLevel-1];
      else
	ff = yyin;
      // here, we seek remember the position in yyin
      LoopControlVariablesTab[ImbricatedLoop][0] = $3 ;
      LoopControlVariablesTab[ImbricatedLoop][1] = $5 ;
      LoopControlVariablesTab[ImbricatedLoop][2] = $7 ;
      LoopControlVariablesNameTab[ImbricatedLoop] = "" ;
      fgetpos( ff, &yyposImbricatedLoopsTab[ImbricatedLoop++]);
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr '}' 
    {
      FILE* ff;
      if(RecursionLevel)
	ff = yyinTab[RecursionLevel-1];
      else
	ff = yyin;
      // here, we seek remember the position in yyin
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
      
      fgetpos( ff, &yyposImbricatedLoopsTab[ImbricatedLoop++]);
    }
  | tFor tSTRING tIn '{' FExpr tDOTS FExpr tDOTS FExpr '}' 
    {
      FILE* ff;
      if(RecursionLevel)
	ff = yyinTab[RecursionLevel-1];
      else
	ff = yyin;
      // here, we seek remember the position in yyin
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
      
      fgetpos( ff, &yyposImbricatedLoopsTab[ImbricatedLoop++]);
    }
  | tEndFor 
    {
      if(LoopControlVariablesTab[ImbricatedLoop-1][1] >  
	 LoopControlVariablesTab[ImbricatedLoop-1][0]){
	FILE* ff;
	if(RecursionLevel)
	  ff = yyinTab[RecursionLevel-1];
	else
	  ff = yyin;
	
	LoopControlVariablesTab[ImbricatedLoop-1][0] +=
	  LoopControlVariablesTab[ImbricatedLoop-1][2];
	
	if(strlen(LoopControlVariablesNameTab[ImbricatedLoop-1])){
	  TheSymbol.Name = LoopControlVariablesNameTab[ImbricatedLoop-1];
	  pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols);
	  *(double*)List_Pointer_Fast(pSymbol->val, 0) += 
	    LoopControlVariablesTab[ImbricatedLoop-1][2] ;
	}
	
	fsetpos( yyin, &yyposImbricatedLoopsTab[ImbricatedLoop-1]);
      }
      else{
	ImbricatedLoop--;
      }
    }
  | tReturn
    {
      if(!FunctionManager::Instance()->leaveFunction(&yyin,yylineno))
	vyyerror("Error while exiting function");
    } 
  | tCall tSTRING tEND
    {
      if(!FunctionManager::Instance()->enterFunction($2,&yyin,yylineno))
	vyyerror("Unknown Function %s",$2);
    } 
  | tFunction tSTRING
    {
      // skip everything until return is found
      if(!FunctionManager::Instance()->createFunction($2,yyin,yylineno))
	vyyerror("Redefinition of function %s",$2);
      skip_until("Return");
    }
  | tIf '(' FExpr ')'
    {
      if(!$3) skip_until("EndIf");
    }
  | tEndIf
    {
    }
;


/* ---------------
    E X T R U D E 
   --------------- */

Extrude :
    tExtrude tPoint '{' FExpr ',' VExpr '}' tEND
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(1,(int)$4,$6[0],$6[1],$6[2],0.,0.,0.,0.,&pc,&prc,NULL);
    }
  | tExtrude tPoint '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Curve *pc, *prc;
      Extrude_ProtudePoint(0,(int)$4,$6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,
			   &pc,&prc,NULL);
    }
  | tExtrude tLine'{' FExpr ',' VExpr '}' tEND
    {
      Extrude_ProtudeCurve(1,(int)$4,$6[0],$6[1],$6[2],0.,0.,0.,0.,NULL);
    }
  | tExtrude tLine'{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Extrude_ProtudeCurve(0,(int)$4,$6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,NULL);
    }
  |  tExtrude tSurface '{' FExpr ',' VExpr '}' tEND
    {
      Extrude_ProtudeSurface(1,(int)$4,$6[0],$6[1],$6[2],0.,0.,0.,0.,0,NULL);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' tEND
    {
      Extrude_ProtudeSurface(0,(int)$4,$6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,0,NULL);
    }
  | tExtrude tSurface '{' FExpr ',' VExpr '}' '{' ExtrudeParameters '}' tEND
  {
    int vol = NEWREG();
    Extrude_ProtudeSurface(1,(int)$4,$6[0],$6[1],$6[2],0.,0.,0.,0.,vol,&extr);
  }
  | tExtrude tSurface '{' FExpr ',' VExpr ',' VExpr ',' FExpr '}' '{' ExtrudeParameters '}'tEND
  {
    int vol = NEWREG();
    Extrude_ProtudeSurface(0,(int)$4,$6[0],$6[1],$6[2],$8[0],$8[1],$8[2],$10,vol,&extr);
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
      int j;
      extr.mesh.NbLayer = List_Nbr($3);
      extr.mesh.ExtrudeMesh = true;
      for(int i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)d;
	extr.mesh.NbElmLayer[i] = j;
	List_Read($5,i,&d);
	j = (int)d;
	extr.mesh.ZonLayer[i] = j;
	List_Read($7,i,&d);
	extr.mesh.hLayer[i] = d;
      }
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
	  vyyerror("Unkown Curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (int)$5;
	  c->ipar[1] = sign(d);
	  c->dpar[0] = 1.0;
	}
      }
    }
  | tTransfinite tLine ListOfDouble tAFFECT FExpr tUsing tProgression FExpr tEND
    {
      Curve *c;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)fabs(d);
        c = FindCurve(j,THEM);
	if(!c)
	  vyyerror("Unkown Curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (int)$5;
	  c->ipar[1] = sign(d); /* Progresion : code 1 ou -1 */
	  c->dpar[0] = fabs($8);
	}
      }
    }
  | tTransfinite tLine ListOfDouble tAFFECT FExpr tUsing tBump FExpr tEND
    {
      Curve *c;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)fabs(d);
        c = FindCurve(j,THEM);
	if(!c)
	  vyyerror("Unkown Curve %d", j);
	else{
	  c->Method = TRANSFINI;
	  c->ipar[0] = (int)$5;
	  c->ipar[1] = 2*sign(d); /* Bump : code 2 ou -2 */
	  c->dpar[0] = fabs($8);
	}
      }
    }
  | tTransfinite tSurface '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Surface *s = FindSurface((int)$4,THEM);
      if(!s)
	vyyerror("Unkown Surface %d", (int)$4);
      else{
	s->Method = TRANSFINI;
	k = List_Nbr($7);
	if(k!=3 && k!=4){
	  vyyerror("Wrong Definition of Transfinite Surface %d: "
		   "%d Points Instead of 3 or 4" , $4, k) ;
	}
	else{
	  for(i=0;i<k;i++){
	    List_Read($7,i,&d);
	    j = (int)fabs(d);
	    s->ipar[i] = j;
	  }
	}
      }
    }
  | tElliptic tSurface '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Surface *s = FindSurface((int)$4,THEM);
      if(!s)
	vyyerror("Unkown Surface %d", (int)$4);
      else{
        s->Method = ELLIPTIC;
        k = List_Nbr($7);
        if(k != 4)
	  vyyerror("Wrong Definition of Elliptic Surface %d: "
		   "%d Points Instead of 4" , $4, k) ;
        else{
	  for(i=0;i<k;i++){
	    List_Read($7,i,&d);
	    j = (int)fabs(d);
	    s->ipar[i] = j;
	  }
	}
      }
    }
  | tTransfinite tVolume '{' FExpr '}' tAFFECT ListOfDouble tEND
    {
      Volume *v = FindVolume((int)$4,THEM);
      if(!v)
	vyyerror("Unkown Volume %d", (int)$4);
      else{
	v->Method = TRANSFINI;
	k = List_Nbr($7);
	if(k!=6 && k!=8)
	  vyyerror("Wrong Definition of Transfinite Volume %d: "
		   "%d Points Instead of 6 or 8" , $4, k) ;
	else{
	  for(i=0;i<k;i++){
	    List_Read($7,i,&d);
	    j = (int)fabs(d);
	    v->ipar[i] = j;
	  }
	}
      }
    }
  | tRecombine tSurface ListOfDouble tAFFECT FExpr tEND
    {
      Surface *s;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)d;
	s = FindSurface(j,THEM);
	if(!s){
	  /* Allow generic lists, even if the surfaces don't exist
	     vyyerror("Unkown Surface %d", j); */
	}
	else{
	  s->Recombine = 1;
	  s->RecombineAngle = $5;
	}
      }
    }
  | tRecombine tSurface ListOfDouble tEND
    {
      Surface *s;
      for(i=0;i<List_Nbr($3);i++){
	List_Read($3,i,&d);
	j = (int)d;
        s = FindSurface(j,THEM);
	if(!s){
	  /* Allow generic lists, even if the surfaces don't exist
	     vyyerror("Unkown Surface %d", j); */
	}
	else{
	  s->Recombine = 1;
	  s->RecombineAngle = 30.;
        }
      }
    }  
;


/* -------------------
    C O H E R E N C E
   ------------------- */

Coherence : 
    tCoherence tEND
    { 
      Coherence_PS();
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
	vyyerror("Division by Zero in '%g / %g'", $1, $3);
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
;

/* Pour etre vraiment complet, il faudrait encore ajouter +=, -=, *= et /= */

FExpr_Single :

  /* -------- Constants -------- */ 

    tDOUBLE   { $$ = $1; }
  | tPi       { $$ = 3.141592653589793; }

  /* -------- Variables -------- */ 

  | tSTRING
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $1) ;
	$$ = 0. ;
      }
      else{
	$$ = *(double*)List_Pointer_Fast(pSymbol->val, 0) ;
      }
      Free($1);
    }
  | tSTRING '[' FExpr ']'
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $1) ;
	$$ = 0. ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  $$ = *pd ;
	else{
	  vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
	  $$ = 0. ;
	}
      }
      Free($1);
    }

  | tSTRING tPLUSPLUS
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $1) ;
	$$ = 0. ;
      }
      else{
	$$ = (*(double*)List_Pointer_Fast(pSymbol->val, 0) += 1.0) ;
      }
      Free($1);
    }
  | tSTRING '[' FExpr ']' tPLUSPLUS
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $1) ;
	$$ = 0. ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  $$ = (*pd += 1.0) ;
	else{
	  vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
	  $$ = 0. ;
	}
      }
      Free($1);
    }

  | tSTRING tMINUSMINUS
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $1) ;
	$$ = 0. ;
      }
      else{
	$$ = (*(double*)List_Pointer_Fast(pSymbol->val, 0) -= 1.0) ;
      }
      Free($1);
    }
  | tSTRING '[' FExpr ']' tMINUSMINUS
    {
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $1) ;
	$$ = 0. ;
      }
      else{
	if((pd = (double*)List_Pointer_Test(pSymbol->val, (int)$3)))
	  $$ = (*pd -= 1.0) ;
	else{
	  vyyerror("Uninitialized Variable '%s[%d]'", $1, (int)$3) ;
	  $$ = 0. ;
	}
      }
      Free($1);
    }

  /* -------- Option Strings -------- */ 

  | tSTRING '.' tSTRING 
    {
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	vyyerror("Unknown Numeric Option Class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i))){
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	  $$ = 0. ;
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : $$ = *(double*)pNumOpt ; break ;
	  case GMSH_FLOAT : $$ = (double)(*(float*)pNumOpt) ; break ;
	  case GMSH_LONG : $$ = (double)(*(long*)pNumOpt) ; break ;
	  case GMSH_INT : $$ = (double)(*(int*)pNumOpt) ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING
    {
      if(strcmp($1, "PostProcessing")){
	vyyerror("Unknown View Option Class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	  $$ = 0. ;
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : $$ = *(double*)pNumOpt ; break ;
	  case GMSH_FLOAT : $$ = (double)(*(float*)pNumOpt) ; break ;
	  case GMSH_LONG : $$ = (double)(*(long*)pNumOpt) ; break ;
	  case GMSH_INT : $$ = (double)(*(int*)pNumOpt) ; break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tPLUSPLUS
    {
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	vyyerror("Unknown Numeric Option Class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i))){
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	  $$ = 0. ;
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : $$ = (*(double*)pNumOpt += 1.) ; break ;
	  case GMSH_FLOAT : $$ = (double)(*(float*)pNumOpt += 1.) ; break ;
	  case GMSH_LONG : $$ = (double)(*(long*)pNumOpt += 1) ; break ;
	  case GMSH_INT : $$ = (double)(*(int*)pNumOpt += 1) ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tPLUSPLUS
    {
      if(strcmp($1, "PostProcessing")){
	vyyerror("Unknown View Option Class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	  $$ = 0. ;
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : $$ = (*(double*)pNumOpt += 1.) ; break ;
	  case GMSH_FLOAT : $$ = (double)(*(float*)pNumOpt += 1.) ; break ;
	  case GMSH_LONG : $$ = (double)(*(long*)pNumOpt += 1) ; break ;
	  case GMSH_INT : $$ = (double)(*(int*)pNumOpt += 1) ; break ;
	  }
	}
      }
    }

  | tSTRING '.' tSTRING tMINUSMINUS
    {
      if(!(pNumCat = Get_NumberOptionCategory($1))){
	vyyerror("Unknown Numeric Option Class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt = Get_NumberOption($3, pNumCat, &i))){
	  vyyerror("Unknown Numeric Option '%s.%s'", $1, $3);
	  $$ = 0. ;
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : $$ = (*(double*)pNumOpt -= 1.) ; break ;
	  case GMSH_FLOAT : $$ = (double)(*(float*)pNumOpt -= 1.) ; break ;
	  case GMSH_LONG : $$ = (double)(*(long*)pNumOpt -= 1) ; break ;
	  case GMSH_INT : $$ = (double)(*(int*)pNumOpt -= 1) ; break ;
	  }
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING tMINUSMINUS
    {
      if(strcmp($1, "PostProcessing")){
	vyyerror("Unknown View Option Class '%s'", $1);
	$$ = 0. ;
      }
      else{
	if(!(pNumOpt = Get_NumberViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Numeric Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	  $$ = 0. ;
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE : $$ = (*(double*)pNumOpt -= 1.) ; break ;
	  case GMSH_FLOAT : $$ = (double)(*(float*)pNumOpt -= 1.) ; break ;
	  case GMSH_LONG : $$ = (double)(*(long*)pNumOpt -= 1) ; break ;
	  case GMSH_INT : $$ = (double)(*(int*)pNumOpt -= 1) ; break ;
	  }
	}
      }
    }
;

FExpr_Range :
    FExpr tDOTS FExpr
    { 
      ListOfDouble2_L = List_Create(2,1,sizeof(double)) ; 
      for(d=$1 ; ($1<$3)?(d<=$3):(d>=$3) ; ($1<$3)?(d+=1.):(d-=1.)) 
	List_Add(ListOfDouble2_L, &d) ;
    }
  | FExpr tDOTS FExpr tDOTS FExpr
   {
      ListOfDouble2_L = List_Create(2,1,sizeof(double)) ; 
      if(!$5 || ($1<$3 && $5<0) || ($1>$3 && $5>0)){
        vyyerror("Wrong Increment in '%g:%g:%g'", $1, $3, $5) ;
	List_Add(ListOfDouble2_L, &($1)) ;
      }
      else 
	for(d=$1 ; ($5>0)?(d<=$3):(d>=$3) ; d+=$5)
	  List_Add(ListOfDouble2_L, &d) ;
   }
  ;

VExpr :
    VExpr_Single
    {
      memcpy($$, $1, 5*sizeof(double)) ;
      //??? Avec ce qui suit, bison se plante sur DEC
      //for(i=0 ; i<5 ; i++) $$[i] = $1[i];
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
  | tSTRING '.' tSTRING
    {
      if(!(pArrCat = Get_ArrayOptionCategory($1))){
	vyyerror("Unknown Array Option Class '%s'", $1);
	$$[0]=$$[1]=$$[2]=$$[3]= 0.0 ;
	$$[4]= 1.0 ;
      }
      else{
	if(!(pArrOpt = Get_ArrayOption($3, pArrCat, &i))){
	  vyyerror("Unknown Array Option '%s.%s'", $1, $3);
	  $$[0]=$$[1]=$$[2]=$$[3]= 0.0 ;
	  $$[4]= 1.0 ;
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE :
	    for(j=0 ; j<4 ; j++) $$[j] = ((double*)pArrOpt)[j] ; 
	    break ;
	  case GMSH_FLOAT :
	    for(j=0 ; j<4 ; j++) $$[j] = (double)((float*)pArrOpt)[j] ;
	    break ;
	  case GMSH_LONG : 
	    for(j=0 ; j<4 ; j++) $$[j] = (double)((int*)pArrOpt)[j] ; 
	    break ;
	  case GMSH_INT :
	    for(j=0 ; j<4 ; j++) $$[j] = (double)((int*)pArrOpt)[j] ; 
	    break ;
	  }
	  $$[4] = 1. ;
	}
      }
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tSTRING
    {
      if(strcmp($1, "PostProcessing")){
	vyyerror("Unknown View Option Class '%s'", $1);
	$$[0]=$$[1]=$$[2]=$$[3]= 0.0 ;
	$$[4]= 1.0 ;
      }
      else{
	if(!(pArrOpt = Get_ArrayViewOption((int)$5, $8, &i))){
	  if(i < 0) vyyerror("PostProcessing View %d does not Exist", (int)$5);
	  else	    vyyerror("Unknown Array Option '%s.View[%d].%s'", 
			     $1, (int)$5, $8);
	  $$[0]=$$[1]=$$[2]=$$[3]= 0.0 ;
	  $$[4]= 1.0 ;
	}
	else{
	  switch(i){
	  case GMSH_DOUBLE :
	    for(j=0 ; j<3 ; j++) $$[j] = ((double*)pArrOpt)[j] ; 
	    break ;
	  case GMSH_FLOAT :
	    for(j=0 ; j<3 ; j++) $$[j] = (double)((float*)pArrOpt)[j] ;
	    break ;
	  case GMSH_LONG : 
	    for(j=0 ; j<3 ; j++) $$[j] = (double)((int*)pArrOpt)[j] ; 
	    break ;
	  case GMSH_INT :
	    for(j=0 ; j<3 ; j++) $$[j] = (double)((int*)pArrOpt)[j] ; 
	    break ;
	  }
	  $$[3] = 0. ;
	  $$[4] = 1. ;
	}
      }
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
       $$=ListOfListOfDouble_L;
    }
  | '(' RecursiveListOfListOfDouble ')'
    {
       $$=ListOfListOfDouble_L;
    }
;

RecursiveListOfListOfDouble :
    ListOfDouble
    {
      ListOfListOfDouble_L = List_Create(2,1,sizeof(List_T*)) ;
      List_Add(ListOfListOfDouble_L, &($1)) ;
    }
  | RecursiveListOfListOfDouble ',' ListOfDouble
    {
      List_Add(ListOfListOfDouble_L, &($3)) ;
    }
;

ListOfDouble :
    /* none */
    {
    }
  | FExpr
    {
      ListOfDouble_L = List_Create(2,1,sizeof(double)) ;
      List_Add(ListOfDouble_L, &($1)) ;
      $$=ListOfDouble_L;
    }
  | tSTRING '[' ']'
    {
      ListOfDouble_L = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $1) ;
	d = 0.0 ;
	List_Add(ListOfDouble_L, &d);
      }
      else{
	for(i = 0 ; i < List_Nbr(pSymbol->val) ; i++)
	  List_Add(ListOfDouble_L, (double*)List_Pointer_Fast(pSymbol->val, i)) ;
      }
      $$=ListOfDouble_L;
    }
  | '{' RecursiveListOfDouble '}'
    {
      $$=ListOfDouble_L;
    }
;


RecursiveListOfDouble :
    FExpr
    {
      ListOfDouble_L = List_Create(2,1,sizeof(double)) ;
      List_Add(ListOfDouble_L, &($1)) ;
    }
  | FExpr_Range
    { 
      ListOfDouble_L = List_Create(2,1,sizeof(double)) ;
      for(i=0 ; i<List_Nbr(ListOfDouble2_L) ; i++){
	List_Read(ListOfDouble2_L, i, &d) ;
	List_Add(ListOfDouble_L, &d) ;
      }
      List_Delete(ListOfDouble2_L);
    }
  | tSTRING '[' ']'
    { 
      ListOfDouble_L = List_Create(2,1,sizeof(double)) ;
      TheSymbol.Name = $1 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $1) ;
      }
      else{
	for(i = 0 ; i < List_Nbr(pSymbol->val) ; i++)
	  List_Add(ListOfDouble_L, (double*)List_Pointer_Fast(pSymbol->val, i)) ;
      }
    }
  | RecursiveListOfDouble ',' FExpr
    {
      List_Add(ListOfDouble_L, &($3)) ;
    }
  | RecursiveListOfDouble ',' FExpr_Range
    {
      for(i=0 ; i<List_Nbr(ListOfDouble2_L) ; i++){
	List_Read(ListOfDouble2_L, i, &d) ;
	List_Add(ListOfDouble_L, &d) ;
      }
      List_Delete(ListOfDouble2_L);
    }
  | RecursiveListOfDouble ',' tSTRING '[' ']'
    {
      TheSymbol.Name = $3 ;
      if (!(pSymbol = (Symbol*)List_PQuery(Symbol_L, &TheSymbol, CompareSymbols))) {
	vyyerror("Unknown Variable '%s'", $3) ;
      }
      else{
	for(i = 0 ; i < List_Nbr(pSymbol->val) ; i++)
	  List_Add(ListOfDouble_L, (double*)List_Pointer_Fast(pSymbol->val, i)) ;
      }
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
  | '{' tSTRING ',' FExpr '}'
    {
      $$ = Get_ColorForString(ColorString, (int)$4, $2, &flag);
      if(flag) vyyerror("Unknown Color '%s'", $2);
    }
  | tSTRING
    {
      $$ = Get_ColorForString(ColorString, -1, $1, &flag);
      if(flag) vyyerror("Unknown Color '%s'", $1);
    }
  | tSTRING '.' tColor '.' tSTRING 
    {
      if(!(pColCat = Get_ColorOptionCategory($1))){
	vyyerror("Unknown Color Option Class '%s'", $1);
	$$ = 0 ;
      }
      else{
	if(!(pColOpt = Get_ColorOption($5, pColCat))){
	  vyyerror("Unknown Color Option '%s.%s'", $1, $5);
	  $$ = 0 ;
	}
	else{
	  $$ = *pColOpt ;
	}
      }
    }
;


ListOfColor :
    '{' RecursiveListOfColor '}'
    {
      $$ = ListOfColor_L;
    }
  | tSTRING '.' tView '[' FExpr ']' '.' tColor
    {
      if(!ListOfColor_L)
	ListOfColor_L = List_Create(256,10,sizeof(unsigned int)) ;
      else
	List_Reset(ListOfColor_L) ;
      if(strcmp($1, "PostProcessing"))
	vyyerror("Unknown View Option Class '%s'", $1);
      else{
	ColorTable *ct = Get_ColorTableViewOption((int)$5);
	if(!ct)
	  vyyerror("PostProcessing View %d does not Exist", (int)$5);
	else{
	  for(i=0 ; i<ct->size ; i++) 
	    List_Add(ListOfColor_L, &ct->table[i]);
	}
      }
      $$ = ListOfColor_L;
    }
;

RecursiveListOfColor :
    ColorExpr
    {
      if(!ListOfColor_L)
	ListOfColor_L = List_Create(256,10,sizeof(unsigned int)) ;
      else
	List_Reset(ListOfColor_L) ;
      List_Add(ListOfColor_L, &($1)) ;
    }
  | RecursiveListOfColor ',' ColorExpr
    {
      List_Add(ListOfColor_L, &($3)) ;
    }
;

StringExpr :
    tBIGSTR
    {
      $$ = $1;
    }
  | tSprintf '(' tBIGSTR ')'
    {
      $$ = $3;
    }
  | tSprintf '(' tBIGSTR ',' FExpr ')'
    {
      sprintf(tmpstring, $3, $5);
      $$ = (char*)Malloc(strlen(tmpstring));
      strcpy($$, tmpstring);
    }
;

%%

void InitSymbols(void){
  Symbol_L = List_Create(10,1,sizeof(Symbol));
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
  
void yyerror(char *s){
  Msg(PARSER_ERROR, "'%s', line %d : %s (%s)",yyname,yylineno-1,s,yytext);
  yyerrorstate=1;
}

void vyyerror(char *fmt, ...){
  va_list args;
  char tmp[TEXT_BUFFER_SIZE];

  va_start (args, fmt);
  vsprintf (tmp, fmt, args);
  va_end (args);

  Msg(PARSER_ERROR, "'%s', line %d : %s", yyname, yylineno-1, tmp);
  yyerrorstate=1;
}

