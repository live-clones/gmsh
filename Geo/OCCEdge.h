// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
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
protected:
  TopoDS_Edge _replacement;
  TopoDS_Edge c;
  TopoDS_Edge c_rev;
  double s0, s1;
  Handle(Geom_Curve) curve;
  mutable Handle(Geom2d_Curve) curve2d;
  mutable GFace *trimmed;

public:
  OCCEdge(GModel *model, TopoDS_Edge _e, int num, GVertex *v1, GVertex *v2);
  virtual ~OCCEdge();
  virtual SBoundingBox3d bounds(bool fast = false) const;
  virtual Range<double> parBounds(int i) const;
  virtual Range<double> parBoundsOnFace(GFace *face = NULL) const;
  virtual GeomType geomType() const;
  virtual bool degenerate(int) const { return BRep_Tool::Degenerated(c); }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature(double par) const;
  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const;
  virtual GPoint closestPoint(const SPoint3 &queryPoint, double &param) const;
  ModelType getNativeType() const { return OpenCascadeModel; }
  void *getNativePtr() const { return (void *)&c; }
  virtual int minimumMeshSegments() const;
  virtual int minimumDrawSegments() const;
  bool is3D() const { return !curve.IsNull(); }
  void setTrimmed(OCCFace *);
  bool isSeam(const GFace *) const;
  virtual void writeGEO(FILE *fp);
};

#endif

#endif
