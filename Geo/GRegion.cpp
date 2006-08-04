#include "GRegion.h"
#include "GFace.h"

GRegion::~GRegion ()
{ 
  std::list<GFace*>::iterator it = l_faces.begin();

  while(it != l_faces.end()){
    (*it)->delRegion(this);
    ++it;
  }

  for(unsigned int i = 0; i < mesh_vertices.size(); i++) 
    delete mesh_vertices[i];
  mesh_vertices.clear();

  for(unsigned int i = 0; i < tetrahedra.size(); i++) 
    delete tetrahedra[i];
  tetrahedra.clear();

  for(unsigned int i = 0; i < hexahedra.size(); i++) 
    delete hexahedra[i];
  hexahedra.clear();

  for(unsigned int i = 0; i < prisms.size(); i++) 
    delete prisms[i];
  prisms.clear();

  for(unsigned int i = 0; i < pyramids.size(); i++) 
    delete pyramids[i];
  pyramids.clear();
}
