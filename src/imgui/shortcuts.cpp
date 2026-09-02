// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Application-level keyboard shortcuts, the counterpart of
// FlGui::testGlobalShortcuts() and FlGui::testArrowShortcuts(). Like the menu
// items, the ones that trigger an action queue it with postAction() so that it
// runs outside of the Dear ImGui frame.

#include "uiSources.h"
#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include "imgui.h"

#include "appWindow.h"
#include "sceneView.h"
#include "GuiActions.h"
#include "menuActions.h"
#include "GuiMenus.h"
#include "Gui.h"
#include "GmshMessage.h"

// The key of a shortcut, as Dear ImGui names it.
static ImGuiKey _imguiKey(int key)
{
  if(key >= 'A' && key <= 'Z') return (ImGuiKey)(ImGuiKey_A + (key - 'A'));
  if(key >= '0' && key <= '9') return (ImGuiKey)(ImGuiKey_0 + (key - '0'));
  if(key >= Ui::KeyF1 && key < Ui::KeyF1 + 12)
    return (ImGuiKey)(ImGuiKey_F1 + (key - Ui::KeyF1));
  return ImGuiKey_None;
}

// Run the first entry whose shortcut is being typed, submenus included.
static bool _runMenuShortcut(const std::vector<Ui::MenuItem> &items, bool ctrl,
                             bool shift, bool alt)
{
  for(const auto &it : items) {
    if(_runMenuShortcut(it.children, ctrl, shift, alt)) return true;
    if(it.shortcut.empty() || !it.action) continue;
    if(ctrl != ((it.shortcut.mods & Ui::ModCommand) != 0)) continue;
    if(shift != ((it.shortcut.mods & Ui::ModShift) != 0)) continue;
    if(alt != ((it.shortcut.mods & Ui::ModAlt) != 0)) continue;
    ImGuiKey key = _imguiKey(it.shortcut.key);
    if(key == ImGuiKey_None || !ImGui::IsKeyPressed(key, false)) continue;
    if(it.enabled && !it.enabled()) continue;
    it.action();
    return true;
  }
  return false;
}

void appWindow::_handleShortcuts()
{
  ImGuiIO &io = ImGui::GetIO();
  // A text field is being typed into, or a modal dialog is up. It has to be
  // WantTextInput and not WantCaptureKeyboard: with keyboard navigation on --
  // and it is on -- the latter is true as soon as any panel has the focus,
  // which would leave the shortcuts working only when nothing is focused.
  if(io.WantTextInput || _modalDepth > 0) return;

  const bool ctrl = io.KeyCtrl || io.KeySuper;
  const bool shift = io.KeyShift;

  auto pressed = [](ImGuiKey key) { return ImGui::IsKeyPressed(key, false); };

  // during an interactive selection these keys end, undo, invert or abort it;
  // they are not "used up", exactly as in the FLTK interface
  if(_currentPane && _currentPane->selectionMode) {
    if(pressed(ImGuiKey_E)) _currentPane->endSelection = 1;
    if(pressed(ImGuiKey_U)) _currentPane->undoSelection = 1;
    if(pressed(ImGuiKey_I) || pressed(ImGuiKey_Minus))
      _currentPane->invertSelection = 1;
    if(pressed(ImGuiKey_Q) || pressed(ImGuiKey_Escape))
      _currentPane->quitSelection = 1;
    return;
  }

  // --- the accelerators of the menu bar
  //
  // Dear ImGui draws the menus itself and never acts on the shortcut it
  // displays next to an item, so they have to be tested here. They are read
  // from the same description the menu is built from, which is the point:
  // a label saying "Ctrl+H" and a handler doing something else was a kind of
  // drift nothing could catch as long as the two were written separately.
  {
    static std::vector<Ui::MenuItem> menus;
    static unsigned built = 0;
    if(built != imguiSources().menuGeneration()) {
      built = imguiSources().menuGeneration();
      menus = imguiSources().menuBar();
    }
    if(_runMenuShortcut(menus, ctrl, shift, io.KeyAlt)) return;
  }

  // not in the menu bar, but in the FLTK interface too
  if(ctrl && !shift && pressed(ImGuiKey_T)) {
    postAction([]() { Gui::onelabAction("compute"); });
    return;
  }
  if(ctrl && !shift && pressed(ImGuiKey_0)) {
    postAction(projectReload);
    return;
  }

  if(pressed(ImGuiKey_0)) {
    postAction(geometryReload);
    return;
  }
  if(pressed(ImGuiKey_9)) { // as in the FLTK interface
    postAction(projectReload);
    return;
  }
  if(pressed(ImGuiKey_1) || pressed(ImGuiKey_F1)) {
    postAction([]() { meshDimension(1); });
    return;
  }
  if(pressed(ImGuiKey_2) || pressed(ImGuiKey_F2)) {
    postAction([]() { meshDimension(2); });
    return;
  }
  if(pressed(ImGuiKey_3) || pressed(ImGuiKey_F3)) {
    postAction([]() { meshDimension(3); });
    return;
  }

  // arrows step through the post-processing animation
  if(pressed(ImGuiKey_LeftArrow)) {
    postAction([]() { animationStepBy(false); });
    return;
  }
  if(pressed(ImGuiKey_RightArrow)) {
    postAction([]() { animationStepBy(true); });
    return;
  }
  if(pressed(ImGuiKey_UpArrow)) {
    postAction([]() { animationStepBy(false, true); });
    return;
  }
  if(pressed(ImGuiKey_DownArrow)) {
    postAction([]() { animationStepBy(true, true); });
    return;
  }
  if(pressed(ImGuiKey_Home)) {
    postAction(animationRewind);
    return;
  }

  // toggle the panels
  if(!ctrl && !shift) {
    if(pressed(ImGuiKey_M)) {
      _showConsole = !_showConsole;
      return;
    }
    if(pressed(ImGuiKey_W)) {
      postAction([]() { Gui::watchFile(); });
      return;
    }
  }
}

#endif
