// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "PViewData.h"
#include "adaptiveData.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "OctreePost.h"
#include "fullMatrix.h"
#include "ElementType.h"

std::map<std::string, interpolationMatrices> PViewData::_interpolationSchemes;

PViewData::PViewData()
  : _dirty(true), _fileIndex(0), _firstStep(0), _octree(nullptr),
    _pc2kdtree(_pc), _kdtree(nullptr), _octreeStamp(-1), _kdtreeStamp(-1),
    _adaptive(nullptr)
{
}

PViewData::~PViewData()
{
  if(_adaptive) delete _adaptive;
  for(auto it = _interpolation.begin(); it != _interpolation.end(); it++)
    for(std::size_t i = 0; i < it->second.size(); i++) delete it->second[i];
  if(_octree) delete _octree;
  if(_kdtree) delete _kdtree;
}

bool PViewData::finalize(bool computeMinMax,
                         const std::string &interpolationScheme)
{
  _dirty = false;
  _stamp++;
  return true;
}

void PViewData::initAdaptiveData()
{
  if(!_adaptive) {
    Msg::Debug("Initializing adaptive data %p interp size=%d", this,
               _interpolation.size());
    _adaptive = new adaptiveData(this);
  }
}

void PViewData::initAdaptiveDataLight(int step, int level, double tol)
{
  if(!_adaptive) {
    Msg::Debug("Initializing adaptive data %p interp size=%d", this,
               _interpolation.size());
    // (without the data refined for the drawing, not needed to save the
    // refined view or to build the data of the ParaView plugin)
    bool outDataInit = false;
    _adaptive = new adaptiveData(this, outDataInit);
  }
}

void PViewData::saveAdaptedViewForVTK(const std::string &fileName, int step,
                                      int level, double tol, int npart,
                                      bool isBinary, double min, double max)
{
  // (with the adaptive data of the view if it has some, else with some made
  // for the occasion)
  bool made = !_adaptive;
  if(made) initAdaptiveDataLight(step, level, tol);
  _adaptive->changeResolutionForVTK(step, level, tol, npart, isBinary, fileName,
                                    0, min, max);
  if(made) destroyAdaptiveData();
}

void PViewData::destroyAdaptiveData()
{
  if(_adaptive) delete _adaptive;
  _adaptive = nullptr;
}

bool PViewData::empty()
{
  return (!getNumElements() && !getNumStrings2D() && !getNumStrings3D());
}

bool PViewData::skipElement(int step, int ent, int ele, bool checkVisibility,
                            int samplingRate)
{
  if(samplingRate <= 1) return false;
  return ele % samplingRate;
}

void PViewData::getScalarValue(int step, int ent, int ele, int nod, double &val,
                               int tensorRep, int forceNumComponents,
                               int componentMap[9])
{
  int numComp = getNumComponents(step, ent, ele);
  // (on the stack: there are at most 9 components)
  double d[9];
  if(forceNumComponents && componentMap) {
    int n = std::min(forceNumComponents, 9);
    for(int i = 0; i < n; i++) {
      int comp = componentMap[i];
      if(comp >= 0 && comp < numComp)
        getValue(step, ent, ele, nod, comp, d[i]);
      else
        d[i] = 0.;
    }
    val = ComputeScalarRep(n, d, tensorRep);
  }
  else if(numComp == 1) {
    getValue(step, ent, ele, nod, 0, val);
  }
  else {
    int n = std::min(numComp, 9);
    for(int comp = 0; comp < n; comp++)
      getValue(step, ent, ele, nod, comp, d[comp]);
    val = ComputeScalarRep(n, d, tensorRep);
  }
}

void PViewData::setNode(int step, int ent, int ele, int nod, double x, double y,
                        double z)
{
  Msg::Error("Cannot change node coordinates in this view");
}

void PViewData::setValue(int step, int ent, int ele, int nod, int comp,
                         double val)
{
  Msg::Error("Cannot change field value in this view");
}

GModel *PViewData::getModel(int step)
{
  Msg::Error("Cannot get model from this view");
  return nullptr;
}

GEntity *PViewData::getEntity(int step, int ent)
{
  Msg::Error("Cannot get entity from this view");
  return nullptr;
}

MElement *PViewData::getElement(int step, int ent, int ele)
{
  Msg::Error("Cannot get element from this view");
  return nullptr;
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

int PViewData::getInterpolationMatrices(int type,
                                        std::vector<fullMatrix<double> *> &p)
{
  if(_interpolation.count(type)) {
    p = _interpolation[type];
    return p.size();
  }
  return 0;
}

bool PViewData::haveInterpolationMatrices(int type)
{
  if(!type)
    return !_interpolation.empty();
  else
    return _interpolation.count(type) ? true : false;
}

bool PViewData::haveHighOrderInterpolation()
{
  for(auto &it : _interpolation) {
    if(it.second.size() == 4) return true; // curved
    int t = ElementType::getType(it.first, 1);
    if(t > 0 && it.second.size() &&
       it.second[0]->size1() > ElementType::getNumVertices(t))
      return true;
  }
  return false;
}

void PViewData::deleteInterpolationMatrices(int type)
{
  for(auto it = _interpolation.begin(); it != _interpolation.end();) {
    if(type && it->first != type) {
      it++;
      continue;
    }
    for(auto m : it->second) delete m;
    it = _interpolation.erase(it);
  }
}

void PViewData::removeInterpolationScheme(const std::string &name)
{
  auto it = _interpolationSchemes.find(name);
  if(it != _interpolationSchemes.end()) {
    for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
      for(std::size_t i = 0; i < it2->second.size(); i++) delete it2->second[i];
    _interpolationSchemes.erase(it);
  }
}

void PViewData::removeAllInterpolationSchemes()
{
  auto it = _interpolationSchemes.begin();
  for(; it != _interpolationSchemes.end(); it++)
    for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
      for(std::size_t i = 0; i < it2->second.size(); i++) delete it2->second[i];
  _interpolationSchemes.clear();
}

void PViewData::addMatrixToInterpolationScheme(const std::string &name,
                                               int type,
                                               fullMatrix<double> &mat)
{
  _interpolationSchemes[name][type].push_back(new fullMatrix<double>(mat));
}

int PViewData::getSizeInterpolationScheme()
{
  return _interpolationSchemes.size();
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

double PViewData::findClosestNode(double &xn, double &yn, double &zn, int step)
{
  double x = xn, y = yn, z = zn;

#pragma omp critical(PViewDataFindClosestNode)
  if(!_kdtree || _kdtreeStamp != _stamp) {
    Msg::Debug("Rebuilding kdtree for view data '%s'", _name.c_str());
    delete _kdtree;
    _kdtreeStamp = _stamp;
    _pc.pts.clear();
    // FIXME: should directly iterate on mesh nodes for model-based views
    if(step < 0) step = getFirstNonEmptyTimeStep();
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        int numNodes = getNumNodes(step, ent, ele);
        for(int nod = 0; nod < numNodes; nod++) {
          double xx, yy, zz;
          getNode(step, ent, ele, nod, xx, yy, zz);
          _pc.pts.push_back(SPoint3(xx, yy, zz));
        }
      }
    }
    _kdtree = new SPoint3KDTree(3, _pc2kdtree,
                                nanoflann::KDTreeSingleIndexAdaptorParams(10));
    _kdtree->buildIndex();
  }

  double query_pt[3] = {x, y, z};
  std::size_t idx;
  double squ_dist = 0.;
  nanoflann::KNNResultSet<double> resultSet(1);
  resultSet.init(&idx, &squ_dist);
  _kdtree->findNeighbors(resultSet, &query_pt[0], nanoflann::SearchParams(10));
  if(idx < _pc.pts.size()) {
    xn = _pc.pts[idx].x();
    yn = _pc.pts[idx].y();
    zn = _pc.pts[idx].z();
    return sqrt(squ_dist);
  }
  return -1.;
}

OctreePost *PViewData::_getOctree()
{
  if(!_octree || _octreeStamp != _stamp) {
#pragma omp critical(PViewDataOctree)
    if(!_octree || _octreeStamp != _stamp) {
      Msg::Debug("Rebuilding octree for view data '%s'", _name.c_str());
      delete _octree;
      _octree = new OctreePost(this);
      _octreeStamp = _stamp;
    }
  }
  return _octree;
}

bool PViewData::searchScalar(double x, double y, double z, double *values,
                             int step, double *size, int qn, double *qx,
                             double *qy, double *qz, bool grad, int dim)
{
  return _getOctree()->searchScalar(x, y, z, values, step, size, qn, qx, qy, qz,
                                    grad, dim);
}

bool PViewData::searchScalarClosest(double x, double y, double z,
                                    double &distance, double *values,
                                    int step, double *size,
                                    int qn, double *qx, double *qy,
                                    double *qz, bool grad, int dim)
{
  bool ret = searchScalar(x, y, z, values, step, size, qn, qx, qy, qz, grad,
                          dim);
  if(ret) {
    distance = 0.;
  }
  else if(distance) {
    double xn = x, yn = y, zn = z, distanceMax = distance;
    distance = findClosestNode(xn, yn, zn, step);
    if(distanceMax < 0. || distance <= distanceMax)
      ret = searchScalar(xn, yn, zn, values, step, size, qn, qx, qy, qz, grad,
                         dim);
  }
  else {
    distance = -1.;
  }
  return ret;
}

bool PViewData::searchVector(double x, double y, double z, double *values,
                             int step, double *size, int qn, double *qx,
                             double *qy, double *qz, bool grad, int dim)
{
  return _getOctree()->searchVector(x, y, z, values, step, size, qn, qx, qy, qz,
                                    grad, dim);
}

bool PViewData::searchVectorClosest(double x, double y, double z,
                                    double &distance, double *values,
                                    int step, double *size,
                                    int qn, double *qx, double *qy,
                                    double *qz, bool grad, int dim)
{
  bool ret = searchVector(x, y, z, values, step, size, qn, qx, qy, qz, grad,
                          dim);
  if(ret) {
    distance = 0.;
  }
  else if(distance) {
    double xn = x, yn = y, zn = z, distanceMax = distance;
    distance = findClosestNode(xn, yn, zn, step);
    if(distanceMax < 0. || distance <= distanceMax)
      ret = searchVector(xn, yn, zn, values, step, size, qn, qx, qy, qz, grad,
                         dim);
  }
  else {
    distance = -1.;
  }
  return ret;
}

bool PViewData::searchTensor(double x, double y, double z, double *values,
                             int step, double *size, int qn, double *qx,
                             double *qy, double *qz, bool grad, int dim)
{
  return _getOctree()->searchTensor(x, y, z, values, step, size, qn, qx, qy, qz,
                                    grad, dim);
}

bool PViewData::searchTensorClosest(double x, double y, double z,
                                    double &distance, double *values,
                                    int step, double *size,
                                    int qn, double *qx, double *qy,
                                    double *qz, bool grad, int dim)
{
  bool ret = searchTensor(x, y, z, values, step, size, qn, qx, qy, qz, grad,
                          dim);
  if(ret) {
    distance = 0.;
  }
  else if(distance) {
    double xn = x, yn = y, zn = z, distanceMax = distance;
    distance = findClosestNode(xn, yn, zn, step);
    if(distanceMax < 0 || distance <= distanceMax)
      ret = searchTensor(xn, yn, zn, values, step, size, qn, qx, qy, qz, grad,
                         dim);
  }
  else {
    distance = -1.;
  }
  return ret;
}
