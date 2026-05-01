#ifndef _MESHGFACEGEODESIC_H_
#define _MESHGFACEGEODESIC_H_

#include "SVector3.h"
#include "geodesic_mesh_elements.h"
#include "meshPolyMesh.h"
#include "geodesic_mesh.h"
#include "geodesic_algorithm_exact.h"
#include "GModel.h"
#include <algorithm>
#include <array>
#include <functional>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

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
  inline std::size_t operator()(const std::pair<int, int> &p) const
  {
    return (static_cast<std::size_t>(p.first) << 32) |
           static_cast<unsigned int>(p.second);
  }

  inline std::size_t operator()(const std::pair<size_t, size_t> &v) const
  {
    // LLM suggestion
    std::size_t seed = v.first;
    seed ^= v.second + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
  }
};

#include <vector>
#include <cassert>

struct PathView {
  geodesic::SurfacePoint *ptr = nullptr;
  size_t length = 0;
  bool _reverse = false;

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

  PathView(PathView &pv, bool reverse)
  {
    if(pv.ptr == nullptr) {
      ptr = nullptr;
      length = 0;
      _reverse = false;
    }
    else {
      ptr = pv.ptr;
      length = pv.length;
      _reverse = reverse != pv._reverse;
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

  bool operator!=(const PathView &other) const
  {
    return (other.ptr != ptr || other.length != length ||
            other._reverse != _reverse);
  }
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

// TriMesh CLASS
class TriMesh {
public:
  static constexpr size_t NONE = std::numeric_limits<size_t>::max();

  std::vector<size_t> vertices;
  std::vector<size_t> opposites;
  std::unordered_map<std::pair<size_t, size_t>, size_t, pair_hash> boundary;

  inline size_t &vertex(size_t he) { return vertices[he]; }
  inline size_t &opposite(size_t he) { return opposites[he]; }

  inline size_t vertex(size_t he) const { return vertices[he]; }
  inline size_t opposite(size_t he) const { return opposites[he]; }
  inline size_t size() const { return vertices.size() / 3; }
  inline size_t face(size_t he) const { return he / 3; }
  inline size_t face_he(size_t face) const { return 3 * face; }
  inline size_t next(size_t he) const
  {
    return (he % 3 == 2) ? he - 2 : he + 1;
  }
  inline size_t prev(size_t he) const
  {
    return (he % 3 == 0) ? he + 2 : he - 1;
  }
  inline size_t rotate_ccw(size_t he) const
  {
    if(opposites[he] != NONE)
      return next(opposite(he));
    else {
      he = prev(he);
      while(opposite(he) != NONE) he = prev(opposite(he));
      return next(he);
    }
  }

  size_t add_face(size_t v0, size_t v1, size_t v2)
  {
    size_t he = vertices.size();
    vertices.push_back(v0);
    vertices.push_back(v1);
    vertices.push_back(v2);
    opposites.push_back(NONE);
    opposites.push_back(NONE);
    opposites.push_back(NONE);

    // Find opposites
    for(int i = 0; i < 3; ++i, he = next(he)) {
      size_t start = vertex(he);
      size_t end = vertex(next(he));
      std::pair<size_t, size_t> key = {std::min(start, end),
                                       std::max(start, end)};
      auto it = boundary.find(key);
      if(it == boundary.end()) {
        boundary[key] = he;
        continue;
      }

      opposite(he) = it->second;
      opposite(it->second) = he;
      boundary.erase(it);
    }

    return face(he);
  }

  void remove_face(size_t face)
  {
    size_t he = face_he(face);
    // Remove opposites
    for(int i = 0; i < 3; ++i, he = next(he)) {
      size_t start = vertex(he);
      size_t end = vertex(next(he));
      std::pair<size_t, size_t> key = {std::min(start, end),
                                       std::max(start, end)};
      size_t opp = opposite(he);
      if(opp != NONE) {
        opposite(opp) = NONE;
        boundary[key] = opp;
      }
      else
        boundary.erase(key);
    }

    vertices[he] = NONE;
    vertices[he + 1] = NONE;
    vertices[he + 2] = NONE;
    opposites[he] = NONE;
    opposites[he + 1] = NONE;
    opposites[he + 2] = NONE;
  }

  inline void set_boundary(size_t he)
  {
    size_t start = vertex(he);
    size_t end = vertex(next(he));
    std::pair<size_t, size_t> key = {std::min(start, end),
                                     std::max(start, end)};
    boundary[key] = he;
  }

  void swap(size_t he)
  {
    size_t ohe = opposite(he);
    if(ohe == NONE) Msg::Error("No opposite half edge");

    for(int i = 0; i < 2; ++i) {
      vertex(next(he)) = vertex(prev(ohe));
      opposite(he) = opposite(next(ohe));
      if(opposite(he) == NONE)
        set_boundary(he);
      else
        opposite(opposite(he)) = he;

      std::swap(he, ohe);
    }

    opposite(next(he)) = next(ohe);
    opposite(next(ohe)) = next(he);
  }

  void split(size_t he, size_t v)
  {
    size_t ohe = opposite(he);
    for(int i = 0; i < 2; ++i) {
      size_t newhe = vertices.size();
      vertices.push_back(v);
      vertices.push_back(vertex(next(he)));
      vertices.push_back(vertex(prev(he)));
      opposites.push_back(ohe);
      opposites.push_back(opposite(next(he)));
      opposites.push_back(next(he));

      if(opposite(next(newhe)) == NONE)
        set_boundary(next(newhe));
      else
        opposite(opposite(next(he))) = next(newhe);

      opposite(next(he)) = prev(newhe);
      vertex(next(he)) = v;

      if(ohe == NONE) break;
      opposite(ohe) = newhe;
      std::swap(he, ohe);
    }
  }
};

// MAIN CLASS
class highOrderPolyMesh {
  int maxTag;

public:
  PolyMesh *pm; // Background mesh
  PolyMesh *ipm; // Intrinsic mesh
  geodesic::Mesh geoMesh; // geometric mesh
  TypedPoints pointsPool; // points of the IGA
  std::map<std::pair<int, int>, int> tags; // edge <a b>, triangles
  std::unordered_map<std::pair<int, int>, std::vector<geodesic::SurfacePoint>,
                     pair_hash>
    geodesics; // one geodesic per edge
  std::vector<std::vector<std::pair<int, int>>> vertexGeodesics;
  std::unordered_map<int, std::vector<std::array<int, 3>>> vertexTriangles;
  std::map<PolyMesh::Face *, int> f2n;
  std::map<PolyMesh::Vertex *, std::vector<int>> pvtags;
  std::map<PolyMesh::Vertex *, std::vector<std::pair<PolyMesh::Vertex *, int>>>
    pvvtags;
  std::map<PolyMesh::Face *, std::vector<int>> fvs;
  std::map<PolyMesh::HalfEdge *, std::vector<int>> evs;
  std::map<int, int> _saddle;
  std::vector<double> characLengthMin;
  std::vector<double> characLengthMax;
  std::vector<geodesic::GeodesicAlgorithmExact> algorithms;
  // std::map<geodesic::SurfacePoint *, PolyMesh::Vertex *> sp2pv;
  std::map<size_t, size_t> sp2pv;
  std::map<size_t, geodesic::SurfacePoint> pv2sp;
  std::unordered_map<std::array<int, 3>, std::pair<size_t, double>>
    circumIndexRadius;
  std::set<std::pair<int, int>> delaunayEdges;
  static std::function<double(const double, const double *, const size_t)>
    edgeQualityPtr;
  static std::function<double(const double *, const size_t, const double *,
                              const size_t, const size_t *, const size_t,
                              const double *, const size_t)>
    triangleQualityPtr;
  unsigned iteration_loop;

  PathView cachedIntersectionPath = PathView();
  std::vector<geodesic::Vertex *> cachedIntersectionVertices;
  std::unordered_map<geodesic::Face *, int> cachedIntersectionFaces;

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
  void printVertex(const char *fn, int i0);
  void printGeodesic(const char *fn, int i0, int i1);
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

  bool intersectGeodesicPath(PathView &p0, PathView &p1);
  bool intersectNewEdges(std::vector<std::pair<size_t, size_t>> &newEdges,
                         std::vector<std::pair<size_t, size_t>> &borderEdges);

  void removePoint(size_t i);

  bool doWeSplit(PolyMesh::HalfEdge *he);
  void write(const PolyMesh *pm_new,
             std::vector<PolyMesh::Vertex *> &pointVertices);

  bool symbolicSwapEdges(std::vector<size_t> &newTriangles,
                         std::vector<size_t> &cavity, bool propagate = true,
                         bool insert = true);
  bool swapEdge(PolyMesh::HalfEdge *he,
                std::vector<PolyMesh::HalfEdge *> &adjacentEdges,
                bool heuristic = true);
  void removeAdjacency(std::vector<size_t> &trigls);
  void addAdjacency(std::vector<size_t> &trigls);
  void doSwapEdge(PolyMesh::HalfEdge *he);
  bool doWeSwapAngleHeuristic(std::pair<int, int> &edge,
                              std::pair<int, int> &oppEdge);
  bool locallyDelaunay(size_t circumindex, double circumradius,
                       size_t oppVertex);
  bool canWeSwap(std::pair<int, int> &edge, std::pair<int, int> &oppEdge);
  bool checkNewTriangles(std::vector<size_t> newTris);
  double getQuality(std::vector<size_t> &triangles);
  void getBorder(std::vector<size_t> &triangles,
                 std::vector<std::pair<size_t, size_t>> &borderEdges,
                 std::vector<std::pair<size_t, size_t>> &innerEdges);
  bool doWeSwap(std::pair<int, int> &edge, std::pair<int, int> &opp,
                bool heuristic = true);
  bool doWeSwapIntrinsic(std::pair<int, int> &p01, std::pair<int, int> &p23);
  int swapEdges(bool heuristic = true);

  void meshAdapt(int niter);

  int intrinsicTriangulate();

  int getDelaunay(std::vector<geodesic::SurfacePoint> &points,
                  std::vector<int> &triangles,
                  std::vector<geodesic::SurfacePoint> &circumcenters,
                  std::vector<double> &circumradii);

  bool splitEdge(PolyMesh::HalfEdge *he, std::vector<HEdgeItem> &removedEdges,
                 std::vector<HEdgeItem> &adjacentEdges, bool propagate = true);
  int splitEdges();

  int findTriangleToSplit(int circumindex, int t);
  void replaceCavity(std::vector<size_t> &cavity, std::vector<size_t> &newTris);
  bool doSplitTriangle(size_t circumindex, std::vector<size_t> &cavity,
                       std::vector<size_t> &newTris);
  bool splitTriangle(int iTriangle, std::vector<TriangleItem> removedTriangles,
                     std::vector<TriangleItem> &adjacentTriangles);
  int splitTriangles();

  bool collapseEdge(PolyMesh::HalfEdge *he,
                    std::vector<HEdgeItem> &removedEdgeItems,
                    std::vector<HEdgeItem> &adjacentEdges);
  bool canWeCollapse(std::vector<PathView> &newPaths,
                     std::vector<PathView> &borderPaths,
                     std::vector<geodesic::SurfacePoint> &borderPath,
                     double &minAngle, double &maxAngle);
  double getEdgeQuality(std::pair<int, int> e);
  double getTriangleQuality(size_t tri[3]);
  bool doWeCollapse(double minAngleBefore, double maxAngleBefore,
                    std::vector<size_t> &newTris, double minHeuristicAngle,
                    double maxHeuristicAngle);
  inline void doCollapseEdge(std::pair<size_t, size_t> &edge, size_t index,
                             std::vector<size_t> &cavity,
                             std::vector<size_t> &newTris);
  void cleanAfterCollapse();
  bool doWeCollapse(PolyMesh::HalfEdge *he);
  int collapseEdges();

  SPoint3 getTrueCoords(geodesic::SurfacePoint &sp);
  double clMin(geodesic::SurfacePoint &sp);
  double clMax(geodesic::SurfacePoint &sp);
  bool sanityCheck();
  double length(std::pair<int, int> edge);
  double length(PolyMesh::HalfEdge *he);
  double adimLengthMin(PolyMesh::HalfEdge *he);
  double adimLengthMax(PolyMesh::HalfEdge *he);
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
  void addPolyMeshVertexVertexTag(PolyMesh::Vertex *v, PolyMesh::Vertex *w,
                                  int tag);
  void classifyGeodesic(std::pair<int, int> pair, const PathView &p, int i0,
                        int i1);
  void classifyGeodesicVertices(std::vector<PolyMesh::Vertex *> &pointVertices);
  double length(std::vector<geodesic::SurfacePoint> *path);
  double length(PathView &path);
  void setAdimLength(std::pair<int, int> edge, double length);
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

void saveIsoTriangles(int num, TypedPoints &hopPoints, PolyMesh *ipm);
void printCuttedMesh(PolyMesh *pm, std::map<int, int> colors = {});
bool colorFaces(PolyMesh *pm, std::map<int, int> &face2Colors,
                int maxColor = 4);
void intrinsicTriangulation(geodesic::GeodesicAlgorithmExact &algorithm,
                            geodesic::Mesh &geoMesh,
                            std::vector<geodesic::SurfacePoint> &points,
                            std::vector<int> &triangles,
                            std::vector<geodesic::SurfacePoint> &circumcenters,
                            std::vector<double> &circumradii, bool print);
inline void getFaceParamCoord(geodesic::SurfacePoint &p, geodesic::Face *f,
                              double uv[2]);

#endif
