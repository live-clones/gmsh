#include "Levy3D.h"
#include "polynomialBasis.h"
#include "Gauss.h"
#include "GModel.h"
#include "MElement.h"
#include "MElementOctree.h"
#include "meshGRegion.h"

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

double VoronoiVertex::get_rho(){
  return rho;
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

void VoronoiVertex::set_rho(double new_rho){
  rho = new_rho;
}

/*********class Metric*********/

Metric::Metric(){
  m11 = 1.0;
  m12 = 0.0;
  m13 = 0.0;
  m21 = 0.0;
  m22 = 1.0;
  m23 = 0.0;
  m31 = 0.0;
  m32 = 0.0;
  m33 = 1.0;	
}

Metric::~Metric(){}

void Metric::set_m11(double new_m11){
  m11 = new_m11;
}

void Metric::set_m12(double new_m12){
  m12 = new_m12;
}

void Metric::set_m13(double new_m13){
  m13 = new_m13;
}

void Metric::set_m21(double new_m21){
  m21 = new_m21;
}

void Metric::set_m22(double new_m22){
  m22 = new_m22;
}

void Metric::set_m23(double new_m23){
  m23 = new_m23;
}

void Metric::set_m31(double new_m31){
  m31 = new_m31;
}

void Metric::set_m32(double new_m32){
  m32 = new_m32;
}

void Metric::set_m33(double new_m33){
  m33 = new_m33;
}

double Metric::get_m11(){
  return m11;
}

double Metric::get_m12(){
  return m12;
}

double Metric::get_m13(){
  return m13;
}

double Metric::get_m21(){
  return m21;
}

double Metric::get_m22(){
  return m22;
}

double Metric::get_m23(){
  return m23;
}

double Metric::get_m31(){
  return m31;
}

double Metric::get_m32(){
  return m32;
}

double Metric::get_m33(){
  return m33;
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

double VoronoiElement::get_drho_dx(){
  return drho_dx;
}

double VoronoiElement::get_drho_dy(){
  return drho_dy;
}

double VoronoiElement::get_drho_dz(){
  return drho_dz;
}

Metric VoronoiElement::get_metric(){
  return m;
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

void VoronoiElement::set_metric(Metric new_m){
  m = new_m;
}

double VoronoiElement::get_rho(double u,double v,double w){
  double rho1;
  double rho2;
  double rho3;
  double rho4;
  double rho;
	
  rho1 = v1.get_rho();
  rho2 = v2.get_rho();
  rho3 = v3.get_rho();
  rho4 = v4.get_rho();
  rho = T(u,v,w,rho1,rho2,rho3,rho4); //A CORRIGER POUR 2D
  return rho;
}

void VoronoiElement::deriv_rho(){
  double rho1;
  double rho2;
  double rho3;
  double rho4;
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
  double drho_du;
  double drho_dv;
  double drho_dw;
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
  jacobian2 = t11*(t22*t33-t23*t32) - t12*(t12*t33-t13*t32) + t13*(t12*t23-t13*t22);
  b11 = t22*t33-t32*t23;
  b12 = t13*t32-t12*t33;
  b13 = t12*t23-t13*t22;
  b21 = t31*t23-t21*t33;
  b22 = t11*t33-t13*t31;
  b23 = t21*t13-t23*t11;
  b31 = t21*t32-t31*t22;
  b32 = t12*t31-t32*t11;
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
	
  rho1 = v1.get_rho();
  rho2 = v2.get_rho();
  rho3 = v3.get_rho();
  rho4 = v4.get_rho();
  drho_du = rho2-rho1;
  drho_dv = rho3-rho1;
  drho_dw = rho4-rho1;
  
  drho_dx = drho_du*du_dx + drho_dv*dv_dx + drho_dw*dw_dx;
  drho_dy = drho_du*du_dy + drho_dv*dv_dy + drho_dw*dw_dy;
  drho_dz = drho_du*du_dz + drho_dv*dv_dz + drho_dw*dw_dz;
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

double VoronoiElement::h_to_rho(double h,int p){
  double rho;
  rho = pow_int(1.0/h,p+3);
  return rho;
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

/*********class LpCVT*********/

LpCVT::LpCVT(){}

LpCVT::~LpCVT(){}

void LpCVT::swap(){
  std::list<VoronoiElement>::iterator it;
  for(it=clipped.begin();it!=clipped.end();it++){
	it->swap();		
  }
}

void LpCVT::compute_parameters(int p){
  double h1,h2,h3,h4;
  double rho1,rho2,rho3,rho4;
  Metric m;
  VoronoiVertex v1,v2,v3,v4;
  std::list<VoronoiElement>::iterator it;
		
  for(it=clipped.begin();it!=clipped.end();it++){
	v1 = it->get_v1();
	v2 = it->get_v2();
	v3 = it->get_v3();
	v4 = it->get_v4(); 
	h1 = 0.0000001;
	h2 = 0.0000001;
	h3 = 0.0000001;
	h4 = 0.0000001;
	rho1 = it->h_to_rho(h1,p);
	rho2 = it->h_to_rho(h2,p);
	rho3 = it->h_to_rho(h3,p);
	rho4 = it->h_to_rho(h4,p);
	v1.set_rho(rho1);
	v2.set_rho(rho2);
	v3.set_rho(rho3);
	v4.set_rho(rho4);
	it->set_v1(v1);
	it->set_v2(v2);
	it->set_v3(v3);
	it->set_v4(v4);
	m = Metric();
	m.set_m11(1.0);
	m.set_m12(0.0);
	m.set_m13(0.0);
	m.set_m21(0.0);
	m.set_m22(1.0);
	m.set_m23(0.0);
	m.set_m31(0.0);
	m.set_m32(0.0);
	m.set_m33(1.0);
	it->set_metric(m);
	it->compute_jacobian();
	it->deriv_rho();
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
  Metric m;
	
  v1 = element.get_v1();
  v2 = element.get_v2();
  v3 = element.get_v3();
  v4 = element.get_v4();
  generator = v1.get_point();
  C1 = v2.get_point();
  C2 = v3.get_point();
  C3 = v4.get_point();
  energy = 0.0;
  m = element.get_metric();
	
  for(i=0;i<gauss_num;i++){
    u = gauss_points(i,0);
	v = gauss_points(i,1);
	w = gauss_points(i,2);
	x = element.T(u,v,w,generator.x(),C1.x(),C2.x(),C3.x());
	y = element.T(u,v,w,generator.y(),C1.y(),C2.y(),C3.y());
	z = element.T(u,v,w,generator.z(),C1.z(),C2.z(),C3.z());
	point = SPoint3(x,y,z);
	weight = gauss_weights(i,0);
	rho = element.get_rho(u,v,w);
	energy = energy + weight*rho*f(generator,point,m,p);
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
  Metric m;
	
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
  m = element.get_metric();
	
  for(i=0;i<gauss_num;i++){
    u = gauss_points(i,0);
	v = gauss_points(i,1);
	w = gauss_points(i,2);
	x = element.T(u,v,w,generator.x(),C1.x(),C2.x(),C3.x());
	y = element.T(u,v,w,generator.y(),C1.y(),C2.y(),C3.y());
	z = element.T(u,v,w,generator.z(),C1.z(),C2.z(),C3.z());
	point = SPoint3(x,y,z);
	weight = gauss_weights(i,0);
	rho = element.get_rho(u,v,w);
	comp_x = comp_x + weight*rho*df_dx(generator,point,m,p);
	comp_y = comp_y + weight*rho*df_dy(generator,point,m,p);
	comp_z = comp_z + weight*rho*df_dz(generator,point,m,p);
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
  Metric m;
	
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
  m = element.get_metric();
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
	rho = element.get_rho(u,v,w);
	drho_dx = element.get_drho_dx();
	drho_dy = element.get_drho_dy();
	drho_dz = element.get_drho_dz();
	distance = f(point,generator,m,p);
	comp_x = comp_x + weight*rho*df_dx(point,generator,m,p)*u*jacobian;
	comp_x = comp_x + weight*rho*distance*((C2.y()-gy)*(C3.z()-gz) - (C3.y()-gy)*(C2.z()-gz));
	comp_x = comp_x + weight*drho_dx*u*distance*jacobian;
	comp_y = comp_y + weight*rho*df_dy(point,generator,m,p)*u*jacobian;
	comp_y = comp_y + weight*rho*distance*((C2.z()-gz)*(C3.x()-gx) - (C2.x()-gx)*(C3.z()-gz));
	comp_y = comp_y + weight*drho_dy*u*distance*jacobian;
	comp_z = comp_z + weight*rho*df_dz(point,generator,m,p)*u*jacobian;
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
  Metric m;
	
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
  m = element.get_metric();
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
	rho = element.get_rho(u,v,w);
	drho_dx = element.get_drho_dx();
	drho_dy = element.get_drho_dy();
	drho_dz = element.get_drho_dz();
	distance = f(point,generator,m,p);
	comp_x = comp_x + weight*rho*df_dx(point,generator,m,p)*v*jacobian;
	comp_x = comp_x + weight*rho*distance*((C1.z()-gz)*(C3.y()-gy) - (C1.y()-gy)*(C3.z()-gz));
	comp_x = comp_x + weight*drho_dx*v*distance*jacobian;
	comp_y = comp_y + weight*rho*df_dy(point,generator,m,p)*v*jacobian;
	comp_y = comp_y + weight*rho*distance*((C1.x()-gx)*(C3.z()-gz) - (C3.x()-gx)*(C1.z()-gz));
	comp_y = comp_y + weight*drho_dy*v*distance*jacobian;
	comp_z = comp_z + weight*rho*df_dz(point,generator,m,p)*v*jacobian;
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
  Metric m;
	
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
  m = element.get_metric();
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
	rho = element.get_rho(u,v,w);
	drho_dx = element.get_drho_dx();
	drho_dy = element.get_drho_dy();
	drho_dz = element.get_drho_dz();
	distance = f(point,generator,m,p);
	comp_x = comp_x + weight*rho*df_dx(point,generator,m,p)*w*jacobian;
	comp_x = comp_x + weight*rho*distance*((C1.y()-gy)*(C2.z()-gz) - (C2.y()-gy)*(C1.z()-gz));
	comp_x = comp_x + weight*drho_dx*w*distance*jacobian;
	comp_y = comp_y + weight*rho*df_dy(point,generator,m,p)*w*jacobian;
	comp_y = comp_y + weight*rho*distance*((C2.x()-gx)*(C1.z()-gz) - (C1.x()-gx)*(C2.z()-gz));
	comp_y = comp_y + weight*drho_dy*w*distance*jacobian;
	comp_z = comp_z + weight*rho*df_dz(point,generator,m,p)*w*jacobian;
	comp_z = comp_z + weight*rho*distance*((C1.x()-gx)*(C2.y()-gy) - (C2.x()-gx)*(C1.y()-gy));
	comp_z = comp_z + weight*drho_dz*w*distance*jacobian;
  }		
  return SVector3(comp_x,comp_y,comp_z);
}

double LpCVT::f(SPoint3 p1,SPoint3 p2,Metric m,int p){
  double x1,y1,z1;
  double x2,y2,z2;
  double m11,m12,m13;
  double m21,m22,m23;
  double m31,m32,m33;
  double val1,val2,val3;
  double val;
	
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  m11 = m.get_m11();
  m12 = m.get_m12();
  m13 = m.get_m13();
  m21 = m.get_m21();
  m22 = m.get_m22();
  m23 = m.get_m23();
  m31 = m.get_m31();
  m32 = m.get_m32();
  m33 = m.get_m33();	
  val1 = m11*x1 + m12*y1 + m13*z1 - m11*x2 - m12*y2 - m13*z2; //A AMELIORER POUR 2D ET 3D ?
  val2 = m21*x1 + m22*y1 + m23*z1 - m21*x2 - m22*y2 - m23*z2;
  val3 = m31*x1 + m32*y1 + m33*z1 - m31*x2 - m32*y2 - m33*z2;
  val = pow_int(val1,p) + pow_int(val2,p) + pow_int(val3,p);
  return val;
}

double LpCVT::df_dx(SPoint3 p1,SPoint3 p2,Metric m,int p){
  double x1,y1,z1;
  double x2,y2,z2;
  double m11,m12,m13;
  double m21,m22,m23;
  double m31,m32,m33;
  double val1,val2,val3;
  double val;
	
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  m11 = m.get_m11();
  m12 = m.get_m12();
  m13 = m.get_m13();
  m21 = m.get_m21();
  m22 = m.get_m22();
  m23 = m.get_m23();
  m31 = m.get_m31();
  m32 = m.get_m32();
  m33 = m.get_m33();	
  val1 = m11*x1 + m12*y1 + m13*z1 - m11*x2 - m12*y2 - m13*z2;
  val2 = m21*x1 + m22*y1 + m23*z1 - m21*x2 - m22*y2 - m23*z2;
  val3 = m31*x1 + m32*y1 + m33*z1 - m31*x2 - m32*y2 - m33*z2;
  val = ((double)p)*pow_int(val1,p-1)*m11 + ((double)p)*pow_int(val2,p-1)*m21 + ((double)p)*pow_int(val3,p-1)*m31;
  return val;
}

double LpCVT::df_dy(SPoint3 p1,SPoint3 p2,Metric m,int p){
  double x1,y1,z1;
  double x2,y2,z2;
  double m11,m12,m13;
  double m21,m22,m23;
  double m31,m32,m33;
  double val1,val2,val3;
  double val;
	
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  m11 = m.get_m11();
  m12 = m.get_m12();
  m13 = m.get_m13();
  m21 = m.get_m21();
  m22 = m.get_m22();
  m23 = m.get_m23();
  m31 = m.get_m31();
  m32 = m.get_m32();
  m33 = m.get_m33();	
  val1 = m11*x1 + m12*y1 + m13*z1 - m11*x2 - m12*y2 - m13*z2;
  val2 = m21*x1 + m22*y1 + m23*z1 - m21*x2 - m22*y2 - m23*z2;
  val3 = m31*x1 + m32*y1 + m33*z1 - m31*x2 - m32*y2 - m33*z2;
  val = ((double)p)*pow_int(val1,p-1)*m12 + ((double)p)*pow_int(val2,p-1)*m22 + ((double)p)*pow_int(val3,p-1)*m32;
  return val;
}

double LpCVT::df_dz(SPoint3 p1,SPoint3 p2,Metric m,int p){
  double x1,y1,z1;
  double x2,y2,z2;
  double m11,m12,m13;
  double m21,m22,m23;
  double m31,m32,m33;
  double val1,val2,val3;
  double val;
	
  x1 = p1.x();
  y1 = p1.y();
  z1 = p1.z();
  x2 = p2.x();
  y2 = p2.y();
  z2 = p2.z();
  m11 = m.get_m11();
  m12 = m.get_m12();
  m13 = m.get_m13();
  m21 = m.get_m21();
  m22 = m.get_m22();
  m23 = m.get_m23();
  m31 = m.get_m31();
  m32 = m.get_m32();
  m33 = m.get_m33();	
  val1 = m11*x1 + m12*y1 + m13*z1 - m11*x2 - m12*y2 - m13*z2;
  val2 = m21*x1 + m22*y1 + m23*z1 - m21*x2 - m22*y2 - m23*z2;
  val3 = m31*x1 + m32*y1 + m33*z1 - m31*x2 - m32*y2 - m33*z2;
  val = ((double)p)*pow_int(val1,p-1)*m13 + ((double)p)*pow_int(val2,p-1)*m23 + ((double)p)*pow_int(val3,p-1)*m33;
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
  int j;
  double epsg;
  double epsf;
  double epsx;
  MVertex* vertex;
  MElement* element;
  MElementOctree* octree;
  deMeshGRegion deleter;
  double initial_conditions[2];
  std::set<MVertex*> all_vertices;
  std::vector<MVertex*> interior_vertices;
  std::set<MVertex*>::iterator it;
  alglib::ae_int_t maxits;
  alglib::minlbfgsstate state;
  alglib::minlbfgsreport rep;
  alglib::real_1d_array x;
	
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
	for(j=0;j<element->getNumVertices();j++){
	  vertex = element->getVertex(j);
	  all_vertices.insert(vertex);
	}
  }
	
  octree = new MElementOctree(gr->model());
	
  epsg = 0;
  epsf = 0;
  epsx = 0;
  maxits = max_iter;
  
  initial_conditions[0] = 12.0;
  initial_conditions[1] = 37.0;
  x.setcontent(2,initial_conditions);
	
  minlbfgscreate(2,1,x,state);
  minlbfgssetcond(state,epsg,epsf,epsx,maxits);
  minlbfgsoptimize(state,call_back,NULL,NULL);
  minlbfgsresults(state,x,rep);
  printf("%f %f\n",x[0],x[1]);
	
  for(it=all_vertices.begin();it!=all_vertices.end();it++){
	if((*it)->onWhat()->dim()==3){
	  interior_vertices.push_back(*it);
	}
  }
  printf("%d\n",interior_vertices.size());
	
  deleter(gr);
  //std::vector<GRegion*> regions;
  //regions.push_back(gr);
  //meshGRegion mesher(regions);
  //mesher(gr);
}

/*********functions*********/

bool inside_domain(MElementOctree* octree,double x,double y,double z){
  MElement* element;
  element = (MElement*)octree->find(x,y,z,3,true);
  if(element!=NULL) return 1;
  else return 0;
}

void call_back(const alglib::real_1d_array& x,double& func,alglib::real_1d_array& grad,void* ptr){
  func = pow_int(3.0-x[0],2) + pow_int(4.0-x[1],2);
  grad[0] = -2.0*(3.0-x[0]);
  grad[1] = -2.0*(4.0-x[1]);
}
