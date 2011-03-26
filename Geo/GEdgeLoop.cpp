// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <algorithm>
#include <functional>
#include "GEdgeLoop.h"
#include "GmshMessage.h"

void GEdgeSigned::print() const
{
  Msg::Info("GEdgeSigned : Edge %d sign %d Ordered Vertices %d,%d",
            ge->tag(), _sign, getBeginVertex()->tag(), getEndVertex()->tag());
}

int countInList(std::list<GEdge*> &wire, GEdge *ge)
{
  std::list<GEdge*>::iterator it = wire.begin();
  std::list<GEdge*>::iterator ite = wire.end();
  int count = 0;
  while(it != ite){
    if(*it == ge) count++; 
    ++it;
  }
  return count;
}

GEdgeSigned nextOne(GEdgeSigned *thisOne, std::list<GEdge*> &wire)
{
  if(!thisOne){
    GEdge *ge = *(wire.begin());
    wire.erase(wire.begin());
    return GEdgeSigned(1, ge);   
  }

  GVertex *gv = thisOne->getEndVertex();

  std::list<GEdge*> possibleChoices;

  std::list<GEdge*>::iterator it = wire.begin();
  std::list<GEdge*>::iterator ite = wire.end();
  while(it != ite){
    GEdge *ge = *it;
    GVertex *v1 = ge->getBeginVertex();
    GVertex *v2 = ge->getEndVertex();
    if(v1 == gv || v2 == gv) possibleChoices.push_back(ge);
    ++it;
  }
  it = possibleChoices.begin();
  ite = possibleChoices.end();
  while(it != ite){
    GEdge *ge = *it;
    if(countInList(possibleChoices, ge) == 2){
      wire.erase(std::remove_if(wire.begin(), wire.end(), 
                                std::bind2nd(std::equal_to<GEdge*>(), ge)), 
                 wire.end());
      wire.push_back(ge);
      GVertex *v1 = ge->getBeginVertex();
      GVertex *v2 = ge->getEndVertex();
      if(v1 == gv) return GEdgeSigned(1, ge);   
      if(v2 == gv) return GEdgeSigned(-1, ge);   
      Msg::Error("Something wrong in edge loop");
      thisOne->print();
    }
    ++it;
  }
  it = possibleChoices.begin();
  ite = possibleChoices.end();
  while(it != ite){
    GEdge *ge = *it;
    if(ge != thisOne->ge){
      wire.erase(std::remove_if(wire.begin(),wire.end(), 
                                std::bind2nd(std::equal_to<GEdge*>(), ge)), 
                 wire.end());
      GVertex *v1 = ge->getBeginVertex();
      GVertex *v2 = ge->getEndVertex();
      if(v1 == gv) return GEdgeSigned(1, ge);   
      if(v2 == gv) return GEdgeSigned(-1, ge);
      Msg::Error("Something wrong in edge loop");
      thisOne->print();
    }   
    ++it;
  }
  
  // should never end up here
  return GEdgeSigned(0, 0);
}

int GEdgeLoop::count(GEdge* ge) const
{
  GEdgeLoop::citer it = begin();
  GEdgeLoop::citer ite = end();
  int count = 0;
  while(it != ite){
    if(it->ge == ge) count++; 
    ++it;
  }
  return count;
}

GEdgeLoop::GEdgeLoop(const std::list<GEdge*> &cwire)
{
  std::list<GEdge*> wire(cwire);

  GEdgeSigned *prevOne = 0;

  GEdgeSigned ges(0,0);
  while(wire.size()){
    ges = nextOne(prevOne, wire);
    if(ges.getSign() == 0){ // oops
      Msg::Error("Something wrong in edge loop of size=%d, no sign !", wire.size());
      for (std::list<GEdge* >::iterator it = wire.begin(); it != wire.end(); it++){
	printf("GEdge=%d begin=%d end =%d \n", (*it)->tag(), (*it)->getBeginVertex()->tag(), (*it)->getEndVertex()->tag()  );
      }
      break;
    }
    prevOne = &ges;
    // ges.print();
    loop.push_back(ges);
  }
}

