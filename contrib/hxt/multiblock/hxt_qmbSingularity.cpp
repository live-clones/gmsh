#include "hxt_qmbSingularity.h"
#include <vector>
#include <array>

Singularity::Singularity()
{
  m_ID=-1;
  m_isDisabled=0;
  m_globalEdgId=-1;
  m_type=-1; //crossfiel sing 1, corner 0
  m_coordinates={-1.,-1.,-1.};
}

Singularity::Singularity(int ID, uint64_t  globalEdgID,std::array<double,3> singCoord, std::vector<uint64_t> patch)
{
  m_ID=ID;
  m_isDisabled=0;
  m_globalEdgId=globalEdgID;
  m_type=1; //crossfield sing 1, corner 0
  for (uint64_t i=0; i<3; i++)
    m_coordinates[i]=singCoord[i];
  for (uint64_t i=0; i<patch.size(); i++)
    m_patch.push_back(patch[i]);
}

int Singularity::getID()
{
  return m_ID;
}
std::array<double,3> Singularity::getCoord()
{
  return m_coordinates;
}
std::array<double,3>* Singularity::getPCoord()
{
  return &m_coordinates;
}
std::vector<uint64_t> Singularity::getPatch()
{
  return m_patch;
}
std::vector<uint64_t>* Singularity::getPPatch()
{
  return &m_patch;
}
uint64_t  Singularity::getGlobalEdg()
{
  return m_globalEdgId;
}
int Singularity::setIsDisabled(){
  m_isDisabled=1;
  return 1;
}
bool Singularity::isDisabled()
{
  return m_isDisabled;
}

Singularity::~Singularity()
{

}
