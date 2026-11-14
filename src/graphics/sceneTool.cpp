// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "sceneTool.h"
#include "sceneView.h"
#include "selectionDriver.h"
#include "drawContext.h"
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "GuiListener.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"

sceneTool *sceneTool::_current = nullptr;
sceneView *sceneTool::_scene = nullptr;
const void *sceneTool::_owner = nullptr;
int sceneTool::_depth = 0;
std::vector<sceneTool *> sceneTool::_ended;
std::function<void()> sceneTool::changed;

// the selection of the tool on its scene, and what it says to do
static void beginTool(sceneTool *t, sceneView *s)
{
  s->beginSelection(t->type(), t->pickElements());
  Msg::StatusGl("%s", t->status(s).c_str());
}

// is s still a scene? (ending a tool, or one of its steps, may process events
// that delete it, e.g. by unsplitting the window)
static bool alive(sceneView *s)
{
  const std::vector<sceneView *> &all = sceneView::all();
  return std::find(all.begin(), all.end(), s) != all.end();
}

void sceneTool::start(sceneTool *tool, sceneView *s, const void *owner)
{
  stop();
  if(!tool) return;
  if(!s || !alive(s)) {
    delete tool;
    return;
  }
  _current = tool;
  _scene = s;
  _owner = owner;
  // a pick needs the mouse selection (the "S" button)
  if(!CTX::instance()->mouseSelection)
    opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
  beginTool(tool, s);
  if(changed) changed();
}

void sceneTool::stop()
{
  sceneTool *t = _current;
  if(!t) return;
  _current = nullptr;
  _owner = nullptr;
  sceneView *s = _scene;
  _scene = nullptr;
  if(s) s->cancelSelection();
  Msg::StatusGl("");
  t->finish();
  // (not while one of its steps is under way)
  if(_depth)
    _ended.push_back(t);
  else
    delete t;
  if(changed) changed();
}

bool sceneTool::step()
{
  // (a step that processes events can come back here: the answers wait for
  // the next event after it)
  if(!_current || !_scene || _depth) return false;
  scenePicks p;
  char ib = _scene->selectionStep(p.vertices, p.edges, p.faces, p.regions,
                                  p.elements, p.points, p.views);
  if(!ib) return false;
  sceneTool *t = _current;
  sceneView *s = _scene;
  _depth++;
  bool more = t->step(ib, s, p);
  _depth--;
  // (unless the step ended it, or started another tool)
  if(_current == t) {
    if(more && alive(s))
      beginTool(t, s);
    else
      stop();
  }
  if(!_depth) {
    for(sceneTool *e : _ended) delete e;
    _ended.clear();
  }
  // what was picked is drawn in every scene
  for(sceneView *v : sceneView::all()) v->askRedraw();
  return true;
}

void sceneTool::restart()
{
  if(_current && _scene) beginTool(_current, _scene);
}

void sceneTool::forget(sceneView *s)
{
  if(_scene != s) return;
  // (the scene is going: it is not told)
  _scene = nullptr;
  stop();
}

// what the query and the measurement leave on the picture is taken away
static void clearClicks()
{
  GModel::current()->setSelection(0);
  for(sceneView *v : sceneView::all()) {
    v->getDrawContext()->clearMarks();
    v->pinTooltip("");
    v->askRedraw();
  }
}

sceneTool *newQueryTool()
{
  return new functionTool(
    "Query", ENT_ALL, true,
    [](sceneView *) {
      return std::string("Click to query the model, Ctrl+click to add a "
                         "query\n[Press Escape to abort]");
    },
    [](char ib, sceneView *s, const scenePicks &p) {
      if(ib == 'q') return false;
      scenePicks q = p;
      if(ib == 'l')
        s->queryClick(q.vertices, q.edges, q.faces, q.regions, q.elements,
                      q.views);
      return true;
    },
    clearClicks);
}

sceneTool *newMeasureTool()
{
  return new functionTool(
    "Measure", ENT_ALL, false,
    [](sceneView *s) {
      return std::string(s->measuring() ? "Click the second point" :
                                          "Click the first point") +
             "\n[Press Escape to abort]";
    },
    [](char ib, sceneView *s, const scenePicks &) {
      if(ib == 'q') return false;
      if(ib == 'l') s->measureClick();
      return true;
    },
    clearClicks);
}

bool pickedModelPoint(const drawContext *ctx, const scenePicks &p,
                      double xyz[3])
{
  if(p.vertices.size()) {
    xyz[0] = p.vertices[0]->x();
    xyz[1] = p.vertices[0]->y();
    xyz[2] = p.vertices[0]->z();
    return true;
  }
  if(!ctx->pickPoint(xyz)) return false;
  SPoint3 pc(xyz[0], xyz[1], xyz[2]);
  GPoint gp;
  if(p.edges.size()) {
    double t;
    gp = p.edges[0]->closestPoint(pc, t);
  }
  else if(p.faces.size()) {
    double uv[2] = {0., 0.};
    gp = p.faces[0]->closestPoint(pc, uv);
  }
  if(gp.succeeded()) {
    xyz[0] = gp.x();
    xyz[1] = gp.y();
    xyz[2] = gp.z();
  }
  return true;
}

sceneTool *newRotationCenterTool()
{
  // (no mesh elements picked for it, which rebuilt the arrays of the mesh
  // twice, a freeze of seconds on a large mesh, to give the barycentre of an
  // element: the point clicked comes from the depth of the pick)
  return new functionTool(
    "Rotation center", ENT_ALL, false,
    [](sceneView *) {
      return std::string("Select point on geometry, mesh or "
                         "post-processing view\n[Press Escape to abort]");
    },
    [](char ib, sceneView *s, const scenePicks &p) {
      // ('e' ends it as 'q' does, nothing set)
      if(ib != 'l') return ib != 'q' && ib != 'e';
      SPoint3 pc(0., 0., 0.);
      double xyz[3];
      if(pickedModelPoint(s->getDrawContext(), p, xyz))
        pc.setPosition(xyz[0], xyz[1], xyz[2]);
      else if(p.elements.size())
        pc = p.elements[0]->barycenter();
      else if(p.edges.size())
        pc = p.edges[0]->bounds().center();
      else if(p.faces.size())
        pc = p.faces[0]->bounds().center();
      else if(p.regions.size())
        pc = p.regions[0]->bounds().center();
      else if(p.views.size() && p.views[0]->getData())
        pc = p.views[0]->getData()->getBoundingBox().center();
      opt_general_rotation_center_cg(0, GMSH_SET | GMSH_GUI, 0);
      opt_general_rotation_center0(0, GMSH_SET | GMSH_GUI, pc.x());
      opt_general_rotation_center1(0, GMSH_SET | GMSH_GUI, pc.y());
      opt_general_rotation_center2(0, GMSH_SET | GMSH_GUI, pc.z());
      s->getDrawContext()->recenterForRotationCenterChange(pc);
      Gui()->sceneTransformChanged();
      return false;
    },
    []() {
      GModel::current()->setSelection(0);
      for(sceneView *v : sceneView::all()) v->askRedraw();
    });
}

operationTool::operationTool(
  const std::string &operation, valueFunction value,
  std::function<bool(const selectionDriver &)> changed,
  std::function<void()> finished)
  : _driver(new selectionDriver(operation, value)), _changed(changed),
    _finished(finished)
{
}

operationTool::~operationTool() { delete _driver; }

bool operationTool::active() const { return _driver->active(); }

std::string operationTool::name() const { return _driver->operation(); }

int operationTool::type() const { return _driver->type(); }

bool operationTool::pickElements() const { return _driver->pickElements(); }

std::string operationTool::status(sceneView *s) const
{ return _driver->status(); }

bool operationTool::step(char ib, sceneView *s, const scenePicks &p)
{
  if(_driver->step(ib, p.vertices, p.edges, p.faces, p.regions, p.elements) &&
     _changed && !_changed(*_driver))
    return false;
  return _driver->active();
}

void operationTool::finish()
{
  _driver->quit();
  if(_finished) _finished();
}
