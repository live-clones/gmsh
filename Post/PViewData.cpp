// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "PViewData.h"
#include "adaptiveData.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "OctreePost.h"
#include "fullMatrix.h"

std::map<std::string, interpolationMatrices> PViewData::_interpolationSchemes;

PViewData::PViewData()
  : _dirty(true), _fileIndex(0), _octree(nullptr), _adaptive(nullptr)
{
}

PViewData::~PViewData()
{
  if(_adaptive) delete _adaptive;
  for(auto it = _interpolation.begin(); it != _interpolation.end(); it++)
    for(std::size_t i = 0; i < it->second.size(); i++) delete it->second[i];
  if(_octree) delete _octree;
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

bool PViewData::searchScalar(double x, double y, double z, double *values,
                             int step, double *size, int qn, double *qx,
                             double *qy, double *qz, bool grad, int dim)
{
  if(!_octree) _octree = new OctreePost(this);
  return _octree->searchScalar(x, y, z, values, step, size, qn, qx, qy, qz,
                               grad, dim);
}

bool PViewData::searchScalarWithTol(double x, double y, double z,
                                    double *values, int step, double *size,
                                    double tol, int qn, double *qx, double *qy,
                                    double *qz, bool grad, int dim)
{
  if(!_octree) _octree = new OctreePost(this);
  return _octree->searchScalarWithTol(x, y, z, values, step, size, tol, qn, qx,
                                      qy, qz, grad, dim);
}

bool PViewData::searchVector(double x, double y, double z, double *values,
                             int step, double *size, int qn, double *qx,
                             double *qy, double *qz, bool grad, int dim)
{
  if(!_octree) _octree = new OctreePost(this);
  return _octree->searchVector(x, y, z, values, step, size, qn, qx, qy, qz,
                               grad, dim);
}

bool PViewData::searchVectorWithTol(double x, double y, double z,
                                    double *values, int step, double *size,
                                    double tol, int qn, double *qx, double *qy,
                                    double *qz, bool grad, int dim)
{
  if(!_octree) _octree = new OctreePost(this);
  return _octree->searchVectorWithTol(x, y, z, values, step, size, tol, qn, qx,
                                      qy, qz, grad, dim);
}

bool PViewData::searchTensor(double x, double y, double z, double *values,
                             int step, double *size, int qn, double *qx,
                             double *qy, double *qz, bool grad, int dim)
{
  if(!_octree) _octree = new OctreePost(this);
  return _octree->searchTensor(x, y, z, values, step, size, qn, qx, qy, qz,
                               grad, dim);
}

bool PViewData::searchTensorWithTol(double x, double y, double z,
                                    double *values, int step, double *size,
                                    double tol, int qn, double *qx, double *qy,
                                    double *qz, bool grad, int dim)
{
  if(!_octree) _octree = new OctreePost(this);
  return _octree->searchTensorWithTol(x, y, z, values, step, size, tol, qn, qx,
                                      qy, qz, grad, dim);
}
