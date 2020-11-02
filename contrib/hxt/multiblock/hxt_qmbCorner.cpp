#include "hxt_qmbCorner.h"
#include <vector>
#include <array>

Corner::Corner() 
{
  m_ID=-1;
  m_globalVertInd=-1;
  m_coordinates={-1.,-1.,-1.};
  m_isFictive=0;
 
}

Corner::Corner(int ID,  uint64_t  globalVertInd, std::array<double,3> cornerCoord, bool isFictive, std::vector<uint64_t> patch, std::vector<uint64_t> triangles, std::vector<uint64_t> cornerEdges)
{
  m_ID=ID;
  m_globalVertInd=globalVertInd;
  m_isFictive=isFictive;
  for (uint64_t i=0; i<3; i++)
    m_coordinates[i]=cornerCoord[i];
  for (uint64_t i=0; i<patch.size(); i++)
    m_patch.push_back(patch[i]);
  for (uint64_t i=0; i<triangles.size(); i++)
    m_tri.push_back(triangles[i]);
  for (uint64_t i=0; i<cornerEdges.size(); i++)
    m_edg.push_back(cornerEdges[i]);
}
int Corner::getID()
{
  return m_ID;
}
uint64_t Corner::getGlobalVertex()
{
  return m_globalVertInd;
}
std::array<double,3> Corner::getCoord()
{
  return m_coordinates;
}
std::array<double,3>* Corner::getPCoord()
{
  return &m_coordinates;
}
std::vector<uint64_t> Corner::getPatch()
{
  return m_patch;
}
std::vector<uint64_t>* Corner::getPPatch()
{
  return &m_patch;
}
bool Corner::isFictive()
{
  return m_isFictive;
}
int Corner::setFictive()
{
  m_isFictive=1;
  return 1;
}
std::vector<uint64_t> Corner::getEdges()
{
  return m_edg;
}
std::vector<uint64_t> Corner::getTriangles()
{
  return m_tri;
}

int  Corner::addDirections(std::array<double,3> dir)
{
  m_directionsBoundary.push_back(dir);
  return 1;
}
std::vector<std::array<double,3>> Corner::getDirections()
{
  return m_directionsBoundary;
}
Corner::~Corner()
{

}
