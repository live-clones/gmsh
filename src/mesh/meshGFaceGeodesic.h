#ifndef _MESHGFACEGEODESIC_H_
#define _MESHGFACEGEODESIC_H_

#include "meshTriangulation.h"
#include "geodesic_mesh.h"
#include "geodesic_algorithm_exact.h"
#include "BDS.h"
#include "GModel.h" 

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
  // std::vector<double> trueCoords;
  std::vector<SVector3> trueCoord;
  std::vector<double> parametricCoords;
  // std::vector<double> lcs;
  std::vector<double> characLength;
  std::map<std::pair<int, int>, double> lengths;
  std::vector<geodesic::GeodesicAlgorithmExact> algorithms;
  std::map<geodesic::SurfacePoint *, PolyMesh::Vertex *> sp2pv;

  ///  std::map<int, std::map<int,double> > nodalDistances; // points -->
  ///  distances to mesh vertices
  // MAIN FUNCTIONS ----
  // highOrderPolyMesh(GModel *gm);
  highOrderPolyMesh(PolyMesh *pm, std::vector<size_t> & tris);
  highOrderPolyMesh(PolyMesh *pm);
  PolyMesh *cutMesh(std::vector<PolyMesh::Vertex *> &pointVertices);
  void createGeodesic(std::vector<geodesic::SurfacePoint> & pts_start,
                      std::vector<geodesic::SurfacePoint> & pts_end,
                      std::vector<std::vector<geodesic::SurfacePoint>> & paths);
                      // std::vector<std::vector<geodesic::SurfacePoint>> & paths,
                      // geodesic::Mesh *restrictedGeoMesh = nullptr);
  void createGeodesicsInParallel(std::set<std::pair<int,int>> edges);
  void createGeodesics();
  void getGeodesicPath(int p0, int p1, std::vector<geodesic::SurfacePoint> &path);
  void getPath(std::pair<int,int> edge, std::vector<geodesic::SurfacePoint> &path);
  void printGeodesics(const char *fn);
  void enforceBoundary();

  bool intersectGeodesicPath(std::vector<geodesic::SurfacePoint> &p0,
                             std::vector<geodesic::SurfacePoint> &p1,
                             SVector3 &intersection);

  int splitTriangle(size_t iTriangle, geodesic::SurfacePoint &sp);
  int swapEdge(const std::pair<int, int> &p01, const int onlyMisoriented,
               std::pair<int, int> *p23 = nullptr);
  std::vector<geodesic::SurfacePoint> circumCenter(int iTriangle,
                                                   double dist_max = 0);
  int splitEdge(const std::pair<int, int> &p01, double lTarget,
                double adimMin = 0.7, double adimMax = 1.4);
  double pathLength(const std::pair<int, int> &p01);
  void write(const PolyMesh *pm_new, std::vector<PolyMesh::Vertex *> &pointVertices);

  bool doWeSwap(int p0, int p1, int p2, int p3, int onlyMisoriented);
  int swapEdges(int niter, int onlyMisoriented = 1);
  int splitEdges(double L);
  double computeBoxProduct(int p0, int p1, int p2);

  bool swapEdge(const std::pair<int, int> &edge, std::vector<std::pair<int,int>> & adjacentEdges);
  void getOppEdge(const std::pair<int, int> &p01, std::pair<int, int> &p23);
  bool doWeSwap(const std::pair<int, int> &p01);
  int swapEdges();

  bool splitEdge(const std::pair<int, int> &edge, std::vector<std::pair<int,int>> & adjacentEdges);
  int splitEdges(const double MAXE, double cl);

  bool collapseEdge(std::pair<int, int> edge,
                   std::set<size_t> & keep,
                   std::vector<std::pair<int, int>> &adjacentEdges,
                   std::vector<std::pair<int, int>> &removedEdges,
                   double MINA = 1e-6);
  void adjacentVertices(std::pair<int,int> p01, std::vector<int> & iXs);
  bool canWeCollapse(std::pair<int,int> p01, std::vector<int> & iXs, double MINA = 1e-6);
  std::pair<bool,bool> doWeCollapse(std::pair<int,int> & edge, std::set<size_t> & keep);
  int collapseEdges(const double MINE, double MINA, std::set<size_t> & keep);
  // int intrinsicCollapseEdge(std::pair<int, int> edge,
  //                  std::set<size_t> & keep,
  //                  std::vector<std::pair<int, int>> &adjacentEdges,
  //                  std::vector<std::pair<int, int>> &removedEdges,
  //                  double MINA = 1e-6);
  // int intrinsicCollapseEdges(const double MINE, double MINA, std::set<size_t> & keep);

  SPoint3 getTrueCoords(geodesic::SurfacePoint &sp);
  double cl(geodesic::SurfacePoint &sp);
  bool sanityCheck();

private:
  int getTag(const std::pair<int, int> &e2);
  SVector3 normal(geodesic::base_pointer b);
  SVector3 normal(int p);
  double computeAngle(int p0, int p1, int p2);
  double computeAngle(SVector3 v01, SVector3 v02, SVector3 n);
  double computeAngle(std::vector<geodesic::SurfacePoint> & p01,
                      std::vector<geodesic::SurfacePoint> & p20, SVector3 n);
  double computeAngle(int p0, int p1, int p2, SVector3 n, int boundary10 = 0, int boundary12 = 0);
  void computeAngles(int ps[3], double angles[3], int boundaryOrients[3]);
  double computeAngleTrue(int p0, int p1, int p2);
  // double computeMinAngle(const int p0, const int p1, const int p2, const int p3);
  bool edgeValid(int p0, int p1, int p2, int p3);
  void addVertexOnSurface(PolyMesh::Face *f, int v);
  void addVertexOnEdge(PolyMesh::HalfEdge *e, int v);
  void addPolyMeshVertexTag(PolyMesh::Vertex *v, int tag);
  void classifyGeodesic(std::pair<int, int> pair,
					   const std::vector<geodesic::SurfacePoint> &p);
  void classifyGeodesicVertices(std::vector<PolyMesh::Vertex *> &pointVertices);
  double adimLength(std::vector<geodesic::SurfacePoint> & path);
  double adimLength(const std::pair<int,int> edge);
  std::vector<size_t>& adjacentTriangles(std::pair<int,int> edge);
  void splitPath(std::vector<geodesic::SurfacePoint> & path, const double length,
                 std::vector<geodesic::SurfacePoint> & firstHalf,
                 std::vector<geodesic::SurfacePoint> & secondHalf);
  // void findConfig(std::vector<size_t> & ts, int *is);
  // void preComputeForCollapse(std::set<int> & allVertices);
  void getBoundaryPath(int p0, int p1, std::vector<geodesic::SurfacePoint> &path);
  void getPath(std::pair<int,int> edge, int boundaryOrientation, std::vector<geodesic::SurfacePoint> &path);
  int getBoundaryOrientation(std::pair<int,int> edge);

};

// void saveIsoTriangles(int num, std::vector<int> & hopTriangles, std::vector<geodesic::SurfacePoint> & hopPoints, std::vector<double> & hopLCs);
void saveIsoTriangles(int num, std::vector<int> & hopTriangles, std::vector<geodesic::SurfacePoint> & hopPoints);
void printCuttedMesh(PolyMesh *pm, std::map<int,int> colors = {});
bool colorFaces(PolyMesh *pm, std::map<int, int> & face2Colors, int maxColor = 4);

#endif
