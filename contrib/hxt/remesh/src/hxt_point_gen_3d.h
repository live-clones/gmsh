#ifndef HXT_POINT_GEN_3D_H
#define HXT_POINT_GEN_3D_H

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_options.h"


// ASSUMPTIONS
// 1) the mesh is a volume mesh that covers one single volume

HXTStatus hxtGeneratePointsOnVolumesGmsh
(
  HXTMesh *mesh, // input tetrahedral mesh with surface triangles 
  int verbosity,
  const double *sizemap,  // in
  const double *directions, // in
  size_t *npts, // out
  double **pts, // out
  uint32_t **binaryIndices // out
); 

HXTStatus hxtGeneratePointsOnVolumes(HXTMesh *mesh, 
                                     HXTPointGenOptions *opt,
                                     const double *sizemap, 
                                     const double *directions,
                                     HXTPointGenParent *parent,   
                                     HXTMesh *fmesh,
                                     uint32_t *bin); 

#endif
