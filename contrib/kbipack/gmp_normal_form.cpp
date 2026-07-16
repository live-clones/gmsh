/*
   Implementation for integer computation of Hermite and Smith normal
   forms of matrices of modest size.

   Implementation: Dense matrix with GMP-library's mpz_t elements to
                   hold huge integers.

   Algorithm: Kannan - Bachem algorithm with improvement by
              Chou and Collins. Expects a large number of unit invariant
	      factors and takes advantage of them as they appear.

   References:
    [1] Ravindran Kannan, Achim Bachem:
        "Polynomial algorithms for computing the Smith and Hermite normal
	forms of an integer matrix",
	SIAM J. Comput., vol. 8, no. 5, pp. 499-507, 1979.
    [2] Tsu-Wu J.Chou, George E. Collins:
        "Algorithms for the solution of systems of linear Diophantine
	equations",
	SIAM J. Comput., vol. 11, no. 4, pp. 687-708, 1982.
    [3] GMP homepage http://www.swox.com/gmp/
    [4] GNU gmp page http://www.gnu.org/software/gmp/

   Copyright (C) 30.10.2003 Saku Suuriniemi TUT/CEM

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA

   Saku Suuriniemi, TUT/Electromagetics
   P.O.Box 692, FIN-33101 Tampere, Finland
   saku.suuriniemi@tut.fi

   $Id: gmp_normal_form.c,v 1.1 2009-03-30 14:10:57 matti Exp $
*/

#include<stdlib.h>
#include<stdint.h>
#include<limits.h>
#include"gmp_blas.h"
#include"gmp_matrix.h"
#include"gmp_normal_form.h"


/* The unaltered matrix and identity left and right factors */
static gmp_normal_form *
create_gmp_trivial_normal_form(gmp_matrix * A,
			       inverted_flag left_inverted,
			       inverted_flag right_inverted)
{
  size_t rows, cols;

  gmp_normal_form * new_nf;
  if(A == NULL)
    {
      return NULL;
    }

  new_nf = (gmp_normal_form *) malloc(sizeof(gmp_normal_form));
  if(new_nf == NULL)
    {
      destroy_gmp_matrix(A);
      return NULL;
    }

  rows = A -> rows;
  cols = A -> cols;

  if((rows == 0) || (cols == 0))
    {
      destroy_gmp_matrix(A);
      free(new_nf);
      return NULL;
    }

  new_nf->left = create_gmp_matrix_identity(rows);
  if(new_nf->left == NULL)
    {
      destroy_gmp_matrix(A);
      free(new_nf);
      return NULL;
    }

  new_nf->right = create_gmp_matrix_identity(cols);
  if(new_nf->right == NULL)
    {
      destroy_gmp_matrix(A);
      destroy_gmp_matrix(new_nf->left);
      free(new_nf);
      return NULL;
    }

  new_nf -> canonical = A;
  new_nf -> left_inverted  = left_inverted;
  new_nf -> right_inverted = right_inverted;

  return new_nf;
}

static int
gmp_Hermite_eliminate_step(gmp_matrix * L, gmp_matrix * U,
			   size_t col, inverted_flag right_inverted)
{
  size_t ind, row_limit;
  mpz_t  pivot, elem;
  mpz_t  bez1, bez2, gc_div;
  mpz_t  cff1, cff2;

  mpz_init(pivot);
  mpz_init(elem);
  mpz_init(bez1);
  mpz_init(bez2);
  mpz_init(cff1);
  mpz_init(cff2);
  mpz_init(gc_div);

  row_limit = (L->rows >= col) ?
    col-1 :
    L->rows;

  for(ind = 1; ind <= row_limit; ind++)
    {
      gmp_matrix_get_elem(elem, ind, col, L);

      /* Eliminate only if nonzero */
      if(mpz_sgn (elem) != 0)
	{
	  gmp_matrix_get_elem(pivot, ind, ind, L);

	  /* Extended Euclid's:
	     bez1*pivot+bez2*elem = gc_div */
	  gmp_blas_rotg(gc_div, bez1, bez2, pivot, elem);

	  /* Make cff1 = -elem/gc_div */
	  mpz_divexact(cff1, elem,  gc_div);
	  mpz_neg     (cff1, cff1);
	  /* Make cff2 = pivot/gc_div */
	  mpz_divexact(cff2, pivot, gc_div);

	  /* Update the HNF canonical matrix */
	  gmp_matrix_col_rot(bez1, bez2, ind,
			     cff1, cff2, col,
			     L);

	  /* Update the unimodular factor matrix */
	  if(right_inverted == INVERTED)
	    {
	      gmp_matrix_col_rot(bez1, bez2, ind,
				 cff1, cff2, col,
				 U);
	    }
	  else
	    {

	      /* [bez1, -elem/gc_div] [pivot/gc_div, elem/gc_div]
		 [bez2, pivot/gc_div] [-bez2,        bez1       ]  = I_2 */
	      mpz_neg(cff1, cff1);
	      mpz_neg(bez2, bez2);
	      gmp_matrix_row_rot(cff2, cff1, ind,
				 bez2, bez1, col,
				 U);
	    }
	}
    }
  mpz_clear(pivot);
  mpz_clear(elem);
  mpz_clear(bez1);
  mpz_clear(bez2);
  mpz_clear(cff1);
  mpz_clear(cff2);
  mpz_clear(gc_div);

  return EXIT_SUCCESS;
}



static int
gmp_Hermite_reduce_step(gmp_matrix * L,  gmp_matrix * U,
			size_t col, inverted_flag right_inverted)
{

  size_t i, j;
  mpz_t  pivot, elem;
  mpz_t  cff;

  mpz_init(pivot);
  mpz_init(elem);
  mpz_init(cff);

  if(col > (L->rows))
    {
      return EXIT_FAILURE;
    }

  /*  printf("Col = %i\n", col);
      printf("L before\n");
      gmp_matrix_printf(L);*/

  for(j = col-1; j >= 1; j--)
    {
      for(i = j+1; i <= col; i++)
	{
	  gmp_matrix_get_elem(pivot, i, i, L);
	  gmp_matrix_get_elem(elem,  i, j, L);
	  /* printf("   i %i j %i\n",i,j);  */

	  if((mpz_cmpabs(elem, pivot) >= 0) || (mpz_sgn(elem) < 0))
	    {
	      /* The objective:
		  0           <= elem + k*pivot < pivot
		  -elem       <= k*pivot        < pivot - elem
		  -elem/pivot <= k              < - elem/pivot + 1

		  Solution:
		  k = ceil(-elem/pivot)
	      */

	      /* Make cff = -elem */
	      mpz_neg    (cff, elem);
	      mpz_cdiv_q (cff, cff, pivot);

	      /* printf("col %i j %i\n", i, j);
		 printf("elem %i k %i pivot %i\n",
		 mpz_get_si(elem),
		 mpz_get_si(cff),
		 mpz_get_si(pivot));*/


	      gmp_matrix_add_col(cff, i, j, L);

	      /* Update the unimodular factor matrix */
	      if(right_inverted == INVERTED)
		{
		  gmp_matrix_add_col(cff, i, j, U);
		}

	      /* [1   0] [ 1   0] = [1 0]
		 [cff 1] [-cff 1]   [0 1] */
	      else
		{
		  mpz_neg (cff, cff);
		  gmp_matrix_add_row(cff, j, i, U);
		}

	      /* printf("\n");
		 gmp_matrix_printf(L);*/

	    }
	}
    }

/*  printf("L after\n"); */
/*   gmp_matrix_printf(L); */

  mpz_clear(pivot);
  mpz_clear(elem);
  mpz_clear(cff);
  return EXIT_SUCCESS;
}


static int
gmp_normal_form_make_Hermite(gmp_normal_form * nf)
{
  size_t rows, cols;
  size_t pivot_ind;
  size_t schur, colind;
  mpz_t  pivot;
  gmp_matrix * canonical;
  gmp_matrix * left;
  gmp_matrix * right;

  if(nf == NULL)
    {
      return EXIT_FAILURE;
    }

  /* OK, it's safe to get to business */
  canonical = nf->canonical;
  left      = nf->left;
  right     = nf->right;
  rows      = canonical -> rows;
  cols      = canonical -> cols;

  mpz_init(pivot);

  /* "schur" denotes where the present Schur complement starts */
  schur = 1;

  while((schur <= rows) && (schur <= cols))
    {
      /* Eliminate a column */
      if (schur > 1)
	{
	  gmp_Hermite_eliminate_step(canonical, right,
				     schur, nf->right_inverted);
	}

      /* Find a pivot */
      pivot_ind = gmp_matrix_col_inz(schur, rows, schur, canonical);


      /* If no nonzeros was found, the column is all zero, hence
	 settled with. Permute it to the end and decrement cols. */
      if(pivot_ind == 0)
	{
	  gmp_matrix_swap_cols(schur, cols, canonical);

	  if(nf -> right_inverted == INVERTED)
	    {
	      gmp_matrix_swap_cols(schur, cols, right);
	    }
	  else
	    {
	      gmp_matrix_swap_rows(schur, cols, right);
	    }

	  cols--;

	  /* When the whole column was zeroed, the diagonal
	     elements may have got reduced. Reduce the sub-
	     diagonals as well*/

	  if(schur > 1)
	    {
	      gmp_Hermite_reduce_step (canonical, right, schur-1,
				       nf -> right_inverted);
	    }
	}

      /* A nonzero pivot was found. Permute it to the diagonal position,
	 make it positive, and reduce the off-diagonals.
	 The schur complement now starts from the next diagonal. */
      else
	{
	  pivot_ind = schur+pivot_ind-1;
	  gmp_matrix_swap_rows(schur, pivot_ind, canonical);

	  if(nf->left_inverted == INVERTED)
	    {
	      gmp_matrix_swap_rows(schur, pivot_ind, left);
	    }
	  else
	    {
	      gmp_matrix_swap_cols(schur, pivot_ind, left);
	    }

	  /* Make the pivot positive */
	  gmp_matrix_get_elem(pivot, schur, schur, canonical);

	  if(mpz_cmp_si(pivot, 0) < 0)
	    {
	      gmp_matrix_negate_col(schur, canonical);

	      if(nf->right_inverted == INVERTED)
		{
		  gmp_matrix_negate_col(schur, right);
		}
	      else
		{
		  gmp_matrix_negate_row(schur, right);
		}
	    }

	  /*  Reduce off-diagonals */
	  gmp_Hermite_reduce_step (canonical, right, schur, nf -> right_inverted);

	  schur++;
	}
    }

  /* The Schur complement is now empty. There may still be uneliminated
     columns left (in case of a wide matrix) */

  colind = schur;
  while (colind <= cols)
    {
      gmp_Hermite_eliminate_step (canonical, right, colind,  nf->right_inverted);
      gmp_Hermite_reduce_step    (canonical, right, schur-1, nf->right_inverted);
      colind++;
    }

  mpz_clear(pivot);

  return EXIT_SUCCESS;
}



/* ================================================================= */
/* Fast native-integer Hermite normal form.                          */
/*                                                                   */
/* This runs exactly the same Kannan-Bachem reduction as             */
/* gmp_normal_form_make_Hermite above, but on int64 storage instead  */
/* of mpz_t.  The incidence matrices of a cell complex are totally   */
/* unimodular, so the Hermite form and its unimodular factors have   */
/* tiny entries; keeping them in machine words removes the per-op GMP */
/* overhead that otherwise dominates.  Every arithmetic step is       */
/* range-checked against int64; on overflow (or if the input entries  */
/* are already too large) the caller discards the attempt and runs    */
/* the exact mpz path, so the result is always correct.              */
/*                                                                   */
/* Column-major storage, 0-based element access. */
#define HE(a, rows, i0, j0) ((a)[(size_t)(j0) * (size_t)(rows) + (size_t)(i0)])

static int he_fits(__int128 v)
{
  return v <= (__int128)INT64_MAX && v >= (__int128)INT64_MIN;
}

/* g = |gcd(a,b)| >= 0, with s*a + t*b = g (minimal cofactors). */
static int64_t he_gcdext(int64_t a, int64_t b, int64_t *s, int64_t *t)
{
  int64_t old_r = a, r = b, old_s = 1, s1 = 0, old_t = 0, t1 = 1;
  while(r != 0) {
    int64_t q = old_r / r, tmp;
    tmp = old_r - q * r; old_r = r; r = tmp;
    tmp = old_s - q * s1; old_s = s1; s1 = tmp;
    tmp = old_t - q * t1; old_t = t1; t1 = tmp;
  }
  if(old_r < 0) { old_r = -old_r; old_s = -old_s; old_t = -old_t; }
  *s = old_s; *t = old_t;
  return old_r;
}

/* ceil(n/d) for d > 0 */
static int64_t he_cdiv_q(int64_t n, int64_t d)
{
  int64_t q = n / d, rem = n % d;
  if(rem != 0 && ((rem > 0) == (d > 0))) q++;
  return q;
}

/* Elementary operations on int64 column-major matrices (1-based targets). */
static void he_swap_cols(size_t c1, size_t c2, int64_t *M, size_t rows)
{
  size_t i;
  if(c1 == c2) return;
  for(i = 0; i < rows; i++) {
    int64_t t = HE(M, rows, i, c1 - 1);
    HE(M, rows, i, c1 - 1) = HE(M, rows, i, c2 - 1);
    HE(M, rows, i, c2 - 1) = t;
  }
}
static void he_swap_rows(size_t r1, size_t r2, int64_t *M, size_t rows, size_t cols)
{
  size_t j;
  if(r1 == r2) return;
  for(j = 0; j < cols; j++) {
    int64_t t = HE(M, rows, r1 - 1, j);
    HE(M, rows, r1 - 1, j) = HE(M, rows, r2 - 1, j);
    HE(M, rows, r2 - 1, j) = t;
  }
}
static void he_neg_col(size_t c, int64_t *M, size_t rows)
{ size_t i; for(i = 0; i < rows; i++) HE(M, rows, i, c - 1) = -HE(M, rows, i, c - 1); }
static void he_neg_row(size_t r, int64_t *M, size_t rows, size_t cols)
{ size_t j; for(j = 0; j < cols; j++) HE(M, rows, r - 1, j) = -HE(M, rows, r - 1, j); }

/* col_dst <- cff*col_src + col_dst */
static void he_add_col(int64_t cff, size_t src, size_t dst,
                       int64_t *M, size_t rows, int *of)
{
  size_t i;
  for(i = 0; i < rows; i++) {
    __int128 v = (__int128)HE(M, rows, i, dst - 1)
               + (__int128)cff * HE(M, rows, i, src - 1);
    if(!he_fits(v)) { *of = 1; return; }
    HE(M, rows, i, dst - 1) = (int64_t)v;
  }
}
/* row_dst <- cff*row_src + row_dst */
static void he_add_row(int64_t cff, size_t src, size_t dst,
                       int64_t *M, size_t rows, size_t cols, int *of)
{
  size_t j;
  for(j = 0; j < cols; j++) {
    __int128 v = (__int128)HE(M, rows, dst - 1, j)
               + (__int128)cff * HE(M, rows, src - 1, j);
    if(!he_fits(v)) { *of = 1; return; }
    HE(M, rows, dst - 1, j) = (int64_t)v;
  }
}
/* col1 <- a*col1 + b*col2 ; col2 <- c*col1_old + d*col2 */
static void he_col_rot(int64_t a, int64_t b, size_t c1,
                       int64_t c, int64_t d, size_t c2,
                       int64_t *M, size_t rows, int *of)
{
  size_t i;
  for(i = 0; i < rows; i++) {
    int64_t x = HE(M, rows, i, c1 - 1), y = HE(M, rows, i, c2 - 1);
    __int128 nx = (__int128)a * x + (__int128)b * y;
    __int128 ny = (__int128)c * x + (__int128)d * y;
    if(!he_fits(nx) || !he_fits(ny)) { *of = 1; return; }
    HE(M, rows, i, c1 - 1) = (int64_t)nx;
    HE(M, rows, i, c2 - 1) = (int64_t)ny;
  }
}
static void he_row_rot(int64_t a, int64_t b, size_t r1,
                       int64_t c, int64_t d, size_t r2,
                       int64_t *M, size_t rows, size_t cols, int *of)
{
  size_t j;
  for(j = 0; j < cols; j++) {
    int64_t x = HE(M, rows, r1 - 1, j), y = HE(M, rows, r2 - 1, j);
    __int128 nx = (__int128)a * x + (__int128)b * y;
    __int128 ny = (__int128)c * x + (__int128)d * y;
    if(!he_fits(nx) || !he_fits(ny)) { *of = 1; return; }
    HE(M, rows, r1 - 1, j) = (int64_t)nx;
    HE(M, rows, r2 - 1, j) = (int64_t)ny;
  }
}
/* first index in [r1,r2] (1-based) with M(.,c)!=0, as offset in [1..], else 0 */
static size_t he_col_inz(size_t r1, size_t r2, size_t c, int64_t *M, size_t rows)
{
  size_t k;
  for(k = r1; k <= r2; k++)
    if(HE(M, rows, k - 1, c - 1) != 0) return k - r1 + 1;
  return 0;
}

/* Eliminate column "col" against the leading diagonal (mirrors
   gmp_Hermite_eliminate_step); column ops on C are mirrored onto R. */
static void he_eliminate(int64_t *C, size_t m, int64_t *R, size_t nR,
                         inverted_flag rinv, size_t col, int *of)
{
  size_t row_limit = (m >= col) ? col - 1 : m, ind;
  for(ind = 1; ind <= row_limit && !*of; ind++) {
    int64_t elem = HE(C, m, ind - 1, col - 1);
    if(elem == 0) continue;
    int64_t pivot = HE(C, m, ind - 1, ind - 1);
    int64_t bez1, bez2;
    int64_t g = he_gcdext(pivot, elem, &bez1, &bez2);
    int64_t cff1 = -(elem / g);   /* -elem/g */
    int64_t cff2 = pivot / g;     /*  pivot/g */
    he_col_rot(bez1, bez2, ind, cff1, cff2, col, C, m, of);
    if(rinv == INVERTED)
      he_col_rot(bez1, bez2, ind, cff1, cff2, col, R, nR, of);
    else
      /* row_rot(pivot/g, elem/g, ind, -bez2, bez1, col) on R */
      he_row_rot(cff2, -cff1, ind, -bez2, bez1, col, R, nR, nR, of);
  }
}

/* Reduce off-diagonals of the leading block (mirrors gmp_Hermite_reduce_step). */
static void he_reduce(int64_t *C, size_t m, int64_t *R, size_t nR,
                      inverted_flag rinv, size_t col, int *of)
{
  size_t i, j;
  if(col < 1 || col > m) return;
  for(j = col - 1; j >= 1 && !*of; j--) {
    for(i = j + 1; i <= col; i++) {
      int64_t pivot = HE(C, m, i - 1, i - 1);
      int64_t elem = HE(C, m, i - 1, j - 1);
      int64_t ap = pivot < 0 ? -pivot : pivot;
      int64_t ae = elem < 0 ? -elem : elem;
      if(ae >= ap || elem < 0) {
        int64_t cff = he_cdiv_q(-elem, pivot);
        he_add_col(cff, i, j, C, m, of);
        if(rinv == INVERTED) he_add_col(cff, i, j, R, nR, of);
        else he_add_row(-cff, j, i, R, nR, nR, of);
      }
    }
    if(j == 1) break;   /* avoid size_t underflow */
  }
}

/* Full Hermite reduction on int64 storage.  Returns 0 on success, 1 on
   overflow (in which case C/L/R are left partially modified and discarded). */
static int he_make_hermite(int64_t *C, size_t m, size_t n,
                           int64_t *L, int64_t *R,
                           inverted_flag linv, inverted_flag rinv, int *of)
{
  size_t schur = 1, ncols = n, colind;
  while(schur <= m && schur <= ncols && !*of) {
    if(schur > 1) he_eliminate(C, m, R, n, rinv, schur, of);
    if(*of) return 1;
    size_t pivot_off = he_col_inz(schur, m, schur, C, m);
    if(pivot_off == 0) {
      he_swap_cols(schur, ncols, C, m);
      if(rinv == INVERTED) he_swap_cols(schur, ncols, R, n);
      else he_swap_rows(schur, ncols, R, n, n);
      ncols--;
      if(schur > 1) he_reduce(C, m, R, n, rinv, schur - 1, of);
    }
    else {
      size_t pivot_ind = schur + pivot_off - 1;
      he_swap_rows(schur, pivot_ind, C, m, n);
      if(linv == INVERTED) he_swap_rows(schur, pivot_ind, L, m, m);
      else he_swap_cols(schur, pivot_ind, L, m);
      if(HE(C, m, schur - 1, schur - 1) < 0) {
        he_neg_col(schur, C, m);
        if(rinv == INVERTED) he_neg_col(schur, R, n);
        else he_neg_row(schur, R, n, n);
      }
      he_reduce(C, m, R, n, rinv, schur, of);
      schur++;
    }
  }
  colind = schur;
  while(colind <= ncols && !*of) {
    he_eliminate(C, m, R, n, rinv, colind, of);
    he_reduce(C, m, R, n, rinv, schur - 1, of);
    colind++;
  }
  return *of ? 1 : 0;
}

/* Portable store of an int64 into an mpz_t. */
static void he_mpz_set_i64(mpz_t r, int64_t v)
{
#if LONG_MAX >= 9223372036854775807L
  mpz_set_si(r, (long)v);
#else
  int neg = (v < 0);
  uint64_t a = neg ? (uint64_t)(-(v + 1)) + 1u : (uint64_t)v;
  mpz_set_ui(r, (unsigned long)(a >> 32));
  mpz_mul_2exp(r, r, 32);
  mpz_add_ui(r, r, (unsigned long)(a & 0xffffffffu));
  if(neg) mpz_neg(r, r);
#endif
}

static gmp_matrix *he_to_gmp(const int64_t *a, size_t rows, size_t cols)
{
  gmp_matrix *M = create_gmp_matrix_zero(rows, cols);
  size_t idx;
  if(M == NULL) return NULL;
  for(idx = 0; idx < rows * cols; idx++) he_mpz_set_i64(M->storage[idx], a[idx]);
  return M;
}

/* Write an int64 canonical back into the (same-shape) input matrix's storage,
   so the input pointer stays valid as nf->canonical -- matching the mpz path,
   which repurposes A as the canonical rather than freeing it.  Some callers
   (ChainComplex::Inclusion) read the input pointer after the call. */
static void he_store_i64(gmp_matrix *M, const int64_t *a)
{
  size_t idx;
  for(idx = 0; idx < M->rows * M->cols; idx++) he_mpz_set_i64(M->storage[idx], a[idx]);
}

/* Attempt the native-integer Hermite form; returns the normal form on
   success, or NULL if the fast path is not applicable / overflowed (A is
   left untouched so the caller can run the exact mpz path). */
static gmp_normal_form *
he_fast_hermite(gmp_matrix *A, inverted_flag linv, inverted_flag rinv)
{
  size_t m = A->rows, n = A->cols, idx;
  size_t mb = 0;
  int of = 0;
  int64_t *C, *L, *R;
  gmp_normal_form *nf;

  for(idx = 0; idx < m * n; idx++) {
    size_t b = (mpz_sgn(A->storage[idx]) == 0) ? 0 : mpz_sizeinbase(A->storage[idx], 2);
    if(b > mb) mb = b;
    if(!mpz_fits_slong_p(A->storage[idx]) || mb > 31) return NULL;
  }

  C = (int64_t *)malloc(m * n * sizeof(int64_t));
  L = (int64_t *)calloc(m * m, sizeof(int64_t));
  R = (int64_t *)calloc(n * n, sizeof(int64_t));
  if(C == NULL || L == NULL || R == NULL) { free(C); free(L); free(R); return NULL; }

  for(idx = 0; idx < m * n; idx++) C[idx] = (int64_t)mpz_get_si(A->storage[idx]);
  for(idx = 0; idx < m; idx++) HE(L, m, idx, idx) = 1;
  for(idx = 0; idx < n; idx++) HE(R, n, idx, idx) = 1;

  if(he_make_hermite(C, m, n, L, R, linv, rinv, &of) != 0 || of) {
    free(C); free(L); free(R);
    return NULL;   /* overflow: fall back to the exact path */
  }

  /* Build the factors first; if anything fails, leave A untouched so the
     caller can still run the exact mpz path. */
  {
    gmp_matrix *newL = he_to_gmp(L, m, m);
    gmp_matrix *newR = he_to_gmp(R, n, n);
    nf = (gmp_normal_form *)malloc(sizeof(gmp_normal_form));
    if(newL == NULL || newR == NULL || nf == NULL) {
      destroy_gmp_matrix(newL); destroy_gmp_matrix(newR); free(nf);
      free(C); free(L); free(R);
      return NULL;
    }
    he_store_i64(A, C);          /* repurpose A as the canonical */
    nf->canonical = A;
    nf->left = newL;
    nf->right = newR;
    nf->left_inverted = linv;
    nf->right_inverted = rinv;
  }
  free(C); free(L); free(R);
  return nf;
}

gmp_normal_form *
create_gmp_Hermite_normal_form(gmp_matrix * A,
			       inverted_flag left_inverted,
			       inverted_flag right_inverted)
{
  gmp_normal_form * new_nf;

  if(A == NULL)
    {
      return NULL;
    }

  /* Try the fast native-integer path; it returns NULL (leaving A intact)
     when the entries are too large or an intermediate overflow occurs. */
  new_nf = he_fast_hermite(A, left_inverted, right_inverted);
  if(new_nf != NULL)
    {
      return new_nf;
    }

  new_nf =
    create_gmp_trivial_normal_form(A, left_inverted, right_inverted);

  if(new_nf == NULL)
    {
      /* A has been destroyed already */
      return NULL;
    }

  if(gmp_normal_form_make_Hermite(new_nf) != EXIT_SUCCESS)
    {
      destroy_gmp_normal_form(new_nf);
      return NULL;
    }

  return new_nf;
}


/* ================================================================= */
/* Fast Smith normal form.                                           */
/*                                                                   */
/* The previous driver reduced to Smith form by recomputing a full   */
/* Hermite normal form of the *entire* matrix -- plus a full         */
/* transposed Hermite -- once per invariant factor, which is         */
/* O(n^4)..O(n^5) big-integer work.  This version diagonalises       */
/* directly on the shrinking Schur complement: for each pivot        */
/* position it clears the pivot's row and column with extended-gcd   */
/* rotations restricted to the trailing submatrix, then enforces the */
/* divisibility of the trailing block by the pivot.  It never leaves  */
/* the trailing submatrix, so it is O(n^3) with small constants and  */
/* collapses to O(rank * n^2) when many invariant factors are units  */
/* (the common case in homology).                                    */
/*                                                                   */
/* Note on coefficient growth: like plain fraction-free elimination,  */
/* this method does not keep the trailing block reduced, so on large  */
/* *dense* full-rank inputs the intermediate integers can grow faster */
/* than in the reduction-based Kannan-Bachem driver.  Homology feeds  */
/* only small, sparse boundary/kernel matrices (entries in {-1,0,1}), */
/* where this method is both faster and growth-free; the dense regime */
/* is not exercised by Gmsh.                                          */
/*                                                                   */
/* The elementary-operation wrappers keep the *same* left/right      */
/* factor bookkeeping and INVERTED/NOT_INVERTED contract as the      */
/* Hermite code above: an operation on the canonical matrix is       */
/* mirrored either directly onto the factor (INVERTED) or as the     */
/* inverse operation on the opposite side (NOT_INVERTED).            */
/* ================================================================= */

#define GNF_ENT(M, i, j) ((M)->storage[(size_t)(j) * (M)->rows + (size_t)(i)])

/* ---- row operations (premultiply the canonical matrix) ---- */

static void gnf_row_swap(gmp_normal_form *nf, size_t r1, size_t r2)
{
  gmp_matrix_swap_rows(r1, r2, nf->canonical);
  if(nf->left_inverted == INVERTED)
    gmp_matrix_swap_rows(r1, r2, nf->left);
  else
    gmp_matrix_swap_cols(r1, r2, nf->left);
}

/* canonical: row_dst <- q*row_src + row_dst */
static void gnf_row_addmul(gmp_normal_form *nf, mpz_t q, size_t src, size_t dst)
{
  gmp_matrix_add_row(q, src, dst, nf->canonical);
  if(nf->left_inverted == INVERTED)
    gmp_matrix_add_row(q, src, dst, nf->left);
  else {
    mpz_t nq; mpz_init(nq); mpz_neg(nq, q);
    gmp_matrix_add_col(nq, dst, src, nf->left);   /* col_src += -q*col_dst */
    mpz_clear(nq);
  }
}

/* canonical rows (r1,r2) <- [[a,b],[c,d]] (r1,r2); det = a*d-b*c must be +-1 */
static void gnf_row_rot(gmp_normal_form *nf,
                        mpz_t a, mpz_t b, size_t r1,
                        mpz_t c, mpz_t d, size_t r2)
{
  gmp_matrix_row_rot(a, b, r1, c, d, r2, nf->canonical);
  if(nf->left_inverted == INVERTED)
    gmp_matrix_row_rot(a, b, r1, c, d, r2, nf->left);
  else {
    /* E^{-1} as a column rotation on the left factor.  With
       det = a*d-b*c (= +-1, so 1/det = det), the col_rot parameters are
       (det*d, -det*c, r1, -det*b, det*a, r2). */
    mpz_t det, t, ap, bp, cp, dp;
    mpz_init(det); mpz_init(t);
    mpz_init(ap); mpz_init(bp); mpz_init(cp); mpz_init(dp);
    mpz_mul(det, a, d); mpz_mul(t, b, c); mpz_sub(det, det, t);
    mpz_mul(ap, det, d);
    mpz_mul(bp, det, c); mpz_neg(bp, bp);
    mpz_mul(cp, det, b); mpz_neg(cp, cp);
    mpz_mul(dp, det, a);
    gmp_matrix_col_rot(ap, bp, r1, cp, dp, r2, nf->left);
    mpz_clear(det); mpz_clear(t);
    mpz_clear(ap); mpz_clear(bp); mpz_clear(cp); mpz_clear(dp);
  }
}

/* ---- column operations (postmultiply the canonical matrix) ---- */

static void gnf_col_swap(gmp_normal_form *nf, size_t c1, size_t c2)
{
  gmp_matrix_swap_cols(c1, c2, nf->canonical);
  if(nf->right_inverted == INVERTED)
    gmp_matrix_swap_cols(c1, c2, nf->right);
  else
    gmp_matrix_swap_rows(c1, c2, nf->right);
}

static void gnf_col_neg(gmp_normal_form *nf, size_t c)
{
  gmp_matrix_negate_col(c, nf->canonical);
  if(nf->right_inverted == INVERTED)
    gmp_matrix_negate_col(c, nf->right);
  else
    gmp_matrix_negate_row(c, nf->right);
}

/* canonical: col_dst <- q*col_src + col_dst */
static void gnf_col_addmul(gmp_normal_form *nf, mpz_t q, size_t src, size_t dst)
{
  gmp_matrix_add_col(q, src, dst, nf->canonical);
  if(nf->right_inverted == INVERTED)
    gmp_matrix_add_col(q, src, dst, nf->right);
  else {
    mpz_t nq; mpz_init(nq); mpz_neg(nq, q);
    gmp_matrix_add_row(nq, dst, src, nf->right);   /* row_src += -q*row_dst */
    mpz_clear(nq);
  }
}

/* canonical cols (c1,c2) <- (c1,c2) [[a,c],[b,d]] via col_rot(a,b,c1,c,d,c2) */
static void gnf_col_rot(gmp_normal_form *nf,
                        mpz_t a, mpz_t b, size_t c1,
                        mpz_t c, mpz_t d, size_t c2)
{
  gmp_matrix_col_rot(a, b, c1, c, d, c2, nf->canonical);
  if(nf->right_inverted == INVERTED)
    gmp_matrix_col_rot(a, b, c1, c, d, c2, nf->right);
  else {
    /* F^{-1} as a row rotation on the right factor.  The right-multiplying
       factor is [[a,c],[b,d]] with det = a*d-b*c; the row_rot parameters are
       (det*d, -det*c, c1, -det*b, det*a, c2). */
    mpz_t det, t, ap, bp, cp, dp;
    mpz_init(det); mpz_init(t);
    mpz_init(ap); mpz_init(bp); mpz_init(cp); mpz_init(dp);
    mpz_mul(det, a, d); mpz_mul(t, b, c); mpz_sub(det, det, t);
    mpz_mul(ap, det, d);
    mpz_mul(bp, det, c); mpz_neg(bp, bp);
    mpz_mul(cp, det, b); mpz_neg(cp, cp);
    mpz_mul(dp, det, a);
    gmp_matrix_row_rot(ap, bp, c1, cp, dp, c2, nf->right);
    mpz_clear(det); mpz_clear(t);
    mpz_clear(ap); mpz_clear(bp); mpz_clear(cp); mpz_clear(dp);
  }
}

/* Zero canonical(i,t) against the pivot canonical(t,t) (both entries live in
   column t).  When the pivot divides the entry we subtract a multiple of the
   pivot row, leaving the pivot row untouched; otherwise we apply an
   extended-gcd row rotation, which strictly shrinks the pivot.  Mixing the two
   is essential: a gcd rotation in the divisible case can return a Bezout
   coefficient of 0 and merely shuffle rows, never making progress. */
static void gnf_clear_below(gmp_normal_form *nf, size_t t, size_t i,
                            mpz_t g, mpz_t bez1, mpz_t bez2,
                            mpz_t c2, mpz_t d2, mpz_t p, mpz_t e)
{
  gmp_matrix *C = nf->canonical;
  mpz_set(p, GNF_ENT(C, t, t));
  mpz_set(e, GNF_ENT(C, i, t));
  mpz_tdiv_qr(bez1, bez2, e, p);            /* e = bez1*p + bez2 */
  if(mpz_sgn(bez2) == 0) {
    mpz_neg(bez1, bez1);
    gnf_row_addmul(nf, bez1, t + 1, i + 1); /* row_i += -(e/p)*row_t */
    return;
  }
  mpz_gcdext(g, bez1, bez2, p, e);          /* bez1*p + bez2*e = g */
  mpz_divexact(c2, e, g); mpz_neg(c2, c2);  /* -e/g */
  mpz_divexact(d2, p, g);                    /*  p/g */
  gnf_row_rot(nf, bez1, bez2, t + 1, c2, d2, i + 1);
}

/* Zero canonical(t,j) against the pivot canonical(t,t) (both entries live in
   row t).  Same divisible/indivisible split as gnf_clear_below. */
static void gnf_clear_right(gmp_normal_form *nf, size_t t, size_t j,
                            mpz_t g, mpz_t bez1, mpz_t bez2,
                            mpz_t c2, mpz_t d2, mpz_t p, mpz_t e)
{
  gmp_matrix *C = nf->canonical;
  mpz_set(p, GNF_ENT(C, t, t));
  mpz_set(e, GNF_ENT(C, t, j));
  mpz_tdiv_qr(bez1, bez2, e, p);            /* e = bez1*p + bez2 */
  if(mpz_sgn(bez2) == 0) {
    mpz_neg(bez1, bez1);
    gnf_col_addmul(nf, bez1, t + 1, j + 1); /* col_j += -(e/p)*col_t */
    return;
  }
  mpz_gcdext(g, bez1, bez2, p, e);
  mpz_divexact(c2, e, g); mpz_neg(c2, c2);
  mpz_divexact(d2, p, g);
  gnf_col_rot(nf, bez1, bez2, t + 1, c2, d2, j + 1);
}

/* ================================================================= */
/* Fast native-integer Smith normal form.                            */
/*                                                                   */
/* This runs exactly the diagonalisation below on int64 storage, with */
/* the same pivot choice, clearing and factor bookkeeping, reusing    */
/* the he_* int64 primitives from the Hermite path.  Every arithmetic */
/* step is range-checked; on overflow (or entries too large to fit in */
/* 32 bits) the attempt is discarded and the exact mpz path runs.  The */
/* algorithm is reproduced step for step, so the result is bit-        */
/* identical to the mpz path (canonical and both transforms).         */
/* ================================================================= */

typedef struct {
  int64_t *C, *L, *R;   /* canonical m x n, left m x m, right n x n */
  size_t m, n;
  inverted_flag linv, rinv;
  int of;
} sn_ctx;

/* ---- row operations on the canonical matrix, mirrored onto L ---- */
static void sn_row_swap(sn_ctx *x, size_t r1, size_t r2)
{
  he_swap_rows(r1, r2, x->C, x->m, x->n);
  if(x->linv == INVERTED) he_swap_rows(r1, r2, x->L, x->m, x->m);
  else he_swap_cols(r1, r2, x->L, x->m);
}
static void sn_row_addmul(sn_ctx *x, int64_t q, size_t src, size_t dst)
{
  he_add_row(q, src, dst, x->C, x->m, x->n, &x->of);
  if(x->linv == INVERTED) he_add_row(q, src, dst, x->L, x->m, x->m, &x->of);
  else he_add_col(-q, dst, src, x->L, x->m, &x->of);   /* col_src += -q*col_dst */
}
static void sn_row_rot(sn_ctx *x, int64_t a, int64_t b, size_t r1,
                       int64_t c, int64_t d, size_t r2)
{
  he_row_rot(a, b, r1, c, d, r2, x->C, x->m, x->n, &x->of);
  if(x->linv == INVERTED)
    he_row_rot(a, b, r1, c, d, r2, x->L, x->m, x->m, &x->of);
  else {
    int64_t det = (int64_t)((__int128)a * d - (__int128)b * c);
    he_col_rot(det * d, -det * c, r1, -det * b, det * a, r2, x->L, x->m, &x->of);
  }
}

/* ---- column operations on the canonical matrix, mirrored onto R ---- */
static void sn_col_swap(sn_ctx *x, size_t c1, size_t c2)
{
  he_swap_cols(c1, c2, x->C, x->m);
  if(x->rinv == INVERTED) he_swap_cols(c1, c2, x->R, x->n);
  else he_swap_rows(c1, c2, x->R, x->n, x->n);
}
static void sn_col_neg(sn_ctx *x, size_t c)
{
  he_neg_col(c, x->C, x->m);
  if(x->rinv == INVERTED) he_neg_col(c, x->R, x->n);
  else he_neg_row(c, x->R, x->n, x->n);
}
static void sn_col_addmul(sn_ctx *x, int64_t q, size_t src, size_t dst)
{
  he_add_col(q, src, dst, x->C, x->m, &x->of);
  if(x->rinv == INVERTED) he_add_col(q, src, dst, x->R, x->n, &x->of);
  else he_add_row(-q, dst, src, x->R, x->n, x->n, &x->of);  /* row_src += -q*row_dst */
}
static void sn_col_rot(sn_ctx *x, int64_t a, int64_t b, size_t c1,
                       int64_t c, int64_t d, size_t c2)
{
  he_col_rot(a, b, c1, c, d, c2, x->C, x->m, &x->of);
  if(x->rinv == INVERTED)
    he_col_rot(a, b, c1, c, d, c2, x->R, x->n, &x->of);
  else {
    int64_t det = (int64_t)((__int128)a * d - (__int128)b * c);
    he_row_rot(det * d, -det * c, c1, -det * b, det * a, c2, x->R, x->n, x->n, &x->of);
  }
}

/* Zero C(i,t) against pivot C(t,t); subtract when the pivot divides, else a
   gcd rotation (mirrors gnf_clear_below).  Indices here are 0-based. */
static void sn_clear_below(sn_ctx *x, size_t t, size_t i)
{
  int64_t p = HE(x->C, x->m, t, t), e = HE(x->C, x->m, i, t);
  int64_t quo = e / p, rem = e - quo * p;
  if(rem == 0) { sn_row_addmul(x, -quo, t + 1, i + 1); return; }
  int64_t bez1, bez2, g = he_gcdext(p, e, &bez1, &bez2);
  sn_row_rot(x, bez1, bez2, t + 1, -(e / g), p / g, i + 1);
}
static void sn_clear_right(sn_ctx *x, size_t t, size_t j)
{
  int64_t p = HE(x->C, x->m, t, t), e = HE(x->C, x->m, t, j);
  int64_t quo = e / p, rem = e - quo * p;
  if(rem == 0) { sn_col_addmul(x, -quo, t + 1, j + 1); return; }
  int64_t bez1, bez2, g = he_gcdext(p, e, &bez1, &bez2);
  sn_col_rot(x, bez1, bez2, t + 1, -(e / g), p / g, j + 1);
}

static gmp_normal_form *
sn_fast_smith(gmp_matrix *A, inverted_flag linv, inverted_flag rinv)
{
  size_t m = A->rows, n = A->cols, ndiag = (m < n) ? m : n, t, idx;
  size_t mb = 0;
  sn_ctx x;
  gmp_normal_form *nf;

  for(idx = 0; idx < m * n; idx++) {
    size_t b = (mpz_sgn(A->storage[idx]) == 0) ? 0 : mpz_sizeinbase(A->storage[idx], 2);
    if(b > mb) mb = b;
    if(!mpz_fits_slong_p(A->storage[idx]) || mb > 31) return NULL;
  }

  x.C = (int64_t *)malloc(m * n * sizeof(int64_t));
  x.L = (int64_t *)calloc(m * m, sizeof(int64_t));
  x.R = (int64_t *)calloc(n * n, sizeof(int64_t));
  if(x.C == NULL || x.L == NULL || x.R == NULL) { free(x.C); free(x.L); free(x.R); return NULL; }
  x.m = m; x.n = n; x.linv = linv; x.rinv = rinv; x.of = 0;
  for(idx = 0; idx < m * n; idx++) x.C[idx] = (int64_t)mpz_get_si(A->storage[idx]);
  for(idx = 0; idx < m; idx++) HE(x.L, m, idx, idx) = 1;
  for(idx = 0; idx < n; idx++) HE(x.R, n, idx, idx) = 1;

  for(t = 0; t < ndiag && !x.of; t++) {
    size_t pi = t, pj = t, i, j;
    int have = 0, unit = 0;
    int64_t best = 0;
    /* Smallest-magnitude pivot.  A nonzero integer has magnitude >= 1, so the
       first entry of magnitude 1 in scan order is already the smallest-
       magnitude choice: stop there (this is the usual case -- the matrices are
       totally unimodular -- and avoids an O(n^2) scan per pivot). */
    for(j = t; j < n && !unit; j++)
      for(i = t; i < m; i++) {
        int64_t v = HE(x.C, m, i, j);
        if(v == 0) continue;
        int64_t av = v < 0 ? -v : v;
        if(!have || av < best) { best = av; pi = i; pj = j; have = 1;
          if(av == 1) { unit = 1; break; } }
      }
    if(!have) break;
    if(pi != t) sn_row_swap(&x, t + 1, pi + 1);
    if(pj != t) sn_col_swap(&x, t + 1, pj + 1);

    for(;;) {
      int dirty = 0, found = 0;
      if(x.of) break;
      for(i = t + 1; i < m; i++)
        if(HE(x.C, m, i, t) != 0) sn_clear_below(&x, t, i);
      for(j = t + 1; j < n; j++)
        if(HE(x.C, m, t, j) != 0) sn_clear_right(&x, t, j);
      if(x.of) break;
      for(i = t + 1; i < m; i++)
        if(HE(x.C, m, i, t) != 0) { dirty = 1; break; }
      if(!dirty)
        for(j = t + 1; j < n; j++)
          if(HE(x.C, m, t, j) != 0) { dirty = 1; break; }
      if(dirty) continue;
      {
        int64_t p = HE(x.C, m, t, t);
        /* A unit pivot divides everything, so the trailing block is trivially
           divisible -- skip the O(n^2) scan (again the usual case). */
        if(p != 1 && p != -1)
          for(j = t + 1; j < n && !found; j++)
            for(i = t + 1; i < m && !found; i++) {
              int64_t v = HE(x.C, m, i, j);
              if(v != 0 && v % p != 0) {
                sn_row_addmul(&x, 1, i + 1, t + 1);   /* row_t += row_i */
                found = 1;
              }
            }
      }
      if(found) continue;
      break;
    }
    if(!x.of && HE(x.C, m, t, t) < 0) sn_col_neg(&x, t + 1);
  }

  if(x.of) { free(x.C); free(x.L); free(x.R); return NULL; }

  /* Build the factors first; on any failure leave A untouched for the mpz
     fallback.  On success repurpose A as the canonical (the mpz path does the
     same, and ChainComplex reads the input pointer after the call). */
  {
    gmp_matrix *newL = he_to_gmp(x.L, m, m);
    gmp_matrix *newR = he_to_gmp(x.R, n, n);
    nf = (gmp_normal_form *)malloc(sizeof(gmp_normal_form));
    if(newL == NULL || newR == NULL || nf == NULL) {
      destroy_gmp_matrix(newL); destroy_gmp_matrix(newR); free(nf);
      free(x.C); free(x.L); free(x.R);
      return NULL;
    }
    he_store_i64(A, x.C);        /* repurpose A as the canonical */
    nf->canonical = A;
    nf->left = newL;
    nf->right = newR;
    nf->left_inverted = linv;
    nf->right_inverted = rinv;
  }
  free(x.C); free(x.L); free(x.R);
  return nf;
}

gmp_normal_form *
create_gmp_Smith_normal_form(gmp_matrix * A,
                             inverted_flag left_inverted,
                             inverted_flag right_inverted)
{
  gmp_normal_form *nf;
  gmp_matrix *C;
  size_t rows, cols, ndiag, t;
  mpz_t g, bez1, bez2, c2, d2, e, p, q, r;

  if(A == NULL) return NULL;

  /* Fast native-integer path (returns NULL, A intact, on overflow / big
     entries so the exact mpz diagonalisation below runs instead). */
  nf = sn_fast_smith(A, left_inverted, right_inverted);
  if(nf != NULL) return nf;

  nf = create_gmp_trivial_normal_form(A, left_inverted, right_inverted);
  if(nf == NULL) return NULL;   /* A already destroyed */

  C = nf->canonical;
  rows = C->rows;
  cols = C->cols;
  ndiag = (rows < cols) ? rows : cols;

  mpz_init(g); mpz_init(bez1); mpz_init(bez2);
  mpz_init(c2); mpz_init(d2);
  mpz_init(e); mpz_init(p); mpz_init(q); mpz_init(r);

  for(t = 0; t < ndiag; t++)
    {
      size_t pi = t, pj = t, i, j;
      int have_pivot = 0;

      /* Pick the smallest-magnitude nonzero in the trailing block as the
         initial pivot.  This tends to surface unit (+-1) pivots first, which
         then clear their row and column in a single pass with no growth. */
      for(j = t; j < cols; j++)
        for(i = t; i < rows; i++)
          if(mpz_sgn(GNF_ENT(C, i, j)) != 0)
            if(!have_pivot ||
               mpz_cmpabs(GNF_ENT(C, i, j), GNF_ENT(C, pi, pj)) < 0)
              { pi = i; pj = j; have_pivot = 1; }

      if(!have_pivot) break;   /* trailing block is all zero: we are done */

      if(pi != t) gnf_row_swap(nf, t + 1, pi + 1);
      if(pj != t) gnf_col_swap(nf, t + 1, pj + 1);

      for(;;)
        {
          int dirty = 0, found = 0;

          for(i = t + 1; i < rows; i++)
            if(mpz_sgn(GNF_ENT(C, i, t)) != 0)
              gnf_clear_below(nf, t, i, g, bez1, bez2, c2, d2, p, e);

          for(j = t + 1; j < cols; j++)
            if(mpz_sgn(GNF_ENT(C, t, j)) != 0)
              gnf_clear_right(nf, t, j, g, bez1, bez2, c2, d2, p, e);

          /* Clearing the row may have re-dirtied column t, and vice versa. */
          for(i = t + 1; i < rows; i++)
            if(mpz_sgn(GNF_ENT(C, i, t)) != 0) { dirty = 1; break; }
          if(!dirty)
            for(j = t + 1; j < cols; j++)
              if(mpz_sgn(GNF_ENT(C, t, j)) != 0) { dirty = 1; break; }
          if(dirty) continue;

          /* The pivot must divide every entry of the trailing block.  If not,
             fold an offending row into the pivot row and reduce again; the
             pivot's gcd then strictly shrinks, so this terminates. */
          mpz_set(p, GNF_ENT(C, t, t));
          for(j = t + 1; j < cols && !found; j++)
            for(i = t + 1; i < rows && !found; i++)
              {
                if(mpz_sgn(GNF_ENT(C, i, j)) == 0) continue;
                mpz_tdiv_r(r, GNF_ENT(C, i, j), p);
                if(mpz_sgn(r) != 0)
                  {
                    mpz_set_si(q, 1);
                    gnf_row_addmul(nf, q, i + 1, t + 1);  /* row_t += row_i */
                    found = 1;
                  }
              }
          if(found) continue;

          break;
        }

      if(mpz_sgn(GNF_ENT(C, t, t)) < 0) gnf_col_neg(nf, t + 1);
    }

  mpz_clear(g); mpz_clear(bez1); mpz_clear(bez2);
  mpz_clear(c2); mpz_clear(d2);
  mpz_clear(e); mpz_clear(p); mpz_clear(q); mpz_clear(r);
  return nf;
}

int destroy_gmp_normal_form(gmp_normal_form * nf)
{
  int status;

  if(nf == NULL)
    {
      return EXIT_FAILURE;
    }

  status = EXIT_SUCCESS;
  if(destroy_gmp_matrix(nf -> left) == EXIT_FAILURE)
    {
      status = EXIT_FAILURE;
    }

  if(destroy_gmp_matrix(nf -> canonical) == EXIT_FAILURE)
    {
      status = EXIT_FAILURE;
    }

  if(destroy_gmp_matrix(nf -> right) == EXIT_FAILURE)
    {
      status = EXIT_FAILURE;
    }
  free(nf);

  return status;
}


