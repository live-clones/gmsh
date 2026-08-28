// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h" // BeginViewportSideBar()

#include "appWindow.h"
#include "scenePane.h"
#include "Gui.h"
#include "GuiDialogs.h"
#include "GuiActions.h"
#include "GuiMenus.h"
#include "menuActions.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "OS.h"
#include "drawContext.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

// The bar along the bottom of the window: the same handful of controls the FLTK
// interface puts there -- the current model, a menu of the options one reaches
// for most often, the view orientation, the animation -- and, taking whatever
// width is left, the last message and the progress of what is running.

namespace {

  bool _number(const char *category, int num, const char *name, double &val)
  {
    return NumberOption(GMSH_GET, category, num, name, val, false);
  }

  void _setNumber(const char *category, int num, const char *name, double val)
  {
    NumberOption(GMSH_SET | GMSH_GUI, category, num, name, val, false);
  }

  // a small square button, the size of the bar
  bool _button(const char *label, const char *tip)
  {
    bool clicked = ImGui::Button(label);
    if(tip && ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
      ImGui::SetTooltip("%s", tip);
    return clicked;
  }

} // namespace

void appWindow::_drawQuickAccessMenu()
{
  // described once in src/common/GuiMenus.cpp, as the menu bar is: the FLTK
  // interface pops the same entries up on the same button
  // It says what the options are worth, and which entries are worth showing at
  // all, so it is built afresh every frame it is open rather than kept: the
  // FLTK popup is built afresh every time it opens, for the same reason.
  static std::vector<Menu::Item> menu;
  menu = Menu::quickAccess();
  menuWalk(menu, this);
}

void appWindow::_drawStatusBar()
{
  const ImGuiViewport *viewport = ImGui::GetMainViewport();
  float height = ImGui::GetFrameHeightWithSpacing();
  // MenuBar is what BeginMenuBar() below needs; without it the whole bar draws
  // empty, since BeginMenuBar() then simply returns false
  ImGuiWindowFlags flags =
    ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;

  if(ImGui::BeginViewportSideBar("##gmshStatusBar", (ImGuiViewport *)viewport,
                                 ImGuiDir_Down, height, flags)) {
    if(ImGui::BeginMenuBar()) {
      // --- current model
      if(ImGui::BeginMenu("M")) {
        for(std::size_t i = 0; i < GModel::list.size(); i++) {
          std::string label = "Model " + std::to_string(i);
          if(GModel::list[i]->getName().size())
            label += " - " + GModel::list[i]->getName();
          bool current = (GModel::list[i] == GModel::current());
          if(ImGui::MenuItem(label.c_str(), nullptr, current) && !current) {
            std::size_t index = i;
            postAction([index]() {
              if(index < GModel::list.size()) {
                GModel::current(index);
                Gui::resetVisibility();
                Gui::updateViews(true, true);
                Gui::rebuildTree(true);
                drawContext::global()->draw();
              }
            });
          }
        }
        ImGui::EndMenu();
      }
      if(ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("Set the current (active) model");

      // --- quick access
      if(ImGui::BeginMenu("O")) {
        _drawQuickAccessMenu();
        ImGui::EndMenu();
      }
      if(ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("Open the quick access menu");

      ImGui::Separator();

      // --- view orientation; Shift gives the opposite direction, as in FLTK
      struct { const char *label, *what, *tip; } orient[] = {
        {"X", "x", "Set the +X or, with Shift, the -X view"},
        {"Y", "y", "Set the +Y or, with Shift, the -Y view"},
        {"Z", "z", "Set the +Z or, with Shift, the -Z view"},
        {"R", "r", "Turn a quarter turn, the other way with Shift"},
        {"1:1", "1:1", "Reset the zoom, and with Shift the bounding box too"},
      };
      for(auto &o : orient) {
        if(_button(o.label, o.tip)) {
          std::string what = o.what;
          bool reverse = ImGui::GetIO().KeyShift;
          postAction([this, what, reverse]() {
            if(scenePane *p = currentPane())
              viewSetOrientation(p->getDrawContext(), what, reverse);
            drawContext::global()->draw();
          });
        }
      }

      // --- mouse selection
      {
        bool on = CTX::instance()->mouseSelection ? true : false;
        if(on) ImGui::PushStyleColor(ImGuiCol_Button,
                                     ImGui::GetStyleColorVec4(ImGuiCol_ButtonActive));
        if(_button("S", "Toggle mouse selection on and off (Escape)"))
          _setNumber("General", 0, "MouseSelection", on ? 0. : 1.);
        if(on) ImGui::PopStyleColor();
      }

      ImGui::Separator();

      // --- animation
      bool animatable = viewIsAnimatable();
      ImGui::BeginDisabled(!animatable);
      if(_button("|<", "Rewind the animation"))
        postAction([]() { animationRewind(); });
      if(_button("<", "Step backward (Left arrow)"))
        postAction([]() {
          animationStep(!CTX::instance()->post.animCycle,
                        -CTX::instance()->post.animStep);
        });
      if(_button(_animating ? "||" : ">", "Play or pause the animation"))
        _animating = !_animating;
      if(_button(">|", "Step forward (Right arrow)"))
        postAction([]() {
          animationStep(!CTX::instance()->post.animCycle,
                        CTX::instance()->post.animStep);
        });
      ImGui::EndDisabled();
      if(!animatable) _animating = false;

      ImGui::Separator();

      // --- last message, then the progress of whatever is running.
      // Clicking the message shows or hides the console, as the FLTK bar does;
      // the target is the whole strip left of the progress bar, not just the
      // text, so that it can be hit when the message is short or empty.
      ImVec2 textPos = ImGui::GetCursorScreenPos();
      float avail = ImGui::GetContentRegionAvail().x;
      if(_progressMax > _progressMin) avail -= 200.f * _styleScale;
      if(avail < 1.f) avail = 1.f;
      if(ImGui::InvisibleButton("##statusMessage",
                                ImVec2(avail, ImGui::GetFrameHeight())))
        _showConsole = !_showConsole;
      if(ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("Show or hide the message console");
      ImGui::SetCursorScreenPos(textPos);

      if(_statusColor == Gui::StatusColorError)
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.90f, 0.30f, 0.30f, 1.f));
      else if(_statusColor == Gui::StatusColorWarning)
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.95f, 0.75f, 0.25f, 1.f));
      else
        ImGui::PushStyleColor(ImGuiCol_Text,
                              ImGui::GetStyleColorVec4(ImGuiCol_Text));
      ImGui::AlignTextToFramePadding();
      ImGui::TextUnformatted(_status.c_str());
      ImGui::PopStyleColor();

      if(_progressMax > _progressMin) {
        float frac = (float)((_progressValue - _progressMin) /
                             (_progressMax - _progressMin));
        float w = 200.f * _styleScale;
        ImGui::SameLine(ImGui::GetWindowWidth() - w - ImGui::GetStyle().ItemSpacing.x);
        ImGui::ProgressBar(frac, ImVec2(w, 0.f), _progressMsg.c_str());
      }
      ImGui::EndMenuBar();
    }
  }
  ImGui::End();
}

// Stepping the animation from the frame loop rather than from a blocking loop
// as the FLTK interface does: an immediate-mode frame is not re-entrant, and
// there is a frame going by anyway.
void appWindow::_stepAnimation()
{
  if(!_animating) return;
  double now = TimeOfDay();
  if(now - _animLastStep < CTX::instance()->post.animDelay) return;
  _animLastStep = now;
  animationStep(!CTX::instance()->post.animCycle,
                CTX::instance()->post.animStep);
}

#endif
