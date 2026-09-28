// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GTK)

#include <cstdio>
#include <set>
#include <string>
#include <vector>

#include "gtkCommon.h"
#include "Tree.h"

// The tree as expanders inside expanders: a branch is filled the first time
// it is opened, so that what is asked of the description is what is shown.
// A node is its path, which is what survives a rebuild.

struct gtkTree::line {
  gtkTree *tree = nullptr;
  std::string path;
  int depth = 0;
  // a branch, and the box of its children, filled when first opened
  GtkWidget *expander = nullptr, *children = nullptr;
  bool filled = false;
  GtkWidget *row = nullptr;
  GtkWidget *field = nullptr;
  GtkWidget *pick = nullptr;
  bool quiet = false;
};

namespace {

  // a background of its own for a line the description colours: one class a
  // colour, all in one sheet
  std::string _highlightClass(const Ui::Colour &c)
  {
    static GtkCssProvider *sheet = nullptr;
    static std::set<std::string> made;
    static std::string css;
    char name[32];
    snprintf(name, sizeof(name), "gmsh-hl-%02x%02x%02x", c.r, c.g, c.b);
    if(made.insert(name).second) {
      char rule[96];
      snprintf(rule, sizeof(rule),
               ".%s{background-color:rgba(%d,%d,%d,%.2f);border-radius:3px}\n",
               name, c.r, c.g, c.b, c.a / 255.);
      css += rule;
      if(!sheet) {
        sheet = gtk_css_provider_new();
        gtk_style_context_add_provider_for_display(
          gdk_display_get_default(), GTK_STYLE_PROVIDER(sheet),
          GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
      }
      gtk_css_provider_load_from_string(sheet, css.c_str());
    }
    return name;
  }

  std::string _labelOf(const Ui::Node &node, const std::string &path)
  {
    if(node.label.size()) return node.label;
    std::size_t slash = path.find_last_of('/');
    return slash == std::string::npos ? path : path.substr(slash + 1);
  }

  struct lineAction {
    std::function<void()> what, after;
  };

  void _pressed(GtkButton *, gpointer data)
  {
    lineAction *a = (lineAction *)data;
    std::function<void()> what = a->what, after = a->after;
    gtkLater([what, after]() {
      if(what) what();
      if(after) after();
    });
  }

  void _dropAction(gpointer data) { delete (lineAction *)data; }

  void _picked(GtkCheckButton *c, gpointer data)
  {
    gtkTree::line *l = (gtkTree::line *)data;
    if(l->quiet) return;
    // the node asked now: the one the line was made from may be stale
    Ui::Node node = l->tree->nodeOf(l->path);
    if(node.pick) node.pick(gtk_check_button_get_active(c));
    l->tree->after();
  }

  struct menuOf {
    std::function<std::vector<Ui::MenuItem>()> menu;
  };

  void _dropMenu(gpointer data) { delete (menuOf *)data; }

  void _secondClick(GtkGestureClick *g, int, double x, double y, gpointer data)
  {
    menuOf *m = (menuOf *)data;
    if(!m->menu) return;
    GtkWidget *w = gtk_event_controller_get_widget(GTK_EVENT_CONTROLLER(g));
    gtkPopupMenu(m->menu(), w, x, y);
  }

} // namespace

gtkTree::gtkTree(const Ui::Tree &tree, bool picks,
                 const std::function<void()> &after)
  : _tree(tree), _picks(picks), _after(after), _built(0), _everBuilt(false),
    _firstBuild(true)
{
  _scroll = gtk_scrolled_window_new();
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(_scroll),
                                 GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_widget_set_vexpand(_scroll, TRUE);
  _box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_margin_start(_box, 4);
  gtk_widget_set_margin_end(_box, 4);
  gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(_scroll), _box);
  // the lines point at their tree: the tree goes before the widgets do
  g_object_ref(_scroll);
  refresh(true);
}

gtkTree::~gtkTree()
{
  for(line *l : _lines) delete l;
  _lines.clear();
  g_object_unref(_scroll);
}

void gtkTree::_expanded(GObject *expander, GParamSpec *, gpointer data)
{
  line *l = (line *)data;
  if(l->quiet) return;
  gtkTree *t = l->tree;
  bool open = gtk_expander_get_expanded(GTK_EXPANDER(expander));
  if(open && !l->filled) {
    l->filled = true;
    t->_branch(l->children, l->path, l->depth + 1);
  }
  if(t->_tree.setClosed) t->_tree.setClosed(l->path, !open);
}

gtkTree::line *gtkTree::_find(const std::string &path) const
{
  for(line *l : _lines)
    if(l->path == path) return l;
  return nullptr;
}

void gtkTree::_branch(GtkWidget *into, const std::string &parent, int depth)
{
  if(!_tree.children || !_tree.node) return;
  bool commands = gtkSources().settings().showModuleMenu;
  for(const std::string &path : _tree.children(parent)) {
    if(parent.empty() && path == "0Modules" && !commands && !_picks) continue;
    Ui::Node node = _tree.node(path);
    line *l = new line;
    l->tree = this;
    l->path = path;
    l->depth = depth;
    _lines.push_back(l);
    std::string label = _labelOf(node, path);
    bool branch = !_tree.children(path).empty();
    GtkWidget *row = nullptr;
    if(branch) {
      GtkWidget *e = gtk_expander_new(label.c_str());
      if(_picks && node.pick) {
        l->pick = gtk_check_button_new_with_label(label.c_str());
        g_signal_connect(l->pick, "toggled", G_CALLBACK(_picked), l);
        gtk_expander_set_label_widget(GTK_EXPANDER(e), l->pick);
      }
      l->children = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
      gtk_widget_set_margin_start(l->children, gtkPx(1.));
      gtk_expander_set_child(GTK_EXPANDER(e), l->children);
      l->expander = e;
      // as the FLTK tree has it: the modules folded under their root -- a
      // branch is made when first opened, so always -- the rest open unless
      // the description folds it; the tree of a field folded
      bool open = !node.closed && !(_tree.closed && _tree.closed(path)) &&
                  !_picks &&
                  path.compare(0, 9, "0Modules/") != 0;
      for(auto it = _wanted.begin(); it != _wanted.end(); ++it)
        if(it->first == path) {
          open = it->second;
          _wanted.erase(it);
          break;
        }
      if(open) {
        l->filled = true;
        _branch(l->children, path, depth + 1);
        l->quiet = true;
        gtk_expander_set_expanded(GTK_EXPANDER(e), TRUE);
        l->quiet = false;
      }
      g_signal_connect(e, "notify::expanded", G_CALLBACK(_expanded), l);
      row = e;
    }
    else {
      row = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, gtkPx(.45));
      // the arrow of a branch takes room: a leaf starts where its label would
      gtk_widget_set_margin_start(row, gtkPx(1.2));
      if(_picks) {
        l->pick = gtk_check_button_new_with_label(label.c_str());
        g_signal_connect(l->pick, "toggled", G_CALLBACK(_picked), l);
        gtk_box_append(GTK_BOX(row), l->pick);
      }
      else {
        if(node.hasField) {
          std::function<void()> after = _after;
          l->field = gtkFieldWidget(node.field, after);
          if(l->field) {
            if(node.field.kind != Ui::Check && node.field.kind != Ui::Action)
              gtk_widget_set_size_request(l->field, gtkPx(8.), -1);
            gtk_box_append(GTK_BOX(row), l->field);
          }
        }
        if(!node.hasField || node.label.size()) {
          GtkWidget *name;
          if(node.pressed) {
            name = gtk_button_new_with_label(label.c_str());
            gtk_widget_add_css_class(name, "flat");
            gtk_widget_set_halign(gtk_button_get_child(GTK_BUTTON(name)),
                                  GTK_ALIGN_START);
            g_object_set_data_full(G_OBJECT(name), "gmsh-action",
                                   new lineAction{node.pressed, _after},
                                   _dropAction);
            g_signal_connect(name, "clicked", G_CALLBACK(_pressed),
                             g_object_get_data(G_OBJECT(name), "gmsh-action"));
          }
          else {
            name = gtk_label_new(label.c_str());
            gtk_label_set_xalign(GTK_LABEL(name), 0.f);
          }
          gtk_widget_set_hexpand(name, TRUE);
          gtk_box_append(GTK_BOX(row), name);
        }
      }
    }
    if(node.tooltip.size() && gtkSources().settings().tooltips)
      gtk_widget_set_tooltip_text(row, node.tooltip.c_str());
    if(node.highlight.a)
      gtk_widget_add_css_class(row, _highlightClass(node.highlight).c_str());
    if(node.menu) {
      GtkGesture *second = gtk_gesture_click_new();
      gtk_gesture_single_set_button(GTK_GESTURE_SINGLE(second),
                                    GDK_BUTTON_SECONDARY);
      menuOf *m = new menuOf{node.menu};
      g_object_set_data_full(G_OBJECT(second), "gmsh-menu", m, _dropMenu);
      g_signal_connect(second, "pressed", G_CALLBACK(_secondClick), m);
      gtk_widget_add_controller(row, GTK_EVENT_CONTROLLER(second));
    }
    l->row = row;
    gtk_box_append(GTK_BOX(into), row);
  }
}

void gtkTree::_build()
{
  // what was open stays open
  for(line *l : _lines)
    if(l->expander) {
      bool open = gtk_expander_get_expanded(GTK_EXPANDER(l->expander));
      bool asked = false;
      for(auto &w : _wanted)
        if(w.first == l->path) asked = true;
      if(!asked) _wanted.push_back(std::make_pair(l->path, open));
    }
  while(GtkWidget *c = gtk_widget_get_first_child(_box))
    gtk_box_remove(GTK_BOX(_box), c);
  for(line *l : _lines) delete l;
  _lines.clear();
  _branch(_box, "", 0);
  _firstBuild = false;
  // what was asked of a branch that is not there any more is forgotten
  _wanted.clear();
}

void gtkTree::refresh(bool rebuild)
{
  unsigned generation = _tree.generation ? _tree.generation() : 0;
  if(rebuild || !_everBuilt || generation != _built) {
    _everBuilt = true;
    _built = generation;
    _build();
  }
  if(!_tree.node) return;
  for(line *l : _lines) {
    // a line under a folded branch is still there, and still up to date
    Ui::Node node = _tree.node(l->path);
    if(l->field) {
      gtkRebindField(l->field, node.field);
      gtkRefreshField(l->field);
    }
    if(l->pick) {
      l->quiet = true;
      gtk_check_button_set_active(GTK_CHECK_BUTTON(l->pick),
                                  node.picked && node.picked());
      l->quiet = false;
    }
    if(l->row) gtk_widget_set_sensitive(l->row, node.enabled ? node.enabled() :
                                                               TRUE);
  }
}

void gtkTree::open(const std::string &path, bool open)
{
  // the branches on the way are opened first, which fills them
  if(open) {
    std::size_t at = 0;
    while((at = path.find('/', at + 1)) != std::string::npos) {
      line *up = _find(path.substr(0, at));
      if(up && up->expander)
        gtk_expander_set_expanded(GTK_EXPANDER(up->expander), TRUE);
    }
  }
  line *l = _find(path);
  if(l && l->expander) {
    gtk_expander_set_expanded(GTK_EXPANDER(l->expander), open);
    return;
  }
  for(auto &w : _wanted)
    if(w.first == path) {
      w.second = open;
      return;
    }
  _wanted.push_back(std::make_pair(path, open));
}

bool gtkTree::isOpen(const std::string &path) const
{
  line *l = _find(path);
  if(l && l->expander) return gtk_expander_get_expanded(GTK_EXPANDER(l->expander));
  for(auto &w : _wanted)
    if(w.first == path) return w.second;
  return false;
}

#endif
