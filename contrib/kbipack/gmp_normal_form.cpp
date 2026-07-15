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


