#ifndef HXT_POINT_GEN_REALLOC_H
#define HXT_POINT_GEN_REALLOC_H

#include "hxt_tools.h"
#include "hxt_mesh.h"

HXTStatus hxtVerticesReserve(HXTMesh* mesh, uint32_t nbNewVertices);
HXTStatus hxtPointsReserve(HXTMesh* mesh, uint64_t nbNewElements);
HXTStatus hxtLinesReserve(HXTMesh* mesh, uint64_t nbNewElements);
HXTStatus hxtTrianglesReserve(HXTMesh* mesh, uint64_t nbNewTriangles);
HXTStatus hxtQuadsReserve(HXTMesh* mesh, uint64_t nbNewElements);
HXTStatus hxtTetsReserve(HXTMesh* mesh, uint64_t nbNewElements);
HXTStatus hxtHexahedraReserve(HXTMesh* mesh, uint64_t nbNewElements);
HXTStatus hxtPrismsReserve(HXTMesh* mesh, uint64_t nbNewElements);
HXTStatus hxtPyramidsReserve(HXTMesh* mesh, uint64_t nbNewElements);

HXTStatus hxtVerticesResize(HXTMesh* mesh, uint32_t nbNewVertices);
HXTStatus hxtPointsResize(HXTMesh* mesh, uint64_t nbNewElements);
HXTStatus hxtLinesResize(HXTMesh* mesh, uint64_t nbNewElements);
HXTStatus hxtTrianglesResize(HXTMesh* mesh, uint64_t nbNewTriangles);


#endif
