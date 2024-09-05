// -*- c++ -*- (enables emacs c++ mode)
//===========================================================================
//
// Copyright (C) 1997-2008 Yves Renard
//
// This file is a part of GETFEM++
//
// Getfem++  is  free software;  you  can  redistribute  it  and/or modify it
// under  the  terms  of the  GNU  Lesser General Public License as published
// by  the  Free Software Foundation;  either version 2.1 of the License,  or
// (at your option) any later version.
// This program  is  distributed  in  the  hope  that it will be useful,  but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or  FITNESS  FOR  A PARTICULAR PURPOSE.  See the GNU Lesser General Public
// License for more details.
// You  should  have received a copy of the GNU Lesser General Public License
// along  with  this program;  if not, write to the Free Software Foundation,
// Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.
//
// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.
//
//===========================================================================

/**@file gmm_modified_gram_schmidt.h
   @author  Andrew Lumsdaine <lums@osl.iu.edu>, Lie-Quan Lee     <llee@osl.iu.edu>
   @date October 13, 2002.
   @brief Modified Gram-Schmidt orthogonalization
*/

#ifndef GMM_MODIFIED_GRAM_SCHMIDT_H
#define GMM_MODIFIED_GRAM_SCHMIDT_H

#include "gmm_kernel.h"

namespace gmm {

  template <typename T>
  class modified_gram_schmidt {
  protected:
    typedef dense_matrix<T> MAT;
    MAT M;

  public:

    modified_gram_schmidt(int restart, size_t s) : M(s, restart+1) {}

    typename linalg_traits<MAT>::const_sub_col_type
      operator[](size_t i) const { return mat_const_col(M, i); }

    typename linalg_traits<MAT>::sub_col_type
      operator[](size_t i) { return mat_col(M, i); }

    inline size_type nrows(void) const { return M.nrows(); }
    inline size_type ncols(void) const { return M.ncols(); }
    MAT &mat(void) { return M; }
    const MAT &mat(void) const { return M; }
    
  };

  template <typename T, typename VecHi> inline
  void orthogonalize(modified_gram_schmidt<T>& V, const VecHi& Hi_, size_t i) {
    VecHi& Hi = const_cast<VecHi&>(Hi_);
    
    for (size_t k = 0; k <= i; k++) {
      Hi[k] = gmm::vect_hp(V[i+1], V[k]);
      gmm::add(gmm::scaled(V[k], -Hi[k]), V[i+1]);
    }
  }

  template <typename T, typename VecHi>
  void orthogonalize_with_refinment(modified_gram_schmidt<T>& V,
				    const VecHi& Hi_, size_t i) {
    VecHi& Hi = const_cast<VecHi&>(Hi_);
    orthogonalize(V, Hi_, i);
    
    sub_interval SUBI(0, V.nrows()), SUBJ(0, i+1);
    std::vector<T> corr(i+1);
    gmm::mult(conjugated(sub_matrix(V.mat(), SUBI, SUBJ)),
	      V[i+1], corr);
    gmm::mult(sub_matrix(V.mat(), SUBI, SUBJ),
	      scaled(corr, T(-1)), V[i+1],V[i+1]);
    gmm::add(corr, sub_vector(Hi, SUBJ));
  }
  
  template <typename T, typename VecS, typename VecX>
  void combine(modified_gram_schmidt<T>& V, const VecS& s, VecX& x, size_t i)
  { for (size_t j = 0; j < i; ++j) gmm::add(gmm::scaled(V[j], s[j]), x); }
}

#endif
