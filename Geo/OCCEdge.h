// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OCC_EDGE_H
#define OCC_EDGE_H

#include "GmshConfig.h"
#include "GEdge.h"
#include "GModel.h"
#include "Range.h"

class OCCFace;

#if defined(HAVE_OCC)

#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <BRep_Tool.hxx>

class OCCEdge : public GEdge {
private:
  TopoDS_Edge _c;
  TopoDS_Edge _c_rev;
  double _s0, _s1;
  Handle(Geom_Curve) _curve;
  mutable Handle(Geom2d_Curve) _curve2d;
  mutable GFace *_trimmed;
  bool _project(const double p[3], double &u, double xyz[3]) const;

public:
  OCCEdge(GModel *model, TopoDS_Edge c, int num, GVertex *v1, GVertex *v2);
  virtual ~OCCEdge();
  virtual SBoundingBox3d bounds(bool fast = false);
  virtual Range<double> parBounds(int i) const;
  virtual Range<double> parBoundsOnFace(GFace *face = nullptr) const;
  virtual GeomType geomType() const;
  virtual bool degenerate(int) const { return BRep_Tool::Degenerated(_c); }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature(double par) const;
  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const;
  virtual GPoint closestPoint(const SPoint3 &queryPoint, double &param) const;
  virtual double parFromPoint(const SPoint3 &P) const;
  virtual ModelType getNativeType() const { return OpenCascadeModel; }
  virtual void *getNativePtr() const { return (void *)&_c; }
  virtual int minimumMeshSegments() const;
  virtual int minimumDrawSegments() const;
  virtual bool is3D() const { return !_curve.IsNull(); }
  void setTrimmed(OCCFace *);
  virtual bool isSeam(const GFace *) const;
  virtual void writeGEO(FILE *fp);
};

#endif

#endif
