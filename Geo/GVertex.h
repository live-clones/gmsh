// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GVERTEX_H_
#define _GVERTEX_H_

#include "GEntity.h"
#include "GPoint.h"
#include "SPoint2.h"

// A model vertex.
class GVertex : public GEntity 
{
 protected:
  std::list<GEdge*> l_edges;
  double meshSize;
 public:
  GVertex(GModel *m, int tag, double ms=1.e22);
  virtual ~GVertex();
  virtual GPoint point() const = 0;
  virtual double x() const = 0;
  virtual double y() const = 0;
  virtual double z() const = 0;
  virtual void setPosition(GPoint &p);
  void addEdge(GEdge *e);
  void delEdge(GEdge *e);
  virtual int dim() const { return 0; }
  virtual GeomType geomType() const { return Point; }
  inline double prescribedMeshSizeAtVertex() const { return meshSize; }
  virtual void setPrescribedMeshSizeAtVertex(double l) { meshSize = l; }
  virtual SBoundingBox3d bounds() const { return SBoundingBox3d(SPoint3(x(), y(), z())); }
  virtual SPoint2 reparamOnFace(GFace *gf, int) const;
  virtual std::string getAdditionalInfoString();
  virtual std::list<GEdge*> edges() const{ return l_edges; }
};

#endif

