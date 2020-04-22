#ifndef HXT_QMBMULTIBLOCK_H
#define HXT_QMBMULTIBLOCK_H

#include <vector>
#include "hxt_qmbSeparatrice.h"
#include "hxt_qmbSingularity.h"
#include "hxt_qmbCorner.h"

extern "C"{
#include "hxt_mesh.h"
#include "hxt_edge.h"
}

class MultiBlock
{
 public:
  MultiBlock(HXTEdges *edges, std::vector<Separatrice> vectSep, std::vector<Singularity> vectSing, std::vector<Corner> vectCorner);
  ~MultiBlock();
  HXTStatus splitTriMeshOnMBDecomp();
  HXTStatus createMyTriMesh(std::vector<std::array<double,3>> *allMeshNodes, std::vector<std::array<int,3>> *allMeshTri,
			    std::vector<std::array<int,2>> *allMeshLines, std::vector<int> *allMeshLinesColors);
  HXTMesh* getMyTriMesh();
  HXTStatus hxtWriteFlaggedTriangles(std::vector<int> flag, const char *fileName);
  HXTStatus hxtWriteFlaggedNodes(std::vector<std::vector<std::array<double,3>>> cCoord, const char *fileName);
  HXTStatus hxtWriteTriVert(std::vector<std::array<double,3>> vertices, const char *fileName);
  

  
 private:
  HXTEdges *m_Edges;
  HXTContext *m_contextTri;
  HXTMesh *m_myTriMesh;
  std::vector<Separatrice> m_vectSep;
  std::vector<Singularity> m_vectSing;
  std::vector<Corner> m_vectCorner;
  
    
  //Methods
  int addInPointsVectIfNotPresent(std::vector<std::array<double,3>> *vect, std::array<double,3> point, int *ind);
  int addInPointsVectIfNotPresent2(std::vector<std::array<double,3>> *vect, std::array<double,3> point);
  int addInPointsVectIfNotPresentCustomized(uint64_t begin,std::vector<std::array<double,3>> *vect, std::array<double,3> point, int *ind);
  HXTStatus addInIntVectIfNotPresent(std::vector<int> *vect, int value);
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
 
  
};

#endif
