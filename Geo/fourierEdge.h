// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FOURIER_EDGE_H_
#define _FOURIER_EDGE_H_

#include "GEdge.h"
#include "GModel.h"
#include "fourierVertex.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_TopoEdge.h"
#include "FM_TopoFace.h"

class fourierEdge : public GEdge {
 protected:
  FM::TopoEdge *edge;
  int edgeNum;
 public:
  fourierEdge(GModel *model, FM::TopoEdge *edge_, int tag, GVertex *v0, GVertex *v1);
  virtual ~fourierEdge() {}
  virtual Range<double> parBounds(int i) const;
  virtual GeomType geomType() const { return ParametricCurve; }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual int minimumMeshSegments () const;
  virtual int minimumDrawSegments () const;
  ModelType getNativeType() const { return FourierModel; }
};

#endif

#endif
