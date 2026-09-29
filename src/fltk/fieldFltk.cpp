// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The widget of one field, for the forms and for the lines of the tree. Each
// carries its binding -- a copy of the field, and what the holder does after a
// change -- so that it goes with it: a change the user makes is written
// through the field, then told, then `after` runs; a refresh reads the field
// and puts the value back. And the widgets FLTK has none for: a number with
// the decimals of its step, a point on the unit sphere, a colour map, a page
// of prose.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Slider.H>

#include <FL/fl_draw.H>

#include "fltkCommon.h"
#include "MapEditor.h"

// --- the widgets FLTK has none for

// a number as every interface shows it (Ui::numberText): with the decimals
// of its step, the step being set when values are dragged
class numberFltk : public Fl_Value_Input {
public:
  numberFltk(int x, int y, int w, int h) : Fl_Value_Input(x, y, w, h) {}
  int format(char *buffer) override
  {
    return snprintf(buffer, 128, "%s", Ui::numberText(value(), step()).c_str());
  }
};

// a point on the unit sphere, dragged in a disc
class discFltk : public Fl_Widget {
  double _x, _y, _z;
  void draw() override;

public:
  discFltk(int x, int y, int w, const char *l = nullptr);
  int handle(int event) override;
  void setValue(double x, double y, double z);
  void getValue(double &x, double &y, double &z) const;
};

// the colour map of a view, edited with the mouse and the keys: the editor
// is Ui::MapEditor, what it edits described by Ui::ColourMap
class colourMapFltk : public Fl_Window {
  Ui::MapEditor _edit;
  Ui::ColourMap _map;
  std::string _name;
  double _min, _max;
  bool *_changed;
  // the entry, the intensity and the part of the picture under x, y
  void _at(int x, int y, int &entry, int &value, bool &onWedge);

public:
  colourMapFltk(int x, int y, int w, int h, const char *l = nullptr);
  void draw() override;
  int handle(int event) override;
  void update(const char *name, double min, double max,
              const Ui::ColourMap &map, bool *changed);
};

std::string fltkEscaped(const std::string &label)
{
  std::string out;
  for(char c : label) {
    out += c;
    if(c == '&') out += c;
  }
  return out;
}

namespace {

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

  // --- a page of prose

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

  // --- the binding a widget carries, deleted with it

  struct binding {
    Ui::Field field;
    std::function<void()> after;
    // set by the colour map widget when it has been drawn on
    bool changed = false;
    // so that a list or a tree is only built again when its lines changed
    std::string was;
    virtual ~binding() {}
  };

  template <class W> class bound : public W, public binding {
  public:
    template <class... A> bound(A... a) : W(a...) {}
  };

  binding *_of(Fl_Widget *w) { return w ? dynamic_cast<binding *>(w) : nullptr; }

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

  // what the user did, written through a copy of the field: what it does may
  // build again the widget this is called from
  void _changed(Fl_Widget *w, void *)
  {
    binding *b = _of(w);
    if(!b) return;
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    switch(f.kind) {
    case Ui::Text:
      if(Fl_Input_Choice *c = dynamic_cast<Fl_Input_Choice *>(w))
        f.setText(c->value() ? c->value() : "");
      else
        f.setText(((Fl_Input *)w)->value());
      break;
    case Ui::Integer:
    case Ui::Number: f.setNumber(((Fl_Valuator *)w)->value()); break;
    case Ui::Check: f.setFlag(((Fl_Button *)w)->value() ? true : false); break;
    case Ui::Color: {
      Ui::Colour c = f.getColour();
      uchar r = c.r, g = c.g, bl = c.b;
      if(fl_color_chooser("Color Chooser", r, g, bl))
        f.setColour(Ui::Colour(r, g, bl, c.a));
    } break;
    case Ui::Direction: {
      double x = 0., y = 0., z = 0.;
      ((discFltk *)w)->getValue(x, y, z);
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
    case Ui::Spacer: break;
    case Ui::Action:
      // a button is pressed, not chosen
      if(f.changed) f.changed();
      if(after) after();
      return;
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
      Ui::choices(f, labels, values);
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
    if(after) after();
  }

  // kept while the tree points at them: an Fl_Tree item carries a void*
  std::deque<std::string> _treePaths;

  void _addBranch(Fl_Tree *tree, Fl_Tree_Item *parent, const Ui::Tree &said,
                  const std::string &path)
  {
    if(!said.children) return;
    for(const auto &child : said.children(path)) {
      Ui::Node node = said.node(child);
      Fl_Tree_Item *item = tree->add(parent, node.label.c_str());
      if(!item) continue;
      _treePaths.push_back(child);
      item->user_data((void *)&_treePaths.back());
      item->close();
      _addBranch(tree, item, said, child);
    }
  }

  // --- the buttons hung after a field

  class buttonFltk : public Fl_Button {
  public:
    Ui::Button button;
    std::string key;
    buttonFltk(int x, int y, int w, int h) : Fl_Button(x, y, w, h) {}
  };

  void _buttonPressed(Fl_Widget *w, void *)
  {
    buttonFltk *b = (buttonFltk *)w;
    if(b->button.menu) {
      fltkPopupMenu(b->button.menu(), Fl::event_x_root(), Fl::event_y_root(),
                    b->key);
      return;
    }
    std::function<void()> what = b->button.action;
    if(what) what();
  }

} // namespace

int fltkProseHeight(const std::vector<Ui::Line> &page, int width)
{
  return _layProse(page, 0, 0, width, false, nullptr);
}

Fl_Widget *fltkFieldWidget(const Ui::Field &f, int x, int y, int w, int h,
                           const std::function<void()> &after)
{
  Fl_Widget *widget = nullptr;
  switch(f.kind) {
  case Ui::Text:
    if(f.dynamicChoices) {
      Fl_Input_Choice *c = new bound<Fl_Input_Choice>(x, y, w, h);
      // picking from the menu goes through the group
      c->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      if(f.commitsWhenDone)
        c->input()->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      widget = c;
    }
    else {
      Fl_Input *in = new bound<Fl_Input>(x, y, w, h);
      in->when(f.commitsWhenDone ? (FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY) :
                                   FL_WHEN_CHANGED);
      widget = in;
    }
    break;
  case Ui::Integer:
  case Ui::Number: {
    if(f.slider && f.maximum > f.minimum) {
      Fl_Value_Slider *v = new bound<Fl_Value_Slider>(x, y, w, h);
      v->type(FL_HOR_SLIDER);
      v->textsize(FL_NORMAL_SIZE);
      v->bounds(f.minimum, f.maximum);
      if(f.step > 0.) v->step(f.step);
      v->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE |
              (f.done ? FL_WHEN_NOT_CHANGED : 0));
      widget = v;
      break;
    }
    Fl_Value_Input *v = new bound<numberFltk>(x, y, w, h);
    // the input inside is given the valuator's when() at every event: set there
    // or not at all. With done, Enter says the value is the one even when it
    // did not change
    v->when((f.commitsWhenDone ? 0 : FL_WHEN_CHANGED) | FL_WHEN_RELEASE |
            FL_WHEN_ENTER_KEY | (f.done ? FL_WHEN_NOT_CHANGED : 0));
    widget = v;
  } break;
  case Ui::Check:
    if(f.disclosure)
      widget = new bound<Fl_Toggle_Button>(x, y, w, h);
    else
      widget = new bound<Fl_Check_Button>(x, y, w, h, nullptr);
    break;
  case Ui::Choice:
    if(f.multiple)
      widget = new bound<Fl_Menu_Button>(x, y, w, h);
    else
      widget = new bound<Fl_Choice>(x, y, w, h);
    break;
  case Ui::Label: {
    Fl_Box *b = new bound<Fl_Box>(x, y, w, h);
    b->align((f.align == Ui::Centre ? FL_ALIGN_CENTER :
              f.align == Ui::Right  ? FL_ALIGN_RIGHT :
                                      FL_ALIGN_LEFT) |
             FL_ALIGN_INSIDE | (f.wraps ? FL_ALIGN_WRAP | FL_ALIGN_TOP : 0));
    if(f.heading) b->labelfont(FL_HELVETICA_BOLD);
    widget = b;
  } break;
  case Ui::Output: widget = new bound<Fl_Output>(x, y, w, h); break;
  case Ui::Prose: widget = new bound<proseView>(x, y, w, h); break;
  case Ui::List: {
    Fl_Browser_ *br;
    if(!f.choose)
      br = new bound<Fl_Select_Browser>(x, y, w, h);
    else if(f.multiple)
      br = new bound<Fl_Multi_Browser>(x, y, w, h);
    else
      br = new bound<Fl_Hold_Browser>(x, y, w, h);
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
    widget = br;
  } break;
  case Ui::Color: {
    Fl_Button *b = new bound<Fl_Button>(x, y, w, h);
    b->box(FL_DOWN_BOX);
    widget = b;
  } break;
  case Ui::Action:
    if(f.isDefault)
      widget = new bound<Fl_Return_Button>(x, y, w, h);
    else
      widget = new bound<Fl_Button>(x, y, w, h);
    break;
  case Ui::Menu: widget = new bound<Fl_Menu_Button>(x, y, w, h); break;
  case Ui::Direction: widget = new bound<discFltk>(x, y, h); break;
  case Ui::Hierarchy: {
    Fl_Tree *tree = new bound<Fl_Tree>(x, y, w, h);
    tree->end();
    tree->selectmode(FL_TREE_SELECT_MULTI);
    tree->when(FL_WHEN_CHANGED);
    widget = tree;
  } break;
  case Ui::ColorMap: {
    colourMapFltk *bar = new bound<colourMapFltk>(x, y, w, h);
    bar->end();
    widget = bar;
  } break;
  case Ui::Spacer: break;
  }
  if(!widget) return nullptr;
  binding *b = _of(widget);
  b->field = f;
  b->after = after;
  // copy_label(): a widget keeps the pointer it is given
  if(f.label.size() && f.kind != Ui::Label)
    widget->copy_label(fltkEscaped(f.label).c_str());
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
  widget->callback(_changed);
  fltkRefreshField(widget);
  return widget;
}

void fltkRebindField(Fl_Widget *widget, const Ui::Field &field)
{
  binding *b = _of(widget);
  if(b && b->field.kind == field.kind) b->field = field;
}

void fltkEnableField(Fl_Widget *widget)
{
  binding *b = _of(widget);
  if(!b || !b->field.enabled) return;
  if(b->field.enabled())
    widget->activate();
  else
    widget->deactivate();
}

void fltkRefreshField(Fl_Widget *widget)
{
  binding *b = _of(widget);
  if(!b) return;
  const Ui::Field &f = b->field;
  switch(f.kind) {
  case Ui::Label: {
    std::string value = f.getText();
    if(!widget->label() || value != widget->label())
      widget->copy_label(value.c_str());
  } break;
  case Ui::Output: {
    std::string value = f.getText();
    Fl_Output *o = (Fl_Output *)widget;
    if(!o->value() || value != o->value()) o->value(value.c_str());
  } break;
  case Ui::Prose: {
    proseView *v = (proseView *)widget;
    std::vector<Ui::Line> page = f.prose ? f.prose() : std::vector<Ui::Line>();
    std::string said;
    for(const Ui::Line &l : page)
      for(const Ui::Words &word : l.words) said += word.text + "\n";
    if(said != b->was) {
      b->was = said;
      v->page = page;
      v->redraw();
    }
  } break;
  case Ui::List: {
    Fl_Browser *br = (Fl_Browser *)widget;
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
        br->add(f.itemLabel ? f.itemLabel((int)k).c_str() :
                              std::to_string((*f.list)[k]).c_str());
      if(keep > 0 && keep <= br->size()) br->select(keep);
    }
  } break;
  case Ui::Color: {
    Ui::Colour c = f.getColour();
    Fl_Color shown = fl_rgb_color(c.r, c.g, c.b);
    if(widget->color() != shown) {
      widget->color(shown);
      widget->redraw();
    }
  } break;
  case Ui::Direction: {
    double x = 0., y = 0., z = 0.;
    f.getVector(x, y, z);
    ((discFltk *)widget)->setValue(x, y, z);
  } break;
  case Ui::Hierarchy: {
    Fl_Tree *tree = (Fl_Tree *)widget;
    if(!f.hierarchy) break;
    const Ui::Tree &said = *f.hierarchy;
    // an Fl_Tree built again forgets what was open
    std::string signature =
      std::to_string(said.generation ? said.generation() : 0);
    if(signature != b->was) {
      b->was = signature;
      tree->clear();
#if FL_API_VERSION >= 10400
      Fl_Tree_Item *root = new Fl_Tree_Item(tree);
#else
      Fl_Tree_Item *root = new Fl_Tree_Item(tree->prefs());
#endif
      root->label(f.label.size() ? f.label.c_str() : "Gmsh");
      tree->root(root);
      _addBranch(tree, root, said, "");
    }
    for(Fl_Tree_Item *item = tree->first(); item; item = tree->next(item)) {
      const std::string *path = (const std::string *)item->user_data();
      if(!path) continue;
      Ui::Node node = said.node(*path);
      bool on = node.picked ? node.picked() : false;
      if(on != (item->is_selected() ? true : false)) item->select(on ? 1 : 0);
    }
    tree->redraw();
  } break;
  case Ui::ColorMap: {
    std::string name;
    double least = 0., most = 0.;
    if(f.map.empty()) break;
    f.map.about(name, least, most);
    ((colourMapFltk *)widget)
      ->update(name.c_str(), least, most, f.map, &b->changed);
  } break;
  case Ui::Menu: {
    Fl_Menu_Button *m = (Fl_Menu_Button *)widget;
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    m->clear();
    for(auto &l : labels) m->add(_escapedMenu(l).c_str());
    if(!m->label() || f.label != m->label())
      m->copy_label(fltkEscaped(f.label).c_str());
  } break;
  case Ui::Action:
  case Ui::Spacer: break;
  case Ui::Text: {
    std::string value = f.getText();
    if(Fl_Input_Choice *c = dynamic_cast<Fl_Input_Choice *>(widget)) {
      std::vector<std::string> labels;
      std::vector<int> values;
      Ui::choices(f, labels, values);
      c->menubutton()->clear();
      for(auto &l : labels) c->menubutton()->add(_escapedMenu(l).c_str());
      if(!c->value() || value != c->value()) c->value(value.c_str());
    }
    else {
      Fl_Input *in = (Fl_Input *)widget;
      if(value != in->value()) in->value(value.c_str());
    }
  } break;
  case Ui::Integer:
  case Ui::Number: {
    Fl_Valuator *v = (Fl_Valuator *)widget;
    if(f.maximum > f.minimum) {
      v->minimum(f.minimum);
      v->maximum(f.maximum);
    }
    if(f.step > 0. && fltkSources().settings().inputScrolling) v->step(f.step);
    v->value(f.getNumber());
  } break;
  case Ui::Check: {
    bool on = f.getFlag();
    ((Fl_Button *)widget)->value(on ? 1 : 0);
    if(f.disclosure) {
      std::string label = fltkEscaped(f.label) + (on ? " @-28->" : " @-22->");
      if(!widget->label() || label != widget->label())
        widget->copy_label(label.c_str());
    }
  } break;
  case Ui::Choice: {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    if(f.multiple) {
      Fl_Menu_Button *m = (Fl_Menu_Button *)widget;
      m->clear();
      for(std::size_t k = 0; k < labels.size(); k++) {
        int index = m->add(_escapedMenu(labels[k]).c_str(), 0, nullptr,
                           nullptr, FL_MENU_TOGGLE);
        if(f.chosen && f.chosen((int)k))
          ((Fl_Menu_Item *)&m->menu()[index])->set();
      }
      break;
    }
    Fl_Choice *c = (Fl_Choice *)widget;
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
  fltkEnableField(widget);
}

Fl_Button *fltkButtonWidget(const Ui::Button &button, int x, int y, int w,
                            int h, const std::string &key)
{
  buttonFltk *made = new buttonFltk(x, y, w, h);
  made->button = button;
  made->key = key;
  // the picture, for the two that have one, in the way FLTK draws a symbol
  if(button.glyph.size())
    made->copy_label(("@-1gmsh_" + button.glyph).c_str());
  else if(button.label.size())
    made->copy_label(button.label.c_str());
  else if(button.menu)
    // one that only drops a list says so with the arrow FLTK draws on a
    // menu button
    made->copy_label("@2>");
  if(button.tooltip.size()) made->copy_tooltip(button.tooltip.c_str());
  made->callback(_buttonPressed);
  if(button.on && button.on()) made->color(FL_GREEN);
  if(button.enabled && !button.enabled()) made->deactivate();
  return made;
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
