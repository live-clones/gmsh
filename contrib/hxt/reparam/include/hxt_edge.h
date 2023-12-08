#ifndef HEXTREME_EDGE_H
#define HEXTREME_EDGE_H

#include "hxt_mesh.h"

typedef struct hxtLineLoopStruct HXTLineLoop;

typedef struct hxtBoundariesStruct HXTBoundaries;

typedef struct hxtEdgesStruct{

  HXTMesh *edg2mesh;
  uint64_t *global; // initial number of elements
  
  uint32_t numEdges;// number of edges

  uint32_t* node;// edg2vertices

  uint32_t* color;// to be used ...

  uint64_t* edg2tri;
  uint32_t* tri2edg;
  uint32_t *bdryedges;// physical lines/boundary
  uint64_t nEdgesBdry;  
  int edgesBdryTotal;// to be removed

} HXTEdges; 


double hxtEdgesLength(const HXTEdges *edges,uint32_t ie);

HXTStatus hxtLineLoopGetEdges(HXTLineLoop *loop, uint32_t **edges);
HXTStatus hxtLineLoopGetNumberOfEdges(HXTLineLoop *loop, int *number);
HXTStatus hxtLineLoopGetLength(HXTLineLoop *loops, double *length);

HXTStatus hxtBoundariesGetNumberOfLineLoops(HXTBoundaries *boundaries, int *number);
HXTStatus hxtBoundariesGetNumberOfBorderEdges(HXTBoundaries *boundaries, int *number);
HXTStatus hxtBoundariesGetNumberOfEdgesOfLineLoop(HXTBoundaries *boundaries, int i, int *number);
HXTStatus hxtBoundariesGetEdgesOfLineLoop(HXTBoundaries *boundaries, int i, uint32_t **edges);
HXTStatus hxtBoundariesGetLengthOfLineLoop(HXTBoundaries *boundaries, int i, double *length);
HXTStatus hxtBoundariesGetLineLoop(HXTBoundaries *boundaries, int i,HXTLineLoop **lineLoop);
HXTStatus hxtBoundariesGetSeamPoint(HXTBoundaries *boundaries, int *seamPoint);
HXTStatus hxtEdgesSetBoundaries(HXTEdges *edges, HXTBoundaries **boundaries);


HXTStatus hxtEdgesCreate(HXTMesh *mesh, HXTEdges** edges);
HXTStatus hxtEdgesCreateNonManifold(HXTMesh *mesh, HXTEdges** edges);
HXTStatus hxtEdgesDelete(HXTEdges **edges);

int hxtEdgesIsBoundary (HXTEdges *edges, uint32_t *e);

#endif
