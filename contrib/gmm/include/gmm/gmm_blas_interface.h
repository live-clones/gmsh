/* -*- c++ -*- (enables emacs c++ mode) */
/*===========================================================================

 Copyright (C) 2003-2020 Yves Renard

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

/**@file gmm_blas_interface.h
   @author  Yves Renard <Yves.Renard@insa-lyon.fr>
   @date October 7, 2003.
   @brief gmm interface for fortran BLAS.
*/

#if defined(GMM_USES_BLAS) || defined(GMM_USES_LAPACK)

#ifndef GMM_BLAS_INTERFACE_H
#define GMM_BLAS_INTERFACE_H

#include "gmm_blas.h"
#include "gmm_interface.h"
#include "gmm_matrix.h"

namespace gmm {

  // Use ./configure --enable-blas-interface to activate this interface.

#define GMMLAPACK_TRACE(f)
// #define GMMLAPACK_TRACE(f) cout << "function " << f << " called" << endl;

#if defined(WeirdNEC) || defined(GMM_USE_BLAS64_INTERFACE)
  #define BLAS_INT long
#else // By default BLAS_INT will just be int in C
  #define BLAS_INT int
#endif

  /* ********************************************************************* */
  /* Operations interfaced for T = float, double, std::complex<float>      */
  /*    or std::complex<double> :                                          */
  /*                                                                       */
  /* vect_norm2(std::vector<T>)                                            */
  /*                                                                       */
  /* vect_sp(std::vector<T>, std::vector<T>)                               */
  /* vect_sp(scaled(std::vector<T>), std::vector<T>)                       */
  /* vect_sp(std::vector<T>, scaled(std::vector<T>))                       */
  /* vect_sp(scaled(std::vector<T>), scaled(std::vector<T>))               */
  /*                                                                       */
  /* vect_hp(std::vector<T>, std::vector<T>)                               */
  /* vect_hp(scaled(std::vector<T>), std::vector<T>)                       */
  /* vect_hp(std::vector<T>, scaled(std::vector<T>))                       */
  /* vect_hp(scaled(std::vector<T>), scaled(std::vector<T>))               */
  /*                                                                       */
  /* add(std::vector<T>, std::vector<T>)                                   */
  /* add(scaled(std::vector<T>, a), std::vector<T>)                        */
  /*                                                                       */
  /* mult(dense_matrix<T>, dense_matrix<T>, dense_matrix<T>)               */
  /* mult(transposed(dense_matrix<T>), dense_matrix<T>, dense_matrix<T>)   */
  /* mult(dense_matrix<T>, transposed(dense_matrix<T>), dense_matrix<T>)   */
  /* mult(transposed(dense_matrix<T>), transposed(dense_matrix<T>),        */
  /*      dense_matrix<T>)                                                 */
  /* mult(conjugated(dense_matrix<T>), dense_matrix<T>, dense_matrix<T>)   */
  /* mult(dense_matrix<T>, conjugated(dense_matrix<T>), dense_matrix<T>)   */
  /* mult(conjugated(dense_matrix<T>), conjugated(dense_matrix<T>),        */
  /*      dense_matrix<T>)                                                 */
  /*                                                                       */
  /* mult(dense_matrix<T>, std::vector<T>, std::vector<T>)                 */
  /* mult(transposed(dense_matrix<T>), std::vector<T>, std::vector<T>)     */
  /* mult(conjugated(dense_matrix<T>), std::vector<T>, std::vector<T>)     */
  /* mult(dense_matrix<T>, scaled(std::vector<T>), std::vector<T>)         */
  /* mult(transposed(dense_matrix<T>), scaled(std::vector<T>),             */
  /*      std::vector<T>)                                                  */
  /* mult(conjugated(dense_matrix<T>), scaled(std::vector<T>),             */
  /*      std::vector<T>)                                                  */
  /*                                                                       */
  /* mult_add(dense_matrix<T>, std::vector<T>, std::vector<T>)             */
  /* mult_add(transposed(dense_matrix<T>), std::vector<T>, std::vector<T>) */
  /* mult_add(conjugated(dense_matrix<T>), std::vector<T>, std::vector<T>) */
  /* mult_add(dense_matrix<T>, scaled(std::vector<T>), std::vector<T>)     */
  /* mult_add(transposed(dense_matrix<T>), scaled(std::vector<T>),         */
  /*          std::vector<T>)                                              */
  /* mult_add(conjugated(dense_matrix<T>), scaled(std::vector<T>),         */
  /*          std::vector<T>)                                              */
  /*                                                                       */
  /* mult(dense_matrix<T>, std::vector<T>, std::vector<T>, std::vector<T>) */
  /* mult(transposed(dense_matrix<T>), std::vector<T>, std::vector<T>,     */
  /*      std::vector<T>)                                                  */
  /* mult(conjugated(dense_matrix<T>), std::vector<T>, std::vector<T>,     */
  /*      std::vector<T>)                                                  */
  /* mult(dense_matrix<T>, scaled(std::vector<T>), std::vector<T>,         */
  /*      std::vector<T>)                                                  */
  /* mult(transposed(dense_matrix<T>), scaled(std::vector<T>),             */
  /*      std::vector<T>, std::vector<T>)                                  */
  /* mult(conjugated(dense_matrix<T>), scaled(std::vector<T>),             */
  /*      std::vector<T>, std::vector<T>)                                  */
  /* mult(dense_matrix<T>, std::vector<T>, scaled(std::vector<T>),         */
  /*      std::vector<T>)                                                  */
  /* mult(transposed(dense_matrix<T>), std::vector<T>,                     */
  /*      scaled(std::vector<T>), std::vector<T>)                          */
  /* mult(conjugated(dense_matrix<T>), std::vector<T>,                     */
  /*      scaled(std::vector<T>), std::vector<T>)                          */
  /* mult(dense_matrix<T>, scaled(std::vector<T>), scaled(std::vector<T>), */
  /*   std::vector<T>)                                                     */
  /* mult(transposed(dense_matrix<T>), scaled(std::vector<T>),             */
  /*      scaled(std::vector<T>), std::vector<T>)                          */
  /* mult(conjugated(dense_matrix<T>), scaled(std::vector<T>),             */
  /*      scaled(std::vector<T>), std::vector<T>)                          */
  /*                                                                       */
  /* lower_tri_solve(dense_matrix<T>, std::vector<T>, k, b)                */
  /* upper_tri_solve(dense_matrix<T>, std::vector<T>, k, b)                */
  /* lower_tri_solve(transposed(dense_matrix<T>), std::vector<T>, k, b)    */
  /* upper_tri_solve(transposed(dense_matrix<T>), std::vector<T>, k, b)    */
  /* lower_tri_solve(conjugated(dense_matrix<T>), std::vector<T>, k, b)    */
  /* upper_tri_solve(conjugated(dense_matrix<T>), std::vector<T>, k, b)    */
  /*                                                                       */
  /* rank_one_update(dense_matrix<T>, std::vector<T>, std::vector<T>)      */
  /* rank_one_update(dense_matrix<T>, scaled(std::vector<T>),              */
  /*                                  std::vector<T>)                      */
  /* rank_one_update(dense_matrix<T>, std::vector<T>,                      */
  /*                                  scaled(std::vector<T>))              */
  /*                                                                       */
  /* ********************************************************************* */

  /* ********************************************************************* */
  /* Basic defines.                                                        */
  /* ********************************************************************* */

# define BLAS_S float
# define BLAS_D double
# define BLAS_C std::complex<float>
# define BLAS_Z std::complex<double>

// Hack due to BLAS ABI mess
#if defined(GMM_BLAS_RETURN_COMPLEX_AS_ARGUMENT)
# define BLAS_CPLX_FUNC_CALL(blasname, res, ...) blasname(&res, __VA_ARGS__)
#else
# define BLAS_CPLX_FUNC_CALL(blasname, res, ...) res = blasname(__VA_ARGS__)
#endif

  /* ********************************************************************* */
  /* BLAS functions used.                                                  */
  /* ********************************************************************* */
  extern "C" {
    void daxpy_(const BLAS_INT *n, const double *alpha, const double *x,
                const BLAS_INT *incx, double *y, const BLAS_INT *incy);
    void saxpy_(...); /*void daxpy_(...);*/ void caxpy_(...); void zaxpy_(...);
    void dgemm_(const char *tA, const char *tB, const BLAS_INT *m,
                const BLAS_INT *n, const BLAS_INT *k, const BLAS_D *alpha,
                const BLAS_D *A, const BLAS_INT *ldA, const BLAS_D *B,
                const BLAS_INT *ldB, const BLAS_D *beta, BLAS_D *C,
                const BLAS_INT *ldC);
    void sgemm_(...); /*void dgemm_(...);*/ void cgemm_(...); void zgemm_(...);
    void sgemv_(...); void dgemv_(...); void cgemv_(...); void zgemv_(...);
    void strsv_(...); void dtrsv_(...); void ctrsv_(...); void ztrsv_(...);
    BLAS_S sdot_ (...); BLAS_D ddot_ (...);
    BLAS_C cdotu_(...); BLAS_Z zdotu_(...);
    // Hermitian product in {c,z}dotc is defined in reverse order than usually
    BLAS_C cdotc_(...); BLAS_Z zdotc_(...);
    BLAS_S snrm2_(...); BLAS_D dnrm2_(...);
    BLAS_S scnrm2_(...); BLAS_D dznrm2_(...);
    void sger_(...); void dger_(...); void cgerc_(...); void zgerc_(...);
  }


  /* ********************************************************************* */
  /* vect_norm2(x).                                                        */
  /* ********************************************************************* */

# define nrm2_interface(blas_name, base_type)             \
  inline number_traits<base_type>::magnitude_type         \
  vect_norm2(const std::vector<base_type> &x) {           \
    GMMLAPACK_TRACE("nrm2_interface");                    \
    const BLAS_INT n=BLAS_INT(vect_size(x)), inc(1);      \
    return blas_name(&n, &x[0], &inc);                    \
  }

  nrm2_interface(snrm2_,  BLAS_S)
  nrm2_interface(dnrm2_,  BLAS_D)
  nrm2_interface(scnrm2_, BLAS_C)
  nrm2_interface(dznrm2_, BLAS_Z)

  /* ********************************************************************* */
  /* vect_sp(x,y) = vect_hp(x,y) for real vectors                          */
  /* ********************************************************************* */

# define dot_interface(funcname, msg, blas_name, base_type)                \
  inline base_type funcname(const std::vector<base_type> &x,               \
                            const std::vector<base_type> &y) {             \
    GMMLAPACK_TRACE(msg);                                                  \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    return blas_name(&n, &x[0], &inc, &y[0], &inc);                        \
  }                                                                        \
  inline base_type funcname                                                \
   (const scaled_vector_const_ref<std::vector<base_type>,base_type> &x_,   \
    const std::vector<base_type> &y) {                                     \
    GMMLAPACK_TRACE(msg);                                                  \
    const std::vector<base_type> &x = *(linalg_origin(x_));                \
    base_type a(x_.r);                                                     \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    return a * blas_name(&n, &x[0], &inc, &y[0], &inc);                    \
  }                                                                        \
  inline base_type funcname                                                \
    (const std::vector<base_type> &x,                                      \
     const scaled_vector_const_ref<std::vector<base_type>,base_type> &y_) {\
    GMMLAPACK_TRACE(msg);                                                  \
    const std::vector<base_type> &y = *(linalg_origin(y_));                \
    base_type b(y_.r);                                                     \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    return b * blas_name(&n, &x[0], &inc, &y[0], &inc);                    \
  }                                                                        \
  inline base_type funcname                                                \
    (const scaled_vector_const_ref<std::vector<base_type>,base_type> &x_,  \
     const scaled_vector_const_ref<std::vector<base_type>,base_type> &y_) {\
    GMMLAPACK_TRACE(msg);                                                  \
    const std::vector<base_type> &x = *(linalg_origin(x_));                \
    const std::vector<base_type> &y = *(linalg_origin(y_));                \
    base_type a(x_.r), b(y_.r);                                            \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    return a*b * blas_name(&n, &x[0], &inc, &y[0], &inc);                  \
  }

  dot_interface(vect_sp, "dot_interface", sdot_,  BLAS_S)
  dot_interface(vect_sp, "dot_interface", ddot_,  BLAS_D)
  dot_interface(vect_hp, "dotc_interface", sdot_,  BLAS_S)
  dot_interface(vect_hp, "dotc_interface", ddot_,  BLAS_D)

  /* ********************************************************************* */
  /* vect_sp(x,y) and vect_hp(x,y) for complex vectors                     */
  /* vect_hp(x, y) = x.conj(y) (different order than in BLAS)              */
  /* switching x,y before passed to BLAS is important only for vect_hp     */
  /* ********************************************************************* */

# define dot_interface_cplx(funcname, msg, blas_name, base_type, bdef)     \
  inline base_type funcname(const std::vector<base_type> &x,               \
                            const std::vector<base_type> &y) {             \
    GMMLAPACK_TRACE(msg);                                                  \
    base_type res;                                                         \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    BLAS_CPLX_FUNC_CALL(blas_name, res, &n, &y[0], &inc, &x[0], &inc);     \
    return res;                                                            \
  }                                                                        \
  inline base_type funcname                                                \
   (const scaled_vector_const_ref<std::vector<base_type>,base_type> &x_,   \
    const std::vector<base_type> &y) {                                     \
    GMMLAPACK_TRACE(msg);                                                  \
    const std::vector<base_type> &x = *(linalg_origin(x_));                \
    base_type res, a(x_.r);                                                \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    BLAS_CPLX_FUNC_CALL(blas_name, res, &n, &y[0], &inc, &x[0], &inc);     \
    return a*res;                                                          \
  }                                                                        \
  inline base_type funcname                                                \
    (const std::vector<base_type> &x,                                      \
     const scaled_vector_const_ref<std::vector<base_type>,base_type> &y_) {\
    GMMLAPACK_TRACE(msg);                                                  \
    const std::vector<base_type> &y = *(linalg_origin(y_));                \
    base_type res, b(bdef);                                                \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    BLAS_CPLX_FUNC_CALL(blas_name, res, &n, &y[0], &inc, &x[0], &inc);     \
    return b*res;                                                          \
  }                                                                        \
  inline base_type funcname                                                \
    (const scaled_vector_const_ref<std::vector<base_type>,base_type> &x_,  \
     const scaled_vector_const_ref<std::vector<base_type>,base_type> &y_) {\
    GMMLAPACK_TRACE(msg);                                                  \
    const std::vector<base_type> &x = *(linalg_origin(x_));                \
    const std::vector<base_type> &y = *(linalg_origin(y_));                \
    base_type res, a(x_.r), b(bdef);                                       \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    BLAS_CPLX_FUNC_CALL(blas_name, res, &n, &y[0], &inc, &x[0], &inc);     \
    return a*b*res;                                                        \
  }

  dot_interface_cplx(vect_sp, "dot_interface", cdotu_, BLAS_C, y_.r)
  dot_interface_cplx(vect_sp, "dot_interface", zdotu_, BLAS_Z, y_.r)
  dot_interface_cplx(vect_hp, "dotc_interface", cdotc_, BLAS_C, gmm::conj(y_.r))
  dot_interface_cplx(vect_hp, "dotc_interface", zdotc_, BLAS_Z, gmm::conj(y_.r))


  /* ********************************************************************* */
  /* add(x, y).                                                            */
  /* ********************************************************************* */
  template<size_type N, class V1, class V2>
  inline void add_fixed(const V1 &x, V2 &y)
  {
    for(size_type i = 0; i != N; ++i) y[i] += x[i];
  }

  template<class V1, class V2>
  inline void add_for_short_vectors(const V1 &x, V2 &y, size_type n)
  {
    switch(n)
    {
      case  1: add_fixed<1>(x, y);  break;
      case  2: add_fixed<2>(x, y);  break;
      case  3: add_fixed<3>(x, y);  break;
      case  4: add_fixed<4>(x, y);  break;
      case  5: add_fixed<5>(x, y);  break;
      case  6: add_fixed<6>(x, y);  break;
      case  7: add_fixed<7>(x, y);  break;
      case  8: add_fixed<8>(x, y);  break;
      case  9: add_fixed<9>(x, y);  break;
      case 10: add_fixed<10>(x, y); break;
      case 11: add_fixed<11>(x, y); break;
      case 12: add_fixed<12>(x, y); break;
      case 13: add_fixed<13>(x, y); break;
      case 14: add_fixed<14>(x, y); break;
      case 15: add_fixed<15>(x, y); break;
      case 16: add_fixed<16>(x, y); break;
      case 17: add_fixed<17>(x, y); break;
      case 18: add_fixed<18>(x, y); break;
      case 19: add_fixed<19>(x, y); break;
      case 20: add_fixed<20>(x, y); break;
      case 21: add_fixed<21>(x, y); break;
      case 22: add_fixed<22>(x, y); break;
      case 23: add_fixed<23>(x, y); break;
      case 24: add_fixed<24>(x, y); break;
      default:
        GMM_ASSERT2(false, "add_for_short_vectors used with unsupported size");
        break;
    }
  }

  template<size_type N, class V1, class V2, class T>
  inline void add_fixed(const V1 &x, V2 &y, const T &a)
  {
    for(size_type i = 0; i != N; ++i) y[i] += a*x[i];
  }

  template<class V1, class V2, class T>
  inline void add_for_short_vectors(const V1 &x, V2 &y, const T &a, size_type n)
  {
    switch(n)
    {
      case  1: add_fixed<1>(x, y, a);  break;
      case  2: add_fixed<2>(x, y, a);  break;
      case  3: add_fixed<3>(x, y, a);  break;
      case  4: add_fixed<4>(x, y, a);  break;
      case  5: add_fixed<5>(x, y, a);  break;
      case  6: add_fixed<6>(x, y, a);  break;
      case  7: add_fixed<7>(x, y, a);  break;
      case  8: add_fixed<8>(x, y, a);  break;
      case  9: add_fixed<9>(x, y, a);  break;
      case 10: add_fixed<10>(x, y, a); break;
      case 11: add_fixed<11>(x, y, a); break;
      case 12: add_fixed<12>(x, y, a); break;
      case 13: add_fixed<13>(x, y, a); break;
      case 14: add_fixed<14>(x, y, a); break;
      case 15: add_fixed<15>(x, y, a); break;
      case 16: add_fixed<16>(x, y, a); break;
      case 17: add_fixed<17>(x, y, a); break;
      case 18: add_fixed<18>(x, y, a); break;
      case 19: add_fixed<19>(x, y, a); break;
      case 20: add_fixed<20>(x, y, a); break;
      case 21: add_fixed<21>(x, y, a); break;
      case 22: add_fixed<22>(x, y, a); break;
      case 23: add_fixed<23>(x, y, a); break;
      case 24: add_fixed<24>(x, y, a); break;
      default:
        GMM_ASSERT2(false, "add_for_short_vectors used with unsupported size");
        break;
    }
  }


# define axpy_interface(blas_name, base_type)                              \
  inline void add(const std::vector<base_type> &x,                         \
                  std::vector<base_type> &y) {                             \
    GMMLAPACK_TRACE("axpy_interface");                                     \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1); base_type a(1);       \
    if (n == 0) return;                                                    \
    else if (n < 25) add_for_short_vectors(x, y, n);                       \
    else blas_name(&n, &a, &x[0], &inc, &y[0], &inc);                      \
  }

  axpy_interface(saxpy_, BLAS_S)
  axpy_interface(daxpy_, BLAS_D)
  axpy_interface(caxpy_, BLAS_C)
  axpy_interface(zaxpy_, BLAS_Z)


# define axpy2_interface(blas_name, base_type)                             \
  inline void add                                                          \
  (const scaled_vector_const_ref<std::vector<base_type>,base_type> &x_,    \
   std::vector<base_type> &y) {                                            \
    GMMLAPACK_TRACE("axpy_interface");                                     \
    const BLAS_INT n=BLAS_INT(vect_size(y)), inc(1);                       \
    const std::vector<base_type>& x = *(linalg_origin(x_));                \
    const base_type a(x_.r);                                               \
    if (n == 0) return;                                                    \
    else if (n < 25) add_for_short_vectors(x, y, a, n);                    \
    else blas_name(&n, &a, &x[0], &inc, &y[0], &inc);                      \
  }

  axpy2_interface(saxpy_, BLAS_S)
  axpy2_interface(daxpy_, BLAS_D)
  axpy2_interface(caxpy_, BLAS_C)
  axpy2_interface(zaxpy_, BLAS_Z)


  /* ********************************************************************* */
  /* mult_add(A, x, z).                                                    */
  /* ********************************************************************* */

# define gemv_interface(param1, trans1, param2, trans2, blas_name,         \
                        base_type, orien)                                  \
  inline void mult_add_spec(param1(base_type), param2(base_type),          \
                            std::vector<base_type> &z, orien) {            \
    GMMLAPACK_TRACE("gemv_interface");                                     \
    trans1(base_type); trans2(base_type); base_type beta(1);               \
    const BLAS_INT m=BLAS_INT(mat_nrows(A)), lda(m),                       \
                   n=BLAS_INT(mat_ncols(A)), inc(1);                       \
    if (m && n) blas_name(&t, &m, &n, &alpha, &A(0,0), &lda, &x[0], &inc,  \
                          &beta, &z[0], &inc);                             \
    else gmm::clear(z);                                                    \
  }

  // First parameter
# define gem_p1_n(base_type)  const dense_matrix<base_type> &A
# define gem_trans1_n(base_type) const char t = 'N'
# define gem_p1_t(base_type)                                               \
         const transposed_col_ref<dense_matrix<base_type> *> &A_
# define gem_trans1_t(base_type) const dense_matrix<base_type> &A =        \
           *(linalg_origin(A_));                                           \
         const char t = 'T'
# define gem_p1_tc(base_type)                                              \
         const transposed_col_ref<const dense_matrix<base_type> *> &A_
# define gem_p1_c(base_type)                                               \
         const conjugated_col_matrix_const_ref<dense_matrix<base_type> > &A_
# define gem_trans1_c(base_type) const dense_matrix<base_type> &A =        \
           *(linalg_origin(A_));                                           \
         const char t = 'C'

  // second parameter
# define gemv_p2_n(base_type)  const std::vector<base_type> &x
# define gemv_trans2_n(base_type) base_type alpha(1)
# define gemv_p2_s(base_type)                                              \
    const scaled_vector_const_ref<std::vector<base_type>,base_type> &x_
# define gemv_trans2_s(base_type) const std::vector<base_type> &x =        \
           (*(linalg_origin(x_)));                                         \
         base_type alpha(x_.r)

  // Z <- AX + Z.
  gemv_interface(gem_p1_n,  gem_trans1_n,
                 gemv_p2_n, gemv_trans2_n, sgemv_, BLAS_S, col_major)
  gemv_interface(gem_p1_n,  gem_trans1_n,
                 gemv_p2_n, gemv_trans2_n, dgemv_, BLAS_D, col_major)
  gemv_interface(gem_p1_n,  gem_trans1_n,
                 gemv_p2_n, gemv_trans2_n, cgemv_, BLAS_C, col_major)
  gemv_interface(gem_p1_n,  gem_trans1_n,
                 gemv_p2_n, gemv_trans2_n, zgemv_, BLAS_Z, col_major)

  // Z <- transposed(A)X + Z.
  gemv_interface(gem_p1_t,  gem_trans1_t,
                 gemv_p2_n, gemv_trans2_n, sgemv_, BLAS_S, row_major)
  gemv_interface(gem_p1_t,  gem_trans1_t,
                 gemv_p2_n, gemv_trans2_n, dgemv_, BLAS_D, row_major)
  gemv_interface(gem_p1_t,  gem_trans1_t,
                 gemv_p2_n, gemv_trans2_n, cgemv_, BLAS_C, row_major)
  gemv_interface(gem_p1_t,  gem_trans1_t,
                 gemv_p2_n, gemv_trans2_n, zgemv_, BLAS_Z, row_major)

  // Z <- transposed(const A)X + Z.
  gemv_interface(gem_p1_tc, gem_trans1_t,
                 gemv_p2_n, gemv_trans2_n, sgemv_, BLAS_S, row_major)
  gemv_interface(gem_p1_tc, gem_trans1_t,
                 gemv_p2_n, gemv_trans2_n, dgemv_, BLAS_D, row_major)
  gemv_interface(gem_p1_tc, gem_trans1_t,
                 gemv_p2_n, gemv_trans2_n, cgemv_, BLAS_C, row_major)
  gemv_interface(gem_p1_tc, gem_trans1_t,
                 gemv_p2_n, gemv_trans2_n, zgemv_, BLAS_Z, row_major)

  // Z <- conjugated(A)X + Z.
  gemv_interface(gem_p1_c,  gem_trans1_c,
                 gemv_p2_n, gemv_trans2_n, sgemv_, BLAS_S, row_major)
  gemv_interface(gem_p1_c,  gem_trans1_c,
                 gemv_p2_n, gemv_trans2_n, dgemv_, BLAS_D, row_major)
  gemv_interface(gem_p1_c,  gem_trans1_c,
                 gemv_p2_n, gemv_trans2_n, cgemv_, BLAS_C, row_major)
  gemv_interface(gem_p1_c, gem_trans1_c,
                 gemv_p2_n, gemv_trans2_n, zgemv_, BLAS_Z, row_major)

  // Z <- A scaled(X) + Z.
  gemv_interface(gem_p1_n,  gem_trans1_n,
                 gemv_p2_s, gemv_trans2_s, sgemv_, BLAS_S, col_major)
  gemv_interface(gem_p1_n,  gem_trans1_n,
                 gemv_p2_s, gemv_trans2_s, dgemv_, BLAS_D, col_major)
  gemv_interface(gem_p1_n,  gem_trans1_n,
                 gemv_p2_s, gemv_trans2_s, cgemv_, BLAS_C, col_major)
  gemv_interface(gem_p1_n,  gem_trans1_n,
                 gemv_p2_s, gemv_trans2_s, zgemv_, BLAS_Z, col_major)

  // Z <- transposed(A) scaled(X) + Z.
  gemv_interface(gem_p1_t,  gem_trans1_t,
                 gemv_p2_s, gemv_trans2_s, sgemv_, BLAS_S, row_major)
  gemv_interface(gem_p1_t,  gem_trans1_t,
                 gemv_p2_s, gemv_trans2_s, dgemv_, BLAS_D, row_major)
  gemv_interface(gem_p1_t,  gem_trans1_t,
                 gemv_p2_s, gemv_trans2_s, cgemv_, BLAS_C, row_major)
  gemv_interface(gem_p1_t,  gem_trans1_t,
                 gemv_p2_s, gemv_trans2_s, zgemv_, BLAS_Z, row_major)

  // Z <- transposed(const A) scaled(X) + Z.
  gemv_interface(gem_p1_tc, gem_trans1_t,
                 gemv_p2_s, gemv_trans2_s, sgemv_, BLAS_S, row_major)
  gemv_interface(gem_p1_tc, gem_trans1_t,
                 gemv_p2_s, gemv_trans2_s, dgemv_, BLAS_D, row_major)
  gemv_interface(gem_p1_tc, gem_trans1_t,
                 gemv_p2_s, gemv_trans2_s, cgemv_, BLAS_C, row_major)
  gemv_interface(gem_p1_tc, gem_trans1_t,
                 gemv_p2_s, gemv_trans2_s, zgemv_, BLAS_Z, row_major)

  // Z <- conjugated(A) scaled(X) + Z.
  gemv_interface(gem_p1_c,  gem_trans1_c,
                 gemv_p2_s, gemv_trans2_s, sgemv_, BLAS_S, row_major)
  gemv_interface(gem_p1_c,  gem_trans1_c,
                 gemv_p2_s, gemv_trans2_s, dgemv_, BLAS_D, row_major)
  gemv_interface(gem_p1_c,  gem_trans1_c,
                 gemv_p2_s, gemv_trans2_s, cgemv_, BLAS_C, row_major)
  gemv_interface(gem_p1_c,  gem_trans1_c,
                 gemv_p2_s, gemv_trans2_s, zgemv_, BLAS_Z, row_major)


  /* ********************************************************************* */
  /* mult(A, x, y).                                                        */
  /* ********************************************************************* */

# define gemv_interface2(param1, trans1, param2, trans2, blas_name,        \
                         base_type, orien)                                 \
  inline void mult_spec(param1(base_type), param2(base_type),              \
                        std::vector<base_type> &z, orien) {                \
    GMMLAPACK_TRACE("gemv_interface2");                                    \
    trans1(base_type); trans2(base_type); base_type beta(0);               \
    const BLAS_INT m=BLAS_INT(mat_nrows(A)), lda(m),                       \
                   n=BLAS_INT(mat_ncols(A)), inc(1);                       \
    if (m && n)                                                            \
      blas_name(&t, &m, &n, &alpha, &A(0,0), &lda, &x[0], &inc, &beta,     \
                &z[0], &inc);                                              \
    else gmm::clear(z);                                                    \
  }

  // Y <- AX.
  gemv_interface2(gem_p1_n,  gem_trans1_n,
                  gemv_p2_n, gemv_trans2_n, sgemv_, BLAS_S, col_major)
  gemv_interface2(gem_p1_n,  gem_trans1_n,
                  gemv_p2_n, gemv_trans2_n, dgemv_, BLAS_D, col_major)
  gemv_interface2(gem_p1_n,  gem_trans1_n,
                  gemv_p2_n, gemv_trans2_n, cgemv_, BLAS_C, col_major)
  gemv_interface2(gem_p1_n,  gem_trans1_n,
                  gemv_p2_n, gemv_trans2_n, zgemv_, BLAS_Z, col_major)

  // Y <- transposed(A)X.
  gemv_interface2(gem_p1_t,  gem_trans1_t,
                  gemv_p2_n, gemv_trans2_n, sgemv_, BLAS_S, row_major)
  gemv_interface2(gem_p1_t,  gem_trans1_t,
                  gemv_p2_n, gemv_trans2_n, dgemv_, BLAS_D, row_major)
  gemv_interface2(gem_p1_t,  gem_trans1_t,
                  gemv_p2_n, gemv_trans2_n, cgemv_, BLAS_C, row_major)
  gemv_interface2(gem_p1_t,  gem_trans1_t,
                  gemv_p2_n, gemv_trans2_n, zgemv_, BLAS_Z, row_major)

  // Y <- transposed(const A)X.
  gemv_interface2(gem_p1_tc, gem_trans1_t,
                  gemv_p2_n, gemv_trans2_n, sgemv_, BLAS_S, row_major)
  gemv_interface2(gem_p1_tc, gem_trans1_t,
                  gemv_p2_n, gemv_trans2_n, dgemv_, BLAS_D, row_major)
  gemv_interface2(gem_p1_tc, gem_trans1_t,
                  gemv_p2_n, gemv_trans2_n, cgemv_, BLAS_C, row_major)
  gemv_interface2(gem_p1_tc, gem_trans1_t,
                  gemv_p2_n, gemv_trans2_n, zgemv_, BLAS_Z, row_major)

  // Y <- conjugated(A)X.
  gemv_interface2(gem_p1_c,  gem_trans1_c,
                  gemv_p2_n, gemv_trans2_n, sgemv_, BLAS_S, row_major)
  gemv_interface2(gem_p1_c,  gem_trans1_c,
                  gemv_p2_n, gemv_trans2_n, dgemv_, BLAS_D, row_major)
  gemv_interface2(gem_p1_c,  gem_trans1_c,
                  gemv_p2_n, gemv_trans2_n, cgemv_, BLAS_C, row_major)
  gemv_interface2(gem_p1_c,  gem_trans1_c,
                  gemv_p2_n, gemv_trans2_n, zgemv_, BLAS_Z, row_major)

  // Y <- A scaled(X).
  gemv_interface2(gem_p1_n,  gem_trans1_n,
                  gemv_p2_s, gemv_trans2_s, sgemv_, BLAS_S, col_major)
  gemv_interface2(gem_p1_n,  gem_trans1_n,
                  gemv_p2_s, gemv_trans2_s, dgemv_, BLAS_D, col_major)
  gemv_interface2(gem_p1_n,  gem_trans1_n,
                  gemv_p2_s, gemv_trans2_s, cgemv_, BLAS_C, col_major)
  gemv_interface2(gem_p1_n,  gem_trans1_n,
                  gemv_p2_s, gemv_trans2_s, zgemv_, BLAS_Z, col_major)

  // Y <- transposed(A) scaled(X).
  gemv_interface2(gem_p1_t,  gem_trans1_t,
                  gemv_p2_s, gemv_trans2_s, sgemv_, BLAS_S, row_major)
  gemv_interface2(gem_p1_t,  gem_trans1_t,
                  gemv_p2_s, gemv_trans2_s, dgemv_, BLAS_D, row_major)
  gemv_interface2(gem_p1_t,  gem_trans1_t,
                  gemv_p2_s, gemv_trans2_s, cgemv_, BLAS_C, row_major)
  gemv_interface2(gem_p1_t,  gem_trans1_t,
                  gemv_p2_s, gemv_trans2_s, zgemv_, BLAS_Z, row_major)

  // Y <- transposed(const A) scaled(X).
  gemv_interface2(gem_p1_tc, gem_trans1_t,
                  gemv_p2_s, gemv_trans2_s, sgemv_, BLAS_S, row_major)
  gemv_interface2(gem_p1_tc, gem_trans1_t,
                  gemv_p2_s, gemv_trans2_s, dgemv_, BLAS_D, row_major)
  gemv_interface2(gem_p1_tc, gem_trans1_t,
                  gemv_p2_s, gemv_trans2_s, cgemv_, BLAS_C, row_major)
  gemv_interface2(gem_p1_tc, gem_trans1_t,
                  gemv_p2_s, gemv_trans2_s, zgemv_, BLAS_Z, row_major)

  // Y <- conjugated(A) scaled(X).
  gemv_interface2(gem_p1_c,  gem_trans1_c,
                  gemv_p2_s, gemv_trans2_s, sgemv_, BLAS_S, row_major)
  gemv_interface2(gem_p1_c,  gem_trans1_c,
                  gemv_p2_s, gemv_trans2_s, dgemv_, BLAS_D, row_major)
  gemv_interface2(gem_p1_c,  gem_trans1_c,
                  gemv_p2_s, gemv_trans2_s, cgemv_, BLAS_C, row_major)
  gemv_interface2(gem_p1_c,  gem_trans1_c,
                  gemv_p2_s, gemv_trans2_s, zgemv_, BLAS_Z, row_major)


  /* ********************************************************************* */
  /* Rank one update.                                                      */
  /* ********************************************************************* */

# define ger_interface(blas_name, base_type)                               \
  inline void rank_one_update(const dense_matrix<base_type> &A,            \
                              const std::vector<base_type> &V,             \
                              const std::vector<base_type> &W) {           \
    GMMLAPACK_TRACE("ger_interface");                                      \
    const BLAS_INT m=BLAS_INT(mat_nrows(A)), lda(m),                       \
                   n=BLAS_INT(mat_ncols(A)), inc(1);                       \
    base_type alpha(1);                                                    \
    if (m && n)                                                            \
      blas_name(&m, &n, &alpha, &V[0], &inc, &W[0], &inc, &A(0,0), &lda);  \
  }

  ger_interface(sger_, BLAS_S)
  ger_interface(dger_, BLAS_D)
  ger_interface(cgerc_, BLAS_C)
  ger_interface(zgerc_, BLAS_Z)

# define ger_interface_sn(blas_name, base_type)                            \
  inline void rank_one_update(const dense_matrix<base_type> &A,            \
                              gemv_p2_s(base_type),                        \
                              const std::vector<base_type> &W) {           \
    GMMLAPACK_TRACE("ger_interface");                                      \
    gemv_trans2_s(base_type);                                              \
    const BLAS_INT m=BLAS_INT(mat_nrows(A)), lda(m),                       \
                   n=BLAS_INT(mat_ncols(A)), inc(1);                       \
    if (m && n)                                                            \
      blas_name(&m, &n, &alpha, &x[0], &inc, &W[0], &inc, &A(0,0), &lda);  \
  }

  ger_interface_sn(sger_, BLAS_S)
  ger_interface_sn(dger_, BLAS_D)
  ger_interface_sn(cgerc_, BLAS_C)
  ger_interface_sn(zgerc_, BLAS_Z)

# define ger_interface_ns(blas_name, base_type)                            \
  inline void rank_one_update(const dense_matrix<base_type> &A,            \
                              const std::vector<base_type> &V,             \
                              gemv_p2_s(base_type)) {                      \
    GMMLAPACK_TRACE("ger_interface");                                      \
    gemv_trans2_s(base_type);                                              \
    const BLAS_INT m=BLAS_INT(mat_nrows(A)), lda(m),                       \
                   n=BLAS_INT(mat_ncols(A)), inc(1);                       \
    base_type al2 = gmm::conj(alpha);                                      \
    if (m && n)                                                            \
      blas_name(&m, &n, &al2, &V[0], &inc, &x[0], &inc, &A(0,0), &lda);    \
  }

  ger_interface_ns(sger_, BLAS_S)
  ger_interface_ns(dger_, BLAS_D)
  ger_interface_ns(cgerc_, BLAS_C)
  ger_interface_ns(zgerc_, BLAS_Z)

  /* ********************************************************************* */
  /* dense matrix x dense matrix multiplication.                           */
  /* ********************************************************************* */

# define gemm_interface_nn(blas_name, base_type)                           \
  inline void mult_spec(const dense_matrix<base_type> &A,                  \
                        const dense_matrix<base_type> &B,                  \
                        dense_matrix<base_type> &C, c_mult) {              \
    GMMLAPACK_TRACE("gemm_interface_nn");                                  \
    const char t = 'N';                                                    \
    const BLAS_INT m=BLAS_INT(mat_nrows(A)), lda(m),                       \
                   k=BLAS_INT(mat_ncols(A)), ldb(k),                       \
                   n=BLAS_INT(mat_ncols(B)), ldc(m);                       \
    const base_type alpha(1), beta(0);                                     \
    if (m && k && n)                                                       \
      blas_name(&t, &t, &m, &n, &k, &alpha,                                \
                  &A(0,0), &lda, &B(0,0), &ldb, &beta, &C(0,0), &ldc);     \
    else gmm::clear(C);                                                    \
  }

  gemm_interface_nn(sgemm_, BLAS_S)
  gemm_interface_nn(dgemm_, BLAS_D)
  gemm_interface_nn(cgemm_, BLAS_C)
  gemm_interface_nn(zgemm_, BLAS_Z)

  /* ********************************************************************* */
  /* transposed(dense matrix) x dense matrix multiplication.               */
  /* ********************************************************************* */

# define gemm_interface_tn(blas_name, base_type, mat_type)                 \
  inline void mult_spec(                                                   \
         const transposed_col_ref<mat_type<base_type> *> &A_,              \
         const dense_matrix<base_type> &B,                                 \
         dense_matrix<base_type> &C, rcmult) {                             \
    GMMLAPACK_TRACE("gemm_interface_tn");                                  \
    const dense_matrix<base_type> &A = *(linalg_origin(A_));               \
    const char t = 'T', u = 'N';                                           \
    const BLAS_INT m=BLAS_INT(mat_ncols(A)), k=BLAS_INT(mat_nrows(A)),     \
                   n=BLAS_INT(mat_ncols(B)), lda(k), ldb(k), ldc(m);       \
    const base_type alpha(1), beta(0);                                     \
    if (m && k && n)                                                       \
      blas_name(&t, &u, &m, &n, &k, &alpha,                                \
                &A(0,0), &lda, &B(0,0), &ldb, &beta, &C(0,0), &ldc);       \
    else gmm::clear(C);                                                    \
  }

  gemm_interface_tn(sgemm_, BLAS_S, dense_matrix)
  gemm_interface_tn(dgemm_, BLAS_D, dense_matrix)
  gemm_interface_tn(cgemm_, BLAS_C, dense_matrix)
  gemm_interface_tn(zgemm_, BLAS_Z, dense_matrix)
  gemm_interface_tn(sgemm_, BLAS_S, const dense_matrix)
  gemm_interface_tn(dgemm_, BLAS_D, const dense_matrix)
  gemm_interface_tn(cgemm_, BLAS_C, const dense_matrix)
  gemm_interface_tn(zgemm_, BLAS_Z, const dense_matrix)

  /* ********************************************************************* */
  /* dense matrix x transposed(dense matrix) multiplication.               */
  /* ********************************************************************* */

# define gemm_interface_nt(blas_name, base_type, mat_type)                 \
  inline void                                                              \
  mult_spec(const dense_matrix<base_type> &A,                              \
            const transposed_col_ref<mat_type<base_type> *> &B_,           \
            dense_matrix<base_type> &C, r_mult) {                          \
    GMMLAPACK_TRACE("gemm_interface_nt");                                  \
    const dense_matrix<base_type> &B = *(linalg_origin(B_));               \
    const char t = 'N', u = 'T';                                           \
    const BLAS_INT m=BLAS_INT(mat_nrows(A)), k=BLAS_INT(mat_ncols(A)),     \
                   n=BLAS_INT(mat_nrows(B)), lda(m), ldb(n), ldc(m);       \
    const base_type alpha(1), beta(0);                                     \
    if (m && k && n)                                                       \
      blas_name(&t, &u, &m, &n, &k, &alpha,                                \
                &A(0,0), &lda, &B(0,0), &ldb, &beta, &C(0,0), &ldc);       \
    else gmm::clear(C);                                                    \
  }

  gemm_interface_nt(sgemm_, BLAS_S, dense_matrix)
  gemm_interface_nt(dgemm_, BLAS_D, dense_matrix)
  gemm_interface_nt(cgemm_, BLAS_C, dense_matrix)
  gemm_interface_nt(zgemm_, BLAS_Z, dense_matrix)
  gemm_interface_nt(sgemm_, BLAS_S, const dense_matrix)
  gemm_interface_nt(dgemm_, BLAS_D, const dense_matrix)
  gemm_interface_nt(cgemm_, BLAS_C, const dense_matrix)
  gemm_interface_nt(zgemm_, BLAS_Z, const dense_matrix)

  /* ********************************************************************* */
  /* transposed(dense matrix) x transposed(dense matrix) multiplication.   */
  /* ********************************************************************* */

# define gemm_interface_tt(blas_name, base_type, matA_type, matB_type)     \
  inline void                                                              \
  mult_spec(const transposed_col_ref<matA_type<base_type> *> &A_,          \
            const transposed_col_ref<matB_type<base_type> *> &B_,          \
            dense_matrix<base_type> &C, r_mult) {                          \
    GMMLAPACK_TRACE("gemm_interface_tt");                                  \
    const dense_matrix<base_type> &A = *(linalg_origin(A_));               \
    const dense_matrix<base_type> &B = *(linalg_origin(B_));               \
    const char t = 'T', u = 'T';                                           \
    const BLAS_INT m=BLAS_INT(mat_ncols(A)), k=BLAS_INT(mat_nrows(A)),     \
                   n=BLAS_INT(mat_nrows(B)), lda(k), ldb(n), ldc(m);       \
    base_type alpha(1), beta(0);                                           \
    if (m && k && n)                                                       \
      blas_name(&t, &u, &m, &n, &k, &alpha,                                \
                &A(0,0), &lda, &B(0,0), &ldb, &beta, &C(0,0), &ldc);       \
    else gmm::clear(C);                                                    \
  }

  gemm_interface_tt(sgemm_, BLAS_S, dense_matrix, dense_matrix)
  gemm_interface_tt(dgemm_, BLAS_D, dense_matrix, dense_matrix)
  gemm_interface_tt(cgemm_, BLAS_C, dense_matrix, dense_matrix)
  gemm_interface_tt(zgemm_, BLAS_Z, dense_matrix, dense_matrix)
  gemm_interface_tt(sgemm_, BLAS_S, const dense_matrix, dense_matrix)
  gemm_interface_tt(dgemm_, BLAS_D, const dense_matrix, dense_matrix)
  gemm_interface_tt(cgemm_, BLAS_C, const dense_matrix, dense_matrix)
  gemm_interface_tt(zgemm_, BLAS_Z, const dense_matrix, dense_matrix)
  gemm_interface_tt(sgemm_, BLAS_S, dense_matrix, const dense_matrix)
  gemm_interface_tt(dgemm_, BLAS_D, dense_matrix, const dense_matrix)
  gemm_interface_tt(cgemm_, BLAS_C, dense_matrix, const dense_matrix)
  gemm_interface_tt(zgemm_, BLAS_Z, dense_matrix, const dense_matrix)
  gemm_interface_tt(sgemm_, BLAS_S, const dense_matrix, const dense_matrix)
  gemm_interface_tt(dgemm_, BLAS_D, const dense_matrix, const dense_matrix)
  gemm_interface_tt(cgemm_, BLAS_C, const dense_matrix, const dense_matrix)
  gemm_interface_tt(zgemm_, BLAS_Z, const dense_matrix, const dense_matrix)


  /* ********************************************************************* */
  /* conjugated(dense matrix) x dense matrix multiplication.               */
  /* ********************************************************************* */

# define gemm_interface_cn(blas_name, base_type)                           \
  inline void mult_spec(                                                   \
      const conjugated_col_matrix_const_ref<dense_matrix<base_type> > &A_, \
      const dense_matrix<base_type> &B,                                    \
      dense_matrix<base_type> &C, rcmult) {                                \
    GMMLAPACK_TRACE("gemm_interface_cn");                                  \
    const dense_matrix<base_type> &A = *(linalg_origin(A_));               \
    const char t = 'C', u = 'N';                                           \
    const BLAS_INT m=BLAS_INT(mat_ncols(A)), k=BLAS_INT(mat_nrows(A)),     \
                   n=BLAS_INT(mat_ncols(B)), lda(k), ldb(k), ldc(m);       \
    const base_type alpha(1), beta(0);                                     \
    if (m && k && n)                                                       \
      blas_name(&t, &u, &m, &n, &k, &alpha,                                \
                &A(0,0), &lda, &B(0,0), &ldb, &beta, &C(0,0), &ldc);       \
    else gmm::clear(C);                                                    \
  }

  gemm_interface_cn(sgemm_, BLAS_S)
  gemm_interface_cn(dgemm_, BLAS_D)
  gemm_interface_cn(cgemm_, BLAS_C)
  gemm_interface_cn(zgemm_, BLAS_Z)

  /* ********************************************************************* */
  /* dense matrix x conjugated(dense matrix) multiplication.               */
  /* ********************************************************************* */

# define gemm_interface_nc(blas_name, base_type)                           \
  inline void mult_spec(                                                   \
      const dense_matrix<base_type> &A,                                    \
      const conjugated_col_matrix_const_ref<dense_matrix<base_type> > &B_, \
      dense_matrix<base_type> &C, c_mult, row_major) {                     \
    GMMLAPACK_TRACE("gemm_interface_nc");                                  \
    const dense_matrix<base_type> &B = *(linalg_origin(B_));               \
    const char t = 'N', u = 'C';                                           \
    const BLAS_INT m=BLAS_INT(mat_nrows(A)), k=BLAS_INT(mat_ncols(A)),     \
                   n=BLAS_INT(mat_nrows(B)), lda(m), ldb(n), ldc(m);       \
    const base_type alpha(1), beta(0);                                     \
    if (m && k && n)                                                       \
      blas_name(&t, &u, &m, &n, &k, &alpha,                                \
                &A(0,0), &lda, &B(0,0), &ldb, &beta, &C(0,0), &ldc);       \
    else gmm::clear(C);                                                    \
  }

  gemm_interface_nc(sgemm_, BLAS_S)
  gemm_interface_nc(dgemm_, BLAS_D)
  gemm_interface_nc(cgemm_, BLAS_C)
  gemm_interface_nc(zgemm_, BLAS_Z)

  /* ********************************************************************* */
  /* conjugated(dense matrix) x conjugated(dense matrix) multiplication.   */
  /* ********************************************************************* */

# define gemm_interface_cc(blas_name, base_type)                           \
  inline void mult_spec(                                                   \
      const conjugated_col_matrix_const_ref<dense_matrix<base_type> > &A_, \
      const conjugated_col_matrix_const_ref<dense_matrix<base_type> > &B_, \
      dense_matrix<base_type> &C, r_mult) {                                \
    GMMLAPACK_TRACE("gemm_interface_cc");                                  \
    const dense_matrix<base_type> &A = *(linalg_origin(A_));               \
    const dense_matrix<base_type> &B = *(linalg_origin(B_));               \
    const char t = 'C', u = 'C';                                           \
    const BLAS_INT m=BLAS_INT(mat_ncols(A)), k=BLAS_INT(mat_nrows(A)),     \
                   n=BLAS_INT(mat_nrows(B)), lda(k), ldb(n), ldc(m);       \
    const base_type alpha(1), beta(0);                                     \
    if (m && k && n)                                                       \
      blas_name(&t, &u, &m, &n, &k, &alpha,                                \
                &A(0,0), &lda, &B(0,0), &ldb, &beta, &C(0,0), &ldc);       \
    else gmm::clear(C);                                                    \
  }

  gemm_interface_cc(sgemm_, BLAS_S)
  gemm_interface_cc(dgemm_, BLAS_D)
  gemm_interface_cc(cgemm_, BLAS_C)
  gemm_interface_cc(zgemm_, BLAS_Z)

  /* ********************************************************************* */
  /* Tri solve.                                                            */
  /* ********************************************************************* */

# define trsv_interface(f_name, LorU, param1, trans1, blas_name, base_type)\
  inline void f_name(param1(base_type), std::vector<base_type> &x,         \
                     size_type k, bool is_unit) {                          \
    GMMLAPACK_TRACE("trsv_interface");                                     \
    const char l = LorU; trans1(base_type); char d = is_unit ? 'U' : 'N';  \
    const BLAS_INT lda=BLAS_INT(mat_nrows(A)), inc(1), n=BLAS_INT(k);      \
    if (lda) blas_name(&l, &t, &d, &n, &A(0,0), &lda, &x[0], &inc);        \
  }

  // X <- LOWER(A)^{-1}X.
  trsv_interface(lower_tri_solve, 'L', gem_p1_n, gem_trans1_n, strsv_, BLAS_S)
  trsv_interface(lower_tri_solve, 'L', gem_p1_n, gem_trans1_n, dtrsv_, BLAS_D)
  trsv_interface(lower_tri_solve, 'L', gem_p1_n, gem_trans1_n, ctrsv_, BLAS_C)
  trsv_interface(lower_tri_solve, 'L', gem_p1_n, gem_trans1_n, ztrsv_, BLAS_Z)

  // X <- UPPER(A)^{-1}X.
  trsv_interface(upper_tri_solve, 'U', gem_p1_n, gem_trans1_n, strsv_, BLAS_S)
  trsv_interface(upper_tri_solve, 'U', gem_p1_n, gem_trans1_n, dtrsv_, BLAS_D)
  trsv_interface(upper_tri_solve, 'U', gem_p1_n, gem_trans1_n, ctrsv_, BLAS_C)
  trsv_interface(upper_tri_solve, 'U', gem_p1_n, gem_trans1_n, ztrsv_, BLAS_Z)

  // X <- LOWER(transposed(A))^{-1}X.
  trsv_interface(lower_tri_solve, 'U', gem_p1_t, gem_trans1_t, strsv_, BLAS_S)
  trsv_interface(lower_tri_solve, 'U', gem_p1_t, gem_trans1_t, dtrsv_, BLAS_D)
  trsv_interface(lower_tri_solve, 'U', gem_p1_t, gem_trans1_t, ctrsv_, BLAS_C)
  trsv_interface(lower_tri_solve, 'U', gem_p1_t, gem_trans1_t, ztrsv_, BLAS_Z)

  // X <- UPPER(transposed(A))^{-1}X.
  trsv_interface(upper_tri_solve, 'L', gem_p1_t, gem_trans1_t, strsv_, BLAS_S)
  trsv_interface(upper_tri_solve, 'L', gem_p1_t, gem_trans1_t, dtrsv_, BLAS_D)
  trsv_interface(upper_tri_solve, 'L', gem_p1_t, gem_trans1_t, ctrsv_, BLAS_C)
  trsv_interface(upper_tri_solve, 'L', gem_p1_t, gem_trans1_t, ztrsv_, BLAS_Z)

  // X <- LOWER(transposed(const A))^{-1}X.
  trsv_interface(lower_tri_solve, 'U', gem_p1_tc, gem_trans1_t, strsv_, BLAS_S)
  trsv_interface(lower_tri_solve, 'U', gem_p1_tc, gem_trans1_t, dtrsv_, BLAS_D)
  trsv_interface(lower_tri_solve, 'U', gem_p1_tc, gem_trans1_t, ctrsv_, BLAS_C)
  trsv_interface(lower_tri_solve, 'U', gem_p1_tc, gem_trans1_t, ztrsv_, BLAS_Z)

  // X <- UPPER(transposed(const A))^{-1}X.
  trsv_interface(upper_tri_solve, 'L', gem_p1_tc, gem_trans1_t, strsv_, BLAS_S)
  trsv_interface(upper_tri_solve, 'L', gem_p1_tc, gem_trans1_t, dtrsv_, BLAS_D)
  trsv_interface(upper_tri_solve, 'L', gem_p1_tc, gem_trans1_t, ctrsv_, BLAS_C)
  trsv_interface(upper_tri_solve, 'L', gem_p1_tc, gem_trans1_t, ztrsv_, BLAS_Z)

  // X <- LOWER(conjugated(A))^{-1}X.
  trsv_interface(lower_tri_solve, 'U', gem_p1_c, gem_trans1_c, strsv_, BLAS_S)
  trsv_interface(lower_tri_solve, 'U', gem_p1_c, gem_trans1_c, dtrsv_, BLAS_D)
  trsv_interface(lower_tri_solve, 'U', gem_p1_c, gem_trans1_c, ctrsv_, BLAS_C)
  trsv_interface(lower_tri_solve, 'U', gem_p1_c, gem_trans1_c, ztrsv_, BLAS_Z)

  // X <- UPPER(conjugated(A))^{-1}X.
  trsv_interface(upper_tri_solve, 'L', gem_p1_c, gem_trans1_c, strsv_, BLAS_S)
  trsv_interface(upper_tri_solve, 'L', gem_p1_c, gem_trans1_c, dtrsv_, BLAS_D)
  trsv_interface(upper_tri_solve, 'L', gem_p1_c, gem_trans1_c, ctrsv_, BLAS_C)
  trsv_interface(upper_tri_solve, 'L', gem_p1_c, gem_trans1_c, ztrsv_, BLAS_Z)
}

#endif // GMM_BLAS_INTERFACE_H

#endif // GMM_USES_BLAS
