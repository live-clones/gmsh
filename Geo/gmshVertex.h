#ifndef _GMSH_VERTEX_H_
#define _GMSH_VERTEX_H_

#include "Mesh.h"
#include "gmshModel.h"
#include "GVertex.h"

class gmshVertex : public GVertex {
public:
  gmshVertex(GModel *m, Vertex *_v) : GVertex(m, _v->Num), v(_v)
  {
    mesh_vertices.push_back(new MVertex(x(), y(), z(), this));
  }
  gmshVertex(GModel *m, int num) : GVertex(m, num), v(0)
  {
  }
  virtual ~gmshVertex() {}
  virtual GPoint point() const 
  {
    if(!v) return GPoint(0., 0., 0., this);
    return GPoint(v->Pos.X, v->Pos.Y, v->Pos.Z, this);
  }
  virtual double x() const {return v ? v->Pos.X : 0.;}
  virtual double y() const {return v ? v->Pos.Y : 0.;}
  virtual double z() const {return v ? v->Pos.Z : 0.;}
  void * getNativePtr() const {return v;}
  virtual double prescribedMeshSizeAtVertex () const {return v ? v->lc : 0.;}
 protected:
  Vertex *v;
};

#endif
