// $Id: PViewDataGModel.cpp,v 1.28 2008-03-18 19:30:14 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
//
// Contributor(s):
// 

#include "PViewDataGModel.h"
#include "MElement.h"

PViewDataGModel::PViewDataGModel(GModel *model) 
  : _model(model), _min(VAL_INF), _max(-VAL_INF)
{
  // store vector of GEntities so we can index them efficiently
  for(GModel::eiter it = _model->firstEdge(); it != _model->lastEdge(); ++it)
    _entities.push_back(*it);
  for(GModel::fiter it = _model->firstFace(); it != _model->lastFace(); ++it)
    _entities.push_back(*it);
  for(GModel::riter it = _model->firstRegion(); it != _model->lastRegion(); ++it)
    _entities.push_back(*it);
  _bbox = _model->bounds();
}

PViewDataGModel::~PViewDataGModel()
{
  for(unsigned int i = 0; i < _nodeData.size(); i++) delete _nodeData[i];
  for(unsigned int i = 0; i < _elementData.size(); i++) delete _elementData[i];  
}

bool PViewDataGModel::finalize()
{
  _min = VAL_INF;
  _max = -VAL_INF;
  for(unsigned int i = 0; i < _nodeData.size(); i++){
    _min = std::min(_min, _nodeData[i]->getMin());
    _max = std::max(_max, _nodeData[i]->getMax());
  }
  for(unsigned int i = 0; i < _elementData.size(); i++){
    _min = std::min(_min, _elementData[i]->getMin());
    _max = std::max(_max, _elementData[i]->getMax());
  }
  setDirty(false);
  return true;
}

int PViewDataGModel::getNumTimeSteps()
{
  return std::max(_nodeData.size(), _elementData.size());
}

double PViewDataGModel::getTime(int step)
{
  if(step < (int)_nodeData.size())
    return _nodeData[step]->getTime();
  else if(step < (int)_elementData.size())
    return _elementData[step]->getTime();
  return 0.;
}

double PViewDataGModel::getMin(int step)
{
  if(step < 0) return _min;
  if(step < (int)_nodeData.size()) 
    return _nodeData[step]->getMin();
  else if(step < (int)_elementData.size())
    return _elementData[step]->getMin();
  return 0.;
}

double PViewDataGModel::getMax(int step)
{
  if(step < 0) return _max;
  if(step < (int)_nodeData.size())
    return _nodeData[step]->getMax();
  else if(step < (int)_elementData.size())
    return _elementData[step]->getMax();
  return 0.;
}

int PViewDataGModel::getNumEntities()
{
  return _entities.size();
}

int PViewDataGModel::getNumElements(int ent)
{
  if(ent < 0) return _model->getNumMeshElements(); 
  return _entities[ent]->getNumMeshElements();
}

int PViewDataGModel::getDimension(int ent, int ele)
{
  return _entities[ent]->getMeshElement(ele)->getDim();
}

int PViewDataGModel::getNumNodes(int ent, int ele)
{
  return _entities[ent]->getMeshElement(ele)->getNumVertices();
}

void PViewDataGModel::getNode(int ent, int ele, int nod, double &x, double &y, double &z)
{
  MVertex *v = _entities[ent]->getMeshElement(ele)->getVertex(nod);
  x = v->x();
  y = v->y();
  z = v->z();
}

int PViewDataGModel::getNumComponents(int ent, int ele, int step)
{
  if(step < (int)_nodeData.size())
    return _nodeData[step]->getNumComp();
  else if(step < (int)_elementData.size())
    return _elementData[step]->getNumComp();
  return 1;
}

void PViewDataGModel::getValue(int ent, int ele, int nod, int comp, int step, double &val)
{
  MVertex *v = _entities[ent]->getMeshElement(ele)->getVertex(nod);
  int index = v->getDataIndex();
  if(step < (int)_nodeData.size())
    val = _nodeData[step]->getData(index)[comp];
  //else if(step < (int)_elementData.size())
  //  val = _elementData[step]->getData(index)[nod * numComp + comp];
}

int PViewDataGModel::getNumEdges(int ent, int ele)
{ 
  return _entities[ent]->getMeshElement(ele)->getNumEdges();
}

bool PViewDataGModel::skipEntity(int ent)
{
  return !_entities[ent]->getVisibility();
}

bool PViewDataGModel::skipElement(int ent, int ele, int step)
{
  if(step >= (int)_nodeData.size() || !_nodeData[step]->getNumData()) return true;
  MElement *e = _entities[ent]->getMeshElement(ele);
  if(!e->getVisibility()) return true;
  for(int i = 0; i < e->getNumVertices(); i++){
    int index = e->getVertex(i)->getDataIndex();
    if(index < 0 || index >= (int)_nodeData[step]->getNumData()) return true;
    if(!_nodeData[step]->getData(index)) return true;
  }
  return false;
}

bool PViewDataGModel::hasTimeStep(int step)
{
  if(step < (int)_nodeData.size() && _nodeData[step]->getNumData()) return true;
  if(step < (int)_elementData.size() && _elementData[step]->getNumData()) return true;
  return false;
}

bool PViewDataGModel::hasPartition(int part)
{
  return _partitions.find(part) != _partitions.end();
}
