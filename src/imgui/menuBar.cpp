// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// every entry queues an action with appWindow::postAction(), which runs outside
// of the frame

#include "uiSources.h"
#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <functional>
#include <string>
#include <vector>

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_internal.h" // BeginViewportSideBar

#include "appWindow.h"
#include "toolkit.h"
#include "menuActions.h"

void menuWalk(const std::vector<Ui::MenuItem> &items, appWindow *app)
{
  for(const auto &it : items) {
    bool enabled = it.enabled ? it.enabled() : true;

    if(it.kind == Ui::MenuItem::Submenu) {
      if(ImGui::BeginMenu(it.label.c_str(), enabled && !it.children.empty())) {
        menuWalk(it.children, app);
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
        if(what) app->postAction(what);
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
        if(what) app->postAction(what);
      }
    }
    if(it.dividerAfter) ImGui::Separator();
  }
}

void appWindow::_drawMenuBar()
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

  menuWalk(menus, this);

  ImGui::EndMenuBar();
  ImGui::End();
}

// --- the "Window" menu acts on the GLFW window of the application

void appWindow::_windowMinimize() { glfwIconifyWindow(_window); }

void appWindow::_windowZoom()
{
  if(_fullscreen) return;
  if(!_zoomed) {
    glfwMaximizeWindow(_window);
    _zoomed = true;
  }
  else {
    glfwRestoreWindow(_window);
    _zoomed = false;
  }
}

void appWindow::_windowFullScreen()
{
  if(!_fullscreen) {
    glfwGetWindowPos(_window, &_savedX, &_savedY);
    glfwGetWindowSize(_window, &_savedW, &_savedH);
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    if(!monitor) {
      Toolkit::report(Toolkit::Error, "Cannot go full screen: no monitor found");
      return;
    }
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if(!mode) {
      Toolkit::report(Toolkit::Error, "Cannot go full screen: no video mode found");
      return;
    }
    glfwSetWindowMonitor(_window, monitor, 0, 0, mode->width, mode->height,
                         mode->refreshRate);
    _fullscreen = true;
  }
  else {
    if(_savedW <= 0 || _savedH <= 0) {
      _savedX = _savedY = 100;
      _savedW = 800;
      _savedH = 600;
    }
    glfwSetWindowMonitor(_window, nullptr, _savedX, _savedY, _savedW, _savedH,
                         GLFW_DONT_CARE);
    _fullscreen = false;
  }
}


void appWindow::windowAction(const std::string &what)
{
  if(what == "minimize")
    _windowMinimize();
  else if(what == "zoom")
    _windowZoom();
  else if(what == "fullscreen")
    _windowFullScreen();
  else if(what == "show_hide_tree")
    _showModules = !_showModules;
  else
    Toolkit::report(Toolkit::Error, "Unknown window action '%s'", what.c_str());
}

#endif
