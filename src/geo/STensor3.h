// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef STENSOR3_H
#define STENSOR3_H

#include "SVector3.h"
#include "Numeric.h"
#include "GmshMessage.h"

template <class scalar> class fullVector;
template <class scalar> class fullMatrix;

// concrete class for symmetric positive definite 3x3 matrix
class SMetric3 {
protected:
  // lower diagonal storage
  // 00 10 11 20 21 22
  double _val[6];

public:
  // default constructor, identity
  SMetric3(const double v = 1.0)
  {
    _val[0] = _val[2] = _val[5] = v;
    _val[1] = _val[3] = _val[4] = 0.0;
  }
  SMetric3(const SMetric3 &m)
  {
    for(int i = 0; i < 6; i++) _val[i] = m._val[i];
  }
  SMetric3(const double l1, // l1 = h1^-2
           const double l2, const double l3, const SVector3 &t1,
           const SVector3 &t2, const SVector3 &t3);
  inline int getIndex(int i, int j) const
  {
    static int _index[3][3] = {{0, 1, 3}, {1, 2, 4}, {3, 4, 5}};
    return _index[i][j];
  }
  void getMat(fullMatrix<double> &mat) const;
  void setMat(const fullMatrix<double> &mat);
  inline double &operator()(int i, int j) { return _val[getIndex(i, j)]; }
  inline double operator()(int i, int j) const { return _val[getIndex(i, j)]; }
  SMetric3 invert() const;
  double determinant() const;
  SMetric3 operator+(const SMetric3 &other) const
  {
    SMetric3 res(*this);
    for(int i = 0; i < 6; i++) res._val[i] += other._val[i];
    return res;
  }
  SMetric3 &operator+=(const SMetric3 &other)
  {
    for(int i = 0; i < 6; i++) _val[i] += other._val[i];
    return *this;
  }
  SMetric3 &operator*=(const double &other)
  {
    for(int i = 0; i < 6; i++) _val[i] *= other;
    return *this;
  }
  SMetric3 &operator*=(const SMetric3 &other);
  SMetric3 transform(fullMatrix<double> &V);
  void eig(fullMatrix<double> &V, fullVector<double> &S, bool s = false) const;
  void print(const char *) const;
};

// scalar product with respect to the metric
inline double dot(const SVector3 &a, const SMetric3 &m, const SVector3 &b)
{
  return b.x() * (m(0, 0) * a.x() + m(1, 0) * a.y() + m(2, 0) * a.z()) +
         b.y() * (m(0, 1) * a.x() + m(1, 1) * a.y() + m(2, 1) * a.z()) +
         b.z() * (m(0, 2) * a.x() + m(1, 2) * a.y() + m(2, 2) * a.z());
}

// preserve orientation of m1
SMetric3 intersection_conserveM1(const SMetric3 &m1, const SMetric3 &m2);

// preserve orientation of the most anisotropic metric
SMetric3 intersection_conserve_mostaniso(const SMetric3 &m1,
                                         const SMetric3 &m2);
SMetric3 intersection_conserve_mostaniso_2d(const SMetric3 &m1,
                                            const SMetric3 &m2);
// compute the largest inscribed ellipsoid...
SMetric3 intersection(const SMetric3 &m1, const SMetric3 &m2);
SMetric3 intersection_alauzet(const SMetric3 &m1, const SMetric3 &m2);
SMetric3 interpolation(const SMetric3 &m1, const SMetric3 &m2, const double t);
SMetric3 interpolation(const SMetric3 &m1, const SMetric3 &m2,
                       const SMetric3 &m3, const double u, const double v);
SMetric3 interpolation(const SMetric3 &m1, const SMetric3 &m2,
                       const SMetric3 &m3, const SMetric3 &m4, const double u,
                       const double v, const double w);

// concrete class for general 3x3 matrix
class STensor3 {
protected:
  // 00 01 02 10 11 12 20 21 22
  double _val[9];

public:
  // default constructor, null tensor
  STensor3(const double v = 0.0)
  {
    _val[0] = _val[4] = _val[8] = v;
    _val[1] = _val[2] = _val[3] = 0.0;
    _val[5] = _val[6] = _val[7] = 0.0;
  }
  STensor3(const STensor3 &other)
  {
    for(int i = 0; i < 9; i++) _val[i] = other._val[i];
  }
  inline int getIndex(int i, int j) const
  {
    static int _index[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    return _index[i][j];
  }
  inline void set_m11(double x) { _val[0] = x; }
  inline void set_m21(double x) { _val[3] = x; }
  inline void set_m31(double x) { _val[6] = x; }
  inline void set_m12(double x) { _val[1] = x; }
  inline void set_m22(double x) { _val[4] = x; }
  inline void set_m32(double x) { _val[7] = x; }
  inline void set_m13(double x) { _val[2] = x; }
  inline void set_m23(double x) { _val[5] = x; }
  inline void set_m33(double x) { _val[8] = x; }
  inline double get_m11() { return _val[0]; }
  inline double get_m21() { return _val[3]; }
  inline double get_m31() { return _val[6]; }
  inline double get_m12() { return _val[1]; }
  inline double get_m22() { return _val[4]; }
  inline double get_m32() { return _val[7]; }
  inline double get_m13() { return _val[2]; }
  inline double get_m23() { return _val[5]; }
  inline double get_m33() { return _val[8]; }
  inline const double *data() const { return _val; }
  inline double *data() { return _val; }
  void getMat(fullMatrix<double> &mat) const;
  void setMat(const fullMatrix<double> &mat);
  inline double &operator()(int i, int j) { return _val[getIndex(i, j)]; }
  inline double operator()(int i, int j) const { return _val[getIndex(i, j)]; }
  inline double operator[](int i) const { return _val[i]; }
  inline double &operator[](int i) { return _val[i]; }
  STensor3 invert() const
  {
    double det = (*this).determinant();
    double udet = 0.;
    STensor3 ithis;
    if(det == 0.)
      Msg::Error("det=0 in STensor inversion");
    else
      udet = 1. / det;
    ithis(0, 0) =
      ((*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1)) * udet;
    ithis(1, 0) =
      -((*this)(1, 0) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 0)) * udet;
    ithis(2, 0) =
      ((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0)) * udet;
    ithis(0, 1) =
      -((*this)(0, 1) * (*this)(2, 2) - (*this)(0, 2) * (*this)(2, 1)) * udet;
    ithis(1, 1) =
      ((*this)(0, 0) * (*this)(2, 2) - (*this)(0, 2) * (*this)(2, 0)) * udet;
    ithis(2, 1) =
      -((*this)(0, 0) * (*this)(2, 1) - (*this)(0, 1) * (*this)(2, 0)) * udet;
    ithis(0, 2) =
      ((*this)(0, 1) * (*this)(1, 2) - (*this)(0, 2) * (*this)(1, 1)) * udet;
    ithis(1, 2) =
      -((*this)(0, 0) * (*this)(1, 2) - (*this)(0, 2) * (*this)(1, 0)) * udet;
    ithis(2, 2) =
      ((*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0)) * udet;
    return ithis;
  }
  STensor3 transpose() const
  {
    STensor3 ithis;
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++) ithis(i, j) = (*this)(j, i);
    return ithis;
  }
  STensor3 &operator=(const STensor3 &other)
  {
    for(int i = 0; i < 9; i++) _val[i] = other._val[i];
    return *this;
  }
  STensor3 operator+(const STensor3 &other) const
  {
    STensor3 res(*this);
    for(int i = 0; i < 9; i++) res._val[i] += other._val[i];
    return res;
  }
  STensor3 &operator+=(const STensor3 &other)
  {
    for(int i = 0; i < 9; i++) _val[i] += other._val[i];
    return *this;
  }
  STensor3 &operator*=(const double &other)
  {
    for(int i = 0; i < 9; i++) _val[i] *= other;
    return *this;
  }
  STensor3 &operator*=(const STensor3 &other)
  {
    double a00 = 0., a01 = 0., a02 = 0., a10 = 0., a11 = 0., a12 = 0., a20 = 0.,
           a21 = 0., a22 = 0.;
    for(int i = 0; i < 3; i++) {
      a00 += (*this)(0, i) * other(i, 0);
      a01 += (*this)(0, i) * other(i, 1);
      a02 += (*this)(0, i) * other(i, 2);
      a10 += (*this)(1, i) * other(i, 0);
      a11 += (*this)(1, i) * other(i, 1);
      a12 += (*this)(1, i) * other(i, 2);
      a20 += (*this)(2, i) * other(i, 0);
      a21 += (*this)(2, i) * other(i, 1);
      a22 += (*this)(2, i) * other(i, 2);
    }
    (*this)(0, 0) = a00;
    (*this)(0, 1) = a01;
    (*this)(0, 2) = a02;
    (*this)(1, 0) = a10;
    (*this)(1, 1) = a11;
    (*this)(1, 2) = a12;
    (*this)(2, 0) = a20;
    (*this)(2, 1) = a21;
    (*this)(2, 2) = a22;
    return *this;
  }
  void operator-=(const STensor3 &other)
  {
    for(int i = 0; i < 9; i++) _val[i] -= other._val[i];
  }
  void daxpy(const STensor3 &other, const double alpha = 1.)
  {
    if(alpha == 1.)
      for(int i = 0; i < 9; i++) _val[i] += other._val[i];
    else
      for(int i = 0; i < 9; i++) _val[i] += alpha * other._val[i];
  }
  double trace() const { return ((_val[0] + _val[4] + _val[8])); }
  double dotprod() const
  {
    double prod = 0;
    for(int i = 0; i < 9; i++) prod += _val[i] * _val[i];
    return prod;
  }

  double determinant() const
  {
    double det =
      ((*this)(0, 0) *
         ((*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1)) -
       (*this)(0, 1) *
         ((*this)(1, 0) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 0)) +
       (*this)(0, 2) *
         ((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0)));
    return det;
  };
  double norm0() const
  {
    double val = 0;
    for(int i = 0; i < 9; i++)
      if(fabs(_val[i]) > val) val = fabs(_val[i]);
    return val;
  };
  double norm2() const
  {
    double sqr = 0;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        sqr += this->operator()(i, j) * this->operator()(i, j);
      }
    }
    return sqrt(sqr);
  }
  STensor3 dev() const
  {
    double p = trace() / 3.;
    STensor3 de(*this);
    de(0, 0) -= p;
    de(1, 1) -= p;
    de(2, 2) -= p;
    return de;
  }
  void eig(fullMatrix<double> &V, fullVector<double> &S, bool s = false) const;
  void print(const char *) const;
};

// tensor product
inline void tensprod(const SVector3 &a, const SVector3 &b, STensor3 &c)
{
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) c(i, j) = a(i) * b(j);
}

inline double dot(const STensor3 &a, const STensor3 &b)
{
  double prod = 0;
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) prod += a(i, j) * b(i, j);
  return prod;
}

inline SVector3 operator*(const STensor3 &t, const SVector3 &v)
{
  SVector3 temp(0., 0., 0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) temp[i] += t(i, j) * v[j];
  return temp;
}

inline SVector3 operator*(const SVector3 &v, const STensor3 &t)
{
  SVector3 temp(0., 0., 0.);
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) temp[j] += v[i] * t(i, j);
  return temp;
}

inline STensor3 operator*(const STensor3 &t, double m)
{
  STensor3 val(t);
  val *= m;
  return val;
}

inline STensor3 operator*(double m, const STensor3 &t)
{
  STensor3 val(t);
  val *= m;
  return val;
}

#endif
