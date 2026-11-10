// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>
#include <functional>
#include <map>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "Actions.h"
#include "Context.h"
#include "GModel.h"
#include "OpenFile.h"
#include "Options.h"
#include "OS.h"
#include "SBoundingBox3d.h"
#include "Shortcuts.h"
#include "scriptStringInterface.h"

#if defined(HAVE_MESH)
#include "Field.h"
// #include "gmshCrossFields.h" (for Compute quad layout)
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

// The menus

// a menu, and a group of items set apart (a menu without label)
static actionItem menu(const std::string &label, const std::string &help,
                       const std::vector<actionItem> &items)
{ return {label, ItemMenu, "", items, help, ""}; }
static actionItem group(const std::vector<actionItem> &items)
{ return menu("", "", items); }
// an action of the table (named as its label if no name is given)
static actionItem action(const std::string &label, const std::string &name = "",
                         const std::string &help = "",
                         const std::string &shortcut = "")
{ return {label, ItemAction, name.empty() ? label : name, {}, help, shortcut}; }
// an operation on the entities picked
static actionItem operation(const std::string &label,
                            const std::string &name = "",
                            const std::string &help = "")
{ return {label, ItemOperation, name.empty() ? label : name, {}, help, ""}; }
// a shape (see scriptShapes())
static actionItem shape(const std::string &label, const std::string &name)
{ return {label, ItemShape, name, {}, "", ""}; }
// an option toggled or set
static actionItem option(const std::string &label, const std::string &name,
                         const std::string &shortcut = "")
{ return {label, ItemOption, name, {}, "", shortcut}; }

// the programs the commands added to the script are also written in (see
// General.ScriptingLanguages), and their edition
static actionItem programsMenu()
{
  std::vector<actionItem> write, edit;
  for(auto &l : scriptLanguages()) {
    write.push_back(action(l.label, "script_write_" + l.name,
                           "Also write the commands added to the script in a " +
                             l.label + " program next to it"));
    edit.push_back(
      action(l.label, "script_edit_" + l.name,
             "Edit the " + l.label + " program written next to the script"));
  }
  return menu("Also write",
              "Also write the commands added to the script as programs of "
              "the API",
              {group(write), menu("Edit program", "", edit)});
}

// a submenu of values of an option, each applied as it is chosen (the one
// the option has checked): {label, value}
static actionItem
presets(const std::string &label, const std::string &option,
        const std::vector<std::pair<std::string, std::string>> &values)
{
  std::vector<actionItem> items;
  for(auto &v : values)
    items.push_back(::option(v.first, option + "=" + v.second));
  return menu(label, "", items);
}
static std::vector<std::pair<std::string, std::string>> opacities()
{ return {{"100%", "1"}, {"75%", "0.75"}, {"50%", "0.5"}, {"25%", "0.25"}}; }

// The Geometry module: rows of buttons, a menu as a button that opens it
static actionItem geometryModule()
{
  std::vector<actionItem> script = {
    action("New", "model_new",
           "Make a new model, an empty script with the OpenCASCADE kernel"),
    action("Reload script", "script_reload", "Read the script again"),
    action("Edit script", "script_edit", "Edit the script"),
    action("Save script", "script_save", "Save the script (.geo)"),
    action("Remove last script command", "script_remove_last",
           "Take back the last command added to the script"),
    programsMenu(),
  };
  std::vector<actionItem> kernel = {
    action("Built-in", "kernel_builtin"),
    action("OpenCASCADE", "kernel_occ"),
  };
  std::vector<actionItem> add = {
    shape("Parameter", "add_parameter"),
    shape("Point", "add_point"),
    operation("Line", "add_line"),
    operation("Spline", "add_spline"),
    operation("Bezier", "add_bezier"),
    operation("B-Spline", "add_bspline"),
    shape("Circle", "add_circle"),
    operation("Circle arc", "add_circle_arc"),
    shape("Ellipse", "add_ellipse"),
    operation("Ellipse arc", "add_ellipse_arc"),
    shape("Rectangle", "add_rectangle"),
    shape("Disk", "add_disk"),
    operation("Plane surface", "add_plane_surface"),
    operation("Surface filling", "add_surface_filling"),
    shape("Sphere", "add_sphere"),
    shape("Cylinder", "add_cylinder"),
    shape("Box", "add_box"),
    shape("Torus", "add_torus"),
    shape("Cone", "add_cone"),
    shape("Wedge", "add_wedge"),
    operation("Volume", "add_volume"),
  };
  std::vector<actionItem> extrude = {
    operation("Translate", "extrude_translate"),
    operation("Rotate", "extrude_rotate"),
    operation("Pipe", "extrude_pipe"),
  };
  std::vector<actionItem> other = {
    operation("Fillet", "fillet"),
    operation("Split curve", "split_curve"),
  };
  std::vector<actionItem> transform = {
    operation("Translate", "translate"),
    operation("Rotate", "rotate"),
    operation("Scale", "scale"),
    operation("Symmetry", "symmetry"),
    menu("Extrude", "", extrude),
    menu("Other", "", other),
  };
  std::vector<actionItem> boolean = {
    operation("Intersection", "boolean_intersection"),
    operation("Union", "boolean_union"),
    operation("Difference", "boolean_difference"),
    operation("Fragments", "boolean_fragments"),
  };
  std::vector<actionItem> addPhysical = {
    operation("Point", "physical_add_point"),
    operation("Curve", "physical_add_curve"),
    operation("Surface", "physical_add_surface"),
    operation("Volume", "physical_add_volume"),
  };
  std::vector<actionItem> removePhysical = {
    operation("Point", "physical_remove_point"),
    operation("Curve", "physical_remove_curve"),
    operation("Surface", "physical_remove_surface"),
    operation("Volume", "physical_remove_volume"),
  };
  std::vector<actionItem> physical = {
    menu("Add", "", addPhysical),
    menu("Remove", "", removePhysical),
  };
  std::vector<actionItem> entities = {
    menu("Set kernel",
         "The geometry kernel of the entities added to the script after",
         kernel),
    menu("Add",
         "Add an entity to the script, from its values or from the entities "
         "picked in the scene",
         add),
    menu("Transform", "Transform the entities picked in the scene", transform),
    menu("Boolean", "Boolean operations on the entities picked in the scene",
         boolean),
    operation("Delete", "delete", "Delete the entities picked in the scene"),
    action("Coherence", "geometry_coherence",
           "Make the entities of the script coherent: merge the duplicates, or "
           "fragment all of them with OpenCASCADE"),
    menu("Physical groups",
         "Physical groups of the entities picked in the scene", physical),
  };
  return group({group(script), group(entities)});
}

// The Mesh module
static actionItem meshModule()
{
  std::vector<actionItem> generate = {
    action("1D", "mesh_1d", "Mesh the curves"),
    action("2D", "mesh_2d",
           "Mesh the surfaces (and the curves they are bounded by)"),
    action("3D", "mesh_3d", "Mesh the volumes (and what they are bounded by)"),
  };
  std::vector<actionItem> modify = {
    action("Refine by splitting", "mesh_refine",
           "Refine the mesh by splitting its elements"),
    action("Smooth", "mesh_smooth",
           "Smooth the mesh of the surfaces, then of the volumes"),
    action("Reclassify surfaces", "mesh_reclassify",
           "Reclassify the surface mesh into new surfaces, by the angle of its "
           "triangles"),
    action("Untangle mesh", "mesh_untangle", "Untangle the elements of the mesh"),
  };
  std::vector<actionItem> save = {
    action("Save", "mesh_save", "Save the mesh"),
  };
  std::vector<actionItem> transfinite = {
    operation("Curve", "define_transfinite_curve"),
    operation("Surface", "define_transfinite_surface"),
    operation("Volume", "define_transfinite_volume"),
  };
  std::vector<actionItem> embedded = {
    operation("Point", "define_embed_point"),
    operation("Curve", "define_embed_curve"),
    operation("Surface", "define_embed_surface"),
  };
  std::vector<actionItem> compound = {
    operation("Curve", "define_compound_curve"),
    operation("Surface", "define_compound_surface"),
  };
  std::vector<actionItem> define = {
    operation("Size at points", "define_size_at_points"),
    action("Size fields", "mesh_size_fields"),
    operation("Recombine", "define_recombine"),
    menu("Transfinite", "", transfinite),
    menu("Embedded", "", embedded),
    menu("Compound", "", compound),
  };
  std::vector<actionItem> highOrder = {
    action("Set order 1", "mesh_order_1"),
    action("Set order 2", "mesh_order_2"),
    action("Set order 3", "mesh_order_3"),
    action("High-order tools", "mesh_high_order_tools"),
  };
  std::vector<actionItem> reverse = {
    operation("Elements", "mesh_reverse_elements"),
    operation("Curves", "mesh_reverse_curves"),
    operation("Surfaces", "mesh_reverse_surfaces"),
    operation("Volumes", "mesh_reverse_volumes"),
  };
  std::vector<actionItem> remove = {
    action("All", "mesh_delete"),
    operation("Elements", "mesh_delete_elements"),
    operation("Curves", "mesh_delete_curves"),
    operation("Surfaces", "mesh_delete_surfaces"),
    operation("Volumes", "mesh_delete_volumes"),
  };
  std::vector<actionItem> quad = {
    action("Recombine triangles into quads", "mesh_recombine"),
    // (back once the cross field computation works, with its action)
    // action("Compute quad layout", "mesh_quad_layout"),
    action("Optimize quad topology", "mesh_optimize_quads"),
  };
  std::vector<actionItem> partitioning = {
    action("Partition", "mesh_partition"),
    action("Unpartition", "mesh_unpartition"),
    action("Convert old partitioning", "mesh_convert_partitioning"),
  };
  std::vector<actionItem> tools = {
    menu("Define",
         "Mesh sizes and constraints on the entities picked in the scene",
         define),
    menu("High order",
         "Make the mesh of order 1, 2 or 3, and the tools of high-order "
         "meshes",
         highOrder),
    menu("Reverse", "Reverse the elements picked in the scene", reverse),
    menu("Delete", "Delete the mesh, or the elements picked in the scene",
         remove),
    menu("Quad",
         "Quadrangles from the triangles, and the tools of quadrangle meshes",
         quad),
    menu("Partitioning", "Partition the mesh, or take its partitions away",
         partitioning),
  };
  return group({group(generate), group(modify), group(save), group(tools)});
}

// The quick access menu of the scene
static actionItem quickAccessMenu()
{
  std::vector<actionItem> split = {
    action("Horizontally", "window_split_horizontal"),
    action("Vertically", "window_split_vertical"),
    action("Unsplit", "window_unsplit"),
  };
  std::vector<actionItem> window = {
    action("Reset viewport", "scene_reset"),
    action("Select rotation center", "scene_rotation_center"),
    action("Query", "query"),
    action("Measure", "measure"),
    action("Full screen", "window_full_screen"),
    action("Install app", "app_install"),
    menu("Split window", "", split),
  };
  std::vector<actionItem> projection = {
    option("Orthographic", "General.Orthographic=1"),
    option("Perspective", "General.Orthographic=0"),
  };
  std::vector<actionItem> general = {
    action("Axes", "axes"),
    option("Hover mesh and views", "General.MouseHoverMeshes"),
    menu("Projection", "", projection),
    action("All general options...", "options_general"),
  };
  std::vector<actionItem> geometryVisibility = {
    option("Points", "Geometry.Points", "geometry_points"),
    option("Curves", "Geometry.Curves", "geometry_curves"),
    option("Surfaces", "Geometry.Surfaces", "geometry_surfaces"),
    option("Volumes", "Geometry.Volumes", "geometry_volumes"),
  };
  std::vector<actionItem> geometry = {
    menu("Geometry visibility", "", geometryVisibility),
    presets("Geometry opacity", "Geometry.Opacity", opacities()),
    action("All geometry options...", "options_geometry"),
  };
  std::vector<actionItem> meshVisibility = {
    option("Nodes", "Mesh.Nodes", "mesh_nodes"),
    option("1D elements", "Mesh.Lines", "mesh_lines"),
    option("2D element edges", "Mesh.SurfaceEdges", "mesh_surface_edges"),
    option("2D element faces", "Mesh.SurfaceFaces", "mesh_surface_faces"),
    option("3D element edges", "Mesh.VolumeEdges", "mesh_volume_edges"),
    option("3D element faces", "Mesh.VolumeFaces", "mesh_volume_faces"),
  };
  std::vector<std::pair<std::string, std::string>> sizeFactors = {
    {"0.25", "0.25"}, {"0.5", "0.5"}, {"1", "1"}, {"2", "2"}, {"4", "4"},
  };
  std::vector<actionItem> mesh = {
    menu("Mesh visibility", "", meshVisibility),
    action("Toggle mesh display", "mesh_toggle"),
    presets("Mesh opacity", "Mesh.Opacity", opacities()),
    presets("Global mesh size factor", "Mesh.MeshSizeFactor", sizeFactors),
    action("All mesh options...", "options_mesh"),
  };
  std::vector<actionItem> intervals = {
    option("Iso-values", "View.IntervalsType=1"),
    option("Continuous map", "View.IntervalsType=2"),
    option("Filled iso-values", "View.IntervalsType=3"),
    option("Numeric values", "View.IntervalsType=4"),
    option("Default range", "View.RangeType=1"),
    option("Range per time step", "View.RangeType=3"),
  };
  std::vector<actionItem> vectors = {
    option("Line", "View.VectorType=1"),
    option("3D arrow", "View.VectorType=4"),
    option("Displacement", "View.VectorType=5"),
    option("At barycenter", "View.GlyphLocation=1"),
    option("At node", "View.GlyphLocation=2"),
  };
  std::vector<actionItem> views = {
    option("View element outlines", "View.ShowElement", "view_elements"),
    menu("View intervals", "", intervals),
    menu("View vectors", "", vectors),
    presets("View opacity", "View.Opacity", opacities()),
    action("All view options...", "options_views"),
  };
  return group({group(window), group(general), group(geometry), group(mesh),
                group(views)});
}

// The menu of a view
static actionItem viewMenu()
{
  std::vector<actionItem> settings = {
    action("Options", "view_options"),
    action("Plugins", "view_plugins"),
  };
  std::vector<actionItem> reloadViews = {
    action("All", "views_reload_all"),
    action("Visible", "views_reload_visible"),
  };
  std::vector<actionItem> reload = {
    action("Reload", "view_reload"),
    menu("Reload views", "", reloadViews),
    action("Create alias", "view_alias"),
  };
  std::vector<actionItem> removeViews = {
    action("All", "views_remove_all"),
    action("Visible", "views_remove_visible"),
    action("Invisible", "views_remove_invisible"),
    action("Other", "views_remove_others"),
    action("Empty", "views_remove_empty"),
    action("With same name", "views_remove_same_name"),
  };
  std::vector<actionItem> remove = {
    action("Remove", "view_remove"),
    menu("Remove views", "", removeViews),
  };
  std::vector<actionItem> visibility = {
    action("All on", "views_show_all"),
    action("All off", "views_hide_all"),
    action("Invert", "views_show_inverted"),
    action("Same name on", "views_show_same_name"),
  };
  std::vector<actionItem> combineElements = {
    action("From all views", "views_combine_elements_all"),
    action("From visible views", "views_combine_elements_visible"),
    action("From all views with same name", "views_combine_elements_same_name"),
  };
  std::vector<actionItem> combineSteps = {
    action("From all views", "views_combine_steps_all"),
    action("From visible views", "views_combine_steps_visible"),
    action("From all views with same name", "views_combine_steps_same_name"),
  };
  std::vector<actionItem> arrange = {
    action("Sort by name", "views_sort"),
    menu("Set visibility", "", visibility),
    menu("Combine elements", "", combineElements),
    menu("Combine time steps", "", combineSteps),
  };
  std::vector<actionItem> use = {
    action("Apply as background mesh", "view_background_mesh"),
    action("Export...", "view_export"),
    action("Export as .pos", "view_export_pos"),
    action("Export as .msh", "view_export_msh"),
  };
  return group({group(settings), group(reload), group(remove), group(arrange),
                group(use)});
}

// The menu bar of the graphical interface: actions it does itself, named as
// their shortcuts (see Shortcuts.h), but those of the menus above
static actionItem menuBar()
{
  std::vector<actionItem> remote = {
    action("Start...", "remote_start"),
    action("Merge...", "remote_merge"),
    action("Clear", "remote_clear"),
    action("Stop", "remote_stop"),
  };
  std::vector<actionItem> file = {
    group({
      action("New...", "file_new"),
      action("Open...", "file_open"),
      action("Open Recent", "recent_files"),
      action("Merge...", "file_merge"),
      action("Watch Pattern...", "watch"),
    }),
    group({
      action("Clear", "file_clear"),
      action("Rename...", "file_rename"),
      action("Delete", "file_delete"),
    }),
    group({menu("Remote", "", remote)}),
    group({
      action("Save Mesh", "mesh_save"),
      action("Save Model Options", "options_save"),
      action("Save Options As Default", "options_save_default"),
    }),
    group({action("Export...", "file_export")}),
    group({action("Quit", "quit")}),
  };
  std::vector<actionItem> tools = {
    group({
      action("Options", "options"),
      action("Plugins", "plugins"),
      action("Visibility", "visibility"),
      action("Clipping", "clipping"),
      action("Manipulator", "manipulator"),
    }),
    group({action("3M", "window_3m")}),
    group({
      action("Statistics", "statistics"),
      action("Message Console", "console"),
    }),
  };
  std::vector<actionItem> window = {
    group({action("New Window", "window_new")}),
    group({action("Copy to Clipboard", "window_copy")}),
    group({
      action("Split Horizontally", "window_split_horizontal"),
      action("Split Vertically", "window_split_vertical"),
      action("Unsplit", "window_unsplit"),
    }),
    group({
      action("Minimize", "minimize"),
      action("Zoom", "window_zoom"),
      action("Enter Full Screen", "window_full_screen"),
    }),
    group({
      action("Show/Hide Menu", "menu_show_hide"),
      action("Attach/Detach Menu", "menu_attach_detach"),
      action("Dock/Undock Tool Window", "dock"),
      action("Dock/Undock All Tool Windows", "dock_all"),
    }),
    group({action("Bring All to Front", "window_front")}),
  };
  std::vector<actionItem> help = {
    group({action("Online Documentation", "help_online")}),
    group({action("Keyboard and Mouse Usage", "help_keys")}),
    group({
      action("Current Options and Workspace", "help_options"),
      action("Restore all Options to Default Settings",
             "options_restore_defaults"),
    }),
    group({action("About Gmsh", "help_about")}),
  };
  return group({
    menu("File", "", file),
    menu("Tools", "", tools),
    menu("Window", "", window),
    menu("Help", "", help),
  });
}

static const std::map<std::string, actionItem> &menus()
{
  static const std::map<std::string, actionItem> menus = {
    {"Geometry", geometryModule()},
    {"Mesh", meshModule()},
    {"Quick access", quickAccessMenu()},
    {"View", viewMenu()},
    {"Menu bar", menuBar()},
  };
  return menus;
}

const actionItem &GetActionMenu(const std::string &name)
{
  static const actionItem none = group({});
  auto it = menus().find(name);
  return it == menus().end() ? none : it->second;
}

// The actions

static std::string scriptFile() { return GModel::current()->getFileName(); }

#if defined(HAVE_MESH)
// an operation on the mesh, not during another operation on the model
static int meshOperation(const std::function<void(GModel *)> &f)
{
  modelLock lock(modelLock::ifFree);
  if(!lock) return ActionDone;
  f(GModel::current());
  CTX::instance()->meshChanged();
  return ActionDone;
}

static int setOrder(int order)
{
  return meshOperation([order](GModel *m) {
    m->setOrderN(order, CTX::instance()->mesh.secondOrderLinear,
                 CTX::instance()->mesh.secondOrderIncomplete,
                 CTX::instance()->mesh.meshOnlyVisible);
  });
}

// the partitions changed: each shown in its colour, or none
static int partitionsChanged(int error)
{
  if(error) return ActionDone;
  opt_mesh_zone_definition(0, GMSH_SET, 0.);
  opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 1.);
  CTX::instance()->meshChanged();
  return ActionDone | ActionModelChanged;
}
#endif

#if defined(HAVE_POST)
// the views removed (from the last), if remove(i)
static int removeViews(const std::function<bool(int i)> &remove)
{
  for(int i = (int)PView::list.size() - 1; i >= 0; i--)
    if(remove(i)) delete PView::list[i];
  return ActionDone | ActionViewsChanged;
}

static bool isViewVisible(int i) { return opt_view_visible(i, GMSH_GET, 0); }

static std::string viewName(int i)
{
  if(i < 0 || i >= (int)PView::list.size()) return "";
  return PView::list[i]->getData()->getName();
}

// each view shown if show(i)
static int showViews(const std::function<bool(int i)> &show)
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    opt_view_visible(i, GMSH_SET | GMSH_GUI, show(i));
  return ActionDone;
}

// the elements (or the time steps, if time) of views combined: of all the
// views (how = 1), the visible ones (0), or those of the same name (2)
static int combineViews(bool time, int how)
{
  PView::combine(time, how, CTX::instance()->post.combineRemoveOrig,
                 CTX::instance()->post.combineCopyOptions);
  return ActionDone | ActionViewsChanged;
}

// a view read again from its file, the new data replacing the old one in the
// view and in every view sharing it (its aliases, or the view it is an alias
// of)
static int reloadView(int index)
{
  if(index < 0 || index >= (int)PView::list.size()) return ActionDone;
  PView *p = PView::list[index];
  // copied: reading processes events, during which the view may go
  std::string fileName = p->getData()->getFileName();
  if(StatFile(fileName)) {
    Msg::Error("File '%s' does not exist", fileName.c_str());
    return ActionDone;
  }
  int tag = p->getTag();
  std::size_t n = PView::list.size();
  {
    // not during another operation on the model, which reading may change
    modelLock lock(modelLock::ifFree);
    if(!lock) return ActionDone;
    MergeFile(fileName);
  }
  p = PView::getViewByTag(tag);
  if(!p || PView::list.size() <= n) return ActionDone;
  PViewData *old = p->getData(), *data = PView::list.back()->getData();
  PView::list.back()->setData(nullptr);
  delete PView::list.back();
  for(PView *v : PView::list) {
    if(v->getData() != old) continue;
    v->setData(data);
    // in case the reloaded view has a different number of time steps
    if(v->getOptions()->timeStep > data->getNumTimeSteps() - 1)
      v->getOptions()->timeStep = 0;
    v->setChanged(true);
  }
  delete old;
  return ActionDone | ActionViewsChanged;
}

static int reloadViews(const std::function<bool(int i)> &reload)
{
  int ret = ActionDone;
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(reload(i)) ret |= reloadView(i);
  return ret;
}
#endif

static bool haveViews()
{
#if defined(HAVE_POST)
  return !PView::list.empty();
#else
  return false;
#endif
}

// the axes on or off, fitted to the model and the visible views when on
static int toggleAxes()
{
  if(opt_general_axes(0, GMSH_GET, 0)) {
    opt_general_axes(0, GMSH_SET | GMSH_GUI, 0);
    return ActionDone;
  }
  opt_general_axes(0, GMSH_SET | GMSH_GUI, 3);
  opt_general_axes_auto_position(0, GMSH_SET | GMSH_GUI, 0);
  SBoundingBox3d bbox = GModel::current()->bounds(true);
#if defined(HAVE_POST)
  for(PView *v : PView::list)
    if(v->getOptions()->visible && !v->getData()->getBoundingBox().empty())
      bbox += v->getData()->getBoundingBox();
#endif
  CTX *c = CTX::instance();
  if(bbox.empty())
    bbox = SBoundingBox3d(c->min[0], c->min[1], c->min[2], c->max[0], c->max[1],
                          c->max[2]);
  opt_general_axes_xmin(0, GMSH_SET | GMSH_GUI, bbox.min().x());
  opt_general_axes_ymin(0, GMSH_SET | GMSH_GUI, bbox.min().y());
  opt_general_axes_zmin(0, GMSH_SET | GMSH_GUI, bbox.min().z());
  opt_general_axes_xmax(0, GMSH_SET | GMSH_GUI, bbox.max().x());
  opt_general_axes_ymax(0, GMSH_SET | GMSH_GUI, bbox.max().y());
  opt_general_axes_zmax(0, GMSH_SET | GMSH_GUI, bbox.max().z());
  return ActionDone;
}

// what an action does: view is the index of the view of a menu of a view,
// ctx the scene
typedef std::function<int(int view, drawContext *ctx)> actionFunction;

// an action: what it does here (nothing if each interface does it), when it
// applies (always if not said), and its check mark (none if not said)
struct actionEntry {
  actionFunction run;
  std::function<bool()> available;
  std::function<int()> check;
};

static const std::map<std::string, actionEntry> &listedActions()
{
  static const std::map<std::string, actionEntry> actions = {
    // the script
    {"script_remove_last", {[](int, drawContext *) {
       scriptRemoveLastCommand(scriptFile());
       return ActionDone | ActionModelChanged;
     }}},
    {"kernel_builtin", {[](int, drawContext *) {
       scriptSetFactory("Built-in", scriptFile());
       return ActionDone;
     }}},
    {"kernel_occ", {[](int, drawContext *) {
       scriptSetFactory("OpenCASCADE", scriptFile());
       return ActionDone;
     }}},
    {"geometry_coherence", {[](int, drawContext *) {
       scriptCoherence(scriptFile());
       return ActionDone | ActionModelChanged;
     }}},
    // the mesh
#if defined(HAVE_MESH)
    {"mesh_1d", {[](int, drawContext *) {
       GModel::current()->mesh(1);
       return ActionDone;
     }}},
    {"mesh_2d", {[](int, drawContext *) {
       GModel::current()->mesh(2);
       return ActionDone;
     }}},
    {"mesh_3d", {[](int, drawContext *) {
       GModel::current()->mesh(3);
       return ActionDone;
     }}},
    {"mesh_refine", {[](int, drawContext *) {
       return meshOperation([](GModel *m) {
         int split = CTX::instance()->mesh.algoSubdivide;
         m->refineMesh(CTX::instance()->mesh.secondOrderLinear, split == 1,
                       split == 2, split == 3);
       });
     }}},
    {"mesh_smooth", {[](int, drawContext *) {
       return meshOperation([](GModel *m) {
         m->optimizeMesh("Laplace2D");
         m->optimizeMesh("Relocate3D");
       });
     }}},
    {"mesh_untangle", {[](int, drawContext *) {
       return meshOperation(
         [](GModel *m) { m->optimizeMesh("UntangleMeshGeometry"); });
     }}},
    {"mesh_delete", {[](int, drawContext *) {
       return meshOperation([](GModel *m) { m->deleteMesh(); });
     }}},
    {"mesh_order_1", {[](int, drawContext *) { return setOrder(1); }}},
    {"mesh_order_2", {[](int, drawContext *) { return setOrder(2); }}},
    {"mesh_order_3", {[](int, drawContext *) { return setOrder(3); }}},
    {"mesh_recombine", {[](int, drawContext *) {
       return meshOperation([](GModel *m) { m->recombineMesh(); });
     }}},
    // (back with its item, once the cross field computation works)
    // {"mesh_quad_layout",
    //  {[](int, drawContext *) {
    //    return meshOperation([](GModel *m) {
    //      std::vector<int> tags;
    //      computeCrossField(m, tags);
    //    });
    //  }}},
    {"mesh_optimize_quads", {[](int, drawContext *) {
       return meshOperation(
         [](GModel *m) { m->optimizeMesh("QuadQuasiStructured"); });
     }}},
    {"mesh_unpartition", {[](int, drawContext *) {
       modelLock lock(modelLock::ifFree);
       if(!lock) return (int)ActionDone;
       return partitionsChanged(GModel::current()->unpartitionMesh());
     }}},
    {"mesh_convert_partitioning", {[](int, drawContext *) {
       modelLock lock(modelLock::ifFree);
       if(!lock) return (int)ActionDone;
       return partitionsChanged(
         GModel::current()->convertOldPartitioningToNewOne());
     }}},
#endif
    // the scene
    {"scene_reset", {[](int, drawContext *ctx) {
       RunSceneShortcut("view_z", 0, ctx);
       RunSceneShortcut("view_1_1", 0, ctx);
       return ActionDone;
     }}},
    {"axes",
     {[](int, drawContext *) { return toggleAxes(); }, nullptr,
      // (what the toggle changes: the model's axes, not those of the views)
      [] { return opt_general_axes(0, GMSH_GET, 0) ? 1 : 0; }}},
    {"mesh_toggle", {[](int, drawContext *ctx) {
       RunSceneShortcut("mesh_toggle", 0, ctx);
       return ActionDone;
     }}},
    {"options_views", {nullptr, haveViews}},
    // the views
#if defined(HAVE_POST)
    {"view_reload", {[](int view, drawContext *) { return reloadView(view); }}},
    {"views_reload_all", {[](int, drawContext *) {
       return reloadViews([](int) { return true; });
     }}},
    {"views_reload_visible",
     {[](int, drawContext *) { return reloadViews(isViewVisible); }}},
    {"view_alias", {[](int view, drawContext *) {
       if(view < 0 || view >= (int)PView::list.size()) return (int)ActionDone;
       new PView(PView::list[view], true); // with its options
       return ActionDone | ActionViewsChanged;
     }}},
    {"view_remove", {[](int view, drawContext *) {
       return removeViews([view](int i) { return i == view; });
     }}},
    {"views_remove_all", {[](int, drawContext *) {
       return removeViews([](int) { return true; });
     }}},
    {"views_remove_visible",
     {[](int, drawContext *) { return removeViews(isViewVisible); }}},
    {"views_remove_invisible", {[](int, drawContext *) {
       return removeViews([](int i) { return !isViewVisible(i); });
     }}},
    {"views_remove_others", {[](int view, drawContext *) {
       return removeViews([view](int i) { return i != view; });
     }}},
    {"views_remove_empty", {[](int, drawContext *) {
       return removeViews(
         [](int i) { return PView::list[i]->getData()->empty(); });
     }}},
    {"views_remove_same_name", {[](int view, drawContext *) {
       std::string name = viewName(view);
       return removeViews([name](int i) { return viewName(i) == name; });
     }}},
    {"views_sort", {[](int, drawContext *) {
       PView::sortByName();
       return ActionDone | ActionViewsChanged;
     }}},
    {"views_show_all",
     {[](int, drawContext *) { return showViews([](int) { return true; }); }}},
    {"views_hide_all",
     {[](int, drawContext *) { return showViews([](int) { return false; }); }}},
    {"views_show_inverted", {[](int, drawContext *) {
       return showViews([](int i) { return !isViewVisible(i); });
     }}},
    {"views_show_same_name", {[](int view, drawContext *) {
       std::string name = viewName(view);
       return showViews([name](int i) { return viewName(i) == name; });
     }}},
    {"views_combine_elements_all",
     {[](int, drawContext *) { return combineViews(false, 1); }}},
    {"views_combine_elements_visible",
     {[](int, drawContext *) { return combineViews(false, 0); }}},
    {"views_combine_elements_same_name",
     {[](int, drawContext *) { return combineViews(false, 2); }}},
    {"views_combine_steps_all",
     {[](int, drawContext *) { return combineViews(true, 1); }}},
    {"views_combine_steps_visible",
     {[](int, drawContext *) { return combineViews(true, 0); }}},
    {"views_combine_steps_same_name",
     {[](int, drawContext *) { return combineViews(true, 2); }}},
#if defined(HAVE_MESH)
    {"view_background_mesh", {[](int view, drawContext *) {
       if(view >= 0 && view < (int)PView::list.size())
         GModel::current()->getFields()->setBackgroundMesh(view);
       return ActionDone;
     }}},
#endif
#endif
  };
  return actions;
}

// the actions of the table, and those of the programs of the script: written
// or not (checked), and edited by the interfaces, once there is one
static const std::map<std::string, actionEntry> &actions()
{
  static const std::map<std::string, actionEntry> all = [] {
    std::map<std::string, actionEntry> m = listedActions();
    for(auto &l : scriptLanguages()) {
      std::string lang = l.name;
      m["script_write_" + l.name] = {
        [lang](int, drawContext *) {
          scriptWriteIn(lang, !scriptWritesIn(lang));
          return (int)ActionDone;
        },
        nullptr, [lang] { return scriptWritesIn(lang) ? 1 : 0; }};
      m["script_edit_" + l.name] = {
        nullptr, [lang] {
          return scriptWritesIn(lang) &&
                 !StatFile(scriptProgram(scriptFile(), lang));
        }};
    }
    return m;
  }();
  return all;
}

// The options

// "Category.Name" or "Category.Name=value": the category, the name, the value
// (none for a toggle), and the indices the option is set for: 0, or the
// visible views for View
namespace {
  struct itemOption {
    std::string category, name;
    double value;
    bool toggle;
    std::vector<int> indices;
    // the value at the first index, shown for all
    double current() const
    {
      double v = 0.;
      if(!indices.empty())
        NumberOption(GMSH_GET, category.c_str(), indices[0], name.c_str(), v,
                     false);
      return v;
    }
  };
} // namespace

static itemOption parseOption(const std::string &option)
{
  itemOption o;
  std::string::size_type dot = option.find('.'), eq = option.find('=');
  o.category = option.substr(0, dot);
  o.name = option.substr(dot + 1, eq == std::string::npos ? eq : eq - dot - 1);
  o.toggle = (eq == std::string::npos);
  o.value = o.toggle ? 0. : atof(option.substr(eq + 1).c_str());
  if(o.category != "View") o.indices.push_back(0);
#if defined(HAVE_POST)
  else
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(isViewVisible(i)) o.indices.push_back(i);
#endif
  return o;
}

static void setOption(const std::string &option, double value)
{
  itemOption o = parseOption(option);
  for(int i : o.indices)
    NumberOption(GMSH_SET | GMSH_GUI, o.category.c_str(), i, o.name.c_str(),
                 value, false);
}

bool HasAction(const std::string &name) { return actions().count(name) > 0; }

bool IsItemDoneByInterface(const actionItem &item)
{
  if(item.kind == ItemOperation || item.kind == ItemShape) return true;
  if(item.kind != ItemAction) return false;
  auto it = actions().find(item.name);
  return it == actions().end() || !it->second.run;
}

int RunItem(const actionItem &item, int view, drawContext *ctx)
{
  if(item.kind == ItemOption) {
    itemOption o = parseOption(item.name);
    if(o.indices.empty()) return ActionDone;
    setOption(item.name, o.toggle ? !o.current() : o.value);
    return ActionDone;
  }
  if(item.kind != ItemAction) return ActionByInterface;
  auto it = actions().find(item.name);
  if(it == actions().end() || !it->second.run) return ActionByInterface;
  return it->second.run(view, ctx);
}

bool IsItemAvailable(const actionItem &item)
{
  if(item.kind == ItemOption) {
    return item.name.compare(0, 5, "View.") || haveViews();
  }
  if(item.kind != ItemAction) return true;
  // (an action not in the table is done by the interfaces, which say whether
  // they do it)
  auto it = actions().find(item.name);
  return it == actions().end() || !it->second.available ||
         it->second.available();
}

int GetItemCheck(const actionItem &item)
{
  if(item.kind == ItemOption && !item.name.empty()) {
    itemOption o = parseOption(item.name);
    if(o.indices.empty()) return 0;
    double v = o.current();
    return o.toggle ? (v != 0.) : (v == o.value);
  }
  if(item.kind != ItemAction) return -1;
  auto it = actions().find(item.name);
  if(it == actions().end() || !it->second.check) return -1;
  return it->second.check();
}
