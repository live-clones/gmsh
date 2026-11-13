// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <cstdio>
#include "sceneView.h"
#include "sceneTool.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "Numeric.h"
#include "OpenFile.h"
#include "OS.h"
#include "StringUtils.h"
#include "Context.h"
#include "glImmediate.h"
#include "glShader.h"

// the scenes there are
static std::vector<sceneView *> &_scenes()
{
  static std::vector<sceneView *> s;
  return s;
}

sceneView::sceneView(drawContext *ctx)
  : _w(1), _h(1), _selection(ENT_NONE), _trySelection(0), _addQuery(false),
    _highlightedDim(-1), _highlightedTag(0), _highlightedWas(0),
    _pickStepTime(0.), _stepping(false), _hoverBehind(false), _spin(0.),
    _spinFrom(0.), _spinPath(0.), _spinHot(0.), _ctx(ctx), _phlogiston(0.),
    _phlogistonTime(0.), addPointMode(0), lassoMode(false), selectionMode(false),
    endSelection(0), undoSelection(0), quitSelection(0), changeSelection(0)
{
  _selectionElements = false;
  _scenes().push_back(this);
  for(int i = 0; i < 3; i++) _point[i] = 0.;
  for(int i = 0; i < 4; i++) _trySelectionXYWH[i] = 0;
  _stepAnchor[0] = _stepAnchor[1] = 0.;
  _hoverAnchor[0] = _hoverAnchor[1] = 0.;
  for(int i = 0; i < 4; i++) _hoverBox[i] = 0.;
}

sceneView::~sceneView()
{
  GEntity *was = _highlightedEntity();
  if(was) was->setSelection(_highlightedWas);
  // (out of the scenes first: the tool on it ends, whose end may go through
  // them, and what a derived class held is gone already)
  auto &s = _scenes();
  s.erase(std::remove(s.begin(), s.end(), this), s.end());
  sceneTool::forget(this);
}

const std::vector<sceneView *> &sceneView::all() { return _scenes(); }

bool sceneView::_select(
  int type, bool multiple, bool mesh, bool post, int x, int y, int w, int h,
  std::vector<GVertex *> &vertices, std::vector<GEdge *> &edges,
  std::vector<GFace *> &faces, std::vector<GRegion *> &regions,
  std::vector<MElement *> &elements, std::vector<SPoint2> &points,
  std::vector<PView *> &views, bool pickElements, bool through)
{
  // no picking passes when mouse selection is off (General.MouseSelection),
  // which is how users avoid their cost
  if(!CTX::instance()->mouseSelection) return false;
  // not while a frame is being drawn (a host checking its events in the
  // middle of one can deliver a click there): the passes would mix
  if(!hostBeginGL()) return false;
  _ctx->pickElements = pickElements;
  bool ret = _ctx->select(type, multiple, mesh, post, x, y, w, h, vertices,
                          edges, faces, regions, elements, points, views,
                          through);
  _ctx->pickElements = false;
  hostEndGL();
  return ret;
}

// One step through the entities under the cursor for one press or one notch,
// which takes some holding down. A wheel event is rate limited because a
// mouse gives one for each notch but a trackpad gives a burst of them for a
// single swipe of two fingers, with more coming while it glides. A key is
// rate limited too, and against being stepped again from inside this call,
// because one press of it can reach the window more than once: macOS sends
// an FL_KEYBOARD for the command an arrow key stands for and another for the
// text it carries (Fl_cocoa.mm, doCommandBySelector: and insertText:).
void sceneView::_stepPick(int direction, bool rateLimited)
{
  if(_stepping) return;
  double now = TimeOfDay();
  // the two deliveries of one press are microseconds apart, so a short guard
  // is enough for them and leaves a held key repeating
  if(now - _pickStepTime < (rateLimited ? 0.2 : 0.03)) return;
  _pickStepTime = now;
  _stepAnchor[0] = _curr.win[0];
  _stepAnchor[1] = _curr.win[1];
  _stepping = true;
  // where the hover last looked: neither a wheel nor a key moves the cursor
  _ctx->stepPick(direction);
  _hover();
  _stepping = false;
}

// the pass of drawContext::pickBehind(), under the same guard as _select()
bool sceneView::_probeBehind()
{
  if(!hostBeginGL()) return false;
  bool behind = _ctx->pickBehind(_selection, CTX::instance()->mouseHoverMeshes,
                                 CTX::instance()->mouseHoverMeshes,
                                 (int)_curr.win[0], (int)_curr.win[1], 5, 5);
  hostEndGL();
  return behind;
}

// The highlighted entity, if it still is: looked up by its tag in the models,
// as it may have been deleted since, and still drawn as highlighted, as
// something else may have changed its selection since (or a new entity may
// have its tag)
GEntity *sceneView::_highlightedEntity() const
{
  if(_highlightedDim < 0) return nullptr;
  for(GModel *m : GModel::list) {
    GEntity *e = m->getEntityByTag(_highlightedDim, _highlightedTag);
    if(e && e->getSelection() == GEntity::SelectHover) return e;
  }
  return nullptr;
}

// The entity the cursor is over, drawn as a selected one until the cursor is
// over something else. The picture changes, so this redraws; what is drawn is
// the same geometry in another colour, so the identifier image a pick is read
// from does not change and is not thrown away.
void sceneView::_highlight(GEntity *e)
{
  if(!CTX::instance()->mouseHoverHighlight) e = nullptr;
  if(!e && _highlightedDim < 0) return;
  GEntity *was = _highlightedEntity();
  if(e && e == was) return;
  // not one already chosen, drawn as such: it would lose its marker and label
  // and no longer read as chosen to what picks it (see getSelection())
  if(e && e->getSelection()) e = nullptr;
  // put back what it was
  if(was) was->setSelection(_highlightedWas);
  _highlightedWas = e ? e->getSelection() : 0;
  _highlightedDim = e ? e->dim() : -1;
  _highlightedTag = e ? e->tag() : 0;
  // selected as far as the drawing is concerned, so that it is drawn again
  // on top of the merged arrays, but in the highlight colour and without the
  // marker and label a chosen entity shows (see getSelectionColor())
  if(e) e->setSelection(GEntity::SelectHover);
  hostRedraw();
}

// the entity in front among those picked: a point before a curve, before a
// surface, before a volume
static GEntity *firstEntity(std::vector<GVertex *> &vertices,
                            std::vector<GEdge *> &edges,
                            std::vector<GFace *> &faces,
                            std::vector<GRegion *> &regions)
{
  if(vertices.size()) return vertices[0];
  if(edges.size()) return edges[0];
  if(faces.size()) return faces[0];
  if(regions.size()) return regions[0];
  return nullptr;
}

// the command a double click on an entity of dimension dim runs
static const std::string &doubleClickCommand(int dim)
{
  CTX *c = CTX::instance();
  const std::string *cmd[4] = {
    &c->geom.doubleClickedPointCommand, &c->geom.doubleClickedCurveCommand,
    &c->geom.doubleClickedSurfaceCommand, &c->geom.doubleClickedVolumeCommand};
  return *cmd[dim];
}

// What the cursor is over: a box by the cursor or the status bar says what a
// click would pick, and the cursor says whether there is anything. When several
// entities are under it, the wheel steps through them (see handleMouse())
// and this says which one is current.
void sceneView::_hover()
{
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;
  std::vector<SPoint2> points;
  std::vector<PView *> views;
  // during a selection the meshes and the views are picked whether or not
  // the hover looks at them otherwise: what is highlighted is what a click
  // would take
  bool all = selectionMode || CTX::instance()->mouseHoverMeshes;
  // (not the mesh element under the cursor, looked for in the octree of the
  // model: a query asks for it on a click, a hover would ask on every move)
  bool res =
    _select(_selection, false, all, all, (int)_curr.win[0], (int)_curr.win[1],
            5, 5, vertices, edges, faces, regions, elements, points, views);
  hostCursor((_selection == ENT_ALL && res) ||
             (_selection == ENT_POINT && vertices.size()) ||
             (_selection == ENT_CURVE && edges.size()) ||
             (_selection == ENT_SURFACE && faces.size()) ||
             (_selection == ENT_VOLUME && regions.size()));
  std::string text, cmd;
  GEntity *over = firstEntity(vertices, edges, faces, regions);
  if(over) {
    text = over->getInfoString(true, true);
    cmd = doubleClickCommand(over->dim());
  }
  else if(elements.size()) {
    text = elements[0]->getInfoString(true);
  }
  else if(points.size()) {
    char tmp[256];
    sprintf(tmp, "Point (%g, %g)", points[0].x(), points[0].y());
    text = tmp;
    cmd = CTX::instance()->post.doubleClickedGraphPointCommand;
  }
  else if(views.size()) {
    // named as a query names it
    char tmp[256];
    sprintf(tmp, "View[%d]", views[0]->getIndex());
    text = tmp;
    if(views[0]->getData() && views[0]->getData()->getName().size())
      text += " \"" + views[0]->getData()->getName() + "\"";
    cmd = views[0]->getOptions()->doubleClickedCommand;
  }
  // what a double-click and the wheel would do, after the information, in
  // as few words as will do: the box is read at a glance
  std::vector<std::string> hints;
  if(cmd.size()) {
    if(cmd == "ONELAB") {
      // add hint if there are ONELAB context parameters
      if(hostHasOnelabContext()) {
        hints.push_back("Double-click to edit parameters");
      }
    }
    else {
      std::replace(cmd.begin(), cmd.end(), '\r', ' ');
      hints.push_back("Double-click to execute: " + cmd);
    }
  }
  // and drawn as selected, so that it is not only named but shown
  _highlight(over);

  // while a measurement waits for its second point, the line follows the
  // cursor over the model, so that its length is seen as it is chosen
  if(sceneTool::running("Measure") && _ctx->numMarks() == 1) {
    double a[3], p[3];
    if(_ctx->mark(0, a) && _ctx->pickPoint(p))
      _ctx->setSegment(a, p);
    else
      _ctx->clearSegment();
    hostRedraw();
  }

  // how far under the cursor this one is and whether there is more, whenever
  // there is something to step to. The image of the pick shows only what is
  // in front, so when nothing else is seen around the cursor the pass is run
  // once more without this entity, once per entity as it costs a redraw.
  if(text.size()) {
    char tmp[256];
    int d = _ctx->pickDepth(), more = _ctx->pickCandidates() - 1;
    bool behind = more > 0;
    if(!behind) {
      if(text != _hoverBehindFor) {
        _hoverBehindFor = text;
        _hoverBehind = _probeBehind();
      }
      behind = _hoverBehind;
    }
    // what was stepped past is in front, what a step would reach is behind
    const char *keys = "(Alt+wheel or Alt+Up/Down)";
    if(d && more > 0)
      sprintf(tmp, "%d in front, %d more behind %s", d, more, keys);
    else if(d && behind)
      sprintf(tmp, "%d in front, more behind %s", d, keys);
    else if(d)
      sprintf(tmp, "%d in front, nothing behind %s", d, keys);
    else if(more > 0)
      sprintf(tmp, "%d more behind %s", more, keys);
    else if(behind)
      sprintf(tmp, "More behind %s", keys);
    else
      tmp[0] = '\0';
    if(tmp[0]) hints.push_back(tmp);
  }
  for(std::size_t i = 0; i < hints.size(); i++)
    text += (i ? "\n" : "\n\n") + hints[i];
  if(CTX::instance()->tooltips)
    drawTooltip(text);
  else {
    // in the status bar, its first line only (what is under the cursor), with
    // the next one when it ends with a colon (an element, then its type)
    std::string::size_type n = text.find('\n');
    if(n != std::string::npos && n && text[n - 1] == ':')
      n = text.find('\n', n + 1);
    Msg::StatusBar(false,
                   ReplaceSubString("\n", "", text.substr(0, n)).c_str());
  }
  if(Msg::GetVerbosity() == 99)
    Msg::Debug(ReplaceSubString("\n", " ", text).c_str());
}

void sceneView::pointerLeft()
{
  // nothing under the cursor once it is out of the window
  _highlight(nullptr);
  drawTooltip("");
}

bool sceneView::acceptsDoubleClick() const
{
  // not during a selection, and only when the clicks pick
  return !selectionMode && CTX::instance()->mouseSelection;
}


// the command of a double click, which may change the model: not during
// another operation on it
static void runCommand(const std::string &command)
{
  modelLock lock(modelLock::ifFree);
  if(lock) ParseString(command, true);
}

// what was double clicked runs its command (General.DoubleClicked*Command),
// shows its ONELAB parameters, or, when there is nothing, the quick access
// menu; an entity without a command lets a double click reach the entity
// behind it of higher dimension
void sceneView::_doubleClick(const paneInput &in)
{
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;
  std::vector<SPoint2> points;
  std::vector<PView *> views;
  _select(ENT_ALL, false, CTX::instance()->mouseHoverMeshes, true, (int)in.x,
          (int)in.y, 5, 5, vertices, edges, faces, regions, elements, points,
          views);
  GEntity *picked[4] = {vertices.size() ? vertices[0] : nullptr,
                        edges.size() ? edges[0] : nullptr,
                        faces.size() ? faces[0] : nullptr,
                        regions.size() ? regions[0] : nullptr};
  for(int dim = 0; dim < 4; dim++) {
    const std::string &cmd = doubleClickCommand(dim);
    if(!picked[dim] || cmd.empty() ||
       (cmd == "ONELAB" && !hostHasOnelabContext()))
      continue;
    CTX::instance()->geom.doubleClickedEntityTag = picked[dim]->tag();
    if(cmd == "ONELAB")
      hostShowOnelabContext(dim, picked[dim]->tag());
    else
      runCommand(cmd);
    return;
  }
  if(views.size() && views[0]->getOptions()->doubleClickedCommand.size()) {
    CTX::instance()->post.doubleClickedView = views[0]->getIndex();
    runCommand(views[0]->getOptions()->doubleClickedCommand);
  }
  else if(points.size() &&
          CTX::instance()->post.doubleClickedGraphPointCommand.size()) {
    CTX::instance()->post.doubleClickedGraphPointX = points[0].x();
    CTX::instance()->post.doubleClickedGraphPointY = points[0].y();
    runCommand(CTX::instance()->post.doubleClickedGraphPointCommand);
  }
  else { // popup quick access menu
    hostQuickAccess();
  }
}

// zoom on the lasso rectangle, from _click to _curr
void sceneView::_lassoZoom()
{
  if(CTX::instance()->camera) {
    Camera *cam = &(_ctx->camera);
    double dy = fabs(-_click.win[1] + _curr.win[1]);
    double dx = fabs(-_click.win[0] + _curr.win[0]);
    if(dx == 0. || dy == 0.) return;
    double factx = _w / fabs(dx);
    double facty = _h / fabs(dy);
    double fact = .8 * std::min(factx, facty);
    double x_med = (_click.win[0] + _curr.win[0]) / 2.;
    double y_med = (_click.win[1] + _curr.win[1]) / 2.;
    double theta_x = .96 * cam->radians * (_w / 2 - x_med) * 2. / _h;
    double theta_y = .96 * cam->radians * (_h / 2 - y_med) * 2. / _h;
    cam->moveRight(theta_x);
    cam->moveUp(theta_y);
    _ctx->camera.zoom(fact);
    _ctx->camera.update();
    hostRedraw();
    return;
  }

  if(_click.win[0] == _curr.win[0] || _click.win[1] == _curr.win[1]) return;

  _ctx->s[0] *= (double)_ctx->viewport[2] / (_curr.win[0] - _click.win[0]);
  _ctx->s[1] *= (double)_ctx->viewport[3] / (_curr.win[1] - _click.win[1]);
  _ctx->s[2] = std::min(_ctx->s[0], _ctx->s[1]); // bof...

  // recenter around the center of the lasso rectangle
  mousePosition tmp(_click);
  tmp.wnr[0] = 0.5 * (_click.wnr[0] + _curr.wnr[0]);
  tmp.wnr[1] = 0.5 * (_click.wnr[1] + _curr.wnr[1]);
  tmp.recenter(_ctx);

  _ctx->initPosition(false);
  hostRedraw();
  hostViewChanged();
}

// a click that selects (sign 1) or unselects (sign -1): it ends a lasso, and
// then tries the entities in the lasso (or zooms on it when not selecting),
// or tries the entity under the cursor; alt keeps what is in front only
void sceneView::_clickSelection(int sign, bool alt)
{
  if(lassoMode) {
    lassoMode = false;
    if(selectionMode && CTX::instance()->mouseSelection) {
      _trySelection = 2 * sign;
      _trySelectionFront = alt;
      _trySelectionXYWH[0] = (int)(_click.win[0] + _curr.win[0]) / 2;
      _trySelectionXYWH[1] = (int)(_click.win[1] + _curr.win[1]) / 2;
      _trySelectionXYWH[2] = (int)fabs(_click.win[0] - _curr.win[0]);
      _trySelectionXYWH[3] = (int)fabs(_click.win[1] - _curr.win[1]);
    }
    else {
      _lassoZoom();
    }
  }
  else if(CTX::instance()->mouseSelection) {
    _trySelection = sign;
    _trySelectionXYWH[0] = (int)_curr.win[0];
    _trySelectionXYWH[1] = (int)_curr.win[1];
    _trySelectionXYWH[2] = 5;
    _trySelectionXYWH[3] = 5;
  }
}

void sceneView::handleMouse(const paneInput &in)
{
  _w = in.w;
  _h = in.h;
  int x = (int)in.x, y = (int)in.y;
  bool shift = in.shift, ctrl = in.ctrl, alt = in.alt, meta = in.meta;

  switch(in.kind) {
  case paneInput::Push:
    // what the click does with the pick is not this highlight's business
    _highlight(nullptr);
    drawTooltip("");
    if(in.doubleClick && acceptsDoubleClick()) {
      _doubleClick(in);
      return;
    }
    if(!hostClicked()) return;
    _curr.set(_ctx, x, y);
    // (Alt+click ends a lasso with what is in front only: the click that
    // ends a lasso can have it)
    if(in.button == 0 && !shift && (!alt || lassoMode)) {
      // Ctrl+click adds a query in query mode (when the clicks select), and
      // starts a lasso otherwise
      _addQuery =
        sceneTool::running("Query") && CTX::instance()->mouseSelection && ctrl;
      if(!lassoMode && ctrl && !_addQuery)
        lassoMode = true;
      else
        _clickSelection(1, alt);
    }
    else if(in.button == 2 || (in.button == 0 && shift)) {
      if(!lassoMode && ctrl) {
        // make zoom isotropic
        _ctx->s[1] = _ctx->s[0];
        _ctx->s[2] = _ctx->s[0];
        hostRedraw();
      }
      else
        _clickSelection(-1, alt);
    }
    else {
      if(ctrl && !lassoMode) {
        if(CTX::instance()->useTrackball)
          _ctx->setQuaternion(0., 0., 0., 1.);
        else
          _ctx->r[0] = _ctx->r[1] = _ctx->r[2] = 0.;
        _ctx->t[0] = _ctx->t[1] = _ctx->t[2] = 0.;
        _ctx->s[0] = _ctx->s[1] = _ctx->s[2] = 1.;
        hostRedraw();
      }
      else {
        lassoMode = false;
      }
    }
    _click.set(_ctx, x, y);
    _prev.set(_ctx, x, y);
    // a drag is measured from where it starts, not from the last one
    _spin = _spinPath = _spinHot = 0.;
    _spinFrom = TimeOfDay();
    hostViewChanged();
    return;

  case paneInput::Release:
    _curr.set(_ctx, x, y);
    CTX::instance()->drawRotationCenter = 0;
    if(!lassoMode) {
      CTX::instance()->mesh.draw = 1;
      CTX::instance()->post.draw = 1;
      hostRedraw();
    }
    _prev.set(_ctx, x, y);
    return;

  case paneInput::Wheel: {
    double dy = in.wheel;
    // which way the wheel is being turned, as the zoom reads it: the sign
    // depends on the mouse, on the trackpad and on how the system is set up,
    // so the one gesture that brings the model closer is the one that steps
    // to the entity in front
    bool direction = (CTX::instance()->mouseInvertZoom) ? (dy <= 0) : (dy > 0);
    // With Alt, the wheel steps through the entities under the cursor
    // instead of zooming: a click then picks the one the hover names,
    // rather than the drawing order deciding which of them wins.
    if(alt && CTX::instance()->mouseSelection && !lassoMode && !addPointMode) {
      // _prev is left alone: it is what a move is measured against, and
      // nothing has moved
      _stepPick(direction ? -1 : 1, true);
      return;
    }
    _prev.set(_ctx, x, y);
    double fact = (5. * CTX::instance()->zoomFactor * fabs(dy) + _h) / (double)_h;
    if(CTX::instance()->camera) {
      fact = (direction ? fact : 1. / fact);
      _ctx->camera.zoom(fact);
      _ctx->camera.update();
      hostRedraw();
    }
    else {
      _ctx->s[0] *= (direction ? fact : 1. / fact);
      _ctx->s[1] = _ctx->s[0];
      _ctx->s[2] = _ctx->s[0];
      _prev.recenter(_ctx);
      hostRedraw();
    }
    hostViewChanged();
    return;
  }

  case paneInput::Drag: {
    _curr.set(_ctx, x, y);
    double dx = _curr.win[0] - _prev.win[0];
    double dy = _curr.win[1] - _prev.win[1];
    if(lassoMode) { hostRedraw(); }
    else {
      if(meta) {
        // will try to select or unselect entities on the fly
        _trySelection = shift ? -1 : 1;
        _trySelectionXYWH[0] = (int)_curr.win[0];
        _trySelectionXYWH[1] = (int)_curr.win[1];
        _trySelectionXYWH[2] = 5;
        _trySelectionXYWH[3] = 5;
      }
      // (m1) and (!shift) and (!alt)  => rotation
      else if(in.button == 0 && !shift && !alt) {
        // How fast the model is spun, in window sizes per second: kept up
        // past a point for a quarter of a second, it gives off its
        // phlogiston, the faster the sooner, and more of it as long as the
        // spinning lasts, up to half as much again as a full release. The
        // speed is the path drawn over a few hundredths of a second, not
        // one event's step over the time since the previous one: events
        // can arrive in clumps microseconds apart, as they do on X11,
        // which made a slight movement look like a frantic one. A step
        // counts for half a window at most, so a pointer that jumps
        // (a stale position, a warp) does not count either.
        double now = TimeOfDay(), dt = now - _spinFrom;
        _spinPath += std::min(0.5, sqrt(dx * dx / (_w * (double)_w) +
                                        dy * dy / (_h * (double)_h)));
        if(dt > 0.25) { // the drag stopped for a while
          _spin = _spinPath = _spinHot = 0.;
          _spinFrom = now;
        }
        else if(dt >= 0.03) {
          _spin = 0.7 * _spin + 0.3 * std::min(40., _spinPath / dt);
          const double catches = 8.;
          _spinHot = (_spin > catches) ? _spinHot + dt : 0.;
          if(_spinHot > 0.25 && CTX::instance()->phlogiston) {
            if(_phlogiston <= 0.) _phlogistonTime = now;
            _phlogiston = std::min(1.5, _phlogiston + 1.5 * (_spin / catches - 1.) * dt);
          }
          _spinPath = 0.;
          _spinFrom = now;
        }
        if(CTX::instance()->useTrackball)
          _ctx->addQuaternion(
            (2. * _prev.win[0] - _w) / _w, (_h - 2. * _prev.win[1]) / _h,
            (2. * _curr.win[0] - _w) / _w, (_h - 2. * _curr.win[1]) / _h);
        else {
          _ctx->r[1] += ((fabs(dx) > fabs(dy)) ? 180. * dx / (double)_w : 0.);
          _ctx->r[0] += ((fabs(dx) > fabs(dy)) ? 0. : 180. * dy / (double)_h);
        }
      }
      // m2 or (m1 and shift) => zoom (only move in y is used)
      // but start point is the center of the homothety
      else if(in.button == 2 || (in.button == 0 && shift)) {
        // isotrop zoom in camera mode
        if(CTX::instance()->camera) {
          double dy = (int)_curr.win[1] - (int)_prev.win[1];
          double fact =
            (CTX::instance()->zoomFactor * fabs(dy) + (double)_h) / (double)_h;
          fact = ((dy > 0) ? fact : 1. / fact);
          _ctx->camera.zoom(fact);
          _ctx->camera.update();
          hostRedraw();
        }
        else {
          // move in y greater than move in x
          if(fabs(dy) > fabs(dx)) {
            double fact =
              (CTX::instance()->zoomFactor * fabs(dy) + _h) / (double)_h;
            _ctx->s[0] *= ((dy > 0) ? fact : 1. / fact);
            _ctx->s[1] = _ctx->s[0];
            _ctx->s[2] = _ctx->s[0];
            _click.recenter(_ctx);
          }
          else if(!CTX::instance()->useTrackball)
            _ctx->r[2] += -180. * dx / (double)_w;
        }
      }
      // other case => translation
      else {
        if(CTX::instance()->camera) {
          Camera *cam = &(_ctx->camera);
          double theta_x = cam->radians *
                           (-(double)_prev.win[0] + (double)_curr.win[0]) *
                           2. / _h;
          double theta_y = cam->radians *
                           (-(double)_prev.win[1] + (double)_curr.win[1]) *
                           2. / _h;
          cam->moveRight(theta_x);
          cam->moveUp(theta_y);
        }
        else {
          _ctx->t[0] += (_curr.wnr[0] - _click.wnr[0]);
          _ctx->t[1] += (_curr.wnr[1] - _click.wnr[1]);
          _ctx->t[2] = 0.;
        }
      }
      CTX::instance()->drawRotationCenter = 1;
      if(CTX::instance()->fastRedraw) {
        CTX::instance()->mesh.draw = 0;
        CTX::instance()->post.draw = 0;
      }
      hostRedraw();
    }
    _prev.set(_ctx, x, y);
    hostViewChanged();
    return;
  }

  case paneInput::Move:
    _curr.set(_ctx, x, y);
    if(lassoMode) { hostRedraw(); }
    else if(addPointMode && !shift) {
      hostCursor(true);
      // find line in real space corresponding to current cursor position
      double p[3], d[3];
      _ctx->unproject(_curr.win[0], _curr.win[1], p, d);
      // find closest point to the center of gravity
      double r[3] = {CTX::instance()->cg[0] - p[0],
                     CTX::instance()->cg[1] - p[1],
                     CTX::instance()->cg[2] - p[2]},
             t;
      t = prosca(r, d);
      for(int i = 0; i < 3; i++) {
        if(!hostFrozenCoordinate(i)) {
          _point[i] = p[i] + t * d[i];
          if(CTX::instance()->geom.snap[i]) {
            double d = _point[i] / CTX::instance()->geom.snap[i];
            double f = floor(d);
            double c = ceil(d);
            double n = (d - f < c - d) ? f : c;
            _point[i] = n * CTX::instance()->geom.snap[i];
          }
        }
      }
      hostPointMoved(_point, addPointMode);
      hostRedraw();
    }
    else { // hover mode
      if(_curr.win[0] != _prev.win[0] || _curr.win[1] != _prev.win[1]) {
        // Somewhere else under the cursor: back to the entity in front. A
        // pixel or two is not somewhere else, as a trackpad nudges the
        // pointer while it is dragged over for the stepping.
        if(fabs(_curr.win[0] - _stepAnchor[0]) > 3. ||
           fabs(_curr.win[1] - _stepAnchor[1]) > 3.) {
          _ctx->resetPick();
          _stepAnchor[0] = _curr.win[0];
          _stepAnchor[1] = _curr.win[1];
        }
        _hover();
      }
    }
    // what the next move is measured against
    _prev = _curr;
    return;
  }
}

void sceneView::beginSelection(int type, bool elements)
{
  _selection = type;
  _selectionElements = elements;
  _trySelection = 0;
  selectionMode = true;
  quitSelection = 0;
  changeSelection = 0;
  endSelection = 0;
  undoSelection = 0;
}

void sceneView::cancelSelection()
{
  _selection = ENT_NONE;
  _trySelection = 0;
  quitSelection = 0;
  selectionMode = false;
  lassoMode = false;
  addPointMode = 0;
  hostCursor(false);
}

char sceneView::selectionStep(std::vector<GVertex *> &vertices,
                              std::vector<GEdge *> &edges,
                              std::vector<GFace *> &faces,
                              std::vector<GRegion *> &regions,
                              std::vector<MElement *> &elements,
                              std::vector<SPoint2> &points,
                              std::vector<PView *> &views)
{
  if(changeSelection) {
    Msg::Debug("Changing selection mode to %d", changeSelection);
    _selection = changeSelection;
    changeSelection = 0;
  }
  if(quitSelection) {
    cancelSelection();
    return 'q';
  }
  // the selection is over, as in every other return below (beginSelection()
  // starts the next): ended or undone
  std::pair<int *, char> asked[2] = {{&endSelection, 'e'},
                                     {&undoSelection, 'u'}};
  for(auto &a : asked) {
    if(!*a.first) continue;
    _selection = ENT_NONE;
    selectionMode = false;
    *a.first = 0;
    return a.second;
  }
  if(_trySelection) {
    bool add = (_trySelection > 0) ? true : false;
    bool multi = (abs(_trySelection) > 1) ? true : false;
    _trySelection = 0;
    if(_selection == ENT_NONE) { // just report the mouse click
      selectionMode = false;
      return 'c';
    }
    else if(_select(_selection, multi, true, true, _trySelectionXYWH[0],
                    _trySelectionXYWH[1], _trySelectionXYWH[2],
                    _trySelectionXYWH[3], vertices, edges, faces, regions,
                    elements, points, views, _selectionElements,
                    !_trySelectionFront)) {
      _selection = ENT_NONE;
      selectionMode = false;
      return add ? 'l' : 'r';
    }
  }
  return 0;
}

// the lines of a query or a measurement in the messages, which keep them all:
// printed last, as the desktop interface processes events then (Msg::Direct),
// which may delete the window of the scene
static void printLines(const std::vector<std::string> &lines)
{
  for(auto &l : lines)
    if(l.size()) Msg::Direct("%s", l.c_str());
}

bool sceneView::queryClick(std::vector<GVertex *> &vertices,
                           std::vector<GEdge *> &edges,
                           std::vector<GFace *> &faces,
                           std::vector<GRegion *> &regions,
                           std::vector<MElement *> &elements,
                           std::vector<PView *> &views)
{
  double xyz[3];
  if(!_ctx->pickPoint(xyz)) return false;

  GEntity *entity = firstEntity(vertices, edges, faces, regions);
  MElement *element = elements.size() ? elements[0] : nullptr;
  // a pick that found a mesh element returns it instead of the entity it
  // belongs to, which the query names as well
  if(!entity) entity = _ctx->pickEntity();
  PView *view = views.size() ? views[0] : nullptr;

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
    _lastSelection(at); // where the click looked, not where the mouse is
    double px = _ctx->pixel_equiv_x / _ctx->s[0];
    if(pick(ENT_ALL, true, false, at[0], at[1], at[2], at[3], v, e, f, r, el, p,
            vw) &&
       _ctx->pickPoint(behind)) {
      GEntity *under = firstEntity(v, e, f, r);
      if(queryBehind(view, xyz, behind, px)) {
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

  double pixel = _ctx->pixel_equiv_x / _ctx->s[0];
  // what was hit may hold no element there (a point or a curve of the
  // geometry, drawn over the mesh and picked before it), or the point read
  // back may be off its surface: the element is then the one of the mesh
  // drawn under the point
  if(!element) element = queryElement(xyz, pixel);

  std::vector<std::string> info = queryPoint(xyz, entity, element, view, pixel);
  // the box over the picture shows the lines that do not begin with a space,
  // i.e. all but the detail of an element
  std::string text;
  for(std::size_t i = 0; i < info.size(); i++) {
    if(info[i].size() && info[i][0] == ' ') continue;
    text += (text.size() ? "\n" : "") + info[i];
  }
  GModel::current()->setSelection(0);
  if(!_addQuery) _ctx->clearMarks();
  _ctx->addMark(xyz);
  hostRedraw();
  if(CTX::instance()->tooltips) pinTooltip(text, xyz, _addQuery);
  printLines(info);
  return true;
}

bool sceneView::measureClick()
{
  double xyz[3];
  if(!_ctx->pickPoint(xyz)) return false;
  GModel::current()->setSelection(0);
  std::vector<std::string> info;
  double first[3];
  if(!measuring() || !_ctx->mark(0, first)) { // start a new measurement
    _ctx->clearMarks();
    _ctx->addMark(xyz);
    pinTooltip("");
  }
  else {
    _ctx->addMark(xyz);
    _ctx->setSegment(first, xyz);
    // the length stays on the picture, in a box over the middle of the line
    // (drawn by the host)
    info = measurePoints(first, xyz);
  }
  hostRedraw();
  printLines(info);
  return true;
}

void sceneView::pinTooltip(const std::string &text, const double *xyz,
                           bool add)
{
  if(!add) {
    if(_pinned.empty() && text.empty()) return;
    _pinned.clear();
  }
  if(text.size() && xyz) {
    pinnedNote n;
    n.text = text;
    for(int i = 0; i < 3; i++) n.xyz[i] = xyz[i];
    _pinned.push_back(n);
  }
  hostRedraw();
}

void sceneView::drawTooltip(const std::string &text)
{
  if(text.empty()) {
    if(_hoverText.empty()) return;
    _hoverText.clear();
    hostRedraw();
    return;
  }
  // it follows the cursor, moving once the cursor has strayed sixty pixels
  // from where it hangs (or when it is under it, or says something else):
  // every move of it is a redraw
  double cx = _curr.win[0], cy = _curr.win[1];
  if(text == _hoverText) {
    // the box, from the top left of the window as the cursor is measured
    double left = _hoverBox[0], right = _hoverBox[0] + _hoverBox[2];
    double top = _ctx->viewport[3] - (_hoverBox[1] + _hoverBox[3]);
    double bottom = _ctx->viewport[3] - _hoverBox[1];
    bool over = (cx > left - 4. && cx < right + 4. && cy > top - 4. &&
                 cy < bottom + 4.);
    if(!over && fabs(cx - _hoverAnchor[0]) < 60. &&
       fabs(cy - _hoverAnchor[1]) < 60.)
      return;
  }
  _hoverText = text;
  _hoverAnchor[0] = cx;
  _hoverAnchor[1] = cy;
  hostRedraw();
}

bool sceneView::releasePhlogiston(int width, int height, bool decay)
{
  if(!CTX::instance()->phlogiston) _phlogiston = 0.;
  if(_phlogiston <= 0.) return false;
  double now = TimeOfDay();
  if(decay) {
    _phlogiston *= exp(-(now - _phlogistonTime) / 1.5);
    _phlogistonTime = now;
  }
  if(_phlogiston < 0.02) {
    _phlogiston = 0.;
    return false;
  }
  glImmediate::flush();
  if(!glShader::phlogiston(width, height, _phlogiston, now)) {
    _phlogiston = 0.;
    return false;
  }
  // (not accumulated: the studio frames start over as long as any is given
  // off)
  _ctx->studioSample = 0;
  return true;
}
