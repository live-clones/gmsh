// Hxt - Copyright (C)
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETNODALSIZE_H
#define HXT_TETNODALSIZE_H

#include "hxt_mesh.h"
#include <math.h>
#include <float.h>

typedef struct {
  double* array;
  HXTStatus (*callback)(double *coord, uint32_t* volume, size_t n, void* userData);
  void* userData;
  double min;
  double max;
  double factor;
  int enabled;
} HXTNodalSizes;

HXTStatus hxtNodalSizesInit(HXTMesh* mesh, HXTNodalSizes* nodalSize);
HXTStatus hxtNodalSizesDestroy(HXTNodalSizes* nodalSize);


static inline double squareDist(double v0[3], double v1[3])
{
  double d0 = v1[0] - v0[0];
  double d1 = v1[1] - v0[1];
  double d2 = v1[2] - v0[2];
  return d0*d0 + d1*d1 + d2*d2;
}


static inline int isTooClose(double s0, double s1, double squareDist, const HXTNodalSizes* ns)
{
  if(s0>0.0 && s1>0.0) {
    double meanSize = fmin(ns->max, fmax(ns->min, 0.5*(s0+s1))) * ns->factor;
    if(squareDist < meanSize * meanSize) { // we won't enter this on overflow of meansize when max is too big...
      return 1;
    }
  }

  return 0;
}



#endif
