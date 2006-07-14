#ifndef _GEDGE_LOOP_H_
#define _GEDGE_LOOP_H_

#include <list>

class GEdgeLoop
{
 private:
  std::list<GEdge*> loop;
  std::list<int>    dirs;
 public :
  GEdgeLoop (const std::list<GEdge*> & l,   const std::list<int> & d)
    : loop (l) , dirs (d)
  {
  }
};

#endif
