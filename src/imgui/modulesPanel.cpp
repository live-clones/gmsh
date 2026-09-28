// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the module tree, read from the description

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

#if defined(HAVE_ONELAB)




#endif

// asking for the children of what is open; the modules open and everything
// below closed at first
void appWindow::_walkModules(const std::string &path, int depth)
{
  const Ui::Tree &tree = imguiSources().tree;
  for(const auto &child : tree.children(path)) {
    Ui::Node node = tree.node(child);
    std::string label = node.label.size() ?
                          node.label :
                          child.substr(child.find_last_of('/') + 1);
    if(!tree.children(child).empty()) {
      // a request is spent once the branch has been drawn, so a chain unfolds
      // in one frame
      auto wanted = _treeWanted.find(child);
      if(wanted != _treeWanted.end()) {
        ImGui::SetNextItemOpen(wanted->second);
        _treeWanted.erase(wanted);
      }
      ImGuiTreeNodeFlags flags =
        depth ? ImGuiTreeNodeFlags_None : ImGuiTreeNodeFlags_DefaultOpen;
      bool open = ImGui::TreeNodeEx(label.c_str(), flags);
      _treeOpen[child] = open;
      if(open) {
        _walkModules(child, depth + 1);
        ImGui::TreePop();
      }
      continue;
    }
    ImGui::PushID(child.c_str());
    bool enabled = node.enabled ? node.enabled() : true;
    ImGui::BeginDisabled(!enabled);
    // half the width is the widget, the rest its name
    if(node.hasField) {
      drawField(node.field, ImGui::GetContentRegionAvail().x * .5f);
      // a switch that says nothing itself is followed by the name, which is
      // what one presses
      if(node.label.size()) ImGui::SameLine();
    }
    if(!node.hasField || node.label.size()) {
      if(ImGui::Selectable(label.c_str())) {
        std::function<void()> what = node.pressed;
        if(what) postAction(what);
      }
    }
    if(node.tooltip.size() &&
       ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
      ImGui::SetTooltip("%s", node.tooltip.c_str());
    if(node.menu && ImGui::BeginPopupContextItem("##line")) {
      static std::vector<Ui::MenuItem> menu;
      menu = node.menu();
      menuWalk(menu, this);
      ImGui::EndPopup();
    }
    ImGui::EndDisabled();
    ImGui::PopID();
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

  {
    float footer = ImGui::GetFrameHeightWithSpacing() +
                   ImGui::GetStyle().ItemSpacing.y;
    ImGui::BeginChild("##tree", ImVec2(0.f, -footer));
    for(const auto &root : imguiSources().tree.children("")) {
      if(root == "0Modules") {
        _walkModules(root, 0);
        continue;
      }
      Ui::Node node = imguiSources().tree.node(root);
      std::string label = node.label.size() ?
                            node.label :
                            root.substr(root.find_last_of('/') + 1);
      if(ImGui::TreeNodeEx(label.c_str(), ImGuiTreeNodeFlags_DefaultOpen)) {
        _walkModules(root, 1);
        ImGui::TreePop();
      }
    }
    ImGui::EndChild();
  }

  {
    std::vector<Ui::Button> row = imguiSources().tree.footer ?
                                    imguiSources().tree.footer() :
                                    std::vector<Ui::Button>();
    for(std::size_t i = 0; i < row.size(); i++) {
      if(i) ImGui::SameLine();
      ImGui::PushID((int)i);
      if(row[i].menu) {
        if(ImGui::Button(row[i].label.c_str())) ImGui::OpenPopup("##drop");
        if(ImGui::BeginPopup("##drop")) {
          static std::vector<Ui::MenuItem> menu;
          menu = row[i].menu();
          menuWalk(menu, this);
          ImGui::EndPopup();
        }
      }
      else if(ImGui::Button(row[i].label.c_str())) {
        std::function<void()> what = row[i].action;
        if(what) postAction(what);
      }
      if(row[i].tooltip.size() &&
         ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("%s", row[i].tooltip.c_str());
      ImGui::PopID();
    }
  }

  ImGui::End();
}

#endif
