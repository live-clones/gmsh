// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GEDGE_LOOP_H
#define GEDGE_LOOP_H

#include "GEdge.h"

class GEdgeSigned {
public:
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
  int getSign() const { return _sign; }
  GEdge *getEdge() const { return ge; }
};

class GEdgeLoop {
private:
  std::list<GEdgeSigned> loop;

public:
  typedef std::list<GEdgeSigned>::iterator iter;
  typedef std::list<GEdgeSigned>::const_iterator citer;
  GEdgeLoop(const std::vector<GEdge *> &);
  inline iter begin() { return loop.begin(); }
  inline iter end() { return loop.end(); }
  inline citer begin() const { return loop.begin(); }
  inline citer end() const { return loop.end(); }
  inline void erase(iter it) { loop.erase(it); }
  int count(GEdge *) const;
  int count() const { return (int)loop.size(); }
  void print() const;
  void getEdges(std::vector<GEdge *> &edges) const;
  void getSigns(std::vector<int> &signs) const;
};

#endif
