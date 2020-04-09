#ifndef HXT_SURFACE_MESH_H
#define HXT_SURFACE_MESH_H

#include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"

#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_options.h"

HXTStatus hxtSurfaceMesh(HXTPointGenOptions *opt,
                         HXTMesh *mesh,
                         HXTEdges *edges,
                         HXTPointGenParent *parent,
                         HXTMesh *fmesh,
                         HXTMesh *nmesh);

#endif
