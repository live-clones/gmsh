//
// C++ Interface: terms
//
// Description: Class to manage the creation of interface
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "InterfaceBuilder.h"
#include "partDomain.h"
unsigned long int manageInterface::getKey(partDomain* dom1, partDomain *dom2){
  int i1 = dom1->getPhysical();
  int i2 = dom2->getPhysical();
  return manageInterface::getKey(i1,i2);
}

void manageInterface::insert(IElement *iele,partDomain *dom)
{
  unsigned long int key = iele->getkey();
  IelementContainer::iterator it_edge=mapinter.find(key);
  if((it_edge == mapinter.end()) or (iele->getType() != it_edge->second->getType()))
    mapinter.insert(IelementPart(key,iele));
  else{ // create the interface
    MElement *interel =  dom->createInterface(iele,it_edge->second);
    this->createinter(interel,iele,it_edge->second->getPhys());
  }
}

void manageInterface::createinter(MElement *iele, IElement *ie, const int phys2)
{
  unsigned int physkey = manageInterface::getKey(ie->getPhys(),phys2);
  #ifdef _DEBUG
   bool findi = false;
  #endif
  for(std::vector<partDomain*>::iterator it = _vdom->begin(); it!=_vdom->end(); ++it){
    partDomain *dom = *it;
    if(dom->getPhysical() == physkey){
      dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(dom);
      dgdom->gi->insert(iele);
      #ifdef _DEBUG
       findi=true;
      #endif
    }
  }
  #ifdef _DEBUG
   if(!findi)
     Msg::Error("Error with the creation of interfaceelement. It seems that an Interface element is not include in any domain");
  #endif
  if(physkey != phys2){
    // search domain
    for(std::vector<partDomain*>::iterator it = _vdom->begin(); it!=_vdom->end(); ++it){
      partDomain *dom = *it;
      if(dom->getPhysical() == ie->getPhys()){
        dgPartDomain *dgdom = dynamic_cast<dgPartDomain*>(dom);
        MElement* interel = dgdom->createVirtualInterface(ie);
        dgdom->giv->insert(interel);
      }
    }
  }
  else{
    this->erase(ie);
  }
}
