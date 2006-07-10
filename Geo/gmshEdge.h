#ifndef _H_GMSH_EDGE_
#define _H_GMSH_EDGE_

#include "GEdge.h"
#include "gmshModel.h"
#include "gmshVertex.h"
#include "Mesh.h"
#include "Range.h"

class gmshEdge : public GEdge{
public:
  gmshEdge(GModel *model,Curve *edge,GVertex *v1,GVertex *v2);
  virtual ~gmshEdge();
  double period() const{throw ;}
  Range<double> parBounds(int i) const;
  virtual bool periodic(int dim=0) const;
  virtual GeomType geomType() const;
  virtual bool degenerate(int) const;
  virtual bool continuous(int dim) const;
  // Geometric Ops
  SBoundingBox3d bounds() const;
  virtual GPoint point(double p) const;
  virtual GPoint closestPoint(const SPoint3 & queryPoint);
  virtual int containsPoint(const SPoint3 &pt) const;  
  virtual int containsParam(double pt) const;
  virtual SVector3 firstDer(double par) const;
  virtual SPoint2 reparamOnFace(GFace * face, double epar, int dir) const{
    throw;
  }
  void * getNativePtr() const; 
  virtual double parFromPoint(const SPoint3 &pt) const;
protected:
  Curve *c; 
};
#endif

