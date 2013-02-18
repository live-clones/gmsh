// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributor(s):
//   François Henrotte

#ifndef _CROSS_3D_H_
#define _CROSS_3D_H_

#include "stat_cwmtx.h"
#include "stat_quatern.h"
using namespace CwMtx;

//double max(const double a, const double b) { return (b>a)?b:a;}
double min(const double a, const double b) { return (b<a)?b:a; }
double squ(const double a) { return a*a; }

double angle(const CWTSSpaceVector<> v, const CWTSSpaceVector<> w) {
  /* returns the angle (in radian) between the vectors v and w
     the return value is between 0 and pi/2                      */
  double val = atan2((v % w).norm(), v*w);
  if((val < 0) || (val > M_PI)){
    std::cout << "This should not happen 1" << std::endl; exit(1);
  }
  return val;
}

class cross3D{
private:
  CWTSSpaceVector<> first, second;
public:
  cross3D(const CWTSSpaceVector<> &a, const CWTSSpaceVector<> &b){
    first = a.unit();
    second = ((a % b) % a).unit();
  }
  cross3D(Matrix &m){
    CWTSSpaceVector<> a(m.get_m11(), m.get_m21(), m.get_m31());
    CWTSSpaceVector<> b(m.get_m12(), m.get_m22(), m.get_m32());
    first = a.unit();
    second = ((a % b) % a).unit();
  }
  ~cross3D() {}
  CWTSSpaceVector<> getFirst() const { return first; }
  CWTSSpaceVector<> getSecond() const { return second; }
  CWTSSpaceVector<> getThird() const { return first % second; }
  cross3D get(const int k) const;
  bool test() const{ 
    if(fabs(first*second) > 1e-8){
      std::cout << "Illegal cross" << std::endl;
      exit(1);
    }
    return true;
  }
  cross3D rotate(const CWTSQuaternion<> &R){
    first = im(R*first*conj(R));
    second = im(R*second*conj(R));
    return *this;
  }
  CWTSQuaternion<> rotationTo(const cross3D &x) const;
};

ostream& operator<< (ostream &os, cross3D &x) {
  x.test();
  os << x.getFirst() << " /\\ " << x.getSecond();
  return os;
}
ostream& operator<< (ostream &os, const cross3D &x) {
  x.test();
  os << x.getFirst() << " /\\ " << x.getSecond();
  return os;
}

cross3D cross3D::get(const int k) const{
  CWTSSpaceVector<> a, b;
  switch(k){
  case  0: a = getFirst() ; b = getSecond(); break;
  case  1: a = getFirst() ; b =-getSecond(); break;
  case  2: a = getFirst() ; b = getThird() ; break;
  case  3: a = getFirst() ; b =-getThird() ; break;
  case  4: a =-getFirst() ; b = getSecond(); break;
  case  5: a =-getFirst() ; b =-getSecond(); break;
  case  6: a =-getFirst() ; b = getThird() ; break;
  case  7: a =-getFirst() ; b =-getThird() ; break;

  case  8: a = getSecond(); b = getThird() ; break;
  case  9: a = getSecond(); b =-getThird() ; break;
  case 10: a = getSecond(); b = getFirst() ; break;
  case 11: a = getSecond(); b =-getFirst() ; break;
  case 12: a =-getSecond(); b = getThird() ; break;
  case 13: a =-getSecond(); b =-getThird() ; break;
  case 14: a =-getSecond(); b = getFirst() ; break;
  case 15: a =-getSecond(); b =-getFirst() ; break;

  case 16: a = getThird() ; b = getFirst() ; break;
  case 17: a = getThird() ; b =-getFirst() ; break;
  case 18: a = getThird() ; b = getSecond(); break;
  case 19: a = getThird() ; b =-getSecond(); break;
  case 20: a =-getThird() ; b = getFirst() ; break;
  case 21: a =-getThird() ; b =-getFirst() ; break;
  case 22: a =-getThird() ; b = getSecond(); break;
  case 23: a =-getThird() ; b =-getSecond(); break;
  default:
    std::cout << "Argument out of range" << std::endl;
    exit(1);
  }
  return cross3D(a,b);
}


CWTSQuaternion<> cross3D::rotationTo(const cross3D &y) const{
  /* x.rotationTo(y) returns a quaternion R representing the rotation 
     such that y = R x, x = conj(R) y
     eulerAngleFromQtn(R) = distance(x, y)
  */
  int ind1, ind2;
  double d, dmin;
  CWTSSpaceVector<> n,w,axis;
  CWTSQuaternion<> Rxy1, Rxy2;

  cross3D xx = get(0);
  dmin = angle(xx.first, y.get(0).first); ind1 = 0;
  for(unsigned int k=4 ; k<24; k=k+4){
    if((d = angle(xx.first, y.get(k).first)) < dmin) {
      ind1 = k;
      dmin = d;
    }
  }

  // y.get(ind1) is the attitude of y whose y.first minimizes the angle with x.first

  axis = xx.first % y.get(ind1).first;
  if(axis.norm() > 1e-8)
    axis = axis.unit();
  else {
    axis = CWTSSpaceVector<>(1,0,0);
    dmin = 0.;
  }
  if(dmin > M_PI/2.){
    std::cout << "This should not happen 2" << std::endl; exit(1);
  }
  /* std::cout << "1 xx.first = " << xx.first << " xx.second = " << xx.second << std::endl; */
  /* std::cout << "1 y.first = " <<  y.get(ind1).first <<  " y.second = " <<  y.get(ind1).second << std::endl; */
  /* std::cout << "1 dmin = " << dmin << " axis = " << axis << std::endl; */

  Rxy1 = qtnFromEulerAxisAndAngle(axis, dmin);
  xx.rotate(Rxy1);

  dmin = angle(xx.second, y.get(ind1).second); ind2 = ind1;
  for(unsigned int k=1 ; k<4; k++){
    if((d = angle(xx.second, y.get(ind1 + k).second)) < dmin) {
      ind2 = ind1 + k;
      dmin = d;
    }
  }

  // y.get(ind2) is the attitude of y whose y.second minimizes the angle with xx.second

  axis = xx.second % y.get(ind2).second;
  //axis = xx.first;
  if(axis.norm() > 1e-8)
     axis = axis.unit();
  else {
    axis = CWTSSpaceVector<>(1,0,0);
    dmin = 0.;
  }
  if(dmin > M_PI/2.){
    std::cout << "This should not happen 3" << std::endl; exit(1);
  }
  /* std::cout << "2 xx.first = " << xx.first << " xx.second = " << xx.second << std::endl; */
  /* std::cout << "2 y.first = " <<  y.get(ind2).first <<  " y.second = " <<  y.get(ind2).second << std::endl; */
  /* std::cout << "2 dmin = " << dmin << " axis = " << axis << std::endl; */

  Rxy2 = qtnFromEulerAxisAndAngle(axis, dmin);

  xx.rotate(Rxy2);
  /* std::cout << "3 xx.first = " << xx.first << " xx.second = " << xx.second << std::endl; */
  /* std::cout << "3 y.first = " <<  y.get(ind2).first <<  " y.second = " <<  y.get(ind2).second << std::endl; */

  CWTSQuaternion<> R = Rxy2*Rxy1;

  xx = *this;
  /* std::cout << "Rx = " << xx.rotate(R) << std::endl; */
  /* std::cout << "y = " << y.get(ind2) << std::endl; */

  double theta = eulerAngleFromQtn(R);
  if(theta > acos(1/sqrt(2))){
    std::cout << "x = " << *this << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "R = " << R << std::endl;
    std::cout << "theta = " << theta << std::endl;
    std::cout << "u = " << eulerAngleFromQtn(R) << std::endl << std::endl;
  }
  return R;
}

Matrix convert(const cross3D x){
  Matrix m;
  CWTSSpaceVector<> v; 
  v = x.getFirst() ; m.set_m11(v[0]); m.set_m21(v[1]); m.set_m31(v[2]);
  v = x.getSecond(); m.set_m12(v[0]); m.set_m22(v[1]); m.set_m32(v[2]);
  v = x.getThird() ; m.set_m13(v[0]); m.set_m23(v[1]); m.set_m33(v[2]);
  return m;
}



#endif
