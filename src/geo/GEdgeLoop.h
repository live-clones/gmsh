// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GEDGE_LOOP_H
#define GEDGE_LOOP_H

#include "GEdge.h"
#include "GmshMessage.h"

class GEdgeSigned {
private:
  int _sign;
  GEdge *_ge;
public:
  GEdgeSigned(int sign, GEdge *ge) : _sign(sign), _ge(ge)
  {
    if(_sign != 1 && _sign != -1)
      Msg::Error("Edge sign should be 1 or -1");
  }
  GVertex *getBeginVertex() const
  {
    return (_sign == 1) ? _ge->getBeginVertex() : _ge->getEndVertex();
  }
  GVertex *getEndVertex() const
  {
    return (_sign == 1) ? _ge->getEndVertex() : _ge->getBeginVertex();
  }
  void print() const;
  int getSign() const { return _sign; }
  GEdge *getEdge() const { return _ge; }
  void changeSign() { _sign *= -1; }
};

class GEdgeLoop {
private:
  std::list<GEdgeSigned> loop;

public:
  typedef std::list<GEdgeSigned>::iterator iter;
  typedef std::list<GEdgeSigned>::const_iterator citer;
  GEdgeLoop() {}
  GEdgeLoop(const std::vector<GEdge *> &wire);
  bool check();
  void add(int ori, GEdge *ge) { loop.push_back(GEdgeSigned(ori, ge)); }
  void recompute(const std::vector<GEdge *> &wire);
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
  void reverse();
};

#endif
