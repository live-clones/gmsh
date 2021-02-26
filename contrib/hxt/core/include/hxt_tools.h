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
  A way to call rand with a seed to get a reproducible
  result.
  For example, we do not call srand() each time we
  call a reproducible Delaunay, else if someone was calling
  rand(); Delaunay(); rand(); ...
  he would always get the same result. We use
  hxtReproducibleRand() instead

  !!!! 1st seed must absolutely be 1 !!!!
**********************************************************/
static inline uint32_t hxtReproducibleLCG(uint32_t *seed)
{
  *seed = 69621*(*seed)%2147483647;
  return *seed;
}

static HXTStatus hxtNorm2V(double *v, int size, double* norm2){
  *norm2=0.0;
  for(int i=0; i<size; i++)
    *norm2+=v[i]*v[i];
  *norm2 = sqrt(*norm2);
  return HXT_STATUS_OK;
}

static HXTStatus hxtNorm2V3(double v[3], double* norm2){
  *norm2 = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
  return HXT_STATUS_OK;
}

static HXTStatus hxtNormalizeV(double *v, int size){
  double norm=0.0;
  hxtNorm2V(v,size,&norm);
  for(int i=0; i<size; i++)
    v[i] /= norm;
  return HXT_STATUS_OK;
}

static HXTStatus hxtNormalizeV3(double v[3]){
  double norm=0.0;
  hxtNorm2V3(v,&norm);
  v[0] /= norm;
  v[1] /= norm;
  v[2] /= norm;
  return HXT_STATUS_OK;
}

static HXTStatus hxtCrossProductV3(const double a[3], const double b[3], double res[3]){
  res[0] = a[1]*b[2] - a[2]*b[1];
  res[1] = a[2]*b[0] - a[0]*b[2];
  res[2] = a[0]*b[1] - a[1]*b[0];
  return HXT_STATUS_OK;
}

static HXTStatus hxtDet2x2(double mat[2][2], double* det){
  *det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
  return HXT_STATUS_OK;
}

static HXTStatus hxtInv2x2(double mat[2][2], double inv[2][2], double *det){
  hxtDet2x2(mat,det);
  if(*det) {
    const double ud = 1. / *det;
    inv[0][0] =  mat[1][1] * ud;
    inv[0][1] = -mat[0][1] * ud;
    inv[1][0] = -mat[1][0] * ud;
    inv[1][1] =  mat[0][0] * ud;
  } else {
    return HXT_STATUS_ERROR;
  }
  return HXT_STATUS_OK;
}

static HXTStatus hxtDet3x3(double mat[3][3], double *det)
{
  *det = (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
          mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
          mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]));
  return HXT_STATUS_OK;
}

static HXTStatus hxtInv3x3(double mat[3][3], double inv[3][3], double *det)
{
  HXT_CHECK(hxtDet3x3(mat, det));
  if(*det){
    double ud = 1. / *det;
    inv[0][0] =  (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * ud;
    inv[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) * ud;
    inv[2][0] =  (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * ud;
    inv[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) * ud;
    inv[1][1] =  (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * ud;
    inv[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) * ud;
    inv[0][2] =  (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * ud;
    inv[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) * ud;
    inv[2][2] =  (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * ud;
    return HXT_STATUS_OK;
  }
  else{
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        inv[i][j] = 0.;
    return HXT_ERROR_MSG(HXT_STATUS_FAILED, "Singular matrix 3x3");
  }
}

// static HXTStatus hxtInv4x4ColumnMajor(double m[16], double invOut[16], double *det)
// {
//   double inv[16];
//   int i;
  
//   inv[ 0] =  m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
//   inv[ 4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
//   inv[ 8] =  m[4] * m[ 9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[ 9];
//   inv[12] = -m[4] * m[ 9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[ 9];
//   inv[ 1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
//   inv[ 5] =  m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
//   inv[ 9] = -m[0] * m[ 9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[ 9];
//   inv[13] =  m[0] * m[ 9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[ 9];
//   inv[ 2] =  m[1] * m[ 6] * m[15] - m[1] * m[ 7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[ 7] - m[13] * m[3] * m[ 6];
//   inv[ 6] = -m[0] * m[ 6] * m[15] + m[0] * m[ 7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[ 7] + m[12] * m[3] * m[ 6];
//   inv[10] =  m[0] * m[ 5] * m[15] - m[0] * m[ 7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[ 7] - m[12] * m[3] * m[ 5];
//   inv[14] = -m[0] * m[ 5] * m[14] + m[0] * m[ 6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[ 6] + m[12] * m[2] * m[ 5];
//   inv[ 3] = -m[1] * m[ 6] * m[11] + m[1] * m[ 7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[ 9] * m[2] * m[ 7] + m[ 9] * m[3] * m[ 6];
//   inv[ 7] =  m[0] * m[ 6] * m[11] - m[0] * m[ 7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[ 8] * m[2] * m[ 7] - m[ 8] * m[3] * m[ 6];
//   inv[11] = -m[0] * m[ 5] * m[11] + m[0] * m[ 7] * m[ 9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[ 9] - m[ 8] * m[1] * m[ 7] + m[ 8] * m[3] * m[ 5];
//   inv[15] =  m[0] * m[ 5] * m[10] - m[0] * m[ 6] * m[ 9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[ 9] + m[ 8] * m[1] * m[ 6] - m[ 8] * m[2] * m[ 5];
  
//   *det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
  
//   if(*det == 0)
//     return HXT_STATUS_ERROR;
    
//   double invDet = 1.0 / *det;
  
//   for(i = 0; i < 16; i++)
//     invOut[i] = inv[i] * invDet;
  
//   return HXT_STATUS_OK;
// }

static HXTStatus hxtJacobianLinTet(double *x , double *y, double *z , double mat[3][3]){
  mat[0][0] = x[1] - x[0];
  mat[0][1] = x[2] - x[0];
  mat[0][2] = x[3] - x[0];
  mat[1][0] = y[1] - y[0];
  mat[1][1] = y[2] - y[0];
  mat[1][2] = y[3] - y[0];
  mat[2][0] = z[1] - z[0];
  mat[2][1] = z[2] - z[0];
  mat[2][2] = z[3] - z[0];  
  return HXT_STATUS_OK;
}

#ifdef __cplusplus
}
#endif


#endif
