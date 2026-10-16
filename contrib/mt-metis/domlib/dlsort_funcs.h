/**
 * @file dlsort_funcs.h
 * @brief Sorting functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */




/* prefixing ugliness */
#define DLSORT_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLSORT_PRE1(prefix,suffix) DLSORT_PRE2(prefix,suffix)
#define DLSORT_PUB(name) DLSORT_PRE1(DLSORT_PREFIX,name)
#define DLSORT_PRI(name) DLSORT_PRE1(_,DLSORT_PRE1(DLSORT_PREFIX,name))




/******************************************************************************
* CONSTANTS *******************************************************************
******************************************************************************/


static const size_t DLSORT_PRI(nbuckets) = 256;




/******************************************************************************
* FUNCTIONS *******************************************************************
******************************************************************************/


#ifndef DLSORT_VISIBILITY
  #define DLSORT_DEFVIS
  #define DLSORT_VISIBILITY
#endif


#ifndef DLSORT_COMPARE
#define DLSORT_DEFAULT_COMPARE 1
#define DLSORT_COMPARE(a,b) ((a) < (b))
#endif


#define __BS_BLOCK(n,x,y,v,b,a) \
  case (n) : \
    if (DLSORT_COMPARE(v,a[(x)+((signed)b)])) { \
      (y) = (x) + ((signed)b); \
    } else { \
      (x) = (y) - ((signed)b); \
    }


DLSORT_VISIBILITY ssize_t DLSORT_PUB(binarysearch)(
    const DLSORT_TYPE_T * const ptr, const DLSORT_TYPE_T v, const size_t n)
{
  ssize_t i = 0;
  ssize_t _bs_end = (ssize_t)n;
  int jump = (int)((64u - dl_bitsize(n)) + dl_clz(n));
  switch (jump) {
    __BS_BLOCK( 0,i,_bs_end,v,BIN63,ptr)
    __BS_BLOCK( 1,i,_bs_end,v,BIN62,ptr)
    __BS_BLOCK( 2,i,_bs_end,v,BIN61,ptr)
    __BS_BLOCK( 3,i,_bs_end,v,BIN60,ptr)
    __BS_BLOCK( 4,i,_bs_end,v,BIN59,ptr)
    __BS_BLOCK( 5,i,_bs_end,v,BIN58,ptr)
    __BS_BLOCK( 6,i,_bs_end,v,BIN57,ptr)
    __BS_BLOCK( 7,i,_bs_end,v,BIN56,ptr)
    __BS_BLOCK( 8,i,_bs_end,v,BIN55,ptr)
    __BS_BLOCK( 9,i,_bs_end,v,BIN54,ptr)
    __BS_BLOCK(10,i,_bs_end,v,BIN53,ptr)
    __BS_BLOCK(11,i,_bs_end,v,BIN52,ptr)
    __BS_BLOCK(12,i,_bs_end,v,BIN51,ptr)
    __BS_BLOCK(13,i,_bs_end,v,BIN50,ptr)
    __BS_BLOCK(14,i,_bs_end,v,BIN49,ptr)
    __BS_BLOCK(15,i,_bs_end,v,BIN48,ptr)
    __BS_BLOCK(16,i,_bs_end,v,BIN47,ptr)
    __BS_BLOCK(17,i,_bs_end,v,BIN46,ptr)
    __BS_BLOCK(18,i,_bs_end,v,BIN45,ptr)
    __BS_BLOCK(19,i,_bs_end,v,BIN44,ptr)
    __BS_BLOCK(20,i,_bs_end,v,BIN43,ptr)
    __BS_BLOCK(21,i,_bs_end,v,BIN42,ptr)
    __BS_BLOCK(22,i,_bs_end,v,BIN41,ptr)
    __BS_BLOCK(23,i,_bs_end,v,BIN40,ptr)
    __BS_BLOCK(24,i,_bs_end,v,BIN39,ptr)
    __BS_BLOCK(25,i,_bs_end,v,BIN38,ptr)
    __BS_BLOCK(26,i,_bs_end,v,BIN37,ptr)
    __BS_BLOCK(27,i,_bs_end,v,BIN36,ptr)
    __BS_BLOCK(28,i,_bs_end,v,BIN35,ptr)
    __BS_BLOCK(29,i,_bs_end,v,BIN34,ptr)
    __BS_BLOCK(30,i,_bs_end,v,BIN33,ptr)
    __BS_BLOCK(31,i,_bs_end,v,BIN32,ptr)
    __BS_BLOCK(32,i,_bs_end,v,BIN31,ptr)
    __BS_BLOCK(33,i,_bs_end,v,BIN30,ptr)
    __BS_BLOCK(34,i,_bs_end,v,BIN29,ptr)
    __BS_BLOCK(35,i,_bs_end,v,BIN28,ptr)
    __BS_BLOCK(36,i,_bs_end,v,BIN27,ptr)
    __BS_BLOCK(37,i,_bs_end,v,BIN26,ptr)
    __BS_BLOCK(38,i,_bs_end,v,BIN25,ptr)
    __BS_BLOCK(39,i,_bs_end,v,BIN24,ptr)
    __BS_BLOCK(40,i,_bs_end,v,BIN23,ptr)
    __BS_BLOCK(41,i,_bs_end,v,BIN22,ptr)
    __BS_BLOCK(42,i,_bs_end,v,BIN21,ptr)
    __BS_BLOCK(43,i,_bs_end,v,BIN20,ptr)
    __BS_BLOCK(44,i,_bs_end,v,BIN19,ptr)
    __BS_BLOCK(45,i,_bs_end,v,BIN18,ptr)
    __BS_BLOCK(46,i,_bs_end,v,BIN17,ptr)
    __BS_BLOCK(47,i,_bs_end,v,BIN16,ptr)
    __BS_BLOCK(48,i,_bs_end,v,BIN15,ptr)
    __BS_BLOCK(49,i,_bs_end,v,BIN14,ptr)
    __BS_BLOCK(50,i,_bs_end,v,BIN13,ptr)
    __BS_BLOCK(51,i,_bs_end,v,BIN12,ptr)
    __BS_BLOCK(52,i,_bs_end,v,BIN11,ptr)
    __BS_BLOCK(53,i,_bs_end,v,BIN10,ptr)
    __BS_BLOCK(54,i,_bs_end,v,BIN09,ptr)
    __BS_BLOCK(55,i,_bs_end,v,BIN08,ptr)
    __BS_BLOCK(56,i,_bs_end,v,BIN07,ptr)
    __BS_BLOCK(57,i,_bs_end,v,BIN06,ptr)
    __BS_BLOCK(58,i,_bs_end,v,BIN05,ptr)
    __BS_BLOCK(59,i,_bs_end,v,BIN04,ptr)
    __BS_BLOCK(60,i,_bs_end,v,BIN03,ptr)
    __BS_BLOCK(61,i,_bs_end,v,BIN02,ptr)
    __BS_BLOCK(62,i,_bs_end,v,BIN01,ptr)
    __BS_BLOCK(63,i,_bs_end,v,BIN00,ptr)
  }


  return i;
}


DLSORT_VISIBILITY DLSORT_TYPE_T * DLSORT_PUB(insertionsort)(
    DLSORT_TYPE_T * const a, const size_t n)
{
  size_t i;
  ssize_t j;
  DLSORT_TYPE_T b;
  for (i=1;i<n;++i) {
    b = a[i];
    j = i;
    while (j > 0 &&  DLSORT_COMPARE(b,a[j-1])) {
      --j;
    }
    memmove(a+(j+1),a+j,sizeof(DLSORT_TYPE_T)*(i-j));
    a[j] = b;
  }
  return a;
}


DLSORT_VISIBILITY DLSORT_TYPE_T * DLSORT_PUB(quicksort)(
    DLSORT_TYPE_T * const a, const size_t n) 
{
  DLSORT_TYPE_T mid;
  size_t i,j,k;
  if (n < MIN_QUICKSORT_SIZE) {
    DLSORT_PUB(insertionsort)(a,n);
  } else {
    i = 1;
    j = n-1;
    k = n >> 1;
    mid = a[k];
    a[k] = a[0];
    while (i < j) {
      if (DLSORT_COMPARE(mid,a[i])) { /* a[i] is on the wrong side */
        if (!DLSORT_COMPARE(mid,a[j])) {
          dl_swap(a[i],a[j]);
          ++i;
        }
        --j;
      } else {
        if (DLSORT_COMPARE(mid,a[j])) { /* a[j] is on the right side */
          --j;
        }
        ++i;
      }
    }
    if (DLSORT_COMPARE(mid,a[i])) {
      --i;
    }
    a[0] = a[i];
    a[i] = mid;
    if (i > 1) {
      DLSORT_PUB(quicksort)(a,i);
    }
    ++i; /* skip the pivot element */
    if (n-i > 1) {
      DLSORT_PUB(quicksort)(a+i,n-i);
    }
  }
  return a;
}


DLSORT_VISIBILITY DLSORT_TYPE_T * DLSORT_PUB(radixsort)(
    DLSORT_TYPE_T * const a, const size_t n)
{
  size_t npass, pass, i, j;
  size_t bcount[DLSORT_PRI(nbuckets)];
  npass = sizeof(DLSORT_TYPE_T);
  DLSORT_TYPE_T * b = malloc(sizeof(DLSORT_TYPE_T)*n);
  DLSORT_TYPE_T * c = a;
  #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ 
  #if defined(DLSORT_DLSIGN) && DLSORT_DLSIGN == DLSIGN_UNSIGNED
  /* do the counting */
  for (pass=npass;pass>0;) {
    --pass;
    size_set(bcount,0,DLSORT_PRI(nbuckets));
    for (i=0;i<n;++i) {
      j = ((unsigned char*)(c+i))[pass];
      ++bcount[j];
    }
    /* prefix sum */
    size_prefixsum_exc(bcount,DLSORT_PRI(nbuckets));
    for (i=0;i<n;++i) {
      j = ((unsigned char*)(c+i))[pass];
      b[bcount[j]++] = c[i];
    }
  }
  dl_swap(c,b);
  #else
  /* do the counting */
  for (pass=npass;pass>0;) {
    --pass;
    size_set(bcount,0,DLSORT_PRI(nbuckets));
    for (i=0;i<n;++i) {
      j = ((unsigned char*)(c+i))[pass];
      ++bcount[j];
    }
    /* prefix sum */
    size_prefixsum_exc(bcount,DLSORT_PRI(nbuckets));
    for (i=0;i<n;++i) {
      j = ((unsigned char*)(c+i))[pass];
      b[bcount[j]++] = c[i];
    }
    dl_swap(c,b);
  }
  /* extract first iteration from the loop */
  size_set(bcount,0,DLSORT_PRI(nbuckets));
  for (i=0;i<n;++i) {
    j = ((unsigned char*)(c+i))[0] ^ 0x80;
    ++bcount[j];
  }
  /* prefix sum */
  size_prefixsum_exc(bcount,DLSORT_PRI(nbuckets));
  for (i=0;i<n;++i) {
    j = ((unsigned char*)(c+i))[0] ^ 0x80;
    b[bcount[j]++] = c[i];
  }
  dl_swap(c,b);
  #endif
  #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  #if defined(DLSORT_DLSIGN) && DLSORT_DLSIGN == DLSIGN_UNSIGNED
  /* do the counting */
  for (pass=0;pass<npass;++pass) {
    size_set(bcount,0,DLSORT_PRI(nbuckets));
    for (i=0;i<n;++i) {
      j = ((unsigned char*)(c+i))[pass];
      ++bcount[j];
    }
    /* prefix sum */
    size_prefixsum_exc(bcount,DLSORT_PRI(nbuckets));
    for (i=0;i<n;++i) {
      j = ((unsigned char*)(c+i))[pass];
      b[bcount[j]++] = c[i];
    }
    dl_swap(c,b);
  }
  #else
  /* do the counting */
  for (pass=0;pass<npass-1;++pass) {
    size_set(bcount,0,DLSORT_PRI(nbuckets));
    for (i=0;i<n;++i) {
      j = ((unsigned char*)(c+i))[pass];
      ++bcount[j];
    }
    /* prefix sum */
    size_prefixsum_exc(bcount,DLSORT_PRI(nbuckets));
    for (i=0;i<n;++i) {
      j = ((unsigned char*)(c+i))[pass];
      b[bcount[j]++] = c[i];
    }
    dl_swap(c,b);
  }
  /* extract last iteration from the loop */
  size_set(bcount,0,DLSORT_PRI(nbuckets));
  for (i=0;i<n;++i) {
    j = ((unsigned char*)(c+i))[pass] ^ 0x80;
    ++bcount[j];
  }
  /* prefix sum */
  size_prefixsum_exc(bcount,DLSORT_PRI(nbuckets));
  for (i=0;i<n;++i) {
    j = ((unsigned char*)(c+i))[pass] ^ 0x80;
    b[bcount[j]++] = c[i];
  }
  dl_swap(c,b);
  #endif
  #else /* they have the crazy PDP order ! */
  #endif
  if (a == c) {
    free(b);
  } else {
    memcpy(a,c,n*sizeof(DLSORT_TYPE_T));
    free(c);
  }
  return a;
} 


#ifdef DLSORT_DEFAULT_COMPARE
  #undef DLSORT_DEFAULT_COMPARE
  #undef DLSORT_COMPARE
#endif


#ifdef DLSORT_DEFVIS
  #undef DLSORT_DEFVIS
  #undef DLSORT_VISIBILITY
#endif


#undef DLSORT_PRE2
#undef DLSORT_PRE1
#undef DLSORT_PUB
#undef DLSORT_PRI


