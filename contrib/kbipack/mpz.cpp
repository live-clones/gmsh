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

#include "mpz.h"
#include "GmshConfig.h"

#if ! defined(HAVE_GMP)

#include "GmshMessage.cpp"
#include "limits.h"

void overflow()
{
  printf("ERROR: Integer overflow detected! Compile with GMP library to fix this. \n");
  Msg::Error("Integer overflow detected! Compile with GMP library to fix this. \n");
}

long int addcheck(long int a, long int b){
  long int c = a + b;
  if (b >= 0){
    if (c < a) overflow();
  }
  else if (b < 0){
    if (c > a) overflow();
  }
  return c;
}

long int multcheck(long int a, long int b){
  long long int c = (long long int)a*b;
  if(c > LONG_MAX || c < LONG_MIN) overflow();
  return c;
}

void mpz_init(mpz_ptr x)
{
  x->z = 0;
}

void mpz_init_set(mpz_ptr rop, mpz_ptr op)
{
  rop->z = op->z;
}

void mpz_init_set_si(mpz_ptr rop, signed long int op)
{
  rop->z = op;
}

void mpz_set_ui(mpz_ptr rop, unsigned long int op)
{
  rop->z = op;
}

void mpz_set(mpz_ptr rop, mpz_ptr op)
{
  rop->z = op->z;
}
void mpz_set_si(mpz_ptr rop, signed long int op)
{
  rop->z = op;
}

void mpz_clear(mpz_ptr x)
{

}

// arithmethic
void mpz_add(mpz_ptr rop, mpz_ptr op1, mpz_ptr op2)
{
  rop->z = addcheck(op1->z, op2->z);
}

void mpz_mul(mpz_ptr rop, mpz_ptr op1, mpz_ptr op2)
{
  rop->z = multcheck(op1->z, op2->z);
}

void mpz_addmul(mpz_ptr rop, mpz_ptr op1, mpz_ptr op2)
{
  rop->z = addcheck(rop->z,multcheck(op1->z,op2->z));
}

void mpz_neg(mpz_ptr rop, mpz_ptr op)
{
  rop->z = -op->z;
}


// division 
void mpz_divexact(mpz_ptr q, mpz_ptr n, mpz_ptr d)
{
  div_t temp;
  temp = div(n->z, d->z);
  q->z = temp.quot;
}

void mpz_cdiv_q(mpz_ptr q, mpz_ptr n, mpz_ptr d)
{
  div_t temp;
  temp = div(n->z, d->z);
  q->z = temp.quot;
}
void mpz_cdiv_qr(mpz_ptr q, mpz_ptr r, mpz_ptr n, mpz_ptr d)
{
  div_t temp;
  temp = div(n->z, d->z);
  q->z = temp.quot;
  r->z = temp.rem;
}

void mpz_tdiv_r(mpz_ptr r, mpz_ptr n, mpz_ptr d)
{
  div_t temp;
  temp = div(n->z, d->z);
  if(n->z < 0) r->z = -temp.rem;
  else r->z = temp.rem;
}

// compare
int mpz_cmp_si(mpz_ptr op1, signed long int op2)
{
  if(op1->z > op2) return 1;
  else if(op1->z < op2) return -1;
  else return 0;
  return 0;
}

int mpz_cmpabs(mpz_ptr op1, mpz_ptr op2)
{
  if(abs(op1->z) > abs(op2->z)) return 1;
  else if(abs(op1->z) < abs(op2->z)) return -1;
  else return 0;
  return 0;
}

int mpz_sgn(mpz_ptr op)
{
  if(op->z > 0) return 1;
  else if(op->z < 0) return -1;
  else return 0;
}

signed long int mpz_get_si(mpz_ptr op)
{
  signed long int temp = op->z;
  return temp;
}

long int gcd(long int a, long int b)
{
  long int temp = 0;
  long int remainder = 0;
  if (a < b) {
    temp = a;
    a = b;
    b = temp;
  }
  remainder = a % b;
  if(remainder == 0) return b;
  else return gcd(b, remainder);
}

void extended_gcd(long int* g, long int* s, long int* t,
		  long int a, long int b)
{
  long int x = 0;
  long int lastx = 1;
  long int y = 1;    
  long int lasty = 0;
  while (b != 0){
    div_t divt = div(a,b);
    long int quotient = divt.quot;
        
    long int temp = b;
    b = a % b;
    a = temp;
        
    temp = x;
    x = addcheck(lastx, multcheck(-quotient,x));
    lastx = temp;
        
    temp = y;
    y = addcheck(lasty, multcheck(-quotient,y));
    lasty = temp;
  }
  *s = lastx;
  *t = lasty;
  *g = a;
}

void mpz_gcdext(mpz_ptr g, mpz_ptr s, mpz_ptr t, mpz_ptr a, mpz_ptr b)
{
  
  extended_gcd(&g->z, &s->z, &t->z, a->z, b->z);
  /*printf("g: %ld, s: %ld, t: %ld, a: %ld, b: %ld. \n", 
    g->z, s->z, t->z, a->z, b->z); */
}

size_t mpz_out_str(FILE *stream, int base, mpz_ptr op)
{
  return 0;
}

/*
main()
{

  mpz_t a;
  mpz_t b;
  mpz_t c;
  mpz_init(a);
  mpz_init(b);
  mpz_init(c);

  mpz_set_si(a, 2147483647);
  mpz_set_si(b, 2);
  mpz_mul(c, a, b);

  printf("a: %ld, b: %ld, c: %ld. \n", a->z, b->z, c->z);

  return EXIT_SUCCESS;

  }*/
#endif
