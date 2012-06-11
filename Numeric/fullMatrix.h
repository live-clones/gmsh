// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _FULL_MATRIX_H_
#define _FULL_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include "GmshConfig.h"
#include "GmshMessage.h"

template <class scalar> class fullMatrix;

// An abstract interface for vectors of scalar
template <class scalar>
class fullVector
{
 private:
  int _r;          // size of the vector
  scalar *_data;   // pointer on the first element
  bool _own_data;
  friend class fullMatrix<scalar>;

 public:
  // constructor and destructor
  fullVector(void) : _r(0),_data(0),_own_data(1) {}
  fullVector(int r) : _r(r),_own_data(1)
  {
    _data = new scalar[_r];
    setAll(scalar(0.));
  }
  fullVector(const fullVector<scalar> &other) : _r(other._r),_own_data(1)
  {
    _data = new scalar[_r];
    for(int i = 0; i < _r; ++i) _data[i] = other._data[i];
  }
  ~fullVector()
  {
    if(_own_data && _data) delete [] _data;
  }

  // get information (size, value)
  inline int size()                  const { return _r; }
  inline const scalar * getDataPtr() const { return _data; }
  inline scalar operator () (int i)  const { return _data[i]; }
  inline scalar & operator () (int i)      { return _data[i]; }
  // copy
  fullVector<scalar>& operator= (const fullVector<scalar> &other)
  {
    if (this != &other) {
      if ((!resize(other.size(), false) && _r > 2*other.size())) {
        if (_data) delete[] _data;
        _r = other.size();
        _data = new scalar[_r];
      }
      setAll(other);
    }
    return *this;
  }
  // set
  inline void set(int r, scalar v){
    #ifdef _DEBUG
    if (r >= _r || r < 0)
      Msg::Fatal("invalid index to access fullVector : %i (size = %i)",
                 r, _r);
    #endif
    (*this)(r) = v;
  }

  // operations
  inline scalar norm() const
  {
    scalar n = 0.;
    for(int i = 0; i < _r; ++i) n += _data[i] * _data[i];
    return sqrt(n);
  }
  bool resize(int r, bool resetValue = true)
  {
    if (_r < r || !_own_data) {
      if (_own_data && _data) delete[] _data;
      _r = r;
      _data = new scalar[_r];
      _own_data = true;
      if(resetValue)
        setAll(scalar(0.));
      return true;
    }
    _r = r;
    if(resetValue)
      setAll(scalar(0.));
    return false;
  }
  void setAsProxy(const fullVector<scalar> &original, int r_start, int r)
  {
    if(_own_data && _data) delete [] _data;
    _own_data = false;
    _r = r;
    _data = original._data + r_start;
  }
  void setAsProxy(const fullMatrix<scalar> &original, int c)
  {
    if(_own_data && _data) delete [] _data;
    _own_data = false;
    _r = original._r;
    _data = original._data + c * _r;
  }
  inline void scale(const scalar s)
  {
    if(s == scalar(0.))
      for(int i = 0; i < _r; ++i) _data[i] = scalar(0.);
    else if (s == -1.)
      for(int i = 0; i < _r; ++i) _data[i] = -_data[i];
    else
      for(int i = 0; i < _r; ++i) _data[i] *= s;
  }
  inline void setAll(const scalar &m)
  {
    for(int i = 0; i < _r; i++) set(i,m);
  }
  inline void setAll(const fullVector<scalar> &m)
  {
    for(int i = 0; i < _r; i++) _data[i] = m._data[i];
  }
  inline scalar operator *(const fullVector<scalar> &other)
  {
    scalar s = 0.;
    for(int i = 0; i < _r; ++i) s += _data[i] * other._data[i];
    return s;
  }
  void axpy(const fullVector<scalar> &x, scalar alpha=1.)
#if !defined(HAVE_BLAS)
  {
    for (int i = 0; i < _r; i++) _data[i] += alpha * x._data[i];
  }
#endif
  ;
  void multTByT(const fullVector<scalar> &x)
  {
    for (int i = 0; i < _r; i++) _data[i] *= x._data[i];
  }

  // printing and file treatment
  void print(const char *name="") const
  {
    printf("double %s[%d]=\n", name,size());
    printf("{  ");
    for(int I = 0; I < size(); I++){
      printf("%12.5E ", (*this)(I));
    }
    printf("};\n");
  }
  void binarySave (FILE *f) const
  {
    fwrite (_data, sizeof(scalar), _r, f);
  }
  void binaryLoad (FILE *f)
  {
    if(fread (_data, sizeof(scalar), _r, f) != _r) return;
  }
};

// An abstract interface for dense matrix of scalar
template <class scalar>
class fullMatrix
{
 private:
  bool _own_data; // should data be freed on delete ?
  int _r, _c; // size of the matrix
  scalar *_data; // pointer on the first element
  friend class fullVector<scalar>;

 public:
  // constructor and destructor
  fullMatrix(scalar *original, int r, int c)
  {
    _r = r;
    _c = c;
    _own_data = false;
    _data = original;
  }
  fullMatrix(fullMatrix<scalar> &original, int c_start, int c)
  {
    _c = c;
    _r = original._r;
    _own_data = false;
    _data = original._data + c_start * _r;
  }
  fullMatrix(int r, int c) : _r(r), _c(c)
  {
    _data = new scalar[_r * _c];
    _own_data = true;
    setAll(scalar(0.));
  }
  fullMatrix(int r, int c, double *data)
    : _r(r), _c(c), _data(data), _own_data(false)
  {
    setAll(scalar(0.));
  }
  fullMatrix(const fullMatrix<scalar> &other) : _r(other._r), _c(other._c)
  {
    _data = new scalar[_r * _c];
    _own_data=true;
    for(int i = 0; i < _r * _c; ++i) _data[i] = other._data[i];
  }
  fullMatrix() : _own_data(false),_r(0), _c(0), _data(0) {}
  ~fullMatrix()
  {
    if(_data && _own_data) delete [] _data;
  }

  // get information (size, value)
  inline int size1() const { return _r; }
  inline int size2() const { return _c; }
  inline scalar get(int r, int c) const
  {
    #ifdef _DEBUG
    if (r >= _r || r < 0 || c >= _c || c < 0)
      Msg::Fatal("invalid index to access fullMatrix : %i %i (size = %i %i)",
                 r, c, _r, _c);
    #endif
    return (*this)(r, c);
  }

  // operations
  inline void set(int r, int c, scalar v){
    #ifdef _DEBUG
    if (r >= _r || r < 0 || c >= _c || c < 0)
      Msg::Fatal("invalid index to access fullMatrix : %i %i (size = %i %i)",
                 r, c, _r, _c);
    #endif
    (*this)(r, c) = v;
  }
  inline scalar norm() const
  {
    scalar n = 0.;
    for(int i = 0; i < _r; ++i)
      for(int j = 0; j < _c; ++j)
        n += (*this)(i, j) * (*this)(i, j);
    return sqrt(n);
  }
  bool resize(int r, int c, bool resetValue = true) // data will be owned (same as constructor)
  {
    if ((r * c > _r * _c) || !_own_data) {
      if (_own_data && _data) delete[] _data;
      _r = r;
      _c = c;
      _data = new scalar[_r * _c];
      _own_data = true;
      if(resetValue)
        setAll(scalar(0.));
      return true;
    }
    _r = r;
    _c = c;
    if(resetValue)
      setAll(scalar(0.));
    return false; // no reallocation
  }
  void setAsProxy(const fullMatrix<scalar> &original)
  {
    if(_data && _own_data)
      delete [] _data;
    _c = original._c;
    _r = original._r;
    _own_data = false;
    _data = original._data;
  }
  void setAsProxy(const fullMatrix<scalar> &original, int c_start, int c)
  {
    if(_data && _own_data)
      delete [] _data;
    _c = c;
    _r = original._r;
    _own_data = false;
    _data = original._data + c_start * _r;
  }
  void setAsProxy(double *data, int r, int c)
  {
    if(_data && _own_data)
      delete [] _data;
    _c = c;
    _r = r;
    _own_data = false;
    _data = data;
  }
  fullMatrix<scalar> & operator = (const fullMatrix<scalar> &other)
  {
    copy(other);
    return *this;
  }
  void operator += (const fullMatrix<scalar> &other)
  {
    if(_r != other._r || _c!= other._c)
      Msg::Error("sum matrices of different sizes\n");
    for(int i = 0; i < _r * _c; ++i) _data[i] += other._data[i];
  }
  inline scalar operator () (int i, int j) const
  {
    #ifdef _DEBUG
    if (i >= _r || i < 0 || j >= _c || j < 0)
      Msg::Fatal("invalid index to access fullMatrix : %i %i (size = %i %i)",
                 i, j, _r, _c);
    #endif
    return _data[i + _r * j];
  }
  inline scalar & operator () (int i, int j)
  {
    #ifdef _DEBUG
    if (i >= _r || i < 0 || j >= _c || j < 0)
      Msg::Fatal("invalid index to access fullMatrix : %i %i (size = %i %i)",
                 i, j, _r, _c);
    #endif
    return _data[i + _r * j];
  }
  void copy(const fullMatrix<scalar> &a, int i0, int ni, int j0, int nj,
            int desti0, int destj0)
  {
    for(int i = i0, desti = desti0; i < i0 + ni; i++, desti++)
      for(int j = j0, destj = destj0; j < j0 + nj; j++, destj++)
        (*this)(desti, destj) = a(i, j);
  }
  void copy(const fullMatrix<scalar> &a)
  {
    if (_data && !_own_data)
      Msg::Fatal("fullMatrix::copy operation is prohibited for proxies, use setAll instead");
    if (_r != a._r || _c != a._c) {
      if(_data && _own_data)
        delete [] _data;
      _r = a._r;
      _c = a._c;
      _data = new scalar[_r * _c];
      _own_data = true;
    }
    setAll(a);
  }
  void mult_naive(const fullMatrix<scalar> &b, fullMatrix<scalar> &c) const
  {
    c.scale(scalar(0.));
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < b.size2(); j++)
        for(int k = 0; k < _c; k++)
          c._data[i + _r * j] += (*this)(i, k) * b(k, j);
  }
  void mult(const fullMatrix<scalar> &b, fullMatrix<scalar> &c) const
#if !defined(HAVE_BLAS)
  {
    mult_naive(b,c);
  }
#endif
  ;
  void multTByT(const fullMatrix<scalar> &a)
  {
    for (int i = 0; i < _r * _c; i++) _data[i] *= a._data[i];
  }
  void axpy(const fullMatrix<scalar> &x, scalar alpha=1.)
#if !defined(HAVE_BLAS)
  {
    int n = _r * _c;
    for (int i = 0; i < n; i++) _data[i] += alpha * x._data[i];
  }
#endif
  ;
  void gemm_naive(const fullMatrix<scalar> &a, const fullMatrix<scalar> &b,
                  scalar alpha=1., scalar beta=1.)
  {
    fullMatrix<scalar> temp(a.size1(), b.size2());
    a.mult_naive(b, temp);
    temp.scale(alpha);
    scale(beta);
    add(temp);
  }
  void gemm(const fullMatrix<scalar> &a, const fullMatrix<scalar> &b,
            scalar alpha=1., scalar beta=1.)
#if !defined(HAVE_BLAS)
  {
    gemm_naive(a,b,alpha,beta);
  }
#endif
  ;
  inline void setAll(const scalar &m)
  {
    for(int i = 0; i < _r * _c; i++) _data[i] = m;
  }
  inline void setAll(const fullMatrix<scalar> &m)
  {
    if (_r != m._r || _c != m._c )
      Msg::Fatal("fullMatrix size does not match");
    for(int i = 0; i < _r * _c; i++) _data[i] = m._data[i];
  }
  void scale(const double s)
#if !defined(HAVE_BLAS)
  {
    if(s == 0.) // this is not really correct nan*0 (or inf*0) is expected to give nan
      for(int i = 0; i < _r * _c; ++i) _data[i] = scalar(0.);
    else
      for(int i = 0; i < _r * _c; ++i) _data[i] *= s;
  }
#endif
  ;
  inline void add(const double &a)
  {
    for(int i = 0; i < _r * _c; ++i) _data[i] += a;
  }
  inline void add(const fullMatrix<scalar> &m)
  {
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
        (*this)(i, j) += m(i, j);
  }
  inline void add(const fullMatrix<scalar> &m, const double &a)
  {
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
        (*this)(i, j) += a*m(i, j);
  }
  void mult(const fullVector<scalar> &x, fullVector<scalar> &y) const
#if !defined(HAVE_BLAS)
  {
    y.scale(scalar(0.));
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++)
        y._data[i] += (*this)(i, j) * x(j);
  }
#endif
  ;
  void multAddy(const fullVector<scalar> &x, fullVector<scalar> &y) const
#if !defined(HAVE_BLAS)
  {
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++)
        y._data[i] += (*this)(i, j) * x(j);
  }
#endif
  ;
  inline fullMatrix<scalar> transpose() const
  {
    fullMatrix<scalar> T(size2(), size1());
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < size2(); j++)
        T(j, i) = (*this)(i, j);
    return T;
  }
  inline void transposeInPlace()
  {
    if(size1() != size2()){
      Msg::Error("Not a square matrix (size1: %d, size2: %d)", size1(), size2());
    }
    scalar t;
    for(int i = 0; i < size1(); i++)
      for(int j = 0; j < i; j++) {
        t = _data[i + _r * j];
        _data[i + _r * j] = _data[j + _r * i];
        _data[j + _r * i] = t;
      }
  }
  bool luSolve(const fullVector<scalar> &rhs, fullVector<scalar> &result)
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("LU factorization requires LAPACK");
    return false;
  }
#endif
  ;
  bool invertInPlace()
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("Matrix inversion requires LAPACK");
    return false;
  }
#endif
  ;
  bool eig(fullVector<double> &eigenValReal, fullVector<double> &eigenValImag,
           fullMatrix<scalar> &leftEigenVect, fullMatrix<scalar> &rightEigenVect,
           bool sortRealPart=false)
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("Eigenvalue computations requires LAPACK");
    return false;
  }
#endif
  ;
  bool invert(fullMatrix<scalar> &result) const
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("LU factorization requires LAPACK");
    return false;
  }
#endif
  ;
  fullMatrix<scalar> cofactor(int i, int j) const
  {
    int ni = size1();
    int nj = size2();
    fullMatrix<scalar> cof(ni - 1, nj - 1);
    for(int I = 0; I < ni; I++)
      for(int J = 0; J < nj; J++)
        if(J != j && I != i)
          cof(I < i ? I : I - 1, J < j ? J : J - 1) = (*this)(I, J);
    return cof;
  }
  scalar determinant() const
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("Determinant computation requires LAPACK");
    return scalar(0.);
  }
#endif
  ;
  bool svd(fullMatrix<scalar> &V, fullVector<scalar> &S)
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("Singular value decomposition requires LAPACK");
    return false;
  }
#endif
  ;

  void print(const std::string name = "", const std::string format = "%12.5E ") const
  {
    int ni = size1();
    int nj = size2();
    printf("double %s [ %d ][ %d ]= { \n", name.c_str(),ni,nj);
    for(int I = 0; I < ni; I++){
      printf("{  ");
      for(int J = 0; J < nj; J++){
        printf(format.c_str(), (*this)(I, J));
	if (J!=nj-1)printf(",");
      }
      if (I!=ni-1)printf("},\n");
      else printf("}\n");
    }
    printf("};\n");
  }

// specific functions for dgshell
  void mult_naiveBlock(const fullMatrix<scalar> &b, const int ncol, const int fcol, const int alpha, const int beta, fullVector<scalar> &c, const int row=0) const
  {
    if(beta != 1)
      c.scale(beta);
    for(int j = fcol; j < fcol+ncol; j++)
      for(int k = 0; k < _c ; k++)
          c._data[j] += alpha*(*this)(row, k) * b(k, j);
  }
  void multOnBlock(const fullMatrix<scalar> &b, const int ncol, const int fcol, const int alpha, const int beta, fullVector<scalar> &c) const
#if !defined(HAVE_BLAS)
  {
    mult_naiveBlock(b,ncol,fcol,alpha,beta,c);
  }
#endif
  ;

  void multWithATranspose(const fullVector<scalar> &x, scalar alpha, scalar beta, fullVector<scalar> &y) const
#if !defined(HAVE_BLAS)
  {
    y.scale(beta);
    for(int j = 0; j < _c; j++)
      for(int i = 0; i < _r; i++)
        y._data[j] += alpha * (*this)(i, j) * x(i);
  }
#endif
  ;

  void copyOneColumn(const fullVector<scalar> &x, const int ind) const
  {
    int cind = _c*ind;
    for(int i = 0; i < _r; i++)
     _data[cind+i] = x(i);
  }

  void gemmWithAtranspose(const fullMatrix<scalar> &a, const fullMatrix<scalar> &b,
            scalar alpha=1., scalar beta=1.)
#if !defined(HAVE_BLAS)
  {
    Msg::Error("gemmWithAtranspose is only available with blas. If blas is not installed please transpose a before used gemm_naive");
  }
#endif
  ;

  void reshape(int nbRows, int nbColumns){
    if (nbRows*nbColumns != size1()*size2())
      Msg::Error("Invalid reshape, total number of entries must be equal");
    _r = nbRows;
    _c = nbColumns;
  }

};
#endif
