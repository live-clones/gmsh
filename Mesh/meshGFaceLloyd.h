// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_LLOYD_H_
#define _MESH_GFACE_LLOYD_H_
#include "fullMatrix.h"
#include "DivideAndConquer.h"
#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h"
#include "linalg.h"
#include "optimization.h"

class GFace;
class boundary_edge;

void function1_grad(const alglib::real_1d_array&,double&,alglib::real_1d_array&,void*);
void topology(const alglib::real_1d_array &,double,void*);

class lloydAlgorithm {
  int ITER_MAX;
  bool infiniteNorm;
  double test;
 public :
  lloydAlgorithm (int itermax, bool infnorm = false)
  : ITER_MAX(itermax), infiniteNorm(infnorm) {}
  lloydAlgorithm() {}
  void operator () (GFace *);
  double optimize(int,int);
  
  void eval(DocRecord&,GFace*,std::vector<SVector3>&,std::vector<double>&,std::vector<SVector3>&,std::vector<double>&,int);
  double total_energy(std::vector<double>);	
  SVector3 numerical(DocRecord&,GFace*,int,int);
  void write(DocRecord&,GFace*,int);
  void write2(DocRecord&,GFace*);
  SVector3 analytical(SPoint2,SVector3,double);
  SVector3 area_centroid(SPoint2,SPoint2,SPoint2);
	
  double F(SPoint2,SPoint2,SPoint2,int);
  SVector3 simple(SPoint2,SPoint2,SPoint2,int);
  SVector3 dF_dC1(SPoint2,SPoint2,SPoint2,int);
  SVector3 dF_dC2(SPoint2,SPoint2,SPoint2,int);
  double f(SPoint2,SPoint2,int);
  double df_dx(SPoint2,SPoint2,int);
  double df_dy(SPoint2,SPoint2,int);
  double L1(double,double);
  double dL1_du();
  double dL1_dv();
  double L2(double,double);
  double dL2_du();
  double dL2_dv();
  double L3(double,double);
  double dL3_du();
  double dL3_dv();
  double Tx(double,double,SPoint2,SPoint2,SPoint2);
  double dTx_dp1x(double,double);
  double dTx_dp2x(double,double);
  double dTx_dp3x(double,double);
  double dTx_du(SPoint2,SPoint2,SPoint2);
  double dTx_dv(SPoint2,SPoint2,SPoint2);
  double Ty(double,double,SPoint2,SPoint2,SPoint2);
  double dTy_dp1y(double,double);
  double dTy_dp2y(double,double);
  double dTy_dp3y(double,double);
  double dTy_du(SPoint2,SPoint2,SPoint2);
  double dTy_dv(SPoint2,SPoint2,SPoint2);
  double J(SPoint2,SPoint2,SPoint2);
  double dJ_dp1x(SPoint2,SPoint2,SPoint2);
  double dJ_dp2x(SPoint2,SPoint2,SPoint2);
  double dJ_dp3x(SPoint2,SPoint2,SPoint2);
  double dJ_dp1y(SPoint2,SPoint2,SPoint2);
  double dJ_dp2y(SPoint2,SPoint2,SPoint2);
  double dJ_dp3y(SPoint2,SPoint2,SPoint2);
  SVector3 inner_dFdx0(SVector3,SPoint2,SPoint2,SPoint2,SPoint2);
  SVector3 boundary_dFdx0(SVector3,SPoint2,SPoint2,SPoint2,SVector3);
  double exp(double,int);
  
  SVector3 normal(SPoint2,SPoint2);
  SPoint2 mid(SPoint2,SPoint2);
  void print_segment(SPoint2,SPoint2,std::ofstream&);
  bool adjacent(const DocRecord&,int,int);
  double triangle_area(SPoint2,SPoint2,SPoint2);
  SPoint2 boundary_intersection(SPoint2,SPoint2,bool&,SVector3&);
  bool inside_domain(double,double);
  int get_number_boundary_edges();
  boundary_edge get_boundary_edge(int);
  SPoint2 intersection(SPoint2,SPoint2,SPoint2,SPoint2,bool&);
};

class boundary_edge{
 private :
  SPoint2 p1;
  SPoint2 p2;
 public :
  boundary_edge(SPoint2,SPoint2);
  boundary_edge();
  ~boundary_edge();
  SPoint2 get_p1();
  SPoint2 get_p2();
};

#endif
