#ifndef _MESH_RELAYING_
#define _MESH_RELAYING_

#include <algorithm>
#include <functional>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#include "SBoundingBox3d.h"
#include "SVector3.h"
#include "meshPolyMesh.h"
#include "meshTriangulation.h"
#include "robustPredicates.h"

class GModel;

class edgeCut {
public:
  size_t a, b;
  SVector3 p;
  double d;
  size_t interface;
  size_t m1;
  size_t m2;

  edgeCut(size_t _a, size_t _b, SVector3 _p, double _d, size_t _interface,
          size_t _m1, size_t _m2)
    : a(_a), b(_b), p(_p), d(_d), interface(_interface), m1(_m1), m2(_m2)
  {
  }

  bool operator<(const edgeCut &o) const
  {
    if(d < o.d) return true;
    return false;
  }
};

class frontNode {
public:
  size_t meshNode;
  size_t interface;
  size_t m1;
  size_t m2;
  double t;
  frontNode(size_t n, size_t _interface, size_t _m1, size_t _m2, double _t)
    : meshNode(n), interface(_interface), m1(_m1), m2(_m2), t(_t)
  {
  }
  bool operator<(const frontNode &other) const
  {
    return t < other.t;
  }
};

class interface {
public:
  size_t id;
  int tag;
  std::vector<size_t> markers;
  bool loop;

  interface(size_t _id, int _tag, std::vector<size_t> _markers, bool _loop)
  {
    id = _id;
    tag = _tag;
    markers = _markers;
    loop = _loop;
  }
};

struct TreeNode {
  int id; //-1 for bnd
  std::vector<TreeNode *> leafs;
  int tag;
  int data = 0;
};

// global functions
TreeNode *newTreeNode(int id, int tag);

double loopOrientation(std::vector<double> pos);
int clockwise(std::vector<double> loop);
int w_number(double P[2], std::vector<double> loop);

double kappa(double x1[2], double x2[2], double x3[2]);
int computeIntersection(double a1[2], double a2[2], double a3[2], double a4[2],
                        double *inter, double *param);

int point_on_triangle_vertex(PolyMesh::Face *f, double *pos);
std::pair<size_t, size_t> intersect_face(PolyMesh::Face *f, double *pos1, double *pos2);

class discreteFront {
  TreeNode *Tree = nullptr;
  size_t nTreeNode;

  PolyMesh *pm = new PolyMesh();
  SBoundingBox3d bbox;

  std::vector<double> pos;
  std::vector<size_t> corners;
  interface *boundary = new interface(0, 0, {}, true);

  std::vector<frontNode> fn;
  std::vector<interface> interfaces;
  std::vector<size_t> triple_points;
  std::vector<std::pair<size_t, std::pair<size_t, size_t>>> on_edge_triples;
  std::vector<int> priority{-10, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  size_t NX = 300;
  size_t NY = 300;
  std::vector<std::vector<std::pair<int, std::pair<size_t, size_t>>>> sss;

  discreteFront() {}
  static discreteFront *_instance;

public:
  static discreteFront *instance()
  {
    if(!_instance) _instance = new discreteFront();
    return _instance;
  }

  bool empty() const { return pos.empty(); }

  void advanceInTime(double dt, std::vector<SVector3> &v, const bool triple_slip)
  {
    createTree();
    printf("move from v \n");
    moveFromV(dt, v, triple_slip);
    printf("before print interfaces \n");
    FILE *f = fopen("interfaces_after_move.txt", "w");
    printInterfaces(f);
    fclose(f);
    printf("build spatial search structure \n");
    buildSpatialSearchStructure();
    printf("intersect interfaces \n");
    intersectInterfaces(false);
    printf("triangulate interface \n");
    triangulateInterfaces();
    printf("color triangles \n");
    colorTriangles();
    computeNewInterfaces();
  }

  void setBbox(SBoundingBox3d _bbox) { bbox = _bbox; }

  void addFrontNode(size_t n, size_t inter, size_t m1, size_t m2, SVector3 t, std::vector<size_t> markers)
  {
    int id1 = std::find(markers.begin(), markers.end(), m1) - markers.begin();
    int id2 = std::find(markers.begin(), markers.end(), m2) - markers.begin();
    double t_m = 0;
    if(id1<id2) {
      t_m = (double)id1;
    }else {
      t_m = (double)id2;
    }

    if(m1 == m2) { 
      fn.push_back(frontNode(n, inter, m1, m2, t_m));
      return;
    }

    SVector3 p0(pos[3 * m1], pos[3 * m1 + 1], pos[3 * m1 + 2]);
    SVector3 p1(pos[3 * m2], pos[3 * m2 + 1], pos[3 * m2 + 2]);
    double d = (p1 - p0).norm();

    if(d < 1e-10) {
      fn.push_back(frontNode(n, inter, m1, m2, t_m+0.5));
      return;
    }

    double a = 0;
    if(id1<id2){
      a = (t - p0).norm() / d;
    } else {
      a = (t - p1).norm() / d;
    }
     
    fn.push_back(frontNode(n, inter, m1, m2, t_m + a));
  }

  void clearFrontNodes() { fn.clear(); }

  std::vector<frontNode> getFrontNodes() { return fn; }

  PolyMesh **getPm() { return &pm; }

  void addInterface(std::vector<double> &p, int tag,
                    std::vector<size_t> interfaceCorners, bool loop)
  {
    size_t n_interface = interfaces.size();
    size_t n_marker = pos.size() / 3;
    size_t n = p.size() / 3;
    pos.insert(pos.end(), p.begin(), p.end());
    std::vector<size_t> m(n);
    std::iota(std::begin(m), std::end(m), n_marker);
    interface i = interface(n_interface, tag, m, loop);
    interfaces.push_back(i);
    for(size_t j = 0; j < interfaceCorners.size(); ++j) {
      corners.push_back(n_marker + interfaceCorners[j]);
    }
  }

  std::vector<frontNode> getFn() { return fn; }

  // geometry functions
  void intersectLine2d(const SVector3 &p0, const SVector3 &p1,
                       std::vector<double> &d, std::vector<int> &c);
  void removeFromSpatialSearchStructure(
    std::pair<int, std::pair<size_t, size_t>> edge);
  void
  addToSpatialSearchStructure(std::pair<int, std::pair<size_t, size_t>> edge);

  // advance in time functions
  void moveFromV(double dt, const std::vector<SVector3> &v, const bool triple_slip);
  void buildSpatialSearchStructure();
  void intersectInterfaces(bool bnd);
  void triangulateInterfaces();
  void colorTriangles(bool bnd = true);
  void computeNewInterfaces();

  // mesh functions
  std::vector<std::pair<size_t, size_t>> getFrontEdges();
  void getCoordinates(double x, double y, int &IX, int &IY);
  void getDF(std::vector<double> *doubleMarkers, std::vector<int> *doubleTags,
             std::vector<size_t> *doubleIds, std::vector<double> *tripleMarkers,
             std::vector<int> *tripleTags, std::vector<size_t> *tripleIds,
             std::vector<size_t> *DF_to_meshNodes, std::vector<double> *DF_to_mesh_parametric,
             std::vector<size_t> *meshNodes_to_DF, std::vector<double> *mesh_to_DF_parametric, const bool mesh_relation);
  int vertexType(size_t i, int *colors);
  size_t getMaxMarker();
  void rotate_pm(PolyMesh::HalfEdge *start,
                 std::vector<PolyMesh::HalfEdge *> *loop_he,
                 std::vector<size_t> *loop_v);
  void rotate_pm_vertex(PolyMesh::HalfEdge *start,
                        std::vector<PolyMesh::HalfEdge *> *loop_he,
                        std::vector<PolyMesh::Vertex *> *loop_vertex);

  int findMarker(size_t marker);
  void cornersInTriangle2d(const SVector3 &p0, const SVector3 &p1,
                           const SVector3 &p2, std::vector<SVector3> &cornerPos,
                           std::vector<std::pair<size_t, size_t>> &corner);
  void tripleInTriangle2d(const SVector3 &p0, const SVector3 &p1,
                          const SVector3 &p2, std::vector<size_t> &m,
                          std::vector<SVector3> &p_out);

  void markersCurvature(std::vector<int> concentration_list,
                        std::vector<double> tension_table,
                        std::vector<double> *curvature);

  void createTree();
  void printTree(TreeNode *node, int depth);
  int insideList(std::vector<size_t> loop, double P[2]);
  void addFreeForm(int tag, const std::vector<SVector3> &poly,
                   const std::vector<size_t> &_corners, bool loop);
  void printInterfaces(FILE *f);

  void setBoundaryFromMesh(std::vector<double> *bnd_pos);
  int findVertex(size_t i, PolyMesh::Vertex *v);
  size_t nextDouble(size_t interface, size_t marker, int direction);
  void switchMarkers(int dominant, size_t m, size_t next, int direction);
  // void findDoubleNeighbours(PolyMesh::Vertex *vertex,
  // std::vector<PolyMesh::Vertex *> *ns, int dominant_color);
  void findNDoubleNeighbours(PolyMesh::Vertex *vertex,
                             std::vector<PolyMesh::Vertex *> *ns, size_t n,
                             int dominant_color, bool with_triple = false);
  void getBndMarkers(std::vector<int> *bnd_markers);
  void getSolidMarkers(std::vector<int> *solid_markers);
  void redistFront(double lc);
  int checkIfOnlyType(size_t id_interface, size_t marker);
  void initFront(std::vector<double> points, std::vector<int> concentration);
  void buildSpatialSearchStructureInit();
  SVector3 closestPoints2d(const SVector3 &P,
                           const std::vector<bool> &bnd_markers);

  void resetInterfacesMesh();

  void write_DF(const std::string DF_filename);
  void read_DF(const std::string DF_filename, const bool pos_flag);

  void remove_features(double l);
  void renumber_DF();
  std::vector<interface> getInterfaces() { return interfaces; }
  std::vector<double> getPos() { return pos; }
};

class meshRelaying {
  std::vector<std::vector<size_t>> v2v;
  std::vector<std::vector<size_t>> v2tet;
  std::vector<std::vector<size_t>> v2tri;
  std::vector<std::vector<size_t>> v2edg;

  std::vector<size_t> tets;
  std::vector<size_t> tris;
  std::vector<size_t> edgs;

  std::vector<size_t> dimVertex;
  std::vector<std::pair<size_t, size_t>> bnd1d;
  std::vector<std::pair<size_t, size_t>> bnd2d;

  std::vector<size_t> front_nodes;
  std::vector<size_t> corners;

  std::vector<double> pos;
  std::vector<double> initial_pos;

  std::vector<std::vector<double>> levelsets;
  std::vector<int> tris_concentration;

  PolyMesh *pm_mesh = nullptr;

  double _distMax, _RATIO;

  static meshRelaying *_instance;
  meshRelaying(
    GModel *gm = nullptr); // use GModel gm or Gmodel::current() if NULL
public:
  static meshRelaying *instance()
  {
    if(!_instance) _instance = new meshRelaying();
    return _instance;
  }

  void setDiscreteFrontBBox()
  {
    SBoundingBox3d bbox;
    for(size_t i = 0; i < pos.size(); i += 3)
      bbox += SPoint3(pos[i], pos[i + 1], pos[i + 2]);
    bbox *= 1.01;
    discreteFront::instance()->setBbox(bbox);
  }

  void setPos(size_t i, double x, double y, double z)
  {
    pos[3 * i] = x;
    pos[3 * i + 1] = y;
    pos[3 * i + 2] = z;
  }

  void setLevelsets(const std::vector<std::vector<double>> &_ls)
  {
    levelsets = _ls;
  }

  void getNodesPosition(std::vector<double> &position) { position = pos; }

  void getFrontNodesPosition(std::vector<double> &api_position, std::vector<int> &fn) {
    fn.clear();
    api_position.clear();
    for (size_t i=0;i< front_nodes.size() ; i++){      
      fn.push_back((int) front_nodes[i]);
      api_position.push_back(pos[3*front_nodes[i]+0]);
      api_position.push_back(pos[3*front_nodes[i]+1]);
      api_position.push_back(pos[3*front_nodes[i]+2]);
    }
  }
  
  void doRelaying(
    const std::function<
      std::vector<std::pair<double, std::pair<size_t, size_t>>>(size_t, size_t)>
      &f);
  void doRelaying(double relax);
  double smallest_measure(const size_t n, const SVector3 &target);

  void untangle(double lambda, int nIterOut, int nIterIn, double distMax,
                double RATIO);
  double myDensity2D(size_t iTriangle, double distMax, double RATIO,
                     std::vector<double> &distances);
  // double qualityElement(size_t elem);

  void concentration(std::vector<int> *concentration);
  void concentration_bfs(std::vector<int> *concentration);
  int full_concentration_triangle(int id);
  void curvature(std::vector<int> concentration, std::vector<double> *curvature,
                 double theta);
  void curvatureFromMarkers(std::vector<int> concentration_list,
                            std::vector<double> tension_table,
                            std::vector<int> concentration,
                            std::vector<double> *curvature);

  void curvatureFromConcentration(std::vector<double>*curvature);

  void print4debug(const char *);
  void getBnd1d(std::vector<std::pair<size_t, size_t>> *bnd) { *bnd = bnd1d; }

  void getPm(PolyMesh **pm);

  void setNodesPosition(std::vector<double> mesh_pos);

  void reset_DF(){
    front_nodes.clear();
    corners.clear();
  }

  void construct_DF_to_mesh_relation(std::vector<size_t> &DF_to_meshNodes, std::vector<double> &DF_to_mesh_parametric);
  void construct_mesh_to_DF_relation(std::vector<size_t> &meshNodes_to_DF, std::vector<double> &mesh_to_DF_parametric);
};

#endif
