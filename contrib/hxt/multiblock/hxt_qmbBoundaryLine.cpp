#include "hxt_qmbBoundaryLine.h"
#include "hxt_qmbCorner.h"
#include <vector>
#include <array>

BoundaryLine::BoundaryLine()
{

}

BoundaryLine::BoundaryLine(uint64_t isALoop, std::vector<std::array<double,3>> nodesCoord, std::vector<uint64_t> triangles, Corner *pStartingCorner, Corner *pEndingCorner)
{
  m_isALoop=isALoop;
  for (uint64_t i=0; i<nodesCoord.size(); i++)
    m_nodesCoord.push_back(nodesCoord[i]);
  for (uint64_t i=0; i<triangles.size(); i++)
    m_triangles.push_back(triangles[i]);
  m_pStartingCorner=pStartingCorner;
  m_pEndingCorner=pEndingCorner;
}

std::vector<std::array<double,3>> BoundaryLine::getCoord(){
  return m_nodesCoord;
}

std::vector<uint64_t> BoundaryLine::getTriangles(){
  return m_triangles;
}
BoundaryLine::~BoundaryLine()
{

}
