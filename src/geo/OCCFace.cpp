// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_OCC.h"
#include "GEdgeLoop.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "Numeric.h"
#include "Context.h"
#include "robustPredicates.h"

#if defined(HAVE_OCC)

#include <BOPTools_AlgoTools.hxx>
#include <BOPTools_AlgoTools2D.hxx>
#include <BRepBndLib.hxx>
#include <BRepClass_FaceClassifier.hxx>
#include <BRepLProp_SLProps.hxx>
#include <BRepTools.hxx>
#include <BRep_Builder.hxx>
#include <Bnd_Box.hxx>
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
#include <ShapeFix_Wire.hxx>
#include <Standard_Version.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <gp_Pln.hxx>
#include <gp_Sphere.hxx>

OCCFace::OCCFace(GModel *m, TopoDS_Face s, int num)
  : GFace(m, num), _s(s), _sf(s, Standard_True), _radius(-1)
{
  _setup();

  if(CTX::instance()->debugSurface > 0 &&
     tag() == CTX::instance()->debugSurface)
    writeBREP("debugSurface.brep");
}

void OCCFace::_setup()
{
  edgeLoops.clear();
  l_edges.clear();
  l_dirs.clear();

  TopExp_Explorer exp2, exp3;
  for(exp2.Init(_s.Oriented(TopAbs_FORWARD), TopAbs_WIRE); exp2.More();
      exp2.Next()) {
    TopoDS_Wire wire = TopoDS::Wire(exp2.Current());

    // it is crucial that the edges in the wire are ordered and oriented
    // correctly (for non-periodic surfaces GEdgeLoop would correct it; but for
    // periodic surfaces the location of degenerate edges linking 2 sides of the
    // parametric space is crucial) - so always make sure to reorder the edges
    ShapeFix_Wire sfw(wire, _s, CTX::instance()->geom.tolerance);
    sfw.FixReorder();
    wire = sfw.Wire();

    Msg::Debug("OCC surface %d - new wire", tag());
    GEdgeLoop el;

    for(exp3.Init(wire, TopAbs_EDGE); exp3.More(); exp3.Next()) {
      TopoDS_Edge edge = TopoDS::Edge(exp3.Current());
      GEdge *e = nullptr;
      if(model()->getOCCInternals())
        e = model()->getOCCInternals()->getEdgeForOCCShape(model(), edge);
      if(!e) { Msg::Error("Unknown curve in surface %d", tag()); }
      else if(edge.Orientation() == TopAbs_INTERNAL &&
              CTX::instance()->geom.occAutoEmbed) {
        Msg::Debug("Adding embedded curve %d in surface %d", e->tag(), tag());
        embedded_edges.push_back(e);
        /*
        if(e->getBeginVertex()) embedded_vertices.insert(e->getBeginVertex());
        if(e->getEndVertex()) embedded_vertices.insert(e->getEndVertex());
        */
      }
      else {
        int ori = edge.Orientation() ? -1 : 1;
        Msg::Debug("Curve %d (%d --> %d) ori %d", e->tag(),
                   e->getBeginVertex() ? e->getBeginVertex()->tag() : -1,
                   e->getEndVertex() ? e->getEndVertex()->tag() : -1, ori);
        el.add(ori, e);
      }
    }

    if(!el.check()) {
      // should not happen, since ShapeFix_Wire has been called before
      Msg::Warning("Recomputing incorrect OpenCASCADE wire in surface %d", tag());
      std::vector<GEdge*> edges;
      el.getEdges(edges);
      el.recompute(edges);
    }
    if(!el.check()) {
      Msg::Error("Could not fix wire in surface %d", tag());
      el.print();
    }

    for(GEdgeLoop::citer it = el.begin(); it != el.end(); ++it) {
      l_edges.push_back(it->getEdge());
      l_dirs.push_back(it->getSign());
      if(el.count() == 2) {
        it->getEdge()->meshAttributes.minimumMeshSegments =
          std::max(it->getEdge()->meshAttributes.minimumMeshSegments, 2);
      }
      if(el.count() == 1) {
        it->getEdge()->meshAttributes.minimumMeshSegments =
          std::max(it->getEdge()->meshAttributes.minimumMeshSegments, 3);
      }
    }
    edgeLoops.push_back(el);
  }

  for(exp2.Init(_s.Oriented(TopAbs_FORWARD), TopAbs_VERTEX, TopAbs_EDGE);
      exp2.More(); exp2.Next()) {
    TopoDS_Vertex vertex = TopoDS::Vertex(exp2.Current());
    GVertex *v = nullptr;
    if(model()->getOCCInternals())
      v = model()->getOCCInternals()->getVertexForOCCShape(model(), vertex);
    if(!v) { Msg::Error("Unknown point in surface %d", tag()); }
    else if(vertex.Orientation() == TopAbs_INTERNAL &&
            CTX::instance()->geom.occAutoEmbed) {
      Msg::Debug("Adding embedded point %d in surface %d", v->tag(), tag());
      embedded_vertices.insert(v);
    }
  }

  BRepAdaptor_Surface surface(_s);
  _periodic[0] = surface.IsUPeriodic();
  _periodic[1] = surface.IsVPeriodic();
  if(_periodic[0]) _period[0] = surface.UPeriod();
  if(_periodic[1]) _period[1] = surface.VPeriod();

  ShapeAnalysis::GetFaceUVBounds(_s, _umin, _umax, _vmin, _vmax);
  Msg::Debug("OCC surface %d with %d parameter bounds (%g,%g)(%g,%g)", tag(),
             l_edges.size(), _umin, _umax, _vmin, _vmax);

  _occface = BRep_Tool::Surface(_s);

  // init projector, with little tolerance to converge on the borders of the
  // surface
  double umin = _umin;
  double vmin = _vmin;
  double umax = _umax;
  double vmax = _vmax;
  if(!_periodic[0]) {
    const double du = _umax - _umin;
    const double utol = std::max(fabs(du) * 1e-8, 1e-12);
    umin -= utol;
    umax += utol;
  }
  if(!_periodic[1]) {
    const double dv = _vmax - _vmin;
    const double vtol = std::max(fabs(dv) * 1e-8, 1e-12);
    vmin -= vtol;
    vmax += vtol;
  }
  _projector.Init(_occface, umin, umax, vmin, vmax);

  if(OCCFace::geomType() == GEntity::Sphere) {
    BRepAdaptor_Surface surface(_s);
    gp_Sphere sphere = surface.Sphere();
    _radius = sphere.Radius();
    gp_Pnt loc = sphere.Location();
    _center = SPoint3(loc.X(), loc.Y(), loc.Z());
  }

  // Only store references to this new face in edges at the end of the
  // constructor, to avoid accessing it too early (e.g. when drawing an edge)
  for(std::size_t i = 0; i < l_edges.size(); i++) {
    GEdge *e = l_edges[i];
    e->addFace(this);
    OCCEdge *occe = dynamic_cast<OCCEdge *>(e);
    if(occe && !e->is3D()) occe->setTrimmed(this);
  }
  for(std::size_t i = 0; i < embedded_edges.size(); i++) {
    GEdge *e = embedded_edges[i];
    // should not addFace(), as the edge is not on the boundary
    //e->addFace(this);
    OCCEdge *occe = dynamic_cast<OCCEdge *>(e);
    if(occe && !e->is3D()) occe->setTrimmed(this);
  }
}

SBoundingBox3d OCCFace::bounds(bool fast)
{
  if(CTX::instance()->geom.occBoundsUseSTL) {
    buildSTLTriangulation();
    // BRepBndLib can use the STL mesh if available, but unfortunately it
    // enlarges the box with the mesh deflection tolerance and the shape
    // tolerance, which makes it hard to get the expected minimal box in simple
    // cases (e.g. for plane surfaces), and always leads to boxes that are too
    // large; so we simply compute the box from the STL vertices. The downside
    // of this approach is that the bbox might be *smaller* than the actual box
    // for curved shapes, but this is preferable for us as boxes are mostly used
    // to find/identify entities
    if(stl_vertices_xyz.size()) {
      SBoundingBox3d bbox;
      for(std::size_t i = 0; i < stl_vertices_xyz.size(); i++)
        bbox += stl_vertices_xyz[i];
      return bbox;
    }
  }

  Bnd_Box b;
  try {
    BRepBndLib::Add(_s, b);
  } catch(Standard_Failure &err) {
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
  if(i == 0) return Range<double>(_umin, _umax);
  return Range<double>(_vmin, _vmax);
}

SVector3 OCCFace::normal(const SPoint2 &param) const
{
  gp_Pnt pnt;
  gp_Vec du, dv;

  _occface->D1(param.x(), param.y(), pnt, du, dv);

  SVector3 t1(du.X(), du.Y(), du.Z());
  SVector3 t2(dv.X(), dv.Y(), dv.Z());
  SVector3 n(crossprod(t1, t2));
  n.normalize();
  if(_s.Orientation() == TopAbs_REVERSED) return n * (-1.);
  return n;
}

Pair<SVector3, SVector3> OCCFace::firstDer(const SPoint2 &param) const
{
  gp_Pnt pnt;
  gp_Vec du, dv;
  _occface->D1(param.x(), param.y(), pnt, du, dv);
  return Pair<SVector3, SVector3>(SVector3(du.X(), du.Y(), du.Z()),
                                  SVector3(dv.X(), dv.Y(), dv.Z()));
}

void OCCFace::secondDer(const SPoint2 &param, SVector3 &dudu, SVector3 &dvdv,
                        SVector3 &dudv) const
{
  gp_Pnt pnt;
  gp_Vec du, dv, duu, dvv, duv;
  _occface->D2(param.x(), param.y(), pnt, du, dv, duu, dvv, duv);

  dudu = SVector3(duu.X(), duu.Y(), duu.Z());
  dvdv = SVector3(dvv.X(), dvv.Y(), dvv.Z());
  dudv = SVector3(duv.X(), duv.Y(), duv.Z());
}

GPoint OCCFace::point(double par1, double par2) const
{
  double pp[2] = {par1, par2};
  gp_Pnt val = _occface->Value(par1, par2);
  return GPoint(val.X(), val.Y(), val.Z(), this, pp);
}

bool OCCFace::_project(const double p[3], double uv[2], double xyz[3]) const
{
  gp_Pnt pnt(p[0], p[1], p[2]);
  _projector.Perform(pnt);
  if(!_projector.NbPoints()) {
    Msg::Debug("Projection of point (%g, %g, %g) on surface %d failed", p[0],
               p[1], p[2], tag());
    return false;
  }
  _projector.LowerDistanceParameters(uv[0], uv[1]);

  if(uv[0] < _umin || uv[0] > _umax || uv[1] < _vmin || uv[1] > _vmax)
    Msg::Debug("Point projection is out of surface parameter bounds");

  if(xyz) {
    pnt = _projector.NearestPoint();
    xyz[0] = pnt.X();
    xyz[1] = pnt.Y();
    xyz[2] = pnt.Z();
  }
  return true;
}

GPoint OCCFace::closestPoint(const SPoint3 &qp,
                             const double initialGuess[2]) const
{
#if defined(HAVE_ALGLIB)
  // less robust but can be much faster
  if(CTX::instance()->geom.occUseGenericClosestPoint)
    return GFace::closestPoint(qp, initialGuess);
#endif
  double uv[2], xyz[3];
  if(_project(qp.data(), uv, xyz))
    return GPoint(xyz[0], xyz[1], xyz[2], this, uv);
  else
    return GFace::closestPoint(qp, initialGuess);
}

SPoint2 OCCFace::parFromPoint(const SPoint3 &qp, bool onSurface,
                              bool convTestXYZ) const
{
  // less robust but can be much faster
  if(CTX::instance()->geom.occUseGenericClosestPoint)
    return GFace::parFromPoint(qp, onSurface, convTestXYZ);
  double uv[2];
  if(_project(qp.data(), uv, nullptr))
    return SPoint2(uv[0], uv[1]);
  else // fallback: force convergence test in XYZ coordinates
    return GFace::parFromPoint(qp, true, true);
}

GEntity::GeomType OCCFace::geomType() const
{
  if(_occface->DynamicType() == STANDARD_TYPE(Geom_Plane))
    return Plane;
  else if(_occface->DynamicType() == STANDARD_TYPE(Geom_ToroidalSurface))
    return Torus;
  else if(_occface->DynamicType() == STANDARD_TYPE(Geom_BezierSurface))
    return BezierSurface;
  else if(_occface->DynamicType() == STANDARD_TYPE(Geom_CylindricalSurface))
    return Cylinder;
  else if(_occface->DynamicType() == STANDARD_TYPE(Geom_ConicalSurface))
    return Cone;
  else if(_occface->DynamicType() == STANDARD_TYPE(Geom_SurfaceOfRevolution))
    return SurfaceOfRevolution;
  else if(_occface->DynamicType() == STANDARD_TYPE(Geom_SphericalSurface))
    return Sphere;
  else if(_occface->DynamicType() == STANDARD_TYPE(Geom_BSplineSurface))
    return BSplineSurface;
  return Unknown;
}

double OCCFace::curvatureMax(const SPoint2 &param) const
{
  const double eps = 1.e-12;
  BRepLProp_SLProps prop(_sf, 2, eps);
  prop.SetParameters(param.x(), param.y());

  if(!prop.IsCurvatureDefined()) { return eps; }

  return std::max(fabs(prop.MinCurvature()), fabs(prop.MaxCurvature()));
}

double OCCFace::curvatures(const SPoint2 &param, SVector3 &dirMax,
                           SVector3 &dirMin, double &curvMax,
                           double &curvMin) const
{
  const double eps = 1.e-12;
  BRepLProp_SLProps prop(_sf, 2, eps);
  prop.SetParameters(param.x(), param.y());

  if(!prop.IsCurvatureDefined()) { return -1.; }

  curvMax = prop.MaxCurvature();
  curvMin = prop.MinCurvature();

  gp_Dir dMax = gp_Dir();
  gp_Dir dMin = gp_Dir();
  prop.CurvatureDirections(dMax, dMin);

  dirMax[0] = dMax.X();
  dirMax[1] = dMax.Y();
  dirMax[2] = dMax.Z();
  dirMin[0] = dMin.X();
  dirMin[1] = dMin.Y();
  dirMin[2] = dMin.Z();

  return curvMax;
}

bool OCCFace::containsPoint(const SPoint3 &pt) const
{
  const Standard_Real tolerance = BRep_Tool::Tolerance(_s);
  BRepClass_FaceClassifier faceClassifier;
  faceClassifier.Perform(_s, gp_Pnt{pt.x(), pt.y(), pt.z()}, tolerance);
  const TopAbs_State state = faceClassifier.State();
  return (state == TopAbs_IN || state == TopAbs_ON);
}

bool OCCFace::containsParam(const SPoint2 &pt)
{
  const Standard_Real tolerance = BRep_Tool::Tolerance(_s);
  BRepClass_FaceClassifier faceClassifier;
  faceClassifier.Perform(_s, gp_Pnt2d{pt.x(), pt.y()}, tolerance);
  const TopAbs_State state = faceClassifier.State();
  return (state == TopAbs_IN || state == TopAbs_ON);
}

bool OCCFace::buildSTLTriangulation(bool force)
{
  if(stl_triangles.size() && !force) return true;
  stl_vertices_uv.clear();
  stl_vertices_xyz.clear();
  stl_triangles.clear();
  if(!model()->getOCCInternals()->makeFaceSTL(
       _s, stl_vertices_uv, stl_vertices_xyz, stl_normals, stl_triangles)) {
    Msg::Info("OpenCASCADE triangulation of surface %d failed", tag());
    // try the default algorithm in GFace
    return GFace::buildSTLTriangulation(force);
  }

  // compute the triangulation of the edges which are the boundaries of this
  // face
  std::vector<GEdge *> const &e = edges();
  for(auto it = e.begin(); it != e.end(); it++) {
    if((*it)->stl_vertices_xyz.size() == 0) {
      const TopoDS_Edge *c = (TopoDS_Edge *)(*it)->getNativePtr();
      model()->getOCCInternals()->makeEdgeSTLFromFace(
        *c, _s, &((*it)->stl_vertices_xyz));
    }
  }

  return true;
}

bool OCCFace::isSphere(double &radius, SPoint3 &center) const
{
  switch(geomType()) {
  case GEntity::Sphere:
    radius = _radius;
    center = _center;
    return true;
  default: return false;
  }
}

void OCCFace::writeBREP(const char *filename)
{
  BRep_Builder b;
  TopoDS_Compound c;
  b.MakeCompound(c);
  b.Add(c, _s);
  BRepTools::Write(c, filename);
}

#endif
