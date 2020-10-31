#ifndef HXT_SURFACE_MESH_COLLAPSE_H
#define HXT_SURFACE_MESH_COLLAPSE_H

#include "hxt_mesh.h"
#include "hxt_edge.h"

#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_options.h"

HXTStatus hxtSurfaceMeshCollapse(const HXTMesh *mesh,
                                 const double *directions,
                                 const double *sizemap,
                                 HXTPointGenOptions *opt,
                                 HXTMesh *tmesh,
                                 HXTEdges *tedges,
                                 HXTPointGenParent *parent,
                                 uint64_t *p2t,
                                 uint32_t *p2p,
                                 uint32_t *flagV,
                                 HXTMesh *nmesh);


#endif
