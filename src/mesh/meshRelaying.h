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
  SVector3 closestCorner2d (const SVector3 &P);
  bool empty() const {return pos.empty();}
  //  void move (double dt);
  void moveFromV (double dt, const std::vector<SVector3> &V, bool bnd);
  void moveFromFront(double dt, const std::vector<SVector3> &v);
  //  virtual SVector3 velocity (double x, double y, double z, double t, int col);
  void printGeometry(FILE *f);
  int whatIsTheColorOf2d (const SVector3 &P);
  double massMarkers (int color);
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
    if (empty())return;
    SVector3 p0 (pos[3*lines[l]],pos[3*lines[l]+1],pos[3*lines[l]+2]);
    SVector3 p1 (pos[3*lines[l+1]],pos[3*lines[l+1]+1],pos[3*lines[l+1]+2]);
    double d = (p1-p0).norm();
    double a = (t-p0).norm() / d;
    fn.push_back(frontNode (n,l,a));
  }
  std::vector<std::pair<size_t,size_t> > getFrontEdges();  
  void printMesh (FILE *f);
  //-----------------------------------------------------------------------------------
  // --> should be simplified to
  void addGmshModel (const char *fn);
  // basic shapes
  void addFreeForm (int tag, const std::vector<SVector3> &poly, const std::vector<size_t> &_corners);
  void getDFPosition(std::vector<double> &position, std::vector<int> &tags);
  void clear();
  void redistFront(double lc);
  void adjustBnd(const std::vector<std::pair<size_t,size_t>> &bnd1d);
  void addLines (std::vector<double> &p, std::vector<size_t> &l, std::vector<int> &c, const std::vector<size_t> &_corners){
    size_t n = colors.size();
    pos.insert (pos.end(), p.begin(), p.end());
    colors.insert (colors.end(), c.begin(), c.end());
    for (size_t i=0;i<l.size();i++)lines.push_back(l[i]+n);
    for (size_t i=0;i<_corners.size(); i++) corners.push_back(_corners[i]+n);
  }
  //  void forceMassConservation ( double mass , int color );  
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

  std::vector<std::vector<double> > levelsets;

  double _distMax, _RATIO;
  
  static meshRelaying *_instance;
  meshRelaying (GModel *gm = nullptr); // use GModel gm or Gmodel::current() if NULL  
  public :
    static meshRelaying *instance() {
      if(!_instance) _instance = new meshRelaying();
      return _instance;
    }

  void doRelaying (const std::function<std::vector<std::pair<double, int> >(size_t, size_t)> &f); 

  void setLevelsets (const std::vector<std::vector<double> > &_ls){
    levelsets = _ls;
  }

  void setDiscreteFrontBBox (){    
    SBoundingBox3d bbox;
    for (size_t i=0;i<pos.size();i+=3)
      bbox += SPoint3(pos[i],pos[i+1],pos[i+2]);    
    bbox *= 1.01;
    discreteFront::instance()->setBbox (bbox);
  }

  void advanceInTime(double dt, std::vector<SVector3> &v, bool front = false){
    if(front)
      discreteFront::instance()->moveFromFront(dt, v);
    else 
      discreteFront::instance()->moveFromV(dt, v, true);
  }
  void setPos (size_t i, double x, double y, double z){
    pos[3*i] = x;
    pos[3*i+1] = y;
    pos[3*i+2] = z;
  }
  void doRelaying (double t);
  double myDensity2D(size_t iTriangle,  double distMax, double RATIO, std::vector<double> &distances);
  void untangle (double lambda=1.0, int nIterOut=10, int nIterIn=1000, double distMax = 0.1, double RATIO = 5.0);
  void restoreInitialMesh ();
  void print4debug(const char *);
  void concentration(std::vector<int> *concentration);
  void getNodesPosition(std::vector<double> &position){
    position = pos;
  }

  void getFrontNodesPosition(std::vector<double> &position){
    std::sort(front_nodes.begin(), front_nodes.end());
    for(size_t i=0; i<front_nodes.size(); ++i){
      position.push_back(pos[3*front_nodes[i]]);
      position.push_back(pos[3*front_nodes[i]+1]);
      position.push_back(pos[3*front_nodes[i]+2]);
    }
  }

  void redistFront(double lc){
    discreteFront::instance()->redistFront(lc);
  }
  
  void setBndFront();
  double smallest_measure (const size_t n, const SVector3 &target) ;  
  double massElements (int color);
  double qualityElement (size_t elem);
  void adjustBnd(){
    discreteFront::instance()->adjustBnd(bnd1d);
  }  
  void curvature(std::vector<int> concentration, std::vector<double> *curvature);
};

void projectPonLine(double A[2], double B[2], double P[2], double *proj);
double kappa(double x1[2], double x2[2], double x3[2]);

#endif
