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
#include "Context.h"

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

void (*GMSH_Plugin::draw)(void *) = nullptr;

void GMSH_Plugin::setDrawFunction(void (*fct)(void *))
{
#if defined(HAVE_OPENGL)
  draw = fct;
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

void GMSH_Plugin::catchErrorMessage(char *errorMessage) const
{
  std::string str = getName() + "failed...";
  strcpy(errorMessage, str.c_str());
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
