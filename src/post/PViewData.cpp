// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "PViewData.h"
#include "adaptiveData.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "OctreePost.h"
#include "fullMatrix.h"

std::map<std::string, interpolationMatrices> PViewData::_interpolationSchemes;

PViewData::PViewData()
  : _dirty(true), _fileIndex(0), _octree(nullptr), _pc2kdtree(_pc),
    _kdtree(nullptr), _adaptive(nullptr)
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
  return true;
}

void PViewData::initAdaptiveData(int step, int level, double tol)
{
  if(!_adaptive) {
    Msg::Debug("Initializing adaptive data %p interp size=%d", this,
               _interpolation.size());
    _adaptive = new adaptiveData(this);
    _adaptive->changeResolution(step, level, tol);
  }
}

void PViewData::initAdaptiveDataLight(int step, int level, double tol)
{
  if(!_adaptive) {
    Msg::Debug("Initializing adaptive data %p interp size=%d", this,
               _interpolation.size());
    // _outData in adaptive.h is only used for visualization of adapted views in
    // the GMSH GUI.  In some cases (export of adapted views under pvtu format,
    // use of GMSH as external lib), this object is not needed so avoid its
    // allocation in order to limit memory consumption
    bool outDataInit = false;
    _adaptive = new adaptiveData(this, outDataInit);
  }
}

void PViewData::saveAdaptedViewForVTK(const std::string &guifileName,
                                      int useDefaultName, int step, int level,
                                      double tol, int npart, bool isBinary)
{
  if(_adaptive) {
    // _adaptiveData has already been allocated from the adaptive view panel of
    // the GUI for instance.
    _adaptive->changeResolutionForVTK(step, level, tol, npart, isBinary,
                                      guifileName, useDefaultName);
  }
  else {
    initAdaptiveDataLight(step, level, tol);
    _adaptive->changeResolutionForVTK(step, level, tol, npart, isBinary,
                                      guifileName, useDefaultName);
    destroyAdaptiveData();
  }
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
  if(forceNumComponents && componentMap) {
    std::vector<double> d(forceNumComponents);
    for(int i = 0; i < forceNumComponents; i++) {
      int comp = componentMap[i];
      if(comp >= 0 && comp < numComp)
        getValue(step, ent, ele, nod, comp, d[i]);
      else
        d[i] = 0.;
    }
    val = ComputeScalarRep(forceNumComponents, &d[0], tensorRep);
  }
  else if(numComp == 1) {
    getValue(step, ent, ele, nod, 0, val);
  }
  else {
    std::vector<double> d(numComp);
    for(int comp = 0; comp < numComp; comp++)
      getValue(step, ent, ele, nod, comp, d[comp]);
    val = ComputeScalarRep(numComp, &d[0], tensorRep);
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

void PViewData::deleteInterpolationMatrices(int type)
{
  _interpolation.erase(type);
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
  std::map<std::string, interpolationMatrices>().swap(_interpolationSchemes);
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

#if 0

  // slow, naive implementation; beware that iterations on view data is
  // currently not thread-safe (it uses a cache for the current element/node)
  double dist2 = 1e200;
#pragma omp critical
  {
    if(step < 0) step = getFirstNonEmptyTimeStep();
    for(int ent = 0; ent < getNumEntities(step); ent++) {
      for(int ele = 0; ele < getNumElements(step, ent); ele++) {
        int numNodes = getNumNodes(step, ent, ele);
        for(int nod = 0; nod < numNodes; nod++) {
          double xx, yy, zz;
          getNode(step, ent, ele, nod, xx, yy, zz);
          double d2 =
            (x - xx) * (x - xx) + (y - yy) * (y - yy) + (z - zz) * (z - zz);
          if(d2 < dist2) {
            dist2 = d2;
            xn = xx;
            yn = yy;
            zn = zz;
          }
        }
      }
    }
  }
  return sqrt(dist2);

#else

#pragma omp critical
  if(!_kdtree) {
    Msg::Debug("Rebuilding kdtree for view data '%s'", _name.c_str());
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
  else{
    return -1.;
  }

#endif
}

bool PViewData::searchScalar(double x, double y, double z, double *values,
                             int step, double *size, int qn, double *qx,
                             double *qy, double *qz, bool grad, int dim)
{
  if(!_octree) {
#pragma omp barrier
#pragma omp single
    {
      Msg::Debug("Rebuilding octree for view data '%s'", _name.c_str());
      _octree = new OctreePost(this);
    }
  }
  return _octree->searchScalar(x, y, z, values, step, size, qn, qx, qy, qz,
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
  if(!_octree) {
#pragma omp barrier
#pragma omp single
    {
      Msg::Debug("Rebuilding octree for view data '%s'", _name.c_str());
      _octree = new OctreePost(this);
    }
  }
  return _octree->searchVector(x, y, z, values, step, size, qn, qx, qy, qz,
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
  if(!_octree) {
#pragma omp barrier
#pragma omp single
    {
      Msg::Debug("Rebuilding octree for view data '%s'", _name.c_str());
      _octree = new OctreePost(this);
    }
  }
  return _octree->searchTensor(x, y, z, values, step, size, qn, qx, qy, qz,
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
