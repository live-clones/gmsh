// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "uiSources.h"
#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <algorithm>
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
#include "dialogFltk.h"
#include "menuFltk.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "Context.h"

// While the interface is being taken down every window is hidden in turn, and
// a dialog that undoes something when it closes must not undo it then: there
// is no view left to draw the undoing into.
static bool _closingDown = false;

void fltkDialogsClosingDown() { _closingDown = true; }

// A window that tells the description it has gone. FLTK calls the callback of
// a window only when the user closes it; a dialog that leaves something
// behind -- the ONELAB context window highlights the entity it is about --
// has to hear about every way of hiding it.
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
  int _rows(const std::vector<Ui::Field> &fields)
  {
    int rows = 0;
    for(std::size_t i = 0; i < fields.size(); i++) {
      if(fields[i].sameRow && i) continue;
      if(fields[i].visible && !fields[i].visible()) continue;
      // a list, a tree, a colour map and a line that wraps are worth as many
      // lines as they show
      rows += (fields[i].kind == Ui::List ||
               fields[i].kind == Ui::Hierarchy ||
               fields[i].kind == Ui::ColorMap ||
               (fields[i].kind == Ui::Label && fields[i].wraps)) ?
                fields[i].rows :
                1;
    }
    return rows;
  }

  // FLTK reads "&" in a label as the mark of a keyboard shortcut and does not
  // draw it. A label is text here, so an ampersand has to be doubled to come
  // out as one -- "Colours & light" is a tab, not a shortcut.
  // ...and only those widgets: a plain box, a group, a tab and a line of a
  // tree draw what they are given. FLTK says which -- the menus, the buttons
  // and the inputs read the ampersand; nothing else does -- and doubling it
  // for the others would put two of them on the screen.
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

  // An entry of a menu goes through the same reading, and "/" opens a submenu
  // there, "\\" escapes the next character: a choice named "Volume and surface"
  // is safe, one named "1/2" would not be.
  std::string _escapedMenu(const std::string &label)
  {
    std::string out;
    for(char c : label) {
      if(c == '&' || c == '/' || c == '\\') out += '\\';
      out += c;
    }
    return out;
  }

  // What a pane on a grid needs to show everything, trailing labels included:
  // they run past their column, but not past the window.
  int _gridWidth(const std::vector<Ui::Field> &fields, int grid);

  // How wide a field's widget has to be. Alone on its line an input gets the
  // usual width, otherwise a narrower one so that several fit. A choice gets
  // the same as an input: sizing it to the longest thing it offers makes it
  // wider than the fields above and below it, and their labels no longer line
  // up. The windows this replaces give a choice a plain IW too, and let a long
  // entry be clipped; one that really needs more says so with widthEm.
  int _fieldWidth(const Ui::Field &f, int columns)
  {
    if(f.disclosure) return BB;
    if(f.kind == Ui::Spacer) return 0;
    if(f.kind == Ui::Action || f.kind == Ui::Menu) {
      // a button is as wide as the text it carries inside, never narrower
      // than an ordinary one
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      int need = (int)fl_width(_escaped(f.label).c_str()) + 2 * FL_NORMAL_SIZE;
      return (need > BB) ? need : BB;
    }
    if(f.kind == Ui::Label) {
      // one that says how wide it is takes that; one that wraps and does not
      // takes the width of an ordinary field, whatever it says
      if(f.widthEm > 0.) return (int)(f.widthEm * FL_NORMAL_SIZE);
      if(f.wraps) return IW;
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      return (int)fl_width(f.getText().c_str()) + FL_NORMAL_SIZE;
    }
    if(f.kind == Ui::Check) return (int)(1.5 * FL_NORMAL_SIZE);
    // A field that says how wide it is takes that, whatever kind it is:
    // nothing about a line of text says how wide the list holding it should
    // be, and the menu of a window that is one menu wide is as wide as the
    // window.
    if(f.widthEm > 0.) return (int)(f.widthEm * FL_NORMAL_SIZE);
    // a swatch says what it is by its colour; it needs no room for text
    if(f.kind == Ui::Color) return (int)(3. * FL_NORMAL_SIZE);
    // the disc of a direction is square, as tall as the lines it hangs over
    if(f.kind == Ui::Direction) return f.rows * BH;
    // a colour map takes the pane it is in
    if(f.kind == Ui::ColorMap) return IW;
    return (columns == 1) ? IW : IW / 2;
  }

  // What a packed field needs: its own text and no more. It takes the width it
  // asks for rather than a share of the line.
  int _packedWidth(const Ui::Field &f)
  {
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    if(f.kind == Ui::Spacer)
      return (int)((f.widthEm > 0. ? f.widthEm : 2.) * FL_NORMAL_SIZE);
    if(f.disclosure) return BB;
    if(f.kind == Ui::Label) {
      // one that says how wide it is takes that: a column of keys is a column
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

  // Whether the field at k shares its cell with the one after it: consecutive
  // fields that declare a share of a field's width are one cell, and all but
  // the last of them sit flush against the next, so that the cell measures
  // exactly what one field would.
  bool _sharesCell(const std::vector<Ui::Field> &fields, std::size_t k,
                   std::size_t to)
  {
    return fields[k].widthShare > 0. && k + 1 < to &&
           fields[k + 1].widthShare > 0.;
  }

  // how far the next field starts from this one, when this one is packed
  int _packedStep(const std::vector<Ui::Field> &fields, std::size_t k,
                  std::size_t to)
  {
    if(_sharesCell(fields, k, to)) return (int)(fields[k].widthShare * IW);
    return _packedWidth(fields[k]) + WB;
  }

  // Where the columns of a pane laid out on a grid start, and how wide each
  // of them is: a column is as wide as the widest thing in it, its label
  // included, and not as wide as the widest thing in the pane.
  std::vector<int> _gridColumns(const std::vector<Ui::Field> &fields,
                                int grid)
  {
    std::vector<int> width((std::size_t)grid, 0);
    int column = 0;
    for(std::size_t k = 0; k < fields.size(); k++) {
      const Ui::Field &f = fields[k];
      if(!f.sameRow)
        column = 0;
      else if(!f.packed)
        column++;
      if(column >= grid) column = grid - 1;
      if(f.kind == Ui::Spacer) continue;
      if(f.visible && !f.visible()) continue;
      // What follows it inside the same column adds to it. Its label only
      // needs room if another column follows on the same row: the label of
      // the last field of a row runs on into the space no one else uses,
      // which is what keeps the columns as narrow as the window this
      // replaces has them.
      // where the line this field is on ends, so that the cells packed
      // against it can be stepped over the way they are placed
      std::size_t end = k + 1;
      while(end < fields.size() && fields[end].sameRow) end++;
      int need = 0;
      std::size_t j = k;
      bool more = false;
      while(j < fields.size() && (j == k || (fields[j].sameRow && fields[j].packed))) {
        bool last = !(j + 1 < fields.size() && fields[j + 1].sameRow &&
                      fields[j + 1].packed);
        need += last ? _packedWidth(fields[j]) : _packedStep(fields, j, end);
        j++;
      }
      if(j < fields.size() && fields[j].sameRow) more = true;
      if(!more) {
        // Take the last of them back off: its label runs on into the space no
        // one else uses. One that carries its text inside comes off whole --
        // a line of a pane that is nothing but a switch is as wide as the
        // switch says, and that is no reason to push the second column of
        // every other line across.
        const Ui::Field &l = fields[j - 1];
        fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
        if(l.kind == Ui::Check || l.kind == Ui::Action ||
           l.kind == Ui::Menu || l.kind == Ui::Label ||
           l.kind == Ui::Direction ||
           (l.kind == Ui::Choice && l.multiple))
          need -= _packedWidth(l);
        else
          need -= (int)fl_width(_escaped(l.label).c_str()) + 2 * WB;
      }
      if(need > width[(std::size_t)column]) width[(std::size_t)column] = need;
    }
    return width;
  }

  // How much room the labels that come before their field take, column by
  // column: they are written to the left of the field, and the fields of a
  // column line up when every one of them starts after the widest of them.
  std::vector<int> _gridLabelsBefore(const std::vector<Ui::Field> &fields,
                                     int grid)
  {
    std::vector<int> width((std::size_t)(grid > 0 ? grid : 1), 0);
    int column = 0;
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    for(std::size_t k = 0; k < fields.size(); k++) {
      const Ui::Field &f = fields[k];
      if(!f.sameRow)
        column = 0;
      else if(!f.packed)
        column++;
      if(column >= (int)width.size()) column = (int)width.size() - 1;
      if(!f.labelBefore || f.label.empty()) continue;
      int need = (int)fl_width(_escaped(f.label).c_str()) + WB;
      if(need > width[(std::size_t)column]) width[(std::size_t)column] = need;
    }
    return width;
  }

  int _gridWidth(const std::vector<Ui::Field> &fields, int grid)
  {
    std::vector<int> column = _gridColumns(fields, grid);
    int widest = 0, at = 0, which = 0;
    for(std::size_t k = 0; k < fields.size(); k++) {
      const Ui::Field &f = fields[k];
      // what a spacer pushes to the right end of a line does not start at a
      // column: the line only has to be as wide as what is really on it
      bool loose = k && fields[k].sameRow &&
                   fields[k - 1].kind == Ui::Spacer;
      if(!f.sameRow) {
        which = 0;
        at = 0;
      }
      else if(loose) {
        // it goes on from where the field before the spacer ended
      }
      else if(!f.packed) {
        which++;
        at = 0;
        for(int c = 0; c < which && c < grid; c++) at += column[(std::size_t)c];
      }
      // a spacer takes at least what it asks for, and what follows it comes
      // after that: a row ending in one is as wide as all of them together
      if(f.kind == Ui::Spacer) {
        at += _packedWidth(f) + WB;
        continue;
      }
      int end = at + _packedWidth(f);
      if(end > widest) widest = end;
      // what follows it on the same line starts where it ends, whether it is
      // packed against it or pushed to the right end by a spacer
      bool more = k + 1 < fields.size() && fields[k + 1].sameRow;
      if(more && (f.packed || fields[k + 1].kind == Ui::Spacer))
        at += _packedWidth(f) + WB;
    }
    return widest;
  }

  // how much of a line the packed fields take, spacing included
  int _packedTotal(const std::vector<Ui::Field> &fields, std::size_t from,
                   std::size_t to)
  {
    int total = 0;
    for(std::size_t k = from; k < to; k++)
      if(fields[k].packed || fields[k].kind == Ui::Spacer)
        total += _packedStep(fields, k, to);
    return total;
  }

  // the width one line needs, labels included
  int _rowWidth(const std::vector<Ui::Field> &fields, std::size_t from,
                std::size_t to, int &columnW)
  {
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    int columns = 0;
    for(std::size_t k = from; k < to; k++)
      if(!fields[k].packed && fields[k].kind != Ui::Spacer) columns++;
    columnW = 0;
    for(std::size_t k = from; k < to; k++) {
      if(fields[k].packed || fields[k].kind == Ui::Spacer) continue;
      if(fields[k].visible && !fields[k].visible()) continue;
      // a plain line and a button carry their text inside
      int label = (fields[k].kind == Ui::Label ||
                   fields[k].kind == Ui::Menu ||
                   fields[k].kind == Ui::Action) ?
                    0 :
                    (int)fl_width(fields[k].label.c_str());
      int need = _fieldWidth(fields[k], columns) + label + 3 * WB;
      if(need > columnW) columnW = need;
    }
    return columns * columnW + _packedTotal(fields, from, to);
  }

  // What the fields need, labels included. The windows this replaces sized
  // themselves by hand; here the description does not say how wide anything is,
  // so it is measured.
  int _neededWidth(const std::vector<Ui::Field> &fields)
  {
    int widest = 0;
    std::size_t i = 0;
    while(i < fields.size()) {
      std::size_t last = i + 1;
      while(last < fields.size() && fields[last].sameRow) last++;
      int columnW = 0;
      int row = _rowWidth(fields, i, last, columnW);
      if(row > widest) widest = row;
      i = last;
    }
    return widest;
  }

  // How tall a pane is, so that all of them fit whichever one is shown. The
  // button of a pane sits at its bottom right and is not given a line of its
  // own: with a pane full of fields it shares the last one, as the window this
  // replaces has it.
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

  // What the window is made of, as opposed to what it holds: the dialog is only
  // built again when this changes, so that re-opening it does not destroy a
  // window that is already on screen and put a new one somewhere else.
  std::string _signature(const Ui::Form &p)
  {
    std::string s = p.title + (p.tabbed ? "|t" : "|f");
    for(const auto &f : p.side)
      s += "|s" + f.label + ((f.visible && !f.visible()) ? "-" : "");
    for(const auto &q : p.panes) {
      s += "|" + q.label + (q.separatorAfter ? "-" : "") + ":" + q.buttonLabel;
      for(const auto &f : q.fields)
        s += "/" + f.label + (char)('0' + f.kind) + (f.sameRow ? "=" : "") +
             ((f.visible && !f.visible()) ? "-" : "");
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
    // A copy, not the field itself: what the field does may build the dialog
    // again -- picking a plugin changes the options shown -- and that is the
    // end of the list this is walking.
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
      f.setNumber(((Fl_Value_Input *)w)->value());
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
      // A line has just been picked or let go: say which, by where it is in
      // the list the description gave. The item carries that place.
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
  // picking in one field can change what the others are: the plugin window
  // shows the options of the plugin one picks
  d->reshape();
}

// the user clicked a tab: the description must follow, or the next refresh
// would put the pane it remembers back
void dialogFltk::_tabCallback(Fl_Widget *w, void *data)
{
  dialogFltk *d = (dialogFltk *)data;
  Fl_Widget *shown = ((Fl_Tabs *)w)->value();
  for(std::size_t i = 0; i < d->_groups.size(); i++) {
    if(d->_groups[i] != shown) continue;
    bool moved = uiSources().formPane(d->_which) != (int)i;
    uiSources().setFormPane(d->_which, (int)i);
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
      bool moved = uiSources().formPane(d->_which) != first;
      uiSources().setFormPane(d->_which, first);
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

// What a button of a dialog carries: the dialog it belongs to, so that it can
// be built again when what it did changed its shape, and the thing to do. The
// description owns the action; the window owns a copy of it.
struct buttonAction {
  dialogFltk *dialog;
  std::function<void()> what;
};

void dialogFltk::_buttonCallback(Fl_Widget *w, void *data)
{
  buttonAction *a = (buttonAction *)data;
  if(!a) return;
  if(a->what) a->what();
  // what it did may have changed the shape of the dialog: a field deleted is
  // one option fewer to show
  if(a->dialog) a->dialog->reshape();
}

namespace {

  // The little buttons of the fields, kept while the widgets that point at
  // them are alive: FLTK hands a widget a void* when it calls back.
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

void dialogFltk::_addFields(const std::vector<Ui::Field> &fields, int x,
                            int &y, int w, int pane, int grid)
{
  int row = 0;
  // The fields are laid out in rows: a field that asks to share the line of the
  // one before it does, and the row is divided evenly between them. It is not
  // the pixel arithmetic the windows this replaces used, but it keeps the
  // grouping they expressed.
  std::size_t i = 0;
  while(i < fields.size()) {
    std::size_t last = i + 1;
    while(last < fields.size() && fields[last].sameRow) last++;
    int columns = 0, spacers = 0;
    for(std::size_t k = i; k < last; k++) {
      if(fields[k].kind == Ui::Spacer)
        spacers++;
      else if(!fields[k].packed)
        columns++;
    }
    int columnW = 0;
    _rowWidth(fields, i, last, columnW);
    // A pane laid out on a grid puts every field at the left of its column,
    // the same columns for every row, and lets it take the width it needs.
    // That is what the windows this replaces do, and it is what makes the
    // rows of one pane line up with each other.
    // A packed field takes the width it needs, from where it stands; a spacer
    // eats what is left, which is what pushes whatever follows it to the right.
    // With no spacer, the columns share the slack, as they always have.
    int packed = _packedTotal(fields, i, last);
    int slack = w - x - WB - packed - columns * columnW;
    if(slack < 0) slack = 0;
    if(!spacers && columns) columnW += slack / columns;
    int spacerW = spacers ? slack / spacers : 0;
    int at = x;
    // on a grid, where a field goes is where its column starts
    std::vector<int> gridW;
    std::vector<int> before = _gridLabelsBefore(fields, grid);
    int gridColumn = 0; // the column the next field goes in, on this row
    if(grid > 0) {
      gridW = _gridColumns(fields, grid);
      columns = grid;
    }

    for(std::size_t k = i; k < last; k++) {
      const Ui::Field &f = fields[k];
      if(f.visible && !f.visible()) continue;
      if(f.kind == Ui::Spacer) {
        if(grid > 0) {
          // What a spacer pushes to the right end of a line is not in a
          // column: it is against the right edge, which is where the window
          // this reproduces puts the buttons and switches it sets apart. The
          // columns are for what comes before it.
          int tail = -WB;
          for(std::size_t j = k + 1; j < last; j++) {
            if(fields[j].kind == Ui::Spacer) continue;
            if(fields[j].visible && !fields[j].visible()) continue;
            tail += _packedWidth(fields[j]) + WB;
          }
          int least = at + _packedWidth(f) + WB;
          at = std::max(w - WB - tail, least);
        }
        else
          at += _packedWidth(f) + WB + spacerW;
        continue;
      }
      int fieldW = _fieldWidth(f, (grid > 0) ? 1 : (columns ? columns : 1));
      if(f.widthEm > 0.) fieldW = (int)(f.widthEm * FL_NORMAL_SIZE);
      if(f.widthShare > 0.) fieldW = (int)(f.widthShare * IW);
      // A button carries its text inside, so a packed one is as wide as that
      // text and no wider -- which is also the room the line was measured to
      // leave it. Given the width of an ordinary button it would overlap the
      // one after it, and the last of a row would be cut off by the edge.
      if(f.packed && (f.kind == Ui::Action || f.kind == Ui::Menu))
        fieldW = _packedWidth(f);
      // On a grid, a cell is a field and whatever is packed against it; the
      // first field of a line begins one, and every field after it that is
      // not packed begins the next. A field that begins a cell goes where its
      // column starts, wherever what precedes it on the line happened to end
      // -- except what a spacer has pushed to the right end of the line,
      // which is where the spacer left it.
      bool loose = k > i && fields[k - 1].kind == Ui::Spacer;
      if(grid > 0) {
        if(k == i)
          gridColumn = 0;
        else if(!f.packed)
          gridColumn++;
        if(gridColumn >= grid) gridColumn = grid - 1;
      }
      int fx = at;
      if(grid > 0 && !loose && (k == i || !f.packed)) {
        fx = x;
        for(int c = 0; c < gridColumn && c < grid; c++) fx += gridW[(std::size_t)c];
      }
      // A label that comes before its field is written outside it, to its
      // left: the field starts after the widest such label of its column, so
      // that the fields line up and the labels end against them.
      if(f.labelBefore && f.label.size())
        fx += before[(std::size_t)(grid > 0 ? gridColumn : 0)];
      // a field of the column down the side is as wide as that column,
      // unless it says how wide it is: the plugins are a list of names and a
      // list of views side by side there
      if(pane == -2 && f.widthEm <= 0.) fieldW = w - fx - WB;
      // and what follows it on the line goes on from where it ends
      if(grid > 0)
        at = fx + (f.packed ? _packedStep(fields, k, last) :
                              _packedWidth(f) + WB);
      else if(f.packed)
        at += _packedStep(fields, k, last);
      else
        at += columnW;
      // The little buttons a field hangs after it -- the range of a value,
      // its loop, the plots it is reported in, the menu of a file. They take
      // their width from the font, as the compound widget this reproduces
      // gives them, and the field gives up the room.
      std::vector<int> trailingW;
      for(const auto &t : f.trailing) {
        int wide = t.label == ":" ? FL_NORMAL_SIZE - 2 : FL_NORMAL_SIZE + 6;
        trailingW.push_back(wide);
        fieldW -= wide;
      }
      if(fieldW < FL_NORMAL_SIZE) fieldW = FL_NORMAL_SIZE;

      Fl_Widget *widget = nullptr;
      switch(f.kind) {
      case Ui::Text:
        if(f.dynamicChoices) {
          // what one may want to type, without being held to it
          Fl_Input_Choice *c =
            new Fl_Input_Choice(fx, y, fieldW, BH);
          // The group has to answer to everything, since picking from the
          // menu goes through it; it is the input inside it that is told to
          // wait until one has finished typing.
          c->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
          if(f.commitsWhenDone)
            c->input()->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
          widget = c;
        }
        else {
          Fl_Input *in = new Fl_Input(fx, y, fieldW, BH);
          in->when(f.commitsWhenDone ?
                     (FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY) :
                     FL_WHEN_CHANGED);
          widget = in;
        }
        break;
      case Ui::Integer:
      case Ui::Number: {
        Fl_Value_Input *v =
          new Fl_Value_Input(fx, y, fieldW, BH);
        v->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        // a value the solver may act upon: the input inside the widget waits
        // until one has finished typing before it says so
        if(f.commitsWhenDone)
          v->input.when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        if(f.maximum > f.minimum) {
          v->minimum(f.minimum);
          v->maximum(f.maximum);
        }
        // the arrows only step where Gmsh is set up for them
        if(f.step > 0. && CTX::instance()->inputScrolling) v->step(f.step);
        widget = v;
      } break;
      case Ui::Check:
        if(f.disclosure)
          // the arrow says which way the fold goes; refresh() sets it
          widget = new Fl_Toggle_Button(fx, y, fieldW, BH);
        else
          widget = new Fl_Check_Button(
            fx, y, f.packed ? _packedWidth(f) : columnW - WB, BH,
            nullptr);
        break;
      case Ui::Choice:
        if(f.multiple) {
          // several switches behind one button, which is how the window this
          // replaces offers the element and field types
          Fl_Menu_Button *m = new Fl_Menu_Button(fx, y, fieldW, BH);
          widget = m;
        }
        else
          widget = new Fl_Choice(fx, y, fieldW, BH);
        break;
      case Ui::Label: {
        // a rule across the pane, and the line written under it
        // (a line that wraps is worth as many lines as it says)
        if(f.rule) {
          Fl_Box *line = new Fl_Box(fx, y, w - fx - WB, 2);
          line->box(FL_ENGRAVED_FRAME);
          line->labeltype(FL_NO_LABEL);
        }
        // it says what it says and no more, on a grid where a column follows
        // it; on its own line it runs to the edge, as a caption does
        Fl_Box *b = new Fl_Box(fx, y + (f.rule ? 1 : 0),
                               (grid > 0 && !f.wraps) ? fieldW : w - fx - WB,
                               (f.wraps && f.rows > 1) ? f.rows * BH : BH);
        b->align((f.heading ? FL_ALIGN_CENTER : FL_ALIGN_LEFT) |
                 FL_ALIGN_INSIDE |
                 (f.wraps ? FL_ALIGN_WRAP | FL_ALIGN_TOP : 0));
        // the name of what the panes are about, as the window this replaces
        // writes it
        if(f.heading) b->labelfont(FL_HELVETICA_BOLD);
        widget = b;
      } break;
      case Ui::Output: {
        Fl_Output *o = new Fl_Output(fx, y, fieldW, BH);
        widget = o;
      } break;
      case Ui::Spacer: break;
      case Ui::List: {
        // one it only shows, one it chooses from, one or several at a time
        int tall = f.rows * BH;
        if(!f.rows) {
          // As tall as there is room for: the whole of the column or of the
          // pane it is in, less whatever comes under it.
          int under = 0;
          for(std::size_t j = last; j < fields.size(); j++) {
            if(fields[j].sameRow) continue;
            if(fields[j].visible && !fields[j].visible()) continue;
            under++;
          }
          tall = (pane == -2) ? _sideHeight - (y - WB) - under * BH :
                                _paneBottom - y - WB - under * BH;
          if(tall < BH) tall = BH;
        }
        // as wide as it says, or as what is left of the line
        int wide = (f.widthEm > 0. || f.widthShare > 0.) ? fieldW :
                                                           w - fx - WB;
        Fl_Browser_ *br;
        if(!f.choose)
          br = new Fl_Select_Browser(fx, y, wide, tall);
        else if(f.multiple)
          br = new Fl_Multi_Browser(fx, y, wide, tall);
        else
          br = new Fl_Hold_Browser(fx, y, wide, tall);
        // a list whose lines are columns says how wide each of them is; the
        // widths have to outlive this call, as the browser keeps the array
        if(f.columnsEm.size()) {
          std::vector<int> *widths = new std::vector<int>;
          for(double em : f.columnsEm)
            widths->push_back((int)(em * FL_NORMAL_SIZE));
          widths->push_back(0); // the last column takes what is left
          ((Fl_Browser *)br)->column_widths(widths->data());
          ((Fl_Browser *)br)->column_char('\t');
        }
        br->callback(_fieldCallback, this);
        widget = br;
      } break;
      case Ui::Color: {
        // the swatch is the widget; its label sits to its right like any other
        Fl_Button *b = new Fl_Button(fx, y, fieldW, BH);
        b->box(FL_DOWN_BOX);
        widget = b;
      } break;
      case Ui::Action: {
        Fl_Button *b = new Fl_Button(fx, y, fieldW, BH);
        // the description owns the action; the window owns a copy of it
        b->callback(_buttonCallback, new buttonAction{this, f.changed});
        widget = b;
      } break;
      case Ui::Menu: {
        // a button that drops what one may do; the items are put in when the
        // dialog is refreshed, as they are made then
        Fl_Menu_Button *m = new Fl_Menu_Button(fx, y, fieldW, BH);
        widget = m;
      } break;
      case Ui::Direction:
        // It is drawn over the lines that follow it rather than pushing them
        // down: the rows under it are half a pane wide, and the window this
        // reproduces has the disc beside them.
        widget = new spherePositionWidget(fx, y, f.rows * BH);
        break;
      case Ui::Hierarchy: {
        // as tall as there is room for, like a list that fills its pane
        int tall = f.rows * BH;
        if(!f.rows) {
          int under = 0;
          for(std::size_t j = last; j < fields.size(); j++) {
            if(fields[j].sameRow) continue;
            if(fields[j].visible && !fields[j].visible()) continue;
            under++;
          }
          tall = _paneBottom - y - WB - under * BH;
          if(tall < BH) tall = BH;
        }
        Fl_Tree *tree = new Fl_Tree(fx, y, w - fx - WB, tall);
        tree->selectmode(FL_TREE_SELECT_MULTI);
        tree->callback(_fieldCallback, this);
        tree->when(FL_WHEN_CHANGED);
        widget = tree;
      } break;
      case Ui::ColorMap: {
        // the widget the window this reproduces already has, given the whole
        // of its pane
        int tall = f.rows ? f.rows * BH : _paneBottom - y - WB;
        if(tall < BH) tall = BH;
        colorbarWindow *bar =
          new colorbarWindow(fx, y, w - fx - WB, tall);
        bar->end();
        widget = bar;
      } break;
      }
      if(!widget) continue;
      // A widget keeps the pointer it is given rather than the text, so the
      // label cannot be a temporary: copy_label() takes a copy of its own.
      // A line the dialog says carries its text in the label, which refresh()
      // rewrites at every turn; every other kind keeps the one it declares --
      // a value one only reads has a label like any other field.
      if(f.label.size() && f.kind != Ui::Label)
        widget->copy_label(_escaped(f.label).c_str());
      // The inputs and the choices carry their label to their right, as every
      // Gmsh window does. A check button is different: it draws its label
      // inside, next to the box, and FL_ALIGN_RIGHT would throw it off.
      // a menu of switches carries its label inside, as a button does
      if(f.kind != Ui::Check && f.kind != Ui::Label &&
         f.kind != Ui::Action && f.kind != Ui::Menu &&
         f.kind != Ui::Direction &&
         f.kind != Ui::ColorMap && f.kind != Ui::Hierarchy &&
         !(f.kind == Ui::Choice && f.multiple))
        widget->align(f.labelBefore ? FL_ALIGN_LEFT : FL_ALIGN_RIGHT);
      // A field to be looked at twice, in red. On a button whose face is dark
      // it is the face that is coloured, as red text on it would not be read;
      // on a light one it is the text, which is what Gmsh has always done.
      if(f.alert) {
        if(f.kind == Ui::Action && CTX::instance()->guiColorScheme)
          widget->color(FL_DARK_RED);
        else
          widget->labelcolor(FL_DARK_RED);
      }
      if(f.tooltip.size()) widget->copy_tooltip(f.tooltip.c_str());
      widget->callback(_fieldCallback, this);
      // and the little buttons after it, which the label then follows
      int at = fx + fieldW;
      for(std::size_t t = 0; t < f.trailing.size(); t++) {
        _kept().push_back(f.trailing[t]);
        Ui::Button *button = &_kept().back();
        Fl_Button *made = new Fl_Button(at, y, trailingW[t], BH);
        at += trailingW[t];
        if(button->glyph.size())
          made->copy_label(("@-1gmsh_" + button->glyph).c_str());
        else if(button->label.size())
          made->copy_label(button->label.c_str());
        else if(button->menu)
          made->copy_label("@2>");
        if(button->tooltip.size())
          made->copy_tooltip(button->tooltip.c_str());
        made->callback(button->menu ? _trailingMenu : _trailingPressed,
                       button);
        if(button->on && button->on()) made->color(FL_GREEN);
      }
      // A field that carries buttons gives up its name to them: FLTK draws a
      // name to the right of the widget it belongs to, which is where they
      // are. It goes on a box of its own after them, as the compound widget
      // this reproduces places it.
      if(f.trailing.size() && f.label.size() && !f.labelBefore) {
        widget->label(nullptr);
        fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
        int labelW = (int)fl_width(_escaped(f.label).c_str()) + WB;
        Fl_Box *say = new Fl_Box(at, y, labelW, BH);
        say->copy_label(_escaped(f.label).c_str());
        say->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      }
      bound b;
      b.field = f;
      b.widget = widget;
      b.pane = pane;
      b.row = row;
      _fields.push_back(b);
    }
    // a list is as tall as the lines it shows, and what follows it comes
    // under it rather than over it
    int tall = 1;
    for(std::size_t k = i; k < last; k++) {
      if(fields[k].kind != Ui::List && fields[k].kind != Ui::Hierarchy &&
         fields[k].kind != Ui::ColorMap &&
         !(fields[k].kind == Ui::Label && fields[k].wraps))
        continue;
      if(fields[k].rows > tall) tall = fields[k].rows;
      if(!fields[k].rows) {
        // one that fills what it is in: what follows it is at the bottom
        int under = 0;
        for(std::size_t j = last; j < fields.size(); j++) {
          if(fields[j].sameRow) continue;
          if(fields[j].visible && !fields[j].visible()) continue;
          under++;
        }
        int fill = (pane == -2) ? _sideHeight - (y - WB) - under * BH :
                                  _paneBottom - y - WB - under * BH;
        if(fill > tall * BH) tall = fill / BH;
      }
    }
    y += tall * BH;
    row += tall;
    i = last;
  }
}

// What a dialog offers can change with what one picks in it. Rebuild it when
// its shape has really changed -- and only then: rebuilding a window that is
// already up makes it blink -- keeping it where the user left it rather than
// where a window of that dialog opens.
void dialogFltk::reshape()
{
  if(_which < 0) return;
  Ui::Form now = uiSources().form(_which);
  if(_win && _signature(now) == _signatureBuilt) {
    _panel = now;
    refresh();
    return;
  }
  int x = _win ? _win->x() : -1, y = _win ? _win->y() : -1;
  build(_which);
  if(_win && x >= 0) _win->position(x, y);
  refresh();
}

void dialogFltk::build(int dialog)
{
  bool wasShown = shown();
  if(_win) {
    // it is not going away, it is being built again: what it undoes when it
    // closes must not be undone here
    if(dialogWindow *w = dynamic_cast<dialogWindow *>(_win)) w->closed = nullptr;
    Fl::delete_widget(_win);
    _win = nullptr;
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
  _paneButtons.clear();

  _which = dialog;
  _panel = uiSources().form(dialog);
  _signatureBuilt = _signature(_panel);
  // a window that has just been built has no tab of its own yet
  _forcePane = true;

  // one long form rather than tabs: every pane is laid out, one after another
  // only a first guess: _relayout() gives the window its real height once it
  // knows which panes show
  std::vector<bool> visible;
  for(const auto &q : _panel.panes)
    visible.push_back(!q.visible || q.visible());

  int formH = 0;
  // A form longer than a window is worth scrolls, as a pane of a tabbed dialog
  // does: the keyboard and mouse reference is a page, not a form one fills.
  _formScrolls = false;
  _formFills = false;
  if(!_panel.tabbed) {
    for(std::size_t i = 0; i < _panel.panes.size(); i++) {
      if(_panel.panes[i].scrolling) _formScrolls = true;
      // and one that holds a field taking whatever is left of it -- a listing
      // -- has a height of its own rather than one counted in rows
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
  // What it is worth at least: a field that fills what is left of the form --
  // the listing of the current options is one long list -- counts for no rows
  // at all, so without this the window would be as tall as its two checks.
  if(!_panel.tabbed && _panel.leastRows > 0 && formH < _panel.leastRows * BH)
    formH = _panel.leastRows * BH;
  // and what of it is shown at once, when it is longer than that
  int formShown = formH;
  if(_formScrolls && _panel.leastRows > 0 &&
     formShown > _panel.leastRows * BH)
    formShown = _panel.leastRows * BH;

  // wide enough for the busiest row of every pane, and never so narrow that a
  // dialog with little in it looks starved. It used to be the width of the
  // widest window this replaces, which made every one of them that wide.
  int width = 20 * FL_NORMAL_SIZE;
  // the column of side fields is beside the panes, not part of what they need
  int aside = _panel.side.empty() ?
                0 :
                (int)((_panel.sideEm > 0. ? _panel.sideEm : 8.) *
                      FL_NORMAL_SIZE);
  width += aside;
  for(const auto &q : _panel.panes) {
    int need = 0;
    if(q.columns > 0)
      need = _gridWidth(q.fields, q.columns) + 2 * WB;
    else
      need = _neededWidth(q.fields) + 2 * WB;
    if(need + aside > width) width = need + aside;
    // and for what stands beside its button
    if(q.beside.size()) {
      int line = _neededWidth(q.beside) + 2 * WB + aside +
                 (q.buttonLabel.size() ? BB + WB : 0);
      if(line > width) width = line;
    }
  }
  {
    int need = _neededWidth(_panel.header) + 2 * WB + aside;
    if(need > width) width = need;
  }
  {
    int need = _neededWidth(_panel.footer) + 2 * WB + aside;
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
  // and wide enough for the row of tabs itself: a window that fits what its
  // panes hold but not their names hides the last of them behind a pulldown.
  // They are one row there, so it is their total that has to fit.
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
      // when the tabs do not fit, which is exactly what is being avoided here
      int need = row.second + aside + 2 * WB + 2 * FL_NORMAL_SIZE;
      if(need > width) width = need;
    }
  }
  // A dialog whose panes change -- the option window shows another category --
  // keeps the width the widest of them asked for: one that grows and shrinks
  // sideways as one goes through it is one that will not sit still.
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

  // A window created while a group is open becomes a child of that group, and
  // the window that was being built is wrecked. Nothing says a dialog is only
  // ever built at a quiet moment, so make sure of it here.
  Fl_Group *previous = Fl_Group::current();
  Fl_Group::current(nullptr);

  dialogWindow *win = new dialogWindow(
    width, height, CTX::instance()->nonModalWindows ? true : false,
    _panel.title.c_str());
  win->closed = _panel.closed;
  _win = win;
  _win->box(GMSH_WINDOW_BOX);

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
        b = new Fl_Box(2 * WB, y, width - 4 * WB, BH);
        b->copy_label(_plain(q.label).c_str());
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        b->labelfont(FL_HELVETICA_BOLD);
        y += BH;
      }
      _sections.push_back(b);
      int rows = _rows(q.fields);
      // a form that scrolls ends before its scrollbar, or what it puts at its
      // right edge is drawn under it
      _addFields(q.fields, 2 * WB, y,
                 width - (form ? Fl::scrollbar_size() : 0), (int)i, q.columns);
      if(q.buttonLabel.size()) {
        Fl_Button *pb = new Fl_Button(width - BB - 2 * WB, y, BB, BH);
        pb->copy_label(_escaped(q.buttonLabel).c_str());
        pb->callback(_buttonCallback, new buttonAction{this, q.button});
        _paneButtons.push_back({pb, (int)i, rows});
        y += BH;
      }
      // the rule the windows this replaces draw between their groups
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
    // A field that fills the form ends at the bottom of the form, whatever the
    // rows above it came to; what follows the form has to start under that and
    // not under the rows, or the buttons are drawn over the last of it.
    if(_formFills && y < _paneBottom) y = _paneBottom;
    y += WB;
  }

  if(_panel.tabbed) {
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
      // the pane ends where its group does, not where the window does -- and
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
        // at the bottom right of the pane, with the same margin under it as
        // around everything else
        Fl_Button *b =
          new Fl_Button(width - BB - 2 * WB, top + height - BH - WB, BB, BH);
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
    }
    y += BH + WB;
  }

  _win->position(CTX::instance()->ctxPosition[0],
                 CTX::instance()->ctxPosition[1]);
  _win->end();
  Fl_Group::current(previous);

  refresh();
  if(wasShown) _win->show();
}

// A dialog that watches something rather than holding it -- the gamepad,
// whose lights follow the pad -- asks to be refreshed on a timer. FLTK draws
// only when something happens, so something has to happen.
void dialogFltk::_tick(void *data)
{
  dialogFltk *d = (dialogFltk *)data;
  if(!d->shown()) return; // it stops with the window and starts with it again
  d->refresh();
  Fl::repeat_timeout(d->_panel.refreshEvery, _tick, data);
}

namespace {

  // The paths of the lines, kept while the tree that points at them is alive:
  // an Fl_Tree item carries a void*, so what it points at has to outlive it.
  std::deque<std::string> _treePaths;

  // Down the model, unfolding as it goes: each child of a line becomes an
  // item under it, and the item remembers which line of the description it
  // stands for.
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

void dialogFltk::refresh()
{
  if(!_panel.tabbed) _relayout();

  int shownPane = uiSources().formPane(_which);
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

  for(auto &b : _fields) {
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
      // The lines, in order, each one a child of the last line shallower than
      // it. Rebuilt only when they have changed: an Fl_Tree that is built
      // again forgets what was open.
      Fl_Tree *tree = (Fl_Tree *)b.widget;
      if(!f.hierarchy) break;
      const Ui::Tree &said = *f.hierarchy;
      // Rebuilt only when the shape has changed: an Fl_Tree that is built
      // again forgets what was open.
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
      ((Fl_Value_Input *)b.widget)->value(f.getNumber());
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
  if(_win) _win->redraw();
}

void dialogFltk::_relayout()
{
  // A form that scrolls has nothing that folds: moving its panes about inside
  // the box it scrolls in would only fight with the box. Neither has one whose
  // fields are as tall as the window is: what is laid out in rows here is not
  // what says how tall it is.
  if(!_win || _panel.tabbed || _formScrolls || _formFills) return;

  std::vector<bool> visible;
  for(const auto &q : _panel.panes)
    visible.push_back(!q.visible || q.visible());

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
    if(visible[i])
      y += (_rows(_panel.panes[i].fields) +
            (_panel.panes[i].buttonLabel.size() ? 1 : 0)) * BH;
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
  y += _rows(_panel.footer) * BH;
  if(!_mergedButtons) buttonTop = y;

  for(auto &b : _fields) {
    int at = (b.pane < 0) ? footerTop : top[b.pane];
    bool show = (b.pane < 0) || visible[b.pane];
    b.widget->position(b.widget->x(), at + b.row * BH);
    if(show)
      b.widget->show();
    else
      b.widget->hide();
  }

  for(auto &b : _paneButtons) {
    b.widget->position(b.widget->x(), top[b.pane] + b.row * BH);
    if(visible[b.pane])
      b.widget->show();
    else
      b.widget->hide();
  }

  if(_buttons.size()) {
    for(auto *w : _buttons) w->position(w->x(), buttonTop);
    if(!_mergedButtons) y += BH + WB;
  }
  y += WB;

  if(_win->h() != y) _win->size(_win->w(), y);
  _win->redraw();
}

void dialogFltk::show()
{
  // What the dialog offers can depend on the model, so it may have to be built
  // again -- but only when its shape really changed: rebuilding a window that
  // is already up makes it blink and come back somewhere else.
  Ui::Form now = uiSources().form(_which);
  if(!_win || _signature(now) != _signatureBuilt)
    build(_which);
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

dialogFltk *fltkDialog(int which, bool create)
{
  // how many forms there are is the application's to say, so this cannot be
  // an array of that size any more; a map keeps the addresses steady, which
  // the widgets that were built for one of them rely on
  static std::map<int, dialogFltk> dialogs;
  if(which < 0 || which >= uiSources().numForms()) return nullptr;
  auto it = dialogs.find(which);
  if(it == dialogs.end()) {
    if(!create) return nullptr;
    it = dialogs.emplace(which, dialogFltk()).first;
    it->second.build(which);
  }
  return &it->second;
}

#endif
