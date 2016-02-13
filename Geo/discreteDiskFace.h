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

class ANNkd_tree;
class Octree;
class GRbf;


class  discreteDiskFaceTriangle {
 public:
  SPoint3 p1, p2, p3; // vertices in (u;v)
  SPoint2 gfp1, gfp2, gfp3; // CAD model
  SPoint3 v1, v2, v3; // vertices in (x;y;z)
  GFace *gf; // GFace tag
  MTriangle *tri; // mesh triangle in (x;y;z)
 discreteDiskFaceTriangle() : gf(0), tri(0) {}
};

// --------------------

class discreteDiskFace : public GFace {
  GFace *_parent;
  //  bool checkOrientation(int iter, bool moveBoundaries=false) const; // mark todo
  void buildOct() const;
  bool parametrize() const;
  void buildAllNodes() ;
  void getBoundingEdges();
  void putOnView();
 public:
  discreteDiskFace(GFace *parent, std::vector<MTriangle*> &mesh);
  virtual ~discreteDiskFace() {triangles.clear();}
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
 protected:
  //------------------------------------------------
  // a copy of the mesh that should not be destroyed
  std::vector<MTriangle*> discrete_triangles;
  std::vector<MVertex*> discrete_vertices;
  //------------------------------------------------
  double _totLength;
  std::map<double,std::vector<MVertex*> > _loops;
  std::vector<MVertex*> _U0; // dirichlet's bc's
  mutable std::set<MVertex*> allNodes;
  mutable std::map<MVertex*, SPoint3> coordinates;
  mutable std::map<SPoint3,SPoint3 > _coordPoints; // ?
  mutable v2t_cont adjv; // ? v2t_cont ? ?????
  mutable std::map<MVertex*, Pair<SVector3,SVector3> > firstDerivatives;
  mutable std::map<MElement*, Pair<SVector3,SVector3> > firstElemDerivatives;
  mutable discreteDiskFaceTriangle *_ddft;
  mutable ANNkd_tree *uv_kdtree;
  mutable ANNkd_tree *kdtree;
  mutable Octree *oct;
  mutable std::vector<double> _coords;

};

#endif

#endif
