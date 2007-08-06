// $Id: GModel.cpp,v 1.45 2007-08-06 21:22:58 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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
#include "gmshSurface.h"
#include "Field.h"
#include "MRep.h"
#include "BackgroundMesh.h"

void GModel::destroy()
{
  std::vector<GFace*> to_keep;

  for(riter it = firstRegion(); it != lastRegion(); ++it)
    delete *it;
  regions.clear();
  for(fiter it = firstFace(); it != lastFace(); ++it){
    // projection faces are persistent
    if((*it)->geomType() == GEntity::ProjectionFace)
      to_keep.push_back(*it);
    else
      delete *it;
  }
  faces.clear();
  faces.insert(to_keep.begin(), to_keep.end());
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
  gmshSurface::reset();
  fields.reset();
  BGMReset();
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

void GModel::remove(GRegion *r) 
{ 
  riter it = std::find(firstRegion(), lastRegion(), r);
  if(it != regions.end()) regions.erase(it);
}

void GModel::remove(GFace *f) 
{ 
  fiter it = std::find(firstFace(), lastFace(), f);
  if(it != faces.end()) faces.erase(it);
}

void GModel::remove(GEdge *e) 
{ 
  eiter it = std::find(firstEdge(), lastEdge(), e);
  if(it != edges.end()) edges.erase(it);
}

void GModel::remove(GVertex *v) 
{
  viter it = std::find(firstVertex(), lastVertex(), v);
  if(it != vertices.end()) vertices.erase(it); 
}

template <class T>
static void removeInvisible(std::vector<T*> &elements, bool all)
{
  std::vector<T*> tmp;
  for(unsigned int i = 0; i < elements.size(); i++){
    if(all || !elements[i]->getVisibility()) 
      delete elements[i];
    else
      tmp.push_back(elements[i]);
  }
  elements.clear();
  elements = tmp;
}

void GModel::removeInvisibleElements()
{
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    bool all = !(*it)->getVisibility(); 
    removeInvisible((*it)->tetrahedra, all);
    removeInvisible((*it)->hexahedra, all);
    removeInvisible((*it)->prisms, all);
    removeInvisible((*it)->pyramids, all);
    if((*it)->meshRep) (*it)->meshRep->destroy();
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    bool all = !(*it)->getVisibility(); 
    removeInvisible((*it)->triangles, all);
    removeInvisible((*it)->quadrangles, all);
    if((*it)->meshRep) (*it)->meshRep->destroy();
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    bool all = !(*it)->getVisibility(); 
    removeInvisible((*it)->lines, all);
    if((*it)->meshRep) (*it)->meshRep->destroy();
  }
}

template<class T>
static void associateEntityWithElementVertices(GEntity *ge, std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++)
    for(int j = 0; j < elements[i]->getNumVertices(); j++)
      elements[i]->getVertex(j)->setEntity(ge);
}

void GModel::associateEntityWithVertices()
{
  // loop on regions, then on faces, edges and vertices and store the
  // entity pointer in the the elements' vertices (this way we
  // associate the entity of lowest geometrical degree with each
  // vertex)
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    associateEntityWithElementVertices(*it, (*it)->tetrahedra);
    associateEntityWithElementVertices(*it, (*it)->hexahedra);
    associateEntityWithElementVertices(*it, (*it)->prisms);
    associateEntityWithElementVertices(*it, (*it)->pyramids);
  }
  for(fiter it = firstFace(); it != lastFace(); ++it){
    associateEntityWithElementVertices(*it, (*it)->triangles);
    associateEntityWithElementVertices(*it, (*it)->quadrangles);
  }
  for(eiter it = firstEdge(); it != lastEdge(); ++it){
    associateEntityWithElementVertices(*it, (*it)->lines);
  }
  for(viter it = firstVertex(); it != lastVertex(); ++it){
    (*it)->mesh_vertices[0]->setEntity(*it);
  }
}

int GModel::renumberMeshVertices(bool saveAll)
{
  // tag all mesh vertices with -1 (negative vertices will not be
  // saved)
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(-1);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(-1);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(-1);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      (*it)->mesh_vertices[i]->setNum(-1);

  // tag all mesh vertices belonging to elements that need to be saved
  // with 0
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    if(saveAll || (*it)->physicals.size()){
      for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
	(*it)->mesh_vertices[i]->setNum(0);
    }
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    if(saveAll || (*it)->physicals.size()){
      for(unsigned int i = 0; i < (*it)->lines.size(); i++)
	for(int j = 0; j < (*it)->lines[i]->getNumVertices(); j++)
	  (*it)->lines[i]->getVertex(j)->setNum(0);
    }
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if(saveAll || (*it)->physicals.size()){
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
	for(int j = 0; j < (*it)->triangles[i]->getNumVertices(); j++)
	  (*it)->triangles[i]->getVertex(j)->setNum(0);
      for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
	for(int j = 0; j < (*it)->quadrangles[i]->getNumVertices(); j++)
	  (*it)->quadrangles[i]->getVertex(j)->setNum(0);
    }
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if(saveAll || (*it)->physicals.size()){
      for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
	for(int j = 0; j < (*it)->tetrahedra[i]->getNumVertices(); j++)
	  (*it)->tetrahedra[i]->getVertex(j)->setNum(0);
      for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
	for(int j = 0; j < (*it)->hexahedra[i]->getNumVertices(); j++)
	  (*it)->hexahedra[i]->getVertex(j)->setNum(0);
      for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
	for(int j = 0; j < (*it)->prisms[i]->getNumVertices(); j++)
	  (*it)->prisms[i]->getVertex(j)->setNum(0);
      for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
	for(int j = 0; j < (*it)->pyramids[i]->getNumVertices(); j++)
	  (*it)->pyramids[i]->getVertex(j)->setNum(0);
    }
  
  // renumber all the mesh vertices tagged with 0
  int numVertices = 0;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      if(!(*it)->mesh_vertices[i]->getNum())
	(*it)->mesh_vertices[i]->setNum(++numVertices);
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      if(!(*it)->mesh_vertices[i]->getNum())
	(*it)->mesh_vertices[i]->setNum(++numVertices);
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      if(!(*it)->mesh_vertices[i]->getNum())
	(*it)->mesh_vertices[i]->setNum(++numVertices);
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++) 
      if(!(*it)->mesh_vertices[i]->getNum())
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
    // physicals can be stored with negative signs when the entity
    // should be "reversed"
    int p = std::abs(ge->physicals[i]);
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

void GModel::deletePhysicalGroup(int dim, int num)
{
  switch(dim){
  case 0:
    for(viter it = firstVertex(); it != lastVertex(); ++it){
      std::vector<int> p;
      for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
	if((*it)->physicals[i] != num) p.push_back((*it)->physicals[i]);
      (*it)->physicals = p;
    }
    break;
  case 1:
    for(eiter it = firstEdge(); it != lastEdge(); ++it){
      std::vector<int> p;
      for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
	if((*it)->physicals[i] != num) p.push_back((*it)->physicals[i]);
      (*it)->physicals = p;
    }
    break;
  case 2:
    for(fiter it = firstFace(); it != lastFace(); ++it){
      std::vector<int> p;
      for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
	if((*it)->physicals[i] != num) p.push_back((*it)->physicals[i]);
      (*it)->physicals = p;
    }
    break;
  case 3:
    for(riter it = firstRegion(); it != lastRegion(); ++it){
      std::vector<int> p;
      for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
	if((*it)->physicals[i] != num) p.push_back((*it)->physicals[i]);
      (*it)->physicals = p;
    }
    break;
  }
}

int GModel::maxPhysicalNumber()
{
  int num = 0;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
      num = std::max(num, std::abs((*it)->physicals[i]));
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
      num = std::max(num, std::abs((*it)->physicals[i]));
  for(fiter it = firstFace(); it != lastFace(); ++it)
    for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
      num = std::max(num, std::abs((*it)->physicals[i]));
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    for(unsigned int i = 0; i < (*it)->physicals.size(); i++)
      num = std::max(num, std::abs((*it)->physicals[i]));
  return num;
}

int GModel::setPhysicalName(std::string name, int number)
{
  // check if the name is already used
  std::map<int, std::string>::iterator it = physicalNames.begin();
  while(it != physicalNames.end()){
    if(it->second == name) return it->first;
    ++it;
  }
  // if no number is given, find the next available one
  if(!number) number = maxPhysicalNumber() + 1;
  physicalNames[number] = name;
  return number;
}

std::string GModel::getPhysicalName(int number)
{
  return physicalNames[number];
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

int GModel::getMeshStatus(bool countDiscrete)
{
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    if((countDiscrete || (*it)->geomType() != GEntity::DiscreteVolume) && 
       ((*it)->tetrahedra.size() ||(*it)->hexahedra.size() || 
	(*it)->prisms.size() || (*it)->pyramids.size())) return 3;
  for(fiter it = firstFace(); it != lastFace(); ++it)
    if((countDiscrete || (*it)->geomType() != GEntity::DiscreteSurface) && 
       ((*it)->triangles.size() || (*it)->quadrangles.size())) return 2;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    if((countDiscrete || (*it)->geomType() != GEntity::DiscreteCurve) && 
       (*it)->lines.size()) return 1;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    if((*it)->mesh_vertices.size()) return 0;
  return -1;
}

int GModel::numVertices()
{
  int n = 0;
  for(viter it = firstVertex(); it != lastVertex(); ++it)
    n += (*it)->mesh_vertices.size();
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    n += (*it)->mesh_vertices.size();
  for(fiter it = firstFace(); it != lastFace(); ++it)
    n += (*it)->mesh_vertices.size();
  for(riter it = firstRegion(); it != lastRegion(); ++it)
    n += (*it)->mesh_vertices.size();
  return n;
}

int GModel::numElements()
{
  int n = 0;
  for(eiter it = firstEdge(); it != lastEdge(); ++it)
    n += (*it)->lines.size();
  for(fiter it = firstFace(); it != lastFace(); ++it){
    n += (*it)->triangles.size();
    n += (*it)->quadrangles.size();
  }
  for(riter it = firstRegion(); it != lastRegion(); ++it){
    n += (*it)->tetrahedra.size();
    n += (*it)->hexahedra.size();
    n += (*it)->prisms.size();
    n += (*it)->pyramids.size();
  }
  return n;
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

static int checkVertices(std::vector<MVertex*> &vertices,
			 std::set<MVertex*, MVertexLessThanLexicographic> &pos)
{
  int num = 0;
  for(unsigned int i = 0; i < vertices.size(); i++){
    MVertex *v = vertices[i];
    std::set<MVertex*, MVertexLessThanLexicographic>::iterator it = pos.find(v);
    if(it == pos.end()){
      pos.insert(v);
    }
    else{
      Msg(INFO, "Vertices %d and %d have identical position (%g, %g, %g)", 
	  (*it)->getNum(), v->getNum(), v->x(), v->y(), v->z());
      num++;
    }
  }
  return num;
}

template <class T>
static int checkElements(std::vector<T*> &elements,
			 std::set<MElement*, MElementLessThanLexicographic> &pos)
{
  int num = 0;
  for(unsigned int i = 0; i < elements.size(); i++){
    MElement *e = elements[i];
    std::set<MElement*, MVertexLessThanLexicographic>::iterator it = pos.find(e);
    if(it == pos.end()){
      pos.insert(e);
    }
    else{
      Msg(INFO, "Elements %d and %d have identical barycenter",
	  (*it)->getNum(), e->getNum());
      num++;
    }
  }
  return num;
}

void GModel::checkMeshCoherence()
{
  int numEle = numElements();
  if(!numEle) return;

  Msg(INFO, "Checking mesh coherence (%d elements)", numEle);

  SBoundingBox3d bb = bounds();
  double lc = bb.empty() ? 1. : norm(SVector3(bb.max(), bb.min()));
  double tol = CTX.geom.tolerance * lc;

  // check for duplicate mesh vertices
  {
    double old_tol = MVertexLessThanLexicographic::tolerance; 
    MVertexLessThanLexicographic::tolerance = tol;
    std::set<MVertex*, MVertexLessThanLexicographic> pos;
    int num = 0;
    for(viter it = firstVertex(); it != lastVertex(); ++it)
      num += checkVertices((*it)->mesh_vertices, pos);
    for(eiter it = firstEdge(); it != lastEdge(); ++it)
      num += checkVertices((*it)->mesh_vertices, pos);
    for(fiter it = firstFace(); it != lastFace(); ++it)
      num += checkVertices((*it)->mesh_vertices, pos);
    for(riter it = firstRegion(); it != lastRegion(); ++it)
      num += checkVertices((*it)->mesh_vertices, pos);
    if(num) Msg(WARNING, "%d duplicate vertices", num);
    MVertexLessThanLexicographic::tolerance = old_tol;
  }

  // check for duplicate elements
  {
    double old_tol = MElementLessThanLexicographic::tolerance; 
    MElementLessThanLexicographic::tolerance = tol;
    std::set<MElement*, MElementLessThanLexicographic> pos;
    int num = 0;
    for(eiter it = firstEdge(); it != lastEdge(); ++it)
      num += checkElements((*it)->lines, pos);
    for(fiter it = firstFace(); it != lastFace(); ++it){
      num += checkElements((*it)->triangles, pos);
      num += checkElements((*it)->quadrangles, pos);
    }
    for(riter it = firstRegion(); it != lastRegion(); ++it){
      num += checkElements((*it)->tetrahedra, pos);
      num += checkElements((*it)->hexahedra, pos);
      num += checkElements((*it)->prisms, pos);
      num += checkElements((*it)->pyramids, pos);
    }
    if(num) Msg(WARNING, "%d duplicate elements", num);
    MElementLessThanLexicographic::tolerance = old_tol;
  }

}
