// $Id: GEdgeLoop.cpp,v 1.16 2008-07-03 17:06:01 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <algorithm>
#include <functional>
#include "GEdgeLoop.h"

#if defined(HAVE_GMSH_EMBEDDED)
#  include "GmshEmbedded.h"
#else
#  include "Message.h"
#endif

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
      Msg::Error("Something wrong in edge loop");
      break;
    }
    prevOne = &ges;
    // ges.print();
    loop.push_back(ges);
  }
}


GEdgeLoop::GEdgeLoop(const std::list<GEdge*> &cwire, const std::list<int> &dir)
{
  std::list<GEdge*>::const_iterator it = cwire.begin();
  std::list<int>::const_iterator itdir = dir.begin();
  for ( ; it != cwire.end() ; ++it,++itdir){
    loop.push_back(GEdgeSigned(*itdir,*it));
  }
}

