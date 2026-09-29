// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <cctype>
#include <string>
#include <vector>

#include "gtkCommon.h"

// The menus are GMenu models with an action per entry: "gm.i12" for the bar,
// whose actions live on the main window, "pm.i3" for a menu that pops up,
// whose actions live on the popover. The shortcut is only shown: the keys are
// read by the main window, off Sources::keys, like the other interfaces.

// --- what runs once the event is over

namespace {

  gboolean _runLater(gpointer data)
  {
    std::function<void()> *what = (std::function<void()> *)data;
    if(*what) (*what)();
    return G_SOURCE_REMOVE;
  }

  void _dropLater(gpointer data) { delete (std::function<void()> *)data; }

  int _buttonsDown = 0;

  gboolean _buttonEvent(GtkEventControllerLegacy *, GdkEvent *event, gpointer)
  {
    GdkEventType type = gdk_event_get_event_type(event);
    if(type == GDK_BUTTON_PRESS)
      _buttonsDown++;
    else if(type == GDK_BUTTON_RELEASE && _buttonsDown > 0)
      _buttonsDown--;
    return FALSE;
  }

} // namespace

void gtkLater(const std::function<void()> &what)
{
  // after the redraws, so that the menu that asked has gone
  g_idle_add_full(G_PRIORITY_DEFAULT_IDLE, _runLater,
                  new std::function<void()>(what), _dropLater);
}

bool gtkButtonDown() { return _buttonsDown > 0; }

void gtkWatchButtons(GtkWidget *window)
{
  GtkEventController *c = gtk_event_controller_legacy_new();
  gtk_event_controller_set_propagation_phase(c, GTK_PHASE_CAPTURE);
  g_signal_connect(c, "event", G_CALLBACK(_buttonEvent), nullptr);
  gtk_widget_add_controller(window, c);
}

// --- keys

bool gtkUiKey(guint keyval, GdkModifierType state, int &key, unsigned &mods)
{
  mods = 0;
  if(state & (GDK_CONTROL_MASK | GDK_META_MASK | GDK_SUPER_MASK))
    mods |= Ui::ModCommand;
  if(state & GDK_SHIFT_MASK) mods |= Ui::ModShift;
  if(state & GDK_ALT_MASK) mods |= Ui::ModAlt;
  key = 0;
  if(keyval >= GDK_KEY_F1 && keyval <= GDK_KEY_F12)
    key = Ui::KeyF1 + (int)(keyval - GDK_KEY_F1);
  else {
    switch(keyval) {
    case GDK_KEY_Left:
    case GDK_KEY_KP_Left: key = Ui::KeyLeft; break;
    case GDK_KEY_Right:
    case GDK_KEY_KP_Right: key = Ui::KeyRight; break;
    case GDK_KEY_Up:
    case GDK_KEY_KP_Up: key = Ui::KeyUp; break;
    case GDK_KEY_Down:
    case GDK_KEY_KP_Down: key = Ui::KeyDown; break;
    case GDK_KEY_Escape: key = Ui::KeyEscape; break;
    case GDK_KEY_Home:
    case GDK_KEY_KP_Home: key = Ui::KeyHome; break;
    case GDK_KEY_Page_Up:
    case GDK_KEY_KP_Page_Up: key = Ui::KeyPageUp; break;
    case GDK_KEY_Page_Down:
    case GDK_KEY_KP_Page_Down: key = Ui::KeyPageDown; break;
    case GDK_KEY_Delete:
    case GDK_KEY_KP_Delete:
    case GDK_KEY_BackSpace: key = Ui::KeyDelete; break;
    default: break;
    }
  }
  if(key) return true;
  guint upper = gdk_keyval_to_upper(keyval);
  if(upper >= GDK_KEY_A && upper <= GDK_KEY_Z) {
    key = 'A' + (int)(upper - GDK_KEY_A);
    return true;
  }
  // a digit or a mark is the one typed, whatever key gives it on this
  // keyboard (Shift, on a French one)
  gunichar c = gdk_keyval_to_unicode(keyval);
  if(c > ' ' && c < 127) {
    key = (int)c;
    mods &= ~Ui::ModShift;
    return true;
  }
  return false;
}

// --- building a menu

namespace {

  // what the entries of one menu do, by their number in the action names
  struct menuActions {
    std::vector<Ui::MenuItem> items;
  };

  void _dropActions(gpointer data) { delete (menuActions *)data; }

  // GTK reads "_" as the mark of the letter that opens the entry
  std::string _label(const std::string &label, char mnemonic)
  {
    std::string out;
    bool marked = false;
    for(char c : label) {
      if(c == '_') {
        out += "__";
        continue;
      }
      if(!marked && mnemonic &&
         std::tolower((unsigned char)c) == std::tolower((unsigned char)mnemonic)) {
        out += '_';
        marked = true;
      }
      out += c;
    }
    return out;
  }

  // as GTK writes an accelerator, "<Control><Shift>o"; empty when it has no
  // such name
  std::string _accel(const Ui::Shortcut &s)
  {
    if(s.empty() || (s.mods & Ui::ModAny)) return "";
    std::string a;
    if(s.mods & Ui::ModCommand) {
#if defined(__APPLE__)
      a += "<Meta>";
#else
      a += "<Control>";
#endif
    }
    if(s.mods & Ui::ModShift) a += "<Shift>";
    if(s.mods & Ui::ModAlt) a += "<Alt>";
    int k = s.key;
    if(k >= Ui::KeyF1 && k < Ui::KeyF1 + 12)
      a += "F" + std::to_string(k - Ui::KeyF1 + 1);
    else if(k == Ui::KeyDelete)
      a += "Delete";
    else if(k == Ui::KeyLeft)
      a += "Left";
    else if(k == Ui::KeyRight)
      a += "Right";
    else if(k == Ui::KeyUp)
      a += "Up";
    else if(k == Ui::KeyDown)
      a += "Down";
    else if(k == Ui::KeyEscape)
      a += "Escape";
    else if(k == Ui::KeyHome)
      a += "Home";
    else if(k == Ui::KeyPageUp)
      a += "Page_Up";
    else if(k == Ui::KeyPageDown)
      a += "Page_Down";
    else if(k >= 'A' && k <= 'Z')
      a += (char)(k - 'A' + 'a');
    else if(k > ' ' && k < 127) {
      const char *name = gdk_keyval_name(gdk_unicode_to_keyval((guint32)k));
      if(!name) return "";
      a += name;
    }
    else
      return "";
    guint key = 0;
    GdkModifierType mods = (GdkModifierType)0;
    if(!gtk_accelerator_parse(a.c_str(), &key, &mods)) return "";
    return a;
  }

  void _activated(GSimpleAction *action, GVariant *, gpointer data)
  {
    menuActions *acts = (menuActions *)data;
    int index =
      GPOINTER_TO_INT(g_object_get_data(G_OBJECT(action), "gmsh-index"));
    if(index < 0 || index >= (int)acts->items.size()) return;
    // a copy: the menu may be built again before it runs
    std::function<void()> what = acts->items[(std::size_t)index].action;
    gtkLater([what]() {
      if(what) what();
      gtkRefreshMenuBar();
    });
  }

  void _fill(GMenu *menu, const std::vector<Ui::MenuItem> &items,
             menuActions *acts, GActionMap *map, const char *prefix, bool bar)
  {
    GMenu *section = bar ? menu : g_menu_new();
    for(const auto &it : items) {
      std::string label = _label(it.label, it.mnemonic);
      if(it.kind == Ui::MenuItem::Submenu) {
        GMenu *sub = g_menu_new();
        bool enabled = it.enabled ? it.enabled() : true;
        if(enabled)
          _fill(sub, it.children, acts, map, prefix, false);
        GMenuItem *mi = g_menu_item_new_submenu(label.c_str(), G_MENU_MODEL(sub));
        g_menu_append_item(section, mi);
        g_object_unref(mi);
        g_object_unref(sub);
      }
      else {
        int n = (int)acts->items.size();
        acts->items.push_back(it);
        std::string name = "i" + std::to_string(n);
        GSimpleAction *a;
        if(it.kind == Ui::MenuItem::Toggle)
          a = g_simple_action_new_stateful(
            name.c_str(), nullptr,
            g_variant_new_boolean(it.checked && it.checked()));
        else
          a = g_simple_action_new(name.c_str(), nullptr);
        g_simple_action_set_enabled(a, it.enabled ? it.enabled() : TRUE);
        g_object_set_data(G_OBJECT(a), "gmsh-index", GINT_TO_POINTER(n));
        g_signal_connect(a, "activate", G_CALLBACK(_activated), acts);
        g_action_map_add_action(map, G_ACTION(a));
        g_object_unref(a);
        std::string full = std::string(prefix) + "." + name;
        GMenuItem *mi = g_menu_item_new(label.c_str(), full.c_str());
        std::string accel = _accel(it.shortcut);
        if(accel.size())
          g_menu_item_set_attribute(mi, "accel", "s", accel.c_str());
        g_menu_append_item(section, mi);
        g_object_unref(mi);
      }
      if(it.dividerAfter && !bar) {
        g_menu_append_section(menu, nullptr, G_MENU_MODEL(section));
        g_object_unref(section);
        section = g_menu_new();
      }
    }
    if(!bar) {
      if(g_menu_model_get_n_items(G_MENU_MODEL(section)))
        g_menu_append_section(menu, nullptr, G_MENU_MODEL(section));
      g_object_unref(section);
    }
  }

  // --- the bar

  GtkWidget *_bar = nullptr;
  GSimpleActionGroup *_barGroup = nullptr;
  menuActions *_barActions = nullptr;
  unsigned _barBuilt = 0;
  bool _barEver = false;

  void _barStates()
  {
    if(!_barActions || !_barGroup) return;
    for(std::size_t i = 0; i < _barActions->items.size(); i++) {
      const Ui::MenuItem &it = _barActions->items[i];
      std::string name = "i" + std::to_string(i);
      GAction *a =
        g_action_map_lookup_action(G_ACTION_MAP(_barGroup), name.c_str());
      if(!a) continue;
      bool enabled = it.enabled ? it.enabled() : true;
      if(g_action_get_enabled(a) != (gboolean)enabled)
        g_simple_action_set_enabled(G_SIMPLE_ACTION(a), enabled);
      if(it.kind == Ui::MenuItem::Toggle) {
        bool on = it.checked && it.checked();
        GVariant *was = g_action_get_state(a);
        bool wasOn = was && g_variant_get_boolean(was);
        if(was) g_variant_unref(was);
        if(wasOn != on)
          g_simple_action_set_state(G_SIMPLE_ACTION(a),
                                    g_variant_new_boolean(on));
      }
    }
  }

  // before the menu under the pointer drops: what is on and what is greyed as
  // it is now
  void _barPressed(GtkGestureClick *, int, double, double, gpointer)
  {
    gtkRefreshMenuBar();
  }

} // namespace

GtkWidget *gtkMenuBar(GtkWidget *window)
{
  if(_bar) return _bar;
  _barGroup = g_simple_action_group_new();
  gtk_widget_insert_action_group(window, "gm", G_ACTION_GROUP(_barGroup));
  _bar = gtk_popover_menu_bar_new_from_model(nullptr);
  GtkGesture *press = gtk_gesture_click_new();
  gtk_event_controller_set_propagation_phase(GTK_EVENT_CONTROLLER(press),
                                             GTK_PHASE_CAPTURE);
  g_signal_connect(press, "pressed", G_CALLBACK(_barPressed), nullptr);
  gtk_widget_add_controller(_bar, GTK_EVENT_CONTROLLER(press));
  gtkRefreshMenuBar();
  return _bar;
}

void gtkRefreshMenuBar()
{
  if(!_bar || !gtkSources().menuBar) return;
  unsigned generation =
    gtkSources().menuGeneration ? gtkSources().menuGeneration() : 0;
  if(_barEver && generation == _barBuilt) {
    _barStates();
    return;
  }
  _barEver = true;
  _barBuilt = generation;
  gchar **names = g_action_group_list_actions(G_ACTION_GROUP(_barGroup));
  for(gchar **n = names; n && *n; n++)
    g_action_map_remove_action(G_ACTION_MAP(_barGroup), *n);
  g_strfreev(names);
  // the actions of the entries made before are gone with them
  delete _barActions;
  _barActions = new menuActions;
  GMenu *model = g_menu_new();
  _fill(model, gtkSources().menuBar(), _barActions, G_ACTION_MAP(_barGroup),
        "gm", true);
  gtk_popover_menu_bar_set_menu_model(GTK_POPOVER_MENU_BAR(_bar),
                                      G_MENU_MODEL(model));
  g_object_unref(model);
}

// --- a menu that pops up

namespace {

  gboolean _unparent(gpointer data)
  {
    GtkWidget *pop = (GtkWidget *)data;
    if(gtk_widget_get_parent(pop)) gtk_widget_unparent(pop);
    g_object_unref(pop);
    return G_SOURCE_REMOVE;
  }

  // the entry picked is activated once the menu has closed: taken away later
  void _popupClosed(GtkPopover *pop, gpointer)
  {
    g_idle_add_full(G_PRIORITY_LOW, _unparent, pop, nullptr);
  }

} // namespace

void gtkPopupMenu(const std::vector<Ui::MenuItem> &items, GtkWidget *over,
                  double x, double y)
{
  if(items.empty() || !over) return;
  GSimpleActionGroup *group = g_simple_action_group_new();
  menuActions *acts = new menuActions;
  g_object_set_data_full(G_OBJECT(group), "gmsh-actions", acts, _dropActions);
  GMenu *model = g_menu_new();
  _fill(model, items, acts, G_ACTION_MAP(group), "pm", false);
  GtkWidget *pop = gtk_popover_menu_new_from_model_full(
    G_MENU_MODEL(model), GTK_POPOVER_MENU_NESTED);
  g_object_unref(model);
  gtk_widget_insert_action_group(pop, "pm", G_ACTION_GROUP(group));
  g_object_unref(group);
  g_object_ref(pop);
  gtk_widget_set_parent(pop, over);
  if(x >= 0.) {
    GdkRectangle at = {(int)x, (int)y, 1, 1};
    gtk_popover_set_pointing_to(GTK_POPOVER(pop), &at);
    gtk_popover_set_has_arrow(GTK_POPOVER(pop), FALSE);
    gtk_widget_set_halign(pop, GTK_ALIGN_START);
  }
  gtk_popover_set_position(GTK_POPOVER(pop), GTK_POS_BOTTOM);
  g_signal_connect(pop, "closed", G_CALLBACK(_popupClosed), nullptr);
  gtk_popover_popup(GTK_POPOVER(pop));
}
