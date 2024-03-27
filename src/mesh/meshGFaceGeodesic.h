#ifndef _MESHGFACEGEODESIC_H_
#define _MESHGFACEGEODESIC_H_

#include "meshTriangulation.h"
#include "geodesic_mesh.h"

int makeMeshGeodesic(GModel *gm);
PolyMesh *createPolyMesh(const std::vector<double> &p,
                         const std::vector<size_t> &t,
                         const std::vector<size_t> &e = {},
                         const std::vector<size_t> &vertexNum = {});


class highOrderPolyMesh {
  int maxTag;

public:
  PolyMesh *pm;
  geodesic::Mesh geoMesh; // geometric mesh
  std::vector<geodesic::SurfacePoint> points; // points of the IGA
  std::map<std::pair<int, int>, int> tags; // edge <a b>, triangles
  std::map<std::pair<int, int>, std::vector<size_t>>
    edges; // edge <a b>, triangles
  std::map<std::pair<int, int>, std::vector<geodesic::SurfacePoint>>
    geodesics; // one geodesic per edge
  std::vector<int> triangles; // 3 integers per triangle
  std::map<PolyMesh::Face *, int> f2n;
  std::map<PolyMesh::Vertex *, std::vector<int>> pvtags;
  //  std::map<PolyMesh::HalfEdge *, std::vector<VertexOnEdge> > cuts;
  std::map<PolyMesh::Face *, std::vector<int>> fvs;
  std::map<PolyMesh::HalfEdge *, std::vector<int>> evs;
  // detect intersecting geodesic @ saddle_points
  std::map<int, int> _saddle;
  std::vector<double> trueCoords;


  ///  std::map<int, std::map<int,double> > nodalDistances; // points -->
  ///  distances to mesh vertices
  // MAIN FUNCTIONS ----
  highOrderPolyMesh(GModel *gm);
  highOrderPolyMesh(PolyMesh *pm, std::vector<size_t> & tris);
  void createGeodesics();
  PolyMesh *cutMesh();
  void createGeodesicPath(int p0, int p1,
                          std::vector<geodesic::SurfacePoint> &path);
  bool intersectGeodesicPath(std::vector<geodesic::SurfacePoint> &p0,
                             std::vector<geodesic::SurfacePoint> &p1,
                             SVector3 &intersection);

  int splitTriangle(size_t iTriangle, geodesic::SurfacePoint &sp);
  int swapEdge(const std::pair<int, int> &p01, const int onlyMisoriented,
               std::pair<int, int> *p23 = nullptr, const bool forceInPlane = false);
  std::vector<geodesic::SurfacePoint> circumCenter(int iTriangle,
                                                   double dist_max = 0);
  int splitEdge(const std::pair<int, int> &p01, double lTarget,
                double adimMin = 0.7, double adimMax = 1.4);
  double pathLength(const std::pair<int, int> &p01);
  void write(const PolyMesh *pm_new);

  void printGeodesics(const char *fn);
  int swapEdges(int niter = 1, int onlyMisoriented = 1, const bool forceInPlane = false);
  int splitEdges(double L);
  double computeAngleTrue(int p0, int p1, int p2);
  double computeBoxProduct(int p0, int p1, int p2);
  // static int getNumThreads();
  void createGeodesicsInParallel(std::vector<int> &__rows,
                                 std::vector<int> &__columns,
                                 std::vector<int> &__starts);
  SPoint3 getTrueCoords(geodesic::SurfacePoint &sp);

private:
  int getTag(const std::pair<int, int> &e2);
  SVector3 unit_normal(geodesic::Face *f);
  SVector3 normal(int p);
  double computeAngle(int p0, int p1, int p2, bool forceInPlane = false);
  bool edgeValid(int p0, int p1, int p2, int p3);
  bool doWeSwap(int p0, int p1, int p2, int p3, int onlyMisoriented, const bool forceInPlane = false);
  void addVertexOnSurface(PolyMesh::Face *f, int v);
  void addVertexOnEdge(PolyMesh::HalfEdge *e, int v);
  void addPolyMeshVertexTag(PolyMesh::Vertex *v, int tag);
  void classifyGeodesic(std::pair<int, int> pair,
					   const std::vector<geodesic::SurfacePoint> &p);
  void classifyGeodesicVertices();
  
};

#endif
