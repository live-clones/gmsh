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
#include "Context.h"
#include "GmshMessage.h"

namespace Menu {

  std::string Shortcut::label() const
  {
    if(empty()) return "";
    std::string s;
    if(mods & ModCommand) {
#if defined(__APPLE__)
      s += "Cmd+";
#else
      s += "Ctrl+";
#endif
    }
    if(mods & ModShift) s += "Shift+";
    if(mods & ModAlt) s += "Alt+";
    if(key >= KeyF1 && key < KeyF1 + 12)
      s += "F" + std::to_string(key - KeyF1 + 1);
    else
      s += (char)key;
    return s;
  }

  static unsigned _generation = 1;
  void invalidate() { _generation++; }
  unsigned generation() { return _generation; }

  namespace {

    // --- little builders, so that the description below is only description

    Item action(const std::string &label, char mnemonic,
                const std::function<void()> &what,
                const Shortcut &shortcut = Shortcut())
    {
      Item i;
      i.kind = Action;
      i.label = label;
      i.mnemonic = mnemonic;
      i.shortcut = shortcut;
      i.action = what;
      return i;
    }

    // An entry that shows and hides one of the panels. Both interfaces show a
    // check mark next to it: the FLTK menu never did, which meant its "Message
    // Console" entry was less telling than the panel it drove.
    Item panel(const std::string &label, char mnemonic, int which,
               const Shortcut &shortcut = Shortcut())
    {
      Item i;
      i.kind = Toggle;
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
    Item dialog(const std::string &label, char mnemonic, int which,
                const Shortcut &shortcut = Shortcut())
    {
      Item i;
      i.kind = Toggle;
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

    Item submenu(const std::string &label, char mnemonic,
                 const std::vector<Item> &children)
    {
      Item i;
      i.kind = Submenu;
      i.label = label;
      i.mnemonic = mnemonic;
      i.children = children;
      // A divider at the very end would draw a line under nothing. It happens
      // as soon as an entry the interface cannot honour is left out, so it is
      // trimmed here rather than guessed at each call.
      if(!i.children.empty()) i.children.back().dividerAfter = false;
      return i;
    }

    Item window(const std::string &label, char mnemonic,
                const std::string &what, const Shortcut &shortcut = Shortcut())
    {
      return action(label, mnemonic, [what]() { Gui::windowAction(what); },
                    shortcut);
    }

    Item file(const std::string &label, char mnemonic, const std::string &what,
              const Shortcut &shortcut = Shortcut())
    {
      return action(label, mnemonic, [what]() { Gui::fileAction(what); },
                    shortcut);
    }

    // divider after the entry, as FL_MENU_DIVIDER has always meant
    Item divide(Item i)
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
    std::vector<Item> recentFiles()
    {
      std::vector<Item> items;
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

  std::vector<Item> bar()
  {
    std::vector<Item> menus;

    // --- File
    {
      std::vector<Item> file_;
      file_.push_back(file("New...", 'N', "new", Shortcut('N', ModCommand)));
      file_.push_back(file("Open...", 'O', "open", Shortcut('O', ModCommand)));
      file_.push_back(submenu("Open Recent", 0, recentFiles()));
      file_.push_back(
        file("Merge...", 'e', "merge", Shortcut('O', ModCommand | ModShift)));
      file_.push_back(divide(file("Watch Pattern...", 0, "watch")));
      file_.push_back(action("Clear", 'C', projectClear));
      file_.push_back(
        file("Rename...", 'R', "rename", Shortcut('R', ModCommand)));
      file_.push_back(divide(action("Delete", 0, projectDelete)));
#if defined(HAVE_ONELAB)
      file_.push_back(divide(submenu(
        "Remote", 0,
        {file("Start...", 0, "remote_start"),
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
      Item quit = action("Quit", 'Q', projectQuit, Shortcut('Q', ModCommand));
      quit.hideInSystemBar = true;
      file_.push_back(quit);
      menus.push_back(submenu("File", 'F', file_));
    }

    // --- Tools
    {
      std::vector<Item> tools;
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
      std::vector<Item> win;
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
      std::vector<Item> help;
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
      Item about = panel("About Gmsh", 'A', Gui::PanelAbout);
      about.hideInSystemBar = true;
      help.push_back(about);
      menus.push_back(submenu("Help", 'H', help));
    }

    return menus;
  }

// --- the modules tree
//
// This is static_modules[] of src/fltk/graphicWindow.cpp, node for node and
// leaf for leaf. What each leaf does is written once here: the entries that
// need parameters show the context panel that holds them and then run the
// shared interactive action, which reads the panel back at every application.

namespace {

  Item act(const std::string &label, const std::function<void()> &what)
  {
    return action(label, 0, what);
  }

  // an entry that shows a panel and leaves it at that
  Item show(const std::string &label, int panel)
  {
    return action(label, 0, [panel]() { Gui::showPanel(panel, true); });
  }

  // pick entities and do something to them, with the parameters of the pane the
  // entry opens
  Item onSelection(const std::string &label, int what, int pane, bool extrude,
                   const std::string &restrict_ = "")
  {
    return action(label, 0, [what, pane, extrude, restrict_]() {
      Dialog::showTransform(pane, extrude);
      geometryActOnSelection(what, restrict_);
    });
  }

  std::vector<Item> addEntities()
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

    std::vector<Item> items;
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

  std::vector<Item> physicalGroups(bool remove)
  {
    std::vector<Item> items;
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

  std::vector<Item> meshParts(const std::string &how)
  {
    std::vector<Item> items;
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

std::vector<Item> modules()
{
  std::vector<Item> tree;

  // --- Geometry
  {
    std::vector<Item> elementary;
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
      std::vector<Item> boolean;
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

    std::vector<Item> geometry;
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
    std::vector<Item> define;
    define.push_back(action("Size at points", 0, []() {
      Dialog::show(Dialog::Mesh, 0);
      geometryActOnSelection(GEO_ACTION_MESH_SIZE, "Point");
    }));
    define.push_back(show("Size fields", Gui::PanelFields));
    {
      std::vector<Item> embedded;
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
      std::vector<Item> transfinite;
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

    std::vector<Item> mesh;
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
      std::vector<Item> experimental;
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
