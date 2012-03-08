// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#ifndef _LEVY3D_H_
#define _LEVY3D_H_

#include <list>
#include "SVector3.h"
#include "fullMatrix.h"
#include "GRegion.h"
#include "MElementOctree.h"

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
  double h;
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
  double get_h();
  void set_point(SPoint3);
  void set_category(int);
  void set_index1(int);
  void set_index2(int);
  void set_index3(int);
  void set_index4(int);
  void set_normal1(SVector3);
  void set_normal2(SVector3);
  void set_h(double);
};

class Tensor{
 private:
  double t11,t12,t13,t21,t22,t23,t31,t32,t33;
 public:
  Tensor();
  ~Tensor();
  void set_t11(double);
  void set_t12(double);
  void set_t13(double);
  void set_t21(double);
  void set_t22(double);
  void set_t23(double);
  void set_t31(double);
  void set_t32(double);
  void set_t33(double);
  double get_t11();
  double get_t12();
  double get_t13();
  double get_t21();
  double get_t22();
  double get_t23();
  double get_t31();
  double get_t32();
  double get_t33();
};

class VoronoiElement{
 private:
  VoronoiVertex v1;
  VoronoiVertex v2;
  VoronoiVertex v3;
  VoronoiVertex v4;
  double jacobian;
  double dh_dx;
  double dh_dy;
  double dh_dz;
  Tensor t;
 public:
  VoronoiElement();
  ~VoronoiElement();
  VoronoiVertex get_v1();
  VoronoiVertex get_v2();
  VoronoiVertex get_v3();
  VoronoiVertex get_v4();
  double get_jacobian();
  double get_dh_dx();
  double get_dh_dy();
  double get_dh_dz();
  Tensor get_tensor();
  void set_v1(VoronoiVertex);
  void set_v2(VoronoiVertex);
  void set_v3(VoronoiVertex);
  void set_v4(VoronoiVertex);
  void set_tensor(Tensor);
  double get_h(double,double,double);
  void deriv_h();
  void compute_jacobian();
  double T(double,double,double,double,double,double,double);
  void swap();
  double get_quality();
};

class LpSmoother{
 private:
  int max_iter;
  int norm;
  static std::vector<MVertex*> interior_vertices;
 public:
  LpSmoother(int,int);
  ~LpSmoother();
  void improve_model();
  void improve_region(GRegion*);
  double get_size(double,double,double);
  static int get_nbr_interior_vertices();
  static MVertex* get_interior_vertex(int);
};

#endif
