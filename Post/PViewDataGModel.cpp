// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "PViewDataGModel.h"
#include "MElement.h"
#include "Numeric.h"
#include "GmshMessage.h"

PViewDataGModel::PViewDataGModel(DataType type) 
  : PViewData(), _min(VAL_INF), _max(-VAL_INF), _type(type)
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
  for(int step = 0; step < getNumTimeSteps(); step++){
    _steps[step]->setMin(VAL_INF);
    _steps[step]->setMax(-VAL_INF);
    if(_type == NodeData || _type == ElementData){
      // treat these 2 special cases separately for maximum efficiency
      int numComp = _steps[step]->getNumComponents();
      for(int i = 0; i < _steps[step]->getNumData(); i++){
	double *d = _steps[step]->getData(i);
	if(d){
	  double val = ComputeScalarRep(numComp, d);
	  _steps[step]->setMin(std::min(_steps[step]->getMin(), val));
	  _steps[step]->setMax(std::max(_steps[step]->getMax(), val));
	}
      }
    }
    else{
      // general case (slower)
      for(int ent = 0; ent < getNumEntities(step); ent++){
	for(int ele = 0; ele < getNumElements(step, ent); ele++){
	  if(skipElement(step, ent, ele)) continue;
	  for(int nod = 0; nod < getNumNodes(step, ent, ele); nod++){
	    double val;
	    getScalarValue(step, ent, ele, nod, val);
	    _steps[step]->setMin(std::min(_steps[step]->getMin(), val));
	    _steps[step]->setMax(std::max(_steps[step]->getMax(), val));
	  }
	}
      }
    }
    _min = std::min(_min, _steps[step]->getMin());
    _max = std::max(_max, _steps[step]->getMax());
  }

  // add interpolation data for known element types (this might be
  // overidden later)
  for(int step = 0; step < getNumTimeSteps(); step++){
    GModel *m = _steps[step]->getModel();
    for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); it++)
      if((*it)->lines.size()) 
        _addInterpolationMatricesForElement((*it)->lines[0]);
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); it++)
      if((*it)->triangles.size()) 
        _addInterpolationMatricesForElement((*it)->triangles[0]);
      else if((*it)->quadrangles.size()) 
        _addInterpolationMatricesForElement((*it)->quadrangles[0]);
    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); it++)
      if((*it)->tetrahedra.size()) 
        _addInterpolationMatricesForElement((*it)->tetrahedra[0]);
      else if((*it)->hexahedra.size()) 
        _addInterpolationMatricesForElement((*it)->hexahedra[0]);
      else if((*it)->prisms.size()) 
        _addInterpolationMatricesForElement((*it)->prisms[0]);
      else if((*it)->pyramids.size()) 
        _addInterpolationMatricesForElement((*it)->pyramids[0]);
  }

  return PViewData::finalize();
}

void PViewDataGModel::_addInterpolationMatricesForElement(MElement *e)
{
  int edg = e->getNumEdges();
  if(_interpolation.count(edg)) return;
  const gmshFunctionSpace *fs = e->getFunctionSpace();
  if(fs){
    _interpolation[edg].push_back(new Double_Matrix(fs->coefficients));
    _interpolation[edg].push_back(new Double_Matrix(fs->monomials));
    if(e->getPolynomialOrder() > 1){
      _interpolation[edg].push_back(new Double_Matrix(fs->coefficients));
      _interpolation[edg].push_back(new Double_Matrix(fs->monomials));
    }
  }
  else if(edg == 4 && e->getPolynomialOrder() == 1){
    // quad4
    Double_Matrix *c = new Double_Matrix(4, 4);
    (*c)(0, 0) = .25; (*c)(0, 1) = -.25; (*c)(0, 2) = .25; (*c)(0, 3) = -.25;
    (*c)(1, 0) = .25; (*c)(1, 1) = .25; (*c)(1, 2) = -.25; (*c)(1, 3) = -.25;
    (*c)(2, 0) = .25; (*c)(2, 1) = .25; (*c)(2, 2) = .25; (*c)(2, 3) = .25;
    (*c)(3, 0) = .25; (*c)(3, 1) = -.25; (*c)(3, 2) = -.25; (*c)(3, 3) = .25;
    Double_Matrix *m = new Double_Matrix(4, 2);
    (*m)(0, 0) = 0; (*m)(0, 1) = 0;
    (*m)(1, 0) = 1; (*m)(1, 1) = 0;
    (*m)(2, 0) = 1; (*m)(2, 1) = 1;
    (*m)(3, 0) = 0; (*m)(3, 1) = 1;
    _interpolation[edg].push_back(c);
    _interpolation[edg].push_back(m);
  }
  else{
    Msg::Warning("need to add interpol matrices for ele type %d", e->getTypeForMSH());
  }
}

MElement *PViewDataGModel::_getElement(int step, int ent, int ele)
{
  static int lastStep = -1, lastEnt = -1, lastEle = -1;
  static MElement *curr = 0;
  if(step != lastStep || ent != lastEnt || ele != lastEle)
    curr = _steps[step]->getEntity(ent)->getMeshElement(ele);
  return curr;
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
  // to generalize
  if(_steps[0]->getNumComponents() == 1) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumVectors(int step)
{
  if(_steps.empty()) return 0;
  // to generalize
  if(_steps[0]->getNumComponents() == 3) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumTensors(int step)
{
  if(_steps.empty()) return 0;
  // to generalize
  if(_steps[0]->getNumComponents() == 9) return getNumElements(0);
  return 0;
}

int PViewDataGModel::getNumPoints(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(GModel::viter it = m->firstVertex(); it != m->lastVertex(); ++it)
    n += (*it)->points.size();
  return n;
}

int PViewDataGModel::getNumLines(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    n += (*it)->lines.size();
  return n;
}

int PViewDataGModel::getNumTriangles(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    n += (*it)->triangles.size();
  return n;
}

int PViewDataGModel::getNumQuadrangles(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    n += (*it)->quadrangles.size();
  return n;
}

int PViewDataGModel::getNumTetrahedra(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->tetrahedra.size();
  return n;
}

int PViewDataGModel::getNumHexahedra(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->hexahedra.size();
  return n;
}

int PViewDataGModel::getNumPrisms(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->prisms.size();
  return n;
}

int PViewDataGModel::getNumPyramids(int step)
{
  if(_steps.empty()) return 0;
  GModel *m = _steps[0]->getModel(); // to generalize
  int n = 0;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    n += (*it)->pyramids.size();
  return n;
}

int PViewDataGModel::getNumEntities(int step)
{
  if(_steps.empty()) return 0;
  // to generalize
  if(step < 0) return _steps[0]->getNumEntities();
  return _steps[step]->getNumEntities();
}

int PViewDataGModel::getNumElements(int step, int ent)
{
  if(_steps.empty()) return 0;
  // to generalize
  if(step < 0 && ent < 0) return _steps[0]->getModel()->getNumMeshElements();
  if(step < 0) return _steps[0]->getEntity(ent)->getNumMeshElements();
  if(ent < 0) return _steps[step]->getModel()->getNumMeshElements(); 
  return _steps[step]->getEntity(ent)->getNumMeshElements();
}

int PViewDataGModel::getDimension(int step, int ent, int ele)
{
  return _getElement(step, ent, ele)->getDim();
}

int PViewDataGModel::getNumNodes(int step, int ent, int ele)
{
  MElement *e = _getElement(step, ent, ele);
  if(_type == GaussPointData){
    return _steps[step]->getGaussPoints(e->getTypeForMSH()).size() / 3;
  }
  else{
    if(isAdaptive())
      return e->getNumVertices();
    else
      return e->getNumPrimaryVertices();
  }
}

int PViewDataGModel::getNode(int step, int ent, int ele, int nod, 
			     double &x, double &y, double &z)
{
  MElement *e = _getElement(step, ent, ele);
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
      x = e->interpolate(vx, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2], 1, 1);
      y = e->interpolate(vy, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2], 1, 1);
      z = e->interpolate(vz, p[3 * nod], p[3 * nod + 1], p[3 * nod + 2], 1, 1);
    }
    return 0;
  }
  else{
    MVertex *v = e->getVertex(nod);
    x = v->x();
    y = v->y();
    z = v->z();
    return v->getIndex();
  }
}

void PViewDataGModel::setNode(int step, int ent, int ele, int nod, 
                              double x, double y, double z)
{
  MVertex *v = _getElement(step, ent, ele)->getVertex(nod);
  v->x() = x;
  v->y() = y;
  v->z() = z;
}

void PViewDataGModel::tagNode(int step, int ent, int ele, int nod, int tag)
{
  MVertex *v = _getElement(step, ent, ele)->getVertex(nod);
  v->setIndex(tag);
}

int PViewDataGModel::getNumComponents(int step, int ent, int ele)
{
  return _steps[step]->getNumComponents();
}

int PViewDataGModel::getNumValues(int step, int ent, int ele)
{
  if(_type == ElementNodeData || _type == NodeData){
    return getNumNodes(step, ent, ele) * getNumComponents(step, ent, ele);
  }
  else{
    Msg::Error("getNumValues should not be used on this type of view");
    return 0;
  }
}

void PViewDataGModel::getValue(int step, int ent, int ele, int idx, double &val)
{
  MElement *e = _getElement(step, ent, ele);
  if(_type == ElementNodeData){
    val = _steps[step]->getData(e->getNum())[idx];
  }
  else if(_type == NodeData){
    int numcomp = _steps[step]->getNumComponents();
    int nod = idx / numcomp;
    int comp = idx % numcomp;
    val = _steps[step]->getData(e->getVertex(nod)->getNum())[comp];
  }
  else{
    Msg::Error("getValue(index) should not be used on this type of view");
  }
}

void PViewDataGModel::getValue(int step, int ent, int ele, int nod, int comp, double &val)
{
  MElement *e = _getElement(step, ent, ele);
  switch(_type){
  case NodeData: 
    val = _steps[step]->getData(e->getVertex(nod)->getNum())[comp];
    break;
  case ElementNodeData:
  case GaussPointData: 
    val = _steps[step]->getData(e->getNum())[_steps[step]->getNumComponents() * nod + comp];
    break;
  case ElementData: 
  default: 
    val = _steps[step]->getData(e->getNum())[comp];
    break;
  }
}

void PViewDataGModel::setValue(int step, int ent, int ele, int nod, int comp, double val)
{
  MElement *e = _getElement(step, ent, ele);
  switch(_type){
  case NodeData: 
    _steps[step]->getData(e->getVertex(nod)->getNum())[comp] = val;
    break;
  case ElementNodeData:
  case GaussPointData: 
    _steps[step]->getData(e->getNum())[_steps[step]->getNumComponents() * nod + comp] = val;
    break;
  case ElementData: 
  default: 
    _steps[step]->getData(e->getNum())[comp] = val;
    break;
  }
}

int PViewDataGModel::getNumEdges(int step, int ent, int ele)
{ 
  return _getElement(step, ent, ele)->getNumEdges();
}

void PViewDataGModel::revertElement(int step, int ent, int ele)
{
  if(!step) _getElement(step, ent, ele)->revert();
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
	if(!getValueByIndex(step, e->getNum(), 0, 0, val)) continue;
	for(int nod = 0; nod < e->getNumVertices(); nod++){
	  MVertex *v = e->getVertex(nod);
	  if(nodeConnect.count(v->getNum()))
	    nodeConnect[v->getNum()]++;
	  else
	    nodeConnect[v->getNum()] = 1;
	  double *d = _steps2.back()->getData(v->getNum(), true);
	  for(int j = 0; j < numComp; j++)
	    if(getValueByIndex(step, e->getNum(), nod, j, val)) d[j] += val;
	}
      }
    }
    for(int i = 0; i < _steps2.back()->getNumData(); i++){
      double *d = _steps2.back()->getData(i);
      if(d){
	double f = nodeConnect[i];
	if(f) for(int j = 0; j < numComp; j++) d[j] /= f;
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
  if(step >= getNumTimeSteps()) return true;
  return !_steps[step]->getEntity(ent)->getVisibility();
}

bool PViewDataGModel::skipElement(int step, int ent, int ele, bool checkVisibility)
{
  if(step >= getNumTimeSteps()) return true;
  stepData<double> *sd = _steps[step];
  if(!_steps[step]->getNumData()) return true;
  MElement *e = _getElement(step, ent, ele);
  if(checkVisibility && !e->getVisibility()) return true;
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

bool PViewDataGModel::hasModel(GModel *model, int step)
{
  if(step < 0){
    for(unsigned int i = 0; i < _steps.size(); i++)
      if(model == _steps[i]->getModel()) return true;
    return false;
  }
  return (model == _steps[step]->getModel());
}

GEntity *PViewDataGModel::getEntity(int step, int ent)
{
  return _steps[step]->getEntity(ent);
}

bool PViewDataGModel::getValueByIndex(int step, int dataIndex, int nod, int comp, double &val)
{
  double *d = _steps[step]->getData(dataIndex);
  if(!d) return false;

  if(_type == NodeData || _type == ElementData)
    val = d[comp];
  else
    val = d[_steps[step]->getNumComponents() * nod + comp];
  return true;
}
