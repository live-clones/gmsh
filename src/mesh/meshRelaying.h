#ifndef _MESH_RELAYING_
#define _MESH_RELAYING_

#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include "SVector3.h"
#include "SBoundingBox3d.h"

class GModel;

class edgeCut {
public:
  size_t a,b;
  SVector3 p;
  double d;  
  int index;
  edgeCut (size_t _a, size_t _b, SVector3 _p, double _d, int _i) : a(_a) , b(_b), p(_p), d(_d), index(_i) {     
  }
  bool operator < (const edgeCut &o) const{
    if (d < o.d)return true;
    return false;
  }
};

class frontNode {
 public :
  size_t meshNode;
  size_t line;
  double t;
  frontNode (size_t n, size_t l, double _t) : meshNode (n), line(l), t(_t){
  }
  bool operator < (const frontNode &other) const{
    if (line != other.line)return line<other.line;
    return t < other.t;
  }
};

class discreteFront {
  //  int64_t octree;
  std::vector<int> colors;
  std::vector<size_t> corners;
  std::vector<size_t> lines;
  std::vector<double> pos;
  double t;
  std::vector<frontNode> fn;
  
  // Let us thus use a search structure based on edges  
  std::vector<std::vector<size_t> > sss;
  size_t NX, NY;
  SBoundingBox3d bbox;
  void getCoordinates(double x, double y, int &IX, int &IY);
  
  discreteFront (){}
  static discreteFront *_instance;
 public :
  static discreteFront *instance() {
    if(!_instance) _instance = new discreteFront();
    return _instance;
  }
  // assume 2D x y here !!!!
  void intersectLine2d (const SVector3 &p0, const SVector3 &p1,
			std::vector<double> &d, std::vector<int> &c);
  void cornersInTriangle2d (const SVector3 &p0, const SVector3 &p1, const SVector3 &p2,
			    std::vector<SVector3> &c, std::vector<int> &col);
  SVector3 closestPoints2d (const SVector3 &P);
  bool empty() const {return pos.empty();}
  void move (double dt);
  void moveFromV (double dt, std::vector<SVector3> V, bool bnd);
  void moveFromFront(double dt, std::vector<SVector3> v);
  virtual SVector3 velocity (double x, double y, double z, double t, int col);
  void printGeometry(FILE *f);
  int whatIsTheColorOf2d (const SVector3 &P);
  int getColor(int i){return colors[i/2];}
  void buildSpatialSearchStructure ();
  int dim() const {return 2;}
  void setBbox (SBoundingBox3d _bbox){bbox=_bbox;}
  // ------------------------------------
  // --> tell what are mesh nodes  
  void clearFrontNodes(){
    fn.clear();
  }
  void addFrontNode(size_t n, size_t l, SVector3 t){
    SVector3 p0 (pos[3*lines[l]],pos[3*lines[l]+1],pos[3*lines[l]+2]);
    SVector3 p1 (pos[3*lines[l+1]],pos[3*lines[l+1]+1],pos[3*lines[l+1]+2]);
    double d = (p1-p0).norm();
    double a = (t-p0).norm() / d;
    fn.push_back(frontNode (n,l,a));
  }
  std::vector<std::pair<size_t,size_t> > getFrontEdges();  
  void printMesh (FILE *f);

  SVector3 relaxFrontNode (size_t i);

  //-----------------------------------------------------------------------------------
  // --> should be simplified to
  void addGmshModel (const char *fn);
  // basic shapes
  void addEllipsis (int tag, double xc, double yc, double theta0, double r1, double r2, int n);
  void addRectangle (int tag, double xc, double yc, double r1, double r2, int n);
  void addPolygon (int tag, const std::vector<SVector3> &poly, int n);
  void addFreeForm (int tag, const std::vector<SVector3> &poly);
  void getDFPosition(std::vector<double> *position, std::vector<int> *tags);
  void clear();
  void redistFront(double lc);
  void adjustBnd(std::vector<std::pair<size_t,size_t>> bnd1d);
  //-----------------------------------------------------------------------------------
  // --> boolean operator 
  void boolOp ();
  // create a loop
  void addLines (std::vector<double> &p, std::vector<size_t> &l, std::vector<int> &c){
    size_t n = colors.size();
    pos.insert (pos.end(), p.begin(), p.end());
    colors.insert (colors.end(), c.begin(), c.end());
    for (size_t i=0;i<l.size();i++)lines.push_back(l[i]+n);
  }
  
};



class meshRelaying {

  std::vector<std::vector<size_t> > v2v;

  std::vector<std::vector<size_t> > v2tet;
  std::vector<std::vector<size_t> > v2tri;
  std::vector<std::vector<size_t> > v2edg;

  std::vector<size_t> tets;
  std::vector<size_t> tris;
  std::vector<size_t> edgs;

  std::vector<size_t> front_nodes;
  std::vector<double> pos;
  std::vector<double> initial_pos;
  std::vector<std::pair<size_t,size_t> > bnd2d;
  std::vector<std::pair<size_t,size_t> > bnd1d;
  std::vector<size_t> corners;
  std::vector<size_t> dimVertex;

  
  //// levelset function that drives relaying
  double time;  
  std::function<double (double, double, double, double)> levelset;

  /// functions for optimization
  double smallest_measure (const size_t n, 
			const SVector3 &target) ;  

  static meshRelaying *_instance;
  meshRelaying (GModel *gm = nullptr); // use GModel gm or Gmodel::current() if NULL  
  public :
    static meshRelaying *instance() {
      if(!_instance) _instance = new meshRelaying();
      return _instance;
    }

  void doRelaying (const std::function<std::vector<std::pair<double, int> >(size_t, size_t)> &f); 
  void setLevelset (const std::function<double(double, double, double, double)> &_ls){
    levelset = _ls;
  }
  void setDiscreteFrontBBox (){    
    SBoundingBox3d bbox;
    for (size_t i=0;i<pos.size();i+=3)
      bbox += SPoint3(pos[i],pos[i+1],pos[i+2]);    
    bbox *= 1.01;
    discreteFront::instance()->setBbox (bbox);
  }
  void advanceInTime(double dt, std::vector<SVector3> v = std::vector<SVector3>(), bool front = false){
    if(front){
      discreteFront::instance()->moveFromFront(dt, v);
    } else if(v.empty()){
      discreteFront::instance()->move(dt);
    } else {
      discreteFront::instance()->moveFromV(dt, v, true);
    }
    
  }
  void doRelaying (double t);
  void doRelax (double r);
  void doRelaxFrontNode (size_t i, const std::vector<size_t> &n, double r, std::vector<std::pair<size_t,size_t> > &fe);
  void print4debug(const char *);
  void concentration(std::vector<int> *concentration);
  void getNodesPosition(std::vector<double> *position){
    for(int i=0; i<pos.size(); ++i){
      position->push_back(pos[i]);
    }
  }

  void getFrontNodesPosition(std::vector<double> *position){
    std::sort(front_nodes.begin(), front_nodes.end());
    for(int i=0; i<front_nodes.size(); ++i){
      position->push_back(pos[3*front_nodes[i]]);
      position->push_back(pos[3*front_nodes[i]+1]);
      position->push_back(pos[3*front_nodes[i]+2]);
    }
  }

  void redistFront(double lc){
    discreteFront::instance()->redistFront(lc);
  }

  void setBndFront();
  void adjustBnd(){
    discreteFront::instance()->adjustBnd(bnd1d);
  }
  

};

void projectPonLine(double A[2], double B[2], double P[2], double *proj);

/*
  FOR API
*/

void concentration(std::vector<int> &concentration);
void advanceInTime(double dt, std::vector<SVector3> v, bool front);
void addFreeForm(int tag, const std::vector<SVector3> &poly);
void getDFPosition(std::vector<double> &api_position, std::vector<int> &api_tags);
void getNodesPosition(std::vector<double> &api_position);
void getFrontNodesPosition(std::vector<double> &api_position);
void setDiscreteFront();
void relayingAndRelax();
void initRelaying();
void resetDiscreteFront();
void redistFront(double lc);
void setBndFront();

#endif
