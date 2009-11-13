/* 
   Header file for integer-oriented elementary versions of some 
   subroutines of BLAS. There routines are chosen to facilitate the 
   computation of Hermite and Smith normal forms of matrices of 
   modest size. 

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

   $Id: gmp_blas.h,v 1.1 2009-03-30 14:10:57 matti Exp $
*/

#ifndef __GMP_BLAS_H__
#define __GMP_BLAS_H__

#include <stdio.h>
#include <gmp.h>

/***********/
/* Level 1 */
/***********/

/* x <-> y */
void 
gmp_blas_swap(size_t n,          mpz_t * x, size_t incx, mpz_t * y, size_t incy);

/* x <- ax */
void 
gmp_blas_scal(size_t n, mpz_t a, mpz_t * x, size_t incx); 

/* y <- x */
void 
gmp_blas_copy(size_t n, const mpz_t * x, size_t incx, mpz_t * y, size_t incy); 

/* y <- ax + y */
void 
gmp_blas_axpy(size_t n, mpz_t a, 
	      const mpz_t * x, size_t incx, 
	      mpz_t * y,       size_t incy); 

/* d <- x^T y The integer * d has to be initialized by e.g. mpz_init() ! */
void
gmp_blas_dot(mpz_t * d, size_t n, 
	     const mpz_t * x, size_t incx, 
	     const mpz_t * y, size_t incy); 


/* Givens rotations are obviously impossible. However, the extended Euclid  
   algorithm produces its close relative: 

      g = gcd(a,b) & ka+lb = g 

   E.g. in the computation of HNF, right-multipliations by the matrix 

     [k -b/g]
     [l  a/g]

   occur frequently. Hence the name for the "Euclid rotation" function pair: */

/* For a,b, find k,l,g such that ka+lb = g = gcd(a,b) holds */
void gmp_blas_rotg(mpz_t g, mpz_t k, mpz_t l, mpz_t a, mpz_t b);
#define gmp_blas_rotg mpz_gcdext


/* x <- ax + by 
   y <- cx + dy */
void gmp_blas_rot(size_t n, 
		  mpz_t a, mpz_t b, mpz_t * x, size_t incx, 
		  mpz_t c, mpz_t d, mpz_t * y, size_t incy); 


/* In integer computations, the first nonzero element, minimal nonzero element 
   by modulus, and maximal nonzero element by modulus come often handy: */

/* Returns k such that x[(k-1)*incx] != 0 holds for the first time. 
   In FORTRAN, this is x((k-1)*incx + 1) .NE. 0.
   If none found, returns n+1. */
size_t gmp_blas_inz  (size_t n, const mpz_t * x, size_t incx);

/* Similarly, x[(k-1)*incx] is maximal by modulus */
size_t gmp_blas_iamax(size_t n, const mpz_t * x, size_t incx);

/* Similarly, x[(k-1)*incx] is nonzero and minimal by modulus */
size_t gmp_blas_iamin(size_t n, const mpz_t * x, size_t incx);

#endif
