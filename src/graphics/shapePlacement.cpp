// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
#include <cstdio>
#include "GmshConfig.h"
#include "shapePlacement.h"
#include "sceneTool.h"
#include "sceneView.h"
#include "drawContext.h"
#include "glImmediate.h"
#include "glShader.h"
#include "VertexArray.h"
#include "GModel.h"
#include "GModelIO_OCC.h"
#include "GuiListener.h"
#include "scriptStringInterface.h"
#include "OpenFile.h"
#include "Context.h"
#include "Numeric.h"
#include "SPoint3.h"
#include "SVector3.h"
#include "mathEvaluator.h"
#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

shapePlacement *shapePlacement::_current = nullptr;

// (see below)
static double windowSize(drawContext *ctx);
static double snapStep(int i, double size);

// the value of an expression of the .geo language, with the variables of the
// script read so far
static bool evaluate(const std::string &str, double &val)
{
  std::vector<std::string> var;
  std::vector<double> valVar;
#if defined(HAVE_PARSER)
  for(auto it = gmsh_yysymbols.begin(); it != gmsh_yysymbols.end(); it++) {
    if(it->second.value.size() == 1) {
      var.push_back(it->first);
      valVar.push_back(it->second.value[0]);
    }
  }
#endif
  std::vector<std::string> expr(1, str);
  std::vector<double> res(1);
  mathEvaluator f(expr, var);
  if(expr.empty()) return false;
  if(!f.eval(valVar, res)) return false;
  val = res[0];
  return true;
}

void shapePlacement::start(int shape, const std::vector<std::string> &values,
                           std::function<void()> changed)
{
  stop();
  if(shape < 1 || shape >= (int)scriptShapes().size()) return;
  _current = new shapePlacement();
  _current->_shape = shape;
  _current->_values = values;
  _current->_values.resize(scriptShapes()[shape].fields.size());
  _current->_changed = changed;
  drawContext::setDrawGeomTransientFunction(draw);
}

void shapePlacement::stop()
{
  if(!_current) return;
  if(_current->_addedAny) SetBoundingBox();
  delete _current;
  _current = nullptr;
  drawContext::setDrawGeomTransientFunction(nullptr);
}

void shapePlacement::_changedByScene()
{
  _changes++;
  if(_changed) _changed();
}

void shapePlacement::setValue(std::size_t i, const std::string &value)
{
  if(i >= _values.size()) return;
  _values[i] = value;
  if(i < 3) _locked[i] = true;
  _added = false;
}

void shapePlacement::setLocked(int i, bool on)
{
  if(i >= 0 && i < 3) _locked[i] = on;
}

void shapePlacement::toggleLock(int i, bool allBut)
{
  if(i < 0 || i > 2) return;
  if(allBut)
    for(int j = 0; j < 3; j++) _locked[j] = (j != i);
  else
    _locked[i] = !_locked[i];
  _changedByScene();
}

bool shapePlacement::position(double xyz[3]) const
{
  for(int i = 0; i < 3; i++)
    if(i >= (int)_values.size() || !evaluate(_values[i], xyz[i])) return false;
  return true;
}

// the coordinate fixed by a plane of the axes (2 for XY...), -1 for the plane
// facing the viewer
static int planeAxis(shapePlacement::Plane p)
{
  return p == shapePlacement::PlaneXY ? 2 :
         p == shapePlacement::PlaneYZ ? 0 :
         p == shapePlacement::PlaneXZ ? 1 :
                                        -1;
}

void shapePlacement::planePoint(drawContext *ctx, double x, double y,
                                double xyz[3]) const
{
  CTX *c = CTX::instance();
  double pos[3];
  bool hasPos = position(pos);
  // the line of sight under the pointer
  double p[3], d[3];
  ctx->unproject(x, y, p, d);
  // the plane: a point o of it and its normal n
  double o[3] = {0., 0., 0.}, n[3] = {0., 0., 0.};
  int k = planeAxis(_plane);
  if(k >= 0) {
    if(hasPos && _locked[k]) o[k] = pos[k];
    n[k] = 1.;
  }
  double dn = prosca(d, n);
  if(k < 0 || std::abs(dn) < 1e-3 * norm3(d)) {
    // facing the viewer, through the center of gravity
    k = -1;
    for(int i = 0; i < 3; i++) {
      o[i] = c->cg[i];
      n[i] = d[i];
    }
    dn = prosca(d, n);
  }
  double po[3] = {o[0] - p[0], o[1] - p[1], o[2] - p[2]};
  double t = dn ? prosca(po, n) / dn : 0.;
  double size = windowSize(ctx);
  for(int i = 0; i < 3; i++) {
    xyz[i] = p[i] + t * d[i];
    if(i != k && size > 0.) {
      double step = snapStep(i, size);
      double v = xyz[i] / step;
      double f = floor(v), cl = ceil(v);
      xyz[i] = ((v - f < cl - v) ? f : cl) * step;
    }
  }
  if(k >= 0) xyz[k] = o[k];
  for(int i = 0; i < 3; i++)
    if(hasPos && _locked[i]) xyz[i] = pos[i];
}

std::string shapePlacement::planeName() const
{
  int k = planeAxis(_plane);
  if(k < 0) return "the plane facing the view";
  double pos[3], off = 0.;
  if(_locked[k] && position(pos)) off = pos[k];
  char tmp[64];
  snprintf(tmp, sizeof(tmp), "the plane %c = %g", "xyz"[k], off);
  return tmp;
}

void shapePlacement::hover(const double *xyz)
{
  _hoverOn = xyz != nullptr;
  if(!xyz) return;
  double pos[3];
  bool hasPos = position(pos);
  for(int i = 0; i < 3; i++)
    _hover[i] = (hasPos && _locked[i]) ? pos[i] : xyz[i];
}

void shapePlacement::drop(const double xyz[3])
{
  for(int i = 0; i < 3 && i < (int)_values.size(); i++) {
    if(_locked[i]) continue;
    char tmp[32];
    snprintf(tmp, sizeof(tmp), "%g", xyz[i]);
    _values[i] = tmp;
  }
  _added = false;
  _changedByScene();
}

bool shapePlacement::add()
{
  // the model is read again, which makes its bounding box again, on which the
  // view is framed: the box is kept as it was while placing, or the view
  // would jump (it is made again at the end, see stop())
  CTX *c = CTX::instance();
  double mn[3] = {c->min[0], c->min[1], c->min[2]};
  double mx[3] = {c->max[0], c->max[1], c->max[2]};
  bool added = scriptAddShape(scriptShapes()[_shape].name, _values,
                              GModel::current()->getFileName());
  SetBoundingBox(mn[0], mx[0], mn[1], mx[1], mn[2], mx[2]);
  if(!added) return false;
  GModel::current()->setSelection(0);
  _added = _addedAny = true;
  return true;
}

// the foreground over the background, by a part a
static void faintColor(double a)
{
  CTX *c = CTX::instance();
  unsigned int fg = c->color.fg, bg = c->color.bg;
  auto mix = [a](int f, int b) { return (unsigned char)(b + a * (f - b)); };
  gmshColor4ub(mix(c->unpackRed(fg), c->unpackRed(bg)),
               mix(c->unpackGreen(fg), c->unpackGreen(bg)),
               mix(c->unpackBlue(fg), c->unpackBlue(bg)), 255);
}

// a round step dividing a length in about ten
static double roundStep(double length)
{
  double raw = length / 10.;
  double step = pow(10., floor(log10(raw)));
  if(raw / step >= 5.)
    step *= 5.;
  else if(raw / step >= 2.)
    step *= 2.;
  return step;
}

// what the window shows across, in the units of the model
static double windowSize(drawContext *ctx)
{
  return (ctx->vxmax - ctx->vxmin) / ctx->s[0];
}

// The steps along axis i, for a window showing size across: the snapping
// step (Geometry.Snap) while it is of use at that zoom, neither coarser than
// a tenth of the window nor finer than a two hundredth; else round steps
// that follow the zoom, the points snapped to a fifth of the lines of the grid
static bool snapApplies(int i, double size)
{
  double snap = CTX::instance()->geom.snap[i];
  return snap > 0. && snap <= size / 10. && snap >= size / 200.;
}
static double gridStep(int i, double size)
{
  return snapApplies(i, size) ? CTX::instance()->geom.snap[i] :
                                roundStep(size);
}
static double snapStep(int i, double size)
{
  return snapApplies(i, size) ? CTX::instance()->geom.snap[i] :
                                roundStep(size) / 5.;
}

void shapePlacement::_drawGrid(drawContext *ctx) const
{
  int k = planeAxis(_plane);
  if(k < 0) return;
  CTX *c = CTX::instance();
  // its two axes, and where it is along the third
  int a = (k + 1) % 3, b = (k + 2) % 3;
  double pos[3], off = 0.;
  bool hasPos = position(pos);
  if(_locked[k] && hasPos) off = pos[k];
  // all the window shows of it, a plane of construction having no end: where
  // the lines of sight through the corners and the center of the window meet
  // it, with the position and the point under the pointer
  double lo[3] = {0., 0., 0.}, hi[3] = {0., 0., 0.};
  bool any = false;
  auto take = [&](const double q[3]) {
    for(int i : {a, b}) {
      lo[i] = any ? std::min(lo[i], q[i]) : q[i];
      hi[i] = any ? std::max(hi[i], q[i]) : q[i];
    }
    any = true;
  };
  double W = ctx->viewport[2], H = ctx->viewport[3];
  const double corners[5][2] = {
    {0., 0.}, {W, 0.}, {0., H}, {W, H}, {0.5 * W, 0.5 * H}};
  for(auto &w : corners) {
    double p[3], d[3];
    ctx->unproject(w[0], w[1], p, d);
    if(std::abs(d[k]) < 1e-6 * norm3(d)) continue; // along the plane
    double t = (off - p[k]) / d[k];
    if(!c->ortho && t < 0.) continue; // behind the eye
    double q[3] = {p[0] + t * d[0], p[1] + t * d[1], p[2] + t * d[2]};
    take(q);
  }
  if(!any) return;
  if(hasPos) take(pos);
  if(_hoverOn) take(_hover);
  // (not past a hundred windows, for a plane seen edge on)
  double window = (ctx->vxmax - ctx->vxmin) / ctx->s[0];
  for(int i : {a, b}) {
    double mid = 0.5 * (lo[i] + hi[i]);
    double half = std::min(0.5 * (hi[i] - lo[i]), 50. * window);
    lo[i] = mid - half;
    hi[i] = mid + half;
  }
  // the step of the window (see gridStep()), about as dense on the screen at
  // any zoom; coarser by tens where the plane, seen edge on, goes far
  double size = std::max(hi[a] - lo[a], hi[b] - lo[b]);
  if(!(size > 0.) || !(window > 0.)) return;
  double step[3] = {0., 0., 0.};
  for(int i : {a, b}) {
    step[i] = gridStep(i, window);
    while((hi[i] - lo[i]) / step[i] > 400.) step[i] *= 10.;
  }
  int na0 = (int)floor(lo[a] / step[a]), na1 = (int)ceil(hi[a] / step[a]);
  int nb0 = (int)floor(lo[b] / step[b]), nb1 = (int)ceil(hi[b] / step[b]);
  for(int pass = 0; pass < 2; pass++) {
    // the lines, then the axes through the origin over them
    faintColor(pass ? 0.45 : 0.15);
    gmshBegin(GL_LINES);
    double q[3];
    q[k] = off;
    for(int i = na0; i <= na1; i++) {
      if((i == 0) != (pass == 1)) continue;
      q[a] = i * step[a];
      q[b] = nb0 * step[b];
      gmshVertex3d(q[0], q[1], q[2]);
      q[b] = nb1 * step[b];
      gmshVertex3d(q[0], q[1], q[2]);
    }
    for(int j = nb0; j <= nb1; j++) {
      if((j == 0) != (pass == 1)) continue;
      q[b] = j * step[b];
      q[a] = na0 * step[a];
      gmshVertex3d(q[0], q[1], q[2]);
      q[a] = na1 * step[a];
      gmshVertex3d(q[0], q[1], q[2]);
    }
    gmshEnd();
  }
}

static void drawArc(double xc, double yc, double zc, double rx, double ry,
                    double angle1, double angle2)
{
  if(angle2 <= angle1) return;
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
  gmshBegin(GL_LINE_STRIP);
  const int N = 30;
  for(int i = 0; i < N; i++) {
    double t = angle1 + (double)i / (double)(N - 1) * (angle2 - angle1);
    gmshVertex3d(xc + rx * cos(t), yc + ry * sin(t), zc);
  }
  gmshEnd();
}

// translucent, as it is not added yet: what it cuts into shows through it (in
// the order the triangles come, which a convex shape hardly shows), and it
// writes no depth, so that the model behind it is drawn
static void drawTriangles(std::vector<SPoint3> &vertices,
                          std::vector<SVector3> &normals,
                          std::vector<int> &triangles)
{
  bool fill = gmshPolygonFilled();
  gmshPolygonFill(CTX::instance()->geom.surfaceType != 1);
  gmshLightTwoSide(true);
  unsigned int c = CTX::instance()->color.geom.highlight[0];
  gmshColor4ub(CTX::instance()->unpackRed(c), CTX::instance()->unpackGreen(c),
               CTX::instance()->unpackBlue(c), 100);
  // (the transparency pass has a blending of its own)
  bool ownBlend = !glShader::transparentPass();
  if(ownBlend) {
    gmshBlend(true);
    gmshBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  }
  gmshDepthMask(false);
  VertexArray va(3, triangles.size());
  for(std::size_t i = 0; i < triangles.size(); i += 3) {
    double x[3], y[3], z[3];
    SVector3 nn[3];
    for(int j = 0; j < 3; j++) {
      SPoint3 &p = vertices[triangles[i + j]];
      x[j] = p.x();
      y[j] = p.y();
      z[j] = p.z();
      nn[j] = normals[triangles[i + j]];
    }
    va.add(x, y, z, nn);
  }
  va.finalize();
  drawVertexArray(&va, GL_TRIANGLES, GMSH_DRAW_LIGHT);
  gmshDepthMask(true);
  if(ownBlend) gmshBlend(false);
  gmshPolygonFill(fill);
}

// the shapes OpenCASCADE triangulates for the preview, by their index in
// scriptShapes()
static bool makeSTL(int shape, const double *v, std::vector<SPoint3> &p,
                    std::vector<SVector3> &n, std::vector<int> &t)
{
  OCC_Internals *o = GModel::current()->getOCCInternals();
  switch(shape) {
  case 4: return o->makeDiskSTL(v[0], v[1], v[2], v[3], v[4], p, n, t);
  case 5:
    return o->makeRectangleSTL(v[0], v[1], v[2], v[3], v[4], v[5], p, n, t);
  case 6:
    return o->makeSphereSTL(v[0], v[1], v[2], v[3], v[4], v[5], v[6], p, n, t);
  case 7:
    return o->makeCylinderSTL(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], p,
                              n, t);
  case 8: return o->makeBoxSTL(v[0], v[1], v[2], v[3], v[4], v[5], p, n, t);
  case 9: return o->makeTorusSTL(v[0], v[1], v[2], v[3], v[4], v[5], p, n, t);
  case 10:
    return o->makeConeSTL(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
                          p, n, t);
  case 11:
    return o->makeWedgeSTL(v[0], v[1], v[2], v[3], v[4], v[5], v[6], p, n, t);
  }
  return false;
}

void shapePlacement::_drawPreview() const
{
  // (the point is its mark; the arcs drawn, the others triangulated)
  if(_shape < 2) return;
  double v[16];
  for(std::size_t i = 0; i < _values.size() && i < 16; i++)
    if(!evaluate(_values[i], v[i])) return;
  if(_shape == 2)
    drawArc(v[0], v[1], v[2], v[3], v[3], v[4], v[5]);
  else if(_shape == 3)
    drawArc(v[0], v[1], v[2], v[3], v[4], v[5], v[6]);
  else {
    if(!GModel::current()->getOCCInternals())
      GModel::current()->createOCCInternals();
    std::vector<SPoint3> vertices;
    std::vector<SVector3> normals;
    std::vector<int> triangles;
    if(makeSTL(_shape, v, vertices, normals, triangles))
      drawTriangles(vertices, normals, triangles);
  }
}

void shapePlacement::draw(void *context)
{
  shapePlacement *p = _current;
  drawContext *ctx = (drawContext *)context;
  // (not in a picking pass: what a click finds is the model; once a frame:
  // in the pass of the opaque geometry, or in the transparent one if there
  // is none, see drawContext::drawGeom())
  if(!p || !ctx || ctx->render_mode == drawContext::GMSH_SELECT) return;
  if(ctx->transparencyPass == TRANSPARENCY_TRANSPARENT &&
     !geometryColorsAreTransparent())
    return;
  CTX *c = CTX::instance();
  p->_drawGrid(ctx);
  if(!p->_added) p->_drawPreview();
  // the marks over what is drawn: on the model, they lie at the depth of its
  // surface
  gmshDepthTest(false);
  gmshPointSize(c->geom.pointSize);
  if(p->_hoverOn) {
    // where a click would put the position, faintly
    faintColor(0.35);
    gmshBegin(GL_POINTS);
    gmshVertex3d(p->_hover[0], p->_hover[1], p->_hover[2]);
    gmshEnd();
  }
  double pos[3];
  if(p->position(pos)) {
    const unsigned char colors[3][3] = {
      {220, 50, 50}, {40, 160, 40}, {50, 90, 230}};
    // the line down to the work plane, if it is off it
    int k = planeAxis(p->_plane);
    if(k >= 0 && !p->_locked[k] && std::abs(pos[k]) > 0.) {
      double q[3] = {pos[0], pos[1], pos[2]};
      q[k] = 0.;
      gmshColor4ub(colors[k][0], colors[k][1], colors[k][2], 255);
      gmshLineWidth(c->geom.curveWidth);
      gmshLineStipple(1, 0x0F0F);
      gmshBegin(GL_LINES);
      gmshVertex3d(pos[0], pos[1], pos[2]);
      gmshVertex3d(q[0], q[1], q[2]);
      gmshEnd();
      gmshLineStippleOff();
    }
    // a small triad in the colours of the axes
    double len = 30. * ctx->pixel_equiv_x / ctx->s[0];
    gmshLineWidth(2. * c->geom.curveWidth);
    for(int i = 0; i < 3; i++) {
      gmshColor4ub(colors[i][0], colors[i][1], colors[i][2], 255);
      double e[3] = {pos[0], pos[1], pos[2]};
      e[i] += len;
      gmshBegin(GL_LINES);
      gmshVertex3d(pos[0], pos[1], pos[2]);
      gmshVertex3d(e[0], e[1], e[2]);
      gmshEnd();
    }
    gmshLineWidth(1.);
    gmshColor4ubv((GLubyte *)&c->color.geom.highlight[0]);
    gmshBegin(GL_POINTS);
    gmshVertex3d(pos[0], pos[1], pos[2]);
    gmshEnd();
  }
  gmshDepthTest(true);
}

sceneTool *newPlacementTool(std::function<void()> finished)
{
  return new functionTool(
    "Place", ENT_NONE, false,
    [](sceneView *) {
      return std::string("Click to place it, on the model or the work plane, "
                         "or type its values\n[Press 'e' to add it, x, y or z "
                         "to lock a coordinate, Escape to stop]");
    },
    [](char ib, sceneView *s, const scenePicks &) {
      shapePlacement *p = shapePlacement::current();
      if(!p || ib == 'q') return false;
      if(ib == 'c') {
        const double *w = s->clickPosition();
        double xyz[3];
        if(!s->modelPointAt((int)w[0], (int)w[1], xyz))
          p->planePoint(s->getDrawContext(), w[0], w[1], xyz);
        p->drop(xyz);
      }
      else if(ib == 'e' && p->add())
        Gui()->entitiesChanged();
      for(sceneView *v : sceneView::all()) v->askRedraw();
      return true;
    },
    [finished]() {
      shapePlacement::stop();
      if(finished) finished();
      for(sceneView *v : sceneView::all()) {
        v->pointerLeft();
        v->askRedraw();
      }
    });
}
