// $Id: PViewDataGModel.cpp,v 1.33 2008-03-20 11:05:08 geuzaine Exp $
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

PViewDataGModel::PViewDataGModel() : _min(VAL_INF), _max(-VAL_INF)
{
}

PViewDataGModel::~PViewDataGModel()
{
  for(unsigned int i = 0; i < _steps.size(); i++) delete _steps[i];
}

bool PViewDataGModel::finalize()
{
  _min = VAL_INF;
  _max = -VAL_INF;
  for(unsigned int i = 0; i < _steps.size(); i++){
    _min = std::min(_min, _steps[i]->getMin());
    _max = std::max(_max, _steps[i]->getMax());
  }
  setDirty(false);
  return true;
}

int PViewDataGModel::getNumTimeSteps()
{
  return _steps.size();
}

double PViewDataGModel::getTime(int step)
{
  return _steps[step]->getTime();
}

double PViewDataGModel::getMin(int step)
{
  if(step < 0) return _min;
  return _steps[step]->getMin();
}

double PViewDataGModel::getMax(int step)
{
  if(step < 0) return _max;
  return _steps[step]->getMax();
}

SBoundingBox3d PViewDataGModel::getBoundingBox(int step)
{ 
  if(step < 0){
    SBoundingBox3d tmp;
    for(unsigned int i = 0; i < _steps.size(); i++)
      tmp += _steps[i]->getBoundingBox();
    return tmp;
  }
  return _steps[step]->getBoundingBox();
}

int PViewDataGModel::getNumScalars(int step)
{
  if(_steps[0]->getNumComp() == 1) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumVectors(int step)
{
  if(_steps[0]->getNumComp() == 3) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumTensors(int step)
{
  if(_steps[0]->getNumComp() == 9) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumEntities(int step)
{
  if(step < 0){
    int num = 0;
    for(unsigned int i = 0; i < _steps.size(); i++)
      num += _steps[i]->getNumEntities();
    return num;
  }
  return _steps[step]->getNumEntities();
}

int PViewDataGModel::getNumElements(int step, int ent)
{
  if(step < 0){
    int num = 0;
    for(unsigned int i = 0; i < _steps.size(); i++){
      if(ent < 0)
	num += _steps[i]->getModel()->getNumMeshElements();
      else
	num += _steps[i]->getEntity(ent)->getNumMeshElements();
    }
    return num;
  }
  if(ent < 0) return _steps[step]->getModel()->getNumMeshElements(); 
  return _steps[step]->getEntity(ent)->getNumMeshElements();
}

int PViewDataGModel::getDimension(int step, int ent, int ele)
{
  return _steps[step]->getEntity(ent)->getMeshElement(ele)->getDim();
}

int PViewDataGModel::getNumNodes(int step, int ent, int ele)
{
  return _steps[step]->getEntity(ent)->getMeshElement(ele)->getNumVertices();
}

void PViewDataGModel::getNode(int step, int ent, int ele, int nod, 
			      double &x, double &y, double &z)
{
  MVertex *v = _steps[step]->getEntity(ent)->getMeshElement(ele)->getVertex(nod);
  x = v->x();
  y = v->y();
  z = v->z();
}

int PViewDataGModel::getNumComponents(int step, int ent, int ele)
{
  return _steps[step]->getNumComp();
}

void PViewDataGModel::getValue(int step, int ent, int ele, int nod, int comp, double &val)
{
  MVertex *v = _steps[step]->getEntity(ent)->getMeshElement(ele)->getVertex(nod);
  int index = v->getDataIndex();
  val = _steps[step]->getData(index)[comp];
}

int PViewDataGModel::getNumEdges(int step, int ent, int ele)
{ 
  return _steps[step]->getEntity(ent)->getMeshElement(ele)->getNumEdges();
}

bool PViewDataGModel::skipEntity(int step, int ent)
{
  return !_steps[step]->getEntity(ent)->getVisibility();
}

bool PViewDataGModel::skipElement(int step, int ent, int ele)
{
  if(step >= (int)_steps.size() || !_steps[step]->getNumData()) return true;
  MElement *e = _steps[step]->getEntity(ent)->getMeshElement(ele);
  if(!e->getVisibility()) return true;
  for(int i = 0; i < e->getNumVertices(); i++){
    int index = e->getVertex(i)->getDataIndex();
    if(index < 0 || index >= (int)_steps[step]->getNumData()) return true;
    if(!_steps[step]->getData(index)) return true;
  }
  return false;
}

bool PViewDataGModel::hasTimeStep(int step)
{
  if(step < (int)_steps.size() && _steps[step]->getNumData()) return true;
  return false;
}

bool PViewDataGModel::hasPartition(int part)
{
  return _partitions.find(part) != _partitions.end();
}

bool PViewDataGModel::hasMultipleMeshes()
{
  if(_steps.size() <= 1) return false;
  GModel *m = _steps[0]->getModel();
  for(unsigned int i = 1; i < _steps.size(); i++)
    if(m != _steps[i]->getModel()) return true;
  return false;
}

GEntity *PViewDataGModel::getEntity(int step, int ent)
{
  return _steps[step]->getEntity(ent);
}

bool PViewDataGModel::getValue(int step, int dataIndex, int comp, double &val)
{
  if(dataIndex < 0 || dataIndex >= (int)_steps[step]->getNumData()) return false;
  double *d = _steps[step]->getData(dataIndex);
  if(!d) return false;
  val = d[comp];
  return true;
}
