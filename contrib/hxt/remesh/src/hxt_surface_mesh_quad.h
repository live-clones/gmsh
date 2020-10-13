#ifndef HXT_SURFACE_MESH_QUAD_H
#define HXT_SURFACE_MESH_QUAD_H

#include "hxt_mesh.h"

#include "hxt_point_gen_options.h"


HXTStatus hxtPointGenQuadConvert(HXTPointGenOptions *opt,
                                 HXTMesh *omesh,
                                 HXTMesh *mesh, 
                                 uint64_t *p2t,
                                 uint32_t *bin);


#endif
