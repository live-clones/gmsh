#ifndef HXT_QMBQUADGENERATOR_H
#define HXT_QMBQUADGENERATOR_H

#include <string>
#include <vector>
#include "hxt_qmbSingularity.h"
#include "hxt_qmbCorner.h"
#include "hxt_qmbBoundaryLine.h"
#include "hxt_qmbBoundary.h"
#include "hxt_qmbSeparatrice.h"
#include "hxt_qmbSepGroup.h"
#include "hxt_qmbMultiBlock.h"

extern "C"{
#include "hxt_mesh.h"
#include "hxt_edge.h"
}

class QuadGenerator
{
 public:
  QuadGenerator(HXTMesh *mesh, int nbTurns, double critNorm, int flagTypePos, const char *fileName);
  ~QuadGenerator();
  static HXTStatus trianglebasis(HXTMesh *m, uint32_t *vtri, double *U, double *V, double *n);
  HXTStatus hxtWriteSingularities(const char *fileName);
  HXTStatus hxtWritePatches(const char *fileName);
  HXTStatus hxtWriteCorners(const char *fileName);
  HXTStatus hxtWriteCornerPatches(const char *fileName);
  HXTStatus hxtWriteBdryLines(const char *fileName);
  HXTStatus hxtWriteInitSep(const char *fileName);
  //Geo file stuff
  HXTStatus prepareGeoFile(std::string geoFileName, double *crossfieldCR);
  HXTStatus fillGeoFile(std::string geoFileName);
  //Separatrices stuff
  //generate separatrices with presecribed singularities - H function crosses
  HXTStatus computeSeparatricesOnExistingSing(double *directionsH);
  //generate separatrices without presecribed singularities - CR  crosses
  HXTStatus computeSeparatrices(double *directionsCR);
  HXTStatus hxtWriteSeparatricesPos(const char *fileName);
  HXTStatus hxtWriteLimitCycleCandidates(std::vector<uint64_t> *limitCycleIDs, const char *fileName);
  HXTStatus hxtWriteSavedSeparatrices(const char *fileName);
  HXTStatus hxtWriteEverything(const char *fileName);
  //Split mesh stuff
  HXTStatus splitTriMeshOnMBDecomp();
  HXTMesh* getSplitTriMeshOnMBDecomp(); 
  
  
 private:
  int m_nbTurns;
  double m_critNorm;
  double *m_crossfield;
  int m_flagTypePosCF;
  const char *m_filePosCF;
  HXTMesh *m_triMesh;
  HXTEdges *m_triEdges;
  MultiBlock *m_mBlock;
  std::vector<Singularity> m_vectSing;
  std::vector<Corner> m_vectCorner;
  std::vector<BoundaryLine> m_vectBoundaryLine;
  int m_sizeSeeding;
  std::vector<Separatrice> m_vectSep;
  std::vector<SepGroup> m_vectGroups;
  std::vector<uint64_t> m_totalElemPatches;
  std::vector<std::vector<std::array<int, 2>>> m_flaggedTri; 

  //Methods
  //1. prepareGeoFile stuff
  int triRot(uint32_t singularEdge, int triNum, int *rotationEdges, int *rotationVertices);
  HXTStatus loadDirectionFieldCR(HXTEdges *edges, const char *fileName, int nbTurns, double *crossfield);
  HXTStatus loadDirectionFieldLag(HXTEdges *edges, const char *fileName, int nbTurns, double *crossfield);
  int listSingularElements(uint64_t *masterElement, uint64_t *elemFlagged, int *sizeSingularEdges, int *elemOcc);
  int locateSingularity(uint64_t *elemFlagged, uint64_t *singularEdges, int *sizeSingularEdges, int *elemOcc);
  int getMiddleEdgeCoord(uint64_t globalEdgeNum, std::array<double,3> *coord);
  HXTStatus findSingularitiesAndCreatePatches();
  int getCornerGlobalVertexInd(std::vector<std::vector<uint64_t>> *boundaryVert2Edg, std::vector<uint64_t> *cornerIndices); 
  int cornerTri(std::vector<uint64_t> cornerIndices,  std::vector<uint64_t> *corner2Tri, int *sizeCorner2Tri);
  int cornerEdg(std::vector<std::vector<uint64_t>> *boundaryVert2Edg, std::vector<uint64_t> cornerIndices,  std::vector<uint64_t> corner2Tri, int *sizeCorner2Tri, std::vector<uint64_t> *corner2Edg, int *sizeCorner2Edg);
  int checkIfInCornerPatch(uint64_t triNum, bool *isInPatch, uint64_t *patchID);
  HXTStatus singEdgToNode(uint64_t edgNum, uint64_t  *nodeID);
  HXTStatus getBoundaryDirectionsAtCorner(std::vector<std::vector<uint64_t>> *boundaryVert2Edg);
  HXTStatus buildCorners();
  HXTStatus cleanSingularities();
  int lineLoopNodes(HXTBoundaries* boundaries, int numLineLoop, int *bdryNodes, int *numNodes, int *triangles, int *numTriangles);
  int doShiffting(int *nodes, int *numNodes, int startIndice, int *newNodes, int *triangles, int *numTriangles, int *newTriangles);
  int bdrySepLine(int *bdryNodes, int *numNodes, int *line, int *num1, int Ind1, int *Ind2, int *startingCornerID, int *endingCornerID);
  int getCornerIDFromGlobalVert(uint64_t  vertexID);
  HXTStatus createBoundaryLines();
  HXTStatus buildBoundary();
  int closestBranchInTri(uint64_t triNum, uint64_t edgNum, double *coordP, double enteringAngle, double *closestAngle);
  int isToCloseToBndryDir(int cornerID, double *dirInit);
  int seedingCorner(int sizeSeed, uint64_t edgToSeed, uint64_t triNum, double *x, int *sizeP, int cornerID);
  HXTStatus initiationFromCorner();
  int seedingPInitSep(uint64_t singEdg, uint64_t triNum, double *x, int *sizeP);
  int seedingQInitSep(uint64_t singEdg, uint64_t triNum, double *y, int *sizeQ);
  int pointP(uint64_t edgNum, uint64_t triNum, double xi, double *P, double *alpha);
  int pointQ(uint64_t edgNum, uint64_t triNum, double eta, double *Q, double *alpha);
  HXTStatus initiationFromSingularities();
  int getAllSepFromSing(int singID, std::vector<int> *separatricesIDs);
  int getAngleBetweenSep(std::array<double,3> singCoord, std::array<double,3> P1, std::array<double,3> P2, double *alpha);
  HXTStatus disableSepDuplicates(int singID);
  HXTStatus saveBdryLinesAsSeparatrices();
  int optimizeSizeofRadius(double *radius);
  int getCornerIndex(int cornerID, int *index);
  int getSingIndex(int singID, int *index);

  //2. Generate separatrices
  int isTriUsed(HXTEdges *edges, int *markedTri, uint64_t triNum);
  HXTStatus readHDirections(HXTEdges *edges, const char *filename, double *h_crossfield);
  HXTStatus writeHDirectionsEdges(HXTEdges *edges, double *h_crossfield, const char *filename);
  HXTStatus readGeoFileToBuildSingsAndCorners(std::vector<std::array<double,3>> *allCoord);
  HXTStatus constructHSingularity(int ID, std::array<double, 3> singCoord, std::vector<uint64_t> *singEdges);
  HXTStatus buildHSingularities(std::vector<std::array<double,3>> allCoord);
  HXTStatus getSingularEdges(int singID, std::vector<uint64_t> *singEdges);
  int seedingSingularity(int sizeSeed, uint64_t edgToSeed, uint64_t triNum, double *x, int *sizeP);
  HXTStatus initiationFromHSingularities();
  int isPointCorner(std::array<double,3> *point);
  std::vector<uint64_t>* getSingularityOrCornerPatch(std::array<double,3> *point);
  HXTStatus addLastPatchInIgnoredPatchs(int sepID);
  int checkIfInPatch(uint64_t triNum, std::array<double,3> *point);
  void projectDirOnTriPlan(double *dir, uint64_t triNum);
  HXTStatus linkSepToSing(Separatrice *sep, uint64_t triNum, uint64_t edgNum, std::array<double,3> singPoint, bool *discard);
  int closestPointAngle(uint64_t triNum, uint64_t edgNum, double *coordP, double enteringAngle, double *closestAngle);
  int closestDirection(uint64_t triNum, uint64_t  edgNum,  double *angleDirection,  double *direction);
  int trialPoint(uint64_t triNum, uint64_t edgNum, double *coordP, double *direction, double *pointCoord,  uint64_t *newEdgNum, double *angle);
  int correction(double *pointCoord, uint64_t triNum, uint64_t edgNum, double enteringAngle, double *direction);
  int candidatePoint(double *coordP, uint64_t triNum, uint64_t edgNum, double *alpha1, double *point, uint64_t *newTriNum, uint64_t *newEdgNum, double *alpha3);
  HXTStatus propagateKowalski(int sepID);
  HXTStatus buildIntersectionTriValues();
  int findPatchID(uint64_t triNum, uint64_t *patchID);
  int groupingSep();
  void buildTotalPatches();
  int intersectionNodeForGraph(uint64_t triNum, double *point1, double *point2, double *point3, double *point4, double *newPoint, int *flag);
  int localIntersection(int sepID1, int sepID2);
  int globalIntersection();
  int comparison();
  int checkIfInPatch2(uint64_t triNum);
  int detectLimitCycleCandidates(std::vector<uint64_t> *limitCycleIDs);
  int cutLimitCycleCandidates(std::vector<uint64_t> *limitCycleIDs);
  int solveTangentialCrossings(std::vector<uint64_t> *limitCycleIDs);





  
    
 
};



#endif

