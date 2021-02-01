// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <algorithm>
#include "PView.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "PViewOptions.h"
#include "VertexArray.h"
#include "SmoothData.h"
#include "adaptiveData.h"
#include "GmshMessage.h"

int PView::_globalTag = 0;
std::vector<PView *> PView::list;

void PView::_init(int tag)
{
  if(tag >= 0) {
    _tag = tag;
    _globalTag = std::max(_globalTag, _tag) + 1;
  }
  else {
    _tag = _globalTag++;
  }

  _changed = true;
  _aliasOf = -1;
  _eye = SPoint3(0., 0., 0.);
  va_points = va_lines = va_triangles = va_vectors = va_ellipses = nullptr;
  normals = nullptr;

  for(std::size_t i = 0; i < list.size(); i++) {
    if(list[i]->getTag() == _tag) {
      // in normal operation this should not happen, but we allow it when
      // programmatically forcing view tags (e.g. when using the views from
      // within getdp's post-processing operations); this is dangerous, as it
      // breaks aliases
      Msg::Info("Removing existing View[%d] (tag = %d)", i, _tag);
      delete list[i]; // warning: this changes the list
    }
  }

  list.push_back(this);
  for(std::size_t i = 0; i < list.size(); i++) list[i]->setIndex(i);
}

PView::PView(int tag)
{
  _init(tag);
  _data = new PViewDataList();
  _options = new PViewOptions(*PViewOptions::reference());
  if(_options->adaptVisualizationGrid)
    _data->initAdaptiveData(_options->timeStep, _options->maxRecursionLevel,
                            _options->targetError);
}

PView::PView(PViewData *data, int tag)
{
  _init(tag);
  _data = data;
  _options = new PViewOptions(*PViewOptions::reference());
  if(_options->adaptVisualizationGrid)
    _data->initAdaptiveData(_options->timeStep, _options->maxRecursionLevel,
                            _options->targetError);
}

PView::PView(PView *ref, bool copyOptions, int tag)
{
  _init(tag);

  if(ref->getAliasOf() >= 0) { // alias of an alias
    PView *orig = getViewByTag(ref->getAliasOf());
    if(orig)
      _aliasOf = orig->getTag();
    else {
      Msg::Warning("Original view for alias does not exist anymore");
      _aliasOf = ref->getTag();
    }
  }
  else
    _aliasOf = ref->getTag();

  _data = ref->getData();
  if(copyOptions)
    _options = new PViewOptions(*ref->getOptions());
  else
    _options = new PViewOptions(*PViewOptions::reference());
  if(_options->adaptVisualizationGrid)
    _data->initAdaptiveData(_options->timeStep, _options->maxRecursionLevel,
                            _options->targetError);
}

PView::PView(const std::string &xname, const std::string &yname,
             std::vector<double> &x, std::vector<double> &y)
{
  _init();
  _data = new PViewDataList();
  _data->setXY(x, y);
  _data->setName(yname);
  _data->setFileName(yname + ".pos");
  _options = new PViewOptions(*PViewOptions::reference());
  _options->type = PViewOptions::Plot2D;
  _options->axes = 3;
  _options->lineWidth = 2.;
  _options->pointSize = 4.;
  _options->axesLabel[0] = xname;
}

void PView::addStep(std::vector<double> &y)
{
  PViewDataList *d = dynamic_cast<PViewDataList *>(_data);
  if(d)
    d->addStep(y);
  else
    Msg::Error("Can only add step data to list-based datasets");
}

PView::PView(const std::string &name, std::vector<double> &x,
             std::vector<double> &y, std::vector<double> &z,
             std::vector<double> &v)
{
  _init();
  _data = new PViewDataList();
  _data->setXYZV(x, y, z, v);
  _data->setName(name);
  _data->setFileName(name + ".pos");
  _options = new PViewOptions(*PViewOptions::reference());
  _options->axes = 3;
  _options->pointSize = 7.;
  _options->pointType = 1.;
}

PView::PView(const std::string &name, const std::string &type, GModel *model,
             std::map<int, std::vector<double> > &data, double time,
             int numComp, int tag)
{
  _init(tag);
  PViewDataGModel::DataType t;
  if(type == "NodeData")
    t = PViewDataGModel::NodeData;
  else if(type == "ElementData")
    t = PViewDataGModel::ElementData;
  else if(type == "ElementNodeData")
    t = PViewDataGModel::ElementNodeData;
  else if(type == "Beam")
    t = PViewDataGModel::BeamData;
  else {
    Msg::Error("Unknown type of view to create '%s'", type.c_str());
    return;
  }
  PViewDataGModel *d = new PViewDataGModel(t);
  d->addData(model, data, 0, time, 1, numComp);
  d->setName(name);
  d->setFileName(name + ".msh");
  _data = d;
  _options = new PViewOptions(*PViewOptions::reference());
  if(_options->adaptVisualizationGrid)
    _data->initAdaptiveData(_options->timeStep, _options->maxRecursionLevel,
                            _options->targetError);
}

void PView::addStep(GModel *model,
                    const std::map<int, std::vector<double> > &data,
                    double time, int numComp)
{
  PViewDataGModel *d = dynamic_cast<PViewDataGModel *>(_data);
  if(d)
    d->addData(model, data, d->getNumTimeSteps(), time, 1, numComp);
  else
    Msg::Error("Can only add step data to mesh-based datasets");
}

PView::~PView()
{
  deleteVertexArrays();
  if(normals) delete normals;
  if(_options) delete _options;

  auto it = std::find(list.begin(), list.end(), this);
  if(it != list.end()) list.erase(it);
  for(std::size_t i = 0; i < list.size(); i++) list[i]->setIndex(i);

  if(!_data) return;

  // do not delete if another view is an alias of this one
  for(std::size_t i = 0; i < list.size(); i++)
    if(list[i]->getAliasOf() == _tag) return;

  // do not delete if this view is an alias and 1) if the original
  // still exists, or 2) if there are other aliases to the same view
  if(_aliasOf >= 0)
    for(std::size_t i = 0; i < list.size(); i++)
      if(list[i]->getTag() == _aliasOf || list[i]->getAliasOf() == _aliasOf)
        return;

  Msg::Debug("Deleting data in View[%d] (tag = %d)", _index, _tag);
  delete _data;
}

int PView::getGlobalTag() { return _globalTag; }

void PView::setGlobalTag(int tag) { _globalTag = tag; }

void PView::deleteVertexArrays()
{
  if(va_points) delete va_points;
  va_points = nullptr;
  if(va_lines) delete va_lines;
  va_lines = nullptr;
  if(va_triangles) delete va_triangles;
  va_triangles = nullptr;
  if(va_vectors) delete va_vectors;
  va_vectors = nullptr;
  if(va_ellipses) delete va_ellipses;
  va_ellipses = nullptr;
}

void PView::setOptions(PViewOptions *val)
{
  // deep copy options
  if(val)
    *_options = *val;
  else if(_options)
    *_options = *PViewOptions::reference();
}

PViewData *PView::getData(bool useAdaptiveIfAvailable)
{
  if(useAdaptiveIfAvailable && _data->getAdaptiveData() && !_data->isRemote())
    return _data->getAdaptiveData()->getData();
  else
    return _data;
}

void PView::setChanged(bool val)
{
  _changed = val;
  // reset the eye position everytime we change the view so that the
  // arrays get resorted for transparency
  if(_changed) _eye = SPoint3(0., 0., 0.);
}

void PView::combine(bool time, int how, bool remove, bool copyOptions)
{
  // time == true: combine the timesteps (oherwise combine the elements)
  // how == 0: try to combine all visible views
  //        1: try to combine all views
  //        2: try to combine all views having identical names

  std::vector<nameData> nds;
  for(std::size_t i = 0; i < list.size(); i++) {
    PView *p = list[i];
    PViewData *data = p->getData();
    if(how || p->getOptions()->visible) {
      nameData nd;
      // this will lead to weird results if there are views named
      // "__all__" or "__vis__" :-)
      if(how == 2)
        nd.name = data->getName();
      else if(how == 1)
        nd.name = "__all__";
      else
        nd.name = "__vis__";
      std::size_t j = 0;
      while(j < nds.size()) {
        if(nds[j].name == nd.name) {
          nds[j].data.push_back(data);
          nds[j].indices.push_back(i);
          break;
        }
        j++;
      }
      if(j == nds.size()) {
        nd.data.push_back(data);
        nd.indices.push_back(i);
        nd.options = p->getOptions();
        nds.push_back(nd);
      }
    }
  }

  std::set<PView *> rm;
  for(std::size_t i = 0; i < nds.size(); i++) {
    if(nds[i].data.size() > 1) { // there's potentially something to combine
      // sanity checks:
      bool allListBased = true, allModelBased = true;
      for(std::size_t j = 0; j < nds[i].data.size(); j++) {
        PViewDataList *d1 = dynamic_cast<PViewDataList *>(nds[i].data[j]);
        if(!d1) allListBased = false;
        PViewDataGModel *d2 = dynamic_cast<PViewDataGModel *>(nds[i].data[j]);
        if(!d2) allModelBased = false;
      }
      PViewData *data = nullptr;
      if(allListBased) { data = new PViewDataList(); }
      else if(allModelBased) {
        PViewDataGModel *d2 = dynamic_cast<PViewDataGModel *>(nds[i].data[0]);
        data = new PViewDataGModel(d2->getType());
      }
      else {
        Msg::Error("Cannot combine hybrid list/mesh-based datasets");
        continue;
      }
      PView *p = new PView(data);
      bool res = time ? data->combineTime(nds[i]) : data->combineSpace(nds[i]);
      if(res) {
        for(std::size_t j = 0; j < nds[i].indices.size(); j++)
          rm.insert(list[nds[i].indices[j]]);
        PViewOptions *opt = p->getOptions();
        if(opt->adaptVisualizationGrid) {
          // the (empty) adaptive data created in PView() must be recreated,
          // since we added some data
          data->destroyAdaptiveData();
          data->initAdaptiveData(opt->timeStep, opt->maxRecursionLevel,
                                 opt->targetError);
        }
        if(copyOptions && nds[i].options)
          p->setOptions(new PViewOptions(*nds[i].options));
      }
      else
        delete p;
    }
  }
  if(remove)
    for(auto it = rm.begin(); it != rm.end(); it++) delete *it;
}

class PViewLessThanName {
public:
  bool operator()(PView *v1, PView *v2) const
  {
    return v1->getData()->getName() < v2->getData()->getName();
  }
};

void PView::sortByName()
{
  std::sort(list.begin(), list.end(), PViewLessThanName());
  for(std::size_t i = 0; i < list.size(); i++) list[i]->setIndex(i);
}

PView *PView::getViewByName(const std::string &name, int timeStep,
                            int partition, const std::string &fileName)
{
  // search views from most recently to least recently added
  for(int i = list.size() - 1; i >= 0; i--) {
    if(list[i]->getData()->getName() == name &&
       ((timeStep < 0 || !list[i]->getData()->hasTimeStep(timeStep)) ||
        (partition < 0 ||
         !list[i]->getData()->hasPartition(timeStep, partition))) &&
       (fileName.empty() || !list[i]->getData()->hasFileName(fileName)))
      return list[i];
  }
  return nullptr;
}

PView *PView::getViewByFileName(const std::string &fileName, int timeStep,
                                int partition)
{
  // search views from most recently to least recently added
  for(int i = list.size() - 1; i >= 0; i--) {
    if(list[i]->getData()->getFileName() == fileName &&
       ((timeStep < 0 || !list[i]->getData()->hasTimeStep(timeStep)) ||
        (partition < 0 ||
         !list[i]->getData()->hasPartition(timeStep, partition))))
      return list[i];
  }
  return nullptr;
}

PView *PView::getViewByTag(int tag, int timeStep, int partition)
{
  for(std::size_t i = 0; i < list.size(); i++) {
    if(list[i]->getTag() == tag &&
       ((timeStep < 0 || !list[i]->getData()->hasTimeStep(timeStep)) ||
        (partition < 0 ||
         !list[i]->getData()->hasPartition(timeStep, partition))))
      return list[i];
  }
  return nullptr;
}

double PView::getMemoryInMb()
{
  double mem = 0;
  if(va_points) mem += va_points->getMemoryInMb();
  if(va_lines) mem += va_lines->getMemoryInMb();
  if(va_triangles) mem += va_triangles->getMemoryInMb();
  if(va_vectors) mem += va_vectors->getMemoryInMb();
  if(va_ellipses) mem += va_ellipses->getMemoryInMb();
  mem += getData()->getMemoryInMb();
  return mem;
}
