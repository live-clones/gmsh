#ifndef HXT_POINT_GEN_3D_H
#define HXT_POINT_GEN_3D_H

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_options.h"

HXTStatus hxtGeneratePointsOnVolumes(HXTMesh *mesh, 
                                     HXTPointGenOptions *opt,
                                     const double *sizemap, 
                                     const double *directions,
                                     HXTPointGenParent *parent,   
                                     HXTMesh *fmesh,
                                     uint32_t *bin); 

#endif
