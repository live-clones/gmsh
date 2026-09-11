// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The keys, wherever the pointer is.
//
// They are read off the one list the interfaces share, Sources::keys -- the
// shortcuts of the menus and after them the keys of the 3D view -- so that
// what a key does is said once. This file used to be a second copy of the
// FLTK list, written by hand, and the two had drifted: 'm' folded the mesh
// module in one and hid the console in the other. What is left here is Dear
// ImGui's way of saying which key was struck, and the one thing that is this
// window's rather than the application's: Escape leaves full screen.

#include "uiSources.h"
#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include "imgui.h"

#include "appWindow.h"

namespace {

  // The key that was struck this frame, said as Ui::Shortcut says it: an
  // upper case letter, a digit or a punctuation mark, or one of the named
  // keys. 0 when none was, or none a shortcut could name. Dear ImGui does not
  // say which key went down; each one is asked.
  int _uiKey()
  {
    for(int k = ImGuiKey_NamedKey_BEGIN; k < ImGuiKey_NamedKey_END; k++) {
      ImGuiKey key = (ImGuiKey)k;
      if(!ImGui::IsKeyPressed(key, false)) continue;
      if(key >= ImGuiKey_A && key <= ImGuiKey_Z) return 'A' + (key - ImGuiKey_A);
      if(key >= ImGuiKey_0 && key <= ImGuiKey_9) return '0' + (key - ImGuiKey_0);
      if(key >= ImGuiKey_Keypad0 && key <= ImGuiKey_Keypad9)
        return '0' + (key - ImGuiKey_Keypad0);
      if(key >= ImGuiKey_F1 && key <= ImGuiKey_F12)
        return Ui::KeyF1 + (key - ImGuiKey_F1);
      switch(key) {
      case ImGuiKey_LeftArrow: return Ui::KeyLeft;
      case ImGuiKey_RightArrow: return Ui::KeyRight;
      case ImGuiKey_UpArrow: return Ui::KeyUp;
      case ImGuiKey_DownArrow: return Ui::KeyDown;
      case ImGuiKey_Escape: return Ui::KeyEscape;
      case ImGuiKey_Home: return Ui::KeyHome;
      case ImGuiKey_PageUp: return Ui::KeyPageUp;
      case ImGuiKey_PageDown: return Ui::KeyPageDown;
      case ImGuiKey_Delete: return Ui::KeyDelete;
      case ImGuiKey_Minus:
      case ImGuiKey_KeypadSubtract: return '-';
      default: break;
      }
    }
    return 0;
  }

} // namespace

void appWindow::_handleShortcuts()
{
  ImGuiIO &io = ImGui::GetIO();
  // A text field is being typed into, or a modal dialog is up. It has to be
  // WantTextInput and not WantCaptureKeyboard: with keyboard navigation on --
  // and it is on -- the latter is true as soon as any panel has the focus,
  // which would leave the shortcuts working only when nothing is focused.
  if(io.WantTextInput || _modalDepth > 0) return;

  int key = _uiKey();
  if(!key) return;

  if(key == Ui::KeyEscape && _fullscreen) {
    _windowFullScreen();
    return;
  }

  unsigned mods = 0;
  if(io.KeyCtrl || io.KeySuper) mods |= Ui::ModCommand;
  if(io.KeyShift) mods |= Ui::ModShift;
  if(io.KeyAlt) mods |= Ui::ModAlt;

  if(!imguiSources().keys) return;
  // Like the menu entries, what a key runs is queued with postAction() so
  // that it runs outside of the frame: it is free to open a blocking dialog
  // or start a picking, both of which pump frames of their own.
  for(const Ui::KeyBinding &k : imguiSources().keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    if(k.action) postAction(k.action);
    if(k.spent) break;
  }
}

#endif
