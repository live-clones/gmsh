// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The menu bar of the Dear ImGui interface. It mirrors, entry for entry, the
// bar_table[] of src/fltk/graphicWindow.cpp: same menus in the same order, same
// labels, same separators and same shortcuts, so that the two interfaces can be
// described by one manual. Anything that is not in the FLTK menu bar does not
// belong here either -- the geometry and mesh commands, for instance, live in
// the modules panel, which is where the FLTK tree puts them.
//
// Every entry does nothing more than queue an action with
// appWindow::postAction(): the action then runs outside of the Dear ImGui
// frame, which is what allows it to open a blocking dialog, ask a question or
// start an interactive selection.

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
#include "GuiMenus.h"
// the one Gmsh header left here: reporting that the window manager refused

// Walk the shared description. An entry is a Dear ImGui menu item of the
// matching kind; the actions it triggers are queued, like every other action
// of the interface, because a Dear ImGui frame is not re-entrant.
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
    else {
      bool checked = (it.kind == Ui::MenuItem::Toggle && it.checked) ? it.checked() :
                                                               false;
      std::string shortcut = it.shortcut.label();
      if(ImGui::MenuItem(it.label.c_str(),
                         shortcut.empty() ? nullptr : shortcut.c_str(),
                         checked, enabled)) {
        std::function<void()> what = it.action;
        if(what) app->postAction(what);
      }
    }
    if(it.dividerAfter) ImGui::Separator();
  }
}

void appWindow::_drawMenuBar()
{
  // rebuilt only when what it shows has changed, not at every frame
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
  // the window must carry ImGuiWindowFlags_MenuBar or this returns false and
  // the bar draws empty, without a word
  if(!ImGui::BeginMenuBar()) {
    ImGui::End();
    return;
  }

  menuWalk(menus, this);

  ImGui::EndMenuBar();
  ImGui::End();
}

// --- the "Window" menu
//
// The FLTK interface iconifies, resizes or raises a set of real windows; here
// there is only one, and the panels live inside it, so each of these acts on
// the GLFW window of the application.

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
    // a window that was never moved has no sensible saved geometry
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
  else
    Toolkit::report(Toolkit::Error, "Unknown window action '%s'", what.c_str());
}

#endif
