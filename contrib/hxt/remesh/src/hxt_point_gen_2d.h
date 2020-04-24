#ifndef HXT_POINT_GEN_2D_H
#define HXT_POINT_GEN_2D_H

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_options.h"

HXTStatus hxtGeneratePointsOnSurface(HXTPointGenOptions *opt,
                                     HXTMesh *mesh,
                                     HXTEdges *edges,
                                     const double *sizemap, 
                                     const double *directions,
                                     HXTPointGenParent *pointParent,   
                                     HXTMesh *fmesh); 

HXTStatus hxtGetPointsOnSurfacesFromInputMesh(HXTMesh *mesh, 
                                              HXTPointGenOptions *opt,
                                              HXTMesh *fmesh, 
                                              HXTPointGenParent *parent);

#endif
