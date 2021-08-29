#ifndef HXT_QMBFEATURELINE_H
#define HXT_QMBFEATURELINE_H
#include <cstdint>
#include <vector>
//#include "hxt_qmbSingularity.h"
#include <array>

class FeatureLine
{
 public:
  FeatureLine();
  //FeatureLine(uint64_t isLoop, std::vector<std::array<double,3>> nodesCoord, std::vector<uint64_t> triangles, std::vector<uint64_t> edges, Singularity *pStartSing, Singularity *pEndSing);
  FeatureLine(uint64_t isLoop, std::vector<std::array<double,3>> nodesCoord, std::vector<uint64_t> triangles, std::vector<uint64_t> edges, uint32_t startNode, uint32_t endNode);
  std::vector<std::array<double,3>> getCoord();
  std::vector<uint64_t> getTriangles();
  std::vector<uint64_t> getEdges();
  uint64_t getIsLoop();
  uint32_t getStartNode();
  uint32_t getEndNode();
  ~FeatureLine();
  
private:
  uint64_t m_isLoop; //0 not a loop, 1 is loop, 2 is loop starting and ending at singularity
  std::vector<std::array<double,3>> m_nodesCoord;
  std::vector<uint64_t> m_triangles;
  std::vector<uint64_t> m_edges;
  uint32_t m_startNode;
  uint32_t m_endNode; 
  // Singularity *m_pStartSing;
  // Singularity *m_pEndSing;
};

#endif
