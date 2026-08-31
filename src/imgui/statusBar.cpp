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
#include "GuiStatus.h"
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

} // namespace

void appWindow::_drawQuickAccessMenu()
{
  // described once in src/common/GuiMenus.cpp, as the menu bar is: the FLTK
  // interface pops the same entries up on the same button
  // It says what the options are worth, and which entries are worth showing at
  // all, so it is built afresh every frame it is open rather than kept: the
  // FLTK popup is built afresh every time it opens, for the same reason.
  static std::vector<Ui::MenuItem> menu;
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
      // The buttons, as src/common/GuiStatus.h describes them. They used
      // to be written out here and again in src/fltk/graphicWindow.cpp, with
      // different labels, different tooltips, and the button that says
      // whether the mouse picks meaning the opposite thing.
      static std::vector<Ui::BarButton> bar;
      bar = StatusBar::bar();
      for(std::size_t i = 0; i < bar.size(); i++) {
        const Ui::BarButton &b = bar[i];
        if(b.gapBefore) ImGui::Separator();
        bool enabled = b.enabled ? b.enabled() : true;
        ImGui::BeginDisabled(!enabled);
        bool on = b.on && b.on();
        std::string label = (on && b.labelOn.size()) ? b.labelOn : b.label;
        int painted = 0;
        // it is worth looking at: red, as the bar this reproduces paints the
        // one that says the mouse does not pick
        if(b.alert && b.alert()) {
          ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(.62f, .13f, .13f, 1.f));
          ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(.98f, .94f, .94f, 1.f));
          painted = 2;
        }
        ImGui::PushID((int)i);
        if(b.menu) {
          if(ImGui::BeginMenu(label.c_str(), enabled)) {
            static std::vector<Ui::MenuItem> menu;
            menu = b.menu();
            menuWalk(menu, this);
            ImGui::EndMenu();
          }
        }
        else if(ImGui::Button(label.c_str())) {
          std::function<void(bool, bool)> what = b.action;
          bool reverse = ImGui::GetIO().KeyShift;
          bool sync = ImGui::GetIO().KeyCtrl;
          if(what) postAction([what, reverse, sync]() { what(reverse, sync); });
        }
        ImGui::PopID();
        if(painted) ImGui::PopStyleColor(painted);
        ImGui::EndDisabled();
        if(b.tooltip.size() &&
           ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal |
                                ImGuiHoveredFlags_AllowWhenDisabled))
          ImGui::SetTooltip("%s", b.tooltip.c_str());
      }

      ImGui::Separator();

      // --- What is left of the bar: the message and the progress, both
      // read from src/common/GuiStatus.h. Clicking shows or hides the console,
      // as the FLTK bar does; the target is the whole strip left of the
      // progress, not just the text, so that it can be hit when the message is
      // short or empty.
      Ui::BarMessage m = StatusBar::message();
      ImVec2 textPos = ImGui::GetCursorScreenPos();
      float avail = ImGui::GetContentRegionAvail().x;
      if(m.running) avail -= 200.f * _styleScale;
      if(avail < 1.f) avail = 1.f;
      if(ImGui::InvisibleButton("##statusMessage",
                                ImVec2(avail, ImGui::GetFrameHeight())))
        postAction(StatusBar::messagePressed);
      if(ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNormal))
        ImGui::SetTooltip("%s", StatusBar::messageTooltip().c_str());
      ImGui::SetCursorScreenPos(textPos);

      if(m.colour == Gui::StatusColorError)
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.90f, 0.30f, 0.30f, 1.f));
      else if(m.colour == Gui::StatusColorWarning)
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.95f, 0.75f, 0.25f, 1.f));
      else
        ImGui::PushStyleColor(ImGuiCol_Text,
                              ImGui::GetStyleColorVec4(ImGuiCol_Text));
      ImGui::AlignTextToFramePadding();
      ImGui::TextUnformatted(m.text.c_str());
      ImGui::PopStyleColor();

      if(m.running) {
        float w = 200.f * _styleScale;
        ImGui::SameLine(ImGui::GetWindowWidth() - w -
                        ImGui::GetStyle().ItemSpacing.x);
        ImGui::ProgressBar((float)m.fraction, ImVec2(w, 0.f),
                           m.progressText.c_str());
      }
      ImGui::EndMenuBar();
    }
  }
  ImGui::End();
}

// The views the status bar acts upon are the panes of the graphic window, which
// is what makes this the interface's rather than the description's.
void appWindow::orientPanes(const std::string &what, bool reverse, bool sync)
{
  std::vector<scenePane *> panes;
  for(auto *p : _panes)
    if(_isTiled(p)) panes.push_back(p);
  if(panes.empty()) {
    if(scenePane *p = currentPane()) panes.push_back(p);
  }
  for(std::size_t i = 0; i < panes.size(); i++) {
    drawContext *ctx = panes[i]->getDrawContext();
    if(!ctx) continue;
    // Control makes the others follow the first instead of being oriented
    // themselves, as the bar this reproduces has it
    if(sync && (what == "r" || what == "1:1")) {
      if(i == 0) continue;
      drawContext *first = panes[0]->getDrawContext();
      if(!first) continue;
      if(what == "r")
        ctx->setQuaternion(first->quaternion[0], first->quaternion[1],
                           first->quaternion[2], first->quaternion[3]);
      else if(!CTX::instance()->camera) {
        for(int j = 0; j < 3; j++) {
          ctx->t[j] = first->t[j];
          ctx->s[j] = first->s[j];
        }
      }
      continue;
    }
    viewSetOrientation(ctx, what, reverse);
  }
  drawContext::global()->draw();
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
