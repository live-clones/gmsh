// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_INTRINSIC_H
#define MESH_INTRINSIC_H

#include "meshPolyMesh.h"
#include <map>


class IntrinsicTriangulation {
  PolyMesh *extrinsic_;
  PolyMesh *intrinsic_;
public:
  struct VertexOnEdge {
    PolyMesh::HalfEdge *he; // he in the extrinsic_ mesh
    double t; // local coordinates of the vertex in that edge
    SVector3 point  ()const{
      return he->v->position*(1.-t)+
	he->next->v->position*t;
    }
  };

  struct VertexOnFace {
    PolyMesh::HalfEdge *he; // he->f in the extrinsic_ mesh
    double u,v; // local coordinates of the vertex in that face
    SVector3 point () const {
      return he->v->position*(1.-u-v)+
	he->next->v->position*u+
	he->next->next->v->position*v;
    }
  };

  struct Geodesic {
    VertexOnFace _start;
    VertexOnFace _end;
    std::vector<VertexOnEdge> _pts;
    void print4debug (int id);
  };

  struct Window {
    PolyMesh::HalfEdge *he;
    double d1, d2;
    double t1, t2;
    bool operator < (const Window &w) const{
      if (std::min(d1,d2) < std::min(w.d1,w.d2))return true;
      if (std::min(d1,d2) > std::min(w.d1,w.d2))return false;
      return he < w.he;
    }
  };

  
  Geodesic trace (const VertexOnFace &start, double L, double theta);
  int continuousRienstra (PolyMesh::Vertex *v, double Lmax);

  IntrinsicTriangulation (PolyMesh *extr) : extrinsic_ (extr), intrinsic_ (nullptr)
  {
    // initialize the intrinsic triangulation as the extrinsic one and initialize
    // hedges and vertices
    intrinsic_ = new PolyMesh (*extrinsic_);
  }

  void test();
  
};


#endif
