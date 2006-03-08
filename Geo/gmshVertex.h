#ifndef _H_GMSH_VERTEX_
#define _H_GMSH_VERTEX_

#include "Mesh.h"
#include "gmshModel.h"

#ifdef _HAVE_SGMODEL_
#include "GVertex.h"
#else
class GVertex {
 public:
  GVertex(SGModel *m, int tag){}
};
#endif

class gmshVertex : public GVertex {
public:
  gmshVertex(SGModel *m, Vertex *_v) : GVertex(m, _v->Num), v(_v){}
  virtual ~gmshVertex() {}

  virtual GVPoint point() const
  {
    return GVPoint ( v->Pos.X,v->Pos.Y,v->Pos.Z, this);
  }
  virtual GeoRep * geometry() {return 0;}

  virtual double tolerance() const {return 1.e-14;}

  void * getNativePtr() const {return v;}
  Vertex *v;
 protected:
};

#endif
