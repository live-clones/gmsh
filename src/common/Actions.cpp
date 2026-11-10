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
#include "scriptStringInterface.h"

#if defined(HAVE_MESH)
#include "Field.h"
// #include "gmshCrossFields.h" (for Compute quad layout)
#endif

#if defined(HAVE_OPENGL)
#include "drawContext.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

// This file is the menus of the two interfaces, each item with what it does
// (see Actions.h): first the functions the actions share, then the builders of
// the items, then the menus, and last how the interfaces run them.

// What the actions share

static std::string scriptFile() { return GModel::current()->getFileName(); }

static bool haveViews()
{
#if defined(HAVE_POST)
  return !PView::list.empty();
#else
  return false;
#endif
}

#if defined(HAVE_MESH)
// an operation on the mesh, not during another operation on the model
static void meshOperation(const std::function<void(GModel *)> &f)
{
  modelLock lock(modelLock::ifFree);
  if(!lock) return;
  f(GModel::current());
  CTX::instance()->meshChanged();
}

static void setOrder(int order)
{
  meshOperation([order](GModel *m) {
    m->setOrderN(order, CTX::instance()->mesh.secondOrderLinear,
                 CTX::instance()->mesh.secondOrderIncomplete,
                 CTX::instance()->mesh.meshOnlyVisible);
  });
}

// the partitions changed (error is 0): each shown in its colour, or none
static void partitionsChanged(int error)
{
  if(error) return;
  opt_mesh_zone_definition(0, GMSH_SET, 0.);
  opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 1.);
  CTX::instance()->meshChanged();
}
#endif

#if defined(HAVE_POST)
static bool isViewVisible(int i) { return opt_view_visible(i, GMSH_GET, 0); }

static std::string viewName(int i)
{
  if(i < 0 || i >= (int)PView::list.size()) return "";
  return PView::list[i]->getData()->getName();
}

// the views removed (from the last), if remove(i)
static void removeViews(const std::function<bool(int i)> &remove)
{
  for(int i = (int)PView::list.size() - 1; i >= 0; i--)
    if(remove(i)) delete PView::list[i];
}

// each view shown if show(i)
static void showViews(const std::function<bool(int i)> &show)
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    opt_view_visible(i, GMSH_SET | GMSH_GUI, show(i));
}

// the elements (or the time steps, if time) of views combined: of all the
// views (how = 1), the visible ones (0), or those of the same name (2)
static void combineViews(bool time, int how)
{
  PView::combine(time, how, CTX::instance()->post.combineRemoveOrig,
                 CTX::instance()->post.combineCopyOptions);
}

// a view read again from its file, the new data replacing the old one in the
// view and in every view sharing it (its aliases, or the view it is an alias
// of)
static void reloadView(int index)
{
  if(index < 0 || index >= (int)PView::list.size()) return;
  PView *p = PView::list[index];
  // copied: reading processes events, during which the view may go
  std::string fileName = p->getData()->getFileName();
  if(StatFile(fileName)) {
    Msg::Error("File '%s' does not exist", fileName.c_str());
    return;
  }
  int tag = p->getTag();
  std::size_t n = PView::list.size();
  {
    // not during another operation on the model, which reading may change
    modelLock lock(modelLock::ifFree);
    if(!lock) return;
    MergeFile(fileName);
  }
  p = PView::getViewByTag(tag);
  if(!p || PView::list.size() <= n) return;
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
}

static void reloadViews(const std::function<bool(int i)> &reload)
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(reload(i)) reloadView(i);
}

// an option of every visible view, from what it is
static void forVisibleViews(double (*option)(int, int, double),
                            double (*next)(double))
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(isViewVisible(i))
      option(i, GMSH_SET | GMSH_GUI, next(option(i, GMSH_GET, 0)));
}

// an option of the visible views as the first of them has it, and turned on
// or off for all of them, as an item toggling it shows and does
static double firstVisibleView(double (*option)(int, int, double))
{
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(isViewVisible(i)) return option(i, GMSH_GET, 0);
  return 0.;
}
static void toggleVisibleViews(double (*option)(int, int, double))
{
  double v = !firstVisibleView(option);
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(isViewVisible(i)) option(i, GMSH_SET | GMSH_GUI, v);
}
#endif

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

// an option toggled (all as the first is not) or set
static void setItemOption(const std::string &option)
{
  itemOption o = parseOption(option);
  double v = o.toggle ? !o.current() : o.value;
  for(int i : o.indices)
    NumberOption(GMSH_SET | GMSH_GUI, o.category.c_str(), i, o.name.c_str(), v,
                 false);
}

// its check mark: on, or set to the value
static int itemOptionCheck(const std::string &option)
{
  itemOption o = parseOption(option);
  if(o.indices.empty()) return 0;
  double v = o.current();
  return o.toggle ? (v != 0.) : (v == o.value);
}

// the axes on or off, fitted to the model and the visible views when on
static void toggleAxes()
{
  if(opt_general_axes(0, GMSH_GET, 0)) {
    opt_general_axes(0, GMSH_SET | GMSH_GUI, 0);
    return;
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
}

// the mesh all off if any of it is drawn (as the options say now, whatever
// changed them), else back as it was when turned off (the default edges if it
// never was)
static void toggleMesh()
{
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
  Msg::StatusBar(false, drawn ? "Mesh display OFF" : "Mesh display restored");
}

// The builders of the items

// what an action does in Gmsh (see actionItem)
typedef std::function<void(int view, drawContext *ctx)> actionFunction;

// a menu, and a group of items set apart (a menu without label)
static actionItem menu(const std::string &label, const std::string &help,
                       const std::vector<actionItem> &items)
{ return {label, ItemMenu, "", items, help}; }
static actionItem group(const std::vector<actionItem> &items)
{ return menu("", "", items); }
// an action Gmsh does: what it does, when it applies and its check mark
static actionItem action(const std::string &label, const std::string &name,
                         const std::string &help, actionFunction run,
                         std::function<bool()> available = nullptr,
                         std::function<int()> check = nullptr)
{ return {label, ItemAction, name, {}, help, run, available, check}; }
// an action the interfaces do (fltkActions() on the desktop, pageActions in
// the web page): when it applies
static actionItem guiAction(const std::string &label, const std::string &name,
                            const std::string &help = "",
                            std::function<bool()> available = nullptr)
{ return {label, ItemAction, name, {}, help, nullptr, available}; }
// an option of the display turned on or off, checked when it is on
static actionItem toggleAction(const std::string &label,
                               const std::string &name,
                               double (*option)(int, int, double))
{
  return action(
    label, name, "",
    [option](int, drawContext *) {
      option(0, GMSH_SET | GMSH_GUI, !option(0, GMSH_GET, 0));
    },
    nullptr, [option] { return option(0, GMSH_GET, 0) ? 1 : 0; });
}
// an operation on the entities picked (see selectionDriver)
static actionItem operation(const std::string &label, const std::string &name,
                            const std::string &help = "")
{ return {label, ItemOperation, name, {}, help}; }
// a shape (see scriptShapes())
static actionItem shape(const std::string &label, const std::string &name)
{ return {label, ItemShape, name, {}, ""}; }
// an option toggled ("Mesh.Nodes", a check box) or set ("View.IntervalsType=3",
// a radio item), named as it is; a View.* option is that of the visible
// views, which it needs
static actionItem option(const std::string &label, const std::string &name)
{
  return action(
    label, name, "", [name](int, drawContext *) { setItemOption(name); },
    name.compare(0, 5, "View.") ? std::function<bool()>() : haveViews,
    [name] { return itemOptionCheck(name); });
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

// The menus

// the programs the commands added to the script are also written in (see
// General.ScriptingLanguages), and their edition (by the interfaces)
static actionItem programsMenu()
{
  std::vector<actionItem> write, edit;
  for(auto &l : scriptLanguages()) {
    std::string lang = l.name;
    write.push_back(action(
      l.label, "script_write_" + lang,
      "Also write the commands added to the script in a " + l.label +
        " program next to it",
      [lang](int, drawContext *) {
        scriptWriteIn(lang, !scriptWritesIn(lang));
      },
      nullptr, [lang] { return scriptWritesIn(lang) ? 1 : 0; }));
    edit.push_back(guiAction(
      l.label, "script_edit_" + lang,
      "Edit the " + l.label + " program written next to the script", [lang] {
        return scriptWritesIn(lang) &&
               !StatFile(scriptProgram(scriptFile(), lang));
      }));
  }
  return menu("Also write",
              "Also write the commands added to the script as programs of "
              "the API",
              {group(write), menu("Edit program", "", edit)});
}

// The Geometry module: rows of buttons, a menu as a button that opens it
static actionItem geometryModule()
{
  std::vector<actionItem> script = {
    guiAction("New", "model_new",
              "Make a new model, an empty script with the OpenCASCADE kernel"),
    guiAction("Reload script", "script_reload", "Read the script again"),
    guiAction("Edit script", "script_edit", "Edit the script"),
    guiAction("Save script", "script_save", "Save the script (.geo)"),
    action("Remove last script command", "script_remove_last",
           "Take back the last command added to the script",
           [](int, drawContext *) { scriptRemoveLastCommand(scriptFile()); }),
    programsMenu(),
  };
  std::vector<actionItem> kernel = {
    action(
      "Built-in", "kernel_builtin", "",
      [](int, drawContext *) { scriptSetFactory("Built-in", scriptFile()); }),
    action("OpenCASCADE", "kernel_occ", "",
           [](int, drawContext *) {
             scriptSetFactory("OpenCASCADE", scriptFile());
           }),
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
           "fragment all of them with OpenCASCADE",
           [](int, drawContext *) { scriptCoherence(scriptFile()); }),
    menu("Physical groups",
         "Physical groups of the entities picked in the scene", physical),
  };
  return group({group(script), group(entities)});
}

// The Mesh module
static actionItem meshModule()
{
#if defined(HAVE_MESH)
  std::vector<actionItem> generate = {
    action("1D", "mesh_1d", "Mesh the curves",
           [](int, drawContext *) { GModel::current()->mesh(1); }),
    action("2D", "mesh_2d",
           "Mesh the surfaces (and the curves they are bounded by)",
           [](int, drawContext *) { GModel::current()->mesh(2); }),
    action("3D", "mesh_3d", "Mesh the volumes (and what they are bounded by)",
           [](int, drawContext *) { GModel::current()->mesh(3); }),
  };
  std::vector<actionItem> modify = {
    action("Refine by splitting", "mesh_refine",
           "Refine the mesh by splitting its elements",
           [](int, drawContext *) {
             meshOperation([](GModel *m) {
               int split = CTX::instance()->mesh.algoSubdivide;
               m->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                             split == 1, split == 2, split == 3);
             });
           }),
    action("Smooth", "mesh_smooth",
           "Smooth the mesh of the surfaces, then of the volumes",
           [](int, drawContext *) {
             meshOperation([](GModel *m) {
               m->optimizeMesh("Laplace2D");
               m->optimizeMesh("Relocate3D");
             });
           }),
    guiAction("Reclassify surfaces", "mesh_reclassify",
              "Reclassify the surface mesh into new surfaces, by the angle of "
              "its triangles"),
    action("Untangle mesh", "mesh_untangle",
           "Untangle the elements of the mesh",
           [](int, drawContext *) {
             meshOperation(
               [](GModel *m) { m->optimizeMesh("UntangleMeshGeometry"); });
           }),
  };
  std::vector<actionItem> save = {
    guiAction("Save", "mesh_save", "Save the mesh"),
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
    guiAction("Size fields", "mesh_size_fields"),
    operation("Recombine", "define_recombine"),
    menu("Transfinite", "", transfinite),
    menu("Embedded", "", embedded),
    menu("Compound", "", compound),
  };
  std::vector<actionItem> highOrder = {
    action("Set order 1", "mesh_order_1", "",
           [](int, drawContext *) { setOrder(1); }),
    action("Set order 2", "mesh_order_2", "",
           [](int, drawContext *) { setOrder(2); }),
    action("Set order 3", "mesh_order_3", "",
           [](int, drawContext *) { setOrder(3); }),
    guiAction("High-order tools", "mesh_high_order_tools"),
  };
  std::vector<actionItem> reverse = {
    operation("Elements", "mesh_reverse_elements"),
    operation("Curves", "mesh_reverse_curves"),
    operation("Surfaces", "mesh_reverse_surfaces"),
    operation("Volumes", "mesh_reverse_volumes"),
  };
  std::vector<actionItem> remove = {
    action("All", "mesh_delete", "",
           [](int, drawContext *) {
             meshOperation([](GModel *m) { m->deleteMesh(); });
           }),
    operation("Elements", "mesh_delete_elements"),
    operation("Curves", "mesh_delete_curves"),
    operation("Surfaces", "mesh_delete_surfaces"),
    operation("Volumes", "mesh_delete_volumes"),
  };
  std::vector<actionItem> quad = {
    action("Recombine triangles into quads", "mesh_recombine", "",
           [](int, drawContext *) {
             meshOperation([](GModel *m) { m->recombineMesh(); });
           }),
    // (back once the cross field computation works)
    // action("Compute quad layout", "mesh_quad_layout", "",
    //        [](int, drawContext *) {
    //          meshOperation([](GModel *m) {
    //            std::vector<int> tags;
    //            computeCrossField(m, tags);
    //          });
    //        }),
    action("Optimize quad topology", "mesh_optimize_quads", "",
           [](int, drawContext *) {
             meshOperation(
               [](GModel *m) { m->optimizeMesh("QuadQuasiStructured"); });
           }),
  };
  std::vector<actionItem> partitioning = {
    guiAction("Partition", "mesh_partition"),
    action("Unpartition", "mesh_unpartition", "",
           [](int, drawContext *) {
             modelLock lock(modelLock::ifFree);
             if(lock) partitionsChanged(GModel::current()->unpartitionMesh());
           }),
    action("Convert old partitioning", "mesh_convert_partitioning", "",
           [](int, drawContext *) {
             modelLock lock(modelLock::ifFree);
             if(lock)
               partitionsChanged(
                 GModel::current()->convertOldPartitioningToNewOne());
           }),
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
#else
  return group({});
#endif
}

// The quick access menu of the scene
static actionItem quickAccessMenu()
{
  std::vector<actionItem> split = {
    guiAction("Horizontally", "window_split_horizontal"),
    guiAction("Vertically", "window_split_vertical"),
    guiAction("Unsplit", "window_unsplit"),
  };
  std::vector<actionItem> window = {
    action("Reset viewport", "scene_reset", "",
           [](int, drawContext *ctx) {
#if defined(HAVE_OPENGL)
             if(!ctx) return;
             ctx->standardView("z", false);
             ctx->standardView("1:1", false);
#endif
           }),
    guiAction("Select rotation center", "scene_rotation_center"),
    guiAction("Query", "query"),
    guiAction("Measure", "measure"),
    guiAction("Full screen", "window_full_screen"),
    guiAction("Install app", "app_install"),
    menu("Split window", "", split),
  };
  std::vector<actionItem> projection = {
    option("Orthographic", "General.Orthographic=1"),
    option("Perspective", "General.Orthographic=0"),
  };
  std::vector<actionItem> general = {
    action(
      "Axes", "axes", "", [](int, drawContext *) { toggleAxes(); }, nullptr,
      // (what the toggle changes: the model's axes, not those of the
      // views)
      [] { return opt_general_axes(0, GMSH_GET, 0) ? 1 : 0; }),
    option("Hover mesh and views", "General.MouseHoverMeshes"),
    menu("Projection", "", projection),
    guiAction("All general options...", "options_general"),
  };
  std::vector<actionItem> geometryVisibility = {
    toggleAction("Points", "geometry_points", opt_geometry_points),
    toggleAction("Curves", "geometry_curves", opt_geometry_curves),
    toggleAction("Surfaces", "geometry_surfaces", opt_geometry_surfaces),
    toggleAction("Volumes", "geometry_volumes", opt_geometry_volumes),
  };
  std::vector<actionItem> geometry = {
    menu("Geometry visibility", "", geometryVisibility),
    presets("Geometry opacity", "Geometry.Opacity", opacities()),
    guiAction("All geometry options...", "options_geometry"),
  };
  std::vector<actionItem> meshVisibility = {
    toggleAction("Nodes", "mesh_nodes", opt_mesh_nodes),
    toggleAction("1D elements", "mesh_lines", opt_mesh_lines),
    toggleAction("2D element edges", "mesh_surface_edges",
                 opt_mesh_surface_edges),
    toggleAction("2D element faces", "mesh_surface_faces",
                 opt_mesh_surface_faces),
    toggleAction("3D element edges", "mesh_volume_edges",
                 opt_mesh_volume_edges),
    toggleAction("3D element faces", "mesh_volume_faces",
                 opt_mesh_volume_faces),
  };
  std::vector<std::pair<std::string, std::string>> sizeFactors = {
    {"0.25", "0.25"}, {"0.5", "0.5"}, {"1", "1"}, {"2", "2"}, {"4", "4"},
  };
  std::vector<actionItem> mesh = {
    menu("Mesh visibility", "", meshVisibility),
    action("Toggle mesh display", "mesh_toggle", "",
           [](int, drawContext *) { toggleMesh(); }),
    presets("Mesh opacity", "Mesh.Opacity", opacities()),
    presets("Global mesh size factor", "Mesh.MeshSizeFactor", sizeFactors),
    guiAction("All mesh options...", "options_mesh"),
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
#if defined(HAVE_POST)
    action(
      "View element outlines", "view_elements", "",
      [](int, drawContext *) { toggleVisibleViews(opt_view_show_element); },
      haveViews, [] { return (int)firstVisibleView(opt_view_show_element); }),
#endif
    menu("View intervals", "", intervals),
    menu("View vectors", "", vectors),
    presets("View opacity", "View.Opacity", opacities()),
    guiAction("All view options...", "options_views", "", haveViews),
  };
  return group({group(window), group(general), group(geometry), group(mesh),
                group(views)});
}

// The menu of a view (view: its index)
static actionItem viewMenu()
{
#if defined(HAVE_POST)
  std::vector<actionItem> settings = {
    guiAction("Options", "view_options"),
    guiAction("Plugins", "view_plugins"),
  };
  std::vector<actionItem> reloadAll = {
    action("All", "views_reload_all", "",
           [](int, drawContext *) { reloadViews([](int) { return true; }); }),
    action("Visible", "views_reload_visible", "",
           [](int, drawContext *) { reloadViews(isViewVisible); }),
  };
  std::vector<actionItem> reload = {
    action("Reload", "view_reload", "",
           [](int view, drawContext *) { reloadView(view); }),
    menu("Reload views", "", reloadAll),
    action("Create alias", "view_alias", "",
           [](int view, drawContext *) {
             if(view >= 0 && view < (int)PView::list.size())
               new PView(PView::list[view], true); // with its options
           }),
  };
  std::vector<actionItem> removeAll = {
    action("All", "views_remove_all", "",
           [](int, drawContext *) { removeViews([](int) { return true; }); }),
    action("Visible", "views_remove_visible", "",
           [](int, drawContext *) { removeViews(isViewVisible); }),
    action("Invisible", "views_remove_invisible", "",
           [](int, drawContext *) {
             removeViews([](int i) { return !isViewVisible(i); });
           }),
    action("Other", "views_remove_others", "",
           [](int view, drawContext *) {
             removeViews([view](int i) { return i != view; });
           }),
    action("Empty", "views_remove_empty", "",
           [](int, drawContext *) {
             removeViews(
               [](int i) { return PView::list[i]->getData()->empty(); });
           }),
    action("With same name", "views_remove_same_name", "",
           [](int view, drawContext *) {
             std::string name = viewName(view);
             removeViews([name](int i) { return viewName(i) == name; });
           }),
  };
  std::vector<actionItem> remove = {
    action("Remove", "view_remove", "",
           [](int view, drawContext *) {
             removeViews([view](int i) { return i == view; });
           }),
    menu("Remove views", "", removeAll),
  };
  std::vector<actionItem> visibility = {
    action("All on", "views_show_all", "",
           [](int, drawContext *) { showViews([](int) { return true; }); }),
    action("All off", "views_hide_all", "",
           [](int, drawContext *) { showViews([](int) { return false; }); }),
    action("Invert", "views_show_inverted", "",
           [](int, drawContext *) {
             showViews([](int i) { return !isViewVisible(i); });
           }),
    action("Same name on", "views_show_same_name", "",
           [](int view, drawContext *) {
             std::string name = viewName(view);
             showViews([name](int i) { return viewName(i) == name; });
           }),
  };
  std::vector<actionItem> combineElements = {
    action("From all views", "views_combine_elements_all", "",
           [](int, drawContext *) { combineViews(false, 1); }),
    action("From visible views", "views_combine_elements_visible", "",
           [](int, drawContext *) { combineViews(false, 0); }),
    action("From all views with same name", "views_combine_elements_same_name",
           "", [](int, drawContext *) { combineViews(false, 2); }),
  };
  std::vector<actionItem> combineSteps = {
    action("From all views", "views_combine_steps_all", "",
           [](int, drawContext *) { combineViews(true, 1); }),
    action("From visible views", "views_combine_steps_visible", "",
           [](int, drawContext *) { combineViews(true, 0); }),
    action("From all views with same name", "views_combine_steps_same_name", "",
           [](int, drawContext *) { combineViews(true, 2); }),
  };
  std::vector<actionItem> arrange = {
    action("Sort by name", "views_sort", "",
           [](int, drawContext *) { PView::sortByName(); }),
    menu("Set visibility", "", visibility),
    menu("Combine elements", "", combineElements),
    menu("Combine time steps", "", combineSteps),
  };
  std::vector<actionItem> use = {
#if defined(HAVE_MESH)
    action("Apply as background mesh", "view_background_mesh", "",
           [](int view, drawContext *) {
             if(view >= 0 && view < (int)PView::list.size())
               GModel::current()->getFields()->setBackgroundMesh(view);
           }),
#endif
    guiAction("Export...", "view_export"),
    guiAction("Export as .pos", "view_export_pos"),
    guiAction("Export as .msh", "view_export_msh"),
  };
  return group({group(settings), group(reload), group(remove), group(arrange),
                group(use)});
#else
  return group({});
#endif
}

// The menu bar of the graphical interface, which does its actions, named as
// their shortcuts (see Shortcuts.h)
static actionItem menuBar()
{
  std::vector<actionItem> remote = {
    guiAction("Start...", "remote_start"),
    guiAction("Merge...", "remote_merge"),
    guiAction("Clear", "remote_clear"),
    guiAction("Stop", "remote_stop"),
  };
  std::vector<actionItem> file = {
    group({
      guiAction("New...", "file_new"),
      guiAction("Open...", "file_open"),
      guiAction("Open Recent", "file_open_recent"),
      guiAction("Merge...", "file_merge"),
      guiAction("Watch Pattern...", "watch"),
    }),
    group({
      guiAction("Clear", "file_clear"),
      guiAction("Rename...", "file_rename"),
      guiAction("Delete", "file_delete"),
    }),
    group({menu("Remote", "", remote)}),
    group({
      guiAction("Save Mesh", "mesh_save"),
      guiAction("Save Model Options", "options_save"),
      guiAction("Save Options As Default", "options_save_default"),
    }),
    group({guiAction("Export...", "file_export")}),
    group({guiAction("Quit", "quit")}),
  };
  std::vector<actionItem> tools = {
    group({
      guiAction("Options", "options"),
      guiAction("Plugins", "plugins"),
      guiAction("Visibility", "visibility"),
      guiAction("Clipping", "clipping"),
      guiAction("Manipulator", "manipulator"),
    }),
    group({guiAction("3M", "window_3m")}),
    group({
      guiAction("Statistics", "statistics"),
      guiAction("Message Console", "console"),
    }),
  };
  std::vector<actionItem> window = {
    group({guiAction("New Window", "window_new")}),
    group({guiAction("Copy to Clipboard", "window_copy")}),
    group({
      guiAction("Split Horizontally", "window_split_horizontal"),
      guiAction("Split Vertically", "window_split_vertical"),
      guiAction("Unsplit", "window_unsplit"),
    }),
    group({
      guiAction("Minimize", "minimize"),
      guiAction("Zoom", "window_zoom"),
      guiAction("Enter Full Screen", "window_full_screen"),
    }),
    group({
      guiAction("Show/Hide Menu", "menu_show_hide"),
      guiAction("Attach/Detach Menu", "menu_attach_detach"),
      guiAction("Dock/Undock Tool Window", "dock"),
      guiAction("Dock/Undock All Tool Windows", "dock_all"),
    }),
    group({guiAction("Bring All to Front", "window_front")}),
  };
  std::vector<actionItem> help = {
    group({guiAction("Online Documentation", "help_online")}),
    group({guiAction("Keyboard and Mouse Usage", "help_keys")}),
    group({
      guiAction("Current Options and Workspace", "help_options"),
      guiAction("Restore all Options to Default Settings",
                "options_restore_defaults"),
    }),
    group({guiAction("About Gmsh", "help_about")}),
  };
  return group({
    menu("File", "", file),
    menu("Tools", "", tools),
    menu("Window", "", window),
    menu("Help", "", help),
  });
}

// The actions only on keys (see Shortcuts.h), in no menu: the display
static actionItem keysOnly()
{
  std::vector<actionItem> keys = {
    toggleAction("", "fast_redraw", opt_general_fast_redraw),
    toggleAction("", "bounding_boxes", opt_general_draw_bounding_box),
    toggleAction("", "small_axes", opt_general_small_axes),
    toggleAction("", "projection", opt_general_orthographic),
    action("", "color_scheme", "",
           [](int, drawContext *) {
             opt_general_color_scheme(0, GMSH_SET | GMSH_GUI,
                                      opt_general_color_scheme(0, GMSH_GET, 0) +
                                        1);
           }),
    action(
      "", "lighting", "",
      [](int, drawContext *) {
        opt_geometry_light(0, GMSH_SET | GMSH_GUI,
                           !opt_geometry_light(0, GMSH_GET, 0));
        opt_mesh_light(0, GMSH_SET | GMSH_GUI, !opt_mesh_light(0, GMSH_GET, 0));
#if defined(HAVE_POST)
        forVisibleViews(opt_view_light, [](double v) { return (double)!v; });
#endif
      }),
    action("", "axes_loop", "",
           [](int, drawContext *) {
             opt_general_axes(0, GMSH_SET | GMSH_GUI,
                              opt_general_axes(0, GMSH_GET, 0) + 1);
#if defined(HAVE_POST)
             // through the six modes: a view left on automatic starts over at
             // none
             forVisibleViews(opt_view_axes,
                             [](double v) { return (v >= 5) ? 0. : v + 1.; });
#endif
           }),
    action("", "surface_type", "",
           [](int, drawContext *) {
             opt_geometry_surface_type(
               0, GMSH_SET | GMSH_GUI,
               opt_geometry_surface_type(0, GMSH_GET, 0) + 1);
           }),
#if defined(HAVE_POST)
    action(
      "", "view_scales", "",
      [](int, drawContext *) {
        forVisibleViews(opt_view_show_scale,
                        [](double v) { return (double)!v; });
      },
      haveViews),
    action(
      "", "colormaps", "",
      [](int, drawContext *) {
        forVisibleViews(opt_view_colormap_number,
                        [](double v) { return v + 1.; });
      },
      haveViews),
    action(
      "", "view_intervals", "",
      [](int, drawContext *) {
        // skipping the numeric display
        forVisibleViews(opt_view_intervals_type,
                        [](double v) { return (v + 1 == 4) ? 1. : v + 1.; });
      },
      haveViews),
    action(
      "", "view_intervals_all", "",
      [](int, drawContext *) {
        forVisibleViews(opt_view_intervals_type,
                        [](double v) { return v + 1.; });
      },
      haveViews),
    action(
      "", "view_range", "",
      [](int, drawContext *) {
        forVisibleViews(opt_view_range_type, [](double v) { return v + 1.; });
      },
      haveViews),
    action(
      "", "view_annotations", "",
      [](int, drawContext *) {
        forVisibleViews(opt_view_draw_strings,
                        [](double v) { return (double)!v; });
      },
      haveViews),
    action(
      "", "views_hide_show", "",
      [](int, drawContext *) {
        // all hidden if any is shown, else all shown
        bool shown = false;
        for(std::size_t i = 0; i < PView::list.size(); i++)
          if(isViewVisible(i)) shown = true;
        showViews([shown](int) { return !shown; });
      },
      haveViews),
#endif
  };
  return group(keys);
}

static const std::map<std::string, actionItem> &menus()
{
  static const std::map<std::string, actionItem> menus = {
    {"Geometry", geometryModule()},
    {"Mesh", meshModule()},
    {"Quick access", quickAccessMenu()},
    {"View", viewMenu()},
    {"Menu bar", menuBar()},
    {"Keys", keysOnly()},
  };
  return menus;
}

const actionItem &GetActionMenu(const std::string &name)
{
  static const actionItem none = group({});
  auto it = menus().find(name);
  return it == menus().end() ? none : it->second;
}

// How the interfaces run them

// the actions by name, from the items of all the menus (an action in several
// menus is the same in each)
static const std::map<std::string, const actionItem *> &actions()
{
  static const std::map<std::string, const actionItem *> all = [] {
    std::map<std::string, const actionItem *> m;
    std::function<void(const actionItem &)> add = [&](const actionItem &i) {
      if(i.kind == ItemMenu)
        for(const actionItem &j : i.items) add(j);
      else if(i.kind == ItemAction && !m.count(i.name))
        m[i.name] = &i;
    };
    for(auto &menu : menus()) add(menu.second);
    return m;
  }();
  return all;
}

static const actionItem *findAction(const std::string &name)
{
  auto it = actions().find(name);
  return it == actions().end() ? nullptr : it->second;
}

bool IsItemDoneByInterface(const actionItem &item)
{
  if(item.kind == ItemOperation || item.kind == ItemShape) return true;
  if(item.kind != ItemAction) return false;
  const actionItem *a = findAction(item.name);
  return !a || !a->run;
}

// the views, for what an action changed in them: added, removed or read again
static std::vector<std::pair<int, void *>> viewsNow()
{
  std::vector<std::pair<int, void *>> v;
#if defined(HAVE_POST)
  for(PView *p : PView::list) v.push_back({p->getTag(), (void *)p->getData()});
#endif
  return v;
}

int RunItem(const actionItem &item, int view, drawContext *ctx)
{
  // (by its name: the item of a key is the name alone)
  const actionItem *a = item.kind == ItemAction ? findAction(item.name) : nullptr;
  if(!a || !a->run) return 0;
  int entities = CTX::instance()->entitiesStamp;
  std::vector<std::pair<int, void *>> views = viewsNow();
  a->run(view, ctx);
  int ret = 0;
  if(CTX::instance()->entitiesStamp != entities) ret |= ActionModelChanged;
  if(viewsNow() != views) ret |= ActionViewsChanged;
  return ret;
}

bool IsItemAvailable(const actionItem &item)
{
  if(item.kind != ItemAction) return true;
  // (an action Gmsh does not know is done by the interfaces, which say
  // whether they do it)
  const actionItem *a = findAction(item.name);
  return !a || !a->available || a->available();
}

int GetItemCheck(const actionItem &item)
{
  if(item.kind != ItemAction) return -1;
  const actionItem *a = findAction(item.name);
  return (a && a->check) ? a->check() : -1;
}
