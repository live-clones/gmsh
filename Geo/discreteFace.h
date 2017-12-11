// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DISCRETE_FACE_H_
#define _DISCRETE_FACE_H_

#include "GmshConfig.h"
#include "GModel.h"
#include "GFace.h"
#include "discreteEdge.h"
#include "MEdge.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "MLine.h"

#if defined(HAVE_HXT)
class MElementOctree;
extern "C" {
#include "hxt_mesh.h"
#include "hxt_parametrization.h"
#include "hxt_linear_system.h"
}
class hxt_reparam_surf {
public:
  MElementOctree *oct;
  std::vector<MVertex>   v2d;
  std::vector<MVertex>   v3d;
  std::vector<MTriangle> t2d;
  std::vector<MTriangle> t3d;
  std::vector<discreteEdge*> bnd;
  hxt_reparam_surf ():oct(NULL) {}
  ~hxt_reparam_surf () ;
};
#else
class discreteDiskFace;
class triangulation;
#endif

class discreteFace : public GFace {
 private:
  void checkAndFixOrientation();
  bool _meshable;
  void splitDiscreteEdge(GEdge*,GVertex*,discreteEdge*[2]);
  void setupDiscreteVertex(GVertex*,MVertex*,std::set<MVertex*>*);
  void setupDiscreteEdge(discreteEdge*,std::vector<MLine*>,std::set<MVertex*>*);

#ifdef HAVE_HXT
  int _current_parametrization;
  std::vector< hxt_reparam_surf > _parametrizations;
  HXTStatus reparametrize_through_hxt ();
  bool compute_topology_of_partition (int nbColors,
				      int *colors,
				      int *nNodes,
				      int *nodes,
				      double *uv,
				      std::vector<MVertex*> &c2v,
				      std::vector<std::vector<MEdge> > &boundaries);
#else
  void gatherMeshes();
  void updateTopology(std::vector<triangulation*>&);
  std::vector<discreteDiskFace*> _atlas;
  std::map<MEdge,std::vector<int>,Less_Edge> allEdg2Tri;
  void fillHoles(triangulation*);
  void split(triangulation*,std::vector<triangulation*>&,int);
  void addTriangle(triangulation*,MTriangle*);
#endif
  
 public:
  discreteFace(GModel *model, int num, bool meshable=false);
  virtual ~discreteFace() {}
  using GFace::point;
  GPoint point(double par1, double par2) const;
  SPoint2 parFromPoint(const SPoint3 &p, bool onSurface=true) const;
  SVector3 normal(const SPoint2 &param) const;
  double curvatureMax(const SPoint2 &param) const;
  double curvatures(const SPoint2 &param, SVector3 *dirMax, SVector3 *dirMin,
                                  double *curvMax, double *curvMin) const;
  GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &param,
                         SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const;
  void writeGEO(FILE *fp);
  void createGeometry();
  virtual void mesh(bool verbose);
  void setBoundEdges(const std::vector<int> &tagEdges);
  void setBoundEdges(const std::vector<int> &tagEdges,
                     const std::vector<int> &signEdges);
};

#endif
