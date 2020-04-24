#include "hxt_eigenvectors.h"

#ifdef HXT_HAVE_EIGEN

#include <Eigen/Eigenvalues>

template<int N>
HXTStatus eigMat(double * __restrict__ mat,
                 double * __restrict__ vp,
                 double * __restrict__ dirPropres) {
  typedef Eigen::Matrix<double, N, N, Eigen::ColMajor> Matrix;
  // typedef Eigen::Map<Matrix, Eigen::Unaligned> Map;

  Matrix eig_mat(mat);
  Eigen::SelfAdjointEigenSolver<Matrix> solver(eig_mat);

  auto &&eigenvalues = solver.eigenvalues();
  std::copy(eigenvalues.data(), eigenvalues.data() + N, vp);

  auto &&eigenvectors = solver.eigenvectors();
  int j = 0;
  for (int i = 0; i < N; i++) {
    auto &&vector = eigenvectors.col(i);
    std::copy(vector.data(), vector.data() + N, dirPropres + N * i);
    if (i + 1 != N && fabs(vp[i] - vp[i+1]) > 1e-6)
      j++;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      double tmp = dirPropres[i*N + j] ;
      dirPropres[i*N + j] = dirPropres[j*N + i];
      dirPropres[j*N + i] = tmp;
    }
  }

  return HXT_STATUS_OK;
}

#else

#include <stdlib.h>

/* DSYEV prototype */
extern "C" void dsyev_( char* jobz, char* uplo, int* n, double* a, int* lda,
                        double* w, double* work, int* lwork, int* info );

template<int n>
HXTStatus eigMat(double * __restrict__ mat,
                 double * __restrict__ vp,
                 double * __restrict__ dirPropres) {
  /* Locals */
  int lda = n, info, lwork;
  double wkopt;
  double* work;
  /* Local arrays */
  double w[n];
  double a[n*n];
  for(int i=0;i<n*lda;i++)
    a[i]=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<i+1;j++)
      a[i*n+j]=mat[i*n+j];
  /* Query and allocate the optimal workspace */
  lwork = -1;
  int m = n;

  char vectors[] = "Vectors";
  char upper[] = "Upper";

  dsyev_(vectors, upper, &m, a, &lda, w, &wkopt, &lwork, &info );
  lwork = (int)wkopt;
  work = (double*)malloc( lwork*sizeof(double) );
  /* Solve eigenproblem */
  dsyev_(vectors, upper, &m, a, &lda, w, work, &lwork, &info );

  /* Free workspace */
  free( (void*)work );

  /* Check for convergence */
  if( info > 0 ) {
    return HXT_STATUS_FAILED;
  }

  for(int i=0;i<n;i++)
    vp[i] = w[i];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      dirPropres[i*n+j]=a[i+j*lda];
  return HXT_STATUS_OK;
}
#endif

extern "C" {

HXTStatus hxtEigenvectors6(double * __restrict__ matrix,
                           double * __restrict__  values,
                           double * __restrict__ vectors) {
  return eigMat<6>(matrix, values, vectors);
}

HXTStatus hxtEigenvectors3(double * __restrict__ matrix,
                           double * __restrict__  values,
                           double * __restrict__ vectors) {
  return eigMat<3>(matrix, values, vectors);
}

}
