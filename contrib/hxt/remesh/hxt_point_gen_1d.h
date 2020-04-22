#ifndef HXT_POINT_GEN_1D_H
#define HXT_POINT_GEN_1D_H

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_point_gen_options.h"
#include "hxt_point_gen_utils.h"

HXTStatus hxtGeneratePointsOnLines(HXTMesh *mesh, 
                                   HXTPointGenOptions *opt,
                                   const double *directions,
                                   const double *sizemap, 
                                   HXTMesh *outmesh, 
                                   HXTPointGenParent *parent);


HXTStatus hxtGetPointsOnLinesFromInputMesh(HXTMesh *mesh, 
                                          HXTPointGenOptions *opt,
                                          HXTMesh *fmesh, 
                                          HXTPointGenParent *parent);
#endif
