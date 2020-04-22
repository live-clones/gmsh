#ifndef HXT_QMBSEPGROUP_H
#define HXT_QMBSEPGROUP_H
#include <vector>
#include "hxt_qmbSeparatrice.h"

class SepGroup
{
 public:
  SepGroup(int ID, std::vector<Separatrice*> vectSep);
  ~SepGroup();
  int getID();
  std::vector<Separatrice*>* getPSeparatrices();
 
 private:
  int m_ID;
  std::vector<Separatrice*> m_vectGroup;
 
  
};

#endif
