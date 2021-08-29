#include "hxt_qmbFeatureLine.h"
//#include "hxt_qmbSingularity.h"
#include <vector>
#include <array>

FeatureLine::FeatureLine()
{

}

//FeatureLine::FeatureLine(uint64_t isLoop, std::vector<std::array<double,3>> nodesCoord, std::vector<uint64_t> triangles, std::vector<uint64_t> edges, Singularity *pStartSing, Singularity *pEndSing)
FeatureLine::FeatureLine(uint64_t isLoop, std::vector<std::array<double,3>> nodesCoord, std::vector<uint64_t> triangles, std::vector<uint64_t> edges, uint32_t startNode, uint32_t endNode)
{
  m_isLoop=isLoop;
  for (uint64_t i=0; i<nodesCoord.size(); i++)
    m_nodesCoord.push_back(nodesCoord[i]);
  for (uint64_t i=0; i<triangles.size(); i++)
    m_triangles.push_back(triangles[i]);
  for (uint64_t i=0; i<edges.size(); i++)
    m_edges.push_back(edges[i]);
  m_startNode=startNode;
  m_endNode=endNode;
  // m_pStartSing=pStartSing;
  // m_pEndSing=pEndSing;
}

std::vector<std::array<double,3>> FeatureLine::getCoord(){
  return m_nodesCoord;
}

std::vector<uint64_t> FeatureLine::getTriangles(){
  return m_triangles;
}

std::vector<uint64_t> FeatureLine::getEdges(){
  return m_edges;
}

uint64_t FeatureLine::getIsLoop(){
  return m_isLoop;
}

uint32_t FeatureLine::getStartNode(){
  return m_startNode;
}

uint32_t FeatureLine::getEndNode(){
  return m_endNode;
}

FeatureLine::~FeatureLine()
{

}
