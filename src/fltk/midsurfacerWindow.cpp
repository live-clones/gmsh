// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "midsurfacerWindow.h"

#if defined(HAVE_MIDSURFACER)

#include <algorithm>
#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <exception>
#include <set>
#include <string>
#include <vector>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include "FlGui.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "drawContext.h"
#include "GModel.h"
#include "GFace.h"
#include "MTriangle.h"
#include "Context.h"
#include "Options.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewDataList.h"
#include "PViewOptions.h"
#include "MatPipeline.h"

namespace {
const char *const stageName[midsurfacerWindow::NumStages] = {
  "skin", "raw", "filtered", "projected", "extended"};

std::string text(const char *fmt, ...)
{
  char buffer[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);
  return buffer;
}

// the faces of the model, those with triangles, and their triangles
void countSkin(GModel *model, std::size_t &faces, std::size_t &meshed,
               std::size_t &triangles)
{
  faces = meshed = triangles = 0;
  for(auto it = model->firstFace(); it != model->lastFace(); ++it) {
    faces++;
    if(!(*it)->triangles.empty()) meshed++;
    triangles += (*it)->triangles.size();
  }
}

void run_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->run((int)(intptr_t)data); }

void display_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->display((int)(intptr_t)data, true); }
} // namespace

void midsurfacer_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->show(); }

struct midsurfacerWindow::State {
  matgmsh_native::Session session;
  // what the stages kept were computed with: the model and its stamps, the
  // method of the raw MAT, the thickness and the threshold of the filter
  GModel *model = nullptr;
  modelStamps stamps;
  int method = -1;
  double thickness = 0., threshold = -1.;
  // the view of each stage: its tag, and its data, to tell it from a view
  // that took the tag since
  int tag[NumStages];
  PViewData *data[NumStages];
  // the warnings of the stages already said for this raw MAT
  std::set<std::string> said;
  State()
  {
    for(int i = 0; i < NumStages; i++) {
      tag[i] = -1;
      data[i] = nullptr;
    }
  }
  PView *view(int stage) const
  {
    if(tag[stage] < 0) return nullptr;
    PView *v = PView::getViewByTag(tag[stage]);
    return (v && v->getData() == data[stage]) ? v : nullptr;
  }
};

midsurfacerWindow::midsurfacerWindow(int deltaFontSize) : _state(new State)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  const int section = WB + 2 + BH; // a line, then a title
  int width = TW;
  int height = 2 * WB + 12 * BH + 6 * section;

  win = new paletteWindow(width, height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Midsurfacer");
  win->box(GMSH_WINDOW_BOX);

  int x = 2 * WB, y = WB;
  const int full = width - 4 * WB;

  auto title = [&](const char *label) {
    Fl_Box *line = new Fl_Box(x, y + WB / 2, full, 2);
    line->box(FL_ENGRAVED_FRAME);
    line->labeltype(FL_NO_LABEL);
    y += WB + 2;
    Fl_Box *b = new Fl_Box(x - WB, y, width - 2 * WB, BH, label);
    b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    y += BH;
  };
  auto input = [&](const char *label, double value, double min, double max,
                   double step, const char *tip) {
    Fl_Value_Input *o = new Fl_Value_Input(x, y, IW, BH, label);
    o->minimum(min);
    o->maximum(max);
    if(CTX::instance()->inputScrolling) o->step(step);
    o->align(FL_ALIGN_RIGHT);
    o->value(value);
    o->tooltip(tip);
    y += BH;
    return o;
  };
  // what the stage gave, and the button that runs it
  auto action = [&](int stage, const char *label, const char *tip) {
    status[stage] = new Fl_Box(x, y, full - BB - WB, BH);
    status[stage]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    status[stage]->labelcolor(FL_INACTIVE_COLOR);
    push[stage] = new Fl_Button(width - BB - 2 * WB, y, BB, BH, label);
    push[stage]->callback(run_cb, (void *)(intptr_t)stage);
    push[stage]->tooltip(tip);
    y += BH;
  };

  // no default: the mesh size, the filter and the extension all follow it
  thickness =
    input("Thickness (of the thickest wall)", 0., 0., 1.e22, .1,
          "The thickness of the thickest wall of the solid, with some "
          "margin (4 for walls of 3.5): the filter removes the wings whose "
          "erosion thickness is below the threshold times this value, so a "
          "smaller value leaves the wings of the thicker walls. It also "
          "gives the default mesh size and the default length of the "
          "extension");

  title("1. Skin");
  meshSize = input("Mesh size (0: thickness / 10)", 0., 0., 1.e22, .01,
                   "Size of the triangles of the skin; 0 for a tenth of the "
                   "thickness");
  action(Skin, "Mesh",
         "Mesh the surfaces again with first-order triangles of this size. "
         "The next stages use the surface mesh of the model, whoever made it");

  title("2. Medial axis");
  static Fl_Menu_Item methods[] = {{"Tetrahedra", 0, nullptr, nullptr},
                                   {"Legacy", 0, nullptr, nullptr},
                                   {nullptr}};
  method = new Fl_Choice(x, y, IW, BH, "Method");
  method->menu(methods);
  method->align(FL_ALIGN_RIGHT);
  method->tooltip(
    "Tetrahedra: the dual of the Delaunay tetrahedra inside the skin, with "
    "a certificate of their boundary, then the filter by collapse. Legacy: circumcentres classified by winding number, then the "
    "filter by CAD patches");
  y += BH;
  action(Raw, "Compute", "Compute the raw medial axis of the skin");

  title("3. Filter");
  threshold =
    input("Threshold (fraction of the thickness)", .21, 0., 10., .01,
          "A sheet is removed where its erosion thickness is below this "
          "fraction of the thickness; the wings of the convex edges are "
          "removed too. The topology of the raw medial axis is kept");
  action(Filter, "Filter",
         "Filter the medial axis; the raw medial axis is not computed again");

  title("4. Projection (optional)");
  action(Projection, "Project",
         "Project the filtered medial axis onto the local mid-surface; a "
         "projection that fails its checks changes nothing");

  title("5. Extension");
  length = input("Length (0: 3 x thickness)", 0., 0., 1.e22, .1,
                 "Largest distance covered by the extension; 0 for three "
                 "times the thickness");
  layers = input("Layers", 12., 1., 10000., 1., "Number of layers");
  action(Extension, "Extend",
         "Extend the free boundaries of the mid-surface to the skin "
         "(experimental: the fronts that do not reach it are reported)");

  title("Show");
  {
    static const char *labels[NumStages] = {"Skin", "Raw", "Filtered",
                                            "Projected", "Extended"};
    // twentieths of the row, for labels of unequal lengths
    static const int share[NumStages + 1] = {0, 3, 6, 10, 15, 20};
    Fl_Group *row = new Fl_Group(x, y, full, BH);
    for(int i = 0; i < NumStages; i++) {
      int x0 = x + share[i] * full / 20, x1 = x + share[i + 1] * full / 20;
      visible[i] = new Fl_Check_Button(x0, y, x1 - x0, BH, labels[i]);
      visible[i]->callback(display_cb, (void *)(intptr_t)i);
      if(i) visible[i]->deactivate();
    }
    row->end();
  }

  win->end();
  // of fixed height, as narrow as the option window, wider as one likes
  ((paletteWindow *)win)->fixedLayout(width, height, 2 * WB);
  FL_NORMAL_SIZE += deltaFontSize;
}

midsurfacerWindow::~midsurfacerWindow()
{
  delete _state;
  Fl::delete_widget(win);
}

void midsurfacerWindow::show()
{
  // the skin as it is now, whoever meshed it
  std::size_t faces, meshed, triangles;
  countSkin(GModel::current(), faces, meshed, triangles);
  if(!faces)
    status[Skin]->copy_label("No surface in the model");
  else if(!triangles)
    status[Skin]->copy_label("Not meshed");
  else
    status[Skin]->copy_label(
      text("%zu triangles on %zu of %zu surfaces", triangles, meshed, faces)
        .c_str());
  visible[Skin]->value(opt_mesh_surface_edges(0, GMSH_GET, 0) ||
                       opt_mesh_surface_faces(0, GMSH_GET, 0));
  win->show();
}

void midsurfacerWindow::_say(int stage, const std::string &what,
                             const std::string &more)
{
  status[stage]->copy_label(what.c_str());
  status[stage]->copy_tooltip(more.empty() ? what.c_str() : more.c_str());
  status[stage]->redraw();
  Msg::Info("Midsurfacer, %s: %s", stageName[stage], what.c_str());
  if(!more.empty())
    Msg::Info("Midsurfacer, %s: %s", stageName[stage], more.c_str());
}

// the stages from this one on are to be computed again: their views go
void midsurfacerWindow::_forget(int fromStage)
{
  for(int i = std::max(fromStage, (int)Raw); i < NumStages; i++) {
    if(PView *v = _state->view(i)) delete v;
    _state->tag[i] = -1;
    _state->data[i] = nullptr;
    status[i]->copy_label("");
    status[i]->copy_tooltip("");
    visible[i]->value(0);
    visible[i]->deactivate();
  }
}

// the view of a stage, colored by sheet
void midsurfacerWindow::_view(int stage)
{
  const matgmsh_native::Result &r = _state->session.result();
  const matgmsh_native::Mesh &mesh = stage == Raw ? r.raw :
                                     stage == Filter ? r.filtered :
                                     stage == Projection ? r.projected :
                                                           r.extended;
  if(mesh.triangles.empty()) return;
  PViewDataList *data = new PViewDataList();
  for(std::size_t t = 0; t < mesh.triangles.size() / 3; t++) {
    std::vector<double> *values = data->incrementList(1, TYPE_TRI);
    for(int component = 0; component < 3; component++)
      for(int corner = 0; corner < 3; corner++)
        values->push_back(
          mesh.xyz[3 * mesh.triangles[3 * t + corner] + component]);
    const double sheet = t < mesh.branch.size() ? mesh.branch[t] : 0.;
    values->insert(values->end(), {sheet, sheet, sheet});
  }
  data->setName(std::string("MAT ") + stageName[stage]);
  data->setFileName(std::string("mat_") + stageName[stage] + ".pos");
  data->finalize();
  PView *view = new PView(data);
  view->getOptions()->visible = 0;
  _state->tag[stage] = view->getTag();
  _state->data[stage] = data;
  visible[stage]->activate();
}

// the result of a stage alone in the scene: the other stages hidden, and the
// skin with them, which hides what is inside it
void midsurfacerWindow::_showOnly(int stage)
{
  for(int i = 0; i < NumStages; i++) {
    bool on = (i == stage);
    if(i != Skin && !_state->view(i)) on = false;
    if(i == Skin && stage == Skin) on = true;
    visible[i]->value(on);
    display(i, false);
  }
}

void midsurfacerWindow::display(int stage, bool draw)
{
  int on = visible[stage]->value() ? 1 : 0;
  if(stage == Skin) {
    opt_mesh_surface_edges(0, GMSH_SET | GMSH_GUI, on);
    if(!on) opt_mesh_surface_faces(0, GMSH_SET | GMSH_GUI, 0);
  }
  else if(PView *v = _state->view(stage))
    opt_view_visible(v->getIndex(), GMSH_SET | GMSH_GUI, on);
  if(draw) drawContext::global()->draw();
}

// meshes the skin again, at the size asked for (the model is locked by the
// caller)
bool midsurfacerWindow::_skin()
{
  GModel *model = GModel::current();
  if(!model->getNumFaces()) {
    _say(Skin, "No surface in the model");
    return false;
  }
  double size =
    meshSize->value() > 0. ? meshSize->value() : .1 * thickness->value();
  status[Skin]->copy_label("Meshing...");
  win->redraw();
  FlGui::check();
  // these sizes and this order for this mesh only
  contextMeshOptions &m = CTX::instance()->mesh;
  const double lcMin = m.lcMin, lcMax = m.lcMax;
  const int order = m.order;
  m.lcMin = m.lcMax = size;
  m.order = 1;
  bool ok = true;
  try {
    model->deleteMesh();
    ok = model->mesh(2, true);
  }
  catch(const std::exception &e) {
    Msg::Error("Midsurfacer: %s", e.what());
    ok = false;
  }
  catch(...) {
    ok = false;
  }
  m.lcMin = lcMin;
  m.lcMax = lcMax;
  m.order = order;
  CTX::instance()->meshChanged();
  if(!FlGui::available()) return false; // closed while meshing
  std::size_t faces, meshed, triangles;
  countSkin(model, faces, meshed, triangles);
  if(!ok || meshed < faces) {
    _say(Skin,
         text("Failed: %zu of %zu surfaces meshed", meshed, faces).c_str());
    return false;
  }
  _say(Skin, text("%zu triangles of size %g", triangles, size));
  return true;
}

void midsurfacerWindow::run(int target)
{
  using namespace matgmsh_native;
  modelLock lock(modelLock::ifFree);
  if(!lock) return;
  State &s = *_state;
  GModel *model = GModel::current();

  Options options;
  options.thickness = thickness->value();
  if(!(options.thickness > 0.)) {
    Msg::Error("Midsurfacer: give the thickness of the thickest wall first");
    return;
  }
  const bool legacy = method->value() == 1;
  options.raw = legacy ? RawMode::Legacy : RawMode::Tet;
  options.filter = legacy ? FilterMode::Legacy : FilterMode::Collapse;
  options.collapseThreshold = threshold->value();
  options.extensionLength = length->value();
  options.extensionLayers = std::max(1, (int)layers->value());
  options.project = true;

  bool viewsChanged = false;
  auto busy = [&](int stage) {
    status[stage]->copy_label("Running...");
    win->redraw();
    FlGui::check();
  };
  auto failed = [&](int stage, const std::string &error) {
    Msg::Error("Midsurfacer: %s", error.c_str());
    if(!FlGui::available()) return;
    status[stage]->copy_label("Failed (see the messages)");
    status[stage]->copy_tooltip(error.c_str());
    FlGui::instance()->updateViews(true);
    drawContext::global()->draw();
  };
  auto done = [&](int stage) {
    _showOnly(stage);
    if(viewsChanged) FlGui::instance()->updateViews(true);
    drawContext::global()->draw();
  };
  // the warnings of the stages, each said once for a raw MAT
  auto warn = [&]() {
    for(const std::string &w : s.session.result().warnings)
      if(s.said.insert(w).second) Msg::Warning("Midsurfacer: %s", w.c_str());
  };
  std::string error;

  // 1. the skin: meshed if asked for, or if a surface has no triangle
  std::size_t faces, meshed, triangles;
  countSkin(model, faces, meshed, triangles);
  if(target == Skin || meshed < faces || !faces) {
    _forget(Raw);
    viewsChanged = true;
    if(!_skin()) {
      if(FlGui::available()) {
        FlGui::instance()->updateViews(true);
        drawContext::global()->draw();
      }
      return;
    }
  }
  if(target == Skin) {
    done(Skin);
    return;
  }

  // 2. the raw MAT: kept, unless it is asked for, or the model, its mesh or
  // the method changed
  if(target == Raw || !s.session.hasRaw() || s.model != model ||
     s.stamps.changed() || s.method != method->value()) {
    _forget(Raw);
    viewsChanged = true;
    busy(Raw);
    bool ok = s.session.raw(model, options, error);
    if(!FlGui::available()) return;
    if(!ok) {
      failed(Raw, error);
      return;
    }
    s.model = model;
    s.stamps.record();
    s.method = method->value();
    s.threshold = -1.;
    s.said.clear();
    const Result &r = s.session.result();
    if(r.tet.computed)
      _say(Raw,
           text("Certificate %s (%.3g s)",
                r.tet.certified ? "passed" : "FAILED", r.rawSeconds),
           text("%zu sites, %zu tetrahedra of which %zu are interior, %zu "
                "polygons. The certificate (the interior tetrahedra are "
                "bounded by a closed surface through every site, with the "
                "Euler characteristic of the skin) %s",
                r.tet.sites, r.tet.tetrahedra, r.tet.interior, r.tet.polygons,
                r.tet.certified ? "passed" : "FAILED"));
    else
      _say(Raw, text("%zu triangles (%.3g s)", r.raw.triangles.size() / 3,
                     r.rawSeconds));
    _view(Raw);
    warn();
  }
  if(target == Raw) {
    done(Raw);
    return;
  }

  // 3. the filter: kept, unless it is asked for or its parameters changed
  if(target == Filter || !s.session.hasFiltered() ||
     s.thickness != options.thickness ||
     s.threshold != options.collapseThreshold) {
    _forget(Filter);
    viewsChanged = true;
    busy(Filter);
    bool ok = s.session.filter(model, options, error);
    if(!FlGui::available()) return;
    if(!ok) {
      failed(Filter, error);
      return;
    }
    s.thickness = options.thickness;
    s.threshold = options.collapseThreshold;
    const Result &r = s.session.result();
    const Topology &t = r.filteredTopology;
    std::string what =
      text("%zu piece%s, Euler characteristic %lld", t.components,
           t.components == 1 ? "" : "s", t.euler);
    if(r.collapse.computed && r.collapse.wireEdges)
      what += text(", %zu edges without surface", r.collapse.wireEdges);
    what += text(" (%.3g s)", r.filterSeconds);
    _say(Filter, what,
         text("%zu triangles in %zu piece%s, Euler characteristic %lld, %zu "
              "free edges, %zu junction edges",
              t.triangles, t.components, t.components == 1 ? "" : "s",
              t.euler, t.freeEdges, t.junctionEdges));
    _view(Filter);
    warn();
  }
  if(target == Filter) {
    done(Filter);
    return;
  }

  // 4. the projection, when asked for
  if(target == Projection) {
    _forget(Projection);
    viewsChanged = true;
    busy(Projection);
    bool ok = s.session.project(model, options, error);
    if(!FlGui::available()) return;
    if(!ok) {
      failed(Projection, error);
      return;
    }
    const Result &r = s.session.result();
    const bool applied = r.projectionStatus == "applied";
    _say(Projection,
         text("%s (%.3g s)", applied ? "Applied" : "Unchanged",
              r.projectionSeconds),
         r.projectionMessage);
    if(applied) _view(Projection);
    done(applied ? Projection : Filter);
    return;
  }

  // 5. the extension, of the projected MAT if there is one
  _forget(Extension);
  viewsChanged = true;
  busy(Extension);
  bool ok = s.session.extend(model, options, error);
  if(!FlGui::available()) return;
  if(!ok) {
    failed(Extension, error);
    return;
  }
  const Result &r = s.session.result();
  std::size_t closed = 0;
  for(const FrontStatus &f : r.extension.fronts)
    if(f.status != "unresolved") closed++;
  _say(Extension,
       text("%s, %zu triangles added (%.3g s)",
            r.extension.complete ? "Complete" : "Partial",
            r.extension.addedTriangles, r.extensionSeconds),
       text("%zu of the %zu free edges of the input reach the skin or "
            "another sheet. ",
            closed, r.extension.fronts.size()) +
         r.extension.message);
  _view(Extension);
  warn();
  done(Extension);
}

#endif
