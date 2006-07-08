#include "GRegion.h"
#include "GFace.h"

GRegion::~GRegion ()
{ 
  std::list<GFace*>::iterator it = l_faces.begin();

  while (it != l_faces.end())
    {
      (*it)->delRegion(this);
      ++it;
    }
}
