// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// A described form as a window of Dear ImGui: placed by Ui::placeTree at every
// frame, each field drawn by imguiField() where it was put, tabs as a tab bar,
// a box that scrolls as a child window.

#include "GmshConfig.h"

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <map>
#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h" // RenderArrow
#include "imgui_stdlib.h"

#include "imguiCommon.h"
#include "Layout.h"
#include "MapEditor.h"
#include "Tree.h"

namespace {

  // a map, since how many there are is nobody's to count
  struct dialogState {
    // the key of the saved layout
    std::string name;
    const Ui::Form *form = nullptr;
    // whether it has just been asked for and must be brought forward
    bool show = false, focus = false;
    // the size given to the window, so that it is given again only when what
    // it holds changes
    bool sized = false;
    float width = 0.f, height = 0.f;
    // so that it sits still from one category to the next
    float widest = 0.f;
    // the pane showing, by its label, and whether it has just been asked
    // for: forced until it has come up, not after, or it would fight the tab
    // the user picks
    std::string pane;
    bool forcePane = false;
  };
  std::map<const Ui::Form *, dialogState> _dialogs;

  // in em of the font; the numbers of the page's stylesheet, at its font
  Ui::Metrics _metrics(float item)
  {
    const ImGuiStyle &style = ImGui::GetStyle();
    const double em = ImGui::GetFontSize();
    Ui::Metrics m;
    m.field = item / em;
    // the room between two lines is linePad's, not the style's
    m.row = ImGui::GetFrameHeight() / em;
    m.line = ImGui::GetTextLineHeight() / em;
    m.gap = .6;
    m.cellGap = style.ItemInnerSpacing.x / em;
    m.linePad = .15;
    m.gridRowGap = .3;
    m.rule = (2.f * style.ItemSpacing.y + 1.f) / em;
    m.tabBar = ImGui::GetFrameHeight() / em;
    m.tab = (2.f * style.FramePadding.x + style.ItemInnerSpacing.x) / em;
    m.tabPad = style.ItemSpacing.x / em;
    m.scrollbar = style.ScrollbarSize / em;
    m.textWidth = [em](const std::string &s) {
      return ImGui::CalcTextSize(s.c_str()).x / em;
    };
    m.widget = [em, item, &style](const Ui::Field &f) -> Ui::Size {
      double text = ImGui::CalcTextSize(f.label.c_str()).x / em;
      double frame = ImGui::GetFrameHeight() / em;
      double pad = 2.f * style.FramePadding.x / em;
      double inner = style.ItemInnerSpacing.x / em;
      switch(f.kind) {
      case Ui::Check:
        if(f.disclosure) return Ui::Size(frame + inner + text + pad, frame);
        return Ui::Size(imguiCheckBoxSide() / em + inner + text, frame);
      case Ui::Action: return Ui::Size(text + pad, frame);
      case Ui::Menu: return Ui::Size(text + pad + 1.2, frame);
      case Ui::Choice:
        if(f.multiple) return Ui::Size(item / em, frame);
        break;
      case Ui::Label: {
        ImFont *bold = f.heading ? imguiBoldFont() : nullptr;
        if(bold) ImGui::PushFont(bold, 0.f);
        double wide = ImGui::CalcTextSize(f.getText().c_str()).x / em;
        if(bold) ImGui::PopFont();
        return Ui::Size(wide, frame);
      }
      case Ui::Color: return Ui::Size(frame * 1.6, frame);
      default: break;
      }
      return Ui::Size(-1., frame);
    };
    m.proseHeight = [em](const Ui::Field &f, double width) -> double {
      return imguiProseHeight(f, (float)(width * em)) / em;
    };
    return m;
  }

  // the placed tree of a form, drawn item by item: a field where it was put,
  // tabs as a tab bar with a child window per pane, a box that scrolls as a
  // child window, a rule as a line
  struct treeDrawer {
    // the pane showing, by its label, and whether it is being asked for
    std::string &pane;
    bool &forcePane;
    const Ui::Placement &placed;
    float em;
    // the items inside each item, by pane (-1 for a box)
    std::vector<std::map<int, std::vector<std::size_t> > > kids;
    // whether the pane asked for has come up: with two rows of tabs the
    // family opens first
    bool forced;

    treeDrawer(std::string &shown, bool &force,
               const Ui::Placement &p, float e)
      : pane(shown), forcePane(force), placed(p), em(e),
        kids(p.items.size()), forced(false)
    {
      for(std::size_t i = 0; i < p.items.size(); i++) {
        const Ui::PlacedItem &it = p.items[i];
        if(it.parent != (std::size_t)-1) kids[it.parent][it.pane].push_back(i);
      }
    }

    // whether the pane asked for is somewhere under this item
    bool _holds(const Ui::Item &it) const
    {
      if(it.kind == Ui::Item::ATabs) {
        for(const auto &t : it.tabs->tabs)
          if(t.first == pane || _holds(t.second)) return true;
        return false;
      }
      if(it.kind == Ui::Item::ABox)
        for(const auto &i : it.box->items)
          if(_holds(i)) return true;
      return false;
    }

    // where a rectangle of the placement goes in the window drawn in, which
    // starts at origin, in pixels of the whole
    ImVec2 at(const Ui::Rect &r, const ImVec2 &origin) const
    {
      ImVec2 start = ImGui::GetCursorStartPos();
      return ImVec2(start.x + (float)r.x * em - origin.x,
                    start.y + (float)r.y * em - origin.y);
    }

    void children(std::size_t i, int pane, const ImVec2 &origin)
    {
      auto found = kids[i].find(pane);
      if(found == kids[i].end()) return;
      for(std::size_t k : found->second) item(k, origin);
    }

    // origin: where the window this draws in starts, in pixels of the whole
    void item(std::size_t i, const ImVec2 &origin)
    {
      const Ui::PlacedItem &p = placed.items[i];
      if(p.hidden) return;
      const ImGuiStyle &style = ImGui::GetStyle();
      ImGui::PushID((int)i);
      if(p.item->kind == Ui::Item::ATabs) {
        ImGui::SetCursorPos(at(p.box, origin));
        // no line under the tabs: the frame of the pane is one
        ImGui::PushStyleVar(ImGuiStyleVar_TabBarBorderSize, 0.f);
        if(imguiBeginTabBar("##tabs", (float)p.box.w * em)) {
          const Ui::Tabs &tabs = *p.item->tabs;
          for(std::size_t k = 0; k < tabs.tabs.size(); k++) {
            const std::string &label = tabs.tabs[k].first;
            bool wanted =
              forcePane && (label == pane || _holds(tabs.tabs[k].second));
            ImGuiTabItemFlags flags = wanted ? ImGuiTabItemFlags_SetSelected : 0;
            if(!ImGui::BeginTabItem(label.c_str(), nullptr, flags)) continue;
            if(label == pane) forced = true;
            // picked by the user, not shown by the dialog: only then
            // something to start
            if(!forcePane && label != pane &&
               tabs.tabs[k].second.kind != Ui::Item::ATabs) {
              pane = label;
              if(tabs.chosen) {
                std::function<void(const std::string &)> chosen = tabs.chosen;
                imguiLater([chosen, label]() { chosen(label); });
              }
            }
            const Ui::Rect &r = p.panes[k];
            ImGui::SetCursorPos(at(r, origin));
            // framed in the colour of its tab, so that what follows is seen
            // not to be in it; on whole pixels, or the line is smudged over two
            ImVec2 corner = ImGui::GetCursorScreenPos();
            float x0 = std::floor(corner.x);
            float y0 = std::floor(corner.y);
            float x1 = std::floor(corner.x + (float)r.w * em);
            float y1 = std::floor(corner.y + (float)r.h * em);
            ImGui::GetWindowDrawList()->AddRect(
              ImVec2(x0, y0), ImVec2(x1, y1),
              ImGui::GetColorU32(ImGuiCol_TabSelected));
            if(ImGui::BeginChild("##pane", ImVec2((float)r.w * em,
                                                  (float)r.h * em),
                                 ImGuiChildFlags_None,
                                 ImGuiWindowFlags_NoScrollbar |
                                   ImGuiWindowFlags_NoScrollWithMouse))
              children(i, (int)k, ImVec2((float)r.x * em, (float)r.y * em));
            ImGui::EndChild();
            ImGui::EndTabItem();
          }
          ImGui::EndTabBar();
        }
        ImGui::PopStyleVar();
      }
      else if(p.item->kind == Ui::Item::ABox) {
        if(p.item->box->scrolling) {
          ImGui::SetCursorPos(at(p.box, origin));
          if(ImGui::BeginChild("##scroll", ImVec2((float)p.box.w * em,
                                                  (float)p.box.h * em))) {
            ImVec2 inside((float)p.box.x * em, (float)p.box.y * em);
            children(i, -1, inside);
            // Dear ImGui scrolls to what is submitted: the bottom of what is
            // placed, marked
            float bottom = 0.f;
            for(std::size_t k : kids[i][-1]) {
              const Ui::PlacedItem &q = placed.items[k];
              if(!q.hidden)
                bottom = std::max(bottom, (float)(q.box.y + q.box.h) * em -
                                            inside.y);
            }
            ImVec2 start = ImGui::GetCursorStartPos();
            ImGui::SetCursorPos(ImVec2(start.x, start.y + bottom));
            ImGui::Dummy(ImVec2(0.f, 0.f));
          }
          ImGui::EndChild();
        }
        else
          children(i, -1, origin);
      }
      else if(p.item->kind == Ui::Item::ARule) {
        ImVec2 top = at(p.box, origin);
        ImGui::SetCursorPos(ImVec2(top.x, top.y + style.ItemSpacing.y));
        // on whole pixels, or the line is smudged over two
        ImVec2 here = ImGui::GetCursorScreenPos();
        here = ImVec2(std::floor(here.x), std::floor(here.y));
        ImGui::GetWindowDrawList()->AddLine(
          here, ImVec2(here.x + std::floor((float)p.box.w * em), here.y),
          ImGui::GetColorU32(ImGuiCol_Separator));
      }
      else if(p.field.kind != Ui::Spacer)
        field(p, origin);
      ImGui::PopID();
    }

    void field(const Ui::PlacedItem &p, const ImVec2 &origin)
    {
      const Ui::Field &f = p.field;
      ImVec2 top = at(p.box, origin);
      float indent = 0.f;
      if(f.labelBefore && f.label.size() && p.label.w > 0.) {
        top.x = at(p.label, origin).x;
        indent = (float)(p.box.x - p.label.x) * em;
      }
      // a list down the whole height of the window runs from under the title
      // bar to the bottom edge, a rule on its right: painted, since the
      // window pads what it holds
      bool bare = f.kind == Ui::List && !f.rows && p.aside && origin.x == 0.f &&
                  origin.y == 0.f && Ui::aloneInColumn(placed);
      const ImGuiStyle &style = ImGui::GetStyle();
      float width = (float)p.box.w * em, tall = 0.f;
      if(((f.kind == Ui::List || f.kind == Ui::Hierarchy) && !f.rows) ||
         f.hangs)
        tall = (float)p.box.h * em;
      if(bare) {
        float edge = style.WindowBorderSize;
        float left = top.x <= 2.f * style.WindowPadding.x ? edge : top.x;
        width += top.x - left;
        top = ImVec2(left, ImGui::GetCursorStartPos().y - style.WindowPadding.y);
        tall = ImGui::GetWindowSize().y - top.y - edge;
        ImGui::SetCursorPos(top);
        ImVec2 corner = ImGui::GetCursorScreenPos();
        float x = std::floor(corner.x + width);
        ImGui::GetWindowDrawList()->AddLine(
          ImVec2(x, corner.y), ImVec2(x, corner.y + tall),
          ImGui::GetColorU32(ImGuiCol_Border));
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.f);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.f);
      }
      ImGui::SetCursorPos(top);
      // a name before a widget stands level with its text; a label is a
      // line of text on its own
      if(f.kind != Ui::Label && f.labelBefore && f.label.size())
        ImGui::AlignTextToFramePadding();
      imguiField(f, width, tall, indent);
      if(bare) ImGui::PopStyleVar(2);
    }
  };


  void _drawDialog(const Ui::Form *which)
  {
    auto found = _dialogs.find(which);
    if(found == _dialogs.end() || !found->second.show) return;
    // a reference into a map stays good while the entry does
    dialogState &state = found->second;

    Ui::Form panel = state.form ? *state.form : Ui::Form();
    state.name = panel.id;
    std::string title = panel.title;
    // the title is the identity of the window and the key of the saved layout:
    // the name the form was made under
    title += "###form:" + state.name;

    if(state.focus) {
      state.focus = false;
      ImGui::SetNextWindowFocus();
    }
    const ImGuiStyle &style = ImGui::GetStyle();
    const float em = ImGui::GetFontSize();
    Ui::Metrics m = _metrics(10.f * em);
    const Ui::Item &content = panel.content;
    // what the form needs; the widest seen is kept, so that it sits still from
    // one category of options to the next
    Ui::Size asked = Ui::treeSize(content, m, panel.leastRows);
    float need = (float)asked.w * em;
    if(need > state.widest)
      state.widest = need;
    else
      need = state.widest;
    float tall = (float)asked.h * em;
    // given when it opens and when what it holds changes; not shrunk by hand
    ImVec2 size(need + 2.f * style.WindowPadding.x,
                tall + 2.f * style.WindowPadding.y + ImGui::GetFrameHeight());
    if(!state.sized || size.x != state.width || size.y != state.height) {
      ImGui::SetNextWindowSize(size);
      state.sized = true;
      state.width = size.x;
      state.height = size.y;
    }
    ImGui::SetNextWindowSizeConstraints(size, ImVec2(FLT_MAX, FLT_MAX));
    if(!ImGui::Begin(title.c_str(), &state.show,
                     ImGuiWindowFlags_NoScrollbar |
                       ImGuiWindowFlags_NoScrollWithMouse)) {
      ImGui::End();
      // the cross of a collapsed window
      if(!state.show && panel.closed) imguiLater(panel.closed);
      return;
    }

    // placed in what the window offers, which is at least what it needs
    ImVec2 avail = ImGui::GetContentRegionAvail();
    Ui::Placement placed =
      Ui::placeTree(content, m, std::max(need, avail.x) / em,
                    std::max(tall, avail.y) / em, panel.leastRows);
    treeDrawer drawer(state.pane, state.forcePane, placed, em);
    for(std::size_t i = 0; i < placed.items.size(); i++)
      if(placed.items[i].parent == (std::size_t)-1)
        drawer.item(i, ImVec2(0.f, 0.f));
    // forced only until the pane has come up, or it fights the tab the user
    // picks
    if(drawer.forced) state.forcePane = false;

    ImGui::End();

    // closed by the user: what the dialog undoes when it goes is undone
    if(!state.show && panel.closed) imguiLater(panel.closed);
  }

  dialogState &_dialog(const Ui::Form &which)
  {
    dialogState &state = _dialogs[&which];
    state.name = which.id;
    state.form = &which;
    return state;
  }


  void _hide(const Ui::Form &which)
  {
    auto it = _dialogs.find(&which);
    if(it == _dialogs.end()) return;
    dialogState &state = it->second;
    bool was = state.show;
    state.show = false;
    state.sized = false;
    // hidden from a menu: undone all the same
    if(was && state.form) {
      Ui::Form panel = *state.form;
      if(panel.closed) imguiLater(panel.closed);
    }
  }


  void _show(const Ui::Form &which)
  {
    dialogState &state = _dialog(which);
    state.show = true;
    state.focus = true;
    // forced once: a tab bar not drawn for a while may have forgotten it
    state.forcePane = state.pane.size();
  }


} // namespace

void imguiShowForm(const Ui::Form &form, bool show)
{
  if(show)
    _show(form);
  else
    _hide(form);
}

void imguiDropForm(const Ui::Form &which)
{
  _dialogs.erase(&which);
}

bool imguiFormVisible(const Ui::Form &which)
{
  auto it = _dialogs.find(&which);
  return it != _dialogs.end() && it->second.show;
}

std::string imguiFormPane(const Ui::Form &which)
{
  auto it = _dialogs.find(&which);
  return it == _dialogs.end() ? "" : it->second.pane;
}

void imguiSetFormPane(const Ui::Form &which, const std::string &pane)
{
  dialogState &state = _dialog(which);
  state.pane = pane;
  if(state.show) state.forcePane = true;
}

void imguiDrawForms()
{
  // off a copy: drawing one may ask for another to be made
  std::vector<const Ui::Form *> forms;
  for(const auto &it : _dialogs) forms.push_back(it.first);
  for(const Ui::Form *which : forms) _drawDialog(which);
}
