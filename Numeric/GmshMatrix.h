// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_MATRIX_H_
#define _GMSH_MATRIX_H_

#include <math.h>
#include "GmshMessage.h"

template <class SCALAR> class Gmsh_Matrix;

template <class SCALAR>
class Gmsh_Vector
{
 private:
  int _r;
  SCALAR *_data;
  friend class Gmsh_Matrix<SCALAR>;
 public:
  Gmsh_Vector(int r) : _r(r)
  {
    _data = new SCALAR[_r];
    scale(0.);
  }
  Gmsh_Vector(const Gmsh_Vector<SCALAR> &other) : _r(other._r)
  {
    _data = new SCALAR[_r];
    for(int i = 0; i < _r; ++i) _data[i] = other._data[i];
  }
  ~Gmsh_Vector() { if(_data) delete [] _data; }
  inline SCALAR operator () (int i) const
  {
    return _data[i];
  }
  inline int size() const { return _r; }
  inline SCALAR & operator () (int i)
  {
    return _data[i];
  }
  inline SCALAR norm()
  {
    SCALAR n = 0.;
    for(int i = 0; i < _r; ++i) n += _data[i] * _data[i];
    return sqrt(n);
  }
  inline void scale(const SCALAR s)
  {
    if(s == 0.) 
      for(int i = 0; i < _r; ++i) _data[i] = 0.;
    else 
      for(int i = 0; i < _r; ++i) _data[i] *= s;
  }
};

template <class SCALAR>
class Gmsh_Matrix
{
 private:
  int _r, _c;
  SCALAR *_data;
  void _back_substitution(int *indx, SCALAR *b)
  {
    int i, ii = -1, ip, j;
    SCALAR sum;
    for(i = 0; i < _c; i++){
      ip = indx[i];
      sum = b[ip];
      b[ip] = b[i];
      if(ii != -1)
	for(j = ii; j <= i - 1; j++) sum -= (*this)(i, j) * b[j];
      else if(sum) ii = i;
      b[i] = sum;
    }
    for(i = _c - 1; i >= 0; i--){
      sum = b[i];
      for(j = i + 1; j < _c; j++) sum -= (*this)(i, j) * b[j];
      b[i] = sum / (*this)(i, i);
    }
  }
  bool _lu_decomposition(int *indx, SCALAR &determinant)
  {
    if(_r != _c) 
      Msg::Fatal("Cannot LU factorize non-square matrix");
    int i, imax, j, k;
    SCALAR big, dum, sum, temp;
    SCALAR *vv = new SCALAR[_c];    
    determinant = 1.;
    for(i = 0; i < _c; i++){
      big = 0.;
      for(j = 0; j < _c; j++)
	if((temp = fabs((*this)(i, j))) > big) big = temp;
      if(big == 0.) {
        delete [] vv;
        Msg::Error("Zero pivot in LU factorization");
	return false;
      }      
      vv[i] = 1. / big;
    }
    for(j = 0; j < _c; j++){
      for(i = 0; i < j; i++){
	sum = (*this)(i, j);
	for(k = 0; k < i; k++) sum -= (*this)(i, k)*(*this)(k, j);
	(*this)(i, j) = sum;
      }
      big = 0.;
      for(i = j; i < _c; i++){
	sum = (*this)(i, j);
	for(k = 0; k < j; k++)
	  sum -= (*this)(i, k) * (*this)(k, j);
	(*this)(i, j) = sum;
	if((dum = vv[i] * fabs(sum)) >= big){
	  big = dum;
	  imax = i;
	}
      }
      if(j != imax){
	for(k = 0; k < _c; k++){
	  dum = (*this)(imax, k);
	  (*this)(imax, k) = (*this)(j, k);
	  (*this)(j, k) = dum;
	}
	determinant = -(determinant);
	vv[imax] = vv[j];
      }
      indx[j] = imax;
      if((*this)(j, j) == 0.) (*this)(j, j) = 1.e-20;
      if(j != _c){
	dum = 1. / ((*this)(j, j));
	for(i = j + 1; i < _c; i++) (*this)(i, j) *= dum;
      }
    }
    delete [] vv;
    return true;
  }
 public:
  Gmsh_Matrix(int r, int c) : _r(r), _c(c)
  {
    _data = new SCALAR[_r * _c];
    scale(0.);
  }
  Gmsh_Matrix(const Gmsh_Matrix<SCALAR> &other) : _r(other._r), _c(other._c)
  {
    _data = new SCALAR[_r * _c];
    memcpy(other);
  }
  Gmsh_Matrix() : _r(0), _c(0), _data(0) {}
  ~Gmsh_Matrix() { if(_data) delete [] _data; }
  inline int size1() const { return _r; }
  inline int size2() const { return _c; }
  Gmsh_Matrix<SCALAR> & operator=(const Gmsh_Matrix<SCALAR> &other)
  {
    if(this != &other){
      _r = other._r; 
      _c = other._c;
      _data = new SCALAR[_r * _c];
      memcpy(other);
    }
    return *this;
  }
  void memcpy(const Gmsh_Matrix<SCALAR> &other)
  {
    for(int i = 0; i < _r * _c; ++i) _data[i] = other._data[i];
  }
  inline SCALAR operator () (int i, int j) const
  {
    return _data[i + _r * j];
  }
  inline SCALAR & operator () (int i, int j)
  {
    return _data[i + _r * j];
  }
  inline void mult(const Gmsh_Matrix<SCALAR> &b, Gmsh_Matrix<SCALAR> &c)
  {
    c.scale(0.);
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < b.size2(); j++)
	for(int k = 0; k < _c; k++)
	  c._data[i + _r * j] += (*this)(i, k) * b(k, j);
  }
  inline void blas_dgemm(const Gmsh_Matrix<SCALAR> &b, Gmsh_Matrix<SCALAR> &c, 
			 const SCALAR alpha=1., const SCALAR beta=1.)
  {
    Gmsh_Matrix<SCALAR> temp(b.size1(), c.size2());
    temp.mult(b, c);
    scale(beta);
    temp.scale(alpha);
    add(temp);
  }
  inline void set_all(const SCALAR &m) 
  {
    for(int i = 0; i < _r * _c; i++) _data[i] = m;
  }
  inline bool lu_solve(const Gmsh_Vector<SCALAR> &rhs, Gmsh_Vector<SCALAR> &result)
  {
    int *indx = new int[_c];
    SCALAR d;
    if(!_lu_decomposition(indx, d)){
      delete [] indx;
      return false;
    }
    for(int i = 0; i < _c; i++) result(i) = rhs(i);
    _back_substitution(indx, result._data);
    delete [] indx; 
    return true;
  }
  inline bool invert()
  {
    Gmsh_Matrix y(_r, _c);
    SCALAR *col = new SCALAR[_c];
    int *indx = new int[_c];
    SCALAR d;
    if (!_lu_decomposition(indx, d)){
      delete [] col;
      delete [] indx;
      return false;
    }
    for(int j = 0; j < _c; j++){
      for(int i = 0; i < _c; i++) col[i] = 0.0;
      col[j] = 1.0;
      _back_substitution(indx, col);
      for(int i = 0; i < _c; i++) y(i, j) = col[i];
    }
    (*this) = y;
    delete [] col;
    delete [] indx;
    return true;
  }
  Gmsh_Matrix<SCALAR> cofactor(int i, int j) const 
  {
    int ni = size1();
    int nj = size2();
    Gmsh_Matrix<SCALAR> cof(ni - 1, nj - 1);
    for(int I = 0; I < ni; I++){
      for(int J = 0; J < nj; J++){
	if(J != j && I != i)
	  cof(I < i ? I : I - 1, J < j ? J : J - 1) = (*this)(I, J);
      }
    }
    return cof;
  }
  inline void mult(const Gmsh_Vector<SCALAR> &x, Gmsh_Vector<SCALAR> &y)
  {
    y.scale(0.);
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++)
	y._data[i] += (*this)(i, j) * x(j);
  }
  SCALAR determinant() const
  {
    Gmsh_Matrix<SCALAR> copy = *this;
    SCALAR factor = 1.;
    int *indx = new int[_c];
    if(!copy._lu_decomposition(indx, factor)) return 0.;
    SCALAR det = factor;
    for(int i = 0; i < _c; i++) det *= copy(i, i);
    delete [] indx;
    return det;
  }
  inline Gmsh_Matrix<SCALAR> submatrix(int i0, int ni, int j0, int nj)  const
  {
    Msg::Fatal("submatrix not implemented yet for Gmsh_Matrix");
    Gmsh_Matrix<SCALAR> subm(ni, nj);
    return subm;
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
  inline void add(const Gmsh_Matrix<SCALAR> &m) 
  {
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
	(*this)(i, j) += m(i, j);
  }
};

#if defined(HAVE_GSL)

#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>

class GSL_Matrix;

class GSL_Vector
{
 private:
  int _r;
  gsl_vector *_data;
  friend class GSL_Matrix;
 public:
  GSL_Vector(int r) : _r(r)
  {
    _data = gsl_vector_calloc(_r);
  }
  GSL_Vector(const GSL_Vector &other) : _r(other._r)
  {
    _data = gsl_vector_calloc(_r);
    gsl_vector_memcpy(_data, other._data);
  }
  ~GSL_Vector() { gsl_vector_free(_data); }
  inline int size() const { return _r; }
  inline double operator () (int i) const
  {
    return gsl_vector_get(_data, i);
  }
  inline double & operator () (int i)
  {
    return *gsl_vector_ptr(_data, i);
  }
  inline double norm()
  {
    return gsl_blas_dnrm2(_data);
  }
  inline void scale(const double s)
  {
    if(s == 0.) gsl_vector_set_zero(_data);
    else gsl_vector_scale(_data, s);
  }
};

class GSL_Matrix
{
 private:
  gsl_matrix_view _view;
  gsl_matrix *_data;
 public:
  GSL_Matrix(int r, int  c) { _data = gsl_matrix_calloc(r, c); }
  GSL_Matrix(const GSL_Matrix &other) : _data(0)
  {
    if(_data) gsl_matrix_free(_data);
    _data = gsl_matrix_calloc(other._data->size1, other._data->size2);
    gsl_matrix_memcpy(_data, other._data);
  }
  GSL_Matrix(gsl_matrix_view view) : _view(view), _data(&_view.matrix) {}
  GSL_Matrix() : _data(0) {}
  ~GSL_Matrix() { if(_data && _data->owner == 1) gsl_matrix_free(_data); }
  inline int size1() const { return _data->size1; }
  inline int size2() const { return _data->size2; }
  GSL_Matrix & operator = (const GSL_Matrix&other)
  {
    if(&other != this){
      if(_data) gsl_matrix_free(_data);
      _data = gsl_matrix_calloc(other._data->size1, other._data->size2);
      gsl_matrix_memcpy(_data, other._data);
    }
    return *this;
  }
  void memcpy(const GSL_Matrix &other)
  {
    gsl_matrix_memcpy(_data, other._data);
  }
  inline double operator () (int i, int j) const
  {
    return gsl_matrix_get(_data, i, j);
  }
  inline double & operator () (int i, int j)
  {
    return *gsl_matrix_ptr(_data, i, j);
  }
  inline void mult(const GSL_Matrix &b, GSL_Matrix &c)
  {
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1., _data, b._data, 0., c._data);
  }
  inline void blas_dgemm(const GSL_Matrix &x, GSL_Matrix &b, 
			 const double alpha=1., const double beta=1.)
  {      
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, alpha, x._data, b._data, beta, _data);
  }
  inline void set_all(const double &m) 
  {
    gsl_matrix_set_all(_data, m);
  }
  inline bool lu_solve(const GSL_Vector &rhs, GSL_Vector &result)
  {
    int s;
    gsl_permutation * p = gsl_permutation_alloc(size1());
    gsl_linalg_LU_decomp(_data, p, &s);
    gsl_linalg_LU_solve(_data, p, rhs._data, result._data);
    gsl_permutation_free(p);
    return true;
  }
  inline bool invert()
  {
    int s;
    gsl_permutation *p = gsl_permutation_alloc(size1());
    gsl_linalg_LU_decomp(_data, p, &s);
    gsl_matrix *inv = gsl_matrix_calloc(size1(), size2());
    gsl_linalg_LU_invert(_data, p, inv) ;
    gsl_matrix_memcpy(_data, inv);
    gsl_matrix_free(inv);
    gsl_permutation_free(p);
    return true;
  }
  GSL_Matrix cofactor(int i, int j) const 
  {
    int ni = size1();
    int nj = size2();
    GSL_Matrix cof(ni - 1, nj - 1);
    if(i > 0) {
      if(j > 0)
        cof.submatrix(0, i, 0, j).
          memcpy(submatrix(0, i, 0, j));
      if(j < nj - 1)
        cof.submatrix(0, i, j, nj - j - 1).
          memcpy(submatrix(0, i, j + 1, nj - j - 1));
    }
    if(i < ni - 1) {  
      if(j < nj - 1)
        cof.submatrix(i, ni - i - 1, j, nj - j - 1).
          memcpy(submatrix(i + 1, ni - i - 1, j + 1, nj - j - 1));
      if(j > 0)
        cof.submatrix(i, ni - i - 1, 0, j).
          memcpy(submatrix(i + 1, ni - i - 1, 0, j));
    }
    return cof;
  }
  inline void mult(const GSL_Vector &x, GSL_Vector &b)
  {
    gsl_blas_dgemv(CblasNoTrans, 1., _data, x._data, 0., b._data);
  }
  double determinant() const 
  {
    GSL_Matrix copy = *this;
    gsl_permutation *p = gsl_permutation_alloc(size1());
    int s;
    gsl_linalg_LU_decomp(copy._data, p, &s);
    gsl_permutation_free(p);
    return gsl_linalg_LU_det(copy._data, s);
  } 
  inline GSL_Matrix submatrix(int i0, int ni, int j0, int nj) const
  {
    return GSL_Matrix(gsl_matrix_submatrix(_data, i0, j0, ni, nj));
  }  
  inline void scale(const double s) 
  {
    if(s == 0.) gsl_matrix_set_zero(_data);
    else gsl_matrix_scale(_data, s);
  }
  inline void add(const double &a) 
  {
    gsl_matrix_add_constant(_data, a);
  }
  inline void add(const GSL_Matrix &m) 
  {
    gsl_matrix_add(_data, m._data);
  }
};

typedef GSL_Matrix Double_Matrix;
typedef GSL_Vector Double_Vector;

#else

typedef Gmsh_Matrix<double> Double_Matrix;
typedef Gmsh_Vector<double> Double_Vector;

#endif

#endif
