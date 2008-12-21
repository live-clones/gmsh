// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_MATRIX_H_
#define _GMSH_MATRIX_H_

#include <math.h>
#include "GmshMessage.h"

template <class SCALAR>
class Gmsh_Vector
{
 private:
  int r;
  SCALAR *data;
  friend class Gmsh_Matrix;
 public:
  inline int size() const { return r; }
  Gmsh_Vector(int R) : r(R)
  {
    data = new SCALAR[r];
    scale(0.);
  }
  Gmsh_Vector(const Gmsh_Vector<SCALAR> &other) : r(other.r)
  {
    data = new SCALAR[r];
    for(int i = 0; i < r; ++i) data[i] = other.data[i];
  }
  ~Gmsh_Vector() { delete [] data; }
  inline SCALAR operator () (int i) const
  {
    return data[i];
  }
  inline SCALAR & operator () (int i)
  {
    return data[i];
  }
  inline SCALAR norm()
  {
    SCALAR n = 0.;
    for(int i = 0; i < r; ++i) n += data[i] * data[i];
    return sqrt(n);
  }
  inline void scale(const SCALAR s)
  {
    if(s == 0.) 
      for(int i = 0; i < r; ++i) data[i] = 0.;
    else 
      for(int i = 0; i < r; ++i) data[i] *= s;
  }
};

template <class SCALAR>
class Gmsh_Matrix
{
 private:
  int r, c;
  SCALAR *data;
  void _back_substitution(int *indx, SCALAR *b)
  {
    int i, ii = -1, ip, j;
    SCALAR sum;
    for(i = 0; i < c; i++){
      ip = indx[i];
      sum = b[ip];
      b[ip] = b[i];
      if(ii != -1)
	for(j = ii; j <= i - 1; j++) sum -= (*this)(i, j) * b[j];
      else if(sum) ii = i;
      b[i] = sum;
    }
    for(i = c - 1; i >= 0; i--){
      sum = b[i];
      for(j = i + 1; j < c; j++) sum -= (*this)(i, j) * b[j];
      b[i] = sum / (*this)(i, i);
    }
  }
  bool _lu_decomposition(int *indx , SCALAR &determinant)
  {
    if(r != c) 
      Msg::Fatal("Gmsh_Matrix::_lu_decomposition : cannot lu decompose a non-square matrix");
    int i, imax, j, k;
    SCALAR big, dum, sum, temp;
    SCALAR *vv = new SCALAR[c];    
    determinant = 1.0;
    for(i = 0; i < c; i++){
      big = 0.0;
      for(j = 0; j < c; j++)
	if((temp=fabs((*this)(i, j))) > big) big = temp;
      if(big == 0.0) {
	return false;
	big = 1.e-12;
      }      
      vv[i] = 1.0 / big;
    }
    for(j = 0; j < c; j++){
      for(i = 0; i < j; i++){
	sum=(*this)(i, j);
	for(k = 0; k < i; k++) sum -= (*this)(i, k)*(*this)(k, j);
	(*this)(i, j) = sum;
      }
      big = 0.0;
      for(i = j; i < c; i++){
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
	for(k = 0; k < c; k++){
	  dum = (*this)(imax, k);
	  (*this)(imax, k) = (*this)(j, k);
	  (*this)(j, k) = dum;
	}
	determinant = -(determinant);
	vv[imax] = vv[j];
      }
      indx[j] = imax;
      if((*this)(j, j) == 0.0) (*this)(j, j) = 1.e-20;
      if(j != c){
	dum = 1.0 / ((*this)(j, j));
	for(i = j + 1; i < c; i++) (*this)(i, j) *= dum;
      }
    }
    delete [] vv;
    return true;
  }
 public:
  inline int size1() const { return r; }
  inline int size2() const { return c; }
  Gmsh_Matrix(int R, int C) : r(R), c(C)
  {
    data = new SCALAR[r * c];
    scale(0.);
  }
  Gmsh_Matrix(const Gmsh_Matrix<SCALAR> &other) : r(other.r), c(other.c)
  {
    data = new SCALAR[r * c];
    memcpy(other);
  }
  ~Gmsh_Matrix() { delete [] data; }
  Gmsh_Matrix & operator=(const Gmsh_Matrix<SCALAR> &other)
  {
    if(this != &other){
      r = other.r; 
      c = other.c;
      data = new SCALAR[r * c];
      memcpy(other);
    }
    return *this;
  }
  Gmsh_Matrix() : r(0), c(0), data(0) {}
  void memcpy(const Gmsh_Matrix &other)
  {
    for(int i = 0; i < r * c; ++i) data[i] = other.data[i];
  }
  inline SCALAR operator () (int i, int j) const
  {
    return data[i + r * j];
  }
  inline SCALAR & operator () (int i, int j)
  {
    return data[i + r * j];
  }
  inline void mult(const Gmsh_Matrix<SCALAR> &b, Gmsh_Matrix<SCALAR> &c)
  {
    c.scale(0.);
    for(int i = 0; i < r; i++)
      for(int j = 0; j < b.size2(); j++)
	for(int k = 0; k < c; k++)
	  c.data[i + r * j] += (*this)(i, k) * b(k, j);
  }
  inline void blas_dgemm(const Gmsh_Matrix<SCALAR> &b, Gmsh_Matrix<SCALAR> &c, 
			 const SCALAR alpha=1.0, const SCALAR beta=1.0)
  {
    Gmsh_Matrix<SCALAR> temp(b.size1(), c.size2());
    temp.mult(b, c);
    scale(beta);
    temp.scale(alpha);
    add(temp);
  }
  inline void set_all(const SCALAR &m) 
  {
    for(int i = 0; i < r * c; i++) data[i] = m;
  }
  inline void lu_solve(const Gmsh_Vector<SCALAR> &rhs, Gmsh_Vector<SCALAR> &result)
  {
    int *indx = new int [c];
    SCALAR d;
    if(!_lu_decomposition(indx, d))
      Msg::Fatal("Singular matrix in Gmsh_Matrix::_lu_decomposition");
    for(int i = 0; i < c; i++) result[i] = rhs[i];
    _back_substitution(indx, result.data);
    delete [] indx; 
  }
  Gmsh_Matrix cofactor(int i, int j) const 
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
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	y.data[i] += (*this)(i, j) * x(j);
  }
  SCALAR determinant() const 
  {
    Gmsh_Matrix copy = *this;
    SCALAR factor = 1.0;
    int *indx = new int[c];
    if(!copy._lu_decomposition(indx, factor)) return 0.0;
    SCALAR det = factor;
    for(int i = 0; i < c; i++) det *= copy(i, i);
    delete [] indx;
    return det;
  }
  inline Gmsh_Matrix touchSubmatrix(int i0, int ni, int j0, int nj) 
  {
    Msg::Fatal("Gmsh_Matrix::touchSubmatrix is not implemented");
    Gmsh_Matrix subm(ni, nj);
    return subm;
  }  
  inline void scale(const double s)
  {
    if(s == 0.)
      for(int i = 0; i < r * c; ++i) data[i] = 0.;
    else
      for(int i = 0; i < r * c; ++i) data[i] *= s;
  }
  inline void add(const double &a) 
  {
    for(int i = 0; i < r * c; ++i) data[i] += a;
  }
  inline void add(const Gmsh_Matrix &m) 
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

class GSL_Vector
{
 private:
  int r;
  gsl_vector *data;
  friend class GSL_Matrix;
 public:
  inline int size() const { return r; }
  GSL_Vector(int R) : r(R)
  {
    data = gsl_vector_calloc(r);
  }
  GSL_Vector(const GSL_Vector &other) : r(other.r)
  {
    data = gsl_vector_calloc(r);
    gsl_vector_memcpy(data, other.data);
  }
  ~GSL_Vector() { gsl_vector_free(data); }
  inline double operator () (int i) const
  {
    return gsl_vector_get(data, i);
  }
  inline double & operator () (int i)
  {
    return *gsl_vector_ptr(data, i);
  }
  inline double norm()
  {
    return gsl_blas_dnrm2(data);
  }
  inline void scale(const double s)
  {
    if(s == 0.) gsl_vector_set_zero(data);
    else gsl_vector_scale(data, s);
  }
};

class GSL_Matrix
{
 private:
  gsl_matrix_view view;
  gsl_matrix *data;
  inline const gsl_matrix_view _see_submatrix(int i0, int ni, int j0, int nj) const
  {
    return gsl_matrix_submatrix(data, i0, j0, ni, nj);
  }
 public:
  inline int size1() const { return data->size1; }
  inline int size2() const { return data->size2; }
  GSL_Matrix(gsl_matrix_view _data) : view(_data), data(&view.matrix) {}
  GSL_Matrix(int r, int  c) { data = gsl_matrix_calloc(r, c); }
  GSL_Matrix() : data(0) {}
  GSL_Matrix(const GSL_Matrix &other) : data(0)
  {
    if(data) gsl_matrix_free(data);
    data = gsl_matrix_calloc(other.data->size1, other.data->size2);
    gsl_matrix_memcpy(data, other.data);
  }
  ~GSL_Matrix() { if(data && data->owner == 1) gsl_matrix_free(data); }
  GSL_Matrix & operator = (const GSL_Matrix&other)
  {
    if(&other != this){
      if(data) gsl_matrix_free(data);
      data = gsl_matrix_calloc(other.data->size1, other.data->size2);
      gsl_matrix_memcpy(data, other.data);
    }
    return *this;
  }
  void memcpy(const GSL_Matrix &other)
  {
    gsl_matrix_memcpy(data, other.data);
  }
  inline double operator () (int i, int j) const
  {
    return gsl_matrix_get(data, i, j);
  }
  inline double & operator () (int i, int j)
  {
    return *gsl_matrix_ptr(data, i, j);
  }
  inline void mult(const GSL_Matrix &b, GSL_Matrix &c)
  {
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1., data, b.data, 0., c.data);
  }
  inline void blas_dgemm(const GSL_Matrix &x, GSL_Matrix &b, 
			 const double alpha = 1.0, const double beta = 1.0)
  {      
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, alpha, x.data, b.data, beta, data);
  }
  inline void set_all(const double &m) 
  {
    gsl_matrix_set_all(data, m);
  }
  inline void lu_solve(const GSL_Vector &rhs, GSL_Vector &result)
  {
    int s;
    gsl_permutation * p = gsl_permutation_alloc(size1());
    gsl_linalg_LU_decomp(data, p, &s);
    gsl_linalg_LU_solve(data, p, rhs.data, result.data);
    gsl_permutation_free(p);
  }
  GSL_Matrix cofactor(int i, int j) const 
  {
    int ni = size1();
    int nj = size2();
    GSL_Matrix cof(ni - 1, nj - 1);
    if(i > 0) {
      if(j > 0)
        GSL_Matrix(cof.touchSubmatrix(0, i , 0, j)).
          memcpy(GSL_Matrix(_see_submatrix(0, i, 0, j)));
      if(j < nj - 1)
        GSL_Matrix(cof.touchSubmatrix(0, i, j, nj - j - 1)).
          memcpy(GSL_Matrix(_see_submatrix(0, i, j + 1,nj - j - 1)));
    }
    if(i < ni - 1) {  
      if(j < nj - 1)
        GSL_Matrix(cof.touchSubmatrix(i, ni - i - 1, j, nj - j - 1)).
          memcpy(GSL_Matrix(_see_submatrix(i + 1, ni - i - 1, j + 1, nj - j - 1)));
      if(j > 0)
        GSL_Matrix(cof.touchSubmatrix(i, ni - i - 1, 0, j)).
          memcpy(GSL_Matrix(_see_submatrix(i + 1, ni - i - 1, 0, j)));
    }
    return cof;
  }
  inline void mult(const GSL_Vector &x, GSL_Vector &b)
  {
    gsl_blas_dgemv(CblasNoTrans, 1., data, x.data, 0., b.data);
  }
  double determinant() const 
  {
    GSL_Matrix copy = *this;
    gsl_permutation *p = gsl_permutation_alloc(size1());
    int s;
    gsl_linalg_LU_decomp(copy.data, p, &s);
    gsl_permutation_free(p);
    return gsl_linalg_LU_det(copy.data, s);
  } 
  inline gsl_matrix_view touchSubmatrix(int i0, int ni, int j0, int nj) 
  {
    return gsl_matrix_submatrix(data, i0, j0, ni, nj);
  }  
  inline void scale(const double s) 
  {
    if(s == 0.) gsl_matrix_set_zero(data);
    else gsl_matrix_scale(data, s);
  }
  inline void add(const double &a) 
  {
    gsl_matrix_add_constant(data, a);
  }
  inline void add(const GSL_Matrix &m) 
  {
    gsl_matrix_add(data, m.data);
  }
};

typedef GSL_Matrix Double_Matrix;
typedef GSL_Vector Double_Vector;

#else

typedef Gmsh_Matrix<double> Double_Matrix;
typedef Gmsh_Vector<double> Double_Vector;

#endif

typedef Gmsh_Matrix<int> Int_Matrix;
typedef Gmsh_Vector<int> Int_Vector;

#endif
