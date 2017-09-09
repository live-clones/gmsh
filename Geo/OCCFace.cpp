// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_OCC.h"
#include "GEdgeLoop.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "Numeric.h"
#include "Context.h"
#include "robustPredicates.h"

#if defined(HAVE_OCC)

#include <BOPTools_AlgoTools.hxx>
#include <BOPTools_AlgoTools2D.hxx>
#include <BRepBndLib.hxx>
#include <BRepLProp_SLProps.hxx>
#include <BRep_Builder.hxx>
#include <Bnd_Box.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_ConicalSurface.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_Plane.hxx>
#include <Geom_SphericalSurface.hxx>
#include <Geom_SurfaceOfRevolution.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <IntTools_Context.hxx>
#include <ShapeAnalysis.hxx>
#include <Standard_Version.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <gp_Pln.hxx>
#include <gp_Sphere.hxx>

OCCFace::OCCFace(GModel *m, TopoDS_Face _s, int num)
: GFace(m, num), s(_s),_radius(-1)
{
  setup();
  if(model()->getOCCInternals())
    model()->getOCCInternals()->bind(s, num);
}

OCCFace::~OCCFace()
{
  if(model()->getOCCInternals()){
    model()->getOCCInternals()->unbind(s, tag());
    model()->getOCCInternals()->unbind(_replaced, tag());
  }
}

void OCCFace::setup()
{
  edgeLoops.clear();
  l_edges.clear();
  l_dirs.clear();
  TopExp_Explorer exp2, exp3;
  for(exp2.Init(s.Oriented(TopAbs_FORWARD), TopAbs_WIRE); exp2.More(); exp2.Next()){
    TopoDS_Wire wire = TopoDS::Wire(exp2.Current());
    Msg::Debug("OCC Face %d - New Wire", tag());
    std::list<GEdge*> l_wire;
    for(exp3.Init(wire, TopAbs_EDGE); exp3.More(); exp3.Next()){
      TopoDS_Edge edge = TopoDS::Edge(exp3.Current());
      GEdge *e = 0;
      if(model()->getOCCInternals())
        e = model()->getOCCInternals()->getEdgeForOCCShape(model(), edge);
      if(!e){
	Msg::Error("Unknown edge in face %d", tag());
      }
      else if(edge.Orientation() == TopAbs_INTERNAL){
        Msg::Debug("Adding embedded edge %d in face %d", e->tag(), tag());
        embedded_edges.push_back(e);
        OCCEdge *occe = (OCCEdge*)e;
        occe->setTrimmed(this);
      }
      else{
        l_wire.push_back(e);
        Msg::Debug("Edge %d (%d --> %d) ori %d", e->tag(),
                   e->getBeginVertex()->tag(), e->getEndVertex()->tag(),
                   edge.Orientation());
        e->addFace(this);
        if(!e->is3D()){
          OCCEdge *occe = (OCCEdge*)e;
          occe->setTrimmed(this);
        }
      }
    }

    GEdgeLoop el(l_wire);
    // printf("l_wire of size %d %d\n",l_wire.size(),el.count());
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
  if (_periodic[0])  _period[0]=surface.UPeriod();
  if (_periodic[1])  _period[1]=surface.VPeriod();

  ShapeAnalysis::GetFaceUVBounds(s, umin, umax, vmin, vmax);
  Msg::Debug("OCC Face %d with %d parameter bounds (%g,%g)(%g,%g)",
             tag(), l_edges.size(), umin, umax, vmin, vmax);
  // we do that for the projections to converge on the borders of the
  // surface
  const double du = umax - umin;
  const double dv = vmax - vmin;
  umin -= fabs(du) / 100.0;
  vmin -= fabs(dv) / 100.0;
  umax += fabs(du) / 100.0;
  vmax += fabs(dv) / 100.0;
  occface = BRep_Tool::Surface(s);

  for(exp2.Init(s, TopAbs_VERTEX); exp2.More(); exp2.Next()){
    TopoDS_Vertex vertex = TopoDS::Vertex(exp2.Current());
    GVertex *v = 0;
    if(model()->getOCCInternals())
      v = model()->getOCCInternals()->getVertexForOCCShape(model(), vertex);
    if(!v){
      Msg::Error("Unknown vertex in face %d", tag());
    }
    else if(vertex.Orientation() == TopAbs_INTERNAL){
      Msg::Debug("Adding embedded vertex %d in face %d", v->tag(), tag());
      embedded_vertices.push_back(v);
    }
  }

  if (geomType()==GEntity::Sphere){
    BRepAdaptor_Surface surface(s);
    gp_Sphere sphere = surface.Sphere();
    _radius = sphere.Radius();
    gp_Pnt loc = sphere.Location();
    _center = SPoint3(loc.X(),loc.Y(),loc.Z());
  }
}

SBoundingBox3d OCCFace::bounds() const
{
  Bnd_Box b;
  try{
    BRepBndLib::Add(s, b);
  }
  catch(Standard_Failure &err){
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return SBoundingBox3d();
  }
  double xmin, ymin, zmin, xmax, ymax, zmax;
  b.Get(xmin, ymin, zmin, xmax, ymax, zmax);
  SBoundingBox3d bbox(xmin, ymin, zmin, xmax, ymax, zmax);
  return bbox;
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

#if 1
  gp_Pnt val = occface->Value(par1, par2);
  return GPoint(val.X(), val.Y(), val.Z(), this, pp);
#else // this is horribly slow!
  double umin2, umax2, vmin2, vmax2;

  ShapeAnalysis::GetFaceUVBounds(s, umin2, umax2, vmin2, vmax2);

  double du = umax2 - umin2;
  double dv = vmax2 - vmin2;

  if (par1 > (umax2+.1*du) || par1 < (umin2-.1*du) ||
      par2 > (vmax2+.1*dv) || par2 < (vmin2-.1*dv)){
    GPoint p(0,0,0, this, pp);
    p.setNoSuccess();
    return p;
  }

  try{
    gp_Pnt val;
    val = occface->Value(par1, par2);
    return GPoint(val.X(), val.Y(), val.Z(), this, pp);
  }
  catch(Standard_OutOfRange){
    GPoint p(0,0,0, this, pp);
    p.setNoSuccess();
    return p;
  }
#endif
}

GPoint OCCFace::closestPoint(const SPoint3 &qp, const double initialGuess[2]) const
{
  gp_Pnt pnt(qp.x(), qp.y(), qp.z());
  GeomAPI_ProjectPointOnSurf proj(pnt, occface, umin, umax, vmin, vmax);

  if(!proj.NbPoints()){
    Msg::Warning("OCC Project Point on Surface FAIL");
    GPoint gp(0, 0);
    gp.setNoSuccess();
    return gp;
  }

  double pp[2] = {initialGuess[0],initialGuess[1]};
  proj.LowerDistanceParameters(pp[0], pp[1]);

  // Msg::Info("projection lower distance parameters %g %g",pp[0],pp[1]);

  if((pp[0] < umin || umax < pp[0]) || (pp[1]<vmin || vmax<pp[1])){
    Msg::Warning("Point projection is out of face bounds");
    GPoint gp(0, 0);
    gp.setNoSuccess();
    return gp;
  }

  pnt = proj.NearestPoint();
  return GPoint(pnt.X(), pnt.Y(), pnt.Z(), this, pp);
}

SPoint2 OCCFace::parFromPoint(const SPoint3 &qp, bool onSurface) const
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
  prop.SetParameters (param.x(), param.y());

  if(!prop.IsCurvatureDefined()){
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

  *curvMax = prop.MaxCurvature();
  *curvMin = prop.MinCurvature();

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

bool OCCFace::buildSTLTriangulation(bool force)
{
  if(stl_triangles.size()){
    if(force){
      stl_vertices.clear();
      stl_triangles.clear();
    }
    else
      return true;
  }
  if(!model()->getOCCInternals()->makeFaceSTL(s, stl_vertices, stl_triangles)){
    Msg::Warning("OpenCASCADE triangulation of surface %d failed", tag());
    // add a dummy triangle so that we won't try again
    stl_vertices.push_back(SPoint2(0., 0.));
    stl_triangles.push_back(0);
    stl_triangles.push_back(0);
    stl_triangles.push_back(0);
    return false;
  }

  bool reverse = false;
  for(unsigned int i = 0; i < stl_triangles.size(); i += 3){
    if(i == 0){
      SPoint2 gp1 = stl_vertices[stl_triangles[i]];
      SPoint2 gp2 = stl_vertices[stl_triangles[i + 1]];
      SPoint2 gp3 = stl_vertices[stl_triangles[i + 2]];
      SPoint2 b = gp1 + gp2 + gp2;
      b *= 1. / 3.;
      SVector3 nf = normal(b);
      GPoint sp1 = point(gp1.x(), gp1.y());
      GPoint sp2 = point(gp2.x(), gp2.y());
      GPoint sp3 = point(gp3.x(), gp3.y());
      double n[3];
      normal3points(sp1.x(), sp1.y(), sp1.z(),
                    sp2.x(), sp2.y(), sp2.z(),
                    sp3.x(), sp3.y(), sp3.z(), n);
      SVector3 ne(n[0], n[1], n[2]);
      if(dot(ne, nf) < 0){
        Msg::Debug("Reversing orientation of STL mesh in face %d", tag());
        reverse = true;
      }
    }
    if(reverse){
      int tmp = stl_triangles[i + 1];
      stl_triangles[i + 1] = stl_triangles[i + 2];
      stl_triangles[i + 2] = tmp;
    }
  }
  return true;
}

bool OCCFace::isSphere (double &radius, SPoint3 &center) const
{
  switch(geomType()){
  case GEntity::Sphere:
    {
      radius = _radius;
      center = _center;
    }
    return true;
  default:
    return false;
  }
}

bool OCCFace::containsParam(const SPoint2 &pt)
{
  //  return GFace::containsParam(pt);
  if(!buildSTLTriangulation(false)){
    Msg::Warning ("Inacurate computation in OCCFace::containsParam");
    return GFace::containsParam(pt);
  }
  //  FILE *F = fopen("HOP.pos","w");
  //  fprintf(F,"View \" \"{\n");
  ///  fprintf(F,"SP(%g,%g,%g){2,2,2};\n",pt.x(),pt.y(),1.0);
  SPoint2 mine = pt;

  //  bool ok = false;

  for(unsigned int i = 0; i < stl_triangles.size(); i += 3){
    SPoint2 gp1 = stl_vertices[stl_triangles[i]];
    SPoint2 gp2 = stl_vertices[stl_triangles[i + 1]];
    SPoint2 gp3 = stl_vertices[stl_triangles[i + 2]];

    double s1 = robustPredicates::orient2d (gp1,gp2,mine);
    double s2 = robustPredicates::orient2d (gp2,gp3,mine);
    double s3 = robustPredicates::orient2d (gp3,gp1,mine);
    /*
    fprintf(F,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){1,1,1};\n",
	    gp1.x(),gp1.y(),0.0,
	    gp2.x(),gp2.y(),0.0,
	    gp3.x(),gp3.y(),0.0);

    printf("%g %g %g\n",s1,s2,s3);
    */
    if (s1*s2 >= 0 && s1*s3 >=0){
      //ok = true;
      return true;
    }
  }
  //  printf("gasp\n");
  //  fprintf(F,"};\n");
  //  fclose(F);
  //  return ok;
  return false;
}

#endif
