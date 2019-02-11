// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _DISCRETE_FACE_H_
#define _DISCRETE_FACE_H_

#include "GmshConfig.h"
#include "GModel.h"
#include "GFace.h"
#include "discreteVertex.h"
#include "discreteEdge.h"
#include "MTriangle.h"
#include "MElementCut.h"
#include "MEdge.h"
#include "MLine.h"

#if defined(HAVE_HXT)
#include <algorithm>
#include "rtree.h"
class MElementOctree;
extern "C" {
#include "hxt_mesh.h"
#include "hxt_parametrization.h"
#include "hxt_linear_system.h"
#include "hxt_curvature.h"
}
class hxt_reparam_surf {
public:
  MElementOctree *oct;
  mutable RTree<std::pair<MTriangle *, MTriangle *> *, double, 3> rtree3d;
  std::vector<MVertex> v2d;
  std::vector<MVertex> v3d;
  std::vector<MTriangle> t2d;
  std::vector<MTriangle> t3d;
  std::vector<discreteEdge *> bnd;
  std::vector<discreteEdge *> emb;
  hxt_reparam_surf() : oct(NULL) {}
  ~hxt_reparam_surf();
};
#endif

class discreteFace : public GFace {
private:
  void checkAndFixOrientation();

#if defined(HAVE_HXT)
  int _current_parametrization;
  std::vector<hxt_reparam_surf> _parametrizations;
  std::vector<discreteEdge *> e_internals;
  std::vector<discreteVertex *> v_internals;
  HXTStatus reparametrize_through_hxt();
  bool
  compute_topology_of_partition(int nbColors, int *colors, int *nNodes,
                                int *nodes, double *uv, double angle_threshold,
                                std::vector<MVertex *> &c2v,
                                std::vector<std::vector<MEdge> > &boundaries,
                                std::vector<std::vector<MEdge> > &internals);
#endif

public:
  discreteFace(GModel *model, int num);
  virtual ~discreteFace() {}
  using GFace::point;
  GPoint point(double par1, double par2) const;
  SPoint2 parFromPoint(const SPoint3 &p, bool onSurface = true) const;
  GPoint closestPoint(const SPoint3 &queryPoint, double maxDistance,
                      SVector3 *normal = NULL) const;
  GPoint closestPoint(const SPoint3 &queryPoint,
                      const double initialGuess[2]) const;
  SVector3 normal(const SPoint2 &param) const;
  double curvatureMax(const SPoint2 &param) const;
  double curvatures(const SPoint2 &param, SVector3 &dirMax, SVector3 &dirMin,
                    double &curvMax, double &curvMin) const;
  GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &param, SVector3 &dudu, SVector3 &dvdv,
                         SVector3 &dudv) const;
  void createGeometry();
  virtual bool haveParametrization()
  {
#if defined(HAVE_HXT)
    return !_parametrizations.empty();
#else
    return false;
#endif
  }
  virtual void mesh(bool verbose);
  void setBoundEdges(const std::vector<int> &tagEdges);
  void setBoundEdges(const std::vector<int> &tagEdges,
                     const std::vector<int> &signEdges);
  int trianglePosition(double par1, double par2, double &u, double &v) const;
  GPoint intersectionWithCircle(const SVector3 &n1, const SVector3 &n2,
                                const SVector3 &p, const double &R,
                                double uv[2]);
};

#endif
