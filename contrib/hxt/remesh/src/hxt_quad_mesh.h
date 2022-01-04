#ifndef HXT_QUAD_MESH_H
#define HXT_QUAD_MESH_H

#include "hxt_mesh.h"
#include "hxt_point_gen_options.h"

// TODO for now here because it is used in hxt_surface_mesh_quad.c

double hxtPointGenQuadScaledJacobian(double *p0, 
                                     double *p1, 
                                     double *p2, 
                                     double *p3, 
                                     int *badNode);

HXTStatus hxtPointGenProjectCloseRTree(HXTMesh *omesh, 
                                      void *dataTri,
                                      uint64_t ot,   // assigned triangle
                                      double *pp,
                                      uint64_t *nt,
                                      double *np);

HXTStatus hxtQuadMeshOptimize(HXTPointGenOptions *opt, 
                              HXTMesh *omesh,
                              void *dataTri,
                              uint64_t *p2t,
                              HXTMesh *mesh);

#endif
