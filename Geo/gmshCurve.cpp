#include "gmshCurve.h"
#include "Geo.h"
#include "GeoInterpolation.h"
SVector3 gmshCurve::curvature (double t) const { 

  SVector3 dx  = firstDer(t);
  SVector3 dxx = secondDer(t);
  
  double normdx = dx.norm();
  double oneovernormdx = 1./normdx;
  double oneovernormdx3 = oneovernormdx*oneovernormdx*oneovernormdx;

  SVector3 c = (dxx * normdx - dx * (dot(dx,dxx) * oneovernormdx))*oneovernormdx3;
  return c;
}


gmshCubicSpline::gmshCubicSpline (std::vector<SPoint3> & data) 
{
  c = Create_Curve ( 0 , MSH_SEGM_BSPLN , 3 , 0 , 0 , 0 , 0 , 0., 1.) ;
  
  c->Control_Points = List_Create(data.size(), 1, sizeof(Vertex *));

  for (unsigned int i=0;i<data.size(); i++){
    Vertex *v = new Vertex (data[i].x(),data[i].y(),data[i].z(), 0.0);
    List_Add (c->Control_Points, &v);
  }
}

gmshCubicSpline::gmshCubicSpline (std::vector<SPoint2> & data) 
{
  c = Create_Curve ( 0 , MSH_SEGM_BSPLN , 3 , 0 , 0 , 0 , 0 , 0., 1.) ;
  
  c->Control_Points = List_Create(data.size(), 1, sizeof(Vertex *));

  for (unsigned int i=0;i<data.size(); i++){
    Vertex *v = new Vertex (data[i].x(),data[i].y(),0.0, 0.0);
    List_Add (c->Control_Points, &v);
  }
}

SPoint3 gmshCubicSpline::point (double t) const
{
  Vertex v = InterpolateCurve(c, t, 0);
  return SPoint3 (v.Pos.X,v.Pos.Y,v.Pos.Z);
} 

SVector3 gmshCubicSpline::firstDer (double t) const
{
  Vertex v = InterpolateCurve(c, t, 1);
  return SVector3 (v.Pos.X,v.Pos.Y,v.Pos.Z);
} 

SVector3 gmshCubicSpline::secondDer (double t) const
{
  Vertex v = InterpolateCurve(c, t, 2);
  return SVector3 (v.Pos.X,v.Pos.Y,v.Pos.Z);
} 


gmshCubicSpline::~gmshCubicSpline ()
{
  for (int i=0;i< List_Nbr(c->Control_Points); i++){
    Vertex *v;
    List_Read(c->Control_Points, i, &v);
    delete v;
  }
  List_Delete(c->Control_Points);  
}

