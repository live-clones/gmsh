#include "hxt_qmbSeparatrice.h"
#include <vector>
#include <array>
#include <algorithm>

Separatrice::Separatrice(int ID, std::vector<std::array<double,3>> nodesCoord, std::vector<uint64_t> triangles, std::vector<uint64_t> edges, std::vector<double> enteringAngles)
{
  m_ID=ID;
  for (uint64_t i=0; i<nodesCoord.size(); i++)
    m_nodesCoord.push_back(nodesCoord[i]);
  for (uint64_t i=0; i<triangles.size(); i++)
    m_triangles.push_back(triangles[i]);
  for (uint64_t i=0; i<edges.size(); i++)
    m_edges.push_back(edges[i]);
  for (uint64_t i=0; i<enteringAngles.size(); i++)
    m_enteringAngles.push_back(enteringAngles[i]);
  m_isSaved=1;
  m_isBoundary=0;
  m_isRemovable=0;
  m_linkAngle=0.0;
}

uint64_t Separatrice::getSizeIgnoredPatch(){
  return m_ignoredPatch.size();
}

bool Separatrice::isInIgnoredPatch(uint64_t triNum){
  if(std::find(m_ignoredPatch.begin(), m_ignoredPatch.end(), triNum) == m_ignoredPatch.end())
    return 0;
  return 1;
}

void Separatrice::addToIgnoredPatch(std::vector<uint64_t> *patch){
  for(uint64_t i=0;i<patch->size();i++)
    m_ignoredPatch.push_back((*patch)[i]);
  return;
}

void Separatrice::setIsRemovable(bool value){
  m_isRemovable=value;
  return;
}

bool Separatrice::getIsRemovable(){
  return m_isRemovable;
}

int Separatrice::getID()
{
  return m_ID;
}
std::vector<std::array<double,3>>  Separatrice::getCoord()
{
  return m_nodesCoord;
}
std::vector<std::array<double,3>>*  Separatrice::getPCoord()
{
  return &(m_nodesCoord);
}

int Separatrice::Disable()
{
  m_isSaved=0;
  return 1;
}
bool Separatrice::isSaved(){
  return  m_isSaved;
}
std::vector<uint64_t> Separatrice::getTriangles(){
  return  m_triangles;
}
std::vector<uint64_t>* Separatrice::getPTriangles(){
  return  &(m_triangles);
}
std::vector<uint64_t> Separatrice::getEdges(){
  return  m_edges;
}
std::vector<double> Separatrice::getAngles(){
  return m_enteringAngles;
}

int Separatrice::addTriangle(uint64_t triNum){
   m_triangles.push_back(triNum);
   return 1;
}
int Separatrice::addEdge(uint64_t edgNum){
   m_edges.push_back(edgNum);
   return 1;
}
int  Separatrice::addAngle(double angle){
  m_enteringAngles.push_back(angle);
  return 1;
}
int  Separatrice::addPoint(std::array<double,3> point){
  m_nodesCoord.push_back(point);
  return 1;
}

int Separatrice::addIntersectingSepID(int ID)
{
  m_intersection.push_back(ID);
  return 1;
}

std::vector<int>* Separatrice::getPIntersection()
{
  return &(m_intersection);
}

int Separatrice::setIsBoundarySep(){
  m_isBoundary=1;
  return 1;
}

int Separatrice::getLoopType(){
  return m_loopType;
}

int Separatrice::setLoopType(int type){
  m_loopType=type;
  return 1;
}

bool Separatrice::isBoundary(){
  return m_isBoundary;
}

int Separatrice::setLinkAngle(double angle){
  m_linkAngle=angle;
  return 1;
}

double Separatrice::getLinkAngle(){
  return m_linkAngle;
}
Separatrice::~Separatrice()
{

}
