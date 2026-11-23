// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_TOOL_H
#define SCENE_TOOL_H

#include <functional>
#include <string>
#include <vector>
#include "GmshDefines.h"
#include "scenePicks.h"

class sceneView;
class drawContext;

// The scene and the clicks, in three layers, shared by the desktop (src/fltk)
// and the web page (contrib/webapp):
// - sceneView (sceneView.h): what the mouse does to the scene, the same in
//   both front-ends: rotation, zoom, pan, the lasso, the hover, and the
//   picking of entities when a selection is under way. The front-end derives
//   it (openglWindow on the desktop, webView in webApp.cpp) and gives it the
//   mouse events.
// - sceneTool (here): what the clicks are for now, when something takes them
//   over: the query, the measurement, an operation, a point being placed. One
//   tool at a time, started with sceneTool::start(), stepped by the front-end
//   after the events (it never waits in a loop).
// - selectionDriver (selectionDriver.h): the operations of the modules, each a
//   tool: what each picks, phase by phase, and what it writes in the script
//   once all is picked.
//
// How to add...
// - An operation of the Geometry or Mesh module: in selectionDriver (see
//   Actions.h for its menu item).
// - A tool of a front-end (the clicks of a dialog, say): a functionTool, made
//   of a status and a step function, started on the scene of the window:
//     sceneTool::start(new functionTool("Pick a curve", ENT_CURVE, false,
//                        [](sceneView *) { return "Select a curve"; },
//                        [](char ib, sceneView *, const scenePicks &p) {
//                          ...; return ib != 'q'; }),
//                      scene);
//   (see add_new_point_based_entity() in fltkActions.cpp).
// - What the mouse does to the scene itself: in sceneView, for both
//   front-ends at once.

// A tool takes over the clicks and the keys of a scene: the query, the
// measurement, an operation on selected entities, the placing of a point, the
// picks of a tool window... One runs at a time. The front-end starts it on a
// scene, then calls step() after the events of the scenes (a click, a key):
// the answer of the selection of the scene (sceneView::selectionStep()) goes
// to the tool, which says what to pick next or that it is over. Nothing waits
// for the clicks in a loop: the desktop and the web page step it alike.
class sceneTool {
public:
  virtual ~sceneTool() {}
  // its name, for what shows it (the buttons of the status bar)
  virtual std::string name() const = 0;
  // what a click picks (ENT_ALL, ENT_POINT..., ENT_NONE for the click
  // itself), and whether a click on a mesh picks its element
  virtual int type() const { return ENT_ALL; }
  virtual bool pickElements() const { return false; }
  // the two lines shown at the top of the scene
  virtual std::string status(sceneView *s) const { return ""; }
  // an answer of the selection of the scene s ('l', 'r', 'c', 'e', 'u' or
  // 'q') with what it picked: false once the tool is over
  virtual bool step(char ib, sceneView *s, const scenePicks &p) = 0;
  // the tool is over, however it ended: its step, stop(), another tool
  virtual void finish() {}
  // the tool starts, the one before it over (see start())
  virtual void begin() {}
  // what the pointer is over: shown by the tool itself (the placement of a
  // shape, see hover()), instead of the hover of the scene and the stepping
  // through what is under the cursor
  virtual bool ownsHover() const { return false; }
  virtual void hover(sceneView *s) {}
  // after the hover of the scene (the line of a measurement)
  virtual void hovered(sceneView *s) {}
  // Ctrl+click adds to what the tool does (a query) rather than starting a
  // lasso
  virtual bool ctrlClickAdds() const { return false; }

  // the tool under way (nullptr if none), started on the scene s whose
  // clicks it takes (a new one ends the previous one); stop() ends it. The
  // owner, if any, is what the front-end shows for it (a dialog: Escape
  // there stops it, closing it ends it)
  static void start(sceneTool *tool, sceneView *s, const void *owner = nullptr);
  static void stop();
  static sceneTool *current() { return _current; }
  // the scene it is on, and its owner (nullptr if none)
  static sceneView *scene() { return _scene; }
  static const void *owner() { return _current ? _owner : nullptr; }
  static bool running(const std::string &name)
  { return _current && _current->name() == name; }
  // the tool under way on the scene s shows what the pointer is over itself
  static bool ownsHoverOf(const sceneView *s)
  { return _current && _scene == s && _current->ownsHover(); }
  // after the events of the scenes: the answer of the selection, if there is
  // one, given to the tool; true if there was one
  static bool step();
  // the selection of the tool begun again (what it picks changed)
  static void restart();
  // a scene goes: the tool on it ends
  static void forget(sceneView *s);
  // told when a tool starts or ends (the buttons that show it)
  static std::function<void()> changed;

private:
  static sceneTool *_current;
  static sceneView *_scene;
  static const void *_owner;
  // the steps under way (a step can process events, which can step again or
  // end the tool) and the tools ended meanwhile, deleted after them
  static int _depth;
  static std::vector<sceneTool *> _ended;
};

// a tool made of functions, for the tools of a front-end
class functionTool : public sceneTool {
public:
  typedef std::function<bool(char, sceneView *, const scenePicks &)>
    stepFunction;
  functionTool(const std::string &name, int type, bool elements,
               std::function<std::string(sceneView *)> status,
               stepFunction step, std::function<void()> finish = nullptr)
    : _name(name), _type(type), _elements(elements), _status(status),
      _step(step), _finish(finish)
  {
  }
  std::string name() const { return _name; }
  int type() const { return _type; }
  bool pickElements() const { return _elements; }
  std::string status(sceneView *s) const { return _status ? _status(s) : ""; }
  bool step(char ib, sceneView *s, const scenePicks &p)
  { return _step(ib, s, p); }
  void finish()
  {
    if(_finish) _finish();
  }

private:
  std::string _name;
  int _type;
  bool _elements;
  std::function<std::string(sceneView *)> _status;
  stepFunction _step;
  std::function<void()> _finish;
};

// the query: a click tells what is there (Ctrl+click adds a query)
sceneTool *newQueryTool();
// the measurement: two clicks give a distance
sceneTool *newMeasureTool();
// the centre of rotation: one click on a point of the model sets it
sceneTool *newRotationCenterTool();

// the point of the model the last pick of ctx hit (see
// drawContext::pickPoint()), on the point, curve or surface picked itself
// rather than on the polyline or triangulation it is drawn as; false if the
// pick hit nothing of the 3D scene
bool pickedModelPoint(const drawContext *ctx, const scenePicks &p,
                      double xyz[3]);

#endif
