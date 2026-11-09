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

// ---------------------------------------------------------------------------
// The menus

// a menu, and a group of items set apart (a menu without label)
static actionItem menu(const std::string &label, const std::string &help,
                       const std::vector<actionItem> &items)
{ return {label, ActionMenu, "", items, help, ""}; }
static actionItem group(const std::vector<actionItem> &items)
{ return menu("", "", items); }
// an action of the table (named as its label if no name is given)
static actionItem run(const std::string &label, const std::string &name = "",
                      const std::string &help = "", const std::string &key = "")
{ return {label, ActionRun, name.empty() ? label : name, {}, help, key}; }
// an operation on the entities picked
static actionItem op(const std::string &label, const std::string &name = "",
                     const std::string &help = "")
{ return {label, ActionOperation, name.empty() ? label : name, {}, help, ""}; }
// a shape, named as its label
static actionItem shape(const std::string &label)
{ return {label, ActionShape, label, {}, "", ""}; }
// an option toggled or set
static actionItem option(const std::string &label, const std::string &name,
                         const std::string &key = "")
{ return {label, ActionOption, name, {}, "", key}; }

// the programs the commands added to the script are also written in (see
// General.ScriptingLanguages), and their edition
static actionItem programsMenu()
{
  std::vector<actionItem> write, edit;
  for(auto &l : scriptLanguages()) {
    write.push_back(run(l.label, "Write " + l.label + " program",
                        "Also write the commands added to the script in a " +
                          l.label + " program next to it"));
    edit.push_back(
      run(l.label, "Edit " + l.label + " program",
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

static const std::map<std::string, actionItem> &menus()
{
  static const std::map<std::string, actionItem> menus = {
    {"Geometry",
     group(
       {group({run("New", "New model",
                   "Make a new model, an empty script with the OpenCASCADE "
                   "kernel"),
               run("Reload script", "", "Read the script again"),
               run("Edit script", "", "Edit the script"),
               run("Save script", "", "Save the script (.geo)"),
               run("Remove last script command", "",
                   "Take back the last command added to the script"),
               programsMenu()}),
        group(
          {menu("Set kernel",
                "The geometry kernel of the entities added to the script after",
                {run("Built-in", "Set kernel Built-in"),
                 run("OpenCASCADE", "Set kernel OpenCASCADE")}),
           menu("Add",
                "Add an entity to the script, from its values or from the "
                "entities picked in the scene",
                {shape("Parameter"),
                 shape("Point"),
                 op("Line"),
                 op("Spline"),
                 op("Bezier"),
                 op("B-Spline", "BSpline"),
                 shape("Circle"),
                 op("Circle arc"),
                 shape("Ellipse"),
                 op("Ellipse arc"),
                 shape("Rectangle"),
                 shape("Disk"),
                 op("Plane surface", "Plane Surface"),
                 op("Surface filling", "Surface"),
                 shape("Sphere"),
                 shape("Cylinder"),
                 shape("Box"),
                 shape("Torus"),
                 shape("Cone"),
                 shape("Wedge"),
                 op("Volume")}),
           menu("Transform", "Transform the entities picked in the scene",
                {op("Translate"), op("Rotate"), op("Scale"), op("Symmetry"),
                 menu("Extrude", "",
                      {op("Translate", "Extrude translate"),
                       op("Rotate", "Extrude rotate"), op("Pipe")}),
                 menu("Other", "", {op("Fillet"), op("Split curve")})}),
           menu("Boolean",
                "Boolean operations on the entities picked in the scene",
                {op("Intersection", "BooleanIntersection"),
                 op("Union", "BooleanUnion"),
                 op("Difference", "BooleanDifference"),
                 op("Fragments", "BooleanFragments")}),
           op("Delete", "", "Delete the entities picked in the scene"),
           run("Coherence", "",
               "Make the entities of the script coherent: merge the "
               "duplicates, or fragment all of them with OpenCASCADE"),
           menu("Physical groups",
                "Physical groups of the entities picked in the scene",
                {menu("Add", "",
                      {op("Point", "Physical Point"),
                       op("Curve", "Physical Curve"),
                       op("Surface", "Physical Surface"),
                       op("Volume", "Physical Volume")}),
                 menu("Remove", "",
                      {op("Point", "Remove Physical Point"),
                       op("Curve", "Remove Physical Curve"),
                       op("Surface", "Remove Physical Surface"),
                       op("Volume", "Remove Physical Volume")})})})})},
    {"Mesh",
     group(
       {group({run("1D", "Mesh 1D", "Mesh the curves"),
               run("2D", "Mesh 2D",
                   "Mesh the surfaces (and the curves they are bounded by)"),
               run("3D", "Mesh 3D",
                   "Mesh the volumes (and what they are bounded by)")}),
        group({run("Refine by splitting", "Refine mesh",
                   "Refine the mesh by splitting its elements"),
               run("Smooth", "Smooth mesh",
                   "Smooth the mesh of the surfaces, then of the volumes"),
               run("Reclassify surfaces", "",
                   "Reclassify the surface mesh into new surfaces, by the "
                   "angle of its triangles"),
               run("Untangle mesh", "", "Untangle the elements of the mesh")}),
        group({run("Save", "Save mesh", "Save the mesh")}),
        group(
          {menu(
             "Define",
             "Mesh sizes and constraints on the entities picked in the scene",
             {op("Size at points"), run("Size fields"), op("Recombine"),
              menu("Transfinite", "",
                   {op("Curve", "Transfinite Curve"),
                    op("Surface", "Transfinite Surface"),
                    op("Volume", "Transfinite Volume")}),
              menu("Embedded", "",
                   {op("Point", "Embed Point"), op("Curve", "Embed Curve"),
                    op("Surface", "Embed Surface")}),
              menu("Compound", "",
                   {op("Curve", "Compound Curve"),
                    op("Surface", "Compound Surface")})}),
           menu("High order",
                "Make the mesh of order 1, 2 or 3, and the tools of "
                "high-order meshes",
                {run("Set order 1"), run("Set order 2"), run("Set order 3"),
                 run("High-order tools")}),
           menu("Reverse", "Reverse the elements picked in the scene",
                {op("Elements", "Reverse mesh elements"),
                 op("Curves", "Reverse mesh curves"),
                 op("Surfaces", "Reverse mesh surfaces"),
                 op("Volumes", "Reverse mesh volumes")}),
           menu(
             "Delete", "Delete the mesh, or the elements picked in the scene",
             {run("All", "Delete mesh"), op("Elements", "Delete mesh elements"),
              op("Curves", "Delete mesh curves"),
              op("Surfaces", "Delete mesh surfaces"),
              op("Volumes", "Delete mesh volumes")}),
           menu("Quad",
                "Quadrangles from the triangles, and the tools of quadrangle "
                "meshes",
                {run("Recombine triangles into quads", "Recombine mesh"),
                 // (back once the cross field computation works, with its
                 // action)
                 // run("Compute quad layout"),
                 run("Optimize quad topology")}),
           menu("Partitioning",
                "Partition the mesh, or take its partitions away",
                {run("Partition", "Partition mesh"),
                 run("Unpartition", "Unpartition mesh"),
                 run("Convert old partitioning")})})})},
    {"Quick access",
     group(
       {group({run("Reset viewport"), run("Select rotation center"),
               run("Query"), run("Measure"), run("Full screen"),
               run("Install app"),
               menu("Split window", "",
                    {run("Horizontally", "Split window horizontally"),
                     run("Vertically", "Split window vertically"),
                     run("Unsplit", "Unsplit window")})}),
        group({run("Axes"),
               option("Hover mesh and views", "General.MouseHoverMeshes"),
               menu("Projection", "",
                    {option("Orthographic", "General.Orthographic=1"),
                     option("Perspective", "General.Orthographic=0")}),
               run("All general options...", "General options")}),
        group(
          {menu("Geometry visibility", "",
                {option("Points", "Geometry.Points", "geometry_points"),
                 option("Curves", "Geometry.Curves", "geometry_curves"),
                 option("Surfaces", "Geometry.Surfaces", "geometry_surfaces"),
                 option("Volumes", "Geometry.Volumes", "geometry_volumes")}),
           presets("Geometry opacity", "Geometry.Opacity", opacities()),
           run("All geometry options...", "Geometry options")}),
        group({menu("Mesh visibility", "",
                    {option("Nodes", "Mesh.Nodes", "mesh_nodes"),
                     option("1D elements", "Mesh.Lines", "mesh_lines"),
                     option("2D element edges", "Mesh.SurfaceEdges",
                            "mesh_surface_edges"),
                     option("2D element faces", "Mesh.SurfaceFaces",
                            "mesh_surface_faces"),
                     option("3D element edges", "Mesh.VolumeEdges",
                            "mesh_volume_edges"),
                     option("3D element faces", "Mesh.VolumeFaces",
                            "mesh_volume_faces")}),
               run("Toggle mesh display"),
               presets("Mesh opacity", "Mesh.Opacity", opacities()),
               presets("Global mesh size factor", "Mesh.MeshSizeFactor",
                       {{"0.25", "0.25"}, {"0.5", "0.5"}, {"1", "1"},
                        {"2", "2"}, {"4", "4"}}),
               run("All mesh options...", "Mesh options")}),
        group(
          {option("View element outlines", "View.ShowElement", "view_elements"),
           menu("View intervals", "",
                {option("Iso-values", "View.IntervalsType=1"),
                 option("Continuous map", "View.IntervalsType=2"),
                 option("Filled iso-values", "View.IntervalsType=3"),
                 option("Numeric values", "View.IntervalsType=4"),
                 option("Default range", "View.RangeType=1"),
                 option("Range per time step", "View.RangeType=3")}),
           menu("View vectors", "",
                {option("Line", "View.VectorType=1"),
                 option("3D arrow", "View.VectorType=4"),
                 option("Displacement", "View.VectorType=5"),
                 option("At barycenter", "View.GlyphLocation=1"),
                 option("At node", "View.GlyphLocation=2")}),
           presets("View opacity", "View.Opacity", opacities()),
           run("All view options...", "All view options")})})},
    {"View",
     group(
       {group({run("Options", "View options"), run("Plugins", "View plugins")}),
        group({run("Reload", "Reload view"),
               menu("Reload views", "",
                    {run("All", "Reload all views"),
                     run("Visible", "Reload visible views")}),
               run("Create alias", "Create view alias")}),
        group({run("Remove", "Remove view"),
               menu("Remove views", "",
                    {run("All", "Remove all views"),
                     run("Visible", "Remove visible views"),
                     run("Invisible", "Remove invisible views"),
                     run("Other", "Remove other views"),
                     run("Empty", "Remove empty views"),
                     run("With same name", "Remove views with same name")})}),
        group(
          {run("Sort by name", "Sort views by name"),
           menu("Set visibility", "",
                {run("All on", "Show all views"),
                 run("All off", "Hide all views"),
                 run("Invert", "Invert view visibility"),
                 run("Same name on", "Show views with same name")}),
           menu("Combine elements", "",
                {run("From all views", "Combine elements of all views"),
                 run("From visible views", "Combine elements of visible views"),
                 run("From all views with same name",
                     "Combine elements of views with same name")}),
           menu(
             "Combine time steps", "",
             {run("From all views", "Combine time steps of all views"),
              run("From visible views", "Combine time steps of visible views"),
              run("From all views with same name",
                  "Combine time steps of views with same name")})}),
        group({run("Apply as background mesh", "Apply view as background mesh"),
               run("Export...", "Export view"),
               run("Export as .pos", "Export view as .pos"),
               run("Export as .msh", "Export view as .msh")})})},
    // the menu bar of the graphical interface: actions it does itself, named
    // as their shortcuts (see Shortcuts.h), but those of the menus above
    {"Menu bar",
     group(
       {menu("File", "",
             {group({run("New...", "file_new"), run("Open...", "file_open"),
                     run("Open Recent", "recent_files"),
                     run("Merge...", "file_merge"),
                     run("Watch Pattern...", "watch")}),
              group({run("Clear", "file_clear"),
                     run("Rename...", "file_rename"),
                     run("Delete", "file_delete")}),
              group({menu("Remote", "",
                          {run("Start...", "remote_start"),
                           run("Merge...", "remote_merge"),
                           run("Clear", "remote_clear"),
                           run("Stop", "remote_stop")})}),
              group({run("Save Mesh", "Save mesh"),
                     run("Save Model Options", "options_save"),
                     run("Save Options As Default", "options_save_default")}),
              group({run("Export...", "file_export")}),
              group({run("Quit", "quit")})}),
        menu("Tools", "",
             {group({run("Options", "options"), run("Plugins", "plugins"),
                     run("Visibility", "visibility"),
                     run("Clipping", "clipping"),
                     run("Manipulator", "manipulator")}),
              group({run("3M", "window_3m")}),
              group({run("Statistics", "statistics"),
                     run("Message Console", "console")})}),
        menu("Window", "",
             {group({run("New Window", "window_new")}),
              group({run("Copy to Clipboard", "window_copy")}),
              group({run("Split Horizontally", "Split window horizontally"),
                     run("Split Vertically", "Split window vertically"),
                     run("Unsplit", "Unsplit window")}),
              group({run("Minimize", "minimize"),
                     run("Zoom", "window_zoom"),
                     run("Enter Full Screen", "Full screen")}),
              group({run("Show/Hide Menu", "menu_show_hide"),
                     run("Attach/Detach Menu", "menu_attach_detach"),
                     run("Dock/Undock Tool Window", "dock"),
                     run("Dock/Undock All Tool Windows", "dock_all")}),
              group({run("Bring All to Front", "window_front")})}),
        menu("Help", "",
             {group({run("Online Documentation", "help_online")}),
              group({run("Keyboard and Mouse Usage", "help_keys")}),
              group({run("Current Options and Workspace", "help_options"),
                     run("Restore all Options to Default Settings",
                         "options_restore_defaults")}),
              group({run("About Gmsh", "help_about")})})})}};
  return menus;
}

const actionItem &GetActionMenu(const std::string &name)
{
  static const actionItem none = group({});
  auto it = menus().find(name);
  return it == menus().end() ? none : it->second;
}

// ---------------------------------------------------------------------------
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

static bool visibleView(int i) { return opt_view_visible(i, GMSH_GET, 0); }

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
struct action {
  actionFunction run;
  std::function<bool()> available;
  std::function<int()> check;
};

static const std::map<std::string, action> &tableActions()
{
  static const std::map<std::string, action> actions = {
    // the script
    {"Remove last script command", {[](int, drawContext *) {
       scriptRemoveLastCommand(scriptFile());
       return ActionDone | ActionModelChanged;
     }}},
    {"Set kernel Built-in", {[](int, drawContext *) {
       scriptSetFactory("Built-in", scriptFile());
       return ActionDone;
     }}},
    {"Set kernel OpenCASCADE", {[](int, drawContext *) {
       scriptSetFactory("OpenCASCADE", scriptFile());
       return ActionDone;
     }}},
    {"Coherence", {[](int, drawContext *) {
       scriptCoherence(scriptFile());
       return ActionDone | ActionModelChanged;
     }}},
    // the mesh
#if defined(HAVE_MESH)
    {"Mesh 1D", {[](int, drawContext *) {
       GModel::current()->mesh(1);
       return ActionDone;
     }}},
    {"Mesh 2D", {[](int, drawContext *) {
       GModel::current()->mesh(2);
       return ActionDone;
     }}},
    {"Mesh 3D", {[](int, drawContext *) {
       GModel::current()->mesh(3);
       return ActionDone;
     }}},
    {"Refine mesh", {[](int, drawContext *) {
       return meshOperation([](GModel *m) {
         int split = CTX::instance()->mesh.algoSubdivide;
         m->refineMesh(CTX::instance()->mesh.secondOrderLinear, split == 1,
                       split == 2, split == 3);
       });
     }}},
    {"Smooth mesh", {[](int, drawContext *) {
       return meshOperation([](GModel *m) {
         m->optimizeMesh("Laplace2D");
         m->optimizeMesh("Relocate3D");
       });
     }}},
    {"Untangle mesh", {[](int, drawContext *) {
       return meshOperation(
         [](GModel *m) { m->optimizeMesh("UntangleMeshGeometry"); });
     }}},
    {"Delete mesh", {[](int, drawContext *) {
       return meshOperation([](GModel *m) { m->deleteMesh(); });
     }}},
    {"Set order 1", {[](int, drawContext *) { return setOrder(1); }}},
    {"Set order 2", {[](int, drawContext *) { return setOrder(2); }}},
    {"Set order 3", {[](int, drawContext *) { return setOrder(3); }}},
    {"Recombine mesh", {[](int, drawContext *) {
       return meshOperation([](GModel *m) { m->recombineMesh(); });
     }}},
    // (back with its item, once the cross field computation works)
    // {"Compute quad layout",
    //  {[](int, drawContext *) {
    //    return meshOperation([](GModel *m) {
    //      std::vector<int> tags;
    //      computeCrossField(m, tags);
    //    });
    //  }}},
    {"Optimize quad topology", {[](int, drawContext *) {
       return meshOperation(
         [](GModel *m) { m->optimizeMesh("QuadQuasiStructured"); });
     }}},
    {"Unpartition mesh", {[](int, drawContext *) {
       modelLock lock(modelLock::ifFree);
       if(!lock) return (int)ActionDone;
       return partitionsChanged(GModel::current()->unpartitionMesh());
     }}},
    {"Convert old partitioning", {[](int, drawContext *) {
       modelLock lock(modelLock::ifFree);
       if(!lock) return (int)ActionDone;
       return partitionsChanged(
         GModel::current()->convertOldPartitioningToNewOne());
     }}},
#endif
    // the scene
    {"Reset viewport", {[](int, drawContext *ctx) {
       RunSceneShortcut("view_z", 0, ctx);
       RunSceneShortcut("view_1_1", 0, ctx);
       return ActionDone;
     }}},
    {"Axes",
     {[](int, drawContext *) { return toggleAxes(); }, nullptr,
      // (what the toggle changes: the model's axes, not those of the views)
      [] { return opt_general_axes(0, GMSH_GET, 0) ? 1 : 0; }}},
    {"Toggle mesh display", {[](int, drawContext *ctx) {
       RunSceneShortcut("Toggle mesh display", 0, ctx);
       return ActionDone;
     }}},
    {"All view options", {nullptr, haveViews}},
    // the views
#if defined(HAVE_POST)
    {"Reload view", {[](int view, drawContext *) { return reloadView(view); }}},
    {"Reload all views", {[](int, drawContext *) {
       return reloadViews([](int) { return true; });
     }}},
    {"Reload visible views",
     {[](int, drawContext *) { return reloadViews(visibleView); }}},
    {"Create view alias", {[](int view, drawContext *) {
       if(view < 0 || view >= (int)PView::list.size()) return (int)ActionDone;
       new PView(PView::list[view], true); // with its options
       return ActionDone | ActionViewsChanged;
     }}},
    {"Remove view", {[](int view, drawContext *) {
       return removeViews([view](int i) { return i == view; });
     }}},
    {"Remove all views", {[](int, drawContext *) {
       return removeViews([](int) { return true; });
     }}},
    {"Remove visible views",
     {[](int, drawContext *) { return removeViews(visibleView); }}},
    {"Remove invisible views", {[](int, drawContext *) {
       return removeViews([](int i) { return !visibleView(i); });
     }}},
    {"Remove other views", {[](int view, drawContext *) {
       return removeViews([view](int i) { return i != view; });
     }}},
    {"Remove empty views", {[](int, drawContext *) {
       return removeViews(
         [](int i) { return PView::list[i]->getData()->empty(); });
     }}},
    {"Remove views with same name", {[](int view, drawContext *) {
       std::string name = viewName(view);
       return removeViews([name](int i) { return viewName(i) == name; });
     }}},
    {"Sort views by name", {[](int, drawContext *) {
       PView::sortByName();
       return ActionDone | ActionViewsChanged;
     }}},
    {"Show all views",
     {[](int, drawContext *) { return showViews([](int) { return true; }); }}},
    {"Hide all views",
     {[](int, drawContext *) { return showViews([](int) { return false; }); }}},
    {"Invert view visibility", {[](int, drawContext *) {
       return showViews([](int i) { return !visibleView(i); });
     }}},
    {"Show views with same name", {[](int view, drawContext *) {
       std::string name = viewName(view);
       return showViews([name](int i) { return viewName(i) == name; });
     }}},
    {"Combine elements of all views",
     {[](int, drawContext *) { return combineViews(false, 1); }}},
    {"Combine elements of visible views",
     {[](int, drawContext *) { return combineViews(false, 0); }}},
    {"Combine elements of views with same name",
     {[](int, drawContext *) { return combineViews(false, 2); }}},
    {"Combine time steps of all views",
     {[](int, drawContext *) { return combineViews(true, 1); }}},
    {"Combine time steps of visible views",
     {[](int, drawContext *) { return combineViews(true, 0); }}},
    {"Combine time steps of views with same name",
     {[](int, drawContext *) { return combineViews(true, 2); }}},
#if defined(HAVE_MESH)
    {"Apply view as background mesh", {[](int view, drawContext *) {
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
static const std::map<std::string, action> &actions()
{
  static const std::map<std::string, action> all = [] {
    std::map<std::string, action> m = tableActions();
    for(auto &l : scriptLanguages()) {
      std::string lang = l.name;
      m["Write " + l.label + " program"] = {
        [lang](int, drawContext *) {
          scriptWriteIn(lang, !scriptWritesIn(lang));
          return (int)ActionDone;
        },
        nullptr, [lang] { return scriptWritesIn(lang) ? 1 : 0; }};
      m["Edit " + l.label + " program"] = {
        nullptr, [lang] {
          return scriptWritesIn(lang) &&
                 !StatFile(scriptProgram(scriptFile(), lang));
        }};
    }
    return m;
  }();
  return all;
}

// ---------------------------------------------------------------------------
// The options

// "Category.Name" or "Category.Name=value": the category, the name, the value
// (none for a toggle), and the indices the option is set for: 0, or the
// visible views for View
namespace {
  struct actionOption {
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

static actionOption optionOf(const std::string &option)
{
  actionOption o;
  std::string::size_type dot = option.find('.'), eq = option.find('=');
  o.category = option.substr(0, dot);
  o.name = option.substr(dot + 1, eq == std::string::npos ? eq : eq - dot - 1);
  o.toggle = (eq == std::string::npos);
  o.value = o.toggle ? 0. : atof(option.substr(eq + 1).c_str());
  if(o.category != "View") o.indices.push_back(0);
#if defined(HAVE_POST)
  else
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(visibleView(i)) o.indices.push_back(i);
#endif
  return o;
}

void SetActionOption(const std::string &option, double value)
{
  actionOption o = optionOf(option);
  for(int i : o.indices)
    NumberOption(GMSH_SET | GMSH_GUI, o.category.c_str(), i, o.name.c_str(),
                 value, false);
}

// ---------------------------------------------------------------------------

bool IsAction(const std::string &name) { return actions().count(name) > 0; }

bool IsDoneByInterface(const actionItem &item)
{
  if(item.kind == ActionOperation || item.kind == ActionShape) return true;
  if(item.kind != ActionRun) return false;
  auto it = actions().find(item.what);
  return it == actions().end() || !it->second.run;
}

int RunAction(const actionItem &item, int view, drawContext *ctx)
{
  if(item.kind == ActionOption) {
    actionOption o = optionOf(item.what);
    if(o.indices.empty()) return ActionDone;
    SetActionOption(item.what, o.toggle ? !o.current() : o.value);
    return ActionDone;
  }
  if(item.kind != ActionRun) return ActionNotHere;
  auto it = actions().find(item.what);
  if(it == actions().end() || !it->second.run) return ActionNotHere;
  return it->second.run(view, ctx);
}

bool IsActionAvailable(const actionItem &item)
{
  if(item.kind == ActionOption) {
    return item.what.compare(0, 5, "View.") || haveViews();
  }
  if(item.kind != ActionRun) return true;
  // (an action not in the table is done by the interfaces, which say whether
  // they do it)
  auto it = actions().find(item.what);
  return it == actions().end() || !it->second.available ||
         it->second.available();
}

int GetActionCheck(const actionItem &item)
{
  if(item.kind == ActionOption && !item.what.empty()) {
    actionOption o = optionOf(item.what);
    if(o.indices.empty()) return 0;
    double v = o.current();
    return o.toggle ? (v != 0.) : (v == o.value);
  }
  if(item.kind != ActionRun) return -1;
  auto it = actions().find(item.what);
  if(it == actions().end() || !it->second.check) return -1;
  return it->second.check();
}
