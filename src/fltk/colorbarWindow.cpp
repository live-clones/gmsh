// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// This class was inspired by the colorbar widget provided in Vis5d, a
// program for visualizing five dimensional gridded data sets
// Copyright (C) 1990 - 1995 Bill Hibbard, Brian Paul, Dave Santek,
// and Andre Battaiola.

#include <FL/fl_draw.H>
#include "colorbarWindow.h"
#include "uiSources.h"
#include "FlGui.h"

#define EPS 1.e-10

colorbarWindow::colorbarWindow(int x, int y, int w, int h, const char *l)
  : Fl_Window(x, y, w, h, l)
{
  label = nullptr;
  font_height = FL_NORMAL_SIZE - 1; // use slightly smaller font
  minval = maxval = 0.0;
}

// the entry, the intensity and the part of the picture under x, y
void colorbarWindow::_at(int x, int y, int &entry, int &value, bool &onWedge)
{
  Ui::MapEditor::at(_map, x, y, w(), h(), font_height, entry, value, onWedge);
}

// what Ui::MapEditor::picture() says, drawn over what is behind the model,
// as master has it
void colorbarWindow::draw()
{
  if(_map.empty() || _map.size() < 2) return;
  Ui::Colour behind = fltkSources().settings().background;
  color_bg = fl_color_cube(behind.r * FL_NUM_RED / 256,
                           behind.g * FL_NUM_GREEN / 256,
                           behind.b * FL_NUM_BLUE / 256);
  Fl_Color ink = fl_contrast(FL_BLACK, color_bg);
  fl_color(color_bg);
  fl_rectf(0, 0, w(), h());
  Ui::MapEditor::Picture pic = _edit.picture(_map, w(), h(), font_height);
  wedge_y = (int)pic.wedge;
  for(const auto &x : pic.boxes) {
    fl_color(x.colour.r, x.colour.g, x.colour.b);
    fl_rectf((int)x.x, (int)x.y, std::max(1, (int)x.w), (int)x.h);
  }
  for(const auto &x : pic.segments) {
    if(x.ink)
      fl_color(ink);
    else
      fl_color(x.colour.r, x.colour.g, x.colour.b);
    fl_line((int)x.x0, (int)x.y0, (int)x.x1, (int)x.y1);
  }
  fl_color(ink);
  for(const auto &x : pic.texts) {
    fl_font(FL_HELVETICA, std::max(1, (int)(font_height * x.scale)));
    int left = (int)(x.right ? x.x - fl_width(x.text.c_str()) : x.x);
    fl_draw(x.text.c_str(), left, (int)x.y + fl_height() - fl_descent());
  }
}

void colorbarWindow::update(const char *name, double min, double max,
                            const Ui::ColourMap &map, bool *changed)
{
  label = name;
  _map = map;
  viewchanged = changed;
  minval = min;
  maxval = max;
  redraw();
}

int colorbarWindow::handle(int event)
{
  if(_map.empty()) return Fl_Window::handle(event);

  int key = 0, entry = 0, value = 0;
  unsigned mods = 0;
  bool onWedge = false;

  switch(event) {
  case FL_FOCUS: // accept focus events when asked
  case FL_UNFOCUS: return 1;

  case FL_ENTER:
    take_focus(); // force keyboard focus as soon as the mouse enters
    return 1;

  case FL_LEAVE: return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    if(!FlGui::eventKey(key, mods)) return Fl_Window::handle(event);
    switch(_edit.key(_map, key, mods)) {
    case Ui::MapEditor::NotMine: return Fl_Window::handle(event);
    case Ui::MapEditor::Redraw: redraw(); return 1;
    case Ui::MapEditor::Changed:
      redraw();
      *viewchanged = true;
      do_callback();
      return 1;
    }
    return 1;

  case FL_PUSH: {
    int button = Fl::event_button() == 3 ? 2 : Fl::event_button() == 2 ? 1 : 0;
    if(Fl::event_state(FL_CTRL) || Fl::event_state(FL_META))
      mods |= Ui::ModCommand;
    if(Fl::event_state(FL_SHIFT)) mods |= Ui::ModShift;
    if(Fl::event_state(FL_ALT)) mods |= Ui::ModAlt;
    // on the wedge or below it: the marker
    _at(Fl::event_x(), Fl::event_y(), entry, value, onWedge);
    if(_edit.press(_map, entry, value, button, mods, onWedge) ==
       Ui::MapEditor::Changed)
      *viewchanged = true;
    redraw();
    return 1;
  }

  case FL_DRAG:
    _at(Fl::event_x(), Fl::event_y(), entry, value, onWedge);
    if(_edit.drawing() &&
       _edit.drag(_map, entry, value) == Ui::MapEditor::Changed)
      *viewchanged = true;
    redraw();
    return 1;

  case FL_RELEASE:
    _edit.release();
    if(*viewchanged) do_callback();
    return 1;

  default:
    // don't know what to do with the event: passing it to parent
    return Fl_Window::handle(event);
  }
}
