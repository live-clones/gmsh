// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Tristan Carrier

#include "GmshConfig.h"

#if defined(HAVE_BFGS)

#include "Levy3D.h"
#include "polynomialBasis.h"
#include "GModel.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "meshGRegion.h"
#include "Voronoi3D.h"
#include "time.h"
#include <algorithm>

/*********definitions*********/

class Wrap{
 private:
  int p;
  int dimension;
  int iteration;
  int max_iteration;
  int offset;
  double initial_energy;
  MElementOctree* octree;
  std::vector<SPoint3> bank;
  std::vector<int> movability;
 public:
  Wrap();
  ~Wrap();
  int get_p();
  int get_dimension();
  int get_iteration();
  int get_max_iteration();
  int get_offset();
  double get_initial_energy();
  MElementOctree* get_octree();
  SPoint3 get_bank(int);
  int get_movability(int);
  int get_size();
  void set_p(int);
  void set_dimension(int);
  void set_iteration(int);
  void set_max_iteration(int);
  void set_offset(int);
  void set_initial_energy(double);
  void set_octree(MElementOctree*);
  void set_bank(SPoint3,int);
  void set_movability(int,int);
  void resize(int);
};

class LpCVT{
 private:
  std::vector<VoronoiElement> clipped;
  fullMatrix<double> gauss_points;
  fullMatrix<double> gauss_weights;
  int gauss_num;
 public:
  LpCVT();
  ~LpCVT();
  void verification(std::vector<SPoint3>&,std::vector<int>&,int,int);
  void eval(std::vector<SPoint3>&,std::vector<int>&,int,std::vector<SVector3>&,double&,int);
  void compute_parameters();
  double get_size(double,double,double);
  Tensor get_tensor(double,double,double);
  double get_drho_dx(double,double,double,int);
  double get_drho_dy(double,double,double,int);
  double get_drho_dz(double,double,double,int);
  double h_to_rho(double,int);
  void swap();
  void get_gauss();
  double F(VoronoiElement,int);
  SVector3 simple(VoronoiElement,int);
  SVector3 dF_dC1(VoronoiElement,int);
  SVector3 dF_dC2(VoronoiElement,int);
  SVector3 dF_dC3(VoronoiElement,int);
  double f(SPoint3,SPoint3,Tensor,int);
  double df_dx(SPoint3,SPoint3,Tensor,int);
  double df_dy(SPoint3,SPoint3,Tensor,int);
  double df_dz(SPoint3,SPoint3,Tensor,int);
  SVector3 bisectors3(SVector3,SPoint3,SPoint3,SPoint3,SPoint3,SPoint3);
  SVector3 bisectors2(SVector3,SPoint3,SPoint3,SPoint3,SPoint3,SVector3);
  SVector3 bisectors1(SVector3,SPoint3,SPoint3,SPoint3,SVector3,SVector3);
  void clear();
};

/*********functions*********/

bool inside_domain(MElementOctree* octree,double x,double y,double z){
  MElement* element;
  element = (MElement*)octree->find(x,y,z,3,true);
  if(element!=NULL) return 1;
  else return 0;
}

void call_back(const alglib::real_1d_array& x,double& func,alglib::real_1d_array& grad,void* ptr){
  int i;
  int p;
  int dimension;
  int iteration;
  int max_iteration;
  int offset;
  int size;
  int error1;
  int error2;
  bool flag;
  double initial_energy;
  double energy;
  LpCVT obj;
  Wrap* w;
  MElementOctree* octree;
  std::vector<SPoint3> bank;
  std::vector<int> movability;
  std::vector<SVector3> gradients;
  
  w = static_cast<Wrap*>(ptr);
  p = w->get_p();
  dimension = w->get_dimension();
  iteration = w->get_iteration();
  max_iteration = w->get_max_iteration();
  offset = w->get_offset();
  size = w->get_size();
  initial_energy = w->get_initial_energy();
  octree = w->get_octree();
  error1 = 0;
  error2 = 0;
  
  bank.resize(size);
  movability.resize(size);
  for(i=0;i<size;i++){
    bank[i] = w->get_bank(i);
    movability[i] = w->get_movability(i);
  }
	
  for(i=0;i<dimension/3;i++){
    bank[i+offset] = SPoint3(x[i],x[i+(dimension/3)],x[i+(2*dimension/3)]);
	flag = inside_domain(octree,x[i],x[i+(dimension/3)],x[i+(2*dimension/3)]);
	if(!flag){
	  error1 = 1;
	  printf("Vertices outside domain.\n");
	}
  }
	
  if(iteration>max_iteration){
    error2 = 1;
	printf("Maximum number of iterations reached.\n");
  }
	
  if(!error1 && !error2){
    gradients.resize(dimension/3);
    obj.get_gauss();
    obj.eval(bank,movability,offset,gradients,energy,p);
    func = energy;
    for(i=0;i<dimension/3;i++){
      grad[i] = gradients[i].x();
	  grad[i+(dimension/3)] = gradients[i].y();
	  grad[i+(2*dimension/3)] = gradients[i].z();
    }
  }
  else{
    func = 1000000000.0;
	for(i=0;i<dimension;i++){
	  grad[i] = 0.0;
	}
  }
	
  if(initial_energy>0.0 && !error1 && !error2){
    printf("%d %.9f\n",iteration,100.0*(initial_energy-energy)/initial_energy);
	w->set_iteration(iteration+1);
  }
  else if(!error1 && !error2){
    w->set_initial_energy(energy);
  }
}

/*********class VoronoiVertex*********/

VoronoiVertex::VoronoiVertex(){
  index1 = -1;
  index2 = -1;
  index3 = -1;
  index4 = -1;
  normal1 = SVector3(0.0,0.0,0.0);
  normal2 = SVector3(0.0,0.0,0.0);	
}

VoronoiVertex::~VoronoiVertex(){}

SPoint3 VoronoiVertex::get_point(){
  return point;
}

int VoronoiVertex::get_category(){
  return category;
}

int VoronoiVertex::get_index1(){
  return index1;
}

int VoronoiVertex::get_index2(){
  return index2;
}

int VoronoiVertex::get_index3(){
  return index3;
}

int VoronoiVertex::get_index4(){
  return index4;
}

SVector3 VoronoiVertex::get_normal1(){
  return normal1;
}

SVector3 VoronoiVertex::get_normal2(){
  return normal2;
}

double VoronoiVertex::get_h(){
  return h;
}

void VoronoiVertex::set_point(SPoint3 new_point){
  point = new_point;
}

void VoronoiVertex::set_category(int new_category){
  category = new_category;
}

void VoronoiVertex::set_index1(int new_index1){
  index1 = new_index1;
}

void VoronoiVertex::set_index2(int new_index2){
  index2 = new_index2;
}

void VoronoiVertex::set_index3(int new_index3){
  index3 = new_index3;
}

void VoronoiVertex::set_index4(int new_index4){
  index4 = new_index4;
}

void VoronoiVertex::set_normal1(SVector3 new_normal1){
  normal1 = new_normal1;
}

void VoronoiVertex::set_normal2(SVector3 new_normal2){
  normal2 = new_normal2;
}

void VoronoiVertex::set_h(double new_h){
  h = new_h;
}

/*********class Tensor*********/

Tensor::Tensor(){
  t11 = 1.0;
  t12 = 0.0;
  t13 = 0.0;
  t21 = 0.0;
  t22 = 1.0;
  t23 = 0.0;
  t31 = 0.0;
  t32 = 0.0;
  t33 = 1.0;	
}

Tensor::~Tensor(){}

void Tensor::set_t11(double new_t11){
  t11 = new_t11;
}

void Tensor::set_t12(double new_t12){
  t12 = new_t12;
}

void Tensor::set_t13(double new_t13){
  t13 = new_t13;
}

void Tensor::set_t21(double new_t21){
  t21 = new_t21;
}

void Tensor::set_t22(double new_t22){
  t22 = new_t22;
}

void Tensor::set_t23(double new_t23){
  t23 = new_t23;
}

void Tensor::set_t31(double new_t31){
  t31 = new_t31;
}

void Tensor::set_t32(double new_t32){
  t32 = new_t32;
}

void Tensor::set_t33(double new_t33){
  t33 = new_t33;
}

double Tensor::get_t11(){
  return t11;
}

double Tensor::get_t12(){
  return t12;
}

double Tensor::get_t13(){
  return t13;
}

double Tensor::get_t21(){
  return t21;
}

double Tensor::get_t22(){
  return t22;
}

double Tensor::get_t23(){
  return t23;
}

double Tensor::get_t31(){
  return t31;
}

double Tensor::get_t32(){
  return t32;
}

double Tensor::get_t33(){
  return t33;
}

/*********class VoronoiElement*********/

VoronoiElement::VoronoiElement(){}

VoronoiElement::~VoronoiElement(){}

VoronoiVertex VoronoiElement::get_v1(){
  return v1;
}

VoronoiVertex VoronoiElement::get_v2(){
  return v2;
}

VoronoiVertex VoronoiElement::get_v3(){
  return v3;
}

VoronoiVertex VoronoiElement::get_v4(){
  return v4;
}

double VoronoiElement::get_jacobian(){
  return jacobian;
}

double VoronoiElement::get_dh_dx(){
  return dh_dx;
}

double VoronoiElement::get_dh_dy(){
  return dh_dy;
}

double VoronoiElement::get_dh_dz(){
  return dh_dz;
}

Tensor VoronoiElement::get_tensor(){
  return t;
}

void VoronoiElement::set_v1(VoronoiVertex new_v1){
  v1 = new_v1;
}

void VoronoiElement::set_v2(VoronoiVertex new_v2){
  v2 = new_v2;
}

void VoronoiElement::set_v3(VoronoiVertex new_v3){
  v3 = new_v3;
}

void VoronoiElement::set_v4(VoronoiVertex new_v4){
  v4 = new_v4;
}

void VoronoiElement::set_tensor(Tensor new_t){
  t = new_t;
}

double VoronoiElement::get_h(double u,double v,double w){
  double h1;
  double h2;
  double h3;
  double h4;
  double h;
	
  h1 = v1.get_h();
  h2 = v2.get_h();
  h3 = v3.get_h();
  h4 = v4.get_h();
  h = T(u,v,w,h1,h2,h3,h4);
  return h;
}

void VoronoiElement::deriv_h(){
  double h1;
  double h2;
  double h3;
  double h4;
  double x1,y1,z1;
  double x2,y2,z2;
  double x3,y3,z3;
  double x4,y4,z4;
  double t11,t12,t13;
  double t21,t22,t23;
  double t31,t32,t33;
  double b11,b12,b13;
  double b21,b22,b23;
  double b31,b32,b33;
  double jacobian2;
  double dh_du;
  double dh_dv;
  double dh_dw;
  double du_dx;
  double dv_dx;
  double dw_dx;
  double du_dy;
  double dv_dy;
  double dw_dy;
  double du_dz;
  double dv_dz;
  double dw_dz;
  SPoint3 p1;
  SPoint3 p2;
  SPoint3 p3;
  SPoint3 p4;
	 
  p1 = v1.get_point();
  p2 = v2.get_point();
  p3 = v3.get_point();
  p4 = v4.get_point();
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  x3 = p3.x();
  y3 = p3.y();
  z3 = p3.z();
  x4 = p4.x();
  y4 = p4.y();
  z4 = p4.z();
  t11 = x2-x1;
  t12 = x3-x1;
  t13 = x4-x1;
  t21 = y2-y1;
  t22 = y3-y1;
  t23 = y4-y1;
  t31 = z2-z1;
  t32 = z3-z1;
  t33 = z4-z1;
  jacobian2 = t11*(t22*t33-t23*t32) - t12*(t21*t33-t31*t23) + t13*(t21*t32-t31*t22);
  b11 = t22*t33-t32*t23;
  b12 = t31*t23-t21*t33;
  b13 = t21*t32-t31*t22;
  b21 = t13*t32-t12*t33;
  b22 = t11*t33-t13*t31;
  b23 = t12*t31-t32*t11;
  b31 = t12*t23-t13*t22;
  b32 = t21*t13-t23*t11;
  b33 = t11*t22-t12*t21;
  du_dx = b11/jacobian2;
  dv_dx = b12/jacobian2;
  dw_dx = b13/jacobian2;
  du_dy = b21/jacobian2;
  dv_dy = b22/jacobian2;
  dw_dy = b23/jacobian2;
  du_dz = b31/jacobian2;
  dv_dz = b32/jacobian2;
  dw_dz = b33/jacobian2;
	
  h1 = v1.get_h();
  h2 = v2.get_h();
  h3 = v3.get_h();
  h4 = v4.get_h();
  dh_du = h2-h1;
  dh_dv = h3-h1;
  dh_dw = h4-h1;
  
  dh_dx = dh_du*du_dx + dh_dv*dv_dx + dh_dw*dw_dx;
  dh_dy = dh_du*du_dy + dh_dv*dv_dy + dh_dw*dw_dy;
  dh_dz = dh_du*du_dz + dh_dv*dv_dz + dh_dw*dw_dz;
}

void VoronoiElement::compute_jacobian(){
  double jacobian2;
  double x1,x2,x3,x4;
  double y1,y2,y3,y4;
  double z1,z2,z3,z4;
  SPoint3 p1;
  SPoint3 p2;
  SPoint3 p3;
  SPoint3 p4;
	
  p1 = v1.get_point();
  p2 = v2.get_point();
  p3 = v3.get_point();
  p4 = v4.get_point();
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  x3 = p3.x();
  y3 = p3.y();
  z3 = p3.z();
  x4 = p4.x();
  y4 = p4.y();
  z4 = p4.z();
  jacobian2 = (x2-x1)*((y3-y1)*(z4-z1)-(y4-y1)*(z3-z1));
  jacobian2 = jacobian2 - (x3-x1)*((y2-y1)*(z4-z1)-(y4-y1)*(z2-z1));
  jacobian2 = jacobian2 + (x4-x1)*((y2-y1)*(z3-z1)-(y3-y1)*(z2-z1));
  jacobian = jacobian2;
}

double VoronoiElement::T(double u,double v,double w,double val1,double val2,double val3,double val4){
  double val;
  val = (1.0-u-v-w)*val1 + u*val2 + v*val3 + w*val4;
  return val;
}

void VoronoiElement::swap(){
  VoronoiVertex v;
  compute_jacobian();
  if(jacobian<0.0){
	v = v2;
	v2 = v3;
	v3 = v;
  }
}

double VoronoiElement::get_quality(){
  int i;
  double quality;
  double min_l,max_l;
  double l[6];
	
  l[0] = v1.get_point().distance(v2.get_point());
  l[1] = v1.get_point().distance(v3.get_point());
  l[2] = v1.get_point().distance(v4.get_point());
  l[3] = v2.get_point().distance(v3.get_point());
  l[4] = v2.get_point().distance(v4.get_point());
  l[5] = v3.get_point().distance(v4.get_point());
	
  min_l = 1000000.0;
  max_l = -1000000.0;
	
  for(i=0;i<6;i++){
    min_l = std::min(min_l,l[i]);
	max_l = std::max(max_l,l[i]);
  }
	
  quality = min_l/max_l;
  return quality;
}

/*********class Wrap*********/

Wrap::Wrap(){
  iteration = 0;
  initial_energy = -1000000.0;
}

Wrap::~Wrap(){}

int Wrap::get_p(){
  return p;
}

int Wrap::get_dimension(){
  return dimension;
}

int Wrap::get_iteration(){
  return iteration;
}

int Wrap::get_max_iteration(){
  return max_iteration;
}

int Wrap::get_offset(){
  return offset;
}

double Wrap::get_initial_energy(){
  return initial_energy;
}

MElementOctree* Wrap::get_octree(){
  return octree;
}

SPoint3 Wrap::get_bank(int index){
  return bank[index];
}

int Wrap::get_movability(int index){
  return movability[index];
}

int Wrap::get_size(){
  return bank.size();
}

void Wrap::set_p(int new_p){
  p = new_p;
}

void Wrap::set_dimension(int new_dimension){
  dimension = new_dimension;
}

void Wrap::set_iteration(int new_iteration){
  iteration = new_iteration;
}

void Wrap::set_max_iteration(int new_max_iteration){
  max_iteration = new_max_iteration;
}

void Wrap::set_offset(int new_offset){
  offset = new_offset;
}

void Wrap::set_initial_energy(double new_initial_energy){
  initial_energy = new_initial_energy;
}

void Wrap::set_octree(MElementOctree* new_octree){
  octree = new_octree;
}

void Wrap::set_bank(SPoint3 point,int index){
  bank[index] = point;
}

void Wrap::set_movability(int flag,int index){
  movability[index] = flag;
}

void Wrap::resize(int size){
  bank.resize(size);
  movability.resize(size);
}

/*********class LpCVT*********/

LpCVT::LpCVT(){}

LpCVT::~LpCVT(){}

void LpCVT::verification(std::vector<SPoint3>& bank,std::vector<int>& movability,int offset,int p){
  int index;
  double energy;
  double up,down;
  double left,right;
  double front,back;
  double e;
  std::vector<SVector3> gradients;
 
  gradients.resize(bank.size()-offset);
  e = 0.0001;
  srand(time(NULL));
  index = rand()%(bank.size()-offset) + offset;
	
  bank[index] = SPoint3(bank[index].x()+e,bank[index].y(),bank[index].z());
  eval(bank,movability,offset,gradients,right,p);
  bank[index] = SPoint3(bank[index].x()-e,bank[index].y(),bank[index].z());
	
  bank[index] = SPoint3(bank[index].x()-e,bank[index].y(),bank[index].z());
  eval(bank,movability,offset,gradients,left,p);
  bank[index] = SPoint3(bank[index].x()+e,bank[index].y(),bank[index].z());
	
  bank[index] = SPoint3(bank[index].x(),bank[index].y()+e,bank[index].z());
  eval(bank,movability,offset,gradients,up,p);
  bank[index] = SPoint3(bank[index].x(),bank[index].y()-e,bank[index].z());
	
  bank[index] = SPoint3(bank[index].x(),bank[index].y()-e,bank[index].z());
  eval(bank,movability,offset,gradients,down,p);
  bank[index] = SPoint3(bank[index].x(),bank[index].y()+e,bank[index].z());
	
  bank[index] = SPoint3(bank[index].x(),bank[index].y(),bank[index].z()+e);
  eval(bank,movability,offset,gradients,front,p);
  bank[index] = SPoint3(bank[index].x(),bank[index].y(),bank[index].z()-e);
	
  bank[index] = SPoint3(bank[index].x(),bank[index].y(),bank[index].z()-e);
  eval(bank,movability,offset,gradients,back,p);
  bank[index] = SPoint3(bank[index].x(),bank[index].y(),bank[index].z()+e);
	
  eval(bank,movability,offset,gradients,energy,p);

  printf("...%f  %f  %f\n",gradients[index-offset].x(),gradients[index-offset].y(),gradients[index-offset].z());
  printf("...%f  %f  %f\n",(right-left)/(2.0*e),(up-down)/(2.0*e),(front-back)/(2.0*e));
}

void LpCVT::eval(std::vector<SPoint3>& bank,std::vector<int>& movability,int offset,std::vector<SVector3>& gradients,double& energy,int p){
  int i;
  int index;
  int index1,index2,index3;
  int index4,index5,index6;
  int index7,index8,index9;
  double e;
  SVector3 grad1,grad2,grad3;
  clip approx;
	
  for(i=0;i<gradients.size();i++){
    gradients[i] = SVector3(0.0,0.0,0.0);
  }
  energy = 0.0;
  e = 0.000001;
	
  clipped.clear();
  approx.execute(bank,clipped);
  swap();
  compute_parameters();
	
  for(i=0;i<clipped.size();i++){
	if(clipped[i].get_quality()<e) continue;
    energy = energy + F(clipped[i],p);
	grad1 = dF_dC1(clipped[i],p);
	grad2 = dF_dC2(clipped[i],p);
	grad3 = dF_dC3(clipped[i],p);
	index = clipped[i].get_v1().get_index1();
	index1 = clipped[i].get_v2().get_index2();
	index2 = clipped[i].get_v2().get_index3();
	index3 = clipped[i].get_v2().get_index4();
	index4 = clipped[i].get_v3().get_index2();
	index5 = clipped[i].get_v3().get_index3();
	index6 = clipped[i].get_v3().get_index4();
	index7 = clipped[i].get_v4().get_index2();
	index8 = clipped[i].get_v4().get_index3();
	index9 = clipped[i].get_v4().get_index4();
	if(movability[index]==1){
	  gradients[index-offset] = gradients[index-offset] + simple(clipped[i],p);
	  if(index1>0 && index2>0 && index3>0)
	    gradients[index-offset] = gradients[index-offset] + bisectors3(grad1,clipped[i].get_v2().get_point(),bank[index],bank[index1],bank[index2],bank[index3]);
	  if(index4>0 && index5>0 && index6>0)
        gradients[index-offset] = gradients[index-offset] + bisectors3(grad2,clipped[i].get_v3().get_point(),bank[index],bank[index4],bank[index5],bank[index6]);
	  if(index7>0 && index8>0 && index9>0)
	    gradients[index-offset] = gradients[index-offset] + bisectors3(grad3,clipped[i].get_v4().get_point(),bank[index],bank[index7],bank[index8],bank[index9]);
	}
	if(index1>0 && index2>0 && index3>0){
	  if(movability[index1]==1){
	    gradients[index1-offset] = gradients[index1-offset] + bisectors3(grad1,clipped[i].get_v2().get_point(),bank[index1],bank[index],bank[index2],bank[index3]);
	  }
	  if(movability[index2]==1){
	    gradients[index2-offset] = gradients[index2-offset] + bisectors3(grad1,clipped[i].get_v2().get_point(),bank[index2],bank[index],bank[index1],bank[index3]);
	  }
	  if(movability[index3]==1){
	    gradients[index3-offset] = gradients[index3-offset] + bisectors3(grad1,clipped[i].get_v2().get_point(),bank[index3],bank[index],bank[index1],bank[index2]);
	  }
	}
	if(index4>0 && index5>0 && index6>0){
	  if(movability[index4]==1){
	    gradients[index4-offset] = gradients[index4-offset] + bisectors3(grad2,clipped[i].get_v3().get_point(),bank[index4],bank[index],bank[index5],bank[index6]);
	  }
	  if(movability[index5]==1){
	    gradients[index5-offset] = gradients[index5-offset] + bisectors3(grad2,clipped[i].get_v3().get_point(),bank[index5],bank[index],bank[index4],bank[index6]);
	  }
	  if(movability[index6]==1){
	    gradients[index6-offset] = gradients[index6-offset] + bisectors3(grad2,clipped[i].get_v3().get_point(),bank[index6],bank[index],bank[index4],bank[index5]);
	  }
	}
	if(index7>0 && index8>0 && index9>0){
	  if(movability[index7]==1){
	    gradients[index7-offset] = gradients[index7-offset] + bisectors3(grad3,clipped[i].get_v4().get_point(),bank[index7],bank[index],bank[index8],bank[index9]);
	  }
	  if(movability[index8]==1){
	    gradients[index8-offset] = gradients[index8-offset] + bisectors3(grad3,clipped[i].get_v4().get_point(),bank[index8],bank[index],bank[index7],bank[index9]);
	  }
	  if(movability[index9]==1){
	    gradients[index9-offset] = gradients[index9-offset] + bisectors3(grad3,clipped[i].get_v4().get_point(),bank[index9],bank[index],bank[index7],bank[index8]);
	  }
	}
  }
}

void LpCVT::compute_parameters(){
  int i;
  double h1,h2,h3,h4;
  Tensor t;
  VoronoiVertex v1,v2,v3,v4;
	
  for(i=0;i<clipped.size();i++){
    v1 = clipped[i].get_v1();
	v2 = clipped[i].get_v2();
	v3 = clipped[i].get_v3();
	v4 = clipped[i].get_v4(); 
	h1 = get_size(clipped[i].get_v1().get_point().x(),clipped[i].get_v1().get_point().y(),clipped[i].get_v1().get_point().z());
	h2 = get_size(clipped[i].get_v2().get_point().x(),clipped[i].get_v2().get_point().y(),clipped[i].get_v2().get_point().z());
	h3 = get_size(clipped[i].get_v3().get_point().x(),clipped[i].get_v3().get_point().y(),clipped[i].get_v3().get_point().z());
	h4 = get_size(clipped[i].get_v4().get_point().x(),clipped[i].get_v4().get_point().y(),clipped[i].get_v4().get_point().z());
	v1.set_h(h1);
	v2.set_h(h2);
	v3.set_h(h3);
	v4.set_h(h4);
	clipped[i].set_v1(v1);
	clipped[i].set_v2(v2);
	clipped[i].set_v3(v3);
	clipped[i].set_v4(v4);
	t = get_tensor(clipped[i].get_v1().get_point().x(),clipped[i].get_v1().get_point().y(),clipped[i].get_v1().get_point().z());
	clipped[i].set_tensor(t);
	clipped[i].compute_jacobian();
	clipped[i].deriv_h();
  }
}

double LpCVT::get_size(double x,double y,double z){
  return 0.25;
}

Tensor LpCVT::get_tensor(double x,double y,double z){
  double angle;
  Tensor t;

  angle = atan2(z,x);
  t = Tensor();
	
  t.set_t11(1.0);
  t.set_t12(0.0);
  t.set_t13(0.0);
  
  t.set_t21(0.0);
  t.set_t22(1.0);
  t.set_t23(0.0);
  
  t.set_t31(0.0);
  t.set_t32(0.0);
  t.set_t33(1.0);
	
  return t;
}

double LpCVT::get_drho_dx(double x,double y,double z,int p){
  double e;
  double less2;
  double less1;
  double plus1;
  double plus2;
  double val;

  e = 0.000001;
  less2 = h_to_rho(get_size(x-2.0*e,y,z),p);
  less1 = h_to_rho(get_size(x-e,y,z),p);
  plus1 = h_to_rho(get_size(x+e,y,z),p);
  plus2 = h_to_rho(get_size(x+2.0*e,y,z),p);
	
  val = (less2 - 8.0*less1 + 8.0*plus1 - plus2)/(12.0*e);
  return val;
}

double LpCVT::get_drho_dy(double x,double y,double z,int p){
  double e;
  double less2;
  double less1;
  double plus1;
  double plus2;
  double val;
	
  e = 0.000001;
  less2 = h_to_rho(get_size(x,y-2.0*e,z),p);
  less1 = h_to_rho(get_size(x,y-e,z),p);
  plus1 = h_to_rho(get_size(x,y+e,z),p);
  plus2 = h_to_rho(get_size(x,y+2.0*e,z),p);
	
  val = (less2 - 8.0*less1 + 8.0*plus1 - plus2)/(12.0*e);
  return val;
}

double LpCVT::get_drho_dz(double x,double y,double z,int p){
  double e;
  double less2;
  double less1;
  double plus1;
  double plus2;
  double val;
	
  e = 0.000001;
  less2 = h_to_rho(get_size(x,y,z-2.0*e),p);
  less1 = h_to_rho(get_size(x,y,z-e),p);
  plus1 = h_to_rho(get_size(x,y,z+e),p);
  plus2 = h_to_rho(get_size(x,y,z+2.0*e),p);
	
  val = (less2 - 8.0*less1 + 8.0*plus1 - plus2)/(12.0*e);
  return val;	
}

double LpCVT::h_to_rho(double h,int p){
  double rho;
  rho = pow_int(1.0/h,p+3);
  return rho;
}

void LpCVT::swap(){
  int i;	
  for(i=0;i<clipped.size();i++){
    clipped[i].swap();		
  }
}

void LpCVT::get_gauss(){
  int order;
  order = 8;
  gaussIntegration::getTetrahedron(order,gauss_points,gauss_weights);
  gauss_num = gauss_points.size1();
}

double LpCVT::F(VoronoiElement element,int p){
  int i;
  double u,v,w;
  double x,y,z;
  double energy;
  double weight;
  double rho;
  SPoint3 point,generator,C1,C2,C3;
  VoronoiVertex v1,v2,v3,v4;
  Tensor t;
	
  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  v4 = element.get_v4();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  C3 = v4.get_point();
  energy = 0.0;
  t = element.get_tensor();
	
  for(i=0;i<gauss_num;i++){
    u = gauss_points(i,0);
	v = gauss_points(i,1);
	w = gauss_points(i,2);
	x = element.T(u,v,w,generator.x(),C1.x(),C2.x(),C3.x());
	y = element.T(u,v,w,generator.y(),C1.y(),C2.y(),C3.y());
	z = element.T(u,v,w,generator.z(),C1.z(),C2.z(),C3.z());
	point = SPoint3(x,y,z);
	weight = gauss_weights(i,0);
	rho = h_to_rho(element.get_h(u,v,w),p); //h_to_rho(get_size(x,y,z),p);
	energy = energy + weight*rho*f(generator,point,t,p);
  }
  energy = element.get_jacobian()*energy;
  return energy;
}

SVector3 LpCVT::simple(VoronoiElement element,int p){
  int i;
  double u,v,w;
  double x,y,z;
  double comp_x,comp_y,comp_z;
  double weight;
  double rho;
  double jacobian;
  SPoint3 point,generator,C1,C2,C3;
  VoronoiVertex v1,v2,v3,v4;
  Tensor t;
	
  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  v4 = element.get_v4();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  C3 = v4.get_point();
  comp_x = 0.0;
  comp_y = 0.0;
  comp_z = 0.0;
  jacobian = element.get_jacobian();
  t = element.get_tensor();
	
  for(i=0;i<gauss_num;i++){
    u = gauss_points(i,0);
	v = gauss_points(i,1);
	w = gauss_points(i,2);
	x = element.T(u,v,w,generator.x(),C1.x(),C2.x(),C3.x());
	y = element.T(u,v,w,generator.y(),C1.y(),C2.y(),C3.y());
	z = element.T(u,v,w,generator.z(),C1.z(),C2.z(),C3.z());
	point = SPoint3(x,y,z);
	weight = gauss_weights(i,0);
	rho = h_to_rho(element.get_h(u,v,w),p); //h_to_rho(get_size(x,y,z),p);
	comp_x = comp_x + weight*rho*df_dx(generator,point,t,p);
	comp_y = comp_y + weight*rho*df_dy(generator,point,t,p);
	comp_z = comp_z + weight*rho*df_dz(generator,point,t,p);
  }
  comp_x = jacobian*comp_x;
  comp_y = jacobian*comp_y;
  comp_z = jacobian*comp_z;
  return SVector3(comp_x,comp_y,comp_z);
}

SVector3 LpCVT::dF_dC1(VoronoiElement element,int p){
  int i;
  double u,v,w;
  double x,y,z;
  double comp_x,comp_y,comp_z;
  double weight;
  double rho;
  double drho_dx,drho_dy,drho_dz;
  double jacobian;
  double distance;
  double gx,gy,gz;
  SPoint3 point,generator,C1,C2,C3;
  VoronoiVertex v1,v2,v3,v4;
  Tensor t;
	
  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  v4 = element.get_v4();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  C3 = v4.get_point();
  comp_x = 0.0;
  comp_y = 0.0;
  comp_z = 0.0;
  jacobian = element.get_jacobian();
  t = element.get_tensor();
  gx = generator.x();
  gy = generator.y();
  gz = generator.z();
	
  for(i=0;i<gauss_num;i++){
    u = gauss_points(i,0);
	v = gauss_points(i,1);
	w = gauss_points(i,2);
	x = element.T(u,v,w,gx,C1.x(),C2.x(),C3.x());
	y = element.T(u,v,w,gy,C1.y(),C2.y(),C3.y());
	z = element.T(u,v,w,gz,C1.z(),C2.z(),C3.z());
	point = SPoint3(x,y,z);
	weight = gauss_weights(i,0);
	rho = h_to_rho(element.get_h(u,v,w),p); //h_to_rho(get_size(x,y,z),p);
	drho_dx = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dx(); //get_drho_dx(x,y,z,p);
	drho_dy = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dy(); //get_drho_dy(x,y,z,p);
	drho_dz = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dz(); //get_drho_dz(x,y,z,p);
	distance = f(point,generator,t,p);
	comp_x = comp_x + weight*rho*df_dx(point,generator,t,p)*u*jacobian;
	comp_x = comp_x + weight*rho*distance*((C2.y()-gy)*(C3.z()-gz) - (C3.y()-gy)*(C2.z()-gz));
	comp_x = comp_x + weight*drho_dx*u*distance*jacobian;
	comp_y = comp_y + weight*rho*df_dy(point,generator,t,p)*u*jacobian;
	comp_y = comp_y + weight*rho*distance*((C2.z()-gz)*(C3.x()-gx) - (C2.x()-gx)*(C3.z()-gz));
	comp_y = comp_y + weight*drho_dy*u*distance*jacobian;
	comp_z = comp_z + weight*rho*df_dz(point,generator,t,p)*u*jacobian;
	comp_z = comp_z + weight*rho*distance*((C2.x()-gx)*(C3.y()-gy) - (C3.x()-gx)*(C2.y()-gy));
	comp_z = comp_z + weight*drho_dz*u*distance*jacobian;
  }		
  return SVector3(comp_x,comp_y,comp_z);
}

SVector3 LpCVT::dF_dC2(VoronoiElement element,int p){
  int i;
  double u,v,w;
  double x,y,z;
  double comp_x,comp_y,comp_z;
  double weight;
  double rho;
  double drho_dx,drho_dy,drho_dz;
  double jacobian;
  double distance;
  double gx,gy,gz;
  SPoint3 point,generator,C1,C2,C3;
  VoronoiVertex v1,v2,v3,v4;
  Tensor t;
	
  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  v4 = element.get_v4();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  C3 = v4.get_point();
  comp_x = 0.0;
  comp_y = 0.0;
  comp_z = 0.0;
  jacobian = element.get_jacobian();
  t = element.get_tensor();
  gx = generator.x();
  gy = generator.y();
  gz = generator.z();
	
  for(i=0;i<gauss_num;i++){
    u = gauss_points(i,0);
	v = gauss_points(i,1);
	w = gauss_points(i,2);
	x = element.T(u,v,w,generator.x(),C1.x(),C2.x(),C3.x());
	y = element.T(u,v,w,generator.y(),C1.y(),C2.y(),C3.y());
	z = element.T(u,v,w,generator.z(),C1.z(),C2.z(),C3.z());
	point = SPoint3(x,y,z);
	weight = gauss_weights(i,0);
	rho = h_to_rho(element.get_h(u,v,w),p); //h_to_rho(get_size(x,y,z),p);
	drho_dx = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dx(); //get_drho_dx(x,y,z,p);
	drho_dy = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dy(); //get_drho_dy(x,y,z,p);
	drho_dz = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dz(); //get_drho_dz(x,y,z,p);
	distance = f(point,generator,t,p);
	comp_x = comp_x + weight*rho*df_dx(point,generator,t,p)*v*jacobian;
	comp_x = comp_x + weight*rho*distance*((C1.z()-gz)*(C3.y()-gy) - (C1.y()-gy)*(C3.z()-gz));
	comp_x = comp_x + weight*drho_dx*v*distance*jacobian;
	comp_y = comp_y + weight*rho*df_dy(point,generator,t,p)*v*jacobian;
	comp_y = comp_y + weight*rho*distance*((C1.x()-gx)*(C3.z()-gz) - (C3.x()-gx)*(C1.z()-gz));
	comp_y = comp_y + weight*drho_dy*v*distance*jacobian;
	comp_z = comp_z + weight*rho*df_dz(point,generator,t,p)*v*jacobian;
	comp_z = comp_z + weight*rho*distance*((C3.x()-gx)*(C1.y()-gy) - (C1.x()-gx)*(C3.y()-gy));
	comp_z = comp_z + weight*drho_dz*v*distance*jacobian;
  }		
  return SVector3(comp_x,comp_y,comp_z);
}

SVector3 LpCVT::dF_dC3(VoronoiElement element,int p){
  int i;
  double u,v,w;
  double x,y,z;
  double comp_x,comp_y,comp_z;
  double weight;
  double rho;
  double drho_dx,drho_dy,drho_dz;
  double jacobian;
  double distance;
  double gx,gy,gz;
  SPoint3 point,generator,C1,C2,C3;
  VoronoiVertex v1,v2,v3,v4;
  Tensor t;
	
  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  v4 = element.get_v4();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  C3 = v4.get_point();
  comp_x = 0.0;
  comp_y = 0.0;
  comp_z = 0.0;
  jacobian = element.get_jacobian();
  t = element.get_tensor();
  gx = generator.x();
  gy = generator.y();
  gz = generator.z();
	
  for(i=0;i<gauss_num;i++){
    u = gauss_points(i,0);
	v = gauss_points(i,1);
	w = gauss_points(i,2);
	x = element.T(u,v,w,gx,C1.x(),C2.x(),C3.x());
	y = element.T(u,v,w,gy,C1.y(),C2.y(),C3.y());
	z = element.T(u,v,w,gz,C1.z(),C2.z(),C3.z());
	point = SPoint3(x,y,z);
	weight = gauss_weights(i,0);
	rho = h_to_rho(element.get_h(u,v,w),p); //h_to_rho(get_size(x,y,z),p);
	drho_dx = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dx(); //get_drho_dx(x,y,z,p);
	drho_dy = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dy(); //get_drho_dy(x,y,z,p);
	drho_dz = (-p-3)*pow_int(1.0/element.get_h(u,v,w),p+4)*element.get_dh_dz(); //get_drho_dz(x,y,z,p);
	distance = f(point,generator,t,p);
	comp_x = comp_x + weight*rho*df_dx(point,generator,t,p)*w*jacobian;
	comp_x = comp_x + weight*rho*distance*((C1.y()-gy)*(C2.z()-gz) - (C2.y()-gy)*(C1.z()-gz));
	comp_x = comp_x + weight*drho_dx*w*distance*jacobian;
	comp_y = comp_y + weight*rho*df_dy(point,generator,t,p)*w*jacobian;
	comp_y = comp_y + weight*rho*distance*((C2.x()-gx)*(C1.z()-gz) - (C1.x()-gx)*(C2.z()-gz));
	comp_y = comp_y + weight*drho_dy*w*distance*jacobian;
	comp_z = comp_z + weight*rho*df_dz(point,generator,t,p)*w*jacobian;
	comp_z = comp_z + weight*rho*distance*((C1.x()-gx)*(C2.y()-gy) - (C2.x()-gx)*(C1.y()-gy));
	comp_z = comp_z + weight*drho_dz*w*distance*jacobian;
  }		
  return SVector3(comp_x,comp_y,comp_z);
}

double LpCVT::f(SPoint3 p1,SPoint3 p2,Tensor t,int p){
  double x1,y1,z1;
  double x2,y2,z2;
  double t11,t12,t13;
  double t21,t22,t23;
  double t31,t32,t33;
  double val1,val2,val3;
  double val;
	
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  t11 = t.get_t11();
  t12 = t.get_t12();
  t13 = t.get_t13();
  t21 = t.get_t21();
  t22 = t.get_t22();
  t23 = t.get_t23();
  t31 = t.get_t31();
  t32 = t.get_t32();
  t33 = t.get_t33();	
  val1 = t11*x1 + t12*y1 + t13*z1 - t11*x2 - t12*y2 - t13*z2;
  val2 = t21*x1 + t22*y1 + t23*z1 - t21*x2 - t22*y2 - t23*z2;
  val3 = t31*x1 + t32*y1 + t33*z1 - t31*x2 - t32*y2 - t33*z2;
  val = pow_int(val1,p) + pow_int(val2,p) + pow_int(val3,p);
  return val;
}

double LpCVT::df_dx(SPoint3 p1,SPoint3 p2,Tensor t,int p){
  double x1,y1,z1;
  double x2,y2,z2;
  double t11,t12,t13;
  double t21,t22,t23;
  double t31,t32,t33;
  double val1,val2,val3;
  double val;
	
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  t11 = t.get_t11();
  t12 = t.get_t12();
  t13 = t.get_t13();
  t21 = t.get_t21();
  t22 = t.get_t22();
  t23 = t.get_t23();
  t31 = t.get_t31();
  t32 = t.get_t32();
  t33 = t.get_t33();	
  val1 = t11*x1 + t12*y1 + t13*z1 - t11*x2 - t12*y2 - t13*z2;
  val2 = t21*x1 + t22*y1 + t23*z1 - t21*x2 - t22*y2 - t23*z2;
  val3 = t31*x1 + t32*y1 + t33*z1 - t31*x2 - t32*y2 - t33*z2;
  val = ((double)p)*pow_int(val1,p-1)*t11 + ((double)p)*pow_int(val2,p-1)*t21 + ((double)p)*pow_int(val3,p-1)*t31;
  return val;
}

double LpCVT::df_dy(SPoint3 p1,SPoint3 p2,Tensor t,int p){
  double x1,y1,z1;
  double x2,y2,z2;
  double t11,t12,t13;
  double t21,t22,t23;
  double t31,t32,t33;
  double val1,val2,val3;
  double val;
	
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  t11 = t.get_t11();
  t12 = t.get_t12();
  t13 = t.get_t13();
  t21 = t.get_t21();
  t22 = t.get_t22();
  t23 = t.get_t23();
  t31 = t.get_t31();
  t32 = t.get_t32();
  t33 = t.get_t33();	
  val1 = t11*x1 + t12*y1 + t13*z1 - t11*x2 - t12*y2 - t13*z2;
  val2 = t21*x1 + t22*y1 + t23*z1 - t21*x2 - t22*y2 - t23*z2;
  val3 = t31*x1 + t32*y1 + t33*z1 - t31*x2 - t32*y2 - t33*z2;
  val = ((double)p)*pow_int(val1,p-1)*t12 + ((double)p)*pow_int(val2,p-1)*t22 + ((double)p)*pow_int(val3,p-1)*t32;
  return val;
}

double LpCVT::df_dz(SPoint3 p1,SPoint3 p2,Tensor t,int p){
  double x1,y1,z1;
  double x2,y2,z2;
  double t11,t12,t13;
  double t21,t22,t23;
  double t31,t32,t33;
  double val1,val2,val3;
  double val;
	
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  t11 = t.get_t11();
  t12 = t.get_t12();
  t13 = t.get_t13();
  t21 = t.get_t21();
  t22 = t.get_t22();
  t23 = t.get_t23();
  t31 = t.get_t31();
  t32 = t.get_t32();
  t33 = t.get_t33();	
  val1 = t11*x1 + t12*y1 + t13*z1 - t11*x2 - t12*y2 - t13*z2;
  val2 = t21*x1 + t22*y1 + t23*z1 - t21*x2 - t22*y2 - t23*z2;
  val3 = t31*x1 + t32*y1 + t33*z1 - t31*x2 - t32*y2 - t33*z2;
  val = ((double)p)*pow_int(val1,p-1)*t13 + ((double)p)*pow_int(val2,p-1)*t23 + ((double)p)*pow_int(val3,p-1)*t33;
  return val;
}

SVector3 LpCVT::bisectors3(SVector3 dIdC,SPoint3 C,SPoint3 x0,SPoint3 x1,SPoint3 x2,SPoint3 x3){
  fullMatrix<double> A(3,3);
  fullMatrix<double> B(3,3);
  fullMatrix<double> M(3,3);
  fullMatrix<double> _dIdC(1,3);
  fullMatrix<double> _val(1,3);
  A(0,0) = x1.x() - x0.x(); 
  A(0,1) = x1.y() - x0.y();
  A(0,2) = x1.z() - x0.z();
  A(1,0) = x2.x() - x0.x(); 
  A(1,1) = x2.y() - x0.y();
  A(1,2) = x2.z() - x0.z();
  A(2,0) = x3.x() - x0.x(); 
  A(2,1) = x3.y() - x0.y();
  A(2,2) = x3.z() - x0.z();
  A.invertInPlace();
  B(0,0) = C.x() - x0.x();
  B(0,1) = C.y() - x0.y();
  B(0,2) = C.z() - x0.z();
  B(1,0) = C.x() - x0.x();
  B(1,1) = C.y() - x0.y();
  B(1,2) = C.z() - x0.z();
  B(2,0) = C.x() - x0.x();
  B(2,1) = C.y() - x0.y();
  B(2,2) = C.z() - x0.z();
  A.mult_naive(B,M);
  _dIdC(0,0) = dIdC.x();
  _dIdC(0,1) = dIdC.y();
  _dIdC(0,2) = dIdC.z();
  _dIdC.mult_naive(M,_val);
  return SVector3(_val(0,0),_val(0,1),_val(0,2));	
}

SVector3 LpCVT::bisectors2(SVector3 dIdC,SPoint3 C,SPoint3 x0,SPoint3 x1,SPoint3 x2,SVector3 normal1){
  fullMatrix<double> A(3,3);
  fullMatrix<double> B(3,3);
  fullMatrix<double> M(3,3);
  fullMatrix<double> _dIdC(1,3);
  fullMatrix<double> _val(1,3);
  A(0,0) = x1.x() - x0.x(); 
  A(0,1) = x1.y() - x0.y();
  A(0,2) = x1.z() - x0.z();
  A(1,0) = x2.x() - x0.x(); 
  A(1,1) = x2.y() - x0.y();
  A(1,2) = x2.z() - x0.z();
  A(2,0) = normal1.x(); 
  A(2,1) = normal1.y();
  A(2,2) = normal1.z();
  A.invertInPlace();
  B(0,0) = C.x() - x0.x();
  B(0,1) = C.y() - x0.y();
  B(0,2) = C.z() - x0.z();
  B(1,0) = C.x() - x0.x();
  B(1,1) = C.y() - x0.y();
  B(1,2) = C.z() - x0.z();
  B(2,0) = 0.0;
  B(2,1) = 0.0;
  B(2,2) = 0.0;
  A.mult_naive(B,M);
  _dIdC(0,0) = dIdC.x();
  _dIdC(0,1) = dIdC.y();
  _dIdC(0,2) = dIdC.z();
  _dIdC.mult_naive(M,_val);
  return SVector3(_val(0,0),_val(0,1),_val(0,2));	
}

SVector3 LpCVT::bisectors1(SVector3 dIdC,SPoint3 C,SPoint3 x0,SPoint3 x1,SVector3 normal1,SVector3 normal2){
  fullMatrix<double> A(3,3);
  fullMatrix<double> B(3,3);
  fullMatrix<double> M(3,3);
  fullMatrix<double> _dIdC(1,3);
  fullMatrix<double> _val(1,3);
  A(0,0) = x1.x() - x0.x(); 
  A(0,1) = x1.y() - x0.y();
  A(0,2) = x1.z() - x0.z();
  A(1,0) = normal1.x(); 
  A(1,1) = normal1.y();
  A(1,2) = normal1.z();
  A(2,0) = normal2.x(); 
  A(2,1) = normal2.y();
  A(2,2) = normal2.z();
  A.invertInPlace();
  B(0,0) = C.x() - x0.x();
  B(0,1) = C.y() - x0.y();
  B(0,2) = C.z() - x0.z();
  B(1,0) = 0.0;
  B(1,1) = 0.0;
  B(1,2) = 0.0;
  B(2,0) = 0.0;
  B(2,1) = 0.0;
  B(2,2) = 0.0;
  A.mult_naive(B,M);
  _dIdC(0,0) = dIdC.x();
  _dIdC(0,1) = dIdC.y();
  _dIdC(0,2) = dIdC.z();
  _dIdC.mult_naive(M,_val);
  return SVector3(_val(0,0),_val(0,1),_val(0,2));	
}

void LpCVT::clear(){
  clipped.clear();
}

/*********class LpSmoother*********/

LpSmoother::LpSmoother(int new_max_iter,int new_norm){
  max_iter = new_max_iter;
  norm = new_norm;
}

LpSmoother::~LpSmoother(){}

void LpSmoother::improve_model(){
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;
	
  for(it=model->firstRegion();it!=model->lastRegion();it++)
  {
    gr = *it;
	if(gr->getNumMeshElements()>0){
	  improve_region(gr);
	}
  }
}

void LpSmoother::improve_region(GRegion* gr){
  int i;
  int offset;
  double epsg;
  double epsf;
  double epsx;
  double factor;
  SPoint3 point;
  MVertex* vertex;
  MVertex *v1,*v2,*v3,*v4;
  MElement* element;
  MElementOctree* octree;
  deMeshGRegion deleter;
  Wrap w;
  std::set<MVertex*> movable2;
  std::set<MVertex*> unmovable2;
  std::set<MVertex*>::iterator it;
  std::vector<MVertex*> movable;
  std::vector<MVertex*> unmovable;
  std::vector<SPoint3> bank;
  std::vector<int> movability;
  alglib::ae_int_t maxits;
  alglib::minlbfgsstate state;
  alglib::minlbfgsreport rep;
  alglib::real_1d_array x;
  alglib::real_1d_array alglib_scales;

  octree = new MElementOctree(gr->model());	
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	v1 = element->getVertex(0);
	v2 = element->getVertex(1);
	v3 = element->getVertex(2);
	v4 = element->getVertex(3);
	if(v1->onWhat()->dim()<3 || v2->onWhat()->dim()<3 || v3->onWhat()->dim()<3 || v4->onWhat()->dim()<3){
	  unmovable2.insert(v1);
	  unmovable2.insert(v2);
	  unmovable2.insert(v3);
	  unmovable2.insert(v4);
	}
  }	

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	v1 = element->getVertex(0);
	v2 = element->getVertex(1);
	v3 = element->getVertex(2);
	v4 = element->getVertex(3);
	if(unmovable2.find(v1)==unmovable2.end()){
	  movable2.insert(v1);
	}
	if(unmovable2.find(v2)==unmovable2.end()){
	  movable2.insert(v2);
	}
	if(unmovable2.find(v3)==unmovable2.end()){
	  movable2.insert(v3);
	}
	if(unmovable2.find(v4)==unmovable2.end()){
      movable2.insert(v4);
	}
  }		

  for(it=unmovable2.begin();it!=unmovable2.end();it++){
    unmovable.push_back(*it);
  }

  for(it=movable2.begin();it!=movable2.end();it++){
    movable.push_back(*it);
  }

  offset = unmovable.size();
		
  for(i=0;i<unmovable.size();i++){
	point = SPoint3(unmovable[i]->x(),unmovable[i]->y(),unmovable[i]->z());
	bank.push_back(point);
	movability.push_back(0);
  }
	
  for(i=0;i<movable.size();i++){
    point = SPoint3(movable[i]->x(),movable[i]->y(),movable[i]->z());
	bank.push_back(point);
	movability.push_back(1);
  }	

  w = Wrap();
  w.set_p(norm);
  w.set_dimension(3*(bank.size()-offset));
  w.set_iteration(0);
  w.set_max_iteration(2*max_iter);
  w.set_offset(offset);
  w.set_initial_energy(-1000000.0);
  w.set_octree(octree);
  w.resize(bank.size());
  for(i=0;i<bank.size();i++) w.set_bank(bank[i],i);
  for(i=0;i<bank.size();i++) w.set_movability(movability[i],i);

  //if((bank.size()-offset)>1){	
    //LpCVT obj;
    //obj.get_gauss();
    //obj.verification(bank,movability,offset,6);
  //}

  epsg = 0;
  epsf = 0;
  epsx = 0;
  maxits = max_iter;
  
  double initial_conditions[3*(bank.size()-offset)];
  double scales[3*(bank.size()-offset)];
  factor = 2.0;
  for(i=0;i<(bank.size()-offset);i++){
    initial_conditions[i] = bank[i+offset].x();
	initial_conditions[i+(bank.size()-offset)] = bank[i+offset].y();
	initial_conditions[i+2*(bank.size()-offset)] = bank[i+offset].z();
	scales[i] = factor*get_size(bank[i+offset].x(),bank[i+offset].y(),bank[i+offset].z());
	scales[i+(bank.size()-offset)] = factor*get_size(bank[i+offset].x(),bank[i+offset].y(),bank[i+offset].z());
	scales[i+2*(bank.size()-offset)] = factor*get_size(bank[i+offset].x(),bank[i+offset].y(),bank[i+offset].z());
  }
  x.setcontent(3*(bank.size()-offset),initial_conditions);
  alglib_scales.setcontent(3*(bank.size()-offset),scales);

  if((bank.size()-offset)>1){	
    minlbfgscreate(3*(bank.size()-offset),4,x,state);
	minlbfgssetscale(state,alglib_scales);
	minlbfgssetprecscale(state);
    minlbfgssetcond(state,epsg,epsf,epsx,maxits);
    minlbfgsoptimize(state,call_back,NULL,&w);
    minlbfgsresults(state,x,rep);
  }

  for(i=0;i<(bank.size()-offset);i++){
    vertex = new MVertex(x[i],x[i+(bank.size()-offset)],x[i+2*(bank.size()-offset)],gr,0);
	interior_vertices.push_back(vertex);
  }

  for(i=0;i<unmovable.size();i++){
    if(unmovable[i]->onWhat()->dim()==3){
	  vertex = new MVertex(unmovable[i]->x(),unmovable[i]->y(),unmovable[i]->z(),gr,0);
	  interior_vertices.push_back(vertex);
	}
  }	
		
  deleter(gr);
  std::vector<GRegion*> regions;
  regions.push_back(gr);
  meshGRegion mesher(regions); //?
  mesher(gr); //?
  MeshDelaunayVolume(regions);
  
  for(i=0;i<interior_vertices.size();i++) delete interior_vertices[i];
  interior_vertices.clear();
  delete octree;
}

double LpSmoother::get_size(double x,double y,double z){
  return 0.25;
}

int LpSmoother::get_nbr_interior_vertices(){
  return interior_vertices.size();
}
 
MVertex* LpSmoother::get_interior_vertex(int i){
  return interior_vertices[i];
}

/*********static declarations*********/

std::vector<MVertex*> LpSmoother::interior_vertices;

#endif
