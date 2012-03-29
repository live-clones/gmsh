// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _STENSOR3_H_
#define _STENSOR3_H_

#include "SVector3.h"
#include "fullMatrix.h"
#include "Numeric.h"

// concrete class for symmetric positive definite 3x3 matrix
class SMetric3 {
 protected:
  // lower diagonal storage
  // 00 10 11 20 21 22
  double _val[6];
 public:
  inline int getIndex(int i, int j) const
  {
    static int _index[3][3] = {{0,1,3},{1,2,4},{3,4,5}};
    return _index[i][j];
  }
  void getMat(fullMatrix<double> &mat) const
  {
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        mat(i,j) = _val[getIndex(i, j)];
      }
    }
  }
  void setMat(const fullMatrix<double> & mat)
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        _val[getIndex(i, j)] = mat(i, j);
  }
  SMetric3(const SMetric3& m)
  {
    for (int i = 0; i < 6; i++) _val[i] = m._val[i];
  }
  // default constructor, identity
  SMetric3(const double v = 1.0)
  {
    _val[0] = _val[2] = _val[5] = v;
    _val[1] = _val[3] = _val[4] = 0.0;
  }
  SMetric3(const double l1, // l1 = h1^-2
           const double l2,
           const double l3,
           const SVector3 &t1,
           const SVector3 &t2,
           const SVector3 &t3)
  {
    // M = e^1 * diag * e^1^t
    // where the elements of diag are l_i = h_i^-2
    // and the rows of e are the UNIT and ORTHOGONAL directions

    fullMatrix<double> e(3,3);
    e(0,0) = t1(0); e(0,1) = t1(1); e(0,2) = t1(2);
    e(1,0) = t2(0); e(1,1) = t2(1); e(1,2) = t2(2);
    e(2,0) = t3(0); e(2,1) = t3(1); e(2,2) = t3(2);
    e.transposeInPlace();
    //      e.invertInPlace();

    fullMatrix<double> tmp(3,3);
    tmp(0,0) = l1 * e(0,0);
    tmp(0,1) = l2 * e(0,1);
    tmp(0,2) = l3 * e(0,2);
    tmp(1,0) = l1 * e(1,0);
    tmp(1,1) = l2 * e(1,1);
    tmp(1,2) = l3 * e(1,2);
    tmp(2,0) = l1 * e(2,0);
    tmp(2,1) = l2 * e(2,1);
    tmp(2,2) = l3 * e(2,2);

    e.transposeInPlace();

    _val[0] = tmp(0,0) * e(0,0) + tmp(0,1) * e(1,0) + tmp(0,2) * e(2,0);
    _val[1] = tmp(1,0) * e(0,0) + tmp(1,1) * e(1,0) + tmp(1,2) * e(2,0);
    _val[2] = tmp(1,0) * e(0,1) + tmp(1,1) * e(1,1) + tmp(1,2) * e(2,1);
    _val[3] = tmp(2,0) * e(0,0) + tmp(2,1) * e(1,0) + tmp(2,2) * e(2,0);
    _val[4] = tmp(2,0) * e(0,1) + tmp(2,1) * e(1,1) + tmp(2,2) * e(2,1);
    _val[5] = tmp(2,0) * e(0,2) + tmp(2,1) * e(1,2) + tmp(2,2) * e(2,2);
  }
  inline double &operator()(int i, int j)
  {
    return _val[getIndex(i, j)];
  }
  inline double operator()(int i, int j) const
  {
    return _val[getIndex(i, j)];
  }
  SMetric3 invert() const
  {
    fullMatrix<double> m(3, 3);
    getMat(m);
    m.invertInPlace();
    SMetric3 ithis;
    ithis.setMat(m);
    return ithis;
  }
  double determinant() const
  {
    fullMatrix<double> m(3,3);
    getMat(m);
    double det = m.determinant();
    return det;
  }
  SMetric3 operator + (const SMetric3 &other) const
  {
    SMetric3 res(*this);
    for (int i = 0; i < 6; i++) res._val[i] += other._val[i];
    return res;
  }
  SMetric3& operator += (const SMetric3 &other)
  {
    for (int i = 0; i < 6; i++) _val[i] += other._val[i];
    return *this;
  }
  SMetric3& operator *= (const double &other)
  {
    for (int i = 0; i < 6; i++) _val[i] *= other;
    return *this;
  }
  SMetric3& operator *= (const SMetric3 &other)
  {
    fullMatrix<double> m1(3, 3), m2(3, 3), m3(3, 3);
    getMat(m1);
    other.getMat(m2);
    m1.mult(m2, m3);
    setMat(m3);
    return *this;
  }
  SMetric3 transform(fullMatrix<double> &V)
  {
    fullMatrix<double> m(3,3);
    getMat(m);
    fullMatrix<double> result(3,3),temp(3,3);
    V.transpose().mult(m,temp);
    temp.mult(V,result);
    SMetric3 a; a.setMat(result);
    return a;
  }
  // s: true if eigenvalues are sorted (from min to max of the REAL part)
  void eig(fullMatrix<double> &V, fullVector<double> &S, bool s=false) const
  {
    fullMatrix<double> me(3, 3), right(3, 3);
    fullVector<double> im(3);
    getMat(me);
    me.eig(S, im, V, right, s);
  }
  void print(const char *) const;
};

// scalar product with respect to the metric
inline double dot(const SVector3 &a, const SMetric3 &m, const SVector3 &b)
{
  return
    b.x() * ( m(0,0) * a.x() + m(1,0) * a.y() + m(2,0) * a.z() ) +
    b.y() * ( m(0,1) * a.x() + m(1,1) * a.y() + m(2,1) * a.z() ) +
    b.z() * ( m(0,2) * a.x() + m(1,2) * a.y() + m(2,2) * a.z() ) ;
}

// preserve orientation of m1
SMetric3 intersection_conserveM1 (const SMetric3 &m1,
				  const SMetric3 &m2);
// preserve orientation of the most anisotropic metric
SMetric3 intersection_conserve_mostaniso (const SMetric3 &m1, const SMetric3 &m2);
// compute the largest inscribed ellipsoid...
SMetric3 intersection (const SMetric3 &m1,
                       const SMetric3 &m2);
SMetric3 interpolation (const SMetric3 &m1,
                        const SMetric3 &m2,
                        const double t);
SMetric3 interpolation (const SMetric3 &m1,
                        const SMetric3 &m2,
                        const SMetric3 &m3,
                        const double u,
                        const double v);
SMetric3 interpolation (const SMetric3 &m1,
                        const SMetric3 &m2,
                        const SMetric3 &m3,
                        const SMetric3 &m4,
                        const double u,
                        const double v,
                        const double w);

// concrete class for general 3x3 matrix
class STensor3 {
 protected:
  // 00 01 02 10 11 12 20 21 22
  double _val[9];
 public:
  inline int getIndex(int i, int j) const
  {
    static int _index[3][3] = {{0,1,2},{3,4,5},{6,7,8}};
    return _index[i][j];
  }
  void getMat(fullMatrix<double> &mat) const
  {
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        mat(i,j) = _val[getIndex(i, j)];
      }
    }
  }
  void setMat (const fullMatrix<double> & mat)
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        _val[getIndex(i, j)] = mat(i, j);
  }
  STensor3(const STensor3& other)
  {
    for (int i = 0; i < 9; i++) _val[i] = other._val[i];
  }
  // default constructor, null tensor
  STensor3(const double v = 0.0)
  {
    _val[0] = _val[4] = _val[8] = v;
    _val[1] = _val[2] = _val[3] = 0.0;
    _val[5] = _val[6] = _val[7] = 0.0;
  }
  inline double &operator()(int i, int j)
  {
    return _val[getIndex(i, j)];
  }
  inline double operator()(int i, int j) const
  {
    return _val[getIndex(i, j)];
  }
  inline double operator[](int i) const
  {
    return _val[i];
  }
  inline double &operator[](int i)
  {
    return _val[i];
  }
  STensor3 invert() const
  {
    fullMatrix<double> m(3, 3);
    getMat(m);
    m.invertInPlace();
    STensor3 ithis;
    ithis.setMat(m);
    return ithis;
  }
  STensor3 transpose () const
  {
    STensor3 ithis;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        ithis(i,j) = (*this)(j,i);
    return ithis;
  }

  STensor3 operator + (const STensor3 &other) const
  {
    STensor3 res(*this);
    for (int i = 0; i < 9; i++) res._val[i] += other._val[i];
    return res;
  }
  STensor3& operator += (const STensor3 &other)
  {
    for (int i = 0; i < 9; i++) _val[i] += other._val[i];
    return *this;
  }
  STensor3& operator *= (const double &other)
  {
    for (int i = 0; i < 9; i++) _val[i] *= other;
    return *this;
  }
  STensor3& operator *= (const STensor3 &other)
  {
    fullMatrix<double> m1(3, 3), m2(3, 3), m3(3, 3);
    getMat(m1);
    other.getMat(m2);
    m1.mult(m2, m3);
    setMat(m3);
    return *this;
  }
  void operator-= (const STensor3 &other)
  {
    for(int i=0;i<9;i++) _val[i]-=other._val[i];
  }
  void daxpy(const STensor3 &other, const double alpha=1.)
  {
    if(alpha==1.)
      for(int i=0;i<9;i++) _val[i]+=other._val[i];
    else
      for(int i=0;i<9;i++) _val[i]+=alpha*other._val[i];
  }
  double trace() const
  {
    return ((_val[0]+_val[4]+_val[8]));
  }

  double dotprod() const
  {
    double prod=0;
    for(int i=0;i<9;i++) prod+=_val[i]*_val[i];
    return prod;
  }

  void print(const char *) const;
};

// tensor product
inline void tensprod(const SVector3 &a, const SVector3 &b, STensor3 &c)
{
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        c(i,j)=a(i)*b(j);
}


inline double dot(const STensor3 &a, const STensor3 &b)
{
  double prod=0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      prod+=a(i,j)*b(i,j);
  return prod;
}

inline SVector3 operator* (const STensor3& t, const SVector3& v){
  SVector3 temp(0.,0.,0.);
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      temp[i]+= t(i,j)*v[j];
  return temp;
};

inline SVector3 operator* (const SVector3& v, const STensor3& t){
  SVector3 temp(0.,0.,0.);
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      temp[j]+= v[i]*t(i,j);
  return temp;
};


inline STensor3 operator*(const STensor3 &t, double m)
{
  STensor3 val(t);
  val *= m;
  return val;
}

inline STensor3 operator*(double m,const STensor3 &t)
{
  STensor3 val(t);
  val *= m;
  return val;
}

#endif
