#ifndef _GMSH_BOOSTMATRIX_
#define _GMSH_BOOSTMATRIX_

#ifndef HAVE_BOOST
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
};

typedef Gmsh_Matrix<double> Double_Matrix;
typedef Gmsh_Matrix<int>    Int_Matrix;

#else
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/io.hpp>
typedef  numerics::matrix<double, numerics::column_major>  Double_Matrix;
typedef  numerics::vector<double>  Double_Vector;
typedef  numerics::matrix<int, numerics::column_major>  Int_Matrix;
typedef  numerics::vector<int>  Int_Vector;
#endif
#endif
