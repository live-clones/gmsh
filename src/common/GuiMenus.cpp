// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The one description of the menus, walked by both interfaces. See GuiMenus.h
// for why it exists; this file is meant to read like the menu it describes.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>
#include <vector>

#include "GuiMenus.h"
#include "GuiActions.h"
#include "GuiDialogs.h"
#include "Gui.h"
#include "Options.h"
#include "drawContext.h"
#include "GModel.h"
#include "Context.h"
#include "GmshMessage.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

namespace Menu {

  static unsigned _generation = 1;
  void invalidate() { _generation++; }
  unsigned generation() { return _generation; }

  namespace {

    // --- little builders, so that the description below is only description

    MenuItem action(const std::string &label, char mnemonic,
                const std::function<void()> &what,
                const Shortcut &shortcut = Shortcut())
    {
      MenuItem i;
      i.kind = MenuItem::Action;
      i.label = label;
      i.mnemonic = mnemonic;
      i.shortcut = shortcut;
      i.action = what;
      return i;
    }

    // An entry that shows and hides one of the panels. Both interfaces show a
    // check mark next to it: the FLTK menu never did, which meant its "Message
    // Console" entry was less telling than the panel it drove.
    MenuItem panel(const std::string &label, char mnemonic, int which,
               const Shortcut &shortcut = Shortcut())
    {
      MenuItem i;
      i.kind = MenuItem::Toggle;
      i.label = label;
      i.mnemonic = mnemonic;
      i.shortcut = shortcut;
      i.checked = [which]() { return Gui::panelVisible(which); };
      i.action = [which]() {
        Gui::showPanel(which, !Gui::panelVisible(which));
      };
      return i;
    }

    // the same, for the windows that have become dialogs of GuiDialogs.h
    MenuItem dialog(const std::string &label, char mnemonic, int which,
                const Shortcut &shortcut = Shortcut())
    {
      MenuItem i;
      i.kind = MenuItem::Toggle;
      i.label = label;
      i.mnemonic = mnemonic;
      i.shortcut = shortcut;
      i.checked = [which]() { return Gui::dialogVisible(which); };
      i.action = [which]() {
        // through Dialog::show(), which is where a dialog gets what it needs
        // read before it appears; -1 keeps the pane it was left on
        if(Gui::dialogVisible(which))
          Gui::showDialog(which, false);
        else
          Dialog::show(which, -1);
      };
      return i;
    }

    MenuItem submenu(const std::string &label, char mnemonic,
                 const std::vector<MenuItem> &children)
    {
      MenuItem i;
      i.kind = MenuItem::Submenu;
      i.label = label;
      i.mnemonic = mnemonic;
      i.children = children;
      // A divider at the very end would draw a line under nothing. It happens
      // as soon as an entry the interface cannot honour is left out, so it is
      // trimmed here rather than guessed at each call.
      if(!i.children.empty()) i.children.back().dividerAfter = false;
      return i;
    }

    MenuItem window(const std::string &label, char mnemonic,
                const std::string &what, const Shortcut &shortcut = Shortcut())
    {
      return action(label, mnemonic, [what]() { Gui::windowAction(what); },
                    shortcut);
    }

    MenuItem file(const std::string &label, char mnemonic, const std::string &what,
              const Shortcut &shortcut = Shortcut())
    {
      return action(label, mnemonic, [what]() { Gui::fileAction(what); },
                    shortcut);
    }

    // divider after the entry, as FL_MENU_DIVIDER has always meant
    MenuItem divide(MenuItem i)
    {
      i.dividerAfter = true;
      return i;
    }

    // A name that is not valid UTF-8 would be drawn as anything: the FLTK
    // menu has always left those out, and now both interfaces do.
static bool check_utf8(const std::string &string)
{
  for(int i = 0, ix = string.length(); i < ix; i++) {
    int n;
    int c = (unsigned char)string[i];
    if(0x00 <= c && c <= 0x7f)
      n = 0; // 0bbbbbbb
    else if((c & 0xE0) == 0xC0)
      n = 1; // 110bbbbb
    else if(c == 0xed && i < (ix - 1) &&
            ((unsigned char)string[i + 1] & 0xa0) == 0xa0)
      return false; // U+d800 to U+dfff
    else if((c & 0xF0) == 0xE0)
      n = 2; // 1110bbbb
    else if((c & 0xF8) == 0xF0)
      n = 3; // 11110bbb
    // else if (($c & 0xFC) == 0xF8) n=4; // 111110bb //byte 5, unnecessary in 4
    // byte UTF-8 else if (($c & 0xFE) == 0xFC) n=5; // 1111110b //byte 6,
    // unnecessary in 4 byte UTF-8
    else
      return false;
    for(int j = 0; j < n && i < ix; j++) { // n bytes matching 10bbbbbb follow ?
      if((++i == ix) || (((unsigned char)string[i] & 0xC0) != 0x80))
        return false;
    }
  }
  return true;
}

    // the entries of "File > Open Recent", read while the menu is built
    std::vector<MenuItem> recentFiles()
    {
      std::vector<MenuItem> items;
      const std::vector<std::string> &recent = CTX::instance()->recentFiles;
      for(std::size_t i = 0; i < recent.size(); i++) {
        if(recent[i].empty()) continue;
        if(!check_utf8(recent[i])) {
          Msg::Info("Ignoring invalid General.RecentFile%d", (int)i);
          continue;
        }
        int index = (int)i;
        // the FLTK interface has always bound the second one to Ctrl+Shift+R
        Shortcut s = (i == 1) ? Shortcut('R', ModCommand | ModShift) :
                                Shortcut();
        items.push_back(action(recent[i], 0,
                               [index]() { projectOpenRecent(index); }, s));
      }
      return items;
    }

  } // namespace

  std::vector<MenuItem> bar()
  {
    std::vector<MenuItem> menus;

    // --- File
    {
      std::vector<MenuItem> file_;
      file_.push_back(file("New...", 'N', "new", Shortcut('N', ModCommand)));
      file_.push_back(file("Open...", 'O', "open", Shortcut('O', ModCommand)));
      file_.push_back(submenu("Open Recent", 0, recentFiles()));
      file_.push_back(
        file("Merge...", 'e', "merge", Shortcut('O', ModCommand | ModShift)));
      file_.push_back(
        divide(action("Watch Pattern...", 0, Dialog::showWatchPattern)));
      file_.push_back(action("Clear", 'C', projectClear));
      file_.push_back(
        file("Rename...", 'R', "rename", Shortcut('R', ModCommand)));
      file_.push_back(divide(action("Delete", 0, projectDelete)));
#if defined(HAVE_ONELAB)
      file_.push_back(divide(submenu(
        "Remote", 0,
        {action("Start...", 0, Dialog::showRemoteCommand),
         file("Merge...", 0, "remote_merge"),
         file("Clear", 0, "remote_clear"), file("Stop", 0, "remote_stop")})));
#endif
      file_.push_back(action("Save Mesh", 'v', meshSave,
                             Shortcut('S', ModCommand | ModShift)));
      file_.push_back(action("Save Model Options", 0,
                             []() { optionsSave(true); },
                             Shortcut('J', ModCommand)));
      file_.push_back(divide(action("Save Options As Default", 0,
                                    []() { optionsSave(false); },
                                    Shortcut('J', ModCommand | ModShift))));
      file_.push_back(
        divide(file("Export...", 'E', "export", Shortcut('E', ModCommand))));
      MenuItem quit = action("Quit", 'Q', projectQuit, Shortcut('Q', ModCommand));
      quit.hideInSystemBar = true;
      file_.push_back(quit);
      menus.push_back(submenu("File", 'F', file_));
    }

    // --- Tools
    {
      std::vector<MenuItem> tools;
      tools.push_back(panel("Options", 'O', Gui::PanelOptions,
                            Shortcut('N', ModCommand | ModShift)));
      tools.push_back(panel("Plugins", 'u', Gui::PanelPlugins,
                            Shortcut('U', ModCommand | ModShift)));
      tools.push_back(panel("Visibility", 'V', Gui::PanelVisibility,
                            Shortcut('V', ModCommand | ModShift)));
      tools.push_back(dialog("Clipping", 'C', Dialog::Clipping,
                            Shortcut('C', ModCommand | ModShift)));
      tools.push_back(divide(dialog("Manipulator", 'M', Dialog::Manipulator,
                                    Shortcut('M', ModCommand | ModShift))));
#if defined(HAVE_3M)
      // the proprietary extension of contrib/3M, which only the FLTK interface
      // has a window for
      if(Gui::supportsWindowAction("3m"))
        tools.push_back(divide(window("3M", '3', "3m")));
#endif
      tools.push_back(dialog("Statistics", 't', Dialog::Statistics,
                            Shortcut('I', ModCommand)));
      tools.push_back(panel("Message Console", 'e', Gui::PanelMessageConsole,
                            Shortcut('L', ModCommand)));
      menus.push_back(submenu("Tools", 'T', tools));
    }

    // --- Window
    {
      std::vector<MenuItem> win;
      if(Gui::supportsWindowAction("new"))
        win.push_back(divide(window("New Window", 0, "new")));
      if(Gui::supportsWindowAction("copy"))
        win.push_back(divide(window("Copy to Clipboard", 0, "copy",
                                    Shortcut('C', ModCommand))));
      win.push_back(window("Split Horizontally", 0, "split_h"));
      win.push_back(window("Split Vertically", 0, "split_v"));
      win.push_back(divide(window("Unsplit", 0, "split_u")));
      win.push_back(
        window("Minimize", 0, "minimize", Shortcut('M', ModCommand)));
      win.push_back(window("Zoom", 0, "zoom"));
      win.push_back(divide(window("Enter Full Screen", 0, "fullscreen",
                                  Shortcut('F', ModCommand))));
      if(Gui::supportsWindowAction("attach_detach"))
        win.push_back(divide(window("Attach/Detach Menu", 0, "attach_detach",
                                    Shortcut('D', ModCommand))));
      if(Gui::supportsWindowAction("front"))
        win.push_back(window("Bring All to Front", 0, "front"));
      menus.push_back(submenu("Window", 'W', win));
    }

    // --- Help
    {
      std::vector<MenuItem> help;
      help.push_back(
        divide(action("Online Documentation", 'l', helpOnline)));
      help.push_back(divide(panel("Keyboard and Mouse Usage", 'K',
                                  Gui::PanelKeyboardAndMouse,
                                  Shortcut('H', ModCommand))));
      help.push_back(panel("Current Options and Workspace", 'C',
                           Gui::PanelCurrentOptions,
                           Shortcut('H', ModCommand | ModShift)));
      help.push_back(divide(action("Restore all Options to Default Settings",
                                   'R', optionsRestoreDefaults)));
      // macOS puts About in the application menu itself
      MenuItem about = panel("About Gmsh", 'A', Gui::PanelAbout);
      about.hideInSystemBar = true;
      help.push_back(about);
      menus.push_back(submenu("Help", 'H', help));
    }

    return menus;
  }

// --- the models that are loaded, which the first button of the status bar
// drops

std::vector<MenuItem> models()
{
  std::vector<MenuItem> items;
  for(std::size_t i = 0; i < GModel::list.size(); i++) {
    std::string label = "Model " + std::to_string(i);
    if(GModel::list[i]->getName().size())
      label += " - " + GModel::list[i]->getName();
    MenuItem m;
    m.kind = MenuItem::Toggle;
    m.label = label;
    m.checked = [i]() {
      return i < GModel::list.size() && GModel::list[i] == GModel::current();
    };
    m.action = [i]() { modelSetCurrent((int)i); };
    items.push_back(m);
  }
  return items;
}

// --- the quick access menu of the status bar
//
// This is the fifty-four entry Fl_Menu_Item[] that status_options_cb() of
// src/fltk/graphicWindow.cpp declared, with the places of the entries whose
// check mark had to be set written out as `const int gen = 7, geo = 14, msh =
// 21, pos = 32, end = 54` -- five numbers that had to be counted again every
// time an entry moved. Here each entry says for itself what it shows.

namespace {

  // one of the entries of quickAccessAction()
  MenuItem quick(const std::string &label, const std::string &what,
             const Shortcut &shortcut = Shortcut())
  {
    return action(label, 0, [what]() { quickAccessAction(what); }, shortcut);
  }

  // The same, for an entry that is a switch: what it does and what its check
  // mark says are both asked of the shared action, so neither can drift from
  // the other, which is what the table of hand-counted indices could not
  // promise.
  MenuItem quickToggle(const std::string &label, const std::string &what,
                   const Shortcut &shortcut = Shortcut())
  {
    MenuItem i;
    i.kind = MenuItem::Toggle;
    i.label = label;
    i.shortcut = shortcut;
    i.checked = [what]() { return quickAccessChecked(what); };
    i.action = [what]() { quickAccessAction(what); };
    return i;
  }

  // "All ... options...", which opens the option window on that category
  MenuItem allOptions(const std::string &label, int category)
  {
    MenuItem i = action(label, 0, [category]() {
      Dialog::optionsCategory() = category;
      Dialog::show(Dialog::Options, -1);
    });
    i.dividerAfter = true;
    return i;
  }

  bool _haveViews()
  {
#if defined(HAVE_POST)
    return !PView::list.empty();
#else
    return false;
#endif
  }

} // namespace

std::vector<MenuItem> quickAccess()
{
  std::vector<MenuItem> items;

  items.push_back(quick("Reset viewport", "reset_viewport"));
  items.push_back(quick("Select rotation center", "select_center"));
  items.push_back(divide(submenu("Split window", 0,
                                 {quick("Horizontally", "split_hor"),
                                  quick("Vertically", "split_ver"),
                                  quick("Unsplit", "unsplit")})));

  // turning the axes on fits them to what is drawn, which is why this one is
  // not simply the option
  items.push_back(quickToggle("Axes", "axes", Shortcut('A', ModAlt)));
  items.push_back(quickToggle("Mouse hover over meshes", "hover_meshes"));
  // perspective asks for the distance to the eye once it is on, which is what
  // makes the difference visible at all
  items.push_back(submenu(
    "Projection mode", 0,
    {quick("Orthographic", "orthographic", Shortcut('O', ModAlt)),
     quick("Perspective", "perspective")}));
  items.push_back(allOptions("All general options...", 0));

  items.push_back(submenu(
    "Geometry visibility", 0,
    {quickToggle("Points", "geometry_points", Shortcut('P', ModAlt)),
     quickToggle("Curves", "geometry_curves", Shortcut('L', ModAlt)),
     quickToggle("Surfaces ", "geometry_surfaces", Shortcut('S', ModAlt)),
     quickToggle("Volumes", "geometry_volumes", Shortcut('V', ModAlt))}));
  items.push_back(allOptions("All geometry options...", 1));

  items.push_back(submenu(
    "Mesh visibility", 0,
    {quickToggle("Nodes", "mesh_nodes", Shortcut('P', ModAlt | ModShift)),
     quickToggle("1D elements", "mesh_lines", Shortcut('L', ModAlt | ModShift)),
     quickToggle("2D element edges ", "mesh_surface_edges",
                 Shortcut('S', ModAlt | ModShift)),
     quickToggle("2D element faces", "mesh_surface_faces",
                 Shortcut('D', ModAlt | ModShift)),
     quickToggle("3D element edges", "mesh_volume_edges",
                 Shortcut('V', ModAlt | ModShift)),
     quickToggle("3D element faces", "mesh_volume_faces",
                 Shortcut('B', ModAlt | ModShift))}));
  {
    // the one the menu opens under: it is what one comes here for
    MenuItem toggle =
      quick("Toggle mesh display", "mesh_toggle", Shortcut('M', ModAlt));
    toggle.preferred = true;
    items.push_back(toggle);
  }
  items.push_back(quick("Global mesh size factor", "mesh_size"));
  items.push_back(allOptions("All mesh options...", 2));

  // and what only means something with a view to say it of
  if(_haveViews()) {
    items.push_back(quickToggle("View element outlines ",
                                "view_element_outlines",
                                Shortcut('E', ModAlt)));
    items.push_back(quick("View normal raise", "view_normal_raise"));
    items.push_back(
      submenu("View intervals", 0,
              {quick("Iso-values", "view_iso", Shortcut('T', ModAlt)),
               quick("Continuous map", "view_continous"),
               quick("Filled iso-values", "view_filled"),
               quick("Numeric values", "view_numeric")}));
    items.push_back(submenu("View range", 0,
                            {quick("Default", "view_range_default"),
                             quick("Per time step", "view_range_per_step")}));
    items.push_back(submenu("View vector display", 0,
                            {quick("Line", "view_line"),
                             quick("3D arrow", "view_3d_arrow"),
                             quick("Displacement", "view_displacement")}));
    items.push_back(submenu("View glyph location", 0,
                            {quick("Barycenter", "view_glyph_barycenter"),
                             quick("Node", "view_glyph_node")}));
    MenuItem all = action("All view options...", 0,
                      []() { Dialog::showOptionsForView(-1); });
    items.push_back(all);
  }
  else
    // nothing follows it: the divider under the mesh options would be a rule
    // along the bottom of the menu
    items.back().dividerAfter = false;

  return items;
}

// --- the menu a view carries, and the one a solver carries
//
// These were the Fl_Menu_Button of src/fltk/viewButton.cpp -- twenty-six
// entries -- and of src/fltk/solverButton.cpp. The Dear ImGui tree offered
// three of the twenty-six, which is the kind of gap a description settles at
// once.

namespace {

  // one of the entries of viewAction(), on this view
  MenuItem onView(const std::string &label, int index, const std::string &what,
              const Shortcut &shortcut = Shortcut())
  {
    return action(label, 0, [what, index]() { viewAction(what, index); },
                  shortcut);
  }

} // namespace

std::vector<MenuItem> viewActions(int index)
{
  std::vector<MenuItem> items;

  items.push_back(onView("Options", index, "options", Shortcut('O')));
  items.push_back(divide(onView("Plugins", index, "plugins", Shortcut('P'))));

  items.push_back(onView("Reload", index, "reload", Shortcut('R')));
  items.push_back(submenu("Reload Views", 0,
                          {onView("All", index, "reload_all"),
                           onView("Visible", index, "reload_visible")}));
  items.push_back(divide(onView("Create Alias", index, "alias")));

  items.push_back(
    onView("Remove", index, "remove", Shortcut(KeyDelete)));
  items.push_back(divide(
    submenu("Remove Views", 0,
            {onView("All", index, "remove_all"),
             onView("Visible", index, "remove_visible"),
             onView("Invisible", index, "remove_invisible"),
             onView("Other", index, "remove_other"),
             onView("Empty", index, "remove_empty"),
             onView("With Same Name", index, "remove_same_name")})));

  items.push_back(onView("Sort By Name", index, "sort_by_name"));
  items.push_back(submenu("Set Visibility", 0,
                          {onView("All On", index, "all_on"),
                           onView("All Off", index, "all_off"),
                           onView("Invert", index, "invert"),
                           onView("Same Name On", index, "same_name_on")}));
  items.push_back(
    submenu("Combine Elements", 0,
            {onView("From All Views", index, "combine_elements_all"),
             onView("From Visible Views", index, "combine_elements_visible"),
             onView("From All Views With Same Name", index,
                    "combine_elements_same_name")}));
  items.push_back(divide(
    submenu("Combine Time Steps", 0,
            {onView("From All Views", index, "combine_steps_all"),
             onView("From Visible Views", index, "combine_steps_visible"),
             onView("From All Views With Same Name", index,
                    "combine_steps_same_name")})));

  items.push_back(
    onView("Apply As Background Mesh", index, "background_mesh"));
  items.push_back(onView("Export...", index, "export"));
  return items;
}

std::vector<MenuItem> solverOptions()
{
  // a switch of the gear menu: what it does and what its check mark says both
  // go through the shared action, so neither can drift from the other
  auto option = [](const std::string &label, const std::string &what) {
    MenuItem i;
    i.kind = MenuItem::Toggle;
    i.label = label;
    i.checked = [what]() { return solverOptionSet(what); };
    i.action = [what]() { solverOptionAction(what); };
    return i;
  };

  // the database is not to be touched while a solver is running, which the
  // tree used to say by greying the entries outside the block of switches --
  // by their places in the table
  auto idle = [](MenuItem i) {
    i.enabled = []() { return !solverIsRunning(); };
    return i;
  };

  std::vector<MenuItem> items;
  items.push_back(idle(action("Reset database", 0,
                              []() { Gui::onelabAction("reset"); })));
  items.push_back(idle(action("Save database...", 0,
                              []() { Gui::onelabAction("save"); })));
  items.push_back(divide(idle(
    action("Load database...", 0, []() { Gui::onelabAction("load"); }))));

  items.push_back(option("Save database automatically", "save"));
  items.push_back(option("Load database automatically", "load"));
  items.push_back(option("Archive output files automatically", "archive"));
  items.push_back(option("Check model after each change", "check"));
  items.push_back(option("Remesh automatically", "mesh"));
  items.push_back(option("Merge results automatically", "merge"));
  items.push_back(option("Show new views", "show"));
  items.push_back(option("Always show last step", "step"));
  items.push_back(divide(option("Show hidden parameters", "invisible")));

  items.push_back(idle(
    action("Add new solver...", 0, []() { solverOptionAction("add"); })));
  return items;
}

std::vector<MenuItem> solverActions(int index)
{
  std::vector<MenuItem> items;
  items.push_back(action("Rename...", 0,
                         [index]() { solverAction("rename", index); }));
  items.push_back(divide(
    action("Change Executable Location...", 0,
           [index]() { solverAction("executable", index); })));
  items.push_back(action("Remove", 0,
                         [index]() { solverAction("remove", index); }));
  return items;
}

// --- the modules tree
//
// This is static_modules[] of src/fltk/graphicWindow.cpp, node for node and
// leaf for leaf. What each leaf does is written once here: the entries that
// need parameters show the context panel that holds them and then run the
// shared interactive action, which reads the panel back at every application.

namespace {

  MenuItem act(const std::string &label, const std::function<void()> &what)
  {
    return action(label, 0, what);
  }

  // an entry that shows a panel and leaves it at that
  MenuItem show(const std::string &label, int panel)
  {
    return action(label, 0, [panel]() { Gui::showPanel(panel, true); });
  }

  // pick entities and do something to them, with the parameters of the pane the
  // entry opens
  MenuItem onSelection(const std::string &label, int what, int pane, bool extrude,
                   const std::string &restrict_ = "")
  {
    return action(label, 0, [what, pane, extrude, restrict_]() {
      Dialog::showTransform(pane, extrude);
      geometryActOnSelection(what, restrict_);
    });
  }

  std::vector<MenuItem> addEntities()
  {
    // the shapes whose parameters are typed in the context panel, with the pane
    // that holds them
    // Every entry of "Add" runs the tool of one pane of the elementary dialog,
    // through the one place that knows how to swap one tool for another.
    auto shape = [](const std::string &label, int pane) {
      return action(label, 0, [pane]() { geometryElementary(pane); });
    };
    // the pane of each picked curve, after the twelve typed shapes
    auto curve = [](const std::string &label, const std::string &, int pane) {
      return action(label, 0, [pane]() { geometryElementary(pane); });
    };
    // the pane of each picked surface or volume, after the picked curves
    auto boundary = [](const std::string &label, int, int pane) {
      return action(label, 0, [pane]() { geometryElementary(pane); });
    };

    std::vector<MenuItem> items;
    // "Parameter" has nothing to place: it is written from the panel alone
    items.push_back(
      action("Parameter", 0, []() { Dialog::show(Dialog::Elementary, 0); }));
    items.push_back(shape("Point", 1));
    items.push_back(curve("Line", "Line", 12));
    items.push_back(curve("Spline", "Spline", 13));
    items.push_back(curve("Bezier", "Bezier", 14));
    items.push_back(curve("B-Spline", "BSpline", 15));
    items.push_back(shape("Circle", 2));
    items.push_back(action("Circle arc", 0,
                           []() { geometryElementary(16); }));
    items.push_back(shape("Ellipse", 3));
    items.push_back(action("Ellipse arc", 0,
                           []() { geometryElementary(17); }));
    items.push_back(shape("Rectangle", 5));
    items.push_back(shape("Disk", 4));
    items.push_back(boundary("Plane surface", 0, 18));
    items.push_back(boundary("Surface filling", 1, 19));
    items.push_back(shape("Sphere", 6));
    items.push_back(shape("Cylinder", 7));
    items.push_back(shape("Box", 8));
    items.push_back(shape("Torus", 9));
    items.push_back(shape("Cone", 10));
    items.push_back(shape("Wedge", 11));
    items.push_back(boundary("Volume", 2, 20));
    return items;
  }

  std::vector<MenuItem> physicalGroups(bool remove)
  {
    std::vector<MenuItem> items;
    static const char *const kinds[] = {"Point", "Curve", "Surface", "Volume"};
    for(auto k : kinds) {
      std::string type = k;
      items.push_back(action(type, 0, [type, remove]() {
        Dialog::showPhysical(type, remove);
        int what = remove ? GEO_ACTION_PHYSICAL_REMOVE : GEO_ACTION_PHYSICAL_ADD;
        geometryActOnSelection(what, type);
      }));
    }
    return items;
  }

  std::vector<MenuItem> meshParts(const std::string &how)
  {
    std::vector<MenuItem> items;
    static const char *const labels[] = {"Elements", "Curves", "Surfaces",
                                         "Volumes"};
    static const char *const args[] = {"elements", "curves", "surfaces",
                                       "volumes"};
    for(int i = 0; i < 4; i++) {
      std::string a = args[i];
      items.push_back(action(labels[i], 0, [a, how]() {
        meshModifyParts(a, how);
      }));
    }
    return items;
  }

} // namespace

std::vector<MenuItem> modules()
{
  std::vector<MenuItem> tree;

  // --- Geometry
  {
    std::vector<MenuItem> elementary;
    elementary.push_back(submenu(
      "Set geometry kernel", 0,
      {act("Built-in", []() { geometrySetFactory("Built-in"); }),
       act("OpenCASCADE", []() { geometrySetFactory("OpenCASCADE"); })}));
    elementary.push_back(submenu("Add", 0, addEntities()));
    elementary.push_back(submenu(
      "Transform", 0,
      {onSelection("Translate", GEO_ACTION_TRANSLATE, 0, false),
       onSelection("Rotate", GEO_ACTION_ROTATE, 1, false),
       onSelection("Scale", GEO_ACTION_SCALE, 2, false),
       onSelection("Symmetry", GEO_ACTION_SYMMETRY, 3, false)}));
    elementary.push_back(submenu(
      "Extrude", 0,
      {onSelection("Translate", GEO_ACTION_EXTRUDE_TRANSLATE, 0, true),
       onSelection("Rotate", GEO_ACTION_EXTRUDE_ROTATE, 1, true),
       onSelection("Pipe", GEO_ACTION_PIPE, -1, true)}));
    {
      std::vector<MenuItem> boolean;
      static const char *const ops[][2] = {
        {"Intersection", "BooleanIntersection"},
        {"Union", "BooleanUnion"},
        {"Difference", "BooleanDifference"},
        {"Fragments", "BooleanFragments"}};
      for(auto &o : ops) {
        std::string op = o[1];
        boolean.push_back(action(o[0], 0, [op]() {
          Dialog::showTransform(4, false);
          geometryBoolean(op);
        }));
      }
      elementary.push_back(submenu("Boolean", 0, boolean));
    }
    elementary.push_back(action("Fillet", 0, []() {
      Dialog::showTransform(5, false);
      geometryFillet();
    }));
    elementary.push_back(act("Split curve", geometrySplitCurve));
    elementary.push_back(
      onSelection("Delete", GEO_ACTION_DELETE, 6, false));
    elementary.push_back(act("Coherence", geometryCoherence));

    std::vector<MenuItem> geometry;
    geometry.push_back(submenu("Elementary entities", 0, elementary));
    geometry.push_back(submenu("Physical groups", 0,
                               {submenu("Add", 0, physicalGroups(false)),
                                submenu("Remove", 0, physicalGroups(true))}));
    geometry.push_back(act("Reload script", geometryReload));
    geometry.push_back(
      act("Remove last script command", geometryRemoveLastCommand));
    geometry.push_back(act("Edit script", geometryEditInTextEditor));
    tree.push_back(submenu("Geometry", 0, geometry));
  }

#if defined(HAVE_MESH)
  // --- Mesh
  {
    std::vector<MenuItem> define;
    define.push_back(action("Size at points", 0, []() {
      Dialog::show(Dialog::Mesh, 0);
      geometryActOnSelection(GEO_ACTION_MESH_SIZE, "Point");
    }));
    define.push_back(show("Size fields", Gui::PanelFields));
    {
      std::vector<MenuItem> embedded;
      static const char *const kinds[] = {"Point", "Curve", "Surface"};
      for(auto k : kinds) {
        std::string type = k;
        embedded.push_back(action(type, 0, [type]() {
          Dialog::showTransform(-1, false);
          meshDefineEmbedded(type);
        }));
      }
      define.push_back(submenu("Embedded", 0, embedded));
    }
    {
      std::vector<MenuItem> transfinite;
      for(int dim = 1; dim <= 3; dim++) {
        static const char *const labels[] = {"Curve", "Surface", "Volume"};
        transfinite.push_back(action(labels[dim - 1], 0, [dim]() {
          // the volume takes its corners without any parameter of its own
          if(dim < 3) Dialog::show(Dialog::Mesh, dim);
          meshDefineTransfinite(dim);
        }));
      }
      define.push_back(submenu("Transfinite", 0, transfinite));
    }
    define.push_back(submenu(
      "Compound", 0,
      {onSelection("Curve", GEO_ACTION_COMPOUND, -1, false, "Curve"),
       onSelection("Surface", GEO_ACTION_COMPOUND, -1, false, "Surface")}));
    define.push_back(action("Recombine", 0, []() {
      geometryActOnSelection(GEO_ACTION_RECOMBINE, "Surface");
    }));

    std::vector<MenuItem> mesh;
    mesh.push_back(submenu("Define", 0, define));
    mesh.push_back(act("1D", []() { meshDimension(1); }));
    mesh.push_back(act("2D", []() { meshDimension(2); }));
    mesh.push_back(act("3D", []() { meshDimension(3); }));
    mesh.push_back(act("Optimize 3D", []() { meshOptimize(""); }));
#if defined(HAVE_NETGEN)
    mesh.push_back(
      act("Optimize 3D (Netgen)", []() { meshOptimize("Netgen"); }));
#endif
    for(int o = 1; o <= 3; o++)
      mesh.push_back(act("Set order " + std::to_string(o),
                         [o]() { meshSetOrder(o); }));
    mesh.push_back(act("High-order tools",
                       []() { Dialog::show(Dialog::HighOrder, 0); }));
    mesh.push_back(act("Refine by splitting", meshRefine));
#if defined(HAVE_METIS)
    mesh.push_back(act("Partition",
                       []() { Dialog::show(Dialog::Partition, 0); }));
    mesh.push_back(act("Unpartition", meshUnpartition));
#endif
    mesh.push_back(act("Smooth 2D", []() { meshOptimize("Laplace2D"); }));
    mesh.push_back(act("Recombine 2D", meshRecombine));
    mesh.push_back(show("Reclassify 2D", Gui::PanelClassify));
    {
      std::vector<MenuItem> experimental;
      experimental.push_back(act("Compute quad layout", meshComputeCrossField));
#if defined(HAVE_METIS)
      experimental.push_back(
        act("Convert old partitioning", meshConvertOldPartitioning));
#endif
      experimental.push_back(act("Optimize quad topology", []() {
        meshOptimize("QuadQuasiStructured");
      }));
      experimental.push_back(act("Untangle geometry", []() {
        meshOptimize("UntangleMeshGeometry");
      }));
      mesh.push_back(submenu("Experimental", 0, experimental));
    }
    mesh.push_back(submenu("Reverse", 0, meshParts("reverse")));
    mesh.push_back(submenu("Delete", 0, meshParts("delete")));
    mesh.push_back(act("Inspect", meshInspectElements));
    mesh.push_back(act("Save", meshSave));
    tree.push_back(submenu("Mesh", 0, mesh));
  }
#endif

  return tree;
}

} // namespace Menu

#endif
