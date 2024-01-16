// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <limits>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "GModelIO_OCC.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "Context.h"

#if defined(HAVE_OCC)

#include <Standard_Version.hxx>
#include <TopoDS.hxx>
#include <Geom2dLProp_CLProps2d.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_OffsetCurve.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_Parabola.hxx>
#include <Geom_Hyperbola.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Line.hxx>
#include <Geom_Conic.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Bnd_Box.hxx>
#include <BRepLProp_CLProps.hxx>
#include <BRepBndLib.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRep_Builder.hxx>
#include <BOPTools_AlgoTools.hxx>

OCCEdge::OCCEdge(GModel *m, TopoDS_Edge c, int num, GVertex *v1, GVertex *v2)
  : GEdge(m, num, v1, v2), _c(c), _trimmed(nullptr)
{
  // force orientation of internal/external edges: otherwise reverse will not
  // produce the expected result
  if(_c.Orientation() == TopAbs_INTERNAL ||
     _c.Orientation() == TopAbs_EXTERNAL) {
    _c = TopoDS::Edge(_c.Oriented(TopAbs_FORWARD));
  }
  _curve = BRep_Tool::Curve(_c, _s0, _s1);
  // build the reverse curve
  _c_rev = _c;
  _c_rev.Reverse();

  _nbpoles = 0;

  if(!_curve.IsNull()) {
    // initialize projector, with a little tolerance to converge on the boundary
    // points
    double umin = _s0;
    double umax = _s1;
    if(_v0 != _v1) {
      const double du = umax - umin;
      const double utol = std::max(fabs(du) * 1e-8, 1e-12);
      umin -= utol;
      umax += utol;
    }
    _projector.Init(_curve, umin, umax);

    // keep track of number of poles for drawing
    if(_curve->DynamicType() == STANDARD_TYPE(Geom_BSplineCurve))
      _nbpoles = Handle(Geom_BSplineCurve)::DownCast(_curve)->NbPoles();
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_BezierCurve))
      _nbpoles = Handle(Geom_BezierCurve)::DownCast(_curve)->NbPoles();
  }
}

void OCCEdge::delFace(GFace *f)
{
  if(_trimmed == f) _trimmed = nullptr;
  GEdge::delFace(f);
}

SBoundingBox3d OCCEdge::bounds(bool fast)
{
  if(CTX::instance()->geom.occBoundsUseSTL && stl_vertices_xyz.size()) {
    // BRepBndLib can use the STL mesh if available, but unfortunately it
    // enlarges the box with the mesh deflection tolerance and the shape
    // tolerance, which makes it hard to get the expected minimal box in simple
    // cases (e.g. for straight lines), and always leads to boxes that are too
    // large; so we simply compute the box from the STL vertices. The downside
    // of this approach is that the bbox might be *smaller* than the actual box
    // for curved shapes, but this is preferable for us as boxes are mostly used
    // to find/identify entities
    SBoundingBox3d bbox;
    for(std::size_t i = 0; i < stl_vertices_xyz.size(); i++)
      bbox += stl_vertices_xyz[i];
    return bbox;
  }

  Bnd_Box b;
  try {
    BRepBndLib::Add(_c, b);
  } catch(Standard_Failure &err) {
    Msg::Error("OpenCASCADE exception %s", err.GetMessageString());
    return SBoundingBox3d();
  }
  double xmin, ymin, zmin, xmax, ymax, zmax;
  b.Get(xmin, ymin, zmin, xmax, ymax, zmax);
  SBoundingBox3d bbox(xmin, ymin, zmin, xmax, ymax, zmax);
  return bbox;
}

Range<double> OCCEdge::parBounds(int i) const
{
  return Range<double>(_s0, _s1);
}

Range<double> OCCEdge::parBoundsOnFace(GFace *face) const
{
  if(face->getNativeType() != GEntity::OpenCascadeModel || !degenerate(0)) {
    return parBounds(0);
  }

  const TopoDS_Face *s = (TopoDS_Face *)((OCCFace *)face->getNativePtr());
  double s0, s1;
  _curve2d = BRep_Tool::CurveOnSurface(_c, *s, s0, s1);
  return {s0, s1};
}

void OCCEdge::setTrimmed(OCCFace *f)
{
  if(!_trimmed) {
    _trimmed = f;
    const TopoDS_Face *s = (TopoDS_Face *)_trimmed->getNativePtr();
    _curve2d = BRep_Tool::CurveOnSurface(_c, *s, _s0, _s1);
    if(_curve2d.IsNull()) _trimmed = nullptr;
  }
}

SPoint2 OCCEdge::reparamOnFace(const GFace *face, double epar, int dir) const
{
  if(face->getNativeType() != GEntity::OpenCascadeModel) {
    const GPoint pt = point(epar);
    SPoint3 sp(pt.x(), pt.y(), pt.z());
    return face->parFromPoint(sp);
  }
  else {
    const TopoDS_Face *s = (TopoDS_Face *)face->getNativePtr();
    double t0, t1;
    Handle(Geom2d_Curve) c2d;

    if(dir == 1) { c2d = BRep_Tool::CurveOnSurface(_c, *s, t0, t1); }
    else {
      c2d = BRep_Tool::CurveOnSurface(_c_rev, *s, t0, t1);
    }

    if(c2d.IsNull()) {
      Msg::Warning("Curve %d is not on surface %d - computing closest point",
                   tag(), face->tag());
      const GPoint pt = point(epar);
      SPoint3 sp(pt.x(), pt.y(), pt.z());
      double guess[2] = {0, 0};
      GPoint pp = face->closestPoint(sp, guess);
      return SPoint2(pp.u(), pp.v());
    }

    double u, v;
    gp_Pnt2d pnt = c2d->Value(epar);
    pnt.Coord(u, v);

    // sometimes OCC miserably fails ...
    if(CTX::instance()->geom.reparamOnFaceRobust) {
      GPoint p1 = point(epar);
      GPoint p2 = face->point(u, v);
      double dx = p1.x() - p2.x();
      double dy = p1.y() - p2.y();
      double dz = p1.z() - p2.z();
      if(sqrt(dx * dx + dy * dy + dz * dz) > CTX::instance()->geom.tolerance) {
        Msg::Debug(
          "Reparam on surface was inaccurate for curve %d on surface %d "
          "at point %g",
          tag(), face->tag(), epar);
        Msg::Debug("On the surface %d local (%g %g) global (%g %g %g)",
                   face->tag(), u, v, p2.x(), p2.y(), p2.z());
        Msg::Debug("On the curve %d local (%g) global (%g %g %g)", tag(), epar,
                   p1.x(), p1.y(), p1.z());
        double guess[2] = {u, v};
        GPoint pp = face->closestPoint(SPoint3(p1.x(), p1.y(), p1.z()), guess);
        u = pp.u();
        v = pp.v();

        GPoint p2 = face->point(u, v);
        dx = p1.x() - p2.x();
        dy = p1.y() - p2.y();
        dz = p1.z() - p2.z();
        if(sqrt(dx * dx + dy * dy + dz * dz) >
           CTX::instance()->geom.tolerance) {
          Msg::Warning(
            "Closest point was inaccurate for curve %d on surface %d "
            "at point %g",
            tag(), face->tag(), epar);
          Msg::Warning("On the surface %d local (%g %g) global (%g %g %g)",
                       face->tag(), u, v, p2.x(), p2.y(), p2.z());
          Msg::Warning("On the curve %d local (%g) global (%g %g %g)", tag(),
                       epar, p1.x(), p1.y(), p1.z());
        }
      }
    }
    return SPoint2(u, v);
  }
}

bool OCCEdge::_project(const double p[3], double &u, double xyz[3]) const
{
  if(_curve.IsNull()) {
    Msg::Error("OpenCASCADE curve is null in projection");
    return false;
  }

  gp_Pnt pnt(p[0], p[1], p[2]);
  _projector.Perform(pnt);

  if(!_projector.NbPoints()) {
    Msg::Debug("Projection of point (%g, %g, %g) on curve %d failed", p[0],
               p[1], p[2], tag());
    return false;
  }

  u = _projector.LowerDistanceParameter();

  if(u < _s0 || u > _s1)
    Msg::Debug("Point projection is out of curve parameter bounds");

  if(xyz) {
    pnt = _projector.NearestPoint();
    xyz[0] = pnt.X();
    xyz[1] = pnt.Y();
    xyz[2] = pnt.Z();
  }
  return true;
}

GPoint OCCEdge::closestPoint(const SPoint3 &qp, double &param) const
{
  // less robust but can be faster
  if(CTX::instance()->geom.occUseGenericClosestPoint)
    return GEdge::closestPoint(qp, param);
  double u, xyz[3];
  if(_project(qp.data(), u, xyz))
    return GPoint(xyz[0], xyz[1], xyz[2], this, u);
  else
    return GEdge::closestPoint(qp, param);
}

double OCCEdge::parFromPoint(const SPoint3 &qp) const
{
  // less robust but can be faster
  if(CTX::instance()->geom.occUseGenericClosestPoint)
    return GEdge::parFromPoint(qp);
  double u;
  if(_project(qp.data(), u, nullptr))
    return u;
  else
    return GEdge::parFromPoint(qp);
}

bool OCCEdge::containsPoint(const SPoint3 &pt) const
{
  double u;
  SPoint3 xyz;
  if(_project(pt.data(), u, xyz.data())) {
    const Standard_Real tolerance = BRep_Tool::Tolerance(_c);
    if(pt.distance(xyz) <= tolerance) return true;
  }
  return false;
}

bool OCCEdge::isSeam(const GFace *face) const
{
  if(face->getNativeType() != GEntity::OpenCascadeModel) return false;
  const TopoDS_Face *s = (TopoDS_Face *)face->getNativePtr();
  // use IsClosed() variant taking Geom_Surface instead of TopoDS_Face as
  // argument, as the latter also tests the STL triangulation if available,
  // which can lead to different results depending if the STL mesh is available
  // or not; e.g. it can return true on plane surfaces with an internal curve,
  // which is not expected by Gmsh 2D meshing algorithms
  TopLoc_Location l;
  const Handle(Geom_Surface)& surf = BRep_Tool::Surface(*s, l);
  bool ret = BRep_Tool::IsClosed(_c, surf, l);
  return ret;
}

GPoint OCCEdge::point(double par) const
{
  if(_trimmed) {
    double u, v;
    _curve2d->Value(par).Coord(u, v);
    return _trimmed->point(u, v);
  }
  else if(!_curve.IsNull()) {
    gp_Pnt pnt = _curve->Value(par);
    return GPoint(pnt.X(), pnt.Y(), pnt.Z(), this, par);
  }
  else if(degenerate(0)) {
    return GPoint(getBeginVertex()->x(), getBeginVertex()->y(),
                  getBeginVertex()->z());
  }
  else {
    Msg::Warning(
      "OpenCASCADE curve %d is neither a 3D curve nor a trimmed curve", tag());
    return GPoint(0, 0, 0);
  }
}

SVector3 OCCEdge::firstDer(double par) const
{
  BRepAdaptor_Curve brepc(_c);
  BRepLProp_CLProps prop(brepc, 1, 1e-5);
  prop.SetParameter(par);
  gp_Vec d1 = prop.D1();
  return SVector3(d1.X(), d1.Y(), d1.Z());
}

GEntity::GeomType OCCEdge::geomType() const
{
  if(_curve.IsNull()) {
    if(_curve2d.IsNull())
      return Unknown;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_Circle))
      return Circle;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_Line))
      return Line;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_Ellipse))
      return Ellipse;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_Parabola))
      return Parabola;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_Hyperbola))
      return Hyperbola;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_TrimmedCurve))
      return TrimmedCurve;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_OffsetCurve))
      return OffsetCurve;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_BSplineCurve))
      return BSpline;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_BezierCurve))
      return Bezier;
    else if(_curve2d->DynamicType() == STANDARD_TYPE(Geom_Conic))
      return Conic;
    return Unknown;
  }
  else {
    if(_curve->DynamicType() == STANDARD_TYPE(Geom_Circle))
      return Circle;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_Line))
      return Line;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_Parabola))
      return Parabola;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_Hyperbola))
      return Hyperbola;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_TrimmedCurve))
      return TrimmedCurve;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_OffsetCurve))
      return OffsetCurve;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_Ellipse))
      return Ellipse;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_BSplineCurve))
      return BSpline;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_BezierCurve))
      return Bezier;
    else if(_curve->DynamicType() == STANDARD_TYPE(Geom_Conic))
      return Conic;
    return Unknown;
  }
}

int OCCEdge::minimumMeshSegments() const
{
  int np;

  // if it is a seam, then return 1 - but why? removed this in Gmsh 4.10.0
  //if(_faces.size() == 1 && isSeam(_faces[0])) return 1;

  if(geomType() == Line) { np = CTX::instance()->mesh.minLineNodes - 1; }
  else if(geomType() == Circle || geomType() == Ellipse) {
    double a = fabs(_s0 - _s1);
    double n = CTX::instance()->mesh.minCircleNodes;
    if(a > 6.28)
      np = n;
    else
      np = (int)(0.99 + (n - 1) * a / (2 * M_PI));
  }
  else {
    np = CTX::instance()->mesh.minCurveNodes - 1;
  }

  // if the edge is closed, ensure that at least 3 points are generated in the
  // 1D mesh (4 segments, one of which is degenerated)
  if(getBeginVertex() == getEndVertex()) np = std::max(4, np);

  return std::max(np, meshAttributes.minimumMeshSegments);
}

int OCCEdge::minimumDrawSegments() const
{
  int n = _nbpoles;
  if(n <= 0) n = GEdge::minimumDrawSegments();

  if(geomType() == Line)
    return n;
  else
    return CTX::instance()->geom.numSubEdges * n;
}

double OCCEdge::curvature(double par) const
{
  const double eps = 1.e-15;

  if(degenerate(0)) return eps;

  Standard_Real Crv;
  if(_curve.IsNull()) {
    Geom2dLProp_CLProps2d aCLProps(_curve2d, 2, eps);
    aCLProps.SetParameter(par);
    if(!aCLProps.IsTangentDefined())
      Crv = eps;
    else
      Crv = aCLProps.Curvature();
  }
  else {
    BRepAdaptor_Curve brepc(_c);
    BRepLProp_CLProps prop(brepc, 2, eps);
    prop.SetParameter(par);
    if(!prop.IsTangentDefined())
      Crv = eps;
    else
      Crv = prop.Curvature();
  }
  if(Crv <= eps) Crv = eps;
  return Crv;
}

void OCCEdge::writeGEO(FILE *fp)
{
  if(geomType() == Circle) {
    gp_Pnt center;
    if(_curve.IsNull()) {
      center = Handle(Geom_Circle)::DownCast(_curve2d)->Location();
    }
    else {
      center = Handle(Geom_Circle)::DownCast(_curve)->Location();
    }
    // GEO supports only circle arcs < Pi
    if(_s1 - _s0 < M_PI && getBeginVertex() && getEndVertex()) {
      fprintf(fp, "p%d = newp;\n", tag());
      fprintf(fp, "Point(p%d + 1) = {%.16g, %.16g, %.16g};\n", tag(),
              center.X(), center.Y(), center.Z());
      fprintf(fp, "Circle(%d) = {%d, p%d + 1, %d};\n", tag(),
              getBeginVertex()->tag(), tag(), getEndVertex()->tag());
    }
    else
      GEdge::writeGEO(fp);
  }
  else
    GEdge::writeGEO(fp);
}

#endif
