#include "GEdge.h"
#include <algorithm>
void GEdge::addFace ( GFace *e )
{ 
  l_faces.push_back (e);  
}
void GEdge::delFace ( GFace *e )
{ 
  l_faces.erase(std::find(l_faces.begin(),l_faces.end(),e));  
}
