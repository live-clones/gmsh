// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// A described form as a window of FLTK: placed by Ui::placeTree, one widget per
// field, bound to the variable the description points at; built again when
// its shape changes, read again when it is shown or refreshed.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H> // fl_font, fl_width

#include "fltkCommon.h"

namespace {

  // the FLTK side of a described form: one widget per field, bound to the
  // variable the description points at

  class dialogFltk {
  public:
    dialogFltk() : _which(nullptr), _win(nullptr), _forcePane(false) {}
    ~dialogFltk();
    void build(const Ui::Form &form);
    void show();
    void hide();
    bool shown() const;
    Fl_Window *window() { return _win; }
    void refresh();
    void optionChanged(const std::string &name);
    // building the window again first: the shape changed
    void reshape();
    // a pane named before the window is built is kept for it
    std::string pane() const;
    void setPane(const std::string &pane);

  private:
    const Ui::Form *_which;
    Ui::Form _panel;
    // the pane showing, by its label
    std::string _pane;
    std::string _paneWanted;
    std::string _signatureBuilt;
    Fl_Window *_win;
    struct paneGroup {
      std::string label;
      Fl_Group *group;
      Fl_Tabs *tabs;
      // the placed item the tabs are, by index: a reload moves the items
      std::size_t index;
    };
    std::vector<paneGroup> _panes;
    // where the solver put everything, in em from the top left of the window's
    // margin; the group or rule made for an item, by its index
    std::vector<Ui::PlacedItem> _placed;
    // the list beside the rest is alone in its column, see Ui::aloneInColumn
    bool _aloneInColumn = false;
    std::vector<Fl_Widget *> _groups;
    // what was folded away when the widgets were last placed
    std::string _folding;
    Ui::Placement _placement(const Ui::Form &p);
    bool _relayout(bool always);
    // the windows inside a group shown as their panes are
    void _showWindows(Fl_Group *group);
    struct bound {
      Ui::Field field;
      Fl_Widget *widget;
      // the box its name is written on when it has buttons after it, moved with
      // it
      Fl_Widget *labelBox = nullptr;
      std::vector<Fl_Widget *> trailing;
      // which placed item, so that a reload reads the field again from a form
      // of the same shape
      std::size_t index = 0;
    };
    std::vector<bound> _fields;
    std::multimap<std::string, std::size_t> _byOption;
    // keeps the widest width asked for, so that it sits still
    int _widestSeen = 0;
    // forced only when just asked for, or it would undo the tab the user clicked
    bool _forcePane;
    void _addItem(std::size_t index, Fl_Group *into);
    void _place(bound &b, const Ui::PlacedItem &p);
    static void _tabCallback(Fl_Widget *w, void *data);
    static void _tick(void *data);
  };

  // while the interface is taken down a dialog that undoes something when it
  // closes must not: there is no view left to draw into
  static bool _closingDown = false;

  void _closing() { _closingDown = true; }

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
        return (fl_width(fltkEscaped(s).c_str()) + 6) / em;
      };
      m.widget = [em, RH](const Ui::Field &f) -> Ui::Size {
        fl_font(f.heading ? FL_HELVETICA_BOLD : FL_HELVETICA, FL_NORMAL_SIZE);
        double text = fl_width(fltkEscaped(f.label).c_str()) / em;
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
        return fltkProseHeight(f.prose(), (int)(width * em)) / em;
      };
      return m;
    }

  } // namespace

  dialogFltk::~dialogFltk()
  {
    if(_win) Fl::delete_widget(_win);
  }

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
    bool tall = f.kind == Ui::Label || f.kind == Ui::Prose ||
                f.kind == Ui::List || f.kind == Ui::Hierarchy ||
                f.kind == Ui::ColorMap || f.kind == Ui::Direction ||
                (f.kind == Ui::Action && f.hangs && !f.isDefault);
    Fl_Widget *widget = fltkFieldWidget(f, fx, fy, fieldW, tall ? fieldH : RH,
                                        [this]() { reshape(); });
    if(!widget) return;
    into->add(widget);
    bound b;
    for(std::size_t t = 0; t < f.trailing.size() && t < p.trailing.size();
        t++) {
      Fl_Button *made =
        fltkButtonWidget(f.trailing[t], WB + px(p.trailing[t].x), fy,
                         px(p.trailing[t].w), RH, "field");
      into->add(made);
      b.trailing.push_back(made);
    }
    // FLTK draws a name to the right of the widget it belongs to: after the
    // buttons, a box of its own
    if(p.label.w > 0. && !f.labelBefore) {
      widget->label(nullptr);
      Fl_Box *say = new Fl_Box(WB + px(p.label.x), fy, px(p.label.w), RH);
      say->copy_label(fltkEscaped(f.label).c_str());
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
    if(_win && Ui::signature(now) == _signatureBuilt) {
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
    std::string folded = Ui::folding(_panel);
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
      if(p.field.kind == b.field.kind) {
        b.field = p.field;
        fltkRebindField(b.widget, p.field);
      }
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
    _signatureBuilt = Ui::signature(_panel);
    _folding = Ui::folding(_panel);
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
          pg->copy_label(t.first.c_str());
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
    for(auto &b : _fields) fltkRefreshField(b.widget);
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
      fltkRefreshField(_fields[it->second].widget);
    for(auto &b : _fields) fltkEnableField(b.widget);
    if(_win) _win->redraw();
  }

  void dialogFltk::show()
  {
    // rebuilding a window that is up makes it blink and come back elsewhere
    if(!_which) return;
    Ui::Form now = *_which;
    if(!_win || Ui::signature(now) != _signatureBuilt)
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

  // a map keeps the addresses steady: the widgets rely on them
  std::map<const Ui::Form *, dialogFltk> &_dialogs()
  {
    static std::map<const Ui::Form *, dialogFltk> dialogs;
    return dialogs;
  }

  // a pane asked for before the window is made
  std::map<const Ui::Form *, std::string> _paneWanted;

  // create false asks for a dialog only if it exists: a window built while
  // a group is open would be a child of it
  dialogFltk *_dialog(const Ui::Form &which, bool create)
  {
    std::map<const Ui::Form *, dialogFltk> &dialogs = _dialogs();
    auto it = dialogs.find(&which);
    if(it == dialogs.end()) {
      if(!create) return nullptr;
      it = dialogs.emplace(&which, dialogFltk()).first;
      auto wanted = _paneWanted.find(&which);
      if(wanted != _paneWanted.end()) {
        it->second.setPane(wanted->second);
        _paneWanted.erase(wanted);
      }
      it->second.build(which);
    }
    return &it->second;
  }

} // namespace

void fltkFormsClosingDown() { _closing(); }

void fltkShowForm(const Ui::Form &form, bool show)
{
  dialogFltk *d = _dialog(form, true);
  if(!d) return;
  if(show)
    d->show();
  else
    d->hide();
}

bool fltkFormVisible(const Ui::Form &form)
{
  dialogFltk *d = _dialog(form, false);
  return d && d->shown();
}

std::string fltkFormPane(const Ui::Form &form)
{
  dialogFltk *d = _dialog(form, false);
  if(d) return d->pane();
  auto it = _paneWanted.find(&form);
  return it == _paneWanted.end() ? "" : it->second;
}

void fltkSetFormPane(const Ui::Form &form, const std::string &pane)
{
  if(dialogFltk *d = _dialog(form, false))
    d->setPane(pane);
  else
    _paneWanted[&form] = pane;
}

void fltkReloadForm(const Ui::Form &form)
{
  dialogFltk *d = _dialog(form, false);
  if(d && d->shown()) d->reshape();
}

void fltkDropForm(const Ui::Form &form)
{
  _dialogs().erase(&form);
  _paneWanted.erase(&form);
}

void fltkFormOptionChanged(const std::string &name)
{
  for(auto &it : _dialogs())
    if(it.second.shown()) it.second.optionChanged(name);
}

bool fltkFormPosition(int &x, int &y)
{
  for(auto &it : _dialogs())
    if(it.second.shown()) {
      x = it.second.window()->x();
      y = it.second.window()->y();
      return true;
    }
  return false;
}

void fltkFormsToFront()
{
  for(auto &it : _dialogs())
    if(it.second.shown()) it.second.window()->show();
}
