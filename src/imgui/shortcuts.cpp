// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the keys, read off Sources::keys; the one that is the window's: Escape leaves
// full screen

#include "uiSources.h"
#include "GmshConfig.h"

#include <cctype>
#include "imgui.h"

#include "appWindow.h"

namespace {

  // as Ui::Shortcut says it, 0 for none; Dear ImGui does not say which key went
  // down: each is asked
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
  // WantTextInput, not WantCaptureKeyboard: with keyboard navigation on, the
  // latter is true as soon as any panel has the focus
  if(io.WantTextInput || _modalDepth > 0) return;

  int key = _uiKey();
  unsigned mods = 0;
  if(io.KeyCtrl || io.KeySuper) mods |= Ui::ModCommand;
  if(io.KeyShift) mods |= Ui::ModShift;
  if(io.KeyAlt) mods |= Ui::ModAlt;
  // a digit or a mark is the one typed, whatever key gives it on this
  // keyboard (Shift, on a French one)
  for(ImWchar c : io.InputQueueCharacters)
    if(c > ' ' && c < 127 && !isalpha((int)c)) {
      key = c;
      mods &= ~Ui::ModShift;
    }
  if(!key) return;

  if(key == Ui::KeyEscape && _fullscreen) {
    _windowFullScreen();
    return;
  }

  if(!imguiSources().keys) return;
  // queued with postAction(): it may open a dialog or start a picking
  for(const Ui::KeyBinding &k : imguiSources().keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    if(k.action) postAction(k.action);
    if(k.spent) break;
  }
}
