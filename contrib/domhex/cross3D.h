// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   François Henrotte

#ifndef CROSS_3D_H
#define CROSS_3D_H

#include <ostream>
using std::ostream;

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

class Qtn {
public:
  double v[4];
  Qtn(){};
  ~Qtn(){};
  Qtn(const SVector3 &axis, const double theta = M_PI)
  {
    double temp = sin(0.5 * theta);
    v[0] = axis[0] * temp;
    v[1] = axis[1] * temp;
    v[2] = axis[2] * temp;
    v[3] = cos(0.5 * theta);
  }
  double re() const { return v[3]; }
  SVector3 im() const { return SVector3(v[0], v[1], v[2]); }
  Qtn conj()
  {
    v[0] *= -1.;
    v[1] *= -1.;
    v[2] *= -1.;
    return *this;
  }
  Qtn opp()
  {
    v[0] *= -1.;
    v[1] *= -1.;
    v[2] *= -1.;
    v[3] *= -1.;
    return *this;
  }
  double operator[](const unsigned int i) const { return v[i]; }
  void storeProduct(const Qtn &x, const Qtn &y);
  Qtn operator*(const Qtn &x) const;
  SVector3 eulerAxisFromQtn(const Qtn &x);
  double eulerAngleFromQtn(const Qtn &x);
};

double re(const Qtn &x) { return x.re(); }
SVector3 im(const Qtn &x) { return x.im(); }
Qtn conj(const Qtn &x)
{
  Qtn y(x);
  return y.conj();
}

void Qtn::storeProduct(const Qtn &x, const Qtn &y)
{
  double a0 = x[0], a1 = x[1], a2 = x[2], a3 = x[3];
  double b0 = y[0], b1 = y[1], b2 = y[2], b3 = y[3];
  v[0] = a0 * b3 + a1 * b2 - a2 * b1 + a3 * b0;
  v[1] = -a0 * b2 + a1 * b3 + a2 * b0 + a3 * b1;
  v[2] = a0 * b1 - a1 * b0 + a2 * b3 + a3 * b2;
  v[3] = -a0 * b0 - a1 * b1 - a2 * b2 + a3 * b3;
}
Qtn Qtn::operator*(const Qtn &y) const
{
  Qtn x;
  x.storeProduct(*this, y);
  return x;
}

SVector3 eulerAxisFromQtn(const Qtn &x)
{
  double temp = sqrt(1. - x[3] * x[3]);
  if(temp < 1e-10)
    return SVector3(1, 0, 0);
  else
    return SVector3(x[0] / temp, x[1] / temp, x[2] / temp);
}

double eulerAngleFromQtn(const Qtn &x) { return 2. * acos(x[3]); }

#define TOL 1e-12
ostream &operator<<(ostream &os, const Qtn &x)
{
  os << "[ " << ((fabs(x[0]) < TOL) ? 0 : x[0]) << ", "
     << ((fabs(x[1]) < TOL) ? 0 : x[1]) << ", "
     << ((fabs(x[2]) < TOL) ? 0 : x[2]) << "; "
     << ((fabs(x[3]) < TOL) ? 0 : x[3]) << " ]";
  return os;
}
ostream &operator<<(ostream &os, const SVector3 &v)
{
  os << "( " << ((fabs(v.x()) < TOL) ? 0 : v.x()) << ", "
     << ((fabs(v.y()) < TOL) ? 0 : v.y()) << ", "
     << ((fabs(v.z()) < TOL) ? 0 : v.z()) << " )";
  return os;
}

class cross3D {
private:
  SVector3 frst, scnd;

public:
  cross3D()
  {
    frst = SVector3(1, 0, 0);
    scnd = SVector3(0, 1, 0);
  }
  cross3D(const SVector3 &a, const SVector3 &b)
  {
    frst = a.unit();
    scnd = crossprod(crossprod(frst, b), frst).unit();
  }
  cross3D(const SVector3 &a)
  {
    // if only a is given, b is an arbitrary vector not parallel to a
    SVector3 b, Ex(1, 0, 0), Ey(0, 1, 0);
    frst = a.unit();
    b = (crossprod(a, Ex).norm() < 1e-2) ? Ey : Ex;
    scnd = crossprod(crossprod(frst, b), frst).unit();
  }
  cross3D(const STensor3 &x)
  {
    STensor3 m = x;
    SVector3 a(m.get_m11(), m.get_m21(), m.get_m31());
    SVector3 b(m.get_m12(), m.get_m22(), m.get_m32());
    frst = a.unit();
    scnd = crossprod(crossprod(a, b), a).unit();
  }
  ~cross3D() {}
  SVector3 getFrst() const { return frst; }
  SVector3 getScnd() const { return scnd; }
  SVector3 getThrd() const { return crossprod(frst, scnd); }
  cross3D get(const int k) const;
  bool test() const
  {
    if((fabs(dot(frst, scnd)) > 1e-8) || (fabs(frst.norm() - 1.) > 1e-8) ||
       (fabs(scnd.norm() - 1.) > 1e-8)) {
      std::cout << "Illegal cross" << std::endl;
      exit(1);
      return false;
    }
    return true;
  }
  cross3D rotate(const Qtn &R)
  {
    frst = im(R * frst * conj(R));
    scnd = im(R * scnd * conj(R));
    return *this;
  }
  Qtn correspQuat();
  Qtn rotationDirectTo(const cross3D &y) const;
  Qtn rotationTo(const cross3D &y) const;
  Qtn rotationToOnSurf(const cross3D &y) const;
};

ostream &operator<<(ostream &os, const cross3D &x)
{
  os << x.getFrst() << " /\\ " << x.getScnd();
  return os;
}

cross3D cross3D::get(int k) const
{
  SVector3 a, b;
  switch(k) {
  case 0:
    a = getFrst();
    b = getScnd();
    break;
  case 1:
    a = getFrst();
    b = -1 * getScnd();
    break;
  case 2:
    a = getFrst();
    b = getThrd();
    break;
  case 3:
    a = getFrst();
    b = -1 * getThrd();
    break;
  case 4:
    a = -1 * getFrst();
    b = getScnd();
    break;
  case 5:
    a = -1 * getFrst();
    b = -1 * getScnd();
    break;
  case 6:
    a = -1 * getFrst();
    b = getThrd();
    break;
  case 7:
    a = -1 * getFrst();
    b = -1 * getThrd();
    break;

  case 8:
    a = getScnd();
    b = getThrd();
    break;
  case 9:
    a = getScnd();
    b = -1 * getThrd();
    break;
  case 10:
    a = getScnd();
    b = getFrst();
    break;
  case 11:
    a = getScnd();
    b = -1 * getFrst();
    break;
  case 12:
    a = -1 * getScnd();
    b = getThrd();
    break;
  case 13:
    a = -1 * getScnd();
    b = -1 * getThrd();
    break;
  case 14:
    a = -1 * getScnd();
    b = getFrst();
    break;
  case 15:
    a = -1 * getScnd();
    b = -1 * getFrst();
    break;

  case 16:
    a = getThrd();
    b = getFrst();
    break;
  case 17:
    a = getThrd();
    b = -1 * getFrst();
    break;
  case 18:
    a = getThrd();
    b = getScnd();
    break;
  case 19:
    a = getThrd();
    b = -1 * getScnd();
    break;
  case 20:
    a = -1 * getThrd();
    b = getFrst();
    break;
  case 21:
    a = -1 * getThrd();
    b = -1 * getFrst();
    break;
  case 22:
    a = -1 * getThrd();
    b = getScnd();
    break;
  case 23:
    a = -1 * getThrd();
    b = -1 * getScnd();
    break;
  default: std::cout << "Argument out of range" << std::endl; exit(1);
  }
  return cross3D(a, b);
}

Qtn cross3D::correspQuat()
{
  /*
     returns the quaternion representing the rotation from the canonical basis
     to this
   */
  SVector3 frst = SVector3(1, 0, 0);
  SVector3 scnd = SVector3(0, 1, 0);
  cross3D xx = cross3D(frst, scnd);
  cross3D yy = *this;
  Qtn R = xx.rotationDirectTo(yy);
  return R;
}

Qtn cross3D::rotationDirectTo(const cross3D &y) const
{
  double dmin, th1, th2;
  SVector3 axis;
  Qtn Rxy1, Rxy2;

  cross3D xx = *this;
  cross3D yy = y;

  // ind1 = 0; jmin=0; dmin = angle(xx.get(kmin).frst, vect[jmin]);
  dmin = angle(xx.frst, yy.frst);

  th1 = dmin;

  if(th1 > 1e-8)
    axis = crossprod(xx.frst, yy.frst).unit();
  else {
    axis = SVector3(1, 0, 0);
    th1 = 0.;
  }

  Rxy1 = Qtn(axis, th1);
  xx.rotate(Rxy1);

  dmin = angle(xx.scnd, yy.scnd);
  // xx.scnd and yy.scnd now form the smallest angle among the 4^2 possible.

  th2 = dmin;

  if(th2 > 1e-8)
    axis = crossprod(xx.scnd, yy.scnd).unit();
  else {
    axis = SVector3(1, 0, 0);
    th2 = 0.;
  }

  Rxy2 = Qtn(axis, th2);
  Qtn R = Rxy2 * Rxy1;

  // test
  double theta = eulerAngleFromQtn(R);
  if(theta > 1.07 /*0.988*/) { //
    std::cout << "Ouch! th1 = " << th1 << " th2 = " << th2 << std::endl;
    std::cout << "x = " << *this << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "R = " << R << std::endl;
    std::cout << "u = " << eulerAngleFromQtn(R) << std::endl;
    std::cout << "axis = " << eulerAxisFromQtn(R) << std::endl;
  }

  return R;
}

Qtn cross3D::rotationTo(const cross3D &y) const
{
  /* x.rotationTo(y) returns a quaternion R representing the rotation
     such that y = R x, x = conj(R) y
     eulerAngleFromQtn(R) = distance(x, y)
     if onFace is true, only the rotation around y.frst (which is the normal) is
     returned
  */
  double d, dmin, jmin, kmin, th1, th2;
  SVector3 axis;
  Qtn Rxy1, Rxy2;

  cross3D xx = *this;
  cross3D yy = y;

  // ind1 = 0; jmin=0; dmin = angle(xx.get(kmin).frst, vect[jmin]);
  dmin = M_PI;
  jmin = kmin = 0;
  for(int j = 0; j < 24; j = j + 4) {
    for(int k = 0; k < 12; k = k + 4) {
      if((d = angle(xx.get(j).frst, yy.get(k).frst)) < dmin) {
        kmin = k;
        jmin = j;
        dmin = d;
      }
    }
  }
  xx = xx.get(jmin);
  yy = yy.get(kmin);
  // xx.frst and yy.frst now form the smallest angle among the 6^2 possible.

  th1 = dmin;
  if(th1 > 1.00001 * acos(1. / sqrt(3.))) {
    std::cout << "This should not happen: th1 = " << th1 << std::endl;
    exit(1);
  }
  if(th1 > 1e-8)
    axis = crossprod(xx.frst, yy.frst).unit();
  else {
    axis = SVector3(1, 0, 0);
    th1 = 0.;
  }

  Rxy1 = Qtn(axis, th1);
  xx.rotate(Rxy1);

  dmin = M_PI;
  for(int j = 0; j < 4; j++) {
    if((d = angle(xx.get(j).scnd, yy.scnd)) < dmin) {
      jmin = j;
      dmin = d;
    }
  }
  xx = xx.get(jmin);
  // xx.scnd and yy.scnd now form the smallest angle among the 4^2 possible.

  th2 = dmin;
  if(th2 > M_PI / 4.) {
    std::cout << "This should not happen: th2 = " << th2 << std::endl;
    exit(1);
  }
  if(th2 > 1e-8)
    axis = crossprod(xx.scnd, yy.scnd).unit();
  else {
    axis = SVector3(1, 0, 0);
    th2 = 0.;
  }

  Rxy2 = Qtn(axis, th2);
  Qtn R = Rxy2 * Rxy1;

  // test
  double theta = eulerAngleFromQtn(R);
  if(theta > 1.07 /*0.988*/) { //
    std::cout << "Ouch! th1 = " << th1 << " th2 = " << th2 << std::endl;
    std::cout << "x = " << *this << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "R = " << R << std::endl;
    std::cout << "u = " << eulerAngleFromQtn(R) << std::endl;
    std::cout << "axis = " << eulerAxisFromQtn(R) << std::endl;
  }

  return R;
}

Qtn cross3D::rotationToOnSurf(const cross3D &y) const
{
  /* this->frst and y.frst are assumed to be the normal to the face
     R1 is the rotation such that R1(this->frst) = y.frst.
     R2 is then the rotation such that R2 o R1(this->scnd) = y.scnd
  */
  double d, dmin, jmin, th1, th2;
  SVector3 axis;

  cross3D xx = *this;
  cross3D yy = y;

  th1 = angle(xx.frst, yy.frst);
  if(th1 > 1e-8)
    axis = crossprod(xx.frst, yy.frst).unit();
  else {
    axis = SVector3(1, 0, 0);
    th1 = 0.;
  }

  Qtn R1 = Qtn(axis, th1);
  xx.rotate(R1);
  double temp = fabs(angle(xx.getFrst(), yy.getFrst()));
  if((temp > 1e-8) && (temp < M_PI - 1e-8)) {
    std::cout << "This should not happen: not aligned= " << temp << std::endl;
    exit(1);
  }

  dmin = M_PI;
  jmin = 0;
  for(int j = 0; j < 4; j++) {
    if((d = angle(xx.get(j).scnd, yy.scnd)) < dmin) {
      jmin = j;
      dmin = d;
    }
  }
  xx = xx.get(jmin);
  // xx.scnd and yy.scnd now form the smallest angle among the 4^2 possible.

  th2 = dmin;
  if(th2 > M_PI / 4.) {
    std::cout << "This should not happen: th2 = " << th2 << std::endl;
    exit(1);
  }
  if(th2 > 1e-8)
    axis = crossprod(xx.scnd, yy.scnd).unit();
  else {
    axis = SVector3(1, 0, 0);
    th2 = 0.;
  }

  Qtn R2 = Qtn(axis, th2);
  return R2;
}

STensor3 convert(const cross3D &x)
{
  STensor3 m;
  SVector3 v;
  v = x.getFrst();
  m.set_m11(v[0]);
  m.set_m21(v[1]);
  m.set_m31(v[2]);
  v = x.getScnd();
  m.set_m12(v[0]);
  m.set_m22(v[1]);
  m.set_m32(v[2]);
  v = x.getThrd();
  m.set_m13(v[0]);
  m.set_m23(v[1]);
  m.set_m33(v[2]);
  return m;
}

double computeSetSmoothness(std::vector<cross3D> S)
{
  /* this->frst and y.frst are assumed to be the normal to the face
     R1 is the rotation such that R1(this->frst) = y.frst.
     R2 is then the rotation such that R2 o R1(this->scnd) = y.scnd
  */
  double result = 1.0;
  double qmean[4];
  qmean[0] = 0.0;
  qmean[1] = 0.0;
  qmean[2] = 0.0;
  qmean[3] = 0.0;
  std::vector<cross3D>::iterator it1 = S.begin();
  cross3D cInit = (*it1);
  Qtn qInit = cInit.correspQuat();
  for(it1 = S.begin(); it1 != S.end(); it1++) {
    // pour chaque element du set
    cross3D cTmp = (*it1);
    Qtn qTmp = cTmp.correspQuat();
    double prodVecMin = 0.0;
    for(unsigned int i = 1; i < 24; i++) {
      // on trouve la cross appropriee
      Qtn qTmpi = cTmp.get(i).correspQuat();
      double prodVeci = 0.0;
      for(unsigned int j = 0; j < 4; j++) {
        prodVeci += qInit.v[j] * qTmpi.v[j];
      }
      if(prodVeci >= 0.0) {
        if(prodVeci > prodVecMin) {
          prodVecMin = prodVeci;
          qTmp = qTmpi;
        }
      }
      else {
        prodVeci = -prodVeci;
        qTmpi = qTmpi.opp();
        if(prodVeci > prodVecMin) {
          prodVecMin = prodVeci;
          qTmp = qTmpi;
        }
      }
    }
    // on a trouve le quat approprie
    for(unsigned int j = 0; j < 4; j++) { qmean[j] += qTmp[j]; }
  }
  double normQt = sqrt(qmean[0] * qmean[0] + qmean[1] * qmean[1] +
                       qmean[2] * qmean[2] + qmean[3] * qmean[3]);
  if(normQt != 0.0) {
    for(unsigned int j = 0; j < 4; j++) { qmean[j] = qmean[j] / normQt; }
  }
  for(it1 = S.begin(); it1 != S.end(); it1++) {
    // pour chaque element du set
    cross3D cTmp = (*it1);
    Qtn qTmp = cTmp.correspQuat();
    double prodVecMin = 0.0;
    for(unsigned int i = 0; i < 24; i++) {
      // on trouve la cross appropriee
      Qtn qTmpi = cTmp.get(i).correspQuat();
      double prodVeci = 0.0;
      for(unsigned int j = 0; j < 4; j++) { prodVeci += qmean[j] * qTmpi.v[j]; }
      if(prodVeci >= 0.0) {
        if(prodVeci > prodVecMin) {
          prodVecMin = prodVeci;
          qTmp = qTmpi;
        }
      }
      else {
        prodVeci = -prodVeci;
        qTmpi = qTmpi.opp();
        if(prodVeci > prodVecMin) {
          prodVecMin = prodVeci;
          qTmp = qTmpi;
        }
      }
    }
    // on a trouve le quat approprie
    if(prodVecMin < result) { result = prodVecMin; }
  }
  return result;
}

#endif
