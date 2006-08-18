// $Id: GModel.cpp,v 1.13 2006-08-18 17:49:35 geuzaine Exp $
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

void GModel::destroy()
{
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    delete *it;
  regions.clear();
  for(fiter it = firstFace(); it != lastFace(); ++it)
    delete *it;
  faces.clear();
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    delete *it;
  edges.clear();
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    delete *it;
  vertices.clear();
  if(normals) delete normals;
  normals = 0;
  MVertex::resetGlobalNumber();
  MElement::resetGlobalNumber();
}

GRegion * GModel::regionByTag(int n) const
{
  GEntity tmp((GModel*)this, n);
  riter it = regions.find((GRegion*)&tmp);
  if(it != regions.end())
    return *it;
  else
    return 0;
}

GFace * GModel::faceByTag(int n) const
{
  GEntity tmp((GModel*)this, n);
  fiter it = faces.find((GFace*)&tmp);
  if(it != faces.end())
    return *it;
  else
    return 0;
}

GEdge * GModel::edgeByTag(int n) const
{
  GEntity tmp((GModel*)this, n);
  eiter it = edges.find((GEdge*)&tmp);
  if(it != edges.end())
    return *it;
  else
    return 0;
}

GVertex * GModel::vertexByTag(int n) const
{
  GEntity tmp((GModel*)this, n);
  viter it = vertices.find((GVertex*)&tmp);
  if(it != vertices.end())
    return *it;
  else
    return 0;
}

int GModel::renumberMeshVertices()
{
  int numVertices = 0;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(++numVertices);
  return numVertices;
}

bool GModel::noPhysicalGroups()
{
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    if((*it)->physicals.size()) return false;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    if((*it)->physicals.size()) return false;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if((*it)->physicals.size()) return false;
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if((*it)->physicals.size()) return false;
  return true;
}

static void addInGroup(GEntity* ge, std::map<int, std::vector<GEntity*> > &group)
{
  for(unsigned int i = 0; i < ge->physicals.size(); i++){
    int p = ge->physicals[i];
    if(std::find(group[p].begin(), group[p].end(), ge) == group[p].end())
      group[p].push_back(ge);
  }
}

void GModel::getPhysicalGroups(std::map<int, std::vector<GEntity*> > groups[4])
{
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    addInGroup(*it, groups[0]);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    addInGroup(*it, groups[1]);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    addInGroup(*it, groups[2]);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    addInGroup(*it, groups[3]);
}

void GModel::deletePhysicalGroups()
{
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    (*it)->physicals.clear();
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    (*it)->physicals.clear();
  for(fiter it = firstFace(); it != lastFace(); ++it)
    (*it)->physicals.clear();
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    (*it)->physicals.clear();
}

SBoundingBox3d GModel::bounds()
{
  SBoundingBox3d bb;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    bb += (*it)->bounds();

  // use the mesh instead of the geometry for now
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      bb += (*it)->mesh_vertices[i]->point();
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      bb += (*it)->mesh_vertices[i]->point();
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
      bb += (*it)->mesh_vertices[i]->point();

  return bb;
}

int GModel::getMeshStatus()
{
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if((*it)->mesh_vertices.size()) return 3;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if((*it)->mesh_vertices.size()) return 2;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    if((*it)->mesh_vertices.size()) return 1;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    if((*it)->mesh_vertices.size()) return 0;
  return -1;
}

std::set<int> &GModel::recomputeMeshPartitions()
{
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    (*it)->recomputeMeshPartitions();
  for(fiter it = firstFace(); it != lastFace(); ++it)
    (*it)->recomputeMeshPartitions();
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    (*it)->recomputeMeshPartitions();
  return meshPartitions;
}

void GModel::deleteMeshPartitions()
{
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    (*it)->deleteMeshPartitions();
  for(fiter it = firstFace(); it != lastFace(); ++it)
    (*it)->deleteMeshPartitions();
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    (*it)->deleteMeshPartitions();
  meshPartitions.clear();
}
