/* 
   Source file for integer-oriented matrix, relying on the arbitrary 
   precision integers from the GNU gmp package. 

   Copyright (C) 28.10.2003 Saku Suuriniemi TUT/CEM

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

   $Id: gmp_matrix.c,v 1.1 2009-03-30 14:10:57 matti Exp $
*/


#include<stdlib.h>
#include"gmp_matrix.h"

gmp_matrix * 
create_gmp_matrix(size_t r, size_t c, 
		  const mpz_t * e)
{
  gmp_matrix * new_matrix;
  size_t       ind;

  new_matrix = (gmp_matrix * ) malloc(sizeof(gmp_matrix));
  if(new_matrix == NULL)
    {
      return NULL;
    }

  new_matrix -> storage = (mpz_t *) calloc(r*c, sizeof(mpz_t));
  if(new_matrix -> storage == NULL)
    {
      free(new_matrix);
      return NULL;
    }

  new_matrix -> rows = r;
  new_matrix -> cols = c;

  for(ind = 0; ind < r*c; ind ++)
    {
      mpz_init (new_matrix -> storage[ind]);
      mpz_set  (new_matrix -> storage[ind], e[ind]);
    }

  return new_matrix;
}


gmp_matrix * 
create_gmp_matrix_identity(size_t dim)
{
  gmp_matrix * new_matrix;
  size_t       ind;

  new_matrix = (gmp_matrix * ) malloc(sizeof(gmp_matrix));
  if(new_matrix == NULL)
    {
      return NULL;
    }

  new_matrix -> storage = (mpz_t *) calloc(dim*dim, sizeof(mpz_t));
  if(new_matrix -> storage == NULL)
    {
      free(new_matrix);
      return NULL;
    }

  new_matrix -> rows = dim;
  new_matrix -> cols = dim;

  for(ind = 0; ind < dim*dim; ind ++)
    {
      mpz_init_set_si (new_matrix -> storage[ind], 0);
    }

  for(ind = 0; ind < dim; ind ++)
    {
      mpz_set_ui(new_matrix -> storage[ind*(dim+1)], 1);
    }

  return new_matrix;
}


gmp_matrix * 
create_gmp_matrix_zero(size_t rows, size_t cols)
{
  gmp_matrix * new_matrix;
  size_t       ind;

  new_matrix = (gmp_matrix * ) malloc(sizeof(gmp_matrix));
  if(new_matrix == NULL)
    {
      return NULL;
    }

  new_matrix -> storage = (mpz_t *) calloc(rows*cols, sizeof(mpz_t));
  if(new_matrix -> storage == NULL)
    {
      free(new_matrix);
      return NULL;
    }

  new_matrix -> rows = rows;
  new_matrix -> cols = cols;

  for(ind = 0; ind < rows*cols; ind ++)
    {
      mpz_init_set_si (new_matrix -> storage[ind], 0);
    }

  return new_matrix;
}

int 
destroy_gmp_matrix(gmp_matrix * m)
{
  size_t       ind, nmb_storage;;

  if(m == NULL)
    {
      return EXIT_FAILURE;
    }

  if(m -> storage == NULL)
    {
      free(m);
      return EXIT_FAILURE;
    }

  nmb_storage = (m -> rows)*(m -> cols);

  for(ind = 0; ind < nmb_storage; ind++)
    {
      mpz_clear(m -> storage[ind]);
    }

  free(m -> storage);
  free(m);
  return EXIT_SUCCESS;
}


size_t
gmp_matrix_rows(const gmp_matrix * m)
{
  if(m == NULL)
    {
      return 0;
    }

  return m -> rows;
}


size_t
gmp_matrix_cols(const gmp_matrix * m)
{
  if(m == NULL)
    {
      return 0;
    }

  return m -> cols;
}

/* elem <- (matrix(row, col)) */
int
gmp_matrix_get_elem(mpz_t elem, size_t row, size_t col,
		    const gmp_matrix * m)
{
#ifdef DEBUG

  if(m == NULL)
    {
      return EXIT_FAILURE;
    }

#endif

  mpz_set(elem, m -> storage[(col-1)*(m -> rows)+row-1]);
  return EXIT_SUCCESS;
}

int  
gmp_matrix_swap_rows(size_t row1, size_t row2, gmp_matrix * m)
{
  if(m == NULL)
    {
      return EXIT_FAILURE;
    }
  if((row1 < 1) || (row1 > m->rows) || (row2 < 1) || (row2 > m->rows))
    {
      return EXIT_FAILURE;
    }

  /* printf("Swapping rows %i %i\n", row1, row2); */
  gmp_blas_swap(m -> cols,
		&(m -> storage[row1-1]), m -> rows, 
		&(m -> storage[row2-1]), m -> rows);

  return EXIT_SUCCESS;
}

int
gmp_matrix_swap_cols(size_t col1, size_t col2, gmp_matrix * m)
{
  if(m == NULL)
    {
      return EXIT_FAILURE;
    }
  if((col1 < 1) || (col1 > m->cols) || (col2 < 1) || (col2 > m->cols))
    {
      return EXIT_FAILURE;
    }

  /* printf("Swapping cols %i %i\n", col1, col2); */
  gmp_blas_swap(m -> rows, 
		&(m -> storage[(m->rows)*(col1-1)]), 1, 
		&(m -> storage[(m->rows)*(col2-1)]), 1);

  return EXIT_SUCCESS;
}

int
gmp_matrix_negate_row(size_t row, gmp_matrix * m)
{
  mpz_t minus_one;

  if(m == NULL)
    {
      return EXIT_FAILURE;
    }
  if((row < 1) || (row > m->rows))
    {
      return EXIT_FAILURE;
    }

  mpz_init(minus_one);
  mpz_set_si(minus_one, -1);
  gmp_blas_scal(m -> cols, minus_one, (&m -> storage[row-1]), m -> rows); 
  mpz_clear(minus_one);
  return EXIT_SUCCESS; 
}

int
gmp_matrix_negate_col(size_t col, gmp_matrix * m)
{
  mpz_t minus_one;
  if(m == NULL)
    {
      return EXIT_FAILURE;
    }
  if((col < 1) || (col > m->cols))
    {
      return EXIT_FAILURE;
    }

  mpz_init(minus_one);
  mpz_set_si(minus_one, -1);
  gmp_blas_scal(m -> rows, minus_one, 
		&(m -> storage[(m->rows)*(col-1)]), 1); 
  mpz_clear(minus_one);
  return EXIT_SUCCESS;
}

/* row2 <- a*row1 + row2*/
int
gmp_matrix_add_row(mpz_t a, size_t row1, size_t row2,
		   gmp_matrix * m)
{
  if(m == NULL)
    {
      return EXIT_FAILURE;
    }
  if((row1 < 1) || (row1 > m->rows) || (row2 < 1) || (row2 > m->rows))
    {
      return EXIT_FAILURE;
    }

  gmp_blas_axpy(m->cols, a, 
		(const mpz_t *) &(m->storage[row1-1]), m->rows, 
		&(m->storage[row2-1]), m->rows); 

  return EXIT_SUCCESS;
}

int
gmp_matrix_add_col(mpz_t a, size_t col1, size_t col2,
		   gmp_matrix * m)
{
  if(m == NULL)
    {
      return EXIT_FAILURE;
    }
  if((col1 < 1) || (col1 > m->cols) || (col2 < 1) || (col2 > m->cols))
    {
      return EXIT_FAILURE;
    }

  gmp_blas_axpy(m->rows, a, 
		(const mpz_t *) &(m -> storage[(m->rows)*(col1-1)]), 1, 
		&(m -> storage[(m->rows)*(col2-1)]), 1); 

  return EXIT_SUCCESS;
}

/* row1 <- a*row1 + b*row2
   row2 <- c*row1 + d*row2 */
int
gmp_matrix_row_rot(mpz_t a, mpz_t b, size_t row1,
		   mpz_t c, mpz_t d, size_t row2,
		   gmp_matrix * m)
{
  if(m == NULL)
    {
      return EXIT_FAILURE;
    }
  if((row1 < 1) || (row1 > m->rows) || (row2 < 1) || (row2 > m->rows))
    {
      return EXIT_FAILURE;
    }

  gmp_blas_rot(m->cols, 
	       a, b, &(m->storage[row1-1]), m->rows, 
	       c, d, &(m->storage[row2-1]), m->rows); 

  return EXIT_SUCCESS;
}
int
gmp_matrix_col_rot(mpz_t a, mpz_t b, size_t col1,
		   mpz_t c, mpz_t d, size_t col2,
		   gmp_matrix * m)
{
  if(m == NULL)
    {
      return EXIT_FAILURE;
    }
  if((col1 < 1) || (col1 > m->cols) || (col2 < 1) || (col2 > m->cols))
    {
      return EXIT_FAILURE;
    }

/*   printf("a: %i b: %i c: %i d:%i col1: %i col2: %i\n", */
/* 	 mpz_get_si(a), */
/* 	 mpz_get_si(b), */
/* 	 mpz_get_si(c), */
/* 	 mpz_get_si(d), */
/* 	 col1, col2); */

  gmp_blas_rot(m->rows, 
	       a, b, &(m -> storage[(m->rows)*(col1-1)]), 1, 
	       c, d, &(m -> storage[(m->rows)*(col2-1)]), 1); 

  return EXIT_SUCCESS;
}

size_t
gmp_matrix_col_inz (size_t r1, size_t r2, size_t c, 
		    gmp_matrix * m)
{
  size_t result;

  if(m == NULL)
    {
      return 0;
    }
  if((r1 < 1) || (r1 > m->rows) || 
     (r2 < 1) || (r2 > m->rows) ||
     (r2 < r1) || (c < 1) || (c > m->cols))
    {
      return 0;
    }

  result = gmp_blas_inz(r2-r1+1, 
			(const mpz_t *) &(m->storage[(c-1)*(m->rows)+r1-1]), 
			1);

  if(result > r2-r1+1)
    {
      return 0;
    }

  return result;
}

size_t
gmp_matrix_row_inz (size_t r, size_t c1, size_t c2, 
		    gmp_matrix * m)
{
  size_t result;

  if(m == NULL)
    {
      return 0;
    }
  if((r  < 1) || (r  > m->rows) || 
     (c1 < 1) || (c1 > m->cols) ||
     (c2 < c1) || (c2 < 1) || (c2 > m->cols))
    {
      return 0;
    }

  result = gmp_blas_inz(c2-c1+1, 
			(const mpz_t *) &(m->storage[(c1-1)*(m->rows)+r-1]), 
			m->rows);

  if(result > c2-c1+1)
    {
      return 0;
    }

  return result;
}


int
gmp_matrix_is_diagonal(const gmp_matrix * M)
{
  size_t i,j;
  size_t rows, cols;

  if(M == NULL)
    {
      return 0;
    }
  
  rows = M->rows;
  cols = M->cols;

  for(j = 1; j <= cols; j ++)
    {
      for(i = 1; i <= rows; i ++)
	{
	  if((mpz_cmp_si(M->storage[(i-1)+(j-1)*rows], 0) != 0) && 
	     (i != j))
	    {
	      return 0;
	    }
	}
    }

  return 1;
}


int
gmp_matrix_transp(gmp_matrix * M)
{
  mpz_t * new_storage;
  size_t i,j;
  size_t rows, cols;

  if(M == NULL)
    {
      return EXIT_FAILURE;
    }
  
  rows = M->rows;
  cols = M->cols;

  new_storage = (mpz_t *) calloc(rows*cols, sizeof(mpz_t));
  if(new_storage == NULL)
    {
      return EXIT_FAILURE;
    }

  for(i = 1; i <= rows; i++)
    {
      for(j = 1; j <= cols; j++)
	{
	  mpz_init_set(new_storage[(j-1)+(i-1)*cols], 
		       M-> storage[(i-1)+(j-1)*rows]);
	  mpz_clear(M-> storage[(i-1)+(j-1)*rows]);
	}
    }
  free(M->storage);

  M -> storage = new_storage;
  M -> rows = cols;
  M -> cols = rows;

  return EXIT_SUCCESS;
}


int
gmp_matrix_right_mult(gmp_matrix * A, const gmp_matrix * B)
{
  mpz_t * new_storage;
  size_t i,j;
  size_t rows_A, cols_A, rows_B, cols_B;

  if((A == NULL) || (B == NULL))
    {
      return EXIT_FAILURE;
    }
  
  rows_A = A->rows;
  cols_A = A->cols;
  rows_B = B->rows;
  cols_B = B->cols;

  if(cols_A != rows_B)
    {
      return EXIT_FAILURE;
    }

  /* Create new storage for the product */
  new_storage = (mpz_t *) calloc(rows_A*cols_B, sizeof(mpz_t));
  if(new_storage == NULL)
    {
      return EXIT_FAILURE;
    }

  /* Compute the product to the storage */
  for(j = 1; j <= cols_B; j++)
    {
      for(i = 1; i <= rows_A; i++)
	{
	  mpz_init (new_storage[(i-1)+(j-1)*rows_A]);
	  gmp_blas_dot(&(new_storage[(i-1)+(j-1)*rows_A]),
		       cols_A,
		       (const mpz_t *) &(A->storage[i-1]),          rows_A,
		       (const mpz_t *) &(B->storage[(j-1)*rows_B]), 1);
	}
    }

  /* Get rid of the old storage */
  for(i = 1; i <= rows_A*cols_A; i++)
    {
      mpz_clear (A->storage[i-1]);
    }
  free(A->storage);

  /* Update A */
  A -> storage = new_storage;
  A -> cols    = cols_B;

  return EXIT_SUCCESS;
}

int
gmp_matrix_left_mult(const gmp_matrix * A, gmp_matrix * B)
{
  mpz_t * new_storage;
  size_t i,j;
  size_t rows_A, cols_A, rows_B, cols_B;

  if((A == NULL) || (B == NULL))
    {
      return EXIT_FAILURE;
    }
  
  rows_A = A->rows;
  cols_A = A->cols;
  rows_B = B->rows;
  cols_B = B->cols;

  if(cols_A != rows_B)
    {
      return EXIT_FAILURE;
    }

  /* Create new storage for the product */
  new_storage = (mpz_t *) calloc(rows_A*cols_B, sizeof(mpz_t));
  if(new_storage == NULL)
    {
      return EXIT_FAILURE;
    }

  /* Compute the product to the storage */
  for(j = 1; j <= cols_B; j++)
    {
      for(i = 1; i <= rows_A; i++)
	{
	  mpz_init (new_storage[(i-1)+(j-1)*rows_A]);
	  gmp_blas_dot(&(new_storage[(i-1)+(j-1)*rows_A]),
		       cols_A,
		       (const mpz_t *) &(A->storage[i-1]),          rows_A,
		       (const mpz_t *) &(B->storage[(j-1)*rows_B]), 1);
	}
    }

  /* Get rid of the old storage */
  for(i = 1; i <= rows_B*cols_B; i++)
    {
      mpz_clear (B->storage[i-1]);
    }
  free(B->storage);

  /* Update A */
  B -> storage = new_storage;
  B -> rows    = rows_A;

  return EXIT_SUCCESS;
}


int gmp_matrix_printf(const gmp_matrix * m)
{

  mpz_t        outz;
  size_t rows, cols, i, j;

  if(m == NULL)
    {
      return EXIT_FAILURE;
    }

  rows = m->rows;
  cols = m->cols;
  mpz_init(outz);
  for(i = 1; i <= rows ; i++)
    {
      for(j = 1; j <= cols ; j++)
	{
	  gmp_matrix_get_elem(outz, i, j, m);
	  mpz_out_str (stdout, 10, outz);
	  printf(" ");
	}
      printf("\n");
    }

  mpz_clear(outz);

  return EXIT_SUCCESS;
}

int gmp_matrix_fprintf(FILE* stream, const gmp_matrix * m)
{
  mpz_t        outz;
  size_t rows, cols, i, j;

  if(m == NULL)
    {
      return EXIT_FAILURE;
    }

  rows = m->rows;
  cols = m->cols;
  mpz_init(outz);
  for(i = 1; i <= rows ; i++)
    {
      for(j = 1; j <= cols ; j++)
	{
	  gmp_matrix_get_elem(outz, i, j, m);
	  mpz_out_str (stream, 10, outz);
	  printf(" ");
	}
      printf("\n");
    }

  mpz_clear(outz);

  return EXIT_SUCCESS;
}
