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
#include "ColorTable.h"

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
  // whether a value may be slid at all: the option that says so in FLTK, where
  // it decides both the dragging and the decimals a value is shown to
  bool _sliding()
  {
    return CTX::instance()->inputScrolling ? true : false;
  }

  bool _wheeled(const Dialog::Field &f, double &value)
  {
    if(f.step <= 0. || !_sliding() || !ImGui::IsItemHovered()) return false;
    ImGui::SetItemKeyOwner(ImGuiKey_MouseWheelY, ImGuiInputFlags_CondHovered);
    float turn = ImGui::GetIO().MouseWheel;
    if(turn == 0.f) return false;
    value += (double)turn * f.step;
    return true;
  }

  // What a channel of a colour map is worth at one entry, and what setting it
  // does to that entry: red, green and blue, or hue, saturation and value,
  // and the alpha over both -- the same four the widget of the window this
  // reproduces draws.
  int _mapChannel(GmshColorTable *table, int i, int channel, bool hsv)
  {
    unsigned int colour = table->table[i];
    int red = CTX::instance()->unpackRed(colour);
    int green = CTX::instance()->unpackGreen(colour);
    int blue = CTX::instance()->unpackBlue(colour);
    if(channel == 3) return CTX::instance()->unpackAlpha(colour);
    if(!hsv) return channel == 0 ? red : (channel == 1 ? green : blue);
    double h, s, v;
    RGB_to_HSV(red / 255., green / 255., blue / 255., &h, &s, &v);
    if(channel == 0) return (int)(h / 6. * 255.);
    return (int)((channel == 1 ? s : v) * 255.);
  }

  void _setMapChannel(GmshColorTable *table, int i, int channel, int value,
                      bool hsv)
  {
    unsigned int colour = table->table[i];
    int red = CTX::instance()->unpackRed(colour);
    int green = CTX::instance()->unpackGreen(colour);
    int blue = CTX::instance()->unpackBlue(colour);
    int alpha = CTX::instance()->unpackAlpha(colour);
    if(channel == 3)
      alpha = value;
    else if(!hsv) {
      if(channel == 0) red = value;
      else if(channel == 1) green = value;
      else blue = value;
    }
    else {
      double h, s, v, r, g, b;
      RGB_to_HSV(red / 255., green / 255., blue / 255., &h, &s, &v);
      if(channel == 0) h = 6. * value / 255.;
      else if(channel == 1) s = value / 255.;
      else v = value / 255.;
      HSV_to_RGB(h, s, v, &r, &g, &b);
      red = (int)(255 * r);
      green = (int)(255 * g);
      blue = (int)(255 * b);
    }
    table->table[i] = CTX::instance()->packColor(red, green, blue, alpha);
  }

  // whether the map is still showing what it answers to, which it stops doing
  // at the first click, as that widget does
  bool _mapHelp = true;

  // where the last stroke left off, so that a drag fills in the entries it
  // passed over rather than only the one it is on
  int _mapFrom(int now)
  {
    static int was = -1;
    if(now < 0) {
      was = -1;
      return -1;
    }
    int from = (was < 0) ? now : was;
    was = now;
    return from;
  }

  // How wide the disc of a direction is: as tall as the lines it hangs over,
  // and square.
  float _discSide(const Dialog::Field &f)
  {
    return (float)f.rows * ImGui::GetFrameHeightWithSpacing() -
           ImGui::GetStyle().ItemSpacing.y;
  }

  // one field of a pane, bound to whatever the description points at: a
  // variable of ours or a Gmsh option, which the accessors hide
  void _field(const Dialog::Field &f, float width)
  {
    bool enabled = f.enabled ? f.enabled() : true;
    ImGui::BeginDisabled(!enabled);
    bool changed = false;
    // A field to be looked at twice: red, as the window this reproduces has
    // the one button that undoes everything. A button is red in the face,
    // with its text turned pale so that it can still be read; anything else
    // has only its text to say it with.
    int painted = 0;
    if(f.alert) {
      if(f.kind == Dialog::Action) {
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
    case Dialog::Label:
      // a rule across the pane, and the line written under it: it takes no
      // line of its own, as it takes none in the window this reproduces
      if(f.rule) {
        ImVec2 at = ImGui::GetCursorScreenPos();
        ImGui::GetWindowDrawList()->AddLine(
          ImVec2(at.x, at.y), ImVec2(at.x + ImGui::GetContentRegionAvail().x,
                                     at.y),
          ImGui::GetColorU32(ImGuiCol_Separator));
      }
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
      // as wide as its text, unless the description says how wide it is: a
      // button that lines up with the values above it says so
      if(ImGui::Button(f.label.c_str(),
                       ImVec2((f.widthShare > 0. || f.widthEm > 0.) ? width :
                                                                     0.f,
                              0.f)))
        changed = true;
      break;
    case Dialog::Spacer: break;
    case Dialog::List: {
      std::string id = "##list" + f.label;
      ImVec2 size(width > 0.f ? width : -FLT_MIN,
                  f.rows ? f.rows * ImGui::GetTextLineHeightWithSpacing() :
                           -FLT_MIN);
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
      // As many decimals as the step it is dragged by, which is what FLTK
      // works out from that step: a length that moves by hundredths is shown
      // to hundredths, whatever it happens to hold.
      // FLTK writes a plain "0" for nothing, whatever the step says, and what
      // the two interfaces show has to be the same thing
      char how[8] = "%g";
      if(value != 0. && f.step > 0. && f.step < 1. && _sliding()) {
        int digits = 0;
        for(double d = f.step; d < 1. && digits < 6; d *= 10.) digits++;
        snprintf(how, sizeof(how), "%%.%df", digits);
      }
      ImGui::SetNextItemWidth(width);
      if(ImGui::InputDouble(f.label.c_str(), &value, 0., 0., how)) {
        const_cast<Dialog::Field &>(f).setNumber(clamped(f, value));
        changed = true;
      }
      if(_wheeled(f, value)) {
        const_cast<Dialog::Field &>(f).setNumber(clamped(f, value));
        changed = true;
      }
    } break;
    case Dialog::Color: {
      unsigned int packed = f.getColour();
      float col[4] = {CTX::instance()->unpackRed(packed) / 255.f,
                      CTX::instance()->unpackGreen(packed) / 255.f,
                      CTX::instance()->unpackBlue(packed) / 255.f,
                      CTX::instance()->unpackAlpha(packed) / 255.f};
      if(ImGui::ColorEdit4(f.label.c_str(), col,
                           ImGuiColorEditFlags_NoInputs |
                             ImGuiColorEditFlags_AlphaPreviewHalf)) {
        const_cast<Dialog::Field &>(f).setColour(CTX::instance()->packColor(
          (int)(col[0] * 255.f + .5f), (int)(col[1] * 255.f + .5f),
          (int)(col[2] * 255.f + .5f), (int)(col[3] * 255.f + .5f)));
        changed = true;
      }
    } break;
    case Dialog::ColorMap: {
      // The colour map of a view, drawn as the widget of the window this
      // reproduces draws it: the four channels over the whole height, the
      // wedge of colours under them, and the value of the marker below that.
      // What is drawn on it is drawn into the table itself.
      std::string name;
      double least = 0., most = 0.;
      GmshColorTable *table = f.colourMap ? f.colourMap(name, least, most) :
                                            nullptr;
      if(!table || table->size < 2) break;
      ImVec2 avail = ImGui::GetContentRegionAvail();
      float wide = (width > 0.f) ? width : avail.x;
      float tall = (f.rows > 0) ? (float)f.rows *
                                    ImGui::GetFrameHeightWithSpacing() :
                                 avail.y;
      if(tall < 4.f * ImGui::GetTextLineHeight()) tall = 4.f * ImGui::GetTextLineHeight();
      ImVec2 at = ImGui::GetCursorScreenPos();
      ImGui::InvisibleButton("##map", ImVec2(wide, tall));
      bool active = ImGui::IsItemActive(), hovered = ImGui::IsItemHovered();
      float lineHeight = ImGui::GetTextLineHeight();
      float labelY = tall - 5.f;
      float markerY = labelY - 2.f * lineHeight;
      float wedgeY = markerY - lineHeight;
      int size = table->size;
      // where an entry of the table is, and what an ordinate is worth
      auto indexToX = [&](int i) {
        return at.x + wide * (float)i / (float)(size - 1);
      };
      auto xToIndex = [&](float x) {
        int i = (int)((x - at.x) * (float)size / wide);
        return i < 0 ? 0 : (i >= size ? size - 1 : i);
      };
      auto valueToY = [&](int v) { return at.y + wedgeY * (1.f - v / 255.f); };
      ImDrawList *into = ImGui::GetWindowDrawList();
      into->AddRectFilled(at, ImVec2(at.x + wide, at.y + tall),
                          ImGui::GetColorU32(ImGuiCol_FrameBg));
      // the four channels, in their own colours
      const ImU32 inks[4] = {IM_COL32(255, 0, 0, 255), IM_COL32(0, 255, 0, 255),
                             IM_COL32(0, 0, 255, 255),
                             ImGui::GetColorU32(ImGuiCol_Text)};
      bool hsv = table->ipar[COLORTABLE_MODE] == COLORTABLE_HSV;
      for(int channel = 0; channel < 4; channel++) {
        for(int i = 1; i < size; i++) {
          int was = _mapChannel(table, i - 1, channel, hsv);
          int now = _mapChannel(table, i, channel, hsv);
          into->AddLine(ImVec2(indexToX(i - 1), valueToY(was)),
                        ImVec2(indexToX(i), valueToY(now)), inks[channel]);
        }
      }
      // the wedge of colours
      for(float x = 0.f; x < wide; x += 1.f) {
        unsigned int colour = table->table[xToIndex(at.x + x)];
        into->AddRectFilled(
          ImVec2(at.x + x, at.y + wedgeY),
          ImVec2(at.x + x + 1.f, at.y + wedgeY + lineHeight),
          IM_COL32(CTX::instance()->unpackRed(colour),
                   CTX::instance()->unpackGreen(colour),
                   CTX::instance()->unpackBlue(colour), 255));
      }
      // What it answers to, until it is drawn on -- the widget of the window
      // this reproduces shows it and forgets it at the first click, and so
      // does this one.
      if(_mapHelp) {
        static const char *const keys[][2] = {
          {"0, 1, 2, 3, ..., 9", "Select predefined colormap 0...9"},
          {"Ctrl+0, ..., Ctrl+9", "Select predefined colormap 10...19"},
          {"F1, ..., F5", "Select predefined colormap 20...24"},
          {"mouse1", "Draw red or hue channel"},
          {"mouse2", "Draw green or saturation channel"},
          {"mouse3", "Draw blue or value channel"},
          {"Ctrl+mouse1", "Draw alpha channel"},
          {"Ctrl+c, Ctrl+v, r", "Copy, paste or reset colormap"},
          {"m", "Toggle RGB/HSV mode"},
          {"left, right", "Translate abscissa"},
          {"Ctrl+left, Ctrl+right", "Rotate abscissa"},
          {"i, Ctrl+i", "Invert abscissa or ordinate"},
          {"up, down", "Modify color channel curvature"},
          {"a, Ctrl+a", "Modify alpha coefficient"},
          {"p, Ctrl+p", "Modify alpha channel power law"},
          {"b, Ctrl+b", "Modify gamma correction"},
          {"h", "Show this help message"}};
        // in a slightly smaller hand than the rest, as that widget writes
        // it, and small enough that the seventeen lines stand clear of the
        // wedge whatever the pane is worth
        ImU32 ink = ImGui::GetColorU32(ImGuiCol_Text);
        float small = std::min(ImGui::GetFontSize() * .85f,
                               (wedgeY - 12.f) / 18.f);
        float step = small + 1.f;
        for(int i = 0; i < 17; i++) {
          into->AddText(ImGui::GetFont(), small,
                        ImVec2(at.x + 6.f, at.y + 8.f + i * step), ink,
                        keys[i][0]);
          into->AddText(ImGui::GetFont(), small,
                        ImVec2(at.x + 12.f * step, at.y + 8.f + i * step), ink,
                        keys[i][1]);
        }
      }
      // and what the value under the marker is
      char says[64];
      snprintf(says, sizeof(says), "%g", least);
      into->AddText(ImVec2(at.x + 10.f, at.y + labelY - lineHeight),
                    ImGui::GetColorU32(ImGuiCol_Text), says);
      snprintf(says, sizeof(says), "%g", most);
      ImVec2 wide2 = ImGui::CalcTextSize(says);
      into->AddText(ImVec2(at.x + wide - wide2.x - 10.f,
                           at.y + labelY - lineHeight),
                    ImGui::GetColorU32(ImGuiCol_Text), says);
      // Drawing on it: a button per channel, as that widget has it, and the
      // entries between the last one and this one are all given the value.
      if(active) {
        _mapHelp = false;
        ImVec2 mouse = ImGui::GetIO().MousePos;
        int channel = ImGui::GetIO().KeyCtrl ? 3 :
                      ImGui::IsMouseDown(ImGuiMouseButton_Right) ? 2 :
                      ImGui::IsMouseDown(ImGuiMouseButton_Middle) ? 1 : 0;
        int value = (int)((wedgeY - (mouse.y - at.y)) * 255.f / wedgeY);
        value = value < 0 ? 0 : (value > 255 ? 255 : value);
        if(mouse.y - at.y < wedgeY) {
          int to = xToIndex(mouse.x);
          int from = _mapFrom(to);
          for(int i = std::min(from, to); i <= std::max(from, to); i++)
            _setMapChannel(table, i, channel, value, hsv);
          changed = true;
        }
      }
      else
        _mapFrom(-1);
      // and the keys that widget answers to, while the pointer is over it
      if(hovered) {
        for(int i = 0; i <= 9; i++)
          if(ImGui::IsKeyPressed((ImGuiKey)(ImGuiKey_0 + i))) {
            ColorTable_InitParam(ImGui::GetIO().KeyCtrl ? i + 10 : i, table);
            ColorTable_Recompute(table);
            changed = true;
          }
        if(ImGui::IsKeyPressed(ImGuiKey_M)) {
          table->ipar[COLORTABLE_MODE] =
            hsv ? COLORTABLE_RGB : COLORTABLE_HSV;
          changed = true;
        }
        if(ImGui::IsKeyPressed(ImGuiKey_H)) _mapHelp = !_mapHelp;
        if(ImGui::IsKeyPressed(ImGuiKey_R)) {
          ColorTable_InitParam(2, table);
          ColorTable_Recompute(table);
          changed = true;
        }
      }
    } break;
    case Dialog::Direction: {
      // The disc the FLTK spherePositionWidget draws: a circle, and the point
      // one drags over it. Dear ImGui has nothing of the sort, so the panel
      // draws it -- and works out the same direction from the same drag,
      // including the way that widget derives the third component.
      double x = 0., y = 0., z = 0.;
      f.getVector(x, y, z);
      // what is drawn is the direction, not the three numbers: the widget
      // this reproduces normalises them as it takes them
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
          const_cast<Dialog::Field &>(f).setVector(xx, yy, sqrt(1. - norm));
          changed = true;
          x = xx;
          y = yy;
        }
      }
      ImDrawList *into = ImGui::GetWindowDrawList();
      ImU32 ink = ImGui::GetColorU32(enabled ? ImGuiCol_Text :
                                               ImGuiCol_TextDisabled);
      // no box around it: the widget this reproduces is flat and the colour
      // of what is behind it, so what one sees is the circle alone
      into->AddCircle(middle, radius, ink);
      ImVec2 point((float)(middle.x + radius * x),
                   (float)(middle.y - radius * y));
      into->AddRectFilled(ImVec2(point.x - 3.f, point.y - 3.f),
                          ImVec2(point.x + 3.f, point.y + 3.f), ink);
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
      if(f.multiple) {
        // Several switches behind one button, which is how the window this
        // reproduces offers the element and field types. A button and a popup
        // rather than a combo: a combo would draw an arrow for a value it does
        // not have.
        std::vector<std::string> labels;
        std::vector<int> values;
        _dynamic(f, labels, values);
        std::string id = "##menu" + f.label;
        if(ImGui::Button(f.label.c_str(), ImVec2(width, 0.f)))
          ImGui::OpenPopup(id.c_str());
        if(ImGui::BeginPopup(id.c_str())) {
          for(std::size_t k = 0; k < labels.size(); k++) {
            bool on = f.chosen ? f.chosen((int)k) : false;
            if(ImGui::Checkbox(labels[k].c_str(), &on) && f.choose) {
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
      _dynamic(f, labels, values);
      // a choice stands either for its own text or for a number
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

    if(painted) ImGui::PopStyleColor(painted);
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
      if(fields[i].visible && !fields[i].visible()) continue;
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
    if(f.kind == Dialog::Action) {
      // one that says how wide it is takes that, the text being inside it
      if(f.widthShare > 0.) return (float)f.widthShare * item;
      if(f.widthEm > 0.) return (float)f.widthEm * ImGui::GetFontSize();
      return ImGui::CalcTextSize(f.label.c_str()).x +
             2.f * style.FramePadding.x;
    }
    // a swatch says what it is by its colour; it needs no room for text
    if(f.kind == Dialog::Color)
      return ImGui::GetFrameHeight() * 1.6f + style.ItemInnerSpacing.x +
             ImGui::CalcTextSize(f.label.c_str()).x;
    if(f.kind == Dialog::Direction) return _discSide(f);
    if(f.kind == Dialog::Check) {
      float w = ImGui::GetFrameHeight() + style.ItemInnerSpacing.x +
                ImGui::CalcTextSize(f.label.c_str()).x;
      if(f.disclosure) w += 2.f * style.FramePadding.x;
      return w;
    }
    // a menu of switches carries its label inside, as a button does
    if(f.kind == Dialog::Choice && f.multiple)
      return f.widthShare > 0. ? (float)f.widthShare * item :
             f.widthEm > 0.    ? (float)f.widthEm * ImGui::GetFontSize() :
                                 item;
    float w = f.widthShare > 0. ? (float)f.widthShare * item :
              f.widthEm > 0.      ? (float)f.widthEm * ImGui::GetFontSize() :
                                    item;
    return w + style.ItemInnerSpacing.x +
           ImGui::CalcTextSize(f.label.c_str()).x;
  }

  // Whether the field at k shares its cell with the one after it: consecutive
  // fields that declare a share of a field's width are one cell, and all but
  // the last of them sit flush against the next, so that the cell measures
  // exactly what one field would.
  bool _sharesCell(const std::vector<Dialog::Field> &fields, std::size_t k,
                   std::size_t to)
  {
    return fields[k].widthShare > 0. && k + 1 < to &&
           fields[k + 1].widthShare > 0.;
  }

  // how far the next field starts from this one, when this one is packed
  float _packedStep(const std::vector<Dialog::Field> &fields, std::size_t k,
                    std::size_t to, float item)
  {
    if(_sharesCell(fields, k, to)) return (float)fields[k].widthShare * item;
    return _packedWidth(fields[k], item) + ImGui::GetStyle().ItemSpacing.x;
  }

  // Where the columns of a pane laid out on a grid start: a column is as wide
  // as the widest thing in it, and the label of the last field of a row runs
  // on past its column into the space no one else uses -- which is what keeps
  // the columns as narrow as the window this reproduces has them.
  std::vector<float> _gridColumns(const std::vector<Dialog::Field> &fields,
                                  int grid, float item)
  {
    const ImGuiStyle &style = ImGui::GetStyle();
    std::vector<float> width((std::size_t)grid, 0.f);
    int column = 0;
    for(std::size_t k = 0; k < fields.size(); k++) {
      const Dialog::Field &f = fields[k];
      if(!f.sameRow)
        column = 0;
      else if(!f.packed)
        column++;
      if(column >= grid) column = grid - 1;
      if(f.kind == Dialog::Spacer) continue;
      // where the line this field is on ends, so that the cells packed
      // against it can be stepped over the way they are placed
      std::size_t end = k + 1;
      while(end < fields.size() && fields[end].sameRow) end++;
      float need = 0.f;
      std::size_t j = k;
      while(j < fields.size() &&
            (j == k || (fields[j].sameRow && fields[j].packed))) {
        bool last = !(j + 1 < fields.size() && fields[j + 1].sameRow &&
                      fields[j + 1].packed);
        need += last ? _packedWidth(fields[j], item) + style.ItemSpacing.x :
                       _packedStep(fields, j, end, item);
        j++;
      }
      if(!(j < fields.size() && fields[j].sameRow)) {
        // the last of them runs on into the space no one else uses, and one
        // that carries its text inside comes off whole
        const Dialog::Field &l = fields[j - 1];
        if(l.kind == Dialog::Check || l.kind == Dialog::Action ||
           l.kind == Dialog::Label || l.kind == Dialog::Direction ||
           (l.kind == Dialog::Choice && l.multiple))
          need -= _packedWidth(l, item) + style.ItemSpacing.x;
        else
          need -= ImGui::CalcTextSize(l.label.c_str()).x +
                  style.ItemInnerSpacing.x;
      }
      if(need > width[(std::size_t)column]) width[(std::size_t)column] = need;
    }
    return width;
  }

  float _packedTotal(const std::vector<Dialog::Field> &fields, std::size_t from,
                     std::size_t to, float item)
  {
    float total = 0.f;
    for(std::size_t k = from; k < to; k++)
      if(fields[k].packed || fields[k].kind == Dialog::Spacer)
        total += _packedStep(fields, k, to, item);
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
    std::vector<std::pair<const std::vector<Dialog::Field> *, int> > lists;
    for(const auto &q : panel.panes) {
      lists.push_back(std::make_pair(&q.fields, q.columns));
      for(const auto &section : q.sections)
        lists.push_back(std::make_pair(&section.fields, section.columns));
    }
    lists.push_back(std::make_pair(&panel.footer, 0));
    for(const auto &entry : lists) {
      const std::vector<Dialog::Field> *fields = entry.first;
      if(entry.second > 0) {
        // the columns together, and whatever the last label of a row adds
        std::vector<float> column = _gridColumns(*fields, entry.second, item);
        float total = 0.f, at = 0.f;
        int which = 0;
        for(std::size_t k = 0; k < fields->size(); k++) {
          const Dialog::Field &f = (*fields)[k];
          // what a spacer pushes to the right end of a line does not start at
          // a column: the line only has to be as wide as what is on it
          bool loose = k && f.sameRow &&
                       (*fields)[k - 1].kind == Dialog::Spacer;
          if(!f.sameRow) { which = 0; at = 0.f; }
          else if(loose) {
            // it goes on from where the field before the spacer ended
          }
          else if(!f.packed) {
            which++;
            at = 0.f;
            for(int c = 0; c < which && c < entry.second; c++)
              at += column[(std::size_t)c];
          }
          if(f.kind == Dialog::Spacer) continue;
          // the same spacing the placement leaves after each of them
          float end = at + _packedWidth(f, item) + ImGui::GetStyle().ItemSpacing.x;
          if(end > total) total = end;
          bool more = k + 1 < fields->size() && (*fields)[k + 1].sameRow;
          if(more && (f.packed || (*fields)[k + 1].kind == Dialog::Spacer))
            at += _packedWidth(f, item) + ImGui::GetStyle().ItemSpacing.x;
        }
        if(total > widest) widest = total;
        continue;
      }
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

  void _fields(const std::vector<Dialog::Field> &fields, float item,
               int grid = 0);

  // What a pane holds: its own fields, then the sections under them, each with
  // its label as a heading. A long one scrolls rather than making the window as
  // tall as it is.
  void _paneBody(const Dialog::Pane &q, float width, bool boxed)
  {
    // In a dialog that is given a size rather than following its contents,
    // every pane is a box of the same height, and what does not fit in it
    // scrolls inside it -- the tab one is looking at, not the window, and not
    // the tallest tab there is. It is how the window this reproduces has it:
    // a group per tab, an Fl_Scroll for the one that holds the colours.
    if(boxed && !ImGui::BeginChild("##pane", ImVec2(0.f, 0.f),
                                   ImGuiChildFlags_None)) {
      ImGui::EndChild();
      return;
    }
    _fields(q.fields, width, q.columns);
    for(std::size_t i = 0; i < q.sections.size(); i++) {
      const Dialog::Pane &section = q.sections[i];
      if(section.visible && !section.visible()) continue;
      if(section.label.size()) ImGui::SeparatorText(section.label.c_str());
      ImGui::PushID((int)i + 1000);
      _fields(section.fields, width, section.columns);
      ImGui::PopID();
    }
    if(boxed) ImGui::EndChild();
  }

  // A list of fields, laid out in rows: those that ask to share the line of the
  // one before them do, and the row is divided evenly between them. Placing
  // each one at the start of its column is what turns a row of three values
  // into a column of a grid -- letting Dear ImGui put them one after another
  // leaves the headings of a table nowhere near what they head.
  void _fields(const std::vector<Dialog::Field> &fields, float item, int grid)
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
      // A pane laid out on a grid puts every field at the left of its column,
      // the same columns for every row, and lets it take the width it needs:
      // it is what makes the rows of one pane line up with each other.
      std::vector<float> gridW;
      if(grid > 0) {
        columns = grid;
        gridW = _gridColumns(fields, grid, item);
      }
      // SameLine() counts from the edge of the window, not from where the
      // content starts, so the row begins where the cursor already is: an `at`
      // starting at zero puts every field after the first one padding-width
      // too far left, and the labels of a row no longer line up with those of
      // the rows around it
      // SameLine() counts from the edge of the window and adds the offset of
      // the group the fields may be inside -- the one that holds the panes
      // beside the column of side fields. Counting that offset here too would
      // put every field after the first one a side column further right.
      const float inset = ImGui::GetCurrentWindow()->DC.GroupOffset.x;
      float at = ImGui::GetCursorPosX() - inset;
      const float start = at;
      int gridColumn = 0; // the column the next field goes in, on this row
      bool first = true;
      // where the row ends once the fields that hang over the ones under it
      // are left out of the reckoning
      float bottom = -1.f;
      for(std::size_t k = i; k < last; k++) {
        const Dialog::Field &f = fields[k];
        if(f.visible && !f.visible()) continue;
        if(f.kind == Dialog::Spacer) {
          if(grid > 0) {
            // What a spacer pushes to the right end of a line is not in a
            // column: it is against the right edge, which is where the window
            // this reproduces puts the buttons and switches it sets apart.
            float tail = -style.ItemSpacing.x;
            for(std::size_t j = k + 1; j < last; j++) {
              if(fields[j].kind == Dialog::Spacer) continue;
              if(fields[j].visible && !fields[j].visible()) continue;
              tail += _packedWidth(fields[j], item) + style.ItemSpacing.x;
            }
            float least = at + _packedWidth(f, item) + style.ItemSpacing.x;
            // SameLine() counts from the edge of the window and adds the
            // offset of the group the fields are inside; the right edge is
            // where the content region ends
            at = std::max(total - inset - tail, least);
          }
          else
            at += _packedWidth(f, item) + style.ItemSpacing.x + spacerW;
          continue;
        }
        float here = item;
        // a colour map is not a field either: it takes the whole of its pane
        if(f.kind == Dialog::ColorMap)
          here = 0.f;
        // a list is not a field with a label beside it: it takes its whole
        // share of the line, or its contents are cut off
        else if(f.kind == Dialog::List)
          here = columns ? columnW - style.ItemSpacing.x : -FLT_MIN;
        else if(f.widthShare > 0.)
          here = (float)f.widthShare * item;
        else if(f.widthEm > 0.)
          here = (float)f.widthEm * ImGui::GetFontSize();
        else if(grid > 0)
          here = item; // its own width; the column only says where it starts
        else if(!f.packed && columns > 1) {
          // A widget carries its label to its right, so on a crowded row it has
          // to give the label room or the two columns overlap.
          float label = ImGui::CalcTextSize(f.label.c_str()).x +
                        2.f * style.ItemInnerSpacing.x;
          here = std::min(item * 0.5f,
                          std::max(3.f * ImGui::GetFontSize(), columnW - label));
        }
        // Two frames that touch read as one box: a field that shares its
        // cell gives the gap back out of its own width, so that the cell
        // still measures exactly one field but the eye can tell its halves
        // apart. FLTK draws a border around each and needs no such thing.
        if(_sharesCell(fields, k, last)) here -= style.ItemSpacing.x;
        // On a grid, a cell is a field and whatever is packed against it;
        // the first field of a line begins one, and every field after it
        // that is not packed begins the next. A field that begins a cell
        // goes where its column starts, wherever what precedes it on the
        // line happened to end -- except what a spacer has pushed to the
        // right end, which is where the spacer left it.
        bool loose = k > i && fields[k - 1].kind == Dialog::Spacer;
        if(grid > 0) {
          if(k == i)
            gridColumn = 0;
          else if(!f.packed)
            gridColumn++;
          if(gridColumn >= grid) gridColumn = grid - 1;
        }
        float fx = at;
        if(grid > 0 && !loose && (k == i || !f.packed)) {
          fx = start;
          for(int c = 0; c < gridColumn && c < grid; c++)
            fx += gridW[(std::size_t)c];
        }
        if(!first) ImGui::SameLine(fx);
        first = false;
        // and what follows it on the line goes on from where it ends
        if(grid > 0)
          at = fx + (f.packed ? _packedStep(fields, k, last, item) :
                                _packedWidth(f, item) + style.ItemSpacing.x);
        else
          at += f.packed ? _packedStep(fields, k, last, item) : columnW;
        // Dear ImGui builds a widget's identity from its label, so the nine
        // unlabelled boxes of a grid would all be the same widget: hovering
        // and typing would go to whichever it saw first. Where the field
        // stands in its list says which one it is.
        ImGui::PushID((int)k);
        _field(f, here);
        ImGui::PopID();
        // A direction is drawn over the lines that follow it rather than
        // making its own line that tall: the cursor goes back to where the
        // rest of the row left it.
        if(f.kind != Dialog::Direction)
          bottom = ImGui::GetCursorPosY();
        else if(bottom >= 0.f)
          ImGui::SetCursorPosY(bottom);
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
  // What one ordinary field is worth: ten times the font size, which is what
  // the windows this reproduces call IW. A field of a fixed number of pixels
  // would be a different field at every size of type.
  float width = 10.f * ImGui::GetFontSize();
  // how many lines the tallest pane that does not scroll takes: the ones that
  // do are given as many, and scroll the rest
  int most = panel.leastRows;
  for(const auto &q : panel.panes) {
    if(q.scrolling) continue;
    int n = _rows(q.fields);
    for(const auto &section : q.sections)
      n += (section.label.size() ? 1 : 0) + _rows(section.fields);
    if(n > most) most = n;
  }
  if(most < 1) most = 12;
  // ...unless it says how tall it is to be, or one of its panes scrolls: both
  // say the opposite -- it is given a size and keeps it, whichever pane is up
  bool scrolls = panel.leastRows > 0;
  for(const auto &q : panel.panes)
    if(q.scrolling) scrolls = true;
  // The dialog keeps the width its widest row needs, whichever pane is up and
  // whichever section is folded away: a window that grows sideways as one uses
  // it is a window that will not sit still.
  // the widest each dialog has ever needed to be: one that grows and shrinks
  // sideways as one goes through its categories is one that will not sit still
  static float widestSeen[Dialog::NumDialogs] = {0.f};
  float need = 0.f;
  {
    need = _neededWidth(panel, width) +
           2.f * ImGui::GetStyle().WindowPadding.x;
    if(panel.side.size())
      need += 8.f * ImGui::GetFontSize() + 2.f * ImGui::GetStyle().ItemSpacing.x;
    if(need > widestSeen[which])
      widestSeen[which] = need;
    else
      need = widestSeen[which];
    // a window that is given a size rather than following its contents shows
    // a scrollbar as soon as they are taller, and that takes width too
    if(scrolls) need += ImGui::GetStyle().ScrollbarSize;
  }
  float tall = 0.f;
  if(scrolls) {
    // The rows of the tallest pane, and what stands around them: the row of
    // tabs, the title bar, the padding above and below, and a line of slack
    // -- a window that is a pixel short of its contents shows a scrollbar,
    // and one that is a line too tall shows nothing at all.
    const ImGuiStyle &style = ImGui::GetStyle();
    tall = (float)(most + 2) * ImGui::GetFrameHeightWithSpacing() +
           ImGui::GetFrameHeight() + 2.f * style.WindowPadding.y;
    // A category with fewer rows than the last is a shorter window, as it is
    // in the window this reproduces, which builds itself again for it.
    if(tall != _estimatedHeight[which]) {
      _estimatedHeight[which] = tall;
      _sizedDialog[which] = false;
    }
    // Given when it opens, and not again: left to itself Dear ImGui fits a
    // window to what its first frame draws, which is one tab of one category
    // and tells nothing about the rest -- and a row ending in a spacer, one
    // that eats what is left of the line, has no width of its own to fit to.
    if(!_sizedDialog[which]) {
      ImGui::SetNextWindowSize(ImVec2(need, tall));
      _sizedDialog[which] = true;
    }
  }
  ImGui::SetNextWindowSizeConstraints(ImVec2(need, scrolls ? tall : 0.f),
                                      ImVec2(FLT_MAX, FLT_MAX));
  if(!ImGui::Begin(title.c_str(), &_showDialog[which],
                   scrolls ? (ImGuiWindowFlags_NoScrollbar |
                              ImGuiWindowFlags_NoScrollWithMouse) :
                             ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::End();
    return;
  }

  // the column of side fields, down the left of everything else
  if(panel.side.size()) {
    float w = 8.f * ImGui::GetFontSize();
    // as tall as what is beside it, so that a list can fill it; the fields
    // under such a list keep their own line at the bottom
    float tall = 0.f;
    for(const auto &f : panel.side)
      if(f.kind == Dialog::List && !f.rows) {
        tall = ImGui::GetContentRegionAvail().y;
        for(const auto &g : panel.side) {
          if(&g == &f) continue;
          if(g.visible && !g.visible()) continue;
          tall -= ImGui::GetFrameHeightWithSpacing();
        }
      }
    if(ImGui::BeginChild("##side", ImVec2(w, tall),
                         tall > 0.f ? ImGuiChildFlags_None :
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
      _paneBody(q, width, scrolls);
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
      _paneBody(panel.panes[i], width, scrolls);
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

  bool merged = panel.buttonsInFooter && panel.footer.size() &&
                panel.buttons.size();
  if(panel.footer.size()) {
    ImGui::Separator();
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
  _sizedDialog[which] = false;
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
