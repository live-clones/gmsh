#ifndef _HXT_TETQUALITY_
#define _HXT_TETQUALITY_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"
#include <float.h>

typedef struct {
  double* values;   // qualities for all tet.
  double threshold; // quality threshold for the optimization
  double (*function)(double* p0, double* p1, double* p2, double* p3, void* userData);
  void* userData;
} HXTTetQualities;

double hxtTetDeterminantInexact(double p0[3],  double p1[3], double p2[3], double p3[3], void* userData);

/// TODO: make an optimized version of this
double hxtTetAspectRatio(double p0[3],  double p1[3], double p2[3], double p3[3], void* userData);

//!\ this function does not return the aspect ratio 'r'. It returns 'r^2/24'
double hxtTetAspectFastRatio(double p0[3],  double p1[3], double p2[3], double p3[3], void* userData);
// double myOwnAspectRatio(double a[3],  double b[3], double c[3], double d[3]);




/*
 Compute the squared aspect ratio of a tet with vertices p0 p1 p2 p3
*/
static inline double tetQuality(HXTMesh *mesh,
                                HXTTetQualities* quality,
                                uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3)
{
  HXT_ASSERT(mesh!=NULL);
  HXT_ASSERT(quality!=NULL);

  double* a = &mesh->vertices.coord[4*p0];
  double* b = &mesh->vertices.coord[4*p1];
  double* c = &mesh->vertices.coord[4*p2];
  double* d = &mesh->vertices.coord[4*p3];
  
  return quality->function(a,b,c,d, quality->userData);
}


#ifdef __cplusplus
}
#endif

#endif
