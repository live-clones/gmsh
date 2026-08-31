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
#include "ColorTable.h"
#include "Context.h"

#define EPS 1.e-10

colorbarWindow::colorbarWindow(int x, int y, int w, int h, const char *l)
  : Fl_Window(x, y, w, h, l)
{
  label = nullptr;
  help_flag = 1;
  font_height = FL_NORMAL_SIZE - 1; // use slightly smaller font
  marker_height = font_height;
  wedge_height = marker_height;
  marker_pos = 0;
  minval = maxval = 0.0;
}

// what one channel of an entry is worth, red, green and blue or hue,
// saturation and value, which is what the four curves are drawn from
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
  int xx0 = 6, xx1 = 11 * fh, yy0 = 10;
  if(help_flag) {
    i = 0;
    fl_draw("0, 1, 2, 3, ..., 9", xx0, yy0 + (i + 1) * fh);
    fl_draw("Select predefined colormap 0...9", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("Ctrl+0, ..., Ctrl+9", xx0, yy0 + (i + 1) * fh);
    fl_draw("Select predefined colormap 10...19", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("F1, ..., F5", xx0, yy0 + (i + 1) * fh);
    fl_draw("Select predefined colormap 20...24", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("mouse1", xx0, yy0 + (i + 1) * fh);
    fl_draw("Draw red or hue channel", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("mouse2", xx0, yy0 + (i + 1) * fh);
    fl_draw("Draw green or saturation channel", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("mouse3", xx0, yy0 + (i + 1) * fh);
    fl_draw("Draw blue or value channel", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("Ctrl+mouse1", xx0, yy0 + (i + 1) * fh);
    fl_draw("Draw alpha channel", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("Ctrl+c, Ctrl+v, r", xx0, yy0 + (i + 1) * fh);
    fl_draw("Copy, paste or reset colormap", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("m", xx0, yy0 + (i + 1) * fh);
    fl_draw("Toggle RGB/HSV mode", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("left, right", xx0, yy0 + (i + 1) * fh);
    fl_draw("Translate abscissa", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("Ctrl+left, Ctrl+right", xx0, yy0 + (i + 1) * fh);
    fl_draw("Rotate abscissa", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("i, Ctrl+i", xx0, yy0 + (i + 1) * fh);
    fl_draw("Invert abscissa or ordinate", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("up, down", xx0, yy0 + (i + 1) * fh);
    fl_draw("Modify color channel curvature", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("a, Ctrl+a", xx0, yy0 + (i + 1) * fh);
    fl_draw("Modify alpha coefficient", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("p, Ctrl+p", xx0, yy0 + (i + 1) * fh);
    fl_draw("Modify alpha channel power law", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("b, Ctrl+b", xx0, yy0 + (i + 1) * fh);
    fl_draw("Modify gamma correction", xx1, yy0 + (i + 1) * fh);
    i++;
    fl_draw("h", xx0, yy0 + (i + 1) * fh);
    fl_draw("Show this help message", xx1, yy0 + (i + 1) * fh);
    i++;
  }
  else if(!_map.hsv())
    fl_draw("RGB", xx0, yy0 + font_height);
  else if(_map.hsv())
    fl_draw("HSV", xx0, yy0 + font_height);
}

void colorbarWindow::redraw_marker()
{
  int x, y0, y1;
  char str[50];
  double val;

  y0 = marker_y;
  y1 = h() - 1;

  fl_color(color_bg);
  fl_rectf(0, y0, w(), y1 - y0 + 1);

  // draw marker below color wedge
  x = index_to_x(marker_pos);
  fl_color(fl_contrast(FL_BLACK, color_bg));
  fl_line(x, marker_y, x, marker_y + marker_height);
  fl_line(x, marker_y, x - 3, marker_y + 6);
  fl_line(x, marker_y, x + 3, marker_y + 6);

  // draw marker value
  fl_font(FL_HELVETICA, font_height);
  val =
    minval + (maxval - minval) * ((double)marker_pos / (double)(_map.size() - 1));
  sprintf(str, "%g", val);
  fl_draw(str, 10, label_y);
}

void colorbarWindow::draw()
{
  if(_map.empty() || _map.size() < 2) return;

  label_y = h() - 5;
  marker_y = label_y - marker_height - font_height;
  wedge_y = marker_y - wedge_height;
  color_bg = fl_color_cube(
    CTX::instance()->unpackRed(CTX::instance()->color.bg) * FL_NUM_RED / 256,
    CTX::instance()->unpackGreen(CTX::instance()->color.bg) * FL_NUM_GREEN /
      256,
    CTX::instance()->unpackBlue(CTX::instance()->color.bg) * FL_NUM_BLUE / 256);
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

// One of the numbers the map is computed from, if the event is one of the keys
// the description gives them. Every key of this widget that changes a value is
// here rather than written out, so that what it does cannot come to differ
// from what another interface does with the same description.
bool colorbarWindow::_adjust()
{
  if(!_map.parameters) return false;
  std::vector<Ui::ColourMap::Parameter> ps = _map.parameters();
  for(std::size_t i = 0; i < ps.size(); i++) {
    if(_pressed(ps[i].up)) {
      _map.adjust(ps[i], true);
      return true;
    }
    if(!ps[i].down.empty() && _pressed(ps[i].down)) {
      _map.adjust(ps[i], false);
      return true;
    }
  }
  return false;
}

// what one of the shortcuts of a description is in the vocabulary of FLTK
bool colorbarWindow::_pressed(const Ui::Shortcut &s)
{
  if(s.empty()) return false;
  int key;
  switch(s.key) {
  case Ui::KeyLeft: key = FL_Left; break;
  case Ui::KeyRight: key = FL_Right; break;
  case Ui::KeyUp: key = FL_Up; break;
  case Ui::KeyDown: key = FL_Down; break;
  default:
    // a letter, which the keyboard reports in lower case
    key = (s.key >= 'A' && s.key <= 'Z') ? s.key - 'A' + 'a' : s.key;
    break;
  }
  int mods = 0;
  if(s.mods & Ui::ModShift) mods |= FL_SHIFT;
  if(s.mods & Ui::ModAlt) mods |= FL_ALT;
  if(s.mods & Ui::ModCommand)
    return Fl::test_shortcut(FL_CTRL + mods + key) ||
           Fl::test_shortcut(FL_META + mods + key);
  return Fl::test_shortcut(mods + key) ? true : false;
}

int colorbarWindow::handle(int event)
{
  if(_map.empty()) return Fl_Window::handle(event);

  static int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
  static int pentry, move_marker;
  int i, ibut, xpos, ypos, modify, entry, compute;
  // declared here rather than in the branch that uses them: a case label may
  // not be jumped over an initialisation
  int presets = 0, preset = -1;

  modify = 0;
  compute = 0;

  switch(event) {
  case FL_FOCUS: // accept focus events when asked
  case FL_UNFOCUS: return 1;

  case FL_ENTER:
    take_focus(); // force keyboard focus as soon as the mouse enters
    return 1;

  case FL_LEAVE: return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // The presets, which the digits, the digits with Control and the first
    // five function keys reach, in that order.
    presets = _map.numPresets ? _map.numPresets() : 0;
    for(int k = 0; k <= 9; k++) {
      if(Fl::test_shortcut('0' + k)) preset = k;
      if(Fl::test_shortcut(FL_CTRL + '0' + k) ||
         Fl::test_shortcut(FL_META + '0' + k))
        preset = k + 10;
    }
    for(int k = 0; k < 5; k++)
      if(Fl::test_shortcut(FL_F + 1 + k)) preset = k + 20;
    if(preset >= 0 && preset < presets) {
      _map.choosePreset(preset);
      compute = 1;
    }
    else if(Fl::test_shortcut(FL_CTRL + 'c') ||
            Fl::test_shortcut(FL_META + 'c')) {
      if(_map.copy) _map.copy();
    }
    else if(Fl::test_shortcut(FL_CTRL + 'v') ||
            Fl::test_shortcut(FL_META + 'v')) {
      if(_map.paste) _map.paste();
      redraw();
      *viewchanged = true;
    }
    else if(Fl::test_shortcut('h')) {
      help_flag = !help_flag;
      redraw();
    }
    else if(Fl::test_shortcut('r')) {
      // back to the one it is on, not to the first
      if(_map.preset) _map.choosePreset(_map.preset());
      compute = 1;
    }
    else if(Fl::test_shortcut('m')) {
      _map.setHsv(!_map.hsv());
      redraw();
    }
    else if(_adjust()) {
      // one of the numbers the map is computed from; setting it recomputes,
      // so there is nothing more to do than draw it again
      redraw();
      *viewchanged = true;
      do_callback();
      return 1;
    }
    else {
      return Fl_Window::handle(event);
    }

    if(compute) {
      redraw();
      *viewchanged = true;
      do_callback();
    }
    return 1;

  case FL_PUSH:
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();
    if(help_flag) {
      help_flag = 0;
      redraw();
    }
    // change color function or marker position
    if(ypos < wedge_y)
      move_marker = 0;
    else
      move_marker = 1;

    // determine which curve to modify
    if(Fl::event_state(FL_CTRL) || Fl::event_state(FL_META))
      p4 = 1;
    else if(ibut == 1 && !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT))
      p1 = 1;
    else if(ibut == 2 || (ibut == 1 && Fl::event_state(FL_SHIFT)))
      p2 = 1;
    else
      p3 = 1;
    pentry = x_to_index(xpos);
    modify = 1;
    break;

  case FL_RELEASE:
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    if(*viewchanged) do_callback();
    break;

  case FL_DRAG:
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();
    modify = 1;
    break;

  default:
    // don't know what to do with the event: passing it to parent
    return Fl_Window::handle(event);
  }

  // Modify one or more of the color curves

  if(modify && (p1 || p2 || p3 || p4)) {
    // calculate which entry in color table to change
    entry = x_to_index(xpos);
    // update
    if(move_marker) {
      // changing marker position
      marker_pos = entry;
    }
    else {
      // changing color graph
      int a, b, value;
      value = y_to_intensity(ypos);
      if(pentry <= entry) {
        a = pentry;
        b = entry;
      }
      else {
        a = entry;
        b = pentry;
      }
      // update entries from 'pentry' to 'entry'
      for(i = a; i <= b; i++) {
        Ui::Colour c = _map.colour(i);
        if(!_map.hsv()) {
          if(p1) c.r = (unsigned char)value;
          if(p2) c.g = (unsigned char)value;
          if(p3) c.b = (unsigned char)value;
          if(p4) c.a = (unsigned char)value;
        }
        else {
          int H, S, V;
          Ui::toHsv(c, H, S, V);
          if(p1) H = value;
          if(p2) S = value;
          if(p3) V = value;
          unsigned char alpha = p4 ? (unsigned char)value : c.a;
          c = Ui::fromHsv(H, S, V, alpha);
        }
        _map.setColour(i, c);
      }
      pentry = entry;
      *viewchanged = true;
    }
    redraw();
    return 1;
  }

  return 1;
}
