// $Id: GRegion.cpp,v 1.12 2006-10-12 01:35:32 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"

GRegion::GRegion(GModel *model, int tag) : GEntity (model, tag)
{
  meshAttributes.Method = LIBRE; 
  meshAttributes.extrude = 0;
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

void GRegion::recomputeMeshPartitions()
{
  for(unsigned int i = 0; i < tetrahedra.size(); i++) {
    int part = tetrahedra[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
  for(unsigned int i = 0; i < hexahedra.size(); i++) {
    int part = hexahedra[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
  for(unsigned int i = 0; i < prisms.size(); i++) {
    int part = prisms[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
  for(unsigned int i = 0; i < pyramids.size(); i++) {
    int part = pyramids[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
}

void GRegion::deleteMeshPartitions()
{
  for(unsigned int i = 0; i < tetrahedra.size(); i++)
    tetrahedra[i]->setPartition(0);
  for(unsigned int i = 0; i < hexahedra.size(); i++)
    hexahedra[i]->setPartition(0);
  for(unsigned int i = 0; i < prisms.size(); i++)
    prisms[i]->setPartition(0);
  for(unsigned int i = 0; i < pyramids.size(); i++)
    pyramids[i]->setPartition(0);
}

std::list<GEdge*> GRegion::edges() const
{
  std::list<GEdge*> e;
  std::list<GFace *>::const_iterator it =  l_faces.begin();
  while(it != l_faces.end()){
    std::list<GEdge*> e2;
    e2 = (*it)->edges();
    std::list<GEdge*>::const_iterator it2 = e2.begin();
    while (it2 != e2.end()){
      if (std::find(e.begin(),e.end(),*it2) == e.end())
	e.push_back(*it2);
      ++it2;
    }
    ++it;
  }
  return e;
}
