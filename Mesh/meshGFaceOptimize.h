// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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

typedef std::map<MVertex*, std::vector<MElement*> > v2t_cont;
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

void laplaceSmoothing(GFace *gf, int niter=1);
/*
void edgeSwappingLawson(GFace *gf);
*/

enum swapCriterion {SWCR_DEL, SWCR_QUAL, SWCR_NORM, SWCR_CLOSE};
enum splitCriterion {SPCR_CLOSE, SPCR_QUAL, SPCR_ALLWAYS};

int edgeSwapPass(GFace *gf, 
                 std::set<MTri3*, compareTri3Ptr> &allTris, 
                 const swapCriterion &cr,
                 const std::vector<double> &Us, 
                 const std::vector<double> &Vs,
                 const std::vector<double> &vSizes, 
                 const std::vector<double> &vSizesBGM);
/*int edgeSplitPass(double maxLC, GFace *gf, 
                  std::set<MTri3*, compareTri3Ptr> &allTris,
                  const splitCriterion &cr,   
                  std::vector<double> &Us,
                  std::vector<double> &Vs,
                  std::vector<double> &vSizes ,
                  std::vector<double> &vSizesBGM);
int edgeCollapsePass(double minLC, GFace *gf, 
                     std::set<MTri3*, compareTri3Ptr> &allTris,
                     std::vector<double> &Us,
                     std::vector<double> &Vs,
                     std::vector<double> &vSizes ,
                     std::vector<double> &vSizesBGM);*/
void removeFourTrianglesNodes(GFace *gf, bool replace_by_quads);
void buildMeshGenerationDataStructures(GFace *gf, 
                                       std::set<MTri3*, compareTri3Ptr> &AllTris,
                                       std::vector<double> &vSizes,
                                       std::vector<double> &vSizesBGM,
                                       std::vector<SMetric3> &vMetricsBGM,
                                       std::vector<double> &Us,
                                       std::vector<double> &Vs);
void transferDataStructure(GFace *gf, std::set<MTri3*, compareTri3Ptr> &AllTris,
                           std::vector<double> &Us, std::vector<double> &Vs);
void recombineIntoQuads(GFace *gf, 
			bool topologicalOpti   = true, 
			bool nodeRepositioning = true);
void recombineIntoQuadsIterative(GFace *gf);
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

class Temporary{
  private :
	static double w1,w2,w3;
	static std::vector<SVector3> gradients;
	void read_data(std::string);
	static SVector3 compute_normal(MElement*);
	static SVector3 compute_other_vector(MElement*);
	static SVector3 compute_gradient(MElement*);
  public :
	Temporary();
	~Temporary();
	void quadrilaterize(std::string,double,double,double);
	static double compute_total_cost(double,double);
	static void select_weights(double,double,double);
	static double compute_alignment(const MEdge&,MElement*,MElement*);
};

#endif
