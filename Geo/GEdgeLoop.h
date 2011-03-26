// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GEDGE_LOOP_H_
#define _GEDGE_LOOP_H_

#include "GEdge.h"

struct GEdgeSigned
{
  int _sign;
  GEdge *ge;
  GEdgeSigned(int i, GEdge *g) : _sign(i), ge(g) {}
  GVertex *getBeginVertex() const
  {
    return (_sign == 1) ? ge->getBeginVertex() : ge->getEndVertex();
  }
  GVertex *getEndVertex() const
  {
    return (_sign != 1) ? ge->getBeginVertex() : ge->getEndVertex();
  }
  void print() const;
  int getSign(){ return _sign; }
};

class GEdgeLoop 
{
 private:
  std::list<GEdgeSigned> loop;
 public:
  typedef std::list<GEdgeSigned>::iterator iter;
  typedef std::list<GEdgeSigned>::const_iterator citer;
  GEdgeLoop(const std::list<GEdge*> &);
  inline iter begin() { return loop.begin(); }
  inline iter end() { return loop.end(); }
  inline citer begin() const { return loop.begin(); }
  inline citer end() const { return loop.end(); }
  inline void erase(iter it){ loop.erase(it); }
  int count(GEdge*) const;
  int count() const { return loop.size(); }
};

#endif
