#ifndef HXT_POINT_GEN_UTILS_H
#define HXT_POINT_GEN_UTILS_H

#include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"

// parent.type 
//  1 for line (boundary edge)
//  2 for triangle 
//  4 for tetrahedra
// 15 for point (1-d point element - corners)
// Attention: the parent.id for type 15 is the number of the
//            corresponding vertex on the initial mesh

typedef struct{

  uint8_t type;
  uint64_t id;

} HXTPointGenParent;

// General functions
HXTStatus hxtPointGenSplitQuads(HXTMesh *mesh, uint16_t *color);
HXTStatus hxtExtractColoredSurface(HXTMesh *mesh, uint16_t color);
HXTStatus hxtCheckZeroAreaTriangles(HXTMesh *mesh, const char *filename); 

// Input directions from edges to vertices 
HXTStatus hxtPointGenConstructFrame(HXTMesh *mesh, double *dirs, double *dirsFrame);
HXTStatus hxtPointGenDirectionsEdgesToVertices(HXTMesh *mesh, double *dirs, double *directions);
HXTStatus hxtPointGenDirectionsTrianglesToEdges(HXTMesh *mesh, double *dirs, double *directions);

// Sizemap functions
HXTStatus hxtPointGenGetSizesInputMesh(HXTEdges *edges, double factor, double *sizemap);
HXTStatus hxtPointGenGetSizesCurvature(HXTEdges *edges, int N, double a, double minSize, double *sizemap);
HXTStatus hxtPointGenSizemapSmoothing(HXTEdges *edges, double factor, double *sizemap);
HXTStatus hxtPointGenSizemapFromNelements(HXTMesh *mesh, uint64_t nelem, double *sizemap);

// Extract lines from dihedral angles function
HXTStatus hxtPointGenOpenLines(HXTMesh *mesh);
HXTStatus hxtPointGenClassifyDihedralLines(HXTMesh *mesh, HXTEdges *edges); 

// Function to associate elements
HXTStatus hxtGetLinesToEdges(HXTEdges *edges, uint32_t *lines2edges);
HXTStatus hxtGetEdgesToLines(HXTEdges *edges, uint32_t *lines2edges, uint64_t *edges2lines);
HXTStatus hxtCountMaxNumberOfTrianglesToEdges(HXTEdges *edges, uint64_t *maxNumTri);
HXTStatus hxtGetLinesToTriangles(HXTEdges *edges, uint64_t maxLT, uint64_t *edges2lines, uint64_t *lines2triangles);
HXTStatus hxtCountMaxNumberOfLinesToVertices(HXTMesh *mesh, uint64_t *maxNumLines);
HXTStatus hxtGetVerticesToLines(HXTMesh *mesh, uint64_t maxVL, uint64_t *vertices2lines);
HXTStatus hxtGetVerticesToTriangles(HXTMesh *mesh, uint64_t *vertices2triangles);
HXTStatus hxtGetTrianglesToTetrahedra(HXTMesh *mesh, uint64_t *tri2tet,uint64_t *lines2tet);
HXTStatus hxtGetBoundaryTetrahedraToTriangles(HXTMesh *mesh, uint64_t **tet2tri);

HXTStatus hxtGetLinesColorsList(HXTMesh *mesh, uint16_t *numColors, uint16_t **listColors);
HXTStatus hxtGetTrianglesColorsList(HXTMesh *mesh, uint16_t *numColors, uint16_t **listColors);

// RTREE functions
HXTStatus hxtPointGenFilter(double *coords,
                            double *pp, // candidate point
                            double size,
                            double threshold,
                            void *data,
                            int *pass);

int hxtIsTriOnBoundary(HXTEdges *edges, uint64_t *edges2lines, uint64_t ct);
HXTStatus hxtGetNeighbourTriangle(HXTEdges *edges, uint64_t ct, uint32_t side, uint64_t *neigh);

HXTStatus hxtVertexCavity(HXTMesh *mesh,
                          HXTEdges *edges, 
                          uint32_t cv, 
                          uint64_t ct, 
                          uint64_t *cavSize, 
                          uint64_t *cavity);

HXTStatus hxtBoundaryVertexCavity(HXTMesh *mesh,
                                  HXTEdges *edges, 
                                  uint32_t cv, 
                                  uint64_t ct, 
                                  uint32_t ce,
                                  uint64_t *edges2lines,
                                  uint64_t *cavSize, 
                                  uint64_t *cavity);

HXTStatus hxtVertexCavityEdges(HXTMesh *mesh,
                               HXTEdges *edges, 
                               uint32_t cv, 
                               uint64_t ct, 
                               uint32_t *cavSize, 
                               uint32_t *cavity);

HXTStatus hxtBoundaryVertexCavityEdges(HXTMesh *mesh,
                                       HXTEdges *edges, 
                                       uint32_t cv, 
                                       uint64_t ct, 
                                       uint32_t ce,
                                       uint64_t *edges2lines,
                                       uint32_t *cavSize, 
                                       uint32_t *cavity);

HXTStatus hxtVertexFanPerimeter(HXTMesh *mesh,
                                HXTEdges *edges, 
                                uint32_t cv, 
                                uint64_t ct, 
                                uint32_t *cavSize, 
                                uint32_t *cavity);

HXTStatus hxtBoundaryVertexFanPerimeter(HXTMesh *mesh,
                                        HXTEdges *edges, 
                                        uint32_t cv, 
                                        uint64_t ct, 
                                        uint32_t ce,
                                        uint64_t *edges2lines,
                                        uint32_t *cavSize, 
                                        uint32_t *cavity);

HXTStatus hxtEstimateNumOfVerticesWithMesh(HXTMesh *mesh, 
                                           const double *sizemap, 
                                           uint32_t *estNumVertices);

HXTStatus hxtEstimateNumOfVerticesWithPoints(double *coords,   
                                             double *sizemap, 
                                             uint32_t numPoints,
                                             uint32_t *estNumVertices);

HXTStatus hxtPointGenModelMaxLength(double *coords,   
                                    uint32_t numPoints,
                                    double *maxL);


#endif
