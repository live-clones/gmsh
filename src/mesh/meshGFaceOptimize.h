// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_OPTIMIZE_H
#define MESH_GFACE_OPTIMIZE_H

#include <map>
//#include <unordered_map>
#include <vector>
#include "MElement.h"
#include "MEdge.h"
#include "meshGFaceDelaunayInsertion.h"
#include "STensor3.h"

class GFace;
class GVertex;
class MVertex;
class Field;

struct edge_angle {
  MVertex *v1, *v2;
  double angle;
  edge_angle(MVertex *_v1, MVertex *_v2, MElement *t1, MElement *t2);
  bool operator<(const edge_angle &other) const { return other.angle < angle; }
};

// TODO: switch to unordered_map here & verify deterministic behavior
typedef std::map<MVertex *, std::vector<MElement *>, MVertexPtrLessThan>
  v2t_cont;
// typedef std::unordered_map<MVertex *, std::vector<MElement *> > v2t_cont;

typedef std::map<MEdge, std::pair<MElement *, MElement *>, MEdgeLessThan>
  e2t_cont;

template <class T>
void buildVertexToElement(std::vector<T *> const &elements, v2t_cont &adj)
{
  for(std::size_t i = 0, elements_size = elements.size(); i < elements_size;
      i++) {
    T *const t = elements[i];

    for(std::size_t j = 0, vertices_size = t->getNumVertices();
        j < vertices_size; j++) {
      adj[t->getVertex(j)].push_back(t);
    }
  }
}

// Same adjacency information as a v2t_cont filled by buildVertexToElement(),
// but stored in a flat CSR (compressed sparse row) layout: vertices are
// ordered by increasing MVertex::getNum() and the elements adjacent to each
// vertex keep their insertion order, so iterating gives exactly the same
// deterministic order as the std::map-based container at a fraction of the
// construction cost
class VertexToElementCSR {
public:
  VertexToElementCSR() : _minNum(0), _maxNum(0) {}
  template <class T> void add(std::vector<T *> const &elements)
  {
    if(elements.empty()) return;
    _pairs.reserve(_pairs.size() +
                   elements.size() * elements[0]->getNumVertices());
    for(std::size_t i = 0, elements_size = elements.size(); i < elements_size;
        i++) {
      T *const t = elements[i];
      for(std::size_t j = 0, vertices_size = t->getNumVertices();
          j < vertices_size; j++) {
        MVertex *v = t->getVertex(j);
        std::size_t num = v->getNum();
        if(_pairs.empty()) { _minNum = _maxNum = num; }
        else {
          _minNum = std::min(_minNum, num);
          _maxNum = std::max(_maxNum, num);
        }
        _pairs.push_back(std::pair<MVertex *, MElement *>(v, t));
      }
    }
  }
  // sort the adjacency by increasing vertex number; must be called once,
  // after the last add() and before accessing the data
  void finalize();
  std::size_t numVertices() const { return _vertices.size(); }
  MVertex *vertex(std::size_t i) const { return _vertices[i]; }
  MElement *const *elements(std::size_t i) const
  {
    return &_elements[_first[i]];
  }
  std::size_t numElements(std::size_t i) const
  {
    return _first[i + 1] - _first[i];
  }

private:
  std::vector<std::pair<MVertex *, MElement *> > _pairs;
  std::vector<MVertex *> _vertices;
  std::vector<std::size_t> _first;
  std::vector<MElement *> _elements;
  std::size_t _minNum, _maxNum;
};

template <class T>
void buildEdgeToElement(std::vector<T *> &eles, e2t_cont &adj);

void buildEdgeToTriangle(std::vector<MTriangle *> &, e2t_cont &adj);
void buildListOfEdgeAngle(e2t_cont adj, std::vector<edge_angle> &edges_detected,
                          std::vector<edge_angle> &edges_lonly);
void buildEdgeToElements(std::vector<MElement *> &tris, e2t_cont &adj);

void laplaceSmoothing(GFace *gf, int niter = 1, bool infinity_norm = false);

bool buildMeshGenerationDataStructures(
  GFace *gf, std::set<MTri3 *, compareTri3Ptr> &AllTris, bidimMeshData &data);
void transferDataStructure(GFace *gf,
                           std::set<MTri3 *, compareTri3Ptr> &AllTris,
                           bidimMeshData &DATA);
void computeEquivalences(GFace *gf, bidimMeshData &DATA);
// compute the gamma quality statistics of the triangles and quadrangles of a
// surface mesh
void computeElementShapes(GFace *gf, double &worst, double &avg, double &best,
                          int &nT, int &greaterThan);
void recombineIntoQuads(GFace *gf, bool blossom, int topologicalOptiPasses,
                        bool nodeRepositioning, double minqual);

// used for meshGFaceRecombine development
void quadsToTriangles(GFace *gf, double minqual);

void splitElementsInBoundaryLayerIfNeeded(GFace *gf);

struct swapquad {
  int v[4];
  bool operator<(const swapquad &o) const
  {
    if(v[0] < o.v[0]) return true;
    if(v[0] > o.v[0]) return false;
    if(v[1] < o.v[1]) return true;
    if(v[1] > o.v[1]) return false;
    if(v[2] < o.v[2]) return true;
    if(v[2] > o.v[2]) return false;
    if(v[3] < o.v[3]) return true;
    return false;
  }

  swapquad(MVertex *v1, MVertex *v2, MVertex *v3, MVertex *v4)
  {
    v[0] = v1->getNum();
    v[1] = v2->getNum();
    v[2] = v3->getNum();
    v[3] = v4->getNum();
    std::sort(v, v + 4);
  }

  swapquad(int const v1, int const v2, int const v3, int const v4)
  {
    v[0] = v1;
    v[1] = v2;
    v[2] = v3;
    v[3] = v4;
    std::sort(v, v + 4);
  }
};

struct RecombineTriangle {
  MElement *t1, *t2;
  double angle;
  double quality;
  MVertex *n1, *n2, *n3, *n4;

  RecombineTriangle(const MEdge &me, MElement *_t1, MElement *_t2, Field *f);

  bool operator<(const RecombineTriangle &other) const
  {
    return quality < other.quality;
  }
};

#endif
