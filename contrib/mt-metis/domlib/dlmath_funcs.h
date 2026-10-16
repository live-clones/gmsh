/**
 * @file dlmath_funcs.h
 * @brief Mathematical functions
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-06
 */




/* prefixing ugliness */
#define DLMATH_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLMATH_PRE1(prefix,suffix) DLMATH_PRE2(prefix,suffix)
#define DLMATH_PUB(name) DLMATH_PRE1(DLMATH_PREFIX,name)
#define DLMATH_PRI(name) DLMATH_PRE1(_,DLMATH_PRE1(DLMATH_PREFIX,name))


/******************************************************************************
* PRIVATE CONSTANTS ***********************************************************
******************************************************************************/


#define R2(n)    n,     n + 2*64,     n + 1*64,     n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )

static const unsigned char DLMATH_PRI(rbyte)[256] = {
    R6(0), R6(2), R6(1), R6(3)
};

#undef R2
#undef R4
#undef R6




/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/


#ifndef DLMATH_VISIBILITY
  #define DLMATH_DEFVIS
  #define DLMATH_VISIBILITY
#endif


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(abs_diff)(
    DLMATH_TYPE_T const a,
    DLMATH_TYPE_T const b)
{
  if (a > b) {
    return a - b;
  } else {
    return b - a;
  }
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(sum)(
    DLMATH_TYPE_T const * const ptr, 
    size_t const n)
{
  size_t i;
  DLMATH_TYPE_T sum = 0;
  #if defined(DLMATH_DLTYPE) && DLMATH_DLTYPE == DLTYPE_FLOAT
  size_t pend;
  DLMATH_TYPE_T pagesum;

  size_t const psize = MEM_BLOCK_SIZE / sizeof(DLMATH_TYPE_T);

  for (i=0;i<n;) {
    pagesum = 0;
    for (pend=dl_min(i+psize,n);i<pend;++i) {
      pagesum += ptr[i];
    }
    sum += pagesum;
  }
  #else
  for (i=0;i<n;++i) {
    sum += ptr[i];
  }
  #endif
  return sum;
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(product)(
    DLMATH_TYPE_T const * const ptr, 
    size_t const n) 
{
  size_t i;
  DLMATH_TYPE_T product = 1;

  for (i=0;i<n;++i) {
    product *= ptr[i];
  }
  return product;
}


DLMATH_VISIBILITY void DLMATH_PUB(differentiate)(
    DLMATH_TYPE_T * const ptr, 
    size_t const n)
{
  size_t i;

  if (n > 0) {
    for (i=0;i<n-1;++i) {
      ptr[i] = ptr[i+1] - ptr[i];
    }
    ptr[i] = 0;
  }
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(prefixsum_exc)(
    DLMATH_TYPE_T * const ptr, 
    size_t const n)
{
  size_t i;
  DLMATH_TYPE_T tmp1,tmp2;

  if (n > 0) {
    tmp1 = ptr[0];
    ptr[0] = 0;
    for (i=1;i<n;++i) {
      tmp2 = ptr[i];
      ptr[i] = tmp1 + ptr[i-1];
      tmp1 = tmp2;
    }
    return tmp1 + ptr[n-1];
  } else {
    return 0;
  }
}


DLMATH_VISIBILITY void DLMATH_PUB(prefixsum_inc)(
    DLMATH_TYPE_T * const ptr, 
    size_t const n)
{
  size_t i;

  if (n > 0) {
    for (i=1;i<n;++i) {
      ptr[i] += ptr[i-1];
    }
  }
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(prefixshift)(
    DLMATH_TYPE_T * const ptr, 
    size_t const n)
{
  size_t i;
  DLMATH_TYPE_T end;

  if (n > 0) {
    end = ptr[n-1];
    for (i=n;i>1;) {
      --i;
      ptr[i] = ptr[i-1];
    }
    ptr[0] = 0;
    return end;
  } else {
    return 0;
  }
}


DLMATH_VISIBILITY void DLMATH_PUB(add)(
    DLMATH_TYPE_T * const ptr, 
    DLMATH_TYPE_T const a, 
    size_t const n)
{
  size_t i;

  for (i=0;i<n;++i) {
    ptr[i] += a;
  }
}


DLMATH_VISIBILITY void DLMATH_PUB(scale)(
    DLMATH_TYPE_T * const ptr, 
    DLMATH_TYPE_T const a, 
    size_t const n)
{
  size_t i;

  for (i=0;i<n;++i) {
    ptr[i] *= a;
  }
}


DLMATH_VISIBILITY size_t DLMATH_PUB(max_index)(
    DLMATH_TYPE_T const * const ptr, 
    size_t const n)
{
  size_t i,maxidx;

  for (maxidx=0,i=1; i<n;++i) {
    if (ptr[i] > ptr[maxidx] || 
        (ptr[i] == ptr[maxidx] && i < maxidx)) {
      maxidx = i;
    }
  }
  return maxidx;
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(max_value)(
    DLMATH_TYPE_T const * const ptr, 
    size_t const n)
{
  DL_ASSERT(n > 0, "Passed in an empty array");
  return ptr[DLMATH_PUB(max_index)(ptr,n)];
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(set_max)(
    DLMATH_TYPE_T * const ptr, 
    DLMATH_TYPE_T const max, 
    size_t const n)
{
  size_t i, maxidx;
  DLMATH_TYPE_T diff, oldmax;

  maxidx = DLMATH_PUB(max_index)(ptr,n);
  oldmax = ptr[maxidx];
  /* Have to do this for unsigned types */
  if (oldmax < max) {
    diff = max - oldmax;
    for (i=0;i<n;++i) {
      ptr[i] += diff;
    }
  } else {
    diff = oldmax - max;
    for (i=0;i<n;++i) {
      ptr[i] -= diff;
    }
  }

  return oldmax;
}


DLMATH_VISIBILITY size_t DLMATH_PUB(min_index)(
    DLMATH_TYPE_T const * const ptr, 
    size_t const n)
{
  size_t i,minidx;

  for (minidx=0,i=1; i<n;++i) {
    if (ptr[i] < ptr[minidx] ||
        (ptr[i] == ptr[minidx] && i < minidx)) {
      minidx = i;
    }
  }
  return minidx;
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(min_value)(
    DLMATH_TYPE_T const * const ptr, 
    size_t const n)
{
  DL_ASSERT(n > 0, "Passed in an empty array");
  return ptr[DLMATH_PUB(min_index)(ptr,n)];
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(set_min)(
    DLMATH_TYPE_T * const ptr, 
    DLMATH_TYPE_T const min, 
    size_t const n)
{
  size_t i, minidx;
  DLMATH_TYPE_T diff, oldmin;

  minidx = DLMATH_PUB(min_index)(ptr,n);
  oldmin = ptr[minidx];
  
  /* Have to do this for unsigned types */
  if (oldmin < min) {
    diff = min - oldmin;
    for (i=0;i<n;++i) {
      ptr[i] += diff;
    }
  } else {
    diff = oldmin - min;
    for (i=0;i<n;++i) {
      ptr[i] -= diff;
    }
  }
  return oldmin;
}


DLMATH_VISIBILITY void DLMATH_PUB(incset)(
    DLMATH_TYPE_T * const ptr,
    DLMATH_TYPE_T const start, 
    DLMATH_TYPE_T const inc, 
    size_t const n)
{
  size_t i;

  for (i=0;i<n;++i) {
    ptr[i] = start + (inc*i);
  }
}


DLMATH_VISIBILITY void DLMATH_PUB(cyclicperm)(
    DLMATH_TYPE_T * const ptr, 
    size_t const cyclesize, 
    size_t const n)
{
  size_t i,j,k;
  size_t * counts;
  
  counts = size_calloc(cyclesize);
  for (i=0;i<n;++i) {
    j = i % cyclesize;
    k = size_chunkstart(j,cyclesize,n);
    ptr[k + counts[j]++] = i;
  }
  dl_free(counts);
}


DLMATH_VISIBILITY void DLMATH_PUB(blockcyclicperm)(
    DLMATH_TYPE_T * const ptr, 
    size_t const cyclesize, 
    size_t const blocksize, 
    size_t const n)
{
  size_t i,j,k;
  size_t * counts;
  
  if (n > 0) {
    counts = size_calloc(cyclesize);
    for (i=0;i<n;++i) {
      j = (i/blocksize) % cyclesize;
      k = size_chunkstart(j*blocksize,cyclesize*blocksize,n);
      ptr[k + counts[j]++] = i;
    }
    dl_free(counts);
  }
}


DLMATH_VISIBILITY void DLMATH_PUB(max_merge)(
    DLMATH_TYPE_T * const dst, 
    DLMATH_TYPE_T const * const src, 
    size_t const n,
    DLMATH_TYPE_T const empty_value)
{
  size_t i;

  for (i=0;i<n;++i) {
    if (src[i] != empty_value) {
      if (dst[i] != empty_value) {
        dst[i] = dl_max(dst[i],src[i]);
      } else {
        dst[i] = src[i];
      }
    }
  }
}


DLMATH_VISIBILITY void DLMATH_PUB(min_merge)(
    DLMATH_TYPE_T * const dst, 
    DLMATH_TYPE_T const * const src,
    size_t const n, 
    DLMATH_TYPE_T const empty_value)
{
  size_t i;

  for (i=0;i<n;++i) {
    if (src[i] != empty_value) {
      if (dst[i] != empty_value) {
        dst[i] = dl_min(dst[i],src[i]);
      } else {
        dst[i] = src[i];
      }
    }
  }
}


DLMATH_VISIBILITY void DLMATH_PUB(avg_merge)(
    DLMATH_TYPE_T * const dst, 
    DLMATH_TYPE_T const * const src,
    size_t const n, 
    DLMATH_TYPE_T const empty_value)
{
  size_t i;

  for (i=0;i<n;++i) {
    if (src[i] != empty_value) {
      if (dst[i] != empty_value) {
        dst[i] = (DLMATH_TYPE_T)((dst[i]+src[i])/2.0);
      } else {
        dst[i] = src[i];
      }
    }
  }
}


DLMATH_VISIBILITY size_t DLMATH_PUB(intersection_size)(
    DLMATH_TYPE_T const * const a, 
    size_t const n, 
    DLMATH_TYPE_T const * const b, 
    size_t const m)
{
  size_t i,j,matches;

  matches = i = j = 0;
  while (i<n && j < m) {
    if (a[i] > b[j]) {
      ++j;
    } else if (a[i] < b[j]) {
      ++i;
    } else {
      ++i;
      ++j;
      ++matches;
    }
  }
  return matches;
}


#if defined(DLMATH_DLTYPE) && DLMATH_DLTYPE == DLTYPE_FLOAT


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(stable_sum)(
    DLMATH_TYPE_T const * const ptr, 
    size_t const n)
{ 
  /* kahan algorithm */
  size_t i;
  DLMATH_TYPE_T y, t;
  DLMATH_TYPE_T sum, c;

  sum = 0;
  c = 0;
  for (i=0;i<n;++i) {
    y = ptr[i] - c;
    t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }
  return sum;
}


DLMATH_VISIBILITY long double DLMATH_PUB(fa_sum)(
    DLMATH_TYPE_T const * const ptr,
    size_t const n)
{
  size_t i,pend;
  long double sum;
  double pagesum;

  size_t const psize = MEM_BLOCK_SIZE / sizeof(DLMATH_TYPE_T);
  sum = 0;
  for (i=0;i<n;) {
    pagesum = 0;
    for (pend=dl_min(i+psize,n);i<pend;++i) {
      pagesum += ptr[i];
    }
    sum += (long double)pagesum;
  }
  return sum;
}


#endif


#if defined(DLMATH_DLTYPE) && DLMATH_DLTYPE == DLTYPE_INTEGRAL


DLMATH_VISIBILITY int64_t DLMATH_PUB(lsum)(
    DLMATH_TYPE_T const * const a,
    size_t const n)
{
  int64_t sum;
  size_t i;
  
  sum = 0;

  for (i=0;i<n;++i) {
    sum+=a[i];
  }

  return sum;
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(updiv)(
    DLMATH_TYPE_T const a, 
    DLMATH_TYPE_T const b)
{
  return (a/b) + (a%b > 0 ? 1 : 0);
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(chunksize)(
    DLMATH_TYPE_T const i, 
    DLMATH_TYPE_T const n, 
    DLMATH_TYPE_T const m)
{
  return (m/n) + (i < (m%n) ? 1 : 0);
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(chunkstart)(
    DLMATH_TYPE_T const i, 
    DLMATH_TYPE_T const n, 
    DLMATH_TYPE_T const m)
{
  return ((m/n)*i) + dl_min(i,m%n);
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(chunkid)(
    DLMATH_TYPE_T const g,
    DLMATH_TYPE_T const n,
    DLMATH_TYPE_T const m)
{
  DLMATH_TYPE_T a, b, c, d;

  c = m/n;
  d = m%n;

  a = g / (c + 1);
  if (g < d) {
    return a;
  } else {
    b = (g - d) / c;
    return dl_max(a,b);
  }
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(uplog2)(
    DLMATH_TYPE_T const n)
{
  return dl_bitsize(DLMATH_TYPE_T)-dl_clz((n-1) | 1);
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(downlog2)(
    DLMATH_TYPE_T const n)
{
  return (dl_bitsize(DLMATH_TYPE_T)-1)-dl_clz(n | 1);
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(uppow2)(
    DLMATH_TYPE_T n)
{
  if (n <= 1) {
    return 1;
  }
  n = n -1;
  n = n | (n >> 1);
  n = n | (n >> 2);
  n = n | (n >> 4);
  if (sizeof(DLMATH_TYPE_T) >= 2) {
    n = n | (n >> dl_maxshift(DLMATH_TYPE_T,8));
    if (sizeof(DLMATH_TYPE_T) >= 4) {
      n = n | (n >> dl_maxshift(DLMATH_TYPE_T,16));
      if (sizeof(DLMATH_TYPE_T) >= 8) {
        n = n | (n >> dl_maxshift(DLMATH_TYPE_T,32));
        if (sizeof(DLMATH_TYPE_T) >= 16) {
          n = n | (n >> dl_maxshift(DLMATH_TYPE_T,64));
        }
      }
    }
  }
  return n + 1;
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(downpow2)(
    DLMATH_TYPE_T n)
{
  if (n <= 1) {
    return 1;
  }
  n = n | (n >> 1);
  n = n | (n >> 2);
  n = n | (n >> 4);
  if (sizeof(DLMATH_TYPE_T) >= 2) {
    n = n | (n >> dl_maxshift(DLMATH_TYPE_T,8));
    if (sizeof(DLMATH_TYPE_T) >= 4) {
      n = n | (n >> dl_maxshift(DLMATH_TYPE_T,16));
      if (sizeof(DLMATH_TYPE_T) >= 8) {
        n = n | (n >> dl_maxshift(DLMATH_TYPE_T,32));
        if (sizeof(DLMATH_TYPE_T) >= 16) {
          n = n | (n >> dl_maxshift(DLMATH_TYPE_T,64));
        }
      }
    }
  }
  return n - (n >> 1);
}


DLMATH_VISIBILITY DLMATH_TYPE_T DLMATH_PUB(reversebits)(
    DLMATH_TYPE_T const n)
{
  DLMATH_TYPE_T r;
  size_t i;

  r = 0;

  for (i=0;i<sizeof(DLMATH_TYPE_T);++i) {
    r |= DLMATH_PRI(rbyte)[(n >> (8*i)) & 0xFF] << 
        ((sizeof(DLMATH_TYPE_T)-i-1)*8);
  }

  return r;
}


#endif


#ifdef DLMATH_DEFVIS  
  #undef DLMATH_DEFVIS
  #undef DLMATH_VISIBILITY
#endif


#undef DLMATH_PRE1
#undef DLMATH_PRE2
#undef DLMATH_PUB
#undef DLMATH_PRI
