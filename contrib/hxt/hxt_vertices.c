#include "hxt_omp.h"
#include <string.h>
#include "hxt_vertices.h"
#include "hxt_sort.h"

/**
* \file hxt_vertices.c see header hxt_vertices.h.
* \author Célestin Marot
*/

/* create a nextbefore macro
 * for a strictly positive value, round to previous double value */
#if (defined (__STD_VERSION__) && (__STD_VERSION__ >= 199901L)) // nextafter only from C99
#include <math.h>
#define nextbefore(x) nextafter(x,0.0);
#else
#include <float.h>
#define nextbefore(x) (x*(1.0-DBL_EPSILON))
#endif


#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define SWAP(x,y) do{uint32_t tmp=x; x=y; y=tmp;}while(0)
#define INVE(x) x=s-1-x // same as x^=s-1 I think


/* final coordinate contain n_iter*3 bits
 * if n < HXT_SORT_SEQUENTIAL_LIMIT hxt_sort makes passes of 8 bit.
 * Thus making a 9 bit coord is stupid because you need a pass just to sort the last bit
 * you could have used a 16 bit coord for the same price
 *
 *                            multiple of 8: 0 8 16 24 32 40 48 56    64
 * from this, we get that it's better to use 0 6 15 24 30 39 48 54 or 63 bit
 * corresponding to a nbr of iteration of    0 2 5  8  10 13 16 18 or 21
 *
 * if n > HXT_SORT_SEQUENTIAL_LIMIT, hxt_sort first make passes of  11 bit
 *
 *                           multiple of 11: 0 11 22 33 44 55 66
 * from this, we get that it's better to use 0 9  21 33 42 54 63 bit
 * corresponding to a nbr of iteration of    0 3  7  11 14 18 21 */
uint32_t hxtAdvisedHilbertBits(const uint32_t n)
{
  uint32_t nlog2 = u32_log2(n)*3/2; // if we have n points, we want approximately n^1.5 possible hilbert coordinates

  if(n < HXT_SORT_SEQUENTIAL_LIMIT){
     return (nlog2+7)/8*8/3*3;
  }
  else{
     return MIN(63, (nlog2+10)/11*11/3*3);
  }
}


// we want a minimum of 16 blocks per partitions^2
// we also want to have at least 16 blocks per vertex to sort
uint32_t hxtAdvancedHilbertBits(HXTBbox* bbox, double sizeStart, double sizeEnd, uint32_t numStart, uint32_t numEnd, uint32_t numInMesh, uint32_t numToSort, uint32_t nthreads){
    uint32_t logNthreads = u32_log2(nthreads+1);
    double k1 = 0.065*(logNthreads+2); // how much the number of iteration depends on the mesh size
    const double k2 = 0.38;   // how much the number of iteration depends on the number of point to sort
    uint32_t num = numInMesh + numToSort/2;

    if(sizeEnd==0.0){    // we have to guess the mesh size
      // k1 *= (2./3.);  // minimum mesh size in uniform distribution
      k1 *= (1./3.);     // grid-like
    }
    else{
      double meanBBoxSize = ((bbox->max[0] - bbox->min[0])
                           + (bbox->max[1] - bbox->min[1])
                           + (bbox->max[2] - bbox->min[2]))/3.0;

      double k1End = (double) u64_log2((uint64_t) (meanBBoxSize/sizeEnd))/u32_log2(numEnd);

      if(sizeStart==0.0){
        k1 *= k1End;
      }
      else{
        double alpha = (double) (num - numStart)/(numEnd-numStart + .1);
        double k1Start = (double) u64_log2((uint64_t) (meanBBoxSize/sizeStart))/u32_log2(numStart);

        k1 *= (1-alpha)*k1Start + alpha*k1End;
      }
    }

    num = u32_log2(num)*k1 + u32_log2(numToSort)*k2;
    return MIN(21, num)*3;
}

/*================================= compute the hilberts distance ===========================================
 *
 * This part is for computing the hilbert coordinates of the vertices (X,Y,Z)
 * shift[i] must be between 0 and 1
 */
HXTStatus hxtVerticesHilbertDist(HXTBbox* bbox, HXTVertex* vertices, const uint32_t n, uint32_t* nbits, const double* shift)
{
HXT_ASSERT(vertices!=NULL);
HXT_ASSERT(bbox!=NULL);
HXT_ASSERT(nbits!=NULL);
HXT_ASSERT_MSG(bbox->min[0]<bbox->max[0] ||
        bbox->min[1]<bbox->max[1] ||
        bbox->min[2]<bbox->max[2],"wrong bounding box");
  
  if(*nbits>63){
    *nbits = 63;
  }
  else if(*nbits==0) {
    #pragma omp parallel for simd
    for (uint32_t i=0; i<n; i++)
      vertices[i].padding.hilbertDist = 0;

    return HXT_STATUS_OK;
  }
  else{
    *nbits = (*nbits+2)/3*3;
  }

  const uint32_t level = *nbits/3;
  const double defaultShift[3] = {0.5,0.5,0.5};

  if(shift==NULL)
    shift=defaultShift;

/* this was a beautifull check of the parameters... */

  // if(level==0){
  //   #pragma omp parallel for
  //   for (uint32_t i=0; i<n; i++)
  //     vertices[i].padding.hilbertDist = 0;

  //   return HXT_STATUS_OK;
  // }

  double hxtDeclareAligned div1[3];
  double hxtDeclareAligned div2[3];
  double hxtDeclareAligned mean[3];
  double hxtDeclareAligned min1[3];
  double hxtDeclareAligned min2[3];

  uint32_t nmax = 1U<<level;

  for (unsigned j=0; j<3; j++) {
    double diff = bbox->max[j]-bbox->min[j];

    div1[j] = nextbefore(nmax/(2.0*shift[j]*diff));
    div2[j] = nextbefore(nmax/(2.0*(1.0-shift[j])*diff));

    min1[j] = -bbox->min[j]*div1[j];
    min2[j] = -(bbox->max[j]-2.0*(1.0-shift[j])*diff)*div2[j];

    mean[j] = bbox->min[j] + shift[j]*diff;
  }


  // const uint32_t invGCTable[8] = {0,1,3,2,7,6,4,5};

#pragma omp parallel for simd
  for (uint32_t i=0; i<n; i++)
  {
    double vx = vertices[i].coord[0];
    double vy = vertices[i].coord[1];
    double vz = vertices[i].coord[2];

    if(vx<bbox->min[0] || vx>bbox->max[0] ||
       vy<bbox->min[1] || vy>bbox->max[1] ||
       vz<bbox->min[2] || vz>bbox->max[2]) {
      /* if a tetrahedron contain a vertex that is outside the bounding box,
         it will not be refined and will never be in any cavity.
         The vertices outside the bounding box get the value UINT64_MAX as hilbert index
      */
      vertices[i].padding.hilbertDist = UINT64_MAX;
      continue;
    }

    if(vx < mean[0]){
      vx = vx*div1[0]+min1[0];
    }
    else{
      vx = vx*div2[0]+min2[0];
    }
    if(vy < mean[1]){
      vy = vy*div1[1]+min1[1];
    }
    else{
      vy = vy*div2[1]+min2[1];
    }
    if(vz < mean[2]){
      vz = vz*div1[2]+min1[2];
    }
    else{
      vz = vz*div2[2]+min2[2];
    }

    __assume(vx>=0.0);
    __assume(vy>=0.0);
    __assume(vz>=0.0);

    uint32_t x = vx;
    uint32_t y = vy;
    uint32_t z = vz;

    uint64_t bits;

    #if 1 // this part is for Moore's curve...
    {
      uint32_t s = 1U<<(level-1);
      uint32_t rx = (x & s) != 0;
      uint32_t ry = (y & s) != 0;
      uint32_t rz = (z & s) != 0;

      uint32_t invGC = (rx*7)^(ry*3)^rz;
      // uint32_t invGC = invGCTable[rx*4+ry*2+rz];

      bits = invGC;

      if(!rx){
        INVE(y);
        INVE(x);
      }
      if(rz){
        INVE(y);
      }
      else{
        INVE(z);
      }

      SWAP(x,z);
      SWAP(x,y);
    }
    #endif

    for (int j = level-2; j>=0; j--) {
      uint32_t s = 1U<<j;
      uint32_t rx = (x >> j) & 1;
      uint32_t ry = (y >> j) & 1;
      uint32_t rz = (z >> j) & 1;

      // the xyz 3 bit number is viewed as gray code that we need to reverse (grayToBinary)
      uint32_t invGC = (rx*7)^(ry*3)^rz;
      // uint32_t invGC = invGCTable[rx*4+ry*2+rz];

      __assume(invGC<=7);

      bits = (bits<<3) + invGC;

      if(rx){
        if(rz){
          INVE(y);
        }
        else{
            INVE(z);
            if(ry)
              SWAP(x,y);
            else
              SWAP(y,z);
        }
        INVE(x);
      }
      else{
        if(!rz){
          if(ry){ // GC:3 -- num:2
            INVE(z);
            SWAP(x,y);
            INVE(x);
          }
          else{
            SWAP(y,z);
          }
        }
      }

      SWAP(y,z);
      SWAP(x,z);
    }
    vertices[i].padding.hilbertDist = bits;
  }

  return HXT_STATUS_OK;
}


static inline uint64_t getVertexDist64(HXTVertex* const __restrict__  v, const void* userData)
{
  HXT_UNUSED(userData);
  return v->padding.hilbertDist;
}

static HXTStatus hxtVerticesSort64(HXTVertex* const __restrict__  vertices, const uint32_t n, const uint64_t distMax)
{
  HXTSORT64_UNIFORM(HXTVertex, vertices, n, distMax, getVertexDist64, NULL);
  return HXT_STATUS_OK;
}

static inline uint32_t getVertexDist32(HXTVertex* const __restrict__  v, const void* userData)
{
  HXT_UNUSED(userData);
  return v->padding.hilbertDist;
}

// TODO: test if it's really worth it to have a 32 bit version
static HXTStatus hxtVerticesSort32(HXTVertex* const __restrict__  vertices, const uint32_t n, const uint32_t distMax){
  HXTSORT32_UNIFORM(HXTVertex, vertices, n, distMax, getVertexDist32, NULL);
  return HXT_STATUS_OK;
}


HXTStatus hxtVerticesSort(HXTVertex* const __restrict__  vertices, const uint32_t n, uint32_t nbits)
{
  HXT_ASSERT(vertices!=NULL);
  if(nbits>64){
    nbits = 64;
  }
  else if(nbits==0){
    return HXT_STATUS_OK;
  }

  uint64_t one = 1;
  if(nbits>32){
    HXT_CHECK( hxtVerticesSort64(vertices, n, (one<<nbits)-1) );
  }
  else{
    HXT_CHECK( hxtVerticesSort32(vertices, n, (one<<nbits)-1) );
  }

  return HXT_STATUS_OK;
}

static inline uint64_t getNodeInfoDist64(hxtNodeInfo*  const __restrict__ nodeInfo, const void* userData)
{
  HXT_UNUSED(userData);
  return nodeInfo->hilbertDist;
}

static HXTStatus hxtNodeInfoSort64(hxtNodeInfo*  const __restrict__ array, const uint32_t n, const uint64_t distMax)
{
  HXTSORT64_UNIFORM(hxtNodeInfo, array, n, distMax, getNodeInfoDist64, NULL);
  return HXT_STATUS_OK;
}

static inline uint32_t getNodeInfoDist32(hxtNodeInfo*  const __restrict__ nodeInfo, const void* userData)
{
  HXT_UNUSED(userData);
  return nodeInfo->hilbertDist;
}


static HXTStatus hxtNodeInfoSort32(hxtNodeInfo*  const __restrict__ array, const uint32_t n, const uint32_t distMax)
{
  HXTSORT32_UNIFORM(hxtNodeInfo, array, n, distMax, getNodeInfoDist32, NULL);
  return HXT_STATUS_OK;
}


HXTStatus hxtNodeInfoSort(hxtNodeInfo*  const __restrict__ array, const uint32_t n, uint32_t nbits)
{
  HXT_ASSERT(array!=NULL);
  if(nbits>64){
    nbits = 64;
  }
  else if(nbits==0){
    return HXT_STATUS_OK;
  }

  const uint64_t one = 1;

  if(nbits>32){
    HXT_CHECK( hxtNodeInfoSort64(array, n, (one<<nbits)-1) );
  }
  else{
    HXT_CHECK( hxtNodeInfoSort32(array, n, (one<<nbits)-1) );
  }

  return HXT_STATUS_OK;
}


/*********************************** shuffle functions ***********************************************/

static inline uint32_t fastHash(uint32_t x) {
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = (x >> 16) ^ x;
  return x;
}

/* for the non-static function, use a 22 bit key and a sort with two pass so we don't need to copy */
HXTStatus hxtVerticesShuffle(HXTVertex* const __restrict__ vertices, const uint32_t n){
  #pragma omp parallel for simd
  for (uint32_t i=0; i<n; i++){
    vertices[i].padding.hilbertDist = fastHash(i);
  }

  HXT_CHECK( hxtVerticesSort32(vertices, n, UINT32_MAX) );
  return HXT_STATUS_OK;
}

/* for the non-static function, use a 22 bit key and a sort with two pass so we don't need to copy */
HXTStatus hxtNodeInfoShuffle(hxtNodeInfo* const __restrict__ nodeInfo, const uint32_t n){
  #pragma omp parallel for simd
  for (uint32_t i=0; i<n; i++){
    nodeInfo[i].hilbertDist = fastHash(i);
  }

  HXT_CHECK( hxtNodeInfoSort32(nodeInfo, n, UINT32_MAX) );
  return HXT_STATUS_OK;
}




