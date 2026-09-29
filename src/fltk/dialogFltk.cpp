// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "uiSources.h"
#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <map>
#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H> // fl_font, fl_width

#include "spherePositionWidget.h"
#include "colorbarWindow.h"
#include <FL/Fl_Tree.H>
#include "Tree.h"
#include "Layout.h"
#include "dialogFltk.h"
#include "menuFltk.h"
#include "fltkMetrics.h"
#include "paletteWindow.h"

// while the interface is taken down a dialog that undoes something when it
// closes must not: there is no view left to draw into
static bool _closingDown = false;

void fltkDialogsClosingDown() { _closingDown = true; }

// FLTK calls the callback of a window only when the user closes it
class dialogWindow : public paletteWindow {
public:
  std::function<void()> closed;
  dialogWindow(int w, int h, bool nonModal, const char *l = nullptr)
    : paletteWindow(w, h, nonModal, l)
  {
  }
  int handle(int event) override
  {
    if(event == FL_HIDE && closed && !_closingDown) closed();
    return paletteWindow::handle(event);
  }
};

namespace {
  // tabs wider than their window drop the rest in a menu, where FLTK can:
  // the snapshots of 1.4 before 1.4.0 say 10400 without handle_overflow()
  template <class T>
  auto _overflowsInMenu(T *tabs, int)
    -> decltype(tabs->handle_overflow(T::OVERFLOW_PULLDOWN), void())
  {
    tabs->handle_overflow(T::OVERFLOW_PULLDOWN);
  }
  template <class T> void _overflowsInMenu(T *, long) {}
  void _overflowsInMenu(Fl_Tabs *tabs) { _overflowsInMenu(tabs, 0); }

  Ui::Metrics _metrics();

  // FLTK reads "&" in a label as a shortcut mark, in the menus, the buttons and
  // the inputs only
  std::string _escaped(const std::string &label);
  const std::string &_plain(const std::string &label) { return label; }

  std::string _escaped(const std::string &label)
  {
    std::string out;
    for(char c : label) {
      out += c;
      if(c == '&') out += c;
    }
    return out;
  }

  // "/" opens a submenu, "\\" escapes the next character
  std::string _escapedMenu(const std::string &label)
  {
    std::string out;
    for(char c : label) {
      if(c == '&' || c == '/' || c == '\\') out += '\\';
      out += c;
    }
    return out;
  }

  // a choice gets the same width as an input rather than that of its longest
  // entry, so that the labels line up
  struct proseSpot {
    int x, y, w, h;
    std::function<void()> follow;
  };

  // measuring and drawing a page of prose are the same walk; by hand rather
  // than through an Fl_Help_View, which cannot be given its page before its
  // window is shown
  int _layProse(const std::vector<Ui::Line> &page, int x, int y, int w,
                bool paint, std::vector<proseSpot> *spots)
  {
    if(spots) spots->clear();
    // the room about it is that of its line
    const int margin = 0;
    const int left = x + margin, right = x + w - margin;
    int at = y + margin;
    struct piece {
      std::string text;
      Fl_Font font;
      int size;
      bool link;
      int width;
      std::function<void()> follow;
    };
    for(const Ui::Line &l : page) {
      int size = l.heading ? FL_NORMAL_SIZE + 6 : FL_NORMAL_SIZE;
      int indent = l.bullet ? 2 * WB : 0;
      fl_font(FL_HELVETICA, size);
      int lead = fl_height();
      if(l.words.empty()) {
        at += lead;
        continue;
      }
      int room = right - left - indent;
      std::vector<piece> row;
      int rowWidth = 0;
      bool first = true;
      auto flush = [&]() {
        if(row.empty()) return;
        int put = l.centred ? left + indent + (room - rowWidth) / 2 :
                              left + indent;
        if(paint && first && l.bullet) {
          fl_font(FL_HELVETICA, size);
          fl_color(FL_FOREGROUND_COLOR);
          fl_draw("\xe2\x80\xa2", left, at + fl_height() - fl_descent());
        }
        for(const piece &q : row) {
          if(paint) {
            fl_font(q.font, q.size);
            fl_color(q.link ? FL_BLUE : FL_FOREGROUND_COLOR);
            int base = at + fl_height() - fl_descent();
            fl_draw(q.text.c_str(), put, base);
            if(q.link) fl_line(put, base + 1, put + q.width, base + 1);
          }
          if(q.follow && spots)
            spots->push_back({put, at, q.width, lead, q.follow});
          put += q.width;
        }
        at += lead;
        row.clear();
        rowWidth = 0;
        first = false;
      };
      for(const Ui::Words &word : l.words) {
        Fl_Font font = l.heading ? FL_HELVETICA_BOLD :
                       word.italic ? FL_HELVETICA_ITALIC :
                                     FL_HELVETICA;
        fl_font(font, size);
        std::string held;
        std::size_t i = 0;
        while(i < word.text.size()) {
          std::size_t j = word.text.find(' ', i);
          std::string next =
            word.text.substr(i, j == std::string::npos ? j : j - i + 1);
          int wide = (int)fl_width((held + next).c_str());
          if(rowWidth + wide > room && (rowWidth || held.size())) {
            if(held.size()) {
              row.push_back({held, font, size, (bool)word.follow,
                             (int)fl_width(held.c_str()), word.follow});
              rowWidth += (int)fl_width(held.c_str());
              held.clear();
            }
            flush();
            fl_font(font, size);
            while(next.size() && next[0] == ' ') next = next.substr(1);
          }
          held += next;
          if(j == std::string::npos) break;
          i = j + 1;
        }
        if(held.size()) {
          fl_font(font, size);
          int wide = (int)fl_width(held.c_str());
          row.push_back({held, font, size, (bool)word.follow, wide,
                         word.follow});
          rowWidth += wide;
        }
      }
      flush();
    }
    return at - y + margin;
  }

  class proseView : public Fl_Widget {
  public:
    std::vector<Ui::Line> page;
    std::vector<proseSpot> spots;
    // on the colour of the window, as in the other interfaces
    proseView(int x, int y, int w, int h) : Fl_Widget(x, y, w, h)
    {
      box(FL_FLAT_BOX);
      color(FL_BACKGROUND_COLOR);
    }
    void draw() override
    {
      draw_box();
      _layProse(page, x(), y(), w(), true, &spots);
    }
    int handle(int event) override
    {
      if(event == FL_PUSH) {
        for(const auto &s : spots)
          if(Fl::event_x() >= s.x && Fl::event_x() < s.x + s.w &&
             Fl::event_y() >= s.y && Fl::event_y() < s.y + s.h) {
            if(s.follow) s.follow();
            return 1;
          }
      }
      return Fl_Widget::handle(event);
    }
  };

  const double _linePad = .15;

  // a line of widgets and the room about it are as tall as a button of the
  // released Gmsh, the widgets touching
  int _rowH()
  { return BH - 2 * (int)std::floor(_linePad * FL_NORMAL_SIZE + .5); }

  // in em of the font; the numbers of the page's stylesheet, at its font
  Ui::Metrics _metrics()
  {
    const double em = FL_NORMAL_SIZE;
    const int RH = _rowH();
    Ui::Metrics m;
    m.field = IW / em;
    m.row = RH / em;
    m.line = (FL_NORMAL_SIZE + 5) / em;
    m.gap = .6;
    m.cellGap = .45;
    m.linePad = _linePad;
    m.gridRowGap = .3;
    m.rule = .7;
    m.tabBar = BH / em;
    m.tab = .9;
    m.tabPad = WB / em;
    m.scrollbar = Fl::scrollbar_size() / em;
    // a box FLTK writes a name on keeps three pixels at each end
    m.textWidth = [em](const std::string &s) {
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      return (fl_width(_escaped(s).c_str()) + 6) / em;
    };
    m.widget = [em, RH](const Ui::Field &f) -> Ui::Size {
      fl_font(f.heading ? FL_HELVETICA_BOLD : FL_HELVETICA, FL_NORMAL_SIZE);
      double text = fl_width(_escaped(f.label).c_str()) / em;
      switch(f.kind) {
      case Ui::Check:
        return Ui::Size(text + (f.disclosure ? 2.5 : 1.8), RH / em);
      // never narrower than an ordinary button; Fl_Return_Button writes its
      // name beside an arrow as wide as the button is tall, less four pixels
      case Ui::Action:
        if(f.isDefault) text += (RH - 4) / em;
        return Ui::Size(std::max(text + 2., BB / em), RH / em);
      case Ui::Menu: return Ui::Size(text + 3.2, RH / em);
      case Ui::Choice:
        if(f.multiple) return Ui::Size(text + 3.2, RH / em);
        break;
      case Ui::Label:
        return Ui::Size(fl_width(f.getText().c_str()) / em + WB / em, RH / em);
      case Ui::Color: return Ui::Size(3., RH / em);
      default: break;
      }
      return Ui::Size(-1., RH / em);
    };
    m.proseHeight = [em, RH](const Ui::Field &f, double width) -> double {
      if(!f.prose) return RH / em;
      return _layProse(f.prose(), 0, 0, (int)(width * em), false, nullptr) /
             em;
    };
    return m;
  }

  // what the window is made of: the dialog is only built again when this
  // changes
  void _sign(const Ui::Item &it, std::string &s)
  {
    switch(it.kind) {
    case Ui::Item::AField:
      s += "/" + it.field.label + (char)('0' + it.field.kind);
      break;
    case Ui::Item::ABox:
      s += it.box->direction == Ui::Box::Down ? "|v" : "|h";
      for(const auto &i : it.box->items) _sign(i, s);
      s += "|.";
      break;
    case Ui::Item::ATabs:
      s += "|t";
      for(const auto &t : it.tabs->tabs) {
        s += "|" + t.first;
        _sign(t.second, s);
      }
      s += "|.";
      break;
    case Ui::Item::AHeading: s += "|=" + it.text; break;
    case Ui::Item::ARule: s += "|_"; break;
    default: break;
    }
  }

  std::string _signature(const Ui::Form &p)
  {
    std::string s = p.title;
    _sign(p.content, s);
    return s;
  }

  // a drag, the wheel, a letter typed are steps of the choosing; Enter, the
  // button let go or the field left end it
  bool _choosingEnds()
  {
    switch(Fl::event()) {
    case FL_DRAG:
    case FL_MOUSEWHEEL:
    case FL_PASTE: return false;
    case FL_KEYBOARD:
      return Fl::event_key() == FL_Enter || Fl::event_key() == FL_KP_Enter;
    default: return true;
    }
  }

} // namespace

dialogFltk::~dialogFltk()
{
  if(_win) Fl::delete_widget(_win);
}

void dialogFltk::_fieldCallback(Fl_Widget *w, void *data)
{
  dialogFltk *d = (dialogFltk *)data;
  for(auto &b : d->_fields) {
    if(b.widget != w) continue;
    // a copy: what the field does may build the dialog again, ending the list
    // this walks
    Ui::Field f = b.field;
    switch(f.kind) {
    case Ui::Text:
      if(Fl_Input_Choice *c = dynamic_cast<Fl_Input_Choice *>(w))
        f.setText(c->value() ? c->value() : "");
      else
        f.setText(((Fl_Input *)w)->value());
      break;
    case Ui::Integer:
    case Ui::Number:
      f.setNumber(((Fl_Valuator *)w)->value());
      break;
    case Ui::Check:
      f.setFlag(((Fl_Button *)w)->value() ? true : false);
      break;
    case Ui::Color: {
      Ui::Colour c = f.getColour();
      uchar r = c.r, g = c.g, b = c.b;
      if(fl_color_chooser("Color Chooser", r, g, b))
        f.setColour(Ui::Colour(r, g, b, c.a));
    } break;
    case Ui::Direction: {
      double x = 0., y = 0., z = 0.;
      ((spherePositionWidget *)w)->getValue(x, y, z);
      f.setVector(x, y, z);
    } break;
    case Ui::Hierarchy: {
      // which line, by where it is in the list the description gave
      Fl_Tree *tree = (Fl_Tree *)w;
      Fl_Tree_Item *item = (Fl_Tree_Item *)tree->callback_item();
      if(!item || !f.hierarchy) break;
      const std::string *path = (const std::string *)item->user_data();
      if(!path) break;
      Ui::Node node = f.hierarchy->node(*path);
      if(!node.pick) break;
      if(tree->callback_reason() == FL_TREE_REASON_SELECTED)
        node.pick(true);
      else if(tree->callback_reason() == FL_TREE_REASON_DESELECTED)
        node.pick(false);
    } break;
    case Ui::ColorMap: break; // it edits the table itself
    case Ui::Menu: {
      Fl_Menu_Button *m = (Fl_Menu_Button *)w;
      const Fl_Menu_Item *item = m->mvalue();
      if(item && f.choose)
        for(int k = 0; k < m->size() - 1; k++)
          if(&m->menu()[k] == item) f.choose(k, true);
    } break;
    case Ui::Label:
    case Ui::Prose:
    case Ui::Output:
    case Ui::Action:
    case Ui::Spacer: break;
    case Ui::List: {
      Fl_Browser *br = (Fl_Browser *)w;
      if(f.choose) {
        for(int line = 1; line <= br->size(); line++)
          f.choose(line - 1, br->selected(line) ? true : false);
      }
      else {
        // a line one clicks is one to be rid of
        int line = br->value();
        if(line > 0 && f.removeItem) f.removeItem(line - 1);
      }
    } break;
    case Ui::Choice: {
      if(f.multiple) {
        Fl_Menu_Button *m = (Fl_Menu_Button *)w;
        const Fl_Menu_Item *item = m->mvalue();
        if(item && f.choose) {
          for(int k = 0; k < m->size() - 1; k++)
            if(&m->menu()[k] == item) f.choose(k, item->value() ? true : false);
        }
        break;
      }
      int i = ((Fl_Choice *)w)->value();
      std::vector<std::string> labels;
      std::vector<int> values;
      if(f.dynamicChoices)
        f.dynamicChoices(labels, values);
      else {
        labels = f.choices;
        values = f.values;
      }
      if(i >= 0 && i < (int)labels.size()) {
        if(values.empty())
          f.setText(labels[i]);
        else if(i < (int)values.size())
          f.setNumber(values[i]);
      }
    } break;
    }
    if(f.done && _choosingEnds())
      f.done();
    else if(f.changed)
      f.changed();
    break;
  }
  d->reshape();
}

// the description must follow the tab clicked, or the next refresh puts the
// pane it remembers back
struct buttonAction {
  dialogFltk *dialog;
  std::function<void()> what;
};

void dialogFltk::_buttonCallback(Fl_Widget *w, void *data)
{
  buttonAction *a = (buttonAction *)data;
  if(!a) return;
  if(a->what) a->what();
  if(a->dialog) a->dialog->reshape();
}

namespace {

  // with the decimals of its step, unless it is off the grid of the step (1e-6
  // on a step of 1e-4): then as it is set
  class valueInput : public Fl_Value_Input {
  public:
    valueInput(int x, int y, int w, int h) : Fl_Value_Input(x, y, w, h) {}
    int format(char *buffer) override
    {
      int n = Fl_Value_Input::format(buffer);
      double v = value();
      if(v != 0. && std::fabs(atof(buffer) - v) > 1e-9 * std::fabs(v))
        return snprintf(buffer, 128, "%g", v);
      return n;
    }
  };

  // kept while the widgets that point at them are alive: FLTK hands a widget a
  // void*
  std::deque<Ui::Button> &_kept()
  {
    static std::deque<Ui::Button> kept;
    return kept;
  }

  void _trailingPressed(Fl_Widget *w, void *data)
  {
    Ui::Button *b = (Ui::Button *)data;
    if(b->action) b->action();
  }

  void _trailingMenu(Fl_Widget *w, void *data)
  {
    Ui::Button *b = (Ui::Button *)data;
    if(b->menu)
      fltkMenuPopup(b->menu(), Fl::event_x_root(), Fl::event_y_root(),
                    "field");
  }

} // namespace

// the widgets of one placed field, in the group it is placed in; where they
// go is _place()'s
void dialogFltk::_addItem(std::size_t index, Fl_Group *into)
{
  const int RH = _rowH();
  const Ui::PlacedItem &p = _placed[index];
  const double em = FL_NORMAL_SIZE;
  auto px = [em](double v) { return (int)std::floor(v * em + 0.5); };
  const Ui::Field &f = p.field;
  int fx = WB + px(p.box.x), fy = WB + px(p.box.y);
  int fieldW = px(p.box.w), fieldH = px(p.box.h);
  Fl_Widget *widget = nullptr;
  switch(f.kind) {
  case Ui::Text:
    if(f.dynamicChoices) {
      Fl_Input_Choice *c = new Fl_Input_Choice(fx, fy, fieldW, RH);
      // picking from the menu goes through the group
      c->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      if(f.commitsWhenDone)
        c->input()->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      widget = c;
    }
    else {
      Fl_Input *in = new Fl_Input(fx, fy, fieldW, RH);
      in->when(f.commitsWhenDone ? (FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY) :
                                   FL_WHEN_CHANGED);
      widget = in;
    }
    break;
  case Ui::Integer:
  case Ui::Number: {
    if(f.slider && f.maximum > f.minimum) {
      Fl_Value_Slider *v = new Fl_Value_Slider(fx, fy, fieldW, RH);
      v->type(FL_HOR_SLIDER);
      v->textsize(FL_NORMAL_SIZE);
      v->bounds(f.minimum, f.maximum);
      if(f.step > 0.) v->step(f.step);
      v->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE |
              (f.done ? FL_WHEN_NOT_CHANGED : 0));
      widget = v;
      break;
    }
    Fl_Value_Input *v = new valueInput(fx, fy, fieldW, RH);
    // the input inside is given the valuator's when() at every event: set there
    // or not at all. With done, Enter says the value is the one even when it
    // did not change
    v->when((f.commitsWhenDone ? 0 : FL_WHEN_CHANGED) | FL_WHEN_RELEASE |
            FL_WHEN_ENTER_KEY | (f.done ? FL_WHEN_NOT_CHANGED : 0));
    if(f.maximum > f.minimum) {
      v->minimum(f.minimum);
      v->maximum(f.maximum);
    }
    if(f.step > 0. && fltkSources().settings().inputScrolling)
      v->step(f.step);
    widget = v;
  } break;
  case Ui::Check:
    if(f.disclosure)
      widget = new Fl_Toggle_Button(fx, fy, fieldW, RH);
    else
      widget = new Fl_Check_Button(fx, fy, fieldW, RH, nullptr);
    break;
  case Ui::Choice:
    if(f.multiple) {
      Fl_Menu_Button *mb = new Fl_Menu_Button(fx, fy, fieldW, RH);
      widget = mb;
    }
    else
      widget = new Fl_Choice(fx, fy, fieldW, RH);
    break;
  case Ui::Label: {
    Fl_Box *b = new Fl_Box(fx, fy, fieldW, fieldH);
    b->align((f.align == Ui::Centre ? FL_ALIGN_CENTER :
              f.align == Ui::Right  ? FL_ALIGN_RIGHT :
                                      FL_ALIGN_LEFT) |
             FL_ALIGN_INSIDE | (f.wraps ? FL_ALIGN_WRAP | FL_ALIGN_TOP : 0));
    if(f.heading) b->labelfont(FL_HELVETICA_BOLD);
    widget = b;
  } break;
  case Ui::Output: {
    Fl_Output *o = new Fl_Output(fx, fy, fieldW, RH);
    widget = o;
  } break;
  case Ui::Prose: {
    widget = new proseView(fx, fy, fieldW, fieldH);
  } break;
  case Ui::List: {
    Fl_Browser_ *br;
    if(!f.choose)
      br = new Fl_Select_Browser(fx, fy, fieldW, fieldH);
    else if(f.multiple)
      br = new Fl_Multi_Browser(fx, fy, fieldW, fieldH);
    else
      br = new Fl_Hold_Browser(fx, fy, fieldW, fieldH);
    // the widths have to outlive this call: the browser keeps the array
    if(f.columnsEm.size()) {
      std::vector<int> *widths = new std::vector<int>;
      for(double wide : f.columnsEm)
        widths->push_back((int)(wide * FL_NORMAL_SIZE));
      widths->push_back(0); // the last column takes what is left
      ((Fl_Browser *)br)->column_widths(widths->data());
      ((Fl_Browser *)br)->column_char('\t');
    }
    if(f.isCode) {
#if defined(WIN32) // FL_SCREEN is too small there
      br->textfont(FL_COURIER);
#else
      br->textfont(FL_SCREEN);
#endif
      br->textsize(FL_NORMAL_SIZE - 2);
    }
    br->callback(_fieldCallback, this);
    widget = br;
  } break;
  case Ui::Color: {
    Fl_Button *b = new Fl_Button(fx, fy, fieldW, RH);
    b->box(FL_DOWN_BOX);
    widget = b;
  } break;
  case Ui::Action: {
    Fl_Button *b;
    if(f.isDefault)
      b = new Fl_Return_Button(fx, fy, fieldW, RH);
    else
      b = new Fl_Button(fx, fy, fieldW, f.hangs ? fieldH : RH);
    b->callback(_buttonCallback, new buttonAction{this, f.changed});
    widget = b;
  } break;
  case Ui::Menu: {
    Fl_Menu_Button *mb = new Fl_Menu_Button(fx, fy, fieldW, RH);
    widget = mb;
  } break;
  case Ui::Direction:
    widget = new spherePositionWidget(fx, fy, fieldH);
    break;
  case Ui::Hierarchy: {
    Fl_Tree *tree = new Fl_Tree(fx, fy, fieldW, fieldH);
    tree->selectmode(FL_TREE_SELECT_MULTI);
    tree->callback(_fieldCallback, this);
    tree->when(FL_WHEN_CHANGED);
    widget = tree;
  } break;
  case Ui::ColorMap: {
    colorbarWindow *bar = new colorbarWindow(fx, fy, fieldW, fieldH);
    bar->end();
    widget = bar;
  } break;
  case Ui::Spacer: break;
  }
  if(!widget) return;
  // copy_label(): a widget keeps the pointer it is given
  if(f.label.size() && f.kind != Ui::Label)
    widget->copy_label(_escaped(f.label).c_str());
  // a check button and a menu of switches draw their label inside:
  // FL_ALIGN_RIGHT would throw it off
  if(f.kind != Ui::Check && f.kind != Ui::Label && f.kind != Ui::Action &&
     f.kind != Ui::Menu && f.kind != Ui::Direction &&
     f.kind != Ui::ColorMap && f.kind != Ui::Hierarchy &&
     !(f.kind == Ui::Choice && f.multiple))
    widget->align(f.labelBefore ? FL_ALIGN_LEFT : FL_ALIGN_RIGHT);
  // on a dark face the face is coloured, on a light one the text
  if(f.alert) {
    if(f.kind == Ui::Action && fltkSources().settings().darkScheme)
      widget->color(FL_DARK_RED);
    else
      widget->labelcolor(FL_DARK_RED);
  }
  if(f.tooltip.size()) widget->copy_tooltip(f.tooltip.c_str());
  widget->callback(_fieldCallback, this);
  into->add(widget);
  bound b;
  for(std::size_t t = 0; t < f.trailing.size() && t < p.trailing.size();
      t++) {
    _kept().push_back(f.trailing[t]);
    Ui::Button *button = &_kept().back();
    Fl_Button *made =
      new Fl_Button(WB + px(p.trailing[t].x), fy, px(p.trailing[t].w), RH);
    into->add(made);
    b.trailing.push_back(made);
    if(button->glyph.size())
      made->copy_label(("@-1gmsh_" + button->glyph).c_str());
    else if(button->label.size())
      made->copy_label(button->label.c_str());
    else if(button->menu)
      made->copy_label("@2>");
    if(button->tooltip.size()) made->copy_tooltip(button->tooltip.c_str());
    made->callback(button->menu ? _trailingMenu : _trailingPressed, button);
    if(button->on && button->on()) made->color(FL_GREEN);
  }
  // FLTK draws a name to the right of the widget it belongs to: after the
  // buttons, a box of its own
  if(p.label.w > 0. && !f.labelBefore) {
    widget->label(nullptr);
    Fl_Box *say = new Fl_Box(WB + px(p.label.x), fy, px(p.label.w), RH);
    say->copy_label(_escaped(f.label).c_str());
    say->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    into->add(say);
    b.labelBox = say;
  }
  b.field = p.field;
  b.widget = widget;
  b.index = index;
  _fields.push_back(b);
}

// built again only when the shape changed: rebuilding a window that is up makes
// it blink
void dialogFltk::reshape()
{
  if(!_which) return;
  Ui::Form now = *_which;
  if(_win && _signature(now) == _signatureBuilt) {
    _panel = now;
    if(_relayout(true)) {
      refresh();
      return;
    }
  }
  build(*_which);
  refresh();
}

Ui::Placement dialogFltk::_placement(const Ui::Form &p)
{
  const double em = FL_NORMAL_SIZE;
  Ui::Metrics m = _metrics();
  Ui::Size need = Ui::treeSize(p.content, m, p.leastRows);
  // never so narrow that a dialog with little in it looks starved, as the
  // page has it; a column down the side is beside the dialog
  double least = 12. - 2. * WB / em;
  const Ui::Item &c = p.content;
  if(c.kind == Ui::Item::ABox && c.box->direction == Ui::Box::Across &&
     c.box->items.size() > 1 && Ui::fills(c.box->items[0]))
    least += Ui::treeSize(c.box->items[0], m, 0).w;
  double width = std::max(need.w, least);
  int pixels = (int)std::floor(width * em + 0.5);
  // keeps the widest width asked for, so that it sits still
  if(pixels > _widestSeen)
    _widestSeen = pixels;
  else
    width = _widestSeen / em;
  return Ui::placeTree(p.content, m, width, need.h, p.leastRows);
}

namespace {
  // what is folded away, as a word: placing the form again is only worth it
  // when this changes
  void _folded(const Ui::Item &it, std::string &s)
  {
    switch(it.kind) {
    case Ui::Item::AField:
      if(it.field.visible) s += it.field.visible() ? '+' : '-';
      break;
    case Ui::Item::ABox:
      if(it.box->visible) s += it.box->visible() ? '+' : '-';
      for(const auto &i : it.box->items) _folded(i, s);
      break;
    case Ui::Item::ATabs:
      for(const auto &t : it.tabs->tabs) _folded(t.second, s);
      break;
    default: break;
    }
  }

  void _show(Fl_Widget *w, bool shown)
  {
    if(!w) return;
    if(shown)
      w->show();
    else
      w->hide();
  }
} // namespace

// the widgets moved to where the form now puts them: what folded away takes
// no room; false when the form is not the shape the widgets were made for
bool dialogFltk::_relayout(bool always)
{
  if(!_win) return true;
  std::string folded;
  _folded(_panel.content, folded);
  if(!always && folded == _folding) return true;
  _folding = folded;
  Ui::Placement placement = _placement(_panel);
  if(placement.items.size() != _placed.size()) return false;
  bool same = !always;
  for(std::size_t i = 0; same && i < _placed.size(); i++) {
    const Ui::PlacedItem &was = _placed[i], &now = placement.items[i];
    if(was.hidden != now.hidden || was.box.x != now.box.x ||
       was.box.y != now.box.y || was.box.w != now.box.w ||
       was.box.h != now.box.h)
      same = false;
  }
  if(same) return true;
  _placed = placement.items;
  _aloneInColumn = Ui::aloneInColumn(placement);
  const double em = FL_NORMAL_SIZE;
  auto px = [em](double v) { return (int)std::floor(v * em + 0.5); };
  _win->size(px(placement.width) + 2 * WB, px(placement.height) + 2 * WB);
  for(std::size_t i = 0; i < _placed.size(); i++) {
    const Ui::PlacedItem &p = _placed[i];
    if(!_groups[i]) continue;
    if(p.item->kind == Ui::Item::ARule)
      _groups[i]->resize(WB + px(p.box.x), WB + px(p.box.y) + WB,
                         px(p.box.w), 2);
    else
      _groups[i]->resize(WB + px(p.box.x), WB + px(p.box.y), px(p.box.w),
                         px(p.box.h));
    if(Fl_Tabs *tabs = dynamic_cast<Fl_Tabs *>(_groups[i]))
      for(int k = 0; k < tabs->children(); k++)
        tabs->child(k)->resize(tabs->x(), tabs->y() + BH, tabs->w(),
                               tabs->h() - BH);
    _show(_groups[i], !p.hidden);
  }
  for(auto &b : _fields) {
    const Ui::PlacedItem &p = _placed[b.index];
    if(p.field.kind == b.field.kind) b.field = p.field;
    _place(b, p);
  }
  for(std::size_t i = 0; i < _placed.size(); i++)
    if(Fl_Group *g = dynamic_cast<Fl_Group *>(_groups[i])) g->init_sizes();
  _win->init_sizes();
  _win->redraw();
  return true;
}

void dialogFltk::_place(bound &b, const Ui::PlacedItem &p)
{
  const int RH = _rowH();
  const double em = FL_NORMAL_SIZE;
  auto px = [em](double v) { return (int)std::floor(v * em + 0.5); };
  int fx = WB + px(p.box.x), fy = WB + px(p.box.y);
  int fieldW = px(p.box.w), fieldH = px(p.box.h);
  if(p.item->kind == Ui::Item::ARule) {
    b.widget->resize(fx, fy + WB, fieldW, 2);
  }
  else if(p.field.kind == Ui::List && !p.field.rows && p.aside &&
          _aloneInColumn) {
    // a list in a column has no box but a rule on its right, and runs to
    // the edges of the window where nothing stands between
    int edge = 2 * WB + 3;
    int x = fx <= edge ? 0 : fx, y = fy <= edge ? 0 : fy;
    int bottom = fy + fieldH + edge >= _win->h() ? _win->h() : fy + fieldH;
    b.widget->resize(x, y, fieldW + fx - x, bottom - y);
    b.widget->box(GMSH_SIMPLE_RIGHT_BOX);
  }
  else if(p.field.kind == Ui::Label) {
    // set in from the top, or the first line touches the frame
    int inset = (p.field.wraps && p.field.rows > 1) ? WB / 2 : 0;
    b.widget->resize(fx, fy + inset, fieldW, fieldH - inset);
  }
  else {
    bool tall = p.field.kind == Ui::Prose || p.field.kind == Ui::List ||
                p.field.kind == Ui::Hierarchy || p.field.kind == Ui::ColorMap ||
                p.field.kind == Ui::Direction || p.field.hangs;
    b.widget->resize(fx, fy, fieldW, tall ? fieldH : RH);
  }
  _show(b.widget, !p.hidden);
  for(std::size_t t = 0; t < b.trailing.size() && t < p.trailing.size(); t++) {
    b.trailing[t]->resize(WB + px(p.trailing[t].x), fy, px(p.trailing[t].w),
                          RH);
    _show(b.trailing[t], !p.hidden);
  }
  if(b.labelBox) {
    b.labelBox->resize(WB + px(p.label.x), fy, px(p.label.w), RH);
    _show(b.labelBox, !p.hidden);
  }
}

void dialogFltk::build(const Ui::Form &form)
{
  // the window stays; the old widgets are deleted once the event that asked for
  // this is over: one of them may be the button whose callback is running
  bool again = _win != nullptr;
  if(again) {
    while(_win->children()) {
      Fl_Widget *w = _win->child(0);
      _win->remove(w);
      w->hide();
      Fl::delete_widget(w);
    }
  }
  _panes.clear();
  _fields.clear();
  _groups.clear();

  _which = &form;
  _panel = form;
  _signatureBuilt = _signature(_panel);
  _folding.clear();
  _folded(_panel.content, _folding);
  _forcePane = true;

  const double em = FL_NORMAL_SIZE;
  auto px = [em](double v) { return (int)std::floor(v * em + 0.5); };
  Ui::Placement placement = _placement(_panel);
  _placed = placement.items;
  _aloneInColumn = Ui::aloneInColumn(placement);
  int width = px(placement.width) + 2 * WB;
  int height = px(placement.height) + 2 * WB;

  Fl_Group *previous = Fl_Group::current();
  Fl_Group::current(nullptr);

  if(again) {
    _win->size(width, height);
    _win->copy_label(_panel.title.c_str());
    if(dialogWindow *w = dynamic_cast<dialogWindow *>(_win))
      w->closed = _panel.closed;
  }
  else {
    dialogWindow *win = new dialogWindow(
      width, height, fltkSources().settings().nonModalWindows,
      _panel.title.c_str());
    win->closed = _panel.closed;
    _win = win;
    _win->box(GMSH_WINDOW_BOX);
    _win->end();
  }

  // the groups first: tabs and their panes, boxes that scroll; then every
  // item into the group it is placed in. A group makes itself current as it
  // is made: ended at once, since every widget is added to its group by hand
  // here
  _groups.assign(_placed.size(), nullptr);
  std::vector<std::vector<Fl_Group *> > paneOf(_placed.size());
  std::vector<Fl_Group *> holder(_placed.size(), nullptr);
  for(std::size_t i = 0; i < _placed.size(); i++) {
    const Ui::PlacedItem &p = _placed[i];
    Fl_Group *into = _win;
    if(p.parent != (std::size_t)-1) {
      if(p.pane >= 0 && p.pane < (int)paneOf[p.parent].size())
        into = paneOf[p.parent][(std::size_t)p.pane];
      else
        into = holder[p.parent];
    }
    if(!into) into = _win;
    int x = WB + px(p.box.x), y = WB + px(p.box.y);
    int w = px(p.box.w), h = px(p.box.h);
    if(p.item->kind == Ui::Item::ATabs) {
      Fl_Tabs *tabs = new Fl_Tabs(x, y, w, h);
      tabs->end();
      tabs->callback(_tabCallback, this);
      _overflowsInMenu(tabs);
      into->add(tabs);
      for(const auto &t : p.item->tabs->tabs) {
        Fl_Group *pg = new Fl_Group(x, y + BH, w, h - BH);
        pg->end();
        pg->copy_label(_plain(t.first).c_str());
        tabs->add(pg);
        paneOf[i].push_back(pg);
        _panes.push_back({t.first, pg, tabs, i});
      }
      _groups[i] = holder[i] = tabs;
      continue;
    }
    if(p.item->kind == Ui::Item::ABox && p.item->box->scrolling) {
      Fl_Scroll *scroll = new Fl_Scroll(x, y, w, h);
      scroll->end();
      scroll->type(Fl_Scroll::VERTICAL);
      scroll->box(FL_FLAT_BOX);
      into->add(scroll);
      _groups[i] = holder[i] = scroll;
      continue;
    }
    if(p.item->kind == Ui::Item::ABox) {
      holder[i] = into;
      continue;
    }
    if(p.item->kind == Ui::Item::ARule) {
      Fl_Box *line = new Fl_Box(x, y + WB, w, 2);
      line->box(FL_ENGRAVED_FRAME);
      line->labeltype(FL_NO_LABEL);
      into->add(line);
      _groups[i] = line;
      continue;
    }
    _addItem(i, into);
  }
  for(auto &b : _fields) _place(b, _placed[b.index]);

  if(!again) {
    const Ui::Backend::Settings set = fltkSources().settings();
    _win->position(set.dialogX, set.dialogY);
  }
  Fl_Group::current(previous);

  _byOption.clear();
  for(std::size_t i = 0; i < _fields.size(); i++)
    if(_fields[i].field.option.size())
      _byOption.emplace(_fields[i].field.option, i);

  if(_paneWanted.size()) {
    _pane = _paneWanted;
    _paneWanted.clear();
  }
  refresh();
  _win->redraw();
}

// the user clicked a tab: the description must follow, or the next refresh
// puts the pane it remembers back
void dialogFltk::_tabCallback(Fl_Widget *w, void *data)
{
  dialogFltk *d = (dialogFltk *)data;
  Fl_Widget *shown = ((Fl_Tabs *)w)->value();
  for(const auto &p : d->_panes) {
    if(p.group != shown) continue;
    bool moved = d->_pane != p.label;
    d->_pane = p.label;
    d->refresh();
    // copies: what is told may build the dialog again, which drops the form
    // the tabs are in
    std::function<void(const std::string &)> chosen =
      d->_placed[p.index].item->tabs->chosen;
    std::string label = p.label;
    if(moved && chosen) chosen(label);
    return;
  }
  d->refresh();
}

void dialogFltk::_tick(void *data)
{
  dialogFltk *d = (dialogFltk *)data;
  if(!d->shown()) return; // it stops with the window and starts with it again
  d->refresh();
  Fl::repeat_timeout(d->_panel.refreshEvery, _tick, data);
}

namespace {

  // kept while the tree points at them: an Fl_Tree item carries a void*
  std::deque<std::string> _treePaths;

  void _addBranch(Fl_Tree *tree, Fl_Tree_Item *parent, const Ui::Tree &said,
                  const std::string &path)
  {
    if(!said.children) return;
    for(const auto &child : said.children(path)) {
      Ui::Node node = said.node(child);
      Fl_Tree_Item *item = tree->add(parent, _plain(node.label).c_str());
      if(!item) continue;
      _treePaths.push_back(child);
      item->user_data((void *)&_treePaths.back());
      item->close();
      _addBranch(tree, item, said, child);
    }
  }

} // namespace

void dialogFltk::_refreshField(bound &b)
{
  const Ui::Field &f = b.field;
  switch(f.kind) {
  case Ui::Label: {
    std::string value = f.getText();
    if(!b.widget->label() || value != b.widget->label())
      b.widget->copy_label(_plain(value).c_str());
  } break;
  case Ui::Output: {
    std::string value = f.getText();
    Fl_Output *o = (Fl_Output *)b.widget;
    if(!o->value() || value != o->value()) o->value(value.c_str());
  } break;
  case Ui::Prose: {
    proseView *v = (proseView *)b.widget;
    std::vector<Ui::Line> page =
      f.prose ? f.prose() : std::vector<Ui::Line>();
    std::string said;
    for(const Ui::Line &l : page)
      for(const Ui::Words &word : l.words) said += word.text + "\n";
    if(said != b.was) {
      b.was = said;
      v->page = page;
      v->redraw();
    }
  } break;
  case Ui::List: {
    Fl_Browser *br = (Fl_Browser *)b.widget;
    // not while the pointer is down on it: what it picks would be lost
    if(Fl::pushed() == br) break;
    int keep = br->value();
    if(f.dynamicChoices) {
      std::vector<std::string> labels;
      std::vector<int> values;
      f.dynamicChoices(labels, values);
      // the lines only when they changed, so that the list does not blink
      bool same = br->size() == (int)labels.size();
      for(int k = 0; same && k < br->size(); k++)
        if(!br->text(k + 1) || labels[(std::size_t)k] != br->text(k + 1))
          same = false;
      if(!same) {
        br->clear();
        for(auto &l : labels) br->add(l.c_str());
      }
      for(int k = 0; f.chosen && k < (int)labels.size(); k++)
        br->select(k + 1, f.chosen(k) ? 1 : 0);
      break;
    }
    br->clear();
    if(f.list) {
      for(std::size_t k = 0; k < f.list->size(); k++)
        br->add(f.itemLabel ? f.itemLabel((int)k).c_str()
                            : std::to_string((*f.list)[k]).c_str());
      if(keep > 0 && keep <= br->size()) br->select(keep);
    }
  } break;
  case Ui::Color: {
    Ui::Colour c = f.getColour();
    Fl_Color shown = fl_rgb_color(c.r, c.g, c.b);
    if(b.widget->color() != shown) {
      b.widget->color(shown);
      b.widget->redraw();
    }
  } break;
  case Ui::Direction: {
    double x = 0., y = 0., z = 0.;
    f.getVector(x, y, z);
    ((spherePositionWidget *)b.widget)->setValue(x, y, z);
  } break;
  case Ui::Hierarchy: {
    Fl_Tree *tree = (Fl_Tree *)b.widget;
    if(!f.hierarchy) break;
    const Ui::Tree &said = *f.hierarchy;
    // an Fl_Tree built again forgets what was open
    std::string signature = std::to_string(said.generation ?
                                             said.generation() : 0);
    if(signature != b.was) {
      b.was = signature;
      tree->clear();
#if FL_API_VERSION >= 10400
      Fl_Tree_Item *root = new Fl_Tree_Item(tree);
#else
      Fl_Tree_Item *root = new Fl_Tree_Item(tree->prefs());
#endif
      root->label(_plain(f.label.size() ? f.label : "Gmsh").c_str());
      tree->root(root);
      _addBranch(tree, root, said, "");
    }
    for(Fl_Tree_Item *item = tree->first(); item; item = tree->next(item)) {
      const std::string *path = (const std::string *)item->user_data();
      if(!path) continue;
      Ui::Node node = said.node(*path);
      bool on = node.picked ? node.picked() : false;
      if(on != (item->is_selected() ? true : false))
        item->select(on ? 1 : 0);
    }
    tree->redraw();
  } break;
  case Ui::ColorMap: {
    std::string name;
    double least = 0., most = 0.;
    if(f.map.empty()) break;
    f.map.about(name, least, most);
    ((colorbarWindow *)b.widget)
      ->update(name.c_str(), least, most, f.map, &b.changed);
  } break;
  case Ui::Menu: {
    Fl_Menu_Button *m = (Fl_Menu_Button *)b.widget;
    std::vector<std::string> labels;
    std::vector<int> values;
    if(f.dynamicChoices) f.dynamicChoices(labels, values);
    m->clear();
    for(auto &l : labels) m->add(_escapedMenu(l).c_str());
    if(!m->label() || f.label != m->label())
      m->copy_label(_escaped(f.label).c_str());
  } break;
  case Ui::Action:
  case Ui::Spacer: break;
  case Ui::Text: {
    std::string value = f.getText();
    if(Fl_Input_Choice *c = dynamic_cast<Fl_Input_Choice *>(b.widget)) {
      std::vector<std::string> labels;
      std::vector<int> values;
      f.dynamicChoices(labels, values);
      c->menubutton()->clear();
      for(auto &l : labels) c->menubutton()->add(_escapedMenu(l).c_str());
      if(!c->value() || value != c->value()) c->value(value.c_str());
    }
    else {
      Fl_Input *in = (Fl_Input *)b.widget;
      if(value != in->value()) in->value(value.c_str());
    }
  } break;
  case Ui::Integer:
  case Ui::Number: {
    Fl_Valuator *v = (Fl_Valuator *)b.widget;
    if(f.maximum > f.minimum) {
      v->minimum(f.minimum);
      v->maximum(f.maximum);
    }
    if(f.step > 0. && fltkSources().settings().inputScrolling) v->step(f.step);
    v->value(f.getNumber());
  } break;
  case Ui::Check: {
    bool on = f.getFlag();
    ((Fl_Button *)b.widget)->value(on ? 1 : 0);
    if(f.disclosure) {
      std::string label = _escaped(f.label) + (on ? " @-28->" : " @-22->");
      if(!b.widget->label() || label != b.widget->label())
        b.widget->copy_label(label.c_str());
    }
  } break;
  case Ui::Choice: {
    if(f.multiple) {
      Fl_Menu_Button *m = (Fl_Menu_Button *)b.widget;
      std::vector<std::string> labels;
      std::vector<int> values;
      if(f.dynamicChoices) f.dynamicChoices(labels, values);
      m->clear();
      for(std::size_t k = 0; k < labels.size(); k++) {
        int index = m->add(_escapedMenu(labels[k]).c_str(), 0, nullptr,
                           nullptr, FL_MENU_TOGGLE);
        if(f.chosen && f.chosen((int)k))
          ((Fl_Menu_Item *)&m->menu()[index])->set();
      }
      break;
    }
    Fl_Choice *c = (Fl_Choice *)b.widget;
    std::vector<std::string> labels;
    std::vector<int> values;
    if(f.dynamicChoices)
      f.dynamicChoices(labels, values);
    else {
      labels = f.choices;
      values = f.values;
    }
    c->clear();
    for(auto &l : labels) c->add(_escapedMenu(l).c_str());
    int which = 0;
    bool byText = values.empty();
    std::string current = byText ? f.getText() : "";
    for(std::size_t k = 0; k < labels.size(); k++) {
      if(byText) {
        if(labels[k] == current) which = (int)k;
      }
      else if(k < values.size() && values[k] == (int)f.getNumber())
        which = (int)k;
    }
    if(labels.size()) c->value(which);
  } break;
  }
  if(f.enabled) {
    if(f.enabled())
      b.widget->activate();
    else
      b.widget->deactivate();
  }
}


void dialogFltk::refresh()
{
  _relayout(false);
  // only when the pane has just been asked for: forcing it at every refresh
  // would undo the tab the user clicked
  if(_forcePane) {
    _forcePane = false;
    for(const auto &p : _panes) {
      if(p.label != _pane) continue;
      p.tabs->value(p.group);
      // and the row of tabs the pane's is in, for tabs under tabs
      Fl_Tabs *inner = p.tabs;
      for(const auto &o : _panes)
        if(o.group->find(inner) < o.group->children()) {
          o.tabs->value(o.group);
          inner = o.tabs;
        }
    }
  }
  for(const auto &p : _panes) {
    if(p.tabs->value() == p.group)
      p.group->show();
    else
      p.group->hide();
  }
  // a window inside a pane -- the colour map -- is one of the X server's,
  // which hiding its pane does not take off the screen
  if(_win) _showWindows(_win);
  for(auto &b : _fields) _refreshField(b);
  if(_win) _win->redraw();
}

void dialogFltk::_showWindows(Fl_Group *group)
{
  for(int k = 0; k < group->children(); k++) {
    Fl_Widget *w = group->child(k);
    if(Fl_Window *sub = w->as_window()) {
      if(sub->parent() && sub->parent()->visible_r())
        sub->show();
      else
        sub->hide();
    }
    else if(Fl_Group *g = w->as_group())
      _showWindows(g);
  }
}

void dialogFltk::optionChanged(const std::string &name)
{
  auto range = _byOption.equal_range(name);
  if(range.first == range.second) return;
  for(auto it = range.first; it != range.second; ++it)
    _refreshField(_fields[it->second]);
  for(auto &b : _fields)
    if(b.field.enabled) {
      if(b.field.enabled())
        b.widget->activate();
      else
        b.widget->deactivate();
    }
  if(_win) _win->redraw();
}

void dialogFltk::show()
{
  // rebuilding a window that is up makes it blink and come back elsewhere
  if(!_which) return;
  Ui::Form now = *_which;
  if(!_win || _signature(now) != _signatureBuilt)
    build(*_which);
  else
    _panel = now;
  if(!_win) return;
  _forcePane = true;
  refresh();
  _win->show();
  if(_panel.refreshEvery > 0.) {
    Fl::remove_timeout(_tick, this);
    Fl::add_timeout(_panel.refreshEvery, _tick, this);
  }
}

void dialogFltk::hide()
{
  if(_win) _win->hide();
}

bool dialogFltk::shown() const { return _win && _win->shown(); }


std::string dialogFltk::pane() const
{
  if(!_win) return _paneWanted;
  return _pane;
}

void dialogFltk::setPane(const std::string &pane)
{
  if(!_win) {
    _paneWanted = pane;
    return;
  }
  _pane = pane;
  _forcePane = true;
}

namespace {
  // a map keeps the addresses steady: the widgets rely on them
  std::map<const Ui::Form *, dialogFltk> &_dialogs()
  {
    static std::map<const Ui::Form *, dialogFltk> dialogs;
    return dialogs;
  }
} // namespace

dialogFltk *fltkDialog(const Ui::Form &which, bool create,
                       const std::string &pane)
{
  std::map<const Ui::Form *, dialogFltk> &dialogs = _dialogs();
  auto it = dialogs.find(&which);
  if(it == dialogs.end()) {
    if(!create) return nullptr;
    it = dialogs.emplace(&which, dialogFltk()).first;
    if(pane.size()) it->second.setPane(pane);
    it->second.build(which);
  }
  return &it->second;
}

void fltkDropDialog(const Ui::Form &which)
{
  _dialogs().erase(&which);
}

void fltkEachDialog(const std::function<void(dialogFltk *)> &what)
{
  for(auto &it : _dialogs()) what(&it.second);
}
