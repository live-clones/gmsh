// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <complex>
#include <string.h>
#include <algorithm>
#include "GmshConfig.h"
#include "fullMatrix.h"
#include "GmshMessage.h"

#if !defined(F77NAME)
#define F77NAME(x) (x##_)
#endif

// Specialisation of fullVector/Matrix operations using BLAS and LAPACK

#if defined(HAVE_BLAS) && !defined(HAVE_EIGEN)

extern "C" {
void F77NAME(daxpy)(int *n, double *alpha, double *x, int *incx, double *y,
                    int *incy);
void F77NAME(zaxpy)(int *n, std::complex<double> *alpha,
                    std::complex<double> *x, int *incx, std::complex<double> *y,
                    int *incy);
void F77NAME(dcopy)(int *n, double *a, int *inca, double *b, int *incb);
void F77NAME(zcopy)(int *n, std::complex<double> *a, int *inca,
                    std::complex<double> *b, int *incb);
void F77NAME(dgemm)(const char *transa, const char *transb, int *m, int *n,
                    int *k, double *alpha, double *a, int *lda, double *b,
                    int *ldb, double *beta, double *c, int *ldc);
void F77NAME(zgemm)(const char *transa, const char *transb, int *m, int *n,
                    int *k, std::complex<double> *alpha,
                    std::complex<double> *a, int *lda, std::complex<double> *b,
                    int *ldb, std::complex<double> *beta,
                    std::complex<double> *c, int *ldc);
void F77NAME(dgemv)(const char *trans, int *m, int *n, double *alpha, double *a,
                    int *lda, double *x, int *incx, double *beta, double *y,
                    int *incy);
void F77NAME(zgemv)(const char *trans, int *m, int *n,
                    std::complex<double> *alpha, std::complex<double> *a,
                    int *lda, std::complex<double> *x, int *incx,
                    std::complex<double> *beta, std::complex<double> *y,
                    int *incy);
void F77NAME(dscal)(int *n, double *alpha, double *x, int *incx);
void F77NAME(zscal)(int *n, std::complex<double> *alpha,
                    std::complex<double> *x, int *incx);
}

template <> void fullVector<double>::setAll(const fullVector<double> &m)
{
  int stride = 1;
  F77NAME(dcopy)(&_r, m._data, &stride, _data, &stride);
}

template <>
void fullVector<std::complex<double> >::setAll(
  const fullVector<std::complex<double> > &m)
{
  int stride = 1;
  F77NAME(zcopy)(&_r, m._data, &stride, _data, &stride);
}

template <>
void fullVector<double>::axpy(const fullVector<double> &x, double alpha)
{
  int M = _r, INCX = 1, INCY = 1;
  F77NAME(daxpy)(&M, &alpha, x._data, &INCX, _data, &INCY);
}

template <>
void fullVector<std::complex<double> >::axpy(
  const fullVector<std::complex<double> > &x, std::complex<double> alpha)
{
  int M = _r, INCX = 1, INCY = 1;
  F77NAME(zaxpy)(&M, &alpha, x._data, &INCX, _data, &INCY);
}

template <> void fullMatrix<int>::setAll(const fullMatrix<int> &m)
{
  if(_r != m._r || _c != m._c) {
    Msg::Error("fullMatrix size does not match");
    return;
  }
  int N = _r * _c;
  for(int i = 0; i < N; ++i) _data[i] = m._data[i];
}

template <> void fullMatrix<double>::setAll(const fullMatrix<double> &m)
{
  if(_r != m._r || _c != m._c) {
    Msg::Error("fullMatrix size does not match");
    return;
  }
  int N = _r * _c;
  int stride = 1;
  F77NAME(dcopy)(&N, m._data, &stride, _data, &stride);
}

template <>
void fullMatrix<std::complex<double> >::setAll(
  const fullMatrix<std::complex<double> > &m)
{
  if(_r != m._r || _c != m._c) {
    Msg::Error("fullMatrix size does not match");
    return;
  }
  int N = _r * _c;
  int stride = 1;
  F77NAME(zcopy)(&N, m._data, &stride, _data, &stride);
}

template <> void fullMatrix<double>::scale(const double s)
{
  int N = _r * _c;
  int stride = 1;
  double ss = s;
  F77NAME(dscal)(&N, &ss, _data, &stride);
}

template <> void fullMatrix<std::complex<double> >::scale(const std::complex<double> s)
{
  int N = _r * _c;
  int stride = 1;
  std::complex<double> ss(s);
  F77NAME(zscal)(&N, &ss, _data, &stride);
}

template <> void fullMatrix<int>::scale(const int s)
{
  for(int i = 0; i < _r * _c; ++i) _data[i] *= s;
}

template <>
void fullMatrix<double>::mult(const fullMatrix<double> &b,
                              fullMatrix<double> &c) const
{
  int M = c.size1(), N = c.size2(), K = _c;
  int LDA = _r, LDB = b.size1(), LDC = c.size1();
  double alpha = 1., beta = 0.;
  F77NAME(dgemm)
  ("N", "N", &M, &N, &K, &alpha, _data, &LDA, b._data, &LDB, &beta, c._data,
   &LDC);
}

template <>
void fullMatrix<std::complex<double> >::mult(
  const fullMatrix<std::complex<double> > &b,
  fullMatrix<std::complex<double> > &c) const
{
  int M = c.size1(), N = c.size2(), K = _c;
  int LDA = _r, LDB = b.size1(), LDC = c.size1();
  std::complex<double> alpha = 1., beta = 0.;
  F77NAME(zgemm)
  ("N", "N", &M, &N, &K, &alpha, _data, &LDA, b._data, &LDB, &beta, c._data,
   &LDC);
}

template <>
void fullMatrix<double>::mult(const fullVector<double> &x,
                              fullVector<double> &y) const
{
  int M = _r, N = _c, LDA = _r, INCX = 1, INCY = 1;
  double alpha = 1., beta = 0.;
  F77NAME(dgemv)
  ("N", &M, &N, &alpha, _data, &LDA, x._data, &INCX, &beta, y._data, &INCY);
}

template <>
void fullMatrix<std::complex<double> >::mult(
  const fullVector<std::complex<double> > &x,
  fullVector<std::complex<double> > &y) const
{
  int M = _r, N = _c, LDA = _r, INCX = 1, INCY = 1;
  std::complex<double> alpha = 1., beta = 0.;
  F77NAME(zgemv)
  ("N", &M, &N, &alpha, _data, &LDA, x._data, &INCX, &beta, y._data, &INCY);
}

template <>
void fullMatrix<double>::multAddy(const fullVector<double> &x,
                                  fullVector<double> &y) const
{
  int M = _r, N = _c, LDA = _r, INCX = 1, INCY = 1;
  double alpha = 1., beta = 1.;
  F77NAME(dgemv)
  ("N", &M, &N, &alpha, _data, &LDA, x._data, &INCX, &beta, y._data, &INCY);
}

template <>
void fullMatrix<std::complex<double> >::multAddy(
  const fullVector<std::complex<double> > &x,
  fullVector<std::complex<double> > &y) const
{
  int M = _r, N = _c, LDA = _r, INCX = 1, INCY = 1;
  std::complex<double> alpha = 1., beta = 1.;
  F77NAME(zgemv)
  ("N", &M, &N, &alpha, _data, &LDA, x._data, &INCX, &beta, y._data, &INCY);
}

template <>
void fullMatrix<double>::multOnBlock(const fullMatrix<double> &b,
                                     const int ncol, const int fcol,
                                     const int alpha_, const int beta_,
                                     fullVector<double> &c) const
{
  int M = 1, N = ncol, K = b.size1();
  int LDA = _r, LDB = b.size1(), LDC = 1;
  double alpha = alpha_, beta = beta_;
  F77NAME(dgemm)
  ("N", "N", &M, &N, &K, &alpha, _data, &LDA, &(b._data[fcol * K]), &LDB, &beta,
   &(c._data[fcol]), &LDC);
}

template <>
void fullMatrix<double>::multWithATranspose(const fullVector<double> &x,
                                            double alpha, double beta,
                                            fullVector<double> &y) const
{
  int M = _r, N = _c, LDA = _r, INCX = 1, INCY = 1;
  F77NAME(dgemv)
  ("T", &M, &N, &alpha, _data, &LDA, x._data, &INCX, &beta, y._data, &INCY);
}

template <>
void fullMatrix<double>::gemm(const fullMatrix<double> &a,
                              const fullMatrix<double> &b, double alpha,
                              double beta, bool transposeA, bool transposeB)
{
  int M = size1(), N = size2(), K = transposeA ? a.size1() : a.size2();
  int LDA = a.size1(), LDB = b.size1(), LDC = size1();
  F77NAME(dgemm)
  (transposeA ? "T" : "N", transposeB ? "T" : "N", &M, &N, &K, &alpha, a._data,
   &LDA, b._data, &LDB, &beta, _data, &LDC);
}

template <>
void fullMatrix<std::complex<double> >::gemm(
  const fullMatrix<std::complex<double> > &a,
  const fullMatrix<std::complex<double> > &b, std::complex<double> alpha,
  std::complex<double> beta, bool transposeA, bool transposeB)
{
  int M = size1(), N = size2(), K = transposeA ? a.size1() : a.size2();
  int LDA = a.size1(), LDB = b.size1(), LDC = size1();
  F77NAME(zgemm)
  (transposeA ? "T" : "N", transposeB ? "T" : "N", &M, &N, &K, &alpha, a._data,
   &LDA, b._data, &LDB, &beta, _data, &LDC);
}

template <>
void fullMatrix<double>::axpy(const fullMatrix<double> &x, double alpha)
{
  int M = _r * _c, INCX = 1, INCY = 1;
  F77NAME(daxpy)(&M, &alpha, x._data, &INCX, _data, &INCY);
}

#endif

#if defined(HAVE_LAPACK) && !defined(HAVE_EIGEN)

extern "C" {
void F77NAME(dgesv)(int *N, int *nrhs, double *A, int *lda, int *ipiv,
                    double *b, int *ldb, int *info);
void F77NAME(dgetrf)(int *M, int *N, double *A, int *lda, int *ipiv, int *info);
void F77NAME(dgetrs)(char *trans, int *N, int *nrhs, double *A, int *lda,
                     int *ipiv, double *b, int *ldb, int *info);
void F77NAME(dgetri)(int *M, double *A, int *lda, int *ipiv, double *work,
                     int *lwork, int *info);
void F77NAME(dgesvd)(const char *jobu, const char *jobvt, int *M, int *N,
                     double *A, int *lda, double *S, double *U, int *ldu,
                     double *VT, int *ldvt, double *work, int *lwork,
                     int *info);
void F77NAME(dgeev)(const char *jobvl, const char *jobvr, int *n, double *a,
                    int *lda, double *wr, double *wi, double *vl, int *ldvl,
                    double *vr, int *ldvr, double *work, int *lwork, int *info);
}

template <>
bool fullMatrix<double>::luSolve(const fullVector<double> &rhs,
                                 fullVector<double> &result)
{
  int N = size1(), nrhs = 1, lda = N, ldb = N, info;
  int *ipiv = new int[N];
  for(int i = 0; i < N; i++) result(i) = rhs(i);
  F77NAME(dgesv)(&N, &nrhs, _data, &lda, ipiv, result._data, &ldb, &info);
  delete[] ipiv;
  if(info == 0) return true;
  return false;
}

template <> bool fullMatrix<double>::luFactor(fullVector<int> &ipiv)
{
  int M = size1(), N = size2(), lda = size1(), info;
  ipiv.resize(std::min(M, N));
  F77NAME(dgetrf)(&M, &N, _data, &lda, &ipiv(0), &info);
  if(info == 0) return true;
  return false;
}

template <>
bool fullMatrix<double>::luSubstitute(const fullVector<double> &rhs,
                                      fullVector<int> &ipiv,
                                      fullVector<double> &result)
{
  int N = size1(), nrhs = 1, lda = N, ldb = N, info;
  char trans = 'N';
  for(int i = 0; i < N; i++) result(i) = rhs(i);
  F77NAME(dgetrs)
  (&trans, &N, &nrhs, _data, &lda, &ipiv(0), result._data, &ldb, &info);
  if(info == 0) return true;
  return false;
}

template <> bool fullMatrix<double>::invert(fullMatrix<double> &result) const
{
  int M = size1(), N = size2(), lda = size1(), info;
  int *ipiv = new int[std::min(M, N)];
  if(result.size2() != M || result.size1() != N) {
    if(result._ownData || !result._data)
      result.resize(M, N, false);
    else {
      Msg::Error("FullMatrix: Bad dimension, I cannot write in proxy");
      return false;
    }
  }
  result.setAll(*this);
  F77NAME(dgetrf)(&M, &N, result._data, &lda, ipiv, &info);
  if(info == 0) {
    int lwork = M * 4;
    double *work = new double[lwork];
    F77NAME(dgetri)(&M, result._data, &lda, ipiv, work, &lwork, &info);
    delete[] work;
  }
  delete[] ipiv;
  if(info == 0)
    return true;
  else if(info > 0)
    Msg::Warning("U(%d,%d)=0 in matrix inversion", info, info);
  else
    Msg::Error("Wrong %d-th argument in matrix inversion", -info);
  return false;
}

template <> bool fullMatrix<double>::invertInPlace()
{
  int N = size1(), nrhs = N, lda = N, ldb = N, info;
  int *ipiv = new int[N];
  double *invA = new double[N * N];

  for(int i = 0; i < N * N; i++) invA[i] = 0.;
  for(int i = 0; i < N; i++) invA[i * N + i] = 1.;

  F77NAME(dgesv)(&N, &nrhs, _data, &lda, ipiv, invA, &ldb, &info);
  memcpy(_data, invA, N * N * sizeof(double));

  delete[] invA;
  delete[] ipiv;

  if(info == 0) return true;
  if(info > 0)
    Msg::Warning("U(%d,%d)=0 in matrix in place inversion", info, info);
  else
    Msg::Error("Wrong %d-th argument in matrix inversion", -info);
  return false;
}

template <> double fullMatrix<double>::determinant() const
{
  fullMatrix<double> tmp(*this);
  int M = size1(), N = size2(), lda = size1(), info;
  int *ipiv = new int[std::min(M, N)];
  F77NAME(dgetrf)(&M, &N, tmp._data, &lda, ipiv, &info);
  double det = 1.;
  if(info == 0) {
    for(int i = 0; i < size1(); i++) {
      det *= tmp(i, i);
      if(ipiv[i] != i + 1) det = -det;
    }
  }
  else if(info > 0)
    det = 0.;
  else
    Msg::Error("Wrong %d-th argument in matrix factorization", -info);
  delete[] ipiv;
  return det;
}

template <>
bool fullMatrix<double>::eig(fullVector<double> &DR, fullVector<double> &DI,
                             fullMatrix<double> &VL, fullMatrix<double> &VR,
                             bool sortRealPart)
{
  int N = size1(), info;
  int lwork = 10 * N;
  double *work = new double[lwork];
  F77NAME(dgeev)
  ("V", "V", &N, _data, &N, DR._data, DI._data, VL._data, &N, VR._data, &N,
   work, &lwork, &info);
  delete[] work;

  if(info > 0)
    Msg::Error("QR Algorithm failed to compute all the eigenvalues", info,
               info);
  else if(info < 0)
    Msg::Error("Wrong %d-th argument in eig", -info);
  else if(sortRealPart)
    eigSort(N, DR._data, DI._data, VL._data, VR._data);

  return true;
}

template <>
bool fullMatrix<double>::svd(fullMatrix<double> &V, fullVector<double> &S)
{
  fullMatrix<double> VT(V.size2(), V.size1());
  int M = size1(), N = size2(), LDA = size1(), LDVT = VT.size1(), info;
  int lwork = std::max(3 * std::min(M, N) + std::max(M, N), 5 * std::min(M, N));
  fullVector<double> WORK(lwork);
  F77NAME(dgesvd)
  ("O", "A", &M, &N, _data, &LDA, S._data, _data, &LDA, VT._data, &LDVT,
   WORK._data, &lwork, &info);
  V = VT.transpose();
  if(info == 0) return true;
  if(info > 0)
    Msg::Error("SVD did not converge");
  else
    Msg::Error("Wrong %d-th argument in SVD decomposition", -info);
  return false;
}

#endif

// Specialisation of norm() and print()

template <> double fullVector<double>::norm() const
{
  double n = 0.;
  for(int i = 0; i < _r; ++i) n += _data[i] * _data[i];
  return sqrt(n);
}

template <> std::complex<double> fullVector<std::complex<double> >::norm() const
{
  double n = 0.;
  for(int i = 0; i < _r; ++i)
    n += _data[i].real() * _data[i].real() + _data[i].imag() * _data[i].imag();
  return std::complex<double>(sqrt(n), 0.);
}

template <>
void fullVector<double>::print(const std::string name,
                               const std::string format) const
{
  std::string rformat = (format == "") ? "%12.5E " : format;
  printf("double %s[%d]=\n", name.c_str(), size());
  printf("{  ");
  for(int I = 0; I < size(); I++) { printf(rformat.c_str(), (*this)(I)); }
  printf("};\n");
}

template <>
void fullVector<int>::print(const std::string name,
                            const std::string format) const
{
  std::string rformat = (format == "") ? "%12d " : format;
  printf("double %s[%d]=\n", name.c_str(), size());
  printf("{  ");
  for(int I = 0; I < size(); I++) { printf(rformat.c_str(), (*this)(I)); }
  printf("};\n");
}

template <>
void fullMatrix<double>::print(const std::string &name,
                               const std::string &format) const
{
  std::string rformat = (format == "") ? "%12.5E " : format;
  int ni = size1();
  int nj = size2();
  printf("double %s [ %d ][ %d ]= { \n", name.c_str(), ni, nj);
  for(int I = 0; I < ni; I++) {
    printf("{  ");
    for(int J = 0; J < nj; J++) {
      printf(rformat.c_str(), (*this)(I, J));
      if(J != nj - 1) printf(",");
    }
    if(I != ni - 1)
      printf("},\n");
    else
      printf("}\n");
  }
  printf("};\n");
}

template <>
void fullMatrix<int>::print(const std::string &name,
                            const std::string &format) const
{
  std::string rformat = (format == "") ? "%12d " : format;
  int ni = size1();
  int nj = size2();
  printf("int %s [ %d ][ %d ]= { \n", name.c_str(), ni, nj);
  for(int I = 0; I < ni; I++) {
    printf("{  ");
    for(int J = 0; J < nj; J++) {
      printf(rformat.c_str(), (*this)(I, J));
      if(J != nj - 1) printf(",");
    }
    if(I != ni - 1)
      printf("},\n");
    else
      printf("}\n");
  }
  printf("};\n");
}
