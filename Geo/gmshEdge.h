#ifndef _GMSH_EDGE_H_
#define _GMSH_EDGE_H_

#include "GEdge.h"
#include "gmshModel.h"
#include "gmshVertex.h"
#include "Mesh.h"
#include "Range.h"

class gmshEdge : public GEdge {
 protected:
  Curve *c; 

 public:
  gmshEdge(GModel *model, Curve *edge, GVertex *v1, GVertex *v2);
  gmshEdge(GModel *model, int num);
  virtual ~gmshEdge() {}
  double period() const { throw ; }
  Range<double> parBounds(int i) const;
  virtual bool periodic(int dim=0) const { return false; }
  virtual GeomType geomType() const;
  virtual bool degenerate(int) const { return false; }
  virtual bool continuous(int dim) const { return true; }
  SBoundingBox3d bounds() const;
  virtual GPoint point(double p) const;
  virtual GPoint closestPoint(const SPoint3 & queryPoint);
  virtual int containsPoint(const SPoint3 &pt) const { throw; }
  virtual int containsParam(double pt) const;
  virtual SVector3 firstDer(double par) const;
  virtual SPoint2 reparamOnFace(GFace * face, double epar, int dir) const { throw; }
  void * getNativePtr() const { return c; }
  virtual double parFromPoint(const SPoint3 &pt) const;
  virtual int minimumMeshSegments () const;
  virtual int minimumDrawSegments () const;
};

#endif
