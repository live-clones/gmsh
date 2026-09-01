// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BDS_H
#define BDS_H

// This is a 2D version of the Bidirectional Data Structure (BDS)
// of shephard and beall
// points may know the normals to the surface they are classified on
// default values are 0,0,1

#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

#include "GmshMessage.h"
#include "SPoint2.h"

class BDS_Edge;
class BDS_Face;
class BDS_Mesh;
class BDS_Point;
class BDS_Vector;
class GFace;
class GEdge;
class GVertex;

class BDS_GeomEntity {
public:
  int classif_tag;
  int classif_degree;

  BDS_GeomEntity(int a, int b) : classif_tag(a), classif_degree(b) {}

  ~BDS_GeomEntity() {}

  bool operator<(const BDS_GeomEntity &other) const
  {
    if(classif_degree < other.classif_degree) return true;
    if(classif_degree > other.classif_degree) return false;
    if(classif_tag < other.classif_tag) return true;
    return false;
  }
};

class BDS_Point {
  // the first size is the one dictated by the Background Mesh the
  // second one is dictated by characteristic lengths at points and is
  // propagated
  double _lcBGM, _lcPTS;

public:
  double X, Y, Z;
  double u, v;
  bool config_modified;
  short degenerated;
  BDS_Point *_periodicCounterpart;
  int iD;
  BDS_GeomEntity *g;
  std::vector<BDS_Edge *> edges;

  double &lcBGM() { return _lcBGM; }
  double &lc() { return _lcPTS; }
  double const &lc() const { return _lcPTS; }

  bool operator<(const BDS_Point &other) const { return iD < other.iD; }

  void del(BDS_Edge *e)
  {
    if(edges.empty()) return;
    edges.erase(std::remove(edges.begin(), edges.end(), e), edges.end());
  }
  std::vector<BDS_Face *> getTriangles() const;
  void getTriangles(std::vector<BDS_Face *> &t) const;
  BDS_Point(int id, double x = 0, double y = 0, double z = 0)
    : _lcBGM(1.e22), _lcPTS(1.e22), X(x), Y(y), Z(z), u(0), v(0),
      config_modified(true), degenerated(0), _periodicCounterpart(nullptr),
      iD(id), g(nullptr)
  {
  }
};

class BDS_Edge {
  // An edge of a surface mesh has two faces, so they are stored inline: a
  // std::vector here meant one extra heap block, and one extra cache miss on
  // every faces() call, for every edge of the mesh. The overflow list is only
  // ever allocated on a non manifold configuration.
  BDS_Face *_f[2];
  int _nf;
  std::vector<BDS_Face *> *_moreFaces;

public:
  BDS_Edge(BDS_Point *A, BDS_Point *B)
    : _nf(0), _moreFaces(nullptr), deleted(false), g(nullptr)
  {
    if(*A < *B) {
      p1 = A;
      p2 = B;
    }
    else {
      p1 = B;
      p2 = A;
    }
    p1->edges.push_back(this);
    p2->edges.push_back(this);
  }

  ~BDS_Edge() { delete _moreFaces; }
  BDS_Face *faces(std::size_t const i) const
  {
    return i < 2 ? _f[i] : (*_moreFaces)[i - 2];
  }
  double length() const
  {
    return std::sqrt((p1->X - p2->X) * (p1->X - p2->X) +
                     (p1->Y - p2->Y) * (p1->Y - p2->Y) +
                     (p1->Z - p2->Z) * (p1->Z - p2->Z));
  }
  int numfaces() const { return _nf; }
  int numTriangles() const;
  inline BDS_Point *commonvertex(const BDS_Edge *other) const
  {
    BDS_Point *v = commonvertexQuiet(other);
    if(!v)
      Msg::Error("Edge %d %d has no common node with edge %d %d", p1->iD,
                 p2->iD, other->p1->iD, other->p2->iD);
    return v;
  }
  // same, without the error message: used to fill BDS_Face's node cache, where
  // a failure must still be reported by getNodes() and not at construction
  inline BDS_Point *commonvertexQuiet(const BDS_Edge *other) const
  {
    if(p1 == other->p1 || p1 == other->p2) return p1;
    if(p2 == other->p1 || p2 == other->p2) return p2;
    return nullptr;
  }
  BDS_Point *othervertex(const BDS_Point *p) const
  {
    if(p1 == p) return p2;
    if(p2 == p) return p1;
    Msg::Error("Edge %d %d does not contain node %d", p1->iD, p2->iD, p->iD);
    return nullptr;
  }
  void addface(BDS_Face *f)
  {
    if(_nf < 2) { _f[_nf] = f; }
    else {
      if(!_moreFaces) _moreFaces = new std::vector<BDS_Face *>();
      _moreFaces->push_back(f);
    }
    _nf++;
  }
  bool operator<(const BDS_Edge &other) const
  {
    if(*other.p1 < *p1) return true;
    if(*p1 < *other.p1) return false;
    if(*other.p2 < *p2) return true;
    return false;
  }
  BDS_Face *otherFace(const BDS_Face *f) const
  {
    if(numfaces() != 2) {
      Msg::Error("%d face(s) attached to edge %d %d", numfaces(), p1->iD,
                 p2->iD);
      return nullptr;
    }
    if(f == _f[0]) return _f[1];
    if(f == _f[1]) return _f[0];
    Msg::Error("Edge %d %d does not belong to the face", p1->iD, p2->iD);
    return nullptr;
  }
  // removes every occurrence of t, keeping the order of the others, as the
  // std::remove_if this used to do
  void del(BDS_Face *t)
  {
    if(!_nf) return;
    int n = _nf;
    _nf = 0;
    for(int i = 0; i < n; i++) {
      BDS_Face *f = i < 2 ? _f[i] : (*_moreFaces)[i - 2];
      if(f == t) continue;
      if(_nf < 2) { _f[_nf] = f; }
      else { (*_moreFaces)[_nf - 2] = f; }
      _nf++;
    }
    if(_moreFaces && _nf <= 2) _moreFaces->clear();
    else if(_moreFaces) _moreFaces->resize(_nf - 2);
  }
  void oppositeof(BDS_Point *oface[2]) const;
  void computeNeighborhood(BDS_Point *t1[4], BDS_Point *t2[4],
                           BDS_Point *oface[2]) const;

public:
  bool deleted;
  BDS_Point *p1, *p2;
  BDS_GeomEntity *g;
};

class BDS_Face {
public:
  BDS_Face(BDS_Edge *A, BDS_Edge *B, BDS_Edge *C, BDS_Edge *D = nullptr)
    : deleted(false), e1(A), e2(B), e3(C), e4(D), g(nullptr)
  {
    e1->addface(this);
    e2->addface(this);
    e3->addface(this);
    if(e4) e4->addface(this);
    // the edges of a face never change once it is built, so its nodes can be
    // computed once here instead of on every getNodes() call
    if(!e4) {
      _n[0] = e1->commonvertexQuiet(e3);
      _n[1] = e1->commonvertexQuiet(e2);
      _n[2] = e2->commonvertexQuiet(e3);
      _n[3] = nullptr;
      _nodes = _n[0] && _n[1] && _n[2];
    }
    else {
      _n[0] = e1->commonvertexQuiet(e4);
      _n[1] = e1->commonvertexQuiet(e2);
      _n[2] = e2->commonvertexQuiet(e3);
      _n[3] = e3->commonvertexQuiet(e4);
      _nodes = _n[0] && _n[1] && _n[2] && _n[3];
    }
  }
  int numEdges() const { return e4 ? 4 : 3; }
  BDS_Edge *oppositeEdge(BDS_Point *p)
  {
    if(e4) {
      Msg::Error("Opposite edge to point %d cannot be found for quad", p->iD);
      return nullptr;
    }
    if(e1->p1 != p && e1->p2 != p) return e1;
    if(e2->p1 != p && e2->p2 != p) return e2;
    if(e3->p1 != p && e3->p2 != p) return e3;
    Msg::Error("Point %d does not belong to this triangle", p->iD);
    return nullptr;
  }
  BDS_Point *oppositeVertex(BDS_Edge *e)
  {
    if(e4) {
      Msg::Error("Opposite point to edge %d %d cannot be found for quad",
                 e->p1->iD, e->p2->iD);
      return nullptr;
    }
    if(e == e1) return e2->commonvertex(e3);
    if(e == e2) return e1->commonvertex(e3);
    if(e == e3) return e1->commonvertex(e2);
    Msg::Error("Edge %d %d does not belong to this triangle", e->p1->iD,
               e->p2->iD);
    return nullptr;
  }
  inline bool getNodes(BDS_Point *n[4]) const
  {
    if(_nodes) {
      n[0] = _n[0];
      n[1] = _n[1];
      n[2] = _n[2];
      n[3] = _n[3];
      return true;
    }
    return _reportInvalidNodes(n);
  }

public:
  bool deleted;
  BDS_Edge *e1, *e2, *e3, *e4;
  BDS_GeomEntity *g;

private:
  BDS_Point *_n[4];
  bool _nodes;
  // only reached for a malformed face: redo the lookups so that the same
  // diagnostics come out as before the nodes were cached
  bool _reportInvalidNodes(BDS_Point *n[4]) const
  {
    if(!e4) {
      n[0] = e1->commonvertex(e3);
      n[1] = e1->commonvertex(e2);
      n[2] = e2->commonvertex(e3);
      n[3] = nullptr;
    }
    else {
      n[0] = e1->commonvertex(e4);
      n[1] = e1->commonvertex(e2);
      n[2] = e2->commonvertex(e3);
      n[3] = e3->commonvertex(e4);
    }
    Msg::Error("Invalid points in face");
    return false;
  }
};

struct GeomLessThan {
  bool operator()(const BDS_GeomEntity *ent1, const BDS_GeomEntity *ent2) const
  {
    return *ent1 < *ent2;
  }
};

struct PointLessThan {
  bool operator()(const BDS_Point *ent1, const BDS_Point *ent2) const
  {
    return *ent1 < *ent2;
  }
};

struct PointLessThanLexicographic {
  static double t;
  bool operator()(const BDS_Point *ent1, const BDS_Point *ent2) const
  {
    if(ent1->X - ent2->X > t) return true;
    if(ent1->X - ent2->X < -t) return false;
    if(ent1->Y - ent2->Y > t) return true;
    if(ent1->Y - ent2->Y < -t) return false;
    if(ent1->Z - ent2->Z > t) return true;
    return false;
  }
};

struct EdgeLessThan {
  bool operator()(const BDS_Edge *ent1, const BDS_Edge *ent2) const
  {
    return *ent1 < *ent2;
  }
};

class BDS_SwapEdgeTest {
public:
  virtual bool operator()(BDS_Point *p1, BDS_Point *p2, BDS_Point *q1,
                          BDS_Point *q2) const = 0;
  virtual bool operator()(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                          BDS_Point *q1, BDS_Point *q2, BDS_Point *q3,
                          BDS_Point *op1, BDS_Point *op2, BDS_Point *op3,
                          BDS_Point *oq1, BDS_Point *oq2,
                          BDS_Point *oq3) const = 0;
  virtual ~BDS_SwapEdgeTest() {}
};

class BDS_SwapEdgeTestRecover : public BDS_SwapEdgeTest {
public:
  BDS_SwapEdgeTestRecover() {}
  virtual bool operator()(BDS_Point *p1, BDS_Point *p2, BDS_Point *q1,
                          BDS_Point *q2) const;
  virtual bool operator()(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                          BDS_Point *q1, BDS_Point *q2, BDS_Point *q3,
                          BDS_Point *op1, BDS_Point *op2, BDS_Point *op3,
                          BDS_Point *oq1, BDS_Point *oq2, BDS_Point *oq3) const;
  virtual ~BDS_SwapEdgeTestRecover() {}
};

class BDS_SwapEdgeTestQuality : public BDS_SwapEdgeTest {
  bool testQuality, testSmallTriangles;

public:
  BDS_SwapEdgeTestQuality(bool a, bool b = true)
    : testQuality(a), testSmallTriangles(b)
  {
  }
  virtual bool operator()(BDS_Point *p1, BDS_Point *p2, BDS_Point *q1,
                          BDS_Point *q2) const;
  virtual bool operator()(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                          BDS_Point *q1, BDS_Point *q2, BDS_Point *q3,
                          BDS_Point *op1, BDS_Point *op2, BDS_Point *op3,
                          BDS_Point *oq1, BDS_Point *oq2, BDS_Point *oq3) const;
  virtual ~BDS_SwapEdgeTestQuality() {}
};

class BDS_SwapEdgeTestNormals : public BDS_SwapEdgeTest {
  GFace *gf;
  double _ori;

public:
  BDS_SwapEdgeTestNormals(GFace *_gf, double ori) : gf(_gf), _ori(ori) {}
  virtual bool operator()(BDS_Point *p1, BDS_Point *p2, BDS_Point *q1,
                          BDS_Point *q2) const;
  virtual bool operator()(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                          BDS_Point *q1, BDS_Point *q2, BDS_Point *q3,
                          BDS_Point *op1, BDS_Point *op2, BDS_Point *op3,
                          BDS_Point *oq1, BDS_Point *oq2, BDS_Point *oq3) const;
};

struct EdgeToRecover {
  int p1, p2;
  GEdge *ge;
  EdgeToRecover(int _p1, int _p2, GEdge *_ge) : ge(_ge)
  {
    if(_p1 < _p2) {
      p1 = _p1;
      p2 = _p2;
    }
    else {
      p2 = _p1;
      p1 = _p2;
    }
  }
  bool operator<(const EdgeToRecover &other) const
  {
    if(p1 < other.p1) return true;
    if(p1 > other.p1) return false;
    if(p2 < other.p2) return true;
    return false;
  }
};

// Scratch buffers reused by BDS_Mesh::smooth_point_centroid()
struct BDS_SmoothScratch {
  std::vector<BDS_Point *> nbg;
  std::vector<double> lc;
  std::vector<SPoint2> kernel;
  std::vector<BDS_Face *> ts;
};

class BDS_Mesh {
public:
  int MAXPOINTNUMBER;
  double Min[3], Max[3], LC;
  BDS_Mesh(int MAXX = 0) : MAXPOINTNUMBER(MAXX) {}
  virtual ~BDS_Mesh();
  BDS_Mesh(const BDS_Mesh &other);
  std::set<BDS_GeomEntity *, GeomLessThan> geom;
  std::set<BDS_Point *, PointLessThan> points;
  std::vector<BDS_Edge *> edges;
  std::vector<BDS_Face *> triangles;
  // Points
  BDS_Point *add_point(int num, double x, double y, double z);
  BDS_Point *add_point(int num, double u, double v, GFace *gf);
  void del_point(BDS_Point *p);
  BDS_Point *find_point(int num);
  // Edges
  BDS_Edge *add_edge(int p1, int p2);
  BDS_Edge *add_edge(BDS_Point *p1, BDS_Point *p2);
  void del_edge(BDS_Edge *e);
  BDS_Edge *find_edge(int p1, int p2);
  BDS_Edge *find_edge(BDS_Point *p1, BDS_Point *p2);
  BDS_Edge *find_edge(BDS_Point *p1, int p2);
  BDS_Edge *find_edge(BDS_Point *p1, BDS_Point *p2, BDS_Face *t) const;
  // Triangles
  BDS_Face *add_triangle(int p1, int p2, int p3);
  BDS_Face *add_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3);
  BDS_Face *add_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3);
  void del_face(BDS_Face *t);
  BDS_Face *find_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3);
  // Geom entities
  void add_geom(int degree, int tag);
  BDS_GeomEntity *get_geom(int p1, int p2);
  // 2D operators
  BDS_Edge *recover_edge(int p1, int p2, bool &_fatal,
                         std::set<EdgeToRecover> *e2r = nullptr,
                         std::set<EdgeToRecover> *not_recovered = nullptr);
  BDS_Edge *recover_edge_fast(BDS_Point *p1, BDS_Point *p2);

  /// Can invalidate the iterators for \p edge
  bool swap_edge(BDS_Edge *, const BDS_SwapEdgeTest &theTest,
                 bool force = false);
  bool collapse_edge_parametric(BDS_Edge *, BDS_Point *, bool = false);
  bool smooth_point_centroid(BDS_Point *p, GFace *gf, double thresh);
  // same, reusing the caller's scratch buffers instead of allocating four
  // vectors for every point of every smoothing pass
  bool smooth_point_centroid(BDS_Point *p, GFace *gf, double thresh,
                             BDS_SmoothScratch &scratch);
  bool split_edge(BDS_Edge *, BDS_Point *, bool check_area_param = false);
  bool edge_constraint(BDS_Point *p1, BDS_Point *p2);
  // Global operators
  void cleanup();
};

void normal_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3, double c[3]);
void outputScalarField(std::vector<BDS_Face *> &t, const char *fn, int param,
                       GFace *gf = nullptr);
void recur_tag(BDS_Face *t, BDS_GeomEntity *g);
int Intersect_Edges_2d(double x1, double y1, double x2, double y2, double x3,
                       double y3, double x4, double y4, double x[2]);
double BDS_Face_Validity(GFace *gf, BDS_Face *f);

#endif
