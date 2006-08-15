// $Id: GRegion.cpp,v 1.8 2006-08-15 06:26:52 geuzaine Exp $
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

SBoundingBox3d GRegion::bounds() const
{
  std::list<GFace*>::const_iterator it = l_faces.begin();
  SBoundingBox3d res = (*it)->bounds();
  ++it;
  while(it != l_faces.end()){
    res += (*it)->bounds();  
    ++it;
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

