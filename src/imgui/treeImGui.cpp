// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The tree of the modules, read from its description at every frame, in a
// panel of its own: a branch asks for its children when it is open, a line
// with a field carries its widget, a line without one is pressed.

#include "GmshConfig.h"

#include <functional>
#include <map>
#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_stdlib.h"

#include "imguiCommon.h"
#include "Glyph.h"
#include "Tree.h"

namespace {

  bool _shown = true;
  // by path, "0Modules/Geometry/..."; a request waits until the branch is
  // drawn, so that a chain unfolds in one go
  std::map<std::string, bool> _treeWanted;
  // what each branch was the last time it was drawn
  std::map<std::string, bool> _treeOpen;

  // asking for the children of what is open; the modules open and everything
  // below closed at first
  void _walk(const std::string &path, int depth)
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
          _walk(child, depth + 1);
          ImGui::TreePop();
        }
        continue;
      }
      ImGui::PushID(child.c_str());
      bool enabled = node.enabled ? node.enabled() : true;
      ImGui::BeginDisabled(!enabled);
      // half the width is the widget, the rest its name
      if(node.hasField) {
        imguiField(node.field, ImGui::GetContentRegionAvail().x * .5f);
        // a switch that says nothing itself is followed by the name, which is
        // what one presses
        if(node.label.size()) ImGui::SameLine();
      }
      if(!node.hasField || node.label.size()) {
        if(ImGui::Selectable(label.c_str())) {
          std::function<void()> what = node.pressed;
          if(what) imguiLater(what);
        }
      }
      if(node.tooltip.size() &&
         ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("%s", node.tooltip.c_str());
      if(node.menu && ImGui::BeginPopupContextItem("##line")) {
        static std::vector<Ui::MenuItem> menu;
        menu = node.menu();
        imguiMenu(menu);
        ImGui::EndPopup();
      }
      ImGui::EndDisabled();
      ImGui::PopID();
    }
  }


} // namespace

void imguiDrawTree()
{
  if(!_shown) return;

  ImGui::SetNextWindowSize(ImVec2(300, 500), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("Modules", &_shown)) {
    ImGui::End();
    return;
  }

  {
    float footer = ImGui::GetFrameHeightWithSpacing() +
                   ImGui::GetStyle().ItemSpacing.y;
    ImGui::BeginChild("##tree", ImVec2(0.f, -footer));
    for(const auto &root : imguiSources().tree.children("")) {
      if(root == "0Modules") {
        _walk(root, 0);
        continue;
      }
      Ui::Node node = imguiSources().tree.node(root);
      std::string label = node.label.size() ?
                            node.label :
                            root.substr(root.find_last_of('/') + 1);
      if(ImGui::TreeNodeEx(label.c_str(), ImGuiTreeNodeFlags_DefaultOpen)) {
        _walk(root, 1);
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
      // the picture when there is one, the label otherwise
      bool pictured = Ui::glyph(row[i].glyph) != nullptr;
      float side = ImGui::GetFrameHeight();
      auto pressed = [&]() {
        bool p = pictured ? ImGui::Button("##g", ImVec2(1.5f * side, side)) :
                            ImGui::Button(row[i].label.c_str());
        if(pictured)
          imguiGlyph(row[i].glyph, ImGui::GetItemRectMin(),
                     ImGui::GetItemRectMax(), ImGui::GetColorU32(ImGuiCol_Text));
        return p;
      };
      if(row[i].menu) {
        if(pressed()) ImGui::OpenPopup("##drop");
        if(ImGui::BeginPopup("##drop")) {
          static std::vector<Ui::MenuItem> menu;
          menu = row[i].menu();
          imguiMenu(menu);
          ImGui::EndPopup();
        }
      }
      else if(pressed()) {
        std::function<void()> what = row[i].action;
        if(what) imguiLater(what);
      }
      if(row[i].tooltip.size() &&
         ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("%s", row[i].tooltip.c_str());
      ImGui::PopID();
    }
  }

  ImGui::End();
}

void imguiShowTree(bool show) { _shown = show; }

bool imguiTreeShown() { return _shown; }

void imguiOpenTreeItem(const std::string &path, bool open)
{
  _treeWanted[path] = open;
}

bool imguiTreeItemOpen(const std::string &path)
{
  auto wanted = _treeWanted.find(path);
  if(wanted != _treeWanted.end()) return wanted->second;
  auto open = _treeOpen.find(path);
  return open != _treeOpen.end() && open->second;
}
