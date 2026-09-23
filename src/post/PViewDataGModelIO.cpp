// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
  changed();

  if(numComp < 0) {
    numComp = 9;
    for(auto it = data.begin(); it != data.end(); it++)
      numComp = std::min(numComp, (int)it->second.size());
  }

  if(!_getStep(step, model, numComp)) return false;
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
                              const std::vector<std::vector<double>> &data,
                              int step, double time, int partition, int numComp,
                              bool minMax)
{
  if(data.empty() || tags.empty() || data.size() != tags.size()) return false;
  changed();

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

  if(!_getStep(step, model, numComp)) return false;
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
  finalize(minMax);
  return true;
}

bool PViewDataGModel::addData(GModel *model,
                              const std::vector<std::size_t> &tags,
                              const std::vector<double> &data, int step,
                              double time, int partition, int numComp)
{
  if(data.empty() || tags.empty()) return false;
  changed();

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

  if(!_getStep(step, model, numComp)) return false;
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

// the lists (in the order of PViewDataList::getListPointers()) hold, for each
// element, its tag and then its values at each step
void PViewDataGModel::importLists(int N[24], std::vector<double> *V[24])
{
  const int numNodes[8] = {1, 2, 3, 4, 4, 8, 6, 5};
  const int numComps[3] = {1, 3, 9};
  for(int i = 0; i < 24; i++) {
    if(!N[i]) continue;
    std::vector<double> &list = *V[i];
    int nc = numComps[i % 3], nn = numNodes[i / 3];
    int stride = list.size() / N[i];
    int numSteps = (stride - 1) / nc / nn;
    for(int step = 0; step < numSteps; step++) {
      if(!_getStep(step, GModel::current(), nc)) break;
      _steps[step]->setTime(step);
      for(std::size_t j = 0; j < list.size(); j += stride) {
        double *d = _steps[step]->getData((int)list[j], true, nn);
        for(int k = 0; k < nc * nn; k++)
          d[k] = list[j + 1 + nc * nn * step + k];
      }
    }
  }
  finalize();
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
