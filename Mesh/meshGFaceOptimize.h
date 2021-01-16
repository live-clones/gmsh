// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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

struct edge_angle {
  MVertex *v1, *v2;
  double angle;
  edge_angle(MVertex *_v1, MVertex *_v2, MElement *t1, MElement *t2);
  bool operator<(const edge_angle &other) const { return other.angle < angle; }
};

// TODO: switch to unordered_map here & verify deterministic bahavior
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

  RecombineTriangle(const MEdge &me, MElement *_t1, MElement *_t2)
    : t1(_t1), t2(_t2)
  {
    n1 = me.getVertex(0);
    n2 = me.getVertex(1);
    n3 = nullptr;
    n4 = nullptr;

    if(t1->getVertex(0) != n1 && t1->getVertex(0) != n2)
      n3 = t1->getVertex(0);
    else if(t1->getVertex(1) != n1 && t1->getVertex(1) != n2)
      n3 = t1->getVertex(1);
    else if(t1->getVertex(2) != n1 && t1->getVertex(2) != n2)
      n3 = t1->getVertex(2);

    if(t2->getVertex(0) != n1 && t2->getVertex(0) != n2)
      n4 = t2->getVertex(0);
    else if(t2->getVertex(1) != n1 && t2->getVertex(1) != n2)
      n4 = t2->getVertex(1);
    else if(t2->getVertex(2) != n1 && t2->getVertex(2) != n2)
      n4 = t2->getVertex(2);

    MQuadrangle q(n1, n3, n2, n4);
    angle = q.etaShapeMeasure();

    double const a1 = 180 * angle3Vertices(n1, n4, n2) / M_PI;
    double const a2 = 180 * angle3Vertices(n4, n2, n3) / M_PI;
    double const a3 = 180 * angle3Vertices(n2, n3, n1) / M_PI;
    double const a4 = 180 * angle3Vertices(n3, n1, n4) / M_PI;
    quality = std::abs(90. - a1);
    quality = std::max(std::abs(90. - a2), quality);
    quality = std::max(std::abs(90. - a3), quality);
    quality = std::max(std::abs(90. - a4), quality);
  }

  bool operator<(const RecombineTriangle &other) const
  {
    return quality < other.quality;
  }
};

#endif
