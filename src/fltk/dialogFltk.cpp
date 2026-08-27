// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <algorithm>
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
#include "dialogFltk.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "Context.h"

namespace {

  // how many lines a list of fields takes, once those that share one are put
  // together
  int _rows(const std::vector<Dialog::Field> &fields)
  {
    int rows = 0;
    for(std::size_t i = 0; i < fields.size(); i++) {
      if(fields[i].sameRow && i) continue;
      if(fields[i].visible && !fields[i].visible()) continue;
      // a list is worth as many lines as it shows
      rows += (fields[i].kind == Dialog::List) ? fields[i].rows : 1;
    }
    return rows;
  }

  // FLTK reads "&" in a label as the mark of a keyboard shortcut and does not
  // draw it. A label is text here, so an ampersand has to be doubled to come
  // out as one -- "Colours & light" is a tab, not a shortcut.
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
  int _gridWidth(const std::vector<Dialog::Field> &fields, int grid);

  // How wide a field's widget has to be. Alone on its line an input gets the
  // usual width, otherwise a narrower one so that several fit. A choice gets
  // the same as an input: sizing it to the longest thing it offers makes it
  // wider than the fields above and below it, and their labels no longer line
  // up. The windows this replaces give a choice a plain IW too, and let a long
  // entry be clipped; one that really needs more says so with widthEm.
  int _fieldWidth(const Dialog::Field &f, int columns)
  {
    if(f.disclosure) return BB;
    if(f.kind == Dialog::Spacer) return 0;
    if(f.kind == Dialog::Action) {
      // a button is as wide as the text it carries inside, never narrower
      // than an ordinary one
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      int need = (int)fl_width(_escaped(f.label).c_str()) + 2 * FL_NORMAL_SIZE;
      return (need > BB) ? need : BB;
    }
    if(f.kind == Dialog::Label) {
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      return (int)fl_width(f.getText().c_str()) + FL_NORMAL_SIZE;
    }
    if(f.kind == Dialog::Check) return (int)(1.5 * FL_NORMAL_SIZE);
    // a swatch says what it is by its colour; it needs no room for text
    if(f.kind == Dialog::Color) return (int)(3. * FL_NORMAL_SIZE);
    // the disc of a direction is square, as tall as the lines it hangs over
    if(f.kind == Dialog::Direction) return f.rows * BH;
    return (columns == 1) ? IW : IW / 2;
  }

  // What a packed field needs: its own text and no more. It takes the width it
  // asks for rather than a share of the line.
  int _packedWidth(const Dialog::Field &f)
  {
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    if(f.kind == Dialog::Spacer)
      return (int)((f.widthEm > 0. ? f.widthEm : 2.) * FL_NORMAL_SIZE);
    if(f.disclosure) return BB;
    if(f.kind == Dialog::Label)
      return (int)fl_width(f.getText().c_str()) + WB;
    if(f.kind == Dialog::Action)
      return (int)fl_width(_escaped(f.label).c_str()) + 2 * FL_NORMAL_SIZE;
    if(f.kind == Dialog::Check)
      return (int)fl_width(_escaped(f.label).c_str()) + (int)(1.8 * FL_NORMAL_SIZE);
    if(f.kind == Dialog::Direction) return f.rows * BH;
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
  bool _sharesCell(const std::vector<Dialog::Field> &fields, std::size_t k,
                   std::size_t to)
  {
    return fields[k].widthShare > 0. && k + 1 < to &&
           fields[k + 1].widthShare > 0.;
  }

  // how far the next field starts from this one, when this one is packed
  int _packedStep(const std::vector<Dialog::Field> &fields, std::size_t k,
                  std::size_t to)
  {
    if(_sharesCell(fields, k, to)) return (int)(fields[k].widthShare * IW);
    return _packedWidth(fields[k]) + WB;
  }

  // Where the columns of a pane laid out on a grid start, and how wide each
  // of them is: a column is as wide as the widest thing in it, its label
  // included, and not as wide as the widest thing in the pane.
  std::vector<int> _gridColumns(const std::vector<Dialog::Field> &fields,
                                int grid)
  {
    std::vector<int> width((std::size_t)grid, 0);
    int column = 0;
    for(std::size_t k = 0; k < fields.size(); k++) {
      const Dialog::Field &f = fields[k];
      if(!f.sameRow)
        column = 0;
      else if(!f.packed)
        column++;
      if(column >= grid) column = grid - 1;
      if(f.kind == Dialog::Spacer) continue;
      // What follows it inside the same column adds to it. Its label only
      // needs room if another column follows on the same row: the label of
      // the last field of a row runs on into the space no one else uses,
      // which is what keeps the columns as narrow as the window this
      // replaces has them.
      int need = 0;
      std::size_t j = k;
      bool more = false;
      while(j < fields.size() && (j == k || (fields[j].sameRow && fields[j].packed))) {
        need += _packedWidth(fields[j]);
        j++;
      }
      if(j < fields.size() && fields[j].sameRow) more = true;
      if(!more) {
        // take the label back off the last of them
        const Dialog::Field &l = fields[j - 1];
        fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
        if(l.kind != Dialog::Check && l.kind != Dialog::Action &&
           l.kind != Dialog::Label && l.kind != Dialog::Direction &&
           !(l.kind == Dialog::Choice && l.multiple))
          need -= (int)fl_width(_escaped(l.label).c_str()) + 2 * WB;
      }
      if(need > width[(std::size_t)column]) width[(std::size_t)column] = need;
    }
    return width;
  }

  int _gridWidth(const std::vector<Dialog::Field> &fields, int grid)
  {
    std::vector<int> column = _gridColumns(fields, grid);
    int widest = 0, at = 0, which = 0;
    for(std::size_t k = 0; k < fields.size(); k++) {
      const Dialog::Field &f = fields[k];
      if(!f.sameRow) {
        which = 0;
        at = 0;
      }
      else if(!f.packed) {
        which++;
        at = 0;
        for(int c = 0; c < which && c < grid; c++) at += column[(std::size_t)c];
      }
      // a spacer takes at least what it asks for, and what follows it comes
      // after that: a row ending in one is as wide as all of them together
      if(f.kind == Dialog::Spacer) {
        at += _packedWidth(f) + WB;
        continue;
      }
      int end = at + _packedWidth(f);
      if(end > widest) widest = end;
      if(f.packed && f.sameRow) at += _packedWidth(f) + WB;
    }
    return widest;
  }

  // how much of a line the packed fields take, spacing included
  int _packedTotal(const std::vector<Dialog::Field> &fields, std::size_t from,
                   std::size_t to)
  {
    int total = 0;
    for(std::size_t k = from; k < to; k++)
      if(fields[k].packed || fields[k].kind == Dialog::Spacer)
        total += _packedStep(fields, k, to);
    return total;
  }

  // the width one line needs, labels included
  int _rowWidth(const std::vector<Dialog::Field> &fields, std::size_t from,
                std::size_t to, int &columnW)
  {
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    int columns = 0;
    for(std::size_t k = from; k < to; k++)
      if(!fields[k].packed && fields[k].kind != Dialog::Spacer) columns++;
    columnW = 0;
    for(std::size_t k = from; k < to; k++) {
      if(fields[k].packed || fields[k].kind == Dialog::Spacer) continue;
      // a plain line and a button carry their text inside
      int label = (fields[k].kind == Dialog::Label ||
                   fields[k].kind == Dialog::Action) ?
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
  int _neededWidth(const std::vector<Dialog::Field> &fields)
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
  std::size_t _paneRows(const Dialog::Pane &q)
  {
    std::size_t rows = _rows(q.fields);
    for(const auto &s : q.sections)
      rows += (s.label.size() ? 1 : 0) + _rows(s.fields);
    return rows;
  }

  int _paneHeight(const Dialog::Panel &p)
  {
    std::size_t most = 0;
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
  std::string _signature(const Dialog::Panel &p)
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
    Dialog::Field &f = b.field;
    switch(f.kind) {
    case Dialog::Text:
      if(Fl_Input_Choice *c = dynamic_cast<Fl_Input_Choice *>(w))
        f.setText(c->value() ? c->value() : "");
      else
        f.setText(((Fl_Input *)w)->value());
      break;
    case Dialog::Integer:
    case Dialog::Number:
      f.setNumber(((Fl_Value_Input *)w)->value());
      break;
    case Dialog::Check:
      f.setFlag(((Fl_Button *)w)->value() ? true : false);
      break;
    case Dialog::Color: {
      unsigned int packed = f.getColour();
      uchar r = CTX::instance()->unpackRed(packed);
      uchar g = CTX::instance()->unpackGreen(packed);
      uchar b = CTX::instance()->unpackBlue(packed);
      uchar a = CTX::instance()->unpackAlpha(packed);
      if(fl_color_chooser("Color Chooser", r, g, b))
        f.setColour(CTX::instance()->packColor(r, g, b, a));
    } break;
    case Dialog::Direction: {
      double x = 0., y = 0., z = 0.;
      ((spherePositionWidget *)w)->getValue(x, y, z);
      f.setVector(x, y, z);
    } break;
    case Dialog::Label:
    case Dialog::Output:
    case Dialog::Action:
    case Dialog::Spacer: break;
    case Dialog::List: {
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
    case Dialog::Choice: {
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
  d->refresh();
}

// the user clicked a tab: the description must follow, or the next refresh
// would put the pane it remembers back
void dialogFltk::_tabCallback(Fl_Widget *w, void *data)
{
  dialogFltk *d = (dialogFltk *)data;
  Fl_Widget *shown = ((Fl_Tabs *)w)->value();
  for(std::size_t i = 0; i < d->_groups.size(); i++) {
    if(d->_groups[i] != shown) continue;
    bool moved = Dialog::currentPane(d->_which) != (int)i;
    Dialog::currentPane(d->_which) = (int)i;
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
      bool moved = Dialog::currentPane(d->_which) != first;
      Dialog::currentPane(d->_which) = first;
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

void dialogFltk::_buttonCallback(Fl_Widget *w, void *data)
{
  std::function<void()> *what = (std::function<void()> *)data;
  if(what && *what) (*what)();
}

void dialogFltk::_addFields(const std::vector<Dialog::Field> &fields, int x,
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
      if(fields[k].kind == Dialog::Spacer)
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
    int gridColumn = 0; // the column the next field goes in, on this row
    if(grid > 0) {
      gridW = _gridColumns(fields, grid);
      columns = grid;
      // what a spacer of this row has to eat, the columns not being shares of
      // the line here but widths of their own
      if(spacers) {
        int used = 0, which = 0;
        for(std::size_t k = i; k < last; k++) {
          if(fields[k].kind == Dialog::Spacer) {
            // the least it takes, which comes out of the slack rather than
            // being added to it: what follows a spacer ends at the right edge
            used += _packedWidth(fields[k]) + WB;
            continue;
          }
          if(fields[k].packed)
            used += _packedStep(fields, k, last);
          else {
            used = 0;
            for(int c = 0; c <= which && c < grid; c++)
              used += gridW[(std::size_t)c];
            which++;
          }
        }
        spacerW = (w - x - WB - used) / spacers;
        if(spacerW < 0) spacerW = 0;
      }
    }

    for(std::size_t k = i; k < last; k++) {
      const Dialog::Field &f = fields[k];
      if(f.visible && !f.visible()) continue;
      if(f.kind == Dialog::Spacer) {
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
      if(f.packed && f.kind == Dialog::Action) fieldW = _packedWidth(f);
      int fx = at;
      // a field of the column down the side is as wide as that column
      if(pane == -2) fieldW = w - fx - WB;
      if(grid > 0) {
        if(f.packed)
          at += _packedStep(fields, k, last);
        else {
          gridColumn++;
          at = x;
          for(int c = 0; c < gridColumn && c < grid; c++) at += gridW[(std::size_t)c];
        }
      }
      else if(f.packed)
        at += _packedStep(fields, k, last);
      else
        at += columnW;
      Fl_Widget *widget = nullptr;
      switch(f.kind) {
      case Dialog::Text:
        if(f.dynamicChoices) {
          // what one may want to type, without being held to it
          Fl_Input_Choice *c =
            new Fl_Input_Choice(fx, y, fieldW, BH);
          c->when(FL_WHEN_CHANGED);
          widget = c;
        }
        else {
          Fl_Input *in = new Fl_Input(fx, y, fieldW, BH);
          in->when(FL_WHEN_CHANGED);
          widget = in;
        }
        break;
      case Dialog::Integer:
      case Dialog::Number: {
        Fl_Value_Input *v =
          new Fl_Value_Input(fx, y, fieldW, BH);
        v->when(FL_WHEN_CHANGED);
        if(f.maximum > f.minimum) {
          v->minimum(f.minimum);
          v->maximum(f.maximum);
        }
        // the arrows only step where Gmsh is set up for them
        if(f.step > 0. && CTX::instance()->inputScrolling) v->step(f.step);
        widget = v;
      } break;
      case Dialog::Check:
        if(f.disclosure)
          // the arrow says which way the fold goes; refresh() sets it
          widget = new Fl_Toggle_Button(fx, y, fieldW, BH);
        else
          widget = new Fl_Check_Button(
            fx, y, f.packed ? _packedWidth(f) : columnW - WB, BH,
            nullptr);
        break;
      case Dialog::Choice:
        if(f.multiple) {
          // several switches behind one button, which is how the window this
          // replaces offers the element and field types
          Fl_Menu_Button *m = new Fl_Menu_Button(fx, y, fieldW, BH);
          widget = m;
        }
        else
          widget = new Fl_Choice(fx, y, fieldW, BH);
        break;
      case Dialog::Label: {
        Fl_Box *b = new Fl_Box(fx, y, w - fx - WB, BH);
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        widget = b;
      } break;
      case Dialog::Output: {
        Fl_Output *o = new Fl_Output(fx, y, fieldW, BH);
        widget = o;
      } break;
      case Dialog::Spacer: break;
      case Dialog::List: {
        // one it only shows, one it chooses from, one or several at a time
        int tall = f.rows * BH;
        if(!f.rows) {
          // as tall as there is room for, which is the whole of a side column
          // less whatever comes under it
          int under = 0;
          for(std::size_t j = last; j < fields.size(); j++) {
            if(fields[j].sameRow) continue;
            if(fields[j].visible && !fields[j].visible()) continue;
            under++;
          }
          tall = _sideHeight - (y - WB) - under * BH;
          if(tall < BH) tall = BH;
        }
        Fl_Browser_ *br;
        if(!f.choose)
          br = new Fl_Select_Browser(fx, y, w - fx - WB, tall);
        else if(f.multiple)
          br = new Fl_Multi_Browser(fx, y, w - fx - WB, tall);
        else
          br = new Fl_Hold_Browser(fx, y, w - fx - WB, tall);
        br->callback(_fieldCallback, this);
        widget = br;
      } break;
      case Dialog::Color: {
        // the swatch is the widget; its label sits to its right like any other
        Fl_Button *b = new Fl_Button(fx, y, fieldW, BH);
        b->box(FL_DOWN_BOX);
        widget = b;
      } break;
      case Dialog::Action: {
        Fl_Button *b = new Fl_Button(fx, y, fieldW, BH);
        // the description owns the action; the window owns a copy of it
        b->callback(_buttonCallback, new std::function<void()>(f.changed));
        widget = b;
      } break;
      case Dialog::Direction:
        // It is drawn over the lines that follow it rather than pushing them
        // down: the rows under it are half a pane wide, and the window this
        // reproduces has the disc beside them.
        widget = new spherePositionWidget(fx, y, f.rows * BH);
        break;
      }
      if(!widget) continue;
      // A widget keeps the pointer it is given rather than the text, so the
      // label cannot be a temporary: copy_label() takes a copy of its own.
      if(f.label.size() && f.kind != Dialog::Label && f.kind != Dialog::Output)
        widget->copy_label(_escaped(f.label).c_str());
      // The inputs and the choices carry their label to their right, as every
      // Gmsh window does. A check button is different: it draws its label
      // inside, next to the box, and FL_ALIGN_RIGHT would throw it off.
      // a menu of switches carries its label inside, as a button does
      if(f.kind != Dialog::Check && f.kind != Dialog::Label &&
         f.kind != Dialog::Action && f.kind != Dialog::Direction &&
         !(f.kind == Dialog::Choice && f.multiple))
        widget->align(FL_ALIGN_RIGHT);
      // A field to be looked at twice, in red. On a button whose face is dark
      // it is the face that is coloured, as red text on it would not be read;
      // on a light one it is the text, which is what Gmsh has always done.
      if(f.alert) {
        if(f.kind == Dialog::Action && CTX::instance()->guiColorScheme)
          widget->color(FL_DARK_RED);
        else
          widget->labelcolor(FL_DARK_RED);
      }
      if(f.tooltip.size()) widget->copy_tooltip(f.tooltip.c_str());
      widget->callback(_fieldCallback, this);
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
      if(fields[k].kind != Dialog::List) continue;
      if(fields[k].rows > tall) tall = fields[k].rows;
      if(!fields[k].rows) {
        // one that fills its column: what follows it is at the bottom
        int under = 0;
        for(std::size_t j = last; j < fields.size(); j++) {
          if(fields[j].sameRow) continue;
          if(fields[j].visible && !fields[j].visible()) continue;
          under++;
        }
        int fill = _sideHeight - (y - WB) - under * BH;
        if(fill > tall * BH) tall = fill / BH;
      }
    }
    y += tall * BH;
    row += tall;
    i = last;
  }
}

void dialogFltk::build(int dialog)
{
  bool wasShown = shown();
  if(_win) {
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
  _panel = Dialog::panel(dialog);
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
  if(!_panel.tabbed) {
    for(std::size_t i = 0; i < _panel.panes.size(); i++) {
      if(!visible[i]) continue;
      formH += (_panel.panes[i].label.size() ? BH : 0) +
               _rows(_panel.panes[i].fields) * BH +
               (_panel.panes[i].buttonLabel.size() ? BH : 0) +
               (_panel.panes[i].separatorAfter ? 2 + WB : 0);
    }
    formH += WB;
  }

  // wide enough for the busiest row of every pane, and never so narrow that a
  // dialog with little in it looks starved. It used to be the width of the
  // widest window this replaces, which made every one of them that wide.
  int width = 20 * FL_NORMAL_SIZE;
  // the column of side fields is beside the panes, not part of what they need
  int aside = _panel.side.empty() ? 0 : 8 * FL_NORMAL_SIZE;
  width += aside;
  for(const auto &q : _panel.panes) {
    int need = 0;
    if(q.columns > 0)
      need = _gridWidth(q.fields, q.columns) + 2 * WB;
    else
      need = _neededWidth(q.fields) + 2 * WB;
    if(need + aside > width) width = need + aside;
  }
  {
    int need = _neededWidth(_panel.footer) + 2 * WB + aside;
    if(need > width) width = need;
  }
  // A dialog whose panes change -- the option window shows another category --
  // keeps the width the widest of them asked for: one that grows and shrinks
  // sideways as one goes through it is one that will not sit still.
  if(width > _widestSeen)
    _widestSeen = width;
  else
    width = _widestSeen;
  int paneH = _paneHeight(_panel);
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
  int height = (_panel.tabbed ? paneH + tabRows * BH : formH) + footerH +
               buttonH + 2 * WB;

  // A window created while a group is open becomes a child of that group, and
  // the window that was being built is wrecked. Nothing says a dialog is only
  // ever built at a quiet moment, so make sure of it here.
  Fl_Group *previous = Fl_Group::current();
  Fl_Group::current(nullptr);

  _win = new paletteWindow(width, height,
                           CTX::instance()->nonModalWindows ? true : false,
                           _panel.title.c_str());
  _win->box(GMSH_WINDOW_BOX);

  // the column of side fields, down the whole left edge
  _sideWidth = _panel.side.empty() ? 0 : 8 * FL_NORMAL_SIZE;
  if(_sideWidth) {
    int sy = WB;
    _sideHeight = height - 2 * WB;
    _addFields(_panel.side, WB, sy, _sideWidth, -2);
  }

  int y = WB;

  if(!_panel.tabbed) {
    // every pane is built, whether it shows or not: folding one away is then
    // only a matter of moving what is left
    for(std::size_t i = 0; i < _panel.panes.size(); i++) {
      const Dialog::Pane &q = _panel.panes[i];
      Fl_Box *b = nullptr;
      if(q.label.size()) {
        b = new Fl_Box(2 * WB, y, width - 4 * WB, BH);
        b->copy_label(_escaped(q.label).c_str());
        b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        b->labelfont(FL_HELVETICA_BOLD);
        y += BH;
      }
      _sections.push_back(b);
      int rows = _rows(q.fields);
      _addFields(q.fields, 2 * WB, y, width, (int)i, q.columns);
      if(q.buttonLabel.size()) {
        Fl_Button *pb = new Fl_Button(width - BB - 2 * WB, y, BB, BH);
        pb->copy_label(_escaped(q.buttonLabel).c_str());
        pb->callback(_buttonCallback, new std::function<void()>(q.button));
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
      const Dialog::Pane &q = _panel.panes[i];
      Fl_Group *pg =
        new Fl_Group(_sideWidth + WB, top, width - _sideWidth - 2 * WB, height);
      pg->copy_label(_escaped(q.label).c_str());
      int fy = top + WB;
      // a long pane scrolls rather than making the window as tall as it is
      Fl_Scroll *scroll = nullptr;
      if(q.scrolling) {
        scroll = new Fl_Scroll(_sideWidth + WB, top, width - _sideWidth - 2 * WB,
                               height);
        scroll->type(Fl_Scroll::VERTICAL);
        scroll->box(FL_FLAT_BOX);
      }
      // the pane ends where its group does, not where the window does -- and
      // one that scrolls ends before its scrollbar, or what it puts at its
      // right edge is drawn under it
      int right = width - 2 * WB - (q.scrolling ? Fl::scrollbar_size() : 0);
      _addFields(q.fields, _sideWidth + 2 * WB, fy, right, (int)i, q.columns);
      // the titled sections under them
      for(const auto &section : q.sections) {
        if(section.label.size()) {
          Fl_Box *b = new Fl_Box(_sideWidth + 2 * WB, fy,
                                 width - _sideWidth - 4 * WB, BH);
          b->copy_label(_escaped(section.label).c_str());
          b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
          b->labelfont(FL_HELVETICA_BOLD);
          fy += BH;
        }
        _addFields(section.fields, _sideWidth + 2 * WB, fy, right, (int)i,
                   section.columns);
      }
      if(scroll) scroll->end();
      if(q.buttonLabel.size()) {
        // at the bottom right of the pane, with the same margin under it as
        // around everything else
        Fl_Button *b = new Fl_Button(width - BB - 2 * WB, top + height - BH - WB,
                                     BB, BH, _escaped(q.buttonLabel).c_str());
        // the description owns the action; the window owns a copy of it
        b->callback(_buttonCallback, new std::function<void()>(q.button));
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
        og->copy_label(_escaped(e.family).c_str());
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
      w->callback(_buttonCallback, new std::function<void()>(b.action));
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

void dialogFltk::refresh()
{
  if(!_panel.tabbed) _relayout();

  int shownPane = Dialog::currentPane(_which);
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
    const Dialog::Field &f = b.field;
    switch(f.kind) {
    case Dialog::Label: {
      std::string value = f.getText();
      if(!b.widget->label() || value != b.widget->label())
        b.widget->copy_label(_escaped(value).c_str());
    } break;
    case Dialog::Output: {
      std::string value = f.getText();
      Fl_Output *o = (Fl_Output *)b.widget;
      if(!o->value() || value != o->value()) o->value(value.c_str());
    } break;
    case Dialog::List: {
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
    case Dialog::Color: {
      unsigned int packed = f.getColour();
      Fl_Color shown = fl_rgb_color(CTX::instance()->unpackRed(packed),
                                    CTX::instance()->unpackGreen(packed),
                                    CTX::instance()->unpackBlue(packed));
      if(b.widget->color() != shown) {
        b.widget->color(shown);
        b.widget->redraw();
      }
    } break;
    case Dialog::Direction: {
      double x = 0., y = 0., z = 0.;
      f.getVector(x, y, z);
      ((spherePositionWidget *)b.widget)->setValue(x, y, z);
    } break;
    case Dialog::Action:
    case Dialog::Spacer: break;
    case Dialog::Text: {
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
    case Dialog::Integer:
    case Dialog::Number:
      ((Fl_Value_Input *)b.widget)->value(f.getNumber());
      break;
    case Dialog::Check: {
      bool on = f.getFlag();
      ((Fl_Button *)b.widget)->value(on ? 1 : 0);
      // the arrow of a disclosure points at what clicking it would do
      if(f.disclosure) {
        std::string label = _escaped(f.label) + (on ? " @-28->" : " @-22->");
        if(!b.widget->label() || label != b.widget->label())
          b.widget->copy_label(label.c_str());
      }
    } break;
    case Dialog::Choice: {
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
  if(!_win || _panel.tabbed) return;

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
  Dialog::Panel now = Dialog::panel(_which);
  if(!_win || _signature(now) != _signatureBuilt)
    build(_which);
  else
    _panel = now;
  if(!_win) return;
  _forcePane = true;
  refresh();
  _win->show();
}

void dialogFltk::hide()
{
  if(_win) _win->hide();
}

bool dialogFltk::shown() const { return _win && _win->shown(); }

dialogFltk *fltkDialog(int which, bool create)
{
  static dialogFltk dialogs[Dialog::NumDialogs];
  static bool built[Dialog::NumDialogs] = {false};
  if(which < 0 || which >= Dialog::NumDialogs) return nullptr;
  if(!built[which]) {
    if(!create) return nullptr;
    built[which] = true;
    dialogs[which].build(which);
  }
  return &dialogs[which];
}

#endif
