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


std::list<GVertex*> GFace::vertices() const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  std::list<GVertex*>ret;
  while (it != l_edges.end())
    {
      GVertex *v1 = (*it)->getBeginVertex ();
      GVertex *v2 = (*it)->getEndVertex ();
      if (std::find (ret.begin(),ret.end(),v1) == ret.end())
	ret.push_back(v1);
      if (std::find (ret.begin(),ret.end(),v2) == ret.end())
	ret.push_back(v2);
      ++it;
    }
  return ret;
}
