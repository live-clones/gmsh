#ifndef _EDGE_LOOP_H_
#define _EDGE_LOOP_H_
#include <list>

class GEdgeLoop
{
  std::list<GEdge*> loop;
  std::list<int>    dirs;
public :
  GEdgeLoop (const std::list<GEdge*> & l,   const std::list<int> & d)
    : loop (l) , dirs (d)
  {
  }
};
#endif
