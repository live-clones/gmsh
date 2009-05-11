// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GEdgeLoop.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "Numeric.h"
#include "VertexArray.h"
#include "Context.h"

#if defined(HAVE_OCC)
#include "Geom_CylindricalSurface.hxx"
#include "Geom_ConicalSurface.hxx"
#include "Geom_BSplineSurface.hxx"
#include "Geom_SphericalSurface.hxx"
#include "Geom_ToroidalSurface.hxx"
#include "Geom_SurfaceOfRevolution.hxx"
#include "Geom_BezierSurface.hxx"
#include "Geom_Plane.hxx"
#include "gp_Pln.hxx"
#include "BRepMesh_FastDiscret.hxx"

OCCFace::OCCFace(GModel *m, TopoDS_Face _s, int num, TopTools_IndexedMapOfShape &emap)
  : GFace(m, num), s(_s)
{
  TopExp_Explorer exp2, exp3;
  for(exp2.Init(s, TopAbs_WIRE); exp2.More(); exp2.Next()){
    TopoDS_Wire wire = TopoDS::Wire(exp2.Current());
    Msg::Debug("OCC Face %d - New Wire", num);
    std::list<GEdge*> l_wire;
    for(exp3.Init(wire, TopAbs_EDGE); exp3.More(); exp3.Next()){          
      TopoDS_Edge edge = TopoDS::Edge(exp3.Current());
      int index = emap.FindIndex(edge);
      GEdge *e = m->getEdgeByTag(index);
      if(!e){
        Msg::Error("Unknown edge %d in face %d", index, num);
      }
      else{
        l_wire.push_back(e);
        Msg::Debug("Edge %d ori %d", e->tag(), edge.Orientation());
        e->addFace(this);
        if(!e->is3D()){
          OCCEdge *occe = (OCCEdge*)e;
          occe->setTrimmed(this);
        }
      }
    }      
    
    GEdgeLoop el(l_wire);
    for(GEdgeLoop::citer it = el.begin(); it != el.end(); ++it){
      l_edges.push_back(it->ge);
      l_dirs.push_back(it->_sign);
      if (el.count() == 2){
        it->ge->meshAttributes.minimumMeshSegments = 
          std::max(it->ge->meshAttributes.minimumMeshSegments,2);
      }
      if (el.count() == 1){
        it->ge->meshAttributes.minimumMeshSegments = 
          std::max(it->ge->meshAttributes.minimumMeshSegments,3);
      }
    }
    edgeLoops.push_back(el);
  }

  BRepAdaptor_Surface surface(s);
  _periodic[0] = surface.IsUPeriodic();
  _periodic[1] = surface.IsVPeriodic();

  ShapeAnalysis::GetFaceUVBounds(_s, umin, umax, vmin, vmax);
  Msg::Debug("OCC Face %d with %d edges bounds (%g,%g)(%g,%g)", 
             num, l_edges.size(), umin, umax, vmin, vmax);
  // we do that for the projections to converge on the borders of the
  // surface
  const double du = umax - umin;
  const double dv = vmax - vmin;
  umin -= fabs(du) / 100.0;
  vmin -= fabs(dv) / 100.0;
  umax += fabs(du) / 100.0;
  vmax += fabs(dv) / 100.0;
  occface = BRep_Tool::Surface(s);
  if(!CTX::instance()->batch) buildSTLTriangulation();
}

Range<double> OCCFace::parBounds(int i) const
{  
  double umin2, umax2, vmin2, vmax2;

  ShapeAnalysis::GetFaceUVBounds(s, umin2, umax2, vmin2, vmax2);
  if(i == 0)
    return Range<double>(umin2, umax2);
  return Range<double>(vmin2, vmax2);
}

SVector3 OCCFace::normal(const SPoint2 &param) const
{
  gp_Pnt pnt;
  gp_Vec du, dv;

  occface->D1(param.x(), param.y(), pnt, du, dv);

  SVector3 t1(du.X(), du.Y(), du.Z());
  SVector3 t2(dv.X(), dv.Y(), dv.Z());
  SVector3 n(crossprod(t1, t2));
  n.normalize();
  if (s.Orientation() == TopAbs_REVERSED) return n * (-1.);  
  return n;  
}

Pair<SVector3,SVector3> OCCFace::firstDer(const SPoint2 &param) const
{
  gp_Pnt pnt;
  gp_Vec du, dv;
  occface->D1(param.x(), param.y(), pnt, du, dv);

  return Pair<SVector3,SVector3>(SVector3(du.X(), du.Y(), du.Z()),
                                 SVector3(dv.X(), dv.Y(), dv.Z()));
}

void OCCFace::secondDer(const SPoint2 &param,
                        SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const
{
  gp_Pnt pnt;
  gp_Vec du, dv, duu, dvv, duv;
  occface->D2(param.x(), param.y(), pnt, du, dv, duu, dvv, duv);

  *dudu = SVector3(duu.X(), duu.Y(), duu.Z());
  *dvdv = SVector3(dvv.X(), dvv.Y(), dvv.Z());
  *dudv = SVector3(duv.X(), duv.Y(), duv.Z());
}

GPoint OCCFace::point(double par1, double par2) const
{
  double pp[2] = {par1, par2};
  gp_Pnt val = occface->Value(par1, par2);
  return GPoint(val.X(), val.Y(), val.Z(), this, pp);
}

GPoint OCCFace::closestPoint(const SPoint3 & qp, const double initialGuess[2]) const
{
  gp_Pnt pnt(qp.x(), qp.y(), qp.z());
  GeomAPI_ProjectPointOnSurf proj(pnt, occface, umin, umax, vmin, vmax);
  
  if(!proj.NbPoints()){
    Msg::Error("OCC Project Point on Surface FAIL");
    return GPoint(0, 0);
  }
  
  double pp[2] = {initialGuess[0],initialGuess[1]};
  proj.LowerDistanceParameters(pp[0], pp[1]);

  //  Msg::Info("projection lower distance parameters %g %g",pp[0],pp[1]);

  if((pp[0] < umin || umax < pp[0]) || (pp[1]<vmin || vmax<pp[1])){
    Msg::Error("Point projection is out of face bounds");
    return GPoint(0, 0);
  }

  pnt = proj.NearestPoint();
  return GPoint(pnt.X(), pnt.Y(), pnt.Z(), this, pp);
}

SPoint2 OCCFace::parFromPoint(const SPoint3 &qp) const
{
  gp_Pnt pnt(qp.x(), qp.y(), qp.z());
  GeomAPI_ProjectPointOnSurf proj(pnt, occface, umin, umax, vmin, vmax);
  if(!proj.NbPoints()){
    Msg::Error("OCC Project Point on Surface FAIL");
    return GFace::parFromPoint(qp);
  }   
  double U, V;
  proj.LowerDistanceParameters(U, V);
  return SPoint2(U, V);
}

GEntity::GeomType OCCFace::geomType() const
{
  if (occface->DynamicType() == STANDARD_TYPE(Geom_Plane))
    return Plane;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_ToroidalSurface))
    return Torus;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_BezierSurface))
    return BezierSurface;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_CylindricalSurface))
    return Cylinder;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_ConicalSurface))
    return Cone;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_SurfaceOfRevolution))
    return SurfaceOfRevolution;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_SphericalSurface))
    return Sphere;
  else if (occface->DynamicType() == STANDARD_TYPE(Geom_BSplineSurface))
    return BSplineSurface;
  return Unknown;
}

double OCCFace::curvatureMax(const SPoint2 &param) const
{
  const double eps = 1.e-12;
  BRepAdaptor_Surface sf(s, Standard_True);
  BRepLProp_SLProps prop(sf, 2, eps);
  prop.SetParameters (param.x(),param.y());

  if (!prop.IsCurvatureDefined()){
    return eps;
  }
  return std::max(fabs(prop.MinCurvature()), fabs(prop.MaxCurvature()));
}

double OCCFace::curvatures(const SPoint2 &param,
                           SVector3 *dirMax,
                           SVector3 *dirMin,
                           double *curvMax,
                           double *curvMin) const
{
  const double eps = 1.e-12;
  BRepAdaptor_Surface sf(s, Standard_True);
  BRepLProp_SLProps prop(sf, 2, eps);
  prop.SetParameters (param.x(),param.y());

  if (!prop.IsCurvatureDefined()){
    return -1.;
  }

  *curvMax = std::max(fabs(prop.MinCurvature()), fabs(prop.MaxCurvature()));
  *curvMin = std::min(fabs(prop.MinCurvature()), fabs(prop.MaxCurvature()));

  gp_Dir dMax = gp_Dir();
  gp_Dir dMin = gp_Dir();
  prop.CurvatureDirections(dMax,dMin);
  (*dirMax)[0] = dMax.X();
  (*dirMax)[1] = dMax.Y();
  (*dirMax)[2] = dMax.Z();
  (*dirMin)[0] = dMin.X();
  (*dirMin)[1] = dMin.Y();
  (*dirMin)[2] = dMin.Z();

  return *curvMax;
}

bool OCCFace::containsPoint(const SPoint3 &pt) const
{ 
  if(geomType() == Plane){
    gp_Pln pl = Handle(Geom_Plane)::DownCast(occface)->Pln();
    double n[3], c;
    pl.Coefficients(n[0], n[1], n[2], c);
    norme(n);
    double angle = 0.;
    double v[3] = {pt.x(), pt.y(), pt.z()};

    std::list<int>::const_iterator ito = l_dirs.begin();
    for(std::list<GEdge*>::const_iterator it = l_edges.begin(); it != l_edges.end(); it++){
      GEdge *c = *it;
      int ori = 1;
      if(ito != l_dirs.end()){
        ori = *ito;
        ++ito;
      }
      int N = 10;
      Range<double> range = c->parBounds(0);
      for(int j = 0; j < N ; j++) {
        double u1 = (double)j / (double)N;
        double u2 = (double)(j + 1) / (double)N;
        if(ori < 0){
          u1 = 1. - u1;
          u2 = 1. - u2;
        }
        GPoint pp1 = c->point(range.low() + u1 * (range.high() - range.low()));
        GPoint pp2 = c->point(range.low() + u2 * (range.high() - range.low()));
        double v1[3] = {pp1.x(), pp1.y(), pp1.z()};
        double v2[3] = {pp2.x(), pp2.y(), pp2.z()};
        angle += angle_plan(v, v1, v2, n);
      }
    }
    // we're inside if angle equals 2 * pi
    if(fabs(angle) > 2 * M_PI - 0.5 && fabs(angle) < 2 * M_PI + 0.5) 
      return true;
    return false;
  }
  else
    Msg::Error("Not Done Yet ...");
  return false;
}

surface_params OCCFace::getSurfaceParams() const 
{
  surface_params p;
  switch(geomType()){
  case GEntity::Cylinder:
    p.radius = Handle(Geom_CylindricalSurface)::DownCast(occface)->Radius();
    break;
  default:
    break;
  }
  return p;
}

bool OCCFace::buildSTLTriangulation()
{
  if(va_geom_triangles){
    delete va_geom_triangles;
    va_geom_triangles = 0;
  }
  
  TopLoc_Location loc;
  int p1, p2, p3;
  Bnd_Box aBox;
  Standard_Boolean bWithShare = Standard_False;
  Standard_Real aDiscret, aXmin, aYmin, aZmin, aXmax, aYmax, aZmax;
  Standard_Real dX, dY, dZ, dMax, aCoeff;     
  BRepBndLib::Add(s, aBox);
  aBox.Get(aXmin, aYmin, aZmin, aXmax, aYmax, aZmax);
   
  dX = aXmax-aXmin;
  dY = aYmax-aYmin;
  dZ = aZmax-aZmin;
  dMax = dX;
  if(dY > dMax) {
    dMax = dY;
  }
  if(dZ > dMax) {
    dMax = dZ;
  }

  aCoeff = 0.01;
  aDiscret = aCoeff * dMax;
  BRepMesh_FastDiscret aMesher(aDiscret, 0.5, aBox, bWithShare, Standard_True,
                               Standard_False, Standard_True);
  aMesher.Add(s);
  Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(s, loc);
  if (triangulation.IsNull()){
    Msg::Warning("OCC STL triangulation failed");
    return false;
  }
  
  int ntriangles = triangulation->NbTriangles();
  if(!triangulation->HasUVNodes()) return false;

  va_geom_triangles = new VertexArray(3, ntriangles);
  
  unsigned int c = CTX::instance()->color.geom.surface;
  unsigned int col[4] = {c, c, c, c};
  for (int j = 1; j <= ntriangles; j++){
    Poly_Triangle triangle = (triangulation->Triangles())(j);
    triangle.Get(p1, p2, p3);
    gp_Pnt2d x1 = (triangulation->UVNodes())(p1);
    gp_Pnt2d x2 = (triangulation->UVNodes())(p2);
    gp_Pnt2d x3 = (triangulation->UVNodes())(p3);
    GPoint gp1 = point(x1.X(), x1.Y());
    GPoint gp2 = point(x2.X(), x2.Y());
    GPoint gp3 = point(x3.X(), x3.Y());
    SVector3 n[3];
    n[0] = normal(SPoint2(x1.X(), x1.Y()));
    n[1] = normal(SPoint2(x2.X(), x2.Y()));
    n[2] = normal(SPoint2(x3.X(), x3.Y()));
    double x[3] = {gp1.x(), gp2.x(), gp3.x()};
    double y[3] = {gp1.y(), gp2.y(), gp3.y()};
    double z[3] = {gp1.z(), gp2.z(), gp3.z()};
    va_geom_triangles->add(x, y, z, n, col);
  }  
  va_geom_triangles->finalize();
  return true;
}

#endif
