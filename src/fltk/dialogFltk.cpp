// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "uiSources.h"
#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <algorithm>
#include <cmath>
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

// While the interface is being taken down every window is hidden in turn, and
// a dialog that undoes something when it closes must not undo it then: there
// is no view left to draw the undoing into.
static bool _closingDown = false;

void fltkDialogsClosingDown() { _closingDown = true; }

// a window that tells the description it has gone: FLTK calls the
// callback of a window only when the user closes it, and a dialog that
// leaves something behind has to hear about every way of hiding it
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

  // how many lines a list of fields takes, once those that share one are put
  // together
  int _proseRows(const Ui::Field &f);

  Ui::Metrics _metrics();

  int _rows(const std::vector<Ui::Field> &fields)
  {
    return Ui::neededRows(fields, _metrics());
  }

  // FLTK reads "&" in a label as the mark of a keyboard shortcut and does
  // not draw it, so an ampersand has to be doubled -- but only in the
  // widgets that read it: the menus, the buttons and the inputs; a box, a
  // group, a tab and a line of a tree draw what they are given
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

  // an entry of a menu goes through the same reading, and "/" opens a
  // submenu there, "\\" escapes the next character
  std::string _escapedMenu(const std::string &label)
  {
    std::string out;
    for(char c : label) {
      if(c == '&' || c == '/' || c == '\\') out += '\\';
      out += c;
    }
    return out;
  }

  // How wide a field's widget has to be. Alone on its line an input gets
  // the usual width, otherwise a narrower one so that several fit. A choice
  // gets the same as an input rather than the width of its longest entry,
  // so that the labels line up; one that really needs more says so with
  // widthEm.
  // Where a word one may follow was drawn, so that a click can find it again
  struct proseSpot {
    int x, y, w, h;
    std::function<void()> follow;
  };

  // Lay a page of prose out in a column, and draw it if asked to. Measuring
  // it and drawing it are the same walk, which is the only way the window
  // can be exactly as tall as what it has to say. Drawn by hand rather than
  // through an Fl_Help_View: FLTK cannot be given the page of a view whose
  // window has not been shown, and the windows made afterwards never open.
  int _layProse(const std::vector<Ui::Line> &page, int x, int y, int w,
                bool paint, std::vector<proseSpot> *spots)
  {
    if(spots) spots->clear();
    const int margin = WB;
    const int left = x + margin, right = x + w - margin;
    int at = y + margin;
    // one piece of a line as it is really drawn: a run of words in one font,
    // as much of it as fits on the row being filled
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
        // word by word, so that a long line is broken where a space is
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
            // a row never begins with a space
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

  // the page one reads, drawn by hand: see _layProse()
  class proseView : public Fl_Widget {
  public:
    std::vector<Ui::Line> page;
    std::vector<proseSpot> spots;
    proseView(int x, int y, int w, int h) : Fl_Widget(x, y, w, h)
    {
      box(FL_FLAT_BOX);
      color(FL_BACKGROUND2_COLOR);
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

  // how tall a page of prose is, in rows: it is laid out, since how many
  // rows a line takes depends on how wide the column is
  int _proseRows(const Ui::Field &f)
  {
    if(!f.prose) return 1;
    int wide = f.widthEm > 0. ? (int)(f.widthEm * FL_NORMAL_SIZE) : IW;
    int tall = _layProse(f.prose(), 0, 0, wide, false, nullptr);
    return (tall + BH - 1) / BH;
  }

  int _fieldWidth(const Ui::Field &f, int columns)
  {
    if(f.disclosure) return BB;
    if(f.kind == Ui::Spacer) return 0;
    if(f.kind == Ui::Action || f.kind == Ui::Menu) {
      // a button is as wide as the text it carries inside, never narrower than
      // an ordinary one
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      int need = (int)fl_width(_escaped(f.label).c_str()) + 2 * FL_NORMAL_SIZE;
      return (need > BB) ? need : BB;
    }
    if(f.kind == Ui::Label) {
      // one that says how wide it is takes that; one that wraps and does not
      // takes the width of an ordinary field
      if(f.widthEm > 0.) return (int)(f.widthEm * FL_NORMAL_SIZE);
      if(f.wraps) return IW;
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      return (int)fl_width(f.getText().c_str()) + FL_NORMAL_SIZE;
    }
    if(f.kind == Ui::Check) return (int)(1.5 * FL_NORMAL_SIZE);
    // a field that says how wide it is takes that, whatever kind it is
    if(f.widthEm > 0.) return (int)(f.widthEm * FL_NORMAL_SIZE);
    // a swatch says what it is by its colour; it needs no room for text
    if(f.kind == Ui::Color) return (int)(3. * FL_NORMAL_SIZE);
    // the disc of a direction is square, as tall as the lines it hangs over
    if(f.kind == Ui::Direction) return f.rows * BH;
    // a colour map takes the pane it is in
    if(f.kind == Ui::ColorMap) return IW;
    int usual = (columns == 1) ? IW : IW / 2;
    // a dropdown sharing a line takes its arrow on top of its share rather
    // than out of its text; alone on its line it has room already
    if(f.kind == Ui::Choice && !f.multiple && columns > 1)
      usual += 2 * FL_NORMAL_SIZE;
    return usual;
  }

  // what a packed field needs: its own text and no more
  int _packedWidth(const Ui::Field &f)
  {
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    if(f.kind == Ui::Spacer)
      return (int)((f.widthEm > 0. ? f.widthEm : 2.) * FL_NORMAL_SIZE);
    if(f.disclosure) return BB;
    if(f.kind == Ui::Label) {
      // one that says how wide it is takes that
      if(f.widthEm > 0.) return (int)(f.widthEm * FL_NORMAL_SIZE);
      return f.wraps ? IW : (int)fl_width(f.getText().c_str()) + WB;
    }
    if(f.kind == Ui::Action || f.kind == Ui::Menu) {
      // one that says how wide it is takes that, the text being inside it
      if(f.widthShare > 0.) return (int)(f.widthShare * IW);
      if(f.widthEm > 0.) return (int)(f.widthEm * FL_NORMAL_SIZE);
      return (int)fl_width(_escaped(f.label).c_str()) + 2 * FL_NORMAL_SIZE;
    }
    if(f.kind == Ui::Check)
      return (int)fl_width(_escaped(f.label).c_str()) + (int)(1.8 * FL_NORMAL_SIZE);
    if(f.kind == Ui::Direction) return f.rows * BH;
    // a menu of switches carries its label inside, as a button does
    if(f.kind == Ui::Choice && f.multiple) return _fieldWidth(f, 1);
    // a declared width, or the usual one, plus the label it carries
    int w = f.widthShare > 0. ? (int)(f.widthShare * IW) :
            f.widthEm > 0.    ? (int)(f.widthEm * FL_NORMAL_SIZE) :
                                _fieldWidth(f, 1);
    return w + (int)fl_width(_escaped(f.label).c_str()) + 2 * WB;
  }

  // what the solver of Layout.h is told about this toolkit, in em: the
  // kinds that size themselves are measured by _packedWidth() and
  // _fieldWidth(), the solver holds the rest
  Ui::Metrics _metrics()
  {
    const double em = FL_NORMAL_SIZE;
    Ui::Metrics m;
    m.field = IW / em;
    m.gap = WB / em;
    m.labelGap = 2 * WB / em;
    m.column = WB / em;
    m.after = 0.;
    m.arrow = 2.;
    m.offer = 0.;
    m.row = BH / em;
    // FLTK places at whole pixels
    m.pixel = 1. / em;
    m.widgetWidth = [em](const Ui::Field &f) -> double {
      // a swatch is worth the swatch alone; its name stands beside it
      if(f.kind == Ui::Color) return _fieldWidth(f, 1) / em;
      // a button in the flow of the fields is never narrower than an ordinary
      // one; packed against its neighbours it is as wide as the word on it
      if((f.kind == Ui::Action || f.kind == Ui::Menu) && !f.packed &&
         f.widthEm <= 0. && f.widthShare <= 0.)
        return _fieldWidth(f, 1) / em;
      bool self = f.disclosure || f.kind == Ui::Label ||
                  f.kind == Ui::Action || f.kind == Ui::Menu ||
                  f.kind == Ui::Check || f.kind == Ui::Direction ||
                  (f.kind == Ui::Choice && f.multiple);
      return self ? _packedWidth(f) / em : -1.;
    };
    // the little buttons after a field take their width from the font
    m.trailingWidth = [em](const Ui::Button &t) {
      return (t.label == ":" ? FL_NORMAL_SIZE - 2 : FL_NORMAL_SIZE + 6) / em;
    };
    m.naturalHeight = [](const Ui::Field &f) -> double {
      return f.kind == Ui::Prose ? _proseRows(f) : -1.;
    };
    m.textWidth = [em](const std::string &s) {
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      return (int)fl_width(_escaped(s).c_str()) / em;
    };
    return m;
  }

  // what a list of fields needs, in pixels; the solver says it in em, and
  // the nearest whole pixel is the one meant
  // With every field counted, folded or not, when asked: a window that
  // grows sideways when a part of it is unfolded is a window that will not
  // sit still. Not in a tabbed dialog, whose hidden fields are the other
  // half of an alternative rather than a part folded away.
  int _neededWidth(const std::vector<Ui::Field> &fields, int columns,
                   bool folded = false)
  {
    double em;
    if(folded) {
      std::vector<Ui::Field> all = fields;
      for(auto &f : all) f.visible = nullptr;
      em = Ui::neededWidth(all, columns, _metrics());
    }
    else
      em = Ui::neededWidth(fields, columns, _metrics());
    return (int)(em * FL_NORMAL_SIZE + 0.5);
  }

  // How tall a pane is, so that all of them fit whichever one is shown. The
  // button of a pane sits at its bottom right and shares the last line when
  // the pane is full of fields.
  // the rows of a pane: its own fields, then each section with its heading
  std::size_t _paneRows(const Ui::Pane &q)
  {
    std::size_t rows = _rows(q.fields);
    for(const auto &s : q.sections)
      rows += (s.label.size() ? 1 : 0) + _rows(s.fields);
    return rows;
  }

  int _paneHeight(const Ui::Form &p)
  {
    std::size_t most = (std::size_t)(p.leastRows > 0 ? p.leastRows : 0);
    for(const auto &q : p.panes) {
      // a scrolling pane is not what makes the window tall: it is given what
      // the others need and scrolls the rest
      if(q.scrolling) continue;
      std::size_t n = _paneRows(q);
      if(n > most) most = n;
    }
    if(!most) most = 12;
    return (int)most * BH + 2 * WB;
  }

  // what the window is made of, as opposed to what it holds: the dialog is
  // only built again when this changes, so that re-opening it does not
  // destroy a window that is already on screen
  std::string _signature(const Ui::Form &p)
  {
    std::string s = p.title + (p.tabbed ? "|t" : "|f");
    for(const auto &f : p.side)
      s += "|s" + f.label + ((f.visible && !f.visible()) ? "-" : "");
    for(const auto &q : p.panes) {
      s += "|" + q.label + (q.separatorAfter ? "-" : "") + ":" + q.buttonLabel;
      for(const auto &f : q.fields)
        s += "/" + f.label + (char)('0' + f.kind) + (f.sameRow ? "=" : "");
    }
    for(const auto &f : p.footer)
      s += "//" + f.label + (char)('0' + f.kind) + (f.sameRow ? "=" : "");
    for(const auto &b : p.buttons) s += "|>" + b.label;
    return s;
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
    // a copy, not the field itself: what the field does may build the dialog
    // again, and that is the end of the list this is walking
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
      // a line has just been picked or let go: say which, by where it is in
      // the list the description gave
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
      // the line that was picked is the thing to do
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
        // a list one chooses from: say what is now chosen and what is not
        for(int line = 1; line <= br->size(); line++)
          f.choose(line - 1, br->selected(line) ? true : false);
      }
      else {
        // a list one only shows: a line one clicks is one to be rid of
        int line = br->value();
        if(line > 0 && f.removeItem) f.removeItem(line - 1);
      }
    } break;
    case Ui::Choice: {
      if(f.multiple) {
        // a menu of switches: the one that was picked has just been toggled
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
    if(f.changed) f.changed();
    break;
  }
  // picking in one field can change what the others are
  d->reshape();
}

// the user clicked a tab: the description must follow, or the next
// refresh would put the pane it remembers back
void dialogFltk::_tabCallback(Fl_Widget *w, void *data)
{
  dialogFltk *d = (dialogFltk *)data;
  Fl_Widget *shown = ((Fl_Tabs *)w)->value();
  for(std::size_t i = 0; i < d->_groups.size(); i++) {
    if(d->_groups[i] != shown) continue;
    bool moved = d->_pane != (int)i;
    d->_pane = (int)i;
    d->refresh();
    // the user picked this pane: it may have something to start
    if(moved && i < d->_panel.panes.size() && d->_panel.panes[i].chosen)
      d->_panel.panes[i].chosen();
    return;
  }
  // an outer tab: show the first pane of the family it names
  for(std::size_t g = 0; g < d->_outerGroups.size(); g++) {
    if(d->_outerGroups[g] != shown) continue;
    if(g < d->_firstOfGroup.size() && d->_firstOfGroup[g] >= 0) {
      int first = d->_firstOfGroup[g];
      bool moved = d->_pane != first;
      d->_pane = first;
      d->_forcePane = true;
      d->refresh();
      // picking a family shows its first member, and starts it
      if(moved && first < (int)d->_panel.panes.size() &&
         d->_panel.panes[first].chosen)
        d->_panel.panes[first].chosen();
      return;
    }
    break;
  }
  d->refresh();
}

// what a button of a dialog carries: the dialog it belongs to, so that it
// can be built again when what it did changed its shape, and a copy of
// the thing to do
struct buttonAction {
  dialogFltk *dialog;
  std::function<void()> what;
};

void dialogFltk::_buttonCallback(Fl_Widget *w, void *data)
{
  buttonAction *a = (buttonAction *)data;
  if(!a) return;
  if(a->what) a->what();
  // what it did may have changed the shape of the dialog
  if(a->dialog) a->dialog->reshape();
}

namespace {

  // the little buttons of the fields, kept while the widgets that point at
  // them are alive: FLTK hands a widget a void* when it calls back
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

void dialogFltk::_addFields(const std::vector<Ui::Field> &given, int x,
                            int &y, int w, int pane, int grid, bool folded)
{
  std::vector<Ui::Field> all;
  if(folded) {
    all = given;
    for(auto &f : all) f.visible = nullptr;
  }
  const std::vector<Ui::Field> &fields = folded ? all : given;
  // the solver says where everything goes, in em from (x, y), and this
  // makes the widgets there; the room is how far a line may reach, how deep
  // a field that fills what is left may go, and whether this is the column
  // down the side
  const double em = FL_NORMAL_SIZE;
  Ui::Metrics m = _metrics();
  Ui::Room room;
  room.width = (w - x - WB) / em;
  room.height = ((pane == -2) ? _sideHeight : _paneBottom - y - WB) / em;
  room.wide = pane == -2;
  Ui::Placed placed = Ui::place(fields, grid, m, room);
  // the solver adds up whole pixels; the nearest one is the one meant
  auto px = [em](double v) { return (int)std::floor(v * em + 0.5); };

  for(const auto &p : placed.fields) {
    const Ui::Field &f = fields[p.index];
    int fx = x + px(p.widget.x), fy = y + px(p.widget.y);
    int fieldW = px(p.widget.w), fieldH = px(p.widget.h);

    Fl_Widget *widget = nullptr;
    switch(f.kind) {
    case Ui::Text:
      if(f.dynamicChoices) {
        // what one may want to type, without being held to it
        Fl_Input_Choice *c = new Fl_Input_Choice(fx, fy, fieldW, BH);
        // the group has to answer to everything, since picking from the menu
        // goes through it; the input inside it is told to wait until one has
        // finished typing
        c->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        if(f.commitsWhenDone)
          c->input()->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        widget = c;
      }
      else {
        Fl_Input *in = new Fl_Input(fx, fy, fieldW, BH);
        in->when(f.commitsWhenDone ? (FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY) :
                                     FL_WHEN_CHANGED);
        widget = in;
      }
      break;
    case Ui::Integer:
    case Ui::Number: {
      // the number and the scale are one widget, the number written at its left
      // end
      if(f.slider && f.maximum > f.minimum) {
        Fl_Value_Slider *v = new Fl_Value_Slider(fx, fy, fieldW, BH);
        v->type(FL_HOR_SLIDER);
        v->textsize(FL_NORMAL_SIZE);
        v->bounds(f.minimum, f.maximum);
        if(f.step > 0.) v->step(f.step);
        v->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);
        widget = v;
        break;
      }
      Fl_Value_Input *v = new Fl_Value_Input(fx, fy, fieldW, BH);
      v->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      // the input inside the widget waits until one has finished typing before
      // it says so
      if(f.commitsWhenDone)
        v->input.when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      if(f.maximum > f.minimum) {
        v->minimum(f.minimum);
        v->maximum(f.maximum);
      }
      // the arrows only step where Gmsh is set up for them
      if(f.step > 0. && fltkSources().settings().inputScrolling)
        v->step(f.step);
      widget = v;
    } break;
    case Ui::Check:
      if(f.disclosure)
        // the arrow says which way the fold goes; refresh() sets it
        widget = new Fl_Toggle_Button(fx, fy, fieldW, BH);
      else
        widget = new Fl_Check_Button(fx, fy, fieldW, BH, nullptr);
      break;
    case Ui::Choice:
      if(f.multiple) {
        // several switches behind one button
        Fl_Menu_Button *mb = new Fl_Menu_Button(fx, fy, fieldW, BH);
        widget = mb;
      }
      else
        widget = new Fl_Choice(fx, fy, fieldW, BH);
      break;
    case Ui::Label: {
      // a rule across the pane, and the line written under it
      if(f.rule) {
        Fl_Box *line = new Fl_Box(fx, fy, w - fx - WB, 2);
        line->box(FL_ENGRAVED_FRAME);
        line->labeltype(FL_NO_LABEL);
      }
      // a paragraph is set in from the top of the box it is written in, or the
      // first line touches the frame
      int inset = (f.wraps && f.rows > 1) ? WB / 2 : 0;
      Fl_Box *b = new Fl_Box(fx, fy + (f.rule ? 1 : 0) + inset, fieldW,
                             fieldH - inset);
      b->align(((f.heading || f.centred) ? FL_ALIGN_CENTER : FL_ALIGN_LEFT) |
               FL_ALIGN_INSIDE | (f.wraps ? FL_ALIGN_WRAP | FL_ALIGN_TOP : 0));
      if(f.heading) b->labelfont(FL_HELVETICA_BOLD);
      widget = b;
    } break;
    case Ui::Output: {
      Fl_Output *o = new Fl_Output(fx, fy, fieldW, BH);
      widget = o;
    } break;
    case Ui::Prose: {
      // the page one reads; what is written on it is set in refresh()
      widget = new proseView(fx, fy, fieldW, fieldH);
    } break;
    case Ui::List: {
      // one it only shows, one it chooses from, one or several at a time
      Fl_Browser_ *br;
      if(!f.choose)
        br = new Fl_Select_Browser(fx, fy, fieldW, fieldH);
      else if(f.multiple)
        br = new Fl_Multi_Browser(fx, fy, fieldW, fieldH);
      else
        br = new Fl_Hold_Browser(fx, fy, fieldW, fieldH);
      // a list whose lines are columns says how wide each of them is; the widths
      // have to outlive this call, as the browser keeps the array
      if(f.columnsEm.size()) {
        std::vector<int> *widths = new std::vector<int>;
        for(double wide : f.columnsEm)
          widths->push_back((int)(wide * FL_NORMAL_SIZE));
        widths->push_back(0); // the last column takes what is left
        ((Fl_Browser *)br)->column_widths(widths->data());
        ((Fl_Browser *)br)->column_char('\t');
      }
      // a list down the side of a window is not a box inside it: nothing but a
      // rule on its right, running the whole height of the window
      if(pane == -2) {
        br->box(GMSH_SIMPLE_RIGHT_BOX);
        br->color(FL_BACKGROUND_COLOR);
      }
      br->callback(_fieldCallback, this);
      widget = br;
    } break;
    case Ui::Color: {
      Fl_Button *b = new Fl_Button(fx, fy, fieldW, BH);
      b->box(FL_DOWN_BOX);
      widget = b;
    } break;
    case Ui::Action: {
      Fl_Button *b = new Fl_Button(fx, fy, fieldW, BH);
      // the description owns the action; the window owns a copy of it
      b->callback(_buttonCallback, new buttonAction{this, f.changed});
      widget = b;
    } break;
    case Ui::Menu: {
      // the items are put in when the dialog is refreshed, as they are made
      // then
      Fl_Menu_Button *mb = new Fl_Menu_Button(fx, fy, fieldW, BH);
      widget = mb;
    } break;
    case Ui::Direction:
      // drawn over the lines that follow it rather than pushing them down
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
      // given the whole of its pane
      colorbarWindow *bar = new colorbarWindow(fx, fy, fieldW, fieldH);
      bar->end();
      widget = bar;
    } break;
    case Ui::Spacer: break;
    }
    if(!widget) continue;
    // a widget keeps the pointer it is given rather than the text, so
    // copy_label(); a Label carries its text in the label, which refresh()
    // rewrites at every turn
    if(f.label.size() && f.kind != Ui::Label)
      widget->copy_label(_escaped(f.label).c_str());
    // the inputs and the choices carry their label to their right; a check
    // button and a menu of switches draw it inside, and FL_ALIGN_RIGHT would
    // throw it off
    if(f.kind != Ui::Check && f.kind != Ui::Label && f.kind != Ui::Action &&
       f.kind != Ui::Menu && f.kind != Ui::Direction &&
       f.kind != Ui::ColorMap && f.kind != Ui::Hierarchy &&
       !(f.kind == Ui::Choice && f.multiple))
      widget->align(f.labelBefore ? FL_ALIGN_LEFT : FL_ALIGN_RIGHT);
    // a field to be looked at twice, in red: on a button whose face is dark it
    // is the face that is coloured, on a light one the text
    if(f.alert) {
      if(f.kind == Ui::Action && fltkSources().settings().darkScheme)
        widget->color(FL_DARK_RED);
      else
        widget->labelcolor(FL_DARK_RED);
    }
    if(f.tooltip.size()) widget->copy_tooltip(f.tooltip.c_str());
    widget->callback(_fieldCallback, this);
    bound b;
    // and the little buttons after it, which the label then follows
    for(std::size_t t = 0; t < f.trailing.size() && t < p.trailing.size();
        t++) {
      _kept().push_back(f.trailing[t]);
      Ui::Button *button = &_kept().back();
      Fl_Button *made =
        new Fl_Button(x + px(p.trailing[t].x), fy, px(p.trailing[t].w), BH);
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
    // a field that carries buttons has its name drawn after them, on a box of
    // its own: FLTK draws a name to the right of the widget it belongs to
    if(p.label.w > 0. && !f.labelBefore) {
      widget->label(nullptr);
      Fl_Box *say = new Fl_Box(x + px(p.label.x), fy, px(p.label.w), BH);
      say->copy_label(_escaped(f.label).c_str());
      say->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      b.labelBox = say;
    }
    b.field = given[p.index];
    b.widget = widget;
    b.pane = pane;
    b.index = (int)p.index;
    b.row = (int)p.row;
    b.top = px(p.widget.y);
    _fields.push_back(b);
  }
  _placedHeight = px(placed.height);
  y += _placedHeight;
}

// Rebuild the dialog when its shape has really changed -- and only then:
// rebuilding a window that is already up makes it blink -- keeping it
// where the user left it.
void dialogFltk::reshape()
{
  if(!_which) return;
  Ui::Form now = *_which;
  if(_win && _signature(now) == _signatureBuilt) {
    _panel = now;
    refresh();
    return;
  }
  build(*_which);
  refresh();
}

void dialogFltk::build(const Ui::Form &form)
{
  // Built again, the window stays: it keeps its place and its focus, and
  // only what is inside it is made anew. The old widgets are taken out at
  // once and deleted when the event that asked for this is over -- one of
  // them may be the button whose callback is running.
  bool again = _win != nullptr;
  if(again) {
    while(_win->children()) {
      Fl_Widget *w = _win->child(0);
      _win->remove(w);
      w->hide();
      Fl::delete_widget(w);
    }
  }
  _tabs.clear();
  _groups.clear();
  _outerTabs = nullptr;
  _outerGroups.clear();
  _firstOfGroup.clear();
  _fields.clear();
  _sections.clear();
  _separators.clear();
  _buttons.clear();
  _buttonsEnabled.clear();
  _paneButtons.clear();
  _paneHeights.clear();
  _paneRooms.clear();

  _which = &form;
  _panel = form;
  _signatureBuilt = _signature(_panel);
  // the pane named before there was a form to find it in
  if(_paneWanted.size()) {
    int i = _paneNamed(_paneWanted);
    if(i >= 0) _pane = i;
    _paneWanted.clear();
  }
  // a window that has just been built has no tab of its own yet
  _forcePane = true;

  // one long form rather than tabs: every pane is laid out, one after
  // another; only a first guess, _relayout() gives the window its real
  // height once it knows which panes show
  std::vector<bool> visible;
  for(const auto &q : _panel.panes)
    visible.push_back(!q.visible || q.visible());

  int formH = 0;
  // a form longer than a window scrolls
  _formScrolls = false;
  _formFills = false;
  if(!_panel.tabbed) {
    for(std::size_t i = 0; i < _panel.panes.size(); i++) {
      if(_panel.panes[i].scrolling) _formScrolls = true;
      // and one that holds a field taking whatever is left of it has a height
      // of its own rather than one counted in rows
      for(const auto &f : _panel.panes[i].fields)
        if((f.kind == Ui::List || f.kind == Ui::Hierarchy) && !f.rows)
          _formFills = true;
      if(!visible[i]) continue;
      formH += (_panel.panes[i].label.size() ? BH : 0) +
               _rows(_panel.panes[i].fields) * BH +
               (_panel.panes[i].buttonLabel.size() ? BH : 0) +
               (_panel.panes[i].separatorAfter ? 2 + WB : 0);
    }
    formH += WB;
  }
  // what it is worth at least: a field that fills what is left of the form
  // counts for no rows at all
  if(!_panel.tabbed && _panel.leastRows > 0 && formH < _panel.leastRows * BH)
    formH = _panel.leastRows * BH;
  // and what of it is shown at once, when it is longer than that
  int formShown = formH;
  if(_formScrolls && _panel.leastRows > 0 &&
     formShown > _panel.leastRows * BH)
    formShown = _panel.leastRows * BH;

  // wide enough for the busiest row of every pane, and never so narrow
  // that a dialog with little in it looks starved
  int width = 20 * FL_NORMAL_SIZE;
  // the column of side fields is beside the panes, not part of what they need
  int aside = _panel.side.empty() ?
                0 :
                (int)((_panel.sideEm > 0. ? _panel.sideEm : 8.) *
                      FL_NORMAL_SIZE);
  width += aside;
  for(const auto &q : _panel.panes) {
    int need = _neededWidth(q.fields, q.columns, !_panel.tabbed) + 2 * WB;
    if(need + aside > width) width = need + aside;
    // and for what stands beside its button
    if(q.beside.size()) {
      int line = _neededWidth(q.beside, 0) + 2 * WB + aside +
                 (q.buttonLabel.size() ? BB + WB : 0);
      if(line > width) width = line;
    }
  }
  {
    int need = _neededWidth(_panel.header, 0) + 2 * WB + aside;
    if(need > width) width = need;
  }
  {
    int need = _neededWidth(_panel.footer, 0) + 2 * WB + aside;
    // when the buttons share the last line of the footer, they need their room
    // on it too
    if(_panel.buttonsInFooter)
      need += (int)_panel.buttons.size() * (BB + WB);
    if(need > width) width = need;
  }
  // and wide enough for the names of the panes: a form writes each of them as
  // a heading over its pane, so the widest of them has to fit
  if(!_panel.tabbed) {
    fl_font(FL_HELVETICA_BOLD, FL_NORMAL_SIZE);
    for(const auto &q : _panel.panes) {
      if(q.visible && !q.visible()) continue;
      int need = (int)fl_width(q.label.c_str()) + 4 * WB + aside;
      if(need > width) width = need;
    }
  }
  // and wide enough for the row of tabs itself, or the last of them hides
  // behind a pulldown
  if(_panel.tabbed) {
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    std::map<std::string, int> rows;
    for(const auto &q : _panel.panes) {
      if(q.visible && !q.visible()) continue;
      rows[q.group] += (int)fl_width(_escaped(q.label).c_str()) +
                       (int)(1.2 * FL_NORMAL_SIZE);
    }
    for(const auto &row : rows) {
      // and the room FLTK keeps at the end of the row for the arrow it offers
      // when the tabs do not fit
      int need = row.second + aside + 2 * WB + 2 * FL_NORMAL_SIZE;
      if(need > width) width = need;
    }
  }
  // a dialog whose panes change keeps the width the widest of them asked
  // for, so that it sits still
  if(width > _widestSeen)
    _widestSeen = width;
  else
    width = _widestSeen;
  int paneH = _paneHeight(_panel);
  int headerH = _rows(_panel.header) * BH;
  int footerH = _rows(_panel.footer) * BH;
  if(_panel.footer.size()) footerH += WB;
  int gathered = 0;
  for(const auto &b : _panel.buttons)
    if(!b.apart) gathered++;
  _mergedButtons = _panel.buttonsInFooter && _panel.footer.size() &&
                   _panel.buttons.size();
  int buttonH = (_panel.buttons.size() && !_mergedButtons) ? BH + WB : 0;
  int tabRows = 1;
  for(const auto &q : _panel.panes)
    if(q.group.size()) tabRows = 2;
  int height = (_panel.tabbed ? paneH + tabRows * BH : formShown) + headerH +
               footerH + buttonH + 2 * WB;

  // a window created while a group is open becomes a child of that group
  Fl_Group *previous = Fl_Group::current();
  Fl_Group::current(nullptr);

  if(again) {
    _win->size(width, height);
    _win->copy_label(_panel.title.c_str());
    if(dialogWindow *w = dynamic_cast<dialogWindow *>(_win))
      w->closed = _panel.closed;
    _win->begin();
  }
  else {
    dialogWindow *win = new dialogWindow(
      width, height, fltkSources().settings().nonModalWindows,
      _panel.title.c_str());
    win->closed = _panel.closed;
    _win = win;
    _win->box(GMSH_WINDOW_BOX);
  }

  // the column of side fields, down the whole left edge, as wide as the panel
  // says it has to be
  _sideWidth = _panel.side.empty() ?
                 0 :
                 (int)((_panel.sideEm > 0. ? _panel.sideEm : 8.) *
                       FL_NORMAL_SIZE);
  if(_sideWidth) {
    int sy = WB;
    _sideHeight = height - 2 * WB;
    _addFields(_panel.side, WB, sy, _sideWidth, -2);
  }

  int y = WB;

  // what the panes are about, over the whole width of them
  if(_panel.header.size())
    _addFields(_panel.header, _sideWidth + 2 * WB, y, width, -1);

  if(!_panel.tabbed) {
    // a form that scrolls: its panes are laid out as they always are, and what
    // does not fit is under the bottom of the box rather than under the bottom
    // of the window
    Fl_Scroll *form = nullptr;
    if(_formScrolls) {
      form = new Fl_Scroll(WB, y, width - 2 * WB, formShown);
      form->type(Fl_Scroll::VERTICAL);
      form->box(FL_FLAT_BOX);
    }
    // where a field that fills what is left of the form ends
    _paneBottom = y + formShown;
    // every pane is built, whether it shows or not: folding one away is then
    // only a matter of moving what is left
    for(std::size_t i = 0; i < _panel.panes.size(); i++) {
      const Ui::Pane &q = _panel.panes[i];
      Fl_Box *b = nullptr;
      if(q.label.size()) {
        b = new Fl_Box(WB, y, width - 2 * WB, BH);
        b->copy_label(_plain(q.label).c_str());
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        b->labelfont(FL_HELVETICA_BOLD);
        y += BH;
      }
      _sections.push_back(b);
      // a form that scrolls ends before its scrollbar, or what it puts at its
      // right edge is drawn under it
      // from WB in, to WB short of the edge: what the window was sized for
      _addFields(q.fields, WB, y, width - (form ? Fl::scrollbar_size() : 0),
                 (int)i, q.columns, true);
      _paneRooms.push_back(
        {WB, width - (form ? Fl::scrollbar_size() : 0), q.columns});
      int placed = _placedHeight;
      if(q.buttonLabel.size()) {
        // at the right of the line, or at its far left when it stands apart
        int bx = q.buttonApart ? WB : width - BB - WB;
        Fl_Button *pb = new Fl_Button(bx, y, BB, BH);
        pb->copy_label(_escaped(q.buttonLabel).c_str());
        pb->callback(_buttonCallback, new buttonAction{this, q.button});
        _paneButtons.push_back({pb, (int)i, placed});
        y += BH;
        placed += BH;
      }
      _paneHeights.push_back(placed);
      // the rule between two groups
      Fl_Box *line = nullptr;
      if(q.separatorAfter) {
        // as much room above the rule as below it, or a button ending the
        // group sits right on top of it
        y += WB;
        line = new Fl_Box(WB, y, width - 2 * WB, 2);
        line->box(FL_ENGRAVED_FRAME);
        line->labeltype(FL_NO_LABEL);
        y += 2 + WB;
      }
      _separators.push_back(line);
    }
    if(form) {
      form->end();
      y = form->y() + form->h();
    }
    // a field that fills the form ends at the bottom of the form: what
    // follows has to start under that and not under the rows
    if(_formFills && y < _paneBottom) y = _paneBottom;
    y += WB;
  }

  if(_panel.tabbed) {
    // the panes of a dialog with more of them than fit across one row are
    // gathered into families, and the rows of tabs are nested; a pane that
    // belongs to no family keeps a tab of its own in the first row
    struct entry {
      std::string family;
      std::vector<std::size_t> panes;
    };
    std::vector<entry> outer;
    bool nested = false;
    for(std::size_t i = 0; i < _panel.panes.size(); i++) {
      const std::string &family = _panel.panes[i].group;
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

    int rows = nested ? 2 : 1;
    _groups.resize(_panel.panes.size(), nullptr);

    if(nested) {
      _outerTabs = new Fl_Tabs(_sideWidth + WB, y, width - _sideWidth - 2 * WB,
                               paneH + rows * BH);
      _outerTabs->callback(_tabCallback, this);
      _outerTabs->handle_overflow(Fl_Tabs::OVERFLOW_PULLDOWN);
    }

    auto addPane = [&](std::size_t i, int top, int height) {
      const Ui::Pane &q = _panel.panes[i];
      Fl_Group *pg =
        new Fl_Group(_sideWidth + WB, top, width - _sideWidth - 2 * WB, height);
      pg->copy_label(_plain(q.label).c_str());
      int fy = top + WB;
      // the button of the pane keeps the last line to itself: the fields have
      // what is above it
      int room = height - (q.buttonLabel.size() ? BH + WB : 0);
      // a long pane scrolls rather than making the window as tall as it is
      Fl_Scroll *scroll = nullptr;
      if(q.scrolling) {
        scroll = new Fl_Scroll(_sideWidth + WB, top, width - _sideWidth - 2 * WB,
                               room);
        scroll->type(Fl_Scroll::VERTICAL);
        scroll->box(FL_FLAT_BOX);
      }
      // one that scrolls ends before its scrollbar, or what it puts at its
      // right edge is drawn under it
      int right = width - 2 * WB - (q.scrolling ? Fl::scrollbar_size() : 0);
      // and where it ends, for a field that fills what is left of it
      _paneBottom = top + room;
      _addFields(q.fields, _sideWidth + 2 * WB, fy, right, (int)i, q.columns);
      // the titled sections under them
      for(const auto &section : q.sections) {
        if(section.label.size()) {
          Fl_Box *b = new Fl_Box(_sideWidth + 2 * WB, fy,
                                 width - _sideWidth - 4 * WB, BH);
          b->copy_label(_plain(section.label).c_str());
          b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
          b->labelfont(FL_HELVETICA_BOLD);
          fy += BH;
        }
        _addFields(section.fields, _sideWidth + 2 * WB, fy, right, (int)i,
                   section.columns);
      }
      if(scroll) scroll->end();
      // what stands on the line of the button, to its left and outside what
      // scrolls above it
      if(q.beside.size()) {
        int by = top + height - BH - WB;
        _addFields(q.beside, _sideWidth + 2 * WB, by,
                   width - (q.buttonLabel.size() ? BB + WB : 0), (int)i);
      }
      if(q.buttonLabel.size()) {
        // at the bottom right of the pane, or at the bottom left for the one that
        // stands apart
        int bx = q.buttonApart ? 2 * WB : width - BB - 2 * WB;
        Fl_Button *b = new Fl_Button(bx, top + height - BH - WB, BB, BH);
        // a widget keeps the pointer it is given rather than the text, so the
        // label cannot be a temporary
        b->copy_label(_escaped(q.buttonLabel).c_str());
        // the description owns the action; the window owns a copy of it
        b->callback(_buttonCallback, new buttonAction{this, q.button});
      }
      pg->end();
      _groups[i] = pg;
    };

    if(!nested) {
      Fl_Tabs *tabs = new Fl_Tabs(_sideWidth + WB, y, width - _sideWidth - 2 * WB,
                                  paneH + BH);
      tabs->callback(_tabCallback, this);
      tabs->handle_overflow(Fl_Tabs::OVERFLOW_PULLDOWN);
      _tabs.push_back(tabs);
      for(std::size_t i = 0; i < _panel.panes.size(); i++)
        addPane(i, y + BH, paneH);
      tabs->end();
    }
    else {
      for(const auto &e : outer) {
        if(e.family.empty()) {
          // a lone pane: it is the tab of the first row, and it has the room
          // the second row would have taken
          addPane(e.panes[0], y + BH, paneH + BH);
          _outerGroups.push_back(_groups[e.panes[0]]);
          _firstOfGroup.push_back((int)e.panes[0]);
          continue;
        }
        Fl_Group *og = new Fl_Group(WB, y + BH, width - 2 * WB, paneH + BH);
        // copy_label: fltk keeps the pointer it is given, and the names are
        // built here
        og->copy_label(_plain(e.family).c_str());
        _outerGroups.push_back(og);
        _firstOfGroup.push_back((int)e.panes[0]);
        Fl_Tabs *tabs = new Fl_Tabs(WB, y + BH, width - 2 * WB, paneH + BH);
        tabs->callback(_tabCallback, this);
        tabs->handle_overflow(Fl_Tabs::OVERFLOW_PULLDOWN);
        _tabs.push_back(tabs);
        for(std::size_t i : e.panes) addPane(i, y + 2 * BH, paneH);
        tabs->end();
        og->end();
      }
    }
    if(_outerTabs) _outerTabs->end();
    y += paneH + rows * BH;
  }

  int buttonY = y;

  if(_panel.footer.size()) {
    y += WB;
    int footerTop = y;
    _addFields(_panel.footer, _sideWidth + 2 * WB, y, width, -1);
    _footerHeight = _placedHeight;
    buttonY = _mergedButtons ? footerTop : y;
  }

  if(_panel.buttons.size()) {
    // gathered at the right in the order they were declared, so that the last
    // one ends against the edge; those that stand apart go to the far left
    y = buttonY;
    int rx = width - WB - gathered * BB - (gathered - 1) * WB;
    int bx = WB;
    for(const auto &b : _panel.buttons) {
      int at = b.apart ? bx : rx;
      (b.apart ? bx : rx) += BB + WB;
      Fl_Button *w;
      if(b.isDefault)
        w = new Fl_Return_Button(at, y, BB, BH);
      else
        w = new Fl_Button(at, y, BB, BH);
      w->copy_label(_escaped(b.label).c_str());
      w->callback(_buttonCallback, new buttonAction{this, b.action});
      _buttons.push_back(w);
      _buttonsEnabled.push_back(b.enabled);
    }
    y += BH + WB;
  }

  if(!again) {
    const Ui::Backend::Settings set = fltkSources().settings();
    _win->position(set.dialogX, set.dialogY);
  }
  _win->end();
  Fl_Group::current(previous);

  _byOption.clear();
  for(std::size_t i = 0; i < _fields.size(); i++)
    if(_fields[i].field.option.size())
      _byOption.emplace(_fields[i].field.option, i);

  refresh();
  _win->redraw();
}

// a dialog that watches something asks to be refreshed on a timer: FLTK
// draws only when something happens
void dialogFltk::_tick(void *data)
{
  dialogFltk *d = (dialogFltk *)data;
  if(!d->shown()) return; // it stops with the window and starts with it again
  d->refresh();
  Fl::repeat_timeout(d->_panel.refreshEvery, _tick, data);
}

namespace {

  // the paths of the lines, kept while the tree that points at them is
  // alive: an Fl_Tree item carries a void*
  std::deque<std::string> _treePaths;

  // down the model, unfolding as it goes: the item remembers which line of
  // the description it stands for
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
    // written again only when it really changed: writing it is drawing it
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
    int keep = br->value();
    br->clear();
    if(f.dynamicChoices) {
      std::vector<std::string> labels;
      std::vector<int> values;
      f.dynamicChoices(labels, values);
      for(auto &l : labels) br->add(l.c_str());
      for(int k = 0; f.chosen && k < (int)labels.size(); k++)
        if(f.chosen(k)) br->select(k + 1);
    }
    else if(f.list) {
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
    // rebuilt only when the shape has changed: an Fl_Tree that is built again
    // forgets what was open
    std::string signature = std::to_string(said.generation ?
                                             said.generation() : 0);
    if(signature != b.was) {
      b.was = signature;
      // clear() takes the root with it, and everything hangs from the root
      tree->clear();
      Fl_Tree_Item *root = new Fl_Tree_Item(tree);
      root->label(_plain(f.label.size() ? f.label : "Gmsh").c_str());
      tree->root(root);
      _addBranch(tree, root, said, "");
    }
    // and what of it is picked, which changes without the shape changing
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
  case Ui::Number:
    ((Fl_Valuator *)b.widget)->value(f.getNumber());
    break;
  case Ui::Check: {
    bool on = f.getFlag();
    ((Fl_Button *)b.widget)->value(on ? 1 : 0);
    // the arrow of a disclosure points at what clicking it would do
    if(f.disclosure) {
      std::string label = _escaped(f.label) + (on ? " @-28->" : " @-22->");
      if(!b.widget->label() || label != b.widget->label())
        b.widget->copy_label(label.c_str());
    }
  } break;
  case Ui::Choice: {
    if(f.multiple) {
      // a menu of switches, each showing whether it is on
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
  for(std::size_t i = 0; i < _buttons.size() && i < _buttonsEnabled.size(); i++) {
    if(!_buttonsEnabled[i]) continue;
    if(_buttonsEnabled[i]())
      _buttons[i]->activate();
    else
      _buttons[i]->deactivate();
  }
  if(!_panel.tabbed) _relayout();

  int shownPane = _pane;
  for(std::size_t i = 0; _panel.tabbed && i < _groups.size(); i++) {
    if((int)i == shownPane) {
      _groups[i]->show();
      _groups[i]->activate();
    }
    else {
      _groups[i]->hide();
      _groups[i]->deactivate();
    }
  }
  // the tab row that holds the pane must be the visible one, but only when the
  // pane has just been asked for
  if(_forcePane) {
    _forcePane = false;
    if(shownPane >= 0 && shownPane < (int)_groups.size() && _groups[shownPane]) {
      // the row of tabs that holds it, and the family that holds that row
      Fl_Group *pane = _groups[shownPane];
      for(auto *t : _tabs)
        if(t->find(pane) < t->children()) t->value(pane);
      if(_outerTabs) {
        for(auto *og : _outerGroups)
          if(og == pane || og->find(pane->parent()) < og->children())
            _outerTabs->value(og);
      }
    }
  }

  for(auto &b : _fields) _refreshField(b);
  if(_win) _win->redraw();
}

void dialogFltk::optionChanged(const std::string &name)
{
  auto range = _byOption.equal_range(name);
  for(auto it = range.first; it != range.second; ++it)
    _refreshField(_fields[it->second]);
  if(range.first != range.second && _win) _win->redraw();
}

void dialogFltk::_relayout()
{
  // a form that scrolls has nothing that folds, and neither has one whose
  // fields are as tall as the window is
  if(!_win || _panel.tabbed || _formScrolls || _formFills) return;

  std::vector<bool> visible;
  for(const auto &q : _panel.panes)
    visible.push_back(!q.visible || q.visible());

  // The fields of a pane, placed again with what is folded away taking no
  // room: each widget goes where the solver now puts it, or hides.
  const double em = FL_NORMAL_SIZE;
  auto px = [em](double v) { return (int)std::floor(v * em + 0.5); };
  Ui::Metrics m = _metrics();
  for(std::size_t i = 0; i < _panel.panes.size() && i < _paneRooms.size(); i++) {
    const Ui::Pane &q = _panel.panes[i];
    Ui::Room room;
    room.width = (_paneRooms[i].w - _paneRooms[i].x - WB) / em;
    room.height = 1e6;
    Ui::Placed placed = Ui::place(q.fields, _paneRooms[i].grid, m, room);
    std::map<int, const Ui::PlacedField *> at;
    for(const auto &p : placed.fields) at[(int)p.index] = &p;
    for(auto &b : _fields) {
      if(b.pane != (int)i) continue;
      auto found = at.find(b.index);
      if(found == at.end()) {
        b.widget->hide();
        if(b.labelBox) b.labelBox->hide();
        for(auto *t : b.trailing) t->hide();
        continue;
      }
      const Ui::PlacedField &p = *found->second;
      int x = _paneRooms[i].x;
      b.top = px(p.widget.y);
      b.widget->resize(x + px(p.widget.x), b.widget->y(), px(p.widget.w),
                       b.widget->h());
      if(b.labelBox)
        b.labelBox->resize(x + px(p.label.x), b.labelBox->y(), px(p.label.w),
                           b.labelBox->h());
      for(std::size_t t = 0; t < b.trailing.size() && t < p.trailing.size(); t++)
        b.trailing[t]->resize(x + px(p.trailing[t].x), b.trailing[t]->y(),
                              px(p.trailing[t].w), b.trailing[t]->h());
    }
    int height = px(placed.height);
    for(const auto &pb : _paneButtons)
      if(pb.pane == (int)i) height += BH;
    if(i < _paneHeights.size()) _paneHeights[i] = height;
  }

  // where each pane starts, once the folded ones take no room
  std::vector<int> top(_panel.panes.size(), 0);
  int y = WB;
  for(std::size_t i = 0; i < _panel.panes.size(); i++) {
    if(i < _sections.size() && _sections[i]) {
      if(visible[i]) {
        _sections[i]->position(_sections[i]->x(), y);
        _sections[i]->show();
        y += BH;
      }
      else
        _sections[i]->hide();
    }
    top[i] = y;
    if(visible[i] && i < _paneHeights.size()) y += _paneHeights[i];
    if(i < _separators.size() && _separators[i]) {
      if(visible[i]) {
        y += WB;
        _separators[i]->position(_separators[i]->x(), y);
        _separators[i]->show();
        y += 2 + WB;
      }
      else
        _separators[i]->hide();
    }
  }
  y += WB;
  int footerTop = y;
  int buttonTop = footerTop;
  y += _panel.footer.size() ? _footerHeight : 0;
  if(!_mergedButtons) buttonTop = y;

  for(auto &b : _fields) {
    int at = (b.pane < 0) ? footerTop : top[b.pane];
    bool show = ((b.pane < 0) || visible[b.pane]) &&
                !(b.field.visible && !b.field.visible());
    b.widget->position(b.widget->x(), at + b.top);
    if(b.labelBox) b.labelBox->position(b.labelBox->x(), at + b.top);
    for(auto *t : b.trailing) t->position(t->x(), at + b.top);
    if(show) {
      b.widget->show();
      if(b.labelBox) b.labelBox->show();
      for(auto *t : b.trailing) t->show();
    }
    else {
      b.widget->hide();
      if(b.labelBox) b.labelBox->hide();
      for(auto *t : b.trailing) t->hide();
    }
  }

  for(auto &b : _paneButtons) {
    b.widget->position(b.widget->x(), top[b.pane] + b.top);
    if(visible[b.pane])
      b.widget->show();
    else
      b.widget->hide();
  }

  if(_buttons.size()) {
    for(auto *w : _buttons) w->position(w->x(), buttonTop);
    if(!_mergedButtons) y += BH + WB;
  }

  if(_win->h() != y) _win->size(_win->w(), y);
  _win->redraw();
}

void dialogFltk::show()
{
  // built again only when its shape really changed: rebuilding a window
  // that is already up makes it blink and come back somewhere else
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

int dialogFltk::_paneNamed(const std::string &label) const
{
  for(std::size_t i = 0; i < _panel.panes.size(); i++)
    if(_panel.panes[i].label == label) return (int)i;
  return -1;
}

std::string dialogFltk::pane() const
{
  if(!_win) return _paneWanted;
  if(_pane >= 0 && _pane < (int)_panel.panes.size())
    return _panel.panes[_pane].label;
  return "";
}

void dialogFltk::setPane(const std::string &pane)
{
  int i = _win ? _paneNamed(pane) : -1;
  if(i < 0) {
    _paneWanted = pane;
    return;
  }
  _pane = i;
  _forcePane = true;
}

namespace {
  // a map keeps the addresses steady, which the widgets built for a dialog
  // rely on
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

#endif
