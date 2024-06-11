// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PViewDataGModel.h"
#include "MVertex.h"
#include "MElement.h"
#include "Numeric.h"
#include "fullMatrix.h"
#include "StringUtils.h"
#include "OS.h"

bool PViewDataGModel::addData(GModel *model,
                              const std::map<int, std::vector<double> > &data,
                              int step, double time, int partition, int numComp)
{
  if(data.empty()) return false;
  if(step < 0) return false;

  if(numComp < 0) {
    numComp = 9;
    for(auto it = data.begin(); it != data.end(); it++)
      numComp = std::min(numComp, (int)it->second.size());
  }

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(model, numComp));
  _steps[step]->fillEntities();
  _steps[step]->computeBoundingBox();
  _steps[step]->setTime(time);

  int numEnt = (_type == NodeData) ? model->getNumMeshVertices() :
                                     model->getNumMeshElements();
  _steps[step]->resizeData(numEnt);

  for(auto it = data.begin(); it != data.end(); it++) {
    int mult = it->second.size() / numComp;
    double *d = _steps[step]->getData(it->first, true, mult);
    for(int j = 0; j < numComp * mult; j++) d[j] = it->second[j];
  }
  if(partition >= 0) _steps[step]->getPartitions().insert(partition);
  finalize();
  return true;
}

bool PViewDataGModel::addData(GModel *model,
                              const std::vector<std::size_t> &tags,
                              const std::vector<std::vector<double> > &data,
                              int step, double time, int partition, int numComp)
{
  if(data.empty() || tags.empty() || data.size() != tags.size()) return false;

  if(numComp < 0) {
    if(_type == ElementNodeData) {
      numComp = 1; // cannot infer, as we can have different element types
    }
    else {
      numComp = 9;
      for(std::size_t i = 0; i < data.size(); i++)
        numComp = std::min(numComp, (int)data[i].size());
    }
  }

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(model, numComp));
  _steps[step]->fillEntities();
  _steps[step]->computeBoundingBox();
  _steps[step]->setTime(time);

  int numEnt = (_type == NodeData) ? model->getNumMeshVertices() :
                                     model->getNumMeshElements();
  _steps[step]->resizeData(numEnt);

  for(std::size_t i = 0; i < data.size(); i++) {
    int mult = data[i].size() / numComp;
    double *d = _steps[step]->getData(tags[i], true, mult);
    for(int j = 0; j < numComp * mult; j++) d[j] = data[i][j];
  }
  if(partition >= 0) _steps[step]->getPartitions().insert(partition);
  finalize();
  return true;
}

bool PViewDataGModel::addData(GModel *model,
                              const std::vector<std::size_t> &tags,
                              const std::vector<double> &data, int step,
                              double time, int partition, int numComp)
{
  if(data.empty() || tags.empty()) return false;

  std::size_t stride = data.size() / tags.size();
  if(stride < 1) return false;

  if(numComp < 0) {
    if(_type == ElementNodeData) {
      numComp = 1; // cannot infer, as we can have different element types
    }
    else {
      numComp = (int)stride;
    }
  }

  while(step >= (int)_steps.size())
    _steps.push_back(new stepData<double>(model, numComp));
  _steps[step]->fillEntities();
  _steps[step]->computeBoundingBox();
  _steps[step]->setTime(time);

  int numEnt = (_type == NodeData) ? model->getNumMeshVertices() :
                                     model->getNumMeshElements();
  _steps[step]->resizeData(numEnt);

  int mult = stride / numComp;
  for(std::size_t i = 0; i < tags.size(); i++) {
    double *d = _steps[step]->getData(tags[i], true, mult);
    int k = i * stride;
    for(std::size_t j = 0; j < stride; j++) d[j] = data[k + j];
  }
  if(partition >= 0) _steps[step]->getPartitions().insert(partition);
  finalize();
  return true;
}

void PViewDataGModel::destroyData()
{
  for(std::size_t i = 0; i < _steps.size(); i++) _steps[i]->destroyData();
}

void PViewDataGModel::importLists(int N[24], std::vector<double> *V[24])
{
  for(int idxtype = 0; idxtype < 24; idxtype++) {
    int nbe = N[idxtype];
    if(!nbe) continue;
    std::vector<double> *list = V[idxtype];
    int nc = 0, nn = 0;
    switch(idxtype) {
    case 0:
      nc = 1;
      nn = 1;
      break; // SP
    case 1:
      nc = 3;
      nn = 1;
      break; // VP
    case 2:
      nc = 9;
      nn = 1;
      break; // TP
    case 3:
      nc = 1;
      nn = 2;
      break; // SL
    case 4:
      nc = 3;
      nn = 2;
      break; // VL
    case 5:
      nc = 9;
      nn = 2;
      break; // TL
    case 6:
      nc = 1;
      nn = 3;
      break; // ST
    case 7:
      nc = 3;
      nn = 3;
      break; // VT
    case 8:
      nc = 9;
      nn = 3;
      break; // TT
    case 9:
      nc = 1;
      nn = 4;
      break; // SQ
    case 10:
      nc = 3;
      nn = 4;
      break; // VQ
    case 11:
      nc = 9;
      nn = 4;
      break; // TQ
    case 12:
      nc = 1;
      nn = 4;
      break; // SS
    case 13:
      nc = 3;
      nn = 4;
      break; // VS
    case 14:
      nc = 9;
      nn = 4;
      break; // TS
    case 15:
      nc = 1;
      nn = 8;
      break; // SH
    case 16:
      nc = 3;
      nn = 8;
      break; // VH
    case 17:
      nc = 9;
      nn = 8;
      break; // TH
    case 18:
      nc = 1;
      nn = 6;
      break; // SI
    case 19:
      nc = 3;
      nn = 6;
      break; // VI
    case 20:
      nc = 9;
      nn = 6;
      break; // TI
    case 21:
      nc = 1;
      nn = 5;
      break; // SY
    case 22:
      nc = 3;
      nn = 5;
      break; // VY
    case 23:
      nc = 9;
      nn = 5;
      break; // TY
    }
    int stride = list->size() / nbe;
    int numSteps = (stride - 1) / nc / nn;
    for(int step = 0; step < numSteps; step++) {
      _steps.push_back(new stepData<double>(GModel::current(), nc));
      _steps[step]->fillEntities();
      _steps[step]->computeBoundingBox();
      _steps[step]->setTime(step);
      _steps[step]->resizeData(nbe);
      for(std::size_t j = 0; j < list->size(); j += stride) {
        double *tmp = &(*list)[j];
        int num = (int)tmp[0];
        double *d = _steps[step]->getData(num, true, nn);
        for(int k = 0; k < nc * nn; k++) { d[k] = tmp[1 + nc * nn * step + k]; }
      }
    }
  }

  finalize();
}

bool PViewDataGModel::readPCH(const std::string &fileName, int fileIndex)
{
  Msg::Info("Placeholder for reading punch file '%s'", fileName.c_str());

  std::map<int, std::vector<double> > data;
  for(int i = 1; i < 200; i++) data[i].push_back(1.234);
  addData(GModel::current(), data, 0, 0.0, 1, 1);

  return true;
}

void PViewDataGModel::sendToServer(const std::string &name)
{
  if(_steps.empty()) return;

  if(_type != NodeData) {
    Msg::Error("sendToServer currently only implemented for nodal datasets");
    return;
  }

  int numEnt = 0, numComp = 0;
  for(std::size_t step = 0; step < _steps.size(); step++) {
    int nc = _steps[step]->getNumComponents();
    int ne = 0;
    for(std::size_t i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) ne++;
    if(!step) {
      numEnt = ne;
      numComp = nc;
    }
    else {
      if(ne != numEnt || nc != numComp) {
        Msg::Error("Can not send heterogeneous view to server");
        return;
      }
    }
  }

  std::vector<double> exp;
  exp.push_back(numEnt);

  for(std::size_t i = 0; i < _steps[0]->getNumData(); i++) {
    if(_steps[0]->getData(i)) {
      MVertex *v = _steps[0]->getModel()->getMeshVertexByTag(i);
      if(!v) {
        Msg::Error("Unknown node %d in data", i);
        return;
      }
      int num = v->getNum();
      exp.push_back(num);
      for(std::size_t step = 0; step < _steps.size(); step++) {
        for(int k = 0; k < numComp; k++) {
          double data = _steps[step]->getData(i)[k];
          exp.push_back(data);
        }
      }
    }
  }

  Msg::SetOnelabNumber(name, exp, false);
}
