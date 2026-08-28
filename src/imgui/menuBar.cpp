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

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <functional>
#include <string>
#include <vector>

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_internal.h" // BeginViewportSideBar

#include "appWindow.h"
#include "menuActions.h"
#include "GuiMenus.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "OS.h"
#include "StringUtils.h"
#include "GModel.h"
#include "drawContext.h"

static void _openOrMerge(bool merge)
{
  appWindow *app = appWindow::instance();
  std::string name;
  if(!app->fileDialog(0, merge ? "Merge file" : "Open file", "", name)) return;
  if(merge)
    MergeFile(name);
  else
    OpenProject(name);
  drawContext::global()->draw();
}

void menuOpen() { _openOrMerge(false); }
void menuMerge() { _openOrMerge(true); }

void menuOpenRecent(int index)
{
  if(index < 0 || index >= (int)CTX::instance()->recentFiles.size()) return;
  std::string name = CTX::instance()->recentFiles[index];
  if(name.empty()) return;
  OpenProject(name);
  drawContext::global()->draw();
}

void menuExport()
{
  appWindow *app = appWindow::instance();
  std::string name = GModel::current()->getFileName();
  if(!app->fileDialog(1, "Export", "", name)) return;
  if(CTX::instance()->confirmOverwrite && !StatFile(name)) {
    std::string q = "File '" + name + "' already exists.\n\nDo you want to "
                    "replace it?";
    if(!Msg::GetAnswer(q.c_str(), 0, "Cancel", "Replace")) return;
  }
  double version = 0.;
  int format = GetFileFormatFromExtension(SplitFileName(name)[2], &version);
  if(format < 0) {
    Msg::Error("Unknown output file format for '%s'", name.c_str());
    return;
  }
  if(version > 0.)
    NumberOption(GMSH_SET, "Mesh", 0, "MshFileVersion", version, false);
  if(!app->exportOptionsDialog(format, name)) return;
  CreateOutputFile(name, format);
}

void menuNew()
{
  appWindow *app = appWindow::instance();
  std::string name;
  if(!app->fileDialog(1, "New geometry file", "*.geo", name)) return;
  std::vector<std::string> split = SplitFileName(name);
  if(split[2] != ".geo") {
    std::string q = "File '" + name + "' does not have the '.geo' extension.\n\n"
                    "Do you want to continue as-is?";
    if(Msg::GetAnswer(q.c_str(), 0, "Continue as-is", "Use '.geo' extension"))
      name = split[0] + split[1] + ".geo";
  }
  if(!StatFile(name)) {
    std::string q = "File '" + name + "' already exists.\n\nDo you want to "
                    "delete it?";
    if(Msg::GetAnswer(q.c_str(), 0, "Cancel", "Delete"))
      UnlinkFile(name);
    else
      return;
  }
  FILE *fp = Fopen(name.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return;
  }
  int factory = Msg::GetAnswer("Which geometry kernel do you want to use?", 0,
                               "Built-in", "OpenCASCADE");
  time_t now;
  time(&now);
  fprintf(fp, "// Gmsh project created on %s", ctime(&now));
  if(factory) fprintf(fp, "SetFactory(\"OpenCASCADE\");\n");
  fclose(fp);
  OpenProject(name);
  drawContext::global()->draw();
}

void menuRename()
{
  appWindow *app = appWindow::instance();
  std::string name = GModel::current()->getFileName();
  if(!app->fileDialog(1, "Rename model file", "", name)) return;
  if(CTX::instance()->confirmOverwrite && !StatFile(name)) {
    std::string q = "File '" + name + "' already exists.\n\nDo you want to "
                    "replace it?";
    if(!Msg::GetAnswer(q.c_str(), 0, "Cancel", "Replace")) return;
  }
  rename(GModel::current()->getFileName().c_str(), name.c_str());
  GModel::current()->setFileName(name);
  GModel::current()->setName(SplitFileName(name)[1]);
  Msg::SetOnelabChanged(3);
  drawContext::global()->draw();
}

void menuWatchPattern()
{
  std::string pattern = CTX::instance()->watchFilePattern;
  if(pattern.empty()) pattern = "output/*.msh";
  if(!Gui::inputDialog("Pattern of the files to watch:", pattern)) return;
  CTX::instance()->watchFilePattern = pattern;
  watchFiles();
}

#if defined(HAVE_ONELAB)

void menuRemote(const std::string &what)
{
  std::string arg;
  if(what == "start") {
    arg = "./gmsh ../tutorials/view3.pos";
    if(!Gui::inputDialog("Command to run the remote Gmsh:", arg)) return;
  }
  else if(what == "merge") {
    arg = "/tmp/data.pos";
    if(!Gui::inputDialog("File the remote Gmsh should merge:", arg)) return;
  }
  remoteAction(what, arg);
}

#endif

namespace {

  // Walk the shared description. An entry is a Dear ImGui menu item of the
  // matching kind; the actions it triggers are queued, like every other action
  // of the interface, because a Dear ImGui frame is not re-entrant.
} // namespace

void menuWalk(const std::vector<Menu::Item> &items, appWindow *app)
{
  for(const auto &it : items) {
    bool enabled = it.enabled ? it.enabled() : true;

    if(it.kind == Menu::Submenu) {
      if(ImGui::BeginMenu(it.label.c_str(), enabled && !it.children.empty())) {
        menuWalk(it.children, app);
        ImGui::EndMenu();
      }
    }
    else {
      bool checked = (it.kind == Menu::Toggle && it.checked) ? it.checked() :
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
  static std::vector<Menu::Item> menus;
  static unsigned built = 0;
  if(built != Menu::generation()) {
    built = Menu::generation();
    menus = Menu::bar();
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
      Msg::Error("Cannot go full screen: no monitor found");
      return;
    }
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if(!mode) {
      Msg::Error("Cannot go full screen: no video mode found");
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

// --- the panels the menus show and hide

bool appWindow::panelVisible(int panel) const
{
  switch(panel) {
  case Gui::PanelOptions: return _showDialog[Dialog::Options];
  case Gui::PanelPlugins: return dialogVisible(Dialog::Plugins);
  case Gui::PanelVisibility: return dialogVisible(Dialog::Visibility);
  case Gui::PanelMessageConsole: return _showConsole;
  // the three windows of the Help menu are described like the other dialogs
  case Gui::PanelKeyboardAndMouse: return dialogVisible(Dialog::Shortcuts);
  case Gui::PanelCurrentOptions: return dialogVisible(Dialog::CurrentOptions);
  case Gui::PanelAbout: return dialogVisible(Dialog::About);
  case Gui::PanelFields: return dialogVisible(Dialog::Fields);
  case Gui::PanelClassify: return dialogVisible(Dialog::Classify);
  default: return false;
  }
}

void appWindow::showPanel(int panel, bool show)
{
  switch(panel) {
  case Gui::PanelOptions: _showDialog[Dialog::Options] = show; break;
  case Gui::PanelPlugins:
    // described like the other dialogs now
    if(show)
      Dialog::show(Dialog::Plugins, -1);
    else
      hideDialog(Dialog::Plugins);
    break;
  case Gui::PanelVisibility:
    // described like the other dialogs now
    if(show)
      Dialog::show(Dialog::Visibility, -1);
    else
      hideDialog(Dialog::Visibility);
    break;
  case Gui::PanelMessageConsole: _showConsole = show; break;
  case Gui::PanelKeyboardAndMouse:
  case Gui::PanelCurrentOptions:
  case Gui::PanelAbout: {
    int dialog = (panel == Gui::PanelKeyboardAndMouse) ? Dialog::Shortcuts :
                 (panel == Gui::PanelCurrentOptions)   ? Dialog::CurrentOptions :
                                                         Dialog::About;
    if(show)
      Dialog::show(dialog, -1);
    else
      hideDialog(dialog);
  } break;
  case Gui::PanelFields:
    // described like the other dialogs now
    if(show)
      Dialog::show(Dialog::Fields, -1);
    else
      hideDialog(Dialog::Fields);
    break;
  case Gui::PanelClassify:
    // described like the other dialogs now
    if(show)
      Dialog::startClassify();
    else
      hideDialog(Dialog::Classify);
    break;
  default: break;
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
    Msg::Error("Unknown window action '%s'", what.c_str());
}

#endif
