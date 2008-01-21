#ifndef _F_EDGE_H_
#define _F_EDGE_H_

#include "GEdge.h"
#include "GModel.h"
#include "FVertex.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_TopoEdge.h"
#include "FM_TopoFace.h"

class FEdge : public GEdge {
 protected:
  FM::TopoEdge *edge;
  int edgeNum;
 public:
  FEdge(GModel *model, FM::TopoEdge *edge_, int tag, GVertex *v0, GVertex *v1);
  virtual ~FEdge() {}
  virtual Range<double> parBounds(int i) const;
  virtual GeomType geomType() const { return ParametricCurve; }
  virtual GPoint point(double p) const;
  virtual int containsParam(double pt) const { throw; }
  virtual SVector3 firstDer(double par) const;
  virtual double parFromPoint(const SPoint3 &pt) const;
  virtual int minimumMeshSegments () const;
  virtual int minimumDrawSegments () const;
  ModelType getNativeType() const { return FourierModel; }
};

#endif

#endif
