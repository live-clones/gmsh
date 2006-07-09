#ifndef _H_GMSH_VERTEX_
#define _H_GMSH_VERTEX_

#include "Mesh.h"
#include "gmshModel.h"
#include "GVertex.h"

class gmshVertex : public GVertex {
public:
  gmshVertex(GModel *m, Vertex *_v) : GVertex(m, _v->Num), v(_v){}
  virtual ~gmshVertex() {}

  virtual GPoint point() const
  {
    return GPoint ( v->Pos.X,v->Pos.Y,v->Pos.Z,this);
  }
  virtual double tolerance() const {return 1.e-14;}
  void * getNativePtr() const {return v;}
  Vertex *v;
 protected:
};

#endif
