#include "GFace.h"
#include "GEdge.h"

GFace::~GFace ()
{ 
  std::list<GEdge*>::iterator it = l_edges.begin();

  while (it != l_edges.end())
    {
      (*it)->delFace(this);
      ++it;
    }
}


void GFace::buildEdgeLoops ()
{
  std::list<GEdge*>::iterator it = l_edges.begin();
  std::list<int>::iterator itd   = l_dirs.begin();
  for ( ; it != l_edges.end() ; ++it , ++itd )
    {  
      std::list <GEdge *>loop;
      std::list <int>    loop_dir;
      GVertex *start = (*itd == 1) ?(*it)->getBeginVertex ():(*it)->getEndVertex ();
      GVertex *end =   (*itd == -1) ?(*it)->getBeginVertex ():(*it)->getEndVertex ();
    }
  
}
