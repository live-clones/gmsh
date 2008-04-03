// $Id: PViewDataGModel.cpp,v 1.47 2008-04-03 07:48:54 geuzaine Exp $
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
#include "Numeric.h"
#include "Message.h"

PViewDataGModel::PViewDataGModel(DataType type) 
  : _min(VAL_INF), _max(-VAL_INF), _type(type)
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
  if(_steps.empty()) return 0.;
  return _steps[step]->getTime();
}

double PViewDataGModel::getMin(int step)
{
  if(step < 0 || _steps.empty()) return _min;
  return _steps[step]->getMin();
}

double PViewDataGModel::getMax(int step)
{
  if(step < 0 || _steps.empty()) return _max;
  return _steps[step]->getMax();
}

SBoundingBox3d PViewDataGModel::getBoundingBox(int step)
{ 
  if(step < 0 || _steps.empty()){
    SBoundingBox3d tmp;
    for(unsigned int i = 0; i < _steps.size(); i++)
      tmp += _steps[i]->getBoundingBox();
    return tmp;
  }
  return _steps[step]->getBoundingBox();
}

int PViewDataGModel::getNumScalars(int step)
{
  if(_steps.empty()) return 0;
  if(_steps[0]->getNumComponents() == 1) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumVectors(int step)
{
  if(_steps.empty()) return 0;
  if(_steps[0]->getNumComponents() == 3) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumTensors(int step)
{
  if(_steps.empty()) return 0;
  if(_steps[0]->getNumComponents() == 9) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumEntities(int step)
{
  if(step < 0 || _steps.empty()){
    int num = 0;
    for(unsigned int i = 0; i < _steps.size(); i++)
      num += _steps[i]->getNumEntities();
    return num;
  }
  return _steps[step]->getNumEntities();
}

int PViewDataGModel::getNumElements(int step, int ent)
{
  if(step < 0 || _steps.empty()){
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
  // no sanity checks (assumed to be guarded by skipElement)
  return _steps[step]->getEntity(ent)->getMeshElement(ele)->getDim();
}

int PViewDataGModel::getNumNodes(int step, int ent, int ele)
{
  // no sanity checks (assumed to be guarded by skipElement)
  MElement *e = _steps[step]->getEntity(ent)->getMeshElement(ele);
  if(_type == GaussPointData){
    return _steps[step]->getGaussPoints(e->getTypeForMSH()).size() / 3;
  }
  else{
    //return e->getNumVertices();
    return e->getNumPrimaryVertices();
  }
}

void PViewDataGModel::getNode(int step, int ent, int ele, int nod, 
                              double &x, double &y, double &z)
{
  // no sanity checks (assumed to be guarded by skipElement)
  MElement *e = _steps[step]->getEntity(ent)->getMeshElement(ele);
  if(_type == GaussPointData){ 
    std::vector<double> &p(_steps[step]->getGaussPoints(e->getTypeForMSH()));
    if(p[0] == 1.e22){
      // hack: the points are the element vertices
      x = e->getVertex(nod)->x();
      y = e->getVertex(nod)->y();
      z = e->getVertex(nod)->z();
    }
    else{
      double vx[8], vy[8], vz[8];
      for(int i = 0; i < e->getNumPrimaryVertices(); i++){
	vx[i] = e->getVertex(i)->x();
	vy[i] = e->getVertex(i)->y();
	vz[i] = e->getVertex(i)->z();
      }
      x = e->interpolate(vx, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2]);
      y = e->interpolate(vy, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2]);
      z = e->interpolate(vz, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2]);
    }
  }
  else{
    MVertex *v = e->getVertex(nod);
    x = v->x();
    y = v->y();
    z = v->z();
  }
}

int PViewDataGModel::getNumComponents(int step, int ent, int ele)
{
  // no sanity checks (assumed to be guarded by skipElement)
  return _steps[step]->getNumComponents();
}

void PViewDataGModel::getValue(int step, int ent, int ele, int nod, int comp, double &val)
{
  // no sanity checks (assumed to be guarded by skipElement)
  stepData<double> *sd = _steps[step];
  MElement *e = sd->getEntity(ent)->getMeshElement(ele);
  switch(_type){
  case NodeData: 
    val = sd->getData(e->getVertex(nod)->getNum())[comp];
    break;
  case ElementNodeData:
  case GaussPointData: 
    val = sd->getData(e->getNum())[sd->getNumComponents() * nod + comp];
    break;
  case ElementData: 
  default: 
    val = sd->getData(e->getNum())[comp];
    break;
  }
}

int PViewDataGModel::getNumEdges(int step, int ent, int ele)
{ 
  // no sanity checks (assumed to be guarded by skipElement)
  return _steps[step]->getEntity(ent)->getMeshElement(ele)->getNumEdges();
}

void PViewDataGModel::smooth()
{
  if(_type == NodeData || _type == GaussPointData) return;
  std::vector<stepData<double>*> _steps2;
  for(unsigned int step = 0; step < _steps.size(); step++){
    GModel *m = _steps[step]->getModel();
    int numComp = _steps[step]->getNumComponents();
    _steps2.push_back(new stepData<double>(m, numComp, _steps[step]->getFileName(),
					   _steps[step]->getFileIndex()));
    std::map<int, int> nodeConnect;
    for(int ent = 0; ent < getNumEntities(step); ent++){
      for(int ele = 0; ele < getNumElements(step, ent); ele++){
	MElement *e = _steps[step]->getEntity(ent)->getMeshElement(ele);
	double val;
	if(!getValue(step, e->getNum(), 0, 0, val)) continue;
	for(int nod = 0; nod < e->getNumVertices(); nod++){
	  MVertex *v = e->getVertex(nod);
	  if(nodeConnect.count(v->getNum()))
	    nodeConnect[v->getNum()]++;
	  else
	    nodeConnect[v->getNum()] = 1;
	  double *d = _steps2.back()->getData(v->getNum(), true);
	  for(int j = 0; j < numComp; j++)
	    if(getValue(step, e->getNum(), nod, j, val)) d[j] += val;
	}
      }
    }
    for(int i = 0; i < _steps2.back()->getNumData(); i++){
      double *d = _steps2.back()->getData(i);
      if(d){
	double f = nodeConnect[i];
	if(f) for(int j = 0; j < numComp; j++) d[j] /= f;
	double s = ComputeScalarRep(numComp, d);
	_steps2[step]->setMin(std::min(_steps2[step]->getMin(), s));
	_steps2[step]->setMax(std::max(_steps2[step]->getMax(), s));
      }
    }
  }
  for(unsigned int i = 0; i < _steps.size(); i++) delete _steps[i];
  _steps = _steps2;
  _type = NodeData;
  finalize();
}

bool PViewDataGModel::skipEntity(int step, int ent)
{
  return !_steps[step]->getEntity(ent)->getVisibility();
}

bool PViewDataGModel::skipElement(int step, int ent, int ele)
{
  if(step >= getNumTimeSteps()) return true;
  stepData<double> *sd = _steps[step];
  if(!_steps[step]->getNumData()) return true;
  MElement *e = sd->getEntity(ent)->getMeshElement(ele);
  if(!e->getVisibility()) return true;
  if(_type == NodeData){
    for(int i = 0; i < e->getNumVertices(); i++)
      if(!sd->getData(e->getVertex(i)->getNum())) return true;
  }
  else{
    if(!sd->getData(e->getNum())) return true;
  }
  return false;
}

bool PViewDataGModel::hasTimeStep(int step)
{
  if(step < getNumTimeSteps() && _steps[step]->getNumData()) return true;
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

bool PViewDataGModel::getValue(int step, int dataIndex, int nod, int comp, double &val)
{
  double *d = _steps[step]->getData(dataIndex);
  if(!d) return false;

  if(_type == NodeData || _type == ElementData)
    val = d[comp];
  else
    val = d[_steps[step]->getNumComponents() * nod + comp];
  return true;
}
