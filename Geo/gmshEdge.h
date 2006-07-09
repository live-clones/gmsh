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
  int isSeam(GFace *face) const;
  double period() const;
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
  virtual void nthDerivative(double param, int n, double *array) const;
  virtual SPoint2 reparamOnFace(GFace * face, double epar, int dir) const{
    throw;
  }
  int geomDirection() const;
  void fixPeriodicPar(double &par);
  virtual double tolerance() const;
  void * getNativePtr() const; 
  virtual GVertex * split(double par);
  Curve *c; 
  //  virtual GeoRep * geometry() {return 0;}
  virtual double parFromPoint(const SPoint3 &pt) const;
protected:
};
#endif

