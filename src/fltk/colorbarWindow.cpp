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
  marker_height = font_height;
  wedge_height = marker_height;
  minval = maxval = 0.0;
}

// red, green and blue or hue, saturation and value: what the curves are drawn
// from
int colorbarWindow::_channel(int i, int channel)
{
  Ui::Colour c = _map.colour(i);
  return channel == 0 ? c.r : (channel == 1 ? c.g : c.b);
}

void colorbarWindow::_channels(int i, double &H, double &S, double &V)
{
  int h, s, v;
  Ui::toHsv(_map.colour(i), h, s, v);
  H = 6. * h / 255.;
  S = s / 255.;
  V = v / 255.;
}

int colorbarWindow::x_to_index(int x)
{
  int index;
  index = (int)(x * (double)_map.size() / (double)w());
  if(index < 0)
    index = 0;
  else if(index >= _map.size())
    index = _map.size() - 1;
  return index;
}

int colorbarWindow::index_to_x(int index)
{
  int x;
  x = (int)(index * (double)w() / (double)(_map.size() - 1));
  if(x >= w()) x = w() - 1;
  return x;
}

int colorbarWindow::y_to_intensity(int y)
{
  int intensity;
  intensity = (int)((wedge_y - y) * 255. / (double)wedge_y);
  if(intensity < 0)
    intensity = 0;
  else if(intensity > 255)
    intensity = 255;
  return intensity;
}

int colorbarWindow::intensity_to_y(int intensity)
{
  int y;
  y = (int)(wedge_y - intensity * (double)wedge_y / 255.);
  if(y < 0)
    y = 0;
  else if(y >= wedge_y)
    y = wedge_y - 1;
  return y;
}

void colorbarWindow::redraw_range(int a, int b)
{
  int i;
  int x, y, px = 0, py = 0;
  int x1, y1, x2, y2;
  int intensity = 0;
  double H, S, V;

  if(a < 0) a = 0;
  if(b >= _map.size()) b = _map.size() - 1;

  // calculate region to update
  x1 = index_to_x(a);
  x2 = index_to_x(b);
  y1 = intensity_to_y(255);
  y2 = intensity_to_y(0);

  // erase region
  fl_color(color_bg);
  fl_rectf(x1, y1, x2 - x1 + 1, y2 - y1 + 1);

  // redraw region of entries in interval [a,b]
  if(a > 0) a--;
  if(b < _map.size() - 1) b++;

  // draw red or hue levels
  for(i = a; i <= b; i++) {
    x = index_to_x(i);
    if(!_map.hsv())
      intensity = _channel(i, 0);
    else {
      _channels(i, H, S, V);
      intensity = (int)(H / 6. * 255. + EPS);
    }
    y = intensity_to_y(intensity);
    if(i != a) {
      fl_color(FL_RED);
      fl_line(px, py, x, y);
    }
    px = x;
    py = y;
  }

  // draw green or saturation levels
  for(i = a; i <= b; i++) {
    x = index_to_x(i);
    if(!_map.hsv())
      intensity = _channel(i, 1);
    else {
      _channels(i, H, S, V);
      intensity = (int)(S * 255.);
    }
    y = intensity_to_y(intensity);
    if(i != a) {
      fl_color(FL_GREEN);
      fl_line(px, py, x, y);
    }
    px = x;
    py = y;
  }

  // draw blue or value levels
  for(i = a; i <= b; i++) {
    x = index_to_x(i);
    if(!_map.hsv())
      intensity = _channel(i, 2);
    else {
      _channels(i, H, S, V);
      intensity = (int)(V * 255.);
    }
    y = intensity_to_y(intensity);
    if(i != a) {
      fl_color(FL_BLUE);
      fl_line(px, py, x, y);
    }
    px = x;
    py = y;
  }

  // draw alpha levels
  for(i = a; i <= b; i++) {
    x = index_to_x(i);
    y = intensity_to_y(_map.colour(i).a);
    if(i != a) {
      fl_color(fl_contrast(FL_BLACK, color_bg));
      fl_line(px, py, x, y);
    }
    px = x;
    py = y;
  }

  // draw the color bar
  for(x = x1; x <= x2; x++) {
    i = x_to_index(x);
    Ui::Colour c = _map.colour(i);
    fl_color(c.r, c.g, c.b);
    fl_line(x, wedge_y, x, wedge_y + wedge_height - 1);
  }

  // print colortable mode and help
  fl_font(FL_HELVETICA, font_height);
  fl_color(fl_contrast(FL_BLACK, color_bg));

  int fh = font_height + 1;
  int xx0 = 6, xx1 = 11 * fh, yy0 = 6;
  if(_edit.help()) {
    const auto &keys = Ui::MapEditor::helpLines();
    for(std::size_t k = 0; k < keys.size(); k++) {
      fl_draw(keys[k].first.c_str(), xx0, yy0 + ((int)k + 1) * fh);
      fl_draw(keys[k].second.c_str(), xx1, yy0 + ((int)k + 1) * fh);
    }
  }
  else
    fl_draw(Ui::MapEditor::title(_map).c_str(), xx0, yy0 + font_height);
}

void colorbarWindow::redraw_marker()
{
  int x, y0, y1;

  y0 = marker_y;
  y1 = h() - 1;

  fl_color(color_bg);
  fl_rectf(0, y0, w(), y1 - y0 + 1);

  // draw marker below color wedge
  x = index_to_x(_edit.marker());
  fl_color(fl_contrast(FL_BLACK, color_bg));
  fl_line(x, marker_y, x, marker_y + marker_height);
  fl_line(x, marker_y, x - 3, marker_y + 6);
  fl_line(x, marker_y, x + 3, marker_y + 6);

  // draw marker value
  fl_font(FL_HELVETICA, font_height);
  fl_draw(Ui::MapEditor::markerText(_map, _edit.marker()).c_str(), 10, label_y);
}

void colorbarWindow::draw()
{
  if(_map.empty() || _map.size() < 2) return;

  label_y = h() - 5;
  marker_y = label_y - marker_height - font_height;
  wedge_y = marker_y - wedge_height;
  // over what is behind the model, not behind the interface
  Ui::Colour behind = fltkSources().settings().background;
  color_bg = fl_color_cube(behind.r * FL_NUM_RED / 256,
                           behind.g * FL_NUM_GREEN / 256,
                           behind.b * FL_NUM_BLUE / 256);
  redraw_range(0, _map.size() - 1);
  redraw_marker();
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

  int key = 0;
  unsigned mods = 0;

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
    if(_edit.press(_map, x_to_index(Fl::event_x()),
                   y_to_intensity(Fl::event_y()), button, mods,
                   Fl::event_y() >= wedge_y) == Ui::MapEditor::Changed)
      *viewchanged = true;
    redraw();
    return 1;
  }

  case FL_DRAG:
    if(_edit.drawing() &&
       _edit.drag(_map, x_to_index(Fl::event_x()),
                  y_to_intensity(Fl::event_y())) == Ui::MapEditor::Changed)
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
