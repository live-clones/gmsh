// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "GFace.h"
#include "gmshEdge.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Message.h"
#include "Context.h"

extern Context_T CTX;

gmshEdge::gmshEdge(GModel *m, Curve *edge, GVertex *v1, GVertex *v2)
  : GEdge(m, edge->Num, v1, v2), c(edge)
{
  resetMeshAttributes();
}

void gmshEdge::resetMeshAttributes()
{
  meshAttributes.Method = c->Method;
  meshAttributes.nbPointsTransfinite = c->nbPointsTransfinite;
  meshAttributes.typeTransfinite = c->typeTransfinite;
  meshAttributes.coeffTransfinite = c->coeffTransfinite;
  meshAttributes.extrude = c->Extrude;
}

Range<double> gmshEdge::parBounds(int i) const
{ 
  return Range<double>(c->ubeg, c->uend);
}

GPoint gmshEdge::point(double par) const
{
  Vertex a = InterpolateCurve(c, par, 0);
  return GPoint(a.Pos.X, a.Pos.Y, a.Pos.Z, this, par);
}

GPoint gmshEdge::closestPoint(const SPoint3 &qp) const
{
  Vertex v;
  Vertex a;
  Vertex der;
  v.Pos.X = qp.x();
  v.Pos.Y = qp.y();
  v.Pos.Z = qp.z();
  ProjectPointOnCurve(c, &v, &a, &der);
  return GPoint(a.Pos.X, a.Pos.Y, a.Pos.Z, this, a.u);
}

SVector3 gmshEdge::firstDer(double par) const
{
  Vertex a = InterpolateCurve(c, par, 1);
  return SVector3(a.Pos.X, a.Pos.Y, a.Pos.Z);
}

double gmshEdge::parFromPoint(const SPoint3 &pt) const
{
  Vertex v;
  Vertex a;
  Vertex der;
  v.Pos.X = pt.x();
  v.Pos.Y = pt.y();
  v.Pos.Z = pt.z();
  ProjectPointOnCurve(c, &v, &a, &der);
  return a.u;
}

GEntity::GeomType gmshEdge::geomType() const
{
  switch (c->Typ){
  case MSH_SEGM_LINE : return Line;
  case MSH_SEGM_PARAMETRIC : return ParametricCurve;
  case MSH_SEGM_CIRC :  
  case MSH_SEGM_CIRC_INV : return Circle;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV: return Ellipse;
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER: 
  case MSH_SEGM_NURBS:
  case MSH_SEGM_SPLN: return Nurb; 
  case MSH_SEGM_BND_LAYER: return BoundaryLayerCurve; 
  case MSH_SEGM_DISCRETE: return DiscreteCurve; 
  default : return Unknown;
  }
}

int gmshEdge::minimumMeshSegments () const
{
  int np;
  if(geomType() == Line)
    np = GEdge::minimumMeshSegments();
  else if(geomType() == Circle || geomType() == Ellipse)
    np = (int)(fabs(c->Circle.t1 - c->Circle.t2) *
                 (double)CTX.mesh.min_circ_points / M_PI) - 1;
  else
    np = CTX.mesh.min_curv_points - 1;
  return std::max(np, meshAttributes.minimumMeshSegments);
}

int gmshEdge::minimumDrawSegments () const
{
  int n = List_Nbr(c->Control_Points) - 1;
  if(!n) n = GEdge::minimumDrawSegments();

  if(geomType() == Line && !c->geometry)
    return n;
  else if(geomType() == Circle || geomType() == Ellipse)
    return CTX.geom.circle_points;
  else
    return 10 * n;
}

SPoint2 gmshEdge::reparamOnFace(GFace *face, double epar,int dir) const
{
  Surface *s = (Surface*) face->getNativePtr();

  bool periodic = (c->end == c->beg);
  if(s->geometry){
    switch (c->Typ) {
    case MSH_SEGM_LINE:
      {
        Vertex *v[3];
        List_Read(c->Control_Points, 0, &v[1]);
        List_Read(c->Control_Points, 1, &v[2]);
        SPoint2 p = v[1]->pntOnGeometry + 
          (v[2]->pntOnGeometry - v[1]->pntOnGeometry) * epar;
        return p;
      }
    case MSH_SEGM_BSPLN:
    case MSH_SEGM_BEZIER:
      {
        int NbControlPoints = List_Nbr(c->Control_Points);
        int NbCurves = NbControlPoints + (periodic ? -1 : 1);
        int iCurve = (int)floor(epar * (double)NbCurves);
        if(iCurve >= NbCurves)
          iCurve = NbCurves - 1;
        else if (iCurve < 0) // ? does it happen ?
          iCurve = 0;
        double t1 = (double)(iCurve) / (double)(NbCurves);
        double t2 = (double)(iCurve+1) / (double)(NbCurves);
        double t = (epar - t1) / (t2 - t1);
        Vertex *v[4];
        for(int j = 0; j < 4; j ++ ){
          int k = iCurve - (periodic ? 1 : 2) + j;
          if(k < 0) 
            k = periodic ? k + NbControlPoints - 1 : 0;
          if(k >= NbControlPoints) 
            k = periodic ? k - NbControlPoints + 1: NbControlPoints - 1;
          List_Read(c->Control_Points, k, &v[j]);
        }
        return InterpolateCubicSpline(v, t, c->mat, t1, t2, c->geometry);
      }
    case MSH_SEGM_SPLN :
      {
        Vertex temp1, temp2;
        int N = List_Nbr(c->Control_Points);
        int i = (int)((double)(N - 1) * epar);
        if(i < 0)
          i = 0;
        if(i >= N - 1)
          i = N - 2;
        double t1 = (double)(i) / (double)(N - 1);
        double t2 = (double)(i + 1) / (double)(N - 1);
        double t = (epar - t1) / (t2 - t1);
        Vertex *v[4];
        List_Read(c->Control_Points, i, &v[1]);
        List_Read(c->Control_Points, i + 1, &v[2]);
        if(!i) {
          if(c->beg == c->end){
            List_Read(c->Control_Points,N-2,&v[0]);
          }
          else{
            v[0] = &temp1;
            v[0]->pntOnGeometry = v[1]->pntOnGeometry * 2. - v[2]->pntOnGeometry;
          }
        }
        else{
          List_Read(c->Control_Points, i - 1, &v[0]);
        }
        if(i == N - 2) {
          if(c->beg == c->end){
            List_Read(c->Control_Points,1,&v[3]);
          }
          else{
            v[3] = &temp2;
            v[3]->pntOnGeometry = v[2]->pntOnGeometry * 2. - v[1]->pntOnGeometry;
          }
        }
        else{
          List_Read(c->Control_Points, i + 2, &v[3]);
        }
        return InterpolateCubicSpline(v, t, c->mat, t1, t2, c->geometry);
      }
    default:
      Msg::Error("Unknown edge type in reparamOnFace");
      return SPoint2();
    }
  }
  

  if(s->Typ ==  MSH_SURF_REGL){
    Curve *C[4];
    for(int i = 0; i < 4; i++)
      List_Read(s->Generatrices, i, &C[i]);

    double U, V;
    if (C[0]->Num == c->Num) {
      U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[0]->Num == -c->Num) {
      U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[1]->Num == c->Num) {
      V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[1]->Num == -c->Num) {
      V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[2]->Num == c->Num) {
      U =  1 - (epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else if (C[2]->Num == -c->Num) {
      U =  1 - ( C[2]->uend -epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else if (C[3]->Num == c->Num) {
      V = 1-(epar - C[3]->ubeg) / (C[3]->uend - C[3]->ubeg) ;
      U = 0;
    }
    else if (C[3]->Num == -c->Num) {
      V = 1-(C[3]->uend - epar - C[3]->ubeg) / (C[3]->uend - C[3]->ubeg) ;
      U = 0;
    }
    else{
      Msg::Info("Reparameterizing edge %d on face %d", c->Num, s->Num);
      return GEdge::reparamOnFace(face, epar, dir);
    }
    return SPoint2(U, V);
  }
  else if (s->Typ ==  MSH_SURF_TRIC){
    Curve *C[3];
    for(int i = 0; i < 3; i++)
      List_Read(s->Generatrices, i, &C[i]);

    double U, V;    
    if (C[0]->Num == c->Num) {
      U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[0]->Num == -c->Num) {
      U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[1]->Num == c->Num) {
      V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[1]->Num == -c->Num) {
      V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[2]->Num == c->Num) {
      U = 1-(epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else if (C[2]->Num == -c->Num) {
      U = 1-(C[2]->uend - epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else{
      Msg::Info("Reparameterizing edge %d on face %d", c->Num, s->Num);
      return GEdge::reparamOnFace(face, epar, dir);
    }
    return SPoint2(U, V);
  }
  else
    return GEdge::reparamOnFace(face, epar, dir);
}
