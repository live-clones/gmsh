// $Id: StepGeomDatabase.cpp,v 1.8 2002-05-18 07:18:00 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "Gmsh.h"
#include "Numeric.h"
#include "Geo.h"
#include "StepGeomDatabase.h"
#include "DataBase.h"
#include "Context.h"

extern Context_T CTX;

static Step_Solid_BRep_t *BREP=NULL;


Step_Solid_BRep_t *Create_Step_Solid_BRep(void){
  Step_Solid_BRep_t *NEWBREP;
  NEWBREP                       = (Step_Solid_BRep_t *)Malloc(sizeof(Step_Solid_BRep_t));
  NEWBREP->AllDirections        = List_Create(10,10,sizeof(Step_Direction_t));
  NEWBREP->AllVectors           = List_Create(10,10,sizeof(Step_Vector_t));
  NEWBREP->AllCartesian_Points  = List_Create(10,10,sizeof(Step_Cartesian_Point_t));
  NEWBREP->AllVertex_Points     = List_Create(10,10,sizeof(Step_Vertex_Point_t));
  NEWBREP->AllCurves            = List_Create(10,10,sizeof(Step_Curve_t));
  NEWBREP->AllSurfaces          = List_Create(10,10,sizeof(Step_Surface_t));
  NEWBREP->AllClosed_Shells     = List_Create(10,10,sizeof(Step_Closed_Shell_t));
  NEWBREP->AllFaces_Outer_Bound = List_Create(10,10,sizeof(Step_Face_Outer_Bound_t));
  NEWBREP->AllOriented_Edges    = List_Create(10,10,sizeof(Step_Oriented_Edge_t));
  NEWBREP->AllEdge_Loops        = List_Create(10,10,sizeof(Step_Edge_Loop_t));
  NEWBREP->AllEdge_Curves       = List_Create(10,10,sizeof(Step_Edge_Curve_t));
  NEWBREP->AllAdvanced_Faces    = List_Create(10,10,sizeof(Step_Advanced_Face_t));
  NEWBREP->AllAxis2_Placement3D = List_Create(10,10,sizeof(Step_Axis2_Placement3D_t));
  NEWBREP->AllClosed_Shells     = List_Create(10,10,sizeof(Step_Closed_Shell_t));
  BREP = NEWBREP;
  return NEWBREP;
}

// Directions

void Add_Direction (int Num , char *name , double x, double y, double z ){
  Step_Direction_t Dir;
  if(!BREP)return;
  Dir.Pos.X = x;
  Dir.Pos.Y = y;
  Dir.Pos.Z = z;
  Dir.Num = Num;
  List_Add(BREP->AllDirections,&Dir);
}

static int comparedir  (const void *a, const void *b){
  return (((Step_Direction_t *)a)->Num -
          ((Step_Direction_t *)b)->Num);
}

Step_Direction_t *Get_Direction (int Num){
  Step_Direction_t Dir;
  if(!BREP)return NULL;
  Dir.Num = Num;
  return (Step_Direction_t*)List_PQuery ( BREP->AllDirections,&Dir, comparedir );
}

// Axis2_Placement3D

void Add_Axis2_Placement3D (int Num, int dir1, int dir2, int ver){
  Step_Axis2_Placement3D_t Axe;
  if(!BREP)return;
  Axe.Num = Num;
  Axe.Step_Cartesian_Point = ver;
  Axe.Step_Direction1 = dir1;
  Axe.Step_Direction2 = dir2;
  List_Add(BREP->AllAxis2_Placement3D,&Axe);
}

static int compareax  (const void *a, const void *b){
  return (((Step_Axis2_Placement3D_t *)a)->Num -
          ((Step_Axis2_Placement3D_t *)b)->Num);
}

Step_Axis2_Placement3D_t *Get_Axis2_Placement3D (int Num){
  Step_Axis2_Placement3D_t Axe;
  if(!BREP)return NULL;
  Axe.Num = Num;
  return (Step_Axis2_Placement3D_t*)List_PQuery ( BREP->AllAxis2_Placement3D,
                                                  &Axe, compareax );
}

// Vectors

void Add_Vector (int Num , char *name , int Dir, double l ){
  Step_Vector_t Vec;
  if(!BREP)return;
  Vec.Lenght = l;
  Vec.Step_Direction = Dir;
  Vec.Num = Num;
  List_Add(BREP->AllVectors,&Vec);
}

static int comparevec  (const void *a, const void *b){
  return (((Step_Vector_t *)a)->Num -
          ((Step_Vector_t *)b)->Num);
}

Step_Vector_t *Get_Vector (int Num){
  Step_Vector_t Vec;
  if(!BREP)return NULL;
  Vec.Num = Num;
  return (Step_Vector_t*)List_PQuery ( BREP->AllVectors,&Vec, comparevec );
}

// Cartesian_Points

void Add_Cartesian_Point (int Num , char *name , double x, double y, double z){
  Step_Cartesian_Point_t CP;

  if(!BREP){
    return;
  }
  CP.Pos.X = x;
  CP.Pos.Y = y;
  CP.Pos.Z = z;
  CP.Num = Num;
   
  List_Add(BREP->AllCartesian_Points,&CP);
}
static int comparecp  (const void *a, const void *b){
  return (((Step_Cartesian_Point_t *)a)->Num -
          ((Step_Cartesian_Point_t *)b)->Num);
}
Step_Cartesian_Point_t *Get_Cartesian_Point (int Num){
  Step_Cartesian_Point_t CP;
  if(!BREP)return NULL;
  CP.Num = Num;
  return (Step_Cartesian_Point_t*)List_PQuery ( BREP->AllCartesian_Points,&CP, comparecp );
}

// Vertex_Points

void Add_Vertex_Point (int Num , char *name, int cp){
  Step_Vertex_Point_t VP;
  if(!BREP)return;
  VP.Cartesian_Point = cp;
  VP.Num = Num;
  List_Add(BREP->AllVertex_Points,&VP);
}
static int comparevp  (const void *a, const void *b){
  return (((Step_Vertex_Point_t *)a)->Num -
          ((Step_Vertex_Point_t *)b)->Num);
}
Step_Vertex_Point_t *Get_Vertex_Point (int Num){
  Step_Vertex_Point_t VP;
  if(!BREP)return NULL;
  VP.Num = Num;
  return (Step_Vertex_Point_t*)List_PQuery ( BREP->AllVertex_Points,&VP, comparevp );
}


// Curves

void Add_Line (int Num, char *name , int begin, int dir){
  Step_Curve_t Curve;
  if(!BREP)return;
  Curve.Num = Num;
  Curve.Typ = STEP_LINE;
  Curve.Curve.Line.Step_Cartesian_Point = begin;
  Curve.Curve.Line.Step_Vector = dir;
  List_Add(BREP->AllCurves,&Curve);
}

void Add_Circle (int Num, char *name , int axis, double radius){
  Step_Curve_t Curve;
  if(!BREP)return;
  Curve.Num = Num;
  Curve.Typ = STEP_CIRC;
  Curve.Curve.Circle.Radius1 = radius;
  Curve.Curve.Circle.Radius2 = radius;
  Curve.Curve.Circle.Step_Axis2_Placement3D = axis;
  List_Add(BREP->AllCurves,&Curve);
}

void Add_Ellipse (int Num, char *name , int axis, double radius1, double radius2){
  Step_Curve_t Curve;
  if(!BREP)return;
  Curve.Num = Num;
  Curve.Typ = STEP_ELLP;
  Curve.Curve.Circle.Radius1 = radius1;
  Curve.Curve.Circle.Radius2 = radius2;
  Curve.Curve.Circle.Step_Axis2_Placement3D = axis;
  List_Add(BREP->AllCurves,&Curve);
}

void Add_BSpline_Curve_With_Knots (int Num, char *name, int Order, List_T *lcp,
                                   List_T *multk, List_T *knots, double udeb, double uend){
  Step_Curve_t Curve;
  int i,j,mult;
  double d;

  if(!BREP)return;
  Curve.Num = Num;
  Curve.Typ = STEP_BSPL;
  Curve.Curve.BSpline.ListOf_Knots = List_Create (List_Nbr(lcp) + Order + 1
                                                  ,1,sizeof(double));
  // Adding knots with their multiplicity
  for(i=0;i<List_Nbr(multk);i++){
    List_Read(multk,i,&d);
    mult = (int)d;
    List_Read(knots,i,&d);
    for(j=0;j<mult;j++){
      List_Add(Curve.Curve.BSpline.ListOf_Knots,&d);
    }
  }
  Curve.Curve.BSpline.ListOf_Cartesian_Points = List_Create(List_Nbr(lcp),1,sizeof(int));
  for(i=0;i<List_Nbr(lcp);i++){
    List_Read(lcp,i,&d);
    j = (int)d;
    List_Add(Curve.Curve.BSpline.ListOf_Cartesian_Points,&j);
  }
  Curve.Curve.BSpline.Order = Order;
  Curve.Curve.BSpline.Ubeg = udeb;
  Curve.Curve.BSpline.Uend = uend;
  List_Add(BREP->AllCurves,&Curve);
}

static int comparecur  (const void *a, const void *b){
  return (((Step_Curve_t *)a)->Num -
          ((Step_Curve_t *)b)->Num);
}
Step_Curve_t *Get_Curve (int Num){
  Step_Curve_t C;
  if(!BREP)return NULL;
  C.Num = Num;
  return (Step_Curve_t*)List_PQuery ( BREP->AllCurves,&C, comparecur );
}

// Edge_Curves

void Add_Edge_Curve (int Num, char *name , int beg, int end, int curve ){
  Step_Edge_Curve_t EC;
  if(!BREP)return;
  EC.Num = Num;
  EC.Step_Vertex_Point_Begin = beg;
  EC.Step_Vertex_Point_End   = end;
  EC.Step_Curve = curve;
  List_Add(BREP->AllEdge_Curves,&EC);
}

static int compareec  (const void *a, const void *b){
  return (((Step_Edge_Curve_t *)a)->Num -
          ((Step_Edge_Curve_t *)b)->Num);
}
Step_Edge_Curve_t *Get_Edge_Curve (int Num){
  Step_Edge_Curve_t EC;
  if(!BREP)return NULL;
  EC.Num = Num;
  return (Step_Edge_Curve_t*)List_PQuery ( BREP->AllEdge_Curves,&EC, compareec );
}

// Oriented_Edges

void Add_Oriented_Edge (int Num, char *name , int ec, bool dir ){
  Step_Oriented_Edge_t OE;
  if(!BREP)return;
  OE.Num = Num;
  OE.Step_Edge_Curve = ec;
  OE.dir = dir;
  List_Add(BREP->AllOriented_Edges,&OE);
}

static int compareoe  (const void *a, const void *b){
  return (((Step_Oriented_Edge_t *)a)->Num -
          ((Step_Oriented_Edge_t *)b)->Num);
}
Step_Oriented_Edge_t *Get_Oriented_Edge (int Num){
  Step_Oriented_Edge_t OE;
  if(!BREP)return NULL;
  OE.Num = Num;
  return (Step_Oriented_Edge_t*)List_PQuery ( BREP->AllOriented_Edges,&OE, compareoe );
}

// Edge_Loops

void Add_Edge_Loop (int Num, char *name , List_T *list ){
  Step_Edge_Loop_t EL;
  if(!BREP)return;
  EL.Num = Num;
  EL.ListOf_Step_Oriented_Edge = list;
  List_Add(BREP->AllEdge_Loops,&EL);
}

static int compareel  (const void *a, const void *b){
  return (((Step_Edge_Loop_t *)a)->Num -
          ((Step_Edge_Loop_t *)b)->Num);
}
Step_Edge_Loop_t *Get_Edge_Loop (int Num){
  Step_Edge_Loop_t EL;
  if(!BREP)return NULL;
  EL.Num = Num;
  return (Step_Edge_Loop_t*)List_PQuery ( BREP->AllEdge_Loops,&EL, compareel );
}

// Faces_Outer_Bounds

void Add_Face_Outer_Bound (int Num, char *name , int el, bool dir, bool outer ){
  Step_Face_Outer_Bound_t F;
  if(!BREP)return;
  F.Num = Num;
  F.Step_Edge_Loop = el;
  F.dir = dir;
  F.outer = outer;
  List_Add(BREP->AllFaces_Outer_Bound,&F);
}

static int comparefab  (const void *a, const void *b){
  return (((Step_Face_Outer_Bound_t *)a)->Num -
          ((Step_Face_Outer_Bound_t *)b)->Num);
}
Step_Face_Outer_Bound_t *Get_Face_Outer_Bound (int Num){
  Step_Face_Outer_Bound_t F;
  if(!BREP)return NULL;
  F.Num = Num;
  return (Step_Face_Outer_Bound_t*)List_PQuery ( BREP->AllFaces_Outer_Bound,&F, comparefab );
}

// Advanced_Faces

void Add_Advanced_Face (int Num, char *name , List_T *el, int surf, bool dir ){
  Step_Advanced_Face_t F;
  if(!BREP)return;
  F.Num = Num;
  F.ListOf_Step_Face_Outer_Bound = el;
  F.Step_Surface = surf;
  F.dir = dir;
  List_Add(BREP->AllAdvanced_Faces,&F);
}

static int compareaf  (const void *a, const void *b){
  return (((Step_Advanced_Face_t *)a)->Num -
          ((Step_Advanced_Face_t *)b)->Num);
}
Step_Advanced_Face_t *Get_Advanced_Face (int Num){
  Step_Advanced_Face_t F;
  if(!BREP)return NULL;
  F.Num = Num;
  return (Step_Advanced_Face_t*)List_PQuery ( BREP->AllAdvanced_Faces,&F, compareaf );
}

// Surfaces

void Add_Plane (int Num, char *name , int axis){
  Step_Surface_t Surface;
  if(!BREP)return;
  Surface.Num = Num;
  Surface.Typ = STEP_PLAN;
  Surface.Surface.Plane.Step_Axis2_Placement3D = axis;
  List_Add(BREP->AllSurfaces,&Surface);
}

void Add_Cylinder (int Num, char *name , int axis, double radius){
  Step_Surface_t S;
  if(!BREP)return;
  S.Num = Num;
  S.Typ = STEP_CYLD;
  S.Surface.Quadric.Radius1 = radius;
  S.Surface.Quadric.Radius2 = 0.0;
  S.Surface.Quadric.Step_Axis2_Placement3D = axis;
  List_Add(BREP->AllSurfaces,&S);
}

void Add_Torus (int Num, char *name , int axis, double radius1, double radius2){
  Step_Surface_t S;
  if(!BREP)return;
  S.Num = Num;
  S.Typ = STEP_TORD;
  S.Surface.Quadric.Radius1 = radius1;
  S.Surface.Quadric.Radius2 = radius2;
  S.Surface.Quadric.Step_Axis2_Placement3D = axis;
  List_Add(BREP->AllSurfaces,&S);
}

void Add_Cone (int Num, char *name , int axis, double radius1, double radius2){
  Step_Surface_t S;
  if(!BREP)return;
  S.Num = Num;
  S.Typ = STEP_CONE;
  S.Surface.Quadric.Radius1 = radius1;
  S.Surface.Quadric.Radius2 = radius2;
  S.Surface.Quadric.Step_Axis2_Placement3D = axis;
  List_Add(BREP->AllSurfaces,&S);
}


void Add_BSpline_Surface_With_Knots (int Num,char *name, int OrderU,int OrderV,
                                     List_T *lcp,List_T *lmu, List_T *lmv, List_T *lku,
                                     List_T *lkv, double udeb, double uend, double vdeb,
                                     double vend){
  Step_Surface_t Surface;
  int i,j,mult;
  double d;

  if(!BREP)return;

  Surface.Surface.BSpline.ListOf_KnotsU = 
    List_Create (List_Nbr(lku) + OrderU + 1,1,sizeof(double));
  Surface.Surface.BSpline.ListOf_KnotsV =
    List_Create (List_Nbr(lkv) + OrderV + 1,1,sizeof(double));

  // Adding knots with their multiplicity
  for(i=0;i<List_Nbr(lmu);i++){
    List_Read(lmu,i,&d);
    mult = (int)d;
    List_Read(lku,i,&d);
    for(j=0;j<mult;j++){
      List_Add(Surface.Surface.BSpline.ListOf_KnotsU,&d);
    }
  }
  for(i=0;i<List_Nbr(lmv);i++){
    List_Read(lmv,i,&d);
    mult = (int)d;
    List_Read(lkv,i,&d);
    for(j=0;j<mult;j++){
      List_Add(Surface.Surface.BSpline.ListOf_KnotsV,&d);
    }
  }

  // Adding the points !
  Surface.Surface.BSpline.ListOf_Cartesian_Points = lcp;
    
  Surface.Num = Num;
  Surface.Typ = STEP_BSPL;
  Surface.Surface.BSpline.OrderU = OrderU;
  Surface.Surface.BSpline.OrderV = OrderV;
  Surface.Surface.BSpline.Ubeg = udeb;
  Surface.Surface.BSpline.Uend = uend;
  Surface.Surface.BSpline.Vbeg = vdeb;
  Surface.Surface.BSpline.Vend = vend;
  List_Add(BREP->AllSurfaces,&Surface);
}

static int comparesur  (const void *a, const void *b){
  return (((Step_Surface_t *)a)->Num -
          ((Step_Surface_t *)b)->Num);
}
Step_Surface_t *Get_Surface (int Num){
  Step_Surface_t S;
  if(!BREP)return NULL;
  S.Num = Num;
  return (Step_Surface_t*)List_PQuery ( BREP->AllSurfaces,&S, comparesur );
}

// Closed_Shells

void Add_Closed_Shell (int Num, char *name , List_T *list ){
  Step_Closed_Shell_t S;
  if(!BREP)return;
  S.Num = Num;
  S.ListOf_Step_Advanced_Face = list;
  List_Add(BREP->AllClosed_Shells,&S);
}

static int comparecs  (const void *a, const void *b){
  return (((Step_Closed_Shell_t *)a)->Num -
          ((Step_Closed_Shell_t *)b)->Num);
}
Step_Closed_Shell_t *Get_Closed_Shell (int Num){
  Step_Closed_Shell_t F;
  if(!BREP)return NULL;
  F.Num = Num;
  return (Step_Closed_Shell_t*)List_PQuery ( BREP->AllClosed_Shells,&F, comparecs );
}

// Closed_Shells

void Resolve_BREP (void){
  int i,j,k,l;
  double d;
  int obj,err,typ;
  Step_Vertex_Point_t      vp;
  Step_Direction_t         *d1,*d2;
  Step_Cartesian_Point_t   *pcp,cp;
  Step_Edge_Curve_t        ec;
  Step_Curve_t             *pc;
  Step_Advanced_Face_t     af, *paf;
  Step_Surface_t           s;
  Step_Surface_t           *ps;
  Step_Face_Outer_Bound_t  *pfab;
  Step_Edge_Loop_t         *pel;
  Step_Oriented_Edge_t     *poe;
  Step_Axis2_Placement3D_t *axs;
  Step_Closed_Shell_t      cs;
  List_T  *ListInt,*ListIntBis;
  double ubeg,uend,n[3],t[3],p[3],XMIN,XMAX,YMIN,YMAX,ZMIN,ZMAX,L;
  int fob;

  ListInt    = List_Create(2,2,sizeof(int));
  ListIntBis = List_Create(2,2,sizeof(int));

  for(i=0;i<List_Nbr(BREP->AllCartesian_Points);i++){
    List_Read(BREP->AllCartesian_Points,i,&cp);
    XMAX = MAX(cp.Pos.X,XMAX);
    YMAX = MAX(cp.Pos.Y,YMAX);
    ZMAX = MAX(cp.Pos.Z,ZMAX);
    XMIN = MIN(cp.Pos.X,XMIN);
    YMIN = MIN(cp.Pos.Y,YMIN);
    ZMIN = MIN(cp.Pos.Z,ZMIN);
  }
  CTX.lc = L = sqrt(SQR(XMIN-XMAX) + SQR(YMIN-YMAX) + SQR(ZMIN-ZMAX));

  // resolving cartesian_points
  for(i=0;i<List_Nbr(BREP->AllCartesian_Points);i++){
    List_Read(BREP->AllCartesian_Points,i,&cp);
    Cdbpts101(cp.Num,cp.Pos.X,cp.Pos.Y,cp.Pos.Z,L*.01,1);
  }

  // resolving vertex_points
  for(i=0;i<List_Nbr(BREP->AllVertex_Points);i++){
    List_Read(BREP->AllVertex_Points,i,&vp);
    if((pcp = Get_Cartesian_Point(vp.Cartesian_Point))){
      Cdbpts101(vp.Num,pcp->Pos.X,pcp->Pos.Y,pcp->Pos.Z,L*.01,1);
    }
  }

  // resolving Edge_Curves
  for(i=0;i<List_Nbr(BREP->AllEdge_Curves);i++){
    List_Read(BREP->AllEdge_Curves,i,&ec);
    if((pc = Get_Curve(ec.Step_Curve))){
      if(pc->Typ == STEP_LINE){
        List_Add(ListInt,&ec.Step_Vertex_Point_Begin);
        List_Add(ListInt,&ec.Step_Vertex_Point_End);
        Cdbseg101(ec.Num,MSH_SEGM_LINE,1,NULL,ListInt,-1,-1,0.,1.,NULL,NULL,NULL);
        List_Reset(ListInt);
      }
      else if(pc->Typ == STEP_BSPL){
        List_Read( pc->Curve.BSpline.ListOf_Knots , 0, &ubeg);
        List_Read( pc->Curve.BSpline.ListOf_Knots ,
                   List_Nbr(pc->Curve.BSpline.ListOf_Knots)-1, &uend);
        AddCurveInDataBase (ec.Num,
                            MSH_SEGM_NURBS,
                            pc->Curve.BSpline.Order,
                            pc->Curve.BSpline.ListOf_Cartesian_Points,
                            pc->Curve.BSpline.ListOf_Knots,
                            ec.Step_Vertex_Point_Begin,
                            ec.Step_Vertex_Point_End,
                            ubeg,
                            uend);
      }
      else if(pc->Typ == STEP_CIRC || pc->Typ == STEP_ELLP){
        axs =  Get_Axis2_Placement3D(pc->Curve.Circle.Step_Axis2_Placement3D);
        pcp =  Get_Cartesian_Point(axs->Step_Cartesian_Point);
        d1 =  Get_Direction(axs->Step_Direction1);
        d2 =  Get_Direction(axs->Step_Direction2);
        n[0] = d1->Pos.X;
        n[1] = d1->Pos.Y;
        n[2] = d1->Pos.Z;

        List_Add(ListInt,&ec.Step_Vertex_Point_Begin);
        List_Add(ListInt,&pcp->Num);
        List_Add(ListInt,&ec.Step_Vertex_Point_End);
        AddCircleInDataBase ( ec.Num,MSH_SEGM_CIRC ,
                              ListInt,n);
        // Cdbseg101(ec.Num,MSH_SEGM_CIRC,1,NULL,
	// ListInt,-1,-1,0.,1.,NULL,NULL,NULL);
        List_Reset(ListInt);
      }
    }
  }

  // resolving Surfaces
  for(i=0;i<List_Nbr(BREP->AllSurfaces);i++){
    List_Read(BREP->AllSurfaces,i,&s);
    if(s.Typ == STEP_BSPL){
      CreateNurbsSurfaceSupport (
                                 s.Num ,
                                 s.Surface.BSpline.OrderV ,
                                 s.Surface.BSpline.OrderU ,
                                 s.Surface.BSpline.ListOf_Cartesian_Points ,
                                 s.Surface.BSpline.ListOf_KnotsV ,
                                 s.Surface.BSpline.ListOf_KnotsU );

    }
  }

  // resolving Advanced_Faces

  for(i=0;i<List_Nbr(BREP->AllAdvanced_Faces);i++){
    err = 0;
    List_Read(BREP->AllAdvanced_Faces,i,&af);
    fob = 0;
    for(j=0;j<List_Nbr(af.ListOf_Step_Face_Outer_Bound);j++){
      List_Read(af.ListOf_Step_Face_Outer_Bound,j,&d);
      obj = (int)d;
      if((pfab = Get_Face_Outer_Bound(obj)) &&
         (!j || fob)){
        if(pfab->outer)fob = 1;
        if((pel = Get_Edge_Loop(pfab->Step_Edge_Loop))){
          for(k=0;k<List_Nbr(pel->ListOf_Step_Oriented_Edge);k++){
            List_Read(pel->ListOf_Step_Oriented_Edge,k,&d);
            obj = (int)d;
            if((poe = Get_Oriented_Edge(obj))){
              l = (poe->dir)?poe->Step_Edge_Curve:-poe->Step_Edge_Curve;
              List_Add(ListInt,&l);
            }
            else err = 1;
          }
        }
        else err = 1;
        if(!err){
          Cdbz101(pfab->Num,MSH_SEGM_LOOP,0,0,0,0,0,NULL,NULL,ListInt);
          List_Add(ListIntBis,& pfab->Num);
        }
        List_Reset(ListInt);
      }
      else err = 0;
    }
    if(!err && (ps = Get_Surface(af.Step_Surface))){
      if(ps->Typ == STEP_PLAN){
        Cdbz101(af.Num,MSH_SURF_PLAN,0,0,0,0,0,NULL,NULL,ListIntBis);
      }
      else if(ps->Typ == STEP_CYLD || ps->Typ == STEP_CONE
              /*|| ps->Typ == STEP_TORD || ps->Typ == STEP_CONE*/){
        axs =  Get_Axis2_Placement3D(ps->Surface.Quadric.Step_Axis2_Placement3D);
        pcp =  Get_Cartesian_Point(axs->Step_Cartesian_Point);
        d1 =  Get_Direction(axs->Step_Direction1);
        d2 =  Get_Direction(axs->Step_Direction2);
        n[0] = d1->Pos.X;n[1] = d1->Pos.Y;n[2] = d1->Pos.Z;
        t[0] = d2->Pos.X;t[1] = d2->Pos.Y;t[2] = d2->Pos.Z;
        p[0] = pcp->Pos.X;p[1] = pcp->Pos.Y;p[2] = pcp->Pos.Z;
        switch(ps->Typ){
        case STEP_CYLD:
          typ = MSH_SURF_CYLNDR;
          break;
        case STEP_TORD:
          typ = MSH_SURF_TORUS;
          break;
        case STEP_CONE:
          typ = MSH_SURF_CONE;
          break;
        }
        AddQuadricSurfaceInDataBase (typ,
                                     af.Num,
                                     n,t,p,
                                     ps->Surface.Quadric.Radius1,
                                     ps->Surface.Quadric.Radius2,
                                     ListIntBis);

        //Cdbz101(af.Num,MSH_SURF_REGL,0,0,0,0,0,NULL,NULL,ListIntBis);
      }

      else if(ps->Typ == STEP_BSPL){
        Cdbz101(af.Num,MSH_SURF_TRIMMED,0,0,0,0,af.Step_Surface,NULL,NULL,ListIntBis);
      }
    }
    List_Reset(ListIntBis);
  }
    
  // resolving closed shells (sheila)
  for(i=0;i<List_Nbr(BREP->AllClosed_Shells);i++){
    List_Reset(ListInt);
    List_Read(BREP->AllClosed_Shells,i,&cs);
    for(j=0;j<List_Nbr(cs.ListOf_Step_Advanced_Face);j++){
      List_Read(cs.ListOf_Step_Advanced_Face,j,&d);
      obj = (int)d;
      if((paf = Get_Advanced_Face(obj))){
        List_Add(ListInt,&paf->Num);
      }
    }
    Cdbz101(cs.Num+1000000,MSH_SURF_LOOP,0,0,0,0,0,NULL,NULL,ListInt);
    List_Reset(ListInt);
    j = cs.Num+1000000;
    List_Add(ListInt,&j);
    Cdbz101(cs.Num,MSH_VOLUME,0,0,0,0,0,NULL,NULL,ListInt);
  }
}


