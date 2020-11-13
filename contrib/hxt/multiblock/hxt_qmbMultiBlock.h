#ifndef HXT_QMBMULTIBLOCK_H
#define HXT_QMBMULTIBLOCK_H

#include <cstdint>
#include <vector>
#include "hxt_qmbSeparatrice.h"
#include "hxt_qmbSingularity.h"
#include "hxt_qmbCorner.h"

extern "C"{
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_tools.h"
}
#include <set>

class BlockParametrization;

class MultiBlock
{
 public:
  MultiBlock(HXTEdges *edges, std::vector<Separatrice> vectSep, std::vector<Singularity> vectSing, std::vector<Corner> vectCorner, double *crossfield, double *scalingFactor);
  ~MultiBlock();
  HXTStatus splitTriMeshOnMBDecomp();
  HXTStatus createMyTriMesh(std::vector<std::array<double,3>> *allMeshNodes, std::vector<std::array<int,3>> *allMeshTri,
			    std::vector<std::array<int,2>> *allMeshLines, std::vector<int> *allMeshLinesColors);
  HXTMesh* getMyTriMesh();
  HXTStatus hxtWriteFlaggedTriangles(std::vector<int> flag, const char *fileName);
  HXTStatus hxtWriteFlaggedNodes(std::vector<std::vector<std::array<double,3>>> cCoord, const char *fileName); 
  HXTStatus hxtWriteTriVert(std::vector<std::array<double,3>> vertices, const char *fileName);
  //new
  HXTStatus buildQuadLayout(); 
  // HXTStatus getExtrVertIndFromSepID(int ID, std::vector<int> *extraVertIndices);
  HXTStatus isExtrVertOnBdry(int ind, int *isBdry);
  HXTStatus isExtrVertTjunction(int ind, int *isTjunction);
  HXTStatus meshQuadLayout(std::vector<double> hVal);
  HXTStatus createQuadMesh();
  HXTMesh* getQuadMesh();
  

  
 private:
  HXTEdges *m_Edges;
  HXTMesh *m_myTriMesh;
  std::vector<Separatrice> m_vectSep;
  std::vector<Singularity> m_vectSing;
  std::vector<Corner> m_vectCorner;

  double *m_crossfield;
  double *m_scalingFactorCrosses;
  std::vector<std::vector<uint64_t>> m_vertToTri;

  //new
  //graph---------------
  std::vector<std::vector<int>> m_sepGraphNodes;
  std::vector<std::vector<uint64_t>> m_sepGraphTriangles;
  std::vector<std::vector<std::array<double,3>>> m_sepGraphDirections;
  //quads------------
  std::vector<std::array<double,3>> m_extraordVertices; //each vector is the coordinates of an extraordinary vertice ID
  std::vector<int> m_extraordVertBdry; //extraordinary vertices indices - which are on boundary
  std::vector<int> m_extraordVertTjunc; //extraordinary vertices indices - which are T-junctions
  std::vector<uint64_t> m_tri;
  double m_minEdgLength; //probably not needed!!! 
  std::vector<std::vector<int>> m_mbQuads; //each vector is quad vertices indices
  std::vector<std::vector<std::array<double,3>>> m_mbEdges; //each vector is a collection of point defining the mbEdg
  std::vector<std::vector<uint64_t>> m_mbEdgesTri; //each vector is a collection of point defining the mbEdg
  std::vector<std::vector<uint64_t>> m_mbEdg2Block;
  std::vector<std::vector<uint64_t>> m_mbBlock2Edg;
  std::vector<std::set<uint64_t>> m_mbBlockTriPatchs; //tri indices patchs for each block
  std::vector<std::vector<uint64_t>> m_Sheets;
  std::vector<uint64_t> m_partitionPerEdge;
  std::vector<std::array<double,3>> m_coordVerticesDiscretization;
  std::vector<std::vector<uint64_t>> m_discrMbEdges;
  std::vector<std::vector<uint64_t>> m_discrQuads;
  HXTMesh *m_quadMesh;
  // std::vector<std::vector<uint64_t>> m_discrHfuncEdges;


  bool m_mbDecompExists;
  std::vector<uint64_t> m_totalElemPatches;


  
    
  //Methods
  int addInPointsVectIfNotPresent(std::vector<std::array<double,3>> *vect, std::array<double,3> point, int *ind);
  int addInPointsVectIfNotPresent2(std::vector<std::array<double,3>> *vect, std::array<double,3> point);
  int addInPointsVectIfNotPresentCustomized(uint64_t begin,std::vector<std::array<double,3>> *vect, std::array<double,3> point, int *ind);
  HXTStatus addInIntVectIfNotPresent(std::vector<int> *vect, int value);
  HXTStatus addInUnsgnIntVectIfNotPresent(std::vector<uint64_t> *vect, uint64_t value);
  int intersectionNodeForGraph2(uint64_t triNum, double *point1, double *point2, double *point3, double *point4, double *newPoint, int *flag);
  int mark(int *flaggedNodes, int size);
  int defineQuads(std::vector<std::vector<int>> graphConnectedNodes, int *quadsWithIndices, int *offset, int *numOffsets, int *sizesQuads, int *numQuads);
  int getGlobalEdg(uint64_t triNum, std::array<double,3> point, uint64_t *edgNum);
  int flagTriangles(std::vector<int> *flag, std::vector<std::vector<int>> *cSep, std::vector<std::vector<uint64_t>> *cEdg, std::vector<std::vector<std::array<double,3>>> *cCoord);
  int isCloseToVert(std::array<double,3> *point, uint64_t edgNum, uint64_t triNum, double *distance);
  int reorderPoints(std::vector<std::array<double,3>> points, std::vector<double> distances, std::vector<std::array<double,3>> *reorderedPoints);
  int orientateTriNodes(uint64_t triNum, std::vector<std::array<double,3>> *cutPoints, std::vector<uint64_t> cutEdg,std::vector<std::array<double,3>> *orientedPoints);
  int getIndice(std::array<double,3> point, std::vector<std::array<double,3>> vectPoints);
  int computeAlpha(double *u, double *v, double *d, double *alpha);
  int reorderingConnectivityNodes(int *connectedNodes, uint64_t *connectedTri, double *connectedDir, int *offset, int *numOffsets, int *newConnectedNodes,
				  std::vector<std::vector<int>> *graphConnectedNodes);
  int getConnectivity(uint64_t triNum, int flag, std::vector<std::array<double,3>> cutPoints, std::vector<int> cutSep, std::vector<std::array<double,3>> *orientedPoints,
		      std::vector<std::vector<int>> *connectedNodes, std::vector<std::array<int,2>> *localLines, std::vector<int> *localLinesColors);
  int split(std::vector<int> nodes, std::vector<std::array<int,3>> *triVertInd, std::vector<int> *rest);
  int isElementBnd(std::vector<std::array<double, 3>> bndNodes, std::vector<std::array<double, 3>> polyNodes);
  int splitTriangle(std::vector<std::array<double,3>> orientedPoints, std::vector<std::array<double,3>> bndryPoints, std::vector<std::vector<int>> connectedNodes,
		    std::vector<std::array<int,3>> *newTri);
  int convertIndToCoord(std::vector<std::array<double,3>> cCoord, int ind, std::array<double,3> *point);
  void computeLocalCutEdges(uint64_t triNum,std::vector<std::array<double,3>> cutCoords,std::vector<uint64_t> *localCutEdges);
  int isTriVert(uint64_t triNum,std::array<double, 3> point, int *globIndex);
  int createNewTriangles(std::vector<int> flag, std::vector<std::vector<int>> cSep, std::vector<std::vector<std::array<double,3>>> cCoord,
			 std::vector<std::array<double,3>> *allMeshNodes, std::vector<std::array<int,3>> *allMeshTri, std::vector<std::array<int,2>> *allMeshLines,
			 std::vector<int> *allMeshLinesColors);

  //new
  void buildTotalPatches();
  bool isInTotalPatch(uint64_t tri);
  int localIntersection2(int sepID1, int sepID2, std::vector<std::array<double,3>> *intersectionPoints,std::vector<uint64_t> *newTriangles, std::vector<std::array<double,3>> *directions, std::vector<double> *length);
  int getGraphElements(std::vector<std::array<double,3>> *nodesCoord, std::vector<uint64_t> *triangles, std::vector<std::array<double,3>> *directions, std::vector<double> *distance, std::vector<int> *offset);
  HXTStatus hxtWriteGraphNodes(std::vector<std::array<double,3>> nodesCoord, const char *fileName);
  int isPointSingularity(double *point1);
  int graphReordering(std::vector<std::array<double,3>> nodesCoord,std::vector<uint64_t> triangles, std::vector<std::array<double,3>> directions, std::vector<double> distance, std::vector<int> offset, std::vector<std::array<double,3>> *newNodes, std::vector<uint64_t> *newTriangles, std::vector<std::array<double,3>> *newDirections, std::vector<double> *newDistances, std::vector<int> *newOffsetGraph);
  int fillGraphStruct(std::vector<std::array<double,3>> newNodes, std::vector<uint64_t> newTriangles,  std::vector<int> newOffset);
  int putIDsInGraph(std::vector<std::array<double,3>> newNodes, std::vector<std::array<double,3>> newDirections,std::vector<uint64_t> newTriangles, std::vector<int> newOffset);
  int nodesConnectivity(int *connectedNodes, uint64_t *connectedTri, double *connectedDir, int *offset, int *numOffsets);
  int checkIfLoop(int cleanSepInd);
  // int reorderingConnectivityNodes(int *connectedNodes, uint64_t *connectedTri, double *connectedDir, int *offset, int *numOffsets, int *newConnectedNodes, std::vector<std::vector<int>> *graphConnectedNodes);
  int killDuplicates(std::vector<std::vector<int>> graphConnectedNodes, std::vector<std::vector<int>> *cleanGraphConnectedNodes,  int *cleanOffset);
  int killDuplicatesSepTjunction();
  int graphNodesOnBdry(int *nodesOnBdry, int *sizeNodesOnBdry);
  int getCleanedSepIndFromSepID(int ID, int *ind);
  int putCleanQuadsInStruct(int *quadsWithIndices, int *sizesQuads, int *numQuads);
  int keepTheQuad(int *quadIndices, int *sizeQuadNodes);
  int getSepCleanIDfrom2extVert(int ind1, int ind2, int &dirSign);
  int getSepIDFromCleanedSepInd(int ind, int *ID);
  int isPointSingularityOrCornerVec(std::array<double,3> *point);
  int getQuadEdgesData();
  int getBlock2Edge();
  int getEdge2Block();
  HXTStatus collectTJunctionIndices();
  HXTStatus getTriangularPatchesIDs(std::vector<int> *triPatchesIDs);
  double getDistanceBetweeenTwoExtrVert(int sepIDNoLimCyc, int extrVertID, int tJuncVertID1);
  int getBlockIDFromVertInd(int v1, int v2, int v3, int *blockID); 
  HXTStatus getTJunctionsPatchesIDs(std::vector<int> *tJunctionPatchesIDs);
 
  
  double normDiffVect(std::array<double,3> *coordP1, std::array<double,3> *coordP2);
  double computeDiscreteLineLengthModified(std::vector<std::array<double,3>> *pCoordLine, std::vector<double> hVal);
  HXTStatus lineDiscretization(std::vector<std::array<double,3>> *line, std::vector<double> hVal, uint64_t partition, std::vector<std::array<double,3>> *newLine);
  

  HXTStatus getDataFromBlockEdgID(int edgID, std::vector<std::array<double, 3>> &pointsOnEdg, std::vector<uint64_t> &trianglesOnEdg);
  HXTStatus createMbTriPatchs();
  int isPointInTri(uint64_t triNum, std::array<double, 3> point, double *alpha, double *beta);
  HXTStatus getTriNumFromPointCoord(std::array<double, 3> pointCoord, std::vector<uint64_t> vectorTriangles, uint64_t *triNum, double *alpha, double *beta);
  HXTStatus getCrossesLifting(const std::vector<uint64_t> &tri, const std::vector<uint64_t> &glob2LocTri, std::vector<std::array<double,3>> &lift, uint64_t triInit, std::array<double,3> dirRef);
  HXTStatus parametrizeBock(uint64_t idBlock, BlockParametrization &blockParam);
  HXTStatus computePatchsParametrization();
  HXTStatus dbgPosEdgData(const char *fileName);
  HXTStatus dbgPosFlagSetTri(const std::set<uint64_t> &tri, const char *fileName);
  HXTStatus dbgPosParametrization(const char *fileName);
  HXTStatus dbgPosPatchData(const char *fileName);
  //meshing
  int getParallelEdg(int blockNum, uint64_t edg1, uint64_t *edg2);
  int getAllSheets();
  int computeAdequatePartitionPerEdge(double sizeofElement, std::vector<double> hVal);
  void getExtrVertIDmbEdg(uint64_t extrID[2],int edgID);
  HXTStatus discretizeEdges(std::vector<double> hVal);
  HXTStatus discretizeQuads();

};

class BlockParametrization
{
 public:
  BlockParametrization(HXTMesh *m):m_mesh(m){};
  ~BlockParametrization(){};

  std::array<double,3> getPhysCoordFromParamCoord(std::array<double,3> paramCoord, uint64_t globNumTriHint=(uint64_t)(-1)){};
  std::array<double,3> getParamCoordFromPhysCoord(std::array<double,3> physCoord, uint64_t globNumTriHint=(uint64_t)(-1)){};
  uint64_t getBelongingTriangleFromParamCoord(std::array<double,3> paramCoord){};
  uint64_t getBelongingTriangleFromPhysCoord(std::array<double,3> physCoord){};

  HXTStatus dbgPosParam(const char *fileName);
    
  HXTMesh *m_mesh;
  std::vector<uint64_t> m_triangles;
  std::vector<uint64_t> m_trianglesGlobalToParam;
  std::vector<std::array<double,3>> m_nodesParamCoord;
  std::vector<uint32_t> m_nodesParamToGlobal;
  std::vector<uint32_t> m_nodesGlobalToParam;

  std::vector<double> scaling;//for dbg only
  std::vector<std::array<double,3>> liftU;//for dbg only
  std::vector<std::array<double,3>> liftV;//for dbg only
  std::array<double,3> pointBC;//for dbg only
  
};

#endif
