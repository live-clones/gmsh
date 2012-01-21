// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include "SVector3.h"
#include <list>
#include "fullMatrix.h"
#include "GRegion.h"
class MElementOctree;

/*********class VoronoiVertex*********/

class VoronoiVertex{
 private:
  SPoint3 point;
  int category;
  int index1;
  int index2;
  int index3;
  int index4;
  SVector3 normal1;
  SVector3 normal2;
  double rho;
 public:
  VoronoiVertex();
  ~VoronoiVertex();
  SPoint3 get_point();
  int get_category();
  int get_index1();
  int get_index2();
  int get_index3();
  int get_index4();
  SVector3 get_normal1();
  SVector3 get_normal2();
  double get_rho();
  void set_point(SPoint3);
  void set_category(int);
  void set_index1(int);
  void set_index2(int);
  void set_index3(int);
  void set_index4(int);
  void set_normal1(SVector3);
  void set_normal2(SVector3);
  void set_rho(double);
};

/*********class Metric*********/

class Metric{
 private:
  double m11,m12,m13,m21,m22,m23,m31,m32,m33;
 public:
  Metric();
  ~Metric();
  void set_m11(double);
  void set_m12(double);
  void set_m13(double);
  void set_m21(double);
  void set_m22(double);
  void set_m23(double);
  void set_m31(double);
  void set_m32(double);
  void set_m33(double);
  double get_m11();	
  double get_m12();	
  double get_m13();	
  double get_m21();
  double get_m22();
  double get_m23();
  double get_m31();
  double get_m32();
  double get_m33();
};

/*********class VoronoiElement*********/

class VoronoiElement{
 private:
  VoronoiVertex v1;
  VoronoiVertex v2;
  VoronoiVertex v3;
  VoronoiVertex v4;
  double jacobian;
  double drho_dx;
  double drho_dy;
  double drho_dz;
  Metric m;
 public:
  VoronoiElement();
  ~VoronoiElement();
  VoronoiVertex get_v1();
  VoronoiVertex get_v2();
  VoronoiVertex get_v3();
  VoronoiVertex get_v4();
  double get_jacobian();
  double get_drho_dx();
  double get_drho_dy();
  double get_drho_dz();
  Metric get_metric();
  void set_v1(VoronoiVertex);
  void set_v2(VoronoiVertex);
  void set_v3(VoronoiVertex);
  void set_v4(VoronoiVertex);
  void set_metric(Metric);
  double get_rho(double,double,double);
  void deriv_rho();
  void compute_jacobian();
  double T(double,double,double,double,double,double,double);
  double h_to_rho(double,int);
  void swap();
};

/*********class LpCVT*********/

class LpCVT{
 private:
  std::list<VoronoiElement> clipped;
  fullMatrix<double> gauss_points;
  fullMatrix<double> gauss_weights;
  int gauss_num;
 public:
  LpCVT();
  ~LpCVT();
  void swap();
  void compute_parameters(int);
  void get_gauss();
  double F(VoronoiElement,int);
  SVector3 simple(VoronoiElement,int);
  SVector3 dF_dC1(VoronoiElement,int);
  SVector3 dF_dC2(VoronoiElement,int);
  SVector3 dF_dC3(VoronoiElement,int);
  double f(SPoint3,SPoint3,Metric,int);
  double df_dx(SPoint3,SPoint3,Metric,int);
  double df_dy(SPoint3,SPoint3,Metric,int);
  double df_dz(SPoint3,SPoint3,Metric,int);
  SVector3 bisectors3(SVector3,SPoint3,SPoint3,SPoint3,SPoint3,SPoint3);
  SVector3 bisectors2(SVector3,SPoint3,SPoint3,SPoint3,SPoint3,SVector3);
  SVector3 bisectors1(SVector3,SPoint3,SPoint3,SPoint3,SVector3,SVector3);
  void clear();
};

/*********class LpSmoother*********/

class LpSmoother{
 private:
  int max_iter;
  int norm;
 public:
  LpSmoother(int,int);
  ~LpSmoother();
  void improve_model();
  void improve_region(GRegion*);
};

/*********class Wrap*********/

class Wrap{
 private:
  int p;
  int dimension;
  int iteration;
  int max_iteration;
  double initial_energy;
  MElementOctree* octree;
 public:
  Wrap();
  ~Wrap();
  int get_p();
  int get_dimension();
  int get_iteration();
  int get_max_iteration();
  double get_initial_energy();
  MElementOctree* get_octree();
  void set_p(int);
  void set_dimension(int);
  void set_iteration(int);
  void set_max_iteration(int);
  void set_initial_energy(double);
  void set_octree(MElementOctree*);
};

/*********functions*********/

bool inside_domain(MElementOctree*,double,double,double);
