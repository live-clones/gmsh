// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "MElement.h"
#include "Message.h"

GRegion::GRegion(GModel *model, int tag) : GEntity (model, tag)
{
  resetMeshAttributes();
}

GRegion::~GRegion()
{
  std::list<GFace*>::iterator it = l_faces.begin();
  while(it != l_faces.end()){
    (*it)->delRegion(this);
    ++it;
  }

  for(unsigned int i = 0; i < mesh_vertices.size(); i++)
    delete mesh_vertices[i];

  for(unsigned int i = 0; i < tetrahedra.size(); i++)
    delete tetrahedra[i];

  for(unsigned int i = 0; i < hexahedra.size(); i++)
    delete hexahedra[i];

  for(unsigned int i = 0; i < prisms.size(); i++)
    delete prisms[i];

  for(unsigned int i = 0; i < pyramids.size(); i++)
    delete pyramids[i];
}

unsigned int GRegion::getNumMeshElements()
{ 
  return tetrahedra.size() + hexahedra.size() + prisms.size() + pyramids.size();
}

void GRegion::getNumMeshElements(unsigned *const c) const
{
  c[0] += tetrahedra.size();
  c[1] += hexahedra.size();
  c[2] += prisms.size();
  c[3] += pyramids.size();
}

MElement *const *GRegion::getStartElementType(int type) const
{
  switch(type) {
  case 0:
    return reinterpret_cast<MElement *const *>(&tetrahedra[0]);
  case 1:
    return reinterpret_cast<MElement *const *>(&hexahedra[0]);
  case 2:
    return reinterpret_cast<MElement *const *>(&prisms[0]);
  case 3:
    return reinterpret_cast<MElement *const *>(&pyramids[0]);
  }
  return 0;
}

MElement *GRegion::getMeshElement(unsigned int index)
{ 
  if(index < tetrahedra.size())
    return tetrahedra[index];
  else if(index < tetrahedra.size() + hexahedra.size())
    return hexahedra[index - tetrahedra.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size())
    return prisms[index - tetrahedra.size() - hexahedra.size()];
  else if(index < tetrahedra.size() + hexahedra.size() + prisms.size() + pyramids.size())
    return pyramids[index - tetrahedra.size() - hexahedra.size() - prisms.size()];
  return 0;
}

void GRegion::resetMeshAttributes()
{
  meshAttributes.Method = MESH_UNSTRUCTURED;
  meshAttributes.extrude = 0;
}

SBoundingBox3d GRegion::bounds() const
{
  SBoundingBox3d res;
  if(geomType() != DiscreteVolume){
    std::list<GFace*>::const_iterator it = l_faces.begin();
    for(; it != l_faces.end(); it++)
      res += (*it)->bounds();
  }
  else{
    for(unsigned int i = 0; i < mesh_vertices.size(); i++)
      res += mesh_vertices[i]->point();
  }
  return res;
}

void GRegion::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive){
    std::list<GFace*>::iterator it = l_faces.begin();
    while(it != l_faces.end()){
      (*it)->setVisibility(val, recursive);
      ++it;
    }
  }
}

std::string GRegion::getAdditionalInfoString()
{
  std::ostringstream sstream;
  if(l_faces.size() > 20){
    sstream << "{" << l_faces.front()->tag() << ",...," << l_faces.back()->tag() << "}";
  }
  else if(l_faces.size()){
    sstream << "{";
    for(std::list<GFace*>::iterator it = l_faces.begin(); it != l_faces.end(); ++it){
      if(it != l_faces.begin()) sstream << ",";
      sstream << (*it)->tag();
    }
    sstream << "}";
  }
  return sstream.str();
}

std::list<GEdge*> GRegion::edges() const
{
  std::list<GEdge*> e;
  std::list<GFace*>::const_iterator it = l_faces.begin();
  while(it != l_faces.end()){
    std::list<GEdge*> e2;
    e2 = (*it)->edges();
    std::list<GEdge*>::const_iterator it2 = e2.begin();
    while (it2 != e2.end()){
      if(std::find(e.begin(), e.end(), *it2) == e.end())
        e.push_back(*it2);
      ++it2;
    }
    ++it;
  }
  return e;
}

bool GRegion::edgeConnected(GRegion *r) const
{
  std::list<GEdge*> e = edges();
  std::list<GEdge*> e2 = r->edges();

  std::list<GEdge*>::const_iterator it = e.begin();
  while(it != e.end()){
    if(std::find(e2.begin(), e2.end(), *it) != e2.end())
      return true;
    ++it;
  }
  return false;
}
