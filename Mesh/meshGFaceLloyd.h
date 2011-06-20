// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_LLOYD_H_
#define _MESH_GFACE_LLOYD_H_
#include "fullMatrix.h"
#include "DivideAndConquer.h"
#include <queue>
#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h" 
#include "linalg.h"
#include "optimization.h"
#include "MElementOctree.h"

class GFace;
class voronoi_vertex;
class voronoi_element;
class voronoi_cell;  
class segment;
class segment_list;
class metric;

void callback(const alglib::real_1d_array&,double&,alglib::real_1d_array&,void*);
bool domain_search(MElementOctree*,double,double);

class smoothing{
  int ITER_MAX;
  int NORM;
 public :
  smoothing(int,int);
  void optimize_face(GFace*);
  void optimize_model();
};

class lpcvt{
 private :
  std::list<voronoi_element> clipped;
  std::queue<int> fifo;
  std::vector<segment_list> borders;
  std::vector<double> angles;
  std::vector<voronoi_cell> temp;
  fullMatrix<double> gauss_points;
  fullMatrix<double> gauss_weights;
  std::vector<metric> metrics;
  int gauss_num;
  GFace* work_around;
 public :
  lpcvt();
  ~lpcvt();
  double angle(SPoint2,SPoint2,SPoint2);
  SVector3 normal(SPoint2,SPoint2);
  SPoint2 mid(SPoint2,SPoint2);
  bool same_side(SPoint2,SPoint2,SPoint2,SPoint2);
  bool interior(DocRecord&,GFace*,int);
  bool interior(DocRecord&,segment,segment,double,SPoint2);
  bool invisible(DocRecord&,GFace*,int);
  bool real(DocRecord&,int,int,int);
  double triangle_area(SPoint2,SPoint2,SPoint2);
  bool sliver(SPoint2,SPoint2,SPoint2);
  SPoint2 intersection(DocRecord&,segment,segment,SPoint2,SPoint2,bool&,SVector3&,segment&);
  SPoint2 intersection(SPoint2,SPoint2,SPoint2,SPoint2,bool&);
  SPoint2 convert(DocRecord&,int);
  SPoint2 circumcircle(DocRecord&,int,int,int);
  SPoint2 seed(DocRecord&,GFace*);
  void step1(DocRecord&,GFace*);
  void step2(DocRecord&,GFace*);
  void step3(DocRecord&,GFace*);
  void step4(DocRecord&,GFace*);
  void step5(DocRecord&,GFace*);
  void clip_cells(DocRecord&,GFace*);
  void clear();
  double total_area();
  void print_voronoi1();
  void print_voronoi2();
  void print_delaunay(DocRecord&);
  void print_segment(SPoint2,SPoint2,std::ofstream&);

  void compute_metrics(DocRecord&);
  void compute_parameters(int);
  double ratio(SPoint2);
  void write(DocRecord&,GFace*,int);
  void eval(DocRecord&,std::vector<SVector3>&,double&,int);
  void swap();
  void get_gauss();
  double F(voronoi_element,int,int);
  SVector3 simple(voronoi_element,int,int);
  SVector3 dF_dC1(voronoi_element,int,int);
  SVector3 dF_dC2(voronoi_element,int,int);
  double f(SPoint2,SPoint2,int,int);
  double df_dx(SPoint2,SPoint2,int,int);
  double df_dy(SPoint2,SPoint2,int,int);
  double Tx(double,double,SPoint2,SPoint2,SPoint2);
  double Ty(double,double,SPoint2,SPoint2,SPoint2);
  double J(SPoint2,SPoint2,SPoint2);
  SVector3 inner_dFdx0(SVector3,SPoint2,SPoint2,SPoint2,SPoint2);
  SVector3 boundary_dFdx0(SVector3,SPoint2,SPoint2,SPoint2,SVector3);
};

class voronoi_vertex{
 private :
  SPoint2 point;
  int index1;
  int index2;
  int index3;
  SVector3 normal;
  bool duplicate;
  double h;
 public :
  voronoi_vertex(SPoint2);
  voronoi_vertex();
  ~voronoi_vertex();
  SPoint2 get_point();
  int get_index1();
  int get_index2();
  int get_index3();
  SVector3 get_normal();
  bool get_duplicate();
  double get_h();
  void set_point(SPoint2);
  void set_index1(int);
  void set_index2(int);
  void set_index3(int);
  void set_normal(SVector3);
  void set_duplicate(bool);
  void set_h(double);
};

class voronoi_element{
 private :
  voronoi_vertex v1;
  voronoi_vertex v2;
  voronoi_vertex v3;
  double drho_dx;
  double drho_dy;
 public :
  voronoi_element(voronoi_vertex,voronoi_vertex,voronoi_vertex);
  voronoi_element();
  ~voronoi_element();
  voronoi_vertex get_v1();
  voronoi_vertex get_v2();
  voronoi_vertex get_v3();
  double get_rho(double,double,int);
  double get_drho_dx();
  double get_drho_dy();
  void set_v1(voronoi_vertex);
  void set_v2(voronoi_vertex);
  void set_v3(voronoi_vertex);
  void deriv_rho(int);
  double compute_rho(double,int);
};

class voronoi_cell{
 private :
  std::vector<voronoi_vertex> vertices;
 public :
  voronoi_cell();
  ~voronoi_cell();
  int get_number_vertices();
  voronoi_vertex get_vertex(int);
  void add_vertex(voronoi_vertex);
  void clear();
};

class segment{
 private :
  int index1;
  int index2;
  int reference;
 public :
  segment(int,int,int);
  segment();
  ~segment();
  int get_index1();
  int get_index2();
  int get_reference();
  void set_index1(int);
  void set_index2(int);
  void set_reference(int);
  bool equal(int,int);
};

class segment_list{
 private :
  std::vector<segment> segments;
 public :
  segment_list();
  ~segment_list();
  int get_number_segments();
  segment get_segment(int);
  bool add_segment(int,int,int);
  bool add_segment(segment);
};

class metric{
 private :
  double a,b,c,d;
 public :
  metric(double,double,double,double);
  metric();
  ~metric();
  void set_a(double);	
  void set_b(double);	
  void set_c(double);	
  void set_d(double);	
  double get_a();	
  double get_b();	
  double get_c();	
  double get_d();
};

class wrapper{
 private :
  int p;
  int dimension;
  GFace* gf;
  int iteration;
  int max;
  double start;
  DocRecord* triangulator;
  MElementOctree* octree;
 public :
  wrapper();
  ~wrapper();
  int get_p();
  void set_p(int);
  int get_dimension();
  void set_dimension(int);
  GFace* get_face();
  void set_face(GFace*);
  int get_iteration();
  void set_iteration(int);
  int get_max();
  void set_max(int);
  double get_start();
  void set_start(double);
  DocRecord* get_triangulator();
  void set_triangulator(DocRecord*);
  MElementOctree* get_octree();
  void set_octree(MElementOctree*);
};

#endif
