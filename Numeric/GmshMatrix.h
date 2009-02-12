// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_MATRIX_H_
#define _GMSH_MATRIX_H_

#include <math.h>
#include "GmshConfig.h"
#include "GmshMessage.h"

template <class scalar> class gmshMatrix;

template <class scalar>
class gmshVector
{
 private:
  int _r;
  scalar *_data;
  friend class gmshMatrix<scalar>;
 public:
  gmshVector(int r) : _r(r)
  {
    _data = new scalar[_r];
    scale(0.);
  }
  gmshVector(const gmshVector<scalar> &other) : _r(other._r)
  {
    _data = new scalar[_r];
    for(int i = 0; i < _r; ++i) _data[i] = other._data[i];
  }
  ~gmshVector() { if(_data) delete [] _data; }
  inline scalar operator () (int i) const
  {
    return _data[i];
  }
  inline int size() const { return _r; }
  inline scalar & operator () (int i)
  {
    return _data[i];
  }
  inline scalar norm()
  {
    scalar n = 0.;
    for(int i = 0; i < _r; ++i) n += _data[i] * _data[i];
    return sqrt(n);
  }
  inline void scale(const scalar s)
  {
    if(s == 0.) 
      for(int i = 0; i < _r; ++i) _data[i] = 0.;
    else 
      for(int i = 0; i < _r; ++i) _data[i] *= s;
  }
};

template <class scalar>
class gmshMatrix
{
 private:
  int _r, _c;
  scalar *_data;
 public:
  gmshMatrix(int r, int c) : _r(r), _c(c)
  {
    _data = new scalar[_r * _c];
    scale(0.);
  }
  gmshMatrix(const gmshMatrix<scalar> &other) : _r(other._r), _c(other._c)
  {
    _data = new scalar[_r * _c];
    memcpy(other);
  }
  gmshMatrix() : _r(0), _c(0), _data(0) {}
  ~gmshMatrix() { if(_data) delete [] _data; }
  inline int size1() const { return _r; }
  inline int size2() const { return _c; }
  gmshMatrix<scalar> & operator = (const gmshMatrix<scalar> &other)
  {
    if(this != &other){
      _r = other._r; 
      _c = other._c;
      _data = new scalar[_r * _c];
      memcpy(other);
    }
    return *this;
  }
  void memcpy(const gmshMatrix<scalar> &other)
  {
    for(int i = 0; i < _r * _c; ++i) _data[i] = other._data[i];
  }
  inline scalar operator () (int i, int j) const
  {
    return _data[i + _r * j];
  }
  inline scalar & operator () (int i, int j)
  {
    return _data[i + _r * j];
  }
  void copy(const gmshMatrix<scalar> &a, int i0, int ni, int j0, int nj, 
            int desti0, int destj0)
  {
    for(int i = i0, desti = desti0; i < i0 + ni; i++, desti++)
      for(int j = j0, destj = destj0; j < j0 + nj; j++, destj++)
        (*this)(desti, destj) = a(i, j);
  }
  void mult(const gmshMatrix<scalar> &b, gmshMatrix<scalar> &c)
#if !defined(HAVE_BLAS)
  {
    c.scale(0.);
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < b.size2(); j++)
        for(int k = 0; k < _c; k++)
          c._data[i + _r * j] += (*this)(i, k) * b(k, j);
  }
#endif
  ;
  void gemm(gmshMatrix<scalar> &a, gmshMatrix<scalar> &b, 
            scalar alpha=1., scalar beta=1.)
#if !defined(HAVE_BLAS)
  {
    gmshMatrix<scalar> temp(a.size1(), b.size2());
    a.mult(b, temp);
    temp.scale(alpha);
    scale(beta);
    add(temp);
  }
#endif
  ;
  inline void set_all(const scalar &m) 
  {
    for(int i = 0; i < _r * _c; i++) _data[i] = m;
  }
  inline void scale(const double s)
  {
    if(s == 0.)
      for(int i = 0; i < _r * _c; ++i) _data[i] = 0.;
    else
      for(int i = 0; i < _r * _c; ++i) _data[i] *= s;
  }
  inline void add(const double &a) 
  {
    for(int i = 0; i < _r * _c; ++i) _data[i] += a;
  }
  inline void add(const gmshMatrix<scalar> &m) 
  {
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
	(*this)(i, j) += m(i, j);
  }
  void mult(const gmshVector<scalar> &x, gmshVector<scalar> &y)
#if !defined(HAVE_BLAS)
  {
    y.scale(0.);
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++)
        y._data[i] += (*this)(i, j) * x(j);
  }
#endif
  ;
  inline gmshMatrix<scalar> transpose()
  {
    gmshMatrix<scalar> T(size2(), size1());
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
        T(j, i) = (*this)(i, j);
    return T;
  }
  bool lu_solve(const gmshVector<scalar> &rhs, gmshVector<scalar> &result)
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("LU factorization requires LAPACK");
    return false;
  }
#endif
  ;
  gmshMatrix<scalar> cofactor(int i, int j) const 
  {
    int ni = size1();
    int nj = size2();
    gmshMatrix<scalar> cof(ni - 1, nj - 1);
    for(int I = 0; I < ni; I++){
      for(int J = 0; J < nj; J++){
	if(J != j && I != i)
	  cof(I < i ? I : I - 1, J < j ? J : J - 1) = (*this)(I, J);
      }
    }
    return cof;
  }
  scalar determinant() const
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("Determinant computation requires LAPACK");
    return 0.;
  }
#endif
  ;
  bool svd(gmshMatrix<scalar> &V, gmshVector<scalar> &S)
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("Singular value decomposition requires LAPACK");
    return false;
  }
#endif
  ;
};

#endif
