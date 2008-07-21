// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_MATRIX_H_
#define _GMSH_MATRIX_H_

template <class SCALAR>
class Gmsh_Vector
{
 private:
  int r;
 public:
  inline int size() const { return r; }
  SCALAR *data;
  ~Gmsh_Vector() { delete [] data; }
  Gmsh_Vector(int R) : r(R)
  {
    data = new SCALAR[r];
    scale(0);
  }
  Gmsh_Vector(const Gmsh_Vector<SCALAR> &other) : r(other.r)
  {
    data = new double[r];
    for (int i = 0; i < r; ++i) data[i] = other.data[i];
  }
  inline SCALAR operator () (int i) const
  {
    return data[i];
  }
  inline SCALAR & operator () (int i)
  {
    return data[i];
  }
  inline double norm()
  {
    double n = 0.;
    for(int i = 0; i < r; ++i) n += data[i] * data[i];
    return sqrt(n);
  }
  inline void scale(const SCALAR s)
  {
    for (int i = 0; i < r; ++i) data[i] *= s;
  }
};

template <class SCALAR>
class Gmsh_Matrix
{
 private:
  int r, c;
 public:
  inline int size1() const { return r; }
  inline int size2() const { return c; }
  SCALAR *data;
  ~Gmsh_Matrix() { delete [] data; }
  Gmsh_Matrix(int R,int C) : r(R), c(C)
  {
    data = new SCALAR[r * c];
    scale(0);
  }
  Gmsh_Matrix(const Gmsh_Matrix<SCALAR> &other) : r(other.r), c(other.c)
  {
    data = new double[r * c];
    memcpy(other);
  }
  Gmsh_Matrix() : r(0), c(0), data(0) {}
  void memcpy(const Gmsh_Matrix &other)
  {
    for (int i = 0; i < r * c; ++i) data[i] = other.data[i];
  }
  inline SCALAR operator () (int i, int j) const
  {
    return data[i + r * j];
  }
  inline SCALAR & operator () (int i, int j)
  {
    return data[i + r * j];
  }
  inline void mult(const Gmsh_Matrix<SCALAR> &x, const Gmsh_Matrix<SCALAR> &b)
  {
    for(int i = 0; i < b.size1(); i++)
      for(int j = 0; j < b.size2(); j++)
	for(int k = 0; k < size2(); k++)
	  b.data[i + r *j] += (*this)(i, k) * x(k, j);
  }
  inline void mult(const Gmsh_Vector<SCALAR> &x, Gmsh_Vector<SCALAR> &b)
  {
    for(int i = 0; i < b.size(); i++)
      for(int j = 0; j < b.size(); j++)
	b.data[i] += (*this)(i, j) * x(j);
  }
  inline void set_all(const double &m) 
  {
    for(int i = 0; i < r * c; i++) data[i] = m;
  }
  inline void lu_solve(const Gmsh_Vector<SCALAR> &rhs, Gmsh_Vector<SCALAR> &result)
  {
    // FIXME: not implemented
    result.scale(0);
  }
  Gmsh_Matrix cofactor(int i, int j) const 
  {
    // FIXME: not implemented
    Gmsh_Matrix cof(size1() - 1, size2() - 1);
    return cof;
  }
  inline void invert()
  {
    // FIXME: not implemented
  }
  double determinant() const 
  {
    // FIXME: not implemented
    return 0.;
  }
  inline Gmsh_Matrix touchSubmatrix(int i0, int ni, int j0, int nj) 
  {
    // FIXME: not implemented
    Gmsh_Matrix subm(ni, nj);
    return subm;
  }  
  inline void scale(const SCALAR s)
  {
    for (int i = 0; i < r * c; ++i) data[i] *= s;
  }
  inline void add(const double &a) 
  {
    for (int i = 0; i < r * c; ++i) data[i] += a;
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
 public:
  inline int size() const { return r; }
  gsl_vector *data;
  ~GSL_Vector() { gsl_vector_free(data); }
  GSL_Vector(int R) : r(R)
  {
    data = gsl_vector_calloc(r);
  }
  GSL_Vector(const GSL_Vector &other) : r(other.r)
  {
    data = gsl_vector_calloc(r);
    gsl_vector_memcpy(data, other.data);
  }
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
  inline void scale(const double &y)
  {
    if (y == 0.0) gsl_vector_set_zero(data);
    else gsl_vector_scale(data, y);
  }
};

class GSL_Matrix
{
 private:
  gsl_matrix_view view;
 public:
  inline int size1() const { return data->size1; }
  inline int size2() const { return data->size2; }
  gsl_matrix *data;
  GSL_Matrix(gsl_matrix_view _data) : view(_data), data(&view.matrix) {}
  GSL_Matrix(int r, int  c) { data = gsl_matrix_calloc(r, c); }
  GSL_Matrix() : data(0) {}
  GSL_Matrix(const GSL_Matrix &other) : data(0)
  {
    if(data) gsl_matrix_free(data);
    data = gsl_matrix_calloc(other.data->size1, other.data->size2);
    gsl_matrix_memcpy(data, other.data);
  }
  virtual ~GSL_Matrix() { if(data && data->owner == 1) gsl_matrix_free(data); }
  GSL_Matrix & operator = (const GSL_Matrix&other)
  {
    if (&other != this){
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
  inline void mult(const GSL_Matrix &x, const GSL_Matrix &b)
  {
    gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, data, x.data, 1.0, b.data);
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
  inline void invert ()
  {
    int s;
    gsl_permutation *p = gsl_permutation_alloc (size1());
    gsl_linalg_LU_decomp(data, p, &s);
    gsl_matrix *data_inv = gsl_matrix_calloc(size1(), size2());
    gsl_linalg_LU_invert(data, p, data_inv) ;
    gsl_matrix_memcpy(data, data_inv);
    gsl_matrix_free(data_inv);
    gsl_permutation_free(p);
  }
  inline bool invertSecure(double &det)
  {
    int s;
    gsl_permutation *p = gsl_permutation_alloc (size1());
    gsl_linalg_LU_decomp(data, p, &s);
    det = gsl_linalg_LU_det(data, s);
    gsl_matrix *data_inv = gsl_matrix_calloc(size1(), size2());
    gsl_linalg_LU_invert(data, p, data_inv);
    gsl_matrix_memcpy(data, data_inv);
    gsl_matrix_free(data_inv);
    gsl_permutation_free(p);
    return (det != 0.);
  }
  double determinant() const 
  {
    GSL_Matrix copy = *this;
    double det;
    copy.invertSecure(det);
    return det;
  } 
  GSL_Matrix cofactor(int i, int j) const 
  {
    int ni = size1();
    int nj = size2();
    GSL_Matrix cof(ni - 1, nj - 1);
    if (i > 0) {
      if (j > 0)
        GSL_Matrix(cof.touchSubmatrix(0, i , 0, j)).
          memcpy(GSL_Matrix(seeSubmatrix(0, i, 0, j)));
      if (j < nj - 1)
        GSL_Matrix(cof.touchSubmatrix(0, i, j, nj - j - 1)).
          memcpy(GSL_Matrix(seeSubmatrix(0, i, j + 1,nj - j - 1)));
    }
    if (i < ni - 1) {  
      if (j < nj - 1)
        GSL_Matrix(cof.touchSubmatrix(i, ni - i - 1, j, nj - j - 1)).
          memcpy(GSL_Matrix(seeSubmatrix(i + 1, ni - i - 1, j + 1, nj - j - 1)));
      if (j > 0)
        GSL_Matrix(cof.touchSubmatrix(i, ni - i - 1, 0, j)).
          memcpy(GSL_Matrix(seeSubmatrix(i + 1, ni - i - 1, 0, j)));
    }      
    return cof;
  }
  inline void mult(const GSL_Vector &x, GSL_Vector &b)
  {
    gsl_blas_dgemv(CblasNoTrans, 1.0, data, x.data, 1.0, b.data);
  }
  inline gsl_matrix_view touchSubmatrix(int i0, int ni, int j0, int nj) 
  {
    return gsl_matrix_submatrix(data, i0, j0, ni, nj);
  }  
  inline const gsl_matrix_view seeSubmatrix(int i0, int ni, int j0, int nj) const
  {
    return gsl_matrix_submatrix(data, i0, j0, ni, nj);
  }
  inline void scale(const double &m) 
  {
    if (m == 0.0) gsl_matrix_set_zero(data);
    else gsl_matrix_scale(data, m);
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
