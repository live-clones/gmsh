// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FULL_MATRIX_H
#define FULL_MATRIX_H

#include "GmshConfig.h"
#include "GmshMessage.h"
#include <cmath>
#include <cstdio>
#include <complex>
#include <iostream>

#if defined(HAVE_EIGEN)
#ifdef Success // in X11 header X.h
#undef Success
#endif
#include <sstream>
#include <Eigen/Dense>
#endif

template <class scalar> class fullMatrix;

// An interface for vectors of scalars (real or complex, with simple or double
// precision). The first index of a fullVector is 0. fullVectors can own their
// scalars, or just be an access point to an other fullVector; such a fullVector
// is called a proxy.

template <class scalar> class fullVector {
private:
  int _r; // size of the vector
  scalar *_data; // pointer on the first element
  bool _ownData;
  friend class fullMatrix<scalar>;

#if defined(HAVE_EIGEN)
  typedef Eigen::Map<Eigen::Matrix<scalar, Eigen::Dynamic, 1> > EigenVec;
#endif

public:
  // Instantiate a zero size fullVector
  fullVector(void) : _r(0), _data(0), _ownData(1) {}
  // Instantiate a fullVector of size r filled with zeros
  fullVector(int r) : _r(r), _ownData(1)
  {
    _data = new scalar[_r];
    setAll(scalar(0.));
  }
  // Instantiate a proxy fullVector given by [original[0], original[1], ...,
  // original[r - 1]]
  fullVector(scalar *original, int r)
  {
    _r = r;
    _ownData = false;
    _data = original;
  }
  // Instantiate a fullVector, which is a copy (and not a proxy) of other
  fullVector(const fullVector<scalar> &other) : _r(other._r), _ownData(1)
  {
    _data = new scalar[_r];
    for(int i = 0; i < _r; ++i) _data[i] = other._data[i];
  }
  ~fullVector()
  {
    if(_ownData && _data) delete[] _data;
  }
  inline int size() const { return _r; }
  inline const scalar *getDataPtr() const { return _data; }
  inline scalar *getDataPtr() { return _data; }
  inline scalar operator()(int i) const { return _data[i]; }
  inline scalar &operator()(int i) { return _data[i]; }
  fullVector<scalar> &operator=(const fullVector<scalar> &other)
  {
    if(this != &other) {
      if((!resize(other._r, false) && _r > 2 * other._r)) {
        if(_data) delete[] _data;
        _r = other._r;
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
  inline void set(int r, scalar v)
  {
#ifdef _DEBUG
    if(r >= _r || r < 0) {
      Msg::Error("Invalid index in vector: %i (size = %i)", r, _r);
      return;
    }
#endif
    (*this)(r) = v;
  }
  // Return the L^2 norm
  scalar norm() const;
  bool resize(int r, bool resetValue = true)
  {
    if(_r < r || !_ownData) {
      if(_ownData && _data) delete[] _data;
      _r = r;
      _data = new scalar[_r];
      _ownData = true;
      if(resetValue) setAll(scalar(0.));
      return true;
    }
    _r = r;
    if(resetValue) setAll(scalar(0.));
    return false;
  }
  // this fullVector becomes a proxy of original, that is: [original(r_start),
  // ..., original(r_start + r - 1)]. Previous data are lost
  void setAsProxy(const fullVector<scalar> &original, int r_start, int r)
  {
    if(_ownData && _data) delete[] _data;
    _ownData = false;
    _r = r;
    _data = original._data + r_start;
  }
  // This fullVector becomes a proxy of original matrix cth row, that is:
  // [original(0, c), ..., original(original.size1() - 1, c)]. Previous data are
  // lost
  void setAsProxy(const fullMatrix<scalar> &original, int c)
  {
    if(_ownData && _data) delete[] _data;
    _ownData = false;
    _r = original._r;
    _data = original._data + c * _r;
  }
  // This fullVector becomes a proxy of the array. Previous data are lost
  void setAsProxy(scalar *data, int r)
  {
    if(_ownData && _data) delete[] _data;
    _ownData = false;
    _r = r;
    _data = data;
  }
  inline void scale(const scalar s)
  {
#if defined(HAVE_EIGEN)
    EigenVec vv(_data, _r);
    vv *= s;
#else
    if(s == scalar(0.))
      for(int i = 0; i < _r; ++i) _data[i] = scalar(0.);
    else if(s == -1.)
      for(int i = 0; i < _r; ++i) _data[i] = -_data[i];
    else
      for(int i = 0; i < _r; ++i) _data[i] *= s;
#endif
  }
  inline void setAll(const scalar &m)
  {
#if defined(HAVE_EIGEN)
    EigenVec vv(_data, _r);
    vv.setConstant(m);
#else
    for(int i = 0; i < _r; i++) set(i, m);
#endif
  }
  void setAll(const fullVector<scalar> &m)
#if defined(HAVE_EIGEN)
  {
    EigenVec vv(_data, _r);
    EigenVec vm(m._data, m._r);
    vv = vm;
  }
#elif !defined(HAVE_BLAS)
  {
    for(int i = 0; i < _r; i++) _data[i] = m._data[i];
  }
#endif
  ;
  // Scalar product
  inline scalar operator*(const fullVector<scalar> &other)
  {
#if defined(HAVE_EIGEN)
    EigenVec vv(_data, _r), vother(other._data, other._r);
    scalar s = vv.dot(vother);
#else
    scalar s = 0.;
    for(int i = 0; i < _r; ++i) s += _data[i] * other._data[i];
    return s;
#endif
  }
  // v(i) = v(i) + alpha * x(i)
  void axpy(const fullVector<scalar> &x, scalar alpha = 1.)
#if defined(HAVE_EIGEN)
  {
    EigenVec vv(_data, _r), vx(x._data, x._r);
    vv.noalias() += alpha * vx;
  }
#elif !defined(HAVE_BLAS)
  {
    for(int i = 0; i < _r; i++) _data[i] += alpha * x._data[i];
  }
#endif
  ;
  // v(i) = v(i) * x(i)
  void multTByT(const fullVector<scalar> &x)
  {
    for(int i = 0; i < _r; i++) _data[i] *= x._data[i];
  }
  void print(const std::string name = "", const std::string format = "") const;
  void binarySave(FILE *f) const { fwrite(_data, sizeof(scalar), _r, f); }
  void binaryLoad(FILE *f)
  {
    if(fread(_data, sizeof(scalar), _r, f) != (size_t)_r) return;
  }
  bool getOwnData() const { return _ownData; };
  void setOwnData(bool ownData) { _ownData = ownData; };
};

// An interface for dense matrix of scalars (real or complex, with simple or
// double precision)

template <class scalar> class fullMatrix {
private:
  bool _ownData; // should data be freed on delete?
  int _r, _c; // size of the matrix
  scalar *_data; // pointer on the first element
  friend class fullVector<scalar>;

#if defined(HAVE_EIGEN)
  typedef Eigen::Map<Eigen::Matrix<scalar, Eigen::Dynamic, Eigen::Dynamic> > EigenMat;
  typedef Eigen::Map<Eigen::Matrix<scalar, Eigen::Dynamic, 1> > EigenVec;
#endif

public:
  fullMatrix(scalar *original, int r, int c)
  {
    _r = r;
    _c = c;
    _ownData = false;
    _data = original;
  }
  fullMatrix(fullMatrix<scalar> &original, int c_start, int c)
  {
    _c = c;
    _r = original._r;
    _ownData = false;
    _data = original._data + c_start * _r;
  }
  fullMatrix(int r, int c, bool init0 = true) : _r(r), _c(c)
  {
    _data = new scalar[_r * _c];
    _ownData = true;
    if(init0) setAll(scalar(0.));
  }
  fullMatrix(int r, int c, scalar *data)
    : _r(r), _c(c), _data(data), _ownData(false)
  {
    setAll(scalar(0.));
  }
  fullMatrix(const fullMatrix<scalar> &other) : _r(other._r), _c(other._c)
  {
    _data = new scalar[_r * _c];
    _ownData = true;
    for(int i = 0; i < _r * _c; ++i) _data[i] = other._data[i];
  }
  fullMatrix() : _ownData(false), _r(0), _c(0), _data(0) {}
  ~fullMatrix()
  {
    if(_data && _ownData) delete[] _data;
  }
  // get information (size, value)
  inline int size1() const { return _r; }
  inline int size2() const { return _c; }
  inline scalar get(int r, int c) const
  {
#ifdef _DEBUG
    if(r >= _r || r < 0 || c >= _c || c < 0) {
      Msg::Error("Invalid index in dense matrix: %i %i (size = %i %i)", r, c,
                 _r, _c);
      return 0;
    }
#endif
    return (*this)(r, c);
  }
  inline const scalar *getDataPtr() const { return _data; }
  inline scalar *getDataPtr() { return _data; }
  inline void set(int r, int c, scalar v)
  {
#ifdef _DEBUG
    if(r >= _r || r < 0 || c >= _c || c < 0) {
      Msg::Error("Invalid index in dense matrix: %i %i (size = %i %i)", r, c,
                 _r, _c);
      return;
    }
#endif
    (*this)(r, c) = v;
  }
  inline scalar norm() const
  {
    scalar n = 0.;
    for(int i = 0; i < _r; ++i)
      for(int j = 0; j < _c; ++j) n += (*this)(i, j) * (*this)(i, j);
    return sqrt(n);
  }
  bool resize(int r, int c, bool resetValue = true)
  {
    // data will be owned (same as constructor)
    if((r * c > _r * _c) || !_ownData) {
      if(_ownData && _data) delete[] _data;
      _r = r;
      _c = c;
      _data = new scalar[_r * _c];
      _ownData = true;
      if(resetValue) setAll(scalar(0.));
      return true;
    }
    _r = r;
    _c = c;
    if(resetValue) setAll(scalar(0.));
    return false; // no reallocation
  }
  void reshape(int nbRows, int nbColumns)
  {
    if(nbRows == -1 && nbColumns != -1) nbRows = _r * _c / nbColumns;
    if(nbRows != -1 && nbColumns == -1) nbColumns = _r * _c / nbRows;
    if(nbRows * nbColumns != _r * _c)
      Msg::Error("Invalid dense matrix reshape: total number of entries must "
                 "be equal (new %i x %i != old %i x %i)",
                 nbRows, nbColumns, _r, _c);
    _r = nbRows;
    _c = nbColumns;
  }
  void setAsProxy(const fullMatrix<scalar> &original)
  {
    if(_data && _ownData) delete[] _data;
    _c = original._c;
    _r = original._r;
    _ownData = false;
    _data = original._data;
  }
  void setAsProxy(const fullMatrix<scalar> &original, int c_start, int c)
  {
    if(_data && _ownData) delete[] _data;
    _c = c;
    _r = original._r;
    _ownData = false;
    _data = original._data + c_start * _r;
  }
  void setAsProxy(scalar *data, int r, int c)
  {
    if(_data && _ownData) delete[] _data;
    _c = c;
    _r = r;
    _ownData = false;
    _data = data;
  }
  fullMatrix<scalar> &operator=(const fullMatrix<scalar> &other)
  {
    copy(other);
    return *this;
  }
  void operator+=(const fullMatrix<scalar> &other)
  {
    if(_r != other._r || _c != other._c) {
      Msg::Error("Cannot sum dense matrices of different sizes");
      return;
    }
    for(int i = 0; i < _r * _c; ++i) _data[i] += other._data[i];
  }
  inline scalar operator()(int i, int j) const
  {
#ifdef _DEBUG
    if(i >= _r || i < 0 || j >= _c || j < 0) {
      Msg::Error("Invalid index to access dense matrix: %i %i (size = %i %i)",
                 i, j, _r, _c);
      return 0;
    }
#endif
    return _data[i + _r * j];
  }
  inline scalar &operator()(int i, int j)
  {
#ifdef _DEBUG
    if(i >= _r || i < 0 || j >= _c || j < 0) {
      Msg::Error("Invalid index to access dense matrix: %i %i (size = %i %i)",
                 i, j, _r, _c);
      return _data[0];
    }
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
    if(_data && !_ownData) {
      Msg::Error("Dense matrix copy prohibited for proxies, use setAll "
                 "instead");
      return;
    }
    if(_r != a._r || _c != a._c) {
      if(_data && _ownData) delete[] _data;
      _r = a._r;
      _c = a._c;
      _data = new scalar[_r * _c];
      _ownData = true;
    }
    setAll(a);
  }
  void copyOneColumn(const fullVector<scalar> &x, const int ind) const
  {
    int cind = _c * ind;
    for(int i = 0; i < _r; i++) _data[cind + i] = x(i);
  }
  inline void setAll(const scalar &m)
  {
#if defined(HAVE_EIGEN)
    EigenMat ma(_data, _r, _c);
    ma.setConstant(m);
#else
    for(int i = 0; i < _r * _c; i++) _data[i] = m;
#endif
  }
  void setAll(const fullMatrix<scalar> &m)
#if defined(HAVE_EIGEN)
  {
    EigenMat ma(_data, _r, _c), mm(m._data, m._r, m._c);
    ma = mm;
  }
#elif !defined(HAVE_BLAS)
  {
    if(_r != m._r || _c != m._c) {
      Msg::Error("Dense matrix sizes do not match in setAll");
      return;
    }
    for(int i = 0; i < _r * _c; i++) _data[i] = m._data[i];
  }
#endif
  ;
  void scale(const double s)
#if defined(HAVE_EIGEN)
  {
    EigenMat ma(_data, _r, _c);
    ma *= s;
  }
#elif !defined(HAVE_BLAS)
  {
    if(s == 0.) // this is not really correct nan*0 (or inf*0) is expected to
                // give nan
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
#if defined(HAVE_EIGEN)
    EigenMat ma(_data, _r, _c), mm(m._data, m._r, m._c);
    ma.noalias() += mm;
#else
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++) (*this)(i, j) += m(i, j);
#endif
  }
  inline void add(const fullMatrix<scalar> &m, const double &a)
  {
#if defined(HAVE_EIGEN)
    EigenMat ma(_data, _r, _c), mm(m._data, m._r, m._c);
    ma.noalias() += a * mm;
#else
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++) (*this)(i, j) += a * m(i, j);
#endif
  }
  void mult(const fullVector<scalar> &x, fullVector<scalar> &y) const
#if defined(HAVE_EIGEN)
  {
    EigenMat ma(_data, _r, _c);
    EigenVec vx(x._data, x._r), vy(y._data, y._r);
    vy = ma * vx;
  }
#elif !defined(HAVE_BLAS)
  {
    y.scale(scalar(0.));
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++) y._data[i] += (*this)(i, j) * x(j);
  }
#endif
  ;
  void multAddy(const fullVector<scalar> &x, fullVector<scalar> &y) const
#if defined(HAVE_EIGEN)
  {
    EigenMat ma(_data, _r, _c);
    EigenVec vx(x._data, x._r), vy(y._data, y._r);
    vy += ma * vx;
  }
#elif !defined(HAVE_BLAS)
  {
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++) y._data[i] += (*this)(i, j) * x(j);
  }
#endif
  ;
  void mult(const fullMatrix<scalar> &b, fullMatrix<scalar> &c) const
#if defined(HAVE_EIGEN)
  {
    EigenMat ma(_data, _r, _c), mb(b._data, b._r, b._c), mc(c._data, c._r, c._c);
    mc.noalias() = ma * mb;
  }
#elif !defined(HAVE_BLAS)
  {
    c.scale(scalar(0.));
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < b._c; j++)
        for(int k = 0; k < _c; k++)
          c._data[i + _r * j] += (*this)(i, k) * b(k, j);
  }
#endif
  ;
  void multTByT(const fullMatrix<scalar> &a)
  {
    for(int i = 0; i < _r * _c; i++) _data[i] *= a._data[i];
  }
  void multOnBlock(const fullMatrix<scalar> &b, const int ncol, const int fcol,
                   const int alpha, const int beta, fullVector<scalar> &c) const
#if defined(HAVE_EIGEN) || !defined(HAVE_BLAS)
  {
    int row = 0;
    if(beta != 1) c.scale(beta);
    for(int j = fcol; j < fcol + ncol; j++)
      for(int k = 0; k < _c; k++)
        c._data[j] += alpha * (*this)(row, k) * b(k, j);
  }
#endif
  ;
  void multWithATranspose(const fullVector<scalar> &x, scalar alpha,
                          scalar beta, fullVector<scalar> &y) const
#if defined(HAVE_EIGEN) || !defined(HAVE_BLAS)
  {
    y.scale(beta);
    for(int j = 0; j < _c; j++)
      for(int i = 0; i < _r; i++) y._data[j] += alpha * (*this)(i, j) * x(i);
  }
#endif
  ;
  inline fullMatrix<scalar> transpose() const
  {
    fullMatrix<scalar> T(_c, _r);
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < _c; j++) T(j, i) = (*this)(i, j);
    return T;
  }
  inline void transposeInPlace()
  {
    if(_r != _c) {
      Msg::Error("In-place transposition requires a square matrix "
                 "(size = %d %d)", _r, _c);
      return;
    }
    scalar t;
    for(int i = 0; i < _r; i++)
      for(int j = 0; j < i; j++) {
        t = _data[i + _r * j];
        _data[i + _r * j] = _data[j + _r * i];
        _data[j + _r * i] = t;
      }
  }
  void gemm(const fullMatrix<scalar> &a, const fullMatrix<scalar> &b,
            scalar alpha = 1., scalar beta = 1., bool transposeA = false,
            bool transposeB = false)
#if defined(HAVE_EIGEN) || !defined(HAVE_BLAS)
  {
    const fullMatrix<scalar> &A = transposeA ? a.transpose() : a;
    const fullMatrix<scalar> &B = transposeA ? b.transpose() : b;
    fullMatrix<scalar> temp(A._r, B._c);
    A.mult(B, temp);
    temp.scale(alpha);
    scale(beta);
    add(temp);
  }
#endif
  ;
  void axpy(const fullMatrix<scalar> &x, scalar alpha = 1.)
#if defined(HAVE_EIGEN) || !defined(HAVE_BLAS)
  {
    int n = _r * _c;
    for(int i = 0; i < n; i++) _data[i] += alpha * x._data[i];
  }
#endif
  ;
  bool luSolve(const fullVector<scalar> &rhs, fullVector<scalar> &result)
#if defined(HAVE_EIGEN)
  {
    if(_r != _c || _r != rhs._r || _r != result._r) {
      Msg::Error("Wrong sizes for dense linear system solve (size = %d %d, "
                 "%d, %d)", _r, _c, result._r, rhs._r);
      return false;
    }
    EigenMat ma(_data, _r, _c);
    EigenVec vb(rhs._data, rhs._r);
    EigenVec vx(result._data, result._r);
    vx = ma.colPivHouseholderQr().solve(vb);
    return true;
  }
#elif !defined(HAVE_LAPACK)
  {
    Msg::Error("LU factorization and substitution requires Eigen or LAPACK");
    return false;
  }
#endif
  ;
  bool luFactor(fullVector<int> &ipiv)
#if defined(HAVE_EIGEN) || !defined(HAVE_LAPACK)
  {
    Msg::Error("LU factorization requires LAPACK");
    return false;
  }
#endif
  ;
  bool luSubstitute(const fullVector<scalar> &rhs, fullVector<int> &ipiv,
                    fullVector<scalar> &result)
#if defined(HAVE_EIGEN) || !defined(HAVE_LAPACK)
  {
    Msg::Error("LU substitution requires LAPACK");
    return false;
  }
#endif
  ;
  bool invert(fullMatrix<scalar> &result) const
#if defined(HAVE_EIGEN)
  {
    if(_r != _c) {
      Msg::Error("Dense matrix inverse requires square matrix (size = %d %d)",
                 _r, _c);
      return false;
    }
    result.resize(_r, _c);
    EigenMat ma(_data, _r, _c);
    EigenMat mi(result._data, _r, _c);
    mi = ma.inverse();
    return true;
  }
#elif !defined(HAVE_LAPACK)
  {
    Msg::Error("Matrix inversion requires Eigen or LAPACK");
    return false;
  }
#endif
  ;
  bool invertInPlace()
#if defined(HAVE_EIGEN)
  {
    if(_r != _c) {
      Msg::Error("Dense matrix inversion requires square matrix (size = %d %d)",
                 _r, _c);
      return false;
    }
    EigenMat ma(_data, _r, _c);
    ma = ma.inverse();
    return true;
  }
#elif !defined(HAVE_LAPACK)
  {
    Msg::Error("Dense matrix inversion requires LAPACK");
    return false;
  }
#endif
  ;
  scalar determinant() const
#if defined(HAVE_EIGEN)
  {
    EigenMat ma(_data, _r, _c);
    return ma.determinant();
  }
#elif !defined(HAVE_LAPACK)
  {
    Msg::Error("Dense matrix inversion requires Eigen or LAPACK");
    return false;
  }
#endif
  ;
  void swap(scalar *a, int inca, scalar *b, int incb, int n)
  {
    scalar tmp;
    for(int i = 0; i < n; i++, a += inca, b += incb) {
      tmp = (*a);
      (*a) = (*b);
      (*b) = tmp;
    }
  }
  void eigSort(int n, scalar *wr, scalar *wi, scalar *VL, scalar *VR)
  {
    // Sort the eigenvalues/vectors in ascending order according to
    // their real part. Warning: this will screw up the ordering if we
    // have complex eigenvalues.
    for(int i = 0; i < n - 1; i++) {
      int k = i;
      scalar ek = wr[i];
      // search for something to swap
      for(int j = i + 1; j < n; j++) {
        const scalar ej = wr[j];
        if(ej < ek) {
          k = j;
          ek = ej;
        }
      }
      if(k != i) {
        swap(&wr[i], 1, &wr[k], 1, 1);
        swap(&wi[i], 1, &wi[k], 1, 1);
        swap(&VL[n * i], 1, &VL[n * k], 1, n);
        swap(&VR[n * i], 1, &VR[n * k], 1, n);
      }
    }
  }
  bool eig(fullVector<double> &eigenValReal, fullVector<double> &eigenValImag,
           fullMatrix<scalar> &leftEigenVect, fullMatrix<scalar> &rightEigenVect,
           bool sortRealPart = false)
#if defined(HAVE_EIGEN)
  {
    EigenMat ma(_data, _r, _c);
    Eigen::EigenSolver<Eigen::Matrix<scalar, Eigen::Dynamic, Eigen::Dynamic> > es(ma);
    if(es.info() != Eigen::Success) {
      Msg::Warning("Eigen could not compute eigenvalues/eigenvectors");
      return false;
    }
    EigenVec vr(eigenValReal._data, eigenValReal._r);
    vr = es.eigenvalues().real();
    EigenVec vi(eigenValImag._data, eigenValImag._r);
    vi = es.eigenvalues().imag();
    EigenMat mr(rightEigenVect._data, rightEigenVect._r, rightEigenVect._c);
    mr = es.eigenvectors().real();
    EigenMat ml(leftEigenVect._data, leftEigenVect._r, leftEigenVect._c);
    // FIXME: compute the true left eigenvectors!
    ml = mr.transpose();
    if(sortRealPart)
      eigSort(_r, eigenValReal._data, eigenValImag._data,
              leftEigenVect._data, rightEigenVect._data);
    return true;
  }
#elif !defined(HAVE_LAPACK)
  {
    Msg::Error("Eigenvalue computation of dense matrices requires Eigen or "
               "LAPACK");
    return false;
  }
#endif
  ;
  bool svd(fullMatrix<scalar> &V, fullVector<scalar> &S)
#if defined(HAVE_EIGEN)
  {
    EigenMat ma(_data, _r, _c);
    EigenMat mv(V._data, V._r, V._c);
    EigenVec vs(S._data, S._r);
    Eigen::BDCSVD
      <Eigen::Matrix<scalar, Eigen::Dynamic, Eigen::Dynamic> >
      svd(ma, Eigen::ComputeThinU | Eigen::ComputeThinV);
    ma = svd.matrixU();
    mv = svd.matrixV();
    vs = svd.singularValues();
    return true;
  }
#elif !defined(HAVE_LAPACK)
  {
    Msg::Error("Singular value decomposition of dense matrices requires "
               "Eigen or LAPACK");
    return false;
  }
#endif
  ;
  void print(const std::string &name = "",
             const std::string &format = "") const;
  void binarySave(FILE *f) const { fwrite(_data, sizeof(scalar), _r * _c, f); }
  void binaryLoad(FILE *f)
  {
    if(fread(_data, sizeof(scalar), _r * _c, f) != (size_t)_r) return;
  }
  bool getOwnData() const { return _ownData; };
  void setOwnData(bool ownData) { _ownData = ownData; };
};

#endif
