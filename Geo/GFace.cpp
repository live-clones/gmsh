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
