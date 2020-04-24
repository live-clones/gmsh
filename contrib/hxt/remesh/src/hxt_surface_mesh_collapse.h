#ifndef HXT_SURFACE_MESH_COLLAPSE_H
#define HXT_SURFACE_MESH_COLLAPSE_H

#include "hxt_mesh.h"
#include "hxt_edge.h"

#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_options.h"

HXTStatus hxtSurfaceMeshCollapse(HXTPointGenOptions *opt,
                                 HXTMesh *tmesh,
                                 HXTMesh *nmesh,
                                 HXTEdges *tedges,
                                 HXTPointGenParent *parent,
                                 uint32_t *flagV);


#endif
