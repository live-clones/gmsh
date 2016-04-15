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

class ANNkd_tree;
class Octree;
class GRbf;


class  discreteDiskFaceTriangle {
 public:
  SPoint3 p[6]; // vertices in (u;v) #improveme std::vector instead
  //SPoint2 gfp[6]; // CAD model
  GFace *gf; // GFace tag
  MTriangle *tri; // mesh triangle in (x;y;z)
 discreteDiskFaceTriangle() : gf(0), tri(0) {}
};

// --------------------

class discreteDiskFace : public GFace {
  GFace *_parent;
  void buildOct() const;
  bool parametrize(bool one2one = false) const;
  void buildAllNodes() ;
  void getBoundingEdges();
  void putOnView();
  bool checkOrientationUV();
  
 public:
  discreteDiskFace(GFace *parent, std::vector<MTriangle*> &mesh, int p=1);// MTriangle -> MTriangle 6
  virtual ~discreteDiskFace();
  void getTriangleUV(const double u,const double v,discreteDiskFaceTriangle **mt, double &_u, double &_v) const;
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
 protected:
  //------------------------------------------------
  // a copy of the mesh that should not be destroyed
  std::vector<MTriangle*> discrete_triangles; 
  std::vector<MVertex*> discrete_vertices;
  //------------------------------------------------
  int nodeLocalNum(MElement* e, MVertex* v) const{
    for(int i=0; i<e->getNumVertices(); i++)
      if (v == e->getVertex(i))
	return i;
    return -1;
  }
  int edgeLocalNum(MElement* e, MEdge ed) const{
    for(int i=0; i<e->getNumEdges(); i++)
      if (ed == e->getEdge(i))
	return i;
    return -1;
  }
  //------------------------------------------------
  int _order;
  int _N;
  double _totLength;
  std::map<double,std::vector<MVertex*> > _loops;
  std::vector<MVertex*> _U0; // dirichlet's bc's
  mutable std::set<MVertex*> allNodes;
  mutable std::map<MVertex*, SPoint3> coordinates;
  mutable std::map<SPoint3,SPoint3 > _coordPoints; // ?
  mutable v2t_cont adjv; // ? v2t_cont ? ?????
  mutable std::map<MVertex*, Pair<SVector3,SVector3> > firstDerivatives;
  mutable discreteDiskFaceTriangle *_ddft;
  mutable Octree *oct;
  mutable std::vector<double> _coords;
  //  const nodalBasis* mynodalbasis;
};

#endif

#endif
