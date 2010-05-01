// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ACIS_EDGE_H_
#define _ACIS_EDGE_H_

#include "GmshConfig.h"
#include "GEdge.h"
#include "GModel.h"
#include "ACISVertex.h"
#include "Range.h"

class ACISFace;

#if defined(HAVE_ACIS)

#include <position.hxx>
#include <edge.hxx>

class ACISEdge : public GEdge {
  EDGE *_e;
  double s0, s1;
 public:
  ACISEdge(GModel *model, EDGE *e, int num, GVertex *v1, GVertex *v2);
  virtual ~ACISEdge() {}
  virtual Range<double> parBounds(int i) const;
  virtual GeomType geomType() const;
  virtual bool degenerate(int) const { return false; }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature (double par) const;
  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const;
  virtual GPoint closestPoint(const SPoint3 &queryPoint, double &param) const;
  ModelType getNativeType() const { return AcisModel; }
  void * getNativePtr() const { return (void*)_e; }
  virtual int minimumMeshSegments () const;
  virtual int minimumDrawSegments () const;
  bool isSeam(const GFace *) const;
  virtual void writeGEO(FILE *fp);
  EDGE* getEDGE() const {return _e;}
};
GEdge *getACISEdgeByNativePtr(GModel *model, EDGE *toFind);

#endif

#endif
