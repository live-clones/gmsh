/* 
   Header file for integer computation of Hermite and Smith normal 
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


   Copyright (C) 30.10.2003Saku Suuriniemi  TUT/CEM

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

   $Id: gmp_normal_form.h,v 1.1 2009-03-30 14:10:57 matti Exp $
*/

#ifndef _GMP_NORMAL_FORM_
#define _GMP_NORMAL_FORM_

#include"gmp_blas.h"
#include"gmp_matrix.h"

typedef enum {NOT_INVERTED, INVERTED} inverted_flag;

typedef struct
{
  gmp_matrix * left;
  gmp_matrix * canonical;
  gmp_matrix * right;
  inverted_flag left_inverted;
  inverted_flag right_inverted;
} gmp_normal_form;

/* For efficiency, the routines assume responsibility for the input matrices. 
   Do *not* destroy them yourself! */

/***********************/
/* Hermite normal form */
/***********************/
/* 
   PA = LU, 

   left:
   o P permutation matrix 
     - Use "left_inverted = INVERTED" for left = P, 
       and "left_inverted = NOT_INVERTED"  for left = P^T, i.e. for the 
       decomposition 
                      A = P^T L U.
   canonical:
   o L lower triangular, 
     - diagonal entries positive, 
     - subdiagonal entries positive 
     - subdiagonal entries smaller than the diagonal entry of their row 

   right:
   o U unimodular,
     - Use "right_inverted = NOT_INVERTED" for right = U, i.e. for the 
       decomposition 
                      P A = L U, 
       and "right_inverted = INVERTED" for right = inv(U), i.e. for the 
       decompositions 
                      P A inv(U) = L and  A inv(U) = P^T L. 

   Algorithm: Kannan-Bachem algorithm with improved (by Chou & Collins) 
              reduction phase.

   References: 
    [1] Ravindran Kannan, Achim Bachem: 
        "Polynomial algorithms for computing the Smith and Hermite normal 
	forms of an integer matrix", 
	SIAM J. Comput., vol. 8, no. 5, pp. 499-507, 1979.
    [2] Tsu-Wu J.Chou, George E. Collins: 
        "Algorithms for the solution of systems of linear Diophantine 
	equations", 
	SIAM J. Comput., vol. 11, no. 4, pp. 687-708, 1982.
*/

gmp_normal_form * 
create_gmp_Hermite_normal_form(gmp_matrix * A, 
			       inverted_flag left_inverted,
			       inverted_flag right_inverted);



/*********************/
/* Smith normal form */
/*********************/
/* 
   A = USV, 

   left:
   o U unimodular factor matrix 
     - Use "left_inverted = NOT_INVERTED"  for left = U and 
       "left_inverted = INVERTED" for left = inv(U), i.e. for 
       the decomposition 
                          inv(U) A = S V.

   canonical:
   o S diagonal, 
     - first k diagonal entries positive (invariant factors of A), 
       rest zero 
     - each positive diagonal entry divisible by the previous one

   right:
   o V unimodular,
     - Use "right_inverted = NOT_INVERTED" for right = V, 
       and "right_inverted = INVERTED" for right = inv(V), i.e. for the 
       decompositions 
                      A inv(V) = U S and  inv(U) A inv(V) = S. 

   Algorithm: Successive Hermite normal forms by Kannan-Bachem algorithm 
              with improved (by Chou & Collins) reduction phase. See 
	      reference [1].
*/

gmp_normal_form *
create_gmp_Smith_normal_form(gmp_matrix * A,
			     inverted_flag left_inverted,
			     inverted_flag right_inverted);

int destroy_gmp_normal_form(gmp_normal_form*);

#endif
