// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_POLYMESH_H
#define MESH_POLYMESH_H

#include <vector>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include "SVector3.h"

class PolyMesh {
public:
  class HalfEdge;
  class Face;
  class Vertex;

  class Vertex {
  public:
    Vertex(double x, double y, double z, int _d = -1)
      : position(x, y, z), he(NULL), data(_d)
    {
    }
    SVector3 position;
    PolyMesh::HalfEdge *he; // one incident half edge
    int data;
  };

  class HalfEdge {
  public:
    HalfEdge(Vertex *vv)
      : v(vv), f(NULL), prev(NULL), next(NULL), opposite(NULL), data(-1)
    {
    }
    Vertex *v; // origin
    Face *f; // incident face
    HalfEdge *prev; // previous half edge on the face
    HalfEdge *next; // next half edge on the face
    HalfEdge *opposite; // opposite half edge (twin)
    int data;
    SVector3 d() const
    {
      SVector3 t = next->v->position - v->position;
      t.normalize();
      return t;
    }
  };

  class Face {
  public:
    Face(HalfEdge *e) : he(e), data(-1) {}
    HalfEdge *he; // one half edge of the face
    int data;
  };

  std::vector<Vertex *> vertices;
  std::vector<HalfEdge *> hedges;
  std::vector<Face *> faces;
  std::vector<SVector3> high_order_nodes;

  void reset()
  {
    for(auto it : vertices) delete it;
    for(auto it : hedges) delete it;
    for(auto it : faces) delete it;
  }
  
  ~PolyMesh() { reset(); }

  void print4debug(const int debugTag)
  {
    char name[256];
    sprintf(name, "polyMesh%d.pos", debugTag);
    FILE *f = fopen(name, "w");
    fprintf(f, "View \" %s \"{\n", name);
    for(auto it : faces) {
      HalfEdge *he0 = it->he;
      HalfEdge *he1 = it->he->next;
      HalfEdge *he2 = it->he->next->next;
      fprintf(f, "ST(%g,%g,0,%g,%g,0,%g,%g,0){%d,%d,%d};\n",
              he0->v->position.x(), he0->v->position.y(), he1->v->position.x(),
              he1->v->position.y(), he2->v->position.x(), he2->v->position.y(),
              it->data, it->data, it->data);
    }
    for(auto it : hedges) {
      HalfEdge *he = it;
      if(he->data >= 0) {
        fprintf(f, "SL(%g,%g,0,%g,%g,0){%d,%d};\n", he->v->position.x(),
                he->v->position.y(), he->opposite->v->position.x(),
                he->opposite->v->position.y(), he->data, he->data);
      }
    }

    fprintf(f, "};\n");
    fclose(f);
  }

  // compute the degree of a given vertex v
  inline int degree(const Vertex *v) const
  {
    HalfEdge *he = v->he;
    size_t count = 0;
    do {
      he = he->opposite;
      if(he == NULL) return -1;
      he = he->next;
      count++;
    } while(he != v->he);
    return count;
  }

  inline int num_sides(const HalfEdge *he) const
  {
    size_t count = 0;
    const HalfEdge *start = he;
    do {
      count++;
      he = he->next;
    } while(he != start);
    return count;
  }

  // compute the normal of an internal vertex v
  inline SVector3 normal(const Vertex *v) const
  {
    SVector3 n(0, 0, 0);
    HalfEdge *he = v->he;
    do {
      SVector3 n1 = he->d();
      he = he->opposite;
      if(he == NULL) return -1;
      he = he->next;
      n += crossprod(n1, he->d());
    } while(he != v->he);
    n.normalize();
    return n;
  }

  inline HalfEdge *getEdge(Vertex *v0, Vertex *v1)
  {
    HalfEdge *he = v0->he;
    do {
      if(he->next->v == v1) return he;
      he = he->opposite;
      if(he == NULL) return NULL;
      he = he->next;
    } while(he != v0->he);
    return NULL;
  }

  inline void createFace(Face *f, Vertex *v0, Vertex *v1, Vertex *v2,
                         HalfEdge *he0, HalfEdge *he1, HalfEdge *he2)
  {
    he0->v = v0;
    he1->v = v1;
    he2->v = v2;
    v0->he = he0;
    v1->he = he1;
    v2->he = he2;

    he0->next = he1;
    he1->prev = he0;
    he1->next = he2;
    he2->prev = he1;
    he2->next = he0;
    he0->prev = he2;
    he0->f = he1->f = he2->f = f;
    f->he = he0;
  }

  // swap without asking questions
  //
  //         he1
  // v2 ------->------ v3
  //    | \          |
  //    |   \ he0    | he2
  // heo2|     \      |
  //    |  heo0 \    |
  //    |         \  |
  // v1 -----<------- v0
  //          heo1
  //
  //          he1
  //    --------------
  //    |         /  |
  //    |   he0 /    | he2
  // heo2|    /       |
  //    |  /heo0     |
  //    |/           |
  //    --------------
  //          heo1
  //

  inline int swap_edge(HalfEdge *he0)
  {
    HalfEdge *heo0 = he0->opposite;
    if(heo0 == NULL) return -1;

    HalfEdge *he1 = he0->next;
    HalfEdge *he2 = he1->next;
    HalfEdge *heo1 = heo0->next;
    HalfEdge *heo2 = heo1->next;

    Vertex *v0 = heo1->v;
    Vertex *v1 = heo2->v;
    Vertex *v2 = heo0->v;
    Vertex *v3 = he2->v;

    createFace(he0->f, v0, v1, v3, heo1, heo0, he2);
    createFace(heo2->f, v1, v2, v3, heo2, he1, he0);
    return 0;
  }

  inline int merge_faces(HalfEdge *he)
  {
    PolyMesh::HalfEdge *heo = he->opposite;

    if(heo == nullptr) return -1;

    PolyMesh::Face *to_delete = heo->f;

    do {
      heo->f = he->f;
      heo = heo->next;
    } while(heo != he->opposite);

    he->next->prev = heo->prev;
    heo->prev->next = he->next;
    he->prev->next = heo->next;
    heo->next->prev = he->prev;

    he->f->he = he->next;
    he->v->he = heo->next;
    heo->v->he = he->next;

    // remove afterwards...
    he->v = nullptr;
    heo->v = nullptr;
    to_delete->he = nullptr;
    return 0;
  }

  void cleanv()
  {
    std::vector<Vertex *> uv;
    for(auto v : vertices) {
      if(v->he)
        uv.push_back(v);
      else
        delete v;
    }
    vertices = uv;
  }

  void cleanh()
  {
    std::vector<HalfEdge *> uh;
    for(auto h : hedges) {
      if(h->f)
        uh.push_back(h);
      else
        delete h;
    }
    hedges = uh;
  }

  void cleanf()
  {
    std::vector<Face *> uf;
    for(auto f : faces) {
      if(f->he)
        uf.push_back(f);
      else
        delete f;
    }
    faces = uf;
  }

  void clean()
  {
    cleanv();
    cleanh();
    cleanf();
  }

  inline int split_edge(HalfEdge *he0m, const SVector3 &position, int data)
  {
    HalfEdge *he1m = he0m->opposite;
    if(he1m == nullptr) return -1;

    Vertex *mid = new Vertex(position.x(), position.y(), position.z(), data);
    vertices.push_back(mid);

    HalfEdge *he12 = he0m->next;
    HalfEdge *he20 = he0m->next->next;
    HalfEdge *he03 = he0m->opposite->next;
    HalfEdge *he31 = he0m->opposite->next->next;

    // if(he03->v != he0m->v) Msg::Error("error 1");
    // if(he1m->v != he12->v) Msg::Error("error 2");

    Vertex *v0 = he03->v;
    Vertex *v1 = he12->v;
    Vertex *v2 = he20->v;
    Vertex *v3 = he31->v;

    HalfEdge *hem0 = new HalfEdge(mid);
    HalfEdge *hem1 = new HalfEdge(mid);
    HalfEdge *hem2 = new HalfEdge(mid);
    HalfEdge *hem3 = new HalfEdge(mid);

    HalfEdge *he2m = new HalfEdge(v2);
    HalfEdge *he3m = new HalfEdge(v3);

    he0m->opposite = hem0;
    hem0->opposite = he0m;
    he1m->opposite = hem1;
    hem1->opposite = he1m;
    he2m->opposite = hem2;
    hem2->opposite = he2m;
    he3m->opposite = hem3;
    hem3->opposite = he3m;

    hedges.push_back(hem0);
    hedges.push_back(hem1);
    hedges.push_back(hem2);
    hedges.push_back(hem3);
    hedges.push_back(he2m);
    hedges.push_back(he3m);

    Face *f0m2 = he0m->f;
    Face *f1m3 = he1m->f;
    Face *f2m1 = new Face(he2m);
    Face *f3m0 = new Face(he3m);
    faces.push_back(f2m1);
    faces.push_back(f3m0);

    createFace(f0m2, v0, mid, v2, he0m, hem2, he20);
    createFace(f1m3, v1, mid, v3, he1m, hem3, he31);
    createFace(f2m1, v2, mid, v1, he2m, hem1, he12);
    createFace(f3m0, v3, mid, v0, he3m, hem0, he03);
    return 0;
  }

  //
  // v0   he0
  // ------------------>------ v1
  // |                      /
  // |                   /
  // |      v         /
  // |he2          /
  // |          /  he1
  // |       /
  // |    /
  // |/
  // v2

  inline void initialize_rectangle(double xmin, double xmax, double ymin,
                                   double ymax)
  {
    reset();
    Vertex *v_mm = new PolyMesh::Vertex(xmin, ymin, 0);
    vertices.push_back(v_mm);
    Vertex *v_mM = new PolyMesh::Vertex(xmin, ymax, 0);
    vertices.push_back(v_mM);
    Vertex *v_MM = new PolyMesh::Vertex(xmax, ymax, 0);
    vertices.push_back(v_MM);
    Vertex *v_Mm = new PolyMesh::Vertex(xmax, ymin, 0);
    vertices.push_back(v_Mm);
    HalfEdge *mm_MM = new HalfEdge(v_mm);
    HalfEdge *MM_Mm = new HalfEdge(v_MM);
    HalfEdge *Mm_mm = new HalfEdge(v_Mm);
    hedges.push_back(mm_MM);
    hedges.push_back(MM_Mm);
    hedges.push_back(Mm_mm);
    Face *f0 = new Face(mm_MM);
    faces.push_back(f0);
    createFace(f0, v_mm, v_MM, v_Mm, mm_MM, MM_Mm, Mm_mm);

    HalfEdge *MM_mm = new HalfEdge(v_MM);
    HalfEdge *mm_mM = new HalfEdge(v_mm);
    HalfEdge *mM_MM = new HalfEdge(v_mM);
    hedges.push_back(MM_mm);
    hedges.push_back(mm_mM);
    hedges.push_back(mM_MM);
    Face *f1 = new Face(MM_mm);
    faces.push_back(f1);
    createFace(f1, v_MM, v_mm, v_mM, MM_mm, mm_mM, mM_MM);

    MM_mm->opposite = mm_MM;
    mm_MM->opposite = MM_mm;
  }

  inline int split_triangle(int index, double x, double y, double z, Face *f,
                            int (*doSwap)(PolyMesh::HalfEdge *, void *) = NULL,
                            void *data = NULL,
                            std::vector<HalfEdge *> *_t = NULL)
  {
    Vertex *v = new PolyMesh::Vertex(x, y, z); // one more vertex
    v->data = -1;

    vertices.push_back(v);

    HalfEdge *he0 = f->he;
    HalfEdge *he1 = he0->next;
    HalfEdge *he2 = he1->next;

    Vertex *v0 = he0->v;
    Vertex *v1 = he1->v;
    Vertex *v2 = he2->v;
    HalfEdge *hev0 = new PolyMesh::HalfEdge(v);
    HalfEdge *hev1 = new PolyMesh::HalfEdge(v);
    HalfEdge *hev2 = new PolyMesh::HalfEdge(v);

    HalfEdge *he0v = new PolyMesh::HalfEdge(v0);
    HalfEdge *he1v = new PolyMesh::HalfEdge(v1);
    HalfEdge *he2v = new PolyMesh::HalfEdge(v2);

    hedges.push_back(hev0);
    hedges.push_back(hev1);
    hedges.push_back(hev2);
    hedges.push_back(he0v);
    hedges.push_back(he1v);
    hedges.push_back(he2v);

    hev0->opposite = he0v;
    he0v->opposite = hev0;
    hev1->opposite = he1v;
    he1v->opposite = hev1;
    hev2->opposite = he2v;
    he2v->opposite = hev2;

    Face *f0 = f;
    f->he = hev0;
    Face *f1 = new Face(hev1);
    Face *f2 = new Face(hev2);
    f1->data = f2->data = f0->data;

    faces.push_back(f1);
    faces.push_back(f2);

    createFace(f0, v0, v1, v, he0, he1v, hev0);
    createFace(f1, v1, v2, v, he1, he2v, hev1);
    createFace(f2, v2, v0, v, he2, he0v, hev2);

    if(doSwap) {
      std::stack<HalfEdge *> _stack;
      _stack.push(he0);
      _stack.push(he1);
      _stack.push(he2);
      std::vector<HalfEdge *> _touched;
      while(!_stack.empty()) {
        HalfEdge *he = _stack.top();
        _touched.push_back(he);
        _stack.pop();
        //	printf("do we swap %g %g --> %g %g ?\n",
        //		       he->v->position.x(),he->v->position.y(),
        //	he->next->v->position.x(),he->next->v->position.y());
        if(doSwap(he, data) == 1) {
          //	  printf("YES\n");
          swap_edge(he);

          HalfEdge *H[2] = {he, he->opposite};

          for(int k = 0; k < 2; k++) {
            if(H[k] == NULL) continue;
            HalfEdge *heb = H[k]->next;
            HalfEdge *hebo = heb->opposite;

            if(std::find(_touched.begin(), _touched.end(), heb) ==
                 _touched.end() &&
               std::find(_touched.begin(), _touched.end(), hebo) ==
                 _touched.end()) {
              _stack.push(heb);
            }

            HalfEdge *hec = heb->next;
            HalfEdge *heco = hec->opposite;

            if(std::find(_touched.begin(), _touched.end(), hec) ==
                 _touched.end() &&
               std::find(_touched.begin(), _touched.end(), heco) ==
                 _touched.end()) {
              _stack.push(hec);
            }
          }
        }
      }
      if(_t) *_t = _touched;
    }
    return 0;
  }
};

struct HalfEdgePtrLessThan {
  bool operator()(PolyMesh::HalfEdge *l1, PolyMesh::HalfEdge *l2) const
  {
    PolyMesh::Vertex *l10 = std::min(l1->v, l1->next->v);
    PolyMesh::Vertex *l11 = std::max(l1->v, l1->next->v);
    PolyMesh::Vertex *l20 = std::min(l2->v, l2->next->v);
    PolyMesh::Vertex *l21 = std::max(l2->v, l2->next->v);
    if(l10 < l20) return true;
    if(l10 > l20) return false;
    if(l11 > l21) return true;
    return false;
  }
};

struct HalfEdgePtrEqual {
  bool operator()(PolyMesh::HalfEdge *l1, PolyMesh::HalfEdge *l2) const
  {
    PolyMesh::Vertex *l10 = std::min(l1->v, l1->next->v);
    PolyMesh::Vertex *l11 = std::max(l1->v, l1->next->v);
    PolyMesh::Vertex *l20 = std::min(l2->v, l2->next->v);
    PolyMesh::Vertex *l21 = std::max(l2->v, l2->next->v);
    if(l10 == l20 && l11 == l21) return true;
    return false;
  }
};

// compute the degree of a given vertex v
inline int degree(const PolyMesh::Vertex *v) 
{
  PolyMesh::HalfEdge *he = v->he;
  size_t count = 0;
  do {
    he = he->opposite;
    if(he == NULL) return -1;
    he = he->next;
    count++;
  } while(he != v->he);
  return count;
}


#endif
