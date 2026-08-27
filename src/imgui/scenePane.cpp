// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cmath>
#include <cstdlib>
#include <algorithm>

#include "imgui.h"

#include "scenePane.h"
#include "appWindow.h"
#include "GuiActions.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "Numeric.h"
#include "Camera.h"
#include "OpenFile.h"
#include "OS.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "MElement.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#endif

scenePane::scenePane()
  : _x(0), _y(0), _w(1), _h(1), _lassoMode(false), _trySelection(0),
    _selection(ENT_NONE), selectionMode(false), endSelection(0),
    undoSelection(0), invertSelection(0), quitSelection(0), changeSelection(0)
{
  _originX = _originY = 0.;
  _pixelFactor = 1.;
  _windowHeight = 0;
  addPointMode = false;
  _point[0] = _point[1] = _point[2] = 0.;
  _ctx = new drawContext();
  _lassoXY[0] = _lassoXY[1] = 0.;
  for(int i = 0; i < 4; i++) _trySelectionXYWH[i] = 0;
}

scenePane::~scenePane() { delete _ctx; }

void scenePane::setRect(int x, int y, int w, int h)
{
  _x = x;
  _y = y;
  _w = (w > 1) ? w : 1;
  _h = (h > 1) ? h : 1;
}

void scenePane::setOrigin(double x, double y, int height, double pixelFactor)
{
  _originX = x;
  _originY = y;
  _windowHeight = height;
  _pixelFactor = pixelFactor;
}

void scenePane::_drawScreenMessage()
{
  if(screenMessage[0].empty() && screenMessage[1].empty()) return;

  glColor4ubv((GLubyte *)&CTX::instance()->color.text);
  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double h = drawContext::global()->getStringHeight();

  for(int i = 0; i < 2; i++) {
    if(screenMessage[i].empty()) continue;
    const char *txt = screenMessage[i].c_str();
    double w = drawContext::global()->getStringWidth(txt);
    glRasterPos2d(_ctx->viewport[2] / 2. - w / 2.,
                  _ctx->viewport[3] - (1.2 + 1.2 * i) * h);
    drawContext::global()->drawString(txt);
  }
}

void scenePane::_drawLasso()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho((double)_ctx->viewport[0], (double)_ctx->viewport[2],
          (double)_ctx->viewport[1], (double)_ctx->viewport[3], -1., 1.);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glColor3d(1., 1., 1.);
  glDisable(GL_DEPTH_TEST);
  if(selectionMode && CTX::instance()->mouseSelection) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0F0F);
  }
  glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
  glEnable(GL_BLEND);
  glLineWidth(1.0F);
  glBegin(GL_LINE_LOOP);
  glVertex2d(_click.win[0], _ctx->viewport[3] - _click.win[1]);
  glVertex2d(_curr.win[0], _ctx->viewport[3] - _click.win[1]);
  glVertex2d(_curr.win[0], _ctx->viewport[3] - _curr.win[1]);
  glVertex2d(_click.win[0], _ctx->viewport[3] - _curr.win[1]);
  glEnd();
  _lassoXY[0] = _curr.win[0];
  _lassoXY[1] = _curr.win[1];
  glDisable(GL_BLEND);
  glDisable(GL_LINE_STIPPLE);
  glEnable(GL_DEPTH_TEST);
}

// when the view is split, outline the pane so that it is clear which one the
// keyboard and the .geo commands act on
void scenePane::_drawBorder()
{
  if(appWindow::instance()->numPanes() < 2) return;
  bool current = (appWindow::instance()->currentPane() == this);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho((double)_ctx->viewport[0], (double)_ctx->viewport[2],
          (double)_ctx->viewport[1], (double)_ctx->viewport[3], -1., 1.);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glDisable(GL_DEPTH_TEST);
  if(current)
    glColor4ubv((GLubyte *)&CTX::instance()->color.text);
  else
    glColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  glLineWidth(current ? 2.f : 1.f);
  glBegin(GL_LINE_LOOP);
  glVertex2d(_ctx->viewport[0] + 1, _ctx->viewport[1] + 1);
  glVertex2d(_ctx->viewport[2] - 1, _ctx->viewport[1] + 1);
  glVertex2d(_ctx->viewport[2] - 1, _ctx->viewport[3] - 1);
  glVertex2d(_ctx->viewport[0] + 1, _ctx->viewport[3] - 1);
  glEnd();
  glLineWidth(1.f);
  glEnable(GL_DEPTH_TEST);
}

void scenePane::draw(double pixelFactor, int windowHeight)
{
  // the scene is rendered directly into the rectangle of the central dock node,
  // so both the viewport and the scissor box are needed: the scissor box keeps
  // glClear() and the drawing inside the pane, which is what makes several
  // panes able to share the same framebuffer
  int px = (int)(_x * pixelFactor + 0.5);
  int py = (int)((windowHeight - _y - _h) * pixelFactor + 0.5);
  int pw = (int)(_w * pixelFactor + 0.5);
  int ph = (int)(_h * pixelFactor + 0.5);
  if(pw < 1) pw = 1;
  if(ph < 1) ph = 1;

  _ctx->viewport[0] = 0;
  _ctx->viewport[1] = 0;
  _ctx->viewport[2] = _w;
  _ctx->viewport[3] = _h;
  _ctx->setHighResolutionPixelFactor(pixelFactor);

  glViewport(px, py, pw, ph);
  glEnable(GL_SCISSOR_TEST);
  glScissor(px, py, pw, ph);

  if(CTX::instance()->printing && !CTX::instance()->print.background)
    glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
  else
    glClearColor(
      (GLclampf)(CTX::instance()->unpackRed(CTX::instance()->color.bg) / 255.),
      (GLclampf)(CTX::instance()->unpackGreen(CTX::instance()->color.bg) / 255.),
      (GLclampf)(CTX::instance()->unpackBlue(CTX::instance()->color.bg) / 255.),
      0.0F);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  if(CTX::instance()->camera && !CTX::instance()->stereo) {
    Camera *cam = &(_ctx->camera);
    if(!cam->on) cam->init();
    cam->giveViewportDimension(_ctx->viewport[2], _ctx->viewport[3]);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(cam->glFleft, cam->glFright, cam->glFbottom, cam->glFtop,
              cam->glFnear, cam->glFfar * cam->Lc);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cam->position.x, cam->position.y, cam->position.z, cam->target.x,
              cam->target.y, cam->target.z, cam->up.x, cam->up.y, cam->up.z);
    _ctx->draw3d();
    _ctx->draw2d();
  }
  else {
    _ctx->draw3d();
    _ctx->draw2d();
  }
  if(addPointMode) {
    // the point that is being placed, drawn between the 3D and the 2D passes
    // exactly as the FLTK backend does
    glColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
    glPointSize(CTX::instance()->geom.pointSize *
                _ctx->highResolutionPixelFactor());
    glBegin(GL_POINTS);
    glVertex3d(_point[0], _point[1], _point[2]);
    glEnd();
  }
  _drawScreenMessage();
  _drawBorder();
  if(_lassoMode) _drawLasso();
  drawContext::global()->flushString();

  glDisable(GL_SCISSOR_TEST);

  // FIXME: this should not be done here, but the FLTK backend does the same
  _ctx->camera.update();
}

bool scenePane::_select(int type, bool multiple, bool mesh, bool post, int x,
                        int y, int w, int h, std::vector<GVertex *> &vertices,
                        std::vector<GEdge *> &edges,
                        std::vector<GFace *> &faces,
                        std::vector<GRegion *> &regions,
                        std::vector<MElement *> &elements,
                        std::vector<SPoint2> &points,
                        std::vector<PView *> &views)
{
  // see the comment in openglWindow::_select(): GL_SELECT passes are skipped
  // altogether when mouse selection is off
  if(!CTX::instance()->mouseSelection) return false;
  return _ctx->select(type, multiple, mesh, post, x, y, w, h, vertices, edges,
                      faces, regions, elements, points, views);
}

void scenePane::_lassoZoom()
{
  if(_click.win[0] == _curr.win[0] || _click.win[1] == _curr.win[1]) return;

  _ctx->s[0] *= (double)_ctx->viewport[2] / (_curr.win[0] - _click.win[0]);
  _ctx->s[1] *= (double)_ctx->viewport[3] / (_curr.win[1] - _click.win[1]);
  _ctx->s[2] = std::min(_ctx->s[0], _ctx->s[1]);

  // recenter around the center of the lasso rectangle
  mousePosition tmp(_click);
  tmp.wnr[0] = 0.5 * (_click.wnr[0] + _curr.wnr[0]);
  tmp.wnr[1] = 0.5 * (_click.wnr[1] + _curr.wnr[1]);
  tmp.recenter(_ctx);

  _ctx->initPosition(false);
  drawContext::global()->draw();
}

// What is under the pointer: the same query the FLTK interface runs on FL_MOVE.
// It says what the entity is, and what a double click on it would do, either in
// a tooltip or in the status bar depending on General.Tooltips.
void scenePane::_hover()
{
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;
  std::vector<SPoint2> points;
  std::vector<PView *> views;

  bool res = _select(_selection, false, CTX::instance()->mouseHoverMeshes,
                     CTX::instance()->mouseHoverMeshes, (int)_curr.win[0],
                     (int)_curr.win[1], 5, 5, vertices, edges, faces, regions,
                     elements, points, views);

  // there is no crosshair among the cursors Dear ImGui knows, so the hand is
  // what says "this can be clicked"
  if((_selection == ENT_ALL && res) ||
     (_selection == ENT_POINT && vertices.size()) ||
     (_selection == ENT_CURVE && edges.size()) ||
     (_selection == ENT_SURFACE && faces.size()) ||
     (_selection == ENT_VOLUME && regions.size()))
    ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);

  std::string text, cmd;
  bool multiline = CTX::instance()->tooltips;
  if(vertices.size()) {
    text = vertices[0]->getInfoString(true, multiline);
    cmd = CTX::instance()->geom.doubleClickedPointCommand;
  }
  else if(edges.size()) {
    text = edges[0]->getInfoString(true, multiline);
    cmd = CTX::instance()->geom.doubleClickedCurveCommand;
  }
  else if(faces.size()) {
    text = faces[0]->getInfoString(true, multiline);
    cmd = CTX::instance()->geom.doubleClickedSurfaceCommand;
  }
  else if(regions.size()) {
    text = regions[0]->getInfoString(true, multiline);
    cmd = CTX::instance()->geom.doubleClickedVolumeCommand;
  }
  else if(elements.size()) {
    text = elements[0]->getInfoString(multiline);
  }
  else if(points.size()) {
    char tmp[256];
    snprintf(tmp, sizeof(tmp), "Point (%g, %g)", points[0].x(), points[0].y());
    text = tmp;
    cmd = CTX::instance()->post.doubleClickedGraphPointCommand;
  }
#if defined(HAVE_POST)
  else if(views.size()) {
    char tmp[256];
    snprintf(tmp, sizeof(tmp), "View[%d]", views[0]->getIndex());
    text = tmp;
    cmd = views[0]->getOptions()->doubleClickedCommand;
  }
#endif

  if(cmd.size()) {
    if(multiline)
      text += "\n\n";
    else
      text += " ";
    if(cmd == "ONELAB") { text += "Double-click to edit parameters"; }
    else {
      text += "Double-click to execute\n\n";
      std::replace(cmd.begin(), cmd.end(), '\r', ' ');
      text += cmd;
    }
  }

  if(CTX::instance()->tooltips)
    appWindow::instance()->setTooltip(text);
  else
    Msg::StatusBar(false, "%s", text.c_str());
}

void scenePane::handleMouse(const paneInput &in)
{
  double mx = in.x, my = in.y;

  // pane-local coordinates, with y measured from the top, as in the FLTK
  // backend; mx and my come in the space the pane origin is expressed in, which
  // is not the space the pane rectangle lives in
  double lx = mx - _originX - _x, ly = my - _originY - _y;

  bool shift = in.shift, ctrl = in.ctrl, alt = in.alt;
  bool meta = in.super;

  // --- wheel: zoom
  if(in.wheel != 0. && contains(mx, my)) {
    _prev.set(_ctx, (int)lx, (int)ly);
    double dy = -in.wheel;
    double fact = (5. * CTX::instance()->zoomFactor * fabs(dy) + _h) / (double)_h;
    bool direction = (CTX::instance()->mouseInvertZoom) ? (dy <= 0) : (dy > 0);
    if(CTX::instance()->camera) {
      fact = (direction ? fact : 1. / fact);
      _ctx->camera.zoom(fact);
      _ctx->camera.update();
    }
    else {
      _ctx->s[0] *= (direction ? fact : 1. / fact);
      _ctx->s[1] = _ctx->s[0];
      _ctx->s[2] = _ctx->s[0];
      _prev.recenter(_ctx);
    }
    appWindow::instance()->requestRedraw();
  }

  // --- placing a new entity: the pointer drives its coordinates, unless the
  // user holds Shift to keep them where they are
  if(addPointMode && contains(mx, my)) {
    if(!shift && (in.dx != 0. || in.dy != 0.)) {
      _curr.set(_ctx, (int)lx, (int)ly);
      bool frozen[3];
      for(int i = 0; i < 3; i++) frozen[i] = elementaryFrozen(i);
      geometryPointUnderCursor(_ctx, (int)_curr.win[0], (int)_curr.win[1],
                               frozen, _point);
      // the coordinates of the entity being placed live in the shared store,
      // which is what the dialog edits
      for(int i = 0; i < 3; i++) {
        if(frozen[i]) continue;
        char str[32];
        snprintf(str, sizeof(str), "%g", _point[i]);
        int pane = elementaryPaneStore();
        if(pane >= 1 && pane <= 11) elementaryStore(pane, i) = str;
      }
      appWindow::instance()->requestRedraw();
    }
    return;
  }

  // --- hover: what is under the pointer, when nothing else is going on
  bool busy = _lassoMode;
  for(int b = 0; b < 3; b++)
    if(in.clicked[b] || in.released[b] || in.dragging[b]) busy = true;
  if(!busy && contains(mx, my) && (in.dx != 0. || in.dy != 0.)) {
    _curr.set(_ctx, (int)lx, (int)ly);
    _hover();
    _prev.set(_ctx, (int)lx, (int)ly);
    appWindow::instance()->requestRedraw();
    return;
  }

  // --- button press
  int button = -1;
  for(int b = 0; b < 3; b++)
    if(in.clicked[b]) button = b;

  if(button >= 0 && contains(mx, my)) {
    appWindow::instance()->setCurrentPane(this);
    _curr.set(_ctx, (int)lx, (int)ly);

    if(in.doubleClicked && !selectionMode &&
       CTX::instance()->mouseSelection) {
      _handleDoubleClick(lx, ly);
      _click.set(_ctx, (int)lx, (int)ly);
      _prev.set(_ctx, (int)lx, (int)ly);
      return;
    }

    if(button == 0 && !shift && !alt) {
      if(!_lassoMode && ctrl) {
        _lassoMode = true;
        _lassoXY[0] = _curr.win[0];
        _lassoXY[1] = _curr.win[1];
      }
      else if(_lassoMode) {
        _lassoMode = false;
        if(selectionMode && CTX::instance()->mouseSelection) {
          _trySelection = 2;
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
        // will try to select an entity
        _trySelection = shift ? -1 : 1;
        _trySelectionXYWH[0] = (int)_curr.win[0];
        _trySelectionXYWH[1] = (int)_curr.win[1];
        _trySelectionXYWH[2] = 5;
        _trySelectionXYWH[3] = 5;
      }
    }
    else if(button == 1 && !selectionMode) {
      if(!CTX::instance()->camera) {
        _ctx->t[0] = _ctx->t[1] = _ctx->t[2] = 0.;
        _ctx->s[0] = _ctx->s[1] = _ctx->s[2] = 1.;
        appWindow::instance()->requestRedraw();
      }
      _lassoMode = false;
    }

    _click.set(_ctx, (int)lx, (int)ly);
    _prev.set(_ctx, (int)lx, (int)ly);
    return;
  }

  // --- release
  if(in.released[0] || in.released[1] || in.released[2]) {
    if(appWindow::instance()->currentPane() != this) return;
    _curr.set(_ctx, (int)lx, (int)ly);
    CTX::instance()->drawRotationCenter = 0;
    if(!_lassoMode) {
      CTX::instance()->mesh.draw = 1;
      CTX::instance()->post.draw = 1;
      appWindow::instance()->requestRedraw();
    }
    _prev.set(_ctx, (int)lx, (int)ly);
    return;
  }

  // --- drag
  int dragButton = -1;
  for(int b = 0; b < 3; b++)
    if(in.dragging[b]) dragButton = b;
  if(dragButton < 0) return;
  if(appWindow::instance()->currentPane() != this) return;

  _curr.set(_ctx, (int)lx, (int)ly);
  double dx = _curr.win[0] - _prev.win[0];
  double dy = _curr.win[1] - _prev.win[1];

  if(_lassoMode) {
    appWindow::instance()->requestRedraw();
    _prev.set(_ctx, (int)lx, (int)ly);
    return;
  }

  if(meta) {
    // select or unselect entities on the fly
    _trySelection = shift ? -1 : 1;
    _trySelectionXYWH[0] = (int)_curr.win[0];
    _trySelectionXYWH[1] = (int)_curr.win[1];
    _trySelectionXYWH[2] = 5;
    _trySelectionXYWH[3] = 5;
  }
  // (m1) and (!shift) and (!alt) => rotation
  else if(dragButton == 0 && !shift && !alt) {
    if(CTX::instance()->useTrackball)
      _ctx->addQuaternion((2. * _prev.win[0] - _w) / _w,
                          (_h - 2. * _prev.win[1]) / _h,
                          (2. * _curr.win[0] - _w) / _w,
                          (_h - 2. * _curr.win[1]) / _h);
    else {
      _ctx->r[1] += ((fabs(dx) > fabs(dy)) ? 180. * dx / (double)_w : 0.);
      _ctx->r[0] += ((fabs(dx) > fabs(dy)) ? 0. : 180. * dy / (double)_h);
    }
  }
  // m2 or (m1 and shift) => zoom around the point that was clicked
  else if(dragButton == 2 ||
          (dragButton == 0 && shift)) {
    if(CTX::instance()->camera) {
      double fact =
        (CTX::instance()->zoomFactor * fabs(dy) + (double)_h) / (double)_h;
      fact = ((dy > 0) ? fact : 1. / fact);
      _ctx->camera.zoom(fact);
      _ctx->camera.update();
    }
    else {
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
      double theta_x =
        cam->radians * (-(double)_prev.win[0] + (double)_curr.win[0]) * 2. / _h;
      double theta_y =
        cam->radians * (-(double)_prev.win[1] + (double)_curr.win[1]) * 2. / _h;
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
  appWindow::instance()->requestRedraw();
  _prev.set(_ctx, (int)lx, (int)ly);
}

void scenePane::_handleDoubleClick(double lx, double ly)
{
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;
  std::vector<SPoint2> points;
  std::vector<PView *> views;
  _select(ENT_ALL, false, CTX::instance()->mouseHoverMeshes, true, (int)lx,
          (int)ly, 5, 5, vertices, edges, faces, regions, elements, points,
          views);

  struct {
    bool hit;
    int dim, tag;
    const std::string *command;
  } hits[4] = {
    {!vertices.empty(), 0, vertices.empty() ? 0 : vertices[0]->tag(),
     &CTX::instance()->geom.doubleClickedPointCommand},
    {!edges.empty(), 1, edges.empty() ? 0 : edges[0]->tag(),
     &CTX::instance()->geom.doubleClickedCurveCommand},
    {!faces.empty(), 2, faces.empty() ? 0 : faces[0]->tag(),
     &CTX::instance()->geom.doubleClickedSurfaceCommand},
    {!regions.empty(), 3, regions.empty() ? 0 : regions[0]->tag(),
     &CTX::instance()->geom.doubleClickedVolumeCommand}};

  for(int i = 0; i < 4; i++) {
    if(!hits[i].hit || hits[i].command->empty()) continue;
    CTX::instance()->geom.doubleClickedEntityTag = hits[i].tag;
    if(*hits[i].command == "ONELAB")
      appWindow::instance()->showContextWindow(hits[i].dim, hits[i].tag);
    else
      ParseString(*hits[i].command, true);
    return;
  }

  if(views.size() && views[0]->getOptions()->doubleClickedCommand.size()) {
    CTX::instance()->post.doubleClickedView = views[0]->getIndex();
    ParseString(views[0]->getOptions()->doubleClickedCommand, true);
    return;
  }
  if(points.size() &&
     CTX::instance()->post.doubleClickedGraphPointCommand.size()) {
    CTX::instance()->post.doubleClickedGraphPointX = points[0].x();
    CTX::instance()->post.doubleClickedGraphPointY = points[0].y();
    ParseString(CTX::instance()->post.doubleClickedGraphPointCommand, true);
  }
}

char scenePane::selectEntity(int type, std::vector<GVertex *> &vertices,
                             std::vector<GEdge *> &edges,
                             std::vector<GFace *> &faces,
                             std::vector<GRegion *> &regions,
                             std::vector<MElement *> &elements,
                             std::vector<SPoint2> &points,
                             std::vector<PView *> &views)
{
  if(!appWindow::available()) return 'q';

  _selection = type;
  _trySelection = 0;
  selectionMode = true;
  quitSelection = 0;
  changeSelection = 0;
  endSelection = 0;
  undoSelection = 0;
  invertSelection = 0;

  while(1) {
    if(!appWindow::available()) return 'q';
    vertices.clear();
    edges.clear();
    faces.clear();
    regions.clear();
    elements.clear();
    appWindow::instance()->wait(false);
    if(!appWindow::available()) return 'q';
    if(changeSelection) {
      Msg::Debug("Changing selection mode to %d", changeSelection);
      _selection = changeSelection;
      changeSelection = 0;
    }
    if(quitSelection) {
      _selection = ENT_NONE;
      selectionMode = false;
      _lassoMode = false;
      return 'q';
    }
    if(endSelection) {
      _selection = ENT_NONE;
      endSelection = 0;
      return 'e';
    }
    if(undoSelection) {
      undoSelection = 0;
      return 'u';
    }
    if(invertSelection) {
      invertSelection = 0;
      return 'i';
    }
    if(_trySelection) {
      bool add = (_trySelection > 0);
      bool multi = (abs(_trySelection) > 1);
      _trySelection = 0;
      if(_selection == ENT_NONE) { // just report the mouse click
        selectionMode = false;
        return 'c';
      }
      else if(_select(_selection, multi, true, true, _trySelectionXYWH[0],
                      _trySelectionXYWH[1], _trySelectionXYWH[2],
                      _trySelectionXYWH[3], vertices, edges, faces, regions,
                      elements, points, views)) {
        _selection = ENT_NONE;
        selectionMode = false;
        return add ? 'l' : 'r';
      }
    }
  }
}

#endif
