// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_VERTEX_H_
#define _GMSH_VERTEX_H_

#include "Geo.h"
#include "GVertex.h"

class gmshVertex : public GVertex {
 protected:
  Vertex *v;

 public:
  gmshVertex(GModel *m, Vertex *_v);
  virtual ~gmshVertex() {}
  virtual GPoint point() const 
  {
    return GPoint(v->Pos.X, v->Pos.Y, v->Pos.Z, this);
  }
  virtual double x() const { return v->Pos.X; }
  virtual double y() const { return v->Pos.Y; }
  virtual double z() const { return v->Pos.Z; }
  virtual void setPosition(GPoint &p);
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return GmshModel; }
  void *getNativePtr() const { return v; }
  virtual void setPrescribedMeshSizeAtVertex(double l) 
  {
    meshSize = l;
    v->lc = meshSize;
  }
  virtual SPoint2 reparamOnFace(const GFace *gf, int) const;
  virtual void writeGEO(FILE *fp);
};

#endif
