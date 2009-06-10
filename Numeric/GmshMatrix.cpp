// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <complex>
#include <string.h>
#include "GmshConfig.h"
#include "GmshMatrix.h"
#include "GmshMessage.h"

#if defined(HAVE_BLAS)

extern "C" {
  void dgemm_(const char *transa, const char *transb, int *m, int *n, int *k, 
              double *alpha, double *a, int *lda, 
              double *b, int *ldb, double *beta, 
              double *c, int *ldc);
  void zgemm_(const char *transa, const char *transb, int *m, int *n, int *k, 
              std::complex<double> *alpha, std::complex<double> *a, int *lda, 
              std::complex<double> *b, int *ldb, std::complex<double> *beta, 
              std::complex<double> *c, int *ldc);
  void dgemv_(const char *trans, int *m, int *n, 
              double *alpha, double *a, int *lda, 
              double *x, int *incx, double *beta, 
              double *y, int *incy);
  void zgemv_(const char *trans, int *m, int *n, 
              std::complex<double> *alpha, std::complex<double> *a, int *lda, 
              std::complex<double> *x, int *incx, std::complex<double> *beta, 
              std::complex<double> *y, int *incy);
}

template<> 
void gmshMatrix<double>::mult(const gmshMatrix<double> &b, gmshMatrix<double> &c)
{
  int M = c.size1(), N = c.size2(), K = _c;
  int LDA = _r, LDB = b.size1(), LDC = c.size1();
  double alpha = 1., beta = 0.;
  dgemm_("N", "N", &M, &N, &K, &alpha, _data, &LDA, b._data, &LDB, 
         &beta, c._data, &LDC);
}

template<> 
void gmshMatrix<std::complex<double> >::mult(const gmshMatrix<std::complex<double> > &b, 
                                             gmshMatrix<std::complex<double> > &c)
{
  int M = c.size1(), N = c.size2(), K = _c;
  int LDA = _r, LDB = b.size1(), LDC = c.size1();
  std::complex<double> alpha = 1., beta = 0.;
  zgemm_("N", "N", &M, &N, &K, &alpha, _data, &LDA, b._data, &LDB, 
         &beta, c._data, &LDC);
}

template<> 
void gmshMatrix<double>::gemm(gmshMatrix<double> &a, gmshMatrix<double> &b, 
                              double alpha, double beta)
{
  int M = size1(), N = size2(), K = a.size2();
  int LDA = a.size1(), LDB = b.size1(), LDC = size1();
  dgemm_("N", "N", &M, &N, &K, &alpha, a._data, &LDA, b._data, &LDB, 
         &beta, _data, &LDC);
}

template<> 
void gmshMatrix<std::complex<double> >::gemm(gmshMatrix<std::complex<double> > &a, 
                                             gmshMatrix<std::complex<double> > &b, 
                                             std::complex<double> alpha, 
                                             std::complex<double> beta)
{
  int M = size1(), N = size2(), K = a.size2();
  int LDA = a.size1(), LDB = b.size1(), LDC = size1();
  zgemm_("N", "N", &M, &N, &K, &alpha, a._data, &LDA, b._data, &LDB, 
         &beta, _data, &LDC);
}

template<> 
void gmshMatrix<double>::mult(const gmshVector<double> &x, gmshVector<double> &y)
{
  int M = _r, N = _c, LDA = _r, INCX = 1, INCY = 1;
  double alpha = 1., beta = 0.;
  dgemv_("N", &M, &N, &alpha, _data, &LDA, x._data, &INCX,
         &beta, y._data, &INCY);
}

template<> 
void gmshMatrix<std::complex<double> >::mult(const gmshVector<std::complex<double> > &x, 
                                             gmshVector<std::complex<double> > &y)
{
  int M = _r, N = _c, LDA = _r, INCX = 1, INCY = 1;
  std::complex<double> alpha = 1., beta = 0.;
  zgemv_("N", &M, &N, &alpha, _data, &LDA, x._data, &INCX,
         &beta, y._data, &INCY);
}

#endif

#if defined(HAVE_LAPACK)

extern "C" {
  void dgesv_(int *N, int *nrhs, double *A, int *lda, int *ipiv, 
              double *b, int *ldb, int *info);
  void dgetrf_(int *M, int *N, double *A, int *lda, int *ipiv, int *info);
  void dgetri_(int *M, double *A, int *lda, int *ipiv, double *work, int *lwork, 
               int *info);
  void dgesvd_(const char* jobu, const char *jobvt, int *M, int *N,
               double *A, int *lda, double *S, double* U, int *ldu,
               double *VT, int *ldvt, double *work, int *lwork, int *info);
  void dgeev_(const char *jobvl, const char *jobvr, 
	      int *n, double *a, int *lda, 
	      double *wr, double *wi, 
	      double *vl, int *ldvl, 
	      double *vr, int *ldvr, 
	      double *work, int *lwork,
	      int *info); 
}

template<> 
bool gmshMatrix<double>::invertInPlace()
{
  int N = size1(), nrhs = N, lda = N, ldb = N, info;
  int *ipiv = new int[N];
  double * invA = new double[N*N];

  for (size_t i = 0; i < N * N; i++) invA[i] = 0.;
  for (size_t i = 0; i < N; i++) invA[i * N + i] = 1.;

  dgesv_(&N, &nrhs, _data, &lda, ipiv, invA, &ldb, &info);
  memcpy(_data, invA, N * N * sizeof(double));

  delete [] invA;
  delete [] ipiv;

  if(info == 0) return true;
  if(info > 0)
    Msg::Error("U(%d,%d)=0 in matrix inversion", info, info);
  else
    Msg::Error("Wrong %d-th argument in matrix inversion", -info);
  return false;
}


template<> 
bool gmshMatrix<double>::eig(gmshMatrix<double> &VL, // left eigenvectors 
			     gmshVector<double> &DR, // Real part of eigenvalues
			     gmshVector<double> &DI, // Im part of eigenvalues
			     gmshMatrix<double> &VR,
                             bool sortRealPart) // if true: sorted from min '|DR|' to max '|DR|'
{
  int N = size1(), info;
  int LWORK = 10*N;
  double * work = new double[LWORK];

  dgeev_("V","V",
	 &N,_data,
	 &N,DR._data,DI._data,
	 VL._data,&N,
	 VR._data,&N,
	 work,&LWORK,&info);
  
  delete [] work;

  if(info > 0)
    Msg::Error("QR Algorithm failed to compute all the eigenvalues", info, info);
  else if(info < 0)
    Msg::Error("Wrong %d-th argument in eig", -info);

  if (sortRealPart) {
    double tmp[8];
    // do permutations
    for (int i=0; i<(size1()-1); i++) {
      int minR = i;
      for (int j=i+1; j<size1(); j++) if ( fabs(DR(j)) < fabs(DR(minR)) ) minR = j;
      if ( minR != i )
        {
          tmp[0] = DR(i); tmp[1] = DI(i);
          tmp[2] = VL(0,i); tmp[3] = VL(1,i); tmp[4] = VL(2,i);
          tmp[5] = VR(0,i); tmp[6] = VR(1,i); tmp[7] = VR(2,i);
        
          DR(i) = DR(minR); DI(i) = DI(minR);
          VL(0,i) = VL(0,minR); VL(1,i) = VL(1,minR); VL(2,i) = VL(2,minR);
          VR(0,i) = VR(0,minR); VR(1,i) = VR(1,minR); VR(2,i) = VR(2,minR);
        
          DR(minR) = tmp[0]; DI(minR) = tmp[1];
          VL(0,minR) = tmp[2]; VL(1,minR) = tmp[3]; VL(2,minR) = tmp[4];
          VR(0,minR) = tmp[5]; VR(1,minR) = tmp[6]; VR(2,minR) = tmp[7];
        }
    }
  }

  return true;
}


template<> 
bool gmshMatrix<double>::lu_solve(const gmshVector<double> &rhs, gmshVector<double> &result)
{
  int N = size1(), nrhs = 1, lda = N, ldb = N, info;
  int *ipiv = new int[N];
  for(int i = 0; i < N; i++) result(i) = rhs(i);
  dgesv_(&N, &nrhs, _data, &lda, ipiv, result._data, &ldb, &info);
  delete [] ipiv;
  if(info == 0) return true;
  if(info > 0)
    Msg::Error("U(%d,%d)=0 in LU decomposition", info, info);
  else
    Msg::Error("Wrong %d-th argument in LU decomposition", -info);
  return false;
}

template<>
bool gmshMatrix<double>::invert(gmshMatrix<double> &result)
{
  int M = size1(), N = size2(), lda = size1(), info;
  int *ipiv = new int[std::min(M, N)];
  result = *this;
  dgetrf_(&M, &N, result._data, &lda, ipiv, &info);
  if(info == 0){
    int lwork = M * 4;
    double *work = new double[lwork];
    dgetri_(&M, result._data, &lda, ipiv, work, &lwork, &info);
    delete [] work;
  }
  delete [] ipiv;
  if(info == 0) return true;
  else if(info > 0)
    Msg::Error("U(%d,%d)=0 in matrix inversion", info, info);
  else
    Msg::Error("Wrong %d-th argument in matrix inversion", -info);
  return false;
}

template<> 
double gmshMatrix<double>::determinant() const
{
  gmshMatrix<double> tmp(*this);
  int M = size1(), N = size2(), lda = size1(), info;
  int *ipiv = new int[std::min(M, N)];
  dgetrf_(&M, &N, tmp._data, &lda, ipiv, &info);
  double det = 1.;
  if(info == 0){
    for(int i = 0; i < size1(); i++){
      det *= tmp(i, i);
      if(ipiv[i] != i + 1) det = -det;
    }
  }
  else if(info > 0)
    det = 0.;
  else
    Msg::Error("Wrong %d-th argument in matrix factorization", -info);
  delete [] ipiv;  
  return det;
}

template<> 
bool gmshMatrix<double>::svd(gmshMatrix<double> &V, gmshVector<double> &S)
{
  gmshMatrix<double> VT(V.size2(), V.size1());
  int M = size1(), N = size2(), LDA = size1(), LDVT = VT.size1(), info;
  int LWORK = std::max(3 * std::min(M, N) + std::max(M, N), 5 * std::min(M, N));
  gmshVector<double> WORK(LWORK);
  dgesvd_("O", "A", &M, &N, _data, &LDA, S._data, _data, &LDA,
          VT._data, &LDVT, WORK._data, &LWORK, &info);
  V = VT.transpose();
  if(info == 0) return true;
  if(info > 0)
    Msg::Error("SVD did not converge");
  else
    Msg::Error("Wrong %d-th argument in SVD decomposition", -info);
  return false;
}

#endif
