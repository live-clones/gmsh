// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _FULL_MATRIX_H_
#define _FULL_MATRIX_H_

#include "GmshConfig.h"
#include "GmshMessage.h"
#include <cmath>
#include <cstdio>

template <class scalar> class fullMatrix;

/**
   @class fullVector
   @brief Vector of scalar

   This class represents a vector of scalar.@n
   Scalars can be real or complex, with simple or double precision.

   The first index of a fullVector is @c 0.

   fullVector%s can own their scalars,
   or just be an access point to an other fullVector.@n
   Such a fullVector is called a proxy.

   @see fullVector::setAsProxy(const fullVector&, int, int)
*/

/**
   @class fullMatrix
   @brief Matrix of scalar

   This class represents a matrix of scalar.@n
   Scalars can be real or complex, with simple or double precision.
*/

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
  /**
     Instantiates a zero size fullVector.
  */
  fullVector(void) : _r(0),_data(0),_own_data(1) {}

  /**
     @param r A positive integer.

     Instantiates a fullVector of size r filled with zeros.
  */
  fullVector(int r) : _r(r),_own_data(1)
  {
    _data = new scalar[_r];
    setAll(scalar(0.));
  }

  /**
     @param original A scalar pointer;
     @param r A positive integer.

     Instantiates a proxy fullVector given by:
     [original[0], original[1], ..., original[r - 1]].
  */
  fullVector(scalar *original, int r)
  {
    _r = r;
    _own_data = false;
    _data = original;
  }

  /**
     @param other A fullVector.

     Instantiates a fullVector, which is a copy (and not a proxy) of other.
  */
  fullVector(const fullVector<scalar> &other) : _r(other._r),_own_data(1)
  {
    _data = new scalar[_r];
    for(int i = 0; i < _r; ++i) _data[i] = other._data[i];
  }

  /**
     Deletes this fullVector.
  */
  ~fullVector()
  {
    if(_own_data && _data) delete [] _data;
  }

  // get information (size, value)
  /**
     @return Returns the size of this fullVector
  */
  inline int size()                  const { return _r; }

  /**
     @return Returns a const pointer to this fullVector data.@n
     This pointer will point to the following memory segment:
     [(*this)(0), (*this)(1), ..., (*this)(this->size() - 1)].
  */
  inline const scalar * getDataPtr() const { return _data; }

  /**
     @return Returns a  pointer to this fullVector data.@n
     This pointer will point to the following memory segment:
     [(*this)(0), (*this)(1), ..., (*this)(this->size() - 1)].
  */
  inline scalar * getDataPtr() { return _data; }

  /**
     @param i A vector index between 0 and size() - 1.
     @returns Returns the ith scalar of this fullVector.
  */
  inline scalar operator () (int i)  const { return _data[i]; }

  /**
     @param i A vector index between 0 and size() - 1.
     @returns Returns a reference to the ith scalar of this fullVector.
  */
  inline scalar & operator () (int i)      { return _data[i]; }

  // copy
  /**
     @param other A fullVector.

     The right hand side fullVector will become a copy of other,
     and will loose its previous data.
  */
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

  void copy(const fullVector<scalar> &v, int i0, int ni, int desti0)
  {
    for(int i = i0, desti = desti0; i < i0 + ni; i++, desti++)
      (*this)(desti) = v(i);
  }

  // set
  /**
     @param r A vector index between 0 and size() - 1;
     @param v A scalar.

     The rth value of this fullVector is set to v.
  */
  inline void set(int r, scalar v){
    #ifdef _DEBUG
    if (r >= _r || r < 0)
      Msg::Fatal("invalid index to access fullVector : %i (size = %i)",
                 r, _r);
    #endif
    (*this)(r) = v;
  }

  // operations
  /**
     @return Returns the @f$ L^2 @f$ norm of this fullVector.
  */
  inline scalar norm() const
  {
    scalar n = 0.;
    for(int i = 0; i < _r; ++i) n += _data[i] * _data[i];
    return sqrt(n);
  }

  /**
     @param r A positive integer;
     @param resetValue A boolean (with default value equals to true).

     Resizes this fullVector to r. Previous data may be damaged.@n
     If resetValue is true, the fullVector data are set to zero.@n
     If this fullVector was a proxy, it now owns its data.

     @return Returns:
     @li true if the previous data are damaged;
     @li false if not (except if resetValue is true).

     @warning
     Nicolas: I'm not sure if this is exactly what resize does !

     @todo
     Check doc of fullVector::resize()
  */
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

  /**
     @param original A fullVector;
     @param r_start A valid index of original;
     @param r A number between 0 and original.size() - r_start.

     This fullVector becomes a proxy of original, that is:
     [original(r_start), ..., original(r_start + r - 1)].

     Previous data are lost.
  */
  void setAsProxy(const fullVector<scalar> &original, int r_start, int r)
  {
    if(_own_data && _data) delete [] _data;
    _own_data = false;
    _r = r;
    _data = original._data + r_start;
  }

  /**
     @param original A fullMatrix;
     @param c A valid column index of original.

     This fullVector becomes a proxy of original cth row, that is:
     [original(0, c), ..., original(original.size1() - 1, c)].

     Previous data are lost.
  */
  void setAsProxy(const fullMatrix<scalar> &original, int c)
  {
    if(_own_data && _data) delete [] _data;
    _own_data = false;
    _r = original._r;
    _data = original._data + c * _r;
  }

  /**
     @param s A scalar.

     Multiplies all the data of this fullVector by s.
  */
  inline void scale(const scalar s)
  {
    if(s == scalar(0.))
      for(int i = 0; i < _r; ++i) _data[i] = scalar(0.);
    else if (s == -1.)
      for(int i = 0; i < _r; ++i) _data[i] = -_data[i];
    else
      for(int i = 0; i < _r; ++i) _data[i] *= s;
  }

  /**
     @param m A scalar.

     Sets all the data of this fullVector to m.
  */
  inline void setAll(const scalar &m)
  {
    for(int i = 0; i < _r; i++) set(i,m);
  }

  /**
     @param m A fullVector.

     If:
     @li @f$ v @f$ is this fullVector;
     @li @f$ N @f$ is equal to this fullVector size,

     then:
     @f$ v(i) = m(i) \qquad \forall{} i \in \{0, \dots, N - 1\} @f$.

     m.size() must be greater or equal to @f$ N @f$.
  */
  void setAll(const fullVector<scalar> &m)
#if !defined(HAVE_BLAS)
  {
    for(int i = 0; i < _r; i++) _data[i] = m._data[i];
  }
#endif
  ;

  /**
     @param other A fullVector.

     @return Returns the scalar product of this fullVector with the other.
  */
  inline scalar operator *(const fullVector<scalar> &other)
  {
    scalar s = 0.;
    for(int i = 0; i < _r; ++i) s += _data[i] * other._data[i];
    return s;
  }

  /**
     @param x A fullVector;
     @param alpha A scalar (by default set to one).

     If:
     @li @f$ v @f$ is this fullVector;
     @li @f$ N @f$ is equal to this fullVector size,

     then:
     @f$ v(i) = v(i) + alpha \times{} x(i) \qquad
     \forall{} i \in \{0, \dots, N - 1\} @f$.

     x.size() must be greater or equal to @f$ N @f$.
  */
  void axpy(const fullVector<scalar> &x, scalar alpha=1.)
#if !defined(HAVE_BLAS)
  {
    for (int i = 0; i < _r; i++) _data[i] += alpha * x._data[i];
  }
#endif
  ;

  /**
     @param x A fullVector.

     If:
     @li @f$ v @f$ is this fullVector;
     @li @f$ N @f$ is equal to this fullVector size,

     then:
     @f$ v(i) = v(i) \times{} x(i) \qquad
     \forall{} i \in \{0, \dots, N - 1\} @f$.

     x.size() must be greater or equal to @f$ N @f$.
  */
  void multTByT(const fullVector<scalar> &x)
  {
    for (int i = 0; i < _r; i++) _data[i] *= x._data[i];
  }

  // printing and file treatment
  /**
     @param name A string in @c C style (set by default to "").

     Prints on the standard output a string describing
     this fullVector.

     This string starts by name.
  */
  void print(const char *name="") const
  {
    printf("double %s[%d]=\n", name,size());
    printf("{  ");
    for(int I = 0; I < size(); I++){
      printf("%12.5E ", (*this)(I));
    }
    printf("};\n");
  }

  /**
     @param f A pointer to a FILE stream.

     Writes a binary representation of this fullVector
     into f.
  */
  void binarySave (FILE *f) const
  {
    fwrite (_data, sizeof(scalar), _r, f);
  }

  /**
     @param f A pointer to a FILE stream containing a fullVector.

     Loads a binary representation, of the fullVector in f,
     into this fullVector.

     @see fullVector::binarySave
  */
  void binaryLoad (FILE *f)
  {
    if(fread (_data, sizeof(scalar), _r, f) != (size_t)_r) return;
  }

  bool getOwnData() const {return _own_data;};
  void setOwnData(bool ownData) {_own_data = ownData;};
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
  fullMatrix(int r, int c, bool init0 = true) : _r(r), _c(c)
  {
    _data = new scalar[_r * _c];
    _own_data = true;
    if (init0)
      setAll(scalar(0.));
  }
  fullMatrix(int r, int c, scalar *data)
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

  inline const scalar * getDataPtr() const { return _data; }
  inline scalar * getDataPtr() { return _data; }

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
  void reshape(int nbRows, int nbColumns){
    if (nbRows == -1 && nbColumns != -1)
      nbRows = _r * _c / nbColumns;
    if (nbRows != -1 && nbColumns == -1)
      nbColumns = _r * _c / nbRows;
    if (nbRows*nbColumns != size1()*size2())
      Msg::Error("Invalid reshape, total number of entries must be equal (new %i x %i != old %i x %i)", nbRows, nbColumns, size1(), size2());
    _r = nbRows;
    _c = nbColumns;
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
  void setAsProxy(scalar *data, int r, int c)
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
            scalar alpha=1., scalar beta=1., bool transposeA = false, bool transposeB = false)
#if !defined(HAVE_BLAS)
  {
    gemm_naive(transposeA ? a.transpose() : a, transposeB ? b.transpose() : b, alpha, beta);
  }
#endif
  ;
  inline void setAll(const scalar &m)
  {
    for(int i = 0; i < _r * _c; i++) _data[i] = m;
  }
  void setAll(const fullMatrix<scalar> &m)
#if !defined(HAVE_BLAS)
  {
    if (_r != m._r || _c != m._c )
      Msg::Fatal("fullMatrix size does not match");
    for(int i = 0; i < _r * _c; i++) _data[i] = m._data[i];
  }
#endif
  ;
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
    Msg::Error("LU factorization and substitution requires LAPACK");
    return false;
  }
#endif
  ;
 bool luFactor(fullVector<int> &ipiv)
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("LU factorization requires LAPACK");
    return false;
  }
#endif
  ;
 bool luSubstitute(const fullVector<scalar> &rhs, fullVector<int> &ipiv, fullVector<scalar> &result)
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("LU substitution requires LAPACK");
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
  bool invert(fullMatrix<scalar> &result) const;

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
  scalar determinant() const;

  bool svd(fullMatrix<scalar> &V, fullVector<scalar> &S)
#if !defined(HAVE_LAPACK)
  {
    Msg::Error("Singular value decomposition requires LAPACK");
    return false;
  }
#endif
  ;

  void print(const std::string name = "", const std::string format = "") const;

  void binarySave (FILE *f) const
  {
    fwrite (_data, sizeof(scalar), _r*_c, f);
  }
  void binaryLoad (FILE *f)
  {
    if(fread (_data, sizeof(scalar), _r*_c, f) != (size_t)_r) return;
  }

  // specific functions for dgshell
  void mult_naiveBlock(const fullMatrix<scalar> &b, const int ncol, const int fcol,
                       const int alpha, const int beta, fullVector<scalar> &c,
                       const int row=0) const
  {
    if(beta != 1)
      c.scale(beta);
    for(int j = fcol; j < fcol+ncol; j++)
      for(int k = 0; k < _c ; k++)
          c._data[j] += alpha*(*this)(row, k) * b(k, j);
  }
  void multOnBlock(const fullMatrix<scalar> &b, const int ncol, const int fcol,
                   const int alpha, const int beta, fullVector<scalar> &c) const
#if !defined(HAVE_BLAS)
  {
    mult_naiveBlock(b,ncol,fcol,alpha,beta,c);
  }
#endif
  ;

  void multWithATranspose(const fullVector<scalar> &x, scalar alpha, scalar beta,
                          fullVector<scalar> &y) const
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

  bool getOwnData() const {return _own_data;};
  void setOwnData(bool ownData) {_own_data = ownData;};
};
#endif
