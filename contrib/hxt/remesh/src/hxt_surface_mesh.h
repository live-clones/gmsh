#ifndef HXT_SURFACE_MESH_H
#define HXT_SURFACE_MESH_H

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"

#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_options.h"

HXTStatus hxtSurfaceMesh(HXTPointGenOptions *opt,
                         HXTMesh *mesh,
                         HXTEdges *edges,
                         const double *directions,
                         const double *sizemap,
                         HXTPointGenParent *parent,
                         uint64_t *p2t,
                         uint32_t *p2p,
                         HXTMesh *fmesh,
                         HXTMesh *nmesh);

HXTStatus hxtGetSurfaceMesh(HXTPointGenOptions *opt,
                            HXTMesh *mesh,
                            HXTMesh *fmesh,
                            HXTMesh *nmesh);
#endif
