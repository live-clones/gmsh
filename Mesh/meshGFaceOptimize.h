// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_GFACE_OPTIMIZE_H_
#define _MESH_GFACE_OPTIMIZE_H_

#include <map>
#include <vector>
#include "MElement.h"
#include "MEdge.h"
#include "meshGFaceDelaunayInsertion.h"
#include "STensor3.h"

class GFace;
class GVertex;
class MVertex;

class edge_angle {
 public :
  MVertex *v1, *v2;
  double angle;
  edge_angle(MVertex *_v1, MVertex *_v2, MElement *t1, MElement *t2);
  bool operator < (const edge_angle &other) const
  {
    return other.angle < angle;
  }
};

typedef std::map<MVertex*, std::vector<MElement*>, MVertexLessThanNum > v2t_cont;
typedef std::map<MEdge, std::pair<MElement*, MElement*>, Less_Edge> e2t_cont;

template <class T> void buildVertexToElement(std::vector<T*> &eles, v2t_cont &adj){
  for(unsigned int i = 0; i < eles.size(); i++){
    T *t = eles[i];
    for(int j = 0; j < t->getNumVertices(); j++){
      MVertex *v = t->getVertex(j);
      v2t_cont :: iterator it = adj.find(v);
      if(it == adj.end()){
        std::vector<MElement*> one;
        one.push_back(t);
        adj[v] = one;
      }
      else{
        it->second.push_back(t);
      }
    }
  }
}

template <class T> void buildEdgeToElement(std::vector<T*> &eles, e2t_cont &adj);

void buildVertexToTriangle(std::vector<MTriangle*> &, v2t_cont &adj);
void buildEdgeToTriangle(std::vector<MTriangle*> &, e2t_cont &adj);
void buildListOfEdgeAngle(e2t_cont adj, std::vector<edge_angle> &edges_detected,
                          std::vector<edge_angle> &edges_lonly);
void buildEdgeToElements(std::vector<MElement*> &tris, e2t_cont &adj);

void laplaceSmoothing(GFace *gf, int niter=1, bool infinity_norm = false);

void _relocateVertex(GFace *gf, MVertex *ver,
                     const std::vector<MElement*> &lt);

enum swapCriterion {SWCR_DEL, SWCR_QUAL, SWCR_NORM, SWCR_CLOSE};
enum splitCriterion {SPCR_CLOSE, SPCR_QUAL, SPCR_ALLWAYS};

int edgeSwapPass(GFace *gf,
                 std::set<MTri3*, compareTri3Ptr> &allTris,
                 const swapCriterion &cr, bidimMeshData &DATA);
void removeThreeTrianglesNodes(GFace *gf);
void buildMeshGenerationDataStructures(GFace *gf,
                                       std::set<MTri3*, compareTri3Ptr> &AllTris,
				       bidimMeshData & data);
void transferDataStructure(GFace *gf, std::set<MTri3*, compareTri3Ptr> &AllTris,bidimMeshData &DATA);
void computeEquivalences(GFace *gf,bidimMeshData &DATA);
void recombineIntoQuads(GFace *gf,
                        bool topologicalOpti   = true,
                        bool nodeRepositioning = true,
			double minqual = 0.1,
			bool verbose = true);

//used for meshGFaceRecombine development
void quadsToTriangles(GFace *gf, double minqual);

struct swapquad{
  int v[4];
  bool operator < (const swapquad &o) const
  {
    if (v[0] < o.v[0]) return true;
    if (v[0] > o.v[0]) return false;
    if (v[1] < o.v[1]) return true;
    if (v[1] > o.v[1]) return false;
    if (v[2] < o.v[2]) return true;
    if (v[2] > o.v[2]) return false;
    if (v[3] < o.v[3]) return true;
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
  swapquad(int v1, int v2, int v3, int v4)
  {
    v[0] = v1;
    v[1] = v2;
    v[2] = v3;
    v[3] = v4;
    std::sort(v, v + 4);
  }
};

struct RecombineTriangle
{
  MElement *t1, *t2;
  double angle;
  double quality;
  MVertex *n1, *n2, *n3, *n4;
  RecombineTriangle(const MEdge &me, MElement *_t1, MElement *_t2)
    : t1(_t1), t2(_t2)
  {
    n1 = me.getVertex(0);
    n2 = me.getVertex(1);
    n3 = 0;
    n4 = 0;

    if(t1->getVertex(0) != n1 && t1->getVertex(0) != n2) n3 = t1->getVertex(0);
    else if(t1->getVertex(1) != n1 && t1->getVertex(1) != n2) n3 = t1->getVertex(1);
    else if(t1->getVertex(2) != n1 && t1->getVertex(2) != n2) n3 = t1->getVertex(2);
    if(t2->getVertex(0) != n1 && t2->getVertex(0) != n2) n4 = t2->getVertex(0);
    else if(t2->getVertex(1) != n1 && t2->getVertex(1) != n2) n4 = t2->getVertex(1);
    else if(t2->getVertex(2) != n1 && t2->getVertex(2) != n2) n4 = t2->getVertex(2);

    MQuadrangle q (n1,n3,n2,n4);
    angle = q.etaShapeMeasure();

    double a1 = 180 * angle3Vertices(n1, n4, n2) / M_PI;
    double a2 = 180 * angle3Vertices(n4, n2, n3) / M_PI;
    double a3 = 180 * angle3Vertices(n2, n3, n1) / M_PI;
    double a4 = 180 * angle3Vertices(n3, n1, n4) / M_PI;
    quality = fabs(90. - a1);
    quality = std::max(fabs(90. - a2),quality);
    quality = std::max(fabs(90. - a3),quality);
    quality = std::max(fabs(90. - a4),quality);
  }
  bool operator < (const RecombineTriangle &other) const
  {
    return quality < other.quality;
  }
};


#endif
