#ifndef HXT_POINT_GEN_2D_H
#define HXT_POINT_GEN_2D_H

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_options.h"

HXTStatus hxtGetDirections(HXTMesh *mesh, 
                           const double *directions,
                           const double *sizemap,
                           uint64_t tri,
                           double *normal,
                           double *uv,
                           double *frame,
                           double *sizes);

HXTStatus hxtGeneratePointsOnSurface(HXTPointGenOptions *opt,
                                     HXTMesh *mesh,
                                     HXTEdges *edges,
                                     const double *sizemap, 
                                     const double *directions,
                                     HXTPointGenParent *pointParent,   
                                     HXTMesh *fmesh, uint32_t *bin); 

HXTStatus hxtGetPointsOnSurfacesFromInputMesh(HXTMesh *mesh, 
                                              HXTPointGenOptions *opt,
                                              HXTMesh *fmesh, 
                                              HXTPointGenParent *parent);

#endif
