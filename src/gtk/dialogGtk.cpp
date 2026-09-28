// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GTK)

#include <algorithm>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "gtkCommon.h"
#include "Layout.h" // Ui::fills()

// A described form as GTK boxes, the way the page writes it as flex and grid
// (render(), lines(), cellOf() and cell() of src/browser/page.html, which
// this follows function for function): a box down is its lines, one across a
// line, a grid one GtkGrid for its rows, tabs a notebook. GTK then sizes the
// window itself. What is folded away is left out, as the page leaves it out:
// the window is made again inside when that changes, and only its values are
// put back otherwise.

namespace {

  // the page's pixels, at its 13 pixel font, in em
  const double LineGap = 8. / 13., CellGap = 6. / 13., LinePad = 2. / 13.,
               GridRowGap = 4. / 13., PanePad = 6. / 13.;

  bool _shown(const Ui::Item &it)
  {
    if(it.kind == Ui::Item::AField)
      return !it.field.visible || it.field.visible();
    if(it.kind == Ui::Item::ABox) return !it.box->visible || it.box->visible();
    return it.kind != Ui::Item::Nothing;
  }

  bool _gap(const Ui::Item &it)
  {
    return it.kind == Ui::Item::AField && it.field.kind == Ui::Spacer;
  }

  // leastRows lines of widgets
  int _leastPx(int rows) { return rows * (gtkPx(1.15) + 18); }

  // what the window is made of, as far as it shows: the inside is made again
  // only when this changes
  void _sign(const Ui::Item &it, std::string &s)
  {
    if(!_shown(it)) {
      s += "|-";
      return;
    }
    switch(it.kind) {
    case Ui::Item::AField:
      s += "/" + it.field.label + (char)('a' + it.field.kind);
      if(it.field.kind == Ui::Choice && it.field.multiple) s += '*';
      break;
    case Ui::Item::ABox:
      s += it.box->direction == Ui::Box::Down ? "|v" : "|h";
      if(it.box->grid) s += 'g';
      if(it.box->scrolling) s += 's';
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

  std::string _signature(const Ui::Form &f)
  {
    std::string s = f.title;
    _sign(f.content, s);
    return s;
  }

  // the fields that show, in the order they are made, so that a form of the
  // same shape can be bound to the widgets made for another
  void _fieldsOf(const Ui::Item &it, std::vector<const Ui::Field *> &out)
  {
    if(!_shown(it)) return;
    if(it.kind == Ui::Item::AField) {
      if(it.field.kind != Ui::Spacer) out.push_back(&it.field);
    }
    else if(it.kind == Ui::Item::ABox)
      for(const auto &i : it.box->items) _fieldsOf(i, out);
    else if(it.kind == Ui::Item::ATabs)
      for(const auto &t : it.tabs->tabs) _fieldsOf(t.second, out);
  }

  void _tabsOf(const Ui::Item &it, std::vector<const Ui::Tabs *> &out)
  {
    if(!_shown(it)) return;
    if(it.kind == Ui::Item::ABox)
      for(const auto &i : it.box->items) _tabsOf(i, out);
    else if(it.kind == Ui::Item::ATabs) {
      out.push_back(it.tabs.get());
      for(const auto &t : it.tabs->tabs) _tabsOf(t.second, out);
    }
  }

  // what a column is wide: its widest line, in em -- a field an ordinary
  // width unless it says, and the gaps of a line
  double _widestEm(const Ui::Item &it)
  {
    if(!_shown(it)) return 0.;
    if(it.kind == Ui::Item::ATabs) {
      double most = 0.;
      for(const auto &t : it.tabs->tabs)
        most = std::max(most, _widestEm(t.second));
      return most;
    }
    if(it.kind != Ui::Item::ABox) {
      if(it.kind != Ui::Item::AField) return 0.;
      if(it.field.widthEm > 0.) return it.field.widthEm;
      return _gap(it) ? 2. : 10.;
    }
    std::vector<double> each;
    for(const auto &i : it.box->items)
      if(_shown(i)) each.push_back(_widestEm(i));
    if(it.box->direction == Ui::Box::Down) {
      double most = 0.;
      for(double w : each) most = std::max(most, w);
      return most;
    }
    double sum = 0.;
    for(double w : each) sum += w;
    return sum + LineGap * (each.size() > 1 ? each.size() - 1 : 0);
  }

} // namespace

class dialogGtk {
public:
  const Ui::Form *which = nullptr;
  Ui::Form panel;
  GtkWidget *win = nullptr, *content = nullptr;
  // docked: the content is in a card of the dock of the main window rather
  // than in the window, which is kept hidden
  bool docked = false, moving = false;
  GtkWidget *card = nullptr, *cardTitle = nullptr, *slot = nullptr;
  std::string built;
  // the pane showing, by its label; forced only when just asked for, or it
  // would undo the tab the user clicked
  std::string pane;
  bool forcePane = false;
  struct tabsMade {
    GtkNotebook *book;
    std::vector<std::string> labels;
    std::vector<GtkWidget *> pages;
  };
  std::vector<tabsMade> tabs;
  // the widgets of the fields, in the order of _fieldsOf()
  std::vector<GtkWidget *> fields;
  std::set<std::string> options;
  GtkSizeGroup *before = nullptr;
  GtkWidget *byDefault = nullptr;
  guint tick = 0;
  bool building = false;

  ~dialogGtk();
  void build();
  void reshape();
  void refresh();
  void show();
  void hide();
  bool shown() const
  {
    if(docked) return card && gtk_widget_get_visible(card);
    return win && gtk_widget_get_visible(win);
  }
  // into the dock, or back into its window
  void dock(bool on);
  void applyPane();

private:
  void _place();
  void _makeCard();
  void _render(const Ui::Item &item, GtkWidget *into);
  void _lines(const std::vector<std::vector<const Ui::Item *> > &rows,
              GtkWidget *into, int columns, bool flush, bool inside);
  GtkWidget *_cellOf(const Ui::Item &item, bool column, int holds);
  GtkWidget *_cell(const Ui::Field &f, int holds);
  GtkWidget *_field(const Ui::Field &f);
  static void _switched(GtkNotebook *book, GtkWidget *page, guint n,
                        gpointer data);
};

// --- where the dialogs are kept, and what a change in one of them asks

namespace {

  std::map<const Ui::Form *, dialogGtk *> &_dialogs()
  {
    static std::map<const Ui::Form *, dialogGtk *> dialogs;
    return dialogs;
  }

  bool _closingDown = false;
  GtkWindow *_main = nullptr;
  // the box of the dock, and the forms docked, by id, for as long as Gmsh runs
  GtkWidget *_dockBox = nullptr;
  std::set<std::string> _dockedIds;

  // the dock shows as long as one of its cards does
  void _dockShows()
  {
    if(!_dockBox) return;
    bool any = false;
    for(GtkWidget *c = gtk_widget_get_first_child(_dockBox); c;
        c = gtk_widget_get_next_sibling(c))
      if(gtk_widget_get_visible(c)) any = true;
    GtkWidget *pane = gtk_widget_get_ancestor(_dockBox, GTK_TYPE_SCROLLED_WINDOW);
    if(pane) gtk_widget_set_visible(pane, any);
  }

  dialogGtk *_find(const Ui::Form *which)
  {
    auto it = _dialogs().find(which);
    return it == _dialogs().end() ? nullptr : it->second;
  }

  // once the event is over, the forms changed are looked at again: what
  // changed may have been the shape
  std::set<const Ui::Form *> _pending;

  gboolean _reshapePending(gpointer)
  {
    std::set<const Ui::Form *> now;
    now.swap(_pending);
    for(const Ui::Form *which : now)
      if(dialogGtk *d = _find(which))
        if(d->shown()) d->reshape();
    return G_SOURCE_REMOVE;
  }

  void _askReshape(const Ui::Form *which)
  {
    if(_pending.empty())
      g_idle_add_full(G_PRIORITY_HIGH_IDLE, _reshapePending, nullptr, nullptr);
    _pending.insert(which);
  }

  gboolean _ticked(gpointer data)
  {
    dialogGtk *d = _find((const Ui::Form *)data);
    if(!d || !d->shown()) {
      if(d) d->tick = 0;
      return G_SOURCE_REMOVE;
    }
    d->reshape();
    return G_SOURCE_CONTINUE;
  }

  void _hidden(GtkWidget *, gpointer data)
  {
    dialogGtk *d = _find((const Ui::Form *)data);
    if(!d || _closingDown || d->moving) return;
    // hiding a dialog undoes what it leaves behind, however it went
    std::function<void()> closed = d->panel.closed;
    if(closed) gtkLater(closed);
  }

  gboolean _dialogKey(GtkEventControllerKey *c, guint keyval, guint,
                      GdkModifierType state, gpointer)
  {
    GtkWidget *win = gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(c));
    if(keyval == GDK_KEY_Escape && !(state & GDK_MODIFIER_MASK)) {
      gtk_window_close(GTK_WINDOW(win));
      return TRUE;
    }
    // what nothing in the dialog took is Gmsh's, as in the main window
    return gtkMainKey(keyval, state);
  }

} // namespace

dialogGtk::~dialogGtk()
{
  if(tick) g_source_remove(tick);
  if(before) g_object_unref(before);
  if(card && gtk_widget_get_parent(card))
    gtk_box_remove(GTK_BOX(gtk_widget_get_parent(card)), card);
  if(card) g_object_unref(card);
  if(content) g_object_unref(content);
  if(win) gtk_window_destroy(GTK_WINDOW(win));
  _dockShows();
}

namespace {

  void _toDock(GtkButton *, gpointer data)
  {
    const Ui::Form *which = (const Ui::Form *)data;
    gtkLater([which]() {
      if(dialogGtk *d = _find(which)) d->dock(true);
    });
  }

  void _toFloat(GtkButton *, gpointer data)
  {
    const Ui::Form *which = (const Ui::Form *)data;
    gtkLater([which]() {
      if(dialogGtk *d = _find(which)) d->dock(false);
    });
  }

  void _cardClosed(GtkButton *, gpointer data)
  {
    const Ui::Form *which = (const Ui::Form *)data;
    gtkLater([which]() {
      if(dialogGtk *d = _find(which)) d->hide();
    });
  }

  GtkWidget *_small(const char *label, const char *tip, GCallback clicked,
                    const Ui::Form *which)
  {
    GtkWidget *b = gtk_button_new_with_label(label);
    gtk_widget_add_css_class(b, "flat");
    gtk_widget_set_tooltip_text(b, tip);
    g_signal_connect(b, "clicked", clicked, (gpointer)which);
    return b;
  }

} // namespace

// a card of the dock: its title, a button to let it float, one to close it,
// then the content
void dialogGtk::_makeCard()
{
  if(card) return;
  card = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  g_object_ref_sink(card);
  gtk_widget_add_css_class(card, "frame");
  gtk_widget_set_margin_bottom(card, 8);
  GtkWidget *head = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
  gtk_widget_add_css_class(head, "toolbar");
  cardTitle = gtk_label_new(panel.title.c_str());
  gtk_widget_add_css_class(cardTitle, "heading");
  gtk_label_set_xalign(GTK_LABEL(cardTitle), 0.f);
  gtk_label_set_ellipsize(GTK_LABEL(cardTitle), PANGO_ELLIPSIZE_END);
  gtk_widget_set_hexpand(cardTitle, TRUE);
  gtk_box_append(GTK_BOX(head), cardTitle);
  gtk_box_append(GTK_BOX(head), _small("\u2750", "Let it float",
                                        G_CALLBACK(_toFloat), which));
  gtk_box_append(GTK_BOX(head), _small("\u00d7", "Close",
                                        G_CALLBACK(_cardClosed), which));
  gtk_box_append(GTK_BOX(card), head);
  gtk_box_append(GTK_BOX(card), gtk_separator_new(GTK_ORIENTATION_HORIZONTAL));
  slot = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_append(GTK_BOX(card), slot);
}

// the content where it belongs: in the card, or in the window
void dialogGtk::_place()
{
  if(!content) return;
  GtkWidget *parent = gtk_widget_get_parent(content);
  if(docked) {
    _makeCard();
    gtk_label_set_text(GTK_LABEL(cardTitle), panel.title.c_str());
    if(parent == slot) return;
    if(parent) gtk_window_set_child(GTK_WINDOW(win), nullptr);
    gtk_box_append(GTK_BOX(slot), content);
    if(_dockBox && !gtk_widget_get_parent(card))
      gtk_box_append(GTK_BOX(_dockBox), card);
    gtk_window_set_default_widget(GTK_WINDOW(win), nullptr);
  }
  else {
    if(parent == win) return;
    if(parent) gtk_box_remove(GTK_BOX(parent), content);
    gtk_window_set_child(GTK_WINDOW(win), content);
    gtk_window_set_default_widget(GTK_WINDOW(win), byDefault);
  }
}

void dialogGtk::dock(bool on)
{
  if(on == docked || (on && !_dockBox)) return;
  bool was = shown();
  moving = true;
  if(on) {
    _dockedIds.insert(panel.id);
    if(win) gtk_widget_set_visible(win, FALSE);
    docked = true;
    _place();
    if(card) gtk_widget_set_visible(card, was);
  }
  else {
    _dockedIds.erase(panel.id);
    if(card) gtk_widget_set_visible(card, FALSE);
    docked = false;
    _place();
    if(was) gtk_window_present(GTK_WINDOW(win));
  }
  moving = false;
  _dockShows();
}

// --- the translation

// a field's widget, told to look at the whole form again once changed
GtkWidget *dialogGtk::_field(const Ui::Field &f)
{
  const Ui::Form *form = which;
  GtkWidget *w = gtkFieldWidget(f, [form]() { _askReshape(form); });
  if(!w) return nullptr;
  fields.push_back(w);
  if(f.option.size()) options.insert(f.option);
  // Enter in a field presses the button that is the default
  if(f.kind == Ui::Text || f.kind == Ui::Integer || f.kind == Ui::Number)
    if(GTK_IS_ENTRY(w)) gtk_entry_set_activates_default(GTK_ENTRY(w), TRUE);
  if(f.kind == Ui::Action && f.isDefault) byDefault = w;
  return w;
}

// the cell of a field: its widget, the buttons after it, its name
GtkWidget *dialogGtk::_cell(const Ui::Field &f, int holds)
{
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, gtkPx(CellGap));
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
  bool whole = (f.kind == Ui::List || f.kind == Ui::Hierarchy ||
                f.kind == Ui::Prose || f.kind == Ui::ColorMap) &&
               !(f.widthEm > 0.) && !(f.widthShare > 0.);
  if(whole) gtk_widget_set_hexpand(box, TRUE);
  if(f.kind == Ui::Spacer) {
    // eats what is left of the line, never less than two em
    gtk_widget_set_hexpand(box, TRUE);
    gtk_widget_set_size_request(box, gtkPx(f.widthEm > 0. ? f.widthEm : 2.),
                                -1);
    return box;
  }
  if(f.kind == Ui::Label) {
    GtkWidget *say = _field(f);
    if(f.widthEm > 0.)
      gtk_widget_set_size_request(say, gtkPx(f.widthEm), -1);
    if(f.align != Ui::Left || f.wraps) {
      gtk_widget_set_hexpand(box, TRUE);
      gtk_widget_set_hexpand(say, TRUE);
    }
    if(f.wraps) gtk_widget_set_valign(box, GTK_ALIGN_START);
    gtk_box_append(GTK_BOX(box), say);
    return box;
  }
  if(f.kind == Ui::Check && f.disclosure) {
    // a disclosure is a button at the end of its line
    gtk_widget_set_hexpand(box, TRUE);
    GtkWidget *b = _field(f);
    gtk_widget_set_halign(b, GTK_ALIGN_END);
    gtk_widget_set_hexpand(b, TRUE);
    gtk_box_append(GTK_BOX(box), b);
    return box;
  }
  GtkWidget *what = _field(f);
  if(!what) return box;
  // in em, or as a fraction of one field, or a share of one when several
  // values share the line
  bool value = f.kind == Ui::Text || f.kind == Ui::Integer ||
               f.kind == Ui::Number || f.kind == Ui::Output ||
               f.kind == Ui::Color || (f.kind == Ui::Choice && !f.multiple);
  int wide = -1;
  if(f.widthEm > 0.)
    wide = gtkPx(f.widthEm);
  else if(f.widthShare > 0.)
    wide = gtkPx(10. * f.widthShare);
  else if(value) {
    double em = 10. / std::max(1, holds);
    // a dropdown sharing a line takes its arrow on top of its share
    if(f.kind == Ui::Choice && holds > 1) em += 1.8;
    wide = gtkPx(em);
  }
  if(f.kind == Ui::Action || f.kind == Ui::Menu ||
     (f.kind == Ui::Choice && f.multiple)) {
    if(wide > 0) gtk_widget_set_size_request(what, wide, -1);
    // tall(n): as tall as the column beside it
    if(f.rows > 1 && f.hangs) {
      gtk_widget_set_valign(box, GTK_ALIGN_FILL);
      gtk_widget_set_vexpand(what, TRUE);
    }
    gtk_box_append(GTK_BOX(box), what);
    return box;
  }
  if(f.kind == Ui::ColorMap) {
    gtk_widget_set_hexpand(box, TRUE);
    gtk_widget_set_vexpand(box, TRUE);
    gtk_widget_set_valign(box, GTK_ALIGN_FILL);
    gtk_widget_set_hexpand(what, TRUE);
    gtk_widget_set_vexpand(what, TRUE);
    if(wide > 0) gtk_widget_set_size_request(what, wide, gtkPx(8.));
    gtk_box_append(GTK_BOX(box), what);
    return box;
  }
  GtkWidget *say = nullptr;
  if(f.label.size() && f.kind != Ui::Check) {
    say = gtk_label_new(f.label.c_str());
    gtk_label_set_xalign(GTK_LABEL(say), f.labelBefore ? 1.f : 0.f);
    if(f.alert) gtk_widget_add_css_class(say, "error");
  }
  if(f.kind == Ui::List || f.kind == Ui::Hierarchy) {
    gtk_widget_set_valign(box, GTK_ALIGN_FILL);
    if(wide > 0) gtk_widget_set_size_request(what, wide, -1);
    if(whole) gtk_widget_set_hexpand(what, TRUE);
    if(!f.rows) {
      gtk_widget_set_vexpand(what, TRUE);
      gtk_widget_set_vexpand(box, TRUE);
    }
    gtk_box_append(GTK_BOX(box), what);
    if(say) gtk_box_append(GTK_BOX(box), say);
    return box;
  }
  if(f.kind == Ui::Prose) gtk_widget_set_hexpand(what, TRUE);
  if(wide > 0) gtk_widget_set_size_request(what, wide, -1);
  std::vector<GtkWidget *> after;
  for(const Ui::Button &b : f.trailing) {
    const Ui::Form *form = which;
    after.push_back(gtkButtonWidget(b, [form]() { _askReshape(form); }));
  }
  if(f.labelBefore) {
    // the names before their fields line up, as wide as the widest
    if(say) {
      gtk_size_group_add_widget(before, say);
      gtk_box_append(GTK_BOX(box), say);
    }
    gtk_box_append(GTK_BOX(box), what);
    for(GtkWidget *b : after) gtk_box_append(GTK_BOX(box), b);
  }
  else {
    gtk_box_append(GTK_BOX(box), what);
    for(GtkWidget *b : after) gtk_box_append(GTK_BOX(box), b);
    if(say) gtk_box_append(GTK_BOX(box), say);
  }
  return box;
}

// a cell of a line: a field, or a box or tabs standing in it -- a column
// when it runs the height of the line
GtkWidget *dialogGtk::_cellOf(const Ui::Item &item, bool column, int holds)
{
  if(column && Ui::fills(item)) {
    GtkWidget *aside = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(aside, gtkPx(_widestEm(item)), -1);
    gtk_widget_set_valign(aside, GTK_ALIGN_FILL);
    gtk_widget_set_vexpand(aside, TRUE);
    _render(item, aside);
    return aside;
  }
  if(item.kind == Ui::Item::ABox || item.kind == Ui::Item::ATabs) {
    // what is left of the line
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_hexpand(box, TRUE);
    gtk_widget_set_valign(box, GTK_ALIGN_FILL);
    gtk_widget_add_css_class(box, "gmsh-inbox");
    _render(item, box);
    return box;
  }
  return _cell(item.field, holds);
}

// one line of cells for each row, or a box's rows on one grid; flush:
// hbox(..., 0.), its cells touching
void dialogGtk::_lines(const std::vector<std::vector<const Ui::Item *> > &rows,
                       GtkWidget *into, int columns, bool flush, bool inside)
{
  GtkWidget *grid = nullptr;
  int gridRow = 0;
  for(const auto &row : rows) {
    bool packed = false, grows = false, spaced = false, others = false;
    int holds = 0;
    for(const Ui::Item *i : row) {
      bool field = i->kind == Ui::Item::AField;
      if(field && i->field.packed) packed = true;
      if(Ui::fills(*i))
        grows = true;
      else if(!_gap(*i))
        others = true;
      if(_gap(*i)) spaced = true;
      if(field) {
        const Ui::Field &f = i->field;
        if(f.kind != Ui::Label && f.kind != Ui::Spacer &&
           f.kind != Ui::Action && f.kind != Ui::List &&
           f.kind != Ui::Hierarchy && f.kind != Ui::Check &&
           f.kind != Ui::ColorMap && !(f.widthEm > 0.) &&
           !(f.widthShare > 0.))
          holds++;
      }
    }
    // a filling list takes what is left of the height; a box that fills is
    // a column, the rest beside it
    bool column = grows && others;
    (void)packed;

    // a run of packed fields is one thing, drawn as one box split, and what
    // is around it another
    std::vector<GtkWidget *> parts;
    {
      GtkWidget *run = nullptr;
      bool said = false;
      for(const Ui::Item *i : row) {
        GtkWidget *one = _cellOf(*i, column, holds);
        bool packedField = i->kind == Ui::Item::AField && i->field.packed &&
                           !_gap(*i) && !i->field.disclosure;
        if(packedField) {
          if(!run) {
            run = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
            gtk_widget_set_valign(run, GTK_ALIGN_CENTER);
            parts.push_back(run);
          }
          // flush only where it is one value split in two: snaps each named
          // after its axis stand off from one another
          if(said) gtk_widget_set_margin_start(one, gtkPx(LineGap));
          said = !i->field.label.empty();
          gtk_box_append(GTK_BOX(run), one);
          continue;
        }
        said = false;
        run = nullptr;
        parts.push_back(one);
      }
    }
    // with a gap on the line each cell takes what it needs, the gap the rest
    if(spaced)
      for(std::size_t k = 0; k < parts.size(); k++)
        if(!(k < row.size() && _gap(*row[k])))
          gtk_widget_set_hexpand(parts[k], FALSE);

    // the names after a run are not the same width on all rows: on the grid
    // the column is as wide as the widest
    if(columns > 1 && !grows) {
      if(!grid) {
        grid = gtk_grid_new();
        gtk_grid_set_column_spacing(GTK_GRID(grid), gtkPx(LineGap));
        gtk_grid_set_row_spacing(GTK_GRID(grid), gtkPx(GridRowGap));
        int pad = gtkPx(LinePad);
        gtk_widget_set_margin_top(grid, pad);
        gtk_widget_set_margin_bottom(grid, pad);
        gtk_widget_set_margin_start(grid, inside ? 0 : pad);
        gtk_widget_set_margin_end(grid, inside ? 0 : pad);
        gtk_box_append(GTK_BOX(into), grid);
        gridRow = 0;
      }
      for(std::size_t k = 0; k < parts.size(); k++) {
        // the last field of a line runs on to the end of the grid
        int span = (k + 1 == parts.size()) ? std::max(1, columns - (int)k) : 1;
        gtk_widget_set_halign(parts[k], GTK_ALIGN_START);
        gtk_grid_attach(GTK_GRID(grid), parts[k], (int)k, gridRow, span, 1);
      }
      gridRow++;
      continue;
    }
    grid = nullptr;
    GtkWidget *line =
      gtk_box_new(GTK_ORIENTATION_HORIZONTAL, flush ? 0 : gtkPx(LineGap));
    int pad = gtkPx(LinePad);
    gtk_widget_set_margin_top(line, pad);
    gtk_widget_set_margin_bottom(line, pad);
    gtk_widget_set_margin_start(line, inside ? 0 : pad);
    gtk_widget_set_margin_end(line, inside ? 0 : pad);
    if(grows) {
      gtk_widget_set_vexpand(line, TRUE);
      // the least of what fills, in lines
      if(panel.leastRows > 0 && !column)
        gtk_widget_set_size_request(line, -1, _leastPx(panel.leastRows));
      if(column) gtk_box_set_spacing(GTK_BOX(line), gtkPx(4. / 13.));
    }
    for(GtkWidget *p : parts) gtk_box_append(GTK_BOX(line), p);
    gtk_box_append(GTK_BOX(into), line);
  }
}

// the tree of a form: a box down is its lines, one across a line, tabs a row
// of them over their panes
void dialogGtk::_render(const Ui::Item &item, GtkWidget *into)
{
  if(!_shown(item)) return;
  bool inside = gtk_widget_has_css_class(into, "gmsh-inbox");
  switch(item.kind) {
  case Ui::Item::ATabs: {
    GtkWidget *book = gtk_notebook_new();
    // the row of tabs decides how wide the window is, as on the page
    gtk_notebook_set_scrollable(GTK_NOTEBOOK(book), FALSE);
    // in the order _tabsOf() walks them: the outer tabs before the inner
    std::size_t at = tabs.size();
    tabs.push_back(tabsMade());
    tabs[at].book = GTK_NOTEBOOK(book);
    bool fills = false;
    for(const auto &t : item.tabs->tabs) {
      GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
      int pad = gtkPx(PanePad);
      gtk_widget_set_margin_top(page, pad);
      gtk_widget_set_margin_bottom(page, pad);
      gtk_widget_set_margin_start(page, pad);
      gtk_widget_set_margin_end(page, pad);
      _render(t.second, page);
      if(Ui::fills(t.second)) fills = true;
      gtk_notebook_append_page(GTK_NOTEBOOK(book), page,
                               gtk_label_new(t.first.size() ? t.first.c_str() :
                                                              "·"));
      tabs[at].labels.push_back(t.first);
      tabs[at].pages.push_back(page);
    }
    if(fills) gtk_widget_set_vexpand(book, TRUE);
    if(panel.leastRows > 0)
      gtk_widget_set_size_request(book, -1, _leastPx(panel.leastRows));
    g_signal_connect(book, "switch-page", G_CALLBACK(_switched), this);
    gtk_box_append(GTK_BOX(into), book);
  } break;
  case Ui::Item::AHeading: {
    GtkWidget *h = gtk_label_new(item.text.c_str());
    gtk_widget_add_css_class(h, "heading");
    gtk_label_set_xalign(GTK_LABEL(h), 0.f);
    gtk_widget_set_margin_top(h, gtkPx(.5));
    gtk_widget_set_margin_bottom(h, gtkPx(.2));
    gtk_box_append(GTK_BOX(into), h);
  } break;
  case Ui::Item::ARule: {
    GtkWidget *r = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_widget_set_margin_top(r, gtkPx(.3));
    gtk_widget_set_margin_bottom(r, gtkPx(.3));
    gtk_box_append(GTK_BOX(into), r);
  } break;
  case Ui::Item::AField:
    if(_gap(item)) {
      // a gap down a column: what is left of its height
      GtkWidget *g = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
      gtk_widget_set_vexpand(g, TRUE);
      gtk_box_append(GTK_BOX(into), g);
    }
    else
      _lines({{&item}}, into, 0, false, inside);
    break;
  case Ui::Item::ABox: {
    const Ui::Box &b = *item.box;
    if(b.scrolling) {
      GtkWidget *scroll = gtk_scrolled_window_new();
      gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
                                     GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
      gtk_widget_set_vexpand(scroll, TRUE);
      gtk_scrolled_window_set_min_content_height(
        GTK_SCROLLED_WINDOW(scroll),
        panel.leastRows > 0 ? _leastPx(panel.leastRows) : gtkPx(8.));
      GtkWidget *main = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
      if(inside) gtk_widget_add_css_class(main, "gmsh-inbox");
      gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll), main);
      Ui::Item plain = item;
      plain.box = std::make_shared<Ui::Box>(b);
      plain.box->scrolling = false;
      _render(plain, main);
      gtk_box_append(GTK_BOX(into), scroll);
      break;
    }
    if(b.direction == Ui::Box::Across || b.grid) {
      std::vector<std::vector<const Ui::Item *> > rows;
      if(b.direction == Ui::Box::Across) {
        rows.emplace_back();
        for(const auto &i : b.items)
          if(_shown(i)) rows.back().push_back(&i);
      }
      else
        for(const auto &i : b.items) {
          if(!_shown(i)) continue;
          // the rows of a grid are its boxes across; a field on its own is a
          // row of one
          if(i.kind == Ui::Item::ABox && i.box->direction == Ui::Box::Across &&
             !i.box->grid && !i.box->scrolling) {
            rows.emplace_back();
            for(const auto &j : i.box->items)
              if(_shown(j)) rows.back().push_back(&j);
          }
          else
            rows.push_back({&i});
        }
      int columns = 0;
      if(b.grid)
        for(const auto &r : rows) columns = std::max(columns, (int)r.size());
      _lines(rows, into, b.grid ? std::max(1, columns) : 0, b.padding == 0.,
             inside);
      break;
    }
    for(const auto &i : b.items) _render(i, into);
  } break;
  default: break;
  }
}

// --- the window

void dialogGtk::_switched(GtkNotebook *book, GtkWidget *page, guint n,
                          gpointer data)
{
  dialogGtk *d = (dialogGtk *)data;
  if(d->building) return;
  for(std::size_t t = 0; t < d->tabs.size(); t++) {
    if(d->tabs[t].book != book || n >= d->tabs[t].labels.size()) continue;
    std::string label = d->tabs[t].labels[n];
    bool moved = d->pane != label;
    d->pane = label;
    // the description must follow the tab clicked, or the next refresh puts
    // the pane it remembers back; told once the switch is over, as what it
    // does may make the window again
    std::vector<const Ui::Tabs *> all;
    _tabsOf(d->panel.content, all);
    if(!moved || t >= all.size() || !all[t]->chosen) return;
    std::function<void(const std::string &)> chosen = all[t]->chosen;
    gtkLater([chosen, label]() { chosen(label); });
    return;
  }
}

void dialogGtk::applyPane()
{
  if(!forcePane || pane.empty()) return;
  forcePane = false;
  building = true;
  for(auto &t : tabs)
    for(std::size_t k = 0; k < t.labels.size(); k++) {
      if(t.labels[k] != pane) continue;
      gtk_notebook_set_current_page(t.book, (int)k);
      // and the tabs the pane's are in, for tabs under tabs
      GtkWidget *inner = GTK_WIDGET(t.book);
      bool again = true;
      while(again) {
        again = false;
        for(auto &o : tabs)
          for(std::size_t j = 0; j < o.pages.size(); j++)
            if(o.pages[j] != inner && gtk_widget_is_ancestor(inner, o.pages[j])) {
              gtk_notebook_set_current_page(o.book, (int)j);
              inner = GTK_WIDGET(o.book);
              again = true;
            }
      }
    }
  building = false;
}

void dialogGtk::build()
{
  building = true;
  panel = *which;
  built = _signature(panel);
  if(!win) {
    win = gtk_window_new();
    gtk_window_set_hide_on_close(GTK_WINDOW(win), TRUE);
    if(_main) gtk_window_set_transient_for(GTK_WINDOW(win), _main);
    g_signal_connect(win, "hide", G_CALLBACK(_hidden), (gpointer)which);
    GtkEventController *keys = gtk_event_controller_key_new();
    g_signal_connect(keys, "key-pressed", G_CALLBACK(_dialogKey), nullptr);
    gtk_widget_add_controller(win, keys);
    gtkWatchButtons(win);
    GtkWidget *head = gtk_header_bar_new();
    gtk_header_bar_pack_end(GTK_HEADER_BAR(head),
                            _small("\u25a4", "Dock it to the side",
                                   G_CALLBACK(_toDock), which));
    gtk_window_set_titlebar(GTK_WINDOW(win), head);
    docked = _dockBox && _dockedIds.count(which->id);
  }
  gtk_window_set_title(GTK_WINDOW(win), panel.title.c_str());
  // the old widgets go with their box
  tabs.clear();
  fields.clear();
  options.clear();
  byDefault = nullptr;
  if(before) g_object_unref(before);
  before = gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
  // the old content out of wherever it was
  if(content) {
    if(GtkWidget *parent = gtk_widget_get_parent(content)) {
      if(parent == win)
        gtk_window_set_child(GTK_WINDOW(win), nullptr);
      else
        gtk_box_remove(GTK_BOX(parent), content);
    }
    g_object_unref(content);
  }
  content = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  g_object_ref_sink(content);
  int pad = gtkPx(5. / 13.);
  gtk_widget_set_margin_top(content, pad);
  gtk_widget_set_margin_bottom(content, pad);
  gtk_widget_set_margin_start(content, pad);
  gtk_widget_set_margin_end(content, pad);
  // never so narrow that a dialog with little in it looks starved
  gtk_widget_set_size_request(content, gtkPx(12.), -1);
  _render(panel.content, content);
  _place();
  forcePane = true;
  building = false;
  applyPane();
}

void dialogGtk::refresh()
{
  applyPane();
  std::vector<const Ui::Field *> now;
  _fieldsOf(panel.content, now);
  for(std::size_t i = 0; i < fields.size(); i++) {
    if(i < now.size()) gtkRebindField(fields[i], *now[i]);
    gtkRefreshField(fields[i]);
  }
}

void dialogGtk::reshape()
{
  if(!which) return;
  Ui::Form now = *which;
  if(!win || _signature(now) != built) {
    // the pane showing stays
    build();
    refresh();
    return;
  }
  panel = now;
  refresh();
}

void dialogGtk::show()
{
  Ui::Form now = *which;
  if(!win || _signature(now) != built) build();
  panel = now;
  forcePane = true;
  refresh();
  if(docked) {
    gtk_widget_set_visible(card, TRUE);
    _dockShows();
  }
  else
    gtk_window_present(GTK_WINDOW(win));
  if(panel.refreshEvery > 0. && !tick)
    tick = g_timeout_add((guint)(panel.refreshEvery * 1000.), _ticked,
                         (gpointer)which);
}

void dialogGtk::hide()
{
  if(docked) {
    if(!card || !gtk_widget_get_visible(card)) return;
    gtk_widget_set_visible(card, FALSE);
    _dockShows();
    // hiding a dialog undoes what it leaves behind, as its window does
    if(!_closingDown && panel.closed) gtkLater(panel.closed);
    return;
  }
  if(win) gtk_widget_set_visible(win, FALSE);
}

// --- what the backend asks

namespace {
  dialogGtk *_dialog(const Ui::Form &form)
  {
    dialogGtk *d = _find(&form);
    if(d) return d;
    d = new dialogGtk;
    d->which = &form;
    _dialogs()[&form] = d;
    return d;
  }
} // namespace

void gtkShowForm(const Ui::Form &form, bool show)
{
  if(!show) {
    if(dialogGtk *d = _find(&form)) d->hide();
    return;
  }
  _dialog(form)->show();
}

bool gtkFormVisible(const Ui::Form &form)
{
  dialogGtk *d = _find(&form);
  return d && d->shown();
}

std::string gtkFormPane(const Ui::Form &form)
{
  dialogGtk *d = _find(&form);
  return d ? d->pane : "";
}

void gtkSetFormPane(const Ui::Form &form, const std::string &pane)
{
  dialogGtk *d = _dialog(form);
  d->pane = pane;
  d->forcePane = true;
  if(d->shown()) d->applyPane();
}

void gtkReloadForm(const Ui::Form &form, bool shape)
{
  dialogGtk *d = _find(&form);
  if(d && d->shown()) d->reshape();
}

void gtkDropForm(const Ui::Form &form)
{
  auto it = _dialogs().find(&form);
  if(it == _dialogs().end()) return;
  dialogGtk *d = it->second;
  _dialogs().erase(it);
  _pending.erase(&form);
  // not a closing by the user
  bool was = _closingDown;
  _closingDown = true;
  delete d;
  _closingDown = was;
}

void gtkFormOptionChanged(const std::string &name)
{
  for(auto &it : _dialogs()) {
    dialogGtk *d = it.second;
    if(!d->shown() || !d->options.count(name)) continue;
    d->refresh();
  }
}

void gtkFormsClosingDown()
{
  _closingDown = true;
  for(auto &it : _dialogs()) delete it.second;
  _dialogs().clear();
  _pending.clear();
}

void gtkSetMainWindow(GtkWindow *window) { _main = window; }

void gtkSetDock(GtkWidget *box)
{
  _dockBox = box;
  _dockShows();
}

GtkWindow *gtkMainWindow() { return _main; }

#endif
