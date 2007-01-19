#ifndef _GEDGELOOP_H_
#define _GEDGELOOP_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include "GEdge.h"
#include <list>

struct GEdgeSigned
{
  int _sign;
  GEdge *ge;
  GEdgeSigned ( int i, GEdge*g ) 
    : _sign(i) , ge(g)
  {}
  GVertex * getBeginVertex() const
  {
    return (_sign==1)?ge->getBeginVertex():ge->getEndVertex();
  }
  GVertex * getEndVertex() const
  {
    return (_sign!=1)?ge->getBeginVertex():ge->getEndVertex();
  }
  void print() const;
  int getSign(){return _sign;}
};

class GEdgeLoop 
{
public:
  typedef std::list<GEdgeSigned>::iterator iter;
  typedef std::list<GEdgeSigned>::const_iterator citer;
  GEdgeLoop ( const std::list<GEdge*> &);
  inline iter begin () {return loop.begin();}
  inline iter end   () {return loop.end();}
  inline citer begin () const {return loop.begin();}
  inline citer end   () const {return loop.end();}
  int  count (GEdge*) const;
  int  count () const {return loop.size();}
private:
  std::list< GEdgeSigned > loop ;
};




#endif
