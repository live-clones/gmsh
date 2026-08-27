// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The per-entity ONELAB parameters, counterpart of onelabContextWindow. It
// opens when an entity whose double-click command is "ONELAB" is double-clicked
// in the 3D view, and shows the parameters instantiated from the
// "ONELAB Context/<Dim> Template/..." templates by
// GuiActions::onelabContextInstantiate(), which the FLTK interface uses too.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdio>
#include <map>
#include <string>
#include <vector>

#include "imgui.h"

#include "appWindow.h"
#include "Gui.h"
#include "GuiActions.h"
#include "GmshMessage.h"
#include "Context.h"
#include "GModel.h"
#include "GEntity.h"
#include "drawContext.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#include "onelabWidgets.h"
#endif

void appWindow::showContextWindow(int dim, int tag)
{
  _contextDim = dim;
  _contextTag = tag;
  _contextChoice = 0;
  _showOnelabContext = true;
}

void appWindow::_drawOnelabContextPanel()
{
  if(!_showOnelabContext) return;

  ImGui::SetNextWindowSize(ImVec2(360, 420), ImGuiCond_FirstUseEver);
  char title[128];
  static const char *dims[4] = {"Point", "Curve", "Surface", "Volume"};
  snprintf(title, sizeof(title), "%s %d###gmshOnelabContext",
           (_contextDim >= 0 && _contextDim < 4) ? dims[_contextDim] : "Entity",
           _contextTag);
  if(!ImGui::Begin(title, &_showOnelabContext)) {
    ImGui::End();
    return;
  }

#if defined(HAVE_ONELAB)
  if(_contextDim < 0 || _contextDim > 3) {
    ImGui::TextDisabled("No entity selected");
    ImGui::End();
    return;
  }

  // the parameters can be attached to the entity itself or to one of the
  // physical groups it belongs to
  std::map<int, std::vector<GEntity *> > groups;
  GModel::current()->getPhysicalGroups(_contextDim, groups);
  std::vector<int> containing;
  for(auto &g : groups)
    for(auto e : g.second)
      if(e && e->tag() == _contextTag) {
        containing.push_back(g.first);
        break;
      }

  std::vector<std::string> labels;
  labels.push_back(std::string(dims[_contextDim]) + " " +
                   std::to_string(_contextTag));
  for(auto g : containing)
    labels.push_back("Physical " + std::string(dims[_contextDim]) + " " +
                     std::to_string(g));
  if(_contextChoice >= (int)labels.size()) _contextChoice = 0;

  if(labels.size() > 1) {
    ImGui::SetNextItemWidth(-1.f);
    if(ImGui::BeginCombo("##what", labels[_contextChoice].c_str())) {
      for(int i = 0; i < (int)labels.size(); i++)
        if(ImGui::Selectable(labels[i].c_str(), _contextChoice == i))
          _contextChoice = i;
      ImGui::EndCombo();
    }
    ImGui::Separator();
  }

  bool physical = (_contextChoice > 0);
  int physicalTag = physical ? containing[_contextChoice - 1] : 0;

  std::vector<std::string> names;
  onelabContextInstantiate(_contextDim, _contextTag, physical, physicalTag,
                           names);

  if(names.empty()) {
    ImGui::TextDisabled("No parameters");
    ImGui::TextWrapped("Define parameters named \"ONELAB Context/%s "
                       "Template/...\" to see them here.", dims[_contextDim]);
    ImGui::End();
    return;
  }

  static std::map<std::string, std::string> edits;
  bool changed = false;
  for(auto &name : names) {
    std::vector<onelab::number> pn;
    onelab::server::instance()->get(pn, name);
    if(pn.size()) {
      if(!pn[0].getVisible()) continue;
      if(drawOnelabNumber(pn[0])) {
        onelab::server::instance()->set(pn[0]);
        changed = true;
      }
      continue;
    }
    std::vector<onelab::string> ps;
    onelab::server::instance()->get(ps, name);
    if(ps.size()) {
      if(!ps[0].getVisible()) continue;
      if(drawOnelabString(ps[0], edits)) {
        onelab::server::instance()->set(ps[0]);
        changed = true;
      }
    }
  }

  if(changed && CTX::instance()->solver.autoCheck)
    postAction([]() { onelabRun("check"); });
#else
  ImGui::TextDisabled("Gmsh was compiled without ONELAB support");
#endif

  ImGui::End();
}

#endif
