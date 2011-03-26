// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ACIS_VERTEX_H_
#define _ACIS_VERTEX_H_

#include "GmshConfig.h"
#include "GModel.h"
#include "GVertex.h"

#if defined(HAVE_ACIS)

#include <vertex.hxx>

class ACISVertex : public GVertex {
 protected:
  VERTEX* _v;
  double _x, _y, _z;
 public:
  ACISVertex(GModel *m, int num, VERTEX *_v);
  virtual ~ACISVertex() {}
  virtual GPoint point() const { return GPoint(x(), y(), z()); }
  virtual double x() const { return _x; }
  virtual double y() const { return _y; }
  virtual double z() const { return _z; }
  virtual void setPosition(GPoint &p);
  ModelType getNativeType() const { return AcisModel; }
  void * getNativePtr() const { return (void*)_v; }
  virtual SPoint2 reparamOnFace(const GFace *gf, int) const;
  VERTEX* getVERTEX() { return _v; }
};
GVertex *getACISVertexByNativePtr(GModel *model, VERTEX*);

#endif

#endif
