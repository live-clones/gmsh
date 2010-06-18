// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "PViewData.h"
#include "adaptiveData.h"
#include "Numeric.h"
#include "GmshMessage.h"

PViewData::PViewData()
  : _dirty(true), _fileIndex(0), _adaptive(0)
{
}

PViewData::~PViewData()
{
  if(_adaptive) delete _adaptive;
  for(std::map<int, std::vector<fullMatrix<double>*> >::iterator it = _interpolation.begin();
      it != _interpolation.end(); it++)
    for(unsigned int i = 0; i < it->second.size(); i++)
      delete it->second[i];
}

bool PViewData::finalize(bool computeMinMax)
{ 
  _dirty = false;
  return true;
}

void PViewData::initAdaptiveData(int step, int level, double tol)
{
  if(!_adaptive){
    Msg::Info("Initializing adaptive data %p interp size=%d", this, _interpolation.size());
    _adaptive = new adaptiveData(this);
    _adaptive->changeResolution(step, level, tol);
  }
}

void PViewData::destroyAdaptiveData()
{
  if(_adaptive) delete _adaptive;
  _adaptive = 0;
}

bool PViewData::empty()
{
  return (!getNumElements() && !getNumStrings2D() && !getNumStrings3D());
}

void PViewData::getScalarValue(int step, int ent, int ele, int nod, double &val)
{
  int numComp = getNumComponents(step, ent, ele);
  if(numComp == 1){
    getValue(step, ent, ele, nod, 0, val);
  }
  else{
    std::vector<double> d(numComp);
    for(int comp = 0; comp < numComp; comp++)
      getValue(step, ent, ele, nod, comp, d[comp]);
    val = ComputeScalarRep(numComp, &d[0]);
  }
}

void PViewData::setNode(int step, int ent, int ele, int nod, double x, double y, double z)
{
  Msg::Error("Cannot change node coordinates in this view");
}

void PViewData::setValue(int step, int ent, int ele, int nod, int comp, double val)
{
  Msg::Error("Cannot change field value in this view");
}

void PViewData::setInterpolationMatrices(int type, 
                                         const fullMatrix<double> &coefVal,
                                         const fullMatrix<double> &expVal)
{
  if(!type || _interpolation[type].size()) return;
  _interpolation[type].push_back(new fullMatrix<double>(coefVal));
  _interpolation[type].push_back(new fullMatrix<double>(expVal));
}

void PViewData::setInterpolationMatrices(int type, 
                                         const fullMatrix<double> &coefVal,
                                         const fullMatrix<double> &expVal, 
                                         const fullMatrix<double> &coefGeo,
                                         const fullMatrix<double> &expGeo)
{
  if(!type || _interpolation[type].size()) return;
  _interpolation[type].push_back(new fullMatrix<double>(coefVal));
  _interpolation[type].push_back(new fullMatrix<double>(expVal));
  _interpolation[type].push_back(new fullMatrix<double>(coefGeo));
  _interpolation[type].push_back(new fullMatrix<double>(expGeo));
}

int PViewData::getInterpolationMatrices(int type, std::vector<fullMatrix<double>*> &p)
{
  if(_interpolation.count(type)){
    p = _interpolation[type];
    return p.size();
  }
  return 0;
}

void PViewData::smooth()
{
  Msg::Error("Smoothing is not implemented for this type of data");
}

bool PViewData::combineTime(nameData &nd)
{ 
  Msg::Error("Combine time is not implemented for this type of data");
  return false; 
}

bool PViewData::combineSpace(nameData &nd)
{ 
  Msg::Error("Combine space is not implemented for this type of data");
  return false; 
}

double PViewData::getValueBinding(int step, int ent, int ele, int nod, int comp)
{
  double val;
  getValue(step,ent,ele,nod,comp,val);
  return val;
}

void PViewData::getAllValuesForElementBinding(int step, int ent, int ele, fullMatrix<double> &m) {
  int nNodes = getNumNodes(step,ent,ele);
  int nComponents = getNumComponents(step,ent,ele);
  for (int i=0; i<nNodes; i++)
    for (int j=0; j<nComponents; j++)
       getValue(step,ent,ele,i,j,m(i,j));
}

void PViewData::getAllNodesForElementBinding(int step, int ent, int ele, fullMatrix<double> &m) {
  int nNodes = getNumNodes(step,ent,ele);
  for (int i=0; i<nNodes; i++)
    getNode(step,ent,ele,i,m(i,0),m(i,1),m(i,2));
}

#include "Bindings.h"
void PViewData::registerBindings(binding *b) {
  classBinding *cb = b->addClass<PViewData>("PViewData");
  cb->setDescription("The data of a post-processing view");
  methodBinding *cm;
  cm = cb->addMethod("getNumEntities",&PViewData::getNumEntities);
  cm->setArgNames("step",NULL);
  cm->setDescription("return the number of entities for a given time step (-1 for default)");
  cm = cb->addMethod("getNumElements",&PViewData::getNumElements);
  cm->setArgNames("step","entity",NULL);
  cm->setDescription("return the number of entities for a given time step (-1 for default) for a given entity (-1 for all)");
  cm = cb->addMethod("getNumTriangles",&PViewData::getNumTriangles);
  cm->setArgNames("step",NULL);
  cm->setDescription("return the number of triangles for a given time step (-1 for default)");

  cm = cb->addMethod("getNumNodes",&PViewData::getNumNodes);
  cm->setArgNames("step","entity","element",NULL);
  cm->setDescription("return the number of nodes of one element of an entity of a time step (-1 for default time step)");

  cm = cb->addMethod("getNumValues",&PViewData::getNumValues);
  cm->setArgNames("step","entity","element",NULL);
  cm->setDescription("return the number of values of one element of an entity of a time step (-1 for default time step)");

  cm = cb->addMethod("getNumComponents",&PViewData::getNumComponents);
  cm->setArgNames("step","entity","element",NULL);
  cm->setDescription("return the number of components of one element of an entity of a time step (-1 for default time step)");

  cm = cb->addMethod("getValue",&PViewData::getValueBinding);
  cm->setArgNames("step","entity","element","node","component",NULL);
  cm->setDescription("return one of the values");

  cm = cb->addMethod("getAllValuesForElement",&PViewData::getAllValuesForElementBinding);
  cm->setArgNames("step","entity","element","values",NULL);
  cm->setDescription("fill a fullMatrix with all values from the elements. The fullMatrix should have the size nbNodes x nbComponents.");

  cm = cb->addMethod("getAllNodesForElement",&PViewData::getAllNodesForElementBinding);
  cm->setArgNames("step","entity","element","coordinates",NULL);
  cm->setDescription("fill a fullMatrix with all coordinates from the nodes of the elements. The fullMatrix should have the size nbNodes x 3");
}
