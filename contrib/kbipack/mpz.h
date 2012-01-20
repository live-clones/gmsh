/*
  This is an interface to masquerade ordinary long integers in C
  language behind an interface mimicing arbitrary precision arithmetic
  interger (mpz) interface in The GNU MP Bignum library.

  Only the functions needed by Kbipack are available.

  THIS INTERFACE IS NOT BERFORMING ANY ARBITRARY PRECISION ARITHMETIC.
  You should always use the GMP library (http://gmplib.org/) when possible.

  Some basic techniques to detect integer overflows are implemented.
  However, they don't interfere the program flow IN ANY WAY, they just write
  an error message to stdout.

 */

#ifndef __MPZ_H__
#define __MPZ_H__

#include "GmshConfig.h"

#if defined(HAVE_GMP)
#include "gmp.h"
#else

#include <stdlib.h>
#include <stdio.h>

typedef struct {
  long int z; 
} mpz_struct;

typedef mpz_struct mpz_t[1];  
typedef mpz_struct* mpz_ptr;

// init
void mpz_init(mpz_ptr x);
void mpz_init_set(mpz_ptr rop, mpz_ptr op);
void mpz_init_set_si(mpz_ptr rop, signed long int op);

// set
void mpz_set(mpz_ptr rop, mpz_ptr op);
void mpz_set_si(mpz_ptr rop, signed long int op);
void mpz_set_ui(mpz_ptr rop, unsigned long int op);

// clear
void mpz_clear(mpz_ptr x);


// arithmethic
void mpz_add(mpz_ptr rop, mpz_ptr op1, mpz_ptr op2);
void mpz_mul(mpz_ptr rop, mpz_ptr op1, mpz_ptr op2);
void mpz_addmul(mpz_ptr rop, mpz_ptr op1, mpz_ptr op2);
void mpz_neg(mpz_ptr rop, mpz_ptr op);

// division 
void mpz_divexact(mpz_ptr q, mpz_ptr n, mpz_ptr d);
void mpz_cdiv_q(mpz_ptr q, mpz_ptr n, mpz_ptr d);
void mpz_cdiv_qr(mpz_ptr q, mpz_ptr r, mpz_ptr n, mpz_ptr d);
void mpz_tdiv_r(mpz_ptr r, mpz_ptr n, mpz_ptr d);

// compare
int mpz_cmp_si(mpz_ptr op1, signed long int op2);
int mpz_cmpabs(mpz_ptr op1, mpz_ptr op2);
int mpz_sgn(mpz_ptr op);

// extended Euclid's algorithm
void mpz_gcdext(mpz_ptr g, mpz_ptr s, mpz_ptr t, mpz_ptr a, mpz_ptr b);

// conversion
signed long int mpz_get_si(mpz_ptr op);

// io
size_t mpz_out_str(FILE *stream, int base, mpz_ptr op);
#endif
#endif

