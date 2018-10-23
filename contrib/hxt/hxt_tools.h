#ifndef HXT_TOOLS_H
#define HXT_TOOLS_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hxt_message.h" // already include hxt_api (for HXT_status_t)


/* define SIMD ALIGNMENT */
#ifndef SIMD_ALIGN
#define SIMD_ALIGN 64
#endif

// declare alignement of pointer allocated on the stack or in a struct
#ifdef _MSC_VER
#define hxtDeclareAligned  __declspec(align(SIMD_ALIGN))
#ifndef __restrict__
#define __restrict__ __restrict
#endif
#else
#define hxtDeclareAligned  __attribute__((aligned(SIMD_ALIGN)))
#endif


#if !defined(__INTEL_COMPILER) || (__INTEL_COMPILER < 1300)
#define __assume(x)
#define __assume_aligned(x,y)
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


// FIXME Gmsh: aligned routines do not seem to work on 32 bit machines
#include <stdint.h>

#if UINTPTR_MAX == 0xffffffff

static inline HXTStatus hxtGetAlignedBlockSize(void* ptrToPtr, size_t* size){
  *size = 0; return HXT_STATUS_OK;
}

static inline HXTStatus hxtAlignedMalloc(void* ptrToPtr, size_t size){
  return hxtMalloc(ptrToPtr, size);
}

static inline HXTStatus hxtAlignedFree(void* ptrToPtr){
  return hxtFree(ptrToPtr);
}

static inline HXTStatus hxtAlignedRealloc(void* ptrToPtr, size_t size){
  return hxtRealloc(ptrToPtr, size);
}

#elif defined ( HAVE_MSDN_ALIGNED_MALLOC ) // microsoft implementation

#include <malloc.h>
#include <errno.h>

static inline HXTStatus hxtAlignedMalloc(void* ptrToPtr, size_t size) {
  void** p = (void**)ptrToPtr;
  *p = _aligned_malloc(size, SIMD_ALIGN);
  if ((*p == NULL && size!=0) || errno == ENOMEM)
    return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  return HXT_STATUS_OK;
}

static inline HXTStatus hxtAlignedFree(void* ptrToPtr)
{
  void** p = (void**)ptrToPtr;
  _aligned_free(*p);
  *p = NULL;
  return HXT_STATUS_OK;
}

static inline HXTStatus hxtAlignedRealloc(void* ptrToPtr, size_t size)
{
  void** p = (void**)ptrToPtr;
  void* newptr = _aligned_realloc(*p, size, SIMD_ALIGN);
  if ((newptr == NULL && *p != NULL && size != 0) || (size!=0 && errno == ENOMEM)) {
    if (errno == ENOMEM)
      HXT_INFO("it was errno");
    return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  }
  *p = newptr;
  return HXT_STATUS_OK;
}

#else  // HEXTREME aligned malloc implementation

static inline HXTStatus hxtGetAlignedBlockSize(void* ptrToPtr, size_t* size)
{
  char** p2 = *(char***)(ptrToPtr);

  if(p2==NULL){
    *size = 0;
    return HXT_STATUS_OK;
  }

  *size = p2[-2]-p2[-1];

  if((*size^0xBF58476D1CE4E5B9ULL) != ((size_t)p2[-3]-(size_t)p2[-1])){
    return HXT_ERROR(HXT_STATUS_POINTER_ERROR);
  }

  return HXT_STATUS_OK;
}

static inline HXTStatus hxtAlignedMalloc(void* ptrToPtr, size_t size)
{
  char** p2;
  char* pstart;
  // malloc is at least aligned on sizeof(size_t), so the maximum shift is SIMD_ALIGN-sizeof(size_t)
  const size_t startOffset = SIMD_ALIGN - sizeof(size_t) + 3*sizeof(char*); // up to 80 bytes...

  const size_t safe_size = size + startOffset;
  if(safe_size<size) // account for possible overflow
    goto error;

  pstart = (char*) malloc(safe_size); // start of original block
  if(pstart==NULL)
    goto error;

  p2 = (char**)(((size_t)(pstart) + startOffset) & ~(SIMD_ALIGN - 1)); // only keep bits ge SIMD_ALIGN
  p2[-1] = pstart;
  p2[-2] = pstart + size;
  p2[-3] = (char*) ((size_t) pstart + (size ^ 0xBF58476D1CE4E5B9ULL)); // makes a verification possible
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
    if(((size_t)(p2[-2]-p2[-1])^0xBF58476D1CE4E5B9ULL) != (size_t)(p2[-3]-p2[-1]))
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

#endif // HEXTREME malloc implementation

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

/*********************************************************
 * Operations on 3D vectors
 *********************************************************/
HXTStatus hxtNorm2V3(double v[3], double* norm2);
HXTStatus hxtNormalizeV3(double v[3]);
HXTStatus hxtCrossProductV3(double a[3], double b[3], double res[3]);

/*********************************************************
 * Matrix operations
 *********************************************************/
HXTStatus hxtDet2x2(double mat[2][2], double* det);
HXTStatus hxtInv2x2(double mat[2][2], double inv[2][2], double *det);
HXTStatus hxtDet3x3(double mat[3][3], double *det);
HXTStatus hxtInv3x3(double mat[3][3], double inv[3][3], double *det);

HXTStatus hxtInv4x4ColumnMajor(double mat[16], double inv[16], double *det);

/*********************************************************
 * Operations on linear Tet
 *********************************************************/
HXTStatus hxtJacobianLinTet(double *x , double *y, double *z , double mat[3][3]);

#ifndef M_PI
  #define M_PI 3.14159265358979323846264338327950
#endif // !M_PI

#ifdef __cplusplus
}
#endif


#endif
