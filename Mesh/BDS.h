// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _BDS_H_
#define _BDS_H_

// This is a 2D version of the Bidirectional Data Structure (BDS)
// of shephard and beall
// points may know the normals to the surface they are classified on
// default values are 0,0,1

#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <math.h>
#include "GFace.h"
#include "PView.h"
#include "GmshMessage.h"

class BDS_Edge;
class BDS_Face;
class BDS_Mesh;
class BDS_Point;
class BDS_Vector;
class GFace;
class GEdge;
class GVertex;

void vector_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3, double c[3]); 
void normal_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3, double c[3]); 
double surface_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3); 
double surface_triangle_param(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3); 
void optimize_vertex_position(GFace *GF, BDS_Point *data, double su, double sv);
void swap_config(BDS_Edge *e, 
                 BDS_Point **p11, BDS_Point **p12, BDS_Point **p13,
                 BDS_Point **p21, BDS_Point **p22, BDS_Point **p23,
                 BDS_Point **p31, BDS_Point **p32, BDS_Point **p33,
                 BDS_Point **p41, BDS_Point **p42, BDS_Point **p43);

class BDS_GeomEntity
{
public:
  int classif_tag;
  int classif_degree;
  inline bool operator < (const BDS_GeomEntity & other) const
  {
    if(classif_degree < other.classif_degree)return true;
    if(classif_degree > other.classif_degree)return false;
    if(classif_tag < other.classif_tag)return true;
    return false;
  }
  BDS_GeomEntity(int a, int b) : classif_tag(a),classif_degree(b) {}
  ~BDS_GeomEntity(){}
};

class BDS_Vector
{
public:
  double x, y, z;
  bool operator < (const BDS_Vector &o) const
  {
    if(x - o.x  > t ) return true;
    if(x - o.x  < -t) return false;
    if(y - o.y  > t ) return true;
    if(y - o.y  < -t) return false;
    if(z - o.z  > t ) return true;
    return false;
  }
  BDS_Vector operator + (const BDS_Vector &v)
  {
    return BDS_Vector(x + v.x, y + v.y, z + v.z);
  }
  BDS_Vector operator - (const BDS_Vector &v)
  {
    return BDS_Vector(x - v.x, y - v.y, z - v.z);
  }
  inline BDS_Vector operator % (const BDS_Vector &other) const
  {
    return BDS_Vector(y * other.z - z * other.y,
                      z * other.x - x * other.z,
                      x * other.y - y * other.x);
  }
  BDS_Vector& operator += (const BDS_Vector &v)
  {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }
  BDS_Vector& operator *= (const double &v)
  {
    x *= v;
    y *= v;
    z *= v;
    return *this;
  }
  BDS_Vector& operator /= (const double &v)
  {
    x/=v;
    y/=v;
    z/=v;
    return *this;
  }
  BDS_Vector operator / (const double &v)
  {
    return BDS_Vector(x / v, y / v, z / v);
  }
  BDS_Vector operator * (const double &v)
  {
    return BDS_Vector(x * v, y * v, z * v);
  }
  double angle(const BDS_Vector &v) const
  {
    double a[3] = {x, y, z};
    double b[3] = {v.x, v.y, v.z};
    double c[3];
    c[2] = a[0] * b[1] - a[1] * b[0];
    c[1] = -a[0] * b[2] + a[2] * b[0];
    c[0] = a[1] * b[2] - a[2] * b[1];
    double cosa = a[0] * b[0] + a[1] * b[1] +a[2] * b[2];
    double sina = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
    double ag = atan2(sina, cosa);
    return ag;
  }
  double angle_deg(const BDS_Vector &v) const
  {
    return angle(v) * 180. / M_PI;
  }
  double operator * (const BDS_Vector &v) const
  {
    return (x * v.x + y * v.y + z * v.z);
  }
  BDS_Vector(const BDS_Point &p2, const BDS_Point &p1);
  
  BDS_Vector(const double X=0., const double Y=0., const double Z=0.)
    : x(X), y(Y), z(Z)
  {
  }
  static double t;
};

class BDS_Point 
{
  // the first size is the one dictated by the Background Mesh the
  // second one is dictated by charecteristic lengths at points and is
  // propagated
  double _lcBGM, _lcPTS;
public:
  double X, Y, Z;
  double u, v;
  bool config_modified;
  int iD;
  BDS_GeomEntity *g;
  std::list<BDS_Edge*> edges;
  // just a transition
  double &lcBGM() { return _lcBGM; }
  double &lc() { return _lcPTS; }
  inline bool operator < (const BDS_Point & other) const
  {
    return iD < other.iD;
  }
  inline void del(BDS_Edge *e)
  {
    std::list<BDS_Edge*>::iterator it = edges.begin();
    std::list<BDS_Edge*>::iterator ite = edges.end();
    while(it != ite){
      if(*it == e){
        edges.erase(it);
        break;
      }
      ++it;
    }
  }
  void getTriangles(std::list<BDS_Face *> &t) const;
  BDS_Point(int id, double x=0, double y=0, double z=0)
    : _lcBGM(1.e22), _lcPTS(1.e22), X(x), Y(y), Z(z), u(0), v(0),
      config_modified(true), iD(id), g(0)
  {         
  }
};

class BDS_Edge
{
  double _length;
  std::vector<BDS_Face*> _faces;
public:
  bool deleted;
  BDS_Point *p1, *p2;
  BDS_GeomEntity *g;
  inline BDS_Face *faces(int i) const
  {
    return _faces [i];
  }
  inline double length() const
  {
    return _length;
  }
  inline int numfaces() const 
  {
    return _faces.size();
  }
  int numTriangles() const ;
  inline BDS_Point *commonvertex(const BDS_Edge *other) const
  {
    if(p1 == other->p1 || p1 == other->p2) return p1;
    if(p2 == other->p1 || p2 == other->p2) return p2;
    return 0;
  }
  inline BDS_Point *othervertex(const BDS_Point *p) const
  {
    if(p1 == p) return p2;
    if(p2 == p) return p1;
    return 0;
  }
  inline void addface(BDS_Face *f)
  {
    _faces.push_back(f);
  }
  inline bool operator < (const BDS_Edge &other) const
  {
    if(*other.p1 < *p1) return true;
    if(*p1 < *other.p1) return false;
    if(*other.p2 < *p2) return true;
    return false;
  }
  inline BDS_Face * otherFace(const BDS_Face *f) const
  {
    if(numfaces()!=2) {
      Msg::Fatal("otherFace wrong, ony %d faces attached to edge %d %d",
		 numfaces(), p1->iD, p2->iD);
      return 0;
    }
    if(f == _faces[0]) return _faces[1];
    if(f == _faces[1]) return _faces[0];
    Msg::Fatal("otherFace wrong: the edge does not belong to the face");
    return 0;
  }
  inline void del(BDS_Face *t)
  {
    _faces.erase(std::remove_if(_faces.begin(),_faces.end(), 
                                std::bind2nd(std::equal_to<BDS_Face*>(), t)), 
                 _faces.end());
  }
  void oppositeof(BDS_Point * oface[2]) const; 
  void update()
  {
    _length = sqrt((p1->X - p2->X) * (p1->X - p2->X) + 
                   (p1->Y - p2->Y) * (p1->Y - p2->Y) + 
                   (p1->Z - p2->Z) * (p1->Z - p2->Z));
  }
  BDS_Edge(BDS_Point *A, BDS_Point *B) : deleted(false), g(0)
  {         
    if(*A < *B){
      p1 = A;
      p2 = B;
    }
    else{
      p1 = B;
      p2 = A;
    }
    p1->edges.push_back(this);
    p2->edges.push_back(this);
    update();
  }
};

class BDS_Face
{
public:
  bool deleted;
  BDS_Edge *e1, *e2, *e3, *e4;
  BDS_GeomEntity *g;
  inline int numEdges () const { return e4 ? 4 : 3; }
  inline BDS_Edge *oppositeEdge (BDS_Point *p)
  {
    if (e4){
      Msg::Fatal("oppositeEdge to point %d cannot be applied to a quad", p->iD);
      return 0;
    }
    if (e1->p1 != p && e1->p2 != p) return e1;
    if (e2->p1 != p && e2->p2 != p) return e2;
    if (e3->p1 != p && e3->p2 != p) return e3;
    Msg::Fatal("point %d does not belong to this triangle", p->iD);
    return 0;
  }
  inline BDS_Point *oppositeVertex (BDS_Edge *e)
  {
    if (e4){
      Msg::Fatal("oppositeVertex to edge %d %d cannot be applied to a quad", 
		 e->p1->iD, e->p2->iD);
      return 0;
    }
    if (e == e1) return e2->commonvertex(e3);
    if (e == e2) return e1->commonvertex(e3);
    if (e == e3) return e1->commonvertex(e2);
    Msg::Fatal("edge  %d %d does not belong to this triangle",
	       e->p1->iD, e->p2->iD);
    return 0;
  }
  inline void getNodes(BDS_Point *n[4]) const
  {
    if (!e4){
      n[0] = e1->commonvertex(e3);
      n[1] = e1->commonvertex(e2);
      n[2] = e2->commonvertex(e3);
      n[3] = 0;
    }
    else{
      n[0] = e1->commonvertex(e4);
      n[1] = e1->commonvertex(e2);
      n[2] = e2->commonvertex(e3);
      n[3] = e3->commonvertex(e4);
    }
  }
  BDS_Face(BDS_Edge *A, BDS_Edge *B, BDS_Edge *C,BDS_Edge *D = 0)
    : deleted(false), e1(A), e2(B), e3(C), e4(D), g(0)
  {     
    e1->addface(this);
    e2->addface(this);
    e3->addface(this);
    if(e4) e4->addface(this);
  }
};

class GeomLessThan
{
public:
  bool operator()(const BDS_GeomEntity *ent1, const BDS_GeomEntity *ent2) const
  {
    return *ent1 < *ent2;
  }
};

class PointLessThan
{
public:
  bool operator()(const BDS_Point *ent1, const BDS_Point *ent2) const
  {
    return *ent1 < *ent2;
  }
};

class PointLessThanLexicographic
{
public:
  static double t;
  bool operator()(const BDS_Point *ent1, const BDS_Point *ent2) const
  {
    if(ent1->X - ent2->X  >  t) return true;
    if(ent1->X - ent2->X  < -t) return false;
    if(ent1->Y - ent2->Y  >  t) return true;
    if(ent1->Y - ent2->Y  < -t) return false;
    if(ent1->Z - ent2->Z  >  t) return true;
    return false;
  }
};

class EdgeLessThan
{
public:
  bool operator()(const BDS_Edge *ent1, const BDS_Edge *ent2) const
  {
    return *ent1 < *ent2;
  }
};

class BDS_SwapEdgeTest
{
 public:
  virtual bool operator() (BDS_Point *p1, BDS_Point *p2,
                           BDS_Point *q1, BDS_Point *q2) const = 0; 
  virtual bool operator() (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                           BDS_Point *q1, BDS_Point *q2, BDS_Point *q3,
                           BDS_Point *op1, BDS_Point *op2, BDS_Point *op3,
                           BDS_Point *oq1, BDS_Point *oq2, BDS_Point *oq3) const = 0; 
  virtual ~BDS_SwapEdgeTest(){}
};

class BDS_SwapEdgeTestQuality : public BDS_SwapEdgeTest
{
  bool testQuality, testSmallTriangles;
 public:
  BDS_SwapEdgeTestQuality(bool a, bool b=true) : testQuality(a), testSmallTriangles(b) {}
  virtual bool operator() (BDS_Point *p1, BDS_Point *p2,
                           BDS_Point *q1, BDS_Point *q2) const ; 
  virtual bool operator() (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                           BDS_Point *q1, BDS_Point *q2, BDS_Point *q3,
                           BDS_Point *op1, BDS_Point *op2, BDS_Point *op3,
                           BDS_Point *oq1, BDS_Point *oq2, BDS_Point *oq3) const ; 
  virtual ~BDS_SwapEdgeTestQuality(){}
};

struct EdgeToRecover 
{
  int p1,p2;
  GEdge *ge;
  EdgeToRecover(int _p1, int _p2, GEdge *_ge) : ge(_ge)
  {
    if(_p1 < _p2 ){
      p1 = _p1;
      p2 = _p2;
    }
    else{
      p2 = _p1;
      p1 = _p2;
    }
  }
  bool operator < (const EdgeToRecover &other) const
  {    
    if(p1 < other.p1) return true;
    if(p1 > other.p1) return false;
    if(p2 < other.p2) return true;
    return false;
  }
};

class BDS_Mesh 
{    
public:
  int MAXPOINTNUMBER, SNAP_SUCCESS, SNAP_FAILURE;
  double Min[3], Max[3], LC;
  double scalingU, scalingV;
  BDS_Mesh(int _MAXX = 0) :  MAXPOINTNUMBER(_MAXX),scalingU(1),scalingV(1){}
  void load(GVertex *gv); // load in BDS all the meshes of the vertex 
  void load(GEdge *ge); // load in BDS all the meshes of the edge 
  void load(GFace *gf); // load in BDS all the meshes of the surface 
  virtual ~BDS_Mesh();
  BDS_Mesh(const BDS_Mesh &other);
  std::set<BDS_GeomEntity*, GeomLessThan> geom; 
  std::set<BDS_Point*, PointLessThan> points; 
  std::list<BDS_Edge*> edges; 
  std::list<BDS_Face*> triangles; 
  // Points
  BDS_Point *add_point(int num, double x, double y, double z);
  BDS_Point *add_point(int num, double u, double v, GFace *gf);
  void del_point(BDS_Point *p);
  BDS_Point *find_point(int num);
  // Edges
  BDS_Edge *add_edge(int p1, int p2);
  void del_edge(BDS_Edge *e);
  BDS_Edge *find_edge(int p1, int p2);
  BDS_Edge *find_edge(BDS_Point *p1, BDS_Point *p2);
  BDS_Edge *find_edge(BDS_Point *p1, int p2);
  BDS_Edge *find_edge(BDS_Point *p1, BDS_Point *p2, BDS_Face *t) const;
  // Triangles & Quadrangles
  BDS_Face *add_triangle(int p1, int p2, int p3);
  BDS_Face *add_quadrangle(int p1, int p2, int p3, int p4); 
  BDS_Face *add_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3);
  BDS_Face *add_quadrangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3, BDS_Edge *e4);
  void del_face(BDS_Face *t);
  BDS_Face *find_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3);
  BDS_Face *find_quadrangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3, BDS_Edge *e4);
  // Geom entities
  void add_geom(int degree, int tag);
  BDS_GeomEntity *get_geom(int p1, int p2);
  // 2D operators
  BDS_Edge *recover_edge(int p1, int p2, std::set<EdgeToRecover> *e2r=0,
                         std::set<EdgeToRecover> *not_recovered=0);
  BDS_Edge *recover_edge_fast(BDS_Point *p1, BDS_Point *p2);
  bool swap_edge(BDS_Edge*, const BDS_SwapEdgeTest &theTest);
  bool collapse_edge_parametric(BDS_Edge*, BDS_Point*);
  void snap_point(BDS_Point*, BDS_Mesh *geom = 0);
  bool smooth_point(BDS_Point*, BDS_Mesh *geom = 0);
  bool smooth_point_parametric(BDS_Point *p, GFace *gf);
  bool smooth_point_centroid(BDS_Point *p, GFace *gf, bool test_quality=false);
  bool move_point(BDS_Point *p , double X, double Y, double Z);
  bool split_edge(BDS_Edge *, BDS_Point *);
  bool split_face(BDS_Face *, BDS_Point *);
  bool edge_constraint(BDS_Point *p1, BDS_Point *p2);
  // Global operators
  void cleanup();
};

void outputScalarField(std::list<BDS_Face*> t, const char *fn, int param, GFace *gf=0);
void recur_tag(BDS_Face *t, BDS_GeomEntity *g);
int Intersect_Edges_2d(double x1, double y1, double x2, double y2,
                       double x3, double y3, double x4, double y4,
		       double x[2]);

#endif
