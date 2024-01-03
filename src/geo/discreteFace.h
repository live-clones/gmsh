// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_FACE_H
#define DISCRETE_FACE_H

#include <algorithm>
#include "GModel.h"
#include "GFace.h"
#include "MTriangle.h"
#include "SBoundingBox3d.h"
#include "rtree.h"

class MElementOctree;

class discreteFace : public GFace {
private:
  class param {
  public:
    MElementOctree *oct;
    mutable RTree<std::pair<MTriangle *, MTriangle *> *, double, 3> rtree3d;
    std::vector<std::pair<MTriangle *, MTriangle *> *> rtree3dData;
    std::vector<MVertex> v2d;
    std::vector<MVertex> v3d;
    std::vector<MTriangle> t2d;
    std::vector<MTriangle> t3d;
    std::vector<SVector3> CURV;
    double umin, umax, vmin, vmax;
    SBoundingBox3d bbox;
    param() : oct(nullptr), umin(-1), umax(1), vmin(-1), vmax(1) {}
    ~param();
    bool empty() const { return t2d.empty(); }
    void clear();
    bool checkPlanar();
  };
  param _param;
  void _createGeometryFromSTL();
  void _computeSTLNormals();
  void _debugParametrization(bool uv);

public:
  discreteFace(GModel *model, int num);
  discreteFace(GModel *model);
  virtual ~discreteFace() {}
  using GFace::point;
  GPoint point(double par1, double par2) const;
  SPoint2 parFromPoint(const SPoint3 &p, bool onSurface = true,
                       bool convTestXYZ = false) const;
  Range<double> parBounds(int i) const;
  bool containsParam(const SPoint2 &pt);
  SBoundingBox3d bounds(bool fast = false);
  GPoint closestPoint(const SPoint3 &queryPoint, double maxDistance,
                      SVector3 *normal = nullptr) const;
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
  int createGeometry();
  virtual bool haveParametrization() { return !_param.empty(); }
  virtual void mesh(bool verbose);
  int trianglePosition(double par1, double par2, double &u, double &v) const;
  GPoint intersectionWithCircle(const SVector3 &n1, const SVector3 &n2,
                                const SVector3 &p, const double &R,
                                double uv[2]);
  bool writeParametrization(FILE *fp, bool binary);
  bool readParametrization(FILE *fp, bool binary);
  virtual void resetMeshAttributes();
};

#endif
