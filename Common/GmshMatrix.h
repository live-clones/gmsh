#ifndef _GMSH_BOOSTMATRIX_
#define _GMSH_BOOSTMATRIX_

#include <assert.h>

template <class SCALAR>
class Gmsh_Vector
{
private:
  int r;
public:
  inline int size() const {return r;}
  SCALAR *data;
  ~Gmsh_Vector() {delete [] data;}
  Gmsh_Vector(int R)
    : r(R)
  {
    data = new SCALAR [r];
    scal(0);
  }
  Gmsh_Vector(const Gmsh_Vector<SCALAR> &other)
    : r(other.r)
  {
    data = new double [r];
    copy ( other.data ) ;
  }
  inline SCALAR operator () (int i) const
  {
    return data[i];
  }
  inline SCALAR & operator () (int i)
  {
    return data[i];
  }
  inline SCALAR operator *(const Gmsh_Vector<SCALAR> & other)
  {
    throw;
  }
  inline void scal ( const SCALAR s)
  {
    for (int i=0;i<r;++i)data[i]*=s;
  }
  inline void copy ( const SCALAR **other)
  {
    for (int i=0;i<r;++i)data[i]=other.data[i];
  }
  inline void lu_solve (const  Gmsh_Vector<SCALAR>& rhs,  Gmsh_Vector<SCALAR> & result)
  {
    throw;
  }
};

template <class SCALAR>
class Gmsh_Matrix
{
private:
  int r,c;
public:
  inline int size1() const {return r;}
  inline int size2() const {return c;}
  SCALAR *data;
  ~Gmsh_Matrix() {delete [] data;}
  Gmsh_Matrix(int R,int C)
    : r(R),c(C)
  {
    data = new SCALAR [r*c];
    scal(0);
  }
  Gmsh_Matrix(const Gmsh_Matrix<SCALAR> &other)
    : r(other.r),c(other.c)
  {
    data = new double [r*c];
    copy ( other.data ) ;
  }
  inline SCALAR operator () (int i, int j) const
  {
    return data[i+r*j];
  }
  inline SCALAR & operator () (int i, int j)
  {
    return data[i+r*j];
  }
  inline Gmsh_Matrix operator *(const Gmsh_Matrix<SCALAR> & other)
  {
    throw;
  }
  inline void scal ( const SCALAR s)
  {
    for (int i=0;i<r*c;++i)data[i]*=s;
  }
  inline void copy ( const SCALAR **other)
  {
    for (int i=0;i<r*c;++i)data[i]=other.data[i];
  }
  inline void mult(const Gmsh_Matrix<SCALAR> & x, const Gmsh_Matrix<SCALAR> & b)
  {
    throw;
  }
  inline void mult (const Gmsh_Vector<SCALAR> & x, Gmsh_Vector<SCALAR> & b )
  {
    throw;
  }
  inline void least_squares (const Gmsh_Vector<SCALAR> & rhs, Gmsh_Vector<SCALAR> & result)
  {
    throw;
  }
  inline void lu_solve (const Gmsh_Vector<SCALAR> & rhs, Gmsh_Vector<SCALAR> & result)
  {
    throw;
  }
};

#ifdef HAVE_GSL
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
class GSL_Vector
{
private:
  int r;
public:
  inline int size() const {return r;}
  gsl_vector *data;
  ~GSL_Vector() {gsl_vector_free (data);}
  GSL_Vector(int R)
    : r(R)
  {
    data = gsl_vector_calloc (r);
  }
  GSL_Vector(const GSL_Vector&other)
    : r(other.r)
  {
    data = gsl_vector_calloc (r);
    gsl_vector_memcpy (data, other.data);
  }
  inline double operator () (int i) const
  {
    return gsl_vector_get (data,i);
  }
  inline double & operator () (int i)
  {
    return *gsl_vector_ptr (data,i);
  }
};

class GSL_Matrix
{
private:
  int r,c;
public:
  inline int size1() const {return r;}
  inline int size2() const {return c;}
  gsl_matrix *data;
  ~GSL_Matrix() {gsl_matrix_free (data);}
  GSL_Matrix(int R,int C)
    : r(R),c(C)
  {
    data = gsl_matrix_calloc (r, c);
  }
  GSL_Matrix(const GSL_Matrix&other)
    : r(other.r),c(other.c)
  {
    data = gsl_matrix_calloc (r, c);
    gsl_matrix_memcpy (data, other.data);
  }
  inline double operator () (int i, int j) const
  {
    return gsl_matrix_get (data,i,j);
  }
  inline double & operator () (int i, int j)
  {
    return *gsl_matrix_ptr (data,i,j);
  }
  inline void mult(const GSL_Matrix & x, const GSL_Matrix & b)
  {
    gsl_blas_dgemm (CblasNoTrans,CblasNoTrans, 1.0, data, x.data, 1.0, b.data);
  }
  inline void least_squares (const GSL_Vector & rhs, GSL_Vector & result)
  {
    assert (r > c);
    assert (rhs.size() == r);
    assert (result.size() == c);
    GSL_Matrix *ls     = new GSL_Matrix(c, c);
    GSL_Vector *ls_rhs = new GSL_Vector(c);
    //GSL_Vector *test = new GSL_Vector(c);
    gsl_blas_dgemm (CblasTrans,CblasNoTrans, 1.0, data, data, 1.0, ls->data);
    gsl_blas_dgemv (CblasTrans, 1.0, data, rhs.data, 1.0, ls_rhs->data);
    ls->lu_solve (*ls_rhs,result);
    delete ls;
    delete ls_rhs;
  }
  inline void lu_solve (const GSL_Vector & rhs, GSL_Vector & result)
  {
    int s;
    gsl_permutation * p = gsl_permutation_alloc (size1());
    gsl_linalg_LU_decomp ( data, p, &s);
    gsl_linalg_LU_solve ( data ,  p, rhs.data, result.data ) ;
    gsl_permutation_free (p);
  }
  inline void mult (const GSL_Vector & x, GSL_Vector & b )
  {
    gsl_blas_dgemv (CblasNoTrans, 1.0, data, x.data, 1.0, b.data);
  }
};
typedef GSL_Matrix Double_Matrix;
typedef GSL_Vector Double_Vector;
#else
typedef Gmsh_Matrix<double> Double_Matrix;
typedef Gmsh_Vector<double> Double_Vector;
#endif
typedef Gmsh_Matrix<int>    Int_Matrix;
typedef Gmsh_Vector<int>    Int_Vector;
#endif
