#ifndef HXT_POINT_GEN_1D_H
#define HXT_POINT_GEN_1D_H

#include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_point_gen_options.h"

HXTStatus hxtGeneratePointsOnLines(HXTMesh *mesh, 
                                   const double *directions,
                                   const double *sizemap, 
                                   HXTMesh *outmesh, 
                                   uint64_t *pointParent);   

#endif
