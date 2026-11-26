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
#include <functional>
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
#include "fileDialogs.h"

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

// With the wing branches removed whole the mid-sheets end on the lines where
// the wings were attached, and a positive threshold would notch these lines:
// ticking the box sets the threshold to 0, unticking it puts it back.
void branches_cb(Fl_Widget *w, void *data)
{
  static double before = .21;
  midsurfacerWindow *m = FlGui::instance()->midsurfacer;
  if(m->branches->value()) {
    if(m->threshold->value() > 0.) before = m->threshold->value();
    m->threshold->value(0.);
    m->angle->activate();
  }
  else {
    if(m->threshold->value() == 0.) m->threshold->value(before);
    m->angle->deactivate();
  }
  m->update();
}

void update_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->update(); }

void angles_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->showAngles(); }

void select_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->selectBranch(); }

void preview_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->previewBranch(); }

void extend_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->extendBranch(data != nullptr); }

void undo_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->undoExtension(data != nullptr); }

void save_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->midsurfacer->save(); }

// a view of a mesh, with one value per triangle
PView *meshView(const matgmsh_native::Mesh &mesh, const std::string &name,
                const std::function<double(std::size_t)> &value,
                const std::function<bool(std::size_t)> &shown = nullptr)
{
  PViewDataList *data = new PViewDataList();
  for(std::size_t t = 0; t < mesh.triangles.size() / 3; t++) {
    if(shown && !shown(t)) continue;
    std::vector<double> *values = data->incrementList(1, TYPE_TRI);
    for(int component = 0; component < 3; component++)
      for(int corner = 0; corner < 3; corner++)
        values->push_back(
          mesh.xyz[3 * mesh.triangles[3 * t + corner] + component]);
    const double v = value(t);
    values->insert(values->end(), {v, v, v});
  }
  data->setName(name);
  data->setFileName(name + ".pos");
  data->finalize();
  PView *view = new PView(data);
  view->getOptions()->visible = 0;
  return view;
}

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
  int method = -1, branches = -1;
  double thickness = 0., threshold = -1., angle = -1.;
  // the view of each stage: its tag, and its data, to tell it from a view
  // that took the tag since
  int tag[NumViews];
  PViewData *data[NumViews];
  // the warnings of the stages already said for this raw MAT
  std::set<std::string> said;
  // the MAT being extended (the filtered or projected one, then with the
  // branches extended so far), its branches as listed, the one selected and
  // those already extended
  matgmsh_native::Mesh work;
  bool hasWork = false;
  std::vector<matgmsh_native::BranchPlane> planes;
  int selected = -1;
  std::set<int> extended;
  // the MAT and the branches extended before each of the last extensions
  std::vector<std::pair<matgmsh_native::Mesh, std::set<int> > > history;
  State()
  {
    for(int i = 0; i < NumViews; i++) {
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
  int height = 2 * WB + 23 * BH + 6 * section;

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
    input("Thickness (of the thickest wall)", 0., 0., 1.e22, .01,
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
  threshold->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  threshold->callback(update_cb);
  branches = new Fl_Check_Button(x, y, full, BH, "Remove the wings by their angle");
  branches->tooltip(
    "A polygon of the raw medial axis that sees its two contacts with the "
    "skin under less than the angle below is a wing if it burns from the "
    "free boundary like the bisector of a wedge does, or if it belongs to a "
    "branch made of such polygons (nine tenths of its area) that touches "
    "the free boundary: it is removed, whatever the threshold and the "
    "thickness. The strip of a mid-sheet along a junction, seen under a "
    "small angle too, stays. The threshold is then set to 0, so that the "
    "mid-sheets end where the wings were attached; a positive threshold "
    "erodes them further and notches these lines");
  branches->callback(branches_cb);
  // the default of the window: wings go whole, and nothing else is eroded
  branches->value(1);
  threshold->value(0.);
  y += BH;
  angle = input("Angle of a wing, at most (degrees)", 135., 1., 180., 1.,
                "The angle under which a polygon of the medial axis sees "
                "its two contacts with the skin: 90 degrees on the wing of "
                "a right-angled edge, 180 between two facing walls. Once "
                "the medial axis is filtered, a new value filters it again");
  angle->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  angle->callback(update_cb);
  angles = new Fl_Check_Button(x, y, full, BH, "Show the angle of the wings");
  angles->tooltip(
    "The raw medial axis colored by the angle under which its polygons see "
    "their two contacts, where they burn like a wing or belong to a wing "
    "branch (180 for the others, which are never removed): what is below "
    "the angle above is removed. Available once filtered");
  angles->callback(angles_cb);
  y += BH;
  action(Filter, "Filter",
         "Filter the medial axis; the raw medial axis is not computed again");

  title("4. Projection (optional)");
  action(Projection, "Project",
         "Project the filtered medial axis onto the local mid-surface; a "
         "projection that fails its checks changes nothing");

  title("5. Extension, branch by branch");
  {
    static int widths[] = {0, 0, 0};
    widths[0] = full / 4;
    widths[1] = full / 3;
    browser = new Fl_Hold_Browser(x, y, full, 5 * BH);
    browser->column_widths(widths);
    browser->callback(select_cb);
    browser->tooltip(
      "The branches of the filtered medial axis, largest first: number, "
      "area, and how far 95% of the area is from the plane of the branch. "
      "A branch chosen here is shown alone");
    y += 5 * BH;
  }
  static Fl_Menu_Item hows[] = {{"In its plane", 0, nullptr, nullptr},
                                {"Ribbon", 0, nullptr, nullptr},
                                {nullptr}};
  how = new Fl_Choice(x, y, IW, BH, "How the branch is extended");
  how->menu(hows);
  how->align(FL_ALIGN_RIGHT);
  how->tooltip(
    "In its plane, for a flat branch: a rectangle of the plane around the "
    "whole part is cut by the skin and by the other branches, and the "
    "fragments that hold a triangle of the branch replace it (with the "
    "other branches lying in the same plane inside them). Ribbon, for any "
    "branch: a ribbon is drawn from its free boundary, tangent to the "
    "branch and normal to the boundary, then cut by the skin, by the other "
    "branches and where it crosses itself; the pieces attached to the "
    "boundary are added");
  y += BH;
  length = input("Reach (0: 2 x thickness)", 0., 0., 1.e22, .01,
                 "How far a branch is extended: the length of the ribbon, and "
                 "in its plane the distance to the branch beyond which the "
                 "fragments are dropped");
  layers = input("Layers of the ribbon", 4., 1., 100., 1.,
                 "Number of rows of triangles across the ribbon");
  action(Extension, "Extend",
         "Extend the selected branch: the result replaces it in the view "
         "\"MAT extended\"");
  push[Extension]->callback(extend_cb, nullptr);
  preview = new Fl_Button(width - 2 * BB - 3 * WB, y - BH, BB, BH, "Preview");
  preview->callback(preview_cb);
  preview->tooltip(
    "Show what would extend the selected branch, without changing "
    "anything: the fragments of its plane (0 on those kept), or its ribbon "
    "before it is cut, colored by the distance to the boundary");
  // the status of this stage goes on its own line, under the buttons
  status[Extension]->resize(x, y, full - BB - WB, BH);
  all = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Extend all");
  all->callback(extend_cb, (void *)1);
  all->tooltip(
    "Extend every branch: the flat ones in their plane, largest first, "
    "then the others by ribbons");
  y += BH;
  saveAs = new Fl_Button(x, y, BB, BH, "Save...");
  saveAs->callback(save_cb);
  saveAs->tooltip(
    "Save the medial axis as it is now (filtered, with the branches extended "
    "so far) as an MSH file: one surface per branch, and its edges in four "
    "groups of lines: on the skin, inside the part, junctions, and along "
    "another branch (where an extended branch stops on a sheet without "
    "sharing its vertices)");
  undo = new Fl_Button(width - 2 * BB - 3 * WB, y, BB, BH, "Undo");
  undo->callback(undo_cb, nullptr);
  undo->tooltip("Take back the last extension (Extend, or the whole of Extend all)");
  reset = new Fl_Button(width - BB - 2 * WB, y, BB, BH, "Reset");
  reset->callback(undo_cb, (void *)1);
  reset->tooltip("Take back every extension: back to the filtered medial axis");
  y += BH;

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
  // the branches listed are those of the filtered or projected MAT
  if(fromStage <= Projection) _listBranches(true);
  if(fromStage > Projection && fromStage <= Extension) status[Extension]->copy_label("");
  // the angles of the branches are those of the raw MAT
  if(fromStage <= Raw) {
    if(PView *v = _state->view(Angles)) delete v;
    _state->tag[Angles] = -1;
    _state->data[Angles] = nullptr;
    angles->value(0);
  }
}

// the view of a stage, colored by sheet
void midsurfacerWindow::_view(int stage)
{
  const matgmsh_native::Result &r = _state->session.result();
  const matgmsh_native::Mesh &mesh = stage == Raw ? r.raw :
                                     stage == Filter ? r.filtered :
                                     stage == Projection ? r.projected :
                                                           _state->work;
  if(mesh.triangles.empty()) return;
  if(PView *old = _state->view(stage)) delete old;
  PView *view =
    meshView(mesh, std::string("MAT ") + stageName[stage], [&](std::size_t t) {
      return t < mesh.branch.size() ? (double)mesh.branch[t] : 0.;
    });
  _state->tag[stage] = view->getTag();
  _state->data[stage] = view->getData();
  visible[stage]->activate();
}

// The branches of the MAT being extended: forgotten (reset without a filtered
// MAT), taken again from the filtered or projected MAT (reset), or listed
// again after an extension.
void midsurfacerWindow::_listBranches(bool reset)
{
  State &s = *_state;
  if(reset) {
    for(int i : {(int)Selected, (int)Preview, (int)Extension}) {
      if(PView *v = s.view(i)) delete v;
      s.tag[i] = -1;
      s.data[i] = nullptr;
    }
    visible[Extension]->value(0);
    visible[Extension]->deactivate();
    s.work = matgmsh_native::Mesh{};
    s.hasWork = false;
    s.selected = -1;
    s.extended.clear();
    s.history.clear();
    s.planes.clear();
  }
  browser->clear();
  if(!s.hasWork) return;
  s.planes = matgmsh_native::branchPlanes(s.work);
  const double flat = .1 * thickness->value();
  int line = 0, chosen = 0;
  for(const matgmsh_native::BranchPlane &p : s.planes) {
    line++;
    browser->add(text("%d\t%.6g\t%s (%.2g)%s", p.branch, p.area,
                      p.deviation <= flat ? "flat" : "curved", p.deviation,
                      s.extended.count(p.branch) ? ", extended" : "")
                   .c_str());
    if(p.branch == s.selected) chosen = line;
  }
  if(chosen)
    browser->value(chosen);
  else
    s.selected = -1;
}

void midsurfacerWindow::selectBranch()
{
  State &s = *_state;
  for(int i : {(int)Selected, (int)Preview}) {
    if(PView *v = s.view(i)) delete v;
    s.tag[i] = -1;
    s.data[i] = nullptr;
  }
  const int line = browser->value();
  if(line < 1 || line > (int)s.planes.size()) {
    s.selected = -1;
    FlGui::instance()->updateViews(true);
    drawContext::global()->draw();
    return;
  }
  const matgmsh_native::BranchPlane &p = s.planes[line - 1];
  s.selected = p.branch;
  const bool flat = p.deviation <= .1 * thickness->value();
  how->value(flat ? 0 : 1);
  PView *view = meshView(
    s.work, "MAT branch", [](std::size_t) { return 1.; },
    [&](std::size_t t) { return t < s.work.branch.size() && s.work.branch[t] == p.branch; });
  view->getOptions()->showScale = 0;
  s.tag[Selected] = view->getTag();
  s.data[Selected] = view->getData();
  // the branch alone
  for(int i = Raw; i < NumStages; i++) {
    visible[i]->value(0);
    display(i, false);
  }
  angles->value(0);
  if(PView *v = s.view(Angles))
    opt_view_visible(v->getIndex(), GMSH_SET | GMSH_GUI, 0);
  FlGui::instance()->updateViews(true);
  opt_view_visible(view->getIndex(), GMSH_SET | GMSH_GUI, 1);
  status[Extension]->copy_label(
    text("Branch %d: area %.6g, %s (95%% within %.2g of its plane)", p.branch,
         p.area, flat ? "flat" : "curved", p.deviation)
      .c_str());
  drawContext::global()->draw();
}

// What extends a branch, in the view Preview; applied to the MAT being
// extended if asked. A ribbon that is only shown is not cut.
bool midsurfacerWindow::_extend(int branch, bool planar, bool apply,
                                std::string &what)
{
  using namespace matgmsh_native;
  State &s = *_state;
  const Result &r = s.session.result();
  const double t = thickness->value();
  const BranchPlane *p = nullptr;
  for(const BranchPlane &candidate : s.planes)
    if(candidate.branch == branch) p = &candidate;
  if(!p) {
    what = "this branch is no longer there";
    return false;
  }
  if(PView *v = s.view(Preview)) delete v;
  s.tag[Preview] = -1;
  s.data[Preview] = nullptr;
  std::string error;
  PView *view = nullptr;
  if(planar) {
    PlaneExtension e;
    const double reach = length->value() > 0. ? length->value() : 2. * t;
    if(!extendBranchInPlane(s.work, r.skin, *p, .1 * t, .25 * t, reach, e, error)) {
      what = error;
      return false;
    }
    what = text("%zu fragments of the plane, %zu kept; area %.6g for %.6g "
                "(%.6g before the reach), %zu triangles, %zu other branches "
                "in the same plane, %zu faces prolonged at the %zu reentrant "
                "corners of the section, %zu sheets of other branches "
                "prolonged to what they stop short of (%.2g s)",
                e.fragments, e.keptFragments, e.addedArea, p->area, e.keptArea,
                e.addedTriangles, e.merged.size(), e.fences, e.corners,
                e.closures, e.seconds);
    if(e.reachesFrame) {
      what = "the skin does not close the fragment of the plane around "
             "this branch: " + what;
      apply = false;
    }
    view = meshView(e.plane, "MAT plane fragments", [&](std::size_t i) {
      return (double)e.plane.branch[i];
    });
    if(apply) {
      s.work = std::move(e.result);
      s.extended.insert(branch);
      for(int merged : e.merged) s.extended.erase(merged);
    }
    else if(e.reachesFrame) {
      s.tag[Preview] = view->getTag();
      s.data[Preview] = view->getData();
      return false;
    }
  }
  else {
    Ribbon ribbon;
    const double l = length->value() > 0. ? length->value() : 2. * t;
    const Mesh &original =
      s.session.hasProjected() && r.projectionStatus == "applied" ? r.projected : r.filtered;
    if(!branchRibbon(s.work, branch, l, std::max(1, (int)layers->value()),
                     ribbon, error, &original)) {
      what = error;
      return false;
    }
    what = text("ribbon along %zu free edges of %zu, in %zu chains of "
                "length %.6g; so that it does not fold, directions turned "
                "at %zu vertices and ribbon shortened at %zu (%zu spans "
                "still fold)",
                ribbon.freeEdges, ribbon.boundaryEdges, ribbon.loops,
                ribbon.boundaryLength, ribbon.smoothedVertices,
                ribbon.shortenedVertices, ribbon.foldedEdges);
    if(!apply)
      view = meshView(ribbon.mesh, "MAT ribbon", [&](std::size_t i) {
        return (ribbon.v[ribbon.mesh.triangles[3 * i]] +
                ribbon.v[ribbon.mesh.triangles[3 * i + 1]] +
                ribbon.v[ribbon.mesh.triangles[3 * i + 2]]) / 3.;
      });
    else {
      PlaneExtension e;
      if(!extendBranchByRibbon(s.work, r.skin, branch, ribbon, e, error)) {
        what = error;
        return false;
      }
      what += text(": %zu rows stopped by the face that stops their "
                   "neighbours; %zu fragments, %zu kept (area %.6g, %zu "
                   "triangles)%s (%.2g s)",
                   e.stoppedRows, e.fragments, e.keptFragments, e.keptArea,
                   e.addedTriangles,
                   e.reachesFrame ? ", some reach the end of the ribbon" : "",
                   e.seconds);
      view = meshView(e.plane, "MAT ribbon pieces", [&](std::size_t i) {
        return (double)e.plane.branch[i];
      });
      s.work = std::move(e.result);
      s.extended.insert(branch);
    }
  }
  s.tag[Preview] = view->getTag();
  s.data[Preview] = view->getData();
  return true;
}

void midsurfacerWindow::previewBranch()
{
  modelLock lock(modelLock::ifFree);
  if(!lock) return;
  State &s = *_state;
  if(s.selected < 0) {
    Msg::Warning("Midsurfacer: choose a branch in the list first");
    return;
  }
  std::string what;
  const bool planar = how->value() == 0;
  const bool ok = _extend(s.selected, planar, false, what);
  status[Extension]->copy_label(what.c_str());
  status[Extension]->copy_tooltip(what.c_str());
  if(ok)
    Msg::Info("Midsurfacer, branch %d: %s", s.selected, what.c_str());
  else
    Msg::Warning("Midsurfacer, branch %d: %s", s.selected, what.c_str());
  FlGui::instance()->updateViews(true);
  // the fragments of the plane lie on the branch: they are shown without it
  if(PView *v = s.view(Selected))
    opt_view_visible(v->getIndex(), GMSH_SET | GMSH_GUI, planar && s.view(Preview) ? 0 : 1);
  if(PView *v = s.view(Preview))
    opt_view_visible(v->getIndex(), GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();
}

void midsurfacerWindow::extendBranch(bool everyBranch)
{
  State &s = *_state;
  if(!s.session.hasFiltered()) run(Filter);
  modelLock lock(modelLock::ifFree);
  if(!lock) return;
  if(!s.hasWork) {
    Msg::Warning("Midsurfacer: filter the medial axis first");
    return;
  }
  const double flat = .1 * thickness->value();
  // the branches to extend, with how: one, or the flat ones in their plane
  // then the others by ribbons
  std::vector<std::pair<int, bool> > todo;
  if(!everyBranch) {
    if(s.selected < 0) {
      Msg::Warning("Midsurfacer: choose a branch in the list first");
      return;
    }
    todo.push_back({s.selected, how->value() == 0});
  }
  else {
    for(const matgmsh_native::BranchPlane &p : s.planes)
      if(p.deviation <= flat && !s.extended.count(p.branch)) todo.push_back({p.branch, true});
    for(const matgmsh_native::BranchPlane &p : s.planes)
      if(p.deviation > flat && !s.extended.count(p.branch)) todo.push_back({p.branch, false});
  }
  // what Undo gives back (the last 10 extensions)
  s.history.push_back({s.work, s.extended});
  if(s.history.size() > 10) s.history.erase(s.history.begin());
  std::size_t done = 0, failed = 0;
  std::string what;
  for(std::size_t i = 0; i < todo.size(); i++) {
    if(everyBranch) {
      status[Extension]->copy_label(
        text("Branch %d (%zu of %zu)...", todo[i].first, i + 1, todo.size()).c_str());
      win->redraw();
      FlGui::check();
      if(!FlGui::available()) return;
    }
    // a branch can have gone with another one lying in the same plane
    bool there = false;
    for(const matgmsh_native::BranchPlane &p : s.planes) there = there || p.branch == todo[i].first;
    if(!there) continue;
    if(_extend(todo[i].first, todo[i].second, true, what)) {
      done++;
      Msg::Info("Midsurfacer, branch %d: %s", todo[i].first, what.c_str());
      s.planes = matgmsh_native::branchPlanes(s.work);
    }
    else {
      failed++;
      Msg::Warning("Midsurfacer, branch %d: %s", todo[i].first, what.c_str());
    }
  }
  if(!done) s.history.pop_back();
  if(everyBranch)
    what = text("%zu branches extended, %zu not (see the messages)", done, failed);
  status[Extension]->copy_label(what.c_str());
  status[Extension]->copy_tooltip(what.c_str());
  // the MAT with its branches extended, alone
  if(PView *v = s.view(Selected)) delete v;
  s.tag[Selected] = -1;
  s.data[Selected] = nullptr;
  _view(Extension);
  _listBranches(false);
  FlGui::instance()->updateViews(true);
  if(PView *v = s.view(Preview))
    opt_view_visible(v->getIndex(), GMSH_SET | GMSH_GUI, 0);
  for(int i = Raw; i < NumStages; i++) {
    visible[i]->value(i == Extension && s.view(Extension));
    display(i, false);
  }
  drawContext::global()->draw();
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
  angles->value(0);
  if(PView *v = _state->view(Angles))
    opt_view_visible(v->getIndex(), GMSH_SET | GMSH_GUI, 0);
}

void midsurfacerWindow::update()
{
  if(_state->session.hasFiltered()) run(Filter);
}

void midsurfacerWindow::showAngles()
{
  const matgmsh_native::Result &r = _state->session.result();
  if(!angles->value()) {
    if(PView *v = _state->view(Angles))
      opt_view_visible(v->getIndex(), GMSH_SET | GMSH_GUI, 0);
    if(_state->view(Filter)) {
      visible[Filter]->value(1);
      display(Filter, false);
    }
    drawContext::global()->draw();
    return;
  }
  if(!_state->session.hasFiltered() || r.contactAngle.empty()) {
    Msg::Warning("Midsurfacer: filter the medial axis first (method "
                 "Tetrahedra) to see the angle of its wings");
    angles->value(0);
    return;
  }
  bool created = false;
  if(!_state->view(Angles)) {
    const matgmsh_native::Mesh &mesh = r.raw;
    PViewDataList *data = new PViewDataList();
    for(std::size_t t = 0; t < mesh.triangles.size() / 3; t++) {
      std::vector<double> *values = data->incrementList(1, TYPE_TRI);
      for(int component = 0; component < 3; component++)
        for(int corner = 0; corner < 3; corner++)
          values->push_back(
            mesh.xyz[3 * mesh.triangles[3 * t + corner] + component]);
      // 180 for what is never removed: it does not burn like a wing, or it
      // has no area
      double a = 180.;
      const int p = t < mesh.parent.size() ? mesh.parent[t] : -1;
      if(p >= 0 && (std::size_t)p < r.contactAngle.size() &&
         r.wingCandidate[p] && r.contactAngle[p] == r.contactAngle[p])
        a = r.contactAngle[p];
      values->insert(values->end(), {a, a, a});
    }
    data->setName("MAT wing angle");
    data->setFileName("mat_wing_angle.pos");
    data->finalize();
    PView *view = new PView(data);
    PViewOptions *o = view->getOptions();
    o->intervalsType = PViewOptions::Discrete;
    o->nbIso = 12; // bands of 15 degrees
    o->rangeType = PViewOptions::Custom;
    o->customMin = 0.;
    o->customMax = 180.;
    _state->tag[Angles] = view->getTag();
    _state->data[Angles] = data;
    created = true;
  }
  for(int i = Raw; i < NumStages; i++) {
    visible[i]->value(0);
    display(i, false);
  }
  if(created) FlGui::instance()->updateViews(true);
  if(PView *v = _state->view(Angles))
    opt_view_visible(v->getIndex(), GMSH_SET | GMSH_GUI, 1);
  drawContext::global()->draw();
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
  options.wingBranches = branches->value() != 0;
  options.branchAngle = std::min(180., std::max(1., angle->value()));
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
     s.threshold != options.collapseThreshold ||
     s.branches != (int)options.wingBranches ||
     s.angle != options.branchAngle) {
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
    s.branches = options.wingBranches;
    s.angle = options.branchAngle;
    const Result &r = s.session.result();
    const Topology &t = r.filteredTopology;
    std::string what =
      text("%zu piece%s, Euler characteristic %lld", t.components,
           t.components == 1 ? "" : "s", t.euler);
    if(r.collapse.computed && r.collapse.wireEdges)
      what += text(", %zu edges without surface", r.collapse.wireEdges);
    what += text(" (%.3g s)", r.filterSeconds);
    std::string more =
      text("%zu triangles in %zu piece%s, Euler characteristic %lld, %zu "
           "free edges, %zu junction edges",
           t.triangles, t.components, t.components == 1 ? "" : "s", t.euler,
           t.freeEdges, t.junctionEdges);
    if(options.wingBranches && r.collapse.computed)
      more += text("; %zu of the %zu branches of the raw medial axis are "
                   "wings",
                   r.collapse.wingBranches, r.collapse.branches);
    _say(Filter, what, more);
    _view(Filter);
    warn();
    s.work = r.filtered;
    s.hasWork = true;
    _listBranches(false);
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
    s.work = applied ? r.projected : r.filtered;
    s.hasWork = true;
    _listBranches(false);
    done(applied ? Projection : Filter);
    return;
  }

  // 5. the extension has its own buttons (see extendBranch)
}

// Takes back the last extension, or all of them: the MAT being extended is
// the one before, or the filtered (or projected) MAT again.
void midsurfacerWindow::undoExtension(bool everything)
{
  modelLock lock(modelLock::ifFree);
  if(!lock) return;
  State &s = *_state;
  if(!s.hasWork || s.history.empty()) {
    Msg::Info("Midsurfacer: no extension to take back");
    return;
  }
  const std::size_t back = everything ? s.history.size() : 1;
  s.work = std::move(s.history[s.history.size() - back].first);
  s.extended = std::move(s.history[s.history.size() - back].second);
  s.history.resize(s.history.size() - back);
  const bool filteredAgain = s.extended.empty();
  for(int i : {(int)Selected, (int)Preview}) {
    if(PView *v = s.view(i)) delete v;
    s.tag[i] = -1;
    s.data[i] = nullptr;
  }
  if(filteredAgain) {
    if(PView *v = s.view(Extension)) delete v;
    s.tag[Extension] = -1;
    s.data[Extension] = nullptr;
    visible[Extension]->value(0);
    visible[Extension]->deactivate();
  }
  else
    _view(Extension);
  _listBranches(false);
  const std::string what =
    filteredAgain ? "Back to the filtered medial axis" :
                    text("Last extension taken back (%zu left)", s.history.size());
  status[Extension]->copy_label(what.c_str());
  status[Extension]->copy_tooltip(what.c_str());
  Msg::Info("Midsurfacer: %s", what.c_str());
  FlGui::instance()->updateViews(true);
  const int shown = filteredAgain ? (s.view(Projection) ? (int)Projection : (int)Filter) : (int)Extension;
  for(int i = Raw; i < NumStages; i++) {
    visible[i]->value(i == shown && s.view(i));
    display(i, false);
  }
  drawContext::global()->draw();
}

// The MAT being extended, or the filtered one before any extension, with its
// branches and its classified edges.
void midsurfacerWindow::save(const std::string &name)
{
  State &s = *_state;
  if(!s.hasWork) {
    Msg::Warning("Midsurfacer: filter the medial axis first");
    return;
  }
  std::string file = name;
  if(file.empty()) {
    if(!fileChooser(FILE_CHOOSER_CREATE, "Save the mid-surface", "*.msh")) return;
    file = fileChooserGetName(1);
  }
  if(file.empty()) return;
  if(file.size() < 4 || file.compare(file.size() - 4, 4, ".msh")) file += ".msh";
  matgmsh_native::ClassifiedEdges c;
  std::string error;
  if(!matgmsh_native::writeClassifiedMesh(s.work, s.session.result().skin, file, c, error)) {
    Msg::Error("Midsurfacer: %s", error.c_str());
    return;
  }
  const std::string what =
    text("Saved %zu branches; edges: %zu on the skin, %zu inside, %zu at junctions, "
         "%zu along another branch",
         c.branches, c.onSkin, c.inside, c.junction, c.along);
  status[Extension]->copy_label(what.c_str());
  status[Extension]->copy_tooltip((what + " (" + file + ")").c_str());
  Msg::Info("Midsurfacer: %s, in '%s'", what.c_str(), file.c_str());
}

#endif
