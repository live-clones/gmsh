// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributor(s):
//   François Henrotte

#ifndef _CROSS_3D_H_
#define _CROSS_3D_H_

#include <ostream>
using std::ostream;

#include "Matrix.h"

//double max(const double a, const double b) { return (b>a)?b:a;}
double min(const double a, const double b) { return (b<a)?b:a; }
double squ(const double a) { return a*a; }

/* Defined in SVector3.h */
/* double angle(const SVector3 v, const SVector3 w) { */
/*   /\* returns the angle (in radian) between the vectors v and w */
/*      the return value is between 0 and pi/2                      *\/ */
/*   double val = atan2(crossprod(v, w).norm(), dot(v, w)); */
/*   if((val < 0) || (val > M_PI)){ */
/*     std::cout << "This should not happen 1" << std::endl; exit(1); */
/*   } */
/*   return val; */
/* } */

class Qtn{
public:
  double v[4];
  Qtn(){}; 
  ~Qtn(){};
  Qtn(const SVector3 axis, const double theta = M_PI ){
    double temp = sin(0.5*theta);
    v[0] = axis[0] * temp; 
    v[1] = axis[1] * temp; 
    v[2] = axis[2] * temp; 
    v[3] = cos(0.5 * theta);
  }
  double re() const{ return v[3]; }
  SVector3 im() const{ return SVector3(v[0], v[1], v[2]); }
  Qtn conj() { v[0] *= -1.; v[1] *= -1.; v[2] *= -1.; return *this; }
  double operator [](const unsigned int i) const { return v[i]; }
  void storeProduct(const Qtn &x, const Qtn &y);
  Qtn operator *(const Qtn &x) const;
  SVector3 eulerAxisFromQtn(const Qtn &x);
  double eulerAngleFromQtn(const Qtn &x);
};

double re(const Qtn &x){ return x.re(); }
SVector3 im(const Qtn &x){ return x.im(); }
Qtn conj(const Qtn &x) { Qtn y(x); return y.conj(); }

void Qtn::storeProduct(const Qtn &x, const Qtn &y) {
  double a0 = x[0], a1 = x[1], a2 = x[2], a3 = x[3];
  double b0 = y[0], b1 = y[1], b2 = y[2], b3 = y[3];
  v[0] = a0*b3 + a1*b2 - a2*b1 + a3*b0;
  v[1] =-a0*b2 + a1*b3 + a2*b0 + a3*b1;
  v[2] = a0*b1 - a1*b0 + a2*b3 + a3*b2;
  v[3] =-a0*b0 - a1*b1 - a2*b2 + a3*b3;
}
Qtn Qtn::operator *(const Qtn &x) const {
  Qtn y;
  y.storeProduct(*this, x);
  return y;
}

SVector3 eulerAxisFromQtn(const Qtn &x){
  double temp = sqrt(1. - x[3]*x[3]);
  return SVector3(x[0]/temp, x[1]/temp, x[2]/temp);
}
 
double eulerAngleFromQtn(const Qtn &x){
  return 2.*acos(x[3]);
}

#define TOL 1e-12
ostream& operator<< (ostream &os, const Qtn &x) {
  os << "[ " << ((fabs(x[0])<TOL)?0:x[0])
     << ", " << ((fabs(x[1])<TOL)?0:x[1])
     << ", " << ((fabs(x[2])<TOL)?0:x[2])
     << "; " << ((fabs(x[3])<TOL)?0:x[3]) << " ]";
  return os;
}
ostream& operator<< (ostream &os, const SVector3 &v) {
  os << "( " << ((fabs(v.x())<TOL)?0:v.x()) 
     << ", " << ((fabs(v.y())<TOL)?0:v.y())
     << ", " << ((fabs(v.z())<TOL)?0:v.z()) << " )";
  return os;
}

class cross3D{
private:
  SVector3 frst, scnd;
public:
  cross3D(const SVector3 &a, const SVector3 &b){
    frst = a.unit();
    scnd = crossprod(crossprod(frst, b), frst).unit();
  }
  cross3D(Matrix &m){
    SVector3 a(m.get_m11(), m.get_m21(), m.get_m31());
    SVector3 b(m.get_m12(), m.get_m22(), m.get_m32());
    frst = a.unit();
    scnd = crossprod(crossprod(a, b),a).unit();
  }
  ~cross3D() {}
  SVector3 getFrst() const { return frst; }
  SVector3 getScnd() const { return scnd; }
  SVector3 getThrd() const { return crossprod(frst, scnd); }
  cross3D get(const int k) const;
  bool test() const{ 
    if( (fabs(dot(frst,scnd)) > 1e-8) ||
	(fabs(frst.norm() - 1.) > 1e-8) ||
	(fabs(scnd.norm() - 1.) > 1e-8) ) {
      std::cout << "Illegal cross" << std::endl;
      exit(1);
      return false;
    }
    return true;
  }
  cross3D rotate(const Qtn &R){
    frst = im(R*frst*conj(R));
    scnd = im(R*scnd*conj(R));
    return *this;
  }
  Qtn rotationTo(const cross3D &x) const;
};

ostream& operator<< (ostream &os, const cross3D &x) {
  os << x.getFrst() << " /\\ " << x.getScnd() ;
  return os;
}

cross3D cross3D::get(const int k) const{
  SVector3 a, b;
  switch(k){
  case  0: a =      getFrst() ; b =      getScnd() ; break;
  case  1: a =      getFrst() ; b = -1 * getScnd() ; break;
  case  2: a =      getFrst() ; b =      getThrd() ; break;
  case  3: a =      getFrst() ; b = -1 * getThrd() ; break;
  case  4: a = -1 * getFrst() ; b =      getScnd() ; break;
  case  5: a = -1 * getFrst() ; b = -1 * getScnd() ; break;
  case  6: a = -1 * getFrst() ; b =      getThrd() ; break;
  case  7: a = -1 * getFrst() ; b = -1 * getThrd() ; break;

  case  8: a =      getScnd() ; b =      getThrd() ; break;
  case  9: a =      getScnd() ; b = -1 * getThrd() ; break;
  case 10: a =      getScnd() ; b =      getFrst() ; break;
  case 11: a =      getScnd() ; b = -1 * getFrst() ; break;
  case 12: a = -1 * getScnd() ; b =      getThrd() ; break;
  case 13: a = -1 * getScnd() ; b = -1 * getThrd() ; break;
  case 14: a = -1 * getScnd() ; b =      getFrst() ; break;
  case 15: a = -1 * getScnd() ; b = -1 * getFrst() ; break;

  case 16: a =      getThrd() ; b =      getFrst() ; break;
  case 17: a =      getThrd() ; b = -1 * getFrst() ; break;
  case 18: a =      getThrd() ; b =      getScnd() ; break;
  case 19: a =      getThrd() ; b = -1 * getScnd() ; break;
  case 20: a = -1 * getThrd() ; b =      getFrst() ; break;
  case 21: a = -1 * getThrd() ; b = -1 * getFrst() ; break;
  case 22: a = -1 * getThrd() ; b =      getScnd() ; break;
  case 23: a = -1 * getThrd() ; b = -1 * getScnd() ; break;
  default:
    std::cout << "Argument out of range" << std::endl;
    exit(1);
  }
  return cross3D(a,b);
}

Qtn cross3D::rotationTo(const cross3D &y) const{
  /* x.rotationTo(y) returns a quaternion R representing the rotation 
     such that y = R x, x = conj(R) y
     eulerAngleFromQtn(R) = distance(x, y)
  */
  int ind1, ind2;
  double d, dmin, th1, th2;
  SVector3 n, w, axis;
  Qtn Rxy1, Rxy2;

  cross3D xx = get(0);
  dmin = angle(xx.frst, y.get(0).frst); ind1 = 0;
  for(unsigned int k=4 ; k<24; k=k+4){
    if((d = angle(xx.frst, y.get(k).frst)) < dmin) {
      ind1 = k;
      dmin = d;
    }
  }

  // y.get(ind1) is the attitude of y whose y.first minimizes the angle with x.first

  axis = crossprod(xx.frst, y.get(ind1).frst);
  if(axis.norm() > 1e-8)
    axis.normalize();
  else {
    axis = SVector3(1,0,0);
    dmin = 0.;
  }

  th1 = dmin;
  if(th1 > 1.00001*acos(1./sqrt(3.))){
    std::cout << "This should not happen: th1 = " << th1 << std::endl; 
    exit(1);
  }

  Rxy1 = Qtn(axis, dmin);
  xx.rotate(Rxy1);

  dmin = angle(xx.scnd, y.get(ind1).scnd); ind2 = ind1;
  for(unsigned int k=1 ; k<4; k++){
    if((d = angle(xx.scnd, y.get(ind1 + k).scnd)) < dmin) {
      ind2 = ind1 + k;
      dmin = d;
    }
  }

  // y.get(ind2) is the attitude of y whose y.second minimizes the angle with xx.second

  axis = crossprod(xx.scnd, y.get(ind2).scnd);
  //axis = xx.first;
  if(axis.norm() > 1e-8)
    axis.normalize();
  else {
    axis = SVector3(1,0,0);
    dmin = 0.;
  }

  th2 = dmin;
  if(th2 > M_PI/2.){
    std::cout << "This should not happen: th2 = " << th2 << std::endl; 
    exit(1);
  }
  Rxy2 = Qtn(axis, dmin);

  xx.rotate(Rxy2);
  Qtn R = Rxy2*Rxy1;

  double theta = eulerAngleFromQtn(R);
  if(theta > 1.11){
    std::cout << "Ouch! th1 = " << th1 << " th2 = " << th2 << std::endl;
    std::cout << "x = " << *this << std::endl;
    std::cout << "y = " << y << std::endl;
    /* std::cout << "R = " << R << std::endl; */
    std::cout << "u = " << eulerAngleFromQtn(R) << std::endl;
    std::cout << "axis = " << eulerAxisFromQtn(R) << std::endl;
  }
  return R;
}

Matrix convert(const cross3D x){
  Matrix m;
  SVector3 v; 
  v = x.getFrst() ; m.set_m11(v[0]); m.set_m21(v[1]); m.set_m31(v[2]);
  v = x.getScnd() ; m.set_m12(v[0]); m.set_m22(v[1]); m.set_m32(v[2]);
  v = x.getThrd() ; m.set_m13(v[0]); m.set_m23(v[1]); m.set_m33(v[2]);
  return m;
}



#endif
