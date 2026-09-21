// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Picking: the scene is drawn with an identifier as the colour of every
// object, and what shows up under the cursor is read back. The image is kept
// for the picks that follow, until something changes what a redraw would
// show; the objects under the cursor can be stepped through, front to back.

#include <algorithm>
#include "GmshMessage.h"
#include "drawContext.h"
#include "glMatrix.h"
#include "glShader.h"
#include "Context.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "VertexArray.h"

bool drawContext::_pickColorActive = false;

// returns the element at a given position in a vertex array (element pointers
// are not always stored: returning 0 is not an error)
static MElement *getElement(GEntity *e, int va_type, int index)
{
  VertexArray *va = nullptr;
  switch(va_type) {
  case 2: va = e->va_lines; break;
  case 3: va = e->va_triangles; break;
  // what the clipping planes add (see drawArrays() in drawMesh.cpp)
  case 12: va = e->va_clip_lines; break;
  case 13: va = e->va_clip_triangles; break;
  }
  if(va && index < va->getNumElementPointers())
    return *va->getElementPointerArray(index);
  return nullptr;
}

void drawContext::stepPick(int direction)
{
  if(direction > 0) {
    if(!_pickLastValid) return;
    _pickSkip.push_back(_pickLast);
  }
  else {
    if(_pickSkip.empty()) return;
    _pickSkip.pop_back();
  }
  _pickCacheValid = false;
}

void drawContext::resetPick()
{
  if(_pickSkip.empty()) return;
  _pickSkip.clear();
  _pickCacheValid = false;
}

void drawContext::setPickColor(int type, int ient, int type2, int ient2,
                               bool front)
{
  if(!_pickColor) return;
  _pickObjects.push_back(pickObject(type, ient, type2, ient2, front));
  // 0 is the background: 24 bits give 16 million pickable objects per pass
  std::size_t id = _pickObjects.size() - 1;
  _pickCheckLimit();
  GLubyte c[4];
  pickIdColor(id, c);
  if(!gmshUseShaders()) glDisableClientState(GL_COLOR_ARRAY);
  gmshPickColor4ubv(c);

  // an entity stepped past with the wheel is drawn into neither the colours
  // nor the depth, so that the pass finds what stands behind it
  pickKey key = {type, ient, type2, ient2};
  bool skip =
    std::find(_pickSkip.begin(), _pickSkip.end(), key) != _pickSkip.end();

  // What is closest to the viewer is picked, and among what lies at the same
  // depth the lowest dimension: a point or a curve, a pixel or two wide, is
  // drawn a little closer than the surface it lies on (the depth range
  // scaled by a step per dimension, see _fillPickCache() for the step), so
  // that it wins over that surface as with the selection buffer, but not
  // over a surface in front of it, which the selection buffer's rule - the
  // lowest dimension under the cursor, wherever it is - let it do. A marker
  // standing for an entity (a volume's) goes in front of everything, as it
  // sits inside what it stands for.
  _pickState(skip, _pickFar(type, front));
}

// The identifier travels with the vertices, so the primitives waiting to be
// drawn only have to go when the masks or the depth range change - not at
// every object: a model with 80,000 points made as many draws of one point
// each, half a second per pass with the shader pipeline. (Not "far", which
// the Windows headers define as a macro.)
void drawContext::_pickState(bool skip, double zfar)
{
  if((int)skip == _pickStateSkip && zfar == _pickStateFar) return;
  gmshFlushImmediate();
  GLboolean on = skip ? GL_FALSE : GL_TRUE;
  glColorMask(on, on, on, on);
  glDepthMask(on);
  glDepthRange(0., zfar);
  _pickStateSkip = skip;
  _pickStateFar = zfar;
}

// more objects in a pass than 24 bits of identifiers: the others are drawn
// as the background (see pickIdColor()), and said once
void drawContext::_pickCheckLimit()
{
  static bool warned = false;
  if(warned || _pickObjects.size() <= ((std::size_t)1 << 24)) return;
  warned = true;
  Msg::Warning("More than %d objects in a picking pass: the others cannot be "
               "picked (pick entities rather than elements, or hide some)",
               1 << 24);
}

std::size_t drawContext::pickRegister(int type, const std::vector<int> &tags)
{
  if(!_pickColor || tags.empty()) return 0;
  std::size_t first = _pickObjects.size();
  for(auto t : tags) _pickObjects.push_back(pickObject(type, t, -1, -1, false));
  _pickCheckLimit();
  return first;
}

bool drawContext::pickSkipped(int type, int ient)
{
  if(_pickSkip.empty()) return false;
  pickKey key = {type, ient, -1, -1};
  return std::find(_pickSkip.begin(), _pickSkip.end(), key) != _pickSkip.end();
}

void drawContext::pickStateFor(int type)
{
  if(!_pickColor) return;
  _pickState(false, _pickFar(type, false));
}

void drawContext::setPickColorFor(GEntity *e, bool front)
{
  if(render_mode != GMSH_SELECT) return;
  if(e->model() == GModel::current())
    setPickColor(e->dim(), e->tag(), -1, -1, front);
  else
    unsetPickColor();
}

void drawContext::unsetPickColor()
{
  if(!_pickColor) return;
  // what was set aside for the wheel is drawn again from here on
  gmshFlushImmediate();
  glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
  glDepthMask(GL_TRUE);
  _pickStateSkip = -1;
  // 0 is the background: no pickable object
  GLubyte c[4] = {0, 0, 0, 255};
  if(!gmshUseShaders()) glDisableClientState(GL_COLOR_ARRAY);
  gmshPickColor4ubv(c);
}

// side (in real pixels) of the region a picking pass draws and keeps around
// the query point
static const int PICK_CACHE_SIZE = 512;

// draw a region of the window in picking colours and keep the image, so that
// the picks that follow are lookups rather than redraws
bool drawContext::_fillPickCache(bool mesh, bool post, int fx, int fy, int fw,
                                 int fh)
{
  if(fw < 1 || fh < 1) return false;

  _pickObjects.clear();
  clearGraph2dDataPointTags();
  _pickObjects.push_back(pickObject()); // 0: background
  _pickColor = _pickColorActive = true;
  _pickStateSkip = -1;
  _pickStateFar = -1.;
  render_mode = drawContext::GMSH_SELECT;

  bool oldLighting = gmshLightingEnabled();
  GLboolean oldBlend = glIsEnabled(GL_BLEND);
  GLfloat oldClear[4];
  glGetFloatv(GL_COLOR_CLEAR_VALUE, oldClear);

  // the shader pipeline draws into its own framebuffer, where the depth is
  // written as a colour: OpenGL ES and WebGL cannot read a depth buffer back
  double hr = highResolutionPixelFactor();
  bool intoPickBuffer =
    gmshUseShaders() &&
    glShader::bindPickBuffer((int)((viewport[2] - viewport[0]) * hr),
                             (int)((viewport[3] - viewport[1]) * hr));
  if(!intoPickBuffer) glDrawBuffer(GL_BACK);
  glDepthFunc(GL_LESS);
  gmshDepthTest(true);
  gmshLighting(false);
  glDisable(GL_BLEND);
  // the identifier colour must not be interpolated (the shader gives every
  // fragment the same one)
  if(!gmshUseShaders()) glShadeModel(GL_FLAT);
  // only rasterise the region the image covers
  glEnable(GL_SCISSOR_TEST);
  glScissor(fx, fy, fw, fh);
  glClearColor(0., 0., 0., 0.);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // both matrices are the frame's, and both are changed below: each stack is
  // its own, so each is pushed under its own mode and popped under it
  gmshMatrixMode(GMSH_PROJECTION);
  gmshPushMatrix();
  gmshMatrixMode(GMSH_MODELVIEW);
  gmshPushMatrix();
  initProjection();
  // in camera mode the projection and the modelview are the camera's, which
  // initProjection() and initPosition() know nothing of: the pass used to
  // draw with the rotation of the ordinary mode under whatever projection
  // the last frame had left, and found nothing
  if(CTX::instance()->camera) {
    double view[16];
    initCameraMatrices(view);
  }
  else
    initPosition(false);
  // the step between the dimensions of setPickColor(): a hundredth of the
  // depth the model spans in the window per dimension, a few units of the
  // depth buffer at least, as a scale of the range (which cannot be shifted)
  // at the middle of that span
  {
    CTX *c = CTX::instance();
    double zmin = 1., zmax = 0.;
    for(int i = 0; i < 8; i++) {
      double p[4] = {(i & 1) ? c->max[0] : c->min[0],
                     (i & 2) ? c->max[1] : c->min[1],
                     (i & 4) ? c->max[2] : c->min[2], 1.};
      double e[4], q[4];
      glMatrix::transform(gmshMatrix(GMSH_MODELVIEW), p, e);
      glMatrix::transform(gmshMatrix(GMSH_PROJECTION), e, q);
      if(q[3] == 0.) continue;
      double z = 0.5 * (q[2] / q[3] + 1.);
      zmin = std::min(zmin, z);
      zmax = std::max(zmax, z);
    }
    double extent = std::max(zmax - zmin, 0.);
    double zmid = std::max(0.05, 0.5 * (zmin + zmax));
    _pickDepthStep = std::max(0.01 * extent, 4. / 16777215.) / zmid;
  }
  drawGeom();
  if(mesh) drawMesh();
  if(post) drawPost();
  drawGraph2d(true);

  // 2D overlay, painted on top in drawing order as in draw2d(): without the
  // depth test off, the graph frame and axes would hide the data points
  gmshDepthTest(false);
  gmshClipPlanesOn(0);
  gmshMatrixMode(GMSH_PROJECTION);
  double px2d[16];
  glMatrix::ortho(viewport[0], viewport[2], viewport[1], viewport[3], -100.,
                  100., px2d);
  gmshLoadMatrix(px2d);
  gmshMatrixMode(GMSH_MODELVIEW);
  gmshLoadIdentity();
  drawGraph2d(false);
  drawText2d();
  gmshPopMatrix();
  gmshMatrixMode(GMSH_PROJECTION);
  gmshPopMatrix();
  gmshMatrixMode(GMSH_MODELVIEW);

  _pickCache.assign((std::size_t)4 * fw * fh, 0);
  _pickCacheDepth.assign((std::size_t)fw * fh, 1.f);
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  if(intoPickBuffer) {
    glShader::readPickBuffer(fx, fy, fw, fh, &_pickCache[0],
                             &_pickCacheDepth[0]);
    glShader::releasePickBuffer();
  }
  else {
    glReadBuffer(GL_BACK);
    glReadPixels(fx, fy, fw, fh, GL_RGBA, GL_UNSIGNED_BYTE, &_pickCache[0]);
    glReadPixels(fx, fy, fw, fh, GL_DEPTH_COMPONENT, GL_FLOAT,
                 &_pickCacheDepth[0]);
  }

  glDisable(GL_SCISSOR_TEST);
  gmshFlushImmediate();
  glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
  glDepthMask(GL_TRUE);
  glDepthRange(0., 1.);
  glClearColor(oldClear[0], oldClear[1], oldClear[2], oldClear[3]);
  if(oldLighting) gmshLighting(true);
  if(oldBlend) glEnable(GL_BLEND);
  if(!gmshUseShaders()) glShadeModel(GL_SMOOTH);
  _pickColor = _pickColorActive = false;
  render_mode = drawContext::GMSH_RENDER;

  _pickCacheX = fx;
  _pickCacheY = fy;
  _pickCacheWidth = fw;
  _pickCacheHeight = fh;
  _pickCacheMesh = mesh;
  _pickCachePost = post;
  _pickCacheElements = CTX::instance()->pickElements ? true : false;
  _pickCacheValid = true;
  Msg::Debug("Colour picking: drew %d objects into a %dx%d image",
             (int)_pickObjects.size(), fw, fh);
  return true;
}

// Find the objects whose colour shows up in the picking rectangle, and return
// them ordered by depth.
bool drawContext::_selectColor(int type, bool multiple, bool mesh, bool post,
                               int x, int y, int w, int h,
                               std::vector<GVertex *> &vertices,
                               std::vector<GEdge *> &edges,
                               std::vector<GFace *> &faces,
                               std::vector<GRegion *> &regions,
                               std::vector<MElement *> &elements,
                               std::vector<SPoint2> &points,
                               std::vector<PView *> &views)
{
  if(w < 1) w = 1;
  if(h < 1) h = 1;
  // the rectangle is given by its centre
  int x0 = x - w / 2, y0 = (viewport[3] - y) - h / 2;
  if(x0 < viewport[0]) x0 = viewport[0];
  if(y0 < viewport[1]) y0 = viewport[1];
  if(x0 + w > viewport[2]) w = viewport[2] - x0;
  if(y0 + h > viewport[3]) h = viewport[3] - y0;
  if(w < 1 || h < 1) return false;

  // the viewport is in logical points, the image in real pixels
  double hr = highResolutionPixelFactor();
  int fx0 = (int)(x0 * hr), fy0 = (int)(y0 * hr);
  int fw = (int)(w * hr), fh = (int)(h * hr);
  if(fw < 1) fw = 1;
  if(fh < 1) fh = 1;
  int winW = (int)((viewport[2] - viewport[0]) * hr);
  int winH = (int)((viewport[3] - viewport[1]) * hr);

  bool pickElements = CTX::instance()->pickElements ? true : false;
  bool inside = _pickCacheValid && fx0 >= _pickCacheX && fy0 >= _pickCacheY &&
                fx0 + fw <= _pickCacheX + _pickCacheWidth &&
                fy0 + fh <= _pickCacheY + _pickCacheHeight;
  if(!inside || _pickCacheMesh != mesh || _pickCachePost != post ||
     _pickCacheElements != pickElements) {
    // a region around the query, so that the image serves the picks that
    // follow
    int cw = std::min(winW, PICK_CACHE_SIZE), ch = std::min(winH, PICK_CACHE_SIZE);
    if(cw < fw) cw = fw;
    if(ch < fh) ch = fh;
    int cx = fx0 + fw / 2 - cw / 2, cy = fy0 + fh / 2 - ch / 2;
    if(cx < 0) cx = 0;
    if(cy < 0) cy = 0;
    if(cx + cw > winW) cx = winW - cw;
    if(cy + ch > winH) cy = winH - ch;
    if(cx < 0 || cy < 0) return false;
    if(!_fillPickCache(mesh, post, cx, cy, cw, ch)) return false;
  }

  const unsigned char *pixels = &_pickCache[0];
  const float *depths = &_pickCacheDepth[0];
  const int stride = _pickCacheWidth;
  fx0 -= _pickCacheX;
  fy0 -= _pickCacheY;
  if(fx0 < 0 || fy0 < 0 || fx0 + fw > _pickCacheWidth ||
     fy0 + fh > _pickCacheHeight)
    return false;

  // gather the objects, keeping the smallest depth of each; the 2D overlay
  // wrote no depth (it is painted on top without depth test), so rank it in
  // front. What lies under the middle of the rectangle is remembered: the
  // rest are only near the cursor.
  std::size_t under = 0;
  {
    std::size_t i = (std::size_t)(fy0 + fh / 2) * stride + (fx0 + fw / 2);
    under = (std::size_t)pixels[4 * i] |
            ((std::size_t)pixels[4 * i + 1] << 8) |
            ((std::size_t)pixels[4 * i + 2] << 16);
    if(under >= _pickObjects.size()) under = 0;
  }
  std::map<std::size_t, float> found;
  for(int r = 0; r < fh; r++) {
    for(int c = 0; c < fw; c++) {
      std::size_t i = (std::size_t)(fy0 + r) * stride + (fx0 + c);
      std::size_t id = (std::size_t)pixels[4 * i] |
                       ((std::size_t)pixels[4 * i + 1] << 8) |
                       ((std::size_t)pixels[4 * i + 2] << 16);
      if(!id || id >= _pickObjects.size()) continue;
      float z = (_pickObjects[id].type >= 4) ? -1.f : depths[i];
      auto it = found.find(id);
      if(it == found.end() || z < it->second) found[id] = z;
    }
  }
  Msg::Debug("Colour picking: %d found in a %dx%d rectangle at (%d,%d) of "
             "the %dx%d image kept at (%d,%d)",
             (int)found.size(), fw, fh, fx0, fy0, _pickCacheWidth,
             _pickCacheHeight, _pickCacheX, _pickCacheY);
  if(found.empty()) return false;
  if(Msg::GetVerbosity() == 99)
    for(auto &p : found)
      Msg::Debug("  found type %d ient %d at depth %g%s",
                 _pickObjects[p.first].type, _pickObjects[p.first].ient,
                 p.second, (p.first == under) ? " (under the middle)" : "");

  // order by depth, and prefer the entities of lowest dimension, as the
  // selection buffer based code did
  std::vector<std::pair<float, std::size_t> > sorted;
  for(auto &p : found) sorted.push_back(std::make_pair(p.second, p.first));
  std::sort(sorted.begin(), sorted.end());

  int typmin = 10;
  for(auto &p : sorted) typmin = std::min(typmin, _pickObjects[p.second].type);

  // what the caller asked for, in the order they would be picked: all of
  // them when several are wanted, otherwise the first, which the wheel can
  // set aside to reach the next (stepPick())
  std::vector<std::size_t> candidates;
  for(auto &p : sorted) {
    const pickObject &o = _pickObjects[p.second];
    if(o.type < 4 &&
       !((type == ENT_ALL) || (type == ENT_NONE && o.type == typmin) ||
         (type == ENT_POINT && o.type == 0) ||
         (type == ENT_CURVE && o.type == 1) ||
         (type == ENT_SURFACE && o.type == 2) ||
         (type == ENT_VOLUME && o.type == 3)))
      continue;
    candidates.push_back(p.second);
  }
  // A marker the cursor is exactly on comes first: it stands for an entity
  // that has nothing else to be picked by (the sphere of a volume), and the
  // rule that a lower dimension wins would otherwise give away half of it to
  // a point or a curve that merely passes within a few pixels.
  if(under && _pickObjects[under].front) {
    for(std::size_t i = 1; i < candidates.size(); i++)
      if(candidates[i] == under) {
        candidates.erase(candidates.begin() + i);
        candidates.insert(candidates.begin(), under);
        break;
      }
  }
  _pickCandidates = (int)candidates.size();
  if(candidates.empty()) return false;

  // where the first candidate was hit: the depth under the middle when it is
  // what lies there, its nearest depth otherwise, unprojected with the
  // matrices of the frame (the rectangle is in the viewport's units, the
  // image in true pixels)
  {
    std::size_t i = (std::size_t)(fy0 + fh / 2) * stride + (fx0 + fw / 2);
    const pickObject &o = _pickObjects[candidates[0]];
    // (a view's depth is only known under the middle: found ranks it in
    // front, and a graph of the 2D overlay wrote none)
    double z = (under == candidates[0]) ? depths[i] : found[candidates[0]];
    _pickPointValid = false;
    if(o.type != 4 && z >= 0. && z < 1.) {
      // undo the depth range setPickColor() drew the dimension in
      z /= _pickFar(o.type, o.front);
      double win[3] = {(double)x, (double)(viewport[3] - y), z};
      _pickPointValid =
        glMatrix::unProject(win, model, proj, viewport, _pickPoint) ? true :
                                                                       false;
    }
  }

  GModel *m = GModel::current();
  for(auto &id : candidates) {
    const pickObject &o = _pickObjects[id];
    // what the wheel would step past, if this is the one that is returned
    if(!multiple) {
      _pickLast = {o.type, o.ient, o.type2, o.ient2};
      _pickLastValid = true;
    }
    switch(o.type) {
    case 0: {
      GVertex *v = m->getVertexByTag(o.ient);
      if(v) vertices.push_back(v);
      break;
    }
    case 1: {
      GEdge *e = m->getEdgeByTag(o.ient);
      if(e) {
        MElement *ele = getElement(e, o.type2, o.ient2);
        if(ele)
          elements.push_back(ele);
        else
          edges.push_back(e);
      }
      break;
    }
    case 2: {
      GFace *f = m->getFaceByTag(o.ient);
      if(f) {
        MElement *ele = getElement(f, o.type2, o.ient2);
        if(ele)
          elements.push_back(ele);
        else
          faces.push_back(f);
      }
      break;
    }
    case 3: {
      GRegion *r = m->getRegionByTag(o.ient);
      if(r) {
        MElement *ele = getElement(r, o.type2, o.ient2);
        if(ele)
          elements.push_back(ele);
        else
          regions.push_back(r);
      }
      break;
    }
    case 4: {
      points.push_back(getGraph2dDataPointForTag(o.ient));
      break;
    }
    case 5: {
      if(o.ient >= 0 && o.ient < (int)PView::list.size())
        views.push_back(PView::list[o.ient]);
      break;
    }
    default: break;
    }
    if(!multiple && (vertices.size() || edges.size() || faces.size() ||
                     regions.size() || elements.size() || points.size() ||
                     views.size()))
      return true;
  }

  return (vertices.size() || edges.size() || faces.size() || regions.size() ||
          elements.size() || points.size() || views.size());
}

bool drawContext::pickBehind(int type, bool mesh, bool post, int x, int y,
                             int w, int h)
{
  if(!_pickLastValid) return false;
  pickKey last = _pickLast;
  int candidates = _pickCandidates;
  _pickSkip.push_back(last);
  _pickCacheValid = false;
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;
  std::vector<SPoint2> points;
  std::vector<PView *> views;
  bool found = _selectColor(type, false, mesh, post, x, y, w, h, vertices,
                            edges, faces, regions, elements, points, views);
  _pickSkip.pop_back();
  _pickCacheValid = false;
  _pickLast = last;
  _pickLastValid = true;
  _pickCandidates = candidates;
  return found;
}

bool drawContext::select(int type, bool multiple, bool mesh, bool post, int x,
                         int y, int w, int h, std::vector<GVertex *> &vertices,
                         std::vector<GEdge *> &edges,
                         std::vector<GFace *> &faces,
                         std::vector<GRegion *> &regions,
                         std::vector<MElement *> &elements,
                         std::vector<SPoint2> &points,
                         std::vector<PView *> &views)
{
  vertices.clear();
  edges.clear();
  faces.clear();
  regions.clear();
  elements.clear();
  points.clear();
  views.clear();

  _pickLastValid = false;
  _pickPointValid = false;
  if(_selectColor(type, multiple, mesh, post, x, y, w, h, vertices, edges,
                  faces, regions, elements, points, views))
    return true;
  // Nothing stands behind the last one: stay on it rather than coming round
  // to the front, so that stepping the other way is what goes back. The
  // steps that found nothing are undone one by one, as the scene may have
  // changed under a cursor that has not moved.
  while(!_pickSkip.empty()) {
    _pickSkip.pop_back();
    _pickCacheValid = false;
    if(_selectColor(type, multiple, mesh, post, x, y, w, h, vertices, edges,
                    faces, regions, elements, points, views))
      return true;
  }
  return false;
}
