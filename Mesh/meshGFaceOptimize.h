// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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


//DEV Amaury
void devRecombine_Amaury(GFace *gf, 
			bool topologicalOpti   = true, 
			bool nodeRepositioning = true);
struct RecombineTriangle
{
  MElement *t1, *t2;
  double angle;
  double cost_quality; //addition for class Temporary
  double cost_alignment; //addition for class Temporary
  double total_cost; //addition for class Temporary
  MVertex *n1, *n2, *n3, *n4;
  RecombineTriangle(const MEdge &me, MElement *_t1, MElement *_t2)
    : t1(_t1), t2(_t2)
  {
    n1 = me.getVertex(0);
    n2 = me.getVertex(1);

    if(t1->getVertex(0) != n1 && t1->getVertex(0) != n2) n3 = t1->getVertex(0);
    else if(t1->getVertex(1) != n1 && t1->getVertex(1) != n2) n3 = t1->getVertex(1);
    else if(t1->getVertex(2) != n1 && t1->getVertex(2) != n2) n3 = t1->getVertex(2);
    if(t2->getVertex(0) != n1 && t2->getVertex(0) != n2) n4 = t2->getVertex(0);
    else if(t2->getVertex(1) != n1 && t2->getVertex(1) != n2) n4 = t2->getVertex(1);
    else if(t2->getVertex(2) != n1 && t2->getVertex(2) != n2) n4 = t2->getVertex(2);

    double a1 = 180 * angle3Vertices(n1, n4, n2) / M_PI;
    double a2 = 180 * angle3Vertices(n4, n2, n3) / M_PI;
    double a3 = 180 * angle3Vertices(n2, n3, n1) / M_PI;
    double a4 = 180 * angle3Vertices(n3, n1, n4) / M_PI;
    angle = fabs(90. - a1);
    angle = std::max(fabs(90. - a2),angle);
    angle = std::max(fabs(90. - a3),angle);
    angle = std::max(fabs(90. - a4),angle);
	cost_quality = 1.0 - std::max(1.0 - angle/90.0,0.0); //addition for class Temporary
	cost_alignment = Temporary::compute_alignment(me,_t1,_t2); //addition for class Temporary
	total_cost = Temporary::compute_total_cost(cost_quality,cost_alignment); //addition for class Temporary
	total_cost = 100.0*cost_quality; //addition for class Temporary
  }
  bool operator < (const RecombineTriangle &other) const;
  /*{
    //return angle < other.angle;
	//return total_cost < other.total_cost; //addition for class Temporary
  }*/
};
struct lessRecombTri
{
  bool operator()(RecombineTriangle *rt1, RecombineTriangle *rt2)
  {
    return *rt1 < *rt2;
  }
};
typedef std::set<RecombineTriangle*,lessRecombTri> SetRecombTri;
typedef std::map< MElement*, std::vector<RecombineTriangle*> > MapElemToIncomp;
class RecombSeq {
  private:
    //std::vector<int> _skipped;
    //std::vector<int> _toBeSkipped;
    //std::map<RecombineTriangle*, int> _numSkip;
    SetRecombTri _canBeSkipped, _toBeSkipped, _toBeKept;
    SetRecombTri::iterator _it1, _it2, _ite;
    //std::set<MElement*> _touched;
    //std::map< MElement*, std::pair<MElement*, bool> > _touched;
    std::map< MElement*, std::pair<RecombineTriangle*, bool> > _touched;
    double _benef, _perspect;
    int _depth;
    
  public:
    RecombSeq(SetRecombTri::iterator it,
	      SetRecombTri::iterator itend,
	      int depth) : _it1(it), _ite(itend), _depth(depth)
    {
      _benef = 0;
      _it2 = it;
      parcours(depth);
    }
    
    RecombSeq(SetRecombTri::iterator it,
	      SetRecombTri::iterator itend,
	      int depth,
	      SetRecombTri toBeSkipped,
	      SetRecombTri toBeKept);
    bool parcours(int d, int a = 10);
    double getOptimalBenef(bool firstSkipable);
    
    bool optimal() const {return _canBeSkipped.empty();}
    bool shouldBeSkipped();
    /*void getOptimal(SetRecombTri::iterator &it)
    {
      SetRecombTri::iterator itmp = _it1;
      itmp++;
      MElement *t1 = (*_it2)->t1;
      MElement *t2 = (*_it2)->t2;
      while (_touched.find(t1) != _touched.end() ||
	     _touched.find(t2) != _touched.end()) {
	if (++itmp == _ite) return;
	t1 = (*_it2)->t1;
	t2 = (*_it2)->t2;
      }
      
      RecombSeq rs(itmp, _ite, _depth);
      
    }*/
    
    double getBenef() const {return _benef;}
    //std::vector<int> getSkipped() const {return _skipped;}
};
#endif
