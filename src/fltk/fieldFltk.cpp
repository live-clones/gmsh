// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The widgets of a field: the one a line of the tree carries, and those of the
// forms FLTK has no widget for -- a number with the decimals of its step, a
// point on the unit sphere, a colour map. Each is bound to the place its value
// lives, which is what the description gives.

#include "GmshConfig.h"

#include <deque>
#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Input.H>

#include <FL/fl_draw.H>

#include <cmath>

#include "fltkCommon.h"

namespace {

  // a widget is given a pointer when it calls back: the field has to outlive
  // the line
  std::deque<Ui::Field> _bound;
  std::deque<std::string> _labels;
  std::deque<Ui::Button> _buttons;

  Ui::Field *_field(void *data) { return (Ui::Field *)data; }

  void _numberChanged(Fl_Widget *w, void *data)
  {
    _field(data)->setNumber(((Fl_Value_Input *)w)->value());
    if(_field(data)->changed) _field(data)->changed();
  }

  void _flagChanged(Fl_Widget *w, void *data)
  {
    _field(data)->setFlag(((Fl_Button *)w)->value() ? true : false);
    if(_field(data)->changed) _field(data)->changed();
  }

  void _choiceChanged(Fl_Widget *w, void *data)
  {
    _field(data)->setNumber(((Fl_Choice *)w)->value());
    if(_field(data)->changed) _field(data)->changed();
  }

  void _textChanged(Fl_Widget *w, void *data)
  {
    Fl_Input_Choice *c = dynamic_cast<Fl_Input_Choice *>(w);
    _field(data)->setText(c ? c->value() : ((Fl_Input *)w)->value());
    if(_field(data)->changed) _field(data)->changed();
  }

  void _pressed(Fl_Widget *w, void *data)
  {
    if(_field(data)->changed) _field(data)->changed();
  }

  void _buttonPressed(Fl_Widget *w, void *data)
  {
    Ui::Button *b = (Ui::Button *)data;
    if(b->action) b->action();
  }

  void _buttonMenu(Fl_Widget *w, void *data)
  {
    Ui::Button *b = (Ui::Button *)data;
    if(!b->menu) return;
    fltkPopupMenu(b->menu(), Fl::event_x_root(), Fl::event_y_root(), "tree");
  }

  const char *_keep(const std::string &say)
  {
    _labels.push_back(say);
    return _labels.back().c_str();
  }

} // namespace

void fltkForgetTreeFields()
{
  _bound.clear();
  _labels.clear();
  _buttons.clear();
}

Fl_Group *fltkTreeField(const Ui::Field &f, int x, int y, int w, int h,
                        double labelRatio, const Ui::Colour &highlight,
                        Fl_Color background)
{
  // a switch and a button take the whole line; the rest the share labelRatio
  // gives
  bool nameInside = f.kind == Ui::Check || f.kind == Ui::Action;
  int lineW = nameInside ? w : (int)(w * labelRatio);
  Fl_Group *line = new Fl_Group(x, y, lineW, h);
  _bound.push_back(f);
  Ui::Field *bound = &_bound.back();

  // a narrow one for the range, two wider for the loop and the plots
  int room = 0;
  std::vector<int> widths;
  for(const auto &b : f.trailing) {
    int wide = b.label == ":" ? FL_NORMAL_SIZE - 2 : FL_NORMAL_SIZE + 6;
    widths.push_back(wide);
    room += wide;
  }
  int valueW = lineW - room;
  if(valueW < FL_NORMAL_SIZE) valueW = FL_NORMAL_SIZE;

  Fl_Widget *widget = nullptr;
  switch(f.kind) {
  case Ui::Choice: {
    Fl_Choice *c = new Fl_Choice(x, y, valueW, h);
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    for(auto &l : labels) c->add(_keep(l), 0, nullptr, nullptr, 0);
    c->value((int)f.getNumber());
    c->callback(_choiceChanged, bound);
    widget = c;
  } break;
  case Ui::Check: {
    Fl_Check_Button *b = new Fl_Check_Button(x, y, valueW, h);
    b->box(FL_FLAT_BOX);
    b->color(background);
    b->value(f.getFlag() ? 1 : 0);
    b->callback(_flagChanged, bound);
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    widget = b;
  } break;
  case Ui::Action: {
    Fl_Button *b = new Fl_Button(x, y, valueW, h);
    b->box(FL_FLAT_BOX);
    b->color(background);
    b->selection_color(background);
    b->callback(_pressed, bound);
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    widget = b;
  } break;
  case Ui::Output: {
    Fl_Output *o = new Fl_Output(x, y, valueW, h);
    o->value(f.getText().c_str());
    widget = o;
  } break;
  case Ui::Number:
  case Ui::Integer: {
    Fl_Value_Input *v = new numberFltk(x, y, valueW, h);
    if(f.maximum > f.minimum) {
      v->minimum(f.minimum);
      v->maximum(f.maximum);
    }
    if(f.step > 0. && fltkSources().settings().inputScrolling)
      v->step(f.step);
    v->value(f.getNumber());
    v->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
    v->callback(_numberChanged, bound);
    widget = v;
  } break;
  default: {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    if(labels.size()) {
      Fl_Input_Choice *c = new Fl_Input_Choice(x, y, valueW, h);
      for(auto &l : labels) c->add(_keep(l));
      c->value(f.getText().c_str());
      c->input()->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      c->callback(_textChanged, bound);
      widget = c;
    }
    else {
      Fl_Input *in = new Fl_Input(x, y, valueW, h);
      in->value(f.getText().c_str());
      in->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      in->callback(_textChanged, bound);
      widget = in;
    }
  } break;
  }

  // the little buttons sit between the widget and its name
  if(f.label.size()) {
    if(nameInside)
      widget->copy_label(f.label.c_str());
    else
      line->copy_label(f.label.c_str());
  }
  if(!nameInside) line->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
  if(highlight.a) {
    Fl_Color paint = fl_rgb_color(highlight.r, highlight.g, highlight.b);
    widget->color(paint);
    widget->labelcolor(fl_contrast(FL_FOREGROUND_COLOR, paint));
  }
  if(f.enabled && !f.enabled()) widget->deactivate();

  int at = x + valueW;
  for(std::size_t i = 0; i < f.trailing.size(); i++) {
    _buttons.push_back(f.trailing[i]);
    Ui::Button *b = &_buttons.back();
    Fl_Button *button = new Fl_Button(at, y, widths[i], h);
    at += widths[i];
    // the picture, for the two that have one, in the way FLTK draws a symbol
    if(b->glyph.size())
      button->copy_label(("@-1gmsh_" + b->glyph).c_str());
    else if(b->label.size())
      button->copy_label(b->label.c_str());
    else if(b->menu)
      // one that only drops a list says so with the arrow FLTK draws on a
      // menu button
      button->copy_label("@2>");
    if(b->tooltip.size()) button->copy_tooltip(b->tooltip.c_str());
    if(b->menu)
      button->callback(_buttonMenu, b);
    else
      button->callback(_buttonPressed, b);
    if(b->on && b->on()) button->color(FL_GREEN);
  }

  line->end();
  line->resizable(nullptr);
  return line;
}

// --- a point on the unit sphere

discFltk::discFltk(int x, int y, int w, const char *l)
  : Fl_Widget(x, y, w, w, l), _x(0.), _y(0.), _z(0.)
{
  box(FL_FLAT_BOX);
  align(FL_ALIGN_BOTTOM);
}

void discFltk::draw()
{
  draw_box(box(), color());
  int x1 = x() + 3;
  int y1 = y() + 3;
  int w1 = w() - 6;
  int h1 = h() - 6;
  fl_color(FL_FOREGROUND_COLOR);
  fl_arc(x1, y1, w1, h1, 0, 360);
  int px = int(x1 + 0.5 * w1 * (1 + _x));
  int py = int(y1 + 0.5 * h1 * (1 - _y));
  draw_box(FL_UP_BOX, px - 3, py - 3, 6, 6, FL_FOREGROUND_COLOR);
}

int discFltk::handle(int event)
{
  switch(event) {
  case FL_PUSH:
  case FL_DRAG:
  case FL_RELEASE: {
    int x1 = x() + 3;
    int y1 = y() + 3;
    int w1 = w() - 6;
    int h1 = h() - 6;
    double xx = (Fl::event_x() - x1) / (0.5 * w1) - 1.;
    double yy = -((Fl::event_y() - y1) / (0.5 * h1) - 1.);
    if(xx != _x || yy != _y) {
      double norm = sqrt(xx * xx + yy * yy);
      if(norm > 1.) {
        xx /= norm;
        yy /= norm;
        norm = 1.;
      }
      _x = xx;
      _y = yy;
      _z = sqrt(1. - norm);
      set_changed();
      redraw();
      do_callback();
    }
  }
    return 1;
  default: return 0;
  }
}

void discFltk::getValue(double &x, double &y, double &z) const
{
  x = _x;
  y = _y;
  z = _z;
}

void discFltk::setValue(double x, double y, double z)
{
  double norm = sqrt(x * x + y * y + z * z);
  if(norm) {
    _x = x / norm;
    _y = y / norm;
    _z = z / norm;
  }
  else {
    _x = _y = _z = 0.;
  }
  redraw();
}

// --- a colour map, inspired by the colorbar widget of Vis5d, a program for
// visualizing five dimensional gridded data sets (Copyright (C) 1990 - 1995
// Bill Hibbard, Brian Paul, Dave Santek, and Andre Battaiola)

namespace {
  // slightly smaller than the rest
  int _line() { return FL_NORMAL_SIZE - 1; }
} // namespace

colourMapFltk::colourMapFltk(int x, int y, int w, int h, const char *l)
  : Fl_Window(x, y, w, h, l), _min(0.), _max(0.), _changed(nullptr)
{
}

// the entry, the intensity and the part of the picture under x, y
void colourMapFltk::_at(int x, int y, int &entry, int &value, bool &onWedge)
{
  Ui::MapEditor::at(_map, x, y, w(), h(), _line(), entry, value, onWedge);
}

// what Ui::MapEditor::picture() says, drawn over what is behind the model,
// as master has it
void colourMapFltk::draw()
{
  if(_map.empty() || _map.size() < 2) return;
  Ui::Colour behind = fltkSources().settings().background;
  Fl_Color back = fl_color_cube(behind.r * FL_NUM_RED / 256,
                           behind.g * FL_NUM_GREEN / 256,
                           behind.b * FL_NUM_BLUE / 256);
  Fl_Color ink = fl_contrast(FL_BLACK, back);
  fl_color(back);
  fl_rectf(0, 0, w(), h());
  Ui::MapEditor::Picture pic = _edit.picture(_map, w(), h(), _line());
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
    fl_font(FL_HELVETICA, std::max(1, (int)(_line() * x.scale)));
    int left = (int)(x.right ? x.x - fl_width(x.text.c_str()) : x.x);
    fl_draw(x.text.c_str(), left, (int)x.y + fl_height() - fl_descent());
  }
}

void colourMapFltk::update(const char *name, double min, double max,
                            const Ui::ColourMap &map, bool *changed)
{
  _name = name ? name : "";
  _map = map;
  _changed = changed;
  _min = min;
  _max = max;
  redraw();
}

int colourMapFltk::handle(int event)
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
    if(!fltkUiKey(key, mods)) return Fl_Window::handle(event);
    switch(_edit.key(_map, key, mods)) {
    case Ui::MapEditor::NotMine: return Fl_Window::handle(event);
    case Ui::MapEditor::Redraw: redraw(); return 1;
    case Ui::MapEditor::Changed:
      redraw();
      *_changed = true;
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
      *_changed = true;
    redraw();
    return 1;
  }

  case FL_DRAG:
    _at(Fl::event_x(), Fl::event_y(), entry, value, onWedge);
    if(_edit.drawing() &&
       _edit.drag(_map, entry, value) == Ui::MapEditor::Changed)
      *_changed = true;
    redraw();
    return 1;

  case FL_RELEASE:
    _edit.release();
    if(*_changed) do_callback();
    return 1;

  default:
    // don't know what to do with the event: passing it to parent
    return Fl_Window::handle(event);
  }
}
