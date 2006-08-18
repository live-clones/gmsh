// $Id: Visibility.cpp,v 1.17 2006-08-18 02:22:40 geuzaine Exp $
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

#include "Visibility.h"
#include "GModel.h"
#include "Parser.h" // for Symbol_T

extern GModel *GMODEL;

VisibilityManager *VisibilityManager::manager = 0;

class VisLessThan{
 public:
  bool operator()(const Vis *v1, const Vis *v2) const
  {
    switch(VisibilityManager::instance()->getSortMode()){
    case  1: return v1->getDim() < v2->getDim() ? true : false;
    case -1: return v1->getDim() > v2->getDim() ? true : false;
    case  2: return v1->getTag() < v2->getTag() ? true : false;
    case -2: return v1->getTag() > v2->getTag() ? true : false;
    case  3: 
      return strcmp(VisibilityManager::instance()->getLabel(v1->getTag()).c_str(), 
		    VisibilityManager::instance()->getLabel(v2->getTag()).c_str()) < 0 ? 
	true : false;
    default: 
      return strcmp(VisibilityManager::instance()->getLabel(v1->getTag()).c_str(), 
		    VisibilityManager::instance()->getLabel(v2->getTag()).c_str()) > 0 ? 
	true : false;
    }
  }
};

static void setLabels(void *a, void *b){
  Symbol *s = (Symbol *)a;
  for(int j = 0; j < List_Nbr(s->val); j++) {
    double tag;
    List_Read(s->val, j, &tag);
    VisibilityManager::instance()->setLabel((int)tag, std::string(s->Name));
  }
}

void VisibilityManager::update(int type)
{
  _labels.clear();
  Tree_Action(Symbol_T, setLabels);

  for(unsigned int i = 0; i < _entities.size(); i++)
    delete _entities[i];
  _entities.clear();
  
  if(type == 0){ // elementary entities
    for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); it++)
      _entities.push_back(new VisElementary(*it));
    for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++)
      _entities.push_back(new VisElementary(*it));
    for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
      _entities.push_back(new VisElementary(*it));
    for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++)
      _entities.push_back(new VisElementary(*it));
  }
  else if(type == 1){ // physical entities
    std::map<int, std::vector<GEntity*> > groups[4];
    GMODEL->getPhysicalGroups(groups);
    for(int i = 0; i < 4; i++){
      std::map<int, std::vector<GEntity*> >::const_iterator it = groups[i].begin();
      for(; it != groups[i].end(); ++it)
	_entities.push_back(new VisPhysical(it->first, i, it->second));
    }
  }
  else if(type == 2){ // partitions
    std::set<int> part = GMODEL->getMeshPartitions();
    for(std::set<int>::const_iterator it = part.begin(); it != part.end(); ++it)
      _entities.push_back(new VisPartition(*it));
  }
  std::sort(_entities.begin(), _entities.end(), VisLessThan());
}

void VisibilityManager::setAllInvisible(int type)
{
  if(type == 0 || type == 1){
    // elementary or physical mode: set all entities in the model invisible
    for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); it++)
      (*it)->setVisibility(false);
    for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++)
      (*it)->setVisibility(false);
    for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
      (*it)->setVisibility(false);
    for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++)
      (*it)->setVisibility(false);
  }

  // this is superfluous in elementary mode, but we don't care
  for(int i = 0; i < getNumEntities(); i++) setVisibility(i, false);
}

std::string VisibilityManager::getBrowserLine(int n)
{
  int tag = _entities[n]->getTag();
  char str[256];
  sprintf(str, "\t%s\t%d\t%s", _entities[n]->getName().c_str(), tag, 
	  _labels.count(tag) ? _labels[tag].c_str() : "");
  return std::string(str);
}

std::string VisibilityManager::getStringForGEO()
{
  std::vector<int> state[4][2];

  for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); it++)
    (*it)->getVisibility() ?
      state[0][1].push_back((*it)->tag()) : state[0][0].push_back((*it)->tag());
  for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++)
    (*it)->getVisibility() ? 
      state[1][1].push_back((*it)->tag()) : state[1][0].push_back((*it)->tag());
  for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
    (*it)->getVisibility() ? 
      state[2][1].push_back((*it)->tag()) : state[2][0].push_back((*it)->tag());
  for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++)
    (*it)->getVisibility() ? 
      state[3][1].push_back((*it)->tag()) : state[3][0].push_back((*it)->tag());
  
  char tmp[256], *labels[4] = {"Point", "Line", "Surface", "Volume"};
  std::string str;
  int mode;

  int on = 0, off = 0;
  for(int i = 0; i < 4; i++){
    on += state[i][1].size();
    off += state[i][0].size();
  }

  if(on > off){
    str = "Show \"*\";\n";
    if(!off) return str;
    str += "Hide {\n";
    mode = 0;
  }
  else{
    str = "Hide \"*\";\n";
    if(!on) return str;
    str += "Show {\n";
    mode = 1;
  }

  for(int i = 0; i < 4; i++){
    if(state[i][mode].size()){
      str += labels[i];
      str += "{";
      for(unsigned int j = 0; j < state[i][mode].size(); j++){
	if(j) str += ",";
	sprintf(tmp, "%d", state[i][mode][j]);
	str += tmp;
      }
      str += "};\n";
    }
  }
  str += "}\n";
  return str;
}

void VisibilityManager::setVisibilityByNumber(int type, int num, int all, bool val)
{
  switch(type){
  case 0: // nodes
    for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); it++)
      for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
	if(all || (*it)->mesh_vertices[i]->getNum() == num) 
	  (*it)->mesh_vertices[i]->setVisibility(val);
    for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++)
      for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
	if(all || (*it)->mesh_vertices[i]->getNum() == num) 
	  (*it)->mesh_vertices[i]->setVisibility(val);
    for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
      for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
	if(all || (*it)->mesh_vertices[i]->getNum() == num) 
	  (*it)->mesh_vertices[i]->setVisibility(val);
    for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++)
      for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
	if(all || (*it)->mesh_vertices[i]->getNum() == num) 
	  (*it)->mesh_vertices[i]->setVisibility(val);
    break;
  case 1: // elements
    for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++){
      for(unsigned int i = 0; i < (*it)->lines.size(); i++)
	if(all || (*it)->lines[i]->getNum() == num) 
	  (*it)->lines[i]->setVisibility(val);
    }
    for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++){
      for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
	if(all || (*it)->triangles[i]->getNum() == num) 
	  (*it)->triangles[i]->setVisibility(val);
      for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
	if(all || (*it)->quadrangles[i]->getNum() == num) 
	  (*it)->quadrangles[i]->setVisibility(val);
    }
    for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++){
      for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
	if(all || (*it)->tetrahedra[i]->getNum() == num) 
	  (*it)->tetrahedra[i]->setVisibility(val);
      for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
	if(all || (*it)->hexahedra[i]->getNum() == num) 
	  (*it)->hexahedra[i]->setVisibility(val);
      for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
	if(all || (*it)->prisms[i]->getNum() == num) 
	  (*it)->prisms[i]->setVisibility(val);
      for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
	if(all || (*it)->pyramids[i]->getNum() == num) 
	  (*it)->pyramids[i]->setVisibility(val);
    }
    break;
  case 2: // point
    for(GModel::viter it = GMODEL->firstVertex(); it != GMODEL->lastVertex(); it++)
      if(all || (*it)->tag() == num) (*it)->setVisibility(val);
    break;
  case 3: // line
    for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++)
      if(all || (*it)->tag() == num) (*it)->setVisibility(val);
    break;
  case 4: // surface
    for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++)
      if(all || (*it)->tag() == num) (*it)->setVisibility(val);
    break;
  case 5: // volume
    for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++)
      if(all || (*it)->tag() == num) (*it)->setVisibility(val);
    break;
  }
}

void VisElementary::setVisibility(char val, bool recursive)
{
  _e->setVisibility(val, recursive);
}

void VisPhysical::setVisibility(char val, bool recursive)
{
  _visible = val;
  for(unsigned int i = 0; i < _list.size(); i++)
    _list[i]->setVisibility(val, recursive);
}

void VisPartition::setVisibility(char val, bool recursive)
{
  _visible = val;
  for(GModel::eiter it = GMODEL->firstEdge(); it != GMODEL->lastEdge(); it++){
    for(unsigned int i = 0; i < (*it)->lines.size(); i++)
      if((*it)->lines[i]->getPartition() == _tag) 
	(*it)->lines[i]->setVisibility(val);
  }
  for(GModel::fiter it = GMODEL->firstFace(); it != GMODEL->lastFace(); it++){
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++)
      if((*it)->triangles[i]->getPartition() == _tag) 
	(*it)->triangles[i]->setVisibility(val);
    for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++)
      if((*it)->quadrangles[i]->getPartition() == _tag) 
	(*it)->quadrangles[i]->setVisibility(val);
  }
  for(GModel::riter it = GMODEL->firstRegion(); it != GMODEL->lastRegion(); it++){
    for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++)
      if((*it)->tetrahedra[i]->getPartition() == _tag) 
	(*it)->tetrahedra[i]->setVisibility(val);
    for(unsigned int i = 0; i < (*it)->hexahedra.size(); i++)
      if((*it)->hexahedra[i]->getPartition() == _tag) 
	(*it)->hexahedra[i]->setVisibility(val);
    for(unsigned int i = 0; i < (*it)->prisms.size(); i++)
      if((*it)->prisms[i]->getPartition() == _tag) 
	(*it)->prisms[i]->setVisibility(val);
    for(unsigned int i = 0; i < (*it)->pyramids.size(); i++)
      if((*it)->pyramids[i]->getPartition() == _tag) 
	(*it)->pyramids[i]->setVisibility(val);
  }
}
