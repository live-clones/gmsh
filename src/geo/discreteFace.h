// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_FACE_H
#define DISCRETE_FACE_H

#include <algorithm>
#include <cstdint>
#include <functional>
#include <mutex>
#include <unordered_map>
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
    struct TriangleBvhNode {
      double minimum[3] = {0., 0., 0.};
      double maximum[3] = {0., 0., 0.};
      std::size_t begin = 0;
      std::size_t end = 0;
      std::size_t left = 0;
      std::size_t right = 0;
      bool leaf = true;
    };
    struct uvKey {
      double u, v;
      uvKey(double u_, double v_) : u(u_), v(v_) {}
      bool operator==(const uvKey &other) const
      {
        return u == other.u && v == other.v;
      }
    };
    struct uvKeyHash {
      std::size_t operator()(const uvKey &key) const
      {
        const std::size_t first = std::hash<double>()(key.u);
        const std::size_t second = std::hash<double>()(key.v);
        return first ^
          (second + static_cast<std::size_t>(0x9e3779b9U) + (first << 6) +
           (first >> 2));
      }
    };
    MElementOctree *oct;
    mutable RTree<std::pair<MTriangle *, MTriangle *> *, double, 3> rtree3d;
    std::vector<std::pair<MTriangle *, MTriangle *> *> rtree3dData;
    int64_t libolOctree;
    std::vector<double> libolVertexCoordinates;
    std::vector<int32_t> libolTriangles;
    std::vector<std::size_t> libolTriangleToParam;
    std::vector<std::size_t> libolDegenerateTrianglePositions;
    std::vector<std::size_t> triangleBvhPositions;
    std::vector<TriangleBvhNode> triangleBvhNodes;
    mutable std::unordered_map<uvKey, std::size_t, uvKeyHash>
      libolUvTriangleCache;
    mutable std::mutex libolMutex;
    std::vector<MVertex> v2d;
    std::vector<MVertex> v3d;
    std::vector<MTriangle> t2d;
    std::vector<MTriangle> t3d;
    // Flat unit normal of each immutable source triangle. Unlike
    // stl_normals (which are smoothed per vertex), this is the exact normal
    // historically returned by normal() for the corresponding t3d entry.
    std::vector<SVector3> triangleUnitNormals;
    // Immutable uniform accelerator for unambiguous interior UV queries.
    // Boundary/overlap cases deliberately fall back to MElementOctree so
    // the historical triangle-selection semantics remain unchanged.
    std::vector<std::vector<std::size_t> > uvTriangleGrid;
    std::size_t uvTriangleGridResolution = 0;
    double uvTriangleGridMin[2] = {0., 0.};
    double uvTriangleGridMax[2] = {0., 0.};
    double uvTriangleGridTolerance = 0.;
    std::vector<SVector3> CURV;
    double umin, umax, vmin, vmax;
    SBoundingBox3d bbox;
    param()
      : oct(nullptr), libolOctree(0), umin(-1), umax(1), vmin(-1), vmax(1)
    {
    }
    ~param();
    bool empty() const { return t2d.empty(); }
    void clear();
    bool checkPlanar();
  };
  param _param;
  // Face-local UV values are only needed by node tag when distinct boundary
  // nodes are exactly coincident in 3D. In that case parFromPoint() is
  // necessarily ambiguous even though the discrete topology is not.
  std::unordered_map<std::size_t, SPoint2> _coincidentVertexParameters;
  void _createGeometryFromSTL();
  void _buildCoincidentVertexParameters();
  void _buildUvTriangleGrid();
  void _buildTriangleBvh();
  const MTriangle *_findUniqueInteriorUvTriangle(double u, double v) const;
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
  bool parFromCoincidentMeshVertex(const MVertex *vertex,
                                   SPoint2 &param) const;
  Range<double> parBounds(int i) const;
  bool containsParam(const SPoint2 &pt);
  SBoundingBox3d bounds(bool fast = false);
  GPoint closestPoint(const SPoint3 &queryPoint, double maxDistance,
                      SVector3 *normal = nullptr) const;
  GPoint closestPoint(const SPoint3 &queryPoint,
                      const double initialGuess[2]) const;
  // Exact nearest-triangle implementation backed by LibOL. The historical
  // R-tree overload above remains available for controlled A/B comparisons.
  GPoint closestPointLibOL(const SPoint3 &queryPoint,
                           SVector3 *normal = nullptr,
                           const double initialGuess[2] = nullptr) const;
  GPoint closestPointFromTrustedGuess(
    const SPoint3 &queryPoint,
    const double initialGuess[2]) const override;
  SVector3 normal(const SPoint2 &param) const;
  double curvatureMax(const SPoint2 &param) const;
  double curvatures(const SPoint2 &param, SVector3 &dirMax, SVector3 &dirMin,
                    double &curvMax, double &curvMin) const;
  GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual std::pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &param, SVector3 &dudu, SVector3 &dvdv,
                         SVector3 &dudv) const;
  int createGeometry();
  virtual bool haveParametrization() { return !_param.empty(); }
  // Resolve containment and the piecewise-linear surface normal with one
  // parameter-octree lookup. This is exactly equivalent to containsParam()
  // followed by normal() for the same parameter, but avoids searching the
  // immutable discrete support twice in orientation-heavy callers.
  bool normalIfContainsParam(const SPoint2 &param, SVector3 &normal) const;
  // Conservative component bounds for every immutable source-triangle
  // normal whose UV triangle intersects the requested triangle. These bounds
  // let a coarser mesh certify a normal sign without locating the exact MAT
  // triangle; ambiguous signs still fall back to normalIfContainsParam().
  bool normalBoundsForParametricTriangle(const SPoint2 &first,
                                         const SPoint2 &second,
                                         const SPoint2 &third,
                                         SVector3 &minimumNormal,
                                         SVector3 &maximumNormal) const;
  virtual void mesh(bool verbose);
  int trianglePosition(double par1, double par2, double &u, double &v) const;
  GPoint intersectionWithCircle(const SVector3 &n1, const SVector3 &n2,
                                const SVector3 &p, const double &R,
                                double uv[2]);
  // Spatially accelerated variant used by the optimized frontal mesher. The
  // original implementation is intentionally kept for reproducible A/B
  // comparisons with algorithm 6.
  GPoint intersectionWithCircleSpatial(const SVector3 &n1,
                                       const SVector3 &n2,
                                       const SVector3 &p, const double &R,
                                       double uv[2]);
  bool writeParametrization(FILE *fp, bool binary);
  bool readParametrization(FILE *fp, bool binary);
  virtual void resetMeshAttributes();
};

#endif
