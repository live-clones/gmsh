// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_SORT_H
#define HXT_SORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_tools.h"
#include "hxt_omp.h"

// sorting function already defined
typedef struct{
  uint64_t v[2];
}HXTGroup2;

typedef struct{
  uint64_t v[3];
}HXTGroup3;

HXTStatus group1_sort(uint64_t* val, const uint64_t n, const uint64_t max);

HXTStatus group2_sort_v0(HXTGroup2* pair, const uint64_t n, const uint64_t max);
HXTStatus group2_sort_v1(HXTGroup2* pair, const uint64_t n, const uint64_t max);

HXTStatus group3_sort_v0(HXTGroup3* triplet, const uint64_t n, const uint64_t max);
HXTStatus group3_sort_v1(HXTGroup3* triplet, const uint64_t n, const uint64_t max);
HXTStatus group3_sort_v2(HXTGroup3* triplet, const uint64_t n, const uint64_t max);

/* convert from other types to uint32_t CONSERVING ORDER FOR ALL VALUES ! */

static inline uint32_t i32_to_u32(int32_t v){
  uint32_t mask = - (v>>31) | UINT32_C(0x80000000);
  return v^mask;
}

static inline uint64_t i64_to_u64(int64_t v){
  uint64_t mask = - (v>>63) | UINT64_C(0x8000000000000000);
  return v^mask;
}

static inline uint32_t float_to_u32(float f){
  union {float f; uint32_t u;} v = {f};
  uint32_t mask = -(v.u>>31) | UINT32_C(0x80000000);
  return v.u^mask;
}


static inline uint64_t double_to_u64(double d){
  union {double f; uint64_t u;} v = {d};
  uint64_t mask = -(v.u>>63) | UINT64_C(0x8000000000000000);
  return v.u^mask;
}


static inline unsigned u32_log2(uint32_t v) {
  unsigned i=0;
  while(v>>=1){i++;}
  return i;
}

static inline unsigned u64_log2(uint64_t v) {
  unsigned i=0;
  while(v>>=1){i++;}
  return i;
}


#ifndef HXT_SORT_SEQUENTIAL_LIMIT
// below this number, launching OpenMP threads is unnecessary
#define HXT_SORT_SEQUENTIAL_LIMIT 32768
#endif


#define HXTSORT32(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)                       \
do{                                                                                      \
  const uint64_t _copyNb = (N);                                                          \
  if(_copyNb<64){                                                                        \
    INSERTION_SORT32(HXTSORT_TYPE, ARRAY, _copyNb, GET_KEY, USER_DATA);                  \
  }                                                                                      \
  else if(_copyNb < HXT_SORT_SEQUENTIAL_LIMIT || omp_get_max_threads()<=1){              \
    LSB32(HXTSORT_TYPE, ARRAY, _copyNb, MAX, GET_KEY, USER_DATA);                        \
  }                                                                                      \
  else {                                                                                 \
    PARALLEL_LSB32(HXTSORT_TYPE, ARRAY, _copyNb, MAX, GET_KEY, USER_DATA);               \
  }                                                                                      \
}while(0)


#define HXTSORT64(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)                       \
do{                                                                                      \
  const uint64_t _copyNb = (N);                                                          \
  const uint64_t _copyMax = (MAX);                                                       \
  if(_copyNb < 64){                                                                      \
    INSERTION_SORT64(HXTSORT_TYPE, ARRAY, _copyNb, GET_KEY, USER_DATA);                  \
  }                                                                                      \
  else if(_copyNb < HXT_SORT_SEQUENTIAL_LIMIT || omp_get_max_threads()<=1) {             \
    LSB64(HXTSORT_TYPE, ARRAY, _copyNb, _copyMax, GET_KEY, USER_DATA);                   \
  }                                                                                      \
  else {                                                                                 \
    PARALLEL_LSB64(HXTSORT_TYPE, ARRAY, _copyNb, _copyMax, GET_KEY, USER_DATA);          \
  }                                                                                      \
}while(0)


#define HXTSORT32_UNIFORM(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)               \
do{                                                                                      \
  const uint64_t _copyNb = (N);                                                          \
  if(_copyNb < 64) {                                                                     \
    INSERTION_SORT32(HXTSORT_TYPE, ARRAY, _copyNb, GET_KEY, USER_DATA);                  \
  }                                                                                      \
  else if(_copyNb < HXT_SORT_SEQUENTIAL_LIMIT || omp_get_max_threads()<=1) {             \
    LSB32(HXTSORT_TYPE, ARRAY, _copyNb, MAX, GET_KEY, USER_DATA);                        \
  }                                                                                      \
  else {                                                                                 \
    PARALLEL_HYBRID32(HXTSORT_TYPE, ARRAY, _copyNb, MAX, GET_KEY, USER_DATA);            \
  }                                                                                      \
}while(0)


#define HXTSORT64_UNIFORM(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)               \
do{                                                                                      \
  const uint64_t _copyNb = (N);                                                          \
  const uint64_t _copyMax = (MAX);                                                       \
  if(_copyNb < 64) {                                                                     \
    INSERTION_SORT64(HXTSORT_TYPE, ARRAY, _copyNb, GET_KEY, USER_DATA);                  \
  }                                                                                      \
  else if(_copyNb < HXT_SORT_SEQUENTIAL_LIMIT || omp_get_max_threads()<=1) {             \
    LSB64(HXTSORT_TYPE, ARRAY, _copyNb, _copyMax, GET_KEY, USER_DATA);                   \
  }                                                                                      \
  else if(_copyMax < UINT64_MAX/2048/SIMD_ALIGN) {                                       \
    PARALLEL_HYBRID64_ADAPT(HXTSORT_TYPE, ARRAY, _copyNb, _copyMax, GET_KEY, USER_DATA); \
  }                                                                                      \
  else {                                                                                 \
    PARALLEL_HYBRID64(HXTSORT_TYPE, ARRAY, _copyNb, _copyMax, GET_KEY, USER_DATA);       \
  }                                                                                      \
}while(0)


/* simply sort 3 values */
#define HXTSORT_3_VALUES_INPLACE(HXTSORT_TYPE, a)                             \
do {                                                                          \
  HXTSORT_TYPE* _copya = (a);                                                 \
  if(_copya[0]>_copya[1]){                                                    \
    HXTSORT_TYPE _tmp = _copya[0]; _copya[0] = _copya[1]; _copya[1] = _tmp;   \
  }                                                                           \
  if(_copya[1]>_copya[2]){                                                    \
    HXTSORT_TYPE _tmp = _copya[1]; _copya[1] = _copya[2]; _copya[2] = _tmp;   \
    if(_copya[0]>_copya[1]){                                                  \
      HXTSORT_TYPE _tmp = _copya[0]; _copya[0] = _copya[1]; _copya[1] = _tmp; \
    }                                                                         \
  }                                                                           \
} while(0)

/* simply sort 4 values */
#define HXTSORT_4_VALUES_INPLACE(HXTSORT_TYPE, a)                             \
do {                                                                          \
  HXTSORT_TYPE* _copya = (a);                                                 \
  if(_copya[0]>_copya[1]){                                                    \
    HXTSORT_TYPE _tmp = _copya[0]; _copya[0] = _copya[1]; _copya[1] = _tmp;   \
  }                                                                           \
  if(_copya[2]>_copya[3]){                                                    \
    HXTSORT_TYPE _tmp = _copya[2]; _copya[2] = _copya[3]; _copya[3] = _tmp;   \
  }                                                                           \
  if(_copya[0]>_copya[2]){                                                    \
    HXTSORT_TYPE _tmp = _copya[0]; _copya[0] = _copya[2]; _copya[2] = _tmp;   \
  }                                                                           \
  if(_copya[1]>_copya[3]){                                                    \
    HXTSORT_TYPE _tmp = _copya[1]; _copya[1] = _copya[3]; _copya[3] = _tmp;   \
  }                                                                           \
  if(_copya[1]>_copya[2]){                                                    \
    HXTSORT_TYPE _tmp = _copya[1]; _copya[1] = _copya[2]; _copya[2] = _tmp;   \
  }                                                                           \
} while(0)


/**************************************************************************************
 * To use pragma in a macro      *
 *************************************************************************************/
#if defined(_MSC_VER) && !defined(__clang__)
#define _HXTSORT_PRAGMA(x) __pragma (#x);
#define _HXTSORT_PRAGMA_ALIGNED(...)
#else
#define _HXTSORT_PRAGMA(x) _Pragma (#x)
#define _HXTSORT_PRAGMA_ALIGNED(...) _HXTSORT_PRAGMA(omp simd aligned(__VA_ARGS__:SIMD_ALIGN))
#endif


/**************************************************************************************
 * INSERTION SORT, common version for 32 and 64 bit                                   *
 * The best when there is less than ~ 128 elements                                    *
 *************************************************************************************/
#define INSERTION_SORT_COMMON(HXTSORT_TYPE, ARRAY, N, GET_KEY, USER_DATA, BASE)          \
do{                                                                                      \
                                                                                         \
  const uint64_t _copyN = (N);                                                           \
  HXTSORT_TYPE* _copyAr = (ARRAY);                                                       \
  const void* _userData = (USER_DATA);                                                   \
                                                                                         \
  uint ## BASE ## _t (*_getKey)(HXTSORT_TYPE*, const void*)=GET_KEY; /*verify prototype*/\
  if(0) {_getKey(_copyAr, _userData);} /* this is just to suppress warning... */         \
                                                                                         \
  for (uint64_t r=1; r<_copyN; r++)                                                      \
  {                                                                                      \
    uint ## BASE ## _t a = GET_KEY(&_copyAr[r], _userData);                              \
    if(a < GET_KEY(&_copyAr[r-1], _userData)){                                           \
      HXTSORT_TYPE tmp = _copyAr[r];                                                     \
      _copyAr[r] = _copyAr[r-1];                                                         \
                                                                                         \
      uint64_t l;                                                                        \
      for (l=r-1; l>0 && GET_KEY(_copyAr + l-1, _userData)>a; l--){                      \
        _copyAr[l] = _copyAr[l-1];                                                       \
      }                                                                                  \
      _copyAr[l] = tmp;                                                                  \
    }                                                                                    \
  }                                                                                      \
}while(0)

#define INSERTION_SORT32(HXTSORT_TYPE, ARRAY, N, GET_KEY, USER_DATA)                     \
INSERTION_SORT_COMMON(HXTSORT_TYPE, ARRAY, N, GET_KEY, USER_DATA, 32)

#define INSERTION_SORT64(HXTSORT_TYPE, ARRAY, N, GET_KEY, USER_DATA)                     \
INSERTION_SORT_COMMON(HXTSORT_TYPE, ARRAY, N, GET_KEY, USER_DATA, 64)


/* simple exclusive scan over an array HIST of length N */
#define _HXTSORT_EXCLUSIVE_SCAN(HIST, N)                                                 \
{                                                                                        \
    uint64_t sum = 0;                                                                    \
    for (unsigned i=0; i<N; i++){                                                        \
      uint64_t tsum = sum + HIST[i];                                                     \
      HIST[i] = sum;                                                                     \
      sum = tsum;                                                                        \
    }                                                                                    \
}

/**************************************************************************************
 * LSB SORT, common version for 32 and 64 bit                                         *
 * The best when starting an OpenMP parallel region and dividing data accross caches  *
 * Usually when there is less than ~ 50,000 elements                                  *
 *************************************************************************************/
#define LSB_COMMON(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA, BASE)                \
do{                                                                                      \
  const unsigned _numpass = u ## BASE ## _log2(MAX)/8 + 1;                               \
  const uint64_t _copyN = (N);                                                           \
  const void* _userData = (USER_DATA);                                                   \
                                                                                         \
  HXTSORT_TYPE* _copyAr1 = (ARRAY);                                                      \
  HXTSORT_TYPE* _copyAr2;                                                                \
  HXT_CHECK( hxtAlignedMalloc(&_copyAr2, _copyN*sizeof(HXTSORT_TYPE)) );                 \
                                                                                         \
  uint ## BASE ## _t (*_getKey)(HXTSORT_TYPE*, const void*)=GET_KEY; /*verify prototype*/\
  if(0) {_getKey(_copyAr1, _userData);} /* this is just to suppress warning... */        \
                                                                                         \
                                                                                         \
  for (unsigned pass=0; pass<_numpass; pass++)                                           \
  {                                                                                      \
    uint64_t hist[256] = {0};                                                            \
    unsigned shift = pass*8;                                                             \
                                                                                         \
    /* computing histogram */                                                            \
    for (uint64_t i=0; i<_copyN; i++)                                                    \
      hist[(GET_KEY(_copyAr1+i, _userData) >> shift) & 255]++;                           \
                                                                                         \
    /* exclusive scan (in place) */                                                      \
    _HXTSORT_EXCLUSIVE_SCAN(hist, 256)                                                   \
    /* copy _copyAr1 to the righ index in _copyAr2 */                                    \
    for (uint64_t i=0; i<_copyN; i++)                                                    \
      _copyAr2[hist[(GET_KEY(_copyAr1+i, _userData)>> shift)&255]++]=_copyAr1[i];        \
                                                                                         \
    /* swap _copyAr1 and _copyAr2 */                                                     \
    HXTSORT_TYPE* tmp = _copyAr1;                                                        \
    _copyAr1 = _copyAr2;                                                                 \
    _copyAr2 = tmp;                                                                      \
  }                                                                                      \
                                                                                         \
  if(_numpass&1){                                                                        \
    memcpy(_copyAr2, _copyAr1, _copyN*sizeof(HXTSORT_TYPE));                             \
    HXT_CHECK( hxtAlignedFree(&_copyAr1) );                                              \
  }                                                                                      \
  else                                                                                   \
    HXT_CHECK( hxtAlignedFree(&_copyAr2) );                                              \
}while(0)

#define LSB32(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)                           \
LSB_COMMON(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA, 32)

#define LSB64(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)                           \
LSB_COMMON(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA, 64)


/**************************************************************************************
 * PARALLEL LSB SORT, common version for 32 and 64 bit                                *
 * /!\ Use when there would be bad load balancing with hybrid sort.                   *
 * i.e. When dividing the domain into 2048 bucket, each element of the array falling  *
 * into one bucket, each bucket does not contain the same nbr. of element at all.     *
 *************************************************************************************/
#define PARALLEL_LSB_COMMON(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA, BASE)       \
do{                                                                                      \
  const unsigned _numpass = u ## BASE ## _log2(MAX)/11 + 1;                              \
  const uint64_t _copyN = (N);                                                           \
  const void* _userData = (USER_DATA);                                                   \
                                                                                         \
  HXTSORT_TYPE* _copyAr1 = (ARRAY);                                                      \
  HXTSORT_TYPE* _copyAr2;                                                                \
  HXT_CHECK( hxtAlignedMalloc(&_copyAr2, _copyN*sizeof(HXTSORT_TYPE)) );                 \
                                                                                         \
  uint ## BASE ## _t (*_getKey)(HXTSORT_TYPE*, const void*)=GET_KEY; /*verify prototype*/\
  if(0) {_getKey(_copyAr1, _userData);} /* this is just to suppress warning... */        \
                                                                                         \
  int nthreads = _copyN/8192 + 1;                                                        \
  nthreads = nthreads>omp_get_max_threads()?omp_get_max_threads():nthreads;              \
  uint64_t* h_all, *h_tot;                                                               \
  HXT_CHECK( hxtAlignedMalloc(&h_all, 2048*(nthreads+1)*sizeof(uint64_t)) );             \
                                                                                         \
  _HXTSORT_PRAGMA(omp parallel num_threads(nthreads))                                    \
  {                                                                                      \
    _HXTSORT_PRAGMA(omp single)                                                          \
    {                                                                                    \
      nthreads = omp_get_num_threads(); /* the real number of threads */                 \
      h_tot = h_all + 2048*nthreads;                                                     \
                                                                                         \
      /* not necessary but avoid reading uninitialized memory */                         \
      memset(h_tot, 0, 2048*sizeof(uint64_t));                                           \
    }                                                                                    \
                                                                                         \
    uint64_t* h_this = h_all + 2048*omp_get_thread_num();                                \
                                                                                         \
    for (unsigned pass=0; pass<_numpass; pass++)                                         \
    {                                                                                    \
      memset(h_this, 0, 2048*sizeof(uint64_t));                                          \
      unsigned shift = pass*11;                                                          \
                                                                                         \
      /* computing histogram */                                                          \
      _HXTSORT_PRAGMA(omp for schedule(static))                                          \
      for (uint64_t i=0; i<_copyN; i++)                                                  \
        h_this[(GET_KEY(_copyAr1+i, _userData) >> shift) & 2047]++;                      \
                                                                                         \
      _HXTSORT_PRAGMA(omp for schedule(static))                                          \
      for (unsigned i=0; i<2048; i++){                                                   \
        uint64_t sum = 0;                                                                \
        for (int j=0; j<nthreads+1; j++)                                                 \
        {                                                                                \
          uint64_t tsum = h_all[j*2048 + i] + sum;                                       \
          h_all[j*2048 + i] = sum;                                                       \
          sum = tsum;                                                                    \
        }                                                                                \
      }                                                                                  \
                                                                                         \
      /* exclusive scan (in place) */                                                    \
      _HXTSORT_PRAGMA(omp single)                                                        \
      _HXTSORT_EXCLUSIVE_SCAN(h_tot, 2048)                                               \
                                                                                         \
      /* now every thread may calculate all it's starting indexes */                     \
      _HXTSORT_PRAGMA_ALIGNED(h_this, h_tot)                                             \
      for (unsigned i=0; i<2048; i++)                                                    \
        h_this[i] += h_tot[i];                                                           \
                                                                                         \
      /* copy values to the righ index */                                                \
      _HXTSORT_PRAGMA(omp for schedule(static))                                          \
      for (uint64_t i=0; i<_copyN; i++){                                                 \
        uint64_t index = (GET_KEY(_copyAr1+i,_userData) >> shift)&2047;                  \
        _copyAr2[h_this[index]++] = _copyAr1[i];                                         \
      }                                                                                  \
                                                                                         \
      _HXTSORT_PRAGMA(omp single)                                                        \
      {                                                                                  \
        /* swap _copyAr1 and _copyAr2 */                                                 \
        HXTSORT_TYPE* tmp = _copyAr1;                                                    \
        _copyAr1 = _copyAr2;                                                             \
        _copyAr2 = tmp;                                                                  \
      } /* implicit barrier here :-) */                                                  \
                                                                                         \
    }                                                                                    \
  }                                                                                      \
                                                                                         \
  if(_numpass&1){                                                                        \
    memcpy(_copyAr2, _copyAr1, _copyN*sizeof(HXTSORT_TYPE));                             \
    HXT_CHECK( hxtAlignedFree(&_copyAr1) );                                              \
  }                                                                                      \
  else                                                                                   \
    HXT_CHECK( hxtAlignedFree(&_copyAr2) );                                              \
}while(0)



#define PARALLEL_LSB32(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)                  \
PARALLEL_LSB_COMMON(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA, 32)

#define PARALLEL_LSB64(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)                  \
PARALLEL_LSB_COMMON(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA, 64)


/**************************************************************************************
 * PARALLEL HYBRID SORT, 32-bit        (use vectorisation to do 3 LSB passes at once) *
 * 1 MSB pass for better spatial locality, then 3 LSB passes at once                  *
 * /!\ Use when there would be goad load balancing with hybrid sort.                  *
 * i.e. When dividing the domain into 2048 bucket, each element of the array falling  *
 * into one bucket, each bucket contain approximately the same nbr. of element        *
 *************************************************************************************/
#define PARALLEL_HYBRID32(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)               \
do{                                                                                      \
  const uint64_t _copyN = (N);                                                           \
  unsigned _shift = u32_log2(MAX);                                                       \
  _shift = (_shift<11)?0:_shift-10;                                                      \
  const void* _userData = (USER_DATA);                                                   \
                                                                                         \
  HXTSORT_TYPE* _copyAr1 = (ARRAY);                                                      \
  HXTSORT_TYPE* _copyAr2;                                                                \
  HXT_CHECK( hxtAlignedMalloc(&_copyAr2, _copyN*sizeof(HXTSORT_TYPE)) );                 \
                                                                                         \
  uint32_t (*_getKey)(HXTSORT_TYPE*, const void*) = GET_KEY; /* verify prototype */      \
  if(0) {_getKey(_copyAr1, _userData);} /* this is just to suppress warning... */        \
                                                                                         \
  int nthreads = _copyN/8192 + 1;                                                        \
  nthreads = nthreads>omp_get_max_threads()?omp_get_max_threads():nthreads;              \
  uint64_t* h_all, *h_tot;                                                               \
  HXT_CHECK( hxtAlignedMalloc(&h_all, (2048*(nthreads+1)+1)*sizeof(uint64_t)) );         \
                                                                                         \
  _HXTSORT_PRAGMA(omp parallel num_threads(nthreads))                                    \
  {                                                                                      \
    _HXTSORT_PRAGMA(omp single)                                                          \
    {                                                                                    \
      nthreads = omp_get_num_threads(); /* the real number of threads */                 \
      memset(h_all, 0, (2048*(nthreads+1)+1)*sizeof(uint64_t));                          \
      h_tot = h_all + 2048*nthreads;                                                     \
      h_tot[2048] = _copyN;                                                              \
    }                                                                                    \
                                                                                         \
    uint64_t* h_this = h_all + omp_get_thread_num()*2048;                                \
                                                                                         \
    /* computing histogram */                                                            \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (uint64_t i=0; i<_copyN; i++)                                                    \
      h_this[GET_KEY(_copyAr1+i, _userData) >> _shift]++;                                \
                                                                                         \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (unsigned i=0; i<2048; i++){                                                     \
      uint64_t sum = 0;                                                                  \
      for (int j=0; j<nthreads+1; j++){                                                  \
        uint64_t tsum = h_all[j*2048 + i] + sum;                                         \
        h_all[j*2048 + i] = sum;                                                         \
        sum = tsum;                                                                      \
      }                                                                                  \
    }                                                                                    \
                                                                                         \
    /* exclusive scan (in place)*/                                                       \
    _HXTSORT_PRAGMA(omp single)                                                          \
    _HXTSORT_EXCLUSIVE_SCAN(h_tot, 2048)                                                 \
                                                                                         \
    /* now every thread may calculate all it's starting indexes*/                        \
    _HXTSORT_PRAGMA_ALIGNED(h_this, h_tot)                                               \
    for (unsigned i=0; i<2048; i++)                                                      \
      h_this[i] += h_tot[i];                                                             \
                                                                                         \
    /* copy _copyAr1 to the righ index*/                                                 \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (uint64_t i=0; i<_copyN; i++)                                                    \
      _copyAr2[h_this[GET_KEY(_copyAr1+i, _userData)>>_shift]++]=_copyAr1[i];            \
                                                                                         \
    /* recursion on each part of the histogram in parallel*/                             \
    _HXTSORT_PRAGMA(omp for schedule(dynamic))                                           \
    for (unsigned i=0; i<2048; i++){                                                     \
      uint64_t start = h_tot[i];                                                         \
      uint64_t n = h_tot[i+1] - start;                                                   \
                                                                                         \
      HXTSORT_TYPE* array1 = _copyAr2+start;                                             \
      HXTSORT_TYPE* array2 = _copyAr1+start;                                             \
                                                                                         \
      /* these are all the other passes at once */                                       \
      memset(h_this, 0, 384*sizeof(uint64_t));                                           \
      uint64_t* hist0 = h_this;                                                          \
      uint64_t* hist1 = hist0 + 128;                                                     \
      uint64_t* hist2 = hist1 + 128;                                                     \
                                                                                         \
      /* computing histogram*/                                                           \
      for (uint64_t j=0; j<n; j++){                                                      \
        uint64_t val = GET_KEY(array1+j, _userData);                                     \
        hist0[val & 127]++;                                                              \
        hist1[(val >> 7) & 127]++;                                                       \
        hist2[(val >> 14) & 127]++;                                                      \
      }                                                                                  \
                                                                                         \
      /* exclusive scan (in place)*/                                                     \
      uint64_t sum0 = 0, sum1 = 0, sum2 = 0;                                             \
      for (unsigned j=0; j<128; j++){                                                    \
        uint64_t tsum = sum0 + hist0[j];                                                 \
        hist0[j] = sum0;                                                                 \
        sum0 = tsum;                                                                     \
                                                                                         \
        tsum = sum1 + hist1[j];                                                          \
        hist1[j] = sum1;                                                                 \
        sum1 = tsum;                                                                     \
                                                                                         \
        tsum = sum2 + hist2[j];                                                          \
        hist2[j] = sum2;                                                                 \
        sum2 = tsum;                                                                     \
      }                                                                                  \
                                                                                         \
      /* copy array1 to the righ index*/                                                 \
      for (uint64_t j=0; j<n; j++)                                                       \
        array2[hist0[GET_KEY(array1 + j, _userData) & 127]++] = array1[j];               \
                                                                                         \
      for (uint64_t j=0; j<n; j++)                                                       \
        array1[hist1[(GET_KEY(array2 + j, _userData) >> 7) & 127]++] = array2[j];        \
                                                                                         \
      for (uint64_t j=0; j<n; j++)                                                       \
        array2[hist2[(GET_KEY(array1 + j, _userData) >> 14) & 127]++] = array1[j];       \
    }                                                                                    \
  }                                                                                      \
                                                                                         \
  HXT_CHECK( hxtAlignedFree(&h_all) );                                                   \
  HXT_CHECK( hxtAlignedFree(&_copyAr2) );                                                \
}while(0)



/**************************************************************************************
 * PARALLEL HYBRID SORT, 64-bit       (use vectorisation but always use 7 LSB passes) *
 * 1 MSB pass for better spatial locality, then 7 LSB passes at once                  *
 * /!\ Use when there would be goad load balancing with hybrid sort.                  *
 * i.e. When dividing the domain into 2048 bucket, each element of the array falling  *
 * into one bucket, each bucket contain approximately the same nbr. of element        *
 *************************************************************************************/
#define PARALLEL_HYBRID64(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)               \
do{                                                                                      \
  const uint64_t _copyN = (N);                                                           \
  unsigned _shift = u64_log2(MAX);                                                       \
  _shift = (_shift<11)?0:_shift-10;                                                      \
  const void* _userData = (USER_DATA);                                                   \
                                                                                         \
  HXTSORT_TYPE* _copyAr1 = (ARRAY);                                                      \
  HXTSORT_TYPE* _copyAr2;                                                                \
  HXT_CHECK( hxtAlignedMalloc(&_copyAr2, _copyN*sizeof(HXTSORT_TYPE)) );                 \
                                                                                         \
  uint64_t (*_getKey)(HXTSORT_TYPE*, const void*) = GET_KEY; /* verify prototype */      \
  if(0) {_getKey(_copyAr1, _userData);} /* this is just to suppress warning... */        \
                                                                                         \
  int nthreads = _copyN/8192 + 1;                                                        \
  nthreads = nthreads>omp_get_max_threads()?omp_get_max_threads():nthreads;              \
  uint64_t* h_all, *h_tot;                                                               \
  HXT_CHECK( hxtAlignedMalloc(&h_all, (2048*(nthreads+1)+1)*sizeof(uint64_t)) );         \
                                                                                         \
  _HXTSORT_PRAGMA(omp parallel num_threads(nthreads))                                    \
  {                                                                                      \
    _HXTSORT_PRAGMA(omp single)                                                          \
    {                                                                                    \
      nthreads = omp_get_num_threads();                                                  \
      memset(h_all, 0, (2048*(nthreads+1)+1)*sizeof(uint64_t));                          \
      h_tot = h_all + 2048*nthreads;                                                     \
      h_tot[2048] = _copyN;                                                              \
    }                                                                                    \
                                                                                         \
    uint64_t* h_this = h_all + omp_get_thread_num()*2048;                                \
                                                                                         \
    /* computing histogram */                                                            \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (uint64_t i=0; i<_copyN; i++)                                                    \
      h_this[GET_KEY(_copyAr1+i, _userData) >> _shift]++;                                \
                                                                                         \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (unsigned i=0; i<2048; i++){                                                     \
      uint64_t sum = 0;                                                                  \
      for (int j=0; j<nthreads+1; j++){                                                  \
        uint64_t tsum = h_all[j*2048 + i] + sum;                                         \
        h_all[j*2048 + i] = sum;                                                         \
        sum = tsum;                                                                      \
      }                                                                                  \
    }                                                                                    \
                                                                                         \
    /* exclusive scan (in place)*/                                                       \
    _HXTSORT_PRAGMA(omp single)                                                          \
    _HXTSORT_EXCLUSIVE_SCAN(h_tot, 2048)                                                 \
                                                                                         \
    /* now every thread may calculate all it's starting indexes*/                        \
    _HXTSORT_PRAGMA_ALIGNED(h_this, h_tot)                                               \
    for (unsigned i=0; i<2048; i++)                                                      \
      h_this[i] += h_tot[i];                                                             \
                                                                                         \
    /* copy _copyAr1 to the righ index*/                                                 \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (uint64_t i=0; i<_copyN; i++)                                                    \
      _copyAr2[h_this[GET_KEY(_copyAr1+i, _userData)>>_shift]++]=_copyAr1[i];            \
                                                                                         \
    /* recursion on each part of the histogram in parallel*/                             \
    _HXTSORT_PRAGMA(omp for schedule(dynamic))                                           \
    for (unsigned i=0; i<2048; i++){                                                     \
      uint64_t start = h_tot[i];                                                         \
      uint64_t n = h_tot[i+1] - start;                                                   \
                                                                                         \
      HXTSORT_TYPE* array1 = _copyAr2+start;                                             \
      HXTSORT_TYPE* array2 = _copyAr1+start;                                             \
      memset(h_this, 0, 2048*sizeof(uint64_t));                                          \
                                                                                         \
      /* computing histogram   */                                                        \
      for (uint64_t j=0; j<n; j++){                                                      \
        uint64_t key = GET_KEY(array1+j, _userData);                                     \
        _HXTSORT_PRAGMA_ALIGNED(h_this)                                                  \
        for (unsigned k=0; k<7; k++)                                                     \
          h_this[((key >> k*8) & 255)+k*256]++;                                          \
      }                                                                                  \
                                                                                         \
      /* exclusive scan (in place)*/                                                     \
      uint64_t hxtDeclareAligned sum[7] = {0};                                           \
      for (unsigned j=0; j<256; j++){                                                    \
        _HXTSORT_PRAGMA_ALIGNED(h_this)                                                  \
        for (unsigned k=0; k<7; k++)                                                     \
        {                                                                                \
          uint64_t tsum = sum[k] + h_this[j+k*256];                                      \
          h_this[j+k*256] = sum[k];                                                      \
          sum[k] = tsum;                                                                 \
        }                                                                                \
      }                                                                                  \
                                                                                         \
      /* copy array1 to the righ index */                                                \
      for (unsigned k=0; k<7; k++){                                                      \
        for (uint64_t j=0; j<n/256; j++){                                                \
                                                                                         \
          uint64_t* key = h_this + 7*256;                                                \
          for (unsigned l=0; l<256; l++) {                                               \
            key[l] = GET_KEY(array1+256*j+l,_userData);                                  \
          }                                                                              \
                                                                                         \
          _HXTSORT_PRAGMA_ALIGNED(key)                                                   \
          for (unsigned l=0; l<256; l++) {                                               \
            key[l] = ((key[l] >> k*8) & 255) + k*256;                                    \
          }                                                                              \
                                                                                         \
          for (unsigned l=0; l<256; l++) {                                               \
            array2[h_this[key[l]]++] = array1[256*j+l];                                  \
          }                                                                              \
        }                                                                                \
                                                                                         \
        /* remainder loop */                                                             \
        for (uint64_t j=0; j<n%256; j++) {                                               \
          uint64_t key = GET_KEY(array1+256*(n/256)+j,_userData);                        \
          array2[h_this[((key >> k*8) & 255) + k*256]++] = array1[256*(n/256)+j];        \
        }                                                                                \
        HXTSORT_TYPE* tmp = array1; array1 = array2; array2 = tmp;                       \
      }                                                                                  \
    }                                                                                    \
  }                                                                                      \
                                                                                         \
  HXT_CHECK( hxtAlignedFree(&h_all) );                                                   \
  HXT_CHECK( hxtAlignedFree(&_copyAr2) );                                                \
}while(0)


/**************************************************************************************
 * PARALLEL HYBRID SORT, 64-bit (adapt the number of iteration to the number of bits) *
 * 1 MSB pass for better spatial locality, then just enough LSB passes to sort all    *
 * /!\ Use when there would be goad load balancing with hybrid sort.                  *
 * i.e. When dividing the domain into 2048 bucket, each element of the array falling  *
 * into one bucket, each bucket contain approximately the same nbr. of element        *
 *************************************************************************************/
#define PARALLEL_HYBRID64_ADAPT(HXTSORT_TYPE, ARRAY, N, MAX, GET_KEY, USER_DATA)         \
do{                                                                                      \
  const uint64_t _copyN = (N);                                                           \
  unsigned _shift = u64_log2(MAX);                                                       \
  _shift = (_shift<11)?0:_shift-10;                                                      \
  const void* _userData = (USER_DATA);                                                   \
                                                                                         \
  HXTSORT_TYPE* _copyAr1 = (ARRAY);                                                      \
  HXTSORT_TYPE* _copyAr2;                                                                \
  HXT_CHECK( hxtAlignedMalloc(&_copyAr2, _copyN*sizeof(HXTSORT_TYPE)) );                 \
                                                                                         \
  uint64_t (*_getKey)(HXTSORT_TYPE*, const void*) = GET_KEY; /* verify prototype */      \
  if(0) {_getKey(_copyAr1, _userData);} /* this is just to suppress warning... */        \
                                                                                         \
  int nthreads = _copyN/8192 + 1;                                                        \
  nthreads = nthreads>omp_get_max_threads()?omp_get_max_threads():nthreads;              \
  uint64_t* h_all, *h_tot;                                                               \
  HXT_CHECK( hxtAlignedMalloc(&h_all, (2048*(nthreads+1)+1)*sizeof(uint64_t)) );         \
                                                                                         \
  _HXTSORT_PRAGMA(omp parallel num_threads(nthreads))                                    \
  {                                                                                      \
    _HXTSORT_PRAGMA(omp single)                                                          \
    {                                                                                    \
      nthreads = omp_get_num_threads();                                                  \
      memset(h_all, 0, (2048*(nthreads+1)+1)*sizeof(uint64_t));                          \
      h_tot = h_all + 2048*nthreads;                                                     \
      h_tot[2048] = _copyN;                                                              \
    }                                                                                    \
                                                                                         \
    uint64_t* h_this = h_all + omp_get_thread_num()*2048;                                \
                                                                                         \
    /* computing histogram */                                                            \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (uint64_t i=0; i<_copyN; i++)                                                    \
      h_this[GET_KEY(_copyAr1+i, _userData) >> _shift]++;                                \
                                                                                         \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (unsigned i=0; i<2048; i++){                                                     \
      uint64_t sum = 0;                                                                  \
      for (int j=0; j<nthreads+1; j++){                                                  \
        uint64_t tsum = h_all[j*2048 + i] + sum;                                         \
        h_all[j*2048 + i] = sum;                                                         \
        sum = tsum;                                                                      \
      }                                                                                  \
    }                                                                                    \
                                                                                         \
    /* exclusive scan (in place)*/                                                       \
    _HXTSORT_PRAGMA(omp single)                                                          \
    _HXTSORT_EXCLUSIVE_SCAN(h_tot, 2048)                                                 \
                                                                                         \
    /* now every thread may calculate all it's starting indexes*/                        \
    _HXTSORT_PRAGMA_ALIGNED(h_this, h_tot)                                               \
    for (unsigned i=0; i<2048; i++)                                                      \
      h_this[i] += h_tot[i];                                                             \
                                                                                         \
    /* copy _copyAr1 to the righ index*/                                                 \
    _HXTSORT_PRAGMA(omp for schedule(static))                                            \
    for (uint64_t i=0; i<_copyN; i++)                                                    \
      _copyAr2[h_this[GET_KEY(_copyAr1+i, _userData)>>_shift]++]=_copyAr1[i];            \
                                                                                         \
    /* recursion on each part of the histogram in parallel*/                             \
    _HXTSORT_PRAGMA(omp for schedule(dynamic))                                           \
    for (unsigned i=0; i<2048; i++){                                                     \
      uint64_t start = h_tot[i];                                                         \
      uint64_t n = h_tot[i+1] - start;                                                   \
                                                                                         \
      HXTSORT_TYPE* array1 = _copyAr2+start;                                             \
      HXTSORT_TYPE* array2 = _copyAr1+start;                                             \
      const unsigned rsort_npass = (_shift + 10)/11;                                     \
      for (unsigned pass=0; pass<rsort_npass; pass++)                                    \
      {                                                                                  \
        memset(h_this, 0, 2048*sizeof(uint64_t));                                        \
                                                                                         \
        /* 1.  parallel histogramming pass */                                            \
        for (uint64_t j=0; j<n; j++)                                                     \
          h_this[(GET_KEY(array1+j, _userData) >> (11*pass)) & 2047]++;                  \
                                                                                         \
        /* 2.  Sum the histograms */                                                     \
        uint64_t sum = 0;                                                                \
        for (unsigned i=0; i<2048; i++) {                                                \
          uint64_t tsum = h_this[i] + sum;                                               \
          h_this[i] = sum; /* sum of the preceding, but not with itself !! */            \
          sum = tsum;                                                                    \
        }                                                                                \
                                                                                         \
        /* read/write histogram */                                                       \
        for(uint64_t j=0; j<n; j++)                                                      \
          array2[h_this[(GET_KEY(array1+j,_userData)>>(11*pass))&2047]++]=array1[j];     \
                                                                                         \
        HXTSORT_TYPE* tmp = array1; array1 = array2; array2 = tmp;                       \
      }                                                                                  \
    }                                                                                    \
  }                                                                                      \
                                                                                         \
  HXT_CHECK( hxtAlignedFree(&h_all) );                                                   \
                                                                                         \
  const unsigned rsort_totalPass = (_shift + 10)/11 + 1;                                 \
  if(rsort_totalPass&1)                                                                  \
    memcpy(_copyAr1, _copyAr2, _copyN*sizeof(HXTSORT_TYPE));                             \
  HXT_CHECK( hxtAlignedFree(&_copyAr2) );                                                \
}while(0)

#ifdef __cplusplus
}
#endif

#endif
