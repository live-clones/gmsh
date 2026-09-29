// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstring>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#include "gtkCommon.h"
#include "Console.h"

// The GTK 4 interface: one main window -- the menu bar, the tree down the
// left, the scene and the console under it, the bar along the bottom -- and a
// window for each described form (dialogGtk.cpp). No GtkApplication: the loop
// is GLib's, turned by hand, so that check() and wait() can turn it from
// inside the mesher, and a question can run a loop of its own.

namespace {

  // --- the main window and its parts

  struct mainWindow {
    GtkWidget *win = nullptr;
    GtkWidget *menuBar = nullptr, *side = nullptr, *split = nullptr;
    GtkWidget *treeBox = nullptr, *footer = nullptr;
    // the tree taken out of the main window into one of its own
    GtkWidget *treeWin = nullptr;
    GtkWidget *console = nullptr, *consoleScroll = nullptr;
    // the bar over the lines, and the lines as a whole
    GtkWidget *consoleBox = nullptr, *filter = nullptr;
    GtkWidget *bar = nullptr, *buttons = nullptr, *message = nullptr,
              *messageLabel = nullptr, *progress = nullptr;
    treeGtk *tree = nullptr;
    GtkCssProvider *sheet = nullptr;
    std::string barBuilt, footerBuilt;
    // the lines, what the filter lets through, whether the last is kept in
    // view
    Ui::Console said;
    bool fullscreen = false;
    // what the full screen hid, to put back
    bool treeWas = true, consoleWas = true;
  };

  mainWindow *_w = nullptr;
  bool _running = false;
  std::atomic<int> _locked(0);
  double _lastCheck = 0.;

  double _now() { return g_get_monotonic_time() / 1e6; }

  GdkModifierType _modifiers()
  {
    GdkDisplay *display = gdk_display_get_default();
    GdkSeat *seat = display ? gdk_display_get_default_seat(display) : nullptr;
    GdkDevice *keyboard = seat ? gdk_seat_get_keyboard(seat) : nullptr;
    return keyboard ? gdk_device_get_modifier_state(keyboard) :
                      (GdkModifierType)0;
  }

  // --- the sheet: the colours of the messages, of the buttons that are on,
  // the sizes the options set

  std::string _css;

  void _sheet(bool dark, int fontSize, int consoleSize)
  {
    if(!_w) return;
    if(!_w->sheet) {
      _w->sheet = gtk_css_provider_new();
      gtk_style_context_add_provider_for_display(
        gdk_display_get_default(), GTK_STYLE_PROVIDER(_w->sheet),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    }
    std::string css;
    char line[256];
    if(fontSize > 0) {
      snprintf(line, sizeof(line), "* { font-size: %dpt; }\n", fontSize);
      css += line;
    }
    snprintf(line, sizeof(line),
             ".gmsh-console { font-family: monospace; font-size: %dpt; }\n",
             consoleSize > 0 ? consoleSize : 9);
    css += line;
    css += ".gmsh-bar button { padding: 2px 6px; min-height: 0; "
           "min-width: 0; }\n";
    css += ".gmsh-bar { padding: 2px; }\n";
    // the title bars of the dialogs as small as their title and buttons
    css += "headerbar.gmsh-dialog-head { min-height: 0; padding: 0 2px; }\n"
           "headerbar.gmsh-dialog-head .title { font-size: 0.9em; }\n"
           "headerbar.gmsh-dialog-head button { min-height: 0; min-width: 0; "
           "padding: 1px 4px; margin: 1px 0; }\n"
           "headerbar.gmsh-dialog-head windowcontrols button { padding: 1px; }\n"
           "headerbar.gmsh-dialog-head windowcontrols button image { "
           "padding: 1px; }\n";
    css += _css;
    gtk_css_provider_load_from_string(_w->sheet, css.c_str());
  }

  // a class a colour, for the buttons painted in the colour of what they
  // leave on the picture
  std::string _colourClass(const Ui::Colour &c)
  {
    char name[32];
    snprintf(name, sizeof(name), "gmsh-on-%02x%02x%02x", c.r, c.g, c.b);
    if(_css.find(name) == std::string::npos) {
      char rule[160];
      snprintf(rule, sizeof(rule),
               "button.%s { background: rgb(%d,%d,%d); color: %s; }\n", name,
               c.r, c.g, c.b,
               (c.r * 299 + c.g * 587 + c.b * 114) / 1000 > 140 ? "black" :
                                                                  "white");
      _css += rule;
      const Ui::Backend::Settings s = gtkSources().settings();
      _sheet(s.darkScheme, s.fontSize, s.consoleFontSize);
    }
    return name;
  }

  // --- the console

  void _consoleTags(GtkTextBuffer *buffer, bool dark)
  {
    GtkTextTagTable *table = gtk_text_buffer_get_tag_table(buffer);
    const char *names[] = {"direct", "warning", "error", "debug"};
    const char *light[] = {"#1a4fa0", "#a05a00", "#b00000", "#707070"};
    const char *darkInk[] = {"#8ab4f8", "#f0b060", "#ff7070", "#a0a0a0"};
    for(int i = 0; i < 4; i++) {
      GtkTextTag *tag = gtk_text_tag_table_lookup(table, names[i]);
      if(!tag) tag = gtk_text_buffer_create_tag(buffer, names[i], nullptr);
      g_object_set(tag, "foreground", dark ? darkInk[i] : light[i], nullptr);
    }
  }

  void _consoleSave(GSimpleAction *, GVariant *, gpointer)
  {
    std::function<void()> what = gtkSources().saveMessages;
    if(what) gtkLater(what);
  }

  void _consoleClear(GSimpleAction *, GVariant *, gpointer)
  {
    if(!_w) return;
    _w->said.clear();
    gtk_text_buffer_set_text(
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(_w->console)), "", 0);
  }

  void _consoleFollow()
  {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(_w->console));
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &end);
    GtkTextMark *mark = gtk_text_buffer_get_mark(buffer, "gmsh-end");
    if(!mark)
      mark = gtk_text_buffer_create_mark(buffer, "gmsh-end", &end, FALSE);
    else
      gtk_text_buffer_move_mark(buffer, mark, &end);
    gtk_text_view_scroll_mark_onscreen(GTK_TEXT_VIEW(_w->console), mark);
  }

  void _consoleLine(const std::string &text, int level)
  {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(_w->console));
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &end);
    const char *tag = level == Ui::Backend::Direct  ? "direct" :
                      level == Ui::Backend::Warning ? "warning" :
                      level == Ui::Backend::Error   ? "error" :
                      level == Ui::Backend::Debug   ? "debug" :
                                                      nullptr;
    std::string line = text + "\n";
    if(tag)
      gtk_text_buffer_insert_with_tags_by_name(buffer, &end, line.c_str(), -1,
                                               tag, nullptr);
    else
      gtk_text_buffer_insert(buffer, &end, line.c_str(), -1);
  }

  void _consoleFiltered(GtkEditable *entry, gpointer)
  {
    if(!_w || !_w->said.setFilter(gtk_editable_get_text(entry))) return;
    gtk_text_buffer_set_text(
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(_w->console)), "", 0);
    for(const Ui::Console::Line *l : _w->said.shown())
      _consoleLine(l->text, l->level);
    if(_w->said.autoScroll()) _consoleFollow();
  }

  void _consoleSaveClicked(GtkButton *, gpointer)
  {
    _consoleSave(nullptr, nullptr, nullptr);
  }

  void _consoleClearClicked(GtkButton *, gpointer)
  {
    _consoleClear(nullptr, nullptr, nullptr);
  }

  void _consoleFollowToggled(GtkCheckButton *b, gpointer)
  {
    if(!_w) return;
    _w->said.setAutoScroll(gtk_check_button_get_active(b));
    if(_w->said.autoScroll()) _consoleFollow();
  }

  // the bar over the lines: the filter, Save, Clear, Autoscroll
  GtkWidget *_consoleBar()
  {
    bool tips = gtkSources().settings().tooltips;
    GtkWidget *bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    gtk_widget_set_margin_start(bar, 2);
    gtk_widget_set_margin_top(bar, 2);
    gtk_widget_set_margin_bottom(bar, 2);
    if(GtkWidget *look = gtkGlyph(Ui::Console::filterGlyph()))
      gtk_box_append(GTK_BOX(bar), look);
    _w->filter = gtk_entry_new();
    gtk_widget_set_size_request(_w->filter, gtkPx(15.), -1);
    if(tips) gtk_widget_set_tooltip_text(_w->filter, Ui::Console::filterTip());
    g_signal_connect(_w->filter, "changed", G_CALLBACK(_consoleFiltered),
                     nullptr);
    gtk_box_append(GTK_BOX(bar), _w->filter);
    GtkWidget *save = gtk_button_new_with_label(Ui::Console::saveLabel());
    if(tips) gtk_widget_set_tooltip_text(save, Ui::Console::saveTip());
    g_signal_connect(save, "clicked", G_CALLBACK(_consoleSaveClicked), nullptr);
    gtk_box_append(GTK_BOX(bar), save);
    GtkWidget *clear = gtk_button_new_with_label(Ui::Console::clearLabel());
    if(tips) gtk_widget_set_tooltip_text(clear, Ui::Console::clearTip());
    g_signal_connect(clear, "clicked", G_CALLBACK(_consoleClearClicked),
                     nullptr);
    gtk_box_append(GTK_BOX(bar), clear);
    GtkWidget *follow =
      gtk_check_button_new_with_label(Ui::Console::autoScrollLabel());
    gtk_check_button_set_active(GTK_CHECK_BUTTON(follow), _w->said.autoScroll());
    g_signal_connect(follow, "toggled", G_CALLBACK(_consoleFollowToggled),
                     nullptr);
    gtk_box_append(GTK_BOX(bar), follow);
    return bar;
  }

  // --- the bar along the bottom

  void _barClicked(GtkButton *button, gpointer data)
  {
    std::size_t i = (std::size_t)GPOINTER_TO_INT(data);
    std::vector<Ui::BarButton> bar = gtkSources().barButtons();
    if(i >= bar.size()) return;
    const Ui::BarButton &b = bar[i];
    if(b.menu) {
      gtkPopupMenu(b.menu(), GTK_WIDGET(button), -1., -1.);
      return;
    }
    GdkModifierType state = _modifiers();
    bool reverse = (state & GDK_SHIFT_MASK) != 0;
    bool sync = (state & GDK_CONTROL_MASK) != 0;
    std::function<void(bool, bool)> what = b.action;
    gtkLater([what, reverse, sync]() {
      if(what) what(reverse, sync);
      gtkRefreshBar();
    });
  }

  void _messagePressed(GtkButton *, gpointer)
  {
    std::function<void()> what = gtkSources().barPressed;
    if(what) gtkLater(what);
  }

} // namespace

void gtkRefreshBar()
{
  if(!_w || !gtkSources().barButtons) return;
  std::vector<Ui::BarButton> bar = gtkSources().barButtons();
  // made again when the buttons are not the same ones
  std::string shape = Ui::signature(bar);
  if(shape != _w->barBuilt) {
    _w->barBuilt = shape;
    while(GtkWidget *c = gtk_widget_get_first_child(_w->buttons))
      gtk_box_remove(GTK_BOX(_w->buttons), c);
    for(std::size_t i = 0; i < bar.size(); i++) {
      if(bar[i].gapBefore && i)
        gtk_box_append(GTK_BOX(_w->buttons),
                       gtk_separator_new(GTK_ORIENTATION_VERTICAL));
      GtkWidget *b = gtk_button_new_with_label(bar[i].label.c_str());
      gtk_widget_add_css_class(b, "flat");
      if(bar[i].widthEm > 0.)
        gtk_widget_set_size_request(b, gtkPx(bar[i].widthEm), -1);
      g_signal_connect(b, "clicked", G_CALLBACK(_barClicked),
                       GINT_TO_POINTER((int)i));
      gtk_box_append(GTK_BOX(_w->buttons), b);
    }
  }
  // what each says, and how it looks, now
  std::size_t i = 0;
  for(GtkWidget *c = gtk_widget_get_first_child(_w->buttons); c;
      c = gtk_widget_get_next_sibling(c)) {
    if(!GTK_IS_BUTTON(c)) continue;
    if(i >= bar.size()) break;
    const Ui::BarButton &b = bar[i++];
    bool on = b.on && b.on();
    std::string label = (on && b.labelOn.size()) ? b.labelOn : b.label;
    std::string glyph = (on && b.glyphOn.size()) ? b.glyphOn : b.glyph;
    gtkButtonShows(c, label, glyph);
    gtk_widget_set_sensitive(c, b.enabled ? b.enabled() : TRUE);
    if(b.tooltip.size() && gtkSources().settings().tooltips)
      gtk_widget_set_tooltip_text(c, b.tooltip.c_str());
    // the classes it had are taken off before the ones it has now go on
    for(const char *k : {"destructive-action", "suggested-action"})
      gtk_widget_remove_css_class(c, k);
    char **classes = gtk_widget_get_css_classes(c);
    for(char **k = classes; k && *k; k++)
      if(!strncmp(*k, "gmsh-on-", 8)) gtk_widget_remove_css_class(c, *k);
    g_strfreev(classes);
    if(b.alert && b.alert())
      gtk_widget_add_css_class(c, "destructive-action");
    else if(on && b.onColour)
      gtk_widget_add_css_class(c, _colourClass(b.onColour()).c_str());
    else if(on)
      gtk_widget_add_css_class(c, "suggested-action");
  }
  if(gtkSources().barMessage) {
    Ui::BarMessage m = gtkSources().barMessage();
    if(m.text != gtk_label_get_text(GTK_LABEL(_w->messageLabel)))
      gtk_label_set_text(GTK_LABEL(_w->messageLabel), m.text.c_str());
    gtk_widget_remove_css_class(_w->messageLabel, "error");
    gtk_widget_remove_css_class(_w->messageLabel, "warning");
    if(m.weight == Ui::MessageError)
      gtk_widget_add_css_class(_w->messageLabel, "error");
    else if(m.weight == Ui::MessageWarning)
      gtk_widget_add_css_class(_w->messageLabel, "warning");
    // a progress that has come to its end stays said: not shown then
    // the progress of what has finished stays said, at nought or at the end
    bool going = m.running && m.fraction > 0. && m.fraction < 1.;
    gtk_widget_set_visible(_w->progress, going);
    if(going) {
      gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(_w->progress),
                                    std::max(0., std::min(1., m.fraction)));
      gtk_progress_bar_set_text(GTK_PROGRESS_BAR(_w->progress),
                                m.progressText.c_str());
    }
  }
  if(gtkSources().barTooltip && gtkSources().settings().tooltips)
    gtk_widget_set_tooltip_text(_w->message, gtkSources().barTooltip().c_str());
}

namespace {

  // --- the tree and the buttons under it

  void _refreshFooter()
  {
    if(!_w) return;
    std::vector<Ui::Button> row = gtkSources().tree.footer ?
                                    gtkSources().tree.footer() :
                                    std::vector<Ui::Button>();
    std::string shape = Ui::signature(row);
    if(shape == _w->footerBuilt) return;
    _w->footerBuilt = shape;
    while(GtkWidget *c = gtk_widget_get_first_child(_w->footer))
      gtk_box_remove(GTK_BOX(_w->footer), c);
    for(const auto &b : row) {
      GtkWidget *w = gtkButtonWidget(b, []() {
        gtkLater([]() {
          if(_w && _w->tree) _w->tree->refresh(false);
          _refreshFooter();
        });
      });
      gtk_widget_set_hexpand(w, TRUE);
      gtk_box_append(GTK_BOX(_w->footer), w);
    }
    gtk_widget_set_visible(_w->footer, !row.empty());
  }

  // --- the tree: a pane beside the scene, or detached in a window of its own

  bool _treeShown()
  {
    return _w->treeWin ? gtk_widget_get_visible(_w->treeWin) :
                         gtk_widget_get_visible(_w->treeBox);
  }

  void _showTree(bool show)
  {
    gtk_widget_set_visible(_w->treeBox, show);
    if(_w->treeWin) gtk_widget_set_visible(_w->treeWin, show);
  }

  void _detachTree(bool detached);
  gboolean _windowKey(GtkEventControllerKey *, guint keyval, guint,
                      GdkModifierType state, gpointer);

  // closed from its frame, it goes back in the main window: closed, it
  // could not be had back
  gboolean _treeCloseRequest(GtkWindow *, gpointer)
  {
    _detachTree(false);
    return TRUE;
  }

  void _detachTree(bool detached)
  {
    if(!_w || detached == (_w->treeWin != nullptr)) return;
    if(detached) {
      const Ui::Backend::Settings set = gtkSources().settings();
      int width = gtk_paned_get_position(GTK_PANED(_w->side));
      g_object_ref(_w->treeBox);
      gtk_paned_set_start_child(GTK_PANED(_w->side), nullptr);
      _w->treeWin = gtk_window_new();
      gtk_window_set_title(GTK_WINDOW(_w->treeWin), "Gmsh");
      gtk_window_set_default_size(GTK_WINDOW(_w->treeWin),
                                  width > 50 ? width : 300,
                                  set.treeHeight > 0 ? set.treeHeight : 600);
      gtk_window_set_child(GTK_WINDOW(_w->treeWin), _w->treeBox);
      g_object_unref(_w->treeBox);
      g_signal_connect(_w->treeWin, "close-request",
                       G_CALLBACK(_treeCloseRequest), nullptr);
      // the keys of the main window work in it too
      GtkEventController *keys = gtk_event_controller_key_new();
      g_signal_connect(keys, "key-pressed", G_CALLBACK(_windowKey), nullptr);
      gtk_widget_add_controller(_w->treeWin, keys);
      gtk_widget_set_visible(_w->treeBox, TRUE);
      gtk_window_present(GTK_WINDOW(_w->treeWin));
      return;
    }
    Ui::Backend::Layout l;
    l.treeHeight = gtk_widget_get_height(_w->treeWin);
    if(gtkHost().layoutChanged) gtkHost().layoutChanged(l);
    g_object_ref(_w->treeBox);
    gtk_window_set_child(GTK_WINDOW(_w->treeWin), nullptr);
    gtk_window_destroy(GTK_WINDOW(_w->treeWin));
    _w->treeWin = nullptr;
    gtk_paned_set_start_child(GTK_PANED(_w->side), _w->treeBox);
    g_object_unref(_w->treeBox);
  }

  // --- the window as a whole

  void _fullscreen(bool on)
  {
    if(!_w || on == _w->fullscreen) return;
    _w->fullscreen = on;
    if(on) {
      _w->treeWas = _treeShown();
      _w->consoleWas = gtk_widget_get_visible(_w->consoleBox);
      gtk_window_fullscreen(GTK_WINDOW(_w->win));
    }
    else
      gtk_window_unfullscreen(GTK_WINDOW(_w->win));
    // nothing but the scene
    gtk_widget_set_visible(_w->menuBar, !on);
    gtk_widget_set_visible(_w->bar, !on);
    _showTree(!on && _w->treeWas);
    gtk_widget_set_visible(_w->consoleBox, !on && _w->consoleWas);
  }

  gboolean _closeRequest(GtkWindow *, gpointer)
  {
    std::function<void()> quit = gtkHost().quitting;
    if(quit)
      gtkLater(quit);
    else
      _running = false;
    return TRUE;
  }

  gboolean _dropped(GtkDropTarget *, const GValue *value, double, double,
                    gpointer)
  {
    if(!G_VALUE_HOLDS(value, GDK_TYPE_FILE_LIST)) return FALSE;
    std::vector<std::string> paths;
    for(GSList *l = (GSList *)g_value_get_boxed(value); l; l = l->next) {
      char *path = g_file_get_path(G_FILE(l->data));
      if(path) paths.push_back(path);
      g_free(path);
    }
    std::function<void(const std::vector<std::string> &)> open =
      gtkHost().filesDropped;
    if(open && paths.size()) gtkLater([open, paths]() { open(paths); });
    return TRUE;
  }

  gboolean _windowKey(GtkEventControllerKey *, guint keyval, guint,
                      GdkModifierType state, gpointer)
  {
    return gtkMainKey(keyval, state);
  }

  void _build(bool quitShouldExit)
  {
    const Ui::Backend::Settings set = gtkSources().settings();
    _w = new mainWindow;
    _w->win = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(_w->win), "Gmsh");
    gtk_window_set_icon_name(GTK_WINDOW(_w->win), "info.gmsh.gmsh");
    int treeWidth = set.treeWidth > 50 ? set.treeWidth : 300;
    int w = (set.sceneWidth > 100 ? set.sceneWidth : 700) + treeWidth;
    int h = (set.sceneHeight > 100 ? set.sceneHeight : 600) +
            (set.consoleHeight > 0 ? set.consoleHeight : 0) + 80;
    gtk_window_set_default_size(GTK_WINDOW(_w->win), w, h);
    _sheet(set.darkScheme, set.fontSize, set.consoleFontSize);
    g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme",
                 set.darkScheme ? TRUE : FALSE, nullptr);

    GtkWidget *all = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    _w->menuBar = gtkMenuBar(_w->win);
    gtk_box_append(GTK_BOX(all), _w->menuBar);

    // the tree, and the buttons of the solver under it
    _w->treeBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    _w->tree = new treeGtk(gtkSources().tree, false, []() {
      gtkLater([]() {
        if(_w && _w->tree) _w->tree->refresh(false);
      });
    });
    gtk_box_append(GTK_BOX(_w->treeBox), _w->tree->widget());
    _w->footer = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    gtk_widget_set_margin_start(_w->footer, 4);
    gtk_widget_set_margin_end(_w->footer, 4);
    gtk_widget_set_margin_top(_w->footer, 4);
    gtk_widget_set_margin_bottom(_w->footer, 4);
    gtk_box_append(GTK_BOX(_w->treeBox), _w->footer);
    gtk_widget_set_visible(_w->treeBox, set.showModuleMenu);

    // the scene over the console
    _w->split = gtk_paned_new(GTK_ORIENTATION_VERTICAL);
    gtk_paned_set_start_child(GTK_PANED(_w->split), gtkSceneWidget());
    gtk_paned_set_resize_start_child(GTK_PANED(_w->split), TRUE);
    gtk_paned_set_shrink_end_child(GTK_PANED(_w->split), FALSE);
    _w->console = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(_w->console), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(_w->console), FALSE);
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(_w->console), 4);
    gtk_widget_add_css_class(_w->console, "gmsh-console");
    _consoleTags(gtk_text_view_get_buffer(GTK_TEXT_VIEW(_w->console)),
                 set.darkScheme);
    {
      GSimpleActionGroup *group = g_simple_action_group_new();
      GSimpleAction *save = g_simple_action_new("save", nullptr);
      g_signal_connect(save, "activate", G_CALLBACK(_consoleSave), nullptr);
      g_action_map_add_action(G_ACTION_MAP(group), G_ACTION(save));
      g_object_unref(save);
      GSimpleAction *clear = g_simple_action_new("clear", nullptr);
      g_signal_connect(clear, "activate", G_CALLBACK(_consoleClear), nullptr);
      g_action_map_add_action(G_ACTION_MAP(group), G_ACTION(clear));
      g_object_unref(clear);
      gtk_widget_insert_action_group(_w->console, "console",
                                     G_ACTION_GROUP(group));
      g_object_unref(group);
      GMenu *more = g_menu_new();
      g_menu_append(more, "Save Messages As…", "console.save");
      g_menu_append(more, "Clear Messages", "console.clear");
      gtk_text_view_set_extra_menu(GTK_TEXT_VIEW(_w->console),
                                   G_MENU_MODEL(more));
      g_object_unref(more);
    }
    _w->consoleScroll = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(_w->consoleScroll),
                                  _w->console);
    gtk_widget_set_vexpand(_w->consoleScroll, TRUE);
    _w->consoleBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_append(GTK_BOX(_w->consoleBox), _consoleBar());
    gtk_box_append(GTK_BOX(_w->consoleBox), _w->consoleScroll);
    gtk_widget_set_size_request(_w->consoleBox, -1, 40);
    gtk_paned_set_end_child(GTK_PANED(_w->split), _w->consoleBox);
    gtk_paned_set_resize_end_child(GTK_PANED(_w->split), FALSE);

    // the dialogs docked down the right, as the page has them
    GtkWidget *dockScroll = gtk_scrolled_window_new();
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(dockScroll),
                                   GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_propagate_natural_width(
      GTK_SCROLLED_WINDOW(dockScroll), TRUE);
    GtkWidget *dock = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_margin_start(dock, 6);
    gtk_widget_set_margin_end(dock, 6);
    gtk_widget_set_margin_top(dock, 6);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(dockScroll), dock);
    GtkWidget *docked = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_paned_set_start_child(GTK_PANED(docked), _w->split);
    gtk_paned_set_end_child(GTK_PANED(docked), dockScroll);
    gtk_paned_set_resize_end_child(GTK_PANED(docked), FALSE);
    gtk_paned_set_shrink_end_child(GTK_PANED(docked), FALSE);
    gtkSetDock(dock);

    _w->side = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_paned_set_start_child(GTK_PANED(_w->side), _w->treeBox);
    gtk_paned_set_end_child(GTK_PANED(_w->side), docked);
    gtk_paned_set_resize_start_child(GTK_PANED(_w->side), FALSE);
    gtk_paned_set_shrink_start_child(GTK_PANED(_w->side), FALSE);
    gtk_paned_set_position(GTK_PANED(_w->side), treeWidth);
    gtk_widget_set_vexpand(_w->side, TRUE);
    gtk_box_append(GTK_BOX(all), _w->side);

    // the bar: the buttons, the message one presses to show the messages,
    // the progress of what runs
    _w->bar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_widget_add_css_class(_w->bar, "gmsh-bar");
    _w->buttons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_append(GTK_BOX(_w->bar), _w->buttons);
    gtk_box_append(GTK_BOX(_w->bar), gtk_separator_new(GTK_ORIENTATION_VERTICAL));
    _w->message = gtk_button_new();
    gtk_widget_add_css_class(_w->message, "flat");
    _w->messageLabel = gtk_label_new("");
    gtk_label_set_xalign(GTK_LABEL(_w->messageLabel), 0.f);
    gtk_label_set_ellipsize(GTK_LABEL(_w->messageLabel), PANGO_ELLIPSIZE_END);
    gtk_label_set_width_chars(GTK_LABEL(_w->messageLabel), 1);
    gtk_button_set_child(GTK_BUTTON(_w->message), _w->messageLabel);
    gtk_widget_set_hexpand(_w->message, TRUE);
    g_signal_connect(_w->message, "clicked", G_CALLBACK(_messagePressed),
                     nullptr);
    gtk_box_append(GTK_BOX(_w->bar), _w->message);
    _w->progress = gtk_progress_bar_new();
    gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(_w->progress), TRUE);
    gtk_widget_set_size_request(_w->progress, 200, -1);
    gtk_widget_set_valign(_w->progress, GTK_ALIGN_CENTER);
    gtk_widget_set_visible(_w->progress, FALSE);
    gtk_box_append(GTK_BOX(_w->bar), _w->progress);
    gtk_box_append(GTK_BOX(all), _w->bar);

    gtk_window_set_child(GTK_WINDOW(_w->win), all);
    g_signal_connect(_w->win, "close-request", G_CALLBACK(_closeRequest),
                     nullptr);
    GtkEventController *keys = gtk_event_controller_key_new();
    g_signal_connect(keys, "key-pressed", G_CALLBACK(_windowKey), nullptr);
    gtk_widget_add_controller(_w->win, keys);
    gtkWatchButtons(_w->win);
    GtkDropTarget *drop = gtk_drop_target_new(GDK_TYPE_FILE_LIST, GDK_ACTION_COPY);
    g_signal_connect(drop, "drop", G_CALLBACK(_dropped), nullptr);
    gtk_widget_add_controller(_w->win, GTK_EVENT_CONTROLLER(drop));

    gtkSetMainWindow(GTK_WINDOW(_w->win));
    _refreshFooter();
    gtkRefreshBar();
    gtk_window_present(GTK_WINDOW(_w->win));
    if(set.detachedTree) _detachTree(true);
    // the console as tall as the options say, once the window has a height
    int consoleHeight = set.consoleHeight > 0 ? set.consoleHeight : 150;
    int sceneHeight = h - 80;
    gtk_paned_set_position(GTK_PANED(_w->split),
                           std::max(100, sceneHeight - consoleHeight));
  }

  // --- asking the user

  struct asking {
    bool done = false;
    int answer = 0;
  };

  void _runUntil(asking &a)
  {
    while(!a.done) g_main_context_iteration(nullptr, TRUE);
  }

  GtkWidget *_askWindow(const std::string &title, asking &a)
  {
    GtkWidget *w = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(w), title.c_str());
    gtk_window_set_modal(GTK_WINDOW(w), TRUE);
    if(_w) gtk_window_set_transient_for(GTK_WINDOW(w), GTK_WINDOW(_w->win));
    gtk_window_set_resizable(GTK_WINDOW(w), TRUE);
    g_signal_connect(w, "close-request",
                     G_CALLBACK(+[](GtkWindow *, gpointer data) -> gboolean {
                       asking *a = (asking *)data;
                       a->answer = -1;
                       a->done = true;
                       return TRUE;
                     }),
                     &a);
    GtkEventController *keys = gtk_event_controller_key_new();
    g_signal_connect(keys, "key-pressed",
                     G_CALLBACK(+[](GtkEventControllerKey *, guint keyval, guint,
                                    GdkModifierType, gpointer data) -> gboolean {
                       if(keyval != GDK_KEY_Escape) return FALSE;
                       asking *a = (asking *)data;
                       a->answer = -1;
                       a->done = true;
                       return TRUE;
                     }),
                     &a);
    gtk_widget_add_controller(w, keys);
    return w;
  }

  GtkWidget *_answerButton(const std::string &label, int answer, asking &a)
  {
    GtkWidget *b = gtk_button_new_with_label(label.c_str());
    g_object_set_data(G_OBJECT(b), "gmsh-answer", GINT_TO_POINTER(answer));
    g_signal_connect(b, "clicked", G_CALLBACK(+[](GtkButton *b, gpointer data) {
                       asking *a = (asking *)data;
                       a->answer = GPOINTER_TO_INT(
                         g_object_get_data(G_OBJECT(b), "gmsh-answer"));
                       a->done = true;
                     }),
                     &a);
    return b;
  }

  GtkWidget *_padded(GtkWidget *w)
  {
    gtk_widget_set_margin_top(w, 12);
    gtk_widget_set_margin_bottom(w, 12);
    gtk_widget_set_margin_start(w, 12);
    gtk_widget_set_margin_end(w, 12);
    return w;
  }

  void _patterns(GtkFileFilter *filter, const Ui::Backend::FileFormat &f)
  {
    for(const auto &p : f.patterns())
      gtk_file_filter_add_pattern(filter, p.c_str());
  }

  struct choosing {
    bool done = false;
    std::vector<std::string> names;
  };

  void _chosenOne(GObject *dialog, GAsyncResult *result, gpointer data)
  {
    choosing *c = (choosing *)data;
    GFile *f = nullptr;
    if(g_object_get_data(G_OBJECT(dialog), "gmsh-save"))
      f = gtk_file_dialog_save_finish(GTK_FILE_DIALOG(dialog), result, nullptr);
    else
      f = gtk_file_dialog_open_finish(GTK_FILE_DIALOG(dialog), result, nullptr);
    if(f) {
      char *path = g_file_get_path(f);
      if(path) c->names.push_back(path);
      g_free(path);
      g_object_unref(f);
    }
    c->done = true;
  }

  void _chosenSeveral(GObject *dialog, GAsyncResult *result, gpointer data)
  {
    choosing *c = (choosing *)data;
    GListModel *files = gtk_file_dialog_open_multiple_finish(
      GTK_FILE_DIALOG(dialog), result, nullptr);
    if(files) {
      for(guint i = 0; i < g_list_model_get_n_items(files); i++) {
        GFile *f = G_FILE(g_list_model_get_item(files, i));
        char *path = g_file_get_path(f);
        if(path) c->names.push_back(path);
        g_free(path);
        g_object_unref(f);
      }
      g_object_unref(files);
    }
    c->done = true;
  }

  // --- the backend

  class backendGtk : public Ui::Backend {
  public:
    std::string name() override
    {
      char s[64];
      snprintf(s, sizeof(s), "GTK %u.%u.%u", gtk_get_major_version(),
               gtk_get_minor_version(), gtk_get_micro_version());
      return s;
    }

    void setSources(const Sources &sources) override { _sources = sources; }
    const Sources &sources() const { return _sources; }
    void setHost(const Host &host) override { _host = host; }
    const Host &host() const { return _host; }

    bool create(int argc, char **argv, bool quitShouldExit) override
    {
      if(_w) return true;
      // the Wayland app id and the X11 class, which window rules key on
      g_set_prgname("info.gmsh.gmsh");
      g_set_application_name("Gmsh");
      // the numbers are read and written the C way: GTK would take the
      // locale of the environment, and a decimal comma with it
      gtk_disable_setlocale();
      if(!gtk_init_check()) {
        if(_host.error)
          _host.error("Could not open a display: no graphical interface "
                      "available");
        return false;
      }
      _build(quitShouldExit);
      gtkSceneStartTimers();
      return true;
    }

    void destroy() override
    {
      _running = false;
      if(!_w) return;
      gtkFormsClosingDown();
      delete _w->tree;
      _w->tree = nullptr;
      GtkWidget *win = _w->win, *treeWin = _w->treeWin;
      mainWindow *w = _w;
      _w = nullptr;
      gtkSetMainWindow(nullptr);
      gtkSetDock(nullptr);
      gtkSceneDestroy();
      gtk_window_destroy(GTK_WINDOW(win));
      if(treeWin) gtk_window_destroy(GTK_WINDOW(treeWin));
      if(w->sheet) {
        gtk_style_context_remove_provider_for_display(
          gdk_display_get_default(), GTK_STYLE_PROVIDER(w->sheet));
        g_object_unref(w->sheet);
      }
      delete w;
      // what the destroyed windows leave is handled before anything else
      while(g_main_context_iteration(nullptr, FALSE)) {}
    }

    int runLoop() override
    {
      _running = true;
      while(_running && _w) g_main_context_iteration(nullptr, TRUE);
      return 0;
    }

    void check(bool rateLimited) override
    {
      if(!_w || _locked > 0 || gtkSceneDrawing()) return;
      double now = _now();
      double rate = _sources.settings ? _sources.settings().refreshRate : 0.;
      if(rateLimited && rate > 0. && now - _lastCheck < 1. / rate) return;
      _lastCheck = now;
      // what is there, and no more: the mesher is waiting
      for(int i = 0; i < 1000 && g_main_context_iteration(nullptr, FALSE); i++) {
      }
    }

    bool ready() override { return _w != nullptr; }

    void wait(double seconds, bool force) override
    {
      if(!_w || gtkSceneDrawing()) return;
      if(!force && _locked > 0) return;
      if(seconds < 0.) {
        g_main_context_iteration(nullptr, TRUE);
        return;
      }
      if(seconds == 0.) {
        g_main_context_iteration(nullptr, FALSE);
        return;
      }
      bool *fired = new bool(false);
      guint t = g_timeout_add_full(G_PRIORITY_DEFAULT, (guint)(seconds * 1000.),
                                   [](gpointer data) -> gboolean {
                                     *(bool *)data = true;
                                     return G_SOURCE_REMOVE;
                                   },
                                   fired, nullptr);
      g_main_context_iteration(nullptr, TRUE);
      if(!*fired) g_source_remove(t);
      // the source is gone either way: nothing can write it any more
      delete fired;
    }

    void lock() override { _locked++; }
    void unlock() override { _locked--; }
    int locked() override { return _locked; }

    void postFromThread(const std::function<void()> &what) override
    {
      // GLib's default context wakes up for a source added from any thread
      g_idle_add_full(G_PRIORITY_DEFAULT,
                      [](gpointer data) -> gboolean {
                        (*(std::function<void()> *)data)();
                        return G_SOURCE_REMOVE;
                      },
                      new std::function<void()>(what), [](gpointer data) {
                        delete(std::function<void()> *) data;
                      });
    }

    void copyText(const std::string &text) override
    {
      GdkDisplay *display = gdk_display_get_default();
      if(!display) return;
      gdk_clipboard_set_text(gdk_display_get_clipboard(display), text.c_str());
      gdk_clipboard_set_text(gdk_display_get_primary_clipboard(display),
                             text.c_str());
    }

    void beep() override
    {
      if(_w) gtk_widget_error_bell(_w->win);
    }

    // --- messages, the bar

    void addMessage(const std::string &text, int level) override
    {
      if(!_w || !_w->said.add(text, level)) return;
      _consoleLine(text, level);
      if(_w->said.autoScroll()) _consoleFollow();
    }

    void messageLines(std::vector<std::string> &lines) override
    {
      if(_w) lines = _w->said.texts();
    }

    void refreshBar() override { gtkRefreshBar(); }

    void optionChanged(const std::string &name) override
    {
      gtkFormOptionChanged(name);
    }

    int numWindows() override { return _w ? 1 : 0; }

    void setWindowTitle(int which, const std::string &title) override
    {
      if(_w && which == 0)
        gtk_window_set_title(GTK_WINDOW(_w->win), title.c_str());
    }

    // --- the questions that stop everything

    bool inputDialog(const std::string &question, std::string &value,
                     const std::string &hint, bool readOnly) override
    {
      asking a;
      GtkWidget *w = _askWindow("Gmsh", a);
      GtkWidget *box = _padded(gtk_box_new(GTK_ORIENTATION_VERTICAL, 8));
      GtkWidget *say = gtk_label_new(question.c_str());
      gtk_label_set_wrap(GTK_LABEL(say), TRUE);
      gtk_label_set_max_width_chars(GTK_LABEL(say), 70);
      gtk_label_set_xalign(GTK_LABEL(say), 0.f);
      gtk_box_append(GTK_BOX(box), say);
      if(hint.size()) {
        GtkWidget *h = gtk_label_new(hint.c_str());
        gtk_widget_add_css_class(h, "dim-label");
        gtk_label_set_wrap(GTK_LABEL(h), TRUE);
        gtk_label_set_xalign(GTK_LABEL(h), 0.f);
        gtk_box_append(GTK_BOX(box), h);
      }
      // several lines: a little editor, or what is shown
      GtkWidget *entry = nullptr, *text = nullptr;
      if(readOnly || hint.size() || value.find('\n') != std::string::npos) {
        GtkWidget *scroll = gtk_scrolled_window_new();
        gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(scroll),
                                                   readOnly ? 300 : 120);
        gtk_scrolled_window_set_min_content_width(GTK_SCROLLED_WINDOW(scroll),
                                                  500);
        gtk_widget_set_vexpand(scroll, TRUE);
        gtk_widget_add_css_class(scroll, "frame");
        text = gtk_text_view_new();
        gtk_widget_add_css_class(text, "monospace");
        gtk_text_view_set_editable(GTK_TEXT_VIEW(text), !readOnly);
        gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(text)),
                                 value.c_str(), -1);
        gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll), text);
        gtk_box_append(GTK_BOX(box), scroll);
      }
      else {
        entry = gtk_entry_new();
        gtk_editable_set_text(GTK_EDITABLE(entry), value.c_str());
        gtk_entry_set_activates_default(GTK_ENTRY(entry), TRUE);
        gtk_widget_set_size_request(entry, 360, -1);
        gtk_box_append(GTK_BOX(box), entry);
      }
      GtkWidget *row = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
      gtk_widget_set_halign(row, GTK_ALIGN_END);
      if(readOnly)
        gtk_box_append(GTK_BOX(row), _answerButton("Close", 0, a));
      else {
        gtk_box_append(GTK_BOX(row), _answerButton("Cancel", 0, a));
        GtkWidget *ok = _answerButton("OK", 1, a);
        gtk_widget_add_css_class(ok, "suggested-action");
        gtk_box_append(GTK_BOX(row), ok);
        gtk_window_set_default_widget(GTK_WINDOW(w), ok);
      }
      gtk_box_append(GTK_BOX(box), row);
      gtk_window_set_child(GTK_WINDOW(w), box);
      gtk_window_present(GTK_WINDOW(w));
      if(entry) gtk_widget_grab_focus(entry);
      _runUntil(a);
      bool ok = !readOnly && a.answer == 1;
      if(ok) {
        if(entry)
          value = gtk_editable_get_text(GTK_EDITABLE(entry));
        else {
          GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text));
          GtkTextIter from, to;
          gtk_text_buffer_get_bounds(buffer, &from, &to);
          char *said = gtk_text_buffer_get_text(buffer, &from, &to, FALSE);
          value = said;
          g_free(said);
        }
      }
      gtk_window_destroy(GTK_WINDOW(w));
      return ok;
    }

    int questionDialog(const std::string &question, const std::string &zero,
                       const std::string &one,
                       const std::string &two) override
    {
      asking a;
      GtkWidget *w = _askWindow("Gmsh", a);
      GtkWidget *box = _padded(gtk_box_new(GTK_ORIENTATION_VERTICAL, 12));
      GtkWidget *say = gtk_label_new(question.c_str());
      gtk_label_set_wrap(GTK_LABEL(say), TRUE);
      gtk_label_set_max_width_chars(GTK_LABEL(say), 70);
      gtk_label_set_xalign(GTK_LABEL(say), 0.f);
      gtk_box_append(GTK_BOX(box), say);
      GtkWidget *row = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
      gtk_widget_set_halign(row, GTK_ALIGN_END);
      // Return presses the second, or the only one, as fl_choice() has it
      GtkWidget *last = nullptr;
      const std::string *said[3] = {&zero, &one, &two};
      for(int i = 0; i < 3; i++) {
        if(said[i]->empty()) continue;
        GtkWidget *b = _answerButton(*said[i], i, a);
        if(i == 0 || i == 1) last = b;
        gtk_box_append(GTK_BOX(row), b);
      }
      if(last) {
        gtk_widget_add_css_class(last, "suggested-action");
        gtk_window_set_default_widget(GTK_WINDOW(w), last);
      }
      gtk_box_append(GTK_BOX(box), row);
      gtk_window_set_child(GTK_WINDOW(w), box);
      gtk_window_present(GTK_WINDOW(w));
      if(last) gtk_widget_grab_focus(last);
      _runUntil(a);
      gtk_window_destroy(GTK_WINDOW(w));
      // closed: the first, as with FLTK
      return a.answer < 0 ? 0 : a.answer;
    }

    bool fileDialog(int mode, const std::string &title,
                    const std::vector<FileFormat> &formats,
                    std::vector<std::string> &names,
                    int *chosenFormat) override
    {
      GtkFileDialog *dialog = gtk_file_dialog_new();
      gtk_file_dialog_set_title(dialog, title.c_str());
      gtk_file_dialog_set_modal(dialog, TRUE);
      if(formats.size()) {
        GListStore *filters = g_list_store_new(GTK_TYPE_FILE_FILTER);
        for(const auto &f : formats) {
          GtkFileFilter *filter = gtk_file_filter_new();
          std::string name = f.name.size() ? f.name + " (" + f.pattern + ")" :
                                             f.pattern;
          gtk_file_filter_set_name(filter, name.c_str());
          _patterns(filter, f);
          g_list_store_append(filters, filter);
          g_object_unref(filter);
        }
        gtk_file_dialog_set_filters(dialog, G_LIST_MODEL(filters));
        g_object_unref(filters);
      }
      std::string from = names.empty() ? "" : names[0];
      if(from.size()) {
        GFile *file = g_file_new_for_path(from.c_str());
        if(g_file_query_file_type(file, G_FILE_QUERY_INFO_NONE, nullptr) ==
           G_FILE_TYPE_DIRECTORY)
          gtk_file_dialog_set_initial_folder(dialog, file);
        else if(mode == Create) {
          GFile *parent = g_file_get_parent(file);
          if(parent &&
             g_file_query_file_type(parent, G_FILE_QUERY_INFO_NONE, nullptr) ==
               G_FILE_TYPE_DIRECTORY)
            gtk_file_dialog_set_initial_folder(dialog, parent);
          if(parent) g_object_unref(parent);
          char *base = g_path_get_basename(from.c_str());
          gtk_file_dialog_set_initial_name(dialog, base);
          g_free(base);
        }
        else if(g_file_query_exists(file, nullptr))
          gtk_file_dialog_set_initial_file(dialog, file);
        else {
          GFile *parent = g_file_get_parent(file);
          if(parent &&
             g_file_query_file_type(parent, G_FILE_QUERY_INFO_NONE, nullptr) ==
               G_FILE_TYPE_DIRECTORY)
            gtk_file_dialog_set_initial_folder(dialog, parent);
          if(parent) g_object_unref(parent);
        }
        g_object_unref(file);
      }
      choosing c;
      GtkWindow *parent = _w ? GTK_WINDOW(_w->win) : nullptr;
      if(mode == Create) {
        g_object_set_data(G_OBJECT(dialog), "gmsh-save", GINT_TO_POINTER(1));
        gtk_file_dialog_save(dialog, parent, nullptr, _chosenOne, &c);
      }
      else if(mode == OpenSeveral)
        gtk_file_dialog_open_multiple(dialog, parent, nullptr, _chosenSeveral,
                                      &c);
      else
        gtk_file_dialog_open(dialog, parent, nullptr, _chosenOne, &c);
      while(!c.done) g_main_context_iteration(nullptr, TRUE);
      g_object_unref(dialog);
      // the chooser does not say which filter was in force: the name of the
      // file decides
      if(chosenFormat) *chosenFormat = -1;
      if(c.names.empty()) return false;
      names = c.names;
      return true;
    }

    void applyColorScheme(bool dark) override
    {
      g_object_set(gtk_settings_get_default(),
                   "gtk-application-prefer-dark-theme", dark ? TRUE : FALSE,
                   nullptr);
      if(!_w) return;
      _consoleTags(gtk_text_view_get_buffer(GTK_TEXT_VIEW(_w->console)), dark);
      const Settings s = _sources.settings();
      _sheet(dark, s.fontSize, s.consoleFontSize);
    }

    // --- the things that are described

    void showForm(const Ui::Form &form, bool show) override
    {
      gtkShowForm(form, show);
    }
    bool formVisible(const Ui::Form &form) override
    {
      return gtkFormVisible(form);
    }
    std::string formPane(const Ui::Form &form) override
    {
      return gtkFormPane(form);
    }
    void setFormPane(const Ui::Form &form, const std::string &pane) override
    {
      gtkSetFormPane(form, pane);
    }
    void reloadForm(const Ui::Form &form) override { gtkReloadForm(form, false); }
    void rebuildForm(const Ui::Form &form) override { gtkReloadForm(form, true); }
    void dropForm(const Ui::Form &form) override { gtkDropForm(form); }

    void refreshMenus() override { gtkRefreshMenuBar(); }

    void popupMenu(const std::vector<Ui::MenuItem> &items,
                   const std::string &key) override
    {
      if(!_w) return;
      // under the pointer, over the scene
      GtkWidget *over = gtkSceneWidget();
      double x = gtk_widget_get_width(over) / 2., y = gtk_widget_get_height(over) / 2.;
      GdkDisplay *display = gdk_display_get_default();
      GdkSeat *seat = gdk_display_get_default_seat(display);
      GdkDevice *pointer = seat ? gdk_seat_get_pointer(seat) : nullptr;
      GtkNative *native = gtk_widget_get_native(over);
      if(pointer && native) {
        double sx = 0., sy = 0., nx = 0., ny = 0.;
        GdkSurface *s = gtk_native_get_surface(native);
        if(gdk_surface_get_device_position(s, pointer, &sx, &sy, nullptr)) {
          gtk_native_get_surface_transform(native, &nx, &ny);
          graphene_point_t in =
            GRAPHENE_POINT_INIT((float)(sx - nx), (float)(sy - ny));
          graphene_point_t out;
          if(gtk_widget_compute_point(GTK_WIDGET(native), over, &in, &out)) {
            x = out.x;
            y = out.y;
          }
        }
      }
      gtkPopupMenu(items, over, x, y);
    }

    void refreshTree(bool rebuild) override
    {
      if(!_w || !_w->tree) return;
      _w->tree->setTree(_sources.tree);
      _w->tree->refresh(rebuild);
      _refreshFooter();
    }

    void openTreeItem(const std::string &name, bool open) override
    {
      if(_w && _w->tree) _w->tree->open(name, open);
    }

    bool treeItemOpen(const std::string &name) override
    {
      return _w && _w->tree && _w->tree->isOpen(name);
    }

    void showTree() override
    {
      if(_w) _showTree(true);
    }

    void setSolverButtonMode(const std::string &, const std::string &) override
    {
      _refreshFooter();
    }

    void showConsole(bool show) override
    {
      if(_w) gtk_widget_set_visible(_w->consoleBox, show);
    }

    bool consoleVisible() override
    {
      return _w && gtk_widget_get_visible(_w->consoleBox);
    }

    // --- the interface as a whole

    void windowAction(const std::string &what) override
    {
      if(!_w) return;
      GtkWindow *win = GTK_WINDOW(_w->win);
      if(what == "new")
        gtkSceneNewWindow();
      else if(what == "minimize")
        gtk_window_minimize(win);
      else if(what == "zoom") {
        if(gtk_window_is_maximized(win))
          gtk_window_unmaximize(win);
        else
          gtk_window_maximize(win);
      }
      else if(what == "fullscreen")
        _fullscreen(!_w->fullscreen);
      else if(what == "front")
        gtk_window_present(win);
      else if(what == "show_hide_tree")
        _showTree(!_treeShown());
      else if(what == "attach_detach")
        _detachTree(!_w->treeWin);
      else if(_host.error)
        _host.error("Unknown window action '" + what + "'");
    }

    void detachTree(bool detached) override { _detachTree(detached); }

    Layout windowLayout() override
    {
      Layout l;
      if(!_w || _w->fullscreen) return l;
      gtkSceneSize(l.sceneWidth, l.sceneHeight);
      if(!_w->treeWin && gtk_widget_get_visible(_w->treeBox))
        l.treeWidth = gtk_paned_get_position(GTK_PANED(_w->side));
      if(gtk_widget_get_visible(_w->consoleBox))
        l.consoleHeight = gtk_widget_get_height(_w->consoleBox);
      // GTK 4 does not say where a window is
      l.treeDetached = _w->treeWin ? 1 : 0;
      if(_w->treeWin) l.treeHeight = gtk_widget_get_height(_w->treeWin);
      return l;
    }

    // --- what the options that shape the main window push into it

    void setSceneSize(int width, int height) override
    {
      if(!_w) return;
      int sw = 0, sh = 0;
      gtkSceneSize(sw, sh);
      int ww = gtk_widget_get_width(_w->win), wh = gtk_widget_get_height(_w->win);
      if(ww <= 0 || wh <= 0) return;
      if(width >= 0) ww += width - sw;
      if(height >= 0) wh += height - sh;
      gtk_window_set_default_size(GTK_WINDOW(_w->win), ww, wh);
    }

    void setConsoleFontSize(int size) override
    {
      const Settings s = _sources.settings();
      _sheet(s.darkScheme, s.fontSize, size);
    }

    void setTreeWidth(int width) override
    {
      if(!_w || width < 0) return;
      if(_w->treeWin)
        gtk_window_set_default_size(GTK_WINDOW(_w->treeWin), width,
                                    gtk_widget_get_height(_w->treeWin));
      else
        gtk_paned_set_position(GTK_PANED(_w->side), width);
    }

    void enableTooltips(bool on) override {}

  private:
    Sources _sources;
    Host _host;
  };

  backendGtk *_the = nullptr;

} // namespace

bool gtkMainKey(guint keyval, GdkModifierType state)
{
  switch(keyval) {
  case GDK_KEY_Shift_L:
  case GDK_KEY_Shift_R:
  case GDK_KEY_Control_L:
  case GDK_KEY_Control_R:
  case GDK_KEY_Alt_L:
  case GDK_KEY_Alt_R:
  case GDK_KEY_Meta_L:
  case GDK_KEY_Meta_R:
  case GDK_KEY_Super_L:
  case GDK_KEY_Super_R:
  case GDK_KEY_ISO_Level3_Shift: return FALSE;
  default: break;
  }
  int key = 0;
  unsigned mods = 0;
  if(!gtkUiKey(keyval, state, key, mods)) return FALSE;
  if(key == Ui::KeyEscape && _w && _w->fullscreen) {
    _fullscreen(false);
    return TRUE;
  }
  if(!gtkSources().keys) return FALSE;
  bool taken = false;
  // each may open a dialog or start a picking
  for(const Ui::KeyBinding &k : gtkSources().keys()) {
    if(!k.shortcut.matches(key, mods)) continue;
    taken = true;
    if(k.action) gtkLater(k.action);
    if(k.spent) break;
  }
  if(taken)
    gtkLater([]() {
      gtkRefreshBar();
      gtkRefreshMenuBar();
    });
  return taken;
}

const Ui::Backend::Sources &gtkSources()
{
  // before the interface was given anything, the settings are their defaults
  static Ui::Backend::Sources none = []() {
    Ui::Backend::Sources empty;
    empty.settings = []() { return Ui::Backend::Settings(); };
    return empty;
  }();
  return _the ? _the->sources() : none;
}

const Ui::Backend::Host &gtkHost()
{
  static const Ui::Backend::Host none;
  return _the ? _the->host() : none;
}

// made once
namespace {
  struct offeringGtk {
    offeringGtk()
    {
      Ui::offer("gtk", []() -> Ui::Backend * {
        if(!_the) _the = new backendGtk();
        return _the;
      });
    }
  };
  offeringGtk _offeringGtk;
} // namespace
