// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _DISCRETE_DISK_FACE_H_
#define _DISCRETE_DISK_FACE_H_

#include "GmshConfig.h"

#if defined(HAVE_SOLVER) && defined(HAVE_ANN)

#include <list>
#include <map>
#include "GModel.h"
#include "GFace.h"
#include "discreteEdge.h"
#include "MEdge.h"
#include "MTriangle.h"
#include "linearSystem.h"
#include "MElementOctree.h"
#include "meshGFaceOptimize.h"
#include "PView.h"
#include "robustPredicates.h"

inline int nodeLocalNum(MElement* e, MVertex* v)
{
  for(int i=0; i<e->getNumVertices(); i++)
    if (v == e->getVertex(i))
      return i;
  return -1;
}

inline int edgeLocalNum(MElement* e, MEdge ed)
{
  for(int i=0; i<e->getNumEdges(); i++)
    if (ed == e->getEdge(i))
      return i;
  return -1;
}

class ANNkd_tree;
class Octree;
class GRbf;

class triangulation {

 public:

  // attributes
  double area;
  bool seamPoint;
  std::vector<MElement*> tri;// triangles
  std::set<MVertex*> vert;// nodes
  // edge to 1 or 2 triangle(s), their num into the vector of MElement*
  std::map<MEdge,std::vector<int>,Less_Edge> ed2tri;
  std::map<double,std::vector<MVertex*> > bord; //border(s)
  std::set<MEdge,Less_Edge> borderEdg; // border edges
  GFace *gf;
  int idNum; // number of identification, for hashing purposes

  std::list<GEdge*> my_GEdges;

  //---- methods

  double aspectRatio()
  { 
    double L = bord.rbegin()->first;
    return L*L / (area*M_PI);
  }

  int genus()
  {
    return ( ed2tri.size() - vert.size() - tri.size() + 2 - bord.size() )/2;
  }

  void assignVert()
  {
    for(unsigned int i = 0; i < tri.size(); ++i){
      MElement* t = tri[i];
      SPoint3 P[3];
      for(int j = 0; j < t->getNumVertices()  ; j++){
	MVertex* tv = t->getVertex(j);
	if(j<3)
	  P[j].setPosition(tv->x(),tv->y(),tv->z());
	std::set<MVertex*>::iterator it = vert.find(tv);
	if (it == vert.end()) vert.insert (tv);
      }
      SVector3 N(crossprod(P[1]-P[0],P[2]-P[0]));
      area += N.norm();
    }
  }

  void assignEd2tri()
  {
    for(unsigned int i = 0; i < tri.size(); ++i){
      MElement *t = tri[i];
      for(int j = 0; j <  3 ; j++){
	MEdge ed = t->getEdge(j);
	ed2tri[ed].push_back(i);
      }
    }
  }

  void assignBord()
  {
    for(unsigned int i = 0; i < tri.size(); ++i){
      MElement *t = tri[i];
      for(int j = 0; j <  t->getNumEdges() ; j++){
	MEdge ed = t->getEdge(j);
	std::set<MEdge,Less_Edge>::iterator it = borderEdg.find(ed);
	if (it == borderEdg.end()) borderEdg.insert(ed);
	else borderEdg.erase(it);
      }
    }

    std::map<MVertex*,std::vector<MVertex*> > firstNode2Edge;
    for (std::set<MEdge>::iterator ie = borderEdg.begin(); ie != borderEdg.end() ; ++ie) {
      MEdge ed = *ie;
      std::vector<int> nT = ed2tri[ed];
      MElement* t = tri[nT[0]];

      std::vector<MVertex*> vecver;
      t->getEdgeVertices(edgeLocalNum(t,ed),vecver);
      MVertex *first = vecver[0];
      MVertex *last = vecver[1];
      vecver.erase(vecver.begin());
      vecver.erase(vecver.begin());

      std::map<MVertex*,std::vector<MVertex*> >::iterator im = firstNode2Edge.find(first);
      if (im != firstNode2Edge.end()){
        Msg::Info("Supposed seam point for discreteFace %d", gf->tag());
	seamPoint = true;
	break;
      }
      firstNode2Edge[first] = vecver;
      firstNode2Edge[first].push_back(last);
    }

    while (!firstNode2Edge.empty()&&!seamPoint) {
      std::vector<MVertex*> loop;
      double length = 0.;

      std::map<MVertex*,std::vector<MVertex*> >::iterator in = firstNode2Edge.begin();
      MVertex* previous = in->first;
      while(in != firstNode2Edge.end()) { // it didn't find it
	std::vector<MVertex*> myV = in->second;
	for(unsigned int i=0; i<myV.size(); i++){
	  loop.push_back(previous);
	  MVertex* current = myV[i];
	  length += sqrt( (current->x()-previous->x()) * (current->x()-previous->x()) +
			  (current->y()-previous->y()) * (current->y()-previous->y()) +
			  (current->z()-previous->z()) * (current->z()-previous->z()) );

	  previous = current;
	}
	firstNode2Edge.erase(in);
	in = firstNode2Edge.find(previous);
      }// end while in
      bord.insert(std::make_pair(length,loop));
      // it shouldn't be possible to have twice the same length ? actually, it
      // is possible, but quite seldom #fixme ----> multimap ?
    } // end while firstNode2Edge
  }// end method

  void assign()
  {
    area = 0.;
    seamPoint = false;
    assignVert();
    assignEd2tri();
    assignBord();
  }

  triangulation() : gf(0) {}
  triangulation(std::vector<MElement*> input, GFace* gface)
    : tri(input), gf(gface) { assign(); }
};

// triangles in the physical space xyz, with their parametric coordinates
class  discreteDiskFaceTriangle {
 public:
  std::vector<SPoint3> p; // vertices in (u;v) #improveme std::vector instead
  //SPoint2 gfp[6]; // CAD model
  GFace *gf; // GFace tag
  MElement *tri; // mesh triangle in (x;y;z)
  discreteDiskFaceTriangle() : gf(0), tri(0) {}
};

class discreteDiskFace : public GFace {
  GFace *_parent;
  void buildOct(std::vector<GFace*> *CAD = NULL) const;
  bool parametrize(bool one2one = false) const;
  void putOnView(bool,bool);
  bool checkOrientationUV();
  void printParamMesh();

 public:
  discreteDiskFace(GFace *parent, triangulation* diskTriangulation,
                   int p=1, std::vector<GFace*> *CAD = NULL);
  virtual ~discreteDiskFace();
  void getTriangleUV(const double u,const double v,discreteDiskFaceTriangle **mt,
                     double &_u, double &_v) const;
  GPoint point(double par1, double par2) const;
  SPoint2 parFromVertex(MVertex *v) const;
  SVector3 normal(const SPoint2&) const;
  double curvatureMax(const SPoint2&) const;
  double curvatures(const SPoint2&,SVector3*,SVector3*,double*,double*) const;
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &param,
			 SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const;
  GEntity::GeomType geomType() const { return DiscreteDiskSurface; }
  GPoint intersectionWithCircle(const SVector3 &n1, const SVector3 &n2,
				const SVector3 &p, const double &d,
				double uv[2]) const;

  
  std::vector<MElement*> discrete_triangles;
 protected:
  // a copy of the mesh that should not be destroyed  
  triangulation* initialTriangulation;
  triangulation* geoTriangulation;// parametrized triangulation
  
  std::vector<MVertex*> discrete_vertices;

  int _order;
  int _N;// number of dof's for a triangle
  double _totLength;
  std::map<double,std::vector<MVertex*> > _loops;
  std::vector<MVertex*> _U0; // dirichlet's bc's
  mutable std::set<MVertex*> allNodes;
  mutable std::map<MVertex*, SPoint3> coordinates;
  mutable std::map<SPoint3,SPoint3 > _coordPoints;
  mutable v2t_cont adjv;
  mutable std::map<MVertex*, Pair<SVector3,SVector3> > firstDerivatives;
  mutable discreteDiskFaceTriangle *_ddft;
  mutable Octree *oct;
  mutable std::vector<double> _coords;
};

#endif

#endif
