// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_POLYMESH_H
#define MESH_POLYMESH_H

#include <vector>
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

  inline int split_triangle(double x, double y, double z, Face *f,
                            int (*doSwap)(PolyMesh::HalfEdge *, void *) = NULL,
                            void *data = NULL,
                            std::vector<HalfEdge *> *_t = NULL)
  {
    Vertex *v = new PolyMesh::Vertex(x, y, z); // one more vertex

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

#endif
