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

#include "appWindow.h"
#include "Gui.h"
#include "GuiDialogs.h"
#include "GuiActions.h"
#include "GuiMenus.h"
#include "menuActions.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "OpenFile.h"
#include "drawContext.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#include "onelabUtils.h"
#endif

#include "onelabWidgets.h"
#include "GuiOnelab.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

namespace {

#if defined(HAVE_ONELAB)

  // ONELAB names are paths: "Solver/Group/Parameter". Split off the leading
  // path so that the parameters can be nested under collapsing headers.
  void _splitPath(const std::string &name, std::string &path,
                  std::string &leaf)
  {
    std::size_t sep = name.find_last_of('/');
    if(sep == std::string::npos) {
      path.clear();
      leaf = name;
    }
    else {
      path = name.substr(0, sep);
      leaf = name.substr(sep + 1);
    }
  }

  // ONELAB sorts its parameters by prefixing them with digits, which are not
  // meant to be shown
  std::string _strip(const std::string &s)
  {
    std::size_t i = 0;
    while(i < s.size() && isdigit((unsigned char)s[i])) i++;
    return (i < s.size()) ? s.substr(i) : s;
  }

#endif

} // namespace

#if defined(HAVE_ONELAB)

bool drawOnelabNumber(onelab::number &p)
{
  double v = p.getValue();
  std::string label = onelabLabel(p);

    bool changed = false;
    ImGui::PushID(p.getName().c_str());
    ImGui::BeginDisabled(p.getReadOnly());

    const std::vector<double> &choices = p.getChoices();
    if(p.getChoices().size() && p.getValueLabels().size()) {
      // an enumeration with named values
      std::string preview;
      for(auto &vl : p.getValueLabels())
        if(vl.first == v) preview = vl.second;
      ImGui::SetNextItemWidth(180.f);
      if(ImGui::BeginCombo(label.c_str(), preview.c_str())) {
        for(auto &vl : p.getValueLabels())
          if(ImGui::Selectable(vl.second.c_str(), vl.first == v)) {
            p.setValue(vl.first);
            changed = true;
          }
        ImGui::EndCombo();
      }
    }
    else if(choices.size() == 2 && choices[0] == 0. && choices[1] == 1.) {
      bool b = (v != 0.);
      if(ImGui::Checkbox(label.c_str(), &b)) {
        p.setValue(b ? 1. : 0.);
        changed = true;
      }
    }
    else if(p.getMin() != -onelab::parameter::maxNumber() &&
            p.getMax() != onelab::parameter::maxNumber() &&
            p.getMax() > p.getMin()) {
      double lo = p.getMin(), hi = p.getMax();
      ImGui::SetNextItemWidth(180.f);
      if(ImGui::SliderScalar(label.c_str(), ImGuiDataType_Double, &v, &lo, &hi,
                             "%.6g")) {
        p.setValue(v);
        changed = true;
      }
    }
    else {
      ImGui::SetNextItemWidth(180.f);
      if(ImGui::InputDouble(label.c_str(), &v, 0., 0., "%.6g",
                            ImGuiInputTextFlags_EnterReturnsTrue)) {
        p.setValue(v);
        changed = true;
      }
    }

    ImGui::EndDisabled();
    if(p.getHelp().size() && ImGui::BeginItemTooltip()) {
      ImGui::TextUnformatted(p.getHelp().c_str());
      ImGui::EndTooltip();
    }
    ImGui::PopID();
    return changed;
  }

bool drawOnelabString(onelab::string &p,
                      std::map<std::string, std::string> &edits)
{
  std::string label = onelabLabel(p);
  std::string current = p.getValue();
    auto it = edits.find(p.getName());
    if(it == edits.end())
      it = edits.insert(std::make_pair(p.getName(), current)).first;

    bool changed = false;
    ImGui::PushID(p.getName().c_str());
    ImGui::BeginDisabled(p.getReadOnly());

    if(p.getChoices().size()) {
      ImGui::SetNextItemWidth(220.f);
      if(ImGui::BeginCombo(label.c_str(), current.c_str())) {
        for(auto &c : p.getChoices())
          if(ImGui::Selectable(c.c_str(), c == current)) {
            p.setValue(c);
            changed = true;
          }
        ImGui::EndCombo();
      }
    }
    else {
      ImGui::SetNextItemWidth(220.f);
      ImGui::InputText(label.c_str(), &it->second);
      if(ImGui::IsItemDeactivatedAfterEdit()) {
        p.setValue(it->second);
        changed = true;
      }
      else if(!ImGui::IsItemActive() && it->second != current) {
        it->second = current;
      }
    }

    ImGui::EndDisabled();
    if(p.getHelp().size() && ImGui::BeginItemTooltip()) {
      ImGui::TextUnformatted(p.getHelp().c_str());
      ImGui::EndTooltip();
    }
  ImGui::PopID();
  return changed;
}

std::string onelabLabel(const onelab::parameter &p)
{
  std::string label = p.getLabel().size() ? p.getLabel() : _strip(p.getName());
  std::size_t sep = label.find_last_of('/');
  if(sep != std::string::npos) label = label.substr(sep + 1);
  return label;
}

#endif

// Walk the shared description. The modules are open and everything below them
// closed, as the FLTK tree leaves it after its first build.
void appWindow::_walkModules(const std::vector<Menu::Item> &items, int depth,
                             const std::string &path)
{
  for(const auto &it : items) {
    if(it.kind == Menu::Submenu) {
      std::string here = path + "/" + it.label;
      // what the API asked for, if this is one of the branches it named; the
      // request is only spent once the branch has been drawn, so a chain of
      // them unfolds in a single frame
      auto wanted = _treeWanted.find(here);
      if(wanted != _treeWanted.end()) {
        ImGui::SetNextItemOpen(wanted->second);
        _treeWanted.erase(wanted);
      }
      ImGuiTreeNodeFlags flags =
        depth ? ImGuiTreeNodeFlags_None : ImGuiTreeNodeFlags_DefaultOpen;
      if(ImGui::TreeNodeEx(it.label.c_str(), flags)) {
        _walkModules(it.children, depth + 1, here);
        ImGui::TreePop();
      }
      continue;
    }
    bool enabled = it.enabled ? it.enabled() : true;
    ImGui::BeginDisabled(!enabled);
    if(ImGui::Selectable(it.label.c_str())) {
      std::function<void()> what = it.action;
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

  // The Geometry and Mesh branches come from the shared description of
  // src/common/GuiMenus.h, which the FLTK tree is built from too. What follows
  // -- the parameters of the solvers and the views -- is widgets rather than
  // entries, so each interface builds that part itself.
  {
    static std::vector<Menu::Item> tree;
    static unsigned built = 0;
    if(built != Menu::generation()) {
      built = Menu::generation();
      tree = Menu::modules();
    }
    _walkModules(tree, 0, "0Modules");
  }

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

    if(ImGui::SmallButton("Save database")) postAction([]() { onelabRun("save"); });
    ImGui::SameLine();
    if(ImGui::SmallButton("Load database")) postAction([]() { onelabRun("load"); });

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
        static std::vector<Menu::Item> menu;
        menu = Menu::solverActions(i);
        menuWalk(menu, this);
        ImGui::EndPopup();
      }
      ImGui::PopID();
    }

    // the parameters of the clients, grouped by their path
    static std::map<std::string, std::string> edits;
    std::vector<onelab::number> numbers;
    std::vector<onelab::string> strings;
    onelab::server::instance()->get(numbers);
    onelab::server::instance()->get(strings);

    std::map<std::string, std::vector<int> > numbersByPath, stringsByPath;
    for(std::size_t i = 0; i < numbers.size(); i++) {
      if(!numbers[i].getVisible()) continue;
      std::string path, leaf;
      _splitPath(numbers[i].getName(), path, leaf);
      numbersByPath[path].push_back((int)i);
    }
    for(std::size_t i = 0; i < strings.size(); i++) {
      if(!strings[i].getVisible()) continue;
      std::string path, leaf;
      _splitPath(strings[i].getName(), path, leaf);
      stringsByPath[path].push_back((int)i);
    }

    std::vector<std::string> paths;
    for(auto &kv : numbersByPath) paths.push_back(kv.first);
    for(auto &kv : stringsByPath)
      if(!numbersByPath.count(kv.first)) paths.push_back(kv.first);
    std::sort(paths.begin(), paths.end());

    for(auto &path : paths) {
      std::string label = _strip(path);
      if(label.empty()) label = "Parameters";
      if(!ImGui::TreeNodeEx(label.c_str(), ImGuiTreeNodeFlags_DefaultOpen))
        continue;
      for(int i : numbersByPath[path]) {
        onelab::number before = numbers[i];
        // what a parameter does when it changes -- the Gmsh option it may
        // stand for, the server actions its attributes ask for, and the check
        // the solver wants -- is shared with the FLTK tree and with the
        // per-entity window, see src/common/GuiOnelab.h
        if(drawOnelabNumber(numbers[i])) GuiOnelab::changed(before, numbers[i]);
      }
      for(int i : stringsByPath[path]) {
        onelab::string before = strings[i];
        if(drawOnelabString(strings[i], edits)) GuiOnelab::changed(before,
                                                                  strings[i]);
      }
      ImGui::TreePop();
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
        static std::vector<Menu::Item> menu;
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
