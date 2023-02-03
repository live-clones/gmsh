// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TOOLS_H
#define HXT_TOOLS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_message.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#ifndef M_PI
  #define M_PI 3.14159265358979323846264338327950
#endif // !M_PI

/* define SIMD ALIGNMENT */
#ifndef SIMD_ALIGN
#ifdef HXT_ALIGN_ALLOCATIONS
#define SIMD_ALIGN 64
#else
#define SIMD_ALIGN 16
#endif
#endif

// declare alignement of pointer allocated on the stack or in a struct
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1 // disable warning about unsafe sscanf, fopen etc.
#define hxtDeclareAligned   __declspec(align(SIMD_ALIGN))
#define hxtDeclareAligned32 __declspec(align(32))
#define hxtDeclareAligned64 __declspec(align(64))
#ifndef __restrict__
#define __restrict__ __restrict
#endif
#define HXTu64 "I64u"
#define HXTd64 "I64d"
#define HXTx64 "I64x"
#define HXT_LIKELY(exp)   exp
#define HXT_UNLIKELY(exp) exp
#define HXT_ASSUME(exp) __assume(exp)
#define HXT_ASSUME_ALIGNED(array, alignement) (__assume((((char*) array) - ((char*) 0)) % (alignement) == 0), (array))
#else
#include <inttypes.h>
#define hxtDeclareAligned   __attribute__((aligned(SIMD_ALIGN)))
#define hxtDeclareAligned32 __attribute__((aligned(32)))
#define hxtDeclareAligned64 __attribute__((aligned(64)))
#define HXTu64 PRIu64
#define HXTi64 PRId64
#define HXTx64 PRIx64
#define HXT_LIKELY(exp)    __builtin_expect(!!(exp), 1)
#define HXT_UNLIKELY(exp)  __builtin_expect(!!(exp), 0)
#ifdef __GNUC__
#define __assume(exp) do { if (!(exp)) __builtin_unreachable(); } while (0)
#elif defined(__clang__)
#define __assume(exp) __builtin_assume(exp)
#elif !defined(__INTEL_COMPILER) || (__INTEL_COMPILER < 1300)
#define HXT_ASSUME(exp) __assume(exp)
#endif
#define HXT_ASSUME_ALIGNED(array, alignement) __builtin_assume_aligned(array, alignement)
#endif



#define HXT_UNUSED(x) (void)(x)  // portable way to avoid warning about unused variable

/*********************************************************
 * Hextreme malloc implementation
 *********************************************************/

/************************************************************************
  WARNING: the pointer passed (p) should be a double pointer !!

  use it like this:
___
|  int arrayLength = ...;
|  int *array;
|  HXT_CHECK( hxtMalloc(&array, sizeof(int)*arrayLength) );
|
|  array[0] = ...;
|  [...]
|  array[arrayLength-1] = ...;
|
|  [...]
|
|  HXT_CHECK( hxtFree(&array) );
|___
 ************************************************************************/

static inline HXTStatus hxtMalloc(void* ptrToPtr, size_t size)
{
  void** p = (void**)ptrToPtr;
  *p = malloc(size);
  if (*p==NULL)
    return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  return HXT_STATUS_OK;
}


// allocate num element of size size and zero the memory
static inline HXTStatus hxtCalloc(void* ptrToPtr, size_t num, size_t size)
{
  void** p = (void**)ptrToPtr;
  *p = calloc(num, size);
  if (*p==NULL)
    return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  return HXT_STATUS_OK;
}


static inline HXTStatus hxtFree(void* ptrToPtr)
{
  void** p = (void**)ptrToPtr;
  free(*p);
  *p=NULL;
  return HXT_STATUS_OK;
}


static inline HXTStatus hxtRealloc(void* ptrToPtr, size_t size)
{
  void** p = (void**)ptrToPtr;
  void* newptr = realloc(*p, size);
  if (newptr==NULL && *p!=NULL && size!=0)
    return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  *p = newptr;
  return HXT_STATUS_OK;
}


// HEXTREME aligned malloc implementation
#ifdef HXT_ALIGN_ALLOCATIONS
static inline HXTStatus hxtGetAlignedBlockSize(void* ptrToPtr, size_t* size)
{
  char** p2 = *(char***)(ptrToPtr);

  if(p2==NULL){
    *size = 0;
    return HXT_STATUS_OK;
  }

  *size = p2[-2]-p2[-1];

  if((*size^0x12345678u) != (size_t) (p2[-3]-p2[-1])){
    return HXT_ERROR(HXT_STATUS_POINTER_ERROR);
  }

  return HXT_STATUS_OK;
}

static inline HXTStatus hxtAlignedMalloc(void* ptrToPtr, size_t size)
{
  char** p2;
  char* pstart;
  // if p is a malloced address, p+3*sizeof(char*) is at least aligned on sizeof(char*) maximum shift is SIMD_ALIGN-sizeof(char*)
  const size_t startOffset = 3*sizeof(char*) + (SIMD_ALIGN - sizeof(char*)); // up to 80 bytes...

  const size_t safe_size = size + startOffset;
  if(safe_size<size) // account for possible overflow
    goto error;

  pstart = (char*) malloc(safe_size); // start of original block
  if(pstart==NULL)
    goto error;


  // if compilation fails on this line, it means we cannot cast a pointer to uintmax_t
  {
    int test_if_pointer_conversion_is_safe[(sizeof(uintmax_t) >= sizeof(void*)) ? 1 : -1];
    HXT_UNUSED(test_if_pointer_conversion_is_safe[0]);
  }

  p2 = (char**)(((uintmax_t)(pstart) + startOffset) & ~(SIMD_ALIGN - 1)); // only keep bits ge SIMD_ALIGN
  p2[-1] = pstart;
  p2[-2] = pstart + size;
  p2[-3] = pstart + (size ^ 0x12345678u); // makes a verification possible
  *(void**)ptrToPtr = p2;

  return HXT_STATUS_OK;

error:
  *(void**)ptrToPtr = NULL;
  return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
}


static inline HXTStatus hxtAlignedFree(void* ptrToPtr)
{
  void** p = (void**)ptrToPtr;

  if(*p!=NULL){
    char** p2 = (char**)(*p);
    if(((p2[-2]-p2[-1])^0x12345678u) != (p2[-3]-p2[-1]))
      return HXT_ERROR(HXT_STATUS_POINTER_ERROR);

    p2[-3] = NULL;
    free(p2[-1]);
    *p = NULL;
  }

  return HXT_STATUS_OK;
}


static inline HXTStatus hxtAlignedRealloc(void* ptrToPtr, size_t size)
{
  if (size == 0) {
    HXT_CHECK(hxtAlignedFree(ptrToPtr));
    return HXT_STATUS_OK;
  }

  size_t old_size;
  HXT_CHECK( hxtGetAlignedBlockSize(ptrToPtr, &old_size) );

  if(size>old_size || size+4096<old_size){ // we do not shrink block to gain less than 4096 bytes
    void* newptr = NULL;
    HXT_CHECK( hxtAlignedMalloc(&newptr, size));
    if(old_size)
      memcpy(newptr, *(void**)ptrToPtr, size>old_size?old_size:size);

    HXT_CHECK( hxtAlignedFree(ptrToPtr) );

    *(void**)ptrToPtr = newptr;
  }

  return HXT_STATUS_OK;
}

#else

#define hxtAlignedMalloc hxtMalloc
#define hxtAlignedFree hxtFree
#define hxtAlignedRealloc hxtRealloc

#endif


/*********************************************************
 Lehmer RNG with prime modulus 2^32−5
 Preferably seed with 1 first...
**********************************************************/
static inline uint32_t hxtLCGu32(uint32_t *state)
{
  return *state = (uint64_t)*state * 279470273u % 0xfffffffb;
}


/* return a double between 0 and 1, uniform distribution with 0 and 1 excluded
 * indeed, 0 cannot be returned by hxtLCGu32() and
 * `(double) 0xfffffffa * (1.0 / 4294967296.0)` < 1 */
static inline double hxtLCGf64(uint32_t *state)
{
  return (double) hxtLCGu32(state) * (1.0 / 4294967296.0);
}


/* good hash function for non-cryptographic purpose, 64 bits
 * from https://stackoverflow.com/a/12996028, posted by Thomas Mueller */
static inline uint64_t hash64(uint64_t x) {
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    return x ^ (x >> 31);
}

/* good hash function for non-cryptographic purpose, 32 bits
 * from https://stackoverflow.com/a/12996028, posted by Thomas Mueller */
static inline uint32_t hash32(uint32_t x) {
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  return (x >> 16) ^ x;
}

#ifdef __cplusplus
}
#endif


#endif
