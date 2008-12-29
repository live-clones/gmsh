// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_MATRIX_H_
#define _GMSH_MATRIX_H_

#include <math.h>
#include <algorithm>
#include "GmshMessage.h"

#if defined(HAVE_BLAS)
extern "C" {
  void dgemm_(const char *transa, const char *transb, int *m, int *n, int *k, 
              double *alpha, double *a, int *lda, double *b, int *ldb, 
              double *beta, double *c, int *ldc);
  void dgemv_(const char *trans, int *m, int *n, double *alpha, double *a, 
              int *lda, double *x, int *incx, double *beta, double *y, int *incy);
}
#endif

#if defined(HAVE_LAPACK)
extern "C" {
  void dgesv_(int *N, int *nrhs, double *A, int *lda, int *ipiv, 
              double *b, int *ldb, int *info);
  void dgetrf_(int *M, int *N, double *A, int *lda, int *ipiv, int *info);
  void dgesvd_(const char* jobu, const char *jobvt, int *M, int *N,
               double *A, int *lda, double *S, double* U, int *ldu,
               double *VT, int *ldvt, double *work, int *lwork, int *info);
}
#endif

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
  Gmsh_Matrix<SCALAR> & operator = (const Gmsh_Matrix<SCALAR> &other)
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
  void copy(const Gmsh_Matrix<SCALAR> &a, int i0, int ni, int j0, int nj, 
            int desti0, int destj0)
  {
    for(int i = i0, desti = desti0; i < i0 + ni; i++, desti++)
      for(int j = j0, destj = destj0; j < j0 + nj; j++, destj++)
        (*this)(desti, destj) = a(i, j);
  }
  inline void mult(const Gmsh_Matrix<SCALAR> &b, Gmsh_Matrix<SCALAR> &c)
  {
#if defined(HAVE_BLAS)
    int M = c.size1(), N = c.size2(), K = _c;
    int LDA = _r, LDB = b.size1(), LDC = c.size1();
    double alpha = 1., beta = 0.;
    dgemm_("N", "N", &M, &N, &K, &alpha, _data, &LDA, b._data, &LDB, 
           &beta, c._data, &LDC);
#else
    c.scale(0.);
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < b.size2(); j++)
	for(int k = 0; k < _c; k++)
	  c._data[i + _r * j] += (*this)(i, k) * b(k, j);
#endif
  }
  inline void blas_dgemm(Gmsh_Matrix<SCALAR> &a, Gmsh_Matrix<SCALAR> &b, 
			 SCALAR alpha=1., SCALAR beta=1.)
  {
#if defined(HAVE_BLAS)
    int M = size1(), N = size2(), K = a.size2();
    int LDA = a.size1(), LDB = b.size1(), LDC = size1();
    dgemm_("N", "N", &M, &N, &K, &alpha, a._data, &LDA, b._data, &LDB, 
           &beta, _data, &LDC);
#else
    Gmsh_Matrix<SCALAR> temp(a.size1(), b.size2());
    a.mult(b, temp);
    temp.scale(alpha);
    scale(beta);
    add(temp);
#endif
  }
  inline void set_all(const SCALAR &m) 
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
  inline void add(const Gmsh_Matrix<SCALAR> &m) 
  {
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
	(*this)(i, j) += m(i, j);
  }
  inline void mult(const Gmsh_Vector<SCALAR> &x, Gmsh_Vector<SCALAR> &y)
  {
#if defined(HAVE_BLAS)
    int M = _r, N = _c, LDA = _r, INCX = 1, INCY = 1;
    double alpha = 1., beta = 0.;
    dgemv_("N", &M, &N, &alpha, _data, &LDA, x._data, &INCX,
           &beta, y._data, &INCY);
#else
    y.scale(0.);
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++)
	y._data[i] += (*this)(i, j) * x(j);
#endif
  }
  inline Gmsh_Matrix<SCALAR> transpose()
  {
    Gmsh_Matrix<SCALAR> T(size2(), size1());
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
        T(j, i) = (*this)(i, j);
    return T;
  }
  inline bool lu_solve(const Gmsh_Vector<SCALAR> &rhs, Gmsh_Vector<SCALAR> &result)
  {
#if defined(HAVE_LAPACK)
    int N = size1(), nrhs = 1, lda = N, ldb = N, info;
    int *ipiv = new int[N];
    for(int i = 0; i < N; i++) result(i) = rhs(i);
    dgesv_(&N, &nrhs, _data, &lda, ipiv, result._data, &ldb, &info);
    delete [] ipiv;
    if(info == 0) return true;
    Msg::Error("Problem in LAPACK LU (info=%d)", info);
#else
    Msg::Error("LU factorization requires LAPACK");
#endif
    return false;
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
  SCALAR determinant() const
  {
#if defined(HAVE_LAPACK)
    Gmsh_Matrix<SCALAR> tmp(*this);
    int M = size1(), N = size2(), lda = size1(), info;
    int *ipiv = new int[std::min(M, N)];
    dgetrf_(&M, &N, tmp._data, &lda, ipiv, &info);
    SCALAR det = 1.;
    for(int i = 0; i < size1(); i++){
      det *= tmp(i, i);
      if(ipiv[i] != i + 1) det = -det;
    }
    return det;
#else
    Msg::Error("Determinant computation requires LAPACK");
    return 0.;
#endif
  }
  bool svd(Gmsh_Matrix<SCALAR> &V, Gmsh_Vector<SCALAR> &S)
  {
#if defined(HAVE_LAPACK)
    Gmsh_Matrix<SCALAR> VT(V.size2(), V.size1());
    int M = size1(), N = size2(), LDA = size1(), LDVT = VT.size1(), info;
    int LWORK = std::max(3 * std::min(M, N) + std::max(M, N), 5 * std::min(M, N));
    Gmsh_Vector<SCALAR> WORK(LWORK);
    dgesvd_("O", "A", &M, &N, _data, &LDA, S._data, _data, &LDA,
            VT._data, &LDVT, WORK._data, &LWORK, &info);
    V = VT.transpose();
    if(info == 0) return true;
    Msg::Error("Problem in LAPACK SVD (info=%d)", info);
#else
    Msg::Error("Singular value decomposition requires LAPACK");
#endif
    return false;
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
  gsl_matrix *_data;
 public:
  GSL_Matrix(int r, int  c) { _data = gsl_matrix_calloc(r, c); }
  GSL_Matrix(const GSL_Matrix &other) : _data(0)
  {
    if(_data) gsl_matrix_free(_data);
    _data = gsl_matrix_calloc(other._data->size1, other._data->size2);
    gsl_matrix_memcpy(_data, other._data);
  }
  GSL_Matrix() : _data(0) {}
  ~GSL_Matrix() { if(_data && _data->owner == 1) gsl_matrix_free(_data); }
  inline int size1() const { return _data->size1; }
  inline int size2() const { return _data->size2; }
  GSL_Matrix & operator = (const GSL_Matrix &other)
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
  void copy(const GSL_Matrix &a, int i0, int ni, int j0, int nj, 
            int desti0, int destj0)
  {
    for(int i = i0, desti = desti0; i < i0 + ni; i++, desti++)
      for(int j = j0, destj = destj0; j < j0 + nj; j++, destj++)
        (*this)(desti, destj) = a(i, j);
  }
  inline void mult(const GSL_Matrix &b, GSL_Matrix &c)
  {
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1., _data, b._data, 0., c._data);
  }
  inline void blas_dgemm(GSL_Matrix &a, GSL_Matrix &b, 
			 double alpha=1., double beta=1.)
  {      
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, alpha, a._data, b._data, beta, _data);
  }
  inline void set_all(const double &m) 
  {
    gsl_matrix_set_all(_data, m);
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
  inline void mult(const GSL_Vector &x, GSL_Vector &y)
  {
    gsl_blas_dgemv(CblasNoTrans, 1., _data, x._data, 0., y._data);
  }
  inline GSL_Matrix transpose()
  {
    GSL_Matrix T(size2(), size1());
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
        T(j, i) = (*this)(i, j);
    return T;
  }
  inline bool lu_solve(const GSL_Vector &rhs, GSL_Vector &result)
  {
    int s;
    gsl_permutation *p = gsl_permutation_alloc(size1());
    gsl_linalg_LU_decomp(_data, p, &s);
    gsl_linalg_LU_solve(_data, p, rhs._data, result._data);
    gsl_permutation_free(p);
    return true;
  }
  GSL_Matrix cofactor(int i, int j) const 
  {
    int ni = size1();
    int nj = size2();
    GSL_Matrix cof(ni - 1, nj - 1);
    for(int I = 0; I < ni; I++){
      for(int J = 0; J < nj; J++){
	if(J != j && I != i)
	  cof(I < i ? I : I - 1, J < j ? J : J - 1) = (*this)(I, J);
      }
    }
    return cof;
  }
  double determinant() const 
  {
    GSL_Matrix tmp = *this;
    gsl_permutation *p = gsl_permutation_alloc(size1());
    int s;
    gsl_linalg_LU_decomp(tmp._data, p, &s);
    gsl_permutation_free(p);
    return gsl_linalg_LU_det(tmp._data, s);
  } 
  bool svd(GSL_Matrix &V, GSL_Vector &S)
  {
    GSL_Vector tmp(S.size());
    gsl_linalg_SV_decomp(_data, V._data, S._data, tmp._data);
    return true;
  }
};

typedef GSL_Matrix Double_Matrix;
typedef GSL_Vector Double_Vector;

#else

typedef Gmsh_Matrix<double> Double_Matrix;
typedef Gmsh_Vector<double> Double_Vector;

#endif

#endif
