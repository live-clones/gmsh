// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The Dear ImGui side of the dialog description of src/common/GuiDialogs.h: one
// window per dialog, one widget per declared field, each bound to the variable
// the description points at. The FLTK interface builds the same description
// into the windows contextWindow.cpp used to hold.

#include <algorithm>

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_internal.h" // RenderArrow
#include "imgui_stdlib.h"

#include "appWindow.h"
#include "Gui.h"
#include "GuiActions.h"
#include "GuiDialogs.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "drawContext.h"

namespace {

  void _dynamic(const Dialog::Field &f, std::vector<std::string> &labels,
                std::vector<int> &values)
  {
    if(f.dynamicChoices)
      f.dynamicChoices(labels, values);
    else {
      labels = f.choices;
      values = f.values;
    }
  }

  // what a bounded field will accept
  double clamped(const Dialog::Field &f, double v)
  {
    if(f.maximum <= f.minimum) return v;
    return v < f.minimum ? f.minimum : (v > f.maximum ? f.maximum : v);
  }

  // Turn the value that was just drawn, by one step per notch of the wheel,
  // while the pointer is over it. This is what the arrows of an InputInt would
  // do, without spending two thirds of a narrow field on them; a step is
  // declared by the same fields that can be slid with the mouse in FLTK.
  // Claiming the wheel for the hovered field also keeps it from reaching the
  // window under it, and has to be done on every frame it is hovered.
  bool _wheeled(const Dialog::Field &f, double &value)
  {
    if(f.step <= 0. || !ImGui::IsItemHovered()) return false;
    ImGui::SetItemKeyOwner(ImGuiKey_MouseWheelY, ImGuiInputFlags_CondHovered);
    float turn = ImGui::GetIO().MouseWheel;
    if(turn == 0.f) return false;
    value += (double)turn * f.step;
    return true;
  }

  // one field of a pane, bound to whatever the description points at: a
  // variable of ours or a Gmsh option, which the accessors hide
  void _field(const Dialog::Field &f, float width)
  {
    bool enabled = f.enabled ? f.enabled() : true;
    ImGui::BeginDisabled(!enabled);
    bool changed = false;

    switch(f.kind) {
    case Dialog::Label:
      ImGui::TextUnformatted(f.getText().c_str());
      break;
    case Dialog::Output: {
      // a value one reads: an input that will not take anything
      std::string value = f.getText();
      ImGui::SetNextItemWidth(width);
      ImGui::InputText(f.label.c_str(), &value,
                       ImGuiInputTextFlags_ReadOnly);
    } break;
    case Dialog::Action:
      if(ImGui::Button(f.label.c_str())) changed = true;
      break;
    case Dialog::Spacer: break;
    case Dialog::List: {
      std::string id = "##list" + f.label;
      ImVec2 size(width > 0.f ? width : -FLT_MIN,
                  f.rows * ImGui::GetTextLineHeightWithSpacing());
      if(ImGui::BeginListBox(id.c_str(), size)) {
        if(f.dynamicChoices) {
          // a list one chooses from
          std::vector<std::string> labels;
          std::vector<int> values;
          f.dynamicChoices(labels, values);
          for(std::size_t i = 0; i < labels.size(); i++) {
            bool on = f.chosen ? f.chosen((int)i) : false;
            ImGui::PushID((int)i);
            if(ImGui::Selectable(labels[i].c_str(), on) && f.choose) {
              if(f.multiple)
                f.choose((int)i, !on);
              else
                for(std::size_t k = 0; k < labels.size(); k++)
                  f.choose((int)k, k == i);
              changed = true;
            }
            ImGui::PopID();
          }
        }
        else if(f.list) {
          // a list one only shows: a line one clicks is one to be rid of
          for(std::size_t i = 0; i < f.list->size(); i++) {
            std::string label = f.itemLabel ? f.itemLabel((int)i)
                                            : std::to_string((*f.list)[i]);
            ImGui::PushID((int)i);
            if(ImGui::Selectable(label.c_str()) && f.removeItem)
              f.removeItem((int)i);
            ImGui::PopID();
          }
        }
        ImGui::EndListBox();
      }
    } break;
    case Dialog::Text: {
      std::string value = f.getText();
      ImGui::SetNextItemWidth(width);
      // A field one may also choose from is two widgets, not one: the arrow
      // has to sit against the input, where a Choice draws its own, so the
      // label is written afterwards by hand rather than by InputText.
      std::string shown = f.dynamicChoices ? "##" + f.label : f.label;
      if(ImGui::InputText(shown.c_str(), &value)) {
        const_cast<Dialog::Field &>(f).setText(value);
        changed = true;
      }
      if(f.dynamicChoices) {
        // what one may want to type, without being held to it
        std::vector<std::string> labels;
        std::vector<int> values;
        _dynamic(f, labels, values);
        if(labels.size()) {
          ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
          std::string id = "##pick" + f.label;
          if(ImGui::BeginCombo(id.c_str(), "", ImGuiComboFlags_NoPreview)) {
            for(auto &l : labels)
              if(ImGui::Selectable(l.c_str())) {
                const_cast<Dialog::Field &>(f).setText(l);
                changed = true;
              }
            ImGui::EndCombo();
          }
        }
        if(f.label.size()) {
          ImGui::SameLine(0.f, ImGui::GetStyle().ItemInnerSpacing.x);
          ImGui::TextUnformatted(f.label.c_str());
        }
      }
    } break;
    case Dialog::Integer: {
      int value = (int)f.getNumber();
      ImGui::SetNextItemWidth(width);
      // no arrows: Dear ImGui draws them inside the field, where they take
      // two thirds of a narrow one, and every value in these dialogs is
      // narrow. The step is turned with the wheel instead -- see _wheeled()
      if(ImGui::InputInt(f.label.c_str(), &value, 0)) {
        const_cast<Dialog::Field &>(f).setNumber(clamped(f, value));
        changed = true;
      }
      double turned = value;
      if(_wheeled(f, turned)) {
        const_cast<Dialog::Field &>(f).setNumber(clamped(f, (double)(int)turned));
        changed = true;
      }
    } break;
    case Dialog::Number: {
      double value = f.getNumber();
      // a rotation that has been turned back to nothing comes out as negative
      // zero, which "%g" prints as "-0"; FLTK shows it as the nothing it is
      if(value == 0.) value = 0.;
      ImGui::SetNextItemWidth(width);
      if(ImGui::InputDouble(f.label.c_str(), &value, 0., 0., "%g")) {
        const_cast<Dialog::Field &>(f).setNumber(clamped(f, value));
        changed = true;
      }
      if(_wheeled(f, value)) {
        const_cast<Dialog::Field &>(f).setNumber(clamped(f, value));
        changed = true;
      }
    } break;
    case Dialog::Check: {
      bool value = f.getFlag();
      if(!f.disclosure) {
        if(ImGui::Checkbox(f.label.c_str(), &value)) {
          const_cast<Dialog::Field &>(f).setFlag(value);
          changed = true;
        }
      }
      else {
        // A fold, not a setting: a button carrying an arrow that says which way
        // it goes, as the window this replaces draws it. Dear ImGui has no
        // arrow in its font, so it draws the triangle itself.
        const ImGuiStyle &style = ImGui::GetStyle();
        ImVec2 text = ImGui::CalcTextSize(f.label.c_str());
        float arrow = ImGui::GetFrameHeight() * 0.6f;
        float bw = text.x + arrow + style.ItemInnerSpacing.x +
                   2.f * style.FramePadding.x;
        ImVec2 at = ImGui::GetCursorScreenPos();
        if(ImGui::Button(f.label.c_str(), ImVec2(bw, 0.f))) {
          const_cast<Dialog::Field &>(f).setFlag(!value);
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
    case Dialog::Choice: {
      std::vector<std::string> labels;
      std::vector<int> values;
      _dynamic(f, labels, values);
      // a choice stands either for its own text or for a number
      bool byText = f.text && values.empty();
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
      if(ImGui::BeginCombo(f.label.c_str(), preview)) {
        for(std::size_t i = 0; i < labels.size(); i++) {
          if(!ImGui::Selectable(labels[i].c_str(), (int)i == which)) continue;
          if(byText)
            const_cast<Dialog::Field &>(f).setText(labels[i]);
          else if(i < values.size())
            const_cast<Dialog::Field &>(f).setNumber(values[i]);
          changed = true;
        }
        ImGui::EndCombo();
      }
    } break;
    }

    ImGui::EndDisabled();
    if(f.tooltip.size() &&
       ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
      ImGui::SetTooltip("%s", f.tooltip.c_str());
    if(changed && f.changed) f.changed();
  }

  // how many lines a list of fields takes, once those that share one are put
  // together
  int _rows(const std::vector<Dialog::Field> &fields)
  {
    int rows = 0;
    for(std::size_t i = 0; i < fields.size(); i++) {
      if(fields[i].sameRow && i) continue;
      // a list is worth as many lines as it shows
      rows += (fields[i].kind == Dialog::List) ? fields[i].rows : 1;
    }
    return rows;
  }

  // What a packed field needs: its own text and no more. It takes the width it
  // asks for rather than a share of the line.
  // what a field asks for when it is not given a share of the line
  float _packedWidth(const Dialog::Field &f, float item)
  {
    const ImGuiStyle &style = ImGui::GetStyle();
    if(f.kind == Dialog::Spacer)
      return (float)(f.widthEm > 0. ? f.widthEm : 2.) * ImGui::GetFontSize();
    if(f.kind == Dialog::Label) return ImGui::CalcTextSize(f.getText().c_str()).x;
    if(f.kind == Dialog::Action)
      return ImGui::CalcTextSize(f.label.c_str()).x +
             2.f * style.FramePadding.x;
    if(f.kind == Dialog::Check) {
      float w = ImGui::GetFrameHeight() + style.ItemInnerSpacing.x +
                ImGui::CalcTextSize(f.label.c_str()).x;
      if(f.disclosure) w += 2.f * style.FramePadding.x;
      return w;
    }
    float w = f.widthShare > 0. ? (float)f.widthShare * item :
              f.widthEm > 0.      ? (float)f.widthEm * ImGui::GetFontSize() :
                                    item;
    // an unlabelled field has nothing to keep at arm's length: it sits flush
    // against whatever follows, the way the two ends of a range do
    if(f.label.empty()) return w;
    return w + style.ItemInnerSpacing.x +
           ImGui::CalcTextSize(f.label.c_str()).x;
  }

  float _packedTotal(const std::vector<Dialog::Field> &fields, std::size_t from,
                     std::size_t to, float item)
  {
    float total = 0.f;
    for(std::size_t k = from; k < to; k++)
      if(fields[k].packed || fields[k].kind == Dialog::Spacer)
        total += _packedWidth(fields[k], item) +
                 (fields[k].label.empty() && fields[k].kind != Dialog::Spacer ?
                    0.f : ImGui::GetStyle().ItemSpacing.x);
    return total;
  }

  // the width the widest column of a row needs
  float _rowNeed(const std::vector<Dialog::Field> &fields, std::size_t from,
                 std::size_t to, float item);

  // How wide a row is, item and label together. It has to be measured, since
  // the description does not say how wide anything is.
  float _rowWidth(const std::vector<Dialog::Field> &fields, std::size_t from,
                  std::size_t to, float item)
  {
    const ImGuiStyle &style = ImGui::GetStyle();
    int columns = 0;
    for(std::size_t k = from; k < to; k++)
      if(!fields[k].packed && fields[k].kind != Dialog::Spacer) columns++;
    // what is left of the row is divided evenly, so every column has to be as
    // wide as the one that needs the most
    float widest = 0.f;
    for(std::size_t k = from; k < to; k++) {
      const Dialog::Field &f = fields[k];
      if(f.packed || f.kind == Dialog::Spacer) continue;
      float here = 0.f;
      if(f.kind == Dialog::List) {
        // wide enough for a loop of a few entities spelled out
        here = item * 2.5f;
      }
      else if(f.kind == Dialog::Label) {
        here = ImGui::CalcTextSize(f.getText().c_str()).x;
      }
      else if(f.kind == Dialog::Action) {
        here = ImGui::CalcTextSize(f.label.c_str()).x +
               2.f * style.FramePadding.x;
      }
      else if(f.kind == Dialog::Check) {
        here = ImGui::GetFrameHeight() + style.ItemInnerSpacing.x +
               ImGui::CalcTextSize(f.label.c_str()).x;
      }
      else {
        // a field sharing its line gets half the usual width, as in the FLTK
        // dialogs, or three columns of full-width inputs would be absurd
        here = (columns > 1 ? item * 0.5f : item) + style.ItemInnerSpacing.x +
               ImGui::CalcTextSize(f.label.c_str()).x;
        // the button that offers what one may type
        if(f.kind == Dialog::Text && f.dynamicChoices)
          here += ImGui::GetFrameHeight() + style.ItemSpacing.x;
      }
      here += style.ItemSpacing.x;
      if(here > widest) widest = here;
    }
    return widest * (float)columns + _packedTotal(fields, from, to, item);
  }

  float _rowNeed(const std::vector<Dialog::Field> &fields, std::size_t from,
                 std::size_t to, float item)
  {
    int columns = 0;
    for(std::size_t k = from; k < to; k++)
      if(!fields[k].packed && fields[k].kind != Dialog::Spacer) columns++;
    if(!columns) return 0.f;
    return (_rowWidth(fields, from, to, item) -
            _packedTotal(fields, from, to, item)) /
           (float)columns;
  }

  // The width the dialog needs, folded parts included: a window that grows
  // sideways when one unfolds a section is a window that will not sit still.
  float _neededWidth(const Dialog::Panel &panel, float item)
  {
    float widest = 0.f;
    std::vector<const std::vector<Dialog::Field> *> lists;
    for(const auto &q : panel.panes) lists.push_back(&q.fields);
    lists.push_back(&panel.footer);
    for(const auto *fields : lists) {
      std::size_t i = 0;
      while(i < fields->size()) {
        std::size_t last = i + 1;
        while(last < fields->size() && (*fields)[last].sameRow) last++;
        float w = _rowWidth(*fields, i, last, item);
        if(w > widest) widest = w;
        i = last;
      }
    }
    return widest;
  }

  // A list of fields, laid out in rows: those that ask to share the line of the
  // one before them do, and the row is divided evenly between them. Placing
  // each one at the start of its column is what turns a row of three values
  // into a column of a grid -- letting Dear ImGui put them one after another
  // leaves the headings of a table nowhere near what they head.
  void _fields(const std::vector<Dialog::Field> &fields, float item)
  {
    std::size_t i = 0;
    while(i < fields.size()) {
      std::size_t last = i + 1;
      while(last < fields.size() && fields[last].sameRow) last++;
      const ImGuiStyle &style = ImGui::GetStyle();
      int columns = 0, spacers = 0;
      for(std::size_t k = i; k < last; k++) {
        if(fields[k].kind == Dialog::Spacer)
          spacers++;
        else if(!fields[k].packed)
          columns++;
      }
      // A packed field takes the width it needs, from where it stands; a spacer
      // eats what is left, which is what pushes whatever follows it to the
      // right. With no spacer, the columns share the slack.
      float total = ImGui::GetContentRegionMax().x;
      float packed = _packedTotal(fields, i, last, item);
      float columnW = _rowNeed(fields, i, last, item);
      float slack = total - packed - columnW * (float)columns;
      if(slack < 0.f) slack = 0.f;
      if(!spacers && columns) columnW += slack / (float)columns;
      float spacerW = spacers ? slack / (float)spacers : 0.f;
      // SameLine() counts from the edge of the window, not from where the
      // content starts, so the row begins where the cursor already is: an `at`
      // starting at zero puts every field after the first one padding-width
      // too far left, and the labels of a row no longer line up with those of
      // the rows around it
      float at = ImGui::GetCursorPosX();
      bool first = true;
      for(std::size_t k = i; k < last; k++) {
        const Dialog::Field &f = fields[k];
        if(f.kind == Dialog::Spacer) {
          at += _packedWidth(f, item) + style.ItemSpacing.x + spacerW;
          continue;
        }
        float here = item;
        // a list is not a field with a label beside it: it takes its whole
        // share of the line, or its contents are cut off
        if(f.kind == Dialog::List)
          here = columns ? columnW - style.ItemSpacing.x : -FLT_MIN;
        else if(f.widthShare > 0.)
          here = (float)f.widthShare * item;
        else if(f.widthEm > 0.)
          here = (float)f.widthEm * ImGui::GetFontSize();
        else if(!f.packed && columns > 1) {
          // A widget carries its label to its right, so on a crowded row it has
          // to give the label room or the two columns overlap.
          float label = ImGui::CalcTextSize(f.label.c_str()).x +
                        2.f * style.ItemInnerSpacing.x;
          here = std::min(item * 0.5f, std::max(40.f, columnW - label));
        }
        // Two frames that touch read as one box: an unlabelled packed field
        // gives the gap back out of its own width, so that the pair still
        // measures exactly one field but the eye can tell them apart. FLTK
        // draws a border around each and needs no such thing.
        if(f.packed && f.label.empty() && k + 1 < last)
          here -= style.ItemSpacing.x;
        if(!first) ImGui::SameLine(at);
        first = false;
        at += f.packed ? _packedWidth(f, item) +
                           (f.label.empty() ? 0.f : style.ItemSpacing.x) :
                         columnW;
        // Dear ImGui builds a widget's identity from its label, so the nine
        // unlabelled boxes of a grid would all be the same widget: hovering
        // and typing would go to whichever it saw first. Where the field
        // stands in its list says which one it is.
        ImGui::PushID((int)k);
        _field(f, here);
        ImGui::PopID();
      }
      i = last;
    }
  }

} // namespace

void appWindow::_drawDialog(int which)
{
  if(!_showDialog[which]) return;

  Dialog::Panel panel = Dialog::panel(which);
  std::string title = panel.title;
  // the physical dialog says which kind of entity it is naming
  if(which == Dialog::Physical)
    title = "Physical " + Dialog::physicalType() + " Context";
  // the title is the identity of the window, so it must not change under Dear
  // ImGui: the dialog index keeps it stable
  title += "###gmshDialog" + std::to_string(which);

  if(_focusDialog[which]) {
    _focusDialog[which] = false;
    ImGui::SetNextWindowFocus();
  }
  // A dialog is worth exactly what it holds: it is not resized by hand and it
  // follows its contents, so that folding a part away shrinks it instead of
  // leaving a hole. Docked, Dear ImGui gives it the size of the node and
  // ignores this, which is what one wants there.
  float width = 150.f * _styleScale;
  // The dialog keeps the width its widest row needs, whichever pane is up and
  // whichever section is folded away: a window that grows sideways as one uses
  // it is a window that will not sit still.
  {
    float need = _neededWidth(panel, width) +
                 2.f * ImGui::GetStyle().WindowPadding.x;
    if(panel.side.size()) need += 10.f * ImGui::GetFontSize();
    ImGui::SetNextWindowSizeConstraints(ImVec2(need, 0.f),
                                        ImVec2(FLT_MAX, FLT_MAX));
  }
  if(!ImGui::Begin(title.c_str(), &_showDialog[which],
                   ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::End();
    return;
  }

  // the column of side fields, down the left of everything else
  if(panel.side.size()) {
    float w = 9.f * ImGui::GetFontSize();
    if(ImGui::BeginChild("##side", ImVec2(w, 0.f),
                         ImGuiChildFlags_AutoResizeY))
      ImGui::PushID("side");
      _fields(panel.side, w);
      ImGui::PopID();
    ImGui::EndChild();
    ImGui::SameLine();
    ImGui::BeginGroup();
  }

  if(!panel.tabbed) {
    // one long form: the panes follow one another as titled sections
    for(std::size_t i = 0; i < panel.panes.size(); i++) {
      const Dialog::Pane &q = panel.panes[i];
      if(q.visible && !q.visible()) continue;
      if(q.label.size()) ImGui::SeparatorText(q.label.c_str());
      ImGui::PushID((int)i);
      _fields(q.fields, width);
      ImGui::PopID();
      if(q.buttonLabel.size()) {
        // against the right edge, where the window this replaces puts it
        float w = ImGui::CalcTextSize(q.buttonLabel.c_str()).x +
                  2.f * ImGui::GetStyle().FramePadding.x;
        ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - w);
        if(ImGui::Button(q.buttonLabel.c_str(), ImVec2(w, 0.f))) {
          std::function<void()> what = q.button;
          if(what) postAction(what);
        }
      }
      if(q.separatorAfter) {
        // A titled section opens with a rule of its own here, which the rule
        // asked for would only double. FLTK draws no such thing, and keeps it.
        bool titled = false;
        for(std::size_t j = i + 1; j < panel.panes.size(); j++) {
          const Dialog::Pane &next = panel.panes[j];
          if(next.visible && !next.visible()) continue;
          titled = next.label.size() > 0;
          break;
        }
        if(!titled) ImGui::Separator();
      }
    }
  }
  else {
    // The pane is forced only when it has just been asked for. Forcing it at
    // every frame while also writing back whichever tab is open makes the two
    // fight, and the dialog flickers between them.
    // The pane that was asked for. It is not forgotten until it has actually
    // come up: with two rows of tabs the family has to open first, and that
    // takes a frame, so clearing the request straight away would leave the
    // family right and the member wrong.
    int wanted = _wantedPane[which];
    // and the height of the tallest pane, for the same reason
    int most = 0;
    for(const auto &q : panel.panes) {
      int n = _rows(q.fields);
      if(n > most) most = n;
    }
    // one pane of a family, wherever the rows of tabs put it
    auto drawPane = [&](std::size_t i) {
      Dialog::currentPane(which) = (int)i;
      if((int)i == wanted) _wantedPane[which] = -1;
      ImGui::PushID((int)i);
      _fields(panel.panes[i].fields, width);
      ImGui::PopID();
      // The pane is padded to the height of the tallest one, so that its
      // button lands at the bottom right and the window does not change size
      // from one tab to the next. The button is not given a line of its own:
      // in a pane that is already as tall as the tallest, it shares the last.
      int mine = _rows(panel.panes[i].fields);
      int pad = most - mine - (panel.panes[i].buttonLabel.size() ? 1 : 0);
      if(pad > 0)
        ImGui::Dummy(ImVec2(0.f, pad * ImGui::GetFrameHeightWithSpacing()));
      if(panel.panes[i].buttonLabel.size()) {
        const char *label = panel.panes[i].buttonLabel.c_str();
        float w = ImGui::CalcTextSize(label).x +
                  2.f * ImGui::GetStyle().FramePadding.x;
        if(pad < 0) ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetContentRegionMax().x - w);
        if(ImGui::Button(label, ImVec2(w, 0.f))) {
          std::function<void()> what = panel.panes[i].button;
          if(what) postAction(what);
        }
      }
    };

    // The panes of a dialog with more of them than fit across one row are
    // gathered into families, and the rows of tabs are nested: which family
    // first, then which member of it. A pane that belongs to no family keeps a
    // tab of its own in the first row.
    struct entry {
      std::string family;
      std::vector<std::size_t> panes;
    };
    std::vector<entry> outer;
    bool nested = false;
    for(std::size_t i = 0; i < panel.panes.size(); i++) {
      const std::string &family = panel.panes[i].group;
      if(family.size()) nested = true;
      bool joined = false;
      for(auto &e : outer)
        if(family.size() && e.family == family) {
          e.panes.push_back(i);
          joined = true;
          break;
        }
      if(!joined) outer.push_back({family, {i}});
    }

    auto tabFor = [&](std::size_t i) {
      if(panel.panes[i].visible && !panel.panes[i].visible()) return;
      ImGuiTabItemFlags flags =
        ((int)i == wanted) ? ImGuiTabItemFlags_SetSelected : 0;
      if(!ImGui::BeginTabItem(panel.panes[i].label.c_str(), nullptr, flags))
        return;
      drawPane(i);
      ImGui::EndTabItem();
      // The user picked this pane, as opposed to the dialog being told to show
      // it: only then does it have something to start. A pane that was asked
      // for takes a frame or two to come up, and the tab bar shows another one
      // meanwhile, which is not a choice anybody made.
      if(wanted < 0 && (int)i != _lastPane[which] && panel.panes[i].chosen)
        postAction(panel.panes[i].chosen);
      _lastPane[which] = (int)i;
    };

    if(!nested) {
      if(ImGui::BeginTabBar("##panes")) {
        for(std::size_t i = 0; i < panel.panes.size(); i++) tabFor(i);
        ImGui::EndTabBar();
      }
    }
    else if(ImGui::BeginTabBar("##families")) {
      for(const auto &e : outer) {
        if(e.family.empty()) {
          tabFor(e.panes[0]);
          continue;
        }
        bool holdsWanted = false;
        for(std::size_t i : e.panes)
          if((int)i == wanted) holdsWanted = true;
        ImGuiTabItemFlags flags =
          holdsWanted ? ImGuiTabItemFlags_SetSelected : 0;
        if(!ImGui::BeginTabItem(e.family.c_str(), nullptr, flags)) continue;
        std::string id = "##panes" + e.family;
        if(ImGui::BeginTabBar(id.c_str())) {
          for(std::size_t i : e.panes) tabFor(i);
          ImGui::EndTabBar();
        }
        ImGui::EndTabItem();
      }
      ImGui::EndTabBar();
    }
  }

  // whether the buttons will share the last line of the footer -- decided
  // before it is drawn, since after it the cursor has already moved on
  bool merged = false;
  if(panel.footer.size()) {
    ImGui::Separator();
    if(panel.buttons.size() && _rows(panel.footer) == 1) {
      float need = _rowWidth(panel.footer, 0, panel.footer.size(), width);
      float room = 0.f;
      for(const auto &b : panel.buttons)
        room += ImGui::CalcTextSize(b.label.c_str()).x +
                2.f * ImGui::GetStyle().FramePadding.x +
                ImGui::GetStyle().ItemSpacing.x;
      merged = need + room <= ImGui::GetContentRegionMax().x;
    }
    ImGui::PushID("footer");
    _fields(panel.footer, width);
    ImGui::PopID();
  }

  if(panel.side.size()) ImGui::EndGroup();

  if(panel.buttons.size()) {
    // gathered at the right in the order they were declared, so that the last
    // one ends against the edge; those that stand apart go to the far left
    const ImGuiStyle &style = ImGui::GetStyle();
    auto widthOf = [&style](const Dialog::Button &b) {
      return ImGui::CalcTextSize(b.label.c_str()).x + 2.f * style.FramePadding.x;
    };
    float group = 0.f;
    int gathered = 0;
    for(const auto &b : panel.buttons)
      if(!b.apart) {
        group += widthOf(b);
        gathered++;
      }
    if(gathered) group += (float)(gathered - 1) * style.ItemSpacing.x;
    float rx = ImGui::GetContentRegionMax().x - group;
    bool first = true, opened = false;
    for(const auto &b : panel.buttons) {
      if(b.apart) {
        if(!first) ImGui::SameLine();
      }
      else if(!opened) {
        // a one-line footer keeps the buttons on its own line, as the window
        // this replaces does: "Memory usage: ..." and Update share one
        if(first && !merged)
          ImGui::SetCursorPosX(rx);
        else
          ImGui::SameLine(rx);
        opened = true;
      }
      else
        ImGui::SameLine();
      first = false;
      if(ImGui::Button(b.label.c_str(), ImVec2(widthOf(b), 0.f))) {
        std::function<void()> what = b.action;
        if(what) postAction(what);
      }
    }
  }

  ImGui::End();
}

void appWindow::hideDialog(int which)
{
  if(which < 0 || which >= Dialog::NumDialogs) return;
  _showDialog[which] = false;
}

bool appWindow::dialogVisible(int which) const
{
  if(which < 0 || which >= Dialog::NumDialogs) return false;
  return _showDialog[which];
}

void appWindow::showDialog(int which)
{
  if(which < 0 || which >= Dialog::NumDialogs) return;
  _showDialog[which] = true;
  _focusDialog[which] = true;
  // the pane the description asks for, to be forced once
  _wantedPane[which] = Dialog::currentPane(which);
}

#endif
