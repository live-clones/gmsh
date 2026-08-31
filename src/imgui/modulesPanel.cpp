// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The module tree, counterpart of onelabGroup: the Geometry, Mesh, Solver and
// Post-processing modules, the post-processing views with their visibility, and
// the ONELAB parameters of the solvers. The actions it triggers all live in
// GuiActions.cpp and are shared with the FLTK interface.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdio>
#include <functional>
#include <cstring>
#include <map>
#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_stdlib.h"

#include "Tree.h"
#include "uiSources.h"
#include "fieldWidget.h"

#include "appWindow.h"
#include "menuActions.h"
#include "Context.h"
#include "Options.h"

#if defined(HAVE_ONELAB)
#endif


#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

namespace {

#if defined(HAVE_ONELAB)

#endif

} // namespace

#if defined(HAVE_ONELAB)




#endif

// Down the model, asking for the children of what is open rather than being
// handed the whole tree. The modules are open and everything below them
// closed, as the FLTK tree leaves it after its first build.
void appWindow::_walkModules(const std::string &path, int depth)
{
  const Ui::Tree &tree = uiSources().tree;
  for(const auto &child : tree.children(path)) {
    Ui::Node node = tree.node(child);
    std::string label = node.label.size() ?
                          node.label :
                          child.substr(child.find_last_of('/') + 1);
    if(!tree.children(child).empty()) {
      // what the API asked for, if this is one of the branches it named; the
      // request is only spent once the branch has been drawn, so a chain of
      // them unfolds in a single frame
      auto wanted = _treeWanted.find(child);
      if(wanted != _treeWanted.end()) {
        ImGui::SetNextItemOpen(wanted->second);
        _treeWanted.erase(wanted);
      }
      ImGuiTreeNodeFlags flags =
        depth ? ImGuiTreeNodeFlags_None : ImGuiTreeNodeFlags_DefaultOpen;
      if(ImGui::TreeNodeEx(label.c_str(), flags)) {
        _walkModules(child, depth + 1);
        ImGui::TreePop();
      }
      continue;
    }
    if(node.hasField) {
      // A line the description gives a widget to. Half the width is the
      // widget and the rest is its name, as the tree this reproduces splits
      // them.
      ImGui::PushID(child.c_str());
      drawField(node.field, ImGui::GetContentRegionAvail().x * .5f);
      if(node.tooltip.size() && ImGui::BeginItemTooltip()) {
        ImGui::TextUnformatted(node.tooltip.c_str());
        ImGui::EndTooltip();
      }
      ImGui::PopID();
      continue;
    }
    bool enabled = node.enabled ? node.enabled() : true;
    ImGui::BeginDisabled(!enabled);
    if(ImGui::Selectable(label.c_str())) {
      std::function<void()> what = node.pressed;
      // like every other action of the interface, it runs outside the frame
      if(what) postAction(what);
    }
    ImGui::EndDisabled();
  }
}

void appWindow::_drawModulesPanel()
{
  if(!_showModules) return;

  ImGui::SetNextWindowSize(ImVec2(300, 500), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("Modules", &_showModules)) {
    ImGui::End();
    return;
  }

  // The commands come from the described tree, which the FLTK one is built
  // from too. What follows -- the parameters of the solvers and the views --
  // is widgets rather than entries, and is still built here.
  _walkModules("0Modules", 0);

  // ---- Solver
#if defined(HAVE_ONELAB)
  if(ImGui::TreeNodeEx("Solver", ImGuiTreeNodeFlags_DefaultOpen)) {
    const char *b0 = _solverButton0.size() ? _solverButton0.c_str() : "check";
    const char *b1 = _solverButton1.size() ? _solverButton1.c_str() : "compute";
    if(_solverButton0.size()) {
      if(ImGui::Button(b0)) {
        std::string a = b0;
        postAction([a]() { onelabRun(a); });
      }
      ImGui::SameLine();
    }
    if(ImGui::Button(b1)) {
      std::string a = b1;
      postAction([a]() { onelabRun(a); });
    }
    ImGui::SameLine();
    if(ImGui::Button("Reset")) postAction([]() { onelabRun("reset"); });

    ImGui::SameLine();
    // The gear menu, described once in src/common/GuiMenus.cpp: the database,
    // the eight things the solver may do by itself, and adding another solver.
    // This panel offered three of the thirteen, as buttons.
    if(ImGui::SmallButton("Options")) ImGui::OpenPopup("##gear");
    if(ImGui::BeginPopup("##gear")) {
      static std::vector<Ui::MenuItem> gear;
      gear = Menu::solverOptions();
      menuWalk(gear, this);
      ImGui::EndPopup();
    }

    // The solvers that are registered, one line each, as the FLTK tree shows
    // them: clicking one runs it, and what else one may do to it is the menu
    // described in src/common/GuiMenus.cpp.
    for(int i = 0; i < NUM_SOLVERS; i++) {
      std::string name = opt_solver_name(i, GMSH_GET, "");
      if(name.empty()) continue;
      ImGui::PushID(1000 + i);
      if(ImGui::Selectable(name.c_str())) {
        int index = i;
        postAction([index]() { solverStart(index); });
      }
      std::string exe = opt_solver_executable(i, GMSH_GET, "");
      if(exe.size() && ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("%s", exe.c_str());
      if(ImGui::BeginPopupContextItem("##solvermenu")) {
        static std::vector<Ui::MenuItem> menu;
        menu = Menu::solverActions(i);
        menuWalk(menu, this);
        ImGui::EndPopup();
      }
      ImGui::PopID();
    }

    // What a solver has published, which the described tree holds beside
    // the commands: every root of it that is not the commands themselves.
    for(const auto &root : uiSources().tree.children("")) {
      if(root == "0Modules") continue;
      Ui::Node node = uiSources().tree.node(root);
      std::string label = node.label.size() ?
                            node.label :
                            root.substr(root.find_last_of('/') + 1);
      if(ImGui::TreeNodeEx(label.c_str(), ImGuiTreeNodeFlags_DefaultOpen)) {
        _walkModules(root, 1);
        ImGui::TreePop();
      }
    }

    ImGui::TreePop();
  }
#endif

  // ---- Post-processing
#if defined(HAVE_POST)
  if(ImGui::TreeNodeEx("Post-processing", ImGuiTreeNodeFlags_DefaultOpen)) {
    if(PView::list.empty()) ImGui::TextDisabled("No view loaded");
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      ImGui::PushID((int)i);
      double v = 0.;
      NumberOption(GMSH_GET, "View", (int)i, "Visible", v, false);
      bool visible = (v != 0.);
      if(ImGui::Checkbox("##visible", &visible)) {
        double nv = visible ? 1. : 0.;
        NumberOption(GMSH_SET | GMSH_GUI, "View", (int)i, "Visible", nv, false);
        drawContext::global()->draw();
      }
      ImGui::SameLine();
      char label[256];
      snprintf(label, sizeof(label), "[%d] %s", (int)i,
               PView::list[i]->getData()->getName().c_str());
      if(ImGui::Selectable(label)) {
        // a click opens the colour map of that view, which is a tab of the
        // option window and not a window of its own
        int index = (int)i;
        postAction([index]() { Dialog::showOptionsForView(index, "Map"); });
      }
      // what it carries is described once in src/common/GuiMenus.cpp: the
      // FLTK tree drops the same entries on the little arrow beside the view
      if(ImGui::BeginPopupContextItem("##viewmenu")) {
        static std::vector<Ui::MenuItem> menu;
        menu = Menu::viewActions((int)i);
        menuWalk(menu, this);
        ImGui::EndPopup();
      }
      ImGui::PopID();
    }
    ImGui::TreePop();
  }
#endif

  ImGui::End();
}

#endif
