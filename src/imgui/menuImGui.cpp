// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The menus are drawn from the description at every frame; an entry runs its
// action with imguiLater(), outside of the frame.

#include "GmshConfig.h"

#include <functional>
#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h" // BeginViewportSideBar

#include "imguiCommon.h"

void imguiMenu(const std::vector<Ui::MenuItem> &items)
{
  for(const auto &it : items) {
    bool enabled = it.enabled ? it.enabled() : true;

    if(it.kind == Ui::MenuItem::Submenu) {
      if(ImGui::BeginMenu(it.label.c_str(), enabled && !it.children.empty())) {
        imguiMenu(it.children);
        ImGui::EndMenu();
      }
    }
    else if(it.kind == Ui::MenuItem::Toggle) {
      // a box before the label, as FLTK draws a toggle: the label makes room
      // for it
      float box = ImGui::GetFontSize() - 2.f;
      float room = box + ImGui::GetStyle().ItemInnerSpacing.x;
      std::string shown = it.label;
      while(ImGui::CalcTextSize(shown.c_str()).x -
              ImGui::CalcTextSize(it.label.c_str()).x <
            room)
        shown = " " + shown;
      std::string shortcut = it.shortcut.label();
      ImVec2 pos = ImGui::GetCursorScreenPos();
      if(ImGui::MenuItem(shown.c_str(),
                         shortcut.empty() ? nullptr : shortcut.c_str(), false,
                         enabled)) {
        std::function<void()> what = it.action;
        if(what) imguiLater(what);
      }
      ImDrawList *draw = ImGui::GetWindowDrawList();
      ImVec2 a(pos.x, (ImGui::GetItemRectMin().y + ImGui::GetItemRectMax().y -
                       box) / 2.f);
      ImVec2 b(a.x + box, a.y + box);
      draw->AddRectFilled(a, b, ImGui::GetColorU32(ImGuiCol_FrameBg));
      draw->AddRect(a, b, ImGui::GetColorU32(ImGuiCol_Border));
      if(it.checked && it.checked()) {
        float pad = ImMax(1.f, IM_TRUNC(box / 6.f));
        ImGui::RenderCheckMark(draw, ImVec2(a.x + pad, a.y + pad),
                               ImGui::GetColorU32(ImGuiCol_CheckMark),
                               box - pad * 2.f);
      }
    }
    else {
      std::string shortcut = it.shortcut.label();
      if(ImGui::MenuItem(it.label.c_str(),
                         shortcut.empty() ? nullptr : shortcut.c_str(), false,
                         enabled)) {
        std::function<void()> what = it.action;
        if(what) imguiLater(what);
      }
    }
    if(it.dividerAfter) ImGui::Separator();
  }
}

void imguiDrawMenuBar()
{
  static std::vector<Ui::MenuItem> menus;
  static unsigned built = 0;
  if(built != imguiSources().menuGeneration()) {
    built = imguiSources().menuGeneration();
    menus = imguiSources().menuBar();
  }

  const ImGuiViewport *viewport = ImGui::GetMainViewport();
  float height = ImGui::GetFrameHeight();
  ImGuiWindowFlags flags = ImGuiWindowFlags_NoDocking |
                           ImGuiWindowFlags_NoScrollbar |
                           ImGuiWindowFlags_NoSavedSettings |
                           ImGuiWindowFlags_MenuBar;
  if(!ImGui::BeginViewportSideBar("##gmshMenuBar", (ImGuiViewport *)viewport,
                                  ImGuiDir_Up, height, flags)) {
    ImGui::End();
    return;
  }
  // without ImGuiWindowFlags_MenuBar this returns false and the bar draws empty
  if(!ImGui::BeginMenuBar()) {
    ImGui::End();
    return;
  }

  imguiMenu(menus);

  ImGui::EndMenuBar();
  ImGui::End();
}
