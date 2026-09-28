// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <vector>
#include <utility>
#include <ctime>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <functional>
#include <filesystem>
#if !defined(WIN32) || defined(__CYGWIN__)
#include <fnmatch.h>
#endif

#include "GuiActions.h"
#include "GmshVersion.h"
#include "GmshDefines.h"
#include "Context.h"
#include "Options.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "OS.h"
#include "StringUtils.h"
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "scriptStringInterface.h"
#include "Gui.h"
#include "drawContext.h"

#if defined(HAVE_ONELAB)
#include "onelab.h"
#include "onelabUtils.h"
#include "gmshLocalNetworkClient.h"
#endif

#if defined(HAVE_MESH)
#include "Field.h"
#include "gmshCrossFields.h"
#include "Generator.h"
#include "HighOrder.h"
#include "MElement.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "GModelParametrize.h"
#include "meshGFaceDelaunay.h"
#endif

#if defined(HAVE_OPTHOM)
#include "HighOrderMeshOptimizer.h"
#include "HighOrderMeshElasticAnalogy.h"
#include "HighOrderMeshFastCurving.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#endif

#if defined(HAVE_GUI)
#include "Gui.h"
#endif

#include "sceneHost.h"
#include "sceneView.h"

void visibility_save(const std::string &fileName)
{
  // get the whole visibility information in geo format
  std::vector<int> state[4][2];
  GModel *m = GModel::current();
  for(auto it = m->firstVertex(); it != m->lastVertex(); it++)
    (*it)->getVisibility() ? state[0][1].push_back((*it)->tag()) :
                             state[0][0].push_back((*it)->tag());
  for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
    (*it)->getVisibility() ? state[1][1].push_back((*it)->tag()) :
                             state[1][0].push_back((*it)->tag());
  for(auto it = m->firstFace(); it != m->lastFace(); it++)
    (*it)->getVisibility() ? state[2][1].push_back((*it)->tag()) :
                             state[2][0].push_back((*it)->tag());
  for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
    (*it)->getVisibility() ? state[3][1].push_back((*it)->tag()) :
                             state[3][0].push_back((*it)->tag());
  std::vector<std::pair<int, int> > entities;
  int mode = 0, on = 0, off = 0;
  for(int i = 0; i < 4; i++) {
    on += state[i][1].size();
    off += state[i][0].size();
  }
  if(on > off) {
    scriptSetVisibilityAll(1, fileName);
    if(!off) return;
    mode = 0;
  }
  else {
    scriptSetVisibilityAll(0, fileName);
    if(!on) return;
    mode = 1;
  }
  for(int i = 0; i < 4; i++) {
    if(state[i][mode].size()) {
      for(std::size_t j = 0; j < state[i][mode].size(); j++) {
        entities.push_back(std::make_pair(i, state[i][mode][j]));
      }
    }
  }
  scriptSetVisibility(mode, entities, fileName);
}

void meshModifyParts(const std::string &what, const std::string &action)
{
  int type;
  if(what == "elements") {
    CTX::instance()->pickElements = 1;
    type = ENT_ALL;
  }
  else if(what == "curves") {
    CTX::instance()->pickElements = 0;
    type = ENT_CURVE;
  }
  else if(what == "surfaces") {
    CTX::instance()->pickElements = 0;
    type = ENT_SURFACE;
  }
  else if(what == "volumes") {
    CTX::instance()->pickElements = 0;
    type = ENT_VOLUME;
  }
  else {
    Msg::Error("Unknown mesh part '%s'", what.c_str());
    return;
  }

  // what is picked is only marked, so that 'u' can take it back; 'e' deletes or
  // reverses the lot
  std::vector<MElement *> ele;
  std::vector<GEntity *> ent;

  while(1) {
    if(!Gui::instance().available()) return;

    CTX::instance()->meshChanged();
    drawContext::global()->draw();

    if(ele.size() || ent.size())
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection, 'u' to undo last selection "
                    "or 'q' to abort]",
                    what.c_str());
    else
      Msg::StatusGl("Select %s\n"
                    "[Press 'e' to end selection or 'q' to abort]",
                    what.c_str());

    char ib = Gui::instance().selectEntity(type);
    if(!Gui::instance().available()) return;

    if(ib == 'l') {
      if(CTX::instance()->pickElements) {
        for(auto e : Gui::instance().selectedElements()) {
          if(e->getVisibility() != 2) {
            e->setVisibility(2);
            ele.push_back(e);
          }
        }
      }
      else {
        std::vector<GEntity *> picked;
        for(auto e : Gui::instance().selectedEdges()) picked.push_back(e);
        for(auto f : Gui::instance().selectedFaces()) picked.push_back(f);
        for(auto r : Gui::instance().selectedRegions()) picked.push_back(r);
        for(auto g : picked) {
          if(g->getSelection() != 1) {
            g->setSelection(1);
            ent.push_back(g);
          }
        }
      }
    }
    if(ib == 'r') {
      if(CTX::instance()->pickElements) {
        for(auto e : Gui::instance().selectedElements()) e->setVisibility(1);
      }
      else {
        for(auto e : Gui::instance().selectedEdges()) e->setSelection(0);
        for(auto f : Gui::instance().selectedFaces()) f->setSelection(0);
        for(auto r : Gui::instance().selectedRegions()) r->setSelection(0);
      }
    }
    if(ib == 'u') {
      if(CTX::instance()->pickElements) {
        if(ele.size()) {
          ele.back()->setVisibility(1);
          ele.pop_back();
        }
      }
      else {
        if(ent.size()) {
          ent.back()->setSelection(0);
          ent.pop_back();
        }
      }
    }
    if(ib == 'e') {
      if(CTX::instance()->pickElements) {
        for(std::size_t i = 0; i < ele.size(); i++)
          if(ele[i]->getVisibility() == 2) ele[i]->setVisibility(0);
      }
      else {
        for(std::size_t i = 0; i < ent.size(); i++)
          if(ent[i]->getSelection() == 1) {
            ent[i]->setVisibility(0);
            ent[i]->setSelection(0);
          }
      }
      if(action == "delete")
        GModel::current()->removeInvisibleElements();
      else if(action == "reverse")
        GModel::current()->reverseInvisibleElements();
      else
        Msg::Error("Unknown action '%s' on mesh part", action.c_str());
      ele.clear();
      ent.clear();
    }
    if(ib == 'q') {
      GModel::current()->setSelection(0);
      break;
    }
  }

  CTX::instance()->meshChanged();
  CTX::instance()->pickElements = 0;
  drawContext::global()->draw();
  Gui::instance().statistics.refresh();
  Msg::StatusGl("");
}

void meshClassifySurfaces(double angleInDegrees, bool ensureParametrizable,
                          GEdge **selected)
{
#if defined(HAVE_MESH)
  // the edges found go into a temporary discrete curve, which may already hold
  // edges picked by hand
  GEdge *local = nullptr;
  GEdge *&curve = selected ? *selected : local;
  if(!curve) {
    curve = new discreteEdge(GModel::current(),
                             GModel::current()->getMaxElementaryNumber(1) + 1,
                             nullptr, nullptr);
    GModel::current()->add(curve);
  }

  computeDiscreteCurvatures(GModel::current());
  if(ensureParametrizable)
    computeEdgeCut(GModel::current(), curve->lines,
                   CTX::instance()->mesh.reparamMaxTriangles);
  computeNonManifoldEdges(GModel::current(), curve->lines, true);
  classifyFaces(GModel::current(), angleInDegrees / 180. * M_PI);

  GModel::current()->remove(curve);
  curve->lines.clear();
  delete curve;
  curve = nullptr;

  GModel::current()->pruneMeshVertexAssociations();

  if(ensureParametrizable)
    GModel::current()->createGeometryOfDiscreteEntities();

  opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 1.);
  CTX::instance()->meshChanged();
  drawContext::global()->draw();
#else
  Msg::Error("Reclassifying surfaces requires the mesh module");
#endif
}

void messagesSaveAs()
{
  std::string fileName;
  if(Gui::instance().fileDialog(Gui::Create, "Save Messages", "", fileName))
    messagesSave(fileName);
}

void pickWithMouse(bool on)
{
  opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, on ? 1 : 0);
  Gui::instance().setMouseSelection(on);
}

void viewSetOrientation(drawContext *ctx, const std::string &what,
                        bool reverse)
{
  if(!ctx) return;

  if(what == "r") {
    double axis[3] = {0., 0., 1.};
    if(!reverse) {
      ctx->addQuaternionFromAxisAndAngle(axis, -90.);
      if(CTX::instance()->camera) ctx->camera.tiltHeadRight();
    }
    else {
      ctx->addQuaternionFromAxisAndAngle(axis, 90.);
      if(CTX::instance()->camera) ctx->camera.tiltHeadLeft();
    }
  }
  else if(what == "x") {
    if(CTX::instance()->camera) { ctx->camera.alongX(); }
    else {
      ctx->r[0] = -90.;
      ctx->r[1] = 0.;
      ctx->r[2] = reverse ? 90. : -90.;
      ctx->setQuaternionFromEulerAngles();
    }
  }
  else if(what == "y") {
    if(CTX::instance()->camera) { ctx->camera.alongY(); }
    else {
      ctx->r[0] = -90.;
      ctx->r[1] = 0.;
      ctx->r[2] = reverse ? 0. : 180.;
      ctx->setQuaternionFromEulerAngles();
    }
  }
  else if(what == "z") {
    if(CTX::instance()->camera) { ctx->camera.alongZ(); }
    else {
      ctx->r[0] = 0.;
      ctx->r[1] = reverse ? 180. : 0.;
      ctx->r[2] = 0.;
      ctx->setQuaternionFromEulerAngles();
    }
  }
  else if(what == "1:1") {
    if(reverse) SetBoundingBox(true);
    if(CTX::instance()->camera) { ctx->camera.lookAtCg(); }
    else {
      ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
      ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
    }
  }
  else if(what == "reset") {
    if(CTX::instance()->camera) { ctx->camera.init(); }
    else {
      ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
      ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
      ctx->r[0] = ctx->r[1] = ctx->r[2] = 0.;
      ctx->setQuaternionFromEulerAngles();
    }
  }
}

bool viewIsAnimatable()
{
#if defined(HAVE_POST)
  if(CTX::instance()->post.animCycle) return true;
  for(std::size_t i = 0; i < PView::list.size(); i++)
    if(PView::list[i]->getData()->getNumTimeSteps() > 1) return true;
#endif
  return false;
}

void animationStep(int time, int incr, bool redraw)
{
  // avoid firing this routine recursively (can happen e.g when
  // keeping the finger down on the arrow key: if the system generates
  // too many events, we can overflow the stack--that happened on my
  // powerbook with the new, optimzed FLTK event handler)
  static bool busy = false;
  if(busy) return;
  busy = true;

  // if we watch some files this is a good time to check for new data
#if defined(HAVE_GUI)
  if(Gui::instance().available()) Gui::instance().watchFile();
#endif

  PView::animate(time, incr);
  if(redraw) drawContext::global()->draw();
  busy = false;
}

void animationTick()
{
  static double last = 0.;
  double now = TimeOfDay();
  if(now - last < CTX::instance()->post.animDelay) return;
  last = now;
  animationStep(!CTX::instance()->post.animCycle,
                CTX::instance()->post.animStep);
}

void animationStepBy(bool forward, bool views)
{
  int step = CTX::instance()->post.animStep;
  animationStep(views ? 0 : !CTX::instance()->post.animCycle,
                forward ? step : -step);
}

void animationRewind()
{
  if(!CTX::instance()->post.animCycle) {
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      int step = PView::list[i]->getData()->getFirstNonEmptyTimeStep();
      opt_view_timestep(i, GMSH_SET | GMSH_GUI, step);
    }
  }
  else
    PView::animate(false, 0);
  drawContext::global()->draw();
}

// --- project

void projectClear()
{
  if(CTX::instance()->lock || Gui::instance().solverBusy()) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  ClearProject();
#if defined(HAVE_ONELAB)
  if(onelabUtils::haveSolverToRun())
    Gui::instance().onelabAction("reset"); // this will call OpenProject
  else
#endif
    OpenProject(GModel::current()->getFileName());
  drawContext::global()->draw();
}

void projectReload()
{
  if(CTX::instance()->lock || Gui::instance().solverBusy()) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  std::string fileName = GModel::current()->getFileName();
  ClearProject();
  GModel::current()->setFileName(fileName);
  Gui::instance().onelabAction("reset"); // will call OpenProject
  drawContext::global()->draw();
}

void projectDelete()
{
  const std::string &name = GModel::current()->getFileName();
  std::string question = "Do you really want to delete file '" + name + "'?";
  if(Msg::GetAnswer(question.c_str(), 0, "Cancel", "Delete")) {
    UnlinkFile(name);
    Msg::Info("Deleted `%s'", name.c_str());
    projectClear();
  }
}

void projectOpenRecent(int index)
{
  if(index < 0 || index >= (int)CTX::instance()->recentFiles.size()) return;
  std::string name = CTX::instance()->recentFiles[index];
  if(name.empty()) return;
  OpenProject(name);
  drawContext::global()->draw();
}

void projectQuit()
{
  // save persistent info to disk
  if(CTX::instance()->sessionSave) {
    PrintOptions(
      0, GMSH_SESSIONRC, 0, 0,
      (CTX::instance()->homeDir + CTX::instance()->sessionFileName).c_str());
  }
  if(CTX::instance()->optionsSave == 1) {
    PrintOptions(
      0, GMSH_OPTIONSRC, 1, 0,
      (CTX::instance()->homeDir + CTX::instance()->optionsFileName).c_str());
  }
  else if(CTX::instance()->optionsSave == 2) {
    std::string fileName = GModel::current()->getFileName() + ".opt";
    PrintOptions(0, GMSH_FULLRC, 1, 0, fileName.c_str());
    // also save visibility info - same as with fltk::run("options")
    visibility_save(fileName);
  }

  if(Gui::instance().quitShouldExit())
    Msg::Exit(0);
  else
    Gui::instance().destroy();
}

void optionsSave(bool toProjectFile)
{
  std::string fileName =
    toProjectFile ? (GModel::current()->getFileName() + ".opt") :
                    (CTX::instance()->homeDir + CTX::instance()->optionsFileName);
  Msg::StatusBar(true, "Writing '%s'...", fileName.c_str());
  if(toProjectFile)
    PrintOptions(0, GMSH_FULLRC, 0, 0, fileName.c_str());
  else
    PrintOptions(0, GMSH_OPTIONSRC, 1, 1, fileName.c_str());
  Msg::StatusBar(true, "Done writing '%s'", fileName.c_str());
}

static void _forEachEditedView(std::function<void(int)> what)
{
#if defined(HAVE_POST)
  int i = Gui::instance().options.view;
  if(i >= 0 && i < (int)PView::list.size()) what(i);
#endif
}

void optionsAction(const std::string &what)
{
  if(what == "rotation_center_select") {
    Msg::StatusGl("Select point on geometry, mesh or post-processing view\n"
                  "[Press 'q' to abort]");
    // the point clicked, from the depth of the pick: no need to pick mesh
    // elements for it, which rebuilt the arrays of the mesh twice (a freeze of
    // seconds on a large mesh) to give the barycentre of an element
    if(Gui::instance().selectEntity(ENT_ALL) == 'l') {
      Gui &gui = Gui::instance();
      SPoint3 pc(0., 0., 0.);
      drawContext *ctx = gui.getCurrentDrawContext();
      double xyz[3];
      if(gui.selectedVertices().size())
        pc.setPosition(gui.selectedVertices()[0]->x(),
                       gui.selectedVertices()[0]->y(),
                       gui.selectedVertices()[0]->z());
      else if(ctx && ctx->pickPoint(xyz)) {
        pc.setPosition(xyz[0], xyz[1], xyz[2]);
        // on the curve or surface itself, not on the polyline or the
        // triangulation it is drawn as
        double t, uv[2] = {0., 0.};
        if(gui.selectedEdges().size()) {
          GPoint gp = gui.selectedEdges()[0]->closestPoint(pc, t);
          if(gp.succeeded()) pc.setPosition(gp.x(), gp.y(), gp.z());
        }
        else if(gui.selectedFaces().size()) {
          GPoint gp = gui.selectedFaces()[0]->closestPoint(pc, uv);
          if(gp.succeeded()) pc.setPosition(gp.x(), gp.y(), gp.z());
        }
      }
      else if(gui.selectedElements().size())
        pc = gui.selectedElements()[0]->barycenter();
      else if(gui.selectedEdges().size())
        pc = gui.selectedEdges()[0]->bounds().center();
      else if(gui.selectedFaces().size())
        pc = gui.selectedFaces()[0]->bounds().center();
      else if(gui.selectedRegions().size())
        pc = gui.selectedRegions()[0]->bounds().center();
#if defined(HAVE_POST)
      else if(gui.selectedViews().size() && gui.selectedViews()[0]->getData())
        pc = gui.selectedViews()[0]->getData()->getBoundingBox().center();
#endif
      opt_general_rotation_center0(0, GMSH_SET | GMSH_GUI, pc.x());
      opt_general_rotation_center1(0, GMSH_SET | GMSH_GUI, pc.y());
      opt_general_rotation_center2(0, GMSH_SET | GMSH_GUI, pc.z());
      if(ctx) ctx->recenterForRotationCenterChange(pc);
      gui.manipulator.reload();
    }
    GModel::current()->setSelection(0);
    Msg::StatusGl("");
    drawContext::global()->draw();
  }
  else if(what == "show_session_file" || what == "show_options_file") {
    std::string file = CTX::instance()->homeDir;
    file += (what == "show_session_file") ? CTX::instance()->sessionFileName :
                                            CTX::instance()->optionsFileName;
    Msg::GetAnswer(("File path: " + file).c_str(), 0, "OK", nullptr);
  }
  else if(what == "gamepad_configure") {
    Gui::instance().configureGamepad();
  }
  else if(what == "restoreDefaults") {
    optionsRestoreDefaults();
  }
  else if(what == "arrow_edit") {
    Gui::instance().arrow.show();
  }
  else if(what == "axes_fit") {
    SBoundingBox3d bbox = GModel::current()->bounds(true);
#if defined(HAVE_POST)
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(PView::list[i]->getOptions()->visible &&
         !PView::list[i]->getData()->getBoundingBox().empty())
        bbox += PView::list[i]->getData()->getBoundingBox();
#endif
    if(bbox.empty())
      bbox = SBoundingBox3d(CTX::instance()->min[0], CTX::instance()->min[1],
                            CTX::instance()->min[2], CTX::instance()->max[0],
                            CTX::instance()->max[1], CTX::instance()->max[2]);
    opt_general_axes_xmin(0, GMSH_SET | GMSH_GUI, bbox.min().x());
    opt_general_axes_ymin(0, GMSH_SET | GMSH_GUI, bbox.min().y());
    opt_general_axes_zmin(0, GMSH_SET | GMSH_GUI, bbox.min().z());
    opt_general_axes_xmax(0, GMSH_SET | GMSH_GUI, bbox.max().x());
    opt_general_axes_ymax(0, GMSH_SET | GMSH_GUI, bbox.max().y());
    opt_general_axes_zmax(0, GMSH_SET | GMSH_GUI, bbox.max().z());
    drawContext::global()->draw();
  }
#if defined(HAVE_POST)
  else if(what == "view_timestep_down" || what == "view_timestep_up") {
    double step = (what == "view_timestep_up") ? 1. : -1.;
    _forEachEditedView([step](int i) {
      opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                        opt_view_timestep(i, GMSH_GET, 0) + step);
    });
    drawContext::global()->draw();
  }
  else if(what == "view_range_min") {
    _forEachEditedView([](int i) {
      opt_view_custom_min(i, GMSH_SET | GMSH_GUI,
                          opt_view_min_visible(i, GMSH_GET, 0));
    });
    drawContext::global()->draw();
  }
  else if(what == "view_range_max") {
    _forEachEditedView([](int i) {
      opt_view_custom_max(i, GMSH_SET | GMSH_GUI,
                          opt_view_max_visible(i, GMSH_GET, 0));
    });
    drawContext::global()->draw();
  }
  else if(what == "view_recursion_down" || what == "view_recursion_up") {
    double step = (what == "view_recursion_up") ? 1. : -1.;
    _forEachEditedView([step](int i) {
      double v = opt_view_max_recursion_level(i, GMSH_GET, 0) + step;
      if(v >= 0.) opt_view_max_recursion_level(i, GMSH_SET | GMSH_GUI, v);
    });
    drawContext::global()->draw();
  }
#endif
  else
    Msg::Debug("No option window action '%s'", what.c_str());
}

void modelSetCurrent(int index)
{
  if(index < 0 || index >= (int)GModel::list.size()) return;
  GModel::current(index);
  SetBoundingBox();
  for(std::size_t i = 0; i < GModel::list.size(); i++)
    GModel::list[i]->setVisibility(0);
  GModel::current()->setVisibility(1);
  CTX::instance()->meshChanged();
  Msg::SetWindowTitle(GModel::current()->getFileName());
  Gui::instance().resetVisibility();
  Gui::instance().updateViews(true, true);
  Gui::instance().rebuildTree(true);
  drawContext::global()->draw();
}

// --- query and measure

namespace {

  // starting one stops the other, which is only over once its loop has
  // returned: the one taking over is started from the event loop
  int _pendingMode = 0; // 1: query, 2: measure
  bool _queryMode = false, _measureMode = false;

  sceneView *_currentView()
  {
    return Scene::host().current ? Scene::host().current() : nullptr;
  }

  // asked to stop while a click is waited for
  void _stopWaiting()
  {
    for(sceneView *v : sceneView::all()) v->quitSelection = 1;
  }

  // what the modes left on the pictures
  void _clearNotes()
  {
    GModel::current()->setSelection(0);
    for(sceneView *v : sceneView::all()) {
      v->getDrawContext()->clearMarks();
      v->pinTooltip("");
    }
    drawContext::global()->draw();
    Msg::StatusGl("");
  }

  void _startPending()
  {
    int what = _pendingMode;
    _pendingMode = 0;
    if(!what) return;
    void (*start)() = (what == 1) ? queryModel : measureModel;
    if(Scene::host().later)
      Scene::host().later(0., start);
    else
      start();
  }

  // a query and a measurement are picks: they need the mouse selection the
  // "S" button switches
  void _selectWithMouse()
  {
    if(!CTX::instance()->mouseSelection)
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
  }

} // namespace

bool queryMode() { return _queryMode; }

bool measureMode() { return _measureMode; }

void queryModel()
{
  Gui &gui = Gui::instance();
  if(!gui.available()) return;
  if(_queryMode) {
    _stopWaiting();
    return;
  }
  if(_measureMode) {
    _pendingMode = 1;
    _stopWaiting();
    return;
  }

  _queryMode = true;
  gui.refreshBar();
  int old = CTX::instance()->pickElements;
  CTX::instance()->pickElements = 1;
  _selectWithMouse();

  while(1) {
    if(!gui.available()) break;
    Msg::StatusGl("Click to query the model, Ctrl+click to add a query\n"
                  "[Press 'q' to abort]");
    char ib = gui.selectEntity(ENT_ALL);
    if(!gui.available()) break;
    if(ib == 'q') break;
    if(ib != 'l') continue;

    sceneView *on = _currentView();
    if(!on) break;
    drawContext *ctx = on->getDrawContext();
    double xyz[3];
    if(!ctx->pickPoint(xyz)) continue;

    GEntity *entity = nullptr;
    if(gui.selectedVertices().size())
      entity = gui.selectedVertices()[0];
    else if(gui.selectedEdges().size())
      entity = gui.selectedEdges()[0];
    else if(gui.selectedFaces().size())
      entity = gui.selectedFaces()[0];
    else if(gui.selectedRegions().size())
      entity = gui.selectedRegions()[0];
    MElement *element =
      gui.selectedElements().size() ? gui.selectedElements()[0] : nullptr;
    // a pick that found a mesh element returns it instead of the entity it
    // belongs to, which the query names as well
    if(!entity) entity = ctx->pickEntity();
    PView *view = gui.selectedViews().size() ? gui.selectedViews()[0] : nullptr;
    double pixel = ctx->pixel_equiv_x / ctx->s[0];

    // A view drawn as glyphs hides the model behind them: the arrow clicked
    // on hangs off the data it stands for, so the query asks about the point
    // of the model under it, where the views can be interpolated, and keeps
    // the point on the glyph only when there is nothing behind it.
    if(view) {
      std::vector<GVertex *> v;
      std::vector<GEdge *> e;
      std::vector<GFace *> f;
      std::vector<GRegion *> r;
      std::vector<MElement *> el;
      std::vector<SPoint2> p;
      std::vector<PView *> vw;
      double behind[3];
      int at[4];
      on->lastSelection(at); // where the click looked, not where the mouse is
      if(on->pick(ENT_ALL, true, false, at[0], at[1], at[2], at[3], v, e, f,
                  r, el, p, vw) &&
         ctx->pickPoint(behind)) {
        GEntity *under = v.size() ? (GEntity *)v[0] :
                         e.size() ? (GEntity *)e[0] :
                         f.size() ? (GEntity *)f[0] :
                         r.size() ? (GEntity *)r[0] :
                                    nullptr;
        if(queryBehind(view, xyz, behind, pixel)) {
          for(int k = 0; k < 3; k++) xyz[k] = behind[k];
          entity = under;
          element = el.size() ? el[0] : nullptr;
        }
        else if(!entity) {
          // the glyph is over something else than what it stands for: name
          // it, as the query is about a point of the view itself
          entity = under;
        }
      }
    }

    // what was hit may hold no element there (a point or a curve of the
    // geometry, drawn over the mesh and picked before it), or the point read
    // back may be off its surface: the element is then the one of the mesh
    // drawn under the point
    if(!element) element = queryElement(xyz, pixel);

    std::vector<std::string> info =
      queryPoint(xyz, entity, element, view, pixel);
    // the messages keep everything, the box over the picture the lines that
    // do not begin with a space, i.e. all but the detail of an element
    std::string text;
    for(std::size_t i = 0; i < info.size(); i++) {
      if(info[i].size()) Msg::Direct("%s", info[i].c_str());
      if(info[i].size() && info[i][0] == ' ') continue;
      text += (text.size() ? "\n" : "") + info[i];
    }
    GModel::current()->setSelection(0);
    bool add = on->addQuery();
    if(!add) ctx->clearMarks();
    ctx->addMark(xyz);
    drawContext::global()->draw();
    if(CTX::instance()->tooltips) on->pinTooltip(text, xyz, add);
  }

  CTX::instance()->pickElements = old;
  _queryMode = false;
  if(gui.available()) {
    gui.refreshBar();
    _clearNotes();
  }
  _startPending();
}

void measureModel()
{
  Gui &gui = Gui::instance();
  if(!gui.available()) return;
  if(_measureMode) {
    _stopWaiting();
    return;
  }
  if(_queryMode) {
    _pendingMode = 2;
    _stopWaiting();
    return;
  }

  _measureMode = true;
  gui.refreshBar();
  // not the mesh elements, only where the click hits
  _selectWithMouse();

  double first[3] = {0., 0., 0.};
  bool half = false; // the first point is taken, the second one is awaited

  while(1) {
    if(!gui.available()) break;
    Msg::StatusGl(half ? "Click the second point\n[Press 'q' to abort]" :
                         "Click the first point\n[Press 'q' to abort]");
    char ib = gui.selectEntity(ENT_ALL);
    if(!gui.available()) break;
    if(ib == 'q') break;
    if(ib != 'l') continue;

    sceneView *on = _currentView();
    if(!on) break;
    drawContext *ctx = on->getDrawContext();
    double xyz[3];
    if(!ctx->pickPoint(xyz)) continue;
    GModel::current()->setSelection(0);

    if(!half) { // start a new measurement
      ctx->clearMarks();
      ctx->addMark(xyz);
      for(int k = 0; k < 3; k++) first[k] = xyz[k];
      half = true;
      on->pinTooltip("");
    }
    else {
      ctx->addMark(xyz);
      ctx->setSegment(first, xyz);
      half = false;
      // the messages keep everything; the length stays on the picture, in a
      // box over the middle of the line
      std::vector<std::string> info = measurePoints(first, xyz);
      for(std::size_t i = 0; i < info.size(); i++)
        if(info[i].size()) Msg::Direct("%s", info[i].c_str());
    }
    drawContext::global()->draw();
  }

  _measureMode = false;
  if(gui.available()) {
    gui.refreshBar();
    _clearNotes();
  }
  _startPending();
}

// --- the quick access menu of the status bar

namespace {

  // the quick access menu acts on every view that is drawn
  void _forEachVisibleView(const std::function<void(int)> &what)
  {
#if defined(HAVE_POST)
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0)) what((int)i);
#endif
  }

  int _firstVisibleView()
  {
#if defined(HAVE_POST)
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0)) return (int)i;
#endif
    return -1;
  }

#if defined(HAVE_POST)
  // the range a raise or a displacement is offered in
  double _viewSpan(int i)
  {
    double most = std::max(fabs(opt_view_min(i, GMSH_GET, 0)),
                           fabs(opt_view_max(i, GMSH_GET, 0)));
    if(!most) most = 1.;
    return 2. * CTX::instance()->lc / most;
  }
#endif

  // named here because the touch bar of macOS reaches for the same entries by
  // name
  struct optionSwitch {
    const char *what, *category, *name;
  };

  const optionSwitch _switches[] = {
    {"hover_meshes", "General", "MouseHoverMeshes"},
    {"geometry_points", "Geometry", "Points"},
    {"geometry_curves", "Geometry", "Curves"},
    {"geometry_surfaces", "Geometry", "Surfaces"},
    {"geometry_volumes", "Geometry", "Volumes"},
    {"mesh_nodes", "Mesh", "Nodes"},
    {"mesh_lines", "Mesh", "Lines"},
    {"mesh_surface_edges", "Mesh", "SurfaceEdges"},
    {"mesh_surface_faces", "Mesh", "SurfaceFaces"},
    {"mesh_volume_edges", "Mesh", "VolumeEdges"},
    {"mesh_volume_faces", "Mesh", "VolumeFaces"},
  };

  const optionSwitch *_switchFor(const std::string &what)
  {
    for(const auto &s : _switches)
      if(what == s.what) return &s;
    return nullptr;
  }

} // namespace

bool quickAccessChecked(const std::string &what)
{
  if(const optionSwitch *s = _switchFor(what)) {
    double v = 0.;
    NumberOption(GMSH_GET, s->category, 0, s->name, v, false);
    return v != 0.;
  }
  if(what == "axes") return opt_general_axes(0, GMSH_GET, 0) != 0.;
#if defined(HAVE_POST)
  if(what == "view_element_outlines") {
    bool on = false;
    _forEachVisibleView([&on](int i) {
      if(opt_view_show_element(i, GMSH_GET, 0) != 0.) on = true;
    });
    return on;
  }
#endif
  return false;
}

void quickAccessAction(const std::string &what)
{
  if(const optionSwitch *s = _switchFor(what)) {
    double v = 0.;
    NumberOption(GMSH_GET, s->category, 0, s->name, v, false);
    v = v ? 0. : 1.;
    NumberOption(GMSH_SET | GMSH_GUI, s->category, 0, s->name, v, false);
    drawContext::global()->draw();
    return;
  }
  if(what == "reset_viewport") {
    if(drawContext *ctx = Gui::instance().getCurrentDrawContext()) {
      viewSetOrientation(ctx, "1:1", false);
      viewSetOrientation(ctx, "z", false);
    }
    drawContext::global()->draw();
  }
  else if(what == "query")
    queryModel();
  else if(what == "measure")
    measureModel();
  else if(what == "select_center") {
    opt_general_rotation_center_cg(0, GMSH_SET | GMSH_GUI, 0);
    optionsAction("rotation_center_select");
  }
  else if(what == "split_hor")
    Gui::instance().windowAction("split_h");
  else if(what == "split_ver")
    Gui::instance().windowAction("split_v");
  else if(what == "unsplit")
    Gui::instance().windowAction("split_u");
  else if(what == "axes") {
    int old = (int)opt_general_axes(0, GMSH_GET, 0);
    opt_general_axes(0, GMSH_SET | GMSH_GUI, old ? 0 : 3);
    if(!old) {
      opt_general_axes_auto_position(0, GMSH_SET | GMSH_GUI, 0);
      optionsAction("axes_fit");
    }
  }
  else if(what == "orthographic")
    opt_general_orthographic(0, GMSH_SET | GMSH_GUI, 1);
  else if(what == "perspective") {
    opt_general_orthographic(0, GMSH_SET | GMSH_GUI, 0);
    drawContext::global()->draw();
    Gui::instance().optionValue.show("General", 0, "ClipFactor", "Factor", 0.1, 20.,
                            0.1);
  }
  else if(what == "mesh_size")
    Gui::instance().optionValue.show("Mesh", 0, "MeshSizeFactor", "Factor", 0.01, 100.,
                            0.01);
  else if(what == "geometry_opacity")
    Gui::instance().optionValue.show("Geometry", 0, "Opacity", "Opacity", 0.,
                                     1., 0.01);
  else if(what == "mesh_opacity")
    Gui::instance().optionValue.show("Mesh", 0, "Opacity", "Opacity", 0., 1.,
                                     0.01);
  else if(what == "view_opacity") {
    int first = _firstVisibleView();
    if(first >= 0)
      Gui::instance().optionValue.show("View", first, "Opacity", "Opacity", 0.,
                                       1., 0.01, "view");
  }
  else if(what == "mesh_toggle") {
    // the six options are all off in between: what they were is remembered here
    static int off = 0;
    static int was[6] = {0, 0, 0, 0, 0, 0};
    double (*const opts[6])(int, int, double) = {
      opt_mesh_nodes,         opt_mesh_lines,
      opt_mesh_surface_edges, opt_mesh_surface_faces,
      opt_mesh_volume_edges,  opt_mesh_volume_faces};
    if(off) {
      Msg::StatusBar(false, "Mesh display restored");
      off = 0;
      for(int i = 0; i < 6; i++) opts[i](0, GMSH_SET | GMSH_GUI, was[i]);
    }
    else {
      Msg::StatusBar(false, "Mesh display OFF");
      off = 1;
      for(int i = 0; i < 6; i++) {
        was[i] = (int)opts[i](0, GMSH_GET, 0.);
        opts[i](0, GMSH_SET | GMSH_GUI, 0);
      }
    }
  }
#if defined(HAVE_POST)
  else if(what == "view_element_outlines") {
    int set = 0;
    _forEachVisibleView([&set](int i) {
      if(!set) set = (int)opt_view_show_element(i, GMSH_GET, 0);
    });
    _forEachVisibleView([set](int i) {
      opt_view_show_element(i, GMSH_SET | GMSH_GUI, !set);
    });
  }
  else if(what == "view_normal_raise") {
    int first = _firstVisibleView();
    if(first >= 0) {
      double span = _viewSpan(first);
      Gui::instance().optionValue.show("View", first, "NormalRaise", "Raise", -span,
                              span, span / 200., "view");
    }
  }
  else if(what == "view_displacement") {
    _forEachVisibleView(
      [](int i) { opt_view_vector_type(i, GMSH_SET | GMSH_GUI, 5); });
    drawContext::global()->draw();
    int first = _firstVisibleView();
    if(first >= 0) {
      double span = _viewSpan(first);
      Gui::instance().optionValue.show("View", first, "DisplacementFactor", "Factor", 0.,
                              span, span / 100., "view");
    }
  }
  else if(what == "view_iso" || what == "view_filled") {
    _forEachVisibleView([&what](int i) {
      opt_view_intervals_type(i, GMSH_SET | GMSH_GUI,
                              (what == "view_iso") ? 1 : 3);
    });
    drawContext::global()->draw();
    int first = _firstVisibleView();
    if(first >= 0)
      Gui::instance().optionValue.show("View", first, "NbIso", "Intervals", 1., 100., 1.,
                              "view");
  }
  else if(what == "view_continous" || what == "view_numeric") {
    int type = (what == "view_continous") ? 2 : 4;
    _forEachVisibleView(
      [type](int i) { opt_view_intervals_type(i, GMSH_SET | GMSH_GUI, type); });
  }
  else if(what == "view_line" || what == "view_3d_arrow") {
    int type = (what == "view_line") ? 1 : 4;
    _forEachVisibleView(
      [type](int i) { opt_view_vector_type(i, GMSH_SET | GMSH_GUI, type); });
  }
  else if(what == "view_glyph_barycenter" || what == "view_glyph_node") {
    int where = (what == "view_glyph_barycenter") ? 1 : 2;
    _forEachVisibleView([where](int i) {
      opt_view_glyph_location(i, GMSH_SET | GMSH_GUI, where);
    });
  }
  else if(what == "view_range_default" || what == "view_range_per_step") {
    int type = (what == "view_range_default") ? 1 : 3;
    _forEachVisibleView(
      [type](int i) { opt_view_range_type(i, GMSH_SET | GMSH_GUI, type); });
  }
#endif
  else
    Msg::Debug("No quick access action '%s'", what.c_str());

  drawContext::global()->draw();
}

// --- the menu a view carries in the modules tree

#if defined(HAVE_POST)

namespace {

  // the data is reloaded, not the view: its options stay
  void _viewReload(int index)
  {
    if(index < 0 || index >= (int)PView::list.size()) return;
    PView *p = PView::list[index];
    if(StatFile(p->getData()->getFileName())) {
      Msg::Error("File '%s' does not exist",
                 p->getData()->getFileName().c_str());
      return;
    }
    std::size_t before = PView::list.size();
    MergeFile(p->getData()->getFileName());
    if(PView::list.size() <= before) return; // nothing came of it
    delete p->getData();
    p->setData(PView::list.back()->getData());
    PView::list.back()->setData(nullptr);
    delete PView::list.back();
    // the file may have fewer time steps than it had
    if(p->getOptions()->timeStep > p->getData()->getNumTimeSteps() - 1)
      p->getOptions()->timeStep = 0;
    p->setChanged(true);
    Gui::instance().updateViews(true, true);
  }

  void _viewCombine(bool time, int how)
  {
    PView::combine(time, how, CTX::instance()->post.combineRemoveOrig,
                   CTX::instance()->post.combineCopyOptions);
    Gui::instance().updateViews(true, true);
    drawContext::global()->draw();
  }

} // namespace

void viewAction(const std::string &what, int index)
{
  bool have = (index >= 0 && index < (int)PView::list.size());

  if(what == "options") {
    Gui::instance().options.showForView(index);
    return;
  }
  if(what == "plugins") {
    Gui::instance().plugins.showForView(index);
    return;
  }
  if(what == "export") {
    Gui::instance().exportView(index);
    return;
  }
  if(what == "reload")
    _viewReload(index);
  else if(what == "reload_all") {
    for(std::size_t i = 0; i < PView::list.size(); i++) _viewReload((int)i);
  }
  else if(what == "reload_visible") {
    for(std::size_t i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0)) _viewReload((int)i);
  }
  else if(what == "alias") {
    if(have) new PView(PView::list[index], true /* copy the options */);
    Gui::instance().updateViews(true, true);
  }
  else if(what == "remove") {
    if(have) delete PView::list[index];
    Gui::instance().updateViews(true, true);
  }
  else if(what == "remove_all") {
    while(PView::list.size()) delete PView::list[0];
    Gui::instance().updateViews(true, true);
  }
  else if(what == "remove_visible" || what == "remove_invisible") {
    bool want = (what == "remove_visible");
    for(int i = (int)PView::list.size() - 1; i >= 0; i--)
      if((opt_view_visible(i, GMSH_GET, 0) != 0.) == want)
        delete PView::list[i];
    Gui::instance().updateViews(true, true);
  }
  else if(what == "remove_other") {
    for(int i = (int)PView::list.size() - 1; i >= 0; i--)
      if(i != index) delete PView::list[i];
    Gui::instance().updateViews(true, true);
  }
  else if(what == "remove_empty") {
    for(int i = (int)PView::list.size() - 1; i >= 0; i--)
      if(PView::list[i]->getData()->empty()) delete PView::list[i];
    Gui::instance().updateViews(true, true);
  }
  else if(what == "remove_same_name") {
    if(!have) return;
    std::string name = PView::list[index]->getData()->getName();
    for(int i = (int)PView::list.size() - 1; i >= 0; i--)
      if(PView::list[i]->getData()->getName() == name) delete PView::list[i];
    Gui::instance().updateViews(true, true);
  }
  else if(what == "sort_by_name") {
    PView::sortByName();
    Gui::instance().updateViews(true, true);
  }
  else if(what == "all_on" || what == "all_off" || what == "invert" ||
          what == "same_name_on") {
    std::string name;
    if(what == "same_name_on" && have)
      name = PView::list[index]->getData()->getName();
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      double on = (what == "all_on")  ? 1. :
                  (what == "all_off") ? 0. :
                  (what == "invert")  ? !opt_view_visible(i, GMSH_GET, 0) :
                  (name == PView::list[i]->getData()->getName()) ? 1. :
                                                                   0.;
      opt_view_visible(i, GMSH_SET | GMSH_GUI, on);
    }
  }
  else if(what == "combine_elements_all")
    _viewCombine(false, 1);
  else if(what == "combine_elements_visible")
    _viewCombine(false, 0);
  else if(what == "combine_elements_same_name")
    _viewCombine(false, 2);
  else if(what == "combine_steps_all")
    _viewCombine(true, 1);
  else if(what == "combine_steps_visible")
    _viewCombine(true, 0);
  else if(what == "combine_steps_same_name")
    _viewCombine(true, 2);
  else if(what == "background_mesh") {
#if defined(HAVE_MESH)
    if(have) GModel::current()->getFields()->setBackgroundMesh(index);
#else
    Msg::Error("Background mesh requires the mesh module");
#endif
    return;
  }
  else {
    Msg::Debug("No view action '%s'", what.c_str());
    return;
  }
  drawContext::global()->draw();
}

#else

void viewAction(const std::string &what, int index) {}

#endif

// --- the gear menu of the modules tree

namespace {

  // all in CTX::solver; two are counted rather than switched
  int *_solverSwitch(const std::string &what)
  {
    if(what == "save") return &CTX::instance()->solver.autoSaveDatabase;
    if(what == "load") return &CTX::instance()->solver.autoLoadDatabase;
    if(what == "archive") return &CTX::instance()->solver.autoArchiveOutputFiles;
    if(what == "check") return &CTX::instance()->solver.autoCheck;
    if(what == "mesh") return &CTX::instance()->solver.autoMesh;
    if(what == "merge") return &CTX::instance()->solver.autoMergeFile;
    if(what == "show") return &CTX::instance()->solver.autoShowViews;
    if(what == "step") return &CTX::instance()->solver.autoShowLastStep;
    if(what == "invisible")
      return &CTX::instance()->solver.showInvisibleParameters;
    return nullptr;
  }

} // namespace

bool solverOptionSet(const std::string &what)
{
  const int *v = _solverSwitch(what);
  return v && *v;
}

void solverOptionAction(const std::string &what)
{
  if(what == "add") {
#if defined(HAVE_ONELAB)
    for(int i = 0; i < NUM_SOLVERS; i++) {
      if(!opt_solver_name(i, GMSH_GET, "").empty() && i != NUM_SOLVERS - 1)
        continue;
      std::string name;
      if(Gui::instance().inputDialog("Solver name:", name) && name.size())
        solverAdd(name, "", "", i);
      return;
    }
#endif
    return;
  }
  int *v = _solverSwitch(what);
  if(!v) {
    Msg::Debug("No solver option '%s'", what.c_str());
    return;
  }
  bool on = !*v;
  // counts rather than switches: two is on
  *v = on ? ((what == "mesh" || what == "show") ? 2 : 1) : 0;
  // the solver buttons and the tree follow
  if(what == "check") Gui::instance().rebuildTree(false);
  if(what == "invisible") Gui::instance().rebuildTree(true);
}

// --- and the menu a solver carries

#if defined(HAVE_ONELAB)

void solverAction(const std::string &what, int index)
{
  if(solverIsRunning()) {
    Msg::Warning("Cannot change a client while a solver is running");
    return;
  }
  std::string name = opt_solver_name(index, GMSH_GET, "");
  std::string exe = opt_solver_executable(index, GMSH_GET, "");
  std::string host = opt_solver_remote_login(index, GMSH_GET, "");

  if(what == "rename") {
    std::string given = name;
    if(!Gui::instance().inputDialog("Solver name:", given)) return;
    solverAdd(given, exe, host, index);
    Gui::instance().onelabAction("reset");
  }
  else if(what == "executable") {
    std::string title = "Choose location of " + name + " executable";
#if defined(WIN32)
    std::string pattern = "*.exe";
#else
    std::string pattern = "*";
#endif
    std::string given = exe;
    if(!Gui::instance().fileDialog(0, title, pattern, given) || given.empty()) return;
    auto it = onelab::server::instance()->findClient(name);
    if(it != onelab::server::instance()->lastClient()) delete *it;
    solverAdd(name, given, host, index);
    Gui::instance().onelabAction("reset");
  }
  else if(what == "remove") {
    opt_solver_name(index, GMSH_SET, "");
    opt_solver_executable(index, GMSH_SET, "");
    opt_solver_remote_login(index, GMSH_SET, "");
    auto it = onelab::server::instance()->findClient(name);
    if(it != onelab::server::instance()->lastClient()) delete *it;
    solverListCompact();
    Gui::instance().rebuildTree(true);
  }
  else
    Msg::Debug("No solver action '%s'", what.c_str());
}

#else

void solverAction(const std::string &what, int index) {}

#endif

void messagesSave(const std::string &fileName)
{
  std::vector<std::string> lines;
  Gui::instance().messageLines(lines);
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return;
  }
  for(const auto &l : lines) fprintf(fp, "%s\n", l.c_str());
  fclose(fp);
  Msg::StatusBar(true, "Wrote '%s'", fileName.c_str());
}

void optionsRestoreDefaults()
{
  if(!Msg::GetAnswer("Do you really want to reset all the options to their "
                     "default values?",
                     0, "Cancel", "Restore"))
    return;
  UnlinkFile(CTX::instance()->homeDir + CTX::instance()->sessionFileName);
  UnlinkFile(CTX::instance()->homeDir + CTX::instance()->optionsFileName);
  ReInitOptions(0);
  InitOptionsGUI(0);
  Gui::instance().applyColorScheme(false);
  drawContext::global()->draw();
}

// --- solver / ONELAB

static bool _solverRunning = false;
static bool _solverStop = false;

#if defined(HAVE_ONELAB)

// no executable given, or an absolute path to something that is not there
static bool _needToChooseExe(const std::string &exe)
{
  if(exe.empty()) return true;
  if(exe[0] == '/' || exe[0] == '\\' || (exe.size() > 2 && exe[1] == ':')) {
    if(StatFile(exe)) return true;
  }
  return false;
}

void solverChooseExecutable(onelabClientHandle client)
{
  onelab::localNetworkClient *c = (onelab::localNetworkClient *)client;
  if(!c) return;

  std::string exe;

  // try to find one next to the Gmsh binary, which is what most beginners
  // actually have
  std::string gmshPath = SplitFileName(CTX::instance()->exeFileName)[0];
  if(gmshPath.size()) {
    std::string name = c->getName();
    for(std::size_t i = 0; i < name.size(); i++)
      name[i] = tolower((unsigned char)name[i]);
    std::string path1 = gmshPath + name;
    std::string path2 = gmshPath + "data/" + name;
#if defined(WIN32)
    path1 += ".exe";
    path2 += ".exe";
#endif
    if(!StatFile(path1))
      exe = path1;
    else if(!StatFile(path2))
      exe = path2;
    if(exe.size())
      Msg::Info("Automatically found %s executable: %s", c->getName().c_str(),
                exe.c_str());
  }

  if(exe.empty()) {
    std::string pattern = "*";
#if defined(WIN32)
    pattern += ".exe";
#endif
    std::string title = "Choose the location of the " + c->getName() +
                        " executable";
    exe = c->getExecutable();
    if(!Gui::instance().fileDialog(0, title, pattern, exe)) exe.clear();
  }

  if(exe.size()) {
    c->setExecutable(exe);
    opt_solver_executable(c->getIndex(), GMSH_SET, exe);
  }
}

void solverAdd(const std::string &name, const std::string &executable,
               const std::string &remoteLogin, int index)
{
  auto it = onelab::server::instance()->findClient(name);
  if(it != onelab::server::instance()->lastClient()) {
    if(_needToChooseExe(executable)) solverChooseExecutable((*it));
    return; // the solver is already there
  }

  // keep only the new one among the network clients
  std::vector<onelab::client *> networkClients;
  for(auto it2 = onelab::server::instance()->firstClient();
      it2 != onelab::server::instance()->lastClient(); it2++)
    if((*it2)->isNetworkClient()) networkClients.push_back(*it2);
  for(std::size_t i = 0; i < networkClients.size(); i++)
    delete networkClients[i];

  onelab::localNetworkClient *c =
    new gmshLocalNetworkClient(name, executable, remoteLogin);
  c->setIndex(index);
  opt_solver_name(index, GMSH_SET, name);
  if(_needToChooseExe(executable))
    solverChooseExecutable(c);
  else
    opt_solver_executable(index, GMSH_SET, executable);
  opt_solver_remote_login(index, GMSH_SET, remoteLogin);

  solverListCompact();
  Gui::instance().rebuildTree(true);
  onelabRun("initialize");
}

void solverListCompact()
{
  std::vector<std::string> names, exes, hosts;
  for(int i = 0; i < NUM_SOLVERS; i++) {
    if(opt_solver_name(i, GMSH_GET, "").size()) {
      names.push_back(opt_solver_name(i, GMSH_GET, ""));
      exes.push_back(opt_solver_executable(i, GMSH_GET, ""));
      hosts.push_back(opt_solver_remote_login(i, GMSH_GET, ""));
    }
  }
  for(std::size_t i = 0; i < NUM_SOLVERS; i++) {
    if(i < names.size()) {
      auto it = onelab::server::instance()->findClient(names[i]);
      if(it != onelab::server::instance()->lastClient()) (*it)->setIndex(i);
      opt_solver_name(i, GMSH_SET, names[i]);
      opt_solver_executable(i, GMSH_SET, exes[i]);
      opt_solver_remote_login(i, GMSH_SET, hosts[i]);
    }
    else {
      opt_solver_name(i, GMSH_SET, "");
      opt_solver_executable(i, GMSH_SET, "");
      opt_solver_remote_login(i, GMSH_SET, "");
    }
  }
}

void solverStart(int index)
{
  if(index >= 0) {
    solverAdd(opt_solver_name(index, GMSH_GET, ""),
              opt_solver_executable(index, GMSH_GET, ""),
              opt_solver_remote_login(index, GMSH_GET, ""), index);
  }
  else {
    solverListCompact();
    Gui::instance().rebuildTree(true);
  }

  if(CTX::instance()->solver.autoLoadDatabase) {
    std::vector<std::string> split =
      SplitFileName(GModel::current()->getFileName());
    std::string db = split[0] + split[1] + ".db";
    if(!StatFile(db)) {
      onelabUtils::loadDb(db);
      CTX::instance()->launchSolverAtStartup = -1;
    }
  }

  if(!solverIsRunning()) {
    if(CTX::instance()->launchSolverAtStartup >= 0) {
      onelabRun("reset");
      onelabUtils::setFirstComputationFlag(true);
    }
    else if(index >= 0)
      onelabRun("check");
    else
      onelabRun("refresh");
  }

  CTX::instance()->launchSolverAtStartup = -1;
}

void remoteAction(const std::string &what, const std::string &arg)
{
  onelab::localNetworkClient *c;
  auto it = onelab::server::instance()->findClient("GmshRemote");
  if(it == onelab::server::instance()->lastClient()) {
    c = new gmshLocalNetworkClient("GmshRemote", "");
    c->setSocketSwitch("-socket");
  }
  else
    c = (onelab::localNetworkClient *)(*it);
  GmshServer *server = c->getGmshServer();

  if(what == "start") {
    if(server) {
      Msg::Error("Cannot start: remote Gmsh is already running");
      return;
    }
    c->setExecutable(arg);
    if(c->getExecutable().size()) c->run();
    return;
  }

  if(!server) {
    Msg::Error("Cannot %s: remote Gmsh not running", what.c_str());
    return;
  }

  if(what == "stop")
    server->SendString(GmshSocket::GMSH_STOP, "Disconnect!");
  else if(what == "merge") {
    if(arg.size()) server->SendString(GmshSocket::GMSH_MERGE_FILE, arg.c_str());
  }
  else if(what == "clear") {
    server->SendString(GmshSocket::GMSH_PARSE_STRING, "Delete All;");
#if defined(HAVE_POST)
    for(int i = PView::list.size() - 1; i >= 0; i--)
      if(PView::list[i]->getData()->isRemote()) delete PView::list[i];
#endif
    Gui::instance().updateViews(true, true);
    drawContext::global()->draw();
  }
  else if(what == "test")
    server->SendString(GmshSocket::GMSH_SPEED_TEST, "Speed test");
}

#else

void solverChooseExecutable(onelabClientHandle client) {}
void solverAdd(const std::string &name, const std::string &executable,
               const std::string &remoteLogin, int index)
{
}
void solverStart(int index) {}
void solverListCompact() {}
void remoteAction(const std::string &what, const std::string &arg) {}

#endif

bool solverIsRunning() { return _solverRunning; }
bool solverStopRequested() { return _solverStop; }
void solverRequestStop(bool stop) { _solverStop = stop; }

void solverCheckForErrors(const std::string &client)
{
  if(Msg::GetErrorCount() > 0 && !CTX::instance()->expertMode) {
    std::string msg(client +
                    " reported an error: do you really want to continue?\n\n"
                    "(To disable this warning in the future, select `Enable "
                    "expert mode'\nin the option dialog.)");
    if(Msg::GetAnswer(msg.c_str(), 1, "Stop", "Continue") == 0)
      _solverStop = true;
  }
}

#if defined(HAVE_ONELAB)

void onelabRun(const std::string &actionIn)
{
  std::string action = actionIn;

  onelab::string o("ONELAB/Action", action);
  o.setVisible(false);
  o.setNeverChanged(true);
  o.setAttribute("Persistent", "1");
  onelab::server::instance()->set(o);

  if(action == "reload") {
    // for outside code that will want to rebuild the geometry
    return;
  }

  if(action == "refresh") {
    onelabUtils::updateGraphs();
    Gui::instance().rebuildTree(true);
    return;
  }

  if(action == "stop") {
    _solverStop = true;
    Gui::instance().setSolverButtonMode("", "kill");
    for(auto it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++) {
      onelab::string s((*it)->getName() + "/Action", "stop");
      s.setVisible(false);
      s.setNeverChanged(true);
      onelab::server::instance()->set(s);
    }
    return;
  }

  if(action == "kill") {
    _solverStop = true;
    for(auto it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++)
      (*it)->kill();
    return;
  }

  if(action == "save") {
    std::string fileName = "onelab.db";

    // special handling for metamodels: add user defined tag, if any
    std::vector<onelab::string> ps;
    onelab::server::instance()->get(ps, "0Metamodel/9Tag");
    if(ps.size() && ps[0].getValue().size())
      fileName.assign("onelab_" + ps[0].getValue() + ".db");

    // special handling for metamodels: save db in "restore" mode
    double restoreMode = 0.;
    std::vector<onelab::number> pn;
    onelab::server::instance()->get(pn, "0Metamodel/9Use restored solution");
    if(pn.size()) {
      restoreMode = pn[0].getValue();
      pn[0].setValue(2); // special value
      onelab::server::instance()->set(pn[0]);
    }

    std::string db =
      SplitFileName(GModel::current()->getFileName())[0] + fileName;
    if(Gui::instance().fileDialog(1, "Save", "*.db", db)) {
      if(!restoreMode) onelabUtils::archiveSolutionFiles(db);
      onelabUtils::saveDb(db);
    }

    // special handling for metamodels: switch back to normal "run" mode
    onelab::server::instance()->get(pn, "0Metamodel/9Use restored solution");
    if(pn.size()) {
      pn[0].setValue(0);
      onelab::server::instance()->set(pn[0]);
    }
    action = "check";
  }

  if(Gui::instance().solverBusy()) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }

  if(action == "load") {
    std::string db =
      SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(Gui::instance().fileDialog(0, "Load", "*.db", db)) onelabUtils::loadDb(db);
    action = "check";
  }

  if(action == "reset") {
    onelabUtils::resetDb(true);
    action = "check";
  }

  // custom button behavior
  {
    std::vector<onelab::string> ps;
    onelab::server::instance()->get(ps, "ONELAB/Button");
    if(ps.size() && ps[0].getValues().size() == 2) {
      // we have a custom onelab "Run" button, we're done
      return;
    }
  }

  Msg::ResetErrorCounter();

  _solverRunning = true;
  _solverStop = false;
  Gui::instance().setSolverButtonMode("", "stop");

  if(action == "compute") onelabUtils::initializeLoops();

  do { // enter loop

    // run Gmsh client for non-metamodels
    if(onelabUtils::runGmshClient(action, CTX::instance()->solver.autoMesh))
      drawContext::global()->draw();

    if(action == "compute") solverCheckForErrors("Gmsh");
    if(_solverStop) break;

    // iterate over all other clients (there should normally only be one)
    for(auto it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++) {
      onelab::client *c = *it;
      if(c->getName() == "Gmsh" || // local Gmsh client
         c->getName() == "Listen" || // client connecting through "-listen"
         c->getName() == "GmshRemote" || // distant post-processing Gmsh client
         c->getName().find("NoAutoRun") != std::string::npos)
        continue;
      if(action != "initialize") onelabUtils::guessModelName(c);
      onelab::string s(c->getName() + "/Action", action);
      s.setVisible(false);
      s.setNeverChanged(true);
      onelab::server::instance()->set(s);
      c->run();
      if(action == "compute") {
        // after computing with this solver, mark the parameters as unchanged
        // for this solver
        onelab::server::instance()->setChanged(0, c->getName());
        solverCheckForErrors(c->getName());
      }
      if(_solverStop) break;
    }

    if(action != "initialize") {
      onelabUtils::updateGraphs();
      Gui::instance().rebuildTree(action == "compute");
    }

  } while(action == "compute" && !_solverStop && onelabUtils::incrementLoops());

  if(action == "compute" && (CTX::instance()->solver.autoSaveDatabase ||
                             CTX::instance()->solver.autoArchiveOutputFiles)) {
    std::string db;
    std::vector<onelab::string> ps;
    onelab::server::instance()->get(ps, "Gmsh/DatabaseFileName");
    if(ps.size() && ps[0].getValue().size()) { db = ps[0].getValue(); }
    else {
      std::vector<std::string> split =
        SplitFileName(GModel::current()->getFileName());
      db = split[0] + split[1] + ".db";
    }
    if(CTX::instance()->solver.autoArchiveOutputFiles)
      onelabUtils::archiveOutputFiles(db);
    if(CTX::instance()->solver.autoSaveDatabase) onelabUtils::saveDb(db);
  }

  _solverRunning = false;
  _solverStop = false;
  Gui::instance().setSolverButtonMode("check", "compute");

  Msg::StatusBar(true, "Done");

}

#else

void onelabRun(const std::string &action)
{
  Msg::Error("ONELAB support is not available in this build");
}

#endif

#if defined(HAVE_ONELAB)

static std::string _dimName(int dim)
{
  switch(dim) {
  case 0: return "Point";
  case 1: return "Curve";
  case 2: return "Surface";
  case 3: return "Volume";
  }
  return "";
}

// for a number parameter the template only appears in the attributes
static void _replaceTemplate(onelab::number &n, const std::string &in,
                             const std::string &out)
{
  auto attr = n.getAttributes();
  for(auto &a : attr) ReplaceSubStringInPlace(in, out, a.second);
  n.setAttributes(attr);
}

// for a string parameter it appears in the values, the choices and the
// attributes
static void _replaceTemplate(onelab::string &n, const std::string &in,
                             const std::string &out)
{
  auto vals = n.getValues();
  for(auto &v : vals) ReplaceSubStringInPlace(in, out, v);
  n.setValues(vals);
  auto choices = n.getChoices();
  for(auto &c : choices) ReplaceSubStringInPlace(in, out, c);
  n.setChoices(choices);
  auto attr = n.getAttributes();
  for(auto &a : attr) ReplaceSubStringInPlace(in, out, a.second);
  n.setAttributes(attr);
}

template <typename T>
static void _instantiate(T &p, const std::string &pattern,
                         const std::string &in, const std::string &out,
                         std::vector<std::string> &names)
{
  if(p.getName().find(pattern) == std::string::npos) return;
  std::string name = ReplaceSubString(in, out, p.getName());
  std::vector<T> existing;
  onelab::server::instance()->get(existing, name);
  if(existing.empty()) {
    T n = p;
    n.setName(name);
    // replace the template string inside the parameter too, so that the
    // attributes and the values can refer to the entity
    _replaceTemplate(n, in, out);
    onelab::server::instance()->set(n);
  }
  names.push_back(name);
}

void onelabContextInstantiate(int dim, int tag, bool physical, int physicalTag,
                              std::vector<std::string> &names)
{
  std::string in = _dimName(dim) + " Template";
  std::string out = physical ? ("Physical " + _dimName(dim) + " " +
                                std::to_string(physicalTag)) :
                               (_dimName(dim) + " " + std::to_string(tag));
  std::string pattern = "ONELAB Context/" + _dimName(dim) + " Template/";

  std::vector<onelab::number> pn;
  onelab::server::instance()->get(pn);
  for(auto &p : pn) _instantiate(p, pattern, in, out, names);

  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps);
  for(auto &p : ps) _instantiate(p, pattern, in, out, names);
}

bool onelabHasContext()
{
  std::vector<std::string> names;
  onelab::server::instance()->getParameterNames(names, "ONELAB Context");
  return !names.empty();
}

#else

void onelabContextInstantiate(int dim, int tag, bool physical, int physicalTag,
                              std::vector<std::string> &names)
{
}

bool onelabHasContext() { return false; }

#endif

// --- geometry

void geometryReload()
{
#if defined(HAVE_ONELAB)
  if(onelabUtils::haveSolverToRun()) { Gui::instance().onelabAction("check_always"); }
  else
#endif
  {
    Gui::instance().onelabAction("reload");
    OpenProject(GModel::current()->getFileName());
  }
  drawContext::global()->draw();
}

void geometrySetFactory(const std::string &factory)
{
  scriptSetFactory(factory, GModel::current()->getFileName());
  if(Gui::instance().available()) Msg::StatusBar(false, "Setting %s factory",
                                      factory.c_str());
}

void geometryEditInTextEditor()
{
  std::string prog = FixWindowsPath(CTX::instance()->editor);
  // allow white space in file name
  std::string file =
    "\"" + FixWindowsPath(GModel::current()->getFileName()) + "\"";
  SystemCall(ReplaceSubString("%s", file, prog));
}

void geometryRemoveLastCommand()
{
  scriptRemoveLastCommand(GModel::current()->getFileName());
  drawContext::global()->draw();
}

void geometryCoherence()
{
  scriptCoherence(GModel::current()->getFileName());
}

// --- mesh

void meshDimension(int dim)
{
  GModel::current()->mesh(dim);
  drawContext::global()->draw();
  Gui::instance().statistics.refresh();
}

void meshRefine()
{
  GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                                CTX::instance()->mesh.algoSubdivide == 1,
                                CTX::instance()->mesh.algoSubdivide == 2,
                                CTX::instance()->mesh.algoSubdivide == 3);
  drawContext::global()->draw();
  Gui::instance().statistics.refresh();
}

void meshOptimize(const std::string &how)
{
  if(CTX::instance()->lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX::instance()->lock = 1;
  GModel::current()->optimizeMesh(how);
  CTX::instance()->lock = 0;
  drawContext::global()->draw();
  Gui::instance().statistics.refresh();
}

void meshSetOrder(int order)
{
  GModel::current()->setOrderN(order, CTX::instance()->mesh.secondOrderLinear,
                               CTX::instance()->mesh.secondOrderIncomplete,
                               CTX::instance()->mesh.meshOnlyVisible);
  drawContext::global()->draw();
}

void meshRecombine()
{
  GModel::current()->recombineMesh();
  drawContext::global()->draw();
  Gui::instance().statistics.refresh();
}

void meshComputeCrossField()
{
#if defined(HAVE_MESH)
  std::vector<int> tags;
  computeCrossField(GModel::current(), tags);
#endif
  drawContext::global()->draw();
}

void meshUnpartition()
{
  if(GModel::current()->unpartitionMesh()) return;
  opt_mesh_zone_definition(0, GMSH_SET, 0.);
  opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 1.);
  CTX::instance()->meshChanged();
  Gui::instance().resetVisibility();
  drawContext::global()->draw();
}

void meshConvertOldPartitioning()
{
  if(GModel::current()->convertOldPartitioningToNewOne()) return;
  opt_mesh_zone_definition(0, GMSH_SET, 0.);
  opt_mesh_color_carousel(0, GMSH_SET | GMSH_GUI, 1.);
  CTX::instance()->meshChanged();
  drawContext::global()->draw();
}

void meshSave()
{
  std::string name = CTX::instance()->outputFileName;
  if(name.empty()) {
    if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
      name = GetDefaultFileName(FORMAT_MSH);
    else
      name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
  }
  if(CTX::instance()->confirmOverwrite && !StatFile(name)) {
    std::string question =
      "File '" + name + "' already exists.\n\nDo you want to replace it?";
    if(!Msg::GetAnswer(question.c_str(), 0, "Cancel", "Replace")) return;
  }
  CreateOutputFile(name, CTX::instance()->mesh.fileFormat);
}

// --- miscellaneous

// fnmatch() is the POSIX one; _globMatch() stands in where there is none, and
// only knows '*' and '?'
#if !defined(WIN32) || defined(__CYGWIN__)
#define GMSH_HAVE_FNMATCH
#endif

// runs of digits compare as numbers: "out2" before "out10"
static bool _numericLess(const std::string &a, const std::string &b)
{
  std::size_t i = 0, j = 0;
  while(i < a.size() && j < b.size()) {
    if(isdigit((unsigned char)a[i]) && isdigit((unsigned char)b[j])) {
      std::size_t i0 = i, j0 = j;
      while(i < a.size() && isdigit((unsigned char)a[i])) i++;
      while(j < b.size() && isdigit((unsigned char)b[j])) j++;
      std::string na = a.substr(i0, i - i0), nb = b.substr(j0, j - j0);
      std::size_t pa = na.find_first_not_of('0'), pb = nb.find_first_not_of('0');
      na = (pa == std::string::npos) ? "" : na.substr(pa);
      nb = (pb == std::string::npos) ? "" : nb.substr(pb);
      if(na.size() != nb.size()) return na.size() < nb.size();
      if(na != nb) return na < nb;
    }
    else {
      if(a[i] != b[j]) return a[i] < b[j];
      i++;
      j++;
    }
  }
  return a.size() - i < b.size() - j;
}

#if !defined(GMSH_HAVE_FNMATCH)
static bool _globMatch(const char *pattern, const char *name)
{
  while(*pattern) {
    if(*pattern == '*') {
      pattern++;
      if(!*pattern) return true;
      for(const char *n = name; *n; n++)
        if(_globMatch(pattern, n)) return true;
      return _globMatch(pattern, name + strlen(name));
    }
    if(!*name) return false;
    if(*pattern != '?' && *pattern != *name) return false;
    pattern++;
    name++;
  }
  return !*name;
}
#endif

void watchFiles()
{
  if(CTX::instance()->watchFilePattern.empty()) return;

  std::string pattern = FixRelativePath(GModel::current()->getFileName(),
                                        CTX::instance()->watchFilePattern);
  std::string directory = SplitFileName(pattern)[0];
  if(directory.empty()) directory = "./";
  // the pattern is a shell glob on the file name
  std::string glob = SplitFileName(pattern)[1] + SplitFileName(pattern)[2];

  std::vector<std::string> matches;
  std::error_code ec;
  for(const auto &entry : std::filesystem::directory_iterator(directory, ec)) {
    std::string name = entry.path().filename().string();
#if defined(GMSH_HAVE_FNMATCH)
    if(fnmatch(glob.c_str(), name.c_str(), 0) == 0)
#else
    if(_globMatch(glob.c_str(), name.c_str()))
#endif
      matches.push_back(directory + name);
  }
  if(ec) {
    Msg::Debug("Could not list '%s': %s", directory.c_str(),
               ec.message().c_str());
    return;
  }
  std::sort(matches.begin(), matches.end(), _numericLess);

  Msg::Info("%d match%s for pattern '%s'", (int)matches.size(),
            (matches.size() > 1) ? "es" : "", pattern.c_str());

  std::set<std::string> allFiles;
  for(std::size_t i = 0; i < GModel::list.size(); i++)
    allFiles.insert(GetFileNameWithoutPath(GModel::list[i]->getFileName()));
#if defined(HAVE_POST)
  for(std::size_t i = 0; i < PView::list.size(); i++)
    for(int j = 0; j < PView::list[i]->getData()->getNumTimeSteps(); j++)
      allFiles.insert(
        GetFileNameWithoutPath(PView::list[i]->getData()->getFileName(j)));
#endif

  for(std::size_t i = 0; i < matches.size(); i++)
    if(allFiles.find(GetFileNameWithoutPath(matches[i])) == allFiles.end())
      MergeFile(matches[i]);
  drawContext::global()->draw();
}

void openURL(const std::string &url)
{
  if(url.empty()) return;
#if defined(WIN32)
  SystemCall("start \"\" \"" + url + "\"");
#elif defined(__APPLE__)
  SystemCall("open \"" + url + "\"");
#else
  SystemCall("xdg-open \"" + url + "\"");
#endif
}

void helpOnline()
{
  if(std::string(GMSH_EXTRA_VERSION) == "")
    openURL("https://gmsh.info/doc/texinfo/gmsh.html");
  else
    openURL("https://gmsh.info/dev/doc/texinfo/gmsh.html");
}

#endif
