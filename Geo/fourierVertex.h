// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FOURIER_VERTEX_H_
#define _FOURIER_VERTEX_H_

#include "GmshConfig.h"
#include "GModel.h"
#include "GVertex.h"
#include "MVertex.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_TopoVertex.h"

class fourierVertex : public GVertex {
 protected:
  FM::TopoVertex *v;
 public:
  fourierVertex(GModel *m, int num, FM::TopoVertex* _v) : GVertex(m, num), v(_v){}
  virtual ~fourierVertex() {}
  virtual GPoint point() const { return GPoint(x(),y(),z()); }
  virtual double x() const { return v->GetX(); }
  virtual double y() const { return v->GetY(); }
  virtual double z() const { return v->GetZ(); }
  ModelType getNativeType() const { return FourierModel; }
};

#endif

#endif
