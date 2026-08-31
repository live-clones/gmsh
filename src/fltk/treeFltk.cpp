// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

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

#include "treeFltk.h"
#include "menuFltk.h"
#include "Context.h"

namespace {

  // What each widget of the tree is bound to. A widget is given a pointer
  // when it calls back, so the field has to outlive the line; a deque keeps
  // the addresses steady as more are added.
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
    fltkMenuPopup(b->menu(), Fl::event_x_root(), Fl::event_y_root(), "tree");
  }

  // the label FLTK is to draw, kept because a widget holds the pointer
  const char *_keep(const std::string &say)
  {
    _labels.push_back(say);
    return _labels.back().c_str();
  }

} // namespace

void fltkTreeForget()
{
  _bound.clear();
  _labels.clear();
  _buttons.clear();
}

Fl_Group *fltkTreeField(const Ui::Field &f, int x, int y, int w, int h,
                        double labelRatio, unsigned int highlight,
                        Fl_Color background)
{
  // A switch and a button carry their name inside themselves and take the
  // whole line; everything else takes the share labelRatio gives it and has
  // its name written to the right of it, which is where the group ends.
  bool nameInside = f.kind == Ui::Check || f.kind == Ui::Action;
  int lineW = nameInside ? w : (int)(w * labelRatio);
  Fl_Group *line = new Fl_Group(x, y, lineW, h);
  _bound.push_back(f);
  Ui::Field *bound = &_bound.back();

  // the little buttons take their width from the font, as the widget this
  // reproduces gives them: a narrow one for the range, two wider ones for the
  // loop and the plots
  int room = 0;
  std::vector<int> widths;
  for(const auto &b : f.trailing) {
    int wide = b.label == ":" ? FL_NORMAL_SIZE - 2 : FL_NORMAL_SIZE + 6;
    widths.push_back(wide);
    room += wide;
  }
  // the value takes the share of the line the tree gives it and its name has
  // the rest, which is what the widget this reproduces does
  int valueW = lineW - room;
  if(valueW < FL_NORMAL_SIZE) valueW = FL_NORMAL_SIZE;

  Fl_Widget *widget = nullptr;
  switch(f.kind) {
  case Ui::Choice: {
    Fl_Choice *c = new Fl_Choice(x, y, valueW, h);
    std::vector<std::string> labels;
    std::vector<int> values;
    if(f.dynamicChoices) f.dynamicChoices(labels, values);
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
    Fl_Value_Input *v = new Fl_Value_Input(x, y, valueW, h);
    if(f.maximum > f.minimum) {
      v->minimum(f.minimum);
      v->maximum(f.maximum);
    }
    if(f.step > 0. && CTX::instance()->inputScrolling) v->step(f.step);
    v->value(f.getNumber());
    v->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
    v->callback(_numberChanged, bound);
    widget = v;
  } break;
  default: {
    // words, with what one may want to type behind a little arrow when the
    // description says what that is
    std::vector<std::string> labels;
    std::vector<int> values;
    if(f.dynamicChoices) f.dynamicChoices(labels, values);
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

  // The name goes on the line rather than on the widget: the little buttons
  // sit between them, and a name belonging to the widget would be drawn under
  // them.
  if(f.label.size()) {
    if(nameInside)
      widget->copy_label(f.label.c_str());
    else
      line->copy_label(f.label.c_str());
  }
  if(!nameInside) line->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
  if(highlight) {
    CTX *c = CTX::instance();
    Fl_Color paint = fl_rgb_color(c->unpackRed(highlight),
                                  c->unpackGreen(highlight),
                                  c->unpackBlue(highlight));
    widget->color(paint);
    widget->labelcolor(fl_contrast(FL_FOREGROUND_COLOR, paint));
  }
  if(f.enabled && !f.enabled()) widget->deactivate();

  // and the little buttons after it
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

#endif
