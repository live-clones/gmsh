/* 
   Source file for integer-oriented elementary versions of some 
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

   $Id: gmp_blas.c,v 1.1 2009-03-30 14:10:57 matti Exp $
*/

/* #include<stdio.h> */
#include"gmp_blas.h"

void gmp_blas_swap(size_t n, mpz_t* x, size_t incx, mpz_t* y, size_t incy)
{
  mpz_t  elbow;
  size_t ind;

  mpz_init(elbow);

  for(ind = 0; ind < n; ind++)
    {
      mpz_set(elbow      , x[ind*incx]);
      mpz_set(x[ind*incx], y[ind*incy]);
      mpz_set(y[ind*incy], elbow);
    }
  mpz_clear(elbow);

  return;
}

void gmp_blas_scal(size_t n, mpz_t a, mpz_t* x, size_t incx)
{
  size_t ind;

  for(ind = 0; ind < n; ind++)
    {
      mpz_mul (x[ind*incx], x[ind*incx], a);
    }

  return;
}

void gmp_blas_copy(size_t n, mpz_t* x, size_t incx, mpz_t* y, size_t incy)
{
  size_t ind;

  for(ind = 0; ind < n; ind++)
    {
      mpz_set(y[ind*incy], x[ind*incx]);
    }

  return;
}

void gmp_blas_axpy(size_t n, mpz_t a, mpz_t* x, size_t incx, 
		   mpz_t* y, size_t incy)
{
  size_t ind;

  for(ind = 0; ind < n; ind++)
    {
      mpz_addmul (y[ind*incy], a, x[ind*incx]);
    }

  return;
}

void
gmp_blas_dot(mpz_t * d, size_t n, 
	     mpz_t* x, size_t incx, 
	     mpz_t* y, size_t incy)
{
  size_t ind;

  mpz_set_si(*d,0);

  for(ind = 0; ind < n; ind++)
    {
      mpz_addmul (*d, x[ind*incx], y[ind*incy]);
    }

  return;  
}

/* x <- ax + by 
   y <- cx + dy */
void gmp_blas_rot(size_t n, 
		  mpz_t a, mpz_t b, mpz_t* x, size_t incx, 
		  mpz_t c, mpz_t d, mpz_t* y, size_t incy)
{
  mpz_t  ax;
  mpz_t  by;
  mpz_t  cx;
  mpz_t  dy;

  size_t ind;

  mpz_init(ax);
  mpz_init(by);
  mpz_init(cx);
  mpz_init(dy);

  for(ind = 0; ind < n; ind++)
    {
      mpz_mul (ax, a, x[ind*incx]);
      mpz_mul (by, b, y[ind*incy]);
      mpz_mul (cx, c, x[ind*incx]);
      mpz_mul (dy, d, y[ind*incy]);
      mpz_add (x[ind*incx], ax, by);
      mpz_add (y[ind*incy], cx, dy);
    }

  mpz_clear(ax);
  mpz_clear(by);
  mpz_clear(cx);
  mpz_clear(dy);

  return;
}


/* Returns k such that x[(k-1)*incx] != 0 holds for the first time. 
   If none found, returns n+1. */
size_t gmp_blas_inz  (size_t n, mpz_t* x, size_t incx)
{
  size_t ind;

  for(ind = 0; ind < n; ind++)
    {
      if(mpz_sgn (x[ind*incx]) != 0)
	{  
	  return ind+1; 
	}
    }

  /* No nonzeros found */
  return n+1; 
}

size_t gmp_blas_iamax(size_t n, mpz_t* x, size_t incx)
{
  size_t ind;
  size_t ind_so_far;
  mpz_t  max_so_far;

  mpz_init(max_so_far);
  mpz_set_si(max_so_far, 0);
  ind_so_far = 0;

  for(ind = 0; ind < n; ind++)
    {
      if(mpz_cmpabs (x[ind*incx], max_so_far) > 0)
	{  
	  mpz_set(max_so_far, x[ind*incx]);
	  ind_so_far = ind;
	}
    }

  /* No nonzeros found */
  if(mpz_sgn (max_so_far) == 0)
    {
      mpz_clear(max_so_far);
      return n + 1; 
    }

  /* Nonzero maximal by modulus element found */
  mpz_clear(max_so_far);
  return ind_so_far + 1; 
}


size_t gmp_blas_iamin(size_t n, mpz_t* x, size_t incx)
{
  size_t ind;
  size_t ind_so_far;
  mpz_t  min_so_far;

  ind_so_far = gmp_blas_inz (n, x, incx);

  /* No nonzeros found? */
  if(ind_so_far == n+1)
    {
      return n+1;
    }

  /* OK, There is at leat one nonzero element */
  mpz_init(min_so_far);
  mpz_set(min_so_far, x[(ind_so_far-1)*incx]);

  /* Scan through te rest of the elements to see if smaller  
     elements by modulus are found */
  for(ind = ind_so_far-1; ind < n; ind++)
    {
      if(mpz_sgn (x[ind*incx]) != 0)
	{
	  if(mpz_cmpabs (x[ind*incx], min_so_far) < 0)
	    { 
	      mpz_set(min_so_far, x[ind*incx]);
	      ind_so_far = ind + 1;
	    }
	}
    }

  /* Nonzero minimal by modulus element found */
  mpz_clear(min_so_far);
  return ind_so_far;
}
