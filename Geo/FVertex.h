#ifndef _F_VERTEX_H_
#define _F_VERTEX_H_

#include "GModel.h"
#include "GVertex.h"
#include "MVertex.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_TopoVertex.h"

class FVertex : public GVertex {
 protected:
  FM::TopoVertex *v;
 public:
  FVertex(GModel *m, int num, FM::TopoVertex* _v) : GVertex(m, num), v(_v)
  {
    mesh_vertices.push_back(new MVertex(x(), y(), z(), this));
  }
  virtual ~FVertex() {}
  virtual GPoint point() const { return GPoint(x(),y(),z()); }
  virtual double x() const { return v->GetX(); }
  virtual double y() const { return v->GetY(); }
  virtual double z() const { return v->GetZ(); }
  ModelType getNativeType() const { return FourierModel; }
};

#endif

#endif
