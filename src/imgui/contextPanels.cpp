// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the Dear ImGui side of the dialogs: one window per dialog, one widget per
// field, bound to what the description points at

#include <algorithm>
#include <cmath>
#include <map>

#include "uiSources.h"
#include "Tree.h"
#include "Layout.h"
#include "MapEditor.h"
#include "fieldWidget.h"
#include "menuActions.h"
#include "GmshConfig.h"

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h" // RenderArrow
#include "imgui_stdlib.h"

#include "appWindow.h"
#include "Gui.h"
#include "GuiActions.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "drawContext.h"

namespace {

  // the pictures FLTK draws on the little buttons after a value, in the
  // same square of -1 to 1, y down; false for one it does not know
  bool _glyph(const std::string &name, ImVec2 lo, ImVec2 hi, ImU32 ink)
  {
    ImVec2 mid(.5f * (lo.x + hi.x), .5f * (lo.y + hi.y));
    float half = .3f * std::min(hi.x - lo.x, hi.y - lo.y);
    auto at = [&](float u, float v) {
      return ImVec2(mid.x + u * half, mid.y + v * half);
    };
    ImDrawList *into = ImGui::GetWindowDrawList();
    if(name == "rotate") {
      for(int k = 0; k <= 24; k++) {
        float a = (float)k / 24.f * 1.5f * 3.14159265f;
        into->PathLineTo(at(.7f * std::cos(a), -.1f - .7f * std::sin(a)));
      }
      into->PathStroke(ink, 0, 1.5f);
      into->AddTriangleFilled(at(.5f, .6f), at(-.1f, .9f), at(-.1f, .3f), ink);
      return true;
    }
    if(name == "graph") {
      ImVec2 axes[] = {at(-.8f, -.8f), at(-.8f, .8f), at(.8f, .8f)};
      into->AddPolyline(axes, 3, ink, 0, 1.f);
      ImVec2 curve[] = {at(-.8f, .3f), at(-.2f, -.2f), at(.3f, .1f),
                        at(.8f, -.4f)};
      into->AddPolyline(curve, 4, ink, 0, 1.5f);
      return true;
    }
    return false;
  }

  // a check box is smaller than a field, as in the other toolkits
  float _checkPad()
  { return std::floor(ImGui::GetStyle().FramePadding.y / 3.f); }
  float _checkBox() { return ImGui::GetFontSize() + 2.f * _checkPad(); }

  // set in the middle of a line `line` tall
  bool _checkbox(const char *name, bool *value, float line)
  {
    if(line > _checkBox())
      ImGui::SetCursorPosY(ImGui::GetCursorPosY() + (line - _checkBox()) / 2.f);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding,
                        ImVec2(ImGui::GetStyle().FramePadding.x, _checkPad()));
    bool changed = ImGui::Checkbox(name, value);
    ImGui::PopStyleVar();
    return changed;
  }

  // BeginTabBar, as wide as the room the tabs were placed in rather than the
  // window, its line no wider
  bool _beginTabBar(const char *id, float width)
  {
    ImGuiContext &g = *GImGui;
    ImGuiWindow *window = g.CurrentWindow;
    if(window->SkipItems) return false;
    ImGuiTabBar *bar = g.TabBars.GetOrAddByKey(window->GetID(id));
    ImVec2 at = window->DC.CursorPos;
    ImRect box(at.x, at.y, at.x + width,
               at.y + g.FontSize + g.Style.FramePadding.y * 2);
    bar->ID = window->GetID(id);
    bar->SeparatorMinX = box.Min.x;
    bar->SeparatorMaxX = box.Max.x;
    return ImGui::BeginTabBarEx(bar, box, ImGuiTabBarFlags_IsFocused);
  }

  double clamped(const Ui::Field &f, double v)
  {
    if(f.maximum <= f.minimum) return v;
    return v < f.minimum ? f.minimum : (v > f.maximum ? f.maximum : v);
  }

  // one step per notch of the wheel while the pointer is over the value: what
  // the arrows of an InputInt would do without taking two thirds of a narrow
  // field; claiming the wheel also keeps it from the window under, every frame
  bool _sliding()
  {
    static int frame = -1;
    static bool on = true;
    int now = ImGui::GetFrameCount();
    if(now != frame) {
      frame = now;
      on = imguiSources().settings().inputScrolling;
    }
    return on;
  }

  bool _wheeled(const Ui::Field &f, double &value)
  {
    if(f.step <= 0. || !_sliding() || !ImGui::IsItemHovered()) return false;
    ImGui::SetItemKeyOwner(ImGuiKey_MouseWheelY, ImGuiInputFlags_CondHovered);
    float turn = ImGui::GetIO().MouseWheel;
    if(turn == 0.f) return false;
    value += (double)turn * f.step;
    return true;
  }

  // the keys pressed in this frame, as Ui::Shortcut says them: the letters,
  // the digits, the function keys and the arrows
  std::vector<std::pair<int, unsigned>> _keysPressed()
  {
    std::vector<std::pair<int, unsigned>> out;
    ImGuiIO &io = ImGui::GetIO();
    unsigned mods = (io.KeyCtrl ? Ui::ModCommand : 0u) |
                    (io.KeyShift ? Ui::ModShift : 0u) |
                    (io.KeyAlt ? Ui::ModAlt : 0u);
    for(int k = 0; k < 26; k++)
      if(ImGui::IsKeyPressed((ImGuiKey)(ImGuiKey_A + k)))
        out.push_back({'A' + k, mods});
    for(int k = 0; k <= 9; k++)
      if(ImGui::IsKeyPressed((ImGuiKey)(ImGuiKey_0 + k)))
        out.push_back({'0' + k, mods});
    for(int k = 0; k < 12; k++)
      if(ImGui::IsKeyPressed((ImGuiKey)(ImGuiKey_F1 + k)))
        out.push_back({Ui::KeyF1 + k, mods});
    const std::pair<ImGuiKey, int> arrows[] = {{ImGuiKey_LeftArrow, Ui::KeyLeft},
                                               {ImGuiKey_RightArrow, Ui::KeyRight},
                                               {ImGuiKey_UpArrow, Ui::KeyUp},
                                               {ImGuiKey_DownArrow, Ui::KeyDown}};
    for(const auto &a : arrows)
      if(ImGui::IsKeyPressed(a.first)) out.push_back({a.second, mods});
    return out;
  }

  // the one map being edited: the help it shows, the stroke being drawn
  Ui::MapEditor _mapEdit;

  float _discSide(const Ui::Field &f)
  {
    return (float)f.rows * ImGui::GetFrameHeightWithSpacing() -
           ImGui::GetStyle().ItemSpacing.y;
  }

  bool _branch(const Ui::Tree &said, const std::string &path, bool &changed)
  {
    if(!said.children) return false;
    for(const auto &child : said.children(path)) {
      Ui::Node node = said.node(child);
      bool branch = !said.children(child).empty();
      bool on = node.picked ? node.picked() : false;
      ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow |
                                 ImGuiTreeNodeFlags_OpenOnDoubleClick;
      if(on) flags |= ImGuiTreeNodeFlags_Selected;
      if(!branch)
        flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
      ImGui::PushID(child.c_str());
      bool unfolded = ImGui::TreeNodeEx(node.label.c_str(), flags);
      if(ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen() && node.pick) {
        node.pick(!on);
        changed = true;
      }
      ImGui::PopID();
      if(branch && unfolded) {
        _branch(said, child, changed);
        ImGui::TreePop();
      }
    }
    return changed;
  }

  // a page of prose: a heading larger and bold, a word slanted in the italic
  // face; the lines of a page as they wrap in the room: each row its pieces,
  // from the words they were cut from
  struct piece {
    std::string text;
    const Ui::Words *from;
    float wide;
    ImFont *face;
  };

  ImFont *_face(const Ui::Words &word, bool heading)
  {
    if(heading) return imguiBoldFont();
    return word.italic ? imguiItalicFont() : nullptr;
  }
  struct proseRow {
    float scale, indent, wide;
    bool bullet, centred, blank;
    std::vector<piece> pieces;
  };

  void _wrapProse(const std::vector<Ui::Line> &page, float room,
                  std::vector<proseRow> &out)
  {
    for(const Ui::Line &l : page) {
      float scale = l.heading ? 1.6f : 1.f;
      ImGui::SetWindowFontScale(scale);
      float indent = l.bullet ? 1.5f * ImGui::GetFontSize() : 0.f;
      if(l.words.empty()) {
        out.push_back({1.f, 0.f, 0.f, false, false, true, {}});
        ImGui::SetWindowFontScale(1.f);
        continue;
      }
      std::vector<std::vector<piece>> rows(1);
      float have = 0.f;
      for(const Ui::Words &word : l.words) {
        ImFont *face = _face(word, l.heading);
        if(face) ImGui::PushFont(face, 0.f);
        std::string held;
        std::size_t i = 0;
        while(i <= word.text.size()) {
          std::size_t j = word.text.find(' ', i);
          std::string next =
            word.text.substr(i, j == std::string::npos ? j : j - i + 1);
          float wide = ImGui::CalcTextSize((held + next).c_str()).x;
          if(have + wide > room - indent && (have > 0.f || held.size())) {
            if(held.size()) {
              float only = ImGui::CalcTextSize(held.c_str()).x;
              rows.back().push_back({held, &word, only, face});
              have += only;
              held.clear();
            }
            rows.push_back(std::vector<piece>());
            have = 0.f;
            while(next.size() && next[0] == ' ') next = next.substr(1);
          }
          held += next;
          if(j == std::string::npos) break;
          i = j + 1;
        }
        if(held.size()) {
          float only = ImGui::CalcTextSize(held.c_str()).x;
          rows.back().push_back({held, &word, only, face});
          have += only;
        }
        if(face) ImGui::PopFont();
      }
      for(std::size_t r = 0; r < rows.size(); r++) {
        float wide = 0.f;
        for(const piece &q : rows[r]) wide += q.wide;
        out.push_back({scale, indent, wide, l.bullet && !r, l.centred, false,
                       rows[r]});
      }
      ImGui::SetWindowFontScale(1.f);
    }
  }

  float _proseHeight(const Ui::Field &f, float room)
  {
    if(!f.prose) return 0.f;
    std::vector<proseRow> rows;
    _wrapProse(f.prose(), room, rows);
    float tall = 0.f;
    for(const proseRow &r : rows)
      tall += ImGui::GetFontSize() * r.scale + ImGui::GetStyle().ItemSpacing.y;
    return tall;
  }

  void _prose(const Ui::Field &f, float width)
  {
    if(!f.prose) return;
    float room = width > 0.f ? width : ImGui::GetContentRegionAvail().x;
    float left = ImGui::GetCursorPosX();
    std::vector<proseRow> rows;
    _wrapProse(f.prose(), room, rows);
    for(const proseRow &row : rows) {
      ImGui::SetWindowFontScale(row.scale);
      if(row.blank) {
        ImGui::TextUnformatted(" ");
        continue;
      }
      float at = left + row.indent;
      if(row.centred && row.wide < room) at = left + .5f * (room - row.wide);
      if(row.bullet) {
        ImGui::SetCursorPosX(left);
        ImGui::TextUnformatted("\xe2\x80\xa2");
        ImGui::SameLine(0.f, 0.f);
      }
      for(std::size_t k = 0; k < row.pieces.size(); k++) {
        const piece &q = row.pieces[k];
        if(k) ImGui::SameLine(0.f, 0.f);
        else ImGui::SetCursorPosX(at);
        bool goes = q.from->follow != nullptr;
        if(goes)
          ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(.02f, .27f, .68f, 1.f));
        if(q.face) ImGui::PushFont(q.face, 0.f);
        ImGui::TextUnformatted(q.text.c_str());
        if(q.face) ImGui::PopFont();
        if(goes) {
          ImVec2 least = ImGui::GetItemRectMin(), most = ImGui::GetItemRectMax();
          ImGui::GetWindowDrawList()->AddLine(
            ImVec2(least.x, most.y - 1.f), ImVec2(most.x, most.y - 1.f),
            ImGui::GetColorU32(ImGuiCol_Text));
          ImGui::PopStyleColor();
          if(ImGui::IsItemHovered()) {
            ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
            if(ImGui::IsMouseClicked(0)) q.from->follow();
          }
        }
      }
    }
    ImGui::SetWindowFontScale(1.f);
  }

  void _field(const Ui::Field &f, float width, float tall = 0.f,
              float indent = 0.f)
  {
    bool enabled = f.enabled ? f.enabled() : true;
    ImGui::BeginDisabled(!enabled);
    // a label written by hand is hidden from the widget, which keeps it as its
    // identity: a name beginning with two hashes
    bool nameAfterButtons = !f.trailing.empty() && !f.labelBefore;
    std::string name =
      (f.labelBefore || nameAfterButtons) ? "##" + f.label : f.label;
    if(f.labelBefore && f.label.size()) {
      // the field starts after the widest such label of its column, the
      // name against it
      float x = ImGui::GetCursorPosX();
      float said = ImGui::CalcTextSize(f.label.c_str()).x;
      if(indent > 0.f)
        ImGui::SetCursorPosX(
          x +
          std::max(0.f, indent - ImGui::GetStyle().ItemInnerSpacing.x - said));
      ImGui::TextUnformatted(f.label.c_str());
      ImGui::SameLine(
        x + (indent > 0.f ? indent : said + ImGui::GetStyle().ItemSpacing.x));
    }
    bool changed = false;
    // the end of the choosing of a number, for a field with done
    bool done = false;
    auto ended = [&f, &done]() {
      if(f.done && ImGui::IsItemDeactivated() &&
         (ImGui::IsItemDeactivatedAfterEdit() ||
          ImGui::IsKeyPressed(ImGuiKey_Enter, false) ||
          ImGui::IsKeyPressed(ImGuiKey_KeypadEnter, false)))
        done = true;
    };
    // a button is red in the face, with its text turned pale
    int painted = 0;
    if(f.alert) {
      if(f.kind == Ui::Action) {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(.62f, .13f, .13f, 1.f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered,
                              ImVec4(.74f, .18f, .18f, 1.f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,
                              ImVec4(.86f, .24f, .24f, 1.f));
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(.98f, .94f, .94f, 1.f));
        painted = 4;
      }
      else {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(.78f, .16f, .16f, 1.f));
        painted = 1;
      }
    }

    switch(f.kind) {
    case Ui::Prose: _prose(f, width); break;
    case Ui::Label:
      if(f.wraps) {
        ImGui::PushTextWrapPos(ImGui::GetCursorPosX() +
                               (width > 0.f ?
                                  width :
                                  ImGui::GetContentRegionAvail().x));
        ImGui::TextUnformatted(f.getText().c_str());
        ImGui::PopTextWrapPos();
        break;
      }
      if(f.heading || f.align != Ui::Left) {
        std::string text = f.getText();
        ImFont *bold = f.heading ? imguiBoldFont() : nullptr;
        if(bold) ImGui::PushFont(bold, 0.f);
        float room = width > 0.f ? width : ImGui::GetContentRegionAvail().x;
        float need = ImGui::CalcTextSize(text.c_str()).x;
        if(need < room)
          ImGui::SetCursorPosX(ImGui::GetCursorPosX() +
                               (f.align == Ui::Right ? 1.f : .5f) *
                                 (room - need));
        ImGui::TextUnformatted(text.c_str());
        if(bold) ImGui::PopFont();
        break;
      }
      ImGui::TextUnformatted(f.getText().c_str());
      break;
    case Ui::Output: {
      std::string value = f.getText();
      ImGui::SetNextItemWidth(width);
      ImGui::InputText(name.c_str(), &value,
                       ImGuiInputTextFlags_ReadOnly);
    } break;
    case Ui::Action: {
      // the one Return presses is framed, and pressed by Return in the
      // window, unless a field is being typed in
      if(f.isDefault) {
        ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.f);
        ImGui::PushStyleColor(ImGuiCol_Border,
                              ImGui::GetStyleColorVec4(ImGuiCol_ButtonActive));
      }
      // Dear ImGui sets a name of several lines in the middle as a block: each
      // line is centred by hand, over a button with none
      bool lines = f.label.find('\n') != std::string::npos;
      std::string said = lines ? "##" + f.label : name;
      if(ImGui::Button(said.c_str(), ImVec2(width, f.hangs ? tall : 0.f)))
        changed = true;
      if(lines) {
        ImVec2 lo = ImGui::GetItemRectMin(), hi = ImGui::GetItemRectMax();
        float high = ImGui::GetTextLineHeight();
        float y =
          lo.y +
          .5f * (hi.y - lo.y -
                 high * (1 + std::count(f.label.begin(), f.label.end(), '\n')));
        std::size_t at = 0;
        while(at <= f.label.size()) {
          std::size_t end = std::min(f.label.find('\n', at), f.label.size());
          std::string one = f.label.substr(at, end - at);
          float wide = ImGui::CalcTextSize(one.c_str()).x;
          ImGui::GetWindowDrawList()->AddText(
            ImVec2(lo.x + .5f * (hi.x - lo.x - wide), y),
            ImGui::GetColorU32(ImGuiCol_Text), one.c_str());
          y += high;
          at = end + 1;
        }
      }
      if(f.isDefault) {
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();
        if(ImGui::IsWindowFocused(ImGuiFocusedFlags_RootAndChildWindows) &&
           !ImGui::GetIO().WantTextInput && enabled &&
           ImGui::IsKeyPressed(ImGuiKey_Enter, false))
          changed = true;
      }
    } break;
    case Ui::Menu: {
      std::string id = "##menu" + f.label;
      float arrow = ImGui::GetFontSize() * 1.2f;
      float w = width > 0.f ? width :
                              ImGui::CalcTextSize(name.c_str()).x +
                                2.f * ImGui::GetStyle().FramePadding.x + arrow;
      if(ImGui::Button(name.c_str(), ImVec2(w, 0.f)))
        ImGui::OpenPopup(id.c_str());
      {
        ImVec2 lo = ImGui::GetItemRectMin(), hi = ImGui::GetItemRectMax();
        float mid = (lo.y + hi.y) * 0.5f;
        float x = hi.x - arrow * 0.55f - ImGui::GetStyle().FramePadding.x;
        float r = ImGui::GetFontSize() * 0.22f;
        ImGui::GetWindowDrawList()->AddTriangleFilled(
          ImVec2(x - r, mid - r * 0.6f), ImVec2(x + r, mid - r * 0.6f),
          ImVec2(x, mid + r * 0.8f),
          ImGui::GetColorU32(ImGuiCol_Text));
      }
      if(ImGui::BeginPopup(id.c_str())) {
        std::vector<std::string> labels;
        std::vector<int> values;
        Ui::choices(f, labels, values);
        for(std::size_t k = 0; k < labels.size(); k++)
          if(ImGui::Selectable(labels[k].c_str())) {
            if(f.choose) f.choose((int)k, true);
            changed = true;
          }
        ImGui::EndPopup();
      }
    } break;
    case Ui::Spacer: break;
    case Ui::List: {
      std::string id = "##list" + f.label;
      ImVec2 size(width > 0.f ? width : -FLT_MIN,
                  f.rows ? f.rows * ImGui::GetTextLineHeightWithSpacing() :
                  tall > 0.f ? tall : -FLT_MIN);
      // a list box, scrolling across too: a long line is not cut; lines of
      // code in the face of fixed width, a size smaller
      ImFont *fixed = f.isCode ? imguiFixedFont() : nullptr;
      if(fixed) ImGui::PushFont(fixed, ImGui::GetStyle().FontSizeBase * .85f);
      if(ImGui::BeginChild(id.c_str(), size, ImGuiChildFlags_FrameStyle,
                           ImGuiWindowFlags_HorizontalScrollbar)) {
        if(f.dynamicChoices) {
          std::vector<std::string> labels;
          std::vector<int> values;
          f.dynamicChoices(labels, values);
          // where a Shift click runs from, the list's own
          ImGuiID list = ImGui::GetID("##anchor");
          for(std::size_t i = 0; i < labels.size(); i++) {
            bool on = f.chosen ? f.chosen((int)i) : false;
            ImGui::PushID((int)i);
            std::string shown = labels[i];
            if(f.columnsEm.size()) shown = "##" + std::to_string(i);
            if(ImGui::Selectable(shown.c_str(), on) && f.choose) {
              // as in a file manager: that line, Ctrl adds or takes one
              // away, Shift runs from the last one clicked
              static std::map<ImGuiID, std::size_t> anchors;
              const ImGuiIO &io = ImGui::GetIO();
              auto anchor = anchors.find(list);
              if(f.multiple && io.KeyCtrl)
                f.choose((int)i, !on);
              else if(f.multiple && io.KeyShift && anchor != anchors.end()) {
                std::size_t a = std::min(anchor->second, i);
                std::size_t b = std::max(anchor->second, i);
                for(std::size_t k = 0; k < labels.size(); k++)
                  f.choose((int)k, k >= a && k <= b);
              }
              else
                for(std::size_t k = 0; k < labels.size(); k++)
                  f.choose((int)k, k == i);
              if(!(f.multiple && io.KeyShift)) anchors[list] = i;
              changed = true;
            }
            if(f.columnsEm.size()) {
              ImVec2 at = ImGui::GetItemRectMin();
              ImU32 ink = ImGui::GetColorU32(ImGuiCol_Text);
              float x = at.x;
              std::size_t start = 0;
              for(std::size_t c = 0; c <= f.columnsEm.size(); c++) {
                std::size_t end = labels[i].find('\t', start);
                std::string cell =
                  labels[i].substr(start, end == std::string::npos ?
                                            std::string::npos : end - start);
                if(cell.size())
                  ImGui::GetWindowDrawList()->AddText(ImVec2(x, at.y), ink,
                                                      cell.c_str());
                if(c < f.columnsEm.size())
                  x += (float)f.columnsEm[c] * ImGui::GetFontSize();
                if(end == std::string::npos) break;
                start = end + 1;
              }
            }
            ImGui::PopID();
          }
        }
        else if(f.list) {
          for(std::size_t i = 0; i < f.list->size(); i++) {
            std::string label = f.itemLabel ? f.itemLabel((int)i)
                                            : std::to_string((*f.list)[i]);
            ImGui::PushID((int)i);
            if(ImGui::Selectable(label.c_str()) && f.removeItem)
              f.removeItem((int)i);
            ImGui::PopID();
          }
        }
      }
      ImGui::EndChild();
      if(fixed) ImGui::PopFont();
    } break;
    case Ui::Text: {
      std::string value = f.getText();
      ImGui::SetNextItemWidth(width);
      // two widgets: the arrow has to sit against the input, so the label is
      // written afterwards by hand
      std::string shown = f.dynamicChoices ? "##" + f.label : name;
      if(f.commitsWhenDone) {
        // read afresh at every frame, the bound value would write over the
        // keyboard between two letters
        static std::map<ImGuiID, std::string> typing;
        std::string &buffer = typing[ImGui::GetID(shown.c_str())];
        ImGui::InputText(shown.c_str(), &buffer);
        if(ImGui::IsItemDeactivatedAfterEdit()) {
          const_cast<Ui::Field &>(f).setText(buffer);
          changed = true;
        }
        else if(!ImGui::IsItemActive() && buffer != value)
          buffer = value;
      }
      else if(ImGui::InputText(shown.c_str(), &value)) {
        const_cast<Ui::Field &>(f).setText(value);
        changed = true;
      }
      if(f.dynamicChoices) {
        std::vector<std::string> labels;
        std::vector<int> values;
        Ui::choices(f, labels, values);
        if(labels.size()) {
          ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
          std::string id = "##pick" + f.label;
          if(ImGui::BeginCombo(id.c_str(), "", ImGuiComboFlags_NoPreview)) {
            for(auto &l : labels)
              if(ImGui::Selectable(l.c_str())) {
                const_cast<Ui::Field &>(f).setText(l);
                changed = true;
              }
            ImGui::EndCombo();
          }
        }
        if(f.label.size()) {
          ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
          ImGui::TextUnformatted(name.c_str());
        }
      }
    } break;
    case Ui::Integer: {
      int value = (int)f.getNumber();
      ImGui::SetNextItemWidth(width);
      // no arrows, which would take two thirds of a narrow field: the wheel
      // steps instead, see _wheeled()
      if(ImGui::InputInt(name.c_str(), &value, 0)) {
        const_cast<Ui::Field &>(f).setNumber(clamped(f, value));
        changed = true;
      }
      double turned = value;
      if(_wheeled(f, turned)) {
        const_cast<Ui::Field &>(f).setNumber(clamped(f, (double)(int)turned));
        changed = true;
      }
    } break;
    case Ui::Number: {
      double value = f.getNumber();
      if(f.slider && f.maximum > f.minimum) {
        float said = (float)value;
        ImGui::SetNextItemWidth(width);
        if(ImGui::SliderFloat(name.c_str(), &said, (float)f.minimum,
                              (float)f.maximum, "%.2f")) {
          const_cast<Ui::Field &>(f).setNumber(said);
          changed = true;
        }
        ended();
        break;
      }
      // "%g" prints negative zero as "-0"
      if(value == 0.) value = 0.;
      // as the other interfaces show it (Ui::numberText): the decimals of
      // the step, unless it is off the grid of the step; a plain "0" for
      // nothing
      char how[16] = "%g";
      if(value != 0. && f.step > 0. && _sliding()) {
        int digits = Ui::decimals(f.step);
        char fixed[64];
        snprintf(fixed, sizeof(fixed), "%.*f", digits, value);
        if(Ui::numberText(value, f.step) == fixed)
          snprintf(how, sizeof(how), "%%.%df", digits);
      }
      ImGui::SetNextItemWidth(width);
      if(f.commitsWhenDone) {
        // acted upon once, not once per digit
        static std::map<ImGuiID, double> typing;
        ImGuiID id = ImGui::GetID(name.c_str());
        auto it = typing.find(id);
        double typed = (it != typing.end()) ? it->second : value;
        if(ImGui::InputDouble(name.c_str(), &typed, 0., 0., how))
          typing[id] = typed;
        if(ImGui::IsItemDeactivatedAfterEdit()) {
          const_cast<Ui::Field &>(f).setNumber(clamped(f, typed));
          typing.erase(id);
          changed = true;
        }
        else if(!ImGui::IsItemActive())
          typing.erase(id);
        break;
      }
      if(ImGui::InputDouble(name.c_str(), &value, 0., 0., how)) {
        const_cast<Ui::Field &>(f).setNumber(clamped(f, value));
        changed = true;
      }
      // Enter, or the field left after an edit
      ended();
      if(_wheeled(f, value)) {
        const_cast<Ui::Field &>(f).setNumber(clamped(f, value));
        changed = true;
      }
    } break;
    case Ui::Color: {
      Ui::Colour was = f.getColour();
      float col[4] = {was.r / 255.f, was.g / 255.f, was.b / 255.f,
                      was.a / 255.f};
      if(ImGui::ColorEdit4(name.c_str(), col,
                           ImGuiColorEditFlags_NoInputs |
                             ImGuiColorEditFlags_AlphaPreviewHalf)) {
        const_cast<Ui::Field &>(f).setColour(Ui::Colour(
          (unsigned char)(col[0] * 255.f + .5f),
          (unsigned char)(col[1] * 255.f + .5f),
          (unsigned char)(col[2] * 255.f + .5f),
          (unsigned char)(col[3] * 255.f + .5f)));
        changed = true;
      }
    } break;
    case Ui::ColorMap: {
      // what is drawn on the map is drawn into the table itself
      std::string name;
      double least = 0., most = 0.;
      const Ui::ColourMap &map = f.map;
      if(map.empty()) break;
      map.about(name, least, most);
      int entries = map.size();
      if(entries < 2) break;
      ImVec2 avail = ImGui::GetContentRegionAvail();
      float wide = (width > 0.f) ? width : avail.x;
      float tall = (f.rows > 0) ? (float)f.rows *
                                    ImGui::GetFrameHeightWithSpacing() :
                                 avail.y;
      if(tall < 4.f * ImGui::GetTextLineHeight()) tall = 4.f * ImGui::GetTextLineHeight();
      ImVec2 at = ImGui::GetCursorScreenPos();
      // the three buttons draw, each its channel
      ImGui::InvisibleButton("##map", ImVec2(wide, tall),
                             ImGuiButtonFlags_MouseButtonLeft |
                               ImGuiButtonFlags_MouseButtonRight |
                               ImGuiButtonFlags_MouseButtonMiddle);
      bool active = ImGui::IsItemActive(), hovered = ImGui::IsItemHovered();
      float lineHeight = ImGui::GetTextLineHeight();
      // what Ui::MapEditor::picture() says, drawn
      Ui::MapEditor::Picture pic = _mapEdit.picture(map, wide, tall, lineHeight);
      ImDrawList *into = ImGui::GetWindowDrawList();
      into->AddRectFilled(at, ImVec2(at.x + wide, at.y + tall),
                          ImGui::GetColorU32(ImGuiCol_FrameBg));
      ImU32 ink = ImGui::GetColorU32(ImGuiCol_Text);
      for(const auto &x : pic.boxes)
        into->AddRectFilled(ImVec2(at.x + x.x, at.y + x.y),
                            ImVec2(at.x + x.x + x.w, at.y + x.y + x.h),
                            IM_COL32(x.colour.r, x.colour.g, x.colour.b, 255));
      for(const auto &x : pic.segments)
        into->AddLine(ImVec2(at.x + x.x0, at.y + x.y0),
                      ImVec2(at.x + x.x1, at.y + x.y1),
                      x.ink ? ink :
                              IM_COL32(x.colour.r, x.colour.g, x.colour.b, 255));
      for(const auto &x : pic.texts) {
        float size = ImGui::GetFontSize() * (float)x.scale;
        float left = (float)x.x;
        if(x.right)
          left -= ImGui::GetFont()
                    ->CalcTextSizeA(size, FLT_MAX, 0.f, x.text.c_str())
                    .x;
        into->AddText(ImGui::GetFont(), size, ImVec2(at.x + left, at.y + x.y),
                      ink, x.text.c_str());
      }
      // the entries between the last stroke and this one are all given the
      // value
      if(active) {
        ImVec2 mouse = ImGui::GetIO().MousePos;
        int entry = 0, value = 0;
        bool onWedge = false;
        Ui::MapEditor::at(map, mouse.x - at.x, mouse.y - at.y, wide, tall,
                          lineHeight, entry, value, onWedge);
        if(ImGui::IsItemActivated()) {
          ImGuiIO &io = ImGui::GetIO();
          unsigned mods = (io.KeyCtrl ? Ui::ModCommand : 0u) |
                          (io.KeyShift ? Ui::ModShift : 0u) |
                          (io.KeyAlt ? Ui::ModAlt : 0u);
          int button = ImGui::IsMouseDown(ImGuiMouseButton_Right)  ? 2 :
                       ImGui::IsMouseDown(ImGuiMouseButton_Middle) ? 1 :
                                                                     0;
          if(_mapEdit.press(map, entry, value, button, mods, onWedge) ==
             Ui::MapEditor::Changed)
            changed = true;
        }
        else if(_mapEdit.drawing()) {
          if(_mapEdit.drag(map, entry, value) == Ui::MapEditor::Changed)
            changed = true;
        }
      }
      else
        _mapEdit.release();
      if(hovered) {
        // the map owns the arrows while the pointer is over it, or Dear ImGui
        // also walks its keyboard focus with them
        ImGuiID owner = ImGui::GetItemID();
        ImGui::SetKeyOwner(ImGuiKey_LeftArrow, owner);
        ImGui::SetKeyOwner(ImGuiKey_RightArrow, owner);
        ImGui::SetKeyOwner(ImGuiKey_UpArrow, owner);
        ImGui::SetKeyOwner(ImGuiKey_DownArrow, owner);
        for(const auto &k : _keysPressed())
          if(_mapEdit.key(map, k.first, k.second) == Ui::MapEditor::Changed)
            changed = true;
      }
    } break;
    case Ui::Hierarchy: {
      // picking a line that folds picks everything under it, which the
      // description says
      if(!f.hierarchy) break;
      const Ui::Tree &said = *f.hierarchy;
      ImVec2 size(width > 0.f ? width : -FLT_MIN,
                  f.rows ? f.rows * ImGui::GetTextLineHeightWithSpacing() :
                  tall > 0.f ? tall : -FLT_MIN);
      if(ImGui::BeginChild("##tree", size, ImGuiChildFlags_Borders))
        if(_branch(said, "", changed)) changed = true;
      ImGui::EndChild();
    } break;
    case Ui::Direction: {
      // Dear ImGui has no disc: drawn here, the third component derived from
      // the drag
      double x = 0., y = 0., z = 0.;
      f.getVector(x, y, z);
      double length = sqrt(x * x + y * y + z * z);
      if(length) {
        x /= length;
        y /= length;
        z /= length;
      }
      float side = _discSide(f);
      ImVec2 at = ImGui::GetCursorScreenPos();
      ImGui::InvisibleButton("##disc", ImVec2(side, side));
      float radius = .5f * side - 3.f;
      ImVec2 middle(at.x + .5f * side, at.y + .5f * side);
      if(enabled && ImGui::IsItemActive()) {
        ImVec2 mouse = ImGui::GetIO().MousePos;
        double xx = (mouse.x - middle.x) / radius;
        double yy = -(mouse.y - middle.y) / radius;
        double norm = sqrt(xx * xx + yy * yy);
        if(norm > 1.) {
          xx /= norm;
          yy /= norm;
          norm = 1.;
        }
        if(xx != x || yy != y) {
          const_cast<Ui::Field &>(f).setVector(xx, yy, sqrt(1. - norm));
          changed = true;
          x = xx;
          y = yy;
        }
      }
      ImDrawList *into = ImGui::GetWindowDrawList();
      ImU32 ink = ImGui::GetColorU32(enabled ? ImGuiCol_Text :
                                               ImGuiCol_TextDisabled);
      into->AddCircle(middle, radius, ink);
      ImVec2 point((float)(middle.x + radius * x),
                   (float)(middle.y - radius * y));
      into->AddRectFilled(ImVec2(point.x - 3.f, point.y - 3.f),
                          ImVec2(point.x + 3.f, point.y + 3.f), ink);
    } break;
    case Ui::Check: {
      bool value = f.getFlag();
      if(!f.disclosure) {
        if(_checkbox(name.c_str(), &value, ImGui::GetFrameHeight())) {
          const_cast<Ui::Field &>(f).setFlag(value);
          changed = true;
        }
      }
      else {
        // Dear ImGui has no arrow in its font: the triangle is drawn
        const ImGuiStyle &style = ImGui::GetStyle();
        ImVec2 text = ImGui::CalcTextSize(name.c_str());
        float arrow = ImGui::GetFrameHeight() * 0.6f;
        float bw = text.x + arrow + style.ItemInnerSpacing.x +
                   2.f * style.FramePadding.x;
        ImVec2 at = ImGui::GetCursorScreenPos();
        if(ImGui::Button(name.c_str(), ImVec2(bw, 0.f))) {
          const_cast<Ui::Field &>(f).setFlag(!value);
          changed = true;
        }
        ImGui::RenderArrow(
          ImGui::GetWindowDrawList(),
          ImVec2(at.x + style.FramePadding.x + text.x + style.ItemInnerSpacing.x,
                 at.y + style.FramePadding.y),
          ImGui::GetColorU32(ImGuiCol_Text),
          value ? ImGuiDir_Up : ImGuiDir_Down, 0.7f);
      }
    } break;
    case Ui::Choice: {
      if(f.multiple) {
        // a button and a popup rather than a combo, which would draw an arrow
        // for a value it does not have
        std::vector<std::string> labels;
        std::vector<int> values;
        Ui::choices(f, labels, values);
        std::string id = "##menu" + f.label;
        if(ImGui::Button(name.c_str(), ImVec2(width, 0.f)))
          ImGui::OpenPopup(id.c_str());
        if(ImGui::BeginPopup(id.c_str())) {
          for(std::size_t k = 0; k < labels.size(); k++) {
            bool on = f.chosen ? f.chosen((int)k) : false;
            if(_checkbox(labels[k].c_str(), &on, 0.f) && f.choose) {
              f.choose((int)k, on);
              changed = true;
            }
          }
          ImGui::EndPopup();
        }
        break;
      }
      std::vector<std::string> labels;
      std::vector<int> values;
      Ui::choices(f, labels, values);
      bool byText = values.empty();
      std::string current = byText ? f.getText() : "";
      double value = byText ? 0. : f.getNumber();
      int which = -1;
      for(std::size_t i = 0; i < labels.size(); i++) {
        if(byText) {
          if(labels[i] == current) which = (int)i;
        }
        else if(i < values.size() && values[i] == (int)value)
          which = (int)i;
      }
      const char *preview = (which >= 0) ? labels[which].c_str() : "";
      ImGui::SetNextItemWidth(width);
      if(ImGui::BeginCombo(name.c_str(), preview)) {
        for(std::size_t i = 0; i < labels.size(); i++) {
          if(!ImGui::Selectable(labels[i].c_str(), (int)i == which)) continue;
          if(byText)
            const_cast<Ui::Field &>(f).setText(labels[i]);
          else if(i < values.size())
            const_cast<Ui::Field &>(f).setNumber(values[i]);
          changed = true;
        }
        ImGui::EndCombo();
      }
    } break;
    }

    // the little buttons after the value, between the field and its name
    for(std::size_t t = 0; t < f.trailing.size(); t++) {
      const Ui::Button &b = f.trailing[t];
      ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
      ImGui::PushID((int)t + 1);
      float side = ImGui::GetFrameHeight();
      ImU32 ink = ImGui::GetColorU32(ImGuiCol_Text);
      if(b.menu) {
        bool open = b.glyph.size() && b.label.empty() ?
                      ImGui::Button("##drop", ImVec2(side, side)) :
                      ImGui::ArrowButton("##drop", ImGuiDir_Down);
        if(b.glyph.size() && b.label.empty())
          _glyph(b.glyph, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(),
                 ink);
        if(open) ImGui::OpenPopup("##m");
        if(ImGui::BeginPopup("##m")) {
          std::vector<Ui::MenuItem> menu = b.menu();
          menuWalk(menu, appWindow::instance());
          ImGui::EndPopup();
        }
      }
      else {
        int on = b.on ? b.on() : 0;
        if(on) ImGui::PushStyleColor(ImGuiCol_Button,
                                     ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]);
        bool pressed =
          b.label.empty() && b.glyph.size() ?
            ImGui::Button("##b", ImVec2(side, side)) :
            ImGui::SmallButton(b.label.size() ? b.label.c_str() : "##b");
        if(b.label.empty() && b.glyph.size())
          _glyph(b.glyph, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(),
                 ink);
        if(pressed) {
          std::function<void()> what = b.action;
          if(what) appWindow::instance()->postAction(what);
        }
        if(on) ImGui::PopStyleColor();
      }
      if(b.tooltip.size() && ImGui::IsItemHovered())
        ImGui::SetTooltip("%s", b.tooltip.c_str());
      ImGui::PopID();
    }
    if(nameAfterButtons && f.label.size()) {
      ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
      ImGui::TextUnformatted(f.label.c_str());
    }

    if(painted) ImGui::PopStyleColor(painted);
    ImGui::EndDisabled();
    if(f.tooltip.size() &&
       ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
      ImGui::SetTooltip("%s", f.tooltip.c_str());
    if(done)
      f.done();
    else if(changed && f.changed) {
      // what a button does may pick in the 3D view, which pumps frames of its
      // own: it waits for the end of this one
      if(f.kind == Ui::Action || f.kind == Ui::Menu)
        appWindow::instance()->postAction(f.changed);
      else
        f.changed();
    }
  }

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
        return Ui::Size(_checkBox() / em + inner + text, frame);
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
      return _proseHeight(f, (float)(width * em)) / em;
    };
    return m;
  }

  // the placed tree of a form, drawn item by item: a field where it was put,
  // tabs as a tab bar with a child window per pane, a box that scrolls as a
  // child window, a rule as a line
  struct treeDrawer {
    appWindow *window;
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

    treeDrawer(appWindow *w, std::string &shown, bool &force,
               const Ui::Placement &p, float e)
      : window(w), pane(shown), forcePane(force), placed(p), em(e),
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
        if(_beginTabBar("##tabs", (float)p.box.w * em)) {
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
                window->postAction([chosen, label]() { chosen(label); });
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
      _field(f, width, tall, indent);
      if(bare) ImGui::PopStyleVar(2);
    }
  };

} // namespace

void drawField(const Ui::Field &f, float width) { _field(f, width); }

void appWindow::_drawDialog(const Ui::Form *which)
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
    if(!state.show && panel.closed) postAction(panel.closed);
    return;
  }

  // placed in what the window offers, which is at least what it needs
  ImVec2 avail = ImGui::GetContentRegionAvail();
  Ui::Placement placed =
    Ui::placeTree(content, m, std::max(need, avail.x) / em,
                  std::max(tall, avail.y) / em, panel.leastRows);
  treeDrawer drawer(this, state.pane, state.forcePane, placed, em);
  for(std::size_t i = 0; i < placed.items.size(); i++)
    if(placed.items[i].parent == (std::size_t)-1)
      drawer.item(i, ImVec2(0.f, 0.f));
  // forced only until the pane has come up, or it fights the tab the user
  // picks
  if(drawer.forced) state.forcePane = false;

  ImGui::End();

  // closed by the user: what the dialog undoes when it goes is undone
  if(!state.show && panel.closed) postAction(panel.closed);
}

appWindow::dialogState &appWindow::_dialog(const Ui::Form &which)
{
  dialogState &state = _dialogs[&which];
  state.name = which.id;
  state.form = &which;
  return state;
}

void appWindow::dropDialog(const Ui::Form &which)
{
  _dialogs.erase(&which);
}

void appWindow::hideDialog(const Ui::Form &which)
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
    if(panel.closed) postAction(panel.closed);
  }
}

bool appWindow::dialogVisible(const Ui::Form &which) const
{
  auto it = _dialogs.find(&which);
  return it != _dialogs.end() && it->second.show;
}

void appWindow::showDialog(const Ui::Form &which)
{
  dialogState &state = _dialog(which);
  state.show = true;
  state.focus = true;
  // forced once: a tab bar not drawn for a while may have forgotten it
  state.forcePane = state.pane.size();
}

std::string appWindow::dialogPane(const Ui::Form &which) const
{
  auto it = _dialogs.find(&which);
  return it == _dialogs.end() ? "" : it->second.pane;
}

void appWindow::setDialogPane(const Ui::Form &which, const std::string &pane)
{
  dialogState &state = _dialog(which);
  state.pane = pane;
  if(state.show) state.forcePane = true;
}
