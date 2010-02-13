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
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

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


gmp_normal_form *
create_gmp_Smith_normal_form(gmp_matrix * A,
			     inverted_flag left_inverted,
			     inverted_flag right_inverted)
{

  gmp_normal_form * new_nf;
  gmp_matrix * canonical;
  gmp_matrix * elbow;
  inverted_flag elbow_flag;
  size_t rows, cols;
  size_t i, j;
  size_t subd_ind, row_undivisible;
  size_t last_ready_row, first_ready_col, ind;
  mpz_t  pivot;
  mpz_t  remainder;

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

  canonical = new_nf -> canonical;
  mpz_init(pivot);
  mpz_init(remainder);
  rows = canonical->rows;
  cols = canonical->cols;
  last_ready_row  = 0;
  first_ready_col = (cols < rows) ? (cols+1) : (rows+1);

  while(first_ready_col > last_ready_row + 1)
    {
      /*******/
      /* HNF */
      /*******/

      if(gmp_normal_form_make_Hermite(new_nf) != EXIT_SUCCESS)
	{
	  destroy_gmp_normal_form(new_nf);
	  mpz_clear(pivot);
	  mpz_clear(remainder);
	  return NULL;
	}

#ifdef DEBUG
      printf("HNF\n");
      gmp_matrix_printf (new_nf -> left);
      gmp_matrix_printf (new_nf -> canonical);
      gmp_matrix_printf (new_nf -> right);
#endif

      /**********************/
      /* Find ready columns */
      /**********************/

      /* If a diagonal entry is zero, so is the corresponding 
	 column. The zero diagonals always reside in the end. 
	 Seek until zero diagonal encountered, but stay within the matrix! */
      ind = 1;
      while ( (ind < first_ready_col) && 
	      (mpz_cmp_si(canonical -> storage[(ind-1)+(ind-1)*rows], 0) != 0) 
	      )	     
	{
	  ind ++;
	}
      first_ready_col = ind;

      /* Note: The number of ready cols is settled after the first HNF, 
	 but the check is cheap. */

      /**********************************************/
      /* Permute unit diagonals such that they lead */
      /**********************************************/

      /* If the recently computed HNF has ones on the diagonal, their 
	 corresponding rows are all zero (except the diagonal). 
	 They are then settled, because the next LHNF kills the elements
	 on their columns. */

      ind = last_ready_row+1;
  
      /* Stay within the nonzero cols of the matrix */
      while (ind < first_ready_col)
	{
	  /* Unit diagonal encountered */
	  if(mpz_cmp_si ( canonical->storage[(ind-1) + (ind-1)*rows], 
			  1) == 0)
	    {
	      /* If not in the beginning, permute to extend the leading minor 
		 with unit diagonals */
	      if(ind != last_ready_row+1)
		{
		  gmp_matrix_swap_rows(last_ready_row+1,     ind, 
				       new_nf -> canonical);
		  
		  if(left_inverted == INVERTED)
		    {
		      gmp_matrix_swap_rows(last_ready_row+1, ind, 
					   new_nf -> left);
		    }
		  else
		    {
		      gmp_matrix_swap_cols(last_ready_row+1, ind, 
					   new_nf -> left);
		    }
		  
		  gmp_matrix_swap_cols(last_ready_row+1,     ind, 
				       new_nf -> canonical);
		  
		  if(right_inverted == INVERTED)
		    {
		      gmp_matrix_swap_cols(last_ready_row+1, ind, 
					   new_nf -> right);
		    }
		  else
		    {
		      gmp_matrix_swap_rows(last_ready_row+1, ind, 
					   new_nf -> right);
		    }
		}
	      last_ready_row ++;
	    }
	  ind++;
	}
      
#ifdef DEBUG
      printf("Leading units\n");
      gmp_matrix_printf (new_nf -> left);
      gmp_matrix_printf (new_nf -> canonical);
      gmp_matrix_printf (new_nf -> right);
#endif

      /********/
      /* LHNF */
      /********/

      /* Extravagant strategy: Compute HNF of an explicit tranpose. */

      /* 1. Transpose everything in the normal form */
      if(gmp_matrix_transp(canonical) != EXIT_SUCCESS)
	{
	  destroy_gmp_normal_form(new_nf);
	  mpz_clear(pivot);
	  mpz_clear(remainder);
	  return NULL;
	}
      if(gmp_matrix_transp(new_nf->left) != EXIT_SUCCESS)
	{
	  destroy_gmp_normal_form(new_nf);
	  mpz_clear(pivot);
	  mpz_clear(remainder);
	  return NULL;
	}
      if(gmp_matrix_transp(new_nf->right) != EXIT_SUCCESS)
	{
	  destroy_gmp_normal_form(new_nf);
	  mpz_clear(pivot);
	  mpz_clear(remainder);
	  return NULL;
	}

      elbow          = new_nf ->left;
      new_nf ->left  = new_nf ->right;
      new_nf ->right = elbow;
      elbow_flag              = new_nf ->left_inverted;
      new_nf ->left_inverted  = new_nf ->right_inverted;
      new_nf ->right_inverted = elbow_flag;

      /* 2. Compute HNF of the transpose */
      if(gmp_normal_form_make_Hermite(new_nf) != EXIT_SUCCESS)
	{
	  destroy_gmp_normal_form(new_nf);
	  mpz_clear(pivot);
	  mpz_clear(remainder);
	  return NULL;
	}

      /* 3. Transpose everything back */
      if(gmp_matrix_transp(canonical) != EXIT_SUCCESS)
	{
	  destroy_gmp_normal_form(new_nf);
	  mpz_clear(pivot);
	  mpz_clear(remainder);
	  return NULL;
	}
      if(gmp_matrix_transp(new_nf->left) != EXIT_SUCCESS)
	{
	  destroy_gmp_normal_form(new_nf);
	  mpz_clear(pivot);
	  mpz_clear(remainder);
	  return NULL;
	}
      if(gmp_matrix_transp(new_nf->right) != EXIT_SUCCESS)
	{
	  destroy_gmp_normal_form(new_nf);
	  mpz_clear(pivot);
	  mpz_clear(remainder);
	  return NULL;
	}
      elbow          = new_nf ->left;
      new_nf ->left  = new_nf ->right;
      new_nf ->right = elbow;
      elbow_flag              = new_nf ->left_inverted;
      new_nf ->left_inverted  = new_nf ->right_inverted;
      new_nf ->right_inverted = elbow_flag;


#ifdef DEBUG
      printf("LHNF\n");
      gmp_matrix_printf (new_nf -> left);
      gmp_matrix_printf (new_nf -> canonical);
      gmp_matrix_printf (new_nf -> right);
#endif


      /*****************************************************/
      /* Check if more of the leading normal form is ready */
      /*****************************************************/

      /* The matrix is in LHNF, i.e. it is upper triangular. 
	 If the row trailing the top left diagonal element is 
	 zero, the diagonal element may be an invariant factor 
	 on its final position, and the stage may be ready.

	 The stage may not still be ready: The leading diagonal element 
	 of D may not divide the rest of the Schur complement. */

      subd_ind = 0;
      row_undivisible = 0;

      /* Explanation of loop conditions:
	 1.) No relative primes found from Schur complement
	 2.) Stay within the Schur complement
	 3.) If a nonzero is found from the trailing row, the stage is 
	     definitely not ready */
      while (row_undivisible == 0 &&   
	     last_ready_row + 1 < first_ready_col && 
	     subd_ind == 0)        
	{
	  subd_ind = 
	    gmp_matrix_row_inz(last_ready_row+1,
			       last_ready_row+2, cols, 
			       canonical);

	  /* printf("subd_ind %i\n", subd_ind);
	     printf("last_ready_row %i\n", last_ready_row); */
      
	  /* No nonzeros found, the stage may be ready */
	  if (subd_ind == 0)
	    {
	      mpz_set (pivot, 
		       canonical->storage[(last_ready_row)+
					  (last_ready_row)*rows]);

	      /* Check whether the pivot divides all elements in the Schur 
		 complement */
	      row_undivisible = 0;
	      for(j = last_ready_row+2; j < first_ready_col; j++)
		{
		  for(i = last_ready_row+2; i <= j; i++)
		    {
		      mpz_tdiv_r (remainder, 
				  canonical->storage[(i-1)+
						     (j-1)*rows], 
				  pivot);
		  
		      if(mpz_cmp_si(remainder, 0) !=0)
			{
			  row_undivisible = i;
			  /* col_undivisible = j; */
			}
		    }
		}

	      /* printf("Row undivisible %i\n", row_undivisible); */

	      /* If a relative prime was found from the Schur complement,  
		 add that row to the first row of the Schur complement */
	      if(row_undivisible != 0)
		{
		  mpz_set_si (remainder, 1);
		  gmp_matrix_add_row(remainder, 
				     row_undivisible, last_ready_row+1, 
				     canonical);

		  /* [ 1 0] [1 0] = [1 0]
		     [-1 1] [1 1]   [0 1] */

		  if(left_inverted == INVERTED)
		    {
		      gmp_matrix_add_row(remainder, 
					 row_undivisible, last_ready_row+1, 
					 new_nf->left);
		    }
		  else
		    {
		      mpz_neg (remainder, remainder);
		      gmp_matrix_add_col(remainder, 
					 last_ready_row+1, row_undivisible,
					 new_nf->left);
		    }
		}
	      /* The Schur complement is smaller by one again */
	      else
		{
		  last_ready_row++;
		}
	    }
	} 
    }  /* The main loop ends here */
  
  mpz_clear(pivot);
  mpz_clear(remainder);
  return new_nf;
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


