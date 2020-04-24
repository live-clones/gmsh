#ifndef HXT_POINT_GEN_H_IO
#define HXT_POINT_GEN_H_IO

#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"

/**
* \file hxt_point_gen_io.h Point generation input/output files.
* \author Christos Georgiadis 
*/

HXTStatus hxtPrintVec(const double *vec);

HXTStatus hxtPointGenExportPointsToPos(HXTMesh* m, 
                                       const char* posFile);

HXTStatus hxtPointGenWriteScalarPoints(HXTMesh *mesh, 
                                       const double *values,
                                       const char *filename);

HXTStatus hxtPointGenWriteScalarTriangles(HXTMesh *mesh, 
                                          const double *values,
                                          const char *filename);

HXTStatus hxtPointGenWriteDirections(HXTMesh *mesh, 
                                     const double *directions,
                                     const char *filename);

HXTStatus hxtPointGenWriteDirectionsEdges(HXTEdges *edges, 
                                          const double *directions,
                                          const char *filename);



HXTStatus hxtPointGenReadSizesFile2D(const char *filename, 
                                     double** sizes, 
                                     int *numSings,
                                     uint32_t **sings,
                                     uint32_t *numEdges, 
                                     uint32_t **edg, 
                                     double **dirs);


#endif
