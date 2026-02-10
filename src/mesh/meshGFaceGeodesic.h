#ifndef _MESHGFACEGEODESIC_H_
#define _MESHGFACEGEODESIC_H_

#include "SVector3.h"
#include "geodesic_mesh_elements.h"
#include "meshPolyMesh.h"
#include "geodesic_mesh.h"
#include "geodesic_algorithm_exact.h"
#include "GModel.h"
#include <array>
#include <functional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#define ANGLECRIT 2

// struct EdgeQualityArgs {
//   double intrinsicLength;
//   size_t numPoints;
//   double **coord;
//   double result;
// };
double edgeQualityDefault(const double, const double *, const size_t);

// struct TriangleQualityArgs {
//   double *intrinsicAngles;
//   double *intrinsicLengths;
//   size_t *nbrEdgePoints;
//   double **edgePointsCoods;
//   double result;
// };
double triangleQualityDefault(const double *intrinsicAngles,
                              const size_t intrinsicAngles_n,
                              const double *intrinsicLengths,
                              const size_t intrinsicLengths_n,
                              const size_t *numPoints, const size_t numPoints_n,
                              const double *edgesCoord,
                              const size_t edgesCoord_n);

int makeMeshGeodesic(GModel *gm);
PolyMesh *createPolyMesh(const std::vector<double> &p,
                         const std::vector<size_t> &t,
                         const std::vector<size_t> &e = {},
                         const std::vector<size_t> &vertexNum = {});

struct pair_hash {
  std::size_t operator()(const std::pair<int, int> &p) const
  {
    return (static_cast<std::size_t>(p.first) << 32) |
           static_cast<unsigned int>(p.second);
  }
};

#include <vector>
#include <cstdint>
#include <cassert>

struct PathView {
  geodesic::SurfacePoint *ptr;
  size_t length;
  bool _reverse;

  PathView() {};
  PathView(std::vector<geodesic::SurfacePoint> &v, bool reverse = false)
    : _reverse(reverse)
  {
    if(v.empty()) {
      ptr = nullptr;
      length = 0;
    }
    else {
      ptr = v.data();
      length = v.size();
    }
  }

  PathView(PathView &pv, bool reverse) : _reverse(reverse)
  {
    if(pv.ptr == nullptr) {
      ptr = nullptr;
      length = 0;
    }
    else {
      ptr = pv.ptr;
      length = pv.length;
    }
  }
  geodesic::SurfacePoint &front() const
  {
    assert(length > 0);
    if(_reverse)
      return ptr[length - 1];
    else
      return ptr[0];
  }

  geodesic::SurfacePoint &back() const
  {
    assert(length > 0);
    if(_reverse)
      return ptr[0];
    else
      return ptr[length - 1];
  }

  // Accessors
  size_t size() const { return length; }
  bool empty() const { return length == 0; }
  geodesic::SurfacePoint &operator[](size_t i) const
  {
    if(_reverse)
      return ptr[length - 1 - i];
    else
      return ptr[i];
  }

  // Iterator support
  struct Iterator {
    geodesic::SurfacePoint *p;
    bool r;
    geodesic::SurfacePoint &operator*() const { return *p; }
    Iterator &operator++()
    {
      if(r)
        --p;
      else
        ++p;
      return *this;
    }
    bool operator!=(const Iterator &other) const { return p != other.p; }
  };

  Iterator begin() const { return {ptr, _reverse}; }
  Iterator end() const { return {ptr + length, _reverse}; }
};

struct EdgeItem {
  std::pair<int, int> edge;
  double adimLength;
  EdgeItem(std::pair<int, int> e, double l) : edge(e), adimLength(l) {}
  bool operator<(const EdgeItem &other) const
  {
    return adimLength < other.adimLength;
  }
  bool operator>(const EdgeItem &other) const
  {
    return adimLength > other.adimLength;
  }
  bool operator==(const EdgeItem &other) const
  {
    return (edge.first == other.edge.first &&
            edge.second == other.edge.second) ||
           (edge.first == other.edge.second &&
            edge.second == other.edge.first); // if edges are undirected
  }
};
struct HEdgeItem {
  PolyMesh::HalfEdge *he;
  double adimLength;
  HEdgeItem(PolyMesh::HalfEdge *hedge, double l) : he(hedge), adimLength(l) {}
  bool operator<(const HEdgeItem &other) const
  {
    return adimLength < other.adimLength;
  }
  bool operator>(const HEdgeItem &other) const
  {
    return adimLength > other.adimLength;
  }
  bool operator==(const HEdgeItem &other) const
  {
    return (
      he == other.he ||
      (he->opposite && he->opposite == other.he)); // if edges are undirected
  }
};

struct TriangleItem {
  int index;
  double quality;
  TriangleItem() {}
  TriangleItem(int i, double q) : index(i), quality(q) {}
  bool operator<(const TriangleItem &other) const
  {
    return quality < other.quality;
  }
  bool operator>(const TriangleItem &other) const
  {
    return quality > other.quality;
  }
  bool operator==(const TriangleItem &other) const
  {
    return index == other.index;
  }
};

namespace std {
  template <> struct hash<EdgeItem> {
    size_t operator()(const EdgeItem &e) const noexcept
    {
      // simple combination of the two ints
      size_t h1 = std::hash<int>{}(e.edge.first);
      size_t h2 = std::hash<int>{}(e.edge.second);
      return h1 ^ (h2 << 1); // combine the two hashes
    }
  };

  template <> struct hash<TriangleItem> {
    size_t operator()(const TriangleItem &t) const noexcept
    {
      return std::hash<int>{}(t.index);
    }
  };

  template <> struct hash<std::array<int, 3>> {
    size_t operator()(const std::array<int, 3> &a) const noexcept
    {
      size_t h1 = hash<int>{}(a[0]);
      size_t h2 = hash<int>{}(a[1]);
      size_t h3 = hash<int>{}(a[2]);
      return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
  };

} // namespace std

enum class PointType { Unused, Vertex, Circumcenter };

class TypedPoints {
public:
  TypedPoints() = default;

  geodesic::SurfacePoint &operator[](size_t idx)
  {
    if(idx >= points.size())
      throw std::out_of_range(
        "SurfacePointPool::operator[] index out of range");
    return points[idx];
  }

  PointType type(size_t i) { return types[i]; };

  size_t size() { return points.size(); }
  void resize(size_t size)
  {
    points.resize(size);
    types.resize(size);
  }

  void remove(size_t i) { types[i] = PointType::Unused; }
  void push_back(const geodesic::SurfacePoint &p)
  {
    points.push_back(p);
    types.push_back(PointType::Vertex);
  }
  void insertCircumcenter(const geodesic::SurfacePoint &p)
  {
    points.push_back(p);
    types.push_back(PointType::Circumcenter);
  }
  bool convertToVertex(const size_t i)
  {
    for(int j = 0; j < points.size(); ++j) {
      if(type(j) != PointType::Vertex) continue;
      if(norm(SVector3(points[i].xyz(), points[j].xyz())) < 1e-10) {
        Msg::Warning("A vertex already exists at this location");
        return false;
      }
    }
    if(types[i] != PointType::Circumcenter)
      throw std::runtime_error(
        "Try to convert to vertex a point that is not a circumcenter (" +
        std::to_string(static_cast<int>(types[i])) + ")");
    types[i] = PointType::Vertex;
    return true;
  }
  void convertToCircumcenter(const size_t i)
  {
    if(types[i] != PointType::Vertex)
      throw std::runtime_error(
        "Try to convert to circumcenter a point that is not a vertex (" +
        std::to_string(static_cast<int>(types[i])) + ")");
    types[i] = PointType::Circumcenter;
  }
  void swap(size_t i, size_t j)
  {
    std::swap(points[i], points[j]);
    std::swap(types[i], types[j]);
  }

  TypedPoints &operator=(const std::vector<geodesic::SurfacePoint> &other)
  {
    points = other; // copy the vector contents
    types.clear();
    types.resize(points.size(), PointType::Vertex);
    return *this;
  }

  operator std::vector<geodesic::SurfacePoint>() const
  {
    return points; // just copy the internal vector
  }

private:
  std::vector<geodesic::SurfacePoint> points;
  std::vector<PointType> types;
};

class highOrderPolyMesh {
  int maxTag;

public:
  PolyMesh *pm; // Background mesh
  PolyMesh *ipm; // Intrinsic mesh
  geodesic::Mesh geoMesh; // geometric mesh
  TypedPoints pointsPool; // points of the IGA
  std::map<std::pair<int, int>, int> tags; // edge <a b>, triangles
  std::unordered_map<std::pair<int, int>, std::vector<size_t>, pair_hash>
    edges; // edge <a b>, triangles
  std::unordered_map<std::pair<int, int>, std::vector<geodesic::SurfacePoint>,
                     pair_hash>
    geodesics; // one geodesic per edge
  std::vector<std::vector<std::pair<int, int>>> vertexGeodesics;
  std::unordered_map<int, std::vector<std::array<int, 3>>> vertexTriangles;
  std::vector<int> triangles; // 3 integers per triangle
  std::map<PolyMesh::Face *, int> f2n;
  std::map<PolyMesh::Vertex *, std::vector<int>> pvtags;
  std::map<PolyMesh::Vertex *, std::vector<std::pair<PolyMesh::Vertex *, int>>>
    pvvtags;
  std::map<PolyMesh::Face *, std::vector<int>> fvs;
  std::map<PolyMesh::HalfEdge *, std::vector<int>> evs;
  std::map<int, int> _saddle;
  std::vector<double> characLength;
  std::vector<double> characLengthMin;
  std::vector<double> characLengthMax;
  std::unordered_map<std::pair<int, int>, double, pair_hash> lengths;
  std::unordered_map<std::pair<int, int>, double, pair_hash> adimLengths;
  std::vector<geodesic::GeodesicAlgorithmExact> algorithms;
  // std::map<geodesic::SurfacePoint *, PolyMesh::Vertex *> sp2pv;
  std::map<size_t, size_t> sp2pv;
  std::unordered_map<std::array<int, 3>, std::pair<size_t, double>>
    circumIndexRadius;
  std::set<std::pair<int, int>> delaunayEdges;
  static std::function<double(const double, const double *, const size_t)>
    edgeQualityPtr;
  static std::function<double(const double *, const size_t, const double *,
                              const size_t, const size_t *, const size_t,
                              const double *, const size_t)>

    triangleQualityPtr;
  unsigned iter;

  highOrderPolyMesh(PolyMesh *pm, std::vector<size_t> &tris);
  highOrderPolyMesh(PolyMesh *pm);
  ~highOrderPolyMesh()
  {
    if(ipm) delete ipm;
  }
  PolyMesh *cutMesh(std::vector<PolyMesh::Vertex *> &pointVertices);
  void setGeodesic(std::pair<int, int> edge,
                   std::vector<geodesic::SurfacePoint> &path);
  void createGeodesics(geodesic::SurfacePoint &pt_start,
                       std::vector<geodesic::SurfacePoint> &pts_end,
                       std::vector<std::vector<geodesic::SurfacePoint>> &paths);
  void
  createGeodesics(std::vector<geodesic::SurfacePoint> &pt_start,
                  std::vector<std::vector<geodesic::SurfacePoint>> &pts_end,
                  std::vector<std::vector<geodesic::SurfacePoint>> &paths);
  void createGeodesicsInParallel(std::vector<std::pair<int, int>> edges,
                                 bool reorder = true);
  void createInitialGeodesics();
  void createGeodesics();
  void getGeodesicPath(int p0, int p1, PathView &path);
  void getPath(PolyMesh::HalfEdge *he, PathView &path);
  void getPath(std::pair<int, int> edge, PathView &path);
  void printGeodesics(const char *fn);
  void enforceBoundary();

  double computeIntrinsicAngle(int p0, int p1, int p2);

  void createCircumcenter(std::vector<geodesic::SurfacePoint> &pts,
                          geodesic::SurfacePoint &circumcenter,
                          double &circumradius);
  void
  createCircumcenters(std::vector<std::vector<geodesic::SurfacePoint>> &pts,
                      std::vector<geodesic::SurfacePoint> &circumcenters,
                      std::vector<double> &circumradii);
  void triangulateCavity(std::vector<size_t> &indices,
                         std::vector<size_t> &triangles);
  void getCircumcenter(int t, size_t &circumindex, double &circumradius);
  void getCircumcenter(std::array<int, 3> &tri, size_t &circumindex,
                       double &circumradius);
  size_t setCircumcenter(std::array<int, 3> &tri,
                         geodesic::SurfacePoint &circumcenter,
                         double circumradius);

  bool intersectGeodesicPath(
    PathView &p0, PathView &p1, SVector3 &intersection,
    std::unordered_map<geodesic::Face *, size_t> *faceSegments = nullptr,
    std::unordered_map<geodesic::Vertex *, std::array<size_t, 2>>
      *vertexSegments = nullptr);

  void removePoint(size_t i);

  bool doWeSplit(PolyMesh::HalfEdge *he, double MAXE);
  void write(const PolyMesh *pm_new,
             std::vector<PolyMesh::Vertex *> &pointVertices);

  void precomputeCircumcenters();

  bool symbolicSwapEdges(std::vector<size_t> &newTris,
                         std::vector<size_t> &cavity, bool propagate = true);
  bool swapEdge(PolyMesh::HalfEdge *he,
                std::vector<PolyMesh::HalfEdge *> &adjacentEdges,
                int OPTION = ANGLECRIT);
  void removeAdjacency(std::vector<size_t> &trigls);
  void addAdjacency(std::vector<size_t> &trigls);
  void doSwapEdge(PolyMesh::HalfEdge *he);
  void getOppEdge(const std::pair<int, int> &p01, std::pair<int, int> &p23,
                  std::pair<int, int> &ts);
  bool doWeSwapAngleHeuristic(int p0, int p1, int p2, int p3);
  bool doWeSwapLengthHeuristic(int p0, int p1, int p2, int p3);
  bool locallyDelaunay(size_t circumindex, double circumradius,
                       size_t oppVertex);
  bool canWeSwap(const std::pair<int, int> &edge,
                 const std::pair<int, int> &oppEdge, PathView &p01,
                 PathView &p23, std::array<PathView, 4> &borderPaths);
  bool checkNewTriangles(std::vector<size_t> newTris);
  bool doWeSwap(const std::pair<int, int> &edge, std::pair<int, int> &opp,
                PathView &p01, PathView &p23, std::array<PathView, 4> &borders,
                int OPTION = ANGLECRIT);
  bool doWeSwapIntrinsic(const std::pair<int, int> &p01,
                         std::pair<int, int> &p23);
  int swapEdges(int OPTION = ANGLECRIT);

  void meshAdapt(int niter, double MINE, double MAXE, double MINA, double MAXA,
                 std::set<size_t> &keepSet);

  int intrinsicTriangulate();

  int getDelaunay(std::vector<geodesic::SurfacePoint> &points,
                  std::vector<int> &triangles,
                  std::vector<geodesic::SurfacePoint> &circumcenters,
                  std::vector<double> &circumradii);

  bool splitEdge(PolyMesh::HalfEdge *, double MINA, double MAXA,
                 std::vector<PolyMesh::HalfEdge *> &adjacentEdges);
  int splitEdges(const double MAXE, double MINA, double MAXA = 1e100);

  char outTriangleFast(int circumindex, int t);
  bool splitTriangle(int iTriangle, double MINA, double MAXA,
                     std::set<int> &skipTriangles,
                     std::vector<TriangleItem> removedTriangles,
                     std::vector<TriangleItem> &adjacentTriangles);
  int splitTriangles(double MAXE);

  bool collapseEdge(PolyMesh::HalfEdge *he, std::set<size_t> keep,
                    std::vector<HEdgeItem> &adjacentEdges,
                    // std::vector<std::pair<int,int>> &removedEdges,
                    std::vector<HEdgeItem> &removedEdgeItems, double MINA = 0,
                    double MAXA = 1e100);
  bool canWeCollapse(std::vector<PathView> &newPaths,
                     std::vector<PathView> &borderPaths,
                     std::vector<geodesic::SurfacePoint> &borderPath,
                     double &minAngle, double &maxAngle);
  double getEdgeQuality(std::pair<int, int> e);
  double getTriangleQuality(size_t tri[3]);
  bool doWeCollapse(double minAngleBefore, double maxAngleBefore,
                    std::vector<size_t> &newTris, double minHeuristicAngle,
                    double maxHeuristicAngle);
  void doCollapseEdge(std::pair<int, int> &edge, size_t index,
                      std::vector<size_t> &cavity, std::vector<size_t> &newTris,
                      std::vector<HEdgeItem> &removedEdgeItems,
                      std::vector<HEdgeItem> &adjacentEdges);
  void cleanAfterCollapse(std::set<size_t> &keep);
  bool doWeCollapse(PolyMesh::HalfEdge *he, double MINE);
  int collapseEdges(const double MINE, double MINA, double MAXA,
                    std::set<size_t> &keep);

  SPoint3 getTrueCoords(geodesic::SurfacePoint &sp);
  double cl(geodesic::SurfacePoint &sp);
  double clMin(geodesic::SurfacePoint &sp);
  double clMax(geodesic::SurfacePoint &sp);
  bool sanityCheck();
  double length(std::pair<int, int> edge);
  double adimLength(std::pair<int, int> edge);
  double length(PolyMesh::HalfEdge *he);
  double adimLength(PolyMesh::HalfEdge *he);
  double adimLengthMin(PolyMesh::HalfEdge *he);
  double adimLengthMax(PolyMesh::HalfEdge *he);
  double adimLength(std::vector<geodesic::SurfacePoint> &path);
  double adimLength(PathView &path);
  double adimLengthMin(PathView &path);
  double adimLengthMax(PathView &path);

private:
  int getTag(const std::pair<int, int> &e2);
  SVector3 normal(geodesic::base_pointer b);
  SVector3 normal(int p);
  double computeAngle(SVector3 v01, SVector3 v02);
  double computeIntrinsicAngle(geodesic::SurfacePoint &p0,
                               geodesic::SurfacePoint &p1,
                               geodesic::SurfacePoint &p2);
  double computeIntrinsicAngle(PathView &p01, PathView &p20);
  double computeAngle(SVector3 v01, SVector3 v02, SVector3 n);
  double computeAngle(PathView &p01, PathView &p20, SVector3 n);
  double computeAngle(int p0, int p1, int p2, SVector3 n, int boundary10 = 0,
                      int boundary12 = 0);
  double computeAngleTrue(int p0, int p1, int p2);
  bool edgeValid(int p0, int p1, int p2, int p3);
  void addVertexOnSurface(PolyMesh::Face *f, int v);
  void addVertexOnEdge(PolyMesh::HalfEdge *e, int v);
  void addPolyMeshVertexTag(PolyMesh::Vertex *v, int tag);
  void addPolyMeshVertexVertexTag(PolyMesh::Vertex *v, PolyMesh::Vertex *w,
                                  int tag);
  void classifyGeodesic(std::pair<int, int> pair, const PathView &p, int i0,
                        int i1);
  void classifyGeodesicVertices(std::vector<PolyMesh::Vertex *> &pointVertices);
  double length(PathView &path);
  void setLength(std::pair<int, int> edge, double length);
  void setAdimLength(std::pair<int, int> edge, double length);
  std::vector<size_t> &adjacentTriangles(std::pair<int, int> edge);
  void splitPath(PathView &path, const double length,
                 std::vector<geodesic::SurfacePoint> &firstHalf,
                 std::vector<geodesic::SurfacePoint> &secondHalf);
  void getBoundaryPath(int p0, int p1, PathView &path);
  void getPath(std::pair<int, int> edge, int boundaryOrientation,
               PathView &path);
  int getBoundaryOrientation(std::pair<int, int> edge);
  double edgeQuality(double intrinsicLength, size_t nbrEdgePoints,
                     double **edgePointsCoods);
};

void saveIsoTriangles(int num, std::vector<int> &hopTriangles,
                      TypedPoints &hopPoints, PolyMesh *ipm);
void printCuttedMesh(PolyMesh *pm, std::map<int, int> colors = {});
bool colorFaces(PolyMesh *pm, std::map<int, int> &face2Colors,
                int maxColor = 4);
void intrinsicTriangulation(geodesic::GeodesicAlgorithmExact &algorithm,
                            geodesic::Mesh &geoMesh,
                            std::vector<geodesic::SurfacePoint> &points,
                            std::vector<int> &triangles,
                            std::vector<geodesic::SurfacePoint> &circumcenters,
                            std::vector<double> &circumradii, bool print);

#endif
