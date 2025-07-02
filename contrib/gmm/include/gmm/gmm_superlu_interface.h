/* -*- c++ -*- (enables emacs c++ mode) */
/*===========================================================================

 Copyright (C) 2003-2024 Yves Renard

 This file is a part of GetFEM

 GetFEM  is  free software;  you  can  redistribute  it  and/or modify it
 under  the  terms  of the  GNU  Lesser General Public License as published
 by  the  Free Software Foundation;  either version 3 of the License,  or
 (at your option) any later version along with the GCC Runtime Library
 Exception either version 3.1 or (at your option) any later version.
 This program  is  distributed  in  the  hope  that it will be useful,  but
 WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 or  FITNESS  FOR  A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 License and GCC Runtime Library Exception for more details.
 You  should  have received a copy of the GNU Lesser General Public License
 along  with  this program;  if not, write to the Free Software Foundation,
 Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.

 As a special exception, you  may use  this file  as it is a part of a free
 software  library  without  restriction.  Specifically,  if   other  files
 instantiate  templates  or  use macros or inline functions from this file,
 or  you compile this  file  and  link  it  with other files  to produce an
 executable, this file  does  not  by itself cause the resulting executable
 to be covered  by the GNU Lesser General Public License.  This   exception
 does not  however  invalidate  any  other  reasons why the executable file
 might be covered by the GNU Lesser General Public License.

===========================================================================*/

/**@file gmm_superlu_interface.h
   @author  Yves Renard <Yves.Renard@insa-lyon.fr>
   @date October 17, 2003.
   @brief Interface with SuperLU (LU direct solver for sparse matrices).
*/
#if defined(GMM_USES_SUPERLU)

#ifndef GMM_SUPERLU_INTERFACE_H
#define GMM_SUPERLU_INTERFACE_H

#include "gmm_kernel.h"


typedef int int_t;

/* because slu_util.h defines TRUE, FALSE, EMPTY ... */
#ifdef TRUE
# undef TRUE
#endif
#ifdef FALSE
# undef FALSE
#endif
#ifdef EMPTY
# undef EMPTY
#endif

namespace SuperLU {
#if defined(GMM_NO_SUPERLU_INCLUDE_SUBDIR)
  #include "slu_Cnames.h"
  #include "supermatrix.h"
  #include "slu_util.h"
  #include "slu_scomplex.h"
  #include "slu_dcomplex.h"
#else
  #include "superlu/slu_Cnames.h"
  #include "superlu/supermatrix.h"
  #include "superlu/slu_util.h"
  #include "superlu/slu_scomplex.h"
  #include "superlu/slu_dcomplex.h"
#endif

#if (SUPERLU_MAJOR_VERSION <= 6)
#  define singlecomplex complex
#endif

  
  // Hard copy from {s,d,c,z}lu_sdefs.h headers from SuperLU version 7
  // This is a fragile solution, but SuperLU headers contaminate the
  // global namespace too much (breaking linking with BLAS for clang).

  //  static_assert(SUPERLU_MAJOR_VERSION >= 6,
  //                "GMM library supports only SuperLU version 7 or later");

  extern "C"{
  extern void
  sgssv(superlu_options_t *, SuperMatrix *, int *, int *, SuperMatrix *,
        SuperMatrix *, SuperMatrix *, SuperLUStat_t *, int_t *info);
  extern void
  dgssv(superlu_options_t *, SuperMatrix *, int *, int *, SuperMatrix *,
        SuperMatrix *, SuperMatrix *, SuperLUStat_t *, int_t *info);
  extern void
  cgssv(superlu_options_t *, SuperMatrix *, int *, int *, SuperMatrix *,
        SuperMatrix *, SuperMatrix *, SuperLUStat_t *, int_t *info);
  extern void
  zgssv(superlu_options_t *, SuperMatrix *, int *, int *, SuperMatrix *,
        SuperMatrix *, SuperMatrix *, SuperLUStat_t *, int_t *info);
  extern void
  sgssvx(superlu_options_t *, SuperMatrix *, int *, int *, int *,
         char *, float *, float *, SuperMatrix *, SuperMatrix *,
         void *, int_t lwork, SuperMatrix *, SuperMatrix *,
         float *, float *, float *, float *,
         GlobalLU_t *, mem_usage_t *, SuperLUStat_t *, int_t *info);
  extern void
  dgssvx(superlu_options_t *, SuperMatrix *, int *, int *, int *,
         char *, double *, double *, SuperMatrix *, SuperMatrix *,
         void *, int_t lwork, SuperMatrix *, SuperMatrix *,
         double *, double *, double *, double *,
         GlobalLU_t *, mem_usage_t *, SuperLUStat_t *, int_t *info);
  extern void
  cgssvx(superlu_options_t *, SuperMatrix *, int *, int *, int *,
         char *, float *, float *, SuperMatrix *, SuperMatrix *,
         void *, int_t lwork, SuperMatrix *, SuperMatrix *,
         float *, float *, float *, float *,
         GlobalLU_t *, mem_usage_t *, SuperLUStat_t *, int_t *info);
  extern void
  zgssvx(superlu_options_t *, SuperMatrix *, int *, int *, int *,
         char *, double *, double *, SuperMatrix *, SuperMatrix *,
         void *, int_t lwork, SuperMatrix *, SuperMatrix *,
         double *, double *, double *, double *,
         GlobalLU_t *, mem_usage_t *, SuperLUStat_t *, int_t *info);
  extern void
  sCreate_CompCol_Matrix(SuperMatrix *, int, int, int_t, float *,
                         int_t *, int_t *, Stype_t, Dtype_t, Mtype_t);
  extern void
  dCreate_CompCol_Matrix(SuperMatrix *, int, int, int_t, double *,
                         int_t *, int_t *, Stype_t, Dtype_t, Mtype_t);
  extern void
  cCreate_CompCol_Matrix(SuperMatrix *, int, int, int_t, singlecomplex *,
                         int_t *, int_t *, Stype_t, Dtype_t, Mtype_t);
  extern void
  zCreate_CompCol_Matrix(SuperMatrix *, int, int, int_t, doublecomplex *,
                         int_t *, int_t *, Stype_t, Dtype_t, Mtype_t);
  extern void
  sCreate_Dense_Matrix(SuperMatrix *, int, int, float *, int,
                       Stype_t, Dtype_t, Mtype_t);
  extern void
  dCreate_Dense_Matrix(SuperMatrix *, int, int, double *, int,
                       Stype_t, Dtype_t, Mtype_t);
  extern void
  cCreate_Dense_Matrix(SuperMatrix *, int, int, singlecomplex *, int,
                       Stype_t, Dtype_t, Mtype_t);
  extern void
  zCreate_Dense_Matrix(SuperMatrix *, int, int, doublecomplex *, int,
                       Stype_t, Dtype_t, Mtype_t);
  }
}

namespace gmm {

  /*  interface for Create_CompCol_Matrix */

  inline void Create_CompCol_Matrix(SuperLU::SuperMatrix *A, int m, int n,
                                    int nnz, float *a, int *ir, int *jc) {
    SuperLU::sCreate_CompCol_Matrix(A, m, n, nnz, a, ir, jc,
                                    SuperLU::SLU_NC, SuperLU::SLU_S,
                                    SuperLU::SLU_GE);
  }

  inline void Create_CompCol_Matrix(SuperLU::SuperMatrix *A, int m, int n,
                                    int nnz, double *a, int *ir, int *jc) {
    SuperLU::dCreate_CompCol_Matrix(A, m, n, nnz, a, ir, jc,
                                    SuperLU::SLU_NC, SuperLU::SLU_D,
                                    SuperLU::SLU_GE);
  }

  inline void Create_CompCol_Matrix(SuperLU::SuperMatrix *A, int m, int n,
                                    int nnz, std::complex<float> *a,
                                    int *ir, int *jc) {
    SuperLU::cCreate_CompCol_Matrix(A, m, n, nnz,
                                    (SuperLU::singlecomplex *)(a),
                                    ir, jc, SuperLU::SLU_NC, SuperLU::SLU_C,
                                    SuperLU::SLU_GE);
  }

  inline void Create_CompCol_Matrix(SuperLU::SuperMatrix *A, int m, int n,
                                    int nnz, std::complex<double> *a,
                                    int *ir, int *jc) {
    SuperLU::zCreate_CompCol_Matrix(A, m, n, nnz,
                                    (SuperLU::doublecomplex *)(a), ir, jc,
                                    SuperLU::SLU_NC, SuperLU::SLU_Z,
                                    SuperLU::SLU_GE);
  }

  /*  interface for Create_Dense_Matrix */

  inline void Create_Dense_Matrix(SuperLU::SuperMatrix *A, int m, int n,
                                  float *a, int k) {
    SuperLU::sCreate_Dense_Matrix(A, m, n, a, k, SuperLU::SLU_DN,
                                                 SuperLU::SLU_S,
                                                 SuperLU::SLU_GE);
  }
  inline void Create_Dense_Matrix(SuperLU::SuperMatrix *A, int m, int n,
                                  double *a, int k) {
    SuperLU::dCreate_Dense_Matrix(A, m, n, a, k, SuperLU::SLU_DN,
                                                 SuperLU::SLU_D,
                                                 SuperLU::SLU_GE);
  }
  inline void Create_Dense_Matrix(SuperLU::SuperMatrix *A, int m, int n,
                                  std::complex<float> *a, int k) {
    SuperLU::cCreate_Dense_Matrix(A, m, n,
                                  (SuperLU::singlecomplex *)(a),
                                  k, SuperLU::SLU_DN, SuperLU::SLU_C,
                                  SuperLU::SLU_GE);
  }
  inline void Create_Dense_Matrix(SuperLU::SuperMatrix *A, int m, int n,
                                  std::complex<double> *a, int k) {
    SuperLU::zCreate_Dense_Matrix(A, m, n, (SuperLU::doublecomplex *)(a),
                                  k, SuperLU::SLU_DN, SuperLU::SLU_Z,
                                  SuperLU::SLU_GE);
  }

  /*  interface for gssv */

#define DECL_GSSV(FNAME,KEYTYPE) \
  inline void SuperLU_gssv(SuperLU::superlu_options_t *options,     \
                           SuperLU::SuperMatrix *A, int *p, int *q, \
                           SuperLU::SuperMatrix *L,                 \
                           SuperLU::SuperMatrix *U,                 \
                           SuperLU::SuperMatrix *B,                 \
                           SuperLU::SuperLUStat_t *stats,           \
                           int *info, KEYTYPE) {                    \
  SuperLU::FNAME(options, A, p, q, L, U, B, stats, info);           \
  }

  DECL_GSSV(sgssv, float)
  DECL_GSSV(cgssv, std::complex<float>)
  DECL_GSSV(dgssv, double)
  DECL_GSSV(zgssv, std::complex<double>)

  /*  interface for gssvx */

#define DECL_GSSVX(FNAME,FLOATTYPE,KEYTYPE) \
  inline float SuperLU_gssvx(SuperLU::superlu_options_t *options,     \
                             SuperLU::SuperMatrix *A,                 \
                             int *perm_c, int *perm_r, int *etree,    \
                             char *equed,                             \
                             FLOATTYPE *R, FLOATTYPE *C,              \
                             SuperLU::SuperMatrix *L,                 \
                             SuperLU::SuperMatrix *U,                 \
                             void *work, int lwork,                   \
                             SuperLU::SuperMatrix *B,                 \
                             SuperLU::SuperMatrix *X,                 \
                             FLOATTYPE *recip_pivot_growth,           \
                             FLOATTYPE *rcond, FLOATTYPE *ferr,       \
                             FLOATTYPE *berr,                         \
                             SuperLU::SuperLUStat_t *stats,           \
                             int *info, KEYTYPE) {                    \
    SuperLU::mem_usage_t mem_usage;                                            \
    SuperLU::GlobalLU_t Glu;                                                   \
    SuperLU::FNAME(options, A, perm_c, perm_r, etree, equed, R, C, L, \
                     U, work, lwork, B, X, recip_pivot_growth, rcond, \
                     ferr, berr, &Glu, &mem_usage, stats, info);      \
    return mem_usage.for_lu; /* bytes used by the factor storage */   \
  }

  DECL_GSSVX(sgssvx,  float, float)
  DECL_GSSVX(cgssvx,  float, std::complex<float>)
  DECL_GSSVX(dgssvx, double, double)
  DECL_GSSVX(zgssvx, double, std::complex<double>)

  /* ********************************************************************* */
  /*   SuperLU solve interface                                             */
  /* ********************************************************************* */

  template <typename MAT, typename VECTX, typename VECTB>
  int SuperLU_solve(const MAT &A, const VECTX &X, const VECTB &B,
                    double& rcond_, int permc_spec = 3) {
    /*
     * Get column permutation vector perm_c[], according to permc_spec:
     *   permc_spec = 0: use the natural ordering
     *   permc_spec = 1: use minimum degree ordering on structure of A'*A
     *   permc_spec = 2: use minimum degree ordering on structure of A'+A
     *   permc_spec = 3: use approximate minimum degree column ordering
     */
    typedef typename linalg_traits<MAT>::value_type T;
    typedef typename number_traits<T>::magnitude_type R;

    int m = int(mat_nrows(A)), n = int(mat_ncols(A)), nrhs = 1, info = 0;

    csc_matrix<T> csc_A(m, n);
    gmm::copy(A, csc_A);
    std::vector<T> rhs(m), sol(m);
    gmm::copy(B, rhs);

    int nz = int(nnz(csc_A));
    if ((2 * nz / n) >= m)
      GMM_WARNING2("CAUTION : it seems that SuperLU has a problem"
                   " for nearly dense sparse matrices");

    SuperLU::superlu_options_t options;
    set_default_options(&options);
    options.ColPerm = SuperLU::NATURAL;
    options.PrintStat = SuperLU::NO;
    options.ConditionNumber = SuperLU::YES;
    switch (permc_spec) {
    case 1 : options.ColPerm = SuperLU::MMD_ATA; break;
    case 2 : options.ColPerm = SuperLU::MMD_AT_PLUS_A; break;
    case 3 : options.ColPerm = SuperLU::COLAMD; break;
    }
    SuperLU::SuperLUStat_t stat;
    StatInit(&stat);

    SuperLU::SuperMatrix SA, SL, SU, SB, SX; // SuperLU format.
    Create_CompCol_Matrix(&SA, m, n, nz, (T *)(&csc_A.pr[0]),
                          (int *)(&csc_A.ir[0]),
                          (int *)(&csc_A.jc[0]));
    Create_Dense_Matrix(&SB, m, nrhs, &rhs[0], m);
    Create_Dense_Matrix(&SX, m, nrhs, &sol[0], m);
    memset(&SL,0,sizeof SL);
    memset(&SU,0,sizeof SU);

    std::vector<int> etree(n);
    char equed[] = "B";
    std::vector<R> Rscale(m),Cscale(n); // row scale factors
    std::vector<R> ferr(nrhs), berr(nrhs);
    R recip_pivot_gross, rcond;
    std::vector<int> perm_r(m), perm_c(n);

    SuperLU_gssvx(&options, &SA, &perm_c[0], &perm_r[0],
                  &etree[0] /* output */, equed /* output         */,
                  &Rscale[0] /* row scale factors (output)        */,
                  &Cscale[0] /* col scale factors (output)        */,
                  &SL /* fact L (output)*/, &SU /* fact U (output)*/,
                  NULL /* work                                    */,
                  0 /* lwork: superlu auto allocates (input)      */,
                  &SB /* rhs */, &SX /* solution                  */,
                  &recip_pivot_gross /* reciprocal pivot growth   */
                  /* factor max_j( norm(A_j)/norm(U_j) ).         */,
                  &rcond /*estimate of the reciprocal condition   */
                  /* number of the matrix A after equilibration   */,
                  &ferr[0] /* estimated forward error             */,
                  &berr[0] /* relative backward error             */,
                  &stat, &info, T());
    rcond_ = rcond;
    if (SB.Store) Destroy_SuperMatrix_Store(&SB);
    if (SX.Store) Destroy_SuperMatrix_Store(&SX);
    if (SA.Store) Destroy_SuperMatrix_Store(&SA);
    if (SL.Store) Destroy_SuperNode_Matrix(&SL);
    if (SU.Store) Destroy_CompCol_Matrix(&SU);
    StatFree(&stat);
    GMM_ASSERT1(info != -333333333, "SuperLU was cancelled."); // user interruption (for matlab interface)

    GMM_ASSERT1(info >= 0, "SuperLU solve failed: info =" << info);
    if (info > 0) GMM_WARNING1("SuperLU solve failed: info =" << info);
    gmm::copy(sol, const_cast<VECTX &>(X));
    return info;
  }

  template <class T>
  class SuperLU_factor {
    typedef typename number_traits<T>::magnitude_type R;

    csc_matrix<T> csc_A;
    mutable SuperLU::SuperMatrix SA, SL, SB, SU, SX;
    mutable SuperLU::SuperLUStat_t stat;
    mutable SuperLU::superlu_options_t options;
    float memory_used;
    mutable std::vector<int> etree, perm_r, perm_c;
    mutable std::vector<R> Rscale, Cscale;
    mutable std::vector<R> ferr, berr;
    mutable std::vector<T> rhs;
    mutable std::vector<T> sol;
    mutable bool is_init;
    mutable char equed;

  public :
    enum { LU_NOTRANSP, LU_TRANSP, LU_CONJUGATED };
    void free_supermatrix() {
      if (is_init) {
        if (SB.Store) Destroy_SuperMatrix_Store(&SB);
        if (SX.Store) Destroy_SuperMatrix_Store(&SX);
        if (SA.Store) Destroy_SuperMatrix_Store(&SA);
        if (SL.Store) Destroy_SuperNode_Matrix(&SL);
        if (SU.Store) Destroy_CompCol_Matrix(&SU);
      }
    }
    template <class MAT> void build_with(const MAT &A,  int permc_spec = 3);
    template <typename VECTX, typename VECTB>
    /* transp = LU_NOTRANSP   -> solves Ax = B
       transp = LU_TRANSP     -> solves A'x = B
       transp = LU_CONJUGATED -> solves conj(A)X = B */
    void solve(const VECTX &X_, const VECTB &B, int transp=LU_NOTRANSP) const;
    SuperLU_factor() { is_init = false; }
    SuperLU_factor(const SuperLU_factor& other) {
      GMM_ASSERT2(!(other.is_init),
                  "copy of initialized SuperLU_factor is forbidden");
      is_init = false;
    }
    SuperLU_factor& operator=(const SuperLU_factor& other) {
      GMM_ASSERT2(!(other.is_init) && !is_init,
                  "assignment of initialized SuperLU_factor is forbidden");
      return *this;
    }
    ~SuperLU_factor() { free_supermatrix(); }
    float memsize() { return memory_used; }
  };


  template <class T> template <class MAT>
  void SuperLU_factor<T>::build_with(const MAT &A, int permc_spec) {
    /*
     * Get column permutation vector perm_c[], according to permc_spec:
     *   permc_spec = 0: use the natural ordering
     *   permc_spec = 1: use minimum degree ordering on structure of A'*A
     *   permc_spec = 2: use minimum degree ordering on structure of A'+A
     *   permc_spec = 3: use approximate minimum degree column ordering
     */
    free_supermatrix();
    int n = int(mat_nrows(A)), m = int(mat_ncols(A)), info = 0;
    csc_A.init_with(A);

    rhs.resize(m); sol.resize(m);
    gmm::clear(rhs);
    int nz = int(nnz(csc_A));

    set_default_options(&options);
    options.ColPerm = SuperLU::NATURAL;
    options.PrintStat = SuperLU::NO;
    options.ConditionNumber = SuperLU::NO;
    switch (permc_spec) {
      case 1 : options.ColPerm = SuperLU::MMD_ATA; break;
      case 2 : options.ColPerm = SuperLU::MMD_AT_PLUS_A; break;
      case 3 : options.ColPerm = SuperLU::COLAMD; break;
    }
    StatInit(&stat);

    Create_CompCol_Matrix(&SA, m, n, nz, (T *)(&csc_A.pr[0]),
                          (int *)(&csc_A.ir[0]),
                          (int *)(&csc_A.jc[0]));
    Create_Dense_Matrix(&SB, m, 0, &rhs[0], m);
    Create_Dense_Matrix(&SX, m, 0, &sol[0], m);
    memset(&SL,0,sizeof SL);
    memset(&SU,0,sizeof SU);
    equed = 'B';
    Rscale.resize(m); Cscale.resize(n); etree.resize(n);
    ferr.resize(1); berr.resize(1);
    R recip_pivot_gross, rcond;
    perm_r.resize(m); perm_c.resize(n);
    memory_used = SuperLU_gssvx(&options, &SA, &perm_c[0], &perm_r[0],
                                &etree[0] /* output */, &equed /* output     */,
                                &Rscale[0] /* row scale factors (output)     */,
                                &Cscale[0] /* col scale factors (output)     */,
                                &SL /* fact L (output)                       */,
                                &SU /* fact U (output)                       */,
                                NULL /* work                                 */,
                                0 /* lwork: superlu auto allocates (input)   */,
                                &SB /* rhs */, &SX /* solution               */,
                                &recip_pivot_gross /* reciprocal pivot growth*/
                                /* factor max_j(norm(A_j)/norm(U_j)).        */,
                                &rcond /*estimate of the reciprocal condition*/
                                /* number of the matrix A after equilibration*/,
                                &ferr[0] /* estimated forward error          */,
                                &berr[0] /* relative backward error          */,
                                &stat, &info, T());

    Destroy_SuperMatrix_Store(&SB);
    Destroy_SuperMatrix_Store(&SX);
    Create_Dense_Matrix(&SB, m, 1, &rhs[0], m);
    Create_Dense_Matrix(&SX, m, 1, &sol[0], m);
    StatFree(&stat);

    GMM_ASSERT1(info != -333333333, "SuperLU was cancelled.");
    GMM_ASSERT1(info == 0, "SuperLU solve failed: info=" << info);
    is_init = true;
  }

  template <class T> template <typename VECTX, typename VECTB>
  void SuperLU_factor<T>::solve(const VECTX &X, const VECTB &B,
                                int transp) const {
    gmm::copy(B, rhs);
    options.Fact = SuperLU::FACTORED;
    options.IterRefine = SuperLU::NOREFINE;
    switch (transp) {
      case LU_NOTRANSP: options.Trans = SuperLU::NOTRANS; break;
      case LU_TRANSP: options.Trans = SuperLU::TRANS; break;
      case LU_CONJUGATED: options.Trans = SuperLU::CONJ; break;
      default: GMM_ASSERT1(false, "invalid value for transposition option");
    }
    StatInit(&stat);
    int info = 0;
    R recip_pivot_gross, rcond;
    SuperLU_gssvx(&options, &SA, &perm_c[0], &perm_r[0],
                  &etree[0] /* output */, &equed /* output        */,
                  &Rscale[0] /* row scale factors (output)        */,
                  &Cscale[0] /* col scale factors (output)        */,
                  &SL /* fact L (output)*/, &SU /* fact U (output)*/,
                  NULL /* work                                    */,
                  0 /* lwork: superlu auto allocates (input)      */,
                  &SB /* rhs */, &SX /* solution                  */,
                  &recip_pivot_gross /* reciprocal pivot growth   */
                  /* factor max_j( norm(A_j)/norm(U_j) ).         */,
                  &rcond /*estimate of the reciprocal condition   */
                  /* number of the matrix A after equilibration   */,
                  &ferr[0] /* estimated forward error             */,
                  &berr[0] /* relative backward error             */,
                  &stat, &info, T());
    StatFree(&stat);
    GMM_ASSERT1(info == 0, "SuperLU solve failed: info=" << info);
    gmm::copy(sol, const_cast<VECTX &>(X));
  }

  template <typename T, typename V1, typename V2> inline
  void mult(const SuperLU_factor<T>& P, const V1 &v1, const V2 &v2) {
    P.solve(v2,v1);
  }

  template <typename T, typename V1, typename V2> inline
  void transposed_mult(const SuperLU_factor<T>& P,const V1 &v1,const V2 &v2) {
    P.solve(v2, v1, SuperLU_factor<T>::LU_TRANSP);
  }

}

#ifdef TRUE
# undef TRUE
#endif
#ifdef FALSE
# undef FALSE
#endif
#ifdef EMPTY
# undef EMPTY
#endif

#endif // GMM_SUPERLU_INTERFACE_H

#endif // GMM_USES_SUPERLU
