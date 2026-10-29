// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cstring>
#include "GmshConfig.h"
#include "Shortcuts.h"
#include "Context.h"

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
    E("geometry_reload", {'0'}, "Reload geometry"),
    E("project_reload", {'0', ModCommand}, "Reload full project"),
    E("project_reload", {'9'}, "Reload full project"), // for Bruno
    E("mesh_1d", {'1'}, "Mesh lines"),
    E("mesh_1d", {KeyF1}, "Mesh lines"),
    E("mesh_2d", {'2'}, "Mesh surfaces"),
    E("mesh_2d", {KeyF1 + 1}, "Mesh surfaces"),
    E("mesh_3d", {'3'}, "Mesh volumes"),
    E("mesh_3d", {KeyF1 + 2}, "Mesh volumes"),
    E("escape", {KeyEscape, AnyModifiers},
      "Leave full screen, cancel a lasso, or toggle mouse selection on/off"),
    E("selection_end", {'e'}, "End/accept selection in geometry creation mode",
      true),
    E("module_geometry", {'g'}, "Go to geometry module"),
    E("selection_invert", {'i'}, "Invert selection in geometry creation mode",
      true),
    E("selection_invert", {'-'}, "Invert selection in geometry creation mode",
      true),
    E("module_mesh", {'m'}, "Go to mesh module"),
    E("module_post", {'p'}, "Go to post-processing module"),
    E("selection_quit", {'q'}, "Abort selection in geometry creation mode",
      true),
    E("module_solver", {'s'}, "Go to solver module"),
    E("selection_undo", {'u'}, "Undo last selection in geometry creation mode",
      true),
    E("watch", {'w'}, "Merge the files matching the watch pattern"),
    E("freeze_x", {'x'},
      "Toggle x coordinate freeze in geometry creation mode"),
    E("freeze_y", {'y'},
      "Toggle y coordinate freeze in geometry creation mode"),
    E("freeze_z", {'z'},
      "Toggle z coordinate freeze in geometry creation mode"),
    E("window_front", {'a', ModShift}, "Bring all windows to front"),
    E("options_geometry", {'g', ModShift}, "Show geometry options"),
    E("options_mesh", {'m', ModShift}, "Show mesh options"),
    E("options_general", {'o', ModShift}, "Show general options"),
    E("options_post", {'p', ModShift}, "Show post-processing options"),
    E("options_solver", {'s', ModShift}, "Show solver options"),
    E("plugins_view", {'u', ModShift}, "Show post-processing view plugins"),
    E("options_view", {'w', ModShift}, "Show post-processing view options"),
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
    E("fullscreen", {'f', ModCommand}, "Enter full screen"),
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
    E("mesh_save", {'s', ModCommand}, "Save mesh in default format"),
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
    E("mesh_toggle", {'m', ModAlt}, "Toggle visibility of all mesh entities"),
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
    E("view_1_1", {'1', ModAlt}, "Set 1:1 view"),
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
