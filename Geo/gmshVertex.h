// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_VERTEX_H_
#define _GMSH_VERTEX_H_

#include "Geo.h"
#include "GVertex.h"
#include "MVertex.h"

class gmshVertex : public GVertex {
 protected:
  Vertex *v;

 public:
  gmshVertex(GModel *m, Vertex *_v) : GVertex(m, _v->Num, _v->lc), v(_v)
  {
    mesh_vertices.push_back(new MVertex(x(), y(), z(), this));
  }
  virtual ~gmshVertex() {}
  virtual GPoint point() const 
  {
    return GPoint(v->Pos.X, v->Pos.Y, v->Pos.Z, this);
  }
  virtual double x() const { return v->Pos.X; }
  virtual double y() const { return v->Pos.Y; }
  virtual double z() const { return v->Pos.Z; }
  virtual void setPosition(GPoint &p)
  {
    v->Pos.X = p.x();
    v->Pos.Y = p.y();
    v->Pos.Z = p.z();
    if(mesh_vertices.size()){
      mesh_vertices[0]->x() = p.x();
      mesh_vertices[0]->y() = p.y();
      mesh_vertices[0]->z() = p.z();
    }
  }
  virtual GeomType geomType() const;
  ModelType getNativeType() const { return GmshModel; }
  void *getNativePtr() const { return v; }
  virtual void setPrescribedMeshSizeAtVertex(double l) 
  {
    meshSize = l;
    v->lc = meshSize;
  }
  virtual SPoint2 reparamOnFace(GFace *gf, int) const;
};

#endif
