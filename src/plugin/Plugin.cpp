// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <sstream>
#include <stdio.h>
#include <string.h>
#include "GmshConfig.h"
#include "Plugin.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "PViewDataGModel.h"
#include "shapeFunctions.h"
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

GMSH_Plugin *GMSH_Plugin::preview = nullptr;

GMSH_Plugin::GMSH_Plugin(const std::vector<StringXNumber> &numOptions,
                         const std::vector<StringXString> &strOptions)
  : dialogBox(nullptr), _numOptions(numOptions), _numDefaults(numOptions),
    _strOptions(strOptions), _strDefaults(strOptions)
{
}

StringXNumber *GMSH_Plugin::findOption(const std::string &name)
{
  auto it = _aliases.find(name);
  const std::string &n = (it == _aliases.end()) ? name : it->second;
  for(int i = 0; i < getNbOptions(); i++)
    if(n == getOption(i)->str) return getOption(i);
  return nullptr;
}

StringXString *GMSH_Plugin::findOptionStr(const std::string &name)
{
  auto it = _aliases.find(name);
  const std::string &n = (it == _aliases.end()) ? name : it->second;
  for(int i = 0; i < getNbOptionsStr(); i++)
    if(n == getOptionStr(i)->str) return getOptionStr(i);
  return nullptr;
}

void GMSH_Plugin::addOptionAlias(const std::string &alias,
                                 const std::string &name)
{ _aliases[alias] = name; }

void GMSH_Plugin::resetOptions()
{
  _numOptions = _numDefaults;
  _strOptions = _strDefaults;
}

bool GMSH_Plugin::optionCallback(int iopt, int num, int action, double &value)
{
  // the function of the option, for plugins that give one
  auto f = getOption(iopt)->function;
  if(!f) return false;
  value = f(num, action, value);
  return true;
}

bool GMSH_Plugin::optionStrCallback(int iopt, int num, int action,
                                    std::string &value)
{
  auto f = getOptionStr(iopt)->function;
  if(!f) return false;
  value = f(num, action, value);
  return true;
}

bool GMSH_Plugin::sliderOption(int iopt, int action, double &value, double step,
                               double min, double max)
{
  switch(action) {
  case 1: value = step; break;
  case 2: value = min; break;
  case 3: value = max; break;
  default:
    option(iopt) = value;
    setPreview(this);
    break;
  }
  return true;
}

void GMSH_Plugin::setPreview(GMSH_Plugin *p)
{
  preview = p;
#if defined(HAVE_OPENGL)
  if(!p) return;
  int old = CTX::instance()->drawBBox;
  CTX::instance()->drawBBox = 1;
  if(CTX::instance()->fastRedraw) {
    CTX::instance()->post.draw = 0;
    CTX::instance()->mesh.draw = 0;
  }
  drawContext::global()->draw();
  CTX::instance()->drawBBox = old;
  CTX::instance()->post.draw = 1;
  CTX::instance()->mesh.draw = 1;
#endif
}

std::string GMSH_Plugin::serialize()
{
  std::ostringstream sstream;
  for(int i = 0; i < getNbOptionsStr(); i++)
    sstream << "Plugin(" << getName() << ")." << getOptionStr(i)->str << "= \""
            << getOptionStr(i)->def << "\";\n";
  for(int i = 0; i < getNbOptions(); i++)
    sstream << "Plugin(" << getName() << ")." << getOption(i)->str << "="
            << getOption(i)->def << ";\n";
  sstream << "Plugin(" << getName() << ").Run;\n";
  return sstream.str();
}

PView *GMSH_PostPlugin::executeRemote(PView *view)
{
  int j = -1, remoteIndex = -1;
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    if(PView::list[i]->getData()->isRemote()) j++;
    if(PView::list[i]->getTag() == view->getTag()) {
      remoteIndex = j;
      break;
    }
  }
  if(remoteIndex < 0) {
    Msg::Error("Unable to determine index of remote view");
    return view;
  }

  for(int i = 0; i < getNbOptions(); i++)
    if(std::string(getOption(i)->str) == "View")
      getOption(i)->def = remoteIndex;

  std::string options = serialize();
  view->getData()->fillRemoteVertexArrays(options);
  return view;
}

PView *GMSH_PostPlugin::getView(int index, PView *view)
{
  if(index < 0) index = view ? view->getIndex() : PView::list.size() - 1;

  if(index >= 0 && index < (int)PView::list.size()) {
    return PView::list[index];
  }
  else {
    Msg::Error("View[%d] does not exist", index);
    return nullptr;
  }
}

PViewData *GMSH_PostPlugin::getPossiblyAdaptiveData(PView *view)
{
  if(!view) return nullptr;
  PViewData *data = view->getData();
  if(data->getAdaptiveData() && data->getNumTimeSteps() > 1)
    Msg::Warning(
      "Using adapted data from view '%s': only the current time step (%d/%d) "
      "is available to the plugin",
      view->getData()->getName().c_str(), view->getOptions()->timeStep,
      data->getNumTimeSteps());
  return view->getData(true);
}

PViewDataList *GMSH_PostPlugin::getDataList(PView *view, bool showError)
{
  if(!view) return nullptr;

  PViewDataList *data = dynamic_cast<PViewDataList *>(view->getData());
  if(data)
    return data;
  else if(showError)
    Msg::Error(
      "This plugin can only be run on list-based views (`.pos' files)");
  return nullptr;
}

static int numCorners(int type)
{
  switch(type) {
  case TYPE_PNT: return 1;
  case TYPE_LIN: return 2;
  case TYPE_TRI: return 3;
  case TYPE_QUA: return 4;
  case TYPE_TET: return 4;
  case TYPE_PYR: return 5;
  case TYPE_PRI: return 6;
  case TYPE_HEX: return 8;
  default: return 0; // polytopes: all their nodes
  }
}

int GMSH_PostPlugin::getNumCornerNodes(PViewData *data, int step, int ent,
                                       int ele) const
{
  PViewDataGModel *gm = dynamic_cast<PViewDataGModel *>(data);
  if(gm && gm->getType() == PViewDataGModel::GaussPointData) {
    if(!_warnedGauss)
      Msg::Warning("Plugin(%s) skips Gauss point data", getName().c_str());
    _warnedGauss = true;
    return 0;
  }
  int numNodes = data->getNumNodes(step, ent, ele);
  int nc = numCorners(data->getType(step, ent, ele));
  if(!nc || numNodes <= nc) return numNodes;
  if(!_warnedCorners)
    Msg::Warning("Plugin(%s) only uses the corners of high order elements",
                 getName().c_str());
  _warnedCorners = true;
  return nc;
}

void GMSH_PostPlugin::forEachNode(
  PViewData *data,
  const std::function<void(int step, int ent, int ele, int nod)> &f,
  int dim) const
{
  PViewDataGModel *gm = dynamic_cast<PViewDataGModel *>(data);
  if(gm && gm->getType() == PViewDataGModel::GaussPointData) {
    Msg::Warning("Plugin(%s) cannot move the points of Gauss point data",
                 getName().c_str());
    return;
  }
  int step = data->getFirstNonEmptyTimeStep();
  auto skip = [&](int ent, int ele) {
    return data->skipElement(step, ent, ele) ||
           (dim >= 0 && data->getDimension(step, ent, ele) != dim);
  };
  if(gm) { // tag the nodes of the mesh, to visit each once
    for(int ent = 0; ent < data->getNumEntities(step); ent++)
      for(int ele = 0; ele < data->getNumElements(step, ent); ele++)
        if(!skip(ent, ele))
          for(int nod = 0; nod < data->getNumNodes(step, ent, ele); nod++)
            data->tagNode(step, ent, ele, nod, 0);
  }
  for(int ent = 0; ent < data->getNumEntities(step); ent++) {
    for(int ele = 0; ele < data->getNumElements(step, ent); ele++) {
      if(skip(ent, ele)) continue;
      for(int nod = 0; nod < data->getNumNodes(step, ent, ele); nod++) {
        if(gm) {
          double x, y, z;
          if(data->getNode(step, ent, ele, nod, x, y, z)) continue;
          data->tagNode(step, ent, ele, nod, 1);
        }
        f(step, ent, ele, nod);
      }
    }
  }
}

void GMSH_PostPlugin::forEachValue(
  PViewData *data, int step,
  const std::function<void(int ent, int ele, int nod, double x, double y,
                           double z)> &f) const
{
  if(!data->hasTimeStep(step)) return;
  PViewDataGModel *gm = dynamic_cast<PViewDataGModel *>(data);
  bool nodeData = gm && gm->getType() == PViewDataGModel::NodeData;
  bool elementData = gm && gm->getType() == PViewDataGModel::ElementData;
  if(nodeData) {
    for(int ent = 0; ent < data->getNumEntities(step); ent++)
      for(int ele = 0; ele < data->getNumElements(step, ent); ele++)
        if(!data->skipElement(step, ent, ele))
          for(int nod = 0; nod < data->getNumNodes(step, ent, ele); nod++)
            data->tagNode(step, ent, ele, nod, 0);
  }
  for(int ent = 0; ent < data->getNumEntities(step); ent++) {
    for(int ele = 0; ele < data->getNumElements(step, ent); ele++) {
      if(data->skipElement(step, ent, ele)) continue;
      int numNodes = data->getNumNodes(step, ent, ele);
      if(elementData) {
        double xc = 0., yc = 0., zc = 0.;
        for(int nod = 0; nod < numNodes; nod++) {
          double x, y, z;
          data->getNode(step, ent, ele, nod, x, y, z);
          xc += x / numNodes;
          yc += y / numNodes;
          zc += z / numNodes;
        }
        f(ent, ele, 0, xc, yc, zc);
        continue;
      }
      for(int nod = 0; nod < numNodes; nod++) {
        double x, y, z;
        int tag = data->getNode(step, ent, ele, nod, x, y, z);
        if(nodeData) {
          if(tag) continue;
          data->tagNode(step, ent, ele, nod, 1);
        }
        f(ent, ele, nod, x, y, z);
      }
    }
  }
}

PluginElement::~PluginElement() { delete _shape; }

element *PluginElement::shape() const
{
  if(!_shape) {
    elementFactory factory;
    _shape = factory.create(numNodes, dim, const_cast<double *>(x.data()),
                            const_cast<double *>(y.data()),
                            const_cast<double *>(z.data()));
  }
  return _shape;
}

void PluginElement::getValues(PViewData *data, int step,
                              std::vector<double> &val) const
{
  val.resize(numNodes * numComp);
  for(int nod = 0; nod < numNodes; nod++)
    for(int comp = 0; comp < numComp; comp++)
      data->getValue(step, ent, ele, nod, comp, val[numComp * nod + comp]);
}

void GMSH_PostPlugin::createListData(
  PViewData *data, const std::vector<PViewDataList *> &out,
  const std::function<int(const PluginElement &e)> &numComp,
  const std::function<bool(const PluginElement &e, int step,
                           std::vector<std::vector<double> > &res)> &values)
  const
{
  int step0 = data->getFirstNonEmptyTimeStep();
  std::vector<int> steps;
  for(int step = step0; step < data->getNumTimeSteps(); step++)
    if(data->hasTimeStep(step)) steps.push_back(step);

  std::vector<std::vector<double> > res(out.size()), all(out.size());
  for(int ent = 0; ent < data->getNumEntities(step0); ent++) {
    for(int ele = 0; ele < data->getNumElements(step0, ent); ele++) {
      if(data->skipElement(step0, ent, ele)) continue;
      PluginElement e;
      e.ent = ent;
      e.ele = ele;
      e.numNodes = getNumCornerNodes(data, step0, ent, ele);
      if(!e.numNodes) continue;
      e.type = data->getType(step0, ent, ele);
      e.dim = data->getDimension(step0, ent, ele);
      e.numComp = data->getNumComponents(step0, ent, ele);
      e.x.resize(e.numNodes);
      e.y.resize(e.numNodes);
      e.z.resize(e.numNodes);
      for(int nod = 0; nod < e.numNodes; nod++)
        data->getNode(step0, ent, ele, nod, e.x[nod], e.y[nod], e.z[nod]);
      int nc = numComp(e);
      if(!nc) continue;
      // all the values first: an element is written whole or not at all
      bool ok = true;
      for(auto &a : all) a.clear();
      for(int step : steps) {
        for(auto &r : res) r.clear();
        if(!values(e, step, res)) {
          ok = false;
          break;
        }
        for(std::size_t i = 0; i < out.size(); i++) {
          if((int)res[i].size() != e.numNodes * nc) {
            Msg::Error("Plugin(%s) gave %d values for %d nodes and %d "
                       "components", getName().c_str(), (int)res[i].size(),
                       e.numNodes, nc);
            return;
          }
          all[i].insert(all[i].end(), res[i].begin(), res[i].end());
        }
      }
      if(!ok) continue;
      for(std::size_t i = 0; i < out.size(); i++) {
        std::vector<double> *l = out[i]->incrementList(nc, e.type, e.numNodes);
        if(!l) continue;
        l->insert(l->end(), e.x.begin(), e.x.end());
        l->insert(l->end(), e.y.begin(), e.y.end());
        l->insert(l->end(), e.z.begin(), e.z.end());
        l->insert(l->end(), all[i].begin(), all[i].end());
      }
    }
  }
  for(auto o : out)
    for(int step : steps) o->Time.push_back(data->getTime(step));
}
