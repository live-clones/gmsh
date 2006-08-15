#ifndef _MEDGE_H_
#define _MEDGE_H_

#include <algorithm>
#include "MVertex.h"

class MElement;

class MEdge {
 private:
  MVertex *_v[2];
  
  // Storing a pointer to (one of the) originating elements is a
  // significant overhead, especially since I only use it to get a
  // crude normal (for graphic purposes) or to know (one of) the
  // adjacent mesh partitions. I will try to come up with something
  // better later.
  MElement *_element;
  
 public:
  MEdge(MVertex *v0, MVertex *v1, MElement *e) 
    : _element(e)
  {
    _v[0] = v0; _v[1] = v1;
  }
  inline MVertex *getVertex(int i) const { return _v[i]; }
  inline MElement *getElement() const { return _element; }
};

class MEdgeLessThan {
 public:
  bool operator()(const MEdge &e1, const MEdge &e2) const
  {
    int e10 = e1.getVertex(0)->getNum();
    int e11 = e1.getVertex(1)->getNum();
    int e20 = e2.getVertex(0)->getNum();
    int e21 = e2.getVertex(1)->getNum();
    int i1 = std::min(e10, e11);
    int i2 = std::min(e20, e21);
    if(i1 < i2)
      return true;
    if(i1 > i2)
      return false;
    int j1 = std::max(e10, e11);
    int j2 = std::max(e20, e21);
    if(j1 < j2)
      return true;
    return false;
  }
};

#endif
