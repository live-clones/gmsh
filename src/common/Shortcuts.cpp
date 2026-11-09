// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <functional>
#include <map>
#include <cstring>
#include "GmshConfig.h"
#include "Shortcuts.h"
#include "Context.h"
#include "GmshMessage.h"
#include "Options.h"
#include "OpenFile.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

std::string Shortcut::label(const std::string &command) const
{
  if(key == KeyNone) return "";
  std::string s;
  if(mods & ModAlt) s += "Alt+";
  if(mods & ModShift) s += "Shift+";
  if(mods & ModCommand) {
    if(command.size())
      s += command;
    else
#if defined(__APPLE__)
      s += "Cmd+";
#else
      s += "Ctrl+";
#endif
  }
  if(key >= KeyF1 && key < KeyF1 + 12)
    s += "F" + std::to_string(key - KeyF1 + 1);
  else if(key == KeyEscape)
    s += "Escape";
  else if(key == KeyLeft)
    s += "Left arrow";
  else if(key == KeyRight)
    s += "Right arrow";
  else if(key == KeyUp)
    s += "Up arrow";
  else if(key == KeyDown)
    s += "Down arrow";
  else if(key == KeyPageUp)
    s += "Page up";
  else if(key == KeyPageDown)
    s += "Page down";
  else
    s += (char)key;
  if(mods & AnyModifiers) s += " (with any modifier)";
  return s;
}

const std::vector<ShortcutEntry> &GetShortcuts()
{
  typedef ShortcutEntry E;
  static const std::vector<ShortcutEntry> table = {
    // the keys of the 3D view
    E("time_step_prev", {KeyLeft}, "Go to previous time step"),
    E("time_step_next", {KeyRight}, "Go to next time step"),
    E("view_prev", {KeyUp}, "Make previous view visible"),
    E("view_next", {KeyDown}, "Make next view visible"),
    E("Reload script", {'0'}, "Reload geometry"),
    E("project_reload", {'0', ModCommand}, "Reload full project"),
    E("project_reload", {'9'}, "Reload full project"), // for Bruno
    E("Mesh 1D", {'1'}, "Mesh lines"),
    E("Mesh 1D", {KeyF1}, "Mesh lines"),
    E("Mesh 2D", {'2'}, "Mesh surfaces"),
    E("Mesh 2D", {KeyF1 + 1}, "Mesh surfaces"),
    E("Mesh 3D", {'3'}, "Mesh volumes"),
    E("Mesh 3D", {KeyF1 + 2}, "Mesh volumes"),
    // (before Escape, which takes any modifier)
    E("mouse_selection", {KeyEscape, ModShift},
      "Toggle mouse selection on/off (a selection under way goes on)"),
    E("escape", {KeyEscape, AnyModifiers},
      "Stop the selection under way (query, measurement, operation on the "
      "entities picked...), cancel a lasso, or leave full screen"),
    E("selection_end", {'e'},
      "End the selection under way (accept what is "
      "picked)",
      true),
    E("module_geometry", {'g'}, "Go to geometry module"),
    E("module_mesh", {'m'}, "Go to mesh module"),
    E("module_post", {'p'}, "Go to post-processing module"),
    E("selection_quit", {'q'}, "Stop the selection under way, as Escape", true),
    E("module_solver", {'s'}, "Go to solver module"),
    E("selection_undo", {'u'}, "Undo the last pick of the selection under way",
      true),
    E("watch", {'w'}, "Merge the files matching the watch pattern"),
    E("freeze_x", {'x'},
      "Toggle x coordinate freeze in geometry creation mode"),
    E("freeze_y", {'y'},
      "Toggle y coordinate freeze in geometry creation mode"),
    E("freeze_z", {'z'},
      "Toggle z coordinate freeze in geometry creation mode"),
    E("window_front", {'a', ModShift}, "Bring all windows to front"),
    E("Geometry options", {'g', ModShift}, "Show geometry options"),
    E("Mesh options", {'m', ModShift}, "Show mesh options"),
    E("General options", {'o', ModShift}, "Show general options"),
    E("options_post", {'p', ModShift}, "Show post-processing options"),
    E("options_solver", {'s', ModShift}, "Show solver options"),
    E("plugins_view", {'u', ModShift}, "Show post-processing view plugins"),
    E("All view options", {'w', ModShift}, "Show post-processing view options"),
    E("freeze_but_x", {'x', ModShift},
      "Move only along x coordinate in geometry creation mode"),
    E("freeze_but_y", {'y', ModShift},
      "Move only along y coordinate in geometry creation mode"),
    E("freeze_but_z", {'z', ModShift},
      "Move only along z coordinate in geometry creation mode"),
#if defined(WIN32)
    E("window_copy", {'c', ModCommand}, "Copy graphic window to clipboard"),
#endif
    // the menus
    E("dock", {'d', ModCommand}, "Dock/undock current tool window"),
    E("dock_all", {'d', ModCommand | ModShift}, "Dock/undock all tool windows"),
    E("file_export", {'e', ModCommand}, "Export project"),
    E("Full screen", {'f', ModCommand}, "Enter full screen"),
    E("help_keys", {'h', ModCommand}, "Show keyboard and mouse usage", false,
      true),
    E("statistics", {'i', ModCommand}, "Show statistics window"),
    E("options_save", {'j', ModCommand}, "Save model options"),
    E("console", {'l', ModCommand}, "Show message console"),
    E("minimize", {'m', ModCommand}, "Minimize window"),
    E("file_new", {'n', ModCommand}, "Create new project file"),
    E("file_open", {'o', ModCommand}, "Open project file"),
    E("quit", {'q', ModCommand}, "Quit"),
    E("file_rename", {'r', ModCommand}, "Rename project file"),
    E("Save mesh", {'s', ModCommand}, "Save mesh in default format"),
    E("solver_run", {'t', ModCommand}, "Run solver"),
    E("clipping", {'c', ModShift | ModCommand}, "Show clipping plane window"),
    E("help_options", {'h', ModShift | ModCommand},
      "Show current options and workspace window"),
    E("options_save_default", {'j', ModShift | ModCommand},
      "Save options as default"),
    E("manipulator", {'m', ModShift | ModCommand}, "Show manipulator window"),
    E("options", {'n', ModShift | ModCommand}, "Show option window"),
    E("file_merge", {'o', ModShift | ModCommand}, "Merge file(s)"),
    E("file_recent", {'r', ModShift | ModCommand},
      "Open next-to-last opened file"),
    E("plugins", {'u', ModShift | ModCommand}, "Show plugin window"),
    E("visibility", {'v', ModShift | ModCommand}, "Show visibility window"),
    // the display, as in the quick access menu of the status bar
    E("axes_loop", {'a', ModAlt}, "Loop through axes modes"),
    E("bounding_boxes", {'b', ModAlt}, "Hide/show bounding boxes"),
    E("color_scheme", {'c', ModAlt}, "Loop through predefined color schemes"),
    E("surface_type", {'d', ModAlt},
      "Loop through geometry surface display modes"),
    E("view_elements", {'e', ModAlt},
      "Hide/Show element outlines for visible post-pro views"),
    E("fast_redraw", {'f', ModAlt}, "Change redraw mode (fast/full)"),
    E("views_hide_show", {'h', ModAlt}, "Hide/show all post-processing views"),
    E("view_scales", {'i', ModAlt},
      "Hide/show all post-processing view scales"),
    E("geometry_curves", {'l', ModAlt}, "Hide/show geometry lines"),
    E("Toggle mesh display", {'m', ModAlt},
      "Toggle visibility of all mesh entities"),
    E("view_annotations", {'n', ModAlt},
      "Hide/show all post-processing view annotations"),
    E("projection", {'o', ModAlt},
      "Change projection mode (orthographic/perspective)"),
    E("geometry_points", {'p', ModAlt}, "Hide/show geometry points"),
    E("view_range", {'r', ModAlt},
      "Loop through range modes for visible post-pro views"),
    E("geometry_surfaces", {'s', ModAlt}, "Hide/show geometry surfaces"),
    E("view_intervals", {'t', ModAlt},
      "Loop through interval modes for visible post-pro views"),
    E("geometry_volumes", {'v', ModAlt}, "Hide/show geometry volumes"),
    E("lighting", {'w', ModAlt}, "Enable/disable all lighting"),
    E("view_x", {'x', ModAlt}, "Set X view"),
    E("view_y", {'y', ModAlt}, "Set Y view"),
    E("view_z", {'z', ModAlt}, "Set Z view"),
    E("view_1_1", {'1', ModAlt}, "Fit the model in the window"),
    E("view_3d", {'3', ModAlt}, "Set isometric 3D view"),
    E("small_axes", {'a', ModAlt | ModShift}, "Hide/show small axes"),
    E("mesh_volume_faces", {'b', ModAlt | ModShift},
      "Hide/show mesh volume faces"),
    E("colormaps", {'c', ModAlt | ModShift},
      "Loop through predefined colormaps"),
    E("mesh_surface_faces", {'d', ModAlt | ModShift},
      "Hide/show mesh surface faces"),
    E("view_elements", {'e', ModAlt | ModShift},
      "Hide/Show element outlines for visible post-pro views"),
    E("mesh_lines", {'l', ModAlt | ModShift}, "Hide/show mesh lines"),
    E("mesh_nodes", {'p', ModAlt | ModShift}, "Hide/show mesh nodes"),
    E("mesh_surface_edges", {'s', ModAlt | ModShift},
      "Hide/show mesh surface edges"),
    E("view_intervals_all", {'t', ModAlt | ModShift},
      "Same as Alt+t, but with numeric mode included"),
    E("mesh_volume_edges", {'v', ModAlt | ModShift},
      "Hide/show mesh volume edges"),
    E("view_x", {'x', ModAlt | ModShift}, "Set -X view"),
    E("view_y", {'y', ModAlt | ModShift}, "Set -Y view"),
    E("view_z", {'z', ModAlt | ModShift}, "Set -Z view"),
    E("view_3d", {'3', ModAlt | ModShift},
      "Set isometric 3D view from the opposite side"),
    E("view_1_1", {'1', ModAlt | ModShift},
      "Reset bounding box around visible entities"),
    E("view_1_1", {'1', ModAlt | ModCommand}, "Sync scale between viewports"),
    E("menu_show_hide", {'t', ModAlt | ModCommand}, "Show/hide menu"),
#if defined(HAVE_POPPLER)
    E("page_prev", {'u'}, "Go to previous PDF page"),
    E("page_prev", {KeyPageUp}, "Go to previous PDF page"),
    E("page_next", {'d'}, "Go to next PDF page"),
    E("page_next", {KeyPageDown}, "Go to next PDF page"),
#endif
  };
  return table;
}

std::vector<Shortcut> GetShortcutsOf(const std::string &action)
{
  std::vector<Shortcut> s;
  for(const ShortcutEntry &e : GetShortcuts())
    if(action == e.action) s.push_back(e.shortcut);
  return s;
}

std::vector<std::pair<std::string, std::string> >
GetShortcutsUsage(const std::string &command)
{
  std::vector<std::pair<std::string, std::string> > s;
  const std::vector<ShortcutEntry> &table = GetShortcuts();
  for(std::size_t i = 0; i < table.size(); i++) {
    const ShortcutEntry &e = table[i];
#if defined(__APPLE__)
    // the list of this interface, with the system menu bar
    if(command.empty() && e.inWindowBarOnly && CTX::instance()->systemMenuBar)
      continue;
#endif
    // keys that do the same, documented alike, on one line
    if(i && s.size() && !strcmp(table[i - 1].action, e.action) &&
       !strcmp(table[i - 1].help, e.help)) {
      s.back().first += " or " + e.shortcut.label(command);
      continue;
    }
    s.push_back(std::make_pair(e.shortcut.label(command), std::string(e.help)));
  }
  return s;
}

// whether to turn a display option of the geometry or the mesh on or off
static void toggle(double (*option)(int, int, double))
{ option(0, GMSH_SET | GMSH_GUI, !option(0, GMSH_GET, 0)); }

#if defined(HAVE_POST)
// an option of every visible view, from what it is
static void forVisibleViews(double (*option)(int, int, double),
                            double (*next)(double))
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(opt_view_visible(i, GMSH_GET, 0))
      option(i, GMSH_SET | GMSH_GUI, next(option(i, GMSH_GET, 0)));
}
#endif

// what each action that only changes the scene does: false if it cannot be
// done here (the point of view without a context)
typedef std::function<bool(unsigned mods, drawContext *ctx)> sceneAction;

static const std::map<std::string, sceneAction> &sceneActions()
{
  static const std::map<std::string, sceneAction> actions = [] {
    std::map<std::string, sceneAction> m;
    auto add = [&m](const char *name, void (*f)()) {
      m[name] = [f](unsigned, drawContext *) {
        f();
        return true;
      };
    };

    // --- the display: the actions that toggle one option
    static const std::pair<const char *, double (*)(int, int, double)>
      toggles[] = {{"geometry_points", opt_geometry_points},
                   {"geometry_curves", opt_geometry_curves},
                   {"geometry_surfaces", opt_geometry_surfaces},
                   {"geometry_volumes", opt_geometry_volumes},
                   {"mesh_nodes", opt_mesh_nodes},
                   {"mesh_lines", opt_mesh_lines},
                   {"mesh_surface_edges", opt_mesh_surface_edges},
                   {"mesh_surface_faces", opt_mesh_surface_faces},
                   {"mesh_volume_edges", opt_mesh_volume_edges},
                   {"mesh_volume_faces", opt_mesh_volume_faces},
                   {"fast_redraw", opt_general_fast_redraw},
                   {"bounding_boxes", opt_general_draw_bounding_box},
                   {"small_axes", opt_general_small_axes},
                   {"projection", opt_general_orthographic}};
    for(const auto &t : toggles) {
      auto option = t.second;
      m[t.first] = [option](unsigned, drawContext *) {
        toggle(option);
        return true;
      };
    }
    add("Toggle mesh display", [] {
      // all of the mesh off if any of it is drawn (as the options say now,
      // whatever changed them), else back as it was when turned off (the
      // default edges if it never was)
      static double (*const options[])(int, int, double) = {
        opt_mesh_nodes,         opt_mesh_lines,        opt_mesh_surface_edges,
        opt_mesh_surface_faces, opt_mesh_volume_edges, opt_mesh_volume_faces};
      static int old[6] = {0, 0, 1, 0, 1, 0};
      bool drawn = false;
      for(int i = 0; i < 6; i++)
        if(options[i](0, GMSH_GET, 0)) drawn = true;
      for(int i = 0; i < 6; i++) {
        if(drawn) old[i] = (int)options[i](0, GMSH_GET, 0);
        options[i](0, GMSH_SET | GMSH_GUI, drawn ? 0 : old[i]);
      }
      Msg::StatusBar(false,
                     drawn ? "Mesh display OFF" : "Mesh display restored");
    });
    add("color_scheme", [] {
      opt_general_color_scheme(0, GMSH_SET | GMSH_GUI,
                               opt_general_color_scheme(0, GMSH_GET, 0) + 1);
    });
    add("lighting", [] {
      toggle(opt_geometry_light);
      toggle(opt_mesh_light);
#if defined(HAVE_POST)
      forVisibleViews(opt_view_light, [](double v) { return (double)!v; });
#endif
    });
    add("axes_loop", [] {
      opt_general_axes(0, GMSH_SET | GMSH_GUI,
                       opt_general_axes(0, GMSH_GET, 0) + 1);
#if defined(HAVE_POST)
      // through the six modes: a view left on automatic starts over at none
      forVisibleViews(opt_view_axes,
                      [](double v) { return (v >= 5) ? 0. : v + 1.; });
#endif
    });
    add("surface_type", [] {
      opt_geometry_surface_type(0, GMSH_SET | GMSH_GUI,
                                opt_geometry_surface_type(0, GMSH_GET, 0) + 1);
    });

#if defined(HAVE_POST)
    // --- the views
    add("view_scales", [] {
      forVisibleViews(opt_view_show_scale, [](double v) { return (double)!v; });
    });
    add("colormaps", [] {
      forVisibleViews(opt_view_colormap_number,
                      [](double v) { return v + 1.; });
    });
    add("view_intervals", [] {
      // skipping the numeric display
      forVisibleViews(opt_view_intervals_type,
                      [](double v) { return (v + 1 == 4) ? 1. : v + 1.; });
    });
    add("view_intervals_all", [] {
      forVisibleViews(opt_view_intervals_type, [](double v) { return v + 1.; });
    });
    add("view_range", [] {
      forVisibleViews(opt_view_range_type, [](double v) { return v + 1.; });
    });
    add("view_annotations", [] {
      forVisibleViews(opt_view_draw_strings,
                      [](double v) { return (double)!v; });
    });
    add("view_elements", [] {
      forVisibleViews(opt_view_show_element,
                      [](double v) { return (double)!v; });
    });
    add("views_hide_show", [] {
      // all hidden if any is shown, else all shown
      bool shown = false;
      for(std::size_t i = 0; i < PView::list.size(); i++)
        if(opt_view_visible(i, GMSH_GET, 0)) shown = true;
      for(std::size_t i = 0; i < PView::list.size(); i++)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, !shown);
    });
    // --- the time steps and the views, on the arrows
    add("time_step_prev",
        [] { PView::animate(true, -CTX::instance()->post.animStep); });
    add("time_step_next",
        [] { PView::animate(true, CTX::instance()->post.animStep); });
    add("view_prev",
        [] { PView::animate(false, -CTX::instance()->post.animStep); });
    add("view_next",
        [] { PView::animate(false, CTX::instance()->post.animStep); });
#endif

#if defined(HAVE_OPENGL)
    // --- the point of view (Shift for the other side, or with "1:1" for the
    // bounding box of what is visible)
    for(const char *a : {"view_x", "view_y", "view_z", "view_3d", "view_1_1"}) {
      std::string which = strcmp(a, "view_1_1") ? std::string(a + 5) : "1:1";
      m[a] = [which](unsigned mods, drawContext *ctx) {
        if(!ctx) return false;
        if(which == "1:1" && (mods & ModShift)) SetBoundingBox(true);
        ctx->standardView(which, mods & ModShift);
        return true;
      };
    }
#endif
    return m;
  }();
  return actions;
}

bool IsSceneShortcut(const std::string &a)
{ return sceneActions().count(a) > 0; }

int RunSceneShortcut(const std::string &a, unsigned mods, drawContext *ctx)
{
  auto it = sceneActions().find(a);
  return (it != sceneActions().end() && it->second(mods, ctx)) ? 2 : 0;
}
