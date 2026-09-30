// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What a web page calls (through ccall) to show Gmsh's scene on its canvas,
// with Emscripten, besides the Gmsh API (api/gmsh.mjs): the scene drawn as a
// window would draw it (see drawContextOffscreen), turned, zoomed and moved by
// the mouse the way the graphical interface does it. Positions are in the CSS
// pixels of the canvas, from its top left corner.

#if defined(__EMSCRIPTEN__)

#include <cmath>
#include <emscripten.h>
#include "Context.h"
#include "drawContextOffscreen.h"

namespace {
  drawContextOffscreen *_view = nullptr;

  // the view of the scene, once it has been drawn
  drawContext *view()
  {
    return _view ? _view->getDrawContext() : nullptr;
  }
} // namespace

extern "C" {

// draw on the canvas of width x height device pixels, scale being the number
// of them per CSS pixel (the devicePixelRatio of the page)
EMSCRIPTEN_KEEPALIVE int gmshWebDraw(int width, int height, double scale)
{
  if(!_view) _view = new drawContextOffscreen();
  if(!_view->begin(width, height, scale, true)) return 0;
  _view->drawCurrentOpenglWindow(true);
  _view->end();
  return 1;
}

// add the next frames of the studio shading (General.Shading) to what the
// last draw showed, for about budget seconds: 1 while there are more to add,
// which the page asks for at its next animation frame
EMSCRIPTEN_KEEPALIVE int gmshWebDrawStudio(int width, int height, double scale,
                                           double budget)
{
  if(!_view || !_view->begin(width, height, scale, true)) return 0;
  bool more = _view->drawStudioFrames(budget);
  _view->end();
  return more ? 1 : 0;
}

// turn the model as the mouse moved from (x0, y0) to (x1, y1)
EMSCRIPTEN_KEEPALIVE void gmshWebRotate(double x0, double y0, double x1,
                                        double y1)
{
  drawContext *ctx = view();
  if(!ctx) return;
  double w = ctx->viewport[2], h = ctx->viewport[3];
  if(CTX::instance()->useTrackball)
    ctx->addQuaternion((2. * x0 - w) / w, (h - 2. * y0) / h, (2. * x1 - w) / w,
                       (h - 2. * y1) / h);
  else {
    double dx = x1 - x0, dy = y1 - y0;
    ctx->r[1] += (std::fabs(dx) > std::fabs(dy)) ? 180. * dx / w : 0.;
    ctx->r[0] += (std::fabs(dx) > std::fabs(dy)) ? 0. : 180. * dy / h;
  }
}

// zoom by factor around the point (x, y)
EMSCRIPTEN_KEEPALIVE void gmshWebZoom(double factor, double x, double y)
{
  drawContext *ctx = view();
  if(!ctx || factor <= 0.) return;
  mousePosition p;
  p.set(ctx, (int)x, (int)y);
  for(int i = 0; i < 3; i++) ctx->s[i] *= factor;
  p.recenter(ctx);
}

// move the model as the mouse moved from (x0, y0) to (x1, y1)
EMSCRIPTEN_KEEPALIVE void gmshWebPan(double x0, double y0, double x1,
                                     double y1)
{
  drawContext *ctx = view();
  if(!ctx) return;
  mousePosition a, b;
  a.set(ctx, (int)x0, (int)y0);
  b.set(ctx, (int)x1, (int)y1);
  ctx->t[0] += b.wnr[0] - a.wnr[0];
  ctx->t[1] += b.wnr[1] - a.wnr[1];
}

// back to the view of the options (General.RotationX, General.ScaleX,
// General.TrackballQuaternion0, ...), as set by the files opened, at the next
// draw
EMSCRIPTEN_KEEPALIVE void gmshWebResetView()
{
  if(_view) _view->resetView();
}

} // extern "C"

#endif
