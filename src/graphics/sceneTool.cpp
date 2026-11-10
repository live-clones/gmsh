// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "sceneTool.h"
#include "sceneView.h"
#include "selectionDriver.h"
#include "drawContext.h"
#include "GModel.h"
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

void sceneTool::start(sceneTool *tool, sceneView *s, const void *owner)
{
  stop();
  if(!tool) return;
  if(!s) {
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
    if(more)
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
