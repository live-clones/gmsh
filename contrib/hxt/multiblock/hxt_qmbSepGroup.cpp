#include "hxt_qmbSepGroup.h"
#include "hxt_qmbSeparatrice.h"
#include <vector>

SepGroup::SepGroup(int ID, std::vector<Separatrice*> vectSep)
{
  m_ID=ID;
  for (uint64_t i=0; i<vectSep.size(); i++)
    m_vectGroup.push_back(vectSep[i]);
}

int SepGroup::getID()
{
  return m_ID;
}

std::vector<Separatrice*>*  SepGroup::getPSeparatrices()
{
  return &(m_vectGroup);
}

SepGroup::~SepGroup()
{

}
