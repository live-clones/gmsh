// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#include "gtkCommon.h"
#include "MapEditor.h"
#include "Tree.h"

// The widget of one field. Each carries its binding -- a copy of the field,
// and what the holder does after a change -- for as long as it lives: a
// change the user makes is written through the field, then told, then
// `after` runs; a refresh reads the field and puts the value back, quietly.

// --- the size of the font

namespace {

  double _em = 0.;

  double _fontPixels()
  {
    GtkWidget *probe = gtk_label_new("");
    g_object_ref_sink(probe);
    PangoContext *pc = gtk_widget_get_pango_context(probe);
    const PangoFontDescription *d = pango_context_get_font_description(pc);
    double size = d ? pango_font_description_get_size(d) / (double)PANGO_SCALE :
                      0.;
    if(d && !pango_font_description_get_size_is_absolute(d)) {
      double dpi = pango_cairo_context_get_resolution(pc);
      if(dpi <= 0.) dpi = 96.;
      size *= dpi / 72.;
    }
    g_object_unref(probe);
    return size > 1. ? size : 14.;
  }

} // namespace

double gtkEm()
{
  if(_em <= 0.) _em = _fontPixels();
  return _em;
}

int gtkPx(double em) { return (int)std::floor(em * gtkEm() + 0.5); }

void gtkForgetMetrics() { _em = 0.; }

// --- the binding

namespace {

  struct binding {
    Ui::Field field;
    std::function<void()> after;
    // the widget proper, inside what the holder places
    GtkWidget *outer = nullptr, *inner = nullptr;
    // the number of a slider
    GtkWidget *number = nullptr;
    // a refresh is putting values in: what the widgets say is not the user
    bool quiet = false;
    // what the widget shows, so that a refresh only redoes what changed
    std::string was;
    std::string shown;
    std::vector<std::string> labels;
    std::vector<int> values;
    // a slider dragged
    bool dragging = false;
    // the colour map
    Ui::MapEditor mapEdit;
    // the tree of a Hierarchy
    gtkTree *tree = nullptr;
    ~binding() { delete tree; }
  };

  void _dropBinding(gpointer data) { delete (binding *)data; }

  binding *_of(GtkWidget *w)
  {
    return w ? (binding *)g_object_get_data(G_OBJECT(w), "gmsh-field") :
               nullptr;
  }

  // what a change the user made does: the done() of a choosing that ended,
  // the changed() of a step, then what the holder does; nothing of b is
  // touched afterwards, as the holder may have made the widget again
  void _told(binding *b, bool ends)
  {
    if(b->quiet) return;
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    if(f.done && ends)
      f.done();
    else if(f.changed)
      f.changed();
    if(after) after();
  }

  std::string _joined(const std::vector<std::string> &labels)
  {
    std::string s;
    for(const auto &l : labels) s += l + '\n';
    return s;
  }

  void _clear(GtkWidget *box)
  {
    while(GtkWidget *c = gtk_widget_get_first_child(box))
      gtk_box_remove(GTK_BOX(box), c);
  }

  // with the decimals of its step when values are dragged
  std::string _number(const Ui::Field &f, double v)
  {
    return Ui::numberText(v, gtkSources().settings().inputScrolling ? f.step : 0.);
  }

  // --- a line of text

  void _textWrite(binding *b, bool ends)
  {
    if(b->quiet) return;
    std::string now = gtk_editable_get_text(GTK_EDITABLE(b->inner));
    b->shown = now;
    b->field.setText(now);
    _told(b, ends);
  }

  void _textChanged(GtkEditable *, gpointer data)
  {
    binding *b = (binding *)data;
    if(!b->field.commitsWhenDone) _textWrite(b, false);
  }

  void _textActivate(GtkEntry *, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->field.commitsWhenDone)
      _textWrite(b, true);
    else if(b->field.done && !b->quiet) {
      Ui::Field f = b->field;
      std::function<void()> after = b->after;
      f.done();
      if(after) after();
    }
  }

  void _textLeave(GtkEventControllerFocus *, gpointer data)
  {
    binding *b = (binding *)data;
    if(!b->field.commitsWhenDone) return;
    std::string now = gtk_editable_get_text(GTK_EDITABLE(b->inner));
    if(now != b->shown) _textWrite(b, true);
  }

  // the choices of a line of text, dropped under it
  void _suggestionPicked(GtkButton *button, gpointer data)
  {
    binding *b = (binding *)data;
    const char *said = (const char *)g_object_get_data(G_OBJECT(button),
                                                       "gmsh-said");
    GtkWidget *pop = gtk_widget_get_ancestor(GTK_WIDGET(button),
                                             GTK_TYPE_POPOVER);
    if(pop) gtk_popover_popdown(GTK_POPOVER(pop));
    b->quiet = true;
    gtk_editable_set_text(GTK_EDITABLE(b->inner), said ? said : "");
    b->quiet = false;
    _textWrite(b, true);
  }

  GtkWidget *_listPopover(binding *b, const std::vector<std::string> &labels,
                          GCallback picked)
  {
    GtkWidget *pop = gtk_popover_new();
    GtkWidget *scroll = gtk_scrolled_window_new();
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
                                   GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_propagate_natural_height(
      GTK_SCROLLED_WINDOW(scroll), TRUE);
    gtk_scrolled_window_set_max_content_height(GTK_SCROLLED_WINDOW(scroll),
                                               gtkPx(30.));
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    for(std::size_t i = 0; i < labels.size(); i++) {
      GtkWidget *row = gtk_button_new_with_label(labels[i].c_str());
      gtk_widget_add_css_class(row, "flat");
      gtk_widget_set_halign(gtk_button_get_child(GTK_BUTTON(row)),
                            GTK_ALIGN_START);
      g_object_set_data_full(G_OBJECT(row), "gmsh-said",
                             g_strdup(labels[i].c_str()), g_free);
      g_object_set_data(G_OBJECT(row), "gmsh-index", GINT_TO_POINTER((int)i));
      g_signal_connect(row, "clicked", picked, b);
      gtk_box_append(GTK_BOX(box), row);
    }
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll), box);
    gtk_popover_set_child(GTK_POPOVER(pop), scroll);
    return pop;
  }

  void _suggestions(GtkEntry *entry, GtkEntryIconPosition, gpointer data)
  {
    binding *b = (binding *)data;
    std::vector<std::string> labels;
    std::vector<int> values;
    b->field.dynamicChoices(labels, values);
    if(labels.empty()) return;
    GtkWidget *pop = _listPopover(b, labels, G_CALLBACK(_suggestionPicked));
    gtk_widget_set_parent(pop, GTK_WIDGET(entry));
    g_signal_connect(pop, "closed", G_CALLBACK(+[](GtkPopover *p, gpointer) {
                       g_idle_add(
                         [](gpointer w) -> gboolean {
                           if(gtk_widget_get_parent((GtkWidget *)w))
                             gtk_widget_unparent((GtkWidget *)w);
                           g_object_unref(w);
                           return G_SOURCE_REMOVE;
                         },
                         p);
                     }),
                     nullptr);
    g_object_ref(pop);
    gtk_popover_popup(GTK_POPOVER(pop));
  }

  // --- a number

  void _numberWrite(binding *b, const std::string &said, bool ends)
  {
    double v = 0.;
    if(!Ui::readNumber(said, v)) {
      // not a number: what it was comes back
      gtkRefreshField(b->outer);
      return;
    }
    v = Ui::bounded(b->field, v);
    b->field.setNumber(v);
    b->shown = _number(b->field, v);
    _told(b, ends);
  }

  void _numberActivate(GtkEntry *e, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet) return;
    std::string now = gtk_editable_get_text(GTK_EDITABLE(e));
    // Enter says the value is the one, even as it was
    if(now == b->shown) {
      if(b->field.done) {
        Ui::Field f = b->field;
        std::function<void()> after = b->after;
        f.done();
        if(after) after();
      }
      return;
    }
    _numberWrite(b, now, true);
  }

  void _numberLeave(GtkEventControllerFocus *c, gpointer data)
  {
    binding *b = (binding *)data;
    GtkWidget *e = b->number ? b->number : b->inner;
    std::string now = gtk_editable_get_text(GTK_EDITABLE(e));
    if(now != b->shown) _numberWrite(b, now, true);
  }

  gboolean _numberScroll(GtkEventControllerScroll *, double, double dy,
                         gpointer data)
  {
    binding *b = (binding *)data;
    const Ui::Field &f = b->field;
    if(!(f.step > 0.) || !gtkSources().settings().inputScrolling) return FALSE;
    if(!gtk_widget_is_sensitive(b->outer)) return FALSE;
    double v = Ui::bounded(f, f.getNumber() - (dy > 0. ? 1. : dy < 0. ? -1. : 0.) *
                                             f.step);
    b->field.setNumber(v);
    gtkRefreshField(b->outer);
    _told(b, false);
    return TRUE;
  }

  void _scaleChanged(GtkRange *range, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet) return;
    double v = Ui::bounded(b->field, gtk_range_get_value(range));
    b->field.setNumber(v);
    b->shown = _number(b->field, v);
    b->quiet = true;
    gtk_editable_set_text(GTK_EDITABLE(b->number), b->shown.c_str());
    b->quiet = false;
    _told(b, !b->dragging);
  }

  // the button let go on the scale ends the choosing
  gboolean _scaleEvent(GtkEventControllerLegacy *, GdkEvent *event,
                       gpointer data)
  {
    binding *b = (binding *)data;
    GdkEventType type = gdk_event_get_event_type(event);
    if(type == GDK_BUTTON_PRESS)
      b->dragging = true;
    else if(type == GDK_BUTTON_RELEASE && b->dragging) {
      b->dragging = false;
      if(b->field.done) {
        Ui::Field f = b->field;
        std::function<void()> after = b->after;
        f.done();
        if(after) after();
      }
    }
    return FALSE;
  }

  // --- the others

  void _checkToggled(GtkCheckButton *c, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet) return;
    b->field.setFlag(gtk_check_button_get_active(c));
    _told(b, true);
  }

  void _discloseToggled(GtkToggleButton *t, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet) return;
    b->field.setFlag(gtk_toggle_button_get_active(t));
    _told(b, true);
  }

  void _dropdownPicked(GObject *d, GParamSpec *, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet) return;
    guint i = gtk_drop_down_get_selected(GTK_DROP_DOWN(d));
    if(i == GTK_INVALID_LIST_POSITION || i >= b->labels.size()) return;
    if(b->values.empty())
      b->field.setText(b->labels[i]);
    else if(i < b->values.size())
      b->field.setNumber(b->values[i]);
    _told(b, true);
  }

  void _severalToggled(GtkCheckButton *c, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet) return;
    int i = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(c), "gmsh-index"));
    if(b->field.choose) b->field.choose(i, gtk_check_button_get_active(c));
    _told(b, true);
  }

  void _menuPicked(GtkButton *button, gpointer data)
  {
    binding *b = (binding *)data;
    int i = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(button), "gmsh-index"));
    GtkWidget *pop = gtk_widget_get_ancestor(GTK_WIDGET(button),
                                             GTK_TYPE_POPOVER);
    if(pop) gtk_popover_popdown(GTK_POPOVER(pop));
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    // what it does may open a window
    gtkLater([f, i, after]() {
      if(f.choose) f.choose(i, true);
      if(f.done)
        f.done();
      else if(f.changed)
        f.changed();
      if(after) after();
    });
  }

  // the list is made when the button is opened
  void _menuOpens(GtkMenuButton *mb, gpointer data)
  {
    binding *b = (binding *)data;
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(b->field, labels, values);
    gtk_menu_button_set_popover(mb, _listPopover(b, labels,
                                                 G_CALLBACK(_menuPicked)));
  }

  void _actionClicked(GtkButton *, gpointer data)
  {
    binding *b = (binding *)data;
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    gtkLater([f, after]() {
      if(f.changed) f.changed();
      if(after) after();
    });
  }

  void _colourChosen(GObject *button, GParamSpec *, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet) return;
    const GdkRGBA *c =
      gtk_color_dialog_button_get_rgba(GTK_COLOR_DIALOG_BUTTON(button));
    if(!c) return;
    auto byte = [](float v) {
      return (unsigned char)std::max(0.f, std::min(255.f, v * 255.f + .5f));
    };
    b->field.setColour(Ui::Colour(byte(c->red), byte(c->green), byte(c->blue),
                                  byte(c->alpha)));
    _told(b, true);
  }

  // --- a list one picks from

  void _listPicked(GtkListBox *list, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet || !b->field.choose) return;
    Ui::Field f = b->field;
    for(int i = 0;; i++) {
      GtkListBoxRow *row = gtk_list_box_get_row_at_index(list, i);
      if(!row) break;
      f.choose(i, gtk_list_box_row_is_selected(row));
    }
    _told(b, true);
  }

  // a line one clicks is one to be rid of
  void _listActivated(GtkListBox *, GtkListBoxRow *row, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->quiet || b->field.choose || !b->field.removeItem) return;
    int i = gtk_list_box_row_get_index(row);
    Ui::Field f = b->field;
    std::function<void()> after = b->after;
    gtkLater([f, i, after]() {
      f.removeItem(i);
      if(f.changed) f.changed();
      if(after) after();
    });
  }

  GtkWidget *_listLine(const Ui::Field &f, const std::string &label)
  {
    if(f.columnsEm.empty() || label.find('\t') == std::string::npos) {
      GtkWidget *l = gtk_label_new(label.c_str());
      gtk_label_set_xalign(GTK_LABEL(l), 0.f);
      return l;
    }
    GtkWidget *line = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    std::size_t at = 0, column = 0;
    while(true) {
      std::size_t tab = label.find('\t', at);
      std::string part = label.substr(at, tab == std::string::npos ?
                                            std::string::npos : tab - at);
      GtkWidget *l = gtk_label_new(part.c_str());
      gtk_label_set_xalign(GTK_LABEL(l), 0.f);
      if(column < f.columnsEm.size() && f.columnsEm[column] > 0.) {
        gtk_widget_set_size_request(l, gtkPx(f.columnsEm[column]), -1);
        gtk_label_set_ellipsize(GTK_LABEL(l), PANGO_ELLIPSIZE_END);
        gtk_label_set_width_chars(GTK_LABEL(l), 1);
      }
      else
        gtk_widget_set_hexpand(l, TRUE);
      gtk_box_append(GTK_BOX(line), l);
      if(tab == std::string::npos) break;
      at = tab + 1;
      column++;
    }
    return line;
  }

  // --- a page of prose

  std::string _markup(const std::string &text)
  {
    gchar *m = g_markup_escape_text(text.c_str(), -1);
    std::string s = m;
    g_free(m);
    return s;
  }

  gboolean _proseLink(GtkLabel *label, const gchar *uri, gpointer)
  {
    std::vector<std::function<void()> > *follow =
      (std::vector<std::function<void()> > *)g_object_get_data(
        G_OBJECT(label), "gmsh-follow");
    int i = atoi(uri);
    if(follow && i >= 0 && i < (int)follow->size()) {
      std::function<void()> what = (*follow)[(std::size_t)i];
      gtkLater(what);
    }
    return TRUE;
  }

  void _dropFollow(gpointer data)
  {
    delete (std::vector<std::function<void()> > *)data;
  }

  void _prose(binding *b)
  {
    std::vector<Ui::Line> page =
      b->field.prose ? b->field.prose() : std::vector<Ui::Line>();
    std::string said;
    for(const Ui::Line &l : page) {
      for(const Ui::Words &w : l.words) said += w.text + (w.italic ? "/" : "|");
      said += '\n';
    }
    if(said == b->was) return;
    b->was = said;
    _clear(b->inner);
    for(const Ui::Line &l : page) {
      std::string m;
      auto *follow = new std::vector<std::function<void()> >;
      for(const Ui::Words &w : l.words) {
        std::string t = _markup(w.text);
        if(w.italic) t = "<i>" + t + "</i>";
        if(w.follow) {
          t = "<a href=\"" + std::to_string(follow->size()) + "\">" + t + "</a>";
          follow->push_back(w.follow);
        }
        m += t;
      }
      if(l.heading) m = "<span size=\"x-large\" weight=\"bold\">" + m + "</span>";
      if(l.bullet) m = "•  " + m;
      GtkWidget *label = gtk_label_new(nullptr);
      gtk_label_set_markup(GTK_LABEL(label), m.empty() ? " " : m.c_str());
      gtk_label_set_wrap(GTK_LABEL(label), TRUE);
      gtk_label_set_wrap_mode(GTK_LABEL(label), PANGO_WRAP_WORD_CHAR);
      gtk_label_set_width_chars(GTK_LABEL(label), 20);
      gtk_label_set_max_width_chars(GTK_LABEL(label), 60);
      gtk_label_set_xalign(GTK_LABEL(label), l.centred ? .5f : 0.f);
      if(l.centred) gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
      if(l.bullet) gtk_widget_set_margin_start(label, gtkPx(.7));
      g_object_set_data_full(G_OBJECT(label), "gmsh-follow", follow,
                             _dropFollow);
      g_signal_connect(label, "activate-link", G_CALLBACK(_proseLink), nullptr);
      gtk_box_append(GTK_BOX(b->inner), label);
    }
  }

  // --- the disc of a direction

  void _discDraw(GtkDrawingArea *, cairo_t *cr, int w, int h, gpointer data)
  {
    binding *b = (binding *)data;
    double x = 0., y = 0., z = 0.;
    b->field.getVector(x, y, z);
    double length = std::sqrt(x * x + y * y + z * z);
    if(length > 0.) {
      x /= length;
      y /= length;
    }
    GdkRGBA ink;
    gtk_widget_get_color(b->inner, &ink);
    double side = std::min(w, h), radius = .5 * side - 3.;
    double cx = .5 * w, cy = .5 * h;
    gdk_cairo_set_source_rgba(cr, &ink);
    cairo_set_line_width(cr, 1.);
    cairo_arc(cr, cx, cy, radius, 0., 2. * M_PI);
    cairo_stroke(cr);
    cairo_rectangle(cr, cx + radius * x - 3., cy - radius * y - 3., 6., 6.);
    cairo_fill(cr);
  }

  void _discAt(binding *b, double px, double py)
  {
    if(!gtk_widget_is_sensitive(b->inner)) return;
    int w = gtk_widget_get_width(b->inner), h = gtk_widget_get_height(b->inner);
    double radius = .5 * std::min(w, h) - 3.;
    if(radius <= 0.) return;
    double xx = (px - .5 * w) / radius, yy = -(py - .5 * h) / radius;
    double norm = std::sqrt(xx * xx + yy * yy);
    if(norm > 1.) {
      xx /= norm;
      yy /= norm;
      norm = 1.;
    }
    b->field.setVector(xx, yy, std::sqrt(std::max(0., 1. - norm * norm)));
    gtk_widget_queue_draw(b->inner);
    _told(b, false);
  }

  void _discBegin(GtkGestureDrag *, double x, double y, gpointer data)
  {
    _discAt((binding *)data, x, y);
  }

  void _discUpdate(GtkGestureDrag *g, double dx, double dy, gpointer data)
  {
    double x = 0., y = 0.;
    gtk_gesture_drag_get_start_point(g, &x, &y);
    _discAt((binding *)data, x + dx, y + dy);
  }

  void _discEnd(GtkGestureDrag *, double, double, gpointer data)
  {
    binding *b = (binding *)data;
    if(b->field.done) {
      Ui::Field f = b->field;
      std::function<void()> after = b->after;
      f.done();
      if(after) after();
    }
  }

  // --- the colour map, drawn into the table itself

  double _lineHeight(GtkWidget *w)
  {
    PangoLayout *l = gtk_widget_create_pango_layout(w, "Mg");
    int lw = 0, lh = 0;
    pango_layout_get_pixel_size(l, &lw, &lh);
    g_object_unref(l);
    return lh;
  }

  void _text(cairo_t *cr, GtkWidget *w, double x, double y,
             const std::string &s, bool right = false, double scale = 1.)
  {
    PangoLayout *l = gtk_widget_create_pango_layout(w, s.c_str());
    if(scale != 1.) {
      PangoFontDescription *d = pango_font_description_copy(
        pango_context_get_font_description(pango_layout_get_context(l)));
      pango_font_description_set_size(
        d, (int)(pango_font_description_get_size(d) * scale));
      pango_layout_set_font_description(l, d);
      pango_font_description_free(d);
    }
    int lw = 0, lh = 0;
    pango_layout_get_pixel_size(l, &lw, &lh);
    cairo_move_to(cr, right ? x - lw : x, y);
    pango_cairo_show_layout(cr, l);
    g_object_unref(l);
  }

  void _mapDraw(GtkDrawingArea *, cairo_t *cr, int w, int h, gpointer data)
  {
    binding *b = (binding *)data;
    const Ui::ColourMap &map = b->field.map;
    if(map.empty()) return;
    std::string name;
    double least = 0., most = 0.;
    map.about(name, least, most);
    int size = map.size();
    GdkRGBA ink;
    gtk_widget_get_color(b->inner, &ink);
    double line = _lineHeight(b->inner);
    double labelY = h - 5., markerY = labelY - 2. * line,
           wedgeY = markerY - line;
    if(size < 2 || wedgeY < 4.) return;
    cairo_set_source_rgba(cr, ink.red, ink.green, ink.blue, .06);
    cairo_paint(cr);
    bool hsv = map.hsv ? map.hsv() : false;
    const double inks[4][3] = {{1., 0., 0.}, {0., .8, 0.}, {0., 0., 1.}, {0., 0., 0.}};
    auto xOf = [&](int i) { return w * (double)i / (double)(size - 1); };
    auto yOf = [&](int v) { return wedgeY * (1. - v / 255.); };
    cairo_set_line_width(cr, 1.);
    for(int channel = 0; channel < 4; channel++) {
      if(channel == 3)
        gdk_cairo_set_source_rgba(cr, &ink);
      else
        cairo_set_source_rgb(cr, inks[channel][0], inks[channel][1],
                             inks[channel][2]);
      cairo_move_to(cr, xOf(0), yOf(Ui::mapChannel(map, 0, channel, hsv)));
      for(int i = 1; i < size; i++)
        cairo_line_to(cr, xOf(i), yOf(Ui::mapChannel(map, i, channel, hsv)));
      cairo_stroke(cr);
    }
    for(int x = 0; x < w; x++) {
      int i = std::min(size - 1, (int)(x * (double)size / w));
      Ui::Colour c = map.colour(i);
      cairo_set_source_rgb(cr, c.r / 255., c.g / 255., c.b / 255.);
      cairo_rectangle(cr, x, wedgeY, 1., line);
      cairo_fill(cr);
    }
    gdk_cairo_set_source_rgba(cr, &ink);
    if(b->mapEdit.help()) {
      const auto &keys = Ui::MapEditor::helpLines();
      const int lines = (int)keys.size();
      double scale = std::min(.85, (wedgeY - 12.) / (lines + 1) / line);
      double step = line * scale + 1.;
      for(int i = 0; i < lines; i++) {
        _text(cr, b->inner, 6., 6. + i * step, keys[i].first.c_str(), false,
              scale);
        _text(cr, b->inner, 12. * step, 6. + i * step, keys[i].second.c_str(),
              false, scale);
      }
    }
    else {
      _text(cr, b->inner, 6., 4., Ui::MapEditor::title(map).c_str());
    }
    char says[64];
    // the marker below the wedge, and the value of the map there
    double mx = xOf(b->mapEdit.marker());
    cairo_set_line_width(cr, 1.);
    cairo_move_to(cr, mx + .5, markerY);
    cairo_line_to(cr, mx + .5, markerY + line * .6);
    cairo_move_to(cr, mx - 2.5, markerY + 6.);
    cairo_line_to(cr, mx + .5, markerY);
    cairo_line_to(cr, mx + 3.5, markerY + 6.);
    cairo_stroke(cr);
    _text(cr, b->inner, 10., labelY - line,
          Ui::MapEditor::markerText(map, b->mapEdit.marker()).c_str());
    snprintf(says, sizeof(says), "%g", most);
    _text(cr, b->inner, w - 10., labelY - line, says, true);
  }

  // button: 0, 1, 2 for a button that went down, -1 for a drag
  void _mapPaint(binding *b, double px, double py, int button, unsigned mods)
  {
    const Ui::ColourMap &map = b->field.map;
    if(map.empty()) return;
    int w = gtk_widget_get_width(b->inner), h = gtk_widget_get_height(b->inner);
    double line = _lineHeight(b->inner);
    double wedgeY = h - 5. - 3. * line;
    if(map.size() < 2 || w < 1 || wedgeY < 1.) return;
    int entry = Ui::MapEditor::entryAt(map, px, w);
    int value = Ui::MapEditor::valueAt(py, wedgeY);
    Ui::MapEditor::Answer said;
    if(button >= 0)
      said = b->mapEdit.press(map, entry, value, button, mods, py >= wedgeY);
    else if(b->mapEdit.drawing())
      said = b->mapEdit.drag(map, entry, value);
    else
      return;
    gtk_widget_queue_draw(b->inner);
    if(said == Ui::MapEditor::Changed) _told(b, false);
  }

  void _mapBegin(GtkGestureDrag *g, double x, double y, gpointer data)
  {
    binding *b = (binding *)data;
    gtk_widget_grab_focus(b->inner);
    guint button = gtk_gesture_single_get_current_button(GTK_GESTURE_SINGLE(g));
    GdkModifierType state = gtk_event_controller_get_current_event_state(
      GTK_EVENT_CONTROLLER(g));
    unsigned mods = 0;
    if(state & GDK_CONTROL_MASK) mods |= Ui::ModCommand;
    if(state & GDK_SHIFT_MASK) mods |= Ui::ModShift;
    if(state & GDK_ALT_MASK) mods |= Ui::ModAlt;
    _mapPaint(b, x, y, button == 3 ? 2 : button == 2 ? 1 : 0, mods);
  }

  void _mapUpdate(GtkGestureDrag *g, double dx, double dy, gpointer data)
  {
    double x = 0., y = 0.;
    gtk_gesture_drag_get_start_point(g, &x, &y);
    _mapPaint((binding *)data, x + dx, y + dy, -1, 0);
  }

  void _mapEnd(GtkGestureDrag *, double, double, gpointer data)
  {
    ((binding *)data)->mapEdit.release();
  }

  void _mapEnter(GtkEventControllerMotion *, double, double, gpointer data)
  {
    gtk_widget_grab_focus(((binding *)data)->inner);
  }

  gboolean _mapKey(GtkEventControllerKey *, guint keyval, guint,
                   GdkModifierType state, gpointer data)
  {
    binding *b = (binding *)data;
    const Ui::ColourMap &map = b->field.map;
    if(map.empty()) return FALSE;
    int key = 0;
    unsigned mods = 0;
    if(!gtkUiKey(keyval, state, key, mods)) return FALSE;
    Ui::MapEditor::Answer said = b->mapEdit.key(map, key, mods);
    if(said == Ui::MapEditor::NotMine) return FALSE;
    gtk_widget_queue_draw(b->inner);
    if(said == Ui::MapEditor::Changed) _told(b, true);
    return TRUE;
  }

  void _setRgba(GdkRGBA &c, const Ui::Colour &u)
  {
    c.red = u.r / 255.f;
    c.green = u.g / 255.f;
    c.blue = u.b / 255.f;
    c.alpha = u.a / 255.f;
  }

  void _addFocusLeave(GtkWidget *w, GCallback leave, binding *b)
  {
    GtkEventController *focus = gtk_event_controller_focus_new();
    g_signal_connect(focus, "leave", leave, b);
    gtk_widget_add_controller(w, focus);
  }

  GtkWidget *_numberEntry(binding *b)
  {
    GtkWidget *e = gtk_entry_new();
    gtk_editable_set_width_chars(GTK_EDITABLE(e), 1);
    gtk_editable_set_max_width_chars(GTK_EDITABLE(e), 1);
    g_signal_connect(e, "activate", G_CALLBACK(_numberActivate), b);
    _addFocusLeave(e, G_CALLBACK(_numberLeave), b);
    GtkEventController *wheel =
      gtk_event_controller_scroll_new((GtkEventControllerScrollFlags)(
        GTK_EVENT_CONTROLLER_SCROLL_VERTICAL |
        GTK_EVENT_CONTROLLER_SCROLL_DISCRETE));
    g_signal_connect(wheel, "scroll", G_CALLBACK(_numberScroll), b);
    gtk_widget_add_controller(e, wheel);
    return e;
  }

} // namespace

GtkWidget *gtkFieldWidget(const Ui::Field &f, const std::function<void()> &after)
{
  binding *b = new binding;
  b->field = f;
  b->after = after;
  GtkWidget *outer = nullptr;
  switch(f.kind) {
  case Ui::Text: {
    GtkWidget *e = gtk_entry_new();
    gtk_editable_set_width_chars(GTK_EDITABLE(e), 1);
    gtk_editable_set_max_width_chars(GTK_EDITABLE(e), 1);
    if(f.dynamicChoices) {
      gtk_entry_set_icon_from_icon_name(GTK_ENTRY(e), GTK_ENTRY_ICON_SECONDARY,
                                        "pan-down-symbolic");
      g_signal_connect(e, "icon-press", G_CALLBACK(_suggestions), b);
    }
    g_signal_connect(e, "changed", G_CALLBACK(_textChanged), b);
    g_signal_connect(e, "activate", G_CALLBACK(_textActivate), b);
    _addFocusLeave(e, G_CALLBACK(_textLeave), b);
    outer = b->inner = e;
  } break;
  case Ui::Integer:
  case Ui::Number:
    if(f.slider && f.maximum > f.minimum) {
      // the number at the left end and the scale beside it, as the page has it
      GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
      b->number = _numberEntry(b);
      gtk_widget_set_size_request(b->number, gtkPx(3.6), -1);
      double step = f.step > 0. ? f.step : (f.maximum - f.minimum) / 100.;
      GtkWidget *scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,
                                                  f.minimum, f.maximum, step);
      gtk_scale_set_draw_value(GTK_SCALE(scale), FALSE);
      gtk_widget_set_hexpand(scale, TRUE);
      g_signal_connect(scale, "value-changed", G_CALLBACK(_scaleChanged), b);
      GtkEventController *legacy = gtk_event_controller_legacy_new();
      gtk_event_controller_set_propagation_phase(legacy, GTK_PHASE_CAPTURE);
      g_signal_connect(legacy, "event", G_CALLBACK(_scaleEvent), b);
      gtk_widget_add_controller(scale, legacy);
      gtk_box_append(GTK_BOX(box), b->number);
      gtk_box_append(GTK_BOX(box), scale);
      b->inner = scale;
      outer = box;
    }
    else
      outer = b->inner = _numberEntry(b);
    break;
  case Ui::Check:
    if(f.disclosure) {
      GtkWidget *t = gtk_toggle_button_new_with_label(f.label.c_str());
      g_signal_connect(t, "toggled", G_CALLBACK(_discloseToggled), b);
      outer = b->inner = t;
    }
    else {
      GtkWidget *c = gtk_check_button_new_with_label(
        f.label.size() ? f.label.c_str() : nullptr);
      g_signal_connect(c, "toggled", G_CALLBACK(_checkToggled), b);
      outer = b->inner = c;
    }
    break;
  case Ui::Choice:
    if(f.multiple) {
      GtkWidget *mb = gtk_menu_button_new();
      gtk_menu_button_set_label(GTK_MENU_BUTTON(mb), f.label.c_str());
      GtkWidget *pop = gtk_popover_new();
      GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
      gtk_popover_set_child(GTK_POPOVER(pop), box);
      gtk_menu_button_set_popover(GTK_MENU_BUTTON(mb), pop);
      b->inner = box;
      outer = mb;
    }
    else {
      GtkStringList *model = gtk_string_list_new(nullptr);
      GtkWidget *d = gtk_drop_down_new(G_LIST_MODEL(model), nullptr);
      g_signal_connect(d, "notify::selected", G_CALLBACK(_dropdownPicked), b);
      outer = b->inner = d;
    }
    break;
  case Ui::Label: {
    GtkWidget *l = gtk_label_new("");
    gtk_label_set_xalign(GTK_LABEL(l), f.align == Ui::Centre ? .5f :
                                       f.align == Ui::Right  ? 1.f :
                                                               0.f);
    if(f.wraps) {
      gtk_label_set_wrap(GTK_LABEL(l), TRUE);
      gtk_label_set_max_width_chars(GTK_LABEL(l), 52);
      gtk_label_set_yalign(GTK_LABEL(l), 0.f);
    }
    if(f.heading) gtk_widget_add_css_class(l, "heading");
    if(f.alert) gtk_widget_add_css_class(l, "error");
    outer = b->inner = l;
  } break;
  case Ui::Output: {
    GtkWidget *e = gtk_entry_new();
    gtk_editable_set_width_chars(GTK_EDITABLE(e), 1);
    gtk_editable_set_max_width_chars(GTK_EDITABLE(e), 1);
    gtk_editable_set_editable(GTK_EDITABLE(e), FALSE);
    outer = b->inner = e;
  } break;
  case Ui::Prose: {
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    outer = b->inner = box;
  } break;
  case Ui::Action: {
    GtkWidget *button = gtk_button_new_with_label(f.label.c_str());
    if(f.isDefault) gtk_widget_add_css_class(button, "suggested-action");
    if(f.alert) gtk_widget_add_css_class(button, "destructive-action");
    g_signal_connect(button, "clicked", G_CALLBACK(_actionClicked), b);
    outer = b->inner = button;
  } break;
  case Ui::Color: {
    GtkColorDialog *dialog = gtk_color_dialog_new();
    gtk_color_dialog_set_with_alpha(dialog, TRUE);
    GtkWidget *button = gtk_color_dialog_button_new(dialog);
    g_signal_connect(button, "notify::rgba", G_CALLBACK(_colourChosen), b);
    outer = b->inner = button;
  } break;
  case Ui::Direction: {
    GtkWidget *area = gtk_drawing_area_new();
    int side = std::max(gtkPx(2.9), gtkPx(1.45 * std::max(2, f.rows)));
    gtk_drawing_area_set_content_width(GTK_DRAWING_AREA(area), side);
    gtk_drawing_area_set_content_height(GTK_DRAWING_AREA(area), side);
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(area), _discDraw, b,
                                   nullptr);
    GtkGesture *drag = gtk_gesture_drag_new();
    g_signal_connect(drag, "drag-begin", G_CALLBACK(_discBegin), b);
    g_signal_connect(drag, "drag-update", G_CALLBACK(_discUpdate), b);
    g_signal_connect(drag, "drag-end", G_CALLBACK(_discEnd), b);
    gtk_widget_add_controller(area, GTK_EVENT_CONTROLLER(drag));
    outer = b->inner = area;
  } break;
  case Ui::ColorMap: {
    GtkWidget *area = gtk_drawing_area_new();
    gtk_widget_set_focusable(area, TRUE);
    gtk_widget_set_size_request(area, gtkPx(10.), gtkPx(8.));
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(area), _mapDraw, b,
                                   nullptr);
    GtkGesture *drag = gtk_gesture_drag_new();
    gtk_gesture_single_set_button(GTK_GESTURE_SINGLE(drag), 0);
    g_signal_connect(drag, "drag-begin", G_CALLBACK(_mapBegin), b);
    g_signal_connect(drag, "drag-update", G_CALLBACK(_mapUpdate), b);
    g_signal_connect(drag, "drag-end", G_CALLBACK(_mapEnd), b);
    gtk_widget_add_controller(area, GTK_EVENT_CONTROLLER(drag));
    GtkEventController *keys = gtk_event_controller_key_new();
    g_signal_connect(keys, "key-pressed", G_CALLBACK(_mapKey), b);
    gtk_widget_add_controller(area, keys);
    GtkEventController *motion = gtk_event_controller_motion_new();
    g_signal_connect(motion, "enter", G_CALLBACK(_mapEnter), b);
    gtk_widget_add_controller(area, motion);
    outer = b->inner = area;
  } break;
  case Ui::Hierarchy: {
    Ui::Tree none;
    b->tree = new gtkTree(f.hierarchy ? *f.hierarchy : none, true, after);
    outer = b->inner = b->tree->widget();
    gtk_widget_add_css_class(outer, "frame");
    if(f.rows)
      gtk_widget_set_size_request(outer, -1, gtkPx(1.45 * f.rows));
  } break;
  case Ui::Menu: {
    GtkWidget *mb = gtk_menu_button_new();
    gtk_menu_button_set_label(GTK_MENU_BUTTON(mb), f.label.c_str());
    gtk_menu_button_set_create_popup_func(GTK_MENU_BUTTON(mb), _menuOpens, b,
                                          nullptr);
    outer = b->inner = mb;
  } break;
  case Ui::List: {
    GtkWidget *scroll = gtk_scrolled_window_new();
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_widget_add_css_class(scroll, "frame");
    GtkWidget *list = gtk_list_box_new();
    gtk_list_box_set_selection_mode(
      GTK_LIST_BOX(list), !f.choose     ? GTK_SELECTION_NONE :
                          f.multiple    ? GTK_SELECTION_MULTIPLE :
                                          GTK_SELECTION_SINGLE);
    gtk_list_box_set_activate_on_single_click(GTK_LIST_BOX(list), TRUE);
    if(f.isCode) gtk_widget_add_css_class(list, "monospace");
    g_signal_connect(list, "selected-rows-changed", G_CALLBACK(_listPicked), b);
    g_signal_connect(list, "row-activated", G_CALLBACK(_listActivated), b);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll), list);
    if(f.rows)
      gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(scroll),
                                                 gtkPx(1.45 * f.rows));
    else
      gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(scroll),
                                                 gtkPx(5.));
    b->inner = list;
    outer = scroll;
  } break;
  case Ui::Spacer: break;
  }
  if(!outer) {
    delete b;
    return nullptr;
  }
  b->outer = outer;
  if(f.tooltip.size() && gtkSources().settings().tooltips)
    gtk_widget_set_tooltip_text(outer, f.tooltip.c_str());
  g_object_set_data_full(G_OBJECT(outer), "gmsh-field", b, _dropBinding);
  gtkRefreshField(outer);
  return outer;
}

const Ui::Field *gtkFieldOf(GtkWidget *widget)
{
  binding *b = _of(widget);
  return b ? &b->field : nullptr;
}

void gtkRebindField(GtkWidget *widget, const Ui::Field &field)
{
  binding *b = _of(widget);
  if(!b || b->field.kind != field.kind) return;
  b->field = field;
  if(b->tree && field.hierarchy) b->tree->setTree(*field.hierarchy);
}

void gtkRefreshField(GtkWidget *widget)
{
  binding *b = _of(widget);
  if(!b) return;
  const Ui::Field &f = b->field;
  b->quiet = true;
  switch(f.kind) {
  case Ui::Text:
  case Ui::Output: {
    std::string value = f.getText();
    // not while the user is typing in it
    bool typing = f.kind == Ui::Text && gtk_widget_has_focus(b->inner) &&
                  gtk_editable_get_text(GTK_EDITABLE(b->inner)) != b->shown;
    if(!typing && value != gtk_editable_get_text(GTK_EDITABLE(b->inner)))
      gtk_editable_set_text(GTK_EDITABLE(b->inner), value.c_str());
    if(!typing) b->shown = value;
  } break;
  case Ui::Integer:
  case Ui::Number: {
    std::string value = _number(f, f.getNumber());
    GtkWidget *e = b->number ? b->number : b->inner;
    bool typing = gtk_widget_has_focus(e) &&
                  gtk_editable_get_text(GTK_EDITABLE(e)) != b->shown;
    if(!typing && value != gtk_editable_get_text(GTK_EDITABLE(e)))
      gtk_editable_set_text(GTK_EDITABLE(e), value.c_str());
    if(!typing) b->shown = value;
    if(b->number && !b->dragging)
      gtk_range_set_value(GTK_RANGE(b->inner), f.getNumber());
  } break;
  case Ui::Check:
    if(f.disclosure) {
      bool on = f.getFlag();
      gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(b->inner), on);
      std::string label = f.label + (on ? " ▴" : " ▾");
      gtk_button_set_label(GTK_BUTTON(b->inner), label.c_str());
    }
    else
      gtk_check_button_set_active(GTK_CHECK_BUTTON(b->inner), f.getFlag());
    break;
  case Ui::Choice: {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    if(f.multiple) {
      if(_joined(labels) != b->was) {
        b->was = _joined(labels);
        _clear(b->inner);
        for(std::size_t k = 0; k < labels.size(); k++) {
          GtkWidget *c = gtk_check_button_new_with_label(labels[k].c_str());
          g_object_set_data(G_OBJECT(c), "gmsh-index", GINT_TO_POINTER((int)k));
          g_signal_connect(c, "toggled", G_CALLBACK(_severalToggled), b);
          gtk_box_append(GTK_BOX(b->inner), c);
        }
      }
      int k = 0;
      for(GtkWidget *c = gtk_widget_get_first_child(b->inner); c;
          c = gtk_widget_get_next_sibling(c), k++)
        gtk_check_button_set_active(GTK_CHECK_BUTTON(c),
                                    f.chosen && f.chosen(k));
      break;
    }
    GtkDropDown *d = GTK_DROP_DOWN(b->inner);
    if(_joined(labels) != b->was) {
      b->was = _joined(labels);
      GtkStringList *model = GTK_STRING_LIST(gtk_drop_down_get_model(d));
      std::vector<const char *> said;
      for(const auto &l : labels) said.push_back(l.c_str());
      said.push_back(nullptr);
      gtk_string_list_splice(
        model, 0, g_list_model_get_n_items(G_LIST_MODEL(model)), said.data());
    }
    b->labels = labels;
    b->values = values;
    guint which = GTK_INVALID_LIST_POSITION;
    std::string current = values.empty() ? f.getText() : "";
    for(std::size_t k = 0; k < labels.size(); k++) {
      if(values.empty()) {
        if(labels[k] == current) which = (guint)k;
      }
      else if(k < values.size() && values[k] == (int)f.getNumber())
        which = (guint)k;
    }
    if(which == GTK_INVALID_LIST_POSITION && labels.size() && !values.empty())
      which = 0;
    if(gtk_drop_down_get_selected(d) != which) gtk_drop_down_set_selected(d, which);
  } break;
  case Ui::Label: {
    std::string value = f.getText();
    if(value.empty()) value = f.label;
    if(value != gtk_label_get_text(GTK_LABEL(b->inner)))
      gtk_label_set_text(GTK_LABEL(b->inner), value.c_str());
  } break;
  case Ui::Prose: _prose(b); break;
  case Ui::Action: break;
  case Ui::Color: {
    GdkRGBA c;
    _setRgba(c, f.getColour());
    const GdkRGBA *was =
      gtk_color_dialog_button_get_rgba(GTK_COLOR_DIALOG_BUTTON(b->inner));
    if(!was || !gdk_rgba_equal(was, &c))
      gtk_color_dialog_button_set_rgba(GTK_COLOR_DIALOG_BUTTON(b->inner), &c);
  } break;
  case Ui::Direction:
  case Ui::ColorMap: gtk_widget_queue_draw(b->inner); break;
  case Ui::Hierarchy:
    if(b->tree) b->tree->refresh(false);
    break;
  case Ui::Menu:
    if(f.label != gtk_menu_button_get_label(GTK_MENU_BUTTON(b->inner)))
      gtk_menu_button_set_label(GTK_MENU_BUTTON(b->inner), f.label.c_str());
    break;
  case Ui::List: {
    std::vector<std::string> labels;
    std::vector<int> values;
    Ui::choices(f, labels, values);
    GtkListBox *list = GTK_LIST_BOX(b->inner);
    if(_joined(labels) != b->was) {
      b->was = _joined(labels);
      gtk_list_box_remove_all(list);
      for(const auto &l : labels) gtk_list_box_append(list, _listLine(f, l));
    }
    if(f.chosen)
      for(int k = 0; k < (int)labels.size(); k++) {
        GtkListBoxRow *row = gtk_list_box_get_row_at_index(list, k);
        if(!row) break;
        bool on = f.chosen(k);
        if(on != (bool)gtk_list_box_row_is_selected(row)) {
          if(on)
            gtk_list_box_select_row(list, row);
          else
            gtk_list_box_unselect_row(list, row);
        }
      }
  } break;
  case Ui::Spacer: break;
  }
  if(f.enabled) gtk_widget_set_sensitive(b->outer, f.enabled());
  b->quiet = false;
}

// --- a button after a field, or in a row of them

namespace {

  struct buttonBinding {
    Ui::Button button;
    std::function<void()> after;
  };

  void _dropButton(gpointer data) { delete (buttonBinding *)data; }

  void _buttonClicked(GtkButton *w, gpointer data)
  {
    buttonBinding *b = (buttonBinding *)data;
    if(b->button.menu) {
      gtkPopupMenu(b->button.menu(), GTK_WIDGET(w), -1., -1.);
      return;
    }
    std::function<void()> what = b->button.action, after = b->after;
    gtkLater([what, after]() {
      if(what) what();
      if(after) after();
    });
  }

} // namespace

GtkWidget *gtkButtonWidget(const Ui::Button &button,
                           const std::function<void()> &after)
{
  std::string label = button.label;
  if(label.empty() && button.menu) label = "▾";
  if(label.empty()) label = button.glyph;
  GtkWidget *w = gtk_button_new_with_label(label.c_str());
  buttonBinding *b = new buttonBinding{button, after};
  g_object_set_data_full(G_OBJECT(w), "gmsh-button", b, _dropButton);
  g_signal_connect(w, "clicked", G_CALLBACK(_buttonClicked), b);
  if(button.tooltip.size() && gtkSources().settings().tooltips)
    gtk_widget_set_tooltip_text(w, button.tooltip.c_str());
  if(button.on && button.on()) gtk_widget_add_css_class(w, "suggested-action");
  if(button.enabled) gtk_widget_set_sensitive(w, button.enabled());
  return w;
}
