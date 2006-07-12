#include "GEdge.h"
#include "GmshDefines.h"
#include <algorithm>

void GEdge::addFace ( GFace *e )
{ 
  l_faces.push_back (e);  
}

void GEdge::delFace ( GFace *e )
{ 
  l_faces.erase(std::find(l_faces.begin(),l_faces.end(),e));  
}

GEdge::GEdge(GModel *model, 
      int tag, 
      GVertex *_v0, 
      GVertex *_v1)
  : GEntity (model,tag),v0(_v0),v1(_v1)
{
  v0->addEdge (this);
  v1->addEdge (this);
  meshAttributes.Method = LIBRE; 
}

GEdge::~GEdge() 
{
  v0->delEdge (this);
  v1->delEdge (this);
}

