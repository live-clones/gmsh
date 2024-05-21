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
  size_t interface;
  size_t m1;
  size_t m2;
  edgeCut (size_t _a, size_t _b, SVector3 _p, double _d, size_t _interface, size_t _m1, size_t _m2) : a(_a) , b(_b), p(_p), d(_d), interface(_interface), m1(_m1), m2(_m2){     
  }
  bool operator < (const edgeCut &o) const{
    if (d < o.d)return true;
    return false;
  }
};

class frontNode {
 public :
  size_t meshNode;
  size_t interface;
  size_t m1;
  size_t m2;
  double t;
  frontNode (size_t n, size_t _interface, size_t _m1, size_t _m2, double _t) : meshNode (n), interface(_interface), m1(_m1), m2(_m2), t(_t){
  }
  bool operator < (const frontNode &other) const{
    if (m1 != other.m1)return m1<other.m1;
    return t < other.t;
  }
};

class triple_p {
  public:
    size_t marker;
    size_t id_interface;
    size_t id_marker;
    int tag;
    double pos[3];
    size_t id_on_interface;
    size_t id_on_marker;
    int sense;

    triple_p(size_t _marker, size_t _id_interface, size_t _id_marker, int _tag, double *_pos){
      marker = _marker;
      id_interface = _id_interface;
      id_marker = _id_marker;
      tag = _tag;
      pos[0] = _pos[0];
      pos[1] = _pos[1];
      pos[2] = _pos[2];
    }

    triple_p(){

    }
};

class interface {
  public:
    size_t id;
    int tag;
    std::vector<size_t> markers;
    std::vector<size_t> triple;
    int sense;

    interface(size_t _id, int _tag, std::vector<size_t> _markers){
      id = _id;
      tag = _tag;
      markers = _markers;
      triple = {};
      sense = 1;
    }
};

struct T_node {
    size_t id;
    std::vector<T_node *>leafs;
    int tag;
    int data=0;
};

T_node *newT_node(size_t id, int tag);

class discreteFront {
  //  int64_t octree;
  std::vector<int> colors;
  std::vector<size_t> corners;
  std::vector<size_t> lines;
  std::vector<double> pos;
  double t;
  std::vector<frontNode> fn;

  //new way with interface and triple points
  std::vector<interface> interfaces;
  std::vector<std::vector<std::pair<size_t,std::pair<int,int>>>> sss_inter;
  std::vector<int> priority {-1, 0, 1, 2, 3}; 
  std::vector<triple_p> triple_points;
  T_node *Tree;
  size_t nT_node;
  
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
  //  SVector3 closestPoints2d (const SVector3 &P);
  bool empty() const {return pos.empty();}
  //  void move (double dt);
  void moveFromV (double dt, const std::vector<SVector3> &v, bool bnd);
  void moveFromFront(double dt, const std::vector<SVector3> &v);
  //  virtual SVector3 velocity (double x, double y, double z, double t, int col);
  void printGeometry(FILE *f);
  int whatIsTheColorOf2d (const SVector3 &P, std::vector<std::vector<size_t>> loops, std::vector<int> loops_tags);
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
  void addFrontNode(size_t n, size_t inter, size_t m1, size_t m2, SVector3 t){
    if(m1==m2){
      fn.push_back(frontNode (n,inter,m1,m2,1.0));
      return;
    }
    SVector3 p0 (pos[3*m1],pos[3*m1+1],pos[3*m1+2]);
    SVector3 p1 (pos[3*m2],pos[3*m2+1],pos[3*m2+2]);
    double d = (p1-p0).norm();
    if(d<1e-10){
      fn.push_back(frontNode (n,inter,m1,m2,1.0));
      return;
    }
    double a = (t-p0).norm() / d;
    fn.push_back(frontNode (n,inter,m1,m2,a));
  }
  std::vector<std::pair<size_t,size_t> > getFrontEdges();  
  void printMesh (FILE *f);
  //-----------------------------------------------------------------------------------
  // --> should be simplified to
  void addGmshModel (const char *fn);
  // basic shapes
  void addFreeForm (int tag, const std::vector<SVector3> &poly, const std::vector<size_t> &_corners, const int sense);
  void getDFPosition(std::vector<double> &position, std::vector<int> &tags);
  void clear();
  void redistFront(double lc);
  void redistFrontNew(double lc);
  void adjustBnd(const std::vector<std::pair<size_t,size_t>> &bnd1d);
  void printInterfaces(FILE *f);
  void buildSpatialSearchStructureInterface();
  void intersectInterfaces(std::vector<std::pair<size_t, size_t>> *interactions);
  void bool_op_priority();
  void mergeLoop(std::vector<size_t> loop1, std::vector<size_t> loop2, std::vector<size_t> inter, std::vector<size_t> *merged);
  int insideList(std::vector<size_t> loop, double P[2]);
  void loop1Minusloop2(std::vector<size_t> loop1, std::vector<size_t> loop2, std::vector<size_t> inter, std::vector<size_t> *minus);
  void loop1Minusloop2_inside(std::vector<size_t> loop1, std::vector<size_t> loop2, std::vector<size_t> inter, std::vector<size_t> *minus);
  void autoIntersect(std::vector<size_t> loop, std::vector<size_t> inter, std::vector<size_t> *outside, std::vector<size_t> *inside);
  void autoIntersectNew(std::vector<size_t> loop, std::vector<size_t> inter, std::vector<std::vector<size_t>> *new_loops, std::vector<int> *new_loops_tags);
  void loops2Interfaces(std::vector<std::vector<size_t>> loops, std::vector<int> loops_tags, std::vector<int> loops_sense, std::vector<interface> *new_interfaces);
  void interfaces2Loops(std::vector<std::vector<size_t>> *new_loops, std::vector<int> *new_loops_tags, std::vector<int> *new_loops_sense);
  void createTree();
  void renumberLoops(std::vector<std::vector<size_t>> loops, std::vector<std::vector<size_t>> *new_loops, std::vector<double> *new_pos);
  void interactionsOrder(std::vector<std::pair<size_t,size_t>> interactions, std::vector<std::pair<size_t,size_t>> *ordered);
  void manageIntersection(std::vector<std::pair<size_t,size_t>> ordered, std::vector<std::vector<size_t>> loops, std::vector<int> loops_tags, std::vector<int> loops_sense, std::vector<size_t> inter_markers, std::vector<std::vector<size_t>> *new_loops, std::vector<int> *new_loops_tags, std::vector<int> *new_loops_sense);
  size_t findMarker(size_t marker);
  void tripleInTriangle2d (const SVector3 &p0, const SVector3 &p1, const SVector3 &p2, std::vector<size_t> &interface_id, std::vector<size_t> &m1, std::vector<size_t> &m2, std::vector<SVector3> &p_out);
  void choose2Inter(std::vector<size_t> loop1, std::vector<size_t> loop2, std::vector<size_t> *inter, bool start_outside);
  //-----------------------------------------------------------------------------------
  // --> boolean operator 
  void boolOp ();
  // create a loop
  void addLines (std::vector<double> &p, std::vector<size_t> &l, std::vector<int> &c, const std::vector<size_t> &_corners){
    size_t n = colors.size();
    pos.insert (pos.end(), p.begin(), p.end());
    colors.insert (colors.end(), c.begin(), c.end());
    for (size_t i=0;i<l.size();i++)lines.push_back(l[i]+n);
    for (size_t i=0;i<_corners.size(); i++) corners.push_back(_corners[i]+n);
  }
  //  void forceMassConservation ( double mass , int color );  

  void addInterface (std::vector<double> &p, int tag, int sense){
    size_t n_interface = interfaces.size();
    size_t n_marker = pos.size()/3;
    size_t n = p.size()/3;
    pos.insert (pos.end(), p.begin(), p.end()); 
    std::vector<size_t> m(n);
    std::iota(std::begin(m), std::end(m), n_marker);
    interface i = interface(n_interface, tag, m);
    i.sense = sense;
    interfaces.push_back(i);
  }

  void setInterfaces(std::vector<interface> _interfaces){
    interfaces = _interfaces;
  }

  void renumberInterfaces();
  size_t max_marker();
  
  
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
  
  static meshRelaying *_instance;
  meshRelaying (GModel *gm = nullptr); // use GModel gm or Gmodel::current() if NULL  
  public :
    static meshRelaying *instance() {
      if(!_instance) _instance = new meshRelaying();
      return _instance;
    }

  void doRelaying (const std::function<std::vector<std::pair<double, std::pair<size_t, size_t>> >(size_t, size_t)> &f); 

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
    discreteFront::instance()->createTree();
    discreteFront::instance()->moveFromV(dt, v, true);
    printf("after v \n");
    printf("before build \n");
    print4debug("before_build.pos");
    discreteFront::instance()->buildSpatialSearchStructureInterface();
    printf("after build \n");
    size_t old_max = discreteFront::instance()->max_marker();
    std::vector<std::pair<size_t, size_t>> interactions;
    discreteFront::instance()->intersectInterfaces(&interactions);
    size_t new_max = discreteFront::instance()->max_marker();
    std::vector<size_t> inter_markers;
    for(size_t i=old_max+1; i<new_max+1; ++i){
      inter_markers.push_back(i);
    }
    FILE *f1 = fopen("after_intersect.pos", "w");
    discreteFront::instance()->printInterfaces(f1);
    fclose(f1);
    printf("after intersect \n");
    std::vector<std::pair<size_t, size_t>> ordered;
    printf("before order \n");
    discreteFront::instance()->interactionsOrder(interactions, &ordered);
    for(size_t i=0; i<ordered.size(); ++i){
      printf("ordered %d, %d \n", ordered[i].first, ordered[i].second);
    }
    std::vector<std::vector<size_t>> loops;
    std::vector<int> loops_tags;
    std::vector<int> loops_sense;
    discreteFront::instance()->interfaces2Loops(&loops, &loops_tags, &loops_sense);
    printf("\n interface2loops \n");
    for(size_t i=0; i<loops.size(); ++i){
      printf("loop %d, %d \n", loops_tags[i], loops_sense[i]);
      for(size_t j=0; j<loops[i].size(); ++j){
        printf(" %d,", loops[i][j]);
      }
      printf("\n");
    }
    
    printf("after loops \n");
    FILE *f = fopen("interfaces_before.pos", "w");
    discreteFront::instance()->printInterfaces(f);
    fclose(f);
    std::vector<std::vector<size_t>> new_loops;
    std::vector<int> new_loops_tags;
    std::vector<int> new_loops_sense;
    
    discreteFront::instance()->manageIntersection(ordered, loops, loops_tags, loops_sense, inter_markers, &new_loops, &new_loops_tags, &new_loops_sense);
    printf("after manage \n");
    std::vector<interface> new_interfaces;
    discreteFront::instance()->loops2Interfaces(new_loops, new_loops_tags, new_loops_sense, &new_interfaces);

    printf("after loops2Interfaces \n");
    for(size_t i=0; i<new_interfaces.size(); ++i){
      printf("interface %d, %d \n", new_interfaces[i].id, new_interfaces[i].tag);
      for(size_t j=0; j<new_interfaces[i].markers.size(); ++j){
        printf(" %d,", new_interfaces[i].markers[j]);
      }
      printf("\n");
    }
    //set new interfaces
    discreteFront::instance()->setInterfaces(new_interfaces);
    printf("after set \n");

    // 
    // if(front)
    //   discreteFront::instance()->moveFromFront(dt, v);
    // else 
    //   discreteFront::instance()->moveFromV(dt, v, true);
  }

  void setPos (size_t i, double x, double y, double z){
    pos[3*i] = x;
    pos[3*i+1] = y;
    pos[3*i+2] = z;
  }

  void doRelaying (double t);
  void untangle ();
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
    discreteFront::instance()->redistFrontNew(lc);
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
int computeIntersection(double a1[2], double a2[2], double a3[2], double a4[2], double *inter, double *param);
double loopOrientation(std::vector<double> pos);
#endif
