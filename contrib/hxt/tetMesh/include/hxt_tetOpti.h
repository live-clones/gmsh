// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_OPTI_H
#define HXT_OPTI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"
#include "hxt_bbox.h"


typedef struct {
  HXTBbox* bbox;      /* The bounding box for all vertices.
                       *  - if bbox==NULL, the bbox is recomputed internally;
                       *  - if bbox!=NULL, bbox must contain all vertices */

  /* function giving the quality of an element, or NULL to use default function*/
  double (*qualityFun)(double* p0, double* p1, double* p2, double* p3,
                       void* qualityData);
  void* qualityData; /* user pointer to give to qualityFun */
  double qualityMin; /* threshold for mesh improvement: optimization terminates when all
                        element have a quality greater than qualityMin */
  int numThreads;    /* - `numThreads>0`: use `numThreads` threads
                        - `numThreads=0`: use the default nbr. of threads
                        - `numThreads<0`: use OMP_NUM_PROCS */

  /* The position of the first `numVerticesConstrained` vertices is constrained,
     meaning that we can't move those vertices with smoothing operations.
     The rest of the vertices can be moved. */
  uint32_t numVerticesConstrained;

  int verbosity;
  int reproducible;

} HXTOptimizeOptions;


/* Improve the quality of the worst element of the mesh such that
 * the worst element has a quality better than options->qualityMin
 * If the quality of the worst element cannot be improved
 * above options->qualityMin, bad elements are moved at the end
 * of mesh->tetrahedra and the functions returns HXT_STATUS_FALSE
 */
HXTStatus hxtOptimizeTetrahedra(HXTMesh *mesh,
                                HXTOptimizeOptions* options);

#ifdef __cplusplus
}
#endif

#endif
