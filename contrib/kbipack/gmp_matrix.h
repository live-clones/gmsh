/* 
   Header file for integer-oriented matrix, relying on the arbitrary 
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

   $Id: gmp_matrix.h,v 1.3 2009-04-14 10:02:22 matti Exp $
*/

#ifndef __GMP_MATRIX_H__
#define __GMP_MATRIX_H__

#include "gmp_blas.h"

typedef struct
{
  size_t  rows;
  size_t  cols;
  mpz_t * storage;
} gmp_matrix;

/* Sets the values of "elems" column by column. The user is 
   responsible for sufficient supply. */
gmp_matrix * 
create_gmp_matrix(size_t rows, size_t cols, 
		  mpz_t * elems);
gmp_matrix * 
create_gmp_matrix_int(size_t rows, size_t cols, 
		  const long int * elems);

gmp_matrix * 
create_gmp_matrix_identity(size_t dim);

gmp_matrix * 
create_gmp_matrix_zero(size_t rows, size_t cols);

/* Copies a block of a matrix to another matrix. No resizing (yet). */
gmp_matrix * 
copy_gmp_matrix(const gmp_matrix * matrix, 
		  const size_t start_row, const size_t start_col, 
		  const size_t end_row, const size_t end_col);

int 
destroy_gmp_matrix(gmp_matrix *);

size_t
gmp_matrix_rows(const gmp_matrix *);

size_t
gmp_matrix_cols(const gmp_matrix *);

/* elem <- (matrix(row, col)) */
int
gmp_matrix_get_elem(mpz_t elem, size_t row, size_t col,
		    const gmp_matrix *);

/* (matrix(row, col)) <- elem */
int
gmp_matrix_set_elem(mpz_t elem, size_t row, size_t col,
		    const gmp_matrix *);		    

int
gmp_matrix_swap_rows(size_t row1, size_t row2, gmp_matrix *);

int
gmp_matrix_swap_cols(size_t col1, size_t col2, gmp_matrix *);

int  
gmp_matrix_negate_row(size_t row, gmp_matrix *);

int 
gmp_matrix_negate_col(size_t col, gmp_matrix *); 

/* row2 <- a*row1 + row2*/
int
gmp_matrix_add_row(mpz_t a, size_t row1, size_t row2,
		   gmp_matrix *);
int
gmp_matrix_add_col(mpz_t a, size_t col1, size_t col2,
		   gmp_matrix *);

/* row1 <- a*row1 + b*row2
   row2 <- c*row1 + d*row2 */
int
gmp_matrix_row_rot(mpz_t a, mpz_t b, size_t row1,
		   mpz_t c, mpz_t d, size_t row2,
		   gmp_matrix *);
int
gmp_matrix_col_rot(mpz_t a, mpz_t b, size_t col1,
		   mpz_t c, mpz_t d, size_t col2,
		   gmp_matrix *);

/* 0 for no, 1 for yes */
int
gmp_matrix_is_diagonal(const gmp_matrix * M);

/* Finds a nonzero in a subcolumn M(r1:r2,c). */
/* Returns zero if no nonzeros found. */
size_t
gmp_matrix_col_inz (size_t r1, size_t r2, size_t c, 
		    gmp_matrix * M);

/* Finds a nonzero in a subrow M(r,c1:c2). */
/* Returns zero if no nonzeros found. */
size_t
gmp_matrix_row_inz (size_t r, size_t c1, size_t c2, 
		    gmp_matrix * M);

int
gmp_matrix_transp(gmp_matrix * M);

/* A <- A+B */
int
gmp_matrix_sum(gmp_matrix * A, const gmp_matrix * B);

/* A <- A*B */
int
gmp_matrix_right_mult(gmp_matrix * A, const gmp_matrix * B);

/* B <- A*B */
int
gmp_matrix_left_mult(const gmp_matrix * A, gmp_matrix * B);

/* (TBD ?)Implement the BLAS style GEMM? Place it here at all? */
/*         (T)   (T) */
/*   A <- B   * C    */
/* Give 1 if the transpose of the matrix is to be used, else 0 */
/* int */
/* gmp_matrix_mult(gmp_matrix * A,  */
/* 		const gmp_matrix * B, int transpose_B,  */
/* 		const gmp_matrix * C, int transpose_C);  */

/* 
   Mainly for diagnostics ...        
   --------------------------
*/

int gmp_matrix_printf(const gmp_matrix *);
int gmp_matrix_fprintf(FILE*, const gmp_matrix *);


#endif
