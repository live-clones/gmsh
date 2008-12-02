// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/gl.h>
#include "openglWindow.h"
#include "graphicWindow.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "Draw.h"
#include "Numeric.h"
#include "GUI.h"
#include "VertexArray.h"
#include "Context.h"

extern Context_T CTX;

void mousePosition::set(drawContext *ctx)
{
  for(int i = 0; i < 3; i++){
    s[i] = ctx->s[i];
    t[i] = ctx->t[i];
  }

  win[0] = (double)Fl::event_x();
  win[1] = (double)Fl::event_y();
  win[2] = 0.;

  wnr[0] = 
    (ctx->vxmin + win[0] / (double)ctx->viewport[2] * (ctx->vxmax - ctx->vxmin)) 
    / ctx->s[0] - ctx->t[0] + ctx->t_init[0] / ctx->s[0];
  wnr[1] = 
    (ctx->vymax - win[1] / (double)ctx->viewport[3] * (ctx->vymax - ctx->vymin))
    / ctx->s[1] - ctx->t[1] + ctx->t_init[1] / ctx->s[1];
  wnr[2] = 0.;
}

void mousePosition::recenter(drawContext *ctx)
{
  // compute the equivalent translation to apply *after* the scaling
  // so that the scaling is done around the point which was clicked:
  ctx->t[0] = t[0] * (s[0] / ctx->s[0]) - wnr[0] * (1. - (s[0] / ctx->s[0]));
  ctx->t[1] = t[1] * (s[1] / ctx->s[1]) - wnr[1] * (1. - (s[1] / ctx->s[1]));
}
  
static void lassoZoom(drawContext *ctx, mousePosition &click1, mousePosition &click2)
{
  if(click1.win[0] == click2.win[0] || click1.win[1] == click2.win[1])
    return;

  ctx->s[0] *= (double)ctx->viewport[2] / (click2.win[0] - click1.win[0]);
  ctx->s[1] *= (double)ctx->viewport[3] / (click2.win[1] - click1.win[1]);
  ctx->s[2] = std::min(ctx->s[0], ctx->s[1]); // bof...
  
  // recenter around the center of the lasso rectangle
  mousePosition tmp(click1);
  tmp.wnr[0] = 0.5 * (click1.wnr[0] + click2.wnr[0]);
  tmp.wnr[1] = 0.5 * (click1.wnr[1] + click2.wnr[1]);
  tmp.recenter(ctx);

  ctx->initPosition();
  Draw();
  GUI::instance()->manip->update();
}

openglWindow::openglWindow(int x, int y, int w, int h, const char *l)
  : Fl_Gl_Window(x, y, w, h, l)
{
  _ctx = new drawContext();
  for(int i = 0; i < 3; i++) _point[i] = 0.;
  _selection = ENT_NONE;
  _trySelection = 0;
  for(int i = 0; i < 4; i++) _trySelectionXYWH[i] = 0;
  
  addPointMode = lassoMode = selectionMode = false;
  endSelection = undoSelection = invertSelection = quitSelection = 0;
}

openglWindow::~openglWindow()
{ 
  delete _ctx; 
}

void openglWindow::draw()
{
  static int locked = 0;
  if(locked)
    return;
  else
    locked = 1;

  Msg::Debug("openglWindow->draw()");

  if(!valid()) {
    valid(1);
    _ctx->viewport[0] = 0;
    _ctx->viewport[1] = 0;
    _ctx->viewport[2] = w();
    _ctx->viewport[3] = h();
    glViewport(_ctx->viewport[0], _ctx->viewport[1],
               _ctx->viewport[2], _ctx->viewport[3]);
  }
  else {
    if((w() != _ctx->viewport[2] - _ctx->viewport[0]) ||
       (h() != _ctx->viewport[3] - _ctx->viewport[1])) {
      GUI::instance()->setGraphicSize(_ctx->viewport[2] - _ctx->viewport[0],
                                      _ctx->viewport[3] - _ctx->viewport[1]);
      glViewport(_ctx->viewport[0], _ctx->viewport[1],
                 _ctx->viewport[2], _ctx->viewport[3]);
    }
  }

  if(lassoMode) { 
    // draw the zoom or selection lasso on top of the current scene
    // (without using overlays!)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((double)_ctx->viewport[0], (double)_ctx->viewport[2],
            (double)_ctx->viewport[1], (double)_ctx->viewport[3], -1., 1.);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3d(1., 1., 1.);
    glDisable(GL_DEPTH_TEST);
    if(selectionMode && CTX.mouse_selection){
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x0F0F);
    }
    // glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    glEnable(GL_BLEND);
    glLineWidth(0.2);
    for(int i = 0; i < 2; i++){
      glBegin(GL_LINE_STRIP);
      glVertex2d(_click.win[0], _ctx->viewport[3] - _click.win[1]);
      glVertex2d(_lasso.win[0], _ctx->viewport[3] - _click.win[1]);
      glVertex2d(_lasso.win[0], _ctx->viewport[3] - _lasso.win[1]);
      glVertex2d(_click.win[0], _ctx->viewport[3] - _lasso.win[1]);
      glVertex2d(_click.win[0], _ctx->viewport[3] - _click.win[1]);
      glEnd();
      if(!i) _lasso.set(_ctx);
    }
    glDisable(GL_BLEND);
    if(selectionMode && CTX.mouse_selection)
      glDisable(GL_LINE_STIPPLE);
    glEnable(GL_DEPTH_TEST);
  }
  else if(addPointMode) { 
    // draw the whole scene and the point to add
    if(CTX.fast_redraw) {
      CTX.mesh.draw = 0;
      CTX.post.draw = 0;
    }
    ClearOpengl();
    _ctx->draw3d();
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glPointSize(CTX.geom.point_size);
    glBegin(GL_POINTS);
    glVertex3d(_point[0], _point[1], _point[2]);
    glEnd();
    _ctx->draw2d();
    CTX.mesh.draw = 1;
    CTX.post.draw = 1;
  }
  else{
    // draw the whole scene
    ClearOpengl();
    _ctx->draw3d();
    _ctx->draw2d();
  }

  locked = 0;
}

// The event model in FLTK is pretty different from other toolkits:
// the events are passed to the widget handle of the widget that has
// the focus. If this handle returns 1, then the event is considered
// as treated, and is suppressed. If the handle returns 0, the event
// is passed to the parent.

int openglWindow::handle(int event)
{
  switch (event) {

  case FL_FOCUS: // accept the focus when I'm asked if I want it
  case FL_UNFOCUS:
    return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // override the default widget arrow-key-navigation
    if(GUI::instance()->testArrowShortcuts())
      return 1;
    return Fl_Gl_Window::handle(event);
    
  case FL_PUSH:
    take_focus(); // force keyboard focus when we click in the window
    _curr.set(_ctx);
    if(Fl::event_button() == 1 && 
       !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
      if(!lassoMode && Fl::event_state(FL_CTRL)) {
        lassoMode = true;
        _lasso.set(_ctx);
      }
      else if(lassoMode) {
        lassoMode = false;
        if(selectionMode && CTX.mouse_selection){
          // will try to select multiple entities
          _trySelection = 2;
          _trySelectionXYWH[0] = (int)(_click.win[0] + _curr.win[0]) / 2;
          _trySelectionXYWH[1] = (int)(_click.win[1] + _curr.win[1]) / 2;
          _trySelectionXYWH[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          _trySelectionXYWH[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else{
          lassoZoom(_ctx, _click, _curr);
        }
      }
      else if(CTX.mouse_selection){
        // will try to select clicked entity
        _trySelection = 1;
        _trySelectionXYWH[0] = (int)_curr.win[0];
        _trySelectionXYWH[1] = (int)_curr.win[1];
        _trySelectionXYWH[2] = 5;
        _trySelectionXYWH[3] = 5;
      }
    }
    else if(Fl::event_button() == 2 || 
            (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
      if(!lassoMode && Fl::event_state(FL_CTRL)) {
        // make zoom isotropic
        _ctx->s[1] = _ctx->s[0];
        _ctx->s[2] = _ctx->s[0];
        redraw();
      }
      else if(lassoMode) {
        lassoMode = false;
        if(selectionMode && CTX.mouse_selection){
          // will try to unselect multiple entities
          _trySelection = -2;
          _trySelectionXYWH[0] = (int)(_click.win[0] + _curr.win[0]) / 2;
          _trySelectionXYWH[1] = (int)(_click.win[1] + _curr.win[1]) / 2;
          _trySelectionXYWH[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          _trySelectionXYWH[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else{
          lassoZoom(_ctx, _click, _curr);
        }
      }
      else if(CTX.mouse_selection){
        // will try to unselect clicked entity
        _trySelection = -1;
        _trySelectionXYWH[0] = (int)_curr.win[0];
        _trySelectionXYWH[1] = (int)_curr.win[1];
        _trySelectionXYWH[2] = 5;
        _trySelectionXYWH[3] = 5;
      }
    }
    else {
      if(Fl::event_state(FL_CTRL) && !lassoMode) {
        if(CTX.useTrackball)
          _ctx->setQuaternion(0., 0., 0., 1.);
        else
          _ctx->r[0] = _ctx->r[1] = _ctx->r[2] = 0.;
        _ctx->t[0] = _ctx->t[1] = _ctx->t[2] = 0.;
        _ctx->s[0] = _ctx->s[1] = _ctx->s[2] = 1.;
        redraw();
      }
      else {
        lassoMode = false;
      }
    }
    _click.set(_ctx);
    _prev.set(_ctx);
    GUI::instance()->manip->update();
    return 1;

  case FL_RELEASE:
    _curr.set(_ctx);
    CTX.draw_rotation_center = 0;
    if(!lassoMode) {
      CTX.mesh.draw = 1;
      CTX.post.draw = 1;
      redraw();
    }
    _prev.set(_ctx);
    return 1;

  case FL_MOUSEWHEEL:
    {
      double dy = Fl::event_dy();
      double fact = (5. * CTX.zoom_factor * fabs(dy) + h()) / (double)h();
      _ctx->s[0] *= ((dy > 0) ? fact : 1./fact);
      _ctx->s[1] = _ctx->s[0];
      _ctx->s[2] = _ctx->s[0];
      _prev.recenter(_ctx);
      redraw();
    }
    GUI::instance()->manip->update();
    return 1;

  case FL_DRAG:
    _curr.set(_ctx);
    {
      double dx = _curr.win[0] - _prev.win[0];
      double dy = _curr.win[1] - _prev.win[1];
      if(lassoMode) {
        redraw();
      }
      else {
        if(Fl::event_state(FL_META)) {
          // will try to select or unselect entities on the fly
          _trySelection = Fl::event_state(FL_SHIFT) ? -1 : 1; 
          _trySelectionXYWH[0] = (int)_curr.win[0];
          _trySelectionXYWH[1] = (int)_curr.win[1];
          _trySelectionXYWH[2] = 5;
          _trySelectionXYWH[3] = 5;
        }
        else if(Fl::event_button() == 1 && 
                !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
          if(CTX.useTrackball)
            _ctx->addQuaternion((2. * _prev.win[0] - w()) / w(),
                                (h() - 2. * _prev.win[1]) / h(),
                                (2. * _curr.win[0] - w()) / w(),
                                (h() - 2. * _curr.win[1]) / h());
          else {
            _ctx->r[1] += ((fabs(dx) > fabs(dy)) ? 180. * dx / (double)w() : 0.);
            _ctx->r[0] += ((fabs(dx) > fabs(dy)) ? 0. : 180. * dy / (double)h());
          }
        }
        else if(Fl::event_button() == 2 ||
                (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
          if(fabs(dy) > fabs(dx)) {
            double fact = (CTX.zoom_factor * fabs(dy) + h()) / (double)h();
            _ctx->s[0] *= ((dy > 0) ? fact : 1./fact);
            _ctx->s[1] = _ctx->s[0];
            _ctx->s[2] = _ctx->s[0];
            _click.recenter(_ctx);
          }
          else if(!CTX.useTrackball)
            _ctx->r[2] += -180. * dx / (double)w();
        }
        else {
          _ctx->t[0] += (_curr.wnr[0] - _click.wnr[0]);
          _ctx->t[1] += (_curr.wnr[1] - _click.wnr[1]);
          _ctx->t[2] = 0.;
        }
        CTX.draw_rotation_center = 1;
        if(CTX.fast_redraw) {
          CTX.mesh.draw = 0;
          CTX.post.draw = 0;
        }
        redraw();
      }
    }
    _prev.set(_ctx);
    GUI::instance()->manip->update();
    return 1;

  case FL_MOVE:
    _curr.set(_ctx);
    if(lassoMode) {
      redraw();
    }
    else if(addPointMode && !Fl::event_state(FL_SHIFT)){
      cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
      // find line in real space corresponding to current cursor position
      double p[3],d[3];
      _ctx->unproject(_curr.win[0], _curr.win[1], p, d);
      // fin closest point to the center of gravity
      double r[3] = {CTX.cg[0] - p[0], CTX.cg[1] - p[1], CTX.cg[2] - p[2]}, t;
      prosca(r, d, &t);
      for(int i = 0; i < 3; i++){
        _point[i] = p[i] + t * d[i];
        if(CTX.geom.snap[i]){
          double d = _point[i] / CTX.geom.snap[i];
          double f = floor(d);
          double c = ceil(d);
          double n = (d - f < c - d) ? f : c;
          _point[i] = n * CTX.geom.snap[i];
        }
      }
      char str[32];
      sprintf(str, "%g", _point[0]); 
      GUI::instance()->geoContext->input[2]->value(str);
      sprintf(str, "%g", _point[1]); 
      GUI::instance()->geoContext->input[3]->value(str);
      sprintf(str, "%g", _point[2]); 
      GUI::instance()->geoContext->input[4]->value(str);
      redraw();
    }
    else{ // hover mode
      if(_curr.win[0] != _prev.win[0] || _curr.win[1] != _prev.win[1]){
        std::vector<GVertex*> vertices;
        std::vector<GEdge*> edges;
        std::vector<GFace*> faces;
        std::vector<GRegion*> regions;
        std::vector<MElement*> elements;
        bool res = processSelectionBuffer(_selection, false, CTX.mouse_hover_meshes, 
                                          (int)_curr.win[0], (int)_curr.win[1], 5, 5,
                                          vertices, edges, faces, regions, elements);
        if((_selection == ENT_ALL && res) ||
           (_selection == ENT_POINT && vertices.size()) ||
           (_selection == ENT_LINE && edges.size()) || 
           (_selection == ENT_SURFACE && faces.size()) ||
           (_selection == ENT_VOLUME && regions.size()))
          cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
        else
          cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
        GEntity *ge = 0;
        if(vertices.size()) ge = vertices[0];
        else if(edges.size()) ge = edges[0];
        else if(faces.size()) ge = faces[0];
        else if(regions.size()) ge = regions[0];
        MElement *me = elements.size() ? elements[0] : 0;
        Msg::StatusBar(2, false, "%s %s",
                       ge ? ge->getInfoString().c_str() : "", 
                       me ? me->getInfoString().c_str() : "");
      }
    }
    _prev.set(_ctx);
    return 1;

  default:
    return Fl_Gl_Window::handle(event);
  }
}

class hit{
 public:
  GLuint type, ient, depth, type2, ient2;
  hit(GLuint t, GLuint i, GLuint d, GLuint t2=0, GLuint i2=0) 
    : type(t), ient(i), depth(d), type2(t2), ient2(i2) {}
};

class hitDepthLessThan{
 public:
  bool operator()(const hit &h1, const hit &h2) const
  {
    return h1.depth < h2.depth;
  }
};

// returns the element at a given position in a vertex array (element
// pointers are not always stored: returning 0 is not an error)
static MElement *getElement(GEntity *e, int va_type, int index)
{
  switch(va_type){
  case 2: 
    if(e->va_lines && index < e->va_lines->getNumElementPointers())
      return *e->va_lines->getElementPointerArray(index);
    break;
  case 3:
    if(e->va_triangles && index < e->va_triangles->getNumElementPointers())
      return *e->va_triangles->getElementPointerArray(index);
    break;
  }
  return 0;
}

bool openglWindow::processSelectionBuffer(int type, bool multipleSelection,
                                          bool meshSelection, int x, int y, int w, int h,
                                          std::vector<GVertex*> &vertices,
                                          std::vector<GEdge*> &edges,
                                          std::vector<GFace*> &faces,
                                          std::vector<GRegion*> &regions,
                                          std::vector<MElement*> &elements)
{
  vertices.clear();
  edges.clear();
  faces.clear();
  regions.clear();
  elements.clear();

  // In our case the selection buffer size is equal to between 5 and 7
  // times the maximum number of possible hits
  GModel *m = GModel::current();
  int eles = (meshSelection && CTX.pick_elements) ? 4 * m->getNumMeshElements() : 0;
  int size = 7 * (m->getNumVertices() + m->getNumEdges() + m->getNumFaces() + 
                  m->getNumRegions() + eles) + 1000 ;

  make_current();
  GLuint *selectionBuffer = new GLuint[size];
  glSelectBuffer(size, selectionBuffer);

  glRenderMode(GL_SELECT);
  _ctx->render_mode = drawContext::GMSH_SELECT;

  glInitNames();
  glPushMatrix();
  _ctx->initProjection(x, y, w, h);
  _ctx->initPosition();
  _ctx->drawGeom();
  if(meshSelection) _ctx->drawMesh();
  glPopMatrix();

  GLint numhits = glRenderMode(GL_RENDER);
  _ctx->render_mode = drawContext::GMSH_RENDER;

  if(!numhits){ // no hits
    delete [] selectionBuffer;
    return false;
  }
  else if(numhits < 0){ // overflow
    delete [] selectionBuffer;
    Msg::Warning("Too many entities selected");
    return false;
  }

  std::vector<hit> hits;
  GLuint *ptr = selectionBuffer;
  for(int i = 0; i < numhits; i++) {
    // in Gmsh 'names' should always be 0, 2 or 4:
    // * names == 0 means that there is nothing on the stack
    // * if names == 2, the first name is the type of the entity 
    //   (0 for point, 1 for edge, 2 for face or 3 for volume) and
    //   the second is the entity number;
    // * if names == 4, the first name is the type of the entity,
    //   the second is the entity number, the third is the type
    //   of vertex array (2 for line, 3 for triangle, 4 for quad)
    //   and the fourth is the index of the element in the vertex
    //   array
    GLuint names = *ptr++; 
    *ptr++; // mindepth
    GLuint maxdepth = *ptr++;
    if(names == 2){
      GLuint depth = maxdepth;
      GLuint type = *ptr++; 
      GLuint ient = *ptr++;
      hits.push_back(hit(type, ient, depth));
    }
    else if(names == 4){
      GLuint depth = maxdepth;
      GLuint type = *ptr++; 
      GLuint ient = *ptr++;
      GLuint type2 = *ptr++; 
      GLuint ient2 = *ptr++;
      hits.push_back(hit(type, ient, depth, type2, ient2));
    }
  }

  delete [] selectionBuffer;
  
  if(!hits.size()){ // no entities
    return false;
  }

  // sort hits to get closest entities first
  std::sort(hits.begin(), hits.end(), hitDepthLessThan());

  // filter result: if type == ENT_NONE, return the closest entity of
  // "lowest dimension" (point < line < surface < volume). Otherwise,
  // return the closest entity of type "type"
  GLuint typmin = 10;
  for(unsigned int i = 0; i < hits.size(); i++)
    typmin = std::min(typmin, hits[i].type);

  for(unsigned int i = 0; i < hits.size(); i++) {
    if((type == ENT_ALL) ||
       (type == ENT_NONE && hits[i].type == typmin) ||
       (type == ENT_POINT && hits[i].type == 0) ||
       (type == ENT_LINE && hits[i].type == 1) ||
       (type == ENT_SURFACE && hits[i].type == 2) ||
       (type == ENT_VOLUME && hits[i].type == 3)){
      switch (hits[i].type) {
      case 0:
        {
          GVertex *v = m->getVertexByTag(hits[i].ient);
          if(!v){
            Msg::Error("Problem in point selection processing");
            return false;
          }
          vertices.push_back(v);
          if(!multipleSelection) return true;
        }
        break;
      case 1:
        {
          GEdge *e = m->getEdgeByTag(hits[i].ient);
          if(!e){
            Msg::Error("Problem in line selection processing");
            return false;
          }
          if(hits[i].type2){
            MElement *ele = getElement(e, hits[i].type2, hits[i].ient2);
            if(ele) elements.push_back(ele);
          }
          edges.push_back(e);
          if(!multipleSelection) return true;
        }
        break;
      case 2:
        {
          GFace *f = m->getFaceByTag(hits[i].ient);
          if(!f){
            Msg::Error("Problem in surface selection processing");
            return false;
          }
          if(hits[i].type2){
            MElement *ele = getElement(f, hits[i].type2, hits[i].ient2);
            if(ele) elements.push_back(ele);
          }
          faces.push_back(f);
          if(!multipleSelection) return true;
        }
        break;
      case 3:
        {
          GRegion *r = m->getRegionByTag(hits[i].ient);
          if(!r){
            Msg::Error("Problem in volume selection processing");
            return false;
          }
          if(hits[i].type2){
            MElement *ele = getElement(r, hits[i].type2, hits[i].ient2);
            if(ele) elements.push_back(ele);
          }
          regions.push_back(r);
          if(!multipleSelection) return true;
        }
        break;
      }
    }
  }

  if(vertices.size() || edges.size() || faces.size() || 
     regions.size() || elements.size()) 
    return true;
  return false;
}

char openglWindow::selectEntity(int type, 
                                std::vector<GVertex*> &vertices,
                                std::vector<GEdge*> &edges,
                                std::vector<GFace*> &faces,
                                std::vector<GRegion*> &regions,
                                std::vector<MElement*> &elements)
{
  // force keyboard focus in GL window 
  take_focus();
  _selection = type;
  _trySelection = 0;
  selectionMode = true;
  quitSelection = 0;
  endSelection = 0;
  undoSelection = 0;
  invertSelection = 0;

  while(1) {
    vertices.clear();
    edges.clear();
    faces.clear();
    regions.clear();
    elements.clear();
    GUI::instance()->wait();
    if(quitSelection) {
      _selection = ENT_NONE;
      selectionMode = false;
      lassoMode = false;
      addPointMode = false;
      cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
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
      bool add = (_trySelection > 0) ? true : false;
      bool multi = (abs(_trySelection) > 1) ? true : false;
      _trySelection = 0;
      if(_selection == ENT_NONE){ // just report the mouse click
        selectionMode = false;
        return 'c';
      }
      else if(processSelectionBuffer(_selection, multi, true, _trySelectionXYWH[0],
                                     _trySelectionXYWH[1], _trySelectionXYWH[2],
                                     _trySelectionXYWH[3], vertices, edges, faces, 
                                     regions, elements)){
        _selection = ENT_NONE;
        selectionMode = false;
        if(add)
          return 'l';
        else
          return 'r';
      }
    }
  }
}
